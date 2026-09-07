// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/text/gfxtextdocview.cpp
// Functions: 93
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\text\gfxtextdocview.h"

//------------------------------------------------------------------------------
// Address: 0x10167930
// Name: public: int GFxTextLineBuffer::Line::GetNonNegLeading(void)const
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall GFxTextLineBuffer::Line::GetNonNegLeading(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this)
{
  CFunctor *result; // eax

  if ( (int)this->m_pAllocator >= 0 )
  {
    LOWORD(result) = *((_WORD *)this + 20);
    if ( (__int16)result > 0 )
      return (CFunctor *)(__int16)result;
  }
  else
  {
    LOBYTE(result) = *((_BYTE *)this + 29);
    if ( (char)result > 0 )
      return (CFunctor *)(char)result;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10167960
// Name: public: static int GFxImageSubstCmp::StrCompare(wchar_t const __near *,unsigned int,wchar_t const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
static unsigned int __cdecl GFxImageSubstCmp::StrCompare(
        const wchar_t *a1,
        unsigned int a2,
        const wchar_t *a3,
        unsigned int a4,
        bool a5)
{
  unsigned int v5; // edi
  const wchar_t *v6; // ecx
  unsigned int v7; // ebx
  int v8; // eax
  int v9; // esi

  v5 = a2;
  if ( a2 == 0 )
    return -a4;
  v6 = a3;
  v7 = a4;
  do
  {
    v8 = *(const wchar_t *)((char *)v6 + (char *)a1 - (char *)a3);
    v9 = *v6++;
    if ( --v5 == 0 || v8 == 0 )
      break;
    if ( v8 != v9 )
      return v8 - v9;
    --v7;
  }
  while ( v7 != 0 );
  if ( v8 == v9 && v7 != 0 && (!a5 || v5 != 0) )
    return a2 - a4;
  return v8 - v9;
}

//------------------------------------------------------------------------------
// Address: 0x101679D0
// Name: public: virtual void GFxTextDocView::DocumentText::OnParagraphRemoving(class GFxTextParagraph const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::DocumentText::OnParagraphRemoving(_DWORD **this)
{
  (*(void (__thiscall **)(_DWORD))(**(this + 9) + 8))(a1: *(this + 9));
}

//------------------------------------------------------------------------------
// Address: 0x101679E0
// Name: public: virtual void GFxTextDocView::DocumentText::OnTextInserting(unsigned int,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::DocumentText::OnTextInserting(
        _DWORD **this,
        void *startPos,
        const char *length,
        unsigned int lengtha)
{
  (*(void (__thiscall **)(_DWORD, int))(**(this + 9) + 4))(a1: *(this + 9), a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x101679F0
// Name: public: virtual void GFxTextDocView::DocumentText::OnTextRemoving(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *__thiscall GFxTextDocView::DocumentText::OnTextRemoving(
        _DWORD **this,
        GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *result,
        unsigned int startPos)
{
  return (*(GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *(__thiscall **)(_DWORD, int))(**(this + 9) + 4))(
           a1: *(this + 9),
           a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10167A00
// Name: public: virtual void GFxTextDocView::OnDocumentChanged(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::OnDocumentChanged(GRefCountBase<GFxAmpMemSegment,2> *this, __int16 notifyMask)
{
  if ( (notifyMask & 0x100) != 0 )
    *((_BYTE *)this + 336) |= 2u;
  else
    *((_BYTE *)this + 336) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10167A30
// Name: public: void GFxTextDocView::PostDisplay(class GFxDisplayContext __near &,class GMatrix2D const __near &,class GRenderer::Cxform const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::PostDisplay(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        const GArrayDefaultPolicy *context,
        int focused,
        int a4,
        int a5)
{
  int v5; // eax

  v5 = *((_DWORD *)this + 5);
  if ( v5 != 0 )
    *(_BYTE *)(v5 + 24) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10167A40
// Name: public: void GFxTextDocView::SetAutoSizeX(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetAutoSizeX(GFxTextDocView *this)
{
  char v1; // al

  v1 = *((_BYTE *)this + 334);
  if ( (v1 & 1) == 0 )
  {
    *((_BYTE *)this + 336) |= 2u;
    *((_BYTE *)this + 334) = v1 | 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167A60
// Name: public: void GFxTextDocView::SetAutoSizeY(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetAutoSizeY(GFxTextDocView *this)
{
  char v1; // al

  v1 = *((_BYTE *)this + 334);
  if ( (v1 & 2) == 0 )
  {
    *((_BYTE *)this + 336) |= 2u;
    *((_BYTE *)this + 334) = v1 | 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167A80
// Name: public: void GFxTextDocView::SetWordWrap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetWordWrap(GFxTextDocView *this)
{
  char v1; // al

  v1 = *((_BYTE *)this + 334);
  if ( (v1 & 8) == 0 )
  {
    *((_BYTE *)this + 336) |= 2u;
    *((_BYTE *)this + 334) = v1 | 8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167AA0
// Name: public: void GFxTextDocView::ClearWordWrap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::ClearWordWrap(GFxTextDocView *this)
{
  char v1; // al

  v1 = *((_BYTE *)this + 334);
  if ( (v1 & 8) != 0 )
  {
    *((_BYTE *)this + 336) |= 2u;
    *((_BYTE *)this + 334) = v1 & 0xF7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167AC0
// Name: public: void GFxTextDocView::UpdateHighlight(struct GFxTextHighlightDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::UpdateHighlight(
        GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> *this,
        unsigned int desc)
{
  int v2; // eax

  v2 = *((_DWORD *)this + 5);
  if ( v2 != 0 )
    *(_WORD *)(v2 + 24) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10167AD0
// Name: public: float GFxTextLineBuffer::Line::GetDescent(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxTextLineBuffer::Line::GetDescent(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this)
{
  int v1; // edx
  float v3; // [esp+0h] [ebp-8h]

  if ( (int)this->m_pAllocator >= 0 )
    v1 = *((_DWORD *)this + 6);
  else
    v1 = *((unsigned __int16 *)this + 11);
  if ( (int)this->m_pAllocator >= 0 )
    v3 = (float)*((unsigned __int16 *)this + 19);
  else
    v3 = (float)*((unsigned __int16 *)this + 13);
  return (float)((double)v1 - v3);
}

//------------------------------------------------------------------------------
// Address: 0x10167B70
// Name: public: bool GFxTextParagraphFormat::IsRightAlignment(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextParagraphFormat::IsRightAlignment(GFxTextParagraphFormat *this)
{
  int result; // eax

  result = 1;
  if ( (*((_BYTE *)this + 22) & 1) == 0 || (*((_WORD *)this + 11) & 0x600) != 0x200 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10167BA0
// Name: public: bool GFxTextParagraphFormat::IsCenterAlignment(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextParagraphFormat::IsCenterAlignment(GFxTextParagraphFormat *this)
{
  int result; // eax

  result = 1;
  if ( (*((_BYTE *)this + 22) & 1) == 0 || (*((_WORD *)this + 11) & 0x600) != 0x600 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10167BC0
// Name: public: void GFxTextDocView::SetText(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextDocView::SetText(
        CUtlMemory<GFxValue,int> **this@<ecx>,
        const char *a2@<edi>,
        const char *putf8String,
        unsigned int stringSize)
{
  GFxStyledText::SetText(this: *(this + 2), a2, putf8String, stringSize);
  ((void (__thiscall *)(CUtlMemory<GFxValue,int> **, int))(*this)->m_nAllocationCount)(a1: this, a2: 262);
}

//------------------------------------------------------------------------------
// Address: 0x10167BF0
// Name: public: void GFxTextDocView::SetText(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextDocView::SetText(
        GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > *this,
        CUtlMemory<GFxValue,int> *length,
        unsigned int a3)
{
  GFxStyledText::SetText(this: (CUtlMemory<GFxValue,int> *)this->Second.pObject, pstr: length, a3);
  return (*(unsigned int (__thiscall **)(GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > *, int))(LODWORD(this->First) + 4))(
           a1: this,
           a2: 262);
}

//------------------------------------------------------------------------------
// Address: 0x10167C20
// Name: public: void GFxTextDocView::SetTextFormat(class GFxTextFormat const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__userpurge GFxTextDocView::SetTextFormat@<eax>(
        int a1@<ecx>,
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *fmt,
        GMemoryHeap *startPos,
        const char *endPos,
        int a5)
{
  *(_BYTE *)(a1 + 336) &= ~0x10u;
  GFxStyledText::SetTextFormat(
    a1: *(char **)(a1 + 8),
    a2: (int)fmt,
    result: fmt,
    runLen: (unsigned int)startPos,
    (unsigned int)endPos);
  return (*(void *(__thiscall **)(int, int))(*(_DWORD *)a1 + 4))(a1, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10167C60
// Name: public: void GFxTextDocView::SetParagraphFormat(class GFxTextParagraphFormat const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxTextDocView::SetParagraphFormat(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **this,
        GRefCountNTSImpl *fmt,
        const char *startPos,
        unsigned int endPos)
{
  GFxStyledText::SetParagraphFormat(this: *(this + 2), fmt, indexInPara: (unsigned int)startPos, runLen: endPos);
  return ((void *(__thiscall *)(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **, int))(*this)->m_Memory.m_nAllocationCount)(
           a1: this,
           a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10167C90
// Name: public: class GString GFxTextDocView::GetText(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::GetText(
        GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > *this,
        CUtlMemory<CImagePacker,int> *a2)
{
  GFxStyledText::GetText(this: (GFxStyledText *)this->Second.pObject, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10167CB0
// Name: public: class GString GFxTextDocView::GetHtml(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::GetHtml(
        GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > *this,
        VertexShaderHandle_t__ **a2)
{
  GFxStyledText::GetHtml(this: (CRefCountServiceDestruct<CRefST>_vtbl *)this->Second.pObject, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10167CD0
// Name: public: void GFxTextDocView::ParseHtml(char const __near *,unsigned int,bool,class GArrayDH<struct GFxStyledText::HTMLImageTagInfo,2,struct GArrayDefaultPolicy> __near *,class GFxTextStyleManager const __near *,class GFxTextFormat const __near *,class GFxTextParagraphFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxTextDocView::ParseHtml(
        _DWORD *this,
        const char *putf8Str,
        GMemAddressStub *utf8Len,
        char condenseWhite,
        const char *pimgInfoArr,
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *a6,
        int a7,
        struct GFxTextParagraphFormat *a8)
{
  GMemAddressStub *v9; // eax

  GFxStyledText::Clear(this: *(this + 2));
  v9 = utf8Len;
  if ( utf8Len == (GMemAddressStub *)-1 )
    v9 = (GMemAddressStub *)strlen(putf8Str);
  GFxStyledText::ParseHtml(
    this: (const struct GFxTextParagraphFormat **)*(this + 2),
    a2: (int)putf8Str,
    htmlSize: (unsigned int)v9,
    a4: (int)pimgInfoArr,
    multiline: (*((_BYTE *)this + 334) & 4) != 0,
    condenseWhite,
    a7: a6,
    a8: a7,
    a9: a8);
  return (*(void *(__thiscall **)(_DWORD *, int))(*this + 4))(a1: this, a2: 262);
}

//------------------------------------------------------------------------------
// Address: 0x10167D40
// Name: public: void GFxTextDocView::ParseHtml(wchar_t const __near *,unsigned int,bool,class GArrayDH<struct GFxStyledText::HTMLImageTagInfo,2,struct GArrayDefaultPolicy> __near *,class GFxTextStyleManager const __near *,class GFxTextFormat const __near *,class GFxTextParagraphFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxTextDocView::ParseHtml(
        GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > *this,
        wchar_t *pwStr,
        GFxResourceId *a3,
        char condenseWhite,
        int a5,
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *a6,
        int a7,
        struct GFxTextParagraphFormat *a8)
{
  GFxResourceId *v9; // eax

  GFxStyledText::Clear(this: (int)this->Second.pObject);
  v9 = a3;
  if ( a3 == (GFxResourceId *)-1 )
    v9 = (GFxResourceId *)G_wcslen(pwch: pwStr);
  GFxStyledText::ParseHtml(
    this: (const struct GFxTextParagraphFormat **)this->Second.pObject,
    a2: pwStr,
    a3: v9,
    a4: a5,
    a5: (*((_BYTE *)this + 334) & 4) != 0,
    a6: condenseWhite,
    a7: a6,
    a8: a7,
    a9: a8);
  return (*(void *(__thiscall **)(GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> > *, int))(LODWORD(this->First) + 4))(
           a1: this,
           a2: 262);
}

//------------------------------------------------------------------------------
// Address: 0x10167DB0
// Name: public: void GFxTextDocView::AppendText(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextDocView::AppendText(
        GFxStyledText **this@<ecx>,
        const char *a2@<edi>,
        const char *putf8String,
        unsigned int utf8Len)
{
  unsigned int Length; // eax
  char v6; // al
  int ppdestTextFmt; // [esp+4h] [ebp-8h] BYREF
  int ppdestParaFmt; // [esp+8h] [ebp-4h] BYREF

  Length = GFxStyledText::GetLength(this: *(this + 2));
  if ( Length != 0
    && (GFxStyledText::GetTextAndParagraphFormat(
          this: (CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *)*(this + 2),
          &ppdestTextFmt,
          &ppdestParaFmt,
          indexInPara: Length - 1),
        v6 != 0) )
  {
    GFxStyledText::AppendString(
      this: (CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *)*(this + 2),
      a2,
      putf8String,
      stringSize: utf8Len,
      a5: (*(_BYTE *)(this + 84) & 8) == 0,
      a6: (struct GFxTextFormat *)ppdestTextFmt,
      a7: (SFTextObjectImpl *)ppdestParaFmt);
    (*((void (__thiscall **)(GFxStyledText **, int))*this + 1))(a1: this, a2: 6);
  }
  else
  {
    GFxStyledText::AppendString(
      this: (CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *)*(this + 2),
      a2,
      putf8String,
      stringSize: utf8Len,
      a5: (*(_BYTE *)(this + 84) & 8) == 0);
    (*((void (__thiscall **)(GFxStyledText **, int))*this + 1))(a1: this, a2: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167E50
// Name: public: void GFxTextDocView::AppendHtml(char const __near *,unsigned int,bool,class GArrayDH<struct GFxStyledText::HTMLImageTagInfo,2,struct GArrayDefaultPolicy> __near *)
// Source: json
//------------------------------------------------------------------------------
GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *__thiscall GFxTextDocView::AppendHtml(
        const struct GFxTextParagraphFormat ***this,
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *result,
        unsigned int utf8Len,
        char condenseWhite,
        int a5)
{
  unsigned int v5; // eax

  v5 = utf8Len;
  if ( utf8Len == -1 )
    v5 = strlen((const char *)result);
  GFxStyledText::ParseHtml(
    this: *(this + 2),
    a2: (int)result,
    htmlSize: v5,
    a4: a5,
    multiline: (*((_BYTE *)this + 334) & 4) != 0,
    condenseWhite,
    a7: nullptr,
    a8: 0,
    a9: nullptr);
  return ((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *(__thiscall *)(const struct GFxTextParagraphFormat ***, int))(*this)[1])(
           a1: this,
           a2: 6);
}

//------------------------------------------------------------------------------
// Address: 0x10167EB0
// Name: public: unsigned int GFxTextDocView::ReplaceTextA(wchar_t const __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextDocView::ReplaceTextA(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this@<ecx>,
        const char *a2@<ebx>,
        GFxValue *pstr,
        unsigned int a4,
        unsigned int endPos,
        unsigned int strLen)
{
  unsigned int v7; // eax

  if ( endPos < a4 )
    v7 = 0;
  else
    v7 = endPos - a4;
  GFxStyledText::Remove(this: (SFTextObjectImpl *)this->Data.Policy.Capacity, a2: a4, Length: v7);
  GFxStyledText::InsertString(
    this: (CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *)this->Data.Policy.Capacity,
    a2,
    pstr,
    a4,
    length: strLen,
    a6: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10167EF0
// Name: public: void GFxTextDocView::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::Close(GFxTextDocView *this)
{
  GRefCountNTSImpl *v2; // ecx
  GRefCountNTSImpl *v3; // ecx
  GRefCountNTSImpl *v4; // ecx

  if ( *((_DWORD *)this + 2) != 0 )
  {
    v2 = *((GRefCountNTSImpl **)this + 2);
    if ( v2 != nullptr )
      GRefCountNTSImpl::Release(this: v2);
    *((_DWORD *)this + 2) = 0;
    v3 = *((GRefCountNTSImpl **)this + 4);
    if ( v3 != nullptr )
      GRefCountNTSImpl::Release(this: v3);
    *((_DWORD *)this + 4) = 0;
    v4 = *((GRefCountNTSImpl **)this + 71);
    if ( v4 != nullptr )
      GRefCountNTSImpl::Release(this: v4);
    *((_DWORD *)this + 71) = 0;
    *((_BYTE *)this + 152) |= 1u;
    GFxTextLineBuffer::RemoveLines(this: (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)((char *)this + 36));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167F50
// Name: public: virtual void GFxTextDocView::OnDocumentParagraphRemoving(class GFxTextParagraph const __near &)
// Source: json
//------------------------------------------------------------------------------
const GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *__thiscall GFxTextDocView::OnDocumentParagraphRemoving(
        const GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        const GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *result)
{
  const GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v2; // eax
  _DWORD *v3; // ecx
  int v4; // esi
  int *v5; // eax
  int v6; // ebx
  bool found; // [esp+13h] [ebp-1h]

  v2 = this;
  v3 = this + 3;
  v4 = 0;
  found = false;
  while ( v3 != nullptr && (unsigned int)v4 < v3[1] && v4 >= 0 )
  {
    v5 = *(int **)(*v3 + 4 * v4);
    if ( *v5 >= 0 )
      v6 = v5[7];
    else
      v6 = v5[1];
    if ( result[2].Data.Policy.Capacity == v6 )
    {
      found = true;
      if ( *v5 >= 0 )
        v5[2] = -1;
      else
        v5[2] |= 0xFFFFFFu;
    }
    else if ( found )
    {
      v2 = this;
      break;
    }
    v2 = this;
    if ( (unsigned int)v4 < v3[1] )
      ++v4;
  }
  LOBYTE(v2[28].Data.Data) |= 1u;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10167FE0
// Name: public: void GFxLineCursor::operator+=(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxLineCursor::operator+=(_DWORD *this, unsigned int a2)
{
  unsigned int result; // eax
  GFxResourceId *v4; // edx
  unsigned int Id; // ecx
  int v6; // ebx
  unsigned int v7; // edi
  unsigned int v8; // ecx

  result = *(this + 7);
  if ( result != 0
    && (result = GFxTextParagraph::GetLength(this: (GFxResourceId *)(result + 20))) != 0
    && (v4 = (GFxResourceId *)*(this + 7),
        result = *(this + 26) + *(_DWORD *)(*(this + 12) + 28),
        Id = v4[12].Id,
        result <= Id) )
  {
    v6 = a2;
    if ( result + a2 >= Id )
    {
      v7 = Id - result;
      if ( Id - result >= a2 )
        v7 = a2;
      result = GFxTextParagraph::GetLength(this: v4 + 5);
      v8 = a2 + *(this + 10) - v7;
      if ( v8 <= result )
      {
        *(this + 42) += a2 - v7;
        *(this + 10) = v8;
      }
      else
      {
        v7 = a2 + *(this + 10) - GFxTextParagraph::GetLength(this: (GFxResourceId *)(*(this + 7) + 20));
        result = GFxTextParagraph::GetLength(this: (GFxResourceId *)(*(this + 7) + 20));
        *(this + 42) += result;
        *(this + 10) = result;
      }
      v6 = v7;
    }
  }
  else
  {
    v6 = a2;
  }
  if ( v6 != 0 )
  {
    result = GFxTextParagraph::CharactersIterator::operator+=(this: this + 19, a2: v6);
    *(this + 42) += v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10168090
// Name: public: void GFxLineCursor::TrackFontParams(class GFxFontResource __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLineCursor::TrackFontParams(GFxLineCursor *this, struct GFxFontResource *a2, float a3)
{
  __int16 *pElems; // eax
  double v5; // st7
  double v6; // st6
  double v7; // st6
  __int16 *v8; // eax
  float v9; // [esp+0h] [ebp-8h]
  float v10; // [esp+4h] [ebp-4h]
  float v11; // [esp+10h] [ebp+8h]
  float v12; // [esp+10h] [ebp+8h]
  float v13; // [esp+10h] [ebp+8h]
  float v14; // [esp+10h] [ebp+8h]
  float v15; // [esp+10h] [ebp+8h]
  float v16; // [esp+10h] [ebp+8h]
  float v17; // [esp+14h] [ebp+Ch]
  float v18; // [esp+14h] [ebp+Ch]

  pElems = a2[1].pElems;
  v11 = *((float *)pElems + 2);
  v10 = *((float *)pElems + 3);
  if ( 0.0 == v11 )
    v11 = 960.0;
  if ( v10 == 0.0 )
    v10 = 64.0;
  v9 = *((float *)this + 16);
  v5 = a3;
  v12 = v11 * a3;
  v6 = v12;
  if ( v9 > (double)v12 )
    v6 = v9;
  v13 = v6;
  *((float *)this + 16) = v13;
  v17 = *((float *)this + 17);
  v14 = v10 * v5;
  v7 = v14;
  if ( v17 > (double)v14 )
    v7 = v17;
  v8 = a2[1].pElems;
  v15 = v7;
  *((float *)this + 17) = v15;
  v18 = *((float *)this + 18);
  v16 = v5 * *((float *)v8 + 4);
  if ( v18 > (double)v16 )
    v16 = v18;
  *((float *)this + 18) = v16;
}

//------------------------------------------------------------------------------
// Address: 0x10168180
// Name: public: float GFxParagraphFormatter::GetActualFontSize(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxParagraphFormatter::GetActualFontSize(GFxParagraphFormatter *this)
{
  int v1; // edx
  int v2; // ecx
  float v4; // [esp+0h] [ebp-8h]
  float v5; // [esp+4h] [ebp-4h]

  v1 = *((_DWORD *)this + 52);
  v5 = (double)*(unsigned __int16 *)(*((_DWORD *)this + 50) + 38) / 20.0;
  if ( 1.0 != *(float *)(v1 + 16) )
    v5 = *(float *)(v1 + 16) * v5;
  v2 = *(_DWORD *)this;
  if ( (*(_BYTE *)(v2 + 336) & 4) != 0 )
  {
    v4 = (double)*(unsigned __int16 *)(v2 + 330) / 20.0;
    return (float)(v4 * v5);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10168200
// Name: public: void GFxTextDocView::PreDisplay(class GFxDisplayContext __near &,class GMatrix2D const __near &,class GRenderer::Cxform const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::PreDisplay(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::Iterator *context,
        int a3,
        int a4,
        char a5)
{
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v5; // ecx

  v5 = *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
       + 71);
  if ( v5 != nullptr && a5 != 0 )
    GFxTextEditorKit::PreDisplay(this: v5, result: context);
}

//------------------------------------------------------------------------------
// Address: 0x10168230
// Name: public: void GFxTextDocView::SetFontScaleFactor(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextDocView::SetFontScaleFactor(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        float f)
{
  if ( 1.0 == f )
  {
    *((_BYTE *)this + 336) &= ~4u;
    *((_WORD *)this + 165) = 20;
    return 20;
  }
  else
  {
    *((_BYTE *)this + 336) |= 4u;
    *((_WORD *)this + 165) = (int)(f * 20.0);
    return HIWORD(f) | 0xC00;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101682A0
// Name: public: unsigned int GFxTextDocView::GetFirstCharInParagraph(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextDocView::GetFirstCharInParagraph(GFxTextDocView *this, unsigned int indexOfChar)
{
  SFTextObjectImpl *v2; // ecx
  GFxValue index; // [esp+4h] [ebp-Ch] BYREF

  v2 = *((SFTextObjectImpl **)this + 2);
  index.Value.pString = (const char *)-1;
  GFxStyledText::GetParagraphByIndex(
    this: v2,
    &index,
    indexa: indexOfChar,
    pindexInParagraph: (unsigned int *)&index.Value);
  if ( index.pObjectInterface != nullptr
    && index.Type >= VT_Undefined
    && index.Type < (int)index.pObjectInterface[1].pMovieRoot )
  {
    return indexOfChar - (unsigned int)index.Value.pString;
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101682F0
// Name: public: class GFxTextEditorKit __near * GFxTextDocView::CreateEditorKit(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxTextEditorKit *__usercall GFxTextDocView::CreateEditorKit@<eax>(
        GFxTextDocView *this@<ecx>,
        unsigned int a2@<edi>)
{
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v3; // eax
  int v4; // eax
  int v5; // edi
  GRefCountNTSImpl *v6; // ecx
  int v8; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 71) != 0 )
    return *((struct GFxTextEditorKit **)this + 71);
  v8 = 324;
  v3 = (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 112, a4: &v8);
  if ( v3 != nullptr )
  {
    GFxTextEditorKit::GFxTextEditorKit(this: v3, pdocview: this, a3: a2);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = *((GRefCountNTSImpl **)this + 71);
  if ( v6 != nullptr )
    GRefCountNTSImpl::Release(this: v6);
  *((_DWORD *)this + 71) = v5;
  return (struct GFxTextEditorKit *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10168360
// Name: protected: void GFxTextDocView::SetDefaultTextAndParaFormat(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetDefaultTextAndParaFormat(
        GRefCountBase<GFxAmpMemSegment,2> *this,
        unsigned int cursorPos)
{
  unsigned int v2; // esi
  SFTextObjectImpl *v4; // ecx
  char v5; // al
  GFxValue index; // [esp+8h] [ebp-14h] BYREF
  int ppdestParaFmt; // [esp+18h] [ebp-4h] BYREF

  v2 = cursorPos;
  v4 = *((SFTextObjectImpl **)this + 2);
  ppdestParaFmt = 0;
  *(_QWORD *)&index.Value.NValue = 0xFFFFFFFFLL;
  GFxStyledText::GetParagraphByIndex(
    this: v4,
    &index,
    indexa: cursorPos,
    pindexInParagraph: (unsigned int *)&index.Value);
  if ( index.pObjectInterface != nullptr
    && index.Type >= VT_Undefined
    && index.Type < (int)index.pObjectInterface[1].pMovieRoot
    && cursorPos - (unsigned int)index.Value.pString != -1 )
  {
    if ( cursorPos - (unsigned int)index.Value.pString != cursorPos )
      v2 = cursorPos - 1;
    GFxStyledText::GetTextAndParagraphFormat(
      this: *((CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)this + 2),
      ppdestTextFmt: (int *)&index.Value.pStringManaged + 1,
      &ppdestParaFmt,
      indexInPara: v2);
    if ( v5 != 0 )
    {
      GFxFontDataCompactedSwf::SetTextureGlyphData(
        this: *((CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)this + 2),
        pdata: ppdestParaFmt);
      GFxStyledText::SetDefaultTextFormat(
        this: *((CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)this + 2),
        a2: *((CMemberFuncProxy3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CFuncMemPolicyNone> **)&index.Value.pStringManaged
        + 1));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101683F0
// Name: protected: bool GFxTextDocView::ContainsNonLeftAlignment(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextDocView::ContainsNonLeftAlignment(_DWORD *this)
{
  int v1; // edx
  unsigned int v2; // esi
  unsigned int v3; // eax
  int v4; // ecx

  v1 = *(this + 2);
  v2 = *(_DWORD *)(v1 + 16);
  v3 = 0;
  if ( v2 == 0 )
    return 0;
  while ( 1 )
  {
    v4 = v3 >= v2 ? 0 : *(_DWORD *)(*(_DWORD *)(v1 + 12) + 4 * v3);
    if ( (*(_WORD *)(*(_DWORD *)(v4 + 12) + 22) & 0x600) != 0 )
      break;
    if ( ++v3 >= v2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10168430
// Name: protected: unsigned int GFxTextDocView::GetMaxHScrollValue(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextDocView::GetMaxHScrollValue(GFxTextDocView *this)
{
  int v2; // eax
  unsigned int v3; // eax
  double v4; // st7
  double v5; // st6
  int editorDelta; // [esp+4h] [ebp-8h]
  int editorDeltaa; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]
  float v10; // [esp+8h] [ebp-4h]

  if ( (*((_BYTE *)this + 334) & 8) != 0 )
    return 0;
  v2 = *((_DWORD *)this + 71);
  if ( v2 == 0 || (editorDelta = 1200, (*(_BYTE *)(v2 + 104) & 1) != 0) )
    editorDelta = 0;
  v3 = *((_DWORD *)this + 66);
  v4 = 0.0;
  if ( v3 != 0 )
    v9 = (float)v3;
  else
    v9 = 0.0;
  v5 = v9;
  v10 = *((float *)this + 17) - *((float *)this + 15);
  *(float *)&editorDeltaa = v5 - v10 + (double)editorDelta;
  if ( *(float *)&editorDeltaa >= 0.0 )
    v4 = *(float *)&editorDeltaa;
  return (__int64)(float)v4;
}

//------------------------------------------------------------------------------
// Address: 0x101684E0
// Name: public: unsigned int GFxTextDocView::GetMaxHScroll(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextDocView::GetMaxHScroll(GFxTextDocView *this)
{
  if ( (*((_BYTE *)this + 336) & 3) != 0 )
  {
    GFxTextDocView::Format(this);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  return GFxTextDocView::GetMaxHScrollValue(this);
}

//------------------------------------------------------------------------------
// Address: 0x10168500
// Name: public: unsigned int GFxTextDocView::GetMaxVScroll(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextDocView::GetMaxVScroll(GFxTextDocView *this)
{
  __int16 v2; // ax
  int v3; // ecx
  int result; // eax
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // edi
  int v9; // edi
  int v10; // eax
  int v11; // edi
  int v12; // ebx
  int i; // edx
  __int16 v14; // cx
  __int16 v15; // ax
  float v16; // [esp+8h] [ebp-8h]
  int v17; // [esp+Ch] [ebp-4h]

  if ( (*((_BYTE *)this + 336) & 3) != 0 )
  {
    GFxTextDocView::Format(this);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  v2 = *((_WORD *)this + 164);
  if ( *((_WORD *)this + 140) == v2 )
    return *((_DWORD *)this + 69);
  v3 = *((_DWORD *)this + 10);
  if ( v3 != 0 )
  {
    v5 = *((_DWORD *)this + 71);
    v17 = 0;
    v6 = *((_DWORD *)this + 9);
    v7 = v3 - 1;
    v8 = *(_DWORD *)(v6 + 4 * v7);
    if ( v5 == 0 || (*(_BYTE *)(v5 + 104) & 1) != 0 )
    {
      v9 = *(int *)v8 >= 0 ? *(_DWORD *)(v8 + 32) : *(unsigned __int8 *)(v8 + 11);
      if ( v9 == 0 )
      {
        if ( v7 >= 0 )
          --v7;
        v17 = 1;
      }
    }
    if ( (unsigned int)v7 >= *((_DWORD *)this + 10) || v7 < 0 )
    {
      v15 = *((_WORD *)this + 164);
      *((_DWORD *)this + 69) = 0;
      *((_WORD *)this + 140) = v15;
      return *((_DWORD *)this + 69);
    }
    else
    {
      v10 = *(_DWORD *)(v6 + 4 * v7);
      v11 = v6 + 4 * v7;
      if ( *(int *)v10 >= 0 )
        v12 = *(_DWORD *)(v10 + 24);
      else
        v12 = *(unsigned __int16 *)(v10 + 22);
      for ( i = v17; (unsigned int)v7 < *((_DWORD *)this + 10); ++i )
      {
        if ( v7 < 0 )
          break;
        if ( i != 0 )
        {
          v16 = (double)(v12 + *(_DWORD *)(v10 + 16)) - *((float *)this + 18) + *((float *)this + 16);
          if ( (double)*(int *)(*(_DWORD *)v11 + 16) < v16 )
            break;
        }
        --v7;
        v11 -= 4;
      }
      v14 = *((_WORD *)this + 164);
      result = *((_DWORD *)this + 10) - i;
      *((_DWORD *)this + 69) = result;
      *((_WORD *)this + 140) = v14;
    }
  }
  else
  {
    *((_WORD *)this + 140) = v2;
    *((_DWORD *)this + 69) = 0;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10168660
// Name: protected: struct GFxTextHighlightDesc __near * GFxTextDocView::GetSelectionHighlighterDesc(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxTextHighlightDesc *__thiscall GFxTextDocView::GetSelectionHighlighterDesc(GFxTextDocView *this)
{
  GFxTextHighlighter *v2; // ecx
  struct GFxTextHighlightDesc *result; // eax
  IVJobs *v4; // ecx
  int (__cdecl *desc)(const char *const *, const char *const *); // [esp+8h] [ebp-28h] BYREF
  int v6; // [esp+Ch] [ebp-24h]
  int v7; // [esp+10h] [ebp-20h]
  int v8; // [esp+14h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  int v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-8h]
  char v14; // [esp+2Ch] [ebp-4h]

  v2 = *((GFxTextHighlighter **)this + 5);
  if ( v2 == nullptr )
    return nullptr;
  result = GFxTextHighlighter::GetHighlighterPtr(this: v2, a2: 0x7FFFFFFFu);
  if ( result == nullptr )
  {
    v4 = *((IVJobs **)this + 5);
    v7 = -1;
    v12 = -1;
    v8 = 0;
    v9 = 0;
    v13 = 0;
    desc = nullptr;
    v6 = 0;
    v10 = 0x7FFFFFFF;
    v11 = -16777216;
    v14 = 24;
    return (struct GFxTextHighlightDesc *)GFxTextHighlighter::CreateHighlighter(this: v4, (const IVJobs *)&desc);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10168890
// Name: public: bool GFxTextDocView::SetHScrollOffset(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextDocView::SetHScrollOffset(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *hscroll)
{
  unsigned int MaxHScrollValue; // eax
  const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v4; // edi
  int v5; // ecx

  if ( (*(_BYTE *)(this + 28) & 3) != 0 )
  {
    GFxTextDocView::Format((GFxTextDocView *)this);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  MaxHScrollValue = GFxTextDocView::GetMaxHScrollValue((GFxTextDocView *)this);
  v4 = hscroll;
  if ( (unsigned int)hscroll > MaxHScrollValue )
    v4 = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)MaxHScrollValue;
  if ( *((const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > **)this + 19) == v4 )
    return 0;
  GFxTextLineBuffer::SetHScrollOffset(result: v4);
  v5 = *((_DWORD *)this + 4);
  if ( v5 != 0 )
    (*(void (__thiscall **)(int, GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *, const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *))(*(_DWORD *)v5 + 8))(
      a1: v5,
      a2: this,
      a3: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101688F0
// Name: public: bool GFxTextDocView::SetVScrollOffset(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextDocView::SetVScrollOffset(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *vscroll)
{
  unsigned int MaxVScroll; // eax
  const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v4; // edi
  int v5; // ecx

  MaxVScroll = GFxTextDocView::GetMaxVScroll((GFxTextDocView *)this);
  v4 = vscroll;
  if ( (unsigned int)vscroll > MaxVScroll )
    v4 = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)MaxVScroll;
  if ( *((const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > **)this + 14) == v4 )
    return 0;
  GFxTextLineBuffer::SetFirstVisibleLine(result: v4);
  v5 = *((_DWORD *)this + 4);
  if ( v5 != 0 )
    (*(void (__thiscall **)(int, GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *, const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *))(*(_DWORD *)v5 + 12))(
      a1: v5,
      a2: this,
      a3: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10168940
// Name: public: bool GFxTextDocView::SetBottomVScroll(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextDocView::SetBottomVScroll(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this,
        unsigned int newBottomMostLine)
{
  unsigned int v2; // eax
  int v3; // esi
  int v4; // edi
  int *v5; // eax
  int v6; // ebx
  int v7; // edx
  int v8; // ecx
  double v9; // st7
  int v10; // eax
  unsigned int MaxVScroll; // eax
  int v12; // ecx
  int v14; // [esp+10h] [ebp-18h]
  unsigned int v15; // [esp+1Ch] [ebp-Ch]
  int **v16; // [esp+20h] [ebp-8h]
  float top; // [esp+30h] [ebp+8h]

  v2 = *((_DWORD *)this + 10);
  v3 = newBottomMostLine;
  if ( newBottomMostLine >= v2 )
    v3 = v2 - 1;
  v4 = v3;
  v14 = v3;
  if ( this == (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)-36 )
    return 0;
  v15 = *((_DWORD *)this + 10);
  if ( v3 >= v15 || v3 < 0 )
    return 0;
  v16 = (int **)(*((_DWORD *)this + 9) + 4 * v3);
  v5 = *v16;
  if ( **v16 >= 0 )
    v6 = v5[6];
  else
    v6 = *((unsigned __int16 *)v5 + 11);
  if ( **v16 >= 0 )
  {
    LOWORD(v7) = *((_WORD *)v5 + 20);
    if ( (__int16)v7 > 0 )
    {
      v7 = (__int16)v7;
      goto LABEL_15;
    }
  }
  else
  {
    LOBYTE(v7) = *((_BYTE *)v5 + 29);
    if ( (char)v7 > 0 )
    {
      v7 = (char)v7;
      goto LABEL_15;
    }
  }
  v7 = 0;
LABEL_15:
  v8 = *((_DWORD *)this + 9) + 4 * v3;
  v9 = (double)(v6 + v7 + v5[4]);
  v10 = v3;
  do
  {
    if ( v10 >= v15 )
      break;
    if ( v10 < 0 )
      break;
    top = v9 - *((float *)this + 18) + *((float *)this + 16);
    if ( (double)*(int *)(*(_DWORD *)v8 + 16) < top )
      break;
    v10 = v14 - 1;
    v3 = v4;
    v8 -= 4;
    --v4;
    --v14;
  }
  while ( v4 >= 0 );
  MaxVScroll = GFxTextDocView::GetMaxVScroll((GFxTextDocView *)this);
  if ( v3 > MaxVScroll )
    v3 = MaxVScroll;
  if ( *((_DWORD *)this + 14) == v3 )
    return 0;
  GFxTextLineBuffer::SetFirstVisibleLine(result: (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v3);
  v12 = *((_DWORD *)this + 4);
  if ( v12 != 0 )
    (*(void (__thiscall **)(int, GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *, int))(*(_DWORD *)v12 + 12))(
      a1: v12,
      a2: this,
      a3: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10168BD0
// Name: protected: void GFxTextDocView::SetViewRect(class GRect<float> const __near &,enum GFxTextDocView::UseType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetViewRect(GFxTextDocView *this, float *a2, int a3)
{
  unsigned int v5; // edx
  unsigned __int8 v6; // bl
  unsigned int v7; // ecx
  unsigned int v8; // edi
  const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *MaxHScroll; // eax
  const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *MaxVScroll; // eax
  unsigned int v11; // [esp+8h] [ebp-18h]
  float v12; // [esp+Ch] [ebp-14h]
  float v13; // [esp+10h] [ebp-10h]
  float v14; // [esp+14h] [ebp-Ch]
  float v15; // [esp+18h] [ebp-8h]
  float v16; // [esp+18h] [ebp-8h]
  float v17; // [esp+1Ch] [ebp-4h]
  float v18; // [esp+28h] [ebp+8h]
  float v19; // [esp+28h] [ebp+8h]
  float v20; // [esp+28h] [ebp+8h]
  float v21; // [esp+28h] [ebp+8h]
  float v22; // [esp+28h] [ebp+8h]

  if ( *((float *)this + 62) != *a2
    || *((float *)this + 64) != a2[2]
    || *((float *)this + 63) != a2[1]
    || *((float *)this + 65) != a2[3] )
  {
    v18 = *((float *)this + 64) - *((float *)this + 62);
    v5 = (__int64)v18;
    v19 = *((float *)this + 65) - *((float *)this + 63);
    v11 = (__int64)v19;
    v20 = a2[1];
    v17 = a2[2];
    v15 = a2[3];
    *((float *)this + 62) = *a2;
    *((float *)this + 63) = v20;
    *((float *)this + 64) = v17;
    *((float *)this + 65) = v15;
    v12 = *((float *)this + 62) + 40.0;
    v14 = *((float *)this + 64) - 40.0;
    v13 = *((float *)this + 63) + 40.0;
    v16 = *((float *)this + 65) - 40.0;
    *((float *)this + 15) = v12;
    *((float *)this + 16) = v13;
    *((float *)this + 17) = v14;
    *((float *)this + 18) = v16;
    if ( a3 == 1 )
    {
      v6 = *((_BYTE *)this + 332);
      v21 = *((float *)this + 64) - *((float *)this + 62);
      v7 = (__int64)v21;
      v22 = *((float *)this + 65) - *((float *)this + 63);
      v8 = (__int64)v22;
      if ( (v6 & 0x30) != 0
        || v5 != v7
        && ((*((_BYTE *)this + 334) & 8) != 0
         || v7 < v5 && (*((_BYTE *)this + 152) & 0x20) != 0
         || (v6 & 3) != 0
         || GFxTextDocView::ContainsNonLeftAlignment(this) != 0)
        || v11 != v8 && (((v6 >> 2) & 3u) > 1 || v8 < v11 && (*((_BYTE *)this + 152) & 0x20) != 0) )
      {
        *((_BYTE *)this + 336) |= 2u;
      }
      else
      {
        ++*((_WORD *)this + 164);
        MaxHScroll = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)GFxTextDocView::GetMaxHScroll(this);
        if ( *((_DWORD *)this + 19) > (unsigned int)MaxHScroll )
          GFxTextDocView::SetHScrollOffset(
            (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)this,
            hscroll: MaxHScroll);
        MaxVScroll = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)GFxTextDocView::GetMaxVScroll(this);
        if ( *((_DWORD *)this + 14) > (unsigned int)MaxVScroll )
          GFxTextDocView::SetVScrollOffset(
            (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)this,
            vscroll: MaxVScroll);
        *((_BYTE *)this + 152) |= 1u;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168E30
// Name: public: GFxLineCursor::GFxLineCursor(void)
// Source: json
//------------------------------------------------------------------------------
GFxLineCursor *__thiscall GFxLineCursor::GFxLineCursor(GFxLineCursor *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((float *)this + 4) = 0.0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((float *)this + 16) = 0.0;
  *((float *)this + 17) = 0.0;
  *((_DWORD *)this + 9) = 0;
  *((float *)this + 18) = 0.0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 8) = -1;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_WORD *)this + 42) = 0;
  *((_DWORD *)this + 24) = -1;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_WORD *)this + 58) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  *((float *)this + 40) = 1.0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_WORD *)this + 82) = 0;
  *((_DWORD *)this + 42) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10168EF0
// Name: public: GFxLineCursor::GFxLineCursor(class GFxTextDocView __near *,class GFxTextParagraph const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxLineCursor *__thiscall GFxLineCursor::GFxLineCursor(
        GFxLineCursor *this,
        struct GFxTextDocView *a2,
        IGameEvent *pparagraph)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((float *)this + 4) = 0.0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((float *)this + 16) = 0.0;
  *((_DWORD *)this + 11) = a2;
  *((float *)this + 17) = 0.0;
  *((float *)this + 18) = 0.0;
  *((_DWORD *)this + 8) = -1;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 12) = pparagraph;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  GFxTextParagraph::CharactersIterator::CharactersIterator(this: (IGameEvent *)this + 19, pparagraph, index: 0);
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_WORD *)this + 58) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  *((float *)this + 40) = 1.0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_WORD *)this + 82) = 0;
  *((_DWORD *)this + 42) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10168FB0
// Name: public: struct GFxTextParagraph::CharacterInfo const __near & GFxLineCursor::operator*(void)
// Source: json
//------------------------------------------------------------------------------
IShaderAPI **__thiscall GFxLineCursor::operator*(int this)
{
  GFxResourceId *v2; // eax
  GFxResourceId *v3; // ecx
  unsigned int v4; // eax
  unsigned int Id; // edx
  int v6; // eax
  const GFxFontMap::MapEntry *v7; // ecx
  int v8; // edx
  int v9; // eax
  const GFxFontMap::MapEntry *TextFormatPtr; // ebx
  int *v11; // eax
  CMaterial *v12; // edi
  int v13; // eax
  GStringDH *TextFormat; // eax
  IShaderAPI *v15; // ecx
  GStringDH *v16; // edi
  IShaderAPI **result; // eax
  int v18; // ebx
  IShaderDevice **v19; // ebx
  IShaderDevice *v20; // ecx
  __int16 v21; // dx
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v22; // [esp+Ch] [ebp-30h] BYREF
  IShaderAPI **v23; // [esp+38h] [ebp-4h]

  *(_DWORD *)(this + 112) = *(_DWORD *)(GFxTextParagraph::CharactersIterator::operator*(this: this + 76) + 4);
  v2 = *(GFxResourceId **)(this + 28);
  if ( v2 != nullptr && GFxTextParagraph::GetLength(this: v2 + 5) != 0 )
  {
    v3 = *(GFxResourceId **)(this + 28);
    v4 = *(_DWORD *)(this + 112) + *(_DWORD *)(*(_DWORD *)(this + 48) + 28);
    Id = v3[12].Id;
    if ( v4 >= Id )
    {
      if ( v4 == Id && *(_DWORD *)(this + 40) < GFxTextParagraph::GetLength(this: v3 + 5) )
      {
        v6 = GFxTextParagraph::CharactersIterator::operator*(this: this + 76);
        v7 = *(const GFxFontMap::MapEntry **)(this + 40);
        v8 = *(_DWORD *)(v6 + 4);
        v9 = *(_DWORD *)(this + 28);
        *(_DWORD *)(this + 112) = (char *)v7 + v8;
        *(_WORD *)(this + 116) = *(_WORD *)(*(_DWORD *)(v9 + 20) + 2 * (_DWORD)v7);
        TextFormatPtr = GFxTextParagraph::GetTextFormatPtr(this: v9 + 20, result: v7);
        v11 = (int *)GFxTextParagraph::CharactersIterator::operator*(this: this + 76);
        v12 = *(CMaterial **)(*(_DWORD *)(this + 28) + 16);
        v13 = GFxTextFormat::Merge(a1: *v11, a2: (int)TextFormatPtr, a3: (int)&v22, fmt: (int)TextFormatPtr);
        TextFormat = GFxTextAllocator::AllocateTextFormat(this: v12, srcfmt: v13);
        v15 = *(IShaderAPI **)(this + 108);
        v16 = TextFormat;
        if ( v15 != nullptr )
          GRefCountImpl::Release(this: v15);
        *(_DWORD *)(this + 108) = v16;
        GFxTextFormat::~GFxTextFormat(this: &v22);
        return (IShaderAPI **)(this + 108);
      }
      v18 = GFxTextParagraph::CharactersIterator::operator*(this: this + 76);
      *(_DWORD *)(this + 112) = GFxTextParagraph::GetLength(this: (GFxResourceId *)(*(_DWORD *)(this + 28) + 20))
                              + *(_DWORD *)(v18 + 4);
    }
  }
  v19 = (IShaderDevice **)GFxTextParagraph::CharactersIterator::operator*(this: this + 76);
  v20 = *v19;
  v23 = (IShaderAPI **)(this + 108);
  if ( v20 != nullptr )
    GRefCountImpl::AddRef(this: v20);
  if ( *v23 != nullptr )
    GRefCountImpl::Release(this: *v23);
  *v23 = (IShaderAPI *)*v19;
  if ( (*(_BYTE *)(*(_DWORD *)(this + 44) + 334) & 0x10) != 0
    && *(_WORD *)(GFxTextParagraph::CharactersIterator::operator*(this: this + 76) + 8) != 0 )
  {
    result = v23;
    *(_WORD *)(this + 116) = 42;
  }
  else
  {
    v21 = *(_WORD *)(GFxTextParagraph::CharactersIterator::operator*(this: this + 76) + 8);
    result = v23;
    *(_WORD *)(this + 116) = v21;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10169120
// Name: public: GFxLineCursor::~GFxLineCursor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLineCursor::~GFxLineCursor(GFxLineCursor *this)
{
  IShaderAPI *v2; // ecx
  IShaderAPI *v3; // ecx
  GRefCountNTSImpl *v4; // ecx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v5; // esi

  v2 = *((IShaderAPI **)this + 27);
  if ( v2 != nullptr )
    GRefCountImpl::Release(this: v2);
  v3 = *((IShaderAPI **)this + 19);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = *((GRefCountNTSImpl **)this + 7);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  v5 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
       + 1);
  if ( v5 != nullptr && LODWORD(v5->m_pfnProxied)-- == 1 )
  {
    GFxFontHandle::~GFxFontHandle(this: v5);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169170
// Name: public: class GFxLineCursor __near & GFxLineCursor::operator=(class GFxLineCursor const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxLineCursor::operator=(void *this, int a2)
{
  _DWORD *v3; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v4; // ebx
  int v6; // eax
  GRefCountNTSImpl *v7; // ecx
  IShaderDevice *v8; // ecx
  IShaderAPI *v9; // ecx
  IShaderDevice *v10; // ecx
  IShaderAPI *v11; // ecx

  *(_DWORD *)this = *(_DWORD *)a2;
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 != nullptr )
    ++*v3;
  v4 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
       + 1);
  if ( v4 != nullptr && LODWORD(v4->m_pfnProxied)-- == 1 )
  {
    GFxFontHandle::~GFxFontHandle(this: v4);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  }
  *((_DWORD *)this + 1) = *(_DWORD *)(a2 + 4);
  *((_DWORD *)this + 2) = *(_DWORD *)(a2 + 8);
  *((_DWORD *)this + 3) = *(_DWORD *)(a2 + 12);
  *((float *)this + 4) = *(float *)(a2 + 16);
  *((_DWORD *)this + 5) = *(_DWORD *)(a2 + 20);
  *((_DWORD *)this + 6) = *(_DWORD *)(a2 + 24);
  v6 = *(_DWORD *)(a2 + 28);
  if ( v6 != 0 )
    ++*(_DWORD *)(v6 + 4);
  v7 = *((GRefCountNTSImpl **)this + 7);
  if ( v7 != nullptr )
    GRefCountNTSImpl::Release(this: v7);
  *((_DWORD *)this + 7) = *(_DWORD *)(a2 + 28);
  *((_DWORD *)this + 8) = *(_DWORD *)(a2 + 32);
  *((_DWORD *)this + 9) = *(_DWORD *)(a2 + 36);
  *((_DWORD *)this + 10) = *(_DWORD *)(a2 + 40);
  *((_DWORD *)this + 11) = *(_DWORD *)(a2 + 44);
  *((_DWORD *)this + 12) = *(_DWORD *)(a2 + 48);
  *((_DWORD *)this + 13) = *(_DWORD *)(a2 + 52);
  *((_DWORD *)this + 14) = *(_DWORD *)(a2 + 56);
  *((_DWORD *)this + 15) = *(_DWORD *)(a2 + 60);
  *((float *)this + 16) = *(float *)(a2 + 64);
  *((float *)this + 17) = *(float *)(a2 + 68);
  *((float *)this + 18) = *(float *)(a2 + 72);
  v8 = *(IShaderDevice **)(a2 + 76);
  if ( v8 != nullptr )
    GRefCountImpl::AddRef(this: v8);
  v9 = *((IShaderAPI **)this + 19);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *((_DWORD *)this + 19) = *(_DWORD *)(a2 + 76);
  *((_DWORD *)this + 20) = *(_DWORD *)(a2 + 80);
  *((_WORD *)this + 42) = *(_WORD *)(a2 + 84);
  *((_DWORD *)this + 22) = *(_DWORD *)(a2 + 88);
  *((_DWORD *)this + 23) = *(_DWORD *)(a2 + 92);
  *((_DWORD *)this + 24) = *(_DWORD *)(a2 + 96);
  *((_DWORD *)this + 25) = *(_DWORD *)(a2 + 100);
  *((_DWORD *)this + 26) = *(_DWORD *)(a2 + 104);
  v10 = *(IShaderDevice **)(a2 + 108);
  if ( v10 != nullptr )
    GRefCountImpl::AddRef(this: v10);
  v11 = *((IShaderAPI **)this + 27);
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  *((_DWORD *)this + 27) = *(_DWORD *)(a2 + 108);
  *((_DWORD *)this + 28) = *(_DWORD *)(a2 + 112);
  *((_WORD *)this + 58) = *(_WORD *)(a2 + 116);
  *((_DWORD *)this + 30) = *(_DWORD *)(a2 + 120);
  *((_DWORD *)this + 31) = *(_DWORD *)(a2 + 124);
  *((_DWORD *)this + 32) = *(_DWORD *)(a2 + 128);
  *((_DWORD *)this + 33) = *(_DWORD *)(a2 + 132);
  *((_DWORD *)this + 34) = *(_DWORD *)(a2 + 136);
  *((_DWORD *)this + 35) = *(_DWORD *)(a2 + 140);
  *((_DWORD *)this + 36) = *(_DWORD *)(a2 + 144);
  *((_DWORD *)this + 37) = *(_DWORD *)(a2 + 148);
  *((_DWORD *)this + 38) = *(_DWORD *)(a2 + 152);
  *((_DWORD *)this + 39) = *(_DWORD *)(a2 + 156);
  *((float *)this + 40) = *(float *)(a2 + 160);
  *((_BYTE *)this + 164) = *(_BYTE *)(a2 + 164);
  *((_BYTE *)this + 165) = *(_BYTE *)(a2 + 165);
  *((_DWORD *)this + 42) = *(_DWORD *)(a2 + 168);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10169350
// Name: public: void GFxParagraphFormatter::FinalizeLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxParagraphFormatter::FinalizeLine(GFxParagraphFormatter *this)
{
  double v2; // st6
  double v3; // st6
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  double v9; // st5
  double v10; // st5
  double v11; // st5
  double v12; // st7
  double v13; // st7
  unsigned int v14; // ebx
  unsigned int v15; // ecx
  int v16; // eax
  float v17; // edx
  bool v18; // zf
  int inserted; // eax
  _DWORD *v20; // edi
  int v21; // eax
  int v22; // edi
  int v23; // eax
  bool v24; // dl
  __int16 v25; // ax
  int *v26; // eax
  unsigned __int8 *v27; // ecx
  unsigned __int8 *v28; // eax
  unsigned __int8 *v29; // eax
  int *v30; // eax
  int v31; // edx
  int v32; // eax
  int v33; // eax
  int v34; // edx
  double v35; // st7
  int v36; // eax
  int v37; // ebx
  __int16 v38; // ax
  int v39; // eax
  GRefCountNTSImpl *v40; // ecx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v41; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v42; // ebx
  float v43; // ebx
  int v44; // eax
  CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > v45; // eax
  int v46; // edx
  double v47; // st7
  signed int v48; // eax
  int v49; // ecx
  __int16 v50; // dx
  int v51; // eax
  signed int v52; // eax
  int v53; // ecx
  int v54; // edx
  int v55; // ebx
  int v56; // eax
  double v57; // st6
  double v58; // st6
  int v59; // eax
  int v60; // ecx
  int v61; // edi
  double v62; // st6
  double v63; // st7
  signed int v64; // eax
  int v65; // ecx
  __int16 v66; // dx
  int v67; // eax
  double v68; // st7
  double v69; // st7
  double v70; // st6
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v71; // edi
  unsigned __int8 *FormatData; // [esp-8h] [ebp-80h]
  __int128 v73; // [esp+0h] [ebp-78h] BYREF
  ITexture *const *v74; // [esp+10h] [ebp-68h]
  const MaterialNonInteractiveMode_t *v75; // [esp+14h] [ebp-64h]
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v76; // [esp+58h] [ebp-20h]
  GRefCountNTSImpl *v77; // [esp+5Ch] [ebp-1Ch]
  unsigned int v78; // [esp+68h] [ebp-10h]
  int v79; // [esp+6Ch] [ebp-Ch]
  int v80; // [esp+70h] [ebp-8h]
  float v81; // [esp+74h] [ebp-4h]

  v79 = *((int *)this + 8);
  v2 = *(float *)&v79;
  if ( *(float *)&v79 <= 0.0 )
    v3 = v2 - 0.5;
  else
    v3 = v2 + 0.5;
  v5 = *((_DWORD *)this + 4);
  v4 = (int)v3;
  v6 = (int)v3;
  if ( v5 != 0 )
  {
    if ( v4 < 0 )
    {
      *(_WORD *)(v5 + 6) |= 0x40u;
      *(_WORD *)(v5 + 2) = abs32(v4);
    }
    else
    {
      *(_WORD *)(v5 + 6) &= ~0x40u;
      *(_WORD *)(v5 + 2) = v6;
    }
  }
  if ( *((_DWORD *)this + 5) != 0 )
    *((_DWORD *)this + 17) += *((_DWORD *)this + 9);
  else
    *((_DWORD *)this + 17) += v6;
  v7 = *((_DWORD *)this + 2);
  if ( (*(_BYTE *)(v7 + 22) & 1) != 0
    && ((*(_WORD *)(v7 + 22) & 0x600) == 0x200
     || (*(_BYTE *)(v7 + 22) & 1) != 0 && (*(_WORD *)(v7 + 22) & 0x600) == 0x600) )
  {
    v8 = *((_DWORD *)this + 36);
    *((_DWORD *)this + 17) += v8;
    *((_DWORD *)this + 18) += v8;
  }
  if ( (*(_BYTE *)(v7 + 22) & 8) != 0 )
    v9 = (double)(20 * *(__int16 *)(v7 + 16));
  else
    v9 = *((float *)this + 22);
  *(float *)&v79 = v9;
  *(float *)&v80 = *((float *)this + 21) + *((float *)this + 20);
  v10 = *(float *)&v80;
  if ( *(float *)&v80 <= 0.0 )
    v11 = v10 - 0.5;
  else
    v11 = v10 + 0.5;
  v80 = (int)v11;
  v12 = *(float *)&v79;
  if ( *(float *)&v79 <= 0.0 )
    v13 = v12 - 0.5;
  else
    v13 = v12 + 0.5;
  v79 = (int)v13;
  v14 = *((_DWORD *)this + 39);
  v15 = *((int *)this + 17) < 0 ? 0 : *((_DWORD *)this + 17);
  v16 = *((_DWORD *)this + 18);
  *((_DWORD *)this + 17) = v15;
  v17 = *(float *)this;
  *((_DWORD *)this + 18) = v16 < 0 ? 0 : v16;
  v18 = (*(_BYTE *)(LODWORD(v17) + 332) & 0x30) == 0;
  v81 = *((float *)this + 41);
  if ( v18
    && *((_DWORD *)this + 19) <= 0xFFu
    && v14 <= 0xFF
    && (unsigned int)(v79 + 128) <= 0xFF
    && (unsigned int)(int)v11 <= 0xFFFF
    && v15 < 0x10000 )
  {
    inserted = GFxTextLineBuffer::Iterator::InsertNewLine(
                 this: *((CMaterialSubRect **)this + 331),
                 glyphCount: v14,
                 formatDataElementsCount: LODWORD(v81),
                 a4: 0);
  }
  else
  {
    v20 = *((_DWORD **)this + 331);
    v21 = v20[2];
    if ( v21 < 0 )
      v21 = *(_DWORD *)(*v20 + 4);
    inserted = GFxTextLineBuffer::InsertNewLine(a1: *v20, a2: v21, a3: v14, a4: LODWORD(v81), a5: 1);
    ++v20[2];
  }
  v22 = inserted;
  v23 = *(_DWORD *)(*((_DWORD *)this + 16) + 32);
  v24 = *(int *)v22 < 0;
  if ( *(int *)v22 >= 0 )
    *(_DWORD *)(v22 + 28) = v23;
  else
    *(_DWORD *)(v22 + 4) = v23;
  v25 = *(_WORD *)(*((_DWORD *)this + 16) + 36);
  if ( v24 )
    *(_WORD *)(v22 + 24) = v25;
  else
    *(_WORD *)(v22 + 36) = v25;
  v26 = *((int **)this + 3);
  v27 = (unsigned __int8 *)v26 + 30;
  if ( *v26 >= 0 )
    v27 = (unsigned __int8 *)v26 + 42;
  v28 = (unsigned __int8 *)(v22 + 30);
  if ( !v24 )
    v28 = (unsigned __int8 *)(v22 + 42);
  memcpy(dst: v28, src: v27, count: 8 * v14);
  FormatData = (unsigned __int8 *)GFxTextLineBuffer::Line::GetFormatData(this: *((CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > **)this
                                                                               + 3));
  v29 = (unsigned __int8 *)GFxTextLineBuffer::Line::GetFormatData(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v22);
  memcpy(dst: v29, src: FormatData, count: 4 * LODWORD(v81));
  v30 = *((int **)this + 3);
  v31 = *v30;
  v32 = v30[2];
  if ( v31 < 0 )
  {
    v32 &= 0xFFFFFFu;
    if ( v32 == 0xFFFFFF )
      v32 = -1;
  }
  if ( *(int *)v22 >= 0 )
    *(_DWORD *)(v22 + 8) = v32;
  else
    *(_DWORD *)(v22 + 8) ^= (v32 ^ *(_DWORD *)(v22 + 8)) & 0xFFFFFF;
  v33 = *((_DWORD *)this + 19);
  if ( *(int *)v22 >= 0 )
    *(_DWORD *)(v22 + 32) = v33;
  else
    *(_BYTE *)(v22 + 11) = v33;
  v34 = *(_DWORD *)v22 >> 31;
  v81 = *((float *)this + 20);
  v35 = v81;
  v78 = (int)v81;
  if ( (v34 & 1) != 0 )
    *(_WORD *)(v22 + 26) = (int)v35;
  else
    *(_WORD *)(v22 + 38) = (int)v35;
  if ( *((_BYTE *)this + 181) == 0 && (*(_BYTE *)(*(_DWORD *)this + 334) & 8) != 0 )
  {
    v78 = *((_DWORD *)this + 42) - *((_DWORD *)this + 43);
    if ( *(float *)&v78 != 0.0 )
    {
      v36 = *((_DWORD *)this + 2);
      if ( (*(_BYTE *)(v36 + 22) & 1) != 0 && (*(_WORD *)(v36 + 22) & 0x600) == 0x400 )
      {
        v37 = (int)(*((float *)this + 182) - 30.0)
            - *((_DWORD *)this + 36)
            - *((_DWORD *)this + 35)
            - *((_DWORD *)this + 34)
            - *((_DWORD *)this + 18);
        if ( v37 > 0 )
        {
          v78 = v37 / v78;
          GFxTextLineBuffer::Line::Begin(
            this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v22,
            a2: (CMatRenderContextBase *)((char *)&v73 + 12),
            a3: v73,
            a4: v74,
            a5: v75);
          while ( HIDWORD(v73) != 0 && HIDWORD(v73) < (unsigned int)v74 )
          {
            v38 = *(_WORD *)(HIDWORD(v73) + 6);
            if ( (v38 & 2) != 0 )
            {
              v18 = (v38 & 0x40) == 0;
              v39 = *(unsigned __int16 *)(HIDWORD(v73) + 2);
              if ( !v18 )
                v39 = -v39;
              GFxTextLineBuffer::GlyphEntry::SetAdvance(
                this: (CIndexBufferBase *)HIDWORD(v73),
                v: (const char *)(v78 + v39));
            }
            GFxTextLineBuffer::GlyphIterator::operator++(result: (const VJobInstance *)v73);
          }
          v40 = v77;
          *((_DWORD *)this + 17) += v37;
          if ( v40 != nullptr )
            GRefCountNTSImpl::Release(this: v40);
          v41 = v76;
          if ( v76 != nullptr )
          {
            --LODWORD(v76->m_pfnProxied);
            v42 = v41;
            if ( LODWORD(v41->m_pfnProxied) == 0 )
            {
              GFxFontHandle::~GFxFontHandle(this: v41);
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v42);
            }
          }
        }
      }
    }
  }
  LODWORD(v43) = *((_DWORD *)this + 34) + *((_DWORD *)this + 35);
  v44 = *((_DWORD *)this + 589);
  *(float *)(v22 + 12) = v43;
  *(_DWORD *)(v22 + 16) = v44;
  v45.m_pAllocator = *(CMemoryStack **)v22;
  v46 = *(_DWORD *)v22 >> 31;
  v81 = v43;
  if ( (v46 & 1) != 0 )
    *(_BYTE *)(v22 + 29) = v79;
  else
    *(_WORD *)(v22 + 40) = v79;
  if ( ((*(unsigned __int16 *)(*((_DWORD *)this + 2) + 22) >> 9) & 3) == 1 )
  {
    v64 = (unsigned int)v45.m_pAllocator & 0xCFFFFFFF | 0x10000000;
    *(_DWORD *)v22 = v64;
    v65 = *((_DWORD *)this + 18);
    if ( v64 >= 0 )
    {
      v67 = v80;
      *(_DWORD *)(v22 + 20) = v65;
      *(_DWORD *)(v22 + 24) = v67;
    }
    else
    {
      v66 = v80;
      *(_WORD *)(v22 + 20) = v65;
      *(_WORD *)(v22 + 22) = v66;
    }
    v78 = *((unsigned int *)this + 182);
    v68 = *(float *)&v78;
    if ( *(float *)&v78 <= 0.0 )
      v69 = v68 - 0.5;
    else
      v69 = v68 + 0.5;
    v70 = v69;
    v47 = 0.5;
    *(_DWORD *)(v22 + 12) = (int)v70 - *((_DWORD *)this + 18) < 0 ? 0 : (int)v70 - *((_DWORD *)this + 18);
    if ( (*(_BYTE *)(*(_DWORD *)this + 334) & 1) != 0 || (*(_BYTE *)(*(_DWORD *)this + 332) & 0x30) != 0 )
      *((_BYTE *)this + 2380) = 1;
  }
  else if ( ((*(unsigned __int16 *)(*((_DWORD *)this + 2) + 22) >> 9) & 3) == 3 )
  {
    v52 = (unsigned int)v45.m_pAllocator & 0xCFFFFFFF | 0x20000000;
    *(_DWORD *)v22 = v52;
    v53 = *((_DWORD *)this + 18);
    if ( v52 >= 0 )
    {
      v54 = v80;
      *(_DWORD *)(v22 + 20) = v53;
      *(_DWORD *)(v22 + 24) = v54;
    }
    else
    {
      *(_WORD *)(v22 + 20) = v53;
      *(_WORD *)(v22 + 22) = v80;
    }
    v55 = *((_DWORD *)this + 35);
    v56 = *((_DWORD *)this + 18);
    *(float *)&v78 = *((float *)this + 182) - (double)v55;
    v47 = 0.5;
    *(float *)&v78 = *(float *)&v78 * 0.5 - (double)(v56 / 2);
    v57 = *(float *)&v78;
    if ( *(float *)&v78 <= 0.0 )
      v58 = v57 - 0.5;
    else
      v58 = v57 + 0.5;
    *(_DWORD *)(v22 + 12) = v55 + (int)v58 < 0 ? 0 : v55 + (int)v58;
    if ( (*(_BYTE *)(*(_DWORD *)this + 334) & 1) != 0 || (*(_BYTE *)(*(_DWORD *)this + 332) & 0x30) != 0 )
      *((_BYTE *)this + 2380) = 1;
    v43 = v81;
  }
  else
  {
    v47 = 0.5;
    v48 = (unsigned int)v45.m_pAllocator & 0xCFFFFFFF;
    *(_DWORD *)v22 = v48;
    v49 = *((_DWORD *)this + 17);
    if ( v48 >= 0 )
    {
      v51 = v80;
      *(_DWORD *)(v22 + 20) = v49;
      *(_DWORD *)(v22 + 24) = v51;
    }
    else
    {
      v50 = v80;
      *(_WORD *)(v22 + 20) = v49;
      *(_WORD *)(v22 + 22) = v50;
    }
  }
  v59 = LODWORD(v43) + *((_DWORD *)this + 17);
  if ( v59 < *((_DWORD *)this + 592) )
    v59 = *((_DWORD *)this + 592);
  v60 = v79;
  v61 = *((_DWORD *)this + 589);
  *((_DWORD *)this + 592) = v59;
  v78 = v80 + v60;
  v62 = (double)(v80 + v60);
  *((_DWORD *)this + 593) = v80 + v61 - *((_DWORD *)this + 590);
  if ( v62 <= 0.0 )
    v63 = v62 - v47;
  else
    v63 = v47 + v62;
  *((_DWORD *)this + 589) = v61 + (int)v63;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 10) = 0;
  v71 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
        + 5);
  if ( v71 != nullptr )
  {
    v18 = LODWORD(v71->m_pfnProxied)-- == 1;
    if ( v18 )
    {
      GFxFontHandle::~GFxFontHandle(this: v71);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v71);
    }
  }
  *((_DWORD *)this + 5) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101699B0
// Name: protected: unsigned int GFxTextDocView::GetCursorPosInLineByOffset(unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextDocView::GetCursorPosInLineByOffset(
        GRefCountBase<GFxAmpMemSegment,2> *this@<ecx>,
        const VJobInstance *a2@<edi>,
        unsigned int lineIndex,
        float xoffInLine)
{
  int v4; // edx
  double v5; // st7
  bool v6; // al
  double v7; // st6
  int v8; // edi
  unsigned __int16 *v9; // esi
  int v10; // edi
  int v11; // esi
  unsigned int v12; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v13; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v14; // esi
  const VJobInstance *v16; // [esp-Ch] [ebp-70h]
  unsigned __int16 *v17; // [esp+0h] [ebp-64h]
  unsigned int v18; // [esp+4h] [ebp-60h]
  CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> v19; // [esp+Ch] [ebp-58h] BYREF
  char v20; // [esp+3Ch] [ebp-28h]
  int v21; // [esp+40h] [ebp-24h]
  int v22; // [esp+44h] [ebp-20h]
  int v23; // [esp+48h] [ebp-1Ch]
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v24; // [esp+4Ch] [ebp-18h]
  GRefCountNTSImpl *v25; // [esp+50h] [ebp-14h]
  int v26; // [esp+54h] [ebp-10h]
  unsigned int p; // [esp+58h] [ebp-Ch]
  int v28; // [esp+5Ch] [ebp-8h]
  int v29; // [esp+60h] [ebp-4h]
  int xoffset; // [esp+6Ch] [ebp+8h]
  float xoffInLinea; // [esp+70h] [ebp+Ch]

  if ( lineIndex < *((_DWORD *)this + 10) )
  {
    v4 = *(_DWORD *)(*((_DWORD *)this + 9) + 4 * lineIndex);
    v5 = xoffInLine - (double)*(int *)(v4 + 12);
    v6 = *(int *)v4 < 0;
    v7 = (double)*((unsigned int *)this + 19);
    v29 = v4;
    xoffset = 0;
    if ( v6 )
      v8 = *(unsigned __int8 *)(v4 + 28);
    else
      v8 = *(_DWORD *)(v4 + 4);
    v9 = (unsigned __int16 *)(v4 + 30);
    if ( !v6 )
      v9 = (unsigned __int16 *)(v4 + 42);
    v19.m_iRefs = -1;
    v19.m_Proxy.m_pfnProxied = 0xFFFFFFFF00000000uLL;
    memset(&v19.m_Proxy.m_pObject, 0, 16);
    v20 = 0;
    v19.CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
    v19.m_nUserID = 0;
    v21 = 0;
    v22 = 0;
    v23 = 0;
    v24 = nullptr;
    v25 = nullptr;
    v26 = 0;
    p = 0;
    v17 = v9;
    v18 = (unsigned int)&v9[4 * v8];
    GFxTextLineBuffer::Line::GetFormatData(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v4);
    GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: a2);
    v10 = 0;
    while ( v17 != nullptr && (unsigned int)v17 < v18 )
    {
      v11 = v17[1];
      if ( (v17[3] & 0x40) != 0 )
        v11 = -v11;
      v28 = v11 + xoffset;
      xoffInLinea = v5 + v7;
      if ( xoffInLinea < (double)(unsigned int)(v11 + xoffset) )
        break;
      xoffset += v11;
      if ( (v17[3] & 0x100) == 0 )
        v10 += v17[2] >> 12;
      v12 = p;
      if ( p == 0 )
      {
        v12 = v17[2] >> 12;
        p = v12;
      }
      v17 += 4;
      if ( (v17[2] & 0xF000) != 0
        && v12 != 0
        && !GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)&v19) )
      {
        GFxTextHighlighterPosIterator::operator+=(this: &v19, p);
        p = 0;
      }
      GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: v16);
    }
    if ( v25 != nullptr )
      GRefCountNTSImpl::Release(this: v25);
    v13 = v24;
    if ( v24 != nullptr )
    {
      --LODWORD(v24->m_pfnProxied);
      v14 = v13;
      if ( LODWORD(v13->m_pfnProxied) == 0 )
      {
        GFxFontHandle::~GFxFontHandle(this: v13);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169C50
// Name: public: void GFxTextDocView::ImageSubstitutor::AddImageDesc(struct GFxTextDocView::ImageSubstitutor::Element const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::ImageSubstitutor::AddImageDesc(
        GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *this,
        GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *elem)
{
  GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *v2; // edi
  int pTable_low; // ebx
  int pObject; // esi
  int v5; // edx
  unsigned int v6; // edi
  char *v7; // eax
  int v8; // esi
  int v9; // ecx
  int v10; // edi
  int v11; // ecx
  int v13; // [esp+14h] [ebp-1Ch]
  unsigned int First; // [esp+18h] [ebp-18h]
  unsigned int v15; // [esp+1Ch] [ebp-14h]
  unsigned int v16; // [esp+20h] [ebp-10h]
  int v17; // [esp+24h] [ebp-Ch]
  int v18; // [esp+28h] [ebp-8h]
  int v19; // [esp+2Ch] [ebp-4h]

  v2 = (GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *)this;
  if ( GFxTextDocView::ImageSubstitutor::FindImageDesc(
         this,
         result: elem,
         a3: LOBYTE(elem[11].Hash.pTable),
         ptextLen: nullptr) == nullptr )
  {
    pTable_low = LOBYTE(elem[11].Hash.pTable);
    pObject = (int)v2->Second.pObject;
    v16 = 0;
    v18 = pObject;
    if ( pObject > 0 )
    {
      First = v2->First;
      do
      {
        v5 = pObject >> 1;
        v6 = (pObject >> 1) + v16;
        v7 = (char *)(First + 48 * v6);
        v15 = v6;
        v19 = (unsigned __int8)v7[44];
        v17 = pTable_low;
        if ( pTable_low != 0 )
        {
          v13 = (unsigned __int8)v7[44];
          v8 = (char *)elem - v7;
          do
          {
            v9 = *(unsigned __int16 *)&v7[v8];
            v10 = *(unsigned __int16 *)v7;
            v7 += 2;
            if ( --v17 == 0 || v9 == 0 )
              break;
            if ( v9 != v10 )
              goto LABEL_14;
            --v19;
          }
          while ( v19 != 0 );
          if ( v9 == v10 && v19 != 0 && v17 != 0 )
          {
            pTable_low = LOBYTE(elem[11].Hash.pTable);
            pObject = v18;
            v6 = v15;
            v11 = pTable_low - v13;
            goto LABEL_16;
          }
LABEL_14:
          pTable_low = LOBYTE(elem[11].Hash.pTable);
          pObject = v18;
          v11 = v9 - v10;
          v6 = v15;
        }
        else
        {
          v11 = -(unsigned __int8)v7[44];
        }
LABEL_16:
        if ( v11 <= 0 )
        {
          pObject = v5;
          v18 = v5;
        }
        else
        {
          pObject += -1 - v5;
          v16 = v6 + 1;
          v18 = pObject;
        }
      }
      while ( pObject > 0 );
      v2 = (GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *)this;
    }
    GArrayBase<GArrayData<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>>::InsertAt(
      result: v2,
      a2: v16,
      a3: (int)elem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169D50
// Name: protected: class GFxTextHighlighter __near * GFxTextDocView::CreateHighlighterManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::CreateHighlighterManager(
        GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> *this)
{
  GFxTextHighlighter *v2; // eax
  GFxTextHighlighter *v3; // esi
  int v4; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 5) == 0 )
  {
    v4 = 324;
    v2 = (GFxTextHighlighter *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: this,
                                 a3: 176,
                                 a4: &v4);
    v3 = v2;
    if ( v2 != nullptr )
    {
      GFxTextHighlighter::GFxTextHighlighter(this: v2);
      GFxDrawingContext::GFxDrawingContext(this: (IClientTools *)v3 + 7);
      *((float *)v3 + 41) = -1.0;
      *((float *)v3 + 42) = -1.0;
      *((_WORD *)v3 + 86) = 0;
      *((_DWORD *)this + 5) = v3;
    }
    else
    {
      *((_DWORD *)this + 5) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169DD0
// Name: protected: struct GFxTextHighlightDesc __near * GFxTextDocView::GetSelectionHighlighterDesc(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxTextHighlightDesc *__thiscall GFxTextDocView::GetSelectionHighlighterDesc(GFxTextDocView *this)
{
  GFxTextHighlighter *v2; // eax
  GFxTextHighlighter *v3; // esi
  int v5; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 5) == 0 )
  {
    v5 = 324;
    v2 = (GFxTextHighlighter *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: this,
                                 a3: 176,
                                 a4: &v5);
    v3 = v2;
    if ( v2 != nullptr )
    {
      GFxTextHighlighter::GFxTextHighlighter(this: v2);
      GFxDrawingContext::GFxDrawingContext(this: (IClientTools *)v3 + 7);
      *((float *)v3 + 41) = -1.0;
      *((_WORD *)v3 + 86) = 0;
      *((float *)v3 + 42) = -1.0;
      *((_DWORD *)this + 5) = v3;
      return GFxTextDocView::GetSelectionHighlighterDesc(this);
    }
    *((_DWORD *)this + 5) = 0;
  }
  return GFxTextDocView::GetSelectionHighlighterDesc(this);
}

//------------------------------------------------------------------------------
// Address: 0x10169E50
// Name: protected: void GFxTextDocView::SetSelection(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::SetSelection(GFxTextDocView *this, unsigned int startPos, unsigned int endPos)
{
  unsigned int v3; // ebx
  bool v5; // zf
  unsigned int v6; // edi
  GFxTextHighlighter *v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  struct GFxTextHighlightDesc *SelectionHighlighterDesc; // eax
  unsigned int v11; // edi
  unsigned int startPosa; // [esp+14h] [ebp+8h]

  v3 = startPos;
  v5 = *((_DWORD *)this + 5) == 0;
  v6 = endPos;
  *((_DWORD *)this + 7) = startPos;
  *((_DWORD *)this + 8) = v6;
  if ( v5 )
  {
    endPos = 324;
    v7 = (GFxTextHighlighter *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: this,
                                 a3: 176,
                                 a4: &endPos);
    startPosa = (unsigned int)v7;
    if ( v7 != nullptr )
    {
      GFxTextHighlighter::GFxTextHighlighter(this: v7);
      GFxDrawingContext::GFxDrawingContext(this: (IClientTools *)(startPosa + 28));
      v8 = startPosa;
      *(float *)(startPosa + 164) = -1.0;
      *(float *)(startPosa + 168) = -1.0;
      *(_WORD *)(startPosa + 172) = 0;
    }
    else
    {
      v8 = 0;
    }
    *((_DWORD *)this + 5) = v8;
  }
  if ( v6 < v3 )
  {
    v9 = v6;
    v6 = v3;
    v3 = v9;
  }
  SelectionHighlighterDesc = GFxTextDocView::GetSelectionHighlighterDesc(this);
  v11 = v6 - v3;
  if ( *(_DWORD *)SelectionHighlighterDesc != v3 || *((_DWORD *)SelectionHighlighterDesc + 1) != v11 )
  {
    *(_DWORD *)SelectionHighlighterDesc = v3;
    *((_DWORD *)SelectionHighlighterDesc + 1) = v11;
    *(_WORD *)(*((_DWORD *)this + 5) + 24) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169F00
// Name: protected: void GFxTextDocView::SetSelectionBackgroundColor(unsigned long)
// Source: json
//------------------------------------------------------------------------------
struct GFxTextHighlightDesc *__thiscall GFxTextDocView::SetSelectionBackgroundColor(
        struct GFxTextHighlightDesc **this,
        unsigned int color)
{
  struct GFxTextHighlightDesc *result; // eax
  int v4; // [esp+8h] [ebp-4h]

  result = GFxTextDocView::GetSelectionHighlighterDesc((GFxTextDocView *)this);
  if ( (*((_BYTE *)result + 36) & 8) != 0 )
    v4 = *((_DWORD *)result + 6);
  else
    v4 = 0;
  if ( v4 != color )
  {
    *((_BYTE *)result + 36) |= 8u;
    *((_DWORD *)result + 6) = color;
    result = *(this + 5);
    *((_BYTE *)result + 24) = 0;
    *((_BYTE *)result + 25) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10169F50
// Name: protected: void GFxTextDocView::SetSelectionTextColor(unsigned long)
// Source: json
//------------------------------------------------------------------------------
struct GFxTextHighlightDesc *__thiscall GFxTextDocView::SetSelectionTextColor(
        struct GFxTextHighlightDesc **this,
        unsigned int color)
{
  struct GFxTextHighlightDesc *result; // eax
  int v4; // [esp+8h] [ebp-4h]

  result = GFxTextDocView::GetSelectionHighlighterDesc((GFxTextDocView *)this);
  if ( (*((_BYTE *)result + 36) & 0x10) != 0 )
    v4 = *((_DWORD *)result + 7);
  else
    v4 = 0;
  if ( v4 != color )
  {
    *((_BYTE *)result + 36) |= 0x10u;
    *((_DWORD *)result + 7) = color;
    result = *(this + 5);
    *((_BYTE *)result + 24) = 0;
    *((_BYTE *)result + 25) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10169FA0
// Name: public: void GFxTextDocView::ImageSubstitutor::RemoveImageDesc(struct GFxTextImageDesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextDocView::ImageSubstitutor::RemoveImageDesc(
        GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *this@<ecx>,
        void *pimgDesc,
        int n)
{
  unsigned int v4; // ebx
  int v5; // edi
  GRefCountNTSImpl *v6; // eax
  unsigned int na; // [esp+8h] [ebp-4h]

  v4 = 0;
  na = *((_DWORD *)this + 1);
  if ( na != 0 )
  {
    v5 = 0;
    do
    {
      if ( *(void **)((char *)this->Hash.pTable + v5 + 40) == pimgDesc )
      {
        if ( *((_DWORD *)this + 1) == 1 )
        {
          GArrayDataBase<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
            (int)this,
            result: (GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *)this,
            newSize: 0);
        }
        else
        {
          v6 = *(GRefCountNTSImpl **)((char *)this->Hash.pTable + v5 + 40);
          if ( v6 != nullptr )
            GRefCountNTSImpl::Release(this: v6);
          memmove(
            dst: (unsigned __int8 *)this->Hash.pTable + v5,
            src: (unsigned __int8 *)this->Hash.pTable + v5 + 48,
            count: 16 * (3 * (*((_DWORD *)this + 1) - v4) - 3));
          --*((_DWORD *)this + 1);
        }
      }
      else
      {
        ++v4;
        v5 += 48;
      }
    }
    while ( v4 < na );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016A020
// Name: public: unsigned int GFxTextDocView::EditCommand(enum GFxTextDocView::CommandType,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextDocView::EditCommand(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this@<ecx>,
        const char *a2@<ebx>,
        unsigned int cmdId,
        ButtonCode_t command)
{
  const char *v4; // edi
  ButtonCode_t v6; // ebx
  unsigned int v7; // edi
  unsigned int Length; // eax
  unsigned int v9; // ecx
  ButtonCode_t v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  ButtonCode_t v13; // edx
  const char *v14; // ebx
  unsigned int v15; // eax
  ButtonCode_t v16; // edi
  const char *v17; // ebx
  bool v18; // zf
  unsigned int v19; // eax
  unsigned int v20; // ecx
  const char *v21; // eax
  const char *inserted; // edi
  const char *v23; // ebx
  unsigned int v24; // eax
  unsigned int v25; // edi
  SFTextObjectImpl *Capacity; // ecx
  const struct GFxTextParagraphFormat *v27; // ebx
  __int16 v28; // ax
  SFTextObjectImpl *v29; // ecx
  CMaterial *v30; // eax
  unsigned int v31; // edi
  unsigned int v32; // ebx
  unsigned int v33; // [esp-Ch] [ebp-38h]
  CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> newFmt; // [esp+8h] [ebp-24h] BYREF
  GFxValue index; // [esp+20h] [ebp-Ch] BYREF

  v4 = nullptr;
  switch ( cmdId )
  {
    case 0u:
      if ( *((_DWORD *)this + 68) == 0
        || GFxStyledText::GetLength(this: (GFxStyledText *)this->Data.Policy.Capacity) + 1 <= *((_DWORD *)this + 68) )
      {
        GFxStyledText::InsertString(
          this: (CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *)this->Data.Policy.Capacity,
          a2,
          pstr: (GFxValue *)(command + 4),
          a4: *(_DWORD *)command,
          length: 1u,
          a6: 1);
      }
      return;
    case 1u:
      v6 = command;
      v7 = *(_DWORD *)(command + 8);
      Length = GFxStyledText::GetLength(this: (GFxStyledText *)this->Data.Policy.Capacity);
      v9 = *((_DWORD *)this + 68);
      if ( v9 != 0 && Length + v7 > v9 )
        v7 = v9 - Length;
      GFxStyledText::InsertString(
        this: (CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *)this->Data.Policy.Capacity,
        a2: (const char *)v6,
        pstr: *(GFxValue **)(v6 + 4),
        a4: *(_DWORD *)v6,
        length: v7,
        a6: 0);
      return;
    case 2u:
      v10 = command;
      cmdId = -1;
      if ( *((_DWORD *)this + 68) != 0 )
      {
        v4 = (const char *)GFxStyledText::GetLength(this: (GFxStyledText *)this->Data.Policy.Capacity);
        v11 = GFxStyledText::GetLength(this: *(GFxStyledText **)(v10 + 4));
        v12 = *((_DWORD *)this + 68);
        if ( (unsigned int)&v4[v11] > v12 )
          cmdId = v12 - (_DWORD)v4;
      }
      GFxStyledText::InsertStyledText(
        this: (SFTextObjectImpl *)this->Data.Policy.Capacity,
        a2: v4,
        a3: *(GFxStyledText **)(v10 + 4),
        a4: *(const char **)v10,
        a5: cmdId);
      return;
    case 3u:
      GFxTextDocView::RemoveText(
        (SFTextObjectImpl **)this,
        startPos: *(_DWORD *)command,
        endPos: *(_DWORD *)command + 1);
      return;
    case 4u:
      v31 = *(_DWORD *)(command + 4);
      if ( *(_DWORD *)command <= v31 )
      {
        v32 = *(_DWORD *)command;
      }
      else
      {
        v32 = *(_DWORD *)(command + 4);
        v31 = *(_DWORD *)command;
      }
      GFxTextDocView::RemoveText((SFTextObjectImpl **)this, startPos: v32, endPos: v31);
      return;
    case 5u:
      v13 = command;
      if ( *(_DWORD *)command <= *(_DWORD *)(command + 4) )
      {
        v14 = *(const char **)command;
        cmdId = *(_DWORD *)(command + 4);
      }
      else
      {
        v14 = *(const char **)(command + 4);
        cmdId = *(_DWORD *)command;
      }
      if ( *((_DWORD *)this + 68) != 0 )
      {
        v15 = GFxStyledText::GetLength(this: (GFxStyledText *)this->Data.Policy.Capacity);
        if ( (unsigned int)&v14[v15 - cmdId + 1] > *((_DWORD *)this + 68) )
          return;
        v13 = command;
      }
      GFxStyledText::InsertString(
        this: (CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *)this->Data.Policy.Capacity,
        a2: v14,
        pstr: (GFxValue *)(v13 + 8),
        a4: (unsigned int)v14,
        length: 1u,
        a6: 0);
      GFxTextDocView::RemoveText((SFTextObjectImpl **)this, startPos: (unsigned int)(v14 + 1), endPos: cmdId + 1);
      return;
    case 6u:
      v16 = command;
      if ( *(_DWORD *)command <= *(_DWORD *)(command + 4) )
      {
        v17 = *(const char **)command;
        command = *(_DWORD *)(command + 4);
      }
      else
      {
        v17 = *(const char **)(command + 4);
        command = *(_DWORD *)command;
      }
      v18 = *((_DWORD *)this + 68) == 0;
      cmdId = *(_DWORD *)(v16 + 12);
      if ( !v18 )
      {
        v19 = GFxStyledText::GetLength(this: (GFxStyledText *)this->Data.Policy.Capacity);
        v20 = *((_DWORD *)this + 68);
        v21 = &v17[v19 - command];
        if ( (unsigned int)&v21[*(_DWORD *)(v16 + 12)] > v20 )
          cmdId = v20 - (_DWORD)v21;
      }
      inserted = GFxStyledText::InsertString(
                   this: (CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *)this->Data.Policy.Capacity,
                   a2: v17,
                   pstr: *(GFxValue **)(v16 + 8),
                   a4: (unsigned int)v17,
                   length: cmdId,
                   a6: 0);
      GFxTextDocView::RemoveText(
        (SFTextObjectImpl **)this,
        startPos: (unsigned int)&v17[(_DWORD)inserted],
        endPos: (unsigned int)&inserted[command]);
      return;
    case 7u:
      if ( *(_DWORD *)command <= *(_DWORD *)(command + 4) )
      {
        v23 = *(const char **)command;
        cmdId = *(_DWORD *)(command + 4);
      }
      else
      {
        v23 = *(const char **)(command + 4);
        cmdId = *(_DWORD *)command;
      }
      index.Value.pString = (const char *)-1;
      if ( *((_DWORD *)this + 68) != 0 )
      {
        v24 = GFxStyledText::GetLength(this: (GFxStyledText *)this->Data.Policy.Capacity);
        index.Type = *((_DWORD *)this + 68);
        v4 = &v23[v24 - cmdId];
        if ( (unsigned int)&v4[GFxStyledText::GetLength(this: *(GFxStyledText **)(command + 8))] > index.Type )
          index.Value.pString = (const char *)(*((_DWORD *)this + 68) - (_DWORD)v4);
      }
      v25 = GFxStyledText::InsertStyledText(
              this: (SFTextObjectImpl *)this->Data.Policy.Capacity,
              a2: v4,
              a3: *(GFxStyledText **)(command + 8),
              a4: v23,
              a5: (unsigned int)index.Value.pString);
      GFxTextDocView::RemoveText((SFTextObjectImpl **)this, startPos: (unsigned int)&v23[v25], endPos: v25 + cmdId);
      return;
    case 8u:
      v33 = *(_DWORD *)command;
      Capacity = (SFTextObjectImpl *)this->Data.Policy.Capacity;
      cmdId = 0;
      GFxStyledText::GetParagraphByIndex(this: Capacity, &index, indexa: v33, pindexInParagraph: &cmdId);
      if ( index.pObjectInterface == nullptr )
        goto LABEL_46;
      if ( index.Type < VT_Undefined )
        goto LABEL_46;
      if ( index.Type >= (int)index.pObjectInterface[1].pMovieRoot )
        goto LABEL_46;
      if ( cmdId != 0 )
        goto LABEL_46;
      v27 = *(const struct GFxTextParagraphFormat **)(*((_DWORD *)index.pObjectInterface->pMovieRoot + index.Type) + 12);
      index.Value.pString = *((const char **)index.pObjectInterface->pMovieRoot + index.Type);
      if ( v27 == nullptr )
        goto LABEL_46;
      if ( GFxTextParagraphFormat::IsBullet(this: v27) )
      {
        GFxTextParagraphFormat::GFxTextParagraphFormat(this: (GFxTextParagraphFormat *)&newFmt, a2: v27);
        v28 = *((_WORD *)&newFmt.m_pObject + 3) & 0x7F7F | 0x80;
LABEL_41:
        v29 = (SFTextObjectImpl *)this->Data.Policy.Capacity;
        *((_WORD *)&newFmt.m_pObject + 3) = v28;
        GFxStyledText::GetAllocator(this: v29);
        GFxTextParagraph::SetFormat(
          this: (GFxFontMap::MapEntry *)index.Value.pString,
          pallocator: v30,
          pallocator_4: (GRefCountNTSImpl *)&newFmt);
        (*((void (__thiscall **)(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *, int))this->Data.Data
         + 1))(
          a1: this,
          a2: 2);
        LODWORD(newFmt.m_pfnProxied) = &GFxTextParagraphFormat::`vftable';
        GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&newFmt);
        GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&newFmt);
        return;
      }
      if ( *((_WORD *)v27 + 7) != 0 || *((_WORD *)v27 + 6) != 0 )
      {
        GFxTextParagraphFormat::GFxTextParagraphFormat(this: (GFxTextParagraphFormat *)&newFmt, a2: v27);
        HIDWORD(newFmt.m_pfnProxied) = 0;
        v28 = *((_WORD *)&newFmt.m_pObject + 3) | 6;
        goto LABEL_41;
      }
LABEL_46:
      if ( *(_DWORD *)command != 0 )
        GFxTextDocView::RemoveText(
          (SFTextObjectImpl **)this,
          startPos: *(_DWORD *)command - 1,
          endPos: *(_DWORD *)command);
      return;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016A410
// Name: public: void GFxParagraphFormatter::InitCustomWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxParagraphFormatter::InitCustomWordWrapping(GFxParagraphFormatter *this)
{
  int v2; // eax
  bool v3; // al
  unsigned int Length; // eax
  GFxResourceId *v5; // ecx
  unsigned int Id; // ebx
  unsigned int v7; // edi
  GFxResourceId *v8; // ecx
  unsigned __int8 *v9; // ebx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // edi
  unsigned int v15; // eax
  int v16; // [esp+4h] [ebp-14h] BYREF
  unsigned __int8 *v17; // [esp+8h] [ebp-10h]
  int v18; // [esp+Ch] [ebp-Ch]
  unsigned int v19; // [esp+10h] [ebp-8h]
  char v20; // [esp+17h] [ebp-1h]

  v2 = *(_DWORD *)(*(_DWORD *)this + 16);
  v3 = v2 != 0 && (*(_BYTE *)(v2 + 8) & 1) != 0;
  *((_BYTE *)this + 756) = v3;
  *((_DWORD *)this + 318) = 0;
  if ( v3 )
  {
    Length = GFxTextParagraph::GetLength(this: *((GFxResourceId **)this + 1));
    v5 = *((GFxResourceId **)this + 1);
    Id = v5[7].Id;
    v7 = Length;
    v19 = Length;
    if ( *((_DWORD *)this + 12) < Id || *((_DWORD *)this + 12) > Id + GFxTextParagraph::GetLength(this: v5) )
    {
      v20 = 0;
    }
    else
    {
      v8 = *((GFxResourceId **)this + 1);
      v20 = 1;
      v19 = *((_DWORD *)this + 13) + GFxTextParagraph::GetLength(this: v8);
      v7 = v19;
    }
    if ( v7 >= 0x100 )
    {
      GFxStyledText::GetAllocator(this: *(SFTextObjectImpl **)(*(_DWORD *)this + 8));
      v11 = *(_DWORD *)(v10 + 28);
      v16 = 324;
      v9 = (unsigned __int8 *)(*(int (__thiscall **)(int, unsigned int, int *))(*(_DWORD *)v11 + 40))(
                                a1: v11,
                                a2: 2 * v7 + 2,
                                a3: &v16);
    }
    else
    {
      v9 = (unsigned __int8 *)this + 758;
    }
    v12 = *((_DWORD *)this + 1);
    v13 = *(unsigned __int8 **)v12;
    v17 = *(unsigned __int8 **)v12;
    if ( v20 != 0 && *((_DWORD *)this + 13) != 0 )
    {
      v14 = *((_DWORD *)this + 12) - *(_DWORD *)(v12 + 28);
      v18 = 2 * v14;
      memcpy(dst: v9, src: v13, count: 2 * v14);
      memcpy(dst: &v9[v18], src: *(unsigned __int8 **)(*((_DWORD *)this + 11) + 20), count: 2 * *((_DWORD *)this + 13));
      v15 = GFxTextParagraph::GetLength(this: *((GFxResourceId **)this + 1));
      memcpy(dst: &v9[2 * v14 + 2 * *((_DWORD *)this + 13)], src: &v17[v18], count: 2 * (v15 - v14));
      v7 = v19;
    }
    else
    {
      memcpy(dst: v9, src: v13, count: 2 * v7);
    }
    *(_WORD *)&v9[2 * v7] = 0;
    *((_DWORD *)this + 319) = v7;
    *((_DWORD *)this + 318) = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016A560
// Name: public: bool GFxParagraphFormatter::HandleCustomWordWrap(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall GFxParagraphFormatter::HandleCustomWordWrap@<al>(
        GFxParagraphFormatter *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>)
{
  int v4; // ecx
  int v6; // eax
  int v7; // eax
  double v8; // st7
  int v9; // edi
  float v10; // ebx
  int v11; // ecx
  int v12; // edx
  int *v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  unsigned int v20; // edx
  int v21; // edi
  unsigned int v22; // ecx
  unsigned __int16 *v23; // eax
  int v24; // ebx
  int v25; // ebx
  int v26; // ebx
  int v27; // ebx
  unsigned __int16 *v28; // eax
  int v29; // ebx
  int v30; // eax
  unsigned __int16 *v31; // edi
  double v32; // st6
  float *v33; // ecx
  float v34; // edx
  double v35; // st6
  unsigned int v36; // edx
  int v37; // eax
  bool v38; // zf
  float v39; // edi
  unsigned int v40; // eax
  int v41; // ecx
  int v42; // eax
  int v43; // eax
  float v44; // ecx
  int v45; // ebx
  CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *v46; // edi
  int (__thiscall *v47)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *); // edx
  GStringDH *v48; // eax
  GStringDH *v49; // edi
  GRefCountNTSImpl *v50; // ecx
  GFxLineCursor *v51; // eax
  void *v52; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v53; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v54; // edi
  GFxLineCursor *v55; // eax
  int v56; // ebx
  double v57; // st7
  double v58; // st7
  int v59; // eax
  int v60; // ecx
  int v61; // ecx
  int v62; // eax
  int v63; // edi
  int v64; // eax
  int v65; // ecx
  double v66; // st7
  double v67; // st7
  double v68; // st7
  int v69; // ecx
  void (__thiscall *v70)(int); // eax
  float v71; // eax
  int v72; // ecx
  unsigned int v73; // eax
  __int128 v74; // [esp+8h] [ebp-520h] BYREF
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v75; // [esp+18h] [ebp-510h]
  GRefCountNTSImpl *v76; // [esp+30h] [ebp-4F8h]
  IShaderAPI *v77; // [esp+60h] [ebp-4C8h]
  IShaderAPI *v78; // [esp+80h] [ebp-4A8h]
  float v79[4]; // [esp+C0h] [ebp-468h] BYREF
  _DWORD v80[4]; // [esp+D0h] [ebp-458h] BYREF
  int v81; // [esp+E0h] [ebp-448h]
  float v82; // [esp+E4h] [ebp-444h]
  float v83; // [esp+E8h] [ebp-440h]
  float v84; // [esp+ECh] [ebp-43Ch]
  float v85; // [esp+F0h] [ebp-438h]
  char v86; // [esp+F4h] [ebp-434h]
  float v87; // [esp+F8h] [ebp-430h]
  char v88; // [esp+FCh] [ebp-42Ch]
  unsigned __int16 *v89; // [esp+100h] [ebp-428h]
  unsigned int v90; // [esp+104h] [ebp-424h]
  int v91; // [esp+108h] [ebp-420h] BYREF
  float v92; // [esp+10Ch] [ebp-41Ch]
  char v93; // [esp+113h] [ebp-415h]
  int v94; // [esp+114h] [ebp-414h] BYREF
  float v95; // [esp+118h] [ebp-410h]
  int v96; // [esp+11Ch] [ebp-40Ch]
  float v97; // [esp+120h] [ebp-408h]
  _BYTE v98[1024]; // [esp+124h] [ebp-404h] BYREF

  v4 = *((_DWORD *)this + 5);
  if ( v4 == 0 )
    return 0;
  v6 = *((_DWORD *)this + 186);
  *(_QWORD *)&v74 = __PAIR64__(a2, a3);
  if ( v6 == 1 && *((_BYTE *)this + 756) != 0 )
  {
    v7 = *((_DWORD *)this + 164);
    if ( v7 != 0 && *((_DWORD *)this + 165) < *(_DWORD *)(v7 + 4) )
    {
      v8 = (double)*((int *)this + 152);
      v9 = *(_DWORD *)(*((_DWORD *)this + 140) + 28);
      v10 = *((float *)this + 181);
    }
    else
    {
      v8 = (double)*((int *)this + 17);
      v9 = *(_DWORD *)(v4 + 28);
      v10 = *((float *)this + 46);
    }
    v11 = *((_DWORD *)this + 318);
    v95 = v8;
    v12 = *((_DWORD *)this + 319);
    v13 = *((int **)this + 3);
    v80[0] = v11;
    v80[1] = v12;
    v14 = *v13;
    v15 = v13[2];
    v92 = v10;
    if ( v14 < 0 )
    {
      v15 &= 0xFFFFFFu;
      if ( v15 == 0xFFFFFF )
        v15 = -1;
    }
    v16 = *((_DWORD *)this + 2);
    v80[3] = v15 - *(_DWORD *)(*((_DWORD *)this + 1) + 28);
    v81 = *((_DWORD *)this + 46);
    switch ( (*(unsigned __int16 *)(v16 + 22) >> 9) & 3 )
    {
      case 0:
        v86 = 0;
        break;
      case 1:
        v86 = 1;
        break;
      case 2:
        v86 = 3;
        break;
      case 3:
        v86 = 2;
        break;
    }
    v82 = *((float *)this + 182);
    v83 = (float)*((int *)this + 17);
    v84 = v95;
    v17 = (*(int (__thiscall **)(_DWORD, int, _DWORD, _DWORD))(**(_DWORD **)(v9 + 12) + 12))(
            a1: *(_DWORD *)(v9 + 12),
            a2: 45,
            a3: v74,
            a4: DWORD1(v74));
    if ( v17 > 0 )
      v85 = ((double (__thiscall *)(_DWORD, int))*(_DWORD *)(**(_DWORD **)(v9 + 12) + 40))(
              a1: *(_DWORD *)(v9 + 12),
              a2: v17);
    v87 = v10;
    v95 = COERCE_FLOAT(v98);
    if ( (unsigned int)(v81 + 1) > 0x100 )
    {
      GFxStyledText::GetAllocator(this: *(SFTextObjectImpl **)(*(_DWORD *)this + 8));
      v19 = *(_DWORD *)(v18 + 28);
      v91 = 324;
      v95 = COERCE_FLOAT((*(int (__thiscall **)(int, int, int *))(*(_DWORD *)v19 + 40))(a1: v19, a2: 4 * v81 + 4, a3: &v91));
    }
    v20 = *((_DWORD *)this + 39);
    v21 = *((_DWORD *)this + 37);
    v97 = 0.0;
    v22 = 0;
    if ( (int)v20 < 4 )
    {
LABEL_36:
      if ( v22 < v20 )
      {
        v28 = (unsigned __int16 *)(v21 + 8 * v22 + 2);
        do
        {
          if ( (v28[1] & 0xF000) != 0 )
            break;
          v29 = *v28;
          if ( (v28[2] & 0x40) != 0 )
            v29 = -v29;
          v96 = v29;
          ++v22;
          v28 += 4;
          v97 = (double)v29 + v97;
        }
        while ( v22 < v20 );
      }
    }
    else
    {
      v23 = (unsigned __int16 *)(v21 + 10);
      while ( (*(v23 - 3) & 0xF000) == 0 )
      {
        v24 = *(v23 - 4);
        if ( (*(_BYTE *)(v23 - 2) & 0x40) != 0 )
          v24 = -v24;
        v96 = v24;
        v97 = (double)v24 + v97;
        if ( (v23[1] & 0xF000) != 0 )
        {
          ++v22;
          break;
        }
        v25 = *v23;
        if ( (v23[2] & 0x40) != 0 )
          v25 = -v25;
        v96 = v25;
        v97 = (double)v25 + v97;
        if ( (v23[5] & 0xF000) != 0 )
        {
          v22 += 2;
          break;
        }
        v26 = v23[4];
        if ( (v23[6] & 0x40) != 0 )
          v26 = -v26;
        v96 = v26;
        v97 = (double)v26 + v97;
        if ( (v23[9] & 0xF000) != 0 )
        {
          v22 += 3;
          break;
        }
        v27 = v23[8];
        if ( (v23[10] & 0x40) != 0 )
          v27 = -v27;
        v96 = v27;
        v22 += 4;
        v23 += 16;
        v97 = (double)v27 + v97;
        if ( v22 >= v20 - 3 )
          goto LABEL_36;
      }
    }
    *(float *)&v80[2] = v95;
    v30 = 0;
    v96 = 0;
    v82 = v82 - v97;
    v83 = v83 - v97;
    v84 = v84 - v97;
    v97 = 0.0;
    if ( v22 < v20 )
    {
      v31 = (unsigned __int16 *)(v21 + 8 * v22 + 2);
      v89 = v31;
      v90 = v20 - v22;
      do
      {
        v32 = v97;
        v33 = (float *)(LODWORD(v95) + 4 * v30);
        *v33 = v97;
        LODWORD(v34) = *v31;
        if ( (v31[2] & 0x40) != 0 )
          LODWORD(v34) = -LODWORD(v34);
        v97 = v34;
        v35 = v32 + (double)SLODWORD(v34);
        v36 = v31[1] >> 12;
        v94 = v36;
        v97 = v35;
        if ( v36 > 1 )
        {
          v37 = 2 * v30;
          do
          {
            *(_WORD *)(v37 + *((_DWORD *)this + 318)) = 160;
            *v33 = 0.0;
            v37 += 2;
            ++v33;
            --v36;
          }
          while ( *(float *)&v36 != 0.0 );
          v36 = v94;
          v30 = v96;
          v31 = v89;
        }
        v30 += v36;
        v31 += 4;
        v38 = v90-- == 1;
        v96 = v30;
        v89 = v31;
      }
      while ( !v38 );
    }
    v39 = v95;
    *(float *)(LODWORD(v95) + 4 * v30) = v97;
    v40 = *(_DWORD *)this;
    v88 = 0;
    v41 = *(_DWORD *)(v40 + 16);
    *(_QWORD *)&v74 = __PAIR64__(v80, v40);
    v93 = (*(int (__thiscall **)(int))(*(_DWORD *)v41 + 4))(a1: v41);
    if ( v93 != 0 )
    {
      *((_BYTE *)this + 748) = v88;
      if ( LODWORD(v87) != LODWORD(v92) )
      {
        v42 = *((_DWORD *)this + 164);
        if ( v42 != 0 && *((_DWORD *)this + 165) < *(_DWORD *)(v42 + 4) && LODWORD(v87) > *((_DWORD *)this + 181) )
        {
          GFxTextLineBuffer::GlyphInserter::ResetTo(
            this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)this
          + 37,
            savedPos: (IShaderAPI *)this + 172,
            a3: v74);
          GFxLineCursor::operator=(this: (char *)this + 16, a2: (int)this + 556);
        }
        else
        {
          v43 = *((_DWORD *)this + 121);
          if ( v43 != 0 && *((_DWORD *)this + 122) < *(_DWORD *)(v43 + 4) && LODWORD(v87) > *((_DWORD *)this + 138) )
          {
            GFxTextLineBuffer::GlyphInserter::ResetTo(
              this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)this
            + 37,
              savedPos: (IShaderAPI *)this + 129,
              a3: v74);
            GFxLineCursor::operator=(this: (char *)this + 16, a2: (int)this + 384);
          }
          else
          {
            GFxTextLineBuffer::GlyphInserter::ResetTo(
              this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)this
            + 37,
              savedPos: (IShaderAPI *)this + 86,
              a3: v74);
            GFxLineCursor::operator=(this: (char *)this + 16, a2: (int)this + 212);
          }
        }
        v44 = v87;
        *((_DWORD *)this + 186) = 2;
        *((float *)this + 188) = v44;
        *((_DWORD *)this + 185) = 0;
      }
    }
    if ( (_BYTE *)LODWORD(v39) != v98 )
    {
      v45 = *(_DWORD *)(*(_DWORD *)this + 8);
      if ( *(_DWORD *)(v45 + 8) == 0 )
      {
        v46 = (CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *)GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: *(_DWORD *)(*(_DWORD *)this + 8));
        v47 = *(int (__thiscall **)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *))(LODWORD(v46->m_pfnProxied) + 40);
        v94 = 324;
        v48 = (GStringDH *)v47(a1: v46, a2: 80, a3: &v94);
        if ( v48 != nullptr )
          v49 = GFxTextAllocator::GFxTextAllocator(this: v48, result: v46, flags: 0);
        else
          v49 = nullptr;
        v50 = *(GRefCountNTSImpl **)(v45 + 8);
        if ( v50 != nullptr )
          GRefCountNTSImpl::Release(this: v50);
        *(_DWORD *)(v45 + 8) = v49;
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)LODWORD(v95));
    }
    v51 = GFxLineCursor::GFxLineCursor(this: (GFxLineCursor *)((char *)&v74 + 12));
    v52 = GFxLineCursor::operator=(this: (char *)this + 384, a2: (int)v51);
    GFxLineCursor::operator=(this: (char *)this + 212, a2: (int)v52);
    if ( v78 != nullptr )
      GRefCountImpl::Release(this: v78);
    if ( v77 != nullptr )
      GRefCountImpl::Release(this: v77);
    if ( v76 != nullptr )
      GRefCountNTSImpl::Release(this: v76);
    v53 = v75;
    if ( v75 != nullptr )
    {
      --LODWORD(v75->m_pfnProxied);
      v54 = v53;
      if ( LODWORD(v53->m_pfnProxied) == 0 )
      {
        GFxFontHandle::~GFxFontHandle(this: v53);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v54);
      }
    }
    if ( v93 != 0 && *((_DWORD *)this + 186) == 2 )
      return 1;
  }
  else if ( v6 == 2 )
  {
    v55 = GFxLineCursor::GFxLineCursor(this: (GFxLineCursor *)((char *)&v74 + 12));
    GFxLineCursor::operator=(this: (char *)this + 556, a2: (int)v55);
    GFxLineCursor::~GFxLineCursor(this: (GFxLineCursor *)((char *)&v74 + 12));
    *((_DWORD *)this + 186) = 1;
  }
  if ( *((_BYTE *)this + 748) != 0 )
  {
    v56 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
    *(_DWORD *)(v56 + 4) = 0;
    v94 = *((int *)this + 8);
    v57 = *(float *)&v94;
    if ( *(float *)&v94 <= 0.0 )
      v58 = v57 - 0.5;
    else
      v58 = v57 + 0.5;
    v59 = (int)v58;
    v60 = *((_DWORD *)this + 4);
    if ( v60 != 0 )
    {
      if ( v59 < 0 )
      {
        LOWORD(v59) = abs32(v59);
        *(_WORD *)(v60 + 6) |= 0x40u;
      }
      else
      {
        *(_WORD *)(v60 + 6) &= ~0x40u;
      }
      *(_WORD *)(v60 + 2) = v59;
    }
    v61 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 28) + 12);
    v62 = (*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v61 + 12))(a1: v61, a2: 45, a3: v74);
    *(_WORD *)(v56 + 4) &= 0xFFFu;
    v63 = v62;
    *(_WORD *)v56 = v62;
    GFxTextLineBuffer::GlyphEntry::SetFontSize(
      this: (_WORD *)v56,
      result: COERCE_CONST_CINDEXBUFFERBASE_(*((float *)this + 329)));
    v64 = *((_DWORD *)this + 5);
    *((_DWORD *)this + 17) = *((_DWORD *)this + 328);
    *(float *)&v94 = ((double (__thiscall *)(_DWORD, int))*(_DWORD *)(**(_DWORD **)(*(_DWORD *)(v64 + 28) + 12) + 32))(
                       a1: *(_DWORD *)(*(_DWORD *)(v64 + 28) + 12),
                       a2: v63);
    v65 = *((_DWORD *)this + 320);
    LODWORD(v74) = v79;
    *(float *)&v94 = *((float *)this + 322) * *(float *)&v94;
    v79[0] = 0.0;
    v79[1] = 0.0;
    v79[2] = 0.0;
    v79[3] = 0.0;
    *(float *)&v91 = *(float *)((*(int (__thiscall **)(_DWORD, int, float *))(**(_DWORD **)(v65 + 12) + 48))(
                                  a1: *(_DWORD *)(v65 + 12),
                                  a2: v63,
                                  a3: v79)
                              + 8)
                   * *((float *)this + 322)
                   + 20.0;
    v66 = *(float *)&v94;
    if ( *(float *)&v91 > (double)*(float *)&v94 )
      v66 = *(float *)&v91;
    v92 = v66;
    v67 = v92;
    if ( v92 <= 0.0 )
      v68 = v67 - 0.5;
    else
      v68 = v67 + 0.5;
    LODWORD(v95) = (int)v68;
    v69 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 28) + 12);
    v70 = *(void (__thiscall **)(int))(*(_DWORD *)v69 + 40);
    LODWORD(v74) = v63;
    v70(a1: v69);
    v71 = v95;
    v72 = LODWORD(v95) + *((_DWORD *)this + 328);
    *((float *)this + 8) = (float)SLODWORD(v95);
    *((float *)this + 9) = v71;
    *((_DWORD *)this + 7) = v63;
    *((_DWORD *)this + 43) = 0;
    *((_DWORD *)this + 18) = v72;
    *((_BYTE *)this + 748) = 0;
    *((_DWORD *)this + 4) = v56;
    if ( *((_DWORD *)this + 37) != 0 )
    {
      v73 = *((_DWORD *)this + 39);
      if ( v73 < *((_DWORD *)this + 40) )
        *((_DWORD *)this + 39) = v73 + 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016ADC0
// Name: public: bool GFxParagraphFormatter::CheckWordWrap(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall GFxParagraphFormatter::CheckWordWrap@<al>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        unsigned int a2@<edi>)
{
  int v3; // ecx
  int v4; // eax
  IShaderAPI_vtbl *v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  GFxLineCursor *v9; // eax
  IShaderAPI **v10; // eax
  int v11; // eax
  int *v12; // eax
  __int128 v14[11]; // [esp+0h] [ebp-D0h] BYREF
  IShaderAPI savedPos; // [esp+B4h] [ebp-1Ch] BYREF
  int v16; // [esp+B8h] [ebp-18h]
  int v17; // [esp+BCh] [ebp-14h]
  int v18; // [esp+C0h] [ebp-10h]
  int v19; // [esp+C4h] [ebp-Ch]
  int v20; // [esp+C8h] [ebp-8h]
  char v21; // [esp+CFh] [ebp-1h]

  v3 = *((_DWORD *)this + 186);
  if ( v3 == 1
    && (BYTE2(this->m_pAllocator[8].m_pBase) & 8) != 0
    && *((_BYTE *)this + 1320) == 0
    && (v20 = *((_DWORD *)this + 34) + *((_DWORD *)this + 35) + *((_DWORD *)this + 327) + *((_DWORD *)this + 328),
        *((float *)this + 182) - (double)*((int *)this + 36) < (double)v20)
    || v3 == 2 && *((_DWORD *)this + 46) == *((_DWORD *)this + 188) )
  {
    if ( GFxParagraphFormatter::HandleCustomWordWrap((GFxParagraphFormatter *)this, a2: 0, a3: a2) != 0 )
      return 1;
    *((_DWORD *)this + 328) = 0;
    v4 = *((_DWORD *)this + 164);
    v21 = 0;
    if ( v4 != 0 && *((_DWORD *)this + 165) < *(_DWORD *)(v4 + 4) )
    {
      v5 = *((IShaderAPI_vtbl **)this + 172);
      v6 = *((_DWORD *)this + 173);
      v17 = *((_DWORD *)this + 174);
      savedPos.__vftable = v5;
      v7 = *((_DWORD *)this + 175);
      v16 = v6;
      v8 = *((_DWORD *)this + 176);
      v18 = v7;
      v19 = v8;
      GFxTextLineBuffer::GlyphInserter::ResetTo(this: this + 37, &savedPos, a3: v14[0]);
      GFxLineCursor::operator=(this: this + 4, a2: (int)(this + 139));
      *((_BYTE *)this + 1320) = 0;
      v21 = 1;
      *((_DWORD *)this + 185) = 0;
    }
    v9 = GFxLineCursor::GFxLineCursor(this: (GFxLineCursor *)((char *)v14 + 8));
    GFxLineCursor::operator=(this: this + 139, a2: (int)v9);
    GFxLineCursor::~GFxLineCursor(this: (GFxLineCursor *)((char *)v14 + 8));
    v20 = *(_DWORD *)(*((_DWORD *)this + 1) + 28);
    v10 = GFxLineCursor::operator*(this: (int)(this + 4));
    v20 += (int)v10[1];
    v11 = *((_DWORD *)this + 4);
    if ( v11 != 0 )
      *(_WORD *)(v11 + 6) |= 8u;
    GFxParagraphFormatter::FinalizeLine((GFxParagraphFormatter *)this);
    *((float *)this + 22) = 0.0;
    *((_DWORD *)this + 4) = 0;
    *((float *)this + 21) = 0.0;
    *((_WORD *)this + 90) = 0;
    *((float *)this + 20) = 0.0;
    *((_DWORD *)this + 18) = 0;
    *((float *)this + 8) = 0.0;
    *((_DWORD *)this + 19) = 0;
    *((_DWORD *)this + 43) = 0;
    *((_DWORD *)this + 42) = 0;
    *((_DWORD *)this + 46) = 0;
    *((_DWORD *)this + 6) = 0;
    v12 = *((int **)this + 3);
    *((_DWORD *)this + 184) = 0;
    if ( *v12 >= 0 )
      v12[2] = v20;
    else
      v12[2] ^= (v20 ^ v12[2]) & 0xFFFFFF;
    if ( v21 != 0 )
    {
      *((_DWORD *)this + 17) = 0;
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016B180
// Name: public: virtual GFxTextDocView::~GFxTextDocView(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1016B280
// Name: public: void GFxParagraphFormatter::InitParagraph(class GFxTextParagraph const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxParagraphFormatter::InitParagraph(GFxParagraphFormatter *this, IGameEvent *a2)
{
  struct GFxTextDocView *v3; // edx
  GFxLineCursor *v4; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v5; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v6; // edi
  GFxLineCursor *v7; // eax
  void *v8; // eax
  void *v9; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v10; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v11; // edi
  struct GFxTextParagraph v12; // eax
  struct GFxFontMapImpl *pImpl; // eax
  GFxResourceId *v14; // eax
  GFxResourceId *v15; // edi
  GRefCountNTSImpl *v16; // ecx
  __int16 v17; // cx
  int v18; // eax
  unsigned int v19; // edi
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  int v22; // eax
  int v23; // eax
  int *v24; // eax
  int v25; // eax
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v26; // ecx
  GFxFontMap *v27; // eax
  unsigned int v28; // edi
  int *v29; // ecx
  int v30; // ecx
  int v31; // edi
  struct GFxTextParagraph v32; // eax
  double v33; // st7
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v34; // [esp+0h] [ebp-168h]
  unsigned int v35; // [esp+4h] [ebp-164h]
  _BYTE v36[4]; // [esp+Ch] [ebp-15Ch] BYREF
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v37; // [esp+10h] [ebp-158h]
  GRefCountNTSImpl *v38; // [esp+28h] [ebp-140h]
  IShaderAPI *v39; // [esp+58h] [ebp-110h]
  IShaderAPI *v40; // [esp+78h] [ebp-F0h]
  _BYTE v41[4]; // [esp+B8h] [ebp-B0h] BYREF
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v42; // [esp+BCh] [ebp-ACh]
  GRefCountNTSImpl *v43; // [esp+D4h] [ebp-94h]
  IShaderAPI *v44; // [esp+104h] [ebp-64h]
  IShaderAPI *v45; // [esp+124h] [ebp-44h]
  int v46; // [esp+164h] [ebp-4h]
  struct GFxTextParagraph *v47; // [esp+170h] [ebp+8h]

  v3 = *(struct GFxTextDocView **)this;
  *((_DWORD *)this + 1) = a2;
  *((IGameEvent *)this + 2) = a2[3];
  v4 = GFxLineCursor::GFxLineCursor(this: (GFxLineCursor *)v41, a2: v3, pparagraph: a2);
  GFxLineCursor::operator=(this: (char *)this + 16, a2: (int)v4);
  if ( v45 != nullptr )
    GRefCountImpl::Release(this: v45);
  if ( v44 != nullptr )
    GRefCountImpl::Release(this: v44);
  if ( v43 != nullptr )
    GRefCountNTSImpl::Release(this: v43);
  v5 = v42;
  if ( v42 != nullptr )
  {
    --LODWORD(v42->m_pfnProxied);
    v6 = v5;
    if ( LODWORD(v5->m_pfnProxied) == 0 )
    {
      GFxFontHandle::~GFxFontHandle(this: v5);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
    }
  }
  v7 = GFxLineCursor::GFxLineCursor(this: (GFxLineCursor *)v36);
  v8 = GFxLineCursor::operator=(this: (char *)this + 556, a2: (int)v7);
  v9 = GFxLineCursor::operator=(this: (char *)this + 384, a2: (int)v8);
  GFxLineCursor::operator=(this: (char *)this + 212, a2: (int)v9);
  if ( v40 != nullptr )
    GRefCountImpl::Release(this: v40);
  if ( v39 != nullptr )
    GRefCountImpl::Release(this: v39);
  if ( v38 != nullptr )
    GRefCountNTSImpl::Release(this: v38);
  v10 = v37;
  if ( v37 != nullptr )
  {
    --LODWORD(v37->m_pfnProxied);
    v11 = v10;
    if ( LODWORD(v10->m_pfnProxied) == 0 )
    {
      GFxFontHandle::~GFxFontHandle(this: v10);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
    }
  }
  v12.pObject = *(GFxFontMap **)this;
  v46 = *(unsigned __int16 *)(*(_DWORD *)this + 330);
  *((float *)this + 44) = (double)v46 / 20.0;
  pImpl = v12.pObject[17].pImpl;
  if ( pImpl != nullptr )
  {
    v14 = *((GFxResourceId **)pImpl + 5);
    if ( v14 != nullptr && GFxTextParagraph::GetLength(this: v14 + 5) != 0 )
    {
      v15 = *(GFxResourceId **)(*(_DWORD *)(*(_DWORD *)this + 284) + 20);
      if ( v15 != nullptr )
        ++v15[1].Id;
      v16 = *((GRefCountNTSImpl **)this + 11);
      if ( v16 != nullptr )
        GRefCountNTSImpl::Release(this: v16);
      *((_DWORD *)this + 11) = v15;
      *((GFxResourceId *)this + 12) = v15[12];
      *((_DWORD *)this + 13) = GFxTextParagraph::GetLength(this: v15 + 5);
    }
  }
  GFxParagraphFormatter::InitCustomWordWrapping(this);
  v17 = *(_WORD *)(*((_DWORD *)this + 2) + 22);
  v18 = (int)a2[1].__vftable + *((_DWORD *)this + 13);
  v46 = v18;
  if ( (v17 & 0x80u) != 0 && v17 < 0 )
    v46 = ++v18;
  v19 = (unsigned int)GFxTextLineBuffer::CalcLineSize(glyphCount: (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)(2 * v18));
  if ( v19 >= 0x400 )
  {
    v21 = *((_DWORD **)this + 588);
    if ( v21 != nullptr )
    {
      if ( v19 >= (*v21 & 0xFFFFFFFu) )
      {
        GFxTextLineBuffer::TextLineAllocator::FreeLine(
          this: (GFxTextLineBuffer::TextLineAllocator *)(*(_DWORD *)this + 236),
          a2: *((struct GFxTextLineBuffer::Line **)this + 588));
        GFxTextLineBuffer::TextLineAllocator::AllocLine(
          this: (GFxMovieView *)(*(_DWORD *)this + 236),
          size: COERCE_FLOAT(v19 + 100),
          lineType: COERCE_FLOAT(1),
          a4: (unsigned int)v34,
          a5: v35);
        *((_DWORD *)this + 588) = v22;
      }
      *((_DWORD *)this + 3) = *((_DWORD *)this + 588);
    }
    else
    {
      GFxTextLineBuffer::TextLineAllocator::AllocLine(
        this: (GFxMovieView *)(*(_DWORD *)this + 236),
        size: COERCE_FLOAT(v19 + 100),
        lineType: COERCE_FLOAT(1),
        a4: (unsigned int)v34,
        a5: v35);
      *((_DWORD *)this + 588) = v23;
      *((_DWORD *)this + 3) = v23;
    }
  }
  else
  {
    v20 = (_DWORD *)((char *)this + 1328);
    if ( this == (GFxParagraphFormatter *)-1328 )
    {
      MEMORY[0xFFFFFADC] = 0;
      MEMORY[0] ^= (v19 ^ MEMORY[0]) & 0xFFFFFFF;
    }
    else
    {
      *v20 = 0;
      *((_DWORD *)this + 3) = v20;
      *v20 ^= (v19 ^ *v20) & 0xFFFFFFF;
    }
  }
  v24 = *((int **)this + 3);
  *v24 = *v24 & 0xFFFFFFF | 0x40000000;
  *(int *)((char *)v24 + 38) = 0;
  v24[1] = 0;
  v24[2] = 0;
  v24[4] = 0;
  v24[3] = 0;
  v24[6] = 0;
  v24[5] = 0;
  v24[8] = 0;
  **((_DWORD **)this + 3) &= ~0x40000000u;
  v25 = *((_DWORD *)this + 3);
  if ( *(int *)v25 >= 0 )
    *(_DWORD *)(v25 + 4) = v46;
  else
    *(_BYTE *)(v25 + 28) = v46;
  v26 = *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)(*(_DWORD *)this + 284);
  if ( v26 != nullptr )
  {
    GFxTextEditorKit::TextPos2GlyphOffset(this: v26, textPos: a2[7].__vftable, a3: v34);
    v28 = (unsigned int)v27;
  }
  else
  {
    v28 = (unsigned int)a2[7].__vftable;
  }
  v29 = *((int **)this + 3);
  if ( *v29 >= 0 )
    v29[2] = v28;
  else
    v29[2] ^= (v28 ^ v29[2]) & 0xFFFFFF;
  v30 = *((_DWORD *)this + 3);
  if ( *(int *)v30 >= 0 )
    v47 = *(struct GFxTextParagraph **)(v30 + 4);
  else
    v47 = (struct GFxTextParagraph *)*(unsigned __int8 *)(v30 + 28);
  v31 = v30 + 30;
  if ( *(int *)v30 >= 0 )
    v31 = v30 + 42;
  *((_DWORD *)this + 38) = GFxTextLineBuffer::Line::GetFormatData(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v30);
  *((_DWORD *)this + 37) = v31;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 40) = v47;
  *((_DWORD *)this + 185) = 1;
  *((_DWORD *)this + 186) = 1;
  v32.pObject = *(GFxFontMap **)this;
  *((_DWORD *)this + 592) = 0;
  *((_DWORD *)this + 593) = 0;
  *((_DWORD *)this + 594) = 0;
  *((_BYTE *)this + 748) = 0;
  *((_DWORD *)this + 188) = 0;
  *((_BYTE *)this + 1320) = 0;
  v33 = *(float *)&v32.pObject[4].RefCount - *(float *)&v32.pObject[3].pImpl;
  *((_DWORD *)this + 183) = 0;
  *((_DWORD *)this + 184) = 0;
  *((float *)this + 182) = v33;
}

//------------------------------------------------------------------------------
// Address: 0x1016B980
// Name: protected: class GFxFontHandle __near * GFxTextDocView::FindFont(struct GFxTextDocView::FindFontInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct GFxFontHandle *__userpurge GFxTextDocView::FindFont@<eax>(
        GFxTextDocView *this@<ecx>,
        struct GFxTextDocView::FindFontInfo *a2,
        CUtlMemory<CImagePacker,int> a3)
{
  struct GFxTextDocView::FindFontInfo *v3; // ebx
  bool v4; // zf
  int *v6; // ecx
  int v7; // edi
  int Index; // eax
  int v9; // edi
  _DWORD **v10; // edi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v11; // esi
  GString::DataDesc *v12; // edx
  int v14; // ecx
  __int16 v15; // ax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *FontHandle; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v17; // edi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *Size; // esi
  CDefaultClientRenderable *v19; // edi
  char v20; // bl
  char v21; // al
  char **FontList; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v23; // ebx
  int v24; // ecx
  __int16 v25; // bx
  char v26; // al
  char **v27; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v28; // eax
  int v29; // ecx
  char v30; // bl
  CImagePacker *v31; // eax
  unsigned int v32; // ebx
  char **v33; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v34; // esi
  CImagePacker *EmptyFont; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v36; // esi
  GString::DataDesc *pData; // ecx
  int v38; // [esp+8h] [ebp-2Ch] BYREF
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v39; // [esp+Ch] [ebp-28h] BYREF
  GString v40; // [esp+24h] [ebp-10h] BYREF
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v41; // [esp+28h] [ebp-Ch]
  GString v42; // [esp+2Ch] [ebp-8h] BYREF
  bool v43; // [esp+31h] [ebp-3h]
  char v44; // [esp+32h] [ebp-2h]
  bool v45; // [esp+33h] [ebp-1h]

  v3 = a2;
  v40.pData = nullptr;
  v4 = *((_DWORD *)a2 + 3) == 0;
  v42.pData = (GString::DataDesc *)((char *)a2 + 12);
  if ( !v4
    && *((_DWORD *)a2 + 2) != 0
    && GFxTextFormat::IsFontSame(this: *((GFxTextFormat **)a2 + 1), fmt: *((const struct GFxTextFormat **)a2 + 2)) )
  {
LABEL_50:
    pData = v42.pData;
    *((_DWORD *)v3 + 2) = *((_DWORD *)v3 + 1);
    return (struct GFxFontHandle *)pData->Size;
  }
  v6 = *(int **)a2;
  if ( *(_DWORD *)a2 == 0
    || (v7 = *v6, *v6 == 0)
    || (Index = GHashSetBase<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeAltHashF,GAllocatorGH<GASObject *,2>,GHashsetNodeEntry<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF>>::findIndexCore<GASObject *>(
                  this: v6,
                  a2: (_DWORD *)a2 + 1,
                  a3: *((_DWORD *)a2 + 1) & *(_DWORD *)(v7 + 4))) < 0
    || (v9 = v7 + 4 * (3 * Index + 3)) == 0
    || (v10 = (_DWORD **)(v9 + 4)) == nullptr )
  {
    v14 = *((_DWORD *)a2 + 1);
    v15 = *(_WORD *)(v14 + 42);
    if ( (v15 & 0x800) != 0 )
    {
      FontHandle = GFxTextFormat::GetFontHandle(this: (GFxTextFormat *)v14);
      v17 = FontHandle;
      if ( FontHandle != nullptr )
        ++LODWORD(FontHandle->m_pfnProxied);
      Size = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)v42.pData->Size;
      if ( *(_DWORD *)v42.HeapTypeBits != 0 )
      {
        v4 = LODWORD(Size->m_pfnProxied)-- == 1;
        if ( v4 )
        {
          GFxFontHandle::~GFxFontHandle(this: Size);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: Size);
        }
      }
      *(_DWORD *)v42.HeapTypeBits = v17;
    }
    else
    {
      v19 = *((CDefaultClientRenderable **)this + 3);
      if ( (v15 & 4) != 0 )
      {
        v20 = *((_BYTE *)this + 334);
        v45 = (v15 & 0x1000) != 0;
        v21 = *(_BYTE *)(v14 + 40) & 1;
        v43 = (*(_BYTE *)(v14 + 40) & 2) != 0;
        v44 = v21;
        FontList = GFxTextFormat::GetFontList(this: (char **)v14);
        v42.pData = (GString::DataDesc *)GFxFontManager::CreateFontHandle(
                                           this: v19,
                                           string: (unsigned __int8 *)(((unsigned int)*FontList & 0xFFFFFFFC) + 8),
                                           matchFontFlags: ((v20 & 0x20) != 0 ? 0x10 : 0) | v43 | (v44 != 0 ? 2 : 0),
                                           allowListOfFonts: !v45,
                                           searchInfo: 0);
        v23 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)a2
              + 3);
        if ( v23 != nullptr )
        {
          v4 = LODWORD(v23->m_pfnProxied)-- == 1;
          if ( v4 )
          {
            GFxFontHandle::~GFxFontHandle(this: v23);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v23);
          }
        }
        *((GString *)a2 + 3) = v42;
        v3 = a2;
      }
      v4 = *((_DWORD *)v3 + 3) == 0;
      v42.pData = (GString::DataDesc *)((char *)v3 + 12);
      if ( v4 )
      {
        if ( LOBYTE(a3.m_pMemory) == 0 && (*((_BYTE *)this + 336) & 0x10) == 0 && *((_DWORD *)this + 81) != 0 )
        {
          v38 = 1;
          GStringBuffer::GStringBuffer(
            this: &v39,
            result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
          v24 = *((_DWORD *)v3 + 1);
          v25 = *(_WORD *)(v24 + 42);
          LOBYTE(a3.m_pMemory) = (*((_BYTE *)this + 334) & 0x20) != 0;
          v26 = *(_BYTE *)(v24 + 40) & 1;
          LOBYTE(v41) = (*(_BYTE *)(v24 + 40) & 2) != 0;
          LOBYTE(v40.pData) = v26;
          v27 = GFxTextFormat::GetFontList(this: (char **)v24);
          v28 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)GFxFontManager::CreateFontHandle(this: v19, result: (const CDefaultClientRenderable *)(((unsigned int)*v27 & 0xFFFFFFFC) + 8), bold: (int)v40.pData, italic: (int)v41, device: (int)a3.m_pMemory, allowListOfFonts: (v25 & 0x1000) == 0, searchInfo: (IScaleformUIFunctionHandlerDefinitionTable)&v38);
          v29 = *((_DWORD *)this + 4);
          v41 = v28;
          if ( v29 != 0 )
          {
            v30 = 1;
            v31 = (CImagePacker *)(*(int (__thiscall **)(int, GString *))(*(_DWORD *)v29 + 36))(a1: v29, a2: &v40);
          }
          else
          {
            v30 = 2;
            GString::GString(this: &a3);
          }
          GString::GString(this: (CCountedStringPoolBase<unsigned int> *)&v42, result: v31);
          if ( (v30 & 2) != 0 )
          {
            v30 &= ~2u;
            GString::~GString(this: (GString *)&a3);
          }
          if ( (v30 & 1) != 0 )
            GString::~GString(this: &v40);
          a3.m_pMemory = (CImagePacker *)v39.m_pfnProxied;
          if ( LODWORD(v39.m_pfnProxied) == 0 )
            a3.m_pMemory = (CImagePacker *)&pMem;
          v32 = v42.HeapTypeBits & 0xFFFFFFFC;
          v33 = GFxTextFormat::GetFontList(this: *((char ***)a2 + 1));
          GFxLogBase<GFxLog>::LogError(
            this: (GFxLogBase<GFxLog> *)(*((_DWORD *)this + 81) + 12),
            pfmt: "Missing font \"%s\" in \"%s\". Search log:\n%s",
            (const char *)(((unsigned int)*v33 & 0xFFFFFFFC) + 8),
            (const char *)(v32 + 8),
            (const char *)a3.m_pMemory);
          *((_BYTE *)this + 336) |= 0x10u;
          GString::~GString(this: &v42);
          v34 = v41;
          if ( v41 != nullptr )
          {
            v4 = LODWORD(v41->m_pfnProxied)-- == 1;
            if ( v4 )
            {
              GFxFontHandle::~GFxFontHandle(this: v34);
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v34);
            }
          }
          GStringBuffer::~GStringBuffer(this: &v39);
          v3 = a2;
        }
        EmptyFont = (CImagePacker *)GFxFontManager::GetEmptyFont(this: v19);
        v36 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)v3
              + 3);
        a3.m_pMemory = EmptyFont;
        v42.pData = (GString::DataDesc *)((char *)v3 + 12);
        if ( v36 != nullptr )
        {
          v4 = LODWORD(v36->m_pfnProxied)-- == 1;
          if ( v4 )
          {
            GFxFontHandle::~GFxFontHandle(this: v36);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v36);
          }
        }
        *((_DWORD *)v3 + 3) = a3.m_pMemory;
      }
    }
    if ( *(_DWORD *)v3 != 0 )
      GHash<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>,GAllocatorDH<GFxTextFormat const *,324>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashsetNodeEntry<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF>,GHashSetDH<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeAltHashF,324,GHashsetNodeEntry<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF>>>::Set(
        this: *(_DWORD *)v3,
        a2: (int *)v3 + 1,
        a3: v42.pData);
    goto LABEL_50;
  }
  if ( *v10 != nullptr )
    ++**v10;
  v11 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)v42.pData->Size;
  if ( *(_DWORD *)v42.HeapTypeBits != 0 )
  {
    v4 = LODWORD(v11->m_pfnProxied)-- == 1;
    if ( v4 )
    {
      GFxFontHandle::~GFxFontHandle(this: v11);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
    }
  }
  v12 = v42.pData;
  *(_DWORD *)v42.HeapTypeBits = *v10;
  *((_DWORD *)a2 + 2) = *((_DWORD *)a2 + 1);
  return (struct GFxFontHandle *)v12->Size;
}

//------------------------------------------------------------------------------
// Address: 0x1016BD00
// Name: public: GFxParagraphFormatter::GFxParagraphFormatter(class GFxTextDocView __near *,class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
GFxParagraphFormatter *__thiscall GFxParagraphFormatter::GFxParagraphFormatter(
        GFxParagraphFormatter *this,
        struct GFxTextDocView *a2,
        struct GFxLog *a3)
{
  int v4; // ecx
  GMemoryHeap *v5; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v6; // edi

  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  GFxLineCursor::GFxLineCursor(this: (GFxParagraphFormatter *)((char *)this + 16));
  v4 = *(_DWORD *)(*((_DWORD *)a2 + 2) + 8);
  if ( v4 != 0 )
    v5 = *(GMemoryHeap **)(v4 + 28);
  else
    v5 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: *((_DWORD *)a2 + 2));
  *((_DWORD *)this + 47) = 0;
  *((_DWORD *)this + 48) = v5;
  *((_DWORD *)this + 49) = (char *)this + 188;
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 51) = 0;
  *((_DWORD *)this + 50) = 0;
  v6 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
       + 52);
  if ( v6 != nullptr && LODWORD(v6->m_pfnProxied)-- == 1 )
  {
    GFxFontHandle::~GFxFontHandle(this: v6);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
  }
  *((_DWORD *)this + 52) = 0;
  GFxLineCursor::GFxLineCursor(this: (GFxParagraphFormatter *)((char *)this + 212));
  GFxLineCursor::GFxLineCursor(this: (GFxParagraphFormatter *)((char *)this + 384));
  GFxLineCursor::GFxLineCursor(this: (GFxParagraphFormatter *)((char *)this + 556));
  *((_DWORD *)this + 321) = 0;
  *((_DWORD *)this + 588) = 0;
  *((_DWORD *)this + 590) = 0;
  *((_DWORD *)this + 589) = 0;
  *((_WORD *)this + 1190) = 0;
  *((_DWORD *)this + 591) = a3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016BDE0
// Name: public: GFxParagraphFormatter::~GFxParagraphFormatter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxParagraphFormatter::~GFxParagraphFormatter(GFxParagraphFormatter *this)
{
  struct GFxTextLineBuffer::Line *v2; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v3; // edi
  bool v4; // zf
  IShaderAPI *v5; // ecx
  IShaderAPI *v6; // ecx
  GRefCountNTSImpl *v7; // ecx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v8; // edi
  IShaderAPI *v9; // ecx
  IShaderAPI *v10; // ecx
  GRefCountNTSImpl *v11; // ecx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v12; // edi
  IShaderAPI *v13; // ecx
  IShaderAPI *v14; // ecx
  GRefCountNTSImpl *v15; // ecx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v16; // edi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v17; // edi
  IShaderAPI *v18; // ecx
  IShaderAPI *v19; // ecx
  GRefCountNTSImpl *v20; // ecx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v21; // esi

  v2 = *((struct GFxTextLineBuffer::Line **)this + 588);
  if ( v2 != nullptr )
    GFxTextLineBuffer::TextLineAllocator::FreeLine(
      this: (GFxTextLineBuffer::TextLineAllocator *)(*(_DWORD *)this + 236),
      a2: v2);
  v3 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
       + 321);
  if ( v3 != nullptr )
  {
    v4 = LODWORD(v3->m_pfnProxied)-- == 1;
    if ( v4 )
    {
      GFxFontHandle::~GFxFontHandle(this: v3);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
    }
  }
  v5 = *((IShaderAPI **)this + 166);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  v6 = *((IShaderAPI **)this + 158);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  v7 = *((GRefCountNTSImpl **)this + 146);
  if ( v7 != nullptr )
    GRefCountNTSImpl::Release(this: v7);
  v8 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
       + 140);
  if ( v8 != nullptr )
  {
    v4 = LODWORD(v8->m_pfnProxied)-- == 1;
    if ( v4 )
    {
      GFxFontHandle::~GFxFontHandle(this: v8);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
    }
  }
  v9 = *((IShaderAPI **)this + 123);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  v10 = *((IShaderAPI **)this + 115);
  if ( v10 != nullptr )
    GRefCountImpl::Release(this: v10);
  v11 = *((GRefCountNTSImpl **)this + 103);
  if ( v11 != nullptr )
    GRefCountNTSImpl::Release(this: v11);
  v12 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
        + 97);
  if ( v12 != nullptr )
  {
    v4 = LODWORD(v12->m_pfnProxied)-- == 1;
    if ( v4 )
    {
      GFxFontHandle::~GFxFontHandle(this: v12);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
    }
  }
  v13 = *((IShaderAPI **)this + 80);
  if ( v13 != nullptr )
    GRefCountImpl::Release(this: v13);
  v14 = *((IShaderAPI **)this + 72);
  if ( v14 != nullptr )
    GRefCountImpl::Release(this: v14);
  v15 = *((GRefCountNTSImpl **)this + 60);
  if ( v15 != nullptr )
    GRefCountNTSImpl::Release(this: v15);
  v16 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
        + 54);
  if ( v16 != nullptr )
  {
    v4 = LODWORD(v16->m_pfnProxied)-- == 1;
    if ( v4 )
    {
      GFxFontHandle::~GFxFontHandle(this: v16);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
    }
  }
  v17 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
        + 52);
  if ( v17 != nullptr )
  {
    v4 = LODWORD(v17->m_pfnProxied)-- == 1;
    if ( v4 )
    {
      GFxFontHandle::~GFxFontHandle(this: v17);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v17);
    }
  }
  GHashSetBase<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeAltHashF,GAllocatorDH<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,324>,GHashsetNodeEntry<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF>>::~GHashSetBase<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeAltHashF,GAllocatorDH<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,324>,GHashsetNodeEntry<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF>>(a1: (void **)this + 47);
  v18 = *((IShaderAPI **)this + 31);
  if ( v18 != nullptr )
    GRefCountImpl::Release(this: v18);
  v19 = *((IShaderAPI **)this + 23);
  if ( v19 != nullptr )
    GRefCountImpl::Release(this: v19);
  v20 = *((GRefCountNTSImpl **)this + 11);
  if ( v20 != nullptr )
    GRefCountNTSImpl::Release(this: v20);
  v21 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
        + 5);
  if ( v21 != nullptr )
  {
    v4 = LODWORD(v21->m_pfnProxied)-- == 1;
    if ( v4 )
    {
      GFxFontHandle::~GFxFontHandle(this: v21);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016BF90
// Name: public: void GFxParagraphFormatter::Format(class GFxTextParagraph const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxParagraphFormatter::Format(GFxParagraphFormatter *this, GRefCountNTSImpl *a2)
{
  int v3; // eax
  int v4; // edi
  IShaderAPI *v5; // eax
  struct GFxFontHandle *Font; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v7; // ebx
  __int16 v8; // ax
  double ActualFontSize; // st7
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  bool v15; // zf
  unsigned int v16; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int *v21; // ebx
  IShaderAPI **v22; // eax
  GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *v23; // edi
  GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *v24; // eax
  GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *ImageDesc; // eax
  IShaderAPI **v26; // edx
  IShaderAPI *v27; // ecx
  GHash<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>,GAllocatorLH<unsigned __int64,2>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF>,GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > > *v28; // eax
  bool v29; // al
  int v30; // ecx
  bool v31; // al
  _DWORD *v32; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v33; // edi
  IShaderAPI **v34; // eax
  struct GFxFontHandle *v35; // eax
  struct GFxFontHandle *v36; // ebx
  double v37; // st7
  IShaderAPI **v38; // edx
  int v39; // ecx
  int v40; // eax
  int v41; // eax
  int v42; // ecx
  char v43; // al
  __int16 v44; // bx
  char **FontList; // eax
  int v46; // ecx
  int (__thiscall *v47)(int, unsigned __int8 *); // edx
  CImagePacker *v48; // eax
  unsigned int v49; // ebx
  unsigned int v50; // edi
  unsigned int v51; // ebx
  char **v52; // eax
  double v53; // st7
  double v54; // st6
  int v55; // eax
  int v56; // ecx
  double v57; // rt2
  double v58; // st6
  double v59; // st7
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **v60; // ecx
  double v61; // st5
  int v62; // eax
  double v63; // st5
  double v64; // st5
  double v65; // rt0
  double v66; // st5
  bool v67; // c0
  bool v68; // c3
  double v69; // st6
  double v70; // st7
  double v71; // st6
  double v72; // st5
  double v73; // st6
  double v74; // st5
  double v75; // st5
  double v76; // st7
  double v77; // st7
  int v78; // ecx
  int v79; // eax
  int v80; // edi
  GFxResourceId *v81; // eax
  int v82; // eax
  GFxResourceId *v83; // ecx
  int v84; // eax
  int v85; // eax
  __int16 v86; // dx
  double v87; // st7
  double v88; // st6
  int RefCount; // ecx
  double v90; // st6
  double v91; // st7
  int v92; // edx
  int v93; // edx
  int v94; // eax
  float v95; // ebx
  _DWORD *v96; // eax
  int v97; // ecx
  int v98; // ecx
  int v99; // eax
  int v100; // eax
  IShaderAPI **v101; // ecx
  __int16 v102; // ax
  int v103; // edx
  int v104; // ecx
  int v105; // eax
  _DWORD *v106; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v107; // ebx
  float v108; // edx
  int v109; // eax
  IShaderAPI **v110; // ebx
  unsigned int v111; // ecx
  int v112; // eax
  int v113; // ecx
  int v114; // eax
  double v115; // st7
  unsigned int v116; // eax
  int v117; // edx
  double v118; // st7
  int v119; // eax
  int v120; // ecx
  int v121; // eax
  unsigned int v122; // eax
  GFxParagraphFormatter *v123; // eax
  CUtlMemory<CImagePacker,int> result; // [esp+8h] [ebp-94h]
  const CIndexBufferBase *v125; // [esp+8h] [ebp-94h]
  int v126; // [esp+18h] [ebp-84h] BYREF
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v127; // [esp+1Ch] [ebp-80h] BYREF
  float v128; // [esp+34h] [ebp-68h]
  int v129; // [esp+38h] [ebp-64h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v130; // [esp+3Ch] [ebp-60h] BYREF
  bool v131[4]; // [esp+48h] [ebp-54h]
  int v132; // [esp+4Ch] [ebp-50h]
  int v133; // [esp+50h] [ebp-4Ch]
  CUtlMemory<CImagePacker,int> v134; // [esp+54h] [ebp-48h] BYREF
  int v135; // [esp+60h] [ebp-3Ch]
  int v136; // [esp+64h] [ebp-38h]
  float v137; // [esp+68h] [ebp-34h] BYREF
  float v138; // [esp+6Ch] [ebp-30h]
  float v139; // [esp+70h] [ebp-2Ch]
  float v140; // [esp+74h] [ebp-28h]
  int p; // [esp+78h] [ebp-24h] BYREF
  unsigned int nNextElement; // [esp+7Ch] [ebp-20h]
  GString v143; // [esp+80h] [ebp-1Ch] BYREF
  GString v144; // [esp+84h] [ebp-18h] BYREF
  float v145; // [esp+88h] [ebp-14h]
  unsigned int v146; // [esp+8Ch] [ebp-10h]
  IShaderAPI **v147; // [esp+90h] [ebp-Ch]
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v148; // [esp+94h] [ebp-8h]
  float pTable; // [esp+98h] [ebp-4h]
  float v150; // [esp+A4h] [ebp+8h]
  GRefCountNTSImpl *v151; // [esp+A4h] [ebp+8h]
  GRefCountNTSImpl *v152; // [esp+A4h] [ebp+8h]

  v146 = 0;
  GFxParagraphFormatter::InitParagraph(this, (IGameEvent *)a2);
  v3 = *((_DWORD *)this + 2);
  *((_DWORD *)this + 35) = 0;
  if ( (*(_WORD *)(v3 + 22) & 0x80u) != 0 && (*(_WORD *)(v3 + 22) & 0x8000) != 0 )
  {
    v4 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
    *(_DWORD *)(v4 + 4) = 0;
    v5 = *GFxLineCursor::operator*(this: (int)this + 16);
    *((_DWORD *)this + 50) = v5;
    if ( v5 != nullptr )
    {
      result.m_pMemory = nullptr;
      Font = GFxTextDocView::FindFont(
               this: *(GFxTextDocView **)this,
               a2: (GFxParagraphFormatter *)((char *)this + 196),
               a3: result);
      v7 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)Font;
      if ( Font != nullptr )
        ++*(_DWORD *)Font;
      v8 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(*((_DWORD *)Font + 7) + 12) + 12))(
             a1: *(_DWORD *)(*((_DWORD *)Font + 7) + 12),
             a2: 8226);
      *(_WORD *)(v4 + 6) &= ~0x40u;
      *(_WORD *)v4 = v8;
      *(_WORD *)(v4 + 2) = 300;
      ActualFontSize = GFxParagraphFormatter::GetActualFontSize(this);
      v150 = (ActualFontSize + ActualFontSize) / 3.0;
      GFxTextLineBuffer::GlyphEntry::SetFontSize(this: (_WORD *)v4, result: (const CIndexBufferBase *)LODWORD(v150));
      *(_WORD *)(v4 + 4) &= 0xFFFu;
      v10 = *(_DWORD *)(*((_DWORD *)this + 50) + 32);
      v11 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
      *(_WORD *)(v11 + 6) |= 0x4000u;
      v12 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
      *(_WORD *)(v12 + 6) |= 0x2000u;
      *(_DWORD *)(*((_DWORD *)this + 38) + 4 * (*((_DWORD *)this + 41))++) = v7;
      ++LODWORD(v7->m_pfnProxied);
      v13 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
      *(_WORD *)(v13 + 6) |= 0x4000u;
      v14 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
      *(_WORD *)(v14 + 6) |= 0x1000u;
      *(_DWORD *)(*((_DWORD *)this + 38) + 4 * (*((_DWORD *)this + 41))++) = v10;
      v15 = *((_DWORD *)this + 37) == 0;
      v129 = v10;
      if ( !v15 )
      {
        v16 = *((_DWORD *)this + 39);
        if ( v16 < *((_DWORD *)this + 40) )
          *((_DWORD *)this + 39) = v16 + 1;
      }
      ++LODWORD(v7->m_pfnProxied);
      v17 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
            + 5);
      v151 = (GRefCountNTSImpl *)v17;
      if ( v17 != nullptr )
      {
        v15 = LODWORD(v17->m_pfnProxied)-- == 1;
        if ( v15 )
        {
          GFxFontHandle::~GFxFontHandle(this: v17);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v151);
        }
      }
      *((_DWORD *)this + 5) = v7;
      *((_DWORD *)this + 10) = v10;
      v15 = LODWORD(v7->m_pfnProxied)-- == 1;
      if ( v15 )
      {
        GFxFontHandle::~GFxFontHandle(this: v7);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
      }
    }
    *((_DWORD *)this + 35) = 700;
    *((_DWORD *)this + 17) = 700;
    *((_DWORD *)this + 34) = -300;
  }
  else
  {
    *((_DWORD *)this + 34) = 20 * *(__int16 *)(v3 + 14);
  }
  v18 = *((_DWORD *)this + 2);
  *((_DWORD *)this + 35) += 20 * (*(unsigned __int16 *)(v18 + 12) + *(unsigned __int16 *)(v18 + 18));
  *((_DWORD *)this + 36) = 20 * *(unsigned __int16 *)(v18 + 20);
  GFxTextParagraphFormat::GetTabStops(
    this: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v18,
    pnum: (const CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)((char *)this + 732));
  v135 = v19;
  v152 = nullptr;
  while ( 1 )
  {
    v20 = *((_DWORD *)this + 29);
    if ( v20 == 0 || *((_DWORD *)this + 30) >= *(_DWORD *)(v20 + 4) )
      break;
    v21 = (int *)((char *)this + 16);
    v22 = GFxLineCursor::operator*(this: (int)this + 16);
    v147 = v22;
    if ( *((_DWORD *)this + 186) == 1 )
    {
      if ( (*(_BYTE *)(*(_DWORD *)this + 334) & 8) != 0
        && v152 == nullptr
        && GFxWWHelper::IsLineBreakOpportunityAt(
             wwMode: 7,
             prevChar: *((_WORD *)this + 12),
             curChar: *((_WORD *)v22 + 4)) )
      {
        GFxLineCursor::operator=(this: (char *)this + 556, a2: (int)this + 16);
      }
      if ( *((_DWORD *)this + 186) == 1 && *((_BYTE *)this + 756) != 0 )
      {
        v15 = *((_DWORD *)this + 17) == 0;
        v148 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
               + 182);
        if ( v15 && *((_DWORD *)this + 64) == 0 )
          GFxLineCursor::operator=(this: (char *)this + 212, a2: (int)this + 16);
        if ( *(float *)&v148 * 0.5 < (double)*((int *)this + 17) && *((_DWORD *)this + 107) == 0 )
          GFxLineCursor::operator=(this: (char *)this + 384, a2: (int)this + 16);
      }
    }
    *((_DWORD *)this + 185) = 1;
    if ( v152 != nullptr )
      GRefCountNTSImpl::Release(this: v152);
    v23 = nullptr;
    v152 = nullptr;
    if ( *(_DWORD *)(*(_DWORD *)this + 24) != 0 )
    {
      GFxTextParagraph::CharactersIterator::GetRemainingTextPtr(
        this: (GFxImportVisitor *)((char *)this + 92),
        plen: (unsigned int *)&v134.m_nAllocationCount);
      ImageDesc = GFxTextDocView::ImageSubstitutor::FindImageDesc(
                    this: *(_DWORD **)(*(_DWORD *)this + 24),
                    result: v24,
                    a3: v134.m_nAllocationCount,
                    ptextLen: (unsigned int *)&v134.m_nGrowSize);
      if ( ImageDesc != nullptr )
        ++ImageDesc[1].Hash.pTable;
      v23 = ImageDesc;
      v152 = (GRefCountNTSImpl *)ImageDesc;
      if ( ImageDesc != nullptr )
      {
        *((_DWORD *)this + 185) = v134.m_nGrowSize;
LABEL_47:
        v26 = v147;
        goto LABEL_48;
      }
    }
    v26 = v147;
    v27 = *v147;
    if ( *v147 != nullptr && (HIWORD(v27[10].__vftable) & 0x200) != 0 && *((_WORD *)v147 + 4) != 0 )
    {
      GFxTextFormat::GetImageDesc(this: (CMemberFuncProxy3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CFuncMemPolicyNone> *)v27);
      v23 = v28;
      if ( v28 != nullptr )
        ++v28[1].Hash.pTable;
      if ( v152 != nullptr )
        GRefCountNTSImpl::Release(this: v152);
      v152 = (GRefCountNTSImpl *)v23;
      goto LABEL_47;
    }
LABEL_48:
    *((_DWORD *)this + 320) = 0;
    *((float *)this + 322) = 1.0;
    *((float *)this + 329) = -1.0;
    if ( v23 != nullptr )
    {
      *((_DWORD *)this + 50) = *v26;
      pTable = (float)(unsigned int)v23[6].Hash.pTable;
      v71 = pTable;
      if ( pTable <= 0.0 )
      {
        v74 = v71 - 0.5;
        v73 = 0.5;
        v33 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)(int)v74;
        v148 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)(int)v74;
      }
      else
      {
        v72 = v71 + 0.5;
        v73 = 0.5;
        v33 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)(int)v72;
        v148 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)(int)v72;
      }
      v75 = (double)(int)v148;
      *((_DWORD *)this + 326) = v33;
      *((float *)this + 324) = v75 + 40.0;
      pTable = *((float *)this + 8);
      v76 = pTable;
      if ( pTable <= 0.0 )
        v77 = v76 - v73;
      else
        v77 = v76 + v73;
      *((_DWORD *)this + 325) = (int)v77;
      *((_DWORD *)this + 327) = v33;
      *((_DWORD *)this + 323) = -1;
      *((_WORD *)this + 660) = 0;
      goto LABEL_117;
    }
    v29 = *((_WORD *)v26 + 4) == 160;
    *((_BYTE *)this + 1321) = v29;
    v30 = *((unsigned __int16 *)v26 + 4);
    v31 = (_WORD)v30 == 0 || !v29 && (v30 == 9 || v30 == 13 || v30 == 32 || *((_WORD *)v26 + 4) == 12288);
    v15 = *((_DWORD *)this + 52) == 0;
    *((_BYTE *)this + 1320) = v31;
    if ( !v15 && *((IShaderAPI **)this + 50) == *v26 )
    {
      v32 = *((_DWORD **)this + 52);
      if ( v32 != nullptr )
        ++*v32;
      v33 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
            + 321);
      if ( v33 != nullptr )
      {
        v15 = LODWORD(v33->m_pfnProxied)-- == 1;
        if ( v15 )
        {
          GFxFontHandle::~GFxFontHandle(this: v33);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v33);
        }
      }
      *((_DWORD *)this + 321) = *((_DWORD *)this + 52);
LABEL_71:
      *((_DWORD *)this + 320) = *(_DWORD *)(*((_DWORD *)this + 321) + 28);
      *(float *)&v148 = GFxParagraphFormatter::GetActualFontSize(this);
      v37 = *(float *)&v148;
      v38 = v147;
      v39 = *(_DWORD *)this;
      *((float *)this + 329) = *(float *)&v148;
      *(float *)&v148 = v37 * 20.0;
      *((float *)this + 322) = *(float *)&v148 * 0.0009765625;
      v40 = *((unsigned __int16 *)v38 + 4);
      if ( (_WORD)v40 == (unsigned __int8)((*(_BYTE *)(*(_DWORD *)(v39 + 8) + 32) & 2) != 0 ? 13 : 10)
        || (_WORD)v40 == 0 )
      {
        v55 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(*((_DWORD *)this + 320) + 12) + 12))(
                a1: *(_DWORD *)(*((_DWORD *)this + 320) + 12),
                a2: 32);
        v56 = *((_DWORD *)this + 320);
        *((_DWORD *)this + 323) = v55;
        pTable = ((double (__thiscall *)(_DWORD, int))*(_DWORD *)(**(_DWORD **)(v56 + 12) + 32))(
                   a1: *(_DWORD *)(v56 + 12),
                   a2: v55);
        *((float *)this + 324) = pTable * 0.5 * *((float *)this + 322);
        v54 = 0.5;
        v53 = 0.0;
      }
      else if ( v40 == 9 )
      {
        v53 = 0.0;
        *((_DWORD *)this + 323) = -1;
        *((float *)this + 324) = 0.0;
        v54 = 0.5;
      }
      else
      {
        v41 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(*((_DWORD *)this + 320) + 12) + 12))(
                a1: *(_DWORD *)(*((_DWORD *)this + 320) + 12),
                a2: v40);
        *((_DWORD *)this + 323) = v41;
        if ( v41 == -1 && *((_DWORD *)this + 591) != 0 && (*(_BYTE *)(*(_DWORD *)this + 336) & 0x10) == 0 )
        {
          v126 = 1;
          GStringBuffer::GStringBuffer(
            this: &v127,
            result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
          v42 = *((_DWORD *)this + 50);
          v43 = *(_BYTE *)(v42 + 40);
          v44 = *(_WORD *)(v42 + 42);
          LOBYTE(v132) = (*(_BYTE *)(*(_DWORD *)this + 334) & 0x20) != 0;
          LOBYTE(v136) = (v43 & 2) != 0;
          LOBYTE(v133) = v43 & 1;
          FontList = GFxTextFormat::GetFontList(this: (char **)v42);
          *(float *)&v148 = COERCE_FLOAT(
                              GFxFontManager::CreateFontHandle(
                                this: *(CDefaultClientRenderable **)(*(_DWORD *)this + 12),
                                result: (const CDefaultClientRenderable *)(((unsigned int)*FontList & 0xFFFFFFFC) + 8),
                                bold: v133,
                                italic: v136,
                                device: v132,
                                allowListOfFonts: (v44 & 0x1000) == 0,
                                searchInfo: (IScaleformUIFunctionHandlerDefinitionTable)&v126));
          v46 = *(_DWORD *)(*(_DWORD *)this + 16);
          if ( v46 != 0 )
          {
            v47 = *(int (__thiscall **)(int, unsigned __int8 *))(*(_DWORD *)v46 + 36);
            v146 |= 1u;
            v48 = (CImagePacker *)v47(a1: v46, a2: &v130.nReferenceCount);
          }
          else
          {
            v146 |= 2u;
            GString::GString(this: &v134);
          }
          GString::GString(this: (CCountedStringPoolBase<unsigned int> *)&v144, result: v48);
          v49 = v146;
          if ( (v146 & 2) != 0 )
          {
            v49 = v146 & 0xFFFFFFFD;
            v146 &= ~2u;
            GString::~GString(this: (GString *)&v134);
          }
          if ( (v49 & 1) != 0 )
          {
            v146 = v49 & 0xFFFFFFFE;
            GString::~GString(this: (GString *)&v130.nReferenceCount);
          }
          (*(void (__thiscall **)(_DWORD, GString *))(**(_DWORD **)(*((_DWORD *)this + 320) + 12) + 68))(
            a1: *(_DWORD *)(*((_DWORD *)this + 320) + 12),
            a2: &v143);
          pTable = COERCE_FLOAT((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*((_DWORD *)this + 320) + 12) + 56))(a1: *(_DWORD *)(*((_DWORD *)this + 320) + 12)));
          v145 = *(float *)&v127.m_pfnProxied;
          if ( LODWORD(v127.m_pfnProxied) == 0 )
            v145 = COERCE_FLOAT(&pMem);
          v50 = v143.HeapTypeBits & 0xFFFFFFFC;
          v51 = v144.HeapTypeBits & 0xFFFFFFFC;
          v52 = GFxTextFormat::GetFontList(this: *((char ***)this + 50));
          v33 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)(v50 + 8);
          GFxLogBase<GFxLog>::LogError(
            this: (GFxLogBase<GFxLog> *)(*((_DWORD *)this + 591) + 12),
            pfmt: "Missing \"%s\" glyph '%c' (0x%x) in \"%s\".\nFont has %u glyphs, ranges %s.\nSearch log: \n%s",
            (const char *)(((unsigned int)*v52 & 0xFFFFFFFC) + 8),
            *((char *)v147 + 8),
            *((unsigned __int16 *)v147 + 4),
            (const char *)(v51 + 8),
            pTable,
            (const char *)v33,
            (const char *)LODWORD(v145));
          *(_BYTE *)(*(_DWORD *)this + 336) |= 0x10u;
          GString::~GString(this: &v143);
          GString::~GString(this: &v144);
          if ( *(float *)&v148 != 0.0 )
          {
            v33 = v148;
            v15 = LODWORD(v148->m_pfnProxied)-- == 1;
            if ( v15 )
            {
              GFxFontHandle::~GFxFontHandle(this: v33);
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v33);
            }
          }
          GStringBuffer::~GStringBuffer(this: &v127);
        }
        pTable = ((double (__thiscall *)(_DWORD, _DWORD))*(_DWORD *)(**(_DWORD **)(*((_DWORD *)this + 320) + 12) + 32))(
                   a1: *(_DWORD *)(*((_DWORD *)this + 320) + 12),
                   a2: *((_DWORD *)this + 323));
        *((float *)this + 324) = pTable * *((float *)this + 322);
        v53 = 0.0;
        v54 = 0.5;
      }
      v21 = (int *)((char *)this + 16);
      if ( *((_DWORD *)this + 4) != 0 )
      {
        v15 = *((_BYTE *)this + 180) == 0;
        v57 = v54;
        v58 = v53;
        v59 = v57;
        *(float *)&v148 = v58;
        if ( !v15 )
        {
          if ( *v21 != 0 )
          {
            v60 = *(CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> ***)(*(_DWORD *)(*((_DWORD *)this + 5) + 28) + 12);
            v33 = *v60;
            *(float *)&v148 = ((double (__thiscall *)(CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **, _DWORD, _DWORD))HIDWORD((*v60)[1].m_pfnProxied))(
                                a1: v60,
                                a2: *((_DWORD *)this + 6),
                                a3: *((unsigned __int16 *)v147 + 4));
            v58 = 0.0;
            v59 = 0.5;
          }
          else
          {
            *(float *)&v148 = v58;
          }
          *(float *)&v148 = *(float *)&v148 * *((float *)this + 322);
        }
        pTable = *((float *)this + 8) + *(float *)&v148;
        v61 = pTable;
        if ( pTable <= v58 )
          v62 = (int)(v61 - v59);
        else
          v62 = (int)(v61 + v59);
      }
      else
      {
        pTable = *((float *)this + 8);
        v63 = pTable;
        if ( pTable <= v53 )
          v64 = v63 - v54;
        else
          v64 = v63 + v54;
        v62 = (int)v64;
        v65 = v54;
        v58 = v53;
        v59 = v65;
      }
      v66 = *((float *)this + 324);
      *((_DWORD *)this + 325) = v62;
      pTable = v66;
      v67 = pTable < v58;
      v68 = pTable == v58;
      v69 = pTable;
      if ( v67 || v68 )
        v70 = v69 - v59;
      else
        v70 = v59 + v69;
      v15 = *((_BYTE *)this + 1320) == 0;
      *((_DWORD *)this + 326) = (int)v70;
      *((_DWORD *)this + 327) = !v15 ? 0 : (int)v70;
LABEL_117:
      *((_DWORD *)this + 328) = *((_DWORD *)this + 17) + *((_DWORD *)this + 325);
      if ( GFxParagraphFormatter::CheckWordWrap(
             (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)this,
             a2: (unsigned int)v33) != 0 )
        goto LABEL_187;
      v78 = *v21;
      if ( *v21 != 0 )
      {
        v79 = *((_DWORD *)this + 325);
        if ( v79 < 0 )
        {
          LOWORD(v79) = abs32(v79);
          *(_WORD *)(v78 + 6) |= 0x40u;
        }
        else
        {
          *(_WORD *)(v78 + 6) &= ~0x40u;
        }
        *(_WORD *)(v78 + 2) = v79;
      }
      v80 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
      *(_DWORD *)(v80 + 4) = 0;
      *(_WORD *)v80 = *((_WORD *)this + 646);
      v81 = (GFxResourceId *)v21[7];
      if ( v81 != nullptr && GFxTextParagraph::GetLength(this: v81 + 5) != 0 )
      {
        v82 = GFxTextParagraph::CharactersIterator::operator*(this: (int)(v21 + 19));
        v83 = (GFxResourceId *)v21[7];
        if ( *(_DWORD *)(v82 + 4) + *(_DWORD *)(v21[12] + 28) >= v83[12].Id
          && v21[10] < GFxTextParagraph::GetLength(this: v83 + 5) )
        {
          *(_WORD *)(v80 + 6) |= 4u;
        }
      }
      if ( v152 != nullptr )
      {
        v84 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
        *(_WORD *)(v84 + 6) |= 0x4000u;
        v85 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
        *(_WORD *)(v85 + 6) |= 0x800u;
        *(_DWORD *)(*((_DWORD *)this + 38) + 4 * (*((_DWORD *)this + 41))++) = v152;
        ++v152->RefCount;
        *(float *)&p = 0.0;
        v86 = *(_WORD *)(v80 + 4);
        *(float *)&nNextElement = 0.0;
        *(_WORD *)(v80 + 4) = (*((_WORD *)this + 370) << 12) | v86 & 0xFFF;
        *((_BYTE *)this + 180) = 0;
        GMatrix2D::Transform(
          this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v152[4],
          result: &v130,
          (float *)&p,
          p_4: result.m_nAllocationCount);
        p = (int)v130.pString;
        nNextElement = v130.nNextElement;
        v148 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
               + 20);
        pTable = -*(float *)&v130.nNextElement;
        v87 = pTable;
        v88 = pTable;
        if ( *(float *)&v148 > (double)pTable )
          v88 = *(float *)&v148;
        *(float *)&v148 = v88;
        *((float *)this + 20) = *(float *)&v148;
        RefCount = v152[3].RefCount;
        v148 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
               + 21);
        v90 = (double)(int)v152[3].RefCount;
        if ( RefCount < 0 )
          v90 = v90 + 4294967300.0;
        pTable = v90 - v87;
        v91 = pTable;
        if ( *(float *)&v148 > (double)pTable )
          v91 = *(float *)&v148;
        v92 = *((_DWORD *)this + 328);
        *(float *)&v148 = v91;
        v93 = *((_DWORD *)this + 327) + v92;
        v94 = *((_DWORD *)this + 50);
        *((float *)this + 21) = *(float *)&v148;
        *((_DWORD *)this + 43) = 0;
        *((_DWORD *)this + 18) = v93;
        if ( (*(_WORD *)(v94 + 42) & 0x100) != 0 && GString::GetLength(this: (GString *)(v94 + 16)) != 0 )
          *(_WORD *)(v80 + 6) |= 0x80u;
        else
          *(_WORD *)(v80 + 6) &= ~0x80u;
        goto LABEL_176;
      }
      v95 = *(float *)(*((_DWORD *)this + 50) + 32);
      v125 = *((const CIndexBufferBase **)this + 329);
      pTable = v95;
      GFxTextLineBuffer::GlyphEntry::SetFontSize(this: (_WORD *)v80, result: v125);
      v96 = *((_DWORD **)this + 321);
      if ( v96 != *((_DWORD **)this + 5) )
      {
        v97 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
        *(_WORD *)(v97 + 6) |= 0x4000u;
        v98 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
        *(_WORD *)(v98 + 6) |= 0x2000u;
        *(_DWORD *)(*((_DWORD *)this + 38) + 4 * (*((_DWORD *)this + 41))++) = v96;
        ++*v96;
      }
      if ( LODWORD(v95) != *((_DWORD *)this + 10) )
      {
        v99 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
        *(_WORD *)(v99 + 6) |= 0x4000u;
        v100 = *((_DWORD *)this + 37) + 8 * *((_DWORD *)this + 39);
        *(_WORD *)(v100 + 6) |= 0x1000u;
        *(float *)(*((_DWORD *)this + 38) + 4 * (*((_DWORD *)this + 41))++) = v95;
        v128 = v95;
      }
      v101 = v147;
      v102 = *((_WORD *)v147 + 4);
      if ( v102 == (unsigned __int8)((*(_BYTE *)(*(_DWORD *)(*(_DWORD *)this + 8) + 32) & 2) != 0 ? 13 : 10) )
      {
        if ( v102 == 0 )
          goto LABEL_159;
        *(_WORD *)(v80 + 4) = *(_WORD *)(v80 + 4) & 0xFFF | 0x1000;
      }
      else
      {
        if ( v102 != 0 )
        {
          if ( *((_BYTE *)this + 1320) == 0 && *((_BYTE *)this + 1321) == 0 )
          {
            *((_DWORD *)this + 18) = *((_DWORD *)this + 327) + *((_DWORD *)this + 328);
            goto LABEL_156;
          }
          *(_WORD *)(v80 + 6) |= 2u;
          v103 = *((_DWORD *)this + 323);
          if ( v103 >= 0 )
          {
            v104 = *((_DWORD *)this + 320);
            v137 = 0.0;
            v138 = 0.0;
            v139 = 0.0;
            v140 = 0.0;
            (*(void (__thiscall **)(_DWORD, int, float *))(**(_DWORD **)(v104 + 12) + 48))(
              a1: *(_DWORD *)(v104 + 12),
              a2: v103,
              a3: &v137);
            if ( v139 <= (double)v137 || v140 <= (double)v138 )
              *(_WORD *)(v80 + 6) |= 0x200u;
          }
          else
          {
            *(_WORD *)(v80 + 6) |= 0x200u;
          }
          ++*((_DWORD *)this + 42);
          if ( *((_BYTE *)this + 1320) != 0 )
          {
            ++*((_DWORD *)this + 43);
          }
          else
          {
            *((_DWORD *)this + 18) = *((_DWORD *)this + 327) + *((_DWORD *)this + 328);
LABEL_156:
            *((_DWORD *)this + 43) = 0;
          }
          *(_WORD *)(v80 + 4) = *(_WORD *)(v80 + 4) & 0xFFF | 0x1000;
          GFxLineCursor::TrackFontParams(
            this: (GFxParagraphFormatter *)((char *)this + 16),
            a2: *((struct GFxFontResource **)this + 320),
            a3: *((float *)this + 322));
LABEL_163:
          if ( (*(_BYTE *)(*((_DWORD *)this + 50) + 40) & 4) != 0 )
            *(_WORD *)(v80 + 6) |= 0x400u;
          else
            *(_WORD *)(v80 + 6) &= ~0x400u;
          v105 = *((_DWORD *)this + 50);
          if ( (*(_WORD *)(v105 + 42) & 0x100) != 0 && GString::GetLength(this: (GString *)(v105 + 16)) != 0 )
            *(_WORD *)(v80 + 6) |= 0x80u;
          else
            *(_WORD *)(v80 + 6) &= ~0x80u;
          v106 = *((_DWORD **)this + 321);
          if ( v106 != nullptr )
            ++*v106;
          v107 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
                 + 5);
          if ( v107 != nullptr )
          {
            v15 = LODWORD(v107->m_pfnProxied)-- == 1;
            if ( v15 )
            {
              GFxFontHandle::~GFxFontHandle(this: v107);
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v107);
            }
          }
          v108 = pTable;
          *((_DWORD *)this + 5) = *((_DWORD *)this + 321);
          v109 = *((_DWORD *)this + 50);
          *((float *)this + 10) = v108;
          *((_BYTE *)this + 180) = (*(_BYTE *)(v109 + 40) & 8) != 0;
LABEL_176:
          v110 = v147;
          if ( *((_WORD *)v147 + 4) == 9 )
          {
            v111 = *((_DWORD *)this + 184);
            if ( v111 >= *((_DWORD *)this + 183) )
            {
              pTable = (*((float *)this + 329) + *((float *)this + 329) + 8.0) * 0.125;
              pTable = floor(X: pTable);
              pTable = pTable * 8.0;
              *(float *)&v148 = pTable * 20.0;
              v145 = (float)*((int *)this + 328);
              pTable = (*(float *)&v148 + v145) / *(float *)&v148;
              pTable = floor(X: pTable);
              pTable = pTable * *(float *)&v148;
              v115 = pTable - v145;
LABEL_181:
              *((float *)this + 324) = v115;
            }
            else
            {
              v112 = 5 * *(_DWORD *)(v135 + 4 * v111);
              *((_DWORD *)this + 184) = v111 + 1;
              v113 = *((_DWORD *)this + 328);
              v114 = 4 * v112;
              if ( v114 > v113 )
              {
                LODWORD(pTable) = v114 - v113;
                v115 = (double)(v114 - v113);
                goto LABEL_181;
              }
            }
          }
          v116 = *(unsigned __int16 *)(v80 + 4);
          v117 = *((_DWORD *)this + 328);
          pTable = *((float *)this + 324);
          v118 = pTable;
          *((_DWORD *)this + 19) += v116 >> 12;
          v119 = *((_DWORD *)this + 323);
          *((_DWORD *)this + 4) = v80;
          v120 = *((unsigned __int16 *)v110 + 4);
          *((float *)this + 8) = v118;
          *((_DWORD *)this + 7) = v119;
          v121 = *((_DWORD *)this + 50);
          *((_DWORD *)this + 6) = v120;
          *((_DWORD *)this + 17) = v117;
          if ( (*(_BYTE *)(v121 + 42) & 2) != 0 )
          {
            LODWORD(pTable) = *(__int16 *)(v121 + 36);
            pTable = (double)SLODWORD(pTable) / 20.0;
            pTable = 20.0 * pTable;
            *((float *)this + 8) = v118 + pTable;
          }
          *((_DWORD *)this + 9) = *((_DWORD *)this + 326);
          if ( *((_DWORD *)this + 37) != 0 )
          {
            v122 = *((_DWORD *)this + 39);
            if ( v122 < *((_DWORD *)this + 40) )
              *((_DWORD *)this + 39) = v122 + 1;
          }
          goto LABEL_187;
        }
LABEL_159:
        *(_WORD *)(v80 + 4) &= 0xFFFu;
      }
      *(_WORD *)(v80 + 6) |= 0x300u;
      *((_DWORD *)this + 326) = 0;
      *((_BYTE *)this + 181) = 1;
      if ( v101[1] == nullptr )
        GFxLineCursor::TrackFontParams(
          this: (GFxParagraphFormatter *)((char *)this + 16),
          a2: *((struct GFxFontResource **)this + 320),
          a3: *((float *)this + 322));
      goto LABEL_163;
    }
    v34 = v147;
    *((_DWORD *)this + 50) = *v147;
    v131[0] = *((_WORD *)v34 + 4) == 0;
    result.m_pMemory = *(CImagePacker **)v131;
    v35 = GFxTextDocView::FindFont(
            this: *(GFxTextDocView **)this,
            a2: (GFxParagraphFormatter *)((char *)this + 196),
            a3: result);
    v36 = v35;
    if ( v35 != nullptr )
      ++*(_DWORD *)v35;
    v33 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
          + 321);
    if ( v33 != nullptr )
    {
      v15 = LODWORD(v33->m_pfnProxied)-- == 1;
      if ( v15 )
      {
        GFxFontHandle::~GFxFontHandle(this: v33);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v33);
      }
    }
    *((_DWORD *)this + 321) = v36;
    if ( v36 != nullptr )
      goto LABEL_71;
LABEL_187:
    GFxLineCursor::operator+=(this: (_DWORD *)this + 4, a2: *((_DWORD *)this + 185));
  }
  if ( *((_DWORD *)this + 3) != 0 )
    GFxParagraphFormatter::FinalizeLine(this);
  v123 = *((GFxParagraphFormatter **)this + 318);
  if ( v123 != nullptr && v123 != (GFxParagraphFormatter *)((char *)this + 758) )
  {
    GFxStyledText::GetAllocator(this: *(SFTextObjectImpl **)(*(_DWORD *)this + 8));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 318));
  }
  if ( v152 != nullptr )
    GRefCountNTSImpl::Release(this: v152);
}

//------------------------------------------------------------------------------
// Address: 0x1016CF70
// Name: public: void GFxTextDocView::Format(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxTextDocView::Format(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>)
{
  int MaxHScrollValue; // eax
  int v3; // edx
  int v4; // ecx
  bool v5; // zf
  char v6; // dl
  double v7; // st7
  CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v8; // ebx
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v9; // edi
  IMaterialVar *v10; // eax
  char *v11; // ecx
  __int16 v12; // cx
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *pTable; // eax
  float v14; // eax
  int v15; // eax
  IMaterialVar *v16; // esi
  char *m_pStringVal; // edi
  bool v18; // cl
  IMaterialVar_vtbl *m_intVal_high; // eax
  int z_low; // eax
  unsigned int Length; // eax
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v22; // ebx
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v23; // eax
  float w; // eax
  float v25; // ecx
  int m_intVal_low; // eax
  int v27; // edi
  double v28; // st6
  double v29; // st6
  float v30; // eax
  double v31; // st7
  double v32; // st7
  double v33; // st6
  float z; // ecx
  int m_intVal; // edx
  bool v36; // cl
  int v37; // edi
  char *v38; // eax
  int i; // esi
  int *v40; // edx
  int v41; // edx
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v42; // eax
  float v43; // esi
  char *v44; // edx
  __int16 v45; // ax
  int v46; // edx
  int j; // esi
  int *v48; // eax
  int v49; // eax
  GFxResourceId *v50; // esi
  int v51; // eax
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v52; // eax
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v53; // eax
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v54; // ecx
  char v55; // dl
  char v56; // bl
  unsigned __int8 v57; // al
  int v58; // esi
  int v59; // eax
  double v60; // st5
  double v61; // st4
  double v62; // st6
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v63; // ebx
  double v64; // st6
  int v65; // eax
  double v66; // st4
  double v67; // st7
  int v68; // eax
  double v69; // st6
  double v70; // st6
  double v71; // st5
  double v72; // st4
  int v73; // esi
  int v74; // esi
  int v75; // ecx
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v76; // edx
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v77; // ebx
  int *v78; // esi
  int v79; // edi
  double v80; // st5
  double v81; // st5
  int v82; // eax
  int v83; // eax
  double v84; // st5
  double v85; // st5
  int v86; // ecx
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v87; // ecx
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v88; // esi
  unsigned int v89; // eax
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v90; // ecx
  const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v91; // esi
  bool v92; // bl
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v93; // edi
  unsigned int v94; // eax
  int v95; // ecx
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v96; // edi
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v97; // ecx
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v98; // edi
  unsigned int MaxVScroll; // eax
  const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v100; // esi
  unsigned int v101; // eax
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v102; // ecx
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v103; // ecx
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v104; // ecx
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v105; // eax
  double v106; // st7
  double v107; // st7
  GFxTextHighlighter *v108; // ecx
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v109; // eax
  const struct GFxTextCompositionString *v110; // eax
  CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > **v111; // edx
  CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *v112; // eax
  int v113; // ecx
  int v114; // eax
  struct GFxLog *v115; // [esp+0h] [ebp-9C8h]
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v116; // [esp+4h] [ebp-9C4h]
  int v117; // [esp+10h] [ebp-9B8h]
  float x; // [esp+14h] [ebp-9B4h]
  float v119; // [esp+1Ch] [ebp-9ACh]
  float v120; // [esp+20h] [ebp-9A8h]
  int v121; // [esp+20h] [ebp-9A8h]
  float v122; // [esp+24h] [ebp-9A4h]
  float v123; // [esp+28h] [ebp-9A0h]
  CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v124[2]; // [esp+2Ch] [ebp-99Ch] BYREF
  int v125; // [esp+34h] [ebp-994h]
  float v126; // [esp+38h] [ebp-990h]
  bool v127; // [esp+3Ch] [ebp-98Ch]
  float v128; // [esp+40h] [ebp-988h]
  int v129; // [esp+44h] [ebp-984h]
  float y; // [esp+48h] [ebp-980h]
  float v131; // [esp+4Ch] [ebp-97Ch]
  char v132; // [esp+53h] [ebp-975h]
  int v133; // [esp+54h] [ebp-974h]
  int v134; // [esp+58h] [ebp-970h] BYREF
  float v135; // [esp+5Ch] [ebp-96Ch]
  __int64 v136; // [esp+60h] [ebp-968h]
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v137; // [esp+68h] [ebp-960h]
  GFxResourceId *v138; // [esp+6Ch] [ebp-95Ch]
  float v139; // [esp+70h] [ebp-958h]
  _BYTE v140[1324]; // [esp+74h] [ebp-954h] BYREF
  CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > **v141; // [esp+5A0h] [ebp-428h]
  float v142; // [esp+9A8h] [ebp-20h]
  float v143; // [esp+9ACh] [ebp-1Ch]
  int v144; // [esp+9B4h] [ebp-14h]
  int v145; // [esp+9B8h] [ebp-10h]
  char v146; // [esp+9C0h] [ebp-8h]
  char v147; // [esp+9C1h] [ebp-7h]

  v137 = this;
  MaxHScrollValue = GFxTextDocView::GetMaxHScrollValue((GFxTextDocView *)this);
  v5 = (*(_BYTE *)(v4 + 332) & 0x30) == 0;
  v117 = MaxHScrollValue;
  v128 = *(float *)(v4 + 276);
  if ( !v5 )
    *(_BYTE *)(v4 + 336) |= 2u;
  v126 = 0.0;
  v136 = (unsigned int)(v3 + 12);
  v6 = *(_BYTE *)(v4 + 152);
  v116 = a2;
  v124[0] = (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)(v4 + 36);
  v115 = *(struct GFxLog **)(v4 + 324);
  v124[1] = nullptr;
  v125 = 0;
  v127 = (v6 & 4) != 0;
  GFxParagraphFormatter::GFxParagraphFormatter(
    this: (GFxParagraphFormatter *)v140,
    a2: (struct GFxTextDocView *)v4,
    a3: v115);
  v7 = 0.5;
  v8 = v124[0];
  v133 = 0;
  v129 = 0;
LABEL_4:
  v9 = v137;
  while ( (_DWORD)v136 != 0 && v136 >= 0 && SHIDWORD(v136) < *(_DWORD *)(v136 + 4) )
  {
    v138 = *(GFxResourceId **)(*(_DWORD *)v136 + 4 * HIDWORD(v136));
    if ( v8 == nullptr || (unsigned int)v125 >= v8->m_Memory.m_nAllocationCount || v125 < 0 )
      goto LABEL_113;
    v10 = v8->m_Memory.m_pMemory[v125];
    if ( ((int)v9[84].pTable & 2) == 0 )
    {
      v11 = (int)v10->__vftable >= 0 ? *((char **)v10 + 7) : v10->m_pStringVal;
      if ( (char *)v138[8].Id == v11 )
      {
        v12 = (int)v10->__vftable >= 0 ? LOWORD(v10[1].m_pStringVal) : LOWORD(v10->m_VecVal.w);
        if ( LOWORD(v138[9].Id) == v12 )
        {
          pTable = (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v9[71].pTable;
          if ( pTable != nullptr )
          {
            GFxTextEditorKit::TextPos2GlyphOffset(this: pTable, textPos: (void *)v138[7].Id, a3: v116);
            v7 = 0.5;
            v8 = v124[0];
            v131 = v14;
          }
          else
          {
            v131 = *(float *)&v138[7].Id;
          }
          v15 = v125;
          while ( 1 )
          {
            if ( v8 == nullptr
              || (unsigned int)v15 >= v8->m_Memory.m_nAllocationCount
              || v15 < 0
              || ((int)(v16 = v8->m_Memory.m_pMemory[v15])->__vftable >= 0
                ? (m_pStringVal = *((char **)v16 + 7))
                : (m_pStringVal = v16->m_pStringVal),
                  (char *)v138[8].Id != m_pStringVal) )
            {
              if ( SHIDWORD(v136) < *(_DWORD *)(v136 + 4) )
                ++HIDWORD(v136);
              goto LABEL_4;
            }
            if ( (int)v16->__vftable >= 0 )
              *(float *)&v16->m_intVal = v131;
            else
              v16->m_intVal ^= (LODWORD(v131) ^ v16->m_intVal) & 0xFFFFFF;
            v18 = (int)v16->__vftable < 0;
            x = v16->m_VecVal.x;
            y = v16->m_VecVal.y;
            if ( v18 )
              m_intVal_high = (IMaterialVar_vtbl *)HIBYTE(v16->m_intVal);
            else
              m_intVal_high = v16[1].__vftable;
            LODWORD(v131) += m_intVal_high;
            v16->m_VecVal.y = v142;
            if ( v18 )
              z_low = LOWORD(v16->m_VecVal.z);
            else
              z_low = LODWORD(v16->m_VecVal.z);
            if ( z_low >= v133 )
              v133 = z_low;
            Length = GFxTextParagraph::GetLength(this: v138);
            v22 = v137;
            if ( Length != 0 || (v23 = v137[71].pTable) != nullptr && (*((_BYTE *)v23 + 104) & 1) == 0 )
            {
              if ( (int)v16->__vftable >= 0 )
                w = v16->m_VecVal.w;
              else
                LODWORD(w) = HIWORD(v16->m_VecVal.z);
              v129 = LODWORD(v142) + LODWORD(w);
            }
            if ( (int)v16->__vftable >= 0 )
              v25 = v16->m_VecVal.w;
            else
              LODWORD(v25) = HIWORD(v16->m_VecVal.z);
            if ( (int)v16->__vftable >= 0 )
              m_intVal_low = SLOWORD(v16[1].m_intVal);
            else
              m_intVal_low = (char)v16->m_nTempIndex;
            LODWORD(v142) += LODWORD(v25) + m_intVal_low;
            if ( (BYTE2(v137[83].pTable) & 1) == 0 )
              goto LABEL_72;
            v27 = (int)v16->__vftable;
            if ( (((unsigned int)v16->__vftable >> 28) & 3) == 1 )
            {
              v139 = *(float *)&v137[17].pTable - *(float *)&v137[15].pTable;
              v31 = v139;
              if ( v139 <= 0.0 )
                v32 = v31 - 0.5;
              else
                v32 = v31 + 0.5;
              v33 = v32;
              v7 = 0.5;
              if ( v27 >= 0 )
                z = v16->m_VecVal.z;
              else
                LODWORD(z) = LOWORD(v16->m_VecVal.z);
              LODWORD(v16->m_VecVal.x) = (int)v33 - LODWORD(z) < 0 ? 0 : (int)v33 - LODWORD(z);
              v146 = 1;
              goto LABEL_73;
            }
            if ( (((unsigned int)v16->__vftable >> 28) & 3) == 2 )
            {
              v139 = *(float *)&v137[17].pTable - *(float *)&v137[15].pTable;
              v7 = 0.5;
              v139 = v139 * 0.5;
              v28 = v139;
              if ( v139 <= 0.0 )
                v29 = v28 - 0.5;
              else
                v29 = v28 + 0.5;
              if ( v27 >= 0 )
                v30 = v16->m_VecVal.z;
              else
                LODWORD(v30) = LOWORD(v16->m_VecVal.z);
              LODWORD(v16->m_VecVal.x) = ((int)v29 - SLODWORD(v30) / 2) & (((int)v29 - SLODWORD(v30) / 2 < 0) - 1);
              v146 = 1;
            }
            else
            {
LABEL_72:
              v7 = 0.5;
            }
LABEL_73:
            if ( LODWORD(x) != LODWORD(v16->m_VecVal.x) || LODWORD(y) != LODWORD(v16->m_VecVal.y) )
              LOBYTE(v22[38].pTable) |= 1u;
            v15 = v125;
            v8 = v124[0];
            if ( (unsigned int)v125 < v124[0]->m_Memory.m_nAllocationCount )
              v15 = ++v125;
          }
        }
      }
    }
    m_intVal = v10->m_intVal;
    v36 = (int)v10->__vftable < 0;
    if ( (int)v10->__vftable < 0 && (m_intVal &= 0xFFFFFFu) == 0xFFFFFF || m_intVal == -1 )
    {
      v37 = 0;
      if ( (int)v10->__vftable >= 0 )
        v38 = *((char **)v10 + 7);
      else
        v38 = v10->m_pStringVal;
      for ( i = v125; (unsigned int)i < v8->m_Memory.m_nAllocationCount && i >= 0; ++i )
      {
        v40 = (int *)v8->m_Memory.m_pMemory[i];
        v41 = *v40 >= 0 ? v40[7] : v40[1];
        if ( (char *)v41 != v38 )
          break;
        ++v37;
      }
      if ( v37 == 0 )
        goto LABEL_4;
      GFxTextLineBuffer::RemoveLines(this: v8);
      v7 = 0.5;
      v42 = v137;
      LOBYTE(v137[38].pTable) |= 1u;
      v8 = v124[0];
      v9 = v42;
    }
    else
    {
      v43 = *(float *)&v138[8].Id;
      v139 = v43;
      if ( v36 )
        v44 = v10->m_pStringVal;
      else
        v44 = *((char **)v10 + 7);
      if ( (char *)LODWORD(v43) == v44 )
      {
        v45 = v36 ? LOWORD(v10->m_VecVal.w) : LOWORD(v10[1].m_pStringVal);
        if ( LOWORD(v138[9].Id) != v45 )
        {
          v46 = v125;
          for ( j = 0; (unsigned int)v46 < v8->m_Memory.m_nAllocationCount && v46 >= 0; ++j )
          {
            v48 = (int *)v8->m_Memory.m_pMemory[v46];
            v49 = *v48 >= 0 ? v48[7] : v48[1];
            v9 = v137;
            if ( v49 != LODWORD(v139) )
              break;
            ++v46;
          }
          GFxTextLineBuffer::RemoveLines(this: v8);
          LOBYTE(v9[38].pTable) |= 1u;
        }
      }
LABEL_113:
      v50 = v138;
      v143 = v142;
      v141 = v124;
      GFxParagraphFormatter::Format(this: (GFxParagraphFormatter *)v140, a2: (GRefCountNTSImpl *)v138);
      v51 = v144;
      LOBYTE(v9[38].pTable) |= 1u;
      if ( v51 >= v133 )
        v133 = v51;
      if ( GFxTextParagraph::GetLength(this: v50) != 0
        || (v52 = v9[71].pTable) != nullptr && (*((_BYTE *)v52 + 104) & 1) == 0 )
      {
        v129 = LODWORD(v143) + v145;
      }
      if ( SHIDWORD(v136) < *(_DWORD *)(v136 + 4) )
        ++HIDWORD(v136);
      v8 = v124[0];
      v7 = 0.5;
    }
  }
  if ( v8 != nullptr && (unsigned int)v125 < v8->m_Memory.m_nAllocationCount && v125 >= 0 )
  {
    GFxTextLineBuffer::RemoveLines(this: v8);
    v7 = 0.5;
    LOBYTE(v9[38].pTable) |= 1u;
  }
  v53 = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)v133;
  v54 = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)v129;
  v55 = BYTE2(v9[83].pTable);
  ++LOWORD(v9[82].pTable);
  LOBYTE(v9[84].pTable) &= 0xFCu;
  v56 = v147;
  v9[66].pTable = v53;
  v57 = (unsigned __int8)v9[83].pTable;
  v9[67].pTable = v54;
  v58 = (v57 >> 2) & 3;
  v132 = 0;
  if ( (v55 & 1) != 0 || (v55 & 2) != 0 || v56 != 0 )
  {
    v134 = (int)v137[62].pTable;
    v135 = *(float *)&v137[63].pTable;
    *(float *)&v136 = *(float *)&v137[64].pTable;
    *((float *)&v136 + 1) = *(float *)&v137[65].pTable;
    if ( (v55 & 1) != 0 )
    {
      v59 = (v57 & 3) - 1;
      v139 = (double)(unsigned int)v133 + 80.0;
      v60 = v139;
      if ( v59 != 0 )
      {
        if ( v59 == 1 )
        {
          v139 = *(float *)&v136 - *(float *)&v134;
          v61 = *(float *)&v134 + v139 * v7 - v60 * v7;
          goto LABEL_134;
        }
      }
      else
      {
        v61 = *(float *)&v136 - v60;
LABEL_134:
        *(float *)&v134 = v61;
      }
      *(float *)&v136 = v60 + *(float *)&v134;
    }
    if ( (v55 & 2) != 0 || v56 != 0 )
    {
      v139 = (double)(unsigned int)v129 + 80.0;
      v62 = v139;
      if ( v58 != 0 )
      {
        if ( v58 == 3 )
          goto LABEL_142;
        if ( v58 == 2 )
          v135 = *((float *)&v136 + 1) - v62;
        v132 = 1;
        *((float *)&v136 + 1) = v62 + v135;
      }
      else
      {
        if ( v56 == 0 )
        {
          v132 = 1;
          *((float *)&v136 + 1) = v62 + v135;
          goto LABEL_146;
        }
LABEL_142:
        v132 = 1;
        v139 = *((float *)&v136 + 1) - v135;
        v135 = v135 + v139 * v7 - v62 * v7;
        *((float *)&v136 + 1) = v62 + v135;
      }
    }
LABEL_146:
    if ( *(float *)&v137[62].pTable != *(float *)&v134
      || *(float *)&v137[64].pTable != *(float *)&v136
      || *(float *)&v137[63].pTable != v135
      || *(float *)&v137[65].pTable != *((float *)&v136 + 1) )
    {
      GFxTextDocView::SetViewRect(this: (GFxTextDocView *)v137, a2: (float *)&v134, a3: 0);
      v7 = 0.5;
    }
  }
  v63 = v137;
  v64 = 40.0;
  v65 = (LOBYTE(v137[83].pTable) >> 4) & 3;
  if ( v65 != 0 )
  {
    v5 = (BYTE2(v137[83].pTable) & 4) == 0;
    v134 = (int)v137[62].pTable;
    v135 = *(float *)&v137[63].pTable;
    *(float *)&v136 = *(float *)&v137[64].pTable;
    *((float *)&v136 + 1) = *(float *)&v137[65].pTable;
    *(float *)&v134 = *(float *)&v134 + 40.0;
    *(float *)&v136 = *(float *)&v136 - 40.0;
    v135 = v135 + 40.0;
    *((float *)&v136 + 1) = *((float *)&v136 + 1) - 40.0;
    if ( v5 && v58 == 0 )
      v58 = 3;
    *(float *)&v138 = 1.0;
    v131 = 1.0;
    if ( v65 == 1 )
    {
      v139 = (float)v133;
      y = *(float *)&v136 - *(float *)&v134;
      if ( y < (double)v139 )
        *(float *)&v138 = y / v139;
      v139 = (float)v129;
      y = *((float *)&v136 + 1) - v135;
      if ( y < (double)v139 )
        v131 = y / v139;
      if ( *(float *)&v138 > (double)v131 )
        *(float *)&v138 = v131;
      goto LABEL_171;
    }
    if ( v65 == 2 )
    {
      v131 = 3.4028235e38;
      *(float *)&v138 = 3.4028235e38;
      if ( v133 >= 20 )
      {
        v139 = *(float *)&v136 - *(float *)&v134;
        *(float *)&v138 = v139 / (double)v133;
      }
      if ( v129 >= 20 )
      {
        v139 = *((float *)&v136 + 1) - v135;
        v131 = v139 / (double)v129;
      }
      v66 = v131;
      if ( *(float *)&v138 <= (double)v131 )
        v66 = *(float *)&v138;
      *(float *)&v138 = v66;
      if ( 3.402823466385289e38 != *(float *)&v138 )
      {
LABEL_171:
        if ( *(float *)&v138 != 1.0 )
        {
          v139 = COERCE_FLOAT(GFxTextLineBuffer::GetMinLineHeight(this: (GFxTextLineBuffer *)&v137[9]));
          if ( SLODWORD(v139) <= 0 )
            goto LABEL_175;
          v139 = (float)SLODWORD(v139);
          if ( v139 * *(float *)&v138 >= 120.0 )
          {
            v67 = *(float *)&v138;
          }
          else
          {
            *(float *)&v138 = 120.0 / v139;
LABEL_175:
            v67 = *(float *)&v138;
          }
          v63[66].pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)(__int64)((double)v133 * v67);
          LODWORD(v139) = HIWORD(v133) | 0xC00;
          v136 = (__int64)((double)v129 * v67);
          v63[67].pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)v136;
          GFxTextLineBuffer::Scale(this: (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)&v63[9]);
          v64 = 40.0;
          v7 = 0.5;
        }
      }
    }
  }
  if ( v132 == 0 && v58 != 0 && (BYTE2(v63[83].pTable) & 2) == 0 )
  {
    v68 = (int)v63[67].pTable;
    v134 = (int)v63[62].pTable;
    v135 = *(float *)&v63[63].pTable;
    *(float *)&v136 = *(float *)&v63[64].pTable;
    *((float *)&v136 + 1) = *(float *)&v63[65].pTable;
    *(float *)&v134 = *(float *)&v134 + v64;
    *(float *)&v136 = *(float *)&v136 - v64;
    v135 = v135 + v64;
    *((float *)&v136 + 1) = *((float *)&v136 + 1) - v64;
    v119 = *(float *)&v63[15].pTable;
    v120 = *(float *)&v63[16].pTable;
    v122 = *(float *)&v63[17].pTable;
    v123 = *(float *)&v63[18].pTable;
    v69 = (double)(int)v63[67].pTable;
    if ( v68 < 0 )
      v69 = v69 + 4294967300.0;
    v139 = v69;
    v70 = *((float *)&v136 + 1);
    v71 = v135;
    y = *((float *)&v136 + 1) - v135;
    v72 = v139;
    if ( y <= (double)v139 )
    {
      v63[15].pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)v134;
      *(float *)&v63[16].pTable = v71;
      v63[17].pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)v136;
      *(float *)&v63[18].pTable = v70;
    }
    else
    {
      v73 = v58 - 1;
      if ( v73 != 0 )
      {
        v74 = v73 - 1;
        if ( v74 != 0 )
        {
          if ( v74 == 1 )
            v120 = y * v7 - v72 * v7 + v71;
        }
        else
        {
          v120 = v70 - v72;
        }
      }
      else
      {
        v119 = *(float *)&v134;
        v120 = v135;
        v122 = *(float *)&v136;
        v123 = *((float *)&v136 + 1);
      }
      *(float *)&v63[15].pTable = v119;
      *(float *)&v63[16].pTable = v120;
      *(float *)&v63[17].pTable = v122;
      *(float *)&v63[18].pTable = v123;
    }
  }
  if ( v146 != 0 )
  {
    v121 = 0;
    v75 = 0;
    v76 = v63;
    while ( 1 )
    {
      v77 = v76 + 9;
      if ( v76 == (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)-36
        || (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)v75 >= v76[10].pTable
        || v75 < 0 )
      {
        goto LABEL_217;
      }
      v78 = *((int **)v77->pTable + v75);
      v79 = *v78;
      if ( (((unsigned int)*v78 >> 28) & 3) == 1 )
        break;
      if ( (((unsigned int)*v78 >> 28) & 3) == 2 )
      {
        v139 = *(float *)&v76[17].pTable - *(float *)&v76[15].pTable;
        v139 = v139 * v7;
        v80 = v139;
        if ( v139 <= 0.0 )
          v81 = v80 - v7;
        else
          v81 = v80 + v7;
        if ( v79 >= 0 )
          v82 = v78[5];
        else
          v82 = *((unsigned __int16 *)v78 + 10);
        v83 = ((int)v81 - v82 / 2) & (((int)v81 - v82 / 2 < 0) - 1);
LABEL_214:
        v75 = v121;
        v76 = v137;
        v78[3] = v83;
      }
      if ( (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)v75 < v77[1].pTable )
        v121 = ++v75;
    }
    v139 = *(float *)&v76[17].pTable - *(float *)&v76[15].pTable;
    v84 = v139;
    if ( v139 <= 0.0 )
      v85 = v84 - v7;
    else
      v85 = v84 + v7;
    if ( v79 >= 0 )
      v86 = v78[5];
    else
      v86 = *((unsigned __int16 *)v78 + 10);
    v83 = (int)v85 - v86 < 0 ? 0 : (int)v85 - v86;
    goto LABEL_214;
  }
LABEL_217:
  v87 = v137;
  if ( ((int)v137[84].pTable & 3) != 0 )
  {
    v88 = v137;
    GFxTextDocView::Format(this: (GFxTextDocView *)v137);
    LOBYTE(v88[84].pTable) &= 0xFCu;
    v87 = v88;
  }
  v89 = GFxTextDocView::GetMaxHScrollValue(this: (GFxTextDocView *)v87);
  v91 = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v89;
  v92 = false;
  if ( v90[19].pTable <= (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)v89 )
  {
    v92 = v89 != v117;
  }
  else
  {
    if ( ((int)v90[84].pTable & 3) != 0 )
    {
      v93 = v137;
      GFxTextDocView::Format(this: (GFxTextDocView *)v137);
      LOBYTE(v93[84].pTable) &= 0xFCu;
      v90 = v93;
    }
    v94 = GFxTextDocView::GetMaxHScrollValue(this: (GFxTextDocView *)v90);
    if ( (unsigned int)v91 > v94 )
      v91 = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v94;
    if ( *(const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > **)(v95 + 76) != v91 )
    {
      v96 = v137;
      GFxTextLineBuffer::SetHScrollOffset(result: v91);
      v97 = v96[4].pTable;
      if ( v97 != nullptr )
        (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *, const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *))(*(_DWORD *)v97 + 8))(
          a1: v97,
          a2: v96,
          a3: v91);
    }
  }
  v98 = v137;
  MaxVScroll = GFxTextDocView::GetMaxVScroll(this: (GFxTextDocView *)v137);
  v100 = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)MaxVScroll;
  if ( v98[14].pTable <= (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)MaxVScroll )
  {
    if ( MaxVScroll != LODWORD(v128) )
      v92 = true;
  }
  else
  {
    v101 = GFxTextDocView::GetMaxVScroll(this: (GFxTextDocView *)v98);
    if ( (unsigned int)v100 > v101 )
      v100 = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v101;
    if ( (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v98[14].pTable != v100 )
    {
      GFxTextLineBuffer::SetFirstVisibleLine(result: v100);
      v102 = v98[4].pTable;
      if ( v102 != nullptr )
        (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *, const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *))(*(_DWORD *)v102 + 12))(
          a1: v102,
          a2: v98,
          a3: v100);
    }
  }
  v103 = v98[4].pTable;
  if ( v103 != nullptr )
  {
    if ( v92 && (*((_BYTE *)v103 + 8) & 4) != 0 )
      (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *))(*(_DWORD *)v103 + 16))(
        a1: v103,
        a2: v98);
    v104 = v98[4].pTable;
    if ( (*((_BYTE *)v104 + 8) & 8) != 0 )
      (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *))(*(_DWORD *)v104 + 20))(
        a1: v104,
        a2: v98);
  }
  v105 = v98[71].pTable;
  if ( v105 != nullptr && (*((_BYTE *)v105 + 104) & 1) == 0
    || (v106 = (double)(unsigned int)v98[66].pTable,
        (v128 = *(float *)&v98[64].pTable - *(float *)&v98[62].pTable) < v106)
    || (v107 = (double)(unsigned int)v98[67].pTable,
        (v128 = *(float *)&v98[65].pTable - *(float *)&v98[63].pTable) < v107)
    || v98[19].pTable != nullptr )
  {
    LOBYTE(v98[38].pTable) &= ~0x20u;
  }
  else
  {
    LOBYTE(v98[38].pTable) |= 0x20u;
  }
  v108 = (GFxTextHighlighter *)v98[5].pTable;
  if ( v108 != nullptr )
  {
    v109 = v98[71].pTable;
    if ( v109 != nullptr )
      v110 = *((const struct GFxTextCompositionString **)v109 + 5);
    else
      v110 = nullptr;
    GFxTextHighlighter::UpdateGlyphIndices(this: v108, a2: v110);
  }
  LOBYTE(v98[84].pTable) &= ~0x20u;
  if ( v98[10].pTable != nullptr )
  {
    v111 = (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > **)v98[9].pTable;
    v112 = *v111;
    v113 = (int)(*v111)->m_pAllocator >= 0 ? (int)v112[1].m_pAllocator : LOBYTE(v112[7].m_pAllocator);
    if ( v113 != 0 )
    {
      v114 = (int)v112->m_pAllocator >= 0 ? (int)&v112[10].m_pAllocator + 2 : (int)&v112[7].m_pAllocator + 2;
      if ( (*(_WORD *)(v114 + 6) & 0x2000) != 0
        && (*(_DWORD *)(*((_DWORD *)GFxTextLineBuffer::Line::GetFormatData(this: *v111)->__vftable[1].operator() + 3)
                      + 20)
          & 0x8000) != 0 )
      {
        LOBYTE(v98[84].pTable) |= 0x20u;
      }
    }
  }
  GFxParagraphFormatter::~GFxParagraphFormatter(this: (GFxParagraphFormatter *)v140);
}

//------------------------------------------------------------------------------
// Address: 0x1016DFD0
// Name: public: unsigned int GFxTextDocView::GetHScrollOffset(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall GFxTextDocView::GetHScrollOffset@<eax>(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>)
{
  if ( (*(_BYTE *)(this + 84) & 3) != 0 )
  {
    GFxTextDocView::Format(this, a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  return *((_DWORD *)this + 19);
}

//------------------------------------------------------------------------------
// Address: 0x1016DFF0
// Name: public: unsigned int GFxTextDocView::GetVScrollOffset(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall GFxTextDocView::GetVScrollOffset@<eax>(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>)
{
  if ( (*(_BYTE *)(this + 84) & 3) != 0 )
  {
    GFxTextDocView::Format(this, a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  return *((_DWORD *)this + 14);
}

//------------------------------------------------------------------------------
// Address: 0x1016E010
// Name: public: float GFxTextDocView::GetTextWidth(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall GFxTextDocView::GetTextWidth@<st0>(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>)
{
  unsigned int v3; // esi

  if ( (*(_BYTE *)(this + 28) & 3) != 0 )
  {
    GFxTextDocView::Format(
      (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  v3 = *((_DWORD *)this + 66);
  if ( v3 != 0 )
    return (double)v3;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016E050
// Name: public: float GFxTextDocView::GetTextHeight(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall GFxTextDocView::GetTextHeight@<st0>(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>)
{
  unsigned int v3; // esi

  if ( (*(_BYTE *)(this + 28) & 3) != 0 )
  {
    GFxTextDocView::Format(
      (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  v3 = *((_DWORD *)this + 67);
  if ( v3 != 0 )
    return (double)v3;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1016E090
// Name: public: unsigned int GFxTextDocView::GetLinesCount(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall GFxTextDocView::GetLinesCount@<eax>(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>)
{
  if ( (*(_BYTE *)(this + 84) & 3) != 0 )
  {
    GFxTextDocView::Format(this, a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  return *((_DWORD *)this + 10);
}

//------------------------------------------------------------------------------
// Address: 0x1016E0B0
// Name: public: bool GFxTextDocView::ForceReformat(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall GFxTextDocView::ForceReformat@<al>(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>)
{
  if ( (*(_BYTE *)(this + 28) & 3) == 0 )
    return 0;
  GFxTextDocView::Format(
    (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
    a2);
  *((_BYTE *)this + 336) &= 0xFCu;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016E0D0
// Name: public: class GRect<float> const __near & GFxTextDocView::GetViewRect(void)
// Source: json
//------------------------------------------------------------------------------
const unsigned int *__usercall GFxTextDocView::GetViewRect@<eax>(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>)
{
  if ( (*(_BYTE *)(this + 28) & 3) != 0 )
  {
    GFxTextDocView::Format(
      (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  return (const unsigned int *)((char *)this + 248);
}

//------------------------------------------------------------------------------
// Address: 0x1016E0F0
// Name: public: unsigned int GFxTextDocView::GetCharIndexAtPoint(float,float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GFxTextDocView::GetCharIndexAtPoint@<eax>(
        GFxTextDocView *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>,
        float a3,
        float a4)
{
  unsigned int v5; // eax
  int v6; // esi
  bool v7; // cl
  double v8; // st7
  double v9; // st6
  unsigned int v10; // edi
  int v11; // edi
  int v12; // eax
  int v13; // edx
  int v14; // esi
  __int128 v16; // [esp+0h] [ebp-80h]
  const VJobInstance *v18; // [esp+0h] [ebp-80h]
  IColorCorrectionSystem *v19; // [esp+4h] [ebp-7Ch]
  __int128 v20; // [esp+8h] [ebp-78h]
  unsigned int v21; // [esp+Ch] [ebp-74h]
  const MaterialNonInteractiveMode_t *v22; // [esp+10h] [ebp-70h]
  unsigned int v23; // [esp+10h] [ebp-70h]
  _DWORD *v24; // [esp+68h] [ebp-18h] BYREF
  int v25; // [esp+70h] [ebp-10h]
  float v26; // [esp+7Ch] [ebp-4h]
  float v27; // [esp+88h] [ebp+8h]
  int v28; // [esp+88h] [ebp+8h]
  float v29; // [esp+8Ch] [ebp+Ch]
  float v30; // [esp+8Ch] [ebp+Ch]
  float v31; // [esp+8Ch] [ebp+Ch]
  int v32; // [esp+8Ch] [ebp+Ch]
  int v33; // [esp+8Ch] [ebp+Ch]

  if ( (*((_BYTE *)this + 336) & 3) != 0 )
  {
    GFxTextDocView::Format(
      (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  v27 = a3 - (*((float *)this + 15) - *((float *)this + 62));
  v29 = a4 - (*((float *)this + 16) - *((float *)this + 63));
  GFxTextLineBuffer::GetVScrollOffsetInTwips(this: (CMatCallQueue *)((char *)this + 36), a2: v19, a3: v20);
  v26 = *(float *)&v5;
  v30 = (double)v5 + v29;
  *(float *)&v16 = v30;
  GFxTextLineBuffer::FindLineAtYOffset(
    this: (CMatCallQueue *)((char *)this + 36),
    yoff: (CMatRenderContextBase *)&v24,
    a3: v16,
    a4: v22);
  if ( v24 == nullptr )
    return -1;
  if ( (unsigned int)v25 >= v24[1] )
    return -1;
  if ( v25 < 0 )
    return -1;
  v6 = *(_DWORD *)(*v24 + 4 * v25);
  v7 = *(int *)v6 < 0;
  v31 = (float)*(int *)(v6 + 12);
  v8 = v27;
  v9 = v31;
  if ( v31 > (double)v27 )
    return -1;
  v32 = *(int *)v6 >= 0 ? *(_DWORD *)(v6 + 20) : *(unsigned __int16 *)(v6 + 20);
  if ( (double)v32 + v9 < v8 )
    return -1;
  v33 = 0;
  v26 = v8 - v9;
  if ( v7 )
    v28 = *(unsigned __int8 *)(v6 + 28);
  else
    v28 = *(_DWORD *)(v6 + 4);
  v10 = v6 + 30;
  if ( !v7 )
    v10 = v6 + 42;
  v21 = v10;
  v23 = v10 + 8 * v28;
  GFxTextLineBuffer::Line::GetFormatData(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v6);
  GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: (const VJobInstance *)a2);
  v11 = 0;
  while ( v21 != 0 && v21 < v23 )
  {
    v12 = *(unsigned __int16 *)(v21 + 2);
    if ( (*(_BYTE *)(v21 + 6) & 0x40) != 0 )
      v12 = -v12;
    v33 += v12;
    if ( v26 < (double)v33 )
      break;
    v11 += *(unsigned __int16 *)(v21 + 4) >> 12;
    GFxTextLineBuffer::GlyphIterator::operator++(result: v18);
  }
  v13 = *(_DWORD *)v6;
  v14 = *(_DWORD *)(v6 + 8);
  if ( v13 < 0 )
  {
    v14 &= 0xFFFFFFu;
    if ( v14 == 0xFFFFFF )
      v14 = -1;
  }
  return v14 + v11;
}

//------------------------------------------------------------------------------
// Address: 0x1016E310
// Name: public: unsigned int GFxTextDocView::GetCursorPosInLine(unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::GetCursorPosInLine(
        GRefCountBase<GFxAmpMemSegment,2> *this,
        const GRefCountBase<GFxAmpMemSegment,2> *lineIndex,
        float x)
{
  if ( (unsigned int)lineIndex < *((_DWORD *)this + 10) )
  {
    if ( (*(_BYTE *)(this + 42) & 3) != 0 )
    {
      GFxTextDocView::Format(
        (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
        a2: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)lineIndex);
      *((_BYTE *)this + 336) &= 0xFCu;
    }
    GFxTextDocView::GetCursorPosInLineByOffset(
      this,
      a2: (const VJobInstance *)lineIndex,
      (unsigned int)lineIndex,
      xoffInLine: x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E360
// Name: public: unsigned int GFxTextDocView::GetCursorPosAtPoint(float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextDocView::GetCursorPosAtPoint(
        GRefCountBase<GFxAmpMemSegment,2> *this@<ecx>,
        IColorCorrectionSystem *a2@<esi>,
        float a3,
        float a4)
{
  unsigned int v5; // eax
  char *v6; // eax
  GRefCountBase<GFxAmpMemSegment,2> *v7; // ecx
  char v8; // al
  __int128 v9; // [esp+0h] [ebp-38h]
  __int128 v10; // [esp+8h] [ebp-30h]
  const MaterialNonInteractiveMode_t *v11; // [esp+10h] [ebp-28h]
  int v12; // [esp+1Ch] [ebp-1Ch]
  _DWORD v13[2]; // [esp+20h] [ebp-18h] BYREF
  GRefCountBase<GFxAmpMemSegment,2> *lineIndex; // [esp+28h] [ebp-10h]
  float v15; // [esp+2Ch] [ebp-Ch]
  int v16; // [esp+30h] [ebp-8h]
  float v17; // [esp+34h] [ebp-4h]
  float v18; // [esp+40h] [ebp+8h]
  float v19; // [esp+44h] [ebp+Ch]

  if ( (*(_BYTE *)(this + 42) & 3) != 0 )
  {
    GFxTextDocView::Format(
      (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      a2: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  v18 = a3 - (*((float *)this + 15) - *((float *)this + 62));
  v19 = a4 - (*((float *)this + 16) - *((float *)this + 63));
  GFxTextLineBuffer::GetVScrollOffsetInTwips(this: (CMatCallQueue *)((char *)this + 36), a2, a3: v10);
  v17 = (double)v5 + v19;
  *(float *)&v9 = v17;
  GFxTextLineBuffer::FindLineAtYOffset(
    this: (CMatCallQueue *)((char *)this + 36),
    yoff: (CMatRenderContextBase *)v13,
    a3: v9,
    a4: v11);
  v6 = (char *)v13[0];
  if ( v13[0] == 0 || (v7 = lineIndex, (unsigned int)lineIndex >= *(_DWORD *)(v13[0] + 4)) || (int)lineIndex < 0 )
  {
    v13[1] = 0;
    v8 = *((_BYTE *)this + 152) >> 2;
    v15 = 0.0;
    if ( v19 > 0.0 )
      v7 = (GRefCountBase<GFxAmpMemSegment,2> *)(*((_DWORD *)this + 10) - 1);
    else
      v7 = nullptr;
    LOBYTE(v12) = v8 & 1;
    v6 = (char *)this + 36;
    v16 = v12;
    lineIndex = v7;
    v13[0] = (char *)this + 36;
  }
  if ( v6 != nullptr && (unsigned int)v7 < *((_DWORD *)v6 + 1) && (int)v7 >= 0 )
    GFxTextDocView::GetCursorPosInLineByOffset(
      this,
      a2: (const VJobInstance *)this,
      lineIndex: (unsigned int)v7,
      xoffInLine: v18);
}

//------------------------------------------------------------------------------
// Address: 0x1016E460
// Name: public: bool GFxTextDocView::IsUrlAtPoint(float,float,class GRange __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextDocView::IsUrlAtPoint(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this@<ecx>,
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>,
        int x,
        float y,
        unsigned int *purlPosRange)
{
  bool v6; // zf
  const char *v7; // eax
  int v8; // edi
  int v9; // ecx
  bool v10; // cl
  double v11; // st7
  double v12; // st6
  int v13; // eax
  double v14; // st7
  double v15; // st6
  int v16; // ebx
  unsigned int v17; // esi
  CFunctor *FormatData; // eax
  int v19; // esi
  int v20; // eax
  bool v21; // sf
  int v22; // edx
  double v23; // st7
  unsigned int *v24; // ebx
  int v25; // ecx
  int v26; // edi
  SFTextObjectImpl *v27; // ecx
  GFxTextParagraph *v28; // edi
  const CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *TextFormat; // eax
  unsigned int v30; // esi
  int v31; // eax
  int *v32; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v33; // esi
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v34[6]; // [esp+0h] [ebp-104h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v35; // [esp+38h] [ebp-CCh] BYREF
  int v36; // [esp+48h] [ebp-BCh]
  _DWORD *v37; // [esp+64h] [ebp-A0h] BYREF
  int v38; // [esp+6Ch] [ebp-98h]
  unsigned int v39; // [esp+78h] [ebp-8Ch]
  unsigned int v40; // [esp+7Ch] [ebp-88h]
  CFunctor *v41; // [esp+80h] [ebp-84h]
  int v42; // [esp+88h] [ebp-7Ch]
  int v43; // [esp+8Ch] [ebp-78h]
  int v44; // [esp+90h] [ebp-74h]
  int v45; // [esp+94h] [ebp-70h]
  int v46; // [esp+98h] [ebp-6Ch]
  int v47; // [esp+9Ch] [ebp-68h]
  int v48; // [esp+A0h] [ebp-64h]
  int v49; // [esp+A4h] [ebp-60h]
  int v50; // [esp+A8h] [ebp-5Ch]
  int v51; // [esp+ACh] [ebp-58h]
  int v52; // [esp+B0h] [ebp-54h]
  char v53; // [esp+B4h] [ebp-50h]
  int v54; // [esp+B8h] [ebp-4Ch]
  int v55; // [esp+BCh] [ebp-48h]
  int v56; // [esp+C0h] [ebp-44h]
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v57; // [esp+C4h] [ebp-40h]
  GRefCountNTSImpl *v58; // [esp+C8h] [ebp-3Ch]
  int v59; // [esp+CCh] [ebp-38h]
  int v60; // [esp+D0h] [ebp-34h]
  GRefCountBase<GFxASUserData,2> it; // [esp+D4h] [ebp-30h] BYREF
  IShaderAPI *v62; // [esp+E0h] [ebp-24h]
  int v63; // [esp+F0h] [ebp-14h]
  unsigned int v64; // [esp+F4h] [ebp-10h]
  GFxValue index; // [esp+F8h] [ebp-Ch] BYREF

  v6 = (*(_BYTE *)(this + 28) & 3) == 0;
  index.Type = (GFxValue::ValueType)this;
  if ( !v6 )
  {
    GFxTextDocView::Format(
      (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  *(float *)&x = *(float *)&x - (*((float *)this + 15) - *((float *)this + 62));
  y = y - (*((float *)this + 16) - *((float *)this + 63));
  GFxTextLineBuffer::GetVScrollOffsetInTwips(
    this: (CMatCallQueue *)(this + 3),
    a2: (IColorCorrectionSystem *)v34[0].m_pObject,
    a3: *(__int128 *)&v34[1].m_pfnProxied);
  index.Value.pString = v7;
  y = (double)(unsigned int)v7 + y;
  *(float *)&v34[0].m_pfnProxied = y;
  GFxTextLineBuffer::FindLineAtYOffset(
    this: (CMatCallQueue *)(this + 3),
    yoff: (CMatRenderContextBase *)&v37,
    a3: *(__int128 *)&v34[0].m_pfnProxied,
    a4: (const MaterialNonInteractiveMode_t *)v34[2].m_pfnProxied);
  HIBYTE(y) = 0;
  if ( v37 != nullptr && (unsigned int)v38 < v37[1] && v38 >= 0 )
  {
    v34[0].m_pfnProxied = (void (__thiscall *)(IMaterial *, float))a2;
    v8 = *(_DWORD *)(*v37 + 4 * v38);
    v9 = *(_DWORD *)v8;
    index.Value.pString = *(const char **)(v8 + 12);
    v10 = v9 < 0;
    *(float *)&index.Value.pString = (float)(int)index.Value.pString;
    v11 = *(float *)&x;
    v12 = *(float *)&index.Value.pString;
    if ( *(float *)&index.Value.pString <= (double)*(float *)&x )
    {
      v13 = v10 ? *(unsigned __int16 *)(v8 + 20) : *(_DWORD *)(v8 + 20);
      x = v13;
      if ( (double)v13 + v12 >= v11 )
      {
        v14 = v11 - v12;
        v15 = (double)*((unsigned int *)this + 19);
        *(float *)&x = 0.0;
        *(float *)&index.Value.pString = v14 + v15;
        if ( v10 )
          v16 = *(unsigned __int8 *)(v8 + 28);
        else
          v16 = *(_DWORD *)(v8 + 4);
        v17 = v8 + 30;
        if ( !v10 )
          v17 = v8 + 42;
        FormatData = GFxTextLineBuffer::Line::GetFormatData(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v8);
        v45 = 0;
        v47 = 0;
        v48 = 0;
        v49 = 0;
        v52 = 0;
        v51 = 0;
        v50 = 0;
        v53 = 0;
        v43 = 0;
        v42 = 0;
        v54 = 0;
        v55 = 0;
        v56 = 0;
        v57 = nullptr;
        v58 = nullptr;
        v59 = 0;
        v60 = 0;
        v40 = v17 + 8 * v16;
        v44 = -1;
        v46 = -1;
        v39 = v17;
        v41 = FormatData;
        GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: (const VJobInstance *)v34[0].m_pfnProxied);
        v19 = 0;
        while ( v39 != 0 && v39 < v40 )
        {
          v20 = *(unsigned __int16 *)(v39 + 2);
          if ( (*(_BYTE *)(v39 + 6) & 0x40) != 0 )
            v20 = -v20;
          v21 = v20 + x < 0;
          v22 = v20 + x;
          x += v20;
          v23 = (double)x;
          if ( v21 )
            v23 = v23 + 4294967300.0;
          if ( *(float *)&index.Value.pString < v23 )
          {
            HIBYTE(y) = *(_BYTE *)(v39 + 6) >> 7;
            if ( HIBYTE(y) != 0 )
            {
              v24 = purlPosRange;
              if ( purlPosRange != nullptr )
              {
                *purlPosRange = 0;
                v24[1] = 0;
                v25 = *(_DWORD *)v8;
                v26 = *(_DWORD *)(v8 + 8);
                if ( v25 < 0 )
                {
                  v26 &= 0xFFFFFFu;
                  if ( v26 == 0xFFFFFF )
                    v26 = -1;
                }
                v27 = *(SFTextObjectImpl **)(index.Type + 8);
                *(float *)&x = 0.0;
                purlPosRange = (unsigned int *)(v26 + v19);
                GFxStyledText::GetParagraphByIndex(
                  this: v27,
                  &index,
                  indexa: v26 + v19,
                  pindexInParagraph: (unsigned int *)&x);
                if ( index.pObjectInterface != nullptr
                  && index.Type >= VT_Undefined
                  && index.Type < (int)index.pObjectInterface[1].pMovieRoot )
                {
                  v28 = *((GFxTextParagraph **)index.pObjectInterface->pMovieRoot + index.Type);
                  TextFormat = (const CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)GFxTextParagraph::GetTextFormat(this: (int)v28, a2: (int)&v34[1].m_pObject, a3: x, a4: x + 1);
                  GFxTextFormat::GFxTextFormat(this: (GStringDH *)&v35, result: TextFormat, srcfmt_4: nullptr);
                  GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v34[1].m_pObject);
                  GFxTextParagraph::GetIterator(this: v28, a2: &it);
                  while ( v64 < *(_DWORD *)(v63 + 4) )
                  {
                    v30 = (unsigned int)v28[7].pObject
                        + GFxTextParagraph::FormatRunIterator::operator*(this: (int *)&it)[1];
                    v31 = GFxTextParagraph::FormatRunIterator::operator*(this: (int *)&it)[3];
                    if ( (*(_WORD *)(v31 + 42) & 0x100) != 0
                      && GString::GetLength(this: (GString *)(v31 + 16)) != 0
                      && (v32 = GFxTextParagraph::FormatRunIterator::operator*(this: (int *)&it),
                          strcmp(
                            (const char *)((*(_DWORD *)(v32[3] + 16) & 0xFFFFFFFC) + 8),
                            (const char *)((v36 & 0xFFFFFFFC) + 8)) == 0) )
                    {
                      if ( v24[1] + *v24 >= v30 )
                      {
                        v24[1] += GFxTextParagraph::FormatRunIterator::operator*(this: (int *)&it)[2];
                      }
                      else
                      {
                        if ( v30 > (unsigned int)purlPosRange )
                          break;
                        *v24 = v30;
                        v24[1] = GFxTextParagraph::FormatRunIterator::operator*(this: (int *)&it)[2];
                      }
                    }
                    else
                    {
                      if ( v30 > (unsigned int)purlPosRange )
                        break;
                      *v24 = 0;
                      v24[1] = 0;
                    }
                    GFxTextParagraph::FormatRunIterator::operator++(this: &it);
                  }
                  if ( v62 != nullptr )
                    GRefCountImpl::Release(this: v62);
                  GFxTextFormat::~GFxTextFormat(this: &v35);
                }
              }
            }
            break;
          }
          v19 += *(unsigned __int16 *)(v39 + 4) >> 12;
          x = v22;
          GFxTextLineBuffer::GlyphIterator::operator++(result: (const VJobInstance *)v34[0].m_pfnProxied);
        }
        if ( v58 != nullptr )
          GRefCountNTSImpl::Release(this: v58);
        v33 = v57;
        if ( v57 != nullptr )
        {
          --LODWORD(v57->m_pfnProxied);
          if ( LODWORD(v33->m_pfnProxied) == 0 )
          {
            GFxFontHandle::~GFxFontHandle(this: v33);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v33);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E870
// Name: public: unsigned int GFxTextDocView::GetLineIndexAtPoint(float,float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GFxTextDocView::GetLineIndexAtPoint@<eax>(
        GFxTextDocView *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>,
        float a3,
        float a4)
{
  unsigned int v5; // eax
  unsigned int result; // eax
  _BYTE v7[24]; // [esp+0h] [ebp-20h] BYREF
  unsigned int v8; // [esp+1Ch] [ebp-4h]
  float v9; // [esp+2Ch] [ebp+Ch]

  if ( (*((_BYTE *)this + 336) & 3) != 0 )
  {
    GFxTextDocView::Format(
      (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  GFxTextLineBuffer::GetVScrollOffsetInTwips(
    this: (CMatCallQueue *)((char *)this + 36),
    a2: *(IColorCorrectionSystem **)&v7[4],
    a3: *(__int128 *)&v7[8]);
  v8 = v5;
  v9 = (double)v5 + a4;
  *(float *)v7 = v9;
  GFxTextLineBuffer::FindLineAtYOffset(
    this: (CMatCallQueue *)((char *)this + 36),
    yoff: (CMatRenderContextBase *)&v7[8],
    a3: *(__int128 *)v7,
    a4: *(const MaterialNonInteractiveMode_t **)&v7[16]);
  if ( *(_DWORD *)&v7[8] == 0 )
    return -1;
  result = *(_DWORD *)&v7[16];
  if ( *(_DWORD *)&v7[16] >= *(_DWORD *)(*(_DWORD *)&v7[8] + 4) || *(int *)&v7[16] < 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016E8E0
// Name: public: unsigned int GFxTextDocView::GetLineIndexOfChar(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxTextDocView::GetLineIndexOfChar@<eax>(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>,
        unsigned int indexOfChar)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-14h] BYREF
  int v6; // [esp+Ch] [ebp-Ch]

  if ( (*(_BYTE *)(this + 84) & 3) != 0 )
  {
    GFxTextDocView::Format(this, a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  GFxTextLineBuffer::FindLineByTextPos(a1: this + 9, a2: &v5, a3: indexOfChar);
  if ( v5 == 0 )
    return -1;
  result = v6;
  if ( (unsigned int)v6 >= *(_DWORD *)(v5 + 4) || v6 < 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016E930
// Name: public: unsigned int GFxTextDocView::GetLineOffset(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxTextDocView::GetLineOffset@<eax>(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>,
        signed int lineIndex)
{
  int *v4; // eax
  int v5; // ecx
  int result; // eax

  if ( (*(_BYTE *)(this + 84) & 3) != 0 )
  {
    GFxTextDocView::Format(this, a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  if ( this == (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)-36 )
    return -1;
  if ( (unsigned int)lineIndex >= *((_DWORD *)this + 10) )
    return -1;
  if ( lineIndex < 0 )
    return -1;
  v4 = *(int **)(*((_DWORD *)this + 9) + 4 * lineIndex);
  v5 = *v4;
  result = v4[2];
  if ( v5 < 0 )
  {
    result &= 0xFFFFFFu;
    if ( result == 0xFFFFFF )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016E990
// Name: public: unsigned int GFxTextDocView::GetLineLength(unsigned int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1016EA10
// Name: public: wchar_t const __near * GFxTextDocView::GetLineText(unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall GFxTextDocView::GetLineText(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this,
        signed int a2,
        unsigned int *a3)
{
  _DWORD *v5; // esi
  signed int v6; // ebx
  int *v7; // eax
  int v8; // ecx
  unsigned int v9; // eax
  SFTextObjectImpl *v10; // ecx
  _DWORD *v11; // ecx
  int v12; // edi
  int v13; // eax
  unsigned int v14; // eax
  _DWORD *v15; // [esp+4h] [ebp-8h] BYREF
  int v16; // [esp+8h] [ebp-4h]

  if ( a3 == nullptr )
    return nullptr;
  if ( (*(_BYTE *)(this + 84) & 3) != 0 )
  {
    GFxTextDocView::Format(this, a2: this);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  v5 = this + 9;
  if ( this == (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)-36 )
    return nullptr;
  v6 = a2;
  if ( (unsigned int)a2 >= *((_DWORD *)this + 10) || a2 < 0 )
    return nullptr;
  v7 = *(int **)(*v5 + 4 * a2);
  v8 = *v7;
  v9 = v7[2];
  if ( v8 < 0 )
  {
    v9 &= 0xFFFFFFu;
    if ( v9 == 0xFFFFFF )
      v9 = -1;
  }
  v10 = *((SFTextObjectImpl **)this + 2);
  a2 = 0;
  GFxStyledText::GetParagraphByIndex(
    this: v10,
    index: (GFxValue *)&v15,
    indexa: v9,
    pindexInParagraph: (unsigned int *)&a2);
  v11 = v15;
  if ( v15 == nullptr )
    return nullptr;
  v12 = v16;
  if ( v16 < 0 || v16 >= v15[1] )
    return nullptr;
  v13 = *(_DWORD *)(*v5 + 4 * v6);
  if ( *(int *)v13 >= 0 )
    v14 = *(_DWORD *)(v13 + 32);
  else
    v14 = *(unsigned __int8 *)(v13 + 11);
  *a3 = v14;
  return (const wchar_t *)(**(_DWORD **)(*v11 + 4 * v12) + 2 * a2);
}

//------------------------------------------------------------------------------
// Address: 0x1016EAF0
// Name: public: bool GFxTextDocView::GetLineMetrics(unsigned int,struct GFxTextDocView::LineMetrics __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextDocView::GetLineMetrics(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this,
        signed int lineIndex,
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a3)
{
  int v5; // esi
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v6; // eax
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v7; // eax
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v8; // eax
  int v10; // [esp+1Ch] [ebp+Ch]
  float v11; // [esp+1Ch] [ebp+Ch]

  if ( a3 == nullptr )
    return 0;
  if ( (*(_BYTE *)(this + 84) & 3) != 0 )
  {
    GFxTextDocView::Format(this, a2: a3);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  if ( this == (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)-36
    || (unsigned int)lineIndex >= *((_DWORD *)this + 10)
    || lineIndex < 0 )
  {
    return 0;
  }
  v5 = *(_DWORD *)(*((_DWORD *)this + 9) + 4 * lineIndex);
  if ( *(int *)v5 >= 0 )
    v10 = *(unsigned __int16 *)(v5 + 38);
  else
    v10 = *(unsigned __int16 *)(v5 + 26);
  v11 = (float)v10;
  a3[2].pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)(__int64)v11;
  a3[3].pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)(__int64)GFxTextLineBuffer::Line::GetDescent(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v5);
  if ( *(int *)v5 >= 0 )
    v6 = *(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType **)(v5 + 20);
  else
    v6 = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)*(unsigned __int16 *)(v5 + 20);
  a3->pTable = v6;
  if ( *(int *)v5 >= 0 )
    v7 = *(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType **)(v5 + 24);
  else
    v7 = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)*(unsigned __int16 *)(v5 + 22);
  a3[1].pTable = v7;
  if ( *(int *)v5 >= 0 )
    v8 = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)*(__int16 *)(v5 + 40);
  else
    v8 = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)*(char *)(v5 + 29);
  a3[5].pTable = v8;
  a3[4].pTable = *(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType **)(v5 + 12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016EC10
// Name: public: bool GFxTextDocView::GetCharBoundaries(class GRect<float> __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextDocView::GetCharBoundaries(GFxStyledText **this, float *a2, unsigned int rv)
{
  int v5; // edi
  int v6; // eax
  bool v7; // cl
  unsigned int v8; // esi
  int v9; // esi
  int v10; // eax
  double v12; // st6
  double v13; // st5
  double v14; // st7
  double v15; // st6
  const VJobInstance *v17; // [esp+0h] [ebp-88h]
  const VJobInstance *v18; // [esp+0h] [ebp-88h]
  unsigned int v19; // [esp+Ch] [ebp-7Ch]
  unsigned int v20; // [esp+10h] [ebp-78h]
  _DWORD *v21; // [esp+68h] [ebp-20h] BYREF
  int v22; // [esp+70h] [ebp-18h]
  float v23; // [esp+7Ch] [ebp-Ch]
  unsigned int indexInLine; // [esp+80h] [ebp-8h]
  int advance; // [esp+84h] [ebp-4h]
  float v26; // [esp+90h] [ebp+8h]
  int v27; // [esp+90h] [ebp+8h]
  float v28; // [esp+90h] [ebp+8h]
  int v29; // [esp+90h] [ebp+8h]
  float v30; // [esp+90h] [ebp+8h]
  int v31; // [esp+90h] [ebp+8h]
  char rv_3; // [esp+97h] [ebp+Fh]

  if ( a2 == nullptr || rv >= GFxStyledText::GetLength(this: *(this + 2)) )
    return 0;
  if ( (*(_BYTE *)(this + 84) & 3) != 0 )
  {
    GFxTextDocView::Format(
      (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      a2: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  GFxTextLineBuffer::FindLineByTextPos(a1: this + 9, a2: &v21, a3: rv);
  rv_3 = 0;
  if ( v21 != nullptr && (unsigned int)v22 < v21[1] && v22 >= 0 )
  {
    v5 = *(_DWORD *)(*v21 + 4 * v22);
    v6 = *(_DWORD *)(v5 + 8);
    v7 = *(int *)v5 < 0;
    if ( *(int *)v5 < 0 )
    {
      v6 &= 0xFFFFFFu;
      if ( v6 == 0xFFFFFF )
        v6 = -1;
    }
    indexInLine = rv - v6;
    if ( v7 )
      advance = *(unsigned __int8 *)(v5 + 28);
    else
      advance = *(_DWORD *)(v5 + 4);
    v8 = v5 + 30;
    if ( !v7 )
      v8 = v5 + 42;
    GFxTextLineBuffer::Line::GetFormatData(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v5);
    v19 = v8;
    v20 = v8 + 8 * advance;
    GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: v17);
    advance = 0;
    v9 = 0;
    while ( v19 != 0 && v19 < v20 )
    {
      if ( v9 == indexInLine )
      {
        if ( (*(_BYTE *)(v19 + 7) & 1) == 0 )
        {
          *a2 = 0.0;
          rv_3 = 1;
          a2[1] = 0.0;
          v26 = 0.0 + 0.0;
          a2[2] = v26;
          a2[3] = v26;
          if ( (*(_BYTE *)(v19 + 6) & 0x40) != 0 )
            v27 = -*(unsigned __int16 *)(v19 + 2);
          else
            v27 = *(unsigned __int16 *)(v19 + 2);
          v28 = (double)v27 + a2[2];
          v12 = v28;
          a2[2] = v28;
          a2[1] = 40.0;
          if ( *(int *)v5 >= 0 )
            v29 = *(_DWORD *)(v5 + 24);
          else
            v29 = *(unsigned __int16 *)(v5 + 22);
          v30 = (float)v29;
          v13 = v30;
          a2[3] = v30;
          v31 = *(_DWORD *)(v5 + 16);
          v23 = (double)advance + 40.0;
          *(float *)&indexInLine = (float)v31;
          v14 = v23;
          *a2 = v23 + 0.0;
          a2[2] = v14 + v12;
          v15 = *(float *)&indexInLine;
          a2[1] = *(float *)&indexInLine + 40.0;
          a2[3] = v13 + v15;
        }
        return rv_3;
      }
      v10 = *(unsigned __int16 *)(v19 + 2);
      if ( (*(_BYTE *)(v19 + 6) & 0x40) != 0 )
        v10 = -v10;
      advance += v10;
      GFxTextLineBuffer::GlyphIterator::operator++(result: v18);
      ++v9;
    }
  }
  return rv_3;
}

//------------------------------------------------------------------------------
// Address: 0x1016EE80
// Name: public: bool GFxTextDocView::GetExactCharBoundaries(class GRect<float> __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxTextDocView::GetExactCharBoundaries(GFxStyledText **this, float *a2, unsigned int advance)
{
  unsigned int Length; // eax
  int v6; // edi
  int v7; // eax
  bool v8; // cl
  CIndexBufferBase *v9; // ebx
  int v10; // eax
  __int16 v11; // dx
  double FontSize; // st7
  int v13; // eax
  unsigned int v14; // ebx
  double v15; // st7
  double v16; // st6
  double v17; // st5
  int v18; // edx
  double v19; // st4
  double v20; // st7
  double v22; // st7
  const VJobInstance *v23; // [esp+0h] [ebp-8Ch]
  const VJobInstance *v24; // [esp+0h] [ebp-8Ch]
  unsigned __int16 *v25; // [esp+10h] [ebp-7Ch]
  _DWORD *v26; // [esp+68h] [ebp-24h] BYREF
  int v27; // [esp+70h] [ebp-1Ch]
  float v28; // [esp+80h] [ebp-Ch]
  unsigned int scale; // [esp+84h] [ebp-8h]
  unsigned int i; // [esp+88h] [ebp-4h]
  bool rv; // [esp+97h] [ebp+Bh]
  int advancea; // [esp+98h] [ebp+Ch]
  int advanceb; // [esp+98h] [ebp+Ch]
  float advancec; // [esp+98h] [ebp+Ch]
  float advanced; // [esp+98h] [ebp+Ch]

  Length = GFxStyledText::GetLength(this: *(this + 2));
  if ( a2 == nullptr || advance > Length )
    return false;
  if ( (*(_BYTE *)(this + 84) & 3) != 0 )
  {
    GFxTextDocView::Format(
      (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      a2: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  GFxTextLineBuffer::FindLineByTextPos(a1: this + 9, a2: &v26, a3: advance);
  rv = false;
  if ( v26 != nullptr && (unsigned int)v27 < v26[1] && v27 >= 0 )
  {
    v6 = *(_DWORD *)(*v26 + 4 * v27);
    v7 = *(_DWORD *)(v6 + 8);
    v8 = *(int *)v6 < 0;
    if ( *(int *)v6 < 0 )
    {
      v7 &= 0xFFFFFFu;
      if ( v7 == 0xFFFFFF )
        v7 = -1;
    }
    scale = advance - v7;
    if ( v8 )
      advancea = *(unsigned __int8 *)(v6 + 28);
    else
      advancea = *(_DWORD *)(v6 + 4);
    v9 = (CIndexBufferBase *)(v6 + 30);
    if ( !v8 )
      v9 = (CIndexBufferBase *)(v6 + 42);
    v25 = (unsigned __int16 *)&v9[advancea];
    GFxTextLineBuffer::Line::GetFormatData(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v6);
    GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: v23);
    advanceb = 0;
    *(float *)&i = 0.0;
    while ( v9 != nullptr && v9 < (CIndexBufferBase *)v25 )
    {
      if ( i == scale )
      {
        v11 = HIWORD(v9->m_pBudgetGroupName) >> 11;
        LODWORD(v28) = (char *)&v9->m_pBudgetGroupName + 2;
        rv = true;
        if ( (v11 & 1) != 0 )
        {
          *a2 = -(double)MEMORY[0x10];
          a2[1] = -(double)MEMORY[0x14];
          a2[2] = (double)MEMORY[0x18] + *a2;
          a2[3] = (double)MEMORY[0x1C] + a2[1];
          i = *(unsigned int *)(v6 + 16);
          advanced = (double)advanceb + 40.0;
          v28 = (double)(int)i + 40.0;
          *a2 = *a2 + advanced;
          a2[2] = advanced + a2[2];
          v22 = v28;
          a2[1] = v28 + a2[1];
          a2[3] = v22 + a2[3];
        }
        else
        {
          *(float *)&i = 0.0;
          FontSize = GFxTextLineBuffer::GlyphEntry::GetFontSize(this: v9);
          v13 = LOWORD(v9->__vftable);
          *(float *)&scale = FontSize * 20.0;
          *(float *)&scale = *(float *)&scale * 0.0009765625;
          if ( (_WORD)v13 == 0xFFFF )
            v13 = -1;
          v14 = i;
          (*(void (__thiscall **)(_DWORD, int, float *))(**(_DWORD **)(i + 12) + 48))(
            a1: *(_DWORD *)(i + 12),
            a2: v13,
            a3: a2);
          if ( (*(_BYTE *)(LODWORD(v28) + 1) & 1) != 0 )
          {
            v28 = a2[2] - *a2;
            v28 = v28 / 3.0;
            a2[2] = v28 + *a2;
          }
          v15 = *(float *)&scale;
          *(float *)&scale = (*(float *)(*(_DWORD *)(v14 + 12) + 12) + *(float *)(*(_DWORD *)(v14 + 12) + 8))
                           * *(float *)&scale;
          v28 = *a2 * v15;
          v16 = v28;
          *a2 = v28;
          v28 = a2[2] * v15;
          v17 = v28;
          a2[2] = v28;
          if ( *(int *)v6 >= 0 )
            LODWORD(v28) = *(unsigned __int16 *)(v6 + 38);
          else
            LODWORD(v28) = *(unsigned __int16 *)(v6 + 26);
          v18 = *(_DWORD *)(v14 + 12);
          *(float *)&i = (float)SLODWORD(v28);
          v28 = *(float *)&i - v15 * *(float *)(v18 + 8) + 40.0;
          v19 = v28;
          a2[1] = v28;
          a2[3] = v19 + *(float *)&scale;
          i = *(unsigned int *)(v6 + 16);
          advancec = (double)advanceb + 40.0;
          v28 = (float)(int)i;
          *a2 = v16 + advancec;
          a2[2] = v17 + advancec;
          v20 = v28;
          a2[1] = v28 + a2[1];
          a2[3] = v20 + a2[3];
        }
        return rv;
      }
      v10 = HIWORD(v9->__vftable);
      if ( (BYTE2(v9->m_pBudgetGroupName) & 0x40) != 0 )
        v10 = -v10;
      advanceb += v10;
      GFxTextLineBuffer::GlyphIterator::operator++(result: v24);
      ++i;
    }
  }
  return rv;
}

//------------------------------------------------------------------------------
// Address: 0x1016F210
// Name: public: unsigned int GFxTextDocView::GetBottomVScroll(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall GFxTextDocView::GetBottomVScroll@<eax>(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>)
{
  char *v3; // esi
  int v4; // edi
  bool v5; // bl
  IColorCorrectionSystem *v7; // [esp+4h] [ebp-14h]
  __int128 v8; // [esp+8h] [ebp-10h]
  int v9; // [esp+14h] [ebp-4h]

  if ( (*(_BYTE *)(this + 84) & 3) != 0 )
  {
    GFxTextDocView::Format(this, a2);
    *((_BYTE *)this + 336) &= 0xFCu;
  }
  v3 = (char *)(this + 9);
  GFxTextLineBuffer::GetVScrollOffsetInTwips(this: (CMatCallQueue *)v3, a2: v7, a3: v8);
  v4 = *((_DWORD *)v3 + 5);
  v5 = (v3[116] & 4) != 0;
  v9 = 0;
  while ( v3 != nullptr
       && (unsigned int)v4 < *((_DWORD *)v3 + 1)
       && v4 >= 0
       && (v5
        || (unsigned __int8)GFxTextLineBuffer::IsLineVisible(this: (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v3) != 0) )
  {
    v9 = v4;
    if ( (unsigned int)v4 < *((_DWORD *)v3 + 1) )
      ++v4;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1016F2A0
// Name: public: void GFxTextDocView::HighlightDesc::DrawBackground(class GFxTextDocView __near &,class GFxDisplayContext __near &,class GMatrix2D const __near &,class GRenderer::Cxform const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextDocView::HighlightDesc::DrawBackground(
        GArrayLH<GFxAmpMemSegment,2,GArrayDefaultPolicy> *this,
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *document,
        FBMAttributeMask_t context,
        float *context_4,
        const void *context_8)
{
  CMatCallQueue *v7; // ebx
  unsigned int v8; // eax
  unsigned int pTable; // eax
  const struct GFxTextCompositionString *v10; // eax
  int LineOffset; // eax
  int v12; // eax
  IColorCorrectionSystem *v13; // [esp+8h] [ebp-10h]
  __int128 _C; // [esp+Ch] [ebp-Ch]
  float newVScrollOffset; // [esp+14h] [ebp-4h]
  float newHScrollOffset; // [esp+20h] [ebp+8h]

  v7 = (CMatCallQueue *)&document[9];
  newHScrollOffset = (float)(unsigned int)document[19].pTable;
  GFxTextLineBuffer::GetVScrollOffsetInTwips(this: v7, a2: v13, a3: _C);
  newVScrollOffset = (float)v8;
  if ( *((_BYTE *)this + 24) == 0 )
  {
    pTable = (unsigned int)document[71].pTable;
    if ( pTable != 0 )
      v10 = *(const struct GFxTextCompositionString **)(pTable + 20);
    else
      v10 = nullptr;
    GFxTextHighlighter::UpdateGlyphIndices((GFxTextHighlighter *)this, a2: v10);
  }
  if ( this->Data.Size != 0
    && (*((_BYTE *)this + 24) == 0
     || newHScrollOffset != *((float *)this + 41)
     || newVScrollOffset != *((float *)this + 42)
     || *((_WORD *)this + 86) != LOWORD(document[82].pTable)) )
  {
    *((float *)this + 41) = newHScrollOffset;
    *((float *)this + 42) = newVScrollOffset;
    *((_WORD *)this + 86) = document[82].pTable;
    LineOffset = GFxTextDocView::GetLineOffset(this: document, a2: document, lineIndex: (signed int)document[14].pTable);
    GFxTextHighlighter::DrawBackground(
      a1: this,
      a2: (char *)this + 28,
      a3: v7,
      a4: &document[15],
      a5: LineOffset,
      a6: *((float *)this + 41),
      a7: *((float *)this + 42));
  }
  v12 = *((_DWORD *)this + 9);
  if ( v12 != 0 && (*(_DWORD *)(v12 + 84) != 0 || *(_DWORD *)(v12 + 96) != 0) )
    GFxDrawingContext::Display(
      this: (IClientTools *)this + 7,
      context,
      blend_4: context_4,
      blend_8: context_8,
      a5: 0,
      edgeAADisabled: false);
}

//------------------------------------------------------------------------------
// Address: 0x1016F3D0
// Name: public: void GFxTextDocView::Display(class GFxDisplayContext __near &,class GMatrix2D const __near &,class GRenderer::Cxform const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextDocView::Display(
        GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *this@<ecx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2@<edi>,
        const GArrayDefaultPolicy *context,
        float *a4,
        const void *a5,
        int a6)
{
  char v7; // cl
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al
  char v12; // al
  char v13; // dl
  GArrayLH<GFxAmpMemSegment,2,GArrayDefaultPolicy> *v14; // ecx
  int v15; // [esp+8h] [ebp-28h] BYREF
  int v16; // [esp+Ch] [ebp-24h]
  int v17; // [esp+10h] [ebp-20h]
  int v18; // [esp+14h] [ebp-1Ch]
  int v19; // [esp+18h] [ebp-18h]
  int v20; // [esp+1Ch] [ebp-14h]
  int v21; // [esp+20h] [ebp-10h]
  int v22; // [esp+24h] [ebp-Ch]
  int v23; // [esp+28h] [ebp-8h]
  char v24; // [esp+2Ch] [ebp-4h]

  if ( (*(_BYTE *)(this + 28) & 3) != 0 )
    GFxTextDocView::Format(
      (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      a2);
  v19 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0x100000;
  v18 = 0;
  v20 = 0x100000;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  GFxTextFieldParam::LoadFromTextFilter(this: (int)&v15, result: (const CResourcePreloadMaterial *)this + 72);
  v7 = *((_BYTE *)this + 334);
  v8 = HIBYTE(v16);
  if ( (v7 & 0x40) != 0 )
  {
    v8 = HIBYTE(v16) | 1;
    HIBYTE(v19) |= 1u;
  }
  if ( v7 < 0 )
  {
    v8 |= 2u;
    HIBYTE(v19) |= 2u;
  }
  if ( (*(_BYTE *)(this + 28) & 0x20) != 0 )
  {
    v9 = HIBYTE(v17) | 1;
    v8 = v8 & 0xF8 | 1;
  }
  else
  {
    v9 = HIBYTE(v17) & 0xFE;
  }
  v10 = *((_BYTE *)this + 335);
  if ( (v10 & 1) != 0 )
    v11 = v8 | 8;
  else
    v11 = v8 & 0xF7;
  if ( (v10 & 2) != 0 )
    v12 = v11 | 0x10;
  else
    v12 = v11 & 0xEF;
  v13 = v9 & 0xE1 | (2 * *((_BYTE *)this + 333));
  v14 = *((GArrayLH<GFxAmpMemSegment,2,GArrayDefaultPolicy> **)this + 5);
  HIBYTE(v16) = v12;
  HIBYTE(v17) = v13;
  if ( v14 != nullptr )
    GFxTextDocView::HighlightDesc::DrawBackground(
      this: v14,
      document: (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this,
      (FBMAttributeMask_t)context,
      context_4: a4,
      context_8: a5);
  GFxTextLineBuffer::Display(this: (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)(this + 3));
}

//------------------------------------------------------------------------------
// Address: 0x1016F4F0
// Name: public: GFxTextDocView::GFxTextDocView(class GFxTextAllocator __near *,class GFxFontManager __near *,class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None
