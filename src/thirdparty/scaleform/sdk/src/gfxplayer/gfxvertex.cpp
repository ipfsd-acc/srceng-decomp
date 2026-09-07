// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxvertex.cpp
// Functions: 86
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxvertex.h"

//------------------------------------------------------------------------------
// Address: 0x1018ADA0
// Name: public: virtual void GFxVertexInterface::GetXY(struct GFxVertexType __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface::GetXY(GFxVertexInterface *this, struct GFxVertexType *a2, float *a3, float *a4)
{
  *a3 = 0.0;
  *a4 = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1018ADC0
// Name: public: virtual void GFxVertexInterface_XY16i::InitVertex(struct GFxVertexType __near *,float,float,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface_XY16i::InitVertex(
        GFxVertexInterface_XY16i *this,
        struct GFxVertexType *a2,
        float a3,
        float a4,
        unsigned int a5)
{
  *(_WORD *)a2 = (int)a3;
  *((_WORD *)a2 + 1) = (int)a4;
}

//------------------------------------------------------------------------------
// Address: 0x1018ADF0
// Name: public: virtual void GFxVertexInterface_XY16i::GetXY(struct GFxVertexType __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface_XY16i::GetXY(
        GFxVertexInterface_XY16i *this,
        struct GFxVertexType *a2,
        float *a3,
        float *a4)
{
  *a3 = (float)*(__int16 *)a2;
  *a4 = (float)*((__int16 *)a2 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1018AE20
// Name: public: virtual void GFxVertexInterface_XY32f::InitVertex(struct GFxVertexType __near *,float,float,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface_XY32f::InitVertex(
        GFxVertexInterface_XY32f *this,
        struct GFxVertexType *a2,
        float a3,
        float a4,
        unsigned int a5)
{
  *(float *)a2 = a3;
  *((float *)a2 + 1) = a4;
}

//------------------------------------------------------------------------------
// Address: 0x1018AE40
// Name: public: virtual void GFxVertexInterface_XY32f::SetXY(struct GFxVertexType __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface_XY32f::SetXY(
        GFxVertexInterface_XY32f *this,
        struct GFxVertexType *a2,
        float a3,
        float a4)
{
  *(float *)a2 = a3;
  *((float *)a2 + 1) = a4;
}

//------------------------------------------------------------------------------
// Address: 0x1018AE60
// Name: public: virtual void GFxVertexInterface_XY32f::GetXY(struct GFxVertexType __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface_XY32f::GetXY(
        GFxVertexInterface_XY32f *this,
        struct GFxVertexType *a2,
        float *a3,
        float *a4)
{
  *a3 = *(float *)a2;
  *a4 = *((float *)a2 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1018AE80
// Name: public: virtual void GFxVertexInterface_XY16iC32::InitVertex(struct GFxVertexType __near *,float,float,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface_XY16iC32::InitVertex(
        GFxVertexInterface_XY16iC32 *this,
        struct GFxVertexType *a2,
        float a3,
        float a4,
        unsigned int a5)
{
  *(_WORD *)a2 = (int)a3;
  *((_WORD *)a2 + 1) = (int)a4;
  *((_DWORD *)a2 + 1) = a5;
}

//------------------------------------------------------------------------------
// Address: 0x1018AEB0
// Name: public: virtual void GFxVertexInterface_XY16iC32::SetXY(struct GFxVertexType __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface_XY16iC32::SetXY(
        GFxVertexInterface_XY16iC32 *this,
        struct GFxVertexType *a2,
        float a3,
        float a4)
{
  *(_WORD *)a2 = (int)a3;
  *((_WORD *)a2 + 1) = (int)a4;
}

