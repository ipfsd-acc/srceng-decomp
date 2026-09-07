// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxtextfield.cpp
// Functions: 225
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxtextfield.h"

//------------------------------------------------------------------------------
// Address: 0x10084510
// Name: public: virtual class GRect<float> GFxCharacter::GetRectBounds(class GMatrix2D const __near &)const
// Source: rtti_class
//------------------------------------------------------------------------------
void __userpurge GFxCharacter::GetRectBounds(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this@<ecx>,
        CMatRenderContextBase *t,
        __int128 a3,
        const FlashlightState_t *a4,
        const VMatrix *a5)
{
  *(float *)&t->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = 0.0;
  *(float *)&t->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = 0.0;
  *(float *)&t->m_iRefs = 0.0;
  *(float *)&t->m_pCurrentMaterial = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A4A0
// Name: public: virtual class GRect<float> GFxASCharacter::GetFocusRect(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxASCharacter::GetFocusRect(
        void *this,
        CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  float v4[6]; // [esp+8h] [ebp-1Ch] BYREF

  GMatrix2D::SetIdentity(this: v4);
  (*(void (__thiscall **)(void *, CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, float *))(*(_DWORD *)this + 52))(
    a1: this,
    a2: result,
    a3: v4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E3E90
// Name: private: void GFxEditTextCharacter::SetHtml(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetHtml(GFxEditTextCharacter *this, bool a2)
{
  if ( a2 )
    *((_WORD *)this + 114) |= 2u;
  else
    *((_WORD *)this + 114) &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x100E3EC0
// Name: private: void GFxEditTextCharacter::SetPassword(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetPassword(GFxEditTextCharacter *this, bool a2)
{
  if ( a2 )
    *((_WORD *)this + 114) |= 4u;
  else
    *((_WORD *)this + 114) &= ~4u;
}

//------------------------------------------------------------------------------
// Address: 0x100E3EF0
// Name: private: void GFxEditTextCharacter::SetMouseWheelEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetMouseWheelEnabled(GFxEditTextCharacter *this, bool a2)
{
  if ( a2 )
    *((_WORD *)this + 114) |= 0x80u;
  else
    *((_WORD *)this + 114) &= ~0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x100E3F20
// Name: GFx_StringToIMEStyleCategory
// Source: json
//------------------------------------------------------------------------------
int __usercall GFx_StringToIMEStyleCategory@<eax>(const char ***a1@<edi>)
{
  int result; // eax
  bool v2; // zf

  result = strcmp(**a1, "compositionSegment");
  if ( result != 0 )
  {
    if ( strcmp(**a1, "clauseSegment") == 0 )
    {
      return 1;
    }
    else if ( strcmp(**a1, "convertedSegment") == 0 )
    {
      return 2;
    }
    else if ( GASString::operator==(this: a1, a2: "phraseLengthAdj") )
    {
      return 3;
    }
    else
    {
      v2 = !GASString::operator==(this: a1, a2: "lowConfSegment");
      result = 4;
      if ( v2 )
        return 5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E4010
// Name: public: void GFxTextClipboard::SetText(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextClipboard::SetText(CBaseAutoPtr<IMatRenderContext> *this, const wchar_t *ptext, unsigned int a3)
{
  GRefCountNTSImpl *v4; // ecx
  const wchar_t *v5; // edi

  v4 = *((GRefCountNTSImpl **)this + 7);
  if ( v4 != nullptr )
  {
    GRefCountNTSImpl::Release(this: v4);
    *((_DWORD *)this + 7) = 0;
  }
  GFxWStringBuffer::SetString(this: (GFxWStringBuffer *)(this + 3), pwch: ptext, a3);
  v5 = *((const wchar_t **)this + 3);
  if ( v5 == nullptr )
    v5 = &word_1028F3E0;
  return ((int (__thiscall *)(CBaseAutoPtr<IMatRenderContext> *, const wchar_t *, _DWORD))this->m_pObject[1].__vftable)(
           a1: this,
           a2: v5,
           a3: *((_DWORD *)this + 4));
}

//------------------------------------------------------------------------------
// Address: 0x100E4060
// Name: public: class GFxWStringBuffer const __near & GFxTextClipboard::GetText(void)const
// Source: json
//------------------------------------------------------------------------------
const IMatRenderContext *__thiscall GFxTextClipboard::GetText(char *this)
{
  return (const IMatRenderContext *)(this + 12);
}

//------------------------------------------------------------------------------
// Address: 0x100E4090
// Name: public: static void __near * GNewOverrideBase<326>::operator new(unsigned int,struct GMemAddressStub __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GNewOverrideBase<326>::operator new(unsigned int sz, const void *adr)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = 326;
  return GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: adr, a3: sz, a4: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x100E40C0
// Name: unsigned int G_LowerBoundSliced<class GArray<struct GFxTextKeyMap::KeyMapEntry,2,struct GArrayDefaultPolicy>,unsigned int,int (*)(struct GFxTextKeyMap::KeyMapEntry const __near &,unsigned int)>(class GArray<struct GFxTextKeyMap::KeyMapEntry,2,struct GArrayDefaultPolicy> const __near &,unsigned int,unsigned int,unsigned int const __near &,int (*)(struct GFxTextKeyMap::KeyMapEntry const __near &,unsigned int))
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_LowerBoundSliced<GArray<GFxTextKeyMap::KeyMapEntry,2,GArrayDefaultPolicy>,unsigned int,int (__cdecl *)(GFxTextKeyMap::KeyMapEntry const &,unsigned int)>(
        _DWORD *a1,
        int a2,
        int a3,
        _DWORD *a4,
        int (__cdecl *a5)(int, _DWORD))
{
  int result; // eax
  int i; // edi
  int v7; // ebx

  result = a2;
  for ( i = a3 - a2; i > 0; result = a2 )
  {
    v7 = (i >> 1) + result;
    if ( a5(a1: *a1 + 16 * v7, a2: *a4) != 0 )
    {
      a2 = v7 + 1;
      i += -1 - (i >> 1);
    }
    else
    {
      i >>= 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E4160
// Name: public: void GFxTextDocView::RemoveText(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::RemoveText(SFTextObjectImpl **this, unsigned int startPos, unsigned int endPos)
{
  if ( endPos < startPos )
    GFxStyledText::Remove(this: *(this + 2), a2: startPos, a3: 0);
  else
    GFxStyledText::Remove(this: *(this + 2), a2: startPos, a3: endPos - startPos);
}

//------------------------------------------------------------------------------
// Address: 0x100E4190
// Name: public: virtual GFxEditTextCharacterDef::~GFxEditTextCharacterDef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacterDef::~GFxEditTextCharacterDef(
        GArrayData<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *this)
{
  volatile LONG *v2; // edi
  volatile LONG *v3; // edi
  IShaderDevice *v4; // ecx

  v2 = (volatile LONG *)(*((_DWORD *)this + 19) & 0xFFFFFFFC);
  this->Data = (GPtr<GFxAmpServer::ViewStats> *)&GFxEditTextCharacterDef::`vftable';
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (volatile LONG *)(*(_DWORD *)(this + 6) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  if ( *((_DWORD *)this + 4) == 0 )
  {
    v4 = *((IShaderDevice **)this + 5);
    if ( v4 != nullptr )
      GFxResource::Release(this: v4);
  }
  this->Data = (GPtr<GFxAmpServer::ViewStats> *)&GFxResource::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100E4200
// Name: public: virtual unsigned int GFxEditTextCharacterDef::GetResourceTypeCode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxEditTextCharacterDef::GetResourceTypeCode(GFxEditTextCharacterDef *this)
{
  return 33536;
}

//------------------------------------------------------------------------------
// Address: 0x100E4210
// Name: private: void GFxEditTextCharacter::SetDirtyFlag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetDirtyFlag(GFxEditTextCharacter *this)
{
  int v1; // eax

  v1 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
  if ( v1 != 0 )
    *(_DWORD *)(v1 + 9332) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x100E4230
// Name: private: bool GFxEditTextCharacter::IsReadOnly(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxEditTextCharacter::IsReadOnly(GFxEditTextCharacter *this)
{
  int v1; // eax

  v1 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v1 != 0 )
    LOBYTE(v1) = *(_BYTE *)(v1 + 104) & 1;
  else
    return (*(_BYTE *)(*((_DWORD *)this + 46) + 80) & 8) != 0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100E4260
// Name: private: class GFxTextEditorKit __near * GFxEditTextCharacter::CreateEditorKit(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxTextEditorKit *__usercall GFxEditTextCharacter::CreateEditorKit@<eax>(
        GFxEditTextCharacter *this@<ecx>,
        int a2@<ebx>)
{
  GFxTextDocView *v3; // ecx
  struct GFxTextEditorKit *result; // eax
  struct GFxTextEditorKit *EditorKit; // edi
  int v6; // eax
  int v7; // eax
  IShaderDevice *v8; // eax
  IShaderDevice *v9; // ebx
  IShaderAPI *v10; // ecx
  int v11; // eax
  int v12; // eax
  IShaderDevice *v13; // eax
  IShaderAPI *v14; // ebx
  IShaderAPI *v15; // ecx
  IShaderAPI *v16; // [esp+4h] [ebp-4h]

  v3 = *((GFxTextDocView **)this + 47);
  result = *((struct GFxTextEditorKit **)v3 + 71);
  if ( result == nullptr )
  {
    EditorKit = GFxTextDocView::CreateEditorKit(this: v3);
    if ( (*(_BYTE *)(*((_DWORD *)this + 46) + 80) & 8) != 0 )
      *((_WORD *)EditorKit + 52) |= 1u;
    if ( (*(_BYTE *)(*((_DWORD *)this + 46) + 80) & 0x20) != 0 )
      *((_WORD *)EditorKit + 52) |= 2u;
    v6 = (*(int (__thiscall **)(GFxEditTextCharacter *, int))(*(_DWORD *)this + 84))(a1: this, a2);
    v7 = (**(int (__thiscall ***)(int))(v6 + 8))(a1: v6 + 8);
    v8 = (IShaderDevice *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 12))(a1: v7, a2: 24);
    v9 = v8;
    v16 = (IShaderAPI *)v8;
    if ( v8 != nullptr )
      GRefCountImpl::AddRef(this: v8);
    v10 = *((IShaderAPI **)EditorKit + 3);
    if ( v10 != nullptr )
      GRefCountImpl::Release(this: v10);
    *((_DWORD *)EditorKit + 3) = v9;
    v11 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
    v12 = (**(int (__thiscall ***)(int))(v11 + 8))(a1: v11 + 8);
    v13 = (IShaderDevice *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v12 + 12))(a1: v12, a2: 25);
    v14 = (IShaderAPI *)v13;
    if ( v13 != nullptr )
      GRefCountImpl::AddRef(this: v13);
    v15 = *((IShaderAPI **)EditorKit + 4);
    if ( v15 != nullptr )
      GRefCountImpl::Release(this: v15);
    *((_DWORD *)EditorKit + 4) = v14;
    if ( (*((_BYTE *)this + 229) & 1) != 0 )
      *((_WORD *)EditorKit + 52) |= 4u;
    else
      *((_WORD *)EditorKit + 52) &= ~4u;
    if ( v14 != nullptr )
      GRefCountImpl::Release(this: v14);
    if ( v16 != nullptr )
      GRefCountImpl::Release(this: v16);
    return EditorKit;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E4360
// Name: public: bool GFxEditTextCharacter::HasStyleSheet(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxEditTextCharacter::HasStyleSheet(GFxEditTextCharacter *this)
{
  _DWORD *v1; // eax

  v1 = *((_DWORD **)this + 59);
  return v1 != nullptr && *v1 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E4380
// Name: public: void GFxEditTextCharacter::UpdateVariable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::UpdateVariable(
        GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **this)
{
  int v2; // ebx
  _DWORD *v3; // eax
  struct GASStringNode *StringNode; // esi
  char *v5; // edi
  bool v6; // zf
  void *v7; // esi
  _IMAGE_SYMBOL_EX *v8; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h] BYREF

  v8 = (_IMAGE_SYMBOL_EX *)(this + 52);
  if ( LODWORD((*(this + 52))[1].First) != 0 )
  {
    v2 = ((int (__thiscall *)(GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **))LODWORD((*this)[7].First))(a1: this);
    if ( v2 != 0 )
    {
      GFxTextDocView::GetText(
        this: *(this + 47),
        a2: (const GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeRef *)&v9);
      StringNode = GASStringManager::CreateStringNode(
                     this: *(GASStringManager **)(*(_DWORD *)(v2 + 120) + 636),
                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*v3 & 0xFFFFFFFC) + 8),
                     length: *(_DWORD *)(*v3 & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++*((_DWORD *)StringNode + 2);
      v5 = (char *)(this + 53);
      if ( (unsigned __int8)*v5 >= 5u )
        GASValue::DropRefs(this: (GASValue *)v5, a2: (int)v5);
      *v5 = 5;
      *((_DWORD *)v5 + 1) = StringNode;
      v6 = ++*((_DWORD *)StringNode + 2) == 1;
      --*((_DWORD *)StringNode + 2);
      if ( v6 )
        GASStringNode::ReleaseNode(a1: (int)StringNode);
      v7 = (void *)(v9 & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v9 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
      GASEnvironment::SetVariable(
        this: (__vc_attributes::propgetAttribute *)v2,
        varname: v8,
        val: (tagWNDCLASSW *)v5,
        doDisplayErrors: nullptr,
        a5: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4450
// Name: _GFxEditTextCharacter::SetTextValue_::_10_::TranslateInfo::TranslateInfo
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxEditTextCharacter::SetTextValue_::_10_::TranslateInfo::TranslateInfo@<eax>(int result@<eax>, int a2)
{
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)result = 0;
  *(_BYTE *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = result + 24;
  *(_DWORD *)(result + 20) = 512;
  *(_DWORD *)(result + 1052) = 512;
  *(_DWORD *)(result + 1048) = result + 1056;
  *(_DWORD *)(result + 2080) = *(_DWORD *)(result + 16);
  *(_DWORD *)(result + 2084) = 0;
  *(_DWORD *)(result + 2088) = *(_DWORD *)(result + 16);
  *(_DWORD *)(result + 2092) = *(_DWORD *)(result + 20);
  *(_DWORD *)(result + 2096) = *(_DWORD *)(result + 1048);
  *(_DWORD *)(result + 2100) = 0;
  *(_DWORD *)(result + 2104) = *(_DWORD *)(result + 1048);
  *(_DWORD *)(result + 2108) = *(_DWORD *)(result + 1052);
  *(_DWORD *)(result + 4) = result + 2080;
  *(_DWORD *)(result + 8) = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E44E0
// Name: public: static void GFxEditTextCharacter::SetTextFormat(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::SetTextFormat(
        int a1@<ebx>,
        int a2@<edi>,
        long double a3@<st0>,
        GASFnCall *a4)
{
  GASFnCall v4; // edi
  GFxEditTextCharacter *v5; // edi
  _DWORD *v6; // eax
  int v7; // eax
  GASValue *v8; // eax
  struct GASObject *v9; // eax
  struct GASObject *v10; // esi
  GASValue *v11; // eax
  struct GASObject *v12; // eax
  struct GASObject *v13; // ebx
  GASValue *v14; // eax
  double v15; // st7
  int v16; // esi
  GASValue *v17; // eax
  struct GASObject *v18; // eax
  struct GASObject *v19; // ebx
  GASValue *v20; // eax
  double v21; // st7
  GASValue *v22; // eax
  double v23; // st7
  const struct GASEnvironment *v24; // [esp-Ch] [ebp-18h]
  _SERVICE_STATUS *v25; // [esp-Ch] [ebp-18h]
  const struct GASEnvironment *v26; // [esp-Ch] [ebp-18h]
  _SERVICE_STATUS *v27; // [esp-Ch] [ebp-18h]
  _SERVICE_STATUS *v28; // [esp-Ch] [ebp-18h]
  const struct GASEnvironment *v29; // [esp-8h] [ebp-14h]
  double startPos; // [esp+4h] [ebp-8h]

  if ( a4[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a4[2]->cbSize + 8))(a1: a4[2]) == 4 )
  {
    v4 = a4[2];
    v5 = v4 != nullptr ? (GFxEditTextCharacter *)&v4[-3] : nullptr;
    v6 = *((_DWORD **)v5 + 59);
    if ( v6 == nullptr || *v6 == 0 )
    {
      v7 = (int)a4[7];
      if ( v7 == 1 )
      {
        v29 = (const struct GASEnvironment *)a4[6];
        v8 = (GASValue *)GASFnCall::Arg(this: a4, a2: 0);
        v9 = GASValue::ToObject(this: v8, a2: (int)v5, a3: v29);
        v10 = v9;
        if ( v9 != nullptr && ((int (__thiscall *)(struct GASObject *))v9[2].pNode[1].pNext)(a1: &v9[2]) == 30 )
        {
          GFxTextDocView::SetTextFormat(
            fmt: (unsigned int)&v10[6].sequence,
            startPos: nullptr,
            endPos: (const char *)0xFFFFFFFF,
            a4: a2);
          GFxTextDocView::SetParagraphFormat(fmt: (unsigned int)&v10[12], startPos: nullptr, a3: -1);
          GFxEditTextCharacter::SetDirtyFlag(this: v5);
        }
        return;
      }
      if ( v7 == 2 )
      {
        v24 = (const struct GASEnvironment *)a4[6];
        v11 = (GASValue *)GASFnCall::Arg(this: a4, a2: 1);
        v12 = GASValue::ToObject(this: v11, a2: (int)v5, a3: v24);
        v13 = v12;
        if ( v12 == nullptr )
          return;
        if ( ((int (__thiscall *)(struct GASObject *))v12[2].pNode[1].pNext)(a1: &v12[2]) != 30 )
          return;
        v25 = (_SERVICE_STATUS *)a4[6];
        v14 = (GASValue *)GASFnCall::Arg(this: a4, a2: 0);
        v15 = GASValue::ToNumber(this: v14, a2: (int)v5, a3, result: v25);
        if ( v15 < 0.0 )
          return;
        v16 = (__int64)v15;
        GFxTextDocView::SetTextFormat(
          fmt: (unsigned int)&v13[6].sequence,
          startPos: (GMemoryHeap *)v16,
          endPos: (const char *)(v16 + 1),
          a4: a1);
        GFxTextDocView::SetParagraphFormat(fmt: (unsigned int)&v13[12], startPos: (const char *)v16, a3: v16 + 1);
LABEL_26:
        GFxEditTextCharacter::SetDirtyFlag(this: v5);
        return;
      }
      if ( v7 >= 3 )
      {
        v26 = (const struct GASEnvironment *)a4[6];
        v17 = (GASValue *)GASFnCall::Arg(this: a4, a2: 2);
        v18 = GASValue::ToObject(this: v17, a2: (int)v5, a3: v26);
        v19 = v18;
        if ( v18 != nullptr && ((int (__thiscall *)(struct GASObject *))v18[2].pNode[1].pNext)(a1: &v18[2]) == 30 )
        {
          v27 = (_SERVICE_STATUS *)a4[6];
          v20 = (GASValue *)GASFnCall::Arg(this: a4, a2: 0);
          v21 = GASValue::ToNumber(this: v20, a2: (int)v5, a3, result: v27);
          if ( v21 < 0.0 )
            v21 = 0.0;
          startPos = v21;
          v28 = (_SERVICE_STATUS *)a4[6];
          v22 = (GASValue *)GASFnCall::Arg(this: a4, a2: 1);
          v23 = GASValue::ToNumber(this: v22, a2: (int)v5, a3: v21, result: v28);
          if ( v23 < 0.0 )
            v23 = 0.0;
          if ( startPos <= v23 )
          {
            GFxTextDocView::SetTextFormat(
              fmt: (unsigned int)&v19[6].sequence,
              (GMemoryHeap *)(__int64)startPos,
              endPos: (const char *)(__int64)v23,
              a4: a1);
            GFxTextDocView::SetParagraphFormat(
              fmt: (unsigned int)&v19[12],
              (const char *)(__int64)startPos,
              a3: (__int64)v23);
            goto LABEL_26;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4740
// Name: public: static void GFxEditTextCharacter::ReplaceTextA(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::ReplaceTextA(int a1@<ebx>, long double a2@<st0>, GASFnCall *a3)
{
  GASFnCall v3; // edi
  int v4; // edi
  _DWORD *v5; // eax
  GASValue *v6; // eax
  GASValue *v7; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v8; // ebx
  unsigned __int8 *v9; // eax
  double v10; // st7
  char *v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // edx
  char *v14; // ebx
  int v15; // eax
  wchar_t *v16; // ebx
  CVTFTexture *v17; // ecx
  const char **v18; // eax
  _SERVICE_STATUS *v20; // [esp-Ch] [ebp-838h]
  _SERVICE_STATUS *v21; // [esp-Ch] [ebp-838h]
  double v23; // [esp+4h] [ebp-828h] BYREF
  int ppdestParaFmt; // [esp+Ch] [ebp-820h] BYREF
  char *startPos[2]; // [esp+10h] [ebp-81Ch]
  int Length; // [esp+18h] [ebp-814h]
  CUtlMap<char const *,int,unsigned short>::CKeyLess *v27; // [esp+1Ch] [ebp-810h] BYREF
  int ppdestTextFmt; // [esp+20h] [ebp-80Ch] BYREF
  int v29; // [esp+24h] [ebp-808h]
  GMemoryHeap pstr; // [esp+28h] [ebp-804h] BYREF

  if ( a3[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a3[2]->cbSize + 8))(a1: a3[2]) == 4 )
  {
    v3 = a3[2];
    v4 = v3 != nullptr ? (int)&v3[-3] : 0;
    v5 = *(_DWORD **)(v4 + 236);
    if ( (v5 == nullptr || *v5 == 0) && (int)a3[7] >= 3 )
    {
      v20 = (_SERVICE_STATUS *)a3[6];
      v6 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
      *(double *)startPos = GASValue::ToNumber(this: v6, a2: v4, a3: a2, result: v20);
      v21 = (_SERVICE_STATUS *)a3[6];
      v7 = (GASValue *)GASFnCall::Arg(this: a3, a2: 1);
      v23 = GASValue::ToNumber(this: v7, a2: v4, a3: *(long double *)startPos, result: v21);
      v8 = (tagRID_DEVICE_INFO_KEYBOARD *)a3[6];
      v9 = (unsigned __int8 *)GASFnCall::Arg(this: a3, a2: 2);
      GASValue::ToStringImpl(this: v9, a2: (int *)&v27, a3: v8, precision: -1, debug: false);
      v10 = *(double *)startPos;
      Length = GASString::GetLength(this: (const char ***)&v27);
      v11 = (char *)(__int64)*(double *)startPos;
      ppdestTextFmt = HIWORD(v29) | 0xC00;
      *(_QWORD *)startPos = (__int64)v23;
      v29 = (__int64)v23;
      if ( v10 >= 0.0 && v23 >= 0.0 && (unsigned int)v11 <= (unsigned int)(__int64)v23 )
      {
        v12 = GFxStyledText::GetLength(this: *(GFxStyledText **)(*(_DWORD *)(v4 + 188) + 8));
        v13 = Length;
        v14 = &v11[v12 - v29 + Length];
        startPos[1] = v14;
        if ( (unsigned int)v11 < v12 )
        {
          GFxStyledText::GetTextAndParagraphFormat(
            this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(*(_DWORD *)(v4 + 188) + 8),
            (int)&ppdestTextFmt,
            (int)&ppdestParaFmt);
          v13 = Length;
        }
        else
        {
          v15 = *(_DWORD *)(v4 + 188);
          ppdestTextFmt = *(_DWORD *)(*(_DWORD *)(v15 + 8) + 28);
          ppdestParaFmt = *(_DWORD *)(*(_DWORD *)(v15 + 8) + 24);
        }
        if ( v13 >= 0x400 )
        {
          HIDWORD(v23) = 324;
          v16 = (wchar_t *)GMemory::pGlobalHeap->Alloc_2(
                             this: GMemory::pGlobalHeap,
                             a2: 2 * v13 + 2,
                             a3: (char *)&v23 + 4);
          GUTF8Util::DecodeString(
            pbegin: v16,
            putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)v27->m_LessFunc,
            length: -1);
          GFxTextDocView::ReplaceTextA(
            this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v4 + 188),
            pstr: (GMemoryHeap *)v16);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
          v14 = startPos[1];
        }
        else
        {
          GUTF8Util::DecodeString(
            pbegin: (wchar_t *)&pstr,
            putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)v27->m_LessFunc,
            length: -1);
          GFxTextDocView::ReplaceTextA(
            this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v4 + 188),
            &pstr);
        }
        v17 = *(CVTFTexture **)(*(_DWORD *)(v4 + 188) + 284);
        if ( v17 != nullptr && GFILEFile::GetErrorCode(this: v17) > (unsigned int)v14 )
          GFxTextEditorKit::SetCursorPos(
            this: *(GFxTextEditorKit **)(*(_DWORD *)(v4 + 188) + 284),
            textPos: (unsigned int)v14,
            selectionAllowed: false);
        if ( ppdestParaFmt != 0 )
          GFxTextDocView::SetParagraphFormat(fmt: ppdestParaFmt, startPos: v11, a3: (int)&v11[Length]);
        if ( ppdestTextFmt != 0 )
          GFxTextDocView::SetTextFormat(fmt: ppdestTextFmt, startPos: (GMemoryHeap *)v11, endPos: &v11[Length], a4: a1);
        GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v4);
      }
      v18 = (const char **)v27;
      if ( v27[2].m_LessFunc-- == (bool (__cdecl *)(const char *const *, const char *const *))1 )
        GASStringNode::ReleaseNode(a1: (int)v18);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4A50
// Name: public: static void GFxEditTextCharacter::ReplaceSel(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::ReplaceSel(int a1@<ebx>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  int v3; // esi
  _DWORD *v4; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v5; // ebx
  unsigned __int8 *v6; // eax
  int v7; // eax
  unsigned int v8; // edx
  unsigned int Length; // edi
  int v10; // eax
  char *v11; // edx
  char *v12; // ecx
  char *v13; // ebx
  wchar_t *v14; // edi
  const char *v15; // edi
  const char **v16; // eax
  int v19; // [esp+4h] [ebp-81Ch] BYREF
  unsigned int fmt; // [esp+8h] [ebp-818h]
  unsigned int v21; // [esp+Ch] [ebp-814h]
  unsigned int v22; // [esp+10h] [ebp-810h]
  char *v23; // [esp+14h] [ebp-80Ch]
  CUtlMap<char const *,int,unsigned short>::CKeyLess *v24; // [esp+18h] [ebp-808h] BYREF
  GMemoryHeap pstr; // [esp+1Ch] [ebp-804h] BYREF

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v2 = a2[2];
    v3 = v2 != nullptr ? (int)&v2[-3] : 0;
    v4 = *(_DWORD **)(v3 + 236);
    if ( (v4 == nullptr || *v4 == 0) && (int)a2[7] >= 1 && *(_DWORD *)(*(_DWORD *)(v3 + 188) + 284) != 0 )
    {
      v5 = (tagRID_DEVICE_INFO_KEYBOARD *)a2[6];
      v6 = (unsigned __int8 *)GASFnCall::Arg(this: a2, a2: 0);
      GASValue::ToStringImpl(this: v6, a2: (int *)&v24, a3: v5, precision: -1, debug: false);
      v7 = *(_DWORD *)(*(_DWORD *)(v3 + 188) + 8);
      v8 = *(_DWORD *)(v7 + 24);
      v21 = *(_DWORD *)(v7 + 28);
      fmt = v8;
      Length = GASString::GetLength(this: (const char ***)&v24);
      v10 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 188) + 284) + 8);
      v11 = *(char **)(v10 + 28);
      v12 = *(char **)(v10 + 32);
      v22 = Length;
      v13 = v11;
      if ( v11 >= v12 )
        v13 = v12;
      v23 = v11;
      if ( v12 >= v11 )
        v23 = v12;
      if ( Length >= 0x400 )
      {
        v19 = 324;
        v14 = (wchar_t *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2 * Length + 2, a3: &v19);
        GUTF8Util::DecodeString(
          pbegin: v14,
          putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)v24->m_LessFunc,
          length: -1);
        GFxTextDocView::ReplaceTextA(
          this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v3 + 188),
          pstr: (GMemoryHeap *)v14);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
        Length = v22;
      }
      else
      {
        GUTF8Util::DecodeString(
          pbegin: (wchar_t *)&pstr,
          putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)v24->m_LessFunc,
          length: -1);
        GFxTextDocView::ReplaceTextA(
          this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v3 + 188),
          &pstr);
      }
      v15 = &v13[Length];
      GFxTextEditorKit::SetCursorPos(
        this: *(GFxTextEditorKit **)(*(_DWORD *)(v3 + 188) + 284),
        textPos: (unsigned int)v15,
        selectionAllowed: false);
      if ( fmt != 0 )
        GFxTextDocView::SetParagraphFormat(fmt, startPos: v13, a3: (int)v15);
      if ( v21 != 0 )
        GFxTextDocView::SetTextFormat(fmt: v21, startPos: (GMemoryHeap *)v13, endPos: v15, a4: a1);
      GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v3);
      v16 = (const char **)v24;
      if ( v24[2].m_LessFunc-- == (bool (__cdecl *)(const char *const *, const char *const *))1 )
        GASStringNode::ReleaseNode(a1: (int)v16);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4C50
// Name: public: static void GFxEditTextCharacter::AppendText(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GFxEditTextCharacter::AppendText(GASFnCall *a1)
{
  GASFnCall *v1; // edi
  GASFnCall v2; // esi
  int v3; // esi
  _DWORD *v4; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v5; // ebx
  unsigned __int8 *v6; // eax
  int v7; // eax
  GASFnCall *v8; // eax
  bool v9; // zf

  v1 = a1;
  if ( a1[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a1[2]->cbSize + 8))(a1: a1[2]) == 4 )
  {
    v2 = v1[2];
    v3 = v2 != nullptr ? (int)&v2[-3] : 0;
    v4 = *(_DWORD **)(v3 + 236);
    if ( (v4 == nullptr || *v4 == 0) && (int)v1[7] >= 1 )
    {
      v5 = (tagRID_DEVICE_INFO_KEYBOARD *)v1[6];
      v6 = (unsigned __int8 *)GASFnCall::Arg(this: v1, a2: 0);
      GASValue::ToStringImpl(this: v6, a2: (int *)&a1, a3: v5, precision: -1, debug: false);
      GFxTextDocView::AppendText(this: *(GFxTextDocView **)(v3 + 188), putf8String: (const char *)*a1, a3: 0xFFFFFFFF);
      v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
      if ( v7 != 0 )
        *(_DWORD *)(v7 + 9332) |= 0x400u;
      v8 = a1;
      v9 = a1[2] == (GASFnCall)1;
      a1[2] = (GASFnCall)((char *)a1[2] - 1);
      if ( v9 )
        GASStringNode::ReleaseNode(a1: (int)v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4D00
// Name: public: static void GFxEditTextCharacter::GetCharIndexAtPoint(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetCharIndexAtPoint(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v3; // eax
  int v4; // edi
  GASValue *v5; // eax
  GASValue *v6; // eax
  int CharIndexAtPoint; // eax
  GASFnCall v8; // esi
  int v9; // edi
  double v10; // st7
  _SERVICE_STATUS *v11; // [esp+4h] [ebp-14h]
  _SERVICE_STATUS *v12; // [esp+4h] [ebp-14h]
  float v13; // [esp+4h] [ebp-14h]
  double v14; // [esp+10h] [ebp-8h]
  float v15; // [esp+20h] [ebp+8h]
  float v16; // [esp+20h] [ebp+8h]

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v3 = a2[2];
    v4 = v3 != nullptr ? (int)&v3[-3] : 0;
    if ( (int)a2[7] >= 2 )
    {
      v11 = (_SERVICE_STATUS *)a2[6];
      v5 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v14 = GASValue::ToNumber(this: v5, a2: v4, a3: a1, result: v11);
      v12 = (_SERVICE_STATUS *)a2[6];
      v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
      v15 = GASValue::ToNumber(this: v6, a2: v4, a3: v14, result: v12) * 20.0;
      v13 = v15;
      v16 = 20.0 * v14;
      CharIndexAtPoint = GFxTextDocView::GetCharIndexAtPoint(this: *(GFxTextDocView **)(v4 + 188), a2: v16, a3: v13);
      v8 = a2[1];
      v9 = CharIndexAtPoint;
      if ( CharIndexAtPoint == -1 )
      {
        if ( LOBYTE(v8->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v8, a2: -1);
        v10 = -1.0;
        LOBYTE(v8->cbSize) = 3;
      }
      else
      {
        if ( LOBYTE(v8->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v8, a2: CharIndexAtPoint);
        v10 = (double)v9;
        LOBYTE(v8->cbSize) = 3;
        if ( v9 < 0 )
        {
          *(double *)&v8->cItems = v10 + 4294967296.0;
          return;
        }
      }
      *(double *)&v8->cItems = v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4DF0
// Name: public: static void GFxEditTextCharacter::GetLineIndexAtPoint(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetLineIndexAtPoint(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v3; // eax
  int v4; // edi
  GASValue *v5; // eax
  GASValue *v6; // eax
  int LineIndexAtPoint; // eax
  GASFnCall v8; // esi
  int v9; // edi
  double v10; // st7
  _SERVICE_STATUS *v11; // [esp+4h] [ebp-14h]
  _SERVICE_STATUS *v12; // [esp+4h] [ebp-14h]
  float v13; // [esp+4h] [ebp-14h]
  double v14; // [esp+10h] [ebp-8h]
  float v15; // [esp+20h] [ebp+8h]
  float v16; // [esp+20h] [ebp+8h]

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v3 = a2[2];
    v4 = v3 != nullptr ? (int)&v3[-3] : 0;
    if ( (int)a2[7] >= 2 )
    {
      v11 = (_SERVICE_STATUS *)a2[6];
      v5 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v14 = GASValue::ToNumber(this: v5, a2: v4, a3: a1, result: v11);
      v12 = (_SERVICE_STATUS *)a2[6];
      v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
      v15 = GASValue::ToNumber(this: v6, a2: v4, a3: v14, result: v12) * 20.0;
      v13 = v15;
      v16 = 20.0 * v14;
      LineIndexAtPoint = GFxTextDocView::GetLineIndexAtPoint(this: *(GFxTextDocView **)(v4 + 188), a2: v16, a3: v13);
      v8 = a2[1];
      v9 = LineIndexAtPoint;
      if ( LineIndexAtPoint == -1 )
      {
        if ( LOBYTE(v8->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v8, a2: -1);
        v10 = -1.0;
        LOBYTE(v8->cbSize) = 3;
      }
      else
      {
        if ( LOBYTE(v8->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v8, a2: LineIndexAtPoint);
        v10 = (double)v9;
        LOBYTE(v8->cbSize) = 3;
        if ( v9 < 0 )
        {
          *(double *)&v8->cItems = v10 + 4294967296.0;
          return;
        }
      }
      *(double *)&v8->cItems = v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4EE0
// Name: public: static void GFxEditTextCharacter::GetLineOffset(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetLineOffset(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int v3; // edi
  GASValue *v4; // eax
  signed int v5; // eax
  unsigned int LineOffset; // eax
  GASFnCall v7; // esi
  _SERVICE_STATUS *v8; // [esp+4h] [ebp-Ch]

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v2 = a2[2];
    v3 = v2 != nullptr ? (int)&v2[-3] : 0;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToInt32(this: v4, a2: v3, a3: a1, a4: v8);
      if ( v5 < 0 || (LineOffset = GFxTextDocView::GetLineOffset(this: *(GFxTextDocView **)(v3 + 188), a2: v5)) == -1 )
      {
        v7 = a2[1];
        if ( LOBYTE(v7->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v7, a2: v3);
        *(double *)&v7->cItems = -1.0;
        LOBYTE(v7->cbSize) = 3;
      }
      else
      {
        GASValue::SetNumber(this: (GASValue *)a2[1], a2: (double)LineOffset);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4F80
// Name: public: static void GFxEditTextCharacter::GetLineLength(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetLineLength(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int v3; // edi
  GASValue *v4; // eax
  const GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v5; // eax
  unsigned int v6; // eax
  GASFnCall v7; // esi
  _SERVICE_STATUS *v8; // [esp+4h] [ebp-Ch]

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v2 = a2[2];
    v3 = v2 != nullptr ? (int)&v2[-3] : 0;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = (const GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)GASValue::ToInt32(this: v4, a2: v3, a3: a1, a4: v8);
      if ( (int)v5 < 0
        || (GFxTextDocView::GetLineLength(
              this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v3 + 188),
              lineIndex: v5),
            v6 == -1) )
      {
        v7 = a2[1];
        if ( LOBYTE(v7->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v7, a2: v3);
        *(double *)&v7->cItems = -1.0;
        LOBYTE(v7->cbSize) = 3;
      }
      else
      {
        GASValue::SetNumber(this: (GASValue *)a2[1], a2: (double)v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5030
// Name: public: static void GFxEditTextCharacter::GetLineText(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetLineText(long double a1@<st0>, _IMAGE_SYMBOL_EX a2)
{
  unsigned int Short; // edi
  int v3; // eax
  int v4; // esi
  GASValue *v5; // eax
  signed int v6; // eax
  GASValue *v7; // edi
  GFxTextDocView *v8; // ecx
  RGB888_t *LineText; // esi
  struct GASStringNode *StringNode; // esi
  GASValue *v11; // ecx
  bool v12; // zf
  struct GASStringNode *ConstStringNode; // esi
  GASValue *v14; // ecx
  _SERVICE_STATUS *v15; // [esp-8h] [ebp-14h]
  struct GASStringNode *v16; // [esp+4h] [ebp-8h] BYREF
  unsigned int v17; // [esp+8h] [ebp-4h] BYREF

  Short = a2.N.Name.Short;
  if ( *(_DWORD *)(a2.N.Name.Short + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2.N.Name.Short + 8) + 8))(a1: *(_DWORD *)(a2.N.Name.Short + 8)) == 4 )
  {
    v3 = *(_DWORD *)(Short + 8);
    v4 = v3 != 0 ? v3 - 120 : 0;
    if ( *(int *)(Short + 28) >= 1 )
    {
      v15 = *(_SERVICE_STATUS **)(Short + 24);
      v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)Short, a2: 0);
      v6 = GASValue::ToInt32(this: v5, a2: Short, a3: a1, a4: v15);
      if ( v6 >= 0 )
      {
        v8 = *(GFxTextDocView **)(v4 + 188);
        v17 = 0;
        LineText = (RGB888_t *)GFxTextDocView::GetLineText(this: v8, a2: v6, a3: &v17);
        if ( LineText != nullptr )
        {
          GString::GString(this: (CUtlMemory<CImagePacker,int> *)&a2);
          GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)&a2, pstr: LineText, a3: v17);
          StringNode = GASStringManager::CreateStringNode(
                         this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(Short + 24) + 120) + 636),
                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((a2.N.Name.Short & 0xFFFFFFFC)
                                                                                                  + 8),
                         length: *(_DWORD *)(a2.N.Name.Short & 0xFFFFFFFC) & 0x7FFFFFFF);
          ++*((_DWORD *)StringNode + 2);
          v11 = *(GASValue **)(Short + 4);
          v16 = StringNode;
          GASValue::SetString(this: v11, str: (_IMAGE_SYMBOL_EX *)&v16);
          v12 = (*((_DWORD *)StringNode + 2))-- == 1;
          if ( v12 )
            GASStringNode::ReleaseNode(a1: (int)StringNode);
          GString::~GString(this: (GString *)&a2);
        }
        else
        {
          ConstStringNode = GASStringManager::CreateConstStringNode(
                              this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(Short + 24) + 120) + 636),
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem,
                              a3: 0,
                              a4: 0);
          ++*((_DWORD *)ConstStringNode + 2);
          v14 = *(GASValue **)(Short + 4);
          a2.N.Name.Short = (unsigned int)ConstStringNode;
          GASValue::SetString(this: v14, str: &a2);
          v12 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
          if ( v12 )
            GASStringNode::ReleaseNode(a1: (int)ConstStringNode);
        }
      }
      else
      {
        v7 = *(GASValue **)(Short + 4);
        GASValue::DropRefs(this: v7, a2: (int)v7);
        *(_BYTE *)v7 = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5170
// Name: public: static void GFxEditTextCharacter::GetFirstCharInParagraph(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetFirstCharInParagraph(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int v3; // edi
  GASValue *v4; // eax
  signed int v5; // eax
  unsigned int FirstCharInParagraph; // eax
  GASFnCall v7; // esi
  _SERVICE_STATUS *v8; // [esp+4h] [ebp-Ch]

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v2 = a2[2];
    v3 = v2 != nullptr ? (int)&v2[-3] : 0;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToInt32(this: v4, a2: v3, a3: a1, a4: v8);
      if ( v5 < 0
        || (FirstCharInParagraph = GFxTextDocView::GetFirstCharInParagraph(this: *(GFxTextDocView **)(v3 + 188), a2: v5)) == -1 )
      {
        v7 = a2[1];
        if ( LOBYTE(v7->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v7, a2: v3);
        *(double *)&v7->cItems = -1.0;
        LOBYTE(v7->cbSize) = 3;
      }
      else
      {
        GASValue::SetNumber(this: (GASValue *)a2[1], a2: (double)FirstCharInParagraph);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5210
// Name: public: static void GFxEditTextCharacter::GetLineIndexOfChar(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetLineIndexOfChar(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int v3; // edi
  GASValue *v4; // eax
  signed int v5; // eax
  unsigned int LineIndexOfChar; // eax
  GASFnCall v7; // esi
  _SERVICE_STATUS *v8; // [esp+4h] [ebp-Ch]

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v2 = a2[2];
    v3 = v2 != nullptr ? (int)&v2[-3] : 0;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToInt32(this: v4, a2: v3, a3: a1, a4: v8);
      if ( v5 < 0
        || (LineIndexOfChar = GFxTextDocView::GetLineIndexOfChar(this: *(GFxTextDocView **)(v3 + 188), a2: v5)) == -1 )
      {
        v7 = a2[1];
        if ( LOBYTE(v7->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v7, a2: v3);
        *(double *)&v7->cItems = -1.0;
        LOBYTE(v7->cbSize) = 3;
      }
      else
      {
        GASValue::SetNumber(this: (GASValue *)a2[1], a2: (double)LineIndexOfChar);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E52B0
// Name: public: static void GFxEditTextCharacter::CopyToClipboard(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::CopyToClipboard(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // eax
  GASFnCall *v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  char *v10; // eax
  GASValue *v11; // eax
  GASValue *v12; // eax
  tagPOLYTEXTW *v13; // [esp-Ch] [ebp-14h]
  _SERVICE_STATUS *v14; // [esp-Ch] [ebp-14h]
  _SERVICE_STATUS *v15; // [esp-Ch] [ebp-14h]
  char v16; // [esp+4h] [ebp-4h]
  GASFnCall *v17; // [esp+10h] [ebp+8h]

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v3 = a2[2];
    v4 = v3 != nullptr ? (int)&v3[-3] : 0;
    v5 = *(_DWORD *)(*(_DWORD *)(v4 + 188) + 284);
    if ( v5 != 0 )
    {
      v6 = *(_DWORD *)(v5 + 8);
      v7 = *(GASFnCall **)(v6 + 28);
      v16 = (*(_BYTE *)(v5 + 104) & 4) != 0;
      v8 = *(_DWORD *)(v6 + 32);
      v17 = v7;
      if ( (unsigned int)v7 >= v8 )
        v17 = *(GASFnCall **)(v6 + 32);
      v9 = *(_DWORD *)(v6 + 28);
      if ( v8 >= (unsigned int)v7 )
        v9 = *(_DWORD *)(v6 + 32);
      if ( (int)a2[7] >= 1 )
      {
        v13 = (tagPOLYTEXTW *)a2[6];
        v10 = (char *)GASFnCall::Arg(this: a2, a2: 0);
        v16 = GASValue::ToBool(a1: v10, a2: a1, result: v13);
      }
      if ( (int)a2[7] >= 2 )
      {
        v14 = (_SERVICE_STATUS *)a2[6];
        v11 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
        v17 = (GASFnCall *)GASValue::ToUInt32(this: v11, a2: v5, a3: a1, a4: v14);
      }
      if ( (int)a2[7] >= 3 )
      {
        v15 = (_SERVICE_STATUS *)a2[6];
        v12 = (GASValue *)GASFnCall::Arg(this: a2, a2: 2);
        v9 = GASValue::ToUInt32(this: v12, a2: v5, a3: a1, a4: v15);
      }
      GFxTextEditorKit::CopyToClipboard(this: (GFxTextEditorKit *)v5, startPos: (unsigned int)v17, endPos: v9, a4: v16);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5390
// Name: public: static void GFxEditTextCharacter::CutToClipboard(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::CutToClipboard(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v3; // eax
  int v4; // edi
  int v5; // eax
  unsigned int v6; // ecx
  GASFnCall *v7; // edx
  unsigned int v8; // ebx
  char *v9; // eax
  GASValue *v10; // eax
  GASValue *v11; // eax
  int v12; // eax
  tagPOLYTEXTW *v13; // [esp-Ch] [ebp-18h]
  _SERVICE_STATUS *v14; // [esp-Ch] [ebp-18h]
  _SERVICE_STATUS *v15; // [esp-Ch] [ebp-18h]
  char v16; // [esp+4h] [ebp-8h]
  tagALTTABINFO *v17; // [esp+8h] [ebp-4h]
  GASFnCall *v18; // [esp+14h] [ebp+8h]

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v3 = a2[2];
    v17 = v3 != nullptr ? &v3[-3] : nullptr;
    v4 = *(_DWORD *)(v17[4].cyItem + 284);
    if ( v4 != 0 )
    {
      v5 = *(_DWORD *)(v4 + 8);
      v6 = *(_DWORD *)(v5 + 32);
      v16 = (*(_BYTE *)(v4 + 104) & 4) != 0;
      v7 = *(GASFnCall **)(v5 + 28);
      v18 = v7;
      if ( (unsigned int)v7 >= v6 )
        v18 = *(GASFnCall **)(v5 + 32);
      v8 = *(_DWORD *)(v5 + 28);
      if ( v6 >= (unsigned int)v7 )
        v8 = *(_DWORD *)(v5 + 32);
      if ( (int)a2[7] >= 1 )
      {
        v13 = (tagPOLYTEXTW *)a2[6];
        v9 = (char *)GASFnCall::Arg(this: a2, a2: 0);
        v16 = GASValue::ToBool(a1: v9, a2: a1, result: v13);
      }
      if ( (int)a2[7] >= 2 )
      {
        v14 = (_SERVICE_STATUS *)a2[6];
        v10 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
        v18 = (GASFnCall *)GASValue::ToUInt32(this: v10, a2: v4, a3: a1, a4: v14);
      }
      if ( (int)a2[7] >= 3 )
      {
        v15 = (_SERVICE_STATUS *)a2[6];
        v11 = (GASValue *)GASFnCall::Arg(this: a2, a2: 2);
        v8 = GASValue::ToUInt32(this: v11, a2: v4, a3: a1, a4: v15);
      }
      GFxTextEditorKit::CutToClipboard(this: (GFxTextEditorKit *)v4, startPos: (unsigned int)v18, endPos: v8, a4: v16);
      v12 = (*(int (__thiscall **)(tagALTTABINFO *))(v17->cbSize + 84))(a1: v17);
      if ( v12 != 0 )
        *(_DWORD *)(v12 + 9332) |= 0x400u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E54A0
// Name: public: static void GFxEditTextCharacter::PasteFromClipboard(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::PasteFromClipboard(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v3; // eax
  int v4; // edi
  int v5; // eax
  unsigned int v6; // ecx
  GASFnCall *v7; // edx
  unsigned int v8; // ebx
  char *v9; // eax
  GASValue *v10; // eax
  GASValue *v11; // eax
  int v12; // eax
  tagPOLYTEXTW *v13; // [esp-Ch] [ebp-18h]
  _SERVICE_STATUS *v14; // [esp-Ch] [ebp-18h]
  _SERVICE_STATUS *v15; // [esp-Ch] [ebp-18h]
  char v16; // [esp+4h] [ebp-8h]
  tagALTTABINFO *v17; // [esp+8h] [ebp-4h]
  GASFnCall *v18; // [esp+14h] [ebp+8h]

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v3 = a2[2];
    v17 = v3 != nullptr ? &v3[-3] : nullptr;
    v4 = *(_DWORD *)(v17[4].cyItem + 284);
    if ( v4 != 0 )
    {
      v5 = *(_DWORD *)(v4 + 8);
      v6 = *(_DWORD *)(v5 + 32);
      v16 = (*(_BYTE *)(v4 + 104) & 4) != 0;
      v7 = *(GASFnCall **)(v5 + 28);
      v18 = v7;
      if ( (unsigned int)v7 >= v6 )
        v18 = *(GASFnCall **)(v5 + 32);
      v8 = *(_DWORD *)(v5 + 28);
      if ( v6 >= (unsigned int)v7 )
        v8 = *(_DWORD *)(v5 + 32);
      if ( (int)a2[7] >= 1 )
      {
        v13 = (tagPOLYTEXTW *)a2[6];
        v9 = (char *)GASFnCall::Arg(this: a2, a2: 0);
        v16 = GASValue::ToBool(a1: v9, a2: a1, result: v13);
      }
      if ( (int)a2[7] >= 2 )
      {
        v14 = (_SERVICE_STATUS *)a2[6];
        v10 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
        v18 = (GASFnCall *)GASValue::ToUInt32(this: v10, a2: v4, a3: a1, a4: v14);
      }
      if ( (int)a2[7] >= 3 )
      {
        v15 = (_SERVICE_STATUS *)a2[6];
        v11 = (GASValue *)GASFnCall::Arg(this: a2, a2: 2);
        v8 = GASValue::ToUInt32(this: v11, a2: v4, a3: a1, a4: v15);
      }
      GFxTextEditorKit::PasteFromClipboard(this: (GFxTextEditorKit *)v4, a2: (unsigned int)v18, a3: v8, a4: v16);
      v12 = (*(int (__thiscall **)(tagALTTABINFO *))(v17->cbSize + 84))(a1: v17);
      if ( v12 != 0 )
        *(_DWORD *)(v12 + 9332) |= 0x400u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E55B0
// Name: public: virtual void GFxEditTextCharacter::ClearCompositionString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::ClearCompositionString(GFxEditTextCharacter *this)
{
  int v2; // eax
  GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *v3; // esi
  int v4; // eax

  v2 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v2 != 0 )
  {
    v3 = *(GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> **)(v2 + 20);
    if ( v3 != nullptr )
    {
      ++v3->Size;
      GFxTextCompositionString::SetText(this: v3);
      GFxTextCompositionString::SetPosition(this: v3);
    }
    v4 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
    if ( v4 != 0 )
      *(_DWORD *)(v4 + 9332) |= 0x400u;
    if ( v3 != nullptr )
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5610
// Name: public: virtual void GFxEditTextCharacter::ReleaseCompositionString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::ReleaseCompositionString(GFxEditTextCharacter *this)
{
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v2; // ecx
  int v3; // eax
  void *v4; // [esp+0h] [ebp-4h]

  v2 = *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)(*((_DWORD *)this + 47) + 284);
  if ( v2 != nullptr )
  {
    GFxTextEditorKit::ReleaseCompositionString(this: v2, a2: v4);
    v3 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 9332) |= 0x400u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5650
// Name: public: virtual void GFxEditTextCharacter::SetCompositionStringText(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetCompositionStringText(
        GFxEditTextCharacter *this,
        const wchar_t *a2,
        unsigned int a3)
{
  int v4; // eax
  GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *v5; // esi
  int v6; // eax

  v4 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v4 != 0 )
  {
    v5 = *(GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> **)(v4 + 20);
    if ( v5 != nullptr )
    {
      ++v5->Size;
      GFxTextCompositionString::SetText(this: v5);
      v6 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
      if ( v6 != 0 )
        *(_DWORD *)(v6 + 9332) |= 0x400u;
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E56B0
// Name: public: virtual void GFxEditTextCharacter::SetCompositionStringPosition(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetCompositionStringPosition(GFxEditTextCharacter *this, unsigned int a2)
{
  int v3; // eax
  GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *v4; // esi
  int v5; // eax

  v3 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v3 != 0 )
  {
    v4 = *(GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> **)(v3 + 20);
    if ( v4 != nullptr )
    {
      ++v4->Size;
      GFxTextCompositionString::SetPosition(this: v4);
      v5 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 9332) |= 0x400u;
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5700
// Name: public: virtual unsigned int GFxEditTextCharacter::GetCompositionStringPosition(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxEditTextCharacter::GetCompositionStringPosition(GFxEditTextCharacter *this)
{
  int v1; // eax
  GRefCountNTSImpl *v2; // ecx
  GRefCountNTSImpl_vtbl *v3; // esi

  v1 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v1 == 0 )
    return -1;
  v2 = *(GRefCountNTSImpl **)(v1 + 20);
  if ( v2 == nullptr )
    return -1;
  ++v2->RefCount;
  v3 = v2[6].__vftable;
  GRefCountNTSImpl::Release(this: v2);
  return (unsigned int)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100E5730
// Name: public: virtual unsigned int GFxEditTextCharacter::GetCompositionStringLength(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxEditTextCharacter::GetCompositionStringLength(GFxEditTextCharacter *this)
{
  int v1; // eax
  int v2; // esi
  unsigned int Length; // edi

  v1 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v1 == 0 )
    return 0;
  v2 = *(_DWORD *)(v1 + 20);
  if ( v2 == 0 )
    return 0;
  ++*(_DWORD *)(v2 + 4);
  Length = GFxTextParagraph::GetLength(this: (GFxResourceId *)(v2 + 20));
  GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v2);
  return Length;
}

//------------------------------------------------------------------------------
// Address: 0x100E5770
// Name: public: virtual void GFxEditTextCharacter::SetCursorInCompositionString(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetCursorInCompositionString(GFxEditTextCharacter *this, unsigned int a2)
{
  int v3; // eax
  GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *v4; // esi
  int v5; // eax

  v3 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v3 != 0 )
  {
    v4 = *(GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> **)(v3 + 20);
    if ( v4 != nullptr )
    {
      ++v4->Size;
      GFxTextCompositionString::SetCursorPosition(this: v4);
      v5 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 9332) |= 0x400u;
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E57C0
// Name: public: virtual void GFxEditTextCharacter::HighlightCompositionStringText(unsigned int,unsigned int,enum GFxTextIMEStyle::Category)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::HighlightCompositionStringText(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // eax
  GRefCountNTSImpl *v6; // esi
  int v7; // eax

  v5 = *(_DWORD *)(*(this + 47) + 284);
  if ( v5 != 0 )
  {
    v6 = *(GRefCountNTSImpl **)(v5 + 20);
    if ( v6 != nullptr )
    {
      ++v6->RefCount;
      GFxTextCompositionString::HighlightText(a1: v6, a2, a3, a4);
      v7 = (*(int (__thiscall **)(_DWORD *))(*this + 84))(a1: this);
      if ( v7 != 0 )
        *(_DWORD *)(v7 + 9332) |= 0x400u;
      GRefCountNTSImpl::Release(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5820
// Name: public: virtual unsigned long GFxEditTextCharacter::GetSelectedTextColor(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxEditTextCharacter::GetSelectedTextColor(GFxEditTextCharacter *this)
{
  int v1; // eax

  v1 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v1 != 0 )
    return *(_DWORD *)(v1 + 92);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100E5840
// Name: public: virtual unsigned long GFxEditTextCharacter::GetSelectedBackgroundColor(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxEditTextCharacter::GetSelectedBackgroundColor(GFxEditTextCharacter *this)
{
  int v1; // eax

  v1 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v1 != 0 )
    return *(_DWORD *)(v1 + 88);
  else
    return -16777216;
}

//------------------------------------------------------------------------------
// Address: 0x100E5860
// Name: public: struct GFxTextIMEStyle __near * GASTextFieldObject::GetIMECompositionStringStyles(void)
// Source: json
//------------------------------------------------------------------------------
const GPtr<GFxAmpServer::SourceFileInfo> *__thiscall GASTextFieldObject::GetIMECompositionStringStyles(
        GPtr<GFxAmpServer::SourceFileInfo> *this)
{
  GPtr<GFxAmpServer::SourceFileInfo> *v1; // esi

  if ( *((_DWORD *)this + 14) != 0 )
    return *((const GPtr<GFxAmpServer::SourceFileInfo> **)this + 14);
  while ( 1 )
  {
    v1 = *((GPtr<GFxAmpServer::SourceFileInfo> **)this + 6);
    if ( v1 == nullptr
      || ((int (__thiscall *)(GPtr<GFxAmpServer::SourceFileInfo> *))v1[4].pObject->Filename.pData)(a1: &v1[4]) != 13 )
    {
      break;
    }
    this = v1;
    if ( v1[14].pObject != nullptr )
      return *((const GPtr<GFxAmpServer::SourceFileInfo> **)this + 14);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E5890
// Name: public: GFxStyledText::HTMLImageTagInfo::~HTMLImageTagInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::HTMLImageTagInfo::~HTMLImageTagInfo(ILocalize *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi

  v2 = (volatile LONG *)(*(_DWORD *)(this + 3) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (volatile LONG *)(*(_DWORD *)(this + 1) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  if ( this->__vftable != nullptr )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)this->__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x100E59A0
// Name: public: class GColor GFxTextHighlightInfo::GetTextColor(void)const
// Source: json
//------------------------------------------------------------------------------
struct GColor __thiscall GFxTextHighlightInfo::GetTextColor(GFxTextHighlightInfo *this, _DWORD *a2)
{
  int v3; // [esp+0h] [ebp-4h]

  if ( (*((_BYTE *)this + 12) & 0x10) != 0 )
    v3 = *((_DWORD *)this + 1);
  else
    v3 = 0;
  *a2 = v3;
  return (struct GColor)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100E59E0
// Name: public: class GColor GFxTextHighlightInfo::GetUnderlineColor(void)const
// Source: json
//------------------------------------------------------------------------------
struct GColor __thiscall GFxTextHighlightInfo::GetUnderlineColor(GFxTextHighlightInfo *this, _DWORD *a2)
{
  int v3; // [esp+0h] [ebp-4h]

  if ( (*((_BYTE *)this + 12) & 0x20) != 0 )
    v3 = *((_DWORD *)this + 2);
  else
    v3 = 0;
  *a2 = v3;
  return (struct GColor)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100E5A20
// Name: public: GFxTextImageDesc::GFxTextImageDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextImageDesc::GFxTextImageDesc(CBaseResourcePrecacher *this)
{
  this->__vftable = (CBaseResourcePrecacher_vtbl *)&GRefCountImplCore::`vftable';
  this->m_nSystem = SERVERGLOBAL;
  this->__vftable = (CBaseResourcePrecacher_vtbl *)&GFxTextImageDesc::`vftable';
  this->m_pName = nullptr;
  this->m_pNext = nullptr;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  GMatrix2D::SetIdentity(this: (float *)this + 8);
}

//------------------------------------------------------------------------------
// Address: 0x100E5AA0
// Name: public: virtual unsigned int GFxTextDocView::DocumentListener::Editor_OnKey(class GFxTextEditorKit __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::DocumentListener::Editor_OnKey(
        GArrayBase<GArrayData<GPtr<GFxMovieStats>,GAllocatorLH<GPtr<GFxMovieStats>,2>,GArrayDefaultPolicy> > *this,
        GMemoryHeap *__formal,
        unsigned int keyCode)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100E5AB0
// Name: public: virtual wchar_t GFxTextDocView::DocumentListener::Editor_OnCharacter(class GFxTextEditorKit __near &,wchar_t)
// Source: json
//------------------------------------------------------------------------------
wchar_t __thiscall GFxTextDocView::DocumentListener::Editor_OnCharacter(
        GFxTextDocView::DocumentListener *this,
        struct GFxTextEditorKit *a2,
        wchar_t srcChar)
{
  return srcChar;
}

//------------------------------------------------------------------------------
// Address: 0x100E5AC0
// Name: public: GFxTextIMEStyle::GFxTextIMEStyle(void)
// Source: json
//------------------------------------------------------------------------------
GFxTextIMEStyle *__thiscall GFxTextIMEStyle::GFxTextIMEStyle(GFxTextIMEStyle *this)
{
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = 0;
  *((_BYTE *)this + 12) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_BYTE *)this + 28) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_BYTE *)this + 44) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_BYTE *)this + 60) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_BYTE *)this + 80) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E5B40
// Name: public: void GFxEditTextCharacterDef::Read(class GFxLoadProcess __near *,enum GFxTagType)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxEditTextCharacterDef::Read(int this, HBITMAP__ p, int a3)
{
  int v4; // esi
  float *v5; // ebx
  bool v6; // bl
  int v7; // edx
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // eax
  unsigned __int16 v12; // dx
  int v13; // eax
  unsigned int v14; // eax
  IShaderDevice *v15; // ecx
  _TRIVERTEX *v16; // eax
  int v17; // ecx
  int v18; // eax
  unsigned __int16 v19; // dx
  int v20; // eax
  int v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  __int16 v31; // cx
  int v32; // eax
  _cpinfo *v34; // [esp+20h] [ebp-1Ch]
  _TRIVERTEX *hres; // [esp+2Ch] [ebp-10h] BYREF
  IShaderDevice *v36; // [esp+30h] [ebp-Ch]
  int v37; // [esp+34h] [ebp-8h]
  bool hasText; // [esp+38h] [ebp-4h]
  bool hasLayout; // [esp+39h] [ebp-3h]
  bool hasMaxLength; // [esp+3Ah] [ebp-2h]
  bool hasColor; // [esp+3Bh] [ebp-1h]
  HBITMAP__ pa; // [esp+44h] [ebp+8h]
  HBITMAP__ pb; // [esp+44h] [ebp+8h]
  HBITMAP__ pc; // [esp+44h] [ebp+8h]
  float pd; // [esp+44h] [ebp+8h]

  if ( *(_DWORD *)(p.unused + 804) != 0 )
    v4 = *(_DWORD *)(p.unused + 804);
  else
    v4 = p.unused + 40;
  v5 = (float *)(this + 28);
  GFxStream::ReadRect(this: (GFxStream *)v4, a2: this + 28);
  GFxLogBase<GFxStream>::LogParse(
    this: (tagBITMAPINFOHEADER *)v4,
    a2: (int)"  TextRect = { l: %f, t: %f, r: %f, b: %f }\n",
    *v5,
    *(float *)(this + 32),
    *(float *)(this + 36),
    *(float *)(this + 40));
  *(_BYTE *)(v4 + 21) = 0;
  hasText = GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0;
  if ( GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0 )
    *(_WORD *)(this + 80) |= 1u;
  else
    *(_WORD *)(this + 80) &= ~1u;
  if ( GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0 )
    *(_WORD *)(this + 80) |= 2u;
  else
    *(_WORD *)(this + 80) &= ~2u;
  if ( GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0 )
    *(_WORD *)(this + 80) |= 4u;
  else
    *(_WORD *)(this + 80) &= ~4u;
  if ( GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0 )
    *(_WORD *)(this + 80) |= 8u;
  else
    *(_WORD *)(this + 80) &= ~8u;
  GFxLogBase<GFxStream>::LogParse(
    this: (tagBITMAPINFOHEADER *)v4,
    a2: (int)"  WordWrap = %d, Multiline = %d, Password = %d, ReadOnly = %d\n",
    *(_BYTE *)(this + 80) & 1,
    (*(_WORD *)(this + 80) & 2) != 0,
    (*(_WORD *)(this + 80) & 4) != 0,
    (*(_WORD *)(this + 80) & 8) != 0);
  hasColor = GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0;
  hasMaxLength = GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0;
  v6 = GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0;
  GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u);
  if ( GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0 )
    *(_WORD *)(this + 80) |= 0x10u;
  else
    *(_WORD *)(this + 80) &= ~0x10u;
  hasLayout = GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0;
  if ( GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0 )
    *(_WORD *)(this + 80) &= ~0x20u;
  else
    *(_WORD *)(this + 80) |= 0x20u;
  if ( GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0 )
    *(_WORD *)(this + 80) |= 0x40u;
  else
    *(_WORD *)(this + 80) &= ~0x40u;
  GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u);
  if ( GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0 )
    *(_WORD *)(this + 80) |= 0x80u;
  else
    *(_WORD *)(this + 80) &= ~0x80u;
  if ( GFxStream::ReadUInt(this: (GFxStream *)v4, a2: 1u) != 0 )
    *(_WORD *)(this + 80) &= ~0x100u;
  else
    *(_WORD *)(this + 80) |= 0x100u;
  GFxLogBase<GFxStream>::LogParse(
    this: (tagBITMAPINFOHEADER *)v4,
    a2: (int)"  AutoSize = %d, Selectable = %d, Border = %d, Html = %d, UseDeviceFont = %d\n",
    (*(_WORD *)(this + 80) & 0x10) != 0,
    (*(_WORD *)(this + 80) & 0x20) != 0,
    (*(_WORD *)(this + 80) & 0x40) != 0,
    (*(_WORD *)(this + 80) & 0x80) != 0,
    (*(_WORD *)(this + 80) & 0x100) != 0);
  if ( v6 )
  {
    v7 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
    *(_BYTE *)(v4 + 21) = 0;
    if ( v7 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v8 = *(_DWORD *)(v4 + 44);
    v9 = (unsigned __int16)(*(unsigned __int8 *)(*(_DWORD *)(v4 + 60) + v8)
                          | (*(unsigned __int8 *)(*(_DWORD *)(v4 + 60) + v8 + 1) << 8));
    *(_DWORD *)(v4 + 44) = v8 + 2;
    *(_DWORD *)(this + 24) = v9;
    v10 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
    *(_BYTE *)(v4 + 21) = 0;
    if ( v10 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v11 = *(_DWORD *)(v4 + 44);
    v12 = *(_WORD *)(*(_DWORD *)(v4 + 60) + v11);
    *(_DWORD *)(v4 + 44) = v11 + 2;
    v13 = *(unsigned __int16 *)(this + 24);
    v37 = v12;
    *(float *)(this + 44) = (float)v12;
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v4, a2: (int)"  HasFont: font id = %d\n", v13);
    v14 = *(_DWORD *)(this + 24);
    hres = nullptr;
    v36 = nullptr;
    GFxMovieDataDef::LoadTaskData::GetResourceHandle(
      this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(p.unused + 32),
      phandle: &hres,
      rid: v14);
    v15 = v36;
    if ( hres == nullptr && v36 != nullptr )
    {
      GRefCountImpl::AddRef(this: v36);
      v15 = v36;
    }
    if ( *(_DWORD *)(this + 16) == 0 && *(_DWORD *)(this + 20) != 0 )
    {
      GFxResource::Release(this: *(IShaderDevice **)(this + 20));
      v15 = v36;
    }
    v16 = hres;
    *(_DWORD *)(this + 16) = hres;
    *(_DWORD *)(this + 20) = v15;
    if ( v16 == nullptr && v15 != nullptr )
      GFxResource::Release(this: v15);
  }
  if ( hasColor )
  {
    GFxStream::ReadRgba(this: (GFxStream *)v4, a2: (struct GColor *)(this + 48));
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v4, a2: (int)"  HasColor\n");
  }
  if ( hasMaxLength )
  {
    v17 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
    *(_BYTE *)(v4 + 21) = 0;
    if ( v17 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v18 = *(_DWORD *)(v4 + 44);
    v19 = *(_WORD *)(*(_DWORD *)(v4 + 60) + v18);
    *(_DWORD *)(v4 + 44) = v18 + 2;
    *(_DWORD *)(this + 52) = v19;
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v4, a2: (int)"  HasMaxLength: len = %d\n", v19);
  }
  if ( hasLayout )
  {
    *(_WORD *)(this + 80) |= 0x200u;
    v20 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
    *(_BYTE *)(v4 + 21) = 0;
    if ( v20 < 1 )
      GFxStream::PopulateBuffer1(result: v34);
    v21 = *(_DWORD *)(v4 + 44);
    v22 = *(unsigned __int8 *)(v21 + *(_DWORD *)(v4 + 60));
    *(_DWORD *)(v4 + 44) = v21 + 1;
    *(_DWORD *)(this + 84) = v22;
    v23 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
    *(_BYTE *)(v4 + 21) = 0;
    if ( v23 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v24 = *(_DWORD *)(v4 + 44);
    pa.unused = (unsigned __int16)(*(unsigned __int8 *)(*(_DWORD *)(v4 + 60) + v24)
                                 | (*(unsigned __int8 *)(*(_DWORD *)(v4 + 60) + v24 + 1) << 8));
    *(_DWORD *)(v4 + 44) = v24 + 2;
    *(float *)(this + 56) = (float)pa.unused;
    v25 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
    *(_BYTE *)(v4 + 21) = 0;
    if ( v25 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v26 = *(_DWORD *)(v4 + 44);
    pb.unused = (unsigned __int16)(*(unsigned __int8 *)(*(_DWORD *)(v4 + 60) + v26)
                                 | (*(unsigned __int8 *)(*(_DWORD *)(v4 + 60) + v26 + 1) << 8));
    *(_DWORD *)(v4 + 44) = v26 + 2;
    *(float *)(this + 60) = (float)pb.unused;
    v27 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
    *(_BYTE *)(v4 + 21) = 0;
    if ( v27 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v28 = *(_DWORD *)(v4 + 44);
    pc.unused = *(__int16 *)(*(_DWORD *)(v4 + 60) + v28);
    *(_DWORD *)(v4 + 44) = v28 + 2;
    *(float *)(this + 64) = (float)pc.unused;
    v29 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
    *(_BYTE *)(v4 + 21) = 0;
    if ( v29 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v30 = *(_DWORD *)(v4 + 44);
    v31 = *(_WORD *)(*(_DWORD *)(v4 + 60) + v30);
    *(_DWORD *)(v4 + 44) = v30 + 2;
    v32 = *(_DWORD *)(this + 84);
    pd = (float)v31;
    *(float *)(this + 68) = pd;
    GFxLogBase<GFxStream>::LogParse(
      this: (tagBITMAPINFOHEADER *)v4,
      a2: (int)"  HasLayout: alignment = %d, leftmarg = %f, rightmarg = %f, indent = %f, leading = %f\n",
      v32,
      *(float *)(this + 56),
      *(float *)(this + 60),
      *(float *)(this + 64),
      pd);
  }
  GFxStream::ReadString(this: (GFxStream *)v4, a2: (struct GString *)(this + 76));
  if ( hasText )
    GFxStream::ReadString(this: (GFxStream *)v4, a2: (struct GString *)(this + 72));
  return GFxLogBase<GFxStream>::LogParse(
           this: (tagBITMAPINFOHEADER *)v4,
           a2: (int)"EditTextChar, varname = %s, text = %s\n",
           (const char *)((*(_DWORD *)(this + 76) & 0xFFFFFFFC) + 8),
           (const char *)((*(_DWORD *)(this + 72) & 0xFFFFFFFC) + 8));
}

//------------------------------------------------------------------------------
// Address: 0x100E6090
// Name: public: void GFxEditTextCharacterDef::InitEmptyTextDef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacterDef::InitEmptyTextDef(
        GArrayData<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *this)
{
  *((_WORD *)this + 40) |= 0x800u;
  *((_DWORD *)this + 12) = -16777216;
  *((float *)this + 11) = 240.0;
  *((_WORD *)this + 40) |= 0x528u;
}

//------------------------------------------------------------------------------
// Address: 0x100E60D0
// Name: public: virtual bool GFxEditTextCharacter::TextDocumentListener::View_OnLineFormat(class GFxTextDocView __near &,struct GFxTextDocView::LineFormatDesc __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxEditTextCharacter::TextDocumentListener::View_OnLineFormat(
        GFxEditTextCharacter::TextDocumentListener *this,
        struct GFxTextDocView *a2,
        struct GFxTextDocView::LineFormatDesc *a3)
{
  int v3; // eax
  IShaderAPI *v4; // edi
  int v5; // edx
  double v6; // st7
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  int v12; // ecx
  double v13; // st6
  float *v14; // ecx
  int v15; // eax
  _DWORD v17[4]; // [esp+8h] [ebp-30h] BYREF
  unsigned int v18; // [esp+18h] [ebp-20h]
  float i; // [esp+1Ch] [ebp-1Ch]
  float v20; // [esp+20h] [ebp-18h]
  float v21; // [esp+24h] [ebp-14h]
  float v22; // [esp+28h] [ebp-10h]
  char v23; // [esp+2Ch] [ebp-Ch]
  int v24; // [esp+30h] [ebp-8h]
  char v25; // [esp+34h] [ebp-4h]

  v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 61) + 84))(a1: (char *)this - 244);
  v4 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v3 + 8) + 12))(a1: v3 + 8, a2: 3);
  if ( v4 != nullptr )
  {
    v5 = *((_DWORD *)a3 + 2);
    v6 = *((float *)a3 + 6) / 20.0;
    v7 = *((_DWORD *)a3 + 3);
    v17[0] = *(_DWORD *)a3;
    v8 = *((_DWORD *)a3 + 10);
    v17[2] = v5;
    v9 = *((_DWORD *)a3 + 1);
    v24 = v8;
    LOBYTE(v8) = *((_BYTE *)a3 + 36);
    v17[3] = v7;
    v10 = *((_DWORD *)a3 + 4);
    v17[1] = v9;
    LOBYTE(v9) = *((_BYTE *)a3 + 44);
    v23 = v8;
    v11 = 0;
    v18 = v10;
    v25 = v9;
    v20 = v6;
    v22 = *((float *)a3 + 8) / 20.0;
    v21 = *((float *)a3 + 7) / 20.0;
    for ( i = *((float *)a3 + 5) / 20.0; v11 < v18; *v14 = v13 / 20.0 )
    {
      v12 = *((_DWORD *)a3 + 2);
      v13 = *(float *)(v12 + 4 * v11);
      v14 = (float *)(v12 + 4 * v11++);
    }
    if ( ((unsigned __int8 (__thiscall *)(IShaderAPI *, _DWORD *))v4->GetSceneFogColor)(a1: v4, a2: v17) != 0 )
    {
      v15 = v24;
      *((_BYTE *)a3 + 44) = v25;
      *((_DWORD *)a3 + 10) = v15;
      GRefCountImpl::Release(this: v4);
      return 1;
    }
    GRefCountImpl::Release(this: v4);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E61C0
// Name: public: virtual void GFxEditTextCharacter::TextDocumentListener::View_OnChanged(class GFxTextDocView __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::TextDocumentListener::View_OnChanged(
        GFxEditTextCharacter::TextDocumentListener *this,
        struct GFxTextDocView *a2)
{
  int v2; // eax

  v2 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 61) + 84))(a1: (char *)this - 244);
  if ( v2 != 0 )
    *(_DWORD *)(v2 + 9332) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x100E6220
// Name: public: static void GFxEditTextCharacter::TextDocumentListener::BroadcastMessage(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GFxEditTextCharacter::TextDocumentListener::BroadcastMessage(GASFnCall *a1)
{
  GASFnCall *v1; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v2; // edi
  unsigned __int8 *v3; // eax
  GASFnCall *v4; // eax
  bool v5; // zf

  v1 = a1;
  v2 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
  v3 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 0);
  GASValue::ToStringImpl(this: v3, a2: (int *)&a1, a3: v2, precision: -1, debug: false);
  GASAsBroadcaster::BroadcastMessage(
    a1: (struct GASEnvironment *)v1[6],
    eventName: (_IMAGE_SYMBOL_EX *)v1[2],
    a3: (const struct GASString *)&a1,
    nArgs: (char *)&v1[7][-1].ptStart.y + 3,
    firstArgBottomIndex: ((v1[6]->cColumns - v1[6]->cRows) >> 4) + 32 * v1[6]->cyItem - 33);
  v4 = a1;
  v5 = a1[2] == (GASFnCall)1;
  a1[2] = (GASFnCall)((char *)a1[2] - 1);
  if ( v5 )
    GASStringNode::ReleaseNode(a1: (int)v4);
}

//------------------------------------------------------------------------------
// Address: 0x100E6290
// Name: public: static void GFxEditTextCharacter::RemoveTextField(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GFxEditTextCharacter::RemoveTextField(const struct GASFnCall *a1)
{
  int v1; // eax
  int v2; // esi
  int v3; // eax

  if ( *((_DWORD *)a1 + 2) != 0
    && (*(int (__thiscall **)(_DWORD))(**((_DWORD **)a1 + 2) + 8))(a1: *((_DWORD *)a1 + 2)) == 4 )
  {
    v1 = *((_DWORD *)a1 + 2);
    if ( v1 != 0 )
      v2 = v1 - 120;
    else
      v2 = 0;
    if ( *(int *)(v2 + 20) >= 0x4000 )
    {
      GFxASCharacter::RemoveDisplayObject(this: (GFxASCharacter *)v2);
    }
    else
    {
      v3 = *(_DWORD *)(v2 + 148);
      if ( v3 == 0 )
      {
        GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v2);
        if ( v3 == 0 )
          v3 = *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v2 + 108))(a1: v2) + 120);
      }
      GFxLogBase<GFxCharacter>::LogScriptWarning(
        a1: v2 + 12,
        a2: (int)"%s.removeMovieClip() failed - depth must be >= 0\n",
        **(const char ***)(v3 + 8));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6310
// Name: public: virtual class GRect<float> GFxEditTextCharacter::GetCursorBounds(unsigned int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxEditTextCharacter::GetCursorBounds(
        GFxTextDocView **this,
        float *a2,
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::Iterator *result,
        float *a4,
        float *a5)
{
  double v5; // st7

  v5 = 0.0;
  if ( *((_DWORD *)*(this + 47) + 71) != 0 )
  {
    if ( (unsigned __int8)GFxTextEditorKit::CalcCursorRectOnScreen(result) != 0 )
    {
      if ( a4 != nullptr )
        *a4 = (float)GFxTextDocView::GetHScrollOffset(this: *(this + 47));
      if ( a5 != nullptr )
        *a5 = (float)GFxTextDocView::GetVScrollOffset(this: *(this + 47));
      *a2 = 0.0;
      a2[1] = 0.0;
      a2[2] = 0.0;
      a2[3] = 0.0;
      return a2;
    }
    v5 = 0.0;
  }
  if ( a4 != nullptr )
    *a4 = v5;
  if ( a5 != nullptr )
    *a5 = v5;
  *a2 = v5;
  a2[1] = v5;
  a2[2] = v5;
  a2[3] = v5;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100E63F0
// Name: public: virtual class GFxFontResource __near * GFxEditTextCharacter::GetFontResource(void)
// Source: json
//------------------------------------------------------------------------------
ExprNode *__usercall GFxEditTextCharacter::GetFontResource@<eax>(GFxEditTextCharacter *this@<ecx>, Kind a2@<edi>)
{
  int v3; // eax
  IShaderDevice *v5; // eax
  IShaderDevice *v6; // edi
  IShaderDevice *v7; // eax
  ExprNode *v8; // esi
  ExprNode *v9; // [esp+0h] [ebp-Ch]
  ExprNode *h; // [esp+4h] [ebp-8h] BYREF

  v3 = *((_DWORD *)this + 46);
  if ( *(_WORD *)(v3 + 24) == 0 )
    return nullptr;
  GFxResourceBinding::GetResourceData(
    this: *((CExpressionEvaluator **)this + 48),
    &h,
    ha: (const GenericThreadLocals::CThreadLocal<int> *)(v3 + 16),
    a4: a2,
    a5: v9,
    a6: h);
  if ( h == nullptr )
  {
    v5 = (IShaderDevice *)(*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 168))(a1: this);
    v6 = v5;
    if ( v5 != nullptr )
    {
      GRefCountImpl::AddRef(this: v5);
      GFxLogBase<GFxLog>::LogError(
        this: (GFxLogBase<GFxLog> *)&v6[3],
        pfmt: "Error: Resource for font id = %d is not found in text field id = %d, def text = '%s'\n",
        *(unsigned __int16 *)(*((_DWORD *)this + 46) + 24),
        *((unsigned __int16 *)this + 8),
        (*(_DWORD *)(*((_DWORD *)this + 46) + 72) & 0xFFFFFFFC) + 8);
LABEL_9:
      GRefCountImpl::Release(this: (IShaderAPI *)v6);
      goto LABEL_10;
    }
    goto LABEL_10;
  }
  if ( (((int (__thiscall *)(ExprNode *))h->left->kind)(a1: h) & 0xFF00) != 0x200 )
  {
    v7 = (IShaderDevice *)(*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 168))(a1: this);
    v6 = v7;
    if ( v7 != nullptr )
    {
      GRefCountImpl::AddRef(this: v7);
      GFxLogBase<GFxLog>::LogError(
        this: (GFxLogBase<GFxLog> *)&v6[3],
        pfmt: "Error: Font id = %d is referring to non-font resource in text field id = %d, def text = '%s'\n",
        *(unsigned __int16 *)(*((_DWORD *)this + 46) + 24),
        *((unsigned __int16 *)this + 8),
        (*(_DWORD *)(*((_DWORD *)this + 46) + 72) & 0xFFFFFFFC) + 8);
      goto LABEL_9;
    }
LABEL_10:
    if ( h != nullptr )
      GFxResource::Release(this: (IShaderDevice *)h);
    return nullptr;
  }
  v8 = h;
  if ( h != nullptr )
    GFxResource::Release(this: (IShaderDevice *)h);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100E64F0
// Name: public: virtual void GFxEditTextCharacter::CreateCompositionString(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxEditTextCharacter::CreateCompositionString(
        GFxEditTextCharacter *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *a2@<esi>)
{
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *CompositionString; // eax
  GFxTextCompositionString *v4; // esi
  GPtr<GFxAmpServer::SourceFileInfo> *v5; // ecx
  const GPtr<GFxAmpServer::SourceFileInfo> *IMECompositionStringStyles; // eax
  int v7; // eax

  if ( *(_DWORD *)(*((_DWORD *)this + 47) + 284) != 0 )
  {
    CompositionString = GFxTextEditorKit::CreateCompositionString(result: a2);
    v4 = (GFxTextCompositionString *)CompositionString;
    if ( CompositionString != nullptr )
      ++CompositionString->Index;
    v5 = *((GPtr<GFxAmpServer::SourceFileInfo> **)this + 66);
    if ( v5 != nullptr )
    {
      IMECompositionStringStyles = GASTextFieldObject::GetIMECompositionStringStyles(this: v5);
      if ( IMECompositionStringStyles != nullptr )
        GFxTextCompositionString::UseStyles(this: v4, a2: (const struct GFxTextIMEStyle *)IMECompositionStringStyles);
    }
    GFxTextCompositionString::SetText(this: (GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *)v4);
    GFILEFile::GetErrorCode(this: *(CVTFTexture **)(*((_DWORD *)this + 47) + 284));
    GFxTextCompositionString::SetPosition(this: (GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *)v4);
    v7 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
    if ( v7 != 0 )
      *(_DWORD *)(v7 + 9332) |= 0x400u;
    if ( v4 != nullptr )
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6580
// Name: public: virtual enum GASObjectInterface::ObjectType GASTextFieldObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASTextFieldObject::GetObjectType(GPtr<GFxAmpServer::SourceFileInfo> *this)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x100E65A0
// Name: public: GFxTextIMEStyle::GFxTextIMEStyle(struct GFxTextIMEStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextIMEStyle::GFxTextIMEStyle(
        GPtr<GFxAmpMemFragReport> *this,
        const GPtr<GFxAmpMemFragReport> *__that)
{
  this->pObject = __that->pObject;
  *(this + 1) = __that[1];
  *(this + 2) = __that[2];
  *((_BYTE *)this + 12) = __that[3].pObject;
  *(this + 4) = __that[4];
  *(this + 5) = __that[5];
  *(this + 6) = __that[6];
  *((_BYTE *)this + 28) = __that[7].pObject;
  *(this + 8) = __that[8];
  *(this + 9) = __that[9];
  *(this + 10) = __that[10];
  *((_BYTE *)this + 44) = __that[11].pObject;
  *(this + 12) = __that[12];
  *(this + 13) = __that[13];
  *(this + 14) = __that[14];
  *((_BYTE *)this + 60) = __that[15].pObject;
  *(this + 16) = __that[16];
  *(this + 17) = __that[17];
  *(this + 18) = __that[18];
  *((_BYTE *)this + 76) = __that[19].pObject;
  *((_BYTE *)this + 80) = __that[20].pObject;
}

//------------------------------------------------------------------------------
// Address: 0x100E6630
// Name: void GFx_CSMTextSettings(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_CSMTextSettings(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  __int16 v7; // dx
  GFxStream *v8; // esi
  int v9; // eax
  _LUID_AND_ATTRIBUTES *v10; // ecx
  int v11; // edx
  _LUID_AND_ATTRIBUTES *p_HighPart; // eax
  int v13; // ecx
  _LUID_AND_ATTRIBUTES *v14; // ecx
  int v15; // edx
  const char *v16; // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v17; // ecx
  IShaderDevice *v18; // esi
  double v19; // [esp+0h] [ebp-34h]
  _TRIVERTEX *handle; // [esp+1Ch] [ebp-18h] BYREF
  IShaderDevice *v21; // [esp+20h] [ebp-14h]
  float v22; // [esp+24h] [ebp-10h]
  int v23; // [esp+28h] [ebp-Ch]
  unsigned int gridFit; // [esp+2Ch] [ebp-8h]
  unsigned int flagType; // [esp+30h] [ebp-4h]
  unsigned __int16 pa; // [esp+3Ch] [ebp+8h]

  v3 = *((char **)p + 201);
  if ( v3 == nullptr )
    v3 = (char *)p + 40;
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *((_DWORD *)v3 + 15);
  v7 = *(unsigned __int8 *)(v6 + v5 + 1);
  LOWORD(v6) = *(unsigned __int8 *)(v6 + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v8 = *((GFxStream **)p + 201);
  pa = v6 | (v7 << 8);
  if ( v8 == nullptr )
    v8 = (GFxStream *)((char *)p + 40);
  flagType = GFxStream::ReadUInt(this: v8, a2: 2u);
  gridFit = GFxStream::ReadUInt(this: v8, a2: 3u);
  v9 = (char *)v8[12] - (char *)v8[11];
  *((_BYTE *)v8 + 21) = 0;
  if ( v9 < 4 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
  v10 = (_LUID_AND_ATTRIBUTES *)v8[11];
  v11 = *((unsigned __int8 *)&(*v8[15])[0].Luid.LowPart + (_DWORD)v10)
      | ((*((unsigned __int8 *)&(*v8[15])[0].Luid.LowPart + (_DWORD)v10 + 1)
        | ((*((unsigned __int8 *)&v10->Luid.LowPart + (_DWORD)v8[15] + 2)
          | (*((unsigned __int8 *)&v10->Luid.LowPart + (_DWORD)v8[15] + 3) << 8)) << 8)) << 8);
  p_HighPart = (_LUID_AND_ATTRIBUTES *)&v10->Luid.HighPart;
  v13 = (char *)v8[12] - (char *)&v10->Luid.HighPart;
  v22 = *(float *)&v11;
  v8[11] = (GFxStream)p_HighPart;
  *((_BYTE *)v8 + 21) = 0;
  if ( v13 < 4 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
  v14 = (_LUID_AND_ATTRIBUTES *)v8[11];
  v15 = *((unsigned __int8 *)&(*v8[15])[0].Luid.LowPart + (_DWORD)v14)
      | ((*((unsigned __int8 *)&(*v8[15])[0].Luid.LowPart + (_DWORD)v14 + 1)
        | ((*((unsigned __int8 *)&v14->Luid.LowPart + (_DWORD)v8[15] + 2)
          | (*((unsigned __int8 *)&v14->Luid.LowPart + (_DWORD)v8[15] + 3) << 8)) << 8)) << 8);
  v8[11] = (GFxStream)&v14->Luid.HighPart;
  v23 = v15;
  if ( GFxStream::IsVerboseParse(this: v8) )
  {
    GFxLogBase<GFxLoadProcess>::LogParse(
      this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)pa,
      pfmt: (unsigned int)p + 20,
      a3: (int)"CSMTextSettings, id = %d\n",
      a4: pa);
    v16 = "System";
    if ( flagType != 0 )
      v16 = "Internal";
    GFxLogBase<GFxLoadProcess>::LogParse(
      this: *(&gridfittypes + gridFit),
      pfmt: (unsigned int)p + 20,
      a3: (int)"  FlagType = %s, GridFit = %s\n",
      a4: (char)v16);
    v19 = v22;
    GFxLogBase<GFxLoadProcess>::LogParse(
      this: v17,
      pfmt: (unsigned int)p + 20,
      a3: (int)"  Thinkness = %f, Sharpnesss = %f\n",
      a4: SLOBYTE(v19));
  }
  handle = nullptr;
  v21 = nullptr;
  if ( GFxMovieDataDef::LoadTaskData::GetResourceHandle(
         this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)p + 8),
         phandle: &handle,
         rid: pa) != 0 )
  {
    if ( handle != nullptr )
      return;
    v18 = v21;
    if ( v21 == nullptr )
      return;
    if ( (v21->GetBackBufferFormat(this: v21) & 0xFF00) == 0x8300 )
    {
      LOWORD(v18[20].__vftable) |= 0x400u;
    }
    else if ( (v18->GetBackBufferFormat(this: v18) & 0xFF00) == 0x8200 )
    {
      LOBYTE(v18[17].__vftable) |= 1u;
    }
  }
  if ( handle == nullptr && v21 != nullptr )
    GFxResource::Release(this: v21);
}

//------------------------------------------------------------------------------
// Address: 0x100E6820
// Name: public: struct GFxTextKeyMap::KeyMapEntry const __near * GFxTextKeyMap::Find(unsigned int,class GFxSpecialKeysState const __near &,enum GFxTextKeyMap::KeyState)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxTextKeyMap::Find(
        GenericThreadLocals::CThreadLocalPtr<IMatRenderContextInternal> *this,
        unsigned int keyCode,
        unsigned __int8 *a3,
        int a4)
{
  int v4; // ebx
  GenericThreadLocals::CThreadLocalPtr<IMatRenderContextInternal> *v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edi
  unsigned int m_index; // esi
  _DWORD *result; // eax
  int v11; // ecx
  int v12; // ecx

  v4 = keyCode;
  v6 = this + 3;
  v7 = G_LowerBoundSliced<GArray<GFxTextKeyMap::KeyMapEntry,2,GArrayDefaultPolicy>,unsigned int,int (__cdecl *)(GFxTextKeyMap::KeyMapEntry const &,unsigned int)>(
         a1: (_DWORD *)this + 3,
         a2: 0,
         a3: *((_DWORD *)this + 4),
         a4: &keyCode,
         a5: (int (__cdecl *)(int, _DWORD))`anonymous namespace'::KeyCodeComparator::Less);
  v8 = *((_DWORD *)this + 4);
  if ( v7 >= v8 )
    return nullptr;
  m_index = v6->m_index;
  result = (_DWORD *)(m_index + 16 * v7);
  if ( result[1] != v4 || result == nullptr )
    return nullptr;
  while ( result[3] != a4 || (result[2] & *a3) != result[2] )
  {
    v11 = (int)((int)result - m_index) >> 4;
    if ( v11 + 1 < v8 )
    {
      v12 = 2 * v11;
      if ( *(_DWORD *)(m_index + 8 * v12 + 20) == result[1] )
      {
        result = (_DWORD *)(m_index + 8 * v12 + 16);
        if ( m_index + 8 * v12 != -16 )
          continue;
      }
    }
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E6A00
// Name: public: GFxEditTextCharacterDef::GFxEditTextCharacterDef(void)
// Source: json
//------------------------------------------------------------------------------
const GArrayData<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *__thiscall GFxEditTextCharacterDef::GFxEditTextCharacterDef(
        char *this)
{
  float v3; // [esp+8h] [ebp-4h]

  *(_DWORD *)this = &GFxResource::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0x40000;
  *(_DWORD *)this = &GFxEditTextCharacterDef::`vftable';
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((float *)this + 7) = 0.0;
  *((float *)this + 8) = 0.0;
  *((float *)this + 9) = 0.0;
  *((float *)this + 10) = 0.0;
  *((_DWORD *)this + 13) = 0;
  *((float *)this + 11) = 1.0;
  *((float *)this + 14) = 0.0;
  *((float *)this + 15) = 0.0;
  *((float *)this + 16) = 0.0;
  *((float *)this + 17) = 0.0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(this + 72));
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(this + 76));
  *((_DWORD *)this + 21) = 0;
  *((_WORD *)this + 40) = 0;
  *(_WORD *)(this + 49) = 0;
  *(this + 48) = 0;
  *(this + 51) = -1;
  *((float *)this + 7) = 0.0;
  *((float *)this + 8) = 0.0;
  v3 = 0.0 + 0.0;
  *((float *)this + 9) = v3;
  *((float *)this + 10) = v3;
  return (const GArrayData<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100E6AA0
// Name: void GFx_DefineEditTextLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineEditTextLoader(HBITMAP__ p, const struct GFxTagInfo *tagInfo)
{
  HBITMAP__ v2; // edi
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  __int16 v7; // dx
  unsigned __int16 v8; // dx
  int v9; // ecx
  unsigned int v10; // ebx
  int (__thiscall *v11)(int, int, HBITMAP__ *); // edx
  char *v12; // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v13; // ecx
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v14; // esi

  v2.unused = p.unused;
  v3 = *(char **)(p.unused + 804);
  if ( v3 == nullptr )
    v3 = (char *)(p.unused + 40);
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *((_DWORD *)v3 + 15);
  v7 = *(unsigned __int8 *)(v6 + v5 + 1);
  LOWORD(v6) = *(unsigned __int8 *)(v6 + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v8 = v6 | (v7 << 8);
  v9 = *(_DWORD *)(*(_DWORD *)(v2.unused + 32) + 28);
  v10 = v8;
  v11 = *(int (__thiscall **)(int, int, HBITMAP__ *))(*(_DWORD *)v9 + 40);
  p.unused = 258;
  v12 = (char *)v11(a1: v9, a2: 88, a3: &p);
  if ( v12 != nullptr )
    v14 = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxEditTextCharacterDef::GFxEditTextCharacterDef(this: v12);
  else
    v14 = nullptr;
  GFxLogBase<GFxLoadProcess>::LogParse(this: v13, pfmt: v2.unused + 20, a3: (int)"EditTextChar, id = %d\n", a4: v10);
  GFxEditTextCharacterDef::Read(this: (int)v14, p: v2, a3: *(_DWORD *)tagInfo);
  if ( *(_DWORD *)(v2.unused + 760) == 0 )
    GFxMovieDataDef::LoadTaskData::AddResource(
      this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v2.unused + 32),
      rid: v10,
      pres: v14);
  if ( v14 != nullptr )
    GFxResource::Release(this: (IShaderDevice *)v14);
}

//------------------------------------------------------------------------------
// Address: 0x100E6BD0
// Name: public: void GASTextFieldObject::SetIMECompositionStringStyles(struct GFxTextIMEStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTextFieldObject::SetIMECompositionStringStyles(
        GPtr<GFxAmpServer::SourceFileInfo> *this,
        const GPtr<GFxAmpMemFragReport> *imeStyles)
{
  GPtr<GFxAmpMemFragReport> *v3; // ecx
  GPtr<GFxAmpMemFragReport> *v4; // eax
  int v5; // eax
  int v6; // [esp+4h] [ebp-4h] BYREF

  v3 = *((GPtr<GFxAmpMemFragReport> **)this + 14);
  if ( v3 != nullptr )
  {
    GFxTextIMEStyle::GFxTextIMEStyle(this: v3, __that: imeStyles);
  }
  else
  {
    v6 = 326;
    v4 = (GPtr<GFxAmpMemFragReport> *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                        this: GMemory::pGlobalHeap,
                                        a2: this,
                                        a3: 84,
                                        a4: &v6);
    if ( v4 != nullptr )
    {
      GFxTextIMEStyle::GFxTextIMEStyle(this: v4, __that: imeStyles);
      *((_DWORD *)this + 14) = v5;
    }
    else
    {
      *((_DWORD *)this + 14) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6C30
// Name: public: GFxTextClipboard::GFxTextClipboard(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAutoPtr<IMatRenderContext> *__thiscall GFxTextClipboard::GFxTextClipboard(CBaseAutoPtr<IMatRenderContext> *this)
{
  this->m_pObject = (IMatRenderContext *)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 24;
  this->m_pObject = (IMatRenderContext *)&GFxTextClipboard::`vftable';
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E6D60
// Name: public: static void GConstructorMov<struct GFxStyledText::HTMLImageTagInfo>::DestructArray(struct GFxStyledText::HTMLImageTagInfo __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GConstructorMov<GFxStyledText::HTMLImageTagInfo>::DestructArray(int a1, int a2)
{
  int i; // edi
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi

  for ( i = a1 + 44 * a2 - 44; a2 != 0; --a2 )
  {
    v3 = (volatile LONG *)(*(_DWORD *)(i + 12) & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
    v4 = (volatile LONG *)(*(_DWORD *)(i + 4) & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
    if ( *(_DWORD *)i != 0 )
      GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)i);
    i -= 44;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6FD0
// Name: protected: virtual void GASTextFieldObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTextFieldObject::Finalize_GC(int this, GFxAmpServer::SourceFileInfo *result)
{
  _DWORD *v3; // eax

  v3 = *(_DWORD **)(this + 52);
  if ( v3 != nullptr && (*v3)-- == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 56));
  JUMPOUT(0x100914D0);
}

//------------------------------------------------------------------------------
// Address: 0x100E7010
// Name: public: void GFxEditTextCharacter::GetInitialFormats(class GFxTextFormat __near *,class GFxTextParagraphFormat __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::GetInitialFormats(
        int adr,
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *a2,
        CMaterial *a3)
{
  int v6; // eax
  IShaderDevice *v7; // eax
  IShaderDevice *v8; // eax
  unsigned int v9; // eax
  GFxFontHandle *v10; // eax
  __int16 v12; // ax
  void (__thiscall *v13)(IMaterial *, float); // edx
  int v14; // eax
  __int16 v15; // cx
  int v16; // ecx
  double v17; // st7
  __int16 v18; // di
  double v19; // st6
  MaterialVarFlags_t v20; // [esp+0h] [ebp-34h]
  MaterialVarFlags_t v21; // [esp+0h] [ebp-34h]
  bool v22; // [esp+4h] [ebp-30h]
  ExprNode *v23; // [esp+4h] [ebp-30h]
  ExprNode *v24; // [esp+8h] [ebp-2Ch]
  IShaderAPI v25; // [esp+Ch] [ebp-28h] BYREF
  int v26; // [esp+10h] [ebp-24h]
  int v27; // [esp+14h] [ebp-20h]
  int v28; // [esp+18h] [ebp-1Ch]
  int v29; // [esp+1Ch] [ebp-18h]
  int v30; // [esp+20h] [ebp-14h]
  __int64 v31; // [esp+24h] [ebp-10h]
  ExprNode *h; // [esp+2Ch] [ebp-8h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *v33; // [esp+3Ch] [ebp+8h]
  ExprNode::<unnamed_type_data> *p_data; // [esp+3Ch] [ebp+8h]
  struct GFxFontHandle *v35; // [esp+3Ch] [ebp+8h]
  ExprNode *v36; // [esp+40h] [ebp+Ch]

  GFxTextFormat::InitByDefaultValues(this: a2);
  GFxTextParagraphFormat::InitByDefaultValues(this: a3, a2: v20, a3: v22);
  v6 = *(_DWORD *)(adr + 184);
  if ( *(_WORD *)(v6 + 24) == 0 )
    goto LABEL_21;
  GFxResourceBinding::GetResourceData(
    this: *(CExpressionEvaluator **)(adr + 192),
    &h,
    ha: (const GenericThreadLocals::CThreadLocal<int> *)(v6 + 16),
    a4: (Kind)v21,
    a5: v23,
    a6: v24);
  if ( h == nullptr )
  {
    v7 = (IShaderDevice *)(*(int (__thiscall **)(int))(*(_DWORD *)adr + 168))(a1: adr);
    v33 = (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)v7;
    if ( v7 == nullptr )
      goto LABEL_19;
    GRefCountImpl::AddRef(this: v7);
    GFxLogBase<GFxLog>::LogError(
      this: (GFxLogBase<GFxLog> *)&v33[1].m_pObject,
      pfmt: "Error: Resource for font id = %d is not found in text field id = %d, def text = '%s'\n",
      *(unsigned __int16 *)(*(_DWORD *)(adr + 184) + 24),
      *(unsigned __int16 *)(adr + 16),
      (*(_DWORD *)(*(_DWORD *)(adr + 184) + 72) & 0xFFFFFFFC) + 8);
    goto LABEL_8;
  }
  if ( (((int (__thiscall *)(ExprNode *))h->left->kind)(a1: h) & 0xFF00) == 0x200 )
  {
    v36 = h;
    if ( h == nullptr )
      goto LABEL_21;
    p_data = &h->data;
    v9 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)&h->data.cond + 60))(a1: *(_DWORD *)&h->data.cond, a2: -1);
    GFxTextFormat::SetFontName(
      this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)a2,
      pfontName: v9);
    if ( *(char *)(*(_DWORD *)(adr + 184) + 80) >= 0 )
    {
      GFxTextFormat::SetBold(this: (GFxTextFormat *)a2, a2: (*(_DWORD *)(*(_DWORD *)&p_data->cond + 20) & 2) != 0);
      GFxTextFormat::SetItalic(this: (GFxTextFormat *)a2, a2: *(_BYTE *)(*(_DWORD *)&p_data->cond + 20) & 1);
      if ( (*(_BYTE *)(*(_DWORD *)(adr + 184) + 81) & 1) == 0
        && (*(_DWORD *)(*(_DWORD *)&p_data->cond + 20) & 0x40) == 0 )
      {
        v10 = (GFxFontHandle *)GNewOverrideBase<326>::operator new(sz: 0x24u, (const void *)adr);
        v35 = v10 != nullptr
            ? GFxFontHandle::GFxFontHandle(
                this: v10,
                a2: nullptr,
                a3: (struct GFxFontResource *)v36,
                a4: nullptr,
                a5: 0,
                a6: *(struct GFxMovieDef **)(*(_DWORD *)(adr + 192) + 40))
            : nullptr;
        GFxTextFormat::SetFontHandle(this: (GFxTextFormat *)a2, a2: v35);
        if ( v35 != nullptr && (*(_DWORD *)v35)-- == 1 )
        {
          GFxFontHandle::~GFxFontHandle(this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)v35);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v35);
        }
      }
    }
    goto LABEL_19;
  }
  v8 = (IShaderDevice *)(*(int (__thiscall **)(int))(*(_DWORD *)adr + 168))(a1: adr);
  v33 = (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)v8;
  if ( v8 != nullptr )
  {
    GRefCountImpl::AddRef(this: v8);
    GFxLogBase<GFxLog>::LogError(
      this: (GFxLogBase<GFxLog> *)&v33[1].m_pObject,
      pfmt: "Error: Font id = %d is referring to non-font resource in text field id = %d, def text = '%s'\n",
      *(unsigned __int16 *)(*(_DWORD *)(adr + 184) + 24),
      *(unsigned __int16 *)(adr + 16),
      (*(_DWORD *)(*(_DWORD *)(adr + 184) + 72) & 0xFFFFFFFC) + 8);
LABEL_8:
    GRefCountImpl::Release(this: (IShaderAPI *)v33);
  }
LABEL_19:
  if ( h != nullptr )
    GFxResource::Release(this: (IShaderDevice *)h);
LABEL_21:
  v31 = (__int64)*(float *)(*(_DWORD *)(adr + 184) + 44);
  v12 = v31;
  if ( (unsigned int)v31 > 0x10000 )
    v12 = -1;
  HIWORD(a2[5].m_pfnProxied) |= 8u;
  HIWORD(a2[4].m_pObject) = v12;
  v13 = *(void (__thiscall **)(IMaterial *, float))(*(_DWORD *)(adr + 184) + 48);
  HIWORD(a2[5].m_pfnProxied) |= 1u;
  a2[4].m_pfnProxied = v13;
  v25.__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
  v28 = 0;
  v14 = *(_DWORD *)(adr + 184);
  v26 = 1;
  v25.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
  v27 = 0;
  v29 = 0;
  v30 = 0;
  switch ( *(_DWORD *)(v14 + 84) )
  {
    case 0:
      v15 = HIWORD(a3->m_pShader) & 0xF9FE | 1;
      goto LABEL_28;
    case 1:
      HIWORD(a3->m_pShader) = HIWORD(a3->m_pShader) & 0xF9FE | 0x201;
      break;
    case 2:
      HIWORD(a3->m_pShader) |= 0x601u;
      break;
    case 3:
      v15 = HIWORD(a3->m_pShader) & 0xF9FE | 0x401;
LABEL_28:
      HIWORD(a3->m_pShader) = v15;
      break;
    default:
      break;
  }
  v16 = *(_DWORD *)(adr + 184);
  if ( (*(_WORD *)(v16 + 80) & 0x200) != 0 )
  {
    v17 = *(float *)(v16 + 56) / 20.0;
    HIWORD(a3->m_pShader) |= 0x10u;
    v18 = HIWORD(a3->m_pShader) | 0x20;
    a3->m_MappingHeight = (int)v17;
    v19 = *(float *)(*(_DWORD *)(adr + 184) + 60) / 20.0;
    HIWORD(a3->m_pShader) = v18;
    LOWORD(a3->m_pShader) = (int)v19;
    HIWORD(a3->m_maxLightmapPageID) = (int)(*(float *)(*(_DWORD *)(adr + 184) + 64) / 20.0);
    v18 |= 4u;
    HIWORD(a3->m_pShader) = v18;
    a3->m_MappingWidth = (int)(*(float *)(*(_DWORD *)(adr + 184) + 68) / 20.0);
    HIWORD(a3->m_pShader) = v18 | 8;
  }
  v25.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
  GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v25, a2: v21, a3: (bool)v23);
  GRefCountImplCore::~GRefCountImplCore(this: &v25);
}

//------------------------------------------------------------------------------
// Address: 0x100E73D0
// Name: public: class GFxTextFormat __near & GFxTextFormat::operator=(class GFxTextFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextFormat::operator=(int this, int __that)
{
  int v3; // eax
  GRefCountNTSImpl *v4; // ecx
  _DWORD *v5; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v6; // ebx
  int v9; // [esp+0h] [ebp-Ch]
  int v10; // [esp+0h] [ebp-Ch]

  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 8),
    src: (_DWORD *)(__that + 8),
    a3: v9);
  *(_DWORD *)(this + 12) = *(_DWORD *)(__that + 12);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 16),
    src: (_DWORD *)(__that + 16),
    a3: v10);
  *(_DWORD *)(this + 20) = *(_DWORD *)(__that + 20);
  v3 = *(_DWORD *)(__that + 24);
  if ( v3 != 0 )
    ++*(_DWORD *)(v3 + 4);
  v4 = *(GRefCountNTSImpl **)(this + 24);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  *(_DWORD *)(this + 24) = *(_DWORD *)(__that + 24);
  v5 = *(_DWORD **)(__that + 28);
  if ( v5 != nullptr )
    ++*v5;
  v6 = *(CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)(this + 28);
  if ( v6 != nullptr && LODWORD(v6->m_pfnProxied)-- == 1 )
  {
    GFxFontHandle::~GFxFontHandle(this: v6);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
  }
  *(_DWORD *)(this + 28) = *(_DWORD *)(__that + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(__that + 32);
  *(_WORD *)(this + 36) = *(_WORD *)(__that + 36);
  *(_WORD *)(this + 38) = *(_WORD *)(__that + 38);
  *(_BYTE *)(this + 40) = *(_BYTE *)(__that + 40);
  *(_WORD *)(this + 42) = *(_WORD *)(__that + 42);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E7480
// Name: public: static void GFxEditTextCharacter::SetNewTextFormat(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::SetNewTextFormat(
        MaterialVarFlags_t a1@<ebx>,
        bool a2@<sil>,
        GASFnCall *a3)
{
  GASFnCall v3; // eax
  int v4; // esi
  _DWORD *v5; // eax
  GASValue *v6; // eax
  struct GASObject *v7; // eax
  struct GASObject *v8; // edi
  int v9; // eax
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v10; // ebx
  int v11; // esi
  const struct GASEnvironment *v12; // [esp-8h] [ebp-38h]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v15; // [esp+4h] [ebp-2Ch] BYREF
  IShaderAPI v16; // [esp+18h] [ebp-18h] BYREF
  GASFnCall *v17; // [esp+38h] [ebp+8h]

  if ( a3[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a3[2]->cbSize + 8))(a1: a3[2]) == 4 )
  {
    v3 = a3[2];
    v4 = v3 != nullptr ? (int)&v3[-3] : 0;
    v5 = *(_DWORD **)(v4 + 236);
    if ( (v5 == nullptr || *v5 == 0) && (int)a3[7] >= 1 )
    {
      v12 = (const struct GASEnvironment *)a3[6];
      v6 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
      v7 = GASValue::ToObject(this: v6, a2: (int)a3, a3: v12);
      v8 = v7;
      if ( v7 != nullptr && ((int (__thiscall *)(struct GASObject *))v7[2].pNode[1].pNext)(a1: &v7[2]) == 30 )
      {
        v9 = *(_DWORD *)(*(_DWORD *)(v4 + 188) + 8);
        v10 = *(CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v9 + 24);
        v17 = *(GASFnCall **)(v4 + 188);
        GFxTextFormat::Merge(a1: *(_DWORD *)(v9 + 28), a2: &v15, a3: &v8[6].sequence);
        GFxStyledText::SetDefaultTextFormat(this: (CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *)v17[2]);
        GFxTextFormat::~GFxTextFormat(this: &v15);
        v11 = *(_DWORD *)(v4 + 188);
        GFxTextParagraphFormat::Merge(this: v10);
        GFxStyledText::SetDefaultParagraphFormat(this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(v11 + 8));
        v16.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
        GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v16, a2: a1, a3: a2);
        GRefCountImplCore::~GRefCountImplCore(this: &v16);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7580
// Name: public: void GFxEditTextCharacter::UpdateUrlStyles(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxEditTextCharacter::UpdateUrlStyles(GFxEditTextCharacter *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  GMemoryHeap_vtbl *v8; // edx
  unsigned int v9; // eax
  struct GMemoryHeap *v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // edi
  int v15; // ebx
  struct GFxStyledText *v16; // eax
  GRefCountNTSImpl *v17; // ecx
  struct GFxStyledText *v18; // edi
  int v19; // [esp-8h] [ebp-9Ch]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v20; // [esp+4h] [ebp-90h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v21; // [esp+30h] [ebp-64h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> fmt; // [esp+5Ch] [ebp-38h] BYREF
  GStringDH v23; // [esp+64h] [ebp-30h] BYREF
  GStringDH v24; // [esp+6Ch] [ebp-28h] BYREF
  int v25; // [esp+74h] [ebp-20h]
  int v26; // [esp+78h] [ebp-1Ch]
  int v27; // [esp+7Ch] [ebp-18h]
  int v28; // [esp+80h] [ebp-14h]
  char v29; // [esp+84h] [ebp-10h]
  __int16 v30; // [esp+86h] [ebp-Eh]
  int v31; // [esp+88h] [ebp-Ch]
  unsigned int startPos; // [esp+8Ch] [ebp-8h]
  int v33; // [esp+90h] [ebp-4h]

  v3 = *((_DWORD *)this + 59);
  if ( v3 != 0 )
  {
    v4 = *(_DWORD *)(v3 + 8);
    if ( v4 != 0 )
    {
      v33 = 0;
      v31 = v4;
      v19 = a2;
      do
      {
        v5 = *((_DWORD *)this + 59);
        if ( *(_DWORD *)v5 != 0 )
        {
          GFxTextStyleManager::GetStyle(
            this: (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)(*(_DWORD *)v5 + 52),
            type: nullptr,
            name: (int)&stru_102A0968.m_Size);
          v7 = v6;
          GFxTextStyleManager::GetStyle(
            this: (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)(**((_DWORD **)this + 59)
                                                                                               + 52),
            type: nullptr,
            name: (int)"a:link");
          v8 = GMemory::pGlobalHeap->__vftable;
          startPos = v9;
          v10 = v8->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
          fmt.m_pObject = (IMaterialInternal *)1;
          fmt.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))&GFxTextFormat::`vftable';
          GStringDH::GStringDH(this: &v23, a2: v10);
          GStringDH::GStringDH(this: &v24, a2: v10);
          v25 = 0;
          v26 = 0;
          v27 = -16777216;
          v28 = 0;
          v29 = 0;
          v30 = 0;
          if ( v7 != 0 )
          {
            v11 = GFxTextFormat::Merge(a1: &fmt, a2: &v21, a3: v7);
            GFxTextFormat::operator=(this: (int)&fmt, __that: v11);
            GFxTextFormat::~GFxTextFormat(this: &v21);
          }
          if ( startPos != 0 )
          {
            v12 = GFxTextFormat::Merge(a1: &fmt, a2: &v20, a3: startPos);
            GFxTextFormat::operator=(this: (int)&fmt, __that: v12);
            GFxTextFormat::~GFxTextFormat(this: &v20);
          }
          v13 = *(_DWORD *)(*((_DWORD *)this + 59) + 4);
          v14 = (const char *)(*(_DWORD *)(v13 + v33) + *(_DWORD *)(v13 + v33 + 4));
          startPos = *(_DWORD *)(v13 + v33);
          GFxTextDocView::SetTextFormat((unsigned int)&fmt, (GMemoryHeap *)startPos, endPos: v14, a4: v19);
          v15 = v33 + *(_DWORD *)(*((_DWORD *)this + 59) + 4);
          v16 = GFxStyledText::CopyStyledText(
                  this: *(GFxStyledText **)(*((_DWORD *)this + 47) + 8),
                  startPos,
                  endPos: (unsigned int)v14);
          v17 = *(GRefCountNTSImpl **)(v15 + 8);
          v18 = v16;
          if ( v17 != nullptr )
            GRefCountNTSImpl::Release(this: v17);
          *(_DWORD *)(v15 + 8) = v18;
          GFxTextFormat::~GFxTextFormat(this: &fmt);
        }
        v33 += 20;
        --v31;
      }
      while ( v31 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7710
// Name: public: void GFxEditTextCharacter::ChangeUrlFormat(enum GFxEditTextCharacter::LinkEvent,unsigned int,class GRange const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxEditTextCharacter::ChangeUrlFormat(_DWORD *a1@<ecx>, int a2@<esi>, int a3, int a4, int *a5)
{
  _DWORD *v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // esi
  unsigned int v10; // ecx
  int *v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // edx
  unsigned int v20; // ecx
  int *v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // esi
  int v25; // eax
  int v26; // eax
  GMemoryHeap *v27; // ebx
  unsigned int v28; // eax
  unsigned int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // ebx
  int v33; // eax
  struct GMemoryHeap *v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v39; // [esp+4h] [ebp-5Ch] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> fmt[5]; // [esp+30h] [ebp-30h] BYREF
  int name; // [esp+5Ch] [ebp-4h]
  unsigned int v42; // [esp+68h] [ebp+8h]
  unsigned int v43; // [esp+68h] [ebp+8h]
  int v44; // [esp+6Ch] [ebp+Ch]
  int v45; // [esp+70h] [ebp+10h]
  int v46; // [esp+70h] [ebp+10h]
  int v47; // [esp+70h] [ebp+10h]

  v6 = (_DWORD *)a1[59];
  if ( v6 != nullptr && *v6 != 0 )
  {
    name = 0;
    switch ( a3 )
    {
      case 0:
        if ( v6[2 * a4 + 4] != 0 )
        {
          if ( BYTE1(v6[2 * a4 + 5]) != 0 )
            return;
          BYTE1(v6[2 * a4 + 5]) = 1;
          v7 = a1[59];
          v8 = *(_DWORD *)(v7 + 4);
          v9 = v8 + 20 * *(_DWORD *)(v7 + 8 * a4 + 16) - 20;
          if ( *(_DWORD *)(v8 + 20 * *(_DWORD *)(v7 + 8 * a4 + 16) - 8) != 0 )
          {
            ++*(_DWORD *)(v9 + 12);
            return;
          }
        }
        else
        {
          v10 = 0;
          v42 = v6[2];
          if ( v42 == 0 )
            return;
          v11 = (int *)v6[1];
          v12 = a5[1] + *a5 - 1;
          v45 = *a5;
          while ( v12 < *v11 || v11[1] + *v11 - 1 < v45 )
          {
            ++v10;
            v11 += 5;
            if ( v10 >= v42 )
              return;
          }
          v13 = a1[59];
          v14 = *(_DWORD *)(v13 + 4);
          *(_DWORD *)(v13 + 8 * a4 + 16) = v10 + 1;
          v9 = v14 + 20 * v10;
          *(_BYTE *)(a1[59] + 8 * a4 + 21) = 1;
        }
        if ( v9 != 0 )
        {
          v15 = *(_DWORD *)(v9 + 12);
          *(_DWORD *)(v9 + 12) = v15 + 1;
          if ( v15 == 0 )
            goto LABEL_48;
        }
        break;
      case 1:
        if ( v6[2 * a4 + 4] != 0 && BYTE1(v6[2 * a4 + 5]) != 0 )
        {
          BYTE1(v6[2 * a4 + 5]) = 0;
          v16 = a1[59];
          v17 = *(_DWORD *)(v16 + 8 * a4 + 16);
          if ( *(_BYTE *)(v16 + 8 * a4 + 20) == 0 )
            *(_DWORD *)(v16 + 8 * a4 + 16) = 0;
          v9 = *(_DWORD *)(a1[59] + 4) + 4 * (5 * v17 - 5);
          if ( *(_DWORD *)(v9 + 12) == 0 )
            goto LABEL_49;
          if ( --*(_DWORD *)(v9 + 12) == 0 )
          {
            if ( *(_DWORD *)(v9 + 16) != 0 )
              name = (int)"a:hover";
            goto LABEL_49;
          }
        }
        break;
      case 2:
        if ( v6[2 * a4 + 4] != 0 )
        {
          if ( LOBYTE(v6[2 * a4 + 5]) != 0 )
            return;
          LOBYTE(v6[2 * a4 + 5]) = 1;
          v18 = a1[59];
          v19 = *(_DWORD *)(v18 + 4);
          v9 = v19 + 20 * *(_DWORD *)(v18 + 8 * a4 + 16) - 20;
          if ( *(_DWORD *)(v19 + 20 * *(_DWORD *)(v18 + 8 * a4 + 16) - 4) != 0 )
          {
            ++*(_DWORD *)(v9 + 16);
            return;
          }
        }
        else
        {
          v20 = 0;
          v43 = v6[2];
          if ( v43 == 0 )
            return;
          v21 = (int *)v6[1];
          v22 = a5[1] + *a5 - 1;
          v46 = *a5;
          while ( v22 < *v21 || v21[1] + *v21 - 1 < v46 )
          {
            ++v20;
            v21 += 5;
            if ( v20 >= v43 )
              return;
          }
          v23 = a1[59];
          v24 = *(_DWORD *)(v23 + 4);
          *(_DWORD *)(v23 + 8 * a4 + 16) = v20 + 1;
          v9 = v24 + 20 * v20;
          *(_BYTE *)(a1[59] + 8 * a4 + 20) = 1;
        }
        if ( v9 != 0 && *(_DWORD *)(v9 + 12) == 0 )
        {
          v25 = *(_DWORD *)(v9 + 16);
          *(_DWORD *)(v9 + 16) = v25 + 1;
          if ( v25 == 0 )
          {
            name = (int)"a:hover";
            goto LABEL_49;
          }
        }
        break;
      case 3:
        if ( v6[2 * a4 + 4] != 0 && LOBYTE(v6[2 * a4 + 5]) != 0 )
        {
          LOBYTE(v6[2 * a4 + 5]) = 0;
          v26 = a1[59];
          v9 = *(_DWORD *)(v26 + 4) + 20 * *(_DWORD *)(v26 + 8 * a4 + 16) - 20;
          if ( *(_BYTE *)(v26 + 8 * a4 + 21) == 0 )
            *(_DWORD *)(v26 + 8 * a4 + 16) = 0;
          if ( *(_DWORD *)(v9 + 16) != 0 )
          {
            if ( --*(_DWORD *)(v9 + 16) != 0 )
              return;
            if ( *(_DWORD *)(v9 + 12) != 0 )
LABEL_48:
              name = (int)"a:active";
          }
LABEL_49:
          if ( *(_DWORD *)(v9 + 8) != 0 )
          {
            v27 = *(GMemoryHeap **)v9;
            v28 = *(_DWORD *)v9 + *(_DWORD *)(v9 + 4);
            if ( v28 < *(_DWORD *)v9 )
              v29 = 0;
            else
              v29 = v28 - (_DWORD)v27;
            GFxStyledText::Remove(this: *(SFTextObjectImpl **)(a1[47] + 8), a2: (unsigned int)v27, a3: v29);
            GFxStyledText::InsertStyledText(
              this: *(SFTextObjectImpl **)(a1[47] + 8),
              a2: *(GFxStyledText **)(v9 + 8),
              a3: (unsigned int)v27,
              a4: 0xFFFFFFFF);
          }
          if ( name != 0 )
          {
            GFxTextStyleManager::GetStyle(
              this: (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)(*(_DWORD *)a1[59] + 52),
              type: nullptr,
              name);
            v47 = v30;
            if ( v30 != 0 )
            {
              GFxTextStyleManager::GetStyle(
                this: (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)(*(_DWORD *)a1[59] + 52),
                type: nullptr,
                name: (int)&stru_102A0968.m_Size);
              v32 = v31;
              GFxTextStyleManager::GetStyle(
                this: (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)(*(_DWORD *)a1[59] + 52),
                type: nullptr,
                name: (int)"a:link");
              v44 = v33;
              v34 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: a1);
              GFxTextFormat::GFxTextFormat(this: (GFxTextFormat *)fmt, a2: v34);
              if ( v32 != 0 )
              {
                v35 = GFxTextFormat::Merge(a1: fmt, a2: &v39, a3: v32);
                GFxTextFormat::operator=(this: (int)fmt, __that: v35);
                GFxTextFormat::~GFxTextFormat(this: &v39);
              }
              if ( v44 != 0 )
              {
                v36 = GFxTextFormat::Merge(a1: fmt, a2: &v39, a3: v44);
                GFxTextFormat::operator=(this: (int)fmt, __that: v36);
                GFxTextFormat::~GFxTextFormat(this: &v39);
              }
              v37 = GFxTextFormat::Merge(a1: fmt, a2: &v39, a3: v47);
              GFxTextFormat::operator=(this: (int)fmt, __that: v37);
              GFxTextFormat::~GFxTextFormat(this: &v39);
              GFxTextDocView::SetTextFormat(
                (unsigned int)fmt,
                startPos: *(GMemoryHeap **)v9,
                endPos: (const char *)(*(_DWORD *)v9 + *(_DWORD *)(v9 + 4)),
                a4: a2);
              GFxTextFormat::~GFxTextFormat(this: fmt);
            }
          }
        }
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7C30
// Name: public: void GFxEditTextCharacter::SetInitialFormatsAsDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetInitialFormatsAsDefault(GFxEditTextCharacter *this)
{
  struct GMemoryHeap *v2; // ebx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v7; // eax
  __int16 v8; // dx
  int v9; // eax
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v10; // eax
  struct GMemoryHeap *v11; // edi
  int v12; // eax
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v13; // eax
  MaterialVarFlags_t v14; // [esp+0h] [ebp-120h]
  MaterialVarFlags_t v15; // [esp+0h] [ebp-120h]
  MaterialVarFlags_t v16; // [esp+0h] [ebp-120h]
  bool v17; // [esp+4h] [ebp-11Ch]
  bool v18; // [esp+4h] [ebp-11Ch]
  bool v19; // [esp+4h] [ebp-11Ch]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v20; // [esp+Ch] [ebp-114h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v21; // [esp+38h] [ebp-E8h] BYREF
  CMaterial v22; // [esp+64h] [ebp-BCh] BYREF
  int v23; // [esp+FCh] [ebp-24h]
  int v24; // [esp+100h] [ebp-20h]
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v25; // [esp+104h] [ebp-1Ch]
  IShaderAPI v26; // [esp+108h] [ebp-18h] BYREF
  int v27; // [esp+10Ch] [ebp-14h]
  int v28; // [esp+110h] [ebp-10h]
  int v29; // [esp+114h] [ebp-Ch]
  int v30; // [esp+118h] [ebp-8h]
  int v31; // [esp+11Ch] [ebp-4h]

  v2 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
  v22.m_VMTIncludes.m_pElements = (void **)1;
  v22.m_VMTIncludes.m_Size = (int)&GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: (GStringDH *)&v22.m_bShouldReloadFromWhitelist, a2: v2);
  GStringDH::GStringDH(this: (GStringDH *)&v22.m_Reflectivity, a2: v2);
  v22.m_QueueFriendlyVersion.__vftable = nullptr;
  HIWORD(v22.m_QueueFriendlyVersion.m_pRealTimeVersion) = 0;
  v26.__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
  v29 = 0;
  v3 = *((_DWORD *)this + 47);
  v31 = 0;
  v4 = *((_DWORD *)this + 46);
  v22.m_Reflectivity.z = 0.0;
  v22.m_ChangeID = 0;
  v22.m_pVMTKeyValues = (KeyValues *)-16777216;
  LOBYTE(v22.m_QueueFriendlyVersion.m_pRealTimeVersion) = 0;
  v30 = 0;
  v27 = 1;
  v26.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
  v28 = 0;
  v5 = *(_DWORD *)(v3 + 8);
  v6 = *(_DWORD *)(v5 + 28);
  v7 = *(CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v5 + 24);
  v8 = *(_WORD *)(v4 + 80) >> 11;
  v25 = v7;
  if ( (v8 & 1) != 0 )
  {
    if ( v6 != 0 )
    {
      GFxTextFormat::operator=(this: (int)&v22.m_VMTIncludes.m_Size, __that: v6);
      v7 = v25;
    }
    if ( v7 != nullptr )
      GFxTextParagraphFormat::operator=(result: v7);
    v11 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
    *(&v22.m_ShaderRenderState.m_Flags + 1) = 1;
    v22.m_ShaderRenderState.m_Flags = (int)&GFxTextFormat::`vftable';
    GStringDH::GStringDH(this: (GStringDH *)&v22.m_ShaderRenderState.m_VertexFormat, a2: v11);
    GStringDH::GStringDH(this: (GStringDH *)&v22.m_ShaderRenderState.m_VertexUsage, a2: v11);
    v22.m_VMTIncludes.m_Memory.m_nAllocationCount = 0;
    v22.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.z = 0.0;
    v22.m_ShaderRenderState.m_pSnapshots = nullptr;
    *((_DWORD *)&v22.m_ShaderRenderState.m_pSnapshots + 1) = 0;
    v22.m_VMTIncludes.m_Memory.m_pMemory = (void **)-16777216;
    LOBYTE(v22.m_VMTIncludes.m_Memory.m_nGrowSize) = 0;
    HIWORD(v22.m_VMTIncludes.m_Memory.m_nGrowSize) = 0;
    LODWORD(v22.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.x) = 1;
    LODWORD(v22.m_QueueFriendlyVersion.m_fAlphaModulationOnQueueCompletion) = &GFxTextParagraphFormat::`vftable';
    v22.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.y = 0.0;
    v23 = 0;
    v24 = 0;
    GFxTextFormat::InitByDefaultValues(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v22.m_ShaderRenderState);
    GFxTextParagraphFormat::InitByDefaultValues(
      this: (CMaterial *)&v22.m_QueueFriendlyVersion.m_fAlphaModulationOnQueueCompletion,
      a2: v14,
      a3: v17);
    v12 = GFxTextFormat::Merge(a1: &v22.m_ShaderRenderState, a2: &v20, a3: &v22.m_VMTIncludes.m_Size);
    GFxTextFormat::operator=(this: (int)&v22.m_VMTIncludes.m_Size, __that: v12);
    GFxTextFormat::~GFxTextFormat(this: &v20);
    GFxTextParagraphFormat::Merge(this: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v22.m_QueueFriendlyVersion.m_fAlphaModulationOnQueueCompletion);
    GFxTextParagraphFormat::operator=(result: v13);
    *(_DWORD *)&v22.m_Name.m_Id = &GFxTextParagraphFormat::`vftable';
    GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v22.m_Name, a2: v15, a3: v18);
    GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v22.m_Name);
    LODWORD(v22.m_QueueFriendlyVersion.m_fAlphaModulationOnQueueCompletion) = &GFxTextParagraphFormat::`vftable';
    GFxTextParagraphFormat::FreeTabStops(
      this: (CMaterial *)&v22.m_QueueFriendlyVersion.m_fAlphaModulationOnQueueCompletion,
      a2: v16,
      a3: v19);
    GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v22.m_QueueFriendlyVersion.m_fAlphaModulationOnQueueCompletion);
    GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v22.m_ShaderRenderState);
  }
  else
  {
    GFxEditTextCharacter::GetInitialFormats(
      adr: (int)this,
      a2: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v22.m_VMTIncludes.m_Size,
      a3: (CMaterial *)&v26);
    if ( v6 != 0 )
    {
      v9 = GFxTextFormat::Merge(a1: v6, a2: &v21, a3: &v22.m_VMTIncludes.m_Size);
      GFxTextFormat::operator=(this: (int)&v22.m_VMTIncludes.m_Size, __that: v9);
      GFxTextFormat::~GFxTextFormat(this: &v21);
    }
    if ( v25 != nullptr )
    {
      GFxTextParagraphFormat::Merge(this: v25);
      GFxTextParagraphFormat::operator=(result: v10);
      v22.__vftable = (CMaterial_vtbl *)&GFxTextParagraphFormat::`vftable';
      GFxTextParagraphFormat::FreeTabStops(this: &v22, a2: v14, a3: v17);
      GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v22);
    }
  }
  GFxStyledText::SetDefaultTextFormat(this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(*((_DWORD *)this + 47)
                                                                                               + 8));
  GFxStyledText::SetDefaultParagraphFormat(this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(*((_DWORD *)this + 47) + 8));
  v26.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
  GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v26, a2: v14, a3: v17);
  GRefCountImplCore::~GRefCountImplCore(this: &v26);
  GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v22.m_VMTIncludes.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x100E7EE0
// Name: public: void GFxEditTextCharacter::RemoveIdImageDescAssoc(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::RemoveIdImageDescAssoc(int **this, GString a2)
{
  void *v3; // esi

  if ( *(this + 68) != nullptr )
  {
    GString::GString(this: &a2, src: (int)a2.pData);
    GHashSetBase<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GPtr<GFxTextImageDesc>,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF>>::RemoveAlt<GString>(
      this: *(this + 68),
      &a2);
    v3 = (void *)(a2.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a2.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7F40
// Name: public: static void GFxEditTextCharacter::GetTextFormat(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetTextFormat(unsigned int a1@<edi>, double a2@<st0>, int a3)
{
  GASFnCall *v3; // esi
  unsigned int v4; // ebx
  GASFnCall v5; // eax
  GASValue *v6; // eax
  int v7; // eax
  GASValue *v8; // eax
  double v9; // st7
  GASValue *v10; // eax
  double v11; // st7
  int cyItem; // eax
  int v13; // ecx
  int (__thiscall *v14)(int, int, int *); // eax
  GASTextFormatObject *v15; // eax
  GPtr<GFxAmpCurrentState> *v16; // edi
  GASValue *v17; // esi
  _SERVICE_STATUS *v18; // [esp-8h] [ebp-60h]
  _SERVICE_STATUS *v19; // [esp-8h] [ebp-60h]
  _SERVICE_STATUS *v20; // [esp-8h] [ebp-60h]
  MaterialVarFlags_t v21; // [esp-4h] [ebp-5Ch]
  bool v22; // [esp+0h] [ebp-58h]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v23; // [esp+8h] [ebp-50h] BYREF
  IShaderAPI v24; // [esp+34h] [ebp-24h] BYREF
  int v25; // [esp+38h] [ebp-20h]
  int v26; // [esp+3Ch] [ebp-1Ch]
  int v27; // [esp+40h] [ebp-18h]
  int v28; // [esp+44h] [ebp-14h]
  int v29; // [esp+48h] [ebp-10h]
  __int64 v30; // [esp+4Ch] [ebp-Ch]
  GASFnCall v31; // [esp+54h] [ebp-4h]

  v3 = (GASFnCall *)a3;
  v4 = 0;
  if ( *(_DWORD *)(a3 + 8) == 0
    || (*(int (__thiscall **)(GASFnCall))(**(_DWORD **)(a3 + 8) + 8))(a1: *(GASFnCall *)(a3 + 8)) != 4 )
  {
    goto LABEL_25;
  }
  v5 = v3[2];
  if ( v5 != nullptr )
    v31 = v5 - 3;
  else
    v31 = nullptr;
  v21 = a1;
  a1 = -1;
  if ( (int)v3[7] >= 1 )
  {
    v18 = (_SERVICE_STATUS *)v3[6];
    v6 = (GASValue *)GASFnCall::Arg(this: v3, a2: 0);
    a2 = GASValue::ToNumber(this: v6, a2: -1, a3: a2, result: v18);
    if ( a2 < 0.0 )
      a2 = 0.0;
    v30 = (__int64)a2;
    v4 = (__int64)a2;
  }
  v7 = (int)v3[7];
  if ( v7 < 2 )
  {
    if ( v7 >= 1 )
    {
      v20 = (_SERVICE_STATUS *)v3[6];
      v10 = (GASValue *)GASFnCall::Arg(this: v3, a2: 0);
      v11 = GASValue::ToNumber(this: v10, a2: -1, a3: a2, result: v20) + 1.0;
      if ( v11 < 0.0 )
        v11 = 0.0;
      v30 = (__int64)v11;
      a1 = (__int64)v11;
    }
  }
  else
  {
    v19 = (_SERVICE_STATUS *)v3[6];
    v8 = (GASValue *)GASFnCall::Arg(this: v3, a2: 1);
    v9 = GASValue::ToNumber(this: v8, a2: -1, a3: a2, result: v19);
    if ( v9 < 0.0 )
      v9 = 0.0;
    v30 = (__int64)v9;
    a1 = (__int64)v9;
  }
  if ( v4 <= a1 )
  {
    GFxTextFormat::GFxTextFormat(this: (GFxTextFormat *)&v23, a2: *(struct GMemoryHeap **)(v3[6][3].cbSize + 656));
    v27 = 0;
    v28 = 0;
    v29 = 0;
    v24.__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
    cyItem = v31[4].cyItem;
    v25 = 1;
    v24.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
    v26 = 0;
    GFxStyledText::GetTextAndParagraphFormat(this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(cyItem + 8));
    v13 = *(_DWORD *)(v3[6][3].cbSize + 656);
    v14 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v13 + 40);
    a3 = 323;
    v15 = (GASTextFormatObject *)v14(a1: v13, a2: 120, &a3);
    if ( v15 != nullptr )
      v16 = (GPtr<GFxAmpCurrentState> *)GASTextFormatObject::GASTextFormatObject(
                                          this: v15,
                                          a2: (struct GASEnvironment *)v3[6]);
    else
      v16 = nullptr;
    GASTextFormatObject::SetTextFormat(this: v16, psc: (const GPtr<GFxAmpCurrentState> *)&v3[6][3]);
    GASTextFormatObject::SetParagraphFormat(this: v16, psc: (GFxAmpCurrentState *)&v3[6][3]);
    GASValue::SetAsObject(this: (GASValue *)v3[1], a2: (struct GASObject *)v16);
    if ( v16 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v16, a2: (int)v16);
    v24.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
    GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v24, a2: v21, a3: v22);
    GRefCountImplCore::~GRefCountImplCore(this: &v24);
    GFxTextFormat::~GFxTextFormat(this: &v23);
  }
  else
  {
LABEL_25:
    v17 = (GASValue *)v3[1];
    GASValue::DropRefs(this: v17, a2: a1);
    *(_BYTE *)v17 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E81A0
// Name: public: static void GFxEditTextCharacter::GetNewTextFormat(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetNewTextFormat(int a1@<edi>, int a2)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  int (__thiscall *v8)(int, int, int *); // edx
  GASTextFormatObject *v9; // eax
  GPtr<GFxAmpCurrentState> *v10; // edi
  GASValue *v11; // esi
  int v12; // [esp+4h] [ebp-4h]

  v2 = a2;
  if ( *(_DWORD *)(a2 + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 8) + 8))(a1: *(_DWORD *)(a2 + 8)) == 4 )
  {
    v3 = *(_DWORD *)(v2 + 8);
    if ( v3 != 0 )
      v4 = v3 - 120;
    else
      v4 = 0;
    v5 = *(_DWORD *)(*(_DWORD *)(v4 + 188) + 8);
    v6 = *(_DWORD *)(v5 + 28);
    v12 = *(_DWORD *)(v5 + 24);
    v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 24) + 120) + 656);
    v8 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v7 + 40);
    a2 = 323;
    v9 = (GASTextFormatObject *)v8(a1: v7, a2: 120, a3: &a2);
    if ( v9 != nullptr )
      v10 = (GPtr<GFxAmpCurrentState> *)GASTextFormatObject::GASTextFormatObject(
                                          this: v9,
                                          a2: *(struct GASEnvironment **)(v2 + 24));
    else
      v10 = nullptr;
    if ( v6 != 0 )
      GASTextFormatObject::SetTextFormat(this: v10, psc: (const GPtr<GFxAmpCurrentState> *)(*(_DWORD *)(v2 + 24) + 120));
    if ( v12 != 0 )
      GASTextFormatObject::SetParagraphFormat(this: v10, psc: (GFxAmpCurrentState *)(*(_DWORD *)(v2 + 24) + 120));
    GASValue::SetAsObject(this: *(GASValue **)(v2 + 4), a2: (struct GASObject *)v10);
    if ( v10 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v10, a2: (int)v10);
  }
  else
  {
    v11 = *(GASValue **)(v2 + 4);
    GASValue::DropRefs(this: v11, a2: a1);
    *(_BYTE *)v11 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8280
// Name: public: static void GFxEditTextCharacter::GetCharBoundaries(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetCharBoundaries(int a1@<edi>, long double a2@<st0>, float a3)
{
  float v3; // esi
  int v4; // eax
  int v5; // edi
  GASValue *v6; // eax
  double v7; // st7
  GFxTextDocView *v8; // ecx
  int v9; // ecx
  int (__thiscall *v10)(int, int, float *); // edx
  GASRectangleObject *v11; // eax
  struct GASObject *v12; // edi
  GASValue *v13; // esi
  unsigned int v14; // [esp-Ch] [ebp-48h]
  _SERVICE_STATUS *v15; // [esp-8h] [ebp-44h]
  double v17[4]; // [esp+4h] [ebp-38h] BYREF
  int v18; // [esp+24h] [ebp-18h] BYREF
  float v19; // [esp+28h] [ebp-14h]
  float v20; // [esp+2Ch] [ebp-10h]
  float v21; // [esp+30h] [ebp-Ch]
  int rv[2]; // [esp+34h] [ebp-8h]

  v3 = a3;
  if ( *(_DWORD *)(LODWORD(a3) + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(a3) + 8) + 8))(a1: *(_DWORD *)(LODWORD(a3) + 8)) == 4 )
  {
    v4 = *(_DWORD *)(LODWORD(v3) + 8);
    v5 = v4 != 0 ? v4 - 120 : 0;
    if ( *(int *)(LODWORD(v3) + 28) >= 1 )
    {
      v15 = *(_SERVICE_STATUS **)(LODWORD(v3) + 24);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(v3), a2: 0);
      v7 = GASValue::ToNumber(this: v6, a2: v5, a3: a2, result: v15);
      rv[1] = HIWORD(a3) | 0xC00;
      v8 = *(GFxTextDocView **)(v5 + 188);
      *(_QWORD *)rv = (__int64)v7;
      *(float *)&v18 = 0.0;
      v19 = 0.0;
      a3 = 0.0 + 0.0;
      v20 = a3;
      v21 = a3;
      if ( (unsigned __int8)GFxTextDocView::GetCharBoundaries(this: v8, a2: (int)&v18, rv: (__int64)v7) != 0 )
      {
        v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v3) + 24) + 120) + 656);
        v10 = *(int (__thiscall **)(int, int, float *))(*(_DWORD *)v9 + 40);
        LODWORD(a3) = 323;
        v11 = (GASRectangleObject *)v10(a1: v9, a2: 52, &a3);
        if ( v11 != nullptr )
          v12 = (struct GASObject *)GASRectangleObject::GASRectangleObject(
                                      this: v11,
                                      a2: *(struct GASEnvironment **)(LODWORD(v3) + 24));
        else
          v12 = nullptr;
        v14 = *(_DWORD *)(LODWORD(v3) + 24);
        v17[0] = *(float *)&v18 / 20.0;
        v17[1] = v19 / 20.0;
        v17[2] = v20 / 20.0;
        v17[3] = v21 / 20.0;
        GASRectangleObject::SetProperties(penv: v14, r: (GMemoryHeap *)v17, a3: a1);
        GASValue::SetAsObject(this: *(GASValue **)(LODWORD(v3) + 4), a2: v12);
        if ( v12 != nullptr )
          GRefCountBaseGC<323>::Release(a1: (int)v12, a2: (int)v12);
      }
      else
      {
        v13 = *(GASValue **)(LODWORD(v3) + 4);
        GASValue::DropRefs(this: v13, a2: v5);
        *(_BYTE *)v13 = 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E83C0
// Name: public: static void GFxEditTextCharacter::GetExactCharBoundaries(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetExactCharBoundaries(int a1@<edi>, long double a2@<st0>, float a3)
{
  float v3; // esi
  int v4; // eax
  int v5; // edi
  GASValue *v6; // eax
  int v7; // eax
  GFxTextDocView *v8; // ecx
  int v9; // ecx
  int (__thiscall *v10)(int, int, float *); // edx
  GASRectangleObject *v11; // eax
  struct GASObject *v12; // edi
  GASValue *v13; // esi
  unsigned int v14; // [esp-Ch] [ebp-40h]
  _SERVICE_STATUS *v15; // [esp-8h] [ebp-3Ch]
  double v17[4]; // [esp+4h] [ebp-30h] BYREF
  __int16 v18[2]; // [esp+24h] [ebp-10h] BYREF
  float v19; // [esp+28h] [ebp-Ch]
  float v20; // [esp+2Ch] [ebp-8h]
  float v21; // [esp+30h] [ebp-4h]

  v3 = a3;
  if ( *(_DWORD *)(LODWORD(a3) + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(a3) + 8) + 8))(a1: *(_DWORD *)(LODWORD(a3) + 8)) == 4 )
  {
    v4 = *(_DWORD *)(LODWORD(v3) + 8);
    v5 = v4 != 0 ? v4 - 120 : 0;
    if ( *(int *)(LODWORD(v3) + 28) >= 1 )
    {
      v15 = *(_SERVICE_STATUS **)(LODWORD(v3) + 24);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(v3), a2: 0);
      v7 = GASValue::ToUInt32(this: v6, a2: v5, a3: a2, a4: v15);
      v8 = *(GFxTextDocView **)(v5 + 188);
      *(float *)v18 = 0.0;
      v19 = 0.0;
      a3 = 0.0 + 0.0;
      v20 = a3;
      v21 = a3;
      if ( (unsigned __int8)GFxTextDocView::GetExactCharBoundaries(this: v8, a2: (__int16)v18, advance: v7) != 0 )
      {
        v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v3) + 24) + 120) + 656);
        v10 = *(int (__thiscall **)(int, int, float *))(*(_DWORD *)v9 + 40);
        LODWORD(a3) = 323;
        v11 = (GASRectangleObject *)v10(a1: v9, a2: 52, &a3);
        if ( v11 != nullptr )
          v12 = (struct GASObject *)GASRectangleObject::GASRectangleObject(
                                      this: v11,
                                      a2: *(struct GASEnvironment **)(LODWORD(v3) + 24));
        else
          v12 = nullptr;
        v14 = *(_DWORD *)(LODWORD(v3) + 24);
        v17[0] = *(float *)v18 / 20.0;
        v17[1] = v19 / 20.0;
        v17[2] = v20 / 20.0;
        v17[3] = v21 / 20.0;
        GASRectangleObject::SetProperties(penv: v14, r: (GMemoryHeap *)v17, a3: a1);
        GASValue::SetAsObject(this: *(GASValue **)(LODWORD(v3) + 4), a2: v12);
        if ( v12 != nullptr )
          GRefCountBaseGC<323>::Release(a1: (int)v12, a2: (int)v12);
      }
      else
      {
        v13 = *(GASValue **)(LODWORD(v3) + 4);
        GASValue::DropRefs(this: v13, a2: v5);
        *(_BYTE *)v13 = 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E84E0
// Name: public: static void GFxEditTextCharacter::GetLineMetrics(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::GetLineMetrics(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int v3; // edi
  GASValue *v4; // eax
  signed int v5; // eax
  int v6; // ecx
  int (__thiscall *v7)(int, int, int *); // edx
  GASObject *v8; // eax
  GASObject *v9; // ebx
  GASValue *v10; // esi
  tagWNDCLASSW *v11; // [esp-14h] [ebp-48h]
  tagWNDCLASSW *v12; // [esp-14h] [ebp-48h]
  tagWNDCLASSW *v13; // [esp-14h] [ebp-48h]
  tagWNDCLASSW *v14; // [esp-14h] [ebp-48h]
  tagWNDCLASSW *v15; // [esp-14h] [ebp-48h]
  tagWNDCLASSW *v16; // [esp-14h] [ebp-48h]
  _SERVICE_STATUS *v17; // [esp-8h] [ebp-3Ch]
  int v18; // [esp+4h] [ebp-30h] BYREF
  GASValue v19; // [esp+8h] [ebp-2Ch] BYREF
  double v20; // [esp+Ch] [ebp-28h]
  _DWORD v21[6]; // [esp+18h] [ebp-1Ch] BYREF

  if ( a2[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) == 4 )
  {
    v2 = a2[2];
    v3 = v2 != nullptr ? (int)&v2[-3] : 0;
    if ( (int)a2[7] >= 1 )
    {
      v17 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToInt32(this: v4, a2: v3, a3: a1, a4: v17);
      if ( v5 >= 0
        && GFxTextDocView::GetLineMetrics(
             this: *(GFxTextDocView **)(v3 + 188),
             a2: v5,
             a3: (struct GFxTextDocView::LineMetrics *)v21) )
      {
        v6 = *(_DWORD *)(a2[6][3].cbSize + 656);
        v7 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v6 + 40);
        v18 = 323;
        v8 = (GASObject *)v7(a1: v6, a2: 52, a3: &v18);
        if ( v8 != nullptr )
          v9 = GASObject::GASObject(this: v8, a2: (struct GASEnvironment *)a2[6]);
        else
          v9 = nullptr;
        LOBYTE(v19) = 3;
        v11 = (tagWNDCLASSW *)&a2[6][3];
        v20 = (double)v21[2] / 20.0;
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v11,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ascent",
          a4: (int)&v19);
        GASValue::~GASValue(this: &v19, a2: v3);
        LOBYTE(v19) = 3;
        v12 = (tagWNDCLASSW *)&a2[6][3];
        v20 = (double)v21[3] / 20.0;
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v12,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"descent",
          a4: (int)&v19);
        GASValue::~GASValue(this: &v19, a2: v3);
        LOBYTE(v19) = 3;
        v13 = (tagWNDCLASSW *)&a2[6][3];
        v20 = (double)v21[0] / 20.0;
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v13,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_pElements,
          a4: (int)&v19);
        GASValue::~GASValue(this: &v19, a2: v3);
        LOBYTE(v19) = 3;
        v14 = (tagWNDCLASSW *)&a2[6][3];
        v20 = (double)v21[1] / 20.0;
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v14,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_Memory.m_nGrowSize,
          a4: (int)&v19);
        GASValue::~GASValue(this: &v19, a2: v3);
        v15 = (tagWNDCLASSW *)&a2[6][3];
        LOBYTE(v19) = 3;
        v20 = (double)v21[5] / 20.0;
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v15,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68,
          a4: (int)&v19);
        GASValue::~GASValue(this: &v19, a2: v3);
        v16 = (tagWNDCLASSW *)&a2[6][3];
        LOBYTE(v19) = 3;
        v20 = (double)v21[4] / 20.0;
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v16,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nGrowSize,
          a4: (int)&v19);
        GASValue::~GASValue(this: &v19, a2: v3);
        GASValue::SetAsObject(this: (GASValue *)a2[1], a2: v9);
        if ( v9 != nullptr )
          GRefCountBaseGC<323>::Release(a1: (int)v9, a2: v3);
      }
      else
      {
        v10 = (GASValue *)a2[1];
        GASValue::DropRefs(this: v10, a2: v3);
        *(_BYTE *)v10 = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8730
// Name: public: void GFxEditTextCharacter::ProcessImageTags(class GArrayDH<struct GFxStyledText::HTMLImageTagInfo,2,struct GArrayDefaultPolicy> __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall GFxEditTextCharacter::ProcessImageTags(IMatRenderContextInternal *a1, int a2, _DWORD *a3)
{
  void (__thiscall *MultMatrixLocal_2)(struct IMatRenderContextInternal *, const VMatrix *); // edx
  GASEnvironment *v5; // edi
  MaterialIndexFormat_t v6; // eax
  int v7; // eax
  MaterialIndexFormat_t v8; // eax
  int v9; // ecx
  GString *v10; // ebx
  IShaderDevice *v11; // eax
  IShaderDevice *v12; // esi
  char v13; // al
  void *v14; // esi
  void *v15; // esi
  void *v16; // esi
  GFxMovieRoot *MovieRoot; // eax
  CMatCallQueue *BitmapA; // eax
  int v19; // edx
  int v20; // ecx
  int (__thiscall *v21)(int, int, IIndexBuffer **); // eax
  int v22; // eax
  IClientUnknown *v23; // esi
  int HeapTypeBits; // edi
  GFxShapeBase *v25; // ecx
  int v26; // edx
  GString::DataDesc *pData; // eax
  double v28; // st7
  double v29; // st6
  unsigned int v30; // eax
  unsigned int v31; // ecx
  double v32; // st5
  IMatRenderContextInternal *m_pHardwareContext; // ecx
  double v34; // st4
  double v35; // st3
  unsigned int v36; // eax
  unsigned int v37; // eax
  float *v38; // eax
  double v39; // st7
  double v40; // st7
  const struct GString *m_nGrowSize; // [esp-4h] [ebp-68h]
  _DWORD v42[4]; // [esp+Ch] [ebp-58h] BYREF
  CMatQueuedIndexBuffer result; // [esp+1Ch] [ebp-48h] BYREF
  MaterialIndexFormat_t v44; // [esp+44h] [ebp-20h]
  GASEnvironment *v45; // [esp+48h] [ebp-1Ch]
  IShaderDevice *v46; // [esp+4Ch] [ebp-18h]
  CUtlMemory<CImagePacker,int> v47; // [esp+50h] [ebp-14h] BYREF
  float v48; // [esp+5Ch] [ebp-8h]
  char v49; // [esp+63h] [ebp-1h]

  MultMatrixLocal_2 = a1->MultMatrixLocal_2;
  result.m_pHardwareContext = a1;
  v5 = (GASEnvironment *)((int (__fastcall *)(IMatRenderContextInternal *))MultMatrixLocal_2)(a1);
  v6 = a3[1];
  v45 = v5;
  v44 = v6;
  if ( v6 != MATERIAL_INDEX_FORMAT_16BIT )
  {
    v7 = ((int (__thiscall *)(IMatRenderContextInternal *))a1->PushMatrix)(a1);
    if ( v7 != 0 )
      *(_DWORD *)(v7 + 9332) |= 0x400u;
    v8 = v44;
    if ( v44 != MATERIAL_INDEX_FORMAT_16BIT )
    {
      v44 = MATERIAL_INDEX_FORMAT_16BIT;
      result.m_nIndexFormat = v8;
      while ( 1 )
      {
        v9 = *((_DWORD *)v5 + 29);
        v10 = (GString *)(v44 + *a3);
        result.__vftable = nullptr;
        result.m_pOwner = nullptr;
        v11 = (IShaderDevice *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 92))(a1: v9);
        v12 = v11;
        v46 = v11;
        if ( v11 != nullptr )
          break;
LABEL_41:
        if ( result.__vftable != nullptr )
          GFxResource::Release(this: (IShaderDevice *)result.__vftable);
        v44 += 44;
        if ( --result.m_nIndexFormat == MATERIAL_INDEX_FORMAT_16BIT )
          return;
      }
      GRefCountImpl::AddRef(this: v11);
      v49 = 0;
      v47.m_nGrowSize = (int)&v10[1];
      if ( GString::GetLength(this: v10 + 1) == 0 )
        goto LABEL_20;
      v13 = *(_BYTE *)((*(_DWORD *)v47.m_nGrowSize & 0xFFFFFFFC) + 8);
      if ( v13 != 105 && v13 != 73 )
        goto LABEL_20;
      GString::ToLower(this: (CUtlMemory<CImagePacker,int> *)v47.m_nGrowSize, a2: &v47);
      HIBYTE(v48) = strcmp(
                      (const char *)((*(_DWORD *)GString::Substring(
                                                   this: (GString *)&v47,
                                                   a2: (GString *)&result.m_bExternalIB,
                                                   a3: 0,
                                                   a4: 6u).HeapTypeBits
                                    & 0xFFFFFFFC)
                                   + 8),
                      (const char *)&stru_102A119C.m_pElements) == 0;
      v14 = (void *)(*(_DWORD *)&result.m_bExternalIB & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(
             Addend: (volatile LONG *)((*(_DWORD *)&result.m_bExternalIB & 0xFFFFFFFC) + 4),
             Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
      if ( HIBYTE(v48) != 0 )
        goto LABEL_16;
      HIBYTE(v48) = strcmp(
                      (const char *)((*(_DWORD *)GString::Substring(
                                                   this: (GString *)&v47,
                                                   a2: (GString *)&result.m_nIndices,
                                                   a3: 0,
                                                   a4: 8u).HeapTypeBits
                                    & 0xFFFFFFFC)
                                   + 8),
                      (const char *)&stru_102A119C.m_Elements.m_nGrowSize) == 0;
      v15 = (void *)(result.m_nIndices & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((result.m_nIndices & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v15);
      if ( HIBYTE(v48) != 0 )
LABEL_16:
        v49 = 1;
      v16 = (void *)((int)v47.m_pMemory & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v47.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
      v12 = v46;
      v5 = v45;
      if ( v49 == 0 )
      {
LABEL_20:
        m_nGrowSize = (const struct GString *)v47.m_nGrowSize;
        MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: v5);
        if ( GFxMovieRoot::FindExportedResource(
               this: MovieRoot,
               a2: (struct GFxMovieDefImpl *)v12,
               &result,
               a4: m_nGrowSize) == 0 )
        {
          GASEnvironment::LogScriptWarning(
            this: v5,
            a2: "ProcessImageTags: can't find a resource for export name '%s'\n",
            (const char *)((*(_DWORD *)v47.m_nGrowSize & 0xFFFFFFFC) + 8));
LABEL_40:
          GFxResource::Release(this: v12);
          goto LABEL_41;
        }
        if ( ((*((int (__thiscall **)(CMatQueuedIndexBuffer_vtbl *))result.IndexCount + 2))(a1: result.__vftable)
            & 0xFF00) != 0x100 )
        {
          (*((void (__thiscall **)(CMatQueuedIndexBuffer_vtbl *))result.IndexCount + 2))(a1: result.__vftable);
          goto LABEL_40;
        }
      }
      BitmapA = (CMatCallQueue *)GASBitmapData::LoadBitmapA(
                                   a1: (struct GASEnvironment *)v5,
                                   a2: (const struct GString *)v47.m_nGrowSize);
      result.m_pCallQueue = BitmapA;
      if ( BitmapA != nullptr )
      {
        v19 = *((_DWORD *)v5 + 30);
        v47.m_nGrowSize = BitmapA->m_nCurSerialNumber;
        v20 = *(_DWORD *)(v19 + 656);
        v21 = *(int (__thiscall **)(int, int, IIndexBuffer **))(*(_DWORD *)v20 + 40);
        result.m_pRTDynamicIndexBuffer = (IIndexBuffer *)258;
        v22 = v21(a1: v20, a2: 124, a3: &result.m_pRTDynamicIndexBuffer);
        if ( v22 != 0 )
          v23 = GFxShapeWithStyles::GFxShapeWithStyles(this: v22, result: (IClientUnknown *)0x1FF8);
        else
          v23 = nullptr;
        GFxShapeWithStyles::SetToImage(
          this: (GFxShapeWithStyles *)v23,
          bilinear: (struct GFxImageResource *)v47.m_nGrowSize,
          a3: true);
        HeapTypeBits = v10->HeapTypeBits;
        if ( v23 != nullptr )
          GFxShapeBase::AddRef(this: (GFxShapeBase *)v23);
        v25 = *(GFxShapeBase **)(HeapTypeBits + 8);
        if ( v25 != nullptr )
          GFxShapeBase::Release(this: v25);
        v26 = v47.m_nGrowSize;
        *(_DWORD *)(HeapTypeBits + 8) = v23;
        (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(v26 + 12) + 28))(a1: *(_DWORD *)(v26 + 12), a2: v42);
        result.m_pRTDynamicIndexBuffer = (IIndexBuffer *)(20 * (v42[2] - v42[0]));
        pData = v10[5].pData;
        *(float *)&result.m_pRTDynamicIndexBuffer = (float)(int)result.m_pRTDynamicIndexBuffer;
        v28 = *(float *)&result.m_pRTDynamicIndexBuffer;
        v47.m_nGrowSize = (int)result.m_pRTDynamicIndexBuffer;
        result.m_pRTDynamicIndexBuffer = (IIndexBuffer *)(20 * (v42[3] - v42[1]));
        *(float *)&result.m_pRTDynamicIndexBuffer = (float)(int)result.m_pRTDynamicIndexBuffer;
        v29 = *(float *)&result.m_pRTDynamicIndexBuffer;
        if ( pData != nullptr )
        {
          result.m_pIndexData = pData;
          *(float *)&v47.m_nGrowSize = (float)(unsigned int)pData;
        }
        v30 = v10[6].HeapTypeBits;
        if ( v30 != 0 )
        {
          result.m_pIndexData = v10[6].pData;
          *(float *)&result.m_pRTDynamicIndexBuffer = (float)v30;
        }
        v31 = v10->HeapTypeBits;
        v48 = v29 - 20.0;
        *(float *)&result.m_pIndexData = v48 + (double)(int)v10[7].pData;
        v32 = *(float *)&v47.m_nGrowSize;
        *(_QWORD *)&v47.m_nAllocationCount = (__int64)*(float *)&v47.m_nGrowSize;
        *(_DWORD *)(v31 + 24) = v47.m_nAllocationCount;
        m_pHardwareContext = result.m_pHardwareContext;
        v34 = *(float *)&result.m_pRTDynamicIndexBuffer;
        v35 = *(float *)&result.m_pRTDynamicIndexBuffer;
        result.m_pRTDynamicIndexBuffer = (IIndexBuffer *)(HIWORD(v48) | 0xC00);
        v36 = v10->HeapTypeBits;
        *(_QWORD *)&result.m_nRTStartIndex = (__int64)v35;
        *(_DWORD *)(v36 + 28) = (__int64)v35;
        v37 = v10->HeapTypeBits;
        *(float *)(v37 + 40) = *(float *)(v10->HeapTypeBits + 40) + 0.0;
        *(float *)(v37 + 52) = *(float *)(v37 + 52) - *(float *)&result.m_pIndexData;
        v38 = (float *)v10->HeapTypeBits;
        *(float *)&result.m_pIndexData = v32 / v28;
        *(float *)&result.m_pRTDynamicIndexBuffer = v34 / v29;
        v39 = *(float *)&result.m_pIndexData;
        v38[8] = v38[8] * *(float *)&result.m_pIndexData;
        v38[9] = v38[9] * v39;
        v38[10] = v39 * v38[10];
        v40 = *(float *)&result.m_pRTDynamicIndexBuffer;
        v38[11] = v38[11] * *(float *)&result.m_pRTDynamicIndexBuffer;
        v38[12] = v38[12] * v40;
        v38[13] = v40 * v38[13];
        LOBYTE(m_pHardwareContext[47].SetFlashlightMode) |= 2u;
        if ( v23 != nullptr )
          GFxShapeBase::Release(this: (GFxShapeBase *)v23);
        GRefCountBaseGC<323>::Release(a1: (int)result.m_pCallQueue, a2: HeapTypeBits);
        v12 = v46;
        v5 = v45;
      }
      else
      {
        GASEnvironment::LogScriptWarning(
          this: v5,
          a2: "ProcessImageTags: can't load the image '%s'\n",
          (const char *)((*(_DWORD *)v47.m_nGrowSize & 0xFFFFFFFC) + 8));
      }
      goto LABEL_40;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8B90
// Name: public: GASTextFieldObject::GASTextFieldObject(class GASGlobalContext __near *,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
GPtr<GFxAmpServer::SourceFileInfo> *__thiscall GASTextFieldObject::GASTextFieldObject(
        GPtr<GFxAmpServer::SourceFileInfo> *this,
        _KCRM_MARSHAL_HEADER *gCtxt,
        GRefCountWeakSupportImpl *a3)
{
  _EVENTLOGRECORD *GC; // eax
  struct GWeakPtrProxy *WeakProxy; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v6; // eax

  GC = (_EVENTLOGRECORD *)GASGlobalContext::GetGC(this: (GASGlobalContext *)gCtxt);
  GASObject::GASObject(result: GC);
  this->pObject = (GFxAmpServer::SourceFileInfo *)&GASTextFieldObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASTextFieldObject::`vftable'{for `GASObjectInterface'};
  if ( a3 != nullptr )
    WeakProxy = GRefCountWeakSupportImpl::CreateWeakProxy(this: a3);
  else
    WeakProxy = nullptr;
  *((_DWORD *)this + 13) = WeakProxy;
  v6 = (CTSQueue<CFunctor *,0,1>::Node_t *)((int (__thiscall *)(GRefCountWeakSupportImpl *))a3->__vftable[28].dtr_GRefCountImplCore)(a1: a3);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 4),
    psc: v6 + 15,
    psc_4: (CTSQueue<CFunctor *,0,1>::Node_t *)a3[10].pWeakProxy);
  *((_DWORD *)this + 14) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E8C00
// Name: public: virtual class GASObject __near * GASTextFieldCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASObject *__stdcall GASTextFieldCtorFunction::CreateNewObject(struct GASEnvironment *a1)
{
  struct GASEnvironment *v1; // ebx
  int v2; // ecx
  int (__thiscall *v3)(int, int, struct GASEnvironment **); // edx
  vc_attributes::PreRangeAttribute **v4; // edi
  GASObject *v5; // eax
  GASObject *v6; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  v1 = a1;
  v2 = *(_DWORD *)(*((_DWORD *)a1 + 30) + 656);
  v3 = *(int (__thiscall **)(int, int, struct GASEnvironment **))(*(_DWORD *)v2 + 40);
  v4 = (vc_attributes::PreRangeAttribute **)((char *)a1 + 120);
  a1 = (struct GASEnvironment *)323;
  v5 = (GASObject *)v3(a1: v2, a2: 60, a3: &a1);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  GASObject::GASObject(this: v5, a2: v1);
  v6->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASTextFieldObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v6[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASTextFieldObject::`vftable'{for `GASObjectInterface'};
  v6[6].sequence = 0;
  v6[7].pNode = nullptr;
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *v4,
                                                    result: (vc_attributes::InvalidCheckAttribute *)0xA);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&v6[2],
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v4,
    psc_4: Prototype);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100E8C80
// Name: private: static struct GFxTextHighlightInfo GASTextFieldProto::ParseStyle(class GASFnCall const __near &,unsigned int,struct GFxTextHighlightInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
const char **__usercall GASTextFieldProto::ParseStyle@<eax>(
        int a1@<edi>,
        unsigned __int64 a2@<st0>,
        const char **ConstStringNode,
        GASFnCall *a4,
        int a5,
        const char **a6)
{
  const char **v6; // eax
  const char **v7; // ebx
  GASFnCall *v8; // esi
  GASValue *v9; // eax
  struct GASObject *v10; // eax
  int v11; // edi
  GASFnCall v12; // eax
  const char **v13; // eax
  bool v14; // zf
  const char **v15; // eax
  GViewport *v16; // ecx
  char v17; // al
  int v18; // eax
  const char **v19; // eax
  const char **v20; // eax
  GViewport *v21; // ecx
  char v22; // al
  int v23; // eax
  const char **v24; // eax
  const char **v25; // eax
  double v26; // st7
  GViewport *v27; // ecx
  char v28; // al
  int v29; // eax
  const char **v30; // eax
  const char **v31; // eax
  const struct GASEnvironment *v33; // [esp+2Ch] [ebp-1Ch]
  GASValue v35[4]; // [esp+38h] [ebp-10h] BYREF

  v6 = a6;
  v7 = ConstStringNode;
  *ConstStringNode = *a6;
  v7[1] = v6[1];
  v7[2] = v6[2];
  v8 = a4;
  *((_BYTE *)v7 + 12) = *((_BYTE *)v6 + 12);
  if ( (int)v8[7] >= 1 )
  {
    v33 = (const struct GASEnvironment *)v8[6];
    v9 = (GASValue *)GASFnCall::Arg(this: v8, a2: a5);
    v10 = GASValue::ToObject(this: v9, a2: a1, a3: v33);
    a4 = (GASFnCall *)v10;
    if ( v10 != nullptr )
    {
      v10[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v10[1].pNode->pNext + 1) & 0x8FFFFFFF);
      v11 = (int)&v10[2];
      v12 = v8[6];
      LOBYTE(v35[0]) = 0;
      ConstStringNode = (const char **)GASStringManager::CreateConstStringNode(
                                         this: *(GASStringManager **)(v12[3].cbSize + 636),
                                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E390.m_Memory.m_nGrowSize,
                                         a3: 9u,
                                         a4: 0);
      ++ConstStringNode[2];
      HIBYTE(a6) = (*(int (__thiscall **)(int, GASFnCall, const char ***, GASValue *, int))(*(_DWORD *)v11 + 16))(
                     a1: v11,
                     a2: v8[6],
                     a3: &ConstStringNode,
                     a4: v35,
                     a5: a1);
      v13 = ConstStringNode;
      v14 = ConstStringNode[2]-- == (const char *)1;
      if ( v14 )
        GASStringNode::ReleaseNode(a1: (int)v13);
      if ( HIBYTE(a6) != 0 )
      {
        GASValue::ToStringImpl(
          this: (unsigned __int8 *)v35,
          a2: (int *)&ConstStringNode,
          a3: (tagRID_DEVICE_INFO_KEYBOARD *)v8[6],
          precision: -1,
          debug: false);
        HIBYTE(a6) = GASString::operator==(this: &ConstStringNode, a2: (const char *)&stru_102A09D0);
        v15 = ConstStringNode;
        v14 = ConstStringNode[2]-- == (const char *)1;
        if ( v14 )
          GASStringNode::ReleaseNode(a1: (int)v15);
        if ( HIBYTE(a6) != 0 )
        {
          *((_BYTE *)v7 + 12) &= ~0x10u;
        }
        else
        {
          *(double *)&a2 = GASValue::ToNumber(
                             this: v35,
                             a2: v11,
                             a3: *(long double *)&a2,
                             result: (_SERVICE_STATUS *)v8[6]);
          GASNumberUtil::IsNaNOrInfinity(v: v16, va: a2, v_4: HIDWORD(a2));
          if ( v17 == 0 )
          {
            v18 = GASValue::ToUInt32(this: v35, a2: v11, a3: *(long double *)&a2, a4: (_SERVICE_STATUS *)v8[6]);
            *((_BYTE *)v7 + 12) |= 0x10u;
            v7[1] = (const char *)(v18 | 0xFF000000);
          }
        }
      }
      ConstStringNode = (const char **)GASStringManager::CreateConstStringNode(
                                         this: *(GASStringManager **)(v8[6][3].cbSize + 636),
                                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"backgroundColor",
                                         a3: 0xFu,
                                         a4: 0);
      ++ConstStringNode[2];
      HIBYTE(a6) = (*(int (__thiscall **)(int, GASFnCall, const char ***, GASValue *))(*(_DWORD *)v11 + 16))(
                     a1: v11,
                     a2: v8[6],
                     a3: &ConstStringNode,
                     a4: v35);
      v19 = ConstStringNode;
      v14 = ConstStringNode[2]-- == (const char *)1;
      if ( v14 )
        GASStringNode::ReleaseNode(a1: (int)v19);
      if ( HIBYTE(a6) != 0 )
      {
        GASValue::ToStringImpl(
          this: (unsigned __int8 *)v35,
          a2: (int *)&ConstStringNode,
          a3: (tagRID_DEVICE_INFO_KEYBOARD *)v8[6],
          precision: -1,
          debug: false);
        HIBYTE(a6) = GASString::operator==(this: &ConstStringNode, a2: (const char *)&stru_102A09D0);
        v20 = ConstStringNode;
        v14 = ConstStringNode[2]-- == (const char *)1;
        if ( v14 )
          GASStringNode::ReleaseNode(a1: (int)v20);
        if ( HIBYTE(a6) != 0 )
        {
          *((_BYTE *)v7 + 12) &= ~8u;
        }
        else
        {
          *(double *)&a2 = GASValue::ToNumber(
                             this: v35,
                             a2: v11,
                             a3: *(long double *)&a2,
                             result: (_SERVICE_STATUS *)v8[6]);
          GASNumberUtil::IsNaNOrInfinity(v: v21, va: a2, v_4: HIDWORD(a2));
          if ( v22 == 0 )
          {
            v23 = GASValue::ToUInt32(this: v35, a2: v11, a3: *(long double *)&a2, a4: (_SERVICE_STATUS *)v8[6]);
            *((_BYTE *)v7 + 12) |= 8u;
            *v7 = (const char *)(v23 | 0xFF000000);
          }
        }
      }
      ConstStringNode = (const char **)GASStringManager::CreateConstStringNode(
                                         this: *(GASStringManager **)(v8[6][3].cbSize + 636),
                                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"underlineColor",
                                         a3: 0xEu,
                                         a4: 0);
      ++ConstStringNode[2];
      HIBYTE(a6) = (*(int (__thiscall **)(int, GASFnCall, const char ***, GASValue *))(*(_DWORD *)v11 + 16))(
                     a1: v11,
                     a2: v8[6],
                     a3: &ConstStringNode,
                     a4: v35);
      v24 = ConstStringNode;
      v14 = ConstStringNode[2]-- == (const char *)1;
      if ( v14 )
        GASStringNode::ReleaseNode(a1: (int)v24);
      if ( HIBYTE(a6) != 0 )
      {
        GASValue::ToStringImpl(
          this: (unsigned __int8 *)v35,
          a2: (int *)&ConstStringNode,
          a3: (tagRID_DEVICE_INFO_KEYBOARD *)v8[6],
          precision: -1,
          debug: false);
        HIBYTE(a6) = GASString::operator==(this: &ConstStringNode, a2: (const char *)&stru_102A09D0);
        v25 = ConstStringNode;
        v14 = ConstStringNode[2]-- == (const char *)1;
        if ( v14 )
          GASStringNode::ReleaseNode(a1: (int)v25);
        if ( HIBYTE(a6) != 0 )
        {
          *((_BYTE *)v7 + 12) &= ~0x20u;
        }
        else
        {
          v26 = GASValue::ToNumber(this: v35, a2: v11, a3: *(long double *)&a2, result: (_SERVICE_STATUS *)v8[6]);
          GASNumberUtil::IsNaNOrInfinity(v: v27, va: SLODWORD(v26), v_4: HIDWORD(*(unsigned __int64 *)&v26));
          if ( v28 == 0 )
          {
            v29 = GASValue::ToUInt32(this: v35, a2: v11, a3: v26, a4: (_SERVICE_STATUS *)v8[6]);
            *((_BYTE *)v7 + 12) |= 0x20u;
            v7[2] = (const char *)(v29 | 0xFF000000);
          }
        }
      }
      ConstStringNode = (const char **)GASStringManager::CreateConstStringNode(
                                         this: *(GASStringManager **)(v8[6][3].cbSize + 636),
                                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2F28.m_pElements,
                                         a3: 0xEu,
                                         a4: 0);
      ++ConstStringNode[2];
      HIBYTE(a6) = (*(int (__thiscall **)(int, GASFnCall, const char ***))(*(_DWORD *)v11 + 16))(
                     a1: v11,
                     a2: v8[6],
                     a3: &ConstStringNode);
      v30 = ConstStringNode;
      v14 = ConstStringNode[2]-- == (const char *)1;
      if ( v14 )
        GASStringNode::ReleaseNode(a1: (int)v30);
      if ( HIBYTE(a6) != 0 )
      {
        GASValue::ToStringImpl(
          this: (unsigned __int8 *)v35,
          a2: (int *)&a6,
          a3: (tagRID_DEVICE_INFO_KEYBOARD *)v8[6],
          precision: -1,
          debug: false);
        if ( GASString::operator==(this: &a6, a2: (const char *)&stru_102A2F28.m_Memory.m_nGrowSize) )
        {
          *((_BYTE *)v7 + 12) = (_BYTE)v7[3] & 0xF8 | 3;
        }
        else if ( GASString::operator==(this: &a6, a2: (const char *)&stru_102A2F28) )
        {
          *((_BYTE *)v7 + 12) = (_BYTE)v7[3] & 0xF8 | 1;
        }
        else if ( GASString::operator==(this: &a6, a2: "thick") )
        {
          *((_BYTE *)v7 + 12) = (_BYTE)v7[3] & 0xF8 | 2;
        }
        else if ( GASString::operator==(this: &a6, a2: "ditheredSingle") )
        {
          *((_BYTE *)v7 + 12) = (_BYTE)v7[3] & 0xF8 | 4;
        }
        else if ( GASString::operator==(this: &a6, a2: "ditheredThick") )
        {
          *((_BYTE *)v7 + 12) = (_BYTE)v7[3] & 0xF8 | 5;
        }
        else
        {
          *((_BYTE *)v7 + 12) &= 0xF8u;
        }
        v31 = a6;
        v14 = a6[2]-- == (const char *)1;
        if ( v14 )
          GASStringNode::ReleaseNode(a1: (int)v31);
      }
      GASValue::~GASValue(this: v35, a2: -1);
      GRefCountBaseGC<323>::Release(a1: (int)a4, a2: -1);
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100E9050
// Name: private: static void GASTextFieldProto::MakeStyle(class GASFnCall const __near &,struct GFxTextHighlightInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASTextFieldProto::MakeStyle(int a1, const struct GFxTextHighlightInfo *a2)
{
  const struct GASFnCall *v2; // edi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  GASObject *v5; // eax
  GASObject *v6; // ebx
  const struct GFxTextHighlightInfo *v7; // esi
  char *p_m_nGrowSize; // esi
  GASStringManager *v9; // ecx
  struct GASStringNode *ConstStringNode; // esi
  tagWNDCLASSW *v12; // eax
  tagWNDCLASSW *v13; // edx
  tagWNDCLASSW *v14; // ecx
  GASValue v15; // [esp+8h] [ebp-10h] BYREF
  double v16; // [esp+Ch] [ebp-Ch]

  v2 = (const struct GASFnCall *)a1;
  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 24) + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a1 = 323;
  v5 = (GASObject *)v4(a1: v3, a2: 52, a3: &a1);
  if ( v5 != nullptr )
    v6 = GASObject::GASObject(this: v5, a2: *((struct GASEnvironment **)v2 + 6));
  else
    v6 = nullptr;
  v7 = a2;
  if ( (*((_BYTE *)a2 + 12) & 7) != 0 )
  {
    switch ( *((_BYTE *)a2 + 12) & 7 )
    {
      case 1:
        p_m_nGrowSize = (char *)&stru_102A2F28;
        goto LABEL_11;
      case 2:
        p_m_nGrowSize = "thick";
        goto LABEL_11;
      case 3:
        p_m_nGrowSize = (char *)&stru_102A2F28.m_Memory.m_nGrowSize;
        goto LABEL_11;
      case 4:
        p_m_nGrowSize = "ditheredSingle";
        goto LABEL_11;
      case 5:
        p_m_nGrowSize = "ditheredThick";
LABEL_11:
        v9 = *(GASStringManager **)(*(_DWORD *)(*((_DWORD *)v2 + 6) + 120) + 636);
        a1 = (int)(p_m_nGrowSize + 1);
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: v9,
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)p_m_nGrowSize,
                            a3: strlen(p_m_nGrowSize),
                            a4: 0);
        ++*((_DWORD *)ConstStringNode + 2);
        LOBYTE(v15) = 5;
        LODWORD(v16) = ConstStringNode;
        ++*((_DWORD *)ConstStringNode + 2);
        GASObjectInterface::SetConstMemberRaw(
          this: &v6[2],
          result: (tagWNDCLASSW *)(*((_DWORD *)v2 + 6) + 120),
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2F28.m_pElements,
          a4: (int)&v15);
        GASValue::~GASValue(this: &v15, a2: (int)v2);
        if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
          GASStringNode::ReleaseNode(a1: (int)ConstStringNode);
        v7 = a2;
        break;
      default:
        break;
    }
  }
  if ( (*((_BYTE *)v7 + 12) & 0x20) != 0 )
  {
    a2 = (const struct GFxTextHighlightInfo *)(*((_DWORD *)v7 + 2) & 0xFFFFFF);
    LOBYTE(v15) = 3;
    v12 = *((tagWNDCLASSW **)v2 + 6);
    v16 = (double)(int)a2;
    GASObjectInterface::SetConstMemberRaw(
      this: &v6[2],
      result: v12 + 3,
      a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"underlineColor",
      a4: (int)&v15);
    GASValue::~GASValue(this: &v15, a2: (int)v2);
  }
  if ( (*((_BYTE *)v7 + 12) & 8) != 0 )
  {
    a2 = (const struct GFxTextHighlightInfo *)(*(_DWORD *)v7 & 0xFFFFFF);
    LOBYTE(v15) = 3;
    v13 = *((tagWNDCLASSW **)v2 + 6);
    v16 = (double)(int)a2;
    GASObjectInterface::SetConstMemberRaw(
      this: &v6[2],
      result: v13 + 3,
      a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"backgroundColor",
      a4: (int)&v15);
    GASValue::~GASValue(this: &v15, a2: (int)v2);
  }
  if ( (*((_BYTE *)v7 + 12) & 0x10) != 0 )
  {
    a2 = (const struct GFxTextHighlightInfo *)(*((_DWORD *)v7 + 1) & 0xFFFFFF);
    LOBYTE(v15) = 3;
    v14 = *((tagWNDCLASSW **)v2 + 6);
    v16 = (double)(int)a2;
    GASObjectInterface::SetConstMemberRaw(
      this: &v6[2],
      result: v14 + 3,
      a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E390.m_Memory.m_nGrowSize,
      a4: (int)&v15);
    GASValue::~GASValue(this: &v15, a2: (int)v2);
  }
  GASValue::SetAsObject(this: *((GASValue **)v2 + 1), a2: v6);
  if ( v6 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v6, a2: (int)v2);
}

//------------------------------------------------------------------------------
// Address: 0x100E9240
// Name: public: static void GASTextFieldProto::SetIMECompositionStringStyle(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextFieldProto::SetIMECompositionStringStyle(
        int a1@<edi>,
        unsigned __int64 a2@<st0>,
        GASFnCall *a3)
{
  GASFnCall v3; // eax
  tagALTTABINFO *v4; // ecx
  int cxItem; // eax
  GPtr<GFxAmpServer::SourceFileInfo> *v6; // esi
  GASFnCall v7; // eax
  GPtr<GFxAmpServer::SourceFileInfo> *p_cxItem; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v9; // edi
  unsigned __int8 *v10; // eax
  const char **v11; // eax
  bool v12; // zf
  const GPtr<GFxAmpMemFragReport> *IMECompositionStringStyles; // esi
  GPtr<GFxAmpMemFragReport> *v14; // esi
  const char **v15; // eax
  GFxAmpMemFragReport *v16; // ecx
  GFxAmpMemFragReport *v17; // edx
  GFxAmpMemFragReport *v18; // ecx
  GPtr<GFxAmpServer::SourceFileInfo> *v19; // ecx
  const char **v20; // eax
  const char *v21; // [esp+4h] [ebp-70h] BYREF
  const char **v22; // [esp+14h] [ebp-60h] BYREF
  GPtr<GFxAmpServer::SourceFileInfo> *v23; // [esp+18h] [ebp-5Ch]
  GPtr<GFxAmpMemFragReport> v24[20]; // [esp+1Ch] [ebp-58h] BYREF
  char v25; // [esp+6Ch] [ebp-8h]

  if ( a3[2] != nullptr )
  {
    if ( (*(int (__thiscall **)(GASFnCall))(a3[2]->cbSize + 8))(a1: a3[2]) == 4 )
    {
      v3 = a3[2];
      if ( v3 != nullptr )
        v4 = v3 - 3;
      else
        v4 = nullptr;
      cxItem = v4[6].cxItem;
      if ( cxItem != 0 )
        *(_DWORD *)(cxItem + 8) = (*(_DWORD *)(cxItem + 8) + 1) & 0x8FFFFFFF;
      v6 = (GPtr<GFxAmpServer::SourceFileInfo> *)v4[6].cxItem;
      v23 = v6;
    }
    else
    {
      if ( (*(int (__thiscall **)(GASFnCall))(a3[2]->cbSize + 8))(a1: a3[2]) != 13 )
        return;
      v7 = a3[2];
      if ( v7 != nullptr )
      {
        p_cxItem = (GPtr<GFxAmpServer::SourceFileInfo> *)&v7[-1].cxItem;
        if ( p_cxItem != nullptr )
          p_cxItem[2].pObject = (GFxAmpServer::SourceFileInfo *)(((int)&p_cxItem[2].pObject->__vftable + 1) & 0x8FFFFFFF);
      }
      else
      {
        p_cxItem = nullptr;
      }
      v23 = p_cxItem;
      v6 = p_cxItem;
    }
    if ( v6 != nullptr )
    {
      if ( (int)a3[7] >= 1 )
      {
        v9 = (tagRID_DEVICE_INFO_KEYBOARD *)a3[6];
        v10 = (unsigned __int8 *)GASFnCall::Arg(this: a3, a2: 0);
        GASValue::ToStringImpl(this: v10, a2: (int *)&v22, a3: v9, precision: -1, debug: false);
        a1 = GFx_StringToIMEStyleCategory(a1: &v22);
        if ( a1 < 5 )
        {
          IMECompositionStringStyles = (const GPtr<GFxAmpMemFragReport> *)GASTextFieldObject::GetIMECompositionStringStyles(this: v6);
          GFxTextIMEStyle::GFxTextIMEStyle(this: (GFxTextIMEStyle *)v24);
          if ( IMECompositionStringStyles != nullptr )
            GFxTextIMEStyle::GFxTextIMEStyle(this: v24, __that: IMECompositionStringStyles);
          v14 = &v24[4 * a1];
          v15 = GASTextFieldProto::ParseStyle(a1, a2, ConstStringNode: &v21, a4: a3, a5: 1, a6: (const char **)v14);
          v16 = (GFxAmpMemFragReport *)*v15;
          v25 |= 1 << a1;
          v17 = (GFxAmpMemFragReport *)v15[1];
          v14->pObject = v16;
          v18 = (GFxAmpMemFragReport *)v15[2];
          v14[1].pObject = v17;
          LOBYTE(v17) = *((_BYTE *)v15 + 12);
          v14[2].pObject = v18;
          v19 = v23;
          LOBYTE(v14[3].pObject) = (_BYTE)v17;
          GASTextFieldObject::SetIMECompositionStringStyles(this: v19, imeStyles: v24);
          v20 = v22;
          v12 = v22[2]-- == (const char *)1;
          if ( v12 )
            GASStringNode::ReleaseNode(a1: (int)v20);
          v6 = v23;
        }
        else
        {
          v11 = v22;
          v12 = v22[2]-- == (const char *)1;
          if ( v12 )
            GASStringNode::ReleaseNode(a1: (int)v11);
        }
      }
      GRefCountBaseGC<323>::Release(a1: (int)v6, a2: a1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E93B0
// Name: public: static void GASTextFieldProto::GetIMECompositionStringStyle(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASTextFieldProto::GetIMECompositionStringStyle(GASFnCall *a1)
{
  GASValue *v2; // edi
  GASFnCall v3; // eax
  GASFnCall v4; // eax
  int cxItem; // ecx
  GPtr<GFxAmpServer::SourceFileInfo> *p_cxItem; // eax
  GASFnCall v7; // eax
  const GPtr<GFxAmpServer::SourceFileInfo> *IMECompositionStringStyles; // ebx
  tagRID_DEVICE_INFO_KEYBOARD *v9; // edi
  unsigned __int8 *v10; // eax
  int v11; // eax
  const char **v12; // eax
  const char **v14; // [esp+8h] [ebp-4h] BYREF
  GASFnCall *v15; // [esp+14h] [ebp+8h]

  v2 = (GASValue *)a1[1];
  GASValue::DropRefs(this: v2, a2: (int)v2);
  *(_BYTE *)v2 = 0;
  if ( a1[2] != nullptr )
  {
    if ( (*(int (__thiscall **)(GASFnCall))(a1[2]->cbSize + 8))(a1: a1[2]) == 4 )
    {
      v3 = a1[2];
      if ( v3 != nullptr )
        v4 = v3 - 3;
      else
        v4 = nullptr;
      cxItem = v4[6].cxItem;
      if ( cxItem != 0 )
        *(_DWORD *)(cxItem + 8) = (*(_DWORD *)(cxItem + 8) + 1) & 0x8FFFFFFF;
      p_cxItem = (GPtr<GFxAmpServer::SourceFileInfo> *)v4[6].cxItem;
    }
    else
    {
      if ( (*(int (__thiscall **)(GASFnCall))(a1[2]->cbSize + 8))(a1: a1[2]) != 13 )
        return;
      v7 = a1[2];
      if ( v7 != nullptr )
      {
        p_cxItem = (GPtr<GFxAmpServer::SourceFileInfo> *)&v7[-1].cxItem;
        if ( p_cxItem != nullptr )
          p_cxItem[2].pObject = (GFxAmpServer::SourceFileInfo *)(((int)&p_cxItem[2].pObject->__vftable + 1) & 0x8FFFFFFF);
      }
      else
      {
        p_cxItem = nullptr;
      }
    }
    v15 = (GASFnCall *)p_cxItem;
    if ( p_cxItem != nullptr )
    {
      IMECompositionStringStyles = GASTextFieldObject::GetIMECompositionStringStyles(this: p_cxItem);
      if ( IMECompositionStringStyles != nullptr )
      {
        v9 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
        v10 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 0);
        GASValue::ToStringImpl(this: v10, a2: (int *)&v14, a3: v9, precision: -1, debug: false);
        v2 = (GASValue *)&v14;
        v11 = GFx_StringToIMEStyleCategory(a1: &v14);
        if ( v11 < 5 )
          GASTextFieldProto::MakeStyle(
            (int)a1,
            a2: (const struct GFxTextHighlightInfo *)&IMECompositionStringStyles[4 * v11]);
        v12 = v14;
        if ( v14[2]-- == (const char *)1 )
          GASStringNode::ReleaseNode(a1: (int)v12);
      }
      GRefCountBaseGC<323>::Release(a1: (int)v15, a2: (int)v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E94B0
// Name: public: GFxTextKeyMap::GFxTextKeyMap(void)
// Source: json
//------------------------------------------------------------------------------
GFxTextKeyMap *__thiscall GFxTextKeyMap::GFxTextKeyMap(GFxTextKeyMap *this)
{
  this->__vftable = (GFxTextKeyMap_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->SType = State_TextKeyMap;
  this->__vftable = (GFxTextKeyMap_vtbl *)&off_102A2F58;
  this->Map.Data.Data = nullptr;
  this->Map.Data.Size = 0;
  this->Map.Data.Policy.Capacity = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E9520
// Name: public: void GFxTextKeyMap::AddKeyEntry(struct GFxTextKeyMap::KeyMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextKeyMap::AddKeyEntry(GFxTextKeyMap *this, const struct GFxTextKeyMap::KeyMapEntry *a2)
{
  const struct GFxTextKeyMap::KeyMapEntry *v2; // ebx
  IMaterialSystem *p_Map; // edi
  int Size; // ecx
  unsigned int v5; // esi
  IMaterialSystem_vtbl *v6; // eax
  GFxTextKeyMap::KeyAction *v7; // esi
  ApplicationInstantCountersInfo_t *v8; // [esp+0h] [ebp-18h]

  v2 = a2;
  p_Map = (IMaterialSystem *)&this->Map;
  Size = this->Map.Data.Size;
  v5 = 0;
  if ( Size > 0 )
  {
    do
    {
      if ( (signed int)(*((_DWORD *)&p_Map->Disconnect + 4 * (Size >> 1) + 4 * v5) - a2->KeyCode) >= 0 )
      {
        Size >>= 1;
      }
      else
      {
        v5 += (Size >> 1) + 1;
        Size += -1 - (Size >> 1);
      }
    }
    while ( Size > 0 );
    v2 = a2;
  }
  GArrayData<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy>::Resize(
    this: p_Map,
    newSize: (ApplicationPerformanceCountersInfo_t *)((char *)&p_Map[1].Connect + 1),
    a3: v8);
  v6 = p_Map[1].__vftable;
  if ( v5 < (unsigned int)&v6[-1].GetFrameTimestamps + 3 )
    memmove(
      dst: (unsigned __int8 *)&p_Map->Shutdown + 16 * v5,
      src: (unsigned __int8 *)p_Map->__vftable + 16 * v5,
      count: 16 * (_DWORD)((char *)v6 - v5 - 1));
  v7 = (GFxTextKeyMap::KeyAction *)((char *)p_Map->__vftable + 16 * v5);
  if ( v7 != nullptr )
  {
    *v7 = v2->Action;
    v7[1] = (GFxTextKeyMap::KeyAction)v2->KeyCode;
    v7[2] = (GFxTextKeyMap::KeyAction)v2->SpecKeysPressed;
    v7[3] = (GFxTextKeyMap::KeyAction)v2->State;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E95D0
// Name: public: class GFxTextKeyMap __near * GFxTextKeyMap::InitWindowsKeyMap(void)
// Source: json
//------------------------------------------------------------------------------
GenericThreadLocals::CThreadLocalPtr<IMatRenderContextInternal> *__thiscall GFxTextKeyMap::InitWindowsKeyMap(
        GenericThreadLocals::CThreadLocalPtr<IMatRenderContextInternal> *this)
{
  struct GFxTextKeyMap::KeyMapEntry v3; // [esp+Ch] [ebp-10h] BYREF

  v3.Action = KeyAct_EnterSelectionMode;
  v3.KeyCode = 16;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_LeaveSelectionMode;
  v3.KeyCode = 16;
  v3.SpecKeysPressed = 0;
  v3.State = State_Up;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Up;
  v3.KeyCode = 38;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Down;
  v3.KeyCode = 40;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Left;
  v3.KeyCode = 37;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Right;
  v3.KeyCode = 39;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_PageUp;
  v3.KeyCode = 33;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_PageDown;
  v3.KeyCode = 34;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_LineHome;
  v3.KeyCode = 36;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_LineEnd;
  v3.KeyCode = 35;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_PageHome;
  v3.KeyCode = 33;
  v3.SpecKeysPressed = 2;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_PageEnd;
  v3.KeyCode = 34;
  v3.SpecKeysPressed = 2;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_DocHome;
  v3.KeyCode = 36;
  v3.SpecKeysPressed = 2;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_DocEnd;
  v3.KeyCode = 35;
  v3.SpecKeysPressed = 2;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Backspace;
  v3.KeyCode = 8;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Delete;
  v3.KeyCode = 46;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Return;
  v3.KeyCode = 13;
  v3.SpecKeysPressed = 0;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Copy;
  v3.KeyCode = 67;
  v3.SpecKeysPressed = 2;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Copy;
  v3.KeyCode = 45;
  v3.SpecKeysPressed = 2;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Paste;
  v3.KeyCode = 86;
  v3.SpecKeysPressed = 2;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Paste;
  v3.KeyCode = 45;
  v3.SpecKeysPressed = 1;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Cut;
  v3.KeyCode = 88;
  v3.SpecKeysPressed = 2;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_Cut;
  v3.KeyCode = 46;
  v3.SpecKeysPressed = 1;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  v3.Action = KeyAct_SelectAll;
  v3.KeyCode = 65;
  v3.SpecKeysPressed = 2;
  v3.State = State_Down;
  GFxTextKeyMap::AddKeyEntry((GFxTextKeyMap *)this, a2: &v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E9B20
// Name: public: void GFxEditTextCharacter::TextDocumentListener::OnScroll(class GFxTextDocView __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::TextDocumentListener::OnScroll(
        GFxEditTextCharacter::TextDocumentListener *this,
        struct GFxTextDocView *a2)
{
  tagAXISINFOA *v2; // esi
  int v3; // edi
  struct GFxMovieRoot *MovieRoot; // eax
  GASStringManager *v5; // ecx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *ConstStringNode; // edi
  tagAXISINFOA *v8; // edi
  struct GFxMovieRoot *v9; // eax
  GPtr<IDirect3DPixelShader9> *inserted; // edi
  GRefCountNTSImpl *pObject; // ecx
  GRefCountNTSImpl *v12; // ecx
  int v13; // edi
  GASValue *i; // esi
  GMatrix3D v15; // [esp+Ch] [ebp-74h] BYREF
  GASValue v16[4]; // [esp+4Ch] [ebp-34h] BYREF
  GASValue v17[4]; // [esp+5Ch] [ebp-24h] BYREF
  GPtr<IDirect3DPixelShader9> v18; // [esp+6Ch] [ebp-14h] BYREF
  int v19; // [esp+70h] [ebp-10h]
  int v20; // [esp+74h] [ebp-Ch]
  GASValue *v21; // [esp+78h] [ebp-8h]
  GASEnvironment *v22; // [esp+7Ch] [ebp-4h]

  v2 = (tagAXISINFOA *)((char *)this - 244);
  v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 61) + 112))(a1: (char *)this - 244);
  memset(&v15.M_[0][3], 0, 14);
  *(_DWORD *)((char *)&v15.M_[1][2] + 2) = 65280;
  memset(v15.M_[2], 0, 9);
  memset(v15.M_[3], 0, sizeof(v15.M_[3]));
  v15.M_[0][0] = 0.0;
  *(_QWORD *)&v15.M_[0][1] = 4;
  ++v2->axMaxValue;
  v22 = (GASEnvironment *)v3;
  *(_QWORD *)&v15.M_[0][2] = (unsigned int)v2;
  LODWORD(v15.M_[2][3]) = GFxEditTextCharacter::TextDocumentListener::BroadcastMessage;
  MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)v3);
  if ( GFxMovieRoot::ActionQueueType::FindEntry(this: (_DWORD *)MovieRoot + 2306, a2: 4, a3: (int)&v15) == nullptr )
  {
    v5 = *(GASStringManager **)(*(_DWORD *)(v3 + 120) + 636);
    v18.pObject = nullptr;
    v19 = 0;
    v20 = 0;
    ConstStringNode = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)GASStringManager::CreateConstStringNode(
                                                                                                   this: v5,
                                                                                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2F5C,
                                                                                                   a3: 0xAu,
                                                                                                   a4: 0);
    ++ConstStringNode->m_nGrowSize;
    LOBYTE(v17[0]) = 5;
    v17[1] = ConstStringNode;
    ++ConstStringNode->m_nGrowSize;
    GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: &v18,
      pheapAddr: (ButtonCode_t)&v18,
      newSize: 1u);
    if ( &v18.pObject[4 * v19] != (IDirect3DPixelShader9 *)16 )
      GASValue::GASValue(this: (GASValue *)&v18.pObject[4 * v19 - 4], v: (tagWNDCLASSW *)v17);
    GASValue::~GASValue(this: v17, a2: (int)ConstStringNode);
    if ( ConstStringNode->m_nGrowSize-- == 1 )
      GASStringNode::ReleaseNode(a1: (int)ConstStringNode);
    v8 = GASValue::GASValue(this: v16, result: v2);
    GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: &v18,
      pheapAddr: (ButtonCode_t)&v18,
      newSize: v19 + 1);
    v21 = (GASValue *)&v18.pObject[4 * v19 - 4];
    if ( &v18.pObject[4 * v19] != (IDirect3DPixelShader9 *)16 )
      GASValue::GASValue(this: (GASValue *)&v18.pObject[4 * v19 - 4], v: (tagWNDCLASSW *)v8);
    GASValue::~GASValue(this: v16, a2: (int)v8);
    v9 = GASEnvironment::GetMovieRoot(this: v22);
    inserted = (GPtr<IDirect3DPixelShader9> *)GFxMovieRoot::ActionQueueType::InsertEntry(
                                                this: (int)v9 + 9224,
                                                result: (const GPoint3<float> *)4);
    inserted[1].pObject = (IDirect3DPixelShader9 *)4;
    ++v2->axMaxValue;
    pObject = (GRefCountNTSImpl *)inserted[2].pObject;
    if ( pObject != nullptr )
      GRefCountNTSImpl::Release(this: pObject);
    inserted[2].pObject = (IDirect3DPixelShader9 *)v2;
    v12 = (GRefCountNTSImpl *)inserted[3].pObject;
    if ( v12 != nullptr )
      GRefCountNTSImpl::Release(this: v12);
    inserted[3].pObject = nullptr;
    inserted[11].pObject = (IDirect3DPixelShader9 *)GFxEditTextCharacter::TextDocumentListener::BroadcastMessage;
    GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::operator=(
      this: inserted + 12,
      a2: &v18);
    v13 = v19;
    for ( i = v21; v13 != 0; --v13 )
    {
      GASValue::~GASValue(this: i, a2: v13);
      i -= 4;
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v18.pObject);
  }
  GFxMovieRoot::ActionEntry::~ActionEntry(this: &v15);
}

//------------------------------------------------------------------------------
// Address: 0x100E9CE0
// Name: public: virtual void GFxEditTextCharacter::TextDocumentListener::View_OnVScroll(class GFxTextDocView __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::TextDocumentListener::View_OnVScroll(
        GFxEditTextCharacter::TextDocumentListener *this,
        struct GFxTextDocView *a2,
        unsigned int a3)
{
  GFxEditTextCharacter::TextDocumentListener::OnScroll(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100E9CF0
// Name: public: virtual void GFxEditTextCharacter::TextDocumentListener::View_OnMaxScrollChanged(class GFxTextDocView __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::TextDocumentListener::View_OnMaxScrollChanged(
        GFxEditTextCharacter::TextDocumentListener *this,
        struct GFxTextDocView *a2)
{
  GFxEditTextCharacter::TextDocumentListener::OnScroll(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100E9D00
// Name: public: void GFxEditTextCharacter::NotifyChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::NotifyChanged(tagAXISINFOA *result)
{
  int v2; // edi
  bool v3; // zf
  struct GASValue *v4; // ecx
  int v5; // esi
  tagAXISINFOA *v6; // eax
  int v7; // esi
  GASStringManager *v8; // ecx
  struct GASStringNode *ConstStringNode; // eax
  int v10; // edx
  struct GASValue *v11; // eax
  int i; // edi
  int v13; // [esp-4h] [ebp-2Ch]
  GASValue v14[4]; // [esp+Ch] [ebp-1Ch] BYREF
  int v15; // [esp+1Ch] [ebp-Ch]
  struct GASValue *v16; // [esp+20h] [ebp-8h] BYREF
  int v17; // [esp+24h] [ebp-4h]

  v2 = (*(int (__thiscall **)(tagAXISINFOA *))(result->axMinValue + 112))(a1: result);
  v3 = *(_BYTE *)(*(_DWORD *)(v2 + 120) + 684) == 1;
  v17 = 1;
  if ( v3 )
  {
    v4 = *((struct GASValue **)result + 67);
    v16 = v4;
    if ( v4 != (struct GASValue *)-1 )
    {
      *(_DWORD *)(v2 + 8) += 16;
      if ( *(_DWORD *)(v2 + 8) >= *(_DWORD *)(v2 + 16) )
      {
        GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v2 + 8));
        v4 = v16;
      }
      v5 = *(_DWORD *)(v2 + 8);
      if ( v5 != 0 )
      {
        *(_BYTE *)v5 = 4;
        *(_DWORD *)(v5 + 4) = v4;
      }
      v17 = 2;
    }
  }
  v6 = GASValue::GASValue(this: v14, result);
  *(_DWORD *)(v2 + 8) += 16;
  v7 = v2 + 8;
  v16 = (struct GASValue *)v6;
  if ( *(_DWORD *)(v2 + 8) >= *(_DWORD *)(v2 + 16) )
    GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v2 + 8));
  if ( *(_DWORD *)v7 != 0 )
    GASValue::GASValue(this: *(GASValue **)v7, v: (tagWNDCLASSW *)v16);
  GASValue::~GASValue(this: v14, a2: v2);
  v8 = *(GASStringManager **)(*(_DWORD *)(v2 + 120) + 636);
  v15 = ((*(_DWORD *)(v2 + 8) - *(_DWORD *)(v2 + 12)) >> 4) + 32 * *(_DWORD *)(v2 + 28) - 32;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: v8,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2F5C.m_Size,
                      a3: 9u,
                      a4: 0);
  v10 = v17;
  v13 = v15;
  v16 = ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  GASAsBroadcaster::BroadcastMessage(
    a1: (struct GASEnvironment *)v2,
    eventName: (_IMAGE_SYMBOL_EX *)result + 6,
    a3: (const struct GASString *)&v16,
    nArgs: v10,
    firstArgBottomIndex: v13);
  v11 = v16;
  v3 = (*((_DWORD *)v16 + 2))-- == 1;
  if ( v3 )
    GASStringNode::ReleaseNode(a1: (int)v11);
  for ( i = v17; i != 0; --i )
  {
    GASValue::~GASValue(this: *(GASValue **)v7, a2: i);
    *(_DWORD *)v7 -= 16;
    if ( *(_DWORD *)v7 < *(_DWORD *)(v7 + 4) )
      GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9E30
// Name: public: virtual void GFxEditTextCharacter::ReplaceTextA(wchar_t const __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::ReplaceTextA(
        tagAXISINFOA *result,
        GMemoryHeap *pstr,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v6; // ecx
  int v7; // eax
  unsigned int Length; // edi

  v6 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)result + 47);
  if ( v6[23].Data.Policy.Capacity != 0 )
  {
    GFxTextDocView::ReplaceTextA(this: v6, pstr);
    v7 = *((_DWORD *)result + 47);
    if ( *(_DWORD *)(v7 + 284) != 0 )
    {
      Length = GFxStyledText::GetLength(this: *(GFxStyledText **)(v7 + 8));
      if ( GFILEFile::GetErrorCode(this: *(CVTFTexture **)(*((_DWORD *)result + 47) + 284)) > Length )
        GFxTextEditorKit::SetCursorPos(
          this: *(GFxTextEditorKit **)(*((_DWORD *)result + 47) + 284),
          textPos: Length,
          selectionAllowed: false);
    }
    GFxEditTextCharacter::UpdateVariable(this: (GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **)result);
    GFxEditTextCharacter::NotifyChanged(result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9EC0
// Name: public: virtual void GFxEditTextCharacter::CommitCompositionString(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::CommitCompositionString(tagAXISINFOA *result, wchar_t *pwch, unsigned int a3)
{
  int v4; // eax
  int v5; // esi
  unsigned int Length; // eax
  int v7; // eax
  unsigned int v8; // eax
  int v9; // edx
  int v10; // ebx
  int v11; // ebx
  unsigned int v12; // ebx

  v4 = *(_DWORD *)(*((_DWORD *)result + 47) + 284);
  if ( v4 == 0 )
    return;
  v5 = *(_DWORD *)(v4 + 20);
  if ( v5 == 0 )
    return;
  ++*(_DWORD *)(v5 + 4);
  if ( pwch != nullptr )
  {
    if ( a3 != -1 )
      goto LABEL_8;
    Length = G_wcslen(pwch);
  }
  else
  {
    pwch = *(wchar_t **)(v5 + 20);
    Length = GFxTextParagraph::GetLength(this: (GFxResourceId *)(v5 + 20));
  }
  a3 = Length;
LABEL_8:
  v7 = *((_DWORD *)result + 47);
  if ( *(_DWORD *)(v7 + 272) != 0 )
  {
    v8 = GFxStyledText::GetLength(this: *(GFxStyledText **)(v7 + 8));
    v9 = *((_DWORD *)result + 47);
    if ( a3 + v8 > *(_DWORD *)(v9 + 272) )
    {
      v10 = *(_DWORD *)(v9 + 272);
      a3 = v10 - GFxStyledText::GetLength(this: *(GFxStyledText **)(v9 + 8));
    }
  }
  v11 = *(_DWORD *)(v5 + 48);
  if ( v11 != GFILEFile::GetErrorCode(this: *(CVTFTexture **)(*((_DWORD *)result + 47) + 284)) )
  {
    GFILEFile::GetErrorCode(this: *(CVTFTexture **)(*((_DWORD *)result + 47) + 284));
    GFxTextCompositionString::SetPosition(this: (GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *)v5);
  }
  GFxStyledText::InsertString(
    this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(*((_DWORD *)result + 47) + 8),
    pstr: (const GFxValue *)pwch);
  GFxTextCompositionString::SetText(this: (GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *)v5);
  v12 = a3 + *(_DWORD *)(v5 + 48);
  GFxTextCompositionString::SetPosition(this: (GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *)v5);
  GFxTextEditorKit::SetCursorPos(
    this: *(GFxTextEditorKit **)(*((_DWORD *)result + 47) + 284),
    textPos: v12,
    selectionAllowed: false);
  GFxEditTextCharacter::UpdateVariable(this: (GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **)result);
  GFxEditTextCharacter::NotifyChanged(result);
  GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v5);
}

//------------------------------------------------------------------------------
// Address: 0x100EA000
// Name: public: GASTextFieldProto::GASTextFieldProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASTextFieldProto *__thiscall GASTextFieldProto::GASTextFieldProto(
        GASTextFieldProto *this,
        IVguiMatInfo *result,
        CTSQueue<CFunctor *,0,1>::Node_t *a3,
        const struct GASFunctionRef *a4)
{
  char *v5; // edi
  IVguiMatInfo_vtbl *v6; // ecx
  int v7; // eax
  bool v8; // zf
  IVguiMatInfo_vtbl *v9; // eax
  int v10; // eax
  IVguiMatInfo_vtbl *v11; // eax
  int v12; // eax
  IVguiMatInfo_vtbl *v13; // eax
  int v14; // eax
  IVguiMatInfo_vtbl *v15; // eax
  int v16; // eax
  IVguiMatInfo_vtbl *v17; // eax
  int v18; // eax
  IVguiMatInfo_vtbl *v19; // eax
  int v20; // eax
  IVguiMatInfo_vtbl *v21; // eax
  int v22; // eax
  IVguiMatInfo_vtbl *v23; // eax
  int v24; // eax
  IVguiMatInfo_vtbl *v25; // eax
  int v26; // eax
  IVguiMatInfo_vtbl *v27; // eax
  int v28; // eax
  IVguiMatInfo_vtbl *v29; // eax
  int v30; // eax
  IVguiMatInfo_vtbl *v31; // eax
  int v32; // eax
  IVguiMatInfo_vtbl *v33; // eax
  int v34; // eax
  IVguiMatInfo_vtbl *v35; // eax
  int v36; // eax
  IVguiMatInfo_vtbl *v37; // eax
  int v38; // eax
  IVguiMatInfo_vtbl *v39; // eax
  int v40; // eax
  IVguiMatInfo_vtbl *v41; // eax
  int v42; // eax
  IVguiMatInfo_vtbl *v43; // eax
  int v44; // eax
  IVguiMatInfo_vtbl *v45; // eax
  int v46; // eax
  IVguiMatInfo_vtbl *v47; // eax
  int v48; // eax
  IVguiMatInfo_vtbl *v49; // eax
  int v50; // eax
  IVguiMatInfo_vtbl *v51; // eax
  int v52; // eax
  IVguiMatInfo_vtbl *v53; // eax
  int v54; // eax
  IVguiMatInfo_vtbl *v55; // eax
  int v56; // eax
  IVguiMatInfo_vtbl *v57; // eax
  int v58; // eax
  IVguiMatInfo_vtbl *v59; // eax
  int v60; // eax
  IVguiMatInfo_vtbl *v61; // eax
  int v62; // eax
  IVguiMatInfo_vtbl *v63; // eax
  int v64; // eax
  IVguiMatInfo_vtbl *v65; // eax
  int v66; // eax
  IVguiMatInfo_vtbl *v67; // eax
  int v68; // eax
  _DWORD *x; // esi
  const GPtr<GFxAmpMemFragReport> *DefaultStyles; // eax
  GPtr<GFxAmpMemFragReport> *v71; // ecx
  const GPtr<GFxAmpMemFragReport> *v72; // edi
  GPtr<GFxAmpMemFragReport> *v73; // eax
  int v74; // eax
  tagMSG v76; // [esp-8h] [ebp-88h] BYREF
  struct GASObjectInterface *v77; // [esp+14h] [ebp-6Ch]
  struct GASStringNode *ConstStringNode; // [esp+20h] [ebp-60h] BYREF
  char v79; // [esp+27h] [ebp-59h] BYREF
  _BYTE v80[84]; // [esp+28h] [ebp-58h] BYREF

  v76.pt.x = (int)this;
  GASPrototype<GASTextFieldObject,GASEnvironment>::GASPrototype<GASTextFieldObject,GASEnvironment>(
    (int)this,
    result,
    psc_4: a3,
    psc_8: (unsigned int)a4);
  v5 = (char *)this + 16;
  v76.message = (unsigned int)this + 16;
  v76.hwnd = (HWND__ *)result;
  *(_DWORD *)this = &GASPrototype<GASTextFieldObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASTextFieldObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 15) = &GASPrototype<GASTextFieldObject,GASEnvironment>::`vftable';
  GASAsBroadcaster::InitializeProto(pobj: v76, a2: v77);
  v79 = 1;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)(v76.pt.x + 60),
    a2: (struct GASObject *)v76.pt.x,
    a3: (struct GASStringContext *)result,
    a4: (const struct GASNameFunction *)&GAS_TextFieldFunctionTable,
    a5: (const struct GASPropFlags *)&v79);
  v6 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v6[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"scroll",
                      a3: 6u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v7 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v7);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v9 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v9[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E314,
                      a3: 7u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v10 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v10);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v11 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v11[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&unk_1029E300,
                      a3: 9u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v12 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v12);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v13 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v13[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E2E8.m_Size,
                      a3: 0xAu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v14 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v14);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v15 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v15[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E2E8,
                      a3: 0xAu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v16 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v16);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v17 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v17[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"backgroundColor",
                      a3: 0xFu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v18 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v18);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v19 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v19[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E344.m_Size,
                      a3: 6u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v20 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v20);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v21 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v21[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"borderColor",
                      a3: 0xBu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v22 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v22);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v23 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v23[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E2B4.m_Memory.m_nGrowSize,
                      a3: 0xCu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v24 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v24);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v25 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v25[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E278.m_Size,
                      a3: 0x11u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v26 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v26);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v27 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v27[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E314.m_Memory.m_nGrowSize,
                      a3: 0xDu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v28 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v28);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v29 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v29[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E364.m_Size,
                      a3: 8u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v30 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v30);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v31 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v31[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E298,
                      a3: 0xDu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v32 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v32);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v33 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v33[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E32C,
                      a3: 0xAu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v34 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v34);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v35 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v35[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E37C.m_Size,
                      a3: 4u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v36 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v36);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v37 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v37[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_10299FCC.m_Memory.m_nGrowSize,
                      a3: 8u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v38 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v38);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v39 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v39[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E390,
                      a3: 6u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v40 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v40);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v41 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v41[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E298.m_pElements,
                      a3: 8u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v42 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v42);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v43 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v43[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&unk_1029E358,
                      a3: 9u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v44 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v44);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v45 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v45[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E278,
                      a3: 8u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v46 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v46);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v47 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 1;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v47[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E08C.m_Size,
                      a3: 8u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v48 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v48);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v49 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v49[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E32C.m_Size,
                      a3: 0xAu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v50 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v50);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v51 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v51[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E37C,
                      a3: 0xAu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v52 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v52);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v53 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v53[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E410,
                      a3: 8u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v54 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v54);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v55 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v55[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_10299FCC,
                      a3: 4u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v56 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v56);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v57 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v57[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E390.m_Memory.m_nGrowSize,
                      a3: 9u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v58 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v58);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v59 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v59[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E3A4,
                      a3: 0xAu,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v60 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v60);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v61 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v61[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E3A4.m_Size,
                      a3: 9u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v62 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v62);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v63 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v63[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E2B4,
                      a3: 4u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v64 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v64);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v65 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v65[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E344,
                      a3: 8u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v66 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v66);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  v67 = result->__vftable;
  v79 = 2;
  LOBYTE(v76.pt.y) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v67[79].GetNumAnimationFrames,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E364,
                      a3: 8u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, IVguiMatInfo *, struct GASStringNode **, int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: result,
    a3: &ConstStringNode,
    a4: &v76.pt.y,
    a5: &v79);
  v68 = (int)ConstStringNode;
  v8 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v68);
  GASValue::~GASValue(this: (GASValue *)&v76.pt.y, a2: (int)v5);
  x = (_DWORD *)v76.pt.x;
  v79 = 1;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)(v76.pt.x + 60),
    a2: (struct GASObject *)v76.pt.x,
    a3: (struct GASStringContext *)result,
    a4: (const struct GASNameFunction *)&GAS_TextFieldExtFunctionTable,
    a5: (const struct GASPropFlags *)&v79);
  DefaultStyles = (const GPtr<GFxAmpMemFragReport> *)GFxTextCompositionString::GetDefaultStyles(a1: v80);
  v71 = *(GPtr<GFxAmpMemFragReport> **)(v76.pt.x + 56);
  v72 = DefaultStyles;
  if ( v71 != nullptr )
  {
    GFxTextIMEStyle::GFxTextIMEStyle(this: v71, __that: DefaultStyles);
  }
  else
  {
    v76.pt.x = 326;
    v73 = (GPtr<GFxAmpMemFragReport> *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                         this: GMemory::pGlobalHeap,
                                         a2: x,
                                         a3: 84,
                                         a4: &v76.pt);
    if ( v73 != nullptr )
    {
      GFxTextIMEStyle::GFxTextIMEStyle(this: v73, __that: v72);
      x[14] = v74;
    }
    else
    {
      x[14] = 0;
    }
  }
  return (GASTextFieldProto *)x;
}

//------------------------------------------------------------------------------
// Address: 0x100EAC60
// Name: public: virtual void GFxEditTextCharacter::TextDocumentListener::Editor_OnChanged(class GFxTextEditorKit __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::TextDocumentListener::Editor_OnChanged(
        GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **this,
        struct GFxTextEditorKit *a2)
{
  tagAXISINFOA *v2; // esi

  v2 = (tagAXISINFOA *)(this - 61);
  GFxEditTextCharacter::UpdateVariable(this: this - 61);
  GFxEditTextCharacter::NotifyChanged(result: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100EAC80
// Name: public: GArrayDH<struct GFxStyledText::HTMLImageTagInfo,2,struct GArrayDefaultPolicy>::~GArrayDH<struct GFxStyledText::HTMLImageTagInfo,2,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayDH<GFxStyledText::HTMLImageTagInfo,2,GArrayDefaultPolicy>::~GArrayDH<GFxStyledText::HTMLImageTagInfo,2,GArrayDefaultPolicy>(
        int *this)
{
  GConstructorMov<GFxStyledText::HTMLImageTagInfo>::DestructArray(a1: *this, a2: *(this + 1));
  return ((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: *this);
}

//------------------------------------------------------------------------------
// Address: 0x100EACB0
// Name: public: static void GFxEditTextCharacter::AppendHtml(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GFxEditTextCharacter::AppendHtml(GASFnCall *a1)
{
  GASFnCall *v1; // edi
  GASFnCall v2; // esi
  tagALTTABINFO *v3; // esi
  _DWORD *y; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v5; // ebx
  unsigned __int8 *v6; // eax
  GMemoryHeap *v7; // eax
  int v8; // eax
  GASFnCall *v9; // eax
  bool v10; // zf
  int v11[4]; // [esp+4h] [ebp-10h] BYREF

  v1 = a1;
  if ( a1[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a1[2]->cbSize + 8))(a1: a1[2]) == 4 )
  {
    v2 = v1[2];
    v3 = v2 != nullptr ? &v2[-3] : nullptr;
    y = (_DWORD *)v3[5].ptStart.y;
    if ( (y == nullptr || *y == 0) && (int)v1[7] >= 1 )
    {
      v5 = (tagRID_DEVICE_INFO_KEYBOARD *)v1[6];
      v6 = (unsigned __int8 *)GASFnCall::Arg(this: v1, a2: 0);
      GASValue::ToStringImpl(this: v6, a2: (int *)&a1, a3: v5, precision: -1, debug: false);
      v7 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v3);
      memset(v11, 0, 12);
      v11[3] = (int)v7;
      GFxTextDocView::AppendHtml(result: (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)*a1);
      v8 = (*(int (__thiscall **)(tagALTTABINFO *))(v3->cbSize + 84))(a1: v3);
      if ( v8 != 0 )
        *(_DWORD *)(v8 + 9332) |= 0x400u;
      GArrayDH<GFxStyledText::HTMLImageTagInfo,2,GArrayDefaultPolicy>::~GArrayDH<GFxStyledText::HTMLImageTagInfo,2,GArrayDefaultPolicy>(this: v11);
      v9 = a1;
      v10 = a1[2] == (GASFnCall)1;
      a1[2] = (GASFnCall)((char *)a1[2] - 1);
      if ( v10 )
        GASStringNode::ReleaseNode(a1: (int)v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EADA0
// Name: protected: void GFxTextClipboard::SetStyledText(class GFxStyledText __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextClipboard::SetStyledText(
        CBaseAutoPtr<IMatRenderContext> *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        GFxStyledText *a4)
{
  GRefCountNTSImpl *v4; // ecx
  CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *v5; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  GStringDH *v7; // eax
  GFxValue *v8; // edi
  int (__thiscall *v9)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *); // edx
  CUtlMemory<GFxValue,int> *v10; // eax
  SFTextObjectImpl *v11; // eax
  CBaseAutoPtr<IMatRenderContext> *v13; // [esp+0h] [ebp-8h]
  int v14; // [esp+4h] [ebp-4h] BYREF

  v13 = this;
  v4 = *((GRefCountNTSImpl **)this + 7);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  v5 = (CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *)GMemory::pGlobalHeap;
  Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
  v14 = 324;
  v7 = (GStringDH *)((int (__thiscall *)(GMemoryHeap *, int, int *, int, int))Alloc_2)(
                      a1: GMemory::pGlobalHeap,
                      a2: 80,
                      a3: &v14,
                      a4: a2,
                      a5: a3);
  if ( v7 != nullptr )
    v8 = (GFxValue *)GFxTextAllocator::GFxTextAllocator(this: v7, result: v5, flags: 1u);
  else
    v8 = nullptr;
  v9 = *(int (__thiscall **)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *))(LODWORD(v5->m_pfnProxied) + 40);
  v14 = 324;
  v10 = (CUtlMemory<GFxValue,int> *)v9(a1: v5, a2: 36, a3: &v14);
  if ( v10 != nullptr )
    GFxStyledText::GFxStyledText(this: v10, pallocator: v8, a3: (int)v13);
  else
    v11 = nullptr;
  v13[7].m_pObject = (IMatRenderContext *)v11;
  GFxStyledText::CopyStyledText(this: a4, a2: v11, indexInPara: 0, a4: 0xFFFFFFFF);
  if ( v8 != nullptr )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x100EAE40
// Name: public: void GFxTextClipboard::SetTextAndStyledText(wchar_t const __near *,unsigned int,class GFxStyledText __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextClipboard::SetTextAndStyledText(
        CBaseAutoPtr<IMatRenderContext> *this,
        IMatRenderContext *result,
        unsigned int a3,
        GFxStyledText *a4)
{
  GRefCountNTSImpl *v5; // ecx
  const wchar_t *v6; // edi

  v5 = *((GRefCountNTSImpl **)this + 7);
  if ( v5 != nullptr )
  {
    GRefCountNTSImpl::Release(this: v5);
    *((_DWORD *)this + 7) = 0;
  }
  GFxWStringBuffer::SetString(this: (GFxWStringBuffer *)(this + 3), pwch: (const wchar_t *)result, a3);
  v6 = *((const wchar_t **)this + 3);
  if ( v6 == nullptr )
    v6 = &word_1028F3E0;
  ((void (__thiscall *)(CBaseAutoPtr<IMatRenderContext> *, const wchar_t *, _DWORD))this->m_pObject[1].__vftable)(
    a1: this,
    a2: v6,
    a3: *((_DWORD *)this + 4));
  GFxTextClipboard::SetStyledText(this, a2: (int)v6, a3: (int)this, a4);
}

//------------------------------------------------------------------------------
// Address: 0x100EB010
// Name: public: struct GFxTextDocView::ImageSubstitutor __near * GFxTextDocView::CreateImageSubstitutor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::CreateImageSubstitutor(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this)
{
  _DWORD *v2; // eax
  int v3; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 6) == 0 )
  {
    v3 = 324;
    v2 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 12, a3: &v3);
    if ( v2 != nullptr )
    {
      *v2 = 0;
      v2[1] = 0;
      v2[2] = 0;
      *((_DWORD *)this + 6) = v2;
    }
    else
    {
      *((_DWORD *)this + 6) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB070
// Name: public: void GFxTextDocView::ClearImageSubstitutor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::ClearImageSubstitutor(GFxTextDocView *this)
{
  void *v2; // esi

  v2 = *((void **)this + 6);
  if ( v2 != nullptr )
  {
    GArrayDataBase<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>::~GArrayDataBase<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>(this: *((_DWORD **)this + 6));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
  }
  *((_DWORD *)this + 6) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EB0A0
// Name: public: static void GFxEditTextCharacter::UpdateImageSubstitution(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::UpdateImageSubstitution(int a1@<ebx>, GString *a2)
{
  GString *v2; // esi
  int pData; // edi
  GString::DataDesc *v4; // edi
  int v5; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v6; // ebx
  unsigned __int8 *v7; // eax
  void **v8; // ebx
  void *v9; // ebx
  struct GASValue *v10; // eax
  GASValue *v11; // eax
  struct GASObject *v12; // eax
  struct GASObject *v13; // ebx
  int v14; // ecx
  int (__thiscall *v15)(int, int, GString *); // edx
  struct GFxImageResource *sequence; // ebx
  int v17; // eax
  IClientUnknown *v18; // esi
  GFxShapeBase *v19; // ecx
  GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *v20; // eax
  const struct GASFnCall *v21; // eax
  const struct GASEnvironment *v23; // [esp-8h] [ebp-18h]
  void *v25; // [esp+8h] [ebp-8h]
  GString v26; // [esp+Ch] [ebp-4h] BYREF

  v2 = a2;
  pData = (int)a2[1].pData;
  GASValue::DropRefs(this: (GASValue *)pData, a2: pData);
  *(_BYTE *)pData = 2;
  *(_BYTE *)(pData + 4) = 0;
  if ( v2[2].HeapTypeBits != 0
    && (*(int (__thiscall **)(unsigned int))(v2[2].pData->Size + 8))(a1: v2[2].HeapTypeBits) == 4 )
  {
    v4 = v2[2].pData;
    v5 = v4 != nullptr ? (int)&v4[-10] : 0;
    if ( (int)v2[7].pData >= 1 )
    {
      v6 = (tagRID_DEVICE_INFO_KEYBOARD *)v2[6].pData;
      v7 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 0);
      GASValue::ToStringImpl(this: v7, (int *)&a2, a3: v6, precision: -1, debug: false);
      if ( *(_DWORD *)(v5 + 272) != 0 )
      {
        GString::GString(this: &v26, src: a2->HeapTypeBits);
        v8 = (void **)GStringHashLH<GPtr<GFxTextImageDesc>,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF>>::Get(
                        this: *(int **)(v5 + 272),
                        a2: &v26);
        GString::~GString(this: &v26);
        if ( v8 != nullptr )
        {
          v9 = *v8;
          v25 = v9;
          if ( (int)v2[7].pData >= 2 )
          {
            if ( *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 1) == 1
              || (v10 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 1),
                  LOBYTE(GASValue::IsUndefined(this: v10).usPreferredNode) != 0) )
            {
              GFxTextDocView::CreateImageSubstitutor(this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v5 + 188));
              if ( v20 != nullptr )
              {
                GFxTextDocView::ImageSubstitutor::RemoveImageDesc(this: v20, pimgDesc: v9, n: a1);
                *(_BYTE *)(*(_DWORD *)(v5 + 188) + 336) |= 2u;
                GFxEditTextCharacter::RemoveIdImageDescAssoc(this: (int **)v5, a2: (GString)a2->pData);
                GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v5);
              }
            }
            else
            {
              v23 = (const struct GASEnvironment *)v2[6].pData;
              v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 1);
              v12 = GASValue::ToObject(this: v11, a2: v5, a3: v23);
              v13 = v12;
              if ( v12 != nullptr && ((int (__thiscall *)(struct GASObject *))v12[2].pNode[1].pNext)(a1: &v12[2]) == 26 )
              {
                v14 = *(_DWORD *)(*(_DWORD *)(v2[6].HeapTypeBits + 120) + 656);
                v15 = *(int (__thiscall **)(int, int, GString *))(*(_DWORD *)v14 + 40);
                sequence = (struct GFxImageResource *)v13[6].sequence;
                v26.pData = (GString::DataDesc *)258;
                v17 = v15(a1: v14, a2: 124, a3: &v26);
                if ( v17 != 0 )
                  v18 = GFxShapeWithStyles::GFxShapeWithStyles(this: v17, result: (IClientUnknown *)0x1FF8);
                else
                  v18 = nullptr;
                GFxShapeWithStyles::SetToImage(this: (GFxShapeWithStyles *)v18, bilinear: sequence, a3: true);
                if ( v18 != nullptr )
                  GFxShapeBase::AddRef(this: (GFxShapeBase *)v18);
                v19 = *((GFxShapeBase **)v25 + 2);
                if ( v19 != nullptr )
                  GFxShapeBase::Release(this: v19);
                *((_DWORD *)v25 + 2) = v18;
                GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v5);
                if ( v18 != nullptr )
                  GFxShapeBase::Release(this: (GFxShapeBase *)v18);
              }
            }
          }
        }
      }
      v21 = (const struct GASFnCall *)a2;
      if ( a2[2].HeapTypeBits-- == 1 )
        GASStringNode::ReleaseNode(a1: (int)v21);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB330
// Name: public: static void GASTextFieldCtorFunction::GetFontList(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASTextFieldCtorFunction::GetFontList(GASEnvironment **a1)
{
  GASEnvironment **v1; // ebx
  struct GFxMovieRoot *MovieRoot; // esi
  int v3; // eax
  IShaderAPI *v4; // eax
  int v5; // edi
  IShaderAPI *v6; // eax
  IShaderAPI *v7; // esi
  int v8; // ecx
  int (__thiscall *v9)(int, int, struct GASObject **); // edx
  GASEnvironment ***v10; // ecx
  unsigned int v11; // eax
  _DWORD *v12; // ecx
  int v13; // edi
  signed int v14; // esi
  int v15; // ecx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *StringNode; // eax
  bool v17; // zf
  unsigned int v18; // eax
  _DWORD *v19; // ecx
  struct GASObject *v20; // esi
  GMemoryHeap *v21; // [esp+0h] [ebp-28h]
  const char *v22; // [esp+4h] [ebp-24h]
  int v23; // [esp+8h] [ebp-20h]
  GASValue v24[4]; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD v25[2]; // [esp+1Ch] [ebp-Ch] BYREF
  struct GASObject *v26; // [esp+24h] [ebp-4h] BYREF

  v1 = a1;
  MovieRoot = GASEnvironment::GetMovieRoot(this: a1[6]);
  v3 = (*(int (__thiscall **)(struct GFxMovieRoot *))(*(_DWORD *)MovieRoot + 4))(a1: MovieRoot);
  v25[1] = &a1;
  a1 = nullptr;
  v25[0] = &`GASTextFieldCtorFunction::GetFontList'::`2'::FontsVisitor::`vftable';
  (*(void (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)v3 + 104))(a1: v3, a2: v25, a3: 1);
  v4 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(a1: (int)MovieRoot + 8, a2: 19);
  v5 = (int)v4;
  if ( v4 != nullptr )
  {
    GRefCountImpl::Release(this: v4);
    GFxFontLib::LoadFontNames(a1: v5, a2: (int)MovieRoot, a3: (int *)&a1);
  }
  v6 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(a1: (int)MovieRoot + 8, a2: 20);
  v7 = v6;
  if ( v6 != nullptr )
  {
    GRefCountImpl::Release(this: v6);
    ((void (__thiscall *)(IShaderAPI *, GASEnvironment ***))v7->GetSceneFogMode)(a1: v7, a2: &a1);
  }
  v8 = *(_DWORD *)(*((_DWORD *)v1[6] + 30) + 656);
  v9 = *(int (__thiscall **)(int, int, struct GASObject **))(*(_DWORD *)v8 + 40);
  v26 = (struct GASObject *)323;
  if ( v9(a1: v8, a2: 76, a3: &v26) != 0 )
    v26 = (struct GASObject *)GASArrayObject::GASArrayObject(penv: (unsigned int)v1[6], a2: v21, a3: v22, a4: v23);
  else
    v26 = nullptr;
  v10 = (GASEnvironment ***)a1;
  if ( a1 != nullptr )
  {
    v11 = 0;
    v12 = a1 + 2;
    do
    {
      if ( *v12 != -2 )
        break;
      ++v11;
      v12 += 4;
    }
    while ( v11 <= (unsigned int)a1[1] );
    v10 = &a1;
  }
  else
  {
    v11 = 0;
  }
  v13 = (int)v10;
  v14 = v11;
  while ( v13 != 0 )
  {
    v15 = *(_DWORD *)v13;
    if ( *(_DWORD *)v13 == 0 || v14 > *(_DWORD *)(v15 + 4) )
      break;
    StringNode = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)GASStringManager::CreateStringNode(
                                                                                              this: *(GASStringManager **)(*((_DWORD *)v1[6] + 30) + 636),
                                                                                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*(_DWORD *)(v15 + 16 * (v14 + 1)) & 0xFFFFFFFC) + 8),
                                                                                              length: *(_DWORD *)(*(_DWORD *)(v15 + 16 * (v14 + 1)) & 0xFFFFFFFC)
                                                                                            & 0x7FFFFFFF);
    ++StringNode->m_nGrowSize;
    LOBYTE(v24[0]) = 5;
    v24[1] = StringNode;
    v17 = ++StringNode->m_nGrowSize == 1;
    --StringNode->m_nGrowSize;
    if ( v17 )
      GASStringNode::ReleaseNode(a1: (int)StringNode);
    GASArrayObject::PushBack(this: (GASArrayObject *)v26, a2: (const struct GASValue *)v24);
    GASValue::~GASValue(this: v24, a2: v13);
    v18 = *(_DWORD *)(*(_DWORD *)v13 + 4);
    if ( v14 <= (int)v18 && ++v14 <= v18 )
    {
      v19 = (_DWORD *)(*(_DWORD *)v13 + 16 * v14 + 8);
      do
      {
        if ( *v19 != -2 )
          break;
        ++v14;
        v19 += 4;
      }
      while ( v14 <= v18 );
    }
  }
  v20 = v26;
  GASValue::SetAsObject(this: (GASValue *)v1[1], a2: v26);
  if ( v20 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v20, a2: v13);
  v25[0] = &GString::InitStruct::`vftable';
  GHashSetBase<GHashNode<GString,GString,GString::NoCaseHashFunctor>,GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GString,2>,GHashsetCachedNodeEntry<GHashNode<GString,GString,GString::NoCaseHashFunctor>,GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeHashF>>::Clear(this: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x100EB510
// Name: public: void GFxEditTextCharacter::ClearIdImageDescAssoc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::ClearIdImageDescAssoc(GFxEditTextCharacter *this)
{
  void *v2; // esi

  v2 = *((void **)this + 68);
  if ( v2 != nullptr )
  {
    GHashSetBase<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GPtr<GFxTextImageDesc>,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF>>::Clear(this: *((_DWORD **)this + 68));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
  }
  *((_DWORD *)this + 68) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EB540
// Name: public: void GFxEditTextCharacter::AddIdImageDescAssoc(char const __near *,struct GFxTextImageDesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::AddIdImageDescAssoc(int **this, char *a2, GString a3)
{
  int *v4; // eax
  GRefCountNTSImpl *pData; // eax
  int *v6; // ecx
  void *v7; // esi
  _DWORD v8[2]; // [esp+4h] [ebp-10h] BYREF
  int v9; // [esp+Ch] [ebp-8h] BYREF
  GRefCountNTSImpl *v10; // [esp+10h] [ebp-4h] BYREF

  if ( *(this + 68) == nullptr )
  {
    v9 = 2;
    v4 = (int *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 4, a4: &v9);
    if ( v4 != nullptr )
      *v4 = 0;
    else
      v4 = nullptr;
    *(this + 68) = v4;
  }
  pData = (GRefCountNTSImpl *)a3.pData;
  if ( a3.pData != nullptr )
    ++a3.pData->RefCount;
  v10 = pData;
  GString::GString(this: &a3, src: (int)a2);
  v6 = *(this + 68);
  v8[0] = &a3;
  v8[1] = &v10;
  GHashSetBase<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GPtr<GFxTextImageDesc>,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF>>::Set<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeRef>(
    this: v6,
    a2: v6,
    a3: (int)v8);
  v7 = (void *)(a3.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a3.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  if ( v10 != nullptr )
    GRefCountNTSImpl::Release(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x100EB5F0
// Name: private: void GFxEditTextCharacter::ProceedImageSubstitution(class GASFnCall const __near &,int,class GASValue const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxEditTextCharacter::ProceedImageSubstitution(
        GFxEditTextCharacter *this@<ecx>,
        int a2@<ebx>,
        const struct GASEnvironment **a3,
        int a4,
        GASValue *a5)
{
  GFxEditTextCharacter *v5; // edi
  struct GASObject *v6; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v7; // ecx
  struct GASObject *v8; // ebx
  GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *v9; // eax
  GASObjectInterface *v10; // ebx
  unsigned int v11; // eax
  int v12; // eax
  GFxShapeWithStyles *v13; // eax
  bool v14; // zf
  GFxShapeWithStyles *v15; // eax
  const struct GASEnvironment *v16; // eax
  struct GASObject *v17; // eax
  int v18; // eax
  int v19; // ecx
  int (__thiscall *v20)(int, int, signed int *, int); // edx
  int v21; // eax
  long double v22; // st7
  int v23; // eax
  int v24; // eax
  double v25; // st7
  const struct GASEnvironment *v26; // eax
  int v27; // eax
  char *v28; // ecx
  int v29; // ecx
  int (__thiscall *v30)(int, int, char *); // edx
  CBaseResourcePrecacher *v31; // eax
  GRefCountNTSImpl *v32; // eax
  GRefCountNTSImpl *v33; // esi
  GFxShapeBase *v34; // ebx
  GFxShapeBase *v35; // ecx
  double v36; // st7
  GRefCountNTSImpl_vtbl *v37; // eax
  double v38; // st7
  volatile int v39; // eax
  double v40; // st7
  GRefCountNTSImpl *v41; // eax
  GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *v42; // ecx
  float *v43; // eax
  double v44; // st7
  double v45; // st7
  int v46; // eax
  struct GASStringContext *v47; // [esp-10h] [ebp-9Ch]
  const char *v48; // [esp-10h] [ebp-9Ch]
  int v49; // [esp-Ch] [ebp-98h]
  int v50; // [esp-8h] [ebp-94h]
  IResourcePrecacher v52; // [esp+8h] [ebp-84h] BYREF
  int v53; // [esp+Ch] [ebp-80h]
  int v54; // [esp+10h] [ebp-7Ch]
  int v55; // [esp+14h] [ebp-78h]
  GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *v56; // [esp+18h] [ebp-74h]
  char *v57; // [esp+1Ch] [ebp-70h]
  float v58; // [esp+20h] [ebp-6Ch]
  float v59; // [esp+24h] [ebp-68h] BYREF
  float v60; // [esp+28h] [ebp-64h]
  float v61; // [esp+2Ch] [ebp-60h]
  GASValue v62[4]; // [esp+30h] [ebp-5Ch] BYREF
  __int64 v63; // [esp+40h] [ebp-4Ch] BYREF
  int v64; // [esp+48h] [ebp-44h]
  signed int v65; // [esp+4Ch] [ebp-40h] BYREF
  struct GFxImageResource *v66; // [esp+50h] [ebp-3Ch]
  GFxShapeWithStyles *v67; // [esp+54h] [ebp-38h] BYREF
  GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > elem; // [esp+58h] [ebp-34h] BYREF
  GRefCountNTSImpl *v69; // [esp+80h] [ebp-Ch]
  char v70; // [esp+84h] [ebp-8h]

  v5 = this;
  if ( a5 != nullptr && *(_BYTE *)a5 == 6 )
  {
    v6 = GASValue::ToObject(this: a5, a2: (int)this, a3: a3[6]);
    v7 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)v5 + 47);
    v8 = v6;
    LOBYTE(v62[0]) = 0;
    GFxTextDocView::CreateImageSubstitutor(this: v7);
    v56 = v9;
    if ( v9 == nullptr )
    {
LABEL_62:
      GASValue::~GASValue(this: v62, a2: (int)v5);
      return;
    }
    v10 = (GASObjectInterface *)&v8[2];
    v47 = (const struct GASEnvironment *)((char *)a3[6] + 120);
    v69 = nullptr;
    if ( GASObjectInterface::GetConstMemberRaw(
           this: v10,
           psc: v47,
           psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"subString",
           psc_8: (struct GASValue *)v62) != 0 )
    {
      GASValue::ToStringImpl(
        this: (unsigned __int8 *)v62,
        a2: (int *)&v67,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)a3[6],
        precision: -1,
        debug: false);
      *(float *)&v11 = COERCE_FLOAT(GASString::GetLength(this: (const char ***)&v67));
      v64 = v11;
      if ( v11 >= 0x13 )
      {
        v64 = 19;
        v11 = 19;
      }
      GUTF8Util::DecodeString(
        pbegin: (wchar_t *)&elem,
        putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)v67->m_TotalLen,
        length: v11 + 1);
      v70 = v64;
      if ( (unsigned __int8)v64 > 0xFu )
      {
        v12 = *((_DWORD *)v5 + 37);
        if ( v12 == 0 )
        {
          GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v5);
          if ( v12 == 0 )
            v12 = *(_DWORD *)((*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)v5 + 108))(a1: v5) + 120);
        }
        v5 = (GFxEditTextCharacter *)((char *)v5 + 12);
        GFxLogBase<GFxCharacter>::LogScriptWarning(
          a1: (int)v5,
          a2: (int)"%s.setImageSubstitutions() failed for #%d element - length of subString should not exceed 15 characters\n",
          **(const char ***)(v12 + 8),
          a4);
        v13 = v67;
        v14 = (*(_DWORD *)v67->m_Data)-- == 1;
        if ( v14 )
          GASStringNode::ReleaseNode(a1: (int)v13);
        goto LABEL_60;
      }
      v15 = v67;
      v14 = (*(_DWORD *)v67->m_Data)-- == 1;
      if ( v14 )
        GASStringNode::ReleaseNode(a1: (int)v15);
      v16 = a3[6];
      *(float *)&v64 = 0.0;
      v57 = nullptr;
      if ( GASObjectInterface::GetConstMemberRaw(
             this: v10,
             psc: (const struct GASEnvironment *)((char *)v16 + 120),
             psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"image",
             psc_8: (struct GASValue *)v62) != 0 )
      {
        *(float *)&v17 = COERCE_FLOAT(GASValue::ToObject(this: v62, a2: (int)v5, a3: a3[6]));
        v65 = (signed int)v17;
        if ( *(float *)&v17 != 0.0 && ((int (__thiscall *)(struct GASObject *))v17[2].pNode[1].pNext)(a1: &v17[2]) == 26 )
        {
          v18 = *((_DWORD *)a3[6] + 30);
          v66 = *(struct GFxImageResource **)(v65 + 52);
          v19 = *(_DWORD *)(v18 + 656);
          v20 = *(int (__thiscall **)(int, int, signed int *, int))(*(_DWORD *)v19 + 40);
          v65 = 258;
          v21 = v20(a1: v19, a2: 124, a3: &v65, a4: a2);
          if ( v21 != 0 )
            v67 = (GFxShapeWithStyles *)GFxShapeWithStyles::GFxShapeWithStyles(
                                          this: v21,
                                          result: (IClientUnknown *)0x1FF8);
          else
            v67 = nullptr;
          GFxShapeWithStyles::SetToImage(this: v67, bilinear: v66, a3: true);
          (*(void (__thiscall **)(_DWORD, IResourcePrecacher *))(**((_DWORD **)v66 + 3) + 28))(
            a1: *((_DWORD *)v66 + 3),
            a2: &v52);
          v65 = 20 * (v54 - (unsigned int)v52.__vftable);
          *(float *)&v65 = (float)v65;
          v60 = *(float *)&v65;
          v66 = (struct GFxImageResource *)(20 * (v55 - v53));
          *(float *)&v66 = (float)(int)v66;
          v58 = *(float *)&v66;
          v22 = 0.0;
          if ( 0.0 == *(float *)&v65 || *(float *)&v66 == 0.0 )
          {
            v24 = *((_DWORD *)v5 + 37);
            if ( v24 == 0 )
            {
              GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v5);
              if ( v24 == 0 )
                v24 = *(_DWORD *)((*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)v5 + 108))(a1: v5) + 120);
            }
            v5 = (GFxEditTextCharacter *)((char *)v5 + 12);
            GFxLogBase<GFxCharacter>::LogScriptWarning(
              a1: (int)v5,
              a2: (int)"%s.setImageSubstitutions() failed for #%d element - image has one zero dimension\n",
              **(const char ***)(v24 + 8),
              a4);
            if ( v67 != nullptr )
              GFxShapeBase::Release(this: (GFxShapeBase *)v67);
            goto LABEL_60;
          }
          if ( v67 != nullptr )
          {
            if ( GASObjectInterface::GetConstMemberRaw(
                   this: v10,
                   psc: (const struct GASEnvironment *)((char *)a3[6] + 120),
                   psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_pElements,
                   psc_8: (struct GASValue *)v62) != 0 )
            {
              v22 = GASValue::ToNumber(this: v62, a2: (int)v5, a3: 0.0, result: (_SERVICE_STATUS *)a3[6]) * 20.0;
              v60 = v22;
            }
            if ( GASObjectInterface::GetConstMemberRaw(
                   this: v10,
                   psc: (const struct GASEnvironment *)((char *)a3[6] + 120),
                   psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_Memory.m_nGrowSize,
                   psc_8: (struct GASValue *)v62) != 0 )
            {
              v22 = GASValue::ToNumber(this: v62, a2: (int)v5, a3: v22, result: (_SERVICE_STATUS *)a3[6]) * 20.0;
              v58 = v22;
            }
            if ( GASObjectInterface::GetConstMemberRaw(
                   this: v10,
                   psc: (const struct GASEnvironment *)((char *)a3[6] + 120),
                   psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"baseLineX",
                   psc_8: (struct GASValue *)v62) != 0 )
            {
              v22 = GASValue::ToNumber(this: v62, a2: (int)v5, a3: v22, result: (_SERVICE_STATUS *)a3[6]) * 20.0;
              *(float *)&v64 = v22;
            }
            if ( GASObjectInterface::GetConstMemberRaw(
                   this: v10,
                   psc: (const struct GASEnvironment *)((char *)a3[6] + 120),
                   psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"baseLineY",
                   psc_8: (struct GASValue *)v62) != 0 )
              v25 = GASValue::ToNumber(this: v62, a2: (int)v5, a3: v22, result: (_SERVICE_STATUS *)a3[6]) * 20.0;
            else
              v25 = *(float *)&v66 - 20.0;
            v26 = a3[6];
            v61 = v25;
            if ( GASObjectInterface::GetConstMemberRaw(
                   this: v10,
                   psc: (const struct GASEnvironment *)((char *)v26 + 120),
                   psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"id",
                   psc_8: (struct GASValue *)v62) != 0 )
            {
              GASValue::ToStringImpl(
                this: (unsigned __int8 *)v62,
                a2: (int *)&v59,
                a3: (tagRID_DEVICE_INFO_KEYBOARD *)a3[6],
                precision: -1,
                debug: false);
              v27 = LODWORD(v59);
              v28 = *(char **)LODWORD(v59);
              v14 = (*(_DWORD *)(LODWORD(v59) + 8))-- == 1;
              v57 = v28;
              if ( v14 )
                GASStringNode::ReleaseNode(a1: v27);
            }
            v29 = *(_DWORD *)(*((_DWORD *)a3[6] + 30) + 656);
            v30 = *(int (__thiscall **)(int, int, char *))(*(_DWORD *)v29 + 40);
            HIDWORD(v63) = 324;
            v31 = (CBaseResourcePrecacher *)v30(a1: v29, a2: 56, a3: (char *)&v63 + 4);
            if ( v31 != nullptr )
            {
              GFxTextImageDesc::GFxTextImageDesc(this: v31);
              v33 = v32;
            }
            else
            {
              v33 = nullptr;
            }
            if ( v69 != nullptr )
              GRefCountNTSImpl::Release(this: v69);
            v34 = (GFxShapeBase *)v67;
            v69 = v33;
            GFxShapeBase::AddRef(this: (GFxShapeBase *)v67);
            v35 = (GFxShapeBase *)v33[1].__vftable;
            if ( v35 != nullptr )
              GFxShapeBase::Release(this: v35);
            v36 = *(float *)&v64;
            v33[1].__vftable = (GRefCountNTSImpl_vtbl *)v34;
            v37 = (GRefCountNTSImpl_vtbl *)(int)v36;
            v38 = v61;
            v69[2].__vftable = v37;
            v39 = (int)v38;
            v40 = v60;
            v69[2].RefCount = v39;
            v69[3].__vftable = (GRefCountNTSImpl_vtbl *)(__int64)v40;
            v63 = (__int64)v58;
            v69[3].RefCount = v63;
            if ( v57 != nullptr )
              GFxEditTextCharacter::AddIdImageDescAssoc(this: (int **)v5, a2: v57, a3: (GString)v69);
            v41 = v69;
            v42 = v56;
            *(float *)&v69[5].__vftable = *(float *)&v69[5].__vftable - *(float *)&v64;
            *(float *)&v41[6].RefCount = *(float *)&v41[6].RefCount - v61;
            v43 = (float *)v69;
            *((float *)&v63 + 1) = v60 / *(float *)&v65;
            v59 = v58 / *(float *)&v66;
            v44 = *((float *)&v63 + 1);
            *(float *)&v69[4].__vftable = *((float *)&v63 + 1) * *(float *)&v69[4].__vftable;
            v43[9] = v43[9] * v44;
            v43[10] = v44 * v43[10];
            v45 = v59;
            v43[11] = v43[11] * v59;
            v43[12] = v43[12] * v45;
            v43[13] = v45 * v43[13];
            GFxTextDocView::ImageSubstitutor::AddImageDesc(this: v42, &elem);
            *(_BYTE *)(*((_DWORD *)v5 + 47) + 336) |= 2u;
            GFxEditTextCharacter::SetDirtyFlag(this: v5);
            GFxShapeBase::Release(this: v34);
            goto LABEL_60;
          }
        }
      }
      v23 = *((_DWORD *)v5 + 37);
      if ( v23 == 0 )
      {
        GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v5);
        if ( v23 == 0 )
          v23 = *(_DWORD *)((*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)v5 + 108))(a1: v5) + 120);
      }
      v50 = a4;
      v49 = **(_DWORD **)(v23 + 8);
      v48 = "%s.setImageSubstitutions() failed for #%d element - 'image' is not specified or not a BitmapData\n";
    }
    else
    {
      v46 = *((_DWORD *)v5 + 37);
      if ( v46 == 0 )
      {
        GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v5);
        if ( v46 == 0 )
          v46 = *(_DWORD *)((*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)v5 + 108))(a1: v5) + 120);
      }
      v50 = a4;
      v49 = **(_DWORD **)(v46 + 8);
      v48 = "%s.setImageSubstitutions() failed for #%d element - subString should be specified\n";
    }
    v5 = (GFxEditTextCharacter *)((char *)v5 + 12);
    GFxLogBase<GFxCharacter>::LogScriptWarning(a1: (int)v5, a2: (int)v48, v49, v50);
LABEL_60:
    if ( v69 != nullptr )
      GRefCountNTSImpl::Release(this: v69);
    goto LABEL_62;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EBBA0
// Name: public: static void GFxEditTextCharacter::SetImageSubstitutions(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GFxEditTextCharacter::SetImageSubstitutions(GASFnCall *a1)
{
  GASFnCall v2; // esi
  GASFnCall v3; // ebx
  int v4; // ebx
  GASValue *v5; // eax
  struct GASObject *v6; // eax
  int v7; // esi
  GASValue *v8; // eax
  int v9; // eax
  const struct GASEnvironment *v10; // [esp-8h] [ebp-14h]
  int v11; // [esp+8h] [ebp-4h]
  GASFnCall *v12; // [esp+14h] [ebp+8h]

  v2 = a1[1];
  GASValue::DropRefs(this: (GASValue *)v2, a2: (int)a1);
  LOBYTE(v2->cbSize) = 2;
  LOBYTE(v2->cItems) = 0;
  if ( a1[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a1[2]->cbSize + 8))(a1: a1[2]) == 4 )
  {
    v3 = a1[2];
    v4 = v3 != nullptr ? (int)&v3[-3] : 0;
    if ( (int)a1[7] >= 1 )
    {
      if ( *(_BYTE *)GASFnCall::Arg(this: a1, a2: 0) == 1 )
      {
        GFxEditTextCharacter::ClearIdImageDescAssoc(this: (GFxEditTextCharacter *)v4);
        GFxTextDocView::ClearImageSubstitutor(this: *(GFxTextDocView **)(v4 + 188));
        *(_BYTE *)(*(_DWORD *)(v4 + 188) + 336) |= 2u;
      }
      else
      {
        v10 = (const struct GASEnvironment *)a1[6];
        v5 = (GASValue *)GASFnCall::Arg(this: a1, a2: 0);
        v6 = GASValue::ToObject(this: v5, a2: (int)a1, a3: v10);
        v12 = (GASFnCall *)v6;
        if ( v6 != nullptr )
        {
          if ( ((int (__thiscall *)(struct GASObject *))v6[2].pNode[1].pNext)(a1: &v6[2]) == 7 )
          {
            v7 = 0;
            v11 = (int)v12[15];
            if ( v11 > 0 )
            {
              do
              {
                GFxEditTextCharacter::ProceedImageSubstitution(
                  this: (GFxEditTextCharacter *)v4,
                  a2: v4,
                  a3: (const struct GASEnvironment **)a1,
                  a4: v7,
                  a5: *((GASValue **)&v12[14]->cbSize + v7));
                ++v7;
              }
              while ( v7 < v11 );
            }
          }
          else
          {
            v8 = (GASValue *)GASFnCall::Arg(this: a1, a2: 0);
            GFxEditTextCharacter::ProceedImageSubstitution(
              this: (GFxEditTextCharacter *)v4,
              a2: v4,
              a3: (const struct GASEnvironment **)a1,
              a4: 0,
              a5: v8);
          }
        }
        else
        {
          v9 = *(_DWORD *)(v4 + 148);
          if ( v9 == 0 )
          {
            GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v4);
            if ( v9 == 0 )
              v9 = *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v4 + 108))(a1: v4) + 120);
          }
          GFxLogBase<GFxCharacter>::LogScriptWarning(
            a1: v4 + 12,
            a2: (int)"%s.setImageSubstitutions() failed: parameter should be either 'null', object or array\n",
            **(const char ***)(v9 + 8));
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EBCE0
// Name: _GASTextFieldCtorFunction::GetFontList_::_2_::FontsVisitor::Visit
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASTextFieldCtorFunction::GetFontList_::_2_::FontsVisitor::Visit(
        void ***this,
        int a2,
        GString a3,
        int a4,
        int a5)
{
  GString::DataDesc *pData; // esi
  int result; // eax
  int v8; // eax
  void **v9; // ecx
  unsigned int v10; // esi
  int v11[2]; // [esp+8h] [ebp-8h] BYREF

  pData = a3.pData;
  result = (*(int (__thiscall **)(GString::DataDesc *))(*(_DWORD *)a3.HeapTypeBits + 8))(a1: a3.pData) & 0xFF00;
  if ( result == 512 )
  {
    v8 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)pData[1].Size + 60))(a1: pData[1].Size);
    GString::GString(this: &a3, src: v8);
    v9 = *(this + 1);
    v11[0] = (int)&a3;
    v11[1] = (int)&a3;
    GHashSetBase<GHashNode<GString,GString,GString::NoCaseHashFunctor>,GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GString,2>,GHashsetCachedNodeEntry<GHashNode<GString,GString,GString::NoCaseHashFunctor>,GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeHashF>>::Set<GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeRef>(
      this: v9,
      a2: (int)v9,
      a3: v11);
    v10 = a3.HeapTypeBits & 0xFFFFFFFC;
    result = InterlockedExchangeAdd(Addend: (volatile LONG *)((a3.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) - 1;
    if ( result == 0 )
      return ((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: v10);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EBD60
// Name: public: GFxEditTextCharacter::GFxEditTextCharacter(struct GFxEditTextCharacterDef __near *,class GFxMovieDefImpl __near *,class GFxASCharacter __near *,class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
GFxEditTextCharacter *__thiscall GFxEditTextCharacter::GFxEditTextCharacter(
        GFxEditTextCharacter *this,
        struct GFxEditTextCharacterDef *a2,
        _IMAGE_SECTION_HEADER::<unnamed_type_Misc> pbindingDefImpl,
        GRefCountNTSImpl *a4,
        struct GFxResourceId a5)
{
  int v7; // eax
  struct GASStringNode *StringNode; // eax
  GRefCountNTSImpl *v9; // edi
  int v10; // eax
  IShaderAPI *v11; // eax
  int v12; // eax
  __int16 v13; // ax
  struct GASEnvironment *v14; // eax
  vc_attributes::PreRangeAttribute *v15; // eax
  int ActualPrototype; // eax
  int v17; // ecx
  int v18; // eax
  GPtr<GFxAmpProfileFrame> v19; // ecx
  const IDirect3DVertexDeclaration9 *TextAllocator; // eax
  int v21; // ecx
  int (__thiscall *v22)(int, int, int *); // edx
  IShaderDevice *v23; // eax
  struct GFxFontManager *v24; // eax
  GFxTextDocView *v25; // ebx
  GRefCountNTSImpl *v26; // ecx
  GRefCountNTSImpl **v27; // ebx
  int v28; // eax
  int v29; // eax
  __int16 v30; // ax
  int v32; // eax
  char v33; // al
  struct GASEnvironment *v35; // [esp-8h] [ebp-1Ch]
  IShaderDevice *v36; // [esp-4h] [ebp-18h]
  int v37; // [esp+10h] [ebp-4h] BYREF
  int pbindingDefImpla; // [esp+20h] [ebp+Ch]
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *pbindingDefImplb; // [esp+20h] [ebp+Ch]
  GRefCountNTSImpl *v40; // [esp+24h] [ebp+10h]
  GRefCountNTSImpl *v41; // [esp+24h] [ebp+10h]

  GFxASCharacter::GFxASCharacter((GFxASCharacter *)this, pbindingDefImpl, a3: (struct GFxASCharacter *)a4, a4: a5);
  *(_DWORD *)this = &GFxEditTextCharacter::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxEditTextCharacter::`vftable'{for `GFxLogBase<GFxCharacter>'};
  *((_DWORD *)this + 30) = &GFxEditTextCharacter::`vftable';
  *((_DWORD *)this + 46) = a2;
  *((_DWORD *)this + 47) = 0;
  v7 = ((int (__thiscall *)(GRefCountNTSImpl *))a4->__vftable[28].dtr_GRefCountImplCore)(a1: a4);
  StringNode = GASStringManager::CreateStringNode(
                 this: *(GASStringManager **)(*(_DWORD *)(v7 + 120) + 636),
                 result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*((_DWORD *)a2 + 19)
                                                                                           & 0xFFFFFFFC)
                                                                                          + 8),
                 length: *(_DWORD *)(*((_DWORD *)a2 + 19) & 0xFFFFFFFC) & 0x7FFFFFFF);
  *((_DWORD *)this + 52) = StringNode;
  ++*((_DWORD *)StringNode + 2);
  *((_BYTE *)this + 212) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)((char *)this + 232));
  *((_DWORD *)this + 59) = 0;
  *((_BYTE *)this + 240) = 1;
  v9 = (GRefCountNTSImpl *)((char *)this + 244);
  *((_DWORD *)this + 61) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 62) = 1;
  *((_BYTE *)this + 252) = 14;
  *((_DWORD *)this + 61) = &GFxEditTextCharacter::TextDocumentListener::`vftable';
  v10 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
  v11 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v10 + 8) + 12))(a1: v10 + 8, a2: 3);
  if ( v11 != nullptr )
  {
    if ( v11[3].__vftable != nullptr )
      *((_BYTE *)this + 252) |= 1u;
    GRefCountImpl::Release(this: v11);
  }
  *((_DWORD *)this + 66) = 0;
  *((_DWORD *)this + 68) = 0;
  v12 = *(_DWORD *)(pbindingDefImpl.PhysicalAddress + 28) + 24;
  *((_WORD *)this + 114) = 0;
  *((_DWORD *)this + 48) = v12;
  *((_DWORD *)this + 67) = -1;
  *((_DWORD *)this + 49) = *((_DWORD *)a2 + 21);
  if ( (*((_BYTE *)a2 + 80) & 4) != 0 )
    v13 = 4;
  else
    v13 = 0;
  *((_WORD *)this + 114) = v13;
  if ( *((char *)a2 + 80) >= 0 )
    *((_WORD *)this + 114) &= ~2u;
  else
    *((_WORD *)this + 114) |= 2u;
  *((_WORD *)this + 114) |= 0x80u;
  *((_DWORD *)this + 64) = 0;
  *((_DWORD *)this + 65) = 0;
  *((_DWORD *)this + 50) = 0xFFFFFF;
  *((_DWORD *)this + 51) = 0;
  if ( (*((_BYTE *)a2 + 80) & 0x40) != 0 )
  {
    *((_BYTE *)this + 203) = -1;
    *((_BYTE *)this + 207) = -1;
  }
  pbindingDefImpla = ((int (__thiscall *)(GRefCountNTSImpl *))a4->__vftable[21].dtr_GRefCountImplCore)(a1: a4);
  GFxCharacter::GetASEnvironment((CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this);
  v35 = v14;
  GFxASCharacter::GetGC((CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this);
  ActualPrototype = GASGlobalContext::GetActualPrototype(this: v15, a2: v35, a3: 10);
  v40 = (GRefCountNTSImpl *)ActualPrototype;
  if ( ActualPrototype != 0 )
    *(_DWORD *)(ActualPrototype + 8) = (*(_DWORD *)(ActualPrototype + 8) + 1) & 0x8FFFFFFF;
  v17 = *((_DWORD *)this + 32);
  if ( v17 != 0 )
  {
    GRefCountBaseGC<323>::Release(a1: v17, a2: (int)v9);
    ActualPrototype = (int)v40;
  }
  *((_DWORD *)this + 32) = ActualPrototype;
  v18 = ((int (__thiscall *)(GRefCountNTSImpl *))a4->__vftable[28].dtr_GRefCountImplCore)(a1: a4);
  GASAsBroadcaster::InitializeInstance(
    a1: (struct GASStringContext *)(v18 + 120),
    a2: (GFxEditTextCharacter *)((char *)this + 120));
  ((void (__thiscall *)(GRefCountNTSImpl *, char *, char *))a4->__vftable[28].dtr_GRefCountImplCore)(
    a1: a4,
    a2: (char *)this + 120,
    a3: (char *)this + 120);
  GASAsBroadcaster::AddListener(penv: v19);
  TextAllocator = GFxMovieRoot::GetTextAllocator(this: pbindingDefImpla);
  v41 = (GRefCountNTSImpl *)TextAllocator;
  if ( TextAllocator != nullptr )
    ++TextAllocator[1].__vftable;
  v21 = *(_DWORD *)(pbindingDefImpla + 32);
  v22 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v21 + 40);
  v37 = 324;
  pbindingDefImplb = (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)v22(a1: v21, a2: 340, a3: &v37);
  if ( pbindingDefImplb != nullptr )
  {
    GFxCharacter::GetLog(this, a2: (VertexShaderHandle_t__ *)this);
    v36 = v23;
    v24 = (struct GFxFontManager *)((int (__thiscall *)(GRefCountNTSImpl *))a4->__vftable[24].dtr_GRefCountImplCore)(a1: a4);
    v25 = GFxTextDocView::GFxTextDocView(this: pbindingDefImplb, pallocator: (GFxValue *)v41, a3: v24, a4: v36);
  }
  else
  {
    v25 = nullptr;
  }
  v26 = *((GRefCountNTSImpl **)this + 47);
  if ( v26 != nullptr )
    GRefCountNTSImpl::Release(this: v26);
  *((_DWORD *)this + 47) = v25;
  v27 = (GRefCountNTSImpl **)((char *)v25 + 16);
  if ( this != (GFxEditTextCharacter *)-244 )
    ++*((_DWORD *)this + 62);
  if ( *v27 != nullptr )
    GRefCountNTSImpl::Release(this: *v27);
  *v27 = v9;
  *(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 47) + 8) + 32) |= 2u;
  GFxEditTextCharacter::SetInitialFormatsAsDefault(this);
  v28 = *((_DWORD *)a2 + 13);
  if ( v28 > 0 )
    *(_DWORD *)(*((_DWORD *)this + 47) + 272) = v28;
  GFxTextDocView::SetViewRect(this: *((GFxTextDocView **)this + 47), a2: (int)a2 + 28, a3: 1);
  if ( (*((_BYTE *)a2 + 81) & 1) != 0 )
  {
    *(_BYTE *)(*((_DWORD *)this + 47) + 334) |= 0x20u;
    *(_BYTE *)(*((_DWORD *)this + 47) + 334) |= 0x40u;
  }
  v29 = *((_DWORD *)this + 47);
  if ( (*((_BYTE *)a2 + 80) & 2) != 0 )
    *(_BYTE *)(v29 + 334) |= 4u;
  else
    *(_BYTE *)(v29 + 334) &= ~4u;
  v30 = *((_WORD *)a2 + 40);
  LOBYTE(v27) = (v30 & 0x10) != 0;
  if ( (v30 & 0x10) != 0 && ((*((_BYTE *)a2 + 80) & 1) == 0 || (v30 & 2) == 0) )
    GFxTextDocView::SetAutoSizeX(this: *((GFxTextDocView **)this + 47));
  if ( (_BYTE)v27 != 0 )
    GFxTextDocView::SetAutoSizeY(this: *((GFxTextDocView **)this + 47));
  if ( (*((_BYTE *)a2 + 80) & 1) != 0 )
    GFxTextDocView::SetWordWrap(this: *((GFxTextDocView **)this + 47));
  if ( (*((_BYTE *)this + 228) & 4) != 0 )
    *(_BYTE *)(*((_DWORD *)this + 47) + 334) |= 0x10u;
  if ( (*(_WORD *)(*((_DWORD *)this + 46) + 80) & 0x400) != 0 )
    *(_BYTE *)(*((_DWORD *)this + 47) + 334) |= 0x40u;
  v32 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v32 != 0 )
    v33 = *(_BYTE *)(v32 + 104);
  else
    v33 = *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 3;
  if ( (v33 & 1) == 0 || (*(_BYTE *)(*((_DWORD *)this + 46) + 80) & 0x20) != 0 )
    GFxEditTextCharacter::CreateEditorKit(this, a2: (int)v27);
  if ( v41 != nullptr )
    GRefCountNTSImpl::Release(this: v41);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EC190
// Name: public: void GFxTextFilter::UpdateShadowOffset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFilter::UpdateShadowOffset(CDummyTexture *this)
{
  double v1; // [esp+4h] [ebp-10h]
  float v2; // [esp+Ch] [ebp-8h]
  float v3; // [esp+Ch] [ebp-8h]
  float aa; // [esp+10h] [ebp-4h]

  aa = (double)*((__int16 *)this + 9) * 3.141592741012573 / 1800.0;
  v1 = (double)*((__int16 *)this + 10);
  v2 = cos(aa);
  *((_WORD *)this + 11) = (int)(v2 * v1);
  v3 = sin(aa);
  *((_WORD *)this + 12) = (int)(v3 * v1);
}

//------------------------------------------------------------------------------
// Address: 0x100EC200
// Name: public: int GRange::CompareTo(int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRange::CompareTo(GetTriangles_Vertex_t *this, const GetTriangles_Vertex_t *index)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100EC240
// Name: public: bool GFxTextFormat::IsUrlSet(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::IsUrlSet(
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *this)
{
  if ( (*((_WORD *)this + 21) & 0x100) != 0 )
    GString::GetLength(this: (GString *)this + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100EC260
// Name: public: void GFxTextDocView::SetFauxBold(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetFauxBold(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        bool f)
{
  if ( f )
    *((_BYTE *)this + 335) |= 1u;
  else
    *((_BYTE *)this + 335) &= ~1u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC280
// Name: public: void GFxTextDocView::SetFauxItalic(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetFauxItalic(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        bool f)
{
  if ( f )
    *((_BYTE *)this + 335) |= 2u;
  else
    *((_BYTE *)this + 335) &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC2A0
// Name: public: void GFxTextDocView::SetKnockOut(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetKnockOut(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        bool f)
{
  if ( f )
    *((_BYTE *)this + 299) |= 0x20u;
  else
    *((_BYTE *)this + 299) &= ~0x20u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC2C0
// Name: public: void GFxTextDocView::SetHideObject(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetHideObject(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        bool f)
{
  if ( f )
    *((_BYTE *)this + 299) |= 0x40u;
  else
    *((_BYTE *)this + 299) &= ~0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC2E0
// Name: public: void GFxTextDocView::SetShadowQuality(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetShadowQuality(GRefCountBase<GFxAmpMemSegment,2> *this, unsigned int v)
{
  if ( v <= 1 )
    *((_BYTE *)this + 299) &= ~0x80u;
  else
    *((_BYTE *)this + 299) |= 0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC300
// Name: public: void GFxTextDocView::SetShadowAngle(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextDocView::SetShadowAngle(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        float a)
{
  int v2; // eax
  int result; // eax
  double v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+8h] [ebp-4h]
  float aa; // [esp+14h] [ebp+8h]
  float ab; // [esp+14h] [ebp+8h]
  float ac; // [esp+14h] [ebp+8h]

  aa = fmod(a, 360.0);
  v2 = (int)(aa * 10.0);
  *((_WORD *)this + 153) = v2;
  ab = (double)(__int16)v2 * 3.141592741012573 / 1800.0;
  v4 = (double)*((__int16 *)this + 154);
  v5 = cos(ab);
  *((_WORD *)this + 155) = (int)(v5 * v4);
  ac = sin(ab);
  result = (int)(ac * v4);
  *((_WORD *)this + 156) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EC3A0
// Name: public: void GFxTextDocView::SetShadowDistance(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextDocView::SetShadowDistance(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        float d)
{
  int result; // eax
  double v3; // [esp+0h] [ebp-Ch]
  float v4; // [esp+8h] [ebp-4h]
  float da; // [esp+14h] [ebp+8h]
  float db; // [esp+14h] [ebp+8h]

  *((_WORD *)this + 154) = (int)(d * 20.0);
  da = (double)*((__int16 *)this + 153) * 3.141592741012573 / 1800.0;
  v3 = (double)*((__int16 *)this + 154);
  v4 = cos(da);
  *((_WORD *)this + 155) = (int)(v4 * v3);
  db = sin(da);
  result = (int)(db * v3);
  *((_WORD *)this + 156) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EC430
// Name: private: void GFxEditTextCharacter::SetCondenseWhite(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetCondenseWhite(GFxEditTextCharacter *this, bool a2)
{
  if ( a2 )
    *((_WORD *)this + 114) |= 0x10u;
  else
    *((_WORD *)this + 114) &= ~0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC460
// Name: private: void GFxEditTextCharacter::SetHandCursor(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetHandCursor(GFxEditTextCharacter *this, bool a2)
{
  if ( a2 )
    *((_WORD *)this + 114) |= 0x20u;
  else
    *((_WORD *)this + 114) &= ~0x20u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC490
// Name: private: void GFxEditTextCharacter::SetNoTranslate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetNoTranslate(GFxEditTextCharacter *this, bool a2)
{
  if ( a2 )
    *((_WORD *)this + 114) |= 8u;
  else
    *((_WORD *)this + 114) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC4C0
// Name: private: void GFxEditTextCharacter::SetUseRichClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetUseRichClipboard(GFxEditTextCharacter *this, bool a2)
{
  if ( a2 )
    *((_WORD *)this + 114) |= 0x100u;
  else
    *((_WORD *)this + 114) &= ~0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC4F0
// Name: private: void GFxEditTextCharacter::SetAlwaysShowSelection(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetAlwaysShowSelection(GFxEditTextCharacter *this, bool a2)
{
  if ( a2 )
    *((_WORD *)this + 114) |= 0x200u;
  else
    *((_WORD *)this + 114) &= ~0x200u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC520
// Name: private: void GFxEditTextCharacter::SetNoAutoSelection(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetNoAutoSelection(GFxEditTextCharacter *this, bool a2)
{
  if ( a2 )
    *((_WORD *)this + 114) |= 0x400u;
  else
    *((_WORD *)this + 114) &= ~0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC550
// Name: private: void GFxEditTextCharacter::SetIMEDisabledFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetIMEDisabledFlag(GFxEditTextCharacter *this, bool a2)
{
  if ( a2 )
    *((_WORD *)this + 114) |= 0x800u;
  else
    *((_WORD *)this + 114) &= ~0x800u;
}

//------------------------------------------------------------------------------
// Address: 0x100EC580
// Name: public: bool GFxEditTextCharacter::UpdateTextFromVariable(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall GFxEditTextCharacter::UpdateTextFromVariable@<al>(
        GFxEditTextCharacter *this@<ecx>,
        long double a2@<st0>)
{
  _IMAGE_SYMBOL_EX *v3; // ebx
  __vc_attributes::max_isAttribute *v4; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v5; // edi
  char v6; // al
  int v7; // eax
  GASValue v10[4]; // [esp+8h] [ebp-14h] BYREF
  _DWORD *v11; // [esp+18h] [ebp-4h] BYREF

  v3 = (_IMAGE_SYMBOL_EX *)((char *)this + 208);
  if ( *(_DWORD *)(*((_DWORD *)this + 52) + 16) == 0 )
    return 1;
  v4 = (__vc_attributes::max_isAttribute *)(*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 112))(a1: this);
  v5 = (tagRID_DEVICE_INFO_KEYBOARD *)v4;
  if ( v4 == nullptr )
    return 0;
  LOBYTE(v10[0]) = 0;
  GASEnvironment::GetVariable(this: v4, varname: v3, a3: v10, retVal: 0, paschar: nullptr, a6: nullptr, a7: 0);
  if ( v6 == 0 )
  {
    (*(void (__thiscall **)(GFxEditTextCharacter *, const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *, _DWORD, _DWORD))(*(_DWORD *)this + 468))(
      a1: this,
      a2: &pMem,
      a3: 0,
      a4: 0);
  }
  else if ( GASValue::IsEqual(this: v10, a2, result: v5, v: (GASValue *)this + 53) == 0 )
  {
    GASValue::operator=(this: (int)this + 212, v: (tagWNDCLASSW *)v10);
    GASValue::ToStringImpl(this: (unsigned __int8 *)v10, a2: (int *)&v11, a3: v5, precision: -1, debug: false);
    (*(void (__thiscall **)(GFxEditTextCharacter *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this + 468))(
      a1: this,
      a2: *v11,
      a3: 0,
      a4: 0);
    v7 = (int)v11;
    if ( v11[2]-- == 1 )
      GASStringNode::ReleaseNode(a1: v7);
    GASValue::~GASValue(this: v10, a2: (int)v5);
    return 1;
  }
  GASValue::~GASValue(this: v10, a2: (int)v5);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EC670
// Name: public: virtual void GFxEditTextCharacter::SetText(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetText(GFxEditTextCharacter *this, const char *a2, int a3)
{
  __int16 v3; // ax
  __int16 v4; // ax

  v3 = *((_WORD *)this + 114);
  if ( (_BYTE)a3 != 0 )
  {
    if ( (*((_WORD *)this + 114) & 2) == 0 )
    {
      v4 = v3 | 2;
LABEL_6:
      *((_WORD *)this + 114) = v4;
    }
  }
  else if ( (*((_WORD *)this + 114) & 2) != 0 )
  {
    v4 = v3 & 0xFFFD;
    goto LABEL_6;
  }
  (*(void (__thiscall **)(GFxEditTextCharacter *, const char *, int, int))(*(_DWORD *)this + 468))(
    a1: this,
    a2,
    a3,
    a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100EC6C0
// Name: public: virtual void GFxEditTextCharacter::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetText(GFxEditTextCharacter *this, wchar_t *pwch, int a3)
{
  __int16 v4; // ax
  __int16 v5; // ax
  unsigned int v6; // edi
  char *v7; // ebx
  int v8; // [esp+Ch] [ebp-10Ch] BYREF
  wchar_t *v9; // [esp+10h] [ebp-108h]
  char v10; // [esp+14h] [ebp-104h] BYREF

  v4 = *((_WORD *)this + 114);
  v9 = pwch;
  if ( (_BYTE)a3 != 0 )
  {
    if ( (v4 & 2) != 0 )
      goto LABEL_7;
    v5 = v4 | 2;
  }
  else
  {
    if ( (v4 & 2) == 0 )
      goto LABEL_7;
    v5 = v4 & 0xFFFD;
  }
  *((_WORD *)this + 114) = v5;
LABEL_7:
  v6 = G_wcslen(pwch);
  if ( v6 >= 0x100 )
  {
    v8 = 2;
    v7 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 5 * v6 + 1, a4: &v8);
  }
  else
  {
    v7 = &v10;
  }
  GUTF8Util::EncodeString(a1: v7, a2: v9, a3: -1);
  (*(void (__thiscall **)(GFxEditTextCharacter *, char *, int, int))(*(_DWORD *)this + 468))(
    a1: this,
    a2: v7,
    a3,
    a4: 1);
  if ( v6 >= 0x100 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100EC7C0
// Name: public: virtual unsigned long GFxEditTextCharacter::GetStandardMemberBitMask(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxEditTextCharacter::GetStandardMemberBitMask(GFxEditTextCharacter *this)
{
  return 1652404175;
}

//------------------------------------------------------------------------------
// Address: 0x100EC7D0
// Name: public: virtual bool GFxEditTextCharacter::IsFocusAllowed(class GFxMovieRoot __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxEditTextCharacter::IsFocusAllowed(
        GFxEditTextCharacter *this,
        struct GFxMovieRoot *a2,
        unsigned int a3)
{
  int v3; // eax

  v3 = *((_DWORD *)this + 67);
  return (v3 == -1 || v3 == a3) && GFxASCharacter::IsFocusAllowed((GFxASCharacter *)this, a2, controllerIdx: a3);
}

//------------------------------------------------------------------------------
// Address: 0x100EC810
// Name: public: virtual bool GFxEditTextCharacter::IsFocusAllowed(class GFxMovieRoot __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxEditTextCharacter::IsFocusAllowed(
        GFxEditTextCharacter *this,
        struct GFxMovieRoot *a2,
        unsigned int a3)
{
  int v3; // eax

  v3 = *((_DWORD *)this + 67);
  return (v3 == -1 || v3 == a3) && GFxASCharacter::IsFocusAllowed((GFxASCharacter *)this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x100EC850
// Name: public: static void __near * GNewOverrideBase<323>::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GNewOverrideBase<323>::operator new(unsigned int sz)
{
  int v2; // [esp+0h] [ebp-4h] BYREF

  v2 = 323;
  return GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: sz, a3: &v2);
}

//------------------------------------------------------------------------------
// Address: 0x100EC8B0
// Name: private: bool GFxEditTextCharacter::IsSelectable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxEditTextCharacter::IsSelectable(GFxEditTextCharacter *this)
{
  int v1; // eax

  v1 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v1 != 0 )
    LOBYTE(v1) = (*(_BYTE *)(v1 + 104) & 2) != 0;
  else
    return (*(_BYTE *)(*((_DWORD *)this + 46) + 80) & 0x20) != 0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100EC8E0
// Name: public: void GFxEditTextCharacter::TextDocumentListener::TranslatorChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::TextDocumentListener::TranslatorChanged(
        GFxEditTextCharacter::TextDocumentListener *this)
{
  int v2; // eax
  IShaderAPI *v3; // eax

  v2 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 61) + 84))(a1: (char *)this - 244);
  v3 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v2 + 8) + 12))(a1: v2 + 8, a2: 3);
  if ( v3 != nullptr && v3[3].__vftable != nullptr )
    *((_BYTE *)this + 8) |= 1u;
  else
    *((_BYTE *)this + 8) &= ~1u;
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100EC930
// Name: public: virtual int GFxEditTextCharacter::CheckAdvanceStatus(bool)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxEditTextCharacter::CheckAdvanceStatus@<eax>(
        ScaleformRenderer::VertexShaderType ch@<ecx>,
        bool a2@<dil>,
        bool a3)
{
  ScaleformRenderer *v4; // eax
  int v5; // edi
  char v6; // al

  if ( (*(_BYTE *)(ch + 160) & 0xC) != 0 || (*(_BYTE *)(ch + 118) & 0x40) != 0 )
  {
    if ( a3 )
      return -1;
    else
      return 0;
  }
  else
  {
    if ( (*(_WORD *)(ch + 228) & 0x4000) != 0
      || *(_DWORD *)(*(_DWORD *)(ch + 208) + 16) != 0
      || (v4 = (ScaleformRenderer *)(*(int (__thiscall **)(ScaleformRenderer::VertexShaderType))(*(_DWORD *)ch + 84))(a1: ch),
          v5 = *(_DWORD *)(*(_DWORD *)(ch + 188) + 284),
          (*(_BYTE *)(ch + 160) & 1) != 0)
      && v5 != 0
      && ((*(_BYTE *)(v5 + 104) & 1) == 0 && (GFxMovieRoot::IsFocused(this: v4, (GRefCountNTSImpl *)ch, i: a2), v6 != 0)
       || (*(_BYTE *)(v5 + 104) & 0x20) != 0) )
    {
      if ( !a3 )
        return 1;
    }
    else if ( a3 )
    {
      return -1;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC9F0
// Name: public: void GFxEditTextCharacter::UpdateAutosizeSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::UpdateAutosizeSettings(GFxEditTextCharacter *this)
{
  char v2; // bl

  v2 = *((_BYTE *)this + 228) & 1;
  if ( v2 != 0 && (*(_BYTE *)(*((_DWORD *)this + 47) + 334) & 8) == 0 )
    GFxTextDocView::SetAutoSizeX(this: *((GFxTextDocView **)this + 47));
  else
    *(_BYTE *)(*((_DWORD *)this + 47) + 334) &= ~1u;
  if ( v2 != 0 )
    GFxTextDocView::SetAutoSizeY(this: *((GFxTextDocView **)this + 47));
  else
    *(_BYTE *)(*((_DWORD *)this + 47) + 334) &= ~2u;
  (*(void (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 352))(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x100ECA60
// Name: public: virtual class GASString GFxEditTextCharacter::GetText(class GASEnvironment __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode **__thiscall GFxEditTextCharacter::GetText(int this, struct GASStringNode **a2, int a3, int a4)
{
  _DWORD *v5; // ecx
  struct GASStringNode *StringNode; // eax
  _DWORD *v8; // eax
  GASStringManager *v9; // ecx
  struct GASStringNode *v10; // eax
  int v11; // esi
  volatile LONG *v12; // esi

  if ( (_BYTE)a4 == 0 )
    goto LABEL_7;
  v5 = *(_DWORD **)(this + 236);
  if ( v5 != nullptr && *v5 != 0 )
  {
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(a3 + 120) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*(_DWORD *)(this + 232)
                                                                                             & 0xFFFFFFFC)
                                                                                            + 8),
                   length: *(_DWORD *)(*(_DWORD *)(this + 232) & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++*((_DWORD *)StringNode + 2);
    *a2 = StringNode;
    return a2;
  }
  if ( (*(_BYTE *)(this + 228) & 2) != 0 )
  {
    GFxTextDocView::GetHtml(
      this: *(GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **)(this + 188),
      a2: (const GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeRef *)&a4);
    v9 = *(GASStringManager **)(*(_DWORD *)(a3 + 120) + 636);
  }
  else
  {
LABEL_7:
    GFxTextDocView::GetText(
      this: *(GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **)(this + 188),
      a2: (const GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeRef *)&a4);
    v9 = *(GASStringManager **)(*(_DWORD *)(a3 + 120) + 636);
  }
  v10 = GASStringManager::CreateStringNode(
          this: v9,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*v8 & 0xFFFFFFFC) + 8),
          length: *(_DWORD *)(*v8 & 0xFFFFFFFC) & 0x7FFFFFFF);
  ++*((_DWORD *)v10 + 2);
  v11 = a4;
  *a2 = v10;
  v12 = (volatile LONG *)(v11 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v12 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v12);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100ECB50
// Name: public: virtual class GFxASCharacter __near * GFxEditTextCharacter::GetTopMostMouseEntity(class GPoint<float> const __near &,struct GFxCharacter::TopMostParams const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxEditTextCharacter *__thiscall GFxEditTextCharacter::GetTopMostMouseEntity(
        GFxEditTextCharacter *this,
        float *p,
        _DWORD *a3)
{
  GFxEditTextCharacter *v3; // esi
  _DWORD *v4; // edi
  int Perspective3D; // edi
  int View3D; // ebx
  int v7; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v8; // ecx
  char v9; // al
  GFxEditTextCharacter *v10; // eax
  int v12; // [esp+1Ch] [ebp-74h]
  CCountedStringPoolBase<unsigned int>::hash_item_t x; // [esp+2Ch] [ebp-64h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v14; // [esp+74h] [ebp-1Ch] BYREF
  float v15; // [esp+88h] [ebp-8h]

  v3 = this;
  v4 = a3;
  if ( (*((_DWORD *)this + 40) & 0x800) != 0
    || (*(unsigned __int8 (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 16))(a1: this) == 0
    || (GFxEditTextCharacter *)a3[1] == v3
    || (*(unsigned __int8 (__thiscall **)(GFxEditTextCharacter *, _DWORD, _DWORD))(*(_DWORD *)v3 + 196))(
         a1: v3,
         a2: *a3,
         a3: a3[2]) == 0 )
  {
    return nullptr;
  }
  v14.m_Memory.m_pMemory = *((CCountedStringPoolBase<unsigned int>::hash_item_t **)v3 + 17);
  v14.m_Memory.m_nAllocationCount = *((int *)v3 + 18);
  v14.m_Memory.m_nGrowSize = *((int *)v3 + 19);
  v14.m_Size = *((int *)v3 + 20);
  v14.m_pElements = *((CCountedStringPoolBase<unsigned int>::hash_item_t **)v3 + 21);
  v15 = *((float *)v3 + 22);
  if ( GFxCharacter::Is3D(
         this: v3,
         result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
  {
    Perspective3D = GFxCharacter::GetPerspective3D(this: v3, checkAncestors: true);
    View3D = GFxCharacter::GetView3D(this: v3, checkAncestors: true);
    if ( Perspective3D != 0 )
      *(_DWORD *)((*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)v3 + 84))(a1: v3) + 224) = Perspective3D;
    if ( View3D != 0 )
      *(_DWORD *)((*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)v3 + 84))(a1: v3) + 228) = View3D;
    GMatrix3D::SetIdentity(this: (GMatrix3D *)&x.nReferenceCount);
    GFxCharacter::GetWorldMatrix3D(
      this: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v3,
      pmat: (CMatQueuedMesh::MST_MeshInfo_t *)&x.nReferenceCount);
    *(_DWORD *)((*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)v3 + 84))(a1: v3) + 232) = &x.nReferenceCount;
    v7 = (*(int (__thiscall **)(GFxEditTextCharacter *, CCountedStringPoolBase<unsigned int>::hash_item_t *))(*(_DWORD *)v3 + 84))(
           a1: v3,
           a2: &x);
    GScreenToWorld::GetWorldPoint(this: (CUtlBuffer *)(v7 + 208));
    v4 = a3;
  }
  else
  {
    GMatrix2D::TransformByInverse(this: &v14, result: &x, p, p_4: v12);
  }
  if ( *((_WORD *)v3 + 58) != 0
    || (*(unsigned __int8 (__thiscall **)(GFxEditTextCharacter *, CCountedStringPoolBase<unsigned int>::hash_item_t *, int))(*(_DWORD *)v3 + 68))(
         a1: v3,
         a2: &x,
         a3: 1) == 0 )
  {
    return nullptr;
  }
  if ( *((_BYTE *)v4 + 12) == 0 && !GFxEditTextCharacter::IsSelectable(this: v3) )
  {
    if ( GFxEditTextCharacter::IsSelectable(this: v3)
      || (*((_BYTE *)v3 + 228) & 2) == 0
      || (*(_BYTE *)((v8 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)v3
                           + 47))->Data.Policy.Capacity
                   + 32)
        & 1) == 0
      || (GFxTextDocView::IsUrlAtPoint(this: v8, x: (unsigned int)x.pString, y: x.nNextElement, purlPosRange: nullptr),
          v9 == 0) )
    {
      v3 = *((GFxEditTextCharacter **)v3 + 8);
      if ( v3 != nullptr )
      {
        while ( (*(int (__thiscall **)(int))(*((_DWORD *)v3 + 30) + 8))(a1: (int)v3 + 120) == 2 )
        {
          if ( *((_BYTE *)v4 + 12) != 0 || GFxSprite::ActsAsButton(this: (GFxSprite *)v3) != 0 )
          {
            v10 = (GFxEditTextCharacter *)v4[1];
            if ( v10 == nullptr || v3 != v10 )
              return v3;
          }
          v3 = *((GFxEditTextCharacter **)v3 + 8);
          if ( v3 == nullptr )
            return nullptr;
        }
      }
      return nullptr;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100ECD50
// Name: public: virtual bool GFxEditTextCharacter::IsTabable(void)const
// Source: json
//------------------------------------------------------------------------------
char __usercall GFxEditTextCharacter::IsTabable@<al>(GFxEditTextCharacter *this@<ecx>, long double a2@<st0>)
{
  int v3; // eax
  char v4; // al
  int (__thiscall *v5)(GFxEditTextCharacter *); // eax
  tagPOLYTEXTW *v6; // ebx
  struct GASStringNode *ConstStringNode; // eax
  int v8; // ecx
  int v9; // eax
  char v11; // bl
  int v13; // edi
  GASValue v14[4]; // [esp+4h] [ebp-1Ch] BYREF
  int v15; // [esp+14h] [ebp-Ch]
  struct GASStringNode *v16; // [esp+18h] [ebp-8h] BYREF
  char v17; // [esp+1Fh] [ebp-1h]

  if ( (*(unsigned __int8 (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 16))(a1: this) == 0 )
    return 0;
  v3 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  v4 = v3 != 0 ? *(_BYTE *)(v3 + 104) : *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 3;
  if ( (v4 & 1) != 0 )
    return 0;
  if ( (*((_BYTE *)this + 160) & 0x60) == 0 )
  {
    v15 = *((_DWORD *)this + 32);
    if ( v15 != 0 )
    {
      v5 = *(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 108);
      LOBYTE(v14[0]) = 0;
      v6 = (tagPOLYTEXTW *)v5(a1: this);
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: *(GASStringManager **)(v6[3].x + 636),
                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E410.m_Size,
                          a3: 0xAu,
                          a4: 0);
      v8 = v15;
      v16 = ConstStringNode;
      ++*((_DWORD *)ConstStringNode + 2);
      v17 = (*(int (__thiscall **)(int, tagPOLYTEXTW *, struct GASStringNode **, GASValue *))(*(_DWORD *)(v8 + 16) + 44))(
              a1: v8 + 16,
              a2: v6 + 3,
              a3: &v16,
              a4: v14);
      v9 = (int)v16;
      if ( (*((_DWORD *)v16 + 2))-- == 1 )
        GASStringNode::ReleaseNode(a1: v9);
      if ( v17 != 0 && LOBYTE(v14[0]) != 0 && LOBYTE(v14[0]) != 10 )
      {
        v11 = GASValue::ToBool(a1: (char *)v14, a2, result: v6);
        GASValue::~GASValue(this: v14, a2: (int)this);
        return v11;
      }
      GASValue::~GASValue(this: v14, a2: (int)this);
    }
  }
  v13 = *((_DWORD *)this + 40) & 0x60;
  return v13 == 0 || v13 == 96;
}

//------------------------------------------------------------------------------
// Address: 0x100ECE80
// Name: public: virtual bool GFxEditTextCharacter::DoesAcceptMouseFocus(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxEditTextCharacter::DoesAcceptMouseFocus(GFxEditTextCharacter *this)
{
  int v1; // edx
  char v2; // al
  char v3; // al
  BOOL result; // eax

  v1 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v1 != 0 )
    v2 = *(_BYTE *)(v1 + 104);
  else
    v2 = *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 3;
  result = true;
  if ( (v2 & 1) != 0 )
  {
    v3 = v1 != 0 ? *(_BYTE *)(v1 + 104) >> 1 : *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 5;
    if ( (v3 & 1) == 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ECED0
// Name: public: virtual unsigned int GFxEditTextCharacter::GetCursorType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxEditTextCharacter::GetCursorType(GFxEditTextCharacter *this)
{
  int v2; // eax

  if ( (*((_BYTE *)this + 228) & 0x20) != 0 )
    return 1;
  v2 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v2 != 0 )
    return (*(_BYTE *)(v2 + 104) & 2) != 0 ? 2 : 0;
  else
    return (*(_BYTE *)(*((_DWORD *)this + 46) + 80) & 0x20) != 0 ? 2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ECF20
// Name: public: virtual bool GFxEditTextCharacter::PointTestLocal(class GPoint<float> const __near &,unsigned char)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxEditTextCharacter::PointTestLocal(void *this, float *a2, char a3)
{
  float *ViewRect; // eax
  unsigned int v6; // [esp+0h] [ebp-4h]

  if ( (*((_DWORD *)this + 40) & 0x800) != 0
    || (a3 & 2) != 0 && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)this + 16))(a1: this) == 0 )
  {
    return false;
  }
  ViewRect = (float *)GFxTextDocView::GetViewRect(
                        this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this
                        + 47),
                        a2: v6);
  return ViewRect[2] >= (double)*a2
      && *ViewRect <= (double)*a2
      && ViewRect[3] >= (double)a2[1]
      && ViewRect[1] <= (double)a2[1];
}

//------------------------------------------------------------------------------
// Address: 0x100ECFB0
// Name: public: void GFxEditTextCharacter::ResetBlink(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::ResetBlink(GFxEditTextCharacter *this, bool a2, bool a3)
{
  GFxTextEditorKit *v4; // ecx
  int v5; // eax

  v4 = *(GFxTextEditorKit **)(*((_DWORD *)this + 47) + 284);
  if ( v4 != nullptr )
  {
    GFxTextEditorKit::ResetBlink(this: v4, a2, a3);
    v5 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
    if ( v5 != 0 )
      *(_DWORD *)(v5 + 9332) |= 0x400u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECFF0
// Name: public: virtual void GFxEditTextCharacter::SetSelection(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxEditTextCharacter::SetSelection(
        GFxEditTextCharacter *this@<ecx>,
        int a2@<ebx>,
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *startPos,
        int endPos)
{
  int v5; // eax
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v6; // edi
  int v7; // ebx
  signed int Length; // eax
  int v9; // eax

  if ( *(_DWORD *)(*((_DWORD *)this + 47) + 284) == 0 )
    GFxEditTextCharacter::CreateEditorKit(this, a2);
  v5 = *((_DWORD *)this + 47);
  if ( *(_DWORD *)(v5 + 284) != 0 )
  {
    v6 = startPos;
    if ( (int)startPos < 0 )
      v6 = nullptr;
    v7 = endPos;
    if ( endPos < 0 )
      v7 = 0;
    Length = GFxStyledText::GetLength(this: *(GFxStyledText **)(v5 + 8));
    if ( Length < (int)v6 )
      v6 = (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)Length;
    if ( Length < v7 )
      v7 = Length;
    GFxTextEditorKit::SetSelection(
      this: *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::Iterator **)(*((_DWORD *)this + 47) + 284),
      startPos: v6,
      endPos: v7);
    v9 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
    if ( v9 != 0 )
      *(_DWORD *)(v9 + 9332) |= 0x400u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED080
// Name: public: virtual int GFxEditTextCharacter::GetCaretIndex(void)
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall GFxEditTextCharacter::GetCaretIndex(GFxEditTextCharacter *this)
{
  int v2; // ecx
  char v3; // al
  char v4; // al

  v2 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v2 != 0 )
    v3 = *(_BYTE *)(v2 + 104);
  else
    v3 = *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 3;
  if ( ((v3 & 1) == 0
     || (v2 == 0 ? (v4 = *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 5) : (v4 = *(_BYTE *)(v2 + 104) >> 1), (v4 & 1) != 0))
    && v2 != 0 )
  {
    return GFILEFile::GetErrorCode(this: (CVTFTexture *)v2);
  }
  else
  {
    return IMAGE_FORMAT_UNKNOWN;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED0E0
// Name: public: virtual unsigned int GFxEditTextCharacter::GetBeginIndex(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxEditTextCharacter::GetBeginIndex(GFxEditTextCharacter *this)
{
  int v1; // eax
  char v2; // dl
  char v3; // cl
  int v4; // eax
  unsigned int v5; // ecx
  unsigned int result; // eax

  v1 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v1 != 0 )
    v2 = *(_BYTE *)(v1 + 104);
  else
    v2 = *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 3;
  if ( (v2 & 1) != 0 )
  {
    v3 = v1 != 0 ? *(_BYTE *)(v1 + 104) >> 1 : *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 5;
    if ( (v3 & 1) == 0 )
      return 0;
  }
  if ( v1 == 0 )
    return 0;
  v4 = *(_DWORD *)(v1 + 8);
  v5 = *(_DWORD *)(v4 + 32);
  result = *(_DWORD *)(v4 + 28);
  if ( result >= v5 )
    return v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ED140
// Name: public: virtual unsigned int GFxEditTextCharacter::GetEndIndex(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxEditTextCharacter::GetEndIndex(GFxEditTextCharacter *this)
{
  int v1; // eax
  char v2; // dl
  char v3; // cl
  int v4; // eax
  unsigned int v5; // ecx
  unsigned int result; // eax

  v1 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v1 != 0 )
    v2 = *(_BYTE *)(v1 + 104);
  else
    v2 = *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 3;
  if ( (v2 & 1) != 0 )
  {
    v3 = v1 != 0 ? *(_BYTE *)(v1 + 104) >> 1 : *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 5;
    if ( (v3 & 1) == 0 )
      return 0;
  }
  if ( v1 == 0 )
    return 0;
  v4 = *(_DWORD *)(v1 + 8);
  v5 = *(_DWORD *)(v4 + 32);
  result = *(_DWORD *)(v4 + 28);
  if ( v5 >= result )
    return v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ED1A0
// Name: public: virtual void GFxEditTextCharacter::SetOverwriteMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetOverwriteMode(GFxEditTextCharacter *this, bool a2)
{
  int v2; // eax

  v2 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v2 != 0 )
  {
    if ( a2 )
      *(_WORD *)(v2 + 104) |= 0x80u;
    else
      *(_WORD *)(v2 + 104) &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED1E0
// Name: public: bool GFxEditTextCharacter::IsOverwriteMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxEditTextCharacter::IsOverwriteMode(GFxEditTextCharacter *this)
{
  int v1; // eax

  v1 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  return v1 != 0 && (*(_WORD *)(v1 + 104) & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ED200
// Name: public: virtual void GFxEditTextCharacter::SetWideCursor(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetWideCursor(GFxEditTextCharacter *this, bool a2)
{
  int v3; // ecx
  int v4; // eax
  void *v5; // [esp+0h] [ebp-4h]

  v3 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( v3 != 0 )
  {
    if ( a2 )
      *(_WORD *)(v3 + 104) |= 0x100u;
    else
      GFxTextEditorKit::ClearWideCursor(
        this: (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v3,
        a2: v5);
    v4 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
    if ( v4 != 0 )
      *(_DWORD *)(v4 + 9332) |= 0x400u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED250
// Name: public: virtual bool GFxEditTextCharacter::OnMouseWheelEvent(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxEditTextCharacter::OnMouseWheelEvent(GFxEditTextCharacter *this, int a2)
{
  GFxTextDocView *v3; // ecx
  int v4; // eax
  char v5; // al
  signed int MaxVScroll; // edi
  int v7; // eax

  if ( *((char *)this + 228) >= 0 )
    return 0;
  v3 = *((GFxTextDocView **)this + 47);
  v4 = *((_DWORD *)v3 + 71);
  v5 = v4 != 0 ? *(_BYTE *)(v4 + 104) >> 1 : *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 5;
  if ( (v5 & 1) == 0 )
    return 0;
  MaxVScroll = GFxTextDocView::GetVScrollOffset(this: v3) - a2;
  if ( MaxVScroll < 0 )
    MaxVScroll = 0;
  if ( MaxVScroll > (int)GFxTextDocView::GetMaxVScroll(this: *((GFxTextDocView **)this + 47)) )
    MaxVScroll = GFxTextDocView::GetMaxVScroll(this: *((GFxTextDocView **)this + 47));
  GFxTextDocView::SetVScrollOffset(
    this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 47),
    vscroll: MaxVScroll);
  v7 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
  if ( v7 != 0 )
    *(_DWORD *)(v7 + 9332) |= 0x400u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ED2F0
// Name: public: virtual void GFxEditTextCharacter::SetNeedToUpdateGeomData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetNeedToUpdateGeomData(GFxEditTextCharacter *this)
{
  int v1; // edx
  int v2; // eax

  v1 = *(_DWORD *)this;
  *((_WORD *)this + 114) |= 0x2000u;
  v2 = (*(int (**)(void))(v1 + 84))();
  if ( v2 != 0 )
    *(_DWORD *)(v2 + 9332) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x100ED320
// Name: public: virtual void GFxEditTextCharacter::OnEventUnload(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxEditTextCharacter::OnEventUnload(GFxASCharacter *this@<ecx>, const char *a2@<edi>)
{
  int v3; // eax
  IShaderAPI *v4; // edi
  char v5; // al
  int v6; // eax
  unsigned int v8; // [esp-4h] [ebp-8h]
  int v9; // [esp+0h] [ebp-4h]

  v3 = (*(int (__thiscall **)(GFxASCharacter *))(*(_DWORD *)this + 84))(a1: this);
  if ( v3 != 0 )
  {
    v4 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v3 + 8) + 12))(a1: v3 + 8, a2: 27);
    if ( v4 != nullptr )
    {
      GFxIMEManager::IsTextFieldFocused(ptextfield: this, a2, a3: v9);
      if ( v5 != 0 )
        GFxIMEManager::DoFinalize(a1: v8);
      GRefCountImpl::Release(this: v4);
    }
  }
  v6 = (*(int (__thiscall **)(GFxASCharacter *))(*(_DWORD *)this + 84))(a1: this);
  if ( v6 != 0 )
    *(_DWORD *)(v6 + 9332) |= 0x400u;
  GFxASCharacter::OnEventUnload(this);
}

//------------------------------------------------------------------------------
// Address: 0x100ED380
// Name: public: virtual bool GFxEditTextCharacter::IsIMEEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxEditTextCharacter::IsIMEEnabled(GFxEditTextCharacter *this)
{
  __int16 v1; // dx
  int v2; // eax
  char v3; // al
  BOOL result; // eax

  v1 = *((_WORD *)this + 114);
  result = false;
  if ( (v1 & 0x800) == 0 )
  {
    v2 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
    v3 = v2 != 0 ? *(_BYTE *)(v2 + 104) : *(_BYTE *)(*((_DWORD *)this + 46) + 80) >> 3;
    if ( (v3 & 1) == 0 && (v1 & 4) == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ED420
// Name: private: unsigned int GRangeDataArray<void __near *,class GArrayLH<class GRangeData<void __near *>,2,struct GArrayDefaultPolicy>>::FindRangeIndex(int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::FindRangeIndex(
        _DWORD *this,
        int a2)
{
  _DWORD *v2; // edx
  int v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned int result; // eax
  int *v7; // edi
  int v8; // edx
  int v9; // edx
  int *v10; // edx
  int v11; // eax
  int v12; // eax
  _DWORD *v13; // [esp+Ch] [ebp-8h]
  unsigned int v14; // [esp+10h] [ebp-4h]

  v2 = this;
  v3 = *(this + 1);
  v4 = 0;
  v5 = v3 - 1;
  v13 = v2;
  v14 = 0;
  if ( v5 != 0 )
  {
    while ( v5 != -1 )
    {
      result = (v5 + v4) >> 1;
      v7 = (int *)(*v2 + 12 * result);
      v8 = *v7;
      if ( a2 < *v7 )
        goto LABEL_6;
      if ( a2 <= v7[1] + v8 - 1 )
        return result;
      v4 = v14;
      if ( a2 >= v8 )
        v9 = v7[1] - a2 + v8 - 1;
      else
LABEL_6:
        v9 = v8 - a2;
      if ( v9 == 0 )
        return result;
      if ( v9 >= 0 )
      {
        v5 = result - 1;
      }
      else
      {
        v4 = result + 1;
        v14 = result + 1;
      }
      v2 = v13;
      if ( v4 >= v5 )
        break;
    }
  }
  if ( v4 == v5 )
  {
    v10 = (int *)(*v2 + 12 * v4);
    v11 = *v10;
    if ( a2 < *v10 )
      goto LABEL_17;
    if ( a2 <= v10[1] + v11 - 1 )
      return v4;
    if ( a2 >= v11 )
      v12 = v10[1] - a2 + v11 - 1;
    else
LABEL_17:
      v12 = v11 - a2;
    if ( v12 == 0 )
      return v4;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100ED4E0
// Name: public: bool GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>::IsDataEqual(struct GFxEditTextCharacter::CSSHolder::UrlZone const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>::IsDataEqual(_DWORD *this, _DWORD *a2)
{
  return *(this + 2) == *a2 && *(this + 3) == a2[1] && *(this + 4) == a2[2];
}

//------------------------------------------------------------------------------
// Address: 0x100ED510
// Name: public: bool GRangeDataArray<class GPtr<class GFxTextFormat>,class GArrayLH<class GRangeData<class GPtr<class GFxTextFormat>>,2,struct GArrayDefaultPolicy>>::Iterator::IsFinished(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(
        int *this)
{
  int v1; // eax

  v1 = *(this + 1);
  return v1 < 0 || (unsigned int)v1 >= *(_DWORD *)(*this + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100ED530
// Name: private: unsigned int GRangeDataArray<void __near *,class GArrayLH<class GRangeData<void __near *>,2,struct GArrayDefaultPolicy>>::FindNearestRangeIndex(int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(
        GFxZlibSupportBase *this,
        int index)
{
  GFxZlibSupportBase *v2; // ebx
  volatile int RefCount; // edx
  unsigned int v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // ecx
  unsigned int v7; // edx
  GFxZlibSupportBase_vtbl *v8; // ebx
  int dtr_GRefCountImplCore; // esi
  int v10; // esi
  bool v11; // zf
  GFxZlibSupportBase_vtbl *v12; // esi
  int v13; // edx
  int v14; // edx
  GFxZlibSupportBase_vtbl *v15; // edx
  int v16; // ecx
  int v17; // ecx
  unsigned int upper; // [esp+4h] [ebp-Ch]
  unsigned int lowest; // [esp+Ch] [ebp-4h]

  v2 = this;
  RefCount = this->RefCount;
  if ( RefCount == 0 )
    return;
  v4 = RefCount - 1;
  v5 = 0;
  v6 = 0;
  upper = RefCount - 1;
  lowest = 0;
  if ( RefCount != 1 )
  {
    while ( v4 != -1 )
    {
      v7 = (v4 + v6) >> 1;
      v8 = &v2->__vftable[v7];
      dtr_GRefCountImplCore = (int)v8->dtr_GRefCountImplCore;
      if ( index < (int)v8->dtr_GRefCountImplCore )
        goto LABEL_7;
      if ( index <= (int)v8->CreateZlibFile + dtr_GRefCountImplCore - 1 )
        return;
      v4 = upper;
      if ( index >= dtr_GRefCountImplCore )
        v10 = (int)v8->CreateZlibFile + dtr_GRefCountImplCore - index - 1;
      else
LABEL_7:
        v10 = dtr_GRefCountImplCore - index;
      if ( v10 == 0 )
        return;
      if ( v10 >= 0 )
      {
        v4 = v7 - 1;
        upper = v7 - 1;
      }
      else
      {
        lowest = v6;
        v6 = v7 + 1;
      }
      v2 = this;
      v5 = lowest;
      v11 = v6 == v4;
      if ( v6 >= v4 )
        goto LABEL_17;
    }
  }
  v11 = v6 == v4;
LABEL_17:
  if ( !v11 )
    goto LABEL_26;
  v12 = &v2->__vftable[v6];
  v13 = (int)v12->dtr_GRefCountImplCore;
  if ( index < (int)v12->dtr_GRefCountImplCore )
    goto LABEL_21;
  if ( index <= (int)v12->CreateZlibFile + v13 - 1 )
    return;
  v2 = this;
  if ( index >= v13 )
    v14 = (int)v12->CreateZlibFile + v13 - index - 1;
  else
LABEL_21:
    v14 = v13 - index;
  if ( v14 != 0 )
  {
    v5 = lowest;
LABEL_26:
    if ( v5 < v4 )
    {
      v15 = &v2->__vftable[v5 + 1];
      do
      {
        v16 = (int)v15->dtr_GRefCountImplCore;
        if ( index < (int)v15->dtr_GRefCountImplCore )
          goto LABEL_31;
        if ( index <= (int)v15->CreateZlibFile + v16 - 1 )
          return;
        if ( index >= v16 )
          v17 = (int)v15->CreateZlibFile + v16 - index - 1;
        else
LABEL_31:
          v17 = v16 - index;
        if ( v17 >= 0 )
          break;
        ++v5;
        ++v15;
      }
      while ( v5 < v4 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED650
// Name: private: unsigned int GRangeDataArray<struct GFxEditTextCharacter::CSSHolder::UrlZone,class GArray<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,2,struct GArrayDefaultPolicy>>::FindNearestRangeIndex(int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GRangeDataArray<GFxEditTextCharacter::CSSHolder::UrlZone,GArray<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(
        _DWORD *this,
        int a2)
{
  _DWORD *v2; // ebx
  int v3; // edx
  unsigned int v5; // eax
  unsigned int v6; // esi
  unsigned int v7; // ecx
  unsigned int v8; // edx
  int *v9; // ebx
  int v10; // esi
  int v11; // esi
  bool v12; // zf
  int *v13; // esi
  int v14; // edx
  int v15; // edx
  int *v16; // edx
  int v17; // ecx
  int v18; // ecx
  unsigned int v19; // [esp+4h] [ebp-Ch]
  unsigned int v21; // [esp+Ch] [ebp-4h]

  v2 = this;
  v3 = *(this + 1);
  if ( v3 == 0 )
    return 0;
  v5 = v3 - 1;
  v6 = 0;
  v7 = 0;
  v19 = v3 - 1;
  v21 = 0;
  if ( v3 != 1 )
  {
    while ( v5 != -1 )
    {
      v8 = (v5 + v7) >> 1;
      v9 = (int *)(*v2 + 20 * v8);
      v10 = *v9;
      if ( a2 < *v9 )
        goto LABEL_8;
      if ( a2 <= v9[1] + v10 - 1 )
        return v8;
      v5 = v19;
      if ( a2 >= v10 )
        v11 = v9[1] - a2 + v10 - 1;
      else
LABEL_8:
        v11 = v10 - a2;
      if ( v11 == 0 )
        return v8;
      if ( v11 >= 0 )
      {
        v5 = v8 - 1;
        v19 = v8 - 1;
      }
      else
      {
        v21 = v7;
        v7 = v8 + 1;
      }
      v2 = this;
      v6 = v21;
      v12 = v7 == v5;
      if ( v7 >= v5 )
        goto LABEL_18;
    }
  }
  v12 = v7 == v5;
LABEL_18:
  if ( v12 )
  {
    v13 = (int *)(*v2 + 20 * v7);
    v14 = *v13;
    if ( a2 < *v13 )
      goto LABEL_22;
    if ( a2 <= v13[1] + v14 - 1 )
      return v7;
    v2 = this;
    if ( a2 >= v14 )
      v15 = v13[1] - a2 + v14 - 1;
    else
LABEL_22:
      v15 = v14 - a2;
    if ( v15 == 0 )
      return v7;
    v6 = v21;
  }
  if ( v6 < v5 )
  {
    v16 = (int *)(*v2 + 4 * (5 * v6 + 5));
    do
    {
      v17 = *v16;
      if ( a2 < *v16 )
        goto LABEL_32;
      if ( a2 <= v16[1] + v17 - 1 )
        return v6;
      if ( a2 >= v17 )
        v18 = v16[1] - a2 + v17 - 1;
      else
LABEL_32:
        v18 = v17 - a2;
      if ( v18 >= 0 )
        break;
      ++v6;
      v16 += 5;
    }
    while ( v6 < v5 );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100ED770
// Name: public: GFxTextFilter::GFxTextFilter(void)
// Source: json
//------------------------------------------------------------------------------
CDummyTexture *__thiscall GFxTextFilter::GFxTextFilter(CDummyTexture *this)
{
  *((_WORD *)this + 9) = 450;
  *((_WORD *)this + 10) = 80;
  this->__vftable = (CDummyTexture_vtbl *)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  this->__vftable = (CDummyTexture_vtbl *)&GRefCountBaseNTS<GASGlobalContext,323>::`vftable';
  *((_DWORD *)this + 2) = -2146435072;
  *((_DWORD *)this + 3) = -15712192;
  *((_WORD *)this + 11) = 57;
  *((_WORD *)this + 12) = 57;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_BYTE *)this + 16) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100ED7C0
// Name: public: void GFxTextDocView::SetBlurX(float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextDocView::SetBlurX(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        float v)
{
  unsigned int result; // eax

  result = (__int64)(v * 16.0 + 0.5);
  if ( result >= 0xFF )
    result = 255;
  *((_BYTE *)this + 296) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ED810
// Name: public: void GFxTextDocView::SetBlurY(float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextDocView::SetBlurY(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        float v)
{
  unsigned int result; // eax

  result = (__int64)(v * 16.0 + 0.5);
  if ( result >= 0xFF )
    result = 255;
  *((_BYTE *)this + 297) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ED860
// Name: public: void GFxTextDocView::SetBlurStrength(float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextDocView::SetBlurStrength(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        float v)
{
  unsigned int result; // eax

  result = (__int64)(v * 16.0 + 0.5);
  if ( result >= 0xFF )
    result = 255;
  *((_BYTE *)this + 298) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ED8B0
// Name: public: void GFxTextDocView::SetShadowBlurX(float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextDocView::SetShadowBlurX(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        float v)
{
  unsigned int result; // eax

  result = (__int64)(v * 16.0 + 0.5);
  if ( result >= 0xFF )
    result = 255;
  *((_BYTE *)this + 300) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ED900
// Name: public: void GFxTextDocView::SetShadowBlurY(float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextDocView::SetShadowBlurY(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        float v)
{
  unsigned int result; // eax

  result = (__int64)(v * 16.0 + 0.5);
  if ( result >= 0xFF )
    result = 255;
  *((_BYTE *)this + 301) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ED950
// Name: public: void GFxTextDocView::SetShadowStrength(float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextDocView::SetShadowStrength(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        float v)
{
  unsigned int result; // eax

  result = (__int64)(v * 16.0 + 0.5);
  if ( result >= 0xFF )
    result = 255;
  *((_BYTE *)this + 302) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ED9A0
// Name: public: void GFxTextDocView::SetShadowAlpha(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextDocView::SetShadowAlpha(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        float a)
{
  double v2; // st7
  bool v3; // c0
  bool v4; // c3
  double v5; // st7
  char result; // al
  float aa; // [esp+Ch] [ebp+8h]
  float ab; // [esp+Ch] [ebp+8h]

  aa = a * 255.0;
  v2 = aa;
  if ( aa >= 255.0 )
  {
    aa = 255.0;
    goto LABEL_3;
  }
  v3 = v2 > 0.0;
  v4 = 0.0 == v2;
  v5 = 0.0;
  if ( v3 || v4 )
LABEL_3:
    v5 = aa;
  ab = v5;
  result = (int)ab;
  *((_BYTE *)this + 303) = result;
  *((_BYTE *)this + 319) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EDA20
// Name: private: void GFxEditTextCharacter::SetSelectable(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxEditTextCharacter::SetSelectable(GFxEditTextCharacter *this@<ecx>, int a2@<ebx>, bool a3)
{
  int v3; // eax
  struct GFxTextEditorKit *EditorKit; // eax

  v3 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
  if ( a3 )
  {
    EditorKit = GFxEditTextCharacter::CreateEditorKit(this, a2);
    *((_WORD *)EditorKit + 52) |= 2u;
  }
  else if ( v3 != 0 )
  {
    *(_WORD *)(v3 + 104) &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EDA60
// Name: public: virtual void GFxEditTextCharacter::SetStateChangeFlags(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetStateChangeFlags(__int32 ch, bool a2)
{
  CMatQueuedMesh *v3; // edx
  int v4; // eax
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v5; // edi
  int v6; // eax

  v3 = *(CMatQueuedMesh **)ch;
  v4 = *(_DWORD *)(ch + 160) ^ (a2 << 16);
  *(_WORD *)(ch + 228) |= 0x4000u;
  *(_DWORD *)(ch + 160) ^= v4 & 0x30000;
  v5 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)((int (__thiscall *)(__int32))v3[1].IMesh::IIndexBuffer::__vftable)(a1: ch);
  v6 = GFxEditTextCharacter::CheckAdvanceStatus(
         (ScaleformRenderer::VertexShaderType)ch,
         a2: (bool)v5,
         a3: (*(_DWORD *)(ch + 160) & 0x80000) != 0);
  if ( v6 == -1 )
  {
    GFxASCharacter::RemoveFromOptimizedPlaylist(this: (CMatQueuedMesh **)ch, result: v5);
  }
  else if ( v6 == 1 )
  {
    GFxASCharacter::AddToOptimizedPlayList(this: ch, result: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EDAE0
// Name: public: virtual void GFxEditTextCharacter::AdvanceFrame(bool,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxEditTextCharacter::AdvanceFrame(
        GRefCountNTSImpl *this@<ecx>,
        bool a2@<bl>,
        long double a3@<st0>,
        bool a4,
        float a5)
{
  int v6; // eax
  __int16 v7; // ax
  GRefCountNTSImpl_vtbl *v8; // edx
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v9; // edi
  int v10; // eax
  ScaleformRenderer *v11; // eax
  int v12; // ebx
  ScaleformRenderer *v13; // edi
  char v14; // al

  if ( (((int (__thiscall *)(GRefCountNTSImpl *))this->__vftable[47].dtr_GRefCountImplCore)(a1: this) & 3) != 0 )
  {
    v6 = *((_DWORD *)this + 47);
    if ( v6 != 0 )
    {
      *(_BYTE *)(v6 + 336) |= 2u;
      GFxEditTextCharacter::TextDocumentListener::TranslatorChanged(this: (GFxEditTextCharacter::TextDocumentListener *)((char *)this + 244));
      ((void (__thiscall *)(GRefCountNTSImpl *, unsigned int, bool, int))this->__vftable[117].dtr_GRefCountImplCore)(
        a1: this,
        a2: (*(_DWORD *)(this + 29) & 0xFFFFFFFC) + 8,
        a3: (*((_WORD *)this + 114) & 0x1000) != 0,
        a4: 1);
    }
  }
  v7 = *((_WORD *)this + 114);
  *((_DWORD *)this + 40) &= 0xFFFCFFFF;
  if ( (v7 & 0x4000) != 0 )
  {
    v8 = this->__vftable;
    *((_WORD *)this + 114) = v7 & 0xBFFF;
    v9 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)((int (__thiscall *)(GRefCountNTSImpl *))v8[21].dtr_GRefCountImplCore)(a1: this);
    v10 = GFxEditTextCharacter::CheckAdvanceStatus(
            ch: (ScaleformRenderer::VertexShaderType)this,
            a2: (bool)v9,
            a3: (*(_DWORD *)(this + 20) & 0x80000) != 0);
    if ( v10 == -1 )
    {
      GFxASCharacter::RemoveFromOptimizedPlaylist((CMatQueuedMesh **)this, result: v9);
    }
    else if ( v10 == 1 )
    {
      GFxASCharacter::AddToOptimizedPlayList((int)this, result: v9);
    }
  }
  if ( a4 )
  {
    GFxEditTextCharacter::UpdateTextFromVariable((GFxEditTextCharacter *)this, a2: a3);
    *((_WORD *)this + 114) |= 0x40u;
  }
  else
  {
    *((_WORD *)this + 114) &= ~0x40u;
  }
  if ( *(_DWORD *)(*((_DWORD *)this + 47) + 284) != 0 )
  {
    v11 = (ScaleformRenderer *)((int (__thiscall *)(GRefCountNTSImpl *))this->__vftable[21].dtr_GRefCountImplCore)(a1: this);
    v12 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
    v13 = v11;
    GFxMovieRoot::IsFocused(this: v11, ch: this, i: a2);
    if ( v14 != 0 || (*(_BYTE *)(v12 + 104) & 0x20) != 0 )
    {
      GFxTextEditorKit::Advance(
        this: (GFxTextEditorKit *)v12,
        timer: (double)*(unsigned __int64 *)&v13->m_projection.M_[2][3] / 1000.0);
      if ( (*(_BYTE *)(v12 + 104) & 1) == 0 )
        v13[1].m_glyphVertexBuffer[101].color.Raw |= 0x400u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EDC80
// Name: public: virtual void GFxEditTextCharacter::TransformToTextRectSpace(class GFxValue::DisplayInfo __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::TransformToTextRectSpace(
        GFxEditTextCharacter *this,
        struct GFxValue::DisplayInfo *a2)
{
  long double v4; // st6
  bool v5; // zf
  long double v6; // st7
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v7; // ecx
  const unsigned int *ViewRect; // eax
  double v9; // st7
  double v10; // st7
  int v11; // [esp+0h] [ebp-1Ch]
  unsigned int v12; // [esp+0h] [ebp-1Ch]
  int v13; // [esp+0h] [ebp-1Ch]
  int p; // [esp+Ch] [ebp-10h] BYREF
  unsigned int nNextElement; // [esp+10h] [ebp-Ch]
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+14h] [ebp-8h] BYREF
  int v17; // [esp+24h] [ebp+8h]
  float v18; // [esp+24h] [ebp+8h]
  float v19; // [esp+24h] [ebp+8h]

  if ( (a2->VarsSet & 2) != 0 )
    v4 = a2->Y * 20.0;
  else
    v4 = (double)*(int *)(*((_DWORD *)this + 38) + 4);
  v5 = (a2->VarsSet & 1) == 0;
  *(float *)&result.nNextElement = v4;
  if ( v5 )
    v6 = (double)**((int **)this + 38);
  else
    v6 = 20.0 * a2->X;
  *(float *)&v17 = v6;
  p = v17;
  nNextElement = result.nNextElement;
  GMatrix2D::TransformByInverse(
    this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)((char *)this + 68),
    &result,
    (float *)&p,
    p_4: v11);
  v7 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 47);
  p = (int)result.pString;
  nNextElement = result.nNextElement;
  ViewRect = GFxTextDocView::GetViewRect(this: v7, a2: v12);
  result.pString = *(char **)ViewRect;
  result.nNextElement = *((unsigned int *)ViewRect + 1);
  *(float *)&p = *(float *)&p - *(float *)&result.pString;
  *(float *)&nNextElement = *(float *)&nNextElement - *(float *)&result.nNextElement;
  GMatrix2D::Transform(
    this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)((char *)this + 68),
    &result,
    (float *)&p,
    p_4: v13);
  if ( (a2->VarsSet & 1) != 0 )
  {
    v9 = *(float *)&result.pString;
    a2->VarsSet |= 1u;
    v18 = v9 / 20.0;
    a2->X = v18;
  }
  if ( (a2->VarsSet & 2) != 0 )
  {
    v10 = *(float *)&result.nNextElement / 20.0;
    a2->VarsSet |= 2u;
    v19 = v10;
    a2->Y = v19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EDD90
// Name: public: virtual bool GFxEditTextCharacter::SetStandardMember(enum GFxASCharacter::StandardMember,class GASValue const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge GFxEditTextCharacter::SetStandardMember@<al>(
        int a1@<ecx>,
        long double a2@<st0>,
        unsigned int member,
        GASValue *a4,
        bool a5)
{
  int (*v6)(void); // eax
  long double v7; // st7
  _SERVICE_STATUS *v8; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v9; // ecx
  float *ViewRect; // eax
  _DWORD *v11; // esi
  double v12; // st7
  bool result; // al
  _SERVICE_STATUS *v14; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v15; // ecx
  const unsigned int *v16; // eax
  int v17; // esi
  double v18; // st7
  _SERVICE_STATUS *v19; // eax
  const unsigned int *v20; // eax
  _SERVICE_STATUS *v21; // eax
  const unsigned int *v22; // eax
  double v23; // st7
  unsigned int v24; // [esp+0h] [ebp-6Ch]
  unsigned int v25; // [esp+0h] [ebp-6Ch]
  int v26; // [esp+0h] [ebp-6Ch]
  unsigned int v27; // [esp+0h] [ebp-6Ch]
  int v28; // [esp+0h] [ebp-6Ch]
  CCountedStringPoolBase<unsigned int>::hash_item_t v29; // [esp+Ch] [ebp-60h] BYREF
  float v30; // [esp+18h] [ebp-54h]
  float v31[2]; // [esp+1Ch] [ebp-50h] BYREF
  float v32[2]; // [esp+24h] [ebp-48h] BYREF
  double v33; // [esp+2Ch] [ebp-40h]
  GASValue v34; // [esp+34h] [ebp-38h] BYREF
  double v35; // [esp+38h] [ebp-34h]
  float v36; // [esp+40h] [ebp-2Ch]
  float v37; // [esp+44h] [ebp-28h]
  int p; // [esp+48h] [ebp-24h] BYREF
  float v39; // [esp+4Ch] [ebp-20h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v40; // [esp+50h] [ebp-1Ch] BYREF
  float v41; // [esp+64h] [ebp-8h]

  switch ( member )
  {
    case 0u:
      v6 = *(int (**)(void))(*(_DWORD *)a1 + 112);
      v40.m_Memory.m_pMemory = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(a1 + 68);
      v40.m_Memory.m_nAllocationCount = *(int *)(a1 + 72);
      v40.m_Memory.m_nGrowSize = *(int *)(a1 + 76);
      v40.m_Size = *(int *)(a1 + 80);
      v40.m_pElements = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(a1 + 84);
      v7 = *(float *)(a1 + 88);
      v41 = *(float *)(a1 + 88);
      v8 = (_SERVICE_STATUS *)v6();
      v33 = GASValue::ToNumber(this: a4, a2: (int)a4, a3: v7, result: v8) * 20.0;
      v37 = v33;
      v39 = v37;
      *(float *)&p = v37;
      GMatrix2D::TransformByInverse(
        this: &v40,
        result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)v31,
        (float *)&p,
        p_4: v24);
      v9 = *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(a1 + 188);
      p = SLODWORD(v31[0]);
      v39 = v31[1];
      ViewRect = (float *)GFxTextDocView::GetViewRect(this: v9, a2: v25);
      *(float *)&p = *(float *)&p - *ViewRect;
      GMatrix2D::Transform(
        this: &v40,
        result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&v29.nReferenceCount,
        (float *)&p,
        p_4: v26);
      p = *(int *)&v29.nReferenceCount;
      v39 = v30;
      LOBYTE(v34) = 3;
      v37 = *(float *)&v29.nReferenceCount / 20.0;
      v35 = v37;
      if ( GFxASCharacter::SetStandardMember(
             this: (CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *)a1,
             member: 0,
             val: (tagWNDCLASSW *)&v34,
             opcodeFlag: false) == 0 )
        goto LABEL_9;
      v11 = *(_DWORD **)(a1 + 152);
      if ( v11 != nullptr )
      {
        if ( v33 <= 0.0 )
          v12 = v33 - 0.5;
        else
          v12 = v33 + 0.5;
        *v11 = (int)v12;
      }
      GASValue::~GASValue(this: &v34, a2: (int)a4);
      return true;
    case 1u:
      v14 = (_SERVICE_STATUS *)(*(int (__thiscall **)(int))(*(_DWORD *)a1 + 112))(a1);
      v33 = GASValue::ToNumber(this: a4, a2: (int)a4, a3: a2, result: v14) * 20.0;
      v40.m_Memory.m_pMemory = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(a1 + 68);
      v40.m_Memory.m_nAllocationCount = *(int *)(a1 + 72);
      v40.m_Memory.m_nGrowSize = *(int *)(a1 + 76);
      v40.m_Size = *(int *)(a1 + 80);
      v40.m_pElements = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(a1 + 84);
      v41 = *(float *)(a1 + 88);
      *(float *)&p = 0.0;
      v39 = v33;
      GMatrix2D::TransformByInverse(
        this: &v40,
        result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)v32,
        (float *)&p,
        p_4: v24);
      v15 = *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(a1 + 188);
      p = SLODWORD(v32[0]);
      v39 = v32[1];
      v16 = GFxTextDocView::GetViewRect(this: v15, a2: v27);
      v39 = v39 - *((float *)v16 + 1);
      GMatrix2D::Transform(this: &v40, result: &v29, (float *)&p, p_4: v28);
      p = (int)v29.pString;
      v39 = *(float *)&v29.nNextElement;
      LOBYTE(v34) = 3;
      v37 = *(float *)&v29.nNextElement / 20.0;
      v35 = v37;
      if ( GFxASCharacter::SetStandardMember(
             this: (CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *)a1,
             member: 1,
             val: (tagWNDCLASSW *)&v34,
             opcodeFlag: false) != 0 )
      {
        v17 = *(_DWORD *)(a1 + 152);
        if ( v17 != 0 )
        {
          if ( v33 <= 0.0 )
            v18 = v33 - 0.5;
          else
            v18 = v33 + 0.5;
          *(_DWORD *)(v17 + 4) = (int)v18;
        }
        GASValue::~GASValue(this: &v34, a2: (int)a4);
        return true;
      }
      else
      {
LABEL_9:
        GASValue::~GASValue(this: &v34, a2: (int)a4);
        return false;
      }
    case 2u:
    case 3u:
    case 0xAu:
    case 0x6Du:
    case 0x6Eu:
    case 0x6Fu:
      (*(void (__thiscall **)(int))(*(_DWORD *)a1 + 352))(a1);
      goto LABEL_21;
    case 8u:
      v19 = (_SERVICE_STATUS *)(*(int (__thiscall **)(int))(*(_DWORD *)a1 + 112))(a1);
      v33 = GASValue::ToNumber(this: a4, a2: (int)a4, a3: a2, result: v19);
      v20 = GFxTextDocView::GetViewRect(
              this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(a1 + 188),
              a2: v24);
      v37 = *((float *)v20 + 1);
      v39 = *((float *)v20 + 3);
      v34 = *(GASValue *)v20;
      *(float *)&v35 = v37;
      v36 = v39;
      v39 = v33 * 20.0;
      *((float *)&v35 + 1) = v39 + *(float *)&v34;
      goto LABEL_18;
    case 9u:
      v21 = (_SERVICE_STATUS *)(*(int (__thiscall **)(int))(*(_DWORD *)a1 + 112))(a1);
      v33 = GASValue::ToNumber(this: a4, a2: (int)a4, a3: a2, result: v21);
      v22 = GFxTextDocView::GetViewRect(
              this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(a1 + 188),
              a2: v24);
      v39 = *((float *)v22 + 1);
      v37 = *((float *)v22 + 2);
      v34 = *(GASValue *)v22;
      v23 = v39;
      *(float *)&v35 = v39;
      *((float *)&v35 + 1) = v37;
      v39 = v33 * 20.0;
      v36 = v23 + v39;
LABEL_18:
      GFxTextDocView::SetViewRect(this: *(GFxTextDocView **)(a1 + 188), a2: (int)&v34, a3: 1);
      (*(void (__thiscall **)(int))(*(_DWORD *)a1 + 352))(a1);
      result = true;
      break;
    default:
LABEL_21:
      result = GFxASCharacter::SetStandardMember(
                 this: (CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *)a1,
                 member,
                 val: (tagWNDCLASSW *)a4,
                 opcodeFlag: a5) != 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EE180
// Name: public: bool GFxEditTextCharacter::IsUrlUnderMouseCursor(unsigned int,class GPoint<float> __near *,class GRange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::IsUrlUnderMouseCursor(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **this,
        unsigned int a2,
        float *a3,
        unsigned int *a4)
{
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v5; // edx
  int v6; // eax
  int v7; // eax
  double v8; // st7
  double v9; // st6
  unsigned int x; // [esp+0h] [ebp-4Ch]
  unsigned int y; // [esp+4h] [ebp-48h]
  int v12; // [esp+Ch] [ebp-40h]
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+18h] [ebp-34h] BYREF
  float v14; // [esp+24h] [ebp-28h]
  float v15; // [esp+28h] [ebp-24h]
  unsigned int *purlPosRange; // [esp+2Ch] [ebp-20h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v17; // [esp+30h] [ebp-1Ch] BYREF

  v5 = *this;
  purlPosRange = a4;
  v6 = ((int (__thiscall *)(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **))v5[7].Data.Data)(a1: this);
  if ( v6 != 0 )
  {
    if ( a2 < 4 )
      v7 = v6 + 36 * a2 + 2356;
    else
      v7 = 0;
    v15 = *(float *)(v7 + 24);
    *(float *)&result.nReferenceCount = *(float *)(v7 + 20);
    v14 = v15;
    GMatrix2D::SetIdentity(this: (float *)&v17);
    GFxCharacter::GetWorldMatrix((GFxCharacter *)this, pmat: (CMaterialDict *)&v17);
    GMatrix2D::TransformByInverse(this: &v17, &result, p: (float *)&result.nReferenceCount, p_4: v12);
    v8 = *(float *)&result.nNextElement;
    v9 = *(float *)&result.pString;
    if ( a3 != nullptr )
    {
      *a3 = *(float *)&result.pString;
      a3[1] = v8;
    }
    *(float *)&y = v8;
    *(float *)&x = v9;
    GFxTextDocView::IsUrlAtPoint(this: *(this + 47), x, y, purlPosRange);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE250
// Name: public: bool GFxEditTextCharacter::IsUrlTheSame(unsigned int,class GRange const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxEditTextCharacter::IsUrlTheSame(
        GFxEditTextCharacter *this,
        unsigned int a2,
        const struct GRange *a3)
{
  int v3; // edi
  bool result; // al
  unsigned int v5; // ebx
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  int v8; // [esp+4h] [ebp-4h]
  const struct GRange *v9; // [esp+14h] [ebp+Ch]

  v3 = *((_DWORD *)this + 59);
  result = true;
  if ( v3 != 0 )
  {
    v5 = *(_DWORD *)(v3 + 8);
    v6 = 0;
    if ( v5 != 0 )
    {
      v8 = *(_DWORD *)a3;
      v7 = *(_DWORD **)(v3 + 4);
      v9 = (const struct GRange *)(*((_DWORD *)a3 + 1) + *(_DWORD *)a3 - 1);
      while ( (int)v9 < *v7 || v7[1] + *v7 - 1 < v8 || *(_DWORD *)(v3 + 8 * a2 + 16) == v6 + 1 )
      {
        ++v6;
        v7 += 5;
        if ( v6 >= v5 )
          return true;
      }
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EE2C0
// Name: public: virtual bool GFxEditTextCharacter::OnButtonEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxEditTextCharacter::OnButtonEvent@<al>(
        GFxEditTextCharacter *this@<ecx>,
        _TAPE_WMI_OPERATIONS *a2@<ebx>,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > a3)
{
  char v4; // al
  char v5; // al
  char v6; // al
  const char *v7; // esi
  unsigned __int8 *v8; // esi
  int v9; // eax
  int v10; // ebx
  unsigned int v11; // esi
  GRefCountNTSImpl *v12; // edi
  struct GFxSprite *v13; // eax
  GFxValue v16; // [esp+Ch] [ebp-34h] BYREF
  GFxValue v17; // [esp+1Ch] [ebp-24h] BYREF
  int v18[2]; // [esp+2Ch] [ebp-14h] BYREF
  unsigned int v19; // [esp+34h] [ebp-Ch]
  GFxMovieRoot *v20; // [esp+38h] [ebp-8h]
  int ppdestTextFmt; // [esp+3Ch] [ebp-4h] BYREF

  if ( *a3.m_Memory.m_pMemory != (void (__cdecl *)(int))2048 )
    return 0;
  if ( (*((_BYTE *)this + 228) & 2) != 0 && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 47) + 8) + 32) & 1) != 0 )
  {
    GFxEditTextCharacter::IsUrlUnderMouseCursor(
      (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this,
      a2: *((char *)a3.m_Memory.m_pMemory + 11),
      a3: (float *)v18,
      a4: nullptr);
    if ( v4 != 0
      && GFxTextDocView::GetCharIndexAtPoint(
           this: *((GFxTextDocView **)this + 47),
           a2: *(float *)v18,
           a3: *(float *)&v18[1]) != -1 )
    {
      GFxStyledText::GetTextAndParagraphFormat(
        this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(*((_DWORD *)this + 47) + 8),
        (int)&ppdestTextFmt,
        ppdestParaFmt: 0);
      if ( v5 != 0 )
      {
        GFxTextFormat::IsUrlSet(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)ppdestTextFmt);
        if ( v6 != 0 )
        {
          v7 = (const char *)((*(_DWORD *)(ppdestTextFmt + 16) & 0xFFFFFFFC) + 8);
          v20 = (GFxMovieRoot *)(*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
          if ( v20 != nullptr && GString::CompareNoCase(a1: v7, a2: "asfunction:", a3: 11) == 0 )
          {
            v8 = (unsigned __int8 *)(v7 + 11);
            strchr(string: v8, chr: 0x2Cu);
            v10 = v9;
            GString::GString(this: (CUtlMemory<CImagePacker,int> *)&a3);
            v17.pObjectInterface = nullptr;
            v17.Type = VT_Undefined;
            v19 = 0;
            if ( v10 != 0 )
            {
              GString::AppendString(
                this: (CUtlMemory<CImagePacker,int> *)&a3,
                putf8str: (CImagePacker *)v8,
                utf8StrSz: v10 - (_DWORD)v8);
              v11 = 1;
              GFxValue::SetString(this: &v17, p: (const char *)(v10 + 1));
            }
            else
            {
              GString::operator=(this: &a3, a2: v8);
              v11 = v19;
            }
            v12 = *((GRefCountNTSImpl **)this + 8);
            v16.pObjectInterface = nullptr;
            v16.Type = VT_Undefined;
            if ( v12 != nullptr
              && (++v12->RefCount, (v13 = (struct GFxSprite *)GASObjectInterface::ToSprite(result: a2)) != nullptr) )
            {
              GFxMovieRoot::Invoke(
                this: (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)v20,
                a2: v13,
                a3: (IDirect3D9 *)(((int)a3.m_Memory.m_pMemory & 0xFFFFFFFC) + 8),
                a4: &v16,
                a5: &v17,
                numArgs: v11);
            }
            else
            {
              (*(void (__thiscall **)(GFxMovieRoot *, unsigned int, GFxValue *, GFxValue *, unsigned int))(*(_DWORD *)v20 + 92))(
                a1: v20,
                a2: ((int)a3.m_Memory.m_pMemory & 0xFFFFFFFC) + 8,
                a3: &v16,
                a4: &v17,
                a5: v11);
            }
            if ( v12 != nullptr )
              GRefCountNTSImpl::Release(this: v12);
            GFxValue::~GFxValue(this: &v16);
            GFxValue::~GFxValue(this: &v17);
            GString::~GString(this: (GString *)&a3);
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100EE480
// Name: public: virtual void GFxEditTextCharacter::OnFocus(enum GFxASCharacter::FocusEventType,class GFxASCharacter __near *,unsigned int,enum GFxFocusMovedType)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxEditTextCharacter::OnFocus(
        ScaleformRenderer::VertexShaderType this,
        struct GASValue *a2,
        tagAXISINFOA *a3,
        unsigned int a4,
        int a5)
{
  int v6; // ecx
  int v7; // eax
  char v8; // al
  unsigned int Length; // eax
  int v10; // ecx
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  char v15; // al
  char v16; // al
  int v17; // eax
  int v18; // eax
  int v19; // eax
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v20; // eax
  void *v22; // [esp+0h] [ebp-Ch]

  v6 = *(_DWORD *)(this + 188);
  v7 = *(_DWORD *)(v6 + 284);
  if ( v7 != 0 )
    v8 = *(_BYTE *)(v7 + 104) >> 1;
  else
    v8 = *(_BYTE *)(*(_DWORD *)(this + 184) + 80) >> 5;
  if ( (v8 & 1) == 0 )
    goto LABEL_18;
  if ( a2 != (struct GASValue *)1 )
  {
    if ( a2 != nullptr )
      goto LABEL_18;
    *(_DWORD *)(this + 268) = -1;
    v13 = *(_DWORD *)(v6 + 284);
    if ( v13 == 0 )
      goto LABEL_18;
    if ( (*(_WORD *)(this + 228) & 0x200) == 0 )
      GFxTextDocView::SetSelection(this: *(GFxTextDocView **)(v13 + 8), startPos: 0, endPos: 0);
    GFxTextEditorKit::OnKillFocus(
      this: *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)(*(_DWORD *)(this + 188) + 284),
      a2: v22);
    v12 = (*(int (__thiscall **)(ScaleformRenderer::VertexShaderType))(*(_DWORD *)this + 84))(a1: this);
    goto LABEL_16;
  }
  if ( (*(_WORD *)(this + 228) & 0x400) == 0 && a5 != 1 )
  {
    Length = GFxStyledText::GetLength(this: *(GFxStyledText **)(v6 + 8));
    (*(void (__thiscall **)(ScaleformRenderer::VertexShaderType, _DWORD, unsigned int))(*(_DWORD *)this + 376))(
      a1: this,
      a2: 0,
      a3: Length);
  }
  v10 = *(_DWORD *)(this + 188);
  *(_DWORD *)(this + 268) = a4;
  v11 = *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)(v10 + 284);
  if ( v11 != nullptr )
  {
    GFxTextEditorKit::OnSetFocus(this: v11, a2: v22);
    v12 = (*(int (__thiscall **)(ScaleformRenderer::VertexShaderType))(*(_DWORD *)this + 84))(a1: this);
LABEL_16:
    if ( v12 != 0 )
      *(_DWORD *)(v12 + 9332) |= 0x400u;
  }
LABEL_18:
  v14 = *(_DWORD *)(*(_DWORD *)(this + 188) + 284);
  if ( v14 != 0 )
    v15 = *(_BYTE *)(v14 + 104);
  else
    v15 = *(_BYTE *)(*(_DWORD *)(this + 184) + 80) >> 3;
  if ( (v15 & 1) == 0
    || (v14 == 0 ? (v16 = *(_BYTE *)(*(_DWORD *)(this + 184) + 80) >> 5) : (v16 = *(_BYTE *)(v14 + 104) >> 1),
        LOBYTE(v17) = v16 & 1,
        (_BYTE)v17 != 0) )
  {
    if ( a2 == (struct GASValue *)1 && v14 != 0 )
    {
      GFxTextEditorKit::ResetBlink(this: (GFxTextEditorKit *)v14, a2: true, a3: true);
      v18 = (*(int (__thiscall **)(ScaleformRenderer::VertexShaderType))(*(_DWORD *)this + 84))(a1: this);
      if ( v18 != 0 )
        *(_DWORD *)(v18 + 9332) |= 0x400u;
    }
    GFxASCharacter::OnFocus(a1: (tagAXISINFOA *)this, a2: (char *)this, a3: a2, result: a3, a5: a4, a6: a5);
    v17 = *(_DWORD *)(*(_DWORD *)(this + 188) + 284);
    if ( v17 != 0 && (*(_BYTE *)(v17 + 104) & 1) == 0 )
    {
      v19 = *(_DWORD *)this;
      *(_WORD *)(this + 228) |= 0x4000u;
      v20 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)(*(int (__thiscall **)(ScaleformRenderer::VertexShaderType))(v19 + 84))(a1: this);
      LOBYTE(v17) = (unsigned __int8)GFxASCharacter::ModifyOptimizedPlayListLocal<GFxEditTextCharacter>(
                                       this,
                                       result: v20);
    }
  }
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x100EE630
// Name: public: virtual class GRect<float> GFxEditTextCharacter::GetBounds(class GMatrix2D const __near &)const
// Source: rtti_class
//------------------------------------------------------------------------------
float *__thiscall GFxEditTextCharacter::GetBounds(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **this,
        float *a2,
        float *a3)
{
  float *ViewRect; // eax
  unsigned int v5; // [esp+0h] [ebp-4h]

  ViewRect = (float *)GFxTextDocView::GetViewRect(this: *(this + 47), a2: v5);
  *a2 = 0.0;
  a2[1] = 0.0;
  a2[2] = 0.0;
  a2[3] = 0.0;
  GMatrix2D::EncloseTransform(this: a3, a2, a3: ViewRect);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100EE660
// Name: public: virtual void GFxEditTextCharacter::Display(class GFxDisplayContext __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::Display(GFxEditTextCharacter *this, GArrayDefaultPolicy *a2)
{
  int v2; // ebx
  float *Capacity; // eax
  GArrayDefaultPolicy *v5; // edx
  int (__cdecl *v6)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *); // eax
  float *v7; // eax
  GArrayDefaultPolicy *v8; // esi
  ScaleformRenderer::VertexShaderType v9; // esi
  float *v10; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v11; // ecx
  const unsigned int *ViewRect; // eax
  int v13; // ecx
  __int16 v14; // ax
  GArrayDefaultPolicy *v15; // edi
  char v16; // al
  int v17; // eax
  unsigned int v18; // ebx
  unsigned __int8 *v19; // eax
  int v20; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v21; // ecx
  unsigned int v22; // ebx
  int v23; // ecx
  int v24; // edx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v25; // ecx
  char v26; // al
  int v27; // [esp-4h] [ebp-168h]
  unsigned int v28; // [esp+0h] [ebp-164h]
  bool v29; // [esp+0h] [ebp-164h]
  int (__cdecl *v30)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *); // [esp+Ch] [ebp-158h]
  ScaleformRenderer *v31; // [esp+10h] [ebp-154h]
  float v32; // [esp+14h] [ebp-150h]
  float v33; // [esp+14h] [ebp-150h]
  unsigned int v34; // [esp+18h] [ebp-14Ch] BYREF
  float v35; // [esp+1Ch] [ebp-148h]
  float v36; // [esp+20h] [ebp-144h]
  float v37; // [esp+24h] [ebp-140h]
  bool v38; // [esp+28h] [ebp-13Ch]
  __int16 v39; // [esp+2Ah] [ebp-13Ah]
  float v40; // [esp+2Ch] [ebp-138h]
  GArrayDefaultPolicy *context; // [esp+30h] [ebp-134h]
  ScaleformRenderer::VertexShaderType v42; // [esp+34h] [ebp-130h]
  int v43; // [esp+38h] [ebp-12Ch]
  char v44; // [esp+3Fh] [ebp-125h]
  CBasePerMaterialContextData v45[5]; // [esp+40h] [ebp-124h] BYREF
  _QWORD v46[8]; // [esp+80h] [ebp-E4h] BYREF
  GRenderer::Cxform v47[2]; // [esp+C0h] [ebp-A4h] BYREF
  GRenderer::Cxform v48; // [esp+100h] [ebp-64h] BYREF
  float v49; // [esp+120h] [ebp-44h]
  float v50; // [esp+124h] [ebp-40h] BYREF
  float v51; // [esp+128h] [ebp-3Ch]
  float v52; // [esp+12Ch] [ebp-38h]
  float v53; // [esp+130h] [ebp-34h]
  float v54; // [esp+134h] [ebp-30h]
  GMatrix2D v55; // [esp+138h] [ebp-2Ch] BYREF
  _WORD v56[5]; // [esp+150h] [ebp-14h] BYREF
  unsigned __int16 v57; // [esp+15Ah] [ebp-Ah]
  __int16 v58; // [esp+15Ch] [ebp-8h]
  unsigned __int16 v59; // [esp+15Eh] [ebp-6h]

  v2 = *(_DWORD *)(a2[18].Capacity + 12);
  v42 = (ScaleformRenderer::VertexShaderType)this;
  context = a2;
  if ( v2 != 0 )
  {
    GMatrix2D::SetIdentity(this: (float *)&v55);
    if ( LOBYTE(a2[5].Capacity) == 0 )
    {
      Capacity = (float *)a2[1].Capacity;
      v55.M_[0][0] = *Capacity;
      v55.M_[0][1] = Capacity[1];
      v55.M_[0][2] = Capacity[2];
      v55.M_[1][0] = Capacity[3];
      v55.M_[1][1] = Capacity[4];
      v55.M_[1][2] = Capacity[5];
      GMatrix2D::Prepend(this: &v55, a2: (const struct GMatrix2D *)((char *)this + 68));
    }
    v48 = *(GRenderer::Cxform *)a2->Capacity;
    GRenderer::Cxform::Concatenate(this: &v48, a2: (const struct GRenderer::Cxform *)(v42 + 36));
    v31 = (ScaleformRenderer *)(*(int (__thiscall **)(ScaleformRenderer::VertexShaderType))(*(_DWORD *)v42 + 84))(a1: v42);
    if ( v31 != nullptr )
    {
      v5 = context;
      v6 = (int (__cdecl *)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *))context[2].Capacity;
      v30 = v6;
      v44 = context[5].Capacity;
      if ( v6 == nullptr )
        v6 = GMatrix3D::Identity;
      qmemcpy(v46, v6, sizeof(v46));
      if ( v44 != 0 )
      {
        GFxCharacter::GetLocalMatrix3D(
          this: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v42,
          a2: v45);
        qmemcpy((void *)v47, v46, sizeof(v47));
        GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)v46, a2: v7, a3: (float *)v47);
        v8 = context;
        (*(void (__thiscall **)(_DWORD, _QWORD *))(**(_DWORD **)(context[18].Capacity + 12) + 92))(
          a1: *(_DWORD *)(context[18].Capacity + 12),
          a2: v46);
        context[2].Capacity = (unsigned int)v46;
        v55.M_[0][0] = GMatrix2D::Identity.M_[0][0];
        v5 = v8;
        v55.M_[0][1] = GMatrix2D::Identity.M_[0][1];
        v55.M_[0][2] = GMatrix2D::Identity.M_[0][2];
        v55.M_[1][0] = GMatrix2D::Identity.M_[1][0];
        v55.M_[1][1] = GMatrix2D::Identity.M_[1][1];
        v55.M_[1][2] = GMatrix2D::Identity.M_[1][2];
      }
      if ( (v9 = v42, v5[2].Capacity != 0)
        || (v10 = (float *)GFxTextDocView::GetViewRect(
                             this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v42 + 188),
                             a2: v28),
            *(float *)&v34 = 0.0,
            v35 = 0.0,
            v36 = 0.0,
            v37 = 0.0,
            GMatrix2D::EncloseTransform(this: (float *)&v55, a2: (float *)&v34, a3: v10),
            v35 <= (double)v31->m_viewportMatrix.M_[0][2])
        && v31->m_viewportMatrix.M_[0][0] <= (double)v37
        && v31->m_userMatrix.M_[1][2] <= (double)v36
        && *(float *)&v34 <= (double)v31->m_viewportMatrix.M_[0][1]
        || (*(_DWORD *)(context[18].Capacity + 20) & 0x100) != 0 )
      {
        v40 = fabs(v48.M_[3][0]);
        if ( v40 >= 0.001 || (v40 = fabs(v48.M_[3][1])) >= 1.0 )
        {
          if ( *(_BYTE *)(v9 + 207) != 0 || *(_BYTE *)(v9 + 203) != 0 )
          {
            (*(void (__thiscall **)(int, GRenderer::Cxform *))(*(_DWORD *)v2 + 64))(a1: v2, a2: &v48);
            v47[1].M_[1][0] = v55.M_[0][0];
            v11 = *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v9 + 188);
            v47[1].M_[1][1] = v55.M_[0][1];
            v47[1].M_[2][0] = v55.M_[0][2];
            v47[1].M_[2][1] = v55.M_[1][0];
            v47[1].M_[3][0] = v55.M_[1][1];
            v47[1].M_[3][1] = v55.M_[1][2];
            *(float *)&v34 = 0.0;
            v35 = 0.0;
            v36 = 0.0;
            v37 = 0.0;
            ViewRect = GFxTextDocView::GetViewRect(this: v11, a2: (unsigned int)&v34);
            GFx_RecalculateRectToFit16Bit(a1: (GMatrix2D *)v47[1].M_[1], a2: (int)ViewRect, a3: v27);
            (*(void (__thiscall **)(int, float *))(*(_DWORD *)v2 + 56))(a1: v2, a2: v47[1].M_[1]);
            v56[0] = (int)*(float *)&v34;
            HIWORD(v43) = (int)v35;
            v56[1] = HIWORD(v43);
            v39 = (int)v36;
            v56[2] = v39;
            v56[3] = HIWORD(v43);
            v56[4] = v56[0];
            v57 = (int)v37;
            v59 = v57;
            HIWORD(v50) = HIWORD(v43);
            HIWORD(v51) = HIWORD(v43);
            HIWORD(v52) = v57;
            HIWORD(v54) = HIWORD(v43);
            v13 = *(_DWORD *)(v9 + 200);
            v58 = v39;
            LOWORD(v51) = v39;
            LOWORD(v52) = v39;
            LOWORD(v50) = v56[0];
            v53 = COERCE_FLOAT(__PAIR32__(v57, v56[0]));
            LOWORD(v54) = v56[0];
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 136))(a1: v2, a2: v13);
            (*(void (__thiscall **)(int, _WORD *, int, int, _DWORD))(*(_DWORD *)v2 + 104))(
              a1: v2,
              a2: v56,
              a3: 4,
              a4: 1,
              a5: 0);
            (*(void (__thiscall **)(int, void *, int, int, _DWORD))(*(_DWORD *)v2 + 108))(
              a1: v2,
              a2: &`GFxEditTextCharacter::Display'::`21'::indices,
              a3: 6,
              a4: 1,
              a5: 0);
            (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)v2 + 116))(
              a1: v2,
              a2: 0,
              a3: 0,
              a4: 4,
              a5: 0,
              a6: 2);
            (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 104))(
              a1: v2,
              a2: 0,
              a3: 0,
              a4: 0,
              a5: 0);
            (*(void (__thiscall **)(int, float *, int, int, _DWORD))(*(_DWORD *)v2 + 104))(
              a1: v2,
              a2: &v50,
              a3: 5,
              a4: 1,
              a5: 0);
            (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 128))(a1: v2, a2: *(_DWORD *)(v9 + 204));
            (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v2 + 120))(a1: v2, a2: 0, a3: 4);
            (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 104))(
              a1: v2,
              a2: 0,
              a3: 0,
              a4: 0,
              a5: 0);
            (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 108))(
              a1: v2,
              a2: 0,
              a3: 0,
              a4: 0,
              a5: 0);
          }
          v14 = *(_WORD *)(v9 + 228);
          v38 = (v14 & 0x40) != 0;
          *(_WORD *)(v9 + 228) = v14 & 0xFFBF;
          GFxMovieRoot::IsFocused(this: v31, ch: (GRefCountNTSImpl *)v9, i: v28);
          v15 = context;
          LOBYTE(v40) = v16;
          GFxTextDocView::PreDisplay(
            this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v9 + 188),
            context);
          v17 = *(_DWORD *)(v9 + 256);
          if ( v17 != 0 )
          {
            v18 = 0;
            if ( *(_DWORD *)(v17 + 12) != 0 )
            {
              do
              {
                v49 = v55.M_[0][0];
                v50 = v55.M_[0][1];
                v47[1] = v48;
                v51 = v55.M_[0][2];
                v52 = v55.M_[1][0];
                v53 = v55.M_[1][1];
                v54 = v55.M_[1][2];
                v47[1].M_[2][0] = 0.0;
                v9 = v42;
                v47[1].M_[1][0] = 0.0;
                v19 = *(unsigned __int8 **)(v42 + 256);
                v47[1].M_[0][0] = 0.0;
                v43 = v19[2];
                v47[1].M_[0][1] = (float)v43;
                v43 = v19[1];
                v47[1].M_[1][1] = (float)v43;
                v43 = *v19;
                v47[1].M_[2][1] = (float)v43;
                v20 = *((_DWORD *)v19 + 2);
                v32 = *(float *)(v20 + 8 * v18);
                v43 = *(int *)(v20 + 8 * v18 + 4);
                v21 = *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v42 + 188);
                v51 = v55.M_[0][2] + v55.M_[0][1] * *(float *)&v43 + v55.M_[0][0] * v32;
                v54 = v32 * v55.M_[1][0] + v55.M_[1][1] * *(float *)&v43 + v55.M_[1][2];
                GFxTextDocView::Display(this: v21, context);
                ++v18;
              }
              while ( v18 < *(_DWORD *)(*(_DWORD *)(v9 + 256) + 12) );
              v15 = context;
            }
            if ( *(_DWORD *)(*(_DWORD *)(v9 + 256) + 24) != 0 )
            {
              v22 = 0;
              do
              {
                v23 = *(_DWORD *)(v9 + 256);
                v49 = v55.M_[0][0];
                v50 = v55.M_[0][1];
                v51 = v55.M_[0][2];
                v52 = v55.M_[1][0];
                v53 = v55.M_[1][1];
                v54 = v55.M_[1][2];
                v24 = *(_DWORD *)(v23 + 20);
                v33 = *(float *)(v24 + 8 * v22);
                v42 = *(ScaleformRenderer::VertexShaderType *)(v24 + 8 * v22 + 4);
                v25 = *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v9 + 188);
                v51 = v55.M_[0][2] + v55.M_[0][1] * *(float *)&v42 + v55.M_[0][0] * v33;
                v54 = v33 * v55.M_[1][0] + v55.M_[1][1] * *(float *)&v42 + v55.M_[1][2];
                GFxTextDocView::Display(this: v25, context: v15);
                ++v22;
              }
              while ( v22 < *(_DWORD *)(*(_DWORD *)(v9 + 256) + 24) );
              goto LABEL_30;
            }
          }
          else
          {
            v15[20].Capacity = v9;
          }
          GFxTextDocView::Display(
            this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v9 + 188),
            context: v15);
LABEL_30:
          if ( *(_DWORD *)(*(_DWORD *)(v9 + 188) + 284) != 0 )
          {
            GFxMovieRoot::IsFocused(this: v31, ch: (GRefCountNTSImpl *)v9, i: v29);
            if ( v26 != 0 )
              GFxTextEditorKit::Display(
                this: *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)(*(_DWORD *)(v9 + 188) + 284),
                result: (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::Iterator *)v15);
          }
          if ( LOBYTE(v15[5].Capacity) != 0 )
            (*(void (__thiscall **)(_DWORD, int (__cdecl *)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)))(**(_DWORD **)(v15[18].Capacity + 12) + 92))(
              a1: *(_DWORD *)(v15[18].Capacity + 12),
              a2: v30);
          LOBYTE(v15[5].Capacity) = v44;
          v15[2].Capacity = (unsigned int)v30;
          (*(void (__thiscall **)(ScaleformRenderer::VertexShaderType))(*(_DWORD *)v9 + 276))(a1: v9);
          GFxTextDocView::PostDisplay(
            this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(v9 + 188),
            context: v15);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EEDA0
// Name: public: static void GFxEditTextCharacter::KeyProcessing(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GFxEditTextCharacter::KeyProcessing(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  GASFnCall v3; // eax
  tagALTTABINFO *v4; // edi
  int v5; // eax
  GASValue *v6; // eax
  int v7; // eax
  long double v8; // st7
  int v9; // eax
  GFxTextEditorKit *v10; // edi
  GASValue *v11; // eax
  unsigned __int16 v12; // ax
  GASValue *v13; // eax
  int v14; // eax
  GASValue *v15; // eax
  int v16; // eax
  int v17; // ecx
  unsigned __int16 v18; // si
  int cyItem; // eax
  unsigned int cbSize; // esi
  bool IsOverwriteMode; // al
  _SERVICE_STATUS *v22; // [esp-4h] [ebp-10h]
  _SERVICE_STATUS *v23; // [esp-4h] [ebp-10h]
  _SERVICE_STATUS *v24; // [esp-4h] [ebp-10h]
  _SERVICE_STATUS *v25; // [esp-4h] [ebp-10h]
  struct GFxSpecialKeysState v26; // [esp+Bh] [ebp-1h] BYREF

  v2 = a2;
  v3 = a2[2];
  if ( v3 != nullptr )
    v4 = v3 - 3;
  else
    v4 = nullptr;
  v5 = *(_DWORD *)(v4[4].cyItem + 284);
  if ( v5 != 0 && ((*(_BYTE *)(v5 + 104) & 1) == 0 || (*(_BYTE *)(v5 + 104) & 2) != 0) )
  {
    v22 = (_SERVICE_STATUS *)a2[6];
    v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
    v7 = GASValue::ToInt32(this: v6, a2: (int)v4, a3: a1, a4: v22);
    if ( v7 != 0 )
    {
      v9 = v7 - 1;
      if ( v9 != 0 )
      {
        if ( v9 == 1 )
        {
          v10 = *(GFxTextEditorKit **)(v4[4].cyItem + 284);
          v23 = (_SERVICE_STATUS *)v2[6];
          v11 = (GASValue *)GASFnCall::Arg(this: v2, a2: 1);
          v12 = GASValue::ToInt32(this: v11, a2: (int)v10, a3: v8, a4: v23);
          GFxTextEditorKit::OnChar(this: v10, rv: v12);
        }
      }
      else
      {
        v24 = (_SERVICE_STATUS *)v2[6];
        v13 = (GASValue *)GASFnCall::Arg(this: v2, a2: 1);
        v14 = GASValue::ToInt32(this: v13, a2: (int)v4, a3: v8, a4: v24);
        HIBYTE(a2) = BYTE2(v14) | 0x80;
        GFxTextEditorKit::OnKeyUp(
          this: *(GFxTextEditorKit **)(v4[4].cyItem + 284),
          keyCode: (unsigned __int16)v14,
          a3: (const struct GFxSpecialKeysState *)&a2 + 3);
      }
    }
    else
    {
      v25 = (_SERVICE_STATUS *)v2[6];
      v15 = (GASValue *)GASFnCall::Arg(this: v2, a2: 1);
      v16 = GASValue::ToInt32(this: v15, a2: (int)v4, a3: v8, a4: v25);
      v17 = v16 >> 16;
      v18 = v16;
      cyItem = v4[4].cyItem;
      v26.States = v17 | 0x80;
      GFxTextEditorKit::OnKeyDown(this: *(GFxTextEditorKit **)(cyItem + 284), a2: v18, a3: &v26);
      if ( v18 == 45 )
      {
        cbSize = v4->cbSize;
        IsOverwriteMode = GFxEditTextCharacter::IsOverwriteMode(this: (GFxEditTextCharacter *)v4);
        (*(void (__thiscall **)(tagALTTABINFO *, bool))(cbSize + 392))(a1: v4, a2: !IsOverwriteMode);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EEEE0
// Name: public: struct GFxASCharacter::GeomDataType __near & GFxEditTextCharacter::UpdateAndGetGeomData(struct GFxASCharacter::GeomDataType __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__userpurge GFxEditTextCharacter::UpdateAndGetGeomData@<eax>(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *this@<ecx>,
        double a2@<st0>,
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *gd,
        bool a4)
{
  float *ViewRect; // eax
  double v6; // st6
  double v7; // st7
  double v8; // st6
  double v9; // st7
  unsigned int v11; // [esp+0h] [ebp-30h]
  float v12; // [esp+20h] [ebp-10h]
  float v13; // [esp+24h] [ebp-Ch]

  GFxASCharacter::GetGeomData(this, a2, fX: gd);
  if ( a4 || (*((_WORD *)this + 114) & 0x2000) != 0 )
  {
    ViewRect = (float *)GFxTextDocView::GetViewRect(
                          this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this
                          + 47),
                          a2: v11);
    v12 = *ViewRect;
    v13 = ViewRect[1];
    v6 = v12 * *((float *)this + 17) + v13 * *((float *)this + 18) + *((float *)this + 19);
    v7 = v12 * *((float *)this + 20) + v13 * *((float *)this + 21) + *((float *)this + 22);
    if ( v6 <= 0.0 )
      v8 = v6 - 0.5;
    else
      v8 = v6 + 0.5;
    gd->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)(int)v8;
    if ( v7 <= 0.0 )
      v9 = v7 - 0.5;
    else
      v9 = v7 + 0.5;
    gd->m_nUserID = (int)v9;
    GFxASCharacter::SetGeomData(this, gd);
    *((_WORD *)this + 114) &= ~0x2000u;
  }
  return gd;
}

//------------------------------------------------------------------------------
// Address: 0x100EEFC0
// Name: public: GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>::GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>(class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>::GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax
  int v3; // edx
  int v4; // edx

  result = this;
  v3 = a2[1];
  *this = *a2;
  *(this + 1) = v3;
  v4 = a2[2];
  if ( v4 != 0 )
    ++*(_DWORD *)(v4 + 4);
  *(this + 2) = a2[2];
  *(this + 3) = a2[3];
  *(this + 4) = a2[4];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EF000
// Name: public: class GRangeDataArray<void __near *,class GArrayLH<class GRangeData<void __near *>,2,struct GArrayDefaultPolicy>>::Iterator GRangeDataArray<void __near *,class GArrayLH<class GRangeData<void __near *>,2,struct GArrayDefaultPolicy>>::GetIteratorAt(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int **__thiscall GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::GetIteratorAt(
        unsigned int *this,
        unsigned int **a2,
        int a3)
{
  signed int RangeIndex; // eax
  unsigned int v6; // esi

  RangeIndex = GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::FindRangeIndex(this, a2: a3);
  if ( RangeIndex == -1 )
  {
    *a2 = nullptr;
    a2[1] = (unsigned int *)-1;
    return a2;
  }
  else
  {
    *a2 = this;
    a2[1] = nullptr;
    if ( RangeIndex >= 0 )
    {
      v6 = *(this + 1);
      if ( RangeIndex < v6 )
        a2[1] = (unsigned int *)RangeIndex;
      else
        a2[1] = (unsigned int *)(v6 - 1);
      return a2;
    }
    else
    {
      a2[1] = nullptr;
      return a2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF060
// Name: public: struct GFxTextFilter __near & GFxTextFilter::operator=(struct GFxTextFilter const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFilter::operator=(CDummyTexture *this, int a2)
{
  *(this + 2) = *(CDummyTexture *)(a2 + 8);
  *(this + 3) = *(CDummyTexture *)(a2 + 12);
  *((_BYTE *)this + 16) = *(_BYTE *)(a2 + 16);
  *((_WORD *)this + 9) = *(_WORD *)(a2 + 18);
  *(this + 5) = *(CDummyTexture *)(a2 + 20);
  *((_WORD *)this + 12) = *(_WORD *)(a2 + 24);
  *(this + 7) = *(CDummyTexture *)(a2 + 28);
  *(this + 8) = *(CDummyTexture *)(a2 + 32);
}

//------------------------------------------------------------------------------
// Address: 0x100EF0E0
// Name: public: virtual void GFxEditTextCharacter::GetPosition(class GFxValue::DisplayInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::GetPosition(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *this,
        struct GFxValue::DisplayInfo *a2)
{
  char v3; // al
  long double v4; // [esp+8h] [ebp-8Ch]
  long double v5; // [esp+10h] [ebp-84h]
  long double v6; // [esp+18h] [ebp-7Ch]
  long double v7; // [esp+20h] [ebp-74h]
  long double v8; // [esp+28h] [ebp-6Ch]
  long double v9; // [esp+30h] [ebp-64h]
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> v10; // [esp+38h] [ebp-5Ch] BYREF
  long double v11; // [esp+70h] [ebp-24h]
  long double v12; // [esp+78h] [ebp-1Ch]
  long double v13; // [esp+80h] [ebp-14h]
  long double v14; // [esp+88h] [ebp-Ch]

  GMatrix2D::SetIdentity(this: (float *)&v10.m_Proxy.m_pObject);
  *((double *)&v10.m_Proxy.m_pfnProxied + 1) = 0.0;
  *(double *)&v10.m_Proxy.m_pfnProxied = 100.0;
  v10.m_nUserID = 0;
  *(double *)&v10.CRefCountServiceDestruct<CRefST> = 100.0;
  v10.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = nullptr;
  v12 = 100.0;
  v14 = 0.0;
  v13 = 0.0;
  v11 = 0.0;
  GFxEditTextCharacter::UpdateAndGetGeomData(this, a2: 0.0, gd: &v10, a4: false);
  v5 = (double)(int)v10.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable
     / 20.0;
  v4 = (double)(int)v10.m_nUserID / 20.0;
  v7 = *((double *)&v10.m_Proxy.m_pfnProxied + 1);
  v9 = *(double *)&v10.CRefCountServiceDestruct<CRefST>;
  v8 = *(double *)&v10.m_Proxy.m_pfnProxied;
  v6 = *((float *)this + 15) * 100.0;
  v3 = (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 16))(a1: this);
  a2->X = v5;
  a2->VarsSet |= 0x7FFu;
  a2->Y = v4;
  a2->Visible = v3;
  a2->Rotation = v7;
  a2->XScale = v9;
  a2->YScale = v8;
  a2->Alpha = v6;
  a2->Z = v11;
  a2->XRotation = v13;
  a2->YRotation = v14;
  a2->ZScale = v12;
}

//------------------------------------------------------------------------------
// Address: 0x100EF1E0
// Name: public: virtual bool GFxEditTextCharacter::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge GFxEditTextCharacter::GetMember@<al>(
        GFxEditTextCharacter *this@<ecx>,
        double a2@<st0>,
        struct GASEnvironment *a3,
        CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *result,
        struct GASValue *a5)
{
  CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *StandardMemberConstant; // eax
  double m_nUserID; // st7
  double Length; // st7
  int v10; // ebx
  struct GASStringNode *ConstStringNode; // eax
  struct GASStringNode *v12; // edi
  GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > *v13; // ecx
  _DWORD *v14; // eax
  struct GASStringNode *v15; // edi
  _DWORD *v16; // eax
  struct GASStringNode *v17; // edi
  _DWORD *v18; // eax
  struct GASStringNode *StringNode; // edi
  const char ***v20; // eax
  const char ***v21; // eax
  int v22; // ecx
  char v23; // bl
  GASValue *v24; // ecx
  bool IsSelectable; // bl
  int v26; // eax
  int v27; // edi
  GASStringManager *v28; // ecx
  struct GASStringNode *v29; // ebx
  struct GASStringNode *v30; // edi
  GASStringManager *v31; // ecx
  bool v32; // zf
  unsigned int v33; // eax
  GASStringManager *v34; // ecx
  struct GASStringNode *v35; // edi
  struct GASObject **v36; // edi
  struct GASObject *v37; // edi
  CVTFTexture *v38; // ecx
  const char ***ErrorCode; // eax
  char v40; // bl
  int v41; // eax
  int v42; // edi
  struct GASStringNode *v43; // eax
  struct GASStringNode *v44; // eax
  int v45; // ecx
  int v46; // edx
  GASStringManager *v47; // ecx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v48; // eax
  struct GASStringNode *v49; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v50; // eax
  __int16 v51; // ax
  char v52; // cl
  int v53; // eax
  int v54; // eax
  int v55; // eax
  int v56; // eax
  struct GFxLog *Log; // eax
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v58; // ecx
  int v59; // eax
  int v60; // edi
  unsigned int v61; // [esp+8h] [ebp-80h]
  GString v62; // [esp+14h] [ebp-74h] BYREF
  GString v63; // [esp+18h] [ebp-70h] BYREF
  char v64; // [esp+1Ch] [ebp-6Ch]
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v65; // [esp+20h] [ebp-68h] BYREF
  GString v66; // [esp+24h] [ebp-64h] BYREF
  const char ***v67; // [esp+28h] [ebp-60h] BYREF
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> v68; // [esp+2Ch] [ebp-5Ch] BYREF

  v67 = (const char ***)result;
  v65 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)((char *)this - 120);
  StandardMemberConstant = GFxASCharacter::GetStandardMemberConstant(
                             this: (char *)this - 120,
                             (_IMAGE_SYMBOL_EX *)result);
  switch ( (unsigned int)StandardMemberConstant )
  {
    case 0u:
      GFxASCharacter::GeomDataType::GeomDataType(this: &v68);
      GFxEditTextCharacter::UpdateAndGetGeomData(this: v65, a2, gd: &v68, a4: false);
      m_nUserID = (double)(int)v68.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable;
      goto LABEL_3;
    case 1u:
      GFxASCharacter::GeomDataType::GeomDataType(this: &v68);
      GFxEditTextCharacter::UpdateAndGetGeomData(this: v65, a2, gd: &v68, a4: false);
      m_nUserID = (double)(int)v68.m_nUserID;
LABEL_3:
      Length = m_nUserID / 20.0;
      goto LABEL_4;
    case 0x19u:
      GASValue::DropRefs(this: (GASValue *)a5, a2: (int)this);
      *(_BYTE *)a5 = 0;
      Log = GASEnvironment::GetLog(this: (GASEnvironment *)a3);
      if ( Log != nullptr )
        GFxLogBase<GFxLog>::LogWarning(
          this: v58,
          pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&Log->GFxLogBase<GFxLog>,
          this_4: (int)"Error: Retrieval of the TextField.filters property is not implemented.",
          this_8: v61);
      return true;
    case 0x26u:
      GFxTextDocView::GetText(
        this: *((GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **)this + 17),
        a2: (const GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeRef *)&v66);
      StringNode = GASStringManager::CreateStringNode(
                     this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*v18 & 0xFFFFFFFC) + 8),
                     length: *(_DWORD *)(*v18 & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++*((_DWORD *)StringNode + 2);
      v67 = (const char ***)StringNode;
      GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)&v67);
      v32 = (*((_DWORD *)StringNode + 2))-- == 1;
      if ( v32 )
        GASStringNode::ReleaseNode(a1: (int)StringNode);
      GString::~GString(this: &v66);
      return true;
    case 0x27u:
      GFxTextDocView::GetTextWidth(
        this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17),
        a2: v61);
      *(float *)&v67 = a2;
      *(float *)&v67 = *(float *)&v67 / 20.0;
      v20 = (const char ***)(int)*(float *)&v67;
      v67 = v20;
      Length = (double)(int)v20;
      goto LABEL_4;
    case 0x28u:
      GFxTextDocView::GetTextHeight(
        this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17),
        a2: v61);
      *(float *)&v67 = a2;
      *(float *)&v67 = *(float *)&v67 / 20.0;
      v21 = (const char ***)(int)*(float *)&v67;
      v67 = v21;
      Length = (double)(int)v21;
      goto LABEL_4;
    case 0x29u:
      GASValue::SetInt(
        this: (int)a5,
        result: (tagCOMPAREITEMSTRUCT *)((unsigned __int8)*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 17) + 8) + 28)
                                                            + 32)
                               | (((unsigned __int8)BYTE1(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 17) + 8)
                                                                                + 28)
                                                                    + 32))
                                 | ((unsigned __int8)BYTE2(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 17) + 8)
                                                                                 + 28)
                                                                     + 32)) << 8)) << 8)));
      return true;
    case 0x2Au:
      Length = (double)GFxStyledText::GetLength(this: *(GFxStyledText **)(*((_DWORD *)this + 17) + 8));
      goto LABEL_4;
    case 0x2Bu:
      LOBYTE(v10) = *((_BYTE *)this + 108) >> 1;
      goto LABEL_8;
    case 0x2Cu:
      if ( GFxEditTextCharacter::HasStyleSheet(this: (GFxEditTextCharacter *)v65) )
      {
        ConstStringNode = GASStringManager::CreateStringNode(
                            this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*((_DWORD *)this + 28) & 0xFFFFFFFC) + 8),
                            length: *(_DWORD *)(*((_DWORD *)this + 28) & 0xFFFFFFFC) & 0x7FFFFFFF);
        goto LABEL_11;
      }
      v13 = *((GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **)this + 17);
      if ( (*((_BYTE *)this + 108) & 2) != 0 )
      {
        GFxTextDocView::GetHtml(
          this: v13,
          a2: (const GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeRef *)&v63);
        v15 = GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*v14 & 0xFFFFFFFC) + 8),
                length: *(_DWORD *)(*v14 & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++*((_DWORD *)v15 + 2);
        v67 = (const char ***)v15;
        GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)&v67);
        v32 = (*((_DWORD *)v15 + 2))-- == 1;
        if ( v32 )
          GASStringNode::ReleaseNode(a1: (int)v15);
        GString::~GString(this: &v63);
      }
      else
      {
        GFxTextDocView::GetText(
          this: v13,
          a2: (const GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeRef *)&v62);
        v17 = GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*v16 & 0xFFFFFFFC) + 8),
                length: *(_DWORD *)(*v16 & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++*((_DWORD *)v17 + 2);
        v67 = (const char ***)v17;
        GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)&v67);
        v32 = (*((_DWORD *)v17 + 2))-- == 1;
        if ( v32 )
          GASStringNode::ReleaseNode(a1: (int)v17);
        GString::~GString(this: &v62);
      }
      return true;
    case 0x2Du:
      GASValue::DropRefs(this: (GASValue *)a5, a2: (int)this);
      *(_BYTE *)a5 = 0;
      v36 = *((struct GASObject ***)this + 29);
      if ( v36 != nullptr )
      {
        v37 = *v36;
        if ( v37 != nullptr )
          GASValue::SetAsObject(this: (GASValue *)a5, a2: v37);
      }
      return true;
    case 0x2Eu:
      if ( (*((_BYTE *)this + 108) & 1) == 0 )
      {
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A09D0,
                            a3: 4u,
                            a4: 0);
LABEL_11:
        v12 = ConstStringNode;
        goto LABEL_12;
      }
      v22 = *((_DWORD *)this + 17);
      if ( (*(_BYTE *)(v22 + 332) & 3) != 0 )
      {
        if ( (*(_BYTE *)(v22 + 332) & 3) != 1 )
        {
          if ( (*(_BYTE *)(v22 + 332) & 3) != 2 )
          {
            GASValue::DropRefs(this: (GASValue *)a5, a2: (int)this);
            *(_BYTE *)a5 = 0;
            return true;
          }
          ConstStringNode = GASStringManager::CreateConstStringNode(
                              this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"center",
                              a3: 6u,
                              a4: 0);
          goto LABEL_11;
        }
        v12 = GASStringManager::CreateConstStringNode(
                this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"right",
                a3: 5u,
                a4: 0);
      }
      else
      {
        v12 = GASStringManager::CreateConstStringNode(
                this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"left",
                a3: 4u,
                a4: 0);
      }
LABEL_12:
      ++*((_DWORD *)v12 + 2);
      v67 = (const char ***)v12;
      GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)&v67);
      v32 = (*((_DWORD *)v12 + 2))-- == 1;
      if ( v32 )
        GASStringNode::ReleaseNode(a1: (int)v12);
      return true;
    case 0x2Fu:
      LOBYTE(v10) = *(_BYTE *)(*((_DWORD *)this + 17) + 334) >> 3;
      goto LABEL_8;
    case 0x30u:
      LOBYTE(v10) = *(_BYTE *)(*((_DWORD *)this + 17) + 334) >> 2;
      goto LABEL_8;
    case 0x31u:
      v23 = *((_BYTE *)this + 87);
      goto LABEL_40;
    case 0x32u:
      v24 = (GASValue *)a5;
      if ( *(_DWORD *)(*((_DWORD *)this + 22) + 16) == 0 )
        goto LABEL_72;
      GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)((char *)this + 88));
      return true;
    case 0x33u:
      IsSelectable = GFxEditTextCharacter::IsSelectable(this: (GFxEditTextCharacter *)v65);
      GASValue::DropRefs(this: (GASValue *)a5, a2: (int)this);
      *(_BYTE *)a5 = 2;
      *((_BYTE *)a5 + 4) = IsSelectable;
      return true;
    case 0x34u:
      LOBYTE(v10) = ~(*(_BYTE *)(*((_DWORD *)this + 17) + 334) >> 5);
      goto LABEL_8;
    case 0x35u:
      v34 = *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636);
      if ( (*(_BYTE *)(*((_DWORD *)this + 17) + 334) & 0x40) != 0 )
      {
        v65 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)4;
        v29 = GASStringManager::CreateConstStringNode(
                this: v34,
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"advanced",
                a3: 8u,
                a4: 0);
        ++*((_DWORD *)v29 + 2);
        v67 = (const char ***)v29;
        v35 = v29;
      }
      else
      {
        v65 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)8;
        v35 = GASStringManager::CreateConstStringNode(
                this: v34,
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029DFB4,
                a3: 6u,
                a4: 0);
        ++*((_DWORD *)v35 + 2);
        v67 = (const char ***)v35;
        v29 = v35;
      }
      GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)&v67);
      if ( ((unsigned __int8)v65 & 8) != 0 )
      {
        v65 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)((unsigned int)v65 & 0xFFFFFFF7);
        v32 = (*((_DWORD *)v35 + 2))-- == 1;
        if ( v32 )
          GASStringNode::ReleaseNode(a1: (int)v35);
      }
      v32 = ((unsigned __int8)v65 & 4) == 0;
      goto LABEL_67;
    case 0x36u:
      Length = (double)(GFxTextDocView::GetHScrollOffset(this: *((GFxTextDocView **)this + 17)) / 0x14);
      goto LABEL_4;
    case 0x37u:
      Length = (double)(GFxTextDocView::GetVScrollOffset(this: *((GFxTextDocView **)this + 17)) + 1);
      goto LABEL_4;
    case 0x38u:
      Length = (double)(GFxTextDocView::GetMaxVScroll(this: *((GFxTextDocView **)this + 17)) + 1);
      goto LABEL_4;
    case 0x39u:
      Length = (double)(GFxTextDocView::GetMaxHScroll(this: *((GFxTextDocView **)this + 17)) / 0x14);
      goto LABEL_4;
    case 0x3Au:
      v23 = *((_BYTE *)this + 83);
LABEL_40:
      GASValue::DropRefs(this: (GASValue *)a5, a2: (int)this);
      *(_BYTE *)a5 = 2;
      *((_BYTE *)a5 + 4) = v23 != 0;
      return true;
    case 0x3Bu:
      Length = (double)(*((_DWORD *)this + 20) & 0xFFFFFF);
      goto LABEL_4;
    case 0x3Cu:
      Length = (double)(*((_DWORD *)this + 21) & 0xFFFFFF);
      goto LABEL_4;
    case 0x3Du:
      Length = (double)(GFxTextDocView::GetBottomVScroll(this: *((GFxTextDocView **)this + 17)) + 1);
      goto LABEL_4;
    case 0x3Eu:
      if ( GFxEditTextCharacter::IsReadOnly(this: (GFxEditTextCharacter *)v65) )
      {
        v28 = *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636);
        v65 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)1;
        v29 = GASStringManager::CreateConstStringNode(
                this: v28,
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"dynamic",
                a3: 7u,
                a4: 0);
        ++*((_DWORD *)v29 + 2);
        v67 = (const char ***)v29;
        v30 = v29;
      }
      else
      {
        v31 = *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636);
        v65 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)2;
        v30 = GASStringManager::CreateConstStringNode(
                this: v31,
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"input",
                a3: 5u,
                a4: 0);
        ++*((_DWORD *)v30 + 2);
        v67 = (const char ***)v30;
        v29 = v30;
      }
      GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)&v67);
      if ( ((unsigned __int8)v65 & 2) != 0 )
      {
        v65 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)((unsigned int)v65 & 0xFFFFFFFD);
        v32 = (*((_DWORD *)v30 + 2))-- == 1;
        if ( v32 )
          GASStringNode::ReleaseNode(a1: (int)v30);
      }
      v32 = ((unsigned __int8)v65 & 1) == 0;
LABEL_67:
      if ( !v32 )
      {
        v32 = (*((_DWORD *)v29 + 2))-- == 1;
        if ( v32 )
          GASStringNode::ReleaseNode(a1: (int)v29);
      }
      return true;
    case 0x3Fu:
      v33 = *(_DWORD *)(*((_DWORD *)this + 17) + 272);
      if ( v33 != 0 )
      {
        v66.pData = *(GString::DataDesc **)(*((_DWORD *)this + 17) + 272);
        Length = (double)v33;
        goto LABEL_4;
      }
      v24 = (GASValue *)a5;
LABEL_72:
      GASValue::DropRefs(this: v24, a2: (int)this);
      *(_BYTE *)a5 = 1;
      return true;
    case 0x40u:
      LOBYTE(v10) = *((_BYTE *)this + 108) >> 4;
      goto LABEL_8;
    case 0x41u:
      LOBYTE(v10) = *((_BYTE *)this + 108) >> 7;
      goto LABEL_8;
    case 0x42u:
      LOBYTE(v10) = *((_BYTE *)this + 108) >> 2;
      goto LABEL_8;
    case 0x43u:
      v26 = *((_DWORD *)a3 + 30);
      if ( *(_BYTE *)(v26 + 684) != 1 )
        goto LABEL_190;
      v27 = *((_DWORD *)this + 34);
      if ( v27 != 0 )
        GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)(v27 + 4));
      else
        GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)(v26 + 8));
      return true;
    case 0x44u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      GASValue::SetInt(
        this: (int)a5,
        result: (tagCOMPAREITEMSTRUCT *)(*(_DWORD *)(*((_DWORD *)this + 17) + 316) & 0xFFFFFF));
      return true;
    case 0x45u:
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v65->m_pfnProxied) + 112))(a1: v65)
                                + 120)
                    + 684) != 1 )
        goto LABEL_190;
      v10 = *((_DWORD *)this + 10) >> 11;
      goto LABEL_8;
    case 0x46u:
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v65->m_pfnProxied) + 112))(a1: v65)
                                + 120)
                    + 684) != 1 )
        goto LABEL_190;
      LOBYTE(v10) = *((_BYTE *)this + 108) >> 3;
      goto LABEL_8;
    case 0x47u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      v38 = *(CVTFTexture **)(*((_DWORD *)this + 17) + 284);
      if ( v38 == nullptr )
        goto LABEL_95;
      ErrorCode = (const char ***)GFILEFile::GetErrorCode(this: v38);
      v67 = ErrorCode;
      Length = (double)(int)ErrorCode;
      goto LABEL_93;
    case 0x48u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      Length = (double)GFxTextDocView::GetLinesCount(this: *((GFxTextDocView **)this + 17));
      goto LABEL_4;
    case 0x49u:
      v41 = *((_DWORD *)a3 + 30);
      if ( *(_BYTE *)(v41 + 684) != 1 )
        goto LABEL_190;
      v42 = *((_DWORD *)this + 17);
      if ( (*(_BYTE *)(v42 + 334) & 2) != 0 )
      {
        switch ( (*(unsigned __int8 *)(v42 + 332) >> 2) & 3 )
        {
          case 0:
            v43 = GASStringManager::CreateConstStringNode(
                    this: *(GASStringManager **)(v41 + 636),
                    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A09D0,
                    a3: 4u,
                    a4: 0);
            goto LABEL_145;
          case 1:
            v44 = GASStringManager::CreateConstStringNode(
                    this: *(GASStringManager **)(v41 + 636),
                    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&unk_102A349C,
                    a3: 3u,
                    a4: 0);
            goto LABEL_147;
          case 2:
            ConstStringNode = GASStringManager::CreateConstStringNode(
                                this: *(GASStringManager **)(v41 + 636),
                                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3488.m_Size,
                                a3: 6u,
                                a4: 0);
            goto LABEL_11;
          case 3:
            v43 = GASStringManager::CreateConstStringNode(
                    this: *(GASStringManager **)(v41 + 636),
                    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"center",
                    a3: 6u,
                    a4: 0);
            goto LABEL_145;
        }
      }
LABEL_142:
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: *(GASStringManager **)(v41 + 636),
                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A09D0,
                          a3: 4u,
                          a4: 0);
      goto LABEL_11;
    case 0x4Au:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) == 1 )
      {
        *(float *)&v66.pData = (double)*(unsigned __int16 *)(*((_DWORD *)this + 17) + 330) / 20.0;
        GASValue::SetNumber(this: (GASValue *)a5, a2: *(float *)&v66.pData);
      }
      goto LABEL_190;
    case 0x4Bu:
      v41 = *((_DWORD *)a3 + 30);
      if ( *(_BYTE *)(v41 + 684) != 1 )
        goto LABEL_190;
      switch ( (*(unsigned __int8 *)(*((_DWORD *)this + 17) + 332) >> 2) & 3 )
      {
        case 0:
          goto LABEL_142;
        case 1:
          v43 = GASStringManager::CreateConstStringNode(
                  this: *(GASStringManager **)(v41 + 636),
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&unk_102A349C,
                  a3: 3u,
                  a4: 0);
LABEL_145:
          v12 = v43;
          break;
        case 2:
          v44 = GASStringManager::CreateConstStringNode(
                  this: *(GASStringManager **)(v41 + 636),
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3488.m_Size,
                  a3: 6u,
                  a4: 0);
LABEL_147:
          v12 = v44;
          break;
        case 3:
          ConstStringNode = GASStringManager::CreateConstStringNode(
                              this: *(GASStringManager **)(v41 + 636),
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"center",
                              a3: 6u,
                              a4: 0);
          goto LABEL_11;
      }
      goto LABEL_12;
    case 0x4Cu:
      v45 = *((_DWORD *)a3 + 30);
      if ( *(_BYTE *)(v45 + 684) != 1 )
        goto LABEL_190;
      v46 = *((_DWORD *)this + 17);
      v47 = *(GASStringManager **)(v45 + 636);
      if ( ((*(unsigned __int8 *)(v46 + 332) >> 4) & 3) == 1 )
      {
        v49 = GASStringManager::CreateConstStringNode(
                this: v47,
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3488,
                a3: 6u,
                a4: 0);
      }
      else
      {
        if ( ((*(unsigned __int8 *)(v46 + 332) >> 4) & 3) != 2 )
        {
          v48 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASStringManager::CreateConstStringNode(this: v47, result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A09D0, a3: 4u, a4: 0);
          ++DWORD2(v48->m_pfnProxied);
          v65 = v48;
          GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)&v65);
          goto LABEL_164;
        }
        v49 = GASStringManager::CreateConstStringNode(
                this: v47,
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3488.m_Memory.m_nGrowSize,
                a3: 3u,
                a4: 0);
      }
      ++*((_DWORD *)v49 + 2);
      v65 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v49;
      GASValue::SetString(this: (GASValue *)a5, str: (_IMAGE_SYMBOL_EX *)&v65);
LABEL_164:
      v50 = v65;
      v32 = DWORD2(v65->m_pfnProxied)-- == 1;
      if ( v32 )
        GASStringNode::ReleaseNode(a1: (int)v50);
LABEL_190:
      v59 = *((_DWORD *)this + 36);
      if ( v59 != 0 )
        return (*(bool (__thiscall **)(int, struct GASEnvironment *, const char ***, struct GASValue *))(*(_DWORD *)(v59 + 16) + 16))(
                 a1: v59 + 16,
                 a2: a3,
                 a3: v67,
                 a4: a5);
      if ( a3 != nullptr && *v67 == *(const char ***)(*((_DWORD *)a3 + 30) + 320) )
      {
        GASValue::SetAsObject(this: (GASValue *)a5, a2: *((struct GASObject **)this + 2));
        return true;
      }
      v60 = *((_DWORD *)this + 2);
      if ( v60 != 0
        && (*(unsigned __int8 (__thiscall **)(int, struct GASEnvironment *, const char ***, struct GASValue *))(*(_DWORD *)(v60 + 16) + 16))(
             a1: v60 + 16,
             a2: a3,
             a3: v67,
             a4: a5) != 0 )
      {
        return true;
      }
      if ( GASString::operator==(this: v67, a2: "_global") && a3 != nullptr )
      {
        GASValue::SetAsObject(this: (GASValue *)a5, a2: *(struct GASObject **)(*((_DWORD *)a3 + 30) + 680));
        return true;
      }
      return false;
    case 0x4Du:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      LOBYTE(v51) = *((_BYTE *)this + 109);
      goto LABEL_168;
    case 0x4Eu:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      v51 = *((_WORD *)this + 54) >> 9;
LABEL_168:
      v64 = v51 & 1;
      GASValue::DropRefs(this: (GASValue *)a5, a2: (int)this);
      v52 = v64;
      *(_BYTE *)a5 = 2;
      *((_BYTE *)a5 + 4) = v52;
      goto LABEL_190;
    case 0x4Fu:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      if ( !GFxEditTextCharacter::IsSelectable(this: (GFxEditTextCharacter *)v65)
        || *(_DWORD *)(*((_DWORD *)this + 17) + 284) == 0 )
      {
        goto LABEL_95;
      }
      ErrorCode = (const char ***)(*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v65->m_pfnProxied) + 384))(a1: v65);
      v67 = ErrorCode;
      Length = (double)(int)ErrorCode;
      goto LABEL_93;
    case 0x50u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      if ( GFxEditTextCharacter::IsSelectable(this: (GFxEditTextCharacter *)v65)
        && *(_DWORD *)(*((_DWORD *)this + 17) + 284) != 0 )
      {
        ErrorCode = (const char ***)(*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v65->m_pfnProxied) + 388))(a1: v65);
        v67 = ErrorCode;
        Length = (double)(int)ErrorCode;
LABEL_93:
        if ( (int)ErrorCode < 0 )
          Length = Length + 4294967296.0;
LABEL_4:
        GASValue::SetNumber(this: (GASValue *)a5, a2: Length);
      }
      else
      {
LABEL_95:
        if ( *(_BYTE *)a5 >= 5u )
          GASValue::DropRefs(this: (GASValue *)a5, a2: (int)this);
        *(_BYTE *)a5 = 3;
        *(double *)((char *)a5 + 4) = -1.0;
      }
      return true;
    case 0x51u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      v54 = *(_DWORD *)(*((_DWORD *)this + 17) + 284);
      if ( v54 == 0 )
        goto LABEL_190;
      Length = (double)*(unsigned int *)(v54 + 88);
      goto LABEL_4;
    case 0x52u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      v53 = *(_DWORD *)(*((_DWORD *)this + 17) + 284);
      if ( v53 == 0 )
        goto LABEL_190;
      Length = (double)*(unsigned int *)(v53 + 92);
      goto LABEL_4;
    case 0x53u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      v56 = *(_DWORD *)(*((_DWORD *)this + 17) + 284);
      if ( v56 == 0 )
        goto LABEL_190;
      Length = (double)*(unsigned int *)(v56 + 96);
      goto LABEL_4;
    case 0x54u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      v55 = *(_DWORD *)(*((_DWORD *)this + 17) + 284);
      if ( v55 == 0 )
        goto LABEL_190;
      Length = (double)*(unsigned int *)(v55 + 100);
      goto LABEL_4;
    case 0x55u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      LOWORD(v10) = *((_WORD *)this + 54) >> 10;
      goto LABEL_8;
    case 0x56u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      LOWORD(v10) = *((_WORD *)this + 54) >> 11;
      goto LABEL_8;
    case 0x5Au:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      v40 = *(_BYTE *)(*((_DWORD *)this + 17) + 334) >> 7;
      GASValue::DropRefs(this: (GASValue *)a5, a2: (int)this);
      *(_BYTE *)a5 = 2;
      *((_BYTE *)a5 + 4) = v40;
      return true;
    case 0x5Bu:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      *(float *)&v66.pData = (double)*(unsigned __int8 *)(*((_DWORD *)this + 17) + 296) * 0.0625;
      Length = *(float *)&v66.pData;
      goto LABEL_4;
    case 0x5Cu:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      *(float *)&v66.pData = (double)*(unsigned __int8 *)(*((_DWORD *)this + 17) + 297) * 0.0625;
      Length = *(float *)&v66.pData;
      goto LABEL_4;
    case 0x5Du:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      *(float *)&v66.pData = (double)*(unsigned __int8 *)(*((_DWORD *)this + 17) + 298) * 0.0625;
      Length = *(float *)&v66.pData;
      goto LABEL_4;
    case 0x5Eu:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      Length = (double)*(unsigned __int8 *)(*((_DWORD *)this + 17) + 333);
      goto LABEL_4;
    case 0x5Fu:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      LOBYTE(v10) = *(_BYTE *)(*((_DWORD *)this + 17) + 335);
      goto LABEL_8;
    case 0x60u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      LOBYTE(v10) = *(_BYTE *)(*((_DWORD *)this + 17) + 335) >> 1;
      goto LABEL_8;
    case 0x62u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      *(float *)&v66.pData = (double)*(unsigned __int8 *)(*((_DWORD *)this + 17) + 303) / 255.0;
      Length = *(float *)&v66.pData;
      goto LABEL_4;
    case 0x63u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      *(float *)&v66.pData = (double)*(__int16 *)(*((_DWORD *)this + 17) + 306) / 10.0;
      Length = *(float *)&v66.pData;
      goto LABEL_4;
    case 0x64u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      *(float *)&v66.pData = (double)*(unsigned __int8 *)(*((_DWORD *)this + 17) + 300) * 0.0625;
      Length = *(float *)&v66.pData;
      goto LABEL_4;
    case 0x65u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      *(float *)&v66.pData = (double)*(unsigned __int8 *)(*((_DWORD *)this + 17) + 301) * 0.0625;
      Length = *(float *)&v66.pData;
      goto LABEL_4;
    case 0x66u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      *(float *)&v66.pData = (double)*(__int16 *)(*((_DWORD *)this + 17) + 308) / 20.0;
      Length = *(float *)&v66.pData;
      goto LABEL_4;
    case 0x67u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      LOBYTE(v10) = *(_BYTE *)(*((_DWORD *)this + 17) + 299) >> 6;
      goto LABEL_8;
    case 0x68u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      LOBYTE(v10) = *(_BYTE *)(*((_DWORD *)this + 17) + 299) >> 5;
LABEL_8:
      GASValue::DropRefs(this: (GASValue *)a5, a2: (int)this);
      *(_BYTE *)a5 = 2;
      *((_BYTE *)a5 + 4) = v10 & 1;
      return true;
    case 0x69u:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      Length = (double)((*(char *)(*((_DWORD *)this + 17) + 299) < 0) + 1);
      goto LABEL_4;
    case 0x6Au:
      if ( *(_BYTE *)(*((_DWORD *)a3 + 30) + 684) != 1 )
        goto LABEL_190;
      *(float *)&v66.pData = (double)*(unsigned __int8 *)(*((_DWORD *)this + 17) + 302) * 0.0625;
      Length = *(float *)&v66.pData;
      goto LABEL_4;
    case 0x6Bu:
      goto LABEL_190;
    default:
      if ( (*(unsigned __int8 (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, struct GASValue *, _DWORD))(LODWORD(v65->m_pfnProxied) + 288))(
             a1: v65,
             a2: StandardMemberConstant,
             a3: a5,
             a4: 0) == 0 )
        goto LABEL_190;
      return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0330
// Name: public: virtual void GFxEditTextCharacter::OnEventLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxEditTextCharacter::OnEventLoad(GFxEditTextCharacter *this@<ecx>, long double a2@<st0>)
{
  __vc_attributes::max_isAttribute *v3; // eax
  char v4; // al
  void (__thiscall *v5)(GFxEditTextCharacter *, GASValue *); // edx
  GASValue v6[2]; // [esp+Ch] [ebp-70h] BYREF
  __int16 v7; // [esp+14h] [ebp-68h]
  int v8; // [esp+16h] [ebp-66h]
  char v9; // [esp+1Fh] [ebp-5Dh]
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> v10; // [esp+20h] [ebp-5Ch] BYREF
  double v11; // [esp+58h] [ebp-24h]
  double v12; // [esp+60h] [ebp-1Ch]
  double v13; // [esp+68h] [ebp-14h]
  double v14; // [esp+70h] [ebp-Ch]

  if ( GString::GetLength(this: (GString *)(*((_DWORD *)this + 46) + 72)) != 0 )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 52) + 16) == 0
      || (v3 = (__vc_attributes::max_isAttribute *)(*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 112))(a1: this)) == nullptr
      || (LOBYTE(v6[0]) = 0,
          GASEnvironment::GetVariable(
            this: v3,
            varname: (_IMAGE_SYMBOL_EX *)((char *)this + 208),
            a3: v6,
            retVal: 0,
            paschar: nullptr,
            a6: nullptr,
            a7: 0),
          v9 = v4,
          GASValue::~GASValue(this: v6, a2: (int)this + 208),
          v9 == 0) )
    {
      (*(void (__thiscall **)(GFxEditTextCharacter *, unsigned int, bool, int))(*(_DWORD *)this + 468))(
        a1: this,
        a2: (*(_DWORD *)(*((_DWORD *)this + 46) + 72) & 0xFFFFFFFC) + 8,
        a3: (*((_BYTE *)this + 228) & 2) != 0,
        a4: 1);
      GFxEditTextCharacter::UpdateVariable((GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **)this);
    }
  }
  else
  {
    a2 = ((double (__thiscall *)(GFxEditTextCharacter *, const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *, bool, _DWORD))*(_DWORD *)(*(_DWORD *)this + 468))(
           a1: this,
           a2: &pMem,
           a3: (*((_BYTE *)this + 228) & 2) != 0,
           a4: 0);
  }
  GFxEditTextCharacter::UpdateTextFromVariable(this, a2);
  GFxTextDocView::Format(this: *((GFxTextDocView **)this + 47));
  v5 = *(void (__thiscall **)(GFxEditTextCharacter *, GASValue *))(*(_DWORD *)this + 128);
  v7 = 0;
  v6[0] = (GASValue)1;
  v6[1] = nullptr;
  v8 = 65280;
  v5(a1: this, a2: v6);
  if ( *((_DWORD *)this + 38) == 0 )
  {
    GMatrix2D::SetIdentity(this: (float *)&v10.m_Proxy.m_pObject);
    *((double *)&v10.m_Proxy.m_pfnProxied + 1) = 0.0;
    *(double *)&v10.m_Proxy.m_pfnProxied = 100.0;
    *(double *)&v10.CRefCountServiceDestruct<CRefST> = 100.0;
    v12 = 100.0;
    v10.m_nUserID = 0;
    v10.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = nullptr;
    v14 = 0.0;
    v13 = 0.0;
    v11 = 0.0;
    GFxEditTextCharacter::UpdateAndGetGeomData(
      (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this,
      a2: 0.0,
      gd: &v10,
      a4: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F04C0
// Name: public: void GRangeDataArray<struct GFxEditTextCharacter::CSSHolder::UrlZone,class GArray<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,2,struct GArrayDefaultPolicy>>::ExpandRange(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRangeDataArray<GFxEditTextCharacter::CSSHolder::UrlZone,GArray<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2,GArrayDefaultPolicy>>::ExpandRange(
        int *this,
        int a2,
        int a3)
{
  int v4; // edi
  signed int NearestRangeIndex; // eax
  int v6; // ecx
  int *v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // edx

  v4 = *(this + 1);
  if ( v4 != 0 )
  {
    NearestRangeIndex = GRangeDataArray<GFxEditTextCharacter::CSSHolder::UrlZone,GArray<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(
                          this,
                          a2);
    if ( NearestRangeIndex >= 0 )
    {
      v6 = v4 - 1;
      if ( NearestRangeIndex < (unsigned int)v4 )
        v6 = NearestRangeIndex;
    }
    else
    {
      v6 = 0;
    }
    if ( v6 < v4 )
    {
      v7 = (int *)(*this + 20 * v6);
      if ( v7 != nullptr )
      {
        if ( a2 >= *v7 && (v8 = v7[1], a2 <= v8 + *v7 - 1) || (v8 = v7[1]) + *v7 == a2 )
          v7[1] = a3 + v8;
      }
    }
    v9 = *(this + 1);
    if ( v6 < v9 )
      ++v6;
    v10 = 20 * v6;
    while ( v6 >= 0 && v6 < (unsigned int)v9 )
    {
      *(_DWORD *)(*this + v10) += a3;
      v9 = *(this + 1);
      if ( v6 < v9 )
      {
        ++v6;
        v10 += 20;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0550
// Name: public: class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone> __near & GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>::operator=(class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone> const __near &)
// Source: json
//------------------------------------------------------------------------------
GRefCountNTSImpl **__thiscall GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>::operator=(
        GRefCountNTSImpl **this,
        GRefCountNTSImpl **a2)
{
  GRefCountNTSImpl *v3; // eax
  GRefCountNTSImpl *v4; // ecx

  *this = *a2;
  *(this + 1) = a2[1];
  v3 = a2[2];
  if ( v3 != nullptr )
    ++v3->RefCount;
  v4 = *(this + 2);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  *(this + 2) = a2[2];
  *(this + 3) = a2[3];
  *(this + 4) = a2[4];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F0600
// Name: public: virtual void GFxEditTextCharacter::SetFilters(class GArray<struct GFxFilterDesc,2,struct GArrayDefaultPolicy>)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxEditTextCharacter::SetFilters(void *this, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // esi
  int v6; // edi
  IShaderAPI v8; // [esp+8h] [ebp-24h] BYREF
  int v9; // [esp+Ch] [ebp-20h]
  int v10; // [esp+10h] [ebp-1Ch]
  int v11; // [esp+14h] [ebp-18h]
  char v12; // [esp+18h] [ebp-14h]
  int v13; // [esp+1Ah] [ebp-12h]
  int v14; // [esp+1Eh] [ebp-Eh]
  int v15; // [esp+24h] [ebp-8h]
  int v16; // [esp+28h] [ebp-4h]

  v4 = 0;
  v9 = 1;
  v8.__vftable = (IShaderAPI_vtbl *)&GRefCountBaseNTS<GASGlobalContext,323>::`vftable';
  v10 = -2146435072;
  v11 = -15712192;
  v13 = 5243330;
  v14 = 3735609;
  v15 = 0;
  v16 = 0;
  v12 = 0;
  if ( a3 != 0 )
  {
    v6 = 0;
    do
    {
      GFxTextFilter::LoadFilterDesc(this: (GFxTextFilter *)&v8, a2: (const struct GFxFilterDesc *)(v6 + a2));
      ++v4;
      v6 += 156;
    }
    while ( v4 < a3 );
  }
  (*(void (__thiscall **)(void *, IShaderAPI *))(*(_DWORD *)this + 464))(a1: this, a2: &v8);
  GRefCountImplCore::~GRefCountImplCore(this: &v8);
  return ((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100F06A0
// Name: public: virtual void GFxEditTextCharacter::SetFilters(struct GFxTextFilter const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::SetFilters(GFxEditTextCharacter *this, const struct GFxTextFilter *a2)
{
  CDummyTexture *v2; // eax

  v2 = *((CDummyTexture **)this + 47);
  if ( v2 != nullptr )
    GFxTextFilter::operator=(this: v2 + 72, (int)a2);
}

//------------------------------------------------------------------------------
// Address: 0x100F07E0
// Name: public: GFxEditTextCharacter::ShadowParams::ShadowParams(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
GFxEditTextCharacter::ShadowParams *__thiscall GFxEditTextCharacter::ShadowParams::ShadowParams(
        GFxEditTextCharacter::ShadowParams *this,
        struct GASStringContext *a2)
{
  GFxEditTextCharacter::ShadowParams *result; // eax
  int v3; // ecx

  result = this;
  v3 = *(_DWORD *)(*(_DWORD *)a2 + 8);
  *((_DWORD *)result + 1) = v3;
  ++*(_DWORD *)(v3 + 8);
  *((_DWORD *)result + 2) = 0;
  *((_DWORD *)result + 3) = 0;
  *((_DWORD *)result + 4) = 0;
  *((_DWORD *)result + 5) = 0;
  *((_DWORD *)result + 6) = 0;
  *((_DWORD *)result + 7) = 0;
  *(_DWORD *)result = -16777216;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F0820
// Name: public: virtual void GFxEditTextCharacter::PropagateMouseEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::PropagateMouseEvent(
        GRefCountNTSImpl *this,
        const CMaterialDict::MissingMaterial_t *a2)
{
  ScaleformRenderer *v3; // ebx
  unsigned int m_Id_high; // eax
  GColor *v5; // ebx
  _DWORD *Raw; // eax
  GRefCountNTSImpl *v7; // eax
  _DWORD *v8; // eax
  int v9; // eax
  int v10; // eax
  ScaleformRenderer::VertexDeclType v11; // ebx
  float v12; // eax
  char v13; // al
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // ebx
  ScaleformRenderer::VertexDeclType v18; // ebx
  float v19; // eax
  char v20; // al
  _DWORD *v21; // eax
  int v22; // eax
  int v23; // ebx
  unsigned int v24; // eax
  float v25; // ebx
  _DWORD *v26; // eax
  bool v27; // al
  unsigned int v28; // ebx
  __int16 v29; // ax
  bool v30; // al
  unsigned int v31; // eax
  BOOL v32; // [esp+Ch] [ebp-ACh]
  int v33; // [esp+Ch] [ebp-ACh]
  int v34; // [esp+Ch] [ebp-ACh]
  CCountedStringPoolBase<unsigned int>::hash_item_t v35; // [esp+18h] [ebp-A0h] BYREF
  float v36; // [esp+24h] [ebp-94h]
  int v37[2]; // [esp+28h] [ebp-90h] BYREF
  int v38[2]; // [esp+30h] [ebp-88h] BYREF
  int p[2]; // [esp+38h] [ebp-80h] BYREF
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+40h] [ebp-78h] BYREF
  int v41; // [esp+4Ch] [ebp-6Ch]
  int v42[2]; // [esp+50h] [ebp-68h] BYREF
  int v43; // [esp+58h] [ebp-60h] BYREF
  bool v44[4]; // [esp+5Ch] [ebp-5Ch]
  GRefCountNTSImpl *v45; // [esp+60h] [ebp-58h]
  ScaleformRenderer *v46; // [esp+64h] [ebp-54h]
  float v47; // [esp+68h] [ebp-50h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v48; // [esp+6Ch] [ebp-4Ch] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v49; // [esp+84h] [ebp-34h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v50; // [esp+9Ch] [ebp-1Ch] BYREF

  v3 = (ScaleformRenderer *)((int (__thiscall *)(GRefCountNTSImpl *))this->__vftable[21].dtr_GRefCountImplCore)(a1: this);
  v46 = v3;
  if ( v3 != nullptr )
  {
    if ( *(_DWORD *)&a2->m_Name.m_Id == 8 )
      GFxASCharacter::DoMouseDrag((GFxASCharacter *)this, a2);
    m_Id_high = SHIBYTE(a2[5].m_Name.m_Id);
    if ( m_Id_high < 4 )
      v5 = &v3->m_glyphVertexBuffer[83].color + 9 * m_Id_high;
    else
      v5 = nullptr;
    Raw = (_DWORD *)v5->Raw;
    v45 = nullptr;
    if ( Raw != nullptr )
    {
      if ( Raw[1] != 0 )
      {
        v7 = (GRefCountNTSImpl *)Raw[1];
        v45 = v7;
        if ( v7 != nullptr )
        {
          ++v7->RefCount;
          ++v7->RefCount;
          GRefCountNTSImpl::Release(this: v7);
        }
      }
      else
      {
        if ( (*Raw)-- == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: Raw);
        v5->Raw = 0;
      }
    }
    if ( v45 != this )
    {
      v8 = *((_DWORD **)this + 59);
      if ( v8 != nullptr
        && *v8 != 0
        && (*((_BYTE *)this + 228) & 2) != 0
        && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 47) + 8) + 32) & 1) != 0 )
      {
        GFxEditTextCharacter::ChangeUrlFormat(
          a1: this,
          a2: (int)this,
          a3: 1,
          a4: SHIBYTE(a2[5].m_Name.m_Id),
          a5: nullptr);
        GFxEditTextCharacter::ChangeUrlFormat(
          a1: this,
          a2: (int)this,
          a3: 3,
          a4: SHIBYTE(a2[5].m_Name.m_Id),
          a5: nullptr);
      }
      v9 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
      if ( v9 == 0 || (*(_BYTE *)(v9 + 104) & 0x20) == 0 )
        goto LABEL_68;
    }
    if ( ((unsigned __int8 (__thiscall *)(GRefCountNTSImpl *))this->__vftable[4].dtr_GRefCountImplCore)(a1: this) == 0 )
      goto LABEL_69;
    v10 = *(_DWORD *)&a2->m_Name.m_Id;
    if ( *(_DWORD *)&a2->m_Name.m_Id != 8 )
    {
      if ( v10 == 16 )
      {
        if ( GFxEditTextCharacter::HasStyleSheet((GFxEditTextCharacter *)this)
          && (*((_BYTE *)this + 228) & 2) != 0
          && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 47) + 8) + 32) & 1) != 0 )
        {
          v18 = SHIBYTE(a2[5].m_Name.m_Id);
          GFxMovieRoot::GetMouseState(this: v46, mouseIndex: v18, a3: v32);
          v47 = v19;
          *(_DWORD *)&result.nReferenceCount = 0;
          v41 = 0;
          GFxEditTextCharacter::IsUrlUnderMouseCursor(
            (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this,
            a2: v18,
            a3: nullptr,
            a4: (unsigned int *)&result.nReferenceCount);
          if ( v20 != 0 )
          {
            v21 = *((_DWORD **)this + 59);
            if ( v21 != nullptr && *v21 != 0 && (*(_BYTE *)(LODWORD(v47) + 12) & 1) != 0 )
              GFxEditTextCharacter::ChangeUrlFormat(
                a1: this,
                a2: (int)this,
                a3: 0,
                a4: SHIBYTE(a2[5].m_Name.m_Id),
                a5: (int *)&result.nReferenceCount);
          }
        }
        if ( *(_DWORD *)(*((_DWORD *)this + 47) + 284) != 0 )
        {
          GFxMovieRoot::GetMouseState(
            this: v46,
            mouseIndex: (ScaleformRenderer::VertexDeclType)SHIBYTE(a2[5].m_Name.m_Id),
            a3: v32);
          v23 = v22;
          GMatrix2D::SetIdentity(this: (float *)&v48);
          GFxCharacter::GetWorldMatrix((GFxCharacter *)this, pmat: (CMaterialDict *)&v48);
          v47 = *(float *)(v23 + 24);
          v37[0] = *(int *)(v23 + 20);
          *(float *)&v37[1] = v47;
          GMatrix2D::TransformByInverse(this: &v48, result: &v35, p: (float *)v37, p_4: v34);
          GFxTextEditorKit::OnMouseDown(
            this: *(GFxTextEditorKit **)(*((_DWORD *)this + 47) + 284),
            st: *(float *)&v35.pString,
            en: *(float *)&v35.nNextElement,
            doubleClicked: *(float *)(v23 + 12));
          GFxASCharacter::ModifyOptimizedPlayListLocal<GFxEditTextCharacter>(
            (ScaleformRenderer::VertexShaderType)this,
            result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)v46);
        }
      }
      else if ( v10 == 32 )
      {
        if ( GFxEditTextCharacter::HasStyleSheet((GFxEditTextCharacter *)this)
          && (*((_BYTE *)this + 228) & 2) != 0
          && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 47) + 8) + 32) & 1) != 0 )
        {
          v11 = SHIBYTE(a2[5].m_Name.m_Id);
          GFxMovieRoot::GetMouseState(this: v46, mouseIndex: v11, a3: v32);
          v47 = v12;
          v43 = 0;
          *(float *)v44 = 0.0;
          GFxEditTextCharacter::IsUrlUnderMouseCursor(
            (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this,
            a2: v11,
            a3: nullptr,
            a4: (unsigned int *)&v43);
          if ( v13 != 0 )
          {
            v14 = *((_DWORD **)this + 59);
            if ( v14 != nullptr && *v14 != 0 && (*(_BYTE *)(LODWORD(v47) + 12) & 1) == 0 )
              GFxEditTextCharacter::ChangeUrlFormat(
                a1: this,
                a2: (int)this,
                a3: 1,
                a4: SHIBYTE(a2[5].m_Name.m_Id),
                a5: &v43);
          }
          GFxEditTextCharacter::ChangeUrlFormat(
            a1: this,
            a2: (int)this,
            a3: 1,
            a4: SHIBYTE(a2[5].m_Name.m_Id),
            a5: nullptr);
        }
        if ( *(_DWORD *)(*((_DWORD *)this + 47) + 284) != 0 )
        {
          GFxMovieRoot::GetMouseState(
            this: v46,
            mouseIndex: (ScaleformRenderer::VertexDeclType)SHIBYTE(a2[5].m_Name.m_Id),
            a3: v32);
          v16 = v15;
          GMatrix2D::SetIdentity(this: (float *)&v50);
          GFxCharacter::GetWorldMatrix((GFxCharacter *)this, pmat: (CMaterialDict *)&v50);
          v47 = *(float *)(v16 + 24);
          p[0] = *(int *)(v16 + 20);
          *(float *)&p[1] = v47;
          GMatrix2D::TransformByInverse(this: &v50, &result, (float *)p, p_4: v33);
          GFxTextEditorKit::OnMouseUp(
            this: *(GFxTextEditorKit **)(*((_DWORD *)this + 47) + 284),
            x: *(float *)&result.pString,
            y: *(float *)&result.nNextElement,
            a4: *(_DWORD *)(v16 + 12));
          GFxASCharacter::ModifyOptimizedPlayListLocal<GFxEditTextCharacter>(
            (ScaleformRenderer::VertexShaderType)this,
            result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)v46);
        }
      }
      goto LABEL_68;
    }
    v24 = SHIBYTE(a2[5].m_Name.m_Id);
    if ( v24 < 4 )
    {
      LODWORD(v47) = &v46->m_glyphVertexBuffer[83].color + 9 * v24;
      v25 = v47;
    }
    else
    {
      v25 = 0.0;
      v47 = 0.0;
    }
    if ( *(_DWORD *)(*((_DWORD *)this + 47) + 284) != 0 )
    {
      GMatrix2D::SetIdentity(this: (float *)&v49);
      GFxCharacter::GetWorldMatrix((GFxCharacter *)this, pmat: (CMaterialDict *)&v49);
      *(float *)v44 = *(float *)(LODWORD(v25) + 24);
      v38[0] = *(int *)(LODWORD(v25) + 20);
      v38[1] = *(int *)v44;
      GMatrix2D::TransformByInverse(
        this: &v49,
        result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&v35.nReferenceCount,
        p: (float *)v38,
        p_4: v32);
      GFxTextEditorKit::OnMouseMove(
        this: *(GFxTextEditorKit **)(*((_DWORD *)this + 47) + 284),
        ay: *(float *)&v35.nReferenceCount,
        y: v36);
    }
    v26 = *((_DWORD **)this + 59);
    if ( v26 != nullptr
      && *v26 != 0
      && (*((_BYTE *)this + 228) & 2) != 0
      && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 47) + 8) + 32) & 1) != 0 )
    {
      v42[0] = 0;
      v42[1] = 0;
      GFxEditTextCharacter::IsUrlUnderMouseCursor(
        (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this,
        a2: SHIBYTE(a2[5].m_Name.m_Id),
        a3: nullptr,
        a4: (unsigned int *)v42);
      v44[0] = v27;
      if ( v27 )
      {
        v28 = SHIBYTE(a2[5].m_Name.m_Id);
        if ( !GFxEditTextCharacter::IsUrlTheSame((GFxEditTextCharacter *)this, a2: v28, a3: (const struct GRange *)v42) )
        {
          GFxEditTextCharacter::ChangeUrlFormat(a1: this, a2: (int)this, a3: 1, a4: v28, a5: nullptr);
          GFxEditTextCharacter::ChangeUrlFormat(
            a1: this,
            a2: (int)this,
            a3: 3,
            a4: SHIBYTE(a2[5].m_Name.m_Id),
            a5: nullptr);
        }
        GFxEditTextCharacter::ChangeUrlFormat(
          a1: this,
          a2: (int)this,
          a3: ~(2 * (unsigned __int8)*(_DWORD *)(LODWORD(v47) + 12)) & 2,
          a4: SHIBYTE(a2[5].m_Name.m_Id),
          a5: v42);
      }
      else
      {
        GFxEditTextCharacter::ChangeUrlFormat(
          a1: this,
          a2: (int)this,
          a3: 1,
          a4: SHIBYTE(a2[5].m_Name.m_Id),
          a5: nullptr);
        GFxEditTextCharacter::ChangeUrlFormat(
          a1: this,
          a2: (int)this,
          a3: 3,
          a4: SHIBYTE(a2[5].m_Name.m_Id),
          a5: nullptr);
      }
      GFxEditTextCharacter::SetHandCursor((GFxEditTextCharacter *)this, a2: v44[0]);
    }
    else
    {
      v29 = *((_WORD *)this + 114);
      if ( (v29 & 2) != 0 && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 47) + 8) + 32) & 1) != 0 )
      {
        GFxEditTextCharacter::IsUrlUnderMouseCursor(
          (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this,
          a2: SHIBYTE(a2[5].m_Name.m_Id),
          a3: nullptr,
          a4: nullptr);
        GFxEditTextCharacter::SetHandCursor((GFxEditTextCharacter *)this, a2: v30);
      }
      else
      {
        if ( (v29 & 0x20) == 0 )
        {
LABEL_68:
          ((void (__thiscall *)(GRefCountNTSImpl *, const CMaterialDict::MissingMaterial_t *))this->__vftable[32].dtr_GRefCountImplCore)(
            a1: this,
            a2);
LABEL_69:
          if ( v45 != nullptr )
            GRefCountNTSImpl::Release(this: v45);
          return;
        }
        GFxEditTextCharacter::ChangeUrlFormat(
          a1: this,
          a2: (int)this,
          a3: 3,
          a4: SHIBYTE(a2[5].m_Name.m_Id),
          a5: nullptr);
        *((_WORD *)this + 114) &= ~0x20u;
      }
    }
    v31 = ((int (__thiscall *)(GRefCountNTSImpl *))this->__vftable[87].dtr_GRefCountImplCore)(a1: this);
    GFxMovieRoot::ChangeMouseCursorType(
      this: (IDirect3DVertexDeclaration9 *)v46,
      mouseIdx: (const IDirect3DVertexDeclaration9 *)SHIBYTE(a2[5].m_Name.m_Id),
      newCursorType: v31);
    goto LABEL_68;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0E70
// Name: public: class GASTextFieldObject __near * GFxEditTextCharacter::GetTextFieldASObject(void)
// Source: json
//------------------------------------------------------------------------------
GPtr<GFxAmpServer::SourceFileInfo> *__thiscall GFxEditTextCharacter::GetTextFieldASObject(
        GRefCountWeakSupportImpl *this)
{
  GPtr<GFxAmpServer::SourceFileInfo> *v2; // edi
  _KCRM_MARSHAL_HEADER *v3; // eax
  GPtr<GFxAmpServer::SourceFileInfo> *v4; // edi
  int v5; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 66) != 0 )
    return *((GPtr<GFxAmpServer::SourceFileInfo> **)this + 66);
  v7 = 323;
  v2 = (GPtr<GFxAmpServer::SourceFileInfo> *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                               this: GMemory::pGlobalHeap,
                                               a2: this,
                                               a3: 60,
                                               a4: &v7);
  if ( v2 != nullptr )
  {
    v3 = (_KCRM_MARSHAL_HEADER *)((int (__thiscall *)(GRefCountWeakSupportImpl *))this->__vftable[52].dtr_GRefCountImplCore)(a1: this);
    v4 = GASTextFieldObject::GASTextFieldObject(this: v2, gCtxt: v3, a3: this);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = *((_DWORD *)this + 66);
  if ( v5 != 0 )
    GRefCountBaseGC<323>::Release(a1: v5, a2: (int)v4);
  *((_DWORD *)this + 66) = v4;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100F0EF0
// Name: public: virtual class GASObject __near * GFxEditTextCharacter::GetASObject(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
GPtr<GFxAmpServer::SourceFileInfo> *__thiscall GFxEditTextCharacter::GetASObject(GRefCountWeakSupportImpl *this)
{
  return GFxEditTextCharacter::GetTextFieldASObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F0F00
// Name: public: virtual bool GFxEditTextCharacter::OnKeyEvent(class GFxEventId const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxEditTextCharacter::OnKeyEvent(IDirect3DPixelShader9 *this, const struct GFxEventId *a2, int *a3)
{
  int v4; // eax
  int v5; // ecx
  _DWORD **v6; // esi
  _DWORD *v7; // eax
  GRefCountNTSImpl *v8; // ebx
  int v9; // ebx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v10; // esi
  GASValue *v11; // ecx
  GPtr<IDirect3DPixelShader9> *inserted; // esi
  GRefCountNTSImpl *pObject; // ecx
  GRefCountNTSImpl *v15; // ecx
  GASValue v17[4]; // [esp+Ch] [ebp-48h] BYREF
  GASValue v18[4]; // [esp+1Ch] [ebp-38h] BYREF
  char v19[4]; // [esp+2Ch] [ebp-28h] BYREF
  int v20; // [esp+30h] [ebp-24h]
  GPtr<IDirect3DPixelShader9> v21; // [esp+3Ch] [ebp-18h] BYREF
  int v22; // [esp+40h] [ebp-14h]
  int v23; // [esp+44h] [ebp-10h]
  int v24; // [esp+48h] [ebp-Ch]
  int v25; // [esp+4Ch] [ebp-8h]
  bool v26; // [esp+53h] [ebp-1h]

  v4 = ((int (__thiscall *)(IDirect3DPixelShader9 *))this->__vftable[4].AddRef)(a1: this);
  v5 = *(unsigned __int8 *)(*((char *)a2 + 11) + v4 + 10228);
  v25 = v4;
  v24 = 1 << v5;
  if ( (*(_WORD *)a3 & (unsigned __int16)(1 << v5)) != 0 || v4 == 0 )
    return 0;
  v6 = (_DWORD **)(v4 + 52 * (v5 + 181));
  v7 = *v6;
  v8 = nullptr;
  if ( *v6 != nullptr )
  {
    if ( v7[1] != 0 )
    {
      v8 = (GRefCountNTSImpl *)v7[1];
      if ( v8 != nullptr )
      {
        ++v8->RefCount;
        ++v8->RefCount;
        GRefCountNTSImpl::Release(this: v8);
      }
    }
    else
    {
      if ( (*v7)-- == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
      *v6 = nullptr;
    }
  }
  v26 = v8 == (GRefCountNTSImpl *)this;
  if ( v8 != nullptr )
    GRefCountNTSImpl::Release(this: v8);
  if ( !v26 )
    return 0;
  v9 = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 != 64 && v9 != 128 )
    return 0;
  if ( *(_DWORD *)(*((_DWORD *)this + 47) + 284) != 0
    && (!GFxEditTextCharacter::IsReadOnly((GFxEditTextCharacter *)this)
     || GFxEditTextCharacter::IsSelectable((GFxEditTextCharacter *)this)) )
  {
    v10 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)(*((__int16 *)a2 + 4)
                                                                                    | (*((unsigned __int8 *)a2 + 13) << 16));
    v21.pObject = nullptr;
    v22 = 0;
    v23 = 0;
    if ( v9 == 64 )
    {
      v20 = 0;
      v19[0] = 4;
      GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::PushBack(
        this: &v21,
        a2: (const struct GASValue *)v19);
      v11 = (GASValue *)v19;
    }
    else
    {
      LOBYTE(v18[0]) = 4;
      v18[1] = (GASValue)1;
      GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::PushBack(
        this: &v21,
        a2: (const struct GASValue *)v18);
      v11 = v18;
    }
    GASValue::~GASValue(this: v11, a2: (int)this);
    LOBYTE(v17[0]) = 4;
    v17[1] = v10;
    GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::PushBack(
      this: &v21,
      a2: (const struct GASValue *)v17);
    GASValue::~GASValue(this: v17, a2: (int)this);
    inserted = (GPtr<IDirect3DPixelShader9> *)GFxMovieRoot::ActionQueueType::InsertEntry(
                                                this: v25 + 9224,
                                                result: (const GPoint3<float> *)4);
    inserted[1].pObject = (IDirect3DPixelShader9 *)4;
    ++*((_DWORD *)this + 1);
    pObject = (GRefCountNTSImpl *)inserted[2].pObject;
    if ( pObject != nullptr )
      GRefCountNTSImpl::Release(this: pObject);
    inserted[2].pObject = this;
    v15 = (GRefCountNTSImpl *)inserted[3].pObject;
    if ( v15 != nullptr )
      GRefCountNTSImpl::Release(this: v15);
    inserted[3].pObject = nullptr;
    inserted[11].pObject = (IDirect3DPixelShader9 *)GFxEditTextCharacter::KeyProcessing;
    GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::operator=(
      this: inserted + 12,
      a2: &v21);
    GArray<GASValue,2,GArrayDefaultPolicy>::~GArray<GASValue,2,GArrayDefaultPolicy>(this: &v21);
  }
  *a3 |= (unsigned __int16)v24;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F10E0
// Name: public: virtual bool GFxEditTextCharacter::OnCharEvent(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxEditTextCharacter::OnCharEvent(
        GFxEditTextCharacter *this,
        int (__stdcall *a2)(HWND__ *, unsigned int, unsigned int, int),
        unsigned int a3)
{
  int v4; // eax
  unsigned int *v5; // ecx
  int (__stdcall *v6)(HWND__ *, unsigned int, unsigned int, int); // esi
  unsigned int **IteratorAt; // eax
  const CFileSystemPassThru *v8; // ecx
  int (__stdcall *v9)(HWND__ *, unsigned int, unsigned int, int); // eax
  int (__stdcall *v10)(HWND__ *, unsigned int, unsigned int, int); // ebx
  const CFileSystemPassThru *v11; // ecx
  int (__stdcall *v12)(HWND__ *, unsigned int, unsigned int, int); // eax
  int *v13; // eax
  const wchar_t *lpszClassName; // ebx
  GPtr<IDirect3DPixelShader9> *inserted; // esi
  GRefCountNTSImpl *pObject; // ecx
  GRefCountNTSImpl *v18; // ecx
  tagWNDCLASSW v19; // [esp+Ch] [ebp-44h] BYREF
  int v20; // [esp+34h] [ebp-1Ch]
  unsigned int *v21; // [esp+38h] [ebp-18h] BYREF
  unsigned int *v22; // [esp+40h] [ebp-10h] BYREF
  int v23; // [esp+48h] [ebp-8h]

  v23 = (*(int (__thiscall **)(GFxEditTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
  if ( v23 != 0 )
  {
    v4 = *(_DWORD *)(*((_DWORD *)this + 47) + 284);
    if ( v4 != 0 && ((*(_BYTE *)(v4 + 104) & 1) == 0 || (*(_BYTE *)(v4 + 104) & 2) != 0) && *((_DWORD *)this + 67) == a3 )
    {
      v5 = *((unsigned int **)this + 65);
      v6 = a2;
      if ( v5 != nullptr )
      {
        IteratorAt = GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::GetIteratorAt(
                       this: v5,
                       a2: &v22,
                       a3: (int)a2);
        v8 = (const CFileSystemPassThru *)IteratorAt[1];
        if ( (int)v8 < 0 || (unsigned int)v8 >= (*IteratorAt)[1] )
        {
          G_towupper(charCode: v8, charCodea: (wchar_t)a2);
          v10 = v9;
          G_towlower(charCode: v11, charCodea: (wchar_t)a2);
          v6 = v10;
          if ( a2 == v10 )
            v6 = v12;
          v13 = (int *)GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::GetIteratorAt(
                         this: *((unsigned int **)this + 65),
                         a2: &v21,
                         a3: (int)v6);
          if ( GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: v13) )
            return 0;
        }
      }
      v19.lpszMenuName = nullptr;
      v19.lpszClassName = nullptr;
      v20 = 0;
      LOBYTE(v19.hInstance) = 4;
      v19.hIcon = (HICON__ *)2;
      GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: (GPtr<IDirect3DPixelShader9> *)&v19.lpszMenuName,
        pheapAddr: (ButtonCode_t)&v19.lpszMenuName,
        newSize: 1u);
      lpszClassName = v19.lpszClassName;
      if ( &v19.lpszMenuName[8 * (int)v19.lpszClassName] != (const wchar_t *)16 )
        GASValue::GASValue(
          this: (GASValue *)&v19.lpszMenuName[8 * (int)v19.lpszClassName - 8],
          v: (tagWNDCLASSW *)&v19.hInstance);
      GASValue::~GASValue(this: (GASValue *)&v19.hInstance, a2: (int)this);
      LOBYTE(v19.style) = 4;
      v19.lpfnWndProc = v6;
      GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: (GPtr<IDirect3DPixelShader9> *)&v19.lpszMenuName,
        pheapAddr: (ButtonCode_t)&v19.lpszMenuName,
        newSize: (unsigned int)lpszClassName + 1);
      if ( &v19.lpszMenuName[8 * (int)v19.lpszClassName] != (const wchar_t *)16 )
        GASValue::GASValue(this: (GASValue *)&v19.lpszMenuName[8 * (int)v19.lpszClassName - 8], v: &v19);
      GASValue::~GASValue(this: (GASValue *)&v19, a2: (int)this);
      inserted = (GPtr<IDirect3DPixelShader9> *)GFxMovieRoot::ActionQueueType::InsertEntry(
                                                  this: v23 + 9224,
                                                  result: (const GPoint3<float> *)4);
      inserted[1].pObject = (IDirect3DPixelShader9 *)4;
      ++*((_DWORD *)this + 1);
      pObject = (GRefCountNTSImpl *)inserted[2].pObject;
      if ( pObject != nullptr )
        GRefCountNTSImpl::Release(this: pObject);
      inserted[2].pObject = (IDirect3DPixelShader9 *)this;
      v18 = (GRefCountNTSImpl *)inserted[3].pObject;
      if ( v18 != nullptr )
        GRefCountNTSImpl::Release(this: v18);
      inserted[3].pObject = nullptr;
      inserted[11].pObject = (IDirect3DPixelShader9 *)GFxEditTextCharacter::KeyProcessing;
      GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::operator=(
        this: inserted + 12,
        a2: &v19.lpszMenuName);
      GArray<GASValue,2,GArrayDefaultPolicy>::~GArray<GASValue,2,GArrayDefaultPolicy>(this: (GPtr<IDirect3DPixelShader9> *)&v19.lpszMenuName);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F1320
// Name: public: void GRangeDataArray<void __near *,class GArrayLH<class GRangeData<void __near *>,2,struct GArrayDefaultPolicy>>::SetRange(class GRangeData<void __near *> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::SetRange(
        GFxZlibSupportBase *this,
        const GetTriangles_Vertex_t **a2)
{
  volatile unsigned int RefCount; // edi
  const GetTriangles_Vertex_t *v4; // ebx
  int v5; // eax
  signed int v6; // edi
  int v7; // ecx
  int v8; // eax
  const GetTriangles_Vertex_t **v9; // ebx
  const GetTriangles_Vertex_t *v10; // edx
  int v11; // eax
  GFxZlibSupportBase_vtbl *v12; // eax
  unsigned int v13; // edx
  int v14; // eax
  int v15; // ebx
  volatile int v16; // eax
  int v17; // ebx
  volatile int v18; // eax
  GFxZlibSupportBase_vtbl *v19; // eax
  unsigned int v20; // eax
  const GetTriangles_Vertex_t *v21; // edx
  unsigned int v22; // edx
  int v23; // eax
  int v24; // ebx
  int v25; // ecx
  _DWORD *v26; // eax
  volatile int v27; // eax
  const GetTriangles_Vertex_t *v28; // ecx
  const GetTriangles_Vertex_t *v29; // edx
  GFxZlibSupportBase_vtbl *v30; // eax
  GFile *(__thiscall *v31)(GFxZlibSupportBase *, GFile *); // ecx
  GFile *(__thiscall *CreateZlibFile)(GFxZlibSupportBase *, GFile *); // edx
  int v33; // edi
  unsigned int v34; // eax
  unsigned int *v35; // esi
  _DWORD *v36; // ecx
  int v37; // ecx
  int v38; // eax
  int v39; // ebx
  _DWORD *v40; // edx
  int v41; // ecx
  int v42; // [esp+8h] [ebp-20h]
  void (__thiscall *v43)(struct GFxZlibSupportBase *); // [esp+8h] [ebp-20h]
  unsigned int v44; // [esp+Ch] [ebp-1Ch]
  void (__thiscall *v45)(GFxZlibSupportBase *, struct GFxStream *, void *, int); // [esp+10h] [ebp-18h]
  unsigned int *v46; // [esp+14h] [ebp-14h] BYREF
  signed int v47; // [esp+18h] [ebp-10h]
  unsigned int *v48; // [esp+1Ch] [ebp-Ch]
  int v49; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  RefCount = this->RefCount;
  if ( RefCount == 0 )
  {
    GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::InsertAt(
      (unsigned int *)this,
      a2: 0,
      a3: a2);
    return;
  }
  v4 = *a2;
  GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(
    this,
    index: (int)*a2);
  v46 = (unsigned int *)this;
  if ( v5 >= 0 )
  {
    if ( v5 < RefCount )
      v6 = v5;
    else
      v6 = RefCount - 1;
  }
  else
  {
    v6 = 0;
  }
  i = 12 * v6;
  v7 = (int)&this->__vftable[v6];
  v47 = v6;
  v8 = *(_DWORD *)v7;
  if ( (int)v4 < *(_DWORD *)v7 || (v49 = (int)a2[1] + (_DWORD)v4) - 1 > *(_DWORD *)(v7 + 4) + v8 - 1 )
  {
    if ( (int)v4 < *(_DWORD *)v7 || (v22 = *(_DWORD *)(v7 + 4), (int)v4 > (int)(v22 + *(_DWORD *)v7 - 1)) )
    {
      GRange::CompareTo(this: (GetTriangles_Vertex_t *)v7, index: v4);
      if ( v23 <= 0 )
      {
        v24 = v6 + 1;
        GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::InsertAt(
          (unsigned int *)this,
          a2: v6 + 1,
          a3: a2);
        if ( v6 < this->RefCount )
        {
          ++v6;
          v47 = v24;
        }
        v48 = v46;
      }
      else
      {
        GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::InsertAt(
          (unsigned int *)this,
          a2: v6,
          a3: a2);
        v48 = v46;
      }
      v49 = v6;
    }
    else
    {
      if ( *(_DWORD *)v7 + v22 - (unsigned int)v4 <= v22 )
        *(_DWORD *)(v7 + 4) = (char *)v4 - *(_DWORD *)v7;
      else
        *(_DWORD *)(v7 + 4) = 0;
      if ( v6 < this->RefCount )
        v47 = ++v6;
      v48 = v46;
      v49 = v6;
      GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::InsertAt(
        (unsigned int *)this,
        a2: v6,
        a3: a2);
    }
    if ( v6 >= this->RefCount )
      goto LABEL_55;
    ++v6;
    goto LABEL_54;
  }
  if ( *(const GetTriangles_Vertex_t **)v7 != v4 )
  {
    if ( *(_DWORD *)v7 + *(_DWORD *)(v7 + 4) <= v49 )
    {
      v9 = a2;
      v20 = *(_DWORD *)(v7 + 4);
      v21 = a2[1];
      if ( (unsigned int)v21 <= v20 )
        *(_DWORD *)(v7 + 4) = v20 - (_DWORD)v21;
      else
        *(_DWORD *)(v7 + 4) = 0;
      if ( v6 < this->RefCount )
        v47 = ++v6;
      v48 = v46;
      v49 = v6;
      GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::InsertAt(
        (unsigned int *)this,
        a2: v6,
        a3: a2);
      if ( v6 < this->RefCount )
      {
        v47 = ++v6;
        goto LABEL_56;
      }
      goto LABEL_55;
    }
    v13 = *(_DWORD *)(v7 + 4);
    v42 = *(_DWORD *)v7;
    v45 = *(void (__thiscall **)(GFxZlibSupportBase *, struct GFxStream *, void *, int))(v7 + 8);
    if ( *(_DWORD *)v7 + v13 - (unsigned int)v4 <= v13 )
      *(_DWORD *)(v7 + 4) = (char *)v4 - *(_DWORD *)v7;
    else
      *(_DWORD *)(v7 + 4) = 0;
    v14 = (int)a2[1] + (unsigned int)this->__vftable[i / 0xCu].CreateZlibFile;
    if ( v14 > (int)v13 )
      v14 = v13;
    v43 = (void (__thiscall *)(struct GFxZlibSupportBase *))(v14 + v42);
    v15 = v6 + 1;
    v44 = v13 - v14;
    GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::InsertAt(
      (unsigned int *)this,
      a2: v6 + 1,
      a3: a2);
    v16 = this->RefCount;
    if ( v6 < v16 )
    {
      ++v6;
      v47 = v15;
    }
    v48 = v46;
    v49 = v6;
    v17 = v6 + 1;
    GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>::Resize(
      (unsigned int *)this,
      a2: v16 + 1);
    v18 = this->RefCount;
    if ( v6 + 1 < (unsigned int)(v18 - 1) )
      memmove(
        dst: (unsigned __int8 *)&this->__vftable[v17 + 1],
        src: (unsigned __int8 *)&this->__vftable[v17],
        count: 4 * (3 * (v18 - v17) - 3));
    v19 = &this->__vftable[v17];
    if ( v19 != nullptr )
    {
      v19->dtr_GRefCountImplCore = v43;
      v19->CreateZlibFile = (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))v44;
      v19->InflateWrapper = v45;
    }
    if ( v6 >= this->RefCount )
    {
LABEL_55:
      v9 = a2;
      goto LABEL_56;
    }
    ++v6;
LABEL_54:
    v47 = v6;
    goto LABEL_55;
  }
  v9 = a2;
  v10 = a2[1];
  v11 = *(_DWORD *)(v7 + 4);
  if ( (int)v10 > v11 )
    v10 = *(const GetTriangles_Vertex_t **)(v7 + 4);
  *(_DWORD *)v7 += v10;
  *(_DWORD *)(v7 + 4) = v11 - (_DWORD)v10;
  v12 = &this->__vftable[i / 0xCu];
  if ( v12->CreateZlibFile != nullptr )
  {
    GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::InsertAt(
      (unsigned int *)this,
      a2: v6,
      a3: a2);
  }
  else
  {
    v12->dtr_GRefCountImplCore = (void (__thiscall *)(struct GFxZlibSupportBase *))*a2;
    v12->CreateZlibFile = (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))a2[1];
    v12->InflateWrapper = (void (__thiscall *)(GFxZlibSupportBase *, struct GFxStream *, void *, int))a2[2];
  }
  v48 = v46;
  v49 = v6;
  if ( v6 < this->RefCount )
    v47 = ++v6;
LABEL_56:
  if ( !GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: (int *)&v46) )
  {
    v25 = 12 * v6;
    for ( i = 12 * v6; ; v25 = i )
    {
      v26 = (void (__thiscall **)(struct GFxZlibSupportBase *))((char *)&this->dtr_GRefCountImplCore + v25);
      if ( *v26 < (int)*v9 )
        break;
      if ( v26[1] + *v26 - 1 > (int)*v9 + (int)v9[1] - 1 )
        goto LABEL_67;
      if ( v6 >= 0 && (unsigned int)v6 < this->RefCount )
      {
        v27 = this->RefCount;
        if ( v27 == 1 )
        {
          GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>::Resize(
            (unsigned int *)this,
            a2: 0);
        }
        else
        {
          memmove(
            dst: (unsigned __int8 *)&this->__vftable[i / 0xCu],
            src: (unsigned __int8 *)&this->__vftable[i / 0xCu + 1],
            count: 4 * (3 * (v27 - v6) - 3));
          --this->RefCount;
        }
      }
      if ( GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: (int *)&v46) )
      {
LABEL_67:
        v9 = a2;
        break;
      }
      v9 = a2;
    }
  }
  if ( v6 >= 0 && (unsigned int)v6 < this->RefCount )
  {
    v28 = v9[1];
    v29 = *v9;
    v30 = &this->__vftable[v6];
    if ( (int)*v9 + (int)v28 - 1 >= (int)v30->dtr_GRefCountImplCore
      && (int)v29 + (int)v28 - 1 <= (int)((int)v30->CreateZlibFile + (unsigned int)v30->dtr_GRefCountImplCore - 1) )
    {
      v31 = (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))((char *)v29
                                                                 + (char *)v28
                                                                 - (char *)v30->dtr_GRefCountImplCore);
      CreateZlibFile = v30->CreateZlibFile;
      if ( (int)v31 > (int)CreateZlibFile )
        v31 = v30->CreateZlibFile;
      v30->dtr_GRefCountImplCore = (void (__thiscall *)(struct GFxZlibSupportBase *))((char *)v30->dtr_GRefCountImplCore
                                                                                    + (unsigned int)v31);
      v30->CreateZlibFile = (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))((char *)CreateZlibFile - (char *)v31);
    }
  }
  v33 = v49;
  v47 = v49;
  if ( v49 < 0 )
    goto LABEL_85;
  v34 = v49 - 1;
  v47 = v49 - 1;
  if ( v49 - 1 < 0 )
    goto LABEL_85;
  v35 = v48;
  if ( v34 < v48[1] )
  {
    v36 = (_DWORD *)(*v48 + 12 * v34);
    if ( v36[1] == 0 )
    {
      GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::RemoveAt(
        this: v48,
        a2: v49 - 1);
      goto LABEL_86;
    }
    if ( (const GetTriangles_Vertex_t *)(*v36 + v36[1]) != *v9 || v36[2] != *(_DWORD *)(*v48 + 12 * v49 + 8) )
      goto LABEL_86;
    *(_DWORD *)(*v48 + 12 * v34 + 4) += v9[1];
    if ( v33 < v35[1] )
      GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::RemoveAt(
        this: v35,
        a2: v33);
    v48 = v35;
    v49 = v47;
    v33 = v47;
LABEL_85:
    v35 = v48;
  }
LABEL_86:
  v37 = v35[1];
  v38 = v33;
  if ( v33 < v37 )
    v38 = v33 + 1;
  if ( v38 >= 0 && v38 < (unsigned int)v37 )
  {
    v39 = *(_DWORD *)(*v35 + 12 * v38 + 4);
    v40 = (_DWORD *)(*v35 + 12 * v38);
    if ( v39 == 0
      || *(_DWORD *)(v41 = *v35 + 12 * v33) + *(_DWORD *)(v41 + 4) == *v40
      && *(_DWORD *)(v41 + 8) == v40[2]
      && (*(_DWORD *)(v41 + 4) += v39, v38 < v35[1]) )
    {
      GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::RemoveAt(
        this: v35,
        a2: v38);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1740
// Name: public: void GRangeDataArray<void __near *,class GArrayLH<class GRangeData<void __near *>,2,struct GArrayDefaultPolicy>>::ClearRange(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::ClearRange(
        GFxZlibSupportBase *this,
        GetTriangles_Vertex_t *index,
        char *a3)
{
  volatile unsigned int RefCount; // edi
  const GetTriangles_Vertex_t *v5; // ebx
  int v6; // eax
  int v7; // edi
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  unsigned int v13; // ebx
  char *v14; // eax
  GFile *(__thiscall *v15)(GFxZlibSupportBase *, GFile *); // ebx
  volatile int v16; // eax
  volatile int v17; // eax
  GFxZlibSupportBase_vtbl *v18; // eax
  bool v19; // cc
  int i; // edx
  unsigned int v21; // eax
  volatile int v22; // eax
  unsigned int v23; // edx
  volatile int v24; // eax
  void (__thiscall *dtr_GRefCountImplCore)(struct GFxZlibSupportBase *); // ecx
  volatile int v26; // eax
  GFxZlibSupportBase_vtbl *v27; // eax
  int v28; // ecx
  GFile *(__thiscall *CreateZlibFile)(GFxZlibSupportBase *, GFile *); // esi
  GFile *(__thiscall *v30)(GFxZlibSupportBase *, GFile *); // ebx
  int v31; // [esp+8h] [ebp-18h]
  void (__thiscall *v32)(struct GFxZlibSupportBase *); // [esp+8h] [ebp-18h]
  void (__thiscall *v33)(GFxZlibSupportBase *, struct GFxStream *, void *, int); // [esp+10h] [ebp-10h]
  GFxZlibSupportBase *v34; // [esp+14h] [ebp-Ch] BYREF
  int v35; // [esp+18h] [ebp-8h]
  char *v36; // [esp+1Ch] [ebp-4h]

  RefCount = this->RefCount;
  if ( RefCount == 0 )
    return;
  v5 = index;
  GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(this, (int)index);
  v34 = this;
  if ( v6 >= 0 )
  {
    if ( v6 < RefCount )
      v7 = v6;
    else
      v7 = RefCount - 1;
  }
  else
  {
    v7 = 0;
  }
  v35 = v7;
  if ( a3 == (char *)-1 )
    a3 = (char *)(0x7FFFFFFF - (_DWORD)index);
  v8 = v7;
  v9 = (int)&this->__vftable[v7];
  if ( (int)index < *(_DWORD *)v9 )
    goto LABEL_42;
  v10 = *(_DWORD *)v9;
  v36 = (char *)index + (_DWORD)a3;
  if ( (int)index + (int)a3 - 1 > *(_DWORD *)(v9 + 4) + v10 - 1 )
  {
    v5 = index;
LABEL_42:
    if ( (int)v5 < *(_DWORD *)v9 || (v23 = *(_DWORD *)(v9 + 4), (int)v5 > (int)(v23 + *(_DWORD *)v9 - 1)) )
    {
      GRange::CompareTo(this: (GetTriangles_Vertex_t *)v9, index: v5);
      if ( v7 < this->RefCount )
        v35 = ++v7;
    }
    else
    {
      if ( *(_DWORD *)v9 + v23 - (unsigned int)v5 <= v23 )
        *(_DWORD *)(v9 + 4) = (char *)v5 - *(_DWORD *)v9;
      else
        *(_DWORD *)(v9 + 4) = 0;
      v24 = this->RefCount;
      if ( v7 < v24 )
      {
        v35 = ++v7;
        if ( v7 < v24 )
          v35 = ++v7;
      }
    }
    goto LABEL_34;
  }
  v11 = *(_DWORD *)(v9 + 4);
  if ( *(GetTriangles_Vertex_t **)v9 == index )
  {
    v36 = a3;
    v12 = v11;
    if ( (int)a3 <= v11 )
      v12 = (int)v36;
    *(_DWORD *)v9 += v12;
    *(_DWORD *)(v9 + 4) = v11 - v12;
    if ( this->__vftable[v8].CreateZlibFile == nullptr )
    {
      if ( v7 >= 0 && (unsigned int)v7 < this->RefCount )
        GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::RemoveAt(
          (unsigned int *)this,
          a2: v7);
      goto LABEL_33;
    }
    goto LABEL_30;
  }
  if ( *(_DWORD *)v9 + v11 > (int)v36 )
  {
    v13 = *(_DWORD *)(v9 + 4);
    v31 = *(_DWORD *)v9;
    v33 = *(void (__thiscall **)(GFxZlibSupportBase *, struct GFxStream *, void *, int))(v9 + 8);
    if ( *(_DWORD *)v9 + v13 - (unsigned int)index <= v13 )
      *(_DWORD *)(v9 + 4) = (char *)index - *(_DWORD *)v9;
    else
      *(_DWORD *)(v9 + 4) = 0;
    v14 = &a3[(unsigned int)this->__vftable[v8].CreateZlibFile];
    if ( (int)v14 > (int)v13 )
      v14 = (char *)v13;
    v32 = (void (__thiscall *)(struct GFxZlibSupportBase *))&v14[v31];
    v15 = (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))(v13 - (_DWORD)v14);
    v16 = this->RefCount;
    if ( v7 < v16 )
      v35 = ++v7;
    GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>::Resize(
      (unsigned int *)this,
      a2: v16 + 1);
    v17 = this->RefCount;
    if ( v7 < (unsigned int)(v17 - 1) )
      memmove(
        dst: (unsigned __int8 *)&this->__vftable[v7 + 1],
        src: (unsigned __int8 *)&this->__vftable[v7],
        count: 4 * (3 * (v17 - v7) - 3));
    v18 = &this->__vftable[v7];
    if ( v18 != nullptr )
    {
      v18->dtr_GRefCountImplCore = v32;
      v18->CreateZlibFile = v15;
      v18->InflateWrapper = v33;
    }
LABEL_30:
    v19 = v7 < this->RefCount;
    goto LABEL_31;
  }
  v21 = *(_DWORD *)(v9 + 4);
  if ( (unsigned int)a3 <= v21 )
    *(_DWORD *)(v9 + 4) = v21 - (_DWORD)a3;
  else
    *(_DWORD *)(v9 + 4) = 0;
  v22 = this->RefCount;
  if ( v7 < v22 )
  {
    v35 = ++v7;
    v19 = v7 < v22;
LABEL_31:
    if ( v19 )
      v35 = ++v7;
  }
LABEL_33:
  v5 = index;
LABEL_34:
  if ( !GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: (int *)&v34) )
  {
    for ( i = v7; ; i = v7 )
    {
      dtr_GRefCountImplCore = this->__vftable[i].dtr_GRefCountImplCore;
      if ( (int)dtr_GRefCountImplCore < (int)v5
        || (int)((int)this->__vftable[i].CreateZlibFile + (unsigned int)dtr_GRefCountImplCore - 1) > (int)&a3[(int)v5 - 1] )
      {
        break;
      }
      if ( v7 >= 0 && (unsigned int)v7 < this->RefCount )
      {
        v26 = this->RefCount;
        if ( v26 == 1 )
        {
          GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>::Resize(
            (unsigned int *)this,
            a2: 0);
        }
        else
        {
          memmove(
            dst: (unsigned __int8 *)&this->__vftable[i],
            src: (unsigned __int8 *)&this->__vftable[i + 1],
            count: 4 * (3 * (v26 - v7) - 3));
          --this->RefCount;
        }
      }
      if ( GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: (int *)&v34) )
        break;
    }
  }
  if ( v7 >= 0 && (unsigned int)v7 < this->RefCount )
  {
    v27 = &this->__vftable[v7];
    v28 = (int)&a3[(_DWORD)v5 - 1];
    if ( v28 >= (int)v27->dtr_GRefCountImplCore )
    {
      CreateZlibFile = v27->CreateZlibFile;
      if ( v28 <= (int)((int)CreateZlibFile + (unsigned int)v27->dtr_GRefCountImplCore - 1) )
      {
        v30 = (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))&a3[(char *)v5 - (char *)v27->dtr_GRefCountImplCore];
        if ( (int)v30 > (int)CreateZlibFile )
          v30 = v27->CreateZlibFile;
        v27->dtr_GRefCountImplCore = (void (__thiscall *)(struct GFxZlibSupportBase *))((char *)v27->dtr_GRefCountImplCore
                                                                                      + (unsigned int)v30);
        v27->CreateZlibFile = (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))((char *)CreateZlibFile - (char *)v30);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1A70
// Name: public: bool GFxEditTextCharacter::ParseRestrict(class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxEditTextCharacter::ParseRestrict(
        GFxEditTextCharacter *this,
        bool (__cdecl ***a2)(const char *const *, const char *const *))
{
  void **v3; // esi
  GetTriangles_Vertex_t *v4; // ebx
  _DWORD *v5; // eax
  bool (__cdecl **v7)(const char *const *, const char *const *); // eax
  GetTriangles_Vertex_t *v8; // esi
  unsigned int Char; // eax
  unsigned int v10; // edi
  GFxZlibSupportBase *v11; // ecx
  GFxEditTextCharacter *v12; // ebx
  GFxZlibSupportBase *v13; // ecx
  const GetTriangles_Vertex_t *v14[3]; // [esp+Ch] [ebp-24h] BYREF
  const GetTriangles_Vertex_t *v15[3]; // [esp+18h] [ebp-18h] BYREF
  unsigned int v16; // [esp+24h] [ebp-Ch] BYREF
  GFxEditTextCharacter *v17; // [esp+28h] [ebp-8h]
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+2Ch] [ebp-4h] BYREF
  bool v19; // [esp+3Bh] [ebp+Bh]

  v3 = *((void ***)this + 65);
  v4 = nullptr;
  v17 = this;
  if ( v3 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v3);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  }
  v16 = 323;
  v5 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 12, a3: &v16);
  if ( v5 != nullptr )
  {
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
  }
  else
  {
    v5 = nullptr;
  }
  *((_DWORD *)this + 65) = v5;
  if ( v5 == nullptr )
    return 0;
  v7 = *a2;
  putf8Buffer.m_LessFunc = **a2;
  v8 = nullptr;
  v19 = false;
  v16 = (unsigned int)putf8Buffer.m_LessFunc + (unsigned int)v7[4];
  while ( (unsigned int)putf8Buffer.m_LessFunc < v16 )
  {
    Char = GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
    v10 = Char;
    switch ( Char )
    {
      case '^':
        v19 = !v19;
        break;
      case '\\':
        if ( (unsigned int)putf8Buffer.m_LessFunc >= v16 )
          return 1;
        v10 = GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
LABEL_14:
        if ( v8 != nullptr )
        {
          if ( v10 < (unsigned int)v8 )
            v10 = (unsigned int)v8;
        }
        else
        {
          v8 = (GetTriangles_Vertex_t *)v10;
        }
        if ( v19 )
        {
          v12 = v17;
          v13 = *((GFxZlibSupportBase **)v17 + 65);
          if ( v13->RefCount == 0 )
          {
            v14[0] = nullptr;
            v14[1] = (const GetTriangles_Vertex_t *)0x10000;
            v14[2] = nullptr;
            GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::SetRange(this: v13, a2: v14);
          }
          GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::ClearRange(
            this: *((GFxZlibSupportBase **)v12 + 65),
            index: v8,
            a3: (char *)(v10 - (_DWORD)v8 + 1));
        }
        else
        {
          v11 = *((GFxZlibSupportBase **)v17 + 65);
          v15[2] = nullptr;
          v15[0] = v8;
          v15[1] = (const GetTriangles_Vertex_t *)(v10 - (_DWORD)v8 + 1);
          GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::SetRange(this: v11, a2: v15);
        }
        v4 = (GetTriangles_Vertex_t *)v10;
        v8 = nullptr;
        break;
      case '-':
        v8 = v4;
        break;
      default:
        goto LABEL_14;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F1BE0
// Name: public: GFxEditTextCharacter::CSSHolder::CSSHolder(void)
// Source: json
//------------------------------------------------------------------------------
GFxEditTextCharacter::CSSHolder *__thiscall GFxEditTextCharacter::CSSHolder::CSSHolder(
        GFxEditTextCharacter::CSSHolder *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_WORD *)this + 10) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_WORD *)this + 14) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_WORD *)this + 18) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_WORD *)this + 22) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F1C10
// Name: public: void GRangeDataArray<struct GFxEditTextCharacter::CSSHolder::UrlZone,class GArray<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,2,struct GArrayDefaultPolicy>>::SetRange(class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRangeDataArray<GFxEditTextCharacter::CSSHolder::UrlZone,GArray<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2,GArrayDefaultPolicy>>::SetRange(
        unsigned int *pheapAddr,
        int *a2)
{
  unsigned int v3; // edi
  signed int NearestRangeIndex; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  unsigned int v13; // ebx
  _DWORD *v14; // ebx
  unsigned int v15; // edx
  unsigned int v16; // eax
  unsigned int v17; // ecx
  int v18; // ebx
  int v19; // eax
  int v20; // ebx
  int v21; // ebx
  unsigned int v22; // eax
  unsigned int v23; // edx
  int v24; // edx
  unsigned int v25; // ebx
  int v26; // eax
  int v27; // ebx
  int v28; // ebx
  int v29; // ecx
  int v30; // ecx
  int v31; // edx
  _DWORD *v32; // eax
  int v33; // esi
  int v34; // ecx
  int v35; // edi
  unsigned int v36; // eax
  _DWORD *v37; // esi
  int v38; // eax
  int v39; // esi
  _DWORD *v40; // eax
  _DWORD *v41; // edi
  int v42; // [esp+8h] [ebp-28h] BYREF
  int v43; // [esp+Ch] [ebp-24h]
  GRefCountNTSImpl *v44; // [esp+10h] [ebp-20h]
  ButtonCode_t pheapAddra; // [esp+1Ch] [ebp-14h] BYREF
  int v46; // [esp+20h] [ebp-10h]
  ButtonCode_t v47; // [esp+24h] [ebp-Ch]
  int v48; // [esp+28h] [ebp-8h]
  int v49; // [esp+2Ch] [ebp-4h]
  int v50; // [esp+38h] [ebp+8h]

  v3 = *(pheapAddr + 1);
  if ( v3 == 0 )
  {
    GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::InsertAt(
      pheapAddr,
      a2: 0,
      a3: a2);
    return;
  }
  NearestRangeIndex = GRangeDataArray<GFxEditTextCharacter::CSSHolder::UrlZone,GArray<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(
                        this: pheapAddr,
                        a2: *a2);
  pheapAddra = (ButtonCode_t)pheapAddr;
  if ( NearestRangeIndex >= 0 )
  {
    if ( NearestRangeIndex < v3 )
      v5 = NearestRangeIndex;
    else
      v5 = v3 - 1;
  }
  else
  {
    v5 = 0;
  }
  v6 = *a2;
  v7 = 20 * v5;
  v8 = 20 * v5 + *pheapAddr;
  v46 = v5;
  if ( v6 < *(_DWORD *)v8 || (v9 = v6 + a2[1], v10 = *(_DWORD *)v8, v49 = v9, v9 - 1 > *(_DWORD *)(v8 + 4) + v10 - 1) )
  {
    v24 = *a2;
    if ( *a2 < *(_DWORD *)v8 || (v25 = *(_DWORD *)(v8 + 4), v24 > (int)(v25 + *(_DWORD *)v8 - 1)) )
    {
      GRange::CompareTo(this: (GetTriangles_Vertex_t *)v8, index: (const GetTriangles_Vertex_t *)*a2);
      if ( v26 <= 0 )
      {
        v27 = v5 + 1;
        GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::InsertAt(
          pheapAddr,
          a2: v5 + 1,
          a3: a2);
        if ( v5 < (int)*(pheapAddr + 1) )
        {
          ++v5;
          v46 = v27;
        }
        v47 = pheapAddra;
      }
      else
      {
        GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::InsertAt(
          pheapAddr,
          a2: v5,
          a3: a2);
        v47 = pheapAddra;
      }
      v48 = v5;
      goto LABEL_49;
    }
    if ( *(_DWORD *)v8 + v25 - v24 <= v25 )
      *(_DWORD *)(v8 + 4) = v24 - *(_DWORD *)v8;
    else
      *(_DWORD *)(v8 + 4) = 0;
    if ( v5 < (int)*(pheapAddr + 1) )
      v46 = ++v5;
LABEL_34:
    v47 = pheapAddra;
    v48 = v5;
    GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::InsertAt(
      pheapAddr,
      a2: v5,
      a3: a2);
LABEL_49:
    if ( v5 < (int)*(pheapAddr + 1) )
      v46 = ++v5;
    goto LABEL_51;
  }
  v11 = *(_DWORD *)(v8 + 4);
  if ( *(_DWORD *)v8 == *a2 )
  {
    v12 = a2[1];
    if ( v12 > v11 )
      v12 = *(_DWORD *)(v8 + 4);
    *(_DWORD *)v8 += v12;
    *(_DWORD *)(v8 + 4) = v11 - v12;
    v13 = *pheapAddr + v7;
    if ( *(_DWORD *)(v13 + 4) != 0 )
      GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::InsertAt(
        pheapAddr,
        a2: v5,
        a3: a2);
    else
      GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>::operator=(
        this: (GRefCountNTSImpl **)v13,
        (GRefCountNTSImpl **)a2);
    v14 = (_DWORD *)pheapAddra;
    v47 = pheapAddra;
    v48 = v5;
    if ( v5 < (int)*(pheapAddr + 1) )
      v46 = ++v5;
    goto LABEL_52;
  }
  if ( *(_DWORD *)v8 + v11 <= v49 )
  {
    v22 = *(_DWORD *)(v8 + 4);
    v23 = a2[1];
    if ( v23 <= v22 )
      *(_DWORD *)(v8 + 4) = v22 - v23;
    else
      *(_DWORD *)(v8 + 4) = 0;
    if ( v5 < (int)*(pheapAddr + 1) )
      v46 = ++v5;
    goto LABEL_34;
  }
  GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>::GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>(
    this: &v42,
    a2: (_DWORD *)v8);
  v15 = *(_DWORD *)(*pheapAddr + v7 + 4);
  v16 = *(_DWORD *)(*pheapAddr + 20 * v5) + *(_DWORD *)(*pheapAddr + 20 * v5 + 4) - *a2;
  v17 = v7 + *pheapAddr;
  if ( v16 <= v15 )
    *(_DWORD *)(v17 + 4) = v15 - v16;
  else
    *(_DWORD *)(v17 + 4) = 0;
  v18 = a2[1] + *(_DWORD *)(v7 + *pheapAddr + 4);
  if ( v18 > v43 )
    v18 = v43;
  v42 += v18;
  v19 = v43 - v18;
  v20 = v5 + 1;
  v43 = v19;
  GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::InsertAt(
    pheapAddr,
    a2: v5 + 1,
    a3: a2);
  if ( v5 < (int)*(pheapAddr + 1) )
  {
    ++v5;
    v46 = v20;
  }
  v47 = pheapAddra;
  v21 = v5 + 1;
  v48 = v5;
  GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::InsertAt(
    pheapAddr,
    a2: v5 + 1,
    a3: &v42);
  if ( v5 < (int)*(pheapAddr + 1) )
  {
    ++v5;
    v46 = v21;
  }
  if ( v44 != nullptr )
    GRefCountNTSImpl::Release(this: v44);
LABEL_51:
  v14 = (_DWORD *)v47;
LABEL_52:
  if ( !GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: (int *)&pheapAddra) )
  {
    v28 = 20 * v5;
    v49 = 20 * v5;
    while ( 1 )
    {
      v29 = *(_DWORD *)(*pheapAddr + v28);
      if ( v29 < *a2 || *(_DWORD *)(v28 + *pheapAddr + 4) + v29 - 1 > a2[1] + *a2 - 1 )
      {
LABEL_62:
        v14 = (_DWORD *)v47;
        break;
      }
      if ( v5 >= 0 && v5 < *(pheapAddr + 1) )
      {
        if ( *(pheapAddr + 1) != 1 )
        {
          v28 = v49;
          if ( *(_DWORD *)(*pheapAddr + v49 + 8) != 0 )
            GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)(*pheapAddr + v49 + 8));
          memmove(
            dst: (unsigned __int8 *)(v28 + *pheapAddr),
            src: (unsigned __int8 *)(v28 + *pheapAddr + 20),
            count: 4 * (5 * (*(pheapAddr + 1) - v5) - 5));
          --*(pheapAddr + 1);
          goto LABEL_61;
        }
        GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
          this: pheapAddr,
          (ButtonCode_t)pheapAddr,
          newCapacity: 0);
      }
      v28 = v49;
LABEL_61:
      if ( GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: (int *)&pheapAddra) )
        goto LABEL_62;
    }
  }
  if ( v5 >= 0 && v5 < *(pheapAddr + 1) )
  {
    v30 = a2[1];
    v31 = *a2;
    v32 = (_DWORD *)(*pheapAddr + 20 * v5);
    if ( v30 + *a2 - 1 >= *v32 && v30 + v31 - 1 <= v32[1] + *v32 - 1 )
    {
      v33 = v32[1];
      v34 = v31 + v30 - *v32;
      if ( v34 > v33 )
        v34 = v32[1];
      *v32 += v34;
      v32[1] = v33 - v34;
    }
  }
  v35 = v48;
  v46 = v48;
  if ( v48 >= 0 )
  {
    v36 = v48 - 1;
    v46 = v48 - 1;
    if ( v48 - 1 >= 0 && v36 < v14[1] )
    {
      v37 = (_DWORD *)(*v14 + 20 * v36);
      if ( v37[1] != 0 )
      {
        if ( *v37 + v37[1] == *a2
          && GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>::IsDataEqual(
               this: v37,
               a2: (_DWORD *)(*v14 + 20 * v48 + 8)) )
        {
          v37[1] += a2[1];
          if ( (unsigned int)v35 < v14[1] )
            GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::RemoveAt(
              pheapAddr: v14,
              a2: v35);
          v47 = (ButtonCode_t)v14;
          v48 = v46;
          v35 = v46;
        }
      }
      else
      {
        GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::RemoveAt(
          pheapAddr: v14,
          a2: v48 - 1);
      }
    }
  }
  v38 = v14[1];
  v39 = v35;
  if ( v35 < v38 )
    v39 = v35 + 1;
  if ( v39 >= 0 && v39 < (unsigned int)v38 )
  {
    v40 = (_DWORD *)(*v14 + 20 * v39);
    v50 = v40[1];
    if ( v50 == 0
      || *(v41 = (_DWORD *)(*v14 + 20 * v35)) + v41[1] == *v40
      && GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>::IsDataEqual(this: v41, a2: v40 + 2)
      && (v41[1] += v50, (unsigned int)v39 < v14[1]) )
    {
      GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::RemoveAt(
        pheapAddr: v14,
        a2: v39);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2040
// Name: public: class GAutoPtr<struct GFxEditTextCharacter::CSSHolder> __near & GAutoPtr<struct GFxEditTextCharacter::CSSHolder>::operator=(struct GFxEditTextCharacter::CSSHolder __near *)
// Source: json
//------------------------------------------------------------------------------
int **__thiscall GAutoPtr<GFxEditTextCharacter::CSSHolder>::operator=(int **this, int *a2)
{
  int *v3; // edi

  v3 = *this;
  if ( *this != a2 )
  {
    if ( v3 != nullptr && *((_BYTE *)this + 4) != 0 )
    {
      *((_BYTE *)this + 4) = 0;
      GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>::~GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>(this: v3 + 1);
      if ( *v3 != 0 )
        GRefCountBaseGC<323>::Release(a1: *v3, a2: (int)v3);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
    }
    *this = a2;
  }
  *((_BYTE *)this + 4) = a2 != nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F20A0
// Name: public: virtual GFxEditTextCharacter::~GFxEditTextCharacter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacter::~GFxEditTextCharacter(
        GFxASCharacter *this,
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *a2)
{
  _DWORD *v3; // edi
  GFxTextDocView *v4; // ecx
  int v5; // edi
  int v6; // ecx
  bool v7; // zf
  void **v8; // edi
  int v9; // ecx
  int *v10; // edi
  volatile LONG *v11; // edi
  int v12; // ecx
  GRefCountNTSImpl *v13; // ecx

  v3 = *((_DWORD **)this + 68);
  *(_DWORD *)this = &GFxEditTextCharacter::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxEditTextCharacter::`vftable'{for `GFxLogBase<GFxCharacter>'};
  *((_DWORD *)this + 30) = &GFxEditTextCharacter::`vftable';
  if ( v3 != nullptr )
  {
    GHashSetBase<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GPtr<GFxTextImageDesc>,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF>>::Clear(this: v3);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  }
  v4 = *((GFxTextDocView **)this + 47);
  *((_DWORD *)this + 68) = 0;
  GFxTextDocView::Close(this: v4);
  v5 = *((_DWORD *)this + 64);
  if ( v5 != 0 )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(v5 + 20));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(v5 + 8));
    v6 = *(_DWORD *)(v5 + 4);
    v7 = (*(_DWORD *)(v6 + 8))-- == 1;
    if ( v7 )
      GASStringNode::ReleaseNode(a1: v6);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v5);
  }
  v8 = *((void ***)this + 65);
  if ( v8 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v8);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
  }
  v9 = *((_DWORD *)this + 66);
  if ( v9 != 0 )
    GRefCountBaseGC<323>::Release(a1: v9, a2: (int)v8);
  GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)this + 61);
  v10 = *((int **)this + 59);
  if ( v10 != nullptr )
  {
    if ( *((_BYTE *)this + 240) != 0 )
    {
      *((_BYTE *)this + 240) = 0;
      GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>::~GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>(this: v10 + 1);
      if ( *v10 != 0 )
        GRefCountBaseGC<323>::Release(a1: *v10, a2: (int)v10);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
    }
    *((_DWORD *)this + 59) = 0;
  }
  *((_BYTE *)this + 240) = 0;
  v11 = (volatile LONG *)(*((_DWORD *)this + 58) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v11 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v11);
  GASValue::~GASValue(this: (GASValue *)this + 53, a2: (int)v11);
  v12 = *((_DWORD *)this + 52);
  v7 = (*(_DWORD *)(v12 + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v12);
  v13 = *((GRefCountNTSImpl **)this + 47);
  if ( v13 != nullptr )
    GRefCountNTSImpl::Release(this: v13);
  GFxASCharacter::~GFxASCharacter(this, a2: (GFxMovie *)this, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x100F2220
// Name: public: void GFxEditTextCharacter::CollectUrlZones(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxEditTextCharacter::CollectUrlZones(GFxEditTextCharacter *this@<ecx>, int a2@<edi>)
{
  GFxEditTextCharacter *v2; // esi
  _DWORD *v3; // ecx
  int v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // edi
  int v7; // eax
  char *v8; // edi
  int v9; // eax
  unsigned int v10; // esi
  const char *v11; // ecx
  int v12; // eax
  struct GFxStyledText *v13; // eax
  int v14; // esi
  GRefCountNTSImpl *v15; // edi
  int v16; // eax
  CImagePacker *m_pMemory; // eax
  struct GFxStyledText *v18; // eax
  int v19; // esi
  GRefCountNTSImpl *v20; // edi
  void *v21; // esi
  int v22; // [esp-4h] [ebp-78h]
  GRefCountBase<GFxASUserData,2> v23; // [esp+8h] [ebp-6Ch] BYREF
  IShaderAPI *v24; // [esp+14h] [ebp-60h]
  int v25; // [esp+24h] [ebp-50h]
  unsigned int v26; // [esp+28h] [ebp-4Ch]
  int v27[2]; // [esp+2Ch] [ebp-48h] BYREF
  GRefCountNTSImpl *v28; // [esp+34h] [ebp-40h]
  int v29; // [esp+38h] [ebp-3Ch]
  int v30; // [esp+3Ch] [ebp-38h]
  int v31[2]; // [esp+40h] [ebp-34h] BYREF
  GRefCountNTSImpl *v32; // [esp+48h] [ebp-2Ch]
  int v33; // [esp+4Ch] [ebp-28h]
  int v34; // [esp+50h] [ebp-24h]
  unsigned int v35; // [esp+54h] [ebp-20h]
  int v36; // [esp+58h] [ebp-1Ch]
  unsigned int i; // [esp+5Ch] [ebp-18h]
  char *v38; // [esp+60h] [ebp-14h]
  GFxEditTextCharacter *v39; // [esp+64h] [ebp-10h]
  GFxTextParagraph *v40; // [esp+68h] [ebp-Ch]
  CUtlMemory<CImagePacker,int> var8; // [esp+6Ch] [ebp-8h] BYREF

  v2 = this;
  v3 = *((_DWORD **)this + 59);
  v4 = 0;
  v39 = v2;
  if ( v3 != nullptr )
  {
    v3[4] = 0;
    v3[5] = 0;
    v3[6] = 0;
    v3[7] = 0;
    v3[8] = 0;
    v3[9] = 0;
    v3[10] = 0;
    v3[11] = 0;
    v22 = a2;
    GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (unsigned int *)(*((_DWORD *)v2 + 59) + 4),
      pheapAddr: (ButtonCode_t)(*((_DWORD *)v2 + 59) + 4),
      newCapacity: 0);
    v36 = *(_DWORD *)(*((_DWORD *)v2 + 47) + 8);
    GString::GString(this: &var8);
    v5 = *(_DWORD *)(v36 + 16);
    v6 = 0;
    var8.m_nAllocationCount = 0;
    v35 = v5;
    for ( i = 0; v6 < v35; i = v6 )
    {
      if ( v6 >= *(_DWORD *)(v36 + 16) )
        v40 = nullptr;
      else
        v40 = *(GFxTextParagraph **)(*(_DWORD *)(v36 + 12) + 4 * v6);
      GFxTextParagraph::GetIterator(this: v40);
      if ( v26 < *(_DWORD *)(v25 + 4) )
      {
        do
        {
          v7 = GFxTextParagraph::FormatRunIterator::operator*(a1: &v23);
          v8 = (char *)v40[7].pObject + *(_DWORD *)(v7 + 4);
          v38 = v8;
          v9 = *(_DWORD *)(GFxTextParagraph::FormatRunIterator::operator*(a1: &v23) + 12);
          if ( (*(_WORD *)(v9 + 42) & 0x100) != 0 && GString::GetLength(this: (GString *)(v9 + 16)) != 0 )
          {
            if ( (*(_DWORD *)((int)var8.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
            {
              v10 = v4 + var8.m_nAllocationCount;
              if ( v8 == (char *)(v4 + var8.m_nAllocationCount)
                && (v11 = (const char *)((*(_DWORD *)(*(_DWORD *)(GFxTextParagraph::FormatRunIterator::operator*(a1: &v23)
                                                                + 12)
                                                    + 16)
                                        & 0xFFFFFFFC)
                                       + 8),
                    strcmp((const char *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 8), v11) == 0) )
              {
                v12 = GFxTextParagraph::FormatRunIterator::operator*(a1: &v23);
                var8.m_nAllocationCount += *(_DWORD *)(v12 + 8);
              }
              else
              {
                v13 = GFxStyledText::CopyStyledText(
                        this: *(GFxStyledText **)(*((_DWORD *)v39 + 47) + 8),
                        startPos: v4,
                        endPos: v10);
                v14 = *((_DWORD *)v39 + 59);
                v15 = (GRefCountNTSImpl *)v13;
                GRangeDataArray<GFxEditTextCharacter::CSSHolder::UrlZone,GArray<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2,GArrayDefaultPolicy>>::ExpandRange(
                  this: (int *)(v14 + 4),
                  a2: v4,
                  a3: var8.m_nAllocationCount);
                v31[0] = v4;
                v31[1] = var8.m_nAllocationCount;
                if ( v15 != nullptr )
                  ++v15->RefCount;
                v32 = v15;
                v33 = 0;
                v34 = 0;
                GRangeDataArray<GFxEditTextCharacter::CSSHolder::UrlZone,GArray<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2,GArrayDefaultPolicy>>::SetRange(
                  pheapAddr: (unsigned int *)(v14 + 4),
                  a2: v31);
                if ( v32 != nullptr )
                  GRefCountNTSImpl::Release(this: v32);
                GString::Clear(this: (GString *)&var8);
                if ( v15 != nullptr )
                  GRefCountNTSImpl::Release(this: v15);
                v8 = v38;
              }
            }
            if ( (*(_DWORD *)((int)var8.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF) == 0 )
            {
              v4 = (int)v8;
              var8.m_nAllocationCount = *(_DWORD *)(GFxTextParagraph::FormatRunIterator::operator*(a1: &v23) + 8);
              v16 = GFxTextParagraph::FormatRunIterator::operator*(a1: &v23);
              GString::operator=(
                this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&var8,
                src: (_DWORD *)(*(_DWORD *)(v16 + 12) + 16),
                a3: v22);
            }
          }
          GFxTextParagraph::FormatRunIterator::operator++(this: &v23);
        }
        while ( v26 < *(_DWORD *)(v25 + 4) );
        v6 = i;
        v2 = v39;
      }
      if ( v24 != nullptr )
        GRefCountImpl::Release(this: v24);
      ++v6;
    }
    m_pMemory = var8.m_pMemory;
    if ( (*(_DWORD *)((int)var8.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
    {
      v18 = GFxStyledText::CopyStyledText(
              this: *(GFxStyledText **)(*((_DWORD *)v2 + 47) + 8),
              startPos: v4,
              endPos: v4 + var8.m_nAllocationCount);
      v19 = *((_DWORD *)v2 + 59);
      v20 = (GRefCountNTSImpl *)v18;
      GRangeDataArray<GFxEditTextCharacter::CSSHolder::UrlZone,GArray<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2,GArrayDefaultPolicy>>::ExpandRange(
        this: (int *)(v19 + 4),
        a2: v4,
        a3: var8.m_nAllocationCount);
      v27[0] = v4;
      v27[1] = var8.m_nAllocationCount;
      if ( v20 != nullptr )
        ++v20->RefCount;
      v28 = v20;
      v29 = 0;
      v30 = 0;
      GRangeDataArray<GFxEditTextCharacter::CSSHolder::UrlZone,GArray<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2,GArrayDefaultPolicy>>::SetRange(
        pheapAddr: (unsigned int *)(v19 + 4),
        a2: v27);
      if ( v28 != nullptr )
        GRefCountNTSImpl::Release(this: v28);
      if ( v20 != nullptr )
        GRefCountNTSImpl::Release(this: v20);
      m_pMemory = var8.m_pMemory;
    }
    v21 = (void *)((unsigned int)m_pMemory & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((unsigned int)m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2530
// Name: public: virtual class GFxCharacter __near * GFxEditTextCharacterDef::CreateCharacterInstance(class GFxASCharacter __near *,class GFxResourceId,class GFxMovieDefImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEditTextCharacterDef::CreateCharacterInstance(
        GArrayData<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *this,
        GRefCountNTSImpl *parent,
        struct GFxResourceId a3,
        _IMAGE_SECTION_HEADER::<unnamed_type_Misc> pbindingImpl)
{
  GFxEditTextCharacter *v5; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  v6 = 322;
  v5 = (GFxEditTextCharacter *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: parent,
                                 a3: 276,
                                 a4: &v6);
  if ( v5 != nullptr )
    GFxEditTextCharacter::GFxEditTextCharacter(
      this: v5,
      a2: (struct GFxEditTextCharacterDef *)this,
      pbindingDefImpl: pbindingImpl,
      a4: parent,
      a5: a3);
}

//------------------------------------------------------------------------------
// Address: 0x100F2590
// Name: public: virtual void GFxEditTextCharacter::SetTextValue(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxEditTextCharacter::SetTextValue(
        int adr@<ecx>,
        MaterialVarFlags_t a2@<edi>,
        char *a3,
        bool a4,
        bool a5)
{
  _DWORD *v6; // eax
  char v7; // dl
  const char *v8; // edi
  int v9; // eax
  int v10; // eax
  const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v11; // eax
  struct GMemoryHeap *v12; // eax
  int *v13; // eax
  int v14; // eax
  int v15; // eax
  int Length; // eax
  struct GMemoryHeap *v17; // eax
  const wchar_t *v18; // eax
  struct GMemoryHeap *v19; // eax
  int *v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  unsigned int v26; // edi
  _DWORD *v27; // eax
  MaterialVarFlags_t v28; // [esp-4h] [ebp-94Ch]
  unsigned int v29; // [esp-4h] [ebp-94Ch]
  RenderPassList_t *m_pSnapshots; // [esp-4h] [ebp-94Ch]
  unsigned int v31; // [esp+0h] [ebp-948h]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v32; // [esp+8h] [ebp-940h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v33; // [esp+34h] [ebp-914h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v34; // [esp+60h] [ebp-8E8h] BYREF
  int ppdestTextFmt; // [esp+8Ch] [ebp-8BCh] BYREF
  int ppdestParaFmt; // [esp+90h] [ebp-8B8h] BYREF
  int v37; // [esp+94h] [ebp-8B4h] BYREF
  int v38; // [esp+98h] [ebp-8B0h]
  int v39; // [esp+9Ch] [ebp-8ACh]
  GMemoryHeap *v40; // [esp+A0h] [ebp-8A8h]
  CMaterial v41; // [esp+A4h] [ebp-8A4h] BYREF
  unsigned int pwStr; // [esp+924h] [ebp-24h] BYREF
  GFxWStringBuffer pBuffer; // [esp+934h] [ebp-14h] BYREF

  v6 = *(_DWORD **)(adr + 236);
  if ( v6 != nullptr && *v6 != 0 )
    a4 = true;
  v28 = a2;
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(adr + 232),
    a2: (unsigned __int8 *)a3);
  if ( a4 )
    *(_WORD *)(adr + 228) |= 0x1000u;
  else
    *(_WORD *)(adr + 228) &= ~0x1000u;
  v7 = *(_BYTE *)(adr + 228) >> 3;
  v8 = (const char *)((*(_DWORD *)(adr + 232) & 0xFFFFFFFC) + 8);
  BYTE2(v41.m_VMTIncludes.m_Size) = 0;
  if ( (v7 & 1) != 0 )
    goto LABEL_37;
  v9 = (*(int (__thiscall **)(int))(*(_DWORD *)adr + 84))(a1: adr);
  v41.m_VMTIncludes.m_Memory.m_nGrowSize = (*(int (__thiscall **)(int, int))(*(_DWORD *)(v9 + 8) + 12))(
                                             a1: v9 + 8,
                                             a2: 3);
  if ( v41.m_VMTIncludes.m_Memory.m_nGrowSize == 0 )
    goto LABEL_37;
  if ( (*(_DWORD *)(adr + 160) & 0x4000) != 0 )
  {
    v11 = &pMem;
  }
  else
  {
    v10 = *(_DWORD *)(adr + 148);
    if ( v10 == 0 )
    {
      GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)adr);
      if ( v10 == 0 )
        v10 = *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)adr + 108))(a1: adr) + 120);
    }
    v11 = **(const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > ***)(v10 + 8);
  }
  GFxEditTextCharacter::SetTextValue_::_10_::TranslateInfo::TranslateInfo(
    result: (int)&v41.m_VMTIncludes.m_pElements,
    a2: (int)v11);
  if ( !a4
    || ((*(int (__thiscall **)(int))(*(_DWORD *)v41.m_VMTIncludes.m_Memory.m_nGrowSize + 4))(a1: v41.m_VMTIncludes.m_Memory.m_nGrowSize)
      & 1) != 0 )
  {
    Length = GUTF8Util::GetLength(length: v8, buflen: -1);
    GFxWStringBuffer::Resize(this: &pBuffer, a2: Length + 1);
    GUTF8Util::DecodeString(
      pbegin: pBuffer.pText,
      putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)v8,
      length: -1);
    v41.m_VMTIncludes.m_pElements = (void **)pBuffer.pText;
    if ( a4 )
      LOBYTE(v41.m_Reflectivity.x) |= 4u;
    (*(void (__thiscall **)(int, void ***))(*(_DWORD *)v41.m_VMTIncludes.m_Memory.m_nGrowSize + 8))(
      a1: v41.m_VMTIncludes.m_Memory.m_nGrowSize,
      a2: &v41.m_VMTIncludes.m_pElements);
  }
  else
  {
    v12 = (struct GMemoryHeap *)((int (__thiscall *)(GMemoryHeap *, int, MaterialVarFlags_t))GMemory::pGlobalHeap->GetAllocHeap)(
                                  a1: GMemory::pGlobalHeap,
                                  a2: adr,
                                  a3: v28);
    GFxTextFormat::GFxTextFormat(this: (GFxTextFormat *)&v32, a2: v12);
    v41.m_RefCount.m_value = 1;
    *(_DWORD *)&v41.m_Name.m_Id = &GFxTextParagraphFormat::`vftable';
    memset(&v41.m_Flags, 0, 16);
    GFxEditTextCharacter::GetInitialFormats(adr, a2: &v32, a3: (CMaterial *)&v41.m_Name);
    v13 = *(int **)(adr + 236);
    if ( v13 != nullptr && (v14 = *v13) != 0 )
      v15 = v14 + 52;
    else
      v15 = 0;
    GFxTextDocView::ParseHtml(
      putf8Str: (unsigned int)v8,
      utf8Len: (GMemAddressStub *)0xFFFFFFFF,
      condenseWhite: (*(_BYTE *)(adr + 228) & 0x10) != 0,
      pimgInfoArr: nullptr,
      a5: v15);
    GFxStyledText::GetText(this: *(CUtlMemory<GFxValue,int> **)(*(_DWORD *)(adr + 188) + 8), (unsigned int)&pBuffer);
    if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v41.m_VMTIncludes.m_Memory.m_nGrowSize + 4))(a1: v41.m_VMTIncludes.m_Memory.m_nGrowSize)
        & 2) != 0 )
      GFxWStringBuffer::StripTrailingNewLines(
        this: (CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&pBuffer,
        a2: v31);
    v41.m_VMTIncludes.m_pElements = (void **)pBuffer.pText;
    (*(void (__thiscall **)(int))(*(_DWORD *)v41.m_VMTIncludes.m_Memory.m_nGrowSize + 8))(a1: v41.m_VMTIncludes.m_Memory.m_nGrowSize);
    *(_DWORD *)&v41.m_Name.m_Id = &GFxTextParagraphFormat::`vftable';
    GFxTextParagraphFormat::FreeTabStops(
      this: (CMaterial *)&v41.m_Name,
      a2: (MaterialVarFlags_t)&v41.m_VMTIncludes.m_pElements,
      a3: v31);
    GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v41.m_Name);
    GFxTextFormat::~GFxTextFormat(this: &v32);
  }
  HIBYTE(v41.m_VMTIncludes.m_Size) = LOBYTE(v41.m_Reflectivity.x) & 1;
  if ( (LOBYTE(v41.m_Reflectivity.x) & 1) != 0 )
  {
    if ( (LOBYTE(v41.m_Reflectivity.x) & 2) != 0 )
    {
      v17 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: adr);
      GFxTextFormat::GFxTextFormat(this: (GFxTextFormat *)&v34, a2: v17);
      *(&v41.m_ShaderRenderState.m_Flags + 1) = 1;
      v41.m_ShaderRenderState.m_Flags = (int)&GFxTextParagraphFormat::`vftable';
      memset(&v41.m_ShaderRenderState.m_VertexFormat, 0, 16);
      GFxEditTextCharacter::GetInitialFormats(adr, a2: &v34, a3: (CMaterial *)&v41.m_ShaderRenderState);
      v40 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: adr);
      v37 = 0;
      v38 = 0;
      v39 = 0;
      v18 = (const wchar_t *)pwStr;
      if ( pwStr == 0 )
        v18 = &word_1028F3E0;
      GFxTextDocView::ParseHtml(
        this: *(GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **)(adr + 188),
        pwStr: (unsigned int)v18);
      if ( v38 != 0 )
        GFxEditTextCharacter::ProcessImageTags(a1: (IMatRenderContextInternal *)adr, a2: (int)&v37, a3: &v37);
      GArrayDH<GFxStyledText::HTMLImageTagInfo,2,GArrayDefaultPolicy>::~GArrayDH<GFxStyledText::HTMLImageTagInfo,2,GArrayDefaultPolicy>(this: &v37);
      v41.m_ShaderRenderState.m_Flags = (int)&GFxTextParagraphFormat::`vftable';
      GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v41.m_ShaderRenderState, a2: v28, a3: v31);
      GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v41.m_ShaderRenderState);
      GFxTextFormat::~GFxTextFormat(this: &v34);
    }
    else
    {
      GFxStyledText::GetTextAndParagraphFormat(
        this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(*(_DWORD *)(adr + 188) + 8),
        (int)&ppdestTextFmt,
        (int)&ppdestParaFmt);
      GFxStyledText::SetDefaultTextFormat(this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(*(_DWORD *)(adr + 188) + 8));
      GFxFontDataCompactedSwf::SetTextureGlyphData(
        this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(*(_DWORD *)(adr + 188) + 8),
        pdata: ppdestParaFmt);
      GFxTextDocView::SetText(this: *(GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **)(adr + 188));
    }
    BYTE2(v41.m_VMTIncludes.m_Size) = 1;
  }
  GFxWStringBuffer::~GFxWStringBuffer(
    this: (CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&pBuffer,
    a2: v28);
  GFxWStringBuffer::~GFxWStringBuffer(
    this: (CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&pwStr,
    a2: v29);
  GRefCountImpl::Release(this: (IShaderAPI *)v41.m_VMTIncludes.m_Memory.m_nGrowSize);
  if ( HIBYTE(v41.m_VMTIncludes.m_Size) == 0 )
  {
LABEL_37:
    if ( a4 )
    {
      v19 = (struct GMemoryHeap *)((int (__thiscall *)(GMemoryHeap *, int, MaterialVarFlags_t))GMemory::pGlobalHeap->GetAllocHeap)(
                                    a1: GMemory::pGlobalHeap,
                                    a2: adr,
                                    a3: v28);
      GFxTextFormat::GFxTextFormat(this: (GFxTextFormat *)&v33, a2: v19);
      v41.m_iEnumerationID = 1;
      v41.__vftable = (CMaterial_vtbl *)&GFxTextParagraphFormat::`vftable';
      memset(&v41.m_minLightmapPageID, 0, 16);
      GFxEditTextCharacter::GetInitialFormats(adr, a2: &v33, a3: &v41);
      v41.m_VMTIncludes.m_Memory.m_nAllocationCount = (int)GMemory::pGlobalHeap->GetAllocHeap(
                                                             this: GMemory::pGlobalHeap,
                                                             a2: adr);
      v20 = *(int **)(adr + 236);
      memset(&v41.m_ShaderRenderState.m_pSnapshots, 0, 12);
      if ( v20 != nullptr && (v21 = *v20) != 0 )
        v22 = v21 + 52;
      else
        v22 = 0;
      GFxTextDocView::ParseHtml(
        putf8Str: (unsigned int)v8,
        utf8Len: (GMemAddressStub *)0xFFFFFFFF,
        condenseWhite: (*(_BYTE *)(adr + 228) & 0x10) != 0,
        pimgInfoArr: (const char *)&v41.m_ShaderRenderState.m_pSnapshots,
        a5: v22);
      if ( *((_DWORD *)&v41.m_ShaderRenderState.m_pSnapshots + 1) != 0 )
        GFxEditTextCharacter::ProcessImageTags(
          a1: (IMatRenderContextInternal *)adr,
          a2: v23,
          a3: &v41.m_ShaderRenderState.m_pSnapshots);
      GConstructorMov<GFxStyledText::HTMLImageTagInfo>::DestructArray(
        a1: (int)v41.m_ShaderRenderState.m_pSnapshots,
        a2: *((int *)&v41.m_ShaderRenderState.m_pSnapshots + 1));
      m_pSnapshots = v41.m_ShaderRenderState.m_pSnapshots;
      ((void (__thiscall *)(GMemoryHeap *))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap);
      v41.__vftable = (CMaterial_vtbl *)&GFxTextParagraphFormat::`vftable';
      GFxTextParagraphFormat::FreeTabStops(this: &v41, a2: (MaterialVarFlags_t)m_pSnapshots, a3: v31);
      GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v41);
      GFxTextFormat::~GFxTextFormat(this: &v33);
    }
    else
    {
      GFxTextDocView::SetText(this: *(GFxTextDocView **)(adr + 188), putf8String: v8, a3: 0xFFFFFFFF);
    }
  }
  v24 = *(_DWORD *)(adr + 188);
  v25 = *(_DWORD *)(v24 + 284);
  if ( v25 != 0 && (*(_BYTE *)(v25 + 104) & 1) == 0 )
  {
    v26 = GFxStyledText::GetLength(this: *(GFxStyledText **)(v24 + 8));
    if ( GFILEFile::GetErrorCode(this: *(CVTFTexture **)(*(_DWORD *)(adr + 188) + 284)) > v26 )
      GFxTextEditorKit::SetCursorPos(
        this: *(GFxTextEditorKit **)(*(_DWORD *)(adr + 188) + 284),
        textPos: v26,
        selectionAllowed: false);
  }
  v27 = *(_DWORD **)(adr + 236);
  if ( v27 != nullptr && *v27 != 0 && (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(adr + 188) + 8) + 32) & 1) != 0 )
    GFxEditTextCharacter::CollectUrlZones(this: (GFxEditTextCharacter *)adr, a2: v28);
  if ( a5 )
    GFxEditTextCharacter::UpdateVariable(this: (GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > **)adr);
  if ( BYTE2(v41.m_VMTIncludes.m_Size) != 0 )
    GFxEditTextCharacter::NotifyChanged(result: (tagAXISINFOA *)adr);
  (*(void (__thiscall **)(int))(*(_DWORD *)adr + 352))(a1: adr);
}

//------------------------------------------------------------------------------
// Address: 0x100F2C00
// Name: public: virtual bool GFxEditTextCharacter::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge GFxEditTextCharacter::SetMember@<al>(
        GFxASCharacter *this@<ecx>,
        double a2@<st0>,
        tagRID_DEVICE_INFO_KEYBOARD *a3,
        CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *result,
        const struct GASValue *a5,
        HICON__ *a6)
{
  int v7; // edi
  char *v8; // esi
  char v9; // al
  const void *v10; // eax
  struct GASValue *v11; // eax
  const void *Version; // eax
  struct GASValue *v13; // eax
  unsigned int v14; // edi
  int v15; // eax
  bool v16; // al
  const char *v17; // eax
  int v18; // eax
  struct GASValue *v19; // eax
  char v20; // al
  GFxTextDocView *v21; // ecx
  char v22; // al
  int v23; // ebx
  HINSTANCE__ *hInstance; // eax
  int v25; // ecx
  HINSTANCE__ *v26; // eax
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v27; // eax
  char v28; // al
  char v29; // al
  int v30; // ebx
  int v31; // eax
  int v32; // eax
  int v33; // eax
  double v34; // st7
  GViewport *v35; // ecx
  char v36; // al
  double v37; // st7
  GViewport *v38; // ecx
  char v39; // al
  GASStringManager *v40; // ecx
  void (__cdecl **m_pMemory)(int); // eax
  bool v42; // zf
  const wchar_t *v43; // ecx
  int v44; // eax
  GASStringManager *v45; // ecx
  struct GASStringNode *v46; // eax
  bool v47; // zf
  const wchar_t *v48; // ecx
  struct GFxTextEditorKit *EditorKit; // eax
  _DWORD *v50; // eax
  bool v51; // zf
  double v52; // st7
  GViewport *v53; // ecx
  char v54; // al
  int v55; // ebx
  char v56; // al
  GASStringManager *v57; // ecx
  void (__cdecl **ConstStringNode)(int); // eax
  bool v59; // zf
  const wchar_t *lpszMenuName; // ecx
  GASStringManager *v61; // ecx
  struct GASStringNode *v62; // eax
  bool v63; // zf
  const wchar_t *v64; // ecx
  char v65; // al
  struct GASObject *v66; // eax
  GFxEditTextCharacter::CSSHolder *v67; // eax
  int *v68; // eax
  struct GASValue *v69; // eax
  int v70; // ecx
  int v71; // eax
  int *v72; // ebx
  GFxEditTextCharacter::ShadowParams *v73; // eax
  GFxEditTextCharacter::ShadowParams *v74; // eax
  int v75; // eax
  HBRUSH__ *hbrBackground; // esi
  const wchar_t *v77; // ecx
  char v78; // al
  char v79; // al
  const wchar_t *v80; // ecx
  const wchar_t *v81; // esi
  signed int v82; // esi
  int v83; // ecx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v84; // eax
  int v85; // esi
  char v86; // al
  unsigned __int8 *v87; // esi
  unsigned __int8 *v88; // ecx
  signed int v89; // esi
  int v90; // edx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v91; // eax
  int v92; // esi
  int v93; // eax
  int v94; // esi
  int v95; // ebx
  int v96; // ecx
  int v97; // esi
  _BYTE *v98; // ecx
  int v99; // eax
  tagPOLYTEXTW *v100; // eax
  unsigned __int8 v101; // al
  tagPOLYTEXTW *v102; // eax
  char v103; // al
  char v104; // al
  int v105; // ebx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v106; // ebx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v107; // ebx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v108; // ebx
  int v109; // ebx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v110; // ebx
  char v111; // al
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v112; // ebx
  char v113; // al
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v114; // ebx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v115; // ebx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v116; // ebx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v117; // ebx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v118; // ebx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v119; // ebx
  char v120; // al
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v121; // ebx
  char v122; // al
  GRefCountBase<GFxAmpMemSegment,2> *v123; // ebx
  unsigned int v124; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v125; // ebx
  int v126; // ebx
  double v127; // st7
  int v128; // ebx
  int v129; // ebx
  int v130; // ebx
  int v131; // ebx
  int v132; // ebx
  tagPOLYTEXTW *v133; // eax
  char v134; // al
  int v135; // eax
  tagPOLYTEXTW *v136; // eax
  char v137; // al
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v138; // esi
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v139; // esi
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v140; // esi
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v141; // esi
  char v142; // al
  char v143; // al
  struct GASValue *v144; // ebx
  vc_attributes::InvalidCheckAttribute *Prototype; // eax
  HBRUSH__ *v146; // eax
  GASValue *v147; // ecx
  struct GASObject *v148; // ebx
  vc_attributes::InvalidCheckAttribute *v149; // eax
  struct GASValue *v150; // eax
  void **v151; // esi
  bool v152; // bl
  void *v153; // [esp+14h] [ebp-A0h]
  GASValue v154[4]; // [esp+20h] [ebp-94h] BYREF
  GASValue v155[4]; // [esp+30h] [ebp-84h] BYREF
  tagWNDCLASSW v; // [esp+40h] [ebp-74h] BYREF
  GASValue v157[4]; // [esp+68h] [ebp-4Ch] BYREF
  struct GASValue *v158; // [esp+78h] [ebp-3Ch] BYREF
  const wchar_t *v159; // [esp+7Ch] [ebp-38h]
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > v160; // [esp+80h] [ebp-34h] BYREF
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > dst; // [esp+98h] [ebp-1Ch] BYREF
  __int16 v162; // [esp+AEh] [ebp-6h]

  v7 = (int)a3;
  v158 = a5;
  v8 = (char *)this - 120;
  v.hbrBackground = (HBRUSH__ *)result;
  v.hIcon = a6;
  v160.m_Memory.m_pMemory = (void (__cdecl **)(int))GFxASCharacter::GetStandardMemberConstant(
                                                      this: (char *)this - 120,
                                                      (_IMAGE_SYMBOL_EX *)result);
  GASValue::GASValue(this: v157, v: (tagWNDCLASSW *)a5);
  if ( v160.m_Memory.m_pMemory >= (void (__cdecl **)(int))0x16
    && a3 != nullptr
    && GFxEditTextCharacter::GetTextFieldASObject(this: (GRefCountWeakSupportImpl *)v8) != nullptr
    && *(_DWORD *)(*((_DWORD *)this + 36) + 44) != 0 )
  {
    LOBYTE(v.style) = 0;
    if ( (unsigned __int8)GASObject::InvokeWatchpoint() != 0 )
      GASValue::operator=(this: (int)v157, &v);
    GASValue::~GASValue(this: (GASValue *)&v, a2: (int)a3);
  }
  if ( (*(unsigned __int8 (__thiscall **)(char *, void (__cdecl **)(int), struct GASValue *, _DWORD))(*(_DWORD *)v8 + 284))(
         a1: v8,
         a2: v160.m_Memory.m_pMemory,
         a3: v158,
         a4: 0) != 0 )
  {
LABEL_38:
    GASValue::~GASValue(this: v157, a2: v7);
    return true;
  }
  else
  {
    switch ( (unsigned int)v160.m_Memory.m_pMemory )
    {
      case 0x19u:
        goto LABEL_292;
      case 0x26u:
        GFxEditTextCharacter::ResetBlink(this: (GFxEditTextCharacter *)v8, a2: true, a3: false);
        Version = GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8);
        GASValue::ToStringVersioned(this: (unsigned __int8 *)v157, a2: (int *)&v158, a3, version: (unsigned int)Version);
        (*(void (__thiscall **)(char *, _DWORD, _DWORD, int))(*(_DWORD *)v8 + 468))(
          a1: v8,
          a2: *(_DWORD *)v158,
          a3: 0,
          a4: 1);
        v13 = v158;
        v42 = (*((_DWORD *)v158 + 2))-- == 1;
        if ( v42 )
          GASStringNode::ReleaseNode(a1: (int)v13);
        goto LABEL_38;
      case 0x29u:
        v158 = (struct GASValue *)GASValue::ToUInt32(this: v157, a2: (int)a3, a3: a2, a4: (_SERVICE_STATUS *)a3);
        GFxTextFormat::GFxTextFormat(
          this: (GFxTextFormat *)&v160.m_Memory.m_nAllocationCount,
          a2: *(struct GMemoryHeap **)(a3[5].dwType + 656));
        v162 |= 1u;
        v14 = (unsigned int)v158 & 0xFFFFFF;
        dst.m_Size = (unsigned int)v158 & 0xFFFFFF | dst.m_Size & 0xFF000000;
        GFxTextDocView::SetTextFormat(
          fmt: (unsigned int)&v160.m_Memory.m_nAllocationCount,
          startPos: nullptr,
          endPos: (const char *)0xFFFFFFFF,
          a4: (int)v153);
        GFxTextFormat::operator=(
          this: (int)&v160.m_Memory.m_nAllocationCount,
          __that: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 17) + 8) + 28));
        v15 = *((_DWORD *)this + 17);
        v162 |= 1u;
        dst.m_Size = v14 | dst.m_Size & 0xFF000000;
        GFxStyledText::SetDefaultTextFormat(this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)(v15 + 8));
        GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
        GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v160.m_Memory.m_nAllocationCount);
        GASValue::~GASValue(this: v157, a2: v14);
        return true;
      case 0x2Bu:
        v9 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        GFxEditTextCharacter::SetHtml(this: (GFxEditTextCharacter *)v8, a2: v9);
        goto LABEL_38;
      case 0x2Cu:
        v10 = GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8);
        GASValue::ToStringVersioned(this: (unsigned __int8 *)v157, a2: (int *)&v158, a3, version: (unsigned int)v10);
        (*(void (__thiscall **)(char *, _DWORD, bool, int))(*(_DWORD *)v8 + 468))(
          a1: v8,
          a2: *(_DWORD *)v158,
          a3: (*((_BYTE *)this + 108) & 2) != 0,
          a4: 1);
        v11 = v158;
        v42 = (*((_DWORD *)v158 + 2))-- == 1;
        if ( v42 )
          GASStringNode::ReleaseNode(a1: (int)v11);
        goto LABEL_38;
      case 0x2Du:
        v66 = GASValue::ToObject(this: v157, a2: (int)a3, (const struct GASEnvironment *)a3);
        v7 = (int)v66;
        if ( v66 != nullptr && ((int (__thiscall *)(struct GASObject *))v66[2].pNode[1].pNext)(a1: &v66[2]) == 31 )
        {
          if ( *((_DWORD *)this + 29) == 0 )
          {
            v67 = (GFxEditTextCharacter::CSSHolder *)GNewOverrideBase<323>::operator new(sz: 0x30u);
            if ( v67 != nullptr )
              v68 = (int *)GFxEditTextCharacter::CSSHolder::CSSHolder(this: v67);
            else
              v68 = nullptr;
            GAutoPtr<GFxEditTextCharacter::CSSHolder>::operator=(this: (int **)this + 29, a2: v68);
          }
          v69 = *((struct GASValue **)this + 29);
          *(_DWORD *)(v7 + 8) = (*(_DWORD *)(v7 + 8) + 1) & 0x8FFFFFFF;
          v70 = *(_DWORD *)v69;
          v158 = v69;
          if ( v70 != 0 )
          {
            GRefCountBaseGC<323>::Release(a1: v70, a2: v7);
            v69 = v158;
          }
          *(_DWORD *)v69 = v7;
          v71 = *(_DWORD *)(*((_DWORD *)this + 17) + 284);
          if ( v71 != 0 )
            *(_WORD *)(v71 + 104) |= 1u;
          GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
          GFxEditTextCharacter::CollectUrlZones(this: (GFxEditTextCharacter *)v8, a2: v7);
          GFxEditTextCharacter::UpdateUrlStyles(this: (GFxEditTextCharacter *)v8, a2: v7);
        }
        else
        {
          v72 = *((int **)this + 29);
          if ( v72 != nullptr )
          {
            if ( *v72 != 0 )
              GRefCountBaseGC<323>::Release(a1: *v72, a2: v7);
            *v72 = 0;
          }
          GFxEditTextCharacter::CollectUrlZones(this: (GFxEditTextCharacter *)v8, a2: v7);
          GFxEditTextCharacter::UpdateUrlStyles(this: (GFxEditTextCharacter *)v8, a2: v7);
        }
        goto LABEL_45;
      case 0x2Eu:
        GASValue::ToStringImpl(this: (unsigned __int8 *)v157, a2: (int *)&v158, a3, precision: -1, debug: false);
        if ( LOBYTE(v157[0]) == 2 )
        {
          if ( GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3) != 0 )
            v17 = "left";
          else
            v17 = (const char *)&stru_102A09D0;
        }
        else
        {
          v17 = *(const char **)v158;
        }
        GString::GString(this: (GString *)&v160, src: (int)v17);
        v7 = *(_BYTE *)(*((_DWORD *)this + 17) + 332) & 3;
        HIBYTE(v159) = *((_BYTE *)this + 108) & 1;
        if ( GString::operator==(this: &v160, a2: (const char *)&stru_102A09D0) )
        {
          *((_WORD *)v8 + 114) &= ~1u;
          v18 = *((_DWORD *)this + 17);
          *(_BYTE *)(v18 + 332) &= 0xFCu;
        }
        else
        {
          *((_WORD *)v8 + 114) |= 1u;
          if ( GString::operator==(this: &v160, a2: "left") )
          {
            v18 = *((_DWORD *)this + 17);
            *(_BYTE *)(v18 + 332) &= 0xFCu;
          }
          else if ( GString::operator==(this: &v160, a2: "right") )
          {
            v18 = *((_DWORD *)this + 17);
            *(_BYTE *)(v18 + 332) = *(_BYTE *)(v18 + 332) & 0xFC | 1;
          }
          else
          {
            if ( !GString::operator==(this: &v160, a2: "center") )
              goto LABEL_33;
            v18 = *((_DWORD *)this + 17);
            *(_BYTE *)(v18 + 332) = *(_BYTE *)(v18 + 332) & 0xFC | 2;
          }
        }
        *(_BYTE *)(v18 + 336) |= 1u;
LABEL_33:
        if ( v7 != (*(_BYTE *)(*((_DWORD *)this + 17) + 332) & 3) || HIBYTE(v159) != (*((_BYTE *)this + 108) & 1) )
          GFxEditTextCharacter::UpdateAutosizeSettings(this: (GFxEditTextCharacter *)v8);
        GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
        GString::~GString(this: (GString *)&v160);
        v19 = v158;
        v42 = (*((_DWORD *)v158 + 2))-- == 1;
        if ( v42 )
          GASStringNode::ReleaseNode(a1: (int)v19);
        goto LABEL_38;
      case 0x2Fu:
        HIBYTE(v159) = (*(_BYTE *)(*((_DWORD *)this + 17) + 334) & 8) != 0;
        v20 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        if ( v20 == HIBYTE(v159) )
          goto LABEL_44;
        v21 = *((GFxTextDocView **)this + 17);
        if ( v20 != 0 )
          GFxTextDocView::SetWordWrap(this: v21);
        else
          GFxTextDocView::ClearWordWrap(this: v21);
        goto LABEL_43;
      case 0x30u:
        HIBYTE(v159) = (*(_BYTE *)(*((_DWORD *)this + 17) + 334) & 4) != 0;
        v22 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        if ( HIBYTE(v159) == v22 )
          goto LABEL_44;
        v23 = *((_DWORD *)this + 17);
        if ( v22 != 0 )
          *(_BYTE *)(v23 + 334) |= 4u;
        else
          *(_BYTE *)(v23 + 334) &= ~4u;
LABEL_43:
        GFxEditTextCharacter::UpdateAutosizeSettings(this: (GFxEditTextCharacter *)v8);
        goto LABEL_44;
      case 0x31u:
        *((_BYTE *)this + 87) = -(GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3) != 0);
        goto LABEL_44;
      case 0x32u:
        GASValue::ToStringImpl(this: (unsigned __int8 *)v157, a2: (int *)&v.hInstance, a3, precision: -1, debug: false);
        hInstance = v.hInstance;
        ++*((_DWORD *)v.hInstance + 2);
        v25 = *((_DWORD *)this + 22);
        v42 = (*(_DWORD *)(v25 + 8))-- == 1;
        v7 = (int)hInstance;
        if ( v42 )
          GASStringNode::ReleaseNode(a1: v25);
        v26 = v.hInstance;
        *((_DWORD *)this + 22) = v7;
        v42 = (*((_DWORD *)v26 + 2))-- == 1;
        if ( v42 )
          GASStringNode::ReleaseNode(a1: (int)v26);
        GFxEditTextCharacter::UpdateTextFromVariable(this: (GFxEditTextCharacter *)v8, a2);
        *((_WORD *)v8 + 114) |= 0x4000u;
        v27 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)(*(int (__thiscall **)(char *))(*(_DWORD *)v8 + 84))(a1: v8);
        GFxASCharacter::ModifyOptimizedPlayListLocal<GFxEditTextCharacter>(
          this: (ScaleformRenderer::VertexShaderType)v8,
          result: v27);
        goto LABEL_45;
      case 0x33u:
        v28 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        GFxEditTextCharacter::SetSelectable(this: (GFxEditTextCharacter *)v8, a2: (int)this, a3: v28);
        goto LABEL_45;
      case 0x34u:
        v29 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        v30 = *((_DWORD *)this + 17);
        if ( v29 != 0 )
          *(_BYTE *)(v30 + 334) &= ~0x20u;
        else
          *(_BYTE *)(v30 + 334) |= 0x20u;
        goto LABEL_45;
      case 0x35u:
        GASValue::ToStringImpl(
          this: (unsigned __int8 *)v157,
          a2: (int *)&v.lpszMenuName,
          a3,
          precision: -1,
          debug: false);
        v57 = *(GASStringManager **)(a3[5].dwType + 636);
        HIBYTE(v159) = LOBYTE(a3[5].dwSubType) > 6u;
        ConstStringNode = (void (__cdecl **)(int))GASStringManager::CreateConstStringNode(
                                                    this: v57,
                                                    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029DFB4,
                                                    a3: 6u,
                                                    a4: 0);
        ConstStringNode[2] = (void (__cdecl *)(int))((char *)ConstStringNode[2] + 1);
        v160.m_Memory.m_pMemory = ConstStringNode;
        if ( HIBYTE(v159) != 0 )
        {
          v59 = ConstStringNode == (void (__cdecl **)(int))v.lpszMenuName;
        }
        else
        {
          if ( *((_DWORD *)v160.m_Memory.m_pMemory + 1) == 0 )
            GASStringNode::ResolveLowercase_Impl(a1: (int *)v160.m_Memory.m_pMemory);
          lpszMenuName = v.lpszMenuName;
          if ( *((_DWORD *)v.lpszMenuName + 1) == 0 )
          {
            GASStringNode::ResolveLowercase_Impl(a1: (int *)v.lpszMenuName);
            lpszMenuName = v.lpszMenuName;
          }
          ConstStringNode = v160.m_Memory.m_pMemory;
          v59 = *((_DWORD *)v160.m_Memory.m_pMemory + 1) == *((_DWORD *)lpszMenuName + 1);
        }
        HIBYTE(v159) = v59;
        v42 = ConstStringNode[2] == (void (__cdecl *)(int))1;
        ConstStringNode[2] = (void (__cdecl *)(int))((char *)ConstStringNode[2] - 1);
        if ( v42 )
          GASStringNode::ReleaseNode(a1: (int)v160.m_Memory.m_pMemory);
        if ( HIBYTE(v159) != 0 )
        {
          *(_BYTE *)(*((_DWORD *)this + 17) + 334) &= ~0x40u;
          GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
        }
        else
        {
          v61 = *(GASStringManager **)(a3[5].dwType + 636);
          HIBYTE(v159) = LOBYTE(a3[5].dwSubType) > 6u;
          v62 = GASStringManager::CreateConstStringNode(
                  this: v61,
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"advanced",
                  a3: 8u,
                  a4: 0);
          v7 = (int)v62;
          ++*((_DWORD *)v62 + 2);
          if ( HIBYTE(v159) != 0 )
          {
            v63 = v62 == (struct GASStringNode *)v.lpszMenuName;
          }
          else
          {
            if ( *((_DWORD *)v62 + 1) == 0 )
              GASStringNode::ResolveLowercase_Impl(a1: (int *)v62);
            v64 = v.lpszMenuName;
            if ( *((_DWORD *)v.lpszMenuName + 1) == 0 )
            {
              GASStringNode::ResolveLowercase_Impl(a1: (int *)v.lpszMenuName);
              v64 = v.lpszMenuName;
            }
            v63 = *(_DWORD *)(v7 + 4) == *((_DWORD *)v64 + 1);
          }
          HIBYTE(v159) = v63;
          v42 = (*(_DWORD *)(v7 + 8))-- == 1;
          if ( v42 )
            GASStringNode::ReleaseNode(a1: v7);
          if ( HIBYTE(v159) != 0 )
            *(_BYTE *)(*((_DWORD *)this + 17) + 334) |= 0x40u;
          GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
        }
        goto LABEL_101;
      case 0x36u:
        v32 = GASValue::ToInt32(this: v157, a2: (int)a3, a3: a2, a4: (_SERVICE_STATUS *)a3);
        if ( v32 < 0 )
          v32 = 0;
        GFxTextDocView::SetHScrollOffset(
          this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17),
          hscroll: 20 * v32);
        goto LABEL_44;
      case 0x37u:
        v33 = GASValue::ToInt32(this: v157, a2: (int)a3, a3: a2, a4: (_SERVICE_STATUS *)a3);
        if ( v33 < 1 )
          v33 = 1;
        GFxTextDocView::SetVScrollOffset(
          this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17),
          vscroll: v33 - 1);
        goto LABEL_44;
      case 0x3Au:
        *((_BYTE *)this + 83) = -(GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3) != 0);
        goto LABEL_44;
      case 0x3Bu:
        v34 = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GASNumberUtil::IsNaN(v: v35, u: SLODWORD(v34), u_4: HIDWORD(*(unsigned __int64 *)&v34));
        if ( v36 == 0 )
          *((_DWORD *)this + 20) = GASValue::ToUInt32(this: v157, a2: (int)a3, a3: v34, a4: (_SERVICE_STATUS *)a3)
                                 & 0xFFFFFF
                                 | *((_DWORD *)this + 20) & 0xFF000000;
        goto LABEL_44;
      case 0x3Cu:
        v37 = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GASNumberUtil::IsNaN(v: v38, u: SLODWORD(v37), u_4: HIDWORD(*(unsigned __int64 *)&v37));
        if ( v39 == 0 )
          *((_DWORD *)this + 21) = GASValue::ToUInt32(this: v157, a2: (int)a3, a3: v37, a4: (_SERVICE_STATUS *)a3)
                                 & 0xFFFFFF
                                 | *((_DWORD *)this + 21) & 0xFF000000;
        goto LABEL_44;
      case 0x3Eu:
        GASValue::ToStringImpl(
          this: (unsigned __int8 *)v157,
          a2: (int *)&v.lpszMenuName,
          a3,
          precision: -1,
          debug: false);
        v40 = *(GASStringManager **)(a3[5].dwType + 636);
        HIBYTE(v159) = LOBYTE(a3[5].dwSubType) > 6u;
        m_pMemory = (void (__cdecl **)(int))GASStringManager::CreateConstStringNode(
                                              this: v40,
                                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"dynamic",
                                              a3: 7u,
                                              a4: 0);
        m_pMemory[2] = (void (__cdecl *)(int))((char *)m_pMemory[2] + 1);
        v160.m_Memory.m_pMemory = m_pMemory;
        if ( HIBYTE(v159) != 0 )
        {
          v42 = m_pMemory == (void (__cdecl **)(int))v.lpszMenuName;
        }
        else
        {
          if ( m_pMemory[1] == nullptr )
            GASStringNode::ResolveLowercase_Impl(a1: (int *)v160.m_Memory.m_pMemory);
          v43 = v.lpszMenuName;
          if ( *((_DWORD *)v.lpszMenuName + 1) == 0 )
          {
            GASStringNode::ResolveLowercase_Impl(a1: (int *)v.lpszMenuName);
            v43 = v.lpszMenuName;
          }
          v42 = *((_DWORD *)v160.m_Memory.m_pMemory + 1) == *((_DWORD *)v43 + 1);
          m_pMemory = v160.m_Memory.m_pMemory;
        }
        HIBYTE(v159) = v42;
        v42 = m_pMemory[2] == (void (__cdecl *)(int))1;
        m_pMemory[2] = (void (__cdecl *)(int))((char *)m_pMemory[2] - 1);
        if ( v42 )
          GASStringNode::ReleaseNode(a1: (int)v160.m_Memory.m_pMemory);
        if ( HIBYTE(v159) != 0 )
        {
          v44 = *(_DWORD *)(*((_DWORD *)this + 17) + 284);
          if ( v44 != 0 )
            *(_WORD *)(v44 + 104) |= 1u;
        }
        else
        {
          v45 = *(GASStringManager **)(a3[5].dwType + 636);
          HIBYTE(v159) = LOBYTE(a3[5].dwSubType) > 6u;
          v46 = GASStringManager::CreateConstStringNode(
                  this: v45,
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"input",
                  a3: 5u,
                  a4: 0);
          v7 = (int)v46;
          ++*((_DWORD *)v46 + 2);
          if ( HIBYTE(v159) != 0 )
          {
            v47 = v46 == (struct GASStringNode *)v.lpszMenuName;
          }
          else
          {
            if ( *((_DWORD *)v46 + 1) == 0 )
              GASStringNode::ResolveLowercase_Impl(a1: (int *)v46);
            v48 = v.lpszMenuName;
            if ( *((_DWORD *)v.lpszMenuName + 1) == 0 )
            {
              GASStringNode::ResolveLowercase_Impl(a1: (int *)v.lpszMenuName);
              v48 = v.lpszMenuName;
            }
            v47 = *(_DWORD *)(v7 + 4) == *((_DWORD *)v48 + 1);
          }
          HIBYTE(v159) = v47;
          v42 = (*(_DWORD *)(v7 + 8))-- == 1;
          if ( v42 )
            GASStringNode::ReleaseNode(a1: v7);
          if ( HIBYTE(v159) != 0 && !GFxEditTextCharacter::HasStyleSheet(this: (GFxEditTextCharacter *)v8) )
          {
            EditorKit = GFxEditTextCharacter::CreateEditorKit(this: (GFxEditTextCharacter *)v8, a2: (int)this);
            *((_WORD *)EditorKit + 52) &= ~1u;
          }
        }
        *(_BYTE *)(*((_DWORD *)this + 17) + 336) |= 1u;
LABEL_101:
        v50 = v.lpszMenuName;
        goto LABEL_102;
      case 0x3Fu:
        v52 = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        *(double *)&v.cbClsExtra = v52;
        GASNumberUtil::IsNaN(v: v53, u: SLODWORD(v52), u_4: HIDWORD(*(unsigned __int64 *)&v52));
        if ( v54 == 0 && *(double *)&v.cbClsExtra >= 0.0 )
        {
          v55 = *((_DWORD *)this + 17);
          *(_DWORD *)(v55 + 272) = GASValue::ToUInt32(this: v157, a2: (int)a3, a3: 0.0, a4: (_SERVICE_STATUS *)a3);
        }
        goto LABEL_45;
      case 0x40u:
        v56 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        GFxEditTextCharacter::SetCondenseWhite(this: (GFxEditTextCharacter *)v8, a2: v56);
        goto LABEL_45;
      case 0x41u:
        v65 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        GFxEditTextCharacter::SetMouseWheelEnabled(this: (GFxEditTextCharacter *)v8, a2: v65);
        goto LABEL_45;
      case 0x42u:
        HIBYTE(v159) = (*((_BYTE *)this + 108) & 4) != 0;
        LOBYTE(v158) = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        if ( HIBYTE(v159) != (_BYTE)v158 )
        {
          GFxEditTextCharacter::SetPassword(this: (GFxEditTextCharacter *)v8, a2: (bool)v158);
          v31 = *((_DWORD *)this + 17);
          if ( (_BYTE)v158 != 0 )
            *(_BYTE *)(v31 + 334) |= 0x10u;
          else
            *(_BYTE *)(v31 + 334) &= ~0x10u;
          *(_BYTE *)(*((_DWORD *)this + 17) + 336) |= 2u;
        }
        goto LABEL_44;
      case 0x43u:
        v.hCursor = (HICON__ *)&a3[5];
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
        GASValue::ToStringImpl(this: (unsigned __int8 *)v157, a2: (int *)&v158, a3, precision: -1, debug: false);
        v42 = *((_DWORD *)this + 34) == 0;
        v160.m_Memory.m_pMemory = *(void (__cdecl ***)(int))v158;
        if ( v42 )
        {
          v73 = (GFxEditTextCharacter::ShadowParams *)GNewOverrideBase<323>::operator new(sz: 0x20u);
          v74 = v73 != nullptr
              ? GFxEditTextCharacter::ShadowParams::ShadowParams(this: v73, a2: (struct GASStringContext *)v.hCursor)
              : nullptr;
          *((_DWORD *)this + 34) = v74;
          if ( v74 == nullptr )
          {
            v50 = v158;
            goto LABEL_102;
          }
        }
        v75 = *(_DWORD *)(*((_DWORD *)this + 17) + 316) & 0xFFFFFF;
        **((_BYTE **)this + 34) = *(_BYTE *)(*((_DWORD *)this + 17) + 316);
        *(_BYTE *)(*((_DWORD *)this + 34) + 1) = BYTE1(v75);
        *(_BYTE *)(*((_DWORD *)this + 34) + 2) = BYTE2(v75);
        *(_BYTE *)(*((_DWORD *)this + 17) + 299) |= 1u;
LABEL_158:
        GArrayBase<GArrayData<GPoint<float>,GAllocatorLH<GPoint<float>,2>,GArrayDefaultPolicy>>::Clear(pheapAddr: (CStudioHdr *)(*((_DWORD *)this + 34) + 8));
        GArrayBase<GArrayData<GPoint<float>,GAllocatorLH<GPoint<float>,2>,GArrayDefaultPolicy>>::Clear(pheapAddr: (CStudioHdr *)(*((_DWORD *)this + 34) + 20));
        hbrBackground = nullptr;
        v.lpszMenuName = (const wchar_t *)v160.m_Memory.m_pMemory;
        v.hbrBackground = nullptr;
LABEL_159:
        v77 = v.lpszMenuName;
        while ( 2 )
        {
          v78 = *(_BYTE *)v77;
          if ( *(_BYTE *)v77 != 0 )
          {
            if ( v78 == 115 || v78 == 83 )
            {
              hbrBackground = (HBRUSH__ *)(*((_DWORD *)this + 34) + 8);
              v.hbrBackground = hbrBackground;
              v77 = (const wchar_t *)((char *)v77 + 1);
              continue;
            }
            if ( v78 == 116 || v78 == 84 )
            {
              hbrBackground = (HBRUSH__ *)(*((_DWORD *)this + 34) + 20);
              v.hbrBackground = hbrBackground;
              v77 = (const wchar_t *)((char *)v77 + 1);
              continue;
            }
            if ( v78 == 123 && hbrBackground != nullptr )
            {
              v79 = *((_BYTE *)v77 + 1);
              v80 = (const wchar_t *)((char *)v77 + 1);
              v81 = v80;
              v.lpszMenuName = v80;
              v159 = v80;
              if ( v79 != 0 )
              {
                while ( v79 != 44 )
                {
                  v79 = *((_BYTE *)v81 + 1);
                  v81 = (const wchar_t *)((char *)v81 + 1);
                  v159 = v81;
                  if ( v79 == 0 )
                    goto LABEL_170;
                }
              }
              if ( *(_BYTE *)v81 != 0 )
              {
                v82 = (char *)v81 - (char *)v80;
                if ( v82 <= 23 )
                {
                  memcpy((unsigned __int8 *)&dst, src: (unsigned __int8 *)v.lpszMenuName, count: v82);
                  v83 = *(_DWORD *)v.hCursor;
                  *((_BYTE *)&dst.m_Memory.m_pMemory + v82) = 0;
                  GASStringManager::CreateStringNode(this: *(GASStringManager **)(v83 + 636), result: &dst);
                  v85 = (int)v84;
                  ++v84->m_nGrowSize;
                  LOBYTE(v154[0]) = 5;
                  v154[1] = v84;
                  ++v84->m_nGrowSize;
                  a2 = GASValue::ToNumber(this: v154, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3) * 20.0;
                  *(float *)&v.hIcon = a2;
                  GASValue::~GASValue(this: v154, a2: (int)a3);
                  v42 = (*(_DWORD *)(v85 + 8))-- == 1;
                  if ( v42 )
                    GASStringNode::ReleaseNode(a1: v85);
                  v86 = *((_BYTE *)v159 + 1);
                  v87 = (unsigned __int8 *)v159 + 1;
                  v159 = (const wchar_t *)v87;
                  v88 = v87;
                  if ( v86 != 0 )
                  {
                    while ( v86 != 125 )
                    {
                      v86 = *++v87;
                      v159 = (const wchar_t *)v87;
                      if ( v86 == 0 )
                      {
                        v160.m_Memory.m_pMemory = **(void (__cdecl ****)(int))(*((_DWORD *)this + 34) + 4);
                        goto LABEL_158;
                      }
                    }
                    if ( *v87 != 0 )
                    {
                      v89 = v87 - v88;
                      if ( v89 <= 23 )
                      {
                        memcpy((unsigned __int8 *)&dst, src: v88, count: v89);
                        v90 = *(_DWORD *)v.hCursor;
                        *((_BYTE *)&dst.m_Memory.m_pMemory + v89) = 0;
                        GASStringManager::CreateStringNode(this: *(GASStringManager **)(v90 + 636), result: &dst);
                        v92 = (int)v91;
                        ++v91->m_nGrowSize;
                        LOBYTE(v155[0]) = 5;
                        v155[1] = v91;
                        ++v91->m_nGrowSize;
                        *(float *)&v.lpszClassName = GASValue::ToNumber(
                                                       this: v155,
                                                       a2: (int)a3,
                                                       a3: a2,
                                                       result: (_SERVICE_STATUS *)a3)
                                                   * 20.0;
                        GASValue::~GASValue(this: v155, a2: (int)a3);
                        v42 = (*(_DWORD *)(v92 + 8))-- == 1;
                        if ( v42 )
                          GASStringNode::ReleaseNode(a1: v92);
                        hbrBackground = v.hbrBackground;
                        v.cbClsExtra = (int)v.hIcon;
                        a2 = *(float *)&v.lpszClassName;
                        v.cbWndExtra = (int)v.lpszClassName;
                        v.lpszMenuName = (const wchar_t *)((char *)v159 + 1);
                        GArrayBase<GArrayData<GPoint<float>,GAllocatorLH<GPoint<float>,2>,GArrayDefaultPolicy>>::PushBack(
                          this: (CStudioHdr *)v.hbrBackground,
                          a2: (float *)&v.cbClsExtra);
                        goto LABEL_159;
                      }
                    }
                  }
                }
              }
            }
LABEL_170:
            v160.m_Memory.m_pMemory = **(void (__cdecl ****)(int))(*((_DWORD *)this + 34) + 4);
            goto LABEL_158;
          }
          break;
        }
        if ( *(_BYTE *)v160.m_Memory.m_pMemory != 0 )
        {
          GASStringManager::CreateStringNode(
            this: *(GASStringManager **)(*(_DWORD *)v.hCursor + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v160.m_Memory.m_pMemory);
          v94 = v93;
          ++*(_DWORD *)(v93 + 8);
          v95 = *((_DWORD *)this + 34);
          ++*(_DWORD *)(v93 + 8);
          v96 = *(_DWORD *)(v95 + 4);
          v7 = -1;
          v42 = (*(_DWORD *)(v96 + 8))-- == 1;
          if ( v42 )
            GASStringNode::ReleaseNode(a1: v96);
          *(_DWORD *)(v95 + 4) = v94;
          v42 = (*(_DWORD *)(v94 + 8))-- == 1;
          if ( v42 )
          {
            GASStringNode::ReleaseNode(a1: v94);
            v50 = v158;
            v51 = (*((_DWORD *)v158 + 2))-- == 1;
            goto LABEL_103;
          }
        }
        else
        {
          v7 = -1;
        }
        v50 = v158;
        v51 = (*((_DWORD *)v158 + 2))-- == 1;
LABEL_103:
        if ( v51 )
          GASStringNode::ReleaseNode(a1: (int)v50);
LABEL_45:
        GASValue::~GASValue(this: v157, a2: v7);
        v16 = true;
        break;
      case 0x44u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
        v97 = *((_DWORD *)this + 17);
        *(_DWORD *)(v97 + 316) = GASValue::ToUInt32(this: v157, a2: (int)a3, a3: a2, a4: (_SERVICE_STATUS *)a3)
                               & 0xFFFFFF
                               | (*(unsigned __int8 *)(v97 + 303) << 24);
        v98 = *((_BYTE **)this + 34);
        if ( v98 != nullptr )
        {
          v99 = *(_DWORD *)(*((_DWORD *)this + 17) + 316) & 0xFFFFFF;
          *v98 = *(_BYTE *)(*((_DWORD *)this + 17) + 316);
          *(_BYTE *)(*((_DWORD *)this + 34) + 1) = BYTE1(v99);
          *(_BYTE *)(*((_DWORD *)this + 34) + 2) = BYTE2(v99);
        }
        goto LABEL_45;
      case 0x45u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v100 = (tagPOLYTEXTW *)(*(int (__thiscall **)(char *))(*(_DWORD *)v8 + 112))(a1: v8);
        v101 = GASValue::ToBool(a1: (char *)v157, a2, result: v100);
        GFxASCharacter::SetHitTestDisableFlag(
          this: (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v8,
          v: (const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v101);
        goto LABEL_45;
      case 0x46u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v102 = (tagPOLYTEXTW *)(*(int (__thiscall **)(char *))(*(_DWORD *)v8 + 112))(a1: v8);
        v103 = GASValue::ToBool(a1: (char *)v157, a2, result: v102);
        GFxEditTextCharacter::SetNoTranslate(this: (GFxEditTextCharacter *)v8, a2: v103);
        *(_BYTE *)(*((_DWORD *)this + 17) + 336) |= 2u;
        goto LABEL_45;
      case 0x49u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        GASValue::ToStringImpl(this: (unsigned __int8 *)v157, a2: (int *)&v158, a3, precision: -1, debug: false);
        GString::GString(this: (GString *)&v160, src: *(_DWORD *)v158);
        if ( GString::operator==(this: &v160, a2: (const char *)&stru_102A09D0) )
        {
          *(_BYTE *)(*((_DWORD *)this + 17) + 334) &= ~2u;
          v126 = *((_DWORD *)this + 17);
          *(_BYTE *)(v126 + 332) &= 0xF3u;
        }
        else
        {
          GFxTextDocView::SetAutoSizeY(this: *((GFxTextDocView **)this + 17));
          if ( GString::operator==(this: &v160, a2: "top") )
          {
            v126 = *((_DWORD *)this + 17);
            *(_BYTE *)(v126 + 332) = *(_BYTE *)(v126 + 332) & 0xF3 | 4;
          }
          else if ( GString::operator==(this: &v160, a2: (const char *)&stru_102A3488.m_Size) )
          {
            v126 = *((_DWORD *)this + 17);
            *(_BYTE *)(v126 + 332) = *(_BYTE *)(v126 + 332) & 0xF3 | 8;
          }
          else
          {
            if ( !GString::operator==(this: &v160, a2: "center") )
              goto LABEL_244;
            v126 = *((_DWORD *)this + 17);
            *(_BYTE *)(v126 + 332) |= 0xCu;
          }
        }
        *(_BYTE *)(v126 + 336) |= 1u;
LABEL_244:
        (*(void (__thiscall **)(char *))(*(_DWORD *)v8 + 352))(a1: v8);
LABEL_245:
        GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
        GString::~GString(this: (GString *)&v160);
        v50 = v158;
        goto LABEL_102;
      case 0x4Au:
        if ( *(_BYTE *)(a3[5].dwType + 684) == 1 )
        {
          v127 = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
          if ( v127 <= 0.0 || v127 >= 1000.0 )
          {
            GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
          }
          else
          {
            *(float *)&v.lpszClassName = v127;
            GFxTextDocView::SetFontScaleFactor(this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this
                                                     + 17));
            GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
          }
        }
        goto LABEL_311;
      case 0x4Bu:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        GASValue::ToStringImpl(this: (unsigned __int8 *)v157, a2: (int *)&v158, a3, precision: -1, debug: false);
        GString::GString(this: (GString *)&v160, src: *(_DWORD *)v158);
        if ( GString::operator==(this: &v160, a2: (const char *)&stru_102A09D0) )
        {
          v128 = *((_DWORD *)this + 17);
          *(_BYTE *)(v128 + 332) &= 0xF3u;
          *(_BYTE *)(v128 + 336) |= 1u;
        }
        else if ( GString::operator==(this: &v160, a2: "top") )
        {
          v129 = *((_DWORD *)this + 17);
          *(_BYTE *)(v129 + 332) = *(_BYTE *)(v129 + 332) & 0xF3 | 4;
          *(_BYTE *)(v129 + 336) |= 1u;
        }
        else if ( GString::operator==(this: &v160, a2: (const char *)&stru_102A3488.m_Size) )
        {
          v130 = *((_DWORD *)this + 17);
          *(_BYTE *)(v130 + 332) = *(_BYTE *)(v130 + 332) & 0xF3 | 8;
          *(_BYTE *)(v130 + 336) |= 1u;
        }
        else if ( GString::operator==(this: &v160, a2: "center") )
        {
          v131 = *((_DWORD *)this + 17);
          *(_BYTE *)(v131 + 332) |= 0xCu;
          *(_BYTE *)(v131 + 336) |= 1u;
        }
        goto LABEL_245;
      case 0x4Cu:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        GASValue::ToStringImpl(this: (unsigned __int8 *)v157, a2: (int *)&v158, a3, precision: -1, debug: false);
        GString::GString(this: (GString *)&v.hCursor, src: *(_DWORD *)v158);
        if ( GString::operator==(
               this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v.hCursor,
               a2: (const char *)&stru_102A09D0) )
        {
          v132 = *((_DWORD *)this + 17);
          *(_BYTE *)(v132 + 332) &= 0xCFu;
        }
        else if ( GString::operator==(
                    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v.hCursor,
                    a2: (const char *)&stru_102A3488) )
        {
          v132 = *((_DWORD *)this + 17);
          *(_BYTE *)(v132 + 332) = *(_BYTE *)(v132 + 332) & 0xCF | 0x10;
        }
        else
        {
          if ( !GString::operator==(
                  this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v.hCursor,
                  a2: (const char *)&stru_102A3488.m_Memory.m_nGrowSize) )
            goto LABEL_268;
          v132 = *((_DWORD *)this + 17);
          *(_BYTE *)(v132 + 332) = *(_BYTE *)(v132 + 332) & 0xCF | 0x20;
        }
        *(_BYTE *)(v132 + 336) |= 1u;
LABEL_268:
        GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
        GString::~GString(this: (GString *)&v.hCursor);
        v50 = v158;
LABEL_102:
        v51 = v50[2]-- == 1;
        goto LABEL_103;
      case 0x4Du:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v133 = (tagPOLYTEXTW *)(*(int (__thiscall **)(char *))(*(_DWORD *)v8 + 112))(a1: v8);
        v134 = GASValue::ToBool(a1: (char *)v157, a2, result: v133);
        GFxEditTextCharacter::SetUseRichClipboard(this: (GFxEditTextCharacter *)v8, a2: v134);
        v135 = *(_DWORD *)(*((_DWORD *)this + 17) + 284);
        if ( v135 != 0 )
        {
          if ( (*((_BYTE *)this + 109) & 1) != 0 )
            *(_WORD *)(v135 + 104) |= 4u;
          else
            *(_WORD *)(v135 + 104) &= ~4u;
        }
        goto LABEL_45;
      case 0x4Eu:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v136 = (tagPOLYTEXTW *)(*(int (__thiscall **)(char *))(*(_DWORD *)v8 + 112))(a1: v8);
        v137 = GASValue::ToBool(a1: (char *)v157, a2, result: v136);
        GFxEditTextCharacter::SetAlwaysShowSelection(this: (GFxEditTextCharacter *)v8, a2: v137);
        goto LABEL_45;
      case 0x51u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v139 = *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)(*((_DWORD *)this + 17) + 284);
        if ( v139 == nullptr )
          goto LABEL_311;
        v139[22].pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)GASValue::ToUInt32(this: v157, a2: (int)a3, a3: a2, a4: (_SERVICE_STATUS *)a3);
        GFxTextEditorKit::InvalidateSelectionColors(this: v139, a2: v153);
        goto LABEL_45;
      case 0x52u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v138 = *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)(*((_DWORD *)this + 17) + 284);
        if ( v138 == nullptr )
          goto LABEL_311;
        v138[23].pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)GASValue::ToUInt32(this: v157, a2: (int)a3, a3: a2, a4: (_SERVICE_STATUS *)a3);
        GFxTextEditorKit::InvalidateSelectionColors(this: v138, a2: v153);
        goto LABEL_45;
      case 0x53u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v141 = *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)(*((_DWORD *)this + 17) + 284);
        if ( v141 == nullptr )
          goto LABEL_311;
        v141[24].pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)GASValue::ToUInt32(this: v157, a2: (int)a3, a3: a2, a4: (_SERVICE_STATUS *)a3);
        GFxTextEditorKit::InvalidateSelectionColors(this: v141, a2: v153);
        goto LABEL_45;
      case 0x54u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v140 = *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)(*((_DWORD *)this + 17) + 284);
        if ( v140 == nullptr )
          goto LABEL_311;
        v140[25].pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)GASValue::ToUInt32(this: v157, a2: (int)a3, a3: a2, a4: (_SERVICE_STATUS *)a3);
        GFxTextEditorKit::InvalidateSelectionColors(this: v140, a2: v153);
        goto LABEL_45;
      case 0x55u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v142 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        GFxEditTextCharacter::SetNoAutoSelection(this: (GFxEditTextCharacter *)v8, a2: v142);
        goto LABEL_45;
      case 0x56u:
        if ( *(_BYTE *)(a3[5].dwType + 684) == 1 )
        {
          v143 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
          GFxEditTextCharacter::SetIMEDisabledFlag(this: (GFxEditTextCharacter *)v8, a2: v143);
        }
        else
        {
LABEL_292:
          v144 = (struct GASValue *)GASValue::ToObject(this: v157, a2: (int)a3, (const struct GASEnvironment *)a3);
          v158 = v144;
          if ( v144 != nullptr )
          {
            Prototype = GASGlobalContext::GetPrototype(
                          this: (vc_attributes::PreRangeAttribute *)a3[5].dwType,
                          result: (vc_attributes::InvalidCheckAttribute *)2);
            if ( (*(unsigned __int8 (__thiscall **)(int, tagRID_DEVICE_INFO_KEYBOARD *, vc_attributes::InvalidCheckAttribute *, int))(*((_DWORD *)v144 + 4) + 72))(
                   a1: (int)v144 + 16,
                   a2: a3,
                   a3: Prototype,
                   a4: 1) != 0 )
            {
              GFxTextFilter::GFxTextFilter(this: (CDummyTexture *)&v160.m_Size);
              v146 = nullptr;
              HIBYTE(v159) = 0;
              v.hbrBackground = nullptr;
              if ( *((int *)v144 + 15) > 0 )
              {
                do
                {
                  v147 = *(GASValue **)(*((_DWORD *)v144 + 14) + 4 * (_DWORD)v146);
                  if ( v147 != nullptr )
                  {
                    v148 = GASValue::ToObject(this: v147, a2: (int)a3, (const struct GASEnvironment *)a3);
                    if ( v148 != nullptr )
                    {
                      v149 = GASGlobalContext::GetPrototype(
                               this: (vc_attributes::PreRangeAttribute *)a3[5].dwType,
                               result: (vc_attributes::InvalidCheckAttribute *)0x25);
                      if ( ((unsigned __int8 (__thiscall *)(struct GASObject *, tagRID_DEVICE_INFO_KEYBOARD *, vc_attributes::InvalidCheckAttribute *, int))v148[2].pNode[9].pNext)(
                             a1: &v148[2],
                             a2: a3,
                             a3: v149,
                             a4: 1) != 0 )
                      {
                        GFxTextFilter::LoadFilterDesc(
                          this: (GFxTextFilter *)&v160.m_Size,
                          a2: (const struct GFxFilterDesc *)&v148[6].sequence);
                        HIBYTE(v159) = 1;
                      }
                    }
                    v144 = v158;
                  }
                  v146 = (HBRUSH__ *)((char *)v.hbrBackground + 1);
                  v.hbrBackground = v146;
                }
                while ( (int)v146 < *((_DWORD *)v144 + 15) );
                if ( HIBYTE(v159) != 0 )
                {
                  (*(void (__thiscall **)(char *, int *))(*(_DWORD *)v8 + 464))(a1: v8, a2: &v160.m_Size);
                  GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
                }
              }
              GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v160.m_Size);
            }
          }
        }
        goto LABEL_45;
      case 0x5Au:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v104 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        v105 = *((_DWORD *)this + 17);
        if ( v104 != 0 )
          *(_BYTE *)(v105 + 334) |= 0x80u;
        else
          *(_BYTE *)(v105 + 334) &= ~0x80u;
        goto LABEL_44;
      case 0x5Bu:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v106 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        *(float *)&v.lpszClassName = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GFxTextDocView::SetBlurX(this: v106, v: *(float *)&v.lpszClassName);
        goto LABEL_44;
      case 0x5Cu:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v107 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        *(float *)&v.lpszClassName = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GFxTextDocView::SetBlurY(this: v107, v: *(float *)&v.lpszClassName);
        goto LABEL_44;
      case 0x5Du:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v108 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        *(float *)&v.lpszClassName = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GFxTextDocView::SetBlurStrength(this: v108, v: *(float *)&v.lpszClassName);
        goto LABEL_44;
      case 0x5Eu:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v109 = *((_DWORD *)this + 17);
        v.lpszClassName = (const wchar_t *)(int)GASValue::ToNumber(
                                                  this: v157,
                                                  a2: (int)a3,
                                                  a3: a2,
                                                  result: (_SERVICE_STATUS *)a3);
        *(_BYTE *)(v109 + 333) = v.lpszClassName;
        goto LABEL_44;
      case 0x5Fu:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v110 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        v111 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        GFxTextDocView::SetFauxBold(this: v110, f: v111);
        goto LABEL_44;
      case 0x60u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        v112 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        v113 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        GFxTextDocView::SetFauxItalic(this: v112, f: v113);
        goto LABEL_44;
      case 0x61u:
        if ( LOBYTE(v157[0]) < 2u || LOBYTE(v157[0]) == 10 )
        {
          v151 = *((void ***)this + 35);
          if ( v151 != nullptr )
          {
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v151);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v151);
          }
          *((_DWORD *)this + 35) = 0;
        }
        else
        {
          GASValue::ToStringImpl(this: (unsigned __int8 *)v157, a2: (int *)&v158, a3, precision: -1, debug: false);
          GFxEditTextCharacter::ParseRestrict(
            this: (GFxEditTextCharacter *)v8,
            a2: (bool (__cdecl ***)(const char *const *, const char *const *))&v158);
          v150 = v158;
          v42 = (*((_DWORD *)v158 + 2))-- == 1;
          if ( v42 )
            GASStringNode::ReleaseNode(a1: (int)v150);
        }
        goto LABEL_311;
      case 0x62u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        *(_BYTE *)(*((_DWORD *)this + 17) + 299) &= ~1u;
        v114 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        *(float *)&v.lpszClassName = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GFxTextDocView::SetShadowAlpha(this: v114, a: *(float *)&v.lpszClassName);
        goto LABEL_44;
      case 0x63u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        *(_BYTE *)(*((_DWORD *)this + 17) + 299) &= ~1u;
        v115 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        *(float *)&v.lpszClassName = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GFxTextDocView::SetShadowAngle(this: v115, a: *(float *)&v.lpszClassName);
        goto LABEL_44;
      case 0x64u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        *(_BYTE *)(*((_DWORD *)this + 17) + 299) &= ~1u;
        v116 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        *(float *)&v.lpszClassName = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GFxTextDocView::SetShadowBlurX(this: v116, v: *(float *)&v.lpszClassName);
        goto LABEL_44;
      case 0x65u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        *(_BYTE *)(*((_DWORD *)this + 17) + 299) &= ~1u;
        v117 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        *(float *)&v.lpszClassName = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GFxTextDocView::SetShadowBlurY(this: v117, v: *(float *)&v.lpszClassName);
        goto LABEL_44;
      case 0x66u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        *(_BYTE *)(*((_DWORD *)this + 17) + 299) &= ~1u;
        v118 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        *(float *)&v.lpszClassName = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GFxTextDocView::SetShadowDistance(this: v118, d: *(float *)&v.lpszClassName);
        goto LABEL_44;
      case 0x67u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        *(_BYTE *)(*((_DWORD *)this + 17) + 299) &= ~1u;
        v119 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        v120 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        GFxTextDocView::SetHideObject(this: v119, f: v120);
        goto LABEL_44;
      case 0x68u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        *(_BYTE *)(*((_DWORD *)this + 17) + 299) &= ~1u;
        v121 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        v122 = GASValue::ToBool(a1: (char *)v157, a2, result: (tagPOLYTEXTW *)a3);
        GFxTextDocView::SetKnockOut(this: v121, f: v122);
        goto LABEL_44;
      case 0x69u:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        *(_BYTE *)(*((_DWORD *)this + 17) + 299) &= ~1u;
        v123 = *((GRefCountBase<GFxAmpMemSegment,2> **)this + 17);
        v124 = GASValue::ToUInt32(this: v157, a2: (int)a3, a3: a2, a4: (_SERVICE_STATUS *)a3);
        GFxTextDocView::SetShadowQuality(this: v123, v: v124);
        goto LABEL_44;
      case 0x6Au:
        if ( *(_BYTE *)(a3[5].dwType + 684) != 1 )
          goto LABEL_311;
        *(_BYTE *)(*((_DWORD *)this + 17) + 299) &= ~1u;
        v125 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 17);
        *(float *)&v.lpszClassName = GASValue::ToNumber(this: v157, a2: (int)a3, a3: a2, result: (_SERVICE_STATUS *)a3);
        GFxTextDocView::SetShadowStrength(this: v125, v: *(float *)&v.lpszClassName);
LABEL_44:
        GFxEditTextCharacter::SetDirtyFlag(this: (GFxEditTextCharacter *)v8);
        goto LABEL_45;
      default:
LABEL_311:
        v152 = GFxASCharacter::SetMember(
                 (CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *)this,
                 a2: (struct GASEnvironment *)a3,
                 name: (_IMAGE_SYMBOL_EX *)v.hbrBackground,
                 val: (tagWNDCLASSW *)v157,
                 flags: (const struct GASPropFlags *)v.hIcon);
        GASValue::~GASValue(this: v157, a2: (int)a3);
        return v152;
    }
  }
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x100F4570
// Name: public: static class GASFunctionRef GASTextFieldCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASTextFieldCtorFunction::Register(struct GASFunctionRef *a1, _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // esi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // edi
  void *v7; // ecx
  GASCFunctionObject *v8; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v11)(const char *, int, _KCRM_MARSHAL_HEADER **); // eax
  GASTextFieldProto *v12; // ebx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASTextFieldProto *v14; // eax
  _DWORD *v15; // eax
  int v16; // ebx
  GASValue *v17; // eax
  GASValue v19[4]; // [esp+Ch] [ebp-1Ch] BYREF
  GSize<int> v20; // [esp+1Ch] [ebp-Ch] BYREF
  _DWORD *v21; // [esp+24h] [ebp-4h]
  struct GASFunctionRef *v22; // [esp+30h] [ebp+8h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  v20.Width = (int)pgc;
  LOBYTE(v20.Height) = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASCFunctionObject *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&v20,
      a3: (void (__cdecl *)(const struct GASFnCall *))CDummyMaterialSystem::EndBatch);
    v6->dwSize = (unsigned int)&GASTextFieldCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    GASNameFunction::AddConstMembers(
      pobj: v7,
      psc: (int)&v6->cLineHeight,
      psca: (CTSQueue<CFunctor *,0,1>::Node_t *)&v20,
      a4: (struct GASObject **)GAS_TextFieldStaticFunctionTable,
      a5: 7);
    v8 = v6;
  }
  else
  {
    v8 = nullptr;
  }
  *(_DWORD *)a1 = v8;
  *((_BYTE *)a1 + 8) = 0;
  *((_DWORD *)a1 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)MaxVal + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v12 = (GASTextFieldProto *)v11(a1: MaxVal, a2: 92, a3: &pgc);
  if ( v12 != nullptr )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    v14 = GASTextFieldProto::GASTextFieldProto(this: v12, result: (IVguiMatInfo *)&v20, a3: Prototype, a4: a1);
    v22 = v14;
  }
  else
  {
    v22 = nullptr;
    v14 = nullptr;
  }
  if ( v14 != nullptr )
    *((_DWORD *)v14 + 2) = (*((_DWORD *)v14 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: 10, a2: v14);
  v15 = v2[56].MaxVal + 16;
  HIBYTE(pgc) = 0;
  v16 = *v15;
  v21 = v15;
  v17 = GASValue::GASValue(this: v19, a2: (int)a1, a3: a1);
  (*(void (__thiscall **)(_DWORD *, GSize<int> *, vc_attributes::PreRangeAttribute *, GASValue *, char *))(v16 + 40))(
    a1: v21,
    a2: &v20,
    a3: v2 + 4,
    a4: v17,
    a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v19, a2: (int)a1);
  GASGlobalContext::AddBuiltinClassRegistry<33,GASStyleSheetCtorFunction>(
    this: (float *)&v2->Deref,
    result: &v20,
    a3: *(_DWORD *)a1);
  if ( v22 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v22, a2: (int)a1);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x1015EDD0
// Name: unsigned int G_LowerBoundSliced<struct GFxSGMLElementDesc const __near *,struct GFxSGMLElementDesc::Comparable<wchar_t>,int (*)(struct GFxSGMLElementDesc const __near &,struct GFxSGMLElementDesc::Comparable<wchar_t> const __near &)>(struct GFxSGMLElementDesc const __near * const __near &,unsigned int,unsigned int,struct GFxSGMLElementDesc::Comparable<wchar_t> const __near &,int (*)(struct GFxSGMLElementDesc const __near &,struct GFxSGMLElementDesc::Comparable<wchar_t> const __near &))
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_LowerBoundSliced<GFxSGMLElementDesc const *,GFxSGMLElementDesc::Comparable<wchar_t>,int (__cdecl *)(GFxSGMLElementDesc const &,GFxSGMLElementDesc::Comparable<wchar_t> const &)>(
        _DWORD *a1,
        int a2,
        int a3,
        int a4,
        int (__cdecl *a5)(int, int))
{
  int result; // eax
  int i; // ebx
  int v7; // edi

  result = a2;
  for ( i = a3 - a2; i > 0; result = a2 )
  {
    v7 = (i >> 1) + result;
    if ( a5(a1: *a1 + 12 * v7, a2: a4) != 0 )
    {
      a2 = v7 + 1;
      i += -1 - (i >> 1);
    }
    else
    {
      i >>= 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015EF20
// Name: public: GRangeData<class GPtr<class GFxTextFormat>>::GRangeData<class GPtr<class GFxTextFormat>>(class GRangeData<class GPtr<class GFxTextFormat>> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GRangeData<GPtr<GFxTextFormat>>::GRangeData<GPtr<GFxTextFormat>>(_DWORD *this, _DWORD *a2)
{
  int v3; // eax
  IShaderDevice *v4; // ecx

  v3 = a2[1];
  *this = *a2;
  *(this + 1) = v3;
  v4 = (IShaderDevice *)a2[2];
  if ( v4 != nullptr )
    GRefCountImpl::AddRef(this: v4);
  *(this + 2) = a2[2];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015EF50
// Name: public: class GRangeData<class GPtr<class GFxTextFormat>> __near & GRangeData<class GPtr<class GFxTextFormat>>::operator=(class GRangeData<class GPtr<class GFxTextFormat>> const __near &)
// Source: json
//------------------------------------------------------------------------------
IShaderAPI **__thiscall GRangeData<GPtr<GFxTextFormat>>::operator=(IShaderAPI **this, IShaderAPI **a2)
{
  IShaderDevice *v3; // ecx
  IShaderAPI *v4; // ecx

  *this = *a2;
  *(this + 1) = a2[1];
  v3 = (IShaderDevice *)a2[2];
  if ( v3 != nullptr )
    GRefCountImpl::AddRef(this: v3);
  v4 = *(this + 2);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  *(this + 2) = a2[2];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10160660
// Name: public: void GRangeDataArray<class GPtr<class GFxTextFormat>,class GArrayLH<class GRangeData<class GPtr<class GFxTextFormat>>,2,struct GArrayDefaultPolicy>>::ExpandRange(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::ExpandRange(
        GFxZlibSupportBase *this,
        int a2,
        int a3)
{
  volatile int RefCount; // edi
  int v5; // eax
  int v6; // ecx
  GFxZlibSupportBase_vtbl *v7; // eax
  GFile *(__thiscall *CreateZlibFile)(GFxZlibSupportBase *, GFile *); // edx
  volatile int v9; // eax
  int v10; // edx

  RefCount = this->RefCount;
  if ( RefCount != 0 )
  {
    GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(this, index: a2);
    if ( v5 >= 0 )
    {
      v6 = RefCount - 1;
      if ( v5 < (unsigned int)RefCount )
        v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    if ( v6 < RefCount )
    {
      v7 = &this->__vftable[v6];
      if ( v7 != nullptr )
      {
        if ( a2 >= (int)v7->dtr_GRefCountImplCore
          && (CreateZlibFile = v7->CreateZlibFile,
              a2 <= (int)((int)CreateZlibFile + (unsigned int)v7->dtr_GRefCountImplCore - 1))
          || (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))((char *)(CreateZlibFile = v7->CreateZlibFile)
                                                                  + (unsigned int)v7->dtr_GRefCountImplCore) == (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))a2 )
        {
          v7->CreateZlibFile = (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))((char *)CreateZlibFile + a3);
        }
      }
    }
    v9 = this->RefCount;
    if ( v6 < v9 )
      ++v6;
    v10 = v6;
    while ( v6 >= 0 && v6 < (unsigned int)v9 )
    {
      this->__vftable[v10].dtr_GRefCountImplCore = (void (__thiscall *)(struct GFxZlibSupportBase *))((char *)this->__vftable[v10].dtr_GRefCountImplCore + a3);
      v9 = this->RefCount;
      if ( v6 < v9 )
      {
        ++v6;
        ++v10;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163060
// Name: public: void GRangeDataArray<class GPtr<class GFxTextFormat>,class GArrayLH<class GRangeData<class GPtr<class GFxTextFormat>>,2,struct GArrayDefaultPolicy>>::SetRange(class GRangeData<class GPtr<class GFxTextFormat>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::SetRange(
        GJPEGSystem *this,
        GRefCountBaseStatImpl<GRefCountNTSImpl,326> *result)
{
  volatile unsigned int RefCount; // edi
  int v4; // eax
  signed int v5; // edi
  GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl *v6; // eax
  int v7; // ebx
  int v8; // ecx
  char *v9; // edx
  int v10; // eax
  volatile int v11; // eax
  volatile int v12; // edx
  IShaderAPI **v13; // ebx
  GJPEGSystem *v14; // ebx
  unsigned int v15; // edx
  unsigned int v16; // eax
  char *v17; // ecx
  int v18; // ebx
  int v19; // eax
  int v20; // ebx
  int v21; // ebx
  volatile unsigned int v22; // eax
  volatile unsigned int v23; // edx
  GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl *v24; // edx
  unsigned int v25; // ebx
  int v26; // eax
  int v27; // ebx
  int v28; // ebx
  int v29; // ecx
  volatile int v30; // ecx
  GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl *v31; // edx
  void (__thiscall **v32)(struct GJPEGSystem *); // eax
  void (__thiscall *v33)(struct GJPEGSystem *); // esi
  void (__thiscall *v34)(struct GJPEGSystem *); // ecx
  unsigned int v35; // esi
  volatile unsigned int v36; // ecx
  void (__thiscall **v37)(struct GJPEGSystem *); // eax
  volatile int v38; // ecx
  unsigned int v39; // eax
  int v40; // edi
  void (__thiscall **v41)(struct GJPEGSystem *); // edx
  int v42; // ecx
  void (__thiscall *v43)(struct GJPEGSystem *); // [esp+8h] [ebp-20h] BYREF
  int v44; // [esp+Ch] [ebp-1Ch]
  IShaderAPI *v45; // [esp+10h] [ebp-18h]
  GJPEGSystem *v46; // [esp+14h] [ebp-14h] BYREF
  signed int v47; // [esp+18h] [ebp-10h]
  GJPEGSystem *v48; // [esp+1Ch] [ebp-Ch]
  int v49; // [esp+20h] [ebp-8h]
  int v50; // [esp+24h] [ebp-4h]

  RefCount = this->RefCount;
  if ( RefCount == 0 )
  {
    GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::InsertAt(
      this,
      index: 0,
      a3: (void (__thiscall **)(struct GJPEGSystem *))result);
    return;
  }
  GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(
    (GFxZlibSupportBase *)this,
    index: (int)result->__vftable);
  v46 = this;
  if ( v4 >= 0 )
  {
    if ( v4 < RefCount )
      v5 = v4;
    else
      v5 = RefCount - 1;
  }
  else
  {
    v5 = 0;
  }
  v6 = result->__vftable;
  v7 = 12 * v5;
  v8 = (int)this->__vftable + 12 * v5;
  v47 = v5;
  if ( (int)v6 < *(_DWORD *)v8
    || (v9 = (char *)v6 + result->RefCount,
        v10 = *(_DWORD *)v8,
        v50 = (int)v9,
        (int)(v9 - 1) > *(_DWORD *)(v8 + 4) + v10 - 1) )
  {
    v24 = result->__vftable;
    if ( (int)result->__vftable < *(_DWORD *)v8
      || (v25 = *(_DWORD *)(v8 + 4), (int)v24 > (int)(v25 + *(_DWORD *)v8 - 1)) )
    {
      GRange::CompareTo(this: (GetTriangles_Vertex_t *)v8, index: (const GetTriangles_Vertex_t *)result->__vftable);
      if ( v26 <= 0 )
      {
        v27 = v5 + 1;
        GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::InsertAt(
          this,
          index: v5 + 1,
          a3: (void (__thiscall **)(struct GJPEGSystem *))result);
        if ( v5 < this->RefCount )
        {
          ++v5;
          v47 = v27;
        }
        v48 = v46;
      }
      else
      {
        GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::InsertAt(
          this,
          index: v5,
          a3: (void (__thiscall **)(struct GJPEGSystem *))result);
        v48 = v46;
      }
      v49 = v5;
      goto LABEL_49;
    }
    if ( *(_DWORD *)v8 + v25 - (unsigned int)v24 <= v25 )
      *(_DWORD *)(v8 + 4) = (char *)v24 - *(_DWORD *)v8;
    else
      *(_DWORD *)(v8 + 4) = 0;
    if ( v5 < this->RefCount )
      v47 = ++v5;
LABEL_34:
    v48 = v46;
    v49 = v5;
    GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::InsertAt(
      this,
      index: v5,
      a3: (void (__thiscall **)(struct GJPEGSystem *))result);
LABEL_49:
    if ( v5 < this->RefCount )
      v47 = ++v5;
    goto LABEL_51;
  }
  v11 = *(_DWORD *)(v8 + 4);
  if ( *(GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl **)v8 == result->__vftable )
  {
    v12 = result->RefCount;
    if ( v12 > v11 )
      v12 = *(_DWORD *)(v8 + 4);
    *(_DWORD *)v8 += v12;
    *(_DWORD *)(v8 + 4) = v11 - v12;
    v13 = (IShaderAPI **)((char *)this->__vftable + v7);
    if ( v13[1] != nullptr )
      GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::InsertAt(
        this,
        index: v5,
        a3: (void (__thiscall **)(struct GJPEGSystem *))result);
    else
      GRangeData<GPtr<GFxTextFormat>>::operator=(this: v13, a2: (IShaderAPI **)result);
    v14 = v46;
    v48 = v46;
    v49 = v5;
    if ( v5 < this->RefCount )
      v47 = ++v5;
    goto LABEL_52;
  }
  if ( *(_DWORD *)v8 + v11 <= v50 )
  {
    v22 = *(_DWORD *)(v8 + 4);
    v23 = result->RefCount;
    if ( v23 <= v22 )
      *(_DWORD *)(v8 + 4) = v22 - v23;
    else
      *(_DWORD *)(v8 + 4) = 0;
    if ( v5 < this->RefCount )
      v47 = ++v5;
    goto LABEL_34;
  }
  GRangeData<GPtr<GFxTextFormat>>::GRangeData<GPtr<GFxTextFormat>>(this: &v43, a2: (_DWORD *)v8);
  v15 = *(unsigned int *)((char *)&this->CreateInput + v7);
  v16 = *((_DWORD *)&this->dtr_GRefCountImplCore + 3 * v5)
      + *((_DWORD *)&this->CreateInput + 3 * v5)
      - (unsigned int)result->__vftable;
  v17 = (char *)this->__vftable + v7;
  if ( v16 <= v15 )
    *((_DWORD *)v17 + 1) = v15 - v16;
  else
    *((_DWORD *)v17 + 1) = 0;
  v18 = *(int *)((char *)&this->CreateInput + v7) + result->RefCount;
  if ( v18 > v44 )
    v18 = v44;
  v43 = (void (__thiscall *)(struct GJPEGSystem *))((char *)v43 + v18);
  v19 = v44 - v18;
  v20 = v5 + 1;
  v44 = v19;
  GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::InsertAt(
    this,
    index: v5 + 1,
    a3: (void (__thiscall **)(struct GJPEGSystem *))result);
  if ( v5 < this->RefCount )
  {
    ++v5;
    v47 = v20;
  }
  v48 = v46;
  v21 = v5 + 1;
  v49 = v5;
  GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::InsertAt(
    this,
    index: v5 + 1,
    a3: &v43);
  if ( v5 < this->RefCount )
  {
    ++v5;
    v47 = v21;
  }
  if ( v45 != nullptr )
    GRefCountImpl::Release(this: v45);
LABEL_51:
  v14 = v48;
LABEL_52:
  if ( !GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: (int *)&v46) )
  {
    v28 = 12 * v5;
    v50 = 12 * v5;
    while ( 1 )
    {
      v29 = *(int *)((char *)&this->dtr_GRefCountImplCore + v28);
      if ( v29 < (int)result->__vftable
        || *(int *)((char *)&this->CreateInput + v28) + v29 - 1 > (int)result->__vftable + result->RefCount - 1 )
      {
LABEL_62:
        v14 = v48;
        break;
      }
      if ( v5 >= 0 && (unsigned int)v5 < this->RefCount )
      {
        if ( this->RefCount != 1 )
        {
          v28 = v50;
          if ( *(GJPEGInput *(__thiscall **)(GJPEGSystem *, const unsigned __int8 *, unsigned int))((char *)&this->CreateSwfJpeg2HeaderOnly
                                                                                                  + v50) != nullptr )
            GRefCountImpl::Release(this: *(IShaderAPI **)((char *)&this->CreateSwfJpeg2HeaderOnly + v50));
          memmove(
            dst: (unsigned __int8 *)this->__vftable + v28,
            src: (unsigned __int8 *)&this->CreateSwfJpeg2HeaderOnly_2 + v28,
            count: 4 * (3 * (this->RefCount - v5) - 3));
          --this->RefCount;
          goto LABEL_61;
        }
        GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
          (int)this,
          pheapAddr: this,
          newSize: 0);
      }
      v28 = v50;
LABEL_61:
      if ( GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: (int *)&v46) )
        goto LABEL_62;
    }
  }
  if ( v5 >= 0 && (unsigned int)v5 < this->RefCount )
  {
    v30 = result->RefCount;
    v31 = result->__vftable;
    v32 = &this->dtr_GRefCountImplCore + 3 * v5;
    if ( (int)result->__vftable + v30 - 1 >= (int)*v32 && (int)v31 + v30 - 1 <= (int)*v32 + (int)v32[1] - 1 )
    {
      v33 = v32[1];
      v34 = (void (__thiscall *)(struct GJPEGSystem *))((char *)v31 + v30 - (_DWORD)*v32);
      if ( (int)v34 > (int)v33 )
        v34 = v32[1];
      *v32 = (void (__thiscall *)(struct GJPEGSystem *))((char *)*v32 + (_DWORD)v34);
      v32[1] = (void (__thiscall *)(struct GJPEGSystem *))((char *)v33 - (char *)v34);
    }
  }
  v35 = v49;
  v47 = v49;
  if ( v49 >= 0 )
  {
    v36 = v49 - 1;
    v47 = v49 - 1;
    if ( v49 - 1 >= 0 && v36 < v14->RefCount )
    {
      v37 = &v14->dtr_GRefCountImplCore + 3 * v36;
      if ( v37[1] != nullptr )
      {
        if ( (char *)v37[1] + (_DWORD)*v37 == (char *)result->__vftable
          && v37[2] == *((void (__thiscall **)(struct GJPEGSystem *))&v14->CreateSwfJpeg2HeaderOnly + 3 * v49) )
        {
          v37[1] = (void (__thiscall *)(struct GJPEGSystem *))((char *)v37[1] + result->RefCount);
          if ( v35 < v14->RefCount )
            GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::RemoveAt(
              this: v14,
              index: v35);
          v48 = v14;
          v49 = v47;
          v35 = v47;
        }
      }
      else
      {
        GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::RemoveAt(
          this: v14,
          index: v49 - 1);
      }
    }
  }
  v38 = v14->RefCount;
  v39 = v35;
  if ( (int)v35 < v38 )
    v39 = v35 + 1;
  if ( (v39 & 0x80000000) == 0 && v39 < v38 )
  {
    v40 = *((_DWORD *)&v14->CreateInput + 3 * v39);
    v41 = &v14->dtr_GRefCountImplCore + 3 * v39;
    if ( v40 == 0
      || (void (__thiscall *)(struct GJPEGSystem *))(*(_DWORD *)(v42 = (int)v14->__vftable + 12 * v35)
                                                   + *(_DWORD *)(v42 + 4)) == *v41
      && *(void (__thiscall **)(struct GJPEGSystem *))(v42 + 8) == v41[2]
      && (*(_DWORD *)(v42 + 4) += v40, v39 < v14->RefCount) )
    {
      GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::RemoveAt(
        this: v14,
        index: v39);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163480
// Name: public: void GRangeDataArray<class GPtr<class GFxTextFormat>,class GArrayLH<class GRangeData<class GPtr<class GFxTextFormat>>,2,struct GArrayDefaultPolicy>>::RemoveRange(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::RemoveRange(
        GFxZlibSupportBase *this,
        GetTriangles_Vertex_t *index,
        unsigned int a3)
{
  volatile unsigned int RefCount; // esi
  const GetTriangles_Vertex_t *v5; // ebx
  int v6; // eax
  signed int v7; // esi
  int dtr_GRefCountImplCore; // edx
  int v9; // ecx
  unsigned int v10; // eax
  GetTriangles_Vertex_t *v11; // ebx
  unsigned int v12; // eax
  bool v13; // zf
  unsigned int v14; // edx
  volatile int v15; // eax
  signed int v16; // ebx
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  char *v20; // eax
  GetTriangles_Vertex_t *v21; // ecx
  int v22; // edx
  GFxZlibSupportBase_vtbl *v23; // eax
  GFile *(__thiscall *CreateZlibFile)(GFxZlibSupportBase *, GFile *); // edi
  GFile *(__thiscall *v25)(GFxZlibSupportBase *, GFile *); // ecx
  unsigned int v26; // eax
  _DWORD *v27; // esi
  unsigned int v28; // ecx
  _DWORD *v29; // eax
  _DWORD *v30; // ecx
  int v31; // ecx
  GFxZlibSupportBase *v32; // [esp+8h] [ebp-14h] BYREF
  signed int v33; // [esp+Ch] [ebp-10h]
  _DWORD *v34; // [esp+10h] [ebp-Ch]
  char *v35; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  RefCount = this->RefCount;
  if ( RefCount == 0 )
    return;
  v5 = index;
  GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(this, (int)index);
  v32 = this;
  if ( v6 >= 0 )
  {
    if ( v6 < RefCount )
      v7 = v6;
    else
      v7 = RefCount - 1;
  }
  else
  {
    v7 = 0;
  }
  v33 = v7;
  if ( a3 == -1 )
    a3 = 0x7FFFFFFF - (_DWORD)index;
  dtr_GRefCountImplCore = (int)this->__vftable[v7].dtr_GRefCountImplCore;
  v9 = (int)&this->__vftable[v7];
  if ( (int)index >= dtr_GRefCountImplCore )
  {
    v10 = *(_DWORD *)(v9 + 4);
    i = v10 + dtr_GRefCountImplCore;
    v35 = (char *)index + a3;
    if ( (int)((int)index + a3 - 1) <= (int)(v10 + dtr_GRefCountImplCore - 1) )
    {
      v11 = *(GetTriangles_Vertex_t **)v9;
      if ( *(GetTriangles_Vertex_t **)v9 == index )
      {
        v12 = a3;
        if ( (signed int)a3 > *(_DWORD *)(v9 + 4) )
          v12 = *(_DWORD *)(v9 + 4);
        v13 = *(_DWORD *)(v9 + 4) == v12;
        *(_DWORD *)(v9 + 4) -= v12;
        *(_DWORD *)v9 = (char *)v11 + v12;
        if ( v13 && v7 >= 0 && (unsigned int)v7 < this->RefCount )
          GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::RemoveAt(
            this,
            index: v7);
        v34 = &v32->__vftable;
        goto LABEL_47;
      }
      v14 = a3;
      if ( i <= (int)v35 )
      {
        if ( a3 <= v10 )
          *(_DWORD *)(v9 + 4) = v10 - a3;
        else
          *(_DWORD *)(v9 + 4) = 0;
        v15 = this->RefCount;
        if ( v7 < v15 )
          v33 = ++v7;
        v34 = &v32->__vftable;
        v16 = v7;
        if ( v7 < v15 )
          v33 = ++v7;
        goto LABEL_48;
      }
      if ( a3 > v10 )
      {
        *(_DWORD *)(v9 + 4) = 0;
        goto LABEL_23;
      }
      goto LABEL_22;
    }
    v5 = index;
  }
  if ( (int)v5 < *(_DWORD *)v9 || (v10 = *(_DWORD *)(v9 + 4), (int)v5 > (int)(v10 + *(_DWORD *)v9 - 1)) )
  {
    GRange::CompareTo(this: (GetTriangles_Vertex_t *)v9, index: v5);
    if ( v17 <= 0 )
    {
      if ( v7 < this->RefCount )
        v33 = ++v7;
      v34 = &v32->__vftable;
    }
    else
    {
      v34 = &v32->__vftable;
    }
    goto LABEL_47;
  }
  v14 = *(_DWORD *)v9 + v10 - (_DWORD)v5;
  if ( v14 <= v10 )
  {
LABEL_22:
    *(_DWORD *)(v9 + 4) = v10 - v14;
    goto LABEL_23;
  }
  *(_DWORD *)(v9 + 4) = 0;
LABEL_23:
  if ( *(_DWORD *)(v9 + 4) != 0 )
  {
    if ( v7 < this->RefCount )
      v33 = ++v7;
    goto LABEL_29;
  }
  if ( v7 < 0 || (unsigned int)v7 >= this->RefCount )
  {
LABEL_29:
    v34 = &v32->__vftable;
    goto LABEL_47;
  }
  GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::RemoveAt(
    this,
    index: v7);
  v34 = &v32->__vftable;
LABEL_47:
  v16 = v7;
LABEL_48:
  if ( GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: (int *)&v32) )
  {
LABEL_61:
    v21 = index;
  }
  else
  {
    v18 = 12 * v7;
    for ( i = 12 * v7; ; v18 = i )
    {
      v19 = *(int *)((char *)&this->dtr_GRefCountImplCore + v18);
      v20 = (char *)this->__vftable + v18;
      v21 = index;
      if ( v19 < (int)index || *((_DWORD *)v20 + 1) + v19 - 1 > (int)((int)index + a3 - 1) )
        break;
      if ( v7 >= 0 && (unsigned int)v7 < this->RefCount )
      {
        if ( this->RefCount == 1 )
        {
          GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
            (int)this,
            pheapAddr: this,
            newSize: 0);
        }
        else
        {
          if ( *(void (__thiscall **)(GFxZlibSupportBase *, struct GFxStream *, void *, int))((char *)&this->InflateWrapper
                                                                                            + i) != nullptr )
            GRefCountImpl::Release(this: *(IShaderAPI **)((char *)&this->InflateWrapper + i));
          memmove(
            dst: (unsigned __int8 *)this->__vftable + i,
            src: (unsigned __int8 *)&this->__vftable[1] + i,
            count: 4 * (3 * (this->RefCount - v7) - 3));
          --this->RefCount;
        }
      }
      if ( GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::Iterator::IsFinished(this: (int *)&v32) )
        goto LABEL_61;
    }
  }
  if ( v7 >= 0 && (unsigned int)v7 < this->RefCount )
  {
    v22 = (int)v21 + a3 - 1;
    v23 = &this->__vftable[v7];
    if ( v22 >= (int)v23->dtr_GRefCountImplCore )
    {
      CreateZlibFile = v23->CreateZlibFile;
      if ( v22 <= (int)((int)CreateZlibFile + (unsigned int)v23->dtr_GRefCountImplCore - 1) )
      {
        v25 = (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))(a3
                                                                   + (char *)v21
                                                                   - (char *)v23->dtr_GRefCountImplCore);
        if ( (int)v25 > (int)CreateZlibFile )
          v25 = v23->CreateZlibFile;
        v23->dtr_GRefCountImplCore = (void (__thiscall *)(struct GFxZlibSupportBase *))((char *)v23->dtr_GRefCountImplCore
                                                                                      + (unsigned int)v25);
        v23->CreateZlibFile = (GFile *(__thiscall *)(GFxZlibSupportBase *, GFile *))((char *)CreateZlibFile - (char *)v25);
      }
    }
  }
  if ( v16 < 0 || (v26 = v16 - 1, v16 - 1 < 0) )
  {
    v27 = v34;
  }
  else
  {
    v27 = v34;
    v28 = v34[1];
    if ( v26 < v28 && v16 < v28 )
    {
      v29 = (_DWORD *)(*v34 + 12 * v26);
      v30 = (_DWORD *)(*v34 + 12 * v16);
      if ( *v29 + v29[1] == *v30 - a3 && v29[2] == v30[2] )
      {
        v29[1] += v30[1];
        if ( (unsigned int)v16 < v27[1] )
          GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::RemoveAt(
            this: v27,
            index: v16);
      }
    }
  }
  v31 = 12 * v16;
  while ( v16 >= 0 && (unsigned int)v16 < v27[1] )
  {
    *(_DWORD *)(*v27 + v31) -= a3;
    if ( v16 < v27[1] )
    {
      ++v16;
      v31 += 12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101638C0
// Name: public: void GRangeDataArray<class GPtr<class GFxTextFormat>,class GArrayLH<class GRangeData<class GPtr<class GFxTextFormat>>,2,struct GArrayDefaultPolicy>>::SetRange(int,unsigned int,class GPtr<class GFxTextFormat> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::SetRange(
        GRefCountBaseStatImpl<GRefCountNTSImpl,326> *this,
        GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl *index,
        volatile int length,
        IShaderAPI **a4)
{
  IShaderAPI *v5; // ecx
  GRefCountBaseStatImpl<GRefCountNTSImpl,326> result; // [esp+8h] [ebp-Ch] BYREF
  IShaderAPI *v7; // [esp+10h] [ebp-4h]

  result.RefCount = length;
  v5 = *a4;
  result.__vftable = index;
  if ( v5 != nullptr )
    GRefCountImpl::AddRef(this: (IShaderDevice *)v5);
  v7 = *a4;
  GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::SetRange(
    (GJPEGSystem *)this,
    &result);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10167B30
// Name: public: class GFxTextLineBuffer::Line __near * GFxTextLineBuffer::Iterator::InsertNewLine(unsigned int,unsigned int,enum GFxTextLineBuffer::LineType)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextLineBuffer::Iterator::InsertNewLine(
        CMaterialSubRect *this,
        unsigned int glyphCount,
        unsigned int formatDataElementsCount,
        int a4)
{
  IMaterialInternal *m_pModelMaterialPage; // eax
  int result; // eax

  m_pModelMaterialPage = this->m_pModelMaterialPage;
  if ( (int)m_pModelMaterialPage < 0 )
    m_pModelMaterialPage = (IMaterialInternal *)this->GetTextureGroupName;
  result = GFxTextLineBuffer::InsertNewLine(
             a1: this->__vftable,
             a2: m_pModelMaterialPage,
             a3: glyphCount,
             a4: formatDataElementsCount,
             a5: a4);
  ++this->m_pModelMaterialPage;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10168760
// Name: public: struct GFxTextImageDesc __near * GFxTextDocView::ImageSubstitutor::FindImageDesc(wchar_t const __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *__thiscall GFxTextDocView::ImageSubstitutor::FindImageDesc(
        _DWORD *this,
        GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *result,
        unsigned int a3,
        unsigned int *ptextLen)
{
  _DWORD *v4; // eax
  int v5; // ecx
  unsigned int v6; // esi
  unsigned int v7; // edi
  int v8; // edx
  unsigned int v9; // esi
  char *v10; // eax
  int v11; // ebx
  int v12; // edi
  int v13; // ecx
  int v14; // esi
  int v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // ebx
  int v20; // [esp+10h] [ebp-1Ch]
  _DWORD *v21; // [esp+14h] [ebp-18h]
  unsigned int v22; // [esp+18h] [ebp-14h]
  unsigned int v23; // [esp+1Ch] [ebp-10h]
  unsigned int v24; // [esp+20h] [ebp-Ch]
  int v25; // [esp+24h] [ebp-8h]
  int v26; // [esp+28h] [ebp-4h]

  v4 = this;
  v5 = *(this + 1);
  v6 = 0;
  v7 = a3;
  v21 = v4;
  v22 = 0;
  v25 = v5;
  if ( v5 > 0 )
  {
    v20 = *v4;
    do
    {
      v8 = v5 >> 1;
      v9 = (v5 >> 1) + v6;
      v10 = (char *)(v20 + 48 * v9);
      v23 = v9;
      v11 = (unsigned __int8)v10[44];
      v26 = v11;
      v24 = v7;
      if ( v7 != 0 )
      {
        v12 = (char *)result - v10;
        do
        {
          v13 = *(unsigned __int16 *)&v10[v12];
          v14 = *(unsigned __int16 *)v10;
          v10 += 2;
          if ( --v24 == 0 || v13 == 0 )
            break;
          if ( v13 != v14 )
            goto LABEL_12;
          --v26;
        }
        while ( v26 != 0 );
        if ( v13 == v14 && v26 != 0 )
        {
          v7 = a3;
          v5 = v25;
          v9 = v23;
          v15 = a3 - v11;
          goto LABEL_14;
        }
LABEL_12:
        v7 = a3;
        v16 = v13 - v14;
        v9 = v23;
        v15 = v16;
        v5 = v25;
      }
      else
      {
        v15 = -v11;
      }
LABEL_14:
      if ( v15 <= 0 )
      {
        v6 = v22;
        v5 = v8;
      }
      else
      {
        v6 = v9 + 1;
        v22 = v6;
        v5 += -1 - v8;
      }
      v25 = v5;
    }
    while ( v5 > 0 );
    v4 = v21;
  }
  if ( v6 >= v4[1] )
    return nullptr;
  v17 = 6 * v6;
  v18 = *v4 + 8 * v17;
  if ( GFxImageSubstCmp::StrCompare(
         a1: (const wchar_t *)result,
         a2: v7,
         a3: (const wchar_t *)v18,
         a4: *(unsigned __int8 *)(v18 + 44),
         a5: false) != 0 )
    return nullptr;
  if ( ptextLen != nullptr )
    *ptextLen = *(unsigned __int8 *)(v18 + 44);
  return *(GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > **)(*v21 + 8 * v17 + 40);
}

//------------------------------------------------------------------------------
// Address: 0x10174A00
// Name: unsigned int G_LowerBoundSliced<class GArrayLH<class GFxTextLineBuffer::Line __near *,2,struct GArrayDefaultPolicy>,float,int (*)(class GFxTextLineBuffer::Line const __near *,float)>(class GArrayLH<class GFxTextLineBuffer::Line __near *,2,struct GArrayDefaultPolicy> const __near &,unsigned int,unsigned int,float const __near &,int (*)(class GFxTextLineBuffer::Line const __near *,float))
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_LowerBoundSliced<GArrayLH<GFxTextLineBuffer::Line *,2,GArrayDefaultPolicy>,float,int (__cdecl *)(GFxTextLineBuffer::Line const *,float)>(
        _DWORD *a1,
        int a2,
        int a3,
        float *a4,
        int (__cdecl *a5)(_DWORD, float))
{
  int result; // eax
  int i; // edi
  int v7; // ebx

  result = a2;
  for ( i = a3 - a2; i > 0; result = a2 )
  {
    v7 = (i >> 1) + result;
    if ( ((int (__cdecl *)(_DWORD, _DWORD))a5)(a1: *(_DWORD *)(*a1 + 4 * v7), a2: *a4) != 0 )
    {
      a2 = v7 + 1;
      i += -1 - (i >> 1);
    }
    else
    {
      i >>= 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019A2B0
// Name: unsigned int G_LowerBoundSliced<class GArrayUnsafeLH_POD<unsigned int,136>,struct GEdgeAA::EdgeType,struct GEdgeAA::EdgeLess>(class GArrayUnsafeLH_POD<unsigned int,136> const __near &,unsigned int,unsigned int,struct GEdgeAA::EdgeType const __near &,struct GEdgeAA::EdgeLess)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_LowerBoundSliced<GArrayUnsafeLH_POD<unsigned int,136>,GEdgeAA::EdgeType,GEdgeAA::EdgeLess>(
        int *a1,
        int a2,
        int a3,
        unsigned int *a4,
        int a5,
        int a6)
{
  int result; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // eax
  unsigned int v10; // esi
  bool v11; // cf
  unsigned int v12; // [esp+4h] [ebp-8h]
  int v13; // [esp+1Ch] [ebp+10h]

  result = a2;
  v7 = a3 - a2;
  if ( a3 - a2 > 0 )
  {
    v13 = *a1;
    v12 = *a4;
    do
    {
      v8 = (v7 >> 1) + result;
      v9 = *(_DWORD *)(*(_DWORD *)(a6 + 12) + 4 * (*(_DWORD *)(v13 + 4 * v8) >> 10));
      v10 = *(_DWORD *)(v9 + 12 * (*(_DWORD *)(v13 + 4 * v8) & 0x3FF));
      v11 = v10 < v12;
      if ( v10 == v12 )
        v11 = *(_DWORD *)(v9 + 12 * (*(_DWORD *)(v13 + 4 * v8) & 0x3FF) + 4) < a4[1];
      if ( v11 )
      {
        result = v8 + 1;
        a2 = v8 + 1;
        v7 += -1 - (v7 >> 1);
      }
      else
      {
        result = a2;
        v7 >>= 1;
      }
    }
    while ( v7 > 0 );
  }
  return result;
}
