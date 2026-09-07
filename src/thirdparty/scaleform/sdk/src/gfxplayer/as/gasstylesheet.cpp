// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasstylesheet.cpp
// Functions: 19
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasstylesheet.h"

//------------------------------------------------------------------------------
// Address: 0x10113870
// Name: public: void GASStyleSheetObject::NotifyOnLoad(class GASEnvironment __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStyleSheetObject::NotifyOnLoad(
        GArrayBase<GArrayData<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > > *this,
        const IClientRenderable *penv,
        _IMAGE_SYMBOL_EX *success)
{
  IClientRenderable *v3; // ebx
  IClientRenderable_vtbl *v5; // eax
  char v6; // cl
  int v7; // edi
  const IClientRenderable *v8; // eax

  v3 = (IClientRenderable *)penv;
  penv[2].__vftable = (IClientRenderable_vtbl *)((char *)penv[2].__vftable + 16);
  if ( v3[2].__vftable >= v3[4].__vftable )
    GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)&v3[2]);
  v5 = v3[2].__vftable;
  if ( v5 != nullptr )
  {
    v6 = (char)success;
    LOBYTE(v5->GetIClientUnknown) = 2;
    LOBYTE(v5->GetRenderOrigin) = v6;
  }
  if ( this != nullptr )
    success = (_IMAGE_SYMBOL_EX *)((char *)this + 16);
  else
    success = nullptr;
  v7 = (((char *)v3[2].__vftable - (char *)v3[3].__vftable) >> 4) + 32 * (int)v3[7].__vftable - 32;
  penv = (const IClientRenderable *)GASStringManager::CreateConstStringNode(
                                      this: (GASStringManager *)v3[30].__vftable[3].MarkShadowDirty,
                                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4098,
                                      a3: 6u,
                                      a4: 0);
  ++penv[2].__vftable;
  GASAsBroadcaster::BroadcastMessage(
    a1: (struct GASEnvironment *)v3,
    eventName: success,
    a3: (const struct GASString *)&penv,
    nArgs: 1,
    firstArgBottomIndex: v7);
  v8 = penv;
  if ( penv[2].__vftable-- == (IClientRenderable_vtbl *)1 )
    GASStringNode::ReleaseNode(a1: (int)v8);
  GASValue::~GASValue(this: (GASValue *)v3[2].__vftable, a2: v7);
  v3[2].__vftable = (IClientRenderable_vtbl *)((char *)v3[2].__vftable - 16);
  if ( v3[2].__vftable < v3[3].__vftable )
    GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)&v3[2]);
}

