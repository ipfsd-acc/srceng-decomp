// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxedgeaagen.cpp
// Functions: 9
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxedgeaagen.h"

//------------------------------------------------------------------------------
// Address: 0x101931F0
// Name: public: void GFxEdgeAAGenerator::ProcessAndSortEdges(class GTessellator __near &,class GFxFillStyle const __near *,unsigned int,float,enum GEdgeAA::AA_Method,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEdgeAAGenerator::ProcessAndSortEdges(
        GEdgeAA *this,
        GTessellator *a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  GEdgeAA *v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ecx
  signed int v10; // edi
  unsigned int v11; // esi
  int v12; // ecx
  signed int v14; // [esp+24h] [ebp+Ch]
  GTessellator v15; // [esp+28h] [ebp+10h]
  unsigned int v16; // [esp+34h] [ebp+1Ch]

  v7 = this;
  GEdgeAA::Clear(this);
  *((_DWORD *)v7 + 35) = a7;
  v8 = 0;
  *((_DWORD *)v7 + 32) = a3;
  *((_DWORD *)v7 + 33) = a4;
  if ( a3 != 0 && a4 == 0 )
    *((_DWORD *)v7 + 32) = 0;
  *((_BYTE *)v7 + 136) = 0;
  if ( a2[65] != nullptr )
  {
    do
    {
      GEdgeAA::AddVertex(
        this: v7,
        a2: (const struct GPointType *)(*(&a2[68]->attributes + (v8 >> 10)) + 8 * (v8 & 0x3FF)));
      ++v8;
    }
    while ( v8 < (unsigned int)a2[65] );
  }
  v9 = 0;
  if ( *((_DWORD *)v7 + 32) != 0 )
    v14 = *((_DWORD *)v7 + 33);
  else
    v14 = 0;
  v16 = 0;
  if ( a2[85] != nullptr )
  {
    while ( 1 )
    {
      v10 = *(_DWORD *)(*(&a2[88]->attributes + (v9 >> 6)) + 24 * (v9 & 0x3F) + 16) - 1;
      if ( v10 < v14 && *(_BYTE *)(*((_DWORD *)v7 + 32) + 40 * v10) != 0 )
      {
        v10 |= 0x40000000u;
        *((_BYTE *)v7 + 136) = 1;
      }
      GTessellator::TriangulateMonotone(this: a2, idx: v9);
      v11 = 0;
      v15 = a2[97];
      if ( v15 != nullptr )
      {
        do
        {
          v12 = *(&a2[100]->attributes + (v11 >> 10));
          GEdgeAA::AddTriangle(
            this,
            a2: *(_DWORD *)(v12 + 12 * (v11 & 0x3FF)),
            a3: *(_DWORD *)(v12 + 12 * (v11 & 0x3FF) + 4),
            a4: *(_DWORD *)(v12 + 12 * (v11 & 0x3FF) + 8),
            a5: v10);
          ++v11;
        }
        while ( v11 < (unsigned int)v15 );
      }
      v7 = this;
      if ( ++v16 >= (unsigned int)a2[85] )
        break;
      v9 = v16;
    }
  }
  GEdgeAA::ProcessEdges(a1: v7, a2: a5, a3: a6);
  if ( *((_BYTE *)v7 + 136) != 0 )
    GEdgeAA::SortTrianglesByStyle(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10193370
// Name: public: unsigned int GFxEdgeAAGenerator::GetVertexCount(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxEdgeAAGenerator::GetVertexCount(GFxEdgeAAGenerator *this)
{
  return *(_DWORD *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10193380
// Name: public: GFxEdgeAAGenerator::GFxEdgeAAGenerator(void)
// Source: json
//------------------------------------------------------------------------------
GFxEdgeAAGenerator *__thiscall GFxEdgeAAGenerator::GFxEdgeAAGenerator(GFxEdgeAAGenerator *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_BYTE *)this + 136) = 0;
  *((_DWORD *)this + 35) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10193400
// Name: public: GFxEdgeAAGenerator::~GFxEdgeAAGenerator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxEdgeAAGenerator::~GFxEdgeAAGenerator(GFxEdgeAAGenerator *this)
{
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 27));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 23);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 19);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 15);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 12));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 8);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 4);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease((int *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10193460
// Name: public: GFxEdgeAAGenerator_VertexCollector::GFxEdgeAAGenerator_VertexCollector(class GFxVertexArray __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxEdgeAAGenerator_VertexCollector *__thiscall GFxEdgeAAGenerator_VertexCollector::GFxEdgeAAGenerator_VertexCollector(
        GFxEdgeAAGenerator_VertexCollector *this,
        struct GFxVertexArray *a2,
        unsigned int a3)
{
  CVertexBuilder *v4; // esi
  unsigned int v5; // eax

  *(_DWORD *)this = a2;
  v4 = (CVertexBuilder *)((char *)this + 4);
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  GFxVertexArray::Resize(this: *(GFxVertexArray **)this, a2: a3);
  if ( a3 >= v4->m_VertexSize_BoneWeight )
  {
    if ( a3 >= v4->m_VertexSize_BoneMatrixIndex )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: v4,
        pheapAddr: (ButtonCode_t)v4,
        newCapacity: a3 + (a3 >> 2));
  }
  else if ( a3 < (unsigned int)v4->m_VertexSize_BoneMatrixIndex >> 1 )
  {
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
      this: v4,
      pheapAddr: (ButtonCode_t)v4,
      newCapacity: a3);
  }
  v5 = 0;
  for ( v4->m_VertexSize_BoneWeight = a3; v5 < *((_DWORD *)this + 2); ++v5 )
    *(_DWORD *)(v4->m_VertexSize_Position + 4 * v5) = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101934D0
