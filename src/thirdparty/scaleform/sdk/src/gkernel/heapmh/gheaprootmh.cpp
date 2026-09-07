// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/heapmh/gheaprootmh.cpp
// Functions: 163
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\heapmh\gheaprootmh.h"

//------------------------------------------------------------------------------
// Address: 0x100D2770
// Name: void GHeapGetMagicHeaders(unsigned int,struct GHeapMagicHeadersInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapGetMagicHeaders(
        bool (__cdecl *pageStart)(const char *const *, const char *const *),
        unsigned int pageStarta,
        _DWORD *headers)
{
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // esi
  unsigned int v6; // edi

  v3 = (pageStarta + 4095) & 0xFFFFF000;
  v4 = (pageStarta + 15) & 0xFFFFFFF0;
  v5 = (pageStarta + 4096) & 0xFFFFFFF0;
  *headers = 0;
  headers[1] = 0;
  if ( v3 - v4 > 0x10 )
    *headers = v3 - 16;
  if ( v5 - v3 > 0x10 )
    headers[1] = v3;
  v6 = v3 - 80;
  if ( v3 - v4 <= v5 - v3 )
    v6 = v3 + 16;
  headers[2] = v6;
  headers[4] = v5;
  headers[3] = v4;
  headers[5] = v3;
  headers[6] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D27E0
// Name: public: void GHeapRootMH::FreeTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapRootMH::FreeTables(
        CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  _TRANSACTION_STATE *v2; // esi

  v2 = &GHeapGlobalPageTableMH;
  do
  {
    if ( *(_TRANSACTION_STATE **)v2 != &GHeapGlobalEmptyPageMH )
      (*(void (__thiscall **)(bool (__cdecl *)(const char *const *, const char *const *), _TRANSACTION_STATE, int, int))(*(_DWORD *)this->m_LessFunc.m_LessFunc + 16))(
        a1: this->m_LessFunc.m_LessFunc,
        a2: *v2,
        a3: 16 * (*((_DWORD *)v2 + 1) + 1),
        a4: 4);
    *v2 = (_TRANSACTION_STATE)&GHeapGlobalEmptyPageMH;
    *((_DWORD *)v2 + 1) = 0;
    v2 += 2;
  }
  while ( (int)v2 < (int)&GHeapGlobalEmptyPageMH );
}

//------------------------------------------------------------------------------
// Address: 0x100D2830
// Name: public: unsigned long GHeapRootMH::GetPageIndex(struct GHeapPageMH const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GHeapRootMH::GetPageIndex(
        CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        int page)
{
  unsigned int v2; // ecx
  int v3; // edx
  unsigned int v4; // eax

  v2 = *((_DWORD *)this + 9);
  v3 = 0;
  if ( v2 == 0 )
    return -1;
  while ( 1 )
  {
    v4 = (page - *((_DWORD *)&GHeapGlobalPageTableMH + 2 * v3)) >> 4;
    if ( v4 <= dword_1035941C[2 * v3] )
      break;
    if ( ++v3 >= v2 )
      return -1;
  }
  return v3 | (v4 << 7);
}

//------------------------------------------------------------------------------
// Address: 0x100D2870
// Name: public: struct GHeapPageMH __near * GHeapRootMH::ResolveAddress(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
__int32 __thiscall GHeapRootMH::ResolveAddress(
        CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        int addr)
{
  __int32 result; // eax

  if ( *(_WORD *)(addr & 0xFFFFF000) != 24512
    || (result = *((_DWORD *)&GHeapGlobalPageTableMH + 2 * (*(_DWORD *)((addr & 0xFFFFF000) + 4) & 0x7F))
               + 16
               * (*(&GHeapGlobalPageTableMH + 2 * (*(_DWORD *)((addr & 0xFFFFF000) + 4) & 0x7F) + 1)
                & (*(_DWORD *)((addr & 0xFFFFF000) + 4) >> 7)),
        (unsigned int)(addr - *(_DWORD *)(result + 12)) >= 0x1000) )
  {
    if ( *(_WORD *)((addr & 0xFFFFF000) + 0xFF0) != 24512 )
      return 0;
    result = *((_DWORD *)&GHeapGlobalPageTableMH + 2 * (*(_DWORD *)((addr & 0xFFFFF000) + 0xFF4) & 0x7F))
           + 16
           * (dword_1035941C[2 * (*(_DWORD *)((addr & 0xFFFFF000) + 0xFF4) & 0x7F)]
            & (*(_DWORD *)((addr & 0xFFFFF000) + 0xFF4) >> 7));
    if ( (unsigned int)(addr - *(_DWORD *)(result + 12)) >= 0x1000 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D2900
// Name: public: class GMemoryHeapMH __near * GHeapRootMH::CreateHeap(char const __near *,class GMemoryHeapMH __near *,struct GMemoryHeap::HeapDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapRootMH::CreateHeap(
        CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const char *name,
        CShaderSystem::ShaderDLLInfo_t *a3,
        unsigned int *desc)
{
  unsigned int v4; // kr00_4
  CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *v5; // eax
  CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *v6; // esi
  CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *v7; // eax
  CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *v8; // ebx
  GHeapAllocEngineMH *v9; // eax
  int v10; // eax
  unsigned __int8 *heapBuf; // [esp+8h] [ebp-8h]

  v4 = strlen(name);
  v5 = (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)(*(int (__thiscall **)(bool (__cdecl *)(const char *const *, const char *const *), unsigned int, int))(*(_DWORD *)this->m_LessFunc.m_LessFunc + 12))(a1: this->m_LessFunc.m_LessFunc, a2: (v4 + 332) & 0xFFFFFFF0, a3: 4);
  v6 = v5;
  heapBuf = (unsigned __int8 *)v5;
  if ( v5 != nullptr )
  {
    v7 = GMemoryHeapMH::GMemoryHeapMH(this: v5);
    v8 = v7;
    if ( v6 == (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)-112 )
      v9 = nullptr;
    else
      v9 = GHeapAllocEngineMH::GHeapAllocEngineMH(
             this: (GHeapAllocEngineMH *)&v6[5].m_Size,
             minAlignSize: (IShaderDLLVerification *)this->m_LessFunc.m_LessFunc,
             a3: (struct GMemoryHeapMH *)v7,
             a4: desc[1],
             limit: desc[5]);
    v8->m_Size = (v4 + 332) & 0xFFFFFFF0;
    v8->m_pElements = (CShaderSystem::ShaderDLLInfo_t *)1;
    v8[1].m_Memory.m_nAllocationCount = 0;
    qmemcpy(&v8[1].m_Memory.m_nGrowSize, desc, 0x20u);
    v8[3].m_Memory.m_pMemory = a3;
    v8[3].m_Memory.m_nAllocationCount = (int)(heapBuf + 316);
    LOBYTE(v8[5].m_Memory.m_pMemory) = (*(_BYTE *)desc & 1) == 0;
    BYTE1(v8[5].m_Memory.m_pMemory) = (*desc & 0x10) == 0;
    v8[5].m_Memory.m_nAllocationCount = (int)v9;
    if ( heapBuf == (unsigned __int8 *)-284 )
      v10 = 0;
    else
      v10 = GHeapDebugStorageMH::GHeapDebugStorageMH();
    v8[5].m_Memory.m_nGrowSize = v10;
    strcpy((char *)v8[3].m_Memory.m_nAllocationCount, name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2A10
// Name: public: void GHeapRootMH::DestroyHeap(class GMemoryHeapMH __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapRootMH::DestroyHeap(GHeapRootMH *this, struct GMemoryHeapMH *a2)
{
  int v2; // ebx

  v2 = *((_DWORD *)a2 + 3);
  GHeapDebugStorageMH::FreeAll(this: *((GHeapDebugStorageMH **)a2 + 27));
  CDummyMaterialSystem::EndBatch();
  (**(void (__thiscall ***)(struct GMemoryHeapMH *, _DWORD))a2)(a1: a2, a2: 0);
  (*(void (__thiscall **)(_DWORD, struct GMemoryHeapMH *, int, int))(**(_DWORD **)this + 16))(
    a1: *(_DWORD *)this,
    a2,
    a3: v2,
    a4: 4);
}

//------------------------------------------------------------------------------
// Address: 0x100D2A50
// Name: public: GHeapRootMH::GHeapRootMH(class GSysAlloc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapRootMH::GHeapRootMH(
        CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        CUtlMap<char const *,IShader *,unsigned short>::CKeyLess *sysAlloc)
{
  int *v3; // eax

  this->m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))sysAlloc;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Elements, spinCount: 0);
  *((_DWORD *)this + 7) = this + 1;
  *((_DWORD *)this + 8) = this + 1;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  dword_10359820 = 0;
  dword_10359824 = 0;
  v3 = dword_1035941C;
  do
  {
    *(v3 - 1) = (int)&GHeapGlobalEmptyPageMH;
    *v3 = 0;
    v3 += 2;
  }
  while ( (int)v3 < (int)&dword_1035981C );
  GHeapGlobalRootMH = this;
}

//------------------------------------------------------------------------------
// Address: 0x100D2AB0
// Name: public: GHeapRootMH::~GHeapRootMH(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapRootMH::~GHeapRootMH(
        CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  GHeapRootMH::FreeTables(this);
  GHeapGlobalRootMH = nullptr;
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Elements);
}

//------------------------------------------------------------------------------
// Address: 0x100D2AD0
// Name: private: bool GHeapRootMH::allocPagePool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapRootMH::allocPagePool(
        CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned int v2; // ecx
  int v3; // esi
  _DWORD *v4; // eax

  v2 = *((_DWORD *)this + 9);
  if ( v2 < 0x80 )
  {
    v3 = 128 << (v2 >> 4);
    v4 = (_DWORD *)(*(int (__thiscall **)(bool (__cdecl *)(const char *const *, const char *const *), int, int))(*(_DWORD *)this->m_LessFunc.m_LessFunc + 12))(
                     a1: this->m_LessFunc.m_LessFunc,
                     a2: 16 * v3,
                     a3: 4);
    if ( v4 != nullptr )
    {
      *((_DWORD *)&GHeapGlobalPageTableMH + 2 * *((_DWORD *)this + 9)) = v4;
      for ( dword_1035941C[2 * *((_DWORD *)this + 9)] = v3 - 1; v3 != 0; --v3 )
      {
        v4[2] = 0;
        v4[3] = 0;
        v4[1] = *((_DWORD *)this + 8);
        *v4 = this + 1;
        **((_DWORD **)this + 8) = v4;
        *((_DWORD *)this + 8) = v4;
        v4 += 4;
      }
      ++*((_DWORD *)this + 9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2B60
// Name: public: struct GHeapPageMH __near * GHeapRootMH::AllocPage(class GMemoryHeapMH __near *)
// Source: json
//------------------------------------------------------------------------------
const CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *__thiscall GHeapRootMH::AllocPage(
        CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *result)
{
  char v3; // al
  _DWORD *v5; // esi
  int v6; // eax
  _WORD *v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  _WORD *v11; // eax
  unsigned int v12; // edx

  if ( *((CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > **)this
       + 8) == this + 1 )
  {
    GHeapRootMH::allocPagePool(this);
    if ( v3 == 0 )
      return nullptr;
  }
  v5 = *((_DWORD **)this + 8);
  v6 = (*(int (__thiscall **)(bool (__cdecl *)(const char *const *, const char *const *), int, int))(*(_DWORD *)this->m_LessFunc.m_LessFunc + 12))(
         a1: this->m_LessFunc.m_LessFunc,
         a2: 4096,
         a3: 4);
  v7 = nullptr;
  v5[3] = v6;
  if ( v6 != 0 )
  {
    *(_DWORD *)(*v5 + 4) = v5[1];
    *(_DWORD *)v5[1] = *v5;
    v8 = v5[3];
    v5[2] = result;
    v9 = v8 + 15;
    v10 = v8 + 4096;
    v11 = (_WORD *)((v8 + 4095) & 0xFFFFF000);
    v12 = v10 & 0xFFFFFFF0;
    if ( (unsigned int)v11 - (v9 & 0xFFFFFFF0) > 0x10 )
      v7 = v11 - 8;
    if ( v12 - (unsigned int)v11 <= 0x10 )
      v11 = nullptr;
    if ( v7 != nullptr )
      *v7 = 24512;
    if ( v11 != nullptr )
      *v11 = 24512;
    return (const CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)v5;
  }
  else
  {
    v5[2] = 0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2C20
// Name: public: void GHeapRootMH::FreePage(struct GHeapPageMH __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlMap<char const *,IShader *,unsigned short>::Node_t *__thiscall GHeapRootMH::FreePage(
        _DWORD *this,
        CUtlMap<char const *,IShader *,unsigned short>::Node_t *result)
{
  IShader *elem; // eax
  unsigned int v4; // ecx
  unsigned int v5; // edx
  _WORD *v6; // eax
  unsigned int v7; // edx
  _WORD *v8; // ebx
  IShader *v9; // eax

  elem = result[1].elem;
  v4 = (unsigned int)&elem[3].__vftable + 3;
  v5 = (unsigned int)&elem[1024];
  v6 = (_WORD *)(((unsigned int)&elem[1023].__vftable + 3) & 0xFFFFF000);
  v7 = v5 & 0xFFFFFFF0;
  v8 = v6 - 8;
  if ( (unsigned int)v6 - (v4 & 0xFFFFFFF0) <= 0x10 )
    v8 = nullptr;
  if ( v7 - (unsigned int)v6 <= 0x10 )
    v6 = nullptr;
  if ( v8 != nullptr )
    *v8 = 0;
  if ( v6 != nullptr )
    *v6 = 0;
  v9 = result[1].elem;
  result[1].elem = nullptr;
  result[1].key = nullptr;
  (*(void (__thiscall **)(_DWORD, IShader *, int, int))(*(_DWORD *)*this + 16))(a1: *this, a2: v9, a3: 4096, a4: 4);
  result->elem = (IShader *)*(this + 8);
  result->key = (const char *)(this + 7);
  *(_DWORD *)*(this + 8) = result;
  *(this + 8) = result;
  return (CUtlMap<char const *,IShader *,unsigned short>::Node_t *)(this + 7);
}

//------------------------------------------------------------------------------
// Address: 0x10215B53
// Name: protected: long D3DXShader::CShaderProgram::ResolveAddress(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ResolveAddress(D3DXShader::CShaderProgram *this)
{
  _DWORD *v2; // ecx
  unsigned int v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  _DWORD *v6; // ecx
  int v7; // edx
  unsigned int v8; // esi
  unsigned int v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // eax
  int v12; // ecx
  int v13; // eax
  bool v14; // cf
  int v15; // eax
  int v16; // ecx
  unsigned int v17; // edi
  D3DXShader::CArgument *v18; // esi
  int result; // eax
  unsigned int v20; // edi
  int v21; // eax
  int v22; // eax
  D3DXShader::CArgument *v23; // ecx
  int v24; // eax
  D3DXShader::CInstruction *v25; // ecx
  unsigned __int8 *v26; // eax
  void **v27; // edi
  int v28; // esi
  D3DXShader::CInstruction *v29; // ecx
  unsigned int v30; // eax
  unsigned int v31; // ecx
  struct D3DXShader::CInstruction *v32; // eax
  struct D3DXShader::CArgument *v33; // [esp+4h] [ebp-58h]
  _DWORD v34[4]; // [esp+14h] [ebp-48h] BYREF
  _DWORD v35[4]; // [esp+24h] [ebp-38h] BYREF
  unsigned int v36; // [esp+34h] [ebp-28h]
  D3DXShader::CArgument *v37; // [esp+38h] [ebp-24h]
  unsigned int v38; // [esp+3Ch] [ebp-20h]
  struct D3DXShader::CArgument *v39; // [esp+40h] [ebp-1Ch]
  unsigned int v40; // [esp+44h] [ebp-18h]
  unsigned int v41; // [esp+48h] [ebp-14h]
  D3DXShader::CInstruction *v42; // [esp+4Ch] [ebp-10h]
  unsigned int v43; // [esp+50h] [ebp-Ch]
  D3DXShader::CInstruction *v44; // [esp+54h] [ebp-8h]
  unsigned int v45; // [esp+58h] [ebp-4h]

  v2 = *((_DWORD **)this + 64);
  v3 = *v2 & 0xFFFFF;
  v43 = v3;
  if ( v3 == 0 )
    return 1;
  v4 = v2[1];
  if ( v4 == 0 )
    return 1;
  if ( v2[3] == 0 )
    return 1;
  v45 = 0;
  v38 = v4 / v3;
  if ( v4 / v3 == 0 )
    return 1;
  v5 = *((_DWORD *)this + 5);
  v6 = (_DWORD *)v2[2];
  v40 = v38;
  do
  {
    v7 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * *v6) + 8);
    if ( v7 != -1 )
    {
      v3 = v43;
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 4 * v7) + 4)) + 4) & 4) == 0 )
      {
        v8 = v45++;
        v34[v8] = v7;
      }
    }
    v6 += v3;
    --v40;
  }
  while ( v40 != 0 );
  v9 = 0;
  if ( v45 == 0 )
    return 1;
  do
  {
    if ( v45 == 1 )
      v10 = 3;
    else
      v10 = v9;
    v11 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 35), a3: 0, a4: v10, a5: 0.0);
    v35[v9] = v11;
    if ( v11 == -1 )
      return -2147024882;
    v12 = *((_DWORD *)this + 5);
    v13 = *(_DWORD *)(v12 + 4 * v11);
    *(_DWORD *)(v13 + 20) = *(_DWORD *)(*(_DWORD *)(v12 + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)) + 20);
    v14 = ++v9 < v45;
    *(_DWORD *)(v13 + 24) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                  + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16))
                                      + 24);
  }
  while ( v14 );
  v45 = 0;
  v40 = 0;
  v42 = nullptr;
  do
  {
    v15 = *((_DWORD *)this + 5);
    v16 = *(_DWORD *)(*(_DWORD *)(v15 + 4 * *(_DWORD *)((char *)v42 + *(_DWORD *)(*((_DWORD *)this + 64) + 8))) + 8);
    if ( v16 != -1
      && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(*(_DWORD *)(v15 + 4 * v16) + 4)) + 4) & 4) == 0 )
    {
      v41 = 0;
      if ( v3 != 0 )
      {
        v44 = v42;
        while ( 1 )
        {
          v39 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5)
                                                 + 4
                                                 * *(_DWORD *)((char *)v44 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)));
          v17 = D3DXShader::CBaseProgram::AddArgument(this, a2: 0, a3: 0, a4: 0, a5: 0.0);
          v36 = v17;
          if ( v17 == -1 )
            return -2147024882;
          v18 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v17);
          result = D3DXShader::CArgument::Initialize(this: v18, a2: v39);
          if ( result < 0 )
            return result;
          if ( *((_DWORD *)v18 + 14) != -1 )
          {
            v20 = D3DXShader::CBaseProgram::AddArgument(this, a2: 0, a3: 0, a4: 0, a5: 0.0);
            if ( v20 == -1 )
              return -2147024882;
            v21 = *((_DWORD *)this + 5);
            v33 = *(struct D3DXShader::CArgument **)(v21 + 4 * *((_DWORD *)v39 + 14));
            v37 = *(D3DXShader::CArgument **)(v21 + 4 * v20);
            D3DXShader::CArgument::Initialize(this: v37, a2: v33);
            v22 = v35[v45];
            v23 = v37;
            *((_DWORD *)v18 + 14) = v20;
            v17 = v36;
            *((_DWORD *)v23 + 2) = v22;
          }
          v24 = v35[v45];
          v25 = v44;
          ++v41;
          v44 = (D3DXShader::CInstruction *)((char *)v44 + 4);
          *((_DWORD *)v18 + 2) = v24;
          *(_DWORD *)((char *)v25 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)) = v17;
          if ( v41 >= v43 )
          {
            v3 = v43;
            break;
          }
        }
      }
      ++v45;
    }
    ++v40;
    v42 = (D3DXShader::CInstruction *)((char *)v42 + 4 * v3);
  }
  while ( v40 < v38 );
  v26 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v26 != nullptr )
  {
    v27 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v26);
    v42 = (D3DXShader::CInstruction *)v27;
  }
  else
  {
    v42 = nullptr;
    v27 = nullptr;
  }
  if ( v27 == nullptr )
    return -2147024882;
  v28 = D3DXShader::CInstruction::Initialize(
          this: (D3DXShader::CInstruction *)v27,
          a2: v45 & 0xFFFFF | 0x10000000,
          a3: v45,
          a4: v45,
          a5: 0);
  v29 = (D3DXShader::CInstruction *)v27;
  if ( v28 < 0 )
  {
LABEL_40:
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v29, a2: 1);
    return v28;
  }
  v28 = D3DXShader::CInstruction::Instance(
          this: (D3DXShader::CInstruction *)v27,
          a2: *((struct D3DXShader::CInstruction **)this + 64));
  if ( v28 < 0 )
  {
    v29 = (D3DXShader::CInstruction *)v27;
    goto LABEL_40;
  }
  v30 = 4 * v45;
  qmemcpy(v27[4], v35, 4 * v45);
  v31 = v30;
  v32 = v42;
  qmemcpy(*((void **)v42 + 2), v34, v31);
  v28 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v32);
  if ( v28 < 0 )
  {
    v29 = v42;
    goto LABEL_40;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10215E59
// Name: protected: long D3DXShader::CShaderProgram::MatchPOW(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchPOW(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *v1; // edx
  int v2; // eax
  int result; // eax
  int v4; // eax
  int v5; // ebx
  unsigned int v6; // ecx
  int v7; // esi
  unsigned int v8; // ecx
  unsigned int *v9; // edx
  int v10; // eax
  int v11; // esi
  struct D3DXShader::CInstruction *v12; // edi
  unsigned int v13; // edi
  unsigned int *v14; // ecx
  unsigned int v15; // edx
  int v16; // edi
  struct D3DXShader::CInstruction *v17; // edx
  unsigned int v18; // ebx
  int v19; // esi
  _DWORD *v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // eax
  int v23; // eax
  struct D3DXShader::CInstruction **v24; // ecx
  struct D3DXShader::CInstruction *v25; // ecx
  int v26; // edi
  int v27; // esi
  _DWORD *v28; // edx
  int m; // eax
  int v30; // eax
  unsigned int n; // edx
  bool v32; // zf
  unsigned int v33; // eax
  unsigned int v34; // edi
  int v35; // ebx
  struct D3DXShader::CInstruction *v36; // ecx
  int v37; // edx
  _DWORD *v38; // ecx
  unsigned int ii; // eax
  unsigned int v40; // ecx
  unsigned __int8 *v41; // eax
  int v42; // ebx
  int v43; // esi
  D3DXShader::CInstruction *v44; // ecx
  D3DXShader::CShaderProgram *v45; // edx
  unsigned int v46[80]; // [esp+8h] [ebp-274h] BYREF
  _DWORD v47[40]; // [esp+148h] [ebp-134h]
  unsigned int v48[4]; // [esp+1E8h] [ebp-94h] BYREF
  struct D3DXShader::CInstruction *v49[16]; // [esp+1F8h] [ebp-84h] BYREF
  unsigned int v50[4]; // [esp+238h] [ebp-44h] BYREF
  unsigned int k; // [esp+248h] [ebp-34h]
  int v52; // [esp+24Ch] [ebp-30h]
  struct D3DXShader::CInstruction **v53; // [esp+250h] [ebp-2Ch]
  int v54; // [esp+254h] [ebp-28h]
  int v55; // [esp+258h] [ebp-24h]
  struct D3DXShader::CInstruction *v56; // [esp+25Ch] [ebp-20h]
  int v57; // [esp+260h] [ebp-1Ch]
  unsigned int j; // [esp+264h] [ebp-18h]
  unsigned int v59; // [esp+268h] [ebp-14h]
  unsigned int v60; // [esp+26Ch] [ebp-10h] BYREF
  D3DXShader::CShaderProgram *v61; // [esp+270h] [ebp-Ch]
  int matched; // [esp+274h] [ebp-8h]
  unsigned int i; // [esp+278h] [ebp-4h]

  v50[0] = 0;
  v1 = *((struct D3DXShader::CInstruction **)this + 64);
  v2 = *(_DWORD *)v1 & 0xFFFFF;
  v61 = this;
  v50[1] = 1;
  v50[2] = 2;
  v50[3] = 3;
  v56 = v1;
  if ( v2 != 1 )
    return 1;
  if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                             + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v1 + 4)) + 4))
                 + 4)
      & 0x20) != 0 )
    return 1;
  v4 = *(_DWORD *)v1;
  v59 = *(_DWORD *)v1 & 0xFFFFF;
  if ( v59 > 1 || (v4 & 0xFFF00000) != 0x10500000 )
    return 1;
  v55 = 0;
  while ( 2 )
  {
    v57 = 0;
    while ( 2 )
    {
      v5 = 0;
      memset(v46, 255, sizeof(v46));
      v60 = 0;
      matched = 0;
      i = 0;
      while ( 1 )
      {
        if ( v57 != 0 )
          v6 = 1 - i;
        else
          v6 = i;
        v7 = *((_DWORD *)v56 + 2);
        v8 = dword_102BE16C[v6];
        v9 = (unsigned int *)(v7 + 4 * v5);
        if ( v8 >= 0x10 )
        {
          v13 = 0;
          v14 = &v46[4 * v8 - 24];
          do
          {
            v15 = v50[v13];
            if ( v15 >= v59 )
              *v14 = -1;
            else
              *v14 = *(_DWORD *)(v7 + 4 * (v5 + v15));
            ++v13;
            ++v14;
          }
          while ( v13 < 4 );
          goto LABEL_22;
        }
        v10 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v61 + 5) + 4 * *v9) + 72);
        if ( v10 == -1 )
          break;
        v11 = 32 * v8;
        v12 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)v61 + 6) + 4 * v10);
        if ( D3DXShader::CShaderProgram::ComputeSwizzle(
               this: v61,
               a2: v12,
               a3: v9,
               a4: v59,
               a5: v50,
               a6: v48,
               a7: dword_102BE178[8 * v8],
               a8: 0) != 0 )
          break;
        matched = D3DXShader::CShaderProgram::MatchComplexTree(
                    this: v61,
                    a2: v12,
                    a3: (const struct D3DXShader::D3DX_MATCHENTRY *)((char *)&unk_102BE160 + v11),
                    a4: v49,
                    a5: &v60,
                    a6: v46,
                    a7: v48,
                    a8: 1u,
                    a9: 0);
LABEL_22:
        if ( matched != 1 )
        {
          ++i;
          v5 += v59;
          if ( i == 0 )
            continue;
        }
        goto LABEL_26;
      }
      matched = 1;
LABEL_26:
      if ( (unsigned int)dword_102BE16C[v57 != 0] >= 0x10 )
      {
        for ( i = 0; i < v60; ++i )
        {
          v16 = 0;
          if ( v59 != 0 )
          {
            v17 = v49[i];
            v18 = *((_DWORD *)v17 + 3);
            while ( 1 )
            {
              j = 0;
              if ( v18 != 0 )
                break;
LABEL_34:
              if ( ++v16 >= v59 )
                goto LABEL_37;
            }
            v19 = *(_DWORD *)(*((_DWORD *)v56 + 2) + 4 * v16);
            v20 = *((_DWORD **)v17 + 4);
            while ( v19 != *v20 )
            {
              ++j;
              ++v20;
              if ( j >= v18 )
                goto LABEL_34;
            }
            matched = 1;
          }
LABEL_37:
          ;
        }
      }
      if ( matched == 0 )
      {
        if ( v55 != 0 )
          goto LABEL_81;
        v21 = 0;
        for ( j = 0; j < v60; ++j )
        {
          v22 = *((_DWORD *)v49[v21] + 3);
          i = 0;
          for ( k = v22; i < k; ++i )
          {
            v23 = *((_DWORD *)v61 + 3);
            if ( v23 != 0 )
            {
              v24 = *((struct D3DXShader::CInstruction ***)v61 + 6);
              v53 = v24;
              v52 = v23;
              do
              {
                v25 = *v24;
                if ( v25 != nullptr && *(_DWORD *)v25 != 0 )
                {
                  v26 = *((_DWORD *)v25 + 1);
                  v54 = 0;
                  if ( v26 != 0 )
                  {
                    v27 = *(_DWORD *)(*((_DWORD *)v49[j] + 4) + 4 * i);
                    v28 = *((_DWORD **)v25 + 2);
                    for ( m = v26; m != 0; --m )
                    {
                      if ( *v28 == v27 || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v61 + 5) + 4 * *v28) + 56) == v27 )
                        v54 = 1;
                      ++v28;
                    }
                  }
                  if ( v25 == v56 )
                    v30 = 0;
                  else
                    v30 = v54;
                  if ( v30 != 0 )
                  {
                    for ( n = 0; n < v60; ++n )
                    {
                      if ( v25 == v49[n] )
                        v30 = 0;
                    }
                    if ( v30 != 0 )
                      matched = 1;
                  }
                }
                v24 = v53 + 1;
                v32 = v52-- == 1;
                ++v53;
              }
              while ( !v32 );
            }
          }
          v21 = j + 1;
        }
        for ( i = 0; i < 0x28; ++i )
        {
          v33 = v46[i + 40];
          if ( v33 != -1 )
          {
            v34 = 0;
            if ( v60 != 0 )
            {
              v35 = *(_DWORD *)(*((_DWORD *)v61 + 5) + 4 * v33);
              do
              {
                v36 = v49[v34];
                v37 = *((_DWORD *)v36 + 3);
                if ( v37 != 0 )
                {
                  v38 = *((_DWORD **)v36 + 4);
                  do
                  {
                    if ( v33 == *v38 || *(_DWORD *)(v35 + 56) == *v38 )
                      matched = 1;
                    ++v38;
                    --v37;
                  }
                  while ( v37 != 0 );
                }
                ++v34;
              }
              while ( v34 < v60 );
            }
          }
        }
        if ( matched == 0 )
        {
LABEL_81:
          v49[v60] = v56;
          for ( ii = 0; ii < 40; ++ii )
          {
            v40 = v46[ii + 40];
            if ( v40 == -1 )
            {
              v40 = v46[ii];
              if ( v40 == -1 )
                continue;
            }
            v47[ii] = v40;
          }
          matched = 0;
LABEL_87:
          result = matched;
          if ( matched == 0 )
          {
            v41 = D3DXShader::CInstruction::operator new(a1: 0x74u);
            if ( v41 != nullptr )
              v42 = D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v41);
            else
              v42 = 0;
            if ( v42 != 0 )
            {
              v43 = D3DXShader::CInstruction::Initialize(
                      this: (D3DXShader::CInstruction *)v42,
                      a2: 0x70D00001u,
                      a3: 2u,
                      a4: 1u,
                      a5: 0);
              v44 = (D3DXShader::CInstruction *)v42;
              if ( v43 >= 0 )
              {
                v43 = D3DXShader::CInstruction::Instance(
                        this: (D3DXShader::CInstruction *)v42,
                        a2: *((struct D3DXShader::CInstruction **)v61 + 64));
                if ( v43 >= 0 )
                {
                  v45 = v61;
                  qmemcpy(
                    *(void **)(v42 + 16),
                    *(const void **)(*((_DWORD *)v61 + 64) + 16),
                    4 * *(_DWORD *)(*((_DWORD *)v61 + 64) + 12));
                  **(_DWORD **)(v42 + 8) = v47[4];
                  *(_DWORD *)(*(_DWORD *)(v42 + 8) + 4) = v47[0];
                  v43 = D3DXShader::CInstruction::Initialize(
                          this: *((D3DXShader::CInstruction **)v45 + 64),
                          a2: (struct D3DXShader::CInstruction *)v42);
                }
                v44 = (D3DXShader::CInstruction *)v42;
              }
              D3DXShader::CInstruction::`scalar deleting destructor'(this: v44, a2: 1);
              return v43;
            }
            else
            {
              return -2147024882;
            }
          }
          return result;
        }
      }
      if ( ++v57 == 0 )
        continue;
      break;
    }
    if ( ++v55 != 0 )
      goto LABEL_87;
    continue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102162E2
// Name: protected: long D3DXShader::CShaderProgram::RemapSamplerMove(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::RemapSamplerMove(D3DXShader::CShaderProgram *this)
{
  int v1; // eax
  unsigned int v2; // esi
  int v4; // eax
  int v5; // edx
  int v6; // ebx
  int v7; // eax
  unsigned int i; // [esp+4h] [ebp-4h]

  v1 = *((_DWORD *)this + 64);
  v2 = *(_DWORD *)v1 & 0xFFFFF;
  if ( *(char *)(*(_DWORD *)(*((_DWORD *)this + 4)
                           + 4
                           * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                   + 4
                                                   * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                                           + 4 * **(_DWORD **)(v1 + 8))
                                                               + 48))
                                       + 4))
               + 4) >= 0 )
    return 1;
  for ( i = 0; i < v2; *(_DWORD *)(v7 + 48) = *(_DWORD *)(v6 + 48) )
  {
    v4 = *((_DWORD *)this + 64);
    v5 = *((_DWORD *)this + 5);
    v6 = *(_DWORD *)(v5 + 4 * *(_DWORD *)(4 * i + *(_DWORD *)(v4 + 8)));
    v7 = *(_DWORD *)(v5 + 4 * *(_DWORD *)(4 * i++ + *(_DWORD *)(v4 + 16)));
  }
  **((_DWORD **)this + 64) = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10216365
// Name: protected: long D3DXShader::CShaderProgram::MatchMinMax(class D3DXShader::CInstruction __near * __near *,class D3DXShader::CInstruction __near * __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchMinMax(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction **a2,
        struct D3DXShader::CInstruction **a3,
        unsigned int *a4)
{
  int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // esi
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  int v14; // eax
  unsigned __int8 *v15; // eax
  D3DXShader::CInstruction *v16; // eax
  int v17; // eax
  unsigned __int8 *v18; // eax
  D3DXShader::CInstruction *v19; // eax
  int v20; // esi
  const void *v21; // esi
  int v22; // edi
  unsigned int v23; // edx
  int v24; // ecx
  int v25; // edi
  unsigned int v26; // eax
  int v27; // edx
  int v28; // edx
  int v29; // eax
  int v30; // edx
  int v31; // edi
  int v32; // eax
  unsigned __int8 *v33; // eax
  D3DXShader::CInstruction *v34; // ecx
  unsigned int v35; // ecx
  const void *v36; // esi
  D3DXShader::CInstruction *v37; // eax
  void *v38; // edi
  unsigned int *v39; // edi
  unsigned int v40; // edx
  _DWORD *v41; // edx
  int v42; // ecx
  int v43; // edi
  int v44; // esi
  int v45; // ecx
  int v46; // edx
  bool v47; // zf
  unsigned int v48; // eax
  struct D3DXShader::CInstruction *v49[16]; // [esp+Ch] [ebp-124h] BYREF
  unsigned int v50[4]; // [esp+4Ch] [ebp-E4h] BYREF
  unsigned int v51[36]; // [esp+5Ch] [ebp-D4h] BYREF
  unsigned int v52[4]; // [esp+ECh] [ebp-44h] BYREF
  unsigned int v53; // [esp+FCh] [ebp-34h] BYREF
  int v54; // [esp+100h] [ebp-30h]
  unsigned int v55; // [esp+104h] [ebp-2Ch]
  int v56; // [esp+108h] [ebp-28h]
  unsigned int v57; // [esp+10Ch] [ebp-24h]
  unsigned int v58; // [esp+110h] [ebp-20h]
  int v59; // [esp+114h] [ebp-1Ch]
  int v60; // [esp+118h] [ebp-18h]
  int v61; // [esp+11Ch] [ebp-14h]
  unsigned int v62; // [esp+120h] [ebp-10h]
  D3DXShader::CInstruction *v63; // [esp+124h] [ebp-Ch]
  unsigned int v64; // [esp+128h] [ebp-8h]
  int matched; // [esp+12Ch] [ebp-4h]

  v5 = **((_DWORD **)this + 64);
  v6 = v5 & 0xFFF00000;
  v7 = v5 & 0xFFFFF;
  v63 = nullptr;
  v53 = 0;
  v52[0] = 0;
  v52[1] = 1;
  v52[2] = 2;
  v52[3] = 3;
  if ( v6 != 805306368 )
    return 1;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v56 = 0;
  v64 = 0;
  if ( v7 != 0 )
  {
    v9 = *(_DWORD *)(*((_DWORD *)this + 64) + 8);
    v62 = 4 * v7;
    v61 = 4 * v7;
    v59 = 8 * v7;
    matched = 8 * v7;
    do
    {
      v10 = *((_DWORD *)this + 5);
      v11 = *(_DWORD *)(v10 + 4 * *(_DWORD *)(v9 + v61));
      v12 = *(_DWORD *)(v10 + 4 * *(_DWORD *)(v9 + matched));
      v13 = *(_DWORD *)(v12 + 4);
      v54 = v12;
      v14 = *((_DWORD *)this + 4);
      v55 = *(_DWORD *)(v14 + 4 * v13);
      if ( (*(_BYTE *)(*(_DWORD *)(v14 + 4 * *(_DWORD *)(v11 + 4)) + 5) & 1) != 0
        && *(double *)(v11 + 32) == 0.0
        && *(_DWORD *)(v11 + 8) == -1
        && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + matched) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8)
                                                                                       + 4 * v64) )
      {
        v60 = 1;
      }
      else
      {
        v58 = 1;
      }
      if ( (*(_BYTE *)(v55 + 5) & 1) != 0
        && *(double *)(v54 + 32) == 0.0
        && *(_DWORD *)(v54 + 8) == -1
        && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + v61) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64)
                                                                                               + 8)
                                                                                   + 4 * v64) )
      {
        v57 = 1;
      }
      else
      {
        v56 = 1;
      }
      ++v64;
      matched += 4;
      v61 += 4;
    }
    while ( v64 < v7 );
    if ( v60 != 0 && v58 == 0 )
    {
      v15 = D3DXShader::CInstruction::operator new(a1: 0x74u);
      if ( v15 != nullptr )
        v16 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v15);
      else
        v16 = nullptr;
      v63 = v16;
      if ( v16 != nullptr )
      {
        v17 = D3DXShader::CInstruction::Initialize(this: v16, a2: v7 & 0xFFFFF | 0x70B00000, a3: 2 * v7, a4: v7, a5: 0);
        goto LABEL_35;
      }
      return -2147024882;
    }
    if ( v57 != 0 && v56 == 0 )
    {
      if ( a2 != nullptr )
        return 1;
      v18 = D3DXShader::CInstruction::operator new(a1: 0x74u);
      if ( v18 != nullptr )
        v19 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v18);
      else
        v19 = nullptr;
      v63 = v19;
      if ( v19 != nullptr )
      {
        v17 = D3DXShader::CInstruction::Initialize(this: v19, a2: v7 & 0xFFFFF | 0x70C00000, a3: 2 * v7, a4: v7, a5: 0);
LABEL_35:
        matched = v17;
        if ( v17 < 0 )
          goto LABEL_76;
        matched = D3DXShader::CInstruction::Instance(this: v63, a2: *((struct D3DXShader::CInstruction **)this + 64));
        if ( matched < 0 )
          goto LABEL_76;
        qmemcpy(*((void **)v63 + 4), *(const void **)(*((_DWORD *)this + 64) + 16), v62);
        qmemcpy(*((void **)v63 + 2), *(const void **)(*((_DWORD *)this + 64) + 8), v62);
        v20 = *(_DWORD *)(*((_DWORD *)this + 64) + 8);
        if ( v60 != 0 )
          v21 = (const void *)(v62 + v20);
        else
          v21 = (const void *)(v59 + v20);
        qmemcpy((void *)(v62 + *((_DWORD *)v63 + 2)), v21, v62);
        goto LABEL_41;
      }
      return -2147024882;
    }
  }
  matched = D3DXShader::CShaderProgram::MatchComplexTree(
              this,
              a2: *((struct D3DXShader::CInstruction **)this + 64),
              a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD620,
              a4: v49,
              a5: &v53,
              a6: v50,
              a7: v52,
              a8: v7,
              a9: a2 == nullptr);
  if ( matched != 0 )
    return matched;
  v22 = 0;
  v60 = 0;
  v64 = 0;
LABEL_44:
  matched = 0;
  while ( 1 )
  {
    v23 = 0;
    v55 = 0;
    if ( v7 != 0 )
    {
      v24 = *((_DWORD *)this + 5);
      do
      {
        v58 = v50[4 * v64 + v23];
        v61 = v51[v23 - 4 * v64];
        v25 = *(_DWORD *)(*(_DWORD *)(v24 + 4 * v61) + 4);
        v26 = v51[matched + 4 + v23];
        v57 = v51[v23 - matched + 8];
        v62 = *(_DWORD *)(v24 + 4 * v57);
        v27 = *((_DWORD *)this + 4);
        v59 = *(_DWORD *)(v27 + 4 * v25);
        v54 = *(_DWORD *)(v27 + 4 * *(_DWORD *)(v62 + 4));
        v56 = *(_DWORD *)(*(_DWORD *)(v24 + 4 * v58) + 56);
        if ( (v56 == v26 || (v28 = *(_DWORD *)(*(_DWORD *)(v24 + 4 * v26) + 56)) == v58 || v56 != -1 && v56 == v28)
          && (*(_DWORD *)(*(_DWORD *)(v24 + 4 * v58) + 60) ^ 0x80000) == *(_DWORD *)(*(_DWORD *)(v24 + 4 * v26) + 60)
          && v61 == v57 )
        {
          v22 = 1;
        }
        else
        {
          if ( v58 == v26 )
          {
            if ( ((v29 = *(_DWORD *)(v24 + 4 * v61), (v30 = *(_DWORD *)(v29 + 56)) == v57)
               || (v31 = *(_DWORD *)(v62 + 56)) == v61
               || v30 != -1 && v30 == v31)
              && (*(_DWORD *)(v29 + 60) ^ 0x80000) == *(_DWORD *)(v62 + 60)
              || (*(_DWORD *)(v59 + 4) & 0x100) != 0
              && (*(_DWORD *)(v54 + 4) & 0x100) != 0
              && *(double *)(v62 + 32) == -*(double *)(v29 + 32) )
            {
              v32 = 1;
              v22 = 1;
              goto LABEL_66;
            }
          }
          v22 = 0;
        }
        v32 = 0;
LABEL_66:
        if ( v55 != 0 )
        {
          if ( v60 != v32 )
            v22 = 0;
        }
        else
        {
          v60 = v32;
        }
        if ( v22 == 0 )
          goto LABEL_73;
        v23 = v55 + 1;
        v55 = v23;
      }
      while ( v23 < v7 );
    }
    if ( v22 != 0 )
      break;
LABEL_73:
    matched += 4;
    if ( (unsigned int)matched >= 8 )
    {
      if ( ++v64 >= 2 )
        goto LABEL_75;
      goto LABEL_44;
    }
  }
  v33 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v33 != nullptr )
    v34 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v33);
  else
    v34 = nullptr;
  v63 = v34;
  if ( v34 == nullptr )
    return -2147024882;
  if ( v60 == 0 )
  {
    if ( v64 == 0 )
      goto LABEL_99;
LABEL_101:
    if ( v64 != 1 )
      goto LABEL_88;
LABEL_87:
    matched = D3DXShader::CInstruction::Initialize(this: v63, a2: v7 & 0xFFFFF | 0x70C00000, a3: 2 * v7, a4: v7, a5: 0);
    if ( matched >= 0 )
      goto LABEL_88;
    goto LABEL_76;
  }
  if ( v64 == 1 )
  {
LABEL_99:
    matched = D3DXShader::CInstruction::Initialize(this: v34, a2: v7 & 0xFFFFF | 0x70B00000, a3: 2 * v7, a4: v7, a5: 0);
    if ( matched < 0 )
      goto LABEL_76;
    if ( v60 == 0 )
      goto LABEL_101;
  }
  if ( v64 == 0 )
    goto LABEL_87;
LABEL_88:
  matched = D3DXShader::CInstruction::Instance(this: v63, a2: *((struct D3DXShader::CInstruction **)this + 64));
  if ( matched < 0 )
    goto LABEL_76;
  v35 = v7;
  v36 = *(const void **)(*((_DWORD *)this + 64) + 16);
  v37 = v63;
  v38 = *((void **)v63 + 4);
  v62 = 4 * v35;
  qmemcpy(v38, v36, 4 * v35);
  v39 = *((unsigned int **)v37 + 2);
  v59 = 16 * v64;
  v40 = v62;
  qmemcpy(v39, &v50[4 * v64], v62);
  qmemcpy((void *)(v40 + *((_DWORD *)v37 + 2)), (char *)v51 - v59, v40);
  v41 = *((_DWORD **)v37 + 2);
  v42 = *((_DWORD *)this + 5);
  v43 = *(_DWORD *)(v42 + 4 * *(_DWORD *)((char *)v41 + v62));
  v44 = *(_DWORD *)(v42 + 4 * *v41);
  v45 = *(_DWORD *)(v42 + 4 * **((_DWORD **)v37 + 4));
  v46 = *(_DWORD *)(v45 + 4);
  v47 = v46 == *(_DWORD *)(v44 + 4);
  v59 = v43;
  if ( !v47 )
  {
LABEL_92:
    if ( v46 == *(_DWORD *)(v43 + 4) && *(_DWORD *)(v45 + 12) == *(_DWORD *)(v43 + 12) )
      goto LABEL_75;
    if ( a2 != nullptr )
    {
      *a2 = v37;
      v48 = v53;
      if ( v53 != 0 )
        qmemcpy(a3, v49, 4 * v53);
      *a4 = v48;
      return matched;
    }
LABEL_41:
    matched = D3DXShader::CInstruction::Initialize(
                this: *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)this + 63)),
                a2: v63);
    goto LABEL_76;
  }
  if ( *(_DWORD *)(v45 + 12) != *(_DWORD *)(v44 + 12) )
  {
    v43 = v59;
    goto LABEL_92;
  }
LABEL_75:
  matched = 1;
LABEL_76:
  if ( v63 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v63, a2: 1);
  return matched;
}

//------------------------------------------------------------------------------
// Address: 0x10216961
// Name: protected: long D3DXShader::CShaderProgram::MatchMinMax2(class D3DXShader::CInstruction __near * __near *,class D3DXShader::CInstruction __near * __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchMinMax2(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction **a2,
        struct D3DXShader::CInstruction **a3,
        unsigned int *a4)
{
  struct D3DXShader::CInstruction *v5; // eax
  unsigned int v6; // ebx
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  bool v11; // zf
  int v12; // edi
  int v13; // edx
  int v14; // edi
  unsigned __int8 *v15; // eax
  int v16; // eax
  const void *v17; // esi
  D3DXShader::CInstruction *v18; // eax
  void *v19; // edi
  unsigned int v20; // edx
  int v21; // esi
  const void *v22; // esi
  int *v23; // esi
  int v24; // ecx
  int v25; // edi
  int v26; // esi
  int v27; // edi
  int v28; // ecx
  int v29; // edx
  unsigned int v30; // eax
  struct D3DXShader::CInstruction *v31; // [esp-20h] [ebp-160h]
  struct D3DXShader::CInstruction *v32[16]; // [esp+Ch] [ebp-134h] BYREF
  unsigned int v33[4]; // [esp+4Ch] [ebp-F4h] BYREF
  char v34; // [esp+5Ch] [ebp-E4h] BYREF
  char v35; // [esp+6Ch] [ebp-D4h] BYREF
  char v36; // [esp+7Ch] [ebp-C4h] BYREF
  char v37; // [esp+8Ch] [ebp-B4h] BYREF
  unsigned int v38[4]; // [esp+ECh] [ebp-54h] BYREF
  int v39; // [esp+FCh] [ebp-44h]
  int v40; // [esp+100h] [ebp-40h]
  char *v41; // [esp+104h] [ebp-3Ch]
  char *v42; // [esp+108h] [ebp-38h]
  char *v43; // [esp+10Ch] [ebp-34h]
  char *v44; // [esp+110h] [ebp-30h]
  char *v45; // [esp+114h] [ebp-2Ch]
  unsigned int v46; // [esp+118h] [ebp-28h] BYREF
  char *v47; // [esp+11Ch] [ebp-24h]
  int v48; // [esp+120h] [ebp-20h]
  char *v49; // [esp+124h] [ebp-1Ch]
  char *v50; // [esp+128h] [ebp-18h]
  unsigned int v51; // [esp+12Ch] [ebp-14h]
  D3DXShader::CShaderProgram *v52; // [esp+130h] [ebp-10h]
  unsigned int v53; // [esp+134h] [ebp-Ch]
  unsigned int v54; // [esp+138h] [ebp-8h]
  D3DXShader::CInstruction *v55; // [esp+13Ch] [ebp-4h]

  v5 = *((struct D3DXShader::CInstruction **)this + 64);
  v6 = *(_DWORD *)v5 & 0xFFFFF;
  v46 = 0;
  v38[0] = 0;
  v55 = nullptr;
  v48 = 0;
  v52 = this;
  v38[1] = 1;
  v38[2] = 2;
  v38[3] = 3;
  if ( D3DXShader::CShaderProgram::MatchComplexTree(
         this,
         a2: v5,
         a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD680,
         a4: v32,
         a5: &v46,
         a6: v33,
         a7: v38,
         a8: v6,
         a9: a2 == nullptr) != 0 )
  {
    v31 = *((struct D3DXShader::CInstruction **)this + 64);
    v48 = 1;
    result = D3DXShader::CShaderProgram::MatchComplexTree(
               this,
               a2: v31,
               a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD700,
               a4: v32,
               a5: &v46,
               a6: v33,
               a7: v38,
               a8: v6,
               a9: a2 == nullptr);
    if ( result != 0 )
      return result;
  }
  v54 = 0;
  v42 = &v34;
  v41 = &v35;
LABEL_4:
  v51 = 0;
  v43 = &v36;
  v47 = &v37;
  while ( 1 )
  {
    v53 = 0;
    if ( v6 != 0 )
    {
      v8 = *((_DWORD *)this + 5);
      v44 = v41;
      v49 = v47;
      v50 = v43;
      v45 = v42;
      do
      {
        v9 = *(_DWORD *)(v8 + 4 * v33[v53]);
        v10 = *(_DWORD *)(v8 + 4 * *(_DWORD *)v45);
        v11 = *(_DWORD *)(v10 + 8) == -1;
        v12 = *(_DWORD *)(v8 + 4 * *(_DWORD *)v50);
        v39 = v9;
        v40 = v12;
        if ( !v11 )
          break;
        if ( *(_DWORD *)(v9 + 8) != -1 )
          break;
        if ( *(_DWORD *)(v12 + 8) != -1 )
          break;
        v13 = *((_DWORD *)this + 4);
        if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v10 + 4)) + 5) & 1) == 0 )
          break;
        if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v40 + 4)) + 5) & 1) == 0 )
          break;
        if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v39 + 4)) + 5) & 1) == 0 )
          break;
        if ( fabs(*(double *)(v40 + 32) - *(double *)(v10 + 32) - *(double *)(v39 + 32)) > 0.000009999999747378752 )
          break;
        if ( *(_DWORD *)v44 != *(_DWORD *)v49 )
          break;
        ++v53;
        v45 += 4;
        v50 += 4;
        v49 += 4;
        v44 += 4;
      }
      while ( v53 < v6 );
    }
    if ( v53 == v6 )
      break;
    ++v51;
    v47 -= 16;
    v43 += 16;
    if ( v51 >= 2 )
    {
      ++v54;
      v41 -= 16;
      v42 += 16;
      if ( v54 < 2 )
        goto LABEL_4;
      goto LABEL_19;
    }
  }
  v15 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v15 != nullptr )
    v55 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v15);
  else
    v55 = nullptr;
  if ( v55 == nullptr )
    return -2147024882;
  if ( v48 != 0 )
  {
    if ( a2 != nullptr )
      goto LABEL_19;
    v16 = D3DXShader::CInstruction::Initialize(this: v55, a2: v6 & 0xFFFFF | 0x70C00000, a3: 2 * v6, a4: v6, a5: 0);
  }
  else
  {
    v16 = D3DXShader::CInstruction::Initialize(this: v55, a2: v6 & 0xFFFFF | 0x70B00000, a3: 2 * v6, a4: v6, a5: 0);
  }
  v14 = v16;
  if ( v16 < 0 )
    goto LABEL_20;
  v14 = D3DXShader::CInstruction::Instance(this: v55, a2: *((struct D3DXShader::CInstruction **)this + 64));
  if ( v14 < 0 )
    goto LABEL_20;
  v17 = *(const void **)(*((_DWORD *)this + 64) + 16);
  v18 = v55;
  v19 = *((void **)v55 + 4);
  v54 = 4 * v6;
  v20 = 4 * v6;
  qmemcpy(v19, v17, 4 * ((4 * v6) >> 2));
  qmemcpy(*((void **)v18 + 2), v33, 4 * ((4 * v6) >> 2));
  v21 = *(_DWORD *)(*((_DWORD *)v52 + 64) + 8);
  if ( v48 != 0 )
    v22 = (const void *)(v20 + v21);
  else
    v22 = (const void *)(v21 + 8 * v6);
  qmemcpy((void *)(4 * v6 + *((_DWORD *)v18 + 2)), v22, v20);
  v23 = *((int **)v18 + 2);
  v24 = *((_DWORD *)v52 + 5);
  v25 = *v23;
  v26 = *(_DWORD *)(v24 + 4 * v23[v6]);
  v27 = *(_DWORD *)(v24 + 4 * v25);
  v28 = *(_DWORD *)(v24 + 4 * **((_DWORD **)v18 + 4));
  v29 = *(_DWORD *)(v28 + 4);
  if ( v29 == *(_DWORD *)(v27 + 4) && *(_DWORD *)(v28 + 12) == *(_DWORD *)(v27 + 12)
    || v29 == *(_DWORD *)(v26 + 4) && *(_DWORD *)(v28 + 12) == *(_DWORD *)(v26 + 12) )
  {
LABEL_19:
    v14 = 1;
    goto LABEL_20;
  }
  if ( a2 != nullptr )
  {
    v55 = nullptr;
    *a2 = v18;
    v30 = v46;
    if ( v46 != 0 )
      qmemcpy(a3, v32, 4 * v46);
    *a4 = v30;
  }
  else
  {
    D3DXShader::CInstruction::Initialize(
      this: *(D3DXShader::CInstruction **)(*((_DWORD *)v52 + 6) + 4 * *((_DWORD *)v52 + 63)),
      a2: v18);
  }
  v14 = 0;
LABEL_20:
  if ( v55 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v55, a2: 1);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10216CC0
// Name: protected: long D3DXShader::CShaderProgram::MatchSatModifier(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchSatModifier(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *v1; // ebx
  int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // ecx
  int v5; // esi
  unsigned int v6; // ecx
  unsigned int *v7; // edx
  int v8; // eax
  int v9; // esi
  struct D3DXShader::CInstruction *v10; // edi
  unsigned int v11; // eax
  unsigned int *v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ecx
  int v15; // esi
  struct D3DXShader::CInstruction *v16; // edx
  unsigned int v17; // edi
  int v18; // eax
  _DWORD *v19; // ecx
  unsigned int v20; // eax
  D3DXShader::CInstruction *v21; // eax
  struct D3DXShader::CInstruction *v22; // ecx
  unsigned int v23; // edi
  int v24; // esi
  _DWORD *v25; // edx
  unsigned int jj; // eax
  unsigned int v27; // esi
  unsigned int v28; // edi
  struct D3DXShader::CInstruction *v29; // ecx
  D3DXShader::CInstruction *v30; // eax
  _DWORD *v31; // ecx
  unsigned int v32; // eax
  unsigned int mm; // eax
  unsigned int v34; // ecx
  int v35; // eax
  struct D3DXShader::CInstruction *v36; // eax
  int v37; // ebx
  unsigned int v38; // ecx
  int v39; // esi
  unsigned int v40; // ecx
  unsigned int *v41; // edx
  int v42; // eax
  int v43; // esi
  struct D3DXShader::CInstruction *v44; // edi
  unsigned int v45; // edi
  unsigned int *v46; // ecx
  unsigned int v47; // edx
  unsigned int v48; // ecx
  int v49; // edi
  struct D3DXShader::CInstruction *v50; // edx
  unsigned int v51; // ebx
  int v52; // esi
  _DWORD *v53; // ecx
  unsigned int v54; // eax
  unsigned int v55; // eax
  unsigned int v56; // eax
  struct D3DXShader::CInstruction **v57; // ecx
  struct D3DXShader::CInstruction *v58; // ecx
  int v59; // edi
  int v60; // esi
  _DWORD *v61; // edx
  int nn; // eax
  D3DXShader::CInstruction *v63; // eax
  unsigned int i1; // edx
  unsigned int v65; // eax
  unsigned int v66; // edi
  int v67; // ebx
  struct D3DXShader::CInstruction *v68; // ecx
  int v69; // edx
  _DWORD *v70; // ecx
  struct D3DXShader::CInstruction *v71; // edx
  struct D3DXShader::CInstruction *v72; // eax
  unsigned int i2; // eax
  unsigned int v74; // ecx
  _DWORD *v75; // edi
  int v76; // ecx
  int v77; // edx
  _DWORD *v78; // esi
  int v79; // eax
  struct D3DXShader::CInstruction **v80; // ebx
  unsigned int v81; // esi
  int v82; // ecx
  int v83; // edx
  int v84; // eax
  unsigned int v85; // edx
  int v86; // esi
  unsigned int v87; // edi
  int v88; // eax
  unsigned int v89; // ecx
  int *v90; // eax
  int v91; // ecx
  int v92; // eax
  int v93; // ebx
  unsigned int v94; // ecx
  int v95; // esi
  unsigned int v96; // ecx
  unsigned int *v97; // edx
  int v98; // eax
  int v99; // esi
  struct D3DXShader::CInstruction *v100; // edi
  unsigned int v101; // edi
  unsigned int *v102; // ecx
  unsigned int v103; // edx
  unsigned int v104; // ecx
  int v105; // edi
  struct D3DXShader::CInstruction *v106; // edx
  unsigned int v107; // ebx
  int v108; // esi
  _DWORD *v109; // ecx
  unsigned int v110; // eax
  unsigned int v111; // eax
  unsigned int v112; // eax
  struct D3DXShader::CInstruction **v113; // ecx
  struct D3DXShader::CInstruction *v114; // ecx
  int v115; // edi
  int v116; // esi
  _DWORD *v117; // edx
  int i6; // eax
  D3DXShader::CInstruction *v119; // eax
  unsigned int i7; // edx
  unsigned int v121; // eax
  unsigned int v122; // edi
  int v123; // ebx
  struct D3DXShader::CInstruction *v124; // ecx
  int v125; // edx
  _DWORD *v126; // ecx
  unsigned int v127; // edx
  unsigned int v128; // eax
  unsigned int i8; // eax
  unsigned int v130; // ecx
  int v131; // esi
  int v132; // eax
  int v133; // ebx
  unsigned int v134; // ecx
  int v135; // esi
  unsigned int v136; // ecx
  unsigned int *v137; // edx
  int v138; // eax
  int v139; // esi
  struct D3DXShader::CInstruction *v140; // edi
  unsigned int v141; // edi
  unsigned int *v142; // ecx
  unsigned int v143; // edx
  unsigned int v144; // ecx
  int v145; // edi
  struct D3DXShader::CInstruction *v146; // edx
  unsigned int v147; // ebx
  int v148; // esi
  _DWORD *v149; // ecx
  unsigned int v150; // eax
  unsigned int v151; // eax
  unsigned int v152; // eax
  struct D3DXShader::CInstruction **v153; // ecx
  struct D3DXShader::CInstruction *v154; // ecx
  int v155; // edi
  int v156; // esi
  _DWORD *v157; // edx
  int i9; // eax
  D3DXShader::CInstruction *v159; // eax
  unsigned int i10; // edx
  unsigned int v161; // eax
  unsigned int v162; // edi
  int v163; // ebx
  struct D3DXShader::CInstruction *v164; // ecx
  int v165; // edx
  _DWORD *v166; // ecx
  struct D3DXShader::CInstruction *v167; // edx
  struct D3DXShader::CInstruction *v168; // eax
  unsigned int i11; // eax
  unsigned int v170; // ecx
  int v171; // ecx
  int v172; // esi
  struct D3DXShader::CInstruction *v173; // edi
  struct D3DXShader::CInstruction *v174; // ecx
  struct D3DXShader::CInstruction *v175; // edx
  int v176; // ecx
  int v177; // eax
  int v178; // edx
  int v179; // ecx
  unsigned int v180; // esi
  unsigned int i12; // eax
  int v182; // eax
  D3DXShader::CShaderProgram *v183; // edi
  struct D3DXShader::CInstruction *v184; // edx
  struct D3DXShader::CInstruction *v185; // edx
  int v186; // ebx
  unsigned int v187; // ecx
  int v188; // esi
  unsigned int v189; // ecx
  unsigned int *v190; // edx
  int v191; // eax
  int v192; // esi
  struct D3DXShader::CInstruction *v193; // edi
  unsigned int v194; // edi
  unsigned int *v195; // ecx
  unsigned int v196; // edx
  unsigned int v197; // ecx
  int v198; // edi
  struct D3DXShader::CInstruction *v199; // edx
  unsigned int v200; // ebx
  int v201; // esi
  _DWORD *v202; // ecx
  unsigned int v203; // eax
  unsigned int v204; // eax
  unsigned int v205; // eax
  D3DXShader::CInstruction *v206; // ecx
  struct D3DXShader::CInstruction *v207; // ecx
  int v208; // edi
  int v209; // esi
  _DWORD *v210; // edx
  int i17; // eax
  unsigned int v212; // eax
  unsigned int i18; // edx
  unsigned int v214; // eax
  unsigned int v215; // edi
  int v216; // ebx
  struct D3DXShader::CInstruction *v217; // ecx
  int v218; // edx
  _DWORD *v219; // ecx
  struct D3DXShader::CInstruction *v220; // edx
  struct D3DXShader::CInstruction *v221; // eax
  unsigned int i19; // eax
  unsigned int v223; // ecx
  unsigned int v224; // eax
  struct D3DXShader::CInstruction **v225; // eax
  struct D3DXShader::CInstruction *v226; // esi
  struct D3DXShader::CInstruction *v227; // edi
  int v228; // eax
  int v229; // ecx
  int v230; // edx
  int v231; // eax
  unsigned int v232; // ebx
  int v233; // ebx
  int v234; // esi
  D3DXShader::CInstruction *v235; // eax
  D3DXShader::CInstruction *v236; // eax
  int result; // eax
  int v238; // ecx
  int v239; // eax
  int v240; // edi
  int v241; // edx
  unsigned int v242; // eax
  int v243; // ecx
  unsigned int v244; // edi
  unsigned int i22; // edx
  int v246; // eax
  int v247; // eax
  int v248; // edx
  int v249; // esi
  unsigned int v250; // edi
  int v251; // ecx
  unsigned int v252; // eax
  bool v253; // zf
  unsigned int v254; // eax
  int v255; // ecx
  int v256; // esi
  _DWORD *v257; // ecx
  unsigned int i20; // ebx
  int v259; // eax
  unsigned int i21; // edx
  unsigned int v261; // edx
  unsigned int v262; // eax
  unsigned int v263; // eax
  _DWORD *v264; // eax
  unsigned int v265; // esi
  unsigned int v266; // edx
  int v267; // edi
  _DWORD *v268; // ecx
  unsigned int v269; // edx
  unsigned int v270; // edi
  unsigned int v271; // ebx
  int v272; // eax
  unsigned int v273; // eax
  D3DXShader::CInstruction *v274; // eax
  struct D3DXShader::CInstruction *v275; // eax
  unsigned int v276; // ecx
  bool v277; // zf
  unsigned int v278; // ecx
  int v279; // edx
  int *v280; // eax
  int v281; // ecx
  int v282; // ebx
  unsigned int i13; // esi
  int v284; // edi
  unsigned __int8 *v285; // eax
  void **v286; // ebx
  D3DXShader::CInstruction *v287; // ecx
  unsigned int v288; // eax
  unsigned int v289; // ecx
  D3DXShader::CShaderProgram *v290; // eax
  unsigned int i16; // edx
  int v292; // ecx
  unsigned int v293; // ecx
  struct D3DXShader::CInstruction *v294; // edx
  bool v295; // cf
  _DWORD *v296; // esi
  D3DXShader::CInstruction *v297; // ecx
  unsigned int v298; // eax
  D3DXShader::CShaderProgram *v299; // edx
  int v300; // eax
  char *v301; // esi
  unsigned int v302; // edi
  _DWORD *v303; // esi
  unsigned int v304; // ebx
  int v305; // ecx
  unsigned int i15; // eax
  unsigned int v307[84]; // [esp+Ch] [ebp-2CCh] BYREF
  _DWORD v308[4]; // [esp+15Ch] [ebp-17Ch] BYREF
  struct D3DXShader::CInstruction *v309[32]; // [esp+16Ch] [ebp-16Ch] BYREF
  struct D3DXShader::CInstruction *v310[16]; // [esp+1ECh] [ebp-ECh] BYREF
  struct D3DXShader::CInstruction *v311[16]; // [esp+22Ch] [ebp-ACh] BYREF
  unsigned int v312[4]; // [esp+26Ch] [ebp-6Ch] BYREF
  unsigned int v313[4]; // [esp+27Ch] [ebp-5Ch] BYREF
  unsigned int i5; // [esp+28Ch] [ebp-4Ch]
  int v315; // [esp+290h] [ebp-48h]
  unsigned int v316; // [esp+294h] [ebp-44h]
  unsigned int v317; // [esp+298h] [ebp-40h] BYREF
  unsigned int v318; // [esp+29Ch] [ebp-3Ch]
  unsigned int m; // [esp+2A0h] [ebp-38h]
  unsigned int kk; // [esp+2A4h] [ebp-34h]
  D3DXShader::CInstruction *n; // [esp+2A8h] [ebp-30h]
  unsigned int v322; // [esp+2ACh] [ebp-2Ch]
  unsigned int i; // [esp+2B0h] [ebp-28h]
  unsigned int k; // [esp+2B4h] [ebp-24h]
  unsigned int ii; // [esp+2B8h] [ebp-20h]
  unsigned int v326; // [esp+2BCh] [ebp-1Ch] BYREF
  unsigned int i4; // [esp+2C0h] [ebp-18h]
  D3DXShader::CShaderProgram *v328; // [esp+2C4h] [ebp-14h]
  int matched; // [esp+2C8h] [ebp-10h]
  unsigned int j; // [esp+2CCh] [ebp-Ch]
  struct D3DXShader::CInstruction *i14; // [esp+2D0h] [ebp-8h] BYREF
  unsigned int i3; // [esp+2D4h] [ebp-4h]

  v1 = *((struct D3DXShader::CInstruction **)this + 64);
  v2 = *(_DWORD *)v1;
  v328 = this;
  v3 = *(_DWORD *)v1 & 0xFFFFF;
  i14 = (struct D3DXShader::CInstruction *)(v2 & 0xFFFFF);
  v322 = v3;
  i4 = 0;
  v316 = 0;
  v317 = 0;
  v313[0] = 0;
  v313[1] = 1;
  v313[2] = 2;
  v313[3] = 3;
  v315 = 0;
  if ( (v2 & 0xFFFFFu) > v3 || (v2 & 0xFFF00000) != 0x20000000 )
    goto LABEL_88;
  for ( i = 0; i == 0; ++i )
  {
    for ( j = 0; j < 2; ++j )
    {
      memset(v307, 255, 320);
      v326 = 0;
      matched = 0;
      v318 = 0;
      k = 0;
      while ( 1 )
      {
        if ( j != 0 )
          v4 = 1 - v318;
        else
          v4 = v318;
        v5 = *((_DWORD *)v1 + 2);
        v6 = dword_102BD5CC[v4];
        v7 = (unsigned int *)(v5 + 4 * k);
        if ( v6 >= 0x10 )
        {
          v11 = 0;
          v12 = &v307[4 * v6 - 24];
          do
          {
            v13 = v313[v11];
            if ( v13 >= (unsigned int)i14 )
              *v12 = -1;
            else
              *v12 = *(_DWORD *)(v5 + 4 * (k + v13));
            ++v11;
            ++v12;
          }
          while ( v11 < 4 );
          goto LABEL_18;
        }
        v8 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *v7) + 72);
        if ( v8 == -1 )
          break;
        v9 = 32 * v6;
        v10 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)v328 + 6) + 4 * v8);
        if ( D3DXShader::CShaderProgram::ComputeSwizzle(
               this: v328,
               a2: v10,
               a3: v7,
               a4: (unsigned int)i14,
               a5: v313,
               a6: v312,
               a7: dword_102BD5D8[8 * v6],
               a8: 0) != 0 )
          break;
        matched = D3DXShader::CShaderProgram::MatchComplexTree(
                    this: v328,
                    a2: v10,
                    a3: (const struct D3DXShader::D3DX_MATCHENTRY *)((char *)&unk_102BD5C0 + v9),
                    a4: v311,
                    a5: &v326,
                    a6: v307,
                    a7: v312,
                    a8: v322,
                    a9: 0);
LABEL_18:
        if ( matched != 1 )
        {
          ++v318;
          k += (unsigned int)i14;
          if ( v318 < 2 )
            continue;
        }
        goto LABEL_22;
      }
      matched = 1;
LABEL_22:
      v318 = 0;
      kk = 0;
      do
      {
        if ( j != 0 )
          v14 = 1 - v318;
        else
          v14 = v318;
        if ( (unsigned int)dword_102BD5CC[v14] >= 0x10 )
        {
          for ( k = 0; k < v326; ++k )
          {
            v15 = 0;
            if ( i14 != nullptr )
            {
              v16 = v311[k];
              v17 = *((_DWORD *)v16 + 3);
              while ( 1 )
              {
                i3 = 0;
                if ( v17 != 0 )
                  break;
LABEL_34:
                if ( ++v15 >= (unsigned int)i14 )
                  goto LABEL_37;
              }
              v18 = *(_DWORD *)(*((_DWORD *)v1 + 2) + 4 * (v15 + kk));
              v19 = *((_DWORD **)v16 + 4);
              while ( v18 != *v19 )
              {
                ++i3;
                v17 = *((_DWORD *)v16 + 3);
                ++v19;
                if ( i3 >= v17 )
                  goto LABEL_34;
              }
              matched = 1;
            }
LABEL_37:
            ;
          }
        }
        ++v318;
        kk += (unsigned int)i14;
      }
      while ( v318 < 2 );
      if ( matched == 0 )
      {
        if ( i != 0 )
          goto LABEL_81;
        for ( k = 0; k < v326; ++k )
        {
          v20 = *((_DWORD *)v311[k] + 3);
          kk = 0;
          for ( m = v20; kk < m; ++kk )
          {
            v21 = *((D3DXShader::CInstruction **)v328 + 3);
            if ( v21 != nullptr )
            {
              i3 = *((_DWORD *)v328 + 6);
              for ( n = v21; n != nullptr; n = (D3DXShader::CInstruction *)((char *)n - 1) )
              {
                v22 = *(struct D3DXShader::CInstruction **)i3;
                if ( *(_DWORD *)i3 != 0 && *(_DWORD *)v22 != 0 )
                {
                  v23 = *((_DWORD *)v22 + 1);
                  v318 = 0;
                  if ( v23 != 0 )
                  {
                    v24 = *(_DWORD *)(*((_DWORD *)v311[k] + 4) + 4 * kk);
                    v25 = *((_DWORD **)v22 + 2);
                    for ( ii = v23; ii != 0; --ii )
                    {
                      if ( *v25 == v24 || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *v25) + 56) == v24 )
                        v318 = 1;
                      ++v25;
                    }
                  }
                  if ( v22 == v1 )
                    v318 = 0;
                  if ( v318 != 0 )
                  {
                    for ( jj = 0; jj < v326; ++jj )
                    {
                      if ( v22 == v311[jj] )
                        v318 = 0;
                    }
                    if ( v318 != 0 )
                      matched = 1;
                  }
                }
                i3 += 4;
              }
            }
          }
        }
        for ( kk = 0; kk < 0x28; ++kk )
        {
          v27 = v307[kk + 40];
          if ( v27 != -1 )
          {
            v28 = 0;
            if ( v326 != 0 )
            {
              m = *(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * v27);
              do
              {
                v29 = v311[v28];
                v30 = *((D3DXShader::CInstruction **)v29 + 3);
                if ( v30 != nullptr )
                {
                  v31 = *((_DWORD **)v29 + 4);
                  for ( n = v30; n != nullptr; n = (D3DXShader::CInstruction *)((char *)n - 1) )
                  {
                    if ( v27 == *v31 || *(_DWORD *)(m + 56) == *v31 )
                      matched = 1;
                    ++v31;
                  }
                }
                ++v28;
              }
              while ( v28 < v326 );
            }
          }
        }
        if ( matched == 0 )
        {
LABEL_81:
          v32 = v326;
          qmemcpy(v310, v311, 4 * v326);
          v310[v32] = v1;
          v317 = v326 + 1;
          for ( mm = 0; mm < 40; ++mm )
          {
            v34 = v307[mm + 40];
            if ( v34 == -1 )
            {
              v34 = v307[mm];
              if ( v34 == -1 )
                continue;
            }
            v307[mm + 80] = v34;
          }
          matched = 0;
          goto LABEL_87;
        }
      }
    }
  }
LABEL_87:
  v35 = matched;
  if ( matched != 1 )
    goto LABEL_178;
LABEL_88:
  i3 = *((_DWORD *)v328 + 64);
  v36 = *(struct D3DXShader::CInstruction **)i3;
  v326 = *(_DWORD *)i3 & 0xFFFFF;
  if ( v326 > v322 || ((unsigned int)v36 & 0xFFF00000) != 0x20100000 )
  {
    v35 = 1;
    goto LABEL_177;
  }
  kk = 0;
  v318 = 4 * v317;
  while ( 2 )
  {
    k = 0;
    while ( 2 )
    {
      qmemcpy(v311, v310, v318);
      memset(v307, 255, 320);
      v37 = 0;
      i14 = (struct D3DXShader::CInstruction *)v317;
      matched = 0;
      j = 0;
      while ( 2 )
      {
        if ( k != 0 )
          v38 = 1 - j;
        else
          v38 = j;
        v39 = *(_DWORD *)(i3 + 8);
        v40 = dword_102BD56C[v38];
        v41 = (unsigned int *)(v39 + 4 * v37);
        if ( v40 >= 0x10 )
        {
          v45 = 0;
          v46 = &v307[4 * v40 - 24];
          do
          {
            v47 = v313[v45];
            if ( v47 >= v326 )
              *v46 = -1;
            else
              *v46 = *(_DWORD *)(v39 + 4 * (v37 + v47));
            ++v45;
            ++v46;
          }
          while ( v45 < 4 );
LABEL_106:
          if ( matched == 1 )
            goto LABEL_110;
          ++j;
          v37 += v326;
          if ( j >= 2 )
            goto LABEL_110;
          continue;
        }
        break;
      }
      v42 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *v41) + 72);
      if ( v42 != -1 )
      {
        v43 = 32 * v40;
        v44 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)v328 + 6) + 4 * v42);
        if ( D3DXShader::CShaderProgram::ComputeSwizzle(
               this: v328,
               a2: v44,
               a3: v41,
               a4: v326,
               a5: v313,
               a6: v312,
               a7: dword_102BD578[8 * v40],
               a8: 0) == 0 )
        {
          matched = D3DXShader::CShaderProgram::MatchComplexTree(
                      this: v328,
                      a2: v44,
                      a3: (const struct D3DXShader::D3DX_MATCHENTRY *)((char *)&unk_102BD560 + v43),
                      a4: v311,
                      a5: (unsigned int *)&i14,
                      a6: v307,
                      a7: v312,
                      a8: v322,
                      a9: 0);
          goto LABEL_106;
        }
      }
      matched = 1;
LABEL_110:
      j = 0;
      i4 = 0;
      do
      {
        if ( k != 0 )
          v48 = 1 - j;
        else
          v48 = j;
        if ( (unsigned int)dword_102BD56C[v48] >= 0x10 )
        {
          i = 0;
          if ( i14 != nullptr )
          {
            do
            {
              v49 = 0;
              if ( v326 != 0 )
              {
                v50 = v311[i];
                v51 = *((_DWORD *)v50 + 3);
                while ( 1 )
                {
                  ii = 0;
                  if ( v51 != 0 )
                    break;
LABEL_122:
                  if ( ++v49 >= v326 )
                    goto LABEL_125;
                }
                v52 = *(_DWORD *)(*(_DWORD *)(i3 + 8) + 4 * (v49 + i4));
                v53 = *((_DWORD **)v50 + 4);
                while ( v52 != *v53 )
                {
                  ++ii;
                  ++v53;
                  if ( ii >= v51 )
                    goto LABEL_122;
                }
                matched = 1;
              }
LABEL_125:
              ++i;
            }
            while ( i < (unsigned int)i14 );
          }
        }
        ++j;
        i4 += v326;
      }
      while ( j < 2 );
      if ( matched == 0 )
      {
        if ( kk != 0 )
          goto LABEL_170;
        v54 = 0;
        i4 = 0;
        if ( i14 != nullptr )
        {
          do
          {
            v55 = *((_DWORD *)v311[v54] + 3);
            i = 0;
            for ( m = v55; i < m; ++i )
            {
              v56 = *((_DWORD *)v328 + 3);
              if ( v56 != 0 )
              {
                v57 = *((struct D3DXShader::CInstruction ***)v328 + 6);
                ii = (unsigned int)v57;
                j = v56;
                do
                {
                  v58 = *v57;
                  if ( v58 != nullptr && *(_DWORD *)v58 != 0 )
                  {
                    v59 = *((_DWORD *)v58 + 1);
                    n = nullptr;
                    if ( v59 != 0 )
                    {
                      v60 = *(_DWORD *)(*((_DWORD *)v311[i4] + 4) + 4 * i);
                      v61 = *((_DWORD **)v58 + 2);
                      for ( nn = v59; nn != 0; --nn )
                      {
                        if ( *v61 == v60 || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *v61) + 56) == v60 )
                          n = (D3DXShader::CInstruction *)1;
                        ++v61;
                      }
                    }
                    if ( v58 == (struct D3DXShader::CInstruction *)i3 )
                      v63 = nullptr;
                    else
                      v63 = n;
                    if ( v63 != nullptr )
                    {
                      for ( i1 = 0; i1 < (unsigned int)i14; ++i1 )
                      {
                        if ( v58 == v311[i1] )
                          v63 = nullptr;
                      }
                      if ( v63 != nullptr )
                        matched = 1;
                    }
                  }
                  v57 = (struct D3DXShader::CInstruction **)(ii + 4);
                  v253 = j-- == 1;
                  ii += 4;
                }
                while ( !v253 );
              }
            }
            v54 = ++i4;
          }
          while ( i4 < (unsigned int)i14 );
        }
        for ( i = 0; i < 0x28; ++i )
        {
          v65 = v307[i + 40];
          if ( v65 != -1 )
          {
            v66 = 0;
            if ( i14 != nullptr )
            {
              v67 = *(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * v65);
              do
              {
                v68 = v311[v66];
                v69 = *((_DWORD *)v68 + 3);
                if ( v69 != 0 )
                {
                  v70 = *((_DWORD **)v68 + 4);
                  do
                  {
                    if ( v65 == *v70 || *(_DWORD *)(v67 + 56) == *v70 )
                      matched = 1;
                    ++v70;
                    --v69;
                  }
                  while ( v69 != 0 );
                }
                ++v66;
              }
              while ( v66 < (unsigned int)i14 );
            }
          }
        }
        if ( matched == 0 )
        {
LABEL_170:
          v71 = i14;
          v72 = (struct D3DXShader::CInstruction *)(4 * (_DWORD)i14);
          qmemcpy(v310, v311, 4 * (_DWORD)i14);
          *(struct D3DXShader::CInstruction **)((char *)v310 + (_DWORD)v72) = (struct D3DXShader::CInstruction *)i3;
          v317 = (unsigned int)v71 + 1;
          for ( i2 = 0; i2 < 40; ++i2 )
          {
            v74 = v307[i2 + 40];
            if ( v74 == -1 )
            {
              v74 = v307[i2];
              if ( v74 == -1 )
                continue;
            }
            v307[i2 + 80] = v74;
          }
          matched = 0;
LABEL_176:
          v35 = matched;
LABEL_177:
          i4 = 1;
LABEL_178:
          if ( v35 == 0 )
          {
            i3 = 0;
            i14 = nullptr;
            v75 = v308;
            while ( 1 )
            {
              ii = 0;
              if ( v322 == 0 )
                break;
              v76 = *((_DWORD *)v328 + 5);
              v77 = *((_DWORD *)v328 + 4);
              v78 = v75;
              for ( n = (D3DXShader::CInstruction *)v322; n != nullptr; n = (D3DXShader::CInstruction *)((char *)n - 1) )
              {
                v79 = *(_DWORD *)(v76 + 4 * *v78);
                if ( (*(_BYTE *)(*(_DWORD *)(v77 + 4 * *(_DWORD *)(v79 + 4)) + 5) & 1) == 0
                  || *(_DWORD *)(v79 + 8) != -1
                  || *(double *)(v79 + 32) != (double)(int)i4 )
                {
                  ii = 1;
                }
                ++v78;
              }
              if ( ii == 0 )
                break;
              i14 = (struct D3DXShader::CInstruction *)((char *)i14 + 1);
              v75 += 4;
              if ( (unsigned int)i14 >= 2 )
              {
                v80 = (struct D3DXShader::CInstruction **)i3;
                goto LABEL_191;
              }
            }
            v80 = &v309[-4 * (_DWORD)i14];
            i3 = (unsigned int)v80;
LABEL_191:
            v81 = 0;
            n = nullptr;
            if ( v322 != 0 )
            {
              v82 = *((_DWORD *)v328 + 5);
              v83 = *((_DWORD *)v328 + 4);
              do
              {
                v84 = *(_DWORD *)(v82 + 4 * v307[v81 + 80]);
                if ( (*(_BYTE *)(*(_DWORD *)(v83 + 4 * *(_DWORD *)(v84 + 4)) + 5) & 1) != 0
                  && *(_DWORD *)(v84 + 8) == -1
                  && *(double *)(v84 + 32) == (double)(int)i4 )
                {
                  n = (D3DXShader::CInstruction *)1;
                }
                ++v81;
              }
              while ( v81 < v322 );
              if ( n != nullptr )
              {
                v80 = nullptr;
                i3 = 0;
              }
            }
            v85 = 0;
            if ( v80 == nullptr )
              return 1;
            if ( v322 != 0 )
            {
              v86 = *((_DWORD *)v328 + 5);
              v87 = v316;
              do
              {
                v88 = *(_DWORD *)(v86 + 4 * (_DWORD)v80[v85]);
                v89 = 0;
                if ( v87 != 0 )
                {
                  do
                  {
                    if ( *(_DWORD *)(v88 + 72) == v313[v89] )
                      break;
                    ++v89;
                  }
                  while ( v89 < v87 );
                  v80 = (struct D3DXShader::CInstruction **)i3;
                }
                if ( v89 == v87 )
                  v313[v87++] = *(_DWORD *)(v88 + 72);
                ++v85;
              }
              while ( v85 < v322 );
              v316 = v87;
            }
            v326 = (unsigned int)v80;
            goto LABEL_589;
          }
          v90 = *((int **)v328 + 64);
          v91 = *v90;
          kk = (unsigned int)v90;
          v92 = *v90;
          i14 = (struct D3DXShader::CInstruction *)(v92 & 0xFFFFF);
          v322 = v91 & 0xFFFFF;
          m = 1;
          if ( (v92 & 0xFFFFFu) <= (v91 & 0xFFFFFu) && (v92 & 0xFFF00000) == 0x30000000 )
          {
            i = 0;
            v318 = 4 * v317;
            while ( 1 )
            {
              for ( k = 0; k == 0; ++k )
              {
                qmemcpy(v311, v310, v318);
                memset(v307, 255, 320);
                v93 = 0;
                v326 = v317;
                matched = 0;
                j = 0;
                while ( 1 )
                {
                  if ( k != 0 )
                    v94 = 1 - j;
                  else
                    v94 = j;
                  v95 = *(_DWORD *)(kk + 8);
                  v96 = dword_102BD36C[v94];
                  v97 = (unsigned int *)(v95 + 4 * v93);
                  if ( v96 >= 0x10 )
                  {
                    v101 = 0;
                    v102 = &v307[4 * v96 - 24];
                    do
                    {
                      v103 = v313[v101];
                      if ( v103 >= (unsigned int)i14 )
                        *v102 = -1;
                      else
                        *v102 = *(_DWORD *)(v95 + 4 * (v93 + v103));
                      ++v101;
                      ++v102;
                    }
                    while ( v101 < 4 );
                    goto LABEL_229;
                  }
                  v98 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *v97) + 72);
                  if ( v98 == -1 )
                    break;
                  v99 = 32 * v96;
                  v100 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)v328 + 6) + 4 * v98);
                  if ( D3DXShader::CShaderProgram::ComputeSwizzle(
                         this: v328,
                         a2: v100,
                         a3: v97,
                         a4: (unsigned int)i14,
                         a5: v313,
                         a6: v312,
                         a7: dword_102BD378[8 * v96],
                         a8: 0) != 0 )
                    break;
                  matched = D3DXShader::CShaderProgram::MatchComplexTree(
                              this: v328,
                              a2: v100,
                              a3: (const struct D3DXShader::D3DX_MATCHENTRY *)((char *)&unk_102BD360 + v99),
                              a4: v311,
                              a5: &v326,
                              a6: v307,
                              a7: v312,
                              a8: v322,
                              a9: 0);
LABEL_229:
                  if ( matched != 1 )
                  {
                    ++j;
                    v93 += (int)i14;
                    if ( j < 3 )
                      continue;
                  }
                  goto LABEL_233;
                }
                matched = 1;
LABEL_233:
                j = 0;
                ii = 0;
                do
                {
                  if ( k != 0 )
                    v104 = 1 - j;
                  else
                    v104 = j;
                  if ( (unsigned int)dword_102BD36C[v104] >= 0x10 )
                  {
                    for ( i3 = 0; i3 < v326; ++i3 )
                    {
                      v105 = 0;
                      if ( i14 != nullptr )
                      {
                        v106 = v311[i3];
                        v107 = *((_DWORD *)v106 + 3);
                        while ( 1 )
                        {
                          i4 = 0;
                          if ( v107 != 0 )
                            break;
LABEL_245:
                          if ( ++v105 >= (unsigned int)i14 )
                            goto LABEL_248;
                        }
                        v108 = *(_DWORD *)(*(_DWORD *)(kk + 8) + 4 * (v105 + ii));
                        v109 = *((_DWORD **)v106 + 4);
                        while ( v108 != *v109 )
                        {
                          ++i4;
                          ++v109;
                          if ( i4 >= v107 )
                            goto LABEL_245;
                        }
                        matched = 1;
                      }
LABEL_248:
                      ;
                    }
                  }
                  ++j;
                  ii += (unsigned int)i14;
                }
                while ( j < 3 );
                if ( matched == 0 )
                {
                  if ( i != 0 )
                    goto LABEL_293;
                  v110 = 0;
                  for ( i4 = 0; i4 < v326; ++i4 )
                  {
                    v111 = *((_DWORD *)v311[v110] + 3);
                    i3 = 0;
                    for ( i5 = v111; i3 < i5; ++i3 )
                    {
                      v112 = *((_DWORD *)v328 + 3);
                      if ( v112 != 0 )
                      {
                        v113 = *((struct D3DXShader::CInstruction ***)v328 + 6);
                        ii = (unsigned int)v113;
                        j = v112;
                        do
                        {
                          v114 = *v113;
                          if ( v114 != nullptr && *(_DWORD *)v114 != 0 )
                          {
                            v115 = *((_DWORD *)v114 + 1);
                            n = nullptr;
                            if ( v115 != 0 )
                            {
                              v116 = *(_DWORD *)(*((_DWORD *)v311[i4] + 4) + 4 * i3);
                              v117 = *((_DWORD **)v114 + 2);
                              for ( i6 = v115; i6 != 0; --i6 )
                              {
                                if ( *v117 == v116
                                  || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *v117) + 56) == v116 )
                                {
                                  n = (D3DXShader::CInstruction *)1;
                                }
                                ++v117;
                              }
                            }
                            if ( v114 == (struct D3DXShader::CInstruction *)kk )
                              v119 = nullptr;
                            else
                              v119 = n;
                            if ( v119 != nullptr )
                            {
                              for ( i7 = 0; i7 < v326; ++i7 )
                              {
                                if ( v114 == v311[i7] )
                                  v119 = nullptr;
                              }
                              if ( v119 != nullptr )
                                matched = 1;
                            }
                          }
                          v113 = (struct D3DXShader::CInstruction **)(ii + 4);
                          v253 = j-- == 1;
                          ii += 4;
                        }
                        while ( !v253 );
                      }
                    }
                    v110 = i4 + 1;
                  }
                  for ( i3 = 0; i3 < 0x28; ++i3 )
                  {
                    v121 = v307[i3 + 40];
                    if ( v121 != -1 )
                    {
                      v122 = 0;
                      if ( v326 != 0 )
                      {
                        v123 = *(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * v121);
                        do
                        {
                          v124 = v311[v122];
                          v125 = *((_DWORD *)v124 + 3);
                          if ( v125 != 0 )
                          {
                            v126 = *((_DWORD **)v124 + 4);
                            do
                            {
                              if ( v121 == *v126 || *(_DWORD *)(v123 + 56) == *v126 )
                                matched = 1;
                              ++v126;
                              --v125;
                            }
                            while ( v125 != 0 );
                          }
                          ++v122;
                        }
                        while ( v122 < v326 );
                      }
                    }
                  }
                  if ( matched == 0 )
                  {
LABEL_293:
                    v127 = v326;
                    v128 = v326;
                    qmemcpy(v310, v311, 4 * v326);
                    v310[v128] = (struct D3DXShader::CInstruction *)kk;
                    v317 = v127 + 1;
                    for ( i8 = 0; i8 < 40; ++i8 )
                    {
                      v130 = v307[i8 + 40];
                      if ( v130 == -1 )
                      {
                        v130 = v307[i8];
                        if ( v130 == -1 )
                          continue;
                      }
                      v307[i8 + 80] = v130;
                    }
                    matched = 0;
                    goto LABEL_299;
                  }
                }
              }
              if ( ++i != 0 )
              {
LABEL_299:
                v131 = matched;
                if ( matched != 1 )
                  goto LABEL_390;
                break;
              }
            }
          }
          kk = *((_DWORD *)v328 + 64);
          v132 = *(_DWORD *)kk;
          v326 = *(_DWORD *)kk & 0xFFFFF;
          if ( v326 > v322 || (v132 & 0xFFF00000) != 0x30000000 )
          {
            v131 = 1;
            goto LABEL_389;
          }
          i = 0;
          v318 = 4 * v317;
          while ( 2 )
          {
            k = 0;
            while ( 2 )
            {
              qmemcpy(v311, v310, v318);
              memset(v307, 255, 320);
              v133 = 0;
              i14 = (struct D3DXShader::CInstruction *)v317;
              matched = 0;
              j = 0;
              while ( 1 )
              {
                if ( k != 0 )
                  v134 = 1 - j;
                else
                  v134 = j;
                v135 = *(_DWORD *)(kk + 8);
                v136 = dword_102BD4CC[v134];
                v137 = (unsigned int *)(v135 + 4 * v133);
                if ( v136 >= 0x10 )
                {
                  v141 = 0;
                  v142 = &v307[4 * v136 - 24];
                  do
                  {
                    v143 = v313[v141];
                    if ( v143 >= v326 )
                      *v142 = -1;
                    else
                      *v142 = *(_DWORD *)(v135 + 4 * (v133 + v143));
                    ++v141;
                    ++v142;
                  }
                  while ( v141 < 4 );
                  goto LABEL_318;
                }
                v138 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *v137) + 72);
                if ( v138 == -1 )
                  break;
                v139 = 32 * v136;
                v140 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)v328 + 6) + 4 * v138);
                if ( D3DXShader::CShaderProgram::ComputeSwizzle(
                       this: v328,
                       a2: v140,
                       a3: v137,
                       a4: v326,
                       a5: v313,
                       a6: v312,
                       a7: dword_102BD4D8[8 * v136],
                       a8: 0) != 0 )
                  break;
                matched = D3DXShader::CShaderProgram::MatchComplexTree(
                            this: v328,
                            a2: v140,
                            a3: (const struct D3DXShader::D3DX_MATCHENTRY *)((char *)&unk_102BD4C0 + v139),
                            a4: v311,
                            a5: (unsigned int *)&i14,
                            a6: v307,
                            a7: v312,
                            a8: v322,
                            a9: 0);
LABEL_318:
                if ( matched != 1 )
                {
                  ++j;
                  v133 += v326;
                  if ( j < 3 )
                    continue;
                }
                goto LABEL_322;
              }
              matched = 1;
LABEL_322:
              j = 0;
              ii = 0;
              do
              {
                if ( k != 0 )
                  v144 = 1 - j;
                else
                  v144 = j;
                if ( (unsigned int)dword_102BD4CC[v144] >= 0x10 )
                {
                  i3 = 0;
                  if ( i14 != nullptr )
                  {
                    do
                    {
                      v145 = 0;
                      if ( v326 != 0 )
                      {
                        v146 = v311[i3];
                        v147 = *((_DWORD *)v146 + 3);
                        while ( 1 )
                        {
                          i4 = 0;
                          if ( v147 != 0 )
                            break;
LABEL_334:
                          if ( ++v145 >= v326 )
                            goto LABEL_337;
                        }
                        v148 = *(_DWORD *)(*(_DWORD *)(kk + 8) + 4 * (v145 + ii));
                        v149 = *((_DWORD **)v146 + 4);
                        while ( v148 != *v149 )
                        {
                          ++i4;
                          ++v149;
                          if ( i4 >= v147 )
                            goto LABEL_334;
                        }
                        matched = 1;
                      }
LABEL_337:
                      ++i3;
                    }
                    while ( i3 < (unsigned int)i14 );
                  }
                }
                ++j;
                ii += v326;
              }
              while ( j < 3 );
              if ( matched == 0 )
              {
                if ( i != 0 )
                  goto LABEL_382;
                v150 = 0;
                i4 = 0;
                if ( i14 != nullptr )
                {
                  do
                  {
                    v151 = *((_DWORD *)v311[v150] + 3);
                    i3 = 0;
                    for ( i5 = v151; i3 < i5; ++i3 )
                    {
                      v152 = *((_DWORD *)v328 + 3);
                      if ( v152 != 0 )
                      {
                        v153 = *((struct D3DXShader::CInstruction ***)v328 + 6);
                        ii = (unsigned int)v153;
                        j = v152;
                        do
                        {
                          v154 = *v153;
                          if ( v154 != nullptr && *(_DWORD *)v154 != 0 )
                          {
                            v155 = *((_DWORD *)v154 + 1);
                            n = nullptr;
                            if ( v155 != 0 )
                            {
                              v156 = *(_DWORD *)(*((_DWORD *)v311[i4] + 4) + 4 * i3);
                              v157 = *((_DWORD **)v154 + 2);
                              for ( i9 = v155; i9 != 0; --i9 )
                              {
                                if ( *v157 == v156
                                  || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *v157) + 56) == v156 )
                                {
                                  n = (D3DXShader::CInstruction *)1;
                                }
                                ++v157;
                              }
                            }
                            if ( v154 == (struct D3DXShader::CInstruction *)kk )
                              v159 = nullptr;
                            else
                              v159 = n;
                            if ( v159 != nullptr )
                            {
                              for ( i10 = 0; i10 < (unsigned int)i14; ++i10 )
                              {
                                if ( v154 == v311[i10] )
                                  v159 = nullptr;
                              }
                              if ( v159 != nullptr )
                                matched = 1;
                            }
                          }
                          v153 = (struct D3DXShader::CInstruction **)(ii + 4);
                          v253 = j-- == 1;
                          ii += 4;
                        }
                        while ( !v253 );
                      }
                    }
                    v150 = ++i4;
                  }
                  while ( i4 < (unsigned int)i14 );
                }
                for ( i3 = 0; i3 < 0x28; ++i3 )
                {
                  v161 = v307[i3 + 40];
                  if ( v161 != -1 )
                  {
                    v162 = 0;
                    if ( i14 != nullptr )
                    {
                      v163 = *(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * v161);
                      do
                      {
                        v164 = v311[v162];
                        v165 = *((_DWORD *)v164 + 3);
                        if ( v165 != 0 )
                        {
                          v166 = *((_DWORD **)v164 + 4);
                          do
                          {
                            if ( v161 == *v166 || *(_DWORD *)(v163 + 56) == *v166 )
                              matched = 1;
                            ++v166;
                            --v165;
                          }
                          while ( v165 != 0 );
                        }
                        ++v162;
                      }
                      while ( v162 < (unsigned int)i14 );
                    }
                  }
                }
                if ( matched == 0 )
                {
LABEL_382:
                  v167 = i14;
                  v168 = (struct D3DXShader::CInstruction *)(4 * (_DWORD)i14);
                  qmemcpy(v310, v311, 4 * (_DWORD)i14);
                  *(struct D3DXShader::CInstruction **)((char *)v310 + (_DWORD)v168) = (struct D3DXShader::CInstruction *)kk;
                  v317 = (unsigned int)v167 + 1;
                  for ( i11 = 0; i11 < 40; ++i11 )
                  {
                    v170 = v307[i11 + 40];
                    if ( v170 == -1 )
                    {
                      v170 = v307[i11];
                      if ( v170 == -1 )
                        continue;
                    }
                    v307[i11 + 80] = v170;
                  }
                  matched = 0;
LABEL_388:
                  v131 = matched;
LABEL_389:
                  m = 0;
LABEL_390:
                  if ( v131 == 0 )
                  {
                    i3 = 0;
                    if ( v322 != 0 )
                    {
                      do
                      {
                        v171 = *((_DWORD *)v328 + 5);
                        v172 = *(_DWORD *)(v171 + 4 * v307[i3 + 80]);
                        v173 = v309[i3];
                        v253 = v173 == v309[i3 + 12];
                        n = *(D3DXShader::CInstruction **)(v171 + 4 * v308[i3]);
                        if ( !v253 )
                          return 1;
                        v174 = v309[i3 + 4];
                        if ( v174 != v309[i3 + 16] )
                          return 1;
                        v175 = v309[i3 + 8];
                        if ( v175 != v309[i3 + 20] )
                          return 1;
                        if ( v173 != v174 )
                          return 1;
                        v176 = *((_DWORD *)v328 + 5);
                        v177 = *((_DWORD *)v328 + 4);
                        v178 = *(_DWORD *)(v176 + 4 * (_DWORD)v175);
                        if ( (*(_BYTE *)(*(_DWORD *)(v177 + 4 * *(_DWORD *)(v172 + 4)) + 5) & 1) == 0 )
                          return 1;
                        if ( (*(_BYTE *)(*(_DWORD *)(v177 + 4 * *((_DWORD *)n + 1)) + 5) & 1) == 0 )
                          return 1;
                        if ( (*(_BYTE *)(*(_DWORD *)(v177 + 4 * *(_DWORD *)(v178 + 4)) + 5) & 1) == 0 )
                          return 1;
                        if ( *(double *)(v172 + 32) != 1.0 )
                          return 1;
                        i5 = 2 * (m == 0) - 1;
                        if ( *((double *)n + 4) != (double)(int)i5 || *(double *)(v178 + 32) != 0.0 )
                          return 1;
                        v179 = *(_DWORD *)(v176 + 4 * (_DWORD)v173);
                        if ( *(_DWORD *)(v179 + 4) != *((_DWORD *)v328 + 34) )
                          v315 = 1;
                        v180 = v316;
                        for ( i12 = 0; i12 < v316; ++i12 )
                        {
                          if ( *(_DWORD *)(v179 + 72) == v313[i12] )
                            break;
                        }
                        if ( i12 == v316 && v315 == 0 )
                        {
                          v313[v316] = *(_DWORD *)(v179 + 72);
                          v316 = v180 + 1;
                        }
                      }
                      while ( ++i3 < v322 );
                    }
                    v326 = (unsigned int)v309;
LABEL_589:
                    i3 = 0;
                    if ( v316 == 0 )
                    {
LABEL_603:
                      v269 = 0;
                      if ( v315 != 0 )
                        goto LABEL_628;
                      v270 = 0;
                      v271 = -1;
                      if ( v322 != 0 )
                      {
                        do
                        {
                          v272 = *(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *(_DWORD *)(v326 + 4 * v269));
                          if ( v270 < *(_DWORD *)(v272 + 88) )
                            v270 = *(_DWORD *)(v272 + 88);
                          v273 = *(_DWORD *)(v272 + 84);
                          if ( v271 > v273 )
                            v271 = v273;
                          ++v269;
                        }
                        while ( v269 < v322 );
                      }
                      v274 = *((D3DXShader::CInstruction **)v328 + 3);
                      if ( v274 != nullptr )
                      {
                        i4 = *((_DWORD *)v328 + 6);
                        for ( n = v274; n != nullptr; n = (D3DXShader::CInstruction *)((char *)n - 1) )
                        {
                          v275 = *(struct D3DXShader::CInstruction **)i4;
                          if ( **(_DWORD **)i4 != 0 )
                          {
                            v276 = 0;
                            v277 = v317 == 0;
                            if ( v317 != 0 )
                            {
                              do
                              {
                                if ( v275 == v310[v276] )
                                  break;
                                ++v276;
                              }
                              while ( v276 < v317 );
                              v277 = v276 == v317;
                            }
                            if ( v277 )
                            {
                              v278 = *((_DWORD *)v275 + 1);
                              if ( v278 != 0 )
                              {
                                v279 = *((_DWORD *)v328 + 5);
                                v280 = *((int **)v275 + 2);
                                for ( m = v278; m != 0; --m )
                                {
                                  v281 = *v280;
                                  v282 = *(_DWORD *)(v279 + 4 * *v280);
                                  for ( i13 = 0; i13 < v322; ++i13 )
                                  {
                                    v284 = *(_DWORD *)(v326 + 4 * i13);
                                    if ( v284 == v281 || *(_DWORD *)(v282 + 56) == v284 )
                                      v315 = 1;
                                  }
                                  ++v280;
                                }
                              }
                            }
                          }
                          i4 += 4;
                        }
                        if ( v315 != 0 )
                          goto LABEL_628;
                      }
                      v298 = 0;
                      m = 0;
                      if ( v316 != 0 )
                      {
                        v299 = v328;
                        do
                        {
                          v300 = *(_DWORD *)(*((_DWORD *)v299 + 6) + 4 * v313[v298]);
                          v301 = nullptr;
                          i5 = *(_DWORD *)(*((_DWORD *)v299 + 64) + 12);
                          for ( i14 = nullptr;
                                (unsigned int)i14 < i5;
                                i14 = (struct D3DXShader::CInstruction *)((char *)i14 + 1) )
                          {
                            v302 = 0;
                            v253 = *(_DWORD *)(v300 + 12) == 0;
                            i4 = 0;
                            if ( !v253 )
                            {
                              v303 = (_DWORD *)(v326 + 4 * (_DWORD)v301);
                              do
                              {
                                if ( *(_DWORD *)(*(_DWORD *)(v300 + 16) + 4 * v302) == *v303 )
                                {
                                  v304 = i4;
                                  *(_DWORD *)(*(_DWORD *)(v300 + 16) + 4 * i4) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v299 + 64) + 16)
                                                                                           + 4 * (_DWORD)i14);
                                  v302 = v304;
                                  v305 = *(_DWORD *)(*((_DWORD *)v299 + 5)
                                                   + 4 * *(_DWORD *)(*(_DWORD *)(v300 + 16) + 4 * v304));
                                  *(_BYTE *)(v305 + 61) |= 2u;
                                }
                                v295 = ++v302 < *(_DWORD *)(v300 + 12);
                                i4 = v302;
                              }
                              while ( v295 );
                            }
                            v301 = (char *)i14 + 1;
                          }
                          v298 = ++m;
                        }
                        while ( m < v316 );
                      }
                      for ( i15 = 0; i15 < v317; ++i15 )
                        *(_DWORD *)v310[i15] = 0;
                      return 0;
                    }
                    while ( 1 )
                    {
                      v263 = v313[i3];
                      if ( v263 == -1 )
                        break;
                      v264 = *(_DWORD **)(*((_DWORD *)v328 + 6) + 4 * v263);
                      if ( (*v264 & 0xF0000000) == 0x60000000 )
                        break;
                      v265 = v264[3];
                      v266 = 0;
                      for ( i4 = 0; v266 < v322; ++v266 )
                      {
                        if ( v265 != 0 )
                        {
                          v267 = *(_DWORD *)(v326 + 4 * v266);
                          v268 = (_DWORD *)v264[4];
                          for ( m = v265; m != 0; --m )
                          {
                            if ( *v268 == v267 )
                              ++i4;
                            ++v268;
                          }
                        }
                      }
                      if ( i4 != v265 )
                      {
                        v315 = 1;
                        goto LABEL_603;
                      }
                      if ( ++i3 >= v316 )
                        goto LABEL_603;
                    }
LABEL_628:
                    v285 = D3DXShader::CInstruction::operator new(a1: 0x74u);
                    if ( v285 != nullptr )
                      v286 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v285);
                    else
                      v286 = nullptr;
                    if ( v286 == nullptr )
                      return 1;
                    v131 = D3DXShader::CInstruction::Initialize(
                             this: (D3DXShader::CInstruction *)v286,
                             a2: v322 & 0xFFFFF | 0x10000000,
                             a3: v322,
                             a4: v322,
                             a5: 0);
                    v287 = (D3DXShader::CInstruction *)v286;
                    if ( v131 >= 0 )
                    {
                      v131 = D3DXShader::CInstruction::Instance(
                               this: (D3DXShader::CInstruction *)v286,
                               a2: *((struct D3DXShader::CInstruction **)v328 + 64));
                      if ( v131 < 0 )
                      {
                        v287 = (D3DXShader::CInstruction *)v286;
                        goto LABEL_636;
                      }
                      v288 = 4 * v322;
                      qmemcpy(v286[2], (const void *)v326, 4 * v322);
                      v289 = v288;
                      v290 = v328;
                      qmemcpy(v286[4], *(const void **)(*((_DWORD *)v328 + 64) + 16), v289);
                      for ( i16 = 0; i16 < v322; ++i16 )
                      {
                        v292 = *(_DWORD *)(*((_DWORD *)v290 + 5) + 4 * *((_DWORD *)v286[4] + i16));
                        *(_BYTE *)(v292 + 61) |= 2u;
                      }
                      v293 = 0;
                      if ( v317 != 0 )
                      {
                        do
                        {
                          v294 = v310[v293++];
                          v295 = v293 < v317;
                          *(_DWORD *)v294 = 0;
                        }
                        while ( v295 );
                      }
                      v296 = (_DWORD *)((char *)v290 + 252);
                      v297 = *(D3DXShader::CInstruction **)(*((_DWORD *)v290 + 6) + 4 * *((_DWORD *)v290 + 63));
                      if ( v297 != nullptr )
                      {
                        D3DXShader::CInstruction::`scalar deleting destructor'(this: v297, a2: 1);
                        v290 = v328;
                      }
                      *(_DWORD *)(*((_DWORD *)v290 + 6) + 4 * *v296) = v286;
                      return 0;
                    }
LABEL_636:
                    D3DXShader::CInstruction::`scalar deleting destructor'(this: v287, a2: 1);
                    return v131;
                  }
                  if ( v131 != 1 )
                  {
LABEL_588:
                    if ( v131 == 0 )
                      goto LABEL_589;
                    return v131;
                  }
                  kk = *((_DWORD *)v328 + 64);
                  v182 = *(_DWORD *)kk;
                  v326 = *(_DWORD *)kk & 0xFFFFF;
                  if ( v326 > v322 || (v182 & 0xFFF00000) != 0x30000000 )
                  {
                    v131 = 1;
                    goto LABEL_416;
                  }
                  i = 0;
                  while ( 2 )
                  {
                    k = 0;
                    while ( 2 )
                    {
                      v185 = (struct D3DXShader::CInstruction *)v317;
                      qmemcpy(v311, v310, 4 * v317);
                      v186 = 0;
                      memset(v307, 255, 320);
                      i14 = v185;
                      matched = 0;
                      j = 0;
                      while ( 2 )
                      {
                        if ( k != 0 )
                          v187 = 1 - j;
                        else
                          v187 = j;
                        v188 = *(_DWORD *)(kk + 8);
                        v189 = dword_102BD40C[v187];
                        v190 = (unsigned int *)(v188 + 4 * v186);
                        if ( v189 >= 0x10 )
                        {
                          v194 = 0;
                          v195 = &v307[4 * v189 - 24];
                          do
                          {
                            v196 = v313[v194];
                            if ( v196 >= v326 )
                              *v195 = -1;
                            else
                              *v195 = *(_DWORD *)(v188 + 4 * (v186 + v196));
                            ++v194;
                            ++v195;
                          }
                          while ( v194 < 4 );
LABEL_435:
                          if ( matched == 1 )
                            goto LABEL_439;
                          ++j;
                          v186 += v326;
                          if ( j >= 3 )
                            goto LABEL_439;
                          continue;
                        }
                        break;
                      }
                      v191 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *v190) + 72);
                      if ( v191 != -1 )
                      {
                        v192 = 32 * v189;
                        v193 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)v328 + 6) + 4 * v191);
                        if ( D3DXShader::CShaderProgram::ComputeSwizzle(
                               this: v328,
                               a2: v193,
                               a3: v190,
                               a4: v326,
                               a5: v313,
                               a6: v312,
                               a7: dword_102BD418[8 * v189],
                               a8: 0) == 0 )
                        {
                          matched = D3DXShader::CShaderProgram::MatchComplexTree(
                                      this: v328,
                                      a2: v193,
                                      a3: (const struct D3DXShader::D3DX_MATCHENTRY *)((char *)&unk_102BD400 + v192),
                                      a4: v311,
                                      a5: (unsigned int *)&i14,
                                      a6: v307,
                                      a7: v312,
                                      a8: v322,
                                      a9: 0);
                          goto LABEL_435;
                        }
                      }
                      matched = 1;
LABEL_439:
                      j = 0;
                      ii = 0;
                      do
                      {
                        if ( k != 0 )
                          v197 = 1 - j;
                        else
                          v197 = j;
                        if ( (unsigned int)dword_102BD40C[v197] >= 0x10 )
                        {
                          i3 = 0;
                          if ( i14 != nullptr )
                          {
                            do
                            {
                              v198 = 0;
                              if ( v326 != 0 )
                              {
                                v199 = v311[i3];
                                v200 = *((_DWORD *)v199 + 3);
                                while ( 1 )
                                {
                                  i4 = 0;
                                  if ( v200 != 0 )
                                    break;
LABEL_451:
                                  if ( ++v198 >= v326 )
                                    goto LABEL_454;
                                }
                                v201 = *(_DWORD *)(*(_DWORD *)(kk + 8) + 4 * (v198 + ii));
                                v202 = *((_DWORD **)v199 + 4);
                                while ( v201 != *v202 )
                                {
                                  ++i4;
                                  ++v202;
                                  if ( i4 >= v200 )
                                    goto LABEL_451;
                                }
                                matched = 1;
                              }
LABEL_454:
                              ++i3;
                            }
                            while ( i3 < (unsigned int)i14 );
                          }
                        }
                        ++j;
                        ii += v326;
                      }
                      while ( j < 3 );
                      if ( matched == 0 )
                      {
                        if ( i != 0 )
                          goto LABEL_499;
                        v203 = 0;
                        i4 = 0;
                        if ( i14 != nullptr )
                        {
                          do
                          {
                            v204 = *((_DWORD *)v311[v203] + 3);
                            i3 = 0;
                            for ( i5 = v204; i3 < i5; ++i3 )
                            {
                              v205 = *((_DWORD *)v328 + 3);
                              if ( v205 != 0 )
                              {
                                v206 = *((D3DXShader::CInstruction **)v328 + 6);
                                n = v206;
                                ii = v205;
                                do
                                {
                                  v207 = *(struct D3DXShader::CInstruction **)v206;
                                  if ( v207 != nullptr && *(_DWORD *)v207 != 0 )
                                  {
                                    v208 = *((_DWORD *)v207 + 1);
                                    m = 0;
                                    if ( v208 != 0 )
                                    {
                                      v209 = *(_DWORD *)(*((_DWORD *)v311[i4] + 4) + 4 * i3);
                                      v210 = *((_DWORD **)v207 + 2);
                                      for ( i17 = v208; i17 != 0; --i17 )
                                      {
                                        if ( *v210 == v209
                                          || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * *v210) + 56) == v209 )
                                        {
                                          m = 1;
                                        }
                                        ++v210;
                                      }
                                    }
                                    if ( v207 == (struct D3DXShader::CInstruction *)kk )
                                      v212 = 0;
                                    else
                                      v212 = m;
                                    if ( v212 != 0 )
                                    {
                                      for ( i18 = 0; i18 < (unsigned int)i14; ++i18 )
                                      {
                                        if ( v207 == v311[i18] )
                                          v212 = 0;
                                      }
                                      if ( v212 != 0 )
                                        matched = 1;
                                    }
                                  }
                                  v206 = (D3DXShader::CInstruction *)((char *)n + 4);
                                  v253 = ii-- == 1;
                                  n = (D3DXShader::CInstruction *)((char *)n + 4);
                                }
                                while ( !v253 );
                              }
                            }
                            v203 = ++i4;
                          }
                          while ( i4 < (unsigned int)i14 );
                        }
                        for ( i3 = 0; i3 < 0x28; ++i3 )
                        {
                          v214 = v307[i3 + 40];
                          if ( v214 != -1 )
                          {
                            v215 = 0;
                            if ( i14 != nullptr )
                            {
                              v216 = *(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * v214);
                              do
                              {
                                v217 = v311[v215];
                                v218 = *((_DWORD *)v217 + 3);
                                if ( v218 != 0 )
                                {
                                  v219 = *((_DWORD **)v217 + 4);
                                  do
                                  {
                                    if ( v214 == *v219 || *(_DWORD *)(v216 + 56) == *v219 )
                                      matched = 1;
                                    ++v219;
                                    --v218;
                                  }
                                  while ( v218 != 0 );
                                }
                                ++v215;
                              }
                              while ( v215 < (unsigned int)i14 );
                            }
                          }
                        }
                        if ( matched == 0 )
                        {
LABEL_499:
                          v220 = i14;
                          v221 = (struct D3DXShader::CInstruction *)(4 * (_DWORD)i14);
                          qmemcpy(v310, v311, 4 * (_DWORD)i14);
                          *(struct D3DXShader::CInstruction **)((char *)v310 + (_DWORD)v221) = (struct D3DXShader::CInstruction *)kk;
                          v317 = (unsigned int)v220 + 1;
                          for ( i19 = 0; i19 < 40; ++i19 )
                          {
                            v223 = v307[i19 + 40];
                            if ( v223 == -1 )
                            {
                              v223 = v307[i19];
                              if ( v223 == -1 )
                                continue;
                            }
                            v307[i19 + 80] = v223;
                          }
                          matched = 0;
LABEL_505:
                          v131 = matched;
                          v224 = 0;
                          if ( matched != 0 )
                          {
LABEL_416:
                            v183 = v328;
                            v253 = (*((_BYTE *)v328 + 110) & 0x40) == 0;
                            i14 = nullptr;
                            n = nullptr;
                            if ( v253
                              || D3DXShader::CShaderProgram::MatchMinMax(this: v328, a2: &i14, a3: v310, a4: &v317) != 0
                              && D3DXShader::CShaderProgram::MatchMinMax2(this: v183, a2: &i14, a3: v310, a4: &v317) != 0 )
                            {
                              v184 = *((struct D3DXShader::CInstruction **)v183 + 64);
                              v317 = 1;
                              v310[0] = v184;
                              i14 = v184;
                            }
                            else
                            {
                              v184 = i14;
                              n = i14;
                            }
                            if ( v184 != nullptr )
                            {
                              v246 = *(_DWORD *)v184;
                              if ( (*(_DWORD *)v184 & 0xFFF00000) == 0x70B00000 )
                              {
                                v322 = v246 & 0xFFFFF;
                                v247 = 4 * (v246 & 0xFFFFF);
                                j = 0;
                                i3 = 0;
                                i = -4 * v322;
                                m = v247;
                                while ( 1 )
                                {
                                  ii = 0;
                                  if ( v322 != 0 )
                                  {
                                    v248 = *((_DWORD *)v184 + 2);
                                    v249 = *((_DWORD *)v328 + 5);
                                    v250 = i3;
                                    i4 = v248 + v247;
                                    do
                                    {
                                      v251 = *(_DWORD *)(v249 + 4 * *(_DWORD *)(v250 + v248));
                                      v253 = (*(_BYTE *)(v251 + 62) & 8) == 0;
                                      v252 = *(_DWORD *)(v249 + 4 * *(_DWORD *)i4);
                                      i5 = v252;
                                      if ( v253 )
                                        v253 = (*(_BYTE *)v251 & 4) == 0;
                                      else
                                        v253 = (*(_BYTE *)v251 & 8) == 0;
                                      if ( v253
                                        || (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v328 + 4) + 4 * *(_DWORD *)(v252 + 4)) + 5)
                                          & 1) == 0
                                        || *(double *)(i5 + 32) != 1.0
                                        || *(_DWORD *)(i5 + 8) != -1 )
                                      {
                                        break;
                                      }
                                      v254 = ii;
                                      v255 = *(_DWORD *)(v251 + 4);
                                      v312[ii] = *(_DWORD *)(v250 + *((_DWORD *)i14 + 2));
                                      if ( v255 != *((_DWORD *)v328 + 34) )
                                        v315 = 1;
                                      i4 += 4;
                                      v250 += 4;
                                      ii = v254 + 1;
                                    }
                                    while ( v254 + 1 < v322 );
                                  }
                                  if ( ii == v322 )
                                    break;
                                  ++j;
                                  i3 += 4 * v322;
                                  v247 = i + m;
                                  m += i;
                                  if ( j >= 2 )
                                    goto LABEL_584;
                                  v184 = i14;
                                }
                                if ( v322 != 0 )
                                {
                                  v256 = *((_DWORD *)v328 + 5);
                                  v257 = (_DWORD *)(*((_DWORD *)i14 + 2) + 4 * v322 * j);
                                  for ( i20 = v322; i20 != 0; --i20 )
                                  {
                                    v259 = *(_DWORD *)(v256 + 4 * *v257);
                                    if ( *(_DWORD *)(v259 + 56) == -1 )
                                    {
                                      for ( i21 = 0; i21 < v316; ++i21 )
                                      {
                                        if ( *(_DWORD *)(v259 + 72) == v313[i21] )
                                          break;
                                      }
                                      if ( i21 == v316 && v315 == 0 )
                                      {
                                        v261 = v316;
                                        v262 = *(_DWORD *)(v259 + 72);
                                        ++v316;
                                        v313[v261] = v262;
                                      }
                                    }
                                    else
                                    {
                                      v315 = 1;
                                    }
                                    ++v257;
                                  }
                                }
LABEL_584:
                                if ( j == 2 )
                                  return 1;
                                v326 = (unsigned int)v312;
                                v131 = 0;
                              }
                            }
                            if ( n != nullptr )
                              D3DXShader::CInstruction::`scalar deleting destructor'(this: n, a2: 1);
                            goto LABEL_588;
                          }
                          ii = 0;
                          if ( v322 == 0 )
                            goto LABEL_589;
                          while ( 1 )
                          {
                            i3 = 0;
                            v225 = &v309[v224 + 8];
                            v253 = *(v225 - 12) == *(v225 - 4);
                            n = *(v225 - 12);
                            if ( !v253 )
                              return 1;
                            v253 = *(v225 - 8) == *v225;
                            i4 = (unsigned int)*(v225 - 8);
                            if ( !v253 )
                              return 1;
                            v226 = v225[4];
                            if ( v226 != v225[12] )
                              return 1;
                            v227 = v225[8];
                            if ( v227 != v225[16] )
                              return 1;
                            v228 = *((_DWORD *)v328 + 5);
                            v229 = *(_DWORD *)(v228 + 4 * (_DWORD)v226);
                            v230 = *(_DWORD *)(v228 + 4 * (_DWORD)v227);
                            v231 = *((_DWORD *)v328 + 4);
                            v232 = *(_DWORD *)(v231 + 4 * *(_DWORD *)(v229 + 4));
                            i14 = nullptr;
                            m = v232;
                            v233 = *(_DWORD *)(v231 + 4 * *(_DWORD *)(v230 + 4));
                            if ( v226 == (struct D3DXShader::CInstruction *)i4
                              && (*(_BYTE *)(v233 + 5) & 1) != 0
                              && *(double *)(v230 + 32) == -1.0
                              || v227 == (struct D3DXShader::CInstruction *)i4
                              && (*(_BYTE *)(m + 5) & 1) != 0
                              && *(double *)(v229 + 32) == -1.0 )
                            {
                              i14 = (struct D3DXShader::CInstruction *)1;
                            }
                            v326 = (unsigned int)v309;
                            if ( i14 == nullptr )
                            {
                              v234 = *(_DWORD *)(*((_DWORD *)v328 + 5) + 4 * (_DWORD)n);
                              v235 = *(D3DXShader::CInstruction **)(v229 + 56);
                              if ( (v235 == n
                                 || v235 != (D3DXShader::CInstruction *)-1
                                 && *(D3DXShader::CInstruction **)(v234 + 56) == v235)
                                && *(_DWORD *)(v229 + 60) == (*(_DWORD *)(v234 + 60) ^ 0x80000)
                                && (*(_BYTE *)(v233 + 5) & 1) != 0
                                && *(double *)(v230 + 32) == 1.0 )
                              {
                                i14 = (struct D3DXShader::CInstruction *)1;
                              }
                              v236 = *(D3DXShader::CInstruction **)(v230 + 56);
                              if ( (v236 == n
                                 || v236 != (D3DXShader::CInstruction *)-1
                                 && *(D3DXShader::CInstruction **)(v234 + 56) == v236)
                                && *(_DWORD *)(v230 + 60) == (*(_DWORD *)(v234 + 60) ^ 0x80000)
                                && (*(_BYTE *)(m + 5) & 1) != 0
                                && *(double *)(v229 + 32) == 1.0 )
                              {
                                result = 1;
                                i14 = (struct D3DXShader::CInstruction *)1;
                              }
                              else
                              {
                                result = 1;
                              }
                              i3 = 1;
                              if ( i14 == nullptr )
                                return result;
                              v326 = (unsigned int)v308;
                            }
                            v238 = *((_DWORD *)v328 + 5);
                            v239 = *(_DWORD *)(v238 + 4 * v307[ii + 80]);
                            if ( i3 != 0 )
                              v240 = *(_DWORD *)(v238 + 4 * i4);
                            else
                              v240 = *(_DWORD *)(v238 + 4 * (_DWORD)n);
                            v241 = *((_DWORD *)v328 + 4);
                            if ( (*(_BYTE *)(*(_DWORD *)(v241 + 4 * *(_DWORD *)(v239 + 4)) + 5) & 1) == 0
                              || *(double *)(v239 + 32) != 0.0
                              || (*(_BYTE *)(*(_DWORD *)(v241 + 4 * *(_DWORD *)(v240 + 4)) + 5) & 1) == 0
                              || *(double *)(v240 + 32) != 1.0 )
                            {
                              return 1;
                            }
                            v242 = ii;
                            v243 = *(_DWORD *)(v238 + 4 * *(_DWORD *)(v326 + 4 * ii));
                            if ( *(_DWORD *)(v243 + 4) != *((_DWORD *)v328 + 34) )
                              v315 = 1;
                            v244 = v316;
                            for ( i22 = 0; i22 < v316; ++i22 )
                            {
                              if ( *(_DWORD *)(v243 + 72) == v313[i22] )
                                break;
                            }
                            if ( i22 == v316 && v315 == 0 )
                            {
                              v313[v316] = *(_DWORD *)(v243 + 72);
                              v316 = v244 + 1;
                            }
                            v224 = v242 + 1;
                            ii = v224;
                            if ( v224 >= v322 )
                              goto LABEL_589;
                          }
                        }
                      }
                      if ( ++k == 0 )
                        continue;
                      break;
                    }
                    if ( ++i != 0 )
                      goto LABEL_505;
                    continue;
                  }
                }
              }
              if ( ++k == 0 )
                continue;
              break;
            }
            if ( ++i != 0 )
              goto LABEL_388;
            continue;
          }
        }
      }
      if ( ++k < 2 )
        continue;
      break;
    }
    if ( ++kk != 0 )
      goto LABEL_176;
    continue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10218AA8
// Name: protected: long D3DXShader::CShaderProgram::CompressOrigin(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::CompressOrigin(D3DXShader::CShaderProgram *this)
{
  unsigned int i; // ebx
  int v3; // eax
  D3DXShader::CArgument *v4; // ecx
  int v5; // esi
  struct D3DXShader::CArgument *v6; // eax
  int v7; // edx

  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    v3 = *((_DWORD *)this + 5);
    v4 = *(D3DXShader::CArgument **)(v3 + 4 * i);
    v5 = *((_DWORD *)v4 + 14);
    if ( v5 != -1 )
    {
      v6 = *(struct D3DXShader::CArgument **)(v3 + 4 * v5);
      v7 = *((_DWORD *)v4 + 14);
      while ( *((_DWORD *)v6 + 14) != -1 )
      {
        *((_DWORD *)v4 + 15) |= *((_DWORD *)v6 + 15);
        v7 = *((_DWORD *)v6 + 14);
        v6 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v7);
      }
      if ( v5 != v7 )
      {
        *((_DWORD *)v4 + 14) = v7;
        D3DXShader::CArgument::Instance(this: v4, a2: v6);
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10218AF9
// Name: protected: long D3DXShader::CShaderProgram::MatchRepMov(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchRepMov(D3DXShader::CShaderProgram *this)
{
  int v2; // eax
  void *v3; // ecx
  int v4; // ecx
  _DWORD *v5; // eax
  int v6; // edx
  D3DXShader::CInstruction *v8; // esi
  _DWORD *v9; // ebx
  _DWORD *v10; // edx
  unsigned int v11; // edx
  _DWORD *v12; // eax
  int v13; // ebx
  unsigned __int8 *v14; // eax
  int v15; // edi
  int v16; // ecx
  char *v17; // esi
  char *v18; // edi
  char v19; // al
  unsigned int v20; // ecx
  char *v21; // edi
  char *v22; // esi
  D3DXShader::CProgram *v23; // eax
  unsigned int v24; // ecx
  int v25; // ecx
  int v26; // edx
  int v27; // edi
  int v28; // edx
  int v29; // ecx
  int *v30; // esi
  int v31; // edx
  D3DXShader::CInstruction *v32; // ecx
  int v33; // [esp+4h] [ebp-1Ch]
  int v34; // [esp+8h] [ebp-18h]
  D3DXShader::CInstruction *v35; // [esp+Ch] [ebp-14h]
  D3DXShader::CProgram *v36; // [esp+10h] [ebp-10h]
  int v37; // [esp+14h] [ebp-Ch]
  unsigned int v38; // [esp+14h] [ebp-Ch]
  unsigned int v39; // [esp+18h] [ebp-8h]
  unsigned int v40; // [esp+18h] [ebp-8h]
  int v41; // [esp+1Ch] [ebp-4h]
  unsigned int v42; // [esp+1Ch] [ebp-4h]

  v2 = *((_DWORD *)this + 64);
  v3 = (void *)(*(_DWORD *)v2 & 0xFFF00000);
  v36 = this;
  if ( v3 != (void *)1342177280
    && v3 != (void *)273678336
    && v3 != (void *)274726912
    && v3 != &unk_10300000
    && v3 != (void *)275775488 )
  {
    return 1;
  }
  if ( *(_DWORD *)(v2 + 12) != 1 )
    return 1;
  v4 = *((_DWORD *)this + 5);
  v41 = 0;
  v34 = **(_DWORD **)(v2 + 16);
  v5 = *(_DWORD **)(v4 + 4 * v34);
  v6 = v5[21];
  if ( v6 == -1 )
    return 1;
  v39 = 0;
  v8 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v6);
  v35 = v8;
  if ( *((_DWORD *)v8 + 3) != 0 )
  {
    v9 = *((_DWORD **)v8 + 4);
    v37 = *((_DWORD *)v8 + 3);
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)(v4 + 4 * *v9) + 76) > v39 )
        v39 = *(_DWORD *)(*(_DWORD *)(v4 + 4 * *v9) + 76);
      ++v9;
      --v37;
    }
    while ( v37 != 0 );
  }
  v10 = *(_DWORD **)(v4 + 4 * **((_DWORD **)v8 + 4));
  if ( v10[1] == v5[1] && v10[3] == v5[3] && v10[2] == v5[2] && v5[21] != v5[22] )
    v41 = 1;
  if ( v39 > *((_DWORD *)this + 63)
    || v41 == 0 && v5[21] != v5[22]
    || (*((_BYTE *)this + 108) & 1) != 0
    && (*((_DWORD *)v8 + 3) == 0
     || *(_DWORD *)(*(_DWORD *)(v4 + 4 * **((_DWORD **)v8 + 4)) + 4) == *((_DWORD *)this + 33))
    || (*(_DWORD *)v8 & 0xFFF00000) != 0x10000000
    || (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v10[1]) + 4) & 4) != 0 )
  {
    return 1;
  }
  v11 = 0;
  if ( *((_DWORD *)v8 + 1) != 0 )
  {
    v12 = *((_DWORD **)v8 + 2);
    while ( *v12 == v34 )
    {
      ++v11;
      ++v12;
      if ( v11 >= *((_DWORD *)v8 + 1) )
        goto LABEL_31;
    }
    return 1;
  }
LABEL_31:
  v13 = 0;
  if ( *(_DWORD *)(*(_DWORD *)(v4 + 4 * **((_DWORD **)v8 + 2)) + 60) != 0 )
    return 1;
  v14 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v14 != nullptr )
    v13 = D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v14);
  if ( v13 == 0 )
    return -2147024882;
  v15 = D3DXShader::CInstruction::Initialize(
          this: (D3DXShader::CInstruction *)v13,
          a2: **((_DWORD **)this + 64),
          a3: *(_DWORD *)(*((_DWORD *)this + 64) + 4),
          a4: *((_DWORD *)v8 + 3) + (v41 != 0),
          a5: 1);
  if ( v15 >= 0 )
  {
    v16 = *((_DWORD *)v8 + 3);
    v17 = *((char **)v8 + 4);
    v18 = *(char **)(v13 + 16);
    v19 = 4 * v16;
    v20 = (unsigned int)(4 * v16) >> 2;
    qmemcpy(v18, v17, 4 * v20);
    v22 = &v17[4 * v20];
    v21 = &v18[4 * v20];
    LOBYTE(v20) = v19;
    v23 = v36;
    qmemcpy(v21, v22, v20 & 3);
    if ( v41 != 0 )
      *(_DWORD *)(*(_DWORD *)(v13 + 16) + 4 * *((_DWORD *)v35 + 3)) = **(_DWORD **)(*((_DWORD *)v36 + 64) + 16);
    v24 = *(_DWORD *)(v13 + 12);
    v42 = 0;
    if ( v24 != 0 )
    {
      v38 = 1;
      while ( 1 )
      {
        v40 = v38;
        if ( v38 < v24 )
          break;
LABEL_48:
        ++v42;
        v24 = *(_DWORD *)(v13 + 12);
        ++v38;
        if ( v42 >= v24 )
          goto LABEL_49;
      }
      while ( 1 )
      {
        v25 = *(_DWORD *)(v13 + 16);
        v26 = *((_DWORD *)v36 + 5);
        v27 = *(_DWORD *)(v26 + 4 * *(_DWORD *)(v25 + 4 * v42));
        v28 = *(_DWORD *)(v26 + 4 * *(_DWORD *)(4 * v40 + v25));
        v33 = v28;
        if ( *(_DWORD *)(v27 + 16) > *(_DWORD *)(v28 + 16) )
        {
          v29 = *(_DWORD *)(v13 + 16);
          v30 = (int *)(v29 + 4 * v40);
          v31 = *v30;
          *v30 = *(_DWORD *)(v29 + 4 * v42);
          *(_DWORD *)(*(_DWORD *)(v13 + 16) + 4 * v42) = v31;
          v28 = v33;
        }
        if ( *(_DWORD *)(v27 + 16) == *(_DWORD *)(v28 + 16) )
          break;
        if ( ++v40 >= *(_DWORD *)(v13 + 12) )
          goto LABEL_48;
      }
      D3DXShader::CProgram::Error(
        this: v36,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)v36 + 64) + 60),
        a3: 0x12D6u,
        format: "internal error: multiple write to same output");
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v35, a2: 1);
      return -2147467259;
    }
    else
    {
LABEL_49:
      qmemcpy(
        *(void **)(v13 + 8),
        *(const void **)(*((_DWORD *)v36 + 64) + 8),
        4 * *(_DWORD *)(*((_DWORD *)v36 + 64) + 4));
      v32 = *(D3DXShader::CInstruction **)(*((_DWORD *)v36 + 6) + 4 * *((_DWORD *)v36 + 63));
      if ( v32 != nullptr )
      {
        D3DXShader::CInstruction::`scalar deleting destructor'(this: v32, a2: 1);
        v23 = v36;
      }
      *(_DWORD *)(*((_DWORD *)v23 + 6) + 4 * *((_DWORD *)v23 + 63)) = v13;
      *(_DWORD *)v35 = 0;
      return 0;
    }
  }
  else
  {
    D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v13, a2: 1);
    return v15;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10218DE7
// Name: protected: long D3DXShader::CShaderProgram::MatchIF2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchIF2(struct D3DXShader::CInstruction **this)
{
  D3DXShader::CShaderProgram *v1; // esi
  unsigned int v2; // ebx
  unsigned __int8 *v3; // eax
  void **v4; // edi
  int v5; // eax
  unsigned __int8 *v6; // eax
  D3DXShader::CInstruction *v7; // ecx
  unsigned int v8; // eax
  void **v9; // ebx
  unsigned int v10; // eax
  unsigned int *v11; // esi
  int result; // eax
  int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // edi
  int v17; // ecx
  int v18; // ecx
  unsigned __int8 *v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  char *v22; // edi
  char *v23; // edi
  unsigned int *v24; // esi
  char v25; // cl
  D3DXShader::CShaderProgram *v26; // eax
  int v27; // esi
  struct D3DXShader::CInstruction *v28; // [esp-20h] [ebp-13Ch]
  struct D3DXShader::CInstruction *v29[16]; // [esp+Ch] [ebp-110h] BYREF
  unsigned int v30[4]; // [esp+4Ch] [ebp-D0h] BYREF
  _DWORD v31[4]; // [esp+5Ch] [ebp-C0h] BYREF
  _DWORD v32[4]; // [esp+6Ch] [ebp-B0h] BYREF
  _DWORD v33[28]; // [esp+7Ch] [ebp-A0h] BYREF
  unsigned int v34[4]; // [esp+ECh] [ebp-30h] BYREF
  unsigned int v35[4]; // [esp+FCh] [ebp-20h] BYREF
  D3DXShader::CShaderProgram *v36; // [esp+10Ch] [ebp-10h]
  unsigned int v37; // [esp+110h] [ebp-Ch] BYREF
  struct D3DXShader::CInstruction *v38; // [esp+114h] [ebp-8h]
  int v39; // [esp+118h] [ebp-4h]

  v37 = 0;
  v35[0] = 0;
  v1 = (D3DXShader::CShaderProgram *)this;
  v2 = *(_DWORD *)*(this + 64) & 0xFFFFF;
  v28 = *(this + 64);
  v36 = (D3DXShader::CShaderProgram *)this;
  v35[1] = 1;
  v35[2] = 2;
  v35[3] = 3;
  if ( D3DXShader::CShaderProgram::MatchComplexTree(
         (D3DXShader::CShaderProgram *)this,
         a2: v28,
         a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDBA0,
         a4: v29,
         a5: &v37,
         a6: v30,
         a7: v35,
         a8: v2,
         a9: 1) == 0 )
  {
    v3 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v3 != nullptr )
    {
      v4 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v3);
      v38 = (struct D3DXShader::CInstruction *)v4;
    }
    else
    {
      v38 = nullptr;
      v4 = nullptr;
    }
    if ( v4 != nullptr )
    {
      v5 = D3DXShader::CInstruction::Initialize(
             this: (D3DXShader::CInstruction *)v4,
             a2: v2 & 0xFFFFF | 0x73600000,
             a3: 2 * v2,
             a4: v2,
             a5: 0);
LABEL_13:
      v39 = v5;
      v7 = (D3DXShader::CInstruction *)v4;
      if ( v5 < 0 )
      {
LABEL_56:
        D3DXShader::CInstruction::`scalar deleting destructor'(this: v7, a2: 1);
        return v39;
      }
      v39 = D3DXShader::CInstruction::Instance(
              this: (D3DXShader::CInstruction *)v4,
              a2: *((struct D3DXShader::CInstruction **)v1 + 64));
      if ( v39 >= 0 )
      {
        v8 = v2;
        v9 = (void **)v38;
        v10 = 4 * v8;
        qmemcpy(v4[4], *(const void **)(*((_DWORD *)v1 + 64) + 16), v10);
        qmemcpy(v9[2], v30, v10);
        v11 = v31;
LABEL_58:
        v22 = (char *)v9[2] + v10;
        qmemcpy(v22, v11, 4 * (v10 >> 2));
        v24 = &v11[v10 >> 2];
        v23 = &v22[4 * (v10 >> 2)];
        v25 = v10;
        v26 = v36;
        qmemcpy(v23, v24, v25 & 3);
        v27 = D3DXShader::CInstruction::Initialize(
                this: *((D3DXShader::CInstruction **)v26 + 64),
                a2: (struct D3DXShader::CInstruction *)v9);
        D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v9, a2: 1);
        return v27;
      }
LABEL_55:
      v7 = (D3DXShader::CInstruction *)v4;
      goto LABEL_56;
    }
    return -2147024882;
  }
  if ( D3DXShader::CShaderProgram::MatchComplexTree(
         this: v1,
         a2: *((struct D3DXShader::CInstruction **)v1 + 64),
         a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDC00,
         a4: v29,
         a5: &v37,
         a6: v30,
         a7: v35,
         a8: v2,
         a9: 1) == 0 )
  {
    v6 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v6 != nullptr )
    {
      v4 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v6);
      v38 = (struct D3DXShader::CInstruction *)v4;
    }
    else
    {
      v38 = nullptr;
      v4 = nullptr;
    }
    if ( v4 != nullptr )
    {
      v5 = D3DXShader::CInstruction::Initialize(
             this: (D3DXShader::CInstruction *)v4,
             a2: v2 & 0xFFFFF | 0x73500000,
             a3: 2 * v2,
             a4: v2,
             a5: 0);
      goto LABEL_13;
    }
    return -2147024882;
  }
  result = D3DXShader::CShaderProgram::MatchComplexTree(
             this: v1,
             a2: *((struct D3DXShader::CInstruction **)v1 + 64),
             a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDC60,
             a4: v29,
             a5: &v37,
             a6: v30,
             a7: v35,
             a8: v2,
             a9: 1);
  if ( result != 0 )
    return result;
  v13 = *((_DWORD *)v1 + 5);
  if ( *(_DWORD *)(*(_DWORD *)(v13 + 4 * v32[0]) + 60) == 0x80000 )
  {
    v14 = 0;
    if ( v2 != 0 )
    {
      qmemcpy(v35, v33, 4 * v2);
      do
      {
        v34[v14] = *(_DWORD *)(*(_DWORD *)(v13 + 4 * v32[v14]) + 56);
        ++v14;
      }
      while ( v14 < v2 );
LABEL_26:
      v1 = v36;
      goto LABEL_27;
    }
    goto LABEL_27;
  }
  if ( *(_DWORD *)(*(_DWORD *)(v13 + 4 * v33[0]) + 60) == 0x80000 )
  {
    v15 = 0;
    if ( v2 != 0 )
    {
      qmemcpy(v35, v32, 4 * v2);
      do
      {
        v34[v15] = *(_DWORD *)(*(_DWORD *)(v13 + 4 * v33[v15]) + 56);
        ++v15;
      }
      while ( v15 < v2 );
      goto LABEL_26;
    }
LABEL_27:
    v38 = nullptr;
    v37 = 1;
    v39 = 1;
    if ( v2 != 0 )
    {
      v16 = *((_DWORD *)v1 + 4);
      do
      {
        v17 = *(_DWORD *)(v13 + 4 * v30[(_DWORD)v38]);
        if ( (*(_BYTE *)(*(_DWORD *)(v16 + 4 * *(_DWORD *)(v17 + 4)) + 5) & 1) == 0 )
        {
          v39 = 0;
          v37 = 0;
        }
        if ( *(double *)(v17 + 32) != 0.0 )
          v39 = 0;
        if ( *(double *)(v17 + 32) != 1.0 )
          v37 = 0;
        v18 = *(_DWORD *)(v13 + 4 * v31[(_DWORD)v38]);
        if ( (*(_BYTE *)(*(_DWORD *)(v16 + 4 * *(_DWORD *)(v18 + 4)) + 5) & 1) == 0 )
        {
          v39 = 0;
          v37 = 0;
        }
        if ( *(double *)(v18 + 32) != 1.0 )
          v39 = 0;
        if ( *(double *)(v18 + 32) != 0.0 )
          v37 = 0;
        v38 = (struct D3DXShader::CInstruction *)((char *)v38 + 1);
      }
      while ( (unsigned int)v38 < v2 );
      if ( v39 == 0 && v37 == 0 )
        return 1;
    }
    v19 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v19 != nullptr )
    {
      v4 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v19);
      v38 = (struct D3DXShader::CInstruction *)v4;
    }
    else
    {
      v38 = nullptr;
      v4 = nullptr;
    }
    if ( v4 != nullptr )
    {
      if ( v39 != 0 )
        v20 = v2 | 0x73600000;
      else
        v20 = v2 | 0x73500000;
      v39 = D3DXShader::CInstruction::Initialize(
              this: (D3DXShader::CInstruction *)v4,
              a2: v20,
              a3: 2 * v2,
              a4: v2,
              a5: 0);
      v7 = (D3DXShader::CInstruction *)v4;
      if ( v39 < 0 )
        goto LABEL_56;
      v39 = D3DXShader::CInstruction::Instance(
              this: (D3DXShader::CInstruction *)v4,
              a2: *((struct D3DXShader::CInstruction **)v1 + 64));
      if ( v39 >= 0 )
      {
        v21 = v2;
        v9 = (void **)v38;
        v10 = 4 * v21;
        qmemcpy(v4[4], *(const void **)(*((_DWORD *)v1 + 64) + 16), v10);
        qmemcpy(v9[2], v35, v10);
        v11 = v34;
        goto LABEL_58;
      }
      goto LABEL_55;
    }
    return -2147024882;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102191DD
// Name: protected: long D3DXShader::CShaderProgram::MatchIF(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchIF(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *v2; // eax
  int v3; // ebx
  unsigned int v4; // ebx
  int result; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // edi
  int v9; // edx
  unsigned __int8 *v10; // eax
  int v11; // eax
  D3DXShader::CBaseProgram *v12; // esi
  unsigned int v13; // eax
  int v14; // esi
  int v15; // ecx
  struct D3DXShader::CInstruction *v16; // [esp+14h] [ebp-108h] BYREF
  unsigned int v17[40]; // [esp+54h] [ebp-C8h] BYREF
  unsigned int v18[4]; // [esp+F4h] [ebp-28h] BYREF
  D3DXShader::CBaseProgram *v19; // [esp+104h] [ebp-18h]
  int v20; // [esp+108h] [ebp-14h]
  unsigned int v21; // [esp+10Ch] [ebp-10h]
  int v22; // [esp+110h] [ebp-Ch]
  unsigned int v23; // [esp+114h] [ebp-8h] BYREF
  D3DXShader::CInstruction *v24; // [esp+118h] [ebp-4h]

  v2 = *((struct D3DXShader::CInstruction **)this + 64);
  v3 = *(_DWORD *)v2;
  v18[1] = 1;
  v4 = v3 & 0xFFFFF;
  v19 = this;
  v23 = 0;
  v18[0] = 0;
  v18[2] = 2;
  v18[3] = 3;
  result = D3DXShader::CShaderProgram::MatchComplexTree(
             this,
             a2: v2,
             a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD800,
             a4: &v16,
             a5: &v23,
             a6: v17,
             a7: v18,
             a8: v4,
             a9: 1);
  if ( result == 0 )
  {
    v23 = 0;
    v22 = 0;
    v21 = 0;
    v24 = nullptr;
    if ( v4 != 0 )
    {
      v6 = *((_DWORD *)this + 5);
      v7 = *(_DWORD *)(v6 + 4 * v17[4]);
      v8 = *(_DWORD *)(v6 + 4 * v17[8]);
      v9 = *((_DWORD *)this + 4);
      v20 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)(v7 + 4)) + 4) & 0x100;
      do
      {
        if ( v20 == 0
          || (*(_BYTE *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)(v8 + 4)) + 5) & 1) == 0
          || *(_DWORD *)(v7 + 8) != -1
          || *(_DWORD *)(v8 + 8) != -1 )
        {
          return 1;
        }
        if ( *(double *)(v7 + 32) == 1.0 && *(double *)(v8 + 32) == 0.0 )
        {
          v23 = 1;
        }
        else
        {
          if ( *(double *)(v8 + 32) != 1.0 || *(double *)(v7 + 32) != 0.0 )
            return 1;
          v22 = 1;
        }
        v24 = (D3DXShader::CInstruction *)((char *)v24 + 1);
      }
      while ( (unsigned int)v24 < v4 );
      if ( v23 != 0 )
      {
        if ( v22 != 0 )
          return 1;
        v21 = v4 & 0xFFFFF | 0x73500000;
      }
      if ( v22 != 0 )
        v21 = v4 & 0xFFFFF | 0x73600000;
    }
    v10 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v10 != nullptr )
      v24 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v10);
    else
      v24 = nullptr;
    if ( v24 == nullptr )
      return -2147024882;
    v11 = D3DXShader::CInstruction::Initialize(this: v24, a2: v21, a3: 2 * v4, a4: v4, a5: 0);
    if ( v11 >= 0 )
    {
      v11 = D3DXShader::CInstruction::Instance(this: v24, a2: *((struct D3DXShader::CInstruction **)this + 64));
      if ( v11 >= 0 )
      {
        qmemcpy(*((void **)v24 + 4), *(const void **)(*((_DWORD *)this + 64) + 16), 4 * ((4 * v4) >> 2));
        qmemcpy(*((void **)v24 + 2), v17, 4 * ((4 * v4) >> 2));
        v12 = v19;
        v13 = D3DXShader::CBaseProgram::AddArgument(this: v19, a2: *((_DWORD *)v19 + 30), a3: 0, a4: 0, a5: 0.0);
        if ( v13 == -1 )
        {
          v14 = -2147024882;
LABEL_35:
          D3DXShader::CInstruction::`scalar deleting destructor'(this: v24, a2: 1);
          return v14;
        }
        if ( v4 != 0 )
        {
          v15 = 4 * v4;
          do
          {
            *(_DWORD *)(v15 + *((_DWORD *)v24 + 2)) = v13;
            v15 += 4;
            --v4;
          }
          while ( v4 != 0 );
        }
        v11 = D3DXShader::CInstruction::Initialize(this: *((D3DXShader::CInstruction **)v12 + 64), a2: v24);
      }
    }
    v14 = v11;
    goto LABEL_35;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10219437
// Name: protected: long D3DXShader::CShaderProgram::MatchNEZero(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchNEZero(D3DXShader::CShaderProgram *this)
{
  _DWORD *v2; // eax
  int result; // eax
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  struct D3DXShader::CArgument *v7; // ebx
  D3DXShader::CArgument *v8; // edi
  unsigned int v9; // [esp+14h] [ebp-4h]

  v2 = *((_DWORD **)this + 64);
  if ( (*v2 & 0xFFFFF) != 1 )
    return 1;
  v4 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v2[2] + 4));
  if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v4 + 4)) + 5) & 1) == 0
    || *(_DWORD *)(v4 + 8) != -1
    || *(double *)(v4 + 32) != 0.0 )
  {
    return 1;
  }
  v5 = D3DXShader::CBaseProgram::AddArgument(this, a2: 0, a3: 0, a4: 0, a5: 0.0);
  v9 = v5;
  if ( v5 == -1 )
    return -2147024882;
  v6 = *((_DWORD *)this + 5);
  v7 = *(struct D3DXShader::CArgument **)(v6 + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 8));
  v8 = *(D3DXShader::CArgument **)(v6 + 4 * v5);
  result = D3DXShader::CArgument::Initialize(this: v8, a2: v7);
  if ( result >= 0 )
  {
    result = D3DXShader::CArgument::Instance(this: v8, a2: v7);
    if ( result >= 0 )
    {
      *((_DWORD *)v8 + 15) ^= 0x80000u;
      if ( *((_DWORD *)v8 + 14) == -1 )
        *((_DWORD *)v8 + 14) = **(_DWORD **)(*((_DWORD *)this + 64) + 8);
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4) = v9;
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021951E
// Name: protected: long D3DXShader::CShaderProgram::MatchNEEQ(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchNEEQ(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *v2; // eax
  int v3; // esi
  unsigned int v4; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // ecx
  int v9; // ecx
  struct D3DXShader::CInstruction *v10; // [esp-20h] [ebp-128h]
  unsigned int v11[40]; // [esp+Ch] [ebp-FCh] BYREF
  struct D3DXShader::CInstruction *v12[16]; // [esp+ACh] [ebp-5Ch] BYREF
  unsigned int v13[4]; // [esp+ECh] [ebp-1Ch] BYREF
  int v14; // [esp+FCh] [ebp-Ch]
  unsigned int v15; // [esp+100h] [ebp-8h]
  unsigned int v16; // [esp+104h] [ebp-4h] BYREF

  v2 = *((struct D3DXShader::CInstruction **)this + 64);
  v3 = *(_DWORD *)v2;
  v16 = 0;
  v13[0] = 0;
  v14 = 0;
  v4 = v3 & 0xFFFFF;
  v13[1] = 1;
  v13[2] = 2;
  v13[3] = 3;
  result = D3DXShader::CShaderProgram::MatchComplexTree(
             this,
             a2: v2,
             a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD9E0,
             a4: v12,
             a5: &v16,
             a6: v11,
             a7: v13,
             a8: v4,
             a9: 1);
  if ( result == 1 )
  {
    v10 = *((struct D3DXShader::CInstruction **)this + 64);
    v14 = 1;
    result = D3DXShader::CShaderProgram::MatchComplexTree(
               this,
               a2: v10,
               a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDA40,
               a4: v12,
               a5: &v16,
               a6: v11,
               a7: v13,
               a8: v4,
               a9: 1);
  }
  if ( result == 0 )
  {
    v15 = 0;
    if ( v4 != 0 )
    {
      v16 = 4 * v4;
      while ( v11[v15 + 4] == v11[v15 + 8] )
      {
        v6 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v16 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)));
        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v6 + 4)) + 5) & 1) == 0
          || *(double *)(v6 + 32) != 0.0
          || *(_DWORD *)(v6 + 8) != -1 )
        {
          break;
        }
        ++v15;
        v16 += 4;
        if ( v15 >= v4 )
          goto LABEL_11;
      }
      return 1;
    }
    else
    {
LABEL_11:
      v7 = 0;
      v8 = v4 & 0xFFFFF;
      if ( v14 != 0 )
        v9 = v8 | 0x73700000;
      else
        v9 = v8 | 0x73800000;
      **((_DWORD **)this + 64) = v9;
      if ( v4 != 0 )
      {
        do
        {
          *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * v7) = v11[v7 + 4];
          ++v7;
        }
        while ( v7 < v4 );
      }
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021966C
// Name: protected: long D3DXShader::CShaderProgram::MatchNEEQ2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchNEEQ2(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *v2; // eax
  int v3; // edi
  unsigned int v4; // edi
  int result; // eax
  unsigned int v6; // edx
  unsigned int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ebx
  struct D3DXShader::CInstruction *v14; // [esp-18h] [ebp-124h]
  struct D3DXShader::CInstruction *v15[16]; // [esp+14h] [ebp-F8h] BYREF
  unsigned int v16[40]; // [esp+54h] [ebp-B8h] BYREF
  unsigned int v17[4]; // [esp+F4h] [ebp-18h] BYREF
  unsigned int v18; // [esp+104h] [ebp-8h]
  unsigned int v19; // [esp+108h] [ebp-4h] BYREF

  v2 = *((struct D3DXShader::CInstruction **)this + 64);
  v3 = *(_DWORD *)v2;
  v19 = 0;
  v17[0] = 0;
  v18 = 0;
  v4 = v3 & 0xFFFFF;
  v17[1] = 1;
  v17[2] = 2;
  v17[3] = 3;
  result = D3DXShader::CShaderProgram::MatchComplexTree(
             this,
             a2: v2,
             a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDAA0,
             a4: v15,
             a5: &v19,
             a6: v16,
             a7: v17,
             a8: v4,
             a9: 1);
  if ( result == 1 )
  {
    v14 = *((struct D3DXShader::CInstruction **)this + 64);
    v18 = 1;
    result = D3DXShader::CShaderProgram::MatchComplexTree(
               this,
               a2: v14,
               a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDB20,
               a4: v15,
               a5: &v19,
               a6: v16,
               a7: v17,
               a8: v4,
               a9: 1);
  }
  if ( result == 0 )
  {
    v19 = 0;
    if ( v4 != 0 )
    {
      while ( 1 )
      {
        v6 = v16[v19];
        v7 = v16[v19 + 4];
        if ( v6 != v7 || v7 != v16[v19 + 8] || v6 != v16[v19 + 12] )
          return 1;
        if ( ++v19 >= v4 )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      v8 = v4 & 0xFFFFF;
      if ( v18 != 0 )
        v9 = v8 | 0x73700000;
      else
        v9 = v8 | 0x73800000;
      **((_DWORD **)this + 64) = v9;
      v18 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 0.0);
      if ( v18 == -1 )
      {
        return -2147024882;
      }
      else
      {
        v10 = 0;
        if ( v4 != 0 )
        {
          v19 = 4 * v4;
          do
          {
            v11 = *(_DWORD *)(*((_DWORD *)this + 64) + 8);
            v12 = v16[v10];
            v13 = v19;
            v19 += 4;
            *(_DWORD *)(v11 + 4 * v10++) = v12;
            *(_DWORD *)(v13 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)) = v18;
          }
          while ( v10 < v4 );
        }
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102197CE
// Name: protected: long D3DXShader::CShaderProgram::MatchIFCOND(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchIFCOND(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *v2; // ecx
  int v3; // eax
  int result; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ebx
  _DWORD *v8; // ecx
  int v9; // edi
  int v10; // edx
  int v11; // ebx
  int v12; // edi
  unsigned int v13; // eax
  D3DXShader::CArgument *v14; // eax
  unsigned int v15[8]; // [esp+14h] [ebp-FCh] BYREF
  _DWORD v16[32]; // [esp+34h] [ebp-DCh]
  struct D3DXShader::CInstruction *v17[16]; // [esp+B4h] [ebp-5Ch] BYREF
  unsigned int v18[4]; // [esp+F4h] [ebp-1Ch] BYREF
  unsigned int v19; // [esp+104h] [ebp-Ch]
  D3DXShader::CArgument *v20; // [esp+108h] [ebp-8h]
  unsigned int v21; // [esp+10Ch] [ebp-4h] BYREF

  v2 = *((struct D3DXShader::CInstruction **)this + 64);
  v3 = *(_DWORD *)v2 & 0xFFFFF;
  v21 = 0;
  v18[0] = 0;
  v18[1] = 1;
  v18[2] = 2;
  v18[3] = 3;
  if ( v3 != 1 )
    return 1;
  result = D3DXShader::CShaderProgram::MatchComplexTree(
             this,
             a2: v2,
             a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD860,
             a4: v17,
             a5: &v21,
             a6: v15,
             a7: v18,
             a8: 1u,
             a9: 1);
  if ( result == 1 )
  {
    result = D3DXShader::CShaderProgram::MatchComplexTree(
               this,
               a2: *((struct D3DXShader::CInstruction **)this + 64),
               a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD8C0,
               a4: v17,
               a5: &v21,
               a6: v15,
               a7: v18,
               a8: 1u,
               a9: 1);
    if ( result == 1 )
    {
      result = D3DXShader::CShaderProgram::MatchComplexTree(
                 this,
                 a2: *((struct D3DXShader::CInstruction **)this + 64),
                 a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD920,
                 a4: v17,
                 a5: &v21,
                 a6: v15,
                 a7: v18,
                 a8: 1u,
                 a9: 1);
      if ( result == 1 )
        result = D3DXShader::CShaderProgram::MatchComplexTree(
                   this,
                   a2: *((struct D3DXShader::CInstruction **)this + 64),
                   a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD980,
                   a4: v17,
                   a5: &v21,
                   a6: v15,
                   a7: v18,
                   a8: 1u,
                   a9: 1);
    }
  }
  if ( result == 0 )
  {
    v5 = *(_DWORD *)(*((_DWORD *)this + 64) + 8);
    v6 = *((_DWORD *)this + 5);
    v21 = 0;
    v7 = *((_DWORD *)this + 4);
    v8 = (_DWORD *)(v5 + 4);
    do
    {
      v9 = *(_DWORD *)(v6 + 4 * *v8);
      if ( (*(_BYTE *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(v9 + 4)) + 5) & 1) == 0
        || *(double *)(v9 + 32) != 0.0
        || *(_DWORD *)(v9 + 8) != -1 )
      {
        return 1;
      }
      ++v21;
      ++v8;
    }
    while ( v21 == 0 );
    v10 = *(_DWORD *)(v6 + 4 * v16[0]);
    v21 = 0;
    if ( *(_DWORD *)(v10 + 8) == -1 )
      v21 = (*(_BYTE *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(v10 + 4)) + 5) & 1) != 0;
    v11 = 0;
    while ( 1 )
    {
      *(_DWORD *)(v11 * 4 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)) = v15[v11 + 4];
      v12 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v16[v11]);
      v13 = D3DXShader::CBaseProgram::AddArgument(
              this,
              a2: *(_DWORD *)(v12 + 4),
              a3: *(_DWORD *)(v12 + 12),
              a4: *(_DWORD *)(v12 + 16),
              a5: *(double *)(v12 + 32));
      v19 = v13;
      if ( v13 == -1 )
        break;
      v20 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v13);
      D3DXShader::CArgument::Initialize(this: v20, a2: (struct D3DXShader::CArgument *)v12);
      v14 = v20;
      if ( v21 != 0 )
      {
        *((double *)v20 + 4) = *((double *)v20 + 4) * -1.0;
      }
      else
      {
        if ( *((_DWORD *)v20 + 14) == -1 )
          *((_DWORD *)v20 + 14) = v16[v11];
        *((_DWORD *)v14 + 15) ^= 0x80000u;
      }
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + v11 * 4 + 4) = v19;
      if ( (unsigned int)++v11 >= 1 )
        return 0;
    }
    return -2147024882;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102199E6
// Name: protected: long D3DXShader::CShaderProgram::MatchBREAK(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CShaderProgram::MatchBREAK(D3DXShader::CShaderProgram *this)
{
  unsigned int v2; // esi
  unsigned __int8 *v3; // eax
  void **v4; // edi
  signed int v5; // eax
  unsigned __int8 *v6; // eax
  D3DXShader::CInstruction *v7; // ecx
  unsigned int v8; // eax
  _DWORD *v9; // esi
  unsigned int result; // eax
  int v11; // edx
  int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  unsigned __int8 *v21; // eax
  int v22; // eax
  unsigned int v23; // eax
  struct D3DXShader::CInstruction *v24; // edx
  int v25; // esi
  struct D3DXShader::CInstruction *v26; // [esp-20h] [ebp-13Ch]
  struct D3DXShader::CInstruction *v27[16]; // [esp+Ch] [ebp-110h] BYREF
  unsigned int v28[4]; // [esp+4Ch] [ebp-D0h] BYREF
  _DWORD v29[4]; // [esp+5Ch] [ebp-C0h] BYREF
  _DWORD v30[4]; // [esp+6Ch] [ebp-B0h] BYREF
  _DWORD v31[28]; // [esp+7Ch] [ebp-A0h] BYREF
  _DWORD v32[4]; // [esp+ECh] [ebp-30h] BYREF
  int v33; // [esp+FCh] [ebp-20h]
  unsigned int v34[4]; // [esp+100h] [ebp-1Ch] BYREF
  unsigned int v35; // [esp+110h] [ebp-Ch]
  unsigned int v36; // [esp+114h] [ebp-8h] BYREF
  struct D3DXShader::CInstruction *v37; // [esp+118h] [ebp-4h]

  v36 = 0;
  v34[0] = 0;
  v2 = **((_DWORD **)this + 64) & 0xFFFFF;
  v26 = *((struct D3DXShader::CInstruction **)this + 64);
  v34[1] = 1;
  v34[2] = 2;
  v34[3] = 3;
  v35 = v2;
  if ( D3DXShader::CShaderProgram::MatchComplexTree(
         this,
         a2: v26,
         a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE080,
         a4: v27,
         a5: &v36,
         a6: v28,
         a7: v34,
         a8: v2,
         a9: 1) == 0 )
  {
    v3 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v3 != nullptr )
    {
      v4 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v3);
      v37 = (struct D3DXShader::CInstruction *)v4;
    }
    else
    {
      v37 = nullptr;
      v4 = nullptr;
    }
    if ( v4 != nullptr )
    {
      v5 = D3DXShader::CInstruction::Initialize(
             this: (D3DXShader::CInstruction *)v4,
             a2: v2 & 0xFFFFF | 0x74600000,
             a3: 2 * v2,
             a4: v2,
             a5: 0);
LABEL_13:
      v36 = v5;
      v7 = (D3DXShader::CInstruction *)v4;
      if ( v5 < 0 )
      {
LABEL_66:
        D3DXShader::CInstruction::`scalar deleting destructor'(this: v7, a2: 1);
        return v36;
      }
      v36 = D3DXShader::CInstruction::Instance(
              this: (D3DXShader::CInstruction *)v4,
              a2: *((struct D3DXShader::CInstruction **)this + 64));
      if ( (v36 & 0x80000000) == 0 )
      {
        v8 = 4 * v2;
        qmemcpy(v4[4], *(const void **)(*((_DWORD *)this + 64) + 16), 4 * v2);
        qmemcpy(*((void **)v37 + 2), v28, 4 * v2);
        v9 = v29;
LABEL_68:
        v24 = v37;
        qmemcpy((void *)(v8 + *((_DWORD *)v37 + 2)), v9, v8);
        v25 = D3DXShader::CInstruction::Initialize(this: *((D3DXShader::CInstruction **)this + 64), a2: v24);
        D3DXShader::CInstruction::`scalar deleting destructor'(this: v37, a2: 1);
        return v25;
      }
LABEL_65:
      v7 = (D3DXShader::CInstruction *)v4;
      goto LABEL_66;
    }
    return -2147024882;
  }
  if ( D3DXShader::CShaderProgram::MatchComplexTree(
         this,
         a2: *((struct D3DXShader::CInstruction **)this + 64),
         a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE020,
         a4: v27,
         a5: &v36,
         a6: v28,
         a7: v34,
         a8: v2,
         a9: 1) == 0 )
  {
    v6 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v6 != nullptr )
    {
      v4 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v6);
      v37 = (struct D3DXShader::CInstruction *)v4;
    }
    else
    {
      v37 = nullptr;
      v4 = nullptr;
    }
    if ( v4 != nullptr )
    {
      v5 = D3DXShader::CInstruction::Initialize(
             this: (D3DXShader::CInstruction *)v4,
             a2: v2 & 0xFFFFF | 0x74700000,
             a3: 2 * v2,
             a4: v2,
             a5: 0);
      goto LABEL_13;
    }
    return -2147024882;
  }
  result = D3DXShader::CShaderProgram::MatchComplexTree(
             this,
             a2: *((struct D3DXShader::CInstruction **)this + 64),
             a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE0E0,
             a4: v27,
             a5: &v36,
             a6: v28,
             a7: v34,
             a8: v2,
             a9: 1);
  if ( result != 0 )
    return result;
  v11 = *((_DWORD *)this + 5);
  v12 = *(_DWORD *)(v11 + 4 * v30[0]);
  v36 = *(_DWORD *)(v12 + 60);
  if ( v36 == 0x80000 )
  {
    v13 = 0;
    if ( v2 != 0 )
    {
      qmemcpy(v34, v31, 4 * v2);
      do
      {
        v32[v13] = *(_DWORD *)(*(_DWORD *)(v11 + 4 * v30[v13]) + 56);
        ++v13;
      }
      while ( v13 < v35 );
LABEL_26:
      v2 = v35;
    }
  }
  else
  {
    v37 = *(struct D3DXShader::CInstruction **)(v11 + 4 * v31[0]);
    v33 = *((_DWORD *)v37 + 15);
    if ( v33 == 0x80000 )
    {
      v14 = 0;
      if ( v2 != 0 )
      {
        qmemcpy(v34, v30, 4 * v2);
        do
        {
          v32[v14] = *(_DWORD *)(*(_DWORD *)(v11 + 4 * v31[v14]) + 56);
          ++v14;
        }
        while ( v14 < v35 );
        goto LABEL_26;
      }
    }
    else
    {
      if ( v2 != 1 )
        return 1;
      v15 = *(_DWORD *)(v12 + 72);
      if ( v15 == -1
        || (_UNKNOWN *)(*(_DWORD *)(v35 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v15)) & 0xFFF00000) != &loc_10100000
        || (*(_DWORD *)v35 & 0xFFFFF) != 1
        || v36 != 0 )
      {
        v17 = *((_DWORD *)v37 + 18);
        if ( v17 == -1 )
          return 1;
        v35 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v17);
        if ( (_UNKNOWN *)(*(_DWORD *)v35 & 0xFFF00000) != &loc_10100000 || (*(_DWORD *)v35 & 0xFFFFF) != 1 || v33 != 0 )
          return 1;
        v32[0] = **(_DWORD **)(v35 + 8);
        v16 = v30[0];
      }
      else
      {
        v32[0] = **(_DWORD **)(v35 + 8);
        v16 = v31[0];
      }
      v34[0] = v16;
    }
  }
  v37 = nullptr;
  v35 = 1;
  v36 = 1;
  if ( v2 != 0 )
  {
    do
    {
      v18 = *((_DWORD *)this + 5);
      v19 = *(_DWORD *)(v18 + 4 * v28[(_DWORD)v37]);
      if ( (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v19 + 4)) + 4) & 0x100) == 0 )
      {
        v36 = 0;
        v35 = 0;
      }
      if ( *(double *)(v19 + 32) != 1.0 )
        v36 = 0;
      if ( *(double *)(v19 + 32) != 0.0 )
        v35 = 0;
      v20 = *(_DWORD *)(v18 + 4 * v29[(_DWORD)v37]);
      if ( (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v20 + 4)) + 4) & 0x100) == 0 )
      {
        v36 = 0;
        v35 = 0;
      }
      if ( *(double *)(v20 + 32) != 0.0 )
        v36 = 0;
      if ( *(double *)(v20 + 32) != 1.0 )
        v35 = 0;
      v37 = (struct D3DXShader::CInstruction *)((char *)v37 + 1);
    }
    while ( (unsigned int)v37 < v2 );
    if ( v36 == 0 && v35 == 0 )
      return 1;
  }
  v21 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v21 != nullptr )
  {
    v4 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v21);
    v37 = (struct D3DXShader::CInstruction *)v4;
  }
  else
  {
    v37 = nullptr;
    v4 = nullptr;
  }
  if ( v4 != nullptr )
  {
    v22 = v2 & 0xFFFFF;
    if ( v36 != 0 )
      v23 = v22 | 0x74600000;
    else
      v23 = v22 | 0x74700000;
    v36 = D3DXShader::CInstruction::Initialize(this: (D3DXShader::CInstruction *)v4, a2: v23, a3: 2 * v2, a4: v2, a5: 0);
    v7 = (D3DXShader::CInstruction *)v4;
    if ( (v36 & 0x80000000) != 0 )
      goto LABEL_66;
    v36 = D3DXShader::CInstruction::Instance(
            this: (D3DXShader::CInstruction *)v4,
            a2: *((struct D3DXShader::CInstruction **)this + 64));
    if ( (v36 & 0x80000000) == 0 )
    {
      v8 = 4 * v2;
      qmemcpy(v4[4], *(const void **)(*((_DWORD *)this + 64) + 16), 4 * v2);
      qmemcpy(*((void **)v37 + 2), v34, 4 * v2);
      v9 = v32;
      goto LABEL_68;
    }
    goto LABEL_65;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x10219E9D
// Name: protected: long D3DXShader::CShaderProgram::FoldIterator(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::FoldIterator(D3DXShader::CShaderProgram *this)
{
  int v2; // eax
  unsigned __int8 *v4; // eax
  D3DXShader::CInstruction *v5; // ebx
  int v6; // edi
  unsigned int v7; // ecx
  unsigned int v8; // eax
  bool v9; // zf
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  unsigned int v13; // edi
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  unsigned int i; // edx
  int *v19; // eax
  int v20; // edi
  _DWORD *v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // edx
  unsigned int v25; // ecx
  unsigned int v26; // ebx
  bool v27; // cc
  _DWORD *v28; // eax
  int v29; // ecx
  int v30; // edi
  int v31; // edx
  int v32; // ecx
  int *v33; // ecx
  int v34; // eax
  _DWORD *v35; // ebx
  unsigned int v36; // eax
  int v37; // edi
  unsigned __int8 *v38; // eax
  D3DXShader::CInstruction *v39; // edi
  int v40; // ebx
  D3DXShader::CInstruction *v41; // ecx
  struct D3DXShader::CInstruction *v42; // eax
  int v43; // ebx
  struct D3DXShader::CInstruction *v44; // [esp+14h] [ebp-218h] BYREF
  struct D3DXShader::CInstruction *v45; // [esp+54h] [ebp-1D8h] BYREF
  unsigned int v46[40]; // [esp+94h] [ebp-198h] BYREF
  unsigned int v47[40]; // [esp+134h] [ebp-F8h] BYREF
  unsigned int v48[4]; // [esp+1D4h] [ebp-58h] BYREF
  unsigned int v49[4]; // [esp+1E4h] [ebp-48h] BYREF
  unsigned int v50; // [esp+1F4h] [ebp-38h]
  unsigned int v51; // [esp+1F8h] [ebp-34h]
  unsigned int v52; // [esp+1FCh] [ebp-30h]
  unsigned int v53; // [esp+200h] [ebp-2Ch]
  int v54; // [esp+204h] [ebp-28h]
  _DWORD *v55; // [esp+208h] [ebp-24h]
  D3DXShader::CInstruction *v56; // [esp+20Ch] [ebp-20h]
  int v57; // [esp+210h] [ebp-1Ch]
  int v58; // [esp+214h] [ebp-18h]
  struct D3DXShader::CInstruction *v59; // [esp+218h] [ebp-14h]
  unsigned int v60; // [esp+21Ch] [ebp-10h]
  unsigned int v61; // [esp+220h] [ebp-Ch] BYREF
  unsigned int v62; // [esp+224h] [ebp-8h]
  unsigned int v63; // [esp+228h] [ebp-4h]

  memset(&v48[1], 255, 12);
  memset(&v49[1], 255, 12);
  v2 = **((_DWORD **)this + 64);
  v48[0] = 0;
  v49[0] = 0;
  v50 = v2 & 0xFFFFF;
  if ( (v2 & 0xFFF00000) != 0x20900000 )
    return 1;
  v4 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v4 != nullptr )
    v56 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v4);
  else
    v56 = nullptr;
  v5 = v56;
  if ( v56 == nullptr )
    return -2147024882;
  v6 = D3DXShader::CInstruction::Initialize(this: v56, a2: *((struct D3DXShader::CInstruction **)this + 64));
  if ( v6 < 0 )
  {
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v56, a2: 1);
    return v6;
  }
  v7 = v50;
  v8 = 0;
  v9 = v50 == 0;
  *((_DWORD *)v56 + 3) = 1;
  *((_DWORD *)v5 + 1) = 2;
  *(_DWORD *)v5 = 546308097;
  v51 = 0;
  if ( v9 )
    return 0;
  v54 = 4 * v7;
  while ( 1 )
  {
    v10 = 4 * v8;
    **((_DWORD **)v5 + 4) = *(_DWORD *)(v10 + *(_DWORD *)(*((_DWORD *)this + 64) + 16));
    **((_DWORD **)v5 + 2) = *(_DWORD *)(v10 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
    v11 = *(_DWORD *)(v54 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
    v12 = *((_DWORD *)v5 + 2);
    v61 = 0;
    *(_DWORD *)(v12 + 4) = v11;
    memset(v47, 0xFFu, sizeof(v47));
    if ( D3DXShader::CShaderProgram::MatchComplexTree(
           this,
           a2: v5,
           a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE860,
           a4: &v45,
           a5: &v61,
           a6: v47,
           a7: v48,
           a8: 1u,
           a9: 1) == 0 )
    {
      v13 = v47[4];
      if ( v47[4] == v47[8] )
      {
        v61 = 0;
        D3DXShader::CShaderProgram::MatchComplexTree(
          this,
          a2: v5,
          a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE920,
          a4: &v44,
          a5: &v61,
          a6: v46,
          a7: v49,
          a8: 1u,
          a9: 1);
        v60 = v46[0] == v47[0] ? v46[4] : v47[0];
        if ( v60 != -1 )
        {
          v14 = 4 * **((_DWORD **)v5 + 4);
          if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v14) + 20) != -1 )
          {
            v15 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                        + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v14) + 20))
                            + 72);
            if ( v15 != -1 )
            {
              v9 = **(_DWORD **)(*((_DWORD *)this + 6) + 4 * v15) == 286261249;
              v59 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v15);
              if ( v9 )
              {
                v16 = *((_DWORD *)this + 5);
                v58 = *(_DWORD *)(v16 + 4 * v47[0]);
                v17 = *(_DWORD *)(v16 + 4 * v13);
                for ( i = v13; ; v17 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i) )
                {
                  v22 = *(_DWORD *)(v17 + 72);
                  if ( v22 == -1 )
                    break;
                  if ( *(_DWORD *)(v17 + 8) != -1 )
                    break;
                  v19 = *(int **)(*((_DWORD *)this + 6) + 4 * v22);
                  v20 = *v19;
                  if ( (*v19 & 0xFFF00000) != 0x10000000 )
                    break;
                  v63 = 0;
                  v62 = v20 & 0xFFFFF;
                  if ( (v20 & 0xFFFFF) == 0 )
                    break;
                  v21 = (_DWORD *)v19[4];
                  while ( *v21 != i )
                  {
                    ++v63;
                    ++v21;
                    if ( v63 >= v62 )
                      goto LABEL_32;
                  }
                  i = *(_DWORD *)(v19[2] + 4 * v63);
                }
LABEL_32:
                v23 = *((_DWORD *)this + 4);
                if ( (*(_DWORD *)(*(_DWORD *)(v23 + 4 * *(_DWORD *)(v58 + 4)) + 4) & 0x100) != 0
                  && (*(_DWORD *)(*(_DWORD *)(v23 + 4 * *(_DWORD *)(v17 + 4)) + 4) & 0x100) != 0
                  && *(double *)(v58 + 32) == 1.0
                  && *(double *)(v17 + 32) == 0.0 )
                {
                  v24 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v60);
                  v25 = *(_DWORD *)(v24 + 84);
                  v26 = -1;
                  v27 = v25 <= *(_DWORD *)(v24 + 88);
                  v53 = -1;
                  v58 = v24;
                  v61 = v25;
                  if ( v27 )
                  {
                    do
                    {
                      v28 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v25);
                      v9 = v28[3] == 0;
                      v55 = v28;
                      if ( !v9 )
                      {
                        v62 = 0;
                        if ( v28[1] != 0 )
                        {
                          while ( 1 )
                          {
                            v29 = *((_DWORD *)this + 5);
                            v30 = *(_DWORD *)(v29 + 4 * *(_DWORD *)(v28[2] + 4 * v62));
                            v31 = *(_DWORD *)(v30 + 8);
                            v57 = -1;
                            if ( v31 == -1 )
                              goto LABEL_49;
                            v32 = *(_DWORD *)(*(_DWORD *)(v29 + 4 * v31) + 72);
                            if ( v32 != -1 )
                              break;
LABEL_55:
                            if ( ++v62 >= v28[1] )
                            {
                              v24 = v58;
                              v25 = v61;
                              goto LABEL_57;
                            }
                          }
                          v33 = *(int **)(*((_DWORD *)this + 6) + 4 * v32);
                          v34 = *v33;
                          if ( (*v33 & 0xFFF00000) == 0x10000000 )
                          {
                            v63 = 0;
                            v52 = v34 & 0xFFFFF;
                            if ( (v34 & 0xFFFFF) != 0 )
                            {
                              v35 = (_DWORD *)v33[4];
                              while ( *v35 != v31 )
                              {
                                ++v63;
                                ++v35;
                                if ( v63 >= v52 )
                                  goto LABEL_49;
                              }
                              v57 = *(_DWORD *)(v33[2] + 4 * v63);
                            }
                          }
                          else
                          {
                            v57 = v31;
                          }
LABEL_49:
                          v26 = v53;
                          if ( v57 == v60 )
                          {
                            if ( v53 == -1 )
                            {
                              v36 = D3DXShader::CBaseProgram::AddPool(this, a2: "al", a3: 0x15u, a4: 0xFFFFFFFF, a5: 4u);
                              v26 = D3DXShader::CBaseProgram::AddArgument(this, a2: v36, a3: 0, a4: 0, a5: 0.0);
                              v53 = v26;
                              *(_DWORD *)(v30 + 8) = v26;
                            }
                            *(_DWORD *)(v30 + 8) = v26;
                            v37 = *(_DWORD *)(v30 + 56);
                            if ( v37 != -1 )
                              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v37) + 8) = v26;
                          }
                          v28 = v55;
                          goto LABEL_55;
                        }
                      }
LABEL_57:
                      v27 = ++v25 <= *(_DWORD *)(v24 + 88);
                      v61 = v25;
                    }
                    while ( v27 );
                    if ( v26 != -1 )
                      break;
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_66:
    v54 += 4;
    v8 = ++v51;
    if ( v51 >= v50 )
      return 0;
    v5 = v56;
  }
  v38 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v38 != nullptr )
    v39 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v38);
  else
    v39 = nullptr;
  if ( v39 == nullptr )
    return -2147024882;
  v40 = D3DXShader::CInstruction::Initialize(this: v39, a2: 0x74100001u, a3: 3u, a4: 1u, a5: 0);
  v41 = v39;
  if ( v40 >= 0 )
  {
    v40 = D3DXShader::CInstruction::Instance(this: v39, a2: v59);
    if ( v40 >= 0 )
    {
      v42 = v59;
      **((_DWORD **)v39 + 4) = **((_DWORD **)v59 + 4);
      **((_DWORD **)v39 + 2) = **((_DWORD **)v42 + 2);
      v43 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v42 + 2));
      *(_DWORD *)(*((_DWORD *)v39 + 2) + 4) = D3DXShader::CBaseProgram::AddArgument(
                                                this,
                                                a2: *(_DWORD *)(v43 + 4),
                                                a3: *(_DWORD *)(v43 + 12),
                                                a4: 2u,
                                                a5: 0.0);
      *(_DWORD *)(*((_DWORD *)v39 + 2) + 8) = D3DXShader::CBaseProgram::AddArgument(
                                                this,
                                                a2: *(_DWORD *)(v43 + 4),
                                                a3: *(_DWORD *)(v43 + 12),
                                                a4: 2u,
                                                a5: 1.0);
      v40 = D3DXShader::CInstruction::Initialize(this: v59, a2: v39);
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v39, a2: 1);
      if ( v40 < 0 )
        return v40;
      goto LABEL_66;
    }
    v41 = v39;
  }
  D3DXShader::CInstruction::`scalar deleting destructor'(this: v41, a2: 1);
  return v40;
}

//------------------------------------------------------------------------------
// Address: 0x1021A377
// Name: protected: long D3DXShader::CShaderProgram::FoldBreak(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::FoldBreak(D3DXShader::CShaderProgram *this)
{
  int v2; // edi
  struct D3DXShader::CArgument *v3; // ebx
  unsigned int v4; // eax
  unsigned __int8 *v6; // eax
  struct D3DXShader::CInstruction *v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edi
  int v14; // ecx
  unsigned int v15; // ebx
  struct D3DXShader::CInstruction *v16; // edx
  unsigned int v17; // edx
  unsigned int v18; // edi
  int v19; // eax
  unsigned int v20; // eax
  _DWORD *v21; // ebx
  int v22; // ecx
  int v23; // eax
  struct D3DXShader::CInstruction *v24; // edx
  bool v25; // zf
  int v26; // eax
  int v27; // eax
  unsigned int v28; // ebx
  int v29; // ecx
  int v30; // eax
  int *v31; // eax
  int v32; // edi
  _DWORD *i; // edi
  unsigned int v34; // ecx
  int v35; // eax
  int v36; // edi
  _DWORD *v37; // eax
  int v38; // ecx
  _DWORD *v39; // edi
  unsigned int v40; // ecx
  unsigned int v41; // eax
  bool v42; // cc
  unsigned int v43; // ebx
  int v44; // ecx
  int v45; // edi
  unsigned int v46; // edx
  int v47; // ecx
  int *v48; // ecx
  int v49; // eax
  _DWORD *v50; // ebx
  unsigned int v51; // eax
  unsigned int v52; // eax
  int v53; // edi
  unsigned int v54; // edi
  unsigned int v55; // eax
  int v56; // ecx
  D3DXShader::CArgument *v57; // edi
  D3DXShader::CArgument *v58; // ebx
  unsigned __int8 *v59; // eax
  int v60; // ebx
  struct D3DXShader::CInstruction *v61; // ebx
  D3DXShader::CInstruction *v62; // ecx
  unsigned int v63; // edi
  int v64; // eax
  int v65; // ecx
  unsigned int k; // ecx
  int v67; // eax
  unsigned int v68[40]; // [esp+14h] [ebp-214h] BYREF
  unsigned int v69[40]; // [esp+B4h] [ebp-174h] BYREF
  struct D3DXShader::CInstruction *v70[16]; // [esp+154h] [ebp-D4h] BYREF
  struct D3DXShader::CInstruction *v71[16]; // [esp+194h] [ebp-94h] BYREF
  unsigned int v72[4]; // [esp+1D4h] [ebp-54h] BYREF
  unsigned int v73[4]; // [esp+1E4h] [ebp-44h] BYREF
  struct D3DXShader::CArgument *v74; // [esp+1F4h] [ebp-34h]
  struct D3DXShader::CInstruction *v75; // [esp+1F8h] [ebp-30h]
  struct D3DXShader::CInstruction *v76; // [esp+1FCh] [ebp-2Ch]
  int v77; // [esp+200h] [ebp-28h]
  unsigned int v78; // [esp+204h] [ebp-24h]
  unsigned int v79; // [esp+208h] [ebp-20h]
  unsigned int v80; // [esp+20Ch] [ebp-1Ch]
  unsigned int v81; // [esp+210h] [ebp-18h]
  unsigned int v82; // [esp+214h] [ebp-14h]
  unsigned int v83; // [esp+218h] [ebp-10h] BYREF
  unsigned int j; // [esp+21Ch] [ebp-Ch]
  int matched; // [esp+220h] [ebp-8h]
  unsigned int v86; // [esp+224h] [ebp-4h] BYREF

  memset(&v73[1], 255, 12);
  memset(&v72[1], 255, 12);
  v2 = 0;
  v3 = (struct D3DXShader::CArgument *)(**((_DWORD **)this + 64) & 0xFFFFF);
  v4 = **((_DWORD **)this + 64) & 0xFFF00000;
  v73[0] = 0;
  v72[0] = 0;
  v74 = v3;
  if ( v4 != 546308096 )
    return 1;
  v6 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v6 != nullptr )
    v2 = D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v6);
  v76 = (struct D3DXShader::CInstruction *)v2;
  if ( v2 == 0 )
    return -2147024882;
  matched = D3DXShader::CInstruction::Initialize(
              this: (D3DXShader::CInstruction *)v2,
              a2: *((struct D3DXShader::CInstruction **)this + 64));
  if ( matched < 0 )
  {
LABEL_101:
    v62 = (D3DXShader::CInstruction *)v2;
LABEL_114:
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v62, a2: 1);
    return matched;
  }
  v79 = 0;
  *(_DWORD *)(v2 + 12) = 1;
  *(_DWORD *)(v2 + 4) = 2;
  *(_DWORD *)v2 = 546308097;
  if ( v3 == nullptr )
    goto LABEL_113;
  v77 = 4 * (_DWORD)v74;
  while ( 1 )
  {
    v7 = v76;
    v8 = 4 * v79;
    **((_DWORD **)v76 + 4) = *(_DWORD *)(4 * v79 + *(_DWORD *)(*((_DWORD *)this + 64) + 16));
    **((_DWORD **)v7 + 2) = *(_DWORD *)(v8 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
    *(_DWORD *)(*((_DWORD *)v7 + 2) + 4) = *(_DWORD *)(v77 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
    memset(v69, 0xFFu, sizeof(v69));
    v86 = 0;
    v82 = 0;
    v78 = 0;
    j = 0;
    matched = D3DXShader::CShaderProgram::MatchComplexTree(
                this,
                a2: v7,
                a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE1E0,
                a4: v71,
                a5: &v86,
                a6: v69,
                a7: v73,
                a8: 1u,
                a9: 1);
    if ( matched != 0 )
    {
      v86 = 0;
      matched = D3DXShader::CShaderProgram::MatchComplexTree(
                  this,
                  a2: v7,
                  a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE340,
                  a4: v71,
                  a5: &v86,
                  a6: v69,
                  a7: v73,
                  a8: 1u,
                  a9: 1);
      if ( matched != 0 )
      {
        v86 = 0;
        matched = D3DXShader::CShaderProgram::MatchComplexTree(
                    this,
                    a2: v7,
                    a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE4E0,
                    a4: v71,
                    a5: &v86,
                    a6: v69,
                    a7: v73,
                    a8: 1u,
                    a9: 1);
        if ( matched != 0 )
        {
          v86 = 0;
          matched = D3DXShader::CShaderProgram::MatchComplexTree(
                      this,
                      a2: v7,
                      a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE680,
                      a4: v71,
                      a5: &v86,
                      a6: v69,
                      a7: v73,
                      a8: 1u,
                      a9: 1);
          if ( matched == 0 )
            j = 1;
        }
        else
        {
          v78 = 1;
        }
      }
      else
      {
        v82 = 1;
      }
    }
    if ( v69[4] != v69[8] )
      goto LABEL_63;
    if ( matched != 0 )
      goto LABEL_63;
    v9 = *((_DWORD *)this + 5);
    v10 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * **((_DWORD **)v71[0] + 4)) + 20);
    if ( v10 == -1 )
      goto LABEL_63;
    v11 = *((_DWORD *)this + 6);
    v12 = *(_DWORD *)(v11 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * v10) + 72));
    v86 = 0;
    if ( *(_DWORD *)v12 != 286261249 )
      goto LABEL_63;
    v13 = **(_DWORD **)(v12 + 16);
    v14 = *(_DWORD *)(v9 + 4 * v13);
    v15 = *(_DWORD *)(v14 + 84);
    v81 = *(_DWORD *)(v14 + 88);
    if ( v15 > v81 )
      goto LABEL_63;
    v16 = (struct D3DXShader::CInstruction *)(v11 + 4 * v15);
    v75 = v16;
    do
    {
      v17 = *(_DWORD *)v16;
      if ( *(_DWORD *)(*(_DWORD *)(v9 + 4 * **(_DWORD **)(v17 + 16)) + 20) == v13 && *(_DWORD *)v17 == 1953497089 )
      {
        if ( v86 != 0 )
        {
          D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x12E3u, format: "internal error: multiple breaks found");
          return -2147467259;
        }
        v86 = v17;
      }
      ++v15;
      v16 = (struct D3DXShader::CInstruction *)((char *)v75 + 4);
      v75 = (struct D3DXShader::CInstruction *)((char *)v75 + 4);
    }
    while ( v15 <= v81 );
    v18 = v86;
    if ( v86 != 0 )
    {
      v83 = 0;
      if ( j != 0 )
      {
        v19 = D3DXShader::CShaderProgram::MatchComplexTree(
                this,
                a2: v76,
                a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE7A0,
                a4: v70,
                a5: &v83,
                a6: v68,
                a7: v73,
                a8: 1u,
                a9: 1);
      }
      else if ( v78 != 0 )
      {
        v19 = D3DXShader::CShaderProgram::MatchComplexTree(
                this,
                a2: v76,
                a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE5E0,
                a4: v70,
                a5: &v83,
                a6: v68,
                a7: v73,
                a8: 1u,
                a9: 1);
      }
      else if ( v82 != 0 )
      {
        v19 = D3DXShader::CShaderProgram::MatchComplexTree(
                this,
                a2: v76,
                a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE440,
                a4: v70,
                a5: &v83,
                a6: v68,
                a7: v73,
                a8: 1u,
                a9: 1);
      }
      else
      {
        v19 = D3DXShader::CShaderProgram::MatchComplexTree(
                this,
                a2: v76,
                a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE2C0,
                a4: v70,
                a5: &v83,
                a6: v68,
                a7: v72,
                a8: 1u,
                a9: 1);
      }
      matched = v19;
      v20 = v69[0];
      if ( v68[0] == v69[0] )
        v20 = v68[4];
      if ( v20 != -1 )
      {
        v21 = *(_DWORD **)(v18 + 8);
        if ( *v21 == v20 )
        {
          v22 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v18 + 16)) + 20);
          if ( v22 != -1 )
          {
            v23 = *((_DWORD *)this + 5);
            v24 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6)
                                                      + 4 * *(_DWORD *)(*(_DWORD *)(v23 + 4 * v22) + 72));
            v25 = *(_DWORD *)v24 == 286261249;
            v26 = *(_DWORD *)(v23 + 4 * **((_DWORD **)v24 + 2));
            v75 = v24;
            if ( v25
              && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v26 + 4)) + 5) & 1) != 0
              && *(double *)(v26 + 32) == (double)*((unsigned int *)this + 26) )
            {
              v27 = *((_DWORD *)this + 5);
              v28 = *(_DWORD *)(v27 + 4 * v21[1]);
              v83 = *(_DWORD *)(v27 + 4 * v69[0]);
              v29 = *(_DWORD *)(v27 + 4 * v69[4]);
              v30 = *(_DWORD *)(v29 + 72);
              v81 = v28;
              j = v69[4];
              if ( v30 != -1 )
              {
                while ( 2 )
                {
                  if ( *(_DWORD *)(v29 + 8) == -1 )
                  {
                    v31 = *(int **)(*((_DWORD *)this + 6) + 4 * v30);
                    if ( (*v31 & 0xFFF00000) == 0x10000000 )
                    {
                      v32 = *v31;
                      v80 = 0;
                      v82 = v32 & 0xFFFFF;
                      if ( (v32 & 0xFFFFF) != 0 )
                      {
                        for ( i = (_DWORD *)v31[4]; *i != j; i = (_DWORD *)v78 )
                        {
                          ++v80;
                          v78 = (unsigned int)(i + 1);
                          if ( v80 >= v82 )
                            goto LABEL_54;
                        }
                        v34 = *(_DWORD *)(v31[2] + 4 * v80);
                        v35 = *((_DWORD *)this + 5);
                        j = v34;
                        v29 = *(_DWORD *)(v35 + 4 * v34);
                        v30 = *(_DWORD *)(v29 + 72);
                        if ( v30 != -1 )
                        {
                          v28 = v81;
                          continue;
                        }
LABEL_54:
                        v28 = v81;
                      }
                    }
                  }
                  break;
                }
              }
              v36 = *((_DWORD *)this + 4);
              if ( (*(_BYTE *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(v83 + 4)) + 5) & 1) != 0
                && (*(_BYTE *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(v29 + 4)) + 5) & 1) != 0
                && *(double *)(v83 + 32) == 1.0
                && *(double *)(v29 + 32) == 0.0
                && (*(_BYTE *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(v28 + 4)) + 5) & 2) != 0
                && (*(_BYTE *)v28 & 2) != 0
                && *(_DWORD *)(v28 + 16) == 0
                && *(_DWORD *)(v28 + 8) == -1 )
              {
                break;
              }
            }
          }
        }
      }
    }
LABEL_63:
    ++v79;
    v77 += 4;
    if ( v79 >= (unsigned int)v74 )
      goto LABEL_113;
  }
  v37 = (_DWORD *)v86;
  v38 = *(_DWORD *)(*(_DWORD *)(v86 + 8) + 4);
  v39 = *((_DWORD **)v24 + 2);
  v82 = -1;
  *v39 = v38;
  *v37 = 0;
  v40 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v24 + 4));
  v41 = *(_DWORD *)(v40 + 84);
  v42 = v41 <= *(_DWORD *)(v40 + 88);
  v83 = v40;
  v81 = v41;
  if ( v42 )
  {
    while ( 1 )
    {
      v43 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v41);
      v25 = *(_DWORD *)(v43 + 12) == 0;
      v80 = v43;
      if ( !v25
        && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v43 + 16)) + 20) == **(_DWORD **)(v86 + 16) )
      {
        v77 = 0;
        if ( *(_DWORD *)(v43 + 4) != 0 )
        {
          while ( 1 )
          {
            v44 = *((_DWORD *)this + 5);
            v45 = *(_DWORD *)(v44 + 4 * *(_DWORD *)(*(_DWORD *)(v43 + 8) + 4 * v77));
            v46 = *(_DWORD *)(v45 + 8);
            j = -1;
            if ( v46 == -1 )
              goto LABEL_83;
            v47 = *(_DWORD *)(*(_DWORD *)(v44 + 4 * v46) + 72);
            if ( v47 != -1 )
              break;
LABEL_88:
            if ( (unsigned int)++v77 >= *(_DWORD *)(v43 + 4) )
              goto LABEL_89;
          }
          v48 = *(int **)(*((_DWORD *)this + 6) + 4 * v47);
          v49 = *v48;
          if ( (*v48 & 0xFFF00000) == 0x10000000 )
          {
            v79 = 0;
            v78 = v49 & 0xFFFFF;
            if ( (v49 & 0xFFFFF) != 0 )
            {
              v50 = (_DWORD *)v48[4];
              while ( *v50 != v46 )
              {
                ++v79;
                ++v50;
                if ( v79 >= v78 )
                  goto LABEL_82;
              }
              j = *(_DWORD *)(v48[2] + 4 * v79);
            }
          }
          else
          {
            j = v46;
          }
LABEL_82:
          v43 = v80;
LABEL_83:
          if ( j == **(_DWORD **)(v86 + 8) )
          {
            v51 = v82;
            if ( v82 == -1 )
            {
              v52 = D3DXShader::CBaseProgram::AddPool(this, a2: "al", a3: 0x15u, a4: 0xFFFFFFFF, a5: 4u);
              v51 = D3DXShader::CBaseProgram::AddArgument(this, a2: v52, a3: 0, a4: 0, a5: 0.0);
              v82 = v51;
              *(_DWORD *)(v45 + 8) = v51;
            }
            *(_DWORD *)(v45 + 8) = v51;
            v53 = *(_DWORD *)(v45 + 56);
            if ( v53 != -1 )
              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v53) + 8) = v51;
          }
          goto LABEL_88;
        }
      }
LABEL_89:
      if ( ++v81 > *(_DWORD *)(v83 + 88) )
        break;
      v41 = v81;
    }
    if ( v82 != -1 )
    {
      v54 = D3DXShader::CBaseProgram::AddArgument(this, a2: 0, a3: 0, a4: 0, a5: 0.0);
      v55 = D3DXShader::CBaseProgram::AddArgument(this, a2: 0, a3: 0, a4: 0, a5: 0.0);
      if ( v54 == -1 || v55 == -1 )
        return -2147024882;
      v56 = *((_DWORD *)this + 5);
      v57 = *(D3DXShader::CArgument **)(v56 + 4 * v54);
      v58 = *(D3DXShader::CArgument **)(v56 + 4 * v55);
      v74 = *(struct D3DXShader::CArgument **)(v56 + 4 * **((_DWORD **)v75 + 2));
      D3DXShader::CArgument::Initialize(this: v57, a2: v74);
      D3DXShader::CArgument::Initialize(this: v58, a2: v74);
      *((_DWORD *)v57 + 4) = 1;
      *((_DWORD *)v58 + 4) = 2;
      v59 = D3DXShader::CInstruction::operator new(a1: 0x74u);
      v2 = v59 != nullptr ? D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v59) : 0;
      if ( v2 == 0 )
        return -2147024882;
      v60 = D3DXShader::CInstruction::Initialize(
              this: (D3DXShader::CInstruction *)v2,
              a2: 0x74100001u,
              a3: 3u,
              a4: 1u,
              a5: 0);
      if ( v60 < 0 )
      {
        D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v2, a2: 1);
        return v60;
      }
      v61 = v75;
      matched = D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)v2, a2: v75);
      if ( matched < 0 )
        goto LABEL_101;
      **(_DWORD **)(v2 + 16) = **((_DWORD **)v61 + 4);
      **(_DWORD **)(v2 + 8) = **((_DWORD **)v61 + 2);
      *(_DWORD *)(*(_DWORD *)(v2 + 8) + 4) = **((_DWORD **)v61 + 2);
      *(_DWORD *)(*(_DWORD *)(v2 + 8) + 8) = **((_DWORD **)v61 + 2);
      matched = D3DXShader::CInstruction::Initialize(this: v61, a2: (struct D3DXShader::CInstruction *)v2);
      D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v2, a2: 1);
      if ( matched < 0 )
        return matched;
    }
  }
  v63 = *(_DWORD *)(v83 + 84);
  v42 = v63 <= *(_DWORD *)(v83 + 88);
  for ( j = v63; v42; j = v63 )
  {
    v64 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v63);
    if ( (*(_DWORD *)v64 & 0xFFF00000) == 0x20800000 )
    {
      if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v64 + 8)) + 20) == **(_DWORD **)(v86 + 16) )
      {
        v65 = *(_DWORD *)v64 & 0xFFFFF;
        *(_DWORD *)v64 = v65 | 0x10000000;
        *(_DWORD *)(v64 + 12) = v65;
        *(_DWORD *)(v64 + 4) = v65;
      }
      v63 = j;
    }
    v42 = ++v63 <= *(_DWORD *)(v83 + 88);
  }
  for ( k = 0; k < *((_DWORD *)this + 2); ++k )
  {
    v67 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * k);
    if ( *(_DWORD *)(v67 + 20) == **(_DWORD **)(v86 + 16) )
      *(_DWORD *)(v67 + 20) = **((_DWORD **)v75 + 4);
  }
LABEL_113:
  v62 = v76;
  goto LABEL_114;
}

//------------------------------------------------------------------------------
// Address: 0x1021AB95
// Name: protected: long D3DXShader::CShaderProgram::MatchBREAK_NEEQ(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchBREAK_NEEQ(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *v2; // eax
  int v3; // esi
  unsigned int v4; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // ecx
  int v9; // ecx
  struct D3DXShader::CInstruction *v10; // [esp-20h] [ebp-128h]
  unsigned int v11[40]; // [esp+Ch] [ebp-FCh] BYREF
  struct D3DXShader::CInstruction *v12[16]; // [esp+ACh] [ebp-5Ch] BYREF
  unsigned int v13[4]; // [esp+ECh] [ebp-1Ch] BYREF
  int v14; // [esp+FCh] [ebp-Ch]
  unsigned int v15; // [esp+100h] [ebp-8h]
  unsigned int v16; // [esp+104h] [ebp-4h] BYREF

  v2 = *((struct D3DXShader::CInstruction **)this + 64);
  v3 = *(_DWORD *)v2;
  v16 = 0;
  v13[0] = 0;
  v14 = 0;
  v4 = v3 & 0xFFFFF;
  v13[1] = 1;
  v13[2] = 2;
  v13[3] = 3;
  result = D3DXShader::CShaderProgram::MatchComplexTree(
             this,
             a2: v2,
             a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDE60,
             a4: v12,
             a5: &v16,
             a6: v11,
             a7: v13,
             a8: v4,
             a9: 1);
  if ( result == 1 )
  {
    v10 = *((struct D3DXShader::CInstruction **)this + 64);
    v14 = 1;
    result = D3DXShader::CShaderProgram::MatchComplexTree(
               this,
               a2: v10,
               a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDEC0,
               a4: v12,
               a5: &v16,
               a6: v11,
               a7: v13,
               a8: v4,
               a9: 1);
  }
  if ( result == 0 )
  {
    v15 = 0;
    if ( v4 != 0 )
    {
      v16 = 4 * v4;
      while ( v11[v15 + 4] == v11[v15 + 8] )
      {
        v6 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v16 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)));
        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v6 + 4)) + 5) & 1) == 0
          || *(double *)(v6 + 32) != 0.0
          || *(_DWORD *)(v6 + 8) != -1 )
        {
          break;
        }
        ++v15;
        v16 += 4;
        if ( v15 >= v4 )
          goto LABEL_11;
      }
      return 1;
    }
    else
    {
LABEL_11:
      v7 = 0;
      v8 = v4 & 0xFFFFF;
      if ( v14 != 0 )
        v9 = v8 | 0x74400000;
      else
        v9 = v8 | 0x74500000;
      **((_DWORD **)this + 64) = v9;
      if ( v4 != 0 )
      {
        do
        {
          *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * v7) = v11[v7 + 4];
          ++v7;
        }
        while ( v7 < v4 );
      }
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021ACE3
// Name: protected: long D3DXShader::CShaderProgram::MatchBREAK_NEEQ2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchBREAK_NEEQ2(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *v2; // eax
  int v3; // edi
  unsigned int v4; // edi
  int result; // eax
  unsigned int v6; // edx
  unsigned int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ebx
  struct D3DXShader::CInstruction *v14; // [esp-18h] [ebp-124h]
  struct D3DXShader::CInstruction *v15[16]; // [esp+14h] [ebp-F8h] BYREF
  unsigned int v16[40]; // [esp+54h] [ebp-B8h] BYREF
  unsigned int v17[4]; // [esp+F4h] [ebp-18h] BYREF
  unsigned int v18; // [esp+104h] [ebp-8h]
  unsigned int v19; // [esp+108h] [ebp-4h] BYREF

  v2 = *((struct D3DXShader::CInstruction **)this + 64);
  v3 = *(_DWORD *)v2;
  v19 = 0;
  v17[0] = 0;
  v18 = 0;
  v4 = v3 & 0xFFFFF;
  v17[1] = 1;
  v17[2] = 2;
  v17[3] = 3;
  result = D3DXShader::CShaderProgram::MatchComplexTree(
             this,
             a2: v2,
             a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDF20,
             a4: v15,
             a5: &v19,
             a6: v16,
             a7: v17,
             a8: v4,
             a9: 1);
  if ( result == 1 )
  {
    v14 = *((struct D3DXShader::CInstruction **)this + 64);
    v18 = 1;
    result = D3DXShader::CShaderProgram::MatchComplexTree(
               this,
               a2: v14,
               a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDFA0,
               a4: v15,
               a5: &v19,
               a6: v16,
               a7: v17,
               a8: v4,
               a9: 1);
  }
  if ( result == 0 )
  {
    v19 = 0;
    if ( v4 != 0 )
    {
      while ( 1 )
      {
        v6 = v16[v19];
        v7 = v16[v19 + 4];
        if ( v6 != v7 || v7 != v16[v19 + 8] || v6 != v16[v19 + 12] )
          return 1;
        if ( ++v19 >= v4 )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      v8 = v4 & 0xFFFFF;
      if ( v18 != 0 )
        v9 = v8 | 0x74400000;
      else
        v9 = v8 | 0x74500000;
      **((_DWORD **)this + 64) = v9;
      v18 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 0.0);
      if ( v18 == -1 )
      {
        return -2147024882;
      }
      else
      {
        v10 = 0;
        if ( v4 != 0 )
        {
          v19 = 4 * v4;
          do
          {
            v11 = *(_DWORD *)(*((_DWORD *)this + 64) + 8);
            v12 = v16[v10];
            v13 = v19;
            v19 += 4;
            *(_DWORD *)(v11 + 4 * v10++) = v12;
            *(_DWORD *)(v13 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)) = v18;
          }
          while ( v10 < v4 );
        }
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021AE45
// Name: protected: long D3DXShader::CShaderProgram::MatchBREAK_COND(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchBREAK_COND(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *v2; // ecx
  int v3; // eax
  int result; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ebx
  _DWORD *v8; // ecx
  int v9; // edi
  int v10; // edx
  int v11; // ebx
  int v12; // edi
  unsigned int v13; // eax
  D3DXShader::CArgument *v14; // eax
  unsigned int v15[8]; // [esp+14h] [ebp-FCh] BYREF
  _DWORD v16[32]; // [esp+34h] [ebp-DCh]
  struct D3DXShader::CInstruction *v17[16]; // [esp+B4h] [ebp-5Ch] BYREF
  unsigned int v18[4]; // [esp+F4h] [ebp-1Ch] BYREF
  unsigned int v19; // [esp+104h] [ebp-Ch]
  D3DXShader::CArgument *v20; // [esp+108h] [ebp-8h]
  unsigned int v21; // [esp+10Ch] [ebp-4h] BYREF

  v2 = *((struct D3DXShader::CInstruction **)this + 64);
  v3 = *(_DWORD *)v2 & 0xFFFFF;
  v21 = 0;
  v18[0] = 0;
  v18[1] = 1;
  v18[2] = 2;
  v18[3] = 3;
  if ( v3 != 1 )
    return 1;
  result = D3DXShader::CShaderProgram::MatchComplexTree(
             this,
             a2: v2,
             a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDCE0,
             a4: v17,
             a5: &v21,
             a6: v15,
             a7: v18,
             a8: 1u,
             a9: 1);
  if ( result == 1 )
  {
    result = D3DXShader::CShaderProgram::MatchComplexTree(
               this,
               a2: *((struct D3DXShader::CInstruction **)this + 64),
               a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDD40,
               a4: v17,
               a5: &v21,
               a6: v15,
               a7: v18,
               a8: 1u,
               a9: 1);
    if ( result == 1 )
    {
      result = D3DXShader::CShaderProgram::MatchComplexTree(
                 this,
                 a2: *((struct D3DXShader::CInstruction **)this + 64),
                 a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDDA0,
                 a4: v17,
                 a5: &v21,
                 a6: v15,
                 a7: v18,
                 a8: 1u,
                 a9: 1);
      if ( result == 1 )
        result = D3DXShader::CShaderProgram::MatchComplexTree(
                   this,
                   a2: *((struct D3DXShader::CInstruction **)this + 64),
                   a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BDE00,
                   a4: v17,
                   a5: &v21,
                   a6: v15,
                   a7: v18,
                   a8: 1u,
                   a9: 1);
    }
  }
  if ( result == 0 )
  {
    v5 = *(_DWORD *)(*((_DWORD *)this + 64) + 8);
    v6 = *((_DWORD *)this + 5);
    v21 = 0;
    v7 = *((_DWORD *)this + 4);
    v8 = (_DWORD *)(v5 + 4);
    do
    {
      v9 = *(_DWORD *)(v6 + 4 * *v8);
      if ( (*(_BYTE *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(v9 + 4)) + 5) & 1) == 0
        || *(double *)(v9 + 32) != 0.0
        || *(_DWORD *)(v9 + 8) != -1 )
      {
        return 1;
      }
      ++v21;
      ++v8;
    }
    while ( v21 == 0 );
    v10 = *(_DWORD *)(v6 + 4 * v16[0]);
    v21 = 0;
    if ( *(_DWORD *)(v10 + 8) == -1 )
      v21 = (*(_BYTE *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(v10 + 4)) + 5) & 1) != 0;
    v11 = 0;
    while ( 1 )
    {
      *(_DWORD *)(v11 * 4 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)) = v15[v11 + 4];
      v12 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v16[v11]);
      v13 = D3DXShader::CBaseProgram::AddArgument(
              this,
              a2: *(_DWORD *)(v12 + 4),
              a3: *(_DWORD *)(v12 + 12),
              a4: *(_DWORD *)(v12 + 16),
              a5: *(double *)(v12 + 32));
      v19 = v13;
      if ( v13 == -1 )
        break;
      v20 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v13);
      D3DXShader::CArgument::Initialize(this: v20, a2: (struct D3DXShader::CArgument *)v12);
      v14 = v20;
      if ( v21 != 0 )
      {
        *((double *)v20 + 4) = *((double *)v20 + 4) * -1.0;
      }
      else
      {
        if ( *((_DWORD *)v20 + 14) == -1 )
          *((_DWORD *)v20 + 14) = v16[v11];
        *((_DWORD *)v14 + 15) ^= 0x80000u;
      }
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + v11 * 4 + 4) = v19;
      if ( (unsigned int)++v11 >= 1 )
        return 0;
    }
    return -2147024882;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021B05D
// Name: protected: long D3DXShader::CShaderProgram::MatchNRM(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchNRM(D3DXShader::CShaderProgram *this)
{
  unsigned int *v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ecx
  int v7; // edi
  unsigned int v8; // ecx
  unsigned int *v9; // esi
  int v10; // eax
  int v11; // edi
  unsigned int v12; // edx
  unsigned int *v13; // ecx
  unsigned int v14; // eax
  int v15; // esi
  unsigned int v16; // ecx
  struct D3DXShader::CInstruction *v17; // ecx
  unsigned int v18; // edi
  int v19; // edx
  _DWORD *v20; // eax
  unsigned int v21; // eax
  struct D3DXShader::CInstruction *v22; // eax
  struct D3DXShader::CInstruction *v23; // ecx
  int v24; // edx
  int v25; // edi
  _DWORD *v26; // esi
  unsigned int n; // eax
  unsigned int v28; // esi
  unsigned int v29; // edi
  struct D3DXShader::CInstruction *v30; // ecx
  struct D3DXShader::CInstruction *v31; // eax
  _DWORD *v32; // ecx
  int v33; // eax
  unsigned int jj; // eax
  unsigned int v35; // ecx
  int v36; // esi
  _DWORD *v37; // ecx
  int v38; // eax
  unsigned int kk; // edx
  int v40; // eax
  _DWORD *v41; // ecx
  unsigned __int8 *v42; // eax
  struct D3DXShader::CInstruction *v43; // esi
  int v45; // edi
  D3DXShader::CInstruction *v46; // ecx
  char *v47; // esi
  struct D3DXShader::CInstruction *v48; // eax
  char *v49; // edi
  char v50; // dl
  unsigned int v51; // ecx
  char *v52; // edi
  char *v53; // esi
  unsigned int v54; // edx
  unsigned int v55; // esi
  _DWORD *v56; // ecx
  int v57; // edx
  _DWORD *v58; // ecx
  _DWORD *v59; // ecx
  unsigned int v60; // [esp-8h] [ebp-28Ch]
  unsigned int v61[80]; // [esp+Ch] [ebp-278h] BYREF
  _DWORD v62[40]; // [esp+14Ch] [ebp-138h] BYREF
  unsigned int v63[4]; // [esp+1ECh] [ebp-98h] BYREF
  struct D3DXShader::CInstruction *v64[16]; // [esp+1FCh] [ebp-88h] BYREF
  unsigned int v65[4]; // [esp+23Ch] [ebp-48h] BYREF
  int m; // [esp+24Ch] [ebp-38h]
  unsigned int j; // [esp+250h] [ebp-34h]
  int v68; // [esp+254h] [ebp-30h]
  struct D3DXShader::CInstruction **v69; // [esp+258h] [ebp-2Ch]
  unsigned int v70; // [esp+25Ch] [ebp-28h] BYREF
  unsigned int v71; // [esp+260h] [ebp-24h]
  struct D3DXShader::CInstruction *v72; // [esp+264h] [ebp-20h]
  int matched; // [esp+268h] [ebp-1Ch]
  unsigned int v74; // [esp+26Ch] [ebp-18h]
  struct D3DXShader::CInstruction *k; // [esp+270h] [ebp-14h]
  unsigned int i; // [esp+274h] [ebp-10h]
  int v77; // [esp+278h] [ebp-Ch]
  unsigned int ii; // [esp+27Ch] [ebp-8h]
  unsigned int v79; // [esp+280h] [ebp-4h]

  v65[0] = 0;
  memset(v62, 0xFFu, sizeof(v62));
  v2 = *((unsigned int **)this + 64);
  v3 = *v2;
  v71 = *v2;
  v4 = v71;
  v71 &= 0xFFFFFu;
  v65[1] = 1;
  v65[2] = 2;
  v65[3] = 3;
  v72 = (struct D3DXShader::CInstruction *)v2;
  v74 = v4 & 0xFFFFF;
  if ( v71 > (v4 & 0xFFFFF) || (v3 & 0xFFF00000) != 0x20500000 )
  {
    v77 = 1;
    goto LABEL_90;
  }
  v68 = 0;
  while ( 2 )
  {
    v77 = 0;
    while ( 2 )
    {
      memset(v61, 255, sizeof(v61));
      v5 = 0;
      v70 = 0;
      matched = 0;
      v79 = 0;
      ii = 0;
      while ( 1 )
      {
        if ( v77 != 0 )
          v6 = 1 - v79;
        else
          v6 = v79;
        v7 = *((_DWORD *)v72 + 2);
        v8 = dword_102BD78C[v6];
        v9 = (unsigned int *)(v7 + 4 * v5);
        if ( v8 >= 0x10 )
        {
          v12 = 0;
          v13 = &v61[4 * v8 - 24];
          do
          {
            v14 = v65[v12];
            if ( v14 >= v71 )
              *v13 = -1;
            else
              *v13 = *(_DWORD *)(v7 + 4 * (ii + v14));
            ++v12;
            ++v13;
          }
          while ( v12 < 4 );
          goto LABEL_19;
        }
        v10 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v9) + 72);
        if ( v10 == -1 )
          break;
        v11 = 32 * v8;
        v60 = dword_102BD798[8 * v8];
        k = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v10);
        if ( D3DXShader::CShaderProgram::ComputeSwizzle(this, a2: k, a3: v9, a4: v71, a5: v65, a6: v63, a7: v60, a8: 0) != 0 )
          break;
        matched = D3DXShader::CShaderProgram::MatchComplexTree(
                    this,
                    a2: k,
                    a3: (const struct D3DXShader::D3DX_MATCHENTRY *)((char *)&unk_102BD780 + v11),
                    a4: v64,
                    a5: &v70,
                    a6: v61,
                    a7: v63,
                    a8: v74,
                    a9: 0);
LABEL_19:
        if ( matched != 1 )
        {
          v5 = v71 + ii;
          ++v79;
          ii += v71;
          if ( v79 < 2 )
            continue;
        }
        goto LABEL_23;
      }
      matched = 1;
LABEL_23:
      v15 = 0;
      v79 = 0;
      v69 = nullptr;
      do
      {
        if ( v77 != 0 )
          v16 = 1 - v79;
        else
          v16 = v79;
        if ( (unsigned int)dword_102BD78C[v16] >= 0x10 )
        {
          for ( i = 0; i < v70; v15 = 0 )
          {
            if ( v71 != 0 )
            {
              v17 = v64[i];
              v18 = *((_DWORD *)v17 + 3);
              while ( 1 )
              {
                ii = 0;
                if ( v18 != 0 )
                  break;
LABEL_35:
                if ( ++v15 >= v71 )
                  goto LABEL_38;
              }
              v19 = *(_DWORD *)(*((_DWORD *)v72 + 2) + 4 * ((_DWORD)v69 + v15));
              v20 = *((_DWORD **)v17 + 4);
              while ( v19 != *v20 )
              {
                ++ii;
                v18 = *((_DWORD *)v17 + 3);
                ++v20;
                if ( ii >= v18 )
                  goto LABEL_35;
              }
              matched = 1;
            }
LABEL_38:
            ++i;
          }
        }
        ++v79;
        v69 = (struct D3DXShader::CInstruction **)((char *)v69 + v71);
      }
      while ( v79 < 2 );
      if ( matched == 0 )
      {
        if ( v68 != 0 )
          goto LABEL_83;
        for ( i = 0; i < v70; ++i )
        {
          v21 = *((_DWORD *)v64[i] + 3);
          ii = 0;
          for ( j = v21; ii < j; ++ii )
          {
            v22 = *((struct D3DXShader::CInstruction **)this + 3);
            if ( v22 != nullptr )
            {
              v69 = *((struct D3DXShader::CInstruction ***)this + 6);
              for ( k = v22; k != nullptr; k = (struct D3DXShader::CInstruction *)((char *)k - 1) )
              {
                v23 = *v69;
                if ( *v69 != nullptr && *(_DWORD *)v23 != 0 )
                {
                  v24 = *((_DWORD *)v23 + 1);
                  v79 = 0;
                  if ( v24 != 0 )
                  {
                    v25 = *(_DWORD *)(*((_DWORD *)v64[i] + 4) + 4 * ii);
                    v26 = *((_DWORD **)v23 + 2);
                    for ( m = v24; m != 0; --m )
                    {
                      if ( *v26 == v25 || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v26) + 56) == v25 )
                        v79 = 1;
                      ++v26;
                    }
                  }
                  if ( v23 == v72 )
                    v79 = 0;
                  if ( v79 != 0 )
                  {
                    for ( n = 0; n < v70; ++n )
                    {
                      if ( v23 == v64[n] )
                        v79 = 0;
                    }
                    if ( v79 != 0 )
                      matched = 1;
                  }
                }
                ++v69;
              }
            }
          }
        }
        for ( ii = 0; ii < 0x28; ++ii )
        {
          v28 = v61[ii + 40];
          if ( v28 != -1 )
          {
            v29 = 0;
            if ( v70 != 0 )
            {
              j = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v28);
              do
              {
                v30 = v64[v29];
                v31 = *((struct D3DXShader::CInstruction **)v30 + 3);
                if ( v31 != nullptr )
                {
                  v32 = *((_DWORD **)v30 + 4);
                  for ( k = v31; k != nullptr; k = (struct D3DXShader::CInstruction *)((char *)k - 1) )
                  {
                    if ( v28 == *v32 || *(_DWORD *)(j + 56) == *v32 )
                      matched = 1;
                    ++v32;
                  }
                }
                ++v29;
              }
              while ( v29 < v70 );
            }
          }
        }
        if ( matched == 0 )
        {
LABEL_83:
          v64[v70] = v72;
          for ( jj = 0; jj < 40; ++jj )
          {
            v35 = v61[jj + 40];
            if ( v35 == -1 )
            {
              v35 = v61[jj];
              if ( v35 == -1 )
                continue;
            }
            v62[jj] = v35;
          }
          v33 = 0;
LABEL_89:
          v77 = v33;
LABEL_90:
          if ( v74 < 3 )
            return 1;
          k = nullptr;
          v36 = *((_DWORD *)this + 4);
          v37 = *(_DWORD **)(*((_DWORD *)this + 64) + 16);
          do
          {
            v38 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v37);
            if ( (*(_BYTE *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(v38 + 4)) + 4) & 0x20) != 0
              || *(struct D3DXShader::CInstruction **)(v38 + 16) != k )
            {
              return 1;
            }
            ++v37;
            k = (struct D3DXShader::CInstruction *)((char *)k + 1);
          }
          while ( (unsigned int)k < v74 );
          if ( v77 != 0 )
            return v77;
          for ( kk = 0; kk < 3; ++kk )
          {
            v40 = v62[kk];
            v41 = &v62[kk + 8];
            if ( v40 != *(v41 - 4)
              || v40 != *v41
              || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v40) + 16) != kk
              && (*((_BYTE *)this + 108) & 2) != 0 )
            {
              return 1;
            }
          }
          if ( v62[7] != -1 || v62[11] != -1 )
            return 1;
          v42 = D3DXShader::CInstruction::operator new(a1: 0x74u);
          if ( v42 != nullptr )
            v43 = (struct D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v42);
          else
            v43 = nullptr;
          v72 = v43;
          if ( v43 == nullptr )
            return -2147024882;
          v45 = D3DXShader::CInstruction::Initialize(this: v43, a2: v74 & 0xFFFFF | 0x70200000, a3: v74, a4: v74, a5: 0);
          v46 = v43;
          if ( v45 < 0 )
            goto LABEL_114;
          v45 = D3DXShader::CInstruction::Instance(this: v43, a2: *((struct D3DXShader::CInstruction **)this + 64));
          if ( v45 < 0 )
          {
            v46 = v43;
LABEL_114:
            D3DXShader::CInstruction::`scalar deleting destructor'(this: v46, a2: 1);
            return v45;
          }
          v47 = *(char **)(*((_DWORD *)this + 64) + 16);
          v48 = v72;
          v49 = *((char **)v72 + 4);
          v50 = 4 * v74;
          v51 = (4 * v74) >> 2;
          qmemcpy(v49, v47, 4 * v51);
          v53 = &v47[4 * v51];
          v52 = &v49[4 * v51];
          LOBYTE(v51) = v50;
          v54 = v74;
          qmemcpy(v52, v53, v51 & 3);
          qmemcpy(*((void **)v48 + 2), v62, 4 * ((4 * v54) >> 2));
          v55 = 0;
          if ( v54 != 0 )
          {
            do
            {
              if ( (*((_BYTE *)this + 108) & 2) != 0 )
              {
                v56 = *(_DWORD **)(*((_DWORD *)this + 5)
                                 + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * v55));
                *v56 |= 0x80000000;
                v57 = *((_DWORD *)this + 5);
                if ( *(_DWORD *)(*(_DWORD *)(v57 + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * v55))
                               + 56) != -1 )
                {
                  v58 = *(_DWORD **)(*((_DWORD *)this + 5)
                                   + 4
                                   * *(_DWORD *)(*(_DWORD *)(v57
                                                           + 4
                                                           * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8)
                                                                       + 4 * v55))
                                               + 56));
                  *v58 |= 0x80000000;
                }
              }
              v59 = *(_DWORD **)(*((_DWORD *)this + 5)
                               + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 16) + 4 * v55));
              *v59 |= 0x80000000;
              ++v55;
            }
            while ( v55 < v74 );
          }
          v77 = D3DXShader::CInstruction::Initialize(this: *((D3DXShader::CInstruction **)this + 64), a2: v72);
          D3DXShader::CInstruction::`scalar deleting destructor'(this: v72, a2: 1);
          return v77;
        }
      }
      if ( (unsigned int)++v77 < 2 )
        continue;
      break;
    }
    v33 = matched;
    if ( ++v68 != 0 )
      goto LABEL_89;
    continue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B660
// Name: protected: long D3DXShader::CShaderProgram::MatchDP2Add(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchDP2Add(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *v2; // eax
  int v3; // esi
  int v4; // edi
  unsigned int v5; // esi
  int result; // eax
  unsigned int *v7; // eax
  int v8; // ecx
  _DWORD *v9; // edx
  unsigned __int8 *v10; // eax
  bool v11; // zf
  D3DXShader::CInstruction *v12; // eax
  struct D3DXShader::CInstruction *v13; // edi
  _DWORD *v14; // eax
  int v15; // eax
  unsigned int v16; // ecx
  int v17; // ecx
  unsigned int *v18; // esi
  unsigned int *v19; // eax
  unsigned int v20; // ecx
  int v21; // ecx
  unsigned int v22; // eax
  int v23; // eax
  unsigned int v24; // edx
  int v25; // eax
  unsigned int v26; // [esp-8h] [ebp-120h]
  unsigned int v27; // [esp-4h] [ebp-11Ch]
  struct D3DXShader::CInstruction *v28[16]; // [esp+14h] [ebp-104h] BYREF
  unsigned int v29[4]; // [esp+54h] [ebp-C4h] BYREF
  unsigned int v30; // [esp+64h] [ebp-B4h]
  unsigned int v31; // [esp+68h] [ebp-B0h]
  int v32; // [esp+74h] [ebp-A4h]
  unsigned int v33[4]; // [esp+F4h] [ebp-24h] BYREF
  unsigned int v34; // [esp+104h] [ebp-14h]
  unsigned int v35; // [esp+108h] [ebp-10h]
  int v36; // [esp+10Ch] [ebp-Ch]
  unsigned int v37; // [esp+110h] [ebp-8h] BYREF
  D3DXShader::CInstruction *v38; // [esp+114h] [ebp-4h]

  v2 = *((struct D3DXShader::CInstruction **)this + 64);
  v3 = *(_DWORD *)v2;
  v37 = 0;
  v33[0] = 0;
  v36 = 0;
  v4 = 1;
  v5 = v3 & 0xFFFFF;
  v33[1] = 1;
  v33[2] = 2;
  v33[3] = 3;
  if ( D3DXShader::CShaderProgram::MatchComplexTree(
         this,
         a2: v2,
         a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE980,
         a4: v28,
         a5: &v37,
         a6: v29,
         a7: v33,
         a8: v5,
         a9: 1) != 0 )
  {
    result = D3DXShader::CShaderProgram::MatchComplexTree(
               this,
               a2: *((struct D3DXShader::CInstruction **)this + 64),
               a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BE9E0,
               a4: v28,
               a5: &v37,
               a6: v29,
               a7: v33,
               a8: v5,
               a9: 1);
    if ( result != 0 )
      return result;
    v36 = 1;
  }
  if ( *(_DWORD *)v28[0] == 1342177282 )
  {
    v38 = (D3DXShader::CInstruction *)1;
    if ( v5 > 1 )
    {
      v7 = *(unsigned int **)(*((_DWORD *)this + 64) + 8);
      v35 = *v7;
      v8 = 4 * v5 + 4;
      v9 = v7 + 1;
      while ( *v9 == v35 )
      {
        if ( *(_DWORD *)(v8 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)) != *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64)
                                                                                                + 8)
                                                                                    + 4 * v5) )
          return 1;
        v38 = (D3DXShader::CInstruction *)((char *)v38 + 1);
        ++v9;
        v8 += 4;
        if ( (unsigned int)v38 >= v5 )
          goto LABEL_11;
        v4 = 1;
      }
      return v4;
    }
LABEL_11:
    v10 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v10 != nullptr )
      v38 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v10);
    else
      v38 = nullptr;
    v4 = D3DXShader::CInstruction::Initialize(this: v38, a2: 0x70800002u, a3: 6u, a4: v5, a5: 0);
    if ( v4 < 0 )
      goto LABEL_30;
    v4 = D3DXShader::CInstruction::Instance(this: v38, a2: *((struct D3DXShader::CInstruction **)this + 64));
    if ( v4 < 0 )
      goto LABEL_30;
    v11 = v36 == 0;
    v12 = v38;
    qmemcpy(*((void **)v38 + 4), *(const void **)(*((_DWORD *)this + 64) + 16), 4 * v5);
    v13 = v12;
    v14 = *((_DWORD **)v12 + 2);
    *v14 = v29[0];
    v14[1] = v29[1];
    if ( v11 )
    {
      v15 = *((_DWORD *)v13 + 2);
      *(_DWORD *)(v15 + 8) = v30;
      v16 = v31;
    }
    else
    {
      v17 = *((_DWORD *)this + 5);
      v18 = *(unsigned int **)(v17 + 4 * v31);
      v34 = v30;
      v19 = *(unsigned int **)(v17 + 4 * v30);
      v20 = v19[14];
      v36 = v31;
      if ( v20 != -1 )
      {
        v19 = *(unsigned int **)(*((_DWORD *)this + 5) + 4 * v20);
        v34 = v20;
      }
      v21 = v18[14];
      if ( v21 != -1 )
      {
        v18 = *(unsigned int **)(*((_DWORD *)this + 5) + 4 * v21);
        v36 = v21;
      }
      v22 = D3DXShader::CBaseProgram::AddArgument(this, a2: v19[1], a3: v19[3], a4: v19[4], a5: 0.0);
      v27 = v18[4];
      v26 = v18[3];
      v35 = v22;
      v37 = D3DXShader::CBaseProgram::AddArgument(this, a2: v18[1], a3: v26, a4: v27, a5: 0.0);
      if ( v35 == -1 || v37 == -1 )
      {
        v4 = -2147024882;
LABEL_30:
        if ( v38 != nullptr )
          D3DXShader::CInstruction::`scalar deleting destructor'(this: v38, a2: 1);
        return v4;
      }
      v23 = 4 * v35;
      *(_DWORD *)(*(_DWORD *)(v23 + *((_DWORD *)this + 5)) + 60) = v34 ^ 0x80000;
      v24 = 4 * v37;
      *(_DWORD *)(*(_DWORD *)(4 * v37 + *((_DWORD *)this + 5)) + 60) = v36 ^ 0x80000;
      *(_DWORD *)(*(_DWORD *)(v23 + *((_DWORD *)this + 5)) + 56) = v34;
      *(_DWORD *)(*(_DWORD *)(v24 + *((_DWORD *)this + 5)) + 56) = v36;
      *(_DWORD *)(*((_DWORD *)v13 + 2) + 8) = v35;
      v15 = *((_DWORD *)v13 + 2);
      v16 = v37;
    }
    *(_DWORD *)(v15 + 12) = v16;
    v25 = v32;
    *(_DWORD *)(*((_DWORD *)v13 + 2) + 16) = v32;
    *(_DWORD *)(*((_DWORD *)v13 + 2) + 20) = v25;
    if ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *, struct D3DXShader::CInstruction *))(*(_DWORD *)this + 48))(
           a1: this,
           a2: v13) != 0 )
      v4 = 1;
    else
      v4 = D3DXShader::CInstruction::Initialize(this: *((D3DXShader::CInstruction **)this + 64), a2: v13);
    goto LABEL_30;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1021B920
// Name: protected: long D3DXShader::CShaderProgram::ConvertDP2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ConvertDP2(D3DXShader::CShaderProgram *this)
{
  unsigned __int8 *v3; // eax
  int v4; // edi
  int v5; // ebx
  unsigned int i; // eax
  unsigned int v7; // eax

  if ( **((_DWORD **)this + 64) != 1342177282 )
    return 1;
  v3 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v3 != nullptr )
    v4 = D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v3);
  else
    v4 = 0;
  if ( v4 == 0 )
    return -2147024882;
  v5 = D3DXShader::CInstruction::Initialize(
         this: (D3DXShader::CInstruction *)v4,
         a2: 0x70800002u,
         a3: 6u,
         a4: 1u,
         a5: 0);
  if ( v5 >= 0 )
  {
    v5 = D3DXShader::CInstruction::Instance(
           this: (D3DXShader::CInstruction *)v4,
           a2: *((struct D3DXShader::CInstruction **)this + 64));
    if ( v5 >= 0 )
    {
      **(_DWORD **)(v4 + 16) = **(_DWORD **)(*((_DWORD *)this + 64) + 16);
      for ( i = 0; i < 0x10; i += 4 )
        *(_DWORD *)(i + *(_DWORD *)(v4 + 8)) = *(_DWORD *)(i + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
      v7 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 0.0);
      if ( v7 == -1 )
        return -2147024882;
      *(_DWORD *)(*(_DWORD *)(v4 + 8) + 16) = v7;
      *(_DWORD *)(*(_DWORD *)(v4 + 8) + 20) = v7;
      if ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int))(*(_DWORD *)this + 48))(a1: this, a2: v4) != 0 )
        v5 = 1;
      else
        v5 = D3DXShader::CInstruction::Initialize(
               this: *((D3DXShader::CInstruction **)this + 64),
               a2: (struct D3DXShader::CInstruction *)v4);
    }
  }
  D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v4, a2: 1);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1021BA16
// Name: protected: long D3DXShader::CShaderProgram::PlaceInstruction(class D3DXShader::CInstruction __near *,class D3DXShader::CInstruction __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::PlaceInstruction(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction *a2,
        struct D3DXShader::CInstruction **a3,
        unsigned int a4)
{
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // eax
  unsigned int v9; // eax
  _DWORD *v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // edx
  struct D3DXShader::CInstruction *v14; // ecx
  struct D3DXShader::CInstruction *v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // edi
  unsigned int j; // eax
  D3DXShader::CInstruction *v21; // ecx
  unsigned int k; // eax
  int v23; // ecx
  int v24; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  _DWORD *v26; // [esp+10h] [ebp-10h]
  _DWORD *v27; // [esp+14h] [ebp-Ch]
  unsigned int v28; // [esp+18h] [ebp-8h]
  unsigned int v29; // [esp+1Ch] [ebp-4h]
  unsigned int v30; // [esp+28h] [ebp+8h]

  if ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *, struct D3DXShader::CInstruction *, _DWORD))(*(_DWORD *)this + 32))(
         a1: this,
         a2,
         a3: 0) != 0 )
    goto LABEL_39;
  v29 = 0;
  v6 = *((_DWORD *)a2 + 3);
  v30 = -1;
  if ( v6 != 0 )
  {
    v7 = *((_DWORD **)a2 + 4);
    for ( i = v6; i != 0; --i )
    {
      v8 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v7);
      if ( v29 < *(_DWORD *)(v8 + 76) )
        v29 = *(_DWORD *)(v8 + 76);
      v9 = *(_DWORD *)(v8 + 72);
      if ( v30 > v9 )
        v30 = v9;
      ++v7;
    }
  }
  if ( *((_DWORD *)a2 + 1) != 0 )
  {
    v26 = *((_DWORD **)a2 + 2);
    v24 = *((_DWORD *)a2 + 1);
    do
    {
      v10 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *v26);
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v10[1]) + 4) & 2) != 0 )
      {
        v11 = v10[18];
        if ( v11 != -1 )
        {
          v12 = v11 + 1;
          if ( v29 < v12 )
            v29 = v12;
          while ( 1 )
          {
            v16 = v10[20];
            if ( v30 < v16 )
              break;
            if ( v16 == -1 )
              goto LABEL_29;
            v13 = 0;
            if ( a4 == 0 )
              goto LABEL_29;
            v14 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v16);
            do
            {
              if ( a3[v13] == v14 )
                break;
              ++v13;
            }
            while ( v13 < a4 );
            if ( v13 >= a4 )
              goto LABEL_29;
            v15 = a3[v13];
            v28 = 0;
            if ( *((_DWORD *)v15 + 3) != 0 )
            {
              v27 = *((_DWORD **)v15 + 4);
              do
              {
                if ( v10[4] == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v27) + 16) )
                  break;
                ++v28;
                ++v27;
              }
              while ( v28 < *((_DWORD *)v15 + 3) );
            }
            if ( v28 >= *((_DWORD *)v15 + 3) )
            {
LABEL_29:
              v30 = v10[20] - 1;
              break;
            }
            v10 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v15 + 4) + 4 * v28));
          }
        }
      }
      ++v26;
      --v24;
    }
    while ( v24 != 0 );
  }
  v17 = 0;
  if ( a4 != 0 )
  {
    do
    {
      v18 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)a3[v17] + 4)) + 72);
      if ( v18 >= v29 && v18 <= v30 )
        break;
      ++v17;
    }
    while ( v17 < a4 );
  }
  else
  {
    v18 = 0;
  }
  if ( v17 == a4
    || (*(int (__thiscall **)(D3DXShader::CShaderProgram *, struct D3DXShader::CInstruction *, unsigned int))(*(_DWORD *)this + 52))(
         a1: this,
         a2,
         a3: v18) != 0 )
  {
LABEL_39:
    if ( a2 != nullptr )
      D3DXShader::CInstruction::`scalar deleting destructor'(this: a2, a2: 1);
    return 1;
  }
  else
  {
    for ( j = 0; j < a4; ++j )
      *(_DWORD *)a3[j] = 0;
    v21 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v18);
    if ( v21 != nullptr )
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v21, a2: 1);
    *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v18) = a2;
    for ( k = 0; k < *((_DWORD *)a2 + 3); *(_DWORD *)(v23 + 72) = v18 )
      v23 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)a2 + 4) + 4 * k++));
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021BBEB
// Name: protected: long D3DXShader::CShaderProgram::MatchMAX(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchMAX(D3DXShader::CShaderProgram *this)
{
  unsigned int v1; // eax
  int v2; // edi
  _DWORD *v3; // edx
  _DWORD *v4; // esi
  unsigned int v6; // [esp+Ch] [ebp-Ch]
  _DWORD *v7; // [esp+10h] [ebp-8h]
  _DWORD *v8; // [esp+14h] [ebp-4h]

  v1 = **((_DWORD **)this + 64) & 0xFFFFF;
  v6 = 0;
  if ( v1 != 0 )
  {
    v2 = *((_DWORD *)this + 5);
    v8 = *(_DWORD **)(*((_DWORD *)this + 64) + 8);
    v7 = &v8[v1];
    while ( 1 )
    {
      v3 = *(_DWORD **)(v2 + 4 * *v8);
      v4 = *(_DWORD **)(v2 + 4 * *v7);
      if ( v3[1] != v4[1] || v3[2] != v4[2] || v3[3] != v4[3] || v3[4] != v4[4] || (v3[15] ^ v4[15]) != 0x80000 )
        return 1;
      ++v6;
      ++v8;
      ++v7;
      if ( v6 >= v1 )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    **((_DWORD **)this + 64) = **((_DWORD **)this + 64) & 0xFFFFF | 0x70000000;
    *(_DWORD *)(*((_DWORD *)this + 64) + 4) = v1;
    if ( v1 != 0
      && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 8)) + 62) & 8) != 0 )
    {
      qmemcpy(
        *(void **)(*((_DWORD *)this + 64) + 8),
        (const void *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * v1),
        4 * v1);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021BCDE
// Name: protected: long D3DXShader::CShaderProgram::MatchABS(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchABS(D3DXShader::CShaderProgram *this)
{
  _DWORD *v1; // eax
  unsigned int v2; // edx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  int v6; // eax
  D3DXShader::CShaderProgram *v8; // [esp+10h] [ebp-18h]
  int v9; // [esp+14h] [ebp-14h]
  int v10; // [esp+18h] [ebp-10h]
  _DWORD *v11; // [esp+1Ch] [ebp-Ch]
  _DWORD *v12; // [esp+20h] [ebp-8h]
  unsigned int v13; // [esp+24h] [ebp-4h]

  v1 = *((_DWORD **)this + 64);
  v2 = *v1 & 0xFFFFF;
  v8 = this;
  v13 = 0;
  if ( v2 != 0 )
  {
    v3 = v1[2];
    v4 = *((_DWORD *)this + 5);
    v11 = (_DWORD *)(v3 + 4 * v2);
    v12 = (_DWORD *)(v3 + 8 * v2);
    while ( 1 )
    {
      v5 = *(_DWORD *)(v3 + 4 * v13);
      v9 = *(_DWORD *)(v4 + 4 * v5);
      v10 = *(_DWORD *)(v4 + 4 * *v12);
      if ( v5 != *v11 )
        return 1;
      v6 = *(_DWORD *)(v10 + 56);
      if ( v6 != *(_DWORD *)(4 * v13 + *(_DWORD *)(*((_DWORD *)this + 64) + 8))
        && (v6 == -1 || v6 != *(_DWORD *)(v9 + 56)) )
      {
        return 1;
      }
      if ( (*(_DWORD *)(v10 + 60) ^ 0x80000) != *(_DWORD *)(v9 + 60) )
        return 1;
      ++v13;
      ++v12;
      ++v11;
      this = v8;
      if ( v13 >= v2 )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    **((_DWORD **)this + 64) = v2 & 0xFFFFF | 0x70000000;
    *(_DWORD *)(*((_DWORD *)this + 64) + 4) = v2;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021BDB0
// Name: protected: long D3DXShader::CShaderProgram::MatchABS2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchABS2(D3DXShader::CShaderProgram *this)
{
  unsigned int v1; // eax
  int v2; // edx
  int v3; // ebx
  int v4; // esi
  int v5; // esi
  int v6; // esi
  D3DXShader::CShaderProgram *v8; // [esp+14h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  _DWORD *v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  unsigned int v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]

  v1 = **((_DWORD **)this + 64) & 0xFFFFF;
  v8 = this;
  v13 = 0;
  if ( v1 != 0 )
  {
    v2 = *((_DWORD *)this + 5);
    v3 = *(_DWORD *)(*((_DWORD *)this + 64) + 8);
    v14 = 8 * v1;
    v11 = (_DWORD *)(v3 + 4 * v1);
    while ( 1 )
    {
      v4 = *(_DWORD *)(v3 + 4 * v13);
      v9 = *(_DWORD *)(v2 + 4 * v4);
      v10 = *(_DWORD *)(v2 + 4 * *v11);
      v12 = *(_DWORD *)(v2 + 4 * *(_DWORD *)(v14 + v3));
      if ( v4 != *v11 )
        return 1;
      this = v8;
      v5 = *(_DWORD *)(v10 + 56);
      if ( v5 != *(_DWORD *)(v14 + *(_DWORD *)(*((_DWORD *)v8 + 64) + 8)) && (v5 == -1 || v5 != *(_DWORD *)(v12 + 56)) )
        return 1;
      if ( (*(_DWORD *)(v10 + 60) ^ 0x80000) != *(_DWORD *)(v12 + 60) )
        return 1;
      v6 = *(_DWORD *)(v9 + 56);
      if ( v6 != *(_DWORD *)(v14 + *(_DWORD *)(*((_DWORD *)v8 + 64) + 8)) && (v6 == -1 || v6 != *(_DWORD *)(v12 + 56)) )
        return 1;
      if ( (*(_DWORD *)(v9 + 60) ^ 0x80000) != *(_DWORD *)(v12 + 60) )
        return 1;
      ++v13;
      ++v11;
      v14 += 4;
      if ( v13 >= v1 )
        goto LABEL_13;
    }
  }
  else
  {
LABEL_13:
    **((_DWORD **)this + 64) = v1 & 0xFFFFF | 0x70000000;
    *(_DWORD *)(*((_DWORD *)this + 64) + 4) = v1;
    qmemcpy(
      *(void **)(*((_DWORD *)this + 64) + 8),
      (const void *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 8 * v1),
      4 * v1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021BEE2
// Name: protected: long D3DXShader::CShaderProgram::FindComp(unsigned int,class D3DXShader::CInstruction __near * __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::FindComp(
        D3DXShader::CShaderProgram *this,
        unsigned int a2,
        struct D3DXShader::CInstruction **a3,
        unsigned int *a4)
{
  _DWORD *v4; // eax
  int v5; // esi
  int v6; // edx
  struct D3DXShader::CInstruction *v7; // edi
  unsigned int v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  unsigned int *v11; // esi
  int v12; // eax
  int v13; // edx
  unsigned int *v14; // edx
  int v15; // ecx
  unsigned int v17; // [esp+10h] [ebp-4h]
  unsigned int *v18; // [esp+1Ch] [ebp+8h]

  v4 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * a2);
  v5 = v4[18];
  if ( v4[22] != v4[21] )
    return 1;
  v6 = -1;
  if ( v5 == -1 )
    return 1;
  v7 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v5);
  if ( (*(_DWORD *)v7 & 0xFFF00000) != 0x20400000 )
    return 1;
  v17 = 0;
  v8 = *((_DWORD *)v7 + 3);
  if ( v8 == 0 )
    return 1;
  v9 = *((_DWORD **)v7 + 4);
  do
  {
    if ( *v9 == a2 )
      v6 = v17;
    ++v17;
    ++v9;
  }
  while ( v17 < v8 );
  if ( v6 == -1 )
    return 1;
  v10 = *((_DWORD *)v7 + 2);
  v18 = (unsigned int *)(v10 + 4 * v6);
  v11 = (unsigned int *)(v10 + 4 * ((*(_DWORD *)v7 & 0xFFFFF) + v6));
  v12 = *((_DWORD *)this + 5);
  v13 = *((_DWORD *)this + 4);
  if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(*(_DWORD *)(v12 + 4 * *v11) + 4)) + 5) & 1) != 0 )
  {
    v14 = v18;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(*(_DWORD *)(v12 + 4 * *v18) + 4)) + 5) & 1) == 0 )
      return 1;
    v14 = v11;
    v11 = v18;
  }
  v15 = *((_DWORD *)this + 5);
  if ( *(double *)(*(_DWORD *)(v15 + 4 * *v11) + 32) == 1.0
    && (*(_DWORD *)(*(_DWORD *)(v15 + 4 * *v14) + 60) & 0x1F0000) == 0x80000 )
  {
    *a4 = *v14;
    *a3 = v7;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021BFF9
// Name: protected: long D3DXShader::CShaderProgram::BuildLRP(unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *,class D3DXShader::CInstruction __near *,class D3DXShader::CInstruction __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::BuildLRP(
        D3DXShader::CShaderProgram *this,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        struct D3DXShader::CInstruction *a6,
        const void **a7,
        unsigned int a8)
{
  int v8; // esi
  unsigned int v10; // esi
  bool v11; // zf
  int v12; // edi
  int result; // eax
  unsigned int *v14; // eax
  int v15; // ebx
  int v16; // edi
  unsigned int v17; // ecx
  int v18; // eax
  unsigned int *v19; // edx
  int v20; // ebx
  int v21; // ecx
  int *v22; // eax
  int v23; // ecx
  int v24; // eax
  unsigned __int8 *v25; // eax
  void **v26; // ebx
  int v27; // eax
  int v28; // esi
  _DWORD *v29; // ecx
  int v30; // edx
  int v31; // eax
  int v32; // ecx
  D3DXShader::CShaderProgram *v33; // edi
  unsigned int v34[4]; // [esp+Ch] [ebp-30h] BYREF
  struct D3DXShader::CInstruction *v35[4]; // [esp+1Ch] [ebp-20h] BYREF
  unsigned int v36; // [esp+2Ch] [ebp-10h]
  int v37; // [esp+30h] [ebp-Ch]
  D3DXShader::CShaderProgram *v38; // [esp+34h] [ebp-8h]
  unsigned int v39; // [esp+38h] [ebp-4h]
  unsigned int *v40; // [esp+4Ch] [ebp+10h]
  int v41; // [esp+4Ch] [ebp+10h]

  v8 = *(_DWORD *)a6;
  memset(v35, 0, sizeof(v35));
  v10 = v8 & 0xFFFFF;
  v11 = (*((_BYTE *)this + 111) & 2) == 0;
  v38 = this;
  v36 = v10;
  if ( v11 )
  {
    v12 = 0;
    if ( v10 != 0 )
    {
      do
      {
        result = D3DXShader::CShaderProgram::FindComp(this, a2: a2[v12], a3: &v35[v12], a4: &v34[v12]);
        if ( result != 0 )
          return result;
      }
      while ( ++v12 < v10 );
    }
    v39 = 0;
    if ( v10 != 0 )
    {
      v14 = a4;
      v15 = *((_DWORD *)this + 5);
      v37 = (char *)v35 - (char *)a4;
      while ( *(_DWORD *)(*(_DWORD *)(v15 + 4 * *(unsigned int *)((char *)v14 + (char *)v34 - (char *)a4)) + 56) == *v14
           && (*(_BYTE *)(*(_DWORD *)(v15 + 4 * *v14) + 62) & 0x1F) == 0
           && *(struct D3DXShader::CInstruction **)((char *)v14 + v37) == v35[0] )
      {
        ++v39;
        ++v14;
        if ( v39 >= v10 )
          goto LABEL_11;
      }
      return 1;
    }
LABEL_11:
    v16 = 0;
    if ( *((_DWORD *)v35[0] + 3) != 0 )
    {
      do
      {
        v17 = 0;
        v39 = 1;
        if ( v10 == 0 )
          return 1;
        v18 = *(_DWORD *)(*((_DWORD *)v35[0] + 4) + 4 * v16);
        do
        {
          if ( v18 == a2[v17] )
            v39 = 0;
          ++v17;
        }
        while ( v17 < v10 );
        if ( v39 != 0 )
          return 1;
      }
      while ( (unsigned int)++v16 < *((_DWORD *)v35[0] + 3) );
    }
  }
  else
  {
    v39 = 0;
    if ( v10 != 0 )
    {
      v19 = a4;
      v20 = *((_DWORD *)this + 5);
      do
      {
        v21 = *(_DWORD *)(v20 + 4 * *(unsigned int *)((char *)v19 + (char *)a2 - (char *)a4));
        if ( *(_DWORD *)(v21 + 56) != *v19 )
          return 1;
        if ( (*(_DWORD *)(v21 + 60) & 0x1F0000) != 0x10000 )
          return 1;
        v22 = *(int **)(v20 + 4 * *v19);
        v23 = v22[15];
        if ( (v23 & 0x1F0000) != 0 )
          return 1;
        if ( (v23 & 0x200) == 0 )
        {
          v24 = *v22;
          if ( (v24 & 4) == 0 || (v24 & 0x10) == 0 )
            return 1;
        }
        ++v39;
        ++v19;
      }
      while ( v39 < v10 );
    }
  }
  v25 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v25 != nullptr )
    v26 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v25);
  else
    v26 = nullptr;
  if ( v26 == nullptr )
    return -2147024882;
  result = D3DXShader::CInstruction::Initialize(
             this: (D3DXShader::CInstruction *)v26,
             a2: v10 & 0xFFFFF | 0x70100000,
             a3: 3 * v10,
             a4: v10,
             a5: 0);
  if ( result >= 0 )
  {
    result = D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)v26, a2: a6);
    if ( result >= 0 )
    {
      qmemcpy(v26[4], a7[4], 4 * v10);
      qmemcpy(v26[2], a4, 4 * v10);
      v40 = (unsigned int *)(8 * v36);
      qmemcpy((char *)v26[2] + 8 * v36, a3, 4 * v10);
      qmemcpy((char *)v26[2] + 4 * v10, a5, 4 * ((4 * v10) >> 2));
      v27 = *((_DWORD *)v38 + 5);
      v28 = *(_DWORD *)(v27 + 4 * *(_DWORD *)v26[4]);
      v29 = v26[2];
      v30 = *(_DWORD *)(v27 + 4 * *v29);
      v31 = *(_DWORD *)(v27 + 4 * *(unsigned int *)((char *)v40 + (_DWORD)v29));
      v32 = *(_DWORD *)(v28 + 4);
      v41 = 0;
      if ( v32 == *(_DWORD *)(v30 + 4) && *(_DWORD *)(v28 + 12) == *(_DWORD *)(v30 + 12)
        || v32 == *(_DWORD *)(v31 + 4) && *(_DWORD *)(v28 + 12) == *(_DWORD *)(v31 + 12) )
      {
        v33 = v38;
      }
      else
      {
        v33 = v38;
        if ( v32 == *((_DWORD *)v38 + 34) )
        {
LABEL_45:
          if ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *, void **, _DWORD))(*(_DWORD *)v33 + 32))(
                 a1: v33,
                 a2: v26,
                 a3: 0) == 0
            && ((*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v33 + 4) + 4 * *(_DWORD *)(v28 + 4)) + 4) & 0x20) == 0 && v41 == 0
             || (*((_BYTE *)v33 + 111) & 2) != 0) )
          {
            result = D3DXShader::CInstruction::Initialize(
                       this: *(D3DXShader::CInstruction **)(*((_DWORD *)v33 + 6) + 4 * a8),
                       a2: (struct D3DXShader::CInstruction *)v26);
            if ( result >= 0 )
            {
              D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v26, a2: 1);
              *(_DWORD *)a6 = 0;
              if ( v35[0] != nullptr )
                *(_DWORD *)v35[0] = 0;
              return 0;
            }
            return result;
          }
          D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v26, a2: 1);
          return 1;
        }
      }
      if ( (*((_BYTE *)v33 + 111) & 2) == 0 )
        v41 = 1;
      goto LABEL_45;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021C2E9
// Name: protected: long D3DXShader::CShaderProgram::ValidModifier(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ValidModifier(D3DXShader::CShaderProgram *this, unsigned int a2)
{
  int v3; // eax
  unsigned int v4; // edx
  _DWORD *i; // eax
  _DWORD *v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // edi
  _DWORD *v9; // ecx
  unsigned int v11; // [esp+14h] [ebp+8h]

  v3 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2);
  v4 = *(_DWORD *)(v3 + 84);
  if ( v4 == -1 )
    return 0;
  if ( (*((_BYTE *)this + 111) & 0x20) != 0 )
    return 0;
  v11 = *(_DWORD *)(v3 + 88);
  if ( v4 > v11 )
    return 0;
  for ( i = (_DWORD *)(*((_DWORD *)this + 6) + 4 * v4); ; ++i )
  {
    v6 = (_DWORD *)*i;
    if ( (*(_DWORD *)*i & 0xF0000000) == 0x60000000 )
    {
      v7 = v6[1];
      v8 = 0;
      if ( v7 != 0 )
        break;
    }
LABEL_10:
    if ( ++v4 > v11 )
      return 0;
  }
  v9 = (_DWORD *)v6[2];
  while ( *v9 != a2 )
  {
    ++v8;
    ++v9;
    if ( v8 >= v7 )
      goto LABEL_10;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021C359
// Name: protected: long D3DXShader::CShaderProgram::MatchLRP2(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchLRP2(struct D3DXShader::CInstruction **this, int a2)
{
  D3DXShader::CProgram *v2; // edi
  unsigned int v3; // esi
  int result; // eax
  int v5; // eax
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  bool v8; // zf
  unsigned __int8 *v9; // eax
  void **v10; // ebx
  D3DXShader::CInstruction *v11; // ecx
  int v12; // edx
  struct D3DXShader::CInstruction **v13; // edi
  D3DXShader::CProgram *v14; // esi
  int v15; // eax
  int *v16; // ecx
  int v17; // edi
  int v18; // ecx
  int v19; // edi
  unsigned int *v20; // edx
  int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // eax
  struct D3DXShader::CInstruction *v24; // ecx
  bool v25; // cf
  D3DXShader::CInstruction *v26; // ecx
  int v27; // edi
  struct D3DXShader::CInstruction *v28; // [esp-20h] [ebp-140h]
  unsigned int v29[4]; // [esp+Ch] [ebp-114h] BYREF
  char v30; // [esp+1Ch] [ebp-104h] BYREF
  char v31[16]; // [esp+2Ch] [ebp-F4h] BYREF
  struct D3DXShader::CInstruction *v32[28]; // [esp+3Ch] [ebp-E4h] BYREF
  struct D3DXShader::CInstruction *v33[16]; // [esp+ACh] [ebp-74h] BYREF
  unsigned int v34[4]; // [esp+ECh] [ebp-34h] BYREF
  unsigned int v35; // [esp+FCh] [ebp-24h]
  D3DXShader::CProgram *v36; // [esp+100h] [ebp-20h]
  char *v37; // [esp+104h] [ebp-1Ch]
  int v38; // [esp+108h] [ebp-18h]
  unsigned int *v39; // [esp+10Ch] [ebp-14h]
  unsigned int v40; // [esp+110h] [ebp-10h]
  unsigned int v41; // [esp+114h] [ebp-Ch] BYREF
  unsigned int v42; // [esp+118h] [ebp-8h]
  unsigned int *v43; // [esp+11Ch] [ebp-4h]

  v41 = 0;
  v34[0] = 0;
  v2 = (D3DXShader::CProgram *)this;
  v3 = *(_DWORD *)*(this + 64) & 0xFFFFF;
  v28 = *(this + 64);
  v36 = (D3DXShader::CProgram *)this;
  v34[1] = 1;
  v34[2] = 2;
  v34[3] = 3;
  v35 = v3;
  if ( D3DXShader::CShaderProgram::MatchComplexTree(
         (D3DXShader::CShaderProgram *)this,
         a2: v28,
         a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD2A0,
         a4: v33,
         a5: &v41,
         a6: v29,
         a7: v34,
         a8: v3,
         a9: a2) != 0
    && D3DXShader::CShaderProgram::MatchComplexTree(
         this: v2,
         a2: *((struct D3DXShader::CInstruction **)v2 + 64),
         a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD300,
         a4: v33,
         a5: &v41,
         a6: v29,
         a7: v34,
         a8: v3,
         a9: a2) != 0 )
  {
    return 1;
  }
  v40 = 0;
  v39 = v29;
  v37 = &v30;
  while ( 1 )
  {
    v42 = 0;
    if ( v3 != 0 )
    {
      v38 = (int)(*((_DWORD *)v2 + 27) << 6) >> 31;
      v43 = v39;
      while ( 1 )
      {
        v5 = *((_DWORD *)v2 + 5);
        v6 = *(_DWORD **)(v5 + 4 * *v43);
        v7 = *(_DWORD **)(v5 + 4 * (_DWORD)v32[v42]);
        if ( v38 != 0 )
        {
          if ( (v6[15] ^ v7[15]) != 0x80000 )
            break;
          v8 = v7[14] == *v43;
        }
        else
        {
          if ( v6[1] != v7[1] || v6[2] != v7[2] || v6[3] != v7[3] || v6[4] != v7[4] )
            break;
          v8 = (v6[15] ^ v7[15]) == 0x80000;
        }
        if ( v8 )
        {
          ++v42;
          ++v43;
          if ( v42 < v3 )
            continue;
        }
        break;
      }
    }
    if ( v42 != v3 )
      goto LABEL_37;
    v9 = D3DXShader::CInstruction::operator new(a1: 0x74u);
    if ( v9 != nullptr )
      v10 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v9);
    else
      v10 = nullptr;
    if ( v10 == nullptr )
      return -2147024882;
    v43 = (unsigned int *)D3DXShader::CInstruction::Initialize(
                            this: (D3DXShader::CInstruction *)v10,
                            a2: v3 & 0xFFFFF | 0x70100000,
                            a3: 3 * v3,
                            a4: v3,
                            a5: 0);
    v11 = (D3DXShader::CInstruction *)v10;
    if ( (int)v43 < 0 )
      goto LABEL_42;
    v43 = (unsigned int *)D3DXShader::CInstruction::Instance(
                            this: (D3DXShader::CInstruction *)v10,
                            a2: *((struct D3DXShader::CInstruction **)v2 + 64));
    if ( (int)v43 < 0 )
    {
      v11 = (D3DXShader::CInstruction *)v10;
LABEL_42:
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v11, a2: 1);
      return (int)v43;
    }
    qmemcpy(v10[4], *(const void **)(*((_DWORD *)v2 + 64) + 16), 4 * v3);
    qmemcpy(v10[2], v31, 4 * v3);
    qmemcpy((char *)v10[2] + 4 * v3, v37, 4 * v3);
    v12 = 2 * v35;
    v13 = (struct D3DXShader::CInstruction **)((char *)v10[2] + 8 * v35);
    v42 = 0;
    qmemcpy(v13, v32, 4 * v3);
    v14 = v36;
    v15 = *((_DWORD *)v36 + 5);
    v43 = *(unsigned int **)(v15 + 4 * *(_DWORD *)v10[4]);
    v16 = (int *)v10[2];
    v17 = *v16;
    v18 = v16[v12];
    v19 = *(_DWORD *)(v15 + 4 * v17);
    v20 = v43;
    v21 = *(_DWORD *)(v15 + 4 * v18);
    v22 = v43[1];
    if ( v22 != *(_DWORD *)(v19 + 4) )
      goto LABEL_27;
    if ( v43[3] != *(_DWORD *)(v19 + 12) )
    {
      v20 = v43;
LABEL_27:
      if ( (v22 != *(_DWORD *)(v21 + 4) || v20[3] != *(_DWORD *)(v21 + 12)) && v22 == *((_DWORD *)v36 + 34) )
        goto LABEL_32;
    }
    if ( (*((_BYTE *)v36 + 111) & 2) == 0 )
      v42 = 1;
LABEL_32:
    if ( (*(int (__thiscall **)(D3DXShader::CProgram *, void **, _DWORD))(*(_DWORD *)v36 + 32))(a1: v36, a2: v10, a3: 0) == 0
      && ((*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v14 + 4) + 4 * v43[1]) + 4) & 0x20) == 0 && v42 == 0
       || (*((_BYTE *)v14 + 111) & 2) != 0) )
    {
      break;
    }
    D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v10, a2: 1);
    v3 = v35;
    v2 = v36;
LABEL_37:
    ++v40;
    v39 += 4;
    v37 -= 16;
    if ( v40 >= 2 )
      return 1;
  }
  if ( a2 == 0 )
  {
    v38 = *(_DWORD *)v33[0];
    *(_DWORD *)v33[0] = 0;
  }
  if ( (*((_BYTE *)v14 + 111) & 2) != 0
    && (*(_BYTE *)(v19 + 61) & 2) == 0
    && ((*(_DWORD *)v19 & 4) == 0 || (*(_DWORD *)v19 & 0x10) == 0) )
  {
    D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v10, a2: 1);
    D3DXShader::CProgram::Warning(
      this: v14,
      a2: *(struct D3DXShader::CNode **)(*((_DWORD *)v14 + 64) + 60),
      a3: 0x125Fu,
      format: "cannot match lerp because lerp factor is not _sat'd");
    *(_DWORD *)v33[0] = v38;
    return 1;
  }
  if ( a2 == 0 )
  {
    v23 = 0;
    if ( v41 != 0 )
    {
      do
      {
        v24 = v33[v23++];
        v25 = v23 < v41;
        *(_DWORD *)v24 = 0;
      }
      while ( v25 );
    }
    v26 = *(D3DXShader::CInstruction **)(*((_DWORD *)v14 + 6) + 4 * *((_DWORD *)v14 + 63));
    if ( v26 != nullptr )
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v26, a2: 1);
    *(_DWORD *)(*((_DWORD *)v14 + 6) + 4 * *((_DWORD *)v14 + 63)) = v10;
    return 0;
  }
  v27 = D3DXShader::CInstruction::Initialize(
          this: *((D3DXShader::CInstruction **)v14 + 64),
          a2: (struct D3DXShader::CInstruction *)v10);
  D3DXShader::CInstruction::`scalar deleting destructor'(this: (D3DXShader::CInstruction *)v10, a2: 1);
  if ( v27 < 0 )
    return v27;
  result = D3DXShader::CInstruction::Instance(
             this: *((D3DXShader::CInstruction **)v14 + 64),
             a2: *((struct D3DXShader::CInstruction **)v14 + 64));
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021C6FC
// Name: protected: long D3DXShader::CShaderProgram::Scan(unsigned int __near *,int __near *,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::Scan(
        D3DXShader::CShaderProgram *this,
        unsigned int *a2,
        int *a3,
        unsigned int a4,
        int a5)
{
  int *v8; // ebx
  int v9; // ecx
  unsigned int v10; // eax
  _DWORD *v11; // ecx
  _DWORD *v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // [esp+8h] [ebp-10h]
  int v17; // [esp+Ch] [ebp-Ch]
  unsigned int i; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]
  _DWORD *v20; // [esp+28h] [ebp+10h]

  if ( a4 > 0x1E )
    return -2147467259;
  if ( *((_DWORD *)this + 63) < *((_DWORD *)this + 3) )
  {
    v8 = a3;
    do
    {
      v9 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)this + 63));
      v10 = *(_DWORD *)v9 & 0xFFF00000;
      v20 = (_DWORD *)v9;
      if ( v10 == 1933574144 || a5 != 0 && (v10 == 1930428416 || v10 == 1932525568) )
        return 0;
      if ( v10 == 1929379840 || v10 == 1932525568 || v10 == 1930428416 || v10 == 1931476992 )
      {
        v19 = 1;
        if ( v10 == 1930428416 || v10 == 1931476992 )
          v19 = 0;
        v17 = 0;
        if ( a4 != 0 )
        {
          v16 = **(_DWORD **)(v9 + 16);
          v11 = v8 + 1;
          for ( i = a4; i != 0; --i )
          {
            if ( v16 == *(_DWORD *)((char *)v11 + (char *)a2 - (char *)v8) && *v11 == v19 )
              v17 = 1;
            ++v11;
          }
          if ( v17 != 0 )
          {
            if ( v10 == 1929379840 || v10 == 1931476992 )
              *v20 = 0;
            else
              *v20 = 1933574144;
            ++*((_DWORD *)this + 63);
            v8 = a3;
            a2[a4 + 1] = a2[a4];
            a3[a4 + 1] = a3[a4];
            D3DXShader::CShaderProgram::Scan(this, a2, a3, a4: a4 + 1, a5: 1);
            v12 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)this + 63));
            v13 = *v12 & 0xFFF00000;
            switch ( v13 )
            {
              case 0x73400000u:
                *v12 = 0;
                break;
              case 0x73100000u:
                *v12 = 1931476993;
                break;
              case 0x73300000u:
                *v12 = 1929379841;
                break;
              default:
                break;
            }
            goto LABEL_37;
          }
          v8 = a3;
          v9 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)this + 63));
        }
        if ( v10 == 1929379840 || v10 == 1931476992 )
        {
          ++*((_DWORD *)this + 63);
          a2[a4 + 1] = **(_DWORD **)(v9 + 16);
          v8[a4 + 1] = v19;
          D3DXShader::CShaderProgram::Scan(this, a2, a3: v8, a4: a4 + 1, a5: 0);
        }
      }
LABEL_37:
      v14 = *((_DWORD *)this + 63);
      if ( v14 >= *((_DWORD *)this + 3) )
        return -2147467259;
      v15 = **(_DWORD **)(*((_DWORD *)this + 6) + 4 * v14) & 0xFFF00000;
      if ( v15 == 1930428416 || v15 == 1932525568 )
        v8[a4] = v8[a4] == 0;
      ++*((_DWORD *)this + 63);
    }
    while ( *((_DWORD *)this + 63) < *((_DWORD *)this + 3) );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021C90A
// Name: private: long D3DXShader::CShaderProgram::RFC_Convert(char const __near *,unsigned long,class D3DXShader::CArgument __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::RFC_Convert(
        D3DXShader::CShaderProgram *this,
        char *a2,
        unsigned int a3,
        struct D3DXShader::CArgument *a4,
        unsigned int *a5)
{
  struct D3DXShader::CArgument *v5; // ebx
  int v7; // edi
  int v8; // eax
  char *v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // eax
  int v12; // edi
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  const char *v16; // eax
  unsigned int v17; // eax
  int v18; // edi
  int v19; // eax
  int v20; // eax
  D3DXShader::CBaseProgram *v21; // ecx
  int v22; // eax
  struct D3DXShader::CInstruction *v23; // eax
  _DWORD *j; // edx
  unsigned int v25; // eax
  unsigned int **v26; // ebx
  unsigned int *v27; // ecx
  unsigned int v29; // [esp+14h] [ebp-14h]
  D3DXShader::CArgument *v30; // [esp+18h] [ebp-10h]
  struct D3DXShader::CInstruction *v31; // [esp+1Ch] [ebp-Ch]
  struct D3DXShader::CInstruction *v32; // [esp+1Ch] [ebp-Ch]
  int v33; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+20h] [ebp-8h]
  unsigned int v35; // [esp+24h] [ebp-4h]
  const char *v36; // [esp+30h] [ebp+8h]
  const char *v37; // [esp+30h] [ebp+8h]
  unsigned int v38; // [esp+34h] [ebp+Ch]
  unsigned int v39; // [esp+34h] [ebp+Ch]

  v5 = a4;
  if ( *((_DWORD *)a4 + 12) != -1 )
    goto LABEL_43;
  v7 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)a4 + 1));
  v8 = *(_DWORD *)(v7 + 4);
  if ( (v8 & 0x800) != 0 )
    v9 = *(char **)v7;
  else
    v9 = a2;
  v10 = D3DXShader::CBaseProgram::AddPool(this, a2: v9, a3: a3 | v8 | 0x40, a4: 0xFFFFFFFF, a5: 4u);
  v31 = (struct D3DXShader::CInstruction *)v10;
  if ( v10 == -1 )
    return -2147024882;
  if ( (*(_BYTE *)(v7 + 5) & 1) == 0 )
  {
    v33 = 0;
    v36 = nullptr;
    v35 = *((_DWORD *)this + 2);
    if ( v35 != 0 )
    {
      do
      {
        v12 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * (_DWORD)v36);
        if ( *(_DWORD *)(v12 + 4) == *((_DWORD *)a4 + 1)
          && (v13 = *(_DWORD *)(v12 + 96)) == *((_DWORD *)a4 + 24)
          && v13 != 0
          && *(_DWORD *)(v12 + 8) == -1
          || a4 == (struct D3DXShader::CArgument *)v12 )
        {
          v14 = D3DXShader::CBaseProgram::AddArgument(
                  this,
                  a2: (unsigned int)v31,
                  a3: *(_DWORD *)(v12 + 100),
                  a4: 0,
                  a5: *(double *)(v12 + 32));
          *(_DWORD *)(v12 + 48) = v14;
          if ( v14 == -1 )
            return -2147024882;
          v30 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v14);
          D3DXShader::CArgument::Instance(this: v30, a2: (struct D3DXShader::CArgument *)v12);
          *((_DWORD *)v30 + 28) = 4 * *((_DWORD *)v30 + 25);
          if ( *(_DWORD *)(v12 + 68) != -1 )
            v33 = 1;
        }
        ++v36;
      }
      while ( (unsigned int)v36 < v35 );
    }
    v15 = *((_DWORD *)this + 56);
    if ( v15 != 0 && v33 != 0 )
    {
      if ( (a3 & 0x2000) != 0 )
        v16 = *(const char **)(v15 + 180);
      else
        v16 = *(const char **)(v15 + 184);
      v37 = v16;
      if ( v16 == (const char *)-1 )
        return -2147024882;
      v17 = 0;
      for ( i = 0; i < v35; v17 = ++i )
      {
        v18 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v17);
        if ( *(_DWORD *)(v18 + 4) == *((_DWORD *)v5 + 1)
          && (v19 = *(_DWORD *)(v18 + 96)) == *((_DWORD *)v5 + 24)
          && v19 != 0
          && *(_DWORD *)(v18 + 8) == -1
          || v5 == (struct D3DXShader::CArgument *)v18 )
        {
          v29 = D3DXShader::CBaseProgram::AddArgument(
                  this: *((D3DXShader::CBaseProgram **)this + 56),
                  a2: (unsigned int)v37,
                  a3: *(_DWORD *)(v18 + 100),
                  a4: 0,
                  a5: *(double *)(v18 + 32));
          if ( v29 == -1 )
            return -2147024882;
          v20 = *(_DWORD *)(v18 + 68);
          if ( v20 != -1 )
          {
            v21 = *((D3DXShader::CBaseProgram **)this + 56);
            v22 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v21 + 5) + 4 * v20) + 72);
            if ( v22 != -1 )
            {
              v23 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)v21 + 6) + 4 * v22);
              v32 = v23;
              if ( (*(_DWORD *)v23 & 0xFFF00000) == 0x10000000 )
              {
                v38 = 0;
                if ( *((_DWORD *)v23 + 3) != 0 )
                {
                  for ( j = *((_DWORD **)v23 + 4); *j != *(_DWORD *)(v18 + 68); ++j )
                  {
                    if ( ++v38 >= *((_DWORD *)v23 + 3) )
                      break;
                  }
                }
                v39 = *(_DWORD *)(*((_DWORD *)v23 + 2) + 4 * v38);
                v25 = D3DXShader::CBaseProgram::AddInstruction(this: v21, a2: 0x10000001u, a3: 1u, a4: 1u);
                if ( v25 == -1 )
                  return -2147024882;
                v26 = *(unsigned int ***)(*(_DWORD *)(*((_DWORD *)this + 56) + 24) + 4 * v25);
                D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)v26, a2: v32);
                *v26[4] = v29;
                v27 = v26[2];
                v5 = a4;
                *v27 = v39;
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v18 + 48)) + 68) = v29;
              }
            }
          }
        }
      }
    }
LABEL_43:
    *a5 = *((_DWORD *)v5 + 12);
    return 0;
  }
  v11 = D3DXShader::CBaseProgram::AddArgument(this, a2: v10, a3: *((_DWORD *)a4 + 25), a4: 0, a5: *((double *)a4 + 4));
  *((_DWORD *)a4 + 12) = v11;
  if ( v11 != -1 )
  {
    *a5 = v11;
    D3DXShader::CArgument::Instance(
      this: *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *((_DWORD *)a4 + 12)),
      a2: a4);
    return 0;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x1021CBA4
// Name: private: long D3DXShader::CShaderProgram::Reschedule_Exchange(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::Reschedule_Exchange(
        D3DXShader::CShaderProgram *this,
        unsigned int a2,
        unsigned int a3)
{
  int v3; // edi
  unsigned int v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // eax

  v3 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * a3);
  v4 = a3;
  if ( a3 >= a2 )
  {
    if ( a3 > a2 )
    {
      do
      {
        v6 = (_DWORD *)(*((_DWORD *)this + 6) + 4 * v4--);
        *v6 = *(v6 - 1);
      }
      while ( v4 > a2 );
    }
  }
  else
  {
    do
    {
      v5 = (_DWORD *)(*((_DWORD *)this + 6) + 4 * v4++);
      *v5 = v5[1];
    }
    while ( v4 < a2 );
  }
  *(_DWORD *)(*((_DWORD *)this + 6) + 4 * a2) = v3;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021CBF1
// Name: private: long D3DXShader::CShaderProgram::Reschedule_FindCoissue(struct D3DXShader::_D3DXCP_DATA __near *,class D3DXShader::CInstruction __near * __near *,class D3DXShader::CInstruction __near * __near *,unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::Reschedule_FindCoissue(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::_D3DXCP_DATA *a2,
        struct D3DXShader::CInstruction **a3,
        struct D3DXShader::CInstruction **a4,
        unsigned int a5,
        int a6,
        int a7)
{
  unsigned int v7; // edi
  int result; // eax
  D3DXShader::CInstruction *v10; // esi
  struct D3DXShader::CInstruction *v11; // esi
  int v12; // edx
  _DWORD *v13; // edx
  int v14; // ecx
  int v15; // ecx
  D3DXShader::CProgram *v16; // ecx
  int v17; // eax
  _DWORD *v18; // esi
  int v19; // [esp+8h] [ebp-14h]
  int i; // [esp+8h] [ebp-14h]
  int v21; // [esp+Ch] [ebp-10h]
  unsigned int v22; // [esp+10h] [ebp-Ch]
  int v23; // [esp+14h] [ebp-8h]
  int v24; // [esp+18h] [ebp-4h]

  v7 = a5;
  result = 1;
  v21 = 1;
  if ( a5 == 0 )
    return result;
  v10 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * a5 - 4);
  if ( D3DXShader::CInstruction::IsFlowControl(this: v10) != 0
    || (*(_DWORD *)v10 & 0xF0000000) == 0x60000000
    || (*(_DWORD *)v10 & 0xFFF00000) == 0x11000000 )
  {
    return 1;
  }
  v22 = a5 - 1;
  if ( (int)(a5 - 1) < 0 )
    return v21;
  while ( 1 )
  {
    v11 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v22);
    if ( *((_DWORD *)v11 + 9) != v7 && (*(_DWORD *)v11 & 0xFFF00000) != 0 )
    {
      if ( (*(_DWORD *)v11 & 0xF0000000) == 0x60000000 || (*(_DWORD *)v11 & 0xFFF00000) == 0x11000000 )
        return v21;
      D3DXShader::CShaderProgram::ColorParents(this, a2: a4, a3: v11, a4: v7);
      v23 = 0;
      v24 = (v12 & *(_DWORD *)v11) == 1342177280;
      if ( *((_DWORD *)v11 + 3) != 0 )
      {
        v13 = *((_DWORD **)v11 + 4);
        v19 = *((_DWORD *)v11 + 3);
        do
        {
          v14 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v13);
          if ( (*((_DWORD *)this + 27) & 0x10000000) != 0 )
            v15 = *(_DWORD *)(v14 + 16);
          else
            v15 = *(_DWORD *)(*((_DWORD *)a2 + 5) + 4 * (*(_DWORD *)(v14 + 16) + 4 * *(_DWORD *)(v14 + 12)));
          if ( v15 == 3 )
            v23 = 1;
          else
            v24 = 1;
          ++v13;
          --v19;
        }
        while ( v19 != 0 );
        v7 = a5;
      }
      if ( v24 != a6 && v23 != a7 )
        break;
    }
LABEL_34:
    if ( (--v22 & 0x80000000) != 0 )
      return v21;
  }
  result = D3DXShader::CShaderProgram::Reschedule_Exchange(this, a2: v7 - 1, a3: v22);
  v21 = result;
  if ( result < 0 )
    return result;
  if ( (*((_BYTE *)this + 111) & 0x10) == 0 )
  {
    if ( D3DXShader::CProgram::CompactPool_Process(this: v16, a2, a3: 0) < 0 )
      goto LABEL_33;
    v17 = *((_DWORD *)v11 + 3);
    if ( v17 != 0 )
    {
      v18 = *((_DWORD **)v11 + 4);
      for ( i = v17; i != 0; --i )
      {
        if ( *(_DWORD *)(*((_DWORD *)a2 + 5)
                       + 4
                       * (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v18) + 16)
                        + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v18) + 12))) == 3 )
          v23 = 1;
        else
          v24 = 1;
        ++v18;
      }
    }
    if ( v24 == a6 || v23 == a7 )
    {
LABEL_33:
      qmemcpy(*((void **)this + 6), a3, 4 * *((_DWORD *)this + 3));
      v7 = a5;
      goto LABEL_34;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021CDED
// Name: private: long D3DXShader::CShaderProgram::Reschedule_FindPair(struct D3DXShader::_D3DXCP_DATA __near *,struct D3DXShader::_D3DXCP_DATA __near *,class D3DXShader::CInstruction __near * __near *,class D3DXShader::CInstruction __near * __near *,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::Reschedule_FindPair(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::_D3DXCP_DATA *a2,
        struct D3DXShader::_D3DXCP_DATA *a3,
        struct D3DXShader::CInstruction **a4,
        struct D3DXShader::CInstruction **a5,
        unsigned int a6,
        int a7)
{
  unsigned int v7; // edi
  D3DXShader::CInstruction *v10; // ebx
  D3DXShader::CInstruction *v11; // ebx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  D3DXShader::CProgram *v18; // ecx
  D3DXShader::CShaderProgram *v19; // ecx

  v7 = a6;
  if ( a6 == 0 )
    return 1;
  v10 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * a6 - 4);
  if ( D3DXShader::CInstruction::IsFlowControl(this: v10) != 0 || (*(_DWORD *)v10 & 0xF0000000) == 0x60000000 )
    return 1;
  while ( 1 )
  {
    --a6;
    v11 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * a6);
    if ( *((_DWORD *)v11 + 9) != v7 && (*(_DWORD *)v11 & 0xFFF00000) != 0 )
    {
      if ( (*(_DWORD *)v11 & 0xF0000000) == 0x60000000 || D3DXShader::CInstruction::IsFlowControl(this: v11) != 0 )
        return 1;
      D3DXShader::CShaderProgram::ColorParents(this, a2: a5, a3: v11, a4: v7);
      v12 = *((_DWORD *)this + 6);
      v13 = *(_DWORD *)(v12 + 4 * v7 - 4);
      v14 = *(_DWORD *)(v12 + 4 * a6);
      if ( *(_DWORD *)(v13 + 12) != 0 && *(_DWORD *)(v14 + 12) != 0 )
        break;
    }
LABEL_18:
    if ( a6 == 0 )
      return 1;
  }
  v15 = *((_DWORD *)this + 5);
  v16 = *(_DWORD *)(v15 + 4 * **(_DWORD **)(v13 + 16));
  v17 = *(_DWORD *)(v15 + 4 * **(_DWORD **)(v14 + 16));
  if ( *(_DWORD *)(v16 + 20) != *(_DWORD *)(v17 + 20) || *(_DWORD *)(v16 + 24) != *(_DWORD *)(v17 + 24) )
    return 1;
  D3DXShader::CShaderProgram::Reschedule_Exchange(this, a2: v7 - 1, a3: a6);
  if ( (*((_BYTE *)this + 111) & 0x10) == 0 && D3DXShader::CProgram::CompactPool_Process(this: v18, a2, a3: 0) < 0
    || a7 != 0 && D3DXShader::CProgram::CompactPool_Process(this, a2: a3, a3: 0) < 0 )
  {
    D3DXShader::CShaderProgram::Reschedule_Exchange(this, a2: a6, a3: v7 - 1);
    D3DXShader::CShaderProgram::ColorParents(this: v19, a2: a5, a3: v11, a4: v7);
    goto LABEL_18;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021CF2A
// Name: protected: virtual long D3DXShader::CShaderProgram::Reschedule(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::Reschedule(D3DXShader::CShaderProgram *this)
{
  int result; // eax
  int v3; // esi
  bool v4; // zf
  int v5; // edi
  unsigned int v6; // esi
  void *v7; // edi
  unsigned int v8; // edx
  unsigned int i; // ecx
  int v10; // eax
  unsigned int v11; // edi
  D3DXShader::CInstruction *v12; // ecx
  struct D3DXShader::CInstruction *v13; // eax
  _DWORD *v14; // eax
  unsigned int v15; // edx
  int v16; // esi
  _DWORD *v17; // eax
  int v18; // ecx
  _DWORD *v19; // edx
  int v20; // edx
  int Pair; // eax
  const void *v22; // esi
  _BYTE v23[100]; // [esp+4h] [ebp-E8h] BYREF
  _DWORD v24[25]; // [esp+68h] [ebp-84h] BYREF
  int v25; // [esp+CCh] [ebp-20h]
  int v26; // [esp+D0h] [ebp-1Ch]
  BOOL v27; // [esp+D4h] [ebp-18h]
  int v28; // [esp+D8h] [ebp-14h]
  unsigned int v29; // [esp+DCh] [ebp-10h]
  void *pMem; // [esp+E0h] [ebp-Ch]
  struct D3DXShader::CInstruction **v31; // [esp+E4h] [ebp-8h]
  unsigned int j; // [esp+E8h] [ebp-4h]

  if ( (*((_BYTE *)this + 204) & 4) != 0 )
    return 1;
  result = D3DXShader::CProgram::CompactInstructions(this);
  if ( result >= 0 )
  {
    result = D3DXShader::CProgram::ParentChildInfo(this);
    if ( result >= 0 )
    {
      v3 = *((_DWORD *)this + 3);
      v31 = nullptr;
      pMem = nullptr;
      v26 = 0;
      v4 = (*((_BYTE *)this + 111) & 0x10) == 0;
      memset(v24, 0, sizeof(v24));
      v28 = v3;
      memset(v23, 0, sizeof(v23));
      if ( v4 )
      {
        if ( *((_DWORD *)this + 12) != 0 )
        {
          v5 = D3DXShader::CProgram::CompactPool_Begin(
                 this,
                 a2: (struct D3DXShader::_D3DXCP_DATA *)v23,
                 a3: *((_DWORD *)this + 35),
                 a4: *((_DWORD *)this + 12));
          if ( v5 < 0 )
            goto LABEL_47;
          v26 = D3DXShader::CProgram::CompactPool_Process(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v23, a3: 0) >= 0;
        }
        if ( D3DXShader::CProgram::CompactPool_Begin(
               this,
               a2: (struct D3DXShader::_D3DXCP_DATA *)v24,
               a3: *((_DWORD *)this + 34),
               a4: *((_DWORD *)this + 11) - 1) < 0
          || D3DXShader::CProgram::CompactPool_Process(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v24, a3: 0) < 0 )
        {
          D3DXShader::CProgram::CompactPool_End(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v24);
          v5 = D3DXShader::CProgram::CompactPool_Begin(
                 this,
                 a2: (struct D3DXShader::_D3DXCP_DATA *)v24,
                 a3: *((_DWORD *)this + 34),
                 a4: *((_DWORD *)this + 11));
          if ( v5 < 0
            || (v5 = D3DXShader::CProgram::CompactPool_Process(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v24, a3: 0)) < 0 )
          {
            if ( v5 != -2147024882 )
              v5 = 1;
            goto LABEL_47;
          }
        }
      }
      v6 = 4 * v3;
      v29 = v6;
      v31 = (struct D3DXShader::CInstruction **)MemAlloc_Alloc(nSize: v6);
      if ( v31 != nullptr && (v7 = MemAlloc_Alloc(nSize: v6), pMem = v7, v7 != nullptr) )
      {
        qmemcpy(v7, *((const void **)this + 6), v6);
        v8 = v28;
        qmemcpy(v31, *((const void **)this + 6), v29);
        for ( i = 0; i < v8; ++i )
        {
          v10 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * i);
          *((_DWORD *)this + 64) = v10;
          *(_DWORD *)(v10 + 36) = -1;
        }
        v11 = v8 - 1;
        for ( j = v8 - 1; (j & 0x80000000) == 0; v11 = --j )
        {
          v12 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v11);
          *((_DWORD *)this + 64) = v12;
          if ( (*(_DWORD *)v12 & 0xFFF00000) != 0
            && (*(_DWORD *)v12 & 0xF0000000) != 0x60000000
            && D3DXShader::CInstruction::IsFlowControl(this: v12) == 0 )
          {
            v13 = *((struct D3DXShader::CInstruction **)this + 64);
            if ( (*(_DWORD *)v13 & 0xFFF00000) != 0x11000000 )
            {
              D3DXShader::CShaderProgram::ColorParents(
                this,
                a2: (struct D3DXShader::CInstruction **)pMem,
                a3: v13,
                a4: v11);
              if ( (*((_BYTE *)this + 112) & 8) == 0 )
              {
                Pair = D3DXShader::CShaderProgram::Reschedule_FindPair(
                         this,
                         a2: (struct D3DXShader::_D3DXCP_DATA *)v24,
                         a3: (struct D3DXShader::_D3DXCP_DATA *)v23,
                         a4: v31,
                         a5: (struct D3DXShader::CInstruction **)pMem,
                         a6: v11,
                         a7: v26);
                goto LABEL_42;
              }
              v14 = *((_DWORD **)this + 64);
              v15 = *v14 & 0xFFF00000;
              v28 = 0;
              v27 = v15 == 1342177280;
              if ( v14[3] != 0 )
              {
                v16 = *((_DWORD *)this + 5);
                v17 = (_DWORD *)v14[4];
                v18 = (8 * *((_DWORD *)this + 27)) >> 31;
                v25 = *(_DWORD *)(*((_DWORD *)this + 64) + 12);
                do
                {
                  v19 = *(_DWORD **)(v16 + 4 * *v17);
                  if ( v18 != 0 || v24[0] != v19[1] )
                    v20 = v19[4];
                  else
                    v20 = *(_DWORD *)(v24[5] + 4 * (v19[4] + 4 * v19[3]));
                  if ( v20 == 3 )
                    v28 = 1;
                  else
                    v27 = true;
                  ++v17;
                  --v25;
                }
                while ( v25 != 0 );
              }
              if ( !v27 )
              {
                Pair = D3DXShader::CShaderProgram::Reschedule_FindCoissue(
                         this,
                         a2: (struct D3DXShader::_D3DXCP_DATA *)v24,
                         a3: v31,
                         a4: (struct D3DXShader::CInstruction **)pMem,
                         a5: j,
                         a6: 0,
                         a7: 1);
LABEL_42:
                v5 = Pair;
                if ( Pair < 0 )
                  goto LABEL_47;
                if ( Pair == 0 )
                {
                  v22 = *((const void **)this + 6);
                  --j;
                  qmemcpy(v31, v22, v29);
                }
                continue;
              }
              if ( v28 == 0 )
              {
                Pair = D3DXShader::CShaderProgram::Reschedule_FindCoissue(
                         this,
                         a2: (struct D3DXShader::_D3DXCP_DATA *)v24,
                         a3: v31,
                         a4: (struct D3DXShader::CInstruction **)pMem,
                         a5: j,
                         a6: 1,
                         a7: 0);
                goto LABEL_42;
              }
            }
          }
        }
        v5 = 0;
      }
      else
      {
        v5 = -2147024882;
      }
LABEL_47:
      if ( (*((_BYTE *)this + 111) & 0x10) == 0 )
      {
        D3DXShader::CProgram::CompactPool_End(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v24);
        if ( *((_DWORD *)this + 12) != 0 )
          D3DXShader::CProgram::CompactPool_End(this, a2: (struct D3DXShader::_D3DXCP_DATA *)v23);
      }
      free(pMem);
      free(pMem: v31);
      return v5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021D28F
// Name: int D3DXShader::IsIf(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall D3DXShader::IsIf(D3DXShader *this, unsigned int a2)
{
  return this == (D3DXShader *)1934622720
      || this == (D3DXShader *)1935671296
      || this == (D3DXShader *)1936719872
      || this == (D3DXShader *)1937768448
      || this == (D3DXShader *)284164096;
}

//------------------------------------------------------------------------------
// Address: 0x1021D2C5
// Name: int D3DXShader::IsBreak(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall D3DXShader::IsBreak(D3DXShader *this, unsigned int a2)
{
  return this == (D3DXShader *)1953497088
      || this == (D3DXShader *)1952448512
      || this == (D3DXShader *)1950351360
      || this == (D3DXShader *)1951399936
      || this == (D3DXShader *)1949302784;
}

//------------------------------------------------------------------------------
// Address: 0x1021D2FB
// Name: protected: class D3DXShader::CInstruction __near * D3DXShader::CShaderProgram::NewAndIf(class D3DXShader::CInstruction __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CInstruction *__thiscall D3DXShader::CShaderProgram::NewAndIf(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction *a2,
        int a3)
{
  unsigned int v4; // edx
  int v5; // esi
  unsigned int v6; // esi
  D3DXShader::CInstruction *v7; // ecx
  int v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  D3DXShader::CInstruction *v14; // ecx
  int v15; // edi
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  unsigned __int8 *v20; // eax
  void **v21; // edi
  int v22; // eax
  D3DXShader::CInstruction *v23; // ecx
  struct D3DXShader::CInstruction *v24; // esi
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // esi
  unsigned int v30; // eax
  int v31; // ebx
  unsigned int v33; // [esp+14h] [ebp-10h]
  unsigned int v34; // [esp+18h] [ebp-Ch]
  int v35; // [esp+1Ch] [ebp-8h]
  D3DXShader::CInstruction *v36; // [esp+20h] [ebp-4h]
  D3DXShader::CInstruction *v37; // [esp+20h] [ebp-4h]
  D3DXShader::CInstruction *v38; // [esp+20h] [ebp-4h]
  struct D3DXShader::CInstruction *v39; // [esp+2Ch] [ebp+8h]

  v35 = 0;
  v4 = *(_DWORD *)a2 & 0xFFF00000;
  v5 = *(_DWORD *)a2 & 0xFFFFF;
  v33 = v4;
  v34 = v5;
  if ( a3 == 0 )
  {
    if ( v4 != 284164096 )
    {
      switch ( v4 )
      {
        case 0x73500000u:
          v6 = v5 & 0xFFFFF | 0x73D00000;
          break;
        case 0x73600000u:
          v6 = v5 & 0xFFFFF | 0x73E00000;
          break;
        case 0x73700000u:
          v6 = v5 & 0xFFFFF | 0x73F00000;
          break;
        case 0x73800000u:
          v6 = v5 & 0xFFFFF | 0x74000000;
          break;
        default:
          return nullptr;
      }
      goto LABEL_45;
    }
    v14 = (D3DXShader::CInstruction *)v5;
    v15 = *(_DWORD *)(*((_DWORD *)this + 4)
                    + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)a2 + 2)) + 4));
    v6 = v5 & 0xFFFFF | 0x73100000;
    v37 = v14;
    if ( (*(_WORD *)(v15 + 4) & 0x208) == 0 )
      goto LABEL_43;
    if ( *(_DWORD *)v15 != 0 )
    {
      strchr(string: *(unsigned __int8 **)v15, chr: 0x69u);
      if ( v16 == 0 )
      {
        strchr(string: *(unsigned __int8 **)v15, chr: 0x49u);
        if ( v17 == 0 )
        {
          strchr(string: *(unsigned __int8 **)v15, chr: 0x62u);
          if ( v18 == 0 )
          {
            strchr(string: *(unsigned __int8 **)v15, chr: 0x42u);
            if ( v19 == 0 && (*(_BYTE *)(v15 + 5) & 8) != 0 )
            {
              v14 = v37;
LABEL_43:
              v13 = (unsigned int)v14 | 0x73F00000;
              goto LABEL_44;
            }
          }
        }
      }
      v14 = v37;
    }
    if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)a2 + 2)) + 8) == -1 )
      goto LABEL_45;
    goto LABEL_43;
  }
  switch ( v4 )
  {
    case 0x10F00000u:
      v7 = (D3DXShader::CInstruction *)v5;
      v8 = *(_DWORD *)(*((_DWORD *)this + 4)
                     + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)a2 + 2)) + 4));
      v6 = v5 & 0xFFFFF | 0x73000000;
      v36 = v7;
      if ( (*(_WORD *)(v8 + 4) & 0x208) != 0 )
      {
        if ( *(_DWORD *)v8 == 0 )
          goto LABEL_19;
        strchr(string: *(unsigned __int8 **)v8, chr: 0x69u);
        if ( v9 != 0
          || (strchr(string: *(unsigned __int8 **)v8, chr: 0x49u), v10 != 0)
          || (strchr(string: *(unsigned __int8 **)v8, chr: 0x62u), v11 != 0)
          || (strchr(string: *(unsigned __int8 **)v8, chr: 0x42u), v12 != 0)
          || (*(_BYTE *)(v8 + 5) & 8) == 0 )
        {
          v7 = v36;
LABEL_19:
          if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)a2 + 2)) + 8) == -1 )
            break;
          goto LABEL_22;
        }
        v7 = v36;
      }
LABEL_22:
      v13 = (unsigned int)v7 | 0x73B00000;
LABEL_44:
      v6 = v13;
      v35 = 1;
      break;
    case 0x73500000u:
      v6 = v5 & 0xFFFFF | 0x73900000;
      break;
    case 0x73600000u:
      v6 = v5 & 0xFFFFF | 0x73A00000;
      break;
    case 0x73700000u:
      v6 = v5 & 0xFFFFF | 0x73B00000;
      break;
    case 0x73800000u:
      v6 = v5 & 0xFFFFF | 0x73C00000;
      break;
    default:
      return nullptr;
  }
LABEL_45:
  v20 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v20 != nullptr )
  {
    v21 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v20);
    v38 = (D3DXShader::CInstruction *)v21;
  }
  else
  {
    v38 = nullptr;
    v21 = nullptr;
  }
  if ( v21 == nullptr )
    return nullptr;
  if ( v33 != 284164096 || v35 != 0 )
    v22 = D3DXShader::CInstruction::Initialize(
            this: (D3DXShader::CInstruction *)v21,
            a2: v6,
            a3: 2 * v34,
            a4: v34,
            a5: 0);
  else
    v22 = D3DXShader::CInstruction::Initialize(this: (D3DXShader::CInstruction *)v21, a2: v6, a3: v34, a4: v34, a5: 0);
  v23 = (D3DXShader::CInstruction *)v21;
  if ( v22 < 0 )
    goto LABEL_71;
  v24 = a2;
  if ( D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)v21, a2) < 0 )
  {
    v23 = (D3DXShader::CInstruction *)v21;
LABEL_71:
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v23, a2: 1);
    return nullptr;
  }
  if ( a3 != 0 )
  {
    qmemcpy(v21[4], *((const void **)a2 + 4), 4 * *((_DWORD *)a2 + 3));
    v21 = (void **)v38;
    v24 = a2;
    goto LABEL_60;
  }
  *(_DWORD *)v21[4] = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 42), a3: 0, a4: 0, a5: 0.0);
  if ( *(_DWORD *)v21[4] == -1 )
    return nullptr;
  v25 = *((_DWORD *)this + 5);
  v26 = *(_DWORD *)(v25 + 4 * *(_DWORD *)v21[4]);
  v27 = *(_DWORD *)(v25 + 4 * **((_DWORD **)a2 + 4));
  *(_DWORD *)(v26 + 24) = *(_DWORD *)(v27 + 24);
  *(_DWORD *)(v26 + 20) = *(_DWORD *)(v27 + 20);
LABEL_60:
  qmemcpy(v21[2], *((const void **)v24 + 2), 4 * *((_DWORD *)v24 + 1));
  if ( v35 != 0 )
  {
    v39 = nullptr;
    if ( *((_DWORD *)this + 2) != 0 )
    {
      v28 = *((_DWORD *)this + 5);
      v29 = *((_DWORD *)this + 2);
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(*(_DWORD *)v28 + 4)) + 5) & 1) != 0 )
        {
          v30 = *(_DWORD *)(*(_DWORD *)v28 + 12);
          if ( v30 >= (unsigned int)v39 )
            v39 = (struct D3DXShader::CInstruction *)(v30 + 1);
        }
        v28 += 4;
        --v29;
      }
      while ( v29 != 0 );
    }
    if ( *((_DWORD *)this + 98) == -1 )
      *((_DWORD *)this + 98) = D3DXShader::CBaseProgram::AddArgument(
                                 this,
                                 a2: *((_DWORD *)this + 30),
                                 a3: (unsigned int)v39,
                                 a4: 0,
                                 a5: 0.0);
    v31 = *((_DWORD *)this + 98);
    if ( v31 == -1 )
    {
      v23 = v38;
      goto LABEL_71;
    }
    *(_DWORD *)(*((_DWORD *)v38 + 2) + 4) = v31;
  }
  return v38;
}

//------------------------------------------------------------------------------
// Address: 0x1021D6AD
// Name: protected: long D3DXShader::CShaderProgram::CompactEndIfs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::CompactEndIfs(D3DXShader::CShaderProgram *this)
{
  unsigned int v2; // edi
  unsigned int v3; // ebx
  D3DXShader::CInstruction *v4; // edi
  int v5; // ecx
  int v6; // edx
  int v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // ecx
  unsigned int j; // ebx
  int v12; // [esp+Ch] [ebp-18h]
  int v13; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  int v15; // [esp+18h] [ebp-Ch]
  int v16; // [esp+1Ch] [ebp-8h]
  _DWORD *v17; // [esp+20h] [ebp-4h]

  do
  {
    v2 = 0;
    v12 = 0;
    v15 = 0;
    if ( *((_DWORD *)this + 3) == 0 )
      break;
    do
    {
      if ( D3DXShader::CInstruction::IsElse(this: *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v2)) != 0 )
      {
        v3 = v2 + 1;
        v16 = 1;
        v13 = v2 + 1;
        if ( v2 + 1 >= *((_DWORD *)this + 3) )
          goto LABEL_21;
        do
        {
          v4 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v3);
          if ( D3DXShader::CInstruction::IsEndIf(this: v4) != 0 )
            break;
          if ( (*(_DWORD *)v4 & 0xFFF00000) != 0x10000000 )
          {
            v16 = 0;
            break;
          }
          v5 = *((_DWORD *)v4 + 3);
          if ( v5 != 0 )
          {
            v6 = *((_DWORD *)this + 5);
            v17 = *((_DWORD **)v4 + 2);
            v7 = *((_DWORD *)v4 + 4) - (_DWORD)v17;
            for ( i = v5; i != 0; --i )
            {
              v8 = *(_DWORD **)(v6 + 4 * *(_DWORD *)((char *)v17 + v7));
              v9 = *(_DWORD **)(v6 + 4 * *v17);
              if ( v8[14] != v9[14]
                || v8[15] != v9[15]
                || v8[1] != v9[1]
                || v8[3] != v9[3]
                || v8[2] != v9[2]
                || v8[4] != v9[4] )
              {
                v16 = 0;
              }
              ++v17;
            }
            v3 = v13;
          }
          v13 = ++v3;
        }
        while ( v3 < *((_DWORD *)this + 3) );
        v2 = v15;
        if ( v16 != 0 )
        {
LABEL_21:
          v12 = 1;
          for ( j = v2; j < *((_DWORD *)this + 3); **(_DWORD **)(*((_DWORD *)this + 6) + 4 * j++) = 0 )
          {
            if ( D3DXShader::CInstruction::IsEndIf(this: *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * j)) != 0 )
              break;
          }
        }
      }
      v15 = ++v2;
    }
    while ( v2 < *((_DWORD *)this + 3) );
  }
  while ( v12 != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021D7E3
// Name: protected: long D3DXShader::CShaderProgram::GroupIfs(unsigned int,unsigned int,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int,int,int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::GroupIfs(
        D3DXShader::CShaderProgram *this,
        __int64 a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        unsigned int *a6,
        unsigned int a7,
        D3DXShader::CInstruction *a8,
        int a9,
        unsigned int a10,
        unsigned int a11)
{
  unsigned int v11; // eax
  bool v12; // cf
  D3DXShader::CBaseProgram *v13; // edi
  int v14; // esi
  int v15; // ebx
  D3DXShader *v16; // ecx
  unsigned int v17; // eax
  bool v18; // zf
  D3DXShader::CInstruction *v19; // edx
  int v20; // eax
  D3DXShader *v21; // ecx
  struct D3DXShader::CInstruction *v22; // eax
  int result; // eax
  struct D3DXShader::CInstruction *v24; // eax
  unsigned int v25; // eax
  unsigned __int8 *v26; // eax
  void **v27; // edi
  D3DXShader::CInstruction *v28; // ecx
  int v29; // ebx
  unsigned int v30; // eax
  int v31; // edx
  int v32; // ecx
  int v33; // ecx
  int v34; // eax
  unsigned __int8 *v35; // eax
  D3DXShader::CInstruction *v36; // eax
  struct D3DXShader::CInstruction *v37; // eax
  _DWORD *v38; // eax
  int v39; // ecx
  int v40; // edx
  int v41; // ecx
  int v42; // eax
  _DWORD *v43; // ecx
  _DWORD *v44; // eax
  unsigned int v45; // ecx
  int v46; // edx
  unsigned int v47; // ecx
  int v48; // edx
  unsigned __int8 *v49; // eax
  int v50; // eax
  char *v51; // esi
  unsigned int v52; // eax
  char *v53; // edi
  char v54; // dl
  unsigned int v55; // ecx
  char *v56; // edi
  char *v57; // esi
  char v58; // cl
  char *v59; // edi
  char *v60; // esi
  char v61; // al
  unsigned int v62; // ecx
  unsigned int v63; // eax
  unsigned int v64; // ecx
  int v65; // eax
  D3DXShader::CArgument *v66; // ecx
  int v67; // esi
  int v68; // eax
  D3DXShader::CInstruction *v69; // ecx
  int v70; // eax
  int v71; // ecx
  D3DXShader::CInstruction *v72; // ecx
  int v73; // esi
  const char *v74; // [esp+4h] [ebp-848h]
  const char *v75; // [esp+4h] [ebp-848h]
  unsigned int v76; // [esp+8h] [ebp-844h]
  unsigned int v77[128]; // [esp+14h] [ebp-838h] BYREF
  unsigned int v78[128]; // [esp+214h] [ebp-638h] BYREF
  unsigned int v79[128]; // [esp+414h] [ebp-438h] BYREF
  unsigned int v80[128]; // [esp+614h] [ebp-238h] BYREF
  unsigned int v81; // [esp+814h] [ebp-38h] BYREF
  unsigned int v82; // [esp+818h] [ebp-34h] BYREF
  D3DXShader::CArgument *i; // [esp+81Ch] [ebp-30h]
  unsigned int v84; // [esp+820h] [ebp-2Ch] BYREF
  unsigned int v85; // [esp+824h] [ebp-28h] BYREF
  D3DXShader::CBaseProgram *v86; // [esp+828h] [ebp-24h]
  unsigned int v87; // [esp+82Ch] [ebp-20h]
  struct D3DXShader::CArgument *v88; // [esp+830h] [ebp-1Ch]
  unsigned int v89; // [esp+834h] [ebp-18h] BYREF
  int v90; // [esp+838h] [ebp-14h]
  unsigned int v91; // [esp+83Ch] [ebp-10h]
  D3DXShader::CInstruction *v92; // [esp+840h] [ebp-Ch]
  unsigned int v93; // [esp+844h] [ebp-8h]
  D3DXShader::CInstruction *v94; // [esp+848h] [ebp-4h]

  v11 = *a3;
  v12 = *a3 < a7;
  v13 = this;
  v86 = this;
  v93 = v11;
  if ( !v12 )
    return 0;
  v14 = 0;
  while ( 1 )
  {
    v15 = *(_DWORD *)(*((_DWORD *)v13 + 6) + 4 * v11);
    v16 = (D3DXShader *)(*(_DWORD *)v15 & 0xFFF00000);
    v17 = *(_DWORD *)v15 & 0xFFFFF;
    v18 = *(_DWORD *)(v15 + 12) == 0;
    v90 = (int)v16;
    v91 = v17;
    if ( v18 )
    {
      D3DXShader::CProgram::Error(
        this: v13,
        a2: *(struct D3DXShader::CNode **)(v15 + 60),
        a3: 0x12DFu,
        format: "internal error: instruction missing outputs");
      return -2147467259;
    }
    v19 = *(D3DXShader::CInstruction **)(*((_DWORD *)v13 + 5) + 4 * **(_DWORD **)(v15 + 16));
    v20 = *((_DWORD *)v19 + 5);
    v92 = v19;
    if ( v20 != (_DWORD)a2 )
      break;
    if ( a9 != 0 && v16 != (D3DXShader *)287309824 )
      goto LABEL_51;
    v94 = a8;
    if ( a8 != nullptr && *((_DWORD *)v19 + 6) != HIDWORD(a2) )
      v94 = nullptr;
    if ( D3DXShader::IsIf(this: v16, a2: v76) )
    {
      if ( v91 != 1 )
      {
        v74 = "internal error: IF with size greater then 1 found";
LABEL_132:
        D3DXShader::CProgram::Error(this: v13, a2: *(struct D3DXShader::CNode **)(v15 + 60), a3: 0x12E0u, format: v74);
        return -2147467259;
      }
      if ( v94 != nullptr )
      {
        v22 = D3DXShader::CShaderProgram::NewAndIf(this: v13, a2: (struct D3DXShader::CInstruction *)v15, a3: 1);
        if ( v22 == nullptr )
          return -2147024882;
        result = D3DXShader::CBaseProgram::AddInstruction(this: v13, a2: v22);
        if ( result < 0 )
          return result;
      }
      v84 = ++v93;
      v82 = 0;
      v89 = 0;
      result = D3DXShader::CShaderProgram::GroupIfs(
                 this: v13,
                 a2: **(_DWORD **)(v15 + 16),
                 a3: 1u,
                 a4: &v84,
                 a5: v79,
                 a6: v80,
                 a7: &v89,
                 a8: a7,
                 a9: (int)v94,
                 a10: 0,
                 a11: 0,
                 a12: 0);
      if ( result < 0 )
        return result;
      if ( v94 != nullptr )
      {
        v24 = D3DXShader::CShaderProgram::NewAndIf(this: v13, a2: (struct D3DXShader::CInstruction *)v15, a3: 0);
        if ( v24 == nullptr )
          return -2147024882;
        result = D3DXShader::CBaseProgram::AddInstruction(this: v13, a2: v24);
        if ( result < 0 )
          return result;
      }
      v84 = v93;
      result = D3DXShader::CShaderProgram::GroupIfs(
                 this: v13,
                 a2: **(_DWORD **)(v15 + 16),
                 a3: 0,
                 a4: &v84,
                 a5: v77,
                 a6: v78,
                 a7: &v82,
                 a8: a7,
                 a9: (int)v94,
                 a10: 0,
                 a11: 0,
                 a12: 0);
      if ( result < 0 )
        return result;
      if ( v94 != nullptr )
      {
        v90 = 1;
        if ( v89 != v82 )
          goto LABEL_125;
        v25 = 0;
        if ( v82 != 0 )
        {
          do
          {
            if ( v78[v25] != v80[v25] )
              v90 = 0;
            ++v25;
          }
          while ( v25 < v82 );
          if ( v90 == 0 )
          {
LABEL_125:
            v75 = "internal error: endif mismatch";
            goto LABEL_126;
          }
        }
        v26 = D3DXShader::CInstruction::operator new(a1: 0x74u);
        if ( v26 != nullptr )
          v27 = (void **)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v26);
        else
          v27 = nullptr;
        v90 = (int)v27;
        if ( v27 == nullptr )
          return -2147024882;
        v94 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::Initialize(
                                            this: (D3DXShader::CInstruction *)v27,
                                            a2: v82 & 0xFFFFF | 0x73400000,
                                            a3: 2 * v82,
                                            a4: v82,
                                            a5: 0);
        v28 = (D3DXShader::CInstruction *)v27;
        if ( (int)v94 < 0 )
          goto LABEL_128;
        v29 = D3DXShader::CInstruction::Instance(
                this: (D3DXShader::CInstruction *)v27,
                a2: (struct D3DXShader::CInstruction *)v15);
        if ( v29 < 0 )
        {
          v72 = (D3DXShader::CInstruction *)v27;
LABEL_130:
          D3DXShader::CInstruction::`scalar deleting destructor'(this: v72, a2: 1);
          return v29;
        }
        qmemcpy(v27[4], v78, 4 * v89);
        qmemcpy(v27[2], v79, 4 * v89);
        qmemcpy((char *)v27[2] + 4 * v89, v77, 4 * v89);
        result = D3DXShader::CBaseProgram::AddInstruction(this: v86, a2: (struct D3DXShader::CInstruction *)v27);
        if ( result < 0 )
          return result;
        v13 = v86;
        v14 = 0;
      }
      *((_DWORD *)v92 + 1) = *((_DWORD *)v13 + 29);
      v30 = v84;
    }
    else if ( D3DXShader::IsBreak(this: v21, a2: v76) )
    {
      v81 = v93 + 1;
      v89 = 0;
      if ( v94 != nullptr )
      {
        result = D3DXShader::CBaseProgram::CopyInstruction(this: v13, a2: (struct D3DXShader::CInstruction *)v15);
        if ( result < 0 )
          return result;
        *((_DWORD *)v92 + 1) = *((_DWORD *)v13 + 29);
      }
      result = D3DXShader::CShaderProgram::GroupIfs(
                 this: v13,
                 a2: **(_DWORD **)(v15 + 16),
                 a3: 1u,
                 a4: &v81,
                 a5: v79,
                 a6: v80,
                 a7: &v89,
                 a8: a7,
                 a9: (int)v94,
                 a10: 0,
                 a11: 0,
                 a12: 0);
      if ( result < 0 )
        return result;
      v30 = v81;
    }
    else
    {
      if ( v32 != 286261248 && v32 != 1947205632 )
      {
        if ( v32 == 287309824 )
        {
          if ( v94 != nullptr && a9 != 0 )
          {
            v33 = 0;
            if ( v91 != 0 )
            {
              do
              {
                v34 = *(_DWORD *)(*((_DWORD *)v13 + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v15 + 16) + 4 * v33));
                *(_DWORD *)(v34 + 52) = a11;
                v12 = ++v33 < v91;
                *(_DWORD *)(v34 + 48) = a10;
              }
              while ( v12 );
            }
            goto LABEL_50;
          }
        }
        else if ( a8 != nullptr && *(_DWORD *)(v31 + 24) == HIDWORD(a2) )
        {
LABEL_50:
          result = D3DXShader::CBaseProgram::CopyInstruction(this: v13, a2: (struct D3DXShader::CInstruction *)v15);
          if ( result < 0 )
            return result;
        }
LABEL_51:
        ++v93;
        goto LABEL_121;
      }
      v85 = ++v93;
      v89 = 0;
      result = D3DXShader::CShaderProgram::GroupIfs(
                 this: v13,
                 a2: **(_DWORD **)(v15 + 16),
                 a3: 1u,
                 a4: &v85,
                 a5: v79,
                 a6: v80,
                 a7: &v89,
                 a8: a7,
                 a9: (int)v94,
                 a10: 1,
                 a11: a2,
                 a12: HIDWORD(a2));
      if ( result < 0 )
        return result;
      if ( v94 != nullptr )
      {
        if ( v90 == 286261248 )
        {
          v88 = (struct D3DXShader::CArgument *)(v91 & 0xFFFFF);
          *(_DWORD *)v15 = v91 & 0xFFFFF | 0x74200000;
          result = D3DXShader::CBaseProgram::CopyInstruction(this: v13, a2: (struct D3DXShader::CInstruction *)v15);
          if ( result < 0 )
            return result;
          *(_DWORD *)v15 = (unsigned int)v88 | 0x11100000;
        }
        else
        {
          result = D3DXShader::CBaseProgram::CopyInstruction(this: v13, a2: (struct D3DXShader::CInstruction *)v15);
          if ( result < 0 )
            return result;
        }
        *((_DWORD *)v92 + 1) = *((_DWORD *)v13 + 29);
      }
      v85 = v93;
      result = D3DXShader::CShaderProgram::GroupIfs(
                 this: v13,
                 a2: **(_DWORD **)(v15 + 16),
                 a3: 1u,
                 a4: &v85,
                 a5: v79,
                 a6: v80,
                 a7: &v89,
                 a8: a7,
                 a9: (int)v94,
                 a10: 0,
                 a11: 0,
                 a12: 0);
      if ( result < 0 )
        return result;
      if ( v94 != nullptr )
      {
        v88 = (struct D3DXShader::CArgument *)D3DXShader::CBaseProgram::AddArgument(
                                                this: v13,
                                                a2: *((_DWORD *)v13 + 42),
                                                a3: 0,
                                                a4: 0,
                                                a5: 0.0);
        if ( v88 == (struct D3DXShader::CArgument *)-1 )
          return -2147024882;
        v35 = D3DXShader::CInstruction::operator new(a1: 0x74u);
        v92 = v35 != nullptr
            ? (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v35)
            : nullptr;
        if ( v92 == nullptr )
          return -2147024882;
        if ( v90 == 286261248 )
          v36 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::Initialize(
                                              this: v92,
                                              a2: 0x74B00001u,
                                              a3: 0,
                                              a4: 1u,
                                              a5: 0);
        else
          v36 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::Initialize(
                                              this: v92,
                                              a2: 0x74A00001u,
                                              a3: 0,
                                              a4: 1u,
                                              a5: 0);
        v28 = v92;
        v94 = v36;
        if ( (int)v36 < 0 )
        {
LABEL_128:
          D3DXShader::CInstruction::`scalar deleting destructor'(this: v28, a2: 1);
          return (int)v94;
        }
        v29 = D3DXShader::CInstruction::Instance(this: v92, a2: (struct D3DXShader::CInstruction *)v15);
        if ( v29 < 0 )
        {
          v72 = v92;
          goto LABEL_130;
        }
        v37 = v92;
        **((_DWORD **)v92 + 4) = v88;
        result = D3DXShader::CBaseProgram::AddInstruction(this: v13, a2: v37);
        if ( result < 0 )
          return result;
      }
      v30 = v85;
    }
    v93 = v30;
LABEL_121:
    v11 = v93;
    if ( v93 >= a7 )
      return 0;
  }
  if ( v16 != (D3DXShader *)544210944 )
    goto LABEL_142;
  if ( a9 != 0 )
    goto LABEL_51;
  v38 = *(_DWORD **)(v15 + 8);
  v39 = *((_DWORD *)v13 + 5);
  v90 = *(_DWORD *)(v39 + 4 * *v38);
  v40 = *(_DWORD *)(v39 + 4 * v38[v91]);
  v41 = *(_DWORD *)(v90 + 20);
  if ( v41 != *(_DWORD *)(v40 + 20) )
  {
    v74 = "internal error: if block with non matching predicates found";
    goto LABEL_132;
  }
  if ( a4 == nullptr || a5 == nullptr || a6 == nullptr )
  {
    v75 = "internal error: unexpected endif found";
LABEL_126:
    D3DXShader::CProgram::Error(this: v13, a2: *(struct D3DXShader::CNode **)(v15 + 60), a3: 0x12E1u, format: v75);
    return -2147467259;
  }
  if ( v41 != (_DWORD)a2 )
  {
LABEL_142:
    *a3 = v93;
    return 0;
  }
  if ( a8 == nullptr )
    goto LABEL_51;
  v18 = *(_DWORD *)(v90 + 24) == HIDWORD(a2);
  v88 = (struct D3DXShader::CArgument *)1;
  v87 = 0;
  if ( !v18 )
    v87 = v91;
  if ( v91 != 0 )
  {
    v92 = *(D3DXShader::CInstruction **)(v15 + 16);
    v94 = (D3DXShader::CInstruction *)&v38[v87];
    for ( i = (D3DXShader::CArgument *)v91; i != nullptr; i = (D3DXShader::CArgument *)((char *)i - 1) )
    {
      v42 = *((_DWORD *)v13 + 5);
      v43 = *(_DWORD **)(v42 + 4 * *(_DWORD *)v92);
      v44 = *(_DWORD **)(v42 + 4 * *(_DWORD *)v94);
      if ( v43[3] != v44[3] || v43[4] != v44[4] || v43[2] != v44[2] || v43[1] != v44[1] || v43[15] != v44[15] )
        v88 = nullptr;
      v92 = (D3DXShader::CInstruction *)((char *)v92 + 4);
      v94 = (D3DXShader::CInstruction *)((char *)v94 + 4);
    }
  }
  if ( v91 + *a6 >= 0x80 )
  {
    D3DXShader::CProgram::Error(
      this: v13,
      a2: *(struct D3DXShader::CNode **)(v15 + 60),
      a3: 0x1194u,
      format: "Conditional block too complex");
    return -2147467259;
  }
  if ( v88 != nullptr )
  {
    if ( v91 != 0 )
    {
      v87 *= 4;
      do
      {
        v45 = *(_DWORD *)(v87 + *(_DWORD *)(v15 + 8));
        v46 = *a6;
        v87 += 4;
        a4[v14 + v46] = v45;
        v47 = *(_DWORD *)(*(_DWORD *)(v15 + 16) + 4 * v14);
        v48 = v14 + *a6;
        v12 = ++v14 < v91;
        a5[v48] = v47;
      }
      while ( v12 );
    }
LABEL_120:
    *a6 += v91;
    ++v93;
    v13 = v86;
    v14 = 0;
    goto LABEL_121;
  }
  v49 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v49 != nullptr )
    v94 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v49);
  else
    v94 = nullptr;
  if ( v94 == nullptr )
    return -2147024882;
  v50 = D3DXShader::CInstruction::Initialize(this: v94, a2: v91 & 0xFFFFF | 0x10000000, a3: v91, a4: v91, a5: 0);
  if ( v50 < 0
    || (v50 = D3DXShader::CInstruction::Instance(this: v94, a2: (struct D3DXShader::CInstruction *)v15)) < 0
    || (v50 = D3DXShader::CBaseProgram::AddInstruction(this: v13, a2: v94)) < 0 )
  {
    v73 = v50;
LABEL_137:
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v94, a2: 1);
    return v73;
  }
  v51 = *(char **)(v15 + 8);
  if ( *(_DWORD *)(v90 + 24) == HIDWORD(a2) )
  {
    v52 = v91;
    v53 = *((char **)v94 + 2);
    v54 = 4 * v91;
    v55 = (4 * v91) >> 2;
    qmemcpy(v53, v51, 4 * v55);
    v57 = &v51[4 * v55];
    v56 = &v53[4 * v55];
    v58 = v54;
  }
  else
  {
    v59 = *((char **)v94 + 2);
    v60 = &v51[4 * v91];
    v61 = 4 * v91;
    v62 = (4 * v91) >> 2;
    qmemcpy(v59, v60, 4 * v62);
    v57 = &v60[4 * v62];
    v56 = &v59[4 * v62];
    v58 = v61;
    v52 = v91;
  }
  v92 = nullptr;
  qmemcpy(v56, v57, v58 & 3);
  if ( v52 == 0 )
    goto LABEL_120;
  v90 = 4 * v52;
  while ( 1 )
  {
    v63 = D3DXShader::CBaseProgram::AddArgument(this: v86, a2: *((_DWORD *)v86 + 34), a3: 0, a4: 0, a5: 0.0);
    a4[(_DWORD)v92 + *a6] = v63;
    v64 = a4[(_DWORD)v92 + *a6];
    if ( v64 == -1 )
    {
      v73 = -2147024882;
      goto LABEL_137;
    }
    v65 = *((_DWORD *)v86 + 5);
    v66 = *(D3DXShader::CArgument **)(v65 + 4 * v64);
    v67 = 4 * (_DWORD)v92;
    v88 = *(struct D3DXShader::CArgument **)(v65 + 4 * *(_DWORD *)(4 * (_DWORD)v92 + *(_DWORD *)(v15 + 16)));
    i = v66;
    if ( D3DXShader::CArgument::Initialize(this: v66, a2: v88) < 0 )
      break;
    v68 = D3DXShader::CArgument::Instance(this: i, a2: v88);
    v69 = v94;
    if ( v68 < 0 )
      goto LABEL_139;
    *(_DWORD *)(v67 + *((_DWORD *)v94 + 4)) = a4[(_DWORD)v92 + *a6];
    a5[(_DWORD)v92 + *a6] = *(_DWORD *)(v67 + *(_DWORD *)(v15 + 16));
    v70 = *(_DWORD *)(v15 + 8);
    v71 = *(_DWORD *)(v70 + v67);
    if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v86 + 5) + 4 * v71) + 24) == HIDWORD(a2) )
      *(_DWORD *)(v67 + *((_DWORD *)v94 + 2)) = v71;
    else
      *(_DWORD *)(v67 + *((_DWORD *)v94 + 2)) = *(_DWORD *)(v70 + v90);
    v92 = (D3DXShader::CInstruction *)((char *)v92 + 1);
    v90 += 4;
    if ( (unsigned int)v92 >= v91 )
      goto LABEL_120;
  }
  v69 = v94;
LABEL_139:
  D3DXShader::CInstruction::`scalar deleting destructor'(this: v69, a2: 1);
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x1021E068
// Name: protected: class D3DXShader::CInstruction __near * D3DXShader::CShaderProgram::FindMatch(unsigned long,class D3DXShader::CInstruction __near *,unsigned int __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CInstruction *__thiscall D3DXShader::CShaderProgram::FindMatch(
        D3DXShader::CShaderProgram *this,
        unsigned int a2,
        unsigned int **a3,
        unsigned int *a4,
        unsigned int a5,
        unsigned int a6)
{
  struct D3DXShader::CInstruction *v6; // esi
  int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // eax
  struct D3DXShader::CInstruction *result; // eax
  int v11; // edi
  unsigned int *v12; // edx
  int v13; // eax
  unsigned int v14; // eax
  int v15; // edi
  unsigned int *v16; // edx
  _DWORD *v17; // edx
  unsigned int v19; // edx
  unsigned int v20; // edi
  unsigned int v21; // edi
  _DWORD *v22; // ecx
  int v23; // ebx
  _DWORD *v24; // ecx
  unsigned int v25; // ebx
  int v26; // esi
  int v27; // ecx
  int *v28; // edx
  int v29; // edi
  char *v30; // ebx
  _DWORD *v31; // edi
  int v32; // ecx
  unsigned int v33; // edx
  char *v34; // edi
  _DWORD *v35; // esi
  char v36; // cl
  _DWORD v37[4]; // [esp+4h] [ebp-20h] BYREF
  unsigned int i; // [esp+14h] [ebp-10h]
  unsigned int *v39; // [esp+18h] [ebp-Ch]
  unsigned int v40; // [esp+1Ch] [ebp-8h]
  char *v41; // [esp+20h] [ebp-4h]
  unsigned int v42; // [esp+2Ch] [ebp+8h]
  unsigned int v43; // [esp+38h] [ebp+14h]
  unsigned int *v44; // [esp+38h] [ebp+14h]
  unsigned int v45; // [esp+3Ch] [ebp+18h]
  unsigned int v46; // [esp+3Ch] [ebp+18h]
  unsigned int v47; // [esp+3Ch] [ebp+18h]

  v6 = (struct D3DXShader::CInstruction *)a3;
  v7 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a3[4]);
  v8 = *(_DWORD *)(v7 + 72);
  v9 = *(_DWORD *)(v7 + 84);
  i = v8;
  v40 = v9;
  if ( v9 == -1 )
    return nullptr;
  v41 = nullptr;
  if ( a3[1] != nullptr )
  {
    v11 = *((_DWORD *)this + 5);
    v12 = a3[2];
    while ( 1 )
    {
      v13 = *(_DWORD *)(v11 + 4 * *v12);
      if ( *((_DWORD *)this + 34) == *(_DWORD *)(v13 + 4) )
      {
        v14 = *(_DWORD *)(v13 + 80);
        if ( v14 > i && v14 < v40 )
          return nullptr;
      }
      ++v41;
      ++v12;
      if ( v41 >= (char *)a3[1] )
      {
        v9 = v40;
        break;
      }
    }
  }
  result = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v9);
  v15 = *(_DWORD *)result;
  if ( a2 != *(_DWORD *)result )
    return nullptr;
  v16 = a3[3];
  v41 = nullptr;
  if ( v16 != nullptr )
  {
    v39 = a3[4];
    do
    {
      v17 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *v39);
      if ( v17[21] != v40 || v17[22] != v40 )
        return nullptr;
      if ( !(a3[3] == (unsigned int *)1 ? v17[23] == a6 * (a2 & 0xFFFFF) : v17[23] == a6) )
        return nullptr;
      ++v41;
      ++v39;
    }
    while ( v41 < (char *)a3[3] );
  }
  v19 = v15 & 0xFFFFF;
  v42 = v15 & 0xFFFFF;
  if ( *((_DWORD *)result + 3) != (v15 & 0xFFFFF) )
    return nullptr;
  v20 = *((_DWORD *)result + 1);
  if ( v20 > a5 * v19 )
    return nullptr;
  v41 = nullptr;
  if ( v20 != 0 )
  {
    v21 = *((_DWORD *)this + 5);
    v43 = *((_DWORD *)this + 34);
    v22 = *((_DWORD **)result + 2);
    v45 = v21;
    do
    {
      v23 = *(_DWORD *)(v45 + 4 * *v22);
      if ( v43 == *(_DWORD *)(v23 + 4) && *(_DWORD *)(v23 + 72) > i )
        return nullptr;
      ++v41;
      v20 = *((_DWORD *)result + 1);
      ++v22;
    }
    while ( (unsigned int)v41 < v20 );
  }
  v41 = nullptr;
  if ( v20 != 0 )
  {
    v46 = *a3[4];
    v24 = *((_DWORD **)result + 2);
    do
    {
      if ( *v24 == v46 )
        break;
      ++v41;
      ++v24;
    }
    while ( (unsigned int)v41 < v20 );
  }
  if ( v41 == (char *)v20 )
    return nullptr;
  if ( (unsigned int)v41 >= v19 )
  {
    v25 = 0;
    if ( v19 != 0 )
    {
      v26 = 4 * v19;
      do
      {
        v27 = *((_DWORD *)result + 2);
        v28 = (int *)(v27 + 4 * v25);
        v29 = *v28;
        *v28 = *(_DWORD *)(v26 + v27);
        *(_DWORD *)(v26 + *((_DWORD *)result + 2)) = v29;
        ++v25;
        v26 += 4;
      }
      while ( v25 < v42 );
      v19 = v42;
      v6 = (struct D3DXShader::CInstruction *)a3;
    }
  }
  if ( *((_DWORD *)v6 + 3) > 1u )
  {
    v30 = *((char **)v6 + 2);
    v41 = &v30[4 * *((_DWORD *)v6 + 1)];
    if ( v30 < v41 )
    {
      while ( 1 )
      {
        if ( v19 != 0 )
        {
          v39 = *((unsigned int **)v6 + 4);
          v31 = v30;
          v32 = *((_DWORD *)result + 2) - (_DWORD)v30;
          for ( i = v19; i != 0; --i )
          {
            v47 = 0;
            v44 = v39;
            while ( *v44 != *(_DWORD *)((char *)v31 + v32) )
            {
              ++v47;
              v19 = v42;
              ++v44;
              if ( v47 >= v42 )
                goto LABEL_48;
            }
            v37[v47] = *v31;
            v19 = v42;
LABEL_48:
            ++v31;
          }
        }
        v33 = 4 * v19;
        qmemcpy(v30, v37, 4 * (v33 >> 2));
        v35 = &v37[v33 >> 2];
        v34 = &v30[4 * (v33 >> 2)];
        v36 = v33;
        v19 = v42;
        qmemcpy(v34, v35, v36 & 3);
        v30 += 4 * v42;
        if ( v30 >= v41 )
          break;
        v6 = (struct D3DXShader::CInstruction *)a3;
      }
    }
  }
  if ( a4 != nullptr )
    *a4 = v40;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021E2C3
// Name: protected: long D3DXShader::CShaderProgram::FindMatchUp(unsigned long,class D3DXShader::CInstruction __near *,class D3DXShader::CInstruction __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::FindMatchUp(
        D3DXShader::CShaderProgram *this,
        unsigned int a2,
        struct D3DXShader::CInstruction *a3,
        struct D3DXShader::CInstruction **a4,
        unsigned int a5)
{
  struct D3DXShader::CInstruction *v5; // ebx
  unsigned int v6; // esi
  unsigned int v7; // edx
  struct D3DXShader::CInstruction **v8; // edi
  int v9; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edx
  int v12; // ebx
  int v13; // ecx
  _DWORD *v14; // esi
  unsigned int v15; // eax
  int v16; // eax
  int v17; // edx
  unsigned int v18; // eax
  unsigned int v19; // esi
  _DWORD *v20; // edx
  unsigned int v21; // edx
  unsigned int v22; // eax
  int v23; // edx
  int v24; // eax
  unsigned int v26; // [esp+8h] [ebp-1Ch]
  unsigned int v27; // [esp+Ch] [ebp-18h]
  int v28; // [esp+10h] [ebp-14h]
  unsigned int i; // [esp+14h] [ebp-10h]
  unsigned int j; // [esp+14h] [ebp-10h]
  int v31; // [esp+18h] [ebp-Ch]
  unsigned int v32; // [esp+1Ch] [ebp-8h]
  D3DXShader::CShaderProgram *v33; // [esp+20h] [ebp-4h]

  v5 = a3;
  v6 = *(_DWORD *)a3 & 0xFFFFF;
  v33 = this;
  v32 = v6;
  if ( v6 == 0 )
    return 1;
  v7 = *((_DWORD *)a3 + 1) / v6;
  v26 = v7;
  if ( v7 == 0 )
    goto LABEL_46;
  v31 = 0;
  v8 = a4;
  v28 = *((_DWORD *)a3 + 1) / v6;
  while ( 1 )
  {
    v9 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v31 + *((_DWORD *)v5 + 2)));
    v10 = *(_DWORD *)(v9 + 84);
    v11 = *(_DWORD *)(v9 + 72);
    v27 = v10;
    if ( v11 == -1 )
    {
LABEL_43:
      *v8 = nullptr;
      goto LABEL_44;
    }
    v12 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v11);
    *v8 = (struct D3DXShader::CInstruction *)v12;
    if ( v6 != 0 )
    {
      v13 = v31;
      for ( i = v6; i != 0; --i )
      {
        v14 = *(_DWORD **)(*((_DWORD *)v33 + 5) + 4 * *(_DWORD *)(v13 + *((_DWORD *)a3 + 2)));
        if ( *((_DWORD *)v33 + 34) != v14[1] )
          *v8 = nullptr;
        if ( v14[15] != 0 )
          *v8 = nullptr;
        v15 = v14[20];
        if ( v15 > v11 && v15 < v27 )
          *v8 = nullptr;
        if ( v14[21] != v14[22] )
          *v8 = nullptr;
        v13 += 4;
      }
    }
    if ( *v8 != nullptr )
    {
      if ( a2 != *(_DWORD *)v12 )
        goto LABEL_43;
      if ( v32 != 0 )
      {
        v16 = v31;
        for ( j = v32; j != 0; --j )
        {
          if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v33 + 5) + 4 * *(_DWORD *)(v16 + *((_DWORD *)a3 + 2))) + 72) != v11 )
            *v8 = nullptr;
          v16 += 4;
        }
      }
      if ( *v8 != nullptr )
      {
        v17 = *(_DWORD *)v12 & 0xFFFFF;
        if ( *(_DWORD *)(v12 + 12) != v17 || *(_DWORD *)(v12 + 4) > a5 * v17 )
          goto LABEL_43;
        v18 = *((_DWORD *)a3 + 1);
        v19 = 0;
        if ( v18 != 0 )
        {
          v20 = *((_DWORD **)a3 + 2);
          do
          {
            if ( *v20 == **(_DWORD **)(v12 + 16) )
              break;
            ++v19;
            ++v20;
          }
          while ( v19 < v18 );
        }
        if ( v19 == v18 )
          goto LABEL_43;
        v21 = *(_DWORD *)(v12 + 12);
        if ( v21 > 1 )
        {
          if ( v21 != v32 || v19 + v32 > v18 )
            *v8 = nullptr;
          v22 = 0;
          if ( v32 != 0 )
          {
            v23 = 4 * v19;
            do
            {
              if ( *(_DWORD *)(*(_DWORD *)(v12 + 16) + 4 * v22) != *(_DWORD *)(v23 + *((_DWORD *)a3 + 2)) )
                *v8 = nullptr;
              ++v22;
              v23 += 4;
            }
            while ( v22 < v32 );
          }
        }
      }
    }
LABEL_44:
    v6 = v32;
    v31 += 4 * v32;
    ++v8;
    if ( --v28 == 0 )
      break;
    this = v33;
    v5 = a3;
  }
  v7 = v26;
LABEL_46:
  v24 = 0;
  if ( v7 == 0 )
    return 1;
  while ( a4[v24] == nullptr )
  {
    if ( ++v24 >= v7 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021E496
// Name: protected: long D3DXShader::CShaderProgram::BuildInstruction(unsigned int __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::BuildInstruction(
        D3DXShader::CShaderProgram *this,
        unsigned int *a2,
        unsigned int a3,
        unsigned int a4)
{
  unsigned __int8 *v5; // eax
  int v6; // edi
  unsigned int v7; // edx
  _DWORD *v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  int j; // [esp+Ch] [ebp-10h]
  unsigned int i; // [esp+10h] [ebp-Ch]
  unsigned int v14; // [esp+14h] [ebp-8h]
  D3DXShader::CInstruction *v15; // [esp+18h] [ebp-4h]

  v5 = D3DXShader::CInstruction::operator new(a1: 0x74u);
  if ( v5 != nullptr )
    v15 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v5);
  else
    v15 = nullptr;
  if ( v15 == nullptr )
    return -2147024882;
  v7 = a4;
  v14 = 0;
  if ( a4 != 0 )
  {
    v8 = *(_DWORD **)(*((_DWORD *)this + 64) + 16);
    do
    {
      if ( a2[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v8) + 16)] != -1 )
        ++v14;
      ++v8;
      --v7;
    }
    while ( v7 != 0 );
  }
  v6 = D3DXShader::CInstruction::Initialize(
         this: v15,
         a2: v14 | **((_DWORD **)this + 64) & 0xFFF00000,
         a3: a3 * v14,
         a4: v14,
         a5: 0);
  if ( v6 >= 0 )
  {
    v6 = D3DXShader::CInstruction::Instance(this: v15, a2: *((struct D3DXShader::CInstruction **)this + 64));
    if ( v6 >= 0 )
    {
      for ( i = 0; i < a3; ++i )
      {
        v9 = 0;
        for ( j = 0; v9 < a4; ++v9 )
        {
          v10 = *((_DWORD *)this + 64);
          if ( a2[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v10 + 16) + 4 * v9)) + 16)] != -1 )
          {
            *(_DWORD *)(*((_DWORD *)v15 + 2) + 4 * (j + v14 * i)) = *(_DWORD *)(*(_DWORD *)(v10 + 8) + 4 * (v9 + a4 * i));
            if ( i == 0 )
              *(_DWORD *)(*((_DWORD *)v15 + 4) + 4 * j) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 16) + 4 * v9);
            ++j;
          }
        }
      }
      v6 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v15);
      if ( v6 >= 0 )
      {
        v15 = nullptr;
        v6 = 0;
      }
    }
  }
  if ( v15 != nullptr )
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v15, a2: 1);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1021E5F9
// Name: protected: virtual unsigned long D3DXShader::CShaderProgram::CoIssue(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CShaderProgram::CoIssue(D3DXShader::CShaderProgram *this, unsigned int a2)
{
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1021E605
// Name: unsigned int D3DXShader::TypeSize(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXShader::TypeSize@<eax>(
        struct D3DXShader::CNode *a1@<edi>,
        D3DXShader *this,
        struct D3DXShader::CNode *a3)
{
  unsigned int v5; // edi
  struct D3DXShader::CNode *v6; // [esp-4h] [ebp-8h]
  struct D3DXShader::CNode *v7; // [esp+0h] [ebp-4h]

  while ( 1 )
  {
    if ( this == nullptr )
      return 0;
    if ( *((_DWORD *)this + 1) == 1 )
      break;
    switch ( *((_DWORD *)this + 1) )
    {
      case 6:
        this = *((D3DXShader **)this + 6);
        break;
      case 8:
        return *((_DWORD *)this + 5) * D3DXShader::TypeSize(this: *((D3DXShader **)this + 4), a2: v7);
      case 9:
        return *((_DWORD *)this + 6) * *((_DWORD *)this + 7);
      case 0xB:
        this = *((D3DXShader **)this + 8);
        break;
      default:
        return 0;
    }
  }
  v5 = D3DXShader::TypeSize(this: *((D3DXShader **)this + 3), a2: a1);
  return v5 + D3DXShader::TypeSize(this: *((D3DXShader **)this + 2), a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1021E668
// Name: long D3DXShader::EmitTypeInfo(class D3DXShader::CCommentBlock __near *,class D3DXShader::CNode __near *,unsigned int,unsigned long,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXShader::EmitTypeInfo@<eax>(
        struct D3DXShader::CNode *a1@<edi>,
        D3DXShader *this,
        struct D3DXShader::CCommentBlock *a3,
        struct D3DXShader::CNode *pMem,
        unsigned int a5,
        unsigned int *a6,
        unsigned int *a7)
{
  __int16 v7; // cx
  int v9; // eax
  int result; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  bool v14; // sf
  unsigned __int16 v15; // cx
  struct D3DXShader::CCommentBlock *v16; // eax
  unsigned int *v17; // ebx
  int v18; // eax
  int v19; // edi
  int v20; // edi
  int v21; // esi
  unsigned int *v22; // [esp-8h] [ebp-1Ch]
  _DWORD v23[2]; // [esp+4h] [ebp-10h] BYREF
  int v24; // [esp+Ch] [ebp-8h]
  unsigned int v25; // [esp+10h] [ebp-4h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF
  D3DXShader *v27; // [esp+20h] [ebp+Ch]
  struct D3DXShader::CNode *pMema; // [esp+24h] [ebp+10h]

  if ( a6 == nullptr )
    return 0;
  v7 = (__int16)pMem;
  while ( *((_DWORD *)a3 + 1) != 1 )
  {
    if ( *((_DWORD *)a3 + 1) != 8 )
    {
      if ( *((_DWORD *)a3 + 1) != 9 )
        return -2147467259;
      v23[0] = 0;
      v23[1] = 0;
      v24 = 0;
      v25 = 0;
      v11 = *((_DWORD *)a3 + 4);
      if ( v11 != 0 )
      {
        v12 = v11 - 1;
        if ( v12 != 0 )
        {
          v13 = v12 - 1;
          if ( v13 != 0 )
          {
            if ( v13 == 1 )
              LOWORD(v23[0]) = 4;
          }
          else
          {
            LOWORD(v23[0]) = ((*((_DWORD *)a3 + 8) & 0x400) == 0) | 2;
          }
        }
        else
        {
          LOWORD(v23[0]) = 1;
        }
      }
      else
      {
        LOWORD(v23[0]) = 0;
      }
      switch ( *((_DWORD *)a3 + 5) )
      {
        case 0:
          HIWORD(v23[0]) = 1;
          break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 0xD:
          HIWORD(v23[0]) = 2;
          break;
        case 9:
        case 0xA:
        case 0xB:
        case 0xC:
          HIWORD(v23[0]) = 3;
          break;
        case 0xE:
          HIWORD(v23[0]) = 4;
          break;
        case 0xF:
          HIWORD(v23[0]) = 5;
          break;
        case 0x10:
          HIWORD(v23[0]) = 6;
          break;
        case 0x11:
          HIWORD(v23[0]) = 7;
          break;
        case 0x12:
          HIWORD(v23[0]) = 8;
          break;
        case 0x13:
          HIWORD(v23[0]) = 9;
          break;
        case 0x14:
          if ( (a5 & 0x200000) != 0 )
            goto LABEL_28;
          if ( (a5 & 0x400000) != 0 )
            goto LABEL_30;
          HIWORD(v23[0]) = (a5 >> 22) & 2 | 0xC;
          break;
        case 0x15:
          HIWORD(v23[0]) = 11;
          break;
        case 0x16:
LABEL_28:
          HIWORD(v23[0]) = 12;
          break;
        case 0x17:
LABEL_30:
          HIWORD(v23[0]) = 13;
          break;
        case 0x18:
          HIWORD(v23[0]) = 14;
          break;
        case 0x19:
          HIWORD(v23[0]) = 15;
          break;
        case 0x1A:
          HIWORD(v23[0]) = 16;
          break;
        case 0x1B:
          HIWORD(v23[0]) = 17;
          break;
        case 0x1C:
          HIWORD(v23[0]) = 18;
          break;
        default:
          HIWORD(v23[0]) = 0;
          break;
      }
      LOWORD(v23[1]) = *((_WORD *)a3 + 12);
      HIWORD(v23[1]) = *((_WORD *)a3 + 14);
      LOWORD(v24) = v7;
      result = D3DXShader::CCommentBlock::Add(this, pMem: v23, nSize: 0x10u, a4: 2u, a5: a6);
      v14 = result < 0;
      goto LABEL_52;
    }
    v9 = *((_DWORD *)a3 + 5);
    a3 = *((struct D3DXShader::CCommentBlock **)a3 + 4);
    v7 *= (_WORD)v9;
  }
  v23[0] = 5;
  LOWORD(v23[1]) = 1;
  v25 = 0;
  HIWORD(v23[1]) = D3DXShader::TypeSize(a1: (struct D3DXShader::CNode *)&savedregs, this: a3, a3: a1);
  v24 = v15;
  v16 = a3;
  do
  {
    ++HIWORD(v24);
    v16 = *((struct D3DXShader::CCommentBlock **)v16 + 3);
  }
  while ( v16 != nullptr );
  v17 = (unsigned int *)MemAlloc_Alloc(nSize: 8 * HIWORD(v24));
  pMema = (struct D3DXShader::CNode *)v17;
  if ( v17 == nullptr )
    return -2147024882;
  do
  {
    v18 = *((_DWORD *)a3 + 2);
    v19 = *(_DWORD *)(v18 + 24);
    v27 = (D3DXShader *)D3DXShader::CCommentBlock::Add(
                          this,
                          pMem: *(const void **)(*(_DWORD *)(v18 + 20) + 24),
                          nSize: 0xFFFFFFFF,
                          a4: 7u,
                          a5: v17);
    if ( (int)v27 < 0 )
    {
      free(pMem: pMema);
      return (int)v27;
    }
    v20 = D3DXShader::EmitTypeInfo(
            this,
            a2: *(struct D3DXShader::CCommentBlock **)(v19 + 32),
            pMem: (struct D3DXShader::CNode *)1,
            a4: a5,
            a5: v17 + 1,
            a6: v22);
    if ( v20 < 0 )
    {
      free(pMem: pMema);
      return v20;
    }
    a3 = *((struct D3DXShader::CCommentBlock **)a3 + 3);
    v17 += 2;
  }
  while ( a3 != nullptr );
  v21 = D3DXShader::CCommentBlock::Add(this, pMem: pMema, nSize: 8 * HIWORD(v24), a4: 2u, a5: &v25);
  free(pMem: pMema);
  if ( v21 < 0 )
    return v21;
  result = D3DXShader::CCommentBlock::Add(this, pMem: v23, nSize: 0x10u, a4: 2u, a5: a6);
  v14 = result < 0;
LABEL_52:
  if ( !v14 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021E961
// Name: protected: long D3DXShader::CShaderProgram::Assure(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::Assure(D3DXShader::CShaderProgram *this, unsigned int a2)
{
  unsigned int v3; // ecx
  bool v4; // cc
  void *v5; // edi
  unsigned int v7; // [esp+8h] [ebp-4h]

  v3 = *((_DWORD *)this + 69);
  v7 = v3;
  if ( v3 == 0 )
    v7 = 1024;
  if ( a2 + *((_DWORD *)this + 68) > v7 )
  {
    do
    {
      v4 = *((_DWORD *)this + 68) + a2 <= 2 * v7;
      v7 *= 2;
    }
    while ( !v4 );
  }
  if ( v7 != v3 )
  {
    v5 = MemAlloc_Alloc(nSize: 4 * v7);
    if ( v5 == nullptr )
      return -2147024882;
    qmemcpy(v5, *((const void **)this + 67), 4 * *((_DWORD *)this + 68));
    free(pMem: *((void **)this + 67));
    *((_DWORD *)this + 67) = v5;
    *((_DWORD *)this + 69) = v7;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021EA09
// Name: protected: virtual long D3DXShader::CShaderProgram::DestRegister(class D3DXShader::CArgument __near *,unsigned long __near *,unsigned long __near *,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::DestRegister(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4,
        int *a5)
{
  int v6; // eax
  unsigned int v7; // eax
  bool v8; // cf
  unsigned int v9; // ecx
  int result; // eax
  int v11; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v12; // [esp+10h] [ebp-4h] BYREF

  v11 = 0;
  v12 = 0;
  if ( a5 != nullptr )
    *a5 = 0;
  v6 = *((_DWORD *)a2 + 1);
  if ( *((_DWORD *)this + 34) == v6 )
  {
    v7 = *((_DWORD *)a2 + 3);
    v8 = v7 < *((_DWORD *)this + 11);
    v11 = 0;
    v12 = v7;
    if ( !v8 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x1199u,
        format: "maximum temp register index exceeded");
      return -2005529767;
    }
    v9 = *((_DWORD *)this + 20);
    if ( v9 != 0 && v7 >= v9 )
    {
      v7 -= v9;
      v12 = v7;
      v11 = 3;
    }
  }
  else if ( *((_DWORD *)this + 35) == v6 )
  {
    v7 = *((_DWORD *)a2 + 3);
    v11 = 3;
    v12 = v7;
    if ( v7 != 0 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x119Cu,
        format: "maximum address register index exceeded");
      return -2005529767;
    }
  }
  else if ( *((_DWORD *)this + 33) == v6 )
  {
    if ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *, struct D3DXShader::CArgument *, unsigned int *, int *, int *))(*(_DWORD *)this + 132))(
           a1: this,
           a2,
           a3: &v12,
           a4: &v11,
           a5) < 0 )
      return -2147467259;
    LOWORD(v7) = v12;
  }
  else
  {
    if ( *((_DWORD *)this + 36) != v6 )
    {
      D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0, format: "internal error: unexpected output register type");
      return -2147467259;
    }
    v7 = *((_DWORD *)a2 + 3);
    v8 = v7 < *((_DWORD *)this + 13);
    v11 = 19;
    v12 = v7;
    if ( !v8 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x11C5u,
        format: "maximum predicate register index exceeded");
      return -2005529767;
    }
  }
  if ( a3 != nullptr )
    *a3 = v7 & 0x7FF | ((v11 & 0x18 | ((v11 | 0xFFFFFFF8) << 20)) << 8);
  result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, struct D3DXShader::CArgument *, unsigned int *))(*(_DWORD *)this + 124))(
             a1: this,
             a2,
             a3: a4);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021EB56
// Name: protected: virtual long D3DXShader::CShaderProgram::FindOutput(class D3DXShader::CArgument __near *,unsigned long __near &,unsigned long __near &,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::FindOutput(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4,
        int *a5)
{
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x1021EB5E
// Name: protected: virtual long D3DXShader::CShaderProgram::DestMask(unsigned int __near *,unsigned int,unsigned long __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::DestMask(
        D3DXShader::CShaderProgram *this,
        unsigned int *a2,
        unsigned int a3,
        unsigned int *a4,
        int a5)
{
  unsigned int *v5; // edx
  int v7; // eax
  unsigned int v8; // ecx
  unsigned int i; // edi
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // eax
  int v17; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]

  v5 = a2;
  v7 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a2) + 60);
  v8 = 0;
  v17 = 0;
  v18 = 0;
  if ( (v7 & 0x400) != 0 )
  {
    v18 = 0x1000000;
  }
  else if ( (v7 & 0x800) != 0 )
  {
    v18 = 0x2000000;
  }
  else if ( (v7 & 0x1000) != 0 )
  {
    v18 = 50331648;
  }
  else if ( (v7 & 0x2000) != 0 )
  {
    v18 = 251658240;
  }
  else if ( (v7 & 0x4000) != 0 )
  {
    v18 = 234881024;
  }
  else if ( (v7 & 0x8000) != 0 )
  {
    v18 = 218103808;
  }
  if ( (v7 & 0x200) != 0 )
    BYTE2(v18) |= 0x10u;
  if ( a5 != 0 )
  {
    v17 = 983040;
  }
  else
  {
    for ( i = 0; i < a3; ++i )
    {
      v10 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v5[i]) + 16);
      v8 = 0;
      v11 = 0;
      if ( v10 != 0 )
      {
        v12 = v10 - 1;
        if ( v12 != 0 )
        {
          v13 = v12 - 1;
          if ( v13 != 0 )
          {
            if ( v13 == 1 )
              v11 = 0x80000;
          }
          else
          {
            v11 = 0x40000;
          }
        }
        else
        {
          v11 = 0x20000;
        }
      }
      else
      {
        v11 = 0x10000;
      }
      if ( (v11 & v17) != 0 )
      {
        D3DXShader::CProgram::Error(
          this,
          a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
          a3: 0x12D5u,
          format: "internal error: overlapping output writes");
        v5 = a2;
        v8 = 0;
      }
      v17 |= v11;
    }
  }
  if ( *((char *)this + 110) < 0 )
  {
    if ( (v17 & 0x80000) != 0 )
    {
      if ( (v17 & 0x70000) != 0 )
        v17 = 983040;
    }
    else
    {
      v17 = 458752;
    }
  }
  if ( (*((_BYTE *)this + 204) & 1) != 0 && *((_DWORD *)this + 73) != 0 && a3 != 0 )
  {
    do
    {
      v14 = v5[v8];
      v15 = v8 + 6 * *((_DWORD *)this + 74);
      ++v8;
      *(_DWORD *)(*((_DWORD *)this + 73) + 4 * v15 - 16) = v14;
    }
    while ( v8 < a3 );
  }
  *a4 = v17 | v18;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021ECC0
// Name: protected: virtual long D3DXShader::CShaderProgram::FindInput(class D3DXShader::CArgument __near *,unsigned long __near &,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::FindInput(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  unsigned int v4; // eax

  *a4 = 1;
  v4 = *((_DWORD *)a2 + 3);
  *a3 = v4;
  if ( v4 < *((_DWORD *)this + 10) )
    return 0;
  D3DXShader::CProgram::Error(
    this,
    a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
    a3: 0x119Au,
    format: "maximum input register index exceeded");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x1021ED07
// Name: protected: virtual long D3DXShader::CShaderProgram::SrcRegister(class D3DXShader::CArgument __near *,unsigned long __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::SrcRegister(
        D3DXShader::CShaderProgram *this,
        int a2,
        unsigned int *a3,
        unsigned int *a4)
{
  int v4; // edi
  int v5; // eax
  bool v7; // zf
  int v8; // ecx
  unsigned int v9; // eax
  bool v10; // cf
  unsigned int v11; // ecx
  int v12; // ecx
  int result; // eax
  int v14; // ecx
  int v15; // ecx
  unsigned int v16; // eax
  unsigned int *v17; // ecx
  const char *v18; // [esp-4h] [ebp-18h]
  unsigned int v19; // [esp+Ch] [ebp-8h] BYREF
  int v20; // [esp+10h] [ebp-4h]

  v4 = a2;
  v5 = *(_DWORD *)(a2 + 4);
  v7 = *((_DWORD *)this + 34) == v5;
  v8 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v5);
  if ( v7 )
  {
    v9 = *(_DWORD *)(a2 + 12);
    a2 = 0;
    v10 = v9 < *((_DWORD *)this + 11);
    v19 = v9;
    if ( !v10 )
    {
      v18 = "maximum temp register index exceeded";
LABEL_4:
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x1199u,
        format: v18);
      return -2005529767;
    }
    v11 = *((_DWORD *)this + 20);
    if ( v11 != 0 && v9 >= v11 )
    {
      v9 -= v11;
      v19 = v9;
      a2 = 3;
    }
    goto LABEL_16;
  }
  v12 = *(_DWORD *)(v8 + 4);
  if ( (v12 & 0x10) != 0 && (v12 & 4) != 0 )
  {
    a2 = 15;
    v9 = 0;
LABEL_11:
    v19 = v9;
    goto LABEL_16;
  }
  if ( (v12 & 0x10) != 0 && (v12 & 0x200) == 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, unsigned int *, int *))(*(_DWORD *)this + 136))(
               a1: this,
               a2,
               a3: &v19,
               a4: &a2);
    if ( result < 0 )
      return result;
    LOWORD(v9) = v19;
    goto LABEL_16;
  }
  if ( (v12 & 0x200) != 0 && (v12 & 0x42080) == 0 )
  {
    v16 = *(_DWORD *)(a2 + 12);
    v10 = v16 < *((_DWORD *)this + 14);
    v19 = v16;
    if ( !v10 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x119Bu,
        format: "maximum constant register index exceeded - Try reducing number of constants referenced");
      return -2005529767;
    }
    if ( v16 >= 0x800 )
    {
      if ( v16 >= 0x1000 )
        a2 = 13 - (v16 < 0x1800);
      else
        a2 = 11;
    }
    else
    {
      a2 = 2;
    }
    v9 = v16 & 0x7FF;
    goto LABEL_11;
  }
  if ( (v12 & 0x200) != 0 )
  {
    if ( (v12 & 0x80u) != 0 )
      goto LABEL_34;
    if ( (v12 & 0x2000) != 0 )
    {
      v9 = *(_DWORD *)(a2 + 12);
      v10 = v9 < *((_DWORD *)this + 24);
      v19 = v9;
      a2 = 14;
      if ( !v10 )
      {
        D3DXShader::CProgram::Error(
          this,
          a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
          a3: 0x1194u,
          format: "maximum bool register index exceeded");
        return -2005529767;
      }
      goto LABEL_16;
    }
  }
  if ( (v12 & 0x80u) != 0 )
  {
LABEL_34:
    v9 = *(_DWORD *)(a2 + 12);
    v10 = v9 < *((_DWORD *)this + 19);
    a2 = 10;
    v19 = v9;
    if ( !v10 )
    {
      v18 = "maximum sampler register index exceeded";
      goto LABEL_4;
    }
    goto LABEL_16;
  }
  if ( (v12 & 0x40000) != 0 )
  {
    v9 = *(_DWORD *)(a2 + 12);
    v10 = v9 < *((_DWORD *)this + 16);
    a2 = 7;
    v19 = v9;
    if ( !v10 )
    {
      v18 = "maximum loop register index exceeded";
      goto LABEL_4;
    }
  }
  else
  {
    if ( *((_DWORD *)this + 36) != *(_DWORD *)(a2 + 4) )
    {
      D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0, format: "internal error: unexpected input register type");
      return -2147467259;
    }
    v9 = *(_DWORD *)(a2 + 12);
    v10 = v9 < *((_DWORD *)this + 13);
    a2 = 19;
    v19 = v9;
    if ( !v10 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x11C5u,
        format: "maximum predicate register index exceeded");
      return -2005529767;
    }
  }
LABEL_16:
  v14 = *(_DWORD *)(v4 + 60);
  v20 = 0;
  v15 = v14 & 0x1F0000;
  switch ( v15 )
  {
    case 1048576:
      v20 = 184549376;
      break;
    case 1572864:
      v20 = 201326592;
      break;
    case 524288:
      v20 = 0x1000000;
      break;
    case 131072:
      v20 = 0x2000000;
      break;
    case 655360:
      v20 = 50331648;
      break;
    case 393216:
      v20 = 0x4000000;
      break;
    case 917504:
      v20 = 83886080;
      break;
    case 65536:
      v20 = 100663296;
      break;
    case 262144:
      v20 = 117440512;
      break;
    case 786432:
      v20 = 0x8000000;
      break;
    default:
      break;
  }
  v17 = a3;
  if ( a3 != nullptr )
    *a3 = v20 | v9 & 0x7FF | ((a2 & 0x18 | ((a2 | 0xFFFFFFF8) << 20)) << 8);
  if ( a4 != nullptr )
    *a4 = *(_DWORD *)(v4 + 8);
  if ( *(_DWORD *)(v4 + 8) == -1 )
    return 0;
  if ( *((_DWORD *)this + 85) != 0 )
  {
    *((_BYTE *)v17 + 1) |= 0x20u;
    return 0;
  }
  D3DXShader::CProgram::Error(
    this,
    a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
    a3: 0x119Fu,
    format: "target does not support relative addressing");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x1021F000
// Name: protected: virtual long D3DXShader::CShaderProgram::FindObjectDims(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::FindObjectDims(D3DXShader::CShaderProgram *this)
{
  unsigned int v1; // esi
  int v2; // edi
  int v3; // eax
  int v4; // eax
  unsigned int v5; // edx
  int v6; // eax

  v1 = 0;
  v2 = 0;
  if ( *((_DWORD *)this + 3) == 0 )
    return 0;
  do
  {
    v3 = *((_DWORD *)this + 6);
    *((_DWORD *)this + 63) = v1;
    v4 = *(_DWORD *)(v3 + 4 * v1);
    *((_DWORD *)this + 64) = v4;
    v5 = *(_DWORD *)v4 & 0xFFF00000;
    if ( v5 != 0 )
    {
      v6 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v4 + 8));
      switch ( v5 )
      {
        case 0x60500000u:
        case 0x60700000u:
        case 0x60800000u:
        case 0x60900000u:
        case 0x60600000u:
        case 0x60000000u:
        case 0x60200000u:
        case 0x60300000u:
        case 0x60400000u:
        case 0x60100000u:
          if ( (*(_BYTE *)(v6 + 62) & 0xC0) != 0 )
            v2 = 1;
          *(_DWORD *)(v6 + 60) = 0x200000;
          break;
        case 0x60A00000u:
        case 0x60C00000u:
        case 0x60D00000u:
        case 0x60E00000u:
        case 0x60B00000u:
          if ( (*(_BYTE *)(v6 + 62) & 0xA0) != 0 )
            v2 = 1;
          *(_DWORD *)(v6 + 60) = 0x400000;
          break;
        case 0x60F00000u:
        case 0x61100000u:
        case 0x61200000u:
        case 0x61300000u:
        case 0x61000000u:
          if ( (*(_BYTE *)(v6 + 62) & 0x60) != 0 )
            v2 = 1;
          *(_DWORD *)(v6 + 60) = 0x800000;
          break;
        default:
          break;
      }
    }
    ++v1;
  }
  while ( v1 < *((_DWORD *)this + 3) );
  if ( v2 == 0 )
    return 0;
  D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x11BBu, format: "sampler mismatch: sampler used inconsistently");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x1021F161
// Name: protected: virtual long D3DXShader::CShaderProgram::SrcSwizzle(unsigned int __near *,unsigned int,unsigned long,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::SrcSwizzle(
        D3DXShader::CShaderProgram *this,
        unsigned int *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5)
{
  int v5; // ebx
  int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // edx
  int v11; // ecx
  int v12; // eax
  unsigned int i; // eax
  unsigned int j; // eax
  int v15; // edi
  int v16; // edx
  unsigned int v17; // edx
  unsigned int v18; // ecx
  _DWORD *v19; // eax
  int v20; // esi
  _DWORD v22[4]; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v23[4]; // [esp+1Ch] [ebp-14h] BYREF
  int v24; // [esp+2Ch] [ebp-4h]

  v5 = *((_DWORD *)this + 4);
  v6 = *((_DWORD *)this + 5);
  v7 = 4 * *a2;
  v24 = *(_DWORD *)(v6 + v7);
  v8 = 0;
  if ( *(char *)(*(_DWORD *)(v5 + 4 * *(_DWORD *)(v24 + 4)) + 4) >= 0 )
  {
    if ( (a4 & 0x10000) != 0 )
    {
      v23[0] = 0;
      v8 = 1;
    }
    if ( (a4 & 0x20000) != 0 )
      v23[v8++] = 1;
    if ( (a4 & 0x40000) != 0 )
      v23[v8++] = 2;
    if ( (a4 & 0x80000) != 0 )
      v23[v8++] = 3;
    v9 = a3;
    if ( a3 > v8 )
      v9 = v8;
    v10 = 0;
    if ( v9 == 0 )
      goto LABEL_21;
    v11 = *((_DWORD *)this + 5);
    v12 = *(_DWORD *)(*(_DWORD *)(v11 + v7) + 16);
    do
    {
      if ( v12 != *(_DWORD *)(*(_DWORD *)(v11 + 4 * a2[v10]) + 16) )
        break;
      ++v10;
    }
    while ( v10 < v9 );
    if ( v10 < v9 )
    {
      for ( i = 0; i < 4; ++i )
        v22[i] = i;
    }
    else
    {
LABEL_21:
      v22[0] = *(_DWORD *)(v24 + 16);
      v22[1] = v22[0];
      v22[2] = v22[0];
      v22[3] = v22[0];
    }
    for ( j = 0; j < v9; v22[v15] = v16 )
    {
      v15 = v23[j];
      v16 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * *(_DWORD *)((char *)&v23[j++] + (char *)a2 - (char *)v23)) + 16);
    }
    v17 = 0;
    v18 = 16;
    v19 = v22;
    do
    {
      v20 = *v19++ << v18;
      v17 |= v20;
      v18 += 2;
    }
    while ( v18 < 0x18 );
    *a5 = v17;
  }
  else
  {
    *a5 = 14942208;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021F277
// Name: protected: virtual long D3DXShader::CShaderProgram::PredRegister(class D3DXShader::CArgument __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::PredRegister(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CArgument *a2,
        unsigned int *a3)
{
  int v3; // edx
  unsigned int v4; // eax
  _DWORD *v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // edx

  v3 = *((_DWORD *)a2 + 5);
  v4 = 0;
  if ( v3 != -1 )
  {
    v5 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v3);
    if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v5[1]) + 4) & 8) != 0 )
    {
      v6 = v5[3];
      v7 = v5[4];
      v4 = v6 & 0x7FF | 0xB0001000;
      if ( v7 != 0 )
      {
        v8 = v7 - 1;
        if ( v8 != 0 )
        {
          v9 = v8 - 1;
          if ( v9 != 0 )
          {
            if ( v9 == 1 )
              v4 |= 0xFF0000u;
          }
          else
          {
            v4 |= 0xAA0000u;
          }
        }
        else
        {
          v4 |= 0x550000u;
        }
      }
      if ( *((_DWORD *)a2 + 6) == 0 )
        v4 |= 0xD000000u;
    }
  }
  if ( a3 != nullptr )
    *a3 = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021F2ED
// Name: protected: virtual long D3DXShader::CShaderProgram::TempRegister(unsigned int,unsigned int __near *,unsigned int,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::TempRegister(
        D3DXShader::CShaderProgram *this,
        unsigned int a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int *a5,
        unsigned int a6)
{
  unsigned int v6; // eax
  int v7; // edx
  int v9; // ecx
  char *v10; // edi
  unsigned int v11; // edx
  char *v12; // edi
  unsigned int v13; // ecx
  unsigned int v14; // edx
  _DWORD *v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  unsigned int *v18; // eax
  int v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // ecx
  _DWORD *v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // eax
  _DWORD *v25; // eax
  int v26; // ecx
  int v27; // esi
  _DWORD *pMem; // [esp+14h] [ebp-4h]
  unsigned int *v30; // [esp+2Ch] [ebp+14h]
  unsigned int *v31; // [esp+30h] [ebp+18h]

  pMem = nullptr;
  v6 = 0;
  v7 = 0;
  if ( a6 != 0 )
  {
    v9 = *((_DWORD *)this + 84);
    do
    {
      if ( v9 == a5[v6] )
        v7 = 1;
      ++v6;
    }
    while ( v6 < a6 );
  }
  if ( *((_DWORD *)this + 83) <= a2 || v7 != 0 )
  {
    *((_DWORD *)this + 79) = -1;
    *((_DWORD *)this + 80) = -1;
    *((_DWORD *)this + 81) = -1;
    *((_DWORD *)this + 82) = -1;
    v10 = (char *)MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 11));
    pMem = v10;
    if ( v10 == nullptr )
    {
LABEL_42:
      v27 = -2147024882;
      goto LABEL_41;
    }
    v11 = 4 * *((_DWORD *)this + 11);
    memset(v10, 0xFFu, 4 * (v11 >> 2));
    v12 = &v10[4 * (v11 >> 2)];
    v13 = v11 & 3;
    v14 = 0;
    memset(v12, -1, v13);
    if ( *((_DWORD *)this + 2) != 0 )
    {
      do
      {
        v15 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v14);
        if ( *((_DWORD *)this + 34) == v15[1] && v15[2] == -1 )
        {
          v16 = v15[3];
          if ( v16 < *((_DWORD *)this + 11) )
          {
            if ( v15[18] < a2 && v15[22] >= a2 )
              pMem[v16] = 0;
            v17 = v15[18];
            if ( v17 >= a2 )
            {
              v18 = &pMem[v15[3]];
              if ( v17 < *v18 )
                *v18 = v17;
            }
          }
        }
        ++v14;
      }
      while ( v14 < *((_DWORD *)this + 2) );
    }
    v19 = *((_DWORD *)this + 11);
    v20 = 0;
    *((_DWORD *)this + 84) = 0;
    *((_DWORD *)this + 83) = 0;
    if ( v19 != 0 )
    {
      do
      {
        v21 = 0;
        if ( a6 == 0 )
          goto LABEL_45;
        do
        {
          if ( v20 == a5[v21] )
            break;
          ++v21;
        }
        while ( v21 < a6 );
        if ( v21 >= a6 )
        {
LABEL_45:
          v22 = &pMem[v20];
          if ( *((_DWORD *)this + 83) < *v22 )
          {
            *((_DWORD *)this + 84) = v20;
            *((_DWORD *)this + 83) = *v22;
          }
        }
        ++v20;
      }
      while ( v20 < *((_DWORD *)this + 11) );
    }
    if ( *((_DWORD *)this + 83) <= a2 )
    {
      *((_DWORD *)this + 83) = -1;
      *((_DWORD *)this + 84) = v19;
    }
  }
  v30 = nullptr;
  v23 = a4 != 1 ? 0 : 3;
  if ( a4 != 0 )
  {
    v31 = (unsigned int *)((char *)this + 4 * v23 + 316);
    do
    {
      if ( *v31 != -1 )
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v31) + 80) = a2;
      v24 = D3DXShader::CBaseProgram::AddArgument(
              this,
              a2: *((_DWORD *)this + 34),
              a3: *((_DWORD *)this + 84),
              a4: v23,
              a5: 0.0);
      *v31 = v24;
      if ( v24 == -1 )
        goto LABEL_42;
      v25 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v24);
      v25[15] = 0;
      v25[12] = 0;
      v25[18] = a2;
      v25[20] = *((_DWORD *)this + 83);
      v25[21] = a2;
      v25[22] = a2;
      v25[23] = 1;
      v26 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * a2);
      if ( *(_DWORD *)(v26 + 12) != 0 )
      {
        v25[6] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v26 + 16)) + 24);
        v25[5] = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                       + 4 * **(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * a2) + 16))
                           + 20);
      }
      if ( a3 != nullptr )
        a3[(_DWORD)v30] = *v31;
      ++v31;
      ++v23;
      v30 = (unsigned int *)((char *)v30 + 1);
    }
    while ( (unsigned int)v30 < a4 );
  }
  v27 = 0;
LABEL_41:
  free(pMem);
  return v27;
}

//------------------------------------------------------------------------------
// Address: 0x1021F526
// Name: protected: long D3DXShader::CShaderProgram::ValidateInst(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ValidateInst(D3DXShader::CShaderProgram *this)
{
  int v2; // edi
  unsigned int v3; // edx
  unsigned int v4; // eax
  int v5; // ecx
  int v6; // ebx
  int result; // eax
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v2 = *((_DWORD *)this + 108);
  if ( v2 == 0 )
    return 0;
  v3 = *((_DWORD *)this + 71);
  v4 = *((_DWORD *)this + 68);
  if ( v3 >= v4 || *((_DWORD *)this + 53) != 0 )
    return 0;
  v5 = *((_DWORD *)this + 64);
  v8 = 0;
  v9 = 0;
  if ( v5 != 0 )
  {
    v6 = *(_DWORD *)(v5 + 60);
    if ( v6 != 0 && *(_DWORD *)(v6 + 4) == 13 )
    {
      v8 = *(_DWORD *)(v6 + 64);
      v9 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 68);
    }
  }
  result = (*(int (__stdcall **)(int, int, int, unsigned int, unsigned int))(*(_DWORD *)v2 + 16))(
             a1: v2,
             a2: v8,
             a3: v9,
             a4: *((_DWORD *)this + 67) + 4 * v3,
             a5: v4 - v3);
  *((_DWORD *)this + 71) = *((_DWORD *)this + 68);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021F5AF
// Name: protected: static long D3DXShader::CShaderProgram::ValidationError(char const __near *,unsigned int,unsigned long,unsigned int,char const __near *,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static int __stdcall D3DXShader::CShaderProgram::ValidationError(
        const char *a1,
        unsigned int a2,
        __int16 a3,
        unsigned int a4,
        const char *a5,
        void *a6)
{
  unsigned int v6; // eax
  int v7; // eax
  int v8; // ecx
  _BYTE v10[16]; // [esp+4h] [ebp-20h] BYREF
  const char *v11; // [esp+14h] [ebp-10h]
  unsigned int v12; // [esp+18h] [ebp-Ch]

  v6 = a2;
  if ( a2 == -1 )
  {
    v7 = *((_DWORD *)a6 + 64);
    if ( v7 == 0
      || (v8 = *(_DWORD *)(v7 + 60)) == 0
      || *(_DWORD *)(v8 + 4) != 13
      || (v6 = *(_DWORD *)(*(_DWORD *)(v7 + 60) + 68), a1 = *(const char **)(v8 + 64), v6 == -1) )
    {
      v6 = 0;
    }
  }
  v12 = v6;
  v11 = a1;
  if ( a3 == 2 || a3 == 6 )
  {
    D3DXShader::CTErrors::Error(
      this: *((D3DXShader::CTErrors **)a6 + 49),
      a2: (struct D3DXShader::D3DXTOKEN *)v10,
      a3: a4 + 5000,
      format: "%s",
      a5);
    *((_DWORD *)a6 + 53) = 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021F63A
// Name: protected: virtual unsigned int D3DXShader::CShaderProgram::CalcNumExtraSymbolTableEntries(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::CalcNumExtraSymbolTableEntries(D3DXShader::CShaderProgram *this)
{
  if ( *((_DWORD *)this + 86) != 0 )
    return *((_DWORD *)this + 116) + *((_DWORD *)this + 124) + *((_DWORD *)this + 125);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021F659
// Name: protected: virtual long D3DXShader::CShaderProgram::AddExtraSymbolTableEntries(class D3DXShader::CCommentBlock __near *,struct _D3DXSHADER_CONSTANTINFO __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::AddExtraSymbolTableEntries(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CCommentBlock *a2,
        struct _D3DXSHADER_CONSTANTINFO *a3,
        unsigned int a4)
{
  unsigned int v4; // edi
  bool v6; // zf
  int v8; // eax
  char *v9; // ebx
  int v10; // edi
  unsigned int v11; // edi
  unsigned int *v12; // esi
  const void ***v13; // ebx
  _WORD v14[6]; // [esp+8h] [ebp-44h] BYREF
  int v15; // [esp+14h] [ebp-38h]
  D3DXShader::CCommentBlock *v16; // [esp+18h] [ebp-34h]
  void *pMem; // [esp+1Ch] [ebp-30h]
  unsigned int v18; // [esp+20h] [ebp-2Ch]
  int v19; // [esp+24h] [ebp-28h]
  char string[32]; // [esp+28h] [ebp-24h] BYREF

  v4 = 0;
  v6 = *((_DWORD *)this + 86) == 0;
  v16 = a2;
  v18 = (unsigned int)a3;
  v19 = 0;
  pMem = nullptr;
  if ( v6 )
    return 0;
  v8 = *((_DWORD *)this + 125) + *((_DWORD *)this + 124) + *((_DWORD *)this + 116);
  if ( v8 != 0 )
  {
    v9 = (char *)MemAlloc_Alloc(nSize: 4 * v8);
    pMem = v9;
    if ( v9 != nullptr )
    {
      if ( *((_DWORD *)this + 11) != 0 )
      {
        while ( 1 )
        {
          sprintf(string, format: "r_$Int%d", v4);
          v19 = D3DXShader::CFragmentRegisterAllocator::AddElement(
                  this: (struct D3DXShader::CRegisterEntryNode **)this + 109,
                  a2: (D3DXShader *)string,
                  a3: v4,
                  a4: 1u);
          if ( v19 < 0 )
            break;
          if ( ++v4 >= *((_DWORD *)this + 11) )
          {
            v9 = (char *)pMem;
            goto LABEL_10;
          }
        }
      }
      else
      {
LABEL_10:
        D3DXShader::CFragmentRegisterAllocator::GetElements(
          this: (D3DXShader::CShaderProgram *)((char *)this + 436),
          a2: (struct D3DXShader::CRegisterEntryNode **)v9);
        v10 = *((_DWORD *)this + 125) + *((_DWORD *)this + 116);
        D3DXShader::CFragmentRegisterAllocator::GetElements(
          this: (D3DXShader::CShaderProgram *)((char *)this + 468),
          a2: (struct D3DXShader::CRegisterEntryNode **)&v9[4 * v10]);
        v11 = *((_DWORD *)this + 124) + v10;
        qsort(base: v9, num: v11, width: 4u, comp: (int (__cdecl *)(const void *, const void *))D3DXShader::compare);
        v14[0] = 1;
        v14[1] = 3;
        v14[2] = 1;
        v14[3] = 4;
        v14[4] = 1;
        v14[5] = 0;
        v15 = 0;
        v12 = (unsigned int *)(v18 + 20 * a4);
        v18 = 0;
        if ( v11 != 0 )
        {
          while ( 1 )
          {
            v13 = (const void ***)&v9[4 * v18];
            v19 = D3DXShader::CCommentBlock::Add(this: v16, pMem: **v13, nSize: 0xFFFFFFFF, a4: 7u, a5: v12);
            if ( v19 < 0 )
              break;
            v19 = D3DXShader::CCommentBlock::Add(this: v16, pMem: v14, nSize: 0x10u, a4: 6u, a5: v12 + 3);
            if ( v19 < 0 )
              break;
            if ( (*v13)[3] != nullptr )
            {
              *((_BYTE *)v12 + 10) |= 1u;
              v19 = D3DXShader::CCommentBlock::Add(this: v16, pMem: *v13 + 4, nSize: 0x10u, a4: 7u, a5: v12 + 4);
              if ( v19 < 0 )
                break;
            }
            ++v18;
            *((_WORD *)v12 + 2) = 2;
            *((_WORD *)v12 + 3) = *((_WORD *)*v13 + 2);
            *((_WORD *)v12 + 4) = 1;
            v12 += 5;
            if ( v18 >= v11 )
              goto LABEL_18;
            v9 = (char *)pMem;
          }
        }
        else
        {
LABEL_18:
          v19 = 0;
        }
      }
    }
    else
    {
      v19 = -2147024882;
    }
  }
  free(pMem);
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x1021F82F
// Name: protected: virtual long D3DXShader::CShaderProgram::AddUserOffsetInfo(class D3DXShader::CNodeVariable __near *,struct _D3DXSHADER_CONSTANTINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::AddUserOffsetInfo(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CNodeVariable *a2,
        struct _D3DXSHADER_CONSTANTINFO *a3)
{
  char *v3; // edi
  bool v4; // zf
  int v6; // ebx
  _DWORD *v7; // eax
  int v8; // ecx
  int v9; // eax
  char *v10; // esi
  int v11; // eax
  const char *v12; // ebx
  const char *v13; // edi
  const char *i; // esi
  unsigned int v15; // eax
  _BYTE v16[4]; // [esp+4h] [ebp-18h] BYREF
  int v17; // [esp+8h] [ebp-14h]
  D3DXShader::CProgram *v18; // [esp+10h] [ebp-Ch]
  char *v19; // [esp+14h] [ebp-8h]
  char *v20; // [esp+18h] [ebp-4h]

  v3 = nullptr;
  v20 = nullptr;
  v19 = nullptr;
  v4 = *((_DWORD *)this + 86) == 0;
  v18 = this;
  if ( v4 )
    return 0;
  v6 = *((_DWORD *)a2 + 12);
  if ( v6 != 0 )
  {
    do
    {
      v7 = *(_DWORD **)(v6 + 8);
      if ( v7[1] == 17 )
      {
        v8 = v7[4];
        if ( v8 != 0 )
          v8 = *(_DWORD *)(v8 + 24);
        v9 = v7[5];
        if ( v9 != 0 )
          v10 = *(char **)(v9 + 24);
        else
          v10 = nullptr;
        if ( v8 != 0 )
        {
          if ( v10 != nullptr && (int)D3DXGetTargetDescByName(a1: v8, a2: 0, a3: v16) >= 0 && tolower(c: *v10) == 99 )
          {
            v11 = *((_DWORD *)v18 + 50);
            if ( v11 == v17 )
            {
              v3 = v10;
            }
            else if ( ((v17 ^ v11) & 0xFFFF0000) == 0 && (_WORD)v17 == 0 )
            {
              v20 = v10;
            }
          }
        }
        else if ( v10 != nullptr && tolower(c: *v10) == 99 )
        {
          v19 = v10;
        }
      }
      v6 = *(_DWORD *)(v6 + 12);
    }
    while ( v6 != 0 );
    if ( v3 != nullptr )
      goto LABEL_31;
  }
  v3 = v20;
  if ( v20 != nullptr || (v3 = v19, v19 != nullptr) )
  {
LABEL_31:
    if ( tolower(c: *v3) == 99 )
    {
      v12 = v3 + 1;
      if ( isdigit(c: v3[1]) != 0 )
      {
        v13 = v3 + 2;
        for ( i = v13; isdigit(c: *i) != 0; ++i )
          ;
        if ( *i == 0 )
        {
          v15 = atoi(nptr: v12);
          if ( v15 > 0x1FFF )
          {
            D3DXShader::CProgram::Error(
              this: v18,
              a2: nullptr,
              a3: 0,
              format: "Constant variable '%s' bound to register greater than 8191 (%d requested)",
              v13,
              v15);
            return -2147467259;
          }
          *((_WORD *)a3 + 5) |= (unsigned __int16)(4 * v15) | 2;
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021F981
// Name: protected: struct D3DXShader::D3DX_SEMANTIC __near * D3DXShader::CShaderProgram::FindSemantic(struct D3DXShader::D3DX_SEMANTIC __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::D3DX_SEMANTIC *__thiscall D3DXShader::CShaderProgram::FindSemantic(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::D3DX_SEMANTIC *a2,
        unsigned int a3)
{
  struct D3DXShader::D3DX_SEMANTIC *result; // eax
  int v4; // ecx

  for ( result = a2; ; result = (struct D3DXShader::D3DX_SEMANTIC *)((char *)result + 36) )
  {
    v4 = *((_DWORD *)result + 4);
    if ( v4 == -1 || v4 == a3 )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021F99F
// Name: public: D3DXShader::CShaderProgram::CShaderProgram(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CShaderProgram *__thiscall D3DXShader::CShaderProgram::CShaderProgram(D3DXShader::CShaderProgram *this)
{
  D3DXShader::CProgram::CProgram(this);
  *(_DWORD *)this = &D3DXShader::CShaderProgram::`vftable';
  memset((char *)this + 436, 0, 0x1Cu);
  memset((char *)this + 468, 0, 0x1Cu);
  *((_DWORD *)this + 88) = -1;
  *((_DWORD *)this + 63) = 0;
  *((_DWORD *)this + 64) = 0;
  *((_DWORD *)this + 65) = 0;
  *((_DWORD *)this + 89) = -1;
  *((_DWORD *)this + 90) = -1;
  *((_DWORD *)this + 91) = -1;
  *((_DWORD *)this + 98) = -1;
  *((_DWORD *)this + 67) = 0;
  *((_DWORD *)this + 68) = 0;
  *((_DWORD *)this + 69) = 0;
  *((_DWORD *)this + 73) = 0;
  *((_DWORD *)this + 74) = 0;
  *((_DWORD *)this + 75) = 0;
  *((_DWORD *)this + 76) = 0;
  *((_DWORD *)this + 77) = 0;
  *((_DWORD *)this + 66) = 0;
  *((_DWORD *)this + 108) = 0;
  *((_DWORD *)this + 86) = 0;
  *((_DWORD *)this + 124) = 0;
  *((_DWORD *)this + 116) = 0;
  *((_DWORD *)this + 125) = 0;
  *((_DWORD *)this + 58) = -65536;
  *((_DWORD *)this + 59) = 16;
  *((_DWORD *)this + 57) = 0xFFFF;
  *((_DWORD *)this + 62) = 0;
  *((_DWORD *)this + 60) = 0;
  *((_DWORD *)this + 61) = 0;
  *((_DWORD *)this + 99) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1021FA85
// Name: public: virtual D3DXShader::CShaderProgram::~CShaderProgram(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CShaderProgram::~CShaderProgram(D3DXShader::CShaderProgram *this)
{
  int v2; // eax
  void *v3; // [esp-4h] [ebp-Ch]

  v3 = *((void **)this + 67);
  *(_DWORD *)this = &D3DXShader::CShaderProgram::`vftable';
  free(pMem: v3);
  free(pMem: *((void **)this + 73));
  v2 = *((_DWORD *)this + 108);
  if ( v2 != 0 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(a1: *((_DWORD *)this + 108));
    *((_DWORD *)this + 108) = 0;
  }
  D3DXShader::CFragmentRegisterAllocator::~CFragmentRegisterAllocator(this: (D3DXShader::CShaderProgram *)((char *)this + 468));
  D3DXShader::CFragmentRegisterAllocator::~CFragmentRegisterAllocator(this: (D3DXShader::CShaderProgram *)((char *)this + 436));
  D3DXShader::CProgram::~CProgram(this);
}

//------------------------------------------------------------------------------
// Address: 0x1021FADD
// Name: public: virtual long D3DXShader::CShaderProgram::IndexSemantic(class D3DXShader::CArgument __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::IndexSemantic(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CArgument *a2,
        int a3)
{
  struct D3DXShader::CNode *v4; // ecx
  int result; // eax
  int v6; // eax
  char *v7; // ebx
  struct D3DXShader::CRegisterEntryNode *Element; // eax
  int v9; // eax
  int v10; // eax
  const char *ArgumentType; // [esp-8h] [ebp-220h]
  int v12; // [esp+10h] [ebp-208h] BYREF
  char string[512]; // [esp+14h] [ebp-204h] BYREF

  v4 = *((struct D3DXShader::CNode **)a2 + 26);
  v12 = 0;
  if ( v4 == nullptr )
  {
    *((_BYTE *)a2 + 3) |= 0x40u;
    *((_DWORD *)a2 + 27) = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, _DWORD))(*(_DWORD *)this + 80))(
                             a1: this,
                             a2: 0,
                             a3: 0);
    return 0;
  }
  v6 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)a2 + 1));
  v7 = *((char **)v4 + 6);
  if ( *((_DWORD *)this + 86) != 0 )
  {
    if ( strlen(v7) > 2 && *(_WORD *)"r_" == *(_WORD *)v7 )
    {
      if ( *((_DWORD *)a2 + 28) > 4u )
      {
        D3DXShader::CProgram::Error(
          this,
          a2: v4,
          a3: 0x11BFu,
          format: "multi-register semantics are not allowed in fragments '%s'",
          v7);
        v12 = 1;
      }
      Element = D3DXShader::CFragmentRegisterAllocator::GetElement(
                  this: (D3DXShader::CShaderProgram *)((char *)this + 436),
                  lpString2: (D3DXShader *)v7);
      if ( Element != nullptr )
      {
        v9 = *((_DWORD *)Element + 1);
      }
      else
      {
        result = D3DXShader::CFragmentRegisterAllocator::AddElement(
                   this: (struct D3DXShader::CRegisterEntryNode **)this + 109,
                   a2: (D3DXShader *)v7,
                   a3: *((_DWORD *)this + 116),
                   a4: 1u);
        if ( result < 0 )
          return result;
        v9 = *((_DWORD *)this + 116);
        *((_DWORD *)this + 116) = v9 + 1;
      }
      *((_DWORD *)a2 + 27) = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int))(*(_DWORD *)this + 80))(
                               a1: this,
                               a2: 0xFFFF,
                               a3: v9);
      return v12 != 0 ? 0x80004005 : 0;
    }
    v6 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)a2 + 1));
  }
  if ( *((_DWORD *)a2 + 27) != -1 && (*((_BYTE *)a2 + 3) & 0x40) != 0 && a3 == 0 )
  {
    D3DXShader::CBaseProgram::CreateArgumentErrorString(this, a2, string, count: 0x200u);
    D3DXShader::CProgram::Error(
      this,
      a2: *((struct D3DXShader::CNode **)a2 + 26),
      a3: 0x1196u,
      format: "invalid %s",
      string);
LABEL_20:
    v12 = 1;
    return v12 != 0 ? 0x80004005 : 0;
  }
  v10 = *(_DWORD *)(v6 + 4);
  if ( (*((_BYTE *)this + 112) & 0x40) == 0 )
  {
    if ( (v10 & 0x10) != 0 && (v10 & 0x200) == 0 )
    {
      result = D3DXShader::CShaderProgram::IndexSemanticFromTable(
                 this,
                 a2,
                 a3: *((struct D3DXShader::D3DX_SEMANTIC **)this + 61),
                 a4: 1u,
                 a5: &v12);
      if ( result >= 0 )
      {
        if ( *((_DWORD *)this + 10) == 2
          && (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD))(*(_DWORD *)this + 84))(
               a1: this,
               a2: *((_DWORD *)a2 + 27)) == 11 )
        {
          *(_WORD *)a2 |= 0x114u;
          *((double *)a2 + 4) = 0.0;
          *((double *)a2 + 5) = 1.0;
        }
        return v12 != 0 ? 0x80004005 : 0;
      }
      return result;
    }
    if ( (v10 & 0x20) == 0 )
      return v12 != 0 ? 0x80004005 : 0;
    result = D3DXShader::CShaderProgram::IndexSemanticFromTable(
               this,
               a2,
               a3: *((struct D3DXShader::D3DX_SEMANTIC **)this + 62),
               a4: 1u,
               a5: &v12);
    goto LABEL_30;
  }
  if ( (v10 & 0x10) == 0 || (v10 & 0x200) != 0 )
  {
    if ( (v10 & 0x20) == 0 )
      return v12 != 0 ? 0x80004005 : 0;
    result = D3DXShader::CShaderProgram::IndexSemanticFromTable(
               this,
               a2,
               a3: *((struct D3DXShader::D3DX_SEMANTIC **)this + 61),
               a4: 2u,
               a5: &v12);
LABEL_30:
    if ( result >= 0 )
      return v12 != 0 ? 0x80004005 : 0;
    return result;
  }
  result = D3DXShader::CShaderProgram::IndexSemanticFromTable(
             this,
             a2,
             a3: *((struct D3DXShader::D3DX_SEMANTIC **)this + 60),
             a4: 2u,
             a5: &v12);
  if ( result >= 0 )
  {
    if ( *((_DWORD *)a2 + 27) != 10 || *((_DWORD *)a2 + 4) != 0 )
      return v12 != 0 ? 0x80004005 : 0;
    ArgumentType = D3DXShader::CBaseProgram::GetArgumentType(this, a2);
    D3DXShader::CProgram::Error(
      this,
      a2: *((struct D3DXShader::CNode **)a2 + 26),
      a3: 0x1196u,
      format: "Invalid %s semantics - POSITIONT0",
      ArgumentType);
    goto LABEL_20;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021FD49
// Name: protected: long D3DXShader::CShaderProgram::ConstrainPorts(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ConstrainPorts(D3DXShader::CShaderProgram *this)
{
  int result; // eax
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int i; // edi
  unsigned int v7; // eax
  unsigned int v8; // eax
  int *v9; // ebx
  int v10; // eax
  bool v11; // zf
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  int v17; // edi
  int v18; // eax
  int v19; // edi
  int v20; // ecx
  unsigned int v21; // edx
  _DWORD *v22; // eax
  int v23; // ecx
  int v24; // edi
  unsigned int v25; // edx
  _DWORD *v26; // eax
  unsigned int v27; // edi
  bool v28; // cc
  unsigned int v29; // eax
  unsigned int v30; // edi
  unsigned int v31; // eax
  int v32; // ecx
  D3DXShader::CArgument *v33; // edi
  int v34; // eax
  unsigned int v35; // eax
  D3DXShader::CInstruction *v36; // edi
  int v37; // eax
  int v38; // ecx
  unsigned int m; // eax
  int v40; // edi
  int v41; // ecx
  int v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // ecx
  int v46; // ebx
  _DWORD *v47; // eax
  int v48; // eax
  unsigned int *v49; // ecx
  int v50; // eax
  D3DXShader::CArgument *v51; // ebx
  _DWORD *v52; // eax
  unsigned int v53; // [esp+Ch] [ebp-7Ch]
  _DWORD v54[8]; // [esp+24h] [ebp-64h] BYREF
  unsigned int v55; // [esp+44h] [ebp-44h]
  int *v56; // [esp+48h] [ebp-40h]
  _DWORD *v57; // [esp+4Ch] [ebp-3Ch]
  int v58; // [esp+50h] [ebp-38h]
  struct D3DXShader::CArgument *v59; // [esp+54h] [ebp-34h]
  int v60; // [esp+58h] [ebp-30h]
  int v61; // [esp+5Ch] [ebp-2Ch]
  unsigned int v62; // [esp+60h] [ebp-28h]
  int v63; // [esp+64h] [ebp-24h]
  int v64; // [esp+68h] [ebp-20h]
  unsigned int j; // [esp+6Ch] [ebp-1Ch]
  unsigned int v66; // [esp+70h] [ebp-18h] BYREF
  unsigned int v67; // [esp+74h] [ebp-14h]
  unsigned int v68; // [esp+78h] [ebp-10h]
  unsigned int v69; // [esp+7Ch] [ebp-Ch]
  int v70; // [esp+80h] [ebp-8h]
  unsigned int k; // [esp+84h] [ebp-4h]

  result = D3DXShader::CShaderProgram::Reset(this);
  if ( result >= 0 )
  {
    v3 = *((_DWORD *)this + 2);
    v69 = 0;
    if ( v3 != 0 )
    {
      v4 = *((_DWORD *)this + 34);
      v5 = *((_DWORD *)this + 5);
      for ( i = v3; i != 0; --i )
      {
        if ( v4 == *(_DWORD *)(*(_DWORD *)v5 + 4) )
        {
          v7 = *(_DWORD *)(*(_DWORD *)v5 + 12);
          if ( v7 >= v69 )
            v69 = v7 + 1;
        }
        v5 += 4;
      }
    }
    v8 = 0;
    v55 = *((_DWORD *)this + 3);
    for ( j = 0; j < v55; ++j )
    {
      v9 = *(int **)(*((_DWORD *)this + 6) + 4 * v8);
      v10 = *v9;
      v11 = (*v9 & 0xFFF00000) == 0;
      v56 = v9;
      if ( !v11 )
      {
        v70 = v10 & 0xFFFFF;
        v12 = *((_DWORD *)this + 5);
        v62 = v9[1] / (v10 & 0xFFFFFu);
        v13 = *(_DWORD *)(v12 + 4 * *(_DWORD *)v9[4]);
        v14 = *(_DWORD *)(v13 + 20);
        v15 = *(_DWORD *)(v13 + 24);
        v64 = v14;
        v63 = v15;
        while ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int *, unsigned int *))(*(_DWORD *)this + 32))(
                  a1: this,
                  a2: v9,
                  a3: &v66) != 0
             && (*v9 & 0xFFF00000) != 0x74100000 )
        {
          v16 = v66;
          v11 = (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                      + 4
                                      * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                              + 4 * *(_DWORD *)(v9[2] + 4 * v70 * v66))
                                                  + 4))
                          + 4)
               & 2) == 0;
          v60 = *(_DWORD *)(*((_DWORD *)this + 4)
                          + 4
                          * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v9[2] + 4 * v70 * v66)) + 4));
          if ( !v11 )
          {
            D3DXShader::CProgram::Error(
              this,
              a2: (struct D3DXShader::CNode *)v9[15],
              a3: 0,
              format: "internal error: result violated port constraints");
            return -2147467259;
          }
          v67 = 0;
          k = 0;
          if ( v62 != 0 )
          {
            v68 = 0;
            do
            {
              v17 = *(_DWORD *)(*((_DWORD *)this + 4)
                              + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v68 + v9[2])) + 4));
              if ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int *, unsigned int))(*(_DWORD *)this + 156))(
                     a1: this,
                     a2: v9,
                     a3: k) != 1 )
              {
                v18 = *(_DWORD *)(v17 + 4);
                if ( (v18 & 0x40) != 0 && (((unsigned __int16)v18 ^ *(_WORD *)(v60 + 4)) & 0x12BF) == 0 )
                {
                  v19 = v70;
                  if ( v70 != 0 )
                  {
                    v20 = *((_DWORD *)this + 5);
                    v21 = v68;
                    do
                    {
                      if ( v67 < *(_DWORD *)(*(_DWORD *)(v20 + 4 * *(_DWORD *)(v21 + v9[2])) + 92) )
                      {
                        v67 = *(_DWORD *)(*(_DWORD *)(v20 + 4 * *(_DWORD *)(v21 + v9[2])) + 92);
                        v66 = k;
                      }
                      v21 += 4;
                      --v19;
                    }
                    while ( v19 != 0 );
                  }
                }
              }
              ++k;
              v68 += 4 * v70;
            }
            while ( k < v62 );
            v16 = v66;
          }
          v22 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v9[2] + 4 * v70 * v16));
          v23 = v22[1];
          v24 = v22[3];
          v60 = v22[2];
          v11 = (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v23) + 4) & 0x40) == 0;
          v58 = v23;
          v61 = v24;
          if ( v11 )
          {
            D3DXShader::CProgram::Error(
              this,
              a2: (struct D3DXShader::CNode *)v9[15],
              a3: 0,
              format: "internal error: non-vectorized pool violated port constraints");
            return -2147467259;
          }
          memset(v54, 255, 16);
          v67 = 0;
          v25 = 0;
          if ( *((_DWORD *)this + 2) != 0 )
          {
            v68 = *((_DWORD *)this + 5);
            do
            {
              v26 = *(_DWORD **)v68;
              if ( *(_DWORD *)(*(_DWORD *)v68 + 4) == v23 && v26[3] == v61 && v26[2] == v60 && v26[14] == -1 )
              {
                v27 = v26[22];
                if ( v27 >= j )
                {
                  v28 = v67 <= v27;
                  v54[v26[4]] = v25;
                  if ( v28 )
                    v67 = v27 + 1;
                }
              }
              v68 += 4;
              ++v25;
            }
            while ( v25 < *((_DWORD *)this + 2) );
          }
          v29 = 0;
          v68 = 0;
          for ( k = 0; k < 4; ++k )
          {
            v30 = k;
            v59 = (struct D3DXShader::CArgument *)v54[k];
            if ( v59 != (struct D3DXShader::CArgument *)-1 )
            {
              v31 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: v69, a4: k, a5: 0.0);
              v54[v30 + 4] = v31;
              if ( v31 == -1 )
                return -2147024882;
              v32 = *((_DWORD *)this + 5);
              v33 = *(D3DXShader::CArgument **)(v32 + 4 * v31);
              result = D3DXShader::CArgument::Instance(
                         this: v33,
                         a2: *(struct D3DXShader::CArgument **)(v32 + 4 * (_DWORD)v59));
              if ( result < 0 )
                return result;
              v34 = v64;
              *((_DWORD *)v33 + 26) = 0;
              *((_DWORD *)v33 + 27) = -1;
              *((_DWORD *)v33 + 28) = 0;
              ++v68;
              *((_DWORD *)v33 + 5) = v34;
              *((_DWORD *)v33 + 6) = v63;
              v29 = v68;
            }
          }
          v35 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v29 & 0xFFFFF | 0x10000000, a3: v29, a4: v29);
          if ( v35 == -1 )
            return -2147024882;
          v36 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v35);
          result = D3DXShader::CInstruction::Instance(this: v36, a2: (struct D3DXShader::CInstruction *)v9);
          if ( result < 0 )
            return result;
          v37 = 0;
          for ( k = 0; k < 0x10; k += 4 )
          {
            v38 = *(_DWORD *)((char *)v54 + k);
            if ( v38 != -1 )
            {
              *(_DWORD *)(v37 + *((_DWORD *)v36 + 2)) = v38;
              *(_DWORD *)(v37 + *((_DWORD *)v36 + 4)) = *(_DWORD *)((char *)&v54[4] + k);
              v37 += 4;
            }
          }
          ++v69;
          for ( m = j; ; m = k + 1 )
          {
            k = m;
            if ( m >= v67 )
              break;
            v40 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * m);
            if ( (*(_WORD *)(v40 + 2) & 0xFFF0) != 0 )
            {
              v41 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v40 + 16));
              v42 = *(_DWORD *)(v41 + 20);
              v43 = *(_DWORD *)(v41 + 24);
              while ( v42 != -1 && (v42 != v64 || v43 != v63) )
              {
                v44 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v42);
                v43 = *(_DWORD *)(v44 + 24);
                v42 = *(_DWORD *)(v44 + 20);
              }
              if ( v42 == v64
                && v43 == v63
                && (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, _DWORD))(*(_DWORD *)this + 32))(
                     a1: this,
                     a2: v40,
                     a3: 0) != 0 )
              {
                v68 = 0;
                if ( *(_DWORD *)(v40 + 4) != 0 )
                {
                  do
                  {
                    v45 = *((_DWORD *)this + 5);
                    v46 = 4 * v68;
                    v59 = (struct D3DXShader::CArgument *)(4 * v68 + *(_DWORD *)(v40 + 8));
                    v47 = *(_DWORD **)(v45 + 4 * *(_DWORD *)v59);
                    v11 = v47[1] == v58;
                    v57 = v47;
                    if ( v11 && v47[3] == v61 && v47[2] == v60 )
                    {
                      v11 = v47[14] == -1;
                      v48 = v54[v47[4] + 4];
                      if ( v11 )
                      {
                        *(_DWORD *)v59 = v48;
                      }
                      else
                      {
                        v49 = *(unsigned int **)(v45 + 4 * v48);
                        v53 = v49[4];
                        v59 = (struct D3DXShader::CArgument *)v49;
                        *(_DWORD *)(v46 + *(_DWORD *)(v40 + 8)) = D3DXShader::CBaseProgram::AddArgument(
                                                                    this,
                                                                    a2: *((_DWORD *)this + 34),
                                                                    a3: v49[3],
                                                                    a4: v53,
                                                                    a5: 0.0);
                        v50 = *(_DWORD *)(v40 + 8);
                        if ( *(_DWORD *)(v46 + v50) == -1 )
                          return -2147024882;
                        v51 = *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v46 + v50));
                        result = D3DXShader::CArgument::Instance(this: v51, a2: v59);
                        if ( result < 0 )
                          return result;
                        v52 = v57;
                        *((_DWORD *)v51 + 14) = v54[v57[4] + 4];
                        *((_DWORD *)v51 + 15) = v52[15];
                      }
                    }
                    ++v68;
                  }
                  while ( v68 < *(_DWORD *)(v40 + 4) );
                  v9 = v56;
                }
              }
            }
          }
        }
        result = D3DXShader::CBaseProgram::CopyInstruction(this, a2: (struct D3DXShader::CInstruction *)v9);
        if ( result < 0 )
          return result;
        *v9 = 0;
      }
      v8 = j + 1;
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102201E3
// Name: protected: long D3DXShader::CShaderProgram::PortConstraints(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::PortConstraints(D3DXShader::CShaderProgram *this)
{
  int result; // eax
  unsigned int v3; // edi
  struct D3DXShader::CInstruction *v4; // esi
  int v5; // eax
  bool v6; // zf
  int v7; // eax
  int v8; // esi
  int v9; // eax
  struct D3DXShader::CInstruction *v10; // edx
  int v11; // esi
  unsigned int v12; // eax
  _DWORD *v13; // edi
  unsigned int v14; // edx
  bool i; // cf
  int v16; // eax
  int v17; // ecx
  void **v18; // edx
  unsigned int v19; // eax
  char *v20; // esi
  _DWORD *v21; // edi
  _DWORD *v22; // edi
  char *v23; // esi
  char v24; // cl
  unsigned int v25; // ecx
  int v26; // edx
  _DWORD v27[12]; // [esp+4h] [ebp-60h] BYREF
  int v28; // [esp+34h] [ebp-30h]
  unsigned int v29; // [esp+38h] [ebp-2Ch]
  unsigned int v30; // [esp+3Ch] [ebp-28h]
  int v31; // [esp+40h] [ebp-24h] BYREF
  void **v32; // [esp+44h] [ebp-20h]
  unsigned int v33; // [esp+48h] [ebp-1Ch]
  char *v34; // [esp+4Ch] [ebp-18h]
  int v35; // [esp+50h] [ebp-14h]
  unsigned int v36; // [esp+54h] [ebp-10h]
  int v37; // [esp+58h] [ebp-Ch]
  unsigned int v38; // [esp+5Ch] [ebp-8h]
  struct D3DXShader::CInstruction *v39; // [esp+60h] [ebp-4h]

  result = D3DXShader::CShaderProgram::Reset(this);
  if ( result >= 0 )
  {
    v38 = 0;
    v30 = *((_DWORD *)this + 3);
    v3 = v30;
    if ( v30 != 0 )
    {
      while ( 1 )
      {
        v4 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v38);
        v5 = *(_DWORD *)v4;
        v6 = (*(_DWORD *)v4 & 0xFFF00000) == 0;
        v39 = v4;
        if ( !v6 )
          break;
LABEL_24:
        if ( ++v38 >= v3 )
          goto LABEL_25;
      }
      v37 = 0;
      v35 = v5 & 0xFFFFF;
      v7 = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, struct D3DXShader::CInstruction *, int *))(*(_DWORD *)this + 32))(
             a1: this,
             a2: v4,
             a3: &v31);
      while ( v7 != 0 && (*(_DWORD *)v4 & 0xFFF00000) != 0x74100000 )
      {
        if ( v38 >= *((_DWORD *)this + 83) )
          memset(&v27[4], 255, 32);
        v8 = *((_DWORD *)v4 + 2);
        v33 = v35 != 1 ? 0 : 3;
        v9 = 4 * v33;
        v34 = (char *)(v8 + 4 * v35 * v31);
        v36 = 4 * v33;
        if ( memcmp(v34, &v27[v33 + 4], 4 * v35) != 0
          || (v10 = v39, *((_DWORD *)v39 + 3) != 0)
          && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v39 + 4)) + 20) != -1 )
        {
          v11 = v35;
          v12 = D3DXShader::CBaseProgram::AddInstruction(
                  this,
                  a2: v35 & 0xFFFFF | 0x10000000,
                  a3: 0xFFFFFFFF,
                  a4: 0xFFFFFFFF);
          if ( v12 == -1 )
            return -2147024882;
          v32 = *(void ***)(*((_DWORD *)this + 6) + 4 * v12);
          result = D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)v32, a2: v39);
          if ( result < 0 )
            return result;
          v13 = &v27[v36 / 4 + 8];
          result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int, _DWORD *, int, _DWORD *, int))(*(_DWORD *)this + 128))(
                     a1: this,
                     a2: v38,
                     a3: &v27[v36 / 4 + 8],
                     a4: v11,
                     a5: v27,
                     a6: v37);
          if ( result < 0 )
            return result;
          v28 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v13);
          v14 = v33;
          v29 = v33 + v11;
          for ( i = v33 < v33 + v11; ; i = v33 + 1 < v29 )
          {
            v33 = v14;
            if ( !i )
              break;
            v16 = *((_DWORD *)this + 5);
            v17 = *(_DWORD *)(v16 + 4 * v27[v14 + 8]);
            if ( *((_DWORD *)v39 + 3) != 0 )
            {
              *(_DWORD *)(v17 + 20) = *(_DWORD *)(*(_DWORD *)(v16 + 4 * **((_DWORD **)v39 + 4)) + 20);
              *(_DWORD *)(v17 + 24) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)v39 + 4)) + 24);
            }
            v14 = v33 + 1;
          }
          v18 = v32;
          v27[v37] = *(_DWORD *)(v28 + 12);
          v19 = 4 * v11;
          qmemcpy(v18[4], v13, 4 * v11);
          qmemcpy(v32[2], v34, 4 * v11);
          ++v37;
          v10 = v39;
          v20 = v34;
          v21 = &v27[v36 / 4 + 4];
          qmemcpy(&v27[v36 / 4 + 4], v34, 4 * (v19 >> 2));
          v23 = &v20[4 * (v19 >> 2)];
          v22 = &v21[v19 >> 2];
          v24 = v19;
          v9 = v36;
          qmemcpy(v22, v23, v24 & 3);
        }
        qmemcpy(v34, (char *)&v27[8] + v9, 4 * v35);
        v7 = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, struct D3DXShader::CInstruction *, int *))(*(_DWORD *)this + 32))(
               a1: this,
               a2: v10,
               a3: &v31);
        v4 = v39;
        v3 = v30;
      }
      if ( D3DXShader::CBaseProgram::CopyInstruction(this, a2: v4) != -1 )
      {
        D3DXShader::CInstruction::`scalar deleting destructor'(this: v4, a2: 1);
        *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v38) = 0;
        goto LABEL_24;
      }
      return -2147024882;
    }
    else
    {
LABEL_25:
      v25 = v3;
      if ( v3 < *((_DWORD *)this + 3) )
      {
        v26 = 0;
        do
        {
          *(_DWORD *)(v26 + *((_DWORD *)this + 6)) = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v25++);
          v26 += 4;
        }
        while ( v25 < *((_DWORD *)this + 3) );
      }
      *((_DWORD *)this + 3) -= v3;
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022047D
// Name: protected: long D3DXShader::CShaderProgram::MatchSourceModifier(unsigned int,unsigned int,unsigned int __near *,unsigned int,class D3DXShader::CInstruction __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchSourceModifier(
        D3DXShader::CShaderProgram *this,
        unsigned int a2,
        unsigned int a3,
        char *a4,
        unsigned int a5,
        struct D3DXShader::CInstruction *a6,
        int a7)
{
  struct D3DXShader::CInstruction *v7; // ebx
  char *v9; // edi
  int v10; // edx
  int *v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  char *v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // edx
  unsigned int v20; // ecx
  bool v21; // zf
  _DWORD *v22; // eax
  _DWORD *v23; // edi
  _DWORD *v24; // edx
  int v25; // ebx
  int v26; // edi
  int v27; // ebx
  unsigned int v28; // ecx
  unsigned int v29; // edi
  char *v30; // eax
  int v31; // ebx
  int v32; // edx
  int v33; // ebx
  _DWORD *v34; // ecx
  unsigned int v35; // ecx
  int *v36; // eax
  unsigned int v37; // ecx
  int v38; // eax
  unsigned int v39; // edx
  unsigned int v40; // eax
  _DWORD *k; // edx
  unsigned int v42; // edx
  unsigned int v43; // eax
  unsigned int j; // edx
  _DWORD *v45; // ecx
  int v46; // edi
  int v47; // eax
  int v49; // eax
  unsigned int v50; // edx
  unsigned int *v51; // ecx
  struct D3DXShader::CArgument *v52; // eax
  unsigned int v53; // edi
  unsigned int v54; // edx
  _DWORD v55[20]; // [esp+Ch] [ebp-A4h]
  _DWORD v56[4]; // [esp+5Ch] [ebp-54h] BYREF
  _DWORD v57[4]; // [esp+6Ch] [ebp-44h] BYREF
  _DWORD v58[4]; // [esp+7Ch] [ebp-34h] BYREF
  int v59; // [esp+8Ch] [ebp-24h]
  int v60; // [esp+90h] [ebp-20h]
  unsigned int v61; // [esp+94h] [ebp-1Ch]
  int v62; // [esp+98h] [ebp-18h]
  int v63; // [esp+9Ch] [ebp-14h]
  int i; // [esp+A0h] [ebp-10h]
  int v65; // [esp+A4h] [ebp-Ch]
  _DWORD *v66; // [esp+A8h] [ebp-8h]
  unsigned int v67; // [esp+ACh] [ebp-4h]
  unsigned int v68; // [esp+B8h] [ebp+8h]
  unsigned int *v69; // [esp+B8h] [ebp+8h]
  unsigned int v70; // [esp+B8h] [ebp+8h]
  unsigned int v71; // [esp+B8h] [ebp+8h]
  unsigned int v72; // [esp+BCh] [ebp+Ch]
  unsigned int v73; // [esp+BCh] [ebp+Ch]
  unsigned int v74; // [esp+BCh] [ebp+Ch]
  struct D3DXShader::CInstruction *v75; // [esp+C8h] [ebp+18h]
  struct D3DXShader::CInstruction *v76; // [esp+C8h] [ebp+18h]
  unsigned int v77; // [esp+CCh] [ebp+1Ch]

  v7 = a6;
  if ( a6 == nullptr )
  {
    v7 = *((struct D3DXShader::CInstruction **)this + 64);
    a6 = v7;
  }
  v9 = *((char **)v7 + 4);
  v10 = *((_DWORD *)this + 5);
  if ( *((_DWORD *)this + 34) != *(_DWORD *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)v9) + 4) )
    return 1;
  v11 = *((int **)this + 64);
  v12 = *v11;
  v13 = v11[3];
  v65 = 0;
  v63 = v12;
  if ( (v12 & 0xFFFFF) != v13 )
    return 1;
  v67 = 0;
  if ( v13 != 0 )
  {
    v14 = (int)(*((_DWORD *)this + 27) << 14) >> 31;
    v15 = (char *)(a4 - v9);
    v66 = v9;
    for ( i = a4 - v9; ; v15 = (char *)i )
    {
      v16 = *(_DWORD *)(v10 + 4 * *(_DWORD *)((char *)v66 + (_DWORD)v15));
      v60 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v16 + 4));
      if ( v14 != 0 && (*(_BYTE *)(v16 + 61) & 2) != 0 && a2 == 0x80000 )
        v65 = 1;
      v17 = *(_DWORD *)(v16 + 60);
      if ( (v17 & 0x1F0000) != 0 && (v17 & ~a3 & 0x1F0000) != 0 )
      {
        if ( a2 != 0x80000 )
          return 1;
        v65 = 1;
      }
      v10 = *((_DWORD *)this + 5);
      if ( (*(_BYTE *)(*(_DWORD *)(v10 + 4 * *v66) + 61) & 0xFE) != 0 )
        break;
      if ( (*((_BYTE *)this + 108) & 0x10) != 0 && (*(_BYTE *)(v60 + 5) & 2) != 0 )
      {
        if ( (_UNKNOWN *)(v63 & 0xFFF00000) != &loc_10100000 )
          return 1;
        v65 = 1;
      }
      ++v67;
      v18 = *((_DWORD *)this + 64);
      ++v66;
      if ( v67 >= *(_DWORD *)(v18 + 12) )
        goto LABEL_22;
    }
    return 1;
  }
LABEL_22:
  v68 = 0;
  if ( *((_DWORD *)v7 + 3) != 0 )
  {
    v72 = ~a5;
    v63 = a4 - (char *)v58;
    do
    {
      v19 = *((_DWORD *)this + 5);
      v20 = v68;
      v21 = v65 == 0;
      v22 = *(_DWORD **)(v19 + 4 * *(_DWORD *)(4 * v68 + *((_DWORD *)v7 + 4)));
      v23 = &v58[v68];
      v24 = *(_DWORD **)(v19 + 4 * *(_DWORD *)((char *)v23 + v63));
      *v23 = v22[2];
      v25 = v22[18];
      v56[v20] = v22[3];
      v57[v20] = v22[4];
      v55[v20 + 4] = v22[5];
      v55[v20 + 16] = v22[6];
      v26 = v22[15];
      v55[v20 + 8] = v25;
      v27 = v22[26];
      v55[v20 + 12] = v26;
      v55[v20] = v27;
      if ( v21 )
      {
        v22[1] = v24[1];
        v22[2] = v24[2];
        v22[3] = v24[3];
        v22[4] = v24[4];
        v22[5] = v24[5];
        v22[6] = v24[6];
        v22[18] = v24[18];
        v22[26] = v24[26];
        v28 = v26 | v72 & v24[15] | a5 ^ v24[15];
      }
      else
      {
        v28 = v26 & v72 | a5 ^ v26;
      }
      ++v68;
      v7 = a6;
      v22[15] = v28;
    }
    while ( v68 < *((_DWORD *)a6 + 3) );
  }
  v73 = 0;
  v63 = *((_DWORD *)v7 + 3);
  v29 = v63;
  if ( v63 != 0 )
  {
    v69 = *((unsigned int **)v7 + 4);
    while ( D3DXShader::CShaderProgram::ValidModifier(this, a2: *v69) != 1 )
    {
      ++v73;
      ++v69;
      if ( v73 >= v29 )
        goto LABEL_32;
    }
    goto LABEL_81;
  }
LABEL_32:
  v67 = -1;
  v74 = 0;
  v70 = -1;
  if ( v29 != 0 )
  {
    v30 = a4;
    v31 = *((_DWORD *)v7 + 4);
    v32 = *((_DWORD *)this + 5);
    v59 = (char *)v58 - a4;
    v61 = (char *)v56 - a4;
    v33 = v31 - (_DWORD)a4;
    v62 = (char *)v57 - a4;
    v60 = v33;
    i = v63;
    while ( 1 )
    {
      v34 = *(_DWORD **)(v32 + 4 * *(_DWORD *)v30);
      v66 = *(_DWORD **)(v32 + 4 * *(_DWORD *)&v30[v33]);
      if ( v66[21] < v67 )
        v67 = v66[21];
      if ( v66[22] > v74 )
        v74 = v66[22];
      if ( *((_DWORD *)this + 34) == v34[1]
        && *(_DWORD *)&v30[v59] == v34[2]
        && *(_DWORD *)&v30[v61] == v34[3]
        && *(_DWORD *)&v30[v62] == v34[4] )
      {
        v34 = v66;
      }
      v35 = v34[20];
      if ( v35 < v70 )
        v70 = v35;
      v30 += 4;
      if ( --i == 0 )
        break;
      v33 = v60;
    }
    v7 = a6;
  }
  if ( a7 == 0 && v70 < v74 && (*((_DWORD *)this + 27) & 0x10000000) == 0 )
  {
LABEL_81:
    for ( j = 0; j < *((_DWORD *)v7 + 3); v45[26] = v47 )
    {
      v45 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(4 * j + *((_DWORD *)v7 + 4)));
      v45[1] = *((_DWORD *)this + 34);
      v45[2] = v58[j];
      v45[3] = v56[j];
      v45[4] = v57[j];
      v45[5] = v55[j + 4];
      v45[6] = v55[j + 16];
      v45[15] = v55[j + 12];
      v46 = v55[j + 8];
      v47 = v55[j++];
      v45[18] = v46;
    }
    return 1;
  }
  if ( v65 != 0 )
  {
    **((_DWORD **)this + 64) = **((_DWORD **)this + 64) & 0xFFFFF | 0x10000000;
  }
  else
  {
    v66 = (_DWORD *)v67;
    if ( v67 <= v74 )
    {
      v67 = *((_DWORD *)this + 6) + 4 * v67;
      do
      {
        v36 = *(int **)v67;
        v65 = **(_DWORD **)v67;
        if ( v65 != 0 )
        {
          v37 = v36[2];
          v38 = v36[1];
          i = 0;
          v39 = v37 + 4 * v38;
          v40 = v65 & 0xFFFFF;
          v61 = v39;
          if ( v37 < v39 )
          {
            do
            {
              v71 = 0;
              v75 = nullptr;
              if ( v40 != 0 )
              {
                do
                {
                  v77 = 0;
                  if ( *((_DWORD *)v7 + 3) != 0 )
                  {
                    for ( k = *((_DWORD **)v7 + 4); *k != *(_DWORD *)(v37 + 4 * (_DWORD)v75); k = (_DWORD *)v62 )
                    {
                      ++v77;
                      v62 = (int)(k + 1);
                      if ( v77 >= *((_DWORD *)v7 + 3) )
                        goto LABEL_64;
                    }
                    ++v71;
                  }
LABEL_64:
                  v75 = (struct D3DXShader::CInstruction *)((char *)v75 + 1);
                }
                while ( (unsigned int)v75 < v40 );
                if ( v71 != 0 )
                {
                  if ( v71 != v40 )
                    goto LABEL_81;
                  v42 = v65 & 0xFFF00000;
                  if ( (v65 & 0xFFF00000) == 0x70500000 || v42 == 1885339648 || v42 == 1886388224 )
                    goto LABEL_81;
                  i = 1;
                }
              }
              v37 += 4 * v40;
            }
            while ( v37 < v61 );
            if ( i != 0 )
            {
              if ( (v65 & 0xF0000000) == 0x60000000
                || (v43 = v65 & 0xFFF00000, (v65 & 0xFFF00000) == 0x10D00000)
                || v43 == 283115520
                || v43 == 285212672 )
              {
                if ( *((char *)this + 110) >= 0 )
                  goto LABEL_81;
              }
            }
          }
        }
        v66 = (_DWORD *)((char *)v66 + 1);
        v67 += 4;
      }
      while ( (unsigned int)v66 <= v74 );
    }
    if ( *((_DWORD *)this + 87) != 0 )
    {
      *((_DWORD *)this + 87) = 2;
      goto LABEL_81;
    }
    v76 = nullptr;
    if ( *((_DWORD *)v7 + 3) != 0 )
    {
      while ( 1 )
      {
        v49 = *((_DWORD *)this + 5);
        v50 = *(_DWORD *)&a4[4 * (_DWORD)v76];
        v51 = *(unsigned int **)(v49 + 4 * *(_DWORD *)(4 * (_DWORD)v76 + *((_DWORD *)v7 + 4)));
        v52 = *(struct D3DXShader::CArgument **)(v49 + 4 * v50);
        v53 = *((_DWORD *)v52 + 14);
        if ( v53 == -1 )
          v51[14] = v50;
        else
          v51[14] = v53;
        v54 = *(_DWORD *)v52;
        *v51 = *(_DWORD *)v52;
        if ( a5 != 0x80000 )
          goto LABEL_91;
        if ( (v54 & 4) != 0 )
          break;
LABEL_93:
        D3DXShader::CArgument::Instance(this: (D3DXShader::CArgument *)v51, a2: v52);
        v76 = (struct D3DXShader::CInstruction *)((char *)v76 + 1);
        if ( (unsigned int)v76 >= *((_DWORD *)v7 + 3) )
          goto LABEL_94;
      }
      *v51 = v54 & 0xFFFFFFF3 | 8;
LABEL_91:
      if ( a5 == 0x100000 )
        *v51 |= 4u;
      goto LABEL_93;
    }
LABEL_94:
    **((_DWORD **)this + 64) = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102209D4
// Name: protected: long D3DXShader::CShaderProgram::MatchNEG(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchNEG(D3DXShader::CShaderProgram *this, int a2)
{
  int v3; // ecx
  int result; // eax

  v3 = *((_DWORD *)this + 64);
  *((_DWORD *)this + 87) = 0;
  result = D3DXShader::CShaderProgram::MatchSourceModifier(
             this,
             a2: 0x80000u,
             a3: 0xE0000u,
             a4: *(char **)(v3 + 8),
             a5: 0x80000u,
             a6: nullptr,
             a7: a2);
  if ( result >= 0 )
    return D3DXShader::CShaderProgram::CompressOrigin(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10220A14
// Name: protected: long D3DXShader::CShaderProgram::MatchABSModifier(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchABSModifier(D3DXShader::CShaderProgram *this)
{
  int v2; // eax
  int v3; // edx
  _DWORD *v4; // ecx
  int result; // eax
  unsigned int v6; // [esp+Ch] [ebp-4h]

  v2 = *((_DWORD *)this + 64);
  v6 = 0;
  if ( *(_DWORD *)(v2 + 4) != 0 )
  {
    v3 = *((_DWORD *)this + 5);
    v4 = *(_DWORD **)(v2 + 8);
    while ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(*(_DWORD *)(v3 + 4 * *v4) + 4)) + 5) & 2) == 0 )
    {
      ++v6;
      ++v4;
      if ( v6 >= *(_DWORD *)(*((_DWORD *)this + 64) + 4) )
        goto LABEL_5;
    }
    return 1;
  }
  else
  {
LABEL_5:
    *((_DWORD *)this + 87) = 0;
    result = D3DXShader::CShaderProgram::MatchSourceModifier(
               this,
               a2: 0x100000u,
               a3: 0,
               a4: *(char **)(v2 + 8),
               a5: 0x100000u,
               a6: nullptr,
               a7: 0);
    if ( result >= 0 )
      return D3DXShader::CShaderProgram::CompressOrigin(this);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10220A8E
// Name: protected: long D3DXShader::CShaderProgram::MatchComplexMad(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchComplexMad(D3DXShader::CShaderProgram *this, int a2)
{
  int *v3; // edx
  int v4; // esi
  unsigned int v5; // eax
  char *v6; // eax
  unsigned int v7; // ecx
  int v8; // edi
  unsigned int v9; // ecx
  unsigned int *v10; // esi
  int v11; // eax
  int v12; // edi
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // ecx
  int v17; // esi
  struct D3DXShader::CInstruction *v18; // ecx
  unsigned int v19; // edi
  int v20; // edx
  _DWORD *v21; // eax
  struct D3DXShader::CInstruction *v22; // eax
  struct D3DXShader::CInstruction *v23; // ecx
  int v24; // edi
  int v25; // esi
  _DWORD *v26; // edx
  unsigned int k; // eax
  unsigned int v28; // esi
  unsigned int v29; // edi
  struct D3DXShader::CInstruction *v30; // ecx
  struct D3DXShader::CInstruction *v31; // eax
  _DWORD *v32; // ecx
  unsigned int v33; // eax
  unsigned int ii; // eax
  unsigned int v35; // ecx
  unsigned int v36; // edx
  int v37; // eax
  unsigned int v38; // edx
  char *v39; // eax
  unsigned int v40; // ecx
  unsigned int v41; // edi
  unsigned int v42; // ecx
  unsigned int *v43; // esi
  int v44; // eax
  int v45; // edi
  unsigned int v46; // edx
  unsigned int *v47; // ecx
  unsigned int v48; // eax
  int v49; // esi
  unsigned int v50; // ecx
  struct D3DXShader::CInstruction *v51; // ecx
  unsigned int v52; // edi
  int v53; // edx
  _DWORD *v54; // eax
  struct D3DXShader::CInstruction *v55; // eax
  struct D3DXShader::CInstruction *v56; // ecx
  struct D3DXShader::CInstruction *v57; // edi
  int v58; // esi
  _DWORD *v59; // edx
  unsigned int kk; // eax
  unsigned int v61; // esi
  unsigned int v62; // edi
  struct D3DXShader::CInstruction *v63; // ecx
  struct D3DXShader::CInstruction *v64; // eax
  _DWORD *v65; // ecx
  unsigned int v66; // eax
  unsigned int mm; // eax
  unsigned int v68; // ecx
  unsigned int v69; // edi
  int v70; // eax
  unsigned int nn; // ecx
  int v72; // eax
  int v73; // esi
  unsigned int v74; // ecx
  int v75; // eax
  unsigned int v76; // ecx
  int v77; // eax
  unsigned int v78; // ecx
  D3DXShader::CInstruction *v79; // esi
  int v81; // eax
  unsigned int v82; // eax
  unsigned int v83; // eax
  unsigned int v84; // eax
  unsigned int v85; // ecx
  int v86; // edx
  int v87; // edi
  int v88; // edx
  unsigned int v89; // ecx
  _DWORD *v90; // esi
  int *v91; // esi
  unsigned int v92; // eax
  unsigned __int8 *v93; // eax
  unsigned int v94; // edi
  unsigned int v95; // eax
  unsigned int v96; // eax
  char *v97; // eax
  unsigned int v98; // eax
  unsigned int *v99; // ecx
  int v100; // eax
  unsigned int v101; // edx
  _DWORD **v102; // edi
  unsigned int v103; // ecx
  int v104; // eax
  unsigned int v105; // edx
  unsigned int v106; // [esp+0h] [ebp-2D8h]
  unsigned int v107; // [esp+0h] [ebp-2D8h]
  unsigned int v108[80]; // [esp+14h] [ebp-2C4h] BYREF
  unsigned int v109[8]; // [esp+154h] [ebp-184h] BYREF
  _DWORD v110[32]; // [esp+174h] [ebp-164h] BYREF
  struct D3DXShader::CInstruction *v111[16]; // [esp+1F4h] [ebp-E4h] BYREF
  struct D3DXShader::CInstruction *v112[16]; // [esp+234h] [ebp-A4h] BYREF
  unsigned int v113[4]; // [esp+274h] [ebp-64h] BYREF
  D3DXShader::CInstruction *v114; // [esp+284h] [ebp-54h]
  unsigned int v115[4]; // [esp+288h] [ebp-50h] BYREF
  int j; // [esp+298h] [ebp-40h]
  int i1; // [esp+29Ch] [ebp-3Ch]
  struct D3DXShader::CInstruction *v118; // [esp+2A0h] [ebp-38h]
  int v119; // [esp+2A4h] [ebp-34h]
  unsigned int v120; // [esp+2A8h] [ebp-30h]
  unsigned int v121; // [esp+2ACh] [ebp-2Ch] BYREF
  struct D3DXShader::CInstruction *n; // [esp+2B0h] [ebp-28h]
  unsigned int v123; // [esp+2B4h] [ebp-24h]
  unsigned int i; // [esp+2B8h] [ebp-20h]
  unsigned int v125; // [esp+2BCh] [ebp-1Ch] BYREF
  unsigned int *m; // [esp+2C0h] [ebp-18h]
  unsigned int v127; // [esp+2C4h] [ebp-14h]
  unsigned int v128; // [esp+2C8h] [ebp-10h]
  _DWORD **v129; // [esp+2CCh] [ebp-Ch]
  unsigned int jj; // [esp+2D0h] [ebp-8h]
  int matched; // [esp+2D4h] [ebp-4h]

  v3 = *((int **)this + 64);
  v4 = *v3;
  v123 = *v3 & 0xFFFFF;
  v5 = v123;
  v114 = nullptr;
  v121 = 0;
  v115[0] = 0;
  v115[1] = 1;
  v115[2] = 2;
  v115[3] = 3;
  i1 = 0;
  jj = (unsigned int)v3;
  v120 = v123;
  if ( (v4 & 0xFFF00000) == 0x20400000 )
  {
    v119 = 0;
LABEL_3:
    v128 = 0;
LABEL_4:
    memset(v108, 255, sizeof(v108));
    v6 = nullptr;
    v125 = 0;
    matched = 0;
    v127 = 0;
    m = nullptr;
    while ( 1 )
    {
      if ( v128 != 0 )
        v7 = 1 - v127;
      else
        v7 = v127;
      v8 = *(_DWORD *)(jj + 8);
      v9 = dword_102BD06C[v7];
      v10 = (unsigned int *)(v8 + 4 * (_DWORD)v6);
      if ( v9 >= 0x10 )
      {
        v13 = 0;
        v14 = &v108[4 * v9 - 24];
        do
        {
          v15 = v115[v13];
          if ( v15 >= v123 )
            *v14 = -1;
          else
            *v14 = *(_DWORD *)(v8 + 4 * ((_DWORD)m + v15));
          ++v13;
          ++v14;
        }
        while ( v13 < 4 );
      }
      else
      {
        v11 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v10) + 72);
        if ( v11 == -1
          || (v12 = 32 * v9,
              v106 = dword_102BD078[8 * v9],
              n = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v11),
              D3DXShader::CShaderProgram::ComputeSwizzle(
                this,
                a2: n,
                a3: v10,
                a4: v123,
                a5: v115,
                a6: v113,
                a7: v106,
                a8: 0) != 0) )
        {
          matched = 1;
LABEL_21:
          v127 = 0;
          v129 = nullptr;
          do
          {
            if ( v128 != 0 )
              v16 = 1 - v127;
            else
              v16 = v127;
            if ( (unsigned int)dword_102BD06C[v16] >= 0x10 )
            {
              for ( i = 0; i < v125; ++i )
              {
                v17 = 0;
                if ( v123 != 0 )
                {
                  v18 = v112[i];
                  v19 = *((_DWORD *)v18 + 3);
                  while ( 1 )
                  {
                    m = nullptr;
                    if ( v19 != 0 )
                      break;
LABEL_33:
                    if ( ++v17 >= v123 )
                      goto LABEL_36;
                  }
                  v20 = *(_DWORD *)(*(_DWORD *)(jj + 8) + 4 * ((_DWORD)v129 + v17));
                  v21 = *((_DWORD **)v18 + 4);
                  while ( v20 != *v21 )
                  {
                    m = (unsigned int *)((char *)m + 1);
                    v19 = *((_DWORD *)v18 + 3);
                    ++v21;
                    if ( (unsigned int)m >= v19 )
                      goto LABEL_33;
                  }
                  matched = 1;
                }
LABEL_36:
                ;
              }
            }
            ++v127;
            v129 = (_DWORD **)((char *)v129 + v123);
          }
          while ( v127 < 2 );
          if ( matched == 0 )
          {
            if ( v119 != 0 )
              goto LABEL_80;
            for ( i = 0; i < v125; ++i )
            {
              v22 = *((struct D3DXShader::CInstruction **)v112[i] + 3);
              m = nullptr;
              v118 = v22;
              if ( v22 != nullptr )
              {
                do
                {
                  if ( *((_DWORD *)this + 3) != 0 )
                  {
                    v129 = *((_DWORD ***)this + 6);
                    n = *((struct D3DXShader::CInstruction **)this + 3);
                    do
                    {
                      v23 = (struct D3DXShader::CInstruction *)*v129;
                      if ( *v129 != nullptr && *(_DWORD *)v23 != 0 )
                      {
                        v24 = *((_DWORD *)v23 + 1);
                        v127 = 0;
                        if ( v24 != 0 )
                        {
                          v25 = *(_DWORD *)(*((_DWORD *)v112[i] + 4) + 4 * (_DWORD)m);
                          v26 = *((_DWORD **)v23 + 2);
                          for ( j = v24; j != 0; --j )
                          {
                            if ( *v26 == v25 || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v26) + 56) == v25 )
                              v127 = 1;
                            ++v26;
                          }
                        }
                        if ( v23 == (struct D3DXShader::CInstruction *)jj )
                          v127 = 0;
                        if ( v127 != 0 )
                        {
                          for ( k = 0; k < v125; ++k )
                          {
                            if ( v23 == v112[k] )
                              v127 = 0;
                          }
                          if ( v127 != 0 )
                            matched = 1;
                        }
                      }
                      ++v129;
                      n = (struct D3DXShader::CInstruction *)((char *)n - 1);
                    }
                    while ( n != nullptr );
                  }
                  m = (unsigned int *)((char *)m + 1);
                }
                while ( m < (unsigned int *)v118 );
              }
            }
            for ( m = nullptr; (unsigned int)m < 0x28; m = (unsigned int *)((char *)m + 1) )
            {
              v28 = v108[(_DWORD)m + 40];
              if ( v28 != -1 )
              {
                v29 = 0;
                if ( v125 != 0 )
                {
                  v118 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 5) + 4 * v28);
                  do
                  {
                    v30 = v112[v29];
                    v31 = *((struct D3DXShader::CInstruction **)v30 + 3);
                    if ( v31 != nullptr )
                    {
                      v32 = *((_DWORD **)v30 + 4);
                      for ( n = v31; n != nullptr; n = (struct D3DXShader::CInstruction *)((char *)n - 1) )
                      {
                        if ( v28 == *v32 || *((_DWORD *)v118 + 14) == *v32 )
                          matched = 1;
                        ++v32;
                      }
                    }
                    ++v29;
                  }
                  while ( v29 < v125 );
                }
              }
            }
            if ( matched == 0 )
            {
LABEL_80:
              v33 = v125;
              qmemcpy(v111, v112, 4 * v125);
              v111[v33] = (struct D3DXShader::CInstruction *)jj;
              v121 = v125 + 1;
              for ( ii = 0; ii < 40; ++ii )
              {
                v35 = v108[ii + 40];
                if ( v35 == -1 )
                {
                  v35 = v108[ii];
                  if ( v35 == -1 )
                    continue;
                }
                v109[ii] = v35;
              }
              matched = 0;
LABEL_86:
              if ( matched != 0 )
              {
                v5 = v120;
                break;
              }
LABEL_231:
              v93 = D3DXShader::CInstruction::operator new(a1: 0x74u);
              if ( v93 != nullptr )
                v79 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v93);
              else
                v79 = nullptr;
              if ( v79 == nullptr )
                return -2147024882;
              v94 = v120;
              v95 = v120 & 0xFFFFF;
              if ( i1 != 0 )
                v96 = v95 | 0x70400000;
              else
                v96 = v95 | 0x70300000;
              matched = D3DXShader::CInstruction::Initialize(this: v79, a2: v96, a3: 3 * v120, a4: v120, a5: 0);
              if ( matched >= 0 )
              {
                matched = D3DXShader::CInstruction::Instance(
                            this: v79,
                            a2: *((struct D3DXShader::CInstruction **)this + 64));
                if ( matched >= 0 )
                {
                  v97 = nullptr;
                  n = nullptr;
                  if ( v94 != 0 )
                  {
                    jj = 8 * v94;
                    v129 = (_DWORD **)(4 * v94);
                    do
                    {
                      v98 = 4 * (_DWORD)v97;
                      *(_DWORD *)(v98 + *((_DWORD *)v79 + 4)) = *(_DWORD *)(v98
                                                                          + *(_DWORD *)(*((_DWORD *)this + 64) + 16));
                      v99 = &v109[v98 / 4 + 4];
                      *(_DWORD *)(v98 + *((_DWORD *)v79 + 2)) = v109[v98 / 4];
                      v100 = *((_DWORD *)v79 + 2);
                      v101 = *v99;
                      v102 = v129;
                      v103 = v99[4];
                      ++v129;
                      *(_DWORD **)((char *)v102 + v100) = (_DWORD *)v101;
                      v104 = *((_DWORD *)v79 + 2);
                      v105 = jj;
                      jj += 4;
                      *(_DWORD *)(v105 + v104) = v103;
                      v97 = (char *)n + 1;
                      n = (struct D3DXShader::CInstruction *)((char *)n + 1);
                    }
                    while ( (unsigned int)n < v120 );
                  }
                  if ( a2 == 0 )
                    return D3DXShader::CShaderProgram::PlaceInstruction(this, a2: v79, a3: v111, a4: v121);
                  matched = D3DXShader::CInstruction::Initialize(
                              this: *((D3DXShader::CInstruction **)this + 64),
                              a2: v79);
                  if ( matched >= 0 )
LABEL_202:
                    matched = 0;
                }
              }
              if ( v79 != nullptr )
                D3DXShader::CInstruction::`scalar deleting destructor'(this: v79, a2: 1);
              return matched;
            }
          }
          if ( ++v128 < 2 )
            goto LABEL_4;
          if ( ++v119 != 0 )
            goto LABEL_86;
          goto LABEL_3;
        }
        matched = D3DXShader::CShaderProgram::MatchComplexTree(
                    this,
                    a2: n,
                    a3: (const struct D3DXShader::D3DX_MATCHENTRY *)((char *)&unk_102BD060 + v12),
                    a4: v112,
                    a5: &v125,
                    a6: v108,
                    a7: v113,
                    a8: v120,
                    a9: 0);
      }
      if ( matched != 1 )
      {
        v6 = (char *)m + v123;
        ++v127;
        m = (unsigned int *)((char *)m + v123);
        if ( v127 < 2 )
          continue;
      }
      goto LABEL_21;
    }
  }
  m = *((unsigned int **)this + 64);
  v36 = *m;
  v123 = *m;
  v123 &= 0xFFFFFu;
  if ( v123 > v5 || (v36 & 0xFFF00000) != 0x20400000 )
  {
    v37 = 1;
    goto LABEL_176;
  }
  v119 = 0;
  while ( 2 )
  {
    v127 = 0;
    while ( 2 )
    {
      v38 = v121;
      qmemcpy(v112, v111, 4 * v121);
      memset(v108, 255, sizeof(v108));
      v39 = nullptr;
      v125 = v38;
      matched = 0;
      v128 = 0;
      v129 = nullptr;
      while ( 1 )
      {
        if ( v127 != 0 )
          v40 = 1 - v128;
        else
          v40 = v128;
        v41 = m[2];
        v42 = dword_102BD0CC[v40];
        v43 = (unsigned int *)(v41 + 4 * (_DWORD)v39);
        if ( v42 >= 0x10 )
        {
          v46 = 0;
          v47 = &v108[4 * v42 - 24];
          do
          {
            v48 = v115[v46];
            if ( v48 >= v123 )
              *v47 = -1;
            else
              *v47 = *(_DWORD *)(v41 + 4 * ((_DWORD)v129 + v48));
            ++v46;
            ++v47;
          }
          while ( v46 < 4 );
          goto LABEL_106;
        }
        v44 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v43) + 72);
        if ( v44 == -1 )
          break;
        v45 = 32 * v42;
        v107 = dword_102BD0D8[8 * v42];
        v118 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v44);
        if ( D3DXShader::CShaderProgram::ComputeSwizzle(
               this,
               a2: v118,
               a3: v43,
               a4: v123,
               a5: v115,
               a6: v113,
               a7: v107,
               a8: 0) != 0 )
          break;
        matched = D3DXShader::CShaderProgram::MatchComplexTree(
                    this,
                    a2: v118,
                    a3: (const struct D3DXShader::D3DX_MATCHENTRY *)((char *)&unk_102BD0C0 + v45),
                    a4: v112,
                    a5: &v125,
                    a6: v108,
                    a7: v113,
                    a8: v120,
                    a9: 0);
LABEL_106:
        if ( matched != 1 )
        {
          v39 = (char *)v129 + v123;
          ++v128;
          v129 = (_DWORD **)((char *)v129 + v123);
          if ( v128 < 2 )
            continue;
        }
        goto LABEL_110;
      }
      matched = 1;
LABEL_110:
      v49 = 0;
      v128 = 0;
      i = 0;
      do
      {
        if ( v127 != 0 )
          v50 = 1 - v128;
        else
          v50 = v128;
        if ( (unsigned int)dword_102BD0CC[v50] >= 0x10 )
        {
          for ( jj = 0; jj < v125; v49 = 0 )
          {
            if ( v123 != 0 )
            {
              v51 = v112[jj];
              v52 = *((_DWORD *)v51 + 3);
              while ( 1 )
              {
                v129 = nullptr;
                if ( v52 != 0 )
                  break;
LABEL_122:
                if ( ++v49 >= v123 )
                  goto LABEL_125;
              }
              v53 = *(_DWORD *)(m[2] + 4 * (v49 + i));
              v54 = *((_DWORD **)v51 + 4);
              while ( v53 != *v54 )
              {
                v129 = (_DWORD **)((char *)v129 + 1);
                v52 = *((_DWORD *)v51 + 3);
                ++v54;
                if ( (unsigned int)v129 >= v52 )
                  goto LABEL_122;
              }
              matched = 1;
            }
LABEL_125:
            ++jj;
          }
        }
        ++v128;
        i += v123;
      }
      while ( v128 < 2 );
      if ( matched == 0 )
      {
        if ( v119 != 0 )
          goto LABEL_169;
        for ( i = 0; i < v125; ++i )
        {
          v55 = *((struct D3DXShader::CInstruction **)v112[i] + 3);
          jj = 0;
          v118 = v55;
          if ( v55 != nullptr )
          {
            do
            {
              if ( *((_DWORD *)this + 3) != 0 )
              {
                v129 = *((_DWORD ***)this + 6);
                j = *((_DWORD *)this + 3);
                do
                {
                  v56 = (struct D3DXShader::CInstruction *)*v129;
                  if ( *v129 != nullptr && *(_DWORD *)v56 != 0 )
                  {
                    v57 = *((struct D3DXShader::CInstruction **)v56 + 1);
                    v128 = 0;
                    if ( v57 != nullptr )
                    {
                      v58 = *(_DWORD *)(*((_DWORD *)v112[i] + 4) + 4 * jj);
                      v59 = *((_DWORD **)v56 + 2);
                      for ( n = v57; n != nullptr; n = (struct D3DXShader::CInstruction *)((char *)n - 1) )
                      {
                        if ( *v59 == v58 || *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v59) + 56) == v58 )
                          v128 = 1;
                        ++v59;
                      }
                    }
                    if ( v56 == (struct D3DXShader::CInstruction *)m )
                      v128 = 0;
                    if ( v128 != 0 )
                    {
                      for ( kk = 0; kk < v125; ++kk )
                      {
                        if ( v56 == v112[kk] )
                          v128 = 0;
                      }
                      if ( v128 != 0 )
                        matched = 1;
                    }
                  }
                  ++v129;
                  --j;
                }
                while ( j != 0 );
              }
              ++jj;
            }
            while ( jj < (unsigned int)v118 );
          }
        }
        for ( jj = 0; jj < 0x28; ++jj )
        {
          v61 = v108[jj + 40];
          if ( v61 != -1 )
          {
            v62 = 0;
            if ( v125 != 0 )
            {
              v118 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 5) + 4 * v61);
              do
              {
                v63 = v112[v62];
                v64 = *((struct D3DXShader::CInstruction **)v63 + 3);
                if ( v64 != nullptr )
                {
                  v65 = *((_DWORD **)v63 + 4);
                  for ( n = v64; n != nullptr; n = (struct D3DXShader::CInstruction *)((char *)n - 1) )
                  {
                    if ( v61 == *v65 || *((_DWORD *)v118 + 14) == *v65 )
                      matched = 1;
                    ++v65;
                  }
                }
                ++v62;
              }
              while ( v62 < v125 );
            }
          }
        }
        if ( matched == 0 )
        {
LABEL_169:
          v66 = v125;
          qmemcpy(v111, v112, 4 * v125);
          v111[v66] = (struct D3DXShader::CInstruction *)m;
          v121 = v125 + 1;
          for ( mm = 0; mm < 40; ++mm )
          {
            v68 = v108[mm + 40];
            if ( v68 == -1 )
            {
              v68 = v108[mm];
              if ( v68 == -1 )
                continue;
            }
            v109[mm] = v68;
          }
          matched = 0;
LABEL_175:
          v37 = matched;
LABEL_176:
          i1 = 1;
          if ( v37 == 0 )
            goto LABEL_231;
          if ( a2 != 0 )
          {
            i1 = 0;
            if ( D3DXShader::CShaderProgram::MatchComplexTree(
                   this,
                   a2: *((struct D3DXShader::CInstruction **)this + 64),
                   a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD060,
                   a4: v111,
                   a5: &v121,
                   a6: v109,
                   a7: v115,
                   a8: v120,
                   a9: a2) == 0 )
              goto LABEL_231;
            v37 = D3DXShader::CShaderProgram::MatchComplexTree(
                    this,
                    a2: *((struct D3DXShader::CInstruction **)this + 64),
                    a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD0C0,
                    a4: v111,
                    a5: &v121,
                    a6: v109,
                    a7: v115,
                    a8: v120,
                    a9: a2);
            i1 = 1;
          }
          if ( v37 == 0 )
            goto LABEL_231;
          v69 = v120;
          i1 = 0;
          v70 = D3DXShader::CShaderProgram::MatchComplexTree(
                  this,
                  a2: *((struct D3DXShader::CInstruction **)this + 64),
                  a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD120,
                  a4: v111,
                  a5: &v121,
                  a6: v109,
                  a7: v115,
                  a8: v120,
                  a9: a2);
          for ( nn = 0; nn < v69; ++nn )
          {
            if ( v109[nn] != v109[nn + 4] )
              v70 = 1;
          }
          if ( v70 != 0 )
          {
            v121 = 0;
            v72 = D3DXShader::CShaderProgram::MatchComplexTree(
                    this,
                    a2: *((struct D3DXShader::CInstruction **)this + 64),
                    a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD180,
                    a4: v111,
                    a5: &v121,
                    a6: v109,
                    a7: v115,
                    a8: v69,
                    a9: a2);
            v73 = 1;
            v74 = 0;
            matched = v72;
            for ( i1 = 1; v74 < v69; ++v74 )
            {
              if ( v109[v74] != v109[v74 + 4] )
                matched = 1;
            }
            if ( matched != 0 )
            {
              i1 = 0;
              v121 = 0;
              v75 = D3DXShader::CShaderProgram::MatchComplexTree(
                      this,
                      a2: *((struct D3DXShader::CInstruction **)this + 64),
                      a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD1E0,
                      a4: v111,
                      a5: &v121,
                      a6: v109,
                      a7: v115,
                      a8: v69,
                      a9: a2);
              v76 = 0;
              for ( matched = v75; v76 < v69; ++v76 )
              {
                if ( v109[v76] != v109[v76 + 4] )
                  matched = 1;
              }
              if ( matched != 0 )
              {
                v121 = 0;
                v77 = D3DXShader::CShaderProgram::MatchComplexTree(
                        this,
                        a2: *((struct D3DXShader::CInstruction **)this + 64),
                        a3: (const struct D3DXShader::D3DX_MATCHENTRY *)&unk_102BD240,
                        a4: v111,
                        a5: &v121,
                        a6: v109,
                        a7: v115,
                        a8: v69,
                        a9: a2);
                v78 = 0;
                matched = v77;
                for ( i1 = 1; v78 < v69; ++v78 )
                {
                  if ( v109[v78] != v109[v78 + 4] )
                    matched = 1;
                }
                if ( matched != 0 )
                {
                  v79 = v114;
                  goto LABEL_202;
                }
              }
            }
          }
          else
          {
            v73 = 1;
          }
          v81 = 0;
          if ( v69 == 0 )
          {
LABEL_210:
            if ( *((_DWORD *)this + 88) != -1
              || (v82 = D3DXShader::CBaseProgram::AddPool(
                          this,
                          a2: (char *)&stru_102A6BD8.m_Memory.m_nGrowSize,
                          a3: 0x311u,
                          a4: 1u,
                          a5: 4u),
                  *((_DWORD *)this + 92) = v82,
                  v82 != -1)
              && (v83 = D3DXShader::CBaseProgram::AddArgument(this, a2: v82, a3: 0, a4: 0, a5: 2.0),
                  *((_DWORD *)this + 88) = v83,
                  v83 != -1) )
            {
              v84 = 0;
              if ( v69 != 0 )
              {
                v85 = *((_DWORD *)this + 88);
                do
                {
                  v86 = v110[v84];
                  v109[v84] = v85;
                  if ( v86 != v110[0] )
                    v73 = 0;
                  ++v84;
                }
                while ( v84 < v69 );
              }
              v87 = *((_DWORD *)this + 5);
              v88 = *(_DWORD *)(v87 + 4 * v110[0]);
              if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v88 + 4)) + 5) & 1) == 0 || v73 == 0 )
                goto LABEL_231;
              v89 = 0;
              v90 = (_DWORD *)((char *)this + 356);
              do
              {
                if ( *v90 == -1 )
                  break;
                if ( *(double *)(*(_DWORD *)(v87 + 4 * *v90) + 32) == *(double *)(v88 + 32) )
                  break;
                ++v89;
                ++v90;
              }
              while ( v89 < 3 );
              if ( v89 == 3 )
                goto LABEL_231;
              v91 = (int *)((char *)this + 4 * v89 + 356);
              if ( *v91 != -1
                || (v92 = D3DXShader::CBaseProgram::AddArgument(
                            this,
                            a2: *((_DWORD *)this + 92),
                            a3: 0,
                            a4: v89 + 1,
                            a5: *(double *)(v88 + 32)),
                    *v91 = v92,
                    v92 != -1) )
              {
                if ( v120 != 0 )
                  memset32(v110, *v91, v120);
                goto LABEL_231;
              }
            }
            return -2147024882;
          }
          while ( v109[v81] == v109[v81 + 4] )
          {
            if ( ++v81 >= v69 )
              goto LABEL_210;
          }
          return 1;
        }
      }
      if ( ++v127 < 2 )
        continue;
      break;
    }
    if ( ++v119 != 0 )
      goto LABEL_175;
    continue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022171A
// Name: protected: long D3DXShader::CShaderProgram::MatchBiasModifier(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchBiasModifier(D3DXShader::CShaderProgram *this)
{
  _DWORD *v2; // ecx
  int result; // eax
  int v4; // edx
  unsigned int *v5; // eax
  unsigned int *v6; // ecx
  int v7; // esi
  int v8; // ebx
  int v9; // edx
  unsigned int v10; // ebx
  unsigned int *v11; // edx
  int v12; // ecx
  _BYTE *v13; // eax
  struct D3DXShader::CInstruction *v14; // ecx
  int v15; // eax
  int matched; // esi
  struct D3DXShader::CInstruction *v17; // eax
  _DWORD *v18; // edx
  int v19; // eax
  _DWORD *v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // esi
  int v25; // eax
  _DWORD *v26; // ecx
  struct D3DXShader::CInstruction *v27; // edx
  unsigned int *v28; // eax
  struct D3DXShader::CInstruction *v29[4]; // [esp+14h] [ebp-2Ch]
  struct D3DXShader::CInstruction *v30[3]; // [esp+24h] [ebp-1Ch] BYREF
  int v31; // [esp+30h] [ebp-10h]
  struct D3DXShader::CInstruction **v32; // [esp+34h] [ebp-Ch]
  unsigned int v33; // [esp+38h] [ebp-8h]
  unsigned int *v34; // [esp+3Ch] [ebp-4h]

  v2 = *((_DWORD **)this + 64);
  if ( (*v2 & 0xFFF00000) != 0x20400000 )
    return 1;
  v4 = *v2 & 0xFFFFF;
  v5 = (unsigned int *)v2[2];
  v6 = &v5[v4];
  v7 = *((_DWORD *)this + 5);
  v8 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v6) + 4);
  v33 = v4;
  v9 = *((_DWORD *)this + 4);
  if ( (*(_BYTE *)(*(_DWORD *)(v9 + 4 * v8) + 5) & 1) != 0 )
  {
    v31 = 0;
    v34 = v5;
    v5 = v6;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v5) + 4)) + 5) & 1) == 0 )
      return 1;
    v31 = 1;
    v34 = v6;
  }
  v10 = v33;
  *((_DWORD *)this + 87) = 0;
  v32 = nullptr;
  if ( v10 != 0 )
  {
    v11 = v34;
    v12 = (char *)v5 - (char *)v34;
    while ( *(double *)(*(_DWORD *)(v7 + 4 * *(unsigned int *)((char *)v11 + v12)) + 32) == -0.5 )
    {
      v13 = *(_BYTE **)(v7 + 4 * *v11);
      if ( (v13[61] & 2) == 0 && (*v13 & 4) == 0 && (*((_BYTE *)this + 110) & 4) != 0 )
        *((_DWORD *)this + 87) = 1;
      v32 = (struct D3DXShader::CInstruction **)((char *)v32 + 1);
      ++v11;
      if ( (unsigned int)v32 >= v10 )
        goto LABEL_15;
    }
    return 1;
  }
LABEL_15:
  v14 = *((struct D3DXShader::CInstruction **)this + 64);
  v15 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * **((_DWORD **)v14 + 4)) + 4);
  if ( v15 == *((_DWORD *)this + 34) )
  {
    matched = D3DXShader::CShaderProgram::MatchSourceModifier(
                this,
                a2: 0x20000u,
                a3: 0,
                a4: (char *)v34,
                a5: 0x20000u,
                a6: nullptr,
                a7: 0);
    if ( *((_DWORD *)this + 87) == 2 )
      D3DXShader::CProgram::Warning(
        this,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
        a3: 0x125Du,
        format: "_bias opportunity missed because source was not clamped 0 to 1");
    return matched;
  }
  if ( v15 != *((_DWORD *)this + 33) )
    return 1;
  result = D3DXShader::CShaderProgram::FindMatchUp(this, a2: v10 & 0xFFFFF | 0x20400000, a3: v14, a4: v30, a5: 2u);
  if ( result != 0 )
    return result;
  v32 = &v30[v31];
  v17 = *v32;
  if ( *v32 == nullptr )
    return 1;
  v34 = nullptr;
  if ( v10 != 0 )
  {
    v18 = *((_DWORD **)v17 + 2);
    do
    {
      v19 = *(_DWORD *)(v7 + 4 * *v18);
      if ( (*(_BYTE *)(v19 + 62) & 0x1F) != 0 )
        break;
      if ( (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v19 + 4)) + 4) & 0x200) != 0
        || (*(_DWORD *)(v19 + 60) & 0x200) == 0 && (*(_BYTE *)v19 & 4) == 0 )
      {
        v10 = v33;
        break;
      }
      v31 = 0;
      v34 = (unsigned int *)((char *)v34 + 1);
      v10 = v33;
      ++v18;
    }
    while ( (unsigned int)v34 < v33 );
  }
  if ( v34 != (unsigned int *)v10 )
  {
    v34 = nullptr;
    if ( v10 != 0 )
    {
      v20 = (_DWORD *)(4 * v10 + *((_DWORD *)*v32 + 2));
      do
      {
        v21 = *(_DWORD *)(v7 + 4 * *v20);
        if ( (*(_BYTE *)(v21 + 62) & 0x1F) != 0 )
          break;
        if ( (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v21 + 4)) + 4) & 0x200) != 0
          || (*(_DWORD *)(v21 + 60) & 0x200) == 0 && (*(_BYTE *)v21 & 4) == 0 )
        {
          v10 = v33;
          break;
        }
        v34 = (unsigned int *)((char *)v34 + 1);
        v10 = v33;
        ++v20;
      }
      while ( (unsigned int)v34 < v33 );
    }
    if ( v34 != (unsigned int *)v10 )
    {
      v22 = v10;
      goto LABEL_44;
    }
    return 1;
  }
  v22 = v31;
LABEL_44:
  v34 = nullptr;
  if ( v10 != 0 )
  {
    v23 = 4 * v22;
    while ( 1 )
    {
      v24 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v23 + *((_DWORD *)*v32 + 2)));
      v25 = D3DXShader::CBaseProgram::AddArgument(
              this,
              a2: *(_DWORD *)(v24 + 4),
              a3: *(_DWORD *)(v24 + 12),
              a4: *(_DWORD *)(v24 + 16),
              a5: *(double *)(v24 + 32));
      v31 = v25;
      v29[(_DWORD)v34] = (struct D3DXShader::CInstruction *)v25;
      if ( v25 == -1 )
        return -2147024882;
      v26 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v25);
      v27 = *v32;
      v26[14] = *(_DWORD *)(v23 + *((_DWORD *)*v32 + 2));
      v26[18] = *(_DWORD *)(v24 + 72);
      v26[20] = *(_DWORD *)(v24 + 80);
      v26[21] = *(_DWORD *)(v24 + 84);
      v26[22] = *(_DWORD *)(v24 + 84);
      v26[15] = *(_DWORD *)(v24 + 60) | 0x20000;
      *(_DWORD *)(v23 + *((_DWORD *)v27 + 2)) = v31;
      v28 = v34;
      *(_DWORD *)(*((_DWORD *)v27 + 4) + 4 * (_DWORD)v34) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 16)
                                                                      + 4 * (_DWORD)v34);
      v23 += 4;
      v34 = (unsigned int *)((char *)v28 + 1);
      if ( (unsigned int)v28 + 1 >= v33 )
        goto LABEL_48;
    }
  }
  else
  {
LABEL_48:
    **((_DWORD **)this + 64) = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10221A17
// Name: protected: long D3DXShader::CShaderProgram::MatchX2Modifier(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchX2Modifier(D3DXShader::CShaderProgram *this)
{
  int *v1; // edx
  int v2; // eax
  unsigned int v3; // esi
  int v4; // esi
  char *v5; // eax
  char *v6; // edx
  int v7; // esi
  int v8; // edx
  char *v9; // edx
  unsigned int v10; // ebx
  char *v12; // edx
  bool v13; // zf
  int v14; // eax
  char *v15; // eax
  _DWORD *i; // esi
  unsigned int v17; // [esp+Ch] [ebp-10h]
  char *v18; // [esp+10h] [ebp-Ch]
  unsigned int v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+14h] [ebp-8h]
  char *v21; // [esp+18h] [ebp-4h]
  int v22; // [esp+18h] [ebp-4h]

  *((_DWORD *)this + 87) = 0;
  v1 = *((int **)this + 64);
  v2 = *v1;
  v3 = *v1 & 0xFFF00000;
  if ( v3 == 542113792 )
  {
    v4 = v2 & 0xFFFFF;
    v5 = (char *)v1[2];
    v6 = &v5[4 * v4];
    v19 = v4;
    v7 = *((_DWORD *)this + 5);
    v21 = v6;
    v8 = *((_DWORD *)this + 4);
    if ( (*(_DWORD *)(*(_DWORD *)(v8 + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)v5) + 4)) + 4) & 0x100) != 0 )
    {
      v9 = v5;
      v5 = v21;
LABEL_6:
      v18 = v9;
      if ( v19 == 0 )
        return D3DXShader::CShaderProgram::MatchSourceModifier(
                 this,
                 a2: 0x40000u,
                 a3: 0x20000u,
                 a4: v18,
                 a5: 0x40000u,
                 a6: nullptr,
                 a7: 0);
      v10 = 0;
      v22 = v5 - v9;
      while ( *(double *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)&v9[v22]) + 32) == 2.0
           && ((*(_DWORD *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)v9) + 60) & 0x1F0000) == 0x20000
            || (*((_BYTE *)this + 110) & 8) == 0) )
      {
        ++v10;
        v9 += 4;
        if ( v10 >= v19 )
          return D3DXShader::CShaderProgram::MatchSourceModifier(
                   this,
                   a2: 0x40000u,
                   a3: 0x20000u,
                   a4: v18,
                   a5: 0x40000u,
                   a6: nullptr,
                   a7: 0);
      }
      return 1;
    }
    if ( (*(_DWORD *)(*(_DWORD *)(v8 + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)v21) + 4)) + 4) & 0x100) != 0 )
    {
      v9 = v21;
      goto LABEL_6;
    }
    return 1;
  }
  if ( v3 != 541065216 )
    return 1;
  v12 = (char *)v1[2];
  v14 = v2 & 0xFFFFF;
  v13 = v14 == 0;
  v17 = v14;
  v15 = &v12[4 * v14];
  v20 = 0;
  if ( !v13 )
  {
    for ( i = v12;
          *i == *(_DWORD *)((char *)i + v15 - v12)
       && ((*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *i) + 60) & 0x1F0000) == 0x20000
        || (*((_BYTE *)this + 110) & 8) == 0);
          ++i )
    {
      if ( ++v20 >= v17 )
        return D3DXShader::CShaderProgram::MatchSourceModifier(
                 this,
                 a2: 0x40000u,
                 a3: 0x20000u,
                 a4: v12,
                 a5: 0x40000u,
                 a6: nullptr,
                 a7: 0);
    }
    return 1;
  }
  return D3DXShader::CShaderProgram::MatchSourceModifier(
           this,
           a2: 0x40000u,
           a3: 0x20000u,
           a4: v12,
           a5: 0x40000u,
           a6: nullptr,
           a7: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10221B79
// Name: protected: long D3DXShader::CShaderProgram::MatchCompModifier(class D3DXShader::CInstruction __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchCompModifier(
        D3DXShader::CShaderProgram *this,
        struct D3DXShader::CInstruction *a2)
{
  struct D3DXShader::CInstruction *v3; // ecx
  int v5; // edx
  unsigned int *v6; // eax
  int v7; // ecx
  unsigned int *v8; // edi
  int v9; // edx
  char **v10; // ebx
  char *v11; // ecx
  int v12; // edi
  int matched; // eax
  int v14; // edi
  unsigned int v15; // [esp+8h] [ebp-14h]
  unsigned int *v16; // [esp+Ch] [ebp-10h]
  unsigned int v17; // [esp+10h] [ebp-Ch]
  int v18; // [esp+14h] [ebp-8h]
  int v19; // [esp+18h] [ebp-4h]

  v19 = 0;
  v3 = a2;
  if ( a2 != nullptr )
  {
    v19 = 1;
  }
  else
  {
    v3 = *((struct D3DXShader::CInstruction **)this + 64);
    a2 = v3;
  }
  if ( (*(_DWORD *)v3 & 0xFFF00000) != 0x20400000 )
    return 1;
  v5 = *(_DWORD *)v3 & 0xFFFFF;
  v6 = *((unsigned int **)v3 + 2);
  v7 = *((_DWORD *)this + 4);
  v8 = &v6[v5];
  v15 = v5;
  v9 = *((_DWORD *)this + 5);
  if ( (*(_BYTE *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * *v8) + 4)) + 5) & 1) != 0 )
  {
    v16 = v6;
    v6 = v8;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * *v6) + 4)) + 5) & 1) == 0 )
      return 1;
    v16 = v8;
  }
  v10 = *((char ***)this + 64);
  v11 = (char *)v16;
  if ( v10 != (char **)a2 )
    v11 = v10[2];
  *((_DWORD *)this + 87) = 0;
  v17 = 0;
  if ( v15 != 0 )
  {
    v18 = (char *)v6 - v11;
    while ( *(double *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)&v11[v18]) + 32) == 1.0
         && (v19 != 0 || (*(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)v11) + 60) & 0x1F0000) == 0x80000) )
    {
      v12 = *(_DWORD *)(v9 + 4 * *(_DWORD *)v11);
      if ( (*(_BYTE *)(v12 + 61) & 2) == 0 && ((4 * (v19 == 0) + 20) & *(_DWORD *)v12) == 0 )
        *((_DWORD *)this + 87) = 1;
      ++v17;
      v11 += 4;
      if ( v17 >= v15 )
        goto LABEL_21;
    }
    return 1;
  }
LABEL_21:
  if ( v19 != 0 )
    matched = D3DXShader::CShaderProgram::MatchSourceModifier(
                this,
                a2: 0x10000u,
                a3: 0,
                a4: v10[2],
                a5: 0x10000u,
                a6: a2,
                a7: 0);
  else
    matched = D3DXShader::CShaderProgram::MatchSourceModifier(
                this,
                a2: 0x10000u,
                a3: 0x80000u,
                a4: (char *)v16,
                a5: 0x90000u,
                a6: nullptr,
                a7: 0);
  v14 = matched;
  if ( *((_DWORD *)this + 87) == 2 )
    D3DXShader::CProgram::Warning(
      this,
      a2: *(struct D3DXShader::CNode **)(*((_DWORD *)this + 64) + 60),
      a3: 0x125Eu,
      format: "complement opportunity missed because input result WAS clamped from 0 to 1");
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10221D01
// Name: protected: long D3DXShader::CShaderProgram::MatchComplexComp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchComplexComp(D3DXShader::CShaderProgram *this)
{
  int v2; // eax
  struct D3DXShader::CInstruction *Match; // eax
  struct D3DXShader::CInstruction *v5; // edi
  int matched; // [esp+8h] [ebp-4h]

  matched = 1;
  if ( (**((_DWORD **)this + 64) & 0xFFF00000) == 0x20500000 )
  {
    v2 = *(_DWORD *)(*((_DWORD *)this + 5)
                   + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * (**((_DWORD **)this + 64) & 0xFFFFF)));
    if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v2 + 4)) + 5) & 1) == 0
      || *(double *)(v2 + 32) != -1.0 )
    {
      return 1;
    }
  }
  Match = D3DXShader::CShaderProgram::FindMatch(
            this,
            a2: **((_DWORD **)this + 64) & 0xFFFFF | 0x20400000,
            a3: *((unsigned int ***)this + 64),
            a4: nullptr,
            a5: 2u,
            a6: 1u);
  v5 = Match;
  if ( Match != nullptr )
  {
    matched = D3DXShader::CShaderProgram::MatchCompModifier(this, a2: Match);
    if ( matched == 0 )
      *(_DWORD *)v5 = 0;
  }
  return matched;
}

//------------------------------------------------------------------------------
// Address: 0x10221DA1
// Name: protected: long D3DXShader::CShaderProgram::MatchComplexBX2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchComplexBX2(D3DXShader::CShaderProgram *this)
{
  struct D3DXShader::CInstruction *Match; // eax
  int v3; // ecx
  _DWORD *v4; // edx
  _DWORD *v5; // esi
  double v6; // st7
  unsigned int v7; // esi
  char *v8; // eax
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // esi
  int v12; // ecx
  struct D3DXShader::CInstruction *v13; // eax
  _DWORD *v14; // ecx
  _DWORD *v15; // edx
  struct D3DXShader::CInstruction *v16; // esi
  int result; // eax
  struct D3DXShader::CInstruction *v18; // [esp+Ch] [ebp-10h]
  char *v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-8h]
  int v22; // [esp+18h] [ebp-4h]
  int v23; // [esp+18h] [ebp-4h]

  *((_DWORD *)this + 87) = 0;
  Match = *((struct D3DXShader::CInstruction **)this + 64);
  if ( (*(_DWORD *)Match & 0xFFF00000) != 0x20400000 )
    return 1;
  v3 = *(_DWORD *)Match & 0xFFFFF;
  v22 = 1;
  if ( v3 == 0 )
    goto LABEL_8;
  v4 = *((_DWORD **)Match + 2);
  v5 = &v4[v3];
  v20 = *(_DWORD *)Match & 0xFFFFF;
  do
  {
    if ( *v4 != *v5 )
      v22 = 0;
    ++v5;
    ++v4;
    --v20;
  }
  while ( v20 != 0 );
  if ( v22 == 0 )
  {
    v6 = -0.5;
  }
  else
  {
LABEL_8:
    Match = D3DXShader::CShaderProgram::FindMatch(
              this,
              a2: v3 | 0x20400000,
              a3: (unsigned int **)Match,
              a4: nullptr,
              a5: 2u,
              a6: 1u);
    v6 = -1.0;
    if ( Match == nullptr )
      return 1;
    v18 = Match;
  }
  v7 = *(_DWORD *)Match;
  v8 = *((char **)Match + 2);
  v9 = *((_DWORD *)this + 5);
  v10 = *((_DWORD *)this + 4);
  v11 = v7 & 0xFFFFF;
  if ( (*(_BYTE *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)&v8[4 * v11]) + 4)) + 5) & 1) != 0 )
  {
    v19 = v8;
    v8 += 4 * v11;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)v8) + 4)) + 5) & 1) == 0 )
      return 1;
    v19 = &v8[4 * v11];
  }
  v12 = 0;
  if ( v11 != 0 )
  {
    while ( *(double *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)&v8[4 * v12]) + 32) == v6 )
    {
      if ( ++v12 >= v11 )
        goto LABEL_18;
    }
    return 1;
  }
LABEL_18:
  if ( v22 == 0 )
  {
    v13 = D3DXShader::CShaderProgram::FindMatch(
            this,
            a2: **((_DWORD **)this + 64) & 0xFFFFF | 0x20400000,
            a3: *((unsigned int ***)this + 64),
            a4: nullptr,
            a5: 2u,
            a6: 2u);
    if ( v13 != nullptr )
    {
      v23 = 1;
      if ( v11 == 0 )
        goto LABEL_26;
      v14 = *((_DWORD **)v13 + 2);
      v15 = &v14[v11];
      for ( i = v11; i != 0; --i )
      {
        if ( *v14 != *v15 )
          v23 = 0;
        ++v15;
        ++v14;
      }
      if ( v23 != 0 )
      {
LABEL_26:
        v16 = v13;
        result = D3DXShader::CShaderProgram::MatchSourceModifier(
                   this,
                   a2: 0x60000u,
                   a3: 0,
                   a4: v19,
                   a5: 0x60000u,
                   a6: v13,
                   a7: 0);
        goto LABEL_28;
      }
    }
    return 1;
  }
  v16 = v18;
  result = D3DXShader::CShaderProgram::MatchSourceModifier(
             this,
             a2: 0x60000u,
             a3: 0,
             a4: *(char **)(*((_DWORD *)this + 64) + 8),
             a5: 0x60000u,
             a6: v18,
             a7: 0);
LABEL_28:
  if ( result == 0 )
    *(_DWORD *)v16 = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10221F3E
// Name: protected: long D3DXShader::CShaderProgram::MatchLRP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::MatchLRP(D3DXShader::CShaderProgram *this)
{
  int v1; // edi
  unsigned int v2; // eax
  unsigned int v3; // edi
  struct D3DXShader::CInstruction *v5; // ebx
  _DWORD *v6; // edx
  _DWORD *v7; // eax
  unsigned int *v8; // esi
  unsigned int v9; // eax
  unsigned int *v10; // edi
  unsigned int *v11; // [esp+Ch] [ebp-24h]
  unsigned int *v12; // [esp+14h] [ebp-1Ch]
  struct D3DXShader::CInstruction *v13; // [esp+18h] [ebp-18h] BYREF
  struct D3DXShader::CInstruction *v14; // [esp+20h] [ebp-10h]
  unsigned int v15; // [esp+24h] [ebp-Ch]
  D3DXShader::CShaderProgram *v16; // [esp+28h] [ebp-8h]
  unsigned int v17; // [esp+2Ch] [ebp-4h]

  v1 = **((_DWORD **)this + 64);
  v2 = v1 & 0xFFF00000;
  v3 = v1 & 0xFFFFF;
  v16 = this;
  if ( v2 != 1882193920 )
    return 1;
  v5 = *((struct D3DXShader::CInstruction **)this + 64);
  v17 = *((_DWORD *)this + 63);
  D3DXShader::CShaderProgram::FindMatchUp(this, a2: v3 & 0xFFFFF | 0x20500000, a3: v5, a4: &v13, a5: 2u);
  if ( v14 == nullptr )
    return 1;
  v15 = 0;
  if ( v3 != 0 )
  {
    v6 = *((_DWORD **)v14 + 4);
    v7 = (_DWORD *)(*((_DWORD *)v5 + 2) + 8 * v3);
    while ( *v7 == *v6 )
    {
      ++v15;
      ++v7;
      ++v6;
      if ( v15 >= v3 )
        goto LABEL_8;
    }
    return 1;
  }
LABEL_8:
  v8 = *((unsigned int **)v5 + 2);
  v9 = v3;
  v10 = *((unsigned int **)v14 + 2);
  v9 *= 4;
  v11 = (unsigned int *)((char *)v8 + v9);
  v12 = (unsigned int *)((char *)v10 + v9);
  if ( D3DXShader::CShaderProgram::BuildLRP(
         this: v16,
         a2: v8,
         a3: (unsigned int *)((char *)v8 + v9),
         a4: v10,
         a5: (unsigned int *)((char *)v10 + v9),
         a6: v14,
         a7: (const void **)v5,
         a8: v17) != 0
    && D3DXShader::CShaderProgram::BuildLRP(
         this: v16,
         a2: v11,
         a3: v8,
         a4: v10,
         a5: v12,
         a6: v14,
         a7: (const void **)v5,
         a8: v17) != 0
    && D3DXShader::CShaderProgram::BuildLRP(
         this: v16,
         a2: v8,
         a3: v11,
         a4: v12,
         a5: v10,
         a6: v14,
         a7: (const void **)v5,
         a8: v17) != 0
    && D3DXShader::CShaderProgram::BuildLRP(
         this: v16,
         a2: v11,
         a3: v8,
         a4: v12,
         a5: v10,
         a6: v14,
         a7: (const void **)v5,
         a8: v17) != 0
    && D3DXShader::CShaderProgram::BuildLRP(
         this: v16,
         a2: v10,
         a3: v12,
         a4: v8,
         a5: v11,
         a6: v14,
         a7: (const void **)v5,
         a8: v17) != 0
    && D3DXShader::CShaderProgram::BuildLRP(
         this: v16,
         a2: v12,
         a3: v10,
         a4: v8,
         a5: v11,
         a6: v14,
         a7: (const void **)v5,
         a8: v17) != 0
    && D3DXShader::CShaderProgram::BuildLRP(
         this: v16,
         a2: v10,
         a3: v12,
         a4: v11,
         a5: v8,
         a6: v14,
         a7: (const void **)v5,
         a8: v17) != 0 )
  {
    return D3DXShader::CShaderProgram::BuildLRP(
             this: v16,
             a2: v12,
             a3: v10,
             a4: v11,
             a5: v8,
             a6: v14,
             a7: (const void **)v5,
             a8: v17);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102220C7
// Name: protected: long D3DXShader::CShaderProgram::ResolveFlowControl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::ResolveFlowControl(D3DXShader::CShaderProgram *this)
{
  unsigned int v1; // ebx
  unsigned int v3; // eax
  bool v4; // zf
  int result; // eax
  int v6; // ecx
  int v7; // edx
  unsigned int v8; // ecx
  _DWORD *v9; // edx
  bool v10; // cf
  int v11; // edi
  unsigned int v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  D3DXShader::CArgument *v16; // ebx
  unsigned int v17; // ecx
  struct D3DXShader::CArgument *v18; // eax
  int v19; // ecx
  unsigned int v20; // eax
  int v21; // ebx
  bool v22; // cc
  int v23; // eax
  int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // edx
  int v27; // ecx
  struct D3DXShader::CArgument *v28; // eax
  int v29; // ecx
  unsigned int v30[32]; // [esp+14h] [ebp-10Ch] BYREF
  int v31[32]; // [esp+94h] [ebp-8Ch] BYREF
  struct D3DXShader::CArgument *v32; // [esp+114h] [ebp-Ch] BYREF
  unsigned int v33; // [esp+118h] [ebp-8h]
  unsigned int v34; // [esp+11Ch] [ebp-4h] BYREF

  v1 = 0;
  v3 = 0;
  v4 = *((_DWORD *)this + 2) == 0;
  v32 = nullptr;
  if ( !v4 )
  {
    do
    {
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v3) + 48) = -1;
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v3++) + 52) = -1;
    }
    while ( v3 < *((_DWORD *)this + 2) );
  }
  v33 = *((_DWORD *)this + 3);
  result = D3DXShader::CShaderProgram::GroupIfs(
             this,
             a2: 0x1FFFFFFFFLL,
             a3: (unsigned int *)&v32,
             a4: nullptr,
             a5: nullptr,
             a6: nullptr,
             a7: v33,
             a8: (D3DXShader::CInstruction *)1,
             a9: 0,
             a10: 0,
             a11: 0);
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v6 = 4 * v1;
      v7 = 4 * v1 + *((_DWORD *)this + 5);
      if ( *(_DWORD *)(*(_DWORD *)v7 + 48) != -1 || *(_DWORD *)(*(_DWORD *)v7 + 52) != -1 )
      {
        *(_DWORD *)(*(_DWORD *)v7 + 20) = *(_DWORD *)(*(_DWORD *)v7 + 48);
        *(_DWORD *)(*(_DWORD *)(v6 + *((_DWORD *)this + 5)) + 24) = *(_DWORD *)(*(_DWORD *)(v6 + *((_DWORD *)this + 5))
                                                                              + 52);
      }
      *(_DWORD *)(*(_DWORD *)(v6 + *((_DWORD *)this + 5)) + 48) = -1;
      *(_DWORD *)(*(_DWORD *)(v6 + *((_DWORD *)this + 5)) + 52) = -1;
      ++v1;
    }
    while ( v1 < *((_DWORD *)this + 2) );
  }
  v8 = 0;
  if ( v33 != 0 )
  {
    do
    {
      v9 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v8++);
      v10 = v8 < v33;
      *v9 = 0;
    }
    while ( v10 );
  }
  if ( result >= 0 )
  {
    *((_DWORD *)this + 63) = 0;
    D3DXShader::CShaderProgram::Scan(this, a2: v30, a3: v31, a4: 0, a5: 0);
    v4 = *((_DWORD *)this + 3) == 0;
    v33 = 0;
    if ( !v4 )
    {
      do
      {
        v11 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v33);
        v12 = *(_DWORD *)v11 & 0xFFF00000;
        if ( (*(_DWORD *)v11 & 0xFFFFF) == 1 )
        {
          v32 = (struct D3DXShader::CArgument *)-1;
          v34 = -1;
          switch ( v12 )
          {
            case 0x73000000u:
            case 0x73200000u:
            case 0x73100000u:
            case 0x73300000u:
              v28 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v11 + 8));
              v29 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)v28 + 1)) + 4);
              if ( (v29 & 0x200) != 0 && (v29 & 0x2000) == 0 )
              {
                result = D3DXShader::CShaderProgram::RFC_Convert(
                           this,
                           a2: (char *)&stru_102A0968,
                           a3: 0x2000u,
                           a4: v28,
                           a5: (unsigned int *)&v32);
                if ( result < 0 )
                  return result;
                **(_DWORD **)(v11 + 8) = v32;
              }
              break;
            case 0x73B00000u:
              v13 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 8) + 4));
              if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v13 + 4)) + 5) & 1) != 0
                && *(_DWORD *)(v13 + 8) == -1
                && *(double *)(v13 + 32) == 0.0 )
              {
                v14 = D3DXShader::CBaseProgram::AddArgument(this, a2: 0, a3: 0, a4: 0, a5: 0.0);
                v34 = v14;
                if ( v14 == -1 )
                  return -2147024882;
                v15 = *((_DWORD *)this + 5);
                v16 = *(D3DXShader::CArgument **)(v15 + 4 * v14);
                v32 = *(struct D3DXShader::CArgument **)(v15 + 4 * **(_DWORD **)(v11 + 8));
                result = D3DXShader::CArgument::Initialize(this: v16, a2: v32);
                if ( result < 0 )
                  return result;
                result = D3DXShader::CArgument::Instance(this: v16, a2: v32);
                if ( result < 0 )
                  return result;
                *((_DWORD *)v16 + 15) ^= 0x80000u;
                v17 = v34;
                *((_DWORD *)v16 + 14) = **(_DWORD **)(v11 + 8);
                *(_DWORD *)(*(_DWORD *)(v11 + 8) + 4) = v17;
              }
              break;
            case 0x74200000u:
            case 0x74100000u:
              v18 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v11 + 8));
              v19 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)v18 + 1)) + 4);
              if ( (v19 & 0x200) != 0 && (v19 & 0x40000) == 0 )
              {
                result = D3DXShader::CShaderProgram::RFC_Convert(this, a2: "i", a3: 0x40000u, a4: v18, a5: &v34);
                if ( result < 0 )
                  return result;
                v20 = v34;
                **(_DWORD **)(v11 + 8) = v34;
                v21 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v20);
                v22 = *(_DWORD *)(v11 + 4) <= 1u;
                v34 = 1;
                if ( !v22 )
                {
                  do
                  {
                    v23 = *(_DWORD *)(*(_DWORD *)(v11 + 8) + 4 * v34);
                    if ( v23 == -1 )
                      v24 = v21;
                    else
                      v24 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v23);
                    v25 = D3DXShader::CBaseProgram::AddArgument(
                            this,
                            a2: *(_DWORD *)(v21 + 4),
                            a3: *(_DWORD *)(v21 + 12),
                            a4: v34,
                            a5: *(double *)(v24 + 32));
                    v26 = v34;
                    v27 = *(_DWORD *)(v11 + 8);
                    ++v34;
                    *(_DWORD *)(v27 + 4 * v26) = v25;
                  }
                  while ( v34 < *(_DWORD *)(v11 + 4) );
                }
              }
              break;
            default:
              break;
          }
        }
        ++v33;
      }
      while ( v33 < *((_DWORD *)this + 3) );
    }
    result = D3DXShader::CProgram::CompactArguments(this);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102223EB
// Name: protected: long D3DXShader::CShaderProgram::Emit(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::Emit(D3DXShader::CShaderProgram *this, unsigned int a2)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::Assure(this, a2: 1u);
  if ( result >= 0 )
  {
    *(_DWORD *)(*((_DWORD *)this + 67) + 4 * (*((_DWORD *)this + 68))++) = a2;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022241B
// Name: protected: long D3DXShader::CShaderProgram::EmitPreShader(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitPreShader(D3DXShader::CShaderProgram *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  const void *v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // eax
  unsigned int v10; // [esp-Ch] [ebp-28h]
  _BYTE v11[16]; // [esp+8h] [ebp-14h] BYREF
  unsigned int nSize; // [esp+18h] [ebp-4h] BYREF

  nSize = 0;
  D3DXShader::CCommentBlock::CCommentBlock(this: (D3DXShader::CCommentBlock *)v11, a2: 0x53455250u);
  v2 = D3DXShader::CProgram::Link(this);
  if ( v2 >= 0 )
  {
    v3 = (*(int (__thiscall **)(_DWORD, unsigned int *))(**((_DWORD **)this + 56) + 8))(
           a1: *((_DWORD *)this + 56),
           a2: &nSize);
    v2 = v3;
    if ( v3 >= 0 )
    {
      if ( v3 != 0
        || (v10 = nSize,
            v4 = (*(int (**)(void))(*(_DWORD *)nSize + 16))(),
            v5 = (const void *)(*(int (__stdcall **)(unsigned int, int))(*(_DWORD *)nSize + 12))(a1: nSize, a2: v4),
            (v2 = D3DXShader::CCommentBlock::Add(
                    this: (D3DXShader::CCommentBlock *)v11,
                    pMem: v5,
                    nSize: v10,
                    a4: 1u,
                    a5: nullptr)) >= 0) )
      {
        v6 = D3DXShader::CCommentBlock::SizeInDwords(this: (D3DXShader::CCommentBlock *)v11);
        v7 = v6;
        if ( v6 > 0x8000 )
        {
          D3DXShader::CProgram::Error(
            this,
            a2: nullptr,
            a3: 0x11C4u,
            format: "constant table info exceeds maximum comment size");
          v2 = -2147467259;
        }
        else
        {
          v2 = D3DXShader::CShaderProgram::Assure(this, a2: v6);
          if ( v2 >= 0 )
          {
            memmove(
              dst: (unsigned __int8 *)(*((_DWORD *)this + 67) + 4 * v7 + 4),
              src: (unsigned __int8 *)(*((_DWORD *)this + 67) + 4),
              count: 4 * *((_DWORD *)this + 68) - 4);
            v2 = D3DXShader::CCommentBlock::WriteComment(
                   this: (D3DXShader::CCommentBlock *)v11,
                   a2: (unsigned int *)(*((_DWORD *)this + 67) + 4),
                   a3: v7);
            if ( v2 >= 0 )
            {
              *((_DWORD *)this + 68) += v7;
              v8 = *((_DWORD *)this + 68);
              *((_DWORD *)this + 72) += v7;
              *((_DWORD *)this + 71) = v8;
              v2 = 0;
            }
          }
        }
      }
    }
  }
  if ( nSize != 0 )
  {
    (*(void (__stdcall **)(unsigned int))(*(_DWORD *)nSize + 8))(a1: nSize);
    nSize = 0;
  }
  D3DXShader::CCommentBlock::~CCommentBlock(this: (D3DXShader::CCommentBlock *)v11);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10222543
// Name: protected: long D3DXShader::CShaderProgram::EmitSymbolTable(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitSymbolTable(D3DXShader::CShaderProgram *this)
{
  unsigned int v2; // ecx
  int v3; // esi
  D3DXShader::CShaderProgram *v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // ecx
  bool v7; // zf
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // edi
  _DWORD *v12; // eax
  int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // ecx
  _DWORD *v18; // edi
  unsigned int v19; // edx
  unsigned int v20; // ecx
  _DWORD *v21; // edi
  int v22; // eax
  unsigned int v23; // ebx
  _DWORD *v24; // eax
  int v25; // ecx
  _DWORD *v26; // ecx
  _DWORD *v27; // esi
  int v28; // ecx
  int v29; // esi
  unsigned int v30; // ecx
  unsigned int v31; // esi
  int v32; // ecx
  int v33; // eax
  unsigned int v34; // eax
  _DWORD *v35; // edx
  int v36; // eax
  unsigned int v37; // ebx
  struct D3DXShader::CNode *v38; // edi
  unsigned int *v39; // ebx
  int v40; // eax
  int v41; // ecx
  _DWORD *v42; // edx
  const void *v43; // ecx
  unsigned int v44; // edx
  int v45; // eax
  int v46; // edx
  const char *v47; // eax
  unsigned int v48; // ecx
  int v49; // edx
  char *v50; // eax
  unsigned int v51; // esi
  unsigned int v52; // eax
  int v53; // ecx
  int v54; // eax
  __int16 v55; // ax
  _DWORD *v56; // ecx
  _DWORD *v57; // eax
  struct D3DXShader::CCommentBlock *v58; // eax
  int v59; // eax
  __int16 v60; // dx
  unsigned int v61; // esi
  _DWORD *v62; // ebx
  unsigned int v63; // esi
  _DWORD *v64; // eax
  _DWORD *v65; // edi
  int v66; // esi
  double *v67; // eax
  unsigned int v68; // esi
  float *v69; // edx
  _DWORD *v70; // edi
  int v71; // ebx
  double *v72; // eax
  double v73; // st7
  unsigned int v74; // esi
  unsigned int v75; // ecx
  char *v76; // esi
  _DWORD *v77; // edi
  int v78; // ecx
  double *v79; // eax
  D3DXShader::CShaderProgram *v80; // ebx
  unsigned int v81; // eax
  unsigned int v82; // edi
  int v83; // eax
  unsigned int v85; // [esp-4h] [ebp-190h]
  unsigned int *v86; // [esp+0h] [ebp-18Ch]
  void *v87[3]; // [esp+Ch] [ebp-180h] BYREF
  unsigned int v88[7]; // [esp+18h] [ebp-174h] BYREF
  unsigned int v89; // [esp+34h] [ebp-158h]
  _BYTE v90[16]; // [esp+38h] [ebp-154h] BYREF
  void *v91; // [esp+48h] [ebp-144h]
  void *v92; // [esp+4Ch] [ebp-140h]
  void *v93; // [esp+50h] [ebp-13Ch]
  unsigned int v94; // [esp+54h] [ebp-138h]
  D3DXShader::CShaderProgram *v95; // [esp+58h] [ebp-134h]
  void *pMem; // [esp+5Ch] [ebp-130h]
  void *v97; // [esp+60h] [ebp-12Ch]
  _DWORD *v98; // [esp+64h] [ebp-128h]
  unsigned int nSize; // [esp+68h] [ebp-124h]
  unsigned int v100; // [esp+6Ch] [ebp-120h]
  unsigned int v101; // [esp+70h] [ebp-11Ch]
  unsigned int *v102; // [esp+74h] [ebp-118h]
  struct D3DXShader::CNode *v103; // [esp+78h] [ebp-114h]
  void *v104; // [esp+7Ch] [ebp-110h]
  unsigned int i; // [esp+80h] [ebp-10Ch]
  unsigned int j; // [esp+84h] [ebp-108h]
  char string[256]; // [esp+88h] [ebp-104h] BYREF

  v85 = *((_DWORD *)this + 86) != 0 ? 1179535686 : 1111577667;
  v95 = this;
  D3DXShader::CCommentBlock::CCommentBlock(this: (D3DXShader::CCommentBlock *)v90, a2: v85);
  memset(v88, 0, sizeof(v88));
  v88[2] = *((_DWORD *)this + 50);
  v2 = *((_DWORD *)this + 51);
  v88[0] = 28;
  v88[5] = v2;
  pMem = nullptr;
  v104 = nullptr;
  v91 = nullptr;
  v93 = nullptr;
  v92 = nullptr;
  v97 = nullptr;
  v3 = D3DXShader::CCommentBlock::Add(
         this: (D3DXShader::CCommentBlock *)v90,
         pMem: v88,
         nSize: 0x1Cu,
         a4: 1u,
         a5: nullptr);
  if ( v3 < 0 )
    goto LABEL_161;
  v4 = v95;
  v5 = 0;
  v6 = 0;
  v7 = *((_DWORD *)v95 + 2) == 0;
  v102 = nullptr;
  j = 0;
  if ( !v7 )
  {
    v103 = *((struct D3DXShader::CNode **)v95 + 5);
    v101 = *((_DWORD *)v95 + 2);
    do
    {
      v8 = *(_DWORD *)v103;
      i = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v95 + 4) + 4 * *(_DWORD *)(*(_DWORD *)v103 + 4)) + 4);
      if ( (i & 0x200) != 0 && (i & 0x100) == 0 )
      {
        v9 = *(_DWORD *)(v8 + 12);
        if ( (i & 0x80u) == 0 )
        {
          if ( (i & 0x2000) != 0 )
          {
            if ( (unsigned int)v102 <= v9 )
              v102 = (unsigned int *)(v9 + 1);
          }
          else if ( (i & 0x40000) != 0 )
          {
            if ( j <= v9 )
              j = v9 + 1;
          }
          else if ( v6 <= v9 )
          {
            v6 = v9 + 1;
          }
        }
        else if ( v5 <= v9 )
        {
          v5 = v9 + 1;
        }
      }
      v103 = (struct D3DXShader::CNode *)((char *)v103 + 4);
      --v101;
    }
    while ( v101 != 0 );
  }
  nSize = (unsigned int)v102 + v6;
  v103 = (struct D3DXShader::CNode *)((char *)v102 + v5 + v6);
  v10 = (unsigned int)v102 + v6 + j + v5;
  v11 = 4 * v10;
  v104 = MemAlloc_Alloc(nSize: 4 * v10);
  if ( v104 == nullptr )
    goto LABEL_159;
  v97 = MemAlloc_Alloc(nSize: v11);
  if ( v97 == nullptr )
    goto LABEL_159;
  i = 0;
  memset(v104, 0, v11);
  if ( *((_DWORD *)v4 + 2) != 0 )
  {
    do
    {
      v12 = *(_DWORD **)(*((_DWORD *)v4 + 5) + 4 * i);
      if ( v12[24] != 0 && v12[2] == -1 )
      {
        v13 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v4 + 4) + 4 * v12[1]) + 4);
        if ( (v13 & 0x200) != 0 && (v13 & 0x100) == 0 )
        {
          if ( (v13 & 0x80u) == 0 )
          {
            if ( (v13 & 0x2000) != 0 )
            {
              v14 = 0;
            }
            else
            {
              v14 = (unsigned int)v103;
              if ( (v13 & 0x40000) == 0 )
                v14 = (unsigned int)v102;
            }
          }
          else
          {
            v14 = nSize;
          }
          v15 = v14 + v12[3];
          v16 = v15 - (v12[28] >> 2);
          v17 = v15 + 1;
          while ( v17 > v16 )
          {
            --v17;
            v18 = (char *)v104 + 4 * v17;
            if ( *v18 != 0 )
              break;
            *v18 = v12;
          }
        }
      }
      ++i;
    }
    while ( i < *((_DWORD *)v4 + 2) );
  }
  v19 = 0;
  v20 = 0;
  v101 = 0;
  if ( v10 != 0 )
  {
    do
    {
      v21 = v104;
      v22 = *((_DWORD *)v104 + v20);
      if ( v22 != 0 )
      {
        v23 = v101++;
        *((_DWORD *)v104 + v23) = v22;
      }
      ++v20;
    }
    while ( v20 < v10 );
  }
  else
  {
    v21 = v104;
  }
  v24 = nullptr;
  v100 = 0;
  if ( v101 != 0 )
  {
    do
    {
      if ( v24 == nullptr
        || *(_DWORD *)((v25 = v21[v19]) + 4) != v24[1]
        || *(_DWORD *)(v25 + 96) != v24[24]
        || *(_DWORD *)(v21[v19] + 12) - (*(_DWORD *)(v21[v19] + 112) >> 2) != v24[3] - (v24[28] >> 2) )
      {
        v24 = (_DWORD *)v21[v19];
        if ( v24 != nullptr )
        {
          v26 = (_DWORD *)v24[24];
          if ( v26[1] == 6 )
          {
            v27 = (_DWORD *)v26[5];
            if ( v27 != nullptr && v27[1] == 3 )
            {
              v28 = v26[6];
              if ( v28 != 0 && *(_DWORD *)(v28 + 4) == 11 && v27[4] == 9 && v27[6] != 0 )
              {
                v29 = v100++;
                *((_DWORD *)v97 + v29) = v19;
              }
            }
          }
        }
      }
      ++v19;
    }
    while ( v19 < v101 );
  }
  v30 = 0;
  for ( i = 0; v30 < v100; i = v30 )
  {
    j = *((_DWORD *)v97 + v30);
    v103 = (struct D3DXShader::CNode *)v21[j];
    v31 = 0;
    nSize = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v103 + 24) + 20) + 24);
    if ( v30 != 0 )
    {
      while ( 1 )
      {
        v32 = v21[*((_DWORD *)v97 + v31)];
        v33 = strcmp((const char *)nSize, *(const char **)(*(_DWORD *)(*(_DWORD *)(v32 + 96) + 20) + 24));
        if ( v33 < 0 || v33 <= 0 && *((_DWORD *)v103 + 1) < *(_DWORD *)(v32 + 4) )
          break;
        if ( ++v31 >= i )
          break;
        v21 = v104;
      }
      v30 = i;
      if ( i > v31 )
      {
        v34 = i;
        do
        {
          v35 = v97;
          *((_DWORD *)v97 + v34) = *((_DWORD *)v97 + v34 - 1);
          --v34;
        }
        while ( v34 > v31 );
        v35[v31] = j;
      }
      v21 = v104;
    }
    ++v30;
  }
  v36 = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)v95 + 140))(a1: v95);
  v37 = v100 + v36;
  if ( v100 + v36 == 0 )
  {
LABEL_151:
    v3 = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _BYTE *, void *, unsigned int))(*(_DWORD *)v95 + 144))(
           a1: v95,
           a2: v90,
           a3: pMem,
           a4: v100);
    if ( v3 >= 0 )
    {
      v80 = v95;
      memset(v87, 0, sizeof(v87));
      v3 = D3DXGetTargetDescByVersion(a1: *((_DWORD *)v95 + 66), a2: 0, a3: v87);
      if ( v3 >= 0 )
      {
        v3 = D3DXShader::CCommentBlock::Add(
               this: (D3DXShader::CCommentBlock *)v90,
               pMem: v87[0],
               nSize: 0xFFFFFFFF,
               a4: 5u,
               a5: &v88[6]);
        if ( v3 >= 0 )
        {
          v3 = D3DXShader::CCommentBlock::Add(
                 this: (D3DXShader::CCommentBlock *)v90,
                 pMem: "Microsoft (R) D3DX9 Shader Compiler 5.04.00.3900",
                 nSize: 0xFFFFFFFF,
                 a4: 5u,
                 a5: &v88[1]);
          if ( v3 >= 0 )
          {
            v81 = D3DXShader::CCommentBlock::SizeInDwords(this: (D3DXShader::CCommentBlock *)v90);
            v82 = v81;
            if ( v81 > 0x8000 )
            {
              D3DXShader::CProgram::Error(
                this: v80,
                a2: nullptr,
                a3: 0x11C4u,
                format: "constant table info exceeds maximum comment size");
              v3 = -2147467259;
            }
            else
            {
              v3 = D3DXShader::CShaderProgram::Assure(this: v80, a2: v81);
              if ( v3 >= 0 )
              {
                memmove(
                  dst: (unsigned __int8 *)(*((_DWORD *)v80 + 67) + 4 * v82 + 4),
                  src: (unsigned __int8 *)(*((_DWORD *)v80 + 67) + 4),
                  count: 4 * *((_DWORD *)v80 + 68) - 4);
                v3 = D3DXShader::CCommentBlock::WriteComment(
                       this: (D3DXShader::CCommentBlock *)v90,
                       a2: (unsigned int *)(*((_DWORD *)v80 + 67) + 4),
                       a3: v82);
                if ( v3 >= 0 )
                {
                  *((_DWORD *)v80 + 68) += v82;
                  v83 = *((_DWORD *)v80 + 68);
                  *((_DWORD *)v80 + 72) += v82;
                  *((_DWORD *)v80 + 71) = v83;
                  v3 = 0;
                }
              }
            }
          }
        }
      }
    }
    goto LABEL_161;
  }
  pMem = MemAlloc_Alloc(nSize: 20 * v37);
  if ( pMem == nullptr )
  {
LABEL_159:
    v3 = -2147024882;
    goto LABEL_161;
  }
  memset(pMem, 0, 4 * ((20 * v37) >> 2));
  v3 = D3DXShader::CCommentBlock::Add(
         this: (D3DXShader::CCommentBlock *)v90,
         pMem,
         nSize: 20 * v37,
         a4: 1u,
         a5: &v88[4]);
  if ( v3 < 0 )
    goto LABEL_161;
  i = 0;
  v88[3] = v37;
  if ( v100 == 0 )
    goto LABEL_151;
  v38 = (struct D3DXShader::CNode *)v97;
  v39 = (unsigned int *)((char *)pMem + 4);
  v103 = (struct D3DXShader::CNode *)v97;
  v102 = (unsigned int *)((char *)pMem + 4);
  while ( 1 )
  {
    v40 = *((_DWORD *)v104 + *(_DWORD *)v38);
    v41 = *(_DWORD *)(v40 + 96);
    v42 = *(_DWORD **)(v41 + 24);
    v43 = *(const void **)(*(_DWORD *)(v41 + 20) + 24);
    v98 = v42;
    v7 = *((_DWORD *)v95 + 86) == 0;
    v44 = *(_DWORD *)(*((_DWORD *)v95 + 4) + 4 * *(_DWORD *)(v40 + 4));
    v94 = v44;
    if ( v7 )
    {
      v45 = D3DXShader::CCommentBlock::Add(
              this: (D3DXShader::CCommentBlock *)v90,
              pMem: v43,
              nSize: 0xFFFFFFFF,
              a4: 7u,
              a5: v39 - 1);
    }
    else
    {
      v46 = *(_DWORD *)(v44 + 4);
      v47 = "c_%s";
      if ( (v46 & 0x2000) != 0 )
      {
        _snprintf(string, count: 0xFFu, format: "b_%s", v43);
      }
      else if ( (v46 & 0x40000) != 0 )
      {
        _snprintf(string, count: 0xFFu, format: "i_%s", v43);
      }
      else
      {
        if ( (v46 & 0x80u) != 0 )
          v47 = "s_%s";
        _snprintf(string, count: 0xFFu, format: v47, v43);
      }
      string[254] = 0;
      v45 = D3DXShader::CCommentBlock::Add(
              this: (D3DXShader::CCommentBlock *)v90,
              pMem: string,
              nSize: 0xFFFFFFFF,
              a4: 6u,
              a5: v39 - 1);
    }
    v3 = v45;
    if ( v45 < 0 )
      goto LABEL_161;
    v48 = *(_DWORD *)v38 + 1;
    v49 = 1;
    if ( v48 < v101 )
    {
      v50 = (char *)v104 + 4 * *(_DWORD *)v38;
      v51 = *(_DWORD *)(*(_DWORD *)v50 + 4);
      v52 = (unsigned int)(v50 + 4);
      v89 = v51;
      j = v48;
      nSize = v52;
      do
      {
        if ( v89 != *(_DWORD *)(*(_DWORD *)v52 + 4) )
          break;
        if ( *(_DWORD *)(*((_DWORD *)v104 + *(_DWORD *)v38) + 96) != *(_DWORD *)(*((_DWORD *)v104 + *(_DWORD *)v38 + v49)
                                                                               + 96) )
          break;
        v53 = *((_DWORD *)v104 + *(_DWORD *)v38 + v49);
        if ( *(_DWORD *)(*((_DWORD *)v104 + *(_DWORD *)v38) + 12)
           - (*(_DWORD *)(*((_DWORD *)v104 + *(_DWORD *)v38) + 112) >> 2) != *(_DWORD *)(v53 + 12)
                                                                           - (*(_DWORD *)(v53 + 112) >> 2) )
          break;
        v52 = nSize + 4;
        ++v49;
        ++j;
        nSize += 4;
      }
      while ( j < v101 );
    }
    v54 = *(_DWORD *)(v94 + 4);
    if ( (v54 & 0x80u) == 0 )
      v55 = (v54 & 0x2000) != 0 ? 0 : ((v54 & 0x40000) == 0) + 1;
    else
      v55 = 3;
    v56 = v104;
    *(_WORD *)v39 = v55;
    *((_WORD *)v39 + 1) = *(_WORD *)(v56[*(_DWORD *)v38] + 12) - (*(_DWORD *)(v56[*(_DWORD *)v38] + 112) >> 2);
    v57 = v98;
    *((_WORD *)v39 + 2) = v49;
    v58 = (struct D3DXShader::CCommentBlock *)v57[8];
    if ( v58 != nullptr )
    {
      v3 = D3DXShader::EmitTypeInfo(
             a1: v38,
             this: (D3DXShader *)v90,
             a3: v58,
             pMem: (struct D3DXShader::CNode *)1,
             a5: *(_DWORD *)(v56[*(_DWORD *)v38] + 60) & 0xE00000,
             a6: v39 + 2,
             a7: v86);
      if ( v3 < 0 )
        goto LABEL_161;
    }
    if ( v98[12] != 0 )
    {
      v3 = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD *, char *))(*(_DWORD *)v95 + 148))(
             a1: v95,
             a2: v98,
             a3: (char *)v39 - 4);
      if ( v3 < 0 )
        goto LABEL_161;
    }
    v59 = v98[13];
    if ( v59 != 0 )
    {
      v60 = *(_WORD *)v39;
      if ( *(_WORD *)v39 == 1 )
      {
        v61 = (v59 + 3) & 0xFFFFFFFC;
        nSize = 4 * v61;
        v92 = MemAlloc_Alloc(nSize: 4 * v61);
        if ( v92 == nullptr )
          goto LABEL_159;
        v62 = v92;
        memset(v92, 0, nSize);
        v63 = v61 >> 2;
        if ( v63 != 0 )
        {
          v64 = v62 + 2;
          do
          {
            *v64 = 1;
            v64 += 4;
            --v63;
          }
          while ( v63 != 0 );
        }
        v65 = v98;
        for ( j = 0; j < v65[13]; ++j )
        {
          v66 = j;
          v67 = *(double **)(4 * j + v65[14]);
          if ( v67 != nullptr )
          {
            if ( *(_DWORD *)v67 != 0 )
            {
              if ( *(_DWORD *)v67 == 1 || *(_DWORD *)v67 == 2 )
              {
                v62[v66] = *((_DWORD *)v67 + 2);
              }
              else if ( *(_DWORD *)v67 == 3 )
              {
                v65 = v98;
                v62[v66] = (__int64)v67[1];
              }
            }
            else
            {
              v62[v66] = *((_DWORD *)v67 + 2) != 0;
            }
          }
        }
        v3 = D3DXShader::CCommentBlock::Add(
               this: (D3DXShader::CCommentBlock *)v90,
               pMem: v62,
               nSize,
               a4: 0xBu,
               a5: v102 + 3);
        if ( v3 < 0 )
          goto LABEL_161;
        v92 = nullptr;
        goto LABEL_149;
      }
      if ( v60 == 2 )
      {
        v68 = 4 * ((v59 + 3) & 0xFFFFFFFC);
        v94 = v68;
        v91 = MemAlloc_Alloc(nSize: v68);
        if ( v91 == nullptr )
          goto LABEL_159;
        v69 = (float *)v91;
        memset(v91, 0, v68);
        v70 = v98;
        v71 = 0;
        if ( v98[13] != 0 )
        {
          while ( 2 )
          {
            v72 = *(double **)(4 * v71 + v70[14]);
            if ( v72 == nullptr )
              goto LABEL_135;
            if ( *(_DWORD *)v72 != 0 )
            {
              switch ( *(_DWORD *)v72 )
              {
                case 1:
                  v73 = (double)*((int *)v72 + 2);
                  break;
                case 2:
                  v89 = *((_DWORD *)v72 + 2);
                  v73 = (double)v89;
                  break;
                case 3:
                  v73 = v72[1];
                  break;
                default:
LABEL_135:
                  if ( (unsigned int)++v71 >= v70[13] )
                    goto LABEL_136;
                  continue;
              }
            }
            else if ( *((_DWORD *)v72 + 2) != 0 )
            {
              v73 = 1.0;
            }
            else
            {
              v73 = 0.0;
            }
            break;
          }
          v69[v71] = v73;
          goto LABEL_135;
        }
LABEL_136:
        v3 = D3DXShader::CCommentBlock::Add(
               this: (D3DXShader::CCommentBlock *)v90,
               pMem: v69,
               nSize: v94,
               a4: 0xBu,
               a5: v102 + 3);
        if ( v3 < 0 )
          goto LABEL_161;
        v91 = nullptr;
LABEL_149:
        v39 = v102;
        v38 = v103;
        goto LABEL_150;
      }
      if ( v60 == 0 )
        break;
    }
LABEL_150:
    ++i;
    v38 = (struct D3DXShader::CNode *)((char *)v38 + 4);
    v39 += 5;
    v103 = v38;
    v102 = v39;
    if ( i >= v100 )
      goto LABEL_151;
  }
  v94 = 4 * v98[5];
  v74 = v94;
  v93 = MemAlloc_Alloc(nSize: v94);
  if ( v93 == nullptr )
    goto LABEL_159;
  v75 = v74;
  v76 = (char *)v93;
  memset(v93, 0, v75);
  v77 = v98;
  v7 = v98[5] == 0;
  j = 0;
  if ( !v7 )
  {
    do
    {
      v78 = 4 * j;
      v79 = *(double **)(4 * j + v77[15]);
      if ( v79 != nullptr )
      {
        if ( *(_DWORD *)v79 <= 2u )
        {
          *(_DWORD *)&v76[v78] = *((_DWORD *)v79 + 2) != 0;
        }
        else if ( *(_DWORD *)v79 == 3 )
        {
          *(_DWORD *)&v76[v78] = v79[1] != 0.0;
        }
      }
      ++j;
    }
    while ( j < v77[5] );
  }
  v3 = D3DXShader::CCommentBlock::Add(
         this: (D3DXShader::CCommentBlock *)v90,
         pMem: v76,
         nSize: v94,
         a4: 0xBu,
         a5: v102 + 3);
  if ( v3 >= 0 )
  {
    v93 = nullptr;
    goto LABEL_149;
  }
LABEL_161:
  free(pMem);
  free(pMem: v104);
  free(pMem: v91);
  free(pMem: v93);
  free(pMem: v92);
  free(pMem: v97);
  D3DXShader::CCommentBlock::~CCommentBlock(this: (D3DXShader::CCommentBlock *)v90);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102230F0
// Name: protected: long D3DXShader::CShaderProgram::EmitDebugInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CShaderProgram::EmitDebugInfo(D3DXShader::CShaderProgram *this)
{
  int v2; // esi
  void *v3; // edi
  char *v4; // edi
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  bool v8; // zf
  int v9; // eax
  unsigned int *v10; // edx
  int v11; // eax
  const void *v12; // eax
  unsigned int v13; // eax
  int (__stdcall *v14)(unsigned int, unsigned int, const void *); // esi
  unsigned int v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  unsigned int v18; // edx
  _DWORD *v19; // esi
  _DWORD *v20; // eax
  struct D3DXShader::CNode *v21; // edi
  const void *v22; // ecx
  const void *v23; // ecx
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  unsigned int *v28; // eax
  unsigned int v29; // eax
  int v30; // eax
  unsigned int v31; // ecx
  _WORD *v32; // edx
  _DWORD *v33; // edi
  unsigned int j; // eax
  _DWORD *v35; // ecx
  int v36; // eax
  int v37; // ecx
  unsigned int *v38; // eax
  const void *v39; // eax
  const void *v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // edi
  unsigned int v43; // ecx
  _DWORD *v44; // eax
  int v45; // eax
  const void *v47; // [esp+0h] [ebp-78h]
  unsigned int *v48; // [esp+0h] [ebp-78h]
  unsigned int v49[10]; // [esp+Ch] [ebp-6Ch] BYREF
  _BYTE v50[16]; // [esp+34h] [ebp-44h] BYREF
  unsigned int v51; // [esp+44h] [ebp-34h]
  unsigned int nSize; // [esp+48h] [ebp-30h]
  unsigned int v53; // [esp+4Ch] [ebp-2Ch] BYREF
  unsigned int i; // [esp+50h] [ebp-28h]
  int v55; // [esp+54h] [ebp-24h]
  void *v56; // [esp+58h] [ebp-20h]
  void *pMem; // [esp+5Ch] [ebp-1Ch]
  void *v58; // [esp+60h] [ebp-18h]
  void *v59; // [esp+64h] [ebp-14h]
  int (__stdcall *v60)(unsigned int, unsigned int, const void *); // [esp+68h] [ebp-10h]
  unsigned int v61; // [esp+6Ch] [ebp-Ch]
  unsigned int v62; // [esp+70h] [ebp-8h]
  unsigned int *v63; // [esp+74h] [ebp-4h]

  D3DXShader::CCommentBlock::CCommentBlock(this: (D3DXShader::CCommentBlock *)v50, a2: 0x47554244u);
  v2 = 0;
  memset(v49, 0, sizeof(v49));
  v49[0] = 40;
  pMem = nullptr;
  v59 = nullptr;
  v56 = nullptr;
  v58 = nullptr;
  v60 = nullptr;
  v63 = nullptr;
  v61 = D3DXShader::CCommentBlock::Add(
          this: (D3DXShader::CCommentBlock *)v50,
          pMem: v49,
          nSize: 0x28u,
          a4: 1u,
          a5: nullptr);
  if ( (v61 & 0x80000000) != 0 )
    goto LABEL_82;
  v49[5] = *((_DWORD *)this + 74);
  if ( v49[5] == 0 )
    goto LABEL_66;
  v3 = MemAlloc_Alloc(nSize: 4 * v49[5]);
  pMem = v3;
  if ( v3 == nullptr
    || (memset(v3, 0, 4 * v49[5]), (v59 = MemAlloc_Alloc(nSize: 8 * v49[5])) == nullptr)
    || (nSize = 8 * v49[5],
        memset(v59, 0, 8 * v49[5]),
        (v60 = (int (__stdcall *)(unsigned int, unsigned int, const void *))MemAlloc_Alloc(nSize: 16 * v49[5])) == nullptr) )
  {
LABEL_79:
    v61 = -2147024882;
    goto LABEL_82;
  }
  memset(v60, 0, 16 * v49[5]);
  v62 = 0;
  if ( v49[5] != 0 )
  {
    v4 = (char *)v59 + 2;
    do
    {
      *(_WORD *)v4 = -1;
      *((_WORD *)v4 - 1) = 0;
      v5 = v2 + 8;
      *(_DWORD *)(v4 + 2) = *(_DWORD *)(*((_DWORD *)this + 73) + v2 + 4);
      i = v2 + 8;
      v55 = 4;
      do
      {
        v6 = *(_DWORD *)(v5 + *((_DWORD *)this + 73));
        if ( v6 != -1 )
        {
          v7 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v6);
          v8 = *(_DWORD *)(v7 + 96) == 0;
          *(_DWORD *)(v7 + 116) = v62;
          if ( !v8 )
          {
            v9 = *(_DWORD *)(v5 + *((_DWORD *)this + 73));
            v10 = v63;
            v63 = (unsigned int *)((char *)v63 + 1);
            *((_DWORD *)v60 + (_DWORD)v10) = v9;
            v5 = i;
          }
        }
        v5 += 4;
        v8 = v55-- == 1;
        i = v5;
      }
      while ( !v8 );
      v11 = *(_DWORD *)(v2 + *((_DWORD *)this + 73));
      if ( v11 != 0 )
      {
        *((_WORD *)v4 - 1) = *(_WORD *)(v11 + 20);
        v12 = *(const void **)(*(_DWORD *)(*((_DWORD *)this + 73) + v2) + 16);
        if ( v12 != nullptr )
        {
          if ( D3DXShader::CCommentBlock::Add(
                 this: (D3DXShader::CCommentBlock *)v50,
                 pMem: v12,
                 nSize: 0xFFFFFFFF,
                 a4: 7u,
                 a5: &v53) < 0 )
            goto LABEL_82;
          v13 = 0;
          for ( i = 0; v13 < v49[3]; i = ++v13 )
          {
            if ( *((_DWORD *)pMem + v13) == v53 )
              break;
          }
          if ( v13 == v49[3] )
          {
            *((_DWORD *)pMem + v49[3]++) = v53;
            LOWORD(v13) = i;
          }
          *(_WORD *)v4 = v13;
        }
      }
      ++v62;
      v2 += 24;
      v4 += 8;
    }
    while ( v62 < v49[5] );
  }
  if ( v49[3] == 0
    || ((v61 = D3DXShader::CCommentBlock::Add(
                 this: (D3DXShader::CCommentBlock *)v50,
                 pMem,
                 nSize: 4 * v49[3],
                 a4: 1u,
                 a5: &v49[4]))
      & 0x80000000) == 0 )
  {
    v61 = D3DXShader::CCommentBlock::Add(this: (D3DXShader::CCommentBlock *)v50, pMem: v59, nSize, a4: 1u, a5: &v49[6]);
    if ( (v61 & 0x80000000) == 0 )
    {
      if ( v63 == nullptr )
        goto LABEL_66;
      v14 = v60;
      D3DXShader::HeapSort(this: (D3DXShader *)sub_10214060, a2: v60, a3: v63, a4: (unsigned int)this, a5: v47);
      v15 = 1;
      v49[7] = 1;
      v16 = 1;
      if ( (unsigned int)v63 > 1 )
      {
        v17 = *((_DWORD *)this + 5);
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(v17 + 4 * *((_DWORD *)v14 + v16 - 1)) + 96) != *(_DWORD *)(*(_DWORD *)(v17 + 4 * *((_DWORD *)v14 + v16))
                                                                                                + 96) )
            ++v49[7];
          ++v16;
        }
        while ( v16 < (unsigned int)v63 );
        v15 = v49[7];
      }
      v56 = MemAlloc_Alloc(nSize: 20 * v15);
      if ( v56 != nullptr )
      {
        v18 = 20 * v49[7];
        memset(v56, 0, 20 * v49[7]);
        v51 = v18;
        v62 = 0;
        i = 0;
        if ( v49[7] != 0 )
        {
          v19 = (char *)v56 + 12;
          while ( 1 )
          {
            v20 = (_DWORD *)((char *)v60 + 4 * v62);
            v21 = *(struct D3DXShader::CNode **)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v20) + 96);
            v22 = *((const void **)v21 + 8);
            v55 = (int)v20;
            v53 = (unsigned int)v21;
            if ( v22 != nullptr )
            {
              v61 = D3DXShader::CCommentBlock::Add(
                      this: (D3DXShader::CCommentBlock *)v50,
                      pMem: v22,
                      nSize: 0xFFFFFFFF,
                      a4: 7u,
                      a5: v19 - 3);
              if ( (v61 & 0x80000000) != 0 )
                goto LABEL_82;
              v20 = (_DWORD *)v55;
            }
            v23 = *(const void **)(*((_DWORD *)v21 + 5) + 24);
            if ( v23 != nullptr )
            {
              v61 = D3DXShader::CCommentBlock::Add(
                      this: (D3DXShader::CCommentBlock *)v50,
                      pMem: v23,
                      nSize: 0xFFFFFFFF,
                      a4: 7u,
                      a5: v19 - 2);
              if ( (v61 & 0x80000000) != 0 )
                goto LABEL_82;
              v20 = (_DWORD *)v55;
            }
            v24 = *((_DWORD *)v21 + 4);
            if ( v24 == 1 || v24 == 2 )
            {
              v61 = D3DXShader::EmitTypeInfo(
                      a1: v21,
                      this: (D3DXShader *)v50,
                      a3: *(struct D3DXShader::CCommentBlock **)(*((_DWORD *)v21 + 6) + 32),
                      pMem: (struct D3DXShader::CNode *)1,
                      a5: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v20) + 60) & 0xE00000,
                      a6: v19 - 1,
                      a7: v48);
              if ( (v61 & 0x80000000) != 0 )
                goto LABEL_82;
            }
            v55 = v62;
            if ( v62 < (unsigned int)v63 )
            {
              do
              {
                v25 = *((_DWORD *)this + 5);
                v26 = *(_DWORD *)(v25 + 4 * *((_DWORD *)v60 + v62));
                if ( v21 != *(struct D3DXShader::CNode **)(v26 + 96) )
                  break;
                nSize = *(_DWORD *)(v26 + 116);
                while ( v62 < (unsigned int)v63 )
                {
                  v27 = *(_DWORD *)(v25 + 4 * *((_DWORD *)v60 + v62));
                  if ( v21 != *(struct D3DXShader::CNode **)(v27 + 96) || nSize != *(_DWORD *)(v27 + 116) )
                    break;
                  ++v62;
                }
                v28 = v63;
                ++*v19;
              }
              while ( v62 < (unsigned int)v28 );
            }
            v58 = MemAlloc_Alloc(nSize: 12 * *v19);
            if ( v58 == nullptr )
              goto LABEL_79;
            v61 = 12 * *v19;
            memset(v58, 0, v61);
            v29 = v55;
            *v19 = 0;
            v62 = v29;
            if ( v29 < (unsigned int)v63 )
            {
              do
              {
                v30 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *((_DWORD *)v60 + v62));
                if ( v53 != *(_DWORD *)(v30 + 96) )
                  break;
                v31 = *(_DWORD *)(v30 + 116);
                v32 = v58;
                *((_DWORD *)v58 + 3 * *v19) = v31;
                nSize = v31;
                v33 = &v32[6 * *v19 + 2];
                *v33 = -1;
                v33[1] = -1;
                for ( j = v62; j < (unsigned int)v63; j = ++v62 )
                {
                  v35 = (_DWORD *)((char *)v60 + 4 * j);
                  v36 = *((_DWORD *)this + 5);
                  v55 = (int)v35;
                  v37 = *(_DWORD *)(v36 + 4 * *v35);
                  if ( v53 != *(_DWORD *)(v37 + 96) || nSize != *(_DWORD *)(v37 + 116) )
                    break;
                  v32[6 * *v19 + 2 + *(_DWORD *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)v55) + 16)] = *(_WORD *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)v55) + 100);
                }
                v38 = v63;
                ++*v19;
              }
              while ( v62 < (unsigned int)v38 );
            }
            v61 = D3DXShader::CCommentBlock::Add(
                    this: (D3DXShader::CCommentBlock *)v50,
                    pMem: v58,
                    nSize: v61,
                    a4: 0xBu,
                    a5: v19 + 1);
            if ( (v61 & 0x80000000) != 0 )
              goto LABEL_82;
            v58 = nullptr;
            ++i;
            v19 += 5;
            if ( i >= v49[7] )
            {
              v18 = v51;
              break;
            }
          }
        }
        v61 = D3DXShader::CCommentBlock::Add(
                this: (D3DXShader::CCommentBlock *)v50,
                pMem: v56,
                nSize: v18,
                a4: 1u,
                a5: &v49[8]);
        if ( (v61 & 0x80000000) != 0 )
          goto LABEL_82;
LABEL_66:
        v39 = *((const void **)this + 52);
        if ( v39 != nullptr )
        {
          v61 = D3DXShader::CCommentBlock::Add(
                  this: (D3DXShader::CCommentBlock *)v50,
                  pMem: v39,
                  nSize: 0xFFFFFFFF,
                  a4: 7u,
                  a5: &v49[9]);
          if ( (v61 & 0x80000000) != 0 )
            goto LABEL_82;
        }
        v40 = *((const void **)this + 76);
        if ( v40 != nullptr
          && (D3DXShader::CCommentBlock::Add(
                this: (D3DXShader::CCommentBlock *)v50,
                pMem: v40,
                nSize: *((_DWORD *)this + 77),
                a4: 5u,
                a5: &v49[2]) < 0
           || D3DXShader::CCommentBlock::Add(
                this: (D3DXShader::CCommentBlock *)v50,
                pMem: &::pMem,
                nSize: 1u,
                a4: 5u,
                a5: nullptr) < 0) )
        {
          goto LABEL_82;
        }
        if ( D3DXShader::CCommentBlock::Add(
               this: (D3DXShader::CCommentBlock *)v50,
               pMem: "Microsoft (R) D3DX9 Shader Compiler 5.04.00.3900",
               nSize: 0xFFFFFFFF,
               a4: 5u,
               a5: &v49[1]) < 0 )
          goto LABEL_82;
        v41 = D3DXShader::CCommentBlock::SizeInDwords(this: (D3DXShader::CCommentBlock *)v50);
        v42 = v41;
        if ( v41 > 0x8000 )
        {
          D3DXShader::CProgram::Warning(
            this,
            a2: nullptr,
            a3: 0x11C3u,
            format: "debug info exceeds maximum comment size; no debug info emitted");
        }
        else
        {
          v61 = D3DXShader::CShaderProgram::Assure(this, a2: v41);
          if ( (v61 & 0x80000000) != 0 )
            goto LABEL_82;
          memmove(
            dst: (unsigned __int8 *)(*((_DWORD *)this + 67) + 4 * v42 + 4),
            src: (unsigned __int8 *)(*((_DWORD *)this + 67) + 4),
            count: 4 * *((_DWORD *)this + 68) - 4);
          v43 = 0;
          if ( v49[5] != 0 )
          {
            v44 = (char *)v59 + 4;
            do
            {
              *v44 += 4 * (v42 + *((_DWORD *)this + 72));
              ++v43;
              v44 += 2;
            }
            while ( v43 < v49[5] );
          }
          v61 = D3DXShader::CCommentBlock::WriteComment(
                  this: (D3DXShader::CCommentBlock *)v50,
                  a2: (unsigned int *)(*((_DWORD *)this + 67) + 4),
                  a3: v42);
          if ( (v61 & 0x80000000) != 0 )
            goto LABEL_82;
          *((_DWORD *)this + 68) += v42;
          v45 = *((_DWORD *)this + 68);
          *((_DWORD *)this + 72) += v42;
          *((_DWORD *)this + 71) = v45;
        }
        v61 = 0;
        goto LABEL_82;
      }
      goto LABEL_79;
    }
  }
LABEL_82:
  free(pMem);
  free(pMem: v59);
  free(pMem: v56);
  free(pMem: v58);
  free(pMem: v60);
  D3DXShader::CCommentBlock::~CCommentBlock(this: (D3DXShader::CCommentBlock *)v50);
  return v61;
}

//------------------------------------------------------------------------------
// Address: 0x10223774
// Name: protected: struct D3DXShader::D3DX_SEMANTIC __near * D3DXShader::CShaderProgram::FindSemantic(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::D3DX_SEMANTIC *__thiscall D3DXShader::CShaderProgram::FindSemantic(
        struct D3DXShader::D3DX_SEMANTIC **this,
        struct D3DXShader::D3DX_SEMANTIC *a2)
{
  D3DXShader::CShaderProgram *v2; // edx
  struct D3DXShader::D3DX_SEMANTIC *result; // eax
  unsigned int i; // esi
  struct D3DXShader::D3DX_SEMANTIC *v5; // ecx
  struct D3DXShader::D3DX_SEMANTIC *v6[3]; // [esp+4h] [ebp-Ch]

  v2 = (D3DXShader::CShaderProgram *)this;
  v6[0] = *(this + 61);
  v6[1] = *(this + 60);
  v6[2] = *(this + 62);
  result = a2;
  for ( i = 0; i < 3; ++i )
  {
    v5 = v6[i];
    if ( v5 != nullptr )
    {
      result = D3DXShader::CShaderProgram::FindSemantic(this: v2, a2: v5, a3: (unsigned int)a2);
      if ( *((_DWORD *)result + 4) != -1 )
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102237E4
// Name: public: virtual long D3DXShader::CShaderProgram::GenerateCode(struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::GenerateCode(D3DXShader::CShaderProgram *this, struct ID3DXBuffer **a2)
{
  signed int Code; // edi
  unsigned int v4; // eax
  int v5; // eax
  HMODULE ModuleHandleA; // eax
  int (*Direct3DShaderValidatorCreate9)(void); // eax
  int v8; // eax
  void *v9; // eax
  int v10; // eax
  unsigned int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // edi
  int v15; // ecx
  int *v16; // edi
  int v17; // eax
  int v18; // ecx
  unsigned int v19; // eax
  int v20; // edx
  _DWORD *v21; // eax
  int v22; // ecx
  _DWORD *v23; // edi
  _DWORD *v24; // edx
  unsigned int i; // eax
  int v26; // ecx
  _DWORD *v27; // edx
  unsigned int j; // esi
  int v29; // eax
  int v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // edi
  unsigned int *v33; // esi
  unsigned int v34; // eax
  int v35; // esi
  int v36; // eax
  int v37; // eax
  int v38; // edi
  int v39; // edx
  int v40; // ecx
  unsigned int v41; // edi
  unsigned int v42; // esi
  unsigned int v43; // ecx
  _DWORD *v44; // esi
  unsigned int m; // edi
  int v46; // eax
  int v47; // ecx
  unsigned int n; // ecx
  int v49; // edx
  int v50; // esi
  int v51; // edx
  int v52; // ecx
  int v53; // edi
  void *v54; // esi
  unsigned int v55; // edi
  unsigned int v56; // esi
  int v57; // edi
  int v58; // eax
  unsigned int v59; // esi
  bool v60; // zf
  int v61; // eax
  int v62; // esi
  _DWORD *v63; // edi
  unsigned int v64; // esi
  _DWORD *v65; // edi
  _DWORD *v66; // edi
  int v67; // ecx
  unsigned int v68; // esi
  _DWORD *v69; // eax
  int v70; // eax
  const void *v71; // esi
  void *v72; // edi
  _DWORD *v73; // ebx
  const char *v75; // [esp+20h] [ebp-58h]
  const char *v76; // [esp+30h] [ebp-48h] BYREF
  void *v77; // [esp+3Ch] [ebp-3Ch]
  struct D3DXCore::CBuffer *k; // [esp+40h] [ebp-38h] BYREF
  void *v79; // [esp+44h] [ebp-34h]
  void *v80; // [esp+48h] [ebp-30h]
  void *v81; // [esp+4Ch] [ebp-2Ch]
  void *v82; // [esp+50h] [ebp-28h]
  unsigned int v83; // [esp+54h] [ebp-24h]
  void *v84; // [esp+58h] [ebp-20h]
  void *v85; // [esp+5Ch] [ebp-1Ch]
  void *pMem; // [esp+60h] [ebp-18h]
  void *v87; // [esp+64h] [ebp-14h]
  unsigned int v88; // [esp+68h] [ebp-10h]
  unsigned int v89; // [esp+6Ch] [ebp-Ch]
  unsigned int v90; // [esp+70h] [ebp-8h]
  unsigned int nSize; // [esp+74h] [ebp-4h]

  *((_DWORD *)this + 65) = 0;
  v88 = 0;
  v89 = 0;
  k = nullptr;
  v83 = 0;
  v79 = nullptr;
  v84 = nullptr;
  pMem = nullptr;
  v87 = nullptr;
  v81 = nullptr;
  v77 = nullptr;
  v85 = nullptr;
  v82 = nullptr;
  v80 = nullptr;
  Code = D3DXShader::CProgram::GenerateCode(this, a2);
  if ( Code < 0 )
    goto LABEL_212;
  v4 = D3DXShader::CBaseProgram::AddPool(this, a2: "i", a3: 0x40311u, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 97) = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  if ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 160))(a1: this) != 0 )
    goto LABEL_186;
  v5 = *((_DWORD *)this + 108);
  *((_DWORD *)this + 67) = 0;
  *((_DWORD *)this + 68) = 0;
  *((_DWORD *)this + 69) = 0;
  *((_DWORD *)this + 71) = 0;
  *((_DWORD *)this + 72) = 0;
  if ( v5 != 0 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    *((_DWORD *)this + 108) = 0;
  }
  if ( (*((_BYTE *)this + 204) & 2) == 0 )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "d3d9.dll");
    if ( ModuleHandleA != nullptr || (ModuleHandleA = LoadLibraryA(lpLibFileName: "d3d9.dll")) != nullptr )
    {
      Direct3DShaderValidatorCreate9 = GetProcAddress(
                                         hModule: ModuleHandleA,
                                         lpProcName: "Direct3DShaderValidatorCreate9");
      if ( Direct3DShaderValidatorCreate9 != nullptr )
      {
        v8 = Direct3DShaderValidatorCreate9();
        *((_DWORD *)this + 108) = v8;
        if ( v8 != 0 )
        {
          Code = (*(int (__stdcall **)(int, int (__stdcall *)(const char *, unsigned int, __int16, unsigned int, const char *, void *), D3DXShader::CShaderProgram *, int))(*(_DWORD *)v8 + 12))(
                   a1: v8,
                   a2: D3DXShader::CShaderProgram::ValidationError,
                   a3: this,
                   a4: 1);
          if ( Code < 0 )
            goto LABEL_212;
        }
      }
    }
  }
  if ( (*((_BYTE *)this + 204) & 1) != 0 )
  {
    v9 = MemAlloc_Alloc(nSize: 48 * *((_DWORD *)this + 3));
    *((_DWORD *)this + 73) = v9;
    if ( v9 == nullptr )
      goto LABEL_3;
    v10 = 2 * *((_DWORD *)this + 3);
    *((_DWORD *)this + 74) = 0;
    *((_DWORD *)this + 75) = v10;
  }
  *((_DWORD *)this + 78) = -1;
  v11 = 0;
  v60 = *((_DWORD *)this + 2) == 0;
  *((_DWORD *)this + 83) = 0;
  if ( !v60 )
  {
    do
    {
      v12 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v11++);
      *(_DWORD *)(v12 + 48) = 0;
    }
    while ( v11 < *((_DWORD *)this + 2) );
  }
  v60 = *((_DWORD *)this + 2) == 0;
  nSize = 0;
  v90 = 0;
  if ( !v60 )
  {
    do
    {
      v13 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v90);
      v14 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v13 + 4));
      v15 = *(_DWORD *)(v14 + 4);
      if ( (v15 & 0x10) != 0 && (v15 & 0x200) == 0 || (v15 & 0x20) != 0 )
        (*(void (__thiscall **)(D3DXShader::CShaderProgram *, int, _DWORD))(*(_DWORD *)this + 4))(
          a1: this,
          a2: v13,
          a3: 0);
      if ( *(char *)(v14 + 4) < 0 )
        ++nSize;
      ++v90;
    }
    while ( v90 < *((_DWORD *)this + 2) );
  }
  if ( nSize > *((_DWORD *)this + 19) )
  {
    if ( (int)D3DXGetTargetDescByVersion(a1: *((_DWORD *)this + 50), a2: 0, a3: &v76) >= 0 )
    {
      if ( *((_DWORD *)this + 19) != 0 )
        D3DXShader::CProgram::Error(
          this,
          a2: nullptr,
          a3: 0x119Eu,
          format: "maximum number of samplers exceeded. %s target can have a maximum of %i samplers",
          v76,
          *((_DWORD *)this + 19));
      else
        D3DXShader::CProgram::Error(
          this,
          a2: nullptr,
          a3: 0x11C1u,
          format: "%s target does not support texture lookups",
          v76);
    }
    goto LABEL_186;
  }
  if ( (*((_DWORD *)this + 50) & 0xFFFF0000) == 0xFFFE0000 )
  {
    Code = D3DXShader::CShaderProgram::CombineConstants(
             this,
             a2: *((_DWORD *)this + 32),
             a3: *((_DWORD *)this + 10),
             a4: 0x10u,
             a5: 0x204u,
             a6: 118);
    if ( Code < 0 )
      goto LABEL_212;
  }
  if ( (*((_DWORD *)this + 50) & 0xFFFF0000) == 0xFFFF0000 )
  {
    Code = D3DXShader::CShaderProgram::CombineConstants(
             this,
             a2: 0xFFFFFFFF,
             a3: *((_DWORD *)this + 19),
             a4: 0x80u,
             a5: 0,
             a6: 115);
    if ( Code < 0 )
      goto LABEL_212;
  }
  if ( *((_DWORD *)this + 2) != 0 )
  {
    v16 = *((int **)this + 5);
    pMem = *((void **)this + 2);
    do
    {
      v17 = *v16;
      v18 = *(_DWORD *)(*v16 + 4);
      if ( *((_DWORD *)this + 34) == v18 && *(_DWORD *)(v17 + 12) + 1 > (unsigned int)k )
      {
        k = (struct D3DXCore::CBuffer *)(*(_DWORD *)(v17 + 12) + 1);
      }
      else if ( *((_DWORD *)this + 32) == v18 && *(_DWORD *)(v17 + 12) + 1 > v88 )
      {
        v88 = *(_DWORD *)(v17 + 12) + 1;
      }
      else if ( *((_DWORD *)this + 33) == v18 && *(_DWORD *)(v17 + 12) + 1 > v89 )
      {
        v89 = *(_DWORD *)(v17 + 12) + 1;
      }
      else if ( *(char *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v18) + 4) < 0 )
      {
        v19 = *(_DWORD *)(v17 + 12) + 1;
        if ( v19 > v83 )
          v83 = v19;
      }
      ++v16;
      pMem = (char *)pMem - 1;
    }
    while ( pMem != nullptr );
  }
  nSize = 4 * v88;
  pMem = MemAlloc_Alloc(nSize: 4 * v88);
  if ( pMem == nullptr )
    goto LABEL_3;
  k = (struct D3DXCore::CBuffer *)(4 * v89);
  v87 = MemAlloc_Alloc(nSize: 4 * v89);
  if ( v87 == nullptr )
    goto LABEL_3;
  v90 = 4 * v83;
  v81 = MemAlloc_Alloc(nSize: 4 * v83);
  if ( v81 == nullptr )
    goto LABEL_3;
  v77 = MemAlloc_Alloc(nSize);
  if ( v77 == nullptr )
    goto LABEL_3;
  v85 = MemAlloc_Alloc(nSize: 4 * v89);
  if ( v85 == nullptr )
    goto LABEL_3;
  memset(pMem, 0, nSize);
  memset(v87, 0, (unsigned int)k);
  memset(v81, 0, v90);
  v20 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    while ( 1 )
    {
      v21 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v20);
      v22 = v21[1];
      if ( *((_DWORD *)this + 33) == v22 )
        break;
      if ( *((_DWORD *)this + 32) == v22 )
      {
        if ( v21[27] == -1 )
        {
          v75 = "internal error: input register missing semantic";
LABEL_101:
          D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0, format: v75);
LABEL_186:
          Code = -2147467259;
          goto LABEL_212;
        }
        v23 = pMem;
        goto LABEL_64;
      }
      if ( *(char *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v22) + 4) < 0 )
      {
        v23 = v81;
LABEL_64:
        v23[v21[3]] = v21;
      }
      if ( (unsigned int)++v20 >= *((_DWORD *)this + 2) )
        goto LABEL_66;
    }
    if ( v21[27] == -1 )
    {
      v75 = "internal error: output register missing semantic";
      goto LABEL_101;
    }
    v23 = v87;
    goto LABEL_64;
  }
LABEL_66:
  v60 = *((_DWORD *)this + 2) == 0;
  v90 = 0;
  if ( !v60 )
  {
    do
    {
      v24 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v90);
      if ( *((_DWORD *)this + 32) == v24[1] )
      {
        for ( i = 0; i < v88; ++i )
        {
          v26 = *((_DWORD *)pMem + i);
          if ( v26 != 0 && v24[27] == *(_DWORD *)(v26 + 108) )
            v24[3] = i;
        }
      }
      ++v90;
    }
    while ( v90 < *((_DWORD *)this + 2) );
  }
  v27 = pMem;
  memset(pMem, 0, nSize);
  for ( j = 0; j < *((_DWORD *)this + 2); ++j )
  {
    v29 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * j);
    v30 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v29 + 4)) + 4);
    if ( (v30 & 0x10) != 0 && (v30 & 0x204) == 0 )
      v27[*(_DWORD *)(v29 + 12)] = v29;
  }
  v31 = 0;
  for ( k = nullptr; v31 < v88; ++v31 )
  {
    if ( v27[v31] != 0 )
      k = (struct D3DXCore::CBuffer *)((char *)k + 1);
  }
  Code = D3DXShader::CShaderProgram::PortConstraints(this);
  if ( Code < 0 )
    goto LABEL_212;
  Code = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 44))(a1: this);
  if ( Code < 0 )
    goto LABEL_212;
  if ( (*((_BYTE *)this + 204) & 4) == 0 || (*((_BYTE *)this + 110) & 0x20) != 0 )
  {
    Code = D3DXShader::CShaderProgram::Reset(this);
    if ( Code < 0 )
      goto LABEL_212;
    Code = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 40))(a1: this);
    if ( Code < 0 )
      goto LABEL_212;
  }
  if ( *((_DWORD *)this + 99) != 0 )
  {
    v90 = D3DXShader::CBaseProgram::AddPool(this, a2: "l", a3: 0x351u, a4: 0xFFFFFFFF, a5: 4u);
    if ( v90 != -1 )
    {
      v32 = 0;
      v33 = (unsigned int *)((char *)this + 400);
      while ( 1 )
      {
        v34 = D3DXShader::CBaseProgram::AddArgument(this, a2: v90, a3: v32 >> 2, a4: v32 & 3, a5: dbl_102BF420[v32]);
        *v33 = v34;
        if ( v34 == -1 )
          break;
        ++v32;
        ++v33;
        if ( v32 >= 8 )
          goto LABEL_94;
      }
    }
    goto LABEL_3;
  }
LABEL_94:
  Code = D3DXShader::CShaderProgram::CombineConstants(
           this,
           a2: *((_DWORD *)this + 31),
           a3: *((_DWORD *)this + 14),
           a4: 0x200u,
           a5: 0x42080u,
           a6: 99);
  if ( Code < 0 )
    goto LABEL_212;
  Code = D3DXShader::CShaderProgram::CombineConstants(
           this,
           a2: *((_DWORD *)this + 39),
           a3: *((_DWORD *)this + 24),
           a4: 0x2200u,
           a5: 0x80u,
           a6: 98);
  if ( Code < 0 )
    goto LABEL_212;
  Code = D3DXShader::CShaderProgram::CombineConstants(
           this,
           a2: *((_DWORD *)this + 44),
           a3: *((_DWORD *)this + 16),
           a4: 0x40200u,
           a5: 0x80u,
           a6: 105);
  if ( Code < 0 )
    goto LABEL_212;
  v35 = 0;
  v60 = *((_DWORD *)this + 3) == 0;
  *((_DWORD *)this + 65) = 0;
  v36 = v60 ? 0 : **((_DWORD **)this + 6);
  *((_DWORD *)this + 64) = v36;
  v37 = *(_DWORD *)this;
  *((_DWORD *)this + 63) = 0;
  Code = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(v37 + 56))(a1: this);
  if ( Code < 0 )
    goto LABEL_212;
  nSize = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    v38 = *((_DWORD *)this + 4);
    v39 = *((_DWORD *)this + 5);
    v82 = *((void **)this + 2);
    do
    {
      v40 = *(_DWORD *)(*(_DWORD *)(v38 + 4 * *(_DWORD *)(*(_DWORD *)v39 + 4)) + 4);
      if ( (v40 & 0x100) != 0
        && *(_DWORD *)(*(_DWORD *)v39 + 8) == -1
        && ((v40 & 0x800) == 0 || *((_DWORD *)this + 86) != 0) )
      {
        ++v35;
      }
      v39 += 4;
      v82 = (char *)v82 - 1;
    }
    while ( v82 != nullptr );
  }
  v41 = 16 * v35;
  v82 = MemAlloc_Alloc(nSize: 16 * v35);
  if ( v82 == nullptr )
    goto LABEL_3;
  v42 = 4 * v35;
  v79 = MemAlloc_Alloc(nSize: v42);
  if ( v79 == nullptr )
    goto LABEL_186;
  memset(v82, 0, v41);
  v43 = v42;
  v44 = v79;
  memset(v79, 0, v43);
  for ( m = 0; m < *((_DWORD *)this + 2); ++m )
  {
    v46 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * m);
    v47 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v46 + 4)) + 4);
    if ( (v47 & 0x100) != 0
      && *(_DWORD *)(v46 + 8) == -1
      && *(_DWORD *)(v46 + 56) == -1
      && (v47 & 0x40000) == 0
      && ((v47 & 0x800) == 0 || *((_DWORD *)this + 86) != 0) )
    {
      for ( n = 0; n < nSize; ++n )
      {
        if ( v44[n] == *(_DWORD *)(v46 + 12) )
          break;
      }
      if ( n == nSize )
      {
        v49 = *(_DWORD *)(v46 + 12);
        ++nSize;
        v44[n] = v49;
      }
      *((float *)v82 + 4 * n + *(_DWORD *)(v46 + 16)) = *(double *)(v46 + 32);
    }
  }
  v50 = 0;
  if ( nSize != 0 )
  {
    v90 = (unsigned int)v82;
    do
    {
      Code = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, unsigned int))(*(_DWORD *)this + 60))(
               a1: this,
               a2: *((_DWORD *)v79 + v50),
               a3: v90);
      if ( Code < 0 )
        goto LABEL_212;
      v90 += 16;
    }
    while ( ++v50 < nSize );
  }
  v60 = *((_DWORD *)this + 2) == 0;
  v80 = nullptr;
  nSize = 0;
  if ( !v60 )
  {
    v51 = *((_DWORD *)this + 4);
    v52 = *((_DWORD *)this + 5);
    v53 = *((_DWORD *)this + 2);
    do
    {
      if ( (*(_BYTE *)(*(_DWORD *)(v51 + 4 * *(_DWORD *)(*(_DWORD *)v52 + 4)) + 5) & 1) != 0
        && *(_DWORD *)(*(_DWORD *)v52 + 8) == -1 )
      {
        v80 = (char *)v80 + 1;
      }
      v52 += 4;
      --v53;
    }
    while ( v53 != 0 );
  }
  v54 = v80;
  v55 = 16 * (_DWORD)v80;
  v80 = MemAlloc_Alloc(nSize: 16 * (_DWORD)v80);
  if ( v80 == nullptr )
  {
LABEL_3:
    Code = -2147024882;
    goto LABEL_212;
  }
  v56 = 4 * (_DWORD)v54;
  v84 = MemAlloc_Alloc(nSize: v56);
  if ( v84 == nullptr )
    goto LABEL_186;
  v90 = 0;
  memset(v80, 0, v55);
  memset(v84, 0, v56);
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v57 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v90);
      v58 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v57 + 4)) + 4);
      if ( (v58 & 0x100) != 0 && *(_DWORD *)(v57 + 8) == -1 && *(_DWORD *)(v57 + 56) == -1 && (v58 & 0x40000) != 0 )
      {
        v59 = 0;
        v60 = nSize == 0;
        if ( nSize != 0 )
        {
          do
          {
            if ( *((_DWORD *)v84 + v59) == *(_DWORD *)(v57 + 12) )
              break;
            ++v59;
          }
          while ( v59 < nSize );
          v60 = v59 == nSize;
        }
        if ( v60 )
        {
          v61 = *(_DWORD *)(v57 + 12);
          ++nSize;
          *((_DWORD *)v84 + v59) = v61;
        }
        *((_DWORD *)v80 + 4 * v59 + *(_DWORD *)(v57 + 16)) = (__int64)*(double *)(v57 + 32);
      }
      ++v90;
    }
    while ( v90 < *((_DWORD *)this + 2) );
  }
  v62 = 0;
  if ( nSize != 0 )
  {
    v90 = (unsigned int)v80;
    while ( 1 )
    {
      Code = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, unsigned int))(*(_DWORD *)this + 64))(
               a1: this,
               a2: *((_DWORD *)v84 + v62),
               a3: v90);
      if ( Code < 0 )
        break;
      v90 += 16;
      if ( ++v62 >= nSize )
        goto LABEL_157;
    }
  }
  else
  {
LABEL_157:
    if ( (unsigned int)k > *((_DWORD *)this + 17) )
    {
      D3DXShader::CProgram::Error(this, a2: nullptr, a3: 0x119Au, format: "maximum number of inputs exceeded");
      goto LABEL_186;
    }
    v90 = 0;
    if ( v88 != 0 )
    {
      v63 = pMem;
      for ( k = (struct D3DXCore::CBuffer *)v88; k != nullptr; k = (struct D3DXCore::CBuffer *)((char *)k - 1) )
      {
        if ( *v63 != 0
          && (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int))(*(_DWORD *)this + 68))(
               a1: this,
               a2: *v63,
               a3: (int)v63 + (_BYTE *)v77 - (_BYTE *)pMem) < 0 )
        {
          v90 = 1;
        }
        ++v63;
      }
    }
    Code = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 76))(a1: this);
    v64 = 0;
    if ( Code >= 0 )
    {
      if ( v83 != 0 )
      {
        do
        {
          if ( *((_DWORD *)v81 + v64) != 0
            && (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD))(*(_DWORD *)this + 72))(
                 a1: this,
                 a2: *((_DWORD *)v81 + v64)) < 0 )
          {
            v90 = 1;
          }
          ++v64;
        }
        while ( v64 < v83 );
      }
      if ( *((char *)this + 112) >= 0 )
      {
        if ( v89 != 0 )
        {
          v66 = v87;
          for ( k = (struct D3DXCore::CBuffer *)v89; k != nullptr; k = (struct D3DXCore::CBuffer *)((char *)k - 1) )
          {
            if ( *v66 != 0
              && (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)this + 108))(
                   a1: this,
                   a2: *v66,
                   a3: (int)v66 + (_BYTE *)v85 - (_BYTE *)v87,
                   a4: 0,
                   a5: 0) < 0 )
            {
              v90 = 1;
            }
            ++v66;
          }
        }
      }
      else if ( v89 != 0 )
      {
        v65 = v87;
        for ( k = (struct D3DXCore::CBuffer *)v89; k != nullptr; k = (struct D3DXCore::CBuffer *)((char *)k - 1) )
        {
          if ( *v65 != 0
            && (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int))(*(_DWORD *)this + 68))(
                 a1: this,
                 a2: *v65,
                 a3: (int)v65 + (_BYTE *)v85 - (_BYTE *)v87) < 0 )
          {
            v90 = 1;
          }
          ++v65;
        }
      }
      v67 = 0;
      if ( v90 != 0 )
        goto LABEL_186;
      v68 = 0;
      if ( v89 != 0 )
      {
        while ( 1 )
        {
          if ( *(_DWORD *)((char *)v87 + v67) != 0 )
          {
            k = nullptr;
            if ( v67 != 0 )
              break;
          }
LABEL_194:
          ++v68;
          v67 += 4;
          if ( v68 >= v89 )
            goto LABEL_195;
        }
        v69 = v85;
        while ( *(_DWORD *)((char *)v69 + (_BYTE *)v87 - (_BYTE *)v85) == 0 || *(_DWORD *)((char *)v85 + v67) != *v69 )
        {
          k = (struct D3DXCore::CBuffer *)((char *)k + 1);
          ++v69;
          if ( (unsigned int)k >= v68 )
            goto LABEL_194;
        }
        D3DXShader::CProgram::Error(
          this,
          a2: *(struct D3DXShader::CNode **)(*((_DWORD *)v87 + v68) + 104),
          a3: 0x1198u,
          format: "overlapping output semantics");
        goto LABEL_186;
      }
LABEL_195:
      if ( (*((_BYTE *)this + 110) & 0x40) != 0 || (Code = D3DXShader::CShaderProgram::Reset(this)) >= 0 )
      {
        Code = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 36))(a1: this);
        if ( Code >= 0 && (*((_DWORD *)this + 56) == 0 || (Code = D3DXShader::CShaderProgram::EmitPreShader(this)) >= 0) )
        {
          Code = D3DXShader::CShaderProgram::EmitSymbolTable(this);
          if ( Code >= 0
            && ((*((_BYTE *)this + 204) & 1) == 0 || (Code = D3DXShader::CShaderProgram::EmitDebugInfo(this)) >= 0) )
          {
            Code = D3DXShader::CShaderProgram::Emit(this, a2: 0xFFFFu);
            if ( Code >= 0 )
            {
              Code = D3DXShader::CShaderProgram::ValidateInst(this);
              if ( Code >= 0 )
              {
                v70 = *((_DWORD *)this + 108);
                if ( v70 == 0
                  || *((_DWORD *)this + 53) != 0
                  || (Code = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v70 + 20))(a1: *((_DWORD *)this + 108))) >= 0 )
                {
                  if ( a2 != nullptr )
                  {
                    Code = D3DXCore::CBuffer::Create(a1: 4 * *((_DWORD *)this + 68), a2: &k);
                    if ( Code < 0 )
                      goto LABEL_212;
                    v71 = *((const void **)this + 67);
                    v83 = 4 * *((_DWORD *)this + 68);
                    v72 = (void *)(*(int (__stdcall **)(struct D3DXCore::CBuffer *))(*(_DWORD *)k + 12))(a1: k);
                    qmemcpy(v72, v71, v83);
                    *a2 = (struct ID3DXBuffer *)k;
                  }
                  Code = 0;
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_212:
  free(pMem);
  free(pMem: v87);
  free(pMem: v77);
  free(pMem: v85);
  free(pMem: nullptr);
  free(pMem: v82);
  free(pMem: v79);
  free(pMem: v81);
  free(pMem: v80);
  free(pMem: v84);
  free(pMem: *((void **)this + 67));
  *((_DWORD *)this + 67) = 0;
  free(pMem: *((void **)this + 73));
  *((_DWORD *)this + 73) = 0;
  v73 = (_DWORD *)((char *)this + 432);
  if ( *v73 != 0 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v73 + 8))(a1: *v73);
    *v73 = 0;
  }
  return Code;
}

//------------------------------------------------------------------------------
// Address: 0x102243A5
// Name: protected: long D3DXShader::CShaderProgram::EmitInst(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitInst(D3DXShader::CShaderProgram *this, unsigned int a2)
{
  unsigned int v3; // eax
  void *v4; // edi
  unsigned int i; // ecx

  if ( (*((_BYTE *)this + 204) & 1) != 0 && *((_DWORD *)this + 73) != 0 )
  {
    v3 = *((_DWORD *)this + 75);
    if ( *((_DWORD *)this + 74) >= v3 )
    {
      v4 = MemAlloc_Alloc(nSize: 48 * v3);
      if ( v4 == nullptr )
        return -2147024882;
      qmemcpy(v4, *((const void **)this + 73), 24 * *((_DWORD *)this + 74));
      free(pMem: *((void **)this + 73));
      *((_DWORD *)this + 75) *= 2;
      *((_DWORD *)this + 73) = v4;
    }
    *(_DWORD *)(*((_DWORD *)this + 73) + 24 * *((_DWORD *)this + 74)) = *((_DWORD *)this + 65);
    *(_DWORD *)(*((_DWORD *)this + 73) + 24 * *((_DWORD *)this + 74) + 4) = 4 * *((_DWORD *)this + 68);
    for ( i = 0; i < 4; ++i )
      *(_DWORD *)(*((_DWORD *)this + 73) + 4 * (i + 6 * *((_DWORD *)this + 74)) + 8) = -1;
    ++*((_DWORD *)this + 74);
  }
  *((_DWORD *)this + 70) = *((_DWORD *)this + 68);
  D3DXShader::CShaderProgram::Emit(this, a2);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102244AB
// Name: protected: long D3DXShader::CShaderProgram::EmitReg(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitReg(D3DXShader::CShaderProgram *this, unsigned int a2)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::Emit(this, a2);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102244C2
// Name: protected: virtual long D3DXShader::CShaderProgram::EmitDest(unsigned long,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitDest(D3DXShader::CShaderProgram *this, __int64 a2, unsigned int a3)
{
  int result; // eax
  int v5; // eax

  result = D3DXShader::CShaderProgram::EmitReg(this, a2: HIDWORD(a2) | a2);
  if ( result >= 0 )
  {
    if ( a3 != 0 )
    {
      result = D3DXShader::CShaderProgram::EmitReg(this, a2: a3);
      if ( result < 0 )
        return result;
      v5 = *((_DWORD *)this + 67) + 4 * *((_DWORD *)this + 70);
      *(_BYTE *)(v5 + 3) |= 0x10u;
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10224508
// Name: protected: virtual long D3DXShader::CShaderProgram::EmitSrc(unsigned long,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitSrc(D3DXShader::CShaderProgram *this, __int64 a2, unsigned int a3)
{
  int result; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  int v9; // ecx
  int v10; // ecx

  result = D3DXShader::CShaderProgram::EmitReg(this, a2: HIDWORD(a2) | a2);
  if ( result >= 0 )
  {
    if ( ((WORD2(a2) | (unsigned __int16)a2) & 0x2000) != 0 )
    {
      v5 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3);
      v6 = *(_DWORD *)(v5 + 12);
      v7 = *(_DWORD *)(v5 + 16);
      v8 = v6 & 0x7FF | 0xB0000000;
      if ( v7 != 0 )
      {
        v9 = v7 - 1;
        if ( v9 != 0 )
        {
          v10 = v9 - 1;
          if ( v10 != 0 )
          {
            if ( v10 == 1 )
              v8 |= 0xFF0000u;
          }
          else
          {
            v8 |= 0xAA0000u;
          }
        }
        else
        {
          v8 |= 0x550000u;
        }
      }
      D3DXShader::CShaderProgram::EmitReg(this, a2: v8);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10224573
// Name: protected: long D3DXShader::CShaderProgram::EmitInstComplex(unsigned long,unsigned int __near *,unsigned int,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int,unsigned long,unsigned long,unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitInstComplex(
        D3DXShader::CShaderProgram *this,
        unsigned int a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int *a5,
        unsigned int *a6,
        unsigned int *a7,
        unsigned int a8,
        unsigned int a9,
        unsigned int a10,
        unsigned int a11,
        int a12)
{
  unsigned int v12; // ebx
  unsigned int v14; // eax
  int result; // eax
  unsigned int *v16; // edi
  unsigned int *v17; // edi
  unsigned int *v18; // edi
  unsigned int *v19; // edi
  int v20; // [esp+8h] [ebp-14h] BYREF
  int v21; // [esp+Ch] [ebp-10h] BYREF
  int v22; // [esp+10h] [ebp-Ch] BYREF
  int v23; // [esp+14h] [ebp-8h] BYREF
  int v24; // [esp+18h] [ebp-4h] BYREF

  v12 = a2;
  v14 = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int))(*(_DWORD *)this + 92))(a1: this, a2);
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: v14);
  if ( result < 0 )
    return result;
  v16 = a3;
  result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *, int *))(*(_DWORD *)this + 108))(
             a1: this,
             a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a3),
             a3: &v24,
             a4: &v20,
             a5: &v21);
  if ( result < 0 )
    return result;
  result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int *, unsigned int, unsigned int *, int))(*(_DWORD *)this + 112))(
             a1: this,
             a2: v16,
             a3: a4,
             a4: &a2,
             a5: v21);
  if ( result < 0 )
    return result;
  result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, unsigned int, int))(*(_DWORD *)this + 100))(
             a1: this,
             a2: v24 | (a12 != 0 ? 0x400000 : 0),
             a3: a2,
             a4: v20);
  if ( result < 0 )
    return result;
  switch ( v12 )
  {
    case 8u:
      a2 = 458752;
      break;
    case 9u:
      goto LABEL_16;
    case 0x5Au:
      a2 = 196608;
      break;
    case 6u:
    case 0xEu:
    case 0xFu:
    case 7u:
      a2 = 0x10000;
      break;
    case 0x25u:
LABEL_16:
      a2 = 983040;
      break;
    default:
      break;
  }
  v17 = a5;
  if ( a5 == nullptr
    || (result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                   a1: this,
                   a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a5),
                   a3: &v24,
                   a4: &v23)) >= 0
    && (result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int *, unsigned int, unsigned int, int *))(*(_DWORD *)this + 120))(
                   a1: this,
                   a2: v17,
                   a3: a8,
                   a4: a2,
                   a5: &v22)) >= 0
    && (result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int, int, int))(*(_DWORD *)this + 104))(
                   a1: this,
                   a2: a9 ^ v24,
                   a3: v22,
                   a4: v23)) >= 0 )
  {
    v18 = a6;
    if ( a6 == nullptr
      || (result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                     a1: this,
                     a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a6),
                     a3: &v24,
                     a4: &v23)) >= 0
      && (result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int *, unsigned int, unsigned int, int *))(*(_DWORD *)this + 120))(
                     a1: this,
                     a2: v18,
                     a3: a8,
                     a4: a2,
                     a5: &v22)) >= 0
      && (result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int, int, int))(*(_DWORD *)this + 104))(
                     a1: this,
                     a2: a10 ^ v24,
                     a3: v22,
                     a4: v23)) >= 0 )
    {
      v19 = a7;
      if ( a7 == nullptr
        || (result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                       a1: this,
                       a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a7),
                       a3: &v24,
                       a4: &v23)) >= 0
        && (result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int *, unsigned int, unsigned int, int *))(*(_DWORD *)this + 120))(
                       a1: this,
                       a2: v19,
                       a3: a8,
                       a4: a2,
                       a5: &v22)) >= 0
        && (result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int, int, int))(*(_DWORD *)this + 104))(
                       a1: this,
                       a2: a11 ^ v24,
                       a3: v22,
                       a4: v23)) >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
        if ( result >= 0 )
        {
          result = D3DXShader::CShaderProgram::ValidateInst(this);
          if ( result >= 0 )
            return 0;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022476C
// Name: protected: virtual long D3DXShader::CShaderProgram::EmitDEF(unsigned int,float __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitDEF(
        struct D3DXShader::CRegisterEntryNode **this,
        unsigned int a2,
        float *a3)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  int result; // eax
  struct D3DXShader::CRegisterEntryNode *Element; // eax
  char string[32]; // [esp+Ch] [ebp-24h] BYREF

  if ( *(this + 86) != nullptr )
  {
    sprintf(string, format: "c_$zz%d", a2);
    result = D3DXShader::CFragmentRegisterAllocator::AddElement(
               this: this + 109,
               a2: (D3DXShader *)string,
               a3: a2,
               a4: 1u);
    if ( result < 0 )
      return result;
    Element = D3DXShader::CFragmentRegisterAllocator::GetElement(
                this: (D3DXShader::CFragmentRegisterAllocator *)(this + 109),
                lpString2: (D3DXShader *)string);
    *((_DWORD *)Element + 3) = 1;
    *((float *)Element + 4) = *a3;
    *((float *)Element + 5) = a3[1];
    *((float *)Element + 6) = a3[2];
    *((float *)Element + 7) = a3[3];
    *(this + 125) = (struct D3DXShader::CRegisterEntryNode *)((char *)*(this + 125) + 1);
    return 0;
  }
  if ( a2 >= 0x800 )
  {
    if ( a2 >= 0x1000 )
    {
      if ( a2 >= 0x1800 )
        v4 = a2 & 0x7FF | 0xD0000800;
      else
        v4 = a2 & 0x7FF | 0xC0000800;
    }
    else
    {
      v4 = a2 & 0x7FF | 0xB0000800;
    }
  }
  else
  {
    v4 = a2 & 0x7FF | 0xA0000000;
  }
  v5 = v4;
  result = D3DXShader::CShaderProgram::EmitInst((D3DXShader::CShaderProgram *)this, a2: 0x51u);
  if ( result >= 0 )
  {
    result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, unsigned int, int, _DWORD))*this + 25))(
               a1: this,
               a2: v5,
               a3: 983040,
               a4: 0);
    if ( result >= 0 )
    {
      result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: *(_DWORD *)a3);
      if ( result >= 0 )
      {
        result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: *((_DWORD *)a3 + 1));
        if ( result >= 0 )
        {
          result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: *((_DWORD *)a3 + 2));
          if ( result >= 0 )
          {
            result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: *((_DWORD *)a3 + 3));
            if ( result >= 0 )
            {
              result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **))*this + 24))(a1: this);
              if ( result >= 0 )
              {
                result = D3DXShader::CShaderProgram::ValidateInst((D3DXShader::CShaderProgram *)this);
                if ( result >= 0 )
                  return 0;
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
// Address: 0x102248B6
// Name: protected: virtual long D3DXShader::CShaderProgram::EmitDEFi(unsigned int,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitDEFi(
        struct D3DXShader::CRegisterEntryNode **this,
        unsigned int a2,
        unsigned int *a3)
{
  int result; // eax
  struct D3DXShader::CRegisterEntryNode *Element; // eax
  char string[32]; // [esp+8h] [ebp-24h] BYREF

  if ( *(this + 86) != nullptr )
  {
    sprintf(string, format: "i_$zz%d", a2);
    result = D3DXShader::CFragmentRegisterAllocator::AddElement(
               this: this + 109,
               a2: (D3DXShader *)string,
               a3: a2,
               a4: 1u);
    if ( result >= 0 )
    {
      Element = D3DXShader::CFragmentRegisterAllocator::GetElement(
                  this: (D3DXShader::CFragmentRegisterAllocator *)(this + 109),
                  lpString2: (D3DXShader *)string);
      *((_DWORD *)Element + 3) = 1;
      *((_DWORD *)Element + 4) = *a3;
      *((_DWORD *)Element + 5) = a3[1];
      *((_DWORD *)Element + 6) = a3[2];
      *((_DWORD *)Element + 7) = a3[3];
      *(this + 125) = (struct D3DXShader::CRegisterEntryNode *)((char *)*(this + 125) + 1);
      return 0;
    }
  }
  else
  {
    result = D3DXShader::CShaderProgram::EmitInst((D3DXShader::CShaderProgram *)this, a2: 0x30u);
    if ( result >= 0 )
    {
      result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **, unsigned int, int, _DWORD))*this + 25))(
                 a1: this,
                 a2: a2 & 0x7FF | 0xF0000000,
                 a3: 983040,
                 a4: 0);
      if ( result >= 0 )
      {
        result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: *a3);
        if ( result >= 0 )
        {
          result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: a3[1]);
          if ( result >= 0 )
          {
            result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: a3[2]);
            if ( result >= 0 )
            {
              result = D3DXShader::CShaderProgram::Emit((D3DXShader::CShaderProgram *)this, a2: a3[3]);
              if ( result >= 0 )
              {
                result = (*((int (__thiscall **)(struct D3DXShader::CRegisterEntryNode **))*this + 24))(a1: this);
                if ( result >= 0 )
                {
                  result = D3DXShader::CShaderProgram::ValidateInst((D3DXShader::CShaderProgram *)this);
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
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102249C7
// Name: protected: long D3DXShader::CShaderProgram::EmitENDLOOP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitENDLOOP(D3DXShader::CShaderProgram *this)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x27u);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
    if ( result >= 0 )
    {
      result = D3DXShader::CShaderProgram::ValidateInst(this);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102249F1
// Name: protected: long D3DXShader::CShaderProgram::EmitENDLOOP_INC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitENDLOOP_INC(D3DXShader::CShaderProgram *this)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x1Du);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
    if ( result >= 0 )
    {
      result = D3DXShader::CShaderProgram::ValidateInst(this);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10224A1B
// Name: protected: long D3DXShader::CShaderProgram::EmitBREAK(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitBREAK(D3DXShader::CShaderProgram *this)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // ecx
  int v5; // edi
  int result; // eax
  int v7; // [esp-4h] [ebp-1Ch]
  int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  int v10; // [esp+14h] [ebp-4h] BYREF

  v2 = **((_DWORD **)this + 64);
  v3 = v2 & 0xFFF00000;
  v4 = 0;
  v5 = v2 & 0xFFFFF;
  if ( v3 != 1949302784 )
  {
    if ( v3 == 1950351360 )
    {
      v7 = 5;
      goto LABEL_10;
    }
    if ( v3 != 1951399936 )
    {
      if ( v3 == 1952448512 )
      {
        v7 = 4;
        goto LABEL_10;
      }
      if ( v3 == 1953497088 )
      {
        v7 = 3;
LABEL_10:
        v4 = v7;
      }
      result = D3DXShader::CShaderProgram::EmitInst(this, a2: (v4 << 16) | 0x2D);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                   a1: this,
                   a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 8)),
                   a3: &v8,
                   a4: &v10);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int, int, int *))(*(_DWORD *)this + 120))(
                     a1: this,
                     a2: *(_DWORD *)(*((_DWORD *)this + 64) + 8),
                     a3: v5,
                     a4: 983040,
                     a5: &v9);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                       a1: this,
                       a2: v8,
                       a3: v9,
                       a4: v10);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                         a1: this,
                         a2: *(_DWORD *)(*((_DWORD *)this + 5)
                                   + 4 * *(_DWORD *)(4 * v5 + *(_DWORD *)(*((_DWORD *)this + 64) + 8))),
                         a3: &v8,
                         a4: &v10);
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int, int *))(*(_DWORD *)this + 120))(
                           a1: this,
                           a2: 4 * v5 + *(_DWORD *)(*((_DWORD *)this + 64) + 8),
                           a3: v5,
                           a4: 983040,
                           a5: &v9);
                if ( result >= 0 )
                {
                  result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                             a1: this,
                             a2: v8,
                             a3: v9,
                             a4: v10);
                  if ( result >= 0 )
                  {
                    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
                    if ( result >= 0 )
                    {
                      result = D3DXShader::CShaderProgram::ValidateInst(this);
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
      return result;
    }
  }
  v7 = 2;
  goto LABEL_10;
}

//------------------------------------------------------------------------------
// Address: 0x10224B61
// Name: protected: long D3DXShader::CShaderProgram::EmitTEX(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitTEX(D3DXShader::CShaderProgram *this)
{
  D3DXShader::CInstruction *v2; // ecx
  unsigned int v3; // esi
  unsigned int *v5; // [esp+Ch] [ebp-10h]
  unsigned int v6; // [esp+10h] [ebp-Ch]
  unsigned int *v7; // [esp+14h] [ebp-8h] BYREF
  unsigned int *v8; // [esp+18h] [ebp-4h] BYREF

  v2 = *((D3DXShader::CInstruction **)this + 64);
  v6 = *((_DWORD *)v2 + 3);
  v5 = *((unsigned int **)v2 + 4);
  v3 = *(_DWORD *)v2 & 0xFFFFF;
  D3DXShader::CInstruction::GetInputs(this: v2, a2: 0, a3: &v8);
  D3DXShader::CInstruction::GetInputs(this: *((D3DXShader::CInstruction **)this + 64), a2: 1u, a3: &v7);
  return D3DXShader::CShaderProgram::EmitInstComplex(
           this,
           a2: 0x42u,
           a3: v5,
           a4: v6,
           a5: v7,
           a6: v8,
           a7: nullptr,
           a8: v3,
           a9: 0,
           a10: 0,
           a11: 0,
           a12: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10224BC5
// Name: protected: long D3DXShader::CShaderProgram::EmitTEXDD(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitTEXDD(D3DXShader::CShaderProgram *this)
{
  D3DXShader::CInstruction *v2; // ecx
  int v3; // edi
  int v4; // edi
  _DWORD *v5; // ebx
  unsigned int v6; // eax
  int result; // eax
  int v8; // [esp+Ch] [ebp-2Ch] BYREF
  int v9; // [esp+10h] [ebp-28h]
  int v10; // [esp+14h] [ebp-24h] BYREF
  unsigned int *v11; // [esp+18h] [ebp-20h] BYREF
  unsigned int *v12; // [esp+1Ch] [ebp-1Ch] BYREF
  unsigned int *v13; // [esp+20h] [ebp-18h] BYREF
  unsigned int *v14; // [esp+24h] [ebp-14h] BYREF
  int v15; // [esp+28h] [ebp-10h] BYREF
  int v16; // [esp+2Ch] [ebp-Ch] BYREF
  int v17; // [esp+30h] [ebp-8h] BYREF
  int v18; // [esp+34h] [ebp-4h] BYREF

  v2 = *((D3DXShader::CInstruction **)this + 64);
  v3 = *(_DWORD *)v2;
  v9 = *((_DWORD *)v2 + 3);
  v4 = v3 & 0xFFFFF;
  D3DXShader::CInstruction::GetInputs(this: v2, a2: 0, a3: &v13);
  D3DXShader::CInstruction::GetInputs(this: *((D3DXShader::CInstruction **)this + 64), a2: 1u, a3: &v14);
  D3DXShader::CInstruction::GetInputs(this: *((D3DXShader::CInstruction **)this + 64), a2: 2u, a3: &v12);
  D3DXShader::CInstruction::GetInputs(this: *((D3DXShader::CInstruction **)this + 64), a2: 3u, a3: &v11);
  v5 = *(_DWORD **)(*((_DWORD *)this + 64) + 16);
  v6 = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int))(*(_DWORD *)this + 92))(a1: this, a2: 93);
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: v6);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *, int *))(*(_DWORD *)this + 108))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v5),
               a3: &v18,
               a4: &v8,
               a5: &v10);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD *, int, int *, int))(*(_DWORD *)this + 112))(
                 a1: this,
                 a2: v5,
                 a3: v9,
                 a4: &v15,
                 a5: v10);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 100))(
                   a1: this,
                   a2: v18,
                   a3: v15,
                   a4: v8);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                     a1: this,
                     a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v14),
                     a3: &v18,
                     a4: &v17);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int *, int, int, int *))(*(_DWORD *)this + 120))(
                       a1: this,
                       a2: v14,
                       a3: v4,
                       a4: v15,
                       a5: &v16);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                         a1: this,
                         a2: v18,
                         a3: v16,
                         a4: v17);
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                           a1: this,
                           a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v13),
                           a3: &v18,
                           a4: &v17);
                if ( result >= 0 )
                {
                  result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int *, int, int, int *))(*(_DWORD *)this + 120))(
                             a1: this,
                             a2: v13,
                             a3: v4,
                             a4: v15,
                             a5: &v16);
                  if ( result >= 0 )
                  {
                    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                               a1: this,
                               a2: v18,
                               a3: v16,
                               a4: v17);
                    if ( result >= 0 )
                    {
                      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                                 a1: this,
                                 a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v12),
                                 a3: &v18,
                                 a4: &v17);
                      if ( result >= 0 )
                      {
                        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int *, int, int, int *))(*(_DWORD *)this + 120))(
                                   a1: this,
                                   a2: v12,
                                   a3: v4,
                                   a4: v15,
                                   a5: &v16);
                        if ( result >= 0 )
                        {
                          result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                                     a1: this,
                                     a2: v18,
                                     a3: v16,
                                     a4: v17);
                          if ( result >= 0 )
                          {
                            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                                       a1: this,
                                       a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v11),
                                       a3: &v18,
                                       a4: &v17);
                            if ( result >= 0 )
                            {
                              result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int *, int, int, int *))(*(_DWORD *)this + 120))(
                                         a1: this,
                                         a2: v11,
                                         a3: v4,
                                         a4: v15,
                                         a5: &v16);
                              if ( result >= 0 )
                              {
                                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                                           a1: this,
                                           a2: v18,
                                           a3: v16,
                                           a4: v17);
                                if ( result >= 0 )
                                {
                                  result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
                                  if ( result >= 0 )
                                  {
                                    result = D3DXShader::CShaderProgram::ValidateInst(this);
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
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10224DF4
// Name: protected: long D3DXShader::CShaderProgram::EmitTEXProj(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitTEXProj(D3DXShader::CShaderProgram *this)
{
  D3DXShader::CInstruction *v2; // ecx
  unsigned int v3; // esi
  unsigned int *v5; // [esp+Ch] [ebp-10h]
  unsigned int v6; // [esp+10h] [ebp-Ch]
  unsigned int *v7; // [esp+14h] [ebp-8h] BYREF
  unsigned int *v8; // [esp+18h] [ebp-4h] BYREF

  v2 = *((D3DXShader::CInstruction **)this + 64);
  v6 = *((_DWORD *)v2 + 3);
  v5 = *((unsigned int **)v2 + 4);
  v3 = *(_DWORD *)v2 & 0xFFFFF;
  D3DXShader::CInstruction::GetInputs(this: v2, a2: 0, a3: &v8);
  D3DXShader::CInstruction::GetInputs(this: *((D3DXShader::CInstruction **)this + 64), a2: 1u, a3: &v7);
  return D3DXShader::CShaderProgram::EmitInstComplex(
           this,
           a2: 0x10042u,
           a3: v5,
           a4: v6,
           a5: v7,
           a6: v8,
           a7: nullptr,
           a8: v3,
           a9: 0,
           a10: 0,
           a11: 0,
           a12: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10224E5B
// Name: protected: long D3DXShader::CShaderProgram::EmitTEXBias(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitTEXBias(D3DXShader::CShaderProgram *this)
{
  D3DXShader::CInstruction *v2; // ecx
  unsigned int v3; // esi
  unsigned int *v5; // [esp+Ch] [ebp-10h]
  unsigned int v6; // [esp+10h] [ebp-Ch]
  unsigned int *v7; // [esp+14h] [ebp-8h] BYREF
  unsigned int *v8; // [esp+18h] [ebp-4h] BYREF

  v2 = *((D3DXShader::CInstruction **)this + 64);
  v6 = *((_DWORD *)v2 + 3);
  v5 = *((unsigned int **)v2 + 4);
  v3 = *(_DWORD *)v2 & 0xFFFFF;
  D3DXShader::CInstruction::GetInputs(this: v2, a2: 0, a3: &v8);
  D3DXShader::CInstruction::GetInputs(this: *((D3DXShader::CInstruction **)this + 64), a2: 1u, a3: &v7);
  return D3DXShader::CShaderProgram::EmitInstComplex(
           this,
           a2: 0x20042u,
           a3: v5,
           a4: v6,
           a5: v7,
           a6: v8,
           a7: nullptr,
           a8: v3,
           a9: 0,
           a10: 0,
           a11: 0,
           a12: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10224EC2
// Name: protected: long D3DXShader::CShaderProgram::EmitTEXLOD(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitTEXLOD(D3DXShader::CShaderProgram *this)
{
  D3DXShader::CInstruction *v2; // ecx
  int v3; // esi
  unsigned int *v5; // [esp+Ch] [ebp-10h] BYREF
  unsigned int *v6; // [esp+10h] [ebp-Ch] BYREF
  unsigned int *v7; // [esp+14h] [ebp-8h]
  unsigned int v8; // [esp+18h] [ebp-4h]

  v2 = *((D3DXShader::CInstruction **)this + 64);
  v3 = *(_DWORD *)v2;
  v8 = *((_DWORD *)v2 + 3);
  v7 = *((unsigned int **)v2 + 4);
  D3DXShader::CInstruction::GetInputs(this: v2, a2: 0, a3: &v5);
  D3DXShader::CInstruction::GetInputs(this: *((D3DXShader::CInstruction **)this + 64), a2: 1u, a3: &v6);
  return D3DXShader::CShaderProgram::EmitInstComplex(
           this,
           a2: 0x5Fu,
           a3: v7,
           a4: v8,
           a5: v6,
           a6: v5,
           a7: nullptr,
           a8: v3 & 0xFFFFF,
           a9: 0,
           a10: 0,
           a11: 0,
           a12: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10224F26
// Name: protected: long D3DXShader::CShaderProgram::EmitDP2ADD(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitDP2ADD(D3DXShader::CShaderProgram *this)
{
  int v1; // edx

  v1 = *((_DWORD *)this + 64);
  return D3DXShader::CShaderProgram::EmitInstComplex(
           this,
           a2: 0x5Au,
           a3: *(unsigned int **)(v1 + 16),
           a4: *(_DWORD *)(v1 + 12),
           a5: *(unsigned int **)(v1 + 8),
           a6: (unsigned int *)(*(_DWORD *)(v1 + 8) + 4 * (*(_DWORD *)v1 & 0xFFFFF)),
           a7: (unsigned int *)(*(_DWORD *)(v1 + 8) + 8 * (*(_DWORD *)v1 & 0xFFFFF)),
           a8: *(_DWORD *)v1 & 0xFFFFF,
           a9: 0,
           a10: 0,
           a11: 0,
           a12: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10224F5C
// Name: protected: long D3DXShader::CShaderProgram::EmitCLIP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitCLIP(D3DXShader::CShaderProgram *this)
{
  int v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // edx
  int v5; // ebx
  _DWORD *v6; // ecx
  int v7; // edx
  int v8; // ecx
  unsigned __int8 v9; // cl
  int v10; // eax
  unsigned int v11; // edi
  int result; // eax
  const char *v13; // [esp-4h] [ebp-1Ch]
  int v14; // [esp+Ch] [ebp-Ch] BYREF
  int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h] BYREF

  v2 = *((_DWORD *)this + 64);
  if ( (*((_BYTE *)this + 110) & 0x40) != 0 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    v4 = 0;
    if ( v3 != 0 )
    {
      v5 = *((_DWORD *)this + 5);
      v6 = *(_DWORD **)(v2 + 8);
      while ( *(_DWORD *)(*(_DWORD *)(v5 + 4 * *v6) + 16) == v4 )
      {
        v3 = *(_DWORD *)(v2 + 4);
        ++v4;
        ++v6;
        if ( v4 >= v3 )
          goto LABEL_6;
      }
      v13 = "cannot clip from a swizzled vector";
      goto LABEL_24;
    }
LABEL_6:
    if ( v3 != 3 )
    {
      v13 = "clip must be performed from a float3 vector for ps_1_x models";
LABEL_24:
      D3DXShader::CProgram::Error(this, a2: *(struct D3DXShader::CNode **)(v2 + 60), a3: 0x1194u, format: v13);
      return -2147467259;
    }
  }
  else if ( *(_DWORD *)(v2 + 4) != 4 )
  {
    v13 = "clip must be performed from a float4 vector for ps_2_0 models";
    goto LABEL_24;
  }
  v7 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v2 + 8));
  v8 = *(_DWORD *)(v7 + 4);
  if ( v8 == *((_DWORD *)this + 32) )
  {
    if ( (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int *, int *))(*(_DWORD *)this + 136))(
           a1: this,
           a2: v7,
           a3: &v15,
           a4: &v16) < 0 )
    {
      D3DXShader::CProgram::Error(
        this,
        a2: nullptr,
        a3: 0x1194u,
        format: "internal error: unexpected input register type");
      return -2147467259;
    }
    v9 = v16;
    LOWORD(v10) = v15;
  }
  else
  {
    if ( v8 != *((_DWORD *)this + 34) )
    {
      v13 = "clip cannot be performed from a constant or literal";
      goto LABEL_24;
    }
    v9 = 0;
    v16 = 0;
    v10 = *(_DWORD *)(v7 + 12);
    v15 = v10;
  }
  v11 = v10 & 0x7FF | ((v9 & 0x18 | ((v9 | 0xFFFFFFF8) << 20)) << 8);
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x41u);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *))(*(_DWORD *)this + 124))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
               a3: &v14);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int, int, int))(*(_DWORD *)this + 100))(
                 a1: this,
                 a2: v11,
                 a3: 983040,
                 a4: v14);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
        if ( result >= 0 )
        {
          result = D3DXShader::CShaderProgram::ValidateInst(this);
          if ( result >= 0 )
            return 0;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102250B1
// Name: protected: long D3DXShader::CShaderProgram::EmitSINCOS(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitSINCOS(D3DXShader::CShaderProgram *this)
{
  int v1; // eax
  int v2; // ebx
  unsigned int v3; // esi
  int v4; // edx
  unsigned int v5; // edx
  unsigned int v7[2]; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v8; // [esp+14h] [ebp-8h]
  unsigned int v9; // [esp+18h] [ebp-4h]

  v9 = 0;
  v1 = *((_DWORD *)this + 64);
  v8 = 0;
  v2 = *((_DWORD *)this + 4);
  do
  {
    v3 = *(_DWORD *)(v8 + *(_DWORD *)(v1 + 16));
    v4 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v3);
    if ( (*(_BYTE *)(*(_DWORD *)(v2 + 4 * *(_DWORD *)(v4 + 4)) + 4) & 1) == 0 || *(_DWORD *)(v4 + 92) != 0 )
    {
      v5 = v9++;
      v7[v5] = v3;
    }
    v8 += 4;
  }
  while ( v8 < 8 );
  if ( v9 != 0 )
    return D3DXShader::CShaderProgram::EmitInstComplex(
             this,
             a2: 0x25u,
             a3: v7,
             a4: v9,
             a5: *(unsigned int **)(v1 + 8),
             a6: *((_DWORD *)this + 99) != 0 ? (unsigned int *)this + 100 : nullptr,
             a7: *((_DWORD *)this + 99) != 0 ? (unsigned int *)this + 104 : nullptr,
             a8: 4u,
             a9: 0,
             a10: 0,
             a11: 0,
             a12: 0);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022514F
// Name: protected: long D3DXShader::CShaderProgram::EmitIF(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitIF(D3DXShader::CShaderProgram *this)
{
  int v2; // ecx
  int result; // eax
  int v4; // edi
  unsigned int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // [esp-14h] [ebp-2Ch]
  int v10; // [esp-Ch] [ebp-24h]
  int v11; // [esp+4h] [ebp-14h] BYREF
  int v12; // [esp+8h] [ebp-10h] BYREF
  int v13; // [esp+Ch] [ebp-Ch] BYREF
  int v14; // [esp+10h] [ebp-8h] BYREF
  int v15; // [esp+14h] [ebp-4h] BYREF

  v2 = 0;
  if ( *((_DWORD *)this + 13) == 0 )
    return -2147467263;
  v4 = **((_DWORD **)this + 64);
  v5 = v4 & 0xFFF00000;
  v6 = v4 & 0xFFFFF;
  if ( v5 != 284164096 )
  {
    if ( v5 == 1934622720 )
    {
      v10 = 3;
      goto LABEL_12;
    }
    if ( v5 == 1935671296 )
    {
      v10 = 4;
      goto LABEL_12;
    }
    if ( v5 != 1936719872 )
    {
      if ( v5 == 1937768448 )
      {
        v10 = 2;
LABEL_12:
        v2 = v10;
      }
      result = D3DXShader::CShaderProgram::EmitInst(this, a2: (v2 << 16) | 0x5E);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, _DWORD, int *))(*(_DWORD *)this + 108))(
                   a1: this,
                   a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
                   a3: &v15,
                   a4: 0,
                   a5: &v11);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, _DWORD, int *, int))(*(_DWORD *)this + 112))(
                     a1: this,
                     a2: *(_DWORD *)(*((_DWORD *)this + 64) + 16),
                     a3: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                     a4: &v12,
                     a5: v11);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, _DWORD))(*(_DWORD *)this + 100))(
                       a1: this,
                       a2: v15,
                       a3: v12,
                       a4: 0);
            if ( result >= 0 )
            {
              v7 = *((_DWORD *)this + 64);
              v8 = *(_DWORD *)this;
              v9 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v7 + 8));
              if ( (*(_DWORD *)v7 & 0xFFF00000) == 0x10F00000 )
              {
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int *, int *))(v8 + 116))(
                           a1: this,
                           a2: v9,
                           a3: &v15,
                           a4: &v14);
                if ( result < 0 )
                  return result;
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, _DWORD, int, int *))(*(_DWORD *)this + 120))(
                           a1: this,
                           a2: *(_DWORD *)(*((_DWORD *)this + 64) + 8),
                           a3: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                           a4: v12,
                           a5: &v13);
                if ( result < 0 )
                  return result;
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                           a1: this,
                           a2: v15,
                           a3: v13,
                           a4: v14);
                if ( result < 0 )
                  return result;
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                           a1: this,
                           a2: v15,
                           a3: v13 ^ 0x1000000,
                           a4: v14);
              }
              else
              {
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int *, int *))(v8 + 116))(
                           a1: this,
                           a2: v9,
                           a3: &v15,
                           a4: &v14);
                if ( result < 0 )
                  return result;
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int, int, int *))(*(_DWORD *)this + 120))(
                           a1: this,
                           a2: *(_DWORD *)(*((_DWORD *)this + 64) + 8),
                           a3: v6,
                           a4: v12,
                           a5: &v13);
                if ( result < 0 )
                  return result;
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                           a1: this,
                           a2: v15,
                           a3: v13,
                           a4: v14);
                if ( result < 0 )
                  return result;
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                           a1: this,
                           a2: *(_DWORD *)(*((_DWORD *)this + 5)
                                     + 4 * *(_DWORD *)(4 * v6 + *(_DWORD *)(*((_DWORD *)this + 64) + 8))),
                           a3: &v15,
                           a4: &v14);
                if ( result < 0 )
                  return result;
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int, int *))(*(_DWORD *)this + 120))(
                           a1: this,
                           a2: 4 * v6 + *(_DWORD *)(*((_DWORD *)this + 64) + 8),
                           a3: v6,
                           a4: v12,
                           a5: &v13);
                if ( result < 0 )
                  return result;
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                           a1: this,
                           a2: v15,
                           a3: v13,
                           a4: v14);
              }
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
                if ( result >= 0 )
                {
                  result = D3DXShader::CShaderProgram::ValidateInst(this);
                  if ( result >= 0 )
                    return 0;
                }
              }
            }
          }
        }
      }
      return result;
    }
  }
  v10 = 5;
  goto LABEL_12;
}

//------------------------------------------------------------------------------
// Address: 0x10225358
// Name: protected: long D3DXShader::CShaderProgram::EmitENDIF(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitENDIF(D3DXShader::CShaderProgram *this)
{
  int result; // eax
  int v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  unsigned int v9; // ebx
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // [esp+4h] [ebp-1Ch]
  int v13; // [esp+8h] [ebp-18h] BYREF
  int v14; // [esp+Ch] [ebp-14h] BYREF
  int v15; // [esp+10h] [ebp-10h] BYREF
  int v16; // [esp+14h] [ebp-Ch] BYREF
  int v17; // [esp+18h] [ebp-8h] BYREF
  unsigned int i; // [esp+1Ch] [ebp-4h]

  if ( *((_DWORD *)this + 13) == 0 )
    return -2147467263;
  v3 = *((_DWORD *)this + 64);
  if ( *(_DWORD *)(v3 + 12) == 0 )
    return 0;
  v4 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v3 + 16));
  v12 = v4;
  for ( i = 0; i < 2; ++i )
  {
    v5 = *(_DWORD **)(*((_DWORD *)this + 5)
                    + 4
                    * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8)
                                + 4 * i * *(_DWORD *)(*((_DWORD *)this + 64) + 12)));
    if ( v5[1] != v4[1] || v5[2] != v4[2] || v5[3] != v4[3] || v5[4] != v4[4] )
    {
      result = D3DXShader::CShaderProgram::EmitInst(this, a2: 1u);
      if ( result < 0 )
        return result;
      v6 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v5[5]);
      v7 = *(_DWORD *)(v6 + 12);
      v8 = *(_DWORD *)(v6 + 16);
      v9 = v7 & 0x7FF | 0xB0001000;
      if ( v8 != 0 )
      {
        v10 = v8 - 1;
        if ( v10 != 0 )
        {
          v11 = v10 - 1;
          if ( v11 != 0 )
          {
            if ( v11 == 1 )
              v9 |= 0xFF0000u;
          }
          else
          {
            v9 |= 0xAA0000u;
          }
        }
        else
        {
          v9 |= 0x550000u;
        }
      }
      if ( v5[6] == 0 )
        v9 |= 0xD000000u;
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, _DWORD, int *))(*(_DWORD *)this + 108))(
                 a1: this,
                 a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
                 a3: &v17,
                 a4: 0,
                 a5: &v15);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, _DWORD, int *, int))(*(_DWORD *)this + 112))(
                 a1: this,
                 a2: *(_DWORD *)(*((_DWORD *)this + 64) + 16),
                 a3: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a4: &v16,
                 a5: v15);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, unsigned int))(*(_DWORD *)this + 100))(
                 a1: this,
                 a2: v17,
                 a3: v16,
                 a4: v9);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                 a1: this,
                 a2: *(_DWORD *)(*((_DWORD *)this + 5)
                           + 4
                           * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8)
                                       + 4 * i * *(_DWORD *)(*((_DWORD *)this + 64) + 12))),
                 a3: &v17,
                 a4: &v14);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int, _DWORD, int, int *))(*(_DWORD *)this + 120))(
                 a1: this,
                 a2: *(_DWORD *)(*((_DWORD *)this + 64) + 8) + 4 * i * *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a3: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a4: v16,
                 a5: &v13);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                 a1: this,
                 a2: v17,
                 a3: v13,
                 a4: v14);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
      if ( result < 0 )
        return result;
      result = D3DXShader::CShaderProgram::ValidateInst(this);
      if ( result < 0 )
        return result;
      v4 = v12;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10225527
// Name: protected: long D3DXShader::CShaderProgram::EmitANDIF(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitANDIF(D3DXShader::CShaderProgram *this)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // ecx
  int v5; // edi
  int result; // eax
  int v7; // [esp-4h] [ebp-1Ch]
  int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  int v10; // [esp+14h] [ebp-4h] BYREF

  v2 = **((_DWORD **)this + 64);
  v3 = v2 & 0xFFF00000;
  v4 = 0;
  v5 = v2 & 0xFFFFF;
  if ( v3 != 1929379840 )
  {
    switch ( v3 )
    {
      case 0x73900000u:
        v7 = 3;
        goto LABEL_7;
      case 0x73A00000u:
        v7 = 4;
        goto LABEL_7;
      case 0x73B00000u:
        v7 = 5;
        goto LABEL_7;
      default:
        break;
    }
    if ( v3 != 1941962752 )
    {
LABEL_8:
      result = D3DXShader::CShaderProgram::EmitInst(this, a2: (v4 << 16) | 0x29);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                   a1: this,
                   a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 8)),
                   a3: &v8,
                   a4: &v10);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int, int, int *))(*(_DWORD *)this + 120))(
                     a1: this,
                     a2: *(_DWORD *)(*((_DWORD *)this + 64) + 8),
                     a3: v5,
                     a4: 983040,
                     a5: &v9);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                       a1: this,
                       a2: v8,
                       a3: v9,
                       a4: v10);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                         a1: this,
                         a2: *(_DWORD *)(*((_DWORD *)this + 5)
                                   + 4 * *(_DWORD *)(4 * v5 + *(_DWORD *)(*((_DWORD *)this + 64) + 8))),
                         a3: &v8,
                         a4: &v10);
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int, int *))(*(_DWORD *)this + 120))(
                           a1: this,
                           a2: 4 * v5 + *(_DWORD *)(*((_DWORD *)this + 64) + 8),
                           a3: v5,
                           a4: 983040,
                           a5: &v9);
                if ( result >= 0 )
                {
                  result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                             a1: this,
                             a2: v8,
                             a3: v9,
                             a4: v10);
                  if ( result >= 0 )
                  {
                    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
                    if ( result >= 0 )
                    {
                      result = D3DXShader::CShaderProgram::ValidateInst(this);
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
      return result;
    }
  }
  v7 = 2;
LABEL_7:
  v4 = v7;
  goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x10225682
// Name: protected: long D3DXShader::CShaderProgram::EmitANDIFBOOL(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitANDIFBOOL(D3DXShader::CShaderProgram *this, int a2)
{
  int result; // eax
  int v4; // [esp+4h] [ebp-8h] BYREF
  int v5; // [esp+8h] [ebp-4h] BYREF

  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x28u);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 8)),
               a3: &v4,
               a4: &v5);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                 a1: this,
                 a2: v4 | (a2 != 0 ? 0xD000000 : 0),
                 a3: 14942208,
                 a4: v5);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
        if ( result >= 0 )
        {
          result = D3DXShader::CShaderProgram::ValidateInst(this);
          if ( result >= 0 )
            return 0;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102256FC
// Name: protected: long D3DXShader::CShaderProgram::EmitANDELSE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitANDELSE(D3DXShader::CShaderProgram *this)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x2Au);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
    if ( result >= 0 )
    {
      result = D3DXShader::CShaderProgram::ValidateInst(this);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10225726
// Name: protected: long D3DXShader::CShaderProgram::EmitANDENDIF(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitANDENDIF(D3DXShader::CShaderProgram *this)
{
  int result; // eax

  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x2Bu);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
    if ( result >= 0 )
    {
      result = D3DXShader::CShaderProgram::ValidateInst(this);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10225750
// Name: protected: long D3DXShader::CShaderProgram::EmitNEG(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitNEG(D3DXShader::CShaderProgram *this)
{
  int result; // eax
  unsigned int v3; // eax
  int v4; // ecx
  int v5; // [esp+4h] [ebp-18h] BYREF
  int v6; // [esp+8h] [ebp-14h] BYREF
  int v7; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+10h] [ebp-Ch] BYREF
  int v9; // [esp+14h] [ebp-8h] BYREF
  unsigned int v10; // [esp+18h] [ebp-4h] BYREF

  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 1u);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, unsigned int *, int *, int *))(*(_DWORD *)this + 108))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
               a3: &v10,
               a4: &v5,
               a5: &v6);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, _DWORD, int *, int))(*(_DWORD *)this + 112))(
                 a1: this,
                 a2: *(_DWORD *)(*((_DWORD *)this + 64) + 16),
                 a3: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a4: &v9,
                 a5: v6);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int, int, int))(*(_DWORD *)this + 100))(
                   a1: this,
                   a2: v10,
                   a3: v9,
                   a4: v5);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, unsigned int *, int *))(*(_DWORD *)this + 116))(
                     a1: this,
                     a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 8)),
                     a3: &v10,
                     a4: &v8);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, _DWORD, int, int *))(*(_DWORD *)this + 120))(
                       a1: this,
                       a2: *(_DWORD *)(*((_DWORD *)this + 64) + 8),
                       a3: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                       a4: v9,
                       a5: &v7);
            if ( result >= 0 )
            {
              v3 = v10;
              if ( (v10 & 0xB000000) != 0 )
              {
                v4 = v7 | 0xC000000;
                v3 = v10 & 0xF4FFFFFF;
              }
              else
              {
                v4 = v7 | 0x1000000;
              }
              result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, unsigned int, int, int))(*(_DWORD *)this + 104))(
                         a1: this,
                         a2: v3,
                         a3: v4,
                         a4: v8);
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
                if ( result >= 0 )
                {
                  result = D3DXShader::CShaderProgram::ValidateInst(this);
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
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022585D
// Name: protected: long D3DXShader::CShaderProgram::EmitPOW(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitPOW(D3DXShader::CShaderProgram *this)
{
  unsigned int v2; // esi
  int result; // eax
  int i; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]

  v2 = **((_DWORD **)this + 64) & 0xFFFFF;
  v5 = 0;
  if ( v2 == 0 )
    return 0;
  for ( i = 4 * v2; ; i += 4 )
  {
    result = D3DXShader::CShaderProgram::EmitInstComplex(
               this,
               a2: 0x20u,
               a3: (unsigned int *)(4 * v5 + *(_DWORD *)(*((_DWORD *)this + 64) + 16)),
               a4: 1u,
               a5: (unsigned int *)(4 * v5 + *(_DWORD *)(*((_DWORD *)this + 64) + 8)),
               a6: (unsigned int *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + i),
               a7: nullptr,
               a8: v2,
               a9: 0,
               a10: 0,
               a11: 0,
               a12: 0);
    if ( result < 0 )
      break;
    if ( ++v5 >= v2 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102258CF
// Name: protected: long D3DXShader::CShaderProgram::EmitLRP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitLRP(D3DXShader::CShaderProgram *this)
{
  int v2; // ebx
  unsigned int v3; // eax
  int result; // eax
  _DWORD *v5; // edi
  int v6; // [esp+Ch] [ebp-20h] BYREF
  int v7; // [esp+10h] [ebp-1Ch] BYREF
  int v8; // [esp+14h] [ebp-18h] BYREF
  int v9; // [esp+18h] [ebp-14h] BYREF
  int v10; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int v11; // [esp+20h] [ebp-Ch]
  int v12; // [esp+24h] [ebp-8h]
  int v13; // [esp+28h] [ebp-4h] BYREF

  v2 = **((_DWORD **)this + 64) & 0xFFFFF;
  v3 = (*(int (__stdcall **)(int))(*(_DWORD *)this + 92))(a1: 18);
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: v3);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *, int *))(*(_DWORD *)this + 108))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
               a3: &v13,
               a4: &v8,
               a5: &v9);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int, int *, int))(*(_DWORD *)this + 112))(
                 a1: this,
                 a2: *(_DWORD *)(*((_DWORD *)this + 64) + 16),
                 a3: v2,
                 a4: &v10,
                 a5: v9);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 100))(
                   a1: this,
                   a2: v13,
                   a3: v10,
                   a4: v8);
        if ( result >= 0 )
        {
          v11 = 0;
          v12 = 0;
          while ( 1 )
          {
            v5 = (_DWORD *)(v12 + *(_DWORD *)(*((_DWORD *)this + 64) + 8));
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                       a1: this,
                       a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v5),
                       a3: &v13,
                       a4: &v7);
            if ( result < 0 )
              break;
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD *, int, int, int *))(*(_DWORD *)this + 120))(
                       a1: this,
                       a2: v5,
                       a3: v2,
                       a4: v10,
                       a5: &v6);
            if ( result < 0 )
              break;
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                       a1: this,
                       a2: v13,
                       a3: v6,
                       a4: v7);
            if ( result < 0 )
              break;
            ++v11;
            v12 += 4 * v2;
            if ( v11 >= 3 )
            {
              result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
              if ( result >= 0 )
              {
                result = D3DXShader::CShaderProgram::ValidateInst(this);
                if ( result >= 0 )
                  return 0;
              }
              return result;
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102259EA
// Name: protected: long D3DXShader::CShaderProgram::EmitNRM(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitNRM(D3DXShader::CShaderProgram *this)
{
  _DWORD *v2; // eax
  unsigned int *v3; // ecx
  unsigned int v4; // edi
  bool v5; // zf
  int result; // eax
  unsigned int v7[4]; // [esp+Ch] [ebp-14h] BYREF
  unsigned int *v8; // [esp+1Ch] [ebp-4h]

  v2 = *((_DWORD **)this + 64);
  v3 = (unsigned int *)v2[4];
  v4 = *v2 & 0xFFFFF;
  v5 = *((_DWORD *)this + 34) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v3) + 4);
  v8 = v3;
  if ( !v5 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, unsigned int *, unsigned int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
               a1: this,
               a2: *((_DWORD *)this + 63),
               a3: v7,
               a4: v4,
               a5: 0,
               a6: 0);
    if ( result < 0 )
      return result;
    v8 = v7;
    v3 = v7;
  }
  result = D3DXShader::CShaderProgram::EmitInstComplex(
             this,
             a2: 0x24u,
             a3: v3,
             a4: v4,
             a5: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
             a6: nullptr,
             a7: nullptr,
             a8: v4,
             a9: 0,
             a10: 0,
             a11: 0,
             a12: 0);
  if ( result >= 0 )
  {
    if ( v8 != v7 )
      return 0;
    result = D3DXShader::CShaderProgram::EmitInstComplex(
               this,
               a2: 1u,
               a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
               a4: v4,
               a5: v7,
               a6: nullptr,
               a7: nullptr,
               a8: v4,
               a9: 0,
               a10: 0,
               a11: 0,
               a12: 0);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10225A90
// Name: protected: long D3DXShader::CShaderProgram::EmitMAD(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitMAD(D3DXShader::CShaderProgram *this)
{
  int v2; // edi
  unsigned int v3; // eax
  int result; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // ebx
  int v7; // [esp+Ch] [ebp-20h] BYREF
  int v8; // [esp+10h] [ebp-1Ch] BYREF
  int v9; // [esp+14h] [ebp-18h] BYREF
  int v10; // [esp+18h] [ebp-14h] BYREF
  int v11; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+20h] [ebp-Ch] BYREF
  int v13; // [esp+24h] [ebp-8h] BYREF
  int v14; // [esp+28h] [ebp-4h]

  v2 = **((_DWORD **)this + 64) & 0xFFFFF;
  v3 = (*(int (__stdcall **)(int))(*(_DWORD *)this + 92))(a1: 4);
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: v3);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *, int *))(*(_DWORD *)this + 108))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
               a3: &v13,
               a4: &v9,
               a5: &v10);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int, int *, int))(*(_DWORD *)this + 112))(
                 a1: this,
                 a2: *(_DWORD *)(*((_DWORD *)this + 64) + 16),
                 a3: v2,
                 a4: &v12,
                 a5: v10);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 100))(
                   a1: this,
                   a2: v13,
                   a3: v12,
                   a4: v9);
        if ( result >= 0 )
        {
          v14 = 0;
          while ( 1 )
          {
            v5 = *((_DWORD **)this + 64);
            v6 = (_DWORD *)(v5[2] + 4 * v2 * v14);
            if ( v14 == 1 && (*v5 & 0xFFF00000) == 0x70400000 )
              v11 = 0x1000000;
            else
              v11 = 0;
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                       a1: this,
                       a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v6),
                       a3: &v13,
                       a4: &v8);
            if ( result < 0 )
              break;
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD *, int, int, int *))(*(_DWORD *)this + 120))(
                       a1: this,
                       a2: v6,
                       a3: v2,
                       a4: v12,
                       a5: &v7);
            if ( result < 0 )
              break;
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                       a1: this,
                       a2: v13 ^ v11,
                       a3: v7,
                       a4: v8);
            if ( result < 0 )
              break;
            if ( (unsigned int)++v14 >= 3 )
            {
              result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
              if ( result >= 0 )
              {
                result = D3DXShader::CShaderProgram::ValidateInst(this);
                if ( result >= 0 )
                  return 0;
              }
              return result;
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10225BCE
// Name: protected: long D3DXShader::CShaderProgram::EmitMAT(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitMAT(D3DXShader::CShaderProgram *this)
{
  int v2; // ecx
  int v3; // ebx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // eax
  int result; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // [esp-4h] [ebp-28h]
  unsigned int v13; // [esp+Ch] [ebp-18h] BYREF
  int v14; // [esp+10h] [ebp-14h] BYREF
  int v15; // [esp+14h] [ebp-10h] BYREF
  int v16; // [esp+18h] [ebp-Ch] BYREF
  int v17; // [esp+1Ch] [ebp-8h] BYREF
  int v18; // [esp+20h] [ebp-4h] BYREF

  v2 = **((_DWORD **)this + 64);
  v3 = v2 & 0xFFFFF;
  v4 = v2 - 1884291075;
  if ( v4 != 0 )
  {
    v5 = v4 - 0x100000;
    if ( v5 != 0 )
    {
      v6 = v5 - 1;
      if ( v6 != 0 )
      {
        v7 = v6 - 0xFFFFF;
        if ( v7 != 0 )
        {
          if ( v7 != 1 )
          {
            v8 = v13;
            goto LABEL_13;
          }
          v12 = 20;
        }
        else
        {
          v12 = 22;
        }
      }
      else
      {
        v12 = 21;
      }
    }
    else
    {
      v12 = 23;
    }
  }
  else
  {
    v12 = 24;
  }
  v8 = v12;
LABEL_13:
  result = D3DXShader::CShaderProgram::EmitInst(this, a2: v8);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, unsigned int *, int *))(*(_DWORD *)this + 108))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 16)),
               a3: &v18,
               a4: &v13,
               a5: &v14);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, _DWORD, int *, int))(*(_DWORD *)this + 112))(
                 a1: this,
                 a2: *(_DWORD *)(*((_DWORD *)this + 64) + 16),
                 a3: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a4: &v17,
                 a5: v14);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, unsigned int))(*(_DWORD *)this + 100))(
                   a1: this,
                   a2: v18,
                   a3: v17,
                   a4: v13);
        if ( result >= 0 )
        {
          v10 = *((_DWORD *)this + 5);
          v11 = *((_DWORD *)this + 64);
          v17 = v3 != 3 ? 983040 : 458752;
          result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                     a1: this,
                     a2: *(_DWORD *)(v10 + 4 * **(_DWORD **)(v11 + 8)),
                     a3: &v18,
                     a4: &v16);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int, int, int *))(*(_DWORD *)this + 120))(
                       a1: this,
                       a2: *(_DWORD *)(*((_DWORD *)this + 64) + 8),
                       a3: v3,
                       a4: v17,
                       a5: &v15);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                         a1: this,
                         a2: v18,
                         a3: v15,
                         a4: v16);
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                           a1: this,
                           a2: *(_DWORD *)(*((_DWORD *)this + 5)
                                     + 4 * *(_DWORD *)(4 * v3 + *(_DWORD *)(*((_DWORD *)this + 64) + 8))),
                           a3: &v18,
                           a4: &v16);
                if ( result >= 0 )
                {
                  result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int, int *))(*(_DWORD *)this + 120))(
                             a1: this,
                             a2: 4 * v3 + *(_DWORD *)(*((_DWORD *)this + 64) + 8),
                             a3: v3,
                             a4: v17,
                             a5: &v15);
                  if ( result >= 0 )
                  {
                    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                               a1: this,
                               a2: v18,
                               a3: v15,
                               a4: v16);
                    if ( result >= 0 )
                    {
                      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
                      if ( result >= 0 )
                      {
                        result = D3DXShader::CShaderProgram::ValidateInst(this);
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
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10225D80
// Name: protected: long D3DXShader::CShaderProgram::EmitInstSimple(unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitInstSimple(D3DXShader::CShaderProgram *this, unsigned int a2, int a3)
{
  D3DXShader::CInstruction *v4; // ecx
  int v5; // edi
  unsigned int v6; // edi
  unsigned int *v7; // edx
  int v8; // eax
  int v9; // ecx
  unsigned int *v11; // [esp+Ch] [ebp-20h] BYREF
  unsigned int *v12; // [esp+10h] [ebp-1Ch] BYREF
  unsigned int *v13; // [esp+14h] [ebp-18h] BYREF
  unsigned int *v14; // [esp+18h] [ebp-14h]
  unsigned int v15; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+20h] [ebp-Ch]
  unsigned int v17; // [esp+24h] [ebp-8h]
  unsigned int *v18; // [esp+28h] [ebp-4h]
  unsigned int i; // [esp+38h] [ebp+Ch]

  v4 = *((D3DXShader::CInstruction **)this + 64);
  v15 = *((_DWORD *)v4 + 3);
  v5 = *(_DWORD *)v4;
  v14 = *((unsigned int **)v4 + 4);
  v6 = v5 & 0xFFFFF;
  D3DXShader::CInstruction::GetInputs(this: v4, a2: 0, a3: &v11);
  D3DXShader::CInstruction::GetInputs(this: *((D3DXShader::CInstruction **)this + 64), a2: 1u, a3: &v12);
  D3DXShader::CInstruction::GetInputs(this: *((D3DXShader::CInstruction **)this + 64), a2: 2u, a3: &v13);
  v16 = 0;
  if ( a3 != 0 )
  {
    for ( i = 0; i < 3; ++i )
    {
      if ( v16 != 0 )
        break;
      v7 = (&v11)[i];
      if ( v7 != nullptr )
      {
        v17 = 0;
        if ( v6 != 0 )
        {
          v8 = *((_DWORD *)this + 5);
          v9 = 0;
          v18 = v7;
          while ( (*(_BYTE *)(v9 + *(_DWORD *)(v8 + 4 * *v18) + 3) & 1) == 0 )
          {
            ++v17;
            ++v18;
            v9 += 128;
            if ( v17 >= v6 )
              goto LABEL_11;
          }
          v16 = 1;
        }
      }
LABEL_11:
      ;
    }
  }
  return D3DXShader::CShaderProgram::EmitInstComplex(
           this,
           a2,
           a3: v14,
           a4: v15,
           a5: v11,
           a6: v12,
           a7: v13,
           a8: v6,
           a9: 0,
           a10: 0,
           a11: 0,
           a12: v16);
}

//------------------------------------------------------------------------------
// Address: 0x10225E59
// Name: protected: long D3DXShader::CShaderProgram::EmitInstScalar(unsigned long,unsigned int __near *,unsigned int __near *,unsigned int,unsigned int,unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitInstScalar(
        D3DXShader::CShaderProgram *this,
        unsigned int a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        int a8)
{
  int result; // eax
  unsigned int *v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  bool v14; // cf
  unsigned int v15; // ecx
  unsigned int i; // edi
  unsigned int v17; // eax
  unsigned int v18; // ecx
  int v19; // eax
  unsigned int v20; // edi
  unsigned int *v21; // ecx
  int v22; // eax
  _DWORD *v23; // ecx
  _DWORD v24[4]; // [esp+4h] [ebp-30h] BYREF
  unsigned int *v25[4]; // [esp+14h] [ebp-20h] BYREF
  unsigned int *v26; // [esp+24h] [ebp-10h]
  int v27; // [esp+28h] [ebp-Ch]
  BOOL v28; // [esp+2Ch] [ebp-8h]
  unsigned int v29; // [esp+30h] [ebp-4h]
  unsigned int v30; // [esp+4Ch] [ebp+18h]
  unsigned int v31; // [esp+4Ch] [ebp+18h]

  if ( a5 > a6 && a6 == 1 && **(_DWORD **)(*((_DWORD *)this + 64) + 8) == *a4 )
    return D3DXShader::CShaderProgram::EmitInstSimple(this, a2, a3: 0);
  v10 = a3;
  v11 = 4 * *a4;
  v12 = 4 * *a3;
  if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v12) + 4) == *(_DWORD *)(*(_DWORD *)(v11 + *((_DWORD *)this + 5))
                                                                              + 4)
    && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v12) + 8) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v11)
                                                                              + 8)
    && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v12) + 12) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v11)
                                                                               + 12) )
  {
    v13 = 0;
    v14 = a5 != 0;
    if ( a5 != 0 )
    {
      do
      {
        v30 = 0;
        if ( v13 != 0 )
        {
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a4[v13]) + 16) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3[v30])
                                                                                                 + 16) )
              break;
            ++v30;
          }
          while ( v30 < v13 );
          if ( v30 < v13 )
            break;
        }
        ++v13;
      }
      while ( v13 < a5 );
      v14 = v13 < a5;
    }
    v28 = v14;
    if ( v14 )
    {
      v15 = 0;
      for ( i = 0; v15 < a5; ++v15 )
      {
        v17 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3[v15]) + 16);
        if ( i <= v17 )
          i = v17 + 1;
      }
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, _DWORD *, unsigned int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
                 a1: this,
                 a2: *((_DWORD *)this + 63),
                 a3: v24,
                 a4: i,
                 a5: 0,
                 a6: 0);
      v18 = 0;
      if ( result < 0 )
        return result;
      if ( a5 != 0 )
      {
        v19 = *((_DWORD *)this + 5);
        do
        {
          v25[v18] = (unsigned int *)v24[*(_DWORD *)(*(_DWORD *)(v19
                                                               + 4
                                                               * *(_DWORD *)((char *)&v25[v18] + (char *)a3
                                                                                               - (char *)v25))
                                                   + 16)];
          ++v18;
        }
        while ( v18 < a5 );
      }
      v26 = a3;
      v10 = (unsigned int *)v25;
      a3 = (unsigned int *)v25;
    }
  }
  else
  {
    v28 = false;
  }
  v20 = 0;
  if ( a5 != 0 )
  {
    while ( 1 )
    {
      v31 = 1;
      if ( v20 + 1 < a5 )
      {
        v21 = &a4[v20];
        v22 = *((_DWORD *)this + 5);
        v27 = *(_DWORD *)(*(_DWORD *)(v22 + 4 * *v21) + 16);
        v29 = v20 + 1;
        v23 = v21 + 1;
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(v22 + 4 * *v23) + 16) != v27 )
            break;
          ++v31;
          ++v29;
          ++v23;
        }
        while ( v29 < a5 );
        v10 = a3;
      }
      result = D3DXShader::CShaderProgram::EmitInstComplex(
                 this,
                 a2,
                 a3: &v10[v20],
                 a4: v31,
                 a5: &a4[v20],
                 a6: nullptr,
                 a7: nullptr,
                 a8: v31,
                 a9: a7,
                 a10: a7,
                 a11: a7,
                 a12: 0);
      if ( result < 0 )
        break;
      v20 += v31;
      if ( v20 >= a5 )
        goto LABEL_34;
    }
  }
  else
  {
LABEL_34:
    if ( !v28 )
      return 0;
    result = D3DXShader::CShaderProgram::EmitInstComplex(
               this,
               a2: 1u,
               a3: v26,
               a4: a5,
               a5: v10,
               a6: nullptr,
               a7: nullptr,
               a8: a5,
               a9: 0,
               a10: 0,
               a11: 0,
               a12: 0);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10226058
// Name: protected: long D3DXShader::CShaderProgram::EmitLOOP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitLOOP(D3DXShader::CShaderProgram *this)
{
  int result; // eax
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h] BYREF

  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x26u);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
               a1: this,
               a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 8)),
               a3: &v3,
               a4: &v4);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                 a1: this,
                 a2: v3,
                 a3: 14942208,
                 a4: v4);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
        if ( result >= 0 )
        {
          result = D3DXShader::CShaderProgram::ValidateInst(this);
          if ( result >= 0 )
            return 0;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102260C2
// Name: protected: long D3DXShader::CShaderProgram::EmitLOOP_INC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitLOOP_INC(D3DXShader::CShaderProgram *this)
{
  int result; // eax
  int v3; // eax
  int v4; // [esp+4h] [ebp-8h] BYREF
  int v5; // [esp+8h] [ebp-4h] BYREF

  result = D3DXShader::CShaderProgram::EmitInst(this, a2: 0x1Bu);
  if ( result >= 0 )
  {
    v3 = *(_DWORD *)this;
    v5 = 0;
    result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, _DWORD))(v3 + 104))(
               a1: this,
               a2: -268433408,
               a3: 14942208,
               a4: 0);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, int *, int *))(*(_DWORD *)this + 116))(
                 a1: this,
                 a2: *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(*((_DWORD *)this + 64) + 8)),
                 a3: &v5,
                 a4: &v4);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, int, int, int))(*(_DWORD *)this + 104))(
                   a1: this,
                   a2: v5,
                   a3: 14942208,
                   a4: v4);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *))(*(_DWORD *)this + 96))(a1: this);
          if ( result >= 0 )
          {
            result = D3DXShader::CShaderProgram::ValidateInst(this);
            if ( result >= 0 )
              return 0;
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10226146
// Name: protected: long D3DXShader::CShaderProgram::EmitMOV(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitMOV(D3DXShader::CShaderProgram *this)
{
  int v1; // eax
  int v3; // eax
  _DWORD *v4; // edx
  int v5; // esi
  int v6; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // edx
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // edx
  _DWORD *v12; // esi
  int i; // [esp+4h] [ebp-Ch]
  unsigned int v14; // [esp+8h] [ebp-8h]
  unsigned int v15; // [esp+Ch] [ebp-4h]
  unsigned int j; // [esp+Ch] [ebp-4h]

  v1 = *((_DWORD *)this + 64);
  if ( *((_DWORD *)this + 35) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v1 + 16)) + 4) )
    return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0x2Eu, a3: 0);
  if ( (*((_BYTE *)this + 110) & 0x10) == 0 )
  {
    v15 = 0;
    v14 = *(_DWORD *)(v1 + 12);
    if ( v14 != 0 )
    {
      v3 = *((_DWORD *)this + 64);
      v4 = *(_DWORD **)(v3 + 16);
      v5 = *((_DWORD *)this + 5);
      v6 = *(_DWORD *)(v3 + 8) - (_DWORD)v4;
      v7 = v4;
      for ( i = v6; ; v6 = i )
      {
        v8 = *(_DWORD **)(v5 + 4 * *(_DWORD *)((char *)v7 + v6));
        v9 = *(_DWORD **)(v5 + 4 * *v7);
        if ( v9[1] != v8[1]
          || v9[2] != v8[2]
          || v9[3] != v8[3]
          || v9[4] != v8[4]
          || v9[15] != v8[15]
          || (*((_BYTE *)this + 204) & 4) != 0 && v9[24] != 0 )
        {
          break;
        }
        ++v15;
        ++v7;
        if ( v15 >= v14 )
          break;
      }
    }
    if ( v15 == v14 )
      return 0;
  }
  for ( j = 0; j < *(_DWORD *)(*((_DWORD *)this + 64) + 12); ++j )
  {
    v10 = *((_DWORD *)this + 64);
    v11 = *((_DWORD *)this + 5);
    v12 = *(_DWORD **)(v11 + 4 * *(_DWORD *)(*(_DWORD *)(v10 + 16) + 4 * j));
    if ( (*v12 & 0xE000000) == 0 )
      *v12 |= **(_DWORD **)(v11 + 4 * *(_DWORD *)(*(_DWORD *)(v10 + 8) + 4 * j)) & 0xE000000;
  }
  return D3DXShader::CShaderProgram::EmitInstComplex(
           this,
           a2: 1u,
           a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
           a4: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
           a5: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
           a6: nullptr,
           a7: nullptr,
           a8: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
           a9: 0,
           a10: 0,
           a11: 0,
           a12: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1022627F
// Name: protected: long D3DXShader::CShaderProgram::EmitDSX(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitDSX(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0x5Bu, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10226289
// Name: protected: long D3DXShader::CShaderProgram::EmitDSY(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitDSY(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0x5Cu, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10226293
// Name: protected: long D3DXShader::CShaderProgram::EmitRCP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitRCP(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstScalar(
           this,
           a2: 6u,
           a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
           a4: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
           a5: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
           a6: *(_DWORD *)(*((_DWORD *)this + 64) + 4),
           a7: 0,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102262B1
// Name: protected: long D3DXShader::CShaderProgram::EmitFRC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitFRC(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0x13u, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102262BB
// Name: protected: long D3DXShader::CShaderProgram::EmitEXP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitEXP(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstScalar(
           this,
           a2: 0xEu,
           a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
           a4: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
           a5: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
           a6: *(_DWORD *)(*((_DWORD *)this + 64) + 4),
           a7: 0,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102262D9
// Name: protected: long D3DXShader::CShaderProgram::EmitLOG(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitLOG(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstScalar(
           this,
           a2: 0xFu,
           a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
           a4: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
           a5: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
           a6: *(_DWORD *)(*((_DWORD *)this + 64) + 4),
           a7: 0,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102262F7
// Name: protected: long D3DXShader::CShaderProgram::EmitRSQ(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitRSQ(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstScalar(
           this,
           a2: 7u,
           a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
           a4: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
           a5: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
           a6: *(_DWORD *)(*((_DWORD *)this + 64) + 4),
           a7: 0,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10226315
// Name: protected: long D3DXShader::CShaderProgram::EmitMIN(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitMIN(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0xAu, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1022631F
// Name: protected: long D3DXShader::CShaderProgram::EmitMAX(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitMAX(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0xBu, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10226329
// Name: protected: long D3DXShader::CShaderProgram::EmitLT(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitLT(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0xCu, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10226333
// Name: protected: long D3DXShader::CShaderProgram::EmitGE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitGE(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0xDu, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1022633D
// Name: protected: long D3DXShader::CShaderProgram::EmitADD(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitADD(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 2u, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10226347
// Name: protected: long D3DXShader::CShaderProgram::EmitMUL(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitMUL(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 5u, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10226351
// Name: protected: long D3DXShader::CShaderProgram::EmitDST(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitDST(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0x11u, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1022635B
// Name: protected: long D3DXShader::CShaderProgram::EmitDOT(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitDOT(D3DXShader::CShaderProgram *this)
{
  int result; // eax
  unsigned int v3; // [esp+8h] [ebp-8h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-4h] BYREF

  switch ( **((_DWORD **)this + 64) & 0xFFFFF )
  {
    case 1:
      return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 5u, a3: 0);
    case 3:
      return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 8u, a3: 0);
    case 4:
      return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 9u, a3: 0);
    default:
      break;
  }
  result = (*(int (__thiscall **)(D3DXShader::CShaderProgram *, _DWORD, unsigned int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             a1: this,
             a2: *((_DWORD *)this + 63),
             a3: &v3,
             a4: 2,
             a5: 0,
             a6: 0);
  if ( result >= 0 )
  {
    result = D3DXShader::CShaderProgram::EmitInstComplex(
               this,
               a2: 5u,
               a3: &v3,
               a4: 2u,
               a5: *(unsigned int **)(*((_DWORD *)this + 64) + 8),
               a6: (unsigned int *)(*(_DWORD *)(*((_DWORD *)this + 64) + 8) + 8),
               a7: nullptr,
               a8: 2u,
               a9: 0,
               a10: 0,
               a11: 0,
               a12: 0);
    if ( result >= 0 )
    {
      result = D3DXShader::CShaderProgram::EmitInstComplex(
                 this,
                 a2: 2u,
                 a3: *(unsigned int **)(*((_DWORD *)this + 64) + 16),
                 a4: *(_DWORD *)(*((_DWORD *)this + 64) + 12),
                 a5: &v3,
                 a6: &v4,
                 a7: nullptr,
                 a8: 1u,
                 a9: 0,
                 a10: 0,
                 a11: 0,
                 a12: 0);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022640E
// Name: protected: long D3DXShader::CShaderProgram::EmitLIT(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitLIT(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0x10u, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10226418
// Name: protected: long D3DXShader::CShaderProgram::EmitCMP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitCMP(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0x58u, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10226422
// Name: protected: long D3DXShader::CShaderProgram::EmitCND(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitCND(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0x50u, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1022642C
// Name: protected: long D3DXShader::CShaderProgram::EmitABS(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CShaderProgram::EmitABS(D3DXShader::CShaderProgram *this)
{
  return D3DXShader::CShaderProgram::EmitInstSimple(this, a2: 0x23u, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10226436
// Name: public: D3DXShader::CArgument::CArgument(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CArgument *__thiscall D3DXShader::CArgument::CArgument(D3DXShader::CArgument *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10226439
// Name: public: long D3DXShader::CPool::Initialize(char const __near *,unsigned long,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPool::Initialize(
        D3DXShader::CPool *this,
        const char *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  unsigned int v5; // eax

  v5 = a5;
  if ( a5 > 4 )
    v5 = 4;
  *((_DWORD *)this + 6) = -1;
  *((_DWORD *)this + 9) = -1;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 3) = v5;
  *((_DWORD *)this + 10) = -1;
  *((_DWORD *)this + 2) = a4;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10226481
// Name: public: long D3DXShader::CPool::Initialize(class D3DXShader::CPool __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPool::Initialize(D3DXShader::CPool *this, struct D3DXShader::CPool *a2)
{
  if ( a2 == nullptr )
    return -2147467259;
  *(_DWORD *)this = *(_DWORD *)a2;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)this + 4) = *((_DWORD *)a2 + 4);
  *((_DWORD *)this + 5) = *((_DWORD *)a2 + 5);
  *((_DWORD *)this + 6) = *((_DWORD *)a2 + 6);
  *((_DWORD *)this + 7) = *((_DWORD *)a2 + 7);
  *((_DWORD *)this + 8) = *((_DWORD *)a2 + 8);
  *((_DWORD *)this + 9) = *((_DWORD *)a2 + 9);
  *((_DWORD *)this + 10) = *((_DWORD *)a2 + 10);
  *((_DWORD *)this + 11) = *((_DWORD *)a2 + 11);
  *((_DWORD *)this + 12) = *((_DWORD *)a2 + 12);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102264E6
// Name: protected: void D3DXShader::CTReorderInstructions::Read(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CTReorderInstructions::Read(
        D3DXShader::CTReorderInstructions *this,
        unsigned int a2,
        unsigned int a3)
{
  unsigned int v4; // esi
  _DWORD *v5; // eax
  int v6; // edi
  unsigned int v7; // eax

  v4 = a2;
  while ( 1 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 1) + 20) + 4 * a3);
      if ( v5[14] == -1 )
        break;
      a3 = v5[14];
    }
    v5[12] = -1;
    v6 = v5[1];
    v5[29] = v4;
    if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 16) + 4 * v6) + 4) & 0x10) == 0 )
    {
      if ( *((_DWORD *)this + 4) != 0 )
      {
        *(_DWORD *)(*((_DWORD *)this + 4)
                  + 4 * (*(_DWORD *)(*((_DWORD *)this + 2) + 4 * v4) + *(_DWORD *)(*((_DWORD *)this + 3) + 4 * v4))) = a3;
        v4 = a2;
      }
      ++*(_DWORD *)(*((_DWORD *)this + 2) + 4 * v4);
    }
    v7 = v5[2];
    if ( v7 == -1 )
      break;
    a3 = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022655B
// Name: protected: void D3DXShader::CTReorderInstructions::Write(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CTReorderInstructions::Write(
        D3DXShader::CTReorderInstructions *this,
        unsigned int a2,
        unsigned int a3)
{
  int v3; // eax
  _DWORD *v4; // edx
  unsigned int v5; // esi
  int v6; // eax
  unsigned int v7; // edx

  v3 = *((_DWORD *)this + 1);
  v4 = *(_DWORD **)(*(_DWORD *)(v3 + 20) + 4 * a3);
  v5 = a2;
  if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v3 + 16) + 4 * v4[1]) + 4) & 0x20) == 0 && v4[23] != 0 )
  {
    v6 = *((_DWORD *)this + 9);
    if ( v6 != 0 )
    {
      *(_DWORD *)(v6 + 4 * (*(_DWORD *)(*((_DWORD *)this + 7) + 4 * a2) + *(_DWORD *)(*((_DWORD *)this + 8) + 4 * a2))) = a3;
      v5 = a2;
    }
    ++*(_DWORD *)(*((_DWORD *)this + 7) + 4 * v5);
  }
  v7 = v4[5];
  if ( v7 != -1 )
    D3DXShader::CTReorderInstructions::Read(this, a2: v5, a3: v7);
}

//------------------------------------------------------------------------------
// Address: 0x102265C4
// Name: protected: void D3DXShader::CTReorderInstructions::ReverseInsts(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CTReorderInstructions::ReverseInsts(
        D3DXShader::CTReorderInstructions *this,
        unsigned int a2,
        unsigned int a3)
{
  unsigned int v3; // edi
  unsigned int v4; // eax
  int v5; // edx
  int v6; // ebx
  unsigned int v7; // [esp+10h] [ebp+Ch]

  if ( (a3 - a2) >> 1 != 0 )
  {
    v3 = 4 * a2;
    v4 = 4 * a3 - 4;
    v7 = (a3 - a2) >> 1;
    do
    {
      v5 = *((_DWORD *)this + 15);
      v6 = *(_DWORD *)(v3 + v5);
      *(_DWORD *)(v3 + v5) = *(_DWORD *)(v4 + v5);
      *(_DWORD *)(v4 + *((_DWORD *)this + 15)) = v6;
      v3 += 4;
      v4 -= 4;
      --v7;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022660E
// Name: protected: static int D3DXShader::CTReorderInstructions::CompareLoad(unsigned int,unsigned int,void const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static int __stdcall D3DXShader::CTReorderInstructions::CompareLoad(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // eax

  v3 = a3[15];
  v4 = *(_DWORD *)(v3 + 4 * a1);
  v5 = *(_DWORD *)(v3 + 4 * a2);
  if ( *(_DWORD *)(a3[11] + 4 * v4) > *(_DWORD *)(a3[11] + 4 * v5) )
    return -1;
  if ( *(_DWORD *)(a3[11] + 4 * v4) < *(_DWORD *)(a3[11] + 4 * v5) )
    return 1;
  if ( v5 > v4 )
    return -1;
  return v5 < v4;
}

//------------------------------------------------------------------------------
// Address: 0x10226655
// Name: protected: void D3DXShader::CTReorderInstructions::RemoveDuplicates(unsigned int __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge D3DXShader::CTReorderInstructions::RemoveDuplicates(
        const void *a1@<esi>,
        int (__stdcall *a2)(unsigned int, unsigned int, const void *),
        unsigned int *a3)
{
  unsigned int v4; // ecx
  unsigned int i; // edx
  unsigned int v6; // eax

  if ( *a3 > 1 )
  {
    D3DXShader::HeapSort(
      this: (D3DXShader *)D3DXShader::CTReorderInstructions::CompareIndex,
      a2,
      a3: (unsigned int *)*a3,
      a4: 0,
      a5: a1);
    v4 = 1;
    for ( i = 1; v4 < *a3; ++v4 )
    {
      v6 = *((_DWORD *)a2 + v4);
      if ( v6 != *((_DWORD *)a2 + v4 - 1) )
        *((_DWORD *)a2 + i++) = v6;
    }
    *a3 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022669B
// Name: protected: void D3DXShader::CTReorderInstructions::RecalculateLoad(unsigned int __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CTReorderInstructions::RecalculateLoad(
        D3DXShader::CTReorderInstructions *this,
        unsigned int *a2,
        unsigned int *a3)
{
  unsigned int v3; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // esi
  int v7; // edi
  int v8; // esi
  unsigned int v9; // edi
  unsigned int v10; // [esp+4h] [ebp-18h]
  unsigned int v11; // [esp+4h] [ebp-18h]
  unsigned int v12; // [esp+8h] [ebp-14h]
  unsigned int j; // [esp+8h] [ebp-14h]
  unsigned int v14; // [esp+Ch] [ebp-10h]
  unsigned int v15; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  unsigned int v17; // [esp+18h] [ebp-4h]

  v3 = 0;
  v10 = 0;
  v15 = 0;
  v14 = 0;
  for ( i = 0; i < *((_DWORD *)this + 14); ++i )
  {
    v4 = *(_DWORD *)(*((_DWORD *)this + 15) + 4 * i);
    v5 = 4 * v4;
    v6 = *(_DWORD *)(4 * v4 + *(_DWORD *)(*((_DWORD *)this + 1) + 24));
    *(_DWORD *)(v5 + *((_DWORD *)this + 11)) = v3;
    *(_DWORD *)(v5 + *((_DWORD *)this + 10)) = 0;
    if ( (*(_WORD *)(v6 + 2) & 0xFFF0) != 0 )
    {
      v17 = 0;
      v7 = *((_DWORD *)this + 4) + 4 * *(_DWORD *)(v5 + *((_DWORD *)this + 3));
      v12 = *(_DWORD *)(v5 + *((_DWORD *)this + 2));
      if ( v12 != 0 )
      {
        do
        {
          if ( v4 == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 20) + 4 * *(_DWORD *)(v7 + 4 * v17))
                               + 88) )
            --*(_DWORD *)(v5 + *((_DWORD *)this + 10));
          ++v17;
        }
        while ( v17 < v12 );
        v3 = v10;
      }
      v8 = *((_DWORD *)this + 9) + 4 * *(_DWORD *)(v5 + *((_DWORD *)this + 8));
      v9 = 0;
      v11 = *(_DWORD *)(v5 + *((_DWORD *)this + 7));
      for ( j = 0; j < v11; ++j )
      {
        if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 20) + 4 * *(_DWORD *)(v8 + 4 * v9)) + 92) != 0 )
          ++*(_DWORD *)(v5 + *((_DWORD *)this + 10));
        v9 = j + 1;
      }
      v15 += v3;
      if ( v3 > v14 )
        v14 = v3;
      v3 += *(_DWORD *)(*((_DWORD *)this + 10) + 4 * v4);
      v10 = v3;
    }
  }
  if ( a2 != nullptr )
    *a2 = v15;
  if ( a3 != nullptr )
    *a3 = v14;
}

//------------------------------------------------------------------------------
// Address: 0x102267B8
// Name: protected: long D3DXShader::CTReorderInstructions::Bubble(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTReorderInstructions::Bubble(D3DXShader::CTReorderInstructions *this, unsigned int a2)
{
  int v3; // edx
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  int v9; // esi
  int v10; // ecx
  void *v11; // edi
  int v12; // esi
  const void *v13; // esi
  unsigned int i; // eax
  _DWORD *v15; // eax
  unsigned int j; // ecx
  int v17; // esi
  unsigned int k; // ecx
  int v19; // esi
  int v20; // esi
  _DWORD *v21; // eax
  bool v22; // cf
  unsigned int v23; // esi
  unsigned int v24; // edx
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  int v28; // edi
  int v29; // edx
  int v30; // edi
  int v31; // edx
  int v32; // edi
  _DWORD *v33; // esi
  int v34; // esi
  unsigned int v35; // esi
  int v36; // ecx
  int v37; // edi
  int v38; // ecx
  int v39; // ecx
  _DWORD *v40; // eax
  unsigned int m; // esi
  unsigned int v42; // esi
  int v43; // eax
  int v44; // ecx
  _DWORD *v45; // eax
  unsigned int v46; // edi
  unsigned int v47; // esi
  unsigned int v48; // esi
  int v49; // eax
  int v50; // eax
  unsigned int v51; // edi
  char *v52; // esi
  unsigned int v53; // edx
  _DWORD *v54; // eax
  unsigned int ii; // ecx
  int v56; // esi
  unsigned int jj; // ecx
  int v58; // esi
  D3DXShader::CTReorderInstructions *v59; // ecx
  D3DXShader::CTReorderInstructions *v60; // ecx
  D3DXShader::CTReorderInstructions *v61; // ecx
  unsigned int v62; // eax
  bool v63; // cc
  unsigned int v64; // eax
  int v66; // [esp+Ch] [ebp-54h]
  unsigned int v67; // [esp+10h] [ebp-50h] BYREF
  int v68; // [esp+14h] [ebp-4Ch]
  _DWORD *v69; // [esp+18h] [ebp-48h]
  int v70; // [esp+1Ch] [ebp-44h]
  int v71; // [esp+20h] [ebp-40h]
  unsigned int v72; // [esp+24h] [ebp-3Ch] BYREF
  unsigned int v73; // [esp+28h] [ebp-38h]
  int v74; // [esp+2Ch] [ebp-34h]
  unsigned int v75; // [esp+30h] [ebp-30h]
  unsigned int v76; // [esp+34h] [ebp-2Ch]
  int v77; // [esp+38h] [ebp-28h]
  int v78; // [esp+3Ch] [ebp-24h]
  unsigned int v79; // [esp+40h] [ebp-20h] BYREF
  int v80; // [esp+44h] [ebp-1Ch]
  int v81; // [esp+48h] [ebp-18h]
  unsigned int v82; // [esp+4Ch] [ebp-14h] BYREF
  unsigned int n; // [esp+50h] [ebp-10h]
  unsigned int v84; // [esp+54h] [ebp-Ch]
  unsigned int v85; // [esp+58h] [ebp-8h]
  int v86; // [esp+5Ch] [ebp-4h]
  unsigned int v87; // [esp+68h] [ebp+8h]
  unsigned int v88; // [esp+68h] [ebp+8h]

  v71 = 0;
  v84 = a2 + 1;
  v3 = *(_DWORD *)(*((_DWORD *)this + 15) + 4 * a2);
  v4 = *((_DWORD *)this + 1);
  v5 = *(_DWORD *)(v4 + 24);
  n = a2;
  v6 = 4 * v3;
  v7 = *(_DWORD *)(4 * v3 + v5);
  v66 = v3;
  if ( *(_DWORD *)(4 * v3 + *((_DWORD *)this + 13)) == 0 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v4 + 20) + 4 * **(_DWORD **)(v7 + 16));
    v9 = *(_DWORD *)(v8 + 20);
    v10 = *(_DWORD *)(v8 + 24);
    v11 = *((void **)this + 5);
    v78 = v9;
    v12 = *((_DWORD *)this + 3);
    v74 = v10;
    v13 = (const void *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v6 + v12));
    v82 = *(_DWORD *)(v6 + *((_DWORD *)this + 2));
    qmemcpy(v11, v13, 4 * v82);
LABEL_3:
    v86 = 0;
    ++*((_DWORD *)this + 18);
    for ( i = n; ; i = v87 + 1 )
    {
      v87 = i;
      if ( i >= v84 )
        break;
      v15 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 1) + 24) + 4 * *(_DWORD *)(*((_DWORD *)this + 15) + 4 * i));
      for ( j = 0; j < v15[5]; *(_DWORD *)(v17 + 36) = *((_DWORD *)this + 18) )
        v17 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 24) + 4 * *(_DWORD *)(v15[6] + 4 * j++));
      for ( k = 0; k < v15[7]; *(_DWORD *)(v19 + 36) = *((_DWORD *)this + 18) )
        v19 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 24) + 4 * *(_DWORD *)(v15[8] + 4 * k++));
      v86 += *(_DWORD *)(*((_DWORD *)this + 10) + 4 * *(_DWORD *)(*((_DWORD *)this + 15) + 4 * v87));
    }
    v20 = 0;
    if ( v82 != 0 )
    {
      do
      {
        v21 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 1) + 20) + 4 * v20);
        v21[12] = *((_DWORD *)this + 18);
        v22 = ++v20 < v82;
        v21[21] = v3 == v21[29];
      }
      while ( v22 );
    }
    while ( 1 )
    {
      if ( v86 >= 0 )
      {
        if ( v86 <= 0 )
          goto LABEL_84;
        v23 = v84 - 1;
        v85 = v84;
        v88 = v84;
        v77 = 1;
      }
      else
      {
        v23 = n;
        v77 = -1;
        v85 = n;
        v88 = n;
      }
      v24 = 0;
      v79 = 0;
      v80 = 0;
      v81 = 0;
      while ( 1 )
      {
        v35 = v77 + v23;
        v22 = v35 < *((_DWORD *)this + 14);
        v73 = v35;
        if ( !v22 )
          break;
        v25 = *((_DWORD *)this + 13);
        v70 = *(_DWORD *)(*((_DWORD *)this + 15) + 4 * v35);
        v26 = 4 * v70;
        if ( *(_DWORD *)(4 * v70 + v25) == 0 )
        {
          v27 = *((_DWORD *)this + 1);
          v28 = *(_DWORD *)(*(_DWORD *)(v27 + 20) + 4 * **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(v27 + 24) + 4 * v70) + 16));
          v29 = *(_DWORD *)(v28 + 20);
          v68 = v28;
          v30 = *(_DWORD *)(v28 + 24);
          while ( v29 != -1 )
          {
            if ( v78 == v29 )
              goto LABEL_23;
            v31 = *(_DWORD *)(*(_DWORD *)(v27 + 20) + 4 * v29);
            v30 = *(_DWORD *)(v31 + 24);
            v29 = *(_DWORD *)(v31 + 20);
          }
          if ( v78 != -1 )
            goto LABEL_84;
LABEL_23:
          if ( v74 != v30 )
            goto LABEL_84;
          v24 = v79;
        }
        if ( v85 > v35 )
          v85 = v35;
        if ( v88 <= v35 )
          v88 = v35 + 1;
        v32 = *((_DWORD *)this + 6);
        v33 = (_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v26 + *((_DWORD *)this + 3)));
        v75 = *(_DWORD *)(v26 + *((_DWORD *)this + 2));
        v69 = v33;
        qmemcpy((void *)(v32 + 4 * v24), v33, 4 * v75);
        v24 += *(_DWORD *)(v26 + *((_DWORD *)this + 2));
        v80 += *(_DWORD *)(*((_DWORD *)this + 10) + v26);
        v34 = *((_DWORD *)this + 18) - *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 24) + v26) + 36);
        v79 = v24;
        v35 = v34 == 0;
        v81 |= v35;
        v36 = 0;
        v76 = 0;
        if ( v75 != 0 )
        {
          v37 = v70;
          do
          {
            v35 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 20) + 4 * v69[v36]);
            v38 = *((_DWORD *)this + 18);
            if ( *(_DWORD *)(v35 + 48) != v38 || v37 == *(_DWORD *)(v35 + 116) )
            {
              *(_DWORD *)(v35 + 48) = v38;
              *(_DWORD *)(v35 + 84) = (v37 != *(_DWORD *)(v35 + 116)) - 1;
            }
            v36 = ++v76;
          }
          while ( v76 < v75 );
        }
        if ( *(_DWORD *)(v26 + *((_DWORD *)this + 13)) == 0
          && v78 == *(_DWORD *)(v68 + 20)
          && v74 == *(_DWORD *)(v68 + 24) )
        {
          break;
        }
        v23 = v73;
      }
      if ( v85 >= v88 )
      {
LABEL_84:
        if ( v71 != 0 )
        {
          qmemcpy(*((void **)this + 15), *((const void **)this + 16), 4 * *((_DWORD *)this + 14));
          D3DXShader::CTReorderInstructions::RecalculateLoad(this, a2: nullptr, a3: nullptr);
        }
        return 1;
      }
      if ( v85 + 1 < v88 )
      {
        D3DXShader::CTReorderInstructions::RemoveDuplicates(
          a1: (const void *)v35,
          a2: *((int (__stdcall **)(unsigned int, unsigned int, const void *))this + 6),
          a3: &v79);
        v24 = v79;
      }
      if ( v81 == 0 )
      {
        if ( v86 >= 0 )
        {
          v42 = v82;
          v43 = v86;
          v77 = v86;
          if ( v82 != 0 )
          {
            v44 = *(_DWORD *)(*((_DWORD *)this + 1) + 20);
            v45 = *((_DWORD **)this + 5);
            do
            {
              if ( *(_DWORD *)(*(_DWORD *)(v44 + 4 * *v45) + 84) == -1 )
                --v77;
              ++v45;
              --v42;
            }
            while ( v42 != 0 );
            v43 = v77;
          }
          if ( v43 < v80 )
LABEL_59:
            v81 = 1;
        }
        else
        {
          v77 = v80;
          if ( v24 != 0 )
          {
            v39 = *(_DWORD *)(*((_DWORD *)this + 1) + 20);
            v40 = *((_DWORD **)this + 6);
            for ( m = v24; m != 0; --m )
            {
              if ( *(_DWORD *)(*(_DWORD *)(v39 + 4 * *v40) + 84) == 1 )
                --v77;
              ++v40;
            }
          }
          if ( v86 > v77 )
            goto LABEL_59;
        }
      }
      v46 = n;
      if ( n >= v85 )
        v46 = v85;
      v47 = v84;
      if ( v84 <= v88 )
        v47 = v88;
      if ( v81 == 0 )
      {
        D3DXShader::CTReorderInstructions::ReverseInsts(this, a2: n, a3: v84);
        D3DXShader::CTReorderInstructions::ReverseInsts(this: v59, a2: v85, a3: v88);
        D3DXShader::CTReorderInstructions::ReverseInsts(this: v60, a2: v46, a3: v47);
        D3DXShader::CTReorderInstructions::RecalculateLoad(this: v61, a2: &v72, a3: &v67);
        v62 = *((_DWORD *)this + 20);
        v63 = v72 <= v62;
        if ( v72 < v62 )
        {
          if ( v67 > *((_DWORD *)this + 19) )
          {
            v63 = v72 <= v62;
            goto LABEL_77;
          }
          return 0;
        }
LABEL_77:
        if ( v63 && v67 < *((_DWORD *)this + 19) )
          return 0;
        if ( v86 >= 0 )
          v64 = v88 - v85;
        else
          v64 = v85 - v88;
        n += v64;
        v84 += v64;
        v3 = v66;
        v71 = 1;
        goto LABEL_3;
      }
      v84 = v47;
      v48 = 0;
      for ( n = v46; v48 < v24; *(_DWORD *)(v49 + 84) = *(_DWORD *)(v49 + 84) != 0 )
        v49 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 20) + 4 * *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v48++));
      v50 = *((_DWORD *)this + 5);
      v51 = v82;
      v52 = *((char **)this + 6);
      v82 += v24;
      v86 += v80;
      qmemcpy((void *)(v50 + 4 * v51), v52, 4 * v24);
      D3DXShader::CTReorderInstructions::RemoveDuplicates(
        a1: &v52[4 * v24],
        a2: *((int (__stdcall **)(unsigned int, unsigned int, const void *))this + 5),
        a3: &v82);
      v53 = v85;
      do
      {
        v54 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 1) + 24) + 4 * *(_DWORD *)(*((_DWORD *)this + 15) + 4 * v53));
        for ( ii = 0; ii < v54[5]; *(_DWORD *)(v56 + 36) = *((_DWORD *)this + 18) )
          v56 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 24) + 4 * *(_DWORD *)(v54[6] + 4 * ii++));
        for ( jj = 0; jj < v54[7]; *(_DWORD *)(v58 + 36) = *((_DWORD *)this + 18) )
          v58 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 24) + 4 * *(_DWORD *)(v54[8] + 4 * jj++));
        ++v53;
      }
      while ( v53 < v88 );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10226C4A
// Name: protected: long D3DXShader::CTReorderInstructions::Reduce(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTReorderInstructions::Reduce(D3DXShader::CTReorderInstructions *this)
{
  unsigned int i; // eax
  int v3; // edi
  int result; // eax
  const void *v5; // [esp+0h] [ebp-8h]

  D3DXShader::CTReorderInstructions::RecalculateLoad(this, a2: (unsigned int *)this + 20, a3: (unsigned int *)this + 19);
  for ( i = 0; i < *((_DWORD *)this + 14); ++i )
  {
    *(_DWORD *)(*((_DWORD *)this + 12) + 4 * i) = i;
    *(_DWORD *)(*((_DWORD *)this + 16) + 4 * i) = *(_DWORD *)(*((_DWORD *)this + 15) + 4 * i);
  }
  D3DXShader::HeapSort(
    this: (D3DXShader *)D3DXShader::CTReorderInstructions::CompareLoad,
    a2: *((int (__stdcall **)(unsigned int, unsigned int, const void *))this + 12),
    a3: *((unsigned int **)this + 14),
    a4: (unsigned int)this,
    a5: v5);
  v3 = 0;
  if ( *((_DWORD *)this + 14) == 0 )
    return 1;
  while ( 1 )
  {
    result = D3DXShader::CTReorderInstructions::Bubble(this, a2: *(_DWORD *)(*((_DWORD *)this + 12) + 4 * v3));
    if ( result < 0 )
      break;
    if ( result == 0 )
      return 0;
    if ( (unsigned int)++v3 >= *((_DWORD *)this + 14) )
      return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10226CB7
// Name: public: virtual long D3DXShader::CTReorderInstructions::Apply(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTReorderInstructions::Apply(D3DXShader::CTReorderInstructions *this, int a2)
{
  unsigned int v2; // ebx
  D3DXShader::CProgram *v4; // ecx
  void *v5; // eax
  void *v6; // eax
  int v7; // edi
  void *v8; // eax
  void *v9; // eax
  int v10; // ecx
  int v11; // edi
  unsigned int v12; // edx
  int v13; // eax
  void *v14; // eax
  void *v15; // eax
  void *v16; // eax
  void *v17; // eax
  int v18; // edi
  void *v19; // eax
  void *v20; // eax
  void *v21; // eax
  void *v22; // eax
  int v23; // edi
  int v24; // ecx
  int IsFlowControl; // eax
  int v26; // edi
  void *v27; // eax
  void *v28; // eax
  void *v29; // eax
  int result; // eax
  unsigned int k; // eax
  unsigned int v32; // [esp-4h] [ebp-18h]
  unsigned int nSize; // [esp+Ch] [ebp-8h]
  unsigned int nSizea; // [esp+Ch] [ebp-8h]
  int nSizeb; // [esp+Ch] [ebp-8h]
  unsigned int nSizec; // [esp+Ch] [ebp-8h]
  unsigned int nSized; // [esp+Ch] [ebp-8h]
  unsigned int nSizee; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]
  unsigned int j; // [esp+10h] [ebp-4h]

  v2 = 0;
  v4 = *((D3DXShader::CProgram **)this + 1);
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 14) = *((_DWORD *)v4 + 3);
  D3DXShader::CProgram::ReadWriteInfo(this: v4);
  v5 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 14));
  *((_DWORD *)this + 2) = v5;
  if ( v5 != nullptr )
  {
    v6 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 14));
    *((_DWORD *)this + 7) = v6;
    if ( v6 != nullptr )
    {
      memset(*((void **)this + 2), 0, 4 * *((_DWORD *)this + 14));
      memset(*((void **)this + 7), 0, 4 * *((_DWORD *)this + 14));
      for ( i = 0; i < *((_DWORD *)this + 14); ++i )
      {
        v7 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 24) + 4 * i);
        if ( (*(_WORD *)(v7 + 2) & 0xFFF0) != 0 )
        {
          for ( nSize = 0; nSize < *(_DWORD *)(v7 + 12); ++nSize )
            D3DXShader::CTReorderInstructions::Write(this, a2: i, a3: *(_DWORD *)(*(_DWORD *)(v7 + 16) + 4 * nSize));
          for ( nSizea = 0; nSizea < *(_DWORD *)(v7 + 4); ++nSizea )
            D3DXShader::CTReorderInstructions::Read(this, a2: i, a3: *(_DWORD *)(*(_DWORD *)(v7 + 8) + 4 * nSizea));
        }
      }
      v8 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 14));
      *((_DWORD *)this + 3) = v8;
      if ( v8 != nullptr )
      {
        v9 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 14));
        *((_DWORD *)this + 8) = v9;
        if ( v9 != nullptr )
        {
          v10 = 0;
          v11 = 0;
          v12 = 0;
          if ( *((_DWORD *)this + 14) != 0 )
          {
            do
            {
              v13 = 4 * v12;
              *(_DWORD *)(v13 + *((_DWORD *)this + 3)) = v10;
              v10 += *(_DWORD *)(4 * v12 + *((_DWORD *)this + 2));
              *(_DWORD *)(v13 + *((_DWORD *)this + 8)) = v11;
              v11 += *(_DWORD *)(4 * v12++ + *((_DWORD *)this + 7));
            }
            while ( v12 < *((_DWORD *)this + 14) );
            v2 = 0;
          }
          nSizeb = 4 * v10;
          v14 = MemAlloc_Alloc(nSize: 4 * v10);
          *((_DWORD *)this + 4) = v14;
          if ( v14 != nullptr )
          {
            v15 = MemAlloc_Alloc(nSize: nSizeb);
            *((_DWORD *)this + 5) = v15;
            if ( v15 != nullptr )
            {
              v16 = MemAlloc_Alloc(nSize: nSizeb);
              *((_DWORD *)this + 6) = v16;
              if ( v16 != nullptr )
              {
                v17 = MemAlloc_Alloc(nSize: 4 * v11);
                *((_DWORD *)this + 9) = v17;
                if ( v17 != nullptr )
                {
                  memset(*((void **)this + 2), 0, 4 * *((_DWORD *)this + 14));
                  memset(*((void **)this + 7), 0, 4 * *((_DWORD *)this + 14));
                  for ( j = 0; j < *((_DWORD *)this + 14); ++j )
                  {
                    v18 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 24) + 4 * j);
                    if ( (*(_WORD *)(v18 + 2) & 0xFFF0) != 0 )
                    {
                      for ( nSizec = 0; nSizec < *(_DWORD *)(v18 + 4); ++nSizec )
                        D3DXShader::CTReorderInstructions::Read(
                          this,
                          a2: j,
                          a3: *(_DWORD *)(*(_DWORD *)(v18 + 8) + 4 * nSizec));
                      for ( nSized = 0; nSized < *(_DWORD *)(v18 + 12); ++nSized )
                        D3DXShader::CTReorderInstructions::Write(
                          this,
                          a2: j,
                          a3: *(_DWORD *)(*(_DWORD *)(v18 + 16) + 4 * nSized));
                    }
                  }
                  for ( nSizee = 0; nSizee < *((_DWORD *)this + 14); ++nSizee )
                  {
                    D3DXShader::CTReorderInstructions::RemoveDuplicates(
                      a1: this,
                      a2: (int (__stdcall *)(unsigned int, unsigned int, const void *))(*((_DWORD *)this + 4)
                                                                                  + 4
                                                                                  * *(_DWORD *)(4 * nSizee
                                                                                              + *((_DWORD *)this + 3))),
                      a3: (unsigned int *)(4 * nSizee + *((_DWORD *)this + 2)));
                    D3DXShader::CTReorderInstructions::RemoveDuplicates(
                      a1: this,
                      a2: (int (__stdcall *)(unsigned int, unsigned int, const void *))(*((_DWORD *)this + 9)
                                                                                  + 4
                                                                                  * *(_DWORD *)(4 * nSizee
                                                                                              + *((_DWORD *)this + 8))),
                      a3: (unsigned int *)(4 * nSizee + *((_DWORD *)this + 7)));
                  }
                  v19 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 14));
                  *((_DWORD *)this + 15) = v19;
                  if ( v19 != nullptr )
                  {
                    v20 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 14));
                    *((_DWORD *)this + 16) = v20;
                    if ( v20 != nullptr )
                    {
                      v21 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 14));
                      *((_DWORD *)this + 17) = v21;
                      if ( v21 != nullptr )
                      {
                        v22 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 14));
                        *((_DWORD *)this + 13) = v22;
                        if ( v22 != nullptr )
                        {
                          if ( *((_DWORD *)this + 14) != 0 )
                          {
                            do
                            {
                              v23 = 4 * v2;
                              v24 = *(_DWORD *)(4 * v2 + *(_DWORD *)(*((_DWORD *)this + 1) + 24));
                              *(_DWORD *)(v23 + *((_DWORD *)this + 15)) = v2;
                              *(_DWORD *)(v23 + *((_DWORD *)this + 17)) = v24;
                              *(_DWORD *)(v24 + 36) = -1;
                              if ( (*(_WORD *)(v24 + 2) & 0xFFF0) == 0
                                || (IsFlowControl = D3DXShader::CInstruction::IsFlowControl(this: (D3DXShader::CInstruction *)v24)) != 0 )
                              {
                                IsFlowControl = 1;
                              }
                              ++v2;
                              *(_DWORD *)(v23 + *((_DWORD *)this + 13)) = IsFlowControl;
                            }
                            while ( v2 < *((_DWORD *)this + 14) );
                          }
                          v26 = 0;
                          v32 = 4 * *((_DWORD *)this + 14);
                          *((_DWORD *)this + 18) = 0;
                          v27 = MemAlloc_Alloc(nSize: v32);
                          *((_DWORD *)this + 10) = v27;
                          if ( v27 != nullptr )
                          {
                            v28 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 14));
                            *((_DWORD *)this + 11) = v28;
                            if ( v28 != nullptr )
                            {
                              v29 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 14));
                              *((_DWORD *)this + 12) = v29;
                              if ( v29 != nullptr )
                              {
                                if ( a2 == 0 )
                                {
LABEL_49:
                                  free(pMem: *((void **)this + 2));
                                  free(pMem: *((void **)this + 3));
                                  free(pMem: *((void **)this + 4));
                                  free(pMem: *((void **)this + 5));
                                  free(pMem: *((void **)this + 6));
                                  free(pMem: *((void **)this + 7));
                                  free(pMem: *((void **)this + 8));
                                  free(pMem: *((void **)this + 9));
                                  free(pMem: *((void **)this + 10));
                                  free(pMem: *((void **)this + 11));
                                  free(pMem: *((void **)this + 12));
                                  free(pMem: *((void **)this + 13));
                                  free(pMem: *((void **)this + 15));
                                  free(pMem: *((void **)this + 16));
                                  free(pMem: *((void **)this + 17));
                                  return v26;
                                }
                                while ( 1 )
                                {
                                  result = D3DXShader::CTReorderInstructions::Reduce(this);
                                  if ( result < 0 )
                                    return result;
                                  if ( result == 1 )
                                  {
                                    for ( k = 0; k < *((_DWORD *)this + 14); ++k )
                                      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 24) + 4 * k) = *(_DWORD *)(*((_DWORD *)this + 17) + 4 * *(_DWORD *)(*((_DWORD *)this + 15) + 4 * k));
                                    goto LABEL_49;
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
  v26 = -2147024882;
  goto LABEL_49;
}
