// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/text/gfxtexteditorkit.cpp
// Functions: 43
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\text\gfxtexteditorkit.h"

//------------------------------------------------------------------------------
// Address: 0x1016F6D0
// Name: public: bool GFxTextLineBuffer::IsLineVisible(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1016F710
// Name: public: void GFxTextIMEStyle::Unite(struct GFxTextIMEStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextIMEStyle::Unite(GPtr<GFxAmpMemFragReport> *this, const GPtr<GFxAmpMemFragReport> *st)
{
  if ( ((int)st[20].pObject & 1) != 0 )
  {
    *((_BYTE *)this + 80) |= 1u;
    this->pObject = st->pObject;
    *(this + 1) = st[1];
    *(this + 2) = st[2];
    *((_BYTE *)this + 12) = st[3].pObject;
  }
  if ( ((int)st[20].pObject & 2) != 0 )
  {
    *((_BYTE *)this + 80) |= 2u;
    *(this + 4) = st[4];
    *(this + 5) = st[5];
    *(this + 6) = st[6];
    *((_BYTE *)this + 28) = st[7].pObject;
  }
  if ( ((int)st[20].pObject & 4) != 0 )
  {
    *((_BYTE *)this + 80) |= 4u;
    *(this + 8) = st[8];
    *(this + 9) = st[9];
    *(this + 10) = st[10];
    *((_BYTE *)this + 44) = st[11].pObject;
  }
  if ( ((int)st[20].pObject & 8) != 0 )
  {
    *((_BYTE *)this + 80) |= 8u;
    *(this + 12) = st[12];
    *(this + 13) = st[13];
    *(this + 14) = st[14];
    *((_BYTE *)this + 60) = st[15].pObject;
  }
  if ( ((int)st[20].pObject & 0x10) != 0 )
  {
    *((_BYTE *)this + 80) |= 0x10u;
    *(this + 16) = st[16];
    *(this + 17) = st[17];
    *(this + 18) = st[18];
    *((_BYTE *)this + 76) = st[19].pObject;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F7D0
// Name: public: void GFxTextEditorKit::ResetBlink(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::ResetBlink(GFxTextEditorKit *this, bool a2, bool a3)
{
  if ( (*(_BYTE *)(this + 26) & 1) != 0 )
  {
    *((_WORD *)this + 52) &= ~8u;
  }
  else if ( a2 )
  {
    *((_WORD *)this + 52) |= 8u;
  }
  else
  {
    *((_WORD *)this + 52) &= ~8u;
  }
  *((double *)this + 7) = 0.0;
  if ( a3 )
    *((_WORD *)this + 52) |= 0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x1016F810
// Name: public: void GFxTextEditorKit::OnMouseUp(float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::OnMouseUp(GFxTextEditorKit *this, float x, float y, char buttons)
{
  __int16 v4; // ax

  if ( (buttons & 1) == 0 )
  {
    v4 = *((_WORD *)this + 52);
    if ( (v4 & 2) != 0 && (v4 & 0x20) != 0 )
      *((_WORD *)this + 52) = v4 & 0xFFDF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F840
// Name: public: void GFxTextCompositionString::UseStyles(struct GFxTextIMEStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextCompositionString::UseStyles(
        GPtr<GFxAmpMemFragReport> *this,
        const GPtr<GFxAmpMemFragReport> *styles)
{
  GFxTextIMEStyle::Unite(this: this + 17, st: styles);
}

//------------------------------------------------------------------------------
// Address: 0x1016F850
// Name: public: void GFxTextEditorKit::ClearWideCursor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::ClearWideCursor(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this)
{
  GFxTextHighlighter *v2; // ecx
  struct GFxTextHighlightDesc *HighlighterPtr; // eax

  *((_WORD *)this + 52) &= ~0x100u;
  v2 = *(GFxTextHighlighter **)(*((_DWORD *)this + 2) + 20);
  if ( v2 != nullptr )
  {
    HighlighterPtr = GFxTextHighlighter::GetHighlighterPtr(this: v2, a2: 0x7FFFFFFEu);
    if ( HighlighterPtr != nullptr && *((_DWORD *)HighlighterPtr + 1) != 0 )
    {
      *((_DWORD *)HighlighterPtr + 1) = 0;
      GFxTextDocView::UpdateHighlight(
        this: *((GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> **)this + 2),
        desc: (unsigned int)HighlighterPtr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F890
// Name: public: bool GFxTextEditorKit::OnKeyUp(int,class GFxSpecialKeysState const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextEditorKit::OnKeyUp(
        GFxTextEditorKit *this,
        unsigned int keyCode,
        const struct GFxSpecialKeysState *a3)
{
  GenericThreadLocals::CThreadLocalPtr<IMatRenderContextInternal> *v4; // ecx
  _DWORD *v5; // eax
  __int16 v6; // ax

  v4 = *((GenericThreadLocals::CThreadLocalPtr<IMatRenderContextInternal> **)this + 4);
  if ( v4 != nullptr )
  {
    v5 = GFxTextKeyMap::Find(this: v4, keyCode, a3: &a3->States, a4: 1);
    if ( v5 != nullptr && *v5 == 3 )
    {
      v6 = *((_WORD *)this + 52);
      if ( (v6 & 2) != 0 && (v6 & 0x40) != 0 )
        *((_WORD *)this + 52) = v6 & 0xFFBF;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016F8E0
// Name: public: void GFxTextEditorKit::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::OnSetFocus(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this)
{
  GFxTextDocView::SetSelectionTextColor(
    this: *((struct GFxTextHighlightDesc ***)this + 2),
    color: *((_DWORD *)this + 23));
  GFxTextDocView::SetSelectionBackgroundColor(
    this: *((struct GFxTextHighlightDesc ***)this + 2),
    color: *((_DWORD *)this + 22));
  *((_WORD *)this + 52) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x1016F910
// Name: public: void GFxTextEditorKit::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::OnKillFocus(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this)
{
  GFxTextDocView::SetSelectionTextColor(
    this: *((struct GFxTextHighlightDesc ***)this + 2),
    color: *((_DWORD *)this + 25));
  GFxTextDocView::SetSelectionBackgroundColor(
    this: *((struct GFxTextHighlightDesc ***)this + 2),
    color: *((_DWORD *)this + 24));
  *((_WORD *)this + 52) &= 0xFB9Fu;
}

//------------------------------------------------------------------------------
// Address: 0x1016F940
// Name: public: void GFxTextEditorKit::CopyToClipboard(unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::CopyToClipboard(
        GFxTextEditorKit *this,
        const char *startPos,
        const struct GFxTextParagraph *endPos,
        bool a4)
{
  int v5; // ecx
  const struct GFxTextParagraph *v6; // esi
  const char *v7; // edi
  SFTextObjectImpl *v8; // esi
  wchar_t *pText; // eax
  wchar_t *v10; // eax
  GFxWStringBuffer result; // [esp+4h] [ebp-10h] BYREF

  if ( *((_DWORD *)this + 3) != 0 )
  {
    v5 = *((_DWORD *)this + 2);
    if ( (*(_BYTE *)(v5 + 334) & 0x10) == 0 )
    {
      v6 = endPos;
      v7 = startPos;
      if ( endPos < (const struct GFxTextParagraph *)startPos )
      {
        v6 = (const struct GFxTextParagraph *)startPos;
        v7 = (const char *)endPos;
      }
      memset(&result, 0, sizeof(result));
      GFxStyledText::GetText(
        this: *(CUtlMemory<GFxValue,int> **)(v5 + 8),
        a2: &result,
        indexInPara: (unsigned int)v7,
        oldSize: (unsigned int)v6);
      if ( a4 )
      {
        v8 = GFxStyledText::CopyStyledText(
               this: *(SFTextObjectImpl **)(*((_DWORD *)this + 2) + 8),
               a2: (int)this,
               startPos: v7,
               endPos: v6);
        pText = result.pText;
        if ( result.pText == nullptr )
          pText = (wchar_t *)&word_1028F3E0;
        GFxTextClipboard::SetTextAndStyledText(
          this: *((CBaseAutoPtr<IMatRenderContext> **)this + 3),
          result: (IMatRenderContext *)pText,
          a3: result.Length,
          a4: (GFxStyledText *)v8);
        if ( v8 != nullptr )
        {
          GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v8);
          GFxWStringBuffer::~GFxWStringBuffer(this: (CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&result);
          return;
        }
      }
      else
      {
        v10 = result.pText;
        if ( result.pText == nullptr )
          v10 = (wchar_t *)&word_1028F3E0;
        GFxTextClipboard::SetText(this: *((CBaseAutoPtr<IMatRenderContext> **)this + 3), ptext: v10, a3: result.Length);
      }
      GFxWStringBuffer::~GFxWStringBuffer(this: (CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&result);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FA10
// Name: public: void GFxTextEditorKit::CutToClipboard(unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::CutToClipboard(
        GFxTextEditorKit *this,
        const char *startPos,
        const struct GFxTextParagraph *endPos,
        bool a4)
{
  const struct GFxTextParagraph *v5; // esi
  const char *v6; // edi
  int v7; // ebx

  if ( *((_DWORD *)this + 3) != 0 )
  {
    v5 = endPos;
    v6 = startPos;
    if ( endPos < (const struct GFxTextParagraph *)startPos )
    {
      v5 = (const struct GFxTextParagraph *)startPos;
      v6 = (const char *)endPos;
    }
    GFxTextEditorKit::CopyToClipboard(this, startPos: v6, endPos: v5, a4);
    if ( (*(_BYTE *)(this + 26) & 1) == 0 )
    {
      v7 = *((_DWORD *)this + 2);
      if ( v5 < (const struct GFxTextParagraph *)v6 )
        GFxStyledText::Remove(this: *(SFTextObjectImpl **)(v7 + 8), a2: (unsigned int)v6, Length: 0);
      else
        GFxStyledText::Remove(this: *(SFTextObjectImpl **)(v7 + 8), a2: (unsigned int)v6, Length: (char *)v5 - v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FA70
// Name: public: unsigned int GFxTextEditorKit::PasteFromClipboard(unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextEditorKit::PasteFromClipboard(
        GFxTextEditorKit *this,
        GFxAmpHeapInfo *startPos,
        GFxAmpHeapInfo *endPos,
        bool useRichClipboard)
{
  int v5; // edi
  CVTFTexture *v6; // ecx
  unsigned int v7; // eax
  GFxAmpHeapInfo *v8; // esi
  int v9; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v10; // ecx
  int v11; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v12; // ebx
  const IMatRenderContext *Text; // eax
  IMatRenderContext_vtbl *v15; // ecx
  const wchar_t *v16; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v17; // ecx
  int v18; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v19; // ebx
  int v20; // eax
  _DWORD v21[4]; // [esp+8h] [ebp-30h] BYREF
  GPtr<GFxAmpHeapInfo> cmd; // [esp+18h] [ebp-20h] BYREF
  const wchar_t *v23; // [esp+1Ch] [ebp-1Ch]
  IMatRenderContext_vtbl *v24; // [esp+20h] [ebp-18h]
  _DWORD v25[3]; // [esp+24h] [ebp-14h] BYREF
  _DWORD v26[2]; // [esp+30h] [ebp-8h] BYREF
  GRefCountNTSImpl *useRichClipboarda; // [esp+48h] [ebp+10h]

  v5 = -1;
  if ( (*(_BYTE *)(this + 26) & 1) != 0 )
    return -1;
  v6 = *((CVTFTexture **)this + 3);
  if ( v6 == nullptr )
    return -1;
  v7 = (unsigned int)endPos;
  v8 = startPos;
  if ( endPos < startPos )
  {
    endPos = startPos;
    v8 = (GFxAmpHeapInfo *)v7;
  }
  if ( useRichClipboard && v6->m_nMipCount != 0 )
  {
    v9 = CMatQueuedIndexBuffer::IndexFormat(this: v6);
    useRichClipboarda = (GRefCountNTSImpl *)v9;
    if ( v9 != 0 )
    {
      ++*(_DWORD *)(v9 + 4);
      if ( GFxStyledText::GetLength(this: (GFxStyledText *)v9) != 0 )
      {
        *((_WORD *)this + 52) &= ~0x40u;
        if ( v8 == endPos )
        {
          v26[1] = useRichClipboarda;
          v10 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
          v26[0] = v8;
          GFxTextDocView::EditCommand(this: v10, a2: (const char *)this, cmdId: 2u, command: (ButtonCode_t)v26);
        }
        else
        {
          v12 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
          v25[1] = endPos;
          v25[0] = v8;
          v25[2] = useRichClipboarda;
          GFxTextDocView::EditCommand(this: v12, a2: (const char *)v12, cmdId: 7u, command: (ButtonCode_t)v25);
        }
        v5 = (int)v8 + v11;
      }
      GRefCountNTSImpl::Release(this: useRichClipboarda);
    }
    return v5;
  }
  Text = GFxTextClipboard::GetText(this: (char *)v6);
  if ( Text[1].__vftable == nullptr )
    return v5;
  *((_WORD *)this + 52) &= ~0x40u;
  v15 = Text[1].__vftable;
  v16 = (const wchar_t *)Text->__vftable;
  if ( v8 == endPos )
  {
    if ( v16 == nullptr )
      v16 = &word_1028F3E0;
    v23 = v16;
    v24 = v15;
    v17 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
    cmd.pObject = v8;
    GFxTextDocView::EditCommand(this: v17, a2: (const char *)this, cmdId: 1u, command: (ButtonCode_t)&cmd);
    return (int)v8 + v18;
  }
  else
  {
    if ( v16 == nullptr )
      v16 = &word_1028F3E0;
    v19 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
    v21[3] = v15;
    v21[0] = v8;
    v21[1] = endPos;
    v21[2] = v16;
    GFxTextDocView::EditCommand(this: v19, a2: (const char *)v19, cmdId: 6u, command: (ButtonCode_t)v21);
    return (int)v8 + v20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FBB0
// Name: protected: void GFxTextEditorKit::InvalidateSelectionColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::InvalidateSelectionColors(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this)
{
  if ( (*(_WORD *)(this + 26) & 0x400) != 0 )
  {
    GFxTextDocView::SetSelectionTextColor(
      this: *((struct GFxTextHighlightDesc ***)this + 2),
      color: *((_DWORD *)this + 23));
    GFxTextDocView::SetSelectionBackgroundColor(
      this: *((struct GFxTextHighlightDesc ***)this + 2),
      color: *((_DWORD *)this + 22));
  }
  else
  {
    GFxTextDocView::SetSelectionTextColor(
      this: *((struct GFxTextHighlightDesc ***)this + 2),
      color: *((_DWORD *)this + 25));
    GFxTextDocView::SetSelectionBackgroundColor(
      this: *((struct GFxTextHighlightDesc ***)this + 2),
      color: *((_DWORD *)this + 24));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FC00
// Name: protected: unsigned int GFxTextEditorKit::TextPos2GlyphOffset(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextEditorKit::TextPos2GlyphOffset(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this@<ecx>,
        void *textPos,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a3)
{
  GFxResourceId *v4; // eax
  GFxResourceId *v5; // esi

  v4 = *((GFxResourceId **)this + 5);
  if ( v4 != nullptr && GFxTextParagraph::GetLength(this: v4 + 5) != 0 )
  {
    v5 = *((GFxResourceId **)this + 5);
    if ( (unsigned int)textPos > v5[12].Id )
      GFxTextParagraph::GetLength(this: v5 + 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FC40
// Name: public: void GFxTextCompositionString::ClearHighlighting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextCompositionString::ClearHighlighting(GFxTextCompositionString *this)
{
  int v2; // eax
  unsigned int v3; // edi
  GFxTextHighlighter *v4; // eax
  unsigned int *v5; // ebx
  struct GFxTextHighlightDesc *HighlighterPtr; // eax
  GFxTextHighlighter *v7; // [esp+8h] [ebp-4h]

  v2 = *((_DWORD *)this + 3);
  *((_BYTE *)this + 64) = 0;
  GFxTextDocView::CreateHighlighterManager(this: *(GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> **)(v2 + 8));
  v3 = 0;
  v7 = v4;
  if ( *((_BYTE *)this + 192) != 0 )
  {
    v5 = (unsigned int *)((char *)this + 152);
    do
    {
      HighlighterPtr = GFxTextHighlighter::GetHighlighterPtr(this: v7, a2: *v5);
      *(_DWORD *)HighlighterPtr = 0;
      *((_DWORD *)HighlighterPtr + 1) = 0;
      GFxTextDocView::UpdateHighlight(
        this: *(GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> **)(*((_DWORD *)this + 3) + 8),
        desc: (unsigned int)HighlighterPtr);
      ++v3;
      ++v5;
    }
    while ( v3 < *((unsigned __int8 *)this + 192) );
  }
  *((_BYTE *)this + 192) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016FCC0
// Name: public: void CachedValue<class GRect<float>>::SetValue(class GRect<float> const __near &,unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CachedValue<GRect<float>>::SetValue(
        float *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v,
        unsigned __int16 counter)
{
  double v4; // st7
  int m_Size; // [esp+0h] [ebp-8h]
  int m_nGrowSize; // [esp+4h] [ebp-4h]
  int va; // [esp+10h] [ebp+8h]

  va = v->m_Memory.m_nAllocationCount;
  m_nGrowSize = v->m_Memory.m_nGrowSize;
  m_Size = v->m_Size;
  v4 = *(float *)&v->m_Memory.m_pMemory;
  *this = v4;
  *((_WORD *)this + 8) = counter;
  *(this + 1) = *(float *)&va;
  *(this + 2) = *(float *)&m_nGrowSize;
  *(this + 3) = *(float *)&m_Size;
  return counter;
}

//------------------------------------------------------------------------------
// Address: 0x1016FD60
// Name: public: void GFxTextEditorKit::PreDisplay(class GFxDisplayContext __near &,class GMatrix2D const __near &,class GRenderer::Cxform const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::PreDisplay(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this,
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::Iterator *result,
        int context_4,
        int context_8)
{
  GFxTextHighlighter *v5; // eax
  IVJobs *v6; // edi
  IVJobs *HighlighterPtr; // eax
  bool v8; // bl
  IVJobs_vtbl *v9; // edi
  int (__cdecl *desc)(const char *const *, const char *const *); // [esp+4h] [ebp-28h] BYREF
  int v11; // [esp+8h] [ebp-24h]
  int v12; // [esp+Ch] [ebp-20h]
  int v13; // [esp+10h] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-18h]
  int v15; // [esp+18h] [ebp-14h]
  int v16; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  char v19; // [esp+28h] [ebp-4h]

  if ( (*(_BYTE *)(this + 26) & 1) == 0 && (*((_BYTE *)this + 105) & 1) != 0 )
  {
    GFxTextDocView::CreateHighlighterManager(this: *((GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> **)this
                                                   + 2));
    v6 = (IVJobs *)v5;
    HighlighterPtr = (IVJobs *)GFxTextHighlighter::GetHighlighterPtr(this: v5, a2: 0x7FFFFFFEu);
    v8 = false;
    if ( HighlighterPtr != nullptr )
    {
      v8 = HighlighterPtr[1].__vftable != nullptr;
    }
    else
    {
      v13 = 0;
      v14 = 0;
      v18 = 0;
      desc = nullptr;
      v11 = 0;
      v12 = 0;
      v15 = 2147483646;
      v16 = -16777216;
      v19 = 24;
      v17 = -1;
      HighlighterPtr = GFxTextHighlighter::CreateHighlighter(this: v6, (const IVJobs *)&desc);
    }
    v9 = *((IVJobs_vtbl **)this + 6);
    if ( HighlighterPtr->__vftable != v9 || v8 != ((*(_BYTE *)(this + 26) & 8) != 0) )
    {
      HighlighterPtr->__vftable = v9;
      HighlighterPtr[1].__vftable = (IVJobs_vtbl *)((*((_WORD *)this + 52) >> 3) & 1);
      GFxTextDocView::UpdateHighlight(
        this: *((GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> **)this + 2),
        desc: (unsigned int)HighlighterPtr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FE20
// Name: private: void GFxTextCompositionString::Reformat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextCompositionString::Reformat(GFxTextCompositionString *this)
{
  int v2; // eax
  _DWORD *v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h]

  GFxStyledText::GetParagraphByIndex(
    this: *(SFTextObjectImpl **)(*(_DWORD *)(*((_DWORD *)this + 3) + 8) + 8),
    index: (GFxValue *)&v3,
    indexa: *((_DWORD *)this + 12),
    pindexInParagraph: nullptr);
  if ( v3 != nullptr && v4 >= 0 && v4 < v3[1] )
  {
    v2 = *(_DWORD *)(*v3 + 4 * v4);
    if ( v2 != 0 )
    {
      ++*(_WORD *)(v2 + 36);
      *(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 3) + 8) + 336) |= 1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FE80
// Name: public: void GFxTextCompositionString::SetText(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextCompositionString::SetText(
        GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *this,
        wchar_t *nchars,
        unsigned int a3)
{
  int v4; // eax
  _DWORD *v5; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h]

  GFxTextCompositionString::ClearHighlighting((GFxTextCompositionString *)this);
  GFxTextParagraph::Clear(this: (int)this + 20);
  GFxTextParagraph::SetText(
    this: (GFxTextParagraph *)this + 5,
    length: *((struct GFxTextAllocator **)this + 4),
    src: nchars,
    a4: a3);
  GFxTextParagraph::SetTextFormat(
    this: (int)this + 20,
    pallocator: *((CMaterial **)this + 4),
    fmt_4: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)this->Policy.Capacity,
    startPos: 0,
    length: *((_DWORD *)this + 6));
  GFxTextParagraph::AppendTermNull(
    this: (GFxTextParagraph *)this + 5,
    result: *((GFxFontMap **)this + 4),
    a3: (const struct GFxTextFormat *)this->Policy.Capacity);
  GFxStyledText::GetParagraphByIndex(
    this: *(SFTextObjectImpl **)(*(_DWORD *)(*((_DWORD *)this + 3) + 8) + 8),
    index: (GFxValue *)&v5,
    indexa: *((_DWORD *)this + 12),
    pindexInParagraph: nullptr);
  if ( v5 != nullptr && v6 >= 0 && v6 < v5[1] )
  {
    v4 = *(_DWORD *)(*v5 + 4 * v6);
    if ( v4 != 0 )
    {
      ++*(_WORD *)(v4 + 36);
      *(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 3) + 8) + 336) |= 1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FF30
// Name: public: void GFxTextCompositionString::SetPosition(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextCompositionString::SetPosition(
        GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *this,
        unsigned int pos)
{
  int v3; // ecx
  int v4; // eax
  _DWORD *v5; // [esp+4h] [ebp-8h] BYREF
  int v6; // [esp+8h] [ebp-4h]

  v3 = *((_DWORD *)this + 3);
  *((_DWORD *)this + 12) = pos;
  GFxStyledText::GetParagraphByIndex(
    this: *(SFTextObjectImpl **)(*(_DWORD *)(v3 + 8) + 8),
    index: (GFxValue *)&v5,
    indexa: pos,
    pindexInParagraph: nullptr);
  if ( v5 != nullptr && v6 >= 0 && v6 < v5[1] )
  {
    v4 = *(_DWORD *)(*v5 + 4 * v6);
    if ( v4 != 0 )
    {
      ++*(_WORD *)(v4 + 36);
      *(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 3) + 8) + 336) |= 1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FF90
// Name: protected: GFxTextEditorKit::GFxTextEditorKit(class GFxTextDocView __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextEditorKit::GFxTextEditorKit(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this@<ecx>,
        _DWORD *pdocview,
        unsigned int a3)
{
  float pdocviewa; // [esp+8h] [ebp+8h]

  this->pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  this->pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)&GFxTextEditorKit::`vftable';
  if ( pdocview != nullptr )
    ++pdocview[1];
  *((_DWORD *)this + 2) = pdocview;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((float *)this + 9) = 0.0;
  *((float *)this + 10) = 0.0;
  *((float *)this + 11) = 0.0;
  *((_WORD *)this + 26) = 0;
  *((float *)this + 12) = 0.0;
  *((_WORD *)this + 52) = 0;
  *((_DWORD *)this + 6) = 0;
  *((double *)this + 7) = 0.0;
  *((_DWORD *)this + 7) = -16777216;
  *((double *)this + 8) = 0.0;
  *((_DWORD *)this + 21) = 0;
  *((float *)this + 18) = -1.0;
  *((float *)this + 9) = 0.0;
  *((float *)this + 10) = 0.0;
  pdocviewa = 0.0 + 0.0;
  *((float *)this + 11) = pdocviewa;
  *((float *)this + 12) = pdocviewa;
  *((_DWORD *)this + 22) = -16777216;
  *((_DWORD *)this + 23) = -1;
  *((_DWORD *)this + 24) = -8355712;
  *((_DWORD *)this + 25) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10170030
// Name: public: void GFxTextEditorKit::ReleaseCompositionString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::ReleaseCompositionString(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this)
{
  int v2; // eax
  GRefCountNTSImpl *v3; // edi

  v2 = *((_DWORD *)this + 5);
  if ( v2 != 0 )
  {
    ++*(_DWORD *)(v2 + 4);
    v3 = *((GRefCountNTSImpl **)this + 5);
    if ( v3 != nullptr )
      GRefCountNTSImpl::Release(this: v3);
    *((_DWORD *)this + 5) = 0;
    GFxTextCompositionString::Reformat(this: (GFxTextCompositionString *)v3);
    if ( v3 != nullptr )
      GRefCountNTSImpl::Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10170070
// Name: public: static struct GFxTextIMEStyle GFxTextCompositionString::GetDefaultStyles(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFxTextCompositionString::GetDefaultStyles(int a1)
{
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_BYTE *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 40) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  *(_BYTE *)(a1 + 44) = 0;
  *(_DWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 52) = 0;
  *(_DWORD *)(a1 + 48) = 0;
  *(_BYTE *)(a1 + 60) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  *(_DWORD *)(a1 + 68) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  *(_BYTE *)(a1 + 76) = 0;
  *(_BYTE *)(a1 + 80) = 1;
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_BYTE *)(a1 + 12) = 3;
  *(_BYTE *)(a1 + 80) |= 2u;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_BYTE *)(a1 + 28) = 2;
  *(_BYTE *)(a1 + 80) |= 4u;
  *(_DWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 40) = 0;
  *(_BYTE *)(a1 + 44) = 1;
  *(_BYTE *)(a1 + 80) |= 8u;
  *(_DWORD *)(a1 + 48) = -16777216;
  *(_DWORD *)(a1 + 52) = -1;
  *(_DWORD *)(a1 + 56) = 0;
  *(_BYTE *)(a1 + 60) = 24;
  *(_BYTE *)(a1 + 80) |= 0x10u;
  *(_DWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 68) = 0;
  *(_DWORD *)(a1 + 72) = 65280;
  *(_BYTE *)(a1 + 76) = 33;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10170120
// Name: public: bool GFxTextEditorKit::CalcCursorRectInLineBuffer(unsigned int,class GRect<float> __near *,unsigned int __near *,unsigned int __near *,bool,enum GFxTextLineBuffer::Line::Alignment __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxTextEditorKit::CalcCursorRectInLineBuffer@<al>(
        int a1@<ecx>,
        const VJobInstance *a2@<ebx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a3@<edi>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *result,
        float *a5,
        unsigned int *plineIndex,
        unsigned int *pglyphIndex,
        char avoidComposStr,
        int *xoffset)
{
  unsigned int LineIndexOfChar; // eax
  int v11; // edx
  int v12; // eax
  bool v13; // cl
  int v14; // edi
  unsigned __int16 *v15; // esi
  unsigned int i; // edi
  unsigned __int16 *v17; // eax
  unsigned __int16 v18; // cx
  int v19; // eax
  unsigned int v20; // esi
  unsigned __int16 v21; // dx
  int v22; // ecx
  unsigned int v23; // ecx
  int v24; // esi
  double v25; // st7
  double v26; // st6
  double v27; // st7
  struct GFxFontHandle *v28; // esi
  GFxFontManager *v29; // ecx
  IShaderDevice *v30; // ecx
  IShaderDevice *v31; // ecx
  IShaderDevice *v32; // ecx
  volatile LONG *v33; // edi
  const VJobInstance *v35; // [esp-4h] [ebp-74h]
  unsigned __int16 *v36; // [esp+8h] [ebp-68h]
  unsigned __int16 *v37; // [esp+Ch] [ebp-64h]
  CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> v38; // [esp+14h] [ebp-5Ch] BYREF
  char v39; // [esp+44h] [ebp-2Ch]
  int v40; // [esp+48h] [ebp-28h]
  int v41; // [esp+4Ch] [ebp-24h]
  int v42; // [esp+50h] [ebp-20h]
  struct GFxFontHandle *v43; // [esp+54h] [ebp-1Ch]
  GRefCountNTSImpl *v44; // [esp+58h] [ebp-18h]
  int v45; // [esp+5Ch] [ebp-14h]
  unsigned int p; // [esp+60h] [ebp-10h]
  unsigned int lineIndex; // [esp+64h] [ebp-Ch]
  int v48; // [esp+68h] [ebp-8h]
  unsigned int posInLine; // [esp+6Ch] [ebp-4h]
  unsigned int w; // [esp+78h] [ebp+8h]
  float wa; // [esp+78h] [ebp+8h]
  int avoidComposStra; // [esp+88h] [ebp+18h]
  float avoidComposStrc; // [esp+88h] [ebp+18h]
  float avoidComposStrd; // [esp+88h] [ebp+18h]
  int avoidComposStrb; // [esp+88h] [ebp+18h]
  int xoffseta; // [esp+8Ch] [ebp+1Ch]

  GFxTextDocView::ForceReformat(
    this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(a1 + 8),
    a2: a3);
  LineIndexOfChar = GFxTextDocView::GetLineIndexOfChar(
                      this: *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)(a1 + 8),
                      a2: result,
                      indexOfChar: (unsigned int)result);
  lineIndex = LineIndexOfChar;
  if ( LineIndexOfChar == -1 )
    return 0;
  v11 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 36) + 4 * LineIndexOfChar);
  v48 = v11;
  if ( xoffset != nullptr )
    *xoffset = (*(_DWORD *)v11 >> 28) & 3;
  v12 = *(_DWORD *)(v11 + 8);
  v13 = *(int *)v11 < 0;
  if ( *(int *)v11 < 0 )
  {
    v12 &= 0xFFFFFFu;
    if ( v12 == 0xFFFFFF )
      v12 = -1;
  }
  posInLine = (unsigned int)result - v12;
  xoffseta = 0;
  if ( v13 )
    v14 = *(unsigned __int8 *)(v11 + 28);
  else
    v14 = *(_DWORD *)(v11 + 4);
  v15 = (unsigned __int16 *)(v11 + 30);
  if ( !v13 )
    v15 = (unsigned __int16 *)(v11 + 42);
  v38.m_iRefs = -1;
  v38.m_Proxy.m_pfnProxied = 0xFFFFFFFF00000000uLL;
  memset(&v38.m_Proxy.m_pObject, 0, 16);
  v39 = 0;
  v38.CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
  v38.m_nUserID = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = nullptr;
  v44 = nullptr;
  v45 = 0;
  p = 0;
  v37 = &v15[4 * v14];
  GFxTextLineBuffer::Line::GetFormatData(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v11);
  GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: a2);
  for ( i = 0; ; ++i )
  {
    v17 = v15;
    if ( v15 == nullptr )
      break;
    if ( v15 >= v37 )
      break;
    if ( (v15[2] & 0xF000) != 0 )
      break;
    v18 = v15[3];
    if ( (v18 & 0x100) != 0 )
      break;
    v19 = v15[1];
    if ( (v18 & 0x40) != 0 )
      v19 = -v19;
    xoffseta += v19;
    GFxTextLineBuffer::GlyphIterator::operator++(result: v35);
  }
  v20 = 0;
  for ( w = i; v20 < posInLine; v17 = v36 )
  {
    if ( v17 == nullptr || v17 >= v37 )
      break;
    v21 = v17[3];
    v22 = v17[1];
    if ( (v21 & 0x40) != 0 )
      v22 = -v22;
    xoffseta += v22;
    if ( avoidComposStr == 0 || (v21 & 4) == 0 )
      v20 += v17[2] >> 12;
    v23 = p;
    i = ++w;
    if ( p == 0 )
    {
      v23 = v17[2] >> 12;
      p = v23;
    }
    v36 = v17 + 4;
    if ( (v17[6] & 0xF000) != 0
      && v23 != 0
      && !GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)&v38) )
    {
      GFxTextHighlighterPosIterator::operator+=(this: &v38, p);
      p = 0;
    }
    GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: v35);
  }
  wa = 0.0;
  if ( v17 != nullptr && v17 < v37 )
  {
    if ( (v17[3] & 0x40) != 0 )
      avoidComposStra = -v17[1];
    else
      avoidComposStra = v17[1];
    wa = (float)avoidComposStra;
  }
  v24 = v48;
  avoidComposStrc = (double)*(int *)(v48 + 12) + (double)xoffseta;
  v25 = avoidComposStrc;
  *a5 = avoidComposStrc;
  avoidComposStrd = (float)*(int *)(v24 + 16);
  a5[1] = avoidComposStrd;
  v26 = v25 + wa;
  v27 = avoidComposStrd;
  a5[2] = v26;
  if ( *(int *)v24 >= 0 )
    avoidComposStrb = *(_DWORD *)(v24 + 24);
  else
    avoidComposStrb = *(unsigned __int16 *)(v24 + 22);
  a5[3] = v27 + (double)avoidComposStrb;
  if ( plineIndex != nullptr )
    *plineIndex = lineIndex;
  if ( pglyphIndex != nullptr )
    *pglyphIndex = i;
  if ( v44 != nullptr )
    GRefCountNTSImpl::Release(this: v44);
  v28 = v43;
  if ( v43 != nullptr )
  {
    --*(_DWORD *)v43;
    if ( *(_DWORD *)v28 == 0 )
    {
      v29 = *((GFxFontManager **)v28 + 1);
      if ( v29 != nullptr )
        GFxFontManager::RemoveFontHandle(this: v29, a2: v28);
      v30 = *((IShaderDevice **)v28 + 7);
      if ( v30 != nullptr )
        GFxResource::Release(this: v30);
      *((_DWORD *)v28 + 7) = 0;
      v31 = *((IShaderDevice **)v28 + 8);
      if ( v31 != nullptr )
        GFxResource::Release(this: v31);
      v32 = *((IShaderDevice **)v28 + 7);
      if ( v32 != nullptr )
        GFxResource::Release(this: v32);
      v33 = (volatile LONG *)(*((_DWORD *)v28 + 3) & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: v33 + 1, Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v33);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v28);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10170440
// Name: public: bool GFxTextEditorKit::CalcCursorRectOnScreen(unsigned int,class GRect<float> __near *,unsigned int __near *,unsigned int __near *,bool,enum GFxTextLineBuffer::Line::Alignment __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxTextEditorKit::CalcCursorRectOnScreen@<al>(
        int a1@<ecx>,
        const VJobInstance *a2@<ebx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *result,
        float *a4,
        unsigned int *plineIndex,
        unsigned int *pglyphIndex,
        char avoidComposStr,
        GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *plineAlignment)
{
  char v9; // bl
  int v10; // eax
  unsigned int v11; // eax
  float *ViewRect; // eax
  int v13; // ecx
  double v14; // st6
  int v15; // ecx
  double v16; // st7
  IColorCorrectionSystem *v18; // [esp+0h] [ebp-1Ch]
  __int128 v19; // [esp+4h] [ebp-18h]
  float v20; // [esp+Ch] [ebp-10h]
  float v21; // [esp+10h] [ebp-Ch]
  float v22; // [esp+10h] [ebp-Ch]
  float v23; // [esp+14h] [ebp-8h]
  float v24; // [esp+14h] [ebp-8h]
  float v25; // [esp+18h] [ebp-4h]
  float v26; // [esp+18h] [ebp-4h]

  v9 = GFxTextEditorKit::CalcCursorRectInLineBuffer(
         a1,
         a2,
         a3: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)a1,
         result,
         a5: a4,
         plineIndex,
         pglyphIndex,
         avoidComposStr,
         xoffset: (int *)plineAlignment);
  if ( v9 != 0 )
  {
    v10 = *(_DWORD *)(a1 + 8);
    v23 = -(double)*(unsigned int *)(v10 + 76);
    GFxTextLineBuffer::GetVScrollOffsetInTwips(this: (CMatCallQueue *)(v10 + 36), a2: v18, a3: v19);
    v25 = -(double)v11;
    *a4 = *a4 + v23;
    a4[2] = v23 + a4[2];
    a4[1] = v25 + a4[1];
    a4[3] = v25 + a4[3];
    ViewRect = (float *)GFxTextDocView::GetViewRect(
                          this: *(GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)(a1 + 8),
                          a2: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)a1);
    v13 = *(_DWORD *)(a1 + 8);
    v20 = *(float *)(v13 + 60) - *ViewRect + *a4;
    v21 = *(float *)(v13 + 64) - ViewRect[1] + a4[1];
    *a4 = v20;
    v14 = v21;
    a4[1] = v21;
    v15 = *(_DWORD *)(a1 + 8);
    v24 = *(float *)(v15 + 60) - *ViewRect + a4[2];
    v26 = *(float *)(v15 + 64) - ViewRect[1] + a4[3];
    a4[2] = v24;
    a4[3] = v26;
    v22 = ViewRect[1];
    v16 = *ViewRect;
    *a4 = v20 + v16;
    a4[2] = v24 + v16;
    a4[1] = v14 + v22;
    a4[3] = v26 + v22;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10170570
// Name: protected: class GFxTextLineBuffer::GlyphEntry const __near * GFxTextEditorKit::GetGlyphEntryAtIndex(unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
const struct GFxTextLineBuffer::GlyphEntry *__userpurge GFxTextEditorKit::GetGlyphEntryAtIndex@<eax>(
        GFxTextEditorKit *this@<ecx>,
        const VJobInstance *a2@<ebx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a3,
        unsigned int *a4)
{
  unsigned int LineIndexOfChar; // eax
  struct GFxTextLineBuffer::Line *Line; // eax
  int v9; // ecx
  bool v10; // dl
  int v11; // edi
  char *v12; // esi
  char *v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // edi
  unsigned int v16; // edx
  unsigned int v17; // ecx
  struct GFxFontHandle *v18; // esi
  GFxFontManager *v19; // ecx
  IShaderDevice *v20; // ecx
  IShaderDevice *v21; // ecx
  IShaderDevice *v22; // ecx
  volatile LONG *v23; // ebx
  const VJobInstance *v24; // [esp-4h] [ebp-70h]
  char *v25; // [esp+8h] [ebp-64h]
  char *v26; // [esp+Ch] [ebp-60h]
  CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> v27; // [esp+14h] [ebp-58h] BYREF
  char v28; // [esp+44h] [ebp-28h]
  int v29; // [esp+48h] [ebp-24h]
  int v30; // [esp+4Ch] [ebp-20h]
  int v31; // [esp+50h] [ebp-1Ch]
  struct GFxFontHandle *v32; // [esp+54h] [ebp-18h]
  GRefCountNTSImpl *v33; // [esp+58h] [ebp-14h]
  int v34; // [esp+5Ch] [ebp-10h]
  unsigned int p; // [esp+60h] [ebp-Ch]
  char *v36; // [esp+64h] [ebp-8h]
  char *v37; // [esp+68h] [ebp-4h]
  unsigned int v38; // [esp+74h] [ebp+8h]

  LineIndexOfChar = GFxTextDocView::GetLineIndexOfChar(
                      this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                      + 2),
                      a2: a3,
                      indexOfChar: (unsigned int)a3);
  if ( LineIndexOfChar == -1 )
    return nullptr;
  Line = GFxTextLineBuffer::GetLine(this: (GFxTextLineBuffer *)(*((_DWORD *)this + 2) + 36), a2: LineIndexOfChar);
  if ( Line == nullptr )
    return nullptr;
  v9 = *((_DWORD *)Line + 2);
  v10 = *(int *)Line < 0;
  if ( *(int *)Line < 0 )
  {
    v9 &= 0xFFFFFFu;
    if ( v9 == 0xFFFFFF )
      v9 = -1;
  }
  v38 = v9;
  v36 = (char *)a3 - v9;
  if ( v10 )
    v11 = *((unsigned __int8 *)Line + 28);
  else
    v11 = *((_DWORD *)Line + 1);
  v12 = (char *)Line + 30;
  if ( !v10 )
    v12 = (char *)Line + 42;
  v27.m_iRefs = -1;
  v26 = &v12[8 * v11];
  v27.m_Proxy.m_pfnProxied = 0xFFFFFFFF00000000uLL;
  memset(&v27.m_Proxy.m_pObject, 0, 16);
  v28 = 0;
  v27.CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
  v27.m_nUserID = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = nullptr;
  v33 = nullptr;
  v34 = 0;
  p = 0;
  GFxTextLineBuffer::Line::GetFormatData(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)Line);
  GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: a2);
  v37 = nullptr;
  while ( 1 )
  {
    v13 = v12;
    if ( v12 == nullptr || v12 >= v26 || (*((_WORD *)v12 + 2) & 0xF000) != 0 || (v12[7] & 1) != 0 )
      break;
    GFxTextLineBuffer::GlyphIterator::operator++(result: v24);
  }
  v14 = 0;
  v15 = 0;
  while ( 1 )
  {
    v38 += v14;
    if ( v13 == nullptr || v13 >= v26 )
      break;
    v16 = p;
    v17 = *((unsigned __int16 *)v13 + 2) >> 12;
    v14 = v17;
    v15 += v17;
    v37 = v13;
    if ( p == 0 )
    {
      v16 = v17;
      p = v17;
    }
    v25 = v13 + 8;
    if ( (*((_WORD *)v13 + 6) & 0xF000) != 0
      && v16 != 0
      && !GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)&v27) )
    {
      GFxTextHighlighterPosIterator::operator+=(this: &v27, p);
      p = 0;
    }
    GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: v24);
    if ( v15 > (unsigned int)v36 )
      break;
    v13 = v25;
  }
  if ( a4 != nullptr )
    *a4 = v38;
  if ( v33 != nullptr )
    GRefCountNTSImpl::Release(this: v33);
  v18 = v32;
  if ( v32 != nullptr )
  {
    --*(_DWORD *)v32;
    if ( *(_DWORD *)v18 == 0 )
    {
      v19 = *((GFxFontManager **)v18 + 1);
      if ( v19 != nullptr )
        GFxFontManager::RemoveFontHandle(this: v19, a2: v18);
      v20 = *((IShaderDevice **)v18 + 7);
      if ( v20 != nullptr )
        GFxResource::Release(this: v20);
      *((_DWORD *)v18 + 7) = 0;
      v21 = *((IShaderDevice **)v18 + 8);
      if ( v21 != nullptr )
        GFxResource::Release(this: v21);
      v22 = *((IShaderDevice **)v18 + 7);
      if ( v22 != nullptr )
        GFxResource::Release(this: v22);
      v23 = (volatile LONG *)(*((_DWORD *)v18 + 3) & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: v23 + 1, Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v23);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v18);
    }
  }
  return (const struct GFxTextLineBuffer::GlyphEntry *)v37;
}

//------------------------------------------------------------------------------
// Address: 0x10170780
// Name: public: bool GFxTextEditorKit::ScrollToPosition(unsigned int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxTextEditorKit::ScrollToPosition@<al>(
        GFxTextEditorKit *this@<ecx>,
        const VJobInstance *a2@<ebx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *pos,
        int avoidComposStr,
        int delta)
{
  double v6; // st7
  int v7; // edi
  const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v8; // esi
  int v9; // ebx
  double v10; // st7
  GFxTextEditorKit *v11; // edi
  int v12; // ecx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v13; // ecx
  unsigned int v14; // esi
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> lastChar; // [esp+8h] [ebp-20h] BYREF
  float v17; // [esp+14h] [ebp-14h]
  unsigned int lineIndex; // [esp+18h] [ebp-10h] BYREF
  int prevHScroll; // [esp+1Ch] [ebp-Ch]
  GFxTextEditorKit *v20; // [esp+20h] [ebp-8h]
  bool rv; // [esp+27h] [ebp-1h]

  *(float *)&lastChar.m_pMemory = 0.0;
  *(float *)&lastChar.m_nAllocationCount = 0.0;
  *(float *)&lastChar.m_nGrowSize = 0.0;
  v17 = 0.0;
  LOBYTE(a2) = 0;
  v20 = this;
  rv = false;
  if ( GFxTextEditorKit::CalcCursorRectOnScreen(
         a1: (int)this,
         a2,
         result: pos,
         a4: (float *)&lastChar,
         plineIndex: &lineIndex,
         pglyphIndex: nullptr,
         avoidComposStr,
         plineAlignment: (GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *)&avoidComposStr) == 0 )
    return 0;
  v6 = *(float *)&lastChar.m_pMemory;
  v7 = *((_DWORD *)this + 2);
  if ( (_BYTE)delta == 0 )
    *(float *)&lastChar.m_nGrowSize = v6 + 20.0;
  if ( *(float *)&lastChar.m_nGrowSize <= (double)*(float *)(v7 + 68)
    && v17 <= (double)*(float *)(v7 + 72)
    && *(float *)(v7 + 60) <= v6
    && *(float *)&lastChar.m_nAllocationCount >= (double)*(float *)(v7 + 64)
    || (*(_BYTE *)(v7 + 332) & 0x30) != 0 )
  {
    return (char)a2;
  }
  v8 = *(const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > **)(v7 + 76);
  v9 = 1200;
  prevHScroll = (int)v8;
  delta = 1200;
  if ( avoidComposStr != 0 )
  {
    v9 = 0;
    delta = 0;
  }
  if ( *(float *)(v7 + 68) >= (double)*(float *)&lastChar.m_nGrowSize )
  {
    if ( *(float *)(v7 + 60) > v6 )
    {
      v8 = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)((char *)v8
                                                                              - v9
                                                                              - (int)(*(float *)(v7 + 60) - v6));
      if ( (int)v8 < 0 )
        v8 = nullptr;
    }
  }
  else
  {
    v8 = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)((char *)v8
                                                                            + (int)(v6
                                                                                  - *(float *)(v7 + 68)
                                                                                  + (double)delta));
    *(float *)&lastChar.m_pMemory = 0.0;
    *(float *)&lastChar.m_nAllocationCount = 0.0;
    *(float *)&lastChar.m_nGrowSize = 0.0;
    v17 = 0.0;
    if ( pos != nullptr
      && GFxTextDocView::GetExactCharBoundaries(
           this: (GFxStyledText **)v7,
           a2: (float *)&lastChar,
           advance: (unsigned int)&pos[-1].pTable + 3) )
    {
      v10 = *(float *)&lastChar.m_pMemory - 40.0;
      if ( (int)v10 < (int)v8 )
        v8 = (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)(int)v10;
    }
    if ( (int)v8 < 0 )
      v8 = nullptr;
  }
  v11 = v20;
  v12 = *((_DWORD *)v20 + 2);
  if ( (*(_BYTE *)(v12 + 334) & 8) != 0 && (int)v8 >= prevHScroll )
    LOBYTE(a2) = rv;
  else
    LOBYTE(a2) = GFxTextDocView::SetHScrollOffset(
                   this: (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)v12,
                   hscroll: v8);
  v13 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)v11 + 2);
  v14 = lineIndex;
  if ( lineIndex < v13[4].Data.Policy.Capacity )
    return (unsigned __int8)a2
         | GFxTextDocView::SetVScrollOffset(
             this: v13,
             vscroll: (const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)lineIndex);
  if ( v14 <= GFxTextDocView::GetBottomVScroll(
                this: (GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v13,
                a2: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v11) )
    return (char)a2;
  else
    return (unsigned __int8)a2
         | GFxTextDocView::SetBottomVScroll(
             this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)v11 + 2),
             newBottomMostLine: v14);
}

//------------------------------------------------------------------------------
// Address: 0x10170930
// Name: public: void GFxTextCompositionString::SetCursorPosition(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextCompositionString::SetCursorPosition(
        GArrayDataBase<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *this@<ecx>,
        const VJobInstance *a2@<ebx>,
        unsigned int pos)
{
  int v4; // ecx

  *((_DWORD *)this + 15) = pos;
  --*(_WORD *)(*((_DWORD *)this + 3) + 52);
  v4 = *((_DWORD *)this + 3);
  if ( (*(_BYTE *)(v4 + 104) & 1) != 0 )
    *(_WORD *)(v4 + 104) &= ~8u;
  else
    *(_WORD *)(v4 + 104) |= 8u;
  *(double *)(v4 + 56) = 0.0;
  GFxTextEditorKit::ScrollToPosition(
    this: *((GFxTextEditorKit **)this + 3),
    a2,
    pos: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)(*((_DWORD *)this + 15) + *((_DWORD *)this + 12)),
    avoidComposStr: 0,
    delta: *(_BYTE *)(*((_DWORD *)this + 3) + 105) & 1);
}

//------------------------------------------------------------------------------
// Address: 0x10170990
// Name: public: void GFxTextCompositionString::HighlightText(unsigned int,unsigned int,enum GFxTextIMEStyle::Category)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextCompositionString::HighlightText(int this, const VJobInstance *a2, int a3, int a4)
{
  bool v5; // cf
  unsigned __int8 v6; // dl
  unsigned int v7; // ecx
  GFxTextHighlighter *v8; // eax
  struct GFxTextHighlightDesc *HighlighterPtr; // eax

  v5 = *(_BYTE *)(this + 192) < 0xAu;
  *(_BYTE *)(this + 64) = 1;
  if ( v5 )
  {
    GFxTextDocView::CreateHighlighterManager(this: *(GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> **)(*(_DWORD *)(this + 12) + 8));
    v6 = *(_BYTE *)(this + 192);
    v7 = *(_DWORD *)(this + 4 * v6 + 152);
    *(_BYTE *)(this + 192) = v6 + 1;
    HighlighterPtr = GFxTextHighlighter::GetHighlighterPtr(this: v8, a2: v7);
    *(_DWORD *)HighlighterPtr = *(_DWORD *)(this + 48);
    *((_DWORD *)HighlighterPtr + 2) = a2;
    *((_DWORD *)HighlighterPtr + 1) = a3;
    *((_DWORD *)HighlighterPtr + 6) = *(_DWORD *)(this + 16 * a4 + 68);
    *((_DWORD *)HighlighterPtr + 7) = *(_DWORD *)(this + 16 * a4 + 72);
    *((_DWORD *)HighlighterPtr + 8) = *(_DWORD *)(this + 16 * a4 + 76);
    *((_BYTE *)HighlighterPtr + 36) = *(_BYTE *)(this + 16 * a4 + 80);
    GFxTextDocView::UpdateHighlight(
      this: *(GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> **)(*(_DWORD *)(this + 12) + 8),
      desc: (unsigned int)HighlighterPtr);
    if ( a3 != 0 )
    {
      GFxTextEditorKit::ScrollToPosition(
        this: *(GFxTextEditorKit **)(this + 12),
        a2,
        pos: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)((char *)a2 + *(_DWORD *)(this + 48) + a3),
        avoidComposStr: 0,
        delta: *(_BYTE *)(*(_DWORD *)(this + 12) + 105) & 1);
      GFxTextEditorKit::ScrollToPosition(
        this: *(GFxTextEditorKit **)(this + 12),
        a2,
        pos: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)((char *)a2 + *(_DWORD *)(this + 48)),
        avoidComposStr: 0,
        delta: *(_BYTE *)(*(_DWORD *)(this + 12) + 105) & 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10170A60
// Name: public: void GFxTextEditorKit::SetCursorPos(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextEditorKit::SetCursorPos(
        GFxTextEditorKit *this@<ecx>,
        const VJobInstance *a2@<ebx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *textPos,
        bool selectionAllowed)
{
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v4; // edi
  unsigned int Length; // eax
  int v7; // edx
  const struct GFxTextLineBuffer::GlyphEntry *GlyphEntryAtIndex; // eax
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v9; // eax
  __int16 v10; // ax
  GFxTextDocView *v11; // ecx
  unsigned int v12; // esi
  unsigned int *v13; // ecx
  unsigned int v14; // esi

  v4 = textPos;
  if ( textPos != (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)-1 )
  {
    Length = GFxStyledText::GetLength(this: *(GFxStyledText **)(*((_DWORD *)this + 2) + 8));
    if ( (unsigned int)v4 > Length )
      v4 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)Length;
    if ( (*(_BYTE *)(this + 26) & 1) != 0 )
      *((_WORD *)this + 52) &= ~8u;
    else
      *((_WORD *)this + 52) |= 8u;
    v7 = *((_DWORD *)this + 2);
    *((double *)this + 7) = 0.0;
    if ( *(_DWORD *)(v7 + 24) != 0 )
    {
      GlyphEntryAtIndex = GFxTextEditorKit::GetGlyphEntryAtIndex(this, a2, a3: v4, a4: (unsigned int *)&textPos);
      if ( GlyphEntryAtIndex != nullptr && (*((_WORD *)GlyphEntryAtIndex + 2) & 0xF000) != 0x1000 && textPos != v4 )
      {
        if ( (unsigned int)v4 < *((_DWORD *)this + 6) )
          v4 = textPos;
        else
          v4 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)((char *)textPos + (*((unsigned __int16 *)GlyphEntryAtIndex + 2) >> 12));
      }
    }
  }
  *((_DWORD *)this + 6) = v4;
  --*((_WORD *)this + 26);
  *((float *)this + 18) = -1.0;
  v9 = *((const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
       + 6);
  if ( v9 != (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)-1 )
  {
    GFxTextEditorKit::ScrollToPosition(this, a2, pos: v9, avoidComposStr: 1, delta: *((_BYTE *)this + 105) & 1);
    GFxTextDocView::SetDefaultTextAndParaFormat(
      this: *((GRefCountBase<GFxAmpMemSegment,2> **)this + 2),
      cursorPos: *((_DWORD *)this + 6));
  }
  v10 = *((_WORD *)this + 52);
  if ( (v10 & 2) != 0 )
  {
    if ( selectionAllowed )
    {
      if ( (v10 & 0x40) != 0 || (v10 & 0x20) != 0 )
      {
        v13 = *((unsigned int **)this + 2);
        v14 = *((_DWORD *)this + 6);
        if ( v13[8] != v14 )
          GFxTextDocView::SetSelection(this: (GFxTextDocView *)v13, startPos: v13[7], endPos: v14);
      }
      else
      {
        v11 = *((GFxTextDocView **)this + 2);
        v12 = *((_DWORD *)this + 6);
        if ( *((_DWORD *)v11 + 7) != v12 || *((_DWORD *)v11 + 8) != v12 )
          GFxTextDocView::SetSelection(this: v11, startPos: v12, endPos: v12);
      }
    }
    else
    {
      GFxTextDocView::SetSelection(
        this: *((GFxTextDocView **)this + 2),
        startPos: *((_DWORD *)this + 6),
        endPos: *((_DWORD *)this + 6));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10170B90
// Name: public: void GFxTextEditorKit::Display(class GFxDisplayContext __near &,class GMatrix2D const __near &,class GRenderer::Cxform const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextEditorKit::Display(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this,
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::Iterator *result,
        int context_4,
        float *context_8)
{
  struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *pTable; // esi
  __int16 v6; // ax
  int v7; // edx
  __int16 v8; // ax
  GFxResourceId *v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  int v12; // eax
  GFxTextHighlighter *v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // eax
  float *v16; // ecx
  float *v17; // ebx
  unsigned int v18; // edx
  __int16 v19; // di
  IColorCorrectionSystem *v20; // [esp+10h] [ebp-F4h]
  const CMaterialDict::MaterialLookup_t *v21; // [esp+10h] [ebp-F4h]
  int v22; // [esp+10h] [ebp-F4h]
  int v23; // [esp+10h] [ebp-F4h]
  int v24; // [esp+10h] [ebp-F4h]
  __int128 v25; // [esp+14h] [ebp-F0h] BYREF
  _BYTE v26[16]; // [esp+40h] [ebp-C4h] BYREF
  float *v27; // [esp+50h] [ebp-B4h]
  unsigned int v28; // [esp+54h] [ebp-B0h] BYREF
  float v29; // [esp+58h] [ebp-ACh]
  unsigned int v30; // [esp+5Ch] [ebp-A8h]
  unsigned int v31; // [esp+60h] [ebp-A4h]
  unsigned int lineIndex; // [esp+64h] [ebp-A0h] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> actualCursorRect; // [esp+68h] [ebp-9Ch] BYREF
  float v34; // [esp+74h] [ebp-90h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v35; // [esp+78h] [ebp-8Ch] BYREF
  float v36; // [esp+84h] [ebp-80h]
  float v37; // [esp+88h] [ebp-7Ch]
  unsigned int cursorPos; // [esp+8Ch] [ebp-78h] BYREF
  CMaterialDict::MaterialLookup_t m; // [esp+90h] [ebp-74h] BYREF
  float v40; // [esp+98h] [ebp-6Ch]
  float v41; // [esp+9Ch] [ebp-68h]
  float v42; // [esp+A0h] [ebp-64h]
  float v43; // [esp+A4h] [ebp-60h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v44; // [esp+A8h] [ebp-5Ch] BYREF
  float v45; // [esp+BCh] [ebp-48h]
  GMatrix2D v46; // [esp+C0h] [ebp-44h] BYREF
  GMatrix2D v47; // [esp+D8h] [ebp-2Ch] BYREF
  _WORD v48[5]; // [esp+F0h] [ebp-14h] BYREF
  __int16 v49; // [esp+FAh] [ebp-Ah]
  __int16 v50; // [esp+FCh] [ebp-8h]
  __int16 v51; // [esp+FEh] [ebp-6h]

  pTable = result[9].pHash[3].pTable;
  v37 = *(float *)&result;
  v6 = *((_WORD *)this + 52);
  v27 = context_8;
  if ( (v6 & 8) != 0 && (*(_BYTE *)(this + 26) & 1) == 0 && (v6 & 0x100) == 0 )
  {
    v7 = *((_DWORD *)this + 2);
    v8 = *((_WORD *)this + 26);
    lineIndex = -1;
    if ( v8 != *(_WORD *)(v7 + 328) )
    {
      v9 = *((GFxResourceId **)this + 5);
      *(float *)&v28 = 0.0;
      v10 = *((_DWORD *)this + 6);
      v29 = 0.0;
      *(float *)&v30 = 0.0;
      cursorPos = v10;
      *(float *)&v31 = 0.0;
      if ( v9 != nullptr && GFxTextParagraph::GetLength(this: v9 + 5) != 0 )
        cursorPos += *(_DWORD *)(*((_DWORD *)this + 5) + 60);
      if ( GFxTextEditorKit::CalcCursorRectInLineBuffer(
             a1: (int)this,
             a2: (const VJobInstance *)context_4,
             a3: this,
             result: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)cursorPos,
             a5: (float *)&v28,
             plineIndex: &lineIndex,
             pglyphIndex: &cursorPos,
             avoidComposStr: 0,
             xoffset: nullptr) != 0 )
      {
        v11 = *(_DWORD *)(*((_DWORD *)this + 2) + 8);
        v30 = v28;
        v12 = *(_DWORD *)(v11 + 28);
        if ( v12 != 0 && (*(_BYTE *)(v12 + 42) & 1) != 0 )
          *(this + 7) = *(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)(v12 + 32);
        v13 = *(GFxTextHighlighter **)(*((_DWORD *)this + 2) + 20);
        if ( v13 != nullptr )
        {
          GFxTextHighlighter::GetPosIterator(
            this: v13,
            retstr: (GFxTextHighlighterPosIterator *)((char *)&v25 + 8),
            a3: *((_DWORD *)this + 6),
            a4: 0xFFFFFFFF);
          if ( (v26[12] & 0x10) != 0 )
            *(this + 7) = **(GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)&GFxTextHighlightInfo::GetTextColor(this: (GFxTextHighlightInfo *)v26, a2: &cursorPos);
        }
      }
      else
      {
        *(float *)&v28 = 0.0;
        v29 = 0.0;
        *(float *)&cursorPos = 0.0 + 0.0;
        v30 = cursorPos;
        v31 = cursorPos;
      }
      CachedValue<GRect<float>>::SetValue(
        this: (float *)this + 9,
        v: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v28,
        counter: *(_WORD *)(*((_DWORD *)this + 2) + 328));
    }
    v14 = *((_DWORD *)this + 2);
    actualCursorRect.m_pMemory = *((CMatRenderContextBase::MatrixStackItem_t **)this + 9);
    cursorPos = v14;
    actualCursorRect.m_nAllocationCount = *((int *)this + 10);
    actualCursorRect.m_nGrowSize = *((int *)this + 11);
    v34 = *((float *)this + 12);
    *(float *)&v35.nReferenceCount = (float)*(unsigned int *)(v14 + 76);
    GFxTextLineBuffer::GetVScrollOffsetInTwips(this: (CMatCallQueue *)(v14 + 36), a2: v20, a3: v25);
    v36 = (float)v15;
    v16 = (float *)cursorPos;
    *(float *)&v35.pString = -*(float *)&v35.nReferenceCount;
    *(float *)&v35.nNextElement = -v36;
    *(float *)&actualCursorRect.m_pMemory = *(float *)&v35.pString + *(float *)&actualCursorRect.m_pMemory;
    *(float *)&actualCursorRect.m_nGrowSize = *(float *)&v35.pString + *(float *)&actualCursorRect.m_nGrowSize;
    *(float *)&actualCursorRect.m_nAllocationCount = *(float *)&v35.nNextElement
                                                   + *(float *)&actualCursorRect.m_nAllocationCount;
    v34 = *(float *)&v35.nNextElement + v34;
    *(float *)&v35.nReferenceCount = *(float *)(cursorPos + 60);
    v36 = *(float *)(cursorPos + 64);
    *(float *)&actualCursorRect.m_pMemory = *(float *)&v35.nReferenceCount + *(float *)&actualCursorRect.m_pMemory;
    *(float *)&actualCursorRect.m_nGrowSize = *(float *)&v35.nReferenceCount + *(float *)&actualCursorRect.m_nGrowSize;
    *(float *)&actualCursorRect.m_nAllocationCount = v36 + *(float *)&actualCursorRect.m_nAllocationCount;
    v34 = v36 + v34;
    if ( *(float *)(cursorPos + 72) < (double)v34 )
    {
      if ( lineIndex == -1 )
        lineIndex = GFxTextDocView::GetLineIndexOfChar(
                      this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                      + 2),
                      a2: this,
                      indexOfChar: *((_DWORD *)this + 6));
      if ( GFxTextLineBuffer::IsLineVisible(
             this: (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)(*((_DWORD *)this + 2) + 36),
             lineIndex) )
      {
        v16 = (float *)cursorPos;
        v34 = *(float *)(cursorPos + 72);
      }
      else
      {
        v16 = (float *)cursorPos;
      }
    }
    if ( *(float *)&actualCursorRect.m_nGrowSize <= (double)v16[17]
      && v34 <= (double)v16[18]
      && *(float *)&actualCursorRect.m_pMemory >= (double)v16[15]
      && *(float *)&actualCursorRect.m_nAllocationCount >= (double)v16[16] )
    {
      *(float *)&actualCursorRect.m_nGrowSize = *(float *)&actualCursorRect.m_pMemory + 20.0;
      v46.M_[0][0] = *(float *)context_4;
      v46.M_[0][1] = *(float *)(context_4 + 4);
      v46.M_[0][2] = *(float *)(context_4 + 8);
      v46.M_[1][0] = *(float *)(context_4 + 12);
      v46.M_[1][1] = *(float *)(context_4 + 16);
      v46.M_[1][2] = *(float *)(context_4 + 20);
      *(float *)&v28 = 0.0;
      v29 = 0.0;
      *(float *)&v30 = 0.0;
      *(float *)&v31 = 0.0;
      GFx_RecalculateRectToFit16Bit(a1: &v46, a2: (int)&actualCursorRect, a3: (int)&v28);
      (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, GMatrix2D *))(*(_DWORD *)pTable + 56))(
        a1: pTable,
        a2: &v46);
      v17 = v27;
      (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, float *))(*(_DWORD *)pTable + 64))(
        a1: pTable,
        a2: v27);
      v47.M_[0][0] = v46.M_[0][0];
      v47.M_[0][1] = v46.M_[0][1];
      v47.M_[0][2] = v46.M_[0][2];
      v47.M_[1][0] = v46.M_[1][0];
      v47.M_[1][1] = v46.M_[1][1];
      v47.M_[1][2] = v46.M_[1][2];
      GMatrix2D::Append(this: &v47, a2: (const struct GMatrix2D *)(LODWORD(v37) + 120));
      *(float *)&v44.m_Memory.m_pMemory = v47.M_[0][0];
      *(float *)&v44.m_Memory.m_nAllocationCount = v47.M_[0][1];
      *(float *)&v44.m_Memory.m_nGrowSize = v47.M_[0][2];
      *(float *)&v44.m_Size = v47.M_[1][0];
      *(float *)&v44.m_pElements = v47.M_[1][1];
      v45 = v47.M_[1][2];
      v43 = v47.M_[1][2];
      *(float *)&m.m_pMaterial = v47.M_[0][0];
      *(float *)&m.m_Name.m_Id = v47.M_[0][1];
      v40 = v47.M_[0][2];
      v41 = v47.M_[1][0];
      v42 = v47.M_[1][1];
      GMatrix2D::SetInverse(a1: (float *)&v44, &m, a3: v21);
      *(float *)&v35.nReferenceCount = *(float *)&v28;
      v36 = v29;
      GMatrix2D::Transform(
        this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v47,
        result: &v35,
        p: (float *)&v35.nReferenceCount,
        p_4: v22);
      v37 = *(float *)&v35.pString + 0.5;
      v37 = floor(X: v37);
      *(float *)&v35.pString = v37;
      GMatrix2D::Transform(
        this: &v44,
        result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&v35.nReferenceCount,
        p: (float *)&v35,
        p_4: v23);
      v28 = *(unsigned int *)&v35.nReferenceCount;
      *(float *)&v35.pString = *(float *)&v35.pString + 1.0;
      GMatrix2D::Transform(
        this: &v44,
        result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&v35.nReferenceCount,
        p: (float *)&v35,
        p_4: v24);
      v18 = *((_DWORD *)this + 7);
      v35.pString = *(char **)&v35.nReferenceCount;
      *(float *)&v35.nNextElement = v36;
      v30 = *(unsigned int *)&v35.nReferenceCount;
      GRenderer::Cxform::Transform(this: v17, result: (CBaseAutoPtr<CFunctor> *)&cursorPos, a3: v18);
      v37 = *(float *)&v28 + 0.5;
      v19 = (int)floor(X: v37);
      v48[0] = v19;
      LOWORD(v17) = (int)v29;
      v48[1] = (_WORD)v17;
      v37 = *(float *)&v30 + 0.5;
      HIWORD(lineIndex) = (int)floor(X: v37);
      v48[2] = HIWORD(lineIndex);
      v48[3] = (_WORD)v17;
      v48[4] = v19;
      v49 = (int)*(float *)&v31;
      v50 = HIWORD(lineIndex);
      v51 = v49;
      (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, unsigned int))(*(_DWORD *)pTable + 136))(
        a1: pTable,
        a2: cursorPos);
      (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, _WORD *, int, int, _DWORD))(*(_DWORD *)pTable + 104))(
        a1: pTable,
        a2: v48,
        a3: 4,
        a4: 1,
        a5: 0);
      (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, void *, int, int, _DWORD))(*(_DWORD *)pTable + 108))(
        a1: pTable,
        a2: &`GFxEditTextCharacter::Display'::`21'::indices,
        a3: 6,
        a4: 1,
        a5: 0);
      (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)pTable + 116))(
        a1: pTable,
        a2: 0,
        a3: 0,
        a4: 4,
        a5: 0,
        a6: 2);
      (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)pTable + 104))(
        a1: pTable,
        a2: 0,
        a3: 0,
        a4: 0,
        a5: 0);
      (*(void (__thiscall **)(struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)pTable + 108))(
        a1: pTable,
        a2: 0,
        a3: 0,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101711B0
// Name: public: bool GFxTextEditorKit::OnChar(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextEditorKit::OnChar(GFxTextEditorKit *this, unsigned int rv)
{
  bool v3; // zf
  int v4; // eax
  unsigned int v5; // ecx
  const char *v6; // ebx
  unsigned int v7; // edi
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v8; // ecx
  int v9; // eax
  unsigned int v10; // ecx
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v11; // ecx
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v12; // edi
  int v13; // ecx
  unsigned int v15; // [esp+4h] [ebp-14h] BYREF
  unsigned int v16; // [esp+8h] [ebp-10h] BYREF
  __int16 v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  unsigned int beginSel; // [esp+14h] [ebp-4h]
  char rv_3; // [esp+23h] [ebp+Bh]

  if ( rv == 0 || (*(_WORD *)(this + 26) & 0x20) != 0 )
    return 0;
  v3 = (*(_BYTE *)(this + 26) & 1) == 0;
  v4 = *((_DWORD *)this + 2);
  v5 = *(_DWORD *)(v4 + 28);
  v6 = *(const char **)(v4 + 32);
  v7 = *((_DWORD *)this + 6);
  v18 = v4;
  rv_3 = 0;
  beginSel = v5;
  if ( v3 && (unsigned __int16)rv >= 0x20u )
  {
    if ( (const char *)v5 != v6 )
      goto LABEL_10;
    if ( (unsigned __int8)(*((_WORD *)this + 52) >> 7) != 0 )
      ++v6;
    if ( (const char *)v5 == v6 )
    {
      v8 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
      v16 = v7;
      v17 = rv;
      GFxTextDocView::EditCommand(this: v8, a2: v6, cmdId: 0, command: (ButtonCode_t)&v16);
      v10 = beginSel;
    }
    else
    {
LABEL_10:
      v17 = rv;
      v15 = v5;
      v11 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
      v16 = (unsigned int)v6;
      GFxTextDocView::EditCommand(this: v11, a2: v6, cmdId: 5u, command: (ButtonCode_t)&v15);
      v10 = beginSel;
      v7 = beginSel;
      if ( beginSel >= (unsigned int)v6 )
        v7 = (unsigned int)v6;
    }
    v12 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)(v9 + v7);
    if ( *((const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
         + 6) != v12
      || (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v10 != v12
      || v6 != (const char *)v12 )
    {
      GFxTextEditorKit::SetCursorPos(this, a2: (const VJobInstance *)v6, textPos: v12, selectionAllowed: false);
      rv_3 = 1;
    }
    v13 = *(_DWORD *)(v18 + 16);
    if ( v13 != 0 )
      (*(void (__thiscall **)(int, GFxTextEditorKit *))(*(_DWORD *)v13 + 32))(a1: v13, a2: this);
  }
  return rv_3;
}

//------------------------------------------------------------------------------
// Address: 0x101712A0
// Name: public: void GFxTextEditorKit::SetCursorPos(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextEditorKit::SetCursorPos(
        GFxTextEditorKit *this@<ecx>,
        const VJobInstance *a2@<ebx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *textPos)
{
  GFxTextEditorKit::SetCursorPos(this, a2, textPos, selectionAllowed: (*(_BYTE *)(this + 26) & 2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x101712C0
// Name: public: void GFxTextEditorKit::Advance(double)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextEditorKit::Advance(
        GFxTextEditorKit *this@<ecx>,
        const VJobInstance *a2@<ebx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a3@<edi>,
        long double timer)
{
  char v5; // al
  long double v6; // st7
  long double v7; // st7
  __int16 v8; // ax
  __int16 v9; // ax
  const unsigned int *ViewRect; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v11; // ecx
  unsigned int Capacity; // eax
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v13; // eax
  const GRefCountBase<GFxAmpMemSegment,2> *v14; // edi
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v15; // eax
  double timera; // [esp+14h] [ebp+8h]
  double timerb; // [esp+14h] [ebp+8h]

  v5 = ~*((_BYTE *)this + 104);
  v6 = timer - *((double *)this + 8);
  *((long double *)this + 8) = timer;
  if ( (v5 & 1) != 0 )
  {
    v7 = v6 + *((double *)this + 7);
    if ( v7 <= 0.5 )
    {
      *((long double *)this + 7) = v7;
    }
    else
    {
      v8 = *((_WORD *)this + 52);
      if ( (v8 & 0x10) == 0 )
      {
        if ( (v8 & 8) != 0 )
          v9 = v8 & 0xFFF7;
        else
          v9 = v8 | 8;
        *((_WORD *)this + 52) = v9;
      }
      *((_WORD *)this + 52) &= ~0x10u;
      *((double *)this + 7) = 0.0;
    }
  }
  if ( (*(_BYTE *)(this + 26) & 0x20) != 0 )
  {
    timera = *((float *)this + 20);
    ViewRect = GFxTextDocView::GetViewRect(
                 this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2),
                 a2: a3);
    v11 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
    if ( *((float *)ViewRect + 1) < timera )
    {
      timerb = *((float *)this + 20);
      if ( *((float *)GFxTextDocView::GetViewRect(this: v11, a2: a3) + 3) <= timerb )
      {
        v14 = (const GRefCountBase<GFxAmpMemSegment,2> *)(GFxTextDocView::GetBottomVScroll(
                                                            this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                                                            + 2),
                                                            a2: a3)
                                                        + 1);
        if ( (unsigned int)v14 < GFxTextDocView::GetLinesCount(
                                   this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                                   + 2),
                                   a2: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v14) )
        {
          GFxTextDocView::GetCursorPosInLine(
            this: *((GRefCountBase<GFxAmpMemSegment,2> **)this + 2),
            lineIndex: v14,
            x: *((float *)this + 20));
          if ( v15 != *((const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                      + 6) )
            GFxTextEditorKit::SetCursorPos(this, a2, textPos: v15);
        }
      }
    }
    else
    {
      Capacity = v11[4].Data.Policy.Capacity;
      if ( Capacity != 0 )
      {
        GFxTextDocView::GetCursorPosInLine(
          this: (GRefCountBase<GFxAmpMemSegment,2> *)v11,
          lineIndex: (const GRefCountBase<GFxAmpMemSegment,2> *)(Capacity - 1),
          x: *((float *)this + 20));
        if ( v13 != *((const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                    + 6) )
          GFxTextEditorKit::SetCursorPos(this, a2, textPos: v13, selectionAllowed: (*(_BYTE *)(this + 26) & 2) != 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101713E0
// Name: public: void GFxTextEditorKit::OnMouseDown(float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextEditorKit::OnMouseDown(
        GFxTextEditorKit *this@<ecx>,
        const VJobInstance *a2@<ebx>,
        float st,
        float en,
        float doubleClicked)
{
  unsigned int *ViewRect; // esi
  void *v7; // ecx
  unsigned __int64 v8; // rax
  unsigned int v9; // ecx
  GRefCountBase<GFxAmpMemSegment,2> *v10; // ecx
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v11; // eax
  unsigned int v12; // esi
  __int16 v13; // ax
  __int16 v14; // ax
  const char *pString; // esi
  unsigned int Length; // eax
  unsigned int v17; // ebx
  int v18; // esi
  const CFileSystemPassThru *v19; // ecx
  const CFileSystemPassThru *v20; // ecx
  int v21; // eax
  int v22; // eax
  unsigned int v23; // esi
  __int16 v24; // ax
  int v25; // edx
  int v26; // edx
  int v27; // esi
  const VJobInstance *v28; // ebx
  GFxValue index; // [esp+14h] [ebp-18h] BYREF
  unsigned int indexInPara; // [esp+24h] [ebp-8h] BYREF
  unsigned int textLen; // [esp+28h] [ebp-4h]
  float sta; // [esp+34h] [ebp+8h]
  unsigned int stb; // [esp+34h] [ebp+8h]
  float ena; // [esp+38h] [ebp+Ch]
  unsigned int enb; // [esp+38h] [ebp+Ch]
  float doubleClickedb; // [esp+3Ch] [ebp+10h]
  float doubleClickedc; // [esp+3Ch] [ebp+10h]
  float doubleClickedd; // [esp+3Ch] [ebp+10h]
  float doubleClickede; // [esp+3Ch] [ebp+10h]
  const CFileSystemPassThru *doubleClickeda; // [esp+3Ch] [ebp+10h]
  char doubleClicked_3; // [esp+3Fh] [ebp+13h]

  if ( (LOBYTE(doubleClicked) & 1) != 0 )
  {
    ViewRect = (unsigned int *)GFxTextDocView::GetViewRect(
                                 this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this
                                 + 2),
                                 a2: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this);
    doubleClickedb = st - *(float *)ViewRect;
    doubleClickedc = floor(X: doubleClickedb);
    sta = doubleClickedc;
    doubleClickedd = en - *((float *)ViewRect + 1);
    doubleClickede = floor(X: doubleClickedd);
    ena = doubleClickede;
    GTimer::GetTicks(this: v7);
    v9 = v8 / 0x3E8;
    LOBYTE(a2) = 0;
    doubleClicked_3 = 0;
    if ( sta != *((float *)this + 19) )
      goto LABEL_9;
    if ( ena == *((float *)this + 20) && v9 <= *((_DWORD *)this + 21) + 300 )
    {
      if ( (*(_WORD *)(this + 26) & 0x200) != 0 )
        LOBYTE(a2) = 1;
      else
        doubleClicked_3 = 1;
      *((_WORD *)this + 52) |= 0x200u;
    }
    else
    {
LABEL_9:
      *((_WORD *)this + 52) &= ~0x200u;
    }
    *((float *)this + 19) = sta;
    *((_DWORD *)this + 21) = v9;
    v10 = *((GRefCountBase<GFxAmpMemSegment,2> **)this + 2);
    *((float *)this + 20) = ena;
    GFxTextDocView::GetCursorPosAtPoint(this: v10, a2: (IColorCorrectionSystem *)ViewRect, a3: sta, a4: ena);
    v12 = (unsigned int)v11;
    if ( v11 != (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)-1 )
    {
      GFxTextEditorKit::SetCursorPos(this, a2, textPos: v11, selectionAllowed: (*(_BYTE *)(this + 26) & 2) != 0);
      v13 = *((_WORD *)this + 52);
      if ( (v13 & 2) != 0 && (v13 & 0x20) == 0 )
      {
        v14 = v13 | 0x20;
        *((_WORD *)this + 52) = v14;
        if ( doubleClicked_3 != 0 || (_BYTE)a2 != 0 )
        {
          GFxStyledText::GetParagraphByIndex(
            this: *(SFTextObjectImpl **)(*((_DWORD *)this + 2) + 8),
            &index,
            indexa: v12,
            pindexInParagraph: &indexInPara);
          if ( index.pObjectInterface != nullptr
            && index.Type >= VT_Undefined
            && index.Type < (int)index.pObjectInterface[1].pMovieRoot )
          {
            index.Value.pString = *((const char **)index.pObjectInterface->pMovieRoot + index.Type);
            pString = index.Value.pString;
            Length = GFxTextParagraph::GetLength(this: (GFxResourceId *)index.Value.pString);
            v17 = indexInPara;
            textLen = Length;
            stb = indexInPara;
            enb = indexInPara;
            if ( doubleClicked_3 != 0 )
            {
              v18 = *(_DWORD *)pString;
              *((_DWORD *)&index.Value.pStringManaged + 1) = v18;
              if ( indexInPara != 0 )
              {
                v19 = (const CFileSystemPassThru *)(v18 + 2 * indexInPara - 2);
                doubleClickeda = v19;
                do
                {
                  G_iswspace(charCode: v19);
                  if ( v21 != 0 )
                    break;
                  G_iswalnum(charCode: v20);
                  if ( v22 == 0 )
                    break;
                  doubleClickeda = (const CFileSystemPassThru *)((char *)doubleClickeda - 2);
                  --stb;
                }
                while ( stb != 0 );
              }
              for ( ; v17 < textLen; enb = ++v17 )
              {
                v23 = *(unsigned __int16 *)(*((_DWORD *)&index.Value.pStringManaged + 1) + 2 * v17);
                v24 = *(_WORD *)(*((_DWORD *)&index.Value.pStringManaged + 1) + 2 * v17);
                v25 = *((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + (v23 >> 8));
                if ( *((_WORD *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + (v23 >> 8)) != 0 )
                {
                  if ( v25 == 1 )
                    break;
                  v17 = enb;
                  if ( (*((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable
                        + v25
                        + ((unsigned __int8)v24 >> 4))
                      & (1 << (v24 & 0xF))) != 0 )
                    break;
                }
                v26 = (unsigned __int16)word_10299FE0[v23 >> 8];
                if ( word_10299FE0[v23 >> 8] == 0
                  || v26 != 1
                  && ((unsigned __int16)word_10299FE0[v26 + ((unsigned __int8)v23 >> 4)] & (1 << (v23 & 0xF))) == 0 )
                {
                  break;
                }
              }
            }
            else
            {
              stb = 0;
              v17 = Length;
            }
            v27 = *((_DWORD *)index.Value.pString + 7);
            v28 = (const VJobInstance *)(v27 + v17);
            GFxTextEditorKit::SetCursorPos(
              this,
              a2: v28,
              textPos: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v28,
              selectionAllowed: (*(_BYTE *)(this + 26) & 2) != 0);
            GFxTextDocView::SetSelection(
              this: *((GFxTextDocView **)this + 2),
              startPos: stb + v27,
              endPos: (unsigned int)v28);
          }
        }
        else if ( (v14 & 0x40) == 0 )
        {
          GFxTextDocView::SetSelection(this: *((GFxTextDocView **)this + 2), startPos: v12, endPos: v12);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101716D0
// Name: public: void GFxTextEditorKit::OnMouseMove(float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextEditorKit::OnMouseMove(
        GFxTextEditorKit *this@<ecx>,
        const VJobInstance *a2@<ebx>,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a3@<edi>,
        float ay,
        float y)
{
  float *ViewRect; // edi
  double v7; // st7
  GRefCountBase<GFxAmpMemSegment,2> *v8; // ecx
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v9; // eax
  unsigned int v10; // edi
  float v11; // [esp+10h] [ebp-4h]
  float aya; // [esp+1Ch] [ebp+8h]
  float ayb; // [esp+1Ch] [ebp+8h]
  float ayc; // [esp+1Ch] [ebp+8h]
  float ayd; // [esp+1Ch] [ebp+8h]

  if ( (*(_BYTE *)(this + 26) & 0x20) != 0 )
  {
    ViewRect = (float *)GFxTextDocView::GetViewRect(
                          this: *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this
                          + 2),
                          a2: a3);
    aya = ay - *ViewRect;
    ayb = floor(X: aya);
    v11 = ayb;
    ayc = y - ViewRect[1];
    v7 = floor(X: ayc);
    v8 = *((GRefCountBase<GFxAmpMemSegment,2> **)this + 2);
    ayd = v7;
    *((float *)this + 19) = v11;
    *((float *)this + 20) = ayd;
    GFxTextDocView::GetCursorPosAtPoint(this: v8, a2: (IColorCorrectionSystem *)this, a3: v11, a4: ayd);
    v10 = (unsigned int)v9;
    if ( v9 != (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)-1 )
    {
      GFxTextEditorKit::SetCursorPos(this, a2, textPos: v9, selectionAllowed: (*(_BYTE *)(this + 26) & 2) != 0);
      if ( (*(_BYTE *)(this + 26) & 2) != 0 )
        GFxTextDocView::SetSelection(
          this: *((GFxTextDocView **)this + 2),
          startPos: *(_DWORD *)(*((_DWORD *)this + 2) + 28),
          endPos: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171780
// Name: public: bool GFxTextEditorKit::OnKeyDown(int,class GFxSpecialKeysState const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextEditorKit::OnKeyDown(
        GFxTextEditorKit *this,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *a2,
        const struct GFxSpecialKeysState *a3)
{
  int v4; // ebx
  GFxStyledText *v5; // ecx
  unsigned int v6; // eax
  int v7; // ecx
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v8; // edi
  unsigned int v9; // eax
  char v10; // cl
  int v11; // ecx
  VJobInstance *v12; // ebx
  unsigned int v13; // edx
  GenericThreadLocals::CThreadLocalPtr<IMatRenderContextInternal> *v14; // ecx
  int *v15; // eax
  int v16; // eax
  unsigned int LineOffset; // eax
  signed int LineIndexOfChar; // eax
  const GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v19; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v20; // ecx
  unsigned int v21; // eax
  const GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v22; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v23; // ecx
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v24; // edi
  VJobInstance *v25; // eax
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v26; // eax
  double v27; // st7
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v28; // ecx
  int BottomVScroll; // eax
  GRefCountBase<GFxAmpMemSegment,2> *v30; // ecx
  unsigned int v31; // eax
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v32; // eax
  double v33; // st7
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v34; // ecx
  int v35; // eax
  GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v36; // ecx
  const struct GFxSpecialKeysState *v37; // edi
  char v38; // al
  double v39; // st7
  GRefCountBase<GFxAmpMemSegment,2> *v40; // ecx
  char v41; // cl
  double v42; // st7
  unsigned int v43; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v44; // ecx
  int v45; // eax
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v46; // ecx
  int v47; // ecx
  int v48; // eax
  float v49; // edx
  char v50; // al
  unsigned int v51; // edi
  __int16 v52; // ax
  int v53; // ecx
  float v55; // [esp+10h] [ebp-34h] BYREF
  float v56; // [esp+14h] [ebp-30h]
  float v57; // [esp+18h] [ebp-2Ch]
  float v58; // [esp+1Ch] [ebp-28h]
  int v59; // [esp+20h] [ebp-24h]
  float v60; // [esp+24h] [ebp-20h] BYREF
  float v61; // [esp+28h] [ebp-1Ch] BYREF
  unsigned int v62; // [esp+2Ch] [ebp-18h] BYREF
  unsigned int v63; // [esp+30h] [ebp-14h]
  unsigned int startPos; // [esp+34h] [ebp-10h]
  float v65; // [esp+38h] [ebp-Ch]
  unsigned int endPos; // [esp+3Ch] [ebp-8h]
  char v67; // [esp+42h] [ebp-2h]
  char v68; // [esp+43h] [ebp-1h]

  v4 = *((_DWORD *)this + 2);
  v5 = *(GFxStyledText **)(v4 + 8);
  v59 = v4;
  *(float *)&v6 = COERCE_FLOAT(GFxStyledText::GetLength(this: v5));
  v7 = *(_DWORD *)(v4 + 16);
  v8 = *((const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
       + 6);
  v63 = v6;
  v68 = 0;
  if ( v7 != 0 )
    v9 = (*(int (__thiscall **)(int, GFxTextEditorKit *, const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *))(*(_DWORD *)v7 + 24))(
           a1: v7,
           a2: this,
           a3: a2);
  else
    v9 = (unsigned int)a2;
  v10 = *((_BYTE *)this + 104) >> 6;
  v65 = -1.0;
  v67 = v10 & 1;
  v11 = *((_DWORD *)this + 2);
  v12 = *(VJobInstance **)(v11 + 28);
  v13 = *(unsigned int *)(v11 + 32);
  v14 = *((GenericThreadLocals::CThreadLocalPtr<IMatRenderContextInternal> **)this + 4);
  HIBYTE(a2) = 0;
  startPos = (unsigned int)v12;
  endPos = v13;
  if ( v14 != nullptr )
  {
    v15 = GFxTextKeyMap::Find(this: v14, keyCode: v9, a3: &a3->States, a4: 0);
    if ( v15 != nullptr )
    {
      v16 = *v15;
      switch ( v16 )
      {
        case 2:
          if ( (*(_BYTE *)(this + 26) & 2) == 0 )
            break;
          goto LABEL_109;
        case 4:
          if ( v8 == (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)-1 )
            v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v63;
          if ( v8 != nullptr )
            v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)((char *)v8 - 1);
          if ( (*(_BYTE *)(this + 26) & 0x40) != 0 )
            goto LABEL_97;
          if ( v12 == (VJobInstance *)endPos )
            goto LABEL_97;
          LineOffset = (unsigned int)v12;
          v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)endPos;
          if ( (unsigned int)v12 >= endPos )
            goto LABEL_97;
          goto LABEL_96;
        case 5:
          if ( v8 == (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)-1 )
          {
            v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v63;
          }
          else if ( (unsigned int)v8 < v63 )
          {
            v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)((char *)v8 + 1);
          }
          if ( (*(_BYTE *)(this + 26) & 0x40) != 0 )
            goto LABEL_97;
          if ( v12 == (VJobInstance *)endPos )
            goto LABEL_97;
          v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)endPos;
          LineOffset = (unsigned int)v12;
          if ( endPos >= (unsigned int)v12 )
            goto LABEL_97;
          goto LABEL_96;
        case 6:
          v38 = *((_BYTE *)this + 104);
          v55 = 0.0;
          v56 = 0.0;
          v57 = 0.0;
          v58 = 0.0;
          if ( (v38 & 0x40) == 0 )
          {
            LineOffset = endPos;
            if ( v12 != (VJobInstance *)endPos )
            {
              if ( (unsigned int)v12 >= endPos )
                goto LABEL_96;
              v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v12;
              goto LABEL_97;
            }
          }
          if ( GFxTextEditorKit::CalcCursorRectOnScreen(
                 a1: (int)this,
                 a2: v12,
                 result: *((const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                 + 6),
                 a4: &v55,
                 plineIndex: (unsigned int *)&a3,
                 pglyphIndex: nullptr,
                 avoidComposStr: 1,
                 plineAlignment: nullptr) == 0 )
            goto LABEL_97;
          if ( a3 == nullptr )
          {
LABEL_40:
            v8 = nullptr;
            goto LABEL_97;
          }
          if ( *((float *)this + 18) >= 0.0 )
            v39 = *((float *)this + 18);
          else
            v39 = v55;
          v40 = *((GRefCountBase<GFxAmpMemSegment,2> **)this + 2);
          v65 = v39;
          GFxTextDocView::GetCursorPosInLine(
            this: v40,
            lineIndex: (const GRefCountBase<GFxAmpMemSegment,2> *)&a3[-1],
            x: v65);
          goto LABEL_96;
        case 7:
          v41 = *((_BYTE *)this + 104);
          v55 = 0.0;
          v56 = 0.0;
          v57 = 0.0;
          v58 = 0.0;
          if ( (v41 & 0x40) != 0 || (LineOffset = endPos, (VJobInstance *)endPos == v12) )
          {
            if ( GFxTextEditorKit::CalcCursorRectOnScreen(
                   a1: (int)this,
                   a2: v12,
                   result: *((const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                   + 6),
                   a4: &v55,
                   plineIndex: (unsigned int *)&a3,
                   pglyphIndex: nullptr,
                   avoidComposStr: 1,
                   plineAlignment: nullptr) == 0 )
              goto LABEL_97;
            v37 = a3 + 1;
            if ( (unsigned int)v37 >= GFxTextDocView::GetLinesCount(
                                        this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                                        + 2),
                                        a2: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)&a3[1]) )
            {
LABEL_47:
              v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v63;
              goto LABEL_97;
            }
            if ( *((float *)this + 18) >= 0.0 )
              v42 = *((float *)this + 18);
            else
              v42 = v55;
            v65 = v42;
LABEL_68:
            GFxTextDocView::GetCursorPosInLine(
              this: *((GRefCountBase<GFxAmpMemSegment,2> **)this + 2),
              lineIndex: (const GRefCountBase<GFxAmpMemSegment,2> *)v37,
              x: v65);
          }
          else if ( endPos < (unsigned int)v12 )
          {
            v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v12;
            goto LABEL_97;
          }
LABEL_96:
          v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)LineOffset;
          goto LABEL_97;
        case 8:
          v26 = *((const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                + 6);
          v60 = 0.0;
          v61 = 0.0;
          *(float *)&v62 = 0.0;
          *(float *)&v63 = 0.0;
          if ( GFxTextEditorKit::CalcCursorRectOnScreen(
                 a1: (int)this,
                 a2: v12,
                 result: v26,
                 a4: &v60,
                 plineIndex: (unsigned int *)&a3,
                 pglyphIndex: nullptr,
                 avoidComposStr: 1,
                 plineAlignment: nullptr) == 0 )
            goto LABEL_97;
          if ( *((float *)this + 18) >= 0.0 )
            v27 = *((float *)this + 18);
          else
            v27 = v60;
          v28 = *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                + 2);
          v65 = v27;
          BottomVScroll = GFxTextDocView::GetBottomVScroll(this: v28, a2: v8);
          v30 = *((GRefCountBase<GFxAmpMemSegment,2> **)this + 2);
          v31 = BottomVScroll - (unsigned int)v30[7].__vftable + 1;
          if ( (unsigned int)a3 < v31 )
            goto LABEL_40;
          GFxTextDocView::GetCursorPosInLine(
            this: v30,
            lineIndex: (const GRefCountBase<GFxAmpMemSegment,2> *)&a3[-v31],
            x: v65);
          goto LABEL_96;
        case 9:
          v32 = *((const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                + 6);
          v55 = 0.0;
          v56 = 0.0;
          v57 = 0.0;
          v58 = 0.0;
          if ( GFxTextEditorKit::CalcCursorRectOnScreen(
                 a1: (int)this,
                 a2: v12,
                 result: v32,
                 a4: &v55,
                 plineIndex: (unsigned int *)&a3,
                 pglyphIndex: nullptr,
                 avoidComposStr: 1,
                 plineAlignment: nullptr) == 0 )
            goto LABEL_97;
          if ( *((float *)this + 18) >= 0.0 )
            v33 = *((float *)this + 18);
          else
            v33 = v55;
          v34 = *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                + 2);
          v65 = v33;
          v35 = GFxTextDocView::GetBottomVScroll(this: v34, a2: v8);
          v36 = *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                + 2);
          v37 = &a3[v35 - (unsigned int)v36[14].pTable + 1];
          if ( (unsigned int)v37 >= GFxTextDocView::GetLinesCount(
                                      this: v36,
                                      a2: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v37) )
            goto LABEL_47;
          goto LABEL_68;
        case 10:
          LineIndexOfChar = GFxTextDocView::GetLineIndexOfChar(
                              this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                              + 2),
                              a2: v8,
                              indexOfChar: *((_DWORD *)this + 6));
          if ( LineIndexOfChar == -1 )
            goto LABEL_97;
          LineOffset = GFxTextDocView::GetLineOffset(
                         this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                         + 2),
                         a2: v8,
                         lineIndex: LineIndexOfChar);
          goto LABEL_96;
        case 11:
          *(float *)&v19 = COERCE_FLOAT(
                             GFxTextDocView::GetLineIndexOfChar(
                               this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                               + 2),
                               a2: v8,
                               indexOfChar: *((_DWORD *)this + 6)));
          v12 = (VJobInstance *)v19;
          if ( *(float *)&v19 != NAN )
          {
            v20 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
            HIBYTE(a3) = 0;
            GFxTextDocView::GetLineLength(this: v20, lineIndex: v19);
            v63 = v21;
            if ( HIBYTE(a3) != 0 )
              --v63;
            v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)(v63 + GFxTextDocView::GetLineOffset(this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this + 2), a2: v8, lineIndex: (signed int)v12));
          }
          goto LABEL_97;
        case 12:
          LineOffset = GFxTextDocView::GetLineOffset(
                         this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
                         + 2),
                         a2: v8,
                         lineIndex: *(_DWORD *)(*((_DWORD *)this + 2) + 56));
          goto LABEL_96;
        case 13:
          v22 = (const GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)GFxTextDocView::GetBottomVScroll(this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this + 2), a2: v8);
          v23 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
          v24 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v22;
          HIBYTE(a3) = 0;
          GFxTextDocView::GetLineLength(this: v23, lineIndex: v22);
          v12 = v25;
          if ( HIBYTE(a3) != 0 )
            v12 = (VJobInstance *)((char *)v25 - 1);
          v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)((char *)v12 + GFxTextDocView::GetLineOffset(this: *((GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this + 2), a2: v24, lineIndex: (signed int)v24));
          goto LABEL_97;
        case 14:
          goto LABEL_40;
        case 15:
          goto LABEL_47;
        case 16:
          if ( (*(_BYTE *)(this + 26) & 1) != 0 )
            goto LABEL_97;
          v43 = endPos;
          v44 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
          if ( v12 != (VJobInstance *)endPos )
            goto LABEL_72;
          a2 = v8;
          GFxTextDocView::EditCommand(this: v44, a2: (const char *)v12, cmdId: 8u, command: (ButtonCode_t)&a2);
          v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)((char *)v8 - v45);
          HIBYTE(a2) = 1;
          goto LABEL_97;
        case 17:
          if ( (*(_BYTE *)(this + 26) & 1) != 0 )
            goto LABEL_97;
          v43 = endPos;
          if ( v12 == (VJobInstance *)endPos )
          {
            if ( *((_DWORD *)this + 6) < v63 )
            {
              v46 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this
                    + 2);
              a2 = v8;
              GFxTextDocView::EditCommand(this: v46, a2: (const char *)v12, cmdId: 3u, command: (ButtonCode_t)&a2);
              HIBYTE(a2) = 1;
            }
            goto LABEL_97;
          }
          v44 = *((GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > **)this + 2);
LABEL_72:
          v63 = v43;
          v62 = (unsigned int)v12;
          GFxTextDocView::EditCommand(this: v44, a2: (const char *)v12, cmdId: 4u, command: (ButtonCode_t)&v62);
          v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)endPos;
          if ( (unsigned int)v12 < endPos )
            v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v12;
          goto LABEL_74;
        case 18:
          if ( (*(_BYTE *)(this + 26) & 1) == 0 )
          {
            v47 = *((_DWORD *)this + 2);
            if ( (*(_BYTE *)(v47 + 334) & 4) != 0 )
            {
              *((_WORD *)this + 52) &= ~0x40u;
              v48 = *(_DWORD *)(v47 + 8);
              if ( v12 == (VJobInstance *)endPos )
              {
                v49 = *((float *)this + 6);
                LOWORD(v63) = (unsigned __int8)((*(_BYTE *)(v48 + 32) & 2) != 0 ? 13 : 10);
                *(float *)&v62 = v49;
                GFxTextDocView::EditCommand(
                  this: (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)v47,
                  a2: (const char *)v12,
                  cmdId: 0,
                  command: (ButtonCode_t)&v62);
                v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)((char *)v8 + 1);
                HIBYTE(a2) = 1;
              }
              else
              {
                v50 = (*(_BYTE *)(v48 + 32) & 2) != 0 ? 3 : 0;
                v62 = endPos;
                v61 = *(float *)&v12;
                LOWORD(v63) = (unsigned __int8)(v50 + 10);
                GFxTextDocView::EditCommand(
                  this: (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)v47,
                  a2: (const char *)v12,
                  cmdId: 5u,
                  command: (ButtonCode_t)&v61);
                v51 = endPos;
                if ( (unsigned int)v12 < endPos )
                  v51 = (unsigned int)v12;
                v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)(v51 + 1);
                HIBYTE(a2) = 1;
              }
            }
          }
          goto LABEL_97;
        case 19:
        case 21:
          if ( *((_DWORD *)this + 3) != 0 )
          {
            if ( (*(_BYTE *)(this + 26) & 1) != 0 || v16 == 19 )
            {
              *((_WORD *)this + 52) &= ~0x40u;
              GFxTextEditorKit::CopyToClipboard(
                this,
                startPos: (const char *)v12,
                (const struct GFxTextParagraph *)endPos,
                a4: (*(_BYTE *)(this + 26) & 4) != 0);
              break;
            }
            v12 = (VJobInstance *)endPos;
            v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)startPos;
            *((_WORD *)this + 52) &= ~0x40u;
            GFxTextEditorKit::CutToClipboard(
              this,
              startPos: (const char *)v8,
              endPos: (const struct GFxTextParagraph *)v12,
              a4: (*(_BYTE *)(this + 26) & 4) != 0);
            if ( v8 < (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v12 )
            {
LABEL_74:
              HIBYTE(a2) = 1;
            }
            else
            {
              v8 = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v12;
              HIBYTE(a2) = 1;
            }
          }
LABEL_97:
          if ( *((const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > **)this
               + 6) != v8 )
          {
            GFxTextEditorKit::SetCursorPos(
              this,
              a2: v12,
              textPos: v8,
              selectionAllowed: (*(_BYTE *)(this + 26) & 2) != 0);
            *((float *)this + 18) = v65;
LABEL_102:
            v68 = 1;
            goto LABEL_103;
          }
          v52 = *((_WORD *)this + 52);
          if ( (v52 & 0x40) == 0 && startPos != endPos )
          {
            GFxTextEditorKit::SetCursorPos(this, a2: v12, textPos: v8, selectionAllowed: (v52 & 2) != 0);
            goto LABEL_102;
          }
LABEL_103:
          if ( HIBYTE(a2) != 0 )
          {
            if ( v68 == 0 )
              GFxTextDocView::SetDefaultTextAndParaFormat(
                this: *((GRefCountBase<GFxAmpMemSegment,2> **)this + 2),
                cursorPos: *((_DWORD *)this + 6));
            v53 = *(_DWORD *)(v59 + 16);
            if ( v53 != 0 )
              (*(void (__thiscall **)(int, GFxTextEditorKit *))(*(_DWORD *)v53 + 32))(a1: v53, a2: this);
          }
          break;
        case 20:
          LOBYTE(a3) = (*(_BYTE *)(this + 26) & 4) != 0;
          LineOffset = GFxTextEditorKit::PasteFromClipboard(
                         this,
                         startPos: (GFxAmpHeapInfo *)v12,
                         (GFxAmpHeapInfo *)endPos,
                         useRichClipboard: (bool)a3);
          if ( LineOffset == -1 )
            goto LABEL_97;
          HIBYTE(a2) = 1;
          goto LABEL_96;
        case 22:
          GFxTextEditorKit::SetCursorPos(
            this,
            a2: v12,
            textPos: (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v63);
          GFxTextDocView::SetSelection(this: *((GFxTextDocView **)this + 2), startPos: 0, endPos: v63);
          break;
        default:
          break;
      }
    }
  }
  if ( v67 != 0 )
LABEL_109:
    *((_WORD *)this + 52) |= 0x40u;
  return v68;
}

//------------------------------------------------------------------------------
// Address: 0x10171E00
// Name: protected: virtual void GFxTextEditorKit::OnDocumentChanged(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextEditorKit::OnDocumentChanged(
        GFxTextEditorKit *this@<ecx>,
        const VJobInstance *a2@<ebx>,
        __int16 a3)
{
  const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *Length; // eax

  if ( (a3 & 0x102) != 0 )
  {
    if ( (*(_BYTE *)(this + 26) & 1) == 0 || (*(_BYTE *)(this + 26) & 2) != 0 )
      GFxTextEditorKit::SetCursorPos(this, a2, textPos: nullptr, selectionAllowed: (*(_BYTE *)(this + 26) & 2) != 0);
  }
  else if ( *((_DWORD *)this + 6) > GFxStyledText::GetLength(this: *(GFxStyledText **)(*((_DWORD *)this + 2) + 8)) )
  {
    Length = (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)GFxStyledText::GetLength(this: *(GFxStyledText **)(*((_DWORD *)this + 2) + 8));
    GFxTextEditorKit::SetCursorPos(this, a2, textPos: Length, selectionAllowed: (*(_BYTE *)(this + 26) & 2) != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171E70
// Name: public: void GFxTextEditorKit::SetSelection(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextEditorKit::SetSelection(
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::Iterator *this@<ecx>,
        const VJobInstance *a2@<ebx>,
        GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *startPos,
        const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *endPos)
{
  if ( (*(_BYTE *)(this + 13) & 1) == 0 || (*(_BYTE *)(this + 13) & 2) != 0 )
    GFxTextEditorKit::SetCursorPos(
      (GFxTextEditorKit *)this,
      a2,
      textPos: endPos,
      selectionAllowed: (*(_BYTE *)(this + 13) & 2) != 0);
  GFxTextDocView::SetSelection(this: *((GFxTextDocView **)this + 2), (unsigned int)startPos, (unsigned int)endPos);
}

//------------------------------------------------------------------------------
// Address: 0x10171EB0
// Name: public: GFxTextCompositionString::GFxTextCompositionString(class GFxTextEditorKit __near *)
// Source: json
//------------------------------------------------------------------------------
GFxTextCompositionString *__thiscall GFxTextCompositionString::GFxTextCompositionString(GFxTextCompositionString *this, struct GFxTextEditorKit *a2)
{
  int v3; // eax
  const GFxResourceId *v4; // eax
  int v5; // edx
  int v6; // edx
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *v7; // eax
  struct GMemoryHeap *TextFormat; // eax
  IShaderAPI *v9; // ecx
  struct GMemoryHeap *v10; // ecx
  int v11; // eax
  IVJobs_vtbl *v12; // ecx
  IVJobs_vtbl **v13; // eax
  bool v14; // zf
  const GPtr<GFxAmpMemFragReport> *DefaultStyles; // eax
  IVJobs v17; // [esp+Ch] [ebp-B8h] BYREF
  int v18; // [esp+10h] [ebp-B4h]
  int v19; // [esp+14h] [ebp-B0h]
  int v20; // [esp+18h] [ebp-ACh]
  int v21; // [esp+1Ch] [ebp-A8h]
  int v22; // [esp+20h] [ebp-A4h]
  int v23; // [esp+24h] [ebp-A0h]
  int v24; // [esp+28h] [ebp-9Ch]
  int v25; // [esp+2Ch] [ebp-98h]
  char v26; // [esp+30h] [ebp-94h]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v27; // [esp+34h] [ebp-90h] BYREF
  GStringDH v28; // [esp+3Ch] [ebp-88h] BYREF
  GStringDH v29; // [esp+44h] [ebp-80h] BYREF
  int v30; // [esp+4Ch] [ebp-78h]
  int v31; // [esp+50h] [ebp-74h]
  int v32; // [esp+54h] [ebp-70h]
  int v33; // [esp+58h] [ebp-6Ch]
  char v34; // [esp+5Ch] [ebp-68h]
  __int16 v35; // [esp+5Eh] [ebp-66h]
  int v36; // [esp+60h] [ebp-64h]
  IVJobs_vtbl **v37; // [esp+64h] [ebp-60h]
  struct GMemoryHeap *v38; // [esp+68h] [ebp-5Ch]
  _BYTE v39[84]; // [esp+6Ch] [ebp-58h] BYREF

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxTextCompositionString::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = a2;
  GFxStyledText::GetAllocator(this: *(SFTextObjectImpl **)(*((_DWORD *)a2 + 2) + 8));
  if ( v3 != 0 )
    ++*(_DWORD *)(v3 + 4);
  *((_DWORD *)this + 4) = v3;
  GFxStyledText::GetAllocator(this: *(SFTextObjectImpl **)(*((_DWORD *)a2 + 2) + 8));
  GFxTextParagraph::GFxTextParagraph(this: (int)this + 20, result: v4);
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_BYTE *)this + 80) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_BYTE *)this + 96) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_BYTE *)this + 112) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_BYTE *)this + 128) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_BYTE *)this + 144) = 0;
  *((_BYTE *)this + 148) = 0;
  v5 = *((_DWORD *)this + 4);
  *((_BYTE *)this + 192) = 0;
  v38 = *(struct GMemoryHeap **)(v5 + 28);
  v27.m_pObject = (IMaterialInternal *)1;
  v27.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))&GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: &v28, a2: v38);
  GStringDH::GStringDH(this: &v29, a2: v38);
  v33 = 0;
  v6 = *((_DWORD *)a2 + 2);
  v30 = 0;
  v31 = 0;
  v32 = -16777216;
  v34 = 0;
  v35 = 0;
  v7 = *(CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> **)(*(_DWORD *)(v6 + 8) + 28);
  if ( v7 == nullptr )
    v7 = &v27;
  TextFormat = (struct GMemoryHeap *)GFxTextAllocator::AllocateTextFormat(
                                       this: *((CMaterial **)this + 4),
                                       srcfmt: (int)v7);
  v9 = *((IShaderAPI **)this + 2);
  v38 = TextFormat;
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  v10 = v38;
  *((_DWORD *)this + 2) = v38;
  GFxTextParagraph::AppendTermNull(
    this: (GFxTextParagraph *)this + 5,
    result: *((GFxFontMap **)this + 4),
    a3: (const struct GFxTextFormat *)v10);
  GFxTextDocView::CreateHighlighterManager(this: *(GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> **)(*((_DWORD *)this + 3) + 8));
  v36 = v11;
  v37 = (IVJobs_vtbl **)((char *)this + 152);
  v38 = (struct GMemoryHeap *)10;
  do
  {
    v20 = 0;
    v21 = 0;
    v22 = 0;
    v25 = 0;
    v24 = 0;
    v23 = 0;
    v26 = 0;
    v17.__vftable = nullptr;
    v19 = 0;
    v18 = 0;
    v12 = GFxTextHighlighter::CreateNewHighlighter(result: &v17)[5].__vftable;
    v13 = v37;
    *v37 = v12;
    v14 = v38 == (struct GMemoryHeap *)1;
    v38 = (struct GMemoryHeap *)((char *)v38 - 1);
    v37 = v13 + 1;
  }
  while ( !v14 );
  DefaultStyles = (const GPtr<GFxAmpMemFragReport> *)GFxTextCompositionString::GetDefaultStyles(a1: (int)v39);
  GFxTextIMEStyle::GFxTextIMEStyle(this: (GPtr<GFxAmpMemFragReport> *)this + 17, __that: DefaultStyles);
  GFxTextFormat::~GFxTextFormat(this: &v27);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101720C0
// Name: public: virtual GFxTextCompositionString::~GFxTextCompositionString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextCompositionString::~GFxTextCompositionString(IShaderAPI *this)
{
  int v2; // eax
  IResourceAccessControl *v3; // eax
  IShaderAPI *v4; // esi
  int i; // ebx
  int v6; // eax
  IShaderAPI **v7; // ebx
  GRefCountNTSImpl *v8; // ecx
  GRefCountNTSImpl *v9; // ecx
  IShaderAPI *v10; // ecx
  IResourceAccessControl *v11; // [esp+Ch] [ebp-4h]
  IResourceAccessControl *v12; // [esp+Ch] [ebp-4h]

  v2 = *((_DWORD *)this + 3);
  this->__vftable = (IShaderAPI_vtbl *)&GFxTextCompositionString::`vftable';
  GFxTextDocView::CreateHighlighterManager(this: *(GArrayData<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayDefaultPolicy> **)(v2 + 8));
  v11 = v3;
  v4 = this + 38;
  for ( i = 10; i != 0; --i )
  {
    GFxTextHighlighter::FreeHighlighter(this: v11);
    ++v4;
  }
  GFxTextParagraph::TextBuffer::Free(this: (GFxFontMap *)(this + 5), pallocator: *((_DWORD *)this + 4));
  v6 = *((_DWORD *)this + 10);
  v7 = (IShaderAPI **)(*((_DWORD *)this + 9) + 12 * v6 - 4);
  if ( v6 != 0 )
  {
    v12 = *((IResourceAccessControl **)this + 10);
    do
    {
      if ( *v7 != nullptr )
        GRefCountImpl::Release(this: *v7);
      v7 -= 3;
      v12 = (IResourceAccessControl *)((char *)v12 - 1);
    }
    while ( v12 != nullptr );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 9));
  v8 = *((GRefCountNTSImpl **)this + 8);
  if ( v8 != nullptr )
    GRefCountNTSImpl::Release(this: v8);
  CDummyMaterialSystem::EndBatch();
  v9 = *((GRefCountNTSImpl **)this + 4);
  if ( v9 != nullptr )
    GRefCountNTSImpl::Release(this: v9);
  v10 = *((IShaderAPI **)this + 2);
  if ( v10 != nullptr )
    GRefCountImpl::Release(this: v10);
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x10172180
// Name: public: class GFxTextCompositionString __near * GFxTextEditorKit::CreateCompositionString(void)
// Source: json
//------------------------------------------------------------------------------
const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *__thiscall GFxTextEditorKit::CreateCompositionString(
        GRefCountNTSImpl **this)
{
  GFxTextCompositionString *v2; // eax
  GFxTextCompositionString *v3; // edi
  GRefCountNTSImpl *v4; // ecx
  int v6; // [esp+8h] [ebp-4h] BYREF

  v6 = 324;
  v2 = (GFxTextCompositionString *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                     this: GMemory::pGlobalHeap,
                                     a2: this,
                                     a3: 196,
                                     a4: &v6);
  if ( v2 != nullptr )
    v3 = GFxTextCompositionString::GFxTextCompositionString(this: v2, a2: (struct GFxTextEditorKit *)this);
  else
    v3 = nullptr;
  v4 = *(this + 5);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  *(this + 5) = (GRefCountNTSImpl *)v3;
  return (const GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10174BC0
// Name: public: bool GFxTextLineBuffer::IsLineVisible(unsigned int,float)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxTextLineBuffer::IsLineVisible(
        CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *this,
        unsigned int lineIndex,
        float yOffset)
{
  IMaterialVar *v3; // eax
  unsigned int v4; // esi
  double v5; // st7
  double v6; // st6
  float y; // esi
  float w; // eax
  float yOffseta; // [esp+10h] [ebp+Ch]
  float yOffsetb; // [esp+10h] [ebp+Ch]

  v3 = this->m_Memory.m_pMemory[lineIndex];
  v4 = *((_DWORD *)this + 5);
  if ( lineIndex == v4 )
  {
    v5 = (double)SLODWORD(v3->m_VecVal.y) + yOffset;
    yOffseta = *((float *)this + 9) - *((float *)this + 7);
    v6 = yOffseta;
  }
  else
  {
    if ( lineIndex <= v4 )
      return false;
    y = v3->m_VecVal.y;
    if ( (int)v3->__vftable >= 0 )
      w = v3->m_VecVal.w;
    else
      LODWORD(w) = HIWORD(v3->m_VecVal.z);
    v5 = (double)(LODWORD(y) + LODWORD(w)) + yOffset;
    yOffsetb = *((float *)this + 9) - *((float *)this + 7);
    v6 = yOffsetb;
  }
  return v6 + 20.0 >= v5;
}