// Name: public: unsigned int GFxEdgeAAGenerator_VertexCollector::AssignFactor(unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxEdgeAAGenerator_VertexCollector::AssignFactor(
        IScaleformUI *this,
        unsigned int val,
        unsigned int a3)
{
  IScaleformUI_vtbl *v4; // ecx
  InitReturnVal_t (__thiscall *Init)(IAppSystem *); // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  int v8; // ecx
  int v9; // edx
  bool v10; // zf
  unsigned int *v11; // edx
  unsigned int v12; // edi
  int v14; // eax
  unsigned int v15; // edi
  unsigned int i; // eax
  InitReturnVal_t (__thiscall *v17)(IAppSystem *); // ecx
  int v18; // edi
  int v19; // ecx
  int v20; // edi
  int (__stdcall *v21)(int); // eax
  int v22; // eax
  void (__thiscall *v23)(int, int, int *, int *); // edx
  unsigned int v24; // edi
  int *appended; // eax
  int v26; // esi
  int v27; // ebx
  int v28; // [esp+24h] [ebp-20h]
  int v29; // [esp+30h] [ebp-14h] BYREF
  int v30; // [esp+34h] [ebp-10h]
  int v31; // [esp+38h] [ebp-Ch] BYREF
  int v32; // [esp+3Ch] [ebp-8h] BYREF
  int v33; // [esp+40h] [ebp-4h]

  v4 = this->__vftable;
  Init = v4->Init;
  v6 = val;
  v7 = (unsigned int)v4->QueryInterface + val * *((_DWORD *)Init + 1);
  v8 = *((_DWORD *)Init + 2);
  v9 = *((_DWORD *)this + 1);
  v10 = *(_DWORD *)(v9 + 4 * val) == -1;
  v11 = (unsigned int *)(v9 + 4 * val);
  if ( v10 )
  {
    v12 = a3;
    *v11 = val;
    (*(void (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)v8 + 20))(a1: v8, a2: v7, a3: v12);
    return v6;
  }
  v14 = (*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)v8 + 28))(a1: v8, a2: v7);
  v15 = a3;
  if ( v14 == a3 )
    return v6;
  for ( i = *(_DWORD *)(*((_DWORD *)this + 1) + 4 * v6); i != v6; i = *(_DWORD *)(*((_DWORD *)this + 1) + 4 * v6) )
  {
    v6 = i;
    if ( (*(int (__thiscall **)(_DWORD, unsigned int))(**((_DWORD **)this->Init + 2) + 28))(
           a1: *((_DWORD *)this->Init + 2),
           a2: (unsigned int)this->QueryInterface + i * *((_DWORD *)this->Init + 1)) == v15 )
      return v6;
  }
  v17 = this->Init;
  v18 = *((_DWORD *)v17 + 1);
  v19 = *((_DWORD *)v17 + 2);
  v20 = (int)this->QueryInterface + v6 * v18;
  v21 = *(int (__stdcall **)(int))(*(_DWORD *)v19 + 24);
  v30 = v19;
  v22 = v21(a1: v20);
  v23 = *(void (__thiscall **)(int, int, int *, int *))(*(_DWORD *)v30 + 12);
  v33 = v22;
  v23(a1: v30, a2: v20, a3: &v31, a4: &v32);
  *(_DWORD *)(*((_DWORD *)this + 1) + 4 * v6) = this->Connect;
  val = (unsigned int)this->Connect;
  v24 = val;
  GArrayBase<GArrayData<unsigned int,GAllocatorGH<unsigned int,2>,GArrayDefaultPolicy>>::PushBack(
    this: this + 1,
    (GTexture::ChangeHandler *const *)&val,
    a3: v28);
  appended = GFxVertexArray::AppendVertex(this: (int *)this->__vftable, a2: &v29);
  v26 = appended[1];
  v27 = *appended;
  (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v26 + 4))(
    a1: v26,
    a2: *appended,
    a3: v31,
    a4: v32,
    a5: v33);
  (*(void (__thiscall **)(int, int, unsigned int))(*(_DWORD *)v26 + 20))(a1: v26, a2: v27, a3);
  return v24;
}

