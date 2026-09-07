// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/dt.cpp
// Functions: 65
// ============================================================

#include "engine\dt.h"

//------------------------------------------------------------------------------
// Address: 0x10131B60
// Name: void std::_Push_heap<int __near *,int,int,bool (*)(int const __near &,int const __near &)>(int __near *,int,int,int __near &&,bool (*)(int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        int *_First,
        int _Hole,
        int _Top,
        int *_Val,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int v5; // edi
  int v6; // esi
  bool v7; // zf
  int *v8; // eax

  v5 = _Hole;
  v6 = (_Hole - 1) / 2;
  if ( _Top >= _Hole )
  {
    _First[_Hole] = *_Val;
  }
  else
  {
    while ( 1 )
    {
      v7 = !_Pred(a1: &_First[v6], a2: _Val);
      v8 = _First;
      if ( v7 )
        break;
      _First[v5] = _First[v6];
      v5 = v6;
      v6 = (v6 - 1) / 2;
      if ( _Top >= v5 )
      {
        v8 = _First;
        break;
      }
    }
    v8[v5] = *_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132C70
// Name: void std::_Adjust_heap<int __near *,int,int,bool (*)(int const __near &,int const __near &)>(int __near *,int,int,int __near &&,bool (*)(int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        int *_First,
        int _Hole,
        int _Bottom,
        int *_Val,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  int v9; // esi

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      _First[v6] = _First[v7];
      v6 = v7;
      v7 = 2 * v7 + 2;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    _First[v6] = _First[v5 - 1];
    v6 = v5 - 1;
  }
  v9 = (v6 - 1) / 2;
  if ( _Hole >= v6 )
  {
    _First[v6] = *_Val;
  }
  else
  {
    while ( _Pred(a1: &_First[v9], a2: _Val) )
    {
      _First[v6] = _First[v9];
      v6 = v9;
      v9 = (v9 - 1) / 2;
      if ( _Hole >= v6 )
      {
        _First[v6] = *_Val;
        return;
      }
    }
    _First[v6] = *_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132F40
// Name: void std::_Make_heap<int __near *,int,int,bool (*)(int const __near &,int const __near &)>(int __near *,int __near *,bool (*)(int const __near &,int const __near &),int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        int *_First,
        int *_Last,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int v4; // ecx
  int v5; // ebx
  int i; // esi
  int v7; // eax
  int v8; // esi
  bool v9; // zf
  int v10; // eax
  int v11; // edx
  int _Val; // [esp+8h] [ebp-8h] BYREF
  int v13; // [esp+Ch] [ebp-4h]
  int _Bottom; // [esp+18h] [ebp+8h]
  int _Lasta; // [esp+1Ch] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    for ( i = 2 * v5 + 2; ; i = v13 )
    {
      v7 = _First[--v5];
      v8 = i - 2;
      v13 = v8;
      _Val = v7;
      _Lasta = v5;
      v9 = v8 == v4;
      if ( v8 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v8], a2: &_First[v8 - 1]) )
            --v8;
          v10 = _Lasta;
          v11 = _First[v8];
          _Lasta = v8;
          v8 = 2 * v8 + 2;
          _First[v10] = v11;
        }
        while ( v8 < _Bottom );
        v4 = _Bottom;
        v9 = v8 == _Bottom;
      }
      if ( v9 )
      {
        _First[_Lasta] = _First[v4 - 1];
        _Lasta = v4 - 1;
      }
      std::_Push_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        _First,
        _Hole: _Lasta,
        _Top: v5,
        &_Val,
        _Pred);
      if ( v5 <= 0 )
        break;
      v4 = _Bottom;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133C70
