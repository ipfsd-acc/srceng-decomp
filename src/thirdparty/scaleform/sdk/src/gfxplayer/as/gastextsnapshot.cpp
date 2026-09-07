// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gastextsnapshot.cpp
// Functions: 160
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gastextsnapshot.h"

//------------------------------------------------------------------------------
// Address: 0x1011C580
// Name: public: void GASTextSnapshotObject::Process(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTextSnapshotObject::Process(GPtr<GFxAmpViewStats> *this, GPtr<GFxZlibSupportBase> *result)
{
  GFxSprite::GetTextSnapshot(this: result, a2: this + 13);
}

//------------------------------------------------------------------------------
// Address: 0x1011C5A0
// Name: public: static void GASTextSnapshotProto::GetCount(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASTextSnapshotProto::GetCount(GASFnCall *a1)
{
  GASFnCall v1; // eax
  GFxStaticTextSnapshotData *p_cxItem; // eax
  int CharCount; // eax
  GASFnCall v4; // esi
  int v5; // edi

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x2Bu) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
    {
      p_cxItem = (GFxStaticTextSnapshotData *)&v1[-1].cxItem;
      if ( p_cxItem != nullptr )
      {
        CharCount = GFxStaticTextSnapshotData::GetCharCount(this: p_cxItem + 13);
        v4 = a1[1];
        v5 = CharCount;
        if ( LOBYTE(v4->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v4, a2: CharCount);
        v4->cItems = v5;
        LOBYTE(v4->cbSize) = 4;
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "TextSnapshot", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C600
// Name: public: static void GASTextSnapshotProto::GetSelected(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextSnapshotProto::GetSelected(int a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  GFxStaticTextSnapshotData *p_cxItem; // ebx
  GASValue *v5; // eax
  GPtr<GFxAmpViewStats> *v6; // edi
  long double v7; // st7
  GASValue *v8; // eax
  unsigned int CharCount; // eax
  char IsSelected; // al
  GASFnCall v11; // esi
  char v12; // bl
  _SERVICE_STATUS *v13; // [esp-Ch] [ebp-10h]
  _SERVICE_STATUS *v14; // [esp-Ch] [ebp-10h]

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x2Bu) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
    {
      p_cxItem = (GFxStaticTextSnapshotData *)&v3[-1].cxItem;
      if ( v3 != (GASFnCall)16 && (int)a3[7] >= 1 )
      {
        v13 = (_SERVICE_STATUS *)a3[6];
        v5 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
        v6 = (GPtr<GFxAmpViewStats> *)GASValue::ToUInt32(this: v5, a2: a1, a3: a2, a4: v13);
        if ( (int)a3[7] <= 1 )
        {
          CharCount = GFxStaticTextSnapshotData::GetCharCount(this: p_cxItem + 13);
        }
        else
        {
          v14 = (_SERVICE_STATUS *)a3[6];
          v8 = (GASValue *)GASFnCall::Arg(this: a3, a2: 1);
          CharCount = GASValue::ToUInt32(this: v8, a2: (int)v6, a3: v7, a4: v14);
        }
        if ( CharCount <= (unsigned int)v6 )
          CharCount = (unsigned int)&v6->pObject + 1;
        IsSelected = GFxStaticTextSnapshotData::IsSelected(this: (_DWORD *)p_cxItem + 13, result: v6, end: CharCount);
        v11 = a3[1];
        v12 = IsSelected;
        GASValue::DropRefs(this: (GASValue *)v11, a2: (int)v6);
        LOBYTE(v11->cbSize) = 2;
        LOBYTE(v11->cItems) = v12;
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "TextSnapshot", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C6A0
// Name: public: static void GASTextSnapshotProto::SetSelected(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextSnapshotProto::SetSelected(int a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  GASValue *v4; // eax
  int v5; // eax
  Vector *v6; // ebx
  GASValue *v7; // eax
  long double v8; // st7
  int v9; // eax
  unsigned int v10; // edi
  char *v11; // eax
  long double v12; // st7
  _SERVICE_STATUS *v13; // [esp-Ch] [ebp-18h]
  _SERVICE_STATUS *v14; // [esp-Ch] [ebp-18h]
  tagPOLYTEXTW *v15; // [esp-Ch] [ebp-18h]
  GPtr<GFxAmpViewStats> *p_cxItem; // [esp+4h] [ebp-8h]
  char v17; // [esp+8h] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x2Bu) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
    {
      p_cxItem = (GPtr<GFxAmpViewStats> *)&v3[-1].cxItem;
      if ( v3 != (GASFnCall)16 && (int)a3[7] >= 3 )
      {
        v13 = (_SERVICE_STATUS *)a3[6];
        v4 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
        v5 = GASValue::ToUInt32(this: v4, a2: a1, a3: a2, a4: v13);
        v14 = (_SERVICE_STATUS *)a3[6];
        v6 = (Vector *)v5;
        v7 = (GASValue *)GASFnCall::Arg(this: a3, a2: 1);
        v9 = GASValue::ToUInt32(this: v7, a2: a1, a3: v8, a4: v14);
        v15 = (tagPOLYTEXTW *)a3[6];
        v10 = v9;
        v11 = (char *)GASFnCall::Arg(this: a3, a2: 2);
        v17 = GASValue::ToBool(a1: v11, a2: v12, result: v15);
        if ( v10 <= (unsigned int)v6 )
          v10 = (unsigned int)&v6->x + 1;
        GFxStaticTextSnapshotData::SetSelected(this: p_cxItem + 13, start: v6, end: v10, bselect: v17);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "TextSnapshot", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C750
// Name: public: static void GASTextSnapshotProto::FindTextA(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextSnapshotProto::FindTextA(int a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  GASValue *v4; // eax
  int v5; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v6; // ebx
  signed int v7; // edi
  unsigned __int8 *v8; // eax
  char *v9; // eax
  long double v10; // st7
  int TextA; // eax
  GASFnCall v12; // esi
  int v13; // edi
  void *v14; // esi
  int v15; // eax
  _SERVICE_STATUS *v17; // [esp-Ch] [ebp-20h]
  tagPOLYTEXTW *v18; // [esp-Ch] [ebp-20h]
  GFxStaticTextSnapshotData *p_cxItem; // [esp+4h] [ebp-10h]
  char v20; // [esp+8h] [ebp-Ch]
  int v21; // [esp+Ch] [ebp-8h] BYREF
  GString v22; // [esp+10h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x2Bu) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
    {
      p_cxItem = (GFxStaticTextSnapshotData *)&v3[-1].cxItem;
      if ( v3 != (GASFnCall)16 && (int)a3[7] >= 3 )
      {
        v17 = (_SERVICE_STATUS *)a3[6];
        v4 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
        v5 = GASValue::ToUInt32(this: v4, a2: a1, a3: a2, a4: v17);
        v6 = (tagRID_DEVICE_INFO_KEYBOARD *)a3[6];
        v7 = v5;
        v8 = (unsigned __int8 *)GASFnCall::Arg(this: a3, a2: 1);
        GASValue::ToStringImpl(this: v8, a2: &v21, a3: v6, precision: -1, debug: false);
        v18 = (tagPOLYTEXTW *)a3[6];
        v9 = (char *)GASFnCall::Arg(this: a3, a2: 2);
        v20 = GASValue::ToBool(a1: v9, a2: v10, result: v18);
        GString::GString(this: &v22, src: *(char **)v21, count: *(_DWORD *)(v21 + 16));
        TextA = GFxStaticTextSnapshotData::FindTextA(
                  this: p_cxItem + 13,
                  a2: v7,
                  putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)((v22.HeapTypeBits & 0xFFFFFFFC) + 8),
                  a4: v20);
        v12 = a3[1];
        v13 = TextA;
        if ( LOBYTE(v12->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v12, a2: TextA);
        LOBYTE(v12->cbSize) = 4;
        v12->cItems = v13;
        v14 = (void *)(v22.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v22.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
        v15 = v21;
        if ( (*(_DWORD *)(v21 + 8))-- == 1 )
          GASStringNode::ReleaseNode(a1: v15);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "TextSnapshot", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C870
// Name: public: static void GASTextSnapshotProto::GetSelectedText(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextSnapshotProto::GetSelectedText(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  GPtr<GFxAmpViewStats> *p_cxItem; // esi
  char *v4; // eax
  struct GASStringNode *StringNode; // esi
  GASFnCall v6; // edi
  bool v7; // zf
  void *v8; // esi
  tagPOLYTEXTW *v9; // [esp-8h] [ebp-14h]
  int v10; // [esp+4h] [ebp-8h] BYREF
  int v11; // [esp+8h] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x2Bu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
    {
      p_cxItem = (GPtr<GFxAmpViewStats> *)&v2[-1].cxItem;
      if ( v2 != (GASFnCall)16 )
      {
        if ( (int)a2[7] <= 0 )
        {
          LOBYTE(v11) = 0;
        }
        else
        {
          v9 = (tagPOLYTEXTW *)a2[6];
          v4 = (char *)GASFnCall::Arg(this: a2, a2: 0);
          LOBYTE(v11) = GASValue::ToBool(a1: v4, a2: a1, result: v9);
        }
        GFxStaticTextSnapshotData::GetSelectedText(
          this: p_cxItem + 13,
          binclNewLines: (CUtlMemory<CImagePacker,int> *)&v10,
          binclNewLinesa: v11);
        StringNode = GASStringManager::CreateStringNode(
                       this: *(GASStringManager **)(a2[6][3].cbSize + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v10 & 0xFFFFFFFC) + 8),
                       length: *(_DWORD *)(v10 & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++*((_DWORD *)StringNode + 2);
        v6 = a2[1];
        if ( LOBYTE(v6->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v6, a2: (int)v6);
        LOBYTE(v6->cbSize) = 5;
        v6->cItems = (int)StringNode;
        v7 = ++*((_DWORD *)StringNode + 2) == 1;
        --*((_DWORD *)StringNode + 2);
        if ( v7 )
          GASStringNode::ReleaseNode(a1: (int)StringNode);
        v8 = (void *)(v10 & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v10 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "TextSnapshot", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C970
// Name: public: static void GASTextSnapshotProto::GetText(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextSnapshotProto::GetText(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  GASValue *v3; // eax
  int v4; // eax
  unsigned int v5; // ebx
  GASValue *v6; // eax
  long double v7; // st7
  unsigned int v8; // esi
  long double v9; // st7
  char *v10; // eax
  struct GASStringNode *StringNode; // esi
  GASFnCall v12; // edi
  bool v13; // zf
  void *v14; // esi
  _SERVICE_STATUS *v15; // [esp-Ch] [ebp-1Ch]
  _SERVICE_STATUS *v16; // [esp-Ch] [ebp-1Ch]
  tagPOLYTEXTW *v17; // [esp-Ch] [ebp-1Ch]
  GPtr<GFxAmpViewStats> *p_cxItem; // [esp+4h] [ebp-Ch]
  int v19; // [esp+8h] [ebp-8h] BYREF
  int v20; // [esp+Ch] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x2Bu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
    {
      p_cxItem = (GPtr<GFxAmpViewStats> *)&v2[-1].cxItem;
      if ( v2 != (GASFnCall)16 && (int)a2[7] >= 2 )
      {
        v15 = (_SERVICE_STATUS *)a2[6];
        v3 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
        v4 = GASValue::ToUInt32(this: v3, (int)a2, a3: a1, a4: v15);
        v16 = (_SERVICE_STATUS *)a2[6];
        v5 = v4;
        v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
        v8 = GASValue::ToUInt32(this: v6, (int)a2, a3: v7, a4: v16);
        if ( (int)a2[7] >= 3 )
        {
          v17 = (tagPOLYTEXTW *)a2[6];
          v10 = (char *)GASFnCall::Arg(this: a2, a2: 2);
          LOBYTE(v20) = GASValue::ToBool(a1: v10, a2: v9, result: v17);
        }
        else
        {
          LOBYTE(v20) = 0;
        }
        if ( v8 <= v5 )
          v8 = v5 + 1;
        GFxStaticTextSnapshotData::GetSubString(
          this: p_cxItem + 13,
          start: (CUtlMemory<CImagePacker,int> *)&v19,
          starta: v5,
          end: v8,
          binclNewLines: v20);
        StringNode = GASStringManager::CreateStringNode(
                       this: *(GASStringManager **)(a2[6][3].cbSize + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v19 & 0xFFFFFFFC) + 8),
                       length: *(_DWORD *)(v19 & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++*((_DWORD *)StringNode + 2);
        v12 = a2[1];
        if ( LOBYTE(v12->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v12, a2: (int)v12);
        LOBYTE(v12->cbSize) = 5;
        v12->cItems = (int)StringNode;
        v13 = ++*((_DWORD *)StringNode + 2) == 1;
        --*((_DWORD *)StringNode + 2);
        if ( v13 )
          GASStringNode::ReleaseNode(a1: (int)StringNode);
        v14 = (void *)(v19 & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v19 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "TextSnapshot", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CAB0
// Name: public: static void GASTextSnapshotProto::HitTestTextNearPos(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextSnapshotProto::HitTestTextNearPos(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int p_cxItem; // edi
  GASValue *v4; // eax
  double v5; // st7
  GASValue *v6; // eax
  double v7; // st7
  GASValue *v8; // eax
  int v9; // eax
  GASFnCall v10; // esi
  _SERVICE_STATUS *v11; // [esp+8h] [ebp-18h]
  _SERVICE_STATUS *v12; // [esp+8h] [ebp-18h]
  _SERVICE_STATUS *v13; // [esp+8h] [ebp-18h]
  float v14; // [esp+14h] [ebp-Ch]
  float x; // [esp+14h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-Ch]
  float v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+18h] [ebp-8h]
  float v19; // [esp+1Ch] [ebp-4h]
  float v20; // [esp+1Ch] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x2Bu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
    {
      p_cxItem = (int)&v2[-1].cxItem;
      if ( v2 != (GASFnCall)16 && (int)a2[7] >= 2 )
      {
        v11 = (_SERVICE_STATUS *)a2[6];
        v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
        v5 = GASValue::ToNumber(this: v4, a2: p_cxItem, a3: a1, result: v11);
        v14 = v5;
        v12 = (_SERVICE_STATUS *)a2[6];
        v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
        v7 = GASValue::ToNumber(this: v6, a2: p_cxItem, a3: v5, result: v12);
        v17 = v7;
        if ( (int)a2[7] <= 2 )
        {
          v19 = 0.0;
        }
        else
        {
          v13 = (_SERVICE_STATUS *)a2[6];
          v8 = (GASValue *)GASFnCall::Arg(this: a2, a2: 2);
          v19 = GASValue::ToNumber(this: v8, a2: p_cxItem, a3: v7, result: v13);
        }
        v20 = v19 * 20.0;
        *(float *)&v18 = v17 * 20.0;
        x = 20.0 * v14;
        v9 = GFxStaticTextSnapshotData::HitTestTextNearPos(
               this: (GPtr<GFxAmpViewStats> *)(p_cxItem + 52),
               a2: (CMatRenderContextBase *)p_cxItem,
               x: (const GPtr<GFxAmpViewStats> *)LODWORD(x),
               y: v18,
               xoffInLine: v20);
        v10 = a2[1];
        v16 = v9;
        if ( LOBYTE(v10->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v10, a2: p_cxItem);
        LOBYTE(v10->cbSize) = 3;
        *(double *)&v10->cItems = (double)v16;
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "TextSnapshot", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CBB0
// Name: public: static void GASTextSnapshotProto::SetSelectColor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextSnapshotProto::SetSelectColor(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  GPtr<GFxAmpViewStats> *p_cxItem; // edi
  GASValue *v4; // eax
  _SERVICE_STATUS *v5; // [esp-8h] [ebp-10h]
  int v6; // [esp+4h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x2Bu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
    {
      p_cxItem = (GPtr<GFxAmpViewStats> *)&v2[-1].cxItem;
      if ( v2 != (GASFnCall)16 && (int)a2[7] >= 1 )
      {
        v5 = (_SERVICE_STATUS *)a2[6];
        v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
        v6 = GASValue::ToUInt32(this: v4, a2: (int)p_cxItem, a3: a1, a4: v5);
        HIBYTE(v6) = -1;
        GFxStaticTextSnapshotData::SetSelectColor(this: p_cxItem + 13, color: (GFxAmpViewStats *)&v6);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "TextSnapshot", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CC60
// Name: public: virtual void GASTextSnapshotGlyphVisitor::OnVisit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASTextSnapshotGlyphVisitor::OnVisit(GASTextSnapshotGlyphVisitor *this@<ecx>, int a2@<ebx>)
{
  int v3; // ecx
  int (__thiscall *v4)(int, int, char *); // edx
  GASObject *v5; // eax
  int v6; // eax
  int v7; // edx
  struct GASObject *v8; // edi
  int v9; // eax
  bool v10; // zf
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v11; // eax
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  unsigned int v16; // ebx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  CFunctor *elem; // edx
  int v21; // edx
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // eax
  int v54; // eax
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int v60; // eax
  int v61; // eax
  int v62; // eax
  int v63; // eax
  int v64; // eax
  struct GASObject *v65; // edi
  tagWNDCLASSW *v66; // eax
  GASValue v67; // [esp+8h] [ebp-48h] BYREF
  double v68; // [esp+Ch] [ebp-44h]
  GASValue v69[2]; // [esp+18h] [ebp-38h] BYREF
  double v70; // [esp+20h] [ebp-30h]
  double v71; // [esp+28h] [ebp-28h]
  double v72; // [esp+30h] [ebp-20h]
  double v73; // [esp+38h] [ebp-18h]
  double v74; // [esp+40h] [ebp-10h] BYREF
  struct GASObject *v75; // [esp+48h] [ebp-8h]
  char v76; // [esp+4Fh] [ebp-1h] BYREF

  v3 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 17) + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, char *))(*(_DWORD *)v3 + 40);
  HIDWORD(v74) = 323;
  v5 = (GASObject *)v4(a1: v3, a2: 52, a3: (char *)&v74 + 4);
  if ( v5 != nullptr )
    v75 = GASObject::GASObject(this: v5, a2: *((struct GASEnvironment **)this + 17));
  else
    v75 = nullptr;
  v6 = *((_DWORD *)this + 13);
  v7 = *((_DWORD *)this + 17);
  LOBYTE(v67) = 4;
  LODWORD(v68) = v6;
  v76 = 0;
  v8 = v75 + 2;
  HIDWORD(v74) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(v7 + 120) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6040.m_Size,
                   a3: 0xAu,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v74) + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v9 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v9);
  v11 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 12) + 60))(
                                                                                    a1: *((_DWORD *)this + 12),
                                                                                    a2);
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(*((_DWORD *)this + 17) + 120) + 636),
    result: v11);
  v13 = (int)v12;
  ++v12->m_nGrowSize;
  LOBYTE(v69[0]) = 5;
  v69[1] = v12;
  ++v12->m_nGrowSize;
  v14 = *((_DWORD *)this + 17);
  v76 = 0;
  HIDWORD(v74) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(v14 + 120) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029050C,
                   a3: 4u,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v74) + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: v69,
    a5: &v76);
  v15 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v15);
  GASValue::~GASValue(this: v69, a2: (int)v8);
  v10 = (*(_DWORD *)(v13 + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v13);
  v16 = *((_DWORD *)this + 15);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  HIDWORD(v74) = v16;
  LOBYTE(v67) = 3;
  v17 = *((_DWORD *)this + 17);
  v68 = (double)v16;
  v76 = 0;
  HIDWORD(v74) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(v17 + 120) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"color",
                   a3: 5u,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v74) + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v18 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v18);
  *((float *)&v74 + 1) = *((float *)this + 14);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v19 = *((_DWORD *)this + 17);
  v68 = *((float *)&v74 + 1);
  LOBYTE(v67) = 3;
  elem = v8->pNode[1].elem;
  v76 = 0;
  ((void (__thiscall *)(struct GASObject *, int, int, GASValue *, char *))elem)(
    a1: v8,
    a2: v19,
    a3: *(_DWORD *)(v19 + 120) + 516,
    a4: &v67,
    a5: &v76);
  v76 = *((_BYTE *)this + 64);
  GASValue::DropRefs(this: &v67, a2: (int)v8);
  v21 = *((_DWORD *)this + 17);
  LOBYTE(v67) = 2;
  LOBYTE(v68) = v76;
  v76 = 0;
  HIDWORD(v74) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(v21 + 120) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6040,
                   a3: 8u,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v74) + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v22 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v22);
  *((float *)&v74 + 1) = *((float *)this + 1) / 20.0;
  v70 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v23 = *((_DWORD *)this + 17);
  v68 = v70;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v23 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"matrix_a");
  HIDWORD(v74) = v24;
  ++*(_DWORD *)(v24 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v25 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v25);
  *((float *)&v74 + 1) = *((float *)this + 4) / 20.0;
  v70 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v26 = *((_DWORD *)this + 17);
  v68 = v70;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v26 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"matrix_b");
  HIDWORD(v74) = v27;
  ++*(_DWORD *)(v27 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v28 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v28);
  *((float *)&v74 + 1) = *((float *)this + 2) / 20.0;
  v70 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v29 = *((_DWORD *)this + 17);
  v68 = v70;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v29 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"matrix_c");
  HIDWORD(v74) = v30;
  ++*(_DWORD *)(v30 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v31 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v31);
  *((float *)&v74 + 1) = *((float *)this + 5) / 20.0;
  v70 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v32 = *((_DWORD *)this + 17);
  v68 = v70;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v32 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"matrix_d");
  HIDWORD(v74) = v33;
  ++*(_DWORD *)(v33 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v34 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v34);
  *((float *)&v74 + 1) = *((float *)this + 3) / 20.0;
  v70 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v35 = *((_DWORD *)this + 17);
  v68 = v70;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v35 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"matrix_tx");
  HIDWORD(v74) = v36;
  ++*(_DWORD *)(v36 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v37 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v37);
  *((float *)&v74 + 1) = *((float *)this + 6) / 20.0;
  v70 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v38 = *((_DWORD *)this + 17);
  v68 = v70;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v38 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"matrix_ty");
  HIDWORD(v74) = v39;
  ++*(_DWORD *)(v39 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v40 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v40);
  *(float *)&v73 = *((float *)this + 7);
  *((float *)&v73 + 1) = *((float *)this + 10);
  *(float *)&v72 = *((float *)this + 9);
  *((float *)&v72 + 1) = *((float *)this + 10);
  *(float *)&v70 = *((float *)this + 7);
  *((float *)&v70 + 1) = *((float *)this + 8);
  *(float *)&v71 = *((float *)this + 9);
  *((float *)&v71 + 1) = *((float *)this + 8);
  *((float *)&v74 + 1) = *(float *)&v73 / 20.0;
  v74 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v41 = *((_DWORD *)this + 17);
  v68 = v74;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v41 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"corner0x");
  HIDWORD(v74) = v42;
  ++*(_DWORD *)(v42 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v43 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v43);
  *((float *)&v74 + 1) = *((float *)&v73 + 1) / 20.0;
  v73 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v44 = *((_DWORD *)this + 17);
  v68 = v73;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v44 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"corner0y");
  HIDWORD(v74) = v45;
  ++*(_DWORD *)(v45 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v46 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v46);
  *((float *)&v74 + 1) = *(float *)&v72 / 20.0;
  v73 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v47 = *((_DWORD *)this + 17);
  v68 = v73;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v47 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"corner1x");
  HIDWORD(v74) = v48;
  ++*(_DWORD *)(v48 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v49 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v49);
  *((float *)&v74 + 1) = *((float *)&v72 + 1) / 20.0;
  v72 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v50 = *((_DWORD *)this + 17);
  v68 = v72;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v50 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"corner1y");
  HIDWORD(v74) = v51;
  ++*(_DWORD *)(v51 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v52 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v52);
  *((float *)&v74 + 1) = *(float *)&v71 / 20.0;
  v72 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v53 = *((_DWORD *)this + 17);
  v68 = v72;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v53 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"corner2x");
  HIDWORD(v74) = v54;
  ++*(_DWORD *)(v54 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v55 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v55);
  *((float *)&v74 + 1) = *((float *)&v71 + 1) / 20.0;
  v71 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v56 = *((_DWORD *)this + 17);
  v68 = v71;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v56 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"corner2y");
  HIDWORD(v74) = v57;
  ++*(_DWORD *)(v57 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v58 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v58);
  *((float *)&v74 + 1) = *(float *)&v70 / 20.0;
  v71 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v59 = *((_DWORD *)this + 17);
  v68 = v71;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v59 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"corner3x");
  HIDWORD(v74) = v60;
  ++*(_DWORD *)(v60 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *, char *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67,
    a5: &v76);
  v61 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v61);
  *((float *)&v74 + 1) = *((float *)&v70 + 1) / 20.0;
  v70 = *((float *)&v74 + 1);
  if ( (unsigned __int8)v67 >= 5u )
    GASValue::DropRefs(this: &v67, a2: (int)v8);
  v62 = *((_DWORD *)this + 17);
  v68 = v70;
  LOBYTE(v67) = 3;
  v76 = 0;
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(*(_DWORD *)(v62 + 120) + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"corner3y");
  HIDWORD(v74) = v63;
  ++*(_DWORD *)(v63 + 8);
  ((void (__thiscall *)(struct GASObject *, _DWORD, char *, GASValue *))v8->pNode[1].elem)(
    a1: v8,
    a2: *((_DWORD *)this + 17),
    a3: (char *)&v74 + 4,
    a4: &v67);
  v64 = HIDWORD(v74);
  v10 = (*(_DWORD *)(HIDWORD(v74) + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v64);
  v65 = v75;
  v66 = (tagWNDCLASSW *)GASValue::GASValue(this: v69, a2: v75);
  GASArrayObject::PushBack(this: *((GASArrayObject **)this + 18), val: v66);
  GASValue::~GASValue(this: v69, a2: (int)v65);
  GASValue::~GASValue(this: &v67, a2: (int)v65);
  GRefCountBaseGC<323>::Release(a1: (int)v65, a2: (int)v65);
}

//------------------------------------------------------------------------------
// Address: 0x1011D550
// Name: public: static void GASTextSnapshotProto::GetTextRunInfo(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextSnapshotProto::GetTextRunInfo(GMemoryHeap *a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  GASValue *v4; // eax
  int v5; // eax
  GASValue *v6; // eax
  long double v7; // st7
  int v8; // ecx
  int (__thiscall *v9)(int, int, int *); // edx
  int v10; // eax
  CMatRenderContextBase *v11; // edi
  int v12; // ebx
  _SERVICE_STATUS *v13; // [esp-8h] [ebp-6Ch]
  _SERVICE_STATUS *v14; // [esp-8h] [ebp-6Ch]
  const char *v15; // [esp+0h] [ebp-64h]
  int v16; // [esp+4h] [ebp-60h]
  int v17; // [esp+8h] [ebp-5Ch] BYREF
  GPtr<GFxAmpViewStats> *p_cxItem; // [esp+Ch] [ebp-58h]
  unsigned int v19; // [esp+10h] [ebp-54h]
  void **v20; // [esp+14h] [ebp-50h] BYREF
  float v21[18]; // [esp+18h] [ebp-4Ch] BYREF

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x2Bu) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
    {
      p_cxItem = (GPtr<GFxAmpViewStats> *)&v3[-1].cxItem;
      if ( v3 != (GASFnCall)16 && (int)a3[7] >= 2 )
      {
        v13 = (_SERVICE_STATUS *)a3[6];
        v4 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
        v5 = GASValue::ToUInt32(this: v4, a2: (int)a1, a3: a2, a4: v13);
        v14 = (_SERVICE_STATUS *)a3[6];
        v19 = v5;
        v6 = (GASValue *)GASFnCall::Arg(this: a3, a2: 1);
        v16 = GASValue::ToUInt32(this: v6, a2: (int)a1, a3: v7, a4: v14);
        v8 = *(_DWORD *)(a3[6][3].cbSize + 656);
        v9 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v8 + 40);
        v17 = 323;
        v10 = v9(a1: v8, a2: 76, a3: &v17);
        if ( v10 != 0 )
          v11 = (CMatRenderContextBase *)GASArrayObject::GASArrayObject(
                                           a1: v10,
                                           penv: (unsigned int)a3[6],
                                           a3: a1,
                                           a4: v15,
                                           a5: v16);
        else
          v11 = nullptr;
        v12 = (int)a3[6];
        v20 = &GString::InitStruct::`vftable';
        GMatrix2D::SetIdentity(this: v21);
        v21[6] = 0.0;
        v21[7] = 0.0;
        v21[8] = 0.0;
        v21[9] = 0.0;
        v20 = &GASTextSnapshotGlyphVisitor::`vftable';
        LODWORD(v21[16]) = v12;
        LODWORD(v21[17]) = v11;
        GFxStaticTextSnapshotData::Visit(this: p_cxItem + 13, a2: v12, a3: v11, a4: (int *)&v20, start: v19, end: v16);
        GASValue::SetAsObject(this: (GASValue *)a3[1], a2: (struct GASObject *)v11);
        v20 = &GString::InitStruct::`vftable';
        if ( v11 != nullptr )
          GRefCountBaseGC<323>::Release(a1: (int)v11, a2: (int)v11);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "TextSnapshot", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D690
// Name: public: GFxStaticTextSnapshotData::~GFxStaticTextSnapshotData(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxStaticTextSnapshotData::~GFxStaticTextSnapshotData(GPtr<GFxAmpViewStats> *this)
{
  volatile LONG *v2; // esi
  int v3; // eax
  GRefCountNTSImpl **v4; // esi
  int v5; // edi

  v2 = (volatile LONG *)(*(_DWORD *)(this + 3) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = *((_DWORD *)this + 1);
  v4 = (GRefCountNTSImpl **)((char *)this->pObject + 8 * v3 - 8);
  if ( v3 != 0 )
  {
    v5 = *((_DWORD *)this + 1);
    do
    {
      if ( *v4 != nullptr )
        GRefCountNTSImpl::Release(this: *v4);
      v4 -= 2;
      --v5;
    }
    while ( v5 != 0 );
  }
  return ((void *(__thiscall *)(GMemoryHeap *, GFxAmpViewStats *))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: this->pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1011D6F0
// Name: public: GASTextSnapshotObject::GASTextSnapshotObject(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
GASTextSnapshotObject *__thiscall GASTextSnapshotObject::GASTextSnapshotObject(GASTextSnapshotObject *this, struct GASEnvironment *a2)
{
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  GASObject::GASObject((GASObject *)this, a2);
  *(_DWORD *)this = &GASTextSnapshotObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A6058;
  GFxStaticTextSnapshotData::GFxStaticTextSnapshotData(this: (GPtr<GFxAmpViewStats> *)this + 13);
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *((vc_attributes::PreRangeAttribute **)a2 + 30),
                                                    result: (vc_attributes::InvalidCheckAttribute *)0x2B);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)((char *)this + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)a2 + 15,
    psc_4: Prototype);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011D740
// Name: public: virtual enum GASObjectInterface::ObjectType GASTextSnapshotObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASTextSnapshotObject::GetObjectType()
{
  return 43;
}

//------------------------------------------------------------------------------
// Address: 0x1011D8F0
// Name: protected: virtual void GASTextSnapshotObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTextSnapshotObject::Finalize_GC(GFxAmpMessageSwdFile *this)
{
  GFxStaticTextSnapshotData::~GFxStaticTextSnapshotData(this: (GPtr<GFxAmpViewStats> *)this + 13);
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1011D9D0
// Name: public: static class GASFunctionRef GASTextSnapshotCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GASTextSnapshotCtorFunction::Register(unsigned int pgc, int sc)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  const char *v3; // ecx
  int (__thiscall *v4)(const char *, int, int *); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // ebx
  GASCFunctionObject *v7; // eax
  unsigned int v8; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v10)(const char *, int, unsigned int *); // edx
  int v11; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v13; // eax
  int v14; // edi
  GASValue v15[4]; // [esp+Ch] [ebp-20h] BYREF
  vc_attributes::PreRangeAttribute *psc[2]; // [esp+1Ch] [ebp-10h] BYREF
  void (__thiscall **psc_8)(_DWORD *, vc_attributes::PreRangeAttribute **, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *psc_12; // [esp+28h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)sc;
  v3 = *(const char **)(sc + 656);
  psc[0] = (vc_attributes::PreRangeAttribute *)sc;
  LOBYTE(psc[1]) = 8;
  v4 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)v3 + 40);
  sc = 323;
  v5 = (GASCFunctionObject *)v4(a1: v3, a2: 56, a3: &sc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(this: v5, func: (_REASON_CONTEXT *)psc, a3: nullptr);
    v6->dwSize = (unsigned int)&GASSelectionCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  v8 = pgc;
  *(_DWORD *)pgc = v7;
  *(_BYTE *)(v8 + 8) = 0;
  *(_DWORD *)(v8 + 4) = 0;
  MaxVal = v2[54].MaxVal;
  v10 = *(int (__thiscall **)(const char *, int, unsigned int *))(*(_DWORD *)MaxVal + 40);
  pgc = 323;
  v11 = v10(a1: MaxVal, a2: 104, a3: &pgc);
  if ( v11 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASTextSnapshotObject,GASEnvironment>::GASPrototype<GASTextSnapshotObject,GASEnvironment>(
      this: (D3DXQUATERNION *)v11,
      (D3DXQUATERNION *)psc,
      psc_4: Prototype,
      psc_8: v8);
    *(_DWORD *)v11 = &GASTextSnapshotProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v11 + 16) = &GASTextSnapshotProto::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v11 + 72) = &GASTextSnapshotProto::`vftable';
    HIBYTE(sc) = 6;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v11 + 72),
      a2: v11,
      flags: psc,
      flags_4: (const struct GASNameFunction *)&GASTextSnapshotProto::FunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&sc + 3));
  }
  else
  {
    v11 = 0;
  }
  if ( v11 != 0 )
    *(_DWORD *)(v11 + 8) = (*(_DWORD *)(v11 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 43, a4: v11);
  psc_12 = v2[56].MaxVal + 16;
  HIBYTE(sc) = 0;
  psc_8 = (void (__thiscall **)(_DWORD *, vc_attributes::PreRangeAttribute **, int, GASValue *, char *))(*psc_12 + 40);
  v13 = GASValue::GASValue(this: v15, a2: (int)v2, a3: (const struct GASFunctionRef *)v8);
  v14 = (int)&v2[15];
  (*psc_8)(a1: psc_12, a2: psc, a3: v14, a4: v13, a5: (char *)&sc + 3);
  GASValue::~GASValue(this: v15, a2: v14);
  if ( v11 != 0 )
    GRefCountBaseGC<323>::Release(a1: v11, a2: v14);
}

//------------------------------------------------------------------------------
// Address: 0x101EDED9
// Name: protected: long D3DXShader::CProgram::CompactPool_Process(struct D3DXShader::_D3DXCP_DATA __near *,int)
// Source: semantic_flat_class
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CompactPool_Process(
        D3DXShader::CProgram *this,
        struct D3DXShader::_D3DXCP_DATA *a2,
        int a3)
{
  unsigned int i; // ecx
  _DWORD *v6; // eax
  unsigned int v7; // edx
  unsigned int j; // ecx
  _DWORD *v9; // eax
  unsigned int v10; // ecx
  int v11; // edx
  _DWORD *v12; // eax
  int k; // edi
  int v14; // edi
  unsigned int v15; // eax
  int v16; // eax
  _DWORD *v17; // eax
  unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int *v20; // ecx
  unsigned int v21; // eax
  int v22; // edi
  unsigned int v23; // eax
  int (__stdcall *v24)(unsigned int, unsigned int, const void *); // edi
  unsigned int *v25; // ecx
  int v26; // eax
  int v27; // ecx
  unsigned int nn; // eax
  int v29; // eax
  int v30; // eax
  _DWORD *v31; // edi
  unsigned int v32; // eax
  int result; // eax
  int v34; // eax
  int v35; // ecx
  unsigned int v36; // edx
  _DWORD *v37; // ecx
  int v38; // edi
  unsigned int v39; // ecx
  int v40; // edx
  _DWORD *v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  bool v45; // zf
  unsigned int v46; // eax
  _DWORD *v47; // eax
  int v48; // ecx
  unsigned int v49; // [esp-8h] [ebp-30h]
  const void *v50; // [esp+0h] [ebp-28h]
  const void *v51; // [esp+0h] [ebp-28h]
  int v52; // [esp+Ch] [ebp-1Ch]
  unsigned int v53; // [esp+10h] [ebp-18h]
  int v54; // [esp+14h] [ebp-14h]
  int v55; // [esp+14h] [ebp-14h]
  int v56; // [esp+14h] [ebp-14h]
  _DWORD *v57; // [esp+18h] [ebp-10h]
  int m; // [esp+1Ch] [ebp-Ch]
  unsigned int v59; // [esp+1Ch] [ebp-Ch]
  _DWORD *v60; // [esp+1Ch] [ebp-Ch]
  int v61; // [esp+1Ch] [ebp-Ch]
  int v62; // [esp+20h] [ebp-8h]
  int v63; // [esp+20h] [ebp-8h]
  int v64; // [esp+20h] [ebp-8h]
  unsigned int n; // [esp+24h] [ebp-4h]
  unsigned int mm; // [esp+24h] [ebp-4h]
  int v67; // [esp+24h] [ebp-4h]
  struct D3DXShader::_D3DXCP_DATA *v68; // [esp+30h] [ebp+8h]
  struct D3DXShader::_D3DXCP_DATA *v69; // [esp+30h] [ebp+8h]
  unsigned int v70; // [esp+30h] [ebp+8h]
  int v71; // [esp+30h] [ebp+8h]
  struct D3DXShader::_D3DXCP_DATA *v72; // [esp+30h] [ebp+8h]
  struct D3DXShader::_D3DXCP_DATA *v73; // [esp+30h] [ebp+8h]
  struct D3DXShader::_D3DXCP_DATA *v74; // [esp+30h] [ebp+8h]
  struct D3DXShader::_D3DXCP_DATA *i1; // [esp+30h] [ebp+8h]
  int v76; // [esp+34h] [ebp+Ch]
  unsigned int ii; // [esp+34h] [ebp+Ch]
  unsigned int jj; // [esp+34h] [ebp+Ch]
  unsigned int kk; // [esp+34h] [ebp+Ch]
  unsigned int v80; // [esp+34h] [ebp+Ch]
  unsigned int v81; // [esp+34h] [ebp+Ch]
  int v82; // [esp+34h] [ebp+Ch]
  int v83; // [esp+34h] [ebp+Ch]

  *((_DWORD *)this + 47) = a2;
  *((_DWORD *)a2 + 24) ^= (*((_DWORD *)a2 + 24) ^ (2 * a3)) & 2;
  D3DXShader::CProgram::ReadWriteInfo(this);
  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    v6 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * i);
    if ( *(_DWORD *)a2 == v6[1] && v6[14] == -1 )
    {
      v7 = v6[18];
      if ( v6[22] <= v7 )
        v6[22] = v7 + 1;
    }
  }
  memset(*((void **)a2 + 4), 0xFFu, 4 * *((_DWORD *)a2 + 10));
  memset(*((void **)a2 + 5), 0xFFu, 16 * *((_DWORD *)a2 + 10));
  memset(*((void **)a2 + 6), 0xFFu, 16 * *((_DWORD *)a2 + 10));
  for ( j = 0; j < *((_DWORD *)this + 2); ++j )
  {
    v9 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * j);
    v9[12] = -1;
    if ( *(_DWORD *)a2 == v9[1] && v9[14] == -1 )
      *(_DWORD *)(*((_DWORD *)a2 + 6) + 4 * (v9[4] + 4 * v9[3])) = j;
  }
  memset(*((void **)a2 + 2), 0, 4 * *((_DWORD *)a2 + 10));
  v10 = 0;
  if ( *((_DWORD *)a2 + 10) != 0 )
  {
    v68 = nullptr;
    do
    {
      v11 = 0;
      v12 = (_DWORD *)((char *)v68 + *((_DWORD *)a2 + 6));
      for ( k = 4; k != 0; --k )
      {
        if ( *v12 != -1 )
          ++v11;
        ++v12;
      }
      v68 = (struct D3DXShader::_D3DXCP_DATA *)((char *)v68 + 16);
      *(_DWORD *)(*((_DWORD *)a2 + 2) + 4 * v10++) = v11;
    }
    while ( v10 < *((_DWORD *)a2 + 10) );
  }
  v69 = nullptr;
  memset(*((void **)a2 + 3), 0, 4 * *((_DWORD *)a2 + 10));
  if ( *((_DWORD *)this + 3) != 0 )
  {
    do
    {
      v14 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (_DWORD)v69);
      v62 = v14;
      if ( D3DXShader::CInstruction::IsCopy(this: (D3DXShader::CInstruction *)v14) != 0 )
      {
        v76 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v14 + 16));
        if ( *(_DWORD *)a2 == *(_DWORD *)(v76 + 4) )
        {
          for ( m = 2; m != 0; --m )
          {
            v15 = 0;
            for ( n = 0; n < *(_DWORD *)(v14 + 4); v15 = n )
            {
              v16 = *(_DWORD *)(*(_DWORD *)(v14 + 8) + 4 * v15);
              if ( v16 != -1 && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v16) + 56) != -1 )
                v16 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v16) + 56);
              v17 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v16);
              if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v17[1]) + 6) & 2) != 0 )
                v17 = *(_DWORD **)(*((_DWORD *)this + 5)
                                 + 4 * **(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * v17[18]) + 8));
              if ( *(_DWORD *)a2 == v17[1] )
              {
                v18 = (unsigned int *)(*((_DWORD *)a2 + 3) + 4 * v17[3]);
                v19 = *(_DWORD *)(*((_DWORD *)a2 + 2) + 4 * *(_DWORD *)(v76 + 12));
                if ( *v18 < v19 )
                  *v18 = v19;
                v14 = v62;
                v20 = (unsigned int *)(*((_DWORD *)a2 + 3) + 4 * *(_DWORD *)(v76 + 12));
                v21 = *(_DWORD *)(*((_DWORD *)a2 + 2) + 4 * v17[3]);
                if ( *v20 < v21 )
                  *v20 = v21;
              }
              n += *(_DWORD *)(v14 + 12);
            }
          }
        }
      }
      v69 = (struct D3DXShader::_D3DXCP_DATA *)((char *)v69 + 1);
    }
    while ( (unsigned int)v69 < *((_DWORD *)this + 3) );
  }
  v70 = 0;
  memset(*((void **)a2 + 19), 0, 4 * *((_DWORD *)a2 + 18));
  if ( *((_DWORD *)this + 3) != 0 )
  {
    do
    {
      v22 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v70);
      if ( (*(_WORD *)(v22 + 2) & 0xFFF0) != 0 )
      {
        for ( ii = 0; ii < *(_DWORD *)(v22 + 12); ++ii )
          D3DXShader::CProgram::CompactPool_WriteCount(
            this,
            a2,
            a3: *(_DWORD *)(*(_DWORD *)(v22 + 16) + 4 * ii),
            a4: v70);
        for ( jj = 0; jj < *(_DWORD *)(v22 + 4); ++jj )
          D3DXShader::CProgram::CompactPool_ReadCount(this, a2, a3: *(_DWORD *)(*(_DWORD *)(v22 + 8) + 4 * jj), a4: v70);
        if ( D3DXShader::CInstruction::IsSpecial(this: (D3DXShader::CInstruction *)v22) != 0 )
        {
          for ( kk = 0; kk < *(_DWORD *)(v22 + 12); ++kk )
            D3DXShader::CProgram::CompactPool_ReadCount(
              this,
              a2,
              a3: *(_DWORD *)(*(_DWORD *)(v22 + 16) + 4 * kk),
              a4: v70);
        }
      }
      ++v70;
    }
    while ( v70 < *((_DWORD *)this + 3) );
  }
  v23 = 0;
  for ( mm = 0; v23 < *((_DWORD *)a2 + 18); mm = v23 )
  {
    v24 = (int (__stdcall *)(unsigned int, unsigned int, const void *))(*((_DWORD *)a2 + 21)
                                                                      + 4 * *(_DWORD *)(*((_DWORD *)a2 + 20) + 4 * v23));
    v25 = *(unsigned int **)(*((_DWORD *)a2 + 19) + 4 * v23);
    v80 = (unsigned int)v25;
    if ( (unsigned int)v25 > 1 )
    {
      D3DXShader::HeapSort(this: (D3DXShader *)sub_101E1989, a2: v24, a3: v25, a4: (unsigned int)this, a5: v50);
      v26 = 1;
      v71 = 1;
      v59 = 1;
      do
      {
        v54 = *((_DWORD *)v24 + v26);
        if ( sub_101E1910(a1: (int)this, a2: v54, a3: *((_DWORD *)v24 + v71 - 1)) != 0 )
        {
          v27 = v71++;
          *((_DWORD *)v24 + v27) = v54;
        }
        v26 = ++v59;
      }
      while ( v59 < v80 );
      *(_DWORD *)(*((_DWORD *)a2 + 19) + 4 * mm) = v71;
      D3DXShader::HeapSort(
        this: (D3DXShader *)sub_101E1951,
        a2: v24,
        a3: (unsigned int *)v71,
        a4: (unsigned int)this,
        a5: v51);
      v23 = mm;
    }
    ++v23;
  }
  memset(*((void **)a2 + 7), 0xFFu, 16 * *((_DWORD *)a2 + 11));
  for ( nn = 0; nn < *((_DWORD *)a2 + 11); ++nn )
    *(_DWORD *)(*((_DWORD *)a2 + 8) + 4 * nn) = nn;
  v29 = *((_DWORD *)a2 + 11) >> 1;
  *((_DWORD *)a2 + 1) = 0;
  *((_DWORD *)a2 + 9) = v29;
  v30 = *((_DWORD *)this + 3);
  while ( v30 != 0 )
  {
    --v30;
    v31 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v30);
    v55 = v30;
    if ( (*v31 & 0xFFF00000) == 0x20900000 )
    {
      v72 = nullptr;
      if ( v31[3] != 0 )
      {
        do
        {
          *((_DWORD *)a2 + 23) = v31;
          v32 = *(_DWORD *)(v31[2] + 4 * (_DWORD)v72);
          if ( v32 != -1 && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v32) + 56) != -1 )
            v32 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v32) + 56);
          result = D3DXShader::CProgram::CompactPool_Read(this, a2, a3: v32, a4: 0, a5: 0xFFFFFFFF, a6: 0xFFFFFFFF);
          if ( result < 0 )
            return result;
          v34 = *(_DWORD *)(v31[2] + 4 * ((_DWORD)v72 + v31[3]));
          v35 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v34) + 72));
          v36 = *(_DWORD *)(v35 + 12);
          v81 = 0;
          v63 = v35;
          if ( v36 != 0 )
          {
            v37 = *(_DWORD **)(v35 + 16);
            v60 = v37;
            do
            {
              if ( *v37 == v34 )
                break;
              ++v81;
              v37 = ++v60;
            }
            while ( v81 < v36 );
          }
          *((_DWORD *)a2 + 23) = v63;
          v49 = *(_DWORD *)(4 * v81 + *(_DWORD *)(v63 + 8));
          v82 = 4 * v81;
          result = D3DXShader::CProgram::CompactPool_Read(
                     this,
                     a2,
                     a3: *(_DWORD *)(v31[4] + 4 * (_DWORD)v72),
                     a4: 0,
                     a5: v49,
                     a6: 0xFFFFFFFF);
          if ( result < 0 )
            return result;
          result = D3DXShader::CProgram::CompactPool_Read(
                     this,
                     a2,
                     a3: *(_DWORD *)(v82 + *(_DWORD *)(v63 + 8)),
                     a4: 0,
                     a5: *(_DWORD *)(v31[4] + 4 * (_DWORD)v72),
                     a6: 0xFFFFFFFF);
          if ( result < 0 )
            return result;
          v72 = (struct D3DXShader::_D3DXCP_DATA *)((char *)v72 + 1);
        }
        while ( (unsigned int)v72 < v31[3] );
        v30 = v55;
      }
    }
  }
  v64 = 4;
  while ( 1 )
  {
    *((_DWORD *)a2 + 1) = v64;
    v67 = *((_DWORD *)this + 3);
    if ( v67 != 0 )
      break;
LABEL_100:
    if ( --v64 == 0 )
    {
      if ( (*((_BYTE *)a2 + 96) & 2) != 0 )
      {
        for ( i1 = nullptr;
              (unsigned int)i1 < *((_DWORD *)this + 2);
              i1 = (struct D3DXShader::_D3DXCP_DATA *)((char *)i1 + 1) )
        {
          v47 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * (_DWORD)i1);
          if ( *(_DWORD *)a2 == v47[1] )
          {
            v48 = 4 * v47[3];
            v47[4] = *(_DWORD *)(*((_DWORD *)a2 + 5) + 4 * (v48 + v47[4]));
            v47[3] = *(_DWORD *)(v48 + *((_DWORD *)a2 + 4));
          }
        }
      }
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)a2) + 8) = -1;
      return 0;
    }
  }
  while ( 1 )
  {
    --v67;
    v38 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v67);
    *((_DWORD *)a2 + 23) = v38;
    if ( (*(_WORD *)(v38 + 2) & 0xFFF0) == 0 )
      goto LABEL_99;
    v73 = nullptr;
    if ( *(_DWORD *)(v38 + 12) != 0 )
      break;
LABEL_79:
    v39 = *(_DWORD *)v38 & 0xFFFFF;
    v83 = 0;
    v53 = v39;
    v61 = *(_DWORD *)(v38 + 4) / v39;
    if ( *(_DWORD *)(v38 + 4) != 0 )
    {
      while ( 1 )
      {
        v74 = nullptr;
        if ( (*((_BYTE *)this + 112) & 1) != 0 && v61 != 0 )
        {
          v40 = *((_DWORD *)this + 5);
          v52 = v39;
          v41 = *(_DWORD **)(v38 + 8);
          v57 = v41;
          v56 = v61;
          do
          {
            v42 = *v41;
            if ( v42 != -1 && *(_DWORD *)(*(_DWORD *)(v40 + 4 * v42) + 56) != -1 )
              v42 = *(_DWORD *)(*(_DWORD *)(v40 + 4 * v42) + 56);
            v43 = *(_DWORD *)(v40 + 4 * v42);
            if ( *(_DWORD *)a2 == *(_DWORD *)(v43 + 4) )
            {
              v44 = *(_DWORD *)(*((_DWORD *)a2 + 4) + 4 * *(_DWORD *)(v43 + 12));
              if ( v44 != -1 )
              {
                if ( (v44 & 1) != 0 )
                  v74 = (struct D3DXShader::_D3DXCP_DATA *)((char *)v74 - 1);
                else
                  v74 = (struct D3DXShader::_D3DXCP_DATA *)((char *)v74 + 1);
              }
            }
            v41 = &v57[v52];
            v45 = v56-- == 1;
            v57 = (_DWORD *)((char *)v57 + v52 * 4);
          }
          while ( !v45 );
        }
        v46 = *(_DWORD *)(*(_DWORD *)(v38 + 8) + 4 * v83);
        if ( v46 != -1 && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v46) + 56) != -1 )
          v46 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v46) + 56);
        result = D3DXShader::CProgram::CompactPool_Read(this, a2, a3: v46, a4: (int)v74, a5: 0xFFFFFFFF, a6: 0xFFFFFFFF);
        if ( result < 0 )
          return result;
        if ( (unsigned int)++v83 >= *(_DWORD *)(v38 + 4) )
          break;
        v39 = v53;
      }
    }
LABEL_99:
    if ( v67 == 0 )
      goto LABEL_100;
  }
  while ( 1 )
  {
    result = D3DXShader::CProgram::CompactPool_Write(this, a2, a3: *(_DWORD *)(*(_DWORD *)(v38 + 16) + 4 * (_DWORD)v73));
    if ( result < 0 )
      return result;
    v73 = (struct D3DXShader::_D3DXCP_DATA *)((char *)v73 + 1);
    if ( (unsigned int)v73 >= *(_DWORD *)(v38 + 12) )
      goto LABEL_79;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE58C
// Name: protected: long D3DXShader::CProgram::Split(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::Split(D3DXShader::CProgram *this)
{
  int v2; // eax
  int result; // eax
  D3DXShader::CFXLProgram *v4; // eax
  D3DXShader::CProgram *v5; // eax
  unsigned int i; // eax
  struct D3DXShader::CInstruction *v7; // edi
  int v8; // eax
  int v9; // ecx
  unsigned int *v10; // ebx
  unsigned int v11; // eax
  int v12; // ebx
  int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // edi
  unsigned int v20; // ecx
  struct D3DXShader::CArgument *v21; // ebx
  unsigned int v22; // eax
  D3DXShader::CInstruction *v23; // edi
  unsigned int v24; // eax
  D3DXShader::CArgument *v25; // ebx
  int v26; // eax
  unsigned int v27; // [esp+14h] [ebp-38h]
  unsigned int v28; // [esp+18h] [ebp-34h]
  D3DXShader::CArgument *v29; // [esp+18h] [ebp-34h]
  unsigned int *v30; // [esp+1Ch] [ebp-30h]
  unsigned int v31; // [esp+1Ch] [ebp-30h]
  _DWORD *v32; // [esp+20h] [ebp-2Ch]
  unsigned int v33; // [esp+24h] [ebp-28h]
  struct D3DXShader::CArgument *v34; // [esp+24h] [ebp-28h]
  int v35; // [esp+28h] [ebp-24h]
  int v36; // [esp+28h] [ebp-24h]
  unsigned int v37; // [esp+2Ch] [ebp-20h]
  int k; // [esp+30h] [ebp-1Ch]
  D3DXShader::CInstruction *v39; // [esp+30h] [ebp-1Ch]
  unsigned int v40; // [esp+34h] [ebp-18h]
  unsigned int j; // [esp+38h] [ebp-14h]
  unsigned int m; // [esp+38h] [ebp-14h]
  int v43; // [esp+3Ch] [ebp-10h]
  int v44; // [esp+40h] [ebp-Ch]
  unsigned int v45; // [esp+44h] [ebp-8h]
  unsigned int v46; // [esp+48h] [ebp-4h]
  unsigned int v47; // [esp+48h] [ebp-4h]

  v2 = *((_DWORD *)this + 51);
  if ( (v2 & 0x100) != 0 || (v2 & 4) != 0 )
    return 1;
  result = D3DXShader::CProgram::MarkVarying(this);
  if ( result >= 0 )
  {
    v4 = (D3DXShader::CFXLProgram *)MemAlloc_Alloc(nSize: 0x1FCu);
    if ( v4 != nullptr )
      v5 = D3DXShader::CFXLProgram::CFXLProgram(this: v4);
    else
      v5 = nullptr;
    *((_DWORD *)this + 56) = v5;
    if ( v5 != nullptr )
    {
      result = D3DXShader::CProgram::Initialize(this: v5, a2: this, a3: 0x46580201u, a4: *((_DWORD *)this + 51) | 0x100);
      if ( result >= 0 )
      {
        result = D3DXShader::CProgram::StripVarying(this: *((D3DXShader::CProgram **)this + 56));
        if ( result >= 0 )
        {
          result = D3DXShader::CProgram::StripUniform(this);
          if ( result >= 0 )
          {
            for ( i = 0; i < *((_DWORD *)this + 2); ++i )
            {
              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * i) + 48) = -1;
              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * i) + 68) = -1;
            }
            v44 = -1;
            v45 = 0;
            for ( j = 0; j < *((_DWORD *)this + 3); ++j )
            {
              v7 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * j);
              v8 = *(_DWORD *)v7;
              if ( (*(_DWORD *)v7 & 0xFFF00000) != 0 )
              {
                v9 = v8 & 0xFFFFF;
                v33 = v8 & 0xFFFFF;
                v37 = 0;
                v27 = *((_DWORD *)v7 + 1) / (v8 & 0xFFFFFu);
                if ( v27 != 0 )
                {
                  v43 = 0;
                  do
                  {
                    v46 = 0;
                    if ( v9 != 0 )
                    {
                      v10 = (unsigned int *)(v43 + *((_DWORD *)v7 + 2));
                      for ( k = v9; k != 0; --k )
                      {
                        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                                   + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v10) + 4))
                                       + 4)
                            & 2) != 0
                          && D3DXShader::CProgram::IsVarying(this, a2: *v10) == 0 )
                        {
                          ++v46;
                        }
                        ++v10;
                      }
                      if ( v46 != 0 )
                      {
                        if ( v44 == -1 )
                        {
                          v44 = D3DXShader::CBaseProgram::AddPool(
                                  this,
                                  a2: (char *)&stru_102A6BD8.m_Memory.m_nGrowSize,
                                  a3: 0x80251u,
                                  a4: 0xFFFFFFFF,
                                  a5: 4u);
                          if ( v44 == -1 )
                            return -2147024882;
                        }
                        v11 = D3DXShader::CBaseProgram::AddInstruction(
                                this: *((D3DXShader::CBaseProgram **)this + 56),
                                a2: v46 & 0xFFFFF | 0x10000000,
                                a3: v46,
                                a4: v46);
                        if ( v11 == -1 )
                          return -2147024882;
                        v39 = *(D3DXShader::CInstruction **)(*(_DWORD *)(*((_DWORD *)this + 56) + 24) + 4 * v11);
                        D3DXShader::CInstruction::Instance(this: v39, a2: v7);
                        v47 = 0;
                        v40 = 0;
                        v12 = v43;
                        do
                        {
                          v30 = (unsigned int *)(v12 + *((_DWORD *)v7 + 2));
                          v35 = 4 * *v30;
                          v32 = *(_DWORD **)(v35 + *((_DWORD *)this + 5));
                          v28 = *v30;
                          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v32[1]) + 4) & 2) != 0
                            && D3DXShader::CProgram::IsVarying(this, a2: *v30) == 0 )
                          {
                            v13 = v32[18];
                            if ( v13 == -1
                              || (_UNKNOWN *)(**(_DWORD **)(*((_DWORD *)this + 6) + 4 * v13) & 0xFFF00000) != &loc_10100000 )
                            {
                              v14 = v32[12];
                              if ( v14 == -1 )
                              {
                                v15 = D3DXShader::CBaseProgram::AddArgument(
                                        this: *((D3DXShader::CBaseProgram **)this + 56),
                                        a2: *(_DWORD *)(*((_DWORD *)this + 56) + 132),
                                        a3: v45,
                                        a4: v47,
                                        a5: 0.0);
                                v31 = v15;
                                if ( v15 == -1 )
                                  return -2147024882;
                                v16 = 4 * v47;
                                *(_DWORD *)(v16 + *((_DWORD *)v39 + 4)) = v15;
                                *(_DWORD *)(v16 + *((_DWORD *)v39 + 2)) = v28;
                                *(_DWORD *)(v12 + *((_DWORD *)v7 + 2)) = D3DXShader::CBaseProgram::AddArgument(
                                                                           this,
                                                                           a2: v44,
                                                                           a3: v45,
                                                                           a4: v47,
                                                                           a5: 0.0);
                                if ( *(_DWORD *)(v12 + *((_DWORD *)v7 + 2)) == -1 )
                                  return -2147024882;
                                v17 = *((_DWORD *)this + 5);
                                v29 = *(D3DXShader::CArgument **)(v17 + 4 * *(_DWORD *)(v12 + *((_DWORD *)v7 + 2)));
                                D3DXShader::CArgument::Instance(
                                  this: v29,
                                  a2: *(struct D3DXShader::CArgument **)(v35 + v17));
                                *((_DWORD *)v29 + 24) = 0;
                                *((_DWORD *)v29 + 25) = 0;
                                ++v47;
                                *((_DWORD *)v29 + 17) = v31;
                                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v35) + 48) = *(_DWORD *)(v12 + *((_DWORD *)v7 + 2));
                              }
                              else
                              {
                                *v30 = v14;
                              }
                            }
                          }
                          ++v40;
                          v12 += 4;
                        }
                        while ( v40 < v33 );
                        ++v45;
                        *(_DWORD *)v39 = v47 != 0 ? v47 & 0xFFFFF | 0x10000000 : 0;
                        *((_DWORD *)v39 + 3) = v47;
                        *((_DWORD *)v39 + 1) = v47;
                      }
                    }
                    v9 = v33;
                    ++v37;
                    v43 += 4 * v33;
                  }
                  while ( v37 < v27 );
                }
              }
            }
            for ( m = 0; m < *((_DWORD *)this + 2); ++m )
            {
              v18 = *((_DWORD *)this + 5);
              v19 = *(_DWORD *)(v18 + 4 * m);
              v20 = *(_DWORD *)(v19 + 8);
              v36 = v19;
              if ( v20 != -1 )
              {
                v21 = *(struct D3DXShader::CArgument **)(v18 + 4 * v20);
                v34 = v21;
                if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)v21 + 1)) + 4) & 2) != 0
                  && D3DXShader::CProgram::IsVarying(this, a2: v20) == 0 )
                {
                  if ( *((_DWORD *)v21 + 12) == -1 )
                  {
                    if ( v44 == -1 )
                    {
                      v44 = D3DXShader::CBaseProgram::AddPool(
                              this,
                              a2: (char *)&stru_102A6BD8.m_Memory.m_nGrowSize,
                              a3: 0x80251u,
                              a4: 0xFFFFFFFF,
                              a5: 4u);
                      if ( v44 == -1 )
                        return -2147024882;
                    }
                    v22 = D3DXShader::CBaseProgram::AddInstruction(
                            this: *((D3DXShader::CBaseProgram **)this + 56),
                            a2: 0x10000001u,
                            a3: 1u,
                            a4: 1u);
                    if ( v22 == -1 )
                      return -2147024882;
                    v23 = *(D3DXShader::CInstruction **)(*(_DWORD *)(*((_DWORD *)this + 56) + 24) + 4 * v22);
                    D3DXShader::CInstruction::Instance(
                      this: v23,
                      a2: *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v21 + 18)));
                    **((_DWORD **)v23 + 2) = *(_DWORD *)(v36 + 8);
                    **((_DWORD **)v23 + 4) = D3DXShader::CBaseProgram::AddArgument(
                                               this: *((D3DXShader::CBaseProgram **)this + 56),
                                               a2: *(_DWORD *)(*((_DWORD *)this + 56) + 132),
                                               a3: v45,
                                               a4: 0,
                                               a5: 0.0);
                    if ( **((_DWORD **)v23 + 4) == -1 )
                      return -2147024882;
                    v24 = D3DXShader::CBaseProgram::AddArgument(this, a2: v44, a3: v45, a4: 0, a5: 0.0);
                    *((_DWORD *)v21 + 12) = v24;
                    if ( v24 == -1 )
                      return -2147024882;
                    v25 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v24);
                    D3DXShader::CArgument::Instance(this: v25, a2: v34);
                    v26 = **((_DWORD **)v23 + 4);
                    *((_DWORD *)v25 + 24) = 0;
                    *((_DWORD *)v25 + 25) = 0;
                    ++v45;
                    v19 = v36;
                    *((_DWORD *)v25 + 17) = v26;
                    v21 = v34;
                  }
                  *(_DWORD *)(v19 + 8) = *((_DWORD *)v21 + 12);
                }
              }
            }
            result = D3DXShader::CProgram::RemoveDeadCode(this: *((D3DXShader::CProgram **)this + 56));
            if ( result >= 0 )
            {
              result = D3DXShader::CProgram::CompactInstructions(this: *((D3DXShader::CProgram **)this + 56));
              if ( result >= 0 )
              {
                D3DXShader::CProgram::ReadWriteInfo(this: *((D3DXShader::CProgram **)this + 56));
                result = D3DXShader::CProgram::RemoveDeadCode(this);
                if ( result >= 0 )
                {
                  result = D3DXShader::CProgram::CompactInstructions(this);
                  if ( result >= 0 )
                  {
                    result = D3DXShader::CProgram::CompactArguments(this);
                    if ( result >= 0 )
                      return 0;
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
      return -2147024882;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EEA8D
// Name: protected: long D3DXShader::CProgram::Link(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::Link(D3DXShader::CProgram *this)
{
  unsigned int v1; // edx
  int v3; // eax

  v1 = 0;
  if ( *((_DWORD *)this + 56) == 0 )
    return 1;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v3 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v1);
      if ( *(_DWORD *)(v3 + 68) != -1 )
      {
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 56) + 20) + 4 * *(_DWORD *)(v3 + 68)) + 12) = *(_DWORD *)(v3 + 12);
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 56) + 20) + 4 * *(_DWORD *)(v3 + 68)) + 68) = v1;
      }
      ++v1;
    }
    while ( v1 < *((_DWORD *)this + 2) );
  }
  return D3DXShader::CProgram::DeadLinkRemove(this: *((D3DXShader::CProgram **)this + 56));
}

//------------------------------------------------------------------------------
// Address: 0x101EEAE8
// Name: protected: long D3DXShader::CProgram::SimplifyInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::SimplifyInstructions(D3DXShader::CProgram *this)
{
  unsigned int v1; // ebx
  D3DXShader::CProgram *v3; // ecx
  bool v4; // zf
  struct D3DXShader::CInstruction *v5; // esi
  int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // edx
  _DWORD *v9; // ecx
  unsigned int v10; // ecx
  unsigned int v11; // edx
  int v12; // eax
  unsigned int v13; // ebx
  void *v14; // ecx
  int *v15; // ecx
  unsigned int *v16; // edx
  unsigned int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ebx
  unsigned int v21; // ebx
  int result; // eax
  int v23; // eax
  int v24; // ecx
  int v25; // edx
  int v26; // eax
  unsigned int v27; // ecx
  int v28; // edx
  int v29; // eax
  int v30; // ecx
  int v31; // ecx
  int v32; // eax
  _DWORD *v33; // ecx
  unsigned int v34; // edx
  int v35; // eax
  int v36; // ecx
  unsigned int v37; // ebx
  int v38; // eax
  unsigned int v39; // edx
  unsigned int v40; // edx
  unsigned int v41; // ecx
  int *v42; // ecx
  unsigned int *v43; // eax
  int v44; // edx
  int v45; // ecx
  int v46; // ebx
  int v47; // ecx
  int v48; // ebx
  unsigned int v49; // ebx
  int v50; // eax
  int v51; // ecx
  int v52; // edx
  unsigned int v53; // eax
  _DWORD *v54; // ecx
  int v55; // eax
  int v56; // edx
  _DWORD *v57; // ecx
  int v58; // eax
  int v59; // ecx
  _DWORD *v60; // eax
  unsigned int v61; // edx
  int v62; // ecx
  int v63; // eax
  _DWORD *v64; // edx
  unsigned int v65; // eax
  unsigned int j; // ebx
  D3DXShader::CArgument *v67; // ecx
  unsigned int v68; // eax
  int v69; // ecx
  int v70; // edx
  int v71; // eax
  int v72; // edx
  unsigned int v73; // edx
  unsigned int v74; // ecx
  int *v75; // ecx
  unsigned int *v76; // eax
  int v77; // edx
  int v78; // ecx
  int v79; // ebx
  int v80; // ecx
  int v81; // ebx
  unsigned int v82; // ebx
  int v83; // eax
  int v84; // ecx
  int v85; // edx
  unsigned int v87; // eax
  _DWORD *v88; // ecx
  int v89; // eax
  int v90; // edx
  _DWORD *v91; // ecx
  int v92; // eax
  int v93; // ecx
  _DWORD *v94; // eax
  unsigned int v95; // edx
  int v96; // ecx
  int v97; // eax
  _DWORD *v98; // edx
  unsigned int v99; // eax
  unsigned int m; // ebx
  D3DXShader::CArgument *v101; // ecx
  _DWORD *v102; // ecx
  int v103; // eax
  int v104; // ecx
  _DWORD *v105; // eax
  int v106; // ecx
  _DWORD *v107; // eax
  int v108; // ebx
  unsigned int v109; // edx
  int v110; // eax
  int v111; // edx
  unsigned int v112; // ebx
  int v113; // eax
  int v114; // eax
  int v115; // eax
  int v116; // eax
  unsigned int v117; // eax
  int v118; // ecx
  int v119; // eax
  int v120; // ecx
  unsigned int v121; // eax
  int v122; // ecx
  int v123; // eax
  int v124; // edx
  _DWORD *v125; // eax
  _DWORD *v126; // ecx
  unsigned int *v127; // eax
  unsigned int v128; // eax
  int v129; // ecx
  unsigned int n; // ecx
  int v131; // edx
  int v132; // [esp+14h] [ebp-48h]
  int v133; // [esp+18h] [ebp-44h]
  int v134; // [esp+1Ch] [ebp-40h]
  int v135; // [esp+20h] [ebp-3Ch]
  unsigned int v136; // [esp+24h] [ebp-38h]
  unsigned int v137; // [esp+28h] [ebp-34h]
  unsigned int v138; // [esp+2Ch] [ebp-30h]
  unsigned int v139; // [esp+30h] [ebp-2Ch]
  unsigned int v140; // [esp+34h] [ebp-28h]
  unsigned int v141; // [esp+38h] [ebp-24h]
  int v142; // [esp+3Ch] [ebp-20h]
  unsigned int v143; // [esp+40h] [ebp-1Ch]
  int v144; // [esp+44h] [ebp-18h]
  unsigned int v145; // [esp+48h] [ebp-14h]
  int v146; // [esp+4Ch] [ebp-10h]
  unsigned int k; // [esp+50h] [ebp-Ch]
  unsigned int i; // [esp+54h] [ebp-8h]
  unsigned int v149; // [esp+58h] [ebp-4h]

  v1 = 0;
  v149 = 0;
  D3DXShader::CProgram::IdentityRemap(this);
  D3DXShader::CProgram::ReadWriteInfo(this: v3);
  v142 = -1;
  v146 = -1;
  v4 = *((_DWORD *)this + 3) == 0;
  v144 = 0;
  if ( v4 )
    return 1;
  while ( 1 )
  {
    v5 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v144);
    v6 = *(_DWORD *)v5;
    v7 = *(_DWORD *)v5 & 0xFFF00000;
    if ( v7 == 0 )
      goto LABEL_211;
    k = *((_DWORD *)this + 2);
    if ( v7 == 285212672 )
    {
      v8 = 0;
      if ( *((_DWORD *)v5 + 1) != 0 )
      {
        v9 = *((_DWORD **)v5 + 2);
        do
        {
          if ( (**(_BYTE **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v9) + 48))
              & 4) == 0 )
            break;
          ++v8;
          ++v9;
        }
        while ( v8 < *((_DWORD *)v5 + 1) );
      }
      if ( v8 != *((_DWORD *)v5 + 1) )
        goto LABEL_197;
LABEL_194:
      v35 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 3) = 0;
      goto LABEL_195;
    }
    v10 = v6 & 0xF0000000;
    if ( (v6 & 0xF0000000) == 0x10000000 )
    {
      v4 = *((_DWORD *)v5 + 3) == 0;
      i = 0;
      k = 0;
      if ( !v4 )
      {
        do
        {
          v11 = *(_DWORD *)(4 * k + *((_DWORD *)v5 + 4));
          v12 = *((_DWORD *)this + 5);
          v13 = *(_DWORD *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(4 * k + *((_DWORD *)v5 + 2))) + 48);
          v14 = (void *)(*(_DWORD *)v5 & 0xFFF00000);
          v141 = v11;
          v140 = v13;
          if ( v14 == (void *)0x10000000 || v14 == &loc_10100000 )
          {
            v15 = *(int **)(v12 + 4 * v11);
            v16 = *(unsigned int **)(v12 + 4 * v13);
            v17 = *v16;
            v139 = (unsigned int)v15;
            v18 = *v15;
            v19 = (v18 | v17) & 0xE000000;
            v20 = 0x2000000;
            if ( (v19 & 0x2000000) != 0
              || (v20 = 0x4000000, (v19 & 0x4000000) != 0)
              || (v20 = 0x8000000, (v19 & 0x8000000) != 0) )
            {
              v19 = v20;
            }
            if ( v19 != (v18 & 0xE000000) )
            {
              *(_DWORD *)v139 = v19 | v18 & 0xF1FFFFFF;
              v149 = 1;
            }
            v139 = *v16;
            if ( v19 != (v139 & 0xE000000)
              && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v16[1]) + 4) & 2) != 0
              && v16[23] == 1 )
            {
              *v16 = v19 | v139 & 0xF1FFFFFF;
              v149 = 1;
            }
          }
          v21 = v141;
          result = D3DXShader::CProgram::SimplifyUnary(this, a2: v5, a3: v141, a4: v140);
          if ( result < 0 )
            return result;
          v23 = *((_DWORD *)this + 5);
          v24 = v23 + 4 * v21;
          v25 = *(_DWORD *)(*(_DWORD *)v24 + 48);
          if ( v25 == v21 )
          {
            ++i;
          }
          else if ( *(_DWORD *)(*(_DWORD *)(v23 + 4 * v25) + 48) == -1 )
          {
            *(_DWORD *)(*(_DWORD *)(v23 + 4 * *(_DWORD *)(*(_DWORD *)v24 + 48)) + 48) = *(_DWORD *)(*(_DWORD *)v24 + 48);
          }
        }
        while ( ++k < *((_DWORD *)v5 + 3) );
      }
      v26 = *((_DWORD *)v5 + 3);
      if ( i == v26 )
        goto LABEL_197;
      v27 = 0;
      i = 0;
      v149 = 0;
      if ( v26 == 0 )
        goto LABEL_42;
      do
      {
        v28 = *((_DWORD *)v5 + 4);
        v29 = *(_DWORD *)(v28 + 4 * v149);
        v30 = *((_DWORD *)this + 5);
        if ( *(_DWORD *)(*(_DWORD *)(v30 + 4 * v29) + 48) == v29 )
        {
          v31 = 4 * i++;
          *(_DWORD *)(v31 + v28) = v29;
          *(_DWORD *)(v31 + *((_DWORD *)v5 + 2)) = *(_DWORD *)(*((_DWORD *)v5 + 2) + 4 * v149);
        }
        else
        {
          v32 = *(_DWORD *)(v30 + 4 * v29);
          v33 = *(_DWORD **)(v30 + 4 * *(_DWORD *)(v32 + 48));
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v33[1]) + 4) & 2) != 0 && v33[24] == 0 )
          {
            v34 = v149;
            v33[24] = *(_DWORD *)(v32 + 96);
            v33[25] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * v34))
                                + 100);
          }
        }
        ++v149;
      }
      while ( v149 < *((_DWORD *)v5 + 3) );
      v27 = i;
      if ( i != 0 )
        v35 = *(_DWORD *)v5 ^ (i ^ *(_DWORD *)v5) & 0xFFFFF;
      else
LABEL_42:
        v35 = 0;
      *((_DWORD *)v5 + 1) = v27;
      *((_DWORD *)v5 + 3) = v27;
LABEL_195:
      v149 = 1;
LABEL_196:
      *(_DWORD *)v5 = v35;
      goto LABEL_197;
    }
    if ( v10 == 0x20000000 )
    {
      v4 = *((_DWORD *)v5 + 3) == 0;
      v145 = 0;
      i = 0;
      if ( !v4 )
      {
        do
        {
          v36 = *((_DWORD *)v5 + 2);
          v37 = *(_DWORD *)(4 * i + *((_DWORD *)v5 + 4));
          v38 = *((_DWORD *)this + 5);
          v140 = *(_DWORD *)(*(_DWORD *)(v38 + 4 * *(_DWORD *)(4 * i + v36)) + 48);
          v39 = i + *((_DWORD *)v5 + 3);
          v137 = v37;
          v40 = *(_DWORD *)(*(_DWORD *)(v38 + 4 * *(_DWORD *)(v36 + 4 * v39)) + 48);
          v41 = *(_DWORD *)v5 & 0xFFF00000;
          v138 = v40;
          if ( v41 == 0x20000000 || v41 == 537919488 )
          {
            v139 = *(_DWORD *)(v38 + 4 * v37);
            v42 = *(int **)(v38 + 4 * v140);
            v43 = *(unsigned int **)(v38 + 4 * v40);
            v44 = *v42;
            v141 = (unsigned int)v42;
            v45 = (v44 | *v43) & 0xE000000;
            v46 = 0x8000000;
            v4 = ((v44 | *v43) & 0x8000000) == 0;
            v143 = (unsigned int)v43;
            if ( !v4 || (v46 = 0x4000000, (v45 & 0x4000000) != 0) || (v46 = 0x2000000, (v45 & 0x2000000) != 0) )
              v45 = v46;
            v47 = *(_DWORD *)v139 & 0xE000000 | v45;
            v48 = 0x2000000;
            if ( (v47 & 0x2000000) != 0
              || (v48 = 0x4000000, (v47 & 0x4000000) != 0)
              || (v48 = 0x8000000, (v47 & 0x8000000) != 0) )
            {
              v47 = v48;
            }
            if ( v47 != (v44 & 0xE000000) )
            {
              if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v141 + 4)) + 4) & 2) != 0
                && *(_DWORD *)(v141 + 92) == 1 )
              {
                *(_DWORD *)v141 = v47 | v44 & 0xF1FFFFFF;
                v149 = 1;
              }
              v43 = (unsigned int *)v143;
            }
            v139 = *v43;
            if ( v47 != (v139 & 0xE000000)
              && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v43[1]) + 4) & 2) != 0
              && v43[23] == 1 )
            {
              *v43 = v47 | v139 & 0xF1FFFFFF;
              v149 = 1;
            }
          }
          v49 = v137;
          result = D3DXShader::CProgram::SimplifyBinary(this, a2: v5, a3: v137, a4: v140, a5: v138);
          if ( result < 0 )
            return result;
          v50 = *((_DWORD *)this + 5);
          v51 = v50 + 4 * v49;
          v52 = *(_DWORD *)(*(_DWORD *)v51 + 48);
          if ( v52 == v49 )
          {
            ++v145;
          }
          else if ( *(_DWORD *)(*(_DWORD *)(v50 + 4 * v52) + 48) == -1 )
          {
            *(_DWORD *)(*(_DWORD *)(v50 + 4 * *(_DWORD *)(*(_DWORD *)v51 + 48)) + 48) = *(_DWORD *)(*(_DWORD *)v51 + 48);
          }
        }
        while ( ++i < *((_DWORD *)v5 + 3) );
      }
      v53 = *((_DWORD *)v5 + 3);
      if ( v145 == v53 )
        goto LABEL_197;
      if ( v145 == 0 )
      {
        v143 = 1;
        if ( v53 <= 1 )
          goto LABEL_77;
        v54 = *((_DWORD **)v5 + 4);
        v55 = *((_DWORD *)this + 5);
        v56 = *(_DWORD *)(*(_DWORD *)(v55 + 4 * *(_DWORD *)(*(_DWORD *)(v55 + 4 * *v54) + 48)) + 4);
        v57 = v54 + 1;
        while ( v56 == *(_DWORD *)(*(_DWORD *)(v55 + 4 * *(_DWORD *)(*(_DWORD *)(v55 + 4 * *v57) + 48)) + 4) )
        {
          ++v143;
          ++v57;
          if ( v143 >= *((_DWORD *)v5 + 3) )
            goto LABEL_77;
        }
        v53 = *((_DWORD *)v5 + 3);
        if ( v53 == 0 )
        {
LABEL_77:
          for ( i = 0; i < *((_DWORD *)v5 + 3); ++i )
          {
            v58 = *((_DWORD *)this + 5);
            v59 = *(_DWORD *)(v58 + 4 * *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * i));
            v60 = *(_DWORD **)(v58 + 4 * *(_DWORD *)(v59 + 48));
            if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v60[1]) + 4) & 2) != 0 && v60[24] == 0 )
            {
              v61 = i;
              v60[24] = *(_DWORD *)(v59 + 96);
              v60[25] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * v61))
                                  + 100);
            }
          }
          goto LABEL_194;
        }
      }
      v145 = 0;
      if ( v53 != 0 )
      {
        do
        {
          v62 = *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * v145);
          v63 = *((_DWORD *)this + 5);
          v64 = *(_DWORD **)(v63 + 4 * v62);
          v4 = v64[12] == v62;
          v137 = (unsigned int)v64;
          if ( !v4 )
          {
            v65 = *v64 | **(_DWORD **)(v63 + 4 * v64[12]) & 0xF1FFFFFF;
            if ( *v64 != v65 )
            {
              *(_DWORD *)v137 = v65;
              v149 = 1;
            }
            *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v62) + 48) = v62;
          }
          ++v145;
        }
        while ( v145 < *((_DWORD *)v5 + 3) );
      }
      for ( j = k; j < *((_DWORD *)this + 2); ++j )
      {
        v67 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * j);
        if ( v67 != nullptr )
          D3DXShader::CArgument::`scalar deleting destructor'(this: v67, a2: 1);
      }
      v68 = k;
LABEL_144:
      *((_DWORD *)this + 2) = v68;
      goto LABEL_197;
    }
    if ( v10 == 805306368 )
    {
      v4 = *((_DWORD *)v5 + 3) == 0;
      v145 = 0;
      i = 0;
      if ( !v4 )
      {
        do
        {
          v69 = *((_DWORD *)v5 + 2);
          v70 = *(_DWORD *)(v69 + 4 * v1);
          v139 = *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * v1);
          v71 = *((_DWORD *)this + 5);
          v136 = *(_DWORD *)(*(_DWORD *)(v71 + 4 * v70) + 48);
          v72 = *((_DWORD *)v5 + 3);
          v141 = *(_DWORD *)(*(_DWORD *)(v71 + 4 * *(_DWORD *)(v69 + 4 * (v72 + v1))) + 48);
          v73 = *(_DWORD *)(*(_DWORD *)(v71 + 4 * *(_DWORD *)(v69 + 4 * (i + 2 * v72))) + 48);
          v74 = *(_DWORD *)v5 & 0xFFF00000;
          v138 = v73;
          if ( v74 == 805306368 )
          {
            v137 = *(_DWORD *)(v71 + 4 * v139);
            v75 = *(int **)(v71 + 4 * v141);
            v76 = *(unsigned int **)(v71 + 4 * v73);
            v77 = *v75;
            v140 = (unsigned int)v75;
            v78 = (v77 | *v76) & 0xE000000;
            v79 = 0x8000000;
            v4 = ((v77 | *v76) & 0x8000000) == 0;
            v143 = (unsigned int)v76;
            if ( !v4 || (v79 = 0x4000000, (v78 & 0x4000000) != 0) || (v79 = 0x2000000, (v78 & 0x2000000) != 0) )
              v78 = v79;
            v80 = *(_DWORD *)v137 & 0xE000000 | v78;
            v81 = 0x2000000;
            if ( (v80 & 0x2000000) != 0
              || (v81 = 0x4000000, (v80 & 0x4000000) != 0)
              || (v81 = 0x8000000, (v80 & 0x8000000) != 0) )
            {
              v80 = v81;
            }
            if ( v80 != (v77 & 0xE000000) )
            {
              if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v140 + 4)) + 4) & 2) != 0
                && *(_DWORD *)(v140 + 92) == 1 )
              {
                *(_DWORD *)v140 = v80 | v77 & 0xF1FFFFFF;
                v149 = 1;
              }
              v76 = (unsigned int *)v143;
            }
            v137 = *v76;
            if ( v80 != (v137 & 0xE000000)
              && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v76[1]) + 4) & 2) != 0
              && v76[23] == 1 )
            {
              *v76 = v80 | v137 & 0xF1FFFFFF;
              v149 = 1;
            }
          }
          v82 = v139;
          result = D3DXShader::CProgram::SimplifyTernary(this, a2: v5, a3: v139, a4: v136, a5: v141, a6: v138);
          if ( result < 0 )
            return result;
          v83 = *((_DWORD *)this + 5);
          v84 = v83 + 4 * v82;
          v85 = *(_DWORD *)(*(_DWORD *)v84 + 48);
          if ( v85 == v82 )
          {
            ++v145;
          }
          else if ( *(_DWORD *)(*(_DWORD *)(v83 + 4 * v85) + 48) == -1 )
          {
            *(_DWORD *)(*(_DWORD *)(v83 + 4 * *(_DWORD *)(*(_DWORD *)v84 + 48)) + 48) = *(_DWORD *)(*(_DWORD *)v84 + 48);
          }
          v1 = i + 1;
        }
        while ( ++i < *((_DWORD *)v5 + 3) );
      }
      v87 = *((_DWORD *)v5 + 3);
      if ( v145 == v87 )
        goto LABEL_197;
      if ( v145 == 0 )
      {
        v143 = 1;
        if ( v87 <= 1 )
          goto LABEL_127;
        v88 = *((_DWORD **)v5 + 4);
        v89 = *((_DWORD *)this + 5);
        v90 = *(_DWORD *)(*(_DWORD *)(v89 + 4 * *(_DWORD *)(*(_DWORD *)(v89 + 4 * *v88) + 48)) + 4);
        v91 = v88 + 1;
        while ( v90 == *(_DWORD *)(*(_DWORD *)(v89 + 4 * *(_DWORD *)(*(_DWORD *)(v89 + 4 * *v91) + 48)) + 4) )
        {
          ++v143;
          ++v91;
          if ( v143 >= *((_DWORD *)v5 + 3) )
            goto LABEL_127;
        }
        v87 = *((_DWORD *)v5 + 3);
        if ( v87 == 0 )
        {
LABEL_127:
          for ( k = 0; k < *((_DWORD *)v5 + 3); ++k )
          {
            v92 = *((_DWORD *)this + 5);
            v93 = *(_DWORD *)(v92 + 4 * *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * k));
            v94 = *(_DWORD **)(v92 + 4 * *(_DWORD *)(v93 + 48));
            if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v94[1]) + 4) & 2) != 0 && v94[24] == 0 )
            {
              v95 = k;
              v94[24] = *(_DWORD *)(v93 + 96);
              v94[25] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * v95))
                                  + 100);
            }
          }
          goto LABEL_194;
        }
      }
      v145 = 0;
      if ( v87 != 0 )
      {
        do
        {
          v96 = *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * v145);
          v97 = *((_DWORD *)this + 5);
          v98 = *(_DWORD **)(v97 + 4 * v96);
          v4 = v98[12] == v96;
          v136 = (unsigned int)v98;
          if ( !v4 )
          {
            v99 = *v98 | **(_DWORD **)(v97 + 4 * v98[12]) & 0xF1FFFFFF;
            if ( *v98 != v99 )
            {
              *(_DWORD *)v136 = v99;
              v149 = 1;
            }
            *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v96) + 48) = v96;
          }
          ++v145;
        }
        while ( v145 < *((_DWORD *)v5 + 3) );
      }
      v68 = k;
      for ( m = k; m < *((_DWORD *)this + 2); ++m )
      {
        v101 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * m);
        if ( v101 != nullptr )
        {
          D3DXShader::CArgument::`scalar deleting destructor'(this: v101, a2: 1);
          v68 = k;
        }
      }
      goto LABEL_144;
    }
    if ( v7 == 1342177280 )
    {
      result = D3DXShader::CProgram::SimplifyDotProduct(this, a2: v5, a3: 1);
      if ( result < 0 )
        return result;
      if ( result != 1 )
        v149 = 1;
      v102 = *((_DWORD **)v5 + 4);
      v103 = *((_DWORD *)this + 5);
      if ( *(_DWORD *)(*(_DWORD *)(v103 + 4 * *v102) + 48) == *v102 )
        goto LABEL_197;
      v104 = *(_DWORD *)(v103 + 4 * *v102);
      v105 = *(_DWORD **)(v103 + 4 * *(_DWORD *)(v104 + 48));
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v105[1]) + 4) & 2) != 0 && v105[24] == 0 )
      {
        v105[24] = *(_DWORD *)(v104 + 96);
        v105[25] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v5 + 4)) + 100);
      }
      v35 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 3) = 0;
      goto LABEL_196;
    }
    if ( v6 == 1343225860 )
    {
      v106 = *((_DWORD *)this + 5);
      v134 = -1;
      v133 = -1;
      v135 = 1;
      v132 = 1;
      v107 = *((_DWORD **)v5 + 2);
      v108 = *(_DWORD *)(v106 + 4 * *v107);
      v109 = *(_DWORD *)(v106 + 4 * v107[1]);
      v145 = *(_DWORD *)(v106 + 4 * v107[3]);
      v110 = *(_DWORD *)(v108 + 4);
      v143 = v109;
      v111 = *((_DWORD *)this + 4);
      if ( (*(_BYTE *)(*(_DWORD *)(v111 + 4 * v110) + 5) & 1) == 0 || *(_DWORD *)(v108 + 8) != -1 )
      {
        if ( *(_DWORD *)(*(_DWORD *)(v106 + 4 * *(_DWORD *)(*((_DWORD *)v5 + 4) + 4)) + 92) == 0 )
          v133 = 0;
        goto LABEL_171;
      }
      if ( *(double *)(v108 + 32) > 0.0 )
      {
        v4 = (*(_BYTE *)(*(_DWORD *)(v111 + 4 * *(_DWORD *)(v143 + 4)) + 5) & 1) == 0;
        v133 = 2;
        if ( !v4 && *(_DWORD *)(v143 + 8) == -1 )
        {
          if ( *(double *)(v143 + 32) <= 0.0 )
            goto LABEL_168;
          if ( (*(_BYTE *)(*(_DWORD *)(v111 + 4 * *(_DWORD *)(v145 + 4)) + 5) & 1) != 0 && *(_DWORD *)(v145 + 8) == -1 )
          {
            if ( 0.0 == *(double *)(v145 + 32) )
            {
              v134 = 1;
              goto LABEL_175;
            }
            if ( 1.0 == *(double *)(v145 + 32) )
            {
              v134 = 3;
              goto LABEL_175;
            }
          }
        }
LABEL_171:
        if ( *(_DWORD *)(*(_DWORD *)(v106 + 4 * *(_DWORD *)(*((_DWORD *)v5 + 4) + 8)) + 92) == 0 )
          v134 = 0;
        if ( v133 != -1 && v134 != -1 )
          goto LABEL_175;
        goto LABEL_197;
      }
      v133 = 0;
LABEL_168:
      v134 = 0;
LABEL_175:
      v112 = 0;
      while ( 2 )
      {
        v113 = *(int *)((char *)&v132 + v112);
        if ( v113 != 0 )
        {
          v114 = v113 - 1;
          if ( v114 != 0 )
          {
            v115 = v114 - 1;
            if ( v115 != 0 )
            {
              if ( v115 == 1 )
              {
                v116 = *(_DWORD *)(*((_DWORD *)v5 + 2) + 4);
                goto LABEL_181;
              }
            }
            else
            {
              v116 = **((_DWORD **)v5 + 2);
LABEL_181:
              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v112 + *((_DWORD *)v5 + 4))) + 48) = v116;
            }
LABEL_190:
            v123 = *((_DWORD *)this + 5);
            v124 = *((_DWORD *)this + 4);
            v136 = *(_DWORD *)(v123 + 4 * *(_DWORD *)(v112 + *((_DWORD *)v5 + 4)));
            v125 = *(_DWORD **)(v123 + 4 * *(_DWORD *)(v136 + 48));
            if ( (*(_BYTE *)(*(_DWORD *)(v124 + 4 * v125[1]) + 4) & 2) != 0 && v125[24] == 0 )
            {
              v125[24] = *(_DWORD *)(v136 + 96);
              v125[25] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v112 + *((_DWORD *)v5 + 4)))
                                   + 100);
            }
            v112 += 4;
            if ( v112 >= 0x10 )
              goto LABEL_194;
            continue;
          }
          if ( v142 == -1 )
          {
            v117 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 1.0);
            v118 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v117);
            v142 = v117;
            *(_DWORD *)(v118 + 48) = v117;
          }
          v119 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v112 + *((_DWORD *)v5 + 4)));
          v120 = v142;
        }
        else
        {
          if ( v146 == -1 )
          {
            v121 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 0.0);
            v122 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v121);
            v146 = v121;
            *(_DWORD *)(v122 + 48) = v121;
          }
          v119 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v112 + *((_DWORD *)v5 + 4)));
          v120 = v146;
        }
        break;
      }
      *(_DWORD *)(v119 + 48) = v120;
      goto LABEL_190;
    }
LABEL_197:
    if ( *((_DWORD *)v5 + 3) != 0 )
    {
      v145 = 0;
      v126 = *((_DWORD **)v5 + 4);
      do
      {
        v127 = *(unsigned int **)(*((_DWORD *)this + 5) + 4 * *v126);
        v139 = *v127;
        if ( (v139 & 0x40) != 0 )
          break;
        if ( (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v127[1]) + 4) & 0x11028) != 0 )
          break;
        if ( (v139 & 4) == 0 )
          break;
        if ( (v139 & 8) == 0 )
          break;
        ++v145;
        ++v126;
      }
      while ( v145 < *((_DWORD *)v5 + 3) );
      if ( v145 == *((_DWORD *)v5 + 3) )
      {
        v128 = v146;
        if ( v146 == -1 )
        {
          v128 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 0.0);
          v129 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v128);
          v146 = v128;
          *(_DWORD *)(v129 + 48) = v128;
        }
        for ( n = 0; n < *((_DWORD *)v5 + 3); *(_DWORD *)(v131 + 48) = v128 )
          v131 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * n++));
        *(_DWORD *)v5 = 0;
        *((_DWORD *)v5 + 1) = 0;
        *((_DWORD *)v5 + 3) = 0;
        v149 = 1;
      }
    }
LABEL_211:
    if ( (unsigned int)++v144 >= *((_DWORD *)this + 3) )
      break;
    v1 = 0;
  }
  if ( v149 == 0 )
    return 1;
  D3DXShader::CProgram::RemapArguments(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101EF691
// Name: protected: long D3DXShader::CProgram::RemoveDuplicateArguments(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::RemoveDuplicateArguments(D3DXShader::CProgram *this)
{
  unsigned int *v1; // edi
  int (__stdcall *v3)(unsigned int, unsigned int, const void *); // ebx
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int *v8; // edi
  unsigned int v9; // eax
  unsigned int *v10; // edi
  int v11; // ecx
  int v12; // ecx
  unsigned int v13; // edi
  const void *v14; // [esp+0h] [ebp-20h]
  const void *v15; // [esp+0h] [ebp-20h]
  int v16; // [esp+Ch] [ebp-14h]
  unsigned int v17; // [esp+10h] [ebp-10h]
  int v18; // [esp+14h] [ebp-Ch]
  int v19; // [esp+14h] [ebp-Ch]
  unsigned int *v20; // [esp+18h] [ebp-8h]
  unsigned int *v21; // [esp+18h] [ebp-8h]
  int v22; // [esp+1Ch] [ebp-4h]
  unsigned int v23; // [esp+1Ch] [ebp-4h]

  v1 = nullptr;
  v16 = 0;
  D3DXShader::CProgram::ReadWriteInfo(this);
  v3 = (int (__stdcall *)(unsigned int, unsigned int, const void *))MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 2));
  v17 = (unsigned int)v3;
  if ( v3 == nullptr )
    return -2147024882;
  v5 = 0;
  v20 = nullptr;
  v18 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v6 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v5);
      *(_DWORD *)(v6 + 48) = v5;
      v7 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v6 + 4)) + 4);
      if ( (v7 & 0x100) != 0 && (v7 & 0xC00) == 0 )
      {
        *((_DWORD *)v3 + (_DWORD)v1) = v5;
        v1 = (unsigned int *)((char *)v1 + 1);
      }
      ++v5;
    }
    while ( v5 < *((_DWORD *)this + 2) );
    v20 = v1;
  }
  D3DXShader::HeapSort(this: (D3DXShader *)sub_101E15A1, a2: v3, a3: v1, a4: (unsigned int)this, a5: v14);
  v22 = 1;
  if ( (unsigned int)v1 > 1 )
  {
    while ( 1 )
    {
      v8 = (int *)((char *)v3 + 4 * v22);
      if ( sub_101E15A1(
             a1: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(v8 - 1)) + 48),
             a2: *v8,
             a3: (int)this) == 0 )
      {
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v8) + 4) = *((_DWORD *)this + 29);
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v8) + 48) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                                                               + 4 * *(v8 - 1))
                                                                                   + 48);
        v18 = 1;
      }
      if ( ++v22 >= (unsigned int)v20 )
        break;
      v3 = (int (__stdcall *)(unsigned int, unsigned int, const void *))v17;
    }
    if ( v18 != 0 )
    {
      D3DXShader::CProgram::RemapArguments(this);
      v16 = 1;
    }
    v3 = (int (__stdcall *)(unsigned int, unsigned int, const void *))v17;
  }
  v9 = 0;
  v10 = nullptr;
  v21 = nullptr;
  v19 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v11 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v9);
      *(_DWORD *)(v11 + 48) = v9;
      v12 = *(_DWORD *)(v11 + 4);
      if ( *((_DWORD *)this + 29) != v12
        && ((*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v12) + 4) & 0x40) != 0 || *((_DWORD *)this + 55) != 0) )
      {
        *((_DWORD *)v3 + (_DWORD)v10) = v9;
        v10 = (unsigned int *)((char *)v10 + 1);
      }
      ++v9;
    }
    while ( v9 < *((_DWORD *)this + 2) );
    v21 = v10;
  }
  D3DXShader::HeapSort(this: (D3DXShader *)sub_101E15F0, a2: v3, a3: v10, a4: (unsigned int)this, a5: v15);
  if ( v10 != nullptr )
    v17 = *(_DWORD *)v3;
  v23 = 1;
  if ( (unsigned int)v10 > 1 )
  {
    do
    {
      v13 = *((_DWORD *)v3 + v23);
      if ( sub_101E15F0(a1: v17, a2: v13, a3: (int)this) != 0 )
      {
        v17 = v13;
      }
      else
      {
        D3DXShader::CProgram::MergeArguments(this, a2: v17, a3: v13);
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *((_DWORD *)v3 + v23)) + 4) = *((_DWORD *)this + 29);
        v19 = 1;
      }
      ++v23;
    }
    while ( v23 < (unsigned int)v21 );
    if ( v19 != 0 )
    {
      D3DXShader::CProgram::RemapArguments(this);
      v16 = 1;
    }
  }
  free(pMem: v3);
  return v16 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101EF85D
// Name: protected: long D3DXShader::CProgram::SquishInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::SquishInstructions(D3DXShader::CProgram *this)
{
  D3DXShader::CProgram *v1; // esi
  D3DXShader::CInstruction *v2; // ebx
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // esi
  int v15; // edx
  int v16; // edx
  int v17; // edx
  int v18; // esi
  int v19; // edx
  int v20; // edx
  int v21; // edx
  int v22; // esi
  int v23; // edx
  int v24; // edx
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // eax
  int v29; // edx
  int v30; // esi
  int v31; // edx
  int v32; // edx
  int v33; // edx
  int v34; // esi
  int v35; // edx
  int v36; // edx
  int v37; // edx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // edx
  int v42; // esi
  int v43; // edx
  int v44; // edx
  int v45; // edx
  int v46; // esi
  int v47; // edx
  int v48; // edx
  int v49; // edx
  int v50; // edx
  int v51; // edx
  int v52; // esi
  int v53; // eax
  int v54; // eax
  int v55; // edi
  int v56; // eax
  int v57; // edx
  int v58; // ecx
  unsigned int v59; // esi
  int v60; // ecx
  int v61; // eax
  int v62; // ebx
  int v63; // ecx
  unsigned int v64; // edi
  int v65; // edx
  unsigned int v67; // [esp+8h] [ebp-40h]
  int IsSymetric; // [esp+Ch] [ebp-3Ch]
  int v69; // [esp+10h] [ebp-38h]
  int v70; // [esp+14h] [ebp-34h]
  int v71; // [esp+14h] [ebp-34h]
  int v72; // [esp+14h] [ebp-34h]
  int v73; // [esp+14h] [ebp-34h]
  unsigned int i; // [esp+14h] [ebp-34h]
  unsigned int v75; // [esp+18h] [ebp-30h]
  D3DXShader::CInstruction *v77; // [esp+20h] [ebp-28h]
  int v78; // [esp+24h] [ebp-24h]
  int v79; // [esp+28h] [ebp-20h]
  int v80; // [esp+28h] [ebp-20h]
  int v81; // [esp+2Ch] [ebp-1Ch]
  int v82; // [esp+2Ch] [ebp-1Ch]
  unsigned int v83; // [esp+30h] [ebp-18h]
  unsigned int v84; // [esp+34h] [ebp-14h]
  unsigned int v85; // [esp+38h] [ebp-10h]
  int v86; // [esp+3Ch] [ebp-Ch]
  unsigned int v87; // [esp+40h] [ebp-8h]
  unsigned int v88; // [esp+40h] [ebp-8h]
  unsigned int v89; // [esp+44h] [ebp-4h]

  v1 = this;
  v69 = 0;
  D3DXShader::CProgram::IdentityRemap(this);
  v75 = 0;
  if ( *((_DWORD *)v1 + 3) == 0 )
    return 1;
  do
  {
    v2 = *(D3DXShader::CInstruction **)(*((_DWORD *)v1 + 6) + 4 * v75);
    v3 = *(_DWORD *)v2;
    v4 = *(_DWORD *)v2 & 0xF0000000;
    v77 = v2;
    if ( v4 < 0x10000000 )
      goto LABEL_120;
    if ( v4 > 0x40000000 )
      goto LABEL_120;
    v85 = v3 & 0xFFFFF;
    v84 = *((_DWORD *)v2 + 1) / (v3 & 0xFFFFFu);
    IsSymetric = D3DXShader::CInstruction::IsSymetric(this: v2);
    v83 = v85;
    v87 = 1;
    if ( v85 <= 1 )
      goto LABEL_120;
    v78 = 4 * v85;
    v86 = 4;
    v79 = 4 * v85 + 4;
    do
    {
      v5 = *((_DWORD *)v1 + 5);
      v67 = *(_DWORD *)(*((_DWORD *)v2 + 4) + v86);
      if ( (*(_WORD *)(*(_DWORD *)(*((_DWORD *)v1 + 4) + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 4 * v67) + 4)) + 4) & 0x1020) == 0 )
      {
        v89 = 0;
        if ( v86 != 0 )
        {
          v81 = 4 * v85;
          do
          {
            v6 = *(_DWORD *)(*((_DWORD *)v2 + 4) + 4 * v89);
            if ( v6 == -1
              || (*(_WORD *)(*(_DWORD *)(*((_DWORD *)v1 + 4) + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 4 * v6) + 4)) + 4)
                & 0x1020) != 0 )
            {
              goto LABEL_100;
            }
            if ( v84 == 1 )
            {
              v7 = *((_DWORD *)v2 + 2);
              v8 = *(_DWORD *)(v7 + v86);
              v9 = v8 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v8) + 48);
              v10 = *(_DWORD *)(v7 + 4 * v89);
              v11 = v10 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v10) + 48);
              if ( v9 == v11 )
              {
LABEL_102:
                v1 = this;
                D3DXShader::CProgram::MergeArguments(this, a2: *(_DWORD *)(*((_DWORD *)v2 + 4) + 4 * v89), a3: v67);
                --v83;
                *(_DWORD *)(v86 + *((_DWORD *)v2 + 4)) = -1;
                break;
              }
            }
            if ( v84 == 2 )
            {
              v12 = *((_DWORD *)v2 + 2);
              v13 = *(_DWORD *)(v12 + v86);
              if ( v13 == -1 )
                v14 = -1;
              else
                v14 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v13) + 48);
              v15 = *(_DWORD *)(v12 + 4 * v89);
              v70 = v15;
              if ( v15 == -1 )
                v16 = -1;
              else
                v16 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v15) + 48);
              if ( v14 == v16 )
              {
                v17 = *(_DWORD *)(v12 + v79);
                v18 = v17 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v17) + 48);
                v19 = *(_DWORD *)(v12 + v81);
                v20 = v19 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v19) + 48);
                if ( v18 == v20 )
                  goto LABEL_102;
              }
              if ( IsSymetric == 0 )
                goto LABEL_100;
              v21 = *(_DWORD *)(v12 + v86);
              v22 = v21 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v21) + 48);
              v23 = *(_DWORD *)(v12 + v81);
              v24 = v23 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v23) + 48);
              if ( v22 != v24 )
                goto LABEL_100;
              v25 = *(_DWORD *)(v12 + v79);
              if ( v25 == -1 )
                v26 = -1;
              else
                v26 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v25) + 48);
              if ( v70 == -1 )
                v27 = -1;
              else
                v27 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v70) + 48);
              if ( v26 == v27 )
                goto LABEL_102;
            }
            if ( v84 == 3 )
            {
              v28 = *((_DWORD *)v2 + 2);
              v29 = *(_DWORD *)(v28 + v86);
              if ( v29 == -1 )
                v30 = -1;
              else
                v30 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v29) + 48);
              v31 = *(_DWORD *)(v28 + 4 * v89);
              if ( v31 == -1 )
                v32 = -1;
              else
                v32 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v31) + 48);
              if ( v30 != v32 )
                goto LABEL_100;
              v33 = *(_DWORD *)(v28 + v79);
              v34 = v33 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v33) + 48);
              v35 = *(_DWORD *)(v28 + v81);
              v36 = v35 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v35) + 48);
              if ( v34 != v36 )
                goto LABEL_100;
              v37 = *(_DWORD *)(v28 + 4 * (2 * v85 + v87));
              if ( v37 == -1 )
                v71 = -1;
              else
                v71 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v37) + 48);
              v38 = *(_DWORD *)(v28 + 4 * (v89 + 2 * v85));
              if ( v38 == -1 )
                v39 = -1;
              else
                v39 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v38) + 48);
              if ( v71 == v39 )
                goto LABEL_102;
            }
            if ( v84 == 4 )
            {
              v40 = *((_DWORD *)v2 + 2);
              v41 = *(_DWORD *)(v40 + v86);
              v42 = v41 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v41) + 48);
              v43 = *(_DWORD *)(v40 + 4 * v89);
              v44 = v43 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v43) + 48);
              if ( v42 == v44 )
              {
                v45 = *(_DWORD *)(v40 + v79);
                v46 = v45 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v45) + 48);
                v47 = *(_DWORD *)(v40 + v81);
                v48 = v47 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v47) + 48);
                if ( v46 == v48 )
                {
                  v49 = *(_DWORD *)(v40 + 4 * (2 * v85 + v87));
                  v72 = v49 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v49) + 48);
                  v50 = *(_DWORD *)(v40 + 4 * (v89 + 2 * v85));
                  v51 = v50 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v50) + 48);
                  if ( v72 == v51 )
                  {
                    v52 = *(_DWORD *)(v40 + 4 * (3 * v85 + v87));
                    v73 = v52 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v52) + 48);
                    v53 = *(_DWORD *)(v40 + 4 * (v89 + 3 * v85));
                    v54 = v53 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v53) + 48);
                    if ( v73 == v54 )
                      goto LABEL_102;
                  }
                }
              }
            }
LABEL_100:
            ++v89;
            v81 += 4;
            v1 = this;
          }
          while ( v89 < v87 );
        }
      }
      ++v87;
      v79 += 4;
      v86 += 4;
    }
    while ( v87 < v85 );
    if ( v83 < v85 )
    {
      v88 = 0;
      if ( v85 != 0 )
      {
        v55 = 0;
        do
        {
          v56 = *((_DWORD *)v2 + 4);
          v57 = 4 * v88;
          v58 = *(_DWORD *)(v56 + 4 * v88);
          if ( v58 != -1 )
          {
            *(_DWORD *)(v56 + v55) = v58;
            if ( v84 != 0 )
            {
              v59 = v84;
              v60 = v55;
              do
              {
                v61 = *((_DWORD *)v2 + 2);
                v62 = *(_DWORD *)(v61 + v57);
                v57 += v78;
                *(_DWORD *)(v61 + v60) = v62;
                v60 += v78;
                --v59;
                v2 = v77;
              }
              while ( v59 != 0 );
            }
            v55 += 4;
          }
          ++v88;
        }
        while ( v88 < v85 );
      }
      if ( v84 > 1 )
      {
        v63 = 4 * v85;
        v82 = 4 * v85;
        v80 = 4 * v83;
        v64 = v84 - 1;
        do
        {
          if ( v83 != 0 )
          {
            v65 = v80;
            for ( i = v83; i != 0; --i )
            {
              *(_DWORD *)(*((_DWORD *)v2 + 2) + v65) = *(_DWORD *)(*((_DWORD *)v2 + 2) + v63);
              v2 = v77;
              v63 += 4;
              v65 += 4;
            }
          }
          v63 = v78 + v82;
          v80 += 4 * v83;
          --v64;
          v82 += v78;
        }
        while ( v64 != 0 );
      }
      *(_DWORD *)v2 ^= (v83 ^ *(_DWORD *)v2) & 0xFFFFF;
      *((_DWORD *)v2 + 1) = v84 * v83;
      *((_DWORD *)v2 + 3) = v83;
      v69 = 1;
    }
LABEL_120:
    ++v75;
    v1 = this;
  }
  while ( v75 < *((_DWORD *)this + 3) );
  if ( v69 == 0 )
    return 1;
  D3DXShader::CProgram::RemapArguments(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101EFD35
// Name: protected: long D3DXShader::CProgram::RemoveDuplicateInstructions(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXShader::CProgram::RemoveDuplicateInstructions@<eax>(
        D3DXShader::CProgram *this@<ecx>,
        const void *a2@<edi>,
        int a3)
{
  int v4; // esi
  _DWORD *v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // edi
  _DWORD *v8; // eax
  unsigned int *v9; // edx
  unsigned int k; // eax
  unsigned int *v11; // ebx
  unsigned int v12; // edi
  int v13; // eax
  int v14; // ecx
  _DWORD *v15; // eax
  int v16; // edi
  int v17; // edx
  unsigned int v18; // eax
  bool v19; // zf
  int v20; // ecx
  int v21; // eax
  unsigned int v22; // edi
  _DWORD *v23; // eax
  unsigned int *v24; // edx
  const void *v26; // [esp-4h] [ebp-30h]
  unsigned int *v27; // [esp+8h] [ebp-24h]
  unsigned int *j; // [esp+Ch] [ebp-20h]
  unsigned int v29; // [esp+Ch] [ebp-20h]
  unsigned int v30; // [esp+10h] [ebp-1Ch]
  unsigned int v31; // [esp+14h] [ebp-18h]
  int v32; // [esp+18h] [ebp-14h]
  unsigned int v33; // [esp+1Ch] [ebp-10h]
  int (__stdcall *v34)(unsigned int, unsigned int, const void *); // [esp+1Ch] [ebp-10h]
  unsigned int i; // [esp+20h] [ebp-Ch]
  int v36; // [esp+20h] [ebp-Ch]
  int (__stdcall *pMem)(unsigned int, unsigned int, const void *); // [esp+24h] [ebp-8h]
  unsigned int *v38; // [esp+28h] [ebp-4h]
  int v39; // [esp+34h] [ebp+8h]
  unsigned int m; // [esp+34h] [ebp+8h]
  unsigned int v41; // [esp+34h] [ebp+8h]

  v38 = nullptr;
  pMem = (int (__stdcall *)(unsigned int, unsigned int, const void *))MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 3));
  if ( pMem != nullptr )
  {
    v26 = a2;
    for ( i = 0; i < *((_DWORD *)this + 3); ++i )
    {
      v5 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * i);
      v6 = *v5 & 0xFFF00000;
      if ( v6 != 0
        && (a3 == 0 || v5[9] == 0)
        && v6 != 284164096
        && v6 != 544210944
        && v6 != 286261248
        && v6 != 287309824
        && v6 != 288358400
        && v6 != 289406976
        && v6 != 545259520
        && v6 != 546308096
        && v6 != 290455552 )
      {
        v7 = v5[3];
        v33 = 0;
        if ( v7 != 0 )
        {
          v8 = (_DWORD *)v5[4];
          do
          {
            if ( (*(_WORD *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                       + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v8) + 4))
                           + 4)
                & 0x1020) != 0 )
              break;
            ++v33;
            ++v8;
          }
          while ( v33 < v7 );
        }
        if ( v33 >= v7 )
        {
          v9 = v38;
          v38 = (unsigned int *)((char *)v38 + 1);
          *((_DWORD *)pMem + (_DWORD)v9) = i;
        }
      }
    }
    v32 = 0;
    while ( 1 )
    {
      v39 = 0;
      D3DXShader::CProgram::IdentityRemap(this);
      D3DXShader::HeapSort(this: (D3DXShader *)sub_101E61B6, a2: pMem, a3: v38, a4: (unsigned int)this, a5: v26);
      if ( v38 == nullptr )
        break;
      v36 = 1;
      v34 = pMem;
      for ( j = v38; j != nullptr; j = (unsigned int *)((char *)j - 1) )
      {
        v31 = *(_DWORD *)v34;
        if ( *(_DWORD *)v34 != -1 )
        {
          for ( k = v36; ; ++k )
          {
            v30 = k;
            if ( k >= (unsigned int)v38 )
              break;
            v11 = (unsigned int *)((char *)pMem + 4 * k);
            v12 = *v11;
            if ( *v11 != -1 )
            {
              if ( v31 >= v12 || sub_101E6017(a1: v12, a2: this) != 0 )
                break;
              v13 = *((_DWORD *)this + 6);
              v14 = *(_DWORD *)(v13 + 4 * v31);
              v15 = *(_DWORD **)(v13 + 4 * v12);
              for ( m = 0; m < *(_DWORD *)(v14 + 12); *(_DWORD *)(v16 + 48) = v17 )
              {
                v16 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v15[4] + 4 * m));
                v17 = *(_DWORD *)(*(_DWORD *)(v14 + 16) + 4 * m++);
              }
              *v11 = -1;
              *v15 = 0;
              v15[1] = 0;
              v15[3] = 0;
              v32 = 1;
              v39 = 1;
              k = v30;
            }
          }
        }
        v34 = (int (__stdcall *)(unsigned int, unsigned int, const void *))((char *)v34 + 4);
        ++v36;
      }
      v18 = 0;
      if ( v39 == 0 )
        break;
      v19 = v38 == nullptr;
      v27 = v38;
      v38 = nullptr;
      v29 = 0;
      if ( !v19 )
      {
        do
        {
          v20 = *((_DWORD *)pMem + v18);
          if ( v20 != -1 )
          {
            v21 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v20);
            v22 = *(_DWORD *)(v21 + 4);
            v41 = 0;
            if ( v22 != 0 )
            {
              v23 = *(_DWORD **)(v21 + 8);
              do
              {
                if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v23) + 48) != *v23 )
                  break;
                ++v41;
                ++v23;
              }
              while ( v41 < v22 );
            }
            if ( v41 != v22 )
            {
              v24 = v38;
              v38 = (unsigned int *)((char *)v38 + 1);
              *((_DWORD *)pMem + (_DWORD)v24) = v20;
            }
          }
          v18 = ++v29;
        }
        while ( v29 < (unsigned int)v27 );
      }
      D3DXShader::CProgram::RemapArguments(this);
    }
    if ( v32 != 0 )
      D3DXShader::CProgram::RemoveDuplicateArguments(this);
    v4 = v32 == 0;
  }
  else
  {
    v4 = -2147024882;
  }
  free(pMem);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101EFFBC
// Name: protected: long D3DXShader::CProgram::ReorderBinary(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::ReorderBinary(D3DXShader::CProgram *this)
{
  unsigned int v2; // eax
  bool v3; // zf
  _DWORD *v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // edi
  int v10; // ecx
  unsigned int v11; // ecx
  int v12; // edx
  unsigned int v13; // edx
  _DWORD *v14; // ecx
  int v15; // ecx
  D3DXShader::CInstruction *v16; // ebx
  char *v17; // ebx
  int v18; // edx
  _DWORD *v19; // ecx
  int v20; // ebx
  int v21; // ecx
  unsigned int v22; // edx
  int v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // ebx
  unsigned int v26; // ecx
  int v27; // ecx
  _DWORD *v28; // ebx
  unsigned int v29; // ecx
  double v30; // st7
  unsigned int v31; // eax
  int *v32; // eax
  int *v33; // edi
  int v34; // ecx
  _DWORD *v35; // eax
  unsigned int v36; // edi
  unsigned int v37; // eax
  int v38; // ecx
  unsigned int v39; // ebx
  int v40; // ecx
  _DWORD *v41; // eax
  int v42; // ecx
  unsigned int v43; // ecx
  _DWORD *k; // edx
  bool v45; // cf
  _DWORD *v46; // ecx
  unsigned int v47; // edx
  unsigned int v48; // eax
  _DWORD *v49; // edi
  unsigned int v50; // ebx
  int v51; // ecx
  int v52; // ecx
  unsigned int v53; // ebx
  int v54; // edi
  D3DXShader::CInstruction *v55; // eax
  int v56; // edx
  int v57; // eax
  int v58; // edx
  int v59; // ecx
  int v60; // edx
  int v61; // edi
  int v62; // edx
  _DWORD *v63; // eax
  int v64; // eax
  unsigned int v65; // edx
  int v66; // eax
  unsigned int v67; // ebx
  int v68; // eax
  unsigned int v69; // edx
  unsigned int v70; // eax
  int v71; // edx
  int v72; // edx
  unsigned int v73; // eax
  int v74; // edx
  unsigned int v75; // eax
  int v76; // edx
  _DWORD *v77; // edx
  _DWORD *m; // eax
  unsigned int v79; // eax
  int v80; // ebx
  int v81; // eax
  int v82; // edx
  unsigned int v83; // eax
  unsigned int v84; // eax
  struct D3DXShader::CInstruction *v85; // edi
  int v86; // ecx
  _DWORD *v87; // eax
  unsigned int *v88; // eax
  unsigned int v89; // edx
  unsigned int v90; // edx
  int v91; // edx
  int v92; // ebx
  unsigned int *v93; // ecx
  int v94; // edx
  unsigned int v95; // ebx
  unsigned int v96; // edx
  int v97; // eax
  int v98; // ebx
  unsigned int v99; // ecx
  unsigned int v100; // ecx
  unsigned int v101; // edx
  unsigned int v102; // ebx
  unsigned int v103; // eax
  int v104; // ecx
  D3DXShader::CInstruction *v105; // ebx
  unsigned int v106; // ecx
  unsigned int v107; // ecx
  unsigned int v108; // eax
  unsigned int v109; // ecx
  unsigned int v110; // edx
  int v111; // eax
  int v112; // ecx
  unsigned int v113; // edx
  int v114; // eax
  _DWORD *v115; // ecx
  D3DXShader::CInstruction *v116; // eax
  unsigned int v117; // ecx
  unsigned int ii; // eax
  _DWORD *v119; // edx
  D3DXShader::CInstruction *v120; // edx
  int v121; // edi
  int v122; // edx
  unsigned int v123; // eax
  int v124; // edi
  int v125; // ecx
  _DWORD *v126; // eax
  int v127; // eax
  unsigned int v128; // edx
  int v129; // eax
  _DWORD *v130; // edx
  int v131; // ecx
  unsigned int v133; // eax
  int v134; // ebx
  unsigned int v135; // edi
  unsigned int v136; // eax
  double *v137; // eax
  unsigned int *v138; // ecx
  unsigned int v139; // edx
  int v140; // eax
  unsigned int *v141; // edi
  unsigned int v142; // ecx
  _DWORD *v143; // edx
  _DWORD *v144; // eax
  int v145; // edx
  _DWORD *v146; // eax
  int v147; // ecx
  int v148; // eax
  unsigned int kk; // eax
  unsigned int v150; // eax
  _DWORD *v151; // eax
  int v152; // ecx
  int v153; // eax
  unsigned int *v154; // edi
  unsigned int v155; // ecx
  _DWORD *v156; // eax
  int v157; // ecx
  int v158; // eax
  int v159; // eax
  unsigned int v160; // eax
  unsigned int *v161; // ecx
  unsigned int v162; // edi
  unsigned int *v163; // eax
  unsigned int v164; // edx
  unsigned int v165; // ecx
  int v166; // eax
  int v167; // ecx
  int v168; // eax
  unsigned int v169; // edx
  D3DXShader::CInstruction *v170; // ecx
  unsigned int v171; // eax
  unsigned int v172; // edi
  int v173; // ecx
  int v174; // edi
  unsigned int v175; // edi
  unsigned int v176; // eax
  int v177; // edx
  D3DXShader::CInstruction *v178; // edi
  D3DXShader::CInstruction *v179; // eax
  int v180; // edi
  unsigned int v181; // eax
  unsigned int v182; // ecx
  D3DXShader::CInstruction *v183; // eax
  int v184; // edi
  unsigned int v185; // eax
  unsigned int v186; // ecx
  unsigned int v187; // ecx
  int v188; // eax
  D3DXShader::CInstruction *v189; // edi
  unsigned int v190; // edi
  int v191; // eax
  int v192; // eax
  D3DXShader::CInstruction *v193; // edi
  unsigned int v194; // edi
  int v195; // eax
  int v196; // edi
  unsigned int v197; // eax
  unsigned int v198; // eax
  int v199; // eax
  int v200; // ecx
  unsigned int v201; // edx
  unsigned int v202; // eax
  unsigned int jj; // ecx
  int v204; // edx
  __int64 v205; // [esp+0h] [ebp-84h]
  _DWORD v206[4]; // [esp+14h] [ebp-70h]
  _DWORD *v207; // [esp+24h] [ebp-60h]
  _DWORD *v208; // [esp+28h] [ebp-5Ch]
  int *v209; // [esp+2Ch] [ebp-58h]
  _DWORD *v210; // [esp+30h] [ebp-54h]
  double v211; // [esp+34h] [ebp-50h] BYREF
  int v212; // [esp+3Ch] [ebp-48h]
  unsigned int v213; // [esp+40h] [ebp-44h]
  unsigned int v214; // [esp+44h] [ebp-40h] BYREF
  int v215; // [esp+48h] [ebp-3Ch]
  unsigned int v216; // [esp+4Ch] [ebp-38h]
  D3DXShader::CInstruction *v217; // [esp+50h] [ebp-34h] BYREF
  unsigned int v218; // [esp+54h] [ebp-30h] BYREF
  unsigned int v219; // [esp+58h] [ebp-2Ch] BYREF
  unsigned int v220; // [esp+5Ch] [ebp-28h]
  unsigned int *j; // [esp+60h] [ebp-24h]
  unsigned int v222; // [esp+64h] [ebp-20h]
  unsigned int v223; // [esp+68h] [ebp-1Ch] BYREF
  unsigned int v224; // [esp+6Ch] [ebp-18h]
  unsigned int i; // [esp+70h] [ebp-14h] BYREF
  void *pMem; // [esp+74h] [ebp-10h]
  void *v227; // [esp+78h] [ebp-Ch]
  unsigned int n; // [esp+7Ch] [ebp-8h]
  D3DXShader::CInstruction *v229; // [esp+80h] [ebp-4h]

  v216 = -1;
  v224 = -1;
  pMem = nullptr;
  v227 = nullptr;
  v222 = 0;
  D3DXShader::CProgram::ReadWriteInfo(this);
  v2 = 0;
  v3 = *((_DWORD *)this + 2) == 0;
  v229 = nullptr;
  if ( !v3 )
  {
    do
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v2++) + 64) = -1;
    while ( v2 < *((_DWORD *)this + 2) );
  }
  v3 = *((_DWORD *)this + 3) == 0;
  j = nullptr;
  if ( !v3 )
  {
    do
    {
      v4 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * (_DWORD)j);
      v5 = *v4 & 0xFFF00000;
      v220 = (unsigned int)v4;
      if ( v5 != 0 )
      {
        v6 = v4[3];
        if ( (v6 == 0 || (**(_BYTE **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)v4[4]) & 0x40) == 0)
          && (v5 == 541065216 || v5 == 542113792) )
        {
          for ( i = 0; i < v6; ++i )
          {
            v7 = v4[2];
            n = 0;
            v207 = (_DWORD *)(v7 + 4 * i);
            v208 = (_DWORD *)(v7 + 4 * (i + v6));
            do
            {
              v8 = *((_DWORD *)this + 5);
              v206[0] = *(_DWORD *)(v8 + 4 * *v207);
              v9 = 1 - n;
              v206[1] = *(_DWORD *)(v8 + 4 * *v208);
              if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v206[n] + 4)) + 4) & 2) != 0 )
              {
                v10 = v206[n];
                if ( *(_DWORD *)(v10 + 8) == -1 )
                {
                  v11 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v10 + 72));
                  v12 = *v4 ^ *(_DWORD *)v11;
                  v214 = v11;
                  if ( (v12 & 0xFFF00000) == 0 )
                  {
                    v13 = 0;
                    v217 = *(D3DXShader::CInstruction **)(v11 + 12);
                    if ( v217 != nullptr )
                    {
                      v14 = *(_DWORD **)(v11 + 16);
                      do
                      {
                        if ( *v14 == *(&v207)[n] )
                          break;
                        ++v13;
                        ++v14;
                      }
                      while ( v13 < (unsigned int)v217 );
                      v11 = v214;
                    }
                    v15 = *(_DWORD *)(v11 + 8);
                    v219 = 0;
                    v209 = (int *)(v15 + 4 * v13);
                    v16 = v217;
                    v217 = (D3DXShader::CInstruction *)-1;
                    v17 = (char *)v16 + v13;
                    v18 = *v209;
                    v19 = (_DWORD *)(v15 + 4 * (_DWORD)v17);
                    v20 = *(_DWORD *)(v8 + 4 * *v209);
                    v210 = v19;
                    v21 = *v19;
                    v206[3] = *(_DWORD *)(v8 + 4 * v21);
                    v206[2] = v20;
                    v3 = *(_DWORD *)(v206[n] + 92) == 1;
                    v215 = v206[n];
                    if ( v3 && v18 != v21 )
                    {
                      D3DXShader::CProgram::AddSequence(this, a2: *(&v207)[v9], a3: (unsigned int *)&v217, a4: &v211);
                      v214 = (unsigned int)v217;
                      v219 = D3DXShader::CProgram::AddSequence(this, a2: *(&v207)[n], a3: &v214, a4: &v211) >= 0;
                    }
                    v22 = 2;
                    v223 = 2;
                    while ( 1 )
                    {
                      v23 = *((_DWORD *)this + 4);
                      v24 = 5 - v22;
                      v25 = *(_DWORD *)(*(_DWORD *)(v23 + 4 * *(_DWORD *)(v206[v22] + 4)) + 4) & 0x100;
                      v218 = 5 - v22;
                      v214 = v25;
                      if ( v25 != 0
                        && *(_DWORD *)(v206[v22] + 8) == -1
                        && (*(_BYTE *)(*(_DWORD *)(v23 + 4 * *(_DWORD *)(v206[v9] + 4)) + 5) & 1) != 0
                        && *(_DWORD *)(v206[v9] + 8) == -1 )
                      {
                        break;
                      }
                      if ( *(_DWORD *)(v215 + 92) == 1 )
                      {
                        v26 = *(_DWORD *)(v206[v9] + 72);
                        if ( v26 == -1 || v26 < *(_DWORD *)(v215 + 72) )
                        {
                          v27 = v206[v9];
                          if ( *(_DWORD *)(v27 + 8) == -1 )
                          {
                            if ( v214 != 0
                              && *(_DWORD *)(v206[v22] + 8) == -1
                              && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v27 + 4)) + 5) & 1) == 0 )
                            {
                              v32 = (&v207)[v22];
LABEL_48:
                              v33 = (&v207)[v9];
                              v34 = *v33;
                              v4 = (_DWORD *)v220;
                              *v33 = *v32;
                              *v32 = v34;
                              v35 = (_DWORD *)v206[n];
                              v35[24] = 0;
                              v35[25] = 0;
                              v35[16] = -1;
                              goto LABEL_49;
                            }
                            v28 = (&v207)[v24];
                            v213 = (unsigned int)(&v207)[v22];
                            v29 = *(_DWORD *)v213;
                            if ( *v28 != *(_DWORD *)v213 )
                            {
                              if ( v219 == 0 )
                              {
                                v214 = (unsigned int)v217;
                                v3 = D3DXShader::CProgram::AddSequence(this, a2: v29, a3: &v214, a4: &v211) < 0;
                                v24 = v218;
                                if ( !v3 )
                                  goto LABEL_47;
                                v22 = v223;
                              }
                              if ( *(&v207)[v9] == *(_DWORD *)v213 )
                              {
LABEL_47:
                                v32 = (&v207)[v24];
                                goto LABEL_48;
                              }
                            }
                          }
                        }
                      }
                      v223 = ++v22;
                      if ( v22 >= 4 )
                      {
                        v4 = (_DWORD *)v220;
                        goto LABEL_50;
                      }
                    }
                    v4 = (_DWORD *)v220;
                    v30 = 0.0;
                    v31 = *(_DWORD *)v220 & 0xFFF00000;
                    if ( v31 == 541065216 )
                    {
                      v30 = *(double *)(v206[v22] + 32) + *(double *)(v206[v9] + 32);
                    }
                    else if ( v31 == 542113792 )
                    {
                      v30 = *(double *)(v206[v22] + 32) * *(double *)(v206[v9] + 32);
                    }
                    *(&v207)[n] = *(&v207)[v218];
                    *(&v207)[v9] = D3DXShader::CBaseProgram::AddArgument(
                                     this,
                                     a2: *((_DWORD *)this + 30),
                                     a3: 0,
                                     a4: 0,
                                     a5: v30);
LABEL_49:
                    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v4[4] + 4 * i)) + 64) = -1;
                    v229 = (D3DXShader::CInstruction *)1;
                  }
                }
              }
LABEL_50:
              ++n;
            }
            while ( n < 2 );
            v6 = v4[3];
          }
        }
      }
      j = (unsigned int *)((char *)j + 1);
    }
    while ( (unsigned int)j < *((_DWORD *)this + 3) );
    if ( v229 != nullptr )
    {
      v229 = nullptr;
      v222 = 1;
      D3DXShader::CProgram::ReadWriteInfo(this);
    }
  }
  for ( j = nullptr; (unsigned int)j < *((_DWORD *)this + 3); j = (unsigned int *)((char *)j + 1) )
  {
    v36 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (_DWORD)j);
    v37 = *(_DWORD *)v36 & 0xFFF00000;
    v223 = v36;
    if ( v37 != 0 )
    {
      v38 = *(_DWORD *)(v36 + 12);
      if ( (v38 == 0 || (**(_BYTE **)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v36 + 16)) & 0x40) == 0)
        && (v37 == 805306368 || v37 == 285212672) )
      {
        v220 = 0;
        if ( v38 != 0 )
        {
          do
          {
            v39 = *(_DWORD *)(*(_DWORD *)(v36 + 8) + 4 * v220);
            v40 = *((_DWORD *)this + 4);
            v214 = *(_DWORD *)(v36 + 8) + 4 * v220;
            v41 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v39);
            v42 = *(_DWORD *)(v40 + 4 * v41[1]);
            i = v39;
            while ( (*(_BYTE *)(v42 + 4) & 2) != 0 && v41[2] == -1 )
            {
              v43 = *(_DWORD *)(v36 + 12);
              if ( v43 < *(_DWORD *)(v36 + 4) )
              {
                for ( k = (_DWORD *)(*(_DWORD *)(v36 + 8) + 4 * v43); v39 != *k; k = (_DWORD *)v213 )
                {
                  v45 = ++v43 < *(_DWORD *)(v36 + 4);
                  v213 = (unsigned int)(k + 1);
                  if ( !v45 )
                    break;
                }
                if ( v43 < *(_DWORD *)(v36 + 4) )
                  break;
              }
              v46 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v41[18]);
              v47 = v46[3];
              v48 = 0;
              if ( v47 != 0 )
              {
                v49 = (_DWORD *)v46[4];
                do
                {
                  if ( *v49 == v39 )
                    break;
                  ++v48;
                  ++v49;
                }
                while ( v48 < v47 );
                v36 = v223;
              }
              v50 = *v46 & 0xFFF00000;
              if ( v50 == 541065216 )
              {
                v51 = v46[2];
                v39 = *(_DWORD *)(v51 + 4 * v48);
                if ( v39 != *(_DWORD *)(v51 + 4 * (v48 + v47)) )
                  break;
                i = *(_DWORD *)(v51 + 4 * v48);
              }
              else
              {
                if ( v50 != 542113792 )
                  break;
                v52 = v46[2];
                v53 = *(_DWORD *)(v52 + 4 * v48);
                v54 = *((_DWORD *)this + 4);
                v55 = *(D3DXShader::CInstruction **)(v52 + 4 * (v48 + v47));
                v56 = *((_DWORD *)this + 5);
                v217 = v55;
                v57 = *(_DWORD *)(v56 + 4 * v53);
                if ( (*(_BYTE *)(*(_DWORD *)(v54 + 4 * *(_DWORD *)(v57 + 4)) + 5) & 1) != 0
                  && *(double *)(v57 + 32) > 0.0 )
                {
                  i = (unsigned int)v217;
                }
                else
                {
                  v58 = *(_DWORD *)(v56 + 4 * (_DWORD)v217);
                  if ( (*(_BYTE *)(*(_DWORD *)(v54 + 4 * *(_DWORD *)(v58 + 4)) + 5) & 1) == 0
                    || *(double *)(v58 + 32) <= 0.0 )
                  {
                    break;
                  }
                  i = v53;
                }
                v36 = v223;
                v39 = i;
              }
              v41 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v39);
              v42 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v41[1]);
            }
            if ( *(_DWORD *)v214 != i )
            {
              *(_DWORD *)v214 = i;
              v229 = (D3DXShader::CInstruction *)1;
            }
            ++v220;
            v36 = v223;
          }
          while ( v220 < *(_DWORD *)(v223 + 12) );
        }
      }
    }
  }
  if ( v229 != nullptr )
  {
    v229 = nullptr;
    v222 = 1;
    D3DXShader::CProgram::ReadWriteInfo(this);
  }
  v220 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
LABEL_95:
    v59 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v220);
    if ( (*(_DWORD *)v59 & 0xFFF00000) == 0 )
      goto LABEL_150;
    v60 = *(_DWORD *)(v59 + 12);
    if ( v60 != 0 && (**(_BYTE **)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v59 + 16)) & 0x40) != 0 )
      goto LABEL_150;
    if ( (*(_DWORD *)v59 & 0xFFF00000) != 0x30000000 )
      goto LABEL_150;
    v61 = 0;
    v215 = 0;
    if ( v60 == 0 )
      goto LABEL_150;
    while ( 1 )
    {
      v62 = *((_DWORD *)this + 5);
      v213 = *(_DWORD *)(*(_DWORD *)(v59 + 8) + 4 * v61);
      v63 = *(_DWORD **)(v62 + 4 * v213);
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v63[1]) + 4) & 2) == 0 || v63[2] != -1 )
        goto LABEL_149;
      v64 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v63[18]);
      v65 = *(_DWORD *)(v64 + 12);
      v223 = 0;
      if ( v65 != 0 )
      {
        v217 = *(D3DXShader::CInstruction **)(v64 + 16);
        do
        {
          if ( *(_DWORD *)v217 == v213 )
            break;
          ++v223;
          v217 = (D3DXShader::CInstruction *)((char *)v217 + 4);
        }
        while ( v223 < v65 );
      }
      v213 = *(_DWORD *)v64 & 0xFFF00000;
      if ( (_UNKNOWN *)v213 == &loc_10100000 )
      {
        j = (unsigned int *)1;
      }
      else
      {
        if ( v213 != 542113792 )
          goto LABEL_149;
        j = (unsigned int *)2;
      }
      v219 = 0;
      v66 = *(_DWORD *)(v64 + 8);
      v212 = 4 * v65;
      HIDWORD(v211) = -4 * v65;
      v217 = (D3DXShader::CInstruction *)(v66 + 4 * v223);
      v218 = v66 + 4 * (v223 + v65);
      while ( 1 )
      {
        v67 = *(_DWORD *)v217;
        v68 = *((_DWORD *)this + 5);
        v69 = *(_DWORD *)(v68 + 4 * *(_DWORD *)v217);
        n = *(_DWORD *)v217;
        v223 = v69;
        if ( v213 != 542113792
          || (v70 = *(_DWORD *)(v68 + 4 * *(_DWORD *)v218),
              v71 = *(_DWORD *)(v70 + 4),
              v214 = v70,
              (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v71) + 5) & 1) != 0)
          && *(_DWORD *)(v214 + 8) == -1
          && *(double *)(v214 + 32) < 0.0 )
        {
          v72 = *(_DWORD *)(v59 + 8);
          if ( v67 == *(_DWORD *)(v72 + 4 * (v61 + 2 * *(_DWORD *)(v59 + 12))) )
          {
            v73 = *(_DWORD *)(v72 + 4 * (v61 + *(_DWORD *)(v59 + 12)));
            v74 = *((_DWORD *)this + 5);
            i = v73;
            v75 = *(_DWORD *)(v74 + 4 * v73);
            v76 = *(_DWORD *)(v75 + 4);
            v214 = v75;
            if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v76) + 5) & 1) != 0
              && *(_DWORD *)(v214 + 8) == -1
              && *(double *)(v214 + 32) == 0.0 )
            {
              *(_DWORD *)(*(_DWORD *)(v59 + 8) + 4 * v61) = v67;
              *(_DWORD *)(*(_DWORD *)(v59 + 8) + 4 * (v61 + *(_DWORD *)(v59 + 12))) = v67;
              *(_DWORD *)(*(_DWORD *)(v59 + 8) + 4 * (v61 + 2 * *(_DWORD *)(v59 + 12))) = i;
              goto LABEL_148;
            }
          }
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v223 + 4)) + 4) & 2) != 0
            && *(_DWORD *)(v223 + 8) == -1 )
          {
            v77 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v223 + 72));
            if ( (*v77 & 0xFFF00000) == 0x30000000 )
            {
              i = 0;
              if ( v77[3] != 0 )
              {
                for ( m = (_DWORD *)v77[4]; *m != v67; m = (_DWORD *)v214 )
                {
                  ++i;
                  v214 = (unsigned int)(m + 1);
                  if ( i >= v77[3] )
                    break;
                  v67 = n;
                }
              }
              v223 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v77[2] + 4 * (v77[3] + i)));
              v79 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v77[2] + 4 * (i + 2 * v77[3])));
              v3 = (*(_BYTE *)v223 & 8) == 0;
              n = v79;
              if ( v3 )
              {
                if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v223 + 4)) + 5) & 1) == 0
                  || *(_DWORD *)(v223 + 8) != -1
                  || *(double *)(v223 + 32) <= 0.0 )
                {
                  goto LABEL_138;
                }
                v79 = n;
                v223 = 1;
              }
              else
              {
                v223 = 0;
              }
              if ( (*(_BYTE *)v79 & 8) != 0 )
              {
                v217 = nullptr;
                goto LABEL_143;
              }
              if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v79 + 4)) + 5) & 1) != 0
                && *(_DWORD *)(n + 8) == -1
                && *(double *)(n + 32) > 0.0 )
              {
                break;
              }
            }
          }
        }
LABEL_138:
        v217 = (D3DXShader::CInstruction *)((char *)v217 + v212);
        ++v219;
        v218 += HIDWORD(v211);
        if ( v219 >= (unsigned int)j )
          goto LABEL_149;
      }
      v217 = (D3DXShader::CInstruction *)1;
LABEL_143:
      v80 = *(_DWORD *)(v59 + 12);
      v81 = *(_DWORD *)(v59 + 8);
      v82 = v77[2];
      v3 = v223 == 0;
      v219 = *(_DWORD *)(v81 + 4 * (v80 + v61));
      v61 = v215;
      v218 = *(_DWORD *)(v81 + 4 * (v215 + 2 * v80));
      *(_DWORD *)(v81 + 4 * v215) = *(_DWORD *)(v82 + 4 * i);
      v83 = v218;
      if ( v3 )
        v83 = v219;
      v3 = v217 == nullptr;
      *(_DWORD *)(*(_DWORD *)(v59 + 8) + 4 * (v61 + *(_DWORD *)(v59 + 12))) = v83;
      v84 = v218;
      if ( v3 )
        v84 = v219;
      *(_DWORD *)(*(_DWORD *)(v59 + 8) + 4 * (v61 + 2 * *(_DWORD *)(v59 + 12))) = v84;
LABEL_148:
      v229 = (D3DXShader::CInstruction *)1;
LABEL_149:
      v45 = (unsigned int)++v61 < *(_DWORD *)(v59 + 12);
      v215 = v61;
      if ( !v45 )
      {
LABEL_150:
        if ( ++v220 >= *((_DWORD *)this + 3) )
          break;
        goto LABEL_95;
      }
    }
  }
  if ( v229 != nullptr )
  {
    v229 = nullptr;
    v222 = 1;
    D3DXShader::CProgram::ReadWriteInfo(this);
  }
  for ( n = 0; n < *((_DWORD *)this + 3); ++n )
  {
    v85 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * n);
    if ( (*(_DWORD *)v85 & 0xFFF00000) != 0
      && (*((_DWORD *)v85 + 3) == 0 || (**(_BYTE **)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v85 + 4)) & 0x40) == 0)
      && (*(_DWORD *)v85 & 0xFFF00000) == 0x10500000 )
    {
      v219 = -1;
      v214 = -1;
      v3 = *((_DWORD *)v85 + 1) == 0;
      i = 0;
      if ( !v3 )
      {
        do
        {
          v86 = *(_DWORD *)(*((_DWORD *)v85 + 2) + 4 * i);
          v87 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v86);
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v87[1]) + 4) & 2) != 0 && v87[2] == -1 )
          {
            v88 = *(unsigned int **)(*((_DWORD *)this + 6) + 4 * v87[18]);
            v89 = *v88 & 0xFFF00000;
            j = v88;
            if ( v89 == 542113792 )
            {
              v90 = v88[3];
              v223 = 0;
              if ( v90 != 0 )
              {
                v217 = (D3DXShader::CInstruction *)v88[4];
                do
                {
                  if ( *(_DWORD *)v217 == v86 )
                    break;
                  ++v223;
                  v217 = (D3DXShader::CInstruction *)((char *)v217 + 4);
                }
                while ( v223 < v90 );
              }
              v220 = 0;
              v218 = 1;
              do
              {
                v91 = *((_DWORD *)this + 5);
                v92 = *((_DWORD *)this + 4);
                HIDWORD(v211) = *(_DWORD *)(v88[2] + 4 * (v223 + v220 * v88[3]));
                v93 = *(unsigned int **)(v91 + 4 * HIDWORD(v211));
                if ( (*(_BYTE *)(*(_DWORD *)(v92 + 4 * v93[1]) + 4) & 2) != 0 && v93[2] == -1 )
                {
                  v94 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v93[18]);
                  v95 = *(_DWORD *)v94 & 0xFFF00000;
                  v215 = v94;
                  if ( v95 == 274726912 )
                  {
                    if ( v93[23] == 1 )
                    {
                      v96 = *v93;
                      v97 = (*v93 | **(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v85 + 4) + 4 * i)))
                          & 0xE000000;
                      v98 = 0x8000000;
                      if ( ((*v93 | **(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v85 + 4) + 4 * i)))
                          & 0x8000000) != 0
                        || (v98 = 0x4000000,
                            ((*v93 | **(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v85 + 4) + 4 * i)))
                           & 0x4000000) != 0)
                        || (v98 = 0x2000000,
                            ((*v93 | **(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v85 + 4) + 4 * i)))
                           & 0x2000000) != 0) )
                      {
                        v97 = v98;
                      }
                      if ( (v96 & 0xE000000) != v97 )
                      {
                        *v93 = v97 | v96 & 0xF1FFFFFF;
                        v229 = (D3DXShader::CInstruction *)1;
                      }
                      v94 = v215;
                      v88 = j;
                    }
                    if ( (*((_BYTE *)this + 108) & 0x40) != 0
                      && *((_DWORD *)v85 + 3) == 1
                      && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v85 + 4) + 4 * i))
                                   + 3)
                        & 2) != 0 )
                    {
                      v99 = 0;
                      if ( *(_DWORD *)(v94 + 12) != 0 )
                      {
                        v217 = *(D3DXShader::CInstruction **)(v94 + 16);
                        do
                        {
                          if ( *(_DWORD *)v217 == HIDWORD(v211) )
                            break;
                          v217 = (D3DXShader::CInstruction *)((char *)v217 + 4);
                          ++v99;
                        }
                        while ( v99 < *(_DWORD *)(v94 + 12) );
                      }
                      v100 = *(_DWORD *)(*(_DWORD *)(v94 + 8) + 4 * v99);
                      v101 = v88[2];
                      v219 = v100;
                      v214 = *(_DWORD *)(v101 + 4 * (v223 + v218 * v88[3]));
                    }
                  }
                }
                ++v220;
                --v218;
              }
              while ( v220 < 2 );
            }
          }
          ++i;
        }
        while ( i < *((_DWORD *)v85 + 1) );
        if ( v219 != -1 )
        {
          v102 = D3DXShader::CBaseProgram::AddInstruction(this, a2: 0x50100004u, a3: 0xFFFFFFFF, a4: 0xFFFFFFFF);
          if ( v102 == -1 )
            return -2147024882;
          v103 = D3DXShader::CBaseProgram::AddInstruction(this, a2: 0x10000001u, a3: 0xFFFFFFFF, a4: 0xFFFFFFFF);
          if ( v103 == -1 )
            return -2147024882;
          v104 = *((_DWORD *)this + 6);
          v105 = *(D3DXShader::CInstruction **)(v104 + 4 * v102);
          v217 = *(D3DXShader::CInstruction **)(v104 + 4 * v103);
          D3DXShader::CInstruction::Instance(this: v105, a2: v85);
          D3DXShader::CInstruction::Instance(this: v217, a2: v85);
          v106 = v219;
          i = 0;
          *(_DWORD *)(*((_DWORD *)v105 + 2) + 4) = v219;
          **((_DWORD **)v105 + 2) = v106;
          v107 = v214;
          *(_DWORD *)(*((_DWORD *)v105 + 2) + 12) = v214;
          *(_DWORD *)(*((_DWORD *)v105 + 2) + 8) = v107;
          do
          {
            v108 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: 0, a5: 0.0);
            v109 = i;
            *(_DWORD *)(i + *((_DWORD *)v105 + 4)) = v108;
            if ( *(_DWORD *)(v109 + *((_DWORD *)v105 + 4)) == -1 )
              return -2147024882;
            v110 = i;
            *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(i + *((_DWORD *)v105 + 4))) + 20) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v85 + 4)) + 20);
            v111 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v110 + *((_DWORD *)v105 + 4)));
            v112 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v85 + 4)) + 24);
            v113 = i;
            i += 4;
            *(_DWORD *)(v111 + 24) = v112;
            v114 = *((_DWORD *)this + 5);
            v115 = *(_DWORD **)(v114 + 4 * *(_DWORD *)(v113 + *((_DWORD *)v105 + 4)));
            *v115 |= **(_DWORD **)(v114 + 4 * **((_DWORD **)v85 + 4)) & 0xE000000;
          }
          while ( i < 0x10 );
          v116 = v217;
          **((_DWORD **)v217 + 2) = *(_DWORD *)(*((_DWORD *)v105 + 4) + 8);
          **((_DWORD **)v116 + 4) = **((_DWORD **)v85 + 4);
          D3DXShader::CInstruction::`scalar deleting destructor'(this: v85, a2: 1);
          v117 = --*((_DWORD *)this + 3) - 1;
          for ( ii = n; v117 > ii; *v119 = *(v119 - 1) )
            v119 = (_DWORD *)(*((_DWORD *)this + 6) + 4 * v117--);
          v120 = v217;
          *(_DWORD *)(*((_DWORD *)this + 6) + 4 * ii) = v105;
          *(_DWORD *)(*((_DWORD *)this + 6) + 4 * ii + 4) = v120;
          D3DXShader::CProgram::ReadWriteInfo(this);
          v229 = (D3DXShader::CInstruction *)1;
        }
      }
    }
  }
  if ( v229 != nullptr )
  {
    v229 = nullptr;
    v222 = 1;
    D3DXShader::CProgram::ReadWriteInfo(this);
  }
  v121 = 0;
  v3 = *((_DWORD *)this + 3) == 0;
  i = 0;
  if ( !v3 )
  {
    do
    {
      v122 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * i);
      v123 = *(_DWORD *)v122 & 0xFFF00000;
      v215 = v122;
      if ( v123 != 0
        && (*(_DWORD *)(v122 + 12) == 0
         || (**(_BYTE **)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v122 + 16)) & 0x40) == 0)
        && v123 == 272629760 )
      {
        v3 = *(_DWORD *)(v122 + 4) == 0;
        j = nullptr;
        if ( !v3 )
        {
          do
          {
            v124 = *((_DWORD *)this + 4);
            v125 = *(_DWORD *)(*(_DWORD *)(v122 + 8) + 4 * (_DWORD)j);
            HIDWORD(v211) = *(_DWORD *)(v122 + 8) + 4 * (_DWORD)j;
            v126 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v125);
            if ( (*(_BYTE *)(*(_DWORD *)(v124 + 4 * v126[1]) + 4) & 2) != 0 && v126[2] == -1 )
            {
              v127 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v126[18]);
              if ( (*(_DWORD *)v127 & 0xFFF00000) == 0x20400000 )
              {
                v128 = *(_DWORD *)(v127 + 12);
                v223 = 0;
                v214 = v128;
                if ( v128 != 0 )
                {
                  v217 = *(D3DXShader::CInstruction **)(v127 + 16);
                  do
                  {
                    if ( *(_DWORD *)v217 == v125 )
                      break;
                    ++v223;
                    v217 = (D3DXShader::CInstruction *)((char *)v217 + 4);
                  }
                  while ( v223 < v128 );
                }
                v129 = *(_DWORD *)(v127 + 8);
                v220 = 0;
                v130 = (_DWORD *)(v129 + 4 * v223);
                while ( 1 )
                {
                  v131 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v130);
                  if ( (*(_BYTE *)(*(_DWORD *)(v124 + 4 * *(_DWORD *)(v131 + 4)) + 5) & 1) != 0
                    && (*(_BYTE *)v131 & 2) != 0
                    && *(_DWORD *)(v131 + 8) == -1 )
                  {
                    break;
                  }
                  ++v220;
                  v130 += v214;
                  if ( v220 >= 2 )
                    goto LABEL_221;
                }
                v229 = (D3DXShader::CInstruction *)1;
                *(_DWORD *)HIDWORD(v211) = *(_DWORD *)(v129 + 4 * (v223 + v214 * (1 - v220)));
LABEL_221:
                v122 = v215;
              }
            }
            j = (unsigned int *)((char *)j + 1);
          }
          while ( (unsigned int)j < *(_DWORD *)(v122 + 4) );
          v121 = 0;
        }
      }
      ++i;
    }
    while ( i < *((_DWORD *)this + 3) );
  }
  if ( v229 == nullptr && v222 == 0 )
  {
    v133 = *((_DWORD *)this + 3);
    v222 = 0;
    v220 = v133;
    if ( v133 != 0 )
    {
      while ( 1 )
      {
        --v220;
        v134 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v220);
        v218 = *(_DWORD *)(v134 + 12);
        v135 = v218;
        if ( v218 == 0 || (**(_BYTE **)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v134 + 16)) & 0x40) == 0 )
          break;
LABEL_376:
        if ( v220 == 0 )
        {
          if ( v229 != nullptr )
            goto LABEL_381;
          goto LABEL_378;
        }
      }
      v136 = *(_DWORD *)v134 & 0xFFF00000;
      if ( v136 != 541065216 && v136 != 542113792 )
        goto LABEL_303;
      if ( v218 > v222 )
      {
        v222 = v218;
        if ( v218 <= 0x10 )
          v222 = 16;
        free(pMem);
        pMem = MemAlloc_Alloc(nSize: 4 * v222);
        if ( pMem == nullptr )
          goto LABEL_383;
        free(pMem: v227);
        v227 = MemAlloc_Alloc(nSize: 8 * v222);
        if ( v227 == nullptr )
          goto LABEL_383;
      }
      i = 0;
      if ( v135 != 0 )
      {
        j = (unsigned int *)pMem;
        v217 = (D3DXShader::CInstruction *)v227;
        do
        {
          v137 = (double *)v217;
          v138 = j;
          *j = -1;
          *v137 = 1.0;
          if ( D3DXShader::CProgram::AddSequence(
                 this,
                 a2: *(_DWORD *)(*(_DWORD *)(v134 + 16) + 4 * i),
                 a3: v138,
                 a4: v137) < 0 )
            break;
          if ( *j == *(_DWORD *)(*(_DWORD *)(v134 + 16) + 4 * i) )
            break;
          ++i;
          v217 = (D3DXShader::CInstruction *)((char *)v217 + 8);
          ++j;
        }
        while ( i < v135 );
      }
      if ( i != v135 )
      {
LABEL_303:
        if ( (*(_DWORD *)v134 & 0xFFF00000) == 0x20500000 )
        {
          v162 = 0;
          n = *(_DWORD *)(v134 + 12);
          j = nullptr;
          v217 = nullptr;
          if ( n != 0 )
          {
            do
            {
              i = -1;
              v223 = -1;
              v218 = -1;
              v219 = -1;
              v163 = (unsigned int *)((char *)pMem + 4 * v162);
              *v163 = -1;
              HIDWORD(v205) = &v219;
              LODWORD(v205) = &v218;
              if ( D3DXShader::CProgram::RangeSequence(
                     this,
                     a2: *(_DWORD *)(*(_DWORD *)(v134 + 16) + 4 * v162),
                     a3: v163,
                     a4: &i,
                     a5: &v223,
                     a6: v205) < 0 )
                break;
              if ( i != -1 && v223 != -1 )
              {
                if ( *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * i) + 32) < *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v223)
                                                                                              + 32) )
                  i = -1;
                else
                  v223 = -1;
              }
              v164 = v219;
              v165 = v218;
              if ( v219 == -1 )
                goto LABEL_318;
              if ( v218 != -1 )
              {
                if ( *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v219) + 32) > *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v218)
                                                                                                 + 32) )
                {
                  v164 = -1;
                  v219 = -1;
                }
                else
                {
                  v164 = v219;
                  v165 = -1;
                  v218 = -1;
                }
              }
              if ( v164 == -1 )
              {
LABEL_318:
                if ( v165 == -1 && i != -1 )
                {
                  v166 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i);
                  v167 = 1;
                  goto LABEL_330;
                }
                if ( v164 == -1 && v165 == -1 && v223 != -1 )
                {
                  *((double *)v227 + v162) = *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v223) + 32);
                  v168 = 540016640;
                  v167 = 0;
                  goto LABEL_331;
                }
              }
              if ( i != -1 || v223 != -1 )
                break;
              if ( v165 != -1 )
              {
                *((double *)v227 + v162) = *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v165) + 32);
                v168 = 540016640;
                v167 = 1;
                goto LABEL_331;
              }
              if ( v164 == -1 )
                break;
              v166 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v164);
              v167 = 0;
LABEL_330:
              *((double *)v227 + v162) = *(double *)(v166 + 32);
              v168 = 538968064;
LABEL_331:
              if ( v162 != 0 )
              {
                if ( (unsigned int *)v168 != j || (D3DXShader::CInstruction *)v167 != v217 )
                  break;
              }
              else
              {
                j = (unsigned int *)v168;
                v217 = (D3DXShader::CInstruction *)v167;
              }
              ++v162;
            }
            while ( v162 < n );
          }
          v169 = n;
          if ( v162 == n )
          {
            if ( *((char *)this + 108) < 0 )
            {
              v175 = n & 0xFFFFF;
              v214 = D3DXShader::CBaseProgram::AddInstruction(
                       this,
                       a2: (unsigned int)&loc_10100000 | n & 0xFFFFF,
                       a3: n,
                       a4: n);
              HIDWORD(v211) = D3DXShader::CBaseProgram::AddInstruction(this, a2: v175 | 0x20400000, a3: 2 * n, a4: n);
              v176 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v175 | 0x30000000, a3: 3 * n, a4: n);
              if ( v214 == -1 || HIDWORD(v211) == -1 || v176 == -1 )
                goto LABEL_383;
              v177 = *((_DWORD *)this + 6);
              v178 = *(D3DXShader::CInstruction **)(v177 + 4 * HIDWORD(v211));
              v179 = *(D3DXShader::CInstruction **)(v177 + 4 * v176);
              v223 = *(_DWORD *)(v177 + 4 * v214);
              i = (unsigned int)v178;
              v229 = v179;
              D3DXShader::CInstruction::Instance(
                this: (D3DXShader::CInstruction *)v223,
                a2: (struct D3DXShader::CInstruction *)v134);
              D3DXShader::CInstruction::Instance(this: v178, a2: (struct D3DXShader::CInstruction *)v134);
              D3DXShader::CInstruction::Instance(this: v229, a2: (struct D3DXShader::CInstruction *)v134);
              v3 = v217 == nullptr;
              v217 = nullptr;
              if ( v3 )
              {
                if ( n != 0 )
                {
                  do
                  {
                    v180 = 4 * (_DWORD)v217;
                    v181 = D3DXShader::CBaseProgram::AddArgument(
                             this,
                             a2: *((_DWORD *)this + 30),
                             a3: 0,
                             a4: 0,
                             a5: *((double *)v227 + (unsigned int)v217));
                    v182 = v223;
                    *(_DWORD *)(v180 + *(_DWORD *)(v223 + 8)) = v181;
                    *(_DWORD *)(v180 + *(_DWORD *)(i + 8)) = *(_DWORD *)((char *)pMem + v180);
                    if ( *(_DWORD *)(v180 + *(_DWORD *)(v182 + 8)) == -1 )
                      goto LABEL_383;
                    v217 = (D3DXShader::CInstruction *)((char *)v217 + 1);
                  }
                  while ( (unsigned int)v217 < n );
                }
              }
              else if ( n != 0 )
              {
                do
                {
                  v183 = v217;
                  v184 = 4 * (_DWORD)v217;
                  *(_DWORD *)(4 * (_DWORD)v217 + *(_DWORD *)(v223 + 8)) = *((_DWORD *)pMem + (_DWORD)v217);
                  v185 = D3DXShader::CBaseProgram::AddArgument(
                           this,
                           a2: *((_DWORD *)this + 30),
                           a3: 0,
                           a4: 0,
                           a5: *((double *)v227 + (unsigned int)v183));
                  v186 = i;
                  *(_DWORD *)(v184 + *(_DWORD *)(i + 8)) = v185;
                  if ( *(_DWORD *)(v184 + *(_DWORD *)(v186 + 8)) == -1 )
                    goto LABEL_383;
                  v217 = (D3DXShader::CInstruction *)((char *)v217 + 1);
                }
                while ( (unsigned int)v217 < n );
              }
              if ( v216 == -1 )
              {
                v216 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 1.0);
                if ( v216 == -1 )
                  goto LABEL_383;
              }
              if ( v224 == -1 )
              {
                v224 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 0.0);
                if ( v224 == -1 )
                  goto LABEL_383;
              }
              v187 = n;
              if ( j == (unsigned int *)540016640 )
              {
                if ( n != 0 )
                {
                  v218 = 8 * n;
                  v217 = (D3DXShader::CInstruction *)(4 * n);
                  v214 = n;
                  do
                  {
                    v188 = *((_DWORD *)v229 + 2);
                    v189 = v217;
                    v217 = (D3DXShader::CInstruction *)((char *)v217 + 4);
                    *(_DWORD *)((char *)v189 + v188) = v216;
                    v190 = v218;
                    v191 = *((_DWORD *)v229 + 2);
                    v218 += 4;
                    v3 = v214-- == 1;
                    *(_DWORD *)(v190 + v191) = v224;
                  }
                  while ( !v3 );
                }
              }
              else if ( n != 0 )
              {
                v218 = 8 * n;
                v217 = (D3DXShader::CInstruction *)(4 * n);
                v214 = n;
                do
                {
                  v192 = *((_DWORD *)v229 + 2);
                  v193 = v217;
                  v217 = (D3DXShader::CInstruction *)((char *)v217 + 4);
                  *(_DWORD *)((char *)v193 + v192) = v224;
                  v194 = v218;
                  v195 = *((_DWORD *)v229 + 2);
                  v218 += 4;
                  v3 = v214-- == 1;
                  *(_DWORD *)(v194 + v195) = v216;
                }
                while ( !v3 );
              }
              v217 = nullptr;
              if ( v187 != 0 )
              {
                v218 = 4 * v187;
                do
                {
                  v196 = 4 * (_DWORD)v217;
                  v197 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: 0, a5: 0.0);
                  *(_DWORD *)(v196 + *(_DWORD *)(v223 + 16)) = v197;
                  v198 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: 0, a5: 0.0);
                  *(_DWORD *)(v196 + *(_DWORD *)(i + 16)) = v198;
                  *(_DWORD *)(v196 + *((_DWORD *)v229 + 4)) = *(_DWORD *)(v196 + *(_DWORD *)(v134 + 16));
                  v199 = *(_DWORD *)(v196 + *(_DWORD *)(v223 + 16));
                  if ( v199 == -1 || *(_DWORD *)(v196 + *(_DWORD *)(i + 16)) == -1 )
                    goto LABEL_383;
                  v200 = *(_DWORD *)(i + 8);
                  v201 = v218;
                  v217 = (D3DXShader::CInstruction *)((char *)v217 + 1);
                  v218 += 4;
                  *(_DWORD *)(v201 + v200) = v199;
                  *(_DWORD *)(v196 + *((_DWORD *)v229 + 2)) = *(_DWORD *)(v196 + *(_DWORD *)(i + 16));
                }
                while ( (unsigned int)v217 < n );
              }
              v202 = v220;
              for ( jj = *((_DWORD *)this + 3) - 3; jj > v202; jj = HIDWORD(v211) )
              {
                v204 = *((_DWORD *)this + 6);
                HIDWORD(v211) = jj - 1;
                *(_DWORD *)(v204 + 4 * (jj - 1) + 12) = *(_DWORD *)(v204 + 4 * (jj - 1));
              }
              *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v202 + 4) = v223;
              *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v202 + 8) = i;
              *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v202 + 12) = v229;
              *(_DWORD *)v134 = 0;
            }
            else
            {
              v170 = v217;
              *(_DWORD *)v134 = (unsigned int)j ^ (n ^ (unsigned int)j) & 0xFFFFF;
              v171 = v170 != nullptr ? v169 : 0;
              v223 = 0;
              v172 = v170 == nullptr ? v169 : 0;
              if ( v169 != 0 )
              {
                v173 = *(_DWORD *)(v134 + 8);
                v174 = 4 * v172;
                v217 = (D3DXShader::CInstruction *)(4 * v171);
                while ( 1 )
                {
                  *(_DWORD *)((char *)v217 + v173) = *((_DWORD *)pMem + v223);
                  *(_DWORD *)(v174 + *(_DWORD *)(v134 + 8)) = D3DXShader::CBaseProgram::AddArgument(
                                                                this,
                                                                a2: *((_DWORD *)this + 30),
                                                                a3: 0,
                                                                a4: 0,
                                                                a5: *((double *)v227 + v223));
                  v173 = *(_DWORD *)(v134 + 8);
                  if ( *(_DWORD *)(v174 + v173) == -1 )
                    break;
                  ++v223;
                  v217 = (D3DXShader::CInstruction *)((char *)v217 + 4);
                  v174 += 4;
                  if ( v223 >= n )
                    goto LABEL_375;
                }
LABEL_383:
                v121 = -2147024882;
                goto LABEL_382;
              }
            }
LABEL_375:
            v229 = (D3DXShader::CInstruction *)1;
          }
        }
        goto LABEL_376;
      }
      v139 = 0;
      v215 = 1;
      v214 = 1;
      if ( v135 == 0 )
        goto LABEL_252;
      do
      {
        if ( v139 != 0 && *((double *)v227 + v139) != *((double *)v227 + v139 - 1) )
          v214 = 0;
        if ( *((double *)v227 + v139) < -1.0 || *((double *)v227 + v139) > 1.0 )
          v215 = 0;
        ++v139;
      }
      while ( v139 < v135 );
      if ( v214 != 0 )
      {
LABEL_252:
        if ( 2.0 == *(double *)v227 )
        {
          v140 = v135 & 0xFFFFF | 0x20400000;
          if ( *(_DWORD *)v134 != v140 )
          {
            *(_DWORD *)v134 = v140;
            v45 = *(_DWORD *)(v134 + 4) < 2 * v135;
            v229 = (D3DXShader::CInstruction *)1;
            v223 = 2 * v135;
            if ( v45 )
            {
              v141 = D3DXShader::CInstruction::Alloc(a1: 2 * v135);
              *(_DWORD *)(v134 + 8) = v141;
              if ( v141 == nullptr )
                goto LABEL_383;
              v142 = v223;
              *(_DWORD *)(v134 + 4) = v223;
              memset(v141, 0xFFu, 4 * v142);
              v135 = v218;
            }
          }
          j = nullptr;
          if ( v135 != 0 )
          {
            v217 = (D3DXShader::CInstruction *)(4 * v135);
            do
            {
              v143 = (char *)pMem + 4 * (_DWORD)j;
              v144 = (_DWORD *)(4 * (_DWORD)j + *(_DWORD *)(v134 + 8));
              if ( *v144 != *v143 )
              {
                *v144 = *v143;
                v229 = (D3DXShader::CInstruction *)1;
              }
              v145 = *v143;
              v146 = (_DWORD *)((char *)v217 + *(_DWORD *)(v134 + 8));
              if ( *v146 != v145 )
              {
                *v146 = v145;
                v229 = (D3DXShader::CInstruction *)1;
              }
              j = (unsigned int *)((char *)j + 1);
              v217 = (D3DXShader::CInstruction *)((char *)v217 + 4);
            }
            while ( (unsigned int)j < v135 );
          }
          goto LABEL_303;
        }
        if ( 1.0 == *(double *)v227 )
        {
          j = nullptr;
          *(_DWORD *)v134 = v135 & 0xFFFFF | 0x10000000;
          *(_DWORD *)(v134 + 4) = v135;
          if ( v135 != 0 )
          {
            do
            {
              v147 = *(_DWORD *)(v134 + 8);
              v148 = 4 * (_DWORD)j;
              j = (unsigned int *)((char *)j + 1);
              v45 = (unsigned int)j < v135;
              *(_DWORD *)(v148 + v147) = *(_DWORD *)((char *)pMem + v148);
            }
            while ( v45 );
          }
LABEL_268:
          v229 = (D3DXShader::CInstruction *)1;
          goto LABEL_303;
        }
        if ( 0.0 == *(double *)v227 )
        {
          v3 = v224 == -1;
          *(_DWORD *)v134 = v135 & 0xFFFFF | 0x10000000;
          *(_DWORD *)(v134 + 4) = v135;
          if ( v3 )
          {
            v224 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 0.0);
            if ( v224 == -1 )
              goto LABEL_383;
          }
          for ( kk = 0; kk < v135; ++kk )
            *(_DWORD *)(*(_DWORD *)(v134 + 8) + 4 * kk) = v224;
          goto LABEL_268;
        }
        if ( -1.0 == *(double *)v227 )
        {
          v150 = (unsigned int)&loc_10100000 | v135 & 0xFFFFF;
          if ( *(_DWORD *)v134 != v150 )
          {
            *(_DWORD *)v134 = v150;
            *(_DWORD *)(v134 + 4) = v135;
            v229 = (D3DXShader::CInstruction *)1;
          }
          for ( j = nullptr; (unsigned int)j < v135; j = (unsigned int *)((char *)j + 1) )
          {
            v151 = (_DWORD *)(4 * (_DWORD)j + *(_DWORD *)(v134 + 8));
            v152 = *((_DWORD *)pMem + (_DWORD)j);
            if ( *v151 != v152 )
            {
              *v151 = v152;
              v229 = (D3DXShader::CInstruction *)1;
            }
          }
          goto LABEL_303;
        }
      }
      if ( (*((_BYTE *)this + 110) & 0x10) == 0 || v215 != 0 )
      {
        v153 = v135 & 0xFFFFF | 0x20500000;
        if ( *(_DWORD *)v134 != v153 )
        {
          *(_DWORD *)v134 = v153;
          v45 = *(_DWORD *)(v134 + 4) < 2 * v135;
          v229 = (D3DXShader::CInstruction *)1;
          v223 = 2 * v135;
          if ( v45 )
          {
            v154 = D3DXShader::CInstruction::Alloc(a1: 2 * v135);
            *(_DWORD *)(v134 + 8) = v154;
            if ( v154 == nullptr )
              goto LABEL_383;
            v155 = v223;
            *(_DWORD *)(v134 + 4) = v223;
            memset(v154, 0xFFu, 4 * v155);
            v135 = v218;
          }
        }
        i = 0;
        if ( v135 != 0 )
        {
          j = (unsigned int *)(4 * v135);
          do
          {
            v156 = (_DWORD *)(4 * i + *(_DWORD *)(v134 + 8));
            v157 = *((_DWORD *)pMem + i);
            if ( *v156 != v157 )
            {
              *v156 = v157;
              v229 = (D3DXShader::CInstruction *)1;
            }
            v158 = *(unsigned int *)((char *)j + *(_DWORD *)(v134 + 8));
            if ( v158 == -1 )
              v159 = 0;
            else
              v159 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v158);
            if ( v159 == 0
              || (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v159 + 4)) + 5) & 1) == 0
              || *(_DWORD *)(v159 + 8) != -1
              || *(double *)(v159 + 32) != *((double *)v227 + i) )
            {
              v160 = D3DXShader::CBaseProgram::AddArgument(
                       this,
                       a2: *((_DWORD *)this + 30),
                       a3: 0,
                       a4: 0,
                       a5: *((double *)v227 + i));
              v161 = j;
              *(unsigned int *)((char *)j + *(_DWORD *)(v134 + 8)) = v160;
              if ( *(unsigned int *)((char *)v161 + *(_DWORD *)(v134 + 8)) == -1 )
                goto LABEL_383;
              v229 = (D3DXShader::CInstruction *)1;
            }
            ++i;
            ++j;
          }
          while ( i < v135 );
        }
      }
      goto LABEL_303;
    }
LABEL_378:
    v121 = D3DXShader::CProgram::RemoveDeadCode(this);
    if ( v121 >= 0 )
    {
      v121 = D3DXShader::CProgram::CompactInstructions(this);
      if ( v121 >= 0 )
      {
        v121 = D3DXShader::CProgram::CompactArguments(this);
        if ( v121 >= 0 )
LABEL_381:
          v121 = v229 == nullptr;
      }
    }
  }
LABEL_382:
  free(pMem);
  free(pMem: v227);
  return v121;
}

//------------------------------------------------------------------------------
// Address: 0x101F180B
// Name: protected: long D3DXShader::CProgram::PropagatePredicates(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::PropagatePredicates(D3DXShader::CProgram *this)
{
  int v2; // edx
  bool v3; // zf
  _DWORD *v4; // eax
  int v5; // ecx
  int v6; // ecx
  int *v7; // esi
  unsigned int i; // ebx
  bool v9; // cc
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // ebx
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // eax
  int k; // ecx
  int v20; // ebx
  unsigned int v21; // eax
  int ii; // eax
  int v23; // ebx
  int m; // eax
  int v25; // ebx
  unsigned int n; // eax
  int v27; // ecx
  int v28; // ecx
  int v29; // eax
  int v30; // edx
  int v31; // ecx
  int v32; // esi
  unsigned int v33; // eax
  unsigned int v34; // eax
  int v35; // edx
  int jj; // eax
  unsigned int v37; // ebx
  unsigned int v38; // eax
  unsigned int mm; // ebx
  int v40; // eax
  int v41; // eax
  int v42; // ecx
  int v43; // edx
  unsigned int v44; // ebx
  int v45; // ecx
  int v46; // edx
  int v47; // esi
  unsigned int v48; // ebx
  int v49; // eax
  int v50; // edx
  int v51; // ecx
  _DWORD *v52; // esi
  int v53; // edx
  unsigned int v54; // edx
  unsigned int v55; // edx
  _DWORD *v56; // ecx
  bool v57; // cf
  _BYTE v59[128]; // [esp+Ch] [ebp-9Ch] BYREF
  int v60; // [esp+8Ch] [ebp-1Ch]
  int i1; // [esp+90h] [ebp-18h]
  unsigned int v62; // [esp+94h] [ebp-14h] BYREF
  unsigned int kk; // [esp+98h] [ebp-10h]
  unsigned int v64; // [esp+9Ch] [ebp-Ch] BYREF
  unsigned int j; // [esp+A0h] [ebp-8h]
  unsigned int nn; // [esp+A4h] [ebp-4h]

  v2 = 0;
  v3 = *((_DWORD *)this + 2) == 0;
  i1 = 0;
  if ( !v3 )
  {
    while ( 1 )
    {
      v4 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v2);
      v5 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v4[1]);
      v4[12] = v4[5];
      v4[16] = v4[6];
      v6 = *(_DWORD *)(v5 + 4);
      if ( (v6 & 0x10) != 0 )
        break;
      if ( (v6 & 0x11028) == 0 )
      {
        v4[6] = 0;
        goto LABEL_6;
      }
LABEL_7:
      if ( (unsigned int)++v2 >= *((_DWORD *)this + 2) )
        goto LABEL_8;
    }
    v4[6] = 1;
LABEL_6:
    v4[5] = -1;
    goto LABEL_7;
  }
LABEL_8:
  v64 = *((_DWORD *)this + 3);
  while ( v64 != 0 )
  {
    --v64;
    v7 = *(int **)(*((_DWORD *)this + 6) + 4 * v64);
    if ( (*((_WORD *)v7 + 1) & 0xFFF0) != 0 )
    {
      for ( i = 1; i < v7[3]; ++i )
        D3DXShader::CProgram::MergePredicates(
          this,
          a2: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)v7[4]),
          a3: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v7[4] + 4 * i)));
      v9 = (unsigned int)v7[3] <= 1;
      nn = 1;
      if ( !v9 )
      {
        do
        {
          v10 = (_DWORD *)v7[4];
          v11 = *((_DWORD *)this + 5);
          v12 = *(_DWORD *)(v11 + 4 * *v10);
          v13 = 4 * nn;
          v14 = *(_DWORD *)(v11 + 4 * v10[nn]);
          v15 = *(_DWORD *)(v12 + 20);
          ++nn;
          *(_DWORD *)(v14 + 20) = v15;
          *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v13 + v7[4])) + 24) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)v7[4]) + 24);
        }
        while ( nn < v7[3] );
      }
      v16 = *v7;
      v17 = *v7 & 0xFFF00000;
      if ( v17 == 544210944 || v17 == 545259520 || v17 == 290455552 )
      {
        v3 = v7[3] == 0;
        j = 0;
        if ( !v3 )
        {
          do
          {
            v28 = *((_DWORD *)this + 5);
            v29 = 4 * j;
            v30 = *(_DWORD *)(*(_DWORD *)(v28 + 4 * *(_DWORD *)(*(_DWORD *)(v28 + 4 * *(_DWORD *)(4 * j + v7[2])) + 20))
                            + 20);
            v31 = *(_DWORD *)(v28 + 4 * *(_DWORD *)(4 * j++ + v7[4]));
            *(_DWORD *)(v31 + 20) = v30;
            *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v29 + v7[4])) + 24) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v29 + v7[2])) + 20)) + 24);
          }
          while ( j < v7[3] );
        }
      }
      else if ( v17 == 287309824 )
      {
        v18 = v7[1] / (v16 & 0xFFFFFu);
        v3 = v7[3] == 0;
        nn = 0;
        kk = v18;
        if ( !v3 )
        {
          do
          {
            for ( j = 0; j < kk; ++j )
            {
              for ( k = *(_DWORD *)(v7[2] + 4 * (nn + j * v7[3]));
                    k != -1;
                    k = *(_DWORD *)(*(_DWORD *)(v20 + *((_DWORD *)this + 5)) + 8) )
              {
                v20 = 4 * k;
                D3DXShader::CProgram::MergePredicates(
                  this,
                  a2: *(struct D3DXShader::CArgument **)(4 * k + *((_DWORD *)this + 5)),
                  a3: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5)
                                                   + 4
                                                   * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                                           + 4 * *(_DWORD *)(v7[4] + 4 * nn))
                                                               + 20)));
              }
            }
            ++nn;
          }
          while ( nn < v7[3] );
        }
      }
      else if ( (v16 & 0xF0000000) < 0x10000000 || (v16 & 0xF0000000) > 0x40000000 )
      {
        if ( v7[3] != 0 )
        {
          v3 = v7[1] == 0;
          j = 0;
          if ( !v3 )
          {
            do
            {
              for ( m = *(_DWORD *)(v7[2] + 4 * j); m != -1; m = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v25) + 8) )
              {
                v25 = 4 * m;
                D3DXShader::CProgram::MergePredicates(
                  this,
                  a2: *(struct D3DXShader::CArgument **)(4 * m + *((_DWORD *)this + 5)),
                  a3: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)v7[4]));
              }
              ++j;
            }
            while ( j < v7[1] );
          }
        }
        else
        {
          for ( n = 0; n < v7[1]; *(_DWORD *)(v27 + 24) = 1 )
          {
            *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v7[2] + 4 * n)) + 20) = -1;
            v27 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v7[2] + 4 * n++));
          }
        }
      }
      else
      {
        v21 = v7[1] / (v16 & 0xFFFFFu);
        v3 = v7[3] == 0;
        nn = 0;
        kk = v21;
        if ( !v3 )
        {
          do
          {
            for ( j = 0; j < kk; ++j )
            {
              for ( ii = *(_DWORD *)(v7[2] + 4 * (nn + j * v7[3]));
                    ii != -1;
                    ii = *(_DWORD *)(*(_DWORD *)(v23 + *((_DWORD *)this + 5)) + 8) )
              {
                v23 = 4 * ii;
                D3DXShader::CProgram::MergePredicates(
                  this,
                  a2: *(struct D3DXShader::CArgument **)(4 * ii + *((_DWORD *)this + 5)),
                  a3: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v7[4] + 4 * nn)));
              }
            }
            ++nn;
          }
          while ( nn < v7[3] );
        }
      }
    }
  }
  D3DXShader::CArgument::CArgument(this: (D3DXShader::CArgument *)v59);
  for ( j = 0; j < *((_DWORD *)this + 3); ++j )
  {
    v32 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * j);
    v33 = *(_DWORD *)v32 & 0xFFF00000;
    if ( v33 != 0
      && v33 != 284164096
      && v33 != 544210944
      && v33 != 286261248
      && v33 != 287309824
      && v33 != 288358400
      && v33 != 289406976
      && v33 != 545259520
      && v33 != 546308096
      && v33 != 290455552 )
    {
      v34 = **(_DWORD **)(v32 + 16);
      v35 = *((_DWORD *)this + 4);
      v60 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v34);
      if ( (*(_BYTE *)(*(_DWORD *)(v35 + 4 * *(_DWORD *)(v60 + 4)) + 5) & 0x10) == 0 )
      {
        v62 = 0;
        v64 = 0;
        D3DXShader::CProgram::PropagatePredicates_Depth(this, a2: v34, a3: &v62);
        for ( jj = v60; ; jj = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v37) )
        {
          v37 = *(_DWORD *)(jj + 8);
          if ( v37 == -1 )
            break;
          D3DXShader::CProgram::PropagatePredicates_Depth(this, a2: v37, a3: &v64);
        }
        v38 = *(_DWORD *)(v32 + 4);
        if ( v38 != 0 )
        {
          nn = *(_DWORD *)(v32 + 8);
          for ( kk = v38; kk != 0; --kk )
          {
            for ( mm = *(_DWORD *)nn; mm != -1; mm = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * mm) + 8) )
              D3DXShader::CProgram::PropagatePredicates_Depth(this, a2: mm, a3: &v64);
            nn += 4;
          }
        }
        v40 = *(_DWORD *)(v60 + 20);
        if ( v62 > v64 )
        {
          v62 -= v64;
          do
          {
            v41 = 4 * v40;
            if ( *(char *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                     + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v41) + 4))
                         + 5) < 0 )
            {
              for ( nn = 0;
                    nn < *(_DWORD *)(v32 + 12);
                    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v32 + 16) + 4 * v44))
                              + 20) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v41) + 20) )
              {
                v42 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v32 + 16) + 4 * nn));
                v43 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v41) + 24);
                v44 = nn++;
                *(_DWORD *)(v42 + 24) = v43;
              }
            }
            v3 = v62-- == 1;
            v40 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v41) + 20);
          }
          while ( !v3 );
        }
      }
    }
  }
  if ( *((_DWORD *)this + 2) == 0 )
    goto LABEL_84;
  v45 = *((_DWORD *)this + 5);
  v46 = *((_DWORD *)this + 2);
  do
  {
    if ( *(_DWORD *)(*(_DWORD *)v45 + 48) != *(_DWORD *)(*(_DWORD *)v45 + 20)
      || *(_DWORD *)(*(_DWORD *)v45 + 64) != *(_DWORD *)(*(_DWORD *)v45 + 24) )
    {
      i1 = 1;
    }
    v45 += 4;
    --v46;
  }
  while ( v46 != 0 );
  if ( i1 != 0 )
  {
    D3DXShader::CProgram::ReadWriteInfo(this);
    v48 = *((_DWORD *)this + 3);
    while ( v48 != 0 )
    {
      --v48;
      v49 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v48);
      if ( (*(_WORD *)(v49 + 2) & 0xFFF0) != 0 )
      {
        v50 = *(_DWORD *)(v49 + 12);
        nn = v48;
        if ( v50 != 0 )
        {
          v51 = *((_DWORD *)this + 5);
          v52 = *(_DWORD **)(v49 + 16);
          for ( i1 = v50; i1 != 0; --i1 )
          {
            v53 = *(_DWORD *)(*(_DWORD *)(v51 + 4 * *v52) + 20);
            if ( v53 != -1 )
            {
              v54 = *(_DWORD *)(*(_DWORD *)(v51 + 4 * v53) + 72);
              if ( nn < v54 )
                nn = v54;
            }
            ++v52;
          }
          if ( v48 != nn )
          {
            v55 = v48;
            if ( v48 < nn )
            {
              do
              {
                v56 = (_DWORD *)(*((_DWORD *)this + 6) + 4 * v55++);
                v57 = v55 < nn;
                *v56 = v56[1];
              }
              while ( v57 );
            }
            *(_DWORD *)(*((_DWORD *)this + 6) + 4 * nn) = v49;
            D3DXShader::CProgram::ReadWriteInfo(this);
          }
        }
      }
    }
    v47 = 0;
  }
  else
  {
LABEL_84:
    v47 = 1;
  }
  D3DXShader::CNodeState::Print(this: (D3DXShader::CNodeState *)v59);
  return v47;
}

//------------------------------------------------------------------------------
// Address: 0x101F1DC1
// Name: protected: long D3DXShader::CProgram::VectorizeRight(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::VectorizeRight(D3DXShader::CProgram *this)
{
  int v2; // eax
  unsigned int v3; // edx
  int v4; // esi
  unsigned int v5; // ecx
  unsigned int v6; // esi
  char *v7; // edx
  char *v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // esi
  _DWORD *v11; // eax
  int v12; // ecx
  unsigned int v13; // eax
  char *v14; // ecx
  unsigned int v15; // eax
  bool v16; // zf
  unsigned int *v17; // edi
  int v18; // esi
  unsigned int Inputs; // eax
  unsigned int v20; // ecx
  struct D3DXShader::CInstruction *v21; // esi
  unsigned int v22; // ecx
  _DWORD *v23; // eax
  int v24; // edi
  int v25; // ecx
  D3DXShader::CInstruction *v26; // edi
  unsigned int v27; // ecx
  unsigned int i; // eax
  D3DXShader::CInstruction *v29; // eax
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  int v33; // eax
  unsigned int v34; // eax
  int result; // eax
  unsigned int v36; // eax
  unsigned int v37; // esi
  int v38; // edi
  _DWORD *v39; // ecx
  int v40; // eax
  D3DXShader::CInstruction *v41; // edi
  unsigned int v42; // ecx
  unsigned int v43; // ecx
  unsigned int v44; // eax
  D3DXShader::CInstruction *v45; // edi
  struct D3DXShader::CInstruction *v46; // esi
  int v47; // ecx
  char *v48; // esi
  char *v49; // edi
  char v50; // al
  D3DXShader::CInstruction *v51; // edx
  unsigned int v52; // ecx
  char *v53; // edi
  char *v54; // esi
  struct D3DXShader::CInstruction *v55; // eax
  unsigned int v56; // ecx
  unsigned int k; // eax
  int v58; // eax
  int v59; // esi
  int v60; // eax
  int v61; // eax
  _DWORD v62[3]; // [esp+14h] [ebp-78h] BYREF
  _DWORD v63[5]; // [esp+20h] [ebp-6Ch] BYREF
  D3DXShader::CInstruction *v64; // [esp+34h] [ebp-58h]
  _DWORD *v65; // [esp+38h] [ebp-54h]
  void *pMem; // [esp+3Ch] [ebp-50h]
  D3DXShader::CInstruction *j; // [esp+40h] [ebp-4Ch]
  unsigned int v68; // [esp+44h] [ebp-48h]
  unsigned int *v69; // [esp+48h] [ebp-44h] BYREF
  unsigned int v70; // [esp+4Ch] [ebp-40h]
  unsigned int v71; // [esp+50h] [ebp-3Ch]
  unsigned int v72; // [esp+54h] [ebp-38h]
  unsigned int v73; // [esp+58h] [ebp-34h]
  unsigned int v74; // [esp+5Ch] [ebp-30h]
  unsigned int v75; // [esp+60h] [ebp-2Ch]
  int v76; // [esp+64h] [ebp-28h]
  unsigned int v77; // [esp+68h] [ebp-24h]
  unsigned int v78; // [esp+6Ch] [ebp-20h] BYREF
  unsigned int v79; // [esp+70h] [ebp-1Ch]
  unsigned int v80; // [esp+74h] [ebp-18h]
  int v81; // [esp+78h] [ebp-14h]
  struct D3DXShader::CInstruction *v82; // [esp+7Ch] [ebp-10h]
  unsigned int v83; // [esp+80h] [ebp-Ch]
  unsigned int v84; // [esp+84h] [ebp-8h]
  unsigned int v85; // [esp+88h] [ebp-4h]

  v70 = -1;
  D3DXShader::CProgram::ReadWriteInfo(this);
  v2 = *((_DWORD *)this + 2);
  v3 = 0;
  v78 = 0;
  if ( v2 != 0 )
  {
    v4 = *((_DWORD *)this + 5);
    do
    {
      if ( *((_DWORD *)this + 34) == *(_DWORD *)(*(_DWORD *)v4 + 4) )
      {
        v5 = *(_DWORD *)(*(_DWORD *)v4 + 12);
        if ( v3 <= v5 )
          v3 = v5 + 1;
      }
      v4 += 4;
      --v2;
    }
    while ( v2 != 0 );
    v78 = v3;
  }
  v6 = 4 * (v3 + 8 * *((_DWORD *)this + 3));
  v7 = (char *)MemAlloc_Alloc(nSize: v6);
  pMem = v7;
  if ( v7 == nullptr )
    return -2147024882;
  memset(v7, 0, 4 * (v6 >> 2));
  v8 = &v7[4 * (v6 >> 2)];
  v9 = v6 & 3;
  v10 = 0;
  memset(v8, 0, v9);
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v11 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v10);
      if ( *((_DWORD *)this + 34) == v11[1] )
      {
        v12 = v11[3];
        v13 = v11[4];
        v14 = &v7[4 * v12];
        if ( *(_DWORD *)v14 <= v13 )
          *(_DWORD *)v14 = v13 + 1;
      }
      ++v10;
    }
    while ( v10 < *((_DWORD *)this + 2) );
  }
  v15 = *((_DWORD *)this + 3);
  v74 = 0;
  v73 = v15;
  while ( v74 < v73 )
  {
    v16 = (*(_WORD *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * v74) + 2) & 0xFFF0) == 0;
    v82 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v74);
    if ( !v16 )
    {
      v17 = (unsigned int *)v82;
      v18 = 0;
      v71 = 1;
      Inputs = D3DXShader::CInstruction::GetInputs(this: v82, a2: 0, a3: &v69);
      if ( Inputs == 0 )
        goto LABEL_83;
      do
      {
        if ( D3DXShader::CProgram::CanVectorize(
               this,
               a2: v69,
               a3: Inputs,
               a4: (unsigned int *)pMem,
               a5: &v78,
               a6: (struct D3DXShader::CInstruction *)v17,
               a7: v73,
               a8: 0xFFFFFFFF) == 0 )
          v71 = 0;
        Inputs = D3DXShader::CInstruction::GetInputs(this: (D3DXShader::CInstruction *)v17, a2: ++v18, a3: &v69);
      }
      while ( Inputs != 0 );
      if ( v71 != 0 || D3DXShader::CInstruction::IsSpecial(this: (D3DXShader::CInstruction *)v17) != 0 )
      {
LABEL_83:
        v68 = D3DXShader::CBaseProgram::AddInstruction(this, a2: *v17, a3: v17[1], a4: v17[3]);
        if ( v68 == -1 )
          goto LABEL_99;
        v46 = v82;
        j = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v68);
        v45 = j;
        D3DXShader::CInstruction::Instance(this: j, a2: v82);
        v47 = *((_DWORD *)v46 + 1);
        v48 = *((char **)v46 + 2);
        v49 = *((char **)v45 + 2);
        v50 = 4 * v47;
        v51 = j;
        v52 = (unsigned int)(4 * v47) >> 2;
        qmemcpy(v49, v48, 4 * v52);
        v54 = &v48[4 * v52];
        v53 = &v49[4 * v52];
        LOBYTE(v52) = v50;
        v55 = v82;
        qmemcpy(v53, v54, v52 & 3);
        qmemcpy(*((void **)v51 + 4), *((const void **)v55 + 4), 4 * *((_DWORD *)v55 + 3));
        v56 = 0;
        if ( *((_DWORD *)v55 + 3) != 0 )
        {
          do
            *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)j + 4) + 4 * v56++)) + 72) = v68;
          while ( v56 < *((_DWORD *)v82 + 3) );
        }
      }
      else
      {
        v85 = 0;
        v20 = D3DXShader::CInstruction::GetInputs(this: (D3DXShader::CInstruction *)v17, a2: 0, a3: nullptr);
        v84 = v20;
        if ( v20 != 0 )
          v83 = v17[1] / v20;
        else
          v83 = 0;
        memset(&v63[1], 0, 16);
        v79 = 0;
        if ( v20 != 0 )
        {
          v80 = 0;
          v21 = v82;
          v65 = v63;
          do
          {
            if ( v65[v80 / 4 + 1] == 0 )
            {
              v22 = v79 + 1;
              v81 = 1;
              v72 = v79 + 1;
              if ( v79 + 1 < v84 )
              {
                v75 = 4;
                do
                {
                  if ( v63[v22 + 1] == 0 )
                  {
                    v77 = 0;
                    if ( v83 != 0 )
                    {
                      v23 = (_DWORD *)(v80 + *((_DWORD *)v21 + 2));
                      do
                      {
                        v24 = *((_DWORD *)this + 5);
                        v25 = 4 * *v23;
                        v71 = 4 * *(_DWORD *)((char *)v23 + v75);
                        if ( *(_DWORD *)(*(_DWORD *)(v24 + v25) + 4) != *(_DWORD *)(*(_DWORD *)(v24 + v71) + 4) )
                          break;
                        if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v25) + 8) != *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v71) + 8) )
                          break;
                        if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v25) + 12) != *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v71) + 12) )
                          break;
                        ++v77;
                        v23 += v84;
                      }
                      while ( v77 < v83 );
                    }
                    if ( v77 == v83 )
                      ++v81;
                  }
                  v75 += 4;
                  v22 = ++v72;
                }
                while ( v72 < v84 );
              }
              v75 = D3DXShader::CBaseProgram::AddInstruction(
                      this,
                      a2: *(_DWORD *)v21 ^ (v81 ^ *(_DWORD *)v21) & 0xFFFFF,
                      a3: 0xFFFFFFFF,
                      a4: 0xFFFFFFFF);
              if ( v75 == -1 )
                goto LABEL_99;
              v26 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v75);
              D3DXShader::CInstruction::Instance(this: v26, a2: v21);
              v27 = v84;
              if ( v84 > v79 )
              {
                v76 = 4 * v81 - 4;
                for ( i = 4 * v84 - v80; ; i = v68 )
                {
                  v68 = i - 4;
                  v71 = v27 - 1;
                  v16 = v63[v27] == 0;
                  v64 = (D3DXShader::CInstruction *)&v63[v27];
                  if ( !v16 )
                    goto LABEL_58;
                  v77 = 0;
                  if ( v83 != 0 )
                  {
                    v29 = (D3DXShader::CInstruction *)(v80 + *((_DWORD *)v21 + 2));
                    j = v29;
                    do
                    {
                      v30 = *(_DWORD *)((char *)v29 + v68);
                      v31 = *((_DWORD *)this + 5);
                      v72 = 4 * *(_DWORD *)v29;
                      v32 = 4 * v30;
                      if ( *(_DWORD *)(*(_DWORD *)(v72 + v31) + 4) != *(_DWORD *)(*(_DWORD *)(v32 + v31) + 4) )
                        break;
                      if ( *(_DWORD *)(*(_DWORD *)(v72 + *((_DWORD *)this + 5)) + 8) != *(_DWORD *)(*(_DWORD *)(v32 + *((_DWORD *)this + 5))
                                                                                                  + 8) )
                        break;
                      if ( *(_DWORD *)(*(_DWORD *)(v72 + *((_DWORD *)this + 5)) + 12) != *(_DWORD *)(*(_DWORD *)(v32 + *((_DWORD *)this + 5)) + 12) )
                        break;
                      ++v77;
                      v29 = (D3DXShader::CInstruction *)((char *)j + 4 * v84);
                      j = v29;
                    }
                    while ( v77 < v83 );
                    if ( v77 < v83 )
                      goto LABEL_58;
                    v72 = v76;
                    v77 = 4 * v71;
                    for ( j = (D3DXShader::CInstruction *)v83; j != nullptr; j = (D3DXShader::CInstruction *)((char *)j - 1) )
                    {
                      *(_DWORD *)(v72 + *((_DWORD *)v26 + 2)) = *(_DWORD *)(v77 + *((_DWORD *)v21 + 2));
                      v77 += 4 * v84;
                      v72 += 4 * v81;
                    }
                    *(_DWORD *)v64 = 1;
                  }
                  if ( (*(_DWORD *)v21 & 0xFFF00000) != 0x50000000 )
                  {
                    v33 = v76;
                    *(_DWORD *)(v76 + *((_DWORD *)v26 + 4)) = *(_DWORD *)(4 * v71 + *((_DWORD *)v21 + 4));
                    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v33 + *((_DWORD *)v26 + 4))) + 72) = v75;
                  }
                  v76 -= 4;
LABEL_58:
                  v27 = v71;
                  if ( v71 <= v79 )
                    break;
                }
              }
              if ( (*(_DWORD *)v21 & 0xFFF00000) == 0x50000000 )
              {
                if ( v81 == v84 )
                {
                  **((_DWORD **)v26 + 4) = **((_DWORD **)v21 + 4);
                }
                else
                {
                  v34 = D3DXShader::CBaseProgram::AddArgument(
                          this,
                          a2: *((_DWORD *)this + 34),
                          a3: v78,
                          a4: v85,
                          a5: 0.0);
                  v62[v85] = v34;
                  **((_DWORD **)v26 + 4) = v34;
                  if ( **((_DWORD **)v26 + 4) == -1 )
                    goto LABEL_99;
                  *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v26 + 4)) + 20) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v21 + 4)) + 20);
                  *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v26 + 4)) + 24) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v21 + 4)) + 24);
                  result = D3DXShader::CProgram::SimplifyDotProduct(this, a2: v26, a3: 0);
                  if ( result < 0 )
                    return result;
                  ++v85;
                }
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v26 + 4)) + 72) = v75;
              }
            }
            ++v79;
            v80 += 4;
          }
          while ( v79 < v84 );
          if ( v85 != 0 )
          {
            if ( v85 == 2 )
            {
              v36 = D3DXShader::CBaseProgram::AddInstruction(this, a2: 0x20400001u, a3: 0xFFFFFFFF, a4: 0xFFFFFFFF);
              v75 = 0;
              v37 = v36;
              do
              {
                v38 = *((_DWORD *)this + 6);
                v39 = &v62[v75];
                v40 = 4 * *v39;
                if ( (**(_DWORD **)(v38 + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v40) + 72)) & 0xFFF00000) == 0x10000000 )
                {
                  **(_DWORD **)(v38 + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v40) + 72)) = 0;
                  *v39 = **(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 6)
                                                 + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v40) + 72))
                                     + 8);
                }
                ++v75;
              }
              while ( v75 < 2 );
            }
            else
            {
              v37 = D3DXShader::CBaseProgram::AddInstruction(
                      this,
                      a2: v85 & 0xFFFFF | 0x50000000,
                      a3: 0xFFFFFFFF,
                      a4: 0xFFFFFFFF);
            }
            if ( v37 == -1 )
              return -2147024882;
            v64 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v37);
            v41 = v64;
            D3DXShader::CInstruction::Instance(this: v64, a2: v82);
            **((_DWORD **)v41 + 4) = **((_DWORD **)v82 + 4);
            v42 = 4 * v85;
            *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v41 + 4)) + 72) = v37;
            qmemcpy(*((void **)v41 + 2), v62, v42);
            if ( v85 != 2 )
            {
              if ( v70 == -1 )
              {
                v70 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 1.0);
                if ( v70 == -1 )
                {
LABEL_99:
                  v59 = -2147024882;
                  goto LABEL_96;
                }
              }
              v43 = v85;
              if ( v85 != 0 )
              {
                v44 = 4 * v85;
                do
                {
                  *(_DWORD *)(v44 + *((_DWORD *)v64 + 2)) = v70;
                  v44 += 4;
                  --v43;
                }
                while ( v43 != 0 );
              }
            }
            ++v78;
          }
        }
      }
    }
    ++v74;
  }
  for ( k = 0; k < v73; ++k )
    **(_DWORD **)(*((_DWORD *)this + 6) + 4 * k) = 0;
  v58 = D3DXShader::CProgram::RemoveDeadCode(this);
  if ( v58 == 0 || (v59 = v58, v58 >= 0) )
  {
    v60 = D3DXShader::CProgram::CompactInstructions(this);
    if ( v60 == 0 || (v59 = v60, v60 >= 0) )
    {
      v61 = D3DXShader::CProgram::RemoveDuplicateArguments(this);
      if ( v61 == 0 || (v59 = v61, v61 >= 0) )
        v59 = 0;
    }
  }
LABEL_96:
  free(pMem);
  return v59;
}

//------------------------------------------------------------------------------
// Address: 0x101F2488
// Name: protected: long D3DXShader::CProgram::CombineInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CombineInstructions(D3DXShader::CProgram *this)
{
  unsigned int v2; // eax
  bool v4; // zf
  int v5; // ecx
  unsigned int i; // edx
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  unsigned int v15; // esi
  unsigned int v16; // edx
  int v17; // ecx
  int v18; // eax
  unsigned int j; // edx
  _DWORD *v20; // eax
  int v21; // ecx
  int v22; // ecx
  unsigned int *v23; // ecx
  unsigned int v24; // eax
  _DWORD *v25; // eax
  unsigned int k; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // edi
  struct D3DXShader::CInstruction *v30; // eax
  _DWORD *v31; // eax
  int v32; // edx
  int v33; // ecx
  int v34; // esi
  int v35; // eax
  unsigned int v36; // esi
  unsigned int v37; // edi
  int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // eax
  int v41; // ecx
  int v42; // edx
  unsigned int v43; // eax
  D3DXShader::CInstruction *v44; // esi
  char v45; // dl
  unsigned int v46; // ecx
  unsigned int *v47; // edi
  char *v48; // esi
  unsigned int v49; // edx
  const void *v50; // esi
  D3DXShader::CInstruction *v51; // edx
  char *v52; // eax
  char *v53; // esi
  char *v54; // edi
  char v55; // dl
  unsigned int v56; // ecx
  char *v57; // edi
  char *v58; // esi
  unsigned int v59; // edx
  unsigned __int8 *v60; // eax
  D3DXShader::CInstruction *v61; // edi
  int v62; // esi
  unsigned int *v63; // esi
  unsigned int v64; // eax
  unsigned int *v65; // esi
  D3DXShader::CInstruction *v66; // edx
  int *v67; // edi
  int v68; // eax
  unsigned int v69; // ecx
  int v70; // ecx
  int v71; // edx
  D3DXShader::CInstruction *v72; // eax
  int m; // eax
  D3DXShader::CInstruction *v74; // ecx
  _DWORD *v75; // eax
  _DWORD *v76; // esi
  _DWORD *v77; // eax
  int v78; // eax
  D3DXShader::CInstruction *v79; // eax
  D3DXShader::CInstruction *v80; // ecx
  int v81; // ecx
  int v82; // ecx
  _DWORD *v83; // esi
  unsigned int *v84; // edi
  unsigned int v85; // edx
  int v86; // eax
  unsigned int v87; // edi
  const void *v88; // esi
  unsigned int v89; // ecx
  int v90; // eax
  int CanVectorize; // eax
  unsigned int v92; // eax
  D3DXShader::CInstruction *v93; // esi
  char v94; // dl
  unsigned int v95; // ecx
  unsigned int *v96; // edi
  char *v97; // esi
  int v98; // edx
  const void *v99; // esi
  D3DXShader::CInstruction *v100; // edx
  int v101; // edi
  int v102; // eax
  unsigned int v103; // eax
  char *v104; // esi
  char v105; // dl
  unsigned int v106; // ecx
  char *v107; // edi
  char *v108; // esi
  int v109; // edx
  int v110; // edi
  int v111; // eax
  int v112; // eax
  char *v113; // esi
  char v114; // dl
  unsigned int v115; // ecx
  unsigned int *v116; // edi
  char *v117; // esi
  int v118; // edx
  int v119; // edi
  int *v120; // esi
  int v121; // edi
  _DWORD *v122; // edx
  _DWORD *v123; // ecx
  int v124; // eax
  unsigned int v125; // esi
  D3DXShader::CInstruction *v126; // eax
  unsigned __int8 *v127; // eax
  struct D3DXShader::CInstruction *v128; // edi
  unsigned int v129; // edx
  unsigned int v130; // ecx
  unsigned int ii; // esi
  _DWORD *v132; // eax
  _DWORD *v133; // eax
  _DWORD *v134; // ecx
  char *v135; // esi
  D3DXShader::CInstruction *v136; // eax
  char *v137; // edi
  unsigned int v138; // edx
  char *v139; // edi
  char *v140; // esi
  char v141; // cl
  struct D3DXShader::CInstruction *v142; // edx
  char *v143; // esi
  char *v144; // edi
  unsigned int v145; // edx
  char *v146; // edi
  char *v147; // esi
  char v148; // cl
  unsigned int v149; // edx
  unsigned int v150; // ecx
  unsigned int *v151; // esi
  unsigned int *v152; // edi
  unsigned int *v153; // esi
  unsigned int v154; // ecx
  unsigned int *v155; // edi
  unsigned int *v156; // edi
  char v157; // dl
  unsigned int v158; // ecx
  unsigned int *v159; // edi
  unsigned int *v160; // esi
  unsigned int v161; // edx
  _DWORD *v162; // esi
  D3DXShader::CInstruction *v163; // edi
  int v164; // eax
  unsigned int v165; // eax
  unsigned int v166; // edx
  void *v167; // [esp-18h] [ebp-D4h]
  struct D3DXShader::CInstruction *v168; // [esp-14h] [ebp-D0h]
  unsigned int v169; // [esp-Ch] [ebp-C8h]
  unsigned int v170; // [esp-Ch] [ebp-C8h]
  unsigned int v171; // [esp-Ch] [ebp-C8h]
  unsigned int v172; // [esp-Ch] [ebp-C8h]
  unsigned int v173[4]; // [esp+4h] [ebp-B8h] BYREF
  unsigned int v174[4]; // [esp+14h] [ebp-A8h] BYREF
  unsigned int v175[4]; // [esp+24h] [ebp-98h] BYREF
  unsigned int v176[4]; // [esp+34h] [ebp-88h] BYREF
  unsigned int v177; // [esp+44h] [ebp-78h]
  unsigned int v178[4]; // [esp+48h] [ebp-74h] BYREF
  int v179; // [esp+58h] [ebp-64h]
  D3DXShader::CInstruction *v180; // [esp+5Ch] [ebp-60h]
  int v181; // [esp+60h] [ebp-5Ch]
  int v182; // [esp+64h] [ebp-58h]
  D3DXShader::CInstruction *v183; // [esp+68h] [ebp-54h]
  void *v184; // [esp+6Ch] [ebp-50h]
  unsigned int v185[4]; // [esp+70h] [ebp-4Ch] BYREF
  D3DXShader::CInstruction *v186; // [esp+80h] [ebp-3Ch]
  unsigned int v187; // [esp+84h] [ebp-38h]
  unsigned int v188; // [esp+88h] [ebp-34h]
  D3DXShader::CInstruction *v189; // [esp+8Ch] [ebp-30h]
  unsigned int v190; // [esp+90h] [ebp-2Ch]
  void *pMem; // [esp+94h] [ebp-28h]
  unsigned int v192; // [esp+98h] [ebp-24h]
  unsigned int v193; // [esp+9Ch] [ebp-20h]
  struct D3DXShader::CInstruction *n; // [esp+A0h] [ebp-1Ch]
  unsigned int v195; // [esp+A4h] [ebp-18h]
  unsigned int v196; // [esp+A8h] [ebp-14h]
  unsigned int v197; // [esp+ACh] [ebp-10h]
  D3DXShader::CInstruction *v198; // [esp+B0h] [ebp-Ch]
  struct D3DXShader::CInstruction *v199; // [esp+B4h] [ebp-8h]
  struct D3DXShader::CInstruction *v200; // [esp+B8h] [ebp-4h]

  v2 = 0;
  if ( (*((_BYTE *)this + 204) & 4) != 0 )
    return 1;
  v4 = *((_DWORD *)this + 1) == 0;
  v179 = 0;
  if ( !v4 )
  {
    do
    {
      v5 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v2++);
      *(_DWORD *)(v5 + 16) = 0;
    }
    while ( v2 < *((_DWORD *)this + 1) );
  }
  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    v7 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i);
    v8 = *(_DWORD *)(v7 + 4);
    if ( *((_DWORD *)this + 29) != v8 )
    {
      v9 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v8);
      v10 = *(_DWORD *)(v9 + 4);
      if ( (v10 & 2) != 0 && (v10 & 0x400) == 0 )
      {
        v11 = *(_DWORD *)(v7 + 12) + 1;
        if ( *(_DWORD *)(v9 + 16) < v11 )
          *(_DWORD *)(v9 + 16) = v11;
      }
    }
  }
  v12 = 0;
  if ( *((_DWORD *)this + 1) != 0 )
  {
    v13 = *((_DWORD *)this + 4);
    v14 = *((_DWORD *)this + 1);
    do
    {
      v12 += *(_DWORD *)(*(_DWORD *)v13 + 16);
      v13 += 4;
      --v14;
    }
    while ( v14 != 0 );
  }
  v15 = 4 * v12;
  v184 = MemAlloc_Alloc(nSize: 4 * v12);
  if ( v184 == nullptr )
  {
LABEL_178:
    v62 = -2147024882;
    goto LABEL_177;
  }
  memset(v184, 0, v15);
  v16 = 0;
  v17 = 0;
  if ( *((_DWORD *)this + 1) != 0 )
  {
    v18 = *((_DWORD *)this + 4);
    do
    {
      *(_DWORD *)(*(_DWORD *)(v18 + 4 * v16) + 28) = *(_DWORD *)(*(_DWORD *)(v18 + 4 * v16) + 16) != 0
                                                   ? (char *)v184 + 4 * v17
                                                   : nullptr;
      v18 = *((_DWORD *)this + 4);
      v17 += *(_DWORD *)(*(_DWORD *)(v18 + 4 * v16++) + 16);
    }
    while ( v16 < *((_DWORD *)this + 1) );
  }
  for ( j = 0; j < *((_DWORD *)this + 2); ++j )
  {
    v20 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * j);
    v21 = v20[1];
    if ( *((_DWORD *)this + 29) != v21 )
    {
      v22 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v21) + 28);
      if ( v22 != 0 )
      {
        v23 = (unsigned int *)(v22 + 4 * v20[3]);
        v24 = v20[4] + 1;
        if ( *v23 < v24 )
          *v23 = v24;
      }
    }
  }
  v4 = *((_DWORD *)this + 3) == 0;
  v195 = 0;
  if ( !v4 )
  {
    do
    {
      v25 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v195);
      if ( (*v25 & 0xF0000000) == 0x60000000 || (*v25 & 0xFFF00000) == 0x11000000 )
      {
        for ( k = 0; k < v25[1]; ++k )
        {
          v27 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v25[2] + 4 * k));
          v28 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v27 + 4)) + 28);
          if ( v28 != 0 )
            *(_DWORD *)(v28 + 4 * *(_DWORD *)(v27 + 12)) = 4;
        }
      }
      ++v195;
    }
    while ( v195 < *((_DWORD *)this + 3) );
  }
  if ( (*((_DWORD *)this + 27) & 6) != 0
    || (D3DXShader::CProgram::ReadWriteInfo(this), v199 = nullptr, *((_DWORD *)this + 3) == 0) )
  {
LABEL_66:
    D3DXShader::CProgram::ReadWriteInfo(this);
    v196 = 0;
    if ( *((_DWORD *)this + 3) == 0 )
    {
LABEL_176:
      v62 = v179 == 0;
      goto LABEL_177;
    }
    while ( 1 )
    {
      v67 = *(int **)(*((_DWORD *)this + 6) + 4 * v196);
      v68 = *v67;
      v69 = *v67 & 0xF0000000;
      pMem = v67;
      if ( v69 >= 0x10000000
        && v69 <= 0x40000000
        && ((v68 & 0xFFF00000) == 0x10000000 || (*((_BYTE *)this + 108) & 6) == 0)
        && D3DXShader::CInstruction::IsFlowControl(this: (D3DXShader::CInstruction *)v67) == 0 )
      {
        v70 = *((_DWORD *)this + 5);
        v71 = *((_DWORD *)this + 4);
        v182 = *(_DWORD *)(*(_DWORD *)(v70 + 4 * *(_DWORD *)v67[4]) + 4);
        v193 = *(_DWORD *)(*(_DWORD *)(v71 + 4 * v182) + 28);
        if ( v193 != 0 )
          break;
      }
LABEL_175:
      if ( ++v196 >= *((_DWORD *)this + 3) )
        goto LABEL_176;
    }
    v72 = *((D3DXShader::CInstruction **)this + 3);
    v189 = nullptr;
    v4 = v67[1] == 0;
    v186 = v72;
    v188 = (unsigned int)v72;
    if ( !v4 )
    {
      v195 = v67[2];
      v190 = v67[1];
      do
      {
        for ( m = *(_DWORD *)v195; m != -1; m = v75[2] )
        {
          v75 = *(_DWORD **)(v70 + 4 * m);
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v75[1]) + 4) & 2) != 0
            && (unsigned int)v189 < v75[18] + 1 )
          {
            v189 = (D3DXShader::CInstruction *)(v75[18] + 1);
          }
        }
        v195 += 4;
        --v190;
      }
      while ( v190 != 0 );
    }
    if ( v67[3] != 0 )
    {
      v76 = (_DWORD *)v67[4];
      v190 = v67[3];
      do
      {
        v77 = *(_DWORD **)(v70 + 4 * *v76);
        if ( (unsigned int)v186 > v77[21] )
          v186 = (D3DXShader::CInstruction *)v77[21];
        while ( 1 )
        {
          v78 = v77[2];
          if ( v78 == -1 )
            break;
          v77 = *(_DWORD **)(v70 + 4 * v78);
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v77[1]) + 4) & 2) != 0
            && (unsigned int)v189 < v77[18] + 1 )
          {
            v189 = (D3DXShader::CInstruction *)(v77[18] + 1);
          }
        }
        ++v76;
        --v190;
      }
      while ( v190 != 0 );
    }
    v79 = v189;
    for ( n = v189; ; v79 = n )
    {
      if ( v79 >= v186 )
        goto LABEL_175;
      if ( (struct D3DXShader::CInstruction *)v196 != n )
      {
        v80 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * (_DWORD)n);
        v180 = v80;
        v199 = v196 >= (unsigned int)n ? (struct D3DXShader::CInstruction *)pMem : v80;
        v200 = v196 >= (unsigned int)n ? v80 : (struct D3DXShader::CInstruction *)pMem;
        v81 = *(_DWORD *)v200;
        v198 = *(D3DXShader::CInstruction **)v199;
        v183 = v198;
        v198 = (D3DXShader::CInstruction *)((unsigned int)v198 & 0xFFF00000);
        if ( v198 == (D3DXShader::CInstruction *)(v81 & 0xFFF00000) )
        {
          v82 = *((_DWORD *)this + 5);
          v83 = *(_DWORD **)(v82 + 4 * **((_DWORD **)v200 + 4));
          v84 = *(unsigned int **)(v82 + 4 * **((_DWORD **)v199 + 4));
          v4 = v84[1] == v83[1];
          v187 = v84[1];
          if ( v4 && v84[2] == v83[2] && v84[5] == v83[5] && v84[6] == v83[6] )
          {
            v85 = *((_DWORD *)v199 + 3);
            v177 = *((_DWORD *)v199 + 1) + *((_DWORD *)v200 + 1);
            v86 = *((_DWORD *)v200 + 3);
            v197 = v85;
            v181 = v86;
            v192 = v86 + v85;
            if ( v86 + v85 <= 4 )
            {
              v87 = v84[3];
              v88 = (const void *)v83[3];
              v195 = v87;
              v190 = (unsigned int)v88;
              if ( (const void *)v87 == v88
                || (*((_BYTE *)this + 108) & 6) == 0
                && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v187) + 4) & 0x20) == 0
                && (unsigned int)(*(_DWORD *)(v193 + 4 * v87) + *(_DWORD *)(v193 + 4 * v190)) <= 4 )
              {
                break;
              }
            }
          }
        }
      }
LABEL_140:
      n = (struct D3DXShader::CInstruction *)((char *)n + 1);
    }
    v187 = v196;
    if ( v196 >= (unsigned int)n )
      v187 = (unsigned int)n;
    if ( v198 == (D3DXShader::CInstruction *)0x10000000 || v198 == (D3DXShader::CInstruction *)&loc_10100000 )
    {
      v120 = *((int **)v200 + 2);
      v121 = *v120;
      v198 = *((D3DXShader::CInstruction **)v199 + 2);
      v122 = *(_DWORD **)(v82 + 4 * *(_DWORD *)v198);
      v123 = *(_DWORD **)(v82 + 4 * v121);
      if ( v122[1] == v123[1] && v122[2] == v123[2] && v122[3] == v123[3] )
      {
        v124 = v86;
        qmemcpy(v185, v120, v124 * 4);
        qmemcpy(&v185[v124], v198, 4 * v197);
LABEL_133:
        v197 = 0;
        goto LABEL_134;
      }
    }
    else
    {
      v89 = (unsigned int)v183 & 0xF0000000;
      if ( ((unsigned int)v183 & 0xF0000000) == 0x10000000 )
      {
        v169 = v187;
        v90 = v86;
        qmemcpy(v185, *((const void **)v200 + 2), v90 * 4);
        v168 = v200;
        qmemcpy(&v185[v90], *((const void **)v199 + 2), 4 * v197);
        CanVectorize = D3DXShader::CProgram::CanVectorize(
                         this,
                         a2: v185,
                         a3: v192,
                         a4: nullptr,
                         a5: nullptr,
                         a6: v168,
                         a7: 0,
                         a8: v169);
      }
      else
      {
        if ( v89 == 0x20000000 )
        {
          v92 = 4 * v86;
          qmemcpy(v185, *((const void **)v200 + 2), v92);
          v93 = *((D3DXShader::CInstruction **)v199 + 2);
          v197 *= 4;
          v94 = v197;
          v95 = v197 >> 2;
          v198 = v93;
          qmemcpy(&v185[v92 / 4], v93, 4 * (v197 >> 2));
          v97 = (char *)v93 + 4 * v95;
          v96 = &v185[v92 / 4 + v95];
          LOBYTE(v95) = v94;
          v98 = *((_DWORD *)v200 + 2);
          qmemcpy(v96, v97, v95 & 3);
          v170 = v187;
          qmemcpy(v178, (const void *)(v98 + v92), 4 * (v92 >> 2));
          v99 = (const void *)(v98 + v92 + 4 * (v92 >> 2));
          v100 = v198;
          qmemcpy(&v178[v92 >> 2], v99, v92 & 3);
          v183 = (D3DXShader::CInstruction *)v92;
          qmemcpy(&v178[v92 / 4], (char *)v100 + v197, v197);
          v101 = D3DXShader::CProgram::CanVectorize(
                   this,
                   a2: v185,
                   a3: v192,
                   a4: nullptr,
                   a5: nullptr,
                   a6: v200,
                   a7: 0,
                   a8: v170);
          v102 = D3DXShader::CProgram::CanVectorize(
                   this,
                   a2: v178,
                   a3: v192,
                   a4: nullptr,
                   a5: nullptr,
                   a6: v200,
                   a7: 0,
                   a8: v187);
          if ( v101 != 0 && v102 != 0 )
            goto LABEL_133;
          if ( D3DXShader::CInstruction::IsSymetric(this: v199) != 0 )
          {
            v103 = (unsigned int)v183;
            qmemcpy(v176, *((const void **)v200 + 2), (unsigned int)v183);
            v104 = (char *)(*((_DWORD *)v199 + 2) + v197);
            v198 = *((D3DXShader::CInstruction **)v199 + 2);
            v105 = v197;
            v106 = v197 >> 2;
            qmemcpy((char *)v176 + v103, v104, 4 * (v197 >> 2));
            v108 = &v104[4 * v106];
            v107 = (char *)&v176[v106] + v103;
            v171 = v187;
            LOBYTE(v106) = v105;
            v109 = *((_DWORD *)v200 + 2);
            qmemcpy(v107, v108, v106 & 3);
            qmemcpy(v175, (const void *)(v109 + v103), v103);
            qmemcpy((char *)v175 + v103, v198, v197);
            v110 = D3DXShader::CProgram::CanVectorize(
                     this,
                     a2: v176,
                     a3: v192,
                     a4: nullptr,
                     a5: nullptr,
                     a6: v200,
                     a7: 0,
                     a8: v171);
            v111 = D3DXShader::CProgram::CanVectorize(
                     this,
                     a2: v175,
                     a3: v192,
                     a4: nullptr,
                     a5: nullptr,
                     a6: v200,
                     a7: 0,
                     a8: v187);
            if ( v110 != 0 && v111 != 0 )
            {
              v197 = 1;
LABEL_134:
              if ( v195 == v190 || (unsigned int)(*(_DWORD *)(v193 + 4 * v195) + *(_DWORD *)(v193 + 4 * v190)) <= 4 )
              {
                v127 = D3DXShader::CInstruction::operator new(a1: 0x74u);
                if ( v127 != nullptr )
                  v198 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v127);
                else
                  v198 = nullptr;
                if ( v198 == nullptr )
                  goto LABEL_178;
                v128 = v199;
                v62 = D3DXShader::CInstruction::Initialize(
                        this: v198,
                        a2: *(_DWORD *)v199 ^ (v192 ^ *(_DWORD *)v199) & 0xFFFFF,
                        a3: v177,
                        a4: v192,
                        a5: 0);
                if ( v62 < 0 || (v62 = D3DXShader::CInstruction::Instance(this: v198, a2: v128)) < 0 )
                {
                  v74 = v198;
                  goto LABEL_77;
                }
                v129 = v190;
                if ( v195 != v190 )
                {
                  v130 = v193;
                  for ( ii = 0; ii < *((_DWORD *)this + 2); ++ii )
                  {
                    v132 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * ii);
                    if ( v182 == v132[1] && v195 == v132[3] )
                    {
                      v132[3] = v129;
                      v132[4] += *(_DWORD *)(v130 + 4 * v129);
                    }
                  }
                  v133 = (_DWORD *)(v130 + 4 * v129);
                  v134 = (_DWORD *)(v130 + 4 * v195);
                  *v133 += *v134;
                  *v134 = 0;
                }
                v135 = *((char **)v200 + 4);
                v136 = v198;
                v137 = *((char **)v198 + 4);
                v138 = 4 * *((_DWORD *)v200 + 3);
                qmemcpy(v137, v135, 4 * (v138 >> 2));
                v140 = &v135[4 * (v138 >> 2)];
                v139 = &v137[4 * (v138 >> 2)];
                v141 = v138;
                v142 = v199;
                qmemcpy(v139, v140, v141 & 3);
                v143 = *((char **)v142 + 4);
                v144 = (char *)(*((_DWORD *)v136 + 4) + 4 * *((_DWORD *)v200 + 3));
                v145 = 4 * *((_DWORD *)v142 + 3);
                qmemcpy(v144, v143, 4 * (v145 >> 2));
                v147 = &v143[4 * (v145 >> 2)];
                v146 = &v144[4 * (v145 >> 2)];
                v148 = v145;
                v149 = v192;
                qmemcpy(v146, v147, v148 & 3);
                if ( (*(_DWORD *)v199 & 0xF0000000) == 0x10000000 )
                  qmemcpy(*((void **)v136 + 2), v185, 4 * v149);
                v150 = *(_DWORD *)v199 & 0xF0000000;
                if ( v150 == 0x20000000 )
                {
                  v151 = v185;
                  if ( v197 != 0 )
                    v151 = v176;
                  v152 = *((unsigned int **)v136 + 2);
                  v182 = 4 * v149;
                  qmemcpy(v152, v151, 4 * v149);
                  v153 = v178;
                  if ( v197 != 0 )
                    v153 = v175;
                  v154 = v182;
                  v155 = (unsigned int *)(v182 + *((_DWORD *)v136 + 2));
LABEL_166:
                  qmemcpy(v155, v153, v154);
                }
                else if ( v150 == 805306368 )
                {
                  qmemcpy(*((void **)v136 + 2), v185, 4 * v149);
                  v156 = (unsigned int *)(4 * v192 + *((_DWORD *)v136 + 2));
                  v157 = 4 * v192;
                  v158 = (4 * v192) >> 2;
                  qmemcpy(v156, v178, 4 * v158);
                  v160 = &v178[v158];
                  v159 = &v156[v158];
                  LOBYTE(v158) = v157;
                  v161 = v192;
                  qmemcpy(v159, v160, v158 & 3);
                  v154 = 4 * v161;
                  v153 = v174;
                  v155 = (unsigned int *)(*((_DWORD *)v136 + 2) + 8 * v161);
                  goto LABEL_166;
                }
                v162 = pMem;
                v163 = v198;
                pMem = (void *)(*((_DWORD *)pMem + 1) / (*(_DWORD *)pMem & 0xFFFFFu));
                D3DXShader::CProgram::SwizzleParameter(
                  this,
                  a2: *((unsigned int **)v198 + 4),
                  a3: v173,
                  a4: v192,
                  a5: 1);
                v193 = 0;
                if ( pMem != nullptr )
                {
                  do
                  {
                    D3DXShader::CProgram::SwizzleParameter(
                      this,
                      a2: (unsigned int *)(*((_DWORD *)v163 + 2) + 4 * v193 * *((_DWORD *)v163 + 3)),
                      a3: v173,
                      a4: v192,
                      a5: 0);
                    ++v193;
                  }
                  while ( v193 < (unsigned int)pMem );
                }
                if ( v180 != nullptr )
                  D3DXShader::CInstruction::`scalar deleting destructor'(this: v180, a2: 1);
                v164 = 4 * (_DWORD)n;
                *(_DWORD *)(v164 + *((_DWORD *)this + 6)) = v163;
                v193 = v164;
                *v162 = 0;
                v162[1] = 0;
                v162[3] = 0;
                v165 = *((_DWORD *)this + 3);
                if ( v165 > v188 )
                {
                  v180 = (D3DXShader::CInstruction *)(v165 - v188);
                  v190 = 4 * (v165 - v188);
                  pMem = MemAlloc_Alloc(nSize: v190);
                  if ( pMem == nullptr )
                    goto LABEL_178;
                  v166 = v188;
                  qmemcpy(pMem, (const void *)(*((_DWORD *)this + 6) + 4 * v188), v190);
                  memmove(
                    dst: (unsigned __int8 *)(*((_DWORD *)this + 6) + 4 * ((int)v180 + (_DWORD)n)),
                    src: (unsigned __int8 *)(*((_DWORD *)this + 6) + v193),
                    count: 4 * (v166 - (_DWORD)n));
                  v167 = pMem;
                  qmemcpy((void *)(v193 + *((_DWORD *)this + 6)), pMem, v190);
                  free(pMem: v167);
                }
                D3DXShader::CProgram::ReadWriteInfo(this);
                v179 = 1;
                v196 = (unsigned int)v189 - 1;
                goto LABEL_175;
              }
              goto LABEL_136;
            }
          }
          goto LABEL_136;
        }
        if ( v89 != 805306368 )
          goto LABEL_136;
        v112 = v86;
        qmemcpy(v185, *((const void **)v200 + 2), v112 * 4);
        v198 = *((D3DXShader::CInstruction **)v199 + 2);
        qmemcpy(&v185[v112], v198, 4 * v197);
        qmemcpy(v178, (const void *)(*((_DWORD *)v200 + 2) + v112 * 4), v112 * 4);
        v113 = (char *)v198 + 4 * v197;
        v114 = 4 * v197;
        v115 = (4 * v197) >> 2;
        qmemcpy(&v178[v112], v113, 4 * v115);
        v117 = &v113[4 * v115];
        v116 = &v178[v112 + v115];
        LOBYTE(v115) = v114;
        v118 = *((_DWORD *)v200 + 2);
        qmemcpy(v116, v117, v115 & 3);
        v172 = v187;
        qmemcpy(v174, (const void *)(v118 + 8 * v181), v112 * 4);
        qmemcpy(&v174[v112], (char *)v198 + 8 * v197, 4 * v197);
        v119 = D3DXShader::CProgram::CanVectorize(
                 this,
                 a2: v185,
                 a3: v192,
                 a4: nullptr,
                 a5: nullptr,
                 a6: v200,
                 a7: 0,
                 a8: v172);
        v181 = D3DXShader::CProgram::CanVectorize(
                 this,
                 a2: v178,
                 a3: v192,
                 a4: nullptr,
                 a5: nullptr,
                 a6: v200,
                 a7: 0,
                 a8: v187);
        CanVectorize = D3DXShader::CProgram::CanVectorize(
                         this,
                         a2: v174,
                         a3: v192,
                         a4: nullptr,
                         a5: nullptr,
                         a6: v200,
                         a7: 0,
                         a8: v187);
        if ( v119 == 0 || v181 == 0 )
          goto LABEL_136;
      }
      if ( CanVectorize != 0 )
        goto LABEL_133;
    }
LABEL_136:
    v125 = v188;
    while ( *((_DWORD *)this + 3) > v125 )
    {
      --*((_DWORD *)this + 3);
      v126 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)this + 3));
      if ( v126 != nullptr )
        D3DXShader::CInstruction::`scalar deleting destructor'(this: v126, a2: 1);
    }
    goto LABEL_140;
  }
  while ( 1 )
  {
    v29 = *((_DWORD *)this + 6);
    v30 = *(struct D3DXShader::CInstruction **)(v29 + 4 * (_DWORD)v199);
    v4 = *(_DWORD *)v30 == 541065217;
    n = v30;
    if ( v4 )
    {
      v31 = *((_DWORD **)v30 + 2);
      v32 = *((_DWORD *)this + 5);
      v33 = *(_DWORD *)(v32 + 4 * *v31);
      v34 = *(_DWORD *)(v33 + 4);
      pMem = *(void **)(v32 + 4 * v31[1]);
      v35 = *((_DWORD *)this + 4);
      if ( (*(_BYTE *)(*(_DWORD *)(v35 + 4 * v34) + 4) & 2) != 0
        && (*(_BYTE *)(*(_DWORD *)(v35 + 4 * *((_DWORD *)pMem + 1)) + 4) & 2) != 0 )
      {
        v36 = *(_DWORD *)(v29 + 4 * *(_DWORD *)(v33 + 72));
        v37 = *(_DWORD *)(v29 + 4 * *((_DWORD *)pMem + 18));
        v38 = *(_DWORD *)v36;
        v4 = *(_DWORD *)v36 == 542113793;
        v195 = v36;
        v197 = v37;
        if ( (v4 || (v38 & 0xFFF00000) == 0x50000000)
          && (*(_DWORD *)v37 == 542113793 || (*(_DWORD *)v37 & 0xFFF00000) == 0x50000000) )
        {
          v39 = *(_DWORD *)(v36 + 4);
          pMem = (void *)(*(_DWORD *)(v37 + 4) >> 1);
          v40 = v39 >> 1;
          v196 = (unsigned int)pMem + v40;
          if ( (unsigned int)pMem + v40 >= (~(unsigned __int8)*((_DWORD *)this + 27) & 0x20 | 0x40u) >> 5 && v196 <= 4 )
          {
            v41 = *(_DWORD *)(v32 + 4 * **(_DWORD **)(v36 + 16));
            if ( v199 == *(struct D3DXShader::CInstruction **)(v41 + 84)
              && v199 == *(struct D3DXShader::CInstruction **)(v41 + 88) )
            {
              v42 = *(_DWORD *)(v32 + 4 * **(_DWORD **)(v37 + 16));
              if ( v199 == *(struct D3DXShader::CInstruction **)(v42 + 84)
                && v199 == *(struct D3DXShader::CInstruction **)(v42 + 88) )
              {
                v43 = 4 * v40;
                v190 = *(_DWORD *)(v195 + 8);
                qmemcpy(v178, (const void *)v190, v43);
                v44 = *(D3DXShader::CInstruction **)(v197 + 8);
                v193 = 4 * (_DWORD)pMem;
                v45 = 4 * (_BYTE)pMem;
                v46 = (unsigned int)(4 * (_DWORD)pMem) >> 2;
                v186 = v44;
                qmemcpy(&v178[v43 / 4], v44, 4 * v46);
                v48 = (char *)v44 + 4 * v46;
                v47 = &v178[v43 / 4 + v46];
                LOBYTE(v46) = v45;
                v49 = v190;
                qmemcpy(v47, v48, v46 & 3);
                qmemcpy(v175, (const void *)(v49 + v43), 4 * (v43 >> 2));
                v50 = (const void *)(v49 + v43 + 4 * (v43 >> 2));
                v51 = v186;
                qmemcpy(&v175[v43 >> 2], v50, v43 & 3);
                v188 = v43;
                qmemcpy(&v175[v43 / 4], (char *)v51 + v193, v193);
                if ( D3DXShader::CProgram::CanVectorize(
                       this,
                       a2: v178,
                       a3: v196,
                       a4: nullptr,
                       a5: nullptr,
                       a6: n,
                       a7: 0,
                       a8: 0xFFFFFFFF) != 0
                  && D3DXShader::CProgram::CanVectorize(
                       this,
                       a2: v175,
                       a3: v196,
                       a4: nullptr,
                       a5: nullptr,
                       a6: n,
                       a7: 0,
                       a8: 0xFFFFFFFF) != 0 )
                {
                  v188 = 0;
                  goto LABEL_54;
                }
                v52 = *(char **)(v195 + 8);
                qmemcpy(v185, v52, v188);
                v53 = (char *)(*(_DWORD *)(v197 + 8) + v193);
                v54 = (char *)v185 + v188;
                v186 = *(D3DXShader::CInstruction **)(v197 + 8);
                v55 = v193;
                v56 = v193 >> 2;
                qmemcpy((char *)v185 + v188, v53, 4 * (v193 >> 2));
                v58 = &v53[4 * v56];
                v57 = &v54[4 * v56];
                LOBYTE(v56) = v55;
                v59 = v188;
                qmemcpy(v57, v58, v56 & 3);
                qmemcpy(v176, &v52[v59], v59);
                qmemcpy((char *)v176 + v59, v186, v193);
                if ( D3DXShader::CProgram::CanVectorize(
                       this,
                       a2: v185,
                       a3: v196,
                       a4: nullptr,
                       a5: nullptr,
                       a6: n,
                       a7: 0,
                       a8: 0xFFFFFFFF) != 0
                  && D3DXShader::CProgram::CanVectorize(
                       this,
                       a2: v176,
                       a3: v196,
                       a4: nullptr,
                       a5: nullptr,
                       a6: n,
                       a7: 0,
                       a8: 0xFFFFFFFF) != 0 )
                {
                  break;
                }
              }
            }
          }
        }
      }
    }
LABEL_65:
    v199 = (struct D3DXShader::CInstruction *)((char *)v199 + 1);
    if ( (unsigned int)v199 >= *((_DWORD *)this + 3) )
      goto LABEL_66;
  }
  v188 = 1;
LABEL_54:
  v60 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v60 != nullptr )
    v189 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v60);
  else
    v189 = nullptr;
  if ( v189 == nullptr )
    goto LABEL_178;
  v61 = v189;
  v62 = D3DXShader::CInstruction::Initialize(this: v189, a2: v196 & 0xFFFFF | 0x50000000, a3: 2 * v196, a4: 1u, a5: 0);
  if ( v62 >= 0 )
  {
    v62 = D3DXShader::CInstruction::Instance(this: v61, a2: n);
    if ( v62 >= 0 )
    {
      v4 = v188 == 0;
      **((_DWORD **)v61 + 4) = **((_DWORD **)n + 4);
      v63 = v178;
      if ( !v4 )
        v63 = v185;
      v64 = 4 * v196;
      qmemcpy(*((void **)v189 + 2), v63, 4 * v196);
      v65 = v175;
      if ( v188 != 0 )
        v65 = v176;
      v66 = v189;
      qmemcpy((void *)(v64 + *((_DWORD *)v189 + 2)), v65, v64);
      *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (_DWORD)v199) = v66;
      D3DXShader::CInstruction::`scalar deleting destructor'(this: n, a2: 1);
      *(_DWORD *)v195 = 0;
      *(_DWORD *)v197 = 0;
      goto LABEL_65;
    }
  }
  v74 = v61;
LABEL_77:
  D3DXShader::CInstruction::`scalar deleting destructor'(this: v74, a2: 1);
LABEL_177:
  free(pMem: v184);
  return v62;
}

//------------------------------------------------------------------------------
// Address: 0x101F332C
// Name: protected: long D3DXShader::CProgram::VectorizeLiterals(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::VectorizeLiterals(D3DXShader::CProgram *this)
{
  unsigned int v1; // esi
  bool v3; // zf
  int v4; // ecx
  int v5; // edi
  int v6; // edx
  unsigned int v7; // edi
  unsigned int v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  unsigned int j; // edx
  _DWORD *v16; // eax
  unsigned int *v17; // ecx
  unsigned int i; // ecx
  _DWORD *v19; // eax
  bool v20; // cf
  unsigned int k; // edx
  int v22; // eax
  int v23; // ecx
  unsigned int Inputs; // eax
  _DWORD *v25; // esi
  int v26; // edi
  int v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // edx
  unsigned int v30; // ecx
  int v31; // eax
  unsigned int v32; // esi
  unsigned int n; // eax
  int v34; // ecx
  unsigned int m; // eax
  int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // edx
  int v39; // esi
  unsigned int v40; // ecx
  unsigned int v41; // edx
  _DWORD *v42; // eax
  int v43; // ecx
  int v44; // esi
  int v45; // ecx
  int v46; // eax
  int v47; // eax
  unsigned int ii; // edx
  _DWORD *v49; // eax
  int v50; // ecx
  int v51; // ecx
  unsigned int v52; // eax
  void *v53; // [esp-4h] [ebp-74h]
  _BYTE v54[16]; // [esp+Ch] [ebp-64h] BYREF
  unsigned int v55[4]; // [esp+1Ch] [ebp-54h] BYREF
  unsigned int v56[4]; // [esp+2Ch] [ebp-44h] BYREF
  unsigned int *v57; // [esp+3Ch] [ebp-34h] BYREF
  int v58; // [esp+40h] [ebp-30h]
  unsigned int *v59; // [esp+44h] [ebp-2Ch] BYREF
  unsigned int v60; // [esp+48h] [ebp-28h]
  unsigned int v61; // [esp+4Ch] [ebp-24h]
  unsigned int v62; // [esp+50h] [ebp-20h]
  unsigned int v63; // [esp+54h] [ebp-1Ch]
  unsigned int *v64; // [esp+58h] [ebp-18h] BYREF
  _DWORD *v65; // [esp+5Ch] [ebp-14h]
  unsigned int v66; // [esp+60h] [ebp-10h]
  D3DXShader::CInstruction *v67; // [esp+64h] [ebp-Ch]
  unsigned int v68; // [esp+68h] [ebp-8h]
  void *pMem; // [esp+6Ch] [ebp-4h]

  v1 = 0;
  v3 = *((_DWORD *)this + 1) == 0;
  v63 = 0;
  if ( !v3 )
  {
    v4 = *((_DWORD *)this + 4);
    v5 = *((_DWORD *)this + 1);
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)v4 + 4);
      if ( (v6 & 0x100) != 0 && (v6 & 0xC00) != 0 )
        v1 += *(_DWORD *)(*(_DWORD *)v4 + 8);
      v4 += 4;
      --v5;
    }
    while ( v5 != 0 );
    v63 = v1;
  }
  v7 = 16 * (v1 + 2 * *((_DWORD *)this + 3));
  pMem = MemAlloc_Alloc(nSize: v7);
  if ( pMem == nullptr )
    return -2147024882;
  memset(pMem, 0xFFu, v7);
  v9 = 0;
  v58 = 0;
  D3DXShader::CProgram::IdentityRemap(this);
  v3 = *((_DWORD *)this + 1) == 0;
  v66 = 0;
  if ( !v3 )
  {
    do
    {
      v64 = *(unsigned int **)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v9) + 4);
      if ( (BYTE1(v64) & 1) != 0 && (BYTE1(v64) & 0xC) != 0 )
      {
        v68 = 0;
        if ( v63 != 0 )
        {
          v10 = *((_DWORD *)this + 2);
          do
          {
            v11 = 0;
            if ( v10 != 0 )
            {
              v12 = *((_DWORD *)this + 5);
              do
              {
                v13 = *(_DWORD *)(v12 + 4 * v11);
                if ( *(_DWORD *)(v13 + 4) == v9 && *(_DWORD *)(v13 + 8) == -1 )
                {
                  v14 = *((_DWORD *)pMem + 4 * v68 + 4 * *(_DWORD *)(v13 + 12) + *(_DWORD *)(v13 + 16));
                  if ( v14 != -1
                    && ((BYTE1(v64) & 8) != 0 || *(double *)(v13 + 32) != *(double *)(*(_DWORD *)(v12 + 4 * v14) + 32)) )
                  {
                    v9 = v66;
                    break;
                  }
                  v9 = v66;
                }
                ++v11;
              }
              while ( v11 < *((_DWORD *)this + 2) );
            }
            v10 = *((_DWORD *)this + 2);
            if ( v11 == v10 )
              break;
            ++v68;
          }
          while ( v68 < v63 );
        }
        if ( (BYTE1(v64) & 8) != 0 )
        {
          for ( i = 0; i < *((_DWORD *)this + 2); ++i )
          {
            v19 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * i);
            if ( v19[1] == v9 )
              *((_DWORD *)pMem + 4 * v68 + 4 * v19[3] + v19[4]) = i;
          }
        }
        else
        {
          for ( j = 0; j < *((_DWORD *)this + 2); ++j )
          {
            v16 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * j);
            if ( v16[1] == v9 )
            {
              v16[3] += v68;
              if ( v16[2] == -1 )
              {
                v17 = (unsigned int *)((char *)pMem + 16 * v16[3] + 4 * v16[4]);
                if ( *v17 == -1 )
                {
                  *v17 = j;
                }
                else
                {
                  v16[1] = *((_DWORD *)this + 29);
                  v16[12] = *v17;
                  v58 = 1;
                }
              }
            }
          }
        }
      }
      v20 = ++v9 < *((_DWORD *)this + 1);
      v66 = v9;
    }
    while ( v20 );
    if ( v58 != 0 )
      D3DXShader::CProgram::RemapArguments(this);
  }
  for ( k = 0; k < *((_DWORD *)this + 2); ++k )
  {
    v22 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * k);
    v23 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v22 + 4)) + 4);
    if ( (v23 & 0x100) != 0 && (v23 & 0xC00) == 0 )
    {
      *(_DWORD *)(v22 + 12) = -1;
      *(_DWORD *)(v22 + 4) = *((_DWORD *)this + 30);
    }
  }
  v3 = *((_DWORD *)this + 3) == 0;
  v63 = 0;
  if ( !v3 )
  {
    do
    {
      v3 = (*(_WORD *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * v63) + 2) & 0xFFF0) == 0;
      v67 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v63);
      if ( !v3 )
      {
        memset(v56, 255, sizeof(v56));
        memset(v55, 0, sizeof(v55));
        v68 = 0;
        v60 = 0;
        v62 = 0;
        Inputs = D3DXShader::CInstruction::GetInputs(this: v67, a2: 0, a3: &v64);
        v61 = Inputs;
        if ( Inputs != 0 )
        {
          v25 = v54;
          v65 = v54;
          while ( 1 )
          {
            v26 = *((_DWORD *)this + 5);
            v27 = *(_DWORD *)(v26 + 4 * *v64);
            if ( *((_DWORD *)this + 30) == *(_DWORD *)(v27 + 4) && *(_DWORD *)(v27 + 8) == -1 )
            {
              *v25 = (~(unsigned __int8)*((_DWORD *)this + 27) & 4) != 0;
              v28 = 1;
              if ( Inputs > 1 )
              {
                do
                {
                  if ( *v25 == 0 )
                    break;
                  if ( *(double *)(v27 + 32) != *(double *)(*(_DWORD *)(v26 + 4 * v64[v28]) + 32) )
                    *v25 = 0;
                  Inputs = v61;
                  ++v28;
                }
                while ( v28 < v61 );
              }
              v66 = 0;
              if ( Inputs != 0 )
              {
                while ( 1 )
                {
                  v29 = v64[v66];
                  v30 = 0;
                  if ( v68 != 0 )
                  {
                    do
                    {
                      if ( *(double *)(*(_DWORD *)(v26 + 4 * v56[v30]) + 32) == *(double *)(*(_DWORD *)(v26 + 4 * v29)
                                                                                          + 32) )
                        break;
                      ++v30;
                    }
                    while ( v30 < v68 );
                    if ( v30 == 4 )
                      break;
                  }
                  if ( v30 == v68 )
                  {
                    v31 = v68++;
                    v56[v31] = v29;
                  }
                  if ( *v65 == 0 )
                    v55[v30] |= 1 << v66;
                  if ( ++v66 >= v61 )
                    goto LABEL_72;
                }
                v60 = 1;
LABEL_72:
                v25 = v65;
              }
              if ( v60 != 0 )
                break;
            }
            ++v62;
            v65 = ++v25;
            Inputs = D3DXShader::CInstruction::GetInputs(this: v67, a2: v62, a3: &v64);
            v61 = Inputs;
            if ( Inputs == 0 )
            {
              if ( v60 != 0 )
                break;
              goto LABEL_76;
            }
          }
LABEL_83:
          v60 = 0;
          for ( m = D3DXShader::CInstruction::GetInputs(this: v67, a2: 0, a3: &v59);
                ;
                m = D3DXShader::CInstruction::GetInputs(this: v67, a2: v60, a3: &v59) )
          {
            v66 = m;
            if ( m == 0 )
              break;
            v36 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v59);
            if ( *((_DWORD *)this + 30) == *(_DWORD *)(v36 + 4) && *(_DWORD *)(v36 + 8) == -1 )
            {
              v37 = v66;
              v38 = 0;
              if ( v66 != 0 )
              {
                qmemcpy(v56, v59, 4 * v66);
                do
                {
                  v39 = 1 << v38++;
                  *(_DWORD *)&v54[4 * v38 + 12] = v39;
                }
                while ( v38 < v37 );
              }
              if ( v37 < 4 )
              {
                v40 = (4 * (4 - v37)) >> 2;
                memset(&v55[v37], 0, 4 * v40);
                memset(&v56[v37], 0xFFu, 4 * v40);
              }
              D3DXShader::CProgram::CompactLiterals(this, a2: (unsigned int *)pMem, a3: v56, a4: v55);
              D3DXShader::CProgram::CompactLiterals_Remap(this, a2: v56, a3: v59, a4: v66);
            }
            ++v60;
          }
          goto LABEL_94;
        }
LABEL_76:
        if ( D3DXShader::CProgram::CompactLiterals(this, a2: (unsigned int *)pMem, a3: v56, a4: v55) < 0 )
          goto LABEL_83;
        v32 = 0;
        for ( n = D3DXShader::CInstruction::GetInputs(this: v67, a2: 0, a3: &v57);
              n != 0;
              n = D3DXShader::CInstruction::GetInputs(this: v67, a2: v32, a3: &v57) )
        {
          v34 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v57);
          if ( *((_DWORD *)this + 30) == *(_DWORD *)(v34 + 4) && *(_DWORD *)(v34 + 8) == -1 )
            D3DXShader::CProgram::CompactLiterals_Remap(this, a2: v56, a3: v57, a4: n);
          ++v32;
        }
      }
LABEL_94:
      ++v63;
    }
    while ( v63 < *((_DWORD *)this + 3) );
  }
  v41 = 0;
  v3 = *((_DWORD *)this + 2) == 0;
  v57 = nullptr;
  if ( !v3 )
  {
    do
    {
      v42 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v41);
      v43 = v42[1];
      v44 = *((_DWORD *)this + 30);
      if ( v44 == v43 && v42[3] == -1 )
      {
        v42[1] = *((_DWORD *)this + 29);
      }
      else
      {
        v45 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v43) + 4);
        if ( (v45 & 0x100) != 0 && (v45 & 0x40) != 0 && (v45 & 0x800) == 0 )
        {
          v3 = v42[2] == -1;
          v42[1] = v44;
          if ( !v3 )
            v57 = (unsigned int *)1;
        }
      }
      ++v41;
    }
    while ( v41 < *((_DWORD *)this + 2) );
  }
  v46 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 30));
  *(_DWORD *)(v46 + 4) |= 0x40u;
  if ( v57 != nullptr )
  {
    v47 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 30));
    *(_BYTE *)(v47 + 5) |= 4u;
  }
  *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 30)) + 8) = 0;
  for ( ii = 0; ii < *((_DWORD *)this + 2); ++ii )
  {
    v49 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * ii);
    v50 = *((_DWORD *)this + 30);
    if ( v50 == v49[1] && v49[2] == -1 )
    {
      v51 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v50);
      v52 = v49[3];
      if ( *(_DWORD *)(v51 + 8) <= v52 )
        *(_DWORD *)(v51 + 8) = v52 + 1;
    }
  }
  if ( v58 != 0 )
    D3DXShader::CProgram::RemoveDuplicateArguments(this);
  v53 = pMem;
  *((_DWORD *)this + 55) = 1;
  free(pMem: v53);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F3886
// Name: protected: long D3DXShader::CProgram::SeparatePhases(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::SeparatePhases(D3DXShader::CProgram *this)
{
  bool v2; // zf
  int result; // eax
  void *v4; // eax
  unsigned int v5; // eax
  D3DXShader::CProgram *v6; // ecx
  unsigned int v7; // eax
  char *v8; // esi
  char *v9; // edi
  unsigned int v10; // eax
  char *v11; // edi
  char *v12; // esi
  char v13; // cl
  unsigned int v14; // eax
  bool v15; // cf
  unsigned int v16; // edx
  unsigned int v17; // eax
  int v18; // ecx
  unsigned int v19; // esi
  int v20; // eax
  int v21; // edx
  int v22; // eax
  unsigned int v23; // edx
  int v24; // eax
  int v25; // ecx
  unsigned int v26; // edx
  int *v27; // edx
  int v28; // edi
  _BYTE v29[100]; // [esp+8h] [ebp-78h] BYREF
  unsigned int v30; // [esp+6Ch] [ebp-14h]
  unsigned int i; // [esp+70h] [ebp-10h]
  unsigned int j; // [esp+74h] [ebp-Ch]
  unsigned int v33; // [esp+78h] [ebp-8h]
  void *pMem; // [esp+7Ch] [ebp-4h]

  v2 = (*((_BYTE *)this + 111) & 0xC) == 0;
  pMem = nullptr;
  if ( v2 )
    return 1;
  result = D3DXShader::CProgram::CompactInstructions(this);
  if ( result >= 0 )
  {
    if ( D3DXShader::CProgram::CompactPool_Begin(
           this,
           a2: (struct D3DXShader::_D3DXCP_DATA *)v29,
           a3: *((_DWORD *)this + 34),
           a4: *((_DWORD *)this + 11) - 1) >= 0
      && D3DXShader::CProgram::CompactPool_Process(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v29, a3: 0) >= 0
      || (D3DXShader::CProgram::CompactPool_End(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v29),
          D3DXShader::CProgram::CompactPool_Begin(
            this,
            a2: (struct D3DXShader::_D3DXCP_DATA *)v29,
            a3: *((_DWORD *)this + 34),
            a4: *((_DWORD *)this + 11)) >= 0)
      && D3DXShader::CProgram::CompactPool_Process(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v29, a3: 0) >= 0 )
    {
      v4 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 3));
      pMem = v4;
      if ( v4 != nullptr )
      {
        qmemcpy(v4, *((const void **)this + 6), 4 * *((_DWORD *)this + 3));
        j = D3DXShader::CProgram::SeparatePhases_Phases(this);
        v5 = 0;
        v2 = *((_DWORD *)this + 3) == 0;
        i = 0;
        if ( !v2 )
        {
          do
          {
            if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * v5) + 44) & 1) != 0 )
            {
              v33 = v5;
              if ( v5 != 0 )
              {
                do
                {
                  if ( D3DXShader::CProgram::SeparatePhases_MoveTex(this, a2: v33) == 0 )
                    break;
                  v7 = D3DXShader::CProgram::SeparatePhases_Phases(this: v6);
                  v30 = v7;
                  if ( v7 <= j
                    && (v7 != j
                     || (*((_BYTE *)this + 111) & 8) == 0
                     && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * v33) + 44) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * v33 - 4) + 44))
                    && D3DXShader::CProgram::CompactPool_Process(
                         this,
                         a2: (struct D3DXShader::_D3DXCP_DATA *)v29,
                         a3: 0) >= 0 )
                  {
                    v8 = *((char **)this + 6);
                    v9 = (char *)pMem;
                    v10 = 4 * i + 4;
                    qmemcpy(pMem, v8, 4 * (v10 >> 2));
                    v12 = &v8[4 * (v10 >> 2)];
                    v11 = &v9[4 * (v10 >> 2)];
                    v13 = v10;
                    v14 = v30;
                    qmemcpy(v11, v12, v13 & 3);
                    j = v14;
                  }
                  --v33;
                }
                while ( v33 != 0 );
                v5 = i;
              }
              qmemcpy(*((void **)this + 6), pMem, 4 * v5 + 4);
            }
            v15 = ++v5 < *((_DWORD *)this + 3);
            i = v5;
          }
          while ( v15 );
        }
        v16 = *((_DWORD *)this + 3);
        v17 = 0;
        for ( i = 0; v17 < v16; i = v17 )
        {
          v18 = 4 * v17;
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * v17) + 44) & 1) != 0 )
          {
            v19 = v17 + 1;
            if ( v17 + 1 < v16 )
            {
              v20 = *((_DWORD *)this + 6);
              v21 = *(_DWORD *)(*(_DWORD *)(v20 + v18) + 44);
              v22 = v20 + 4 * v19;
              do
              {
                if ( v21 != *(_DWORD *)(*(_DWORD *)v22 + 44) )
                  break;
                ++v19;
                v22 += 4;
              }
              while ( v19 < *((_DWORD *)this + 3) );
              v17 = i;
            }
            v23 = (v19 - v17) >> 1;
            if ( v23 != 0 )
            {
              i = v18;
              v24 = 4 * v19;
              for ( j = v23; j != 0; --j )
              {
                v25 = *((_DWORD *)this + 6);
                v26 = i;
                i += 4;
                v27 = (int *)(v25 + v26);
                v28 = *v27;
                *v27 = *(_DWORD *)(v24 + v25 - 4);
                *(_DWORD *)(v24 + *((_DWORD *)this + 6) - 4) = v28;
                v24 -= 4;
              }
            }
            v17 = v19 - 1;
          }
          v16 = *((_DWORD *)this + 3);
          ++v17;
        }
      }
    }
    D3DXShader::CProgram::CompactPool_End(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v29);
    free(pMem);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F3ABA
// Name: protected: long D3DXShader::CProgram::CompactRegisters(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CompactRegisters(D3DXShader::CProgram *this)
{
  int result; // eax
  unsigned int v3; // eax
  int v4; // edi
  bool v5; // zf
  _DWORD *v6; // eax
  int v7; // ecx
  int v8; // ebx
  int v9; // edx
  int v10; // ecx
  int v11; // edi
  _DWORD *v12; // edx
  _DWORD *v13; // ecx
  int v14; // ecx
  int v15; // ecx
  D3DXShader::CProgram *v16; // ecx
  _BYTE v17[100]; // [esp+8h] [ebp-7Ch] BYREF
  int v18; // [esp+6Ch] [ebp-18h]
  int v19; // [esp+70h] [ebp-14h]
  int v20; // [esp+74h] [ebp-10h]
  int v21; // [esp+78h] [ebp-Ch]
  unsigned int v22; // [esp+7Ch] [ebp-8h]
  unsigned int v23; // [esp+80h] [ebp-4h]

  result = D3DXShader::CProgram::CombinePools(this, a2: *((_DWORD *)this + 34), a3: 3u, a4: 0x20400u);
  if ( result >= 0 )
  {
    result = D3DXShader::CProgram::CombinePools(this, a2: *((_DWORD *)this + 35), a3: 6u, a4: 0x401u);
    if ( result >= 0 )
    {
      result = D3DXShader::CProgram::CombinePools(this, a2: *((_DWORD *)this + 36), a3: 0xAu, a4: 0x4401u);
      if ( result >= 0
        && ((v3 = *((_DWORD *)this + 50) & 0xFFFF0000) != 1180172288 && v3 != 1415053312
         || (result = D3DXShader::CProgram::CombinePools(this, a2: *((_DWORD *)this + 34), a3: 2u, a4: 0x31028u)) >= 0)
        && ((*((_DWORD *)this + 50) & 0xFFFF0000) == 0xFFFE0000
         || (result = D3DXShader::CProgram::CombinePools(this, a2: *((_DWORD *)this + 32), a3: 0x10u, a4: 0x200u)) >= 0) )
      {
        result = D3DXShader::CProgram::CombinePools(this, a2: *((_DWORD *)this + 33), a3: 0x20u, a4: 0x42000u);
        if ( result >= 0 )
        {
          result = D3DXShader::CProgram::CombinePools(this, a2: *((_DWORD *)this + 45), a3: 0x2020u, a4: 0x40000u);
          if ( result >= 0 )
          {
            result = D3DXShader::CProgram::CombinePools(this, a2: *((_DWORD *)this + 46), a3: 0x40020u, a4: 0x2000u);
            if ( result >= 0
              && ((*((_DWORD *)this + 50) & 0xFFFF0000) == 0xFFFF0000
               || (result = D3DXShader::CProgram::CombinePools(this, a2: *((_DWORD *)this + 37), a3: 0x80u, a4: 0)) >= 0) )
            {
              if ( *((_DWORD *)this + 12) == 0 )
                goto LABEL_22;
              result = D3DXShader::CProgram::CompactPool_Begin(
                         this,
                         a2: (struct D3DXShader::_D3DXCP_DATA *)v17,
                         a3: *((_DWORD *)this + 35),
                         a4: *((_DWORD *)this + 12));
              if ( result < 0 )
                return result;
              if ( D3DXShader::CProgram::CompactPool_Process(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v17, a3: 0) >= 0 )
              {
                D3DXShader::CProgram::CompactPool_Process(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v17, a3: 1);
              }
              else
              {
                v4 = D3DXShader::CProgram::CombinePools(this, a2: *((_DWORD *)this + 34), a3: 2u, a4: 0x30028u);
                if ( v4 < 0 )
                {
LABEL_18:
                  D3DXShader::CProgram::CompactPool_End(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v17);
                  return v4;
                }
              }
              result = D3DXShader::CProgram::CompactPool_End(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v17);
              if ( result >= 0 )
              {
LABEL_22:
                v4 = D3DXShader::CProgram::CompactPool_Begin(
                       this,
                       a2: (struct D3DXShader::_D3DXCP_DATA *)v17,
                       a3: *((_DWORD *)this + 34),
                       a4: *((_DWORD *)this + 11));
                if ( v4 < 0 )
                  goto LABEL_18;
                v4 = D3DXShader::CProgram::CompactPool_Process(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v17, a3: 1);
                if ( v4 < 0 )
                  goto LABEL_18;
                v4 = D3DXShader::CProgram::CompactPool_End(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v17);
                if ( v4 < 0 )
                  goto LABEL_18;
                v4 = D3DXShader::CProgram::CompactPool_Begin(
                       this,
                       a2: (struct D3DXShader::_D3DXCP_DATA *)v17,
                       a3: *((_DWORD *)this + 36),
                       a4: *((_DWORD *)this + 13));
                if ( v4 < 0 )
                  goto LABEL_18;
                v4 = D3DXShader::CProgram::CompactPool_Process(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v17, a3: 1);
                if ( v4 < 0 )
                  goto LABEL_18;
                v4 = D3DXShader::CProgram::CompactPool_End(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v17);
                if ( v4 < 0 )
                  goto LABEL_18;
                if ( (*((_BYTE *)this + 204) & 4) != 0 )
                  return 0;
                v20 = 0;
                D3DXShader::CProgram::IdentityRemap(this);
                v5 = *((_DWORD *)this + 3) == 0;
                v22 = 0;
                if ( v5 )
                  return 0;
                do
                {
                  v6 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v22);
                  if ( (*v6 & 0xFFF00000) == 0x10000000 )
                  {
                    v7 = 0;
                    v5 = v6[3] == 0;
                    v21 = 0;
                    v23 = 0;
                    if ( !v5 )
                    {
                      do
                      {
                        v8 = v6[2];
                        v9 = *(_DWORD *)(v6[4] + 4 * v23);
                        v10 = *((_DWORD *)this + 5);
                        v18 = 4 * v23;
                        v11 = *(_DWORD *)(4 * v23 + v8);
                        v19 = v9;
                        v12 = *(_DWORD **)(v10 + 4 * v9);
                        v13 = *(_DWORD **)(v10 + 4 * v11);
                        if ( v12[1] == v13[1]
                          && v12[2] == v13[2]
                          && v12[3] == v13[3]
                          && v12[4] == v13[4]
                          && v12[5] == v13[5]
                          && v12[6] == v13[6]
                          && v12[15] == 0
                          && v13[15] == 0 )
                        {
                          v14 = -1;
                          if ( v11 != -1 )
                            v14 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v11) + 48);
                          v12[12] = v14;
                          v7 = v21;
                        }
                        else
                        {
                          v15 = v21;
                          *(_DWORD *)(v6[4] + 4 * v21) = v19;
                          *(_DWORD *)(v6[2] + 4 * v15) = *(_DWORD *)(v6[2] + v18);
                          v7 = v15 + 1;
                          v21 = v7;
                        }
                        ++v23;
                      }
                      while ( v23 < v6[3] );
                    }
                    if ( v7 != v6[3] )
                    {
                      *v6 = v7 != 0 ? v7 & 0xFFFFF | 0x10000000 : 0;
                      v6[1] = v7;
                      v6[3] = v7;
                      v20 = 1;
                    }
                  }
                  ++v22;
                }
                while ( v22 < *((_DWORD *)this + 3) );
                if ( v20 == 0 )
                  return 0;
                result = D3DXShader::CProgram::RemapArguments(this);
                if ( result >= 0 )
                {
                  result = D3DXShader::CProgram::CompactArguments(this: v16);
                  if ( result >= 0 )
                  {
                    result = D3DXShader::CProgram::CompactInstructions(this);
                    if ( result >= 0 )
                      return 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F3E54
// Name: protected: long D3DXShader::CProgram::Optimize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::Optimize(D3DXShader::CProgram *this)
{
  int result; // eax
  unsigned int i; // ecx
  int *v4; // eax
  BOOL v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  unsigned int k; // edx
  _DWORD *v14; // eax
  int v15; // ecx
  int v16; // ecx
  unsigned int j; // [esp+8h] [ebp-4h]

  result = D3DXShader::CProgram::Validate(this);
  if ( result >= 0 )
  {
    result = D3DXShader::CProgram::RemoveDeadCode(this);
    if ( result >= 0 )
    {
      result = D3DXShader::CProgram::RemoveDuplicateArguments(this);
      if ( result >= 0 )
      {
        result = D3DXShader::CProgram::CompactInstructions(this);
        if ( result >= 0 )
        {
          result = D3DXShader::CProgram::CompactArguments(this);
          if ( result >= 0 )
          {
            for ( i = 0; i < *((_DWORD *)this + 3); ++i )
            {
              v4 = *(int **)(*((_DWORD *)this + 6) + 4 * i);
              if ( (_UNKNOWN *)(*v4 & 0xFFF00000) == (_UNKNOWN *)((char *)&loc_101FFFFF + 1) )
                *v4 = v4[3] & 0xFFFFF | 0x10000000;
            }
            if ( (*((_BYTE *)this + 204) & 4) != 0 )
            {
              *((_DWORD *)this + 54) = 1;
              return 0;
            }
            else
            {
              result = D3DXShader::CProgram::VectorizeLeft(this);
              if ( result >= 0 )
              {
                result = D3DXShader::CProgram::DelayOutputs(this);
                if ( result >= 0 )
                {
                  for ( j = 0; j < 0x100; ++j )
                  {
                    result = D3DXShader::CProgram::SimplifyInstructions(this);
                    if ( result != 0 )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v5 = result == 0;
                    result = D3DXShader::CProgram::RemoveDeadCode(this);
                    if ( result != 0 )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v6 = result == 0 || v5;
                    result = D3DXShader::CProgram::SquishInstructions(this);
                    if ( result != 0 )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v7 = (result == 0) | v6;
                    result = D3DXShader::CProgram::RemoveDuplicateInstructions(this, a2: (const void *)v7, a3: 0);
                    if ( result != 0 )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v8 = (result == 0) | v7;
                    result = D3DXShader::CProgram::MergeInstructions(this);
                    if ( result != 0 )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v9 = (result == 0) | v8;
                    result = D3DXShader::CProgram::ReorderBinary(this);
                    if ( result != 0 )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v10 = (result == 0) | v9;
                    result = D3DXShader::CProgram::SimplifyAddresses(this);
                    if ( result != 0 )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v11 = (result == 0) | v10;
                    result = D3DXShader::CProgram::SimplifyPredicates(this);
                    if ( result != 0 )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v12 = (result == 0) | v11;
                    result = D3DXShader::CProgram::PropagatePredicates(this);
                    if ( result != 0 )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    if ( (v12 | (result == 0)) == 0 )
                      break;
                  }
                  if ( j == 256 )
                    D3DXShader::CProgram::Warning(
                      this,
                      a2: nullptr,
                      a3: 0,
                      format: "internal warning: optimization did not converge");
                  for ( k = 0; k < *((_DWORD *)this + 2); ++k )
                  {
                    v14 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * k);
                    v15 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v14[1]) + 4);
                    if ( (v15 & 0x100) != 0 && (v15 & 0xC00) == 0 )
                    {
                      v16 = *((_DWORD *)this + 30);
                      v14[3] = -1;
                      v14[4] = -1;
                      v14[1] = v16;
                    }
                  }
                  result = D3DXShader::CProgram::Split(this);
                  if ( result >= 0 )
                  {
                    result = D3DXShader::CProgram::CompactOutputs(this);
                    if ( result >= 0 )
                    {
                      result = D3DXShader::CProgram::RemoveDuplicateArguments(this);
                      if ( result >= 0 )
                      {
                        result = D3DXShader::CProgram::CompactInstructions(this);
                        if ( result >= 0 )
                        {
                          result = D3DXShader::CProgram::CompactArguments(this);
                          if ( result >= 0 )
                          {
                            *((_DWORD *)this + 54) = 1;
                            return 0;
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
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F40D2
// Name: protected: long D3DXShader::CProgram::Vectorize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::Vectorize(D3DXShader::CProgram *this)
{
  int result; // eax
  char *i; // edi

  result = D3DXShader::CProgram::VectorizeLeft(this);
  if ( result >= 0 )
  {
    result = D3DXShader::CProgram::VectorizeRight(this);
    if ( result >= 0 )
    {
      result = D3DXShader::CProgram::SplitRegisters(this, a2: 1);
      if ( result >= 0 )
      {
        for ( i = nullptr; (unsigned int)i < 0x100; ++i )
        {
          result = D3DXShader::CProgram::RemoveDuplicateInstructions(this, a2: i, a3: 1);
          if ( result != 0 )
          {
            if ( result < 0 )
              return result;
            if ( result == 1 )
              break;
          }
        }
        result = D3DXShader::CProgram::PropagateSwizzles(this);
        if ( result >= 0 )
        {
          result = D3DXShader::CProgram::CombineInstructions(this);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CProgram *))(*(_DWORD *)this + 16))(a1: this);
            if ( result >= 0 )
            {
              result = D3DXShader::CProgram::SplitRegisters(this, a2: 0);
              if ( result >= 0 )
              {
                result = D3DXShader::CProgram::VectorizeLiterals(this);
                if ( result >= 0 )
                {
                  *((_DWORD *)this + 55) = 1;
                  result = D3DXShader::CProgram::ReorderInstructions(this);
                  if ( result >= 0 )
                  {
                    result = D3DXShader::CProgram::SeparatePhases(this);
                    if ( result >= 0 )
                    {
                      result = D3DXShader::CProgram::PropagateMovs(this);
                      if ( result >= 0 )
                      {
                        result = (*(int (__thiscall **)(D3DXShader::CProgram *))(*(_DWORD *)this + 20))(a1: this);
                        if ( result >= 0 )
                        {
                          result = (*(int (__thiscall **)(D3DXShader::CProgram *))(*(_DWORD *)this + 24))(a1: this);
                          if ( result >= 0 )
                          {
                            result = D3DXShader::CProgram::CompactInstructions(this);
                            if ( result >= 0 )
                            {
                              result = D3DXShader::CProgram::CompactArguments(this);
                              if ( result >= 0 )
                              {
                                result = D3DXShader::CProgram::CompactRegisters(this);
                                if ( result >= 0 )
                                {
                                  result = D3DXShader::CProgram::SwizzleRegisters(this);
                                  if ( result >= 0 )
                                    return 0;
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
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F41DD
// Name: public: virtual long D3DXShader::CProgram::GenerateCode(struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::GenerateCode(D3DXShader::CProgram *this, struct ID3DXBuffer **a2)
{
  int result; // eax

  *((_DWORD *)this + 54) = 0;
  *((_DWORD *)this + 55) = 0;
  if ( a2 != nullptr )
    *a2 = nullptr;
  result = D3DXShader::CProgram::Optimize(this);
  if ( result >= 0 )
  {
    result = D3DXShader::CProgram::Vectorize(this);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F421A
// Name: public: D3DXShader::CParse::CParse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CParse *__thiscall D3DXShader::CParse::CParse(D3DXShader::CParse *this)
{
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F422E
// Name: protected: void D3DXShader::CParse::Error(char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void D3DXShader::CParse::Error(D3DXShader::CParse *this, char *format, ...)
{
  D3DXShader::CParse *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  D3DXShader::CTErrors *v6; // [esp-24h] [ebp-130h]
  char string[256]; // [esp+8h] [ebp-104h] BYREF
  va_list ap; // [esp+11Ch] [ebp+10h] BYREF

  va_start(ap, format);
  if ( strcmp(format, "syntax error") == 0 )
  {
    v2 = this;
    if ( *((_DWORD *)this + 16) != 0 )
      goto LABEL_23;
    v3 = *((_DWORD *)this + 8);
    if ( v3 <= 9 )
    {
      if ( v3 == 9 )
      {
        _snprintf(string, count: 0x100u, format: "token '%s'", *((const char **)this + 10));
      }
      else if ( v3 != 0 )
      {
        if ( v3 != 1 )
        {
          if ( v3 > 1 )
          {
            if ( v3 <= 4 )
              _snprintf(string, count: 0x100u, format: "integer constant");
            else
              _snprintf(string, count: 0x100u, format: "float constant");
            goto LABEL_22;
          }
LABEL_18:
          _snprintf(string, count: 0x100u, format: "token");
          goto LABEL_22;
        }
        _snprintf(string, count: 0x100u, format: "token '%s'", (const char *)this + 40);
      }
      else
      {
        _snprintf(string, count: 0x100u, format: "version token");
      }
LABEL_22:
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CTErrors *)(*((_DWORD *)this + 1) + 24),
        a2: (D3DXShader::CParse *)((char *)this + 32),
        a3: 0xBB8u,
        format: "syntax error: unexpected %s",
        string);
      goto LABEL_23;
    }
    v4 = v3 - 10;
    if ( v4 == 0 )
    {
      _snprintf(string, count: 0x100u, format: "string constant");
      goto LABEL_22;
    }
    v5 = v4 - 2;
    if ( v5 == 0 )
    {
      _snprintf(string, count: 0x100u, format: "end of line");
      goto LABEL_22;
    }
    if ( v5 == 1 )
    {
      _snprintf(string, count: 0x100u, format: "end of file");
      goto LABEL_22;
    }
    goto LABEL_18;
  }
  _vsnprintf(string, count: 0x100u, format, ap);
  v2 = this;
  v6 = (D3DXShader::CTErrors *)(*((_DWORD *)this + 1) + 24);
  string[255] = 0;
  D3DXShader::CTErrors::Error(this: v6, a2: (D3DXShader::CParse *)((char *)this + 32), a3: 0, format: "%s", string);
LABEL_23:
  *((_DWORD *)v2 + 16) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F436E
// Name: protected: void D3DXShader::CParse::Error(struct D3DXShader::D3DXTOKEN __near *,unsigned int,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void D3DXShader::CParse::Error(
        D3DXShader::CParse *this,
        struct D3DXShader::D3DXTOKEN *a2,
        unsigned int a3,
        char *format,
        ...)
{
  D3DXShader::CTErrors *v4; // eax
  char string[256]; // [esp+4h] [ebp-104h] BYREF
  va_list ap; // [esp+120h] [ebp+18h] BYREF

  va_start(ap, format);
  _vsnprintf(string, count: 0x100u, format, ap);
  v4 = (D3DXShader::CTErrors *)(*((_DWORD *)this + 1) + 24);
  string[255] = 0;
  D3DXShader::CTErrors::Error(this: v4, a2, a3, format: "%s", string);
  *((_DWORD *)this + 16) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F43D4
// Name: protected: void D3DXShader::CParse::Warning(struct D3DXShader::D3DXTOKEN __near *,unsigned int,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void D3DXShader::CParse::Warning(
        D3DXShader::CParse *this,
        struct D3DXShader::D3DXTOKEN *a2,
        unsigned int a3,
        char *format,
        ...)
{
  D3DXShader::CTErrors *v4; // eax
  char string[256]; // [esp+0h] [ebp-104h] BYREF
  va_list ap; // [esp+11Ch] [ebp+18h] BYREF

  va_start(ap, format);
  _vsnprintf(string, count: 0x100u, format, ap);
  v4 = (D3DXShader::CTErrors *)(*((_DWORD *)this + 1) + 24);
  string[255] = 0;
  D3DXShader::CTErrors::Warning(this: v4, a2, a3, format: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x101F4431
// Name: protected: void D3DXShader::CParse::FatalError(struct D3DXShader::D3DXTOKEN __near *,unsigned int,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void D3DXShader::CParse::FatalError(
        D3DXShader::CParse *this,
        struct D3DXShader::D3DXTOKEN *a2,
        unsigned int a3,
        char *format,
        ...)
{
  D3DXShader::CTErrors *v4; // eax
  char string[256]; // [esp+4h] [ebp-104h] BYREF
  va_list ap; // [esp+120h] [ebp+18h] BYREF

  va_start(ap, format);
  _vsnprintf(string, count: 0x100u, format, ap);
  v4 = (D3DXShader::CTErrors *)(*((_DWORD *)this + 1) + 24);
  string[255] = 0;
  D3DXShader::CTErrors::Error(this: v4, a2, a3, format: "%s", string);
  *((_DWORD *)this + 16) = 1;
  *((_DWORD *)this + 17) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F4499
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::NonNull(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::NonNull(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2)
{
  if ( a2 == nullptr )
  {
    if ( *((_DWORD *)this + 16) == 0 )
      D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: production failed!");
    *((_DWORD *)this + 16) = 1;
    *((_DWORD *)this + 17) = 1;
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x101F44CE
// Name: protected: long D3DXShader::CParse::PushScope(enum D3DXShader::_D3DXSCOPE_TYPE,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::PushScope(D3DXShader::CParse *this, int a2, int a3)
{
  int v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // eax

  v4 = *((_DWORD *)this + 4);
  if ( v4 != 0 && a3 == 0 )
    a3 = *(_DWORD *)(v4 + 20);
  v5 = D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v5 != nullptr )
    v6 = D3DXShader::CNodeScope::CNodeScope(a1: v5, a2, a3, a4: 0, a5: 0, a6: *((_DWORD *)this + 4));
  else
    v6 = 0;
  if ( v6 != 0 )
  {
    *((_DWORD *)this + 4) = v6;
    return 0;
  }
  else
  {
    D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: out of memory");
    return -2147024882;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4532
// Name: protected: long D3DXShader::CParse::AddDeclTree(class D3DXShader::CNodeScope __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::AddDeclTree(
        D3DXShader::CParse *this,
        struct D3DXShader::CNodeScope *a2,
        struct D3DXShader::CNode *a3)
{
  char *v3; // esi
  int v4; // edi
  int v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // eax
  unsigned __int8 *v8; // eax
  unsigned int v9; // ebx
  int v10; // eax
  int *v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // edi
  _DWORD *v16; // edx
  int v17; // ecx
  int v18; // eax
  int v19; // edi
  struct D3DXShader::CNodeScope *v20; // [esp+14h] [ebp+8h]
  struct D3DXShader::CNode *i; // [esp+18h] [ebp+Ch]

  v3 = (char *)a2 + 28;
  v4 = *((_DWORD *)a3 + 5) + 16;
  if ( *((_DWORD *)a2 + 7) == 0 )
    goto LABEL_33;
  do
  {
    v20 = *(struct D3DXShader::CNodeScope **)v3;
    v5 = strcmp(*(const char **)(*((_DWORD *)a3 + 5) + 24), *(const char **)(*(_DWORD *)v3 + 16));
    if ( v5 >= 0 )
    {
      if ( v5 <= 0 )
        break;
      v3 = (char *)v20 + 12;
    }
    else
    {
      v3 = (char *)v20 + 8;
    }
  }
  while ( *(_DWORD *)v3 != 0 );
  if ( *(_DWORD *)v3 == 0 )
  {
LABEL_33:
    v6 = D3DXShader::CNode::operator new(a1: 0x18u);
    v7 = v6 != nullptr
       ? D3DXShader::CNodeTree::CNodeTree(
           this: (D3DXShader::CNodeTree *)v6,
           a2: *(const char **)(v4 + 8),
           a3: nullptr,
           a4: nullptr,
           a5: nullptr)
       : 0;
    *(_DWORD *)v3 = v7;
    if ( v7 == 0 )
      return -2147024882;
  }
  v8 = D3DXShader::CNode::operator new(a1: 0x14u);
  v9 = 0;
  v10 = v8 != nullptr
      ? D3DXShader::CNodeList::CNodeList(
          this: (D3DXShader::CNodeList *)v8,
          a2: a3,
          a3: *(struct D3DXShader::CNode **)(*(_DWORD *)v3 + 20),
          a4: "Stmts")
      : 0;
  *(_DWORD *)(*(_DWORD *)v3 + 20) = v10;
  if ( v10 == 0 )
    return -2147024882;
  if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v3 + 20) + 12) == 0 )
  {
    v12 = (int *)v3;
    if ( *(_DWORD *)v3 != 0 )
    {
      do
      {
        while ( 1 )
        {
          v13 = *v12;
          if ( *v12 == 0 )
            break;
          v14 = *(_DWORD *)(v13 + 8);
          if ( v14 == 0 )
            break;
          v15 = *(_DWORD *)(v14 + 12);
          *(_DWORD *)(v14 + 12) = v13;
          *(_DWORD *)(v13 + 8) = v15;
          *v12 = v14;
        }
        v12 = (int *)(v13 + 12);
        ++v9;
      }
      while ( *(_DWORD *)(v13 + 12) != 0 );
    }
    while ( 1 )
    {
      v9 >>= 1;
      if ( v9 == 0 )
        break;
      v16 = v3;
      for ( i = (struct D3DXShader::CNode *)v9; i != nullptr; i = (struct D3DXShader::CNode *)((char *)i - 1) )
      {
        v17 = *v16;
        if ( *v16 != 0 )
        {
          v18 = *(_DWORD *)(v17 + 12);
          if ( v18 != 0 )
          {
            v19 = *(_DWORD *)(v18 + 8);
            *(_DWORD *)(v18 + 8) = v17;
            *(_DWORD *)(v17 + 12) = v19;
            *v16 = v18;
          }
        }
        v16 = (_DWORD *)(*v16 + 12);
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F4665
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::FindDecls(struct D3DXShader::D3DXTOKEN __near *,class D3DXShader::CNodeScope __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::FindDecls(
        D3DXShader::CParse *this,
        const char **a2,
        struct D3DXShader::CNodeScope *a3)
{
  int v3; // edi
  int v4; // eax

  v3 = *((_DWORD *)a3 + 7);
  if ( v3 == 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = strcmp(a2[2], *(const char **)(v3 + 16));
    if ( v4 == 0 )
      break;
    if ( v4 >= 0 )
      v3 = *(_DWORD *)(v3 + 12);
    else
      v3 = *(_DWORD *)(v3 + 8);
    if ( v3 == 0 )
      return nullptr;
  }
  return *(struct D3DXShader::CNode **)(v3 + 20);
}

//------------------------------------------------------------------------------
// Address: 0x101F46C9
// Name: protected: int D3DXShader::CParse::IsCast(enum D3DXShader::_D3DXCOMPONENT_TYPE,enum D3DXShader::_D3DXCOMPONENT_TYPE)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CParse::IsCast(int a1, int a2)
{
  bool v2; // cc
  int result; // eax
  bool v4; // zf
  int v5; // eax
  bool v6; // zf

  if ( a1 == a2 )
    return 0;
  switch ( a1 )
  {
    case 1:
    case 5:
      if ( a2 <= 0 )
        goto LABEL_6;
      v2 = a2 <= 8;
      goto LABEL_5;
    case 2:
    case 6:
      if ( a2 <= 0 )
        goto LABEL_6;
      if ( a2 <= 2 )
        return 0;
      if ( a2 <= 4 )
        goto LABEL_6;
      v2 = a2 <= 6;
LABEL_5:
      if ( !v2 )
        goto LABEL_6;
      return 0;
    case 3:
    case 7:
      if ( a2 == 1 || a2 == 3 )
        return 0;
      v5 = a2 - 5;
      v4 = a2 == 5;
      goto LABEL_14;
    case 4:
    case 8:
      if ( a2 == 1 )
        return 0;
      if ( a2 <= 3 )
        goto LABEL_6;
      if ( a2 <= 5 )
        return 0;
      v6 = a2 == 8;
      goto LABEL_27;
    case 9:
      if ( a2 < 9 )
        goto LABEL_6;
      v2 = a2 <= 12;
      goto LABEL_5;
    case 10:
      if ( a2 < 9 )
        goto LABEL_6;
      v2 = a2 <= 10;
      goto LABEL_5;
    case 11:
      v5 = a2 - 9;
      v4 = a2 == 9;
LABEL_14:
      if ( v4 )
        return 0;
      v6 = v5 == 2;
LABEL_27:
      if ( v6 )
        return 0;
LABEL_6:
      result = 1;
      break;
    case 12:
      if ( a2 == 9 )
        return 0;
      v6 = a2 == 12;
      goto LABEL_27;
    default:
      goto LABEL_6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F4782
// Name: protected: long D3DXShader::CParse::PopUsageType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::PopUsageType(D3DXShader::CParse *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 5);
  if ( v1 != 0 )
  {
    *((_DWORD *)this + 5) = *(_DWORD *)(v1 + 12);
    *(_DWORD *)(v1 + 12) = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F4796
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::GetUsageType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::GetUsageType(D3DXShader::CParse *this)
{
  struct D3DXShader::CNode *result; // eax

  result = *((struct D3DXShader::CNode **)this + 5);
  if ( result != nullptr )
    return *((struct D3DXShader::CNode **)result + 2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F47A2
// Name: protected: long D3DXShader::CParse::MakeTypeConst(class D3DXShader::CNode __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::MakeTypeConst(D3DXShader::CParse *this, struct D3DXShader::CNode **a2, int a3)
{
  struct D3DXShader::CNode **v3; // esi

  v3 = a2;
  if ( a2 != nullptr )
  {
    if ( a2[1] == (struct D3DXShader::CNode *)1 )
    {
      do
      {
        if ( v3[1] != (struct D3DXShader::CNode *)1 )
          break;
        D3DXShader::CParse::MakeTypeConst(this, a2: v3[2], a3);
        v3 = (struct D3DXShader::CNode **)v3[3];
      }
      while ( v3 != nullptr );
      if ( v3 != nullptr )
        D3DXShader::CParse::MakeTypeConst(this, a2: (struct D3DXShader::CNode *)v3, a3);
    }
    else if ( a2[1] == (struct D3DXShader::CNode *)6 )
    {
      D3DXShader::CParse::MakeTypeConst(this, a2: a2[6], a3);
    }
    else if ( a2[1] == (struct D3DXShader::CNode *)8 )
    {
      D3DXShader::CParse::MakeTypeConst(this, a2: a2[4], a3);
    }
    else if ( a2[1] == (struct D3DXShader::CNode *)9 )
    {
      if ( a3 != 0 )
        *((_BYTE *)a2 + 33) |= 2u;
      else
        *((_BYTE *)a2 + 33) &= ~2u;
    }
    else if ( a2[1] == (struct D3DXShader::CNode *)11 )
    {
      D3DXShader::CParse::MakeTypeConst(this, a2: a2[8], a3);
    }
    else
    {
      D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: unknown node");
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F4837
// Name: protected: long D3DXShader::CParse::CombineUsages(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::CombineUsages(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  struct D3DXShader::CNode *v3; // esi
  int v5; // eax
  struct D3DXShader::CNode *v6; // esi
  struct D3DXShader::CNode *v7; // eax

  v3 = a3;
  if ( (*((_DWORD *)a3 + 4) & *((_DWORD *)a2 + 4)) != 0 )
    D3DXShader::CParse::Error(
      this,
      a2: (D3DXShader::CParse *)((char *)this + 32),
      a3: 0xBE8u,
      format: "duplicate usages specified");
  if ( *((_DWORD *)a2 + 5) != 0 )
  {
    v5 = *((_DWORD *)a3 + 5);
    if ( v5 != 0 )
    {
      qmemcpy((char *)this + 32, (const void *)(v5 + 16), 0x20u);
      D3DXShader::CParse::Error(this, format: "syntax error");
      v3 = a3;
    }
  }
  *((_DWORD *)a2 + 4) |= *((_DWORD *)v3 + 4);
  if ( *((_DWORD *)a2 + 5) != 0 )
    return 0;
  v6 = *((struct D3DXShader::CNode **)v3 + 5);
  if ( v6 == nullptr )
    return 0;
  v7 = D3DXShader::CNode::Copy(a1: v6);
  *((_DWORD *)a2 + 5) = v7;
  if ( v7 != nullptr )
    return 0;
  else
    return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x101F48C4
// Name: protected: int D3DXShader::CParse::IsConst(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::IsConst(D3DXShader::CParse *this, struct D3DXShader::CNode *a2)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          if ( a2 == nullptr )
            return 0;
          v4 = *((_DWORD *)a2 + 1);
          if ( v4 != 1 )
            break;
          if ( D3DXShader::CParse::IsConst(this, a2: *((struct D3DXShader::CNode **)a2 + 2)) != 0 )
            return 1;
          a2 = *((struct D3DXShader::CNode **)a2 + 3);
        }
        v5 = v4 - 6;
        if ( v5 != 0 )
          break;
        a2 = *((struct D3DXShader::CNode **)a2 + 6);
      }
      v6 = v5 - 2;
      if ( v6 != 0 )
        break;
      a2 = *((struct D3DXShader::CNode **)a2 + 4);
    }
    v7 = v6 - 1;
    if ( v7 == 0 )
      break;
    if ( v7 != 2 )
    {
      D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: unknown node");
      return 0;
    }
    a2 = *((struct D3DXShader::CNode **)a2 + 8);
  }
  return *((_DWORD *)a2 + 8) & 0x200;
}

//------------------------------------------------------------------------------
// Address: 0x101F4937
// Name: protected: int D3DXShader::CParse::IsScalar(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CParse::IsScalar(D3DXShader::CParse *this, struct D3DXShader::CNode *a2)
{
  return a2 != nullptr && *((_DWORD *)a2 + 1) == 9 && *((_DWORD *)a2 + 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F495B
// Name: protected: int D3DXShader::CParse::IsNumeric(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CParse::IsNumeric(D3DXShader::CParse *this, struct D3DXShader::CNode *a2)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          if ( a2 == nullptr )
            return true;
          v4 = *((_DWORD *)a2 + 1);
          if ( v4 != 1 )
            break;
          if ( D3DXShader::CParse::IsNumeric(this, a2: *((struct D3DXShader::CNode **)a2 + 2)) == 0 )
            return false;
          a2 = *((struct D3DXShader::CNode **)a2 + 3);
        }
        v5 = v4 - 6;
        if ( v5 != 0 )
          break;
        a2 = *((struct D3DXShader::CNode **)a2 + 6);
      }
      v6 = v5 - 2;
      if ( v6 != 0 )
        break;
      a2 = *((struct D3DXShader::CNode **)a2 + 4);
    }
    v7 = v6 - 1;
    if ( v7 == 0 )
      break;
    if ( v7 != 2 )
    {
      D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: unknown node");
      return false;
    }
    a2 = *((struct D3DXShader::CNode **)a2 + 8);
  }
  return *((_DWORD *)a2 + 4) <= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x101F49D2
// Name: protected: unsigned int D3DXShader::CParse::TypeSize(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::TypeSize(D3DXShader::CParse *this, struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode *v2; // esi
  int v3; // edi
  unsigned int v5; // eax
  int v7; // eax

  v2 = a2;
  v3 = 0;
  if ( a2 != nullptr )
  {
    do
    {
      if ( *((_DWORD *)v2 + 1) != 1 )
        break;
      v5 = D3DXShader::CParse::TypeSize(this, a2: *((struct D3DXShader::CNode **)v2 + 2));
      v2 = *((struct D3DXShader::CNode **)v2 + 3);
      v3 += v5;
    }
    while ( v2 != nullptr );
    if ( v2 != nullptr )
    {
      switch ( *((_DWORD *)v2 + 1) )
      {
        case 6:
          v7 = D3DXShader::CParse::TypeSize(this, a2: *((struct D3DXShader::CNode **)v2 + 6));
          break;
        case 8:
          v7 = *((_DWORD *)v2 + 5) * D3DXShader::CParse::TypeSize(this, a2: *((struct D3DXShader::CNode **)v2 + 4));
          break;
        case 9:
          v7 = *((_DWORD *)v2 + 6) * *((_DWORD *)v2 + 7);
          break;
        case 0xB:
          v7 = D3DXShader::CParse::TypeSize(this, a2: *((struct D3DXShader::CNode **)v2 + 8));
          break;
        default:
          D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: unknown node");
          return 0;
      }
      return v3 + v7;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101F4A60
// Name: protected: int D3DXShader::CParse::IsTypeEqual(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CParse::IsTypeEqual(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax

  while ( 1 )
  {
    while ( 1 )
    {
      if ( a2 == nullptr )
        return a3 == nullptr;
      v6 = *((_DWORD *)a2 + 1);
      if ( v6 != 1 )
        break;
      if ( a3 == nullptr )
        return false;
      if ( *((_DWORD *)a3 + 1) != 1 )
        break;
      if ( D3DXShader::CParse::IsTypeEqual(
             this,
             a2: *((struct D3DXShader::CNode **)a2 + 2),
             a3: *((struct D3DXShader::CNode **)a3 + 2)) == 0 )
        return false;
      a2 = *((struct D3DXShader::CNode **)a2 + 3);
      a3 = *((struct D3DXShader::CNode **)a3 + 3);
    }
    if ( a3 == nullptr || v6 != *((_DWORD *)a3 + 1) )
      break;
    v7 = v6 - 6;
    if ( v7 != 0 )
    {
      v8 = v7 - 2;
      if ( v8 != 0 )
      {
        v9 = v8 - 1;
        if ( v9 == 0 )
          return *((_DWORD *)a2 + 4) == *((_DWORD *)a3 + 4)
              && *((_DWORD *)a2 + 5) == *((_DWORD *)a3 + 5)
              && *((_DWORD *)a2 + 6) == *((_DWORD *)a3 + 6)
              && *((_DWORD *)a2 + 7) == *((_DWORD *)a3 + 7);
        if ( v9 != 2 )
          return false;
        a3 = *((struct D3DXShader::CNode **)a3 + 8);
        a2 = *((struct D3DXShader::CNode **)a2 + 8);
      }
      else
      {
        if ( *((_DWORD *)a2 + 5) != *((_DWORD *)a3 + 5) )
          return false;
        a3 = *((struct D3DXShader::CNode **)a3 + 4);
        a2 = *((struct D3DXShader::CNode **)a2 + 4);
      }
    }
    else
    {
      a3 = *((struct D3DXShader::CNode **)a3 + 6);
      a2 = *((struct D3DXShader::CNode **)a2 + 6);
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101F4B12
// Name: protected: unsigned int D3DXShader::CParse::PrintType(char __near *,unsigned int,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CParse::PrintType(
        D3DXShader::CParse *this,
        char *a2,
        unsigned int a3,
        struct D3DXShader::CNode *a4)
{
  struct D3DXShader::CNode *v4; // edi
  const char *v6; // edx
  const char *v7; // eax
  struct D3DXShader::CNode *v8; // eax
  int v9; // ebx
  const char *v10; // esi
  unsigned int result; // eax
  int v12; // [esp-4h] [ebp-11Ch]
  char *p_string; // [esp+10h] [ebp-108h]
  char string; // [esp+14h] [ebp-104h] BYREF
  _BYTE v15[3]; // [esp+15h] [ebp-103h] BYREF
  char v16; // [esp+113h] [ebp-5h]

  v4 = a4;
  p_string = &string;
  if ( a4 == nullptr )
  {
    p_string = "void";
    goto LABEL_48;
  }
  if ( *((_DWORD *)a4 + 1) == 1 )
  {
    v10 = "const ";
    if ( D3DXShader::CParse::IsConst(this, a2: a4) == 0 )
      v10 = (const char *)&pMem;
    v12 = D3DXShader::CParse::TypeSize(this, a2: a4);
    _snprintf(&string, count: 0xFFu, format: "%sstruct{%u}", v10, v12);
LABEL_47:
    v16 = 0;
    goto LABEL_48;
  }
  if ( *((_DWORD *)a4 + 1) != 8 )
  {
    if ( *((_DWORD *)a4 + 1) != 9 )
    {
      p_string = "unknown";
      goto LABEL_48;
    }
    v6 = "const ";
    if ( (*((_BYTE *)a4 + 33) & 2) == 0 )
      v6 = (const char *)&pMem;
    switch ( *((_DWORD *)a4 + 5) )
    {
      case 0:
        v7 = "bool";
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
        v7 = "int";
        break;
      case 9:
      case 0xB:
        v7 = "float";
        break;
      case 0xA:
        v7 = "half";
        break;
      case 0xC:
        v7 = "double";
        break;
      case 0xD:
        v7 = "NULL";
        break;
      case 0xE:
        v7 = "string";
        break;
      case 0xF:
        v7 = "texture";
        break;
      case 0x10:
        v7 = "texture1D";
        break;
      case 0x11:
        v7 = "texture2D";
        break;
      case 0x12:
        v7 = "texture3D";
        break;
      case 0x13:
        v7 = "textureCUBE";
        break;
      case 0x14:
        v7 = "sampler";
        break;
      case 0x15:
        v7 = "sampler1D";
        break;
      case 0x16:
        v7 = "sampler2D";
        break;
      case 0x17:
        v7 = "sampler3D";
        break;
      case 0x18:
        v7 = "samplerCUBE";
        break;
      case 0x19:
        v7 = "pixelshader";
        break;
      case 0x1A:
        v7 = "vertexshader";
        break;
      case 0x1B:
        v7 = "pixelfragment";
        break;
      case 0x1C:
        v7 = "vertexfragment";
        break;
      case 0x1D:
        v7 = "stateblock";
        break;
      default:
        v7 = "unknown";
        break;
    }
    if ( *((_DWORD *)a4 + 4) == 1 )
    {
      _snprintf(&string, count: 0xFFu, format: "%s%s%u", v6, v7, *((_DWORD *)a4 + 7));
    }
    else if ( *((_DWORD *)a4 + 4) == 2 )
    {
      _snprintf(&string, count: 0xFFu, format: "%s%s%ux%u", v6, v7, *((_DWORD *)a4 + 6), *((_DWORD *)a4 + 7));
    }
    else
    {
      _snprintf(&string, count: 0xFFu, format: "%s%s", v6, v7);
    }
    goto LABEL_47;
  }
  v8 = a4;
  do
    v8 = *((struct D3DXShader::CNode **)v8 + 4);
  while ( *((_DWORD *)v8 + 1) == 8 );
  v9 = D3DXShader::CParse::PrintType(this, a2: &string, a3: 0xFFu, a4: v8);
  while ( *((_DWORD *)v4 + 1) == 8 )
  {
    _snprintf(string: &v15[v9 - 1], count: 255 - v9, format: "[%u]", *((_DWORD *)v4 + 5));
    v16 = 0;
    v4 = *((struct D3DXShader::CNode **)v4 + 4);
    v9 = &v15[v9 + strlen(&v15[v9 - 1])] - v15;
  }
LABEL_48:
  result = strlen(p_string);
  if ( result > a3 )
    result = a3;
  qmemcpy(a2, p_string, result);
  a2[result] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F4E0D
// Name: protected: long D3DXShader::CParse::GetSubType(class D3DXShader::CNode __near *,unsigned int,class D3DXShader::CNodeType __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::GetSubType(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        unsigned int a3,
        struct D3DXShader::CNodeType *a4)
{
  struct D3DXShader::CNode *v4; // esi
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx

  v4 = a2;
  if ( a2 == nullptr )
    return -2147467259;
  while ( 1 )
  {
    switch ( *((_DWORD *)v4 + 1) )
    {
      case 1:
        v8 = D3DXShader::CParse::TypeSize(this, a2: *((struct D3DXShader::CNode **)v4 + 2));
        if ( a3 >= v8 )
        {
          v4 = *((struct D3DXShader::CNode **)v4 + 3);
          a3 -= v8;
        }
        else
        {
          v4 = *((struct D3DXShader::CNode **)v4 + 2);
        }
        goto LABEL_14;
      case 6:
        v4 = *((struct D3DXShader::CNode **)v4 + 6);
        goto LABEL_14;
      case 8:
        v4 = *((struct D3DXShader::CNode **)v4 + 4);
        v7 = D3DXShader::CParse::TypeSize(this, a2: v4);
        if ( v7 == 0 )
          return -2147467259;
        a3 %= v7;
        goto LABEL_14;
      default:
        break;
    }
    if ( *((_DWORD *)v4 + 1) == 9 )
      break;
    if ( *((_DWORD *)v4 + 1) != 11 )
    {
      D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: unknown node");
      return 0;
    }
    v4 = *((struct D3DXShader::CNode **)v4 + 8);
LABEL_14:
    if ( v4 == nullptr )
      return -2147467259;
  }
  v10 = *((_DWORD *)v4 + 4);
  if ( v10 != 0 && (v11 = v10 - 1) != 0 && (v12 = v11 - 1) != 0 )
  {
    if ( v12 == 1 )
      *((_DWORD *)a4 + 4) = 3;
  }
  else
  {
    *((_DWORD *)a4 + 4) = 0;
  }
  *((_DWORD *)a4 + 5) = *((_DWORD *)v4 + 5);
  *((_DWORD *)a4 + 6) = 1;
  *((_DWORD *)a4 + 7) = 1;
  *((_DWORD *)a4 + 8) = *((_DWORD *)v4 + 8) & 0x200;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F4ED8
// Name: protected: long D3DXShader::CParse::GetComponentType(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,enum D3DXShader::_D3DXCOMPONENT_TYPE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::GetComponentType(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        enum D3DXShader::_D3DXCOMPONENT_TYPE *a4)
{
  int v4; // esi
  int v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // edx
  unsigned int i; // edx
  int v10; // ecx
  int v11; // eax
  bool v12; // cc

  if ( a2 == nullptr || *((_DWORD *)a2 + 1) != 9 || a3 == nullptr || *((_DWORD *)a3 + 1) != 9 )
    return -2147467259;
  v4 = *((_DWORD *)a2 + 5);
  v5 = *((_DWORD *)a3 + 5);
  if ( v4 == v5 )
  {
    *(_DWORD *)a4 = v4;
    return 0;
  }
  v6 = dword_102B99D0[2 * v5];
  if ( dword_102B99D0[2 * v4] > v6 )
    v6 = dword_102B99D0[2 * v4];
  v7 = dword_102B99D4[2 * v5] & dword_102B99D4[2 * v4];
  v8 = 1;
  if ( (v7 & 1) != 0 )
  {
    *(_DWORD *)a4 = 0;
    return 0;
  }
  if ( (v7 & 4) != 0 )
  {
    if ( v6 == 0 )
    {
      *(_DWORD *)a4 = 5;
      return 0;
    }
    v8 = 8;
    switch ( v6 )
    {
      case 8u:
        *(_DWORD *)a4 = 6;
        return 0;
      case 0x10u:
        *(_DWORD *)a4 = 7;
        return 0;
      case 0x20u:
      case 0x40u:
LABEL_17:
        *(_DWORD *)a4 = v8;
        return 0;
      default:
        break;
    }
    return 0;
  }
  if ( (v7 & 2) != 0 )
  {
    switch ( v6 )
    {
      case 0u:
        goto LABEL_17;
      case 8u:
        *(_DWORD *)a4 = 2;
        break;
      case 0x10u:
        *(_DWORD *)a4 = 3;
        break;
      case 0x20u:
      case 0x40u:
        *(_DWORD *)a4 = 4;
        break;
      default:
        break;
    }
    return 0;
  }
  if ( (v7 & 8) == 0 )
  {
    if ( (v7 & 0x10) != 0 )
    {
      for ( i = 0; i < 2; ++i )
      {
        v10 = *((_DWORD *)a2 + 5);
        if ( i != 0 )
        {
          v11 = *((_DWORD *)a3 + 5);
        }
        else
        {
          v10 = *((_DWORD *)a3 + 5);
          v11 = *((_DWORD *)a2 + 5);
        }
        if ( v10 == 13 )
        {
LABEL_55:
          *(_DWORD *)a4 = v11;
          return 0;
        }
        if ( v10 == 15 )
        {
          if ( v11 < 15 )
            continue;
          v12 = v11 <= 19;
        }
        else
        {
          if ( v10 != 20 || v11 < 20 )
            continue;
          v12 = v11 <= 24;
        }
        if ( v12 )
          goto LABEL_55;
      }
    }
    return -2147467259;
  }
  if ( v6 != 0 )
  {
    switch ( v6 )
    {
      case 8u:
      case 0x10u:
        *(_DWORD *)a4 = 10;
        break;
      case 0x20u:
        *(_DWORD *)a4 = 11;
        break;
      case 0x40u:
        *(_DWORD *)a4 = 12;
        break;
      default:
        break;
    }
  }
  else
  {
    *(_DWORD *)a4 = 9;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F508B
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::ObjectExpr(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::ObjectExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2)
{
  int i; // eax
  int v3; // edx

  for ( i = *((_DWORD *)this + 4); ; i = *(_DWORD *)(i + 32) )
  {
    if ( i == 0 )
      return a2;
    v3 = *(_DWORD *)(i + 16);
    if ( v3 == 2 || v3 == 3 || v3 == 4 )
      break;
  }
  D3DXShader::CParse::Error(
    this,
    a2: (D3DXShader::CParse *)((char *)this + 32),
    a3: 0xBF8u,
    format: "object literals are not allowed inside functions");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F50D0
// Name: protected: unsigned int D3DXShader::CParse::EvalType(class D3DXShader::CNode __near *,struct D3DXShader::_D3DXVALUE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CParse::EvalType(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode **a2,
        struct D3DXShader::_D3DXVALUE *a3)
{
  struct D3DXShader::CNode **v3; // esi
  int v5; // edi
  int v8; // eax
  struct D3DXShader::_D3DXVALUE *v9; // ecx
  int v10; // edx
  unsigned int v11; // ebx
  unsigned int v12; // eax
  int v13; // [esp-4h] [ebp-14h]

  v3 = a2;
  v5 = 0;
  if ( a2 == nullptr )
    return 0;
  if ( a2[1] == (struct D3DXShader::CNode *)1 )
  {
    do
    {
      if ( v3[1] != (struct D3DXShader::CNode *)1 )
        break;
      v12 = D3DXShader::CParse::EvalType(this, a2: v3[2], a3: (struct D3DXShader::_D3DXVALUE *)((char *)a3 + 16 * v5));
      v3 = (struct D3DXShader::CNode **)v3[3];
      v5 += v12;
    }
    while ( v3 != nullptr );
    if ( v3 != nullptr )
      v5 += D3DXShader::CParse::EvalType(
              this,
              a2: (struct D3DXShader::CNode *)v3,
              a3: (struct D3DXShader::_D3DXVALUE *)((char *)a3 + 16 * v5));
    return v5;
  }
  if ( a2[1] == (struct D3DXShader::CNode *)6 )
    return D3DXShader::CParse::EvalType(this, a2: a2[6], a3);
  if ( a2[1] == (struct D3DXShader::CNode *)8 )
  {
    v11 = 0;
    if ( a2[5] != nullptr )
    {
      do
      {
        v5 += D3DXShader::CParse::EvalType(this, a2: a2[4], a3: (struct D3DXShader::_D3DXVALUE *)((char *)a3 + 16 * v5));
        ++v11;
      }
      while ( v11 < (unsigned int)a2[5] );
    }
    return v5;
  }
  if ( a2[1] == (struct D3DXShader::CNode *)9 )
  {
    v5 = (_DWORD)a2[6] * (_DWORD)a2[7];
    v8 = 3;
    switch ( (unsigned int)a2[5] )
    {
      case 0u:
        v8 = 0;
        break;
      case 1u:
      case 2u:
      case 3u:
      case 4u:
        v8 = 1;
        break;
      case 5u:
      case 6u:
      case 7u:
      case 8u:
        v13 = 2;
        goto LABEL_15;
      case 0xDu:
      case 0xEu:
      case 0xFu:
      case 0x10u:
      case 0x11u:
      case 0x12u:
      case 0x13u:
      case 0x19u:
      case 0x1Au:
      case 0x1Bu:
      case 0x1Cu:
        v8 = 5;
        break;
      case 0x14u:
      case 0x15u:
      case 0x16u:
      case 0x17u:
      case 0x18u:
      case 0x1Du:
        v13 = 4;
LABEL_15:
        v8 = v13;
        break;
      default:
        break;
    }
    if ( v5 != 0 )
    {
      v9 = a3;
      v10 = (_DWORD)a2[6] * (_DWORD)a2[7];
      do
      {
        *(_DWORD *)v9 = v8;
        v9 = (struct D3DXShader::_D3DXVALUE *)((char *)v9 + 16);
        --v10;
      }
      while ( v10 != 0 );
    }
    return v5;
  }
  if ( a2[1] == (struct D3DXShader::CNode *)11 )
    return D3DXShader::CParse::EvalType(this, a2: a2[8], a3);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101F5215
// Name: protected: long D3DXShader::CParse::CastToFloat(double __near *,struct D3DXShader::_D3DXVALUE __near *,struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::CastToFloat(
        D3DXShader::CParse *this,
        double *a2,
        struct D3DXShader::_D3DXVALUE *a3,
        struct D3DXShader::D3DXTOKEN *a4)
{
  double v5; // st7
  double v6; // st7

  if ( *(_DWORD *)a3 != 0 )
  {
    switch ( *(_DWORD *)a3 )
    {
      case 1:
        v5 = (double)*((int *)a3 + 2);
        break;
      case 2:
        v5 = (double)*((unsigned int *)a3 + 2);
        break;
      case 3:
        v5 = *((double *)a3 + 1);
        break;
      default:
        return -2147467259;
    }
    *a2 = v5;
  }
  else
  {
    if ( *((_DWORD *)a3 + 2) != 0 )
      v6 = 1.0;
    else
      v6 = 0.0;
    *a2 = v6;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F5273
// Name: protected: int D3DXShader::CParse::IsPartiallyLiteral(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CParse::IsPartiallyLiteral(D3DXShader::CParse *this, struct D3DXShader::CNode *a2)
{
  int v4; // eax
  int v5; // eax
  bool v7; // cc

  while ( 1 )
  {
    while ( 1 )
    {
      if ( a2 == nullptr )
        return false;
      v4 = *((_DWORD *)a2 + 1);
      if ( v4 != 1 )
        break;
      if ( D3DXShader::CParse::IsPartiallyLiteral(this, a2: *((struct D3DXShader::CNode **)a2 + 2)) != 0 )
        return true;
      a2 = *((struct D3DXShader::CNode **)a2 + 3);
    }
    if ( v4 == 14 )
      return *((_DWORD *)a2 + 4) != 6;
    if ( v4 != 13 )
      return false;
    v5 = *((_DWORD *)a2 + 7);
    if ( v5 > 23 )
      break;
    if ( v5 < 22 )
    {
      if ( v5 < 0 )
        return true;
      if ( v5 > 1 )
      {
        if ( v5 > 19 )
        {
          v7 = v5 <= 21;
          return !v7;
        }
        return true;
      }
    }
    a2 = *((struct D3DXShader::CNode **)a2 + 8);
  }
  if ( v5 < 25 )
    return true;
  v7 = v5 <= 26;
  return !v7;
}

//------------------------------------------------------------------------------
// Address: 0x101F52EF
// Name: protected: int D3DXShader::CParse::IsFullyLiteral(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CParse::IsFullyLiteral(D3DXShader::CParse *this, struct D3DXShader::CNode *a2)
{
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v8; // eax
  int IsFullyLiteral; // eax

  while ( 1 )
  {
    while ( 1 )
    {
      if ( a2 == nullptr )
        return 1;
      v4 = *((_DWORD *)a2 + 1);
      if ( v4 != 1 )
        break;
      if ( D3DXShader::CParse::IsFullyLiteral(this, a2: *((struct D3DXShader::CNode **)a2 + 2)) == 0 )
        return 0;
      a2 = *((struct D3DXShader::CNode **)a2 + 3);
    }
    if ( v4 == 14 )
      return *((_DWORD *)a2 + 4) != 6;
    if ( v4 != 13 )
      return 1;
    v5 = *((_DWORD *)a2 + 7);
    if ( v5 < 20 )
      break;
    if ( v5 <= 21 || v5 == 25 )
      return 0;
    if ( v5 == 26 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)a2 + 8) + 8) + 24);
      if ( v8 > 70 )
      {
        if ( v8 >= 73 && (v8 <= 75 || v8 > 77 && (v8 <= 80 || v8 > 82 && v8 <= 85)) )
          return 0;
      }
      else if ( v8 >= 68 || v8 == 9 || v8 == 26 || v8 == 40 || v8 == 61 )
      {
        return 0;
      }
      if ( D3DXShader::CParse::IsFullyLiteral(this, a2: *(struct D3DXShader::CNode **)(*((_DWORD *)a2 + 9) + 8)) != 0 )
      {
        IsFullyLiteral = D3DXShader::CParse::IsFullyLiteral(
                           this,
                           a2: *(struct D3DXShader::CNode **)(*((_DWORD *)a2 + 9) + 12));
        return IsFullyLiteral != 0;
      }
      return 0;
    }
    if ( v5 != 27 )
      break;
    v6 = *((_DWORD *)a2 + 9);
    if ( v6 == 0 || *(_DWORD *)(v6 + 4) != 13 )
      return 0;
    a2 = *(struct D3DXShader::CNode **)(v6 + 36);
  }
  if ( D3DXShader::CParse::IsFullyLiteral(this, a2: *((struct D3DXShader::CNode **)a2 + 8)) == 0 )
    return 0;
  IsFullyLiteral = D3DXShader::CParse::IsFullyLiteral(this, a2: *((struct D3DXShader::CNode **)a2 + 9));
  return IsFullyLiteral != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F540D
// Name: protected: void D3DXShader::CParse::ComputeExprSize(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CParse::ComputeExprSize(D3DXShader::CParse *this, struct D3DXShader::CNode *a2)
{
  _DWORD *v2; // eax
  int v3; // eax
  struct D3DXShader::CNode *v4; // [esp-4h] [ebp-8h]

  if ( a2 != nullptr && *((_DWORD *)a2 + 1) == 13 )
  {
    v2 = *((_DWORD **)a2 + 4);
    if ( v2 != nullptr )
    {
      if ( v2[1] == 9 )
      {
        *((_DWORD *)a2 + 5) = v2[6];
        v3 = v2[7];
      }
      else
      {
        v4 = *((struct D3DXShader::CNode **)a2 + 4);
        *((_DWORD *)a2 + 5) = 1;
        v3 = D3DXShader::CParse::TypeSize(this, a2: v4);
      }
      *((_DWORD *)a2 + 6) = v3;
    }
    else
    {
      *((_DWORD *)a2 + 5) = 0;
      *((_DWORD *)a2 + 6) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5455
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::Stmt(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::Stmt(D3DXShader::CParse *this, struct D3DXShader::CNode *a2)
{
  unsigned __int8 *v2; // eax
  struct D3DXShader::CNode *v3; // esi
  int v4; // eax
  unsigned __int8 *v5; // eax
  struct D3DXShader::CNode *result; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v2 != nullptr )
    v3 = (struct D3DXShader::CNode *)D3DXShader::CNodeStatement::CNodeStatement(this: (D3DXShader::CNodeStatement *)v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  *((_DWORD *)v3 + 4) = 0;
  if ( a2 != nullptr )
  {
    v4 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a2 + 4))(a1: a2);
    *((_DWORD *)v3 + 5) = v4;
    if ( v4 == 0 )
      return nullptr;
  }
  v5 = D3DXShader::CNode::operator new(a1: 0x14u);
  result = v5 != nullptr
         ? (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                         this: (D3DXShader::CNodeList *)v5,
                                         a2: v3,
                                         a3: nullptr,
                                         a4: "Stmts")
         : nullptr;
  if ( result == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F54B7
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::DiscardStmt(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::DiscardStmt(D3DXShader::CParse *this)
{
  struct D3DXShader::CNode *result; // eax
  unsigned __int8 *v3; // eax
  struct D3DXShader::CNode *v4; // esi
  unsigned __int8 *v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // eax

  if ( *((_DWORD *)this + 6) == 0 )
    return nullptr;
  v3 = D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v3 != nullptr )
    v4 = (struct D3DXShader::CNode *)D3DXShader::CNodeStatement::CNodeStatement(this: (D3DXShader::CNodeStatement *)v3);
  else
    v4 = nullptr;
  if ( v4 == nullptr )
    return nullptr;
  *((_DWORD *)v4 + 4) = 6;
  v5 = D3DXShader::CNode::operator new(a1: 0x50u);
  v6 = v5 != nullptr
     ? D3DXShader::CNodeExpression::CNodeExpression(a1: v5, a2: 0, a3: 0, a4: 0, a5: 0, a6: 1, a7: (char *)this + 32)
     : 0;
  if ( v6 == 0 )
    return nullptr;
  *((_DWORD *)v4 + 6) = v6;
  v7 = D3DXShader::CNode::operator new(a1: 0x14u);
  result = v7 != nullptr
         ? (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                         this: (D3DXShader::CNodeList *)v7,
                                         a2: v4,
                                         a3: nullptr,
                                         a4: "Stmts")
         : nullptr;
  if ( result == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F553A
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::ForStmt(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::ForStmt(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4,
        struct D3DXShader::CNode *a5)
{
  struct D3DXShader::CNode *result; // eax
  unsigned __int8 *v6; // eax
  int v7; // esi
  struct D3DXShader::CNode *v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  struct D3DXShader::CNode *v12; // eax
  unsigned __int8 *v13; // eax

  if ( a3 != nullptr
    && (*((_DWORD *)a3 + 5) * *((_DWORD *)a3 + 6) != 1
     || !D3DXShader::CParse::IsNumeric(this, a2: *((struct D3DXShader::CNode **)a3 + 4))) )
  {
    D3DXShader::CParse::Error(
      this,
      a2: (struct D3DXShader::CNode *)((char *)a3 + 48),
      a3: 0xBCBu,
      format: "float expected");
    return nullptr;
  }
  v6 = D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v6 != nullptr )
    v7 = D3DXShader::CNodeStatement::CNodeStatement(this: (D3DXShader::CNodeStatement *)v6);
  else
    v7 = 0;
  if ( v7 == 0 )
    return nullptr;
  v8 = a2;
  *(_DWORD *)(v7 + 16) = 3;
  if ( a4 == nullptr )
  {
    if ( a2 == nullptr )
    {
      *(_DWORD *)(v7 + 16) = 4;
      goto LABEL_17;
    }
    if ( a2 == a5 )
    {
      *(_DWORD *)(v7 + 16) = 5;
      v8 = nullptr;
    }
  }
  if ( v8 != nullptr )
  {
    v9 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)v8 + 4))(a1: v8);
    *(_DWORD *)(v7 + 20) = v9;
    if ( v9 == 0 )
      return nullptr;
  }
LABEL_17:
  if ( a3 != nullptr )
  {
    v10 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a3 + 4))(a1: a3);
    *(_DWORD *)(v7 + 24) = v10;
    if ( v10 == 0 )
      return nullptr;
  }
  if ( a5 != nullptr )
  {
    v11 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a5 + 4))(a1: a5);
    *(_DWORD *)(v7 + 28) = v11;
    if ( v11 == 0 )
      return nullptr;
  }
  if ( a4 != nullptr )
  {
    v12 = D3DXShader::CParse::Stmt(this, a2: a4);
    if ( v12 != nullptr )
    {
      *(_DWORD *)(v7 + 28) = D3DXShader::CNode::Append(a1: *(struct D3DXShader::CNode **)(v7 + 28), a2: v12);
      goto LABEL_24;
    }
    return nullptr;
  }
LABEL_24:
  v13 = D3DXShader::CNode::operator new(a1: 0x14u);
  if ( v13 != nullptr )
    result = (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                           this: (D3DXShader::CNodeList *)v13,
                                           a2: (struct D3DXShader::CNode *)v7,
                                           a3: nullptr,
                                           a4: "Stmts");
  else
    result = nullptr;
  if ( result == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F5655
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::AsmDecl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::AsmDecl(D3DXShader::CPreProcessor **this)
{
  D3DXShader::CPreProcessor::Begin(this: *(this + 1), a2: 1u);
  D3DXShader::CPreProcessor::End(this: *(this + 1));
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F5670
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::AsmBlock(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::AsmBlock(
        struct D3DXShader::CPreProcessor **this,
        unsigned int a2)
{
  D3DXShader::CFragmentConstants *v3; // eax
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // esi
  void *v8; // [esp-4h] [ebp-9Ch]
  _BYTE v9[128]; // [esp+Ch] [ebp-8Ch] BYREF
  unsigned __int8 *v10; // [esp+8Ch] [ebp-Ch]
  struct ID3DXBuffer *v11; // [esp+90h] [ebp-8h] BYREF
  void *pMem; // [esp+94h] [ebp-4h]
  unsigned int v13; // [esp+A0h] [ebp+8h]

  v11 = nullptr;
  pMem = nullptr;
  D3DXShader::CAssembler::CAssembler(this: (D3DXShader::CAssembler *)v9);
  if ( a2 != 0 )
  {
    v3 = (D3DXShader::CFragmentConstants *)MemAlloc_Alloc(nSize: 8u);
    pMem = v3 != nullptr
         ? (void *)D3DXShader::CFragmentConstants::CFragmentConstants(
                     this: v3,
                     a2: (struct D3DXShader::CParse *)this,
                     a3: *(this + 4))
         : nullptr;
    if ( pMem == nullptr )
      goto LABEL_15;
  }
  if ( D3DXShader::CAssembler::Assemble(
         this: (D3DXShader::CAssembler *)v9,
         a2: *(this + 1),
         a3: (char *)((unsigned int)*this & 0xC3),
         a4: (struct D3DXShader::CFragmentConstants *)pMem,
         a5: &v11) < 0 )
    goto LABEL_15;
  v13 = v11->GetBufferSize(this: v11);
  v4 = D3DXCore::CAlloc::Alloc(this: D3DXShader::CNode::s_pAlloc, a2: v13, dwSize: 1u);
  v10 = v4;
  if ( v4 == nullptr )
    goto LABEL_15;
  qmemcpy(v4, v11->GetBufferPointer(this: v11), v13);
  if ( v11 != nullptr )
  {
    v11->Release(this: v11);
    v11 = nullptr;
  }
  v5 = D3DXShader::CNode::operator new(a1: 0x38u);
  v6 = v5 != nullptr
     ? D3DXShader::CNodeBuffer::CNodeBuffer(
         this: (D3DXShader::CNodeBuffer *)v5,
         a2: (const struct D3DXShader::D3DXTOKEN *)(this + 8),
         a3: v10,
         a4: v13)
     : 0;
  if ( v6 != 0 )
  {
    free(pMem);
    D3DXShader::CAssembler::~CAssembler(this: (D3DXShader::CAssembler *)v9);
    return (struct D3DXShader::CNode *)v6;
  }
  else
  {
LABEL_15:
    D3DXShader::CAssembler::~CAssembler(this: (D3DXShader::CAssembler *)v9);
    v8 = pMem;
    *(this + 16) = (struct D3DXShader::CPreProcessor *)1;
    free(pMem: v8);
    if ( v11 != nullptr )
      v11->Release(this: v11);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F57A9
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::CombineUintId(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::CombineUintId(
        D3DXCore::CAlloc **this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  unsigned __int8 *v3; // eax
  const char *v4; // ebx
  unsigned int v5; // kr00_4
  unsigned int v6; // kr04_4
  unsigned int v7; // edi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // esi
  int v11; // [esp+Ch] [ebp-20h]
  int v13; // [esp+14h] [ebp-18h]
  char string[16]; // [esp+18h] [ebp-14h] BYREF

  if ( a2 == nullptr
    || *((_DWORD *)a2 + 1) != 3
    || *((_DWORD *)a2 + 4) != 2
    || a3 == nullptr
    || *((_DWORD *)a3 + 1) != 3
    || *((_DWORD *)a3 + 4) != 9 )
  {
    return nullptr;
  }
  v3 = D3DXShader::CNode::operator new(a1: 0x30u);
  v13 = v3 != nullptr
      ? D3DXShader::CNodeToken::CNodeToken(
          this: (D3DXShader::CNodeToken *)v3,
          a2: (struct D3DXShader::CNode *)((char *)a3 + 16))
      : 0;
  if ( v13 == 0 )
    return nullptr;
  v4 = *((const char **)a3 + 6);
  v11 = *((_DWORD *)a2 + 6);
  _snprintf(string, count: 0x10u, format: "%u", v11);
  string[15] = 0;
  v5 = strlen(string);
  v6 = strlen(v4);
  v7 = v6 + v5 + 1;
  v8 = D3DXCore::CAlloc::Alloc(this: *(this + 1), a2: v7, dwSize: 1u);
  v9 = v8;
  if ( v8 == nullptr )
    return nullptr;
  _snprintf(string: (char *)v8, count: v7, format: "%u%s", v11, v4);
  v9[v6 + v5] = 0;
  *(_DWORD *)(v13 + 24) = v9;
  return (struct D3DXShader::CNode *)v13;
}

//------------------------------------------------------------------------------
// Address: 0x101F58A8
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::CombineStrings(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::CombineStrings(
        D3DXCore::CAlloc **this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  unsigned __int8 *v4; // eax
  const char *v5; // ebx
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // esi
  struct D3DXShader::CNode *v11; // [esp+18h] [ebp+8h]
  struct D3DXShader::CNode *v12; // [esp+1Ch] [ebp+Ch]

  if ( a2 == nullptr
    || *((_DWORD *)a2 + 1) != 3
    || *((_DWORD *)a2 + 4) != 10
    || a3 == nullptr
    || *((_DWORD *)a3 + 1) != 3
    || *((_DWORD *)a3 + 4) != 10 )
  {
    return nullptr;
  }
  v4 = D3DXShader::CNode::operator new(a1: 0x30u);
  v11 = v4 != nullptr
      ? (struct D3DXShader::CNode *)D3DXShader::CNodeToken::CNodeToken(
                                      this: (D3DXShader::CNodeToken *)v4,
                                      a2: (struct D3DXShader::CNode *)((char *)a2 + 16))
      : nullptr;
  if ( v11 == nullptr )
    return nullptr;
  v5 = *((const char **)a3 + 6);
  v12 = *((struct D3DXShader::CNode **)a2 + 6);
  v6 = strlen(v5) + strlen((const char *)v12) + 1;
  v7 = D3DXCore::CAlloc::Alloc(this: *(this + 1), a2: v6, dwSize: 1u);
  v8 = v7;
  if ( v7 == nullptr )
    return nullptr;
  _snprintf(string: (char *)v7, count: v6, format: "%s%s", (const char *)v12, v5);
  v8[v6 - 1] = 0;
  *((_DWORD *)v11 + 6) = v8;
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x101F5978
// Name: protected: void D3DXShader::CParse::CheckForObjectsInStructs(class D3DXShader::CNodeScope __near *,class D3DXShader::CNodeType __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CParse::CheckForObjectsInStructs(
        D3DXShader::CParse *this,
        struct D3DXShader::CNodeScope *a2,
        struct D3DXShader::CNodeType *a3)
{
  while ( a2 != nullptr )
  {
    if ( *((_DWORD *)a2 + 4) == 1 )
      D3DXShader::CParse::Error(
        this,
        a2: (D3DXShader::CParse *)((char *)this + 32),
        a3: 0xC0Au,
        format: "Object types are not allowed in structs");
    a2 = *((struct D3DXShader::CNodeScope **)a2 + 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F59B0
// Name: protected: long D3DXShader::CParse::PopScope(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::PopScope(D3DXShader::CParse *this)
{
  int v2; // eax
  int result; // eax
  int v4; // ecx
  int i; // edi
  int v6; // eax

  v2 = *((_DWORD *)this + 4);
  if ( v2 != 0 )
  {
    if ( *(_DWORD *)(v2 + 16) == 4 )
    {
      v4 = *(_DWORD *)(v2 + 32);
      if ( v4 != 0 && *(_DWORD *)(v4 + 16) != 4 )
      {
        for ( i = v2 + 24; *(_DWORD *)i != 0; i = *(_DWORD *)i + 12 )
        {
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)i + 8) + 44) = 1;
          result = D3DXShader::CParse::AddDeclTree(
                     this,
                     a2: *(struct D3DXShader::CNodeScope **)(*((_DWORD *)this + 4) + 32),
                     a3: *(struct D3DXShader::CNode **)(*(_DWORD *)i + 8));
          if ( result < 0 )
            return result;
        }
        *(_DWORD *)i = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 32) + 24);
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 32) + 24) = *(_DWORD *)(*((_DWORD *)this + 4) + 24);
        *(_DWORD *)(*((_DWORD *)this + 4) + 24) = 0;
      }
    }
    v6 = *((_DWORD *)this + 4);
    *((_DWORD *)this + 4) = *(_DWORD *)(v6 + 32);
    *(_DWORD *)(v6 + 32) = 0;
    return 0;
  }
  else
  {
    D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: scope underflow");
    return -2147467259;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5A47
// Name: protected: long D3DXShader::CParse::AddDecl(class D3DXShader::CNode __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::AddDecl(D3DXShader::CParse *this, struct D3DXShader::CNode *a2, int a3)
{
  struct D3DXShader::CNodeScope *v4; // eax
  int result; // eax
  int v6; // edi
  struct D3DXShader::CNode *i; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  unsigned __int8 *v11; // eax
  int v12; // edi
  struct D3DXShader::CNode *v13; // eax

  v4 = *((struct D3DXShader::CNodeScope **)this + 4);
  if ( v4 != nullptr )
  {
    v6 = *((_DWORD *)a2 + 5) + 16;
    for ( i = D3DXShader::CParse::FindDecls(this, a2: (const char **)v6, a3: v4);
          i != nullptr;
          i = *((struct D3DXShader::CNode **)i + 3) )
    {
      v8 = *((_DWORD *)i + 2);
      if ( *(_DWORD *)(v8 + 44) == 0 && (*((_DWORD *)a2 + 4) != 2 || *(_DWORD *)(v8 + 16) != 2) )
      {
        if ( a3 == 0 || D3DXShader::CNode::IsEqual(a1: a2, a2: *((struct D3DXShader::CNode **)i + 2)) == 0 )
        {
          D3DXShader::CParse::Error(
            this,
            a2: (struct D3DXShader::D3DXTOKEN *)v6,
            a3: 0xBBBu,
            format: "redefinition of '%s'",
            *(_DWORD *)(v6 + 8));
          return -2147467259;
        }
        return 0;
      }
    }
    v9 = *((_DWORD *)this + 4);
    v10 = *(_DWORD *)(v9 + 32);
    if ( v10 != 0
      && *(_DWORD *)(v9 + 16) == 3
      && *(_DWORD *)(v10 + 16) == 2
      && D3DXShader::CParse::FindDecls(this, a2: (const char **)v6, a3: *(struct D3DXShader::CNodeScope **)(v9 + 32)) != nullptr )
    {
      D3DXShader::CParse::Error(
        this,
        a2: (struct D3DXShader::D3DXTOKEN *)v6,
        a3: 0xBDCu,
        format: "redefinition of formal parameter '%s'",
        *(_DWORD *)(v6 + 8));
      return -2147467259;
    }
    v11 = D3DXShader::CNode::operator new(a1: 0x14u);
    v12 = 0;
    if ( v11 != nullptr )
      v12 = D3DXShader::CNodeList::CNodeList(this: (D3DXShader::CNodeList *)v11, a2: nullptr, a3: nullptr, a4: "Stmts");
    if ( v12 == 0 )
      return -2147024882;
    v13 = D3DXShader::CNode::Copy(a1: a2);
    *(_DWORD *)(v12 + 8) = v13;
    if ( v13 == nullptr )
      return -2147024882;
    *((_DWORD *)v13 + 8) = *(_DWORD *)(*((_DWORD *)this + 4) + 20);
    *((_DWORD *)a2 + 8) = *(_DWORD *)(*(_DWORD *)(v12 + 8) + 32);
    *(_DWORD *)(*(_DWORD *)(v12 + 8) + 36) = *((_DWORD *)this + 19);
    *((_DWORD *)a2 + 9) = *(_DWORD *)(*(_DWORD *)(v12 + 8) + 36);
    ++*((_DWORD *)this + 19);
    *(_DWORD *)(v12 + 12) = *(_DWORD *)(*((_DWORD *)this + 4) + 24);
    *(_DWORD *)(*((_DWORD *)this + 4) + 24) = v12;
    result = D3DXShader::CParse::AddDeclTree(
               this,
               a2: *((struct D3DXShader::CNodeScope **)this + 4),
               a3: *(struct D3DXShader::CNode **)(v12 + 8));
    if ( result >= 0 )
      return 0;
  }
  else
  {
    D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: scope missing");
    return -2147467259;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F5B91
// Name: protected: long D3DXShader::CParse::FindIntrinsic(struct D3DXShader::D3DXTOKEN __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near * __near *,class D3DXShader::CNode __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::FindIntrinsic(
        D3DXShader::CParse *this,
        struct D3DXShader::D3DXTOKEN *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode **a4,
        struct D3DXShader::CNode **a5)
{
  unsigned int v5; // ebx
  struct D3DXShader::CNode *v6; // eax
  unsigned int v7; // edx
  int v8; // ecx
  int v9; // ecx
  const char *v11; // eax
  unsigned int v12; // eax
  int v13; // ecx
  const char **v14; // edi
  const char **v15; // edi
  int *v16; // esi
  struct D3DXShader::CNode *v17; // ebx
  int *v18; // edi
  struct D3DXShader::CNode *v19; // esi
  unsigned int v20; // eax
  int v21; // ecx
  int v22; // ecx
  bool v23; // zf
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  unsigned int v28; // ecx
  unsigned int *v29; // eax
  int v30; // eax
  unsigned int v31; // ecx
  unsigned int *v32; // eax
  _DWORD *v33; // eax
  _DWORD *v34; // eax
  int **v35; // ebx
  int *v36; // eax
  int *v37; // ecx
  int v38; // esi
  int v39; // edx
  _DWORD *v40; // ecx
  int *v41; // eax
  int v42; // eax
  _DWORD *v43; // eax
  const char *v44; // edi
  D3DXShader::CNodeType *v45; // esi
  int i; // edi
  unsigned int v47; // edi
  int v48; // ebx
  int *v49; // eax
  int *v50; // ecx
  int v51; // edx
  int v52; // edx
  int v53; // esi
  unsigned __int8 *v54; // eax
  unsigned int v55; // esi
  struct D3DXShader::CNodeType *v56; // eax
  int *v57; // esi
  char *v58; // edi
  unsigned __int8 *v59; // eax
  int v60; // eax
  unsigned __int8 *v61; // eax
  int v62; // ebx
  unsigned __int8 *v63; // eax
  int v64; // eax
  unsigned __int8 *v65; // eax
  _DWORD *v66; // esi
  struct D3DXShader::CNodeType *v67; // eax
  struct D3DXShader::CNode *v68; // esi
  unsigned __int8 *v69; // eax
  unsigned __int8 *v70; // eax
  int v71; // eax
  _BYTE v72[16]; // [esp+4h] [ebp-160h] BYREF
  int v73; // [esp+14h] [ebp-150h]
  _DWORD v74[10]; // [esp+1Ch] [ebp-148h] BYREF
  char v75; // [esp+44h] [ebp-120h] BYREF
  _BYTE v76[20]; // [esp+B8h] [ebp-ACh] BYREF
  int v77; // [esp+CCh] [ebp-98h]
  _BYTE v78[20]; // [esp+DCh] [ebp-88h] BYREF
  int v79; // [esp+F0h] [ebp-74h]
  _DWORD v80[5]; // [esp+100h] [ebp-64h]
  _DWORD v81[5]; // [esp+114h] [ebp-50h] BYREF
  _DWORD v82[5]; // [esp+128h] [ebp-3Ch] BYREF
  _DWORD v83[5]; // [esp+13Ch] [ebp-28h] BYREF
  D3DXShader::CParse *v84; // [esp+150h] [ebp-14h]
  const char *v85; // [esp+154h] [ebp-10h]
  int *v86; // [esp+158h] [ebp-Ch]
  unsigned int v87; // [esp+15Ch] [ebp-8h]
  unsigned int v88; // [esp+160h] [ebp-4h]
  struct D3DXShader::CNode *v89; // [esp+170h] [ebp+Ch]
  struct D3DXShader::CNode *v90; // [esp+170h] [ebp+Ch]

  v5 = 0;
  v84 = this;
  if ( a4 != nullptr )
    *a4 = nullptr;
  if ( a5 != nullptr )
    *a5 = nullptr;
  v6 = a3;
  v7 = 0;
  if ( a3 != nullptr )
  {
    do
    {
      v8 = *((_DWORD *)v6 + 2);
      if ( v8 == 0 )
        break;
      if ( *(_DWORD *)(v8 + 4) != 13 )
        break;
      v9 = *(_DWORD *)(v8 + 16);
      if ( v9 == 0 )
        break;
      if ( *(_DWORD *)(v9 + 4) != 9 )
        break;
      v6 = *((struct D3DXShader::CNode **)v6 + 3);
      ++v7;
    }
    while ( v6 != nullptr );
    if ( v6 != nullptr || v7 > 4 )
      return 1;
  }
  v11 = *((const char **)a2 + 2);
  v88 = 94;
  v85 = v11;
  while ( 1 )
  {
    v12 = (v5 + v88) >> 1;
    v13 = strcmp(v85, (&off_102B59B4)[41 * v12]);
    if ( v13 <= 0 )
      break;
    v5 = v12 + 1;
LABEL_19:
    if ( v5 >= v88 )
      goto LABEL_29;
  }
  if ( v13 < 0 )
  {
    v88 = (v5 + v88) >> 1;
    goto LABEL_19;
  }
  v5 = (v5 + v88) >> 1;
  v88 = v12 + 1;
  if ( v12 != 0 )
  {
    v14 = (const char **)((char *)&unk_102B5910 + 164 * v12);
    do
    {
      if ( strcmp(v85, *v14) != 0 )
        break;
      --v5;
      v14 -= 41;
    }
    while ( v5 != 0 );
  }
  if ( v88 < 0x5E )
  {
    v15 = (const char **)&(&off_102B59B4)[41 * v88];
    do
    {
      if ( strcmp(v85, *v15) != 0 )
        break;
      ++v88;
      v15 += 41;
    }
    while ( v88 < 0x5E );
  }
LABEL_29:
  if ( v5 == v88 )
    return 1;
  v85 = (const char *)v5;
  if ( v5 >= v88 )
    goto LABEL_92;
  v86 = &dword_102B59B0[41 * v5];
  while ( 2 )
  {
    memset(v81, 255, sizeof(v81));
    v83[0] = 30;
    v83[1] = 30;
    v83[2] = 30;
    v16 = v86;
    v83[3] = 30;
    v83[4] = 30;
    v82[0] = 5;
    v82[1] = 5;
    v82[2] = 5;
    v82[3] = 5;
    v82[4] = 5;
    D3DXShader::CNodeType::CNodeType(this: (D3DXShader::CNodeType *)v78);
    D3DXShader::CNodeType::CNodeType(this: (D3DXShader::CNodeType *)v76);
    v17 = a3;
    v87 = 1;
    if ( a3 == nullptr )
      break;
    v18 = v16 + 11;
    while ( 2 )
    {
      if ( v87 < 5 && *(v18 - 2) != 0 )
      {
        v19 = *(struct D3DXShader::CNode **)(*((_DWORD *)v17 + 2) + 16);
        v20 = v82[*v18];
        if ( v20 == 5 || v20 == 0 && ((v21 = *((_DWORD *)v19 + 4)) == 1 || v21 == 2) )
        {
          v24 = *v18;
          v82[v24] = *((_DWORD *)v19 + 4);
          v80[v24] = v18[1];
        }
        else
        {
          v22 = *((_DWORD *)v19 + 4);
          if ( v22 != 0 )
          {
            v23 = v22 == v20;
            goto LABEL_44;
          }
          if ( v20 >= 2 )
          {
            v23 = v20 == 2;
LABEL_44:
            if ( !v23 )
              break;
          }
        }
        v25 = v18[2];
        if ( v83[v25] == 30 )
        {
          v26 = v25;
          v83[v26] = *((_DWORD *)v19 + 5);
          v80[v26] = v18[3];
        }
        else
        {
          v79 = v83[v25];
          v77 = *((_DWORD *)v19 + 5);
          if ( D3DXShader::CParse::GetComponentType(
                 this: v84,
                 a2: (struct D3DXShader::CNode *)v78,
                 a3: (struct D3DXShader::CNode *)v76,
                 a4: (enum D3DXShader::_D3DXCOMPONENT_TYPE *)&v83[v18[2]]) < 0 )
            break;
        }
        if ( *((_DWORD *)v19 + 4) != 0 )
        {
          v27 = v18[4];
          if ( v27 >= 0 )
          {
            if ( *((_DWORD *)v19 + 6) < (unsigned int)v27 )
              break;
          }
          else
          {
            v28 = *((_DWORD *)v19 + 6);
            v29 = &v81[~v27];
            if ( *v29 > v28 )
              *v29 = v28;
          }
          v30 = v18[5];
          if ( v30 >= 0 )
          {
            if ( *((_DWORD *)v19 + 7) < (unsigned int)v30 )
              break;
          }
          else
          {
            v31 = *((_DWORD *)v19 + 7);
            v32 = &v81[~v30];
            if ( *v32 > v31 )
              *v32 = v31;
          }
        }
        if ( (*(_BYTE *)(v18 - 1) & 0x20) != 0 && D3DXShader::CParse::IsConst(this: v84, a2: v19) != 0 )
          break;
        v17 = *((struct D3DXShader::CNode **)v17 + 3);
        ++v87;
        v18 += 8;
        if ( v17 == nullptr )
          break;
        continue;
      }
      break;
    }
    if ( v17 != nullptr || (v16 = v86, v87 < 5) && v86[8 * v87 + 1] != 0 )
    {
LABEL_91:
      ++v85;
      v86 += 41;
      if ( (unsigned int)v85 >= v88 )
        goto LABEL_92;
      continue;
    }
    break;
  }
  if ( v16[2] != 0 )
  {
    v33 = &v82[v16[3]];
    if ( *v33 == 5 )
      *v33 = *(_DWORD *)v16[4];
    v34 = &v83[v16[5]];
    if ( *v34 == 30 )
      *v34 = *(_DWORD *)v16[6];
  }
  v87 = 0;
  v35 = (int **)(v86 + 6);
  while ( 2 )
  {
    v36 = *(v35 - 2);
    v37 = &v82[v87];
    v38 = *v37;
    if ( *v37 == 5 )
    {
      if ( v36 != nullptr )
        *v37 = *v36;
    }
    else
    {
      if ( v38 == 0 && ((v39 = *v36, *v36 == 1) || v39 == 2) )
      {
        *v37 = v39;
      }
      else
      {
        while ( *v36 != 5 && v38 != *v36 )
          ++v36;
      }
      if ( *v36 == 5 )
        break;
    }
    v40 = &v83[v87];
    v41 = *v35;
    if ( *v40 == 30 )
    {
      if ( v41 != nullptr )
      {
        v42 = *v41;
        goto LABEL_86;
      }
    }
    else
    {
      while ( *v41 != 30 && *v40 != *v41 )
        ++v41;
      if ( *v41 == 30 )
      {
        v42 = **v35;
LABEL_86:
        *v40 = v42;
      }
    }
    v43 = &v81[v87];
    if ( *v43 == -1 )
      *v43 = 1;
    ++v87;
    v35 += 8;
    if ( v87 < 5 )
      continue;
    break;
  }
  if ( v87 != 5 )
    goto LABEL_91;
LABEL_92:
  v44 = v85;
  if ( v85 == (const char *)v88 )
    return 1;
  if ( a4 != nullptr )
  {
    v45 = (D3DXShader::CNodeType *)v72;
    for ( i = 5; i != 0; --i )
    {
      D3DXShader::CNodeType::CNodeType(this: v45);
      v45 = (D3DXShader::CNodeType *)((char *)v45 + 36);
    }
    v47 = 0;
    v48 = 41 * (_DWORD)v85;
    v49 = v74;
    v50 = (int *)((char *)&unk_102B59CC + 164 * (_DWORD)v85);
    do
    {
      if ( *(v50 - 6) == 0 )
        break;
      v89 = (struct D3DXShader::CNode *)*(v50 - 5);
      if ( v89 != nullptr )
      {
        *(v49 - 2) = v82[*(v50 - 4)];
        *(v49 - 1) = v83[*(v50 - 2)];
        v51 = *v50;
        if ( *v50 < 0 )
          v51 = v81[~v51];
        *v49 = v51;
        v52 = v50[1];
        if ( v52 < 0 )
          v52 = v81[~v52];
        v53 = (unsigned __int16)v89 & 0xC00;
        v49[1] = v52;
        v49[2] = v53;
        if ( v47 == 0 || ((unsigned __int8)v89 & 0x20) == 0 )
          v49[2] = v53 | 0x200;
      }
      ++v47;
      v50 += 8;
      v49 += 9;
    }
    while ( v47 < 5 );
    if ( (v73 == 1 || v73 == 2) && v74[1] == 1 && v74[0] == 1 )
      v73 = 0;
    v54 = D3DXShader::CNode::operator new(a1: 0x40u);
    if ( v54 != nullptr )
    {
      v55 = D3DXShader::CNodeFunction::CNodeFunction(this: (D3DXShader::CNodeFunction *)v54);
      v88 = v55;
    }
    else
    {
      v88 = 0;
      v55 = 0;
    }
    if ( v55 != 0 )
    {
      if ( dword_102B59B8[v48] == 0
        || (v56 = D3DXShader::CNodeType::Copy(this: (D3DXShader::CNodeType *)v72),
            *(_DWORD *)(v55 + 32) = v56,
            v56 != nullptr) )
      {
        v57 = (int *)(v55 + 36);
        v86 = v57;
        v87 = 1;
        v58 = &v75;
        v90 = (struct D3DXShader::CNode *)((char *)&off_102B59D4 + v48 * 4);
        do
        {
          if ( *(_DWORD *)v90 == 0 )
            break;
          v59 = D3DXShader::CNode::operator new(a1: 0x14u);
          if ( v59 != nullptr )
            v60 = D3DXShader::CNodeList::CNodeList(
                    this: (D3DXShader::CNodeList *)v59,
                    a2: nullptr,
                    a3: nullptr,
                    a4: "Decls");
          else
            v60 = 0;
          *v57 = v60;
          if ( v60 == 0 )
            return -2147024882;
          v61 = D3DXShader::CNode::operator new(a1: 0x30u);
          v62 = v61 != nullptr ? D3DXShader::CNodeDecl::CNodeDecl(a1: v61, a2: 1, a3: 0, a4: 0, a5: 0) : 0;
          if ( v62 == 0 )
            return -2147024882;
          *(_DWORD *)(*v86 + 8) = v62;
          v63 = D3DXShader::CNode::operator new(a1: 0x30u);
          v64 = v63 != nullptr ? D3DXShader::CNodeToken::CNodeToken(this: (D3DXShader::CNodeToken *)v63, a2) : 0;
          *(_DWORD *)(v62 + 20) = v64;
          if ( v64 == 0 )
            return -2147024882;
          *(_DWORD *)(v64 + 24) = *(_DWORD *)v90;
          v65 = D3DXShader::CNode::operator new(a1: 0x40u);
          v66 = v65 != nullptr
              ? (_DWORD *)D3DXShader::CNodeVariable::CNodeVariable(this: (D3DXShader::CNodeVariable *)v65)
              : nullptr;
          if ( v66 == nullptr )
            return -2147024882;
          *(_DWORD *)(v62 + 24) = v66;
          v66[4] = -1;
          v66[5] = *(_DWORD *)v58 * *((_DWORD *)v58 - 1);
          v66[6] = 2;
          v66[7] = *((_DWORD *)v90 + 1);
          v67 = D3DXShader::CNodeType::Copy(this: (D3DXShader::CNodeType *)(v58 - 28));
          v66[8] = v67;
          if ( v67 == nullptr )
            return -2147024882;
          v90 = (struct D3DXShader::CNode *)((char *)v90 + 32);
          v57 = (int *)(*v86 + 12);
          ++v87;
          v58 += 36;
          v86 = v57;
        }
        while ( v87 < 5 );
        v44 = v85;
        *a4 = (struct D3DXShader::CNode *)v88;
        goto LABEL_145;
      }
    }
    return -2147024882;
  }
  else
  {
LABEL_145:
    v68 = nullptr;
    if ( a5 != nullptr )
    {
      v69 = D3DXShader::CNode::operator new(a1: 0x14u);
      if ( v69 != nullptr )
        v68 = (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                            this: (D3DXShader::CNodeList *)v69,
                                            a2: nullptr,
                                            a3: nullptr,
                                            a4: "Values");
      if ( v68 == nullptr )
        return -2147024882;
      v70 = D3DXShader::CNode::operator new(a1: 0x40u);
      v71 = v70 != nullptr
          ? D3DXShader::CNodeValue::CNodeValue(a1: v70, a2: 2, a3: dword_102B59B0[41 * (_DWORD)v44], a4: a2)
          : 0;
      *((_DWORD *)v68 + 2) = v71;
      if ( v71 == 0 )
        return -2147024882;
      *a5 = v68;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6249
// Name: protected: unsigned int D3DXShader::CParse::ScoreFunctionDecl(class D3DXShader::CNodeFunction __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CParse::ScoreFunctionDecl(
        D3DXShader::CParse *this,
        struct D3DXShader::CNodeFunction *a2,
        const char **a3,
        struct D3DXShader::CNode *a4,
        unsigned int a5)
{
  int v5; // eax
  int v7; // edx
  int v9; // eax
  int v10; // ecx
  _DWORD v11[3]; // [esp+8h] [ebp-1Ch] BYREF
  D3DXShader::CParse *v12[3]; // [esp+14h] [ebp-10h] BYREF
  D3DXShader::CParse *v13; // [esp+20h] [ebp-4h]

  v5 = *((_DWORD *)a2 + 7);
  v13 = this;
  if ( (a3 == nullptr) != (v5 == 0) )
    return -1;
  if ( a3 != nullptr )
  {
    if ( D3DXGetTargetDescByName(a1: *(const char **)(v5 + 24), a2: 0, a3: v12) < 0
      || D3DXGetTargetDescByName(a1: a3[6], a2: 0, a3: v11) < 0 )
    {
      if ( strcmp(a3[6], *(const char **)(*((_DWORD *)a2 + 7) + 24)) != 0 )
        return -1;
    }
    else if ( v12[1] != (D3DXShader::CParse *)v11[1] )
    {
      return -1;
    }
  }
  v7 = *((_DWORD *)a2 + 9);
  while ( v7 != 0 )
  {
    if ( a4 == nullptr )
      return -1;
    v9 = *(_DWORD *)(*(_DWORD *)(v7 + 8) + 24);
    v10 = *(_DWORD *)(*((_DWORD *)a4 + 2) + 24);
    if ( *(_DWORD *)(v9 + 28) != *(_DWORD *)(v10 + 28)
      || !D3DXShader::CParse::IsTypeEqual(
            this: v13,
            a2: *(struct D3DXShader::CNode **)(v9 + 32),
            a3: *(struct D3DXShader::CNode **)(v10 + 32)) )
    {
      return -1;
    }
    do
      v7 = *(_DWORD *)(v7 + 12);
    while ( v7 != 0 && *(_DWORD *)(*(_DWORD *)(v7 + 8) + 4) != 6 );
    do
      a4 = *((struct D3DXShader::CNode **)a4 + 3);
    while ( a4 != nullptr && *(_DWORD *)(*((_DWORD *)a4 + 2) + 4) != 6 );
  }
  if ( a4 != nullptr )
    return -1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6358
// Name: protected: unsigned int D3DXShader::CParse::ScoreCast(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CParse::ScoreCast(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  unsigned int v3; // edi
  unsigned int result; // eax
  int v6; // ebx
  _BYTE v7[20]; // [esp+8h] [ebp-5Ch] BYREF
  int v8; // [esp+1Ch] [ebp-48h]
  _BYTE v9[20]; // [esp+2Ch] [ebp-38h] BYREF
  int v10; // [esp+40h] [ebp-24h]
  unsigned int v11; // [esp+50h] [ebp-14h]
  int v12; // [esp+54h] [ebp-10h] BYREF
  unsigned int v13; // [esp+58h] [ebp-Ch]
  unsigned int v14; // [esp+5Ch] [ebp-8h]
  int v15; // [esp+60h] [ebp-4h]

  v3 = 0;
  v11 = 0;
  v14 = D3DXShader::CParse::TypeSize(this, a2);
  v13 = D3DXShader::CParse::TypeSize(this, a2: a3);
  if ( D3DXShader::CParse::IsTypeEqual(this, a2, a3) )
    return 0;
  v6 = 0;
  v15 = 0;
  D3DXShader::CNodeType::CNodeType(this: (D3DXShader::CNodeType *)v9);
  D3DXShader::CNodeType::CNodeType(this: (D3DXShader::CNodeType *)v7);
  if ( v14 != 0 )
  {
    do
    {
      if ( v3 >= v13 )
        break;
      if ( D3DXShader::CParse::GetSubType(this, a2, a3: v3, a4: (struct D3DXShader::CNodeType *)v9) < 0
        || D3DXShader::CParse::GetSubType(this, a2: a3, a3: v3, a4: (struct D3DXShader::CNodeType *)v7) < 0
        || D3DXShader::CParse::GetComponentType(
             this,
             a2: (struct D3DXShader::CNode *)v9,
             a3: (struct D3DXShader::CNode *)v7,
             a4: (enum D3DXShader::_D3DXCOMPONENT_TYPE *)&v12) < 0 )
      {
        v6 = 1;
        v15 = 1;
      }
      else
      {
        if ( D3DXShader::CParse::IsCast(a1: v10, a2: v12) != 0 )
          v6 = 1;
        if ( D3DXShader::CParse::IsCast(a1: v12, a2: v8) != 0 )
          v15 = 1;
      }
      if ( v6 != 0 && v15 != 0 )
        break;
      ++v3;
    }
    while ( v3 < v14 );
  }
  if ( v13 >= v14 )
    result = v11;
  else
    result = 4;
  if ( v6 != 0 )
    result += 512;
  if ( v15 != 0 )
    result += 0x10000;
  if ( v14 < v13 )
    result += 0x800000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F647B
// Name: protected: long D3DXShader::CParse::ApplyUsage(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::ApplyUsage(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode **a3)
{
  int v3; // esi
  int v5; // ebx

  v3 = *((_DWORD *)a2 + 4);
  if ( (v3 & 0x200) != 0 )
    D3DXShader::CParse::MakeTypeConst(this, a2: a3, a3: 1);
  if ( a3 != nullptr && a3[1] == (struct D3DXShader::CNode *)9 && a3[4] == (struct D3DXShader::CNode *)2 )
  {
    if ( (v3 & 0xC00) == 0 )
      v3 |= *(_DWORD *)(*((_DWORD *)this + 1) + 56);
    if ( (v3 & 0xC00) == 0 )
    {
      v5 = *(_DWORD *)this;
      if ( (v5 & 8) != 0 )
      {
        LOWORD(v3) = v3 | 0x400;
      }
      else if ( (v5 & 0x10) != 0 )
      {
        LOWORD(v3) = v3 | 0x800;
      }
    }
    if ( (v3 & 0x400) != 0 )
      a3[8] = (struct D3DXShader::CNode *)((unsigned int)a3[8] & 0xFFFFF3FF | 0x400);
    if ( (v3 & 0x800) != 0 )
      a3[8] = (struct D3DXShader::CNode *)((unsigned int)a3[8] & 0xFFFFF3FF | 0x800);
  }
  else if ( (v3 & 0xC00) != 0 )
  {
    D3DXShader::CParse::Error(
      this,
      a2: (D3DXShader::CParse *)((char *)this + 32),
      a3: 0xC05u,
      format: "non-matrix types cannot be declared 'row_major' or 'column_major'");
    return -2147467259;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F652E
// Name: protected: int D3DXShader::CParse::IsSupportedCast(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CParse::IsSupportedCast(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        int a4)
{
  struct D3DXShader::CNode *v5; // edi
  struct D3DXShader::CNode *v6; // esi
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // eax
  int v10; // esi
  bool v11; // zf
  unsigned int v12; // eax
  int v13; // edi
  int v14; // esi
  int v15; // edi
  int v16; // edi
  unsigned int v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // esi
  unsigned int v20; // esi
  _BYTE v21[16]; // [esp+Ch] [ebp-4Ch] BYREF
  int v22; // [esp+1Ch] [ebp-3Ch]
  int v23; // [esp+24h] [ebp-34h]
  int v24; // [esp+28h] [ebp-30h]
  _BYTE v25[16]; // [esp+30h] [ebp-28h] BYREF
  int v26; // [esp+40h] [ebp-18h]
  int v27; // [esp+48h] [ebp-10h]
  int v28; // [esp+4Ch] [ebp-Ch]
  D3DXShader::CParse *v29; // [esp+54h] [ebp-4h]

  v29 = this;
  if ( a4 != 0 )
  {
    if ( a2 == nullptr )
      return true;
  }
  else if ( a2 == nullptr )
  {
    return a3 == nullptr;
  }
  if ( a3 == nullptr )
    return false;
  D3DXShader::CNodeType::CNodeType(this: (D3DXShader::CNodeType *)v21);
  D3DXShader::CNodeType::CNodeType(this: (D3DXShader::CNodeType *)v25);
  if ( *((_DWORD *)a2 + 1) == 9 )
  {
    v5 = a2;
  }
  else
  {
    v5 = (struct D3DXShader::CNode *)v21;
    v22 = 4;
    v23 = 1;
    v24 = D3DXShader::CParse::TypeSize(this: v29, a2);
    if ( a4 != 0 && D3DXShader::CParse::IsNumeric(this: v29, a2) )
      v22 = 1;
  }
  if ( *((_DWORD *)a3 + 1) == 9 )
  {
    v6 = a3;
  }
  else
  {
    v6 = (struct D3DXShader::CNode *)v25;
    v26 = 4;
    v27 = 1;
    v28 = D3DXShader::CParse::TypeSize(this: v29, a2: a3);
    if ( a4 != 0 && D3DXShader::CParse::IsNumeric(this: v29, a2: a3) )
      v26 = 1;
  }
  v7 = *((_DWORD *)v5 + 4);
  if ( v7 != 4 )
  {
    v8 = *((_DWORD *)v6 + 4);
    if ( v8 != 4 )
    {
      switch ( v7 )
      {
        case 0:
          return v8 != 3;
        case 1:
          if ( v8 == 0 )
            return true;
          if ( v8 != 1 )
          {
            if ( v8 == 2 )
            {
              v9 = *((_DWORD *)v6 + 6);
              if ( v9 == 1 && *((_DWORD *)v5 + 7) > *((_DWORD *)v6 + 7) )
                return false;
              v10 = *((_DWORD *)v6 + 7);
              if ( v10 == 1 && *((_DWORD *)v5 + 7) > v9 )
                return false;
              if ( v9 != 1 && v10 != 1 )
              {
                v11 = v10 * v9 == *((_DWORD *)v5 + 7);
                break;
              }
              return true;
            }
            return v8 != 3;
          }
          return *((_DWORD *)v5 + 7) <= *((_DWORD *)v6 + 7);
        case 2:
          if ( v8 == 0 )
            return true;
          if ( v8 != 1 )
          {
            if ( v8 != 2 )
              return v8 != 3;
            if ( *((_DWORD *)v5 + 6) > *((_DWORD *)v6 + 6) )
              return false;
            return *((_DWORD *)v5 + 7) <= *((_DWORD *)v6 + 7);
          }
          v12 = *((_DWORD *)v5 + 6);
          if ( v12 == 1 && *((_DWORD *)v5 + 7) > *((_DWORD *)v6 + 7) )
            return false;
          v13 = *((_DWORD *)v5 + 7);
          if ( v13 == 1 && v12 > *((_DWORD *)v6 + 7) )
            return false;
          if ( v12 == 1 || v13 == 1 )
            return true;
          v11 = v13 * v12 == *((_DWORD *)v6 + 7);
          break;
        case 3:
          if ( v8 != 3 )
            return false;
          v14 = *((_DWORD *)v6 + 5);
          switch ( v14 )
          {
            case 13:
              return true;
            case 15:
              v15 = *((_DWORD *)v5 + 5);
              if ( v15 == 15 || v15 == 16 || v15 == 17 || v15 == 18 )
                return true;
              v11 = v15 == 19;
              break;
            case 20:
              v16 = *((_DWORD *)v5 + 5);
              if ( v16 == 20 || v16 == 21 || v16 == 22 || v16 == 23 )
                return true;
              v11 = v16 == 24;
              break;
            default:
              v11 = *((_DWORD *)v5 + 5) == v14;
              break;
          }
          break;
        default:
          return true;
      }
      return v11;
    }
  }
  v17 = *((_DWORD *)v5 + 6) * *((_DWORD *)v5 + 7);
  v18 = *((_DWORD *)v6 + 6) * *((_DWORD *)v6 + 7);
  if ( a4 != 0 )
  {
    if ( v17 > v18 )
      return false;
    v19 = 0;
    if ( v17 != 0 )
    {
      while ( D3DXShader::CParse::GetSubType(this: v29, a2, a3: v19, a4: (struct D3DXShader::CNodeType *)v21) >= 0
           && D3DXShader::CParse::GetSubType(this: v29, a2: a3, a3: v19, a4: (struct D3DXShader::CNodeType *)v25) >= 0
           && D3DXShader::CParse::IsSupportedCast(
                this: v29,
                a2: (struct D3DXShader::CNode *)v21,
                a3: (struct D3DXShader::CNode *)v25,
                a4: 1) != 0 )
      {
        if ( ++v19 >= v17 )
          return true;
      }
      return false;
    }
  }
  else
  {
    if ( v7 != *((_DWORD *)v6 + 4) || v17 != v18 )
      return false;
    v20 = 0;
    if ( v17 != 0 )
    {
      while ( D3DXShader::CParse::GetSubType(this: v29, a2, a3: v20, a4: (struct D3DXShader::CNodeType *)v21) >= 0
           && D3DXShader::CParse::GetSubType(this: v29, a2: a3, a3: v20, a4: (struct D3DXShader::CNodeType *)v25) >= 0
           && D3DXShader::CParse::IsTypeEqual(
                this: v29,
                a2: (struct D3DXShader::CNode *)v21,
                a3: (struct D3DXShader::CNode *)v25) )
      {
        if ( ++v20 >= v17 )
          return true;
      }
      return false;
    }
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101F6866
// Name: protected: void D3DXShader::CParse::ErrorUnsupportedCast(struct D3DXShader::D3DXTOKEN __near *,char const __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CParse::ErrorUnsupportedCast(
        D3DXShader::CParse *this,
        struct D3DXShader::D3DXTOKEN *a2,
        const char *a3,
        struct D3DXShader::CNode *a4,
        struct D3DXShader::CNode *a5,
        int a6)
{
  struct D3DXShader::CNode *v6; // esi
  struct D3DXShader::CNode *v7; // edi
  int v8; // ecx
  int v9; // eax
  const char *v10; // edi
  D3DXShader::CParse *v11; // ebx
  unsigned int v12; // eax
  int v13; // edi
  bool v14; // zf
  unsigned int v15; // eax
  int v16; // esi
  int v17; // edi
  int v18; // esi
  int v19; // esi
  unsigned int v20; // ebx
  unsigned int v21; // esi
  _BYTE v22[16]; // [esp+Ch] [ebp-260h] BYREF
  int v23; // [esp+1Ch] [ebp-250h]
  int v24; // [esp+24h] [ebp-248h]
  int v25; // [esp+28h] [ebp-244h]
  _BYTE v26[16]; // [esp+30h] [ebp-23Ch] BYREF
  int v27; // [esp+40h] [ebp-22Ch]
  int v28; // [esp+48h] [ebp-224h]
  int v29; // [esp+4Ch] [ebp-220h]
  const char *v30; // [esp+54h] [ebp-218h]
  struct D3DXShader::D3DXTOKEN *v31; // [esp+58h] [ebp-214h]
  struct D3DXShader::CNode *v32; // [esp+5Ch] [ebp-210h]
  struct D3DXShader::CNode *v33; // [esp+60h] [ebp-20Ch]
  D3DXShader::CParse *v34; // [esp+64h] [ebp-208h]
  char v35[256]; // [esp+68h] [ebp-204h] BYREF
  char v36[256]; // [esp+168h] [ebp-104h] BYREF

  v31 = a2;
  v6 = a4;
  v30 = a3;
  v34 = this;
  v32 = a4;
  v33 = a5;
  if ( a6 != 0 || a4 == nullptr )
    goto LABEL_68;
  if ( a5 == nullptr )
  {
LABEL_17:
    v10 = "implicitly ";
    goto LABEL_18;
  }
  D3DXShader::CNodeType::CNodeType(this: (D3DXShader::CNodeType *)v26);
  D3DXShader::CNodeType::CNodeType(this: (D3DXShader::CNodeType *)v22);
  if ( *((_DWORD *)a4 + 1) != 9 )
  {
    v6 = (struct D3DXShader::CNode *)v26;
    v27 = 4;
    v28 = 1;
    v29 = D3DXShader::CParse::TypeSize(this: v34, a2: v32);
    if ( D3DXShader::CParse::IsNumeric(this: v34, a2: v32) )
      v27 = 1;
  }
  v7 = v33;
  if ( *((_DWORD *)v33 + 1) != 9 )
  {
    v7 = (struct D3DXShader::CNode *)v22;
    v23 = 4;
    v24 = 1;
    v25 = D3DXShader::CParse::TypeSize(this: v34, a2: v33);
    if ( D3DXShader::CParse::IsNumeric(this: v34, a2: v33) )
      v23 = 1;
  }
  v8 = *((_DWORD *)v6 + 4);
  if ( v8 == 4 || (v9 = *((_DWORD *)v7 + 4)) == 4 )
  {
    v20 = *((_DWORD *)v6 + 6) * *((_DWORD *)v6 + 7);
    if ( v20 > *((_DWORD *)v7 + 6) * *((_DWORD *)v7 + 7) )
      goto LABEL_17;
    v21 = 0;
    if ( v20 != 0 )
    {
      while ( D3DXShader::CParse::GetSubType(this: v34, a2: v32, a3: v21, a4: (struct D3DXShader::CNodeType *)v26) >= 0
           && D3DXShader::CParse::GetSubType(this: v34, a2: v33, a3: v21, a4: (struct D3DXShader::CNodeType *)v22) >= 0
           && D3DXShader::CParse::IsSupportedCast(
                this: v34,
                a2: (struct D3DXShader::CNode *)v26,
                a3: (struct D3DXShader::CNode *)v22,
                a4: 1) )
      {
        if ( ++v21 >= v20 )
          goto LABEL_68;
      }
      goto LABEL_17;
    }
    goto LABEL_68;
  }
  if ( v8 == 0 )
    goto LABEL_42;
  if ( v8 != 1 )
  {
    if ( v8 == 2 )
    {
      if ( v9 == 0 )
        goto LABEL_68;
      if ( v9 != 1 )
      {
        if ( v9 == 2 )
        {
          if ( *((_DWORD *)v6 + 6) > *((_DWORD *)v7 + 6) || *((_DWORD *)v6 + 7) > *((_DWORD *)v7 + 7) )
            goto LABEL_17;
          goto LABEL_68;
        }
        goto LABEL_42;
      }
      v15 = *((_DWORD *)v6 + 6);
      if ( v15 == 1 && *((_DWORD *)v6 + 7) > *((_DWORD *)v7 + 7) )
        goto LABEL_17;
      v16 = *((_DWORD *)v6 + 7);
      if ( v16 == 1 && v15 > *((_DWORD *)v7 + 7) )
        goto LABEL_17;
      if ( v15 == 1 || v16 == 1 )
        goto LABEL_68;
      v14 = v16 * v15 == *((_DWORD *)v7 + 7);
    }
    else
    {
      if ( v8 != 3 )
        goto LABEL_68;
      if ( v9 != 3 )
        goto LABEL_17;
      v17 = *((_DWORD *)v7 + 5);
      switch ( v17 )
      {
        case 13:
          goto LABEL_68;
        case 15:
          v18 = *((_DWORD *)v6 + 5);
          if ( v18 == 15 || v18 == 16 || v18 == 17 || v18 == 18 )
            goto LABEL_68;
          v14 = v18 == 19;
          break;
        case 20:
          v19 = *((_DWORD *)v6 + 5);
          if ( v19 == 20 || v19 == 21 || v19 == 22 || v19 == 23 )
            goto LABEL_68;
          v14 = v19 == 24;
          break;
        default:
          v14 = *((_DWORD *)v6 + 5) == v17;
          break;
      }
    }
LABEL_59:
    if ( !v14 )
      goto LABEL_17;
    goto LABEL_68;
  }
  if ( v9 == 0 )
    goto LABEL_68;
  if ( v9 != 1 )
  {
    if ( v9 == 2 )
    {
      v12 = *((_DWORD *)v7 + 6);
      if ( v12 == 1 && *((_DWORD *)v6 + 7) > *((_DWORD *)v7 + 7) )
        goto LABEL_17;
      v13 = *((_DWORD *)v7 + 7);
      if ( v13 == 1 && *((_DWORD *)v6 + 7) > v12 )
        goto LABEL_17;
      if ( v12 == 1 || v13 == 1 )
        goto LABEL_68;
      v14 = v13 * v12 == *((_DWORD *)v6 + 7);
      goto LABEL_59;
    }
LABEL_42:
    if ( v9 == 3 )
      goto LABEL_17;
    goto LABEL_68;
  }
  if ( *((_DWORD *)v6 + 7) > *((_DWORD *)v7 + 7) )
    goto LABEL_17;
LABEL_68:
  v10 = (const char *)&pMem;
LABEL_18:
  v11 = v34;
  D3DXShader::CParse::PrintType(this: v34, a2: v36, a3: 0xFFu, a4: v32);
  D3DXShader::CParse::PrintType(this: v11, a2: v35, a3: 0xFFu, a4: v33);
  if ( v30 != nullptr )
    D3DXShader::CParse::Error(
      this: v11,
      a2: v31,
      a3: 0xBC9u,
      format: "'%s': cannot %sconvert from '%s' to '%s'",
      v30,
      v10,
      v35,
      v36);
  else
    D3DXShader::CParse::Error(
      this: v11,
      a2: v31,
      a3: 0xBC9u,
      format: "cannot %sconvert from '%s' to '%s'",
      v10,
      v35,
      v36);
}

//------------------------------------------------------------------------------
// Address: 0x101F6C47
// Name: protected: long D3DXShader::CParse::BinaryType(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near * __near *,class D3DXShader::CNode __near * __near *,class D3DXShader::CNode __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::BinaryType(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode **a4,
        struct D3DXShader::CNode **a5,
        struct D3DXShader::CNode **a6)
{
  struct D3DXShader::CNode **v6; // eax
  int result; // eax
  struct D3DXShader::CNode *v8; // ebx
  unsigned int v9; // esi
  struct D3DXShader::CNode *v10; // esi
  struct D3DXShader::CNode *v11; // edi
  int v12; // eax
  struct D3DXShader::CNode **v13; // edi
  struct D3DXShader::CNode **v14; // eax

  if ( a4 == nullptr )
    return -2147467259;
  v6 = a5;
  if ( a5 == nullptr )
    return -2147467259;
  *a4 = nullptr;
  *v6 = nullptr;
  if ( a6 != nullptr )
    *a6 = nullptr;
  if ( a2 == nullptr )
  {
    if ( a3 != nullptr )
      return -2147467259;
    return 0;
  }
  v8 = a3;
  if ( a3 == nullptr )
    return -2147467259;
  v9 = D3DXShader::CParse::TypeSize(this, a2);
  if ( v9 < D3DXShader::CParse::TypeSize(this, a2: v8) || !D3DXShader::CParse::IsSupportedCast(this, a2, a3: v8, a4: 0) )
  {
    if ( D3DXShader::CParse::IsSupportedCast(this, a2: v8, a3: a2, a4: 0) )
    {
      v10 = v8;
      goto LABEL_16;
    }
    if ( !D3DXShader::CParse::IsSupportedCast(this, a2, a3: v8, a4: 0) )
      return -2147467259;
  }
  v10 = a2;
LABEL_16:
  result = D3DXShader::CParse::GetComponentType(this, a2, a3: v8, a4: (enum D3DXShader::_D3DXCOMPONENT_TYPE *)&a3);
  if ( result >= 0 )
  {
    v11 = a3;
    if ( *((struct D3DXShader::CNode **)v10 + 5) != a3 )
    {
      v12 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)v10 + 4))(a1: v10);
      if ( v12 == 0 )
        return -2147024882;
      *(_DWORD *)(v12 + 20) = v11;
      v10 = (struct D3DXShader::CNode *)v12;
    }
    v13 = a6;
    if ( a6 != nullptr )
    {
      v14 = (struct D3DXShader::CNode **)(*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)v10 + 4))(a1: v10);
      *v13 = (struct D3DXShader::CNode *)v14;
      if ( v14 == nullptr )
        return -2147024882;
      D3DXShader::CParse::MakeTypeConst(this, a2: v14, a3: 1);
    }
    *a4 = v10;
    *a5 = v10;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D45
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::ScalarExpr(enum D3DXShader::_D3DXCOMPONENT_TYPE,unsigned int,double,struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::ScalarExpr(D3DXShader::CParse *this, int a2, int a3, int a4, int a5, int a6)
{
  unsigned __int8 *v6; // eax
  int v7; // esi
  unsigned __int8 *v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // eax
  unsigned __int8 *v12; // eax
  int v13; // eax
  int v16; // [esp+1Ch] [ebp-4h]

  v16 = 2;
  if ( a2 != 0 )
  {
    if ( a2 > 0 )
    {
      if ( a2 <= 4 )
      {
        v16 = 1;
      }
      else if ( a2 <= 8 )
      {
        v16 = 2;
      }
      else if ( a2 <= 12 )
      {
        v16 = 3;
      }
    }
  }
  else
  {
    v16 = 0;
  }
  v6 = D3DXShader::CNode::operator new(a1: 0x50u);
  if ( v6 != nullptr )
    v7 = D3DXShader::CNodeExpression::CNodeExpression(a1: v6, a2: 0, a3: 0, a4: 0, a5: 0, a6: 1, a7: a6);
  else
    v7 = 0;
  if ( v7 == 0 )
    return 0;
  v8 = D3DXShader::CNode::operator new(a1: 0x24u);
  v9 = v8 != nullptr ? D3DXShader::CNodeType::CNodeType(a1: v8, a2: 0, a3: a2, a4: 1, a5: 1, a6: 512) : 0;
  *(_DWORD *)(v7 + 16) = v9;
  if ( v9 == 0 )
    return 0;
  v10 = D3DXShader::CNode::operator new(a1: 0x40u);
  if ( v16 == 3 )
    v11 = v10 != nullptr ? D3DXShader::CNodeValue::CNodeValue(a1: v10, a2: 3, a3: a4, a4: a5, a5: a6) : 0;
  else
    v11 = v10 != nullptr ? D3DXShader::CNodeValue::CNodeValue(a1: v10, a2: v16, a3, a4: a6) : 0;
  *(_DWORD *)(v7 + 32) = v11;
  if ( v11 == 0 )
    return 0;
  v12 = D3DXShader::CNode::operator new(a1: 0x14u);
  v13 = v12 != nullptr
      ? D3DXShader::CNodeList::CNodeList(
          this: (D3DXShader::CNodeList *)v12,
          a2: *(struct D3DXShader::CNode **)(v7 + 32),
          a3: nullptr,
          a4: "Value")
      : 0;
  if ( v13 == 0 )
    return 0;
  *(_DWORD *)(v7 + 32) = v13;
  D3DXShader::CParse::ComputeExprSize(this, a2: (struct D3DXShader::CNode *)v7);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101F6E5D
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::ScalarExpr(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::ScalarExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2)
{
  unsigned __int64 v2; // st7
  int v3; // edi
  char *v4; // eax
  unsigned int v5; // edx
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-Ch]

  *(double *)&v2 = 0.0;
  v3 = 0;
  v4 = (char *)this + 32;
  v5 = 5;
  if ( a2 == nullptr || *((_DWORD *)a2 + 1) != 3 )
    return (struct D3DXShader::CNode *)D3DXShader::CParse::ScalarExpr(
                                         this,
                                         a2: v5,
                                         a3: v3,
                                         a4: v2,
                                         a5: HIDWORD(v2),
                                         a6: (int)v4);
  v4 = (char *)a2 + 16;
  switch ( *((_DWORD *)a2 + 4) )
  {
    case 2:
      v5 = (*((_DWORD *)a2 + 6) & 0x9FFFFFFF | 0x20000000) >> 29;
      v3 = *((_DWORD *)a2 + 6);
      return (struct D3DXShader::CNode *)D3DXShader::CParse::ScalarExpr(
                                           this,
                                           a2: v5,
                                           a3: v3,
                                           a4: v2,
                                           a5: HIDWORD(v2),
                                           a6: (int)v4);
    case 3:
      v8 = 4;
      goto LABEL_16;
    case 4:
      v8 = 8;
LABEL_16:
      v3 = *((_DWORD *)a2 + 6);
      v5 = v8;
      return (struct D3DXShader::CNode *)D3DXShader::CParse::ScalarExpr(
                                           this,
                                           a2: v5,
                                           a3: v3,
                                           a4: v2,
                                           a5: HIDWORD(v2),
                                           a6: (int)v4);
    case 5:
      v7 = 9;
      goto LABEL_11;
    case 6:
      v7 = 10;
      goto LABEL_11;
    case 7:
      v7 = 11;
      goto LABEL_11;
    case 8:
      v7 = 12;
LABEL_11:
      v5 = v7;
      v2 = *((unsigned __int64 *)a2 + 3);
      break;
    default:
      break;
  }
  return (struct D3DXShader::CNode *)D3DXShader::CParse::ScalarExpr(
                                       this,
                                       a2: v5,
                                       a3: v3,
                                       a4: v2,
                                       a5: HIDWORD(v2),
                                       a6: (int)v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F6EE1
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::StringExpr(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::StringExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2)
{
  char *v3; // ebx
  unsigned __int8 *v4; // eax
  int v5; // esi
  unsigned __int8 *v6; // eax
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // eax
  int v10; // eax
  unsigned __int8 *v12; // [esp+14h] [ebp+8h]

  if ( a2 == nullptr )
    return nullptr;
  v3 = (char *)a2 + 16;
  v4 = D3DXShader::CNode::operator new(a1: 0x50u);
  if ( v4 != nullptr )
    v5 = D3DXShader::CNodeExpression::CNodeExpression(a1: v4, a2: 0, a3: 0, a4: 0, a5: 0, a6: 1, a7: v3);
  else
    v5 = 0;
  if ( v5 == 0 )
    return nullptr;
  v6 = D3DXShader::CNode::operator new(a1: 0x24u);
  v7 = v6 != nullptr ? D3DXShader::CNodeType::CNodeType(a1: v6, a2: 3, a3: 14, a4: 1, a5: 1, a6: 512) : 0;
  *(_DWORD *)(v5 + 16) = v7;
  if ( v7 == 0 )
    return nullptr;
  v12 = D3DXShader::CNode::operator new(a1: 0x40u);
  v8 = v12 != nullptr
     ? D3DXShader::CNodeValue::CNodeValue(
         a1: v12,
         a2: 5,
         a3: *((_DWORD *)v3 + 2),
         a4: strlen(*((const char **)v3 + 2)) + 1,
         a5: v3)
     : 0;
  *(_DWORD *)(v5 + 32) = v8;
  if ( v8 == 0 )
    return nullptr;
  v9 = D3DXShader::CNode::operator new(a1: 0x14u);
  v10 = v9 != nullptr
      ? D3DXShader::CNodeList::CNodeList(
          this: (D3DXShader::CNodeList *)v9,
          a2: *(struct D3DXShader::CNode **)(v5 + 32),
          a3: nullptr,
          a4: "Value")
      : 0;
  if ( v10 == 0 )
    return nullptr;
  *(_DWORD *)(v5 + 32) = v10;
  D3DXShader::CParse::ComputeExprSize(this, a2: (struct D3DXShader::CNode *)v5);
  return (struct D3DXShader::CNode *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x101F6FC7
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::InitExpr(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::InitExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  unsigned __int8 *v4; // eax
  struct D3DXShader::CNode *v5; // ebx
  int v6; // eax
  struct D3DXShader::CNode *v7; // eax
  _DWORD *v8; // esi
  int v10; // ebx
  unsigned __int8 *v11; // eax
  int v12; // eax
  int v13; // esi
  struct D3DXShader::CNode *v15; // [esp+10h] [ebp-4h]
  struct D3DXShader::CNode *v16; // [esp+1Ch] [ebp+8h]

  while ( *((_DWORD *)a2 + 1) != 3 )
    a2 = *((struct D3DXShader::CNode **)a2 + 2);
  v4 = D3DXShader::CNode::operator new(a1: 0x50u);
  if ( v4 != nullptr )
  {
    v5 = (struct D3DXShader::CNode *)D3DXShader::CNodeExpression::CNodeExpression(
                                       a1: v4,
                                       a2: 0,
                                       a3: 0,
                                       a4: 0,
                                       a5: 0,
                                       a6: 1,
                                       a7: (char *)a2 + 16);
    v15 = v5;
  }
  else
  {
    v15 = nullptr;
    v5 = nullptr;
  }
  if ( v5 == nullptr )
    return nullptr;
  if ( a3 != nullptr )
  {
    v6 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a3 + 4))(a1: a3);
    *((_DWORD *)v5 + 8) = v6;
    if ( v6 == 0 )
      return nullptr;
  }
  v7 = *((struct D3DXShader::CNode **)v5 + 8);
  v8 = (_DWORD *)((char *)v5 + 16);
  v16 = v7;
  if ( v7 != nullptr )
  {
    while ( 1 )
    {
      v10 = *((_DWORD *)v7 + 2);
      if ( v10 != 0 && *(_DWORD *)(v10 + 4) == 13 && *(_DWORD *)(v10 + 16) != 0 )
      {
        v11 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v11 != nullptr )
          v12 = D3DXShader::CNodeList::CNodeList(
                  this: (D3DXShader::CNodeList *)v11,
                  a2: nullptr,
                  a3: nullptr,
                  a4: "Types");
        else
          v12 = 0;
        *v8 = v12;
        if ( v12 == 0 )
          return nullptr;
        *(_DWORD *)(*v8 + 8) = D3DXShader::CNode::Copy(a1: *(struct D3DXShader::CNode **)(v10 + 16));
        v13 = *v8;
        if ( *(_DWORD *)(v13 + 8) == 0 )
          return nullptr;
        v7 = v16;
        v8 = (_DWORD *)(v13 + 12);
      }
      v16 = *((struct D3DXShader::CNode **)v7 + 3);
      if ( v16 == nullptr )
        break;
      v7 = *((struct D3DXShader::CNode **)v7 + 3);
    }
    v5 = v15;
  }
  D3DXShader::CParse::ComputeExprSize(this, a2: v5);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101F70AF
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::OffsetExpr(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::OffsetExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  _DWORD *v3; // edi
  const char **v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // edi
  int v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // eax
  unsigned int v13; // ebx
  int v14; // esi
  unsigned int v15; // ecx
  char v16; // al
  char v17; // cl
  char v18; // al
  unsigned int v19; // esi
  unsigned int v20; // edi
  char v21; // cl
  char v22; // al
  unsigned __int8 *v23; // eax
  int v24; // eax
  unsigned __int8 *v25; // eax
  int v26; // eax
  int i; // eax
  int v28; // edx
  int v29; // ecx
  int v30; // eax
  unsigned __int8 *v31; // eax
  int v32; // eax
  int v33; // [esp-4h] [ebp-44h]
  _DWORD *v34; // [esp+Ch] [ebp-34h]
  int v35; // [esp+10h] [ebp-30h]
  unsigned int v36; // [esp+18h] [ebp-28h]
  struct D3DXShader::D3DXTOKEN *v37; // [esp+1Ch] [ebp-24h]
  unsigned int v38; // [esp+20h] [ebp-20h]
  _DWORD *v40; // [esp+28h] [ebp-18h]
  int v41; // [esp+28h] [ebp-18h]
  unsigned int v42; // [esp+2Ch] [ebp-14h]
  int v43; // [esp+30h] [ebp-10h]
  unsigned int v44; // [esp+34h] [ebp-Ch]
  struct D3DXShader::CNode *v45; // [esp+38h] [ebp-8h]
  char *v46; // [esp+3Ch] [ebp-4h]
  struct D3DXShader::CNode *v47; // [esp+4Ch] [ebp+Ch]
  struct D3DXShader::CNode *v48; // [esp+4Ch] [ebp+Ch]

  if ( a3 == nullptr || *((_DWORD *)a3 + 1) != 3 || a2 == nullptr || *((_DWORD *)a2 + 1) != 13 )
    return nullptr;
  v3 = *((_DWORD **)a2 + 4);
  v4 = (const char **)((char *)a3 + 16);
  v34 = v3;
  v37 = (struct D3DXShader::CNode *)((char *)a3 + 16);
  v5 = D3DXShader::CNode::operator new(a1: 0x50u);
  v45 = v5 != nullptr
      ? (struct D3DXShader::CNode *)D3DXShader::CNodeExpression::CNodeExpression(
                                      a1: v5,
                                      a2: 0,
                                      a3: 23,
                                      a4: 0,
                                      a5: 0,
                                      a6: 1,
                                      a7: v4)
      : nullptr;
  if ( v45 == nullptr )
    return nullptr;
  if ( v3 == nullptr )
    goto LABEL_17;
  v6 = v3[1];
  if ( v6 == 1 )
  {
    v47 = nullptr;
    v40 = v3;
    while ( 1 )
    {
      v7 = (_DWORD *)v3[2];
      if ( v7 != nullptr && v7[1] == 6 )
      {
        v8 = v7[6];
        if ( strcmp(v4[2], *(const char **)(v7[5] + 24)) == 0 )
        {
          if ( *(_DWORD *)(v8 + 32) == 0
            || (v10 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v8 + 32) + 4))(a1: *(_DWORD *)(v8 + 32)),
                *((_DWORD *)v45 + 4) = v10,
                v10 != 0) )
          {
            v11 = D3DXShader::CNode::operator new(a1: 0x40u);
            if ( v11 != nullptr )
              v12 = D3DXShader::CNodeValue::CNodeValue(a1: v11, a2: 2, a3: v47, a4: v4);
            else
              v12 = 0;
            *((_DWORD *)v45 + 9) = v12;
            goto LABEL_104;
          }
          return nullptr;
        }
        v47 = (struct D3DXShader::CNode *)((char *)v47
                                         + D3DXShader::CParse::TypeSize(
                                             this,
                                             a2: *(struct D3DXShader::CNode **)(v8 + 32)));
        v3 = v40;
      }
      v3 = (_DWORD *)v3[3];
      v40 = v3;
      if ( v3 == nullptr )
        goto LABEL_17;
    }
  }
  if ( v6 != 9 )
    goto LABEL_17;
  v13 = *((_DWORD *)a3 + 6);
  v36 = v3[6];
  v38 = v3[7];
  v14 = v3[8] & 0x200;
  v35 = v14;
  v15 = v13 + strlen((const char *)v13);
  v16 = *(_BYTE *)v13;
  v42 = v15;
  if ( *(_BYTE *)v13 == 95 )
  {
    if ( v3[4] != 2 )
      goto LABEL_17;
    if ( v13 + 1 >= v15 || (v43 = 3, *(_BYTE *)(v13 + 1) != 109) )
      v43 = 2;
  }
  else
  {
    if ( v16 <= 96 )
      goto LABEL_17;
    if ( v16 <= 98 || v16 == 103 || v16 == 114 )
    {
      if ( v3[4] > 1u )
        goto LABEL_17;
      v43 = 1;
    }
    else
    {
      if ( v16 <= 118 || v16 > 122 || v3[4] > 1u )
        goto LABEL_17;
      v43 = 0;
    }
  }
  v44 = 0;
  v41 = (int)v45 + 36;
  if ( v13 < v15 )
  {
    v48 = (struct D3DXShader::CNode *)(v13 + 2);
    v46 = (char *)(v13 + 3);
    while ( 1 )
    {
      if ( v44 >= 4 )
      {
LABEL_87:
        if ( v13 >= v42 && v44 <= 4 )
        {
          v14 = v35;
          v3 = v34;
          break;
        }
LABEL_17:
        D3DXShader::CParse::Error(
          this,
          a2: v37,
          a3: 0xBCAu,
          format: "invalid subscript '%s'",
          *((const char **)v37 + 2));
        return nullptr;
      }
      if ( v43 != 0 )
      {
        if ( v43 != 1 )
        {
          if ( v43 == 2 )
          {
            if ( (unsigned int)v48 >= v42 )
              goto LABEL_17;
            if ( *(_BYTE *)v13 != 95 )
              goto LABEL_17;
            v21 = *(_BYTE *)(v13 + 1);
            if ( v21 < 49 )
              goto LABEL_17;
            if ( v21 > 57 )
              goto LABEL_17;
            v22 = *(_BYTE *)v48;
            if ( *(char *)v48 < 49 || v22 > 57 )
              goto LABEL_17;
            v46 += 3;
            v19 = v21 - 49;
            v20 = v22 - 49;
            v13 += 3;
            v48 = (struct D3DXShader::CNode *)((char *)v48 + 3);
          }
          else
          {
            if ( (unsigned int)v46 >= v42 )
              goto LABEL_17;
            if ( *(_BYTE *)v13 != 95 )
              goto LABEL_17;
            if ( *(_BYTE *)(v13 + 1) != 109 )
              goto LABEL_17;
            v17 = *(_BYTE *)v48;
            if ( *(char *)v48 < 48 )
              goto LABEL_17;
            if ( v17 > 57 )
              goto LABEL_17;
            v18 = *v46;
            if ( *v46 < 48 || v18 > 57 )
              goto LABEL_17;
            v46 += 4;
            v19 = v17 - 48;
            v20 = v18 - 48;
            v13 += 4;
            v48 = (struct D3DXShader::CNode *)((char *)v48 + 4);
          }
          goto LABEL_76;
        }
        switch ( *(_BYTE *)v13 )
        {
          case 'a':
LABEL_73:
            v33 = 3;
            goto LABEL_74;
          case 'b':
            goto LABEL_72;
          case 'g':
            goto LABEL_67;
          default:
            break;
        }
        if ( *(_BYTE *)v13 != 114 )
          goto LABEL_17;
      }
      else
      {
        if ( *(_BYTE *)v13 == 119 )
          goto LABEL_73;
        if ( *(_BYTE *)v13 != 120 )
        {
          if ( *(_BYTE *)v13 != 121 )
          {
            if ( *(_BYTE *)v13 != 122 )
              goto LABEL_17;
LABEL_72:
            v33 = 2;
LABEL_74:
            v20 = v33;
            goto LABEL_75;
          }
LABEL_67:
          v20 = 1;
          goto LABEL_75;
        }
      }
      v20 = 0;
LABEL_75:
      v19 = 0;
      ++v13;
      ++v46;
      v48 = (struct D3DXShader::CNode *)((char *)v48 + 1);
LABEL_76:
      if ( v19 >= v36 || v20 >= v38 )
        goto LABEL_17;
      v23 = D3DXShader::CNode::operator new(a1: 0x14u);
      if ( v23 != nullptr )
        v24 = D3DXShader::CNodeList::CNodeList(
                this: (D3DXShader::CNodeList *)v23,
                a2: nullptr,
                a3: nullptr,
                a4: "Swizzle");
      else
        v24 = 0;
      *(_DWORD *)v41 = v24;
      if ( v24 == 0 )
        return nullptr;
      v25 = D3DXShader::CNode::operator new(a1: 0x40u);
      v26 = v25 != nullptr ? D3DXShader::CNodeValue::CNodeValue(a1: v25, a2: 2, a3: v20 + v38 * v19, a4: v37) : 0;
      *(_DWORD *)(*(_DWORD *)v41 + 8) = v26;
      if ( v26 == 0 )
        return nullptr;
      ++v44;
      v41 = *(_DWORD *)v41 + 12;
      if ( v13 >= v42 )
        goto LABEL_87;
    }
  }
  for ( i = *((_DWORD *)v45 + 9); i != 0 && v14 == 0; i = v28 )
  {
    v28 = *(_DWORD *)(i + 12);
    v29 = v28;
    if ( v28 != 0 )
    {
      v30 = *(_DWORD *)(*(_DWORD *)(i + 8) + 24);
      while ( v30 != *(_DWORD *)(*(_DWORD *)(v29 + 8) + 24) )
      {
        v29 = *(_DWORD *)(v29 + 12);
        if ( v29 == 0 )
          goto LABEL_98;
      }
      v14 = 1;
    }
LABEL_98:
    ;
  }
  v31 = D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v31 != nullptr )
    v12 = D3DXShader::CNodeType::CNodeType(a1: v31, a2: v44 != 1, a3: v3[5], a4: 1, a5: v44, a6: v14 != 0 ? 0x200 : 0);
  else
    v12 = 0;
  *((_DWORD *)v45 + 4) = v12;
LABEL_104:
  if ( v12 == 0 )
    return nullptr;
  v32 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a2 + 4))(a1: a2);
  *((_DWORD *)v45 + 8) = v32;
  if ( v32 == 0 )
    goto LABEL_17;
  D3DXShader::CParse::ComputeExprSize(this, a2: v45);
  return v45;
}

//------------------------------------------------------------------------------
// Address: 0x101F7540
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::AsmExpr(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::AsmExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2)
{
  _DWORD *v3; // eax
  unsigned int v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // esi
  unsigned __int8 *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // eax
  int v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // eax
  int v15; // [esp+18h] [ebp+8h]

  if ( a2 == nullptr )
    return nullptr;
  if ( *((_DWORD *)a2 + 1) != 15 )
    return nullptr;
  v3 = *((_DWORD **)a2 + 12);
  if ( v3 == nullptr || *((_DWORD *)a2 + 13) < 4u )
    return nullptr;
  v4 = *v3 & 0xFFFF0000;
  switch ( v4 )
  {
    case 0x7FFE0000u:
      v15 = 28;
      break;
    case 0x7FFF0000u:
      v15 = 27;
      break;
    case 0xFFFE0000:
      v15 = 26;
      break;
    case 0xFFFF0000:
      v15 = 25;
      break;
    default:
      return nullptr;
  }
  v5 = D3DXShader::CNode::operator new(a1: 0x50u);
  if ( v5 != nullptr )
    v6 = D3DXShader::CNodeExpression::CNodeExpression(a1: v5, a2: 0, a3: 0, a4: 0, a5: 0, a6: 1, a7: (char *)a2 + 16);
  else
    v6 = 0;
  if ( v6 != 0 )
  {
    v7 = D3DXShader::CNode::operator new(a1: 0x24u);
    v8 = v7 != nullptr ? D3DXShader::CNodeType::CNodeType(a1: v7, a2: 3, a3: v15, a4: 1, a5: 1, a6: 512) : 0;
    *(_DWORD *)(v6 + 16) = v8;
    if ( v8 != 0 )
    {
      v9 = D3DXShader::CNode::operator new(a1: 0x40u);
      v10 = v9 != nullptr
          ? D3DXShader::CNodeValue::CNodeValue(
              a1: v9,
              a2: 5,
              a3: *((_DWORD *)a2 + 12),
              a4: *((_DWORD *)a2 + 13),
              a5: (char *)a2 + 16)
          : 0;
      *(_DWORD *)(v6 + 32) = v10;
      if ( v10 != 0 )
      {
        v11 = D3DXShader::CNode::operator new(a1: 0x14u);
        v12 = v11 != nullptr
            ? D3DXShader::CNodeList::CNodeList(
                this: (D3DXShader::CNodeList *)v11,
                a2: *(struct D3DXShader::CNode **)(v6 + 32),
                a3: nullptr,
                a4: "Value")
            : 0;
        if ( v12 != 0 )
        {
          *(_DWORD *)(v6 + 32) = v12;
          D3DXShader::CParse::ComputeExprSize(this, a2: (struct D3DXShader::CNode *)v6);
          return (struct D3DXShader::CNode *)v6;
        }
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F767A
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::SamplerExpr(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::SamplerExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2)
{
  unsigned __int8 *v3; // eax
  int v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // eax
  int v8; // esi
  struct D3DXShader::CNode *v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // eax

  v3 = D3DXShader::CNode::operator new(a1: 0x50u);
  if ( v3 != nullptr )
    v4 = D3DXShader::CNodeExpression::CNodeExpression(a1: v3, a2: 0, a3: 0, a4: 0, a5: 0, a6: 1, a7: (char *)this + 32);
  else
    v4 = 0;
  if ( v4 == 0 )
    return nullptr;
  v5 = D3DXShader::CNode::operator new(a1: 0x24u);
  v6 = v5 != nullptr ? D3DXShader::CNodeType::CNodeType(a1: v5, a2: 3, a3: 20, a4: 1, a5: 1, a6: 512) : 0;
  *(_DWORD *)(v4 + 16) = v6;
  if ( v6 == 0 )
    return nullptr;
  v7 = D3DXShader::CNode::operator new(a1: 0x40u);
  v8 = v7 != nullptr ? D3DXShader::CNodeValue::CNodeValue(a1: v7, a2: 4, a3: 0, a4: (char *)this + 32) : 0;
  if ( v8 == 0 )
    return nullptr;
  *(_DWORD *)(v4 + 32) = v8;
  if ( a2 != nullptr )
  {
    v9 = D3DXShader::CNode::Copy(a1: a2);
    *(_DWORD *)(v8 + 24) = v9;
    if ( v9 == nullptr )
      return nullptr;
  }
  v10 = D3DXShader::CNode::operator new(a1: 0x14u);
  v11 = v10 != nullptr
      ? D3DXShader::CNodeList::CNodeList(
          this: (D3DXShader::CNodeList *)v10,
          a2: *(struct D3DXShader::CNode **)(v4 + 32),
          a3: nullptr,
          a4: "Value")
      : 0;
  if ( v11 == 0 )
    return nullptr;
  *(_DWORD *)(v4 + 32) = v11;
  D3DXShader::CParse::ComputeExprSize(this, a2: (struct D3DXShader::CNode *)v4);
  return (struct D3DXShader::CNode *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x101F7754
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::StateblockExpr(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::StateblockExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2)
{
  unsigned __int8 *v3; // eax
  int v4; // edi
  unsigned __int8 *v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // eax
  int v8; // esi
  struct D3DXShader::CNode *v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // eax

  v3 = D3DXShader::CNode::operator new(a1: 0x50u);
  if ( v3 != nullptr )
    v4 = D3DXShader::CNodeExpression::CNodeExpression(a1: v3, a2: 0, a3: 0, a4: 0, a5: 0, a6: 1, a7: (char *)this + 32);
  else
    v4 = 0;
  if ( v4 == 0 )
    return nullptr;
  v5 = D3DXShader::CNode::operator new(a1: 0x24u);
  v6 = v5 != nullptr ? D3DXShader::CNodeType::CNodeType(a1: v5, a2: 3, a3: 29, a4: 1, a5: 1, a6: 512) : 0;
  *(_DWORD *)(v4 + 16) = v6;
  if ( v6 == 0 )
    return nullptr;
  v7 = D3DXShader::CNode::operator new(a1: 0x40u);
  v8 = v7 != nullptr ? D3DXShader::CNodeValue::CNodeValue(a1: v7, a2: 4, a3: 0, a4: (char *)this + 32) : 0;
  if ( v8 == 0 )
    return nullptr;
  *(_DWORD *)(v4 + 32) = v8;
  if ( a2 != nullptr )
  {
    v9 = D3DXShader::CNode::Copy(a1: a2);
    *(_DWORD *)(v8 + 24) = v9;
    if ( v9 == nullptr )
      return nullptr;
  }
  v10 = D3DXShader::CNode::operator new(a1: 0x14u);
  v11 = v10 != nullptr
      ? D3DXShader::CNodeList::CNodeList(
          this: (D3DXShader::CNodeList *)v10,
          a2: *(struct D3DXShader::CNode **)(v4 + 32),
          a3: nullptr,
          a4: "Value")
      : 0;
  if ( v11 == 0 )
    return nullptr;
  *(_DWORD *)(v4 + 32) = v11;
  D3DXShader::CParse::ComputeExprSize(this, a2: (struct D3DXShader::CNode *)v4);
  return (struct D3DXShader::CNode *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x101F782E
// Name: protected: long D3DXShader::CParse::Cast(struct D3DXShader::_D3DXVALUE __near *,struct D3DXShader::_D3DXVALUE __near *,struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::Cast(
        D3DXShader::CParse *this,
        struct D3DXShader::_D3DXVALUE *a2,
        struct D3DXShader::_D3DXVALUE *a3,
        struct D3DXShader::D3DXTOKEN *a4)
{
  __int64 v4; // rax
  double v5; // st7
  double v6; // st7
  double v8; // st7
  char v9; // c0

  switch ( *(_DWORD *)a2 )
  {
    case 0:
      if ( *(_DWORD *)a3 <= 2u )
      {
        *((_DWORD *)a2 + 2) = *((_DWORD *)a3 + 2) != 0;
        return 0;
      }
      if ( *(_DWORD *)a3 == 3 )
      {
        *((_DWORD *)a2 + 2) = 0.0 != *((double *)a3 + 1);
        return 0;
      }
      return -2147467259;
    case 1:
    case 2:
      if ( *(_DWORD *)a3 != 0 )
      {
        if ( *(_DWORD *)a3 == 1 || *(_DWORD *)a3 == 2 )
        {
          LODWORD(v4) = *((_DWORD *)a3 + 2);
        }
        else
        {
          if ( *(_DWORD *)a3 != 3 )
            return -2147467259;
          v8 = *((double *)a3 + 1);
          if ( v9 != 0 )
            v6 = v8 - 0.000001;
          else
            v6 = v8 + 0.000001;
          v4 = (__int64)v6;
        }
      }
      else
      {
        LODWORD(v4) = *((_DWORD *)a3 + 2) != 0;
      }
LABEL_33:
      *((_DWORD *)a2 + 2) = v4;
      return 0;
    case 3:
      if ( *(_DWORD *)a3 != 0 )
      {
        switch ( *(_DWORD *)a3 )
        {
          case 1:
            v5 = (double)*((int *)a3 + 2);
            break;
          case 2:
            v5 = (double)*((unsigned int *)a3 + 2);
            break;
          case 3:
            v5 = *((double *)a3 + 1);
            break;
          default:
            return -2147467259;
        }
      }
      else
      {
        v5 = (double)(*((_DWORD *)a3 + 2) != 0);
      }
      *((double *)a2 + 1) = v5;
      return 0;
    case 4:
      if ( *(_DWORD *)a3 == 4 )
      {
LABEL_13:
        LODWORD(v4) = *((_DWORD *)a3 + 2);
        goto LABEL_33;
      }
      break;
    case 5:
      break;
    default:
      return -2147467259;
  }
  if ( *(_DWORD *)a3 == 4 )
  {
    *(_DWORD *)a2 = 4;
    goto LABEL_13;
  }
  if ( *(_DWORD *)a3 != 5 )
    return -2147467259;
  *((_DWORD *)a2 + 2) = *((_DWORD *)a3 + 2);
  *((_DWORD *)a2 + 3) = *((_DWORD *)a3 + 3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F796A
// Name: protected: long D3DXShader::CParse::CastToUint(unsigned int __near *,struct D3DXShader::_D3DXVALUE __near *,struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::CastToUint(
        D3DXShader::CParse *this,
        unsigned int *a2,
        struct D3DXShader::_D3DXVALUE *a3,
        struct D3DXShader::D3DXTOKEN *a4)
{
  double v6; // st7
  char v7; // c0
  double v8; // st7
  __int64 v9; // rax

  if ( *(_DWORD *)a3 != 0 )
  {
    if ( *(_DWORD *)a3 == 1 || *(_DWORD *)a3 == 2 )
    {
      LODWORD(v9) = *((_DWORD *)a3 + 2);
    }
    else
    {
      if ( *(_DWORD *)a3 != 3 )
        return -2147467259;
      v6 = *((double *)a3 + 1);
      if ( v7 != 0 )
        v8 = v6 - 0.000001;
      else
        v8 = v6 + 0.000001;
      v9 = (__int64)v8;
    }
  }
  else
  {
    LODWORD(v9) = *((_DWORD *)a3 + 2) != 0;
  }
  *a2 = v9;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F79C9
// Name: protected: long D3DXShader::CParse::CastToValue(struct D3DXShader::_D3DXVALUE __near *,double,struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::CastToValue(
        D3DXShader::CParse *this,
        struct D3DXShader::_D3DXVALUE *a2,
        double a3,
        struct D3DXShader::D3DXTOKEN *a4)
{
  char v6; // c0
  double v7; // st7
  __int64 v8; // rax

  if ( *(_DWORD *)a2 == 0 )
  {
    LODWORD(v8) = 0.0 != a3;
LABEL_12:
    *((_DWORD *)a2 + 2) = v8;
    return 0;
  }
  if ( *(_DWORD *)a2 == 1 || *(_DWORD *)a2 == 2 )
  {
    if ( v6 != 0 )
      v7 = a3 - 0.000001;
    else
      v7 = a3 + 0.000001;
    v8 = (__int64)v7;
    goto LABEL_12;
  }
  if ( *(_DWORD *)a2 != 3 )
    return -2147467259;
  *((double *)a2 + 1) = a3;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F7A3C
// Name: protected: unsigned int D3DXShader::CParse::ScoreFunctionCall(class D3DXShader::CNodeFunction __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::ScoreFunctionCall(
        D3DXShader::CParse *this,
        struct D3DXShader::CNodeFunction *a2,
        const char **a3,
        struct D3DXShader::CNode *a4,
        char a5)
{
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // eax
  struct D3DXShader::CNode *v11; // ebx
  unsigned int v12; // eax
  unsigned int v13; // eax
  int v15; // [esp+Ch] [ebp-20h] BYREF
  int v16; // [esp+10h] [ebp-1Ch]
  int v17; // [esp+18h] [ebp-14h] BYREF
  int v18; // [esp+1Ch] [ebp-10h]
  D3DXShader::CParse *v19; // [esp+24h] [ebp-8h]
  int v20; // [esp+28h] [ebp-4h]
  struct D3DXShader::CNode *v22; // [esp+38h] [ebp+Ch]

  v19 = this;
  v20 = 0;
  if ( a3 != nullptr && (v5 = *((_DWORD *)a2 + 7)) != 0 )
  {
    if ( D3DXGetTargetDescByName(a1: *(const char **)(v5 + 24), a2: 0, a3: &v17) >= 0
      && D3DXGetTargetDescByName(a1: a3[6], a2: 0, a3: &v15) >= 0 )
    {
      if ( v18 == v16 )
        goto LABEL_14;
      if ( ((v18 ^ v16) & 0xFFFF0000) == 0 && ((_WORD)v18 == 0 || (_WORD)v16 == 0) )
      {
        v20 = ((unsigned __int16)v16 == 0) + 1;
        goto LABEL_14;
      }
      return -1;
    }
    if ( strcmp(a3[6], *(const char **)(*((_DWORD *)a2 + 7) + 24)) != 0 )
      return -1;
  }
  else if ( (a3 == nullptr) != (*((_DWORD *)a2 + 7) == 0) )
  {
    v20 = 2;
  }
LABEL_14:
  v6 = *((_DWORD *)a2 + 9);
  while ( v6 != 0 )
  {
    v7 = *(_DWORD *)(v6 + 8);
    v6 = *(_DWORD *)(v6 + 12);
    v8 = 0;
    if ( v6 != 0 && *(_DWORD *)(*(_DWORD *)(v6 + 8) + 4) == 12 )
    {
      v6 = *(_DWORD *)(v6 + 12);
      v8 = 1;
    }
    if ( (a5 & 0x10) == 0 || (*(_BYTE *)(*(_DWORD *)(v7 + 24) + 28) & 0x40) != 0 )
    {
      if ( a4 != nullptr )
      {
        v9 = *(_DWORD *)(v7 + 24);
        v10 = *((_DWORD *)a4 + 2);
        v11 = *(struct D3DXShader::CNode **)(v9 + 32);
        if ( v10 != 0 )
          v22 = *(struct D3DXShader::CNode **)(v10 + 16);
        else
          v22 = nullptr;
        if ( (*(_BYTE *)(v9 + 28) & 0x10) != 0 )
        {
          if ( !D3DXShader::CParse::IsSupportedCast(this: v19, a2: v11, a3: v22, a4: 0) )
            return -1;
          v12 = D3DXShader::CParse::ScoreCast(this: v19, a2: v11, a3: v22);
          v20 += v12;
        }
        if ( (*(_BYTE *)(v9 + 28) & 0x20) != 0 )
        {
          if ( D3DXShader::CParse::IsConst(this: v19, a2: v22) != 0
            || !D3DXShader::CParse::IsSupportedCast(this: v19, a2: v22, a3: v11, a4: 0) )
          {
            return -1;
          }
          v13 = D3DXShader::CParse::ScoreCast(this: v19, a2: v22, a3: v11);
          v20 += v13;
        }
        a4 = *((struct D3DXShader::CNode **)a4 + 3);
      }
      else if ( v8 == 0 )
      {
        return -1;
      }
    }
  }
  if ( a4 != nullptr )
    return -1;
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x101F7C0B
// Name: protected: long D3DXShader::CParse::PushUsageType(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::PushUsageType(struct D3DXShader::CNode **this, struct D3DXShader::CNode *a2)
{
  unsigned __int8 *v3; // eax
  struct D3DXShader::CNode *v4; // edi
  struct D3DXShader::CNode ***v5; // eax
  struct D3DXShader::CNode ***v6; // esi
  int result; // eax

  v3 = D3DXShader::CNode::operator new(a1: 0x14u);
  if ( v3 != nullptr )
    v4 = (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                       this: (D3DXShader::CNodeList *)v3,
                                       a2: nullptr,
                                       a3: *(this + 5),
                                       a4: "UsageType");
  else
    v4 = nullptr;
  if ( v4 == nullptr )
    goto LABEL_7;
  *(this + 5) = v4;
  if ( a2 == nullptr )
    return 0;
  v5 = (struct D3DXShader::CNode ***)D3DXShader::CNode::Copy(a1: a2);
  v6 = v5;
  *((_DWORD *)v4 + 2) = v5;
  if ( v5 == nullptr )
  {
LABEL_7:
    D3DXShader::CParse::NonNull((D3DXShader::CParse *)this, a2: nullptr);
    return -2147024882;
  }
  result = D3DXShader::CParse::ApplyUsage((D3DXShader::CParse *)this, a2: (struct D3DXShader::CNode *)v5, a3: v5[6]);
  if ( result >= 0 )
  {
    *((_BYTE *)v6 + 17) &= 0xF1u;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F7C86
// Name: protected: long D3DXShader::CParse::EvalIntrinsic(class D3DXShader::CNode __near *,struct D3DXShader::_D3DXVALUE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::EvalIntrinsic(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::_D3DXVALUE *a3)
{
  struct D3DXShader::CNode *v3; // ebx
  unsigned int v5; // edx
  bool v6; // zf
  int v7; // ecx
  double *v8; // ecx
  _DWORD *v9; // ecx
  int v10; // eax
  double *v11; // edx
  _DWORD *v12; // ebx
  struct D3DXShader::CNode **v13; // esi
  double *v14; // edi
  int v15; // esi
  double *v16; // edx
  int v17; // edx
  double *v18; // eax
  double *v19; // eax
  long double *v21; // eax
  int v22; // ecx
  unsigned int i; // edi
  long double *v24; // edi
  int v25; // ebx
  unsigned int v26; // edi
  double *v27; // ecx
  double v28; // st7
  unsigned int v29; // edi
  double *v30; // ecx
  long double *v31; // edi
  int v32; // ebx
  long double *v33; // eax
  int v34; // ecx
  unsigned int m; // edi
  char *v36; // ecx
  long double *v37; // eax
  char *v38; // ebx
  unsigned int n; // edi
  double *v40; // edi
  int v41; // ebx
  char *v42; // edi
  double *v43; // ecx
  double *v44; // ebx
  double v45; // st7
  long double *v46; // eax
  int v47; // ecx
  unsigned int kk; // edi
  long double *v49; // edi
  int v50; // ebx
  double *v51; // ecx
  double *v52; // eax
  double *v53; // eax
  unsigned int nn; // ecx
  double *v55; // eax
  unsigned int i1; // ecx
  double *v57; // eax
  int v58; // ecx
  unsigned int i2; // edi
  double v60; // st7
  double v61; // st6
  double v62; // st5
  double v63; // st4
  double v64; // st3
  int v65; // eax
  long double v66; // st7
  double *v67; // eax
  unsigned int i3; // edi
  double v69; // st6
  double *v70; // eax
  int v71; // ecx
  unsigned int i4; // edi
  double v73; // st7
  double *v74; // eax
  double *v75; // ecx
  long double *v76; // edi
  int v77; // ebx
  long double *v78; // edi
  int v79; // ebx
  double v80; // st7
  double *v81; // eax
  unsigned int i7; // edi
  double v83; // st6
  double *v84; // ecx
  int v85; // edi
  unsigned int i8; // ebx
  double v88; // st6
  unsigned __int8 v89; // c0
  unsigned __int8 v90; // c2
  double *v91; // edi
  int v92; // ebx
  char *v93; // ebx
  long double *v94; // edi
  double *v95; // edi
  int v96; // ebx
  double v97; // st7
  double *v98; // eax
  unsigned int i11; // ecx
  double *v100; // edi
  int v101; // ebx
  double v102; // st7
  double *v103; // edi
  int v104; // ebx
  double v105; // st7
  double *v106; // edi
  int v107; // ebx
  double v108; // st7
  int v109; // ebx
  double *v110; // edi
  double *v111; // eax
  unsigned int i15; // ecx
  double v113; // st6
  char *v114; // edx
  int v115; // edi
  double *v116; // eax
  int v117; // ebx
  double *v118; // ecx
  double v119; // st7
  double *v120; // ecx
  long double *v121; // edi
  long double *v122; // edi
  long double *v123; // edi
  char *v124; // edi
  double *v125; // ecx
  char *v126; // ebx
  double v127; // st7
  char *v128; // edi
  double *v129; // ecx
  char *v130; // ebx
  double v131; // st7
  double *v132; // eax
  int v133; // ecx
  unsigned int i18; // edi
  double *v135; // eax
  int v136; // ecx
  unsigned int i19; // edi
  int v138; // edi
  int v139; // ebx
  int v140; // ecx
  int v141; // edi
  int v142; // eax
  int v143; // ecx
  int v144; // eax
  double v145; // st7
  double *v146; // edi
  double v147; // st6
  long double v148; // st7
  double *v149; // eax
  unsigned int i21; // edi
  double v151; // st6
  long double v152; // st7
  double *v153; // eax
  int v154; // ecx
  unsigned int i22; // edi
  char *v156; // ebx
  long double *v157; // edi
  long double v158; // st6
  int v159; // eax
  double *v160; // eax
  int v161; // ecx
  unsigned int i23; // edi
  double v163; // st7
  double *v164; // eax
  double v165; // st6
  char *v166; // edi
  double *v167; // eax
  char *v168; // ebx
  unsigned int i24; // ecx
  double v170; // st7
  double v171; // st6
  double *v172; // eax
  double v173; // st5
  long double v174; // st5
  double *v175; // eax
  unsigned int i26; // ecx
  long double v177; // st6
  char *v178; // edi
  double *v179; // eax
  char *v180; // ebx
  unsigned int i25; // ecx
  double *v182; // edi
  int v183; // ebx
  long double *v184; // edi
  double *v185; // ecx
  int v186; // edi
  unsigned int i28; // ebx
  double v188; // st7
  double *v189; // ecx
  int v190; // edi
  unsigned int i29; // ebx
  double v192; // st6
  long double *v193; // eax
  int v194; // ecx
  unsigned int i30; // edi
  long double *v196; // edi
  int v197; // ebx
  char *v198; // ebx
  double *v199; // ecx
  char *v200; // edi
  double v201; // st7
  double v202; // st7
  long double *v203; // edi
  int v204; // edi
  double *v205; // ecx
  int v206; // ebx
  double v207; // st7
  long double *v208; // eax
  int v209; // ecx
  unsigned int i33; // edi
  long double *v211; // edi
  int v212; // ebx
  int v213; // eax
  unsigned int v214; // ecx
  int v215; // ecx
  int v216; // edx
  double *v217; // eax
  struct D3DXShader::_D3DXVALUE *v218; // edi
  unsigned int i35; // edi
  _BYTE v220[16]; // [esp+18h] [ebp-64h] BYREF
  int v221; // [esp+28h] [ebp-54h] BYREF
  _DWORD *v222; // [esp+2Ch] [ebp-50h]
  int v223; // [esp+30h] [ebp-4Ch]
  int v224; // [esp+34h] [ebp-48h]
  void *pMem; // [esp+38h] [ebp-44h]
  double *v226; // [esp+3Ch] [ebp-40h]
  int v227; // [esp+40h] [ebp-3Ch]
  int v228; // [esp+44h] [ebp-38h]
  int v229; // [esp+48h] [ebp-34h]
  double v230; // [esp+4Ch] [ebp-30h]
  int i20; // [esp+54h] [ebp-28h]
  int v232; // [esp+58h] [ebp-24h]
  int v233; // [esp+5Ch] [ebp-20h]
  int v234; // [esp+60h] [ebp-1Ch]
  double *jj; // [esp+64h] [ebp-18h]
  double *v236; // [esp+68h] [ebp-14h]
  double *v237; // [esp+6Ch] [ebp-10h]
  double *v238; // [esp+70h] [ebp-Ch]
  D3DXShader::CParse *v239; // [esp+74h] [ebp-8h]
  struct D3DXShader::_D3DXVALUE *v240; // [esp+78h] [ebp-4h]
  struct D3DXShader::_D3DXVALUE *j; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *k; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *ii; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v244; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *mm; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i5; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i6; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i9; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v249; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i10; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i12; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i13; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i14; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v254; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v255; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v256; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v257; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v258; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i16; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i17; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v261; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v262; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i27; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v264; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i31; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v266; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v267; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i32; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *i34; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v270; // [esp+88h] [ebp+Ch]
  struct D3DXShader::_D3DXVALUE *v271; // [esp+88h] [ebp+Ch]

  v3 = a2;
  v239 = this;
  if ( a2 == nullptr )
  {
    if ( a3 == nullptr )
      return 0;
  }
  else if ( *((_DWORD *)a2 + 1) == 13 )
  {
    v5 = *((_DWORD *)a2 + 6) * *((_DWORD *)a2 + 5);
    v6 = *((_DWORD *)a2 + 7) == 26;
    v240 = (struct D3DXShader::_D3DXVALUE *)v5;
    if ( v6 )
    {
      v221 = 0;
      v222 = nullptr;
      v223 = 0;
      v224 = 0;
      v7 = *((_DWORD *)a2 + 9);
      memset(v220, 0, sizeof(v220));
      pMem = nullptr;
      v226 = nullptr;
      v229 = v7;
      v8 = *(double **)(v7 + 8);
      v227 = 0;
      v228 = 0;
      v236 = v8;
      if ( v8 == nullptr )
        goto LABEL_18;
      v238 = nullptr;
      while ( 1 )
      {
        v9 = *((_DWORD **)v236 + 2);
        if ( v9 != nullptr && v9[1] == 13 )
          break;
LABEL_16:
        v19 = *((double **)v236 + 3);
        v238 = (double *)((char *)v238 + 4);
        v236 = v19;
        if ( v19 == nullptr )
        {
          v3 = a2;
          v5 = (unsigned int)v240;
LABEL_18:
          switch ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 8) + 8) + 24) )
          {
            case 0:
              if ( v5 != 0 )
              {
                v21 = (long double *)((char *)a3 + 8);
                v22 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( i = v5; i != 0; --i )
                {
                  *v21 = fabs(*(long double *)((char *)v21 + v22));
                  v21 += 2;
                }
              }
              goto LABEL_97;
            case 1:
              if ( v5 == 0 )
                goto LABEL_97;
              v24 = (long double *)((char *)pMem + 8);
              v25 = a3 - (struct D3DXShader::_D3DXVALUE *)pMem;
              for ( j = (struct D3DXShader::_D3DXVALUE *)v5;
                    j != nullptr;
                    j = (struct D3DXShader::_D3DXVALUE *)((char *)j - 1) )
              {
                if ( *v24 < -1.0 || *v24 > 1.0 )
                  D3DXShader::CParse::Error(
                    this: v239,
                    a2: (struct D3DXShader::CNode *)((char *)a2 + 48),
                    a3: 0xBFEu,
                    format: "indefinite acos");
                *(long double *)((char *)v24 + v25) = acos(*v24);
                v24 += 2;
              }
              goto LABEL_344;
            case 2:
              v26 = 0;
              *((double *)a3 + 1) = 1.0;
              if ( v5 == 0 )
                goto LABEL_97;
              v27 = (double *)((char *)pMem + 8);
              while ( *v27 != 0.0 )
              {
                ++v26;
                v27 += 2;
                if ( v26 >= v5 )
                  goto LABEL_97;
              }
              v28 = 0.0;
              goto LABEL_100;
            case 3:
              v29 = 0;
              *((double *)a3 + 1) = 0.0;
              if ( v5 == 0 )
                goto LABEL_97;
              v30 = (double *)((char *)pMem + 8);
              while ( *v30 == 0.0 )
              {
                ++v29;
                v30 += 2;
                if ( v29 >= v5 )
                  goto LABEL_97;
              }
              v28 = 1.0;
LABEL_100:
              *((double *)a3 + 1) = v28;
              goto LABEL_97;
            case 4:
              if ( v5 == 0 )
                goto LABEL_97;
              v31 = (long double *)((char *)pMem + 8);
              v32 = a3 - (struct D3DXShader::_D3DXVALUE *)pMem;
              for ( k = (struct D3DXShader::_D3DXVALUE *)v5;
                    k != nullptr;
                    k = (struct D3DXShader::_D3DXVALUE *)((char *)k - 1) )
              {
                if ( *v31 < -1.0 || *v31 > 1.0 )
                  D3DXShader::CParse::Error(
                    this: v239,
                    a2: (struct D3DXShader::CNode *)((char *)a2 + 48),
                    a3: 0xBFFu,
                    format: "indefinite asin");
                *(long double *)((char *)v31 + v32) = asin(*v31);
                v31 += 2;
              }
              goto LABEL_344;
            case 5:
              if ( v5 != 0 )
              {
                v33 = (long double *)((char *)a3 + 8);
                v34 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( m = v5; m != 0; --m )
                {
                  *v33 = atan2(*(long double *)((char *)v33 + v34), 1.0);
                  v33 += 2;
                }
              }
              goto LABEL_97;
            case 6:
              if ( v5 != 0 )
              {
                v36 = (char *)((_BYTE *)pMem - (_BYTE *)v226);
                v37 = v226 + 1;
                v38 = (char *)(a3 - (struct D3DXShader::_D3DXVALUE *)v226);
                for ( n = v5; n != 0; --n )
                {
                  *(long double *)((char *)v37 + (_DWORD)v38) = atan2(*(double *)((char *)v37 + (_DWORD)v36), *v37);
                  v37 += 2;
                }
              }
              goto LABEL_97;
            case 7:
              if ( v5 == 0 )
                goto LABEL_97;
              v40 = (double *)((char *)a3 + 8);
              v41 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( ii = (struct D3DXShader::_D3DXVALUE *)v5;
                    ii != nullptr;
                    ii = (struct D3DXShader::_D3DXVALUE *)((char *)ii - 1) )
              {
                *v40 = ceil(X: *(double *)((char *)v40 + v41));
                v40 += 2;
              }
              goto LABEL_344;
            case 8:
              if ( v5 != 0 )
              {
                v42 = (char *)v226 - v227;
                v244 = (struct D3DXShader::_D3DXVALUE *)((char *)a3 - v227);
                v43 = (double *)(v227 + 8);
                v238 = (double *)((char *)pMem - v227);
                for ( jj = (double *)v5; jj != nullptr; jj = (double *)((char *)jj - 1) )
                {
                  v44 = (double *)((int)v43 + (_DWORD)v238);
                  if ( *(double *)((char *)v43 + (_DWORD)v238) >= *(double *)((char *)v43 + (_DWORD)v42) )
                  {
                    if ( *v44 <= *v43 )
                      v45 = *v44;
                    else
                      v45 = *v43;
                  }
                  else
                  {
                    v45 = *(double *)((char *)v43 + (_DWORD)v42);
                  }
                  *(double *)((char *)v43 + (_DWORD)v244) = v45;
                  v43 += 2;
                }
              }
              goto LABEL_97;
            case 0xA:
              if ( v5 != 0 )
              {
                v46 = (long double *)((char *)a3 + 8);
                v47 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( kk = v5; kk != 0; --kk )
                {
                  *v46 = cos(*(long double *)((char *)v46 + v47));
                  v46 += 2;
                }
              }
              goto LABEL_97;
            case 0xB:
              if ( v5 == 0 )
                goto LABEL_97;
              v49 = (long double *)((char *)a3 + 8);
              v50 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( mm = (struct D3DXShader::_D3DXVALUE *)v5;
                    mm != nullptr;
                    mm = (struct D3DXShader::_D3DXVALUE *)((char *)mm - 1) )
              {
                *v49 = cosh(*(long double *)((char *)v49 + v50));
                v49 += 2;
              }
              goto LABEL_344;
            case 0xC:
              v51 = (double *)pMem;
              v52 = v226;
              *((double *)a3 + 1) = *((double *)pMem + 3) * v226[5] - *((double *)pMem + 5) * v226[3];
              *((double *)a3 + 3) = v51[5] * v52[1] - v52[5] * v51[1];
              *((double *)a3 + 5) = v52[3] * v51[1] - v51[3] * v52[1];
              goto LABEL_97;
            case 0xD:
              if ( v5 != 0 )
              {
                v53 = (double *)((char *)a3 + 8);
                for ( nn = v5; nn != 0; --nn )
                {
                  *v53 = 0.0;
                  v53 += 2;
                }
              }
              goto LABEL_97;
            case 0xE:
              if ( v5 != 0 )
              {
                v55 = (double *)((char *)a3 + 8);
                for ( i1 = v5; i1 != 0; --i1 )
                {
                  *v55 = 0.0;
                  v55 += 2;
                }
              }
              goto LABEL_97;
            case 0xF:
              if ( v5 != 0 )
              {
                v57 = (double *)((char *)a3 + 8);
                v58 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( i2 = v5; i2 != 0; --i2 )
                {
                  *v57 = *(double *)((char *)v57 + v58) * 57.29577791868205;
                  v57 += 2;
                }
              }
              goto LABEL_97;
            case 0x10:
              switch ( *(_DWORD *)(v221 + 20) )
              {
                case 1:
                  v28 = *((double *)pMem + 1);
                  goto LABEL_100;
                case 2:
                  v28 = *((double *)pMem + 7) * *((double *)pMem + 1) - *((double *)pMem + 5) * *((double *)pMem + 3);
                  goto LABEL_100;
                case 3:
                  v28 = (*((double *)pMem + 17) * *((double *)pMem + 9) - *((double *)pMem + 11)
                                                                        * *((double *)pMem + 15))
                      * *((double *)pMem + 1)
                      - (*((double *)pMem + 17) * *((double *)pMem + 7) - *((double *)pMem + 11)
                                                                        * *((double *)pMem + 13))
                      * *((double *)pMem + 3)
                      + (*((double *)pMem + 15) * *((double *)pMem + 7) - *((double *)pMem + 9) * *((double *)pMem + 13))
                      * *((double *)pMem + 5);
                  goto LABEL_100;
                default:
                  break;
              }
              if ( *(_DWORD *)(v221 + 20) != 4 )
                goto LABEL_360;
              v60 = *((double *)pMem + 21) * *((double *)pMem + 31) - *((double *)pMem + 23) * *((double *)pMem + 29);
              v61 = *((double *)pMem + 31) * *((double *)pMem + 19) - *((double *)pMem + 27) * *((double *)pMem + 23);
              v62 = *((double *)pMem + 19) * *((double *)pMem + 29) - *((double *)pMem + 21) * *((double *)pMem + 27);
              v63 = *((double *)pMem + 17) * *((double *)pMem + 31) - *((double *)pMem + 25) * *((double *)pMem + 23);
              v64 = *((double *)pMem + 17) * *((double *)pMem + 29) - *((double *)pMem + 25) * *((double *)pMem + 21);
              v230 = *((double *)pMem + 17) * *((double *)pMem + 27) - *((double *)pMem + 25) * *((double *)pMem + 19);
              *((double *)a3 + 1) = (v60 * *((double *)pMem + 11)
                                   - v61 * *((double *)pMem + 13)
                                   + v62 * *((double *)pMem + 15))
                                  * *((double *)pMem + 1)
                                  - (v60 * *((double *)pMem + 9)
                                   - v63 * *((double *)pMem + 13)
                                   + v64 * *((double *)pMem + 15))
                                  * *((double *)pMem + 3)
                                  + (v61 * *((double *)pMem + 9)
                                   - v63 * *((double *)pMem + 11)
                                   + v230 * *((double *)pMem + 15))
                                  * *((double *)pMem + 5)
                                  - (v62 * *((double *)pMem + 9)
                                   - v64 * *((double *)pMem + 11)
                                   + v230 * *((double *)pMem + 13))
                                  * *((double *)pMem + 7);
              goto LABEL_97;
            case 0x11:
              v66 = 0.0;
              if ( v5 != 0 )
              {
                v67 = v226 + 1;
                for ( i3 = v5; i3 != 0; --i3 )
                {
                  v69 = *(double *)((char *)v67 + (_BYTE *)pMem - (_BYTE *)v226) - *v67;
                  v67 += 2;
                  v66 = v66 + v69 * v69;
                }
              }
              goto LABEL_105;
            case 0x12:
              *((double *)a3 + 1) = 0.0;
              if ( v5 != 0 )
              {
                v70 = (double *)((char *)pMem + 8);
                v71 = (char *)v226 - (_BYTE *)pMem;
                for ( i4 = v5; i4 != 0; --i4 )
                {
                  v73 = *(double *)((char *)v70 + v71) * *v70;
                  v70 += 2;
                  *((double *)a3 + 1) = v73 + *((double *)a3 + 1);
                }
              }
              goto LABEL_97;
            case 0x13:
              v74 = v226;
              v75 = (double *)pMem;
              *((double *)a3 + 1) = 1.0;
              *((double *)a3 + 3) = v74[3] * v75[3];
              *((double *)a3 + 5) = v75[5];
              *((double *)a3 + 7) = v74[7];
              goto LABEL_97;
            case 0x14:
              if ( v5 == 0 )
                goto LABEL_97;
              v76 = (long double *)((char *)a3 + 8);
              v77 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( i5 = (struct D3DXShader::_D3DXVALUE *)v5;
                    i5 != nullptr;
                    i5 = (struct D3DXShader::_D3DXVALUE *)((char *)i5 - 1) )
              {
                *v76 = exp(*(long double *)((char *)v76 + v77));
                v76 += 2;
              }
              goto LABEL_344;
            case 0x15:
              if ( v5 == 0 )
                goto LABEL_97;
              v78 = (long double *)((char *)a3 + 8);
              v79 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( i6 = (struct D3DXShader::_D3DXVALUE *)v5;
                    i6 != nullptr;
                    i6 = (struct D3DXShader::_D3DXVALUE *)((char *)i6 - 1) )
              {
                *v78 = pow(2.0, *(long double *)((char *)v78 + v79));
                v78 += 2;
              }
              goto LABEL_344;
            case 0x16:
              v80 = 0.0;
              if ( v5 != 0 )
              {
                v81 = v226 + 1;
                for ( i7 = v5; i7 != 0; --i7 )
                {
                  v83 = *(double *)((char *)v81 + v227 - (_DWORD)v226) * *v81;
                  v81 += 2;
                  v80 = v80 + v83;
                }
                v84 = (double *)((char *)pMem + 8);
                v85 = a3 - (struct D3DXShader::_D3DXVALUE *)pMem;
                for ( i8 = v5; i8 != 0; --i8 )
                {
                  v88 = *v84;
                  if ( (v89 | v90) == 0 )
                    v88 = -v88;
                  *(double *)((char *)v84 + v85) = v88;
                  v84 += 2;
                }
              }
              goto LABEL_97;
            case 0x17:
              if ( v5 == 0 )
                goto LABEL_97;
              v91 = (double *)((char *)a3 + 8);
              v92 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( i9 = (struct D3DXShader::_D3DXVALUE *)v5;
                    i9 != nullptr;
                    i9 = (struct D3DXShader::_D3DXVALUE *)((char *)i9 - 1) )
              {
                *v91 = floor(X: *(double *)((char *)v91 + v92));
                v91 += 2;
              }
              goto LABEL_344;
            case 0x18:
              if ( v5 == 0 )
                goto LABEL_97;
              v93 = (char *)((_BYTE *)pMem - (_BYTE *)v226);
              v249 = (struct D3DXShader::_D3DXVALUE *)(a3 - (struct D3DXShader::_D3DXVALUE *)v226);
              v94 = v226 + 1;
              jj = (double *)v240;
              do
              {
                *(long double *)((char *)v94 + (_DWORD)v249) = fmod(*(double *)((char *)v94 + (_DWORD)v93), *v94);
                v94 += 2;
                jj = (double *)((char *)jj - 1);
              }
              while ( jj != nullptr );
              goto LABEL_344;
            case 0x19:
              if ( v5 == 0 )
                goto LABEL_97;
              v95 = (double *)((char *)pMem + 8);
              v96 = a3 - (struct D3DXShader::_D3DXVALUE *)pMem;
              for ( i10 = (struct D3DXShader::_D3DXVALUE *)v5;
                    i10 != nullptr;
                    i10 = (struct D3DXShader::_D3DXVALUE *)((char *)i10 - 1) )
              {
                if ( _finite(x: *v95) != 0 )
                  v97 = *v95 - floor(X: *v95);
                else
                  v97 = 0.0;
                *(double *)((char *)v95 + v96) = v97;
                v95 += 2;
              }
              goto LABEL_344;
            case 0x1B:
              if ( v5 != 0 )
              {
                v98 = (double *)((char *)a3 + 8);
                for ( i11 = v5; i11 != 0; --i11 )
                {
                  *v98 = 0.0;
                  v98 += 2;
                }
              }
              goto LABEL_97;
            case 0x1C:
              if ( v5 == 0 )
                goto LABEL_97;
              v100 = (double *)((char *)a3 + 8);
              v101 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( i12 = (struct D3DXShader::_D3DXVALUE *)v5;
                    i12 != nullptr;
                    i12 = (struct D3DXShader::_D3DXVALUE *)((char *)i12 - 1) )
              {
                if ( _finite(x: *(double *)((char *)v100 + v101)) != 0 )
                  v102 = 1.0;
                else
                  v102 = 0.0;
                *v100 = v102;
                v100 += 2;
              }
              goto LABEL_344;
            case 0x1D:
              if ( v5 == 0 )
                goto LABEL_97;
              v103 = (double *)((char *)a3 + 8);
              v104 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( i13 = (struct D3DXShader::_D3DXVALUE *)v5;
                    i13 != nullptr;
                    i13 = (struct D3DXShader::_D3DXVALUE *)((char *)i13 - 1) )
              {
                if ( _finite(x: *(double *)((char *)v103 + v104)) != 0 )
                  v105 = 0.0;
                else
                  v105 = 1.0;
                *v103 = v105;
                v103 += 2;
              }
              goto LABEL_344;
            case 0x1E:
              if ( v5 == 0 )
                goto LABEL_97;
              v106 = (double *)((char *)a3 + 8);
              v107 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( i14 = (struct D3DXShader::_D3DXVALUE *)v5;
                    i14 != nullptr;
                    i14 = (struct D3DXShader::_D3DXVALUE *)((char *)i14 - 1) )
              {
                if ( _isnan(x: *(double *)((char *)v106 + v107)) != 0 )
                  v108 = 1.0;
                else
                  v108 = 0.0;
                *v106 = v108;
                v106 += 2;
              }
              goto LABEL_344;
            case 0x1F:
              if ( v5 == 0 )
                goto LABEL_97;
              v109 = (char *)v226 - (_BYTE *)pMem;
              v254 = (struct D3DXShader::_D3DXVALUE *)(a3 - (struct D3DXShader::_D3DXVALUE *)pMem);
              v110 = (double *)((char *)pMem + 8);
              jj = (double *)v240;
              do
              {
                *(long double *)((char *)v254 + (_DWORD)v110) = pow(2.0, *(double *)((char *)v110 + v109)) * *v110;
                v110 += 2;
                jj = (double *)((char *)jj - 1);
              }
              while ( jj != nullptr );
              goto LABEL_344;
            case 0x20:
              v66 = 0.0;
              if ( v5 != 0 )
              {
                v111 = (double *)((char *)pMem + 8);
                for ( i15 = v5; i15 != 0; --i15 )
                {
                  v113 = *v111;
                  v111 += 2;
                  v66 = v66 + v113 * v113;
                }
              }
LABEL_105:
              v28 = sqrt(v66);
              goto LABEL_100;
            case 0x21:
              if ( v5 == 0 )
                goto LABEL_97;
              v114 = (char *)v226 - v227;
              v115 = v227 - (_DWORD)pMem;
              v116 = (double *)((char *)pMem + 8);
              v117 = a3 - (struct D3DXShader::_D3DXVALUE *)pMem;
              v255 = v240;
              do
              {
                *(double *)((char *)v116 + v117) = (*(double *)&v114[(_DWORD)v116 + v115] - *v116)
                                                 * *(double *)((char *)v116 + v115)
                                                 + *v116;
                v116 += 2;
                v255 = (struct D3DXShader::_D3DXVALUE *)((char *)v255 - 1);
              }
              while ( v255 != nullptr );
              goto LABEL_344;
            case 0x22:
              v118 = (double *)pMem;
              *((double *)a3 + 1) = 1.0;
              *((double *)a3 + 3) = 0.0;
              *((double *)a3 + 5) = 0.0;
              *((double *)a3 + 7) = 1.0;
              if ( v118[1] <= 0.0 )
                goto LABEL_97;
              v119 = v118[1];
              v120 = v226;
              *((double *)a3 + 3) = v119;
              if ( v120[1] <= 0.0 )
                goto LABEL_97;
              *((long double *)a3 + 5) = pow(v120[1], *(double *)(v227 + 8));
              goto LABEL_344;
            case 0x23:
              if ( v5 != 0 )
              {
                v256 = (struct D3DXShader::_D3DXVALUE *)(a3 - (struct D3DXShader::_D3DXVALUE *)pMem);
                v121 = (long double *)((char *)pMem + 8);
                for ( jj = (double *)v5; jj != nullptr; jj = (double *)((char *)jj - 1) )
                {
                  if ( *v121 <= 0.0 )
                  {
                    D3DXShader::CParse::Error(
                      this: v239,
                      a2: (struct D3DXShader::CNode *)((char *)v3 + 48),
                      a3: 0xBD8u,
                      format: "infinite/indefinite log");
                    v5 = (unsigned int)v240;
                  }
                  *(long double *)((char *)v121 + (_DWORD)v256) = __FYL2X__(*v121, 0.6931471805599453094);
                  v121 += 2;
                }
              }
              goto LABEL_97;
            case 0x24:
              if ( v5 != 0 )
              {
                v257 = (struct D3DXShader::_D3DXVALUE *)(a3 - (struct D3DXShader::_D3DXVALUE *)pMem);
                v122 = (long double *)((char *)pMem + 8);
                jj = (double *)v5;
                v230 = __FYL2X__(10.0, 0.6931471805599453094);
                do
                {
                  if ( *v122 <= 0.0 )
                  {
                    D3DXShader::CParse::Error(
                      this: v239,
                      a2: (struct D3DXShader::CNode *)((char *)v3 + 48),
                      a3: 0xBD8u,
                      format: "infinite/indefinite log");
                    v5 = (unsigned int)v240;
                  }
                  *(long double *)((char *)v122 + (_DWORD)v257) = __FYL2X__(*v122, 0.6931471805599453094) / v230;
                  v122 += 2;
                  jj = (double *)((char *)jj - 1);
                }
                while ( jj != nullptr );
              }
              goto LABEL_97;
            case 0x25:
              if ( v5 != 0 )
              {
                v258 = (struct D3DXShader::_D3DXVALUE *)(a3 - (struct D3DXShader::_D3DXVALUE *)pMem);
                v123 = (long double *)((char *)pMem + 8);
                jj = (double *)v5;
                v230 = __FYL2X__(2.0, 0.6931471805599453094);
                do
                {
                  if ( *v123 <= 0.0 )
                  {
                    D3DXShader::CParse::Error(
                      this: v239,
                      a2: (struct D3DXShader::CNode *)((char *)v3 + 48),
                      a3: 0xBD8u,
                      format: "infinite/indefinite log");
                    v5 = (unsigned int)v240;
                  }
                  *(long double *)((char *)v123 + (_DWORD)v258) = __FYL2X__(*v123, 0.6931471805599453094) / v230;
                  v123 += 2;
                  jj = (double *)((char *)jj - 1);
                }
                while ( jj != nullptr );
              }
              goto LABEL_97;
            case 0x26:
              if ( v5 != 0 )
              {
                v124 = (char *)((_BYTE *)pMem - (_BYTE *)v226);
                v125 = v226 + 1;
                v126 = (char *)(a3 - (struct D3DXShader::_D3DXVALUE *)v226);
                for ( i16 = (struct D3DXShader::_D3DXVALUE *)v5;
                      i16 != nullptr;
                      i16 = (struct D3DXShader::_D3DXVALUE *)((char *)i16 - 1) )
                {
                  if ( *(double *)((char *)v125 + (_DWORD)v124) <= *v125 )
                    v127 = *v125;
                  else
                    v127 = *(double *)((char *)v125 + (_DWORD)v124);
                  *(double *)((char *)v125 + (_DWORD)v126) = v127;
                  v125 += 2;
                }
              }
              goto LABEL_97;
            case 0x27:
              if ( v5 != 0 )
              {
                v128 = (char *)((_BYTE *)pMem - (_BYTE *)v226);
                v129 = v226 + 1;
                v130 = (char *)(a3 - (struct D3DXShader::_D3DXVALUE *)v226);
                for ( i17 = (struct D3DXShader::_D3DXVALUE *)v5;
                      i17 != nullptr;
                      i17 = (struct D3DXShader::_D3DXVALUE *)((char *)i17 - 1) )
                {
                  if ( *(double *)((char *)v129 + (_DWORD)v128) >= *v129 )
                    v131 = *v129;
                  else
                    v131 = *(double *)((char *)v129 + (_DWORD)v128);
                  *(double *)((char *)v129 + (_DWORD)v130) = v131;
                  v129 += 2;
                }
              }
              goto LABEL_97;
            case 0x29:
            case 0x2A:
            case 0x2B:
              if ( v5 != 0 )
              {
                v132 = (double *)((char *)a3 + 8);
                v133 = (char *)v226 - (char *)a3;
                for ( i18 = v5; i18 != 0; --i18 )
                {
                  *v132 = *(double *)((char *)v132 + v133) * *((double *)pMem + 1);
                  v132 += 2;
                }
              }
              goto LABEL_97;
            case 0x2C:
            case 0x2F:
              if ( v5 != 0 )
              {
                v135 = (double *)((char *)a3 + 8);
                v136 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( i19 = v5; i19 != 0; --i19 )
                {
                  *v135 = *(double *)((char *)v135 + v136) * v226[1];
                  v135 += 2;
                }
              }
              goto LABEL_97;
            case 0x2D:
            case 0x2E:
            case 0x30:
            case 0x31:
              v138 = *(_DWORD *)(v222[4] + 16);
              v139 = *(_DWORD *)(v221 + 20);
              v140 = *(_DWORD *)(v221 + 24);
              v233 = v140;
              if ( v138 == 1 )
              {
                v141 = v222[6];
                v142 = v222[5];
              }
              else
              {
                v141 = v222[5];
                v142 = v222[6];
              }
              v234 = v142;
              if ( v140 != v141 || v139 * v142 != v5 )
                goto LABEL_360;
              if ( v139 != 0 )
              {
                v143 = 16 * v140;
                v144 = 16 * v142;
                jj = (double *)((char *)pMem + 8);
                v238 = (double *)((char *)a3 + 8);
                HIDWORD(v230) = v139;
                do
                {
                  if ( v234 != 0 )
                  {
                    v236 = v226 + 1;
                    v237 = v238;
                    for ( i20 = v234; i20 != 0; --i20 )
                    {
                      v145 = 0.0;
                      if ( v233 != 0 )
                      {
                        v146 = jj;
                        v261 = (struct D3DXShader::_D3DXVALUE *)v236;
                        v232 = v233;
                        do
                        {
                          v147 = *v146 * *(double *)v261;
                          v261 = (struct D3DXShader::_D3DXVALUE *)((char *)v261 + v144);
                          v146 += 2;
                          v6 = v232-- == 1;
                          v145 = v145 + v147;
                        }
                        while ( !v6 );
                      }
                      v236 += 2;
                      *v237 = v145;
                      v237 += 2;
                    }
                  }
                  v238 = (double *)((char *)v238 + v144);
                  jj = (double *)((char *)jj + v143);
                  --HIDWORD(v230);
                }
                while ( HIDWORD(v230) != 0 );
              }
              goto LABEL_97;
            case 0x33:
              v148 = 0.0;
              if ( v5 == 0 )
                goto LABEL_241;
              v149 = (double *)((char *)pMem + 8);
              for ( i21 = v5; i21 != 0; --i21 )
              {
                v151 = *v149;
                v149 += 2;
                v148 = v148 + v151 * v151;
              }
              if ( v148 != 0.0 )
                v152 = 1.0 / sqrt(v148);
              else
LABEL_241:
                v152 = 0.0;
              if ( v5 != 0 )
              {
                v153 = (double *)((char *)a3 + 8);
                v154 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( i22 = v5; i22 != 0; --i22 )
                {
                  *v153 = v152 * *(double *)((char *)v153 + v154);
                  v153 += 2;
                }
              }
              goto LABEL_97;
            case 0x34:
              if ( v5 == 0 )
                goto LABEL_97;
              v156 = (char *)((_BYTE *)pMem - (_BYTE *)v226);
              v262 = (struct D3DXShader::_D3DXVALUE *)(a3 - (struct D3DXShader::_D3DXVALUE *)v226);
              v157 = v226 + 1;
              HIDWORD(v230) = v240;
              do
              {
                v158 = pow(*(double *)&v156[(_DWORD)v157], *v157);
                *(long double *)((char *)v262 + (_DWORD)v157) = v158;
                v159 = _fpclass(x: v158);
                if ( v159 > 0 && v159 <= 2 )
                  D3DXShader::CParse::Error(
                    this: v239,
                    a2: (struct D3DXShader::CNode *)((char *)a2 + 48),
                    a3: 0xBD8u,
                    format: "indefinite power");
                v157 += 2;
                --HIDWORD(v230);
              }
              while ( HIDWORD(v230) != 0 );
              goto LABEL_344;
            case 0x35:
              if ( v5 != 0 )
              {
                v160 = (double *)((char *)a3 + 8);
                v161 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( i23 = v5; i23 != 0; --i23 )
                {
                  *v160 = *(double *)((char *)v160 + v161) * 0.01745329300562541;
                  v160 += 2;
                }
              }
              goto LABEL_97;
            case 0x36:
              v163 = 0.0;
              if ( v5 != 0 )
              {
                v164 = (double *)((char *)pMem + 8);
                HIDWORD(v230) = v5;
                do
                {
                  v165 = *(double *)((char *)v164 + (char *)v226 - (_BYTE *)pMem) * *v164;
                  v164 += 2;
                  v6 = HIDWORD(v230)-- == 1;
                  v163 = v163 + v165;
                }
                while ( !v6 );
                v166 = (char *)((_BYTE *)pMem - (_BYTE *)v226);
                v167 = v226 + 1;
                v168 = (char *)(a3 - (struct D3DXShader::_D3DXVALUE *)v226);
                for ( i24 = v5; i24 != 0; --i24 )
                {
                  *(double *)((char *)v167 + (_DWORD)v168) = *(double *)((char *)v167 + (_DWORD)v166)
                                                           - (v163 * *v167
                                                            + v163 * *v167);
                  v167 += 2;
                }
              }
              goto LABEL_97;
            case 0x37:
              v170 = *(double *)(v227 + 8);
              v171 = 0.0;
              if ( v5 != 0 )
              {
                v172 = (double *)((char *)pMem + 8);
                HIDWORD(v230) = v5;
                do
                {
                  v173 = *(double *)((char *)v172 + (char *)v226 - (_BYTE *)pMem) * *v172;
                  v172 += 2;
                  v6 = HIDWORD(v230)-- == 1;
                  v171 = v171 + v173;
                }
                while ( !v6 );
              }
              v174 = 1.0 - (1.0 - v171 * v171) * v170 * v170;
              if ( v174 >= 0.0 )
              {
                v177 = sqrt(v174) + v171 * v170;
                if ( v5 != 0 )
                {
                  v178 = (char *)((_BYTE *)pMem - (_BYTE *)v226);
                  v179 = v226 + 1;
                  v180 = (char *)(a3 - (struct D3DXShader::_D3DXVALUE *)v226);
                  for ( i25 = v5; i25 != 0; --i25 )
                  {
                    *(long double *)((char *)v179 + (_DWORD)v180) = v170 * *(double *)((char *)v179 + (_DWORD)v178)
                                                                  - v177 * *v179;
                    v179 += 2;
                  }
                }
              }
              else if ( v5 != 0 )
              {
                v175 = (double *)((char *)a3 + 8);
                for ( i26 = v5; i26 != 0; --i26 )
                {
                  *v175 = 0.0;
                  v175 += 2;
                }
              }
              goto LABEL_97;
            case 0x38:
              if ( v5 == 0 )
                goto LABEL_97;
              v182 = (double *)((char *)a3 + 8);
              v183 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( i27 = (struct D3DXShader::_D3DXVALUE *)v5;
                    i27 != nullptr;
                    i27 = (struct D3DXShader::_D3DXVALUE *)((char *)i27 - 1) )
              {
                *v182 = floor(X: *(double *)((char *)v182 + v183) + 0.5);
                v182 += 2;
              }
              goto LABEL_344;
            case 0x39:
              if ( v5 != 0 )
              {
                v264 = (struct D3DXShader::_D3DXVALUE *)(a3 - (struct D3DXShader::_D3DXVALUE *)pMem);
                v184 = (long double *)((char *)pMem + 8);
                HIDWORD(v230) = v5;
                do
                {
                  if ( *v184 < 0.0 )
                  {
                    D3DXShader::CParse::Error(
                      this: v239,
                      a2: (struct D3DXShader::CNode *)((char *)v3 + 48),
                      a3: 0xBD7u,
                      format: "imaginary square root");
                    v5 = (unsigned int)v240;
                  }
                  if ( 0.0 == *v184 )
                  {
                    D3DXShader::CParse::Error(
                      this: v239,
                      a2: (struct D3DXShader::CNode *)((char *)v3 + 48),
                      a3: 0xBD9u,
                      format: "division by zero");
                    v5 = (unsigned int)v240;
                  }
                  *(long double *)((char *)v264 + (_DWORD)v184) = 1.0 / sqrt(*v184);
                  v184 += 2;
                  --HIDWORD(v230);
                }
                while ( HIDWORD(v230) != 0 );
              }
              goto LABEL_97;
            case 0x3A:
              if ( v5 != 0 )
              {
                v185 = (double *)((char *)a3 + 8);
                v186 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( i28 = v5; i28 != 0; --i28 )
                {
                  if ( *(double *)((char *)v185 + v186) >= 0.0 )
                  {
                    if ( *(double *)((char *)v185 + v186) <= 1.0 )
                      v188 = *(double *)((char *)v185 + v186);
                    else
                      v188 = 1.0;
                  }
                  else
                  {
                    v188 = 0.0;
                  }
                  *v185 = v188;
                  v185 += 2;
                }
              }
              goto LABEL_97;
            case 0x3B:
              if ( v5 != 0 )
              {
                v189 = (double *)((char *)a3 + 8);
                v190 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( i29 = v5; i29 != 0; --i29 )
                {
                  if ( *(double *)((char *)v189 + v190) >= 0.0 )
                  {
                    if ( *(double *)((char *)v189 + v190) <= 0.0 )
                      v192 = 0.0;
                    else
                      v192 = 1.0;
                  }
                  else
                  {
                    v192 = -1.0;
                  }
                  *v189 = v192;
                  v189 += 2;
                }
              }
              goto LABEL_97;
            case 0x3C:
              if ( v5 != 0 )
              {
                v193 = (long double *)((char *)a3 + 8);
                v194 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( i30 = v5; i30 != 0; --i30 )
                {
                  *v193 = sin(*(long double *)((char *)v193 + v194));
                  v193 += 2;
                }
              }
              goto LABEL_97;
            case 0x3E:
              if ( v5 == 0 )
                goto LABEL_97;
              v196 = (long double *)((char *)a3 + 8);
              v197 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( i31 = (struct D3DXShader::_D3DXVALUE *)v5;
                    i31 != nullptr;
                    i31 = (struct D3DXShader::_D3DXVALUE *)((char *)i31 - 1) )
              {
                *v196 = sinh(*(long double *)((char *)v196 + v197));
                v196 += 2;
              }
              goto LABEL_344;
            case 0x3F:
              if ( v5 == 0 )
                goto LABEL_97;
              v238 = (double *)((char *)pMem - v227);
              v198 = (char *)v226 - v227;
              v199 = (double *)(v227 + 8);
              v200 = (char *)a3 - v227;
              v266 = (struct D3DXShader::_D3DXVALUE *)v5;
              break;
            case 0x40:
              if ( v5 != 0 )
              {
                v267 = (struct D3DXShader::_D3DXVALUE *)(a3 - (struct D3DXShader::_D3DXVALUE *)pMem);
                v203 = (long double *)((char *)pMem + 8);
                HIDWORD(v230) = v5;
                do
                {
                  if ( *v203 < 0.0 )
                  {
                    D3DXShader::CParse::Error(
                      this: v239,
                      a2: (struct D3DXShader::CNode *)((char *)v3 + 48),
                      a3: 0xBD7u,
                      format: "imaginary square root");
                    v5 = (unsigned int)v240;
                  }
                  *(long double *)((char *)v203 + (_DWORD)v267) = sqrt(*v203);
                  v203 += 2;
                  --HIDWORD(v230);
                }
                while ( HIDWORD(v230) != 0 );
              }
              goto LABEL_97;
            case 0x41:
              if ( v5 != 0 )
              {
                v204 = (char *)v226 - (_BYTE *)pMem;
                v205 = (double *)((char *)pMem + 8);
                v206 = a3 - (struct D3DXShader::_D3DXVALUE *)pMem;
                for ( i32 = (struct D3DXShader::_D3DXVALUE *)v5;
                      i32 != nullptr;
                      i32 = (struct D3DXShader::_D3DXVALUE *)((char *)i32 - 1) )
                {
                  if ( *(double *)((char *)v205 + v204) < *v205 )
                    v207 = 0.0;
                  else
                    v207 = 1.0;
                  *(double *)((char *)v205 + v206) = v207;
                  v205 += 2;
                }
              }
              goto LABEL_97;
            case 0x42:
              if ( v5 != 0 )
              {
                v208 = (long double *)((char *)a3 + 8);
                v209 = (_BYTE *)pMem - (_BYTE *)a3;
                for ( i33 = v5; i33 != 0; --i33 )
                {
                  *v208 = tan(*(long double *)((char *)v208 + v209));
                  v208 += 2;
                }
              }
              goto LABEL_97;
            case 0x43:
              if ( v5 == 0 )
                goto LABEL_97;
              v211 = (long double *)((char *)a3 + 8);
              v212 = (_BYTE *)pMem - (_BYTE *)a3;
              for ( i34 = (struct D3DXShader::_D3DXVALUE *)v5;
                    i34 != nullptr;
                    i34 = (struct D3DXShader::_D3DXVALUE *)((char *)i34 - 1) )
              {
                *v211 = tanh(*(long double *)((char *)v211 + v212));
                v211 += 2;
              }
LABEL_344:
              v5 = (unsigned int)v240;
              goto LABEL_97;
            case 0x58:
              v213 = v221;
              v238 = nullptr;
              if ( *(_DWORD *)(v221 + 24) != 0 )
              {
                v214 = *(_DWORD *)(v221 + 20);
                do
                {
                  v270 = nullptr;
                  if ( v214 != 0 )
                  {
                    do
                    {
                      v215 = 16 * ((_DWORD)v238 + (_DWORD)v270 * *(_DWORD *)(v213 + 24));
                      v216 = 16 * ((_DWORD)v270 + (_DWORD)v238 * *((_DWORD *)v3 + 6));
                      v270 = (struct D3DXShader::_D3DXVALUE *)((char *)v270 + 1);
                      *(double *)((char *)a3 + v216 + 8) = *(double *)((char *)pMem + v215 + 8);
                      v214 = *(_DWORD *)(v213 + 20);
                    }
                    while ( (unsigned int)v270 < v214 );
                    v5 = (unsigned int)v240;
                  }
                  v238 = (double *)((char *)v238 + 1);
                }
                while ( (unsigned int)v238 < *(_DWORD *)(v213 + 24) );
              }
              goto LABEL_97;
            case 0x59:
              v217 = (double *)pMem;
              *((double *)a3 + 1) = *((double *)pMem + 5) * 255.001953125;
              *((double *)a3 + 3) = v217[3] * 255.001953125;
              *((double *)a3 + 5) = v217[1] * 255.001953125;
              *((double *)a3 + 7) = v217[7] * 255.001953125;
              goto LABEL_97;
            default:
              goto LABEL_360;
          }
          while ( 1 )
          {
            if ( *v199 >= *(double *)((char *)v238 + (_DWORD)v199) )
            {
              if ( *v199 < *(double *)&v198[(_DWORD)v199] )
              {
                v202 = (*v199 - *(double *)((char *)v238 + (_DWORD)v199))
                     / (*(double *)&v198[(_DWORD)v199] - *(double *)((char *)v238 + (_DWORD)v199));
                *(double *)&v200[(_DWORD)v199] = 3.0 * (v202 * v202) - (v202 * v202 * v202 + v202 * v202 * v202);
                goto LABEL_322;
              }
              v201 = 1.0;
            }
            else
            {
              v201 = 0.0;
            }
            *(double *)&v200[(_DWORD)v199] = v201;
LABEL_322:
            v199 += 2;
            v266 = (struct D3DXShader::_D3DXVALUE *)((char *)v266 - 1);
            if ( v266 == nullptr )
            {
LABEL_97:
              v65 = v229;
              while ( 1 )
              {
                v65 = *(_DWORD *)(v65 + 12);
                if ( v65 == 0 )
                  break;
                if ( *(_DWORD *)(v65 + 8) != 0 )
                {
LABEL_360:
                  v15 = -2147467259;
                  goto LABEL_361;
                }
              }
              v271 = nullptr;
              if ( v5 != 0 )
              {
                v218 = a3;
                while ( 1 )
                {
                  v15 = D3DXShader::CParse::CastToValue(
                          this: v239,
                          a2: v218,
                          a3: *((double *)v218 + 1),
                          a4: (struct D3DXShader::CNode *)((char *)a2 + 48));
                  if ( v15 < 0 )
                    break;
                  v271 = (struct D3DXShader::_D3DXVALUE *)((char *)v271 + 1);
                  v218 = (struct D3DXShader::_D3DXVALUE *)((char *)v218 + 16);
                  if ( v271 >= v240 )
                    goto LABEL_359;
                }
              }
              else
              {
LABEL_359:
                v15 = 0;
              }
              goto LABEL_361;
            }
          }
        }
      }
      v10 = v9[5] * v9[6];
      v11 = v238;
      v12 = &v220[(_DWORD)v238];
      *(_DWORD *)&v220[(_DWORD)v238] = v10;
      v13 = (struct D3DXShader::CNode **)((char *)&v221 + (_DWORD)v11);
      *(int *)((char *)&v221 + (_DWORD)v11) = (int)v9;
      v14 = (double *)MemAlloc_Alloc(nSize: 16 * v10);
      *(void **)((char *)&pMem + (_DWORD)v238) = v14;
      if ( v14 == nullptr )
      {
        v15 = -2147024882;
        goto LABEL_361;
      }
      v15 = D3DXShader::CParse::Eval(this: v239, a2: *v13, a3: (struct D3DXShader::_D3DXVALUE *)v14);
      if ( v15 >= 0 )
      {
        v237 = nullptr;
        if ( *v12 != 0 )
        {
          HIDWORD(v230) = (char *)a2 + 48;
          v16 = v14 + 1;
          do
          {
            v15 = D3DXShader::CParse::CastToFloat(
                    this: v239,
                    a2: v16,
                    a3: (struct D3DXShader::_D3DXVALUE *)v14,
                    a4: (struct D3DXShader::D3DXTOKEN *)HIDWORD(v230));
            if ( v15 < 0 )
              goto LABEL_361;
            v237 = (double *)((char *)v237 + 1);
            v18 = v237;
            *(_DWORD *)v14 = 3;
            v14 += 2;
            v16 = (double *)(v17 + 16);
          }
          while ( (unsigned int)v18 < *v12 );
        }
        goto LABEL_16;
      }
LABEL_361:
      for ( i35 = 0; i35 < 4; ++i35 )
        free(pMem: *(&pMem + i35));
      return v15;
    }
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x101F9076
// Name: protected: long D3DXShader::CParse::FindDecl(enum D3DXShader::_D3DXDECL_TYPE,struct D3DXShader::D3DXTOKEN __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNodeScope __near *,unsigned long,class D3DXShader::CNode __near * __near *,class D3DXShader::CNode __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::FindDecl(
        D3DXShader::CParse *this,
        int a2,
        const char **a3,
        const char **a4,
        struct D3DXShader::CNode *a5,
        struct D3DXShader::CNodeScope **a6,
        unsigned int a7,
        int *a8,
        int **a9)
{
  int *v9; // esi
  struct D3DXShader::CNode *Decls; // eax
  bool i; // zf
  int v12; // esi
  unsigned int v13; // ebx
  bool v14; // zf
  unsigned int v15; // eax
  struct D3DXShader::CNodeScope *v16; // eax
  struct D3DXShader::CNode *j; // eax
  struct D3DXShader::CNode *v18; // eax
  int v19; // edi
  int v20; // esi
  unsigned int v21; // ebx
  int v22; // edx
  struct D3DXShader::CNode *v24; // eax
  int v25; // edi
  int **v26; // esi
  unsigned __int8 *v27; // eax
  int *v28; // eax
  unsigned __int8 *v29; // eax
  int v30; // eax
  int v31; // edi
  unsigned __int8 *v32; // eax
  int v33; // eax
  bool v34; // zf
  unsigned __int8 *v35; // eax
  unsigned __int8 *v36; // eax
  int *v37; // edi
  int v38; // esi
  unsigned __int8 *v39; // eax
  const char *v40; // ebx
  unsigned int v41; // eax
  int v42; // esi
  char *v43; // ebx
  unsigned int v44; // eax
  int v45; // ecx
  const char *v46; // edi
  const char *v47; // esi
  bool v48; // zf
  unsigned __int8 *v49; // eax
  int v50; // eax
  char v51; // al
  unsigned __int8 *v52; // eax
  unsigned __int8 *v53; // eax
  _DWORD *v54; // esi
  unsigned __int8 *v55; // eax
  int v56; // eax
  unsigned __int8 *v57; // eax
  int v58; // eax
  int v59; // [esp-4h] [ebp-120h]
  int v60; // [esp-4h] [ebp-120h]
  int v61; // [esp-4h] [ebp-120h]
  _DWORD v62[64]; // [esp+Ch] [ebp-110h]
  struct D3DXShader::CNode *v63; // [esp+10Ch] [ebp-10h]
  unsigned int v64; // [esp+110h] [ebp-Ch]
  unsigned int v65; // [esp+114h] [ebp-8h]
  D3DXShader::CParse *v66; // [esp+118h] [ebp-4h]

  v9 = a8;
  v66 = this;
  if ( a8 != nullptr )
    *a8 = 0;
  if ( a9 != nullptr )
    *a9 = nullptr;
  v64 = -1;
  v65 = 0;
  if ( a6 != nullptr )
  {
    while ( 2 )
    {
      if ( v64 != 0 )
      {
        Decls = D3DXShader::CParse::FindDecls(this: v66, a2: a3, a3: (struct D3DXShader::CNodeScope *)a6);
        for ( i = Decls == nullptr; ; i = Decls == nullptr )
        {
          v63 = Decls;
          if ( i || v64 == 0 )
            break;
          v12 = *((_DWORD *)v63 + 2);
          if ( a2 != *(_DWORD *)(v12 + 16) )
          {
            if ( (a7 & 5) != 0 )
              D3DXShader::CParse::Error(
                this: v66,
                a2: (struct D3DXShader::D3DXTOKEN *)a3,
                a3: 0xBBDu,
                format: "'%s': identifier represents a %s, not a %s",
                a3[2],
                *((const char **)&off_102B9D70 + *(_DWORD *)(v12 + 16)),
                *((const char **)&off_102B9D70 + a2));
            if ( a8 != nullptr )
              *a8 = 0;
            return -2147467259;
          }
          v13 = 0;
          if ( (a7 & 4) != 0 )
            v13 = D3DXShader::CParse::ScoreFunctionCall(
                    this: v66,
                    a2: *(struct D3DXShader::CNodeFunction **)(v12 + 24),
                    a3: a4,
                    a4: a5,
                    a5: a7);
          if ( (a7 & 8) != 0 )
            v13 += D3DXShader::CParse::ScoreFunctionDecl(
                     this: v66,
                     a2: *(struct D3DXShader::CNodeFunction **)(v12 + 24),
                     a3: a4,
                     a4: a5,
                     a5: a7);
          if ( v13 != -1 )
          {
            v14 = v13 == v64;
            if ( v13 < v64 )
            {
              v65 = 0;
              v64 = v13;
              v14 = true;
            }
            if ( v14 && v65 < 0x40 )
            {
              v15 = v65++;
              v62[v15] = v12;
            }
            if ( v64 == 0 && *(_DWORD *)(v12 + 44) != 0 && *(_DWORD *)(v12 + 40) == 0 )
            {
              v16 = a6[8];
              if ( v16 != nullptr && *((_DWORD *)v16 + 4) == 4 )
              {
                for ( j = D3DXShader::CParse::FindDecls(this: v66, a2: a3, a3: a6[8]);
                      j != nullptr;
                      j = *((struct D3DXShader::CNode **)j + 3) )
                {
                  if ( *(_DWORD *)(*((_DWORD *)j + 2) + 44) == 0 )
                  {
                    D3DXShader::CParse::Warning(
                      this: v66,
                      a2: (struct D3DXShader::D3DXTOKEN *)a3,
                      a3: 0xC06u,
                      format: "'%s': loop control variable used outside for-loop scope conflicts with a previous declaration in t"
                      "he outer scope; most recent definition used",
                      a3[2]);
                    *(_DWORD *)(v12 + 40) = 1;
                    break;
                  }
                }
              }
              v18 = v63;
              while ( 1 )
              {
                v18 = *((struct D3DXShader::CNode **)v18 + 3);
                if ( v18 == nullptr )
                  break;
                if ( *(_DWORD *)(*((_DWORD *)v18 + 2) + 44) == 0 )
                {
                  D3DXShader::CParse::Warning(
                    this: v66,
                    a2: (struct D3DXShader::D3DXTOKEN *)a3,
                    a3: 0xC06u,
                    format: "'%s': loop control variable used outside for-loop scope conflicts with a previous declaration in the"
                    " outer scope; most recent definition used",
                    a3[2]);
                  *(_DWORD *)(v12 + 40) = 1;
                  break;
                }
              }
            }
          }
          Decls = *((struct D3DXShader::CNode **)v63 + 3);
        }
        a6 = (struct D3DXShader::CNodeScope **)a6[8];
        if ( a6 != nullptr )
          continue;
      }
      break;
    }
    if ( v64 != -1 )
    {
      v19 = v62[0];
      if ( (a7 & 4) != 0 )
      {
        v20 = *(_DWORD *)(v62[0] + 24);
        v21 = 1;
        if ( v65 > 1 )
        {
          do
          {
            if ( !D3DXShader::CParse::IsTypeEqual(
                    this: v66,
                    a2: *(struct D3DXShader::CNode **)(v20 + 32),
                    a3: *(struct D3DXShader::CNode **)(*(_DWORD *)(v62[v21] + 24) + 32)) )
              break;
            if ( D3DXShader::CParse::ScoreFunctionDecl(
                   this: v66,
                   a2: (struct D3DXShader::CNodeFunction *)v20,
                   a3: *(const char ***)(v20 + 28),
                   a4: *(struct D3DXShader::CNode **)(v22 + 36),
                   a5: 0) == -1 )
              break;
            ++v21;
          }
          while ( v21 < v65 );
          if ( v21 < v65 )
            D3DXShader::CParse::Error(
              this: v66,
              a2: (struct D3DXShader::D3DXTOKEN *)a3,
              a3: 0xBFBu,
              format: "'%s': ambiguous function call",
              a3[2]);
        }
      }
      if ( a8 == nullptr )
        goto LABEL_57;
      if ( (a7 & 2) != 0 )
      {
        *a8 = *(_DWORD *)(v19 + 24);
        goto LABEL_57;
      }
      if ( *(_DWORD *)(v19 + 24) == 0
        || (v24 = D3DXShader::CNode::Copy(a1: *(struct D3DXShader::CNode **)(v19 + 24)), *a8 = (int)v24, v24 != nullptr) )
      {
LABEL_57:
        v25 = 0;
        if ( a9 != nullptr )
        {
          a8 = nullptr;
          v26 = &a8;
          if ( v65 != 0 )
          {
            do
            {
              v27 = D3DXShader::CNode::operator new(a1: 0x14u);
              v28 = v27 != nullptr
                  ? (int *)D3DXShader::CNodeList::CNodeList(
                             this: (D3DXShader::CNodeList *)v27,
                             a2: nullptr,
                             a3: nullptr,
                             a4: "Values")
                  : nullptr;
              *v26 = v28;
              if ( v28 == nullptr )
                return -2147024882;
              v29 = D3DXShader::CNode::operator new(a1: 0x40u);
              v30 = v29 != nullptr
                  ? D3DXShader::CNodeValue::CNodeValue(a1: v29, a2: 2, a3: *(_DWORD *)(v62[v25] + 36), a4: a3)
                  : 0;
              (*v26)[2] = v30;
              if ( v30 == 0 )
                return -2147024882;
              v26 = (int **)(*v26 + 3);
            }
            while ( ++v25 < v65 );
          }
          *a9 = a8;
        }
        return 0;
      }
      return -2147024882;
    }
    v9 = a8;
  }
  if ( (a7 & 2) == 0 && a9 == nullptr )
  {
    if ( a2 != 0 )
    {
      if ( a2 == 1 && strcmp(a3[2], "NULL") == 0 )
      {
        if ( a8 != nullptr )
        {
          v53 = D3DXShader::CNode::operator new(a1: 0x40u);
          if ( v53 != nullptr )
            v54 = (_DWORD *)D3DXShader::CNodeVariable::CNodeVariable(this: (D3DXShader::CNodeVariable *)v53);
          else
            v54 = nullptr;
          if ( v54 == nullptr )
            return -2147024882;
          v54[5] = 1;
          v54[6] = 0;
          v54[7] = 514;
          v55 = D3DXShader::CNode::operator new(a1: 0x24u);
          v56 = v55 != nullptr ? D3DXShader::CNodeType::CNodeType(a1: v55, a2: 3, a3: 13, a4: 1, a5: 1, a6: 512) : 0;
          v54[8] = v56;
          if ( v56 == 0 )
            return -2147024882;
          v57 = D3DXShader::CNode::operator new(a1: 0x40u);
          v58 = v57 != nullptr ? D3DXShader::CNodeValue::CNodeValue(a1: v57, a2: 5, a3: 0, a4: 0, a5: a3) : 0;
          v54[9] = v58;
          if ( v58 == 0 )
            return -2147024882;
          *a8 = (int)v54;
        }
        return 0;
      }
    }
    else
    {
      if ( _stricmp(dst: a3[2], src: "dword") == 0 )
      {
        v59 = 4;
        goto LABEL_77;
      }
      if ( _stricmp(dst: a3[2], src: "float") == 0 )
      {
        v59 = 11;
LABEL_77:
        v31 = v59;
        if ( v9 == nullptr )
          return 0;
        v32 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v32 != nullptr )
        {
          v33 = D3DXShader::CNodeType::CNodeType(a1: v32, a2: 0, a3: v31, a4: 1, a5: 1, a6: 0);
LABEL_81:
          *v9 = v33;
LABEL_82:
          v34 = v33 == 0;
          goto LABEL_83;
        }
LABEL_80:
        v33 = 0;
        goto LABEL_81;
      }
      if ( _stricmp(dst: a3[2], src: "vector") == 0 )
      {
        if ( v9 == nullptr )
          return 0;
        v35 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v35 != nullptr )
        {
          v33 = D3DXShader::CNodeType::CNodeType(a1: v35, a2: 1, a3: 11, a4: 1, a5: 4, a6: 0);
          goto LABEL_81;
        }
        goto LABEL_80;
      }
      if ( _stricmp(dst: a3[2], src: (const char *)&stru_102A69D8) == 0 )
      {
        if ( v9 == nullptr )
          return 0;
        v36 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v36 != nullptr )
        {
          v33 = D3DXShader::CNodeType::CNodeType(a1: v36, a2: 2, a3: 11, a4: 4, a5: 4, a6: 0);
          goto LABEL_81;
        }
        goto LABEL_80;
      }
      if ( _stricmp(dst: a3[2], src: "string") == 0 )
      {
        v60 = 14;
LABEL_101:
        v37 = a8;
        v38 = v60;
        if ( a8 == nullptr )
          return 0;
        v39 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v39 != nullptr )
          v33 = D3DXShader::CNodeType::CNodeType(a1: v39, a2: 3, a3: v38, a4: 1, a5: 1, a6: 0);
        else
          v33 = 0;
        *v37 = v33;
        goto LABEL_82;
      }
      if ( _stricmp(dst: a3[2], src: "texture") == 0 )
      {
        v60 = 15;
        goto LABEL_101;
      }
      if ( _stricmp(dst: a3[2], src: "pixelshader") == 0 )
      {
        v60 = 25;
        goto LABEL_101;
      }
      if ( _stricmp(dst: a3[2], src: "vertexshader") == 0 )
      {
        v60 = 26;
        goto LABEL_101;
      }
      v40 = a3[2];
      v41 = strlen(v40);
      if ( v41 >= 4 && *(_DWORD *)v40 == *(_DWORD *)"bool" )
      {
        v42 = 0;
        v43 = (char *)(v40 + 4);
        v44 = v41 - 4;
      }
      else
      {
        if ( v41 >= 3 && memcmp(a3[2], "int", 3u) == 0 )
        {
          v43 = (char *)(v40 + 3);
          v61 = 4;
          v44 = v41 - 3;
        }
        else if ( v41 >= 4 && *(_DWORD *)v40 == *(_DWORD *)"half" )
        {
          v43 = (char *)(v40 + 4);
          v61 = 10;
          v44 = v41 - 4;
        }
        else if ( v41 >= 5 && memcmp(a3[2], "float", 5u) == 0 )
        {
          v43 = (char *)(v40 + 5);
          v61 = 11;
          v44 = v41 - 5;
        }
        else
        {
          if ( v41 < 6 )
            goto LABEL_160;
          v45 = 3;
          v46 = "double";
          v47 = a3[2];
          v48 = true;
          do
          {
            if ( v45 == 0 )
              break;
            v48 = *(_WORD *)v47 == *(_WORD *)v46;
            v47 += 2;
            v46 += 2;
            --v45;
          }
          while ( v48 );
          if ( !v48 )
            goto LABEL_160;
          v43 = (char *)(v40 + 6);
          v61 = 12;
          v44 = v41 - 6;
        }
        v42 = v61;
      }
      if ( v44 == 1 )
      {
        if ( *v43 >= 49 && *v43 < 53 )
        {
          if ( a8 == nullptr )
            return 0;
          v49 = D3DXShader::CNode::operator new(a1: 0x24u);
          if ( v49 != nullptr )
          {
            v50 = D3DXShader::CNodeType::CNodeType(a1: v49, a2: 1, a3: v42, a4: 1, a5: *v43 - 48, a6: 0);
LABEL_141:
            *a8 = v50;
            v34 = v50 == 0;
LABEL_83:
            if ( v34 )
              return -2147024882;
            return 0;
          }
          goto LABEL_140;
        }
      }
      else if ( v44 == 3 && *v43 >= 49 && *v43 < 53 && v43[1] == 120 )
      {
        v51 = v43[2];
        if ( v51 >= 49 && v51 < 53 )
        {
          if ( a8 == nullptr )
            return 0;
          v52 = D3DXShader::CNode::operator new(a1: 0x24u);
          if ( v52 != nullptr )
          {
            v50 = D3DXShader::CNodeType::CNodeType(a1: v52, a2: 2, a3: v42, a4: *v43 - 48, a5: v43[2] - 48, a6: 0);
            goto LABEL_141;
          }
LABEL_140:
          v50 = 0;
          goto LABEL_141;
        }
      }
    }
  }
LABEL_160:
  if ( (a7 & 1) != 0 )
    D3DXShader::CParse::Error(
      this: v66,
      a2: (struct D3DXShader::D3DXTOKEN *)a3,
      a3: 0xBBCu,
      format: "undeclared identifier '%s'",
      a3[2]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F9733
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::VariableExpr(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::VariableExpr(
        struct D3DXShader::CNodeScope ***this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  struct D3DXShader::CNode *v3; // edi
  const char **v4; // esi
  unsigned __int8 *v5; // eax
  int v6; // esi
  int v7; // eax
  unsigned __int8 *v8; // eax
  struct D3DXShader::CNode **v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // eax
  struct D3DXShader::CNode *v14; // [esp+8h] [ebp-4h] BYREF
  struct D3DXShader::CNode *v15; // [esp+14h] [ebp+8h]

  v14 = nullptr;
  if ( a2 != nullptr && *((_DWORD *)a2 + 1) == 3 )
  {
    v3 = a3;
    v4 = (const char **)((char *)a2 + 16);
    v15 = (struct D3DXShader::CNode *)((char *)a2 + 16);
    if ( a3 == nullptr )
    {
      if ( D3DXShader::CParse::FindDecl(
             (D3DXShader::CParse *)this,
             a2: 1,
             a3: v4,
             a4: nullptr,
             a5: nullptr,
             a6: *(this + 4),
             a7: 1u,
             a8: (int *)&v14,
             a9: nullptr) != 0 )
        return nullptr;
      v3 = v14;
    }
    v5 = D3DXShader::CNode::operator new(a1: 0x50u);
    if ( v5 != nullptr )
      v6 = D3DXShader::CNodeExpression::CNodeExpression(a1: v5, a2: 0, a3: 0, a4: 0, a5: 0, a6: 1, a7: v4);
    else
      v6 = 0;
    if ( v6 != 0 )
    {
      if ( *((_DWORD *)v3 + 9) != 0 )
      {
        v7 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v3 + 9) + 4))(a1: *((_DWORD *)v3 + 9));
      }
      else
      {
        v8 = D3DXShader::CNode::operator new(a1: 0x40u);
        v7 = v8 != nullptr
           ? D3DXShader::CNodeValue::CNodeValue(
               a1: v8,
               a2: 6,
               a3: *((_DWORD *)v3 + 4),
               a4: *((_DWORD *)v3 + 5),
               a5: v15)
           : 0;
      }
      *(_DWORD *)(v6 + 32) = v7;
      if ( v7 != 0 )
      {
        v9 = (struct D3DXShader::CNode **)D3DXShader::CNode::Copy(a1: *((struct D3DXShader::CNode **)v3 + 8));
        *(_DWORD *)(v6 + 16) = v9;
        if ( a3 != nullptr )
          D3DXShader::CParse::MakeTypeConst((D3DXShader::CParse *)this, a2: v9, a3: 0);
        v10 = D3DXShader::CNode::operator new(a1: 0x14u);
        v11 = v10 != nullptr
            ? D3DXShader::CNodeList::CNodeList(
                this: (D3DXShader::CNodeList *)v10,
                a2: *(struct D3DXShader::CNode **)(v6 + 32),
                a3: nullptr,
                a4: "Value")
            : 0;
        if ( v11 != 0 )
        {
          *(_DWORD *)(v6 + 32) = v11;
          D3DXShader::CParse::ComputeExprSize((D3DXShader::CParse *)this, a2: (struct D3DXShader::CNode *)v6);
          return (struct D3DXShader::CNode *)v6;
        }
      }
    }
    return nullptr;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F983A
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::CastExpr(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::CastExpr(
        struct D3DXShader::CNodeScope ***this,
        const char **a2,
        struct D3DXShader::CNode **a3,
        int a4,
        int a5)
{
  struct D3DXShader::CNode *v5; // edi
  struct D3DXShader::CNode *v7; // ebx
  unsigned __int8 *v8; // eax
  int v9; // esi
  int v10; // eax
  int v11; // eax
  int i; // edi
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  int v16; // eax
  unsigned int v18; // [esp-8h] [ebp-1Ch]
  char *v19; // [esp-4h] [ebp-18h]
  struct D3DXShader::CNode *v20; // [esp+Ch] [ebp-8h] BYREF
  D3DXShader::CParse *v21; // [esp+10h] [ebp-4h]
  struct D3DXShader::D3DXTOKEN *v22; // [esp+1Ch] [ebp+8h]
  unsigned int IsConst; // [esp+20h] [ebp+Ch]
  struct D3DXShader::CNode *v24; // [esp+20h] [ebp+Ch]

  v5 = (struct D3DXShader::CNode *)a2;
  v21 = (D3DXShader::CParse *)this;
  v20 = nullptr;
  if ( a2 != nullptr && a2[1] == (const char *)3 )
  {
    D3DXShader::CParse::FindDecl(
      (D3DXShader::CParse *)this,
      a2: 0,
      a3: a2 + 4,
      a4: nullptr,
      a5: nullptr,
      a6: *(this + 4),
      a7: 1u,
      a8: (int *)&v20,
      a9: nullptr);
    v5 = v20;
  }
  v22 = (struct D3DXShader::D3DXTOKEN *)(this + 8);
  if ( a4 != 0 )
  {
    if ( v5 == nullptr || *((_DWORD *)v5 + 1) != 9 || !D3DXShader::CParse::IsNumeric((D3DXShader::CParse *)this, a2: v5) )
    {
      D3DXShader::CParse::Error(
        (D3DXShader::CParse *)this,
        a2: v22,
        a3: 0xBDDu,
        format: "constructors only defined for numeric base types");
      return nullptr;
    }
    v7 = (struct D3DXShader::CNode *)a3;
    if ( a3 != nullptr && a3[1] != (struct D3DXShader::CNode *)1 )
      return nullptr;
    IsConst = D3DXShader::CParse::IsConst((D3DXShader::CParse *)this, a2: v5);
  }
  else
  {
    v20 = nullptr;
    v7 = (struct D3DXShader::CNode *)a3;
    if ( a3 != nullptr )
    {
      if ( a3[1] != (struct D3DXShader::CNode *)13 )
        return nullptr;
      v20 = a3[4];
      v22 = (struct D3DXShader::D3DXTOKEN *)(a3 + 12);
    }
    if ( !D3DXShader::CParse::IsSupportedCast((D3DXShader::CParse *)this, a2: v5, a3: v20, a4: a5) )
    {
      D3DXShader::CParse::ErrorUnsupportedCast(
        (D3DXShader::CParse *)this,
        a2: v22,
        a3: nullptr,
        a4: v5,
        a5: v20,
        a6: a5);
      return nullptr;
    }
    IsConst = D3DXShader::CParse::IsConst((D3DXShader::CParse *)this, a2: v5) != 0
           || D3DXShader::CParse::IsConst((D3DXShader::CParse *)this, a2: v20) != 0;
  }
  v24 = (struct D3DXShader::CNode *)(D3DXShader::CParse::IsPartiallyLiteral((D3DXShader::CParse *)this, a2: v7) | IsConst);
  v8 = D3DXShader::CNode::operator new(a1: 0x50u);
  v9 = 0;
  if ( v8 != nullptr )
    v9 = D3DXShader::CNodeExpression::CNodeExpression(a1: v8, a2: 0, a3: 0, a4: 0, a5: 0, a6: 1, a7: v22);
  if ( v9 != 0 )
  {
    if ( v5 == nullptr
      || (v10 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)v5 + 4))(a1: v5),
          *(_DWORD *)(v9 + 16) = v10,
          v10 != 0) )
    {
      if ( v7 == nullptr
        || (v11 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)v7 + 4))(a1: v7),
            *(_DWORD *)(v9 + 32) = v11,
            v11 != 0) )
      {
        if ( a4 != 0 )
        {
          for ( i = *(_DWORD *)(v9 + 32); i != 0; i = *(_DWORD *)(i + 12) )
          {
            v13 = *(_DWORD *)(i + 8);
            if ( v13 != 0 && *(_DWORD *)(v13 + 4) == 13 )
            {
              if ( !D3DXShader::CParse::IsNumeric(this: v21, a2: *(struct D3DXShader::CNode **)(v13 + 16)) )
              {
                v19 = "cannot convert from 'object type' to 'numeric type'";
                v18 = 3017;
                goto LABEL_49;
              }
              if ( v24 == nullptr )
                v24 = (struct D3DXShader::CNode *)D3DXShader::CParse::IsConst(
                                                    this: v21,
                                                    a2: *(struct D3DXShader::CNode **)(*(_DWORD *)(i + 8) + 16));
            }
          }
        }
        if ( v24 != nullptr )
          D3DXShader::CParse::MakeTypeConst(this: v21, a2: *(struct D3DXShader::CNode ***)(v9 + 16), a3: 1);
        if ( a4 == 0 )
          goto LABEL_51;
        v14 = *(_DWORD *)(v9 + 32);
        v15 = 0;
        while ( v14 != 0 )
        {
          v16 = *(_DWORD *)(v14 + 8);
          if ( v16 != 0 && *(_DWORD *)(v16 + 4) == 13 )
            v15 += D3DXShader::CParse::TypeSize(this: v21, a2: *(struct D3DXShader::CNode **)(v16 + 16));
          v14 = *(_DWORD *)(v14 + 12);
        }
        if ( v15 == D3DXShader::CParse::TypeSize(this: v21, a2: *(struct D3DXShader::CNode **)(v9 + 16)) )
        {
LABEL_51:
          D3DXShader::CParse::ComputeExprSize(this: v21, a2: (struct D3DXShader::CNode *)v9);
          return (struct D3DXShader::CNode *)v9;
        }
        v19 = "incorrect number of arguments to numeric-type constructor";
        v18 = 3014;
LABEL_49:
        D3DXShader::CParse::Error(this: v21, a2: v22, a3: v18, format: v19);
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F9A63
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::ConditionalExpr(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::ConditionalExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4)
{
  struct D3DXShader::D3DXTOKEN *v6; // ebx
  struct D3DXShader::CNode *v7; // ebx
  unsigned __int8 *v8; // eax
  struct D3DXShader::CNode **v9; // esi
  unsigned __int8 *v10; // eax
  int v11; // eax
  unsigned __int8 *v12; // ebx
  struct D3DXShader::CNode *v13; // eax
  unsigned __int8 *v14; // eax
  struct D3DXShader::CNode *v15; // esi
  unsigned __int8 *v16; // eax
  int v17; // eax
  struct D3DXShader::CNode *v18; // ebx
  unsigned __int8 *v19; // eax
  int v20; // eax
  struct D3DXShader::CNode *v21; // eax
  unsigned __int8 *v22; // eax
  int v23; // eax
  struct D3DXShader::CNode *v24; // ebx
  unsigned __int8 *v25; // eax
  int v26; // eax
  struct D3DXShader::CNode *v27; // eax
  int v28; // [esp-Ch] [ebp-34h]
  char *v29; // [esp-8h] [ebp-30h]
  struct D3DXShader::CNode *v30; // [esp+8h] [ebp-20h] BYREF
  struct D3DXShader::CNode *v31; // [esp+Ch] [ebp-1Ch] BYREF
  struct D3DXShader::CNode *v32; // [esp+10h] [ebp-18h]
  struct D3DXShader::CNode *v33; // [esp+14h] [ebp-14h]
  struct D3DXShader::CNode *v34; // [esp+18h] [ebp-10h]
  struct D3DXShader::D3DXTOKEN *v35; // [esp+1Ch] [ebp-Ch]
  struct D3DXShader::CNode *v36; // [esp+20h] [ebp-8h]
  D3DXShader::CParse *v37; // [esp+24h] [ebp-4h]

  v37 = this;
  if ( a2 != nullptr && *((_DWORD *)a2 + 1) != 13
    || a3 != nullptr && *((_DWORD *)a3 + 1) != 13
    || a4 != nullptr && *((_DWORD *)a4 + 1) != 13 )
  {
    return nullptr;
  }
  v6 = (struct D3DXShader::CNode *)((char *)a2 + 48);
  if ( a2 == nullptr )
    v6 = (D3DXShader::CParse *)((char *)this + 32);
  v35 = v6;
  if ( a2 != nullptr )
    v32 = *((struct D3DXShader::CNode **)a2 + 4);
  else
    v32 = nullptr;
  if ( a3 != nullptr )
    v34 = *((struct D3DXShader::CNode **)a3 + 4);
  else
    v34 = nullptr;
  if ( a4 != nullptr )
    v33 = *((struct D3DXShader::CNode **)a4 + 4);
  else
    v33 = nullptr;
  v31 = v34;
  v30 = v33;
  v7 = nullptr;
  v8 = D3DXShader::CNode::operator new(a1: 0x50u);
  if ( v8 != nullptr )
    v36 = (struct D3DXShader::CNode *)D3DXShader::CNodeExpression::CNodeExpression(
                                        a1: v8,
                                        a2: 0,
                                        a3: 24,
                                        a4: 0,
                                        a5: 0,
                                        a6: 1,
                                        a7: v35);
  else
    v36 = nullptr;
  if ( v36 == nullptr )
    return nullptr;
  if ( !D3DXShader::CParse::IsNumeric(this, a2: v32) )
  {
    D3DXShader::CParse::Error(this, a2: v35, a3: 0xBCCu, format: "conditional must be numeric");
    return nullptr;
  }
  v9 = (struct D3DXShader::CNode **)((char *)v36 + 16);
  if ( D3DXShader::CParse::BinaryType(
         this: v37,
         a2: v34,
         a3: v33,
         a4: &v31,
         a5: &v30,
         a6: (struct D3DXShader::CNode **)v36 + 4) < 0 )
  {
    v29 = "type mismatch between conditional values";
LABEL_39:
    D3DXShader::CParse::Error(this: v37, a2: v35, a3: 0xBCCu, format: v29);
    return nullptr;
  }
  if ( *v9 != nullptr )
  {
    if ( *((_DWORD *)*v9 + 1) == 9 )
    {
      v10 = D3DXShader::CNode::operator new(a1: 0x24u);
      if ( v10 != nullptr )
      {
        v11 = D3DXShader::CNodeType::CNodeType(
                a1: v10,
                a2: 2,
                a3: 0,
                a4: *((_DWORD *)*v9 + 6),
                a5: *((_DWORD *)*v9 + 7),
                a6: 512);
LABEL_34:
        v7 = (struct D3DXShader::CNode *)v11;
        goto LABEL_36;
      }
    }
    else
    {
      v12 = D3DXShader::CNode::operator new(a1: 0x24u);
      if ( v12 != nullptr )
      {
        v28 = D3DXShader::CParse::TypeSize(this: v37, a2: *v9);
        v11 = D3DXShader::CNodeType::CNodeType(a1: v12, a2: 2, a3: 0, a4: 1, a5: v28, a6: 512);
        goto LABEL_34;
      }
    }
    v7 = nullptr;
LABEL_36:
    if ( v7 == nullptr )
      return nullptr;
    if ( !D3DXShader::CParse::IsSupportedCast(this: v37, a2: v7, a3: v32, a4: 0) )
    {
      v29 = "dimension of conditional does not match value";
      goto LABEL_39;
    }
  }
  if ( a2 == nullptr
    || (v13 = D3DXShader::CParse::CastExpr(
                this: (struct D3DXShader::CNodeScope ***)v37,
                a2: (const char **)v7,
                a3: (struct D3DXShader::CNode **)a2,
                a4: 0,
                a5: 0),
        *((_DWORD *)v36 + 8) = v13,
        v13 != nullptr) )
  {
    v14 = D3DXShader::CNode::operator new(a1: 0x50u);
    v15 = v14 != nullptr
        ? (struct D3DXShader::CNode *)D3DXShader::CNodeExpression::CNodeExpression(
                                        a1: v14,
                                        a2: 0,
                                        a3: 0,
                                        a4: 0,
                                        a5: 0,
                                        a6: 1,
                                        a7: v35)
        : nullptr;
    *((_DWORD *)v36 + 9) = v15;
    if ( v15 != nullptr )
    {
      v16 = D3DXShader::CNode::operator new(a1: 0x14u);
      v17 = v16 != nullptr
          ? D3DXShader::CNodeList::CNodeList(this: (D3DXShader::CNodeList *)v16, a2: nullptr, a3: nullptr, a4: "Types")
          : 0;
      *((_DWORD *)v15 + 4) = v17;
      if ( v17 != 0 )
      {
        v18 = v31;
        if ( v31 == nullptr
          || (*(_DWORD *)(*((_DWORD *)v15 + 4) + 8) = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)v31 + 4))(a1: v31),
              *(_DWORD *)(*((_DWORD *)v15 + 4) + 8) != 0) )
        {
          v19 = D3DXShader::CNode::operator new(a1: 0x14u);
          v20 = v19 != nullptr
              ? D3DXShader::CNodeList::CNodeList(
                  this: (D3DXShader::CNodeList *)v19,
                  a2: nullptr,
                  a3: nullptr,
                  a4: "Value")
              : 0;
          *((_DWORD *)v15 + 8) = v20;
          if ( v20 != 0 )
          {
            if ( a3 == nullptr
              || (v34 == v18 || D3DXShader::CParse::IsTypeEqual(this: v37, a2: v34, a3: v18)
                ? (v21 = D3DXShader::CNode::Copy(a1: a3))
                : (v21 = D3DXShader::CParse::CastExpr(
                           this: (struct D3DXShader::CNodeScope ***)v37,
                           a2: (const char **)v18,
                           (struct D3DXShader::CNode **)a3,
                           a4: 0,
                           a5: 0)),
                  *(_DWORD *)(*((_DWORD *)v15 + 8) + 8) = v21,
                  *(_DWORD *)(*((_DWORD *)v15 + 8) + 8) != 0) )
            {
              v22 = D3DXShader::CNode::operator new(a1: 0x14u);
              v23 = v22 != nullptr
                  ? D3DXShader::CNodeList::CNodeList(
                      this: (D3DXShader::CNodeList *)v22,
                      a2: nullptr,
                      a3: nullptr,
                      a4: "Types")
                  : 0;
              *(_DWORD *)(*((_DWORD *)v15 + 4) + 12) = v23;
              if ( v23 != 0 )
              {
                v24 = v30;
                if ( v30 == nullptr
                  || (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)v15 + 4) + 12) + 8) = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)v30 + 4))(a1: v30),
                      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v15 + 4) + 12) + 8) != 0) )
                {
                  v25 = D3DXShader::CNode::operator new(a1: 0x14u);
                  v26 = v25 != nullptr
                      ? D3DXShader::CNodeList::CNodeList(
                          this: (D3DXShader::CNodeList *)v25,
                          a2: nullptr,
                          a3: nullptr,
                          a4: "Value")
                      : 0;
                  *(_DWORD *)(*((_DWORD *)v15 + 8) + 12) = v26;
                  if ( v26 != 0 )
                  {
                    if ( a4 == nullptr
                      || (v33 == v24 || D3DXShader::CParse::IsTypeEqual(this: v37, a2: v33, a3: v24)
                        ? (v27 = D3DXShader::CNode::Copy(a1: a4))
                        : (v27 = D3DXShader::CParse::CastExpr(
                                   this: (struct D3DXShader::CNodeScope ***)v37,
                                   a2: (const char **)v24,
                                   a3: (struct D3DXShader::CNode **)a4,
                                   a4: 0,
                                   a5: 0)),
                          *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v15 + 8) + 12) + 8) = v27,
                          *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v15 + 8) + 12) + 8) != 0) )
                    {
                      D3DXShader::CParse::ComputeExprSize(this: v37, a2: v15);
                      D3DXShader::CParse::ComputeExprSize(this: v37, a2: v36);
                      return v36;
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
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F9DD3
// Name: protected: long D3DXShader::CParse::Eval(class D3DXShader::CNode __near *,struct D3DXShader::_D3DXVALUE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::Eval(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::_D3DXVALUE *a3)
{
  int v4; // eax
  struct D3DXShader::CNode *v5; // eax
  struct D3DXShader::D3DXTOKEN *v6; // esi
  struct D3DXShader::CNode *v7; // ebx
  _DWORD *v8; // eax
  int v9; // esi
  int v11; // eax
  int v12; // eax
  struct D3DXShader::D3DXTOKEN *v13; // ebx
  struct D3DXShader::_D3DXVALUE *v14; // edi
  unsigned int v15; // eax
  struct D3DXShader::_D3DXVALUE *v16; // eax
  int v17; // eax
  int v18; // ecx
  struct D3DXShader::D3DXTOKEN *v19; // ebx
  struct D3DXShader::_D3DXVALUE *v20; // edi
  int v21; // ebx
  struct D3DXShader::D3DXTOKEN *v22; // edi
  struct D3DXShader::D3DXTOKEN *v23; // edi
  struct D3DXShader::_D3DXVALUE *v24; // ebx
  struct D3DXShader::_D3DXVALUE *v25; // edi
  struct D3DXShader::D3DXTOKEN *v26; // ebx
  struct D3DXShader::_D3DXVALUE *v27; // edi
  int v28; // ecx
  unsigned int v29; // eax
  int v30; // ebx
  struct D3DXShader::_D3DXVALUE *v31; // edi
  int v32; // eax
  struct D3DXShader::_D3DXVALUE *v33; // eax
  int v34; // ebx
  _DWORD *v35; // eax
  struct D3DXShader::_D3DXVALUE *v36; // eax
  struct D3DXShader::_D3DXVALUE *v37; // edx
  _DWORD *v38; // edx
  unsigned int v39; // eax
  double *v40; // edx
  _DWORD *v41; // edx
  unsigned int v42; // eax
  double *v43; // esi
  double v44; // st7
  double v45; // st6
  int v46; // eax
  double v47; // st6
  bool v48; // pf
  bool v49; // zf
  unsigned __int8 v51; // c2
  bool v52; // c3
  struct D3DXShader::D3DXTOKEN *v53; // ebx
  struct D3DXShader::_D3DXVALUE *v54; // edi
  unsigned int v55; // [esp+18h] [ebp-28h] BYREF
  int v56; // [esp+1Ch] [ebp-24h]
  unsigned int v57; // [esp+20h] [ebp-20h]
  struct D3DXShader::D3DXTOKEN *v58[2]; // [esp+24h] [ebp-1Ch] BYREF
  long double v59; // [esp+2Ch] [ebp-14h]
  void *pMem; // [esp+34h] [ebp-Ch]
  struct D3DXShader::_D3DXVALUE *v61; // [esp+38h] [ebp-8h]
  D3DXShader::CParse *v62; // [esp+3Ch] [ebp-4h]
  unsigned int v63; // [esp+48h] [ebp+8h]
  struct D3DXShader::CNode *v64; // [esp+48h] [ebp+8h]
  struct D3DXShader::CNode *v65; // [esp+48h] [ebp+8h]

  v62 = this;
  if ( a2 != nullptr && *((_DWORD *)a2 + 1) == 13 )
  {
    v63 = *((_DWORD *)a2 + 5) * *((_DWORD *)a2 + 6);
    if ( v63 == D3DXShader::CParse::EvalType(this, a2: *((struct D3DXShader::CNode ***)a2 + 4), a3) )
    {
      v4 = *((_DWORD *)a2 + 7);
      if ( v4 < 2 )
        goto LABEL_11;
      if ( v4 > 3 )
      {
        if ( v4 <= 19 )
          goto LABEL_11;
        if ( v4 > 21 && v4 != 25 )
        {
          if ( v4 == 26 )
            return D3DXShader::CParse::EvalIntrinsic(this: v62, a2, a3);
          if ( v4 != 27 )
          {
LABEL_11:
            v5 = *((struct D3DXShader::CNode **)a2 + 8);
            v6 = nullptr;
            v7 = nullptr;
            v55 = 0;
            v58[1] = nullptr;
            v61 = nullptr;
            pMem = nullptr;
            HIDWORD(v59) = 0;
            v57 = 0;
            if ( v5 == nullptr
              || *((_DWORD *)v5 + 1) != 13
              || (v7 = v5,
                  HIDWORD(v59) = *((_DWORD *)v5 + 5) * *((_DWORD *)v5 + 6),
                  v55 = (unsigned int)v5,
                  (v61 = (struct D3DXShader::_D3DXVALUE *)MemAlloc_Alloc(nSize: 16 * HIDWORD(v59))) != nullptr) )
            {
              v8 = *((_DWORD **)a2 + 9);
              if ( v8 == nullptr
                || v8[1] != 13
                || (v6 = *((struct D3DXShader::D3DXTOKEN **)a2 + 9),
                    v57 = v8[5] * v8[6],
                    v58[1] = v6,
                    (pMem = MemAlloc_Alloc(nSize: 16 * v57)) != nullptr) )
              {
                if ( *((_DWORD *)a2 + 10) != 0 )
                {
                  if ( v7 != nullptr )
                  {
                    v9 = D3DXShader::CParse::Eval(this: v62, a2: v7, a3: v61);
                    if ( v9 < 0 )
                      goto LABEL_159;
                    v6 = v58[1];
                  }
                  if ( v6 == nullptr )
                  {
LABEL_30:
                    v12 = *((_DWORD *)a2 + 7);
                    if ( v12 < 0 )
                      goto LABEL_104;
                    if ( v12 <= 1 )
                    {
                      if ( v7 != nullptr )
                      {
                        if ( HIDWORD(v59) == 1 )
                        {
                          v57 = 0;
                          if ( v63 != 0 )
                          {
                            v26 = (struct D3DXShader::CNode *)((char *)a2 + 48);
                            v27 = a3;
                            do
                            {
                              v9 = D3DXShader::CParse::Cast(this: v62, a2: v27, a3: v61, a4: v26);
                              if ( v9 < 0 )
                                goto LABEL_159;
                              ++v57;
                              v27 = (struct D3DXShader::_D3DXVALUE *)((char *)v27 + 16);
                            }
                            while ( v57 < v63 );
                          }
                        }
                        else if ( v63 == HIDWORD(v59)
                               || (unsigned int)(v28 = *((_DWORD *)a2 + 5)) > *((_DWORD *)v7 + 5)
                               || (v29 = *((_DWORD *)a2 + 6)) > *((_DWORD *)v7 + 6) )
                        {
                          v57 = 0;
                          if ( v63 != 0 )
                          {
                            v58[1] = (struct D3DXShader::CNode *)((char *)a2 + 48);
                            v31 = a3;
                            do
                            {
                              v9 = D3DXShader::CParse::Cast(
                                     this: v62,
                                     a2: v31,
                                     a3: (struct D3DXShader::_D3DXVALUE *)((char *)v31 + v61 - a3),
                                     a4: v58[1]);
                              if ( v9 < 0 )
                                goto LABEL_159;
                              ++v57;
                              v31 = (struct D3DXShader::_D3DXVALUE *)((char *)v31 + 16);
                            }
                            while ( v57 < v63 );
                          }
                        }
                        else
                        {
                          v65 = nullptr;
                          if ( v28 != 0 )
                          {
                            while ( 1 )
                            {
                              v30 = 0;
                              if ( v29 != 0 )
                                break;
LABEL_80:
                              v65 = (struct D3DXShader::CNode *)((char *)v65 + 1);
                              if ( (unsigned int)v65 >= *((_DWORD *)a2 + 5) )
                                goto LABEL_158;
                            }
                            while ( 1 )
                            {
                              v9 = D3DXShader::CParse::Cast(
                                     this: v62,
                                     a2: (struct D3DXShader::_D3DXVALUE *)((char *)a3 + 16 * v30 + 16 * (_DWORD)v65 * v29),
                                     a3: (struct D3DXShader::_D3DXVALUE *)((char *)v61
                                                                     + 16 * v30
                                                                     + 16 * (_DWORD)v65 * *(_DWORD *)(v55 + 24)),
                                     a4: (struct D3DXShader::CNode *)((char *)a2 + 48));
                              if ( v9 < 0 )
                                goto LABEL_159;
                              v29 = *((_DWORD *)a2 + 6);
                              if ( ++v30 >= v29 )
                                goto LABEL_80;
                            }
                          }
                        }
                      }
                      else
                      {
                        v32 = *((_DWORD *)a2 + 8);
                        if ( v32 == 0 )
                          goto LABEL_160;
                        if ( *(_DWORD *)(v32 + 4) != 14 )
                        {
                          if ( *(_DWORD *)(v32 + 4) == 1 )
                          {
                            v34 = *((_DWORD *)a2 + 8);
                            while ( 1 )
                            {
                              v35 = *(_DWORD **)(v34 + 8);
                              if ( v35 != nullptr )
                              {
                                if ( v35[1] == 14 )
                                {
                                  v36 = (struct D3DXShader::_D3DXVALUE *)(v35 + 4);
                                  if ( *(_DWORD *)v36 == 6 )
                                    goto LABEL_160;
                                  v9 = D3DXShader::CParse::Cast(
                                         this: v62,
                                         a2: a3,
                                         a3: v36,
                                         a4: (struct D3DXShader::CNode *)((char *)a2 + 48));
                                  if ( v9 < 0 )
                                    goto LABEL_159;
                                  a3 = (struct D3DXShader::_D3DXVALUE *)((char *)a3 + 16);
                                }
                                else if ( v35[1] == 13 )
                                {
                                  v9 = D3DXShader::CParse::Eval(this: v62, a2: (struct D3DXShader::CNode *)v35, a3);
                                  if ( v9 < 0 )
                                    goto LABEL_159;
                                  a3 = (struct D3DXShader::_D3DXVALUE *)((char *)a3
                                                                       + 16
                                                                       * *(_DWORD *)(*(_DWORD *)(v34 + 8) + 20)
                                                                       * *(_DWORD *)(*(_DWORD *)(v34 + 8) + 24));
                                }
                              }
                              v34 = *(_DWORD *)(v34 + 12);
                              if ( v34 == 0 )
                                goto LABEL_158;
                            }
                          }
                          goto LABEL_160;
                        }
                        v33 = (struct D3DXShader::_D3DXVALUE *)(v32 + 16);
                        if ( *(_DWORD *)v33 == 6 )
                        {
LABEL_160:
                          v9 = -2147467259;
                          goto LABEL_159;
                        }
                        v9 = D3DXShader::CParse::Cast(
                               this: v62,
                               a2: a3,
                               a3: v33,
                               a4: (struct D3DXShader::CNode *)((char *)a2 + 48));
                        if ( v9 < 0 )
                          goto LABEL_159;
                      }
                    }
                    else
                    {
                      switch ( v12 )
                      {
                        case 22:
                          v23 = (struct D3DXShader::CNode *)((char *)a2 + 48);
                          v58[1] = v23;
                          v9 = D3DXShader::CParse::CastToUint(
                                 this: v62,
                                 a2: &v55,
                                 a3: (struct D3DXShader::_D3DXVALUE *)pMem,
                                 a4: v23);
                          if ( v9 < 0 )
                            goto LABEL_159;
                          if ( v63 * v55 >= HIDWORD(v59) )
                          {
                            D3DXShader::CParse::Error(
                              this: v62,
                              a2: v23,
                              a3: 0xBD6u,
                              format: "array index out of bounds");
                            goto LABEL_160;
                          }
                          v57 = 0;
                          if ( v63 != 0 )
                          {
                            v24 = a3;
                            v25 = (struct D3DXShader::_D3DXVALUE *)((char *)v61 + 16 * v63 * v55);
                            while ( 1 )
                            {
                              v9 = D3DXShader::CParse::Cast(this: v62, a2: v24, a3: v25, a4: v58[1]);
                              if ( v9 < 0 )
                                goto LABEL_159;
                              ++v57;
                              v25 = (struct D3DXShader::_D3DXVALUE *)((char *)v25 + 16);
                              v24 = (struct D3DXShader::_D3DXVALUE *)((char *)v24 + 16);
                              if ( v57 >= v63 )
                                goto LABEL_158;
                            }
                          }
                          break;
                        case 23:
                          v17 = *((_DWORD *)a2 + 9);
                          v18 = *(_DWORD *)(v17 + 4);
                          if ( v18 == 14 )
                          {
                            v19 = (struct D3DXShader::CNode *)((char *)a2 + 48);
                            v9 = D3DXShader::CParse::CastToUint(
                                   this: v62,
                                   a2: &v55,
                                   a3: (struct D3DXShader::_D3DXVALUE *)(v17 + 16),
                                   a4: (struct D3DXShader::CNode *)((char *)a2 + 48));
                            if ( v9 < 0 )
                              goto LABEL_159;
                            v57 = 0;
                            if ( v63 != 0 )
                            {
                              v20 = (struct D3DXShader::_D3DXVALUE *)((char *)v61 + 16 * v55);
                              while ( 1 )
                              {
                                v9 = D3DXShader::CParse::Cast(this: v62, a2: a3, a3: v20, a4: v19);
                                if ( v9 < 0 )
                                  goto LABEL_159;
                                ++v57;
                                a3 = (struct D3DXShader::_D3DXVALUE *)((char *)a3 + 16);
                                v20 = (struct D3DXShader::_D3DXVALUE *)((char *)v20 + 16);
                                if ( v57 >= v63 )
                                  goto LABEL_158;
                              }
                            }
                          }
                          else
                          {
                            if ( v18 != 1 )
                              goto LABEL_160;
                            v57 = 0;
                            v21 = v17;
                            if ( v63 != 0 )
                            {
                              v22 = (struct D3DXShader::CNode *)((char *)a2 + 48);
                              while ( 1 )
                              {
                                v9 = D3DXShader::CParse::CastToUint(
                                       this: v62,
                                       a2: &v55,
                                       a3: (struct D3DXShader::_D3DXVALUE *)(*(_DWORD *)(v21 + 8) + 16),
                                       a4: v22);
                                if ( v9 < 0 )
                                  goto LABEL_159;
                                v9 = D3DXShader::CParse::Cast(
                                       this: v62,
                                       a2: a3,
                                       a3: (struct D3DXShader::_D3DXVALUE *)((char *)v61 + 16 * v55),
                                       a4: v22);
                                if ( v9 < 0 )
                                  goto LABEL_159;
                                ++v57;
                                a3 = (struct D3DXShader::_D3DXVALUE *)((char *)a3 + 16);
                                v21 = *(_DWORD *)(v21 + 12);
                                if ( v57 >= v63 )
                                  goto LABEL_158;
                              }
                            }
                          }
                          break;
                        case 24:
                          v57 = 0;
                          if ( HIDWORD(v59) != 0 )
                          {
                            v13 = (struct D3DXShader::CNode *)((char *)a2 + 48);
                            v14 = (struct D3DXShader::_D3DXVALUE *)pMem;
                            v64 = (struct D3DXShader::CNode *)((char *)pMem + 16 * v63);
                            v15 = v61 - (struct D3DXShader::_D3DXVALUE *)pMem;
                            v55 = v61 - (struct D3DXShader::_D3DXVALUE *)pMem;
                            v56 = a3 - (struct D3DXShader::_D3DXVALUE *)pMem;
                            while ( 1 )
                            {
                              v9 = D3DXShader::CParse::CastToFloat(
                                     this: v62,
                                     a2: (double *)v58,
                                     a3: (struct D3DXShader::_D3DXVALUE *)((char *)v14 + v15),
                                     a4: v13);
                              if ( v9 < 0 )
                                goto LABEL_159;
                              v16 = v14;
                              if ( *(double *)v58 == 0.0 )
                                v16 = v64;
                              v9 = D3DXShader::CParse::Cast(
                                     this: v62,
                                     a2: (struct D3DXShader::_D3DXVALUE *)((char *)v14 + v56),
                                     a3: v16,
                                     a4: v13);
                              if ( v9 < 0 )
                                goto LABEL_159;
                              ++v57;
                              v64 = (struct D3DXShader::CNode *)((char *)v64 + 16);
                              v14 = (struct D3DXShader::_D3DXVALUE *)((char *)v14 + 16);
                              if ( v57 >= HIDWORD(v59) )
                                goto LABEL_158;
                              v15 = v55;
                            }
                          }
                          break;
                        default:
LABEL_104:
                          v56 = 0;
                          if ( HIDWORD(v59) != 0 )
                          {
                            v37 = v61;
                            do
                            {
                              v9 = D3DXShader::CParse::CastToFloat(
                                     this: v62,
                                     a2: (double *)v37 + 1,
                                     a3: v37,
                                     a4: (struct D3DXShader::CNode *)((char *)a2 + 48));
                              if ( v9 < 0 )
                                goto LABEL_159;
                              v39 = ++v56;
                              *v38 = 3;
                              v37 = (struct D3DXShader::_D3DXVALUE *)(v38 + 4);
                            }
                            while ( v39 < HIDWORD(v59) );
                          }
                          v56 = 0;
                          if ( v57 != 0 )
                          {
                            v40 = (double *)pMem;
                            while ( 1 )
                            {
                              v9 = D3DXShader::CParse::CastToFloat(
                                     this: v62,
                                     a2: v40 + 1,
                                     a3: (struct D3DXShader::_D3DXVALUE *)v40,
                                     a4: (struct D3DXShader::CNode *)((char *)a2 + 48));
                              if ( v9 < 0 )
                                goto LABEL_159;
                              v42 = ++v56;
                              *v41 = 3;
                              v40 = (double *)(v41 + 4);
                              if ( v42 >= v57 )
                              {
                                v7 = (struct D3DXShader::CNode *)v55;
                                break;
                              }
                            }
                          }
                          if ( (v7 == nullptr || HIDWORD(v59) == v63) && (v58[1] == nullptr || v57 == v63) )
                          {
                            v57 = 0;
                            if ( v63 != 0 )
                            {
                              v55 = v61 - (struct D3DXShader::_D3DXVALUE *)pMem;
                              v43 = (double *)((char *)pMem + 8);
                              v56 = a3 - (struct D3DXShader::_D3DXVALUE *)pMem;
                              while ( 2 )
                              {
                                if ( v61 != nullptr )
                                  v44 = *(double *)((char *)v43 + v55);
                                else
                                  v44 = 0.0;
                                v59 = v44;
                                if ( pMem != nullptr )
                                  v45 = *v43;
                                else
                                  v45 = 0.0;
                                v46 = *((_DWORD *)a2 + 7);
                                *(double *)v58 = v45;
                                switch ( v46 )
                                {
                                  case 4:
                                    v47 = 0.0;
                                    goto LABEL_127;
                                  case 5:
                                    v44 = -v44;
                                    goto LABEL_153;
                                  case 6:
                                    goto LABEL_153;
                                  case 7:
                                    v44 = v44 * *(double *)v58;
                                    goto LABEL_153;
                                  case 8:
                                    if ( 0.0 == *(double *)v58 )
                                    {
                                      D3DXShader::CParse::Error(
                                        this: v62,
                                        a2: (struct D3DXShader::CNode *)((char *)a2 + 48),
                                        a3: 0xBD9u,
                                        format: "division by zero");
                                      v44 = v59;
                                    }
                                    v44 = v44 / *(double *)v58;
                                    goto LABEL_153;
                                  case 9:
                                    if ( 0.0 == *(double *)v58 )
                                      D3DXShader::CParse::Error(
                                        this: v62,
                                        a2: (struct D3DXShader::CNode *)((char *)a2 + 48),
                                        a3: 0xBD9u,
                                        format: "division by zero");
                                    v44 = fmod(v59, *(long double *)v58);
                                    goto LABEL_153;
                                  case 10:
                                    v44 = v44 + *(double *)v58;
                                    goto LABEL_153;
                                  case 11:
                                    v44 = v44 - *(double *)v58;
                                    goto LABEL_153;
                                  case 12:
                                    v48 = v44 >= *(double *)v58;
                                    goto LABEL_128;
                                  case 13:
                                    v49 = v44 > *(double *)v58;
                                    goto LABEL_144;
                                  case 14:
                                    v48 = v44 > *(double *)v58;
                                    goto LABEL_128;
                                  case 15:
                                    v49 = v44 >= *(double *)v58;
LABEL_144:
                                    if ( !v49 )
                                      goto LABEL_129;
                                    goto LABEL_152;
                                  case 16:
                                    v47 = *(double *)v58;
LABEL_127:
                                    v48 = v44 != v47;
LABEL_128:
                                    if ( v48 )
                                      goto LABEL_129;
                                    goto LABEL_152;
                                  case 17:
                                    goto LABEL_151;
                                  case 18:
                                    if ( v44 != 0.0 )
                                      goto LABEL_150;
                                    goto LABEL_129;
                                  case 19:
                                    if ( v44 != 0.0 )
                                      goto LABEL_152;
LABEL_150:
                                    v51 = 0;
                                    v52 = *(double *)v58 == 0.0;
LABEL_151:
                                    if ( (v52 | v51) != 0 )
LABEL_129:
                                      v44 = 0.0;
                                    else
LABEL_152:
                                      v44 = 1.0;
LABEL_153:
                                    ++v57;
                                    *(double *)((char *)v43 + v56) = v44;
                                    v43 += 2;
                                    if ( v57 >= v63 )
                                      break;
                                    continue;
                                  default:
                                    goto LABEL_160;
                                }
                                break;
                              }
                            }
                            v55 = 0;
                            if ( v63 != 0 )
                            {
                              v53 = (struct D3DXShader::CNode *)((char *)a2 + 48);
                              v54 = a3;
                              while ( 1 )
                              {
                                v9 = D3DXShader::CParse::CastToValue(
                                       this: v62,
                                       a2: v54,
                                       a3: *((double *)v54 + 1),
                                       a4: v53);
                                if ( v9 < 0 )
                                  goto LABEL_159;
                                ++v55;
                                v54 = (struct D3DXShader::_D3DXVALUE *)((char *)v54 + 16);
                                if ( v55 >= v63 )
                                  goto LABEL_158;
                              }
                            }
                            break;
                          }
                          goto LABEL_160;
                      }
                    }
LABEL_158:
                    v9 = 0;
                    goto LABEL_159;
                  }
                  v11 = D3DXShader::CParse::Eval(this: v62, a2: v58[1], a3: (struct D3DXShader::_D3DXVALUE *)pMem);
                }
                else
                {
                  if ( v6 != nullptr )
                  {
                    v9 = D3DXShader::CParse::Eval(this: v62, a2: v58[1], a3: (struct D3DXShader::_D3DXVALUE *)pMem);
                    if ( v9 < 0 )
                      goto LABEL_159;
                  }
                  if ( v7 == nullptr )
                    goto LABEL_30;
                  v11 = D3DXShader::CParse::Eval(this: v62, a2: v7, a3: v61);
                }
                v9 = v11;
                if ( v11 < 0 )
                  goto LABEL_159;
                goto LABEL_30;
              }
            }
            v9 = -2147024882;
LABEL_159:
            free(pMem);
            free(pMem: v61);
            return v9;
          }
        }
      }
    }
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x101FA630
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::IfStmt(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::IfStmt(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4)
{
  struct D3DXShader::CNode *v5; // eax
  struct D3DXShader::CNode *result; // eax
  unsigned __int8 *v7; // eax
  struct D3DXShader::CNode *v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned __int8 *v12; // eax
  _BYTE v13[16]; // [esp+8h] [ebp-18h] BYREF
  double v14; // [esp+18h] [ebp-8h] BYREF

  if ( a2 == nullptr )
    return nullptr;
  if ( *((_DWORD *)a2 + 5) * *((_DWORD *)a2 + 6) != 1
    || !D3DXShader::CParse::IsNumeric(this, a2: *((struct D3DXShader::CNode **)a2 + 4)) )
  {
    D3DXShader::CParse::Error(
      this,
      a2: (struct D3DXShader::CNode *)((char *)a2 + 48),
      a3: 0xBCBu,
      format: "float expected");
    return nullptr;
  }
  if ( D3DXShader::CParse::IsFullyLiteral(this, a2)
    && D3DXShader::CParse::Eval(this, a2, a3: (struct D3DXShader::_D3DXVALUE *)v13) >= 0
    && D3DXShader::CParse::CastToFloat(
         this,
         a2: &v14,
         a3: (struct D3DXShader::_D3DXVALUE *)v13,
         a4: (struct D3DXShader::CNode *)((char *)a2 + 48)) >= 0 )
  {
    v5 = a3;
    if ( 0.0 == v14 )
      v5 = a4;
    return D3DXShader::CNode::Copy(a1: v5);
  }
  v7 = D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v7 != nullptr )
    v8 = (struct D3DXShader::CNode *)D3DXShader::CNodeStatement::CNodeStatement(this: (D3DXShader::CNodeStatement *)v7);
  else
    v8 = nullptr;
  if ( v8 == nullptr )
    return nullptr;
  *((_DWORD *)v8 + 4) = 2;
  v9 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a2 + 4))(a1: a2);
  *((_DWORD *)v8 + 6) = v9;
  if ( v9 == 0 )
    return nullptr;
  if ( a3 != nullptr )
  {
    v10 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a3 + 4))(a1: a3);
    *((_DWORD *)v8 + 7) = v10;
    if ( v10 == 0 )
      return nullptr;
  }
  if ( a4 != nullptr )
  {
    v11 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a4 + 4))(a1: a4);
    *((_DWORD *)v8 + 8) = v11;
    if ( v11 == 0 )
      return nullptr;
  }
  v12 = D3DXShader::CNode::operator new(a1: 0x14u);
  result = v12 != nullptr
         ? (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                         this: (D3DXShader::CNodeList *)v12,
                                         a2: v8,
                                         a3: nullptr,
                                         a4: "Stmts")
         : nullptr;
  if ( result == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FA757
// Name: protected: int D3DXShader::CParse::Token(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::Token(D3DXShader::CParse *this)
{
  D3DXShader::CParse *v1; // ebx
  struct D3DXShader::D3DXTOKEN *v2; // esi
  int result; // eax
  char v4; // cl
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  char v12; // al
  int v13; // eax
  int v14; // eax
  int v15; // eax
  const char *v16; // eax
  const char *v17; // edi
  int v18; // eax
  unsigned int v19; // [esp-4h] [ebp-18h]

  v1 = this;
  v2 = (D3DXShader::CParse *)((char *)this + 32);
  while ( 2 )
  {
    if ( D3DXShader::CPreProcessor::GetToken(this: *((D3DXShader::CPreProcessor **)v1 + 1), a2: v2) >= 0 )
    {
      switch ( *(_DWORD *)v2 )
      {
        case 0:
          goto LABEL_198;
        case 1:
          v4 = *((_BYTE *)v1 + 41);
          if ( v4 == 0 )
            return *((char *)v1 + 40);
          if ( *((_BYTE *)v1 + 42) != 0 )
            goto LABEL_198;
          if ( v4 == 61 )
          {
            v5 = *((char *)v1 + 40);
            if ( v5 > 45 )
            {
              v9 = v5 - 47;
              if ( v9 == 0 )
                return 323;
              v10 = v9 - 13;
              if ( v10 == 0 )
                return 316;
              v11 = v10 - 1;
              if ( v11 == 0 )
                return 318;
              if ( v11 == 1 )
                return 317;
            }
            else
            {
              if ( v5 == 45 )
                return 326;
              v6 = v5 - 33;
              if ( v6 == 0 )
                return 319;
              v7 = v6 - 4;
              if ( v7 == 0 )
                return 324;
              v8 = v7 - 5;
              if ( v8 == 0 )
                return 322;
              if ( v8 == 1 )
                return 325;
            }
          }
          else
          {
            v12 = *((_BYTE *)v1 + 40);
            if ( v12 == v4 )
            {
              v13 = v12 - 38;
              if ( v13 == 0 )
                return 320;
              v14 = v13 - 5;
              if ( v14 == 0 )
                return 314;
              v15 = v14 - 2;
              if ( v15 == 0 )
                return 315;
              if ( v15 == 79 )
                return 321;
            }
          }
LABEL_198:
          result = 337;
          break;
        case 2:
          return 327;
        case 3:
          return 328;
        case 4:
          return 329;
        case 5:
          return 330;
        case 6:
          return 331;
        case 7:
          return 332;
        case 8:
          return 333;
        case 9:
          v16 = *((const char **)v1 + 10);
          switch ( *v16 )
          {
            case 'a':
              if ( strcmp(*((const char **)v1 + 10), "auto") == 0 )
                goto LABEL_198;
              if ( strcmp(*((const char **)v1 + 10), "asm_fragment") != 0 )
                goto LABEL_80;
              return 258;
            case 'b':
              if ( strcmp(*((const char **)v1 + 10), "bool") != 0 )
              {
                v17 = "break";
                goto LABEL_53;
              }
              return 259;
            case 'c':
              if ( strcmp(*((const char **)v1 + 10), "case") == 0
                || strcmp(*((const char **)v1 + 10), "catch") == 0
                || strcmp(*((const char **)v1 + 10), "char") == 0
                || strcmp(*((const char **)v1 + 10), "class") == 0 )
              {
                goto LABEL_198;
              }
              if ( strcmp(*((const char **)v1 + 10), "column_major") == 0 )
                return 260;
              if ( strcmp(*((const char **)v1 + 10), "compile") == 0 )
                return 261;
              if ( strcmp(*((const char **)v1 + 10), "compile_fragment") == 0 )
                return 262;
              if ( strcmp(*((const char **)v1 + 10), "const") != 0 )
              {
                if ( strcmp(*((const char **)v1 + 10), "const_cast") == 0 )
                  goto LABEL_198;
                v17 = "continue";
                goto LABEL_122;
              }
              return 263;
            case 'd':
              if ( strcmp(*((const char **)v1 + 10), "default") == 0 || strcmp(*((const char **)v1 + 10), "delete") == 0 )
                goto LABEL_198;
              if ( strcmp(*((const char **)v1 + 10), "discard") == 0 )
                return 265;
              if ( strcmp(*((const char **)v1 + 10), "do") == 0 )
                return 267;
              if ( strcmp(*((const char **)v1 + 10), "double") != 0 )
              {
                if ( strcmp(*((const char **)v1 + 10), "dynamic_cast") == 0 )
                  goto LABEL_198;
                v1 = this;
                goto LABEL_80;
              }
              return 266;
            case 'e':
              if ( strcmp(*((const char **)v1 + 10), "else") == 0 )
                return 268;
              if ( strcmp(*((const char **)v1 + 10), "enum") == 0 || strcmp(*((const char **)v1 + 10), "explicit") == 0 )
                goto LABEL_198;
              if ( strcmp(*((const char **)v1 + 10), "extern") != 0 )
                goto LABEL_80;
              return 269;
            case 'f':
              if ( strcmp(*((const char **)v1 + 10), "false") == 0 )
                return 270;
              if ( strcmp(*((const char **)v1 + 10), "float") == 0 )
                return 271;
              if ( strcmp(*((const char **)v1 + 10), "for") != 0 )
              {
                v17 = "friend";
                v19 = 7;
                goto LABEL_54;
              }
              return 272;
            case 'g':
              v17 = "goto";
              goto LABEL_113;
            case 'h':
              if ( strcmp(*((const char **)v1 + 10), "half") != 0 )
                goto LABEL_80;
              return 273;
            case 'i':
              if ( strcmp(*((const char **)v1 + 10), "if") == 0 )
                return 274;
              if ( strcmp(*((const char **)v1 + 10), "in") == 0 )
                return 275;
              if ( strcmp(*((const char **)v1 + 10), "inline") == 0 )
                return 276;
              if ( strcmp(*((const char **)v1 + 10), "inout") == 0 )
                return 277;
              if ( strcmp(*((const char **)v1 + 10), "int") != 0 )
                goto LABEL_80;
              return 278;
            case 'l':
              v17 = "long";
LABEL_113:
              v19 = 5;
              goto LABEL_54;
            case 'm':
              if ( strcmp(*((const char **)v1 + 10), (const char *)&stru_102A69D8) == 0 )
                return 279;
              v17 = "mutable";
              v19 = 8;
              goto LABEL_54;
            case 'n':
              if ( strcmp(*((const char **)v1 + 10), "namespace") == 0 )
                goto LABEL_198;
              v17 = "new";
              v19 = 4;
              goto LABEL_54;
            case 'o':
              if ( strcmp(*((const char **)v1 + 10), "out") == 0 )
                return 280;
              v17 = "operator";
LABEL_122:
              v19 = 9;
              goto LABEL_54;
            case 'p':
              if ( strcmp(*((const char **)v1 + 10), "pixelfragment") == 0 )
                return 282;
              if ( strcmp(*((const char **)v1 + 10), "private") == 0
                || strcmp(*((const char **)v1 + 10), "protected") == 0
                || strcmp(*((const char **)v1 + 10), "public") == 0 )
              {
                goto LABEL_198;
              }
              if ( *((_DWORD *)v1 + 18) == 0 || strcmp(*((const char **)v1 + 10), "pixelshader") != 0 )
                goto LABEL_80;
              return 283;
            case 'r':
              if ( strcmp(*((const char **)v1 + 10), "register") == 0 )
                return 284;
              if ( strcmp(*((const char **)v1 + 10), "reinterpret_cast") == 0 )
                goto LABEL_198;
              if ( strcmp(*((const char **)v1 + 10), "row_major") == 0 )
                return 286;
              if ( strcmp(*((const char **)v1 + 10), "return") != 0 )
                goto LABEL_80;
              return 285;
            case 's':
              if ( strcmp(*((const char **)v1 + 10), "sampler1D") == 0 )
                return 288;
              if ( strcmp(*((const char **)v1 + 10), "sampler2D") == 0 )
                return 289;
              if ( strcmp(*((const char **)v1 + 10), "sampler3D") == 0 )
                return 290;
              if ( strcmp(*((const char **)v1 + 10), "samplerCUBE") == 0 )
                return 291;
              if ( strcmp(*((const char **)v1 + 10), "sampler_state") == 0 )
                return 292;
              if ( strcmp(*((const char **)v1 + 10), "shared") == 0 )
                return 293;
              if ( strcmp(*((const char **)v1 + 10), "short") == 0
                || strcmp(*((const char **)v1 + 10), "signed") == 0
                || strcmp(*((const char **)v1 + 10), "sizeof") == 0 )
              {
                goto LABEL_198;
              }
              if ( strcmp(*((const char **)v1 + 10), "stateblock_state") == 0 )
                return 295;
              if ( strcmp(*((const char **)v1 + 10), "static") == 0 )
                return 296;
              if ( strcmp(*((const char **)v1 + 10), "static_cast") == 0 )
                goto LABEL_198;
              if ( strcmp(*((const char **)v1 + 10), "string") == 0 )
                return 297;
              if ( strcmp(*((const char **)v1 + 10), "struct") == 0 )
                return 298;
              if ( strcmp(*((const char **)v1 + 10), "switch") == 0 )
                goto LABEL_198;
              v1 = this;
              if ( *((_DWORD *)this + 18) == 0 )
                goto LABEL_80;
              if ( strcmp(v16, "sampler") == 0 )
                return 287;
              if ( strcmp(v16, "stateblock") != 0 )
                goto LABEL_80;
              return 294;
            case 't':
              if ( strcmp(*((const char **)v1 + 10), "template") == 0 )
                goto LABEL_198;
              if ( strcmp(*((const char **)v1 + 10), "texture1D") == 0 )
                return 301;
              if ( strcmp(*((const char **)v1 + 10), "texture2D") == 0 )
                return 302;
              if ( strcmp(*((const char **)v1 + 10), "texture3D") == 0 )
                return 303;
              if ( strcmp(*((const char **)v1 + 10), "textureCUBE") == 0 )
                return 304;
              if ( strcmp(*((const char **)v1 + 10), "this") == 0 || strcmp(*((const char **)v1 + 10), "throw") == 0 )
                goto LABEL_198;
              if ( strcmp(*((const char **)v1 + 10), "true") == 0 )
                return 305;
              if ( strcmp(*((const char **)v1 + 10), "try") == 0 )
                goto LABEL_198;
              if ( strcmp(*((const char **)v1 + 10), "typedef") == 0 )
                return 306;
              if ( strcmp(*((const char **)v1 + 10), "typename") == 0 )
                goto LABEL_198;
              if ( *((_DWORD *)v1 + 18) == 0 || strcmp(*((const char **)v1 + 10), "texture") != 0 )
                goto LABEL_80;
              return 300;
            case 'u':
              if ( strcmp(*((const char **)v1 + 10), "uniform") == 0 )
                return 307;
              if ( strcmp(*((const char **)v1 + 10), "union") == 0 || strcmp(*((const char **)v1 + 10), "unsigned") == 0 )
                goto LABEL_198;
              v17 = "using";
LABEL_53:
              v19 = 6;
LABEL_54:
              if ( memcmp(*((const void **)v1 + 10), v17, v19) == 0 )
                goto LABEL_198;
              goto LABEL_80;
            case 'v':
              if ( strcmp(*((const char **)v1 + 10), "vector") == 0 )
                return 308;
              if ( strcmp(*((const char **)v1 + 10), "vertexfragment") == 0 )
                return 309;
              if ( strcmp(*((const char **)v1 + 10), "virtual") == 0 )
                goto LABEL_198;
              if ( strcmp(*((const char **)v1 + 10), "void") == 0 )
                return 311;
              if ( strcmp(*((const char **)v1 + 10), "volatile") == 0 )
                return 312;
              if ( *((_DWORD *)v1 + 18) != 0 && strcmp(*((const char **)v1 + 10), "vertexshader") == 0 )
                return 310;
LABEL_80:
              v18 = tolower(c: *v16);
              switch ( v18 )
              {
                case 'a':
                  if ( _stricmp(dst: *((const char **)v1 + 10), src: "asm") == 0 )
                    return 257;
                  break;
                case 'd':
                  if ( _stricmp(dst: *((const char **)v1 + 10), src: "decl") == 0 )
                    return 264;
                  break;
                case 'p':
                  if ( _stricmp(dst: *((const char **)v1 + 10), src: "pass") == 0 )
                    return 281;
                  break;
                default:
                  if ( v18 == 116 && _stricmp(dst: *((const char **)v1 + 10), src: "technique") == 0 )
                    return 299;
                  break;
              }
              result = (D3DXShader::CParse::FindDecl(
                          this: v1,
                          a2: 0,
                          a3: (const char **)v1 + 8,
                          a4: nullptr,
                          a5: nullptr,
                          a6: *((struct D3DXShader::CNodeScope ***)v1 + 4),
                          a7: 0,
                          a8: nullptr,
                          a9: nullptr) != 0)
                     + 335;
              break;
            case 'w':
              if ( strcmp(*((const char **)v1 + 10), "while") != 0 )
                goto LABEL_80;
              return 313;
            default:
              goto LABEL_80;
          }
          return result;
        case 0xA:
          return 334;
        case 0xD:
          return -1;
        default:
          continue;
      }
    }
    else
    {
      *((_DWORD *)v1 + 16) = 1;
      return -1;
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB2B2
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::FunctionDecl(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::FunctionDecl(
        D3DXShader::CParse *this,
        const char **a2,
        struct D3DXShader::CNode **a3,
        struct D3DXShader::CNode **a4)
{
  struct D3DXShader::CNode *UsageType; // esi
  bool v6; // zf
  struct D3DXShader::CNode **i; // esi
  struct D3DXShader::CNode *v8; // ecx
  struct D3DXShader::CNode *v9; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // eax
  struct D3DXShader::CNode *v12; // ebx
  struct D3DXShader::CNode *v13; // eax
  unsigned __int8 *v14; // eax
  int v15; // esi
  struct D3DXShader::CNode *v16; // eax
  struct D3DXShader::CNode *v17; // eax
  struct D3DXShader::CNode *v18; // eax
  struct D3DXShader::CNode *v19; // eax
  struct D3DXShader::CNode *v20; // eax
  struct D3DXShader::CNode *v21; // eax
  struct D3DXShader::CNode *v22; // eax
  struct D3DXShader::CNode *v23; // eax
  int Decl; // eax
  struct D3DXShader::CNode *result; // eax
  struct D3DXShader::CNode **v26; // ebx
  struct D3DXShader::CNode *v27; // ecx
  int v28; // eax
  int v29; // eax
  int v30; // ebx
  int v31; // eax
  struct D3DXShader::CNode *v32; // [esp-8h] [ebp-6Ch]
  struct D3DXShader::CNode *v33; // [esp-4h] [ebp-68h]
  _BYTE v34[16]; // [esp+Ch] [ebp-58h] BYREF
  int v35; // [esp+1Ch] [ebp-48h]
  int v36; // [esp+20h] [ebp-44h]
  int v37; // [esp+24h] [ebp-40h]
  int v38; // [esp+28h] [ebp-3Ch]
  struct D3DXShader::CNode *v39; // [esp+2Ch] [ebp-38h]
  struct D3DXShader::CNode *v40; // [esp+38h] [ebp-2Ch]
  struct D3DXShader::CNode *v41; // [esp+4Ch] [ebp-18h]
  int *v42; // [esp+50h] [ebp-14h] BYREF
  struct D3DXShader::CNode *v43; // [esp+54h] [ebp-10h]
  int v44; // [esp+58h] [ebp-Ch]
  struct D3DXShader::CNode *v45; // [esp+5Ch] [ebp-8h]
  struct D3DXShader::D3DXTOKEN *v46; // [esp+60h] [ebp-4h]

  v42 = nullptr;
  UsageType = D3DXShader::CParse::GetUsageType(this);
  v41 = UsageType;
  D3DXShader::CNodeVariable::CNodeVariable(this: (D3DXShader::CNodeVariable *)v34);
  if ( UsageType == nullptr || a2 == nullptr )
    return nullptr;
  v6 = (*((_BYTE *)UsageType + 16) & 0x40) == 0;
  v43 = *((struct D3DXShader::CNode **)UsageType + 6);
  v46 = (struct D3DXShader::D3DXTOKEN *)(a2 + 4);
  if ( !v6 )
    D3DXShader::CParse::Error(
      this,
      a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
      a3: 0xBE7u,
      format: "'%s': functions cannot be declared 'uniform'",
      a2[6]);
  if ( (*((_BYTE *)UsageType + 16) & 1) != 0 )
    D3DXShader::CParse::Error(
      this,
      a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
      a3: 0xBBEu,
      format: "'%s': functions cannot be declared 'extern'",
      a2[6]);
  if ( !D3DXShader::CParse::IsNumeric(this, a2: v43) )
    D3DXShader::CParse::Error(
      this,
      a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
      a3: 0xBDEu,
      format: "'%s': function return value must be numeric",
      a2[6]);
  v44 = 0;
  for ( i = a3; i != nullptr; i = (struct D3DXShader::CNode **)i[3] )
  {
    v8 = i[2];
    if ( v8 != nullptr && *((_DWORD *)v8 + 1) == 6 )
    {
      v9 = i[3];
      if ( v9 != nullptr && *(_DWORD *)(*((_DWORD *)v9 + 2) + 4) == 12 )
      {
        v44 = 1;
        i = (struct D3DXShader::CNode **)v9;
      }
      else if ( v44 != 0 )
      {
        D3DXShader::CParse::Error(
          this,
          a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
          a3: 0xBE4u,
          format: "'%s': missing default value for parameter '%s'",
          a2[6],
          *(const char **)(*((_DWORD *)v8 + 5) + 24));
      }
    }
  }
  v10 = D3DXShader::CNode::operator new(a1: 0x14u);
  v44 = v10 != nullptr
      ? D3DXShader::CNodeList::CNodeList(this: (D3DXShader::CNodeList *)v10, a2: nullptr, a3: nullptr, a4: "Stmts")
      : 0;
  if ( v44 == 0 )
    return nullptr;
  v11 = D3DXShader::CNode::operator new(a1: 0x30u);
  if ( v11 != nullptr )
  {
    v12 = (struct D3DXShader::CNode *)D3DXShader::CNodeDecl::CNodeDecl(a1: v11, a2: 2, a3: 0, a4: 0, a5: 0);
    v45 = v12;
  }
  else
  {
    v45 = nullptr;
    v12 = nullptr;
  }
  if ( v12 == nullptr )
    return nullptr;
  *(_DWORD *)(v44 + 8) = v12;
  v13 = D3DXShader::CNode::Copy(a1: (struct D3DXShader::CNode *)a2);
  *((_DWORD *)v12 + 5) = v13;
  if ( v13 == nullptr )
    return nullptr;
  v14 = D3DXShader::CNode::operator new(a1: 0x40u);
  v15 = v14 != nullptr ? D3DXShader::CNodeFunction::CNodeFunction(this: (D3DXShader::CNodeFunction *)v14) : 0;
  if ( v15 == 0 )
    return nullptr;
  v16 = v41;
  *((_DWORD *)v12 + 6) = v15;
  *(_DWORD *)(v15 + 24) = *((_DWORD *)v16 + 4);
  v17 = *((struct D3DXShader::CNode **)v16 + 5);
  if ( v17 != nullptr )
  {
    v18 = D3DXShader::CNode::Copy(a1: v17);
    *(_DWORD *)(v15 + 28) = v18;
    if ( v18 == nullptr )
      return nullptr;
  }
  if ( v43 != nullptr )
  {
    v19 = D3DXShader::CNode::Copy(a1: v43);
    *(_DWORD *)(v15 + 32) = v19;
    if ( v19 == nullptr )
      return nullptr;
  }
  D3DXShader::CParse::MakeTypeConst(this, a2: *(struct D3DXShader::CNode ***)(v15 + 32), a3: 1);
  if ( a4 != nullptr )
  {
    if ( *(_DWORD *)(v15 + 32) == 0 )
    {
      D3DXShader::CParse::Error(
        this,
        a2: v46,
        a3: 0xC04u,
        format: "'%s': void function cannot have a semantic",
        *((const char **)v46 + 2));
      a4 = nullptr;
    }
    if ( a4 != nullptr )
    {
      v20 = D3DXShader::CNode::Copy(a1: (struct D3DXShader::CNode *)a4);
      *(_DWORD *)(v15 + 52) = v20;
      if ( v20 != nullptr )
      {
        while ( 1 )
        {
          v21 = a4[2];
          if ( v21 != nullptr && *((_DWORD *)v21 + 1) == 3 )
          {
            v22 = D3DXShader::CNode::Copy(a1: a4[2]);
            *(_DWORD *)(v15 + 48) = v22;
            if ( v22 == nullptr )
              break;
          }
          a4 = (struct D3DXShader::CNode **)a4[3];
          if ( a4 == nullptr )
            goto LABEL_45;
        }
      }
      return nullptr;
    }
  }
LABEL_45:
  if ( a3 != nullptr && a3[2] != nullptr )
  {
    v23 = D3DXShader::CNode::Copy(a1: (struct D3DXShader::CNode *)a3);
    *(_DWORD *)(v15 + 36) = v23;
    if ( v23 == nullptr )
      return nullptr;
  }
  Decl = D3DXShader::CParse::FindDecl(
           this,
           a2: 2,
           a3: (const char **)v46,
           a4: *(const char ***)(v15 + 28),
           a5: *(struct D3DXShader::CNode **)(v15 + 36),
           a6: *(struct D3DXShader::CNodeScope ***)(*((_DWORD *)this + 4) + 32),
           a7: 0xAu,
           a8: (int *)&a3,
           a9: &v42);
  if ( Decl < 0 )
  {
    D3DXShader::CParse::Error(this, a2: v46, a3: 0xBBBu, format: "redefinition of '%s'", *((_DWORD *)v46 + 2));
    return nullptr;
  }
  v26 = a3;
  if ( Decl != 0 )
  {
    v33 = *(struct D3DXShader::CNode **)(v15 + 32);
    *(_DWORD *)(v15 + 16) = *((_DWORD *)this + 22);
    v28 = D3DXShader::CParse::TypeSize(this, a2: v33);
    *(_DWORD *)(v15 + 20) = v28;
    *((_DWORD *)this + 22) += v28;
  }
  else
  {
    if ( !D3DXShader::CParse::IsTypeEqual(this, a2: *(struct D3DXShader::CNode **)(v15 + 32), a3: a3[8]) )
    {
      D3DXShader::CParse::Error(
        this,
        a2: v46,
        a3: 0xBFCu,
        format: "'%s': function return value differs from prototype",
        *((_DWORD *)v46 + 2));
      return nullptr;
    }
    v27 = v45;
    *(_DWORD *)(v15 + 16) = v26[4];
    *(_DWORD *)(v15 + 20) = v26[5];
    *((_DWORD *)v27 + 9) = *(_DWORD *)(v42[2] + 24);
  }
  v35 = *(_DWORD *)(v15 + 16);
  v29 = *(_DWORD *)(v15 + 20);
  v38 = 0;
  v36 = v29;
  v37 = 3;
  v39 = D3DXShader::CNode::Copy(a1: *(struct D3DXShader::CNode **)(v15 + 32));
  v40 = D3DXShader::CNode::Copy(a1: (struct D3DXShader::CNode *)a4);
  D3DXShader::CParse::MakeTypeConst(this, a2: (struct D3DXShader::CNode **)v39, a3: 0);
  *(_DWORD *)(v15 + 44) = D3DXShader::CParse::VariableExpr(
                            (struct D3DXShader::CNodeScope ***)this,
                            (struct D3DXShader::CNode *)a2,
                            a3: (struct D3DXShader::CNode *)v34);
  if ( v26 == nullptr )
  {
    v30 = *((_DWORD *)this + 4);
    v32 = v45;
    *((_DWORD *)this + 4) = *(_DWORD *)(v30 + 32);
    v31 = D3DXShader::CParse::AddDecl(this, a2: v32, a3: 0);
    *((_DWORD *)this + 4) = v30;
    if ( v31 < 0 )
      return nullptr;
    ++*((_DWORD *)this + 21);
  }
  *(_DWORD *)(*((_DWORD *)this + 4) + 20) = *((_DWORD *)v46 + 2);
  result = (struct D3DXShader::CNode *)v44;
  *((_DWORD *)this + 6) = v15;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FB633
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::Eval(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::Eval(D3DXShader::CParse *this, struct D3DXShader::CNode *a2)
{
  struct D3DXShader::_D3DXVALUE *v3; // eax
  unsigned __int8 *v4; // eax
  struct D3DXShader::CNode *v5; // ebx
  int v6; // eax
  int v7; // edi
  unsigned __int8 *v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // eax
  struct D3DXShader::_D3DXVALUE *pMem; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h]
  int v16; // [esp+14h] [ebp-4h]
  struct D3DXShader::_D3DXVALUE *v17; // [esp+20h] [ebp+8h]

  if ( a2 != nullptr && *((_DWORD *)a2 + 1) == 13 )
  {
    v15 = *((_DWORD *)a2 + 5) * *((_DWORD *)a2 + 6);
    v3 = (struct D3DXShader::_D3DXVALUE *)MemAlloc_Alloc(nSize: 16 * v15);
    pMem = v3;
    if ( v3 != nullptr && D3DXShader::CParse::Eval(this, a2, a3: v3) >= 0 )
    {
      v4 = D3DXShader::CNode::operator new(a1: 0x50u);
      v5 = v4 != nullptr
         ? (struct D3DXShader::CNode *)D3DXShader::CNodeExpression::CNodeExpression(
                                         a1: v4,
                                         a2: 0,
                                         a3: 0,
                                         a4: 0,
                                         a5: 0,
                                         a6: 1,
                                         a7: (char *)a2 + 48)
         : nullptr;
      if ( v5 != nullptr )
      {
        if ( *((_DWORD *)a2 + 4) == 0
          || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)a2 + 4) + 4))(a1: *((_DWORD *)a2 + 4)),
              *((_DWORD *)v5 + 4) = v6,
              v6 != 0) )
        {
          v16 = 0;
          v7 = (int)v5 + 32;
          if ( v15 == 0 )
          {
LABEL_22:
            D3DXShader::CParse::ComputeExprSize(this, a2: v5);
LABEL_24:
            free(pMem);
            return v5;
          }
          v17 = pMem;
          while ( 1 )
          {
            v8 = D3DXShader::CNode::operator new(a1: 0x14u);
            v9 = v8 != nullptr
               ? D3DXShader::CNodeList::CNodeList(
                   this: (D3DXShader::CNodeList *)v8,
                   a2: nullptr,
                   a3: nullptr,
                   a4: "Value")
               : 0;
            *(_DWORD *)v7 = v9;
            if ( v9 == 0 )
              break;
            v10 = D3DXShader::CNode::operator new(a1: 0x40u);
            v11 = v10 != nullptr
                ? D3DXShader::CNodeValue::CNodeValue(
                    this: (D3DXShader::CNodeValue *)v10,
                    a2: v17,
                    a3: (struct D3DXShader::CNode *)((char *)a2 + 48))
                : 0;
            *(_DWORD *)(*(_DWORD *)v7 + 8) = v11;
            if ( v11 == 0 )
              break;
            v17 = (struct D3DXShader::_D3DXVALUE *)((char *)v17 + 16);
            v7 = *(_DWORD *)v7 + 12;
            if ( ++v16 >= v15 )
              goto LABEL_22;
          }
        }
      }
    }
    v5 = nullptr;
    goto LABEL_24;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FB75E
// Name: protected: long D3DXShader::CParse::EvalUint(class D3DXShader::CNode __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::EvalUint(D3DXShader::CParse *this, struct D3DXShader::CNode *a2, unsigned int *a3)
{
  struct D3DXShader::CNode *v4; // eax
  struct D3DXShader::CNode *v5; // edx
  int v6; // eax
  int v7; // edx
  int result; // eax

  v4 = D3DXShader::CParse::Eval(this, a2);
  v5 = v4;
  if ( v4 == nullptr )
    return -2147467259;
  v6 = *((_DWORD *)v4 + 4);
  if ( v6 == 0
    || *(_DWORD *)(v6 + 4) != 9
    || !D3DXShader::CParse::IsScalar(this, a2: *((struct D3DXShader::CNode **)v5 + 4)) )
  {
    return -2147467259;
  }
  result = D3DXShader::CParse::CastToUint(
             this,
             a2: a3,
             a3: (struct D3DXShader::_D3DXVALUE *)(*(_DWORD *)(*(_DWORD *)(v7 + 32) + 8) + 16),
             a4: (struct D3DXShader::D3DXTOKEN *)(v7 + 48));
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FB7B7
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::TypeDecl(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::TypeDecl(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  int *v3; // edi
  unsigned __int8 *v4; // eax
  int v5; // eax
  unsigned __int8 *v6; // eax
  struct D3DXShader::CNode *v7; // ebx
  struct D3DXShader::CNode *v8; // eax
  struct D3DXShader::CNode *v9; // edi
  unsigned __int8 *v10; // eax
  int v11; // eax
  struct D3DXShader::CNode *v12; // ecx
  _DWORD *v13; // esi
  struct D3DXShader::CNode *v14; // eax
  struct D3DXShader::D3DXTOKEN *v15; // edi
  int v17; // [esp+Ch] [ebp-14h]
  int v18; // [esp+10h] [ebp-10h] BYREF
  int v19; // [esp+14h] [ebp-Ch]
  unsigned int v20; // [esp+18h] [ebp-8h]
  D3DXShader::CParse *v21; // [esp+1Ch] [ebp-4h]

  v21 = this;
  v18 = 0;
  v3 = &v18;
  if ( a3 != nullptr )
  {
    while ( 1 )
    {
      if ( *((_DWORD *)a3 + 2) == 0 )
        return nullptr;
      v4 = D3DXShader::CNode::operator new(a1: 0x14u);
      v5 = v4 != nullptr
         ? D3DXShader::CNodeList::CNodeList(this: (D3DXShader::CNodeList *)v4, a2: nullptr, a3: nullptr, a4: "Stmts")
         : 0;
      *v3 = v5;
      if ( v5 == 0 )
        return nullptr;
      v6 = D3DXShader::CNode::operator new(a1: 0x30u);
      v7 = v6 != nullptr
         ? (struct D3DXShader::CNode *)D3DXShader::CNodeDecl::CNodeDecl(a1: v6, a2: 0, a3: 0, a4: 0, a5: 0)
         : nullptr;
      if ( v7 == nullptr )
        return nullptr;
      *(_DWORD *)(*v3 + 8) = v7;
      v17 = *v3 + 12;
      v20 = 1;
      v19 = 0;
      if ( a2 != nullptr )
      {
        v8 = D3DXShader::CNode::Copy(a1: a2);
        *((_DWORD *)v7 + 6) = v8;
        if ( v8 == nullptr )
          return nullptr;
      }
      v9 = *((struct D3DXShader::CNode **)a3 + 2);
      while ( *((_DWORD *)v9 + 1) != 3 )
      {
        v10 = D3DXShader::CNode::operator new(a1: 0x18u);
        if ( v10 != nullptr )
          v11 = D3DXShader::CNodeArray::CNodeArray(this: (D3DXShader::CNodeArray *)v10);
        else
          v11 = 0;
        if ( v11 == 0 )
          return nullptr;
        *(_DWORD *)(v11 + 16) = *((_DWORD *)v7 + 6);
        *((_DWORD *)v7 + 6) = v11;
        v12 = *((struct D3DXShader::CNode **)v9 + 3);
        v13 = (_DWORD *)(v11 + 20);
        if ( v12 != nullptr )
        {
          if ( D3DXShader::CParse::EvalUint(this: v21, a2: v12, a3: (unsigned int *)(v11 + 20)) >= 0 )
            goto LABEL_25;
          v19 = 3058;
        }
        else
        {
          v19 = 3072;
        }
        *v13 = 1;
LABEL_25:
        v9 = *((struct D3DXShader::CNode **)v9 + 2);
        v20 *= *v13;
      }
      v14 = D3DXShader::CNode::Copy(a1: v9);
      *((_DWORD *)v7 + 5) = v14;
      if ( v14 == nullptr )
        return nullptr;
      v15 = (struct D3DXShader::CNode *)((char *)v9 + 16);
      if ( v19 == 3058 )
      {
        D3DXShader::CParse::Error(
          this: v21,
          a2: v15,
          a3: 0xBF2u,
          format: "'%s': array dimensions must be literal scalar expressions",
          *((_DWORD *)v15 + 2));
        return nullptr;
      }
      if ( v19 == 3072 )
      {
        D3DXShader::CParse::Error(
          this: v21,
          a2: v15,
          a3: 0xC00u,
          format: "'%s': array dimensions of type must be explicit",
          *((_DWORD *)v15 + 2));
        return nullptr;
      }
      if ( v20 == 0 || v20 > 0x10000 )
      {
        D3DXShader::CParse::Error(
          this: v21,
          a2: v15,
          a3: 0xBF3u,
          format: "'%s': array dimension must be between 1 and 65536",
          *((_DWORD *)v15 + 2));
        return nullptr;
      }
      if ( D3DXShader::CParse::AddDecl(this: v21, a2: v7, a3: 1) < 0 )
        return nullptr;
      a3 = *((struct D3DXShader::CNode **)a3 + 3);
      if ( a3 == nullptr )
        return (struct D3DXShader::CNode *)v18;
      v3 = (int *)v17;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FB967
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::StructDecl(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::StructDecl(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  unsigned __int8 *v4; // eax
  struct D3DXShader::CNode *v5; // esi
  struct D3DXShader::CNode *result; // eax

  v4 = D3DXShader::CNode::operator new(a1: 0x14u);
  if ( v4 != nullptr )
    v5 = (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                       this: (D3DXShader::CNodeList *)v4,
                                       a2: a3,
                                       a3: nullptr,
                                       a4: "Ids");
  else
    v5 = nullptr;
  if ( v5 == nullptr )
    return nullptr;
  result = D3DXShader::CParse::TypeDecl(this, a2, a3: v5);
  *((_DWORD *)v5 + 2) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FB9AF
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::VectorType(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::VectorType(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  struct D3DXShader::CNode *v3; // esi
  unsigned __int8 *v5; // eax

  v3 = a2;
  if ( a2 != nullptr )
  {
    if ( D3DXShader::CParse::EvalUint(this, a2: a3, a3: (unsigned int *)&a2) >= 0 )
    {
      if ( a2 != nullptr && (unsigned int)a2 <= 4 )
      {
        v5 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v5 != nullptr )
          return (struct D3DXShader::CNode *)D3DXShader::CNodeType::CNodeType(
                                               a1: v5,
                                               a2: 1,
                                               a3: *((_DWORD *)v3 + 5),
                                               a4: 1,
                                               a5: a2,
                                               a6: 0);
      }
      else
      {
        D3DXShader::CParse::Error(
          this,
          a2: (D3DXShader::CParse *)((char *)this + 32),
          a3: 0xBECu,
          format: "vector dimension must be between 1 and %u",
          4);
      }
    }
    else
    {
      D3DXShader::CParse::Error(
        this,
        a2: (D3DXShader::CParse *)((char *)this + 32),
        a3: 0xBF4u,
        format: "vector dimension must be a literal scalar expression");
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FBA35
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::MatrixType(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::MatrixType(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4)
{
  struct D3DXShader::CNode *v4; // edi
  unsigned __int8 *v6; // eax

  v4 = a2;
  if ( a2 != nullptr )
  {
    if ( D3DXShader::CParse::EvalUint(this, a2: a3, (unsigned int *)&a3) < 0
      || D3DXShader::CParse::EvalUint(this, a2: a4, a3: (unsigned int *)&a2) < 0 )
    {
      D3DXShader::CParse::Error(
        this,
        a2: (D3DXShader::CParse *)((char *)this + 32),
        a3: 0xBF5u,
        format: "matrix dimensions must be literal scalar expressions");
    }
    else if ( a3 != nullptr && (unsigned int)a3 <= 4 && a2 != nullptr && (unsigned int)a2 <= 4 )
    {
      v6 = D3DXShader::CNode::operator new(a1: 0x24u);
      if ( v6 != nullptr )
        return (struct D3DXShader::CNode *)D3DXShader::CNodeType::CNodeType(
                                             a1: v6,
                                             a2: 2,
                                             a3: *((_DWORD *)v4 + 5),
                                             a4: a3,
                                             a5: a2,
                                             a6: 0);
    }
    else
    {
      D3DXShader::CParse::Error(
        this,
        a2: (D3DXShader::CParse *)((char *)this + 32),
        a3: 0xBEDu,
        format: "matrix dimensions must be between 1 and %u",
        4);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FBADE
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::TypeDim(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::TypeDim(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  unsigned __int8 *v4; // eax
  struct D3DXShader::CNode *v5; // eax
  struct D3DXShader::CNode **v7; // ecx
  struct D3DXShader::CNode *v8; // edx

  if ( D3DXShader::CParse::EvalUint(this, a2: a3, (unsigned int *)&a3) < 0 )
  {
    D3DXShader::CParse::Error(
      this,
      a2: nullptr,
      a3: 0xBF2u,
      format: "array dimensions must be literal scalar expressions");
    return nullptr;
  }
  v4 = D3DXShader::CNode::operator new(a1: 0x18u);
  if ( v4 != nullptr )
    v5 = (struct D3DXShader::CNode *)D3DXShader::CNodeArray::CNodeArray(
                                       this: (D3DXShader::CNodeArray *)v4,
                                       a2: nullptr,
                                       (unsigned int)a3);
  else
    v5 = nullptr;
  if ( v5 == nullptr )
    return nullptr;
  v7 = &a2;
  if ( a2 != nullptr )
  {
    do
    {
      v8 = *v7;
      if ( *((_DWORD *)*v7 + 1) != 8 )
        break;
      v7 = (struct D3DXShader::CNode **)((char *)v8 + 16);
    }
    while ( *((_DWORD *)v8 + 4) != 0 );
  }
  *((_DWORD *)v5 + 4) = *v7;
  *v7 = v5;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x101FBB57
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::ArrayExpr(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::ArrayExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  char *v3; // edi
  unsigned __int8 *v4; // eax
  int v5; // edi
  _DWORD *v6; // esi
  int v7; // eax
  int v8; // eax
  unsigned int v9; // esi
  unsigned __int8 *v10; // eax
  int v11; // eax
  unsigned __int8 *v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // esi
  unsigned __int8 *v16; // eax
  int v17; // eax
  struct D3DXShader::CNode *v18; // eax
  struct D3DXShader::CNode *v20; // [esp+Ch] [ebp-Ch]
  struct D3DXShader::D3DXTOKEN *v22; // [esp+14h] [ebp-4h]

  if ( a2 == nullptr || *((_DWORD *)a2 + 1) != 13 || a3 == nullptr || *((_DWORD *)a3 + 1) != 13 )
    return nullptr;
  v3 = (char *)a3 + 48;
  v22 = (struct D3DXShader::CNode *)((char *)a3 + 48);
  v4 = D3DXShader::CNode::operator new(a1: 0x50u);
  v5 = v4 != nullptr
     ? D3DXShader::CNodeExpression::CNodeExpression(a1: v4, a2: 0, a3: 22, a4: 0, a5: 0, a6: 1, a7: v3)
     : 0;
  if ( v5 == 0 )
    return nullptr;
  v6 = *((_DWORD **)a2 + 4);
  v20 = *((struct D3DXShader::CNode **)a3 + 4);
  if ( v6 == nullptr )
    goto LABEL_41;
  v7 = v6[1];
  if ( v7 != 8 )
  {
    if ( v7 == 9 )
    {
      if ( v6[4] == 1 )
      {
        v10 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v10 != nullptr )
          v11 = D3DXShader::CNodeType::CNodeType(a1: v10, a2: 0, a3: v6[5], a4: 1, a5: 1, a6: v6[8] & 0x200);
        else
          v11 = 0;
        *(_DWORD *)(v5 + 16) = v11;
        if ( v11 == 0 )
          return nullptr;
        v9 = v6[7];
        goto LABEL_27;
      }
      if ( v6[4] == 2 )
      {
        v12 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v12 != nullptr )
          v13 = D3DXShader::CNodeType::CNodeType(a1: v12, a2: 1, a3: v6[5], a4: 1, a5: v6[7], a6: v6[8] & 0x200);
        else
          v13 = 0;
        *(_DWORD *)(v5 + 16) = v13;
        if ( v13 == 0 )
          return nullptr;
        v9 = v6[6];
        goto LABEL_27;
      }
    }
LABEL_41:
    D3DXShader::CParse::Error(this, a2: v22, a3: 0xBCDu, format: "array expected");
    return nullptr;
  }
  if ( v6[4] != 0 )
  {
    v8 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v6[4] + 4))(a1: v6[4]);
    *(_DWORD *)(v5 + 16) = v8;
    if ( v8 == 0 )
      return nullptr;
  }
  v9 = v6[5];
LABEL_27:
  if ( D3DXShader::CParse::IsScalar(this, a2: v20) )
  {
    v14 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a2 + 4))(a1: a2);
    *(_DWORD *)(v5 + 32) = v14;
    if ( v14 != 0 )
    {
      if ( D3DXShader::CParse::IsFullyLiteral(this, a2: a3) )
      {
        if ( D3DXShader::CParse::EvalUint(this, a2: a3, (unsigned int *)&a3) < 0 )
          return nullptr;
        if ( (unsigned int)a3 >= v9 )
        {
          D3DXShader::CParse::Error(this, a2: v22, a3: 0xBD6u, format: "array index out of bounds");
          a3 = nullptr;
        }
        v15 = D3DXShader::CParse::TypeSize(this, a2: *(struct D3DXShader::CNode **)(v5 + 16));
        v16 = D3DXShader::CNode::operator new(a1: 0x40u);
        v17 = v16 != nullptr ? D3DXShader::CNodeValue::CNodeValue(a1: v16, a2: 2, a3: (_DWORD)a3 * v15, a4: v22) : 0;
        *(_DWORD *)(v5 + 36) = v17;
        if ( v17 == 0 )
          return nullptr;
        *(_DWORD *)(v5 + 28) = 23;
      }
      else
      {
        v18 = D3DXShader::CNode::Copy(a1: a3);
        *(_DWORD *)(v5 + 36) = v18;
        if ( v18 == nullptr )
          return nullptr;
      }
      D3DXShader::CParse::ComputeExprSize(this, a2: (struct D3DXShader::CNode *)v5);
      return (struct D3DXShader::CNode *)v5;
    }
  }
  else
  {
    D3DXShader::CParse::Error(this, a2: v22, a3: 0xBEBu, format: "scalar expected");
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FBD81
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::Expr(enum D3DXShader::_D3DXEXPR_OP,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::Expr(
        D3DXShader::CParse *this,
        unsigned int a2,
        struct D3DXShader::D3DXTOKEN *a3,
        _DWORD *a4,
        int a5)
{
  struct D3DXShader::D3DXTOKEN *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned int v9; // edi
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  struct D3DXShader::CNode *v15; // eax
  struct D3DXShader::CNode *v16; // ebx
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  struct D3DXShader::CNode **v23; // edx
  struct D3DXShader::CNode *v24; // eax
  struct D3DXShader::CNode **v25; // edx
  struct D3DXShader::CNode *v26; // eax
  struct D3DXShader::CNode *v27; // eax
  int v28; // [esp-8h] [ebp-24h]
  struct D3DXShader::CNode *v29; // [esp+8h] [ebp-14h] BYREF
  struct D3DXShader::CNode *v30; // [esp+Ch] [ebp-10h]
  struct D3DXShader::CNode *v31; // [esp+10h] [ebp-Ch] BYREF
  struct D3DXShader::CNode *v32; // [esp+14h] [ebp-8h]
  D3DXShader::CParse *v33; // [esp+18h] [ebp-4h]
  struct D3DXShader::D3DXTOKEN *v34; // [esp+28h] [ebp+Ch]

  v33 = this;
  v30 = nullptr;
  v29 = nullptr;
  v32 = nullptr;
  v31 = nullptr;
  if ( a3 != nullptr && *((_DWORD *)a3 + 1) != 13 )
    return nullptr;
  if ( a4 != nullptr )
  {
    if ( a4[1] != 13 )
      return nullptr;
    v7 = (struct D3DXShader::D3DXTOKEN *)(a4 + 12);
    goto LABEL_7;
  }
  if ( a3 != nullptr )
  {
    v7 = (struct D3DXShader::D3DXTOKEN *)((char *)a3 + 48);
LABEL_7:
    v34 = v7;
    goto LABEL_11;
  }
  v34 = (D3DXShader::CParse *)((char *)this + 32);
LABEL_11:
  v8 = D3DXShader::CNode::operator new(a1: 0x50u);
  v9 = a2;
  if ( v8 != nullptr )
    v10 = D3DXShader::CNodeExpression::CNodeExpression(a1: v8, a2: 0, a3: a2, a4: 0, a5: 0, a6: a5, a7: v34);
  else
    v10 = 0;
  if ( v10 == 0 )
    return nullptr;
  if ( a3 != nullptr )
  {
    v11 = (*(int (__thiscall **)(struct D3DXShader::D3DXTOKEN *))(*(_DWORD *)a3 + 4))(a1: a3);
    *(_DWORD *)(v10 + 32) = v11;
    if ( v11 == 0 )
      return nullptr;
  }
  if ( a2 != 28 && a2 != 29 && a2 != 30 && a2 != 31 && a2 != 32 && a2 != 33 && a2 != 34 )
  {
    if ( a4 != nullptr )
    {
      v12 = (*(int (__thiscall **)(_DWORD *))(*a4 + 4))(a1: a4);
      *(_DWORD *)(v10 + 36) = v12;
      if ( v12 == 0 )
        return nullptr;
    }
LABEL_44:
    v14 = *(_DWORD *)(v10 + 32);
    if ( v14 != 0 )
    {
      v15 = *(struct D3DXShader::CNode **)(v14 + 16);
      v30 = v15;
      v29 = v15;
    }
    else
    {
      v15 = v30;
    }
    if ( v9 >= 2
      && v9 != 20
      && v9 != 21
      && v9 != 16
      && v9 != 17
      && (v15 == nullptr || *((_DWORD *)v30 + 1) != 9 || !D3DXShader::CParse::IsNumeric(this: v33, a2: v30)) )
    {
      D3DXShader::CParse::Error(this: v33, a2: v34, a3: 0xBCEu, format: "scalar, vector, or matrix expected");
      return nullptr;
    }
    if ( v9 == 2 || v9 == 3 || v9 == 20 || v9 == 21 )
    {
      v16 = v30;
      if ( D3DXShader::CParse::IsConst(this: v33, a2: v30) != 0
        || D3DXShader::CParse::IsPartiallyLiteral(this: v33, a2: *(struct D3DXShader::CNode **)(v10 + 32)) )
      {
        D3DXShader::CParse::Error(this: v33, a2: v34, a3: 0xBD1u, format: "l-value specifies const object");
        return nullptr;
      }
      v18 = *(_DWORD *)(*(_DWORD *)(v17 + 16) + 16);
      if ( (v18 == 3 || v18 == 4) && !D3DXShader::CParse::IsNumeric(this: v33, a2: v30) )
      {
        D3DXShader::CParse::Error(
          this: v33,
          a2: v34,
          a3: 0xBF9u,
          format: "object assignments are not allowed inside functions");
        return nullptr;
      }
    }
    else
    {
      v16 = v30;
    }
    v19 = *(_DWORD *)(v10 + 36);
    if ( v19 != 0 )
    {
      v32 = *(struct D3DXShader::CNode **)(v19 + 16);
      v31 = v32;
    }
    if ( v9 == 20 || v9 == 21 )
    {
      if ( !D3DXShader::CParse::IsSupportedCast(this: v33, a2: v16, a3: v32, a4: 0) )
      {
        D3DXShader::CParse::ErrorUnsupportedCast(this: v33, a2: v34, a3: nullptr, a4: v16, a5: v32, a6: 0);
        return nullptr;
      }
      if ( v16 != nullptr )
      {
        v22 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)v16 + 4))(a1: v16);
        *(_DWORD *)(v10 + 16) = v22;
        if ( v22 == 0 )
          return nullptr;
      }
      v31 = v16;
    }
    else if ( v9 != 0 )
    {
      if ( v9 != 4 && v9 != 5 && v9 != 6 && v9 != 2 && v9 != 3 && v9 != 1 )
      {
        if ( v9 == 12 || v9 == 13 || v9 == 14 || v9 == 15 || v9 == 16 || v9 == 17 || v9 == 18 || v9 == 19 )
        {
          if ( D3DXShader::CParse::BinaryType(
                 this: v33,
                 a2: v16,
                 a3: v32,
                 a4: &v29,
                 a5: &v31,
                 a6: (struct D3DXShader::CNode **)(v10 + 16)) >= 0 )
          {
            *(_DWORD *)(*(_DWORD *)(v10 + 16) + 20) = 0;
            goto LABEL_102;
          }
        }
        else if ( D3DXShader::CParse::BinaryType(
                    this: v33,
                    a2: v16,
                    a3: v32,
                    a4: &v29,
                    a5: &v31,
                    a6: (struct D3DXShader::CNode **)(v10 + 16)) >= 0 )
        {
          goto LABEL_102;
        }
        D3DXShader::CParse::Error(this: v33, a2: v34, a3: 0xBCCu, format: "type mismatch");
        return nullptr;
      }
      if ( v16 != nullptr )
      {
        v21 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)v16 + 4))(a1: v16);
        *(_DWORD *)(v10 + 16) = v21;
        if ( v21 == 0 )
          return nullptr;
      }
      D3DXShader::CParse::MakeTypeConst(this: v33, a2: *(struct D3DXShader::CNode ***)(v10 + 16), a3: 1);
    }
    else if ( v16 != nullptr )
    {
      v20 = (*(int (__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)v16 + 4))(a1: v16);
      *(_DWORD *)(v10 + 16) = v20;
      if ( v20 == 0 )
        return nullptr;
    }
LABEL_102:
    if ( *(_DWORD *)(v10 + 32) != 0 && v16 != v29 && !D3DXShader::CParse::IsTypeEqual(this: v33, a2: v16, a3: v29) )
    {
      v24 = D3DXShader::CParse::CastExpr(
              this: (struct D3DXShader::CNodeScope ***)v33,
              a2: (const char **)v29,
              a3: v23,
              a4: 0,
              a5: 0);
      if ( v24 == nullptr )
        return nullptr;
      *(_DWORD *)(v10 + 32) = v24;
    }
    if ( *(_DWORD *)(v10 + 36) != 0 && v32 != v31 && !D3DXShader::CParse::IsTypeEqual(this: v33, a2: v32, a3: v31) )
    {
      v26 = D3DXShader::CParse::CastExpr(
              this: (struct D3DXShader::CNodeScope ***)v33,
              a2: (const char **)v31,
              a3: v25,
              a4: 0,
              a5: 0);
      if ( v26 == nullptr )
        return nullptr;
      *(_DWORD *)(v10 + 36) = v26;
    }
    if ( *(_DWORD *)(v10 + 16) == 0 )
      *(_DWORD *)(v10 + 16) = 0;
    D3DXShader::CParse::ComputeExprSize(this: v33, a2: (struct D3DXShader::CNode *)v10);
    if ( D3DXShader::CParse::IsFullyLiteral(this: v33, a2: (struct D3DXShader::CNode *)v10) )
    {
      v27 = D3DXShader::CParse::Eval(this: v33, a2: (struct D3DXShader::CNode *)v10);
      if ( v27 != nullptr )
        return v27;
    }
    return (struct D3DXShader::CNode *)v10;
  }
  switch ( a2 )
  {
    case 0x1Cu:
      v28 = 7;
      goto LABEL_41;
    case 0x1Du:
      v28 = 8;
      goto LABEL_41;
    case 0x1Eu:
      v28 = 9;
      goto LABEL_41;
    case 0x1Fu:
      v28 = 10;
      goto LABEL_41;
    case 0x20u:
      v28 = 11;
LABEL_41:
      v9 = 21;
      goto LABEL_42;
    default:
      break;
  }
  v9 = 1;
  if ( a2 == 33 )
    v28 = 2;
  else
    v28 = 3;
LABEL_42:
  v13 = D3DXShader::CParse::Expr(a1: v33, a2: v28, a3, a4, a5: 0);
  *(_DWORD *)(v10 + 36) = v13;
  if ( v13 != 0 )
  {
    *(_DWORD *)(v10 + 28) = v9;
    goto LABEL_44;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FC19A
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::ReturnStmt(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::ReturnStmt(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2)
{
  unsigned __int8 *v4; // eax
  struct D3DXShader::CNode *v5; // edi
  int v6; // eax
  unsigned __int8 *v7; // eax

  if ( *((_DWORD *)this + 6) == 0 )
    return nullptr;
  v4 = D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v4 != nullptr )
    v5 = (struct D3DXShader::CNode *)D3DXShader::CNodeStatement::CNodeStatement(this: (D3DXShader::CNodeStatement *)v4);
  else
    v5 = nullptr;
  if ( v5 == nullptr )
    return nullptr;
  *((_DWORD *)v5 + 4) = 1;
  v6 = *((_DWORD *)this + 6);
  if ( a2 != nullptr )
  {
    if ( *(_DWORD *)(v6 + 32) != 0 )
      *((_DWORD *)v5 + 5) = D3DXShader::CParse::Expr(
                              this,
                              a2: 0x15u,
                              a3: *(struct D3DXShader::D3DXTOKEN **)(v6 + 44),
                              a4: a2,
                              a5: 1);
    else
      D3DXShader::CParse::Error(
        this,
        a2: (D3DXShader::CParse *)((char *)this + 32),
        a3: 0xC07u,
        format: "'%s': void functions cannot return a value",
        *(_DWORD *)(*((_DWORD *)this + 4) + 20));
  }
  else if ( *(_DWORD *)(v6 + 32) != 0 )
  {
    D3DXShader::CParse::Error(
      this,
      a2: (D3DXShader::CParse *)((char *)this + 32),
      a3: 0xC08u,
      format: "'%s': function must return a value",
      *(_DWORD *)(*((_DWORD *)this + 4) + 20));
  }
  v7 = D3DXShader::CNode::operator new(a1: 0x14u);
  if ( v7 != nullptr )
    return (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                         this: (D3DXShader::CNodeList *)v7,
                                         a2: v5,
                                         a3: nullptr,
                                         a4: "Stmts");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FC24E
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::VariableDecl(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::VariableDecl(
        D3DXShader::CParse *this,
        const char **a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4,
        struct D3DXShader::CNode *a5)
{
  struct D3DXShader::CNode *UsageType; // eax
  int v6; // ecx
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  struct D3DXShader::CNode *v9; // edi
  unsigned __int8 *v10; // eax
  int v11; // esi
  struct D3DXShader::CNode *v12; // eax
  struct D3DXShader::CNode *v13; // ebx
  struct D3DXShader::CNode *v14; // eax
  int v15; // eax
  struct D3DXShader::CNode *v16; // eax
  struct D3DXShader::CNode *v17; // eax
  unsigned __int8 *v18; // eax
  int v19; // ebx
  struct D3DXShader::CNode *v20; // eax
  _DWORD *v21; // edi
  struct D3DXShader::CNode *v22; // eax
  unsigned int v23; // ebx
  struct D3DXShader::D3DXTOKEN *v24; // edi
  int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // et2
  int v29; // eax
  D3DXShader::CParse *v30; // ecx
  D3DXShader::CParse *v31; // ecx
  struct D3DXShader::CNode *v32; // eax
  struct D3DXShader::CNode **v33; // eax
  struct D3DXShader::CNode *v34; // eax
  struct D3DXShader::CNode *v35; // eax
  struct D3DXShader::CNodeScope ***v36; // ecx
  struct D3DXShader::CNode *v37; // eax
  struct D3DXShader::CNode *v38; // eax
  _DWORD v40[6]; // [esp+18h] [ebp-48h]
  _DWORD v41[6]; // [esp+30h] [ebp-30h]
  struct D3DXShader::CNode *v42; // [esp+48h] [ebp-18h]
  struct D3DXShader::CNode *v43; // [esp+4Ch] [ebp-14h]
  int v44; // [esp+50h] [ebp-10h]
  int v45; // [esp+54h] [ebp-Ch]
  struct D3DXShader::CNode *v46; // [esp+58h] [ebp-8h]
  D3DXShader::CParse *v47; // [esp+5Ch] [ebp-4h]
  struct D3DXShader::CNode *v48; // [esp+6Ch] [ebp+Ch]
  struct D3DXShader::CNode **v49; // [esp+6Ch] [ebp+Ch]
  struct D3DXShader::CNode *v50; // [esp+6Ch] [ebp+Ch]
  unsigned int v51; // [esp+70h] [ebp+10h]
  unsigned int v52; // [esp+70h] [ebp+10h]
  struct D3DXShader::CNode *v53; // [esp+70h] [ebp+10h]
  struct D3DXShader::CNode *v54; // [esp+74h] [ebp+14h]
  struct D3DXShader::CNode *v55; // [esp+74h] [ebp+14h]
  struct D3DXShader::CNode *v56; // [esp+74h] [ebp+14h]

  v47 = this;
  v41[0] = "global variables";
  v41[1] = "structure members";
  v41[2] = "function parameters";
  v41[3] = "local variables";
  v41[4] = "loop control variables";
  v41[5] = "annotation members";
  v40[0] = "initial value";
  v40[1] = "initializer";
  v40[2] = "default value";
  v40[3] = "initial value";
  v40[4] = "initial value";
  v40[5] = "value";
  UsageType = D3DXShader::CParse::GetUsageType(this);
  v42 = UsageType;
  if ( UsageType != nullptr && *(_DWORD *)(v6 + 16) != 0 && a2 != nullptr )
  {
    v43 = *((struct D3DXShader::CNode **)UsageType + 6);
    v7 = D3DXShader::CNode::operator new(a1: 0x14u);
    v45 = v7 != nullptr
        ? D3DXShader::CNodeList::CNodeList(this: (D3DXShader::CNodeList *)v7, a2: nullptr, a3: nullptr, a4: "Stmts")
        : 0;
    if ( v45 != 0 )
    {
      v8 = D3DXShader::CNode::operator new(a1: 0x30u);
      v9 = v8 != nullptr
         ? (struct D3DXShader::CNode *)D3DXShader::CNodeDecl::CNodeDecl(a1: v8, a2: 1, a3: 0, a4: 0, a5: 0)
         : nullptr;
      v46 = v9;
      if ( v9 != nullptr )
      {
        *(_DWORD *)(v45 + 8) = v9;
        v10 = D3DXShader::CNode::operator new(a1: 0x40u);
        v11 = v10 != nullptr ? D3DXShader::CNodeVariable::CNodeVariable(this: (D3DXShader::CNodeVariable *)v10) : 0;
        if ( v11 != 0 )
        {
          *((_DWORD *)v9 + 6) = v11;
          if ( a4 == nullptr || (v12 = D3DXShader::CNode::Copy(a1: a4), *((_DWORD *)v9 + 7) = v12, v12 != nullptr) )
          {
            v13 = a3;
            if ( a3 != nullptr )
            {
              v14 = D3DXShader::CNode::Copy(a1: a3);
              *(_DWORD *)(v11 + 48) = v14;
              if ( v14 != nullptr )
              {
                while ( 1 )
                {
                  v15 = *((_DWORD *)v13 + 2);
                  if ( v15 != 0 && *(_DWORD *)(v15 + 4) == 3 )
                  {
                    v16 = D3DXShader::CNode::Copy(a1: *((struct D3DXShader::CNode **)v13 + 2));
                    *(_DWORD *)(v11 + 44) = v16;
                    if ( v16 == nullptr )
                      break;
                  }
                  v13 = *((struct D3DXShader::CNode **)v13 + 3);
                  if ( v13 == nullptr )
                    goto LABEL_24;
                }
              }
              return nullptr;
            }
LABEL_24:
            if ( a5 != nullptr && *((_DWORD *)a5 + 1) != 13 )
              *(_DWORD *)(v11 + 36) = D3DXShader::CParse::InitExpr(this: v47, (struct D3DXShader::CNode *)a2, a3: a5);
            v51 = 1;
            v48 = nullptr;
            v44 = 0;
            if ( v43 == nullptr || (v17 = D3DXShader::CNode::Copy(a1: v43), *(_DWORD *)(v11 + 32) = v17, v17 != nullptr) )
            {
              if ( a2[1] != (const char *)3 )
              {
                while ( 1 )
                {
                  v18 = D3DXShader::CNode::operator new(a1: 0x18u);
                  if ( v18 != nullptr )
                    v19 = D3DXShader::CNodeArray::CNodeArray(this: (D3DXShader::CNodeArray *)v18);
                  else
                    v19 = 0;
                  if ( v19 == 0 )
                    return nullptr;
                  if ( v48 != nullptr )
                    v44 = 3073;
                  *(_DWORD *)(v19 + 16) = *(_DWORD *)(v11 + 32);
                  v20 = (struct D3DXShader::CNode *)a2[3];
                  v21 = (_DWORD *)(v19 + 20);
                  if ( v20 == nullptr )
                    break;
                  if ( D3DXShader::CParse::EvalUint(this: v47, a2: v20, a3: (unsigned int *)(v19 + 20)) < 0 )
                  {
                    v44 = 3058;
LABEL_40:
                    *v21 = 1;
                  }
                  v51 *= *v21;
                  *(_DWORD *)(v11 + 32) = v19;
                  a2 = (const char **)a2[2];
                  if ( a2[1] == (const char *)3 )
                  {
                    v9 = v46;
                    goto LABEL_43;
                  }
                }
                v48 = (struct D3DXShader::CNode *)(v19 + 20);
                goto LABEL_40;
              }
LABEL_43:
              v22 = D3DXShader::CNode::Copy(a1: (struct D3DXShader::CNode *)a2);
              *((_DWORD *)v9 + 5) = v22;
              if ( v22 != nullptr )
              {
                v23 = *(_DWORD *)(*((_DWORD *)v47 + 4) + 16);
                v24 = (struct D3DXShader::D3DXTOKEN *)(a2 + 4);
                if ( v44 == 3058 )
                {
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: v24,
                    a3: 0xBF2u,
                    format: "'%s': array dimensions must be literal scalar expressions",
                    a2[6]);
                  return nullptr;
                }
                if ( v44 == 3073 )
                {
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: v24,
                    a3: 0xC01u,
                    format: "'%s': secondary array dimensions must be explicit",
                    a2[6]);
                  return nullptr;
                }
                if ( v48 != nullptr )
                {
                  if ( v23 != 0 && v23 != 3 && v23 != 4 && v23 != 5 )
                  {
                    D3DXShader::CParse::Error(
                      this: v47,
                      a2: v24,
                      a3: 0xC00u,
                      format: "'%s': array dimensions of %s must be explicit",
                      a2[6],
                      v41[v23]);
                    return nullptr;
                  }
                  v43 = (struct D3DXShader::CNode *)(v51 * D3DXShader::CParse::TypeSize(this: v47, a2: v43));
                  if ( v43 != nullptr )
                  {
                    v25 = *(_DWORD *)(v11 + 36);
                    if ( v25 == 0 || *(_DWORD *)(v25 + 4) != 13 )
                    {
                      D3DXShader::CParse::Error(
                        this: v47,
                        a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                        a3: 0xC02u,
                        format: "'%s': implicit array missing %s",
                        a2[6],
                        v40[v23]);
                      return nullptr;
                    }
                    v26 = D3DXShader::CParse::TypeSize(this: v47, a2: *(struct D3DXShader::CNode **)(v25 + 16));
                    v28 = v26 % (unsigned int)v43;
                    v27 = v26 / (unsigned int)v43;
                    if ( v28 != 0 )
                    {
                      D3DXShader::CParse::Error(
                        this: v47,
                        a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                        a3: 0xC03u,
                        format: "'%s': implicit array type does not match %s",
                        a2[6],
                        v40[v23]);
                      return nullptr;
                    }
                    *(_DWORD *)v48 = v27;
                    v51 *= v27;
                  }
                  else
                  {
                    *(_DWORD *)v48 = 0;
                    v51 = 0;
                  }
                }
                if ( v51 == 0 || v51 > 0x10000 )
                {
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                    a3: 0xBF3u,
                    format: "'%s': array dimension must be between 1 and 65536",
                    a2[6]);
                  return nullptr;
                }
                v29 = D3DXShader::CParse::TypeSize(this: v47, a2: *(struct D3DXShader::CNode **)(v11 + 32));
                v30 = v47;
                *(_DWORD *)(v11 + 20) = v29;
                *(_DWORD *)(v11 + 24) = *(_DWORD *)(*((_DWORD *)v30 + 4) + 16);
                if ( *(_DWORD *)(*((_DWORD *)v30 + 4) + 16) == 1 )
                {
                  *(_DWORD *)(v11 + 16) = -1;
                }
                else
                {
                  v31 = v47;
                  *(_DWORD *)(v11 + 16) = *((_DWORD *)v47 + 22);
                  *((_DWORD *)v31 + 22) += v29;
                }
                v52 = *((_DWORD *)v42 + 4);
                if ( *((_DWORD *)v42 + 5) != 0 )
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                    a3: 0xBDFu,
                    format: "'%s': %s cannot be target specific",
                    a2[6],
                    (const char *)v41[v23]);
                if ( (v52 & 0x100) != 0 )
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                    a3: 0xBEFu,
                    format: "'%s': %s cannot be declared 'inline'",
                    a2[6],
                    (const char *)v41[v23]);
                if ( v23 == 1 )
                {
                  if ( D3DXShader::CParse::IsConst(this: v47, a2: *(struct D3DXShader::CNode **)(v11 + 32)) == 0 )
                    goto LABEL_89;
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                    a3: 0xBDBu,
                    format: "'%s': %s cannot be declared 'const'",
                    a2[6],
                    "structure members");
                }
                if ( v23 == 2 )
                {
                  if ( (v52 & 0x10) != 0
                    || D3DXShader::CParse::IsConst(this: v47, a2: *(struct D3DXShader::CNode **)(v11 + 32)) == 0 )
                  {
                    goto LABEL_89;
                  }
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                    a3: 0xBE6u,
                    format: "'%s': output paramaters cannot be declared 'const'",
                    a2[6]);
                }
                if ( (v23 == 3 || v23 == 4)
                  && !D3DXShader::CParse::IsNumeric(this: v47, a2: *(struct D3DXShader::CNode **)(v11 + 32)) )
                {
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                    a3: 0xBDEu,
                    format: "'%s': %s must be numeric",
                    a2[6],
                    (const char *)v41[v23]);
                }
                if ( v23 == 0 )
                {
                  if ( (v52 & 2) == 0 )
                    goto LABEL_88;
                  if ( (v52 & 1) != 0 )
                  {
                    D3DXShader::CParse::Error(
                      this: v47,
                      a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                      a3: 0xBBFu,
                      format: "'%s': extern %s cannot be declared 'static'",
                      a2[6],
                      "global variables");
                    v52 &= ~2u;
                  }
                  if ( (v52 & 2) == 0 )
                    goto LABEL_88;
                  if ( (v52 & 0x40) != 0 )
                  {
                    D3DXShader::CParse::Error(
                      this: v47,
                      a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                      a3: 0xBBFu,
                      format: "'%s': uniform %s cannot be declared 'static'",
                      a2[6],
                      "global variables");
                    v52 &= ~2u;
                  }
                  if ( (v52 & 2) == 0 )
LABEL_88:
                    v52 |= 0x41u;
                  goto LABEL_103;
                }
LABEL_89:
                if ( (v52 & 2) != 0 && v23 != 3 && v23 != 4 )
                {
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                    a3: 0xBBFu,
                    format: "'%s': %s cannot be declared 'static'",
                    a2[6],
                    (const char *)v41[v23]);
                  v52 &= ~2u;
                }
                if ( (v52 & 0x40) != 0 )
                {
                  if ( v23 != 2 )
                  {
                    D3DXShader::CParse::Error(
                      this: v47,
                      a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                      a3: 0xBE7u,
                      format: "'%s': %s cannot be declared 'uniform'",
                      a2[6],
                      (const char *)v41[v23]);
                    v52 &= ~0x40u;
                  }
                  if ( (v52 & 0x40) != 0 && (v52 & 0x20) != 0 )
                  {
                    D3DXShader::CParse::Error(
                      this: v47,
                      a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                      a3: 0xBF6u,
                      format: "'%s': %s cannot be declared 'uniform out'",
                      a2[6],
                      (const char *)v41[v23]);
                    v52 &= ~0x40u;
                  }
                }
                if ( (v52 & 1) != 0 )
                {
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                    a3: 0xBBEu,
                    format: "'%s': %s cannot be declared 'extern'",
                    a2[6],
                    (const char *)v41[v23]);
                  v52 &= ~1u;
                }
                if ( (v52 & 8) != 0 )
                {
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                    a3: 0xBEEu,
                    format: "'%s': %s cannot be declared 'shared'",
                    a2[6],
                    (const char *)v41[v23]);
                  v52 &= ~8u;
                }
LABEL_103:
                if ( (v52 & 4) != 0 && v23 != 3 && v23 != 4 && v23 != 2 )
                {
                  D3DXShader::CParse::Error(
                    this: v47,
                    a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                    a3: 0xBC0u,
                    format: "'%s': %s cannot be declared 'volatile'",
                    a2[6],
                    (const char *)v41[v23]);
                  v52 &= ~4u;
                }
                if ( v23 == 5 )
                {
                  D3DXShader::CParse::MakeTypeConst(this: v47, a2: *(struct D3DXShader::CNode ***)(v11 + 32), a3: 1);
                  v52 |= 0x40u;
                }
                v43 = nullptr;
                *(_DWORD *)(v11 + 28) = v52;
                if ( a5 != nullptr )
                {
                  if ( *((_DWORD *)a5 + 1) == 13 )
                  {
                    v32 = D3DXShader::CParse::CastExpr(
                            this: (struct D3DXShader::CNodeScope ***)v47,
                            a2: *(const char ***)(v11 + 32),
                            a3: (struct D3DXShader::CNode **)a5,
                            a4: 0,
                            a5: 0);
                  }
                  else
                  {
                    v33 = *(struct D3DXShader::CNode ***)(v11 + 36);
                    v49 = v33;
                    if ( v33 != nullptr )
                      v54 = v33[4];
                    else
                      v54 = nullptr;
                    if ( *(_DWORD *)(v11 + 20) != D3DXShader::CParse::TypeSize(this: v47, a2: v54) )
                    {
                      D3DXShader::CParse::ErrorUnsupportedCast(
                        this: v47,
                        a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                        a3: a2[6],
                        a4: *(struct D3DXShader::CNode **)(v11 + 32),
                        a5: v54,
                        a6: 1);
                      *(_DWORD *)(v11 + 36) = 0;
                      goto LABEL_125;
                    }
                    v32 = D3DXShader::CParse::CastExpr(
                            this: (struct D3DXShader::CNodeScope ***)v47,
                            a2: *(const char ***)(v11 + 32),
                            a3: v49,
                            a4: 0,
                            a5: 1);
                  }
                }
                else
                {
                  if ( v23 != 0 && v23 != 3 && v23 != 4 || (v52 & 2) == 0 )
                  {
LABEL_125:
                    if ( *(_DWORD *)(v11 + 36) != 0 )
                    {
                      if ( v23 == 1 )
                      {
                        D3DXShader::CParse::Error(
                          this: v47,
                          a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                          a3: 0xBC1u,
                          format: "'%s': %s cannot have %ss",
                          a2[6],
                          "structure members",
                          "initializer");
LABEL_160:
                        *(_DWORD *)(v11 + 36) = 0;
                        goto LABEL_161;
                      }
                      if ( v23 == 2
                        && !D3DXShader::CParse::IsNumeric(this: v47, a2: *(struct D3DXShader::CNode **)(v11 + 32)) )
                      {
                        D3DXShader::CParse::Error(
                          this: v47,
                          a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                          a3: 0xBC1u,
                          format: "'%s': non-numeric uniform %s cannot have %ss",
                          a2[6],
                          "function parameters",
                          "default value");
                        goto LABEL_160;
                      }
                      v50 = (struct D3DXShader::CNode *)(v52 & 0x10);
                      if ( (v52 & 0x10) == 0 && (v52 & 0x20) != 0 )
                      {
                        D3DXShader::CParse::Error(
                          this: v47,
                          a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                          a3: 0xBE5u,
                          format: "'%s': output only %s cannot have %ss",
                          a2[6],
                          (const char *)v41[v23],
                          (const char *)v40[v23]);
LABEL_139:
                        *(_DWORD *)(v11 + 36) = 0;
                        goto LABEL_157;
                      }
                      v55 = (struct D3DXShader::CNode *)(v52 & 0x50);
                      if ( (v52 & 0x50) != 0
                        && !D3DXShader::CParse::IsFullyLiteral(this: v47, a2: *(struct D3DXShader::CNode **)(v11 + 36)) )
                      {
                        D3DXShader::CParse::Error(
                          this: v47,
                          a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                          a3: 0xBC3u,
                          format: "'%s': %s must be a literal expression",
                          a2[6],
                          (const char *)v40[v23]);
                        goto LABEL_139;
                      }
                      if ( !D3DXShader::CParse::IsSupportedCast(
                              this: v47,
                              a2: *(struct D3DXShader::CNode **)(v11 + 32),
                              a3: *(struct D3DXShader::CNode **)(*(_DWORD *)(v11 + 36) + 16),
                              a4: 0) )
                      {
                        D3DXShader::CParse::ErrorUnsupportedCast(
                          this: v47,
                          a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                          a3: a2[6],
                          a4: *(struct D3DXShader::CNode **)(v11 + 32),
                          a5: *(struct D3DXShader::CNode **)(*(_DWORD *)(v11 + 36) + 16),
                          a6: 0);
                        goto LABEL_139;
                      }
                      v53 = (struct D3DXShader::CNode *)(v52 & 0x40);
                      if ( v53 != nullptr )
                        *(_DWORD *)(v11 + 40) = D3DXShader::CParse::Eval(
                                                  this: v47,
                                                  a2: *(struct D3DXShader::CNode **)(v11 + 36));
                      if ( v55 != nullptr
                        || D3DXShader::CParse::IsConst(this: v47, a2: *(struct D3DXShader::CNode **)(v11 + 32)) == 0 )
                      {
                        v34 = nullptr;
                        if ( v50 != nullptr || v53 == nullptr )
                        {
                          v35 = *(struct D3DXShader::CNode **)(v11 + 36);
                          v36 = (struct D3DXShader::CNodeScope ***)v47;
                          *(_DWORD *)(v11 + 36) = 0;
                          v56 = v35;
                          v37 = D3DXShader::CParse::VariableExpr(
                                  this: v36,
                                  (struct D3DXShader::CNode *)a2,
                                  a3: (struct D3DXShader::CNode *)v11);
                          v43 = D3DXShader::CParse::Expr(this: v47, a2: 0x14u, a3: v37, a4: v56, a5: 1);
                          goto LABEL_157;
                        }
                      }
                      else
                      {
                        v34 = D3DXShader::CParse::Eval(this: v47, a2: *(struct D3DXShader::CNode **)(v11 + 36));
                      }
                      *(_DWORD *)(v11 + 36) = v34;
                    }
                    else
                    {
                      if ( v23 == 0 )
                      {
                        if ( D3DXShader::CParse::IsConst(this: v47, a2: *(struct D3DXShader::CNode **)(v11 + 32)) == 0 )
                          goto LABEL_161;
                        if ( (v52 & 2) != 0 )
                          goto LABEL_156;
                      }
                      if ( (v23 == 3 || v23 == 4)
                        && D3DXShader::CParse::IsConst(this: v47, a2: *(struct D3DXShader::CNode **)(v11 + 32)) != 0
                        || v23 == 5 )
                      {
LABEL_156:
                        D3DXShader::CParse::Error(
                          this: v47,
                          a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                          a3: 0xBC4u,
                          format: "'%s': missing %s",
                          a2[6],
                          (const char *)v40[v23]);
                      }
                    }
LABEL_157:
                    if ( v23 > 2 && *(_DWORD *)(v11 + 44) != 0 )
                    {
                      D3DXShader::CParse::Error(
                        this: v47,
                        a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                        a3: 0xBE3u,
                        format: "'%s': %s cannot have semantics",
                        a2[6],
                        (const char *)v41[v23]);
                      goto LABEL_160;
                    }
LABEL_161:
                    if ( *((_DWORD *)v46 + 7) != 0 && v23 != 0 && v23 != 2 )
                    {
                      D3DXShader::CParse::Error(
                        this: v47,
                        a2: (struct D3DXShader::D3DXTOKEN *)(a2 + 4),
                        a3: 0xBE0u,
                        format: "'%s': %s cannot have annotations",
                        a2[6],
                        (const char *)v41[v23]);
                      *((_DWORD *)v46 + 7) = 0;
                    }
                    if ( D3DXShader::CParse::AddDecl(this: v47, a2: v46, a3: 0) >= 0 )
                    {
                      if ( v43 == nullptr )
                        return (struct D3DXShader::CNode *)v45;
                      v38 = D3DXShader::CParse::Stmt(this: v47, a2: v43);
                      *(_DWORD *)(v45 + 12) = v38;
                      if ( v38 != nullptr )
                        return (struct D3DXShader::CNode *)v45;
                    }
                    return nullptr;
                  }
                  v32 = (struct D3DXShader::CNode *)D3DXShader::CParse::ScalarExpr(
                                                      this: v47,
                                                      a2: 5,
                                                      a3: 0,
                                                      a4: COERCE_UNSIGNED_INT64(0.0),
                                                      a5: HIDWORD(COERCE_UNSIGNED_INT64(0.0)),
                                                      a6: (int)v24);
                }
                *(_DWORD *)(v11 + 36) = v32;
                goto LABEL_125;
              }
            }
          }
        }
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FCB73
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::FunctionExpr(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::FunctionExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        int a4)
{
  struct D3DXShader::D3DXTOKEN *v4; // ebx
  int v5; // eax
  const char **v6; // eax
  unsigned int v7; // ecx
  int Decl; // eax
  BOOL v9; // esi
  int Intrinsic; // eax
  int v11; // eax
  int v12; // eax
  struct D3DXShader::CNode *v13; // esi
  int i; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // edx
  struct D3DXShader::CNode *v18; // ebx
  int v19; // eax
  unsigned __int8 *v20; // eax
  int v21; // eax
  unsigned __int8 *v22; // eax
  int v23; // eax
  struct D3DXShader::CNode *v24; // eax
  struct D3DXShader::CNode **v25; // eax
  struct D3DXShader::CNode *v26; // eax
  struct D3DXShader::CNode *v27; // eax
  unsigned __int8 *v28; // eax
  struct D3DXShader::CNode *v29; // esi
  int v30; // eax
  unsigned __int8 *v31; // eax
  int v32; // eax
  struct D3DXShader::CNode *v33; // eax
  struct D3DXShader::CNode *v34; // eax
  int v35; // ecx
  const char *v36; // eax
  int v38; // [esp+4h] [ebp-30h]
  int v39; // [esp+8h] [ebp-2Ch] BYREF
  int v40; // [esp+Ch] [ebp-28h] BYREF
  struct D3DXShader::CNode *v41; // [esp+10h] [ebp-24h]
  int *v42; // [esp+14h] [ebp-20h]
  int *v43; // [esp+18h] [ebp-1Ch]
  struct D3DXShader::CNode *v44; // [esp+1Ch] [ebp-18h] BYREF
  struct D3DXShader::CNode *v45; // [esp+20h] [ebp-14h] BYREF
  struct D3DXShader::CNode *v46; // [esp+24h] [ebp-10h] BYREF
  int v47; // [esp+28h] [ebp-Ch]
  struct D3DXShader::D3DXTOKEN *v48; // [esp+2Ch] [ebp-8h]
  D3DXShader::CParse *v49; // [esp+30h] [ebp-4h]
  struct D3DXShader::CNode *v50; // [esp+3Ch] [ebp+8h]

  v49 = this;
  v46 = nullptr;
  v44 = nullptr;
  v45 = nullptr;
  v40 = 0;
  v39 = 0;
  if ( a2 == nullptr || *((_DWORD *)a2 + 1) != 3 )
    return nullptr;
  v4 = (struct D3DXShader::CNode *)((char *)a2 + 16);
  v5 = *((_DWORD *)this + 6);
  v48 = (struct D3DXShader::CNode *)((char *)a2 + 16);
  if ( v5 != 0 )
    v6 = *(const char ***)(v5 + 28);
  else
    v6 = nullptr;
  v7 = 6;
  if ( a4 != 0 )
    v7 = 22;
  Decl = D3DXShader::CParse::FindDecl(
           this: v49,
           a2: 2,
           a3: (const char **)v4,
           a4: v6,
           a5: a3,
           a6: *((struct D3DXShader::CNodeScope ***)v49 + 4),
           a7: v7,
           a8: (int *)&v46,
           a9: (int **)&v45);
  if ( Decl >= 0 )
  {
    v9 = Decl == 0;
    if ( a4 == 0 )
    {
      if ( Decl == 0 )
      {
LABEL_27:
        v13 = a3;
        v43 = &v40;
        v42 = &v39;
        for ( i = *((_DWORD *)v46 + 9); ; i = *(_DWORD *)(v47 + 12) )
        {
          v47 = i;
          if ( i == 0 )
            break;
          v15 = *(_DWORD *)(v47 + 8);
          v16 = *(_DWORD *)(v47 + 12);
          v17 = 0;
          v38 = v15;
          if ( v16 != 0 )
          {
            v4 = v48;
            if ( *(_DWORD *)(*(_DWORD *)(v16 + 8) + 4) == 12 )
            {
              v17 = 1;
              v47 = *(_DWORD *)(v47 + 12);
            }
          }
          if ( a4 == 0 || (*(_BYTE *)(*(_DWORD *)(v15 + 24) + 28) & 0x40) != 0 )
          {
            if ( v13 != nullptr )
            {
              v18 = *(struct D3DXShader::CNode **)(*(_DWORD *)(v15 + 24) + 32);
              v41 = *(struct D3DXShader::CNode **)(v15 + 24);
              v19 = *((_DWORD *)v13 + 2);
              if ( v19 != 0 )
                v50 = *(struct D3DXShader::CNode **)(v19 + 16);
              else
                v50 = nullptr;
              v20 = D3DXShader::CNode::operator new(a1: 0x14u);
              if ( v20 != nullptr )
                v21 = D3DXShader::CNodeList::CNodeList(
                        this: (D3DXShader::CNodeList *)v20,
                        a2: nullptr,
                        a3: nullptr,
                        a4: "Inputs");
              else
                v21 = 0;
              *v43 = v21;
              if ( v21 == 0 )
                return nullptr;
              v22 = D3DXShader::CNode::operator new(a1: 0x14u);
              v23 = v22 != nullptr
                  ? D3DXShader::CNodeList::CNodeList(
                      this: (D3DXShader::CNodeList *)v22,
                      a2: nullptr,
                      a3: nullptr,
                      a4: "Outputs")
                  : 0;
              *v42 = v23;
              if ( v23 == 0 )
                return nullptr;
              if ( (*((_BYTE *)v41 + 28) & 0x10) != 0 )
              {
                if ( !D3DXShader::CParse::IsSupportedCast(this: v49, a2: v18, a3: v50, a4: 0) )
                {
                  D3DXShader::CParse::ErrorUnsupportedCast(
                    this: v49,
                    a2: v48,
                    a3: *((const char **)v48 + 2),
                    a4: v18,
                    a5: v50,
                    a6: 0);
                  return nullptr;
                }
                v24 = D3DXShader::CParse::CastExpr(
                        this: (struct D3DXShader::CNodeScope ***)v49,
                        a2: (const char **)v18,
                        a3: *((struct D3DXShader::CNode ***)v13 + 2),
                        a4: 0,
                        a5: 0);
                *(_DWORD *)(*v43 + 8) = v24;
              }
              if ( (*((_BYTE *)v41 + 28) & 0x20) != 0 )
              {
                if ( D3DXShader::CParse::IsConst(this: v49, a2: v50) != 0
                  || !D3DXShader::CParse::IsSupportedCast(this: v49, a2: v50, a3: v18, a4: 0) )
                {
                  D3DXShader::CParse::ErrorUnsupportedCast(
                    this: v49,
                    a2: v48,
                    a3: *((const char **)v48 + 2),
                    a4: v50,
                    a5: v18,
                    a6: 0);
                  return nullptr;
                }
                v25 = (struct D3DXShader::CNode **)D3DXShader::CParse::VariableExpr(
                                                     this: (struct D3DXShader::CNodeScope ***)v49,
                                                     a2: *(struct D3DXShader::CNode **)(v38 + 20),
                                                     a3: v41);
                if ( v25 == nullptr )
                  return nullptr;
                v26 = D3DXShader::CParse::CastExpr(
                        this: (struct D3DXShader::CNodeScope ***)v49,
                        a2: (const char **)v50,
                        a3: v25,
                        a4: 0,
                        a5: 0);
                if ( v26 == nullptr )
                  return nullptr;
                v27 = D3DXShader::CParse::Expr(
                        this: v49,
                        a2: 0x15u,
                        a3: *((struct D3DXShader::D3DXTOKEN **)v13 + 2),
                        a4: v26,
                        a5: 1);
                if ( v27 == nullptr )
                  return nullptr;
                *(_DWORD *)(*v42 + 8) = v27;
              }
              v13 = *((struct D3DXShader::CNode **)v13 + 3);
              v4 = v48;
              v43 = (int *)(*v43 + 12);
              v42 = (int *)(*v42 + 12);
            }
            else if ( v17 == 0 )
            {
              goto LABEL_60;
            }
          }
        }
        if ( v13 == nullptr )
        {
LABEL_60:
          if ( v47 == 0 )
          {
            v28 = D3DXShader::CNode::operator new(a1: 0x50u);
            if ( v28 != nullptr )
              v29 = (struct D3DXShader::CNode *)D3DXShader::CNodeExpression::CNodeExpression(
                                                  a1: v28,
                                                  a2: 0,
                                                  a3: (v44 != nullptr) + 25,
                                                  a4: 0,
                                                  a5: 0,
                                                  a6: 1,
                                                  a7: v4);
            else
              v29 = nullptr;
            if ( v29 != nullptr )
            {
              if ( *((_DWORD *)v46 + 8) == 0
                || (v30 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v46 + 8) + 4))(a1: *((_DWORD *)v46 + 8)),
                    *((_DWORD *)v29 + 4) = v30,
                    v30 != 0) )
              {
                *((_DWORD *)v29 + 8) = v45;
                v31 = D3DXShader::CNode::operator new(a1: 0x14u);
                v32 = v31 != nullptr
                    ? D3DXShader::CNodeList::CNodeList(
                        this: (D3DXShader::CNodeList *)v31,
                        a2: nullptr,
                        a3: nullptr,
                        a4: "Parameters")
                    : 0;
                *((_DWORD *)v29 + 9) = v32;
                if ( v32 != 0 )
                {
                  *(_DWORD *)(v32 + 8) = v40;
                  *(_DWORD *)(*((_DWORD *)v29 + 9) + 12) = v39;
                  D3DXShader::CParse::ComputeExprSize(this: v49, a2: v29);
                  if ( D3DXShader::CParse::IsFullyLiteral(this: v49, a2: v29) )
                  {
                    v33 = D3DXShader::CParse::Eval(this: v49, a2: v29);
                    if ( v33 != nullptr )
                      return v33;
                  }
                  return v29;
                }
              }
            }
            return nullptr;
          }
        }
        v34 = a3;
        v35 = 0;
        while ( v34 != nullptr )
        {
          v34 = *((struct D3DXShader::CNode **)v34 + 3);
          ++v35;
        }
        v36 = "s";
        if ( v44 != nullptr )
        {
          if ( v35 == 1 )
            v36 = (const char *)&pMem;
          D3DXShader::CParse::Error(
            this: v49,
            a2: v4,
            a3: 0xBC5u,
            format: "'%s': intrinsic function does not take %u parameter%s",
            *((_DWORD *)v4 + 2),
            v35,
            v36);
        }
        else
        {
          if ( v35 == 1 )
            v36 = (const char *)&pMem;
          D3DXShader::CParse::Error(
            this: v49,
            a2: v4,
            a3: 0xBC5u,
            format: "'%s': function does not take %u parameter%s",
            *((_DWORD *)v4 + 2),
            v35,
            v36);
        }
        return nullptr;
      }
      Intrinsic = D3DXShader::CParse::FindIntrinsic(this: v49, a2: v4, a3, a4: &v44, a5: &v45);
      if ( Intrinsic < 0 )
        return nullptr;
      if ( Intrinsic != 0 )
      {
LABEL_15:
        v11 = D3DXShader::CParse::FindDecl(
                this: v49,
                a2: 2,
                a3: (const char **)v4,
                a4: nullptr,
                a5: nullptr,
                a6: *((struct D3DXShader::CNodeScope ***)v49 + 4),
                a7: 2u,
                a8: (int *)&v46,
                a9: (int **)&v45);
        if ( v11 < 0 )
          return nullptr;
        if ( v11 == 0 )
          v9 = true;
LABEL_18:
        if ( a4 == 0 )
        {
          if ( v9 )
          {
LABEL_25:
            if ( v44 != nullptr )
              v46 = v44;
            goto LABEL_27;
          }
          v12 = D3DXShader::CParse::FindIntrinsic(this: v49, a2: v4, a3: nullptr, a4: &v44, a5: &v45);
          if ( v12 < 0 )
            return nullptr;
          if ( v12 != 0 )
            goto LABEL_24;
          v9 = true;
        }
        if ( !v9 )
        {
LABEL_24:
          D3DXShader::CParse::Error(
            this: v49,
            a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
            a3: 0xBBCu,
            format: "undeclared identifier '%s'",
            *((const char **)a2 + 6));
          return nullptr;
        }
        goto LABEL_25;
      }
      v9 = true;
    }
    if ( v9 )
      goto LABEL_18;
    goto LABEL_15;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FCF8B
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CParse::CompileExpr(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CParse::CompileExpr(
        D3DXShader::CParse *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4,
        int a5)
{
  int v6; // eax
  unsigned __int8 *v7; // eax
  _DWORD *v8; // ebx
  unsigned __int8 *v9; // eax
  int v10; // eax
  struct D3DXShader::CNode *v11; // eax
  struct D3DXShader::CNode *v12; // eax
  unsigned __int8 *v13; // eax
  struct D3DXShader::CNode *v14; // ebx
  unsigned __int8 *v15; // eax
  int v16; // eax
  unsigned __int8 *v17; // eax
  int v18; // eax
  unsigned __int8 *v19; // eax
  int v20; // eax
  const char *v21; // [esp-Ch] [ebp-30h]
  int v22; // [esp+Ch] [ebp-18h] BYREF
  int v23; // [esp+10h] [ebp-14h]
  char *v24; // [esp+18h] [ebp-Ch]
  D3DXShader::CParse *v25; // [esp+1Ch] [ebp-8h]
  _DWORD *v26; // [esp+20h] [ebp-4h]

  v25 = this;
  if ( a2 == nullptr || a3 == nullptr )
    return nullptr;
  v21 = *((const char **)a2 + 6);
  v24 = (char *)a2 + 16;
  if ( D3DXGetTargetDescByName(a1: v21, a2: 2, a3: &v22) < 0 )
  {
    D3DXShader::CParse::Error(
      this: v25,
      a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
      a3: 0xBE1u,
      format: "unsupported compiler target '%s'",
      *((const char **)a2 + 6));
    return nullptr;
  }
  if ( (v23 & 0xFFFF0000) == 0xFFFE0000 )
  {
    v6 = 2 * (a5 != 0) + 26;
  }
  else
  {
    if ( (v23 & 0xFFFF0000) != 0xFFFF0000 )
      goto LABEL_11;
    v6 = 2 * (a5 != 0) + 25;
  }
  a5 = v6;
LABEL_11:
  v7 = D3DXShader::CNode::operator new(a1: 0x50u);
  if ( v7 != nullptr )
  {
    v8 = (_DWORD *)D3DXShader::CNodeExpression::CNodeExpression(
                     a1: v7,
                     a2: 0,
                     a3: 27,
                     a4: 0,
                     a5: 0,
                     a6: 1,
                     a7: (char *)a2 + 16);
    v26 = v8;
  }
  else
  {
    v26 = nullptr;
    v8 = nullptr;
  }
  if ( v8 == nullptr )
    return nullptr;
  v9 = D3DXShader::CNode::operator new(a1: 0x24u);
  v10 = v9 != nullptr ? D3DXShader::CNodeType::CNodeType(a1: v9, a2: 3, a3: a5, a4: 1, a5: 1, a6: 512) : 0;
  v8[4] = v10;
  if ( v10 == 0 )
    return nullptr;
  v11 = D3DXShader::CNode::Copy(a1: a2);
  v8[8] = v11;
  if ( v11 == nullptr )
    return nullptr;
  v12 = D3DXShader::CParse::FunctionExpr(this: v25, a2: a3, a3: a4, a4: 1);
  v8[9] = v12;
  if ( v12 == nullptr )
    return nullptr;
  v13 = D3DXShader::CNode::operator new(a1: 0x50u);
  v14 = v13 != nullptr
      ? (struct D3DXShader::CNode *)D3DXShader::CNodeExpression::CNodeExpression(
                                      a1: v13,
                                      a2: 0,
                                      a3: 0,
                                      a4: 0,
                                      a5: 0,
                                      a6: 1,
                                      a7: v24)
      : nullptr;
  if ( v14 == nullptr )
    return nullptr;
  v15 = D3DXShader::CNode::operator new(a1: 0x24u);
  v16 = v15 != nullptr ? D3DXShader::CNodeType::CNodeType(a1: v15, a2: 3, a3: a5, a4: 1, a5: 1, a6: 512) : 0;
  *((_DWORD *)v14 + 4) = v16;
  if ( v16 == 0 )
    return nullptr;
  v17 = D3DXShader::CNode::operator new(a1: 0x14u);
  v18 = v17 != nullptr
      ? D3DXShader::CNodeList::CNodeList(this: (D3DXShader::CNodeList *)v17, a2: nullptr, a3: nullptr, a4: "Value")
      : 0;
  *((_DWORD *)v14 + 8) = v18;
  if ( v18 == 0 )
    return nullptr;
  v19 = D3DXShader::CNode::operator new(a1: 0x40u);
  v20 = v19 != nullptr ? D3DXShader::CNodeValue::CNodeValue(a1: v19, a2: 4, a3: v26, a4: v24) : 0;
  *(_DWORD *)(*((_DWORD *)v14 + 8) + 8) = v20;
  if ( v20 == 0 )
    return nullptr;
  D3DXShader::CParse::ComputeExprSize(this: v25, a2: v14);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x101FD153
// Name: protected: void D3DXShader::CParse::Production(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CParse::Production(
        D3DXShader::CParse *this,
        unsigned int a2,
        struct D3DXShader::CNodeScope *a3)
{
  struct D3DXShader::CNode *v4; // esi
  bool v5; // zf
  int v7; // eax
  unsigned __int8 *v8; // eax
  struct D3DXShader::CNode *v9; // eax
  unsigned __int8 *v10; // eax
  struct D3DXShader::CNode *v11; // eax
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // eax
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // eax
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // eax
  unsigned __int8 *v22; // eax
  struct D3DXShader::CNode *v23; // eax
  const char **v24; // esi
  struct D3DXShader::CNode *v25; // esi
  struct D3DXShader::CNode *v26; // ebx
  unsigned __int8 *v27; // eax
  unsigned __int8 *v28; // eax
  int v29; // eax
  struct D3DXShader::D3DXTOKEN *v30; // ebx
  unsigned __int8 *v31; // eax
  unsigned __int8 *v32; // eax
  unsigned __int8 *v33; // eax
  unsigned __int8 *v34; // eax
  unsigned __int8 *v35; // eax
  unsigned __int8 *v36; // eax
  const char *v37; // esi
  int v38; // eax
  struct D3DXShader::CNodeScope *v39; // eax
  const char **v40; // ebx
  struct D3DXShader::CNode *Decls; // eax
  int v42; // ecx
  unsigned __int8 *v43; // eax
  unsigned __int8 *v44; // eax
  unsigned __int8 *v45; // eax
  unsigned __int8 *v46; // eax
  unsigned __int8 *v47; // eax
  unsigned __int8 *v48; // eax
  unsigned __int8 *v49; // eax
  struct D3DXShader::CNode *v50; // eax
  unsigned __int8 *v51; // eax
  unsigned __int8 *v52; // eax
  struct D3DXShader::CNode *v53; // eax
  unsigned __int8 *v54; // eax
  unsigned __int8 *v55; // eax
  unsigned __int8 *v56; // eax
  int v57; // eax
  struct D3DXShader::CNode *v58; // eax
  unsigned __int8 *v59; // eax
  unsigned __int8 *v60; // eax
  int v61; // [esp-4h] [ebp-7Ch]
  int v62; // [esp-4h] [ebp-7Ch]
  int v63; // [esp+4h] [ebp-74h]
  struct D3DXShader::CNode *v64; // [esp+8h] [ebp-70h]
  const char *v65; // [esp+8h] [ebp-70h]
  const char *v66; // [esp+8h] [ebp-70h]
  int v67; // [esp+8h] [ebp-70h]
  const char **v68; // [esp+18h] [ebp-60h]
  struct D3DXShader::CNode *v69; // [esp+1Ch] [ebp-5Ch]
  struct D3DXShader::CNode *v70; // [esp+20h] [ebp-58h]
  struct D3DXShader::CNode *v71; // [esp+24h] [ebp-54h]
  struct D3DXShader::CNode *v72; // [esp+28h] [ebp-50h]
  _BYTE v73[28]; // [esp+58h] [ebp-20h] BYREF
  struct D3DXShader::CNode *v74; // [esp+74h] [ebp-4h] BYREF
  unsigned int v75; // [esp+80h] [ebp+8h]
  struct D3DXShader::CNodeScope *v76; // [esp+84h] [ebp+Ch]

  v4 = nullptr;
  v5 = *((_DWORD *)this + 17) == 0;
  v74 = nullptr;
  if ( v5 )
  {
    while ( a3 != nullptr )
    {
      v7 = *((_DWORD *)this + 2);
      a3 = (struct D3DXShader::CNodeScope *)((char *)a3 - 1);
      if ( v7 == 0 )
      {
        D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: stack underflow");
        return;
      }
      (&v68)[(_DWORD)a3] = *(const char ***)(v7 + 8);
      *((_DWORD *)this + 2) = *(_DWORD *)(v7 + 12);
      *(_DWORD *)(v7 + 8) = 0;
      *(_DWORD *)(v7 + 12) = *((_DWORD *)this + 3);
      *((_DWORD *)this + 3) = v7;
    }
    switch ( a2 )
    {
      case 0u:
        v8 = D3DXShader::CNode::operator new(a1: 0x20u);
        if ( v8 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeProgram::CNodeProgram(
                                           this: (D3DXShader::CNodeProgram *)v8,
                                           a2: 0,
                                           a3: 0,
                                           a4: 0,
                                           a5: nullptr);
        goto LABEL_294;
      case 1u:
        v10 = D3DXShader::CNode::operator new(a1: 0x20u);
        if ( v10 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeProgram::CNodeProgram(
                                           this: (D3DXShader::CNodeProgram *)v10,
                                           a2: *((_DWORD *)this + 20),
                                           a3: *((_DWORD *)this + 21),
                                           a4: *((_DWORD *)this + 22),
                                           a5: (struct D3DXShader::CNode *)v68);
        goto LABEL_294;
      case 2u:
      case 5u:
      case 6u:
      case 7u:
      case 8u:
      case 9u:
      case 0xAu:
      case 0x12u:
      case 0x14u:
      case 0x21u:
      case 0x24u:
      case 0x25u:
      case 0x28u:
      case 0x2Au:
      case 0x2Du:
      case 0x2Eu:
      case 0x2Fu:
      case 0x4Eu:
      case 0x51u:
      case 0x56u:
      case 0x59u:
      case 0x5Fu:
      case 0x61u:
      case 0x64u:
      case 0x65u:
      case 0x66u:
      case 0x68u:
      case 0x6Bu:
      case 0x6Eu:
      case 0x79u:
      case 0x80u:
      case 0x86u:
      case 0x8Cu:
      case 0x93u:
      case 0x97u:
      case 0x9Eu:
      case 0xA7u:
      case 0xA8u:
      case 0xA9u:
      case 0xAAu:
      case 0xADu:
      case 0xB5u:
      case 0xB7u:
      case 0xB9u:
      case 0xBCu:
      case 0xBDu:
      case 0xBEu:
      case 0xBFu:
      case 0xC0u:
      case 0xC7u:
      case 0xD4u:
      case 0xD5u:
      case 0xD6u:
      case 0xDBu:
      case 0xE1u:
      case 0xE3u:
      case 0xE7u:
      case 0xEAu:
      case 0xEFu:
      case 0xF2u:
      case 0xF4u:
      case 0xF6u:
      case 0xFDu:
      case 0x102u:
      case 0x104u:
      case 0x105u:
      case 0x106u:
      case 0x108u:
      case 0x109u:
      case 0x10Bu:
      case 0x10Du:
      case 0x10Fu:
      case 0x111u:
      case 0x118u:
      case 0x119u:
      case 0x121u:
        v4 = (struct D3DXShader::CNode *)v68;
        goto LABEL_57;
      case 3u:
      case 0x52u:
      case 0x62u:
      case 0x6Cu:
      case 0x7Au:
      case 0x8Du:
      case 0x94u:
      case 0x9Fu:
      case 0x107u:
        v11 = D3DXShader::CNode::Append(a1: (struct D3DXShader::CNode *)v68, a2: v69);
        goto LABEL_16;
      case 4u:
      case 0x2Cu:
      case 0x4Au:
      case 0x58u:
      case 0x5Cu:
      case 0x5Eu:
      case 0x67u:
      case 0x74u:
      case 0x75u:
      case 0x78u:
      case 0x88u:
      case 0x8Fu:
      case 0x96u:
      case 0x9Au:
      case 0xA0u:
      case 0xB3u:
      case 0xB6u:
      case 0xB8u:
      case 0xCCu:
      case 0x101u:
      case 0x117u:
        goto LABEL_183;
      case 0xBu:
      case 0x15u:
      case 0x81u:
        v4 = (struct D3DXShader::CNode *)v68;
        D3DXShader::CParse::CombineUsages(this, a2: (struct D3DXShader::CNode *)v68, a3: v69);
        goto LABEL_57;
      case 0xCu:
        v12 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v12 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v12,
                                           a2: 2u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0xDu:
        v13 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v13 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v13,
                                           a2: 0x40u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0xEu:
        v14 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v14 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v14,
                                           a2: 1u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0xFu:
        v15 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v15 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v15,
                                           a2: 4u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x10u:
        v16 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v16 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v16,
                                           a2: 0x100u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x11u:
        v17 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v17 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v17,
                                           a2: 8u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x13u:
        v18 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v18 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v18,
                                           a2: 0,
                                           a3: (struct D3DXShader::CNode *)v68,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x16u:
        v19 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v19 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v19,
                                           a2: 0x200u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x17u:
        v20 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v20 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v20,
                                           a2: 0x400u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x18u:
        v21 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v21 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v21,
                                           a2: 0x800u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x19u:
        v22 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v22 == nullptr )
          goto LABEL_40;
        v23 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                            this: (D3DXShader::CNodeUsage *)v22,
                                            a2: 0,
                                            a3: nullptr,
                                            a4: (struct D3DXShader::CNode *)v68);
        goto LABEL_162;
      case 0x1Au:
        v4 = (struct D3DXShader::CNode *)v68;
        v68[6] = (const char *)v69;
        goto LABEL_42;
      case 0x1Du:
        v4 = (struct D3DXShader::CNode *)v68;
        D3DXShader::CNodeUsage::CNodeUsage(
          this: (D3DXShader::CNodeUsage *)v73,
          a2: 0,
          a3: nullptr,
          a4: *((struct D3DXShader::CNode **)v68[2] + 6));
        D3DXShader::CParse::PushUsageType((struct D3DXShader::CNode **)this, a2: (struct D3DXShader::CNode *)v73);
        goto LABEL_57;
      case 0x1Eu:
        v24 = v68;
        v64 = (struct D3DXShader::CNode *)v68;
        v68[6] = *(const char **)(*((_DWORD *)v69 + 2) + 24);
        D3DXShader::CParse::PushUsageType((struct D3DXShader::CNode **)this, a2: v64);
        v24[6] = nullptr;
        goto LABEL_47;
      case 0x1Fu:
        v9 = D3DXShader::CParse::TypeDecl(this, a2: (struct D3DXShader::CNode *)v68, a3: v69);
        goto LABEL_294;
      case 0x20u:
        v25 = (struct D3DXShader::CNode *)v68;
        v26 = D3DXShader::CParse::TypeDecl(this, a2: *((struct D3DXShader::CNode **)v68[2] + 6), a3: v69);
        D3DXShader::CParse::NonNull(this, a2: v26);
        v11 = D3DXShader::CNode::Append(a1: v25, a2: v26);
        goto LABEL_16;
      case 0x22u:
        v27 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v27 == nullptr )
          goto LABEL_10;
        v65 = "TypeDefs";
        goto LABEL_52;
      case 0x23u:
        v28 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v28 == nullptr )
          goto LABEL_10;
        v66 = "TypeDefs";
        goto LABEL_222;
      case 0x26u:
        D3DXShader::CParse::FindDecl(
          this,
          a2: 0,
          a3: v68 + 4,
          a4: nullptr,
          a5: nullptr,
          a6: *((struct D3DXShader::CNodeScope ***)this + 4),
          a7: 1u,
          a8: (int *)&v74,
          a9: nullptr);
        goto LABEL_56;
      case 0x27u:
        v30 = (struct D3DXShader::D3DXTOKEN *)(v68 + 4);
        if ( D3DXShader::CParse::FindDecl(
               this,
               a2: 0,
               a3: v68 + 4,
               a4: nullptr,
               a5: nullptr,
               a6: *((struct D3DXShader::CNodeScope ***)this + 4),
               a7: 1u,
               a8: (int *)&v74,
               a9: nullptr) != 0 )
        {
LABEL_56:
          v4 = v74;
        }
        else
        {
          v4 = v74;
          if ( v74 != nullptr && *((_DWORD *)v74 + 1) != 1 )
            D3DXShader::CParse::Error(
              this,
              a2: v30,
              a3: 0xBBDu,
              format: "invalid use of '%s'",
              *((const char **)v30 + 2));
        }
        goto LABEL_57;
      case 0x29u:
        v4 = v69;
        D3DXShader::CParse::ApplyUsage(this, a2: (struct D3DXShader::CNode *)v68, a3: (struct D3DXShader::CNode **)v69);
        goto LABEL_57;
      case 0x2Bu:
        v9 = D3DXShader::CParse::TypeDim(this, a2: (struct D3DXShader::CNode *)v68, a3: v69);
        goto LABEL_294;
      case 0x30u:
        v4 = (struct D3DXShader::CNode *)v68;
        D3DXShader::CParse::CheckForObjectsInStructs(
          this,
          a2: *((struct D3DXShader::CNodeScope **)this + 4),
          a3: (struct D3DXShader::CNodeType *)v68);
        goto LABEL_57;
      case 0x31u:
        v31 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v31 == nullptr )
          goto LABEL_10;
        v61 = 0;
        goto LABEL_71;
      case 0x32u:
        v31 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v31 == nullptr )
          goto LABEL_10;
        v61 = 4;
        goto LABEL_71;
      case 0x33u:
        v31 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v31 == nullptr )
          goto LABEL_10;
        v61 = 10;
        goto LABEL_71;
      case 0x34u:
        v31 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v31 == nullptr )
          goto LABEL_10;
        v61 = 11;
        goto LABEL_71;
      case 0x35u:
        v31 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v31 == nullptr )
          goto LABEL_10;
        v61 = 12;
LABEL_71:
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeType::CNodeType(a1: v31, a2: 0, a3: v61, a4: 1, a5: 1, a6: 0);
        goto LABEL_294;
      case 0x36u:
        v32 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v32 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeType::CNodeType(a1: v32, a2: 1, a3: 11, a4: 1, a5: 4, a6: 0);
        goto LABEL_294;
      case 0x37u:
        v9 = D3DXShader::CParse::VectorType(this, a2: (struct D3DXShader::CNode *)v68, a3: v69);
        goto LABEL_294;
      case 0x38u:
        v33 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v33 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeType::CNodeType(a1: v33, a2: 2, a3: 11, a4: 4, a5: 4, a6: 0);
        goto LABEL_294;
      case 0x39u:
        v9 = D3DXShader::CParse::MatrixType(this, a2: (struct D3DXShader::CNode *)v68, a3: v69, a4: v70);
        goto LABEL_294;
      case 0x3Au:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 14;
        goto LABEL_118;
      case 0x3Bu:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 15;
        goto LABEL_118;
      case 0x3Cu:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 16;
        goto LABEL_118;
      case 0x3Du:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 17;
        goto LABEL_118;
      case 0x3Eu:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 18;
        goto LABEL_118;
      case 0x3Fu:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 19;
        goto LABEL_118;
      case 0x40u:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 20;
        goto LABEL_118;
      case 0x41u:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 21;
        goto LABEL_118;
      case 0x42u:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 22;
        goto LABEL_118;
      case 0x43u:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 23;
        goto LABEL_118;
      case 0x44u:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 24;
        goto LABEL_118;
      case 0x45u:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 25;
        goto LABEL_118;
      case 0x46u:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 26;
        goto LABEL_118;
      case 0x47u:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 27;
        goto LABEL_118;
      case 0x48u:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 28;
        goto LABEL_118;
      case 0x49u:
        v34 = D3DXShader::CNode::operator new(a1: 0x24u);
        if ( v34 == nullptr )
          goto LABEL_10;
        v62 = 29;
LABEL_118:
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeType::CNodeType(a1: v34, a2: 3, a3: v62, a4: 1, a5: 1, a6: 0);
        goto LABEL_294;
      case 0x4Bu:
      case 0x5Du:
      case 0x76u:
      case 0x89u:
      case 0x90u:
      case 0x9Bu:
        goto LABEL_47;
      case 0x4Cu:
        v9 = D3DXShader::CParse::StructDecl(this, a2: nullptr, a3: (struct D3DXShader::CNode *)v68);
        goto LABEL_294;
      case 0x4Du:
        v9 = D3DXShader::CParse::StructDecl(this, a2: v70, a3: (struct D3DXShader::CNode *)v68);
        goto LABEL_294;
      case 0x4Fu:
        D3DXShader::CParse::ApplyUsage(
          this,
          a2: (struct D3DXShader::CNode *)v68,
          a3: *((struct D3DXShader::CNode ***)v68[2] + 6));
LABEL_47:
        v4 = v69;
        goto LABEL_57;
      case 0x50u:
        v67 = 0;
        v63 = 1;
        goto LABEL_124;
      case 0x53u:
      case 0x63u:
      case 0x8Bu:
      case 0x9Du:
        goto LABEL_125;
      case 0x54u:
      case 0x55u:
        v27 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v27 == nullptr )
          goto LABEL_10;
        v65 = "Semantics";
        goto LABEL_52;
      case 0x57u:
        v9 = D3DXShader::CNode::Append(a1: (struct D3DXShader::CNode *)v68, a2: v69);
        goto LABEL_294;
      case 0x5Au:
        v35 = D3DXShader::CNode::operator new(a1: 0x18u);
        if ( v35 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeRegister::CNodeRegister(
                                           this: (D3DXShader::CNodeRegister *)v35,
                                           a2: nullptr,
                                           a3: (struct D3DXShader::CNode *)v68);
        goto LABEL_294;
      case 0x5Bu:
        v36 = D3DXShader::CNode::operator new(a1: 0x18u);
        if ( v36 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeRegister::CNodeRegister(
                                           this: (D3DXShader::CNodeRegister *)v36,
                                           a2: (struct D3DXShader::CNode *)v68,
                                           a3: v69);
        goto LABEL_294;
      case 0x60u:
        v67 = 0;
        v63 = 5;
        goto LABEL_124;
      case 0x69u:
      case 0x7Bu:
        v4 = v69;
        goto LABEL_136;
      case 0x6Au:
        v4 = D3DXShader::CNode::Append(a1: (struct D3DXShader::CNode *)v68, a2: v69);
        goto LABEL_136;
      case 0x6Du:
        v9 = D3DXShader::CParse::VariableDecl(this, a2: v68, a3: v69, a4: v70, a5: v71);
        goto LABEL_294;
      case 0x6Fu:
        v27 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v27 == nullptr )
          goto LABEL_10;
        v65 = "VariableDim";
        goto LABEL_52;
      case 0x70u:
        v28 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v28 == nullptr )
          goto LABEL_10;
        v66 = "VariableDim";
        goto LABEL_222;
      case 0x71u:
        goto LABEL_157;
      case 0x72u:
        if ( v68 == nullptr )
          goto LABEL_157;
        v37 = v68[2];
        if ( v37 == nullptr )
          goto LABEL_157;
        v38 = *((_DWORD *)v37 + 6);
        *((_DWORD *)v37 + 7) = v69;
        *(_DWORD *)(v38 + 40) = v70;
        *(_DWORD *)(v38 + 60) = 1;
        v39 = *((struct D3DXShader::CNodeScope **)this + 4);
        v40 = (const char **)(*((_DWORD *)v37 + 5) + 16);
        break;
      case 0x73u:
        v4 = D3DXShader::CParse::FunctionDecl(
               this,
               a2: (const char **)v69,
               a3: (struct D3DXShader::CNode **)v70,
               a4: (struct D3DXShader::CNode **)v71);
        D3DXShader::CParse::NonNull(this, a2: v4);
LABEL_136:
        D3DXShader::CParse::PopUsageType(this);
        goto LABEL_57;
      case 0x77u:
        v67 = *((_DWORD *)this + 7);
        v63 = 2;
        goto LABEL_124;
      case 0x7Cu:
        v43 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v43 != nullptr )
        {
          v23 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                              this: (D3DXShader::CNodeUsage *)v43,
                                              a2: 0x10u,
                                              a3: nullptr,
                                              a4: (struct D3DXShader::CNode *)v68);
LABEL_162:
          v4 = v23;
        }
        else
        {
LABEL_40:
          v4 = nullptr;
        }
        D3DXShader::CParse::NonNull(this, a2: v4);
        goto LABEL_42;
      case 0x7Du:
        v4 = (struct D3DXShader::CNode *)v68;
        v68[6] = (const char *)v69;
        if ( (*((_BYTE *)v4 + 16) & 0x70) == 0 )
          *((_DWORD *)v4 + 4) |= 0x10u;
LABEL_42:
        D3DXShader::CParse::PushUsageType((struct D3DXShader::CNode **)this, a2: v4);
        goto LABEL_57;
      case 0x82u:
        v44 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v44 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v44,
                                           a2: 0x10u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x83u:
        v45 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v45 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v45,
                                           a2: 0x20u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x84u:
        v46 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v46 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v46,
                                           a2: 0x30u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x85u:
        v47 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v47 == nullptr )
          goto LABEL_10;
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeUsage::CNodeUsage(
                                           this: (D3DXShader::CNodeUsage *)v47,
                                           a2: 0x50u,
                                           a3: nullptr,
                                           a4: nullptr);
        goto LABEL_294;
      case 0x87u:
        v48 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v48 != nullptr )
          v4 = (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                             this: (D3DXShader::CNodeList *)v48,
                                             a2: nullptr,
                                             a3: nullptr,
                                             a4: "Stmts");
        else
          v4 = nullptr;
        if ( D3DXShader::CParse::NonNull(this, a2: v4) != nullptr )
        {
          v49 = D3DXShader::CNode::operator new(a1: 0x30u);
          if ( v49 != nullptr )
            v50 = (struct D3DXShader::CNode *)D3DXShader::CNodeDecl::CNodeDecl(
                                                a1: v49,
                                                a2: 3,
                                                a3: v68,
                                                a4: v70,
                                                a5: v69);
          else
            v50 = nullptr;
          *((_DWORD *)v4 + 2) = v50;
          D3DXShader::CParse::NonNull(this, a2: v50);
        }
        ++*((_DWORD *)this + 20);
        goto LABEL_57;
      case 0x8Au:
        D3DXShader::CParse::PushScope(this, a2: 6, a3: 0);
        goto LABEL_183;
      case 0x8Eu:
        v51 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v51 != nullptr )
          v4 = (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                             this: (D3DXShader::CNodeList *)v51,
                                             a2: nullptr,
                                             a3: nullptr,
                                             a4: "Passes");
        else
          v4 = nullptr;
        if ( D3DXShader::CParse::NonNull(this, a2: v4) == nullptr )
          goto LABEL_57;
        v52 = D3DXShader::CNode::operator new(a1: 0x30u);
        if ( v52 == nullptr )
          goto LABEL_198;
        v53 = (struct D3DXShader::CNode *)D3DXShader::CNodeDecl::CNodeDecl(a1: v52, a2: 4, a3: v68, a4: v70, a5: v69);
        goto LABEL_199;
      case 0x91u:
        D3DXShader::CParse::PushScope(this, a2: 7, a3: 0);
        *((_DWORD *)this + 18) = 0;
LABEL_183:
        v4 = nullptr;
        goto LABEL_57;
      case 0x92u:
        *((_DWORD *)this + 18) = 1;
LABEL_125:
        v4 = nullptr;
        goto LABEL_126;
      case 0x95u:
        v54 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v54 != nullptr )
          v4 = (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                             this: (D3DXShader::CNodeList *)v54,
                                             a2: nullptr,
                                             a3: nullptr,
                                             a4: "States");
        else
          v4 = nullptr;
        if ( D3DXShader::CParse::NonNull(this, a2: v4) == nullptr )
          goto LABEL_57;
        v55 = D3DXShader::CNode::operator new(a1: 0x1Cu);
        if ( v55 != nullptr )
          v53 = (struct D3DXShader::CNode *)D3DXShader::CNodeState::CNodeState(
                                              this: (D3DXShader::CNodeState *)v55,
                                              a2: (struct D3DXShader::CNode *)v68,
                                              a3: v69,
                                              a4: v71);
        else
LABEL_198:
          v53 = nullptr;
LABEL_199:
        *((_DWORD *)v4 + 2) = v53;
        D3DXShader::CParse::NonNull(this, a2: v53);
        goto LABEL_57;
      case 0x98u:
        *((_DWORD *)this + 18) = 1;
        goto LABEL_57;
      case 0x99u:
        *((_DWORD *)this + 18) = 0;
        goto LABEL_57;
      case 0x9Cu:
        v67 = 0;
        v63 = 3;
        goto LABEL_124;
      case 0xA1u:
      case 0xB4u:
        v11 = D3DXShader::CParse::Stmt(this, a2: (struct D3DXShader::CNode *)v68);
        goto LABEL_16;
      case 0xA2u:
        v11 = D3DXShader::CParse::ReturnStmt(this, a2: nullptr);
        goto LABEL_16;
      case 0xA3u:
        v11 = D3DXShader::CParse::ReturnStmt(this, a2: (struct D3DXShader::CNode *)v68);
        goto LABEL_16;
      case 0xA4u:
        v11 = D3DXShader::CParse::ForStmt(
                this,
                a2: (struct D3DXShader::CNode *)v68,
                a3: v69,
                a4: nullptr,
                a5: (struct D3DXShader::CNode *)v68);
        goto LABEL_16;
      case 0xA5u:
        v27 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v27 == nullptr )
          goto LABEL_10;
        v65 = "Stmts";
        goto LABEL_52;
      case 0xA6u:
        v11 = D3DXShader::CParse::DiscardStmt(this);
        goto LABEL_16;
      case 0xABu:
      case 0xAEu:
        v11 = D3DXShader::CParse::ForStmt(this, a2: nullptr, a3: (struct D3DXShader::CNode *)v68, a4: nullptr, a5: v69);
        goto LABEL_16;
      case 0xACu:
      case 0xAFu:
        v4 = D3DXShader::CParse::ForStmt(this, a2: v69, a3: v70, a4: v71, a5: v72);
LABEL_126:
        D3DXShader::CParse::PopScope(this);
        goto LABEL_57;
      case 0xB0u:
        v11 = D3DXShader::CParse::IfStmt(this, a2: (struct D3DXShader::CNode *)v68, a3: v69, a4: nullptr);
        goto LABEL_16;
      case 0xB1u:
        v11 = D3DXShader::CParse::IfStmt(this, a2: (struct D3DXShader::CNode *)v68, a3: v69, a4: v70);
        goto LABEL_16;
      case 0xB2u:
        v67 = 0;
        v63 = 4;
LABEL_124:
        v4 = nullptr;
        D3DXShader::CParse::PushScope(this, a2: v63, a3: v67);
        goto LABEL_57;
      case 0xBAu:
        v27 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v27 == nullptr )
          goto LABEL_10;
        v65 = "DwordExpr";
        goto LABEL_52;
      case 0xBBu:
        v28 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v28 == nullptr )
          goto LABEL_10;
        v66 = "DwordExpr";
LABEL_222:
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                           this: (D3DXShader::CNodeList *)v28,
                                           a2: (struct D3DXShader::CNode *)v68,
                                           a3: v69,
                                           a4: v66);
        goto LABEL_294;
      case 0xC1u:
        v9 = (struct D3DXShader::CNode *)D3DXShader::CParse::ScalarExpr(
                                           this,
                                           a2: 0,
                                           a3: 1,
                                           a4: COERCE_UNSIGNED_INT64(1.0),
                                           a5: HIDWORD(COERCE_UNSIGNED_INT64(1.0)),
                                           a6: (int)this + 32);
        goto LABEL_294;
      case 0xC2u:
        v9 = (struct D3DXShader::CNode *)D3DXShader::CParse::ScalarExpr(
                                           this,
                                           a2: 0,
                                           a3: 0,
                                           a4: COERCE_UNSIGNED_INT64(0.0),
                                           a5: HIDWORD(COERCE_UNSIGNED_INT64(0.0)),
                                           a6: (int)this + 32);
        goto LABEL_294;
      case 0xC3u:
      case 0xC4u:
        v9 = D3DXShader::CParse::ScalarExpr(this, a2: (struct D3DXShader::CNode *)v68);
        goto LABEL_294;
      case 0xC5u:
        v9 = D3DXShader::CParse::StringExpr(this, a2: (struct D3DXShader::CNode *)v68);
        goto LABEL_294;
      case 0xC6u:
        v9 = D3DXShader::CParse::VariableExpr(
               (struct D3DXShader::CNodeScope ***)this,
               a2: (struct D3DXShader::CNode *)v68,
               a3: nullptr);
        goto LABEL_294;
      case 0xC8u:
      case 0xC9u:
        v9 = D3DXShader::CParse::CastExpr(
               (struct D3DXShader::CNodeScope ***)this,
               a2: v68,
               a3: (struct D3DXShader::CNode **)v69,
               a4: 1,
               a5: 1);
        goto LABEL_294;
      case 0xCAu:
        v9 = D3DXShader::CParse::FunctionExpr(this, a2: (struct D3DXShader::CNode *)v68, a3: v69, a4: 0);
        goto LABEL_294;
      case 0xCBu:
        v11 = D3DXShader::CParse::ObjectExpr(this, a2: (struct D3DXShader::CNode *)v68);
        goto LABEL_16;
      case 0xCDu:
        v11 = D3DXShader::CParse::AsmExpr(this, a2: v69);
        goto LABEL_16;
      case 0xCEu:
      case 0xCFu:
        v11 = D3DXShader::CParse::AsmExpr(this, a2: (struct D3DXShader::CNode *)v68);
        goto LABEL_16;
      case 0xD0u:
        v11 = D3DXShader::CParse::CompileExpr(this, a2: (struct D3DXShader::CNode *)v68, a3: v69, a4: v70, a5: 0);
        goto LABEL_16;
      case 0xD1u:
        v9 = D3DXShader::CParse::SamplerExpr(this, a2: (struct D3DXShader::CNode *)v68);
        goto LABEL_294;
      case 0xD2u:
        v11 = D3DXShader::CParse::CompileExpr(this, a2: (struct D3DXShader::CNode *)v68, a3: v69, a4: v70, a5: 1);
        goto LABEL_16;
      case 0xD3u:
        v9 = D3DXShader::CParse::StateblockExpr(this, a2: (struct D3DXShader::CNode *)v68);
        goto LABEL_294;
      case 0xD7u:
        v9 = D3DXShader::CParse::ArrayExpr(this, a2: (struct D3DXShader::CNode *)v68, a3: v69);
        goto LABEL_294;
      case 0xD8u:
        v9 = D3DXShader::CParse::OffsetExpr(this, a2: (struct D3DXShader::CNode *)v68, a3: v69);
        goto LABEL_294;
      case 0xD9u:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x21u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: nullptr, a5: 1);
        goto LABEL_294;
      case 0xDAu:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x22u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: nullptr, a5: 1);
        goto LABEL_294;
      case 0xDCu:
        v9 = D3DXShader::CParse::Expr(this, a2: 2u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: nullptr, a5: 1);
        goto LABEL_294;
      case 0xDDu:
        v9 = D3DXShader::CParse::Expr(this, a2: 3u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: nullptr, a5: 1);
        goto LABEL_294;
      case 0xDEu:
        v9 = D3DXShader::CParse::Expr(this, a2: 4u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: nullptr, a5: 1);
        goto LABEL_294;
      case 0xDFu:
        v9 = D3DXShader::CParse::Expr(this, a2: 5u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: nullptr, a5: 1);
        goto LABEL_294;
      case 0xE0u:
        v9 = D3DXShader::CParse::Expr(this, a2: 6u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: nullptr, a5: 1);
        goto LABEL_294;
      case 0xE2u:
        v9 = D3DXShader::CParse::CastExpr(
               (struct D3DXShader::CNodeScope ***)this,
               a2: v68,
               a3: (struct D3DXShader::CNode **)v69,
               a4: 0,
               a5: 1);
        goto LABEL_294;
      case 0xE4u:
        v9 = D3DXShader::CParse::Expr(this, a2: 7u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xE5u:
        v9 = D3DXShader::CParse::Expr(this, a2: 8u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xE6u:
        v9 = D3DXShader::CParse::Expr(this, a2: 9u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xE8u:
        v9 = D3DXShader::CParse::Expr(this, a2: 0xAu, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xE9u:
        v9 = D3DXShader::CParse::Expr(this, a2: 0xBu, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xEBu:
        v9 = D3DXShader::CParse::Expr(this, a2: 0xCu, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xECu:
        v9 = D3DXShader::CParse::Expr(this, a2: 0xDu, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xEDu:
        v9 = D3DXShader::CParse::Expr(this, a2: 0xEu, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xEEu:
        v9 = D3DXShader::CParse::Expr(this, a2: 0xFu, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xF0u:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x10u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xF1u:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x11u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xF3u:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x12u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xF5u:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x13u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xF7u:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x15u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xF8u:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x1Cu, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xF9u:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x1Du, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xFAu:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x1Eu, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xFBu:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x1Fu, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xFCu:
        v9 = D3DXShader::CParse::Expr(this, a2: 0x20u, a3: (struct D3DXShader::D3DXTOKEN *)v68, a4: v69, a5: 1);
        goto LABEL_294;
      case 0xFEu:
        v9 = D3DXShader::CParse::ConditionalExpr(this, a2: (struct D3DXShader::CNode *)v68, a3: v69, a4: v70);
        goto LABEL_294;
      case 0xFFu:
        v27 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v27 == nullptr )
          goto LABEL_10;
        v65 = "Arguments";
        goto LABEL_52;
      case 0x100u:
        v56 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v56 != nullptr )
          v4 = (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                             this: (D3DXShader::CNodeList *)v56,
                                             a2: v69,
                                             a3: nullptr,
                                             a4: "Arguments");
        else
          v4 = nullptr;
        if ( D3DXShader::CParse::NonNull(this, a2: v4) == nullptr )
          goto LABEL_57;
        v11 = D3DXShader::CNode::Append(a1: (struct D3DXShader::CNode *)v68, a2: v4);
        goto LABEL_16;
      case 0x103u:
        v27 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v27 == nullptr )
          goto LABEL_10;
        v65 = "Value";
LABEL_52:
        v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeList::CNodeList(
                                           this: (D3DXShader::CNodeList *)v27,
                                           a2: (struct D3DXShader::CNode *)v68,
                                           a3: nullptr,
                                           a4: v65);
        goto LABEL_294;
      case 0x10Au:
        v57 = *((_DWORD *)this + 4);
        if ( v57 != 0 && *(_DWORD *)(v57 + 16) == 7 )
        {
          v58 = v69;
          if ( v69 == nullptr )
            v58 = (struct D3DXShader::CNode *)v68;
          D3DXShader::CParse::Warning(
            this,
            a2: (struct D3DXShader::CNode *)((char *)v58 + 48),
            a3: 0xC09u,
            format: "comma expression used where an initializer list may have been intended");
        }
        v9 = D3DXShader::CParse::Expr(this, a2: 1u, a3: v69, a4: v68, a5: 0);
        goto LABEL_294;
      case 0x10Cu:
        v4 = (struct D3DXShader::CNode *)v68;
        v68[6] = (const char *)-(int)v68[6];
        goto LABEL_57;
      case 0x10Eu:
        v4 = (struct D3DXShader::CNode *)v68;
        *((double *)v68 + 3) = -*((double *)v68 + 3);
        goto LABEL_57;
      case 0x110u:
        v11 = D3DXShader::CParse::CombineUintId((D3DXCore::CAlloc **)this, a2: (struct D3DXShader::CNode *)v68, a3: v69);
        goto LABEL_16;
      case 0x112u:
      case 0x113u:
      case 0x114u:
      case 0x11Au:
      case 0x11Bu:
      case 0x11Cu:
      case 0x11Du:
      case 0x11Eu:
      case 0x11Fu:
      case 0x120u:
      case 0x123u:
      case 0x124u:
      case 0x125u:
        v59 = D3DXShader::CNode::operator new(a1: 0x30u);
        if ( v59 != nullptr )
        {
          v9 = (struct D3DXShader::CNode *)D3DXShader::CNodeToken::CNodeToken(
                                             this: (D3DXShader::CNodeToken *)v59,
                                             a2: (D3DXShader::CParse *)((char *)this + 32));
LABEL_294:
          v4 = v9;
        }
        else
        {
LABEL_10:
          v4 = nullptr;
        }
        D3DXShader::CParse::NonNull(this, a2: v4);
        goto LABEL_57;
      case 0x115u:
      case 0x116u:
        v4 = (struct D3DXShader::CNode *)v68;
        *((_DWORD *)this + 7) = v68[6];
        goto LABEL_57;
      case 0x122u:
        v11 = D3DXShader::CParse::CombineStrings(
                (D3DXCore::CAlloc **)this,
                a2: (struct D3DXShader::CNode *)v68,
                a3: v69);
        goto LABEL_16;
      case 0x126u:
        v11 = D3DXShader::CParse::AsmDecl((D3DXShader::CPreProcessor **)this);
        goto LABEL_16;
      case 0x127u:
        v11 = D3DXShader::CParse::AsmBlock((struct D3DXShader::CPreProcessor **)this, a2: 0);
        goto LABEL_16;
      case 0x128u:
        v11 = D3DXShader::CParse::AsmBlock((struct D3DXShader::CPreProcessor **)this, a2: 1u);
LABEL_16:
        v4 = v11;
        goto LABEL_57;
      default:
        D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: unhandled production");
        goto LABEL_57;
    }
    while ( 1 )
    {
      v76 = v39;
      if ( v39 == nullptr )
        break;
      Decls = D3DXShader::CParse::FindDecls(this, a2: v40, a3: v39);
      v75 = (unsigned int)Decls;
      if ( Decls != nullptr )
      {
        while ( 1 )
        {
          v42 = *((_DWORD *)Decls + 2);
          if ( v42 != 0 && *(_DWORD *)(v42 + 4) == 6 && *(_DWORD *)(v42 + 36) == *((_DWORD *)v37 + 9) )
            break;
          Decls = *((struct D3DXShader::CNode **)Decls + 3);
          v75 = (unsigned int)Decls;
          if ( Decls == nullptr )
            goto LABEL_151;
        }
        if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)Decls + 2) + 24) + 60) != 0 )
        {
          D3DXShader::CParse::Error(
            this,
            a2: (struct D3DXShader::D3DXTOKEN *)v40,
            a3: 0xBFDu,
            format: "'%s' already has a body",
            v40[2]);
          Decls = (struct D3DXShader::CNode *)v75;
        }
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)Decls + 2) + 24) + 60) = 1;
        break;
      }
LABEL_151:
      v39 = *((struct D3DXShader::CNodeScope **)v76 + 8);
    }
LABEL_157:
    v4 = (struct D3DXShader::CNode *)v68;
    D3DXShader::CParse::PopScope(this);
    *((_DWORD *)this + 6) = 0;
LABEL_57:
    if ( *((_DWORD *)this + 17) == 0 )
    {
      v29 = *((_DWORD *)this + 3);
      if ( v29 != 0 )
      {
        *((_DWORD *)this + 3) = *(_DWORD *)(v29 + 12);
        *(_DWORD *)(v29 + 8) = v4;
        *(_DWORD *)(v29 + 12) = *((_DWORD *)this + 2);
      }
      else
      {
        v60 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v60 != nullptr )
          v29 = D3DXShader::CNodeList::CNodeList(
                  this: (D3DXShader::CNodeList *)v60,
                  a2: v4,
                  a3: *((struct D3DXShader::CNode **)this + 2),
                  a4: "Stack");
        else
          v29 = 0;
        if ( v29 == 0 )
        {
          D3DXShader::CParse::FatalError(this, a2: nullptr, a3: 0, format: "internal error: out of memory");
          return;
        }
      }
      *((_DWORD *)this + 2) = v29;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE4BC
// Name: int D3DXShader::d3dxshader_parse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int D3DXShader::d3dxshader_parse()
{
  int v0; // eax
  int v1; // esi
  int v2; // ecx
  unsigned int v3; // ecx
  int v4; // ecx
  __int16 *v5; // eax
  unsigned int v6; // ecx
  int v7; // ecx
  int v8; // esi
  __int16 *v9; // eax
  int v10; // edx
  int v11; // ecx
  bool v12; // zf
  int v14; // esi
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // eax
  __int16 *i; // ecx
  unsigned int v20; // eax
  int v21; // [esp+Ch] [ebp-8h]

  v0 = -1;
  v1 = 0;
  D3DXShader::d3dxshader_nerrs = 0;
  D3DXShader::d3dxshader_errflag = 0;
  D3DXShader::d3dxshader_ssp = (__int16 *)&D3DXShader::d3dxshader_ss;
  D3DXShader::d3dxshader_vsp = (int *)&D3DXShader::d3dxshader_vs;
  LOWORD(D3DXShader::d3dxshader_ss) = 0;
  while ( 2 )
  {
    D3DXShader::d3dxshader_char = -1;
    while ( 1 )
    {
      while ( 1 )
      {
        v2 = *((__int16 *)&D3DXShader::d3dxshader_defred + v1);
        if ( *((_WORD *)&D3DXShader::d3dxshader_defred + v1) == 0 )
          break;
LABEL_17:
        v8 = *((__int16 *)&D3DXShader::d3dxshader_len + v2);
        v21 = 2 * v2;
        D3DXShader::d3dxshader_val = D3DXShader::d3dxshader_vsp[-v8 + 1];
        switch ( v2 )
        {
          case 1:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0, a3: nullptr);
            break;
          case 2:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 1u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 3:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 2u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 4:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 3u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 5:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 4u, a3: nullptr);
            break;
          case 6:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 5u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 7:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 6u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 8:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 7u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 9:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 8u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 10:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 9u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 11:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xAu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 12:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xBu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 13:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xCu, a3: nullptr);
            break;
          case 14:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xDu, a3: nullptr);
            break;
          case 15:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xEu, a3: nullptr);
            break;
          case 16:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xFu, a3: nullptr);
            break;
          case 17:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x10u, a3: nullptr);
            break;
          case 18:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x11u, a3: nullptr);
            break;
          case 19:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x12u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 20:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x13u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 21:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x14u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 22:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x15u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 23:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x16u, a3: nullptr);
            break;
          case 24:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x17u, a3: nullptr);
            break;
          case 25:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x18u, a3: nullptr);
            break;
          case 26:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x19u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 27:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x1Au,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 28:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x1Du,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 29:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x1Eu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 30:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x1Fu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 31:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x20u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 32:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x21u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 33:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x22u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 34:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x23u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 35:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x24u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 36:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x25u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 37:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x26u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 38:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x27u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 39:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x28u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 40:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x29u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 41:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x2Au,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 42:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x2Bu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 43:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x2Cu, a3: nullptr);
            break;
          case 44:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x2Du,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 45:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x2Eu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 46:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x2Fu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 47:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x30u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 48:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x31u, a3: nullptr);
            break;
          case 49:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x32u, a3: nullptr);
            break;
          case 50:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x33u, a3: nullptr);
            break;
          case 51:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x34u, a3: nullptr);
            break;
          case 52:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x35u, a3: nullptr);
            break;
          case 53:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x36u, a3: nullptr);
            break;
          case 54:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x37u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 55:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x38u, a3: nullptr);
            break;
          case 56:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x39u,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 57:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x3Au, a3: nullptr);
            break;
          case 58:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x3Bu, a3: nullptr);
            break;
          case 59:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x3Cu, a3: nullptr);
            break;
          case 60:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x3Du, a3: nullptr);
            break;
          case 61:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x3Eu, a3: nullptr);
            break;
          case 62:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x3Fu, a3: nullptr);
            break;
          case 63:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x40u, a3: nullptr);
            break;
          case 64:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x41u, a3: nullptr);
            break;
          case 65:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x42u, a3: nullptr);
            break;
          case 66:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x43u, a3: nullptr);
            break;
          case 67:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x44u, a3: nullptr);
            break;
          case 68:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x45u, a3: nullptr);
            break;
          case 69:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x46u, a3: nullptr);
            break;
          case 70:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x47u, a3: nullptr);
            break;
          case 71:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x48u, a3: nullptr);
            break;
          case 72:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x49u, a3: nullptr);
            break;
          case 73:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x4Au,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 74:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x4Bu,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 75:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x4Cu,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 76:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x4Du,
              a3: (struct D3DXShader::CNodeScope *)4);
            break;
          case 77:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x4Eu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 78:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x4Fu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 79:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x50u, a3: nullptr);
            break;
          case 80:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x51u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 81:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x52u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 82:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x53u, a3: nullptr);
            break;
          case 83:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x54u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 84:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x55u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 85:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x56u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 86:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x57u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 87:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x58u, a3: nullptr);
            break;
          case 88:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x59u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 89:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x5Au,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 90:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x5Bu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 91:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x5Cu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 92:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x5Du,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 93:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x5Eu, a3: nullptr);
            break;
          case 94:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x5Fu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 95:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x60u, a3: nullptr);
            break;
          case 96:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x61u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 97:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x62u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 98:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x63u, a3: nullptr);
            break;
          case 99:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x64u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 100:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x65u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 101:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x66u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 102:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x67u, a3: nullptr);
            break;
          case 103:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x68u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 104:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x69u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 105:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x6Au,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 106:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x6Bu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 107:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x6Cu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 108:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x6Du,
              a3: (struct D3DXShader::CNodeScope *)4);
            break;
          case 109:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x6Eu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 110:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x6Fu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 111:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x70u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 112:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x71u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 113:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x72u,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 114:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x73u,
              a3: (struct D3DXShader::CNodeScope *)4);
            break;
          case 115:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x74u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 116:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x75u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 117:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x76u,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 118:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x77u, a3: nullptr);
            break;
          case 119:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x78u, a3: nullptr);
            break;
          case 120:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x79u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 121:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x7Au,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 122:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x7Bu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 123:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x7Cu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 124:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x7Du,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 125:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x80u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 126:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x81u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 127:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x82u, a3: nullptr);
            break;
          case 128:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x83u, a3: nullptr);
            break;
          case 129:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x84u, a3: nullptr);
            break;
          case 130:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x85u, a3: nullptr);
            break;
          case 131:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x86u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 132:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x87u,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 133:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x88u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 134:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x89u,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 135:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x8Au, a3: nullptr);
            break;
          case 136:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x8Bu, a3: nullptr);
            break;
          case 137:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x8Cu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 138:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x8Du,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 139:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x8Eu,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 140:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x8Fu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 141:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x90u,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 142:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x91u, a3: nullptr);
            break;
          case 143:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x92u, a3: nullptr);
            break;
          case 144:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x93u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 145:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x94u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 146:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x95u,
              a3: (struct D3DXShader::CNodeScope *)5);
            break;
          case 147:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x96u, a3: nullptr);
            break;
          case 148:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x97u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 149:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x98u, a3: nullptr);
            break;
          case 150:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x99u, a3: nullptr);
            break;
          case 151:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x9Au,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 152:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x9Bu,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 153:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x9Cu, a3: nullptr);
            break;
          case 154:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x9Du, a3: nullptr);
            break;
          case 155:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x9Eu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 156:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x9Fu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 157:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xA0u, a3: nullptr);
            break;
          case 158:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xA1u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 159:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xA2u, a3: nullptr);
            break;
          case 160:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xA3u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 161:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xA4u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 162:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xA5u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 163:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xA6u, a3: nullptr);
            break;
          case 164:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xA7u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 165:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xA8u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 166:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xA9u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 167:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xAAu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 168:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xABu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 169:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xACu,
              a3: (struct D3DXShader::CNodeScope *)5);
            break;
          case 170:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xADu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 171:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xAEu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 172:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xAFu,
              a3: (struct D3DXShader::CNodeScope *)5);
            break;
          case 173:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xB0u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 174:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xB1u,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 175:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xB2u, a3: nullptr);
            break;
          case 176:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xB3u, a3: nullptr);
            break;
          case 177:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xB4u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 178:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xB5u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 179:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xB6u, a3: nullptr);
            break;
          case 180:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xB7u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 181:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xB8u, a3: nullptr);
            break;
          case 182:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xB9u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 183:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xBAu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 184:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xBBu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 185:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xBCu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 186:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xBDu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 187:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xBEu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 188:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xBFu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 189:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xC0u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 190:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xC1u, a3: nullptr);
            break;
          case 191:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0xC2u, a3: nullptr);
            break;
          case 192:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xC3u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 193:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xC4u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 194:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xC5u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 195:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xC6u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 196:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xC7u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 197:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xC8u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 198:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xC9u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 199:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xCAu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 200:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xCBu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 201:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xCCu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 202:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xCDu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 203:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xCEu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 204:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xCFu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 205:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xD0u,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 206:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xD1u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 207:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xD2u,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 208:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xD3u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 209:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xD4u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 210:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xD5u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 211:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xD6u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 212:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xD7u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 213:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xD8u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 214:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xD9u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 215:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xDAu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 216:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xDBu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 217:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xDCu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 218:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xDDu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 219:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xDEu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 220:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xDFu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 221:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xE0u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 222:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xE1u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 223:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xE2u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 224:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xE3u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 225:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xE4u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 226:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xE5u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 227:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xE6u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 228:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xE7u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 229:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xE8u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 230:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xE9u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 231:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xEAu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 232:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xEBu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 233:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xECu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 234:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xEDu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 235:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xEEu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 236:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xEFu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 237:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xF0u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 238:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xF1u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 239:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xF2u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 240:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xF3u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 241:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xF4u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 242:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xF5u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 243:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xFDu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 244:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xFEu,
              a3: (struct D3DXShader::CNodeScope *)3);
            break;
          case 245:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xF6u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 246:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xF7u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 247:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xF8u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 248:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xF9u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 249:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xFAu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 250:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xFBu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 251:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xFCu,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 252:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0xFFu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 253:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x100u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 254:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x101u, a3: nullptr);
            break;
          case 255:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x102u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 256:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x103u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 257:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x104u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 258:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x105u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 259:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x106u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 260:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x107u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 261:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x108u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 262:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x109u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 263:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x10Au,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 264:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x10Bu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 265:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x10Cu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 266:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x10Du,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 267:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x10Eu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 268:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x10Fu,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 269:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x110u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 270:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x111u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 271:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x112u, a3: nullptr);
            break;
          case 272:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x113u, a3: nullptr);
            break;
          case 273:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x114u, a3: nullptr);
            break;
          case 274:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x115u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 275:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x116u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 276:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x117u, a3: nullptr);
            break;
          case 277:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x118u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 278:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x119u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 279:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x11Au, a3: nullptr);
            break;
          case 280:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x11Bu, a3: nullptr);
            break;
          case 281:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x11Cu, a3: nullptr);
            break;
          case 282:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x11Du, a3: nullptr);
            break;
          case 283:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x11Eu, a3: nullptr);
            break;
          case 284:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x11Fu, a3: nullptr);
            break;
          case 285:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x120u, a3: nullptr);
            break;
          case 286:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x121u,
              a3: (struct D3DXShader::CNodeScope *)1);
            break;
          case 287:
            D3DXShader::CParse::Production(
              this: D3DXShader::CParse::s_pParse,
              a2: 0x122u,
              a3: (struct D3DXShader::CNodeScope *)2);
            break;
          case 288:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x123u, a3: nullptr);
            break;
          case 289:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x124u, a3: nullptr);
            break;
          case 290:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x125u, a3: nullptr);
            break;
          case 291:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x126u, a3: nullptr);
            break;
          case 292:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x127u, a3: nullptr);
            break;
          case 293:
            D3DXShader::CParse::Production(this: D3DXShader::CParse::s_pParse, a2: 0x128u, a3: nullptr);
            break;
          default:
            break;
        }
        v9 = &D3DXShader::d3dxshader_ssp[-v8];
        D3DXShader::d3dxshader_ssp = v9;
        v10 = *v9;
        D3DXShader::d3dxshader_vsp -= v8;
        v11 = *(__int16 *)((char *)&D3DXShader::d3dxshader_lhs + v21);
        if ( v10 != 0 || *(_WORD *)((char *)&D3DXShader::d3dxshader_lhs + v21) != 0 )
        {
          v14 = 2 * v11;
          v15 = *((__int16 *)&D3DXShader::d3dxshader_gindex + v11);
          if ( v15 != 0
            && (unsigned int)(v16 = v10 + v15) <= 0xD88
            && (v17 = 2 * v16, *(__int16 *)((char *)&D3DXShader::d3dxshader_check + v17) == v10) )
          {
            v1 = *(__int16 *)((char *)&D3DXShader::d3dxshader_table + v17);
          }
          else
          {
            v1 = *(__int16 *)((char *)&D3DXShader::d3dxshader_dgoto + v14);
          }
          if ( v9 >= &word_1035BD96 )
            goto LABEL_339;
          D3DXShader::d3dxshader_ssp = v9 + 1;
          v9[1] = v1;
          v18 = D3DXShader::d3dxshader_val;
LABEL_336:
          *++D3DXShader::d3dxshader_vsp = v18;
          v0 = D3DXShader::d3dxshader_char;
        }
        else
        {
          D3DXShader::d3dxshader_ssp = v9 + 1;
          v1 = 40;
          v9[1] = 40;
          *++D3DXShader::d3dxshader_vsp = D3DXShader::d3dxshader_val;
          v0 = D3DXShader::d3dxshader_char;
          v12 = D3DXShader::d3dxshader_char == 0;
          if ( D3DXShader::d3dxshader_char < 0 )
          {
            v0 = D3DXShader::CParse::Token(this: D3DXShader::CParse::s_pParse);
            v12 = v0 == 0;
            D3DXShader::d3dxshader_char = v0;
            if ( v0 < 0 )
            {
              v0 = 0;
              D3DXShader::d3dxshader_char = 0;
              v12 = true;
            }
          }
          if ( v12 )
            return 0;
        }
      }
      if ( v0 < 0 )
      {
        v0 = D3DXShader::CParse::Token(this: D3DXShader::CParse::s_pParse);
        D3DXShader::d3dxshader_char = v0;
        if ( v0 < 0 )
        {
          v0 = 0;
          D3DXShader::d3dxshader_char = 0;
        }
      }
      if ( *((_WORD *)&D3DXShader::d3dxshader_sindex + v1) == 0 )
        break;
      v3 = v0 + *((__int16 *)&D3DXShader::d3dxshader_sindex + v1);
      if ( v3 > 0xD88 )
        break;
      v4 = 2 * v3;
      if ( *(__int16 *)((char *)&D3DXShader::d3dxshader_check + v4) != v0 )
        break;
      v5 = D3DXShader::d3dxshader_ssp;
      if ( D3DXShader::d3dxshader_ssp >= &word_1035BD96 )
        goto LABEL_339;
      v1 = *(__int16 *)((char *)&D3DXShader::d3dxshader_table + v4);
      ++D3DXShader::d3dxshader_ssp;
      v5[1] = v1;
      *++D3DXShader::d3dxshader_vsp = D3DXShader::d3dxshader_lval;
      v0 = -1;
      D3DXShader::d3dxshader_char = -1;
      if ( D3DXShader::d3dxshader_errflag > 0 )
        --D3DXShader::d3dxshader_errflag;
    }
    if ( *((_WORD *)&D3DXShader::d3dxshader_rindex + v1) != 0 )
    {
      v6 = v0 + *((__int16 *)&D3DXShader::d3dxshader_rindex + v1);
      if ( v6 <= 0xD88 )
      {
        v7 = 2 * v6;
        if ( *(__int16 *)((char *)&D3DXShader::d3dxshader_check + v7) == v0 )
        {
          v2 = *(__int16 *)((char *)&D3DXShader::d3dxshader_table + v7);
          goto LABEL_17;
        }
      }
    }
    if ( D3DXShader::d3dxshader_errflag == 0 )
    {
      D3DXShader::CParse::Error(this: D3DXShader::CParse::s_pParse, format: "syntax error");
      ++D3DXShader::d3dxshader_nerrs;
      v0 = D3DXShader::d3dxshader_char;
    }
    if ( D3DXShader::d3dxshader_errflag >= 3 )
    {
      if ( v0 == 0 )
        return 1;
      v0 = -1;
      continue;
    }
    break;
  }
  D3DXShader::d3dxshader_errflag = 3;
  for ( i = D3DXShader::d3dxshader_ssp; ; D3DXShader::d3dxshader_ssp = i )
  {
    if ( *((_WORD *)&D3DXShader::d3dxshader_sindex + *i) != 0 )
    {
      v20 = *((__int16 *)&D3DXShader::d3dxshader_sindex + *i) + 256;
      if ( v20 <= 0xD88 && *((_WORD *)&D3DXShader::d3dxshader_check + v20) == 256 )
        break;
    }
    if ( i <= (__int16 *)&D3DXShader::d3dxshader_ss )
      return 1;
    --i;
    --D3DXShader::d3dxshader_vsp;
  }
  if ( i < &word_1035BD96 )
  {
    v1 = *((__int16 *)&D3DXShader::d3dxshader_table + v20);
    D3DXShader::d3dxshader_ssp = i + 1;
    i[1] = v1;
    v18 = D3DXShader::d3dxshader_lval;
    goto LABEL_336;
  }
LABEL_339:
  D3DXShader::CParse::Error(this: D3DXShader::CParse::s_pParse, format: "yacc stack overflow");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101FF7BB
// Name: public: long D3DXShader::CParse::Parse(class D3DXShader::CPreProcessor __near *,unsigned long,class D3DXShader::CNode __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CParse::Parse(
        D3DXShader::CParse *this,
        struct D3DXShader::CPreProcessor *a2,
        unsigned int a3,
        struct D3DXShader::CNode **a4)
{
  int result; // eax

  if ( a4 == nullptr )
    return -2005530516;
  *a4 = nullptr;
  *(_DWORD *)this = a3;
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 1;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  D3DXShader::CParse::s_pParse = this;
  result = D3DXShader::CPreProcessor::Begin(this: *((D3DXShader::CPreProcessor **)this + 1), a2: 1u);
  if ( result >= 0 )
  {
    D3DXShader::CParse::PushScope(this, a2: 0, a3: 0);
    if ( D3DXShader::d3dxshader_parse() != 0 )
      *((_DWORD *)this + 16) = 1;
    result = D3DXShader::CPreProcessor::End(this: *((D3DXShader::CPreProcessor **)this + 1));
    if ( result >= 0 )
    {
      if ( *((_DWORD *)this + 16) == 0 )
      {
        *a4 = *(struct D3DXShader::CNode **)(*((_DWORD *)this + 2) + 8);
        *(_DWORD *)(*((_DWORD *)this + 2) + 8) = 0;
      }
      return *((_DWORD *)this + 16) != 0 ? 0x80004005 : 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FF869
// Name: public: D3DXShader::C30Program::C30Program(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::C30Program *__thiscall D3DXShader::C30Program::C30Program(D3DXShader::C30Program *this, int a2)
{
  D3DXShader::CShaderProgram::CShaderProgram(this);
  *((_DWORD *)this + 86) = a2;
  *(_DWORD *)this = &D3DXShader::C30Program::`vftable';
  *((_DWORD *)this + 60) = &D3DXShader::g_30VertexInputSemantic;
  *((_DWORD *)this + 61) = &D3DXShader::g_30InputOutput;
  *((_DWORD *)this + 62) = &D3DXShader::g_30PSOutput;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FF8AA
// Name: protected: virtual long D3DXShader::C30Program::InitCaps(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::InitCaps(D3DXShader::C30Program *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 50);
  *((_DWORD *)this + 66) = v1;
  if ( v1 == -130304 )
  {
    *((_DWORD *)this + 27) |= 0x40200100u;
    *((_WORD *)this + 56) |= 0xFE4u;
    *((_DWORD *)this + 12) = 1;
    *((_DWORD *)this + 19) = 4;
LABEL_9:
    *((_DWORD *)this + 24) = 16;
    *((_DWORD *)this + 16) = 16;
    *((_DWORD *)this + 21) = 8;
    *((_DWORD *)this + 23) = 4;
    goto LABEL_10;
  }
  if ( v1 != -130049 )
  {
    if ( v1 != -64768 && v1 != -64513 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: nullptr,
        a3: 0,
        format: "internal error: no profile exists for this shader version");
      return -2147467259;
    }
    *((_DWORD *)this + 12) = 0;
    *((_DWORD *)this + 27) |= 0x402001A0u;
    *((_WORD *)this + 56) |= 0x534u;
    *((_DWORD *)this + 18) = 4;
    *((_DWORD *)this + 19) = 16;
    goto LABEL_9;
  }
  *((_DWORD *)this + 27) |= 0x40200100u;
  *((_WORD *)this + 56) |= 0xFE4u;
  *((_DWORD *)this + 12) = 1;
  *((_DWORD *)this + 24) = 2048;
  *((_DWORD *)this + 16) = 2048;
  *((_DWORD *)this + 21) = 16;
  *((_DWORD *)this + 23) = 4;
  *((_DWORD *)this + 19) = 16;
LABEL_10:
  *((_BYTE *)this + 113) |= 0x10u;
  *((_DWORD *)this + 10) = 16;
  *((_DWORD *)this + 17) = 16;
  *((_DWORD *)this + 11) = 32;
  *((_DWORD *)this + 14) = 0x2000;
  *((_DWORD *)this + 26) = 255;
  *((_DWORD *)this + 25) = 1;
  *((_DWORD *)this + 22) = 24;
  *((_DWORD *)this + 116) = 32;
  *((_DWORD *)this + 85) = 1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FF9B1
// Name: protected: virtual long D3DXShader::C30Program::ValidateOutput(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::ValidateOutput(D3DXShader::C30Program *this)
{
  int result; // eax
  bool v3; // zf
  _DWORD *v4; // edi
  int v5; // ebx
  int v6; // eax
  int v7; // ecx
  unsigned int k; // eax
  int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  unsigned int i; // edi
  int v14; // ecx
  struct D3DXShader::CNode **v15; // eax
  int j; // edx
  int v17; // ebx
  int v18; // [esp-Ch] [ebp-70h]
  struct D3DXShader::CNode *v19[16]; // [esp+4h] [ebp-60h] BYREF
  struct D3DXShader::CNode *v20; // [esp+44h] [ebp-20h]
  int v21; // [esp+48h] [ebp-1Ch]
  int v22; // [esp+4Ch] [ebp-18h]
  int v23; // [esp+50h] [ebp-14h]
  int v24; // [esp+54h] [ebp-10h]
  int v25; // [esp+58h] [ebp-Ch]
  unsigned int v26; // [esp+5Ch] [ebp-8h]
  int v27; // [esp+60h] [ebp-4h]

  result = 0;
  if ( *((_DWORD *)this + 86) == 0 )
  {
    v3 = (*((_BYTE *)this + 112) & 0x40) == 0;
    v27 = 0;
    v26 = 0;
    v24 = 0;
    if ( v3 )
    {
      memset(v19, 0, sizeof(v19));
      v20 = nullptr;
      v21 = 0;
      v22 = 0;
      v3 = *((_DWORD *)this + 2) == 0;
      v23 = 0;
      if ( !v3 )
      {
        do
        {
          v9 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v26);
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v9 + 4)) + 4) & 0x20) != 0 )
          {
            v10 = (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 84))(
                    a1: this,
                    a2: *(_DWORD *)(v9 + 108));
            v18 = *(_DWORD *)(v9 + 108);
            v25 = v10;
            v11 = (*(int (__thiscall **)(D3DXShader::C30Program *, int))(*(_DWORD *)this + 88))(a1: this, a2: v18);
            if ( v25 == 11 )
            {
              if ( v11 < 4 )
              {
                v12 = 4 * v11;
                *(&v19[v12] + *(_DWORD *)(v9 + 16)) = (struct D3DXShader::CNode *)1;
                *(struct D3DXShader::CNode **)((char *)&v20 + v12) = *(struct D3DXShader::CNode **)(v9 + 96);
              }
            }
            else if ( v25 == 13 && v11 == 0 && *(_DWORD *)(v9 + 16) != 0 && v24 == 0 )
            {
              D3DXShader::CProgram::Error(
                this,
                a2: *(struct D3DXShader::CNode **)(v9 + 96),
                a3: 0x11B0u,
                format: "DEPTH must be a scalar");
              v24 = 1;
              v27 = 1;
            }
          }
          ++v26;
        }
        while ( v26 < *((_DWORD *)this + 2) );
      }
      v24 = 0;
      v25 = 1;
      for ( i = 0; i < 4; ++i )
      {
        v14 = 0;
        v15 = &v19[4 * i];
        for ( j = 4; j != 0; --j )
        {
          v17 = *v15++ != nullptr;
          v14 += v17;
        }
        if ( v14 != 0 )
        {
          if ( v14 != 4 )
          {
            D3DXShader::CProgram::Error(
              this,
              a2: *(&v20 + i),
              a3: 0x11B1u,
              format: "COLOR%d must be a four-component vector",
              i);
            v27 = 1;
          }
          if ( v24 != 0 )
            v25 = 0;
        }
        else
        {
          if ( i == 0 )
          {
            D3DXShader::CProgram::Error(
              this,
              a2: v20,
              a3: 0x11B2u,
              format: "pixel shader must minimally write all four components of COLOR0");
            v27 = 1;
          }
          v24 = 1;
        }
      }
      if ( v25 != 0 )
        return v27 != 0 ? 0x80004005 : 0;
      D3DXShader::CProgram::Error(
        this,
        a2: nullptr,
        a3: 0x11BAu,
        format: "COLOR outputs must be contiguous from COLOR0 to COLORn");
    }
    else
    {
      v3 = *((_DWORD *)this + 2) == 0;
      v20 = nullptr;
      v21 = 0;
      v22 = 0;
      v25 = 0;
      v23 = 0;
      if ( !v3 )
      {
        do
        {
          v4 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v26);
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v4[1]) + 4) & 0x20) != 0 )
          {
            v5 = (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 84))(a1: this, a2: v4[27]);
            v6 = (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 88))(a1: this, a2: v4[27]);
            if ( v5 == 1 )
            {
              if ( v6 == 0 )
              {
                *(&v20 + v4[4]) = (struct D3DXShader::CNode *)1;
                v24 = v4[24];
              }
            }
            else if ( v5 == 5 && v6 == 0 && v4[4] != 0 && v25 == 0 )
            {
              D3DXShader::CProgram::Error(
                this,
                a2: (struct D3DXShader::CNode *)v4[24],
                a3: 0x11BCu,
                format: "PSIZE must be a scalar");
              v25 = 1;
              v27 = 1;
            }
          }
          ++v26;
        }
        while ( v26 < *((_DWORD *)this + 2) );
      }
      v7 = 0;
      for ( k = 0; k < 4; ++k )
      {
        if ( *(&v20 + k) != nullptr )
          ++v7;
      }
      if ( v7 == 4 )
        return v27 != 0 ? 0x80004005 : 0;
      D3DXShader::CProgram::Error(
        this,
        a2: (struct D3DXShader::CNode *)v24,
        a3: 0x11BDu,
        format: "vertex shader must minimally write all four components of POSITION");
    }
    v27 = 1;
    return v27 != 0 ? 0x80004005 : 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FFC14
// Name: protected: virtual long D3DXShader::C30Program::FindOutput(class D3DXShader::CArgument __near *,unsigned long __near &,unsigned long __near &,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::FindOutput(
        D3DXShader::C30Program *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4,
        int *a5)
{
  int v6; // ebx
  unsigned int v7; // eax
  int v8; // edi

  v6 = (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 84))(
         a1: this,
         a2: *((_DWORD *)a2 + 27));
  v7 = (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 88))(
         a1: this,
         a2: *((_DWORD *)a2 + 27));
  *a3 = v7;
  if ( (*((_BYTE *)this + 112) & 0x40) != 0 )
  {
    if ( a5 != nullptr )
      *a5 = 0;
    if ( v6 == 5 )
    {
      if ( *a3 != 0 || a5 == nullptr )
        goto LABEL_10;
      *a5 = 1;
    }
    if ( v6 == 0xFFFF )
    {
      *a4 = 0;
      return 0;
    }
LABEL_10:
    *a4 = 6;
    *a3 = *((_DWORD *)a2 + 3);
    return 0;
  }
  v8 = 0;
  if ( v6 != 11 )
  {
    switch ( v6 )
    {
      case 0xD:
        if ( v7 != 0 )
          return -2147467259;
        v8 = 1;
        *a4 = 9;
        break;
      case 0x11:
        if ( v7 != 0 )
          return -2147467259;
        *a4 = 17;
        *a3 = 1;
        break;
      case 0x12:
        if ( v7 != 0 )
          return -2147467259;
        *a4 = 17;
        *a3 = 0;
        break;
      case 0xFFFF:
        *a4 = 0;
        v8 = 0;
        break;
      default:
        return -2147467259;
    }
LABEL_25:
    if ( a5 != nullptr )
      *a5 = v8;
    return 0;
  }
  if ( v7 < 4 )
  {
    *a4 = 8;
    goto LABEL_25;
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x101FFD02
// Name: protected: virtual long D3DXShader::C30Program::FindInput(class D3DXShader::CArgument __near *,unsigned long __near &,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::FindInput(
        D3DXShader::C30Program *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  int v5; // eax
  unsigned int v6; // eax

  v5 = (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 84))(
         a1: this,
         a2: *((_DWORD *)a2 + 27));
  switch ( v5 )
  {
    case 0xFFFF:
      *a4 = 0;
      v6 = (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 88))(
             a1: this,
             a2: *((_DWORD *)a2 + 27));
LABEL_8:
      *a3 = v6;
      return 0;
    case 0x11:
      *a4 = 17;
      *a3 = 1;
      break;
    case 0x12:
      *a4 = 17;
      *a3 = 0;
      break;
    default:
      *a4 = 1;
      v6 = *((_DWORD *)a2 + 3);
      goto LABEL_8;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FFD6E
// Name: public: virtual long D3DXShader::C30Program::GenerateCode(struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::GenerateCode(D3DXShader::C30Program *this, struct ID3DXBuffer **a2)
{
  return D3DXShader::CShaderProgram::GenerateCode(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101FFD79
// Name: protected: long D3DXShader::C30Program::ProcessVFaceVPos(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::ProcessVFaceVPos(D3DXShader::C30Program *this)
{
  int v1; // edi
  int v2; // eax
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // esi
  int v7; // edx
  int v8; // eax
  int v9; // edx
  unsigned int v10; // edi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  unsigned int v15; // [esp+4h] [ebp-14h]
  unsigned int v16; // [esp+8h] [ebp-10h]
  int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]

  v18 = -1;
  v17 = -1;
  v1 = 0;
  v16 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    while ( 1 )
    {
      v2 = 4 * v1;
      v3 = *(_DWORD *)(4 * v1 + *((_DWORD *)this + 5));
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v3 + 4)) + 4) & 0x10) != 0 )
      {
        v4 = *(_DWORD *)(v3 + 108);
        if ( v4 == 17 || v4 == 18 )
        {
          **(_DWORD **)(v2 + *((_DWORD *)this + 5)) &= 0x40000000u;
          if ( **(_DWORD **)(v2 + *((_DWORD *)this + 5)) != 0 )
            goto LABEL_23;
          v5 = *(_DWORD *)(v2 + *((_DWORD *)this + 5));
          v6 = *(_DWORD *)(v5 + 108);
          if ( v6 != 17 )
            goto LABEL_9;
          if ( v18 == -1 )
            break;
        }
      }
LABEL_23:
      v1 = ++v16;
      if ( v16 >= *((_DWORD *)this + 2) )
        return 0;
    }
    v18 = v1;
LABEL_9:
    if ( v6 == 18 )
    {
      if ( v17 != -1 )
      {
        v7 = *((_DWORD *)this + 5);
        v8 = *(_DWORD *)(v7 + 4 * v1);
        v9 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * v17) + 12);
LABEL_22:
        *(_DWORD *)(v8 + 12) = v9;
        goto LABEL_23;
      }
      v17 = v1;
    }
    v19 = -1;
    v10 = 0;
    v15 = *(_DWORD *)(v5 + 12);
    if ( *((_DWORD *)this + 2) == 0 )
      goto LABEL_23;
    do
    {
      v11 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v10);
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v11 + 4)) + 4) & 0x10) != 0 )
      {
        v12 = *(_DWORD *)(v11 + 12);
        if ( v12 > v15 )
        {
          if ( v19 <= v12 )
            v19 = v12;
          v13 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v10);
          --*(_DWORD *)(v13 + 12);
        }
      }
      ++v10;
    }
    while ( v10 < *((_DWORD *)this + 2) );
    v9 = v19;
    if ( v19 == -1 )
      goto LABEL_23;
    v8 = *(_DWORD *)(v2 + *((_DWORD *)this + 5));
    goto LABEL_22;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FFE86
// Name: protected: virtual long D3DXShader::C30Program::PatternMatch(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::PatternMatch(D3DXShader::C30Program *this)
{
  int v2; // edi
  bool v3; // zf
  _DWORD *v4; // eax
  int result; // eax
  unsigned int v6; // ebx
  int v7; // edi
  unsigned int v8; // ebx
  int v9; // edi
  unsigned int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]
  int v12; // [esp+10h] [ebp-4h]

  if ( *((_DWORD *)this + 23) != 0 )
  {
    v2 = 0;
    v3 = *((_DWORD *)this + 3) == 0;
    *((_DWORD *)this + 63) = 0;
    if ( !v3 )
    {
      do
      {
        v4 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)this + 63));
        *((_DWORD *)this + 64) = v4;
        if ( (*v4 & 0xFFF00000) == 0x20800000 )
        {
          result = D3DXShader::CShaderProgram::MatchENDWHILE(this);
          if ( result < 0 )
            return result;
          v2 |= result == 0;
        }
        ++*((_DWORD *)this + 63);
      }
      while ( *((_DWORD *)this + 63) < *((_DWORD *)this + 3) );
      if ( v2 != 0 )
        D3DXShader::CShaderProgram::Reset(this);
    }
  }
  if ( *((_DWORD *)this + 12) != 0 )
  {
    v10 = 0;
    while ( v10 < 0x10 )
    {
      v6 = *((_DWORD *)this + 3);
      v7 = 0;
      v11 = 1;
      if ( v6 != 0 )
      {
        do
        {
          *((_DWORD *)this + 64) = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v7);
          result = D3DXShader::CShaderProgram::ResolveAddress(this);
          if ( result < 0 )
            return result;
          if ( result == 0 )
            v11 = 0;
          result = D3DXShader::CBaseProgram::CopyInstruction(this, a2: *((struct D3DXShader::CInstruction **)this + 64));
          if ( result < 0 )
            return result;
          **((_DWORD **)this + 64) = 0;
        }
        while ( ++v7 < v6 );
      }
      result = D3DXShader::CProgram::CompactInstructions(this);
      if ( result < 0 )
        return result;
      ++v10;
      if ( v11 != 0 )
      {
        if ( v10 < 0x10 )
          goto LABEL_30;
        break;
      }
    }
    v8 = *((_DWORD *)this + 3);
    v9 = 0;
    v12 = 1;
    if ( v8 != 0 )
    {
      do
      {
        *((_DWORD *)this + 64) = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v9);
        result = D3DXShader::CShaderProgram::ResolveAddress(this);
        if ( result < 0 )
          return result;
        if ( result == 0 )
        {
          D3DXShader::CProgram::Error(
            this,
            a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
            a3: 0x11C9u,
            format: "relative address refrences too deep");
          v12 = 0;
        }
        result = D3DXShader::CBaseProgram::CopyInstruction(this, a2: *((struct D3DXShader::CInstruction **)this + 64));
        if ( result < 0 )
          return result;
        **((_DWORD **)this + 64) = 0;
      }
      while ( ++v9 < v8 );
    }
    result = D3DXShader::CProgram::CompactInstructions(this);
    if ( result < 0 )
      return result;
    if ( v12 == 0 )
      return -2147467259;
  }
LABEL_30:
  if ( (*((_BYTE *)this + 112) & 0x40) != 0
    || (result = (*(int (__thiscall **)(D3DXShader::C30Program *))(*(_DWORD *)this + 152))(a1: this)) >= 0 )
  {
    if ( *((_DWORD *)this + 24) == 0 )
      return 0;
    result = D3DXShader::CShaderProgram::ResolveFlowControl(this);
    if ( result >= 0 )
    {
      D3DXShader::CShaderProgram::Reset(this);
      result = D3DXShader::CProgram::CompactArguments(this);
      if ( result >= 0 )
      {
        result = D3DXShader::CShaderProgram::CompactEndIfs(this);
        if ( result >= 0 )
          return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200050
// Name: protected: virtual long D3DXShader::C30Program::EmitSize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::EmitSize(D3DXShader::C30Program *this)
{
  *(_DWORD *)(*((_DWORD *)this + 67) + 4 * *((_DWORD *)this + 70)) |= (*((_DWORD *)this + 68)
                                                                     - *((_DWORD *)this + 70)
                                                                     - 1) << 24;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10200070
// Name: protected: virtual long D3DXShader::C30Program::EmitDCL(class D3DXShader::CArgument __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::EmitDCL(
        struct D3DXShader::CRegisterEntryNode **this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  struct D3DXShader::D3DX_SEMANTIC *Semantic; // eax
  struct D3DXShader::D3DX_SEMANTIC *v7; // eax
  int result; // eax
  int v9; // eax
  int v10; // edi
  void *v11; // eax
  int v12; // edi
  bool v13; // zf
  int v14; // edi
  int v15; // ecx
  _DWORD *v16; // eax
  int v17; // edx
  unsigned int i; // ecx
  int v19; // eax
  int v20; // eax
  unsigned int v21; // edi
  unsigned int v22; // [esp-8h] [ebp-6Ch]
  int v23; // [esp-4h] [ebp-68h]
  int v24; // [esp-4h] [ebp-68h]
  _DWORD v25[4]; // [esp+Ch] [ebp-58h] BYREF
  int v26; // [esp+1Ch] [ebp-48h]
  int v27; // [esp+20h] [ebp-44h]
  int v28; // [esp+24h] [ebp-40h] BYREF
  unsigned int *v29; // [esp+28h] [ebp-3Ch]
  int v30; // [esp+2Ch] [ebp-38h] BYREF
  int v31; // [esp+30h] [ebp-34h] BYREF
  void *pMem; // [esp+34h] [ebp-30h]
  int v33; // [esp+38h] [ebp-2Ch] BYREF
  unsigned int v34; // [esp+3Ch] [ebp-28h]
  char string[32]; // [esp+40h] [ebp-24h] BYREF

  v23 = *((_DWORD *)a2 + 27);
  v29 = a3;
  v4 = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, int))*this + 21))(a1: this, a2: v23);
  v24 = *((_DWORD *)a2 + 27);
  v34 = v4;
  v5 = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, int))*this + 22))(a1: this, a2: v24);
  if ( *(this + 86) == nullptr )
  {
    v31 = 0;
    switch ( v34 )
    {
      case 0u:
        return 1;
      case 1u:
        v34 = 0;
        goto LABEL_21;
      case 2u:
        v34 = 1;
        goto LABEL_21;
      case 3u:
        v34 = 2;
        goto LABEL_21;
      case 4u:
        v34 = 3;
        goto LABEL_21;
      case 5u:
        v34 = 4;
        goto LABEL_21;
      case 6u:
        v34 = 5;
        goto LABEL_21;
      case 7u:
        v34 = 6;
        goto LABEL_21;
      case 8u:
        v34 = 7;
        goto LABEL_21;
      case 9u:
        v34 = 8;
        if ( v5 != 0 )
          return -2147467259;
        goto LABEL_22;
      case 0xAu:
        v34 = 9;
        goto LABEL_21;
      case 0xBu:
        v34 = 10;
        goto LABEL_21;
      case 0xCu:
        v34 = 11;
        goto LABEL_21;
      case 0xDu:
        v34 = 12;
        goto LABEL_21;
      case 0xEu:
        v34 = 13;
        goto LABEL_21;
      case 0x11u:
        v34 = 0x80000000;
        v31 = 1;
        goto LABEL_21;
      case 0x12u:
        v34 = 0x80000000;
LABEL_21:
        if ( v5 > 0xF )
          return -2147467259;
LABEL_22:
        v34 |= (v5 | 0xFFFF8000) << 16;
        v13 = (*((_BYTE *)a2 + 3) & 1) == 0;
        v27 = 0;
        if ( !v13 )
          v27 = 0x400000;
        result = D3DXShader::CShaderProgram::EmitInst((D3DXShader::CShaderProgram *)this, a2: 0x1Fu);
        if ( result < 0 )
          return result;
        result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: v34);
        if ( result < 0 )
          return result;
        if ( (*(_BYTE *)(*((_DWORD *)*(this + 4) + *((_DWORD *)a2 + 1)) + 4) & 0x10) != 0 )
        {
          v31 |= (int)((_DWORD)*(this + 28) << 25) >> 31;
          result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, struct D3DXShader::CArgument *, int *, int *))*this
                    + 34))(
                     a1: this,
                     a2,
                     a3: &v30,
                     a4: &v28);
          if ( result < 0 )
            return result;
        }
        else
        {
          result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, struct D3DXShader::CArgument *, int *, int *, int *))*this
                    + 33))(
                     a1: this,
                     a2,
                     a3: &v30,
                     a4: &v28,
                     a5: &v31);
          if ( result < 0 )
            return result;
          v31 = 0;
        }
        v26 = 0;
        pMem = nullptr;
        v13 = *(this + 2) == nullptr;
        memset(v25, 255, sizeof(v25));
        if ( !v13 )
        {
          v14 = *((_DWORD *)a2 + 1);
          v15 = (int)*(this + 5);
          do
          {
            v16 = *(_DWORD **)v15;
            if ( v14 == *(_DWORD *)(*(_DWORD *)v15 + 4)
              && *((_DWORD *)a2 + 2) == v16[2]
              && *((_DWORD *)a2 + 3) == v16[3] )
            {
              v25[v16[4]] = pMem;
            }
            pMem = (char *)pMem + 1;
            v15 += 4;
          }
          while ( pMem < *(this + 2) );
        }
        v17 = v26;
        for ( i = 0; i < 4; ++i )
        {
          v19 = v25[i];
          if ( v19 != -1 )
            v25[v17++] = v19;
        }
        result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, _DWORD *, int, int *, int))*this + 28))(
                   a1: this,
                   a2: v25,
                   a3: v17,
                   a4: &v33,
                   a5: v31);
        if ( result < 0 )
          return result;
        v20 = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, int, _DWORD))*this + 20))(
                a1: this,
                a2: 4,
                a3: 0);
        v21 = v34;
        if ( (v34 & 0x7FFFFFFF) == v20 )
          BYTE2(v33) |= 0xFu;
        BYTE2(v33) &= ~0x10u;
        if ( (*(_BYTE *)(this + 28) & 0x40) == 0
          && ((*(_BYTE *)(this + 51) & 0x20) != 0 || (*((_BYTE *)a2 + 3) & 2) != 0) )
        {
          BYTE2(v33) |= 0x20u;
        }
        result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, unsigned int, int, _DWORD))*this + 25))(
                   a1: this,
                   a2: v27 | v30 & 0x7FF | ((v28 & 0x18 | ((v28 | 0xFFFFFFF8) << 20)) << 8),
                   a3: v33,
                   a4: 0);
        if ( result < 0 )
          return result;
        result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **))*this + 24))(a1: this);
        if ( result < 0 )
          return result;
        result = D3DXShader::CShaderProgram::ValidateInst((D3DXShader::CShaderProgram *)this);
        if ( result < 0 )
          return result;
        if ( v29 != nullptr )
          *v29 = v21;
        break;
      default:
        return -2147467259;
    }
    return 0;
  }
  if ( *((_DWORD *)a2 + 27) == -1 )
    return 0;
  if ( v34 == 0xFFFF )
  {
LABEL_17:
    if ( v29 != nullptr )
      *v29 = *((_DWORD *)a2 + 27);
    return 0;
  }
  if ( (*(_BYTE *)(*((_DWORD *)*(this + 4) + *((_DWORD *)a2 + 1)) + 4) & 0x10) != 0 )
  {
    Semantic = D3DXShader::CShaderProgram::FindSemantic(this, a2: (struct D3DXShader::D3DX_SEMANTIC *)v34);
    _snprintf(string, count: 0x20u, format: "v_%s%d", *(_DWORD *)Semantic, v5);
  }
  else
  {
    v7 = D3DXShader::CShaderProgram::FindSemantic(this, a2: (struct D3DXShader::D3DX_SEMANTIC *)v34);
    _snprintf(string, count: 0x20u, format: "o_%s%d", *(_DWORD *)v7, v5);
  }
  v22 = *((_DWORD *)a2 + 3);
  string[31] = 0;
  result = D3DXShader::CFragmentRegisterAllocator::AddElement(
             this: this + 117,
             a2: (D3DXShader *)string,
             a3: v22,
             a4: 1u);
  if ( result >= 0 )
  {
    *(this + 124) = (struct D3DXShader::CRegisterEntryNode *)((char *)*(this + 124) + 1);
    if ( (*(_BYTE *)(this + 51) & 1) != 0 )
    {
      v9 = *((_DWORD *)a2 + 24);
      if ( v9 != 0 && *(_DWORD *)(v9 + 4) == 6 )
      {
        v10 = *(_DWORD *)(v9 + 20);
        if ( *(_DWORD *)(v10 + 4) == 3 )
        {
          v11 = MemAlloc_Alloc(nSize: strlen(*(const char **)(v10 + 24)) + 3);
          pMem = v11;
          if ( v11 == nullptr )
            return -2147024882;
          sprintf(string: (char *)v11, format: "n_%s", *(const char **)(v10 + 24));
          v12 = D3DXShader::CFragmentRegisterAllocator::AddElement(
                  this: this + 117,
                  a2: (D3DXShader *)pMem,
                  a3: *((_DWORD *)a2 + 3),
                  a4: 1u);
          free(pMem);
          if ( v12 < 0 )
            return v12;
          *(this + 124) = (struct D3DXShader::CRegisterEntryNode *)((char *)*(this + 124) + 1);
        }
      }
    }
    goto LABEL_17;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102004D5
// Name: protected: virtual long D3DXShader::CVSProgram::EmitSrc(unsigned long,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CVSProgram::EmitSrc(D3DXShader::CVSProgram *this, __int64 a2, unsigned int a3)
{
  int result; // eax
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx

  result = D3DXShader::CShaderProgram::EmitReg(this, a2: HIDWORD(a2) | a2);
  if ( result >= 0 )
  {
    if ( ((WORD2(a2) | (unsigned __int16)a2) & 0x2000) != 0 && (unsigned __int16)*((_DWORD *)this + 50) >= 0x200u )
    {
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                 + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3) + 4))
                     + 4)
          & 0x10) != 0 )
      {
        v5 = -253491200;
      }
      else
      {
        v6 = *(_DWORD *)(4 * a3 + *((_DWORD *)this + 5));
        v7 = *(_DWORD *)(v6 + 12);
        v8 = *(_DWORD *)(v6 + 16);
        v5 = v7 & 0x7FF | 0xB0000000;
        if ( v8 != 0 )
        {
          v9 = v8 - 1;
          if ( v9 != 0 )
          {
            v10 = v9 - 1;
            if ( v10 != 0 )
            {
              if ( v10 == 1 )
                v5 |= 0xFF0000u;
            }
            else
            {
              v5 |= 0xAA0000u;
            }
          }
          else
          {
            v5 |= 0x550000u;
          }
        }
      }
      D3DXShader::CShaderProgram::EmitReg(this, a2: v5);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200571
// Name: protected: virtual long D3DXShader::C30Program::SrcSwizzle(unsigned int __near *,unsigned int,unsigned long,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::SrcSwizzle(
        D3DXShader::C30Program *this,
        unsigned int *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5)
{
  if ( (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 84))(
         a1: this,
         a2: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a2) + 108)) != 17 )
    return D3DXShader::CShaderProgram::SrcSwizzle(this, a2, a3, a4, a5);
  *a5 = 14942208;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102005B8
// Name: protected: virtual long D3DXShader::C30Program::DestRegister(class D3DXShader::CArgument __near *,unsigned long __near *,unsigned long __near *,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::DestRegister(
        D3DXShader::C30Program *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4,
        int *a5)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::DestRegister(this, a2, a3, a4, a5);
  if ( result >= 0 )
  {
    if ( (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 84))(
           a1: this,
           a2: *((_DWORD *)a2 + 27)) == 17 )
      *a5 = 1;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102005F7
// Name: protected: virtual long D3DXShader::C30Program::DestMask(unsigned int __near *,unsigned int,unsigned long __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::DestMask(
        D3DXShader::C30Program *this,
        unsigned int *a2,
        unsigned int a3,
        unsigned int *a4,
        int a5)
{
  unsigned int v5; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  unsigned int v11; // ecx
  bool v12; // zf
  int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // edi
  unsigned int v16; // eax
  unsigned int v18; // [esp+Ch] [ebp-4h]

  v5 = 0;
  v18 = 0;
  if ( a5 != 0 )
  {
    v18 = 983040;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a2) + 61) & 2) != 0 )
      v18 = 0x100000;
    if ( a3 != 0 )
    {
      do
      {
        v7 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2[v5]) + 16);
        v8 = 0;
        if ( v7 != 0 )
        {
          v9 = v7 - 1;
          if ( v9 != 0 )
          {
            v10 = v9 - 1;
            if ( v10 != 0 )
            {
              if ( v10 == 1 )
                v8 = 0x80000;
            }
            else
            {
              v8 = 0x40000;
            }
          }
          else
          {
            v8 = 0x20000;
          }
        }
        else
        {
          v8 = 0x10000;
        }
        if ( (v8 & v18) != 0 )
          D3DXShader::CProgram::Error(
            this,
            a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
            a3: 0x12D5u,
            format: "internal error: overlapping output writes");
        v18 |= v8;
        ++v5;
      }
      while ( v5 < a3 );
    }
  }
  if ( (*((_BYTE *)this + 112) & 0x40) == 0 )
  {
    if ( (*((_BYTE *)this + 204) & 0x20) != 0 )
      goto LABEL_27;
    v11 = 0;
    v12 = a3 == 0;
    if ( a3 != 0 )
    {
      do
      {
        v13 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2[v11]);
        if ( (*(_BYTE *)(v13 + 3) & 2) == 0
          && ((*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v13 + 4)) + 4) & 1) == 0
           || *(_DWORD *)(v13 + 72) == -1
           || *(_DWORD *)(v13 + 84) != -1) )
        {
          break;
        }
        ++v11;
      }
      while ( v11 < a3 );
      v12 = v11 == a3;
    }
    if ( v12 )
LABEL_27:
      BYTE2(v18) |= 0x20u;
  }
  if ( (*((_BYTE *)this + 204) & 1) != 0 )
  {
    v14 = 0;
    if ( *((_DWORD *)this + 73) != 0 && a3 != 0 )
    {
      do
      {
        v15 = a2[v14];
        v16 = v14 + 6 * *((_DWORD *)this + 74);
        ++v14;
        *(_DWORD *)(*((_DWORD *)this + 73) + 4 * v16 - 16) = v15;
      }
      while ( v14 < a3 );
    }
  }
  *a4 = v18;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10200736
// Name: protected: virtual void D3DXShader::C30Program::GetArgumentName(class D3DXShader::CArgument __near *,char __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::C30Program::GetArgumentName(
        D3DXShader::C30Program *this,
        struct D3DXShader::CArgument *a2,
        char *string,
        unsigned int count)
{
  int v4; // eax
  unsigned int v6; // eax
  const char **Semantic; // ebx
  int v8; // eax

  v4 = *((_DWORD *)a2 + 1);
  if ( (v4 == *((_DWORD *)this + 32) || v4 == *((_DWORD *)this + 33))
    && (v6 = (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 84))(
               a1: this,
               a2: *((_DWORD *)a2 + 27)),
        (Semantic = (const char **)D3DXShader::CShaderProgram::FindSemantic(
                                     this,
                                     a2: (struct D3DXShader::D3DX_SEMANTIC *)&D3DXShader::g_30InputOutput,
                                     a3: v6))[4] != (const char *)-1) )
  {
    v8 = (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 88))(
           a1: this,
           a2: *((_DWORD *)a2 + 27));
    _snprintf(
      string,
      count,
      format: "%s%s%u",
      **(const char ***)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)a2 + 1)),
      *Semantic,
      v8);
    string[count - 1] = 0;
  }
  else
  {
    D3DXShader::CProgram::GetArgumentName(this, a2, string, a4: count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102007BE
// Name: protected: virtual long D3DXShader::C30Program::ConstrainPortsArgumentTest(class D3DXShader::CInstruction __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::ConstrainPortsArgumentTest(
        D3DXShader::C30Program *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int a3)
{
  unsigned int v3; // edx
  bool v5; // zf

  v3 = *(_DWORD *)a2 & 0xFFF00000;
  if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                             + 4 * *(_DWORD *)(*((_DWORD *)a2 + 2) + 4 * a3 * (*(_DWORD *)a2 & 0xFFFFF)))
                 + 108) == 17 )
  {
    if ( v3 == 805306368 )
    {
      if ( a3 == 0 )
        return 1;
    }
    else
    {
      if ( v3 > 0x73800000 )
      {
        if ( v3 == 1950351360 || v3 == 1951399936 || v3 == 1952448512 )
          return 1;
        v5 = v3 == 1953497088;
      }
      else
      {
        if ( v3 == 1937768448 || v3 == 284164096 || v3 == 1934622720 || v3 == 1935671296 )
          return 1;
        v5 = v3 == 1936719872;
      }
      if ( v5 )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10200851
// Name: protected: virtual long D3DXShader::CShaderProgram::EmitObjectDCL(class D3DXShader::CArgument __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitObjectDCL(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CArgument *a2)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020087D
// Name: protected: virtual long D3DXShader::C30Program::ValidateArguments(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::ValidateArguments(D3DXShader::C30Program *this)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::ValidateArguments(this);
  if ( result >= 0 )
    return D3DXShader::C30Program::ProcessVFaceVPos(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200895
// Name: protected: long D3DXShader::C30Program::MatchVFace(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::MatchVFace(D3DXShader::C30Program *this)
{
  unsigned int v1; // edi
  unsigned int v3; // ebx
  int v4; // eax
  int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned int v13; // eax
  D3DXShader::CInstruction *v14; // edi
  _DWORD *v15; // eax
  unsigned int j; // ecx
  D3DXShader::CInstruction **v17; // eax
  unsigned int v19; // [esp+18h] [ebp-20h]
  unsigned int i; // [esp+1Ch] [ebp-1Ch]
  unsigned int Inputs; // [esp+20h] [ebp-18h]
  int v22; // [esp+24h] [ebp-14h]
  struct D3DXShader::CInstruction *v23; // [esp+28h] [ebp-10h]
  struct D3DXShader::CInstruction *v24; // [esp+28h] [ebp-10h]
  unsigned int v25; // [esp+2Ch] [ebp-Ch]
  unsigned int *v26; // [esp+30h] [ebp-8h] BYREF
  unsigned int v27; // [esp+34h] [ebp-4h]

  v1 = 0;
  v3 = -1;
  v22 = 0;
  if ( *((_DWORD *)this + 3) == 0 )
    return 0;
  do
  {
    v4 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = v1;
    v5 = *(_DWORD *)(v4 + 4 * v1);
    *((_DWORD *)this + 64) = v5;
    if ( (*(_WORD *)(v5 + 2) & 0xFFF0) != 0 )
    {
      v6 = *(_DWORD *)(v5 + 4) / (*(_DWORD *)v5 & 0xFFFFFu);
      v27 = 0;
      for ( i = v6; v27 < i; ++v27 )
      {
        v25 = 0;
        Inputs = D3DXShader::CInstruction::GetInputs(this: *((D3DXShader::CInstruction **)this + 64), a2: v27, a3: &v26);
        if ( Inputs != 0 )
        {
          do
          {
            v7 = v25;
            v8 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v26[v25]);
            v9 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v8 + 4)) + 4);
            if ( (v9 & 0x10) == 0
              || (v9 & 0x200) != 0
              || (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 84))(
                   a1: this,
                   a2: *(_DWORD *)(v8 + 108)) != 17
              || v27 == 0 && (**((_DWORD **)this + 64) & 0xFFF00000) == 0x30000000 )
            {
              break;
            }
            if ( v3 == -1 )
            {
              v24 = nullptr;
              if ( *((_DWORD *)this + 2) != 0 )
              {
                v10 = *((_DWORD *)this + 5);
                v11 = *((_DWORD *)this + 2);
                do
                {
                  if ( *((_DWORD *)this + 34) == *(_DWORD *)(*(_DWORD *)v10 + 4) )
                  {
                    v12 = *(_DWORD *)(*(_DWORD *)v10 + 12);
                    if ( v12 >= (unsigned int)v24 )
                      v24 = (struct D3DXShader::CInstruction *)(v12 + 1);
                  }
                  v10 += 4;
                  --v11;
                }
                while ( v11 != 0 );
              }
              v3 = D3DXShader::CBaseProgram::AddArgument(
                     this,
                     a2: *((_DWORD *)this + 34),
                     a3: (unsigned int)v24,
                     a4: 0,
                     a5: 0.0);
              if ( v3 == -1 )
                return -2147024882;
              D3DXShader::CArgument::Instance(
                this: *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v3),
                a2: *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v26[v7]));
              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v3) + 108) = -1;
              v19 = v26[v7];
              v23 = *((struct D3DXShader::CInstruction **)this + 64);
            }
            ++v25;
            v26[v7] = v3;
          }
          while ( v25 < Inputs );
          v1 = v22;
        }
      }
    }
    v22 = ++v1;
  }
  while ( v1 < *((_DWORD *)this + 3) );
  if ( v3 == -1 )
    return 0;
  v13 = D3DXShader::CBaseProgram::AddInstruction(this, a2: 0x30000001u, a3: 3u, a4: 1u);
  if ( v13 != -1 )
  {
    v14 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v13);
    D3DXShader::CInstruction::Instance(this: v14, a2: v23);
    **((_DWORD **)v14 + 4) = v3;
    **((_DWORD **)v14 + 2) = v19;
    *(_DWORD *)(*((_DWORD *)v14 + 2) + 4) = D3DXShader::CBaseProgram::AddArgument(
                                              this,
                                              a2: *((_DWORD *)this + 30),
                                              a3: 0,
                                              a4: 0,
                                              a5: 1.0);
    *(_DWORD *)(*((_DWORD *)v14 + 2) + 8) = D3DXShader::CBaseProgram::AddArgument(
                                              this,
                                              a2: *((_DWORD *)this + 30),
                                              a3: 0,
                                              a4: 0,
                                              a5: -1.0);
    v15 = *((_DWORD **)v14 + 2);
    if ( v15[1] != -1 && v15[2] != -1 )
    {
      for ( j = *((_DWORD *)this + 3); ; v17[j] = v17[j - 1] )
      {
        v17 = *((D3DXShader::CInstruction ***)this + 6);
        if ( j <= 1 )
          break;
        --j;
      }
      *v17 = v14;
      return 0;
    }
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x10200ADD
// Name: protected: virtual int D3DXShader::C30Program::ViolatesPortConstraints(class D3DXShader::CInstruction __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::ViolatesPortConstraints(
        D3DXShader::C30Program *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int *a3)
{
  int v5; // eax
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // edi
  bool v11; // zf
  _DWORD *v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // edx
  _DWORD *v16; // ecx
  _DWORD *v17; // eax
  unsigned int v18; // ecx
  _DWORD *v19; // eax
  int v20; // ebx
  int v21; // edi
  unsigned int *v22; // eax
  _DWORD v23[36]; // [esp+8h] [ebp-A8h] BYREF
  int v24; // [esp+98h] [ebp-18h]
  unsigned int v25; // [esp+9Ch] [ebp-14h]
  int v26; // [esp+A0h] [ebp-10h]
  int v27; // [esp+A4h] [ebp-Ch]
  unsigned int v28; // [esp+A8h] [ebp-8h]
  unsigned int v29; // [esp+ACh] [ebp-4h]

  if ( a2 == nullptr )
    return 1;
  v5 = *(_DWORD *)a2;
  v6 = *(_DWORD *)a2 & 0xFFF00000;
  if ( v6 == 0 || v6 == 544210944 )
    return 0;
  v26 = v5 & 0xFFFFF;
  v28 = *((_DWORD *)a2 + 1) / (v5 & 0xFFFFFu);
  if ( v6 == 1884291072 || v6 == 1885339648 || v6 == 1886388224 )
    v28 = 2;
  if ( v28 <= 1 )
    return 0;
  v7 = *((_DWORD *)this + 34);
  v8 = *((_DWORD *)this + 31);
  v9 = *((_DWORD *)this + 32);
  v23[v9 + 18] = 0;
  v7 *= 4;
  v8 *= 4;
  *(_DWORD *)((char *)&v23[18] + v7) = 0;
  *(_DWORD *)((char *)&v23[18] + v8) = 0;
  v10 = *((_DWORD *)this + 37);
  v23[v9] = 1;
  v10 *= 4;
  *(_DWORD *)((char *)&v23[18] + v10) = 0;
  *(_DWORD *)((char *)v23 + v7) = 3;
  *(_DWORD *)((char *)v23 + v8) = 1;
  v11 = v28 == 0;
  *(_DWORD *)((char *)v23 + v10) = 1;
  v24 = 0;
  v29 = 0;
  if ( v11 )
  {
LABEL_35:
    v29 = 0;
    if ( v28 != 0 )
    {
      v20 = 0;
      v27 = 4 * v26;
      while ( 1 )
      {
        if ( (*(_DWORD *)a2 & 0xF0000000) == 0x60000000 )
        {
          v21 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v20 + *((_DWORD *)a2 + 2)));
          if ( (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 84))(
                 a1: this,
                 a2: *(_DWORD *)(v21 + 108)) == 18
            && *(_DWORD *)(v21 + 4) == *((_DWORD *)this + 32) )
          {
            break;
          }
        }
        ++v29;
        v20 += v27;
        if ( v29 >= v28 )
          return 0;
      }
      if ( a3 != nullptr )
        *a3 = v29;
      return 1;
    }
    return 0;
  }
  v27 = 0;
  while ( 1 )
  {
    v12 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v27 + *((_DWORD *)a2 + 2)));
    v13 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v12[1]);
    if ( v12[27] == 17 && (*(_BYTE *)(v13 + 4) & 0x10) != 0 )
      goto LABEL_34;
    v14 = *(_DWORD *)(v13 + 4);
    if ( (v14 & 0x200) != 0 )
    {
      if ( (v14 & 0x80u) == 0 )
      {
        v15 = *((_DWORD *)this + 31);
        goto LABEL_24;
      }
LABEL_18:
      v15 = *((_DWORD *)this + 37);
      goto LABEL_24;
    }
    if ( (v14 & 0x80u) != 0 )
      goto LABEL_18;
    v15 = (v14 & 0x10) == 0
       || (v14 & 0x200) != 0
       || (*(int (__thiscall **)(D3DXShader::C30Program *, _DWORD))(*(_DWORD *)this + 84))(a1: this, a2: v12[27]) == 0xFFFF
        ? *((_DWORD *)this + 34)
        : *((_DWORD *)this + 32);
LABEL_24:
    v25 = 0;
    if ( v29 != 0 )
    {
      v16 = *((_DWORD **)a2 + 2);
      do
      {
        v17 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *v16);
        if ( v12[1] == v17[1] && v12[2] == v17[2] && v12[3] == v17[3] )
          break;
        ++v25;
        v16 += v26;
      }
      while ( v25 < v29 );
    }
    v18 = v29;
    if ( v25 == v29 )
    {
      v19 = &v23[v15 + 18];
      if ( ++*v19 > v23[v15] )
      {
        v22 = a3;
        if ( a3 == nullptr )
          return 1;
        goto LABEL_43;
      }
    }
    if ( *((_DWORD *)this + 31) == v15 && (unsigned int)++v24 > 2 )
      break;
LABEL_34:
    ++v29;
    v27 += 4 * v26;
    if ( v29 >= v28 )
      goto LABEL_35;
  }
  v22 = a3;
  if ( a3 != nullptr )
  {
    v18 = v29;
LABEL_43:
    *v22 = v18;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10200D4E
// Name: protected: virtual long D3DXShader::C30Program::Translate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::C30Program::Translate(D3DXShader::C30Program *this)
{
  int matched; // edi
  unsigned int v3; // ecx
  int v4; // eax
  _DWORD *v5; // eax
  unsigned int v6; // ecx
  int v7; // eax
  _DWORD *v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  _DWORD *v11; // eax
  void *v12; // eax
  unsigned int v13; // ecx
  int v14; // eax
  _DWORD *v15; // eax
  int v16; // ecx
  int v17; // eax
  _DWORD *v18; // eax
  unsigned int v19; // eax
  int v20; // eax
  int v21; // ecx
  _DWORD *v22; // eax
  unsigned int v23; // eax
  int v24; // eax
  unsigned int v25; // ecx
  int v26; // eax
  _DWORD *v27; // eax
  int v28; // ecx
  int v29; // eax
  _DWORD *v30; // eax
  unsigned int v31; // eax
  int v32; // eax
  unsigned int v33; // ecx
  int v34; // eax
  _DWORD *v35; // eax
  unsigned int v36; // eax
  int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  _DWORD *v40; // eax
  unsigned int v41; // ecx
  int v42; // eax
  _DWORD *v43; // eax
  unsigned int v44; // eax
  unsigned int k; // edi
  int v46; // eax
  _DWORD *v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // ecx
  int v50; // eax
  _DWORD *v51; // eax
  unsigned int v52; // ecx
  int v53; // eax
  _DWORD *v54; // eax
  unsigned int v55; // ecx
  int v56; // eax
  _DWORD *v57; // eax
  unsigned int v58; // ecx
  int v59; // eax
  _DWORD *v60; // eax
  unsigned int v61; // ecx
  int v62; // eax
  _DWORD *v63; // eax
  void *v64; // eax
  int v65; // eax
  int v67; // [esp+8h] [ebp-8h]
  unsigned int v68; // [esp+8h] [ebp-8h]
  int mm; // [esp+8h] [ebp-8h]
  unsigned int nn; // [esp+8h] [ebp-8h]
  int j; // [esp+8h] [ebp-8h]
  unsigned int m; // [esp+8h] [ebp-8h]
  unsigned int n; // [esp+8h] [ebp-8h]
  unsigned int ii; // [esp+8h] [ebp-8h]
  unsigned int jj; // [esp+8h] [ebp-8h]
  int v76; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]
  int v78; // [esp+Ch] [ebp-4h]
  int v79; // [esp+Ch] [ebp-4h]
  int kk; // [esp+Ch] [ebp-4h]
  int v81; // [esp+Ch] [ebp-4h]
  int v82; // [esp+Ch] [ebp-4h]
  int v83; // [esp+Ch] [ebp-4h]

  if ( (*((_BYTE *)this + 112) & 0x40) != 0 )
  {
    matched = v67;
  }
  else
  {
    matched = D3DXShader::C30Program::MatchVFace(this);
    if ( matched < 0 )
      return matched;
  }
  v3 = 0;
  for ( i = 0; v3 < *((_DWORD *)this + 3); i = v3 )
  {
    v4 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = v3;
    v5 = *(_DWORD **)(v4 + 4 * v3);
    *((_DWORD *)this + 64) = v5;
    if ( (*v5 & 0xFFF00000) == 0x11400000 )
    {
      matched = D3DXShader::CShaderProgram::MatchBREAK(this);
      if ( matched < 0 )
        return matched;
      v3 = i;
    }
    else
    {
      matched = 1;
    }
    ++v3;
  }
  if ( (*((_BYTE *)this + 204) & 4) != 0 )
  {
    D3DXShader::CProgram::IdentityRemap(this);
    v78 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      v6 = 0;
      do
      {
        v7 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v6;
        v8 = *(_DWORD **)(v7 + 4 * v6);
        *((_DWORD *)this + 64) = v8;
        if ( (*v8 & 0xFFF00000) == 0x10000000 )
        {
          D3DXShader::CShaderProgram::RemapSamplerMove(this);
          v6 = v78;
        }
        v78 = ++v6;
      }
      while ( v6 < *((_DWORD *)this + 3) );
    }
    D3DXShader::CProgram::RemapArguments(this);
    if ( (*((_BYTE *)this + 204) & 4) != 0 )
    {
LABEL_118:
      D3DXShader::CShaderProgram::Reset(this);
      v41 = 0;
      for ( j = 0; v41 < *((_DWORD *)this + 3); j = ++v41 )
      {
        v42 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v41;
        v43 = *(_DWORD **)(v42 + 4 * v41);
        *((_DWORD *)this + 64) = v43;
        v44 = *v43 & 0xFFF00000;
        if ( v44 == 1952448512 || v44 == 1953497088 )
        {
          matched = D3DXShader::CShaderProgram::MatchBREAK_NEEQ(this);
          if ( matched < 0 )
            return matched;
          matched = D3DXShader::CShaderProgram::MatchBREAK_NEEQ2(this);
          if ( matched < 0 )
            return matched;
          v41 = j;
        }
      }
      for ( k = 0; k < *((_DWORD *)this + 3); ++k )
      {
        v46 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = k;
        v47 = *(_DWORD **)(v46 + 4 * k);
        *((_DWORD *)this + 64) = v47;
        v48 = *v47 & 0xFFF00000;
        if ( v48 == 1950351360 || v48 == 1951399936 || v48 == 1952448512 || v48 == 1953497088 )
          D3DXShader::CShaderProgram::MatchBREAK_COND(this);
      }
      v49 = 0;
      for ( m = 0; v49 < *((_DWORD *)this + 3); m = v49 )
      {
        v50 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v49;
        v51 = *(_DWORD **)(v50 + 4 * v49);
        *((_DWORD *)this + 64) = v51;
        if ( (*v51 & 0xFFF00000) == 0x20900000 )
        {
          matched = D3DXShader::CShaderProgram::FoldBreak(this);
          if ( matched < 0 )
            return matched;
          v49 = m;
        }
        ++v49;
      }
      D3DXShader::CShaderProgram::Reset(this);
      v52 = 0;
      for ( n = 0; v52 < *((_DWORD *)this + 3); n = v52 )
      {
        v53 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v52;
        v54 = *(_DWORD **)(v53 + 4 * v52);
        *((_DWORD *)this + 64) = v54;
        if ( (*v54 & 0xFFF00000) == 0x20900000 )
        {
          matched = D3DXShader::CShaderProgram::FoldIterator(this);
          if ( matched < 0 )
            return matched;
          v52 = n;
        }
        ++v52;
      }
      v55 = 0;
      for ( ii = 0; v55 < *((_DWORD *)this + 3); ii = v55 )
      {
        v56 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v55;
        v57 = *(_DWORD **)(v56 + 4 * v55);
        *((_DWORD *)this + 64) = v57;
        if ( (*v57 & 0xFFF00000) == 0x11400000 )
        {
          matched = D3DXShader::CShaderProgram::MatchBREAK2(this);
          if ( matched < 0 )
            return matched;
          v55 = ii;
        }
        ++v55;
      }
      v58 = 0;
      for ( jj = 0; v58 < *((_DWORD *)this + 3); jj = v58 )
      {
        v59 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v58;
        v60 = *(_DWORD **)(v59 + 4 * v58);
        *((_DWORD *)this + 64) = v60;
        if ( (*v60 & 0xFFF00000) == 0x70300000 )
        {
          matched = D3DXShader::CShaderProgram::MatchLRP2((struct D3DXShader::CInstruction **)this, a2: 0);
          if ( matched < 0 )
            return matched;
          v58 = jj;
        }
        ++v58;
      }
      D3DXShader::CShaderProgram::Reset(this);
      v61 = 0;
      v76 = 0;
      if ( *((_DWORD *)this + 3) != 0 )
      {
        while ( 1 )
        {
          v62 = *((_DWORD *)this + 6);
          *((_DWORD *)this + 63) = v61;
          v63 = *(_DWORD **)(v62 + 4 * v61);
          *((_DWORD *)this + 64) = v63;
          v64 = (void *)(*v63 & 0xFFF00000);
          if ( v64 == &unk_10300000
            || v64 == (void *)273678336
            || v64 == (void *)274726912
            || v64 == (void *)275775488
            || v64 == (void *)1342177280 )
          {
            break;
          }
          if ( v64 == (void *)1882193920 )
          {
            v65 = D3DXShader::CShaderProgram::MatchLRP(this);
LABEL_161:
            matched = v65;
            if ( v65 < 0 )
              return matched;
            v61 = v76;
          }
          v76 = ++v61;
          if ( v61 >= *((_DWORD *)this + 3) )
            goto LABEL_164;
        }
        v65 = D3DXShader::CShaderProgram::MatchRepMov(this);
        goto LABEL_161;
      }
LABEL_164:
      D3DXShader::CShaderProgram::Reset(this);
      matched = D3DXShader::CProgram::RemoveDeadCode(this);
      if ( matched >= 0 )
      {
        matched = D3DXShader::CProgram::RemoveDuplicateArguments(this);
        if ( matched >= 0 )
        {
          matched = D3DXShader::CProgram::CompactInstructions(this);
          if ( matched >= 0 )
          {
            matched = D3DXShader::CProgram::CompactArguments(this);
            if ( matched >= 0 )
            {
              D3DXShader::CShaderProgram::Reset(this);
              return 0;
            }
          }
        }
      }
      return matched;
    }
  }
  v9 = 0;
  v79 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    while ( 1 )
    {
      v10 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v9;
      v11 = *(_DWORD **)(v10 + 4 * v9);
      *((_DWORD *)this + 64) = v11;
      v12 = (void *)(*v11 & 0xFFF00000);
      if ( v12 == &loc_10100000 )
        break;
      if ( v12 == (void *)0x20000000 || v12 == (void *)537919488 || v12 == (void *)805306368 )
      {
        matched = D3DXShader::CShaderProgram::MatchSatModifier(this);
        D3DXShader::CShaderProgram::Reset(this);
LABEL_26:
        if ( matched < 0 )
          return matched;
        v9 = v79;
        goto LABEL_28;
      }
      matched = 1;
LABEL_28:
      v79 = ++v9;
      if ( v9 >= *((_DWORD *)this + 3) )
        goto LABEL_29;
    }
    matched = D3DXShader::CShaderProgram::MatchNEG(this, a2: 1);
    goto LABEL_26;
  }
LABEL_29:
  if ( *((char *)this + 108) < 0 && (*((_BYTE *)this + 113) & 1) != 0 )
  {
    v13 = 0;
    for ( kk = 0; v13 < *((_DWORD *)this + 3); kk = ++v13 )
    {
      v14 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v13;
      v15 = *(_DWORD **)(v14 + 4 * v13);
      *((_DWORD *)this + 64) = v15;
      if ( (*v15 & 0xFFF00000) == 0x30000000 )
      {
        if ( matched < 0 )
          return matched;
        matched = D3DXShader::CShaderProgram::MatchMinMax(this, a2: nullptr, a3: nullptr, a4: nullptr);
        if ( matched < 0 )
          return matched;
        matched = D3DXShader::CShaderProgram::MatchMinMax2(this, a2: nullptr, a3: nullptr, a4: nullptr);
        if ( matched < 0 )
          return matched;
        v13 = kk;
      }
      else
      {
        matched = 1;
      }
    }
    matched = D3DXShader::CProgram::RemoveDeadCode(this);
    if ( matched < 0 )
      return matched;
    D3DXShader::CShaderProgram::Reset(this);
    v81 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v16 = v81;
        v17 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v81;
        v18 = *(_DWORD **)(v17 + 4 * v81);
        *((_DWORD *)this + 64) = v18;
        v19 = *v18 & 0xFFF00000;
        if ( v19 == 0x20000000 )
          break;
        if ( v19 == 805306368 )
        {
          matched = D3DXShader::CShaderProgram::MatchABS(this);
          if ( matched < 0 )
            return matched;
          matched = D3DXShader::CShaderProgram::MatchABS2(this);
          goto LABEL_48;
        }
        if ( v19 == 1890582528 )
          break;
        matched = 1;
LABEL_50:
        v81 = v16 + 1;
        if ( (unsigned int)(v16 + 1) >= *((_DWORD *)this + 3) )
          goto LABEL_51;
      }
      matched = D3DXShader::CShaderProgram::MatchSatModifier(this);
      D3DXShader::CShaderProgram::Reset(this);
LABEL_48:
      if ( matched < 0 )
        return matched;
      v16 = v81;
      goto LABEL_50;
    }
  }
LABEL_51:
  v20 = 0;
  v68 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    while ( 1 )
    {
      v21 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v20;
      v22 = *(_DWORD **)(v21 + 4 * v20);
      *((_DWORD *)this + 64) = v22;
      v23 = *v22 & 0xFFF00000;
      if ( v23 == 273678336 )
        break;
      switch ( v23 )
      {
        case 0x10F00000u:
          v24 = D3DXShader::CShaderProgram::MatchIF2((struct D3DXShader::CInstruction **)this);
          goto LABEL_65;
        case 0x11400000u:
          v24 = D3DXShader::CShaderProgram::MatchBREAK(this);
          goto LABEL_65;
        case 0x20100000u:
          if ( (unsigned __int16)*((_DWORD *)this + 50) >= 0x200u )
          {
            v24 = D3DXShader::CShaderProgram::MatchMAX(this);
            goto LABEL_65;
          }
          goto LABEL_68;
        default:
          break;
      }
      if ( v23 != 541065216 )
        goto LABEL_68;
      if ( (*((_BYTE *)this + 108) & 0x20) != 0 )
        matched = D3DXShader::CShaderProgram::MatchDP2Add(this);
      if ( matched == 1 )
      {
        v24 = D3DXShader::CShaderProgram::MatchComplexMad(this, a2: 1);
LABEL_65:
        matched = v24;
      }
LABEL_69:
      v25 = 0;
      v82 = 0;
      if ( *((_DWORD *)this + 3) != 0 )
      {
        matched = 1;
        do
        {
          v26 = *((_DWORD *)this + 6);
          *((_DWORD *)this + 63) = v25;
          v27 = *(_DWORD **)(v26 + 4 * v25);
          *((_DWORD *)this + 64) = v27;
          if ( (*v27 & 0xFFF00000) == 0x70000000 )
          {
            D3DXShader::CShaderProgram::MatchABSModifier(this);
            v25 = v82;
          }
          v82 = ++v25;
        }
        while ( v25 < *((_DWORD *)this + 3) );
      }
      if ( matched < 0 )
        return matched;
      v20 = ++v68;
      if ( v68 >= *((_DWORD *)this + 3) )
        goto LABEL_76;
    }
    if ( (unsigned __int16)*((_DWORD *)this + 50) >= 0x200u )
    {
      v24 = D3DXShader::CShaderProgram::MatchPOW(this);
      goto LABEL_65;
    }
LABEL_68:
    matched = 1;
    goto LABEL_69;
  }
LABEL_76:
  matched = D3DXShader::CProgram::RemoveDeadCode(this);
  if ( matched >= 0 )
  {
    D3DXShader::CShaderProgram::Reset(this);
    v83 = 0;
    if ( *((_DWORD *)this + 3) != 0 )
    {
      while ( 1 )
      {
        v28 = v83;
        v29 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 63) = v83;
        v30 = *(_DWORD **)(v29 + 4 * v83);
        *((_DWORD *)this + 64) = v30;
        v31 = *v30 & 0xFFF00000;
        if ( v31 == 542113792 )
        {
          v32 = D3DXShader::CShaderProgram::MatchNRM(this);
          goto LABEL_94;
        }
        if ( v31 == 1342177280 )
          break;
        switch ( v31 )
        {
          case 0x70300000u:
            v32 = D3DXShader::CShaderProgram::MatchLRP2((struct D3DXShader::CInstruction **)this, a2: 1);
            goto LABEL_94;
          case 0x73500000u:
          case 0x73600000u:
            matched = D3DXShader::CShaderProgram::MatchNEEQ(this);
            if ( matched < 0 )
              return matched;
            v32 = D3DXShader::CShaderProgram::MatchNEEQ2(this);
LABEL_94:
            matched = v32;
LABEL_95:
            if ( matched < 0 )
              return matched;
            v28 = v83;
            goto LABEL_97;
          case 0x74600000u:
          case 0x74700000u:
            matched = D3DXShader::CShaderProgram::MatchBREAK_NEEQ(this);
            if ( matched < 0 )
              return matched;
            v32 = D3DXShader::CShaderProgram::MatchBREAK_NEEQ2(this);
            goto LABEL_94;
          default:
            break;
        }
        matched = 1;
LABEL_97:
        v83 = v28 + 1;
        if ( (unsigned int)(v28 + 1) >= *((_DWORD *)this + 3) )
          goto LABEL_98;
      }
      if ( (*((_BYTE *)this + 108) & 0x20) != 0 )
      {
        v32 = D3DXShader::CShaderProgram::ConvertDP2(this);
        goto LABEL_94;
      }
      goto LABEL_95;
    }
LABEL_98:
    v33 = 0;
    for ( mm = 0; v33 < *((_DWORD *)this + 3); mm = ++v33 )
    {
      v34 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v33;
      v35 = *(_DWORD **)(v34 + 4 * v33);
      *((_DWORD *)this + 64) = v35;
      v36 = *v35 & 0xFFF00000;
      if ( v36 > 0x74400000 )
      {
        if ( v36 == 1951399936 || v36 == 1952448512 || v36 == 1953497088 )
        {
LABEL_109:
          v37 = D3DXShader::CShaderProgram::MatchBREAK_COND(this);
          goto LABEL_110;
        }
      }
      else
      {
        if ( v36 == 1950351360 )
          goto LABEL_109;
        if ( v36 == 1934622720 || v36 == 1935671296 || v36 == 1936719872 || v36 == 1937768448 )
        {
          v37 = D3DXShader::CShaderProgram::MatchIFCOND(this);
LABEL_110:
          matched = v37;
          if ( v37 < 0 )
            return matched;
          v33 = mm;
        }
      }
    }
    v38 = 0;
    for ( nn = 0; v38 < *((_DWORD *)this + 3); nn = v38 )
    {
      v39 = *((_DWORD *)this + 6);
      *((_DWORD *)this + 63) = v38;
      v40 = *(_DWORD **)(v39 + 4 * v38);
      *((_DWORD *)this + 64) = v40;
      if ( (*v40 & 0xFFF00000) == 0x73700000 )
      {
        matched = D3DXShader::CShaderProgram::MatchNEZero(this);
        if ( matched < 0 )
          return matched;
        v38 = nn;
      }
      ++v38;
    }
    goto LABEL_118;
  }
  return matched;
}

//------------------------------------------------------------------------------
// Address: 0x102014DA
// Name: protected: virtual long D3DXShader::C30Program::EmitInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall D3DXShader::C30Program::EmitInstructions@<eax>(
        D3DXShader::C30Program *this@<ecx>,
        unsigned int a2@<ebx>)
{
  unsigned int i; // edi
  int v4; // eax
  unsigned int j; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  void *v10; // eax
  int v11; // eax
  bool v12; // zf
  bool v13; // zf
  _exception *v14; // [esp+0h] [ebp-Ch]

  for ( i = 0; i < *((_DWORD *)this + 3); ++i )
  {
    v4 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = i;
    *((_DWORD *)this + 64) = *(_DWORD *)(v4 + 4 * i);
    D3DXShader::CShaderProgram::SortInstruction(this, a2);
  }
  for ( j = 0; j < *((_DWORD *)this + 3); ++j )
  {
    v6 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = j;
    v7 = *(_DWORD *)(v6 + 4 * j);
    *((_DWORD *)this + 64) = v7;
    v8 = *(_DWORD *)(v7 + 60);
    if ( v8 != 0 && *(_DWORD *)(v8 + 4) == 13 )
      *((_DWORD *)this + 65) = v8 + 48;
    result = D3DXShader::CVSProgram::EmitAddresses(this);
    if ( result < 0 )
      return result;
    v10 = (void *)(**((_DWORD **)this + 64) & 0xFFF00000);
    if ( (unsigned int)v10 > 0x60F00000 )
    {
      if ( (unsigned int)v10 > 0x73400000 )
      {
        if ( (unsigned int)v10 <= 0x73F00000 )
        {
          if ( v10 == (void *)1945108480 )
            goto LABEL_132;
          if ( (unsigned int)v10 > 0x73A00000 )
          {
            if ( v10 != (void *)1940914176 && v10 != (void *)1941962752 )
            {
              if ( v10 != (void *)1943011328 )
              {
                v13 = v10 == (void *)1944059904;
                goto LABEL_131;
              }
LABEL_132:
              v11 = D3DXShader::CShaderProgram::EmitANDELSE(this);
              goto LABEL_158;
            }
            goto LABEL_145;
          }
          if ( v10 == (void *)1939865600 )
            goto LABEL_145;
          if ( v10 != (void *)1934622720
            && v10 != (void *)1935671296
            && v10 != (void *)1936719872
            && v10 != (void *)1937768448 )
          {
            if ( v10 != (void *)1938817024 )
              goto LABEL_170;
LABEL_145:
            v11 = D3DXShader::CShaderProgram::EmitANDIF(this);
            goto LABEL_158;
          }
LABEL_146:
          v11 = D3DXShader::CShaderProgram::EmitIF(this);
          goto LABEL_158;
        }
        if ( (unsigned int)v10 > 0x74500000 )
        {
          if ( v10 != (void *)1952448512 && v10 != (void *)1953497088 )
          {
            if ( v10 == (void *)1956642816 )
            {
              v11 = D3DXShader::CShaderProgram::EmitENDLOOP_INC(this);
            }
            else
            {
              if ( v10 != (void *)1957691392 )
              {
LABEL_170:
                if ( (*((_BYTE *)this + 112) & 0x40) != 0 )
LABEL_171:
                  D3DXShader::CProgram::Error(
                    this,
                    a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
                    a3: 0x11B4u,
                    format: "cannot map expression to vertex shader instruction set");
                else
                  D3DXShader::CProgram::Error(
                    this,
                    a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
                    a3: 0x11B4u,
                    format: "cannot map expression to pixel shader instruction set");
                return -2147467263;
              }
              v11 = D3DXShader::CShaderProgram::EmitENDLOOP(this);
            }
            goto LABEL_158;
          }
          goto LABEL_157;
        }
        if ( v10 == (void *)1951399936 )
          goto LABEL_157;
        if ( v10 == (void *)1946157056 )
          goto LABEL_132;
        if ( v10 == (void *)1947205632 )
        {
          v11 = D3DXShader::CShaderProgram::EmitLOOP_INC(this);
        }
        else
        {
          if ( v10 != (void *)1948254208 )
          {
            if ( v10 != (void *)1950351360 )
              goto LABEL_170;
LABEL_157:
            v11 = D3DXShader::CShaderProgram::EmitBREAK(this);
            goto LABEL_158;
          }
          v11 = D3DXShader::CShaderProgram::EmitLOOP(this);
        }
      }
      else
      {
        if ( v10 == (void *)1933574144 )
        {
          v11 = D3DXShader::CShaderProgram::EmitANDENDIF(this);
          goto LABEL_158;
        }
        if ( (unsigned int)v10 > 0x70600000 )
        {
          if ( (unsigned int)v10 > 0x70D00000 )
          {
            if ( v10 == (void *)1929379840 )
            {
              v11 = D3DXShader::CShaderProgram::EmitANDIFBOOL(this, a2: 0);
            }
            else
            {
              if ( v10 == (void *)1930428416 )
                goto LABEL_132;
              if ( v10 != (void *)1931476992 )
              {
                v13 = v10 == (void *)1932525568;
LABEL_131:
                if ( !v13 )
                  goto LABEL_170;
                goto LABEL_132;
              }
              v11 = D3DXShader::CShaderProgram::EmitANDIFBOOL(this, a2: 1);
            }
          }
          else if ( v10 == (void *)1892679680 )
          {
            v11 = D3DXShader::CShaderProgram::EmitPOW(this);
          }
          else
          {
            if ( v10 == (void *)1886388224 )
              goto LABEL_113;
            if ( v10 == (void *)1887436800 )
            {
              v11 = D3DXShader::CShaderProgram::EmitDP2ADD(this);
            }
            else
            {
              if ( v10 != (void *)1888485376 )
              {
                if ( v10 == (void *)1890582528 )
                  goto LABEL_44;
                if ( v10 != (void *)1891631104 )
                  goto LABEL_170;
LABEL_123:
                v11 = D3DXShader::CShaderProgram::EmitMAX(this);
                goto LABEL_158;
              }
              v11 = D3DXShader::CShaderProgram::EmitDST(this);
            }
          }
        }
        else
        {
          if ( v10 == (void *)1885339648 )
            goto LABEL_113;
          if ( (unsigned int)v10 > 0x70100000 )
          {
            if ( v10 == (void *)1881145344 )
            {
              v11 = D3DXShader::CShaderProgram::EmitNRM(this);
            }
            else
            {
              if ( v10 != (void *)1882193920 && v10 != (void *)1883242496 )
              {
                if ( v10 != (void *)1884291072 )
                  goto LABEL_170;
LABEL_113:
                v11 = D3DXShader::CShaderProgram::EmitMAT(this);
                goto LABEL_158;
              }
              v11 = D3DXShader::CShaderProgram::EmitMAD(this);
            }
          }
          else
          {
            if ( v10 == (void *)1880096768 )
            {
              v11 = D3DXShader::CShaderProgram::EmitLRP(this);
              goto LABEL_158;
            }
            if ( v10 == (void *)1627389952 )
            {
LABEL_107:
              v11 = D3DXShader::CShaderProgram::EmitTEXDD(this);
              goto LABEL_158;
            }
            if ( v10 == (void *)1628438528 )
              goto LABEL_105;
            if ( v10 == (void *)1629487104 )
              goto LABEL_75;
            if ( v10 == (void *)1630535680 )
              goto LABEL_89;
            if ( v10 != (void *)1879048192 )
              goto LABEL_170;
            v11 = D3DXShader::CShaderProgram::EmitABS(this);
          }
        }
      }
    }
    else
    {
      if ( v10 == (void *)1626341376 )
        goto LABEL_91;
      if ( (unsigned int)v10 > 0x20700000 )
      {
        if ( (unsigned int)v10 > 0x60400000 )
        {
          if ( (unsigned int)v10 > 0x60A00000 )
          {
            if ( v10 == (void *)1622147072 )
              goto LABEL_107;
            if ( v10 != (void *)1623195648 )
            {
              if ( v10 == (void *)1624244224 )
                goto LABEL_75;
              v12 = v10 == (void *)1625292800;
              goto LABEL_88;
            }
          }
          else
          {
            if ( v10 == (void *)1621098496 || v10 == (void *)1615855616 )
            {
LABEL_91:
              if ( (*((_BYTE *)this + 112) & 0x40) != 0 )
                goto LABEL_171;
              v11 = D3DXShader::CShaderProgram::EmitTEX(this);
              goto LABEL_158;
            }
            if ( v10 == (void *)1616904192 )
              goto LABEL_107;
            if ( v10 != (void *)1617952768 )
            {
              if ( v10 == (void *)1619001344 )
                goto LABEL_75;
              v12 = v10 == (void *)1620049920;
LABEL_88:
              if ( !v12 )
                goto LABEL_170;
LABEL_89:
              if ( (*((_BYTE *)this + 112) & 0x20) == 0 )
                goto LABEL_170;
              v11 = D3DXShader::CShaderProgram::EmitTEXLOD(this);
              goto LABEL_158;
            }
          }
          goto LABEL_105;
        }
        if ( v10 == (void *)1614807040 )
          goto LABEL_89;
        if ( (unsigned int)v10 > 0x50300000 )
        {
          if ( v10 == (void *)1610612736 )
            goto LABEL_91;
          if ( v10 == (void *)1611661312 )
            goto LABEL_107;
          if ( v10 != (void *)1612709888 )
          {
            if ( v10 != (void *)1613758464 )
              goto LABEL_170;
LABEL_75:
            if ( (*((_BYTE *)this + 112) & 0x40) != 0 )
              goto LABEL_171;
            v11 = D3DXShader::CShaderProgram::EmitTEXBias(this);
            goto LABEL_158;
          }
LABEL_105:
          if ( (*((_BYTE *)this + 112) & 0x40) != 0 )
            goto LABEL_171;
          v11 = D3DXShader::CShaderProgram::EmitTEXProj(this);
          goto LABEL_158;
        }
        if ( v10 == (void *)1345323008 )
        {
          v11 = D3DXShader::CShaderProgram::EmitSINCOS(this);
        }
        else
        {
          if ( v10 == (void *)545259520 )
            continue;
          if ( v10 == (void *)546308096 )
            goto LABEL_45;
          if ( v10 == (void *)805306368 )
          {
            if ( (*((_BYTE *)this + 112) & 0x40) != 0 )
              goto LABEL_171;
            v11 = D3DXShader::CShaderProgram::EmitCMP(this);
          }
          else if ( v10 == (void *)1342177280 )
          {
            v11 = D3DXShader::CShaderProgram::EmitDOT(this);
          }
          else
          {
            if ( v10 != (void *)1343225856 )
              goto LABEL_170;
            v11 = D3DXShader::CShaderProgram::EmitLIT(this);
          }
        }
      }
      else
      {
        if ( v10 == (void *)544210944 )
        {
          v11 = D3DXShader::CShaderProgram::EmitENDIF(this);
          goto LABEL_158;
        }
        if ( (unsigned int)v10 > 0x10F00000 )
        {
          if ( (unsigned int)v10 > 0x20100000 )
          {
            if ( v10 == (void *)538968064 )
            {
              v11 = D3DXShader::CShaderProgram::EmitLT(this);
            }
            else if ( v10 == (void *)540016640 )
            {
              v11 = D3DXShader::CShaderProgram::EmitGE(this);
            }
            else if ( v10 == (void *)541065216 )
            {
              v11 = D3DXShader::CShaderProgram::EmitADD(this);
            }
            else
            {
              if ( v10 != (void *)542113792 )
                goto LABEL_170;
              v11 = D3DXShader::CShaderProgram::EmitMUL(this);
            }
          }
          else
          {
            if ( v10 == (void *)537919488 )
              goto LABEL_123;
            if ( v10 != (void *)285212672 )
            {
              if ( v10 != (void *)287309824 )
              {
                if ( v10 == (void *)288358400 )
                  continue;
                if ( v10 != (void *)290455552 )
                {
                  if ( v10 != (void *)0x20000000 )
                    goto LABEL_170;
LABEL_44:
                  v11 = D3DXShader::CShaderProgram::EmitMIN(this);
                  goto LABEL_158;
                }
              }
LABEL_45:
              v11 = D3DXShader::CShaderProgram::EmitMOV(this);
              goto LABEL_158;
            }
            if ( (*((_BYTE *)this + 112) & 0x40) != 0 )
              goto LABEL_171;
            v11 = D3DXShader::CShaderProgram::EmitCLIP(this);
          }
        }
        else
        {
          if ( v10 == (void *)284164096 )
            goto LABEL_146;
          if ( (unsigned int)v10 > 0x10500000 )
          {
            if ( v10 == (void *)274726912 )
            {
              v11 = D3DXShader::CShaderProgram::EmitLOG(this);
            }
            else if ( v10 == (void *)275775488 )
            {
              v11 = D3DXShader::CShaderProgram::EmitRSQ(this);
            }
            else if ( v10 == (void *)282066944 )
            {
              if ( (*((_BYTE *)this + 112) & 0x10) != 0 )
                v11 = D3DXShader::CShaderProgram::EmitDSX(this);
              else
                v11 = -2147467263;
            }
            else
            {
              if ( v10 != (void *)283115520 )
                goto LABEL_170;
              if ( (*((_BYTE *)this + 112) & 0x10) != 0 )
                v11 = D3DXShader::CShaderProgram::EmitDSY(this);
              else
                v11 = -2147467263;
            }
          }
          else
          {
            if ( v10 == (void *)273678336 )
            {
              v11 = D3DXShader::CShaderProgram::EmitEXP(this);
              goto LABEL_158;
            }
            if ( v10 == nullptr )
            {
              v11 = D3DXShader::CShaderProgram::EmitVersion(pexcept: v14);
              goto LABEL_158;
            }
            if ( v10 == (void *)0x10000000 )
              goto LABEL_45;
            if ( v10 == &loc_10100000 )
            {
              v11 = D3DXShader::CShaderProgram::EmitNEG(this);
            }
            else if ( v10 == &unk_10300000 )
            {
              v11 = D3DXShader::CShaderProgram::EmitRCP(this);
            }
            else
            {
              if ( v10 != (void *)272629760 )
                goto LABEL_170;
              v11 = D3DXShader::CShaderProgram::EmitFRC(this);
            }
          }
        }
      }
    }
LABEL_158:
    if ( v11 == -2147467263 )
      goto LABEL_170;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10201B2C
// Name: int D3DXShader::IsTextureInst(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall D3DXShader::IsTextureInst(D3DXShader *this, unsigned int a2)
{
  return this == (D3DXShader *)1615855616
      || this == (D3DXShader *)1621098496
      || this == (D3DXShader *)1610612736
      || this == (D3DXShader *)1927282688
      || this == (D3DXShader *)1617952768
      || this == (D3DXShader *)1626341376;
}

//------------------------------------------------------------------------------
// Address: 0x10201B69
// Name: public: D3DXShader::CPSLegacyProgram::CPSLegacyProgram(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPSLegacyProgram *__thiscall D3DXShader::CPSLegacyProgram::CPSLegacyProgram(
        D3DXShader::CPSLegacyProgram *this)
{
  D3DXShader::CShaderProgram::CShaderProgram(this);
  *((_DWORD *)this + 271) = -1;
  *(_DWORD *)this = &D3DXShader::CPSLegacyProgram::`vftable';
  *((_DWORD *)this + 139) = 0;
  *((_DWORD *)this + 140) = 0;
  *((_DWORD *)this + 274) = 0;
  *((_DWORD *)this + 173) = 0;
  *((_DWORD *)this + 174) = 0;
  *((_DWORD *)this + 176) = 0;
  *((_DWORD *)this + 175) = 0;
  memset((char *)this + 708, 0, 0x40u);
  *((_DWORD *)this + 257) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10201BC5
// Name: public: virtual long D3DXShader::CPSLegacyProgram::GenerateCode(struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::GenerateCode(D3DXShader::CPSLegacyProgram *this, struct ID3DXBuffer **a2)
{
  _DWORD *v3; // edi

  memset((char *)this + 504, 0, 0x20u);
  *((_DWORD *)this + 134) = 0;
  *((_DWORD *)this + 135) = 0;
  *((_DWORD *)this + 136) = 0;
  *((_DWORD *)this + 137) = 0;
  v3 = (_DWORD *)((char *)this + 556);
  free(pMem: *((void **)this + 139));
  free(pMem: *((void **)this + 140));
  *v3 = 0;
  *((_DWORD *)this + 140) = 0;
  return D3DXShader::CShaderProgram::GenerateCode(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10201C25
// Name: protected: virtual long D3DXShader::CPSLegacyProgram::InitCaps(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::InitCaps(D3DXShader::CPSLegacyProgram *this)
{
  int v1; // edx
  int v2; // eax
  unsigned int v3; // eax

  v1 = *((_DWORD *)this + 50);
  v2 = *((_DWORD *)this + 27);
  *((_DWORD *)this + 12) = 0;
  *((_BYTE *)this + 205) |= 1u;
  *((_DWORD *)this + 28) |= 8u;
  *((_DWORD *)this + 66) = v1;
  v3 = v2 & 0xE98ED354 | 0x16712C8A;
  *((_DWORD *)this + 10) = 2;
  *((_DWORD *)this + 11) = 24;
  *((_DWORD *)this + 14) = 8;
  *((_DWORD *)this + 18) = 1;
  *((_DWORD *)this + 25) = 64;
  *((_DWORD *)this + 27) = v3;
  if ( (unsigned __int16)v1 == 260 )
  {
    *((_DWORD *)this + 20) = 0;
    *((_DWORD *)this + 15) = 6;
    *((_DWORD *)this + 17) = 8;
    *((_DWORD *)this + 19) = 6;
    *((_DWORD *)this + 27) = v3 & 0xFF712FCB | 0xD010;
  }
  else
  {
    *((_DWORD *)this + 15) = 4;
    *((_DWORD *)this + 17) = 6;
    *((_DWORD *)this + 19) = 4;
    *((_DWORD *)this + 27) = v3 & 0xFFFD2FFF | (((unsigned __int16)v1 == 257) << 17) | 0x208C0014;
    *((_DWORD *)this + 20) = 2;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10201CD8
// Name: protected: long D3DXShader::CPSLegacyProgram::ValidateTexSat(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::ValidateTexSat(D3DXShader::CPSLegacyProgram *this)
{
  unsigned int v1; // eax
  int v2; // esi
  int v3; // edi
  _DWORD *v4; // ebx
  int v5; // eax
  int v6; // edx
  int v8; // [esp+Ch] [ebp-10h]
  unsigned int v9; // [esp+10h] [ebp-Ch]
  int *i; // [esp+14h] [ebp-8h]
  unsigned int v11; // [esp+18h] [ebp-4h]

  v1 = *((_DWORD *)this + 19);
  v9 = v1;
  if ( v1 < *((_DWORD *)this + 137) )
  {
    for ( i = (int *)(*((_DWORD *)this + 140) + 4 * v1); ; ++i )
    {
      v2 = *i;
      if ( *i != 0 && *(_DWORD *)v2 != 0 )
      {
        v3 = *((_DWORD *)this + 5);
        if ( *(_DWORD *)(*(_DWORD *)(v3 + 4 * **(_DWORD **)(v2 + 16)) + 4) != *((_DWORD *)this + 33)
          || (*(_DWORD *)v2 & 0xFFF00000) != 0x10000000 )
        {
          v11 = 0;
          if ( *(_DWORD *)(v2 + 4) != 0 )
            break;
        }
      }
LABEL_15:
      if ( ++v9 >= *((_DWORD *)this + 137) )
        return 0;
    }
    v4 = *(_DWORD **)(v2 + 8);
    while ( 1 )
    {
      v5 = *(_DWORD *)(v3 + 4 * *v4);
      v8 = *(_DWORD *)(v5 + 60);
      while ( 1 )
      {
        v6 = *(_DWORD *)(v5 + 56);
        if ( v6 == -1 )
          break;
        v5 = *(_DWORD *)(v3 + 4 * v6);
      }
      if ( *(_BYTE *)(v5 + 108) == 3 && (((unsigned __int16)v8 | *(_WORD *)(v5 + 60)) & 0x200) == 0 )
        break;
      ++v11;
      ++v4;
      if ( v11 >= *(_DWORD *)(v2 + 4) )
        goto LABEL_15;
    }
    D3DXShader::CProgram::Warning(
      this,
      a2: *(struct D3DXShader::CNode **)(v2 + 60),
      a3: 0x1263u,
      format: "texcoord inputs used directly (that is, other than sampling from textures) in shader body in ps_1_%i are always cl"
      "amped from 0 to 1",
      (unsigned __int8)*((_DWORD *)this + 50));
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10201DB7
// Name: protected: long D3DXShader::CPSLegacyProgram::MatchTexldPR(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::MatchTexldPR(D3DXShader::CPSLegacyProgram *this)
{
  int v1; // eax
  int v2; // edx
  int v4; // ebx
  _DWORD *v5; // esi
  unsigned int v6; // edx
  int v7; // eax
  int v8; // edx
  _DWORD *v9; // eax
  unsigned int v10; // edi
  int v11; // edx
  int v12; // edx
  _DWORD *v13; // esi
  int v14; // [esp+4h] [ebp-10h]
  int v15; // [esp+8h] [ebp-Ch]
  int v16; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]
  int v18; // [esp+10h] [ebp-4h]

  v1 = *((_DWORD *)this + 5);
  v2 = *(_DWORD *)(*(_DWORD *)(v1 + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 28)) + 72);
  if ( v2 == -1 )
    return 1;
  v4 = *((_DWORD *)this + 6);
  v5 = *(_DWORD **)(v4 + 4 * v2);
  v6 = *v5 & 0xFFF00000;
  if ( v6 != 0x10000000 && v6 != 1342177280 )
    return 1;
  v16 = -1;
  v14 = *(_DWORD *)(*((_DWORD *)this + 64) + 8);
  v7 = *(_DWORD *)(v1 + 4 * *(_DWORD *)(v14 + 24));
  v15 = *(_DWORD *)(v14 + 24);
  v8 = *(_DWORD *)(v7 + 72);
  if ( v8 != -1 && *(_DWORD *)(v7 + 60) == 0 )
  {
    v9 = *(_DWORD **)(v4 + 4 * v8);
    if ( (*v9 & 0xFFF00000) == 0x10000000 )
    {
      for ( i = 0; i < v9[1]; ++i )
      {
        if ( *(_DWORD *)(v9[4] + 4 * i) == v15 )
          v16 = *(_DWORD *)(4 * i + v9[2]);
      }
    }
  }
  v18 = 0;
  if ( (*v5 & 0xFFF00000) == 0x10000000 )
  {
    v10 = 0;
    if ( v5[1] != 0 )
    {
      do
      {
        v11 = *(_DWORD *)(v5[2] + 4 * v10);
        if ( v11 == v15 && *(_DWORD *)(v5[4] + 4 * v10) == *(_DWORD *)(v14 + 28) )
          v18 = 1;
        if ( v11 == v16 && *(_DWORD *)(v5[4] + 4 * v10) == *(_DWORD *)(v14 + 28) )
          v18 = 1;
        ++v10;
      }
      while ( v10 < v5[1] );
      goto LABEL_28;
    }
    return 1;
  }
  v12 = v5[1];
  if ( v12 == 0 )
    return 1;
  v13 = (_DWORD *)v5[4];
  do
  {
    if ( v16 == *v13 )
      v18 = 1;
    ++v13;
    --v12;
  }
  while ( v12 != 0 );
LABEL_28:
  if ( v18 == 0 )
    return 1;
  **((_DWORD **)this + 64) = 1927282691;
  *(_DWORD *)(*((_DWORD *)this + 64) + 4) = 6;
  *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 12) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 16);
  *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 16) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 20);
  *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 20) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 24);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10201F3B
// Name: protected: long D3DXShader::CPSLegacyProgram::CleanUpClip(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::CleanUpClip(D3DXShader::CPSLegacyProgram *this)
{
  D3DXShader::CPSLegacyProgram *v1; // ebx
  int v2; // eax
  _DWORD *v3; // esi
  int v4; // ecx
  int v5; // edx
  _DWORD *v6; // eax
  unsigned int v7; // ecx
  _DWORD *v8; // eax
  int v9; // edx
  int v10; // eax
  int *v11; // edi
  _DWORD *v12; // esi
  int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // edx
  _DWORD *v16; // ecx
  unsigned int v17; // eax
  _DWORD *v18; // ecx
  _DWORD *v19; // edx
  _DWORD *v20; // eax
  int v21; // esi
  int v23; // [esp+Ch] [ebp-2Ch]
  int v24; // [esp+10h] [ebp-28h]
  int v26; // [esp+18h] [ebp-20h]
  int v27; // [esp+1Ch] [ebp-1Ch]
  int v28; // [esp+1Ch] [ebp-1Ch]
  int v29; // [esp+20h] [ebp-18h]
  int v30; // [esp+24h] [ebp-14h]
  unsigned int v31; // [esp+28h] [ebp-10h]
  unsigned int v32; // [esp+2Ch] [ebp-Ch]
  _DWORD *v33; // [esp+30h] [ebp-8h]
  _DWORD *j; // [esp+30h] [ebp-8h]
  unsigned int v35; // [esp+34h] [ebp-4h]
  unsigned int i; // [esp+34h] [ebp-4h]
  unsigned int v37; // [esp+34h] [ebp-4h]
  int v38; // [esp+34h] [ebp-4h]

  v1 = this;
  v2 = *((_DWORD *)this + 64);
  v26 = v2;
  if ( (*(_DWORD *)v2 & 0xFFFFF) == 4 && *(_DWORD *)(v2 + 4) == 4 )
  {
    v3 = *(_DWORD **)(v2 + 8);
    v4 = v3[3];
    v35 = 0;
    v23 = v4;
    v33 = *(_DWORD **)(*((_DWORD *)v1 + 64) + 8);
    while ( *v33 != *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v1 + 64) + 8) + 12) )
    {
      ++v35;
      ++v33;
      if ( v35 >= 3 )
      {
        v5 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v1 + 5) + 4 * v4) + 72);
        v27 = -1;
        v24 = v5;
        if ( v5 != -1 )
        {
          v6 = *(_DWORD **)(*((_DWORD *)v1 + 6) + 4 * v5);
          if ( (*v6 & 0xFFF00000) == 0x10000000 )
          {
            for ( i = 0; i < v6[3]; ++i )
            {
              if ( v4 == *(_DWORD *)(v6[4] + 4 * i) )
                v27 = *(_DWORD *)(4 * i + v6[2]);
            }
          }
        }
        v7 = 0;
        v8 = v3;
        while ( *v8 != v27 )
        {
          ++v7;
          ++v8;
          if ( v7 >= 3 )
          {
            v28 = 0;
            for ( j = v3; ; ++j )
            {
              v9 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v1 + 5) + 4 * *j) + 72);
              if ( v9 != -1 )
              {
                v10 = *((_DWORD *)v1 + 6);
                v11 = *(int **)(v10 + 4 * v24);
                v12 = *(_DWORD **)(v10 + 4 * v9);
                v13 = *v11;
                if ( ((*v12 ^ *v11) & 0xFFF00000) == 0 )
                {
                  v14 = *v12 & 0xFFFFF;
                  v32 = v13 & 0xFFFFF;
                  v31 = v14;
                  if ( (v13 & 0xFFFFF) != 0 && v14 != 0 )
                  {
                    v29 = v11[1] / v32;
                    if ( v29 == v12[1] / v14 && v32 == v11[3] )
                    {
                      v15 = v12[3];
                      if ( v14 == v15 )
                      {
                        v30 = -1;
                        v37 = 0;
                        if ( v15 != 0 )
                        {
                          v16 = (_DWORD *)v12[4];
                          while ( *v16 != *j )
                          {
                            ++v37;
                            ++v16;
                            if ( v37 >= v15 )
                              goto LABEL_30;
                          }
                          v30 = v37;
                        }
LABEL_30:
                        v17 = 0;
                        if ( v15 != 0 )
                        {
                          v18 = (_DWORD *)v11[4];
                          while ( *v18 != v23 )
                          {
                            ++v17;
                            ++v18;
                            if ( v17 >= v12[3] )
                              goto LABEL_43;
                          }
                          if ( v17 != -1 && v30 != -1 )
                          {
                            v38 = 1;
                            if ( v29 == 0 )
                              break;
                            v19 = (_DWORD *)(v11[2] + 4 * v17);
                            v20 = (_DWORD *)(v12[2] + 4 * v30);
                            v21 = v11[1] / v32;
                            do
                            {
                              if ( *v19 != *v20 )
                                v38 = 0;
                              v20 += v31;
                              v19 += v32;
                              --v21;
                            }
                            while ( v21 != 0 );
                            v1 = this;
                            if ( v38 != 0 )
                              break;
                          }
                        }
                      }
                    }
                  }
                }
              }
LABEL_43:
              if ( (unsigned int)++v28 >= 3 )
              {
                D3DXShader::CProgram::Error(
                  this: v1,
                  a2: *(struct D3DXShader::CNode **)(v26 + 60),
                  a3: 0x11C0u,
                  format: "Clip must be from a 3 vector in ps_1_%i",
                  (unsigned __int8)*((_DWORD *)v1 + 50));
                return -2147467259;
              }
            }
            **((_DWORD **)v1 + 64) = 285212675;
            *(_DWORD *)(*((_DWORD *)v1 + 64) + 4) = 3;
            *(_DWORD *)(*((_DWORD *)v1 + 64) + 12) = 3;
            return 0;
          }
        }
        break;
      }
    }
    *(_DWORD *)v26 = 285212675;
    return 0;
  }
  else
  {
    D3DXShader::CProgram::Error(
      this,
      a2: *(struct D3DXShader::CNode **)(v2 + 60),
      a3: 0x12D4u,
      format: "internal error: malformed clip found");
    return -2147467259;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102021C3
// Name: protected: long D3DXShader::CPSLegacyProgram::MatchClip(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::MatchClip(D3DXShader::CPSLegacyProgram *this)
{
  struct D3DXShader::CInstruction *v2; // edx
  int result; // eax
  _DWORD *v4; // edi
  unsigned int v5[40]; // [esp+8h] [ebp-F4h] BYREF
  struct D3DXShader::CInstruction *v6; // [esp+A8h] [ebp-54h] BYREF
  unsigned int v7[4]; // [esp+E8h] [ebp-14h] BYREF
  unsigned int v8; // [esp+F8h] [ebp-4h] BYREF

  v8 = 0;
  v7[0] = 0;
  v2 = *((struct D3DXShader::CInstruction **)this + 64);
  result = 1;
  v7[1] = 1;
  v7[2] = 2;
  v7[3] = 3;
  if ( (*(_DWORD *)v2 & 0xFFFFF) == 3 )
  {
    result = D3DXShader::CShaderProgram::MatchComplexTree(
               this,
               a2: v2,
               a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BBBB8,
               a4: &v6,
               a5: &v8,
               a6: v5,
               a7: v7,
               a8: 3u,
               a9: 1);
    if ( result == 0 )
    {
      v4 = *(_DWORD **)(*((_DWORD *)this + 64) + 8);
      *v4++ = v5[0];
      *v4 = v5[1];
      v4[1] = v5[2];
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020223D
// Name: protected: long D3DXShader::CPSLegacyProgram::FixSatTex(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::FixSatTex(D3DXShader::CPSLegacyProgram *this)
{
  int v1; // eax
  int v2; // edx
  int v3; // edi
  int v4; // edx
  unsigned int v5; // esi
  int v6; // eax
  unsigned int j; // edx
  int v8; // eax
  unsigned int v10; // [esp+0h] [ebp-14h]
  _DWORD *v11; // [esp+4h] [ebp-10h]
  int v12; // [esp+8h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-8h]
  unsigned int v14; // [esp+10h] [ebp-4h]

  if ( (**((_DWORD **)this + 64) & 0xFFF00000) == 0x10000000 && (unsigned __int16)*((_DWORD *)this + 50) < 0x104u )
  {
    v1 = *((_DWORD *)this + 64);
    v2 = *((_DWORD *)this + 5);
    v3 = *(_DWORD *)(v2 + 4 * **(_DWORD **)(v1 + 8));
    v4 = *(_DWORD *)(v2 + 4 * **(_DWORD **)(v1 + 16));
    v5 = *(_DWORD *)v1 & 0xFFFFF;
    v10 = v5;
    if ( *(_DWORD *)(v3 + 60) == 0
      && (*(_BYTE *)(v4 + 61) & 2) != 0
      && *(_BYTE *)(v3 + 108) == 3
      && *(_DWORD *)(v4 + 4) == *((_DWORD *)this + 34) )
    {
      for ( i = 0; i < v5; ++i )
      {
        v12 = 4 * i;
        v6 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(4 * i + *(_DWORD *)(*((_DWORD *)this + 64) + 8)));
        *(_BYTE *)(v6 + 61) |= 2u;
        for ( j = *((_DWORD *)this + 63); j < *((_DWORD *)this + 3); ++j )
        {
          v8 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * j);
          v14 = 0;
          if ( *(_DWORD *)(v8 + 4) != 0 )
          {
            do
            {
              v11 = (_DWORD *)(*(_DWORD *)(v8 + 8) + 4 * v14);
              if ( *v11 == *(_DWORD *)(v12 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)) )
                *v11 = *(_DWORD *)(v12 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
              ++v14;
            }
            while ( v14 < *(_DWORD *)(v8 + 4) );
            v5 = v10;
          }
        }
      }
      **((_DWORD **)this + 64) = 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10202369
// Name: protected: long D3DXShader::CPSLegacyProgram::FixNeg(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::FixNeg(D3DXShader::CPSLegacyProgram *this)
{
  _DWORD *v2; // edi
  int v4; // eax
  int v5; // ecx
  unsigned int v6; // esi
  int v7; // eax
  int v8; // edi
  unsigned __int8 *v9; // eax
  int v10; // edi
  unsigned int v11; // eax
  int v12; // eax
  void **v13; // edx
  unsigned int i; // ecx
  D3DXShader::CInstruction *v15; // ecx
  int v16; // [esp+18h] [ebp-Ch]
  _DWORD *v17; // [esp+1Ch] [ebp-8h]
  unsigned int v18; // [esp+1Ch] [ebp-8h]
  BOOL v19; // [esp+20h] [ebp-4h]
  void **v20; // [esp+20h] [ebp-4h]

  v2 = *((_DWORD **)this + 64);
  if ( (_UNKNOWN *)(*v2 & 0xFFF00000) != &loc_10100000 )
    return 0;
  v4 = *((_DWORD *)this + 64);
  v5 = *((_DWORD *)this + 5);
  v6 = *(_DWORD *)v4 & 0xFFFFF;
  v19 = (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4
                                                       * *(_DWORD *)(*(_DWORD *)(v5 + 4 * **(_DWORD **)(v4 + 8)) + 4))
                   + 4)
       & 0x200) != 0;
  if ( (*((_BYTE *)this + 110) & 2) != 0 && v6 != 0 )
  {
    v17 = (_DWORD *)v2[2];
    v16 = *(_DWORD *)v4 & 0xFFFFF;
    do
    {
      v7 = *(_DWORD *)(v5 + 4 * *v17);
      if ( (*(_DWORD *)(v7 + 60) & 0x200) != 0 )
        v19 = true;
      v8 = *(_DWORD *)(v7 + 56);
      if ( v8 != -1 )
        v7 = *(_DWORD *)(v5 + 4 * v8);
      if ( (*(_DWORD *)(v7 + 60) & 0x200) != 0 )
        v19 = true;
      ++v17;
      --v16;
    }
    while ( v16 != 0 );
  }
  if ( !v19 )
    return 0;
  v9 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v9 != nullptr )
    v20 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v9);
  else
    v20 = nullptr;
  if ( v20 == nullptr )
    return -2147024882;
  v10 = D3DXShader::CInstruction::Initialize(
          this: (D3DXShader::CInstruction *)v20,
          a2: v6 & 0xFFFFF | 0x20500000,
          a3: 2 * v6,
          a4: v6,
          a5: 0);
  if ( v10 >= 0 )
  {
    v10 = D3DXShader::CInstruction::Instance(
            this: (D3DXShader::CInstruction *)v20,
            a2: *((struct D3DXShader::CInstruction **)this + 64));
    if ( v10 >= 0 )
    {
      v11 = D3DXShader::CBaseProgram::AddPool(
              this,
              a2: (char *)&stru_102A6BD8.m_Memory.m_nGrowSize,
              a3: 0x311u,
              a4: 1u,
              a5: 4u);
      if ( v11 == -1 || (v18 = D3DXShader::CBaseProgram::AddArgument(this, a2: v11, a3: 0, a4: 0, a5: -1.0)) == -1 )
      {
        v10 = -2147024882;
      }
      else
      {
        v12 = 4 * v6;
        qmemcpy(v20[2], *(const void **)(*((_DWORD *)this + 64) + 8), 4 * v6);
        v13 = v20;
        qmemcpy(v20[4], *(const void **)(*((_DWORD *)this + 64) + 16), 4 * v6);
        for ( i = v6; i != 0; --i )
        {
          *(_DWORD *)((char *)v20[2] + v12) = v18;
          v12 += 4;
        }
        v15 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)this + 63));
        v10 = 0;
        if ( v15 != nullptr )
        {
          D3DXShader::CInstruction::`scalar deleting destructor'(this: v15, a2: 1);
          v13 = v20;
        }
        *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)this + 63)) = v13;
        v20 = nullptr;
      }
    }
  }
  if ( v20 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v20, a2: 1);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10202563
// Name: protected: long D3DXShader::CPSLegacyProgram::PackOutput(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::PackOutput(D3DXShader::CPSLegacyProgram *this)
{
  int v1; // edx
  _DWORD *v2; // esi
  int v3; // eax
  unsigned int v4; // edi
  int v5; // esi
  unsigned int v6; // esi
  int v7; // ebx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // eax
  unsigned int v11; // esi
  _DWORD *v12; // eax
  _DWORD *v13; // esi
  _DWORD *v14; // edx
  int v15; // edx
  _DWORD *v16; // eax
  _DWORD *v17; // edx
  unsigned int v18; // edi
  unsigned int v19; // esi
  _DWORD *v20; // eax
  int v21; // edx
  unsigned int v23; // [esp+10h] [ebp-20h]
  int v24; // [esp+14h] [ebp-1Ch]
  int i; // [esp+14h] [ebp-1Ch]
  _DWORD *v26; // [esp+18h] [ebp-18h]
  _DWORD **v27; // [esp+1Ch] [ebp-14h]
  _DWORD **v28; // [esp+1Ch] [ebp-14h]
  _DWORD *v29; // [esp+20h] [ebp-10h]
  int v30; // [esp+24h] [ebp-Ch]
  unsigned int j; // [esp+24h] [ebp-Ch]
  unsigned int v32; // [esp+28h] [ebp-8h]
  unsigned int v33; // [esp+2Ch] [ebp-4h]

  v1 = *((_DWORD *)this + 137);
  v2 = *(_DWORD **)(*((_DWORD *)this + 140) + 4 * v1 - 4);
  v29 = v2;
  if ( v2 == nullptr || *v2 != 268435460 )
    return 0;
  v3 = *((_DWORD *)this + 5);
  v4 = 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(v3 + 4 * *(_DWORD *)(v4 + v2[4]));
    if ( *(_DWORD *)(v5 + 4) != *((_DWORD *)this + 33)
      || *(_DWORD *)(v5 + 60) != 0
      || (*(_BYTE *)(*(_DWORD *)(v3 + 4 * *(_DWORD *)(v4 + v29[2])) + 62) & 0x1F) != 0 )
    {
      return 0;
    }
    v4 += 4;
    if ( v4 >= 0x10 )
      break;
    v2 = *(_DWORD **)(*((_DWORD *)this + 140) + 4 * v1 - 4);
  }
  v32 = 0;
  v30 = 1;
  v33 = v1 - 1;
  v26 = (_DWORD *)v29[2];
  do
  {
    v6 = 0;
    v7 = 0;
    if ( v33 != 0 )
    {
      v27 = *((_DWORD ***)this + 140);
      do
      {
        v8 = *v27;
        if ( *v27 != nullptr && *v8 != 0 )
        {
          v9 = v8[3];
          if ( v9 != 0 )
          {
            v10 = (_DWORD *)v8[4];
            do
            {
              if ( *v10 == *v26 )
                v7 = 1;
              ++v10;
              --v9;
            }
            while ( v9 != 0 );
          }
          if ( v7 != 0 )
            break;
        }
        ++v27;
        ++v6;
      }
      while ( v6 < v33 );
    }
    if ( (unsigned __int16)*((_DWORD *)this + 50) != 260 )
    {
      if ( v6 >= *((_DWORD *)this + 19) )
        goto LABEL_27;
LABEL_26:
      v30 = 0;
      goto LABEL_27;
    }
    if ( v6 < *((_DWORD *)this + 19) && v6 != 0 )
      goto LABEL_26;
LABEL_27:
    if ( v7 == 0 )
      return 0;
    v11 = v6 + 1;
    if ( v11 < v33 )
    {
      v28 = (_DWORD **)(*((_DWORD *)this + 140) + 4 * v11);
      v23 = v33 - v11;
      do
      {
        v12 = *v28;
        if ( *v28 != nullptr && *v12 != 0 )
        {
          if ( v12[3] != 0 )
          {
            v13 = (_DWORD *)v12[4];
            v24 = v12[3];
            do
            {
              v14 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *v13);
              if ( v14[1] == *((_DWORD *)this + 34) && v14[4] == v32 && v14[3] == 0 )
                v30 = 0;
              ++v13;
              --v24;
            }
            while ( v24 != 0 );
          }
          v15 = v12[1];
          if ( v15 != 0 )
          {
            v16 = (_DWORD *)v12[2];
            for ( i = v15; i != 0; --i )
            {
              v17 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *v16);
              if ( v17[1] == *((_DWORD *)this + 34) && v17[4] == v32 && v17[3] == 0 )
                v30 = 0;
              ++v16;
            }
          }
        }
        ++v28;
        --v23;
      }
      while ( v23 != 0 );
    }
    ++v32;
    ++v26;
  }
  while ( v32 < 4 );
  v18 = 0;
  if ( v30 != 0 )
  {
    do
    {
      v19 = 0;
      for ( j = 0; j < v33; v33 = *((_DWORD *)this + 137) - 1 )
      {
        v20 = *(_DWORD **)(*((_DWORD *)this + 140) + 4 * j);
        if ( v20 != nullptr && *v20 != 0 && v20[3] != 0 )
        {
          do
          {
            v21 = *(_DWORD *)(v20[4] + 4 * v19);
            if ( v21 == *(_DWORD *)(v18 + v29[2]) )
              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v21) + 12) = 0;
            ++v19;
          }
          while ( v19 < v20[3] );
          v19 = 0;
        }
        ++j;
      }
      v18 += 4;
    }
    while ( v18 < 0x10 );
    *v29 = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102027A5
// Name: protected: long D3DXShader::CPSLegacyProgram::MovConsts(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::MovConsts(D3DXShader::CPSLegacyProgram *this)
{
  int *v2; // edx
  int v3; // ecx
  unsigned int v4; // eax
  unsigned __int8 *v5; // eax
  D3DXShader::CInstruction *v6; // edi
  int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  int v10; // edx
  bool v11; // cf
  unsigned int v12; // ecx
  int v14; // esi
  int v15; // [esp+14h] [ebp-10h]
  int v16; // [esp+18h] [ebp-Ch]
  unsigned int v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]

  v18 = 0;
  if ( *((_DWORD *)this + 19) == 0 )
    return 0;
  while ( 1 )
  {
    v2 = *(int **)(*((_DWORD *)this + 140) + 4 * v18);
    if ( v2 != nullptr )
    {
      v3 = *v2;
      v4 = *v2 & 0xFFF00000;
      if ( v4 != 1913651200 && v4 != 0 )
      {
        v17 = v3 & 0xFFFFF;
        v16 = 4 * (v4 != 285212672 ? v3 & 0xFFFFF : 0);
        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                   + 4
                                   * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v16 + v2[2])) + 4))
                       + 5)
            & 2) != 0 )
        {
          v5 = D3DXShader::CInstruction::operator new(a1: 0x74u);
          if ( v5 != nullptr )
            v6 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v5);
          else
            v6 = nullptr;
          if ( v6 == nullptr )
            return -2147024882;
          v7 = D3DXShader::CInstruction::Initialize(this: v6, a2: v17 & 0xFFFFF | 0x10000000, a3: v17, a4: v17, a5: 0);
          if ( v7 < 0 )
            break;
          v7 = D3DXShader::CInstruction::Instance(
                 this: v6,
                 a2: *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 140) + 4 * v18));
          if ( v7 < 0 )
            break;
          v8 = 0;
          v15 = 0;
          if ( v17 != 0 )
          {
            do
            {
              v9 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: v8, a5: 0.0);
              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v9) + 60) = 0;
              *(_DWORD *)(*((_DWORD *)v6 + 4) + 4 * v8) = v9;
              *(_DWORD *)(*((_DWORD *)v6 + 2) + 4 * v15) = *(_DWORD *)(v16
                                                                     + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 140)
                                                                                             + 4 * v18)
                                                                                 + 8));
              v10 = v16;
              v16 += 4;
              v8 = v15 + 1;
              v11 = v15 + 1 < v17;
              *(_DWORD *)(v10 + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 140) + 4 * v18) + 8)) = v9;
              ++v15;
            }
            while ( v11 );
          }
          v12 = *((_DWORD *)this + 136);
          if ( v12 >= 0x200 )
          {
            v14 = -2147024882;
            goto LABEL_21;
          }
          *(_DWORD *)(*((_DWORD *)this + 139) + 4 * v12) = v6;
          ++*((_DWORD *)this + 136);
          v7 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v6);
          if ( v7 < 0 )
            break;
        }
      }
    }
    if ( (unsigned int)++v18 >= *((_DWORD *)this + 19) )
      return 0;
  }
  v14 = v7;
LABEL_21:
  D3DXShader::CInstruction::`scalar deleting destructor'(this: v6, a2: 1);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10202958
// Name: protected: long D3DXShader::CPSLegacyProgram::CheckDegenShader(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::CheckDegenShader(D3DXShader::CPSLegacyProgram *this)
{
  unsigned __int8 *v2; // eax
  D3DXShader::CInstruction *v3; // edi
  int v5; // eax
  unsigned int i; // ecx
  int v7; // eax
  unsigned int j; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // esi
  unsigned int v12; // eax
  int v13; // eax
  unsigned int v14; // ecx
  _DWORD *v15; // eax
  unsigned int v16; // [esp+14h] [ebp-14h]
  unsigned int v17; // [esp+18h] [ebp-10h]
  unsigned int k; // [esp+1Ch] [ebp-Ch]
  int v19; // [esp+20h] [ebp-8h]
  int v20; // [esp+24h] [ebp-4h]
  int v21; // [esp+24h] [ebp-4h]

  v17 = *((_DWORD *)this + 3);
  v2 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v2 != nullptr )
    v3 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return -2147024882;
  v5 = D3DXShader::CInstruction::Initialize(this: v3, a2: 0x10000004u, a3: 4u, a4: 4u, a5: 0);
  if ( v5 < 0 )
  {
LABEL_15:
    v11 = v5;
LABEL_16:
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v3, a2: 1);
    return v11;
  }
  else
  {
    v20 = -1;
    for ( i = 0; i < *((_DWORD *)this + 2); ++i )
    {
      v7 = 4 * i;
      if ( *(_DWORD *)(*(_DWORD *)(4 * i + *((_DWORD *)this + 5)) + 4) == *((_DWORD *)this + 33) )
      {
        *(_DWORD *)(*((_DWORD *)v3 + 2) + 4 * *(_DWORD *)(*(_DWORD *)(v7 + *((_DWORD *)this + 5)) + 16)) = i;
        *(_DWORD *)(*(_DWORD *)(v7 + *((_DWORD *)this + 5)) + 4) = *((_DWORD *)this + 34);
        *(_DWORD *)(*(_DWORD *)(v7 + *((_DWORD *)this + 5)) + 12) = -1;
        v20 = *(_DWORD *)(*(_DWORD *)(v7 + *((_DWORD *)this + 5)) + 108);
      }
    }
    for ( j = 0; j < 4; ++j )
    {
      *(_DWORD *)(*((_DWORD *)v3 + 4) + 4 * j) = D3DXShader::CBaseProgram::AddArgument(
                                                   this,
                                                   a2: *((_DWORD *)this + 33),
                                                   a3: 0,
                                                   a4: j,
                                                   a5: 0.0);
      v9 = *((_DWORD *)v3 + 4);
      if ( *(_DWORD *)(v9 + 4 * j) == -1 )
      {
        v11 = -2147024882;
        goto LABEL_16;
      }
      v10 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v9 + 4 * j));
      *(_DWORD *)(v10 + 60) = 0;
      *(_DWORD *)(v10 + 108) = v20;
    }
    v5 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v3);
    if ( v5 < 0 )
      goto LABEL_15;
    v12 = 0;
    for ( k = 0; k < v17; ++k )
    {
      v13 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v12);
      v19 = v13;
      if ( v13 != 0 )
      {
        v16 = *(_DWORD *)(v13 + 12);
        if ( v16 != 0
          && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v13 + 16)) + 4) == *((_DWORD *)this + 33) )
        {
          v21 = 0;
          while ( 1 )
          {
            v14 = 0;
            while ( 1 )
            {
              v15 = (_DWORD *)(*(_DWORD *)(v13 + 16) + 4 * v21);
              if ( *v15 == *(_DWORD *)(v14 + *((_DWORD *)v3 + 4)) )
                *v15 = *(_DWORD *)(v14 + *((_DWORD *)v3 + 2));
              v14 += 4;
              if ( v14 >= 0x10 )
                break;
              v13 = v19;
            }
            if ( ++v21 >= v16 )
              break;
            v13 = v19;
          }
        }
      }
      v12 = k + 1;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202AF8
// Name: protected: int D3DXShader::CPSProgram::ValidSwizzle(unsigned int __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSProgram::ValidSwizzle(D3DXShader::CPSProgram *this, unsigned int *a2, unsigned int *a3)
{
  unsigned int *v3; // eax
  unsigned int v4; // esi

  v3 = a2;
  v4 = 0;
  while ( *v3 == -1 || *v3 == *(unsigned int *)((char *)v3 + (char *)a3 - (char *)a2) )
  {
    ++v4;
    ++v3;
    if ( v4 >= 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10202B29
// Name: int D3DXShader::IsValidSwizzle(unsigned int __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::IsValidSwizzle(D3DXShader *this, unsigned int *a2, unsigned int *a3, unsigned int a4)
{
  _DWORD *v4; // ecx
  unsigned int *v5; // eax
  int v6; // esi
  int i; // edx
  int v9; // [esp+Ch] [ebp-4h]

  v9 = 0;
  if ( a3 == nullptr )
    return 0;
  v4 = &D3DXShader::g_SwizzleL;
  while ( 1 )
  {
    v5 = a2;
    v6 = 1;
    for ( i = 4; i != 0; --i )
    {
      if ( *(unsigned int *)((char *)v5 + this - (D3DXShader *)a2) != *v4 && *v5 != -1 )
        v6 = 0;
      ++v4;
      ++v5;
    }
    if ( v6 != 0 )
      break;
    if ( ++v9 >= (unsigned int)a3 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10202B84
// Name: protected: int D3DXShader::CPSLegacyProgram::HasWriteMask(class D3DXShader::CInstruction __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::HasWriteMask(
        D3DXShader::CPSLegacyProgram *this,
        struct D3DXShader::CInstruction *a2)
{
  unsigned int v2; // edx
  unsigned int v3; // edi
  int v4; // esi
  _DWORD *v5; // eax
  unsigned int v6; // ecx
  int v7; // ecx
  int v8; // edx
  unsigned int i; // eax
  _DWORD v11[4]; // [esp+Ch] [ebp-14h] BYREF
  int v12; // [esp+1Ch] [ebp-4h]

  v12 = 0;
  memset(v11, 0, sizeof(v11));
  v2 = *((_DWORD *)a2 + 3);
  v3 = 0;
  if ( v2 != 0 )
  {
    v4 = *((_DWORD *)this + 5);
    v5 = *((_DWORD **)a2 + 4);
    while ( 1 )
    {
      v6 = *(_DWORD *)(*(_DWORD *)(v4 + 4 * *v5) + 16);
      if ( v6 > 3 )
        return 0;
      ++v3;
      ++v5;
      v11[v6] = 1;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v7 = 0;
    v8 = 1;
    for ( i = 0; i < 3; ++i )
    {
      if ( v11[i] != 0 )
        v8 = 0;
      else
        v7 = 1;
    }
    if ( v7 != 0 && v8 == 0 )
      return 1;
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202BFC
// Name: protected: long D3DXShader::CPSLegacyProgram::EmmulateReplicate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::EmmulateReplicate(D3DXShader::CPSLegacyProgram *this)
{
  unsigned int v2; // eax
  bool i; // cf
  struct D3DXShader::CInstruction *v4; // esi
  int v5; // eax
  unsigned int v6; // eax
  D3DXShader *v7; // edi
  unsigned int v8; // edx
  _DWORD *v9; // eax
  int v10; // ecx
  unsigned int v11; // ecx
  int v12; // edx
  D3DXShader *v13; // ecx
  unsigned int j; // eax
  int v15; // edi
  unsigned int v16; // eax
  unsigned __int8 *v17; // eax
  int v18; // edi
  int v19; // edi
  unsigned int v20; // eax
  int v21; // ecx
  double v22; // st7
  unsigned int v23; // eax
  int v24; // eax
  int v25; // ecx
  D3DXShader::CInstruction *v26; // eax
  _DWORD *v27; // edi
  unsigned int v28; // ecx
  _DWORD *v29; // edi
  int v30; // eax
  unsigned int v31; // eax
  struct D3DXShader::CInstruction *v32; // ecx
  unsigned __int8 *v33; // eax
  unsigned int v34; // eax
  int v35; // ecx
  D3DXShader::CInstruction *v36; // edx
  unsigned int v38; // [esp-Ch] [ebp-108h]
  unsigned int v39; // [esp+8h] [ebp-F4h]
  unsigned int v40[20]; // [esp+14h] [ebp-E8h] BYREF
  _DWORD v41[12]; // [esp+64h] [ebp-98h] BYREF
  _DWORD v42[4]; // [esp+94h] [ebp-68h]
  _DWORD v43[4]; // [esp+A4h] [ebp-58h]
  _DWORD v44[4]; // [esp+B4h] [ebp-48h]
  unsigned int v45; // [esp+C4h] [ebp-38h]
  unsigned int v46; // [esp+C8h] [ebp-34h]
  unsigned int v47; // [esp+CCh] [ebp-30h]
  unsigned int v48; // [esp+D0h] [ebp-2Ch]
  struct D3DXShader::CInstruction *v49; // [esp+D4h] [ebp-28h]
  int v50; // [esp+D8h] [ebp-24h]
  unsigned int v51; // [esp+DCh] [ebp-20h]
  D3DXShader *v52; // [esp+E0h] [ebp-1Ch]
  D3DXShader::CArgument *v53; // [esp+E4h] [ebp-18h]
  int v54; // [esp+E8h] [ebp-14h]
  unsigned int v55; // [esp+ECh] [ebp-10h]
  unsigned int k; // [esp+F0h] [ebp-Ch]
  D3DXShader::CInstruction *v57; // [esp+F4h] [ebp-8h]
  D3DXShader::CInstruction *v58; // [esp+F8h] [ebp-4h]

  v58 = nullptr;
  v57 = nullptr;
  v2 = *((_DWORD *)this + 19);
  v45 = *((_DWORD *)this + 137);
  for ( i = v2 < v45; ; i = v47 + 1 < v45 )
  {
    v47 = v2;
    if ( !i )
    {
      v18 = 0;
      goto LABEL_65;
    }
    v49 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 140) + 4 * v2);
    v4 = v49;
    if ( v49 == nullptr )
      goto LABEL_62;
    v5 = *(_DWORD *)v49;
    if ( *(_DWORD *)v49 == 0 )
      goto LABEL_62;
    v55 = v5 & 0xFFFFF;
    v6 = *((_DWORD *)v49 + 1) / (v5 & 0xFFFFFu);
    v51 = 0;
    v46 = v6;
    if ( v6 != 0 )
      break;
LABEL_54:
    v33 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v33 != nullptr )
      v57 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v33);
    else
      v57 = nullptr;
    if ( v57 == nullptr || (D3DXShader::CBaseProgram::AddInstruction(this, a2: v57) & 0x80000000) != 0 )
      goto LABEL_70;
    v18 = D3DXShader::CInstruction::Initialize(this: v57, a2: v4);
    if ( v18 < 0 )
      goto LABEL_67;
    v34 = *((_DWORD *)this + 137);
    if ( v34 >= 0x200 )
      goto LABEL_70;
    v35 = *((_DWORD *)this + 140);
    v36 = v57;
    v57 = nullptr;
    *(_DWORD *)(v35 + 4 * v34) = v36;
    ++*((_DWORD *)this + 137);
    *(_DWORD *)v4 = 0;
LABEL_62:
    v2 = v47 + 1;
  }
  v54 = 0;
  v52 = (D3DXShader *)v41;
  while ( 1 )
  {
    v7 = v52;
    *(_DWORD *)v52 = -1;
    v7 = (D3DXShader *)((char *)v7 + 4);
    *(_DWORD *)v7 = -1;
    v7 = (D3DXShader *)((char *)v7 + 4);
    *(_DWORD *)v7 = -1;
    *((_DWORD *)v7 + 1) = -1;
    memset(v40, 255, 16);
    v8 = 0;
    v50 = 0;
    v48 = 0;
    if ( v55 == 0 )
      goto LABEL_27;
    v53 = (D3DXShader::CArgument *)(*(_DWORD *)v4 & 0xFFF00000);
    v9 = (_DWORD *)(v54 + *((_DWORD *)v4 + 2));
    do
    {
      v10 = *((_DWORD *)this + 5);
      k = *(_DWORD *)(v10 + 4 * *v9);
      if ( v53 != (D3DXShader::CArgument *)1342177280 && v55 == *((_DWORD *)v4 + 3) )
        v8 = *(_DWORD *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)(*((_DWORD *)v4 + 4) + 4 * v8)) + 16);
      v11 = v8 + 4 * v51;
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(k + 4)) + 5) & 1) != 0 )
        v41[v11] = v8;
      else
        v41[v11] = *(_DWORD *)(k + 16);
      if ( v8 == 3 )
        v50 = 1;
      v40[v8] = 0;
      v8 = v48 + 1;
      ++v9;
      ++v48;
    }
    while ( v48 < v55 );
    if ( v50 == 0 )
      goto LABEL_27;
    v12 = 1;
    if ( v55 != 1 || v53 == (D3DXShader::CArgument *)1342177280 && *((_DWORD *)v4 + 3) == 1 )
      goto LABEL_27;
    v13 = v52;
    for ( j = 0; j < 4; ++j )
    {
      if ( *(_DWORD *)v13 != dword_10336770[j] && v40[j] != -1 )
        v12 = 0;
      v13 = (D3DXShader *)((char *)v13 + 4);
    }
    if ( v12 == 0 )
    {
LABEL_27:
      if ( D3DXShader::IsValidSwizzle(this: v52, a2: v40, a3: (unsigned int *)2, a4: v39) == 0 )
        break;
    }
LABEL_53:
    ++v51;
    v52 = (D3DXShader *)((char *)v52 + 16);
    v54 += 4 * v55;
    if ( v51 >= v46 )
      goto LABEL_54;
  }
  v15 = 0;
  while ( 1 )
  {
    v16 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: 3u, a5: 0.0);
    v44[v15] = v16;
    if ( v16 == -1 )
      break;
    if ( ++v15 != 0 )
    {
      v17 = D3DXShader::CInstruction::operator new(a1: 0x74u);
      if ( v17 != nullptr )
        v58 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v17);
      else
        v58 = nullptr;
      if ( v58 != nullptr )
      {
        v18 = D3DXShader::CInstruction::Initialize(this: v58, a2: 0x50000003u, a3: 6u, a4: 1u, a5: 0);
        if ( v18 < 0 )
          goto LABEL_65;
        v18 = D3DXShader::CInstruction::Instance(this: v58, a2: v4);
        if ( v18 < 0 )
          goto LABEL_65;
        v19 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v54 + *((_DWORD *)v4 + 2)));
        v50 = *(_DWORD *)(v19 + 16);
        v20 = 0;
        for ( k = 0; ; v20 = k )
        {
          v21 = v20 == v50 ? *((_DWORD *)this + 273) : *((_DWORD *)this + 272);
          v22 = *(double *)(v19 + 32);
          v38 = *(_DWORD *)(v19 + 4);
          v43[v20] = v21;
          v23 = D3DXShader::CBaseProgram::AddArgument(this, a2: v38, a3: 0, a4: v20, a5: v22);
          v42[k] = v23;
          if ( v23 == -1 )
            break;
          v53 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v23);
          D3DXShader::CArgument::Initialize(this: v53, a2: (struct D3DXShader::CArgument *)v19);
          v24 = *(_DWORD *)(v54 + *((_DWORD *)v4 + 2));
          v25 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v24) + 56);
          if ( v25 == -1 )
            *((_DWORD *)v53 + 14) = v24;
          else
            *((_DWORD *)v53 + 14) = v25;
          if ( ++k >= 3 )
          {
            v26 = v58;
            v27 = *((_DWORD **)v58 + 2);
            v28 = v55;
            *v27++ = v43[0];
            *v27 = v43[1];
            v27[1] = v43[2];
            v29 = (_DWORD *)(*((_DWORD *)v26 + 2) + 12);
            *v29++ = v42[0];
            *v29 = v42[1];
            v29[1] = v42[2];
            **((_DWORD **)v26 + 4) = v44[0];
            if ( v28 != 0 )
            {
              v30 = v54;
              do
              {
                *(_DWORD *)(v30 + *((_DWORD *)v49 + 2)) = v44[0];
                v30 += 4;
                --v28;
              }
              while ( v28 != 0 );
            }
            v31 = *((_DWORD *)this + 137);
            if ( v31 < 0x200 )
            {
              v32 = v58;
              *(_DWORD *)(*((_DWORD *)this + 140) + 4 * v31) = v58;
              ++*((_DWORD *)this + 137);
              if ( (D3DXShader::CBaseProgram::AddInstruction(this, a2: v32) & 0x80000000) == 0 )
              {
                v58 = nullptr;
                v4 = v49;
                goto LABEL_53;
              }
            }
            goto LABEL_70;
          }
        }
      }
      break;
    }
  }
LABEL_70:
  v18 = -2147024882;
LABEL_65:
  if ( v58 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v58, a2: 1);
LABEL_67:
  if ( v57 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v57, a2: 1);
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x10202FD1
// Name: protected: long D3DXShader::CPSLegacyProgram::FixPortConstraintsAndFixCMP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::FixPortConstraintsAndFixCMP(D3DXShader::CPSLegacyProgram *this)
{
  int v2; // edx
  int v3; // ecx
  int v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ecx
  struct D3DXShader::CInstruction *v7; // ebx
  int v8; // eax
  unsigned int v9; // edi
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // edx
  unsigned __int8 *v13; // eax
  int v14; // edi
  int v15; // eax
  unsigned int v16; // edx
  int *v17; // eax
  int v18; // ecx
  _DWORD *v19; // eax
  unsigned __int8 *v20; // eax
  int v21; // edi
  D3DXShader::CInstruction *v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  D3DXShader::CInstruction *v26; // ecx
  int *v27; // ecx
  bool v28; // cf
  unsigned int v29; // eax
  int v30; // eax
  unsigned __int8 *v31; // eax
  int v32; // eax
  unsigned int v33; // eax
  unsigned __int8 *v34; // eax
  D3DXShader::CInstruction *v35; // edi
  unsigned int i; // eax
  unsigned int v38; // [esp+1Ch] [ebp-20h]
  int v39; // [esp+20h] [ebp-1Ch]
  int v40; // [esp+24h] [ebp-18h]
  unsigned int v41; // [esp+28h] [ebp-14h]
  D3DXShader::CInstruction *v42; // [esp+2Ch] [ebp-10h]
  D3DXShader::CInstruction *v43; // [esp+2Ch] [ebp-10h]
  D3DXShader::CInstruction *v44; // [esp+2Ch] [ebp-10h]
  unsigned int v45; // [esp+30h] [ebp-Ch]
  unsigned int v46; // [esp+34h] [ebp-8h]
  int v47; // [esp+38h] [ebp-4h]
  int v48; // [esp+38h] [ebp-4h]
  int v49; // [esp+38h] [ebp-4h]

  v46 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    v2 = *((_DWORD *)this + 34);
    v3 = *((_DWORD *)this + 5);
    v4 = *((_DWORD *)this + 2);
    do
    {
      if ( v2 == *(_DWORD *)(*(_DWORD *)v3 + 4) )
      {
        v5 = *(_DWORD *)(*(_DWORD *)v3 + 12);
        if ( v5 >= v46 )
          v46 = v5 + 1;
      }
      v3 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
  v6 = *((_DWORD *)this + 137);
  v38 = v6;
  v41 = *((_DWORD *)this + 19);
  if ( v41 >= v6 )
  {
LABEL_68:
    for ( i = *((_DWORD *)this + 19); i < v6; ++i )
      **(_DWORD **)(*((_DWORD *)this + 140) + 4 * i) = 0;
    return 0;
  }
  while ( 1 )
  {
    v7 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 140) + 4 * v41);
    if ( v7 == nullptr )
      goto LABEL_67;
    v8 = *(_DWORD *)v7;
    if ( *(_DWORD *)v7 == 0 )
      goto LABEL_67;
    v9 = v8 & 0xFFFFF;
    v45 = v8 & 0xFFFFF;
    if ( (v8 & 0xFFF00000) == 0x70100000 )
    {
      v10 = *((_DWORD **)v7 + 2);
      v11 = *((_DWORD *)this + 5);
      v12 = *((_DWORD *)this + 4);
      if ( (*(_BYTE *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 4 * *v10) + 4)) + 5) & 2) != 0
        && (*(_BYTE *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 4 * v10[v45]) + 4)) + 5) & 2) != 0 )
      {
        v9 = v45;
        if ( (*(_BYTE *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 4 * v10[2 * v45]) + 4)) + 5) & 2) != 0 )
        {
          v13 = D3DXShader::CInstruction::operator new(a1: 0x74u);
          if ( v13 != nullptr )
            v42 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v13);
          else
            v42 = nullptr;
          if ( v42 == nullptr )
            return -2147024882;
          v47 = D3DXShader::CInstruction::Initialize(this: v42, a2: v45 & 0xFFFFF | 0x10000000, a3: v45, a4: v45, a5: 0);
          if ( v47 < 0 )
            return v47;
          v47 = D3DXShader::CInstruction::Instance(this: v42, a2: v7);
          if ( v47 < 0 )
            return v47;
          v48 = 0;
          if ( v45 != 0 )
          {
            while ( 1 )
            {
              v14 = 4 * v48;
              v15 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(4 * v48 + *((_DWORD *)v7 + 4)));
              *(_DWORD *)(4 * v48 + *((_DWORD *)v42 + 2)) = *(_DWORD *)(4 * v48 + *((_DWORD *)v7 + 2));
              *(_DWORD *)(v14 + *((_DWORD *)v42 + 4)) = D3DXShader::CBaseProgram::AddArgument(
                                                          this,
                                                          a2: *((_DWORD *)this + 34),
                                                          a3: v46,
                                                          a4: *(_DWORD *)(v15 + 16),
                                                          a5: 0.0);
              *(_DWORD *)(v14 + *((_DWORD *)v7 + 2)) = *(_DWORD *)(v14 + *((_DWORD *)v42 + 4));
              if ( *(_DWORD *)(4 * v48 + *((_DWORD *)v42 + 4)) == -1 )
                return -2147024882;
              if ( ++v48 >= v45 )
              {
                v9 = v45;
                break;
              }
            }
          }
          ++v46;
          if ( *((_DWORD *)this + 137) >= 0x200u )
            return -2147024882;
          v47 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v42);
          if ( v47 < 0 )
            return v47;
          *(_DWORD *)(*((_DWORD *)this + 140) + 4 * (*((_DWORD *)this + 137))++) = v42;
        }
      }
      else
      {
        v9 = v45;
      }
    }
    if ( (*(_DWORD *)v7 & 0xFFF00000) == 0x30000000 && (unsigned __int16)*((_DWORD *)this + 50) != 260 )
      break;
LABEL_59:
    v34 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v34 != nullptr )
      v35 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v34);
    else
      v35 = nullptr;
    if ( v35 == nullptr )
      return -2147024882;
    v47 = D3DXShader::CInstruction::Initialize(this: v35, a2: v7);
    if ( v47 < 0 )
      return v47;
    if ( *((_DWORD *)this + 137) >= 0x200u )
      return -2147024882;
    v47 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v35);
    if ( v47 < 0 )
      return v47;
    *(_DWORD *)(*((_DWORD *)this + 140) + 4 * (*((_DWORD *)this + 137))++) = v35;
    v6 = v38;
LABEL_67:
    if ( ++v41 >= v6 )
      goto LABEL_68;
  }
  v16 = 1;
  if ( v9 <= 1 )
  {
LABEL_34:
    v20 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v20 != nullptr )
      v21 = D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v20);
    else
      v21 = 0;
    if ( v21 == 0 )
      return -2147024882;
    v47 = D3DXShader::CBaseProgram::AddInstruction(this, a2: (struct D3DXShader::CInstruction *)v21);
    v22 = (D3DXShader::CInstruction *)v21;
    if ( v47 < 0 )
      goto LABEL_71;
    v47 = D3DXShader::CInstruction::Initialize(
            this: (D3DXShader::CInstruction *)v21,
            a2: 0x70300001u,
            a3: 3u,
            a4: 1u,
            a5: 0);
    if ( v47 < 0 )
      return v47;
    v47 = D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)v21, a2: v7);
    if ( v47 < 0 )
      return v47;
    **(_DWORD **)(v21 + 8) = **((_DWORD **)v7 + 2);
    *(_DWORD *)(*(_DWORD *)(v21 + 8) + 4) = D3DXShader::CBaseProgram::AddArgument(
                                              this,
                                              a2: *((_DWORD *)this + 30),
                                              a3: 0,
                                              a4: 0,
                                              a5: -1.0);
    *(_DWORD *)(*(_DWORD *)(v21 + 8) + 8) = D3DXShader::CBaseProgram::AddArgument(
                                              this,
                                              a2: *((_DWORD *)this + 30),
                                              a3: 0,
                                              a4: 0,
                                              a5: 0.5);
    v23 = *(_DWORD *)(v21 + 8);
    if ( *(_DWORD *)(v23 + 4) == -1 )
      return -2147024882;
    if ( *(_DWORD *)(v23 + 8) == -1 )
      return -2147024882;
    **(_DWORD **)(v21 + 16) = D3DXShader::CBaseProgram::AddArgument(
                                this,
                                a2: *((_DWORD *)this + 34),
                                a3: v46,
                                a4: 3u,
                                a5: 0.0);
    if ( **(_DWORD **)(v21 + 16) == -1 )
      return -2147024882;
    v24 = 0;
    v49 = 0;
    if ( v45 != 0 )
    {
      v40 = 8 * v45;
      v43 = (D3DXShader::CInstruction *)(4 * v45);
      do
      {
        *(_DWORD *)(*((_DWORD *)v7 + 2) + 4 * v24) = **(_DWORD **)(v21 + 16);
        v25 = *((_DWORD *)v7 + 2);
        v26 = v43;
        v43 = (D3DXShader::CInstruction *)((char *)v43 + 4);
        v27 = (int *)((char *)v26 + v25);
        v39 = *v27;
        *v27 = *(_DWORD *)(v25 + v40);
        *(_DWORD *)(v40 + *((_DWORD *)v7 + 2)) = v39;
        v24 = v49 + 1;
        v28 = ++v49 < v45;
        v40 += 4;
      }
      while ( v28 );
    }
    v29 = *((_DWORD *)this + 137);
    ++v46;
    if ( v29 >= 0x200 )
      return -2147024882;
    *(_DWORD *)(*((_DWORD *)this + 140) + 4 * v29) = v21;
    v30 = *(_DWORD *)this;
    ++*((_DWORD *)this + 137);
    if ( (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, int, _DWORD))(v30 + 32))(a1: this, a2: v21, a3: 0) != 0 )
    {
      v31 = D3DXShader::CInstruction::operator new(a1: 0x74u);
      if ( v31 != nullptr )
      {
        v44 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v31);
        v32 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v44);
      }
      else
      {
        v44 = nullptr;
        v32 = D3DXShader::CBaseProgram::AddInstruction(this, a2: nullptr);
      }
      v22 = v44;
      v47 = v32;
      if ( v32 < 0 )
      {
        if ( v44 == nullptr )
          return v47;
LABEL_71:
        D3DXShader::CInstruction::`scalar deleting destructor'(this: v22, a2: 1);
        return v47;
      }
      if ( v44 == nullptr )
        return -2147024882;
      v47 = D3DXShader::CInstruction::Initialize(this: v44, a2: 0x20400001u, a3: 2u, a4: 1u, a5: 0);
      if ( v47 < 0 )
        return v47;
      v47 = D3DXShader::CInstruction::Instance(this: v44, a2: v7);
      if ( v47 < 0 )
        return v47;
      **((_DWORD **)v44 + 4) = **(_DWORD **)(v21 + 16);
      **((_DWORD **)v44 + 2) = *(_DWORD *)(*(_DWORD *)(v21 + 8) + 8);
      **(_DWORD **)(v21 + 16) = D3DXShader::CBaseProgram::AddArgument(
                                  this,
                                  a2: *((_DWORD *)this + 34),
                                  a3: 0,
                                  a4: 3u,
                                  a5: 0.0);
      *(_DWORD *)(*((_DWORD *)v44 + 2) + 4) = **(_DWORD **)(v21 + 16);
      *(_DWORD *)(v21 + 4) = 2;
      *(_DWORD *)v21 = 542113793;
      v33 = *((_DWORD *)this + 137);
      if ( v33 >= 0x200 )
        return -2147024882;
      *(_DWORD *)(*((_DWORD *)this + 140) + 4 * v33) = v44;
      ++*((_DWORD *)this + 137);
    }
    *((_DWORD *)this + 275) = 1;
    *(_DWORD *)v7 = v45 & 0xFFFFF | 0x70F00000;
    goto LABEL_59;
  }
  v17 = *((int **)v7 + 2);
  v18 = *v17;
  v19 = v17 + 1;
  while ( v18 == *v19 )
  {
    ++v16;
    ++v19;
    if ( v16 >= v9 )
      goto LABEL_34;
  }
  D3DXShader::CProgram::Error(
    this,
    a2: *((struct D3DXShader::CNode **)v7 + 15),
    a3: 0x11CAu,
    format: "unable to emulate vector conditionals in ps_1_%i shader model",
    (unsigned __int8)*((_DWORD *)this + 50));
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10203549
// Name: protected: long D3DXShader::CPSLegacyProgram::DeSwizzle(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::DeSwizzle(struct D3DXShader::CInstruction **this)
{
  D3DXShader::CPSLegacyProgram *v1; // ebx
  struct D3DXShader::CInstruction *v2; // esi
  int v3; // ecx
  unsigned int v4; // edi
  unsigned int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  _DWORD *v9; // esi
  D3DXShader *v10; // edi
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // esi
  unsigned int v15; // eax
  unsigned int v16; // esi
  bool v17; // zf
  unsigned int *v18; // edi
  char *v19; // ecx
  unsigned int v20; // edx
  unsigned int *v21; // esi
  int IsValidSwizzle; // edi
  int v23; // eax
  int result; // eax
  unsigned int i; // eax
  unsigned int k; // esi
  int v27; // edx
  unsigned int v28; // edi
  unsigned int v29; // edi
  int v30; // esi
  int v31; // ecx
  unsigned int v32; // [esp-8h] [ebp-BCh]
  unsigned int v33; // [esp-4h] [ebp-B8h]
  unsigned int v34; // [esp+0h] [ebp-B4h]
  unsigned int v35; // [esp+0h] [ebp-B4h]
  unsigned int v36[12]; // [esp+Ch] [ebp-A8h] BYREF
  unsigned int v37; // [esp+3Ch] [ebp-78h] BYREF
  unsigned int v38; // [esp+40h] [ebp-74h]
  unsigned int v39; // [esp+44h] [ebp-70h]
  unsigned int v40; // [esp+48h] [ebp-6Ch]
  unsigned int v41[4]; // [esp+4Ch] [ebp-68h] BYREF
  unsigned int v42[4]; // [esp+5Ch] [ebp-58h] BYREF
  unsigned int v43[4]; // [esp+6Ch] [ebp-48h] BYREF
  unsigned int v44[4]; // [esp+7Ch] [ebp-38h] BYREF
  int v45; // [esp+8Ch] [ebp-28h]
  int v46; // [esp+90h] [ebp-24h]
  unsigned int v47; // [esp+94h] [ebp-20h]
  int v48; // [esp+98h] [ebp-1Ch]
  unsigned int v49; // [esp+9Ch] [ebp-18h]
  D3DXShader *v50; // [esp+A0h] [ebp-14h]
  unsigned int v51; // [esp+A4h] [ebp-10h]
  unsigned int j; // [esp+A8h] [ebp-Ch]
  unsigned int v53; // [esp+ACh] [ebp-8h]
  D3DXShader *v54; // [esp+B0h] [ebp-4h]

  v1 = (D3DXShader::CPSLegacyProgram *)this;
  v2 = *(this + 64);
  v3 = *(_DWORD *)v2;
  v4 = *(_DWORD *)v2 & 0xFFFFF;
  v48 = (int)v1;
  v49 = v4;
  if ( v2 == nullptr || v3 == 0 )
    return 0;
  v5 = *((_DWORD *)v2 + 1) / v4;
  v50 = nullptr;
  v53 = v5;
  if ( (v3 & 0xFFF00000) == 0x50000000 || *((_DWORD *)v2 + 3) != v4 )
  {
    result = D3DXShader::CBaseProgram::CopyInstruction(this: v1, a2: v2);
    if ( result < 0 )
      return result;
    **((_DWORD **)v1 + 64) = 0;
    return 0;
  }
  v6 = *((_DWORD *)v1 + 50);
  v45 = 0;
  if ( (unsigned __int16)v6 != 260 && D3DXShader::CPSLegacyProgram::HasWriteMask(this: v1, a2: v2) != 0 )
  {
    v7 = *((_DWORD *)v2 + 3);
    if ( v7 != 0 )
    {
      v8 = *((_DWORD *)v1 + 5);
      v9 = *((_DWORD **)v2 + 4);
      do
      {
        if ( *(_DWORD *)(*(_DWORD *)(v8 + 4 * *v9) + 16) == 3 )
        {
          v50 = (D3DXShader *)1;
          v45 = 1;
        }
        ++v9;
        --v7;
      }
      while ( v7 != 0 );
    }
  }
  v51 = 0;
  if ( v53 != 0 )
  {
    v47 = 0;
    v54 = (D3DXShader *)v36;
    do
    {
      v10 = v54;
      *(_DWORD *)v54 = -1;
      v10 = (D3DXShader *)((char *)v10 + 4);
      j = 0;
      *(_DWORD *)v10 = -1;
      v10 = (D3DXShader *)((char *)v10 + 4);
      *(_DWORD *)v10 = -1;
      *((_DWORD *)v10 + 1) = -1;
      v37 = -1;
      v38 = -1;
      v39 = -1;
      v40 = -1;
      if ( v49 != 0 )
      {
        v11 = *((_DWORD *)v1 + 64);
        v12 = *((_DWORD *)v1 + 5);
        v13 = *((_DWORD *)v1 + 4);
        v46 = v47;
        do
        {
          v14 = *(_DWORD *)(v12 + 4 * *(_DWORD *)(v46 + *(_DWORD *)(v11 + 8)));
          v15 = *(_DWORD *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 16) + 4 * j)) + 16);
          if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v14 + 4)) + 5) & 1) != 0 )
            v36[4 * v51 + v15] = v15;
          else
            v36[4 * v51 + v15] = *(_DWORD *)(v14 + 16);
          *(&v37 + v15) = 0;
          ++j;
          v46 += 4;
        }
        while ( j < v49 );
        v1 = (D3DXShader::CPSLegacyProgram *)v48;
      }
      if ( D3DXShader::IsValidSwizzle(this: v54, a2: &v37, a3: (unsigned int *)5, a4: v34) == 0 )
        v50 = (D3DXShader *)1;
      ++v51;
      v54 = (D3DXShader *)((char *)v54 + 16);
      v47 += 4 * v49;
    }
    while ( v51 < v53 );
  }
  v16 = 0;
  if ( v50 == nullptr )
  {
    result = D3DXShader::CBaseProgram::CopyInstruction(this: v1, a2: *((struct D3DXShader::CInstruction **)v1 + 64));
    goto LABEL_105;
  }
  v51 = 0;
  v48 = 0;
  if ( v49 != 4 )
  {
    if ( v49 == 3 )
    {
      v48 = -1;
      for ( i = 0; i < 4; ++i )
      {
        if ( v36[i] == -1 )
          v48 = i;
      }
      for ( j = 0; j < 4; ++j )
      {
        if ( v51 != 0 )
          goto LABEL_96;
        for ( k = 0; k < 4; ++k )
        {
          if ( v51 != 0 )
            break;
          if ( k != j )
          {
            v27 = v48;
            if ( k != v48 && j != v48 )
            {
              v37 = -1;
              v38 = -1;
              v39 = -1;
              v40 = -1;
              memset(v41, 0, sizeof(v41));
              v28 = j;
              *(unsigned int *)((char *)&v37 + v28 * 4) = 0;
              *(&v37 + k) = 0;
              v41[v28] = -1;
              v41[k] = -1;
              v41[v27] = -1;
              v29 = 0;
              v54 = nullptr;
              if ( v53 != 0 )
              {
                v50 = (D3DXShader *)v36;
                do
                {
                  if ( v54 != nullptr )
                    break;
                  v54 = (D3DXShader *)(D3DXShader::IsValidSwizzle(this: v50, a2: &v37, a3: (unsigned int *)5, a4: v34) == 0);
                  v50 = (D3DXShader *)((char *)v50 + 16);
                  ++v29;
                }
                while ( v29 < v53 );
              }
              if ( v40 == 0 && (v37 == 0 || v38 == 0 || v39 == 0) && v45 != 0 )
                v54 = (D3DXShader *)1;
              if ( v54 == nullptr )
                v51 = 1;
            }
          }
        }
      }
      if ( v51 != 0 )
      {
LABEL_96:
        result = D3DXShader::CShaderProgram::BuildInstruction(this: v1, a2: &v37, a3: v53, a4: 3u);
        if ( result < 0 )
          return result;
        result = D3DXShader::CShaderProgram::BuildInstruction(this: v1, a2: v41, a3: v53, a4: 3u);
        goto LABEL_98;
      }
    }
LABEL_100:
    v30 = 0;
    if ( v49 != 0 )
    {
      do
      {
        v31 = *((_DWORD *)v1 + 5);
        v33 = v49;
        v32 = v53;
        v37 = -1;
        v38 = -1;
        v39 = -1;
        v40 = -1;
        *(&v37 + *(_DWORD *)(*(_DWORD *)(v31 + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v1 + 64) + 16) + 4 * v30)) + 16)) = 0;
        result = D3DXShader::CShaderProgram::BuildInstruction(this: v1, a2: &v37, a3: v32, a4: v33);
        if ( result < 0 )
          return result;
      }
      while ( ++v30 < v49 );
    }
LABEL_106:
    **((_DWORD **)v1 + 64) = 0;
    return 0;
  }
  v54 = (D3DXShader *)1;
  do
  {
    v37 = 0;
    v38 = 0;
    v39 = 0;
    v40 = 0;
    memset(v41, 255, sizeof(v41));
    *(&v37 + v16) = -1;
    v17 = v53 == 0;
    v41[v16] = 0;
    v54 = nullptr;
    if ( !v17 )
    {
      v18 = v36;
      v50 = (D3DXShader *)v53;
      do
      {
        if ( D3DXShader::IsValidSwizzle(this: (D3DXShader *)v18, a2: &v37, a3: (unsigned int *)5, a4: v34) == 0
          || D3DXShader::IsValidSwizzle(this: (D3DXShader *)v18, a2: &v37, a3: (unsigned int *)5, a4: v34) == 0 )
        {
          v54 = (D3DXShader *)1;
        }
        v18 += 4;
        v50 = (D3DXShader *)((char *)v50 - 1);
      }
      while ( v50 != nullptr );
    }
    if ( v45 != 0 && v16 != 3 )
      v54 = (D3DXShader *)1;
    if ( v54 == nullptr )
    {
      result = D3DXShader::CShaderProgram::BuildInstruction(this: v1, a2: &v37, a3: v53, a4: 4u);
      if ( result < 0 )
        return result;
      result = D3DXShader::CShaderProgram::BuildInstruction(this: v1, a2: v41, a3: v53, a4: 4u);
LABEL_105:
      if ( result < 0 )
        return result;
      goto LABEL_106;
    }
    ++v16;
  }
  while ( v16 < 4 );
  v54 = (D3DXShader *)1;
  for ( j = 0; j < 4; ++j )
  {
    if ( v54 == nullptr )
      break;
    v19 = nullptr;
    v50 = nullptr;
    while ( 1 )
    {
      v20 = j;
      if ( v19 != (char *)j )
        break;
LABEL_58:
      v19 = (char *)v50 + 1;
      v50 = (D3DXShader *)((char *)v50 + 1);
      if ( (unsigned int)v50 >= 4 )
        goto LABEL_61;
    }
    v37 = 0;
    v38 = 0;
    v39 = 0;
    v40 = 0;
    memset(v41, 255, sizeof(v41));
    *(&v37 + j) = -1;
    *(&v37 + (_DWORD)v19) = -1;
    v17 = v53 == 0;
    v41[v20] = 0;
    v41[(_DWORD)v19] = 0;
    v54 = nullptr;
    v46 = 0;
    if ( !v17 )
    {
      v21 = v36;
      v47 = v53;
      while ( 1 )
      {
        IsValidSwizzle = D3DXShader::IsValidSwizzle(this: (D3DXShader *)v21, a2: &v37, a3: (unsigned int *)5, a4: v34);
        v23 = D3DXShader::IsValidSwizzle(this: (D3DXShader *)v21, a2: v41, a3: (unsigned int *)5, a4: v35);
        if ( IsValidSwizzle == 0 )
          break;
        if ( v23 == 0 )
          goto LABEL_49;
LABEL_50:
        v21 += 4;
        if ( --v47 == 0 )
          goto LABEL_51;
      }
      v46 = 1;
LABEL_49:
      v54 = (D3DXShader *)1;
      goto LABEL_50;
    }
LABEL_51:
    if ( v45 != 0 )
      v54 = (D3DXShader *)1;
    if ( v54 != nullptr )
    {
      if ( v46 == 0 && (v45 == 0 || v40 != 0) )
      {
        v42[0] = v37;
        v42[1] = v38;
        v42[2] = v39;
        v42[3] = v40;
        memset(v43, 255, sizeof(v43));
        memset(v44, 255, sizeof(v44));
        v43[j] = 0;
        v44[(_DWORD)v50] = 0;
        v48 = 1;
      }
      goto LABEL_58;
    }
    v51 = 1;
LABEL_61:
    ;
  }
  if ( v51 == 0 )
  {
    if ( v48 != 0 )
    {
      v51 = 1;
      result = D3DXShader::CShaderProgram::BuildInstruction(this: v1, a2: v42, a3: v53, a4: 4u);
      if ( result < 0 )
        return result;
      result = D3DXShader::CShaderProgram::BuildInstruction(this: v1, a2: v43, a3: v53, a4: 4u);
      if ( result < 0 )
        return result;
      result = D3DXShader::CShaderProgram::BuildInstruction(this: v1, a2: v44, a3: v53, a4: 4u);
LABEL_98:
      if ( result < 0 )
        return result;
      if ( v51 != 0 )
        goto LABEL_106;
      goto LABEL_100;
    }
    goto LABEL_100;
  }
  result = D3DXShader::CShaderProgram::BuildInstruction(this: v1, a2: &v37, a3: v53, a4: 4u);
  if ( result >= 0 )
  {
    result = D3DXShader::CShaderProgram::BuildInstruction(this: v1, a2: v41, a3: v53, a4: 4u);
    goto LABEL_98;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203B04
// Name: protected: long D3DXShader::CPSLegacyProgram::MatchTexReflect(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::MatchTexReflect(D3DXShader::CPSLegacyProgram *this, int a2)
{
  unsigned int v3; // eax
  _DWORD *v5; // eax
  unsigned int v6; // esi
  int matched; // eax
  unsigned int i; // esi
  int v9; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // esi
  int v13; // eax
  _DWORD *v14; // edi
  unsigned int *v15; // ebx
  int v16; // esi
  unsigned int *v17; // edx
  unsigned int v18; // eax
  unsigned int v19; // edi
  bool v20; // zf
  _DWORD *v21; // edx
  int v22; // eax
  _DWORD *v23; // eax
  int v24; // eax
  int v25; // esi
  int v26; // edx
  int v27; // ebx
  unsigned int j; // eax
  struct D3DXShader::CInstruction *v29; // ecx
  unsigned __int8 *v30; // eax
  int v31; // ebx
  D3DXShader::CPSLegacyProgram *v32; // esi
  int v33; // eax
  int v34; // edi
  D3DXShader::CPSLegacyProgram *v35; // edx
  unsigned int v36; // eax
  _DWORD *v37; // esi
  D3DXShader::CInstruction *v38; // ecx
  unsigned int v39; // [esp-10h] [ebp-138h]
  struct D3DXShader::CInstruction *v40[16]; // [esp+4h] [ebp-124h] BYREF
  unsigned int v41[40]; // [esp+44h] [ebp-E4h] BYREF
  unsigned int v42; // [esp+E4h] [ebp-44h] BYREF
  _DWORD v43[3]; // [esp+E8h] [ebp-40h] BYREF
  _DWORD v44[6]; // [esp+F4h] [ebp-34h] BYREF
  int v45; // [esp+10Ch] [ebp-1Ch]
  unsigned int v46; // [esp+110h] [ebp-18h] BYREF
  BOOL v47; // [esp+114h] [ebp-14h]
  int v48; // [esp+118h] [ebp-10h]
  unsigned int v49; // [esp+11Ch] [ebp-Ch]
  _DWORD *v50; // [esp+120h] [ebp-8h]
  D3DXShader::CPSLegacyProgram *v51; // [esp+124h] [ebp-4h]

  v3 = (unsigned __int16)*((_DWORD *)this + 50);
  v51 = this;
  if ( v3 >= 0x104 )
    return 1;
  v5 = *((_DWORD **)this + 64);
  v6 = 0;
  v46 = 0;
  v42 = 0;
  v43[0] = 1;
  v43[1] = 2;
  v43[2] = 3;
  if ( (*v5 & 0xFFFFF) == 3 )
  {
    do
    {
      matched = D3DXShader::CShaderProgram::MatchComplexTree(
                  this,
                  a2: *((struct D3DXShader::CInstruction **)this + 64),
                  a3: *(&off_103366B0 + v6),
                  a4: v40,
                  a5: &v46,
                  a6: v41,
                  a7: &v42,
                  a8: 3u,
                  a9: 0);
      if ( matched == 0 )
        break;
      ++v6;
    }
    while ( v6 < 9 );
    v48 = 0;
    v47 = v6 > 4;
    if ( matched == 0 )
      goto LABEL_12;
    for ( i = 0; i < 3; ++i )
    {
      v9 = D3DXShader::CShaderProgram::MatchComplexTree(
             this,
             a2: *((struct D3DXShader::CInstruction **)this + 64),
             a3: *(&off_103366D4 + i),
             a4: v40,
             a5: &v46,
             a6: v41,
             a7: &v42,
             a8: 3u,
             a9: 0);
      if ( v9 == 0 )
        break;
    }
    v47 = i > 1;
    v48 = 1;
    if ( v9 == 0 )
    {
LABEL_12:
      v49 = 0;
      v10 = *((_DWORD *)this + 5);
      v45 = 12 - (_DWORD)v44;
      do
      {
        v11 = v49;
        v12 = v41[v49 + 4];
        v13 = *(_DWORD *)(v10 + 4 * v12);
        if ( *(_DWORD *)(v13 + 16) != v49 )
          return 1;
        if ( a2 != 0 )
        {
          if ( *(_DWORD *)(v13 + 72) != -1
            || *(_DWORD *)(v13 + 4) != *((_DWORD *)v51 + 32)
            || *(unsigned __int8 *)(v13 + 109) != v49 + 1
            || *(_BYTE *)(v13 + 108) != 5 )
          {
            return 1;
          }
          v20 = !v47;
          v44[v49] = v12;
          if ( v20 )
          {
            if ( *(_DWORD *)(v13 + 60) != 0x80000 )
              return 1;
            v14 = *(_DWORD **)(v13 + 56);
            v15 = &v41[v11 + 12];
            v20 = v41[v11 + 12] == (_DWORD)v14;
            v50 = v14;
            if ( v20 )
            {
              v16 = *(v15 - 4);
              if ( v41[v11 + 16] == v16 )
              {
                v17 = &v41[v11 + 20];
                v18 = v41[v11 + 20];
                if ( v18 == v15[12] && v41[v11 + 16] == v18 )
                  goto LABEL_51;
              }
            }
LABEL_46:
            v20 = v41[v11 + 16] == (_DWORD)v14;
          }
          else
          {
            if ( *(_DWORD *)(v13 + 60) != 0 )
              return 1;
            v15 = &v41[v11 + 12];
            if ( v41[v11 + 12] == v12 )
            {
              v19 = v41[v11 + 16];
              v16 = *(v15 - 4);
              if ( v19 == v16 )
              {
                v17 = &v41[v11 + 20];
                v18 = v41[v11 + 20];
                if ( v18 == v15[12] && v19 == v18 )
                  goto LABEL_51;
              }
            }
            v20 = v41[v11 + 16] == v41[v11 + 4];
          }
          if ( !v20 )
            return 1;
          v16 = *(v15 - 4);
          if ( *v15 != v16 )
            return 1;
          v17 = &v41[v11 + 20];
          v18 = v41[v11 + 20];
          if ( v18 != v15[12] || *v15 != v18 )
            return 1;
          goto LABEL_51;
        }
        if ( v47 )
        {
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v51 + 4) + 4 * *(_DWORD *)(v13 + 4)) + 5) & 2) == 0 )
            return 1;
          v21 = &v44[v11];
          v44[v49] = v12;
        }
        else
        {
          v22 = *(_DWORD *)(v13 + 72);
          if ( v22 == -1 )
            return 1;
          v23 = *(_DWORD **)(*((_DWORD *)v51 + 6) + 4 * v22);
          if ( *v23 != 542113795 )
            return 1;
          v24 = v23[2];
          v25 = *((_DWORD *)v51 + 4);
          v50 = *(_DWORD **)(v11 * 4 + v24);
          v26 = *(_DWORD *)(v10 + 4 * (_DWORD)v50);
          if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v26 + 4)) + 5) & 2) == 0 )
            return 1;
          if ( *(_DWORD *)(v26 + 16) != v49 )
            return 1;
          v21 = &v44[v11];
          v27 = *(_DWORD *)(v10 + 4 * *(_DWORD *)((char *)&v44[v11] + v24 + v45));
          if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v27 + 4)) + 5) & 1) == 0 || *(double *)(v27 + 32) != -1.0 )
            return 1;
          *v21 = v50;
        }
        v14 = (_DWORD *)*v21;
        v15 = &v41[v11 + 12];
        v20 = v41[v11 + 12] == *v21;
        v50 = (_DWORD *)*v21;
        if ( !v20 )
          goto LABEL_46;
        v16 = *(v15 - 4);
        if ( v41[v11 + 16] != v16 )
          goto LABEL_46;
        v17 = &v41[v11 + 20];
        v18 = v41[v11 + 20];
        if ( v18 != v15[12] || v41[v11 + 16] != v18 )
          goto LABEL_46;
LABEL_51:
        v20 = v48 == 0;
        v44[v11 + 3] = v16;
        if ( !v20 && v18 != v17[8] )
          return 1;
        v10 = *((_DWORD *)v51 + 5);
        if ( *(_DWORD *)(*(_DWORD *)(v10 + 4 * v16) + 16) != v49 )
          return 1;
        ++v49;
      }
      while ( v49 < 3 );
      for ( j = 0; j < v46; *(_DWORD *)v29 = 0 )
        v29 = v40[j++];
      v30 = D3DXShader::CInstruction::operator new(a1: 0x74u);
      if ( v30 != nullptr )
        v31 = D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v30);
      else
        v31 = 0;
      if ( v31 == 0 )
        return -2147024882;
      v32 = v51;
      v39 = *(_DWORD *)(*((_DWORD *)v51 + 64) + 12);
      if ( a2 != 0 )
        v33 = D3DXShader::CInstruction::Initialize(
                this: (D3DXShader::CInstruction *)v31,
                a2: 0x72C00003u,
                a3: 6u,
                a4: v39,
                a5: 0);
      else
        v33 = D3DXShader::CInstruction::Initialize(
                this: (D3DXShader::CInstruction *)v31,
                a2: 0x72D00003u,
                a3: 9u,
                a4: v39,
                a5: 0);
      v34 = v33;
      if ( v33 >= 0 )
      {
        v48 = D3DXShader::CInstruction::Instance(
                this: (D3DXShader::CInstruction *)v31,
                a2: *((struct D3DXShader::CInstruction **)v32 + 64));
        if ( v48 >= 0 )
        {
          v35 = v51;
          qmemcpy(
            *(void **)(v31 + 16),
            *(const void **)(*((_DWORD *)v51 + 64) + 16),
            4 * *(_DWORD *)(*((_DWORD *)v51 + 64) + 12));
          v36 = 3;
          v50 = v43;
          do
          {
            *(_DWORD *)(v36 * 4 + *(_DWORD *)(v31 + 8) - 12) = **(_DWORD **)(*((_DWORD *)v35 + 64) + 8);
            *(_DWORD *)(v36 * 4 + *(_DWORD *)(v31 + 8)) = v44[v36];
            if ( a2 == 0 )
              *(_DWORD *)(v36 * 4 + *(_DWORD *)(v31 + 8) + 12) = v50[v36];
            ++v36;
          }
          while ( v36 < 6 );
          v37 = (_DWORD *)((char *)v35 + 252);
          v38 = *(D3DXShader::CInstruction **)(*((_DWORD *)v35 + 6) + 4 * *((_DWORD *)v35 + 63));
          if ( v38 != nullptr )
          {
            D3DXShader::CInstruction::`scalar deleting destructor'(this: v38, a2: 1);
            v35 = v51;
          }
          *(_DWORD *)(*((_DWORD *)v35 + 6) + 4 * *v37) = v31;
        }
        else
        {
          D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v31, a2: 1);
        }
        return v48;
      }
      else
      {
        D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v31, a2: 1);
        return v34;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10203F91
// Name: protected: long D3DXShader::CPSLegacyProgram::ValidateInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::ValidateInstructions(D3DXShader::CPSLegacyProgram *this)
{
  int v1; // esi
  bool v2; // zf
  int v3; // ebx
  unsigned int v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // edx
  int v8; // eax
  int v9; // eax
  _DWORD *v10; // edx
  int v11; // esi
  int v13; // [esp-4h] [ebp-1Ch]
  int v14; // [esp-4h] [ebp-1Ch]
  unsigned int v15; // [esp+0h] [ebp-18h]
  int *i; // [esp+Ch] [ebp-Ch]
  int *v17; // [esp+10h] [ebp-8h]
  unsigned int v18; // [esp+10h] [ebp-8h]
  unsigned int v19; // [esp+14h] [ebp-4h]
  int v20; // [esp+14h] [ebp-4h]

  v19 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    v17 = *((int **)this + 6);
    do
    {
      *((_DWORD *)this + 63) = v19;
      v1 = *v17;
      v2 = *v17 == 0;
      *((_DWORD *)this + 64) = *v17;
      if ( !v2 && *(_DWORD *)v1 != 0 )
      {
        v3 = *(_DWORD *)v1 & 0xFFFFF;
        v4 = *(_DWORD *)v1 & 0xFFF00000;
        if ( v4 > 0x60C00000 )
        {
          switch ( v4 )
          {
            case 0x60D00000u:
              v14 = 2;
LABEL_42:
              v5 = v14;
LABEL_43:
              v6 = 0;
LABEL_44:
              D3DXShader::CProgram::Error(
                this,
                a2: *(struct D3DXShader::CNode **)(v1 + 60),
                a3: 0x11B4u,
                format: "%s%s is not supported on ps_1_%i",
                off_10336780[v5],
                off_10336790[v6],
                (unsigned __int8)*((_DWORD *)this + 50));
              return -2147467259;
            case 0x61100000u:
              v13 = 3;
LABEL_39:
              v5 = v13;
LABEL_40:
              v6 = 1;
              goto LABEL_44;
            case 0x61200000u:
              v14 = 3;
              goto LABEL_42;
            default:
              break;
          }
        }
        else
        {
          switch ( v4 )
          {
            case 0x60C00000u:
              v13 = 2;
              goto LABEL_39;
            case 0x60200000u:
              v5 = 0;
              goto LABEL_40;
            case 0x60300000u:
              v5 = 0;
              goto LABEL_43;
            case 0x60700000u:
              if ( (unsigned __int16)*((_DWORD *)this + 50) != 260 )
              {
                v6 = 1;
                v5 = 1;
                goto LABEL_44;
              }
              break;
            case 0x60800000u:
              v5 = 1;
              goto LABEL_43;
            default:
              break;
          }
        }
        if ( D3DXShader::IsTextureInst(this: (D3DXShader *)(*(_DWORD *)v1 & 0xFFF00000), a2: v15) || v7 == 285212672 )
        {
          v8 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v1 + 8) + 4 * (v7 != 285212672 ? v3 : 0)));
          if ( *(_DWORD *)(v8 + 60) != 0
            && (unsigned __int16)*((_DWORD *)this + 50) != 260
            && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v8 + 4)) + 4) & 0x10) != 0 )
          {
            D3DXShader::CProgram::Error(
              this,
              a2: *(struct D3DXShader::CNode **)(v1 + 60),
              a3: 0x11B4u,
              format: "dependent texture read not supported on ps_1_%i",
              (unsigned __int8)*((_DWORD *)this + 50));
            return -2147467259;
          }
        }
      }
      ++v19;
      ++v17;
    }
    while ( v19 < *((_DWORD *)this + 3) );
  }
  v20 = 0;
  if ( *((_DWORD *)this + 3) == 0 )
    return 0;
  for ( i = *((int **)this + 6); ; ++i )
  {
    *((_DWORD *)this + 63) = v20;
    v9 = *i;
    v2 = *i == 0;
    *((_DWORD *)this + 64) = *i;
    if ( !v2 && *(_DWORD *)v9 != 0 )
    {
      v18 = 0;
      if ( *(_DWORD *)(v9 + 4) != 0 )
        break;
    }
LABEL_32:
    if ( (unsigned int)++v20 >= *((_DWORD *)this + 3) )
      return 0;
  }
  v10 = *(_DWORD **)(v9 + 8);
  while ( 1 )
  {
    v11 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v10);
    if ( *(_DWORD *)(v11 + 4) == *((_DWORD *)this + 32) && *(_BYTE *)(v11 + 108) == 5 )
      break;
    ++v18;
    ++v10;
    if ( v18 >= *(_DWORD *)(*((_DWORD *)this + 64) + 4) )
      goto LABEL_32;
  }
  D3DXShader::CProgram::Error(
    this,
    a2: *(struct D3DXShader::CNode **)(v9 + 60),
    a3: 0x11A0u,
    format: "cannot access w component from texcoord in general expression");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x102041E0
// Name: protected: long D3DXShader::CPSLegacyProgram::MatchComplexAdd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPSLegacyProgram::MatchComplexAdd(D3DXShader::CPSLegacyProgram *this)
{
  struct D3DXShader::CInstruction *v2; // eax
  D3DXShader::CInstruction *v3; // ebx
  unsigned int v4; // esi
  int matched; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  unsigned __int8 *v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  bool v13; // zf
  int v14; // edx
  _DWORD *v15; // ecx
  int v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  bool v22; // cf
  unsigned int i; // eax
  D3DXShader::CInstruction *v24; // ecx
  unsigned int v26[4]; // [esp+Ch] [ebp-108h] BYREF
  _DWORD v27[36]; // [esp+1Ch] [ebp-F8h] BYREF
  struct D3DXShader::CInstruction *v28[16]; // [esp+ACh] [ebp-68h] BYREF
  unsigned int v29[4]; // [esp+ECh] [ebp-28h] BYREF
  BOOL v30; // [esp+FCh] [ebp-18h]
  int v31; // [esp+100h] [ebp-14h]
  unsigned int v32; // [esp+104h] [ebp-10h] BYREF
  int v33; // [esp+108h] [ebp-Ch]
  unsigned int v34; // [esp+10Ch] [ebp-8h]
  int v35; // [esp+110h] [ebp-4h]

  v2 = *((struct D3DXShader::CInstruction **)this + 64);
  v3 = nullptr;
  v32 = 0;
  v29[0] = 0;
  v29[1] = 1;
  v29[2] = 2;
  v29[3] = 3;
  v4 = *(_DWORD *)v2 & 0xFFFFF;
  v34 = 0;
  if ( D3DXShader::CShaderProgram::MatchComplexTree(
         this,
         a2: v2,
         a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BAEF8,
         a4: v28,
         a5: &v32,
         a6: v26,
         a7: v29,
         a8: v4,
         a9: 0) != 0 )
  {
    matched = D3DXShader::CShaderProgram::MatchComplexTree(
                this,
                a2: *((struct D3DXShader::CInstruction **)this + 64),
                a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BAF58,
                a4: v28,
                a5: &v32,
                a6: v26,
                a7: v29,
                a8: v4,
                a9: 0);
    v34 = 1;
    if ( matched != 0 )
    {
LABEL_30:
      v35 = 0;
      goto LABEL_31;
    }
  }
  v30 = false;
  if ( v34 != 0 )
  {
    v6 = *((_DWORD *)this + 5);
    v7 = *((_DWORD *)this + 4);
    v8 = *(_DWORD *)(v7 + 4 * *(_DWORD *)(*(_DWORD *)(v6 + 4 * v26[0]) + 4));
    v9 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(*(_DWORD *)(v6 + 4 * v27[0]) + 4)) + 4);
    v30 = (v9 & 0x200) != 0;
    if ( (*(_DWORD *)(v8 + 4) & 0x300) != 0 && (v9 & 0x300) != 0 )
      return 1;
  }
  v10 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v10 != nullptr )
    v3 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v10);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return -2147024882;
  if ( v34 != 0 )
    v11 = v4 | 0x70400000;
  else
    v11 = v4 | 0x70300000;
  v35 = D3DXShader::CInstruction::Initialize(this: v3, a2: v11, a3: 3 * v4, a4: v4, a5: 0);
  if ( v35 >= 0 )
  {
    v35 = D3DXShader::CInstruction::Instance(this: v3, a2: *((struct D3DXShader::CInstruction **)this + 64));
    if ( v35 >= 0 )
    {
      v34 = 0;
      if ( v4 != 0 )
      {
        v31 = 8 * v4;
        v33 = 4 * v4;
        do
        {
          v12 = 4 * v34;
          v13 = !v30;
          *(_DWORD *)(v12 + *((_DWORD *)v3 + 4)) = *(_DWORD *)(4 * v34 + *(_DWORD *)(*((_DWORD *)this + 64) + 16));
          v14 = *((_DWORD *)v3 + 2);
          v15 = &v27[v12 / 4];
          v35 = (int)&v27[v12 / 4];
          if ( v13 )
          {
            *(_DWORD *)(v12 + v14) = *(v15 - 4);
            v16 = *(_DWORD *)v35;
          }
          else
          {
            *(_DWORD *)(v12 + v14) = *v15;
            v16 = *(_DWORD *)(v35 - 16);
          }
          v17 = v33;
          v18 = *((_DWORD *)v3 + 2);
          ++v34;
          v33 += 4;
          *(_DWORD *)(v17 + v18) = v16;
          v19 = v31;
          v20 = *((_DWORD *)v3 + 2);
          v21 = *(_DWORD *)(v35 + 16);
          v31 += 4;
          v22 = v34 < v4;
          *(_DWORD *)(v19 + v20) = v21;
        }
        while ( v22 );
      }
      if ( (*(int (__thiscall **)(D3DXShader::CPSLegacyProgram *, D3DXShader::CInstruction *, _DWORD))(*(_DWORD *)this + 32))(
             a1: this,
             a2: v3,
             a3: 0) != 0 )
      {
        v35 = 1;
        goto LABEL_31;
      }
      for ( i = 0; i < v32; ++i )
        *(_DWORD *)v28[i] = 0;
      v24 = *((D3DXShader::CInstruction **)this + 64);
      if ( v24 != nullptr )
        D3DXShader::CInstruction::`scalar deleting destructor'(this: v24, a2: 1);
      *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)this + 63)) = v3;
      v3 = nullptr;
      goto LABEL_30;
    }
  }
LABEL_31:
  if ( v3 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v3, a2: 1);
  return v35;
}