//------------------------------------------------------------------------------
// Address: 0x101935F0
// Name: public: bool GFxEdgeAAGenerator::GenerateSolidMesh(class GFxVertexArray __near *,class GFxMesh __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxEdgeAAGenerator::GenerateSolidMesh(
        GFxEdgeAAGenerator *this,
        struct GFxVertexArray *a2,
        struct GFxMesh *a3,
        float a4)
{
  GFxEdgeAAGenerator *v4; // esi
  struct GFxVertexArray *v5; // edi
  unsigned int v6; // ecx
  int v7; // ebx
  int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // eax
  GFxEdgeAAGenerator *v12; // ebx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // ecx
  int v16; // eax
  int v17; // eax
  unsigned int i; // edi
  int v19; // ecx
  float v21; // [esp+4h] [ebp-2Ch]
  int v22; // [esp+18h] [ebp-18h]
  int v23; // [esp+1Ch] [ebp-14h]
  unsigned int v24; // [esp+20h] [ebp-10h]
  float v25; // [esp+24h] [ebp-Ch]
  float v26; // [esp+24h] [ebp-Ch]
  int v27; // [esp+24h] [ebp-Ch]
  int v28; // [esp+24h] [ebp-Ch]
  int v29; // [esp+24h] [ebp-Ch]
  int v30; // [esp+24h] [ebp-Ch]
  bool v32; // [esp+2Fh] [ebp-1h]

  v4 = this;
  v5 = a2;
  GFxVertexArray::Resize(this: a2, a2: *(_DWORD *)this);
  v6 = 0;
  v22 = **((_DWORD **)a2 + 3);
  if ( *((_DWORD *)v4 + 32) != 0 )
    v23 = *((_DWORD *)v4 + 33);
  else
    v23 = 0;
  v24 = 0;
  if ( *(_DWORD *)v4 != 0 )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(*((_DWORD *)v4 + 3) + 4 * (v6 >> 8)) + 12 * (unsigned __int8)v6;
      v8 = *((_DWORD *)v5 + 3);
      v25 = *(float *)(v7 + 4) * a4;
      v9 = *((_DWORD *)v5 + 2) + v6 * *(_DWORD *)(v8 + 4);
      v10 = *(_DWORD *)(v8 + 8);
      v21 = v25;
      v26 = a4 * *(float *)v7;
      (*(void (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v10 + 4))(
        a1: v10,
        a2: v9,
        a3: LODWORD(v26),
        a4: LODWORD(v21),
        a5: 0);
      v11 = *(_DWORD *)(v7 + 8);
      v12 = this;
      v27 = v11;
      v13 = v11 & 0xFFFFFF;
      if ( v13 >= v23 || (v12 = this, v32 = v13 >= v23, *(_BYTE *)(*((_DWORD *)this + 32) + 40 * v13) == v13 >= v23) )
        v32 = true;
      if ( v27 >= 0 )
        break;
      if ( v22 != 3 )
      {
        if ( v13 < v23 )
        {
          if ( !v32 )
          {
            (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 20))(a1: v10, a2: v9, a3: 0xFFFFFF);
            goto LABEL_27;
          }
          v16 = *(_DWORD *)(*((_DWORD *)v12 + 32) + 40 * v13 + 4);
          v29 = v16;
          LOBYTE(v29) = BYTE2(v16);
          BYTE2(v29) = v16;
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 16))(a1: v10, a2: v9, a3: v29);
          v15 = *((_DWORD *)v12 + 35);
        }
        else
        {
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 16))(a1: v10, a2: v9, a3: -1);
          v15 = *((_DWORD *)v12 + 35);
        }
        goto LABEL_26;
      }
      if ( v13 < v23 )
      {
        if ( v32 )
        {
          v14 = *(_DWORD *)(*((_DWORD *)v12 + 32) + 40 * v13 + 4);
          BYTE1(v28) = BYTE1(v14);
          LOBYTE(v28) = BYTE2(v14);
          BYTE2(v28) = v14;
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 16))(a1: v10, a2: v9, a3: v28 & 0xFFFFFF);
        }
      }
      else
      {
        (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 16))(a1: v10, a2: v9, a3: 0xFFFFFF);
      }
LABEL_27:
      v4 = this;
      if ( ++v24 >= *(_DWORD *)v12 )
        goto LABEL_28;
      v6 = v24;
      v5 = a2;
    }
    if ( v13 < v23 )
    {
      if ( v32 )
      {
        v17 = *(_DWORD *)(*((_DWORD *)v12 + 32) + 40 * v13 + 4);
        v30 = v17;
        LOBYTE(v30) = BYTE2(v17);
        BYTE2(v30) = v17;
        (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 16))(a1: v10, a2: v9, a3: v30);
      }
    }
    else
    {
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 16))(a1: v10, a2: v9, a3: -1);
    }
    v15 = *((_DWORD *)v12 + 35) | 0xFF000000;
LABEL_26:
    (*(void (__thiscall **)(int, int, unsigned int))(*(_DWORD *)v10 + 20))(a1: v10, a2: v9, a3: v15);
    goto LABEL_27;
  }
LABEL_28:
  for ( i = 0; i < *((_DWORD *)v4 + 23); ++i )
  {
    v19 = *(_DWORD *)(*((_DWORD *)v4 + 26) + 4 * (i >> 8));
    GFxMesh::AddTriangle(
      this: a3,
      a2: *(_WORD *)(v19 + 12 * (unsigned __int8)i),
      a3: *(_WORD *)(v19 + 12 * (unsigned __int8)i + 4),
      a4: *(_WORD *)(v19 + 12 * (unsigned __int8)i + 8));
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10193830
// Name: public: bool GFxEdgeAAGenerator::GenerateSolidMesh(class GFxVertexArray __near *,class GFxMesh __near *,class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxEdgeAAGenerator::GenerateSolidMesh(
        GFxEdgeAAGenerator *this,
        struct GFxVertexArray *a2,
        struct GFxMesh *a3,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *a4)
{
  struct GFxVertexArray *v4; // esi
  unsigned int v6; // ecx
  int v7; // edx
  double v8; // st7
  int v9; // edx
  int v10; // eax
  int v11; // edi
  int v12; // edi
  int v13; // esi
  double v14; // st7
  int v15; // eax
  bool v16; // cl
  bool v17; // zf
  float v18; // eax
  void (__thiscall *v19)(int, int, int); // edx
  unsigned int v20; // ecx
  float v21; // eax
  float v22; // eax
  unsigned int i; // esi
  int v24; // ecx
  int v26; // [esp+Ch] [ebp-34h]
  int p[2]; // [esp+18h] [ebp-28h] BYREF
  CCountedStringPoolBase<unsigned int>::hash_item_t v28; // [esp+20h] [ebp-20h] BYREF
  int v29; // [esp+2Ch] [ebp-14h]
  int v30; // [esp+30h] [ebp-10h]
  unsigned int v31; // [esp+34h] [ebp-Ch]
  float v32; // [esp+38h] [ebp-8h]
  bool v33; // [esp+3Eh] [ebp-2h]
  char v34; // [esp+3Fh] [ebp-1h]