//------------------------------------------------------------------------------
// Address: 0x1018AEE0
// Name: public: virtual void GFxVertexInterface_XY16iCF32::InitVertex(struct GFxVertexType __near *,float,float,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface_XY16iCF32::InitVertex(
        GFxVertexInterface_XY16iCF32 *this,
        struct GFxVertexType *a2,
        float a3,
        float a4,
        unsigned int a5)
{
  *(_WORD *)a2 = (int)a3;
  *((_WORD *)a2 + 1) = (int)a4;
  *((_DWORD *)a2 + 1) = a5;
  *((_DWORD *)a2 + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018AF10
// Name: public: virtual void GFxVertexInterface_XY16iCF32::SetColor(struct GFxVertexType __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface_XY16iCF32::SetColor(
        GFxVertexInterface_XY16iCF32 *this,
        struct GFxVertexType *a2,
        unsigned int a3)
{
  *((_DWORD *)a2 + 1) = a3;
}

//------------------------------------------------------------------------------
// Address: 0x1018AF20
// Name: public: virtual unsigned long GFxVertexInterface_XY16iCF32::GetColor(struct GFxVertexType __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxVertexInterface_XY16iCF32::GetColor(
        GFxVertexInterface_XY16iCF32 *this,
        struct GFxVertexType *a2)
{
  return *((_DWORD *)a2 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1018AF30
// Name: public: virtual void GFxVertexInterface_XY16iCF32::SetFactor(struct GFxVertexType __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexInterface_XY16iCF32::SetFactor(
        GFxVertexInterface_XY16iCF32 *this,
        struct GFxVertexType *a2,
        unsigned int a3)
{
  *((_DWORD *)a2 + 2) = a3;
}

//------------------------------------------------------------------------------
// Address: 0x1018AF40
// Name: public: GFxVertexArray::~GFxVertexArray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexArray::~GFxVertexArray(GFxVertexArray *this)
{
  void *v1; // eax

  v1 = *((void **)this + 2);
  if ( v1 != nullptr )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1018AF60
// Name: public: void GFxVertexArray::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexArray::Resize(GFxVertexArray *this, unsigned int a2)
{
  unsigned int v3; // ecx
  unsigned int v4; // edi
  _DWORD *v5; // eax
  int v6; // ecx
  unsigned __int8 *v7; // ebx
  unsigned __int8 *v8; // eax

  v3 = *(_DWORD *)this;
  v4 = a2;
  if ( a2 != v3 )
  {
    v5 = *((_DWORD **)this + 3);
    if ( *v5 != 0 )
    {
      if ( a2 > *((_DWORD *)this + 1) && a2 > v3 )
      {
        v6 = *((_DWORD *)this + 4);
        a2 = 130;
        v7 = (unsigned __int8 *)(*(int (__thiscall **)(int, unsigned int, unsigned int *))(*(_DWORD *)v6 + 40))(
                                  a1: v6,
                                  a2: v4 * v5[1],
                                  a3: &a2);
        v8 = *((unsigned __int8 **)this + 2);
        if ( v8 != nullptr )
        {
          if ( v7 != nullptr )
            memcpy(dst: v7, src: v8, count: *(_DWORD *)this * *(_DWORD *)(*((_DWORD *)this + 3) + 4));
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2));
        }
        *((_DWORD *)this + 2) = v7;
        *((_DWORD *)this + 1) = v4;
      }
      *(_DWORD *)this = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018AFE0
// Name: public: void GFxVertexArray::Reserve(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexArray::Reserve(GFxVertexArray *this, unsigned int a2, int a3)
{
  unsigned int v4; // edx
  unsigned int v5; // edi
  _DWORD *v6; // ecx
  unsigned __int8 *v7; // ebx
  unsigned __int8 *v8; // eax

  v4 = *((_DWORD *)this + 1);
  v5 = a2;
  if ( a2 != v4 )
  {
    v6 = *((_DWORD **)this + 3);
    if ( *v6 != 0 )
    {
      if ( a2 < *(_DWORD *)this )
        v5 = *(_DWORD *)this;
      if ( v5 > v4 || (_BYTE)a3 != 0 && v4 != v5 )
      {
        if ( v5 != 0 )
        {
          a3 = 130;
          v7 = (unsigned __int8 *)(*(int (__thiscall **)(_DWORD, unsigned int, int *))(**((_DWORD **)this + 4) + 40))(
                                    a1: *((_DWORD *)this + 4),
                                    a2: v5 * v6[1],
                                    &a3);
        }
        else
        {
          v7 = nullptr;
        }
        v8 = *((unsigned __int8 **)this + 2);
        if ( v8 != nullptr )
        {
          if ( v7 != nullptr )
            memcpy(dst: v7, src: v8, count: *(_DWORD *)this * *(_DWORD *)(*((_DWORD *)this + 3) + 4));
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2));
        }
        *((_DWORD *)this + 2) = v7;
        *((_DWORD *)this + 1) = v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B080
// Name: public: void GFxVertexArray::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexArray::Clear(GFxVertexArray *this)
{
  GFxVertexArray::Resize(this, a2: 0);
  GFxVertexArray::Reserve(this, a2: 0, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1018B0A0
// Name: public: void GFxVertexArray::AppendVertices(class GFxVertexArray const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexArray::AppendVertices(GFxVertexArray *this, unsigned __int8 **a2)
{
  int v3; // eax
  unsigned int v4; // eax

  v3 = **((_DWORD **)this + 3);
  if ( v3 == *(_DWORD *)a2[3] && v3 != 0 )
  {
    GFxVertexArray::Reserve(this, a2: (unsigned int)&(*a2)[*(_DWORD *)this], a3: 0);
    v4 = (unsigned int)&(*a2)[*(_DWORD *)this];
    if ( *((_DWORD *)this + 1) >= v4 )
    {
      *(_DWORD *)this = v4;
      if ( *a2 != nullptr )
        memcpy(
          dst: (unsigned __int8 *)(*((_DWORD *)this + 2) + *(_DWORD *)(*((_DWORD *)this + 3) + 4) * (v4 - (_DWORD)*a2)),
          src: a2[2],
          count: (_DWORD)*a2 * *(_DWORD *)(*((_DWORD *)this + 3) + 4));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B110
// Name: public: void GFxVertexArray::ApplyToRenderer(class GRenderer __near *,class GRenderer::CacheProvider __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxVertexArray::ApplyToRenderer(
        GFxVertexArray *this,
        struct GRenderer *a2,
        struct GRenderer::CacheProvider *a3)
{
  a2->SetVertexData(
    this: a2,
    a2: *((const void **)this + 2),
    a3: *(_DWORD *)this,
    a4: **((GRenderer::VertexFormat **)this + 3),
    a5: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1018B140
// Name: public: class GFxVertexRef GFxVertexArray::AppendVertex(void)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GFxVertexArray::AppendVertex(int *this, int *a2)
{
  int v3; // ecx
  int v4; // eax
  int v5; // edx
  int v7; // ecx

  if ( *(this + 1) <= (unsigned int)*this )
    GFxVertexArray::Reserve((GFxVertexArray *)this, a2: *this + 16, a3: 0);
  if ( *(this + 1) <= (unsigned int)*this )
  {
    if ( (_S2_1 & 1) == 0 )
    {
      _S2_1 |= 1u;
      dword_103599C8 = (int)&GFxVertexInterface::`vftable';
      atexit(func: (void (__cdecl *)())GFxVertexArray::AppendVertex_::_7_::_dynamic_atexit_destructor_for__viNone__);
    }
    *a2 = 0;
    a2[1] = (int)&dword_103599C8;
    return a2;
  }
  else
  {
    v3 = *(this + 3);
    v4 = *this + 1;
    *this = v4;
    v5 = *(this + 2) + *(_DWORD *)(v3 + 4) * (v4 - 1);
    v7 = *(_DWORD *)(v3 + 8);
    *a2 = v5;
    a2[1] = v7;
    return a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B1C0
// Name: private: struct GFxVertexDesc __near * GFxVertexArray::GetFormatDesc(enum GRenderer::VertexFormat)
// Source: json
//------------------------------------------------------------------------------
struct GFxVertexDesc *__thiscall GFxVertexArray::GetFormatDesc(GFxVertexArray *this, enum GRenderer::VertexFormat a2)
{
  struct GFxVertexDesc *result; // eax

  if ( (_S1_5 & 1) == 0 )
  {
    _S1_5 |= 1u;
    dword_103599E0 = (int)&GFxVertexInterface::`vftable';
    atexit(func: (void (__cdecl *)())GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viNone__);
  }
  if ( (_S1_5 & 2) == 0 )
  {
    _S1_5 |= 2u;
    dword_103599DC = (int)&GFxVertexInterface_XY16i::`vftable';
    atexit(func: (void (__cdecl *)())GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY16i__);
  }
  if ( (_S1_5 & 4) == 0 )
  {
    _S1_5 |= 4u;
    dword_103599D8 = (int)&GFxVertexInterface_XY32f::`vftable';
    atexit(func: (void (__cdecl *)())GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY32f__);
  }
  if ( (_S1_5 & 8) == 0 )
  {
    _S1_5 |= 8u;
    dword_103599D4 = (int)&GFxVertexInterface_XY16iC32::`vftable';
    atexit(func: (void (__cdecl *)())GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY16iC32__);
  }
  if ( (_S1_5 & 0x10) == 0 )
  {
    _S1_5 |= 0x10u;
    dword_103599D0 = (int)&GFxVertexInterface_XY16iCF32::`vftable';
    atexit(func: (void (__cdecl *)())GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY16iCF32__);
  }
  switch ( a2 )
  {
    case Vertex_XY16i:
      result = (struct GFxVertexDesc *)&unk_10330728;
      break;
    case Vertex_XY32f:
      result = (struct GFxVertexDesc *)&unk_10330734;
      break;
    case Vertex_XY16iC32:
      result = (struct GFxVertexDesc *)&unk_10330740;
      break;
    case Vertex_XY16iCF32:
      result = (struct GFxVertexDesc *)&unk_1033074C;
      break;
    default:
      result = (struct GFxVertexDesc *)&unk_1033071C;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018B2F0
// Name: public: GFxVertexArray::GFxVertexArray(class GMemoryHeap __near *,enum GRenderer::VertexFormat,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxVertexArray *__thiscall GFxVertexArray::GFxVertexArray(
        GFxVertexArray *this,
        struct GMemoryHeap *a2,
        enum GRenderer::VertexFormat a3,
        unsigned int a4)
{
  GMemoryHeap *v4; // eax

  v4 = a2;
  if ( a2 == nullptr )
    v4 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
  *((_DWORD *)this + 4) = v4;
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = GFxVertexArray::GetFormatDesc(this, a2: a3);
  GFxVertexArray::Resize(this, a2: a4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1018B350
// Name: public: bool GFxVertexArray::SetFormat(enum GRenderer::VertexFormat)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxVertexArray::SetFormat(GFxVertexArray *this, enum GRenderer::VertexFormat a2)
{
  unsigned int v4; // edi
  struct GFxVertexDesc *FormatDesc; // eax

  if ( *(_DWORD *)this != 0 )
    return 0;
  v4 = *((_DWORD *)this + 1) * *(_DWORD *)(*((_DWORD *)this + 3) + 4);
  FormatDesc = GFxVertexArray::GetFormatDesc(this, a2);
  *((_DWORD *)this + 3) = FormatDesc;
  *((_DWORD *)this + 1) = v4 / *((_DWORD *)FormatDesc + 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1028CC60
// Name: _GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viNone__
// Source: json
//------------------------------------------------------------------------------
void GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viNone__()
{
  dword_103599E0 = (int)&GFxVertexInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CC70
// Name: _GFxVertexArray::AppendVertex_::_7_::_dynamic_atexit_destructor_for__viNone__
// Source: json
//------------------------------------------------------------------------------
void GFxVertexArray::AppendVertex_::_7_::_dynamic_atexit_destructor_for__viNone__()
{
  dword_103599C8 = (int)&GFxVertexInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CC80
// Name: _GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY16iCF32__
// Source: json
//------------------------------------------------------------------------------
void GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY16iCF32__()
{
  dword_103599D0 = (int)&GFxVertexInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CC90
// Name: _GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY16iC32__
// Source: json
//------------------------------------------------------------------------------
void GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY16iC32__()
{
  dword_103599D4 = (int)&GFxVertexInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CCA0
// Name: _GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY32f__
// Source: json
//------------------------------------------------------------------------------
void GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY32f__()
{
  dword_103599D8 = (int)&GFxVertexInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CCB0
// Name: _GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY16i__
// Source: json
//------------------------------------------------------------------------------
void GFxVertexArray::GetFormatDesc_::_2_::_dynamic_atexit_destructor_for__viXY16i__()
{
  dword_103599DC = (int)&GFxVertexInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CCC0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x1028CCD0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CD20
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1028CD60
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1028CD70
// Name: _DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x1028CD80
// Name: _DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x1028CD90
// Name: _DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

//------------------------------------------------------------------------------
// Address: 0x1028CDA0
// Name: _DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

//------------------------------------------------------------------------------
// Address: 0x1028CDB0
// Name: _DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x1028CDC0
// Name: _DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_4);
}

//------------------------------------------------------------------------------
// Address: 0x1028CDD0
// Name: _DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_5);
}

//------------------------------------------------------------------------------
// Address: 0x1028D530
// Name: GSTAT_GStatHeap_LocalFootprint$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge GSTAT_GStatHeap_LocalFootprint_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<of>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  if ( a2 )
    JUMPOUT(0x1028D4E8);
  *a3 -= a4;
  return GSTAT_GStatHeap_ChildFootprint_initializer_(this, a2: a5, a3: a6);
}

//------------------------------------------------------------------------------
// Address: 0x1028D534
// Name: GSTAT_GStatHeap_ChildFootprint$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatHeap_ChildFootprint_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<esi>,
        int a3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4)
{
  *(_BYTE *)(a2 - 1232072664) ^= 0x28u;
  JUMPOUT(0x1028D53B);
}

//------------------------------------------------------------------------------
// Address: 0x1028D53C
// Name: GSTAT_GStatHeap_LocalUsedSpace$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GSTAT_GStatHeap_LocalUsedSpace_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  JUMPOUT(0x1028D541);
}

//------------------------------------------------------------------------------
// Address: 0x1028D544
// Name: GSTAT_GStatHeap_Bookkeeping$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatHeap_Bookkeeping_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<esi>,
        int a3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4)
{
  *(_BYTE *)(a2 - 1227878360) = 0;
  JUMPOUT(0x1028D54B);
}

//------------------------------------------------------------------------------
// Address: 0x1028D54C
// Name: GSTAT_GStatHeap_Segments$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatHeap_Segments_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<zf>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  char *v6; // ecx

  v6 = (char *)this - 1;
  if ( a2 != 0 || v6 == nullptr )
  {
    *a3 -= a4;
    JUMPOUT(0x1028D550);
  }
  JUMPOUT(0x1028D504);
}

//------------------------------------------------------------------------------
// Address: 0x1028D554
// Name: GSTAT_GStatHeap_DynamicGranularity$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatHeap_DynamicGranularity_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<dh>,
        int a3@<edi>,
        int a4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a5)
{
  *(_BYTE *)(a3 - 1223684056) += a2;
  JUMPOUT(0x1028D55A);
}

//------------------------------------------------------------------------------
// Address: 0x1028D55C
// Name: GSTAT_GStatRender_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatRender_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<dh>,
        int a3@<edi>,
        int a4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a5)
{
  *(_BYTE *)(a3 - 1221586904) &= a2;
  JUMPOUT(0x1028D562);
}

//------------------------------------------------------------------------------
// Address: 0x1028D570
// Name: GSTAT_GStatRender_TextureUpload_Cnt$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge GSTAT_GStatRender_TextureUpload_Cnt_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<of>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  if ( a2 )
    JUMPOUT(0x1028D52B);
  *a3 -= a4;
  return GSTAT_GStatRender_TextureUpdate_Cnt_initializer_(this, a2: a5, a3: a6);
}

//------------------------------------------------------------------------------
// Address: 0x1028D574
// Name: GSTAT_GStatRender_TextureUpdate_Cnt$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatRender_TextureUpdate_Cnt_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<edi>,
        int a3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4)
{
  *(_BYTE *)(a2 - 1215295448) ^= 0x28u;
  JUMPOUT(0x1028D57B);
}

//------------------------------------------------------------------------------
// Address: 0x1028D57C
// Name: GSTAT_GStatRender_DP_Line_Cnt$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GSTAT_GStatRender_DP_Line_Cnt_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  JUMPOUT(0x1028D581);
}

//------------------------------------------------------------------------------
// Address: 0x1028D584
// Name: GSTAT_GStatRender_Triangle_Cnt$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatRender_Triangle_Cnt_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<edi>,
        int a3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4)
{
  *(_BYTE *)(a2 - 1211101144) = 0;
  JUMPOUT(0x1028D58B);
}

//------------------------------------------------------------------------------
// Address: 0x1028D58C
// Name: GSTAT_GStatRender_Mask_Cnt$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatRender_Mask_Cnt_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<zf>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  char *v6; // ecx

  v6 = (char *)this - 1;
  if ( a2 != 0 || v6 == nullptr )
  {
    *a3 -= a4;
    JUMPOUT(0x1028D590);
  }
  JUMPOUT(0x1028D545);
}

//------------------------------------------------------------------------------
// Address: 0x1028D594
// Name: GSTAT_GStatGroup_Default$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatGroup_Default_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<eax>,
        char a3@<bh>,
        int a4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a5)
{
  *(_BYTE *)(a2 - 1204809688) += a3;
  JUMPOUT(0x1028D59A);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5A4
// Name: GSTAT_GStat_Sound_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStat_Sound_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<eax>,
        int a3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4)
{
  *(char *)(a2 - 1192226776) >>= 7;
  JUMPOUT(0x1028D5AB);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5AC
// Name: GSTAT_GStat_Video_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStat_Video_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<bh>,
        int a3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4)
{
  *((_BYTE *)this - 1185935320) &= a2;
  JUMPOUT(0x1028D5B2);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5B4
// Name: GSTAT_GStat_DebugHUD_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GSTAT_GStat_DebugHUD_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  JUMPOUT(0x1028D5BB);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5BC
// Name: GSTAT_GStat_StatBag_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge GSTAT_GStat_StatBag_Mem_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<zf>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v6; // ecx

  v6 = (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)((char *)this - 1);
  if ( a2 == 0 && v6 != nullptr )
    JUMPOUT(0x1028D577);
  *a3 -= a4;
  return GStat_MemoryInterface_initializer_(this: v6, a2: a5, a3: a6);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5C0
// Name: GStat_MemoryInterface$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GStat_MemoryInterface_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<cf>,
        int a3@<edx>,
        char a4@<bh>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  *(_BYTE *)(a3 - 1172303832) += a4 + a2;
  JUMPOUT(0x1028D5C6);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5C8
// Name: GStat_CounterInterface$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GStat_CounterInterface_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<edx>,
        char a3@<bh>,
        int a4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a5)
{
  *(_BYTE *)(a2 - 1170206680) ^= a3;
  JUMPOUT(0x1028D5CE);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5D8
// Name: GSTAT_GFxStatMD_ShapeData_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GFxStatMD_ShapeData_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<of>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        char a5@<bh>,
        int a6,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a7)
{
  if ( a2 )
  {
    GSTAT_GStatGroup_Default_initializer_(this, a2: (int)a3, a3: a5, a4: a6, a5: a7);
  }
  else
  {
    *a3 -= a4;
    GSTAT_GFxStatMD_Tags_Mem_initializer_(this, a2: a6, a3: a7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028D5DC
// Name: GSTAT_GFxStatMD_Tags_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GSTAT_GFxStatMD_Tags_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  JUMPOUT(0x1028D5E3);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5E4
// Name: GSTAT_GFxStatMD_Images_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GSTAT_GFxStatMD_Images_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  JUMPOUT(0x1028D5E9);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5EC
// Name: GSTAT_GFxStatMD_ActionOps_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall GSTAT_GFxStatMD_ActionOps_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        int a3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4)
{
  *(char *)(a2 - 1160769496) >>= 7;
  JUMPOUT(0x1028D5F3);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5F4
// Name: GSTAT_GFxStatMD_Time$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge GSTAT_GFxStatMD_Time_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<zf>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v6; // ecx

  v6 = (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)((char *)this - 1);
  if ( a2 == 0 && v6 != nullptr )
    JUMPOUT(0x1028D5B0);
  *a3 -= a4;
  return GSTAT_GFxStatMD_Load_Tks_initializer_(this: v6, a2: a5, a3: a6);
}

//------------------------------------------------------------------------------
// Address: 0x1028D5F8
// Name: GSTAT_GFxStatMD_Load_Tks$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GSTAT_GFxStatMD_Load_Tks_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  __asm { lock mov edx, 0BB001028h }
  JUMPOUT(0x1028D5FE);
}

//------------------------------------------------------------------------------
// Address: 0x1028D600
// Name: GSTAT_GFxStatMV_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GFxStatMV_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<cf>,
        int a3@<ebx>,
        int a4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a5)
{
  *(_BYTE *)(a3 - 1155526616) += BYTE1(a3) + a2;
  JUMPOUT(0x1028D606);
}

//------------------------------------------------------------------------------
// Address: 0x1028D608
// Name: GSTAT_GFxStatMV_ActionScript_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GFxStatMV_ActionScript_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<ebx>,
        int a3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4)
{
  *(_BYTE *)(a2 - 1153429464) ^= BYTE1(a2);
  JUMPOUT(0x1028D60E);
}

//------------------------------------------------------------------------------
// Address: 0x1028D618
// Name: GSTAT_GFxStatIME_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge GSTAT_GFxStatIME_Mem_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<of>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  if ( a2 )
    JUMPOUT(0x1028D5D5);
  *a3 -= a4;
  return GSTAT_GFxStatFC_Mem_initializer_(this, a2: a5, a3: a6);
}

//------------------------------------------------------------------------------
// Address: 0x1028D61C
// Name: GSTAT_GFxStatFC_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GSTAT_GFxStatFC_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  JUMPOUT(0x1028D623);
}

//------------------------------------------------------------------------------
// Address: 0x1028D624
// Name: GSTAT_GFxStatFC_GlyphCache_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GSTAT_GFxStatFC_GlyphCache_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  JUMPOUT(0x1028D629);
}

//------------------------------------------------------------------------------
// Address: 0x1028D62C
// Name: GSTAT_GFxStatMV_Tks$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GFxStatMV_Tks_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<ebx>,
        int a3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4)
{
  *(char *)(a2 - 1143992280) >>= 7;
  JUMPOUT(0x1028D633);
}

//------------------------------------------------------------------------------
// Address: 0x1028D634
// Name: GSTAT_GFxStatMV_Action_Tks$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge GSTAT_GFxStatMV_Action_Tks_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<zf>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v6; // ecx

  v6 = (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)((char *)this - 1);
  if ( a2 == 0 && v6 != nullptr )
    JUMPOUT(0x1028D5F1);
  *a3 -= a4;
  return GSTAT_GFxStatMV_Timeline_Tks_initializer_(this: v6, a2: a5, a3: a6);
}

//------------------------------------------------------------------------------
// Address: 0x1028D638
// Name: GSTAT_GFxStatMV_Timeline_Tks$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GSTAT_GFxStatMV_Timeline_Tks_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  __asm { lock mov ebx, 0BC001028h }
  JUMPOUT(0x1028D63E);
}

//------------------------------------------------------------------------------
// Address: 0x1028D640
// Name: GSTAT_GFxStatMV_Mouse_Tks$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GFxStatMV_Mouse_Tks_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<cf>,
        int a3@<eax>,
        char a4@<bh>,
        int a5@<ebp>,
        int a6,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a7)
{
  *(_BYTE *)(a3 + a5 + 683417616) += a4 + a2;
  JUMPOUT(0x1028D647);
}

//------------------------------------------------------------------------------
// Address: 0x1028D648
// Name: GSTAT_GFxStatMV_GetVariable_Tks$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GFxStatMV_GetVariable_Tks_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<eax>,
        char a3@<bh>,
        int a4@<ebp>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  *(_BYTE *)(a2 + a4 + 683425808) ^= a3;
  JUMPOUT(0x1028D64F);
}