// Name: void std::_Sort_heap<int __near *,bool (*)(int const __near &,int const __near &)>(int __near *,int __near *,bool (*)(int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<int *,bool (__cdecl *)(int const &,int const &)>(
        char *_First,
        int *_Last,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int v3; // eax
  bool (__cdecl *v4)(const int *, const int *); // ebx
  int *v5; // edx
  int v6; // edi

  v3 = (char *)_Last - _First;
  if ( (int)(((char *)_Last - _First) & 0xFFFFFFFC) > 4 )
  {
    v4 = _Pred;
    do
    {
      v5 = *(int **)&_First[v3 - 4];
      v6 = v3 - 4;
      *(_DWORD *)&_First[v3 - 4] = *(_DWORD *)_First;
      _Last = v5;
      std::_Adjust_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        (int *)_First,
        _Hole: 0,
        _Bottom: (v3 - 4) >> 2,
        _Val: (int *)&_Last,
        _Pred: v4);
      v3 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101651E0
// Name: public: CDeltaBitsReader::CDeltaBitsReader(class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
CDeltaBitsReader *__thiscall CDeltaBitsReader::CDeltaBitsReader(CDeltaBitsReader *this, bf_read *pBuf)
{
  CDeltaBitsReader *result; // eax
  unsigned int m_nInBufWord; // esi
  int v4; // ecx
  const unsigned int *m_pDataIn; // esi
  const unsigned int *m_pBufferEnd; // edi
  bool v8; // cl
  unsigned int v9; // edi

  result = this;
  this->m_pBuf = pBuf;
  this->m_bFinished = false;
  this->m_iLastProp = -1;
  if ( pBuf != nullptr )
  {
    m_nInBufWord = pBuf->m_nInBufWord;
    v4 = m_nInBufWord & 1;
    if ( pBuf->m_nBitsAvail-- == 1 )
    {
      m_pDataIn = pBuf->m_pDataIn;
      m_pBufferEnd = pBuf->m_pBufferEnd;
      pBuf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pBuf->m_pDataIn = m_pDataIn + 1;
        pBuf->m_nBitsAvail = 1;
        pBuf->m_nInBufWord = 0;
        result->m_bUsingNewScheme = v4 != 0;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v9 = *m_pDataIn;
          pBuf->m_pDataIn = m_pDataIn + 1;
          pBuf->m_nInBufWord = v9;
          v8 = v4 != 0;
        }
        else
        {
          v8 = v4 != 0;
          pBuf->m_bOverflow = true;
          pBuf->m_nInBufWord = 0;
        }
        result->m_bUsingNewScheme = v8;
      }
    }
    else
    {
      pBuf->m_nInBufWord = m_nInBufWord >> 1;
      result->m_bUsingNewScheme = v4 != 0;
    }
  }
  else
  {
    this->m_bUsingNewScheme = false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10165290
// Name: public: int CDeltaBitsReader::ReadNextPropIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDeltaBitsReader::ReadNextPropIndex(CDeltaBitsReader *this)
{
  bf_read *m_pBuf; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  bool v5; // zf
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // edi
  bf_read *v9; // edx
  unsigned int v10; // ecx
  int v11; // edi
  const unsigned int *v12; // ecx
  const unsigned int *v13; // esi
  int m_nBitsAvail; // ecx
  unsigned int v15; // esi
  int v16; // ebx
  int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // esi
  const unsigned int *v20; // ecx
  const unsigned int *v21; // esi
  const unsigned int *v22; // edi
  unsigned int v23; // ebx
  int v24; // esi
  const unsigned int *v25; // ecx
  unsigned int v26; // edi
  unsigned int v27; // eax
  unsigned int v28; // edi
  int v29; // ecx
  unsigned int v30; // esi
  int v31; // edi
  int v32; // ecx
  int v33; // eax
  const unsigned int *v34; // ecx
  const unsigned int *v35; // esi
  const unsigned int *v36; // edi
  unsigned int v37; // ebx
  int v38; // esi
  const unsigned int *v39; // ecx
  unsigned int v40; // edi
  unsigned int v41; // eax
  int v42; // ecx
  int v43; // edi
  unsigned int v44; // esi
  int v45; // ecx
  int v46; // edi
  int v47; // esi
  unsigned int v48; // esi
  int v49; // edi
  const unsigned int *v50; // esi
  const unsigned int *v51; // edi
  unsigned int v52; // ecx
  unsigned int v53; // edi
  const unsigned int *v54; // ecx
  unsigned int v55; // ebx
  int v56; // esi
  const unsigned int *v57; // edi
  unsigned int v58; // edi
  unsigned int v59; // eax
  int v60; // edi
  unsigned int v61; // esi
  int v62; // ecx
  int v63; // edi
  const unsigned int *v64; // esi
  const unsigned int *v65; // edi
  const unsigned int *v66; // ecx
  unsigned int v67; // ebx
  int v68; // esi
  const unsigned int *v69; // edi
  unsigned int v70; // edi
  unsigned int v71; // eax
  int v72; // ebx
  int v73; // ecx
  int v75; // [esp+10h] [ebp-4h]

  if ( this->m_bUsingNewScheme )
  {
    m_pBuf = this->m_pBuf;
    m_nInBufWord = this->m_pBuf->m_nInBufWord;
    v4 = m_nInBufWord & 1;
    v5 = this->m_pBuf->m_nBitsAvail-- == 1;
    if ( v5 )
    {
      m_pDataIn = m_pBuf->m_pDataIn;
      m_pBufferEnd = m_pBuf->m_pBufferEnd;
      m_pBuf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        m_pBuf->m_nBitsAvail = 1;
        m_pBuf->m_nInBufWord = 0;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        m_pBuf->m_nInBufWord = *m_pDataIn;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        m_pBuf->m_bOverflow = true;
        m_pBuf->m_nInBufWord = 0;
      }
    }
    else
    {
      m_pBuf->m_nInBufWord = m_nInBufWord >> 1;
    }
    if ( v4 != 0 )
      return ++this->m_iLastProp;
  }
  v9 = this->m_pBuf;
  if ( this->m_bUsingNewScheme )
  {
    v10 = v9->m_nInBufWord;
    v11 = v10 & 1;
    v5 = v9->m_nBitsAvail-- == 1;
    if ( v5 )
    {
      v12 = v9->m_pDataIn;
      v13 = v9->m_pBufferEnd;
      v9->m_nBitsAvail = 32;
      if ( v12 == v13 )
      {
        v9->m_nBitsAvail = 1;
        v9->m_nInBufWord = 0;
        v9->m_pDataIn = v12 + 1;
      }
      else if ( v12 <= v13 )
      {
        v9->m_nInBufWord = *v12;
        v9->m_pDataIn = v12 + 1;
      }
      else
      {
        v9->m_bOverflow = true;
        v9->m_nInBufWord = 0;
      }
    }
    else
    {
      v9->m_nInBufWord = v10 >> 1;
    }
    if ( v11 != 0 )
    {
      m_nBitsAvail = v9->m_nBitsAvail;
      if ( m_nBitsAvail >= 3 )
      {
        v15 = v9->m_nInBufWord;
        v16 = v15 & 7;
        v17 = m_nBitsAvail - 3;
        v18 = 0;
        v9->m_nBitsAvail = v17;
        if ( v17 != 0 )
        {
          v9->m_nInBufWord = v15 >> 3;
          v19 = v15 & 7;
        }
        else
        {
          v20 = v9->m_pDataIn;
          v21 = v9->m_pBufferEnd;
          v9->m_nBitsAvail = 32;
          if ( v20 == v21 )
          {
            v9->m_nBitsAvail = 1;
            v9->m_pDataIn = v20 + 1;
            v9->m_nInBufWord = 0;
            v19 = v16;
          }
          else
          {
            if ( v20 <= v21 )
            {
              v18 = *v20;
              v9->m_pDataIn = v20 + 1;
            }
            else
            {
              v9->m_bOverflow = true;
            }
            v9->m_nInBufWord = v18;
            v19 = v16;
          }
        }
        goto LABEL_100;
      }
      v22 = v9->m_pBufferEnd;
      v23 = v9->m_nInBufWord;
      v24 = 3 - m_nBitsAvail;
      v25 = v9->m_pDataIn;
      if ( v25 == v22 )
      {
        v9->m_nBitsAvail = 1;
        v9->m_nInBufWord = 0;
        v9->m_bOverflow = true;
      }
      else
      {
        if ( v25 > v22 )
        {
          v9->m_bOverflow = true;
          v9->m_nInBufWord = 0;
          goto LABEL_35;
        }
        v9->m_nInBufWord = *v25;
      }
      v9->m_pDataIn = v25 + 1;
LABEL_35:
      if ( v9->m_bOverflow )
      {
        v19 = 0;
      }
      else
      {
        v26 = v9->m_nInBufWord;
        v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << v9->m_nBitsAvail;
        v9->m_nBitsAvail = 32 - v24;
        v28 = v26 >> v24;
        v19 = v27 | v23;
        v9->m_nInBufWord = v28;
      }
      goto LABEL_100;
    }
  }
  v29 = v9->m_nBitsAvail;
  if ( v29 < 7 )
  {
    v36 = v9->m_pBufferEnd;
    v37 = v9->m_nInBufWord;
    v38 = 7 - v29;
    v39 = v9->m_pDataIn;
    if ( v39 == v36 )
    {
      v9->m_nBitsAvail = 1;
      v9->m_nInBufWord = 0;
      v9->m_bOverflow = true;
    }
    else
    {
      if ( v39 > v36 )
      {
        v9->m_bOverflow = true;
        v9->m_nInBufWord = 0;
        goto LABEL_53;
      }
      v9->m_nInBufWord = *v39;
    }
    v9->m_pDataIn = v39 + 1;
LABEL_53:
    if ( v9->m_bOverflow )
    {
      v33 = 0;
      v75 = 0;
    }
    else
    {
      v40 = v9->m_nInBufWord;
      v41 = (v40 & CBitBuffer::s_nMaskTable[v38]) << v9->m_nBitsAvail;
      v9->m_nBitsAvail = 32 - v38;
      v33 = v41 | v37;
      v75 = v33;
      v9->m_nInBufWord = v40 >> v38;
    }
    goto LABEL_56;
  }
  v30 = v9->m_nInBufWord;
  v31 = v30 & 0x7F;
  v32 = v29 - 7;
  v9->m_nBitsAvail = v32;
  if ( v32 != 0 )
  {
    v33 = v30 & 0x7F;
    v9->m_nInBufWord = v30 >> 7;
    v75 = v33;
  }
  else
  {
    v34 = v9->m_pDataIn;
    v35 = v9->m_pBufferEnd;
    v9->m_nBitsAvail = 32;
    if ( v34 == v35 )
    {
      v9->m_nInBufWord = 0;
      v33 = v31;
      v9->m_nBitsAvail = 1;
      v9->m_pDataIn = v34 + 1;
      v75 = v31;
    }
    else
    {
      if ( v34 <= v35 )
      {
        v9->m_nInBufWord = *v34;
        v33 = v31;
        v9->m_pDataIn = v34 + 1;
      }
      else
      {
        v9->m_nInBufWord = 0;
        v33 = v31;
        v9->m_bOverflow = true;
      }
      v75 = v31;
    }
  }
LABEL_56:
  v42 = v33 & 0x60;
  v19 = v33;
  if ( v42 == 32 )
  {
    v60 = v9->m_nBitsAvail;
    if ( v60 >= 2 )
    {
      v61 = v9->m_nInBufWord;
      v62 = v61 & 3;
      v63 = v60 - 2;
      v9->m_nBitsAvail = v63;
      if ( v63 != 0 )
      {
        v9->m_nInBufWord = v61 >> 2;
      }
      else
      {
        v64 = v9->m_pDataIn;
        v65 = v9->m_pBufferEnd;
        v9->m_nBitsAvail = 32;
        if ( v64 == v65 )
        {
          v9->m_nBitsAvail = 1;
          v9->m_nInBufWord = 0;
          v9->m_pDataIn = v64 + 1;
        }
        else if ( v64 <= v65 )
        {
          v9->m_nInBufWord = *v64;
          v9->m_pDataIn = v64 + 1;
        }
        else
        {
          v9->m_bOverflow = true;
          v9->m_nInBufWord = 0;
        }
      }
LABEL_99:
      v19 = (32 * v62) | v33 & 0xFFFFFF9F;
      goto LABEL_100;
    }
    v66 = v9->m_pDataIn;
    v67 = v9->m_nInBufWord;
    v68 = 2 - v60;
    v69 = v9->m_pBufferEnd;
    if ( v66 == v69 )
    {
      v9->m_nBitsAvail = 1;
      v9->m_nInBufWord = 0;
      v9->m_bOverflow = true;
    }
    else
    {
      if ( v66 > v69 )
      {
        v9->m_bOverflow = true;
        v9->m_nInBufWord = 0;
        goto LABEL_96;
      }
      v9->m_nInBufWord = *v66;
    }
    v9->m_pDataIn = v66 + 1;
LABEL_96:
    if ( v9->m_bOverflow )
    {
      v62 = 0;
    }
    else
    {
      v70 = v9->m_nInBufWord;
      v71 = (v70 & CBitBuffer::s_nMaskTable[v68]) << v9->m_nBitsAvail;
      v9->m_nBitsAvail = 32 - v68;
      v72 = v71 | v67;
      v33 = v75;
      v62 = v72;
      v9->m_nInBufWord = v70 >> v68;
    }
    goto LABEL_99;
  }
  if ( v42 != 64 )
  {
    if ( v42 != 96 )
      goto LABEL_100;
    v43 = v9->m_nBitsAvail;
    if ( v43 >= 7 )
    {
      v44 = v9->m_nInBufWord;
      v45 = v44 & 0x7F;
      v46 = v43 - 7;
      v9->m_nBitsAvail = v46;
      if ( v46 != 0 )
      {
        v9->m_nInBufWord = v44 >> 7;
        v19 = v33 & 0xFFFFFF9F | (32 * v45);
        goto LABEL_100;
      }
LABEL_66:
      v50 = v9->m_pDataIn;
      v51 = v9->m_pBufferEnd;
      v9->m_nBitsAvail = 32;
      if ( v50 == v51 )
      {
        v9->m_pDataIn = v50 + 1;
        v9->m_nBitsAvail = 1;
        v9->m_nInBufWord = 0;
        v19 = v33 & 0xFFFFFF9F | (32 * v45);
      }
      else
      {
        if ( v50 <= v51 )
        {
          v53 = *v50;
          v52 = v33 & 0xFFFFFF9F | (32 * v45);
          v9->m_pDataIn = v50 + 1;
          v9->m_nInBufWord = v53;
        }
        else
        {
          v52 = v33 & 0xFFFFFF9F | (32 * v45);
          v9->m_bOverflow = true;
          v9->m_nInBufWord = 0;
        }
        v19 = v52;
      }
      goto LABEL_100;
    }
    v47 = 7;
LABEL_73:
    v54 = v9->m_pDataIn;
    v55 = v9->m_nInBufWord;
    v56 = v47 - v43;
    v57 = v9->m_pBufferEnd;
    if ( v54 == v57 )
    {
      v9->m_nBitsAvail = 1;
      v9->m_nInBufWord = 0;
      v9->m_bOverflow = true;
    }
    else
    {
      if ( v54 > v57 )
      {
        v9->m_bOverflow = true;
        v9->m_nInBufWord = 0;
        goto LABEL_79;
      }
      v9->m_nInBufWord = *v54;
    }
    v9->m_pDataIn = v54 + 1;
LABEL_79:
    if ( v9->m_bOverflow )
    {
      v19 = v33 & 0xFFFFFF9F;
    }
    else
    {
      v58 = v9->m_nInBufWord;
      v59 = (v58 & CBitBuffer::s_nMaskTable[v56]) << v9->m_nBitsAvail;
      v9->m_nBitsAvail = 32 - v56;
      v9->m_nInBufWord = v58 >> v56;
      v19 = v75 & 0xFFFFFF9F | (32 * (v59 | v55));
    }
    goto LABEL_100;
  }
  v43 = v9->m_nBitsAvail;
  if ( v43 < 4 )
  {
    v47 = 4;
    goto LABEL_73;
  }
  v48 = v9->m_nInBufWord;
  v45 = v48 & 0xF;
  v49 = v43 - 4;
  v9->m_nBitsAvail = v49;
  if ( v49 == 0 )
    goto LABEL_66;
  v9->m_nInBufWord = v48 >> 4;
  v19 = v33 & 0xFFFFFF9F | (32 * v45);
LABEL_100:
  if ( v19 == 4095 )
  {
    this->m_bFinished = true;
    return -1;
  }
  else
  {
    v73 = this->m_iLastProp + v19 + 1;
    this->m_iLastProp = v73;
    return v73;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165810
// Name: public: void CDeltaBitsReader::ForceFinished(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaBitsReader::ForceFinished(CDeltaBitsReader *this)
{
  this->m_bFinished = true;
  this->m_pBuf = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10165840
// Name: class ExcludeProp const __near * FindExcludeProp(char const __near *,char const __near *,class ExcludeProp const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const ExcludeProp *__cdecl FindExcludeProp(
        const char *pTableName,
        const char *pPropName,
        const ExcludeProp *pExcludeProps,
        int nExcludeProps)
{
  int v4; // esi

  v4 = 0;
  if ( nExcludeProps <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: pExcludeProps[v4].m_pTableName, s2: pTableName) != 0
       || _V_stricmp(s1: pExcludeProps[v4].m_pPropName, s2: pPropName) != 0 )
  {
    if ( ++v4 >= nExcludeProps )
      return nullptr;
  }
  return &pExcludeProps[v4];
}

//------------------------------------------------------------------------------
// Address: 0x10165890
// Name: SendTable_GetPropsExcluded
// Source: json
//------------------------------------------------------------------------------
char __cdecl SendTable_GetPropsExcluded(
        const SendTable *pTable,
        ExcludeProp *pExcludeProps,
        int *nExcludeProps,
        int nMaxExcludeProps)
{
  const SendTable *v4; // ecx
  SendProp *v5; // esi
  const char *m_pExcludeDTName; // ebx
  const SendTable *m_pDataTable; // esi
  int i; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]

  v4 = pTable;
  i = 0;
  if ( pTable->m_nProps <= 0 )
    return 1;
  for ( j = 0; ; ++j )
  {
    v5 = &v4->m_pProps[j];
    if ( (v5->m_Flags & 0x40) != 0 )
    {
      m_pExcludeDTName = v5->m_pExcludeDTName;
      if ( m_pExcludeDTName == nullptr )
        _Error(a1: "Found an exclude prop missing a name.");
      if ( *nExcludeProps >= nMaxExcludeProps )
        _Error(a1: "SendTable_GetPropsExcluded: Overflowed max exclude props with %s.", m_pExcludeDTName);
      pExcludeProps[*nExcludeProps].m_pTableName = m_pExcludeDTName;
      pExcludeProps[(*nExcludeProps)++].m_pPropName = v5->m_pVarName;
      goto LABEL_11;
    }
    m_pDataTable = v5->m_pDataTable;
    if ( m_pDataTable != nullptr
      && !SendTable_GetPropsExcluded(pTable: m_pDataTable, pExcludeProps, nExcludeProps, nMaxExcludeProps) )
    {
      break;
    }
LABEL_11:
    v4 = pTable;
    if ( ++i >= pTable->m_nProps )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10165950
// Name: bool AreBitArraysEqual(void const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AreBitArraysEqual(_BYTE *pvBits1, _BYTE *pvBits2, int nBits)
{
  int v3; // eax
  _BYTE *v4; // edi
  unsigned int v5; // ecx
  _BYTE *v6; // esi
  int v8; // edi

  v3 = nBits >> 3;
  v4 = pvBits1;
  v5 = nBits >> 3;
  v6 = pvBits2;
  if ( (unsigned int)(nBits >> 3) >= 4 )
  {
    while ( *(_DWORD *)v4 == *(_DWORD *)v6 )
    {
      v5 -= 4;
      v6 += 4;
      v4 += 4;
      if ( v5 < 4 )
        goto LABEL_4;
    }
    return 0;
  }
LABEL_4:
  if ( v5 != 0 && (*v6 != *v4 || v5 > 1 && (v6[1] != v4[1] || v5 > 2 && v6[2] != v4[2])) )
    return 0;
  v8 = 8 * v3;
  if ( 8 * v3 < nBits )
  {
    while ( ((unsigned __int8)(1 << (v8 & 7)) & pvBits1[v8 >> 3]) == ((unsigned __int8)(1 << (v8 & 7)) & pvBits2[v8 >> 3]) )
    {
      if ( ++v8 >= nBits )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10165A00
// Name: bool CompareBitArrays(void const __near *,void const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CompareBitArrays(_BYTE *pPacked1, _BYTE *pPacked2, int nBits1, int nBits2)
{
  if ( nBits1 < 0 || nBits1 != nBits2 )
    return 0;
  if ( pPacked1 == pPacked2 )
    return 1;
  return AreBitArraysEqual(pvBits1: pPacked1, pvBits2: pPacked2, nBits: nBits1);
}

//------------------------------------------------------------------------------
// Address: 0x10165A30
// Name: bool Sendprop_UsingDebugWatch(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Sendprop_UsingDebugWatch()
{
  bool result; // al
  char *m_pszString; // eax

  result = true;
  if ( g_CV_DTWatchEnt.m_pParent != nullptr
    && g_CV_DTWatchEnt.m_pParent->m_Value.m_nValue == -1
    && (g_CV_DTWatchClass.m_nFlags & 0x1000) == 0 )
  {
    m_pszString = g_CV_DTWatchClass.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr || *m_pszString == 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10165A70
// Name: void DataTable_Warning(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DataTable_Warning(char *pInMessage, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(params, pInMessage);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: pInMessage, params);
  _Warning(a1: "DataTable warning: %s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10165B30
// Name: public: void CUtlMemory<class CSendTablePrecalc::CProxyPathEntry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSendTablePrecalc::CProxyPathEntry,int>::Grow(
        CUtlMemory<SendProp const *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  const SendProp **m_pMemory; // ecx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (const SendProp **)_realloc_crt(ptr: m_pMemory, size: 4 * m_nAllocationCount);
    else
      this->m_pMemory = (const SendProp **)MemAlloc_Alloc(nSize: 4 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165BD0
// Name: public: CDeltaBitsWriter::CDeltaBitsWriter(class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
CDeltaBitsWriter *__thiscall CDeltaBitsWriter::CDeltaBitsWriter(CDeltaBitsWriter *this, bf_write *pBuf)
{
  int m_nValue; // eax
  bool v4; // al
  int m_iCurBit; // ecx
  int v6; // edi

  this->m_pBuf = pBuf;
  this->m_iLastProp = -1;
  if ( sv_new_delta_bits.m_pParent != nullptr )
    m_nValue = sv_new_delta_bits.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v4 = m_nValue != 0;
  this->m_bUsingNewScheme = v4;
  m_iCurBit = pBuf->m_iCurBit;
  v6 = m_iCurBit + 1;
  if ( v4 )
  {
    if ( v6 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++pBuf->m_iCurBit;
      return this;
    }
  }
  else
  {
    if ( v6 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      pBuf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++pBuf->m_iCurBit;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10165C70
// Name: public: CDeltaBitsWriter::~CDeltaBitsWriter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaBitsWriter::~CDeltaBitsWriter(CDeltaBitsWriter *this)
{
  bf_write *m_pBuf; // eax
  int m_iCurBit; // ecx
  bf_write *v4; // eax
  int v5; // ecx

  if ( this->m_bUsingNewScheme )
  {
    m_pBuf = this->m_pBuf;
    m_iCurBit = this->m_pBuf->m_iCurBit;
    if ( m_iCurBit + 1 > this->m_pBuf->m_nDataBits )
      m_pBuf->m_bOverflow = true;
    if ( !m_pBuf->m_bOverflow )
    {
      m_pBuf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++m_pBuf->m_iCurBit;
    }
  }
  v4 = this->m_pBuf;
  if ( this->m_bUsingNewScheme )
  {
    v5 = v4->m_iCurBit;
    if ( v5 + 1 > v4->m_nDataBits )
      v4->m_bOverflow = true;
    if ( !v4->m_bOverflow )
    {
      v4->m_pData[v5 >> 3] &= ~(1 << (v5 & 7));
      ++v4->m_iCurBit;
    }
  }
  bf_write::WriteUBitLong(this: v4, curData: 0x3FFFu, numbits: 14, bCheckRange: true);
}

//------------------------------------------------------------------------------
// Address: 0x10165CF0
// Name: public: void CDeltaBitsWriter::WritePropIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaBitsWriter::WritePropIndex(CDeltaBitsWriter *this, int iProp)
{
  unsigned int v3; // eax
  bool v4; // zf
  bf_write *v5; // edi
  int m_iCurBit; // ecx
  bf_write *v7; // esi
  int v8; // ecx
  bf_write *v9; // esi
  int v10; // ecx
  int v11; // edi
  bf_write *m_pBuf; // ecx

  v3 = iProp - this->m_iLastProp - 1;
  v4 = !this->m_bUsingNewScheme;
  this->m_iLastProp = iProp;
  if ( v4 )
  {
    m_pBuf = this->m_pBuf;
    if ( v3 >= 0x20 )
    {
      if ( v3 >= 0x80 )
      {
        if ( v3 >= 0x200 )
          bf_write::WriteUBitLong(
            this: m_pBuf,
            curData: v3 & 0x1F | (4 * (v3 & 0xFE0 | 0x18)),
            numbits: 14,
            bCheckRange: true);
        else
          bf_write::WriteUBitLong(
            this: m_pBuf,
            curData: v3 & 0x1F | (4 * (v3 & 0x1E0 | 0x10)),
            numbits: 11,
            bCheckRange: true);
      }
      else
      {
        bf_write::WriteUBitLong(this: m_pBuf, curData: v3 & 0x1F | (4 * (v3 & 0x60 | 8)), numbits: 9, bCheckRange: true);
      }
    }
    else
    {
      bf_write::WriteUBitLong(this: m_pBuf, curData: v3, numbits: 7, bCheckRange: true);
    }
    return;
  }
  if ( v3 == 0 )
  {
    v5 = this->m_pBuf;
    m_iCurBit = this->m_pBuf->m_iCurBit;
    if ( m_iCurBit + 1 > v5->m_nDataBits )
      v5->m_bOverflow = true;
    if ( !v5->m_bOverflow )
    {
      v5->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++v5->m_iCurBit;
    }
    return;
  }
  v7 = this->m_pBuf;
  v8 = this->m_pBuf->m_iCurBit;
  if ( v8 + 1 > this->m_pBuf->m_nDataBits )
    v7->m_bOverflow = true;
  if ( !v7->m_bOverflow )
  {
    v7->m_pData[v8 >> 3] &= ~(1 << (v8 & 7));
    ++v7->m_iCurBit;
  }
  v9 = this->m_pBuf;
  if ( !this->m_bUsingNewScheme )
  {
LABEL_23:
    if ( v3 >= 0x20 )
    {
      if ( v3 >= 0x80 )
      {
        if ( v3 >= 0x200 )
          bf_write::WriteUBitLong(
            this: v9,
            curData: v3 & 0x1F | (4 * (v3 & 0xFE0 | 0x18)),
            numbits: 14,
            bCheckRange: true);
        else
          bf_write::WriteUBitLong(
            this: v9,
            curData: v3 & 0x1F | (4 * (v3 & 0x1E0 | 0x10)),
            numbits: 11,
            bCheckRange: true);
      }
      else
      {
        bf_write::WriteUBitLong(this: v9, curData: v3 & 0x1F | (4 * (v3 & 0x60 | 8)), numbits: 9, bCheckRange: true);
      }
    }
    else
    {
      bf_write::WriteUBitLong(this: v9, curData: v3, numbits: 7, bCheckRange: true);
    }
    return;
  }
  v10 = v9->m_iCurBit;
  v11 = v10 + 1;
  if ( v3 >= 8 )
  {
    if ( v11 > v9->m_nDataBits )
      v9->m_bOverflow = true;
    if ( !v9->m_bOverflow )
    {
      v9->m_pData[v10 >> 3] &= ~(1 << (v10 & 7));
      ++v9->m_iCurBit;
    }
    goto LABEL_23;
  }
  if ( v11 > v9->m_nDataBits )
    v9->m_bOverflow = true;
  if ( !v9->m_bOverflow )
  {
    v9->m_pData[v10 >> 3] |= 1 << (v10 & 7);
    ++v9->m_iCurBit;
  }
  bf_write::WriteUBitLong(this: v9, curData: v3, numbits: 3, bCheckRange: true);
}

//------------------------------------------------------------------------------
// Address: 0x10165F00
// Name: bool ShouldWatchThisProp(class SendTable const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldWatchThisProp(const SendTable *pTable, int objectID, const char *pPropName)
{
  int m_nValue; // eax
  char *v4; // eax
  char *v5; // eax
  char *m_pszString; // eax

  if ( g_CV_DTEncode.m_pParent != nullptr && g_CV_DTEncode.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( g_CV_DTWatchEnt.m_pParent != nullptr )
    {
      m_nValue = g_CV_DTWatchEnt.m_pParent->m_Value.m_nValue;
      if ( m_nValue == -1 )
        goto LABEL_5;
    }
    else
    {
      m_nValue = 0;
    }
    if ( m_nValue == objectID )
    {
      if ( (g_CV_DTWatchVar.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = g_CV_DTWatchVar.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr || *m_pszString == 0 )
          return 1;
      }
      return _V_stricmp(s1: m_pszString, s2: pPropName) == 0;
    }
LABEL_5:
    if ( (g_CV_DTWatchClass.m_nFlags & 0x1000) == 0 )
    {
      v4 = g_CV_DTWatchClass.m_pParent->m_Value.m_pszString;
      if ( v4 == nullptr || *v4 == 0 )
        return 0;
    }
    if ( (g_CV_DTWatchClass.m_nFlags & 0x1000) != 0 )
    {
      v5 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v5 = g_CV_DTWatchClass.m_pParent->m_Value.m_pszString;
      if ( v5 == nullptr )
        v5 = (char *)defaultValue;
    }
    return V_stristr(pStr: pTable->m_pNetTableName, pSearch: v5) != nullptr;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10165FC0
// Name: bool ShouldWatchThisProp(class RecvTable const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldWatchThisProp(const RecvTable *pTable, int objectID, const char *pPropName)
{
  int m_nValue; // eax
  char *v4; // eax
  char *v5; // eax
  char *m_pszString; // eax

  if ( g_CV_DTDecode.m_pParent != nullptr && g_CV_DTDecode.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( g_CV_DTWatchEnt.m_pParent != nullptr )
    {
      m_nValue = g_CV_DTWatchEnt.m_pParent->m_Value.m_nValue;
      if ( m_nValue == -1 )
        goto LABEL_5;
    }
    else
    {
      m_nValue = 0;
    }
    if ( m_nValue == objectID )
    {
      if ( (g_CV_DTWatchVar.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = g_CV_DTWatchVar.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr || *m_pszString == 0 )
          return 1;
      }
      return _V_stricmp(s1: m_pszString, s2: pPropName) == 0;
    }
LABEL_5:
    if ( (g_CV_DTWatchClass.m_nFlags & 0x1000) == 0 )
    {
      v4 = g_CV_DTWatchClass.m_pParent->m_Value.m_pszString;
      if ( v4 == nullptr || *v4 == 0 )
        return 0;
    }
    if ( (g_CV_DTWatchClass.m_nFlags & 0x1000) != 0 )
    {
      v5 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v5 = g_CV_DTWatchClass.m_pParent->m_Value.m_pszString;
      if ( v5 == nullptr )
        v5 = (char *)defaultValue;
    }
    return V_stristr(pStr: pTable->m_pNetTableName, pSearch: v5) != nullptr;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10166080
// Name: void std::_Rotate<unsigned char __near *,int,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char __near *,int __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Rotate<unsigned char *,int,unsigned char>(
        unsigned __int8 *_First,
        unsigned __int8 *_Mid,
        unsigned __int8 *_Last)
{
  unsigned __int8 *v3; // ecx
  int v5; // esi
  unsigned __int8 *v6; // edx
  int v7; // eax
  int v8; // ebx
  int v9; // edx
  unsigned __int8 *v10; // ebx
  unsigned __int8 *v11; // edx
  unsigned __int8 *v12; // eax
  int v13; // ecx
  unsigned __int8 *v14; // [esp+14h] [ebp-8h]
  unsigned __int8 *_Next; // [esp+28h] [ebp+Ch]
  unsigned __int8 *_Nexta; // [esp+28h] [ebp+Ch]
  unsigned __int8 _Next_3; // [esp+2Bh] [ebp+Fh]
  int _Count; // [esp+2Ch] [ebp+10h]

  v3 = _First;
  v5 = _Mid - _First;
  v6 = (unsigned __int8 *)(_Last - _First);
  _Next = (unsigned __int8 *)(_Last - _First);
  v7 = _Last - _First;
  _Count = _Last - _First;
  v8 = v5;
  if ( v5 != 0 )
  {
    do
    {
      v9 = v7 % v8;
      v7 = v8;
      v8 = v9;
    }
    while ( v9 != 0 );
    v6 = _Next;
    _Count = v7;
  }
  if ( v7 < (int)v6 && v7 > 0 )
  {
    v10 = &_First[v7];
    v14 = &_First[v7];
    while ( 1 )
    {
      v11 = &v10[v5];
      v12 = v10;
      if ( &v10[v5] == _Last )
        v11 = v3;
      v13 = -(int)v11;
      do
      {
        _Next_3 = *v12;
        *v12 = *v11;
        *v11 = _Next_3;
        v12 = v11;
        _Nexta = v11;
        if ( v5 >= (int)&_Last[v13] )
        {
          v11 = &_First[v5 - (_DWORD)_Last + (_DWORD)v11];
          v13 = &_Last[v13 - v5] - _First;
          v12 = _Nexta;
        }
        else
        {
          v11 += v5;
          v13 -= v5;
        }
      }
      while ( v11 != v14 );
      v10 = v14 - 1;
      --_Count;
      --v14;
      if ( _Count <= 0 )
        break;
      v3 = _First;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166150
// Name: SetDataTableProxyIndices_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetDataTableProxyIndices_R(
        CSendTablePrecalc *pMainTable,
        CSendNode *pCurTable,
        CBuildHierarchyStruct *bhs)
{
  int i; // esi
  CSendNode *v4; // eax

  for ( i = 0; i < pCurTable->m_Children.m_Size; ++i )
  {
    v4 = pCurTable->m_Children.m_Memory.m_pMemory[i];
    if ( (bhs->m_pDatatableProps[v4->m_iDatatableProp]->m_Flags & 0x200) != 0 )
    {
      v4->m_DataTableProxyIndex = 255;
    }
    else
    {
      v4->m_DataTableProxyIndex = pMainTable->m_nDataTableProxies;
      ++pMainTable->m_nDataTableProxies;
    }
    SetDataTableProxyIndices_R(pMainTable, pCurTable: v4, bhs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101661B0
// Name: SetRecursiveProxyIndices_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetRecursiveProxyIndices_R(SendTable *pBaseTable, CSendNode *pCurTable, int *iCurProxyIndex)
{
  int i; // esi

  if ( *iCurProxyIndex >= 64 )
    _Error(a1: "Too many proxies for datatable %s.", pBaseTable->m_pNetTableName);
  pCurTable->m_RecursiveProxyIndex = *(_WORD *)iCurProxyIndex;
  ++*iCurProxyIndex;
  for ( i = 0; i < pCurTable->m_Children.m_Size; ++i )
    SetRecursiveProxyIndices_R(pBaseTable, pCurTable: pCurTable->m_Children.m_Memory.m_pMemory[i], iCurProxyIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10166210
// Name: void CalcPathLengths_R(class CSendNode __near *,class CUtlVector<int,class CUtlMemory<int,int>> __near &,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcPathLengths_R(
        CSendNode *pNode,
        CUtlVector<int,CUtlMemory<int,int> > *pathLengths,
        int curPathLength,
        int *totalPathLengths)
{
  int i; // esi

  pathLengths->m_Memory.m_pMemory[pNode->m_RecursiveProxyIndex] = curPathLength;
  *totalPathLengths += curPathLength;
  for ( i = 0; i < pNode->m_Children.m_Size; ++i )
    CalcPathLengths_R(
      pNode: pNode->m_Children.m_Memory.m_pMemory[i],
      pathLengths,
      curPathLength: curPathLength + 1,
      totalPathLengths);
}

//------------------------------------------------------------------------------
// Address: 0x10166260
// Name: void FillPathEntries_R(class CSendTablePrecalc __near *,class CSendNode __near *,class CSendNode __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FillPathEntries_R(CSendTablePrecalc *pPrecalc, CSendNode *pNode, CSendNode *pParent, int *iCurEntry)
{
  CSendTablePrecalc *v4; // ebx
  CSendNode *v5; // edi
  CSendTablePrecalc::CProxyPath *v6; // eax
  CSendTablePrecalc::CProxyPath *v7; // ecx
  int v8; // eax
  int v9; // edx
  int i; // [esp+14h] [ebp+8h]

  v4 = pPrecalc;
  v5 = pNode;
  v6 = &pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[pNode->m_RecursiveProxyIndex];
  v6->m_iFirstEntry = *(_WORD *)iCurEntry;
  if ( pParent != nullptr )
  {
    v7 = &pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[pParent->m_RecursiveProxyIndex];
    v6->m_nEntries = v7->m_nEntries + 1;
    v8 = 0;
    if ( v7->m_nEntries != 0 )
    {
      do
      {
        v9 = (*iCurEntry)++;
        v4->m_ProxyPathEntries.m_Memory.m_pMemory[v9] = v4->m_ProxyPathEntries.m_Memory.m_pMemory[v8 + v7->m_iFirstEntry];
        v4 = pPrecalc;
        ++v8;
      }
      while ( v8 < v7->m_nEntries );
      v5 = pNode;
    }
    v4->m_ProxyPathEntries.m_Memory.m_pMemory[*iCurEntry].m_iProxy = v5->m_RecursiveProxyIndex;
    v4->m_ProxyPathEntries.m_Memory.m_pMemory[(*iCurEntry)++].m_iDatatableProp = v5->m_iDatatableProp;
  }
  else
  {
    v6->m_nEntries = 0;
  }
  for ( i = 0; i < v5->m_Children.m_Size; ++i )
    FillPathEntries_R(pPrecalc: v4, pNode: v5->m_Children.m_Memory.m_pMemory[i], pParent: v5, iCurEntry);
}

//------------------------------------------------------------------------------
// Address: 0x10166330
// Name: struct std::pair<unsigned char __near *,int> std::get_temporary_buffer<unsigned char>(int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101663D0
// Name: void std::_Insertion_sort1<unsigned char __near *,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Insertion_sort1<unsigned char *,unsigned char>(unsigned __int8 *_First, unsigned __int8 *_Last)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // esi
  int i; // eax
  unsigned __int8 v5; // bl
  unsigned __int8 *v6; // edi
  unsigned __int8 v7; // cl
  unsigned __int8 *j; // eax

  v2 = _First;
  if ( _First != _Last )
  {
    v3 = _First + 1;
    if ( _First + 1 != _Last )
    {
      for ( i = 1 - (_DWORD)_First; ; i = 1 - (_DWORD)_First )
      {
        v5 = *v3;
        v6 = v3;
        if ( *v3 >= *v2 )
        {
          v7 = *(v3 - 1);
          for ( j = v3 - 1; v5 < v7; --j )
          {
            *v6 = v7;
            v7 = *(j - 1);
            v6 = j;
          }
          *v6 = v5;
        }
        else
        {
          memmove(dst: (unsigned __int8 *)(1 - i + 1), src: v2, count: (unsigned int)&v3[i - 1]);
          v2 = _First;
          *_First = v5;
        }
        if ( ++v3 == _Last )
          break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166440
// Name: unsigned char __near * std::_Merge<unsigned char __near *,unsigned char __near *,unsigned char __near *>(unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl std::_Merge<unsigned char *,unsigned char *,unsigned char *>(
        unsigned __int8 *_First1,
        unsigned __int8 *_Last1,
        unsigned __int8 *_First2,
        unsigned __int8 *_Last2,
        unsigned __int8 *_Dest)
{
  unsigned __int8 *i; // eax
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // esi

  for ( i = _First1; i != _Last1; ++_Dest )
  {
    if ( _First2 == _Last2 )
      break;
    if ( *_First2 >= *i )
      *_Dest = *i++;
    else
      *_Dest = *_First2++;
  }
  v8 = (unsigned __int8 *)(_Last1 - i);
  memmove(dst: _Dest, src: i, count: _Last1 - i);
  v9 = &_Dest[(_DWORD)v8];
  memmove(dst: v9, src: _First2, count: _Last2 - _First2);
  return &v9[_Last2 - _First2];
}

//------------------------------------------------------------------------------
// Address: 0x101664A0
// Name: unsigned char __near * std::_Merge_backward<unsigned char __near *,unsigned char __near *,unsigned char __near *>(unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl std::_Merge_backward<unsigned char *,unsigned char *,unsigned char *>(
        unsigned __int8 *_First1,
        unsigned __int8 *_Last1,
        unsigned __int8 *_First2,
        unsigned __int8 *_Last2,
        unsigned __int8 *_Dest)
{
  unsigned __int8 *v5; // eax
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  unsigned __int8 *v10; // edi
  unsigned __int8 *v12; // edi

  v5 = _Last1;
  if ( _First1 == _Last1 )
  {
LABEL_7:
    v10 = &_Dest[-(_Last2 - _First2)];
    memmove(dst: v10, src: _First2, count: _Last2 - _First2);
    return v10;
  }
  else
  {
    while ( _First2 != _Last2 )
    {
      v8 = *(_Last2 - 1);
      v9 = *(v5 - 1);
      --_Last2;
      --v5;
      --_Dest;
      if ( v8 >= v9 )
      {
        *_Dest = v8;
        ++v5;
      }
      else
      {
        *_Dest = v9;
        ++_Last2;
      }
      if ( _First1 == v5 )
        goto LABEL_7;
    }
    v12 = &_Dest[-(v5 - _First1)];
    memmove(dst: v12, src: _First1, count: v5 - _First1);
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166510
// Name: unsigned char __near * std::lower_bound<unsigned char __near *,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl std::lower_bound<unsigned char *,unsigned char>(
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        const unsigned __int8 *_Val)
{
  unsigned __int8 *v3; // esi
  int v4; // ecx
  int v5; // eax

  v3 = _First;
  v4 = _Last - _First;
  while ( v4 > 0 )
  {
    v5 = v4 / 2;
    if ( v3[v4 / 2] >= *_Val )
    {
      v4 /= 2;
    }
    else
    {
      v3 += v5 + 1;
      v4 += -1 - v5;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10166550
// Name: unsigned char __near * std::upper_bound<unsigned char __near *,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl std::upper_bound<unsigned char *,unsigned char>(
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        const unsigned __int8 *_Val)
{
  unsigned __int8 *v3; // esi
  int v4; // ecx
  int v5; // eax

  v3 = _First;
  v4 = _Last - _First;
  while ( v4 > 0 )
  {
    v5 = v4 / 2;
    if ( *_Val < v3[v4 / 2] )
    {
      v4 /= 2;
    }
    else
    {
      v3 += v5 + 1;
      v4 += -1 - v5;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10166590
// Name: class std::_Temp_iterator<unsigned char> std::_Move<unsigned char __near *,class std::_Temp_iterator<unsigned char>>(unsigned char __near *,unsigned char __near *,class std::_Temp_iterator<unsigned char>,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
std::_Temp_iterator<unsigned char> *__cdecl std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
        std::_Temp_iterator<unsigned char> *result,
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        std::_Temp_iterator<unsigned char> _Dest)
{
  unsigned __int8 *i; // ecx
  std::_Temp_iterator<unsigned char>::_Bufpar *Pbuf; // edx
  unsigned __int8 *Current; // eax

  for ( i = _First; i != _Last; ++i )
  {
    Pbuf = _Dest._Pbuf;
    Current = _Dest._Pbuf->_Current;
    if ( Current >= _Dest._Pbuf->_Hiwater )
    {
      if ( Current != nullptr )
      {
        *Current = *i;
        Pbuf = _Dest._Pbuf;
      }
      _Dest._Pbuf->_Hiwater = ++Pbuf->_Current;
    }
    else
    {
      *Current = *i;
      ++_Dest._Pbuf->_Current;
    }
  }
  result->_Pbuf = _Dest._Pbuf;
  result->_Buf._Begin = nullptr;
  result->_Buf._Current = nullptr;
  result->_Buf._Hiwater = nullptr;
  result->_Buf._Size = 0;
  if ( _Dest._Buf._Begin != nullptr )
    free(pMem: _Dest._Buf._Begin);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166620
// Name: public: int std::_Temp_iterator<unsigned char>::_Maxlen(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::_Temp_iterator<unsigned char>::_Maxlen(std::_Temp_iterator<unsigned char> *this)
{
  std::_Temp_iterator<unsigned char>::_Bufpar *Pbuf; // eax
  bool v3; // zf
  int result; // eax
  unsigned __int8 *first; // eax
  std::pair<unsigned char *,int> _Pair; // [esp+4h] [ebp-8h] BYREF

  Pbuf = this->_Pbuf;
  v3 = Pbuf->_Begin == nullptr;
  result = Pbuf->_Size;
  if ( v3 )
  {
    if ( result <= 0 )
    {
      return this->_Pbuf->_Size;
    }
    else
    {
      std::get_temporary_buffer<unsigned char>(result: &_Pair, _Count: result);
      first = _Pair.first;
      this->_Pbuf->_Begin = _Pair.first;
      this->_Pbuf->_Current = first;
      this->_Pbuf->_Hiwater = first;
      this->_Pbuf->_Size = _Pair.second;
      return this->_Pbuf->_Size;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101666F0
// Name: void std::_Chunked_merge<unsigned char __near *,unsigned char __near *,int>(unsigned char __near *,unsigned char __near *,unsigned char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Chunked_merge<unsigned char *,unsigned char *,int>(
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        unsigned __int8 *_Dest,
        int _Chunk,
        int _Count)
{
  int i; // edx
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // ebx
  unsigned __int8 *j; // edi
  unsigned __int8 *v11; // esi
  unsigned __int8 *v12; // edi
  unsigned __int8 *k; // ebx
  unsigned int v14; // edi
  int v15; // [esp+Ch] [ebp-8h]
  unsigned __int8 *_Mid2; // [esp+10h] [ebp-4h]

  for ( i = _Chunk; _Count >= 2 * _Chunk; i = _Chunk )
  {
    v8 = &_First[i];
    _Mid2 = &_First[i + i];
    v9 = &_First[i];
    for ( j = _First; j != v8; ++_Dest )
    {
      if ( v9 == _Mid2 )
        break;
      if ( *v9 >= *j )
        *_Dest = *j++;
      else
        *_Dest = *v9++;
    }
    v15 = v8 - j;
    memmove(dst: _Dest, src: j, count: v8 - j);
    v11 = &_Dest[v15];
    memmove(dst: v11, src: v9, count: _Mid2 - v9);
    _First = _Mid2;
    _Dest = &v11[_Mid2 - v9];
    _Count -= 2 * _Chunk;
  }
  if ( _Count > i )
  {
    v12 = &_First[i];
    for ( k = &_First[i]; _First != v12; ++_Dest )
    {
      if ( k == _Last )
        break;
      if ( *k >= *_First )
        *_Dest = *_First++;
      else
        *_Dest = *k++;
    }
    v14 = v12 - _First;
    memmove(dst: _Dest, src: _First, count: v14);
    memmove(dst: &_Dest[v14], src: k, count: _Last - k);
  }
  else
  {
    memmove(dst: _Dest, src: _First, count: _Last - _First);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101667E0
// Name: class std::_Temp_iterator<unsigned char> std::_Move<unsigned char __near *,class std::_Temp_iterator<unsigned char>>(unsigned char __near *,unsigned char __near *,class std::_Temp_iterator<unsigned char>)
// Source: json
//------------------------------------------------------------------------------
std::_Temp_iterator<unsigned char> *__cdecl std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
        std::_Temp_iterator<unsigned char> *result,
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        std::_Temp_iterator<unsigned char> _Dest)
{
  std::_Temp_iterator<unsigned char> v5; // [esp-18h] [ebp-1Ch] BYREF

  memset(&v5, 0, 16);
  v5._Pbuf = _Dest._Pbuf;
  std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(result, _First, _Last, _Dest: v5);
  if ( _Dest._Buf._Begin != nullptr )
    free(pMem: _Dest._Buf._Begin);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166840
// Name: class std::_Temp_iterator<unsigned char> std::_Merge<unsigned char __near *,unsigned char __near *,class std::_Temp_iterator<unsigned char>>(unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *,class std::_Temp_iterator<unsigned char>)
// Source: json
//------------------------------------------------------------------------------
std::_Temp_iterator<unsigned char> *__cdecl std::_Merge<unsigned char *,unsigned char *,std::_Temp_iterator<unsigned char>>(
        std::_Temp_iterator<unsigned char> *result,
        unsigned __int8 *_First1,
        unsigned __int8 *_Last1,
        unsigned __int8 *_First2,
        unsigned __int8 *_Last2,
        std::_Temp_iterator<unsigned char> _Dest)
{
  unsigned __int8 *v7; // esi
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  std::_Temp_iterator<unsigned char>::_Bufpar *v10; // ecx
  unsigned __int8 *v11; // eax
  std::_Temp_iterator<unsigned char>::_Bufpar *Pbuf; // edx
  unsigned __int8 *Current; // eax
  std::_Temp_iterator<unsigned char> v15; // [esp-18h] [ebp-38h] BYREF
  std::_Temp_iterator<unsigned char> v16; // [esp+Ch] [ebp-14h] BYREF

  v7 = _First1;
  while ( v7 != _Last1 )
  {
    if ( _First2 == _Last2 )
      break;
    v8 = *v7;
    v9 = *_First2;
    if ( *_First2 >= *v7 )
    {
      Pbuf = _Dest._Pbuf;
      Current = _Dest._Pbuf->_Current;
      if ( Current >= _Dest._Pbuf->_Hiwater )
      {
        if ( Current != nullptr )
        {
          *Current = v8;
          Pbuf = _Dest._Pbuf;
        }
        _Dest._Pbuf->_Hiwater = ++Pbuf->_Current;
      }
      else
      {
        *Current = v8;
        ++_Dest._Pbuf->_Current;
      }
      ++v7;
    }
    else
    {
      v10 = _Dest._Pbuf;
      v11 = _Dest._Pbuf->_Current;
      if ( v11 >= _Dest._Pbuf->_Hiwater )
      {
        if ( v11 != nullptr )
        {
          *v11 = v9;
          v10 = _Dest._Pbuf;
        }
        _Dest._Pbuf->_Hiwater = ++v10->_Current;
        ++_First2;
      }
      else
      {
        *v11 = v9;
        ++_Dest._Pbuf->_Current;
        ++_First2;
      }
    }
  }
  v15._Pbuf = _Dest._Pbuf;
  memset(&v15, 0, 16);
  std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(result: &v16, _First: v7, _Last: _Last1, _Dest: v15);
  _Dest._Pbuf = v16._Pbuf;
  if ( v16._Buf._Begin != nullptr )
    free(pMem: v16._Buf._Begin);
  memset(&v15, 0, 16);
  v15._Pbuf = _Dest._Pbuf;
  std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(result, _First: _First2, _Last: _Last2, _Dest: v15);
  if ( _Dest._Buf._Begin != nullptr )
    free(pMem: _Dest._Buf._Begin);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166A10
// Name: void std::_Chunked_merge<unsigned char __near *,class std::_Temp_iterator<unsigned char>,int>(unsigned char __near *,unsigned char __near *,class std::_Temp_iterator<unsigned char>,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Chunked_merge<unsigned char *,std::_Temp_iterator<unsigned char>,int>(
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        std::_Temp_iterator<unsigned char> _Dest,
        int _Chunk,
        int _Count)
{
  int i; // ecx
  unsigned __int8 *v7; // esi
  _QWORD v8[3]; // [esp-18h] [ebp-38h] BYREF
  std::_Temp_iterator<unsigned char> result; // [esp+Ch] [ebp-14h] BYREF

  for ( i = _Count; i >= 2 * _Chunk; _Count = i )
  {
    v7 = &_First[_Chunk + _Chunk];
    memset((char *)v8 + 4, 0, 16);
    HIDWORD(v8[2]) = _Dest._Pbuf;
    _Dest._Pbuf = std::_Merge<unsigned char *,unsigned char *,std::_Temp_iterator<unsigned char>>(
                    &result,
                    _First1: _First,
                    _Last1: &_First[_Chunk],
                    _First2: &_First[_Chunk],
                    _Last2: v7,
                    _Dest: *(std::_Temp_iterator<unsigned char> *)((char *)v8 + 4))->_Pbuf;
    if ( result._Buf._Begin != nullptr )
      free(pMem: result._Buf._Begin);
    i = _Count - 2 * _Chunk;
    _First = v7;
  }
  if ( i > _Chunk )
  {
    memset((char *)v8 + 4, 0, 16);
    HIDWORD(v8[2]) = _Dest._Pbuf;
    std::_Merge<unsigned char *,unsigned char *,std::_Temp_iterator<unsigned char>>(
      &result,
      _First1: _First,
      _Last1: &_First[_Chunk],
      _First2: &_First[_Chunk],
      _Last2: _Last,
      _Dest: *(std::_Temp_iterator<unsigned char> *)((char *)v8 + 4));
  }
  else
  {
    LODWORD(v8[2]) = _Dest._Pbuf;
    memset(v8, 0, 16);
    std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
      &result,
      _First,
      _Last,
      _Dest: *(std::_Temp_iterator<unsigned char> *)v8);
  }
  if ( result._Buf._Begin != nullptr )
    free(pMem: result._Buf._Begin);
  if ( _Dest._Buf._Begin != nullptr )
    free(pMem: _Dest._Buf._Begin);
}

//------------------------------------------------------------------------------
// Address: 0x10166B10
// Name: unsigned char __near * std::_Buffered_rotate<unsigned char __near *,int,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char __near *,int,int,class std::_Temp_iterator<unsigned char> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl std::_Buffered_rotate<unsigned char *,int,unsigned char>(
        unsigned __int8 *_First,
        unsigned __int8 *_Mid,
        unsigned __int8 *_Last,
        int _Count1,
        int _Count2,
        std::_Temp_iterator<unsigned char> *_Tempbuf)
{
  std::_Temp_iterator<unsigned char>::_Bufpar *v6; // esi
  unsigned __int8 *v7; // ecx
  unsigned __int8 *v8; // esi
  std::_Temp_iterator<unsigned char>::_Bufpar *Pbuf; // eax
  int Size; // eax
  unsigned __int8 *first; // eax
  int second; // ecx
  std::_Temp_iterator<unsigned char>::_Bufpar *v14; // edx
  std::_Temp_iterator<unsigned char>::_Bufpar *v15; // esi
  unsigned __int8 *Begin; // eax
  unsigned int v17; // esi
  _QWORD v18[3]; // [esp-18h] [ebp-40h] BYREF
  std::_Temp_iterator<unsigned char> v19; // [esp+Ch] [ebp-1Ch] BYREF
  std::pair<unsigned char *,int> v20; // [esp+20h] [ebp-8h] BYREF

  if ( _Count1 > _Count2 || _Count1 > std::_Temp_iterator<unsigned char>::_Maxlen(this: _Tempbuf) )
  {
    Pbuf = _Tempbuf->_Pbuf;
    if ( Pbuf->_Begin == nullptr )
    {
      Size = Pbuf->_Size;
      if ( Size > 0 )
      {
        std::get_temporary_buffer<unsigned char>(result: &v20, _Count: Size);
        first = v20.first;
        _Tempbuf->_Pbuf->_Begin = v20.first;
        _Tempbuf->_Pbuf->_Current = first;
        second = v20.second;
        _Tempbuf->_Pbuf->_Hiwater = first;
        _Tempbuf->_Pbuf->_Size = second;
      }
    }
    v14 = _Tempbuf->_Pbuf;
    if ( _Count2 > v14->_Size )
    {
      if ( _First != _Mid && _Mid != _Last )
        std::_Rotate<unsigned char *,int,unsigned char>(_First, _Mid, _Last);
      return &_First[_Count2];
    }
    else
    {
      _Tempbuf->_Pbuf->_Current = v14->_Begin;
      LODWORD(v18[2]) = _Tempbuf->_Pbuf;
      memset(v18, 0, 16);
      std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
        result: &v19,
        _First: _Mid,
        _Last,
        _Dest: *(std::_Temp_iterator<unsigned char> *)v18);
      if ( v19._Buf._Begin != nullptr )
        free(pMem: v19._Buf._Begin);
      memmove(dst: &_Last[-(_Mid - _First)], src: _First, count: _Mid - _First);
      v15 = _Tempbuf->_Pbuf;
      Begin = v15->_Begin;
      v17 = v15->_Current - v15->_Begin;
      memmove(dst: _First, src: Begin, count: v17);
      return &_First[v17];
    }
  }
  else
  {
    _Tempbuf->_Pbuf->_Current = _Tempbuf->_Pbuf->_Begin;
    memset((char *)v18 + 4, 0, 16);
    HIDWORD(v18[2]) = _Tempbuf->_Pbuf;
    std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
      result: &v19,
      _First,
      _Last: _Mid,
      _Dest: *(std::_Temp_iterator<unsigned char> *)((char *)v18 + 4));
    if ( v19._Buf._Begin != nullptr )
      free(pMem: v19._Buf._Begin);
    memmove(dst: _First, src: _Mid, count: _Last - _Mid);
    v6 = _Tempbuf->_Pbuf;
    v7 = v6->_Begin;
    LODWORD(v18[1]) = v6->_Current - v6->_Begin;
    v8 = &_Last[-LODWORD(v18[1])];
    memmove(dst: &_Last[-LODWORD(v18[1])], src: v7, count: v18[1]);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166C90
// Name: public: CSendNode::~CSendNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSendNode::~CSendNode(CSendNode *this)
{
  int i; // edi
  CSendNode *v3; // ebx
  CSendNode **m_pMemory; // eax
  CSendNode **v5; // eax

  for ( i = this->m_Children.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_Children.m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CSendNode::~CSendNode(this: this->m_Children.m_Memory.m_pMemory[i]);
      free(pMem: v3);
    }
  }
  this->m_Children.m_Size = 0;
  if ( this->m_Children.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Children.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Children.m_Memory.m_pMemory);
      this->m_Children.m_Memory.m_pMemory = nullptr;
    }
    this->m_Children.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Children.m_Memory.m_pMemory;
  this->m_Children.m_pElements = this->m_Children.m_Memory.m_pMemory;
  this->m_Children.m_Size = 0;
  if ( this->m_Children.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_Children.m_Memory.m_pMemory = nullptr;
    }
    this->m_Children.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_Children.m_Memory.m_pMemory;
  this->m_Children.m_pElements = this->m_Children.m_Memory.m_pMemory;
  if ( this->m_Children.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      free(pMem: v5);
      this->m_Children.m_Memory.m_pMemory = nullptr;
    }
    this->m_Children.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166D30
// Name: public: CFastLocalTransferInfo::~CFastLocalTransferInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFastLocalTransferInfo::~CFastLocalTransferInfo(CFastLocalTransferInfo *this)
{
  CFastLocalTransferPropInfo *m_pMemory; // eax
  CFastLocalTransferPropInfo *v3; // eax
  CFastLocalTransferPropInfo *v4; // eax
  CFastLocalTransferPropInfo *v5; // eax
  CFastLocalTransferPropInfo *v6; // eax

  this->m_OtherProps.m_Size = 0;
  if ( this->m_OtherProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OtherProps.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_OtherProps.m_Memory.m_pMemory);
      this->m_OtherProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_OtherProps.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_OtherProps.m_Memory.m_pMemory;
  this->m_OtherProps.m_pElements = m_pMemory;
  if ( this->m_OtherProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_OtherProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_OtherProps.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FastVector.m_Size = 0;
  if ( this->m_FastVector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FastVector.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_FastVector.m_Memory.m_pMemory);
      this->m_FastVector.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastVector.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_FastVector.m_Memory.m_pMemory;
  this->m_FastVector.m_pElements = v3;
  if ( this->m_FastVector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3 != nullptr )
    {
      free(pMem: v3);
      this->m_FastVector.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastVector.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FastInt8.m_Size = 0;
  if ( this->m_FastInt8.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FastInt8.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_FastInt8.m_Memory.m_pMemory);
      this->m_FastInt8.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt8.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_FastInt8.m_Memory.m_pMemory;
  this->m_FastInt8.m_pElements = v4;
  if ( this->m_FastInt8.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      free(pMem: v4);
      this->m_FastInt8.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt8.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FastInt16.m_Size = 0;
  if ( this->m_FastInt16.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FastInt16.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_FastInt16.m_Memory.m_pMemory);
      this->m_FastInt16.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt16.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_FastInt16.m_Memory.m_pMemory;
  this->m_FastInt16.m_pElements = v5;
  if ( this->m_FastInt16.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      free(pMem: v5);
      this->m_FastInt16.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt16.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FastInt32.m_Size = 0;
  if ( this->m_FastInt32.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FastInt32.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_FastInt32.m_Memory.m_pMemory);
      this->m_FastInt32.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt32.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_FastInt32.m_Memory.m_pMemory;
  this->m_FastInt32.m_pElements = this->m_FastInt32.m_Memory.m_pMemory;
  if ( this->m_FastInt32.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      free(pMem: v6);
      this->m_FastInt32.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt32.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166E70
// Name: void SendTable_BuildHierarchy_IterateProps(class CSendNode __near *,class SendTable const __near *,class CBuildHierarchyStruct __near *,class SendProp const __near * __near * const,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_BuildHierarchy_IterateProps(
        CSendNode *pNode,
        const SendTable *pTable,
        CBuildHierarchyStruct *bhs,
        const SendProp **pNonDatatableProps,
        int *nNonDatatableProps)
{
  const SendTable *v5; // edi
  SendProp *v6; // ebx
  CSendNode *v7; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CSendNode **m_pMemory; // ecx
  int v11; // eax
  CSendNode **v12; // edi
  int i; // [esp+4h] [ebp-Ch]
  int v14; // [esp+8h] [ebp-8h]
  CSendNode *pChild; // [esp+Ch] [ebp-4h]

  v5 = pTable;
  i = 0;
  if ( pTable->m_nProps > 0 )
  {
    v14 = 0;
    do
    {
      v6 = &v5->m_pProps[v14];
      if ( (v6->m_Flags & 0x40) == 0
        && (v6->m_Flags & 0x100) == 0
        && FindExcludeProp(
             pTableName: v5->m_pNetTableName,
             pPropName: v6->m_pVarName,
             pExcludeProps: bhs->m_pExcludeProps,
             nExcludeProps: bhs->m_nExcludeProps) == nullptr )
      {
        if ( v6->m_Type == DPT_DataTable )
        {
          if ( (v6->m_Flags & 0x800) != 0 )
          {
            SendTable_BuildHierarchy_IterateProps(
              pNode,
              pTable: v6->m_pDataTable,
              bhs,
              pNonDatatableProps,
              nNonDatatableProps);
          }
          else
          {
            v7 = (CSendNode *)MemAlloc_Alloc(nSize: 0x24u);
            if ( v7 != nullptr )
            {
              v7->m_Children.m_Memory.m_pMemory = nullptr;
              v7->m_Children.m_Memory.m_nAllocationCount = 0;
              v7->m_Children.m_Memory.m_nGrowSize = 0;
              v7->m_Children.m_Size = 0;
              v7->m_Children.m_pElements = nullptr;
              v7->m_pTable = nullptr;
              *(_DWORD *)&v7->m_iFirstRecursiveProp = 0;
              v7->m_iDatatableProp = -1;
              v7->m_DataTableProxyIndex = 254;
              pChild = v7;
            }
            else
            {
              pChild = nullptr;
            }
            if ( bhs->m_nDatatableProps >= 0xFFFu )
              _Error(a1: "Overflowed datatable prop list in SendTable '%s'.", pTable->m_pNetTableName);
            bhs->m_pDatatableProps[bhs->m_nDatatableProps] = v6;
            pChild->m_iDatatableProp = bhs->m_nDatatableProps;
            ++bhs->m_nDatatableProps;
            m_Size = pNode->m_Children.m_Size;
            m_nAllocationCount = pNode->m_Children.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CSendTablePrecalc::CProxyPathEntry,int>::Grow(
                this: (CUtlMemory<SendProp const *,int> *)pNode,
                num: m_Size - m_nAllocationCount + 1);
            ++pNode->m_Children.m_Size;
            m_pMemory = pNode->m_Children.m_Memory.m_pMemory;
            v11 = pNode->m_Children.m_Size - m_Size - 1;
            pNode->m_Children.m_pElements = pNode->m_Children.m_Memory.m_pMemory;
            if ( v11 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
            v12 = &pNode->m_Children.m_Memory.m_pMemory[m_Size];
            if ( v12 != nullptr )
              *v12 = pChild;
            SendTable_BuildHierarchy(pNode: pChild, pTable: v6->m_pDataTable, bhs);
          }
        }
        else
        {
          if ( *nNonDatatableProps >= 4095 )
            _Error(a1: "SendTable_BuildHierarchy: overflowed non-datatable props with '%s'.", v6->m_pVarName);
          pNonDatatableProps[(*nNonDatatableProps)++] = v6;
        }
      }
      v5 = pTable;
      ++v14;
      ++i;
    }
    while ( i < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167030
// Name: void SendTable_BuildHierarchy(class CSendNode __near *,class SendTable const __near *,class CBuildHierarchyStruct __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_BuildHierarchy(CSendNode *pNode, const SendTable *pTable, CBuildHierarchyStruct *bhs)
{
  CBuildHierarchyStruct *v3; // esi
  CSendNode *v4; // edi
  unsigned __int8 m_nPropProxies; // bl
  int i; // eax
  SendProp *pNonDatatableProps[4095]; // [esp+Ch] [ebp-3FFCh] BYREF

  v3 = bhs;
  v4 = pNode;
  pNode->m_pTable = pTable;
  v4->m_iFirstRecursiveProp = v3->m_nProps;
  if ( v3->m_nPropProxies == 0xFF )
    _Error(a1: "Exceeded max number of datatable proxies in SendTable_BuildHierarchy()");
  m_nPropProxies = v3->m_nPropProxies;
  pNode = nullptr;
  v3->m_nPropProxies = m_nPropProxies + 1;
  SendTable_BuildHierarchy_IterateProps(
    pNode: v4,
    pTable,
    bhs: v3,
    (const SendProp **)pNonDatatableProps,
    nNonDatatableProps: (int *)&pNode);
  if ( (unsigned int)pNode + v3->m_nProps >= 0xFFF )
    _Error(a1: "SendTable_BuildHierarchy: overflowed prop buffer.");
  for ( i = 0; i < (int)pNode; ++i )
  {
    v3->m_pProps[v3->m_nProps] = pNonDatatableProps[i];
    v3->m_PropProxyIndices[v3->m_nProps++] = m_nPropProxies;
  }
  v4->m_nRecursiveProps = LOWORD(v3->m_nProps) - v4->m_iFirstRecursiveProp;
}

//------------------------------------------------------------------------------
// Address: 0x10167180
// Name: void std::_Buffered_merge_sort<unsigned char __near *,int,unsigned char>(unsigned char __near *,unsigned char __near *,int,class std::_Temp_iterator<unsigned char> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Buffered_merge_sort<unsigned char *,int,unsigned char>(
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        int _Count,
        std::_Temp_iterator<unsigned char> *_Tempbuf)
{
  unsigned __int8 *v4; // eax
  unsigned int v5; // ebx
  unsigned __int8 *v6; // esi
  int i; // esi
  int v8; // esi
  std::_Temp_iterator<unsigned char> v9[2]; // [esp-1Ch] [ebp-28h] BYREF

  v4 = _First;
  if ( _Count >= 32 )
  {
    v5 = (unsigned int)_Count >> 5;
    do
    {
      v6 = v4 + 32;
      std::_Insertion_sort1<unsigned char *,unsigned char>(_First: v4, _Last: v4 + 32);
      --v5;
      v4 = v6;
    }
    while ( v5 != 0 );
  }
  std::_Insertion_sort1<unsigned char *,unsigned char>(_First: v4, _Last);
  for ( i = 32; i < _Count; i = 2 * v8 )
  {
    _Tempbuf->_Pbuf->_Current = _Tempbuf->_Pbuf->_Begin;
    memset(v9, 0, 16);
    v9[0]._Pbuf = _Tempbuf->_Pbuf;
    std::_Chunked_merge<unsigned char *,std::_Temp_iterator<unsigned char>,int>(
      _First,
      _Last,
      _Dest: v9[0],
      _Chunk: i,
      _Count);
    v8 = 2 * i;
    std::_Chunked_merge<unsigned char *,unsigned char *,int>(
      _First: _Tempbuf->_Pbuf->_Begin,
      _Last: _Tempbuf->_Pbuf->_Current,
      _Dest: _First,
      _Chunk: v8,
      _Count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167220
// Name: void std::_Buffered_merge<unsigned char __near *,int,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char __near *,int,int,class std::_Temp_iterator<unsigned char> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Buffered_merge<unsigned char *,int,unsigned char>(
        unsigned __int8 *_First,
        unsigned __int8 *_Mid,
        unsigned __int8 *_Last,
        int _Count1,
        int _Count2,
        std::_Temp_iterator<unsigned char> *_Tempbuf)
{
  int v7; // edi
  int v8; // edi
  unsigned __int8 *v9; // eax
  int v10; // esi
  unsigned __int8 *v11; // eax
  int v12; // ecx
  unsigned __int8 v13; // al
  std::_Temp_iterator<unsigned char> v14; // [esp-14h] [ebp-40h] BYREF
  std::_Temp_iterator<unsigned char> result; // [esp+Ch] [ebp-20h] BYREF
  unsigned __int8 *_Midn; // [esp+20h] [ebp-Ch]
  unsigned __int8 *_Lastn; // [esp+24h] [ebp-8h]
  unsigned __int8 *_Firstn; // [esp+28h] [ebp-4h]

  v7 = _Count2;
  if ( _Count2 + _Count1 == 2 )
  {
LABEL_11:
    v13 = *_First;
    if ( *_Mid < *_First )
    {
      *_First = *_Mid;
      *_Mid = v13;
    }
  }
  else
  {
    while ( _Count1 > v7 || _Count1 > std::_Temp_iterator<unsigned char>::_Maxlen(this: _Tempbuf) )
    {
      if ( v7 <= std::_Temp_iterator<unsigned char>::_Maxlen(this: _Tempbuf) )
      {
        _Tempbuf->_Pbuf->_Current = _Tempbuf->_Pbuf->_Begin;
        memset(&v14, 0, 16);
        v14._Pbuf = _Tempbuf->_Pbuf;
        std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(&result, _First: _Mid, _Last, _Dest: v14);
        if ( result._Buf._Begin != nullptr )
          free(pMem: result._Buf._Begin);
        std::_Merge_backward<unsigned char *,unsigned char *,unsigned char *>(
          _First1: _First,
          _Last1: _Mid,
          _First2: _Tempbuf->_Pbuf->_Begin,
          _Last2: _Tempbuf->_Pbuf->_Current,
          _Dest: _Last);
        return;
      }
      if ( v7 >= _Count1 )
      {
        v10 = v7 / 2;
        _Lastn = &_Mid[v7 / 2];
        v11 = std::upper_bound<unsigned char *,unsigned char>(_First, _Last: _Mid, _Val: _Lastn);
        v8 = v11 - _First;
        _Firstn = v11;
        v9 = _Lastn;
      }
      else
      {
        v8 = _Count1 / 2;
        _Firstn = &_First[_Count1 / 2];
        v9 = std::lower_bound<unsigned char *,unsigned char>(_First: _Mid, _Last, _Val: _Firstn);
        _Lastn = v9;
        v10 = v9 - _Mid;
      }
      _Count1 -= v8;
      _Midn = std::_Buffered_rotate<unsigned char *,int,unsigned char>(
                _First: _Firstn,
                _Mid,
                _Last: v9,
                _Count1,
                _Count2: v10,
                _Tempbuf);
      std::_Buffered_merge<unsigned char *,int,unsigned char>(
        _First,
        _Mid: _Firstn,
        _Last: _Midn,
        _Count1: v8,
        _Count2: v10,
        _Tempbuf);
      _Mid = _Lastn;
      v12 = _Count2 - v10 + _Count1;
      _Count2 -= v10;
      _First = _Midn;
      if ( v12 == 2 )
        goto LABEL_11;
      v7 = _Count2;
    }
    _Tempbuf->_Pbuf->_Current = _Tempbuf->_Pbuf->_Begin;
    memset(&v14, 0, 16);
    v14._Pbuf = _Tempbuf->_Pbuf;
    std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(&result, _First, _Last: _Mid, _Dest: v14);
    if ( result._Buf._Begin != nullptr )
      free(pMem: result._Buf._Begin);
    std::_Merge<unsigned char *,unsigned char *,unsigned char *>(
      _First1: _Tempbuf->_Pbuf->_Begin,
      _Last1: _Tempbuf->_Pbuf->_Current,
      _First2: _Mid,
      _Last2: _Last,
      _Dest: _First);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167400
// Name: void std::_Stable_sort<unsigned char __near *,int,unsigned char>(unsigned char __near *,unsigned char __near *,int,class std::_Temp_iterator<unsigned char> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Stable_sort<unsigned char *,int,unsigned char>(
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        int _Count,
        std::_Temp_iterator<unsigned char> *_Tempbuf)
{
  int v4; // esi
  unsigned __int8 *v5; // ebx
  int v6; // edi

  if ( _Count > 32 )
  {
    v4 = (_Count + 1) / 2;
    v5 = &_First[v4];
    if ( v4 > std::_Temp_iterator<unsigned char>::_Maxlen(this: _Tempbuf) )
    {
      std::_Stable_sort<unsigned char *,int,unsigned char>(_First, _Last: v5, _Count: (_Count + 1) / 2, _Tempbuf);
      v6 = _Count - v4;
      std::_Stable_sort<unsigned char *,int,unsigned char>(_First: v5, _Last, _Count: _Count - v4, _Tempbuf);
    }
    else
    {
      std::_Buffered_merge_sort<unsigned char *,int,unsigned char>(
        _First,
        _Last: v5,
        _Count: (_Count + 1) / 2,
        _Tempbuf);
      v6 = _Count - v4;
      std::_Buffered_merge_sort<unsigned char *,int,unsigned char>(_First: v5, _Last, _Count: _Count - v4, _Tempbuf);
    }
    std::_Buffered_merge<unsigned char *,int,unsigned char>(_First, _Mid: v5, _Last, _Count1: v4, _Count2: v6, _Tempbuf);
  }
  else
  {
    std::_Insertion_sort1<unsigned char *,unsigned char>(_First, _Last);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101674A0
// Name: public: virtual CSendTablePrecalc::~CSendTablePrecalc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSendTablePrecalc::~CSendTablePrecalc(CSendTablePrecalc *this)
{
  SendTable *m_pSendTable; // eax
  const SendProp **m_pMemory; // eax
  unsigned __int8 *v4; // eax
  const SendProp **v5; // eax
  CSendTablePrecalc::CProxyPath *v6; // eax
  CSendTablePrecalc::CProxyPathEntry *v7; // eax

  m_pSendTable = this->m_pSendTable;
  this->__vftable = (CSendTablePrecalc_vtbl *)&CSendTablePrecalc::`vftable';
  if ( m_pSendTable != nullptr )
    m_pSendTable->m_pPrecalc = nullptr;
  CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_PropOffsetToIndexMap.m_Tree);
  this->m_PropOffsetToIndexMap.m_Tree.m_FirstFree = -1;
  if ( this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      free(pMem: this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory);
      this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_PropOffsetToIndexMap.m_Tree.m_LastAlloc.index = -1;
  if ( this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      free(pMem: this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory);
      this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  CFastLocalTransferInfo::~CFastLocalTransferInfo(this: &this->m_FastLocalTransfer);
  CSendNode::~CSendNode(this: &this->m_Root);
  this->m_DatatableProps.m_Size = 0;
  if ( this->m_DatatableProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DatatableProps.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_DatatableProps.m_Memory.m_pMemory);
      this->m_DatatableProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_DatatableProps.m_Memory.m_pMemory;
  this->m_DatatableProps.m_pElements = m_pMemory;
  if ( this->m_DatatableProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_DatatableProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PropProxyIndices.m_Size = 0;
  if ( this->m_PropProxyIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PropProxyIndices.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_PropProxyIndices.m_Memory.m_pMemory);
      this->m_PropProxyIndices.m_Memory.m_pMemory = nullptr;
    }
    this->m_PropProxyIndices.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_PropProxyIndices.m_Memory.m_pMemory;
  this->m_PropProxyIndices.m_pElements = v4;
  if ( this->m_PropProxyIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      free(pMem: v4);
      this->m_PropProxyIndices.m_Memory.m_pMemory = nullptr;
    }
    this->m_PropProxyIndices.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Props.m_Size = 0;
  if ( this->m_Props.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Props.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Props.m_Memory.m_pMemory);
      this->m_Props.m_Memory.m_pMemory = nullptr;
    }
    this->m_Props.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_Props.m_Memory.m_pMemory;
  this->m_Props.m_pElements = v5;
  if ( this->m_Props.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      free(pMem: v5);
      this->m_Props.m_Memory.m_pMemory = nullptr;
    }
    this->m_Props.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ProxyPaths.m_Size = 0;
  if ( this->m_ProxyPaths.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ProxyPaths.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_ProxyPaths.m_Memory.m_pMemory);
      this->m_ProxyPaths.m_Memory.m_pMemory = nullptr;
    }
    this->m_ProxyPaths.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_ProxyPaths.m_Memory.m_pMemory;
  this->m_ProxyPaths.m_pElements = v6;
  if ( this->m_ProxyPaths.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      free(pMem: v6);
      this->m_ProxyPaths.m_Memory.m_pMemory = nullptr;
    }
    this->m_ProxyPaths.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ProxyPathEntries.m_Size = 0;
  if ( this->m_ProxyPathEntries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ProxyPathEntries.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_ProxyPathEntries.m_Memory.m_pMemory);
      this->m_ProxyPathEntries.m_Memory.m_pMemory = nullptr;
    }
    this->m_ProxyPathEntries.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_ProxyPathEntries.m_Memory.m_pMemory;
  this->m_ProxyPathEntries.m_pElements = v7;
  if ( this->m_ProxyPathEntries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      free(pMem: v7);
      this->m_ProxyPathEntries.m_Memory.m_pMemory = nullptr;
    }
    this->m_ProxyPathEntries.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167670
// Name: void SendTable_GenerateProxyPaths(class CSendTablePrecalc __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_GenerateProxyPaths(CSendTablePrecalc *pPrecalc, int nProxyIndices)
{
  int v2; // esi
  int i; // eax
  int *m_pMemory; // ecx
  int m_Size; // eax
  CSendNode *p_m_Root; // esi
  int j; // edi
  int v8; // eax
  int v9; // ebx
  int m_nAllocationCount; // ecx
  CSendTablePrecalc::CProxyPathEntry *v11; // ecx
  int v12; // eax
  CSendTablePrecalc::CProxyPath *v13; // eax
  int k; // edi
  int *v15; // eax
  int v16; // [esp-4h] [ebp-28h]
  CUtlVector<int,CUtlMemory<int,int> > pathLengths; // [esp+Ch] [ebp-18h] BYREF
  int iCurEntry; // [esp+20h] [ebp-4h] BYREF

  v2 = nProxyIndices;
  v16 = nProxyIndices;
  pPrecalc->m_ProxyPaths.m_Size = 0;
  CUtlVector<SendProp const *,CUtlMemory<SendProp const *,int>>::InsertMultipleBefore(
    this: (CUtlVector<SendProp const *,CUtlMemory<SendProp const *,int> > *)&pPrecalc->m_ProxyPaths,
    elem: 0,
    num: v16);
  for ( i = 0; i < v2; ++i )
  {
    pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[i].m_nEntries = -1;
    pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[i].m_iFirstEntry = -1;
  }
  m_pMemory = nullptr;
  m_Size = 0;
  nProxyIndices = 0;
  memset(&pathLengths, 0, sizeof(pathLengths));
  if ( v2 != 0 )
  {
    if ( v2 > 0 )
    {
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&pathLengths, num: v2);
      m_Size = pathLengths.m_Size;
      m_pMemory = pathLengths.m_Memory.m_pMemory;
    }
    pathLengths.m_Size = v2 + m_Size;
    pathLengths.m_pElements = m_pMemory;
    if ( m_Size > 0 && v2 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v2], src: m_pMemory, count: 4 * m_Size);
      m_pMemory = pathLengths.m_Memory.m_pMemory;
    }
  }
  memset(dst: (unsigned __int8 *)m_pMemory, value: 0, count: 4 * v2);
  p_m_Root = &pPrecalc->m_Root;
  pathLengths.m_Memory.m_pMemory[pPrecalc->m_Root.m_RecursiveProxyIndex] = 0;
  for ( j = 0; j < pPrecalc->m_Root.m_Children.m_Size; ++j )
    CalcPathLengths_R(
      pNode: p_m_Root->m_Children.m_Memory.m_pMemory[j],
      &pathLengths,
      curPathLength: 1,
      totalPathLengths: &nProxyIndices);
  v8 = nProxyIndices;
  iCurEntry = 0;
  v9 = nProxyIndices;
  pPrecalc->m_ProxyPathEntries.m_Size = 0;
  if ( v9 != 0 )
  {
    m_nAllocationCount = pPrecalc->m_ProxyPathEntries.m_Memory.m_nAllocationCount;
    if ( v8 > m_nAllocationCount )
      CUtlMemory<CSendTablePrecalc::CProxyPathEntry,int>::Grow(
        this: (CUtlMemory<SendProp const *,int> *)&pPrecalc->m_ProxyPathEntries,
        num: v8 - m_nAllocationCount);
    pPrecalc->m_ProxyPathEntries.m_Size += v9;
    v11 = pPrecalc->m_ProxyPathEntries.m_Memory.m_pMemory;
    v12 = pPrecalc->m_ProxyPathEntries.m_Size - v9;
    pPrecalc->m_ProxyPathEntries.m_pElements = v11;
    if ( v12 > 0 && v9 > 0 )
      _V_memmove(dest: &v11[v9], src: v11, count: 4 * v12);
  }
  v13 = &pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[pPrecalc->m_Root.m_RecursiveProxyIndex];
  v13->m_iFirstEntry = iCurEntry;
  v13->m_nEntries = 0;
  for ( k = 0; k < pPrecalc->m_Root.m_Children.m_Size; ++k )
    FillPathEntries_R(pPrecalc, pNode: p_m_Root->m_Children.m_Memory.m_pMemory[k], pParent: p_m_Root, &iCurEntry);
  v15 = pathLengths.m_Memory.m_pMemory;
  pathLengths.m_Size = 0;
  if ( pathLengths.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pathLengths.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: pathLengths.m_Memory.m_pMemory);
      v15 = nullptr;
      pathLengths.m_Memory.m_pMemory = nullptr;
    }
    pathLengths.m_Memory.m_nAllocationCount = 0;
  }
  pathLengths.m_pElements = v15;
  if ( pathLengths.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
    free(pMem: v15);
}

//------------------------------------------------------------------------------
// Address: 0x10167830
// Name: public: CSendTablePrecalc::CSendTablePrecalc(void)
// Source: json
//------------------------------------------------------------------------------
CSendTablePrecalc *__thiscall CSendTablePrecalc::CSendTablePrecalc(CSendTablePrecalc *this)
{
  this->__vftable = (CSendTablePrecalc_vtbl *)&CSendTablePrecalc::`vftable';
  this->m_ProxyPathEntries.m_Memory.m_pMemory = nullptr;
  this->m_ProxyPathEntries.m_Memory.m_nAllocationCount = 0;
  this->m_ProxyPathEntries.m_Memory.m_nGrowSize = 0;
  this->m_ProxyPathEntries.m_Size = 0;
  this->m_ProxyPathEntries.m_pElements = nullptr;
  this->m_ProxyPaths.m_Memory.m_pMemory = nullptr;
  this->m_ProxyPaths.m_Memory.m_nAllocationCount = 0;
  this->m_ProxyPaths.m_Memory.m_nGrowSize = 0;
  this->m_ProxyPaths.m_Size = 0;
  this->m_ProxyPaths.m_pElements = nullptr;
  this->m_Props.m_Memory.m_pMemory = nullptr;
  this->m_Props.m_Memory.m_nAllocationCount = 0;
  this->m_Props.m_Memory.m_nGrowSize = 0;
  this->m_Props.m_Size = 0;
  this->m_Props.m_pElements = nullptr;
  this->m_PropProxyIndices.m_Memory.m_pMemory = nullptr;
  this->m_PropProxyIndices.m_Memory.m_nAllocationCount = 0;
  this->m_PropProxyIndices.m_Memory.m_nGrowSize = 0;
  this->m_PropProxyIndices.m_Size = 0;
  this->m_PropProxyIndices.m_pElements = nullptr;
  this->m_DatatableProps.m_Memory.m_pMemory = nullptr;
  this->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
  this->m_DatatableProps.m_Memory.m_nGrowSize = 0;
  this->m_DatatableProps.m_Size = 0;
  this->m_DatatableProps.m_pElements = nullptr;
  this->m_Root.m_Children.m_Memory.m_pMemory = nullptr;
  this->m_Root.m_Children.m_Memory.m_nAllocationCount = 0;
  this->m_Root.m_Children.m_Memory.m_nGrowSize = 0;
  this->m_Root.m_Children.m_Size = 0;
  this->m_Root.m_Children.m_pElements = nullptr;
  this->m_Root.m_pTable = nullptr;
  this->m_Root.m_iDatatableProp = -1;
  this->m_Root.m_nRecursiveProps = 0;
  this->m_Root.m_iFirstRecursiveProp = 0;
  this->m_Root.m_DataTableProxyIndex = 254;
  this->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory = nullptr;
  this->m_FastLocalTransfer.m_FastInt32.m_Memory.m_nAllocationCount = 0;
  this->m_FastLocalTransfer.m_FastInt32.m_Memory.m_nGrowSize = 0;
  this->m_FastLocalTransfer.m_FastInt32.m_Size = 0;
  this->m_FastLocalTransfer.m_FastInt32.m_pElements = nullptr;
  this->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory = nullptr;
  this->m_FastLocalTransfer.m_FastInt16.m_Memory.m_nAllocationCount = 0;
  this->m_FastLocalTransfer.m_FastInt16.m_Memory.m_nGrowSize = 0;
  this->m_FastLocalTransfer.m_FastInt16.m_Size = 0;
  this->m_FastLocalTransfer.m_FastInt16.m_pElements = nullptr;
  this->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory = nullptr;
  this->m_FastLocalTransfer.m_FastInt8.m_Memory.m_nAllocationCount = 0;
  this->m_FastLocalTransfer.m_FastInt8.m_Memory.m_nGrowSize = 0;
  this->m_FastLocalTransfer.m_FastInt8.m_Size = 0;
  this->m_FastLocalTransfer.m_FastInt8.m_pElements = nullptr;
  this->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory = nullptr;
  this->m_FastLocalTransfer.m_FastVector.m_Memory.m_nAllocationCount = 0;
  this->m_FastLocalTransfer.m_FastVector.m_Memory.m_nGrowSize = 0;
  this->m_FastLocalTransfer.m_FastVector.m_Size = 0;
  this->m_FastLocalTransfer.m_FastVector.m_pElements = nullptr;
  this->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory = nullptr;
  this->m_FastLocalTransfer.m_OtherProps.m_Memory.m_nAllocationCount = 0;
  this->m_FastLocalTransfer.m_OtherProps.m_Memory.m_nGrowSize = 0;
  this->m_FastLocalTransfer.m_OtherProps.m_Size = 0;
  this->m_FastLocalTransfer.m_OtherProps.m_pElements = nullptr;
  this->m_PropOffsetToIndexMap.m_Tree.m_LessFunc.m_LessFunc = CDefOps<unsigned short>::LessFunc;
  this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PropOffsetToIndexMap.m_Tree.m_Root = -1;
  this->m_PropOffsetToIndexMap.m_Tree.m_NumElements = 0;
  this->m_PropOffsetToIndexMap.m_Tree.m_FirstFree = -1;
  this->m_PropOffsetToIndexMap.m_Tree.m_LastAlloc.index = -1;
  this->m_PropOffsetToIndexMap.m_Tree.m_pElements = this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory;
  this->m_pDTITable = nullptr;
  this->m_pSendTable = nullptr;
  this->m_nDataTableProxies = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101679F0
// Name: void SendTable_SortByPriority(class CBuildHierarchyStruct __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_SortByPriority(CBuildHierarchyStruct *bhs)
{
  unsigned __int8 *m_pMemory; // edi
  int m_Size; // ebx
  int v3; // eax
  unsigned __int8 v5; // dl
  int v6; // eax
  const SendProp **v7; // ecx
  unsigned __int8 *v8; // ecx
  int v9; // edi
  int v10; // eax
  int v11; // eax
  const SendProp **v12; // edi
  const SendProp *v13; // ecx
  unsigned __int8 v14; // dl
  int v15; // edi
  unsigned __int8 v16; // bl
  const SendProp **v17; // edi
  std::_Temp_iterator<unsigned char> _Tempbuf; // [esp+Ch] [ebp-34h] BYREF
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > priorities; // [esp+20h] [ebp-20h] BYREF
  int priorityIndex; // [esp+34h] [ebp-Ch]
  int start; // [esp+38h] [ebp-8h]
  const SendProp **v22; // [esp+3Ch] [ebp-4h]
  unsigned __int8 priority_3; // [esp+4Bh] [ebp+Bh]
  unsigned __int8 priority_3a; // [esp+4Bh] [ebp+Bh]

  memset(&priorities, 0, sizeof(priorities));
  CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)&priorities, num: 1);
  m_pMemory = priorities.m_Memory.m_pMemory;
  m_Size = priorities.m_Size + 1;
  v3 = priorities.m_Size++;
  priorities.m_pElements = priorities.m_Memory.m_pMemory;
  if ( v3 > 0 )
    _V_memmove(dest: priorities.m_Memory.m_pMemory + 1, src: priorities.m_Memory.m_pMemory, count: v3);
  if ( m_pMemory != nullptr )
    *m_pMemory = 64;
  priorityIndex = 0;
  if ( bhs->m_nProps > 0 )
  {
    start = (int)bhs->m_pProps;
    do
    {
      v5 = *(_BYTE *)(*(_DWORD *)start + 56);
      v6 = 0;
      priority_3 = v5;
      if ( m_Size <= 0 )
        goto LABEL_12;
      while ( m_pMemory[v6] != v5 )
      {
        if ( ++v6 >= m_Size )
          goto LABEL_12;
      }
      if ( v6 < 0 )
      {
LABEL_12:
        v7 = (const SendProp **)m_Size;
        v22 = (const SendProp **)m_Size;
        if ( m_Size + 1 > priorities.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<bool,int>::Grow(
            this: (CUtlMemory<char,int> *)&priorities,
            num: m_Size - priorities.m_Memory.m_nAllocationCount + 1);
          m_Size = priorities.m_Size;
          m_pMemory = priorities.m_Memory.m_pMemory;
          v5 = priority_3;
          v7 = v22;
        }
        priorities.m_Size = ++m_Size;
        priorities.m_pElements = m_pMemory;
        if ( m_Size - (int)v7 - 1 > 0 )
        {
          _V_memmove(
            dest: (char *)v7 + (_DWORD)m_pMemory + 1,
            src: (char *)v7 + (_DWORD)m_pMemory,
            count: m_Size - (_DWORD)v7 - 1);
          v5 = priority_3;
          v7 = v22;
        }
        v8 = (unsigned __int8 *)v7 + (_DWORD)m_pMemory;
        if ( v8 != nullptr )
          *v8 = v5;
      }
      start += 4;
      ++priorityIndex;
    }
    while ( priorityIndex < bhs->m_nProps );
  }
  if ( m_pMemory != &m_pMemory[m_Size] )
  {
    memset(&_Tempbuf, 0, 12);
    _Tempbuf._Buf._Size = (m_Size + 1) / 2;
    _Tempbuf._Pbuf = (std::_Temp_iterator<unsigned char>::_Bufpar *)&_Tempbuf;
    std::_Stable_sort<unsigned char *,int,unsigned char>(
      _First: m_pMemory,
      _Last: &m_pMemory[m_Size],
      _Count: m_Size,
      &_Tempbuf);
    if ( _Tempbuf._Buf._Begin != nullptr )
      free(pMem: _Tempbuf._Buf._Begin);
  }
  v9 = 0;
  v10 = 0;
  start = 0;
  for ( priorityIndex = 0; v10 < m_Size; priorityIndex = v10 )
  {
    priority_3a = priorities.m_Memory.m_pMemory[v10];
    v22 = &bhs->m_pProps[v9];
    do
    {
      v11 = v9;
      if ( v9 < bhs->m_nProps )
      {
        v12 = v22;
        while ( 1 )
        {
          v13 = *v12;
          v14 = bhs->m_PropProxyIndices[v11];
          if ( (*v12)->m_priority == priority_3a || (v13->m_Flags & 0x40000) != 0 && priority_3a == 64 )
            break;
          ++v11;
          ++v12;
          if ( v11 >= bhs->m_nProps )
          {
            v9 = start;
            goto LABEL_34;
          }
        }
        v15 = start;
        if ( v11 != start )
        {
          bhs->m_pProps[v11] = *v22;
          v16 = bhs->m_PropProxyIndices[v15];
          v17 = v22;
          bhs->m_PropProxyIndices[v11] = v16;
          *v17 = v13;
          v15 = start;
          bhs->m_PropProxyIndices[start] = v14;
        }
        v9 = v15 + 1;
        ++v22;
        start = v9;
LABEL_34:
        m_Size = priorities.m_Size;
      }
    }
    while ( v11 != bhs->m_nProps );
    v10 = priorityIndex + 1;
  }
  if ( priorities.m_Memory.m_nGrowSize >= 0 && priorities.m_Memory.m_pMemory != nullptr )
    free(pMem: priorities.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10167C00
// Name: public: bool CSendTablePrecalc::SetupFlatPropertyArray(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSendTablePrecalc::SetupFlatPropertyArray(CSendTablePrecalc *this)
{
  SendTable *v2; // edi
  bool result; // al
  int m_nProps; // ebx
  int i; // eax
  int m_nDatatableProps; // ebx
  int j; // eax
  int v8; // [esp-4h] [ebp-A028h]
  int v9; // [esp-4h] [ebp-A028h]
  CBuildHierarchyStruct bhs; // [esp+Ch] [ebp-A018h] BYREF
  ExcludeProp pExcludeProps; // [esp+9018h] [ebp-100Ch] BYREF
  SendTable *pBaseTable; // [esp+A018h] [ebp-Ch]
  int iCurProxyIndex; // [esp+A01Ch] [ebp-8h] BYREF
  int nExcludeProps; // [esp+A020h] [ebp-4h] BYREF

  pBaseTable = this->m_pSendTable;
  v2 = pBaseTable;
  SetupArrayProps_R<SendTable,SendProp>(pTable: pBaseTable);
  nExcludeProps = 0;
  result = SendTable_GetPropsExcluded(pTable: pBaseTable, &pExcludeProps, &nExcludeProps, nMaxExcludeProps: 512);
  if ( result )
  {
    bhs.m_nExcludeProps = nExcludeProps;
    bhs.m_pExcludeProps = &pExcludeProps;
    bhs.m_nDatatableProps = 0;
    bhs.m_nProps = 0;
    bhs.m_nPropProxies = 0;
    SendTable_BuildHierarchy(pNode: &this->m_Root, pTable: v2, &bhs);
    SendTable_SortByPriority(&bhs);
    m_nProps = bhs.m_nProps;
    v8 = bhs.m_nProps;
    this->m_Props.m_Size = 0;
    CUtlVector<SendProp const *,CUtlMemory<SendProp const *,int>>::InsertMultipleBefore(
      this: &this->m_Props,
      elem: 0,
      num: v8);
    for ( i = 0; i < m_nProps; ++i )
      this->m_Props.m_Memory.m_pMemory[i] = bhs.m_pProps[i];
    m_nDatatableProps = bhs.m_nDatatableProps;
    v9 = bhs.m_nDatatableProps;
    this->m_DatatableProps.m_Size = 0;
    CUtlVector<SendProp const *,CUtlMemory<SendProp const *,int>>::InsertMultipleBefore(
      this: &this->m_DatatableProps,
      elem: 0,
      num: v9);
    for ( j = 0; j < m_nDatatableProps; ++j )
      this->m_DatatableProps.m_Memory.m_pMemory[j] = bhs.m_pDatatableProps[j];
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
      this: &this->m_PropProxyIndices,
      pArray: bhs.m_PropProxyIndices,
      size: bhs.m_nProps);
    this->m_nDataTableProxies = 0;
    SetDataTableProxyIndices_R(pMainTable: this, pCurTable: &this->m_Root, &bhs);
    iCurProxyIndex = 0;
    SetRecursiveProxyIndices_R(pBaseTable, pCurTable: &this->m_Root, &iCurProxyIndex);
    SendTable_GenerateProxyPaths(pPrecalc: this, nProxyIndices: iCurProxyIndex);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10319AF0
// Name: _dynamic_initializer_for__dt_UsePartialChangeEnts__
// Source: semantic_dyn_pfx_dt
//------------------------------------------------------------------------------
int dynamic_initializer_for__dt_UsePartialChangeEnts__()
{
  ConVar::ConVar(
    this: &dt_UsePartialChangeEnts,
    pName: "dt_UsePartialChangeEnts",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "(SP only) - enable FL_EDICT_PARTIAL_CHANGE optimization.");
  return atexit(func: dynamic_atexit_destructor_for__dt_UsePartialChangeEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x10319B20
// Name: _dynamic_initializer_for__dt_ShowPartialChangeEnts__
// Source: semantic_dyn_pfx_dt
//------------------------------------------------------------------------------
int dynamic_initializer_for__dt_ShowPartialChangeEnts__()
{
  ConVar::ConVar(
    this: &dt_ShowPartialChangeEnts,
    pName: "dt_ShowPartialChangeEnts",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "(SP only) - show entities that were copied using small optimized lists (FL_EDICT_PARTIAL_CHANGE).");
  return atexit(func: dynamic_atexit_destructor_for__dt_ShowPartialChangeEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x10324FD0
// Name: _dynamic_atexit_destructor_for__dt_UsePartialChangeEnts__
// Source: semantic_dyn_pfx_dt
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dt_UsePartialChangeEnts__()
{
  ConVar::~ConVar(this: &dt_UsePartialChangeEnts);
}

//------------------------------------------------------------------------------
// Address: 0x10324FE0
// Name: _dynamic_atexit_destructor_for__dt_ShowPartialChangeEnts__
// Source: semantic_dyn_pfx_dt
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dt_ShowPartialChangeEnts__()
{
  ConVar::~ConVar(this: &dt_ShowPartialChangeEnts);
}

//------------------------------------------------------------------------------
// Address: 0x10319B50
// Name: _dynamic_initializer_for__g_PartialChangeEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PartialChangeEnts__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PartialChangeEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x10319B60
// Name: _dynamic_initializer_for__g_RecvTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RecvTables__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_RecvTables__);
}

//------------------------------------------------------------------------------
// Address: 0x10319B70
// Name: _dynamic_initializer_for__g_RecvDecoders__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RecvDecoders__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_RecvDecoders__);
}

//------------------------------------------------------------------------------
// Address: 0x10319B80
// Name: _dynamic_initializer_for__g_ClientSendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ClientSendTables__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ClientSendTables__);
}

//------------------------------------------------------------------------------
// Address: 0x10319B90
// Name: _dynamic_initializer_for__g_SendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SendTables__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SendTables__);
}

//------------------------------------------------------------------------------
// Address: 0x10319BA0
// Name: _dynamic_initializer_for____g_CreateCEngineTraceServerIEngineTrace_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineTraceServerIEngineTrace_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineTraceServerIEngineTrace_reg,
           fn: (void *(__cdecl *)())_CreateCEngineTraceServerIEngineTrace_interface,
           pName: "EngineTraceServer004");
}

//------------------------------------------------------------------------------
// Address: 0x10319BC0
// Name: _dynamic_initializer_for____g_CreateCEngineTraceClientIEngineTrace_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineTraceClientIEngineTrace_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineTraceClientIEngineTrace_reg,
           fn: (void *(__cdecl *)())_CreateCEngineTraceClientIEngineTrace_interface,
           pName: "EngineTraceClient004");
}

//------------------------------------------------------------------------------
// Address: 0x10324FF0
// Name: _dynamic_atexit_destructor_for__g_PartialChangeEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PartialChangeEnts__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_PartialChangeEnts);
}

//------------------------------------------------------------------------------
// Address: 0x10325020
// Name: _dynamic_atexit_destructor_for__g_RecvTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RecvTables__()
{
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvTables);
  if ( g_RecvTables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_RecvTables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RecvTables.m_Memory.m_pMemory);
      g_RecvTables.m_Memory.m_pMemory = nullptr;
    }
    g_RecvTables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10325070
// Name: _dynamic_atexit_destructor_for__g_RecvDecoders__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RecvDecoders__()
{
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvDecoders);
  if ( g_RecvDecoders.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_RecvDecoders.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RecvDecoders.m_Memory.m_pMemory);
      g_RecvDecoders.m_Memory.m_pMemory = nullptr;
    }
    g_RecvDecoders.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103250C0
// Name: _dynamic_atexit_destructor_for__g_ClientSendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ClientSendTables__()
{
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_ClientSendTables);
  if ( g_ClientSendTables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ClientSendTables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ClientSendTables.m_Memory.m_pMemory);
      g_ClientSendTables.m_Memory.m_pMemory = nullptr;
    }
    g_ClientSendTables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10325110
// Name: _dynamic_atexit_destructor_for__g_SendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SendTables__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_SendTables);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10131BA0
// Name: void std::_Push_heap<int __near *,int,int,bool (*)(int const __near &,int const __near &)>(int __near *,int,int,int __near &&,bool (*)(int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        int *_First,
        int _Hole,
        int _Top,
        int *_Val,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int v5; // edi
  int v6; // esi
  bool v7; // zf
  int *v8; // eax

  v5 = _Hole;
  v6 = (_Hole - 1) / 2;
  if ( _Top >= _Hole )
  {
    _First[_Hole] = *_Val;
  }
  else
  {
    while ( 1 )
    {
      v7 = !_Pred(a1: &_First[v6], a2: _Val);
      v8 = _First;
      if ( v7 )
        break;
      _First[v5] = _First[v6];
      v5 = v6;
      v6 = (v6 - 1) / 2;
      if ( _Top >= v5 )
      {
        v8 = _First;
        break;
      }
    }
    v8[v5] = *_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132CB0
// Name: void std::_Adjust_heap<int __near *,int,int,bool (*)(int const __near &,int const __near &)>(int __near *,int,int,int __near &&,bool (*)(int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        int *_First,
        int _Hole,
        int _Bottom,
        int *_Val,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  int v9; // esi

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      _First[v6] = _First[v7];
      v6 = v7;
      v7 = 2 * v7 + 2;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    _First[v6] = _First[v5 - 1];
    v6 = v5 - 1;
  }
  v9 = (v6 - 1) / 2;
  if ( _Hole >= v6 )
  {
    _First[v6] = *_Val;
  }
  else
  {
    while ( _Pred(a1: &_First[v9], a2: _Val) )
    {
      _First[v6] = _First[v9];
      v6 = v9;
      v9 = (v9 - 1) / 2;
      if ( _Hole >= v6 )
      {
        _First[v6] = *_Val;
        return;
      }
    }
    _First[v6] = *_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132F80
// Name: void std::_Make_heap<int __near *,int,int,bool (*)(int const __near &,int const __near &)>(int __near *,int __near *,bool (*)(int const __near &,int const __near &),int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        int *_First,
        int *_Last,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int v4; // ecx
  int v5; // ebx
  int i; // esi
  int v7; // eax
  int v8; // esi
  bool v9; // zf
  int v10; // eax
  int v11; // edx
  int _Val; // [esp+8h] [ebp-8h] BYREF
  int v13; // [esp+Ch] [ebp-4h]
  int _Bottom; // [esp+18h] [ebp+8h]
  int _Lasta; // [esp+1Ch] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    for ( i = 2 * v5 + 2; ; i = v13 )
    {
      v7 = _First[--v5];
      v8 = i - 2;
      v13 = v8;
      _Val = v7;
      _Lasta = v5;
      v9 = v8 == v4;
      if ( v8 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v8], a2: &_First[v8 - 1]) )
            --v8;
          v10 = _Lasta;
          v11 = _First[v8];
          _Lasta = v8;
          v8 = 2 * v8 + 2;
          _First[v10] = v11;
        }
        while ( v8 < _Bottom );
        v4 = _Bottom;
        v9 = v8 == _Bottom;
      }
      if ( v9 )
      {
        _First[_Lasta] = _First[v4 - 1];
        _Lasta = v4 - 1;
      }
      std::_Push_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        _First,
        _Hole: _Lasta,
        _Top: v5,
        &_Val,
        _Pred);
      if ( v5 <= 0 )
        break;
      v4 = _Bottom;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133CB0
// Name: void std::_Sort_heap<int __near *,bool (*)(int const __near &,int const __near &)>(int __near *,int __near *,bool (*)(int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<int *,bool (__cdecl *)(int const &,int const &)>(
        char *_First,
        int *_Last,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int v3; // eax
  bool (__cdecl *v4)(const int *, const int *); // ebx
  int *v5; // edx
  int v6; // edi

  v3 = (char *)_Last - _First;
  if ( (int)(((char *)_Last - _First) & 0xFFFFFFFC) > 4 )
  {
    v4 = _Pred;
    do
    {
      v5 = *(int **)&_First[v3 - 4];
      v6 = v3 - 4;
      *(_DWORD *)&_First[v3 - 4] = *(_DWORD *)_First;
      _Last = v5;
      std::_Adjust_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        (int *)_First,
        _Hole: 0,
        _Bottom: (v3 - 4) >> 2,
        _Val: (int *)&_Last,
        _Pred: v4);
      v3 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101653F0
// Name: public: CDeltaBitsReader::CDeltaBitsReader(class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
CDeltaBitsReader *__thiscall CDeltaBitsReader::CDeltaBitsReader(CDeltaBitsReader *this, bf_read *pBuf)
{
  CDeltaBitsReader *result; // eax
  unsigned int m_nInBufWord; // esi
  int v4; // ecx
  const unsigned int *m_pDataIn; // esi
  const unsigned int *m_pBufferEnd; // edi
  bool v8; // cl
  unsigned int v9; // edi

  result = this;
  this->m_pBuf = pBuf;
  this->m_bFinished = false;
  this->m_iLastProp = -1;
  if ( pBuf != nullptr )
  {
    m_nInBufWord = pBuf->m_nInBufWord;
    v4 = m_nInBufWord & 1;
    if ( pBuf->m_nBitsAvail-- == 1 )
    {
      m_pDataIn = pBuf->m_pDataIn;
      m_pBufferEnd = pBuf->m_pBufferEnd;
      pBuf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pBuf->m_pDataIn = m_pDataIn + 1;
        pBuf->m_nBitsAvail = 1;
        pBuf->m_nInBufWord = 0;
        result->m_bUsingNewScheme = v4 != 0;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v9 = *m_pDataIn;
          pBuf->m_pDataIn = m_pDataIn + 1;
          pBuf->m_nInBufWord = v9;
          v8 = v4 != 0;
        }
        else
        {
          v8 = v4 != 0;
          pBuf->m_bOverflow = true;
          pBuf->m_nInBufWord = 0;
        }
        result->m_bUsingNewScheme = v8;
      }
    }
    else
    {
      pBuf->m_nInBufWord = m_nInBufWord >> 1;
      result->m_bUsingNewScheme = v4 != 0;
    }
  }
  else
  {
    this->m_bUsingNewScheme = false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101654A0
// Name: public: int CDeltaBitsReader::ReadNextPropIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDeltaBitsReader::ReadNextPropIndex(CDeltaBitsReader *this)
{
  bf_read *m_pBuf; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  bool v5; // zf
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // edi
  bf_read *v9; // edx
  unsigned int v10; // ecx
  int v11; // edi
  const unsigned int *v12; // ecx
  const unsigned int *v13; // esi
  int m_nBitsAvail; // ecx
  unsigned int v15; // esi
  int v16; // ebx
  int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // esi
  const unsigned int *v20; // ecx
  const unsigned int *v21; // esi
  const unsigned int *v22; // edi
  unsigned int v23; // ebx
  int v24; // esi
  const unsigned int *v25; // ecx
  unsigned int v26; // edi
  unsigned int v27; // eax
  unsigned int v28; // edi
  int v29; // ecx
  unsigned int v30; // esi
  int v31; // edi
  int v32; // ecx
  int v33; // eax
  const unsigned int *v34; // ecx
  const unsigned int *v35; // esi
  const unsigned int *v36; // edi
  unsigned int v37; // ebx
  int v38; // esi
  const unsigned int *v39; // ecx
  unsigned int v40; // edi
  unsigned int v41; // eax
  int v42; // ecx
  int v43; // edi
  unsigned int v44; // esi
  int v45; // ecx
  int v46; // edi
  int v47; // esi
  unsigned int v48; // esi
  int v49; // edi
  const unsigned int *v50; // esi
  const unsigned int *v51; // edi
  unsigned int v52; // ecx
  unsigned int v53; // edi
  const unsigned int *v54; // ecx
  unsigned int v55; // ebx
  int v56; // esi
  const unsigned int *v57; // edi
  unsigned int v58; // edi
  unsigned int v59; // eax
  int v60; // edi
  unsigned int v61; // esi
  int v62; // ecx
  int v63; // edi
  const unsigned int *v64; // esi
  const unsigned int *v65; // edi
  const unsigned int *v66; // ecx
  unsigned int v67; // ebx
  int v68; // esi
  const unsigned int *v69; // edi
  unsigned int v70; // edi
  unsigned int v71; // eax
  int v72; // ebx
  int v73; // ecx
  int v75; // [esp+10h] [ebp-4h]

  if ( this->m_bUsingNewScheme )
  {
    m_pBuf = this->m_pBuf;
    m_nInBufWord = this->m_pBuf->m_nInBufWord;
    v4 = m_nInBufWord & 1;
    v5 = this->m_pBuf->m_nBitsAvail-- == 1;
    if ( v5 )
    {
      m_pDataIn = m_pBuf->m_pDataIn;
      m_pBufferEnd = m_pBuf->m_pBufferEnd;
      m_pBuf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        m_pBuf->m_nBitsAvail = 1;
        m_pBuf->m_nInBufWord = 0;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        m_pBuf->m_nInBufWord = *m_pDataIn;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        m_pBuf->m_bOverflow = true;
        m_pBuf->m_nInBufWord = 0;
      }
    }
    else
    {
      m_pBuf->m_nInBufWord = m_nInBufWord >> 1;
    }
    if ( v4 != 0 )
      return ++this->m_iLastProp;
  }
  v9 = this->m_pBuf;
  if ( this->m_bUsingNewScheme )
  {
    v10 = v9->m_nInBufWord;
    v11 = v10 & 1;
    v5 = v9->m_nBitsAvail-- == 1;
    if ( v5 )
    {
      v12 = v9->m_pDataIn;
      v13 = v9->m_pBufferEnd;
      v9->m_nBitsAvail = 32;
      if ( v12 == v13 )
      {
        v9->m_nBitsAvail = 1;
        v9->m_nInBufWord = 0;
        v9->m_pDataIn = v12 + 1;
      }
      else if ( v12 <= v13 )
      {
        v9->m_nInBufWord = *v12;
        v9->m_pDataIn = v12 + 1;
      }
      else
      {
        v9->m_bOverflow = true;
        v9->m_nInBufWord = 0;
      }
    }
    else
    {
      v9->m_nInBufWord = v10 >> 1;
    }
    if ( v11 != 0 )
    {
      m_nBitsAvail = v9->m_nBitsAvail;
      if ( m_nBitsAvail >= 3 )
      {
        v15 = v9->m_nInBufWord;
        v16 = v15 & 7;
        v17 = m_nBitsAvail - 3;
        v18 = 0;
        v9->m_nBitsAvail = v17;
        if ( v17 != 0 )
        {
          v9->m_nInBufWord = v15 >> 3;
          v19 = v15 & 7;
        }
        else
        {
          v20 = v9->m_pDataIn;
          v21 = v9->m_pBufferEnd;
          v9->m_nBitsAvail = 32;
          if ( v20 == v21 )
          {
            v9->m_nBitsAvail = 1;
            v9->m_pDataIn = v20 + 1;
            v9->m_nInBufWord = 0;
            v19 = v16;
          }
          else
          {
            if ( v20 <= v21 )
            {
              v18 = *v20;
              v9->m_pDataIn = v20 + 1;
            }
            else
            {
              v9->m_bOverflow = true;
            }
            v9->m_nInBufWord = v18;
            v19 = v16;
          }
        }
        goto LABEL_100;
      }
      v22 = v9->m_pBufferEnd;
      v23 = v9->m_nInBufWord;
      v24 = 3 - m_nBitsAvail;
      v25 = v9->m_pDataIn;
      if ( v25 == v22 )
      {
        v9->m_nBitsAvail = 1;
        v9->m_nInBufWord = 0;
        v9->m_bOverflow = true;
      }
      else
      {
        if ( v25 > v22 )
        {
          v9->m_bOverflow = true;
          v9->m_nInBufWord = 0;
          goto LABEL_35;
        }
        v9->m_nInBufWord = *v25;
      }
      v9->m_pDataIn = v25 + 1;
LABEL_35:
      if ( v9->m_bOverflow )
      {
        v19 = 0;
      }
      else
      {
        v26 = v9->m_nInBufWord;
        v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << v9->m_nBitsAvail;
        v9->m_nBitsAvail = 32 - v24;
        v28 = v26 >> v24;
        v19 = v27 | v23;
        v9->m_nInBufWord = v28;
      }
      goto LABEL_100;
    }
  }
  v29 = v9->m_nBitsAvail;
  if ( v29 < 7 )
  {
    v36 = v9->m_pBufferEnd;
    v37 = v9->m_nInBufWord;
    v38 = 7 - v29;
    v39 = v9->m_pDataIn;
    if ( v39 == v36 )
    {
      v9->m_nBitsAvail = 1;
      v9->m_nInBufWord = 0;
      v9->m_bOverflow = true;
    }
    else
    {
      if ( v39 > v36 )
      {
        v9->m_bOverflow = true;
        v9->m_nInBufWord = 0;
        goto LABEL_53;
      }
      v9->m_nInBufWord = *v39;
    }
    v9->m_pDataIn = v39 + 1;
LABEL_53:
    if ( v9->m_bOverflow )
    {
      v33 = 0;
      v75 = 0;
    }
    else
    {
      v40 = v9->m_nInBufWord;
      v41 = (v40 & CBitBuffer::s_nMaskTable[v38]) << v9->m_nBitsAvail;
      v9->m_nBitsAvail = 32 - v38;
      v33 = v41 | v37;
      v75 = v33;
      v9->m_nInBufWord = v40 >> v38;
    }
    goto LABEL_56;
  }
  v30 = v9->m_nInBufWord;
  v31 = v30 & 0x7F;
  v32 = v29 - 7;
  v9->m_nBitsAvail = v32;
  if ( v32 != 0 )
  {
    v33 = v30 & 0x7F;
    v9->m_nInBufWord = v30 >> 7;
    v75 = v33;
  }
  else
  {
    v34 = v9->m_pDataIn;
    v35 = v9->m_pBufferEnd;
    v9->m_nBitsAvail = 32;
    if ( v34 == v35 )
    {
      v9->m_nInBufWord = 0;
      v33 = v31;
      v9->m_nBitsAvail = 1;
      v9->m_pDataIn = v34 + 1;
      v75 = v31;
    }
    else
    {
      if ( v34 <= v35 )
      {
        v9->m_nInBufWord = *v34;
        v33 = v31;
        v9->m_pDataIn = v34 + 1;
      }
      else
      {
        v9->m_nInBufWord = 0;
        v33 = v31;
        v9->m_bOverflow = true;
      }
      v75 = v31;
    }
  }
LABEL_56:
  v42 = v33 & 0x60;
  v19 = v33;
  if ( v42 == 32 )
  {
    v60 = v9->m_nBitsAvail;
    if ( v60 >= 2 )
    {
      v61 = v9->m_nInBufWord;
      v62 = v61 & 3;
      v63 = v60 - 2;
      v9->m_nBitsAvail = v63;
      if ( v63 != 0 )
      {
        v9->m_nInBufWord = v61 >> 2;
      }
      else
      {
        v64 = v9->m_pDataIn;
        v65 = v9->m_pBufferEnd;
        v9->m_nBitsAvail = 32;
        if ( v64 == v65 )
        {
          v9->m_nBitsAvail = 1;
          v9->m_nInBufWord = 0;
          v9->m_pDataIn = v64 + 1;
        }
        else if ( v64 <= v65 )
        {
          v9->m_nInBufWord = *v64;
          v9->m_pDataIn = v64 + 1;
        }
        else
        {
          v9->m_bOverflow = true;
          v9->m_nInBufWord = 0;
        }
      }
LABEL_99:
      v19 = (32 * v62) | v33 & 0xFFFFFF9F;
      goto LABEL_100;
    }
    v66 = v9->m_pDataIn;
    v67 = v9->m_nInBufWord;
    v68 = 2 - v60;
    v69 = v9->m_pBufferEnd;
    if ( v66 == v69 )
    {
      v9->m_nBitsAvail = 1;
      v9->m_nInBufWord = 0;
      v9->m_bOverflow = true;
    }
    else
    {
      if ( v66 > v69 )
      {
        v9->m_bOverflow = true;
        v9->m_nInBufWord = 0;
        goto LABEL_96;
      }
      v9->m_nInBufWord = *v66;
    }
    v9->m_pDataIn = v66 + 1;
LABEL_96:
    if ( v9->m_bOverflow )
    {
      v62 = 0;
    }
    else
    {
      v70 = v9->m_nInBufWord;
      v71 = (v70 & CBitBuffer::s_nMaskTable[v68]) << v9->m_nBitsAvail;
      v9->m_nBitsAvail = 32 - v68;
      v72 = v71 | v67;
      v33 = v75;
      v62 = v72;
      v9->m_nInBufWord = v70 >> v68;
    }
    goto LABEL_99;
  }
  if ( v42 != 64 )
  {
    if ( v42 != 96 )
      goto LABEL_100;
    v43 = v9->m_nBitsAvail;
    if ( v43 >= 7 )
    {
      v44 = v9->m_nInBufWord;
      v45 = v44 & 0x7F;
      v46 = v43 - 7;
      v9->m_nBitsAvail = v46;
      if ( v46 != 0 )
      {
        v9->m_nInBufWord = v44 >> 7;
        v19 = v33 & 0xFFFFFF9F | (32 * v45);
        goto LABEL_100;
      }
LABEL_66:
      v50 = v9->m_pDataIn;
      v51 = v9->m_pBufferEnd;
      v9->m_nBitsAvail = 32;
      if ( v50 == v51 )
      {
        v9->m_pDataIn = v50 + 1;
        v9->m_nBitsAvail = 1;
        v9->m_nInBufWord = 0;
        v19 = v33 & 0xFFFFFF9F | (32 * v45);
      }
      else
      {
        if ( v50 <= v51 )
        {
          v53 = *v50;
          v52 = v33 & 0xFFFFFF9F | (32 * v45);
          v9->m_pDataIn = v50 + 1;
          v9->m_nInBufWord = v53;
        }
        else
        {
          v52 = v33 & 0xFFFFFF9F | (32 * v45);
          v9->m_bOverflow = true;
          v9->m_nInBufWord = 0;
        }
        v19 = v52;
      }
      goto LABEL_100;
    }
    v47 = 7;
LABEL_73:
    v54 = v9->m_pDataIn;
    v55 = v9->m_nInBufWord;
    v56 = v47 - v43;
    v57 = v9->m_pBufferEnd;
    if ( v54 == v57 )
    {
      v9->m_nBitsAvail = 1;
      v9->m_nInBufWord = 0;
      v9->m_bOverflow = true;
    }
    else
    {
      if ( v54 > v57 )
      {
        v9->m_bOverflow = true;
        v9->m_nInBufWord = 0;
        goto LABEL_79;
      }
      v9->m_nInBufWord = *v54;
    }
    v9->m_pDataIn = v54 + 1;
LABEL_79:
    if ( v9->m_bOverflow )
    {
      v19 = v33 & 0xFFFFFF9F;
    }
    else
    {
      v58 = v9->m_nInBufWord;
      v59 = (v58 & CBitBuffer::s_nMaskTable[v56]) << v9->m_nBitsAvail;
      v9->m_nBitsAvail = 32 - v56;
      v9->m_nInBufWord = v58 >> v56;
      v19 = v75 & 0xFFFFFF9F | (32 * (v59 | v55));
    }
    goto LABEL_100;
  }
  v43 = v9->m_nBitsAvail;
  if ( v43 < 4 )
  {
    v47 = 4;
    goto LABEL_73;
  }
  v48 = v9->m_nInBufWord;
  v45 = v48 & 0xF;
  v49 = v43 - 4;
  v9->m_nBitsAvail = v49;
  if ( v49 == 0 )
    goto LABEL_66;
  v9->m_nInBufWord = v48 >> 4;
  v19 = v33 & 0xFFFFFF9F | (32 * v45);
LABEL_100:
  if ( v19 == 4095 )
  {
    this->m_bFinished = true;
    return -1;
  }
  else
  {
    v73 = this->m_iLastProp + v19 + 1;
    this->m_iLastProp = v73;
    return v73;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165A20
// Name: public: void CDeltaBitsReader::ForceFinished(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaBitsReader::ForceFinished(CDeltaBitsReader *this)
{
  this->m_bFinished = true;
  this->m_pBuf = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10165A80
// Name: SendTable_GetPropsExcluded
// Source: json
//------------------------------------------------------------------------------
char __cdecl SendTable_GetPropsExcluded(
        const SendTable *pTable,
        ExcludeProp *pExcludeProps,
        int *nExcludeProps,
        int nMaxExcludeProps)
{
  const SendTable *v4; // ecx
  SendProp *v5; // esi
  const char *m_pExcludeDTName; // ebx
  const SendTable *m_pDataTable; // esi
  int i; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]

  v4 = pTable;
  i = 0;
  if ( pTable->m_nProps <= 0 )
    return 1;
  for ( j = 0; ; ++j )
  {
    v5 = &v4->m_pProps[j];
    if ( (v5->m_Flags & 0x40) != 0 )
    {
      m_pExcludeDTName = v5->m_pExcludeDTName;
      if ( m_pExcludeDTName == nullptr )
        _Error(a1: "Found an exclude prop missing a name.");
      if ( *nExcludeProps >= nMaxExcludeProps )
        _Error(a1: "SendTable_GetPropsExcluded: Overflowed max exclude props with %s.", m_pExcludeDTName);
      pExcludeProps[*nExcludeProps].m_pTableName = m_pExcludeDTName;
      pExcludeProps[(*nExcludeProps)++].m_pPropName = v5->m_pVarName;
      goto LABEL_11;
    }
    m_pDataTable = v5->m_pDataTable;
    if ( m_pDataTable != nullptr
      && !SendTable_GetPropsExcluded(pTable: m_pDataTable, pExcludeProps, nExcludeProps, nMaxExcludeProps) )
    {
      break;
    }
LABEL_11:
    v4 = pTable;
    if ( ++i >= pTable->m_nProps )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10165B40
// Name: bool AreBitArraysEqual(void const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AreBitArraysEqual(_BYTE *pvBits1, _BYTE *pvBits2, int nBits)
{
  int v3; // eax
  _BYTE *v4; // edi
  unsigned int v5; // ecx
  _BYTE *v6; // esi
  int v8; // edi

  v3 = nBits >> 3;
  v4 = pvBits1;
  v5 = nBits >> 3;
  v6 = pvBits2;
  if ( (unsigned int)(nBits >> 3) >= 4 )
  {
    while ( *(_DWORD *)v4 == *(_DWORD *)v6 )
    {
      v5 -= 4;
      v6 += 4;
      v4 += 4;
      if ( v5 < 4 )
        goto LABEL_4;
    }
    return 0;
  }
LABEL_4:
  if ( v5 != 0 && (*v6 != *v4 || v5 > 1 && (v6[1] != v4[1] || v5 > 2 && v6[2] != v4[2])) )
    return 0;
  v8 = 8 * v3;
  if ( 8 * v3 < nBits )
  {
    while ( ((unsigned __int8)(1 << (v8 & 7)) & pvBits1[v8 >> 3]) == ((unsigned __int8)(1 << (v8 & 7)) & pvBits2[v8 >> 3]) )
    {
      if ( ++v8 >= nBits )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10165BF0
// Name: bool CompareBitArrays(void const __near *,void const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CompareBitArrays(_BYTE *pPacked1, _BYTE *pPacked2, int nBits1, int nBits2)
{
  if ( nBits1 < 0 || nBits1 != nBits2 )
    return 0;
  if ( pPacked1 == pPacked2 )
    return 1;
  return AreBitArraysEqual(pvBits1: pPacked1, pvBits2: pPacked2, nBits: nBits1);
}

//------------------------------------------------------------------------------
// Address: 0x10165C20
// Name: bool Sendprop_UsingDebugWatch(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Sendprop_UsingDebugWatch()
{
  bool result; // al
  char *m_pszString; // eax

  result = true;
  if ( g_CV_DTWatchEnt.m_pParent != nullptr
    && g_CV_DTWatchEnt.m_pParent->m_Value.m_nValue == -1
    && (g_CV_DTWatchClass.m_nFlags & 0x1000) == 0 )
  {
    m_pszString = g_CV_DTWatchClass.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr || *m_pszString == 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10165C60
// Name: void DataTable_Warning(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DataTable_Warning(char *pInMessage, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(params, pInMessage);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: pInMessage, params);
  _Warning(a1: "DataTable warning: %s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10165D20
// Name: public: void CUtlMemory<class CSendTablePrecalc::CProxyPathEntry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSendTablePrecalc::CProxyPathEntry,int>::Grow(
        CUtlMemory<SendProp const *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  const SendProp **m_pMemory; // ecx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (const SendProp **)_realloc_crt(ptr: m_pMemory, size: 4 * m_nAllocationCount);
    else
      this->m_pMemory = (const SendProp **)MemAlloc_Alloc(nSize: 4 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165DC0
// Name: public: CDeltaBitsWriter::CDeltaBitsWriter(class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
CDeltaBitsWriter *__thiscall CDeltaBitsWriter::CDeltaBitsWriter(CDeltaBitsWriter *this, bf_write *pBuf)
{
  int m_nValue; // eax
  bool v4; // al
  int m_iCurBit; // ecx
  int v6; // edi

  this->m_pBuf = pBuf;
  this->m_iLastProp = -1;
  if ( sv_new_delta_bits.m_pParent != nullptr )
    m_nValue = sv_new_delta_bits.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v4 = m_nValue != 0;
  this->m_bUsingNewScheme = v4;
  m_iCurBit = pBuf->m_iCurBit;
  v6 = m_iCurBit + 1;
  if ( v4 )
  {
    if ( v6 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++pBuf->m_iCurBit;
      return this;
    }
  }
  else
  {
    if ( v6 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      pBuf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++pBuf->m_iCurBit;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10165E60
// Name: public: CDeltaBitsWriter::~CDeltaBitsWriter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaBitsWriter::~CDeltaBitsWriter(CDeltaBitsWriter *this)
{
  bf_write *m_pBuf; // eax
  int m_iCurBit; // ecx
  bf_write *v4; // eax
  int v5; // ecx

  if ( this->m_bUsingNewScheme )
  {
    m_pBuf = this->m_pBuf;
    m_iCurBit = this->m_pBuf->m_iCurBit;
    if ( m_iCurBit + 1 > this->m_pBuf->m_nDataBits )
      m_pBuf->m_bOverflow = true;
    if ( !m_pBuf->m_bOverflow )
    {
      m_pBuf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++m_pBuf->m_iCurBit;
    }
  }
  v4 = this->m_pBuf;
  if ( this->m_bUsingNewScheme )
  {
    v5 = v4->m_iCurBit;
    if ( v5 + 1 > v4->m_nDataBits )
      v4->m_bOverflow = true;
    if ( !v4->m_bOverflow )
    {
      v4->m_pData[v5 >> 3] &= ~(1 << (v5 & 7));
      ++v4->m_iCurBit;
    }
  }
  bf_write::WriteUBitLong(this: v4, curData: 0x3FFFu, numbits: 14, bCheckRange: true);
}

//------------------------------------------------------------------------------
// Address: 0x10165EE0
// Name: public: void CDeltaBitsWriter::WritePropIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaBitsWriter::WritePropIndex(CDeltaBitsWriter *this, int iProp)
{
  unsigned int v3; // eax
  bool v4; // zf
  bf_write *v5; // edi
  int m_iCurBit; // ecx
  bf_write *v7; // esi
  int v8; // ecx
  bf_write *v9; // esi
  int v10; // ecx
  int v11; // edi
  bf_write *m_pBuf; // ecx

  v3 = iProp - this->m_iLastProp - 1;
  v4 = !this->m_bUsingNewScheme;
  this->m_iLastProp = iProp;
  if ( v4 )
  {
    m_pBuf = this->m_pBuf;
    if ( v3 >= 0x20 )
    {
      if ( v3 >= 0x80 )
      {
        if ( v3 >= 0x200 )
          bf_write::WriteUBitLong(
            this: m_pBuf,
            curData: v3 & 0x1F | (4 * (v3 & 0xFE0 | 0x18)),
            numbits: 14,
            bCheckRange: true);
        else
          bf_write::WriteUBitLong(
            this: m_pBuf,
            curData: v3 & 0x1F | (4 * (v3 & 0x1E0 | 0x10)),
            numbits: 11,
            bCheckRange: true);
      }
      else
      {
        bf_write::WriteUBitLong(this: m_pBuf, curData: v3 & 0x1F | (4 * (v3 & 0x60 | 8)), numbits: 9, bCheckRange: true);
      }
    }
    else
    {
      bf_write::WriteUBitLong(this: m_pBuf, curData: v3, numbits: 7, bCheckRange: true);
    }
    return;
  }
  if ( v3 == 0 )
  {
    v5 = this->m_pBuf;
    m_iCurBit = this->m_pBuf->m_iCurBit;
    if ( m_iCurBit + 1 > v5->m_nDataBits )
      v5->m_bOverflow = true;
    if ( !v5->m_bOverflow )
    {
      v5->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++v5->m_iCurBit;
    }
    return;
  }
  v7 = this->m_pBuf;
  v8 = this->m_pBuf->m_iCurBit;
  if ( v8 + 1 > this->m_pBuf->m_nDataBits )
    v7->m_bOverflow = true;
  if ( !v7->m_bOverflow )
  {
    v7->m_pData[v8 >> 3] &= ~(1 << (v8 & 7));
    ++v7->m_iCurBit;
  }
  v9 = this->m_pBuf;
  if ( !this->m_bUsingNewScheme )
  {
LABEL_23:
    if ( v3 >= 0x20 )
    {
      if ( v3 >= 0x80 )
      {
        if ( v3 >= 0x200 )
          bf_write::WriteUBitLong(
            this: v9,
            curData: v3 & 0x1F | (4 * (v3 & 0xFE0 | 0x18)),
            numbits: 14,
            bCheckRange: true);
        else
          bf_write::WriteUBitLong(
            this: v9,
            curData: v3 & 0x1F | (4 * (v3 & 0x1E0 | 0x10)),
            numbits: 11,
            bCheckRange: true);
      }
      else
      {
        bf_write::WriteUBitLong(this: v9, curData: v3 & 0x1F | (4 * (v3 & 0x60 | 8)), numbits: 9, bCheckRange: true);
      }
    }
    else
    {
      bf_write::WriteUBitLong(this: v9, curData: v3, numbits: 7, bCheckRange: true);
    }
    return;
  }
  v10 = v9->m_iCurBit;
  v11 = v10 + 1;
  if ( v3 >= 8 )
  {
    if ( v11 > v9->m_nDataBits )
      v9->m_bOverflow = true;
    if ( !v9->m_bOverflow )
    {
      v9->m_pData[v10 >> 3] &= ~(1 << (v10 & 7));
      ++v9->m_iCurBit;
    }
    goto LABEL_23;
  }
  if ( v11 > v9->m_nDataBits )
    v9->m_bOverflow = true;
  if ( !v9->m_bOverflow )
  {
    v9->m_pData[v10 >> 3] |= 1 << (v10 & 7);
    ++v9->m_iCurBit;
  }
  bf_write::WriteUBitLong(this: v9, curData: v3, numbits: 3, bCheckRange: true);
}

//------------------------------------------------------------------------------
// Address: 0x101660F0
// Name: bool ShouldWatchThisProp(class SendTable const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldWatchThisProp(const SendTable *pTable, int objectID, const char *pPropName)
{
  int m_nValue; // eax
  char *v4; // eax
  char *v5; // eax
  char *m_pszString; // eax

  if ( g_CV_DTEncode.m_pParent != nullptr && g_CV_DTEncode.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( g_CV_DTWatchEnt.m_pParent != nullptr )
    {
      m_nValue = g_CV_DTWatchEnt.m_pParent->m_Value.m_nValue;
      if ( m_nValue == -1 )
        goto LABEL_5;
    }
    else
    {
      m_nValue = 0;
    }
    if ( m_nValue == objectID )
    {
      if ( (g_CV_DTWatchVar.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = g_CV_DTWatchVar.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr || *m_pszString == 0 )
          return 1;
      }
      return _V_stricmp(s1: m_pszString, s2: pPropName) == 0;
    }
LABEL_5:
    if ( (g_CV_DTWatchClass.m_nFlags & 0x1000) == 0 )
    {
      v4 = g_CV_DTWatchClass.m_pParent->m_Value.m_pszString;
      if ( v4 == nullptr || *v4 == 0 )
        return 0;
    }
    if ( (g_CV_DTWatchClass.m_nFlags & 0x1000) != 0 )
    {
      v5 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v5 = g_CV_DTWatchClass.m_pParent->m_Value.m_pszString;
      if ( v5 == nullptr )
        v5 = (char *)defaultValue;
    }
    return V_stristr(pStr: pTable->m_pNetTableName, pSearch: v5) != nullptr;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10166270
// Name: void std::_Rotate<unsigned char __near *,int,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char __near *,int __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Rotate<unsigned char *,int,unsigned char>(
        unsigned __int8 *_First,
        unsigned __int8 *_Mid,
        unsigned __int8 *_Last)
{
  unsigned __int8 *v3; // ecx
  int v5; // esi
  unsigned __int8 *v6; // edx
  int v7; // eax
  int v8; // ebx
  int v9; // edx
  unsigned __int8 *v10; // ebx
  unsigned __int8 *v11; // edx
  unsigned __int8 *v12; // eax
  int v13; // ecx
  unsigned __int8 *v14; // [esp+14h] [ebp-8h]
  unsigned __int8 *_Next; // [esp+28h] [ebp+Ch]
  unsigned __int8 *_Nexta; // [esp+28h] [ebp+Ch]
  unsigned __int8 _Next_3; // [esp+2Bh] [ebp+Fh]
  int _Count; // [esp+2Ch] [ebp+10h]

  v3 = _First;
  v5 = _Mid - _First;
  v6 = (unsigned __int8 *)(_Last - _First);
  _Next = (unsigned __int8 *)(_Last - _First);
  v7 = _Last - _First;
  _Count = _Last - _First;
  v8 = v5;
  if ( v5 != 0 )
  {
    do
    {
      v9 = v7 % v8;
      v7 = v8;
      v8 = v9;
    }
    while ( v9 != 0 );
    v6 = _Next;
    _Count = v7;
  }
  if ( v7 < (int)v6 && v7 > 0 )
  {
    v10 = &_First[v7];
    v14 = &_First[v7];
    while ( 1 )
    {
      v11 = &v10[v5];
      v12 = v10;
      if ( &v10[v5] == _Last )
        v11 = v3;
      v13 = -(int)v11;
      do
      {
        _Next_3 = *v12;
        *v12 = *v11;
        *v11 = _Next_3;
        v12 = v11;
        _Nexta = v11;
        if ( v5 >= (int)&_Last[v13] )
        {
          v11 = &_First[v5 - (_DWORD)_Last + (_DWORD)v11];
          v13 = &_Last[v13 - v5] - _First;
          v12 = _Nexta;
        }
        else
        {
          v11 += v5;
          v13 -= v5;
        }
      }
      while ( v11 != v14 );
      v10 = v14 - 1;
      --_Count;
      --v14;
      if ( _Count <= 0 )
        break;
      v3 = _First;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166340
// Name: SetDataTableProxyIndices_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetDataTableProxyIndices_R(
        CSendTablePrecalc *pMainTable,
        CSendNode *pCurTable,
        CBuildHierarchyStruct *bhs)
{
  int i; // esi
  CSendNode *v4; // eax

  for ( i = 0; i < pCurTable->m_Children.m_Size; ++i )
  {
    v4 = pCurTable->m_Children.m_Memory.m_pMemory[i];
    if ( (bhs->m_pDatatableProps[v4->m_iDatatableProp]->m_Flags & 0x200) != 0 )
    {
      v4->m_DataTableProxyIndex = 255;
    }
    else
    {
      v4->m_DataTableProxyIndex = pMainTable->m_nDataTableProxies;
      ++pMainTable->m_nDataTableProxies;
    }
    SetDataTableProxyIndices_R(pMainTable, pCurTable: v4, bhs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101663A0
// Name: SetRecursiveProxyIndices_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetRecursiveProxyIndices_R(SendTable *pBaseTable, CSendNode *pCurTable, int *iCurProxyIndex)
{
  int i; // esi

  if ( *iCurProxyIndex >= 64 )
    _Error(a1: "Too many proxies for datatable %s.", pBaseTable->m_pNetTableName);
  pCurTable->m_RecursiveProxyIndex = *(_WORD *)iCurProxyIndex;
  ++*iCurProxyIndex;
  for ( i = 0; i < pCurTable->m_Children.m_Size; ++i )
    SetRecursiveProxyIndices_R(pBaseTable, pCurTable: pCurTable->m_Children.m_Memory.m_pMemory[i], iCurProxyIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10166400
// Name: void CalcPathLengths_R(class CSendNode __near *,class CUtlVector<int,class CUtlMemory<int,int>> __near &,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcPathLengths_R(
        CSendNode *pNode,
        CUtlVector<int,CUtlMemory<int,int> > *pathLengths,
        int curPathLength,
        int *totalPathLengths)
{
  int i; // esi

  pathLengths->m_Memory.m_pMemory[pNode->m_RecursiveProxyIndex] = curPathLength;
  *totalPathLengths += curPathLength;
  for ( i = 0; i < pNode->m_Children.m_Size; ++i )
    CalcPathLengths_R(
      pNode: pNode->m_Children.m_Memory.m_pMemory[i],
      pathLengths,
      curPathLength: curPathLength + 1,
      totalPathLengths);
}

//------------------------------------------------------------------------------
// Address: 0x10166450
// Name: void FillPathEntries_R(class CSendTablePrecalc __near *,class CSendNode __near *,class CSendNode __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FillPathEntries_R(CSendTablePrecalc *pPrecalc, CSendNode *pNode, CSendNode *pParent, int *iCurEntry)
{
  CSendTablePrecalc *v4; // ebx
  CSendNode *v5; // edi
  CSendTablePrecalc::CProxyPath *v6; // eax
  CSendTablePrecalc::CProxyPath *v7; // ecx
  int v8; // eax
  int v9; // edx
  int i; // [esp+14h] [ebp+8h]

  v4 = pPrecalc;
  v5 = pNode;
  v6 = &pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[pNode->m_RecursiveProxyIndex];
  v6->m_iFirstEntry = *(_WORD *)iCurEntry;
  if ( pParent != nullptr )
  {
    v7 = &pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[pParent->m_RecursiveProxyIndex];
    v6->m_nEntries = v7->m_nEntries + 1;
    v8 = 0;
    if ( v7->m_nEntries != 0 )
    {
      do
      {
        v9 = (*iCurEntry)++;
        v4->m_ProxyPathEntries.m_Memory.m_pMemory[v9] = v4->m_ProxyPathEntries.m_Memory.m_pMemory[v8 + v7->m_iFirstEntry];
        v4 = pPrecalc;
        ++v8;
      }
      while ( v8 < v7->m_nEntries );
      v5 = pNode;
    }
    v4->m_ProxyPathEntries.m_Memory.m_pMemory[*iCurEntry].m_iProxy = v5->m_RecursiveProxyIndex;
    v4->m_ProxyPathEntries.m_Memory.m_pMemory[(*iCurEntry)++].m_iDatatableProp = v5->m_iDatatableProp;
  }
  else
  {
    v6->m_nEntries = 0;
  }
  for ( i = 0; i < v5->m_Children.m_Size; ++i )
    FillPathEntries_R(pPrecalc: v4, pNode: v5->m_Children.m_Memory.m_pMemory[i], pParent: v5, iCurEntry);
}

//------------------------------------------------------------------------------
// Address: 0x10166520
// Name: struct std::pair<unsigned char __near *,int> std::get_temporary_buffer<unsigned char>(int)
// Source: json
//------------------------------------------------------------------------------
std::pair<unsigned char *,int> *__cdecl std::get_temporary_buffer<unsigned char>(
        std::pair<unsigned char *,int> *result,
        int _Count)
{
  int v2; // esi
  unsigned __int8 *i; // ecx

  v2 = _Count;
  if ( _Count < 0 )
    v2 = 0;
  for ( i = nullptr; v2 > 0; v2 /= 2 )
  {
    i = (unsigned __int8 *)operator new(count: v2);
    if ( i != nullptr )
      break;
  }
  result->second = v2;
  result->first = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101665C0
// Name: void std::_Insertion_sort1<unsigned char __near *,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Insertion_sort1<unsigned char *,unsigned char>(__m128i *_First, __m128i *_Last)
{
  const __m128i *v2; // edx
  unsigned __int8 *v3; // esi
  int i; // eax
  unsigned __int8 v5; // bl
  unsigned __int8 *v6; // edi
  unsigned __int8 v7; // cl
  unsigned __int8 *j; // eax

  v2 = _First;
  if ( _First != _Last )
  {
    v3 = &_First->m128i_u8[1];
    if ( &_First->m128i_i8[1] != (char *)_Last )
    {
      for ( i = 1 - (_DWORD)_First; ; i = 1 - (_DWORD)_First )
      {
        v5 = *v3;
        v6 = v3;
        if ( *v3 >= (unsigned int)v2->m128i_i8[0] )
        {
          v7 = *(v3 - 1);
          for ( j = v3 - 1; v5 < v7; --j )
          {
            *v6 = v7;
            v7 = *(j - 1);
            v6 = j;
          }
          *v6 = v5;
        }
        else
        {
          memmove(dst: (__m128i *)(1 - i + 1), src: v2, count: (unsigned int)&v3[i - 1]);
          v2 = _First;
          _First->m128i_i8[0] = v5;
        }
        if ( ++v3 == (unsigned __int8 *)_Last )
          break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166630
// Name: unsigned char __near * std::_Merge<unsigned char __near *,unsigned char __near *,unsigned char __near *>(unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
__m128i *__cdecl std::_Merge<unsigned char *,unsigned char *,unsigned char *>(
        const __m128i *_First1,
        const __m128i *_Last1,
        const __m128i *_First2,
        const __m128i *_Last2,
        __m128i *_Dest)
{
  const __m128i *i; // eax
  unsigned __int8 *v8; // ebx
  __m128i *v9; // esi

  for ( i = _First1; i != _Last1; _Dest = (__m128i *)((char *)_Dest + 1) )
  {
    if ( _First2 == _Last2 )
      break;
    if ( _First2->m128i_i8[0] >= (unsigned int)i->m128i_i8[0] )
    {
      _Dest->m128i_i8[0] = i->m128i_i8[0];
      i = (const __m128i *)((char *)i + 1);
    }
    else
    {
      _Dest->m128i_i8[0] = _First2->m128i_i8[0];
      _First2 = (const __m128i *)((char *)_First2 + 1);
    }
  }
  v8 = (unsigned __int8 *)((char *)_Last1 - (char *)i);
  memmove(dst: _Dest, src: i, count: (char *)_Last1 - (char *)i);
  v9 = (__m128i *)((char *)_Dest + (_DWORD)v8);
  memmove(dst: v9, src: _First2, count: (char *)_Last2 - (char *)_First2);
  return (__m128i *)((char *)v9 + (char *)_Last2 - (char *)_First2);
}

//------------------------------------------------------------------------------
// Address: 0x10166690
// Name: unsigned char __near * std::_Merge_backward<unsigned char __near *,unsigned char __near *,unsigned char __near *>(unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
__m128i *__cdecl std::_Merge_backward<unsigned char *,unsigned char *,unsigned char *>(
        const __m128i *_First1,
        const __m128i *_Last1,
        const __m128i *_First2,
        const __m128i *_Last2,
        unsigned __int8 *_Dest)
{
  unsigned __int8 *v5; // eax
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  __m128i *v10; // edi
  __m128i *v12; // edi

  v5 = (unsigned __int8 *)_Last1;
  if ( _First1 == _Last1 )
  {
LABEL_7:
    v10 = (__m128i *)&_Dest[-((char *)_Last2 - (char *)_First2)];
    memmove(dst: v10, src: _First2, count: (char *)_Last2 - (char *)_First2);
    return v10;
  }
  else
  {
    while ( _First2 != _Last2 )
    {
      v8 = _Last2[-1].m128i_u8[15];
      v9 = *(v5 - 1);
      _Last2 = (const __m128i *)((char *)_Last2 - 1);
      --v5;
      --_Dest;
      if ( v8 >= v9 )
      {
        *_Dest = v8;
        ++v5;
      }
      else
      {
        *_Dest = v9;
        _Last2 = (const __m128i *)((char *)_Last2 + 1);
      }
      if ( _First1 == (const __m128i *)v5 )
        goto LABEL_7;
    }
    v12 = (__m128i *)&_Dest[-(v5 - (unsigned __int8 *)_First1)];
    memmove(dst: v12, src: _First1, count: v5 - (unsigned __int8 *)_First1);
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166700
// Name: unsigned char __near * std::lower_bound<unsigned char __near *,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl std::lower_bound<unsigned char *,unsigned char>(
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        const unsigned __int8 *_Val)
{
  unsigned __int8 *v3; // esi
  int v4; // ecx
  int v5; // eax

  v3 = _First;
  v4 = _Last - _First;
  while ( v4 > 0 )
  {
    v5 = v4 / 2;
    if ( v3[v4 / 2] >= *_Val )
    {
      v4 /= 2;
    }
    else
    {
      v3 += v5 + 1;
      v4 += -1 - v5;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10166740
// Name: unsigned char __near * std::upper_bound<unsigned char __near *,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl std::upper_bound<unsigned char *,unsigned char>(
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        const unsigned __int8 *_Val)
{
  unsigned __int8 *v3; // esi
  int v4; // ecx
  int v5; // eax

  v3 = _First;
  v4 = _Last - _First;
  while ( v4 > 0 )
  {
    v5 = v4 / 2;
    if ( *_Val < v3[v4 / 2] )
    {
      v4 /= 2;
    }
    else
    {
      v3 += v5 + 1;
      v4 += -1 - v5;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10166780
// Name: class std::_Temp_iterator<unsigned char> std::_Move<unsigned char __near *,class std::_Temp_iterator<unsigned char>>(unsigned char __near *,unsigned char __near *,class std::_Temp_iterator<unsigned char>,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
std::_Temp_iterator<unsigned char> *__cdecl std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
        std::_Temp_iterator<unsigned char> *result,
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        std::_Temp_iterator<unsigned char> _Dest)
{
  unsigned __int8 *i; // ecx
  std::_Temp_iterator<unsigned char>::_Bufpar *Pbuf; // edx
  unsigned __int8 *Current; // eax

  for ( i = _First; i != _Last; ++i )
  {
    Pbuf = _Dest._Pbuf;
    Current = _Dest._Pbuf->_Current;
    if ( Current >= _Dest._Pbuf->_Hiwater )
    {
      if ( Current != nullptr )
      {
        *Current = *i;
        Pbuf = _Dest._Pbuf;
      }
      _Dest._Pbuf->_Hiwater = ++Pbuf->_Current;
    }
    else
    {
      *Current = *i;
      ++_Dest._Pbuf->_Current;
    }
  }
  result->_Pbuf = _Dest._Pbuf;
  result->_Buf._Begin = nullptr;
  result->_Buf._Current = nullptr;
  result->_Buf._Hiwater = nullptr;
  result->_Buf._Size = 0;
  if ( _Dest._Buf._Begin != nullptr )
    free(pMem: _Dest._Buf._Begin);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166810
// Name: public: int std::_Temp_iterator<unsigned char>::_Maxlen(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::_Temp_iterator<unsigned char>::_Maxlen(std::_Temp_iterator<unsigned char> *this)
{
  std::_Temp_iterator<unsigned char>::_Bufpar *Pbuf; // eax
  bool v3; // zf
  int result; // eax
  unsigned __int8 *first; // eax
  std::pair<unsigned char *,int> _Pair; // [esp+4h] [ebp-8h] BYREF

  Pbuf = this->_Pbuf;
  v3 = Pbuf->_Begin == nullptr;
  result = Pbuf->_Size;
  if ( v3 )
  {
    if ( result <= 0 )
    {
      return this->_Pbuf->_Size;
    }
    else
    {
      std::get_temporary_buffer<unsigned char>(result: &_Pair, _Count: result);
      first = _Pair.first;
      this->_Pbuf->_Begin = _Pair.first;
      this->_Pbuf->_Current = first;
      this->_Pbuf->_Hiwater = first;
      this->_Pbuf->_Size = _Pair.second;
      return this->_Pbuf->_Size;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101668E0
// Name: void std::_Chunked_merge<unsigned char __near *,unsigned char __near *,int>(unsigned char __near *,unsigned char __near *,unsigned char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Chunked_merge<unsigned char *,unsigned char *,int>(
        const __m128i *_First,
        const __m128i *_Last,
        __m128i *_Dest,
        int _Chunk,
        int _Count)
{
  int i; // edx
  unsigned __int8 *v8; // eax
  const __m128i *v9; // ebx
  const __m128i *v10; // edi
  __m128i *v11; // esi
  unsigned __int8 *v12; // edi
  const __m128i *v13; // ebx
  unsigned int v14; // edi
  int v15; // [esp+Ch] [ebp-8h]
  unsigned __int8 *_Mid2; // [esp+10h] [ebp-4h]

  for ( i = _Chunk; _Count >= 2 * _Chunk; i = _Chunk )
  {
    v8 = &_First->m128i_u8[i];
    _Mid2 = &_First->m128i_u8[i + i];
    v9 = (const __m128i *)((char *)_First + i);
    v10 = _First;
    if ( _First != (const __m128i *)&_First->m128i_i8[i] )
    {
      do
      {
        if ( v9 == (const __m128i *)_Mid2 )
          break;
        if ( v9->m128i_i8[0] >= (unsigned int)v10->m128i_i8[0] )
        {
          _Dest->m128i_i8[0] = v10->m128i_i8[0];
          v10 = (const __m128i *)((char *)v10 + 1);
        }
        else
        {
          _Dest->m128i_i8[0] = v9->m128i_i8[0];
          v9 = (const __m128i *)((char *)v9 + 1);
        }
        _Dest = (__m128i *)((char *)_Dest + 1);
      }
      while ( v10 != (const __m128i *)v8 );
    }
    v15 = v8 - (unsigned __int8 *)v10;
    memmove(dst: _Dest, src: v10, count: v8 - (unsigned __int8 *)v10);
    v11 = (__m128i *)((char *)_Dest + v15);
    memmove(dst: v11, src: v9, count: _Mid2 - (unsigned __int8 *)v9);
    _First = (const __m128i *)_Mid2;
    _Dest = (__m128i *)((char *)v11 + _Mid2 - (unsigned __int8 *)v9);
    _Count -= 2 * _Chunk;
  }
  if ( _Count > i )
  {
    v12 = &_First->m128i_u8[i];
    v13 = (const __m128i *)((char *)_First + i);
    if ( _First != (const __m128i *)&_First->m128i_i8[i] )
    {
      do
      {
        if ( v13 == _Last )
          break;
        if ( v13->m128i_i8[0] >= (unsigned int)_First->m128i_i8[0] )
        {
          _Dest->m128i_i8[0] = _First->m128i_i8[0];
          _First = (const __m128i *)((char *)_First + 1);
        }
        else
        {
          _Dest->m128i_i8[0] = v13->m128i_i8[0];
          v13 = (const __m128i *)((char *)v13 + 1);
        }
        _Dest = (__m128i *)((char *)_Dest + 1);
      }
      while ( _First != (const __m128i *)v12 );
    }
    v14 = v12 - (unsigned __int8 *)_First;
    memmove(dst: _Dest, src: _First, count: v14);
    memmove(dst: (__m128i *)((char *)_Dest + v14), src: v13, count: (char *)_Last - (char *)v13);
  }
  else
  {
    memmove(dst: _Dest, src: _First, count: (char *)_Last - (char *)_First);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101669D0
// Name: class std::_Temp_iterator<unsigned char> std::_Move<unsigned char __near *,class std::_Temp_iterator<unsigned char>>(unsigned char __near *,unsigned char __near *,class std::_Temp_iterator<unsigned char>)
// Source: json
//------------------------------------------------------------------------------
std::_Temp_iterator<unsigned char> *__cdecl std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
        std::_Temp_iterator<unsigned char> *result,
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        std::_Temp_iterator<unsigned char> _Dest)
{
  std::_Temp_iterator<unsigned char> v5; // [esp-18h] [ebp-1Ch] BYREF

  memset(&v5, 0, 16);
  v5._Pbuf = _Dest._Pbuf;
  std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(result, _First, _Last, _Dest: v5);
  if ( _Dest._Buf._Begin != nullptr )
    free(pMem: _Dest._Buf._Begin);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166A30
// Name: class std::_Temp_iterator<unsigned char> std::_Merge<unsigned char __near *,unsigned char __near *,class std::_Temp_iterator<unsigned char>>(unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *,class std::_Temp_iterator<unsigned char>)
// Source: json
//------------------------------------------------------------------------------
std::_Temp_iterator<unsigned char> *__cdecl std::_Merge<unsigned char *,unsigned char *,std::_Temp_iterator<unsigned char>>(
        std::_Temp_iterator<unsigned char> *result,
        unsigned __int8 *_First1,
        unsigned __int8 *_Last1,
        unsigned __int8 *_First2,
        unsigned __int8 *_Last2,
        std::_Temp_iterator<unsigned char> _Dest)
{
  unsigned __int8 *v7; // esi
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  std::_Temp_iterator<unsigned char>::_Bufpar *v10; // ecx
  unsigned __int8 *v11; // eax
  std::_Temp_iterator<unsigned char>::_Bufpar *Pbuf; // edx
  unsigned __int8 *Current; // eax
  std::_Temp_iterator<unsigned char> v15; // [esp-18h] [ebp-38h] BYREF
  std::_Temp_iterator<unsigned char> v16; // [esp+Ch] [ebp-14h] BYREF

  v7 = _First1;
  while ( v7 != _Last1 )
  {
    if ( _First2 == _Last2 )
      break;
    v8 = *v7;
    v9 = *_First2;
    if ( *_First2 >= *v7 )
    {
      Pbuf = _Dest._Pbuf;
      Current = _Dest._Pbuf->_Current;
      if ( Current >= _Dest._Pbuf->_Hiwater )
      {
        if ( Current != nullptr )
        {
          *Current = v8;
          Pbuf = _Dest._Pbuf;
        }
        _Dest._Pbuf->_Hiwater = ++Pbuf->_Current;
      }
      else
      {
        *Current = v8;
        ++_Dest._Pbuf->_Current;
      }
      ++v7;
    }
    else
    {
      v10 = _Dest._Pbuf;
      v11 = _Dest._Pbuf->_Current;
      if ( v11 >= _Dest._Pbuf->_Hiwater )
      {
        if ( v11 != nullptr )
        {
          *v11 = v9;
          v10 = _Dest._Pbuf;
        }
        _Dest._Pbuf->_Hiwater = ++v10->_Current;
        ++_First2;
      }
      else
      {
        *v11 = v9;
        ++_Dest._Pbuf->_Current;
        ++_First2;
      }
    }
  }
  v15._Pbuf = _Dest._Pbuf;
  memset(&v15, 0, 16);
  std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(result: &v16, _First: v7, _Last: _Last1, _Dest: v15);
  _Dest._Pbuf = v16._Pbuf;
  if ( v16._Buf._Begin != nullptr )
    free(pMem: v16._Buf._Begin);
  memset(&v15, 0, 16);
  v15._Pbuf = _Dest._Pbuf;
  std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(result, _First: _First2, _Last: _Last2, _Dest: v15);
  if ( _Dest._Buf._Begin != nullptr )
    free(pMem: _Dest._Buf._Begin);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166C00
// Name: void std::_Chunked_merge<unsigned char __near *,class std::_Temp_iterator<unsigned char>,int>(unsigned char __near *,unsigned char __near *,class std::_Temp_iterator<unsigned char>,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Chunked_merge<unsigned char *,std::_Temp_iterator<unsigned char>,int>(
        unsigned __int8 *_First,
        unsigned __int8 *_Last,
        std::_Temp_iterator<unsigned char> _Dest,
        int _Chunk,
        int _Count)
{
  int i; // ecx
  unsigned __int8 *v7; // esi
  _QWORD v8[3]; // [esp-18h] [ebp-38h] BYREF
  std::_Temp_iterator<unsigned char> result; // [esp+Ch] [ebp-14h] BYREF

  for ( i = _Count; i >= 2 * _Chunk; _Count = i )
  {
    v7 = &_First[_Chunk + _Chunk];
    memset((char *)v8 + 4, 0, 16);
    HIDWORD(v8[2]) = _Dest._Pbuf;
    _Dest._Pbuf = std::_Merge<unsigned char *,unsigned char *,std::_Temp_iterator<unsigned char>>(
                    &result,
                    _First1: _First,
                    _Last1: &_First[_Chunk],
                    _First2: &_First[_Chunk],
                    _Last2: v7,
                    _Dest: *(std::_Temp_iterator<unsigned char> *)((char *)v8 + 4))->_Pbuf;
    if ( result._Buf._Begin != nullptr )
      free(pMem: result._Buf._Begin);
    i = _Count - 2 * _Chunk;
    _First = v7;
  }
  if ( i > _Chunk )
  {
    memset((char *)v8 + 4, 0, 16);
    HIDWORD(v8[2]) = _Dest._Pbuf;
    std::_Merge<unsigned char *,unsigned char *,std::_Temp_iterator<unsigned char>>(
      &result,
      _First1: _First,
      _Last1: &_First[_Chunk],
      _First2: &_First[_Chunk],
      _Last2: _Last,
      _Dest: *(std::_Temp_iterator<unsigned char> *)((char *)v8 + 4));
  }
  else
  {
    LODWORD(v8[2]) = _Dest._Pbuf;
    memset(v8, 0, 16);
    std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
      &result,
      _First,
      _Last,
      _Dest: *(std::_Temp_iterator<unsigned char> *)v8);
  }
  if ( result._Buf._Begin != nullptr )
    free(pMem: result._Buf._Begin);
  if ( _Dest._Buf._Begin != nullptr )
    free(pMem: _Dest._Buf._Begin);
}

//------------------------------------------------------------------------------
// Address: 0x10166D00
// Name: unsigned char __near * std::_Buffered_rotate<unsigned char __near *,int,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char __near *,int,int,class std::_Temp_iterator<unsigned char> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl std::_Buffered_rotate<unsigned char *,int,unsigned char>(
        __m128i *_First,
        __m128i *_Mid,
        __m128i *_Last,
        int _Count1,
        int _Count2,
        std::_Temp_iterator<unsigned char> *_Tempbuf)
{
  std::_Temp_iterator<unsigned char>::_Bufpar *v6; // esi
  const __m128i *v7; // ecx
  unsigned __int8 *v8; // esi
  std::_Temp_iterator<unsigned char>::_Bufpar *Pbuf; // eax
  int Size; // eax
  unsigned __int8 *first; // eax
  int second; // ecx
  std::_Temp_iterator<unsigned char>::_Bufpar *v14; // edx
  std::_Temp_iterator<unsigned char>::_Bufpar *v15; // esi
  const __m128i *Begin; // eax
  unsigned int v17; // esi
  _QWORD v18[3]; // [esp-18h] [ebp-40h] BYREF
  std::_Temp_iterator<unsigned char> v19; // [esp+Ch] [ebp-1Ch] BYREF
  std::pair<unsigned char *,int> v20; // [esp+20h] [ebp-8h] BYREF

  if ( _Count1 > _Count2 || _Count1 > std::_Temp_iterator<unsigned char>::_Maxlen(this: _Tempbuf) )
  {
    Pbuf = _Tempbuf->_Pbuf;
    if ( Pbuf->_Begin == nullptr )
    {
      Size = Pbuf->_Size;
      if ( Size > 0 )
      {
        std::get_temporary_buffer<unsigned char>(result: &v20, _Count: Size);
        first = v20.first;
        _Tempbuf->_Pbuf->_Begin = v20.first;
        _Tempbuf->_Pbuf->_Current = first;
        second = v20.second;
        _Tempbuf->_Pbuf->_Hiwater = first;
        _Tempbuf->_Pbuf->_Size = second;
      }
    }
    v14 = _Tempbuf->_Pbuf;
    if ( _Count2 > v14->_Size )
    {
      if ( _First != _Mid && _Mid != _Last )
        std::_Rotate<unsigned char *,int,unsigned char>(
          (unsigned __int8 *)_First,
          (unsigned __int8 *)_Mid,
          (unsigned __int8 *)_Last);
      return (unsigned __int8 *)_First + _Count2;
    }
    else
    {
      _Tempbuf->_Pbuf->_Current = v14->_Begin;
      LODWORD(v18[2]) = _Tempbuf->_Pbuf;
      memset(v18, 0, 16);
      std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
        result: &v19,
        _First: (unsigned __int8 *)_Mid,
        (unsigned __int8 *)_Last,
        _Dest: *(std::_Temp_iterator<unsigned char> *)v18);
      if ( v19._Buf._Begin != nullptr )
        free(pMem: v19._Buf._Begin);
      memmove(
        dst: (__m128i *)((char *)_Last - ((char *)_Mid - (char *)_First)),
        src: _First,
        count: (char *)_Mid - (char *)_First);
      v15 = _Tempbuf->_Pbuf;
      Begin = (const __m128i *)v15->_Begin;
      v17 = v15->_Current - v15->_Begin;
      memmove(dst: _First, src: Begin, count: v17);
      return (unsigned __int8 *)_First + v17;
    }
  }
  else
  {
    _Tempbuf->_Pbuf->_Current = _Tempbuf->_Pbuf->_Begin;
    memset((char *)v18 + 4, 0, 16);
    HIDWORD(v18[2]) = _Tempbuf->_Pbuf;
    std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
      result: &v19,
      (unsigned __int8 *)_First,
      _Last: (unsigned __int8 *)_Mid,
      _Dest: *(std::_Temp_iterator<unsigned char> *)((char *)v18 + 4));
    if ( v19._Buf._Begin != nullptr )
      free(pMem: v19._Buf._Begin);
    memmove(dst: _First, src: _Mid, count: (char *)_Last - (char *)_Mid);
    v6 = _Tempbuf->_Pbuf;
    v7 = (const __m128i *)v6->_Begin;
    LODWORD(v18[1]) = v6->_Current - v6->_Begin;
    v8 = (unsigned __int8 *)_Last - LODWORD(v18[1]);
    memmove(dst: (__m128i *)((char *)_Last - LODWORD(v18[1])), src: v7, count: v18[1]);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166E80
// Name: public: CSendNode::~CSendNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSendNode::~CSendNode(CSendNode *this)
{
  int i; // edi
  CSendNode *v3; // ebx
  CSendNode **m_pMemory; // eax
  CSendNode **v5; // eax

  for ( i = this->m_Children.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_Children.m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CSendNode::~CSendNode(this: this->m_Children.m_Memory.m_pMemory[i]);
      free(pMem: v3);
    }
  }
  this->m_Children.m_Size = 0;
  if ( this->m_Children.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Children.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Children.m_Memory.m_pMemory);
      this->m_Children.m_Memory.m_pMemory = nullptr;
    }
    this->m_Children.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Children.m_Memory.m_pMemory;
  this->m_Children.m_pElements = this->m_Children.m_Memory.m_pMemory;
  this->m_Children.m_Size = 0;
  if ( this->m_Children.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_Children.m_Memory.m_pMemory = nullptr;
    }
    this->m_Children.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_Children.m_Memory.m_pMemory;
  this->m_Children.m_pElements = this->m_Children.m_Memory.m_pMemory;
  if ( this->m_Children.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      free(pMem: v5);
      this->m_Children.m_Memory.m_pMemory = nullptr;
    }
    this->m_Children.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166F20
// Name: public: CFastLocalTransferInfo::~CFastLocalTransferInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFastLocalTransferInfo::~CFastLocalTransferInfo(CFastLocalTransferInfo *this)
{
  CFastLocalTransferPropInfo *m_pMemory; // eax
  CFastLocalTransferPropInfo *v3; // eax
  CFastLocalTransferPropInfo *v4; // eax
  CFastLocalTransferPropInfo *v5; // eax
  CFastLocalTransferPropInfo *v6; // eax

  this->m_OtherProps.m_Size = 0;
  if ( this->m_OtherProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OtherProps.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_OtherProps.m_Memory.m_pMemory);
      this->m_OtherProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_OtherProps.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_OtherProps.m_Memory.m_pMemory;
  this->m_OtherProps.m_pElements = m_pMemory;
  if ( this->m_OtherProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_OtherProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_OtherProps.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FastVector.m_Size = 0;
  if ( this->m_FastVector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FastVector.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_FastVector.m_Memory.m_pMemory);
      this->m_FastVector.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastVector.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_FastVector.m_Memory.m_pMemory;
  this->m_FastVector.m_pElements = v3;
  if ( this->m_FastVector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3 != nullptr )
    {
      free(pMem: v3);
      this->m_FastVector.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastVector.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FastInt8.m_Size = 0;
  if ( this->m_FastInt8.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FastInt8.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_FastInt8.m_Memory.m_pMemory);
      this->m_FastInt8.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt8.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_FastInt8.m_Memory.m_pMemory;
  this->m_FastInt8.m_pElements = v4;
  if ( this->m_FastInt8.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      free(pMem: v4);
      this->m_FastInt8.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt8.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FastInt16.m_Size = 0;
  if ( this->m_FastInt16.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FastInt16.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_FastInt16.m_Memory.m_pMemory);
      this->m_FastInt16.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt16.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_FastInt16.m_Memory.m_pMemory;
  this->m_FastInt16.m_pElements = v5;
  if ( this->m_FastInt16.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      free(pMem: v5);
      this->m_FastInt16.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt16.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FastInt32.m_Size = 0;
  if ( this->m_FastInt32.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FastInt32.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_FastInt32.m_Memory.m_pMemory);
      this->m_FastInt32.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt32.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_FastInt32.m_Memory.m_pMemory;
  this->m_FastInt32.m_pElements = this->m_FastInt32.m_Memory.m_pMemory;
  if ( this->m_FastInt32.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      free(pMem: v6);
      this->m_FastInt32.m_Memory.m_pMemory = nullptr;
    }
    this->m_FastInt32.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167060
// Name: void SendTable_BuildHierarchy_IterateProps(class CSendNode __near *,class SendTable const __near *,class CBuildHierarchyStruct __near *,class SendProp const __near * __near * const,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_BuildHierarchy_IterateProps(
        CSendNode *pNode,
        const SendTable *pTable,
        CBuildHierarchyStruct *bhs,
        const SendProp **pNonDatatableProps,
        int *nNonDatatableProps)
{
  const SendTable *v5; // edi
  SendProp *v6; // ebx
  CSendNode *v7; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CSendNode **m_pMemory; // ecx
  int v11; // eax
  CSendNode **v12; // edi
  int i; // [esp+4h] [ebp-Ch]
  int v14; // [esp+8h] [ebp-8h]
  CSendNode *pChild; // [esp+Ch] [ebp-4h]

  v5 = pTable;
  i = 0;
  if ( pTable->m_nProps > 0 )
  {
    v14 = 0;
    do
    {
      v6 = &v5->m_pProps[v14];
      if ( (v6->m_Flags & 0x40) == 0
        && (v6->m_Flags & 0x100) == 0
        && FindExcludeProp(
             pTableName: v5->m_pNetTableName,
             pPropName: v6->m_pVarName,
             pExcludeProps: bhs->m_pExcludeProps,
             nExcludeProps: bhs->m_nExcludeProps) == nullptr )
      {
        if ( v6->m_Type == DPT_DataTable )
        {
          if ( (v6->m_Flags & 0x800) != 0 )
          {
            SendTable_BuildHierarchy_IterateProps(
              pNode,
              pTable: v6->m_pDataTable,
              bhs,
              pNonDatatableProps,
              nNonDatatableProps);
          }
          else
          {
            v7 = (CSendNode *)MemAlloc_Alloc(nSize: 0x24u);
            if ( v7 != nullptr )
            {
              v7->m_Children.m_Memory.m_pMemory = nullptr;
              v7->m_Children.m_Memory.m_nAllocationCount = 0;
              v7->m_Children.m_Memory.m_nGrowSize = 0;
              v7->m_Children.m_Size = 0;
              v7->m_Children.m_pElements = nullptr;
              v7->m_pTable = nullptr;
              *(_DWORD *)&v7->m_iFirstRecursiveProp = 0;
              v7->m_iDatatableProp = -1;
              v7->m_DataTableProxyIndex = 254;
              pChild = v7;
            }
            else
            {
              pChild = nullptr;
            }
            if ( bhs->m_nDatatableProps >= 0xFFFu )
              _Error(a1: "Overflowed datatable prop list in SendTable '%s'.", pTable->m_pNetTableName);
            bhs->m_pDatatableProps[bhs->m_nDatatableProps] = v6;
            pChild->m_iDatatableProp = bhs->m_nDatatableProps;
            ++bhs->m_nDatatableProps;
            m_Size = pNode->m_Children.m_Size;
            m_nAllocationCount = pNode->m_Children.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CSendTablePrecalc::CProxyPathEntry,int>::Grow(
                this: (CUtlMemory<SendProp const *,int> *)pNode,
                num: m_Size - m_nAllocationCount + 1);
            ++pNode->m_Children.m_Size;
            m_pMemory = pNode->m_Children.m_Memory.m_pMemory;
            v11 = pNode->m_Children.m_Size - m_Size - 1;
            pNode->m_Children.m_pElements = pNode->m_Children.m_Memory.m_pMemory;
            if ( v11 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
            v12 = &pNode->m_Children.m_Memory.m_pMemory[m_Size];
            if ( v12 != nullptr )
              *v12 = pChild;
            SendTable_BuildHierarchy(pNode: pChild, pTable: v6->m_pDataTable, bhs);
          }
        }
        else
        {
          if ( *nNonDatatableProps >= 4095 )
            _Error(a1: "SendTable_BuildHierarchy: overflowed non-datatable props with '%s'.", v6->m_pVarName);
          pNonDatatableProps[(*nNonDatatableProps)++] = v6;
        }
      }
      v5 = pTable;
      ++v14;
      ++i;
    }
    while ( i < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167300
// Name: void std::_Buffered_merge_sort<unsigned char __near *,int,unsigned char>(unsigned char __near *,unsigned char __near *,int,class std::_Temp_iterator<unsigned char> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Buffered_merge_sort<unsigned char *,int,unsigned char>(
        __m128i *_First,
        __m128i *_Last,
        int _Count,
        std::_Temp_iterator<unsigned char> *_Tempbuf)
{
  __m128i *v4; // eax
  unsigned int v5; // ebx
  __m128i *v6; // esi
  int i; // esi
  int v8; // esi
  std::_Temp_iterator<unsigned char> v9[2]; // [esp-1Ch] [ebp-28h] BYREF

  v4 = _First;
  if ( _Count >= 32 )
  {
    v5 = (unsigned int)_Count >> 5;
    do
    {
      v6 = v4 + 2;
      std::_Insertion_sort1<unsigned char *,unsigned char>(_First: v4, _Last: v4 + 2);
      --v5;
      v4 = v6;
    }
    while ( v5 != 0 );
  }
  std::_Insertion_sort1<unsigned char *,unsigned char>(_First: v4, _Last);
  for ( i = 32; i < _Count; i = 2 * v8 )
  {
    _Tempbuf->_Pbuf->_Current = _Tempbuf->_Pbuf->_Begin;
    memset(v9, 0, 16);
    v9[0]._Pbuf = _Tempbuf->_Pbuf;
    std::_Chunked_merge<unsigned char *,std::_Temp_iterator<unsigned char>,int>(
      (unsigned __int8 *)_First,
      (unsigned __int8 *)_Last,
      _Dest: v9[0],
      _Chunk: i,
      _Count);
    v8 = 2 * i;
    std::_Chunked_merge<unsigned char *,unsigned char *,int>(
      _First: (const __m128i *)_Tempbuf->_Pbuf->_Begin,
      _Last: (const __m128i *)_Tempbuf->_Pbuf->_Current,
      _Dest: _First,
      _Chunk: v8,
      _Count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101673A0
// Name: void std::_Buffered_merge<unsigned char __near *,int,unsigned char>(unsigned char __near *,unsigned char __near *,unsigned char __near *,int,int,class std::_Temp_iterator<unsigned char> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Buffered_merge<unsigned char *,int,unsigned char>(
        __m128i *_First,
        __m128i *_Mid,
        __m128i *_Last,
        int _Count1,
        int _Count2,
        std::_Temp_iterator<unsigned char> *_Tempbuf)
{
  int v7; // edi
  int v8; // edi
  __m128i *v9; // eax
  int v10; // esi
  unsigned __int8 *v11; // eax
  int v12; // ecx
  unsigned __int8 v13; // al
  std::_Temp_iterator<unsigned char> v14; // [esp-14h] [ebp-40h] BYREF
  std::_Temp_iterator<unsigned char> result; // [esp+Ch] [ebp-20h] BYREF
  unsigned __int8 *_Midn; // [esp+20h] [ebp-Ch]
  unsigned __int8 *_Lastn; // [esp+24h] [ebp-8h]
  unsigned __int8 *_Firstn; // [esp+28h] [ebp-4h]

  v7 = _Count2;
  if ( _Count2 + _Count1 == 2 )
  {
LABEL_11:
    v13 = _First->m128i_i8[0];
    if ( _Mid->m128i_i8[0] < (unsigned int)_First->m128i_i8[0] )
    {
      _First->m128i_i8[0] = _Mid->m128i_i8[0];
      _Mid->m128i_i8[0] = v13;
    }
  }
  else
  {
    while ( _Count1 > v7 || _Count1 > std::_Temp_iterator<unsigned char>::_Maxlen(this: _Tempbuf) )
    {
      if ( v7 <= std::_Temp_iterator<unsigned char>::_Maxlen(this: _Tempbuf) )
      {
        _Tempbuf->_Pbuf->_Current = _Tempbuf->_Pbuf->_Begin;
        memset(&v14, 0, 16);
        v14._Pbuf = _Tempbuf->_Pbuf;
        std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
          &result,
          _First: (unsigned __int8 *)_Mid,
          (unsigned __int8 *)_Last,
          _Dest: v14);
        if ( result._Buf._Begin != nullptr )
          free(pMem: result._Buf._Begin);
        std::_Merge_backward<unsigned char *,unsigned char *,unsigned char *>(
          _First1: _First,
          _Last1: _Mid,
          _First2: (const __m128i *)_Tempbuf->_Pbuf->_Begin,
          _Last2: (const __m128i *)_Tempbuf->_Pbuf->_Current,
          _Dest: (unsigned __int8 *)_Last);
        return;
      }
      if ( v7 >= _Count1 )
      {
        v10 = v7 / 2;
        _Lastn = &_Mid->m128i_u8[v7 / 2];
        v11 = std::upper_bound<unsigned char *,unsigned char>(
                (unsigned __int8 *)_First,
                _Last: (unsigned __int8 *)_Mid,
                _Val: _Lastn);
        v8 = v11 - (unsigned __int8 *)_First;
        _Firstn = v11;
        v9 = (__m128i *)_Lastn;
      }
      else
      {
        v8 = _Count1 / 2;
        _Firstn = &_First->m128i_u8[_Count1 / 2];
        v9 = (__m128i *)std::lower_bound<unsigned char *,unsigned char>(
                          _First: (unsigned __int8 *)_Mid,
                          (unsigned __int8 *)_Last,
                          _Val: _Firstn);
        _Lastn = (unsigned __int8 *)v9;
        v10 = (char *)v9 - (char *)_Mid;
      }
      _Count1 -= v8;
      _Midn = std::_Buffered_rotate<unsigned char *,int,unsigned char>(
                _First: (__m128i *)_Firstn,
                _Mid,
                _Last: v9,
                _Count1,
                _Count2: v10,
                _Tempbuf);
      std::_Buffered_merge<unsigned char *,int,unsigned char>(
        (unsigned __int8 *)_First,
        _Mid: _Firstn,
        _Last: _Midn,
        _Count1: v8,
        _Count2: v10,
        _Tempbuf);
      _Mid = (__m128i *)_Lastn;
      v12 = _Count2 - v10 + _Count1;
      _Count2 -= v10;
      _First = (__m128i *)_Midn;
      if ( v12 == 2 )
        goto LABEL_11;
      v7 = _Count2;
    }
    _Tempbuf->_Pbuf->_Current = _Tempbuf->_Pbuf->_Begin;
    memset(&v14, 0, 16);
    v14._Pbuf = _Tempbuf->_Pbuf;
    std::_Move<unsigned char *,std::_Temp_iterator<unsigned char>>(
      &result,
      (unsigned __int8 *)_First,
      _Last: (unsigned __int8 *)_Mid,
      _Dest: v14);
    if ( result._Buf._Begin != nullptr )
      free(pMem: result._Buf._Begin);
    std::_Merge<unsigned char *,unsigned char *,unsigned char *>(
      _First1: (const __m128i *)_Tempbuf->_Pbuf->_Begin,
      _Last1: (const __m128i *)_Tempbuf->_Pbuf->_Current,
      _First2: _Mid,
      _Last2: _Last,
      _Dest: _First);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167580
// Name: void std::_Stable_sort<unsigned char __near *,int,unsigned char>(unsigned char __near *,unsigned char __near *,int,class std::_Temp_iterator<unsigned char> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Stable_sort<unsigned char *,int,unsigned char>(
        __m128i *_First,
        __m128i *_Last,
        int _Count,
        std::_Temp_iterator<unsigned char> *_Tempbuf)
{
  int v4; // esi
  __m128i *v5; // ebx
  int v6; // edi

  if ( _Count > 32 )
  {
    v4 = (_Count + 1) / 2;
    v5 = (__m128i *)((char *)_First + v4);
    if ( v4 > std::_Temp_iterator<unsigned char>::_Maxlen(this: _Tempbuf) )
    {
      std::_Stable_sort<unsigned char *,int,unsigned char>(
        (unsigned __int8 *)_First,
        _Last: (unsigned __int8 *)v5,
        _Count: (_Count + 1) / 2,
        _Tempbuf);
      v6 = _Count - v4;
      std::_Stable_sort<unsigned char *,int,unsigned char>(
        _First: (unsigned __int8 *)v5,
        (unsigned __int8 *)_Last,
        _Count: _Count - v4,
        _Tempbuf);
    }
    else
    {
      std::_Buffered_merge_sort<unsigned char *,int,unsigned char>(
        _First,
        _Last: v5,
        _Count: (_Count + 1) / 2,
        _Tempbuf);
      v6 = _Count - v4;
      std::_Buffered_merge_sort<unsigned char *,int,unsigned char>(_First: v5, _Last, _Count: _Count - v4, _Tempbuf);
    }
    std::_Buffered_merge<unsigned char *,int,unsigned char>(_First, _Mid: v5, _Last, _Count1: v4, _Count2: v6, _Tempbuf);
  }
  else
  {
    std::_Insertion_sort1<unsigned char *,unsigned char>(_First, _Last);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167620
// Name: public: virtual CSendTablePrecalc::~CSendTablePrecalc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSendTablePrecalc::~CSendTablePrecalc(CSendTablePrecalc *this)
{
  SendTable *m_pSendTable; // eax
  const SendProp **m_pMemory; // eax
  unsigned __int8 *v4; // eax
  const SendProp **v5; // eax
  CSendTablePrecalc::CProxyPath *v6; // eax
  CSendTablePrecalc::CProxyPathEntry *v7; // eax

  m_pSendTable = this->m_pSendTable;
  this->__vftable = (CSendTablePrecalc_vtbl *)&CSendTablePrecalc::`vftable';
  if ( m_pSendTable != nullptr )
    m_pSendTable->m_pPrecalc = nullptr;
  CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_PropOffsetToIndexMap.m_Tree);
  this->m_PropOffsetToIndexMap.m_Tree.m_FirstFree = -1;
  if ( this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      free(pMem: this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory);
      this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_PropOffsetToIndexMap.m_Tree.m_LastAlloc.index = -1;
  if ( this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      free(pMem: this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory);
      this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  CFastLocalTransferInfo::~CFastLocalTransferInfo(this: &this->m_FastLocalTransfer);
  CSendNode::~CSendNode(this: &this->m_Root);
  this->m_DatatableProps.m_Size = 0;
  if ( this->m_DatatableProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DatatableProps.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_DatatableProps.m_Memory.m_pMemory);
      this->m_DatatableProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_DatatableProps.m_Memory.m_pMemory;
  this->m_DatatableProps.m_pElements = m_pMemory;
  if ( this->m_DatatableProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_DatatableProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PropProxyIndices.m_Size = 0;
  if ( this->m_PropProxyIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PropProxyIndices.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_PropProxyIndices.m_Memory.m_pMemory);
      this->m_PropProxyIndices.m_Memory.m_pMemory = nullptr;
    }
    this->m_PropProxyIndices.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_PropProxyIndices.m_Memory.m_pMemory;
  this->m_PropProxyIndices.m_pElements = v4;
  if ( this->m_PropProxyIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      free(pMem: v4);
      this->m_PropProxyIndices.m_Memory.m_pMemory = nullptr;
    }
    this->m_PropProxyIndices.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Props.m_Size = 0;
  if ( this->m_Props.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Props.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Props.m_Memory.m_pMemory);
      this->m_Props.m_Memory.m_pMemory = nullptr;
    }
    this->m_Props.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_Props.m_Memory.m_pMemory;
  this->m_Props.m_pElements = v5;
  if ( this->m_Props.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      free(pMem: v5);
      this->m_Props.m_Memory.m_pMemory = nullptr;
    }
    this->m_Props.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ProxyPaths.m_Size = 0;
  if ( this->m_ProxyPaths.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ProxyPaths.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_ProxyPaths.m_Memory.m_pMemory);
      this->m_ProxyPaths.m_Memory.m_pMemory = nullptr;
    }
    this->m_ProxyPaths.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_ProxyPaths.m_Memory.m_pMemory;
  this->m_ProxyPaths.m_pElements = v6;
  if ( this->m_ProxyPaths.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      free(pMem: v6);
      this->m_ProxyPaths.m_Memory.m_pMemory = nullptr;
    }
    this->m_ProxyPaths.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ProxyPathEntries.m_Size = 0;
  if ( this->m_ProxyPathEntries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ProxyPathEntries.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_ProxyPathEntries.m_Memory.m_pMemory);
      this->m_ProxyPathEntries.m_Memory.m_pMemory = nullptr;
    }
    this->m_ProxyPathEntries.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_ProxyPathEntries.m_Memory.m_pMemory;
  this->m_ProxyPathEntries.m_pElements = v7;
  if ( this->m_ProxyPathEntries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      free(pMem: v7);
      this->m_ProxyPathEntries.m_Memory.m_pMemory = nullptr;
    }
    this->m_ProxyPathEntries.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101677F0
// Name: void SendTable_GenerateProxyPaths(class CSendTablePrecalc __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_GenerateProxyPaths(CSendTablePrecalc *pPrecalc, int nProxyIndices)
{
  int v2; // esi
  int i; // eax
  int *m_pMemory; // ecx
  int m_Size; // eax
  CSendNode *p_m_Root; // esi
  int j; // edi
  int v8; // eax
  int v9; // ebx
  int m_nAllocationCount; // ecx
  CSendTablePrecalc::CProxyPathEntry *v11; // ecx
  int v12; // eax
  CSendTablePrecalc::CProxyPath *v13; // eax
  int k; // edi
  int *v15; // eax
  int v16; // [esp-4h] [ebp-28h]
  CUtlVector<int,CUtlMemory<int,int> > pathLengths; // [esp+Ch] [ebp-18h] BYREF
  int iCurEntry; // [esp+20h] [ebp-4h] BYREF

  v2 = nProxyIndices;
  v16 = nProxyIndices;
  pPrecalc->m_ProxyPaths.m_Size = 0;
  CUtlVector<SendProp const *,CUtlMemory<SendProp const *,int>>::InsertMultipleBefore(
    this: (CUtlVector<SendProp const *,CUtlMemory<SendProp const *,int> > *)&pPrecalc->m_ProxyPaths,
    elem: 0,
    num: v16);
  for ( i = 0; i < v2; ++i )
  {
    pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[i].m_nEntries = -1;
    pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[i].m_iFirstEntry = -1;
  }
  m_pMemory = nullptr;
  m_Size = 0;
  nProxyIndices = 0;
  memset(&pathLengths, 0, sizeof(pathLengths));
  if ( v2 != 0 )
  {
    if ( v2 > 0 )
    {
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&pathLengths, num: v2);
      m_Size = pathLengths.m_Size;
      m_pMemory = pathLengths.m_Memory.m_pMemory;
    }
    pathLengths.m_Size = v2 + m_Size;
    pathLengths.m_pElements = m_pMemory;
    if ( m_Size > 0 && v2 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v2], src: m_pMemory, count: 4 * m_Size);
      m_pMemory = pathLengths.m_Memory.m_pMemory;
    }
  }
  memset(dst: (unsigned __int8 *)m_pMemory, value: 0, count: 4 * v2);
  p_m_Root = &pPrecalc->m_Root;
  pathLengths.m_Memory.m_pMemory[pPrecalc->m_Root.m_RecursiveProxyIndex] = 0;
  for ( j = 0; j < pPrecalc->m_Root.m_Children.m_Size; ++j )
    CalcPathLengths_R(
      pNode: p_m_Root->m_Children.m_Memory.m_pMemory[j],
      &pathLengths,
      curPathLength: 1,
      totalPathLengths: &nProxyIndices);
  v8 = nProxyIndices;
  iCurEntry = 0;
  v9 = nProxyIndices;
  pPrecalc->m_ProxyPathEntries.m_Size = 0;
  if ( v9 != 0 )
  {
    m_nAllocationCount = pPrecalc->m_ProxyPathEntries.m_Memory.m_nAllocationCount;
    if ( v8 > m_nAllocationCount )
      CUtlMemory<CSendTablePrecalc::CProxyPathEntry,int>::Grow(
        this: (CUtlMemory<SendProp const *,int> *)&pPrecalc->m_ProxyPathEntries,
        num: v8 - m_nAllocationCount);
    pPrecalc->m_ProxyPathEntries.m_Size += v9;
    v11 = pPrecalc->m_ProxyPathEntries.m_Memory.m_pMemory;
    v12 = pPrecalc->m_ProxyPathEntries.m_Size - v9;
    pPrecalc->m_ProxyPathEntries.m_pElements = v11;
    if ( v12 > 0 && v9 > 0 )
      _V_memmove(dest: &v11[v9], src: v11, count: 4 * v12);
  }
  v13 = &pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[pPrecalc->m_Root.m_RecursiveProxyIndex];
  v13->m_iFirstEntry = iCurEntry;
  v13->m_nEntries = 0;
  for ( k = 0; k < pPrecalc->m_Root.m_Children.m_Size; ++k )
    FillPathEntries_R(pPrecalc, pNode: p_m_Root->m_Children.m_Memory.m_pMemory[k], pParent: p_m_Root, &iCurEntry);
  v15 = pathLengths.m_Memory.m_pMemory;
  pathLengths.m_Size = 0;
  if ( pathLengths.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pathLengths.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: pathLengths.m_Memory.m_pMemory);
      v15 = nullptr;
      pathLengths.m_Memory.m_pMemory = nullptr;
    }
    pathLengths.m_Memory.m_nAllocationCount = 0;
  }
  pathLengths.m_pElements = v15;
  if ( pathLengths.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
    free(pMem: v15);
}

//------------------------------------------------------------------------------
// Address: 0x101679B0
// Name: public: CSendTablePrecalc::CSendTablePrecalc(void)
// Source: json
//------------------------------------------------------------------------------
CSendTablePrecalc *__thiscall CSendTablePrecalc::CSendTablePrecalc(CSendTablePrecalc *this)
{
  this->__vftable = (CSendTablePrecalc_vtbl *)&CSendTablePrecalc::`vftable';
  this->m_ProxyPathEntries.m_Memory.m_pMemory = nullptr;
  this->m_ProxyPathEntries.m_Memory.m_nAllocationCount = 0;
  this->m_ProxyPathEntries.m_Memory.m_nGrowSize = 0;
  this->m_ProxyPathEntries.m_Size = 0;
  this->m_ProxyPathEntries.m_pElements = nullptr;
  this->m_ProxyPaths.m_Memory.m_pMemory = nullptr;
  this->m_ProxyPaths.m_Memory.m_nAllocationCount = 0;
  this->m_ProxyPaths.m_Memory.m_nGrowSize = 0;
  this->m_ProxyPaths.m_Size = 0;
  this->m_ProxyPaths.m_pElements = nullptr;
  this->m_Props.m_Memory.m_pMemory = nullptr;
  this->m_Props.m_Memory.m_nAllocationCount = 0;
  this->m_Props.m_Memory.m_nGrowSize = 0;
  this->m_Props.m_Size = 0;
  this->m_Props.m_pElements = nullptr;
  this->m_PropProxyIndices.m_Memory.m_pMemory = nullptr;
  this->m_PropProxyIndices.m_Memory.m_nAllocationCount = 0;
  this->m_PropProxyIndices.m_Memory.m_nGrowSize = 0;
  this->m_PropProxyIndices.m_Size = 0;
  this->m_PropProxyIndices.m_pElements = nullptr;
  this->m_DatatableProps.m_Memory.m_pMemory = nullptr;
  this->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
  this->m_DatatableProps.m_Memory.m_nGrowSize = 0;
  this->m_DatatableProps.m_Size = 0;
  this->m_DatatableProps.m_pElements = nullptr;
  this->m_Root.m_Children.m_Memory.m_pMemory = nullptr;
  this->m_Root.m_Children.m_Memory.m_nAllocationCount = 0;
  this->m_Root.m_Children.m_Memory.m_nGrowSize = 0;
  this->m_Root.m_Children.m_Size = 0;
  this->m_Root.m_Children.m_pElements = nullptr;
  this->m_Root.m_pTable = nullptr;
  this->m_Root.m_iDatatableProp = -1;
  this->m_Root.m_nRecursiveProps = 0;
  this->m_Root.m_iFirstRecursiveProp = 0;
  this->m_Root.m_DataTableProxyIndex = 254;
  this->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory = nullptr;
  this->m_FastLocalTransfer.m_FastInt32.m_Memory.m_nAllocationCount = 0;
  this->m_FastLocalTransfer.m_FastInt32.m_Memory.m_nGrowSize = 0;
  this->m_FastLocalTransfer.m_FastInt32.m_Size = 0;
  this->m_FastLocalTransfer.m_FastInt32.m_pElements = nullptr;
  this->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory = nullptr;
  this->m_FastLocalTransfer.m_FastInt16.m_Memory.m_nAllocationCount = 0;
  this->m_FastLocalTransfer.m_FastInt16.m_Memory.m_nGrowSize = 0;
  this->m_FastLocalTransfer.m_FastInt16.m_Size = 0;
  this->m_FastLocalTransfer.m_FastInt16.m_pElements = nullptr;
  this->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory = nullptr;
  this->m_FastLocalTransfer.m_FastInt8.m_Memory.m_nAllocationCount = 0;
  this->m_FastLocalTransfer.m_FastInt8.m_Memory.m_nGrowSize = 0;
  this->m_FastLocalTransfer.m_FastInt8.m_Size = 0;
  this->m_FastLocalTransfer.m_FastInt8.m_pElements = nullptr;
  this->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory = nullptr;
  this->m_FastLocalTransfer.m_FastVector.m_Memory.m_nAllocationCount = 0;
  this->m_FastLocalTransfer.m_FastVector.m_Memory.m_nGrowSize = 0;
  this->m_FastLocalTransfer.m_FastVector.m_Size = 0;
  this->m_FastLocalTransfer.m_FastVector.m_pElements = nullptr;
  this->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory = nullptr;
  this->m_FastLocalTransfer.m_OtherProps.m_Memory.m_nAllocationCount = 0;
  this->m_FastLocalTransfer.m_OtherProps.m_Memory.m_nGrowSize = 0;
  this->m_FastLocalTransfer.m_OtherProps.m_Size = 0;
  this->m_FastLocalTransfer.m_OtherProps.m_pElements = nullptr;
  this->m_PropOffsetToIndexMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned __int16 *, const unsigned __int16 *))CDefOps<unsigned short>::LessFunc;
  this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PropOffsetToIndexMap.m_Tree.m_Root = -1;
  this->m_PropOffsetToIndexMap.m_Tree.m_NumElements = 0;
  this->m_PropOffsetToIndexMap.m_Tree.m_FirstFree = -1;
  this->m_PropOffsetToIndexMap.m_Tree.m_LastAlloc.index = -1;
  this->m_PropOffsetToIndexMap.m_Tree.m_pElements = this->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory;
  this->m_pDTITable = nullptr;
  this->m_pSendTable = nullptr;
  this->m_nDataTableProxies = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10167B70
// Name: void SendTable_SortByPriority(class CBuildHierarchyStruct __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_SortByPriority(CBuildHierarchyStruct *bhs)
{
  __m128i *m_pMemory; // edi
  int m_Size; // ebx
  int v3; // eax
  char v5; // dl
  int v6; // eax
  const SendProp **v7; // ecx
  char *v8; // ecx
  int v9; // edi
  int v10; // eax
  int v11; // eax
  const SendProp **v12; // edi
  const SendProp *v13; // ecx
  unsigned __int8 v14; // dl
  int v15; // edi
  unsigned __int8 v16; // bl
  const SendProp **v17; // edi
  std::_Temp_iterator<unsigned char> _Tempbuf; // [esp+Ch] [ebp-34h] BYREF
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > priorities; // [esp+20h] [ebp-20h] BYREF
  int priorityIndex; // [esp+34h] [ebp-Ch]
  int start; // [esp+38h] [ebp-8h]
  const SendProp **v22; // [esp+3Ch] [ebp-4h]
  char priority_3; // [esp+4Bh] [ebp+Bh]
  unsigned __int8 priority_3a; // [esp+4Bh] [ebp+Bh]

  memset(&priorities, 0, sizeof(priorities));
  CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)&priorities, num: 1);
  m_pMemory = (__m128i *)priorities.m_Memory.m_pMemory;
  m_Size = priorities.m_Size + 1;
  v3 = priorities.m_Size++;
  priorities.m_pElements = priorities.m_Memory.m_pMemory;
  if ( v3 > 0 )
    _V_memmove(dest: priorities.m_Memory.m_pMemory + 1, src: priorities.m_Memory.m_pMemory, count: v3);
  if ( m_pMemory != nullptr )
    m_pMemory->m128i_i8[0] = 64;
  priorityIndex = 0;
  if ( bhs->m_nProps > 0 )
  {
    start = (int)bhs->m_pProps;
    do
    {
      v5 = *(_BYTE *)(*(_DWORD *)start + 56);
      v6 = 0;
      priority_3 = v5;
      if ( m_Size <= 0 )
        goto LABEL_12;
      while ( m_pMemory->m128i_i8[v6] != v5 )
      {
        if ( ++v6 >= m_Size )
          goto LABEL_12;
      }
      if ( v6 < 0 )
      {
LABEL_12:
        v7 = (const SendProp **)m_Size;
        v22 = (const SendProp **)m_Size;
        if ( m_Size + 1 > priorities.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<bool,int>::Grow(
            this: (CUtlMemory<char,int> *)&priorities,
            num: m_Size - priorities.m_Memory.m_nAllocationCount + 1);
          m_Size = priorities.m_Size;
          m_pMemory = (__m128i *)priorities.m_Memory.m_pMemory;
          v5 = priority_3;
          v7 = v22;
        }
        priorities.m_Size = ++m_Size;
        priorities.m_pElements = (unsigned __int8 *)m_pMemory;
        if ( m_Size - (int)v7 - 1 > 0 )
        {
          _V_memmove(
            dest: (char *)v7 + (_DWORD)m_pMemory + 1,
            src: (char *)v7 + (_DWORD)m_pMemory,
            count: m_Size - (_DWORD)v7 - 1);
          v5 = priority_3;
          v7 = v22;
        }
        v8 = (char *)v7 + (_DWORD)m_pMemory;
        if ( v8 != nullptr )
          *v8 = v5;
      }
      start += 4;
      ++priorityIndex;
    }
    while ( priorityIndex < bhs->m_nProps );
  }
  if ( m_pMemory != (__m128i *)&m_pMemory->m128i_i8[m_Size] )
  {
    memset(&_Tempbuf, 0, 12);
    _Tempbuf._Buf._Size = (m_Size + 1) / 2;
    _Tempbuf._Pbuf = (std::_Temp_iterator<unsigned char>::_Bufpar *)&_Tempbuf;
    std::_Stable_sort<unsigned char *,int,unsigned char>(
      _First: m_pMemory,
      _Last: (__m128i *)((char *)m_pMemory + m_Size),
      _Count: m_Size,
      &_Tempbuf);
    if ( _Tempbuf._Buf._Begin != nullptr )
      free(pMem: _Tempbuf._Buf._Begin);
  }
  v9 = 0;
  v10 = 0;
  start = 0;
  for ( priorityIndex = 0; v10 < m_Size; priorityIndex = v10 )
  {
    priority_3a = priorities.m_Memory.m_pMemory[v10];
    v22 = &bhs->m_pProps[v9];
    do
    {
      v11 = v9;
      if ( v9 < bhs->m_nProps )
      {
        v12 = v22;
        while ( 1 )
        {
          v13 = *v12;
          v14 = bhs->m_PropProxyIndices[v11];
          if ( (*v12)->m_priority == priority_3a || (v13->m_Flags & 0x40000) != 0 && priority_3a == 64 )
            break;
          ++v11;
          ++v12;
          if ( v11 >= bhs->m_nProps )
          {
            v9 = start;
            goto LABEL_34;
          }
        }
        v15 = start;
        if ( v11 != start )
        {
          bhs->m_pProps[v11] = *v22;
          v16 = bhs->m_PropProxyIndices[v15];
          v17 = v22;
          bhs->m_PropProxyIndices[v11] = v16;
          *v17 = v13;
          v15 = start;
          bhs->m_PropProxyIndices[start] = v14;
        }
        v9 = v15 + 1;
        ++v22;
        start = v9;
LABEL_34:
        m_Size = priorities.m_Size;
      }
    }
    while ( v11 != bhs->m_nProps );
    v10 = priorityIndex + 1;
  }
  if ( priorities.m_Memory.m_nGrowSize >= 0 && priorities.m_Memory.m_pMemory != nullptr )
    free(pMem: priorities.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10167D80
// Name: public: bool CSendTablePrecalc::SetupFlatPropertyArray(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSendTablePrecalc::SetupFlatPropertyArray(CSendTablePrecalc *this)
{
  SendTable *v2; // edi
  char result; // al
  int m_nProps; // ebx
  int i; // eax
  int m_nDatatableProps; // ebx
  int j; // eax
  int v8; // [esp-4h] [ebp-A028h]
  int v9; // [esp-4h] [ebp-A028h]
  CBuildHierarchyStruct bhs; // [esp+Ch] [ebp-A018h] BYREF
  ExcludeProp pExcludeProps; // [esp+9018h] [ebp-100Ch] BYREF
  SendTable *pBaseTable; // [esp+A018h] [ebp-Ch]
  int iCurProxyIndex; // [esp+A01Ch] [ebp-8h] BYREF
  int nExcludeProps; // [esp+A020h] [ebp-4h] BYREF

  pBaseTable = this->m_pSendTable;
  v2 = pBaseTable;
  SetupArrayProps_R<SendTable,SendProp>(pTable: pBaseTable);
  nExcludeProps = 0;
  result = SendTable_GetPropsExcluded(pTable: pBaseTable, &pExcludeProps, &nExcludeProps, nMaxExcludeProps: 512);
  if ( result != 0 )
  {
    bhs.m_nExcludeProps = nExcludeProps;
    bhs.m_pExcludeProps = &pExcludeProps;
    bhs.m_nDatatableProps = 0;
    bhs.m_nProps = 0;
    bhs.m_nPropProxies = 0;
    SendTable_BuildHierarchy(pNode: &this->m_Root, pTable: v2, &bhs);
    SendTable_SortByPriority(&bhs);
    m_nProps = bhs.m_nProps;
    v8 = bhs.m_nProps;
    this->m_Props.m_Size = 0;
    CUtlVector<SendProp const *,CUtlMemory<SendProp const *,int>>::InsertMultipleBefore(
      this: &this->m_Props,
      elem: 0,
      num: v8);
    for ( i = 0; i < m_nProps; ++i )
      this->m_Props.m_Memory.m_pMemory[i] = bhs.m_pProps[i];
    m_nDatatableProps = bhs.m_nDatatableProps;
    v9 = bhs.m_nDatatableProps;
    this->m_DatatableProps.m_Size = 0;
    CUtlVector<SendProp const *,CUtlMemory<SendProp const *,int>>::InsertMultipleBefore(
      this: &this->m_DatatableProps,
      elem: 0,
      num: v9);
    for ( j = 0; j < m_nDatatableProps; ++j )
      this->m_DatatableProps.m_Memory.m_pMemory[j] = bhs.m_pDatatableProps[j];
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
      this: &this->m_PropProxyIndices,
      pArray: bhs.m_PropProxyIndices,
      size: bhs.m_nProps);
    this->m_nDataTableProxies = 0;
    SetDataTableProxyIndices_R(pMainTable: this, pCurTable: &this->m_Root, &bhs);
    iCurProxyIndex = 0;
    SetRecursiveProxyIndices_R(pBaseTable, pCurTable: &this->m_Root, &iCurProxyIndex);
    SendTable_GenerateProxyPaths(pPrecalc: this, nProxyIndices: iCurProxyIndex);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10319CD0
// Name: _dynamic_initializer_for__dt_UsePartialChangeEnts__
// Source: semantic_dyn_pfx_dt
//------------------------------------------------------------------------------
int dynamic_initializer_for__dt_UsePartialChangeEnts__()
{
  ConVar::ConVar(
    this: &dt_UsePartialChangeEnts,
    pName: "dt_UsePartialChangeEnts",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "(SP only) - enable FL_EDICT_PARTIAL_CHANGE optimization.");
  return atexit(func: dynamic_atexit_destructor_for__dt_UsePartialChangeEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x10319D00
// Name: _dynamic_initializer_for__dt_ShowPartialChangeEnts__
// Source: semantic_dyn_pfx_dt
//------------------------------------------------------------------------------
int dynamic_initializer_for__dt_ShowPartialChangeEnts__()
{
  ConVar::ConVar(
    this: &dt_ShowPartialChangeEnts,
    pName: "dt_ShowPartialChangeEnts",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "(SP only) - show entities that were copied using small optimized lists (FL_EDICT_PARTIAL_CHANGE).");
  return atexit(func: dynamic_atexit_destructor_for__dt_ShowPartialChangeEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x103251C0
// Name: _dynamic_atexit_destructor_for__dt_UsePartialChangeEnts__
// Source: semantic_dyn_pfx_dt
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dt_UsePartialChangeEnts__()
{
  ConVar::~ConVar(this: &dt_UsePartialChangeEnts);
}

//------------------------------------------------------------------------------
// Address: 0x103251D0
// Name: _dynamic_atexit_destructor_for__dt_ShowPartialChangeEnts__
// Source: semantic_dyn_pfx_dt
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dt_ShowPartialChangeEnts__()
{
  ConVar::~ConVar(this: &dt_ShowPartialChangeEnts);
}

//------------------------------------------------------------------------------
// Address: 0x10319D30
// Name: _dynamic_initializer_for__g_PartialChangeEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PartialChangeEnts__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PartialChangeEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x10319D40
// Name: _dynamic_initializer_for__g_RecvTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RecvTables__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_RecvTables__);
}

//------------------------------------------------------------------------------
// Address: 0x10319D50
// Name: _dynamic_initializer_for__g_RecvDecoders__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RecvDecoders__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_RecvDecoders__);
}

//------------------------------------------------------------------------------
// Address: 0x10319D60
// Name: _dynamic_initializer_for__g_ClientSendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ClientSendTables__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ClientSendTables__);
}

//------------------------------------------------------------------------------
// Address: 0x10319D70
// Name: _dynamic_initializer_for__g_SendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SendTables__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SendTables__);
}

//------------------------------------------------------------------------------
// Address: 0x10319D80
// Name: _dynamic_initializer_for____g_CreateCEngineTraceServerIEngineTrace_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineTraceServerIEngineTrace_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineTraceServerIEngineTrace_reg,
           fn: _CreateCEngineTraceServerIEngineTrace_interface,
           pName: "EngineTraceServer004");
}

//------------------------------------------------------------------------------
// Address: 0x10319DA0
// Name: _dynamic_initializer_for____g_CreateCEngineTraceClientIEngineTrace_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineTraceClientIEngineTrace_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineTraceClientIEngineTrace_reg,
           fn: _CreateCEngineTraceClientIEngineTrace_interface,
           pName: "EngineTraceClient004");
}

//------------------------------------------------------------------------------
// Address: 0x103251E0
// Name: _dynamic_atexit_destructor_for__g_PartialChangeEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PartialChangeEnts__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_PartialChangeEnts);
}

//------------------------------------------------------------------------------
// Address: 0x10325210
// Name: _dynamic_atexit_destructor_for__g_RecvTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RecvTables__()
{
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvTables);
  if ( g_RecvTables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_RecvTables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RecvTables.m_Memory.m_pMemory);
      g_RecvTables.m_Memory.m_pMemory = nullptr;
    }
    g_RecvTables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10325260
// Name: _dynamic_atexit_destructor_for__g_RecvDecoders__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RecvDecoders__()
{
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvDecoders);
  if ( g_RecvDecoders.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_RecvDecoders.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RecvDecoders.m_Memory.m_pMemory);
      g_RecvDecoders.m_Memory.m_pMemory = nullptr;
    }
    g_RecvDecoders.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103252B0
// Name: _dynamic_atexit_destructor_for__g_ClientSendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ClientSendTables__()
{
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_ClientSendTables);
  if ( g_ClientSendTables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ClientSendTables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ClientSendTables.m_Memory.m_pMemory);
      g_ClientSendTables.m_Memory.m_pMemory = nullptr;
    }
    g_ClientSendTables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10325300
// Name: _dynamic_atexit_destructor_for__g_SendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SendTables__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_SendTables);
}

} // namespace engine_xlsp