  v4 = a2;
  GFxVertexArray::Resize(this: a2, a2: *(_DWORD *)this);
  v6 = 0;
  *(_DWORD *)&v28.nReferenceCount = **((_DWORD **)a2 + 3);
  if ( *((_DWORD *)this + 32) != 0 )
    v30 = *((_DWORD *)this + 33);
  else
    v30 = 0;
  v31 = 0;
  if ( *(_DWORD *)this != 0 )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(*((_DWORD *)this + 3) + 4 * (v6 >> 8));
      v8 = *(float *)(v7 + 12 * (unsigned __int8)v6);
      v9 = v7 + 12 * (unsigned __int8)v6;
      v10 = *((_DWORD *)v4 + 3);
      *(float *)p = v8;
      v11 = v6 * *(_DWORD *)(v10 + 4);
      p[1] = *(int *)(v9 + 4);
      v12 = *((_DWORD *)v4 + 2) + v11;
      v13 = *(_DWORD *)(v10 + 8);
      v29 = v9;
      GMatrix2D::Transform(this: a4, result: &v28, (float *)p, p_4: v26);
      v32 = fabs(*(float *)&v28.pString);
      if ( v32 <= 32767.0 )
      {
        v14 = 32767.0;
      }
      else
      {
        v14 = 32767.0;
        if ( *(float *)&v28.pString <= 32767.0 )
          *(float *)&v28.pString = -32768.0;
        else
          *(float *)&v28.pString = 32767.0;
      }
      v32 = fabs(*(float *)&v28.nNextElement);
      if ( v32 > v14 )
      {
        if ( *(float *)&v28.nNextElement <= v14 )
          *(float *)&v28.nNextElement = -32768.0;
        else
          *(float *)&v28.nNextElement = 32767.0;
      }
      (*(void (__thiscall **)(int, int, char *, unsigned int, _DWORD))(*(_DWORD *)v13 + 4))(
        a1: v13,
        a2: v12,
        a3: v28.pString,
        a4: v28.nNextElement,
        a5: 0);
      v29 = *(_DWORD *)(v29 + 8);
      v15 = v29 & 0xFFFFFF;
      v16 = (v29 & 0xFFFFFF) >= v30;
      v33 = v16;
      if ( (v29 & 0xFFFFFF) >= v30
        || (v17 = *(_BYTE *)(*((_DWORD *)this + 32) + 40 * v15) == 0, v16 = v33, v34 = 0, v17) )
      {
        v34 = 1;
      }
      if ( v29 >= 0 )
        break;
      if ( *(_DWORD *)&v28.nReferenceCount != 3 )
      {
        if ( v16 )
        {
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v13 + 16))(a1: v13, a2: v12, a3: -1);
          v20 = *((_DWORD *)this + 35);
        }
        else
        {
          if ( v34 == 0 )
          {
            (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v13 + 20))(a1: v13, a2: v12, a3: 0xFFFFFF);
            goto LABEL_36;
          }
          v21 = *(float *)(*((_DWORD *)this + 32) + 40 * v15 + 4);
          v32 = v21;
          LOBYTE(v32) = BYTE2(v21);
          BYTE2(v32) = LOBYTE(v21);
          (*(void (__thiscall **)(int, int, float))(*(_DWORD *)v13 + 16))(
            a1: v13,
            a2: v12,
            a3: COERCE_FLOAT(LODWORD(v32)));
          v20 = *((_DWORD *)this + 35);
        }
        goto LABEL_35;
      }
      if ( v16 )
      {
        (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v13 + 16))(a1: v13, a2: v12, a3: 0xFFFFFF);
      }
      else if ( v34 != 0 )
      {
        v18 = *(float *)(*((_DWORD *)this + 32) + 40 * v15 + 4);
        v19 = *(void (__thiscall **)(int, int, int))(*(_DWORD *)v13 + 16);
        v32 = v18;
        BYTE2(v32) = LOBYTE(v18);
        LOBYTE(v32) = BYTE2(v18);
        v19(a1: v13, a2: v12, a3: LODWORD(v32) & 0xFFFFFF);
      }
