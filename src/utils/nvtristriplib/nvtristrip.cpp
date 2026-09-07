// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/nvtristriplib/nvtristrip.cpp
// Functions: 19
// ============================================================

#include "utils\nvtristriplib\nvtristrip.h"

//------------------------------------------------------------------------------
// Address: 0x005B5800
// Name: void SetListsOnly(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetListsOnly(bool _bListsOnly)
{
  bListsOnly = _bListsOnly;
}

//------------------------------------------------------------------------------
// Address: 0x005B5810
// Name: void SetCacheSize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetCacheSize(unsigned int _cacheSize)
{
  cacheSize = _cacheSize;
}

//------------------------------------------------------------------------------
// Address: 0x005B5820
// Name: void SetStitchStrips(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetStitchStrips(bool _bStitchStrips)
{
  bStitchStrips = _bStitchStrips;
}

//------------------------------------------------------------------------------
// Address: 0x005B5830
// Name: void SetMinStripSize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetMinStripSize(unsigned int _minStripSize)
{
  minStripSize = _minStripSize;
}

//------------------------------------------------------------------------------
// Address: 0x005B5840
// Name: public: unsigned short __near * std::allocator<unsigned short>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__thiscall std::allocator<unsigned short>::allocate(
        std::allocator<unsigned short> *this,
        unsigned int _Count)
{
  unsigned __int16 *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0
    && (_Count > 0x7FFFFFFF || (result = (unsigned __int16 *)MemAlloc_Alloc(nSize: 2 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B58A0
// Name: protected: unsigned short __near * std::vector<unsigned short,class std::allocator<unsigned short>>::_Umove<unsigned short __near *>(unsigned short __near *,unsigned short __near *,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__thiscall std::vector<unsigned short>::_Umove<unsigned short *>(
        std::vector<unsigned short> *this,
        unsigned __int8 *_First,
        unsigned __int16 *_Last,
        unsigned __int8 *_Ptr)
{
  int v4; // eax

  memmove(dst: _Ptr, src: _First, count: 2 * (((char *)_Last - (char *)_First) >> 1));
  return (unsigned __int16 *)(2 * (((char *)_Last - (char *)_First) >> 1) + v4);
}

//------------------------------------------------------------------------------
// Address: 0x005B58D0
// Name: public: void std::vector<unsigned short,class std::allocator<unsigned short>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<unsigned short>::reserve(std::vector<unsigned short> *this, unsigned int _Count)
{
  unsigned __int16 *v3; // ebx
  int v4; // edi
  int v5; // [esp+0h] [ebp-20h] BYREF
  unsigned __int16 *_Ptr; // [esp+Ch] [ebp-14h]
  int *v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = &v5;
  if ( _Count > 0x7FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = std::allocator<unsigned short>::allocate(this: &this->_Alval, _Count);
    _Ptr = v3;
    v8 = 0;
    std::vector<unsigned short>::_Umove<unsigned short *>(
      this,
      _First: (unsigned __int8 *)this->_Myfirst,
      _Last: this->_Mylast,
      _Ptr: (unsigned __int8 *)v3);
    v8 = -1;
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      free(pMem: this->_Myfirst);
    this->_Myend = &v3[_Count];
    this->_Mylast = &v3[v4];
    this->_Myfirst = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B5990
// Name: protected: void std::vector<unsigned short,class std::allocator<unsigned short>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<unsigned short>::_Reserve(std::vector<unsigned short> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0x7FFFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0x7FFFFFFF - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<unsigned short>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B5A00
// Name: public: void std::vector<unsigned short,class std::allocator<unsigned short>>::resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<unsigned short>::resize(std::vector<unsigned short> *this, unsigned int _Newsize)
{
  unsigned __int8 *Mylast; // ecx
  unsigned int v4; // eax
  unsigned __int8 *v5; // edi
  unsigned __int16 *v6; // edi
  signed int v7; // edx
  unsigned int v8; // ecx
  char v9; // cf
  unsigned int v10; // ecx
  unsigned __int16 *v11; // edi
  int i; // ecx

  Mylast = (unsigned __int8 *)this->_Mylast;
  v4 = (Mylast - (unsigned __int8 *)this->_Myfirst) >> 1;
  if ( v4 <= _Newsize )
  {
    if ( v4 < _Newsize )
    {
      std::vector<unsigned short>::_Reserve(this, _Count: _Newsize - v4);
      v6 = this->_Mylast;
      v7 = v6 - this->_Myfirst;
      v8 = _Newsize - v7;
      if ( _Newsize != v7 )
      {
        v9 = v8 & 1;
        v10 = v8 >> 1;
        memset(v6, 0, 4 * v10);
        v11 = &v6[2 * v10];
        for ( i = v9; i != 0; --i )
          *v11++ = 0;
      }
      this->_Mylast += _Newsize - (this->_Mylast - this->_Myfirst);
    }
  }
  else
  {
    v5 = (unsigned __int8 *)&this->_Myfirst[_Newsize];
    if ( v5 != Mylast )
    {
      memmove(dst: v5, src: Mylast, count: 0);
      this->_Mylast = (unsigned __int16 *)v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B5A90
// Name: void GenerateStrips(unsigned short const __near *,unsigned int,struct PrimitiveGroup __near * __near *,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateStrips(
        const unsigned __int16 *in_indices,
        unsigned int in_numIndices,
        PrimitiveGroup **primGroups,
        unsigned __int16 *numGroups)
{
  int v4; // edi
  unsigned __int16 v5; // si
  unsigned int i; // eax
  _DWORD *v7; // eax
  PrimitiveGroup *v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // ebx
  int v12; // ecx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  unsigned int v16; // edx
  NvStripInfo **Myfirst; // ecx
  int v18; // ebx
  unsigned int k; // edi
  NvStripInfo *v20; // eax
  int v21; // edx
  std::vector<NvFaceInfo *> *p_m_faces; // eax
  NvStripInfo *v23; // eax
  int v24; // edx
  NvFaceInfo **v25; // eax
  unsigned int v26; // edi
  int v27; // ecx
  NvFaceInfo **Mylast; // edx
  int v29; // edx
  __int16 v30; // ax
  unsigned __int16 *v31; // ebx
  int v32; // esi
  _DWORD *v33; // eax
  int v34; // ecx
  PrimitiveGroup *v35; // edx
  _DWORD *m; // eax
  PrimitiveGroup *v37; // esi
  unsigned __int16 **p_indices; // ebx
  unsigned int v39; // ecx
  unsigned int n; // eax
  int v41; // esi
  unsigned __int16 *v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // edx
  PrimitiveGroup *v46; // esi
  unsigned int v47; // edi
  int v48; // ecx
  unsigned int v49; // edi
  NvStripInfo *v50; // eax
  int v51; // edx
  std::vector<NvFaceInfo *> *v52; // eax
  unsigned int v53; // esi
  NvStripInfo *v54; // eax
  int v55; // edx
  NvStripInfo *v56; // esi
  unsigned int v57; // esi
  NvStripifier stripifier; // [esp+Ch] [ebp-68h] BYREF
  std::vector<unsigned short> tempIndices; // [esp+2Ch] [ebp-48h] BYREF
  std::vector<int> stripIndices; // [esp+3Ch] [ebp-38h] BYREF
  std::vector<NvStripInfo *> tempStrips; // [esp+4Ch] [ebp-28h] BYREF
  std::vector<NvFaceInfo *> tempFaces; // [esp+5Ch] [ebp-18h] BYREF
  int stripCtr; // [esp+6Ch] [ebp-8h]
  unsigned int numSeparateStrips; // [esp+70h] [ebp-4h] BYREF
  int j; // [esp+80h] [ebp+Ch]
  unsigned int ja; // [esp+80h] [ebp+Ch]
  int jb; // [esp+80h] [ebp+Ch]

  v4 = 0;
  memset(&tempIndices, 0, 12);
  std::vector<unsigned short>::resize(this: &tempIndices, _Newsize: in_numIndices);
  v5 = 0;
  for ( i = 0; i < in_numIndices; ++i )
  {
    tempIndices._Myfirst[i] = in_indices[i];
    if ( in_indices[i] > v5 )
      v5 = in_indices[i];
  }
  memset(&tempStrips, 0, 12);
  memset(&tempFaces, 0, 12);
  NvStripifier::NvStripifier(this: &stripifier);
  NvStripifier::Stripify(
    this: &stripifier,
    in_indices: &tempIndices,
    in_cacheSize: cacheSize,
    in_minStripLength: minStripSize,
    maxIndex: v5,
    outStrips: &tempStrips,
    outFaceList: &tempFaces);
  memset(&stripIndices, 0, 12);
  numSeparateStrips = 0;
  if ( bListsOnly )
  {
    *numGroups = 1;
    v7 = MemAlloc_Alloc(nSize: 0x10u);
    if ( v7 != nullptr )
    {
      v8 = (PrimitiveGroup *)(v7 + 1);
      *v7 = 1;
      v7[1] = 1;
      v7[2] = 0;
      v7[3] = 0;
    }
    else
    {
      v8 = nullptr;
    }
    *primGroups = v8;
    v9 = 0;
    v10 = tempStrips._Mylast - tempStrips._Myfirst;
    v11 = 0;
    stripCtr = 0;
    j = v10;
    if ( v10 >= 2 )
    {
      do
      {
        v12 = (char *)tempStrips._Myfirst[v4]->m_faces._Mylast - (char *)tempStrips._Myfirst[v4]->m_faces._Myfirst;
        v4 += 2;
        v9 += (v12 >> 2) + 2 * (v12 >> 2);
        v13 = tempStrips._Myfirst[v4 - 1]->m_faces._Mylast - tempStrips._Myfirst[v4 - 1]->m_faces._Myfirst;
        v11 += v13 + 2 * v13;
      }
      while ( v4 < j - 1 );
      v10 = j;
    }
    if ( v4 >= (unsigned int)v10 )
      v14 = stripCtr;
    else
      v14 = 3 * (tempStrips._Myfirst[v4]->m_faces._Mylast - tempStrips._Myfirst[v4]->m_faces._Myfirst);
    v15 = (char *)tempFaces._Mylast - (char *)tempFaces._Myfirst;
    v8->type = PT_LIST;
    v16 = v11 + (v15 >> 2) + v9 + 2 * (v15 >> 2) + v14;
    v8->numIndices = v16;
    v8->indices = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)v16 >> 31 != 0 ? -1 : 2 * v16);
    Myfirst = tempStrips._Myfirst;
    v18 = 0;
    for ( k = 0; k < tempStrips._Mylast - Myfirst; ++k )
    {
      v20 = Myfirst[k];
      v21 = (char *)v20->m_faces._Mylast - (char *)v20->m_faces._Myfirst;
      p_m_faces = &v20->m_faces;
      ja = 0;
      if ( v21 >> 2 != 0 )
      {
        do
        {
          if ( NvStripifier::IsDegenerate(face: p_m_faces->_Myfirst[ja]) )
          {
            v8->numIndices -= 3;
          }
          else
          {
            v8->indices[v18] = tempStrips._Myfirst[k]->m_faces._Myfirst[ja]->m_v0;
            v8->indices[v18 + 1] = tempStrips._Myfirst[k]->m_faces._Myfirst[ja]->m_v1;
            v8->indices[v18 + 2] = tempStrips._Myfirst[k]->m_faces._Myfirst[ja]->m_v2;
            v18 += 3;
          }
          Myfirst = tempStrips._Myfirst;
          v23 = tempStrips._Myfirst[k];
          v24 = (char *)v23->m_faces._Mylast - (char *)v23->m_faces._Myfirst;
          ++ja;
          p_m_faces = &v23->m_faces;
        }
        while ( ja < v24 >> 2 );
      }
    }
    v25 = tempFaces._Myfirst;
    v26 = 0;
    if ( tempFaces._Mylast - tempFaces._Myfirst != 0 )
    {
      v27 = v18;
      do
      {
        v8->indices[v27] = v25[v26]->m_v0;
        v8->indices[v27 + 1] = tempFaces._Myfirst[v26]->m_v1;
        v8->indices[v27 + 2] = tempFaces._Myfirst[v26]->m_v2;
        Mylast = tempFaces._Mylast;
        v25 = tempFaces._Myfirst;
        ++v26;
        v27 += 3;
      }
      while ( v26 < tempFaces._Mylast - tempFaces._Myfirst );
LABEL_25:
      Myfirst = tempStrips._Myfirst;
      goto LABEL_52;
    }
    Mylast = tempFaces._Mylast;
  }
  else
  {
    NvStripifier::CreateStrips(
      this: &stripifier,
      allStrips: &tempStrips,
      &stripIndices,
      bStitchStrips: bStitchStrips,
      &numSeparateStrips);
    v29 = (char *)tempFaces._Mylast - (char *)tempFaces._Myfirst;
    v30 = numSeparateStrips;
    v31 = numGroups;
    *numGroups = numSeparateStrips;
    if ( (v29 & 0xFFFFFFFC) != 0 )
      *numGroups = v30 + 1;
    v32 = *numGroups;
    v33 = MemAlloc_Alloc(nSize: __CFADD__(12 * v32, 4) ? -1 : 12 * v32 + 4);
    if ( v33 != nullptr )
    {
      v34 = v32 - 1;
      v35 = (PrimitiveGroup *)(v33 + 1);
      *v33 = v32;
      for ( m = v33 + 1; v34 >= 0; --v34 )
      {
        *m = 1;
        m[1] = 0;
        m[2] = 0;
        m += 3;
      }
      v37 = v35;
      jb = (int)v35;
    }
    else
    {
      jb = 0;
      v37 = nullptr;
    }
    *primGroups = v37;
    stripCtr = 0;
    if ( numSeparateStrips != 0 )
    {
      p_indices = &v37->indices;
      do
      {
        if ( bStitchStrips )
        {
          v41 = stripIndices._Mylast - stripIndices._Myfirst;
        }
        else
        {
          v39 = stripIndices._Mylast - stripIndices._Myfirst;
          for ( n = v4; n < v39; ++n )
          {
            if ( stripIndices._Myfirst[n] == -1 )
              break;
          }
          v41 = n - v4;
        }
        *(p_indices - 2) = (unsigned __int16 *)1;
        v42 = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v41 >> 31 != 0 ? -1 : 2 * v41);
        v43 = v41 + v4;
        *p_indices = v42;
        *(p_indices - 1) = (unsigned __int16 *)v41;
        v44 = v4;
        if ( v4 < v41 + v4 )
        {
          v45 = 0;
          do
            (*p_indices)[v45++] = stripIndices._Myfirst[v44++];
          while ( v44 < v43 );
        }
        p_indices += 3;
        v4 = v43 + 1;
        ++stripCtr;
      }
      while ( stripCtr < numSeparateStrips );
      v31 = numGroups;
      v37 = (PrimitiveGroup *)jb;
    }
    Mylast = tempFaces._Mylast;
    v25 = tempFaces._Myfirst;
    if ( (((char *)tempFaces._Mylast - (char *)tempFaces._Myfirst) & 0xFFFFFFFC) == 0 )
      goto LABEL_25;
    v46 = &v37[*v31 - 1];
    v46->type = PT_LIST;
    v46->indices = (unsigned __int16 *)MemAlloc_Alloc(
                                         nSize: (unsigned __int64)(unsigned int)(3 * (tempFaces._Mylast - tempFaces._Myfirst)) >> 31 != 0
                                       ? -1
                                       : 6 * (tempFaces._Mylast - tempFaces._Myfirst));
    v46->numIndices = 3 * (tempFaces._Mylast - tempFaces._Myfirst);
    Mylast = tempFaces._Mylast;
    v25 = tempFaces._Myfirst;
    v47 = 0;
    if ( tempFaces._Mylast - tempFaces._Myfirst == 0 )
      goto LABEL_25;
    v48 = 0;
    do
    {
      v46->indices[v48] = v25[v47]->m_v0;
      v46->indices[v48 + 1] = tempFaces._Myfirst[v47]->m_v1;
      v46->indices[v48 + 2] = tempFaces._Myfirst[v47]->m_v2;
      Mylast = tempFaces._Mylast;
      v25 = tempFaces._Myfirst;
      ++v47;
      v48 += 3;
    }
    while ( v47 < tempFaces._Mylast - tempFaces._Myfirst );
    Myfirst = tempStrips._Myfirst;
  }
LABEL_52:
  v49 = 0;
  if ( tempStrips._Mylast - Myfirst != 0 )
  {
    do
    {
      v50 = Myfirst[v49];
      v51 = (char *)v50->m_faces._Mylast - (char *)v50->m_faces._Myfirst;
      v52 = &v50->m_faces;
      v53 = 0;
      if ( v51 >> 2 != 0 )
      {
        do
        {
          free(pMem: v52->_Myfirst[v53]);
          tempStrips._Myfirst[v49]->m_faces._Myfirst[v53] = nullptr;
          Myfirst = tempStrips._Myfirst;
          v54 = tempStrips._Myfirst[v49];
          v55 = (char *)v54->m_faces._Mylast - (char *)v54->m_faces._Myfirst;
          v52 = &v54->m_faces;
          ++v53;
        }
        while ( v53 < v55 >> 2 );
      }
      v56 = Myfirst[v49];
      if ( v56 != nullptr )
      {
        if ( v56->m_faces._Myfirst != nullptr )
          free(pMem: v56->m_faces._Myfirst);
        v56->m_faces._Myfirst = nullptr;
        v56->m_faces._Mylast = nullptr;
        v56->m_faces._Myend = nullptr;
        free(pMem: v56);
        Myfirst = tempStrips._Myfirst;
      }
      Myfirst[v49] = nullptr;
      Myfirst = tempStrips._Myfirst;
      ++v49;
    }
    while ( v49 < tempStrips._Mylast - tempStrips._Myfirst );
    Mylast = tempFaces._Mylast;
    v25 = tempFaces._Myfirst;
  }
  v57 = 0;
  if ( Mylast - v25 != 0 )
  {
    do
    {
      free(pMem: v25[v57]);
      tempFaces._Myfirst[v57] = nullptr;
      v25 = tempFaces._Myfirst;
      ++v57;
    }
    while ( v57 < tempFaces._Mylast - tempFaces._Myfirst );
  }
  if ( stripIndices._Myfirst != nullptr )
    free(pMem: stripIndices._Myfirst);
  memset(&stripIndices, 0, 12);
  NvStripifier::~NvStripifier(this: &stripifier);
  if ( tempFaces._Myfirst != nullptr )
    free(pMem: tempFaces._Myfirst);
  memset(&tempFaces, 0, 12);
  if ( tempStrips._Myfirst != nullptr )
    free(pMem: tempStrips._Myfirst);
  memset(&tempStrips, 0, 12);
  if ( tempIndices._Myfirst != nullptr )
    free(pMem: tempIndices._Myfirst);
}

//------------------------------------------------------------------------------
// Address: 0x005B6C60
// Name: public: class NvFaceInfo __near * __near * std::allocator<class NvFaceInfo __near *>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall std::allocator<NvFaceInfo *>::allocate(std::allocator<int> *this, unsigned int _Count)
{
  int *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x3FFFFFFF || (result = (int *)MemAlloc_Alloc(nSize: 4 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B6DA0
// Name: protected: bool std::vector<unsigned short,class std::allocator<unsigned short>>::_Buy(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::vector<unsigned short>::_Buy(std::vector<unsigned short> *this, unsigned int _Capacity)
{
  unsigned __int16 *v4; // eax

  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
  if ( _Capacity == 0 )
    return 0;
  if ( _Capacity > 0x7FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  v4 = std::allocator<unsigned short>::allocate(this: &this->_Alval, _Count: _Capacity);
  this->_Myfirst = v4;
  this->_Mylast = v4;
  this->_Myend = &v4[_Capacity];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6DF0
// Name: protected: class NvFaceInfo __near * __near * std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>>::_Umove<class NvFaceInfo __near * __near *>(class NvFaceInfo __near * __near *,class NvFaceInfo __near * __near *,class NvFaceInfo __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall std::vector<NvFaceInfo *>::_Umove<NvFaceInfo * *>(
        std::vector<int> *this,
        int *_First,
        int *_Last,
        int *_Ptr)
{
  int v4; // eax

  memmove(dst: (unsigned __int8 *)_Ptr, src: (unsigned __int8 *)_First, count: 4 * (_Last - _First));
  return (int *)(4 * (_Last - _First) + v4);
}

//------------------------------------------------------------------------------
// Address: 0x005B7110
// Name: public: void std::vector<int,class std::allocator<int>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<int>::reserve(std::vector<int> *this, unsigned int _Count)
{
  int *v3; // ebx
  int v4; // edi
  int v5; // [esp+0h] [ebp-20h] BYREF
  int *_Ptr; // [esp+Ch] [ebp-14h]
  int *v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = &v5;
  if ( _Count > 0x3FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = std::allocator<NvFaceInfo *>::allocate(this: &this->_Alval, _Count);
    _Ptr = v3;
    v8 = 0;
    std::vector<NvFaceInfo *>::_Umove<NvFaceInfo * *>(this, _First: this->_Myfirst, _Last: this->_Mylast, _Ptr: v3);
    v8 = -1;
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      free(pMem: this->_Myfirst);
    this->_Myend = &v3[_Count];
    this->_Mylast = &v3[v4];
    this->_Myfirst = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B7580
// Name: public: class std::vector<unsigned short,class std::allocator<unsigned short>> __near & std::vector<unsigned short,class std::allocator<unsigned short>>::operator=(class std::vector<unsigned short,class std::allocator<unsigned short>> const __near &)
// Source: json
//------------------------------------------------------------------------------
std::vector<unsigned short> *__thiscall std::vector<unsigned short>::operator=(
        std::vector<unsigned short> *this,
        const std::vector<unsigned short> *_Right)
{
  unsigned __int16 *Mylast; // ecx
  unsigned __int8 *Myfirst; // eax
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v9; // ebx
  unsigned int v10; // edx
  unsigned __int8 *v11; // ebx
  unsigned int v12; // edi
  int v13; // eax
  unsigned __int8 *v14; // eax
  unsigned int v15; // edi
  int v16; // eax
  unsigned int _Righta; // [esp+10h] [ebp+8h]

  if ( this != _Right )
  {
    Mylast = _Right->_Mylast;
    Myfirst = (unsigned __int8 *)_Right->_Myfirst;
    _Righta = Mylast - _Right->_Myfirst;
    if ( _Righta != 0 )
    {
      v9 = (unsigned __int8 *)this->_Myfirst;
      v10 = this->_Mylast - this->_Myfirst;
      if ( _Righta <= v10 )
      {
        memmove(dst: v9, src: Myfirst, count: 2 * (((char *)Mylast - (char *)Myfirst) >> 1));
        this->_Mylast = &this->_Myfirst[_Right->_Mylast - _Right->_Myfirst];
        return this;
      }
      if ( _Righta <= ((char *)this->_Myend - (char *)v9) >> 1 )
      {
        v11 = &Myfirst[2 * v10];
        memmove(dst: (unsigned __int8 *)this->_Myfirst, src: Myfirst, count: 2 * ((int)(2 * v10) >> 1));
        v12 = 2 * (((char *)_Right->_Mylast - (char *)v11) >> 1);
        memmove(dst: (unsigned __int8 *)this->_Mylast, src: v11, count: v12);
        this->_Mylast = (unsigned __int16 *)(v12 + v13);
        return this;
      }
      if ( v9 != nullptr )
        free(pMem: v9);
      if ( std::vector<unsigned short>::_Buy(this, _Capacity: _Right->_Mylast - _Right->_Myfirst) != 0 )
      {
        v14 = (unsigned __int8 *)_Right->_Myfirst;
        v15 = 2 * (_Right->_Mylast - _Right->_Myfirst);
        memmove(dst: (unsigned __int8 *)this->_Myfirst, src: v14, count: v15);
        this->_Mylast = (unsigned __int16 *)(v15 + v16);
      }
    }
    else
    {
      v6 = (unsigned __int8 *)this->_Mylast;
      v7 = (unsigned __int8 *)this->_Myfirst;
      if ( (unsigned __int8 *)this->_Myfirst != v6 )
      {
        memmove(dst: v7, src: v6, count: 0);
        this->_Mylast = (unsigned __int16 *)v7;
        return this;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B76A0
// Name: protected: void std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<NvFaceInfo *>::_Reserve(std::vector<int> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0x3FFFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0x3FFFFFFF - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<int>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B7970
// Name: public: void std::vector<unsigned short,class std::allocator<unsigned short>>::push_back(unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<unsigned short>::push_back(std::vector<unsigned short> *this, unsigned __int16 *_Val)
{
  unsigned __int16 *Mylast; // eax
  int v4; // edi
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<unsigned short>::_Reserve(this, _Count: 1u);
    v6 = this->_Mylast;
    if ( v6 != nullptr )
      *v6 = *_Val;
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<unsigned short>::_Reserve(this, _Count: 1u);
    v5 = this->_Mylast;
    if ( v5 != nullptr )
    {
      *v5 = this->_Myfirst[v4];
      ++this->_Mylast;
      return;
    }
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x005B79E0
// Name: public: void std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>>::resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<NvEdgeInfo *>::resize(std::vector<NvEdgeInfo *> *this, unsigned int _Newsize)
{
  unsigned __int8 *Mylast; // ecx
  unsigned int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // edx

  Mylast = (unsigned __int8 *)this->_Mylast;
  v4 = (Mylast - (unsigned __int8 *)this->_Myfirst) >> 2;
  if ( v4 <= _Newsize )
  {
    if ( v4 < _Newsize )
    {
      std::vector<NvFaceInfo *>::_Reserve((std::vector<int> *)this, _Count: _Newsize - v4);
      v6 = this->_Mylast - this->_Myfirst;
      if ( _Newsize != v6 )
        memset(this->_Mylast, 0, 4 * (_Newsize - v6));
      this->_Mylast += _Newsize - (this->_Mylast - this->_Myfirst);
    }
  }
  else
  {
    v5 = (unsigned __int8 *)&this->_Myfirst[_Newsize];
    if ( v5 != Mylast )
    {
      memmove(dst: v5, src: Mylast, count: 0);
      this->_Mylast = (NvEdgeInfo **)v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B7A70
// Name: public: void std::vector<int,class std::allocator<int>>::push_back(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<int>::push_back(std::vector<int> *this, int *_Val)
{
  int *Mylast; // eax
  int v4; // edi
  int *v5; // eax
  int *v6; // eax

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<NvFaceInfo *>::_Reserve(this, _Count: 1u);
    v6 = this->_Mylast;
    if ( v6 != nullptr )
      *v6 = *_Val;
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<NvFaceInfo *>::_Reserve(this, _Count: 1u);
    v5 = this->_Mylast;
    if ( v5 != nullptr )
    {
      *v5 = this->_Myfirst[v4];
      ++this->_Mylast;
      return;
    }
  }
  ++this->_Mylast;
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005AE730
// Name: void SetListsOnly(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetListsOnly(bool _bListsOnly)
{
  bListsOnly = _bListsOnly;
}

//------------------------------------------------------------------------------
// Address: 0x005AE740
// Name: void SetCacheSize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetCacheSize(unsigned int _cacheSize)
{
  cacheSize = _cacheSize;
}

//------------------------------------------------------------------------------
// Address: 0x005AE750
// Name: void SetStitchStrips(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetStitchStrips(bool _bStitchStrips)
{
  bStitchStrips = _bStitchStrips;
}

//------------------------------------------------------------------------------
// Address: 0x005AE760
// Name: void SetMinStripSize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetMinStripSize(unsigned int _minStripSize)
{
  minStripSize = _minStripSize;
}

//------------------------------------------------------------------------------
// Address: 0x005AE770
// Name: public: unsigned short __near * std::allocator<unsigned short>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__thiscall std::allocator<unsigned short>::allocate(
        std::allocator<unsigned short> *this,
        unsigned int _Count)
{
  unsigned __int16 *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0
    && (_Count > 0x7FFFFFFF || (result = (unsigned __int16 *)MemAlloc_Alloc(nSize: 2 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AE7D0
// Name: protected: unsigned short __near * std::vector<unsigned short,class std::allocator<unsigned short>>::_Umove<unsigned short __near *>(unsigned short __near *,unsigned short __near *,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__thiscall std::vector<unsigned short>::_Umove<unsigned short *>(
        std::vector<unsigned short> *this,
        unsigned __int8 *_First,
        unsigned __int16 *_Last,
        unsigned __int8 *_Ptr)
{
  int v4; // eax

  memmove(dst: _Ptr, src: _First, count: 2 * (((char *)_Last - (char *)_First) >> 1));
  return (unsigned __int16 *)(2 * (((char *)_Last - (char *)_First) >> 1) + v4);
}

//------------------------------------------------------------------------------
// Address: 0x005AE800
// Name: public: void std::vector<unsigned short,class std::allocator<unsigned short>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<unsigned short>::reserve(std::vector<unsigned short> *this, unsigned int _Count)
{
  unsigned __int16 *v3; // ebx
  int v4; // edi
  int v5; // [esp+0h] [ebp-20h] BYREF
  unsigned __int16 *_Ptr; // [esp+Ch] [ebp-14h]
  int *v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = &v5;
  if ( _Count > 0x7FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = std::allocator<unsigned short>::allocate(this: &this->_Alval, _Count);
    _Ptr = v3;
    v8 = 0;
    std::vector<unsigned short>::_Umove<unsigned short *>(
      this,
      _First: (unsigned __int8 *)this->_Myfirst,
      _Last: this->_Mylast,
      _Ptr: (unsigned __int8 *)v3);
    v8 = -1;
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      free(pMem: this->_Myfirst);
    this->_Myend = &v3[_Count];
    this->_Mylast = &v3[v4];
    this->_Myfirst = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AE8C0
// Name: protected: void std::vector<unsigned short,class std::allocator<unsigned short>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<unsigned short>::_Reserve(std::vector<unsigned short> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0x7FFFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0x7FFFFFFF - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<unsigned short>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AE930
// Name: public: void std::vector<unsigned short,class std::allocator<unsigned short>>::resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<unsigned short>::resize(std::vector<unsigned short> *this, unsigned int _Newsize)
{
  unsigned __int8 *Mylast; // ecx
  unsigned int v4; // eax
  unsigned __int8 *v5; // edi
  unsigned __int16 *v6; // edi
  signed int v7; // edx
  unsigned int v8; // ecx
  char v9; // cf
  unsigned int v10; // ecx
  unsigned __int16 *v11; // edi
  int i; // ecx

  Mylast = (unsigned __int8 *)this->_Mylast;
  v4 = (Mylast - (unsigned __int8 *)this->_Myfirst) >> 1;
  if ( v4 <= _Newsize )
  {
    if ( v4 < _Newsize )
    {
      std::vector<unsigned short>::_Reserve(this, _Count: _Newsize - v4);
      v6 = this->_Mylast;
      v7 = v6 - this->_Myfirst;
      v8 = _Newsize - v7;
      if ( _Newsize != v7 )
      {
        v9 = v8 & 1;
        v10 = v8 >> 1;
        memset(v6, 0, 4 * v10);
        v11 = &v6[2 * v10];
        for ( i = v9; i != 0; --i )
          *v11++ = 0;
      }
      this->_Mylast += _Newsize - (this->_Mylast - this->_Myfirst);
    }
  }
  else
  {
    v5 = (unsigned __int8 *)&this->_Myfirst[_Newsize];
    if ( v5 != Mylast )
    {
      memmove(dst: v5, src: Mylast, count: 0);
      this->_Mylast = (unsigned __int16 *)v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AE9C0
// Name: void GenerateStrips(unsigned short const __near *,unsigned int,struct PrimitiveGroup __near * __near *,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateStrips(
        const unsigned __int16 *in_indices,
        unsigned int in_numIndices,
        PrimitiveGroup **primGroups,
        unsigned __int16 *numGroups)
{
  int v4; // edi
  unsigned __int16 v5; // si
  unsigned int i; // eax
  _DWORD *v7; // eax
  PrimitiveGroup *v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // ebx
  int v12; // ecx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  unsigned int v16; // edx
  NvStripInfo **Myfirst; // ecx
  int v18; // ebx
  unsigned int k; // edi
  NvStripInfo *v20; // eax
  int v21; // edx
  std::vector<NvFaceInfo *> *p_m_faces; // eax
  NvStripInfo *v23; // eax
  int v24; // edx
  NvFaceInfo **v25; // eax
  unsigned int v26; // edi
  int v27; // ecx
  NvFaceInfo **Mylast; // edx
  int v29; // edx
  __int16 v30; // ax
  unsigned __int16 *v31; // ebx
  int v32; // esi
  _DWORD *v33; // eax
  int v34; // ecx
  PrimitiveGroup *v35; // edx
  _DWORD *m; // eax
  PrimitiveGroup *v37; // esi
  unsigned __int16 **p_indices; // ebx
  unsigned int v39; // ecx
  unsigned int n; // eax
  int v41; // esi
  unsigned __int16 *v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // edx
  PrimitiveGroup *v46; // esi
  unsigned int v47; // edi
  int v48; // ecx
  unsigned int v49; // edi
  NvStripInfo *v50; // eax
  int v51; // edx
  std::vector<NvFaceInfo *> *v52; // eax
  unsigned int v53; // esi
  NvStripInfo *v54; // eax
  int v55; // edx
  NvStripInfo *v56; // esi
  unsigned int v57; // esi
  NvStripifier stripifier; // [esp+Ch] [ebp-68h] BYREF
  std::vector<unsigned short> tempIndices; // [esp+2Ch] [ebp-48h] BYREF
  std::vector<int> stripIndices; // [esp+3Ch] [ebp-38h] BYREF
  std::vector<NvStripInfo *> tempStrips; // [esp+4Ch] [ebp-28h] BYREF
  std::vector<NvFaceInfo *> tempFaces; // [esp+5Ch] [ebp-18h] BYREF
  int stripCtr; // [esp+6Ch] [ebp-8h]
  unsigned int numSeparateStrips; // [esp+70h] [ebp-4h] BYREF
  int j; // [esp+80h] [ebp+Ch]
  unsigned int ja; // [esp+80h] [ebp+Ch]
  int jb; // [esp+80h] [ebp+Ch]

  v4 = 0;
  memset(&tempIndices, 0, 12);
  std::vector<unsigned short>::resize(this: &tempIndices, _Newsize: in_numIndices);
  v5 = 0;
  for ( i = 0; i < in_numIndices; ++i )
  {
    tempIndices._Myfirst[i] = in_indices[i];
    if ( in_indices[i] > v5 )
      v5 = in_indices[i];
  }
  memset(&tempStrips, 0, 12);
  memset(&tempFaces, 0, 12);
  NvStripifier::NvStripifier(this: &stripifier);
  NvStripifier::Stripify(
    this: &stripifier,
    in_indices: &tempIndices,
    in_cacheSize: cacheSize,
    in_minStripLength: minStripSize,
    maxIndex: v5,
    outStrips: &tempStrips,
    outFaceList: &tempFaces);
  memset(&stripIndices, 0, 12);
  numSeparateStrips = 0;
  if ( bListsOnly )
  {
    *numGroups = 1;
    v7 = MemAlloc_Alloc(nSize: 0x10u);
    if ( v7 != nullptr )
    {
      v8 = (PrimitiveGroup *)(v7 + 1);
      *v7 = 1;
      v7[1] = 1;
      v7[2] = 0;
      v7[3] = 0;
    }
    else
    {
      v8 = nullptr;
    }
    *primGroups = v8;
    v9 = 0;
    v10 = tempStrips._Mylast - tempStrips._Myfirst;
    v11 = 0;
    stripCtr = 0;
    j = v10;
    if ( v10 >= 2 )
    {
      do
      {
        v12 = (char *)tempStrips._Myfirst[v4]->m_faces._Mylast - (char *)tempStrips._Myfirst[v4]->m_faces._Myfirst;
        v4 += 2;
        v9 += (v12 >> 2) + 2 * (v12 >> 2);
        v13 = tempStrips._Myfirst[v4 - 1]->m_faces._Mylast - tempStrips._Myfirst[v4 - 1]->m_faces._Myfirst;
        v11 += v13 + 2 * v13;
      }
      while ( v4 < j - 1 );
      v10 = j;
    }
    if ( v4 >= (unsigned int)v10 )
      v14 = stripCtr;
    else
      v14 = 3 * (tempStrips._Myfirst[v4]->m_faces._Mylast - tempStrips._Myfirst[v4]->m_faces._Myfirst);
    v15 = (char *)tempFaces._Mylast - (char *)tempFaces._Myfirst;
    v8->type = PT_LIST;
    v16 = v11 + (v15 >> 2) + v9 + 2 * (v15 >> 2) + v14;
    v8->numIndices = v16;
    v8->indices = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)v16 >> 31 != 0 ? -1 : 2 * v16);
    Myfirst = tempStrips._Myfirst;
    v18 = 0;
    for ( k = 0; k < tempStrips._Mylast - Myfirst; ++k )
    {
      v20 = Myfirst[k];
      v21 = (char *)v20->m_faces._Mylast - (char *)v20->m_faces._Myfirst;
      p_m_faces = &v20->m_faces;
      ja = 0;
      if ( v21 >> 2 != 0 )
      {
        do
        {
          if ( NvStripifier::IsDegenerate(face: p_m_faces->_Myfirst[ja]) )
          {
            v8->numIndices -= 3;
          }
          else
          {
            v8->indices[v18] = tempStrips._Myfirst[k]->m_faces._Myfirst[ja]->m_v0;
            v8->indices[v18 + 1] = tempStrips._Myfirst[k]->m_faces._Myfirst[ja]->m_v1;
            v8->indices[v18 + 2] = tempStrips._Myfirst[k]->m_faces._Myfirst[ja]->m_v2;
            v18 += 3;
          }
          Myfirst = tempStrips._Myfirst;
          v23 = tempStrips._Myfirst[k];
          v24 = (char *)v23->m_faces._Mylast - (char *)v23->m_faces._Myfirst;
          ++ja;
          p_m_faces = &v23->m_faces;
        }
        while ( ja < v24 >> 2 );
      }
    }
    v25 = tempFaces._Myfirst;
    v26 = 0;
    if ( tempFaces._Mylast - tempFaces._Myfirst != 0 )
    {
      v27 = v18;
      do
      {
        v8->indices[v27] = v25[v26]->m_v0;
        v8->indices[v27 + 1] = tempFaces._Myfirst[v26]->m_v1;
        v8->indices[v27 + 2] = tempFaces._Myfirst[v26]->m_v2;
        Mylast = tempFaces._Mylast;
        v25 = tempFaces._Myfirst;
        ++v26;
        v27 += 3;
      }
      while ( v26 < tempFaces._Mylast - tempFaces._Myfirst );
LABEL_25:
      Myfirst = tempStrips._Myfirst;
      goto LABEL_52;
    }
    Mylast = tempFaces._Mylast;
  }
  else
  {
    NvStripifier::CreateStrips(
      this: &stripifier,
      allStrips: &tempStrips,
      &stripIndices,
      bStitchStrips: bStitchStrips,
      &numSeparateStrips);
    v29 = (char *)tempFaces._Mylast - (char *)tempFaces._Myfirst;
    v30 = numSeparateStrips;
    v31 = numGroups;
    *numGroups = numSeparateStrips;
    if ( (v29 & 0xFFFFFFFC) != 0 )
      *numGroups = v30 + 1;
    v32 = *numGroups;
    v33 = MemAlloc_Alloc(nSize: __CFADD__(12 * v32, 4) ? -1 : 12 * v32 + 4);
    if ( v33 != nullptr )
    {
      v34 = v32 - 1;
      v35 = (PrimitiveGroup *)(v33 + 1);
      *v33 = v32;
      for ( m = v33 + 1; v34 >= 0; --v34 )
      {
        *m = 1;
        m[1] = 0;
        m[2] = 0;
        m += 3;
      }
      v37 = v35;
      jb = (int)v35;
    }
    else
    {
      jb = 0;
      v37 = nullptr;
    }
    *primGroups = v37;
    stripCtr = 0;
    if ( numSeparateStrips != 0 )
    {
      p_indices = &v37->indices;
      do
      {
        if ( bStitchStrips )
        {
          v41 = stripIndices._Mylast - stripIndices._Myfirst;
        }
        else
        {
          v39 = stripIndices._Mylast - stripIndices._Myfirst;
          for ( n = v4; n < v39; ++n )
          {
            if ( stripIndices._Myfirst[n] == -1 )
              break;
          }
          v41 = n - v4;
        }
        *(p_indices - 2) = (unsigned __int16 *)1;
        v42 = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v41 >> 31 != 0 ? -1 : 2 * v41);
        v43 = v41 + v4;
        *p_indices = v42;
        *(p_indices - 1) = (unsigned __int16 *)v41;
        v44 = v4;
        if ( v4 < v41 + v4 )
        {
          v45 = 0;
          do
            (*p_indices)[v45++] = stripIndices._Myfirst[v44++];
          while ( v44 < v43 );
        }
        p_indices += 3;
        v4 = v43 + 1;
        ++stripCtr;
      }
      while ( stripCtr < numSeparateStrips );
      v31 = numGroups;
      v37 = (PrimitiveGroup *)jb;
    }
    Mylast = tempFaces._Mylast;
    v25 = tempFaces._Myfirst;
    if ( (((char *)tempFaces._Mylast - (char *)tempFaces._Myfirst) & 0xFFFFFFFC) == 0 )
      goto LABEL_25;
    v46 = &v37[*v31 - 1];
    v46->type = PT_LIST;
    v46->indices = (unsigned __int16 *)MemAlloc_Alloc(
                                         nSize: (unsigned __int64)(unsigned int)(3 * (tempFaces._Mylast - tempFaces._Myfirst)) >> 31 != 0
                                       ? -1
                                       : 6 * (tempFaces._Mylast - tempFaces._Myfirst));
    v46->numIndices = 3 * (tempFaces._Mylast - tempFaces._Myfirst);
    Mylast = tempFaces._Mylast;
    v25 = tempFaces._Myfirst;
    v47 = 0;
    if ( tempFaces._Mylast - tempFaces._Myfirst == 0 )
      goto LABEL_25;
    v48 = 0;
    do
    {
      v46->indices[v48] = v25[v47]->m_v0;
      v46->indices[v48 + 1] = tempFaces._Myfirst[v47]->m_v1;
      v46->indices[v48 + 2] = tempFaces._Myfirst[v47]->m_v2;
      Mylast = tempFaces._Mylast;
      v25 = tempFaces._Myfirst;
      ++v47;
      v48 += 3;
    }
    while ( v47 < tempFaces._Mylast - tempFaces._Myfirst );
    Myfirst = tempStrips._Myfirst;
  }
LABEL_52:
  v49 = 0;
  if ( tempStrips._Mylast - Myfirst != 0 )
  {
    do
    {
      v50 = Myfirst[v49];
      v51 = (char *)v50->m_faces._Mylast - (char *)v50->m_faces._Myfirst;
      v52 = &v50->m_faces;
      v53 = 0;
      if ( v51 >> 2 != 0 )
      {
        do
        {
          free(pMem: v52->_Myfirst[v53]);
          tempStrips._Myfirst[v49]->m_faces._Myfirst[v53] = nullptr;
          Myfirst = tempStrips._Myfirst;
          v54 = tempStrips._Myfirst[v49];
          v55 = (char *)v54->m_faces._Mylast - (char *)v54->m_faces._Myfirst;
          v52 = &v54->m_faces;
          ++v53;
        }
        while ( v53 < v55 >> 2 );
      }
      v56 = Myfirst[v49];
      if ( v56 != nullptr )
      {
        if ( v56->m_faces._Myfirst != nullptr )
          free(pMem: v56->m_faces._Myfirst);
        v56->m_faces._Myfirst = nullptr;
        v56->m_faces._Mylast = nullptr;
        v56->m_faces._Myend = nullptr;
        free(pMem: v56);
        Myfirst = tempStrips._Myfirst;
      }
      Myfirst[v49] = nullptr;
      Myfirst = tempStrips._Myfirst;
      ++v49;
    }
    while ( v49 < tempStrips._Mylast - tempStrips._Myfirst );
    Mylast = tempFaces._Mylast;
    v25 = tempFaces._Myfirst;
  }
  v57 = 0;
  if ( Mylast - v25 != 0 )
  {
    do
    {
      free(pMem: v25[v57]);
      tempFaces._Myfirst[v57] = nullptr;
      v25 = tempFaces._Myfirst;
      ++v57;
    }
    while ( v57 < tempFaces._Mylast - tempFaces._Myfirst );
  }
  if ( stripIndices._Myfirst != nullptr )
    free(pMem: stripIndices._Myfirst);
  memset(&stripIndices, 0, 12);
  NvStripifier::~NvStripifier(this: &stripifier);
  if ( tempFaces._Myfirst != nullptr )
    free(pMem: tempFaces._Myfirst);
  memset(&tempFaces, 0, 12);
  if ( tempStrips._Myfirst != nullptr )
    free(pMem: tempStrips._Myfirst);
  memset(&tempStrips, 0, 12);
  if ( tempIndices._Myfirst != nullptr )
    free(pMem: tempIndices._Myfirst);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB90
// Name: public: class NvFaceInfo __near * __near * std::allocator<class NvFaceInfo __near *>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall std::allocator<NvFaceInfo *>::allocate(std::allocator<int> *this, unsigned int _Count)
{
  int *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x3FFFFFFF || (result = (int *)MemAlloc_Alloc(nSize: 4 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AFCD0
// Name: protected: bool std::vector<unsigned short,class std::allocator<unsigned short>>::_Buy(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::vector<unsigned short>::_Buy(std::vector<unsigned short> *this, unsigned int _Capacity)
{
  unsigned __int16 *v4; // eax

  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
  if ( _Capacity == 0 )
    return 0;
  if ( _Capacity > 0x7FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  v4 = std::allocator<unsigned short>::allocate(this: &this->_Alval, _Count: _Capacity);
  this->_Myfirst = v4;
  this->_Mylast = v4;
  this->_Myend = &v4[_Capacity];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005AFD20
// Name: protected: class NvFaceInfo __near * __near * std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>>::_Umove<class NvFaceInfo __near * __near *>(class NvFaceInfo __near * __near *,class NvFaceInfo __near * __near *,class NvFaceInfo __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall std::vector<NvFaceInfo *>::_Umove<NvFaceInfo * *>(
        std::vector<int> *this,
        int *_First,
        int *_Last,
        int *_Ptr)
{
  int v4; // eax

  memmove(dst: (unsigned __int8 *)_Ptr, src: (unsigned __int8 *)_First, count: 4 * (_Last - _First));
  return (int *)(4 * (_Last - _First) + v4);
}

//------------------------------------------------------------------------------
// Address: 0x005B0040
// Name: public: void std::vector<int,class std::allocator<int>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<int>::reserve(std::vector<int> *this, unsigned int _Count)
{
  int *v3; // ebx
  int v4; // edi
  int v5; // [esp+0h] [ebp-20h] BYREF
  int *_Ptr; // [esp+Ch] [ebp-14h]
  int *v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = &v5;
  if ( _Count > 0x3FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = std::allocator<NvFaceInfo *>::allocate(this: &this->_Alval, _Count);
    _Ptr = v3;
    v8 = 0;
    std::vector<NvFaceInfo *>::_Umove<NvFaceInfo * *>(this, _First: this->_Myfirst, _Last: this->_Mylast, _Ptr: v3);
    v8 = -1;
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      free(pMem: this->_Myfirst);
    this->_Myend = &v3[_Count];
    this->_Mylast = &v3[v4];
    this->_Myfirst = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B04B0
// Name: public: void std::vector<int,class std::allocator<int>>::push_back(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<int>::push_back(std::vector<int> *this, int *_Val)
{
  int *Mylast; // eax
  int v4; // edi
  int *v5; // eax
  int *v6; // eax

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<NvFaceInfo *>::_Reserve(this, _Count: 1u);
    v6 = this->_Mylast;
    if ( v6 != nullptr )
      *v6 = *_Val;
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<NvFaceInfo *>::_Reserve(this, _Count: 1u);
    v5 = this->_Mylast;
    if ( v5 != nullptr )
    {
      *v5 = this->_Myfirst[v4];
      ++this->_Mylast;
      return;
    }
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x005B0520
// Name: public: class std::vector<unsigned short,class std::allocator<unsigned short>> __near & std::vector<unsigned short,class std::allocator<unsigned short>>::operator=(class std::vector<unsigned short,class std::allocator<unsigned short>> const __near &)
// Source: json
//------------------------------------------------------------------------------
std::vector<unsigned short> *__thiscall std::vector<unsigned short>::operator=(
        std::vector<unsigned short> *this,
        const std::vector<unsigned short> *_Right)
{
  unsigned __int16 *Mylast; // ecx
  unsigned __int8 *Myfirst; // eax
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v9; // ebx
  unsigned int v10; // edx
  unsigned __int8 *v11; // ebx
  unsigned int v12; // edi
  int v13; // eax
  unsigned __int8 *v14; // eax
  unsigned int v15; // edi
  int v16; // eax
  unsigned int _Righta; // [esp+10h] [ebp+8h]

  if ( this != _Right )
  {
    Mylast = _Right->_Mylast;
    Myfirst = (unsigned __int8 *)_Right->_Myfirst;
    _Righta = Mylast - _Right->_Myfirst;
    if ( _Righta != 0 )
    {
      v9 = (unsigned __int8 *)this->_Myfirst;
      v10 = this->_Mylast - this->_Myfirst;
      if ( _Righta <= v10 )
      {
        memmove(dst: v9, src: Myfirst, count: 2 * (((char *)Mylast - (char *)Myfirst) >> 1));
        this->_Mylast = &this->_Myfirst[_Right->_Mylast - _Right->_Myfirst];
        return this;
      }
      if ( _Righta <= ((char *)this->_Myend - (char *)v9) >> 1 )
      {
        v11 = &Myfirst[2 * v10];
        memmove(dst: (unsigned __int8 *)this->_Myfirst, src: Myfirst, count: 2 * ((int)(2 * v10) >> 1));
        v12 = 2 * (((char *)_Right->_Mylast - (char *)v11) >> 1);
        memmove(dst: (unsigned __int8 *)this->_Mylast, src: v11, count: v12);
        this->_Mylast = (unsigned __int16 *)(v12 + v13);
        return this;
      }
      if ( v9 != nullptr )
        free(pMem: v9);
      if ( std::vector<unsigned short>::_Buy(this, _Capacity: _Right->_Mylast - _Right->_Myfirst) != 0 )
      {
        v14 = (unsigned __int8 *)_Right->_Myfirst;
        v15 = 2 * (_Right->_Mylast - _Right->_Myfirst);
        memmove(dst: (unsigned __int8 *)this->_Myfirst, src: v14, count: v15);
        this->_Mylast = (unsigned __int16 *)(v15 + v16);
      }
    }
    else
    {
      v6 = (unsigned __int8 *)this->_Mylast;
      v7 = (unsigned __int8 *)this->_Myfirst;
      if ( (unsigned __int8 *)this->_Myfirst != v6 )
      {
        memmove(dst: v7, src: v6, count: 0);
        this->_Mylast = (unsigned __int16 *)v7;
        return this;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B0640
// Name: protected: void std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<NvFaceInfo *>::_Reserve(std::vector<int> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0x3FFFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0x3FFFFFFF - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<int>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B0910
// Name: public: void std::vector<unsigned short,class std::allocator<unsigned short>>::push_back(unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<unsigned short>::push_back(std::vector<unsigned short> *this, unsigned __int16 *_Val)
{
  unsigned __int16 *Mylast; // eax
  int v4; // edi
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<unsigned short>::_Reserve(this, _Count: 1u);
    v6 = this->_Mylast;
    if ( v6 != nullptr )
      *v6 = *_Val;
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<unsigned short>::_Reserve(this, _Count: 1u);
    v5 = this->_Mylast;
    if ( v5 != nullptr )
    {
      *v5 = this->_Myfirst[v4];
      ++this->_Mylast;
      return;
    }
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x005B0980
// Name: public: void std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>>::resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<NvEdgeInfo *>::resize(std::vector<NvEdgeInfo *> *this, unsigned int _Newsize)
{
  unsigned __int8 *Mylast; // ecx
  unsigned int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // edx

  Mylast = (unsigned __int8 *)this->_Mylast;
  v4 = (Mylast - (unsigned __int8 *)this->_Myfirst) >> 2;
  if ( v4 <= _Newsize )
  {
    if ( v4 < _Newsize )
    {
      std::vector<NvFaceInfo *>::_Reserve((std::vector<int> *)this, _Count: _Newsize - v4);
      v6 = this->_Mylast - this->_Myfirst;
      if ( _Newsize != v6 )
        memset(this->_Mylast, 0, 4 * (_Newsize - v6));
      this->_Mylast += _Newsize - (this->_Mylast - this->_Myfirst);
    }
  }
  else
  {
    v5 = (unsigned __int8 *)&this->_Myfirst[_Newsize];
    if ( v5 != Mylast )
    {
      memmove(dst: v5, src: Mylast, count: 0);
      this->_Mylast = (NvEdgeInfo **)v5;
    }
  }
}

} // namespace studiomdl