//------------------------------------------------------------------------------
// Address: 0x1028D658
// Name: GSTAT_GFxStatMV_Tessellate_Tks$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge GSTAT_GFxStatMV_Tessellate_Tks_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<of>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  if ( !a2 )
  {
    *a3 -= a4;
    JUMPOUT(0x1028D65C);
  }
  a2 = __OFSUB__(*a3, a4);
  *a3 -= a4;
  return GSTAT_GFxStatIME_Mem_initializer_(this, a2, a3, a4, a5, a6);
}

//------------------------------------------------------------------------------
// Address: 0x1028D660
// Name: GFxMovieDataDefFileKeyInterface_Instance$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDefFileKeyInterface_Instance_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  JUMPOUT(0x1028D666);
}

//------------------------------------------------------------------------------
// Address: 0x1028D668
// Name: static_inst$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge static_inst_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        _BYTE *a2@<eax>,
        char a3@<dl>,
        int a4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a5)
{
  LOBYTE(a2) = -68;
  *a2 -= a3;
  return Generator_1_initializer_(this, a2: a4, a3: a5);
}

//------------------------------------------------------------------------------
// Address: 0x1028D66C
// Name: Generator_1$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge Generator_1_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<eax>,
        int a3@<ebp>,
        int a4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a5)
{
  *(char *)(a2 + a3 + 683466768) >>= 7;
  return GFxPoint_NanParams_initializer_(this, a2: a4, a3: a5);
}