LABEL_36:
      if ( ++v31 >= *(_DWORD *)this )
        goto LABEL_37;
      v4 = a2;
      v6 = v31;
    }
    if ( v16 )
    {
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v13 + 16))(a1: v13, a2: v12, a3: -1);
    }
    else if ( v34 != 0 )
    {
      v22 = *(float *)(*((_DWORD *)this + 32) + 40 * v15 + 4);
      v32 = v22;
      LOBYTE(v32) = BYTE2(v22);
      BYTE2(v32) = LOBYTE(v22);
      (*(void (__thiscall **)(int, int, float))(*(_DWORD *)v13 + 16))(a1: v13, a2: v12, a3: COERCE_FLOAT(LODWORD(v32)));
    }
    v20 = *((_DWORD *)this + 35) | 0xFF000000;
LABEL_35:
    (*(void (__thiscall **)(int, int, unsigned int))(*(_DWORD *)v13 + 20))(a1: v13, a2: v12, a3: v20);
    goto LABEL_36;
  }
LABEL_37:
  for ( i = 0; i < *((_DWORD *)this + 23); ++i )
  {
    v24 = *(_DWORD *)(*((_DWORD *)this + 26) + 4 * (i >> 8));
    GFxMesh::AddTriangle(
      this: a3,
      a2: *(_WORD *)(v24 + 12 * (unsigned __int8)i),
      a3: *(_WORD *)(v24 + 12 * (unsigned __int8)i + 4),
      a4: *(_WORD *)(v24 + 12 * (unsigned __int8)i + 8));
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10193AF0
// Name: public: unsigned int GFxEdgeAAGenerator::GenerateTexturedMeshes(class GFxVertexArray __near *,class GArrayLH<class GFxMesh,131,struct GArrayDefaultPolicy> __near *,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxEdgeAAGenerator::GenerateTexturedMeshes(
        unsigned int *this,
        struct GFxVertexArray *a2,
        unsigned int *a3,
        float a4)
{
  int v5; // edx
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // edi
  int v10; // esi
  void (__thiscall *v11)(int, int, _DWORD, _DWORD, _DWORD); // edx
  float v12; // eax
  unsigned int *v13; // ebx
  int v14; // eax
  bool v15; // cl
  int v16; // eax
  void (__thiscall *v17)(int, int, unsigned int); // edx
  unsigned int v18; // ecx
  int v19; // eax
  int v20; // eax
  IScaleformUI_vtbl *v21; // esi
  unsigned int v22; // ecx
  unsigned __int16 *v23; // edi
  int v24; // edx
  int v25; // eax
  int v26; // ecx
  bool v27; // bl
  unsigned int v28; // eax
  bool v29; // dl
  int v30; // eax
  int v31; // ecx
  unsigned int v32; // edx
  unsigned int *v33; // ebx
  unsigned int v34; // eax
  int v35; // eax
  unsigned int v36; // ecx
  unsigned int v37; // eax
  unsigned int v38; // eax
  unsigned int v39; // edx
  unsigned int v40; // ebx
  InitReturnVal_t (__thiscall *Init)(IAppSystem *); // ecx
  int v42; // eax
  int v43; // ecx
  int v44; // eax
  unsigned int v45; // edi
  int v46; // eax
  InitReturnVal_t (__thiscall *v47)(IAppSystem *); // ecx
  int v48; // edx
  int v49; // ecx
  int v50; // ecx
  bool v51; // zf
  int v52; // ecx
  unsigned int v53; // eax
  void *(__thiscall *QueryInterface)(IAppSystem *, const char *); // edx
  char *v55; // edi
  int v56; // eax
  void *(__thiscall *v57)(IAppSystem *, const char *); // edx
  char *v58; // edi
  int v59; // eax
  void *v60; // eax
  void *(__thiscall *v61)(IAppSystem *, const char *); // edx
  char *v62; // edi
  int v63; // eax
  void *(__thiscall *v64)(IAppSystem *, const char *); // edx
  char *v65; // edi
  int v66; // eax
  __int16 v67; // ax
  void *(__thiscall *v68)(IAppSystem *, const char *); // edx
  char *v69; // edi
  int v70; // eax
  void *(__thiscall *v71)(IAppSystem *, const char *); // edx
  char *v72; // edi
  int v73; // eax
  float v75; // [esp+4h] [ebp-98h]
  unsigned int v76; // [esp+8h] [ebp-94h]
  int v77; // [esp+1Ch] [ebp-80h]
  int v78; // [esp+24h] [ebp-78h]
  int v79; // [esp+2Ch] [ebp-70h]
  int v80; // [esp+34h] [ebp-68h]
  int v81; // [esp+3Ch] [ebp-60h]
  int v82; // [esp+44h] [ebp-58h]
  int v83; // [esp+48h] [ebp-54h]
  int v84; // [esp+4Ch] [ebp-50h]
  IScaleformUI v85[4]; // [esp+50h] [ebp-4Ch] BYREF
  int v86; // [esp+60h] [ebp-3Ch]
  int v87; // [esp+64h] [ebp-38h]
  unsigned int v88; // [esp+68h] [ebp-34h]
  unsigned int v89; // [esp+6Ch] [ebp-30h]
  signed int v90; // [esp+70h] [ebp-2Ch]
  float v91; // [esp+74h] [ebp-28h]
  unsigned int v92; // [esp+78h] [ebp-24h]
  unsigned int v93; // [esp+7Ch] [ebp-20h]
  unsigned int *v94; // [esp+80h] [ebp-1Ch]
  bool v95; // [esp+86h] [ebp-16h]
  bool v96; // [esp+87h] [ebp-15h]
  unsigned int v97; // [esp+88h] [ebp-14h]
  char v98; // [esp+8Fh] [ebp-Dh]
  int v99; // [esp+90h] [ebp-Ch]
  void *hdata; // [esp+94h] [ebp-8h]
  char v101; // [esp+9Ah] [ebp-2h]
  bool v102; // [esp+9Bh] [ebp-1h]
  bool v103; // [esp+A7h] [ebp+Bh]
  bool v104; // [esp+AFh] [ebp+13h]

  v5 = **((_DWORD **)a2 + 3);
  v76 = *this;
  v94 = this;
  v87 = v5;
  GFxEdgeAAGenerator_VertexCollector::GFxEdgeAAGenerator_VertexCollector(
    this: (GFxEdgeAAGenerator_VertexCollector *)v85,
    a2,
    a3: v76);
  v51 = *this == 0;
  v98 = 0;
  v93 = 0;
  if ( !v51 )
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(v94[3] + 4 * (v93 >> 8)) + 12 * (unsigned __int8)v93;
      v7 = *((_DWORD *)a2 + 3);
      v8 = *(_DWORD *)(v7 + 4);
      v9 = *(_DWORD *)(v7 + 8);
      v91 = *(float *)(v6 + 4) * a4;
      v10 = *((_DWORD *)a2 + 2) + v93 * v8;
      v11 = *(void (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v9 + 4);
      v75 = v91;
      v91 = a4 * *(float *)v6;
      v11(a1: v9, a2: v10, a3: LODWORD(v91), a4: LODWORD(v75), a5: 0);
      v12 = *(float *)(v6 + 8);
      v13 = v94;
      v91 = v12;
      v14 = LODWORD(v12) & 0xFFFFFF;
      v15 = v14 >= (int)v94[33];
      if ( v14 >= (int)v94[33]
        || (v51 = *(_BYTE *)(v94[32] + 40 * v14) == v15, v13 = v94, v102 = v14 >= (int)v94[33], v51) )
      {
        v102 = true;
      }
      if ( v91 >= 0.0 )
        break;
      if ( v87 == 3 )
      {
        if ( v15 )
        {
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v9 + 16))(a1: v9, a2: v10, a3: 0xFFFFFF);
        }
        else if ( v102 )
        {
          v16 = *(_DWORD *)(v13[32] + 40 * v14 + 4);
          v99 = v16;
          LOBYTE(v99) = BYTE2(v16);
          BYTE2(v99) = v16;
          v17 = *(void (__thiscall **)(int, int, unsigned int))(*(_DWORD *)v9 + 16);
          v18 = v99 & 0xFFFFFF;
          goto LABEL_22;
        }
      }
      else
      {
        if ( v15 )
        {
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v9 + 16))(a1: v9, a2: v10, a3: -1);
          v18 = v13[35];
          goto LABEL_21;
        }
        if ( v102 )
        {
          v19 = *(_DWORD *)(v13[32] + 40 * v14 + 4);
          v99 = v19;
          LOBYTE(v99) = BYTE2(v19);
          BYTE2(v99) = v19;
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v9 + 16))(a1: v9, a2: v10, a3: v99);
          v18 = v13[35];
          goto LABEL_21;
        }
        (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v9 + 20))(a1: v9, a2: v10, a3: 0xFFFFFF);
      }