//------------------------------------------------------------------------------
// Address: 0x101789A0
// Name: public: static void GASStyleSheetProto::Clear(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASStyleSheetProto::Clear(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int *p_cxItem; // eax

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x1Fu) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
    {
      p_cxItem = &v1[-1].cxItem;
      if ( p_cxItem != nullptr )
        GFxTextStyleManager::ClearStyles(this: (GFxTextStyleManager *)(p_cxItem + 13));
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "StyleSheet", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101789E0
// Name: public: static void GASStyleSheetProto::ParseCSS(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASStyleSheetProto::ParseCSS(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int p_cxItem; // edi
  GASFnCall v3; // esi
  tagWNDCLASSW *v4; // eax
  char v5; // al
  GASFnCall v6; // esi
  char v7; // bl
  int v8; // eax
  GASValue v10[4]; // [esp+4h] [ebp-14h] BYREF
  int v11; // [esp+14h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x1Fu) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
    {
      p_cxItem = (int)&v1[-1].cxItem;
      if ( v1 != (GASFnCall)16 )
      {
        if ( (int)a1[7] >= 1 )
        {
          v4 = (tagWNDCLASSW *)GASFnCall::Arg(this: a1, a2: 0);
          GASValue::GASValue(this: v10, v: v4);
          GASValue::ToStringImpl(
            this: (unsigned __int8 *)v10,
            a2: &v11,
            a3: (tagRID_DEVICE_INFO_KEYBOARD *)a1[6],
            precision: -1,
            debug: false);
          v5 = GFxTextStyleManager::ParseCSS(
                 this: (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)(p_cxItem + 52),
                 buffer: *(_DWORD *)v11,
                 len: *(ColorCorrectionLookup_t *const **)(v11 + 16));
          v6 = a1[1];
          v7 = v5;
          GASValue::DropRefs(this: (GASValue *)v6, a2: p_cxItem);
          LOBYTE(v6->cItems) = v7;
          LOBYTE(v6->cbSize) = 2;
          v8 = v11;
          if ( (*(_DWORD *)(v11 + 8))-- == 1 )
            GASStringNode::ReleaseNode(a1: v8);
          GASValue::~GASValue(this: v10, a2: p_cxItem);
        }
        else
        {
          v3 = a1[1];
          GASValue::DropRefs(this: (GASValue *)v3, a2: p_cxItem);
          LOBYTE(v3->cbSize) = 2;
          LOBYTE(v3->cItems) = 0;
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "StyleSheet", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178AB0
// Name: public: virtual enum GASObjectInterface::ObjectType GASStyleSheetObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASStyleSheetObject::GetObjectType()
{
  return 31;
}

//------------------------------------------------------------------------------
// Address: 0x10178BD0
// Name: public: bool GFxTextParagraphFormat::IsLeftAlignment(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextParagraphFormat::IsLeftAlignment(GFxTextParagraphFormat *this)
{
  int result; // eax

  result = 1;
  if ( (*((_BYTE *)this + 22) & 1) == 0 || (*((_WORD *)this + 11) & 0x600) != 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10178BF0
// Name: protected: virtual void GASStyleSheetObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStyleSheetObject::Finalize_GC(
        GArrayBase<GArrayData<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > > *this)
{
  GFxTextStyleManager::~GFxTextStyleManager(this: (GFxTextStyleManager *)((char *)this + 52));
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10178C10
// Name: public: virtual void GFxCSSFileLoaderAndParserImpl::Load(class GString const __near &,class GFxFileOpener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCSSFileLoaderAndParserImpl::Load(
        GFxCSSFileLoaderAndParserImpl *this,
        int a2,
        struct GFxFileOpener *a3)
{
  GFile *v4; // eax
  IShaderAPI *v5; // edi
  int v6; // eax
  void *v7; // eax
  int v8; // ecx

  v4 = a3->OpenFile(this: a3, a2: (*(_DWORD *)a2 & 0xFFFFFFFC) + 8, a3: 33, a4: 438);
  v5 = (IShaderAPI *)v4;
  if ( v4 != nullptr )
  {
    if ( v4->IsValid(this: v4) )
    {
      v6 = ((int (__thiscall *)(IShaderAPI *))v5->SetDefaultState)(a1: v5);
      *((_DWORD *)this + 4) = v6;
      if ( v6 != 0 )
      {
        a2 = 324;
        v7 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: v6 + 2, a3: &a2);
        v8 = *((_DWORD *)this + 4);
        *((_DWORD *)this + 3) = v7;
        ((void (__thiscall *)(IShaderAPI *, void *, int))v5->GetCurrentFogType)(a1: v5, a2: v7, a3: v8);
        *(_BYTE *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 4) + 1) = 0;
        *(_BYTE *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 4)) = 0;
      }
    }
    GRefCountImpl::Release(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178CB0
// Name: public: virtual void CSSStringBuilder::Visit(class GASString const __near &,class GASValue const __near &,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSStringBuilder::Visit(
        CSSStringBuilder *this,
        const char ***a2,
        const struct GASValue *a3,
        unsigned __int8 a4)
{
  const char ***v4; // ebx
  CImagePacker *v5; // edi
  const struct GASString *v7; // eax
  bool v8; // zf

  v4 = a2;
  v5 = (CImagePacker *)**a2;
  if ( strcmp((const char *)v5, "fontFamily") == 0 )
  {
    GString::AppendString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 2),
      putf8str: (CImagePacker *)"font-family",
      utf8StrSz: -1);
  }
  else if ( strcmp(**a2, (const char *)&stru_1029F074) == 0 )
  {
    GString::AppendString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 2),
      putf8str: (CImagePacker *)"font-size",
      utf8StrSz: -1);
  }
  else if ( strcmp(**a2, "fontStyle") == 0 )
  {
    GString::AppendString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 2),
      putf8str: (CImagePacker *)"font-style",
      utf8StrSz: -1);
  }
  else if ( GASString::operator==(this: a2, a2: "fontWeight") )
  {
    GString::AppendString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 2),
      putf8str: (CImagePacker *)"font-weight",
      utf8StrSz: -1);
  }
  else if ( GASString::operator==(this: v4, a2: (const char *)&stru_102A5CC8.m_Memory.m_nGrowSize) )
  {
    GString::AppendString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 2),
      putf8str: (CImagePacker *)"letter-spacing",
      utf8StrSz: -1);
  }
  else if ( GASString::operator==(this: v4, a2: "marginLeft") )
  {
    GString::AppendString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 2),
      putf8str: (CImagePacker *)"margin-left",
      utf8StrSz: -1);
  }
  else if ( GASString::operator==(this: v4, a2: "marginRight") )
  {
    GString::AppendString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 2),
      putf8str: (CImagePacker *)"margin-right",
      utf8StrSz: -1);
  }
  else if ( GASString::operator==(this: v4, a2: "textAlign") )
  {
    GString::AppendString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 2),
      putf8str: (CImagePacker *)"text-align",
      utf8StrSz: -1);
  }
  else if ( GASString::operator==(this: v4, a2: "textDecoration") )
  {
    GString::AppendString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 2),
      putf8str: (CImagePacker *)"text-decoration",
      utf8StrSz: -1);
  }
  else if ( GASString::operator==(this: v4, a2: "textIndent") )
  {
    GString::AppendString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 2),
      putf8str: (CImagePacker *)"text-indent",
      utf8StrSz: -1);
  }
  else
  {
    GString::AppendString(this: *((CUtlMemory<CImagePacker,int> **)this + 2), putf8str: v5, utf8StrSz: -1);
  }
  GString::AppendString(
    this: *((CUtlMemory<CImagePacker,int> **)this + 2),
    putf8str: (CImagePacker *)":",
    utf8StrSz: -1);
  GASValue::ToStringImpl(
    this: (unsigned __int8 *)a3,
    (int *)&a2,
    a3: *((tagRID_DEVICE_INFO_KEYBOARD **)this + 1),
    precision: -1,
    debug: false);
  GString::AppendString(
    this: *((CUtlMemory<CImagePacker,int> **)this + 2),
    putf8str: (CImagePacker *)*a2,
    utf8StrSz: -1);
  v7 = (const struct GASString *)a2;
  v8 = a2[2] == (const char **)1;
  a2[2] = (const char **)((char *)a2[2] - 1);
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v7);
  GString::AppendString(
    this: *((CUtlMemory<CImagePacker,int> **)this + 2),
    putf8str: (CImagePacker *)";",
    utf8StrSz: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10178EC0
// Name: public: static void GASStyleSheetProto::SetStyle(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASStyleSheetProto::SetStyle(GASFnCall *a1)
{
  GASFnCall v1; // ebx
  int *p_cxItem; // ebx
  int v3; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v4; // edi
  unsigned __int8 *v5; // eax
  GASValue *v6; // eax
  struct GASObject *v7; // edi
  int v8; // eax
  bool v9; // zf
  GASFnCall v10; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v11; // edi
  unsigned __int8 *v12; // eax
  int v13; // eax
  CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *v14; // ecx
  const struct GASEnvironment *v15; // [esp-Ch] [ebp-24h]
  _DWORD v16[3]; // [esp+4h] [ebp-14h] BYREF
  int v17; // [esp+10h] [ebp-8h] BYREF
  GString v18; // [esp+14h] [ebp-4h] BYREF

  if ( !GASFnCall::CheckThisPtr(this: a1, type: 0x1Fu) )
  {
    GASFnCall::ThisPtrError(this: a1, a2: "StyleSheet", a3: nullptr, a4: 0);
    return;
  }
  v1 = a1[2];
  if ( v1 != nullptr )
  {
    p_cxItem = &v1[-1].cxItem;
    if ( p_cxItem != nullptr )
    {
      v3 = (int)a1[7];
      if ( v3 >= 1 )
      {
        if ( v3 < 2 || *(_BYTE *)GASFnCall::Arg(this: a1, a2: 1) == 1 )
        {
          v11 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
          v12 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 0);
          GASValue::ToStringImpl(this: v12, a2: &v17, a3: v11, precision: -1, debug: false);
          v13 = v17;
          if ( *(_DWORD *)(v17 + 16) == 0 )
            goto LABEL_17;
          v14 = (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)(p_cxItem + 13);
          if ( **(_BYTE **)v17 == 46 )
            GFxTextStyleManager::ClearStyle(this: v14, type: (ColorCorrectionLookup_t *const *)1);
          else
            GFxTextStyleManager::ClearStyle(this: v14, type: nullptr);
        }
        else
        {
          v4 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
          v5 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 0);
          GASValue::ToStringImpl(this: v5, a2: &v17, a3: v4, precision: -1, debug: false);
          v15 = (const struct GASEnvironment *)a1[6];
          v6 = (GASValue *)GASFnCall::Arg(this: a1, a2: 1);
          v7 = GASValue::ToObject(this: v6, a2: (int)v4, a3: v15);
          if ( v7 == nullptr )
          {
            v8 = v17;
            v9 = (*(_DWORD *)(v17 + 8))-- == 1;
            if ( v9 )
              GASStringNode::ReleaseNode(a1: v8);
            return;
          }
          GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v18);
          GString::AppendString(
            this: (CUtlMemory<CImagePacker,int> *)&v18,
            putf8str: *(CImagePacker **)v17,
            utf8StrSz: -1);
          GString::AppendChar(this: (unsigned int *)&v18, result: (CImagePacker *)0x7B);
          v10 = a1[6];
          v16[2] = &v18;
          v16[1] = v10;
          v16[0] = &CSSStringBuilder::`vftable';
          ((void (__thiscall *)(struct GASObject *, tagALTTABINFO *, _DWORD *, _DWORD, _DWORD))v7[2].pNode[4].pNext)(
            a1: &v7[2],
            a2: &v10[3],
            a3: v16,
            a4: 0,
            a5: 0);
          GString::AppendChar(this: (unsigned int *)&v18, result: (CImagePacker *)0x7D);
          GFxTextStyleManager::ParseCSS(
            this: (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)(p_cxItem + 13),
            buffer: (v18.HeapTypeBits & 0xFFFFFFFC) + 8,
            len: (ColorCorrectionLookup_t *const *)(*(_DWORD *)(v18.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF));
          v16[0] = &GString::InitStruct::`vftable';
          GString::~GString(this: &v18);
        }
        v13 = v17;
LABEL_17:
        v9 = (*(_DWORD *)(v13 + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode(a1: v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10179050
// Name: public: virtual void CSSTextFormatLoader::Visit(class GASString const __near &,class GASValue const __near &,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSSTextFormatLoader::Visit(
        tagRID_DEVICE_INFO_KEYBOARD **this@<ecx>,
        double a2@<st0>,
        const char ***a3,
        const struct GASValue *pfontList,
        unsigned __int8 a5)
{
  const struct GASValue *v6; // edx
  unsigned int v7; // edi
  int v8; // eax
  int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // esi
  int v17; // ecx
  int v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  int v25; // esi
  int v26; // ecx
  bool v27; // zf
  const struct GASValue **v28; // [esp+10h] [ebp-8h] BYREF
  char *endptr; // [esp+14h] [ebp-4h] BYREF
  float result; // [esp+20h] [ebp+8h]
  float v31; // [esp+20h] [ebp+8h]
  float v32; // [esp+20h] [ebp+8h]
  float v33; // [esp+20h] [ebp+8h]
  float v34; // [esp+20h] [ebp+8h]
  const struct GASValue *pfontLista; // [esp+24h] [ebp+Ch]

  GASValue::ToStringImpl(
    this: (unsigned __int8 *)pfontList,
    a2: (int *)&v28,
    a3: *(this + 1),
    precision: -1,
    debug: false);
  v6 = *v28;
  endptr = nullptr;
  v7 = (unsigned int)v28[4];
  pfontLista = v6;
  if ( strcmp(**a3, "color") == 0 )
  {
    v8 = strtol(nptr: (const char *)pfontLista + 1, &endptr, ibase: 16);
    v9 = (int)*(this + 2);
    *(_DWORD *)(v9 + 84) ^= (v8 ^ *(_DWORD *)(v9 + 84)) & 0xFFFFFF;
    *(_WORD *)(v9 + 94) |= 1u;
  }
  else if ( strcmp(**a3, "display") != 0 )
  {
    if ( strcmp(**a3, "fontFamily") == 0 )
    {
      GFxTextFormat::SetFontList(
        this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)&(*(this + 2))[2].dwSubType,
        pfontList: (unsigned int)pfontLista);
    }
    else if ( GASString::operator==(this: a3, a2: (const char *)&stru_1029F074) )
    {
      G_strtod(_Src: (char *)pfontLista, &endptr);
      result = a2;
      GFxTextFormat::SetFontSize(result: (const CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)LODWORD(result));
    }
    else if ( GASString::operator==(this: a3, a2: "fontStyle") )
    {
      v10 = v7;
      if ( v7 >= 4 )
        v10 = 4;
      if ( strncmp(first: (const char *)&stru_1029DFB4, last: (const char *)pfontLista, count: v10) == 0 )
      {
        GFxTextFormat::SetItalic(this: (GFxTextFormat *)&(*(this + 2))[2].dwSubType, a2: false);
      }
      else
      {
        v11 = v7;
        if ( v7 >= 9 )
          v11 = 9;
        if ( strncmp(first: (const char *)&stru_102904EC, last: (const char *)pfontLista, count: v11) == 0 )
          GFxTextFormat::SetItalic(this: (GFxTextFormat *)&(*(this + 2))[2].dwSubType, a2: true);
      }
    }
    else if ( GASString::operator==(this: a3, a2: "fontWeight") )
    {
      v12 = v7;
      if ( v7 >= 6 )
        v12 = 6;
      if ( strncmp(first: (const char *)&stru_1029DFB4, last: (const char *)pfontLista, count: v12) == 0 )
      {
        GFxTextFormat::SetBold(this: (GFxTextFormat *)&(*(this + 2))[2].dwSubType, a2: false);
      }
      else
      {
        v13 = v7;
        if ( v7 >= 4 )
          v13 = 4;
        if ( strncmp(
               first: (const char *)&stru_102904EC.m_Memory.m_nGrowSize,
               last: (const char *)pfontLista,
               count: v13) == 0 )
          GFxTextFormat::SetBold(this: (GFxTextFormat *)&(*(this + 2))[2].dwSubType, a2: true);
      }
    }
    else if ( GASString::operator==(this: a3, a2: (const char *)&stru_102A5CC8) )
    {
      v14 = v7;
      if ( v7 >= 4 )
        v14 = 4;
      if ( strncmp(first: "true", last: (const char *)pfontLista, count: v14) == 0 )
      {
        GFxTextFormat::SetKerning(this: (GFxTextFormat *)&(*(this + 2))[2].dwSubType, a2: false);
      }
      else
      {
        v15 = v7;
        if ( v7 >= 5 )
          v15 = 5;
        if ( strncmp(first: "false", last: (const char *)pfontLista, count: v15) == 0 )
          GFxTextFormat::SetKerning(this: (GFxTextFormat *)&(*(this + 2))[2].dwSubType, a2: true);
      }
    }
    else if ( GASString::operator==(this: a3, a2: (const char *)&stru_102A5CC8.m_Memory.m_nGrowSize) )
    {
      G_strtod(_Src: (char *)pfontLista, &endptr);
      v31 = a2;
      v16 = (int)*(this + 2);
      *(_WORD *)(v16 + 94) |= 2u;
      *(_WORD *)(v16 + 88) = (int)(v31 * 20.0);
    }
    else if ( GASString::operator==(this: a3, a2: "marginLeft") )
    {
      G_strtod(_Src: (char *)pfontLista, &endptr);
      v32 = a2;
      v17 = (int)*(this + 2);
      *(_WORD *)(v17 + 118) |= 0x10u;
      *(_WORD *)(v17 + 114) = (int)v32;
    }
    else if ( GASString::operator==(this: a3, a2: "marginRight") )
    {
      G_strtod(_Src: (char *)pfontLista, &endptr);
      v33 = a2;
      v18 = (int)*(this + 2);
      *(_WORD *)(v18 + 118) |= 0x20u;
      *(_WORD *)(v18 + 116) = (int)v33;
    }
    else if ( GASString::operator==(this: a3, a2: "textAlign") )
    {
      v19 = v7;
      if ( v7 >= 4 )
        v19 = 4;
      if ( strncmp(first: "left", last: (const char *)pfontLista, count: v19) == 0 )
      {
        HIWORD((*(this + 2))[4].dwNumberOfKeysTotal) = HIWORD((*(this + 2))[4].dwNumberOfKeysTotal) & 0xF9FE | 1;
      }
      else
      {
        v20 = v7;
        if ( v7 >= 6 )
          v20 = 6;
        if ( strncmp(first: "center", last: (const char *)pfontLista, count: v20) == 0 )
        {
          HIWORD((*(this + 2))[4].dwNumberOfKeysTotal) |= 0x601u;
        }
        else
        {
          v21 = v7;
          if ( v7 >= 5 )
            v21 = 5;
          if ( strncmp(first: "right", last: (const char *)pfontLista, count: v21) == 0 )
          {
            HIWORD((*(this + 2))[4].dwNumberOfKeysTotal) = HIWORD((*(this + 2))[4].dwNumberOfKeysTotal) & 0xF9FE | 0x201;
          }
          else
          {
            v22 = v7;
            if ( v7 >= 7 )
              v22 = 7;
            if ( strncmp(first: "justify", last: (const char *)pfontLista, count: v22) == 0 )
              HIWORD((*(this + 2))[4].dwNumberOfKeysTotal) = HIWORD((*(this + 2))[4].dwNumberOfKeysTotal) & 0xF9FE
                                                           | 0x401;
          }
        }
      }
    }
    else if ( GASString::operator==(this: a3, a2: "textDecoration") )
    {
      v23 = v7;
      if ( v7 >= 4 )
        v23 = 4;
      if ( strncmp(first: (const char *)&stru_102A09D0, last: (const char *)pfontLista, count: v23) == 0 )
      {
        GFxTextFormat::SetUnderline(this: (GFxTextFormat *)&(*(this + 2))[2].dwSubType, a2: false);
      }
      else
      {
        v24 = v7;
        if ( v7 >= 9 )
          v24 = 9;
        if ( strncmp(
               first: (const char *)&stru_102A5CE0.m_Memory.m_nAllocationCount,
               last: (const char *)pfontLista,
               count: v24) == 0 )
          GFxTextFormat::SetUnderline(this: (GFxTextFormat *)&(*(this + 2))[2].dwSubType, a2: true);
      }
    }
    else if ( GASString::operator==(this: a3, a2: "textIndent") )
    {
      G_strtod(_Src: (char *)pfontLista, &endptr);
      v34 = a2;
      v25 = (int)*(this + 2);
      *(_WORD *)(v25 + 118) |= 4u;
      *(_WORD *)(v25 + 110) = (int)v34;
    }
  }
  v26 = (int)v28;
  v27 = v28[2] == (const struct GASValue *)1;
  v28[2] = (const struct GASValue *)((char *)v28[2] - 1);
  if ( v27 )
    GASStringNode::ReleaseNode(a1: v26);
}

//------------------------------------------------------------------------------
// Address: 0x101797E0
// Name: public: static void GASStyleSheetProto::Load(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStyleSheetProto::Load(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  GASFnCall v3; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v4; // edi
  unsigned __int8 *v5; // eax
  IShaderDevice *v6; // eax
  IShaderDevice *v7; // edi
  struct GFxMovieRoot *MovieRoot; // eax
  GASFnCall v9; // esi
  int v10; // eax
  char *v12; // [esp-Ch] [ebp-1Ch]
  ScaleformRenderer::FillStyle *result; // [esp+4h] [ebp-Ch]
  int v14; // [esp+8h] [ebp-8h] BYREF
  int v15; // [esp+Ch] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x1Fu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
    {
      result = (ScaleformRenderer::FillStyle *)&v2[-1].cxItem;
      if ( v2 != (GASFnCall)16 )
      {
        if ( a2[7] != nullptr )
        {
          v4 = (tagRID_DEVICE_INFO_KEYBOARD *)a2[6];
          v5 = (unsigned __int8 *)GASFnCall::Arg(this: a2, a2: 0);
          GASValue::ToStringImpl(this: v5, a2: &v15, a3: v4, precision: -1, debug: false);
          v14 = 2;
          v6 = (IShaderDevice *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 20, a3: &v14);
          if ( v6 != nullptr )
          {
            v6->__vftable = (IShaderDevice_vtbl *)&GRefCountImplCore::`vftable';
            v6[1].__vftable = (IShaderDevice_vtbl *)1;
            v6->__vftable = (IShaderDevice_vtbl *)&GFxCSSFileLoaderAndParserImpl::`vftable';
            v6[2].__vftable = nullptr;
            v6[3].__vftable = nullptr;
            v6[4].__vftable = nullptr;
            v7 = v6;
          }
          else
          {
            v7 = nullptr;
          }
          v12 = *(char **)v15;
          MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)a2[6]);
          GFxMovieRoot::AddCssLoadQueueEntry(this: (int)MovieRoot, result, a3: v7, a4: v12, a5: nullptr);
          v9 = a2[1];
          GASValue::DropRefs(this: (GASValue *)v9, a2: (int)v7);
          LOBYTE(v9->cbSize) = 2;
          LOBYTE(v9->cItems) = 1;
          if ( v7 != nullptr )
            GRefCountImpl::Release(this: (IShaderAPI *)v7);
          v10 = v15;
          if ( (*(_DWORD *)(v15 + 8))-- == 1 )
            GASStringNode::ReleaseNode(a1: v10);
        }
        else
        {
          v3 = a2[1];
          GASValue::DropRefs(this: (GASValue *)v3, a2: a1);
          LOBYTE(v3->cbSize) = 2;
          LOBYTE(v3->cItems) = 0;
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "StyleSheet", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101799E0
// Name: public: static void GASStyleSheetProto::GetStyle(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStyleSheetProto::GetStyle(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  GASValue *v3; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // eax
  int m_nGrowSize; // edi
  int v8; // eax
  GASValue *v9; // esi
  int v10; // ecx
  int (__thiscall *v11)(int, int, int *); // edx
  GASObject *v12; // eax
  GASFnCall v13; // esi
  char v14; // di
  char v15; // di
  char v16; // di
  struct GASStringNode *StringNode; // edi
  unsigned int cbSize; // eax
  int m_nAllocationCount; // ecx
  int v20; // eax
  int v21; // eax
  bool v22; // zf
  _DWORD *v23; // eax
  struct GASStringNode *v24; // edi
  unsigned int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  unsigned int v29; // edx
  int v30; // edi
  int v31; // eax
  int v32; // eax
  GASStringManager *v33; // ecx
  CImagePacker *v34; // eax
  int v35; // edi
  unsigned int v36; // eax
  int v37; // eax
  int v38; // eax
  CImagePacker *m_pMemory; // ecx
  CImagePacker *v40; // ecx
  unsigned int v41; // edx
  CImagePacker *v42; // eax
  unsigned int v43; // eax
  int v44; // edi
  unsigned int v45; // ecx
  int v46; // eax
  int v47; // eax
  CImagePacker *v48; // ecx
  CImagePacker *v49; // ecx
  unsigned int v50; // eax
  CImagePacker *v51; // eax
  unsigned int v52; // ecx
  int v53; // edi
  unsigned int v54; // edx
  int v55; // eax
  int v56; // eax
  CImagePacker *v57; // ecx
  CImagePacker *v58; // ecx
  int v59; // eax
  unsigned int v60; // eax
  int v61; // edi
  int v62; // eax
  int v63; // eax
  int v64; // edi
  char v65; // al
  int v66; // ecx
  unsigned int v67; // edx
  int v68; // edi
  int v69; // eax
  int v70; // eax
  unsigned int v71; // eax
  int v72; // edi
  int v73; // eax
  int v74; // eax
  GASStringManager *v75; // ecx
  int v76; // eax
  int *v77; // eax
  GASStringManager *v78; // ecx
  int v79; // eax
  int *v80; // eax
  unsigned int v81; // edx
  int v82; // eax
  unsigned int v83; // eax
  int v84; // eax
  int v85; // eax
  int v86; // edi
  unsigned int v87; // ecx
  int v88; // eax
  int v89; // eax
  int v90; // ecx
  int v91; // ecx
  int v92; // ecx
  int v93; // ecx
  int v94; // ecx
  int v95; // ecx
  unsigned int v96; // edx
  int v97; // eax
  unsigned int v98; // eax
  unsigned int v99; // ecx
  int v100; // eax
  int v101; // eax
  int v102; // ecx
  int v103; // ecx
  unsigned int v104; // eax
  int v105; // eax
  int v106; // eax
  int v107; // esi
  int v108; // eax
  GASValue v109; // [esp+4h] [ebp-38h] BYREF
  double v110; // [esp+8h] [ebp-34h]
  int v111; // [esp+14h] [ebp-28h] BYREF
  int v112; // [esp+18h] [ebp-24h] BYREF
  int v113; // [esp+1Ch] [ebp-20h] BYREF
  int v114; // [esp+20h] [ebp-1Ch] BYREF
  int *v115; // [esp+24h] [ebp-18h] BYREF
  CUtlMemory<CImagePacker,int> v116; // [esp+28h] [ebp-14h] BYREF
  int v117; // [esp+34h] [ebp-8h]
  char v118; // [esp+3Bh] [ebp-1h] BYREF

  v117 = 0;
  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x1Fu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
    {
      v116.m_pMemory = (CImagePacker *)&v2[-1].cxItem;
      if ( v2 != (GASFnCall)16 )
      {
        if ( (int)a2[7] >= 1 )
        {
          v4 = (tagRID_DEVICE_INFO_KEYBOARD *)a2[6];
          v5 = (unsigned __int8 *)GASFnCall::Arg(this: a2, a2: 0);
          GASValue::ToStringImpl(this: v5, a2: (int *)&v115, a3: v4, precision: -1, debug: false);
          if ( v115[4] != 0 && *(_BYTE *)*v115 == 46 )
          {
            GFxTextStyleManager::GetStyle(
              this: (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)&v116.m_pMemory->m_pLightmapWavefront[11],
              type: (ColorCorrectionLookup_t *const *)1,
              name: *v115 + 1);
            m_nGrowSize = v6;
            v116.m_nGrowSize = v6;
          }
          else
          {
            GFxTextStyleManager::GetStyle(
              this: (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)&v116.m_pMemory->m_pLightmapWavefront[11],
              type: nullptr,
              name: *v115);
            v116.m_nGrowSize = v8;
            m_nGrowSize = v8;
          }
          if ( m_nGrowSize != 0 )
          {
            v10 = *(_DWORD *)(a2[6][3].cbSize + 656);
            v11 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v10 + 40);
            v111 = 323;
            v12 = (GASObject *)v11(a1: v10, a2: 52, a3: &v111);
            if ( v12 != nullptr )
              v116.m_nAllocationCount = (int)GASObject::GASObject(this: v12, a2: (struct GASEnvironment *)a2[6]);
            else
              v116.m_nAllocationCount = 0;
            v13 = a2[6];
            if ( (*(_BYTE *)(m_nGrowSize + 42) & 1) != 0 )
            {
              GString::GString(this: &v116);
              GString::AppendChar(this: (unsigned int *)&v116, result: (CImagePacker *)0x23);
              v114 = *(_DWORD *)(v116.m_nGrowSize + 32);
              v14 = BYTE2(v114);
              GString::AppendChar(
                this: (unsigned int *)&v116,
                result: (CImagePacker *)a0123456789abcd[BYTE2(v114) >> 4]);
              GString::AppendChar(this: (unsigned int *)&v116, result: (CImagePacker *)a0123456789abcd[v14 & 0xF]);
              v15 = BYTE1(v114);
              GString::AppendChar(
                this: (unsigned int *)&v116,
                result: (CImagePacker *)a0123456789abcd[BYTE1(v114) >> 4]);
              GString::AppendChar(this: (unsigned int *)&v116, result: (CImagePacker *)a0123456789abcd[v15 & 0xF]);
              v16 = v114;
              GString::AppendChar(
                this: (unsigned int *)&v116,
                result: (CImagePacker *)a0123456789abcd[(unsigned __int8)v114 >> 4]);
              GString::AppendChar(this: (unsigned int *)&v116, result: (CImagePacker *)a0123456789abcd[v16 & 0xF]);
              StringNode = GASStringManager::CreateStringNode(
                             this: *(GASStringManager **)(v13[3].cbSize + 636),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)v116.m_pMemory & 0xFFFFFFFC) + 8),
                             length: *(_DWORD *)((int)v116.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF);
              ++*((_DWORD *)StringNode + 2);
              LOBYTE(v109) = 5;
              LODWORD(v110) = StringNode;
              ++*((_DWORD *)StringNode + 2);
              cbSize = v13[3].cbSize;
              v118 = 0;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(cbSize + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"color");
              m_nAllocationCount = v116.m_nAllocationCount;
              v114 = v20;
              ++*(_DWORD *)(v20 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(m_nAllocationCount + 16)
                                                                                + 12))(
                a1: m_nAllocationCount + 16,
                a2: a2[6],
                a3: &v114,
                a4: &v109,
                a5: &v118);
              v21 = v114;
              v22 = (*(_DWORD *)(v114 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v21);
              GASValue::~GASValue(this: &v109, a2: (int)StringNode);
              v22 = (*((_DWORD *)StringNode + 2))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: (int)StringNode);
              GString::~GString(this: (GString *)&v116);
              m_nGrowSize = v116.m_nGrowSize;
            }
            if ( (*(_BYTE *)(m_nGrowSize + 42) & 4) != 0 )
            {
              LOBYTE(v23) = GFxTextFormat::GetFontList();
              v24 = GASStringManager::CreateStringNode(
                      this: *(GASStringManager **)(v13[3].cbSize + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*v23 & 0xFFFFFFFC) + 8),
                      length: *(_DWORD *)(*v23 & 0xFFFFFFFC) & 0x7FFFFFFF);
              ++*((_DWORD *)v24 + 2);
              LOBYTE(v109) = 5;
              LODWORD(v110) = v24;
              ++*((_DWORD *)v24 + 2);
              v25 = v13[3].cbSize;
              v118 = 0;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v25 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"fontFamily");
              v26 = v116.m_nAllocationCount;
              v114 = v27;
              ++*(_DWORD *)(v27 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v26 + 16) + 12))(
                a1: v26 + 16,
                a2: a2[6],
                a3: &v114,
                a4: &v109,
                a5: &v118);
              v28 = v114;
              v22 = (*(_DWORD *)(v114 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v28);
              GASValue::~GASValue(this: &v109, a2: (int)v24);
              v22 = (*((_DWORD *)v24 + 2))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: (int)v24);
              m_nGrowSize = v116.m_nGrowSize;
            }
            if ( (*(_BYTE *)(m_nGrowSize + 42) & 8) != 0 )
            {
              v111 = *(unsigned __int16 *)(m_nGrowSize + 38);
              v29 = v13[3].cbSize;
              v30 = v116.m_nAllocationCount;
              LOBYTE(v109) = 3;
              v118 = 0;
              *(float *)&v111 = (double)v111 / 20.0;
              v110 = *(float *)&v111;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v29 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F074);
              v114 = v31;
              ++*(_DWORD *)(v31 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v30 + 16) + 12))(
                a1: v30 + 16,
                a2: a2[6],
                a3: &v114,
                a4: &v109,
                a5: &v118);
              v32 = v114;
              v22 = (*(_DWORD *)(v114 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v32);
              GASValue::~GASValue(this: &v109, a2: v30);
              m_nGrowSize = v116.m_nGrowSize;
            }
            if ( (*(_BYTE *)(m_nGrowSize + 42) & 0x20) != 0 )
            {
              v33 = *(GASStringManager **)(v13[3].cbSize + 636);
              if ( (*(_BYTE *)(m_nGrowSize + 40) & 2) != 0 )
              {
                v117 = 1;
                GASStringManager::CreateStringNode(
                  this: v33,
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102904EC);
              }
              else
              {
                v117 = 2;
                GASStringManager::CreateStringNode(
                  this: v33,
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029DFB4);
              }
              ++v34->m_pLightmapWavefront[0];
              v35 = v116.m_nAllocationCount;
              v116.m_pMemory = v34;
              LODWORD(v110) = v34;
              LOBYTE(v109) = 5;
              ++v34->m_pLightmapWavefront[0];
              v36 = v13[3].cbSize;
              v118 = 0;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v36 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"fontStyle");
              v114 = v37;
              ++*(_DWORD *)(v37 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v35 + 16) + 12))(
                a1: v35 + 16,
                a2: a2[6],
                a3: &v114,
                a4: &v109,
                a5: &v118);
              v38 = v114;
              v22 = (*(_DWORD *)(v114 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v38);
              GASValue::~GASValue(this: &v109, a2: v35);
              if ( (v117 & 2) != 0 )
              {
                m_pMemory = v116.m_pMemory;
                v117 &= ~2u;
                v22 = v116.m_pMemory->m_pLightmapWavefront[0]-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: (int)m_pMemory);
              }
              if ( (v117 & 1) != 0 )
              {
                v40 = v116.m_pMemory;
                v117 &= ~1u;
                v22 = v116.m_pMemory->m_pLightmapWavefront[0]-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: (int)v40);
              }
              m_nGrowSize = v116.m_nGrowSize;
            }
            if ( (*(_BYTE *)(m_nGrowSize + 42) & 0x10) != 0 )
            {
              if ( (*(_BYTE *)(v116.m_nGrowSize + 40) & 1) != 0 )
              {
                v41 = v13[3].cbSize;
                v117 |= 4u;
                GASStringManager::CreateStringNode(
                  this: *(GASStringManager **)(v41 + 636),
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102904EC.m_Memory.m_nGrowSize);
              }
              else
              {
                v43 = v13[3].cbSize;
                v117 |= 8u;
                GASStringManager::CreateStringNode(
                  this: *(GASStringManager **)(v43 + 636),
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029DFB4);
              }
              ++v42->m_pLightmapWavefront[0];
              v44 = v116.m_nAllocationCount;
              v116.m_pMemory = v42;
              LOBYTE(v109) = 5;
              LODWORD(v110) = v42;
              ++v42->m_pLightmapWavefront[0];
              v45 = v13[3].cbSize;
              v118 = 0;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v45 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"fontWeight");
              v114 = v46;
              ++*(_DWORD *)(v46 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v44 + 16) + 12))(
                a1: v44 + 16,
                a2: a2[6],
                a3: &v114,
                a4: &v109,
                a5: &v118);
              v47 = v114;
              v22 = (*(_DWORD *)(v114 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v47);
              GASValue::~GASValue(this: &v109, a2: v44);
              if ( (v117 & 8) != 0 )
              {
                v48 = v116.m_pMemory;
                v117 &= ~8u;
                v22 = v116.m_pMemory->m_pLightmapWavefront[0]-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: (int)v48);
              }
              if ( (v117 & 4) != 0 )
              {
                v49 = v116.m_pMemory;
                v117 &= ~4u;
                v22 = v116.m_pMemory->m_pLightmapWavefront[0]-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: (int)v49);
              }
            }
            if ( *(char *)(v116.m_nGrowSize + 42) < 0 )
            {
              if ( (*(_BYTE *)(v116.m_nGrowSize + 40) & 8) != 0 )
              {
                v50 = v13[3].cbSize;
                v117 |= 0x10u;
                GASStringManager::CreateStringNode(
                  this: *(GASStringManager **)(v50 + 636),
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"true");
              }
              else
              {
                v52 = v13[3].cbSize;
                v117 |= 0x20u;
                GASStringManager::CreateStringNode(
                  this: *(GASStringManager **)(v52 + 636),
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"false");
              }
              ++v51->m_pLightmapWavefront[0];
              v53 = v116.m_nAllocationCount;
              v116.m_pMemory = v51;
              LOBYTE(v109) = 5;
              LODWORD(v110) = v51;
              ++v51->m_pLightmapWavefront[0];
              v54 = v13[3].cbSize;
              v118 = 0;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v54 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CC8);
              v114 = v55;
              ++*(_DWORD *)(v55 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v53 + 16) + 12))(
                a1: v53 + 16,
                a2: a2[6],
                a3: &v114,
                a4: &v109,
                a5: &v118);
              v56 = v114;
              v22 = (*(_DWORD *)(v114 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v56);
              GASValue::~GASValue(this: &v109, a2: v53);
              if ( (v117 & 0x20) != 0 )
              {
                v57 = v116.m_pMemory;
                v117 &= ~0x20u;
                v22 = v116.m_pMemory->m_pLightmapWavefront[0]-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: (int)v57);
              }
              if ( (v117 & 0x10) != 0 )
              {
                v58 = v116.m_pMemory;
                v117 &= ~0x10u;
                v22 = v116.m_pMemory->m_pLightmapWavefront[0]-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: (int)v58);
              }
            }
            v59 = v116.m_nGrowSize;
            if ( (*(_BYTE *)(v116.m_nGrowSize + 42) & 2) != 0 )
            {
              v111 = *(__int16 *)(v116.m_nGrowSize + 36);
              v60 = v13[3].cbSize;
              v61 = v116.m_nAllocationCount;
              LOBYTE(v109) = 3;
              v118 = 0;
              *(float *)&v111 = (double)v111 / 20.0;
              v110 = *(float *)&v111;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v60 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CC8.m_Memory.m_nGrowSize);
              v114 = v62;
              ++*(_DWORD *)(v62 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v61 + 16) + 12))(
                a1: v61 + 16,
                a2: a2[6],
                a3: &v114,
                a4: &v109,
                a5: &v118);
              v63 = v114;
              v22 = (*(_DWORD *)(v114 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v63);
              GASValue::~GASValue(this: &v109, a2: v61);
              v59 = v116.m_nGrowSize;
            }
            v64 = v59 + 44;
            v65 = *(_BYTE *)(v59 + 66) >> 4;
            v116.m_pMemory = (CImagePacker *)v64;
            if ( (v65 & 1) != 0 )
            {
              v66 = *(unsigned __int16 *)(v64 + 18);
              v67 = v13[3].cbSize;
              v68 = v116.m_nAllocationCount;
              v111 = v66;
              LOBYTE(v109) = 3;
              v118 = 0;
              v110 = (double)v66;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v67 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"marginLeft");
              v114 = v69;
              ++*(_DWORD *)(v69 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v68 + 16) + 12))(
                a1: v68 + 16,
                a2: a2[6],
                a3: &v114,
                a4: &v109,
                a5: &v118);
              v70 = v114;
              v22 = (*(_DWORD *)(v114 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v70);
              GASValue::~GASValue(this: &v109, a2: v68);
              v64 = (int)v116.m_pMemory;
            }
            if ( (*(_BYTE *)(v64 + 22) & 0x20) != 0 )
            {
              v71 = v13[3].cbSize;
              v72 = v116.m_nAllocationCount;
              v111 = LOWORD(v116.m_pMemory->m_pLightmapWavefront[3]);
              LOBYTE(v109) = 3;
              v118 = 0;
              v110 = (double)v111;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v71 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"marginRight");
              v114 = v73;
              ++*(_DWORD *)(v73 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v72 + 16) + 12))(
                a1: v72 + 16,
                a2: a2[6],
                a3: &v114,
                a4: &v109,
                a5: &v118);
              v74 = v114;
              v22 = (*(_DWORD *)(v114 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v74);
              GASValue::~GASValue(this: &v109, a2: v72);
              v64 = (int)v116.m_pMemory;
            }
            if ( (*(_BYTE *)(v64 + 22) & 1) != 0 )
            {
              if ( (unsigned __int8)GFxTextParagraphFormat::IsLeftAlignment(this: (GFxTextParagraphFormat *)v64) != 0 )
              {
                v75 = *(GASStringManager **)(v13[3].cbSize + 636);
                v117 |= 0x40u;
                GASStringManager::CreateStringNode(
                  this: v75,
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"left");
                ++*(_DWORD *)(v76 + 8);
                v111 = v76;
                v77 = &v111;
              }
              else
              {
                if ( GFxTextParagraphFormat::IsCenterAlignment(this: (GFxTextParagraphFormat *)v64) )
                {
                  v78 = *(GASStringManager **)(v13[3].cbSize + 636);
                  v117 |= 0x80u;
                  GASStringManager::CreateStringNode(
                    this: v78,
                    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"center");
                  ++*(_DWORD *)(v79 + 8);
                  v111 = v79;
                  v80 = &v111;
                }
                else
                {
                  if ( GFxTextParagraphFormat::IsRightAlignment(this: (GFxTextParagraphFormat *)v64) )
                  {
                    v81 = v13[3].cbSize;
                    v117 |= 0x100u;
                    GASStringManager::CreateStringNode(
                      this: *(GASStringManager **)(v81 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"right");
                  }
                  else
                  {
                    v83 = v13[3].cbSize;
                    v117 |= 0x200u;
                    GASStringManager::CreateStringNode(
                      this: *(GASStringManager **)(v83 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"justify");
                  }
                  ++*(_DWORD *)(v82 + 8);
                  v117 |= 0x400u;
                  v111 = v82;
                  ++*(_DWORD *)(v82 + 8);
                  v112 = v82;
                  v80 = &v112;
                }
                v84 = *v80;
                v117 |= 0x800u;
                ++*(_DWORD *)(v84 + 8);
                v113 = v84;
                v77 = &v113;
              }
              v85 = *v77;
              v86 = v116.m_nAllocationCount;
              LOBYTE(v109) = 5;
              LODWORD(v110) = v85;
              ++*(_DWORD *)(v85 + 8);
              v87 = v13[3].cbSize;
              v118 = 0;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v87 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"textAlign");
              v114 = v88;
              ++*(_DWORD *)(v88 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v86 + 16) + 12))(
                a1: v86 + 16,
                a2: a2[6],
                a3: &v114,
                a4: &v109,
                a5: &v118);
              v89 = v114;
              v22 = (*(_DWORD *)(v114 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v89);
              GASValue::~GASValue(this: &v109, a2: v86);
              v64 = -1;
              if ( (v117 & 0x800) != 0 )
              {
                v90 = v113;
                v117 &= ~0x800u;
                v22 = (*(_DWORD *)(v113 + 8))-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: v90);
              }
              if ( (v117 & 0x400) != 0 )
              {
                v91 = v112;
                v117 &= ~0x400u;
                v22 = (*(_DWORD *)(v112 + 8))-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: v91);
              }
              if ( (v117 & 0x200) != 0 )
              {
                v92 = v111;
                v117 &= ~0x200u;
                v22 = (*(_DWORD *)(v111 + 8))-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: v92);
              }
              if ( (v117 & 0x100) != 0 )
              {
                v93 = v111;
                v117 &= ~0x100u;
                v22 = (*(_DWORD *)(v111 + 8))-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: v93);
              }
              if ( (v117 & 0x80u) != 0 )
              {
                v94 = v111;
                v117 &= ~0x80u;
                v22 = (*(_DWORD *)(v111 + 8))-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: v94);
              }
              if ( (v117 & 0x40) != 0 )
              {
                v95 = v111;
                v117 &= ~0x40u;
                v22 = (*(_DWORD *)(v111 + 8))-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: v95);
              }
            }
            if ( (*(_BYTE *)(v116.m_nGrowSize + 42) & 0x40) != 0 )
            {
              if ( (*(_BYTE *)(v116.m_nGrowSize + 40) & 4) != 0 )
              {
                v96 = v13[3].cbSize;
                v117 |= 0x1000u;
                GASStringManager::CreateStringNode(
                  this: *(GASStringManager **)(v96 + 636),
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CE0.m_Memory.m_nAllocationCount);
              }
              else
              {
                v98 = v13[3].cbSize;
                v117 |= 0x2000u;
                GASStringManager::CreateStringNode(
                  this: *(GASStringManager **)(v98 + 636),
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A09D0);
              }
              ++*(_DWORD *)(v97 + 8);
              v64 = v116.m_nAllocationCount;
              v112 = v97;
              LOBYTE(v109) = 5;
              LODWORD(v110) = v97;
              ++*(_DWORD *)(v97 + 8);
              v99 = v13[3].cbSize;
              v118 = 0;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v99 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"textDecoration");
              v111 = v100;
              ++*(_DWORD *)(v100 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v64 + 16) + 12))(
                a1: v64 + 16,
                a2: a2[6],
                a3: &v111,
                a4: &v109,
                a5: &v118);
              v101 = v111;
              v22 = (*(_DWORD *)(v111 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v101);
              GASValue::~GASValue(this: &v109, a2: v64);
              if ( (v117 & 0x2000) != 0 )
              {
                v102 = v112;
                v117 &= ~0x2000u;
                v22 = (*(_DWORD *)(v112 + 8))-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: v102);
              }
              if ( (v117 & 0x1000) != 0 )
              {
                v103 = v112;
                v22 = (*(_DWORD *)(v112 + 8))-- == 1;
                if ( v22 )
                  GASStringNode::ReleaseNode(a1: v103);
              }
            }
            if ( (v116.m_pMemory->m_pLightmapWavefront[3] & 0x40000) != 0 )
            {
              v104 = v13[3].cbSize;
              v64 = v116.m_nAllocationCount;
              v111 = SHIWORD(v116.m_pMemory->m_pLightmapWavefront[1]);
              LOBYTE(v109) = 3;
              v118 = 0;
              v110 = (double)v111;
              GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(v104 + 636),
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"textIndent");
              v111 = v105;
              ++*(_DWORD *)(v105 + 8);
              (*(void (__thiscall **)(int, GASFnCall, int *, GASValue *, char *))(*(_DWORD *)(v64 + 16) + 12))(
                a1: v64 + 16,
                a2: a2[6],
                a3: &v111,
                a4: &v109,
                a5: &v118);
              v106 = v111;
              v22 = (*(_DWORD *)(v111 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v106);
              GASValue::~GASValue(this: &v109, a2: v64);
            }
            v107 = v116.m_nAllocationCount;
            GASValue::SetAsObject(this: (GASValue *)a2[1], a2: (struct GASObject *)v116.m_nAllocationCount);
            if ( v107 != 0 )
              GRefCountBaseGC<323>::Release(a1: v107, a2: v64);
          }
          else
          {
            v9 = (GASValue *)a2[1];
            GASValue::DropRefs(this: v9, a2: 0);
            *(_BYTE *)v9 = 1;
          }
          v108 = (int)v115;
          v22 = v115[2]-- == 1;
          if ( v22 )
            GASStringNode::ReleaseNode(a1: v108);
        }
        else
        {
          v3 = (GASValue *)a2[1];
          GASValue::DropRefs(this: v3, a2: a1);
          *(_BYTE *)v3 = 1;
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "StyleSheet", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A4D0
// Name: public: static void GASStyleSheetProto::GetStyleNames(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStyleSheetProto::GetStyleNames(unsigned int a1@<ebx>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  GASFnCall v3; // eax
  int p_cxItem; // edi
  CMaterial *RealTimeVersion; // eax
  GArrayDataBase<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > *v6; // ebx
  int v7; // edi
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *StringNode; // eax
  struct GASObject *v9; // ecx
  int v10; // esi
  unsigned int v12; // eax
  GRenderer::BlendType *v13; // ecx
  void *v14; // esi
  int v15; // [esp-8h] [ebp-2Ch]
  GASValue v16[2]; // [esp+4h] [ebp-20h] BYREF
  GArrayDataBase<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > *v17[2]; // [esp+Ch] [ebp-18h] BYREF
  int v18; // [esp+14h] [ebp-10h]
  CMaterial *v19; // [esp+18h] [ebp-Ch]
  struct GASObject *v20; // [esp+1Ch] [ebp-8h]
  GString v21; // [esp+20h] [ebp-4h] BYREF

  v2 = a2;
  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x1Fu) )
  {
    v3 = a2[2];
    if ( v3 != nullptr )
    {
      p_cxItem = (int)&v3[-1].cxItem;
      if ( v3 != (GASFnCall)16 )
      {
        v20 = GASEnvironment::OperatorNew(
                this: (__vc_attributes::idl_quoteAttribute *)a2[6],
                a2: p_cxItem,
                a3: *(struct GASObject **)(a2[6][3].cbSize + 680),
                a4: (const struct GASString *)(a2[6][3].cbSize + 16),
                nargs: 0,
                argsTopOff: -1);
        v18 = (int)&a2[6][3];
        GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v21);
        v19 = (CMaterial *)(p_cxItem + 52);
        RealTimeVersion = CMaterial::GetRealTimeVersion(this: (CMaterial *)(p_cxItem + 52));
        GHash<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>,GAllocatorLH<GFxTextStyleKey,324>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashsetNodeEntry<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF>,GHashSet<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeAltHashF,GAllocatorLH<GFxTextStyleKey,324>,GHashsetNodeEntry<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF>>>::Begin(
          this: (GArrayDataBase<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > *)RealTimeVersion,
          a2: v17,
          a3: a1);
        v6 = v17[0];
        v7 = (int)v17[1];
        while ( 1 )
        {
          CMaterial::GetRealTimeVersion(this: v19);
          if ( v6 == nullptr || v6->Data == nullptr || v7 > *((_DWORD *)v6->Data + 1) )
            break;
          GString::Clear(this: &v21);
          if ( v6->Data[5 * v7 + 3] == Blend_Normal )
            GString::AppendChar(this: (unsigned int *)&v21, result: (CImagePacker *)0x2E);
          GString::operator+=(
            this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v21,
            src: (int *)&v6->Data[5 * v7 + 4],
            srcSize: v15);
          StringNode = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)GASStringManager::CreateStringNode(
                                                                                                    this: *(GASStringManager **)(*(_DWORD *)v18 + 636),
                                                                                                    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v21.HeapTypeBits & 0xFFFFFFFC) + 8),
                                                                                                    length: *(_DWORD *)(v21.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
          v9 = v20;
          v10 = (int)StringNode;
          ++StringNode->m_nGrowSize;
          LOBYTE(v16[0]) = 5;
          v16[1] = StringNode;
          ++StringNode->m_nGrowSize;
          GASArrayObject::PushBack(this: (GASArrayObject *)v9, val: (tagWNDCLASSW *)v16);
          GASValue::~GASValue(this: v16, a2: v7);
          if ( (*(_DWORD *)(v10 + 8))-- == 1 )
            GASStringNode::ReleaseNode(a1: v10);
          v12 = *((_DWORD *)v6->Data + 1);
          if ( v7 <= (int)v12 && ++v7 <= v12 )
          {
            v13 = &v6->Data[5 * v7 + 2];
            do
            {
              if ( *v13 != -2 )
                break;
              ++v7;
              v13 += 5;
            }
            while ( v7 <= v12 );
          }
          v2 = a2;
        }
        GASValue::SetAsObject(this: (GASValue *)v2[1], a2: v20);
        v14 = (void *)(v21.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v21.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
        if ( v20 != nullptr )
          GRefCountBaseGC<323>::Release(a1: (int)v20, a2: v7);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "StyleSheet", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A690
// Name: public: static void GASStyleSheetProto::Transform(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStyleSheetProto::Transform(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  GASValue *v3; // eax
  struct GASObject *v4; // ebx
  struct GASObject *v5; // edi
  const struct GASEnvironment *v6; // [esp-8h] [ebp-18h]
  void **v7; // [esp+4h] [ebp-Ch] BYREF
  GASFnCall v8; // [esp+8h] [ebp-8h]
  struct GASObject *v9; // [esp+Ch] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x1Fu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr && v2 != (GASFnCall)16 && (int)a2[7] >= 1 )
    {
      v6 = (const struct GASEnvironment *)a2[6];
      v3 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v4 = GASValue::ToObject(this: v3, a2: a1, a3: v6);
      if ( v4 != nullptr )
      {
        v5 = GASEnvironment::OperatorNew(
               this: (__vc_attributes::idl_quoteAttribute *)a2[6],
               a2: a1,
               a3: *(struct GASObject **)(a2[6][3].cbSize + 680),
               a4: (const struct GASString *)(a2[6][3].cbSize + 136),
               nargs: 0,
               argsTopOff: -1);
        v8 = a2[6];
        v7 = &CSSTextFormatLoader::`vftable';
        v9 = v5;
        ((void (__thiscall *)(struct GASObject *, tagALTTABINFO *, void ***, _DWORD, _DWORD))v4[2].pNode[4].pNext)(
          a1: &v4[2],
          a2: &v8[3],
          a3: &v7,
          a4: 0,
          a5: 0);
        GASValue::SetAsObject(this: (GASValue *)a2[1], a2: v5);
        v7 = &GString::InitStruct::`vftable';
        if ( v5 != nullptr )
          GRefCountBaseGC<323>::Release(a1: (int)v5, a2: (int)v5);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "StyleSheet", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A7C0
// Name: public: virtual void GFxCSSFileLoaderAndParserImpl::Init(class GASEnvironment __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCSSFileLoaderAndParserImpl::Init(
        GFxCSSFileLoaderAndParserImpl *this,
        struct GASEnvironment *a2,
        _IMAGE_SYMBOL_EX *a3)
{
  const wchar_t *v4; // ecx
  signed int v5; // eax
  const wchar_t *v6; // edi
  signed int v7; // ecx
  signed int v8; // edx
  GArrayBase<GArrayData<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > > *v9; // edi
  GFxTextStyleManager *p_SectionNumber; // ecx
  char v11; // al
  const wchar_t *v12; // [esp-Ch] [ebp-14h]

  v4 = *((const wchar_t **)this + 3);
  if ( v4 != nullptr )
  {
    v5 = *((_DWORD *)this + 4);
    if ( *v4 == 0xFEFF )
    {
      v6 = v4 + 1;
      v5 = v5 / 2 - 1;
      v7 = 0;
      for ( *((_DWORD *)this + 2) = 1; v7 < v5; ++v7 )
        ;
    }
    else if ( *v4 == 0xFFFE )
    {
      v5 = v5 / 2 - 1;
      v8 = 0;
      v6 = v4 + 1;
      for ( *((_DWORD *)this + 2) = 1; v8 < v5; ++v8 )
        v4[v8 + 1] = __ROL2__(v4[v8 + 1], 8);
    }
    else if ( v5 > 2 && *(_BYTE *)v4 == 0xEF && *((_BYTE *)v4 + 1) == 0xBB && *((_BYTE *)v4 + 2) == 0xBF )
    {
      v6 = (const wchar_t *)((char *)v4 + 3);
      v5 -= 3;
    }
    else
    {
      v6 = v4;
    }
    v12 = v6;
    v9 = (GArrayBase<GArrayData<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > > *)a3;
    p_SectionNumber = (GFxTextStyleManager *)&a3[2].SectionNumber;
    if ( *((_DWORD *)this + 2) == 1 )
      v11 = GFxTextStyleManager::ParseCSS(this: p_SectionNumber, a2: v12, a3: v5);
    else
      v11 = GFxTextStyleManager::ParseCSS(
              this: (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)p_SectionNumber,
              buffer: (int)v12,
              len: (ColorCorrectionLookup_t *const *)v5);
    LOBYTE(a3) = v11;
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 3));
    *((_DWORD *)this + 3) = 0;
    GASStyleSheetObject::NotifyOnLoad(this: v9, penv: (const IClientRenderable *)a2, success: a3);
  }
  else
  {
    GASStyleSheetObject::NotifyOnLoad(
      this: (GArrayBase<GArrayData<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > > *)a3,
      penv: (const IClientRenderable *)a2,
      success: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A910
// Name: public: GASStyleSheetObject::GASStyleSheetObject(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1017A980
// Name: public: static void GASStyleSheetCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASStyleSheetCtorFunction::GlobalCtor(int a1)
{
  int v1; // esi
  int v2; // eax
  struct GASObject *v3; // edi
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // eax
  GRenderer::BlendType v6; // eax

  v1 = a1;
  if ( *(_DWORD *)(a1 + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 8) + 8))(a1: *(_DWORD *)(a1 + 8)) == 31
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(v1 + 8) + 64))(a1: *(_DWORD *)(v1 + 8)) == 0 )
  {
    v2 = *(_DWORD *)(v1 + 8);
    if ( v2 != 0 )
    {
      v3 = (struct GASObject *)(v2 - 16);
      if ( v2 != 16 )
        v3[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v3[1].pNode->pNext + 1) & 0x8FFFFFFF);
    }
    else
    {
      v3 = nullptr;
    }
  }
  else
  {
    v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 24) + 120) + 656);
    v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
    a1 = 323;
    if ( v5(a1: v4, a2: 68, a3: &a1) != 0 )
      v6 = GASStyleSheetObject::GASStyleSheetObject();
    else
      v6 = Blend_None;
    v3 = (struct GASObject *)v6;
  }
  GASValue::SetAsObject(this: *(GASValue **)(v1 + 4), a2: v3);
  if ( v3 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v3, a2: (int)v3);
}