//------------------------------------------------------------------------------
// Address: 0x1028D674
// Name: GFxPoint_NanParams$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GFxPoint_NanParams_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  __asm { lock mov esp, 0BD201028h }
  JUMPOUT(0x1028D67A);
}

//------------------------------------------------------------------------------
// Address: 0x1028D680
// Name: static_inst_data$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall static_inst_data_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  JUMPOUT(0x1028D686);
}

//------------------------------------------------------------------------------
// Address: 0x1028D688
// Name: GFxSystemFontResourceKeyInterface_Instance$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge GFxSystemFontResourceKeyInterface_Instance_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        _BYTE *a2@<eax>,
        char a3@<dl>,
        int a4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a5)
{
  LOBYTE(a2) = -67;
  *a2 -= a3;
  return GFxImageFileKeyInterface_Instance_initializer_(this, a2: a4, a3: a5);
}

//------------------------------------------------------------------------------
// Address: 0x1028D68C
// Name: GFxImageFileKeyInterface_Instance$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GFxImageFileKeyInterface_Instance_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        int a2@<ebp>,
        int a3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4)
{
  *(char *)(a2 - 1110437848) >>= 7;
  JUMPOUT(0x1028D693);
}

//------------------------------------------------------------------------------
// Address: 0x1028D694
// Name: GSTAT_GStatRG_Vertices_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __userpurge GSTAT_GStatRG_Vertices_Mem_initializer_@<al>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<zf>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v6; // ecx

  v6 = (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)((char *)this - 1);
  if ( a2 == 0 && v6 != nullptr )
    JUMPOUT(0x1028D653);
  *a3 -= a4;
  return GSTAT_GStatRG_MeshFill_Mem_initializer_(this: v6, a2: a5, a3: a6);
}

//------------------------------------------------------------------------------
// Address: 0x1028D698
// Name: GSTAT_GStatRG_MeshFill_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GSTAT_GStatRG_MeshFill_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a3)
{
  __asm { lock mov ebp, 0BE001028h }
  JUMPOUT(0x1028D69E);
}

//------------------------------------------------------------------------------
// Address: 0x1028D6A0
// Name: GSTAT_GStatRG_Tessellator_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatRG_Tessellator_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<cf>,
        char a3@<bh>,
        int a4@<esi>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  *(_BYTE *)(a4 - 1105194968) += a3 + a2;
  JUMPOUT(0x1028D6A6);
}

//------------------------------------------------------------------------------
// Address: 0x1028D6A8
// Name: GSTAT_GStatRG_Stroker_Mem$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge GSTAT_GStatRG_Stroker_Mem_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<bh>,
        int a3@<esi>,
        int a4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a5)
{
  *(_BYTE *)(a3 - 1103097816) ^= a2;
  JUMPOUT(0x1028D6AE);
}