LABEL_23:
      v98 |= v102;
      if ( ++v93 >= *v13 )
        goto LABEL_24;
    }
    if ( v15 )
    {
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v9 + 16))(a1: v9, a2: v10, a3: -1);
    }
    else if ( v102 )
    {
      v20 = *(_DWORD *)(v13[32] + 40 * v14 + 4);
      v99 = v20;
      LOBYTE(v99) = BYTE2(v20);
      BYTE2(v99) = v20;
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v9 + 16))(a1: v9, a2: v10, a3: v99);
    }
    v18 = v13[35] | 0xFF000000;
LABEL_21:
    v17 = *(void (__thiscall **)(int, int, unsigned int))(*(_DWORD *)v9 + 20);
LABEL_22:
    v17(a1: v9, a2: v10, a3: v18);
    goto LABEL_23;
  }
LABEL_24:
  v99 = -1;
  v88 = -1;
  v90 = -1;
  v86 = 0;
  v93 = 0;
  if ( v94[23] != 0 )
  {
    v21 = v85[0].__vftable;
    do
    {
      v22 = v94[3];
      v23 = (unsigned __int16 *)(*(_DWORD *)(v94[26] + 4 * (v93 >> 8)) + 12 * (unsigned __int8)v93);
      v24 = *(_DWORD *)(v22 + 4 * (*(_DWORD *)v23 >> 8)) + 12 * (unsigned __int8)*(_DWORD *)v23;
      v87 = *(_DWORD *)(v22 + 4 * (*((_DWORD *)v23 + 1) >> 8)) + 12 * (unsigned __int8)*((_DWORD *)v23 + 1);
      v25 = *(_DWORD *)(v22 + 4 * (*((_DWORD *)v23 + 2) >> 8)) + 12 * (unsigned __int8)*((_DWORD *)v23 + 2);
      v26 = *(_DWORD *)(v24 + 8);
      v91 = *(float *)&v24;
      v27 = (v26 & 0xC0000000) == 0x40000000;
      v84 = v25;
      v28 = *(_DWORD *)(v25 + 8);
      v97 = *(_DWORD *)(v87 + 8);
      v92 = v28;
      v29 = (v97 & 0xC0000000) == 0x40000000;
      v104 = (v28 & 0xC0000000) == 0x40000000;
      v95 = v27 || v29 || v104;
      v83 = v26;
      v30 = v26 & 0xFFFFFF;
      v31 = v99 & 0xFFFFFF;
      v102 = v27;
      v103 = v29;
      if ( (v99 & 0xFFFFFF) == v30 || !v27 )
      {
        v29 = (v97 & 0xC0000000) == 0x40000000;
        if ( (((v88 ^ v97) & 0xFFFFFF) == 0 || (v97 & 0xC0000000) != 0x40000000)
          && (((v90 ^ v92) & 0xFFFFFF) == 0 || !v104)
          && v93 != 0 )
        {
LABEL_78:
          v33 = a3;
          goto LABEL_79;
        }
      }
      hdata = nullptr;
      if ( v95 )
      {
        hdata = (void *)((v98 != 0) + 1);
        if ( v102 && v29 && v104 && ((v92 & 0xFFFFFF) != (v97 & 0xFFFFFF) || (v92 & 0xFFFFFF) != v30) )
          hdata = (void *)3;
      }
      v101 = 0;
      if ( hdata == (void *)2 || hdata == (void *)1 || hdata == (void *)3 )
      {
        v96 = (v99 & 0xC0000000) == 0x40000000;
        v32 = v92 & 0xFFFFFF;
        v89 = v90 & 0xFFFFFF;
        if ( (v90 & 0xFFFFFF) == (v92 & 0xFFFFFF) && (v31 == v30 || v30 == v32 || hdata == (void *)2 && (!v102 || !v96)) )
        {
          if ( (v97 & 0xC0000000) == 0x40000000 )
          {
            if ( ((v97 & 0xFFFFFF) == v32 || (v97 & 0xFFFFFF) == v30)
              && ((v88 & 0xC0000000) != 0x40000000
               || (v88 & 0xFFFFFF) == v32
               || (v88 & 0xFFFFFF) == v30
               || hdata != (void *)3) )
            {
LABEL_59:
              v101 = 1;
            }
          }
          else if ( !v96 && v31 == (v90 & 0xFFFFFF) )
          {
            goto LABEL_59;
          }
        }
      }
      v99 = v83;
      v88 = v97;
      v90 = v92;
      if ( v101 != 0 )
        goto LABEL_78;
      v33 = a3;
      GArrayData<GFxMesh,GAllocatorLH<GFxMesh,131>,GArrayDefaultPolicy>::Resize(this: a3, a2: a3[1] + 1);
      v34 = a3[1];
      ++v86;
      GRenderTargetImplNode::SetUserData(this: (GRenderTargetImplNode *)(*a3 + 40 * v34 - 40), hdata);
      if ( (int)hdata <= 0 )
        goto LABEL_77;
      if ( (int)hdata <= 2 )
      {
        if ( v90 >= 0 )
          v38 = v90 & 0xFFFFFF;
        else
          v38 = -1;
        GFxMesh::SetEdgeAAStyles(
          this: (GFxMesh *)(*a3 + 40 * a3[1] - 40),
          a2: 1u,
          a3: v38,
          a4: 0xFFFFFFFF,
          a5: 0xFFFFFFFF);
      }
      else
      {
        if ( hdata != (void *)3 )
        {
LABEL_77:
          GFxMesh::SetEdgeAAStyles(
            this: (GFxMesh *)(*a3 + 40 * a3[1] - 40),
            a2: 0,
            a3: 0xFFFFFFFF,
            a4: 0xFFFFFFFF,
            a5: 0xFFFFFFFF);
          goto LABEL_79;
        }
        v35 = v88;
        v36 = v90 & 0xFFFFFF;
        if ( (v90 & 0xFFFFFF) == (v88 & 0xFFFFFF) )
          v35 = v99;
        if ( v35 >= 0 )
          v37 = v35 & 0xFFFFFF;
        else
          v37 = -1;
        if ( v90 < 0 )
          v36 = -1;
        GFxMesh::SetEdgeAAStyles(this: (GFxMesh *)(*a3 + 40 * a3[1] - 40), a2: 2u, a3: v36, a4: v37, a5: 0xFFFFFFFF);
      }
LABEL_79:
      if ( !v95 )
      {
        GFxMesh::AddTriangle(this: (GFxMesh *)(*v33 + 40 * v33[1] - 40), a2: *v23, a3: v23[2], a4: v23[4]);
        goto LABEL_109;
      }
      v39 = *(_DWORD *)v23;
      v40 = *((_DWORD *)v23 + 2);
      hdata = *((void **)v23 + 1);
      Init = v21->Init;
      v42 = *((_DWORD *)Init + 1);
      v43 = *((_DWORD *)Init + 2);
      v44 = (int)v21->QueryInterface + v39 * v42;
      v97 = v39;
      v45 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v43 + 28))(a1: v43, a2: v44) & 0xFF000000;
      v46 = (*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)v21->Init + 2) + 28))(
              a1: *((_DWORD *)v21->Init + 2),
              a2: (int)v21->QueryInterface + (_DWORD)hdata * *((_DWORD *)v21->Init + 1));
      v47 = v21->Init;
      v92 = v46 & 0xFF000000;
      v89 = (*(int (__thiscall **)(_DWORD, unsigned int))(**((_DWORD **)v47 + 2) + 28))(
              a1: *((_DWORD *)v47 + 2),
              a2: (unsigned int)v21->QueryInterface + v40 * *((_DWORD *)v47 + 1))
          & 0xFF000000;
      if ( v104 )
      {
        v48 = *(_DWORD *)(v87 + 8);
        v49 = *(_DWORD *)(v84 + 8);
        v89 |= 0xFFFFFFu;
        v50 = v49 & 0xFFFFFF;
        if ( (v48 & 0xFFFFFF) == v50 || v48 < 0 )
        {
          v52 = *(_DWORD *)(LODWORD(v91) + 8);
          v92 |= 0xFFFFFFu;
          if ( (v52 & 0xFFFFFF) != (v48 & 0xFFFFFF) )
          {
            v51 = v52 >= 0;
            goto LABEL_87;
          }
        }
        else if ( (*(_DWORD *)(LODWORD(v91) + 8) & 0xFFFFFF) != v50 )
        {
          v51 = *(int *)(LODWORD(v91) + 8) >= 0;
LABEL_87:
          if ( v51 )
            goto LABEL_89;
        }
        v45 |= 0xFFFFFFu;
      }