//------------------------------------------------------------------------------
// Address: 0x1017AA20
// Name: public: virtual class GASObject __near * GASStyleSheetCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__thiscall GASStyleSheetCtorFunction::CreateNewObject(GASStyleSheetCtorFunction *this, int a2)
{
  int v2; // ecx
  int (__thiscall *v3)(int, int, int *); // edx

  v2 = *(_DWORD *)(*(_DWORD *)(a2 + 120) + 656);
  v3 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v2 + 40);
  a2 = 323;
  if ( v3(a1: v2, a2: 68, a3: &a2) != 0 )
    return (struct GASObject *)GASStyleSheetObject::GASStyleSheetObject();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1017AB50
// Name: public: static class GASFunctionRef GASStyleSheetCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASStyleSheetCtorFunction::Register(struct GASFunctionRef *a1, int a2)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *v3; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // ebx
  GASCFunctionObject *v7; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v10)(const char *, int, int *); // edx
  int v11; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  vc_attributes::InvalidCheckAttribute *v13; // eax
  int Value; // ecx
  tagIMECHARPOSITION *v15; // edx
  int v16; // esi
  GASValue *v17; // eax
  int p_MaxVal; // edi
  GASValue v20[4]; // [esp+Ch] [ebp-2Ch] BYREF
  int v21; // [esp+1Ch] [ebp-1Ch] BYREF
  int v22; // [esp+20h] [ebp-18h]
  char v23; // [esp+24h] [ebp-14h]
  CTSQueue<CFunctor *,0,1>::Node_t psc; // [esp+28h] [ebp-10h] BYREF
  int v25; // [esp+30h] [ebp-8h]
  int v26; // [esp+34h] [ebp-4h] BYREF
  struct GASFunctionRef *v27; // [esp+40h] [ebp+8h]

  v2 = (vc_attributes::PreRangeAttribute *)a2;
  v3 = *(CTSQueue<CFunctor *,0,1>::Node_t **)(a2 + 656);
  psc.pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)a2;
  LOBYTE(psc.elem) = 8;
  pNext = v3->pNext[5].pNext;
  a2 = 323;
  v5 = (GASCFunctionObject *)((int (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, int, int *))pNext)(
                               a1: v3,
                               a2: 56,
                               a3: &a2);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&psc,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASStyleSheetCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASStyleSheetCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  *(_DWORD *)a1 = v7;
  *((_BYTE *)a1 + 8) = 0;
  *((_DWORD *)a1 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v10 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)MaxVal + 40);
  v26 = 323;
  v11 = v10(a1: MaxVal, a2: 100, a3: &v26);
  if ( v11 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASStyleSheetObject,GASEnvironment>::GASPrototype<GASStyleSheetObject,GASEnvironment>(
      pthis: (CMaterialVar *)v11,
      &psc,
      a3: Prototype,
      a4: (unsigned int)a1);
    *(_DWORD *)v11 = &GASPrototype<GASStyleSheetObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v11 + 16) = &GASStyleSheetProto::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v11 + 68) = &GASStyleSheetProto::`vftable';
    HIBYTE(a2) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v11 + 68),
      a2: v11,
      flags: (vc_attributes::PreRangeAttribute **)&psc,
      flags_4: (const struct GASNameFunction *)&GAS_StyleSheetFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&a2 + 3));
    v27 = (struct GASFunctionRef *)v11;
  }
  else
  {
    v27 = nullptr;
    v11 = 0;
  }
  if ( v11 != 0 )
    *(_DWORD *)(v11 + 8) = (*(_DWORD *)(v11 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 33, a4: v11);
  v13 = GASGlobalContext::GetPrototype(this: v2, result: (vc_attributes::InvalidCheckAttribute *)0xA);
  v23 = 0;
  Value = v13[16].Value;
  v21 = Value;
  if ( Value != 0 )
  {
    ++*(_DWORD *)(Value + 8);
    *(_DWORD *)(Value + 8) &= 0x8FFFFFFF;
    Value = v21;
  }
  v22 = 0;
  v15 = (tagIMECHARPOSITION *)v13[17].Value;
  if ( v15 != nullptr )
  {
    GASFunctionRefBase::SetLocalFrame(a1: (int)&v21, a2: (int)v2, result: v15, internal: v13[18].Value & 1);
    Value = v21;
  }
  HIBYTE(a2) = 0;
  v16 = *(_DWORD *)(Value + 16);
  v25 = Value + 16;
  v17 = GASValue::GASValue(this: v20, a2: (int)v2, a3: a1);
  p_MaxVal = (int)&v2[11].MaxVal;
  (*(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, int, GASValue *, char *))(v16 + 40))(
    a1: v25,
    a2: &psc,
    a3: p_MaxVal,
    a4: v17,
    a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: v20, a2: p_MaxVal);
  if ( (v23 & 2) == 0 && v21 != 0 )
    GRefCountBaseGC<323>::Release(a1: v21, a2: p_MaxVal);
  v21 = 0;
  if ( (v23 & 1) == 0 && v22 != 0 )
    GRefCountBaseGC<323>::Release(a1: v22, a2: p_MaxVal);
  v22 = 0;
  if ( v27 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v27, a2: p_MaxVal);
  return a1;
}