LABEL_89:
      if ( v102 )
      {
        v53 = GFxEdgeAAGenerator_VertexCollector::AssignFactor(this: v85, val: v97, a3: v45);
        v21 = v85[0].__vftable;
        v97 = v53;
      }
      else
      {
        if ( v103 )
        {
          QueryInterface = v21->QueryInterface;
          v55 = (char *)QueryInterface + (_DWORD)hdata * *((_DWORD *)v21->Init + 1);
          v80 = *((_DWORD *)v21->Init + 2);
          v56 = (*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)v80 + 24))(
                  a1: v80,
                  a2: (unsigned int)QueryInterface + v97 * *((_DWORD *)v21->Init + 1));
          (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v80 + 16))(a1: v80, a2: v55, a3: v56);
        }
        if ( v104 )
        {
          v57 = v21->QueryInterface;
          v58 = (char *)v57 + v40 * *((_DWORD *)v21->Init + 1);
          v77 = *((_DWORD *)v21->Init + 2);
          v59 = (*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)v77 + 24))(
                  a1: v77,
                  a2: (unsigned int)v57 + v97 * *((_DWORD *)v21->Init + 1));
          (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v77 + 16))(a1: v77, a2: v58, a3: v59);
        }
      }
      if ( v103 )
      {
        v60 = (void *)GFxEdgeAAGenerator_VertexCollector::AssignFactor(this: v85, val: (unsigned int)hdata, a3: v92);
        v21 = v85[0].__vftable;
        hdata = v60;
      }
      else
      {
        if ( v102 )
        {
          v61 = v21->QueryInterface;
          v62 = (char *)v61 + v97 * *((_DWORD *)v21->Init + 1);
          v82 = *((_DWORD *)v21->Init + 2);
          v63 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v82 + 24))(
                  a1: v82,
                  a2: (int)v61 + (_DWORD)hdata * *((_DWORD *)v21->Init + 1));
          (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v82 + 16))(a1: v82, a2: v62, a3: v63);
        }
        if ( !v104 )
        {
LABEL_103:
          if ( v102 )
          {
            v68 = v21->QueryInterface;
            v69 = (char *)v68 + v97 * *((_DWORD *)v21->Init + 1);
            v81 = *((_DWORD *)v21->Init + 2);
            v70 = (*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)v81 + 24))(
                    a1: v81,
                    a2: (unsigned int)v68 + v40 * *((_DWORD *)v21->Init + 1));
            (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v81 + 16))(a1: v81, a2: v69, a3: v70);
          }
          if ( v103 )
          {
            v71 = v21->QueryInterface;
            v72 = (char *)v71 + (_DWORD)hdata * *((_DWORD *)v21->Init + 1);
            v79 = *((_DWORD *)v21->Init + 2);
            v73 = (*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)v79 + 24))(
                    a1: v79,
                    a2: (unsigned int)v71 + v40 * *((_DWORD *)v21->Init + 1));
            (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v79 + 16))(a1: v79, a2: v72, a3: v73);
          }
          goto LABEL_107;
        }
        v64 = v21->QueryInterface;
        v65 = (char *)v64 + v40 * *((_DWORD *)v21->Init + 1);
        v78 = *((_DWORD *)v21->Init + 2);
        v66 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v78 + 24))(
                a1: v78,
                a2: (int)v64 + (_DWORD)hdata * *((_DWORD *)v21->Init + 1));
        (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v78 + 16))(a1: v78, a2: v65, a3: v66);
      }
      if ( !v104 )
        goto LABEL_103;
      v67 = GFxEdgeAAGenerator_VertexCollector::AssignFactor(this: v85, val: v40, a3: v89);
      v21 = v85[0].__vftable;
      LOWORD(v40) = v67;
LABEL_107:
      GFxMesh::AddTriangle(this: (GFxMesh *)(*a3 + 40 * a3[1] - 40), a2: v97, a3: (unsigned __int16)hdata, a4: v40);
LABEL_109:
      ++v93;
    }
    while ( v93 < v94[23] );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v85[1].__vftable);
  return v86;
}
