// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/ragdoll.cpp
// Functions: 182
// ============================================================

#include "game\client\ragdoll.h"

//------------------------------------------------------------------------------
// Address: 0x100193E0
// Name: public: struct CInterpolatedVarEntryBase<class Vector,0> __near & CSimpleRingBuffer<struct CInterpolatedVarEntryBase<class Vector,0>>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
CInterpolatedVarEntryBase<Vector,0> *__thiscall CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0>>::operator[](
        CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0> > *this,
        int i)
{
  int v2; // eax
  int m_maxElement; // edx

  v2 = this->m_firstElement + i;
  m_maxElement = this->m_maxElement;
  if ( v2 >= m_maxElement )
    v2 -= m_maxElement;
  return &this->m_pElements[v2];
}

//------------------------------------------------------------------------------
// Address: 0x100272C0
// Name: public: void CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::SetMaxCount(float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::SetMaxCount(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        float flCurrentTime,
        int newmax)
{
  unsigned __int8 v3; // al
  bool v5; // cl
  unsigned __int8 *v6; // eax
  int m_nMaxCount; // edi
  CRangeCheckedVar<float,-2,2,0> *v8; // edx
  unsigned __int8 *m_bLooping; // ecx
  unsigned int v10; // [esp+0h] [ebp-Ch]

  v3 = newmax;
  v5 = newmax != this->m_nMaxCount;
  if ( newmax < 1 )
    v3 = 1;
  this->m_nMaxCount = v3;
  if ( v5 )
  {
    C_BaseEntity::operator delete(pMem: this->m_bLooping);
    C_BaseEntity::operator delete(pMem: this->m_LastNetworkedValue);
    v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: this->m_nMaxCount);
    m_nMaxCount = this->m_nMaxCount;
    this->m_bLooping = v6;
    v8 = (CRangeCheckedVar<float,-2,2,0> *)MemAlloc_Alloc(nSize: 4 * m_nMaxCount);
    if ( v8 != nullptr )
    {
      if ( m_nMaxCount - 1 >= 0 )
        memset(v8, 0, 4 * m_nMaxCount);
    }
    else
    {
      v8 = nullptr;
    }
    m_bLooping = this->m_bLooping;
    v10 = this->m_nMaxCount;
    this->m_LastNetworkedValue = v8;
    memset(dst: (int)m_bLooping, value: nullptr, count: v10);
    memset(dst: (int)this->m_LastNetworkedValue, value: nullptr, count: 4 * this->m_nMaxCount);
    ((void (__thiscall *)(CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *, _DWORD))this->Reset)(
      a1: this,
      a2: LODWORD(flCurrentTime));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100274D0
// Name: public: struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near & CSimpleRingBuffer<struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0>>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *__thiscall CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0>>::operator[](
        CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> > *this,
        int i)
{
  int v2; // eax
  int m_maxElement; // edx

  v2 = this->m_firstElement + i;
  m_maxElement = this->m_maxElement;
  if ( v2 >= m_maxElement )
    v2 -= m_maxElement;
  return &this->m_pElements[v2];
}

//------------------------------------------------------------------------------
// Address: 0x100274F0
// Name: public: void CSimpleRingBuffer<struct CInterpolatedVarEntryBase<class QAngle,1>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
        CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *this,
        CInterpolatedVarEntryBase<float,1> *capSize)
{
  CInterpolatedVarEntryBase<float,1> *m_maxElement; // ebx
  unsigned int v4; // edi
  int v5; // ecx
  unsigned int *v6; // eax
  int v7; // edx
  int v8; // ecx
  CInterpolatedVarEntryBase<float,1> *v9; // ebx
  _DWORD *i; // eax
  int *p_count; // ecx
  int v12; // ebx
  int v13; // eax
  CInterpolatedVarEntryBase<float,1> *v14; // eax
  CInterpolatedVarEntryBase<float,1> *m_pElements; // eax
  float *value; // ebx
  float **p_value; // ecx
  int v18; // edx
  int v19; // ebx
  CInterpolatedVarEntryBase<float,1> *v20; // eax
  float **v21; // edi
  void *v22; // eax
  float **v23; // [esp+8h] [ebp-4h]
  CInterpolatedVarEntryBase<float,1> *pNew; // [esp+14h] [ebp+8h]

  m_maxElement = (CInterpolatedVarEntryBase<float,1> *)this->m_maxElement;
  if ( (int)capSize > (int)m_maxElement )
  {
    v4 = (unsigned int)m_maxElement + this->m_growSize * (((int)capSize + this->m_growSize - 1) / this->m_growSize);
    v5 = (12 * (unsigned __int64)v4) >> 32 != 0 ? -1 : 12 * v4;
    v6 = (unsigned int *)MemAlloc_Alloc(nSize: __CFADD__(v5, 4) ? -1 : v5 + 4);
    v7 = 0;
    if ( v6 != nullptr )
    {
      v8 = v4 - 1;
      v9 = (CInterpolatedVarEntryBase<float,1> *)(v6 + 1);
      *v6 = v4;
      for ( i = v6 + 1; v8 >= 0; --v8 )
      {
        i[2] = 0;
        i[1] = 0;
        *i = 0;
        i += 3;
      }
      pNew = v9;
    }
    else
    {
      pNew = nullptr;
    }
    if ( this->m_maxElement != 0 )
    {
      p_count = &pNew->count;
      do
      {
        v12 = this->m_maxElement;
        v13 = v7 + this->m_firstElement;
        if ( v13 >= v12 )
          v13 -= v12;
        v14 = &this->m_pElements[v13];
        p_count[1] = (int)v14->value;
        *p_count = v14->count;
        *(p_count - 1) = SLODWORD(v14->flChangeTime);
        v14->value = nullptr;
        v14->count = 0;
        ++v7;
        p_count += 3;
      }
      while ( v7 < this->m_maxElement );
    }
    m_pElements = this->m_pElements;
    this->m_firstElement = 0;
    this->m_maxElement = v4;
    if ( m_pElements != nullptr )
    {
      value = m_pElements[-1].value;
      p_value = &m_pElements[-1].value;
      v18 = (int)value;
      v19 = (int)value - 1;
      v23 = &m_pElements[-1].value;
      v20 = &m_pElements[v18];
      if ( v19 >= 0 )
      {
        v21 = &v20->value;
        do
        {
          v22 = *(v21 - 3);
          v21 -= 3;
          C_BaseEntity::operator delete(pMem: v22);
          --v19;
          *v21 = nullptr;
        }
        while ( v19 >= 0 );
        p_value = v23;
      }
      C_BaseEntity::operator delete(pMem: p_value);
    }
    this->m_pElements = pNew;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027630
// Name: public: void CSimpleRingBuffer<struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0>>::EnsureCapacity(
        CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> > *this,
        int capSize)
{
  int m_maxElement; // ebx
  int v4; // edi
  int v5; // ecx
  int *v6; // eax
  int v7; // ecx
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *v8; // edx
  _DWORD *v9; // eax
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *v10; // ebx
  int v11; // ecx
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *v12; // edx
  int v13; // eax
  int v14; // ecx
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *m_pElements; // ecx
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *v16; // eax
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *pNew; // [esp+8h] [ebp-4h]
  int i; // [esp+14h] [ebp+8h]

  m_maxElement = this->m_maxElement;
  if ( capSize > m_maxElement )
  {
    v4 = m_maxElement + this->m_growSize * ((this->m_growSize + capSize - 1) / this->m_growSize);
    v5 = (unsigned __int64)(unsigned int)v4 >> 29 != 0 ? -1 : 8 * v4;
    v6 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v5, 4) ? -1 : v5 + 4);
    if ( v6 != nullptr )
    {
      v7 = v4 - 1;
      *v6 = v4;
      v8 = (CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *)(v6 + 1);
      if ( v4 - 1 >= 0 )
      {
        v9 = v6 + 2;
        do
        {
          *v9 = 0;
          v9 += 2;
          --v7;
        }
        while ( v7 >= 0 );
      }
      v10 = v8;
      pNew = v8;
    }
    else
    {
      v10 = nullptr;
      pNew = nullptr;
    }
    v11 = 0;
    i = 0;
    if ( this->m_maxElement != 0 )
    {
      v12 = v10;
      do
      {
        v13 = v11 + this->m_firstElement;
        v14 = this->m_maxElement;
        if ( v13 >= v14 )
          v13 -= v14;
        m_pElements = this->m_pElements;
        v12->flChangeTime = this->m_pElements[v13].flChangeTime;
        v12->value.m_Val = m_pElements[v13].value.m_Val;
        v11 = i + 1;
        ++v12;
        i = v11;
      }
      while ( v11 < this->m_maxElement );
      v10 = pNew;
    }
    v16 = this->m_pElements;
    this->m_maxElement = v4;
    this->m_firstElement = 0;
    if ( v16 != nullptr )
      C_BaseEntity::operator delete(pMem: &v16[-1].value);
    this->m_pElements = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A480
// Name: public: CSimpleRingBuffer<struct CInterpolatedVarEntryBase<class Vector,1>>::~CSimpleRingBuffer<struct CInterpolatedVarEntryBase<class Vector,1>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>::~CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>(
        CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *this)
{
  CInterpolatedVarEntryBase<float,1> *m_pElements; // eax
  float **p_value; // ebx
  float *value; // edi
  int v4; // ecx
  int v5; // edi
  CInterpolatedVarEntryBase<float,1> *v6; // eax
  float **v7; // esi
  void *v8; // edx

  m_pElements = this->m_pElements;
  if ( this->m_pElements != nullptr )
  {
    p_value = &m_pElements[-1].value;
    value = m_pElements[-1].value;
    v4 = (int)value;
    v5 = (int)value - 1;
    v6 = &m_pElements[v4];
    if ( v5 >= 0 )
    {
      v7 = &v6->value;
      do
      {
        v8 = *(v7 - 3);
        v7 -= 3;
        C_BaseEntity::operator delete(pMem: v8);
        --v5;
        *v7 = nullptr;
      }
      while ( v5 >= 0 );
    }
    C_BaseEntity::operator delete(pMem: p_value);
    this->m_pElements = nullptr;
  }
  else
  {
    this->m_pElements = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CC80
// Name: protected: void CInterpolatedVarArrayBase<class QAngle,1>::RemoveEntriesPreviousTo(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,1>::RemoveEntriesPreviousTo(
        CInterpolatedVarArrayBase<float,1> *this,
        float flTime)
{
  int v2; // edx
  int m_maxElement; // edi
  int i; // esi
  int v5; // eax

  v2 = 0;
  if ( this->m_VarHistory.m_count != 0 )
  {
    m_maxElement = this->m_VarHistory.m_maxElement;
    for ( i = this->m_VarHistory.m_firstElement - m_maxElement; ; ++i )
    {
      v5 = v2 + this->m_VarHistory.m_firstElement;
      if ( v5 >= m_maxElement )
        v5 = i;
      if ( flTime > this->m_VarHistory.m_pElements[v5].flChangeTime )
        break;
      if ( ++v2 >= this->m_VarHistory.m_count )
        return;
    }
    if ( v2 + 3 < this->m_VarHistory.m_count )
      this->m_VarHistory.m_count = v2 + 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D620
// Name: public: virtual void CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::NoteLastNetworkedValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::NoteLastNetworkedValue(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this)
{
  memcpy(
    dst: (unsigned __int8 *)this->m_LastNetworkedValue,
    src: (unsigned __int8 *)this->m_pValue,
    count: 4 * this->m_nMaxCount);
  this->m_LastNetworkedTime = g_flLastPacketTimestamp;
}

//------------------------------------------------------------------------------
// Address: 0x1002D650
// Name: protected: void CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::RemoveEntriesPreviousTo(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::RemoveEntriesPreviousTo(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        float flTime)
{
  int v2; // eax
  int m_maxElement; // edi
  int i; // esi
  int v5; // edx
  bool v6; // cc
  int m_count; // edx
  int v8; // eax

  v2 = 0;
  if ( this->m_VarHistory.m_count != 0 )
  {
    m_maxElement = this->m_VarHistory.m_maxElement;
    for ( i = this->m_VarHistory.m_firstElement - m_maxElement; ; ++i )
    {
      v5 = v2 + this->m_VarHistory.m_firstElement;
      if ( v5 >= m_maxElement )
        v5 = i;
      v6 = flTime <= this->m_VarHistory.m_pElements[v5].flChangeTime;
      m_count = this->m_VarHistory.m_count;
      if ( !v6 )
        break;
      if ( ++v2 >= m_count )
        return;
    }
    v8 = v2 + 3;
    if ( v8 < m_count )
      this->m_VarHistory.m_count = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D6B0
// Name: protected: void CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::_Extrapolate(class CRangeCheckedVar<float,-2,2,0> __near *,struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near *,struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::_Extrapolate(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        CRangeCheckedVar<float,-2,2,0> *pOut,
        CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *pOld,
        CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *pNew,
        float flDestinationTime,
        float flMaxExtrapolationAmount)
{
  int v6; // eax
  CRangeCheckedVar<float,-2,2,0> *v7; // edx
  int v8; // eax
  CRangeCheckedVar<float,-2,2,0> *p_value; // edx

  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(pOld->flChangeTime - pNew->flChangeTime) & _mask__AbsFloat_) < 0.001
    || pNew->flChangeTime >= flDestinationTime )
  {
    v8 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      p_value = &pNew->value;
      do
      {
        pOut[v8++] = LODWORD(p_value->m_Val);
        ++p_value;
      }
      while ( v8 < this->m_nMaxCount );
    }
  }
  else
  {
    v6 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      v7 = &pNew->value;
      do
      {
        pOut[v6++] = LODWORD(v7->m_Val);
        ++v7;
      }
      while ( v6 < this->m_nMaxCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D730
// Name: public: void CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::AddToHead(float,class CRangeCheckedVar<float,-2,2,0> const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::AddToHead(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        float changeTime,
        CRangeCheckedVar<float,-2,2,0> *values,
        bool bFlushNewer)
{
  unsigned int m_firstElement; // eax
  unsigned int m_maxElement; // ecx
  unsigned __int16 m_count; // dx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> > *p_m_VarHistory; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // edx
  int v19; // ebx
  int v20; // ecx
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *m_pElements; // eax
  int v22; // ecx
  int v23; // ecx
  int v24; // eax
  int v25; // eax
  unsigned int v26; // [esp-10h] [ebp-18h]
  int i; // [esp+0h] [ebp-8h]
  int v28; // [esp+4h] [ebp-4h]
  int newslot; // [esp+18h] [ebp+10h]

  if ( bFlushNewer )
  {
    while ( this->m_VarHistory.m_count != 0 )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      if ( m_firstElement >= m_maxElement )
        m_firstElement -= m_maxElement;
      if ( (float)(this->m_VarHistory.m_pElements[m_firstElement].flChangeTime + 0.000099999997) <= changeTime )
        break;
      m_count = this->m_VarHistory.m_count;
      if ( m_count != 0 )
      {
        v8 = this->m_VarHistory.m_maxElement;
        v9 = this->m_VarHistory.m_firstElement + 1;
        if ( v9 >= v8 )
          LOWORD(v9) = v9 - v8;
        this->m_VarHistory.m_firstElement = v9;
        this->m_VarHistory.m_count = m_count - 1;
      }
    }
    p_m_VarHistory = &this->m_VarHistory;
    CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0>>::EnsureCapacity(
      this: &this->m_VarHistory,
      capSize: this->m_VarHistory.m_count + 1);
    v11 = this->m_VarHistory.m_maxElement;
    v12 = this->m_VarHistory.m_firstElement;
    ++this->m_VarHistory.m_count;
    v13 = v12 + v11 - 1;
    if ( v13 >= v11 )
      LOWORD(v13) = v13 - v11;
    this->m_VarHistory.m_firstElement = v13;
    newslot = 0;
  }
  else
  {
    p_m_VarHistory = &this->m_VarHistory;
    CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0>>::EnsureCapacity(
      this: &this->m_VarHistory,
      capSize: this->m_VarHistory.m_count + 1);
    v14 = this->m_VarHistory.m_maxElement;
    v15 = this->m_VarHistory.m_firstElement;
    ++this->m_VarHistory.m_count;
    v16 = v15 + v14 - 1;
    if ( v16 >= v14 )
      LOWORD(v16) = v16 - v14;
    this->m_VarHistory.m_firstElement = v16;
    v17 = 1;
    newslot = 0;
    i = 1;
    if ( this->m_VarHistory.m_count > 1u )
    {
      do
      {
        v18 = this->m_VarHistory.m_maxElement;
        v19 = v17 + this->m_VarHistory.m_firstElement;
        v20 = v19;
        if ( v19 >= v18 )
          v20 = v19 - v18;
        m_pElements = p_m_VarHistory->m_pElements;
        if ( changeTime >= p_m_VarHistory->m_pElements[v20].flChangeTime )
          break;
        v28 = v19;
        if ( v19 >= v18 )
          v28 = v19 - v18;
        v22 = newslot + this->m_VarHistory.m_firstElement;
        if ( v22 >= v18 )
          v22 -= v18;
        m_pElements[v22].flChangeTime = m_pElements[v28].flChangeTime;
        m_pElements[v22].value.m_Val = m_pElements[v28].value.m_Val;
        newslot = i;
        v17 = i + 1;
        i = v17;
      }
      while ( v17 < this->m_VarHistory.m_count );
    }
  }
  v23 = p_m_VarHistory->m_maxElement;
  v24 = newslot + p_m_VarHistory->m_firstElement;
  if ( v24 >= v23 )
    v24 -= v23;
  v25 = (int)&p_m_VarHistory->m_pElements[v24];
  v26 = 4 * this->m_nMaxCount;
  *(float *)v25 = changeTime;
  memcpy(dst: (unsigned __int8 *)(v25 + 4), src: (unsigned __int8 *)values, count: v26);
}

//------------------------------------------------------------------------------
// Address: 0x1002D8C0
// Name: protected: bool CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::GetInterpolationInfo(class CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::CInterpolationInfo __near *,float,float,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::GetInterpolationInfo(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::CInterpolationInfo *pInfo,
        float currentTime,
        float interpolation_amount,
        int *pNoMoreChanges)
{
  float v5; // xmm0_4
  int v6; // esi
  int m_maxElement; // edi
  int v8; // eax
  float flChangeTime; // xmm1_4
  int newer; // eax
  int v12; // ebx
  int v13; // edi
  int v14; // eax
  float v15; // xmm2_4
  float v16; // xmm0_4
  int v17; // edi
  int v18; // eax
  int v19; // edi
  int m_firstElement; // ebx
  int v21; // eax
  unsigned int v22; // edi
  int v23; // esi
  int p_value; // ecx
  int v25; // esi
  int v26; // esi
  int v27; // edx
  unsigned int v28; // esi
  int v29; // ecx
  int v30; // edx
  int v31; // eax
  int older; // eax
  int v33; // [esp+0h] [ebp-4h]
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *currentTimea; // [esp+10h] [ebp+Ch]
  unsigned int interpolation_amounta; // [esp+14h] [ebp+10h]

  v5 = currentTime - interpolation_amount;
  pInfo->m_bHermite = false;
  pInfo->frac = 0.0;
  pInfo->newer = -1;
  pInfo->older = -1;
  pInfo->oldest = -1;
  v6 = 0;
  if ( this->m_VarHistory.m_count == 0 )
  {
LABEL_7:
    newer = pInfo->newer;
    if ( newer == -1 )
    {
      older = pInfo->older;
      pInfo->newer = older;
      return older != -1;
    }
    else
    {
      pInfo->older = newer;
      return true;
    }
  }
  while ( 1 )
  {
    pInfo->older = v6;
    m_maxElement = this->m_VarHistory.m_maxElement;
    v8 = v6 + this->m_VarHistory.m_firstElement;
    if ( v8 >= m_maxElement )
      v8 -= m_maxElement;
    flChangeTime = this->m_VarHistory.m_pElements[v8].flChangeTime;
    if ( flChangeTime == 0.0 )
      goto LABEL_7;
    if ( flChangeTime <= v5 )
      break;
    pInfo->newer = v6++;
    if ( v6 >= this->m_VarHistory.m_count )
      goto LABEL_7;
  }
  v12 = pInfo->newer;
  if ( v12 != -1 )
  {
    v13 = this->m_VarHistory.m_maxElement;
    v14 = v12 + this->m_VarHistory.m_firstElement;
    if ( v14 >= v13 )
      v14 -= v13;
    v15 = this->m_VarHistory.m_pElements[v14].flChangeTime - flChangeTime;
    if ( v15 > 0.000099999997 )
    {
      v16 = (float)(v5 - flChangeTime) / v15;
      pInfo->frac = v16;
      if ( v16 >= 2.0 )
        v16 = 2.0;
      pInfo->frac = v16;
      v17 = v6 + 1;
      if ( (this->m_fType & 0x10) == 0 && v17 >= 0 && v17 < this->m_VarHistory.m_count )
      {
        pInfo->oldest = v17;
        v18 = v17 + this->m_VarHistory.m_firstElement;
        v19 = this->m_VarHistory.m_maxElement;
        if ( v18 >= v19 )
          v18 -= v19;
        if ( (float)(flChangeTime - this->m_VarHistory.m_pElements[v18].flChangeTime) > 0.000099999997 )
          pInfo->m_bHermite = true;
      }
      if ( pNoMoreChanges != nullptr && v12 == (this->m_VarHistory.m_count != 0) - 1 )
      {
        m_firstElement = this->m_VarHistory.m_firstElement;
        v21 = this->m_VarHistory.m_maxElement;
        v22 = 4 * this->m_nMaxCount;
        v23 = m_firstElement + v6;
        interpolation_amounta = v22;
        if ( v23 >= v21 )
          v23 -= v21;
        currentTimea = this->m_VarHistory.m_pElements;
        p_value = (int)&currentTimea[v23].value;
        v25 = m_firstElement + pInfo->newer;
        v33 = v25;
        if ( v25 >= v21 )
          v25 -= v21;
        v26 = (int)&currentTimea[v25].value;
        if ( v22 >= 4 )
        {
          while ( *(_DWORD *)v26 == *(_DWORD *)p_value )
          {
            v22 -= 4;
            p_value += 4;
            v26 += 4;
            if ( v22 < 4 )
              goto LABEL_35;
          }
          return true;
        }
LABEL_35:
        if ( v22 == 0
          || *(_BYTE *)p_value == *(_BYTE *)v26
          && (v22 <= 1
           || *(_BYTE *)(p_value + 1) == *(_BYTE *)(v26 + 1)
           && (v22 <= 2 || *(_BYTE *)(p_value + 2) == *(_BYTE *)(v26 + 2))) )
        {
          if ( !pInfo->m_bHermite )
            goto LABEL_55;
          v27 = m_firstElement + pInfo->oldest;
          v28 = interpolation_amounta;
          if ( v27 >= v21 )
            v27 -= v21;
          v29 = v33;
          v30 = (int)&currentTimea[v27].value;
          if ( v33 >= v21 )
            v29 = v33 - v21;
          v31 = (int)&currentTimea[v29].value;
          if ( interpolation_amounta >= 4 )
          {
            while ( *(_DWORD *)v31 == *(_DWORD *)v30 )
            {
              v28 -= 4;
              v30 += 4;
              v31 += 4;
              if ( v28 < 4 )
                goto LABEL_49;
            }
            return true;
          }
LABEL_49:
          if ( v28 == 0
            || *(_BYTE *)v30 == *(_BYTE *)v31
            && (v28 <= 1
             || *(_BYTE *)(v30 + 1) == *(_BYTE *)(v31 + 1) && (v28 <= 2 || *(_BYTE *)(v30 + 2) == *(_BYTE *)(v31 + 2))) )
          {
LABEL_55:
            *pNoMoreChanges = 1;
          }
        }
      }
    }
    return true;
  }
  pInfo->newer = v6;
  if ( pNoMoreChanges != nullptr )
    *pNoMoreChanges = 1;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1002DB30
// Name: protected: void CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::_Interpolate(class CRangeCheckedVar<float,-2,2,0> __near *,float,struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near *,struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::_Interpolate(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        CRangeCheckedVar<float,-2,2,0> *out,
        float frac,
        CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *start,
        CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *end)
{
  int v5; // eax
  CRangeCheckedVar<float,-2,2,0> *p_value; // esi
  float m_Val; // xmm0_4
  CRangeCheckedVar<float,-2,2,0> *v8; // edx
  int v9; // edi
  float v10; // xmm0_4

  v5 = 0;
  if ( start == end )
  {
    if ( this->m_nMaxCount != 0 )
    {
      p_value = &end->value;
      do
      {
        out[v5] = LODWORD(p_value->m_Val);
        m_Val = out[v5].m_Val;
        if ( m_Val >= -2.0 )
        {
          if ( m_Val > 2.0 )
            out[v5].m_Val = 2.0;
        }
        else
        {
          out[v5].m_Val = -2.0;
        }
        ++v5;
        ++p_value;
      }
      while ( v5 < this->m_nMaxCount );
    }
  }
  else if ( this->m_nMaxCount != 0 )
  {
    v8 = &start->value;
    v9 = (char *)end - (char *)start;
    do
    {
      if ( this->m_bLooping[v5] != 0 )
        out[v5].m_Val = (float)((float)(1.0 - frac) * v8->m_Val) + (float)(*(float *)((char *)&v8->m_Val + v9) * frac);
      else
        out[v5].m_Val = (float)((float)(*(float *)((char *)&v8->m_Val + v9) - v8->m_Val) * frac) + v8->m_Val;
      v10 = out[v5].m_Val;
      if ( v10 >= -2.0 )
      {
        if ( v10 > 2.0 )
          out[v5].m_Val = 2.0;
      }
      else
      {
        out[v5].m_Val = -2.0;
      }
      ++v5;
      ++v8;
    }
    while ( v5 < this->m_nMaxCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DC50
// Name: protected: void CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::TimeFixup2_Hermite(struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near &,struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near * __near &,struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near * __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::TimeFixup2_Hermite(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *fixup,
        CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> **prev,
        CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> **start,
        float dt1,
        bool bAllowHermiteFix)
{
  float v6; // xmm3_4
  float v7; // xmm0_4
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *v8; // edx
  int v9; // eax
  float v10; // xmm1_4
  CRangeCheckedVar<float,-2,2,0> *p_dt1; // edx
  float v12; // xmm2_4
  float m_Val; // ebx
  float v14; // [esp+0h] [ebp-4h] BYREF

  v14 = *(float *)&this;
  v6 = dt1;
  v7 = (*start)->flChangeTime - (*prev)->flChangeTime;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(dt1 - v7) & _mask__AbsFloat_) > 0.000099999997 && v7 > 0.000099999997 )
  {
    v8 = fixup;
    v9 = 0;
    fixup->flChangeTime = (*start)->flChangeTime - dt1;
    v10 = v6 / v7;
    if ( this->m_nMaxCount != 0 )
    {
      do
      {
        if ( this->m_bLooping[v9] != 0 )
        {
          if ( g_bHermiteFix && bAllowHermiteFix )
          {
            p_dt1 = &(*prev)->value + v9;
          }
          else
          {
            dt1 = (float)((float)(1.0 - (float)(1.0 - v10)) * *(&(*prev)->value.m_Val + v9))
                + (float)((float)(1.0 - v10) * *(&(*start)->value.m_Val + v9));
            p_dt1 = (CRangeCheckedVar<float,-2,2,0> *)&dt1;
          }
        }
        else if ( g_bHermiteFix && bAllowHermiteFix )
        {
          p_dt1 = &(*prev)->value + v9;
        }
        else
        {
          v12 = *(&(*prev)->value.m_Val + v9);
          v14 = (float)((float)(*(&(*start)->value.m_Val + v9) - v12) * (float)(1.0 - v10)) + v12;
          p_dt1 = (CRangeCheckedVar<float,-2,2,0> *)&v14;
        }
        m_Val = p_dt1->m_Val;
        v8 = fixup;
        *(&fixup->value.m_Val + v9++) = m_Val;
      }
      while ( v9 < this->m_nMaxCount );
    }
    *prev = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E1F0
// Name: public: virtual void CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::Reset(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::Reset(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        float flCurrentTime)
{
  CRangeCheckedVar<float,-2,2,0> *m_pValue; // eax

  *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
  m_pValue = this->m_pValue;
  if ( m_pValue != nullptr )
  {
    CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: m_pValue,
      bFlushNewer: false);
    CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: this->m_pValue,
      bFlushNewer: false);
    CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: this->m_pValue,
      bFlushNewer: false);
    memcpy(
      dst: (unsigned __int8 *)this->m_LastNetworkedValue,
      src: (unsigned __int8 *)this->m_pValue,
      count: 4 * this->m_nMaxCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E270
// Name: public: virtual void CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::Copy(class IInterpolatedVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::Copy(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        IInterpolatedVar *pInSrc)
{
  _BYTE *v3; // eax
  _BYTE *v4; // edi
  unsigned __int8 m_nMaxCount; // cl
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int m_maxElement; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *v13; // ecx
  int v14; // eax
  int v15; // edx
  double v16; // st7
  int v17; // eax
  int v18; // edx

  v3 = __RTDynamicCast(
         inptr: pInSrc,
         VfDelta: 0,
         SrcType: &IInterpolatedVar `RTTI Type Descriptor',
         TargetType: &CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> `RTTI Type Descriptor',
         isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    m_nMaxCount = this->m_nMaxCount;
    if ( v3[29] == m_nMaxCount )
    {
      v6 = 0;
      if ( m_nMaxCount != 0 )
      {
        do
        {
          this->m_LastNetworkedValue[v6].m_Val = *(float *)(*((_DWORD *)v4 + 5) + 4 * v6);
          this->m_bLooping[v6] = *(_BYTE *)(v6 + *((_DWORD *)v4 + 8));
          ++v6;
        }
        while ( v6 < this->m_nMaxCount );
      }
      this->m_LastNetworkedTime = *((float *)v4 + 6);
      *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
      v7 = 0;
      if ( *((_WORD *)v4 + 8) != 0 )
      {
        do
        {
          CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0>>::EnsureCapacity(
            this: &this->m_VarHistory,
            capSize: this->m_VarHistory.m_count + 1);
          v8 = this->m_VarHistory.m_firstElement + ++this->m_VarHistory.m_count - 1;
          m_maxElement = this->m_VarHistory.m_maxElement;
          if ( v8 >= m_maxElement )
            v8 -= m_maxElement;
          v10 = v8 + this->m_VarHistory.m_firstElement;
          v11 = this->m_VarHistory.m_maxElement;
          if ( v10 >= v11 )
            v10 -= v11;
          v12 = *((unsigned __int16 *)v4 + 6);
          v13 = &this->m_VarHistory.m_pElements[v10];
          v14 = v7 + *((unsigned __int16 *)v4 + 7);
          if ( v14 >= v12 )
            v14 -= v12;
          v15 = *((_DWORD *)v4 + 2);
          v16 = *(float *)(v15 + 8 * v14);
          v17 = v15 + 8 * v14;
          v18 = this->m_nMaxCount;
          v13->flChangeTime = v16;
          memcpy(dst: (unsigned __int8 *)&v13->value, src: (unsigned __int8 *)(v17 + 4), count: 4 * v18);
          ++v7;
        }
        while ( v7 < *((unsigned __int16 *)v4 + 8) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E6D0
// Name: public: bool CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::NoteChanged(float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::NoteChanged(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        float flCurrentTime,
        float flChangeTime,
        float interpolation_amount,
        bool bUpdateLastNetworkedValue)
{
  char v6; // bl
  unsigned int m_firstElement; // ecx
  unsigned int m_maxElement; // edx
  unsigned int v9; // eax
  CRangeCheckedVar<float,-2,2,0> *m_pValue; // edi
  CRangeCheckedVar<float,-2,2,0> *p_value; // ecx
  int v12; // eax
  int v13; // edi
  int i; // edx
  int v15; // ecx
  bool v16; // cc
  int m_count; // ecx
  int v19; // eax
  bool bRet; // [esp+1Bh] [ebp-1h]

  v6 = 1;
  bRet = true;
  if ( this->m_VarHistory.m_count != 0 )
  {
    m_firstElement = this->m_VarHistory.m_firstElement;
    m_maxElement = this->m_VarHistory.m_maxElement;
    v9 = 4 * this->m_nMaxCount;
    if ( m_firstElement >= m_maxElement )
      m_firstElement -= m_maxElement;
    m_pValue = this->m_pValue;
    p_value = &this->m_VarHistory.m_pElements[m_firstElement].value;
    if ( v9 < 4 )
    {
LABEL_7:
      if ( v9 == 0
        || LOBYTE(p_value->m_Val) == LOBYTE(m_pValue->m_Val)
        && (v9 <= 1
         || BYTE1(p_value->m_Val) == BYTE1(m_pValue->m_Val)
         && (v9 <= 2 || BYTE2(p_value->m_Val) == BYTE2(m_pValue->m_Val))) )
      {
        v6 = 0;
        bRet = false;
      }
    }
    else
    {
      while ( LODWORD(m_pValue->m_Val) == LODWORD(p_value->m_Val) )
      {
        v9 -= 4;
        ++p_value;
        ++m_pValue;
        if ( v9 < 4 )
          goto LABEL_7;
      }
    }
  }
  CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::AddToHead(
    this,
    changeTime: flChangeTime,
    values: this->m_pValue,
    bFlushNewer: true);
  if ( bUpdateLastNetworkedValue )
    this->NoteLastNetworkedValue(this);
  v12 = 0;
  if ( this->m_VarHistory.m_count == 0 )
    return v6;
  v13 = this->m_VarHistory.m_maxElement;
  for ( i = this->m_VarHistory.m_firstElement - v13; ; ++i )
  {
    v15 = v12 + this->m_VarHistory.m_firstElement;
    if ( v15 >= v13 )
      v15 = i;
    v16 = (float)((float)(flCurrentTime - interpolation_amount) - 0.050000001) <= this->m_VarHistory.m_pElements[v15].flChangeTime;
    m_count = this->m_VarHistory.m_count;
    if ( !v16 )
      break;
    if ( ++v12 >= m_count )
      return bRet;
  }
  v19 = v12 + 3;
  if ( v19 >= m_count )
    return bRet;
  this->m_VarHistory.m_count = v19;
  return bRet;
}

//------------------------------------------------------------------------------
// Address: 0x1002EDD0
// Name: public: virtual bool CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::NoteChanged(float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::NoteChanged(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        float flCurrentTime,
        float flChangeTime,
        bool bUpdateLastNetworkedValue)
{
  return CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::NoteChanged(
           this,
           flCurrentTime,
           flChangeTime,
           interpolation_amount: this->m_InterpolationAmount,
           bUpdateLastNetworkedValue);
}

//------------------------------------------------------------------------------
// Address: 0x1002EE10
// Name: protected: void CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::_Interpolate_Hermite(class CRangeCheckedVar<float,-2,2,0> __near *,float,struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near *,struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near *,struct CInterpolatedVarEntryBase<class CRangeCheckedVar<float,-2,2,0>,0> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::_Interpolate_Hermite(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        CRangeCheckedVar<float,-2,2,0> *out,
        float frac,
        CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *prev,
        float start,
        float end,
        bool looping)
{
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *v8; // ebx
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *v9; // esi
  int v10; // ecx
  float v11; // xmm2_4
  int v12; // ebx
  float v13; // xmm4_4
  float *p_m_Val; // eax
  float v16; // xmm6_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  CRangeCheckedVar<float,-2,2,0> v20; // xmm0_4
  float m_Val; // xmm0_4
  float v22; // xmm1_4
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> fixup; // [esp+14h] [ebp-14h] BYREF
  CRangeCheckedVar<float,-2,2,0> v24; // [esp+1Ch] [ebp-Ch]
  float v25; // [esp+20h] [ebp-8h]
  CDisableRangeChecks disableRangeChecks; // [esp+27h] [ebp-1h] BYREF
  float outa; // [esp+30h] [ebp+8h]

  CDisableRangeChecks::CDisableRangeChecks(this: &disableRangeChecks);
  v8 = (CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *)LODWORD(end);
  v9 = (CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *)LODWORD(start);
  fixup.value.m_Val = 0.0;
  CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::TimeFixup2_Hermite(
    this,
    &fixup,
    &prev,
    (CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> **)&start,
    dt1: *(float *)LODWORD(end) - *(float *)LODWORD(start),
    bAllowHermiteFix: true);
  v10 = 0;
  if ( this->m_nMaxCount != 0 )
  {
    v11 = frac;
    v12 = (char *)v8 - (char *)v9;
    v13 = v11 * v11;
    prev = (CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *)((char *)prev - (int)v9);
    end = v11 * v11;
    p_m_Val = &v9->value.m_Val;
    while ( 1 )
    {
      if ( this->m_bLooping[v10] != 0 )
      {
        v25 = *(float *)((char *)p_m_Val + v12);
        v16 = v25;
        outa = *p_m_Val;
        v17 = *p_m_Val;
        start = *(float *)((char *)p_m_Val + (_DWORD)prev);
        v18 = start;
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(outa - start) & _mask__AbsFloat_) > 0.5 )
        {
          if ( v17 <= start )
          {
            v17 = v17 + 1.0;
          }
          else
          {
            v18 = start + 1.0;
            start = start + 1.0;
          }
        }
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v25 - v17) & _mask__AbsFloat_) > 0.5 )
        {
          if ( v25 <= v17 )
          {
            v16 = v25 + 1.0;
          }
          else
          {
            v17 = v17 + 1.0;
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v17 - v18) & _mask__AbsFloat_) > 0.5 )
            {
              if ( v17 <= v18 )
                v17 = v17 + 1.0;
              else
                start = v18 + 1.0;
            }
          }
        }
        v19 = (float)((float)((float)((float)((float)((float)((float)(v13 * v11) * 2.0) - (float)(v13 * 3.0)) + 1.0)
                                    * v17)
                            + (float)((float)((float)(v13 * 3.0) - (float)((float)(v13 * v11) * 2.0)) * v16))
                    + (float)((float)((float)((float)(v13 * v11) - (float)(v13 * 2.0)) + frac) * (float)(v17 - start)))
            + (float)((float)((float)(v13 * v11) - v13) * (float)(v16 - v17));
        v20.m_Val = v19 - (float)(int)v19;
        if ( v20.m_Val < 0.0 )
          v20.m_Val = v20.m_Val + 1.0;
        out[v10] = v20;
      }
      else
      {
        v24.m_Val = (float)((float)((float)((float)((float)(v13 * v11) - (float)(v13 * 2.0)) + frac)
                                  * (float)(*p_m_Val - *(float *)((char *)p_m_Val + (_DWORD)prev)))
                          + (float)((float)((float)((float)((float)((float)(v13 * v11) * 2.0) - (float)(v13 * 3.0)) + 1.0)
                                          * *p_m_Val)
                                  + (float)((float)((float)(v13 * 3.0) - (float)((float)(v13 * v11) * 2.0))
                                          * *(float *)((char *)p_m_Val + v12))))
                  + (float)((float)(*(float *)((char *)p_m_Val + v12) - *p_m_Val) * (float)((float)(v13 * v11) - v13));
        out[v10] = v24;
      }
      m_Val = out[v10].m_Val;
      v22 = -2.0;
      v13 = end;
      if ( m_Val < -2.0 || (v22 = 2.0, m_Val > 2.0) )
        out[v10].m_Val = v22;
      ++v10;
      ++p_m_Val;
      if ( v10 >= this->m_nMaxCount )
        break;
      v11 = frac;
    }
  }
  CDisableRangeChecks::~CDisableRangeChecks(this: &disableRangeChecks);
}

//------------------------------------------------------------------------------
// Address: 0x10030580
// Name: public: int CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::Interpolate(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::Interpolate(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        float currentTime,
        float interpolation_amount)
{
  int m_firstElement; // ecx
  int m_maxElement; // eax
  int v6; // edx
  int v7; // ecx
  int newer; // ebx
  int older; // edx
  int v10; // eax
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ebx
  int v15; // ecx
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *v17; // [esp+8h] [ebp-34h]
  float flMaxExtrapolationAmount; // [esp+10h] [ebp-2Ch]
  CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::CInterpolationInfo info; // [esp+20h] [ebp-1Ch] BYREF
  int realOlder; // [esp+34h] [ebp-8h]
  int noMoreChanges; // [esp+38h] [ebp-4h] BYREF

  noMoreChanges = 0;
  if ( CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::GetInterpolationInfo(
         this,
         pInfo: &info,
         currentTime,
         interpolation_amount,
         pNoMoreChanges: &noMoreChanges) )
  {
    if ( info.m_bHermite )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      realOlder = m_firstElement + info.newer;
      if ( m_firstElement + info.newer >= m_maxElement )
        realOlder = m_firstElement + info.newer - m_maxElement;
      v6 = m_firstElement + info.older;
      if ( m_firstElement + info.older >= m_maxElement )
        v6 -= m_maxElement;
      v7 = info.oldest + m_firstElement;
      if ( v7 >= m_maxElement )
        v7 -= m_maxElement;
      CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::_Interpolate_Hermite(
        this,
        out: this->m_pValue,
        frac: info.frac,
        prev: &this->m_VarHistory.m_pElements[v7],
        start: COERCE_FLOAT((int)&this->m_VarHistory.m_pElements[v6]),
        end: COERCE_FLOAT((int)&this->m_VarHistory.m_pElements[realOlder]),
        looping: false);
      goto LABEL_24;
    }
    newer = info.newer;
    older = info.older;
    if ( info.newer == info.older )
    {
      v10 = info.newer + 1;
      realOlder = info.newer + 1;
      if ( CInterpolationContext::s_bAllowExtrapolation && v10 >= 0 && v10 < this->m_VarHistory.m_count )
      {
        if ( CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0>>::operator[](
               this: &this->m_VarHistory,
               i: info.newer + 1)->flChangeTime != 0.0
          && interpolation_amount > 0.000001
          && this->m_LastNetworkedTime >= CInterpolationContext::s_flLastTimeStamp )
        {
          flMaxExtrapolationAmount = cl_extrapolate_amount.m_pParent->m_Value.m_fValue;
          v17 = CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0>>::operator[](
                  this: &this->m_VarHistory,
                  i: newer);
          v11 = CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0>>::operator[](
                  this: &this->m_VarHistory,
                  i: realOlder);
          CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::_Extrapolate(
            this,
            pOut: this->m_pValue,
            pOld: v11,
            pNew: v17,
            flDestinationTime: currentTime - interpolation_amount,
            flMaxExtrapolationAmount);
LABEL_24:
          CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::RemoveEntriesPreviousTo(
            this,
            flTime: (float)(currentTime - interpolation_amount) - 0.050000001);
          return noMoreChanges;
        }
        older = info.older;
      }
    }
    v12 = this->m_VarHistory.m_firstElement;
    v13 = this->m_VarHistory.m_maxElement;
    v14 = v12 + newer;
    if ( v14 >= v13 )
      v14 -= v13;
    v15 = older + v12;
    if ( v15 >= v13 )
      v15 -= v13;
    CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::_Interpolate(
      this,
      out: this->m_pValue,
      frac: info.frac,
      start: &this->m_VarHistory.m_pElements[v15],
      end: &this->m_VarHistory.m_pElements[v14]);
    goto LABEL_24;
  }
  return noMoreChanges;
}

//------------------------------------------------------------------------------
// Address: 0x10031B20
// Name: public: virtual int CInterpolatedVarArrayBase<class CRangeCheckedVar<float,-2,2,0>,0>::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::Interpolate(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        float currentTime)
{
  return CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::Interpolate(
           this,
           currentTime,
           interpolation_amount: this->m_InterpolationAmount);
}

//------------------------------------------------------------------------------
// Address: 0x10033920
// Name: public: struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near & CSimpleRingBuffer<struct CInterpolatedVarEntryBase<class C_AnimationLayer,0>>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
CInterpolatedVarEntryBase<C_AnimationLayer,0> *__thiscall CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0>>::operator[](
        CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0> > *this,
        int i)
{
  int v2; // eax
  int m_maxElement; // edx

  v2 = this->m_firstElement + i;
  m_maxElement = this->m_maxElement;
  if ( v2 >= m_maxElement )
    v2 -= m_maxElement;
  return &this->m_pElements[v2];
}

//------------------------------------------------------------------------------
// Address: 0x10034000
// Name: protected: bool CInterpolatedVarArrayBase<class C_AnimationLayer,0>::GetInterpolationInfo(class CInterpolatedVarArrayBase<class C_AnimationLayer,0>::CInterpolationInfo __near *,float,float,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::GetInterpolationInfo(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        CInterpolatedVarArrayBase<C_AnimationLayer,0>::CInterpolationInfo *pInfo,
        float currentTime,
        float interpolation_amount,
        int *pNoMoreChanges)
{
  float v5; // xmm0_4
  int v6; // esi
  int m_maxElement; // edi
  int v8; // eax
  float flChangeTime; // xmm1_4
  int newer; // eax
  int v12; // ebx
  int v13; // edi
  int v14; // eax
  float v15; // xmm2_4
  float v16; // xmm0_4
  int v17; // edi
  int v18; // eax
  int v19; // edi
  int m_firstElement; // ebx
  unsigned int v21; // edi
  int v22; // eax
  int v23; // esi
  int p_value; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // edx
  unsigned int v28; // edi
  int v29; // eax
  int v30; // edx
  int v31; // eax
  int older; // eax
  int v33; // [esp+0h] [ebp-4h]
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *currentTimea; // [esp+10h] [ebp+Ch]
  unsigned int interpolation_amounta; // [esp+14h] [ebp+10h]

  v5 = currentTime - interpolation_amount;
  pInfo->m_bHermite = false;
  pInfo->frac = 0.0;
  pInfo->newer = -1;
  pInfo->older = -1;
  pInfo->oldest = -1;
  v6 = 0;
  if ( this->m_VarHistory.m_count == 0 )
  {
LABEL_7:
    newer = pInfo->newer;
    if ( newer == -1 )
    {
      older = pInfo->older;
      pInfo->newer = older;
      return older != -1;
    }
    else
    {
      pInfo->older = newer;
      return true;
    }
  }
  while ( 1 )
  {
    pInfo->older = v6;
    m_maxElement = this->m_VarHistory.m_maxElement;
    v8 = v6 + this->m_VarHistory.m_firstElement;
    if ( v8 >= m_maxElement )
      v8 -= m_maxElement;
    flChangeTime = this->m_VarHistory.m_pElements[v8].flChangeTime;
    if ( flChangeTime == 0.0 )
      goto LABEL_7;
    if ( flChangeTime <= v5 )
      break;
    pInfo->newer = v6++;
    if ( v6 >= this->m_VarHistory.m_count )
      goto LABEL_7;
  }
  v12 = pInfo->newer;
  if ( v12 != -1 )
  {
    v13 = this->m_VarHistory.m_maxElement;
    v14 = v12 + this->m_VarHistory.m_firstElement;
    if ( v14 >= v13 )
      v14 -= v13;
    v15 = this->m_VarHistory.m_pElements[v14].flChangeTime - flChangeTime;
    if ( v15 > 0.000099999997 )
    {
      v16 = (float)(v5 - flChangeTime) / v15;
      pInfo->frac = v16;
      if ( v16 >= 2.0 )
        v16 = 2.0;
      pInfo->frac = v16;
      v17 = v6 + 1;
      if ( (this->m_fType & 0x10) == 0 && v17 >= 0 && v17 < this->m_VarHistory.m_count )
      {
        pInfo->oldest = v17;
        v18 = v17 + this->m_VarHistory.m_firstElement;
        v19 = this->m_VarHistory.m_maxElement;
        if ( v18 >= v19 )
          v18 -= v19;
        if ( (float)(flChangeTime - this->m_VarHistory.m_pElements[v18].flChangeTime) > 0.000099999997 )
          pInfo->m_bHermite = true;
      }
      if ( pNoMoreChanges != nullptr && v12 == (this->m_VarHistory.m_count != 0) - 1 )
      {
        m_firstElement = this->m_VarHistory.m_firstElement;
        interpolation_amounta = 40 * this->m_nMaxCount;
        v21 = interpolation_amounta;
        v22 = m_firstElement + v6;
        v23 = this->m_VarHistory.m_maxElement;
        if ( v22 >= v23 )
          v22 -= v23;
        currentTimea = this->m_VarHistory.m_pElements;
        p_value = (int)&currentTimea[v22].value;
        v25 = m_firstElement + pInfo->newer;
        v33 = v25;
        if ( v25 >= v23 )
          v25 -= v23;
        v26 = (int)&currentTimea[v25].value;
        if ( interpolation_amounta >= 4 )
        {
          while ( *(_DWORD *)v26 == *(_DWORD *)p_value )
          {
            v21 -= 4;
            p_value += 4;
            v26 += 4;
            if ( v21 < 4 )
              goto LABEL_35;
          }
          return true;
        }
LABEL_35:
        if ( v21 == 0
          || *(_BYTE *)p_value == *(_BYTE *)v26
          && (v21 <= 1
           || *(_BYTE *)(p_value + 1) == *(_BYTE *)(v26 + 1)
           && (v21 <= 2 || *(_BYTE *)(p_value + 2) == *(_BYTE *)(v26 + 2))) )
        {
          if ( !pInfo->m_bHermite )
            goto LABEL_55;
          v27 = m_firstElement + pInfo->oldest;
          v28 = interpolation_amounta;
          if ( v27 >= v23 )
            v27 -= v23;
          v29 = v33;
          v30 = (int)&currentTimea[v27].value;
          if ( v33 >= v23 )
            v29 = v33 - v23;
          v31 = (int)&currentTimea[v29].value;
          if ( interpolation_amounta >= 4 )
          {
            while ( *(_DWORD *)v31 == *(_DWORD *)v30 )
            {
              v28 -= 4;
              v30 += 4;
              v31 += 4;
              if ( v28 < 4 )
                goto LABEL_49;
            }
            return true;
          }
LABEL_49:
          if ( v28 == 0
            || *(_BYTE *)v30 == *(_BYTE *)v31
            && (v28 <= 1
             || *(_BYTE *)(v30 + 1) == *(_BYTE *)(v31 + 1) && (v28 <= 2 || *(_BYTE *)(v30 + 2) == *(_BYTE *)(v31 + 2))) )
          {
LABEL_55:
            *pNoMoreChanges = 1;
          }
        }
      }
    }
    return true;
  }
  pInfo->newer = v6;
  if ( pNoMoreChanges != nullptr )
    *pNoMoreChanges = 1;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10034350
// Name: public: virtual void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::NoteLastNetworkedValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::NoteLastNetworkedValue(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this)
{
  memcpy(
    dst: (unsigned __int8 *)this->m_LastNetworkedValue,
    src: (unsigned __int8 *)this->m_pValue,
    count: 40 * this->m_nMaxCount);
  this->m_LastNetworkedTime = g_flLastPacketTimestamp;
}

//------------------------------------------------------------------------------
// Address: 0x10034380
// Name: public: virtual void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::RestoreToLastNetworked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::RestoreToLastNetworked(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this)
{
  memcpy(
    dst: (unsigned __int8 *)this->m_pValue,
    src: (unsigned __int8 *)this->m_LastNetworkedValue,
    count: 40 * this->m_nMaxCount);
}

//------------------------------------------------------------------------------
// Address: 0x100343A0
// Name: protected: void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::RemoveEntriesPreviousTo(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::RemoveEntriesPreviousTo(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        float flTime)
{
  int v2; // edx
  int m_maxElement; // edi
  int i; // esi
  int v5; // eax

  v2 = 0;
  if ( this->m_VarHistory.m_count != 0 )
  {
    m_maxElement = this->m_VarHistory.m_maxElement;
    for ( i = this->m_VarHistory.m_firstElement - m_maxElement; ; ++i )
    {
      v5 = v2 + this->m_VarHistory.m_firstElement;
      if ( v5 >= m_maxElement )
        v5 = i;
      if ( flTime > this->m_VarHistory.m_pElements[v5].flChangeTime )
        break;
      if ( ++v2 >= this->m_VarHistory.m_count )
        return;
    }
    if ( v2 + 3 < this->m_VarHistory.m_count )
      this->m_VarHistory.m_count = v2 + 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034400
// Name: protected: void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::_Extrapolate(class C_AnimationLayer __near *,struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near *,struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::_Extrapolate(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        C_AnimationLayer *pOut,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> *pOld,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> *pNew,
        float flDestinationTime,
        float flMaxExtrapolationAmount)
{
  int v6; // esi
  C_AnimationLayer *v7; // edx
  C_AnimationLayer *v8; // eax
  int v9; // esi
  C_AnimationLayer *v10; // edx
  C_AnimationLayer *p_value; // eax

  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(pOld->flChangeTime - pNew->flChangeTime) & _mask__AbsFloat_) < 0.001
    || pNew->flChangeTime >= flDestinationTime )
  {
    v9 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      v10 = pOut;
      p_value = &pNew->value;
      do
      {
        *(_QWORD *)&v10->m_flLayerAnimtime = *(_QWORD *)&p_value->m_flLayerAnimtime;
        *(_QWORD *)&v10->m_nOrder = *(_QWORD *)&p_value->m_nOrder;
        *(_QWORD *)&v10->m_flPrevCycle.m_Val = *(_QWORD *)&p_value->m_flPrevCycle.m_Val;
        *(_QWORD *)&v10->m_flPlaybackRate.m_Val = *(_QWORD *)&p_value->m_flPlaybackRate.m_Val;
        *(_QWORD *)&v10->m_pOwner = *(_QWORD *)&p_value->m_pOwner;
        ++v9;
        ++p_value;
        ++v10;
      }
      while ( v9 < this->m_nMaxCount );
    }
  }
  else
  {
    v6 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      v7 = pOut;
      v8 = &pNew->value;
      do
      {
        *(_QWORD *)&v7->m_flLayerAnimtime = *(_QWORD *)&v8->m_flLayerAnimtime;
        *(_QWORD *)&v7->m_nOrder = *(_QWORD *)&v8->m_nOrder;
        *(_QWORD *)&v7->m_flPrevCycle.m_Val = *(_QWORD *)&v8->m_flPrevCycle.m_Val;
        *(_QWORD *)&v7->m_flPlaybackRate.m_Val = *(_QWORD *)&v8->m_flPlaybackRate.m_Val;
        *(_QWORD *)&v7->m_pOwner = *(_QWORD *)&v8->m_pOwner;
        ++v6;
        ++v8;
        ++v7;
      }
      while ( v6 < this->m_nMaxCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100344F0
// Name: public: void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::SetMaxCount(float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::SetMaxCount(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        float flCurrentTime,
        int newmax)
{
  unsigned __int8 v3; // al
  bool v5; // cl
  unsigned __int8 *v6; // eax
  int m_nMaxCount; // edi
  C_AnimationLayer *v8; // eax
  int v9; // edx
  CRangeCheckedVar<int,-1,65535,0> *p_m_nSequence; // ecx
  unsigned __int8 *m_bLooping; // ecx

  v3 = newmax;
  v5 = newmax != this->m_nMaxCount;
  if ( newmax < 1 )
    v3 = 1;
  this->m_nMaxCount = v3;
  if ( v5 )
  {
    C_BaseEntity::operator delete(pMem: this->m_bLooping);
    C_BaseEntity::operator delete(pMem: this->m_LastNetworkedValue);
    v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: this->m_nMaxCount);
    m_nMaxCount = this->m_nMaxCount;
    this->m_bLooping = v6;
    v8 = (C_AnimationLayer *)MemAlloc_Alloc(nSize: 40 * m_nMaxCount);
    if ( v8 != nullptr )
    {
      v9 = m_nMaxCount - 1;
      if ( m_nMaxCount - 1 >= 0 )
      {
        p_m_nSequence = &v8->m_nSequence;
        do
        {
          p_m_nSequence[5].m_Val = 0;
          p_m_nSequence[6].m_Val = 0;
          p_m_nSequence->m_Val = 0;
          p_m_nSequence[1].m_Val = 0;
          p_m_nSequence[2].m_Val = 0;
          p_m_nSequence[3].m_Val = 0;
          p_m_nSequence[4].m_Val = 0;
          p_m_nSequence[-3].m_Val = 0;
          p_m_nSequence[-2].m_Val = 0;
          p_m_nSequence += 10;
          --v9;
        }
        while ( v9 >= 0 );
      }
    }
    else
    {
      v8 = nullptr;
    }
    m_bLooping = this->m_bLooping;
    this->m_LastNetworkedValue = v8;
    memset(dst: (int)m_bLooping, value: nullptr, count: this->m_nMaxCount);
    memset(dst: (int)this->m_LastNetworkedValue, value: nullptr, count: 40 * this->m_nMaxCount);
    ((void (__thiscall *)(CInterpolatedVarArrayBase<C_AnimationLayer,0> *, _DWORD))this->Reset)(
      a1: this,
      a2: LODWORD(flCurrentTime));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035460
// Name: public: void CSimpleRingBuffer<struct CInterpolatedVarEntryBase<class C_AnimationLayer,0>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0>>::EnsureCapacity(
        CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0> > *this,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> *capSize)
{
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *m_maxElement; // ebx
  unsigned int v4; // edi
  int v5; // ecx
  unsigned int *v6; // eax
  int v7; // edx
  int v8; // ecx
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *v9; // ebx
  _DWORD *v10; // eax
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *v11; // ecx
  int v12; // ebx
  int v13; // eax
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *v14; // eax
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *m_pElements; // eax
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *pNew; // [esp+10h] [ebp+8h]

  m_maxElement = (CInterpolatedVarEntryBase<C_AnimationLayer,0> *)this->m_maxElement;
  if ( (int)capSize > (int)m_maxElement )
  {
    v4 = (unsigned int)m_maxElement + this->m_growSize * (((int)capSize + this->m_growSize - 1) / this->m_growSize);
    v5 = (44 * (unsigned __int64)v4) >> 32 != 0 ? -1 : 44 * v4;
    v6 = (unsigned int *)MemAlloc_Alloc(nSize: __CFADD__(v5, 4) ? -1 : v5 + 4);
    v7 = 0;
    if ( v6 != nullptr )
    {
      v8 = v4 - 1;
      *v6 = v4;
      v9 = (CInterpolatedVarEntryBase<C_AnimationLayer,0> *)(v6 + 1);
      if ( (int)(v4 - 1) >= 0 )
      {
        v10 = v6 + 5;
        do
        {
          v10[5] = 0;
          v10[6] = 0;
          *v10 = 0;
          v10[1] = 0;
          v10[2] = 0;
          v10[3] = 0;
          v10[4] = 0;
          *(v10 - 3) = 0;
          *(v10 - 2) = 0;
          v10 += 11;
          --v8;
        }
        while ( v8 >= 0 );
      }
    }
    else
    {
      v9 = nullptr;
    }
    pNew = v9;
    if ( this->m_maxElement != 0 )
    {
      v11 = v9;
      do
      {
        v12 = this->m_maxElement;
        v13 = v7 + this->m_firstElement;
        if ( v13 >= v12 )
          v13 -= v12;
        v14 = &this->m_pElements[v13];
        ++v7;
        *(_QWORD *)&v11->flChangeTime = *(_QWORD *)&v14->flChangeTime;
        *(_QWORD *)&v11->value.m_flLayerFadeOuttime = *(_QWORD *)&v14->value.m_flLayerFadeOuttime;
        *(_QWORD *)&v11->value.m_nSequence.m_Val = *(_QWORD *)&v14->value.m_nSequence.m_Val;
        *(_QWORD *)&v11->value.m_flWeight.m_Val = *(_QWORD *)&v14->value.m_flWeight.m_Val;
        *(_QWORD *)&v11->value.m_flCycle.m_Val = *(_QWORD *)&v14->value.m_flCycle.m_Val;
        v11->value.m_nInvalidatePhysicsBits = v14->value.m_nInvalidatePhysicsBits;
        ++v11;
      }
      while ( v7 < this->m_maxElement );
      v9 = pNew;
    }
    m_pElements = this->m_pElements;
    this->m_maxElement = v4;
    this->m_firstElement = 0;
    if ( m_pElements != nullptr )
      C_BaseEntity::operator delete(pMem: &m_pElements[-1].value.m_nInvalidatePhysicsBits);
    this->m_pElements = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035630
// Name: protected: void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::_Interpolate(class C_AnimationLayer __near *,float,struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near *,struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::_Interpolate(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        C_AnimationLayer *out,
        float frac,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> *start,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> *end)
{
  int v7; // edi
  CRangeCheckedVar<float,-2,2,0> *p_m_flCycle; // eax
  C_AnimationLayer *p_value; // ecx
  int m_Val_low; // edx
  float m_Val; // xmm0_4
  float v12; // xmm0_4
  int v13; // edx
  float flPercent; // xmm1_4
  CRangeCheckedVar<float,-2,2,0> *v15; // esi
  CRangeCheckedVar<float,-5,5,0> *p_m_flWeight; // ebx
  int v17; // eax
  CRangeCheckedVar<float,-2,2,0> *v18; // edi
  C_AnimationLayer *v19; // eax
  __int64 v20; // xmm0_8
  float v21; // xmm6_4
  int v22; // ecx
  float v23; // xmm0_4
  float v24; // xmm6_4
  float v25; // eax
  float v26; // xmm6_4
  int v27; // ecx
  float v28; // eax
  float v29; // xmm6_4
  int v30; // eax
  float v31; // xmm0_4
  float v32; // xmm0_4
  C_AnimationLayer result; // [esp+18h] [ebp-2Ch] BYREF
  CInterpolatedVarArrayBase<C_AnimationLayer,0> *v34; // [esp+40h] [ebp-4h]
  C_AnimationLayer *outa; // [esp+4Ch] [ebp+8h]
  int i; // [esp+54h] [ebp+10h]

  v34 = this;
  if ( start == end )
  {
    v7 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      p_m_flCycle = &out->m_flCycle;
      p_value = &end->value;
      do
      {
        *(_QWORD *)&p_m_flCycle[-7].m_Val = *(_QWORD *)&p_value->m_flLayerAnimtime;
        *(_QWORD *)&p_m_flCycle[-5].m_Val = *(_QWORD *)&p_value->m_nOrder;
        *(_QWORD *)&p_m_flCycle[-3].m_Val = *(_QWORD *)&p_value->m_flPrevCycle.m_Val;
        *(_QWORD *)&p_m_flCycle[-1].m_Val = *(_QWORD *)&p_value->m_flPlaybackRate.m_Val;
        *(_QWORD *)&p_m_flCycle[1].m_Val = *(_QWORD *)&p_value->m_pOwner;
        m_Val_low = LODWORD(p_m_flCycle[-4].m_Val);
        if ( m_Val_low >= -1 )
        {
          if ( m_Val_low > 0xFFFF )
            LODWORD(p_m_flCycle[-4].m_Val) = 0xFFFF;
        }
        else
        {
          p_m_flCycle[-4].m_Val = NAN;
        }
        if ( p_m_flCycle->m_Val >= -2.0 )
        {
          if ( p_m_flCycle->m_Val > 2.0 )
            p_m_flCycle->m_Val = 2.0;
        }
        else
        {
          p_m_flCycle->m_Val = -2.0;
        }
        m_Val = p_m_flCycle[-3].m_Val;
        if ( m_Val >= -2.0 )
        {
          if ( m_Val > 2.0 )
            p_m_flCycle[-3].m_Val = 2.0;
        }
        else
        {
          p_m_flCycle[-3].m_Val = -2.0;
        }
        v12 = p_m_flCycle[-2].m_Val;
        if ( v12 >= -5.0 )
        {
          if ( v12 > 5.0 )
            p_m_flCycle[-2].m_Val = 5.0;
        }
        else
        {
          p_m_flCycle[-2].m_Val = -5.0;
        }
        ++v7;
        ++p_value;
        p_m_flCycle += 10;
      }
      while ( v7 < this->m_nMaxCount );
    }
  }
  else
  {
    v13 = 0;
    i = 0;
    if ( this->m_nMaxCount != 0 )
    {
      flPercent = frac;
      v15 = &out->m_flCycle;
      p_m_flWeight = &start->value.m_flWeight;
      v17 = (char *)start - (char *)end;
      v18 = &end->value.m_flCycle;
      for ( outa = (C_AnimationLayer *)v17; ; v17 = (int)outa )
      {
        if ( v34->m_bLooping[v13] != 0 )
        {
          v19 = LoopingLerp(
                  &result,
                  flPercent,
                  from: (C_AnimationLayer *)&p_m_flWeight[-5],
                  to: (C_AnimationLayer *)&v18[-7]);
          flPercent = frac;
          v13 = i;
          *(_QWORD *)&v15[-7].m_Val = *(_QWORD *)&v19->m_flLayerAnimtime;
          *(_QWORD *)&v15[-5].m_Val = *(_QWORD *)&v19->m_nOrder;
          *(_QWORD *)&v15[-3].m_Val = *(_QWORD *)&v19->m_flPrevCycle.m_Val;
          *(_QWORD *)&v15[-1].m_Val = *(_QWORD *)&v19->m_flPlaybackRate.m_Val;
          v20 = *(_QWORD *)&v19->m_pOwner;
        }
        else
        {
          v21 = v18->m_Val - *(float *)((char *)&v18->m_Val + v17);
          v22 = LODWORD(v18[-4].m_Val);
          result.m_flPlaybackRate.m_Val = 0.0;
          v23 = v18[-7].m_Val;
          v24 = (float)(v21 * flPercent) + *(float *)((char *)&v18->m_Val + v17);
          v25 = v18[-3].m_Val;
          result.m_flCycle.m_Val = v24;
          v26 = v18[-2].m_Val - p_m_flWeight->m_Val;
          result.m_flLayerAnimtime = v23;
          result.m_flLayerFadeOuttime = v18[-6].m_Val;
          result.m_nSequence.m_Val = v22;
          v27 = LODWORD(v18[-5].m_Val);
          result.m_flPrevCycle.m_Val = v25;
          v28 = v18[1].m_Val;
          v29 = (float)(v26 * flPercent) + p_m_flWeight->m_Val;
          *(_QWORD *)&v15[-7].m_Val = *(_QWORD *)&result.m_flLayerAnimtime;
          result.m_nOrder = v27;
          *(_QWORD *)&v15[-5].m_Val = *(_QWORD *)&result.m_nOrder;
          result.m_flWeight.m_Val = v29;
          *(_QWORD *)&v15[-3].m_Val = *(_QWORD *)&result.m_flPrevCycle.m_Val;
          *(_QWORD *)&result.m_pOwner = LODWORD(v28);
          *(_QWORD *)&v15[-1].m_Val = *(_QWORD *)&result.m_flPlaybackRate.m_Val;
          v20 = *(_QWORD *)&result.m_pOwner;
        }
        *(_QWORD *)&v15[1].m_Val = v20;
        v30 = LODWORD(v15[-4].m_Val);
        if ( v30 >= -1 )
        {
          if ( v30 > 0xFFFF )
            LODWORD(v15[-4].m_Val) = 0xFFFF;
        }
        else
        {
          v15[-4].m_Val = NAN;
        }
        if ( v15->m_Val >= -2.0 )
        {
          if ( v15->m_Val > 2.0 )
            v15->m_Val = 2.0;
        }
        else
        {
          v15->m_Val = -2.0;
        }
        v31 = v15[-3].m_Val;
        if ( v31 >= -2.0 )
        {
          if ( v31 > 2.0 )
            v15[-3].m_Val = 2.0;
        }
        else
        {
          v15[-3].m_Val = -2.0;
        }
        v32 = v15[-2].m_Val;
        if ( v32 >= -5.0 )
        {
          if ( v32 > 5.0 )
            v15[-2].m_Val = 5.0;
        }
        else
        {
          v15[-2].m_Val = -5.0;
        }
        ++v13;
        v18 += 10;
        p_m_flWeight += 10;
        v15 += 10;
        i = v13;
        if ( v13 >= v34->m_nMaxCount )
          break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035940
// Name: protected: void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::TimeFixup2_Hermite(struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near &,struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near * __near &,struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near * __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::TimeFixup2_Hermite(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> *fixup,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> **prev,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> **start,
        float dt1,
        bool bAllowHermiteFix)
{
  float flChangeTime; // xmm1_4
  float v8; // xmm0_4
  int v9; // eax
  float v10; // xmm2_4
  int v11; // esi
  C_AnimationLayer *p_result; // eax
  char *v13; // eax
  float *v14; // ecx
  int v15; // edx
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  int v19; // ecx
  C_BaseAnimatingOverlay *v20; // edx
  float v21; // xmm0_4
  C_AnimationLayer result; // [esp+18h] [ebp-2Ch] BYREF
  CInterpolatedVarArrayBase<C_AnimationLayer,0> *v23; // [esp+40h] [ebp-4h]
  int i; // [esp+50h] [ebp+Ch]
  float frac; // [esp+58h] [ebp+14h]

  flChangeTime = (*start)->flChangeTime;
  v8 = flChangeTime - (*prev)->flChangeTime;
  v23 = this;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(dt1 - v8) & _mask__AbsFloat_) > 0.000099999997 && v8 > 0.000099999997 )
  {
    v9 = 0;
    fixup->flChangeTime = flChangeTime - dt1;
    v10 = dt1 / v8;
    frac = dt1 / v8;
    i = 0;
    if ( this->m_nMaxCount != 0 )
    {
      v11 = 0;
      do
      {
        if ( this->m_bLooping[v9] != 0 )
        {
          if ( !g_bHermiteFix || !bAllowHermiteFix )
          {
            p_result = LoopingLerp(
                         &result,
                         flPercent: 1.0 - v10,
                         from: (C_AnimationLayer *)((char *)&(*prev)->value + v11),
                         to: (C_AnimationLayer *)((char *)&(*start)->value + v11));
            v10 = frac;
LABEL_14:
            this = v23;
            goto LABEL_15;
          }
          p_result = (C_AnimationLayer *)((char *)&(*prev)->value + v11);
        }
        else
        {
          if ( !g_bHermiteFix || !bAllowHermiteFix )
          {
            v13 = (char *)&(*start)->value + v11;
            v14 = (float *)((char *)&(*prev)->value.m_flLayerAnimtime + v11);
            v15 = *(int *)((char *)&(*start)->value.m_nSequence.m_Val + v11);
            result.m_flCycle.m_Val = (float)((float)(*(float *)((char *)&(*start)->value.m_flCycle.m_Val + v11)
                                                   - *(float *)((char *)&(*prev)->value.m_flCycle.m_Val + v11))
                                           * (float)(1.0 - v10))
                                   + *(float *)((char *)&(*prev)->value.m_flCycle.m_Val + v11);
            v16 = *((float *)v13 + 5) - v14[5];
            result.m_nSequence.m_Val = v15;
            v17 = *(float *)v13;
            v18 = (float)(v16 * (float)(1.0 - v10)) + v14[5];
            v19 = *((_DWORD *)v13 + 2);
            result.m_flPrevCycle.m_Val = *((float *)v13 + 4);
            v20 = *((C_BaseAnimatingOverlay **)v13 + 8);
            result.m_flLayerAnimtime = v17;
            v21 = *((float *)v13 + 1);
            result.m_nInvalidatePhysicsBits = 0;
            result.m_flPlaybackRate.m_Val = 0.0;
            result.m_flWeight.m_Val = v18;
            result.m_nOrder = v19;
            result.m_flLayerFadeOuttime = v21;
            result.m_pOwner = v20;
            p_result = &result;
            goto LABEL_14;
          }
          p_result = (C_AnimationLayer *)((char *)&(*prev)->value + v11);
        }
LABEL_15:
        *(C_AnimationLayer *)((char *)&fixup->value + v11) = *p_result;
        v9 = i + 1;
        v11 += 40;
        i = v9;
      }
      while ( v9 < this->m_nMaxCount );
    }
    *prev = fixup;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035C40
// Name: public: void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::AddToHead(float,class C_AnimationLayer const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::AddToHead(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        float changeTime,
        C_AnimationLayer *values,
        bool bFlushNewer)
{
  unsigned int m_firstElement; // eax
  unsigned int m_maxElement; // ecx
  unsigned __int16 m_count; // dx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0> > *p_m_VarHistory; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // ebx
  int v20; // ebx
  int v21; // eax
  int v22; // ecx
  int v23; // ebx
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *m_pElements; // ebx
  int v25; // eax
  int v26; // ecx
  __int64 v27; // xmm0_8
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *v28; // eax
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *v29; // ecx
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  unsigned int v33; // [esp-10h] [ebp-10h]
  int newslot; // [esp+10h] [ebp+10h]

  if ( bFlushNewer )
  {
    while ( this->m_VarHistory.m_count != 0 )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      if ( m_firstElement >= m_maxElement )
        m_firstElement -= m_maxElement;
      if ( (float)(this->m_VarHistory.m_pElements[m_firstElement].flChangeTime + 0.000099999997) <= changeTime )
        break;
      m_count = this->m_VarHistory.m_count;
      if ( m_count != 0 )
      {
        v8 = this->m_VarHistory.m_maxElement;
        v9 = this->m_VarHistory.m_firstElement + 1;
        if ( v9 >= v8 )
          LOWORD(v9) = v9 - v8;
        this->m_VarHistory.m_firstElement = v9;
        this->m_VarHistory.m_count = m_count - 1;
      }
    }
    p_m_VarHistory = &this->m_VarHistory;
    CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0>>::EnsureCapacity(
      this: &this->m_VarHistory,
      capSize: this->m_VarHistory.m_count + 1);
    v11 = this->m_VarHistory.m_maxElement;
    v12 = this->m_VarHistory.m_firstElement;
    ++this->m_VarHistory.m_count;
    v13 = v12 + v11 - 1;
    if ( v13 >= v11 )
      LOWORD(v13) = v13 - v11;
    this->m_VarHistory.m_firstElement = v13;
    newslot = 0;
  }
  else
  {
    p_m_VarHistory = &this->m_VarHistory;
    CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0>>::EnsureCapacity(
      this: &this->m_VarHistory,
      capSize: this->m_VarHistory.m_count + 1);
    v14 = this->m_VarHistory.m_maxElement;
    v15 = this->m_VarHistory.m_firstElement;
    ++this->m_VarHistory.m_count;
    v16 = v15 + v14 - 1;
    if ( v16 >= v14 )
      LOWORD(v16) = v16 - v14;
    v17 = 1;
    this->m_VarHistory.m_firstElement = v16;
    newslot = 0;
    if ( this->m_VarHistory.m_count > 1u )
    {
      do
      {
        v18 = this->m_VarHistory.m_maxElement;
        v19 = v17 + this->m_VarHistory.m_firstElement;
        if ( v19 >= v18 )
          v19 -= v18;
        if ( changeTime >= p_m_VarHistory->m_pElements[v19].flChangeTime )
          break;
        v20 = this->m_VarHistory.m_firstElement;
        v21 = v20 + v17;
        if ( v20 + v17 >= v18 )
          v21 -= v18;
        v22 = v20 + newslot;
        v23 = this->m_VarHistory.m_maxElement;
        if ( v22 >= v23 )
          v22 -= v23;
        m_pElements = p_m_VarHistory->m_pElements;
        v25 = v21;
        v26 = v22;
        *(_QWORD *)&m_pElements[v26].flChangeTime = *(_QWORD *)&p_m_VarHistory->m_pElements[v25].flChangeTime;
        v27 = *(_QWORD *)&m_pElements[v25].value.m_flLayerFadeOuttime;
        v28 = &m_pElements[v25];
        v29 = &m_pElements[v26];
        *(_QWORD *)&v29->value.m_flLayerFadeOuttime = v27;
        *(_QWORD *)&v29->value.m_nSequence.m_Val = *(_QWORD *)&v28->value.m_nSequence.m_Val;
        *(_QWORD *)&v29->value.m_flWeight.m_Val = *(_QWORD *)&v28->value.m_flWeight.m_Val;
        *(_QWORD *)&v29->value.m_flCycle.m_Val = *(_QWORD *)&v28->value.m_flCycle.m_Val;
        v29->value.m_nInvalidatePhysicsBits = v28->value.m_nInvalidatePhysicsBits;
        newslot = v17++;
      }
      while ( v17 < this->m_VarHistory.m_count );
    }
  }
  v30 = p_m_VarHistory->m_maxElement;
  v31 = newslot + p_m_VarHistory->m_firstElement;
  if ( v31 >= v30 )
    v31 -= v30;
  v32 = (int)&p_m_VarHistory->m_pElements[v31];
  v33 = 40 * this->m_nMaxCount;
  *(float *)v32 = changeTime;
  memcpy(dst: (unsigned __int8 *)(v32 + 4), src: (unsigned __int8 *)values, count: v33);
}

//------------------------------------------------------------------------------
// Address: 0x10035F20
// Name: public: virtual void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::Reset(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::Reset(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        float flCurrentTime)
{
  C_AnimationLayer *m_pValue; // eax

  *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
  m_pValue = this->m_pValue;
  if ( m_pValue != nullptr )
  {
    CInterpolatedVarArrayBase<C_AnimationLayer,0>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: m_pValue,
      bFlushNewer: false);
    CInterpolatedVarArrayBase<C_AnimationLayer,0>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: this->m_pValue,
      bFlushNewer: false);
    CInterpolatedVarArrayBase<C_AnimationLayer,0>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: this->m_pValue,
      bFlushNewer: false);
    memcpy(
      dst: (unsigned __int8 *)this->m_LastNetworkedValue,
      src: (unsigned __int8 *)this->m_pValue,
      count: 40 * this->m_nMaxCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035FA0
// Name: public: virtual void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::Copy(class IInterpolatedVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::Copy(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        IInterpolatedVar *pInSrc)
{
  unsigned __int16 *v3; // edi
  unsigned __int8 m_nMaxCount; // al
  int v5; // edx
  int v6; // esi
  int v7; // eax
  C_AnimationLayer *m_LastNetworkedValue; // ecx
  __int64 v9; // xmm0_8
  _QWORD *v10; // eax
  _QWORD *p_m_flLayerAnimtime; // ecx
  int m_maxElement; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // ecx
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *v17; // edx
  int v18; // eax
  int v19; // eax
  unsigned int v20; // [esp-8h] [ebp-10h]
  int i; // [esp+10h] [ebp+8h]

  v3 = (unsigned __int16 *)__RTDynamicCast(
                             inptr: pInSrc,
                             VfDelta: 0,
                             SrcType: &IInterpolatedVar `RTTI Type Descriptor',
                             TargetType: &CInterpolatedVarArrayBase<C_AnimationLayer,0> `RTTI Type Descriptor',
                             isReference: 0);
  if ( v3 != nullptr )
  {
    m_nMaxCount = this->m_nMaxCount;
    if ( *((_BYTE *)v3 + 29) == m_nMaxCount )
    {
      v5 = 0;
      if ( m_nMaxCount != 0 )
      {
        v6 = 0;
        do
        {
          v7 = *((_DWORD *)v3 + 5);
          m_LastNetworkedValue = this->m_LastNetworkedValue;
          *(_QWORD *)&m_LastNetworkedValue[v6].m_flLayerAnimtime = *(_QWORD *)(v7 + v6 * 40);
          v9 = *(_QWORD *)(v7 + v6 * 40 + 8);
          v10 = (_QWORD *)(v6 * 40 + v7);
          p_m_flLayerAnimtime = (_QWORD *)&m_LastNetworkedValue[v6].m_flLayerAnimtime;
          p_m_flLayerAnimtime[1] = v9;
          p_m_flLayerAnimtime[2] = v10[2];
          p_m_flLayerAnimtime[3] = v10[3];
          p_m_flLayerAnimtime[4] = v10[4];
          this->m_bLooping[v5] = *(_BYTE *)(v5 + *((_DWORD *)v3 + 8));
          ++v5;
          ++v6;
        }
        while ( v5 < this->m_nMaxCount );
      }
      this->m_LastNetworkedTime = *((float *)v3 + 6);
      *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
      i = 0;
      if ( v3[8] != 0 )
      {
        do
        {
          CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0>>::EnsureCapacity(
            this: &this->m_VarHistory,
            capSize: this->m_VarHistory.m_count + 1);
          ++this->m_VarHistory.m_count;
          m_maxElement = this->m_VarHistory.m_maxElement;
          v13 = this->m_VarHistory.m_count + this->m_VarHistory.m_firstElement - 1;
          if ( v13 >= m_maxElement )
            v13 -= m_maxElement;
          v14 = v13 + this->m_VarHistory.m_firstElement;
          v15 = this->m_VarHistory.m_maxElement;
          if ( v14 >= v15 )
            v14 -= v15;
          v16 = v3[6];
          v17 = &this->m_VarHistory.m_pElements[v14];
          v18 = i + v3[7];
          if ( v18 >= v16 )
            v18 -= v16;
          v19 = *((_DWORD *)v3 + 2) + 44 * v18;
          v20 = 40 * this->m_nMaxCount;
          v17->flChangeTime = *(float *)v19;
          memcpy(dst: (unsigned __int8 *)&v17->value, src: (unsigned __int8 *)(v19 + 4), count: v20);
          ++i;
        }
        while ( i < v3[8] );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100360F0
// Name: public: bool CInterpolatedVarArrayBase<class C_AnimationLayer,0>::NoteChanged(float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::NoteChanged(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        float flCurrentTime,
        float flChangeTime,
        float interpolation_amount,
        bool bUpdateLastNetworkedValue)
{
  char v6; // bl
  unsigned int m_firstElement; // ecx
  unsigned int m_maxElement; // edx
  unsigned int v9; // eax
  C_AnimationLayer *m_pValue; // edi
  C_AnimationLayer *p_value; // ecx
  int v12; // ecx
  int v13; // edi
  int i; // edx
  int v15; // eax
  bool bRet; // [esp+1Bh] [ebp-1h]

  v6 = 1;
  bRet = true;
  if ( this->m_VarHistory.m_count != 0 )
  {
    m_firstElement = this->m_VarHistory.m_firstElement;
    m_maxElement = this->m_VarHistory.m_maxElement;
    v9 = 40 * this->m_nMaxCount;
    if ( m_firstElement >= m_maxElement )
      m_firstElement -= m_maxElement;
    m_pValue = this->m_pValue;
    p_value = &this->m_VarHistory.m_pElements[m_firstElement].value;
    if ( v9 < 4 )
    {
LABEL_7:
      if ( v9 == 0
        || LOBYTE(p_value->m_flLayerAnimtime) == LOBYTE(m_pValue->m_flLayerAnimtime)
        && (v9 <= 1
         || BYTE1(p_value->m_flLayerAnimtime) == BYTE1(m_pValue->m_flLayerAnimtime)
         && (v9 <= 2 || BYTE2(p_value->m_flLayerAnimtime) == BYTE2(m_pValue->m_flLayerAnimtime))) )
      {
        v6 = 0;
        bRet = false;
      }
    }
    else
    {
      while ( LODWORD(m_pValue->m_flLayerAnimtime) == LODWORD(p_value->m_flLayerAnimtime) )
      {
        v9 -= 4;
        p_value = (C_AnimationLayer *)((char *)p_value + 4);
        m_pValue = (C_AnimationLayer *)((char *)m_pValue + 4);
        if ( v9 < 4 )
          goto LABEL_7;
      }
    }
  }
  CInterpolatedVarArrayBase<C_AnimationLayer,0>::AddToHead(
    this,
    changeTime: flChangeTime,
    values: this->m_pValue,
    bFlushNewer: true);
  if ( bUpdateLastNetworkedValue )
    this->NoteLastNetworkedValue(this);
  v12 = 0;
  if ( this->m_VarHistory.m_count == 0 )
    return v6;
  v13 = this->m_VarHistory.m_maxElement;
  for ( i = this->m_VarHistory.m_firstElement - v13; ; ++i )
  {
    v15 = v12 + this->m_VarHistory.m_firstElement;
    if ( v15 >= v13 )
      v15 = i;
    if ( (float)((float)(flCurrentTime - interpolation_amount) - 0.050000001) > this->m_VarHistory.m_pElements[v15].flChangeTime )
      break;
    if ( ++v12 >= this->m_VarHistory.m_count )
      return bRet;
  }
  if ( v12 + 3 >= this->m_VarHistory.m_count )
    return bRet;
  this->m_VarHistory.m_count = v12 + 3;
  return bRet;
}

//------------------------------------------------------------------------------
// Address: 0x10036210
// Name: protected: void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::_Interpolate_Hermite(class C_AnimationLayer __near *,float,struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near *,struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near *,struct CInterpolatedVarEntryBase<class C_AnimationLayer,0> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::_Interpolate_Hermite(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        C_AnimationLayer *out,
        float frac,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> *prev,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> *start,
        CInterpolatedVarEntryBase<C_AnimationLayer,0> *end,
        bool looping)
{
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *v8; // esi
  float flChangeTime; // xmm0_4
  C_AnimationLayer *v10; // eax
  CRangeCheckedVar<float,-2,2,0> *p_m_flCycle; // ebx
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *v12; // ecx
  C_AnimationLayer *p_value; // edi
  _QWORD *p_m_Val; // esi
  C_AnimationLayer *v15; // eax
  int m_Val_low; // eax
  float m_Val; // xmm0_4
  float v18; // xmm0_4
  int v19; // xmm1_4
  int m_nMaxCount; // ecx
  const C_AnimationLayer *v21; // [esp-4h] [ebp-7Ch]
  C_AnimationLayer *v22; // [esp+4h] [ebp-74h]
  C_AnimationLayer *v23; // [esp+Ch] [ebp-6Ch]
  CInterpolatedVarEntryBase<C_AnimationLayer,0> fixup; // [esp+1Ch] [ebp-5Ch] BYREF
  C_AnimationLayer result; // [esp+48h] [ebp-30h] BYREF
  CInterpolatedVarArrayBase<C_AnimationLayer,0> *v26; // [esp+70h] [ebp-8h]
  CDisableRangeChecks disableRangeChecks; // [esp+77h] [ebp-1h] BYREF
  C_AnimationLayer *outa; // [esp+80h] [ebp+8h]

  v26 = this;
  CDisableRangeChecks::CDisableRangeChecks(this: &disableRangeChecks);
  v8 = start;
  fixup.value.m_flLayerAnimtime = 0.0;
  fixup.value.m_flLayerFadeOuttime = 0.0;
  flChangeTime = end->flChangeTime;
  memset(&fixup.value.m_nSequence, 0, 28);
  CInterpolatedVarArrayBase<C_AnimationLayer,0>::TimeFixup2_Hermite(
    this,
    &fixup,
    &prev,
    &start,
    dt1: flChangeTime - start->flChangeTime,
    bAllowHermiteFix: true);
  start = nullptr;
  if ( this->m_nMaxCount != 0 )
  {
    v10 = (C_AnimationLayer *)((char *)end - (char *)v8);
    p_m_flCycle = &out->m_flCycle;
    v12 = (CInterpolatedVarEntryBase<C_AnimationLayer,0> *)((char *)prev - (char *)v8);
    p_value = &v8->value;
    outa = (C_AnimationLayer *)((char *)end - (char *)v8);
    end = (CInterpolatedVarEntryBase<C_AnimationLayer,0> *)((char *)prev - (char *)v8);
    while ( 1 )
    {
      v23 = (C_AnimationLayer *)((char *)v10 + (_DWORD)p_value);
      v22 = (C_AnimationLayer *)((char *)v12 + (_DWORD)p_value);
      p_m_Val = (_QWORD *)&p_m_flCycle[-7].m_Val;
      v21 = (const C_AnimationLayer *)&p_m_flCycle[-7];
      v15 = *((_BYTE *)&start->flChangeTime + (unsigned int)v26->m_bLooping) != 0
          ? LoopingLerp_Hermite(&result, current: v21, flPercent: frac, prev: v22, from: p_value, to: v23)
          : Lerp_Hermite(&result, current: v21, flPercent: frac, prev: v22, from: p_value, to: v23);
      *p_m_Val = *(_QWORD *)&v15->m_flLayerAnimtime;
      p_m_Val[1] = *(_QWORD *)&v15->m_nOrder;
      p_m_Val[2] = *(_QWORD *)&v15->m_flPrevCycle.m_Val;
      p_m_Val[3] = *(_QWORD *)&v15->m_flPlaybackRate.m_Val;
      p_m_Val[4] = *(_QWORD *)&v15->m_pOwner;
      m_Val_low = LODWORD(p_m_flCycle[-4].m_Val);
      if ( m_Val_low >= -1 )
      {
        if ( m_Val_low > 0xFFFF )
          LODWORD(p_m_flCycle[-4].m_Val) = 0xFFFF;
      }
      else
      {
        p_m_flCycle[-4].m_Val = NAN;
      }
      if ( p_m_flCycle->m_Val >= -2.0 )
      {
        if ( p_m_flCycle->m_Val > 2.0 )
          p_m_flCycle->m_Val = 2.0;
      }
      else
      {
        p_m_flCycle->m_Val = -2.0;
      }
      m_Val = p_m_flCycle[-3].m_Val;
      if ( m_Val >= -2.0 )
      {
        if ( m_Val > 2.0 )
          p_m_flCycle[-3].m_Val = 2.0;
      }
      else
      {
        p_m_flCycle[-3].m_Val = -2.0;
      }
      v18 = p_m_flCycle[-2].m_Val;
      v19 = -1063256064;
      if ( v18 < -5.0 || (v19 = 1084227584, v18 > 5.0) )
        LODWORD(p_m_flCycle[-2].m_Val) = v19;
      m_nMaxCount = v26->m_nMaxCount;
      ++p_value;
      p_m_flCycle += 10;
      start = (CInterpolatedVarEntryBase<C_AnimationLayer,0> *)((char *)start + 1);
      if ( (int)start >= m_nMaxCount )
        break;
      v12 = end;
      v10 = outa;
    }
  }
  CDisableRangeChecks::~CDisableRangeChecks(this: &disableRangeChecks);
}

//------------------------------------------------------------------------------
// Address: 0x100363D0
// Name: public: virtual bool CInterpolatedVarArrayBase<class C_AnimationLayer,0>::NoteChanged(float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::NoteChanged(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        float flCurrentTime,
        float flChangeTime,
        bool bUpdateLastNetworkedValue)
{
  return CInterpolatedVarArrayBase<C_AnimationLayer,0>::NoteChanged(
           this,
           flCurrentTime,
           flChangeTime,
           interpolation_amount: this->m_InterpolationAmount,
           bUpdateLastNetworkedValue);
}

//------------------------------------------------------------------------------
// Address: 0x10036410
// Name: public: int CInterpolatedVarArrayBase<class C_AnimationLayer,0>::Interpolate(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::Interpolate(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        float currentTime,
        float interpolation_amount)
{
  int m_firstElement; // eax
  int m_maxElement; // ebx
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  int newer; // ebx
  int v11; // eax
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // edx
  CInterpolatedVarEntryBase<C_AnimationLayer,0> *v20; // [esp+8h] [ebp-34h]
  float flMaxExtrapolationAmount; // [esp+10h] [ebp-2Ch]
  CInterpolatedVarArrayBase<C_AnimationLayer,0>::CInterpolationInfo info; // [esp+20h] [ebp-1Ch] BYREF
  int realOlder; // [esp+34h] [ebp-8h]
  int noMoreChanges; // [esp+38h] [ebp-4h] BYREF

  noMoreChanges = 0;
  if ( CInterpolatedVarArrayBase<C_AnimationLayer,0>::GetInterpolationInfo(
         this,
         pInfo: &info,
         currentTime,
         interpolation_amount,
         pNoMoreChanges: &noMoreChanges) )
  {
    if ( info.m_bHermite )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      v6 = m_firstElement + info.newer;
      if ( m_firstElement + info.newer >= m_maxElement )
        v6 -= m_maxElement;
      v7 = m_firstElement + info.older;
      if ( m_firstElement + info.older >= m_maxElement )
        v7 -= m_maxElement;
      v8 = this->m_VarHistory.m_maxElement;
      v9 = info.oldest + m_firstElement;
      if ( v9 >= v8 )
        v9 -= v8;
      CInterpolatedVarArrayBase<C_AnimationLayer,0>::_Interpolate_Hermite(
        this,
        out: this->m_pValue,
        frac: info.frac,
        prev: &this->m_VarHistory.m_pElements[v9],
        start: &this->m_VarHistory.m_pElements[v7],
        end: &this->m_VarHistory.m_pElements[v6],
        looping: false);
      goto LABEL_28;
    }
    newer = info.newer;
    if ( info.newer == info.older )
    {
      v11 = info.newer + 1;
      realOlder = info.newer + 1;
      if ( CInterpolationContext::s_bAllowExtrapolation
        && v11 >= 0
        && v11 < this->m_VarHistory.m_count
        && CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0>>::operator[](
             this: &this->m_VarHistory,
             i: info.newer + 1)->flChangeTime != 0.0
        && interpolation_amount > 0.000001
        && this->m_LastNetworkedTime >= CInterpolationContext::s_flLastTimeStamp )
      {
        flMaxExtrapolationAmount = cl_extrapolate_amount.m_pParent->m_Value.m_fValue;
        v20 = CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0>>::operator[](
                this: &this->m_VarHistory,
                i: newer);
        v12 = CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0>>::operator[](
                this: &this->m_VarHistory,
                i: realOlder);
        CInterpolatedVarArrayBase<C_AnimationLayer,0>::_Extrapolate(
          this,
          pOut: this->m_pValue,
          pOld: v12,
          pNew: v20,
          flDestinationTime: currentTime - interpolation_amount,
          flMaxExtrapolationAmount);
LABEL_28:
        CInterpolatedVarArrayBase<C_AnimationLayer,0>::RemoveEntriesPreviousTo(
          this,
          flTime: (float)(currentTime - interpolation_amount) - 0.050000001);
        return noMoreChanges;
      }
      v13 = this->m_VarHistory.m_firstElement;
      v14 = this->m_VarHistory.m_maxElement;
      v15 = v13 + newer;
      if ( v13 + newer >= v14 )
        v15 -= v14;
      v16 = info.older + v13;
      if ( v16 >= v14 )
        v16 -= v14;
    }
    else
    {
      v17 = this->m_VarHistory.m_firstElement;
      v18 = this->m_VarHistory.m_maxElement;
      v15 = v17 + info.newer;
      if ( v17 + info.newer >= v18 )
        v15 -= v18;
      v16 = info.older + v17;
      if ( v16 >= v18 )
        v16 -= v18;
    }
    CInterpolatedVarArrayBase<C_AnimationLayer,0>::_Interpolate(
      this,
      out: this->m_pValue,
      frac: info.frac,
      start: &this->m_VarHistory.m_pElements[v16],
      end: &this->m_VarHistory.m_pElements[v15]);
    goto LABEL_28;
  }
  return noMoreChanges;
}

//------------------------------------------------------------------------------
// Address: 0x10036610
// Name: public: virtual int CInterpolatedVarArrayBase<class C_AnimationLayer,0>::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::Interpolate(
        CInterpolatedVarArrayBase<C_AnimationLayer,0> *this,
        float currentTime)
{
  return CInterpolatedVarArrayBase<C_AnimationLayer,0>::Interpolate(
           this,
           currentTime,
           interpolation_amount: this->m_InterpolationAmount);
}

//------------------------------------------------------------------------------
// Address: 0x100395F0
// Name: protected: void CInterpolatedVarArrayBase<class Vector,0>::TimeFixup2_Hermite(struct CInterpolatedVarEntryBase<class Vector,0> __near &,struct CInterpolatedVarEntryBase<class Vector,0> __near * __near &,struct CInterpolatedVarEntryBase<class Vector,0> __near * __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::TimeFixup2_Hermite(
        CInterpolatedVarArrayBase<Vector,0> *this,
        CInterpolatedVarEntryBase<Vector,0> *fixup,
        CInterpolatedVarEntryBase<Vector,0> **prev,
        CInterpolatedVarEntryBase<Vector,0> **start,
        float dt1,
        bool bAllowHermiteFix)
{
  int v6; // ebx
  float flChangeTime; // xmm1_4
  int v8; // edi
  float v9; // xmm0_4
  CInterpolatedVarEntryBase<Vector,0> *v10; // edx
  bool v11; // zf
  float v12; // xmm7_4
  int v13; // ecx
  Vector *p_value; // esi
  float *v15; // eax
  float *v16; // edx
  float v17; // ecx
  float v18; // edx
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26[3]; // [esp+0h] [ebp-44h] BYREF
  float v27[3]; // [esp+Ch] [ebp-38h] BYREF
  __int64 v28; // [esp+18h] [ebp-2Ch]
  float v29; // [esp+20h] [ebp-24h]
  __int64 v30; // [esp+24h] [ebp-20h]
  float v31; // [esp+2Ch] [ebp-18h]
  float frac; // [esp+30h] [ebp-14h]
  int v33; // [esp+34h] [ebp-10h]
  int v34; // [esp+38h] [ebp-Ch]
  int v35; // [esp+3Ch] [ebp-8h]
  CInterpolatedVarArrayBase<Vector,0> *v36; // [esp+40h] [ebp-4h]
  int i; // [esp+54h] [ebp+10h]

  v6 = (int)*start;
  flChangeTime = (*start)->flChangeTime;
  v8 = (int)*prev;
  v9 = flChangeTime - (*prev)->flChangeTime;
  v36 = this;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(dt1 - v9) & _mask__AbsFloat_) > 0.000099999997 && v9 > 0.000099999997 )
  {
    v10 = fixup;
    fixup->flChangeTime = flChangeTime - dt1;
    v11 = this->m_nMaxCount == 0;
    v12 = dt1 / v9;
    frac = dt1 / v9;
    i = 0;
    if ( !v11 )
    {
      v33 = v6 - v8;
      v35 = -12 - v8;
      v34 = v6 - (_DWORD)fixup;
      v13 = 0;
      p_value = &fixup->value;
      v15 = (float *)(v8 + 12);
      do
      {
        if ( v36->m_bLooping[v13] != 0 )
        {
          if ( g_bHermiteFix && bAllowHermiteFix )
          {
            v16 = v15 - 2;
          }
          else
          {
            v17 = *(float *)((char *)v15 + v35 + v6 + 12);
            v28 = *(_QWORD *)((char *)v15 + v35 + v6 + 4);
            v18 = *(float *)((char *)v15 + v35 + v8 + 12);
            v30 = *(_QWORD *)((char *)v15 + v35 + v8 + 4);
            v31 = v18;
            v19 = 1.0 - (float)(1.0 - v12);
            v29 = v17;
            v20 = (float)(1.0 - v12) * v17;
            v13 = i;
            v27[0] = (float)((float)(1.0 - v12) * *(float *)&v28) + (float)(*(float *)&v30 * v19);
            v27[1] = (float)((float)(1.0 - v12) * *((float *)&v28 + 1)) + (float)(*((float *)&v30 + 1) * v19);
            v27[2] = v20 + (float)(v18 * v19);
            v16 = v27;
          }
        }
        else if ( g_bHermiteFix && bAllowHermiteFix )
        {
          v16 = v15 - 2;
        }
        else
        {
          v21 = *v15;
          v22 = 1.0 - v12;
          v23 = (float)(1.0 - v12) * (float)(*(float *)((char *)v15 + v33) - *v15);
          v24 = *(v15 - 2) + (float)((float)(1.0 - v12) * (float)(*(float *)((char *)&p_value->x + v34) - *(v15 - 2)));
          v12 = frac;
          v25 = *(v15 - 1) + (float)(v22 * (float)(*(float *)((char *)v15 + v33 - 4) - *(v15 - 1)));
          v26[0] = v24;
          v26[1] = v25;
          v26[2] = v21 + v23;
          v16 = v26;
        }
        ++v13;
        p_value->x = *v16;
        v15 += 3;
        ++p_value;
        p_value[-1].y = v16[1];
        i = v13;
        *(float *)((char *)v15 + (_DWORD)fixup - v8 - 12) = v16[2];
      }
      while ( v13 < v36->m_nMaxCount );
      v10 = fixup;
    }
    *prev = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B710
// Name: protected: void CInterpolatedVarArrayBase<class Vector,0>::_Derivative_Linear(class Vector __near *,struct CInterpolatedVarEntryBase<class Vector,0> __near *,struct CInterpolatedVarEntryBase<class Vector,0> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::_Derivative_Linear(
        CInterpolatedVarArrayBase<Vector,0> *this,
        Vector *out,
        CInterpolatedVarEntryBase<Vector,0> *start,
        CInterpolatedVarEntryBase<Vector,0> *end)
{
  int v5; // edi
  float v6; // xmm3_4
  Vector *v7; // esi
  Vector *p_value; // edx
  float *p_y; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  int v12; // esi
  float *p_z; // edx
  float *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  CInterpolatedVarEntryBase<Vector,0> *starta; // [esp+20h] [ebp+Ch]

  if ( start == end
    || COERCE_FLOAT(COERCE_UNSIGNED_INT(start->flChangeTime - end->flChangeTime) & _mask__AbsFloat_) < 0.000099999997 )
  {
    v12 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      p_z = &out->z;
      v14 = &start->value.z;
      do
      {
        v15 = *(v14 - 1) * 0.0;
        v16 = *v14 * 0.0;
        *(p_z - 2) = *(v14 - 2) * 0.0;
        *(p_z - 1) = v15;
        *p_z = v16;
        ++v12;
        v14 += 3;
        p_z += 3;
      }
      while ( v12 < this->m_nMaxCount );
    }
  }
  else
  {
    v5 = 0;
    v6 = 1.0 / (float)(end->flChangeTime - start->flChangeTime);
    if ( this->m_nMaxCount != 0 )
    {
      v7 = out;
      p_value = &end->value;
      starta = (CInterpolatedVarEntryBase<Vector,0> *)((char *)end - (char *)start);
      p_y = &start->value.y;
      do
      {
        v10 = p_value->x - *(p_y - 1);
        v11 = *(float *)((char *)p_y + (_DWORD)starta) - *p_y;
        *(float *)((char *)p_y + (char *)out - (char *)start) = (float)(p_value->z - p_y[1]) * v6;
        v7->x = v10 * v6;
        *(float *)((char *)&p_value->x + (char *)out - (char *)end) = v11 * v6;
        ++v5;
        p_y += 3;
        ++p_value;
        ++v7;
      }
      while ( v5 < this->m_nMaxCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B850
// Name: protected: void CInterpolatedVarArrayBase<class Vector,0>::_Extrapolate(class Vector __near *,struct CInterpolatedVarEntryBase<class Vector,0> __near *,struct CInterpolatedVarEntryBase<class Vector,0> __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::_Extrapolate(
        CInterpolatedVarArrayBase<Vector,0> *this,
        Vector *pOut,
        CInterpolatedVarEntryBase<Vector,0> *pOld,
        CInterpolatedVarEntryBase<Vector,0> *pNew,
        float flDestinationTime,
        float flMaxExtrapolationAmount)
{
  float flChangeTime; // xmm0_4
  float v7; // xmm1_4
  int v8; // edi
  float v9; // xmm0_4
  float *v10; // eax
  int v11; // esi
  float *p_y; // edx
  int v13; // ebx
  float v14; // xmm7_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  int v17; // edi
  float *p_z; // edx
  float *v19; // eax
  Vector *pOuta; // [esp+8h] [ebp+8h]

  flChangeTime = pNew->flChangeTime;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(pOld->flChangeTime - pNew->flChangeTime) & _mask__AbsFloat_) < 0.001
    || flChangeTime >= flDestinationTime )
  {
    v17 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      p_z = &pOut->z;
      v19 = &pNew->value.z;
      do
      {
        ++v17;
        *(p_z - 2) = *(v19 - 2);
        v19 += 3;
        p_z += 3;
        *(p_z - 4) = *(v19 - 4);
        *(p_z - 3) = *(v19 - 3);
      }
      while ( v17 < this->m_nMaxCount );
    }
  }
  else
  {
    v7 = flDestinationTime - flChangeTime;
    if ( flMaxExtrapolationAmount <= (float)(flDestinationTime - flChangeTime) )
      v7 = flMaxExtrapolationAmount;
    v8 = 0;
    v9 = flChangeTime - pOld->flChangeTime;
    if ( this->m_nMaxCount != 0 )
    {
      v10 = &pOld->value.z;
      v11 = (char *)pNew - (char *)pOld;
      p_y = &pOut->y;
      v13 = (char *)pNew - (char *)pOut;
      v14 = (float)((float)(1.0 / v9) * v7) + 1.0;
      for ( pOuta = (Vector *)((char *)pNew - (char *)pOut); ; v13 = (int)pOuta )
      {
        v15 = *(v10 - 1) + (float)(v14 * (float)(*(float *)((char *)v10 + v11 - 4) - *(v10 - 1)));
        v16 = *v10 + (float)(v14 * (float)(*(float *)((char *)v10 + v11) - *v10));
        *(p_y - 1) = *(v10 - 2) + (float)((float)(*(float *)((char *)p_y + v13) - *(v10 - 2)) * v14);
        *p_y = v15;
        p_y[1] = v16;
        ++v8;
        v10 += 3;
        p_y += 3;
        if ( v8 >= this->m_nMaxCount )
          break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B990
// Name: protected: void CInterpolatedVarArrayBase<class Vector,0>::_Interpolate(class Vector __near *,float,struct CInterpolatedVarEntryBase<class Vector,0> __near *,struct CInterpolatedVarEntryBase<class Vector,0> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::_Interpolate(
        CInterpolatedVarArrayBase<Vector,0> *this,
        Vector *out,
        float frac,
        CInterpolatedVarEntryBase<Vector,0> *start,
        CInterpolatedVarEntryBase<Vector,0> *end)
{
  int v5; // edi
  float *p_z; // edx
  float *v7; // eax
  float *p_y; // eax
  float *v9; // edx
  int v10; // esi
  float v11; // xmm3_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  __int64 v14; // [esp+8h] [ebp-18h]
  __int64 v15; // [esp+14h] [ebp-Ch]
  CInterpolatedVarEntryBase<Vector,0> *starta; // [esp+30h] [ebp+10h]

  v5 = 0;
  if ( start == end )
  {
    if ( this->m_nMaxCount != 0 )
    {
      p_z = &out->z;
      v7 = &end->value.z;
      do
      {
        ++v5;
        *(p_z - 2) = *(v7 - 2);
        v7 += 3;
        p_z += 3;
        *(p_z - 4) = *(v7 - 4);
        *(p_z - 3) = *(v7 - 3);
      }
      while ( v5 < this->m_nMaxCount );
    }
  }
  else if ( this->m_nMaxCount != 0 )
  {
    p_y = &out->y;
    v9 = &start->value.z;
    v10 = (char *)end - (char *)out;
    starta = (CInterpolatedVarEntryBase<Vector,0> *)((char *)end - (char *)start);
    do
    {
      if ( this->m_bLooping[v5] != 0 )
      {
        v14 = *(_QWORD *)((char *)p_y + v10);
        v15 = *((_QWORD *)v9 - 1);
        v11 = (float)(*(float *)((char *)p_y + v10 + 8) * frac) + (float)(*v9 * (float)(1.0 - frac));
        *(p_y - 1) = (float)(*(float *)&v14 * frac) + (float)(*(float *)&v15 * (float)(1.0 - frac));
        *p_y = (float)(*((float *)&v14 + 1) * frac) + (float)((float)(1.0 - frac) * *((float *)&v15 + 1));
        p_y[1] = v11;
      }
      else
      {
        v12 = *(v9 - 1) + (float)((float)(*(float *)((char *)v9 + (_DWORD)starta - 4) - *(v9 - 1)) * frac);
        v13 = *v9 + (float)((float)(*(float *)((char *)v9 + (_DWORD)starta) - *v9) * frac);
        *(p_y - 1) = *(v9 - 2) + (float)((float)(*(float *)((char *)p_y + v10) - *(v9 - 2)) * frac);
        *p_y = v12;
        p_y[1] = v13;
      }
      ++v5;
      v9 += 3;
      p_y += 3;
    }
    while ( v5 < this->m_nMaxCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E090
// Name: protected: void CInterpolatedVarArrayBase<class Vector,0>::_Derivative_Hermite_SmoothVelocity(class Vector __near *,float,struct CInterpolatedVarEntryBase<class Vector,0> __near *,struct CInterpolatedVarEntryBase<class Vector,0> __near *,struct CInterpolatedVarEntryBase<class Vector,0> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::_Derivative_Hermite_SmoothVelocity(
        CInterpolatedVarArrayBase<Vector,0> *this,
        Vector *out,
        float frac,
        CInterpolatedVarEntryBase<Vector,0> *b,
        CInterpolatedVarEntryBase<Vector,0> *c,
        CInterpolatedVarEntryBase<Vector,0> *d,
        int bAllowHermiteFix)
{
  CInterpolatedVarEntryBase<Vector,0> *v7; // ebx
  CInterpolatedVarEntryBase<Vector,0> *v8; // esi
  float dt1; // xmm0_4
  bool v11; // zf
  float *p_z; // eax
  float *p_y; // edx
  int v14; // edi
  float *v15; // ecx
  float v16; // xmm2_4
  float v17; // xmm3_4
  CInterpolatedVarArrayBase<Vector,0> *v18; // ebx
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm1_4
  CInterpolatedVarEntryBase<Vector,0> *v25; // edi
  int m_nMaxCount; // ebx
  CInterpolatedVarEntryBase<Vector,0> fixup; // [esp+14h] [ebp-30h] BYREF
  Vector prevVel; // [esp+24h] [ebp-20h]
  CInterpolatedVarArrayBase<Vector,0> *v29; // [esp+30h] [ebp-14h]
  char *v30; // [esp+34h] [ebp-10h]
  float v31; // [esp+38h] [ebp-Ch]
  int v32; // [esp+3Ch] [ebp-8h]
  char *v33; // [esp+40h] [ebp-4h]
  Vector *outa; // [esp+4Ch] [ebp+8h]

  v7 = d;
  v8 = c;
  dt1 = d->flChangeTime - c->flChangeTime;
  v29 = this;
  CInterpolatedVarArrayBase<Vector,0>::TimeFixup2_Hermite(this, &fixup, prev: &b, start: &c, dt1, bAllowHermiteFix);
  v11 = this->m_nMaxCount == 0;
  c = nullptr;
  if ( !v11 )
  {
    p_z = &b->value.z;
    v32 = (char *)v7 - (char *)b;
    v33 = (char *)((char *)d - (char *)v8);
    bAllowHermiteFix = (char *)v8 - (char *)b;
    v30 = (char *)((char *)out - (char *)v8);
    p_y = &out->y;
    v14 = (char *)d - (char *)out;
    v15 = &v8->value.y;
    for ( outa = (Vector *)((char *)d - (char *)out); ; v14 = (int)outa )
    {
      v16 = *(v15 - 1) - *(p_z - 2);
      v17 = *v15 - *(p_z - 1);
      v18 = v29;
      v19 = 1.0 / (float)(v8->flChangeTime - b->flChangeTime);
      v31 = *(float *)((char *)p_z + bAllowHermiteFix);
      prevVel.z = (float)(v31 - *p_z) * v19;
      v20 = v19 * v16;
      v21 = v19 * v17;
      v22 = 1.0 / (float)(d->flChangeTime - v8->flChangeTime);
      v23 = (float)((float)(v22 * (float)(*(float *)((char *)p_y + v14) - *(v15 - 1))) - (float)(v19 * v16)) * frac;
      v24 = (float)((float)((float)(*(float *)((char *)v15 + (_DWORD)v33) - *v15) * v22) - v21) * frac;
      *(float *)((char *)v15 + (_DWORD)v30) = (float)((float)((float)((float)(*(float *)((char *)p_z + v32) - v31) * v22)
                                                            - prevVel.z)
                                                    * frac)
                                            + prevVel.z;
      v25 = c;
      *(p_y - 1) = v23 + v20;
      *p_y = v24 + v21;
      m_nMaxCount = v18->m_nMaxCount;
      p_z += 3;
      v15 += 3;
      p_y += 3;
      c = (CInterpolatedVarEntryBase<Vector,0> *)((char *)&v25->flChangeTime + 1);
      if ( (int)&v25->flChangeTime + 1 >= m_nMaxCount )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E4E0
// Name: public: void CSimpleRingBuffer<struct CInterpolatedVarEntryBase<class QAngle,0>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
        CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0> > *this,
        CInterpolatedVarEntryBase<QAngle,0> *capSize)
{
  CInterpolatedVarEntryBase<QAngle,0> *m_maxElement; // ebx
  unsigned int v4; // edi
  int v5; // ecx
  unsigned int *v6; // eax
  CInterpolatedVarEntryBase<QAngle,0> *v7; // ebx
  int v8; // edx
  float *p_z; // ecx
  int v10; // ebx
  int v11; // eax
  CInterpolatedVarEntryBase<QAngle,0> *v12; // eax
  CInterpolatedVarEntryBase<QAngle,0> *m_pElements; // eax
  CInterpolatedVarEntryBase<QAngle,0> *pNew; // [esp+10h] [ebp+8h]

  m_maxElement = (CInterpolatedVarEntryBase<QAngle,0> *)this->m_maxElement;
  if ( (int)capSize > (int)m_maxElement )
  {
    v4 = (unsigned int)m_maxElement + this->m_growSize * (((int)capSize + this->m_growSize - 1) / this->m_growSize);
    v5 = (unsigned __int64)v4 >> 28 != 0 ? -1 : 16 * v4;
    v6 = (unsigned int *)MemAlloc_Alloc(nSize: __CFADD__(v5, 4) ? -1 : v5 + 4);
    if ( v6 != nullptr )
    {
      *v6 = v4;
      v7 = (CInterpolatedVarEntryBase<QAngle,0> *)(v6 + 1);
    }
    else
    {
      v7 = nullptr;
    }
    v8 = 0;
    pNew = v7;
    if ( this->m_maxElement != 0 )
    {
      p_z = &v7->value.z;
      do
      {
        v10 = this->m_maxElement;
        v11 = v8 + this->m_firstElement;
        if ( v11 >= v10 )
          v11 -= v10;
        v12 = &this->m_pElements[v11];
        ++v8;
        p_z += 4;
        *(p_z - 7) = v12->flChangeTime;
        *(p_z - 6) = v12->value.x;
        *(p_z - 5) = v12->value.y;
        *(p_z - 4) = v12->value.z;
      }
      while ( v8 < this->m_maxElement );
      v7 = pNew;
    }
    m_pElements = this->m_pElements;
    this->m_maxElement = v4;
    this->m_firstElement = 0;
    if ( m_pElements != nullptr )
      C_BaseEntity::operator delete(pMem: &m_pElements[-1].value.z);
    this->m_pElements = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E5B0
// Name: protected: void CInterpolatedVarArrayBase<class Vector,0>::_Interpolate_Hermite(class Vector __near *,float,struct CInterpolatedVarEntryBase<class Vector,0> __near *,struct CInterpolatedVarEntryBase<class Vector,0> __near *,struct CInterpolatedVarEntryBase<class Vector,0> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::_Interpolate_Hermite(
        CInterpolatedVarArrayBase<Vector,0> *this,
        Vector *out,
        float frac,
        CInterpolatedVarEntryBase<Vector,0> *prev,
        float start,
        CInterpolatedVarEntryBase<Vector,0> *end,
        bool looping)
{
  CInterpolatedVarEntryBase<Vector,0> *v8; // ebx
  CInterpolatedVarEntryBase<Vector,0> *v9; // edi
  bool v10; // zf
  Vector *v11; // esi
  float v12; // xmm1_4
  float *p_x; // edx
  float v14; // xmm7_4
  CInterpolatedVarEntryBase<Vector,0> *v15; // eax
  float *p_z; // ecx
  float v17; // ebx
  float v18; // eax
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm7_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm6_4
  float v30; // xmm6_4
  float v31; // xmm5_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm5_4
  float v39; // xmm7_4
  float v40; // xmm6_4
  float v41; // xmm2_4
  float v42; // xmm5_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm4_4
  float v46; // xmm6_4
  float v47; // xmm3_4
  float v48; // xmm0_4
  CInterpolatedVarArrayBase<Vector,0> *v49; // ebx
  int m_nMaxCount; // ebx
  CInterpolatedVarEntryBase<Vector,0> fixup; // [esp+14h] [ebp-C4h] BYREF
  float v52; // [esp+28h] [ebp-B0h]
  float v53; // [esp+30h] [ebp-A8h]
  float v54; // [esp+3Ch] [ebp-9Ch]
  float v55; // [esp+48h] [ebp-90h]
  float v56; // [esp+54h] [ebp-84h]
  float v57; // [esp+5Ch] [ebp-7Ch]
  __int64 v58; // [esp+60h] [ebp-78h]
  float v59; // [esp+68h] [ebp-70h]
  float v60; // [esp+6Ch] [ebp-6Ch]
  int v61; // [esp+70h] [ebp-68h]
  float v62; // [esp+74h] [ebp-64h]
  Vector *p_value; // [esp+78h] [ebp-60h]
  char *v64; // [esp+7Ch] [ebp-5Ch]
  float v65; // [esp+80h] [ebp-58h]
  float v66; // [esp+84h] [ebp-54h]
  float v67; // [esp+88h] [ebp-50h]
  float v68; // [esp+8Ch] [ebp-4Ch]
  float v69; // [esp+90h] [ebp-48h]
  int v70; // [esp+94h] [ebp-44h]
  float v71; // [esp+98h] [ebp-40h]
  float v72; // [esp+9Ch] [ebp-3Ch]
  float v73; // [esp+A0h] [ebp-38h]
  char *v74; // [esp+A4h] [ebp-34h]
  float v75; // [esp+A8h] [ebp-30h]
  float v76; // [esp+ACh] [ebp-2Ch]
  float v77; // [esp+B0h] [ebp-28h]
  float v78; // [esp+B4h] [ebp-24h]
  __int64 v79; // [esp+B8h] [ebp-20h]
  float v80; // [esp+C0h] [ebp-18h]
  __int64 v81; // [esp+C4h] [ebp-14h]
  float v82; // [esp+CCh] [ebp-Ch]
  CInterpolatedVarArrayBase<Vector,0> *v83; // [esp+D0h] [ebp-8h]
  CDisableRangeChecks disableRangeChecks; // [esp+D7h] [ebp-1h] BYREF
  Vector *outa; // [esp+E0h] [ebp+8h]

  v83 = this;
  CDisableRangeChecks::CDisableRangeChecks(this: &disableRangeChecks);
  v8 = end;
  v9 = (CInterpolatedVarEntryBase<Vector,0> *)LODWORD(start);
  CInterpolatedVarArrayBase<Vector,0>::TimeFixup2_Hermite(
    this,
    &fixup,
    &prev,
    (CInterpolatedVarEntryBase<Vector,0> **)&start,
    dt1: end->flChangeTime - *(float *)LODWORD(start),
    bAllowHermiteFix: true);
  v10 = this->m_nMaxCount == 0;
  end = nullptr;
  if ( !v10 )
  {
    v11 = out;
    v12 = frac;
    v64 = (char *)((char *)prev - (char *)v9);
    v70 = (char *)v8 - (char *)v9;
    v61 = -12 - (_DWORD)v9;
    v74 = (char *)((char *)prev - (char *)v8);
    p_x = &v8->value.x;
    v14 = v12 * v12;
    outa = (Vector *)((char *)out - (char *)v8);
    v15 = end;
    start = v12 * v12;
    p_value = &v8->value;
    p_z = &v9->value.z;
    while ( 1 )
    {
      if ( *((_BYTE *)&v15->flChangeTime + (unsigned int)v83->m_bLooping) != 0 )
      {
        v17 = *(float *)((char *)&p_value->z + (_DWORD)p_z + v61);
        v81 = *(_QWORD *)((char *)&p_value->x + (_DWORD)p_z + v61);
        v79 = *(_QWORD *)((char *)&v9->value.x + (_DWORD)p_z + v61);
        v82 = v17;
        v80 = *(float *)((char *)&v9->value.z + (_DWORD)p_z + v61);
        v58 = *(_QWORD *)((char *)&prev->value.x + (_DWORD)p_z + v61);
        v18 = *(float *)((char *)&prev->value.z + (_DWORD)p_z + v61);
        v55 = *(float *)&v79 - *(float *)&v58;
        v54 = *(float *)&v81 - *(float *)&v79;
        v19 = v14 * frac;
        v65 = (float)(v14 * frac) * 2.0;
        v20 = (float)(v65 - (float)(v14 * 3.0)) + 1.0;
        v21 = (float)(v14 * 3.0) - v65;
        v75 = *(float *)&v79 * v20;
        v76 = *((float *)&v79 + 1) * v20;
        v71 = (float)(*(float *)&v81 * v21) + (float)(*(float *)&v79 * v20);
        v77 = v80 * v20;
        v22 = *((float *)&v81 + 1) * v21;
        v73 = (float)(v21 * v17) + (float)(v80 * v20);
        v72 = (float)(*((float *)&v81 + 1) * v21) + (float)(*((float *)&v79 + 1) * v20);
        v23 = (float)(v19 - (float)(start * 2.0)) + frac;
        v59 = v18;
        v52 = v22;
        v14 = start;
        v24 = (float)(v23 * (float)(*(float *)&v79 - *(float *)&v58)) + v71;
        v25 = (float)((float)(*((float *)&v79 + 1) - *((float *)&v58 + 1)) * v23) + v72;
        v26 = (float)((float)(v80 - v18) * v23) + v73;
        v27 = v19 - start;
        v28 = v27 * (float)(*(float *)&v81 - *(float *)&v79);
        v29 = (float)((float)(v17 - v80) * v27) + v26;
        *(float *)((char *)&outa->x + (_DWORD)p_x) = (float)((float)(*((float *)&v81 + 1) - *((float *)&v79 + 1)) * v27)
                                                   + v25;
        v15 = end;
        v11->z = v29;
      }
      else
      {
        v30 = *(p_z - 2);
        v31 = *p_z;
        v32 = *(p_z - 1);
        v56 = v30 - *(float *)&v74[(_DWORD)p_x];
        v57 = v31 - *(float *)((char *)p_z + (_DWORD)v64);
        v66 = *p_x;
        v67 = v66 - v30;
        v60 = p_x[1];
        v33 = v32 - *(float *)((char *)p_z + (_DWORD)v64 - 4);
        v68 = v60 - v32;
        v78 = *(float *)((char *)p_z + v70);
        v69 = v78 - v31;
        v34 = v14 * v12;
        v62 = (float)(v14 * v12) * 2.0;
        v35 = (float)(v62 - (float)(v14 * 3.0)) + 1.0;
        v36 = (float)(v14 * 3.0) - v62;
        v37 = v32 * v35;
        v38 = v31 * v35;
        v39 = v35 * v30;
        v40 = v60 * v36;
        v41 = (float)(v66 * v36) + v39;
        v14 = start;
        v42 = v38 + (float)(v36 * v78);
        v53 = v41;
        v43 = (float)(v34 - (float)(start * 2.0)) + frac;
        v24 = (float)(v43 * v56) + v41;
        v44 = v34 - start;
        v45 = (float)(v33 * v43) + (float)(v40 + v37);
        v46 = (float)(v43 * v57) + v42;
        v28 = v44 * v67;
        v47 = (float)(v68 * v44) + v45;
        v48 = (float)(v44 * v69) + v46;
        *(float *)((char *)&outa->x + (_DWORD)p_x) = v47;
        v11->z = v48;
      }
      v49 = v83;
      v11->x = v28 + v24;
      m_nMaxCount = v49->m_nMaxCount;
      v15 = (CInterpolatedVarEntryBase<Vector,0> *)((char *)v15 + 1);
      p_x += 3;
      p_z += 3;
      ++v11;
      end = v15;
      if ( (int)v15 >= m_nMaxCount )
        break;
      v12 = frac;
    }
  }
  CDisableRangeChecks::~CDisableRangeChecks(this: &disableRangeChecks);
}

//------------------------------------------------------------------------------
// Address: 0x1003F5A0
// Name: public: void CInterpolatedVarArrayBase<class Vector,0>::GetDerivative_SmoothVelocity(class Vector __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::GetDerivative_SmoothVelocity(
        CInterpolatedVarArrayBase<Vector,0> *this,
        Vector *pOut,
        float currentTime,
        int bAllowHermiteFix)
{
  CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0> > *p_m_VarHistory; // esi
  int m_firstElement; // eax
  int m_maxElement; // edi
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int newer; // ebx
  float m_InterpolationAmount; // xmm0_4
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  float v19; // xmm0_4
  int v20; // ecx
  float v21; // xmm1_4
  float *p_z; // eax
  int v23; // eax
  int v24; // edx
  int v25; // ecx
  int v26; // eax
  float interpolation_amount; // [esp+14h] [ebp-24h]
  CInterpolatedVarArrayBase<Vector,0>::CInterpolationInfo info; // [esp+20h] [ebp-18h] BYREF
  CInterpolatedVarArrayBase<Vector,0> *v29; // [esp+34h] [ebp-4h]
  int realOlder; // [esp+48h] [ebp+10h]

  interpolation_amount = this->m_InterpolationAmount;
  v29 = this;
  if ( CInterpolatedVarArrayBase<QAngle,0>::GetInterpolationInfo(
         (CInterpolatedVarArrayBase<QAngle,0> *)this,
         pInfo: (CInterpolatedVarArrayBase<QAngle,0>::CInterpolationInfo *)&info,
         currentTime,
         interpolation_amount,
         pNoMoreChanges: nullptr) )
  {
    p_m_VarHistory = &this->m_VarHistory;
    if ( info.m_bHermite )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      v8 = m_firstElement + info.newer;
      if ( m_firstElement + info.newer >= m_maxElement )
        v8 -= m_maxElement;
      v9 = m_firstElement + info.older;
      if ( m_firstElement + info.older >= m_maxElement )
        v9 -= m_maxElement;
      v10 = info.oldest + m_firstElement;
      if ( v10 >= m_maxElement )
        v10 -= m_maxElement;
      CInterpolatedVarArrayBase<Vector,0>::_Derivative_Hermite_SmoothVelocity(
        this: v29,
        out: pOut,
        frac: info.frac,
        b: &p_m_VarHistory->m_pElements[v10],
        c: &p_m_VarHistory->m_pElements[v9],
        d: &p_m_VarHistory->m_pElements[v8],
        bAllowHermiteFix);
    }
    else
    {
      newer = info.newer;
      if ( info.newer == info.older
        && CInterpolationContext::s_bAllowExtrapolation
        && (realOlder = info.newer + 1, info.newer + 1 >= 0)
        && info.newer + 1 < this->m_VarHistory.m_count
        && CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0>>::operator[](
             this: &this->m_VarHistory,
             i: info.newer + 1)->flChangeTime != 0.0
        && (m_InterpolationAmount = this->m_InterpolationAmount) > 0.000001
        && (float)(currentTime - m_InterpolationAmount) >= CInterpolationContext::s_flLastTimeStamp )
      {
        v13 = this->m_VarHistory.m_firstElement;
        v14 = this->m_VarHistory.m_maxElement;
        v15 = v13 + newer;
        if ( v13 + newer >= v14 )
          v15 -= v14;
        v16 = realOlder + v13;
        if ( v16 >= v14 )
          v16 -= v14;
        CInterpolatedVarArrayBase<Vector,0>::_Derivative_Linear(
          this,
          out: pOut,
          start: &p_m_VarHistory->m_pElements[v16],
          end: &p_m_VarHistory->m_pElements[v15]);
        v17 = this->m_VarHistory.m_maxElement;
        v18 = info.newer + this->m_VarHistory.m_firstElement;
        if ( v18 >= v17 )
          v18 -= v17;
        v19 = (float)(currentTime - this->m_InterpolationAmount) - p_m_VarHistory->m_pElements[v18].flChangeTime;
        if ( v19 >= 0.0 )
        {
          if ( v19 > (float)(cl_extrapolate_amount.m_pParent->m_Value.m_fValue * 2.0) )
            v19 = cl_extrapolate_amount.m_pParent->m_Value.m_fValue * 2.0;
        }
        else
        {
          v19 = 0.0;
        }
        if ( v19 > cl_extrapolate_amount.m_pParent->m_Value.m_fValue )
        {
          v20 = 0;
          v21 = 1.0
              - (float)((float)(v19 - cl_extrapolate_amount.m_pParent->m_Value.m_fValue)
                      / cl_extrapolate_amount.m_pParent->m_Value.m_fValue);
          if ( this->m_nMaxCount != 0 )
          {
            p_z = &pOut->z;
            do
            {
              *(p_z - 2) = *(p_z - 2) * v21;
              *(p_z - 1) = *(p_z - 1) * v21;
              *p_z = *p_z * v21;
              ++v20;
              p_z += 3;
            }
            while ( v20 < this->m_nMaxCount );
          }
        }
      }
      else
      {
        v23 = this->m_VarHistory.m_firstElement;
        v24 = this->m_VarHistory.m_maxElement;
        v25 = v23 + newer;
        if ( v23 + newer >= v24 )
          v25 -= v24;
        v26 = info.older + v23;
        if ( v26 >= v24 )
          v26 -= v24;
        CInterpolatedVarArrayBase<Vector,0>::_Derivative_Linear(
          this,
          out: pOut,
          start: &p_m_VarHistory->m_pElements[v26],
          end: &p_m_VarHistory->m_pElements[v25]);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FB30
// Name: public: virtual void CInterpolatedVarArrayBase<class C_AnimationLayer,0>::SetDebugName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<C_AnimationLayer,0>::SetDebugName(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        const char *pName)
{
  this->m_pDebugName = pName;
}

//------------------------------------------------------------------------------
// Address: 0x1003FB40
// Name: protected: void CInterpolatedVarArrayBase<class QAngle,0>::_Extrapolate(class QAngle __near *,struct CInterpolatedVarEntryBase<class QAngle,0> __near *,struct CInterpolatedVarEntryBase<class QAngle,0> __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,0>::_Extrapolate(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        QAngle *pOut,
        CInterpolatedVarEntryBase<QAngle,0> *pOld,
        CInterpolatedVarEntryBase<QAngle,0> *pNew,
        float flDestinationTime,
        float flMaxExtrapolationAmount)
{
  float flChangeTime; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  int v11; // ebx
  float v12; // xmm1_4
  QAngle *v13; // edi
  int v14; // eax
  int v15; // edx
  QAngle *p_value; // esi
  QAngle *v17; // eax
  CInterpolatedVarArrayBase<QAngle,0> *v18; // edx
  int v19; // edx
  float *p_z; // ecx
  float *v21; // eax
  QAngle result; // [esp+14h] [ebp-10h] BYREF
  CInterpolatedVarArrayBase<QAngle,0> *v23; // [esp+20h] [ebp-4h]
  QAngle *pOuta; // [esp+2Ch] [ebp+8h]
  float flExtrapolationAmount; // [esp+30h] [ebp+Ch]
  int flDestinationTimea; // [esp+38h] [ebp+14h]

  flChangeTime = pNew->flChangeTime;
  v9 = pOld->flChangeTime;
  LODWORD(v10) = COERCE_UNSIGNED_INT(pOld->flChangeTime - pNew->flChangeTime) & _mask__AbsFloat_;
  v23 = this;
  if ( v10 < 0.001 || flChangeTime >= flDestinationTime )
  {
    v19 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      p_z = &pOut->z;
      v21 = &pNew->value.z;
      do
      {
        ++v19;
        *(p_z - 2) = *(v21 - 2);
        v21 += 3;
        p_z += 3;
        *(p_z - 4) = *(v21 - 4);
        *(p_z - 3) = *(v21 - 3);
      }
      while ( v19 < this->m_nMaxCount );
    }
  }
  else
  {
    if ( flMaxExtrapolationAmount <= (float)(flDestinationTime - flChangeTime) )
      flExtrapolationAmount = flMaxExtrapolationAmount;
    else
      flExtrapolationAmount = flDestinationTime - flChangeTime;
    v11 = 0;
    v12 = 1.0 / (float)(flChangeTime - v9);
    if ( this->m_nMaxCount != 0 )
    {
      v13 = pOut;
      v14 = (char *)pNew - (char *)pOld;
      v15 = (char *)pOut - (char *)pOld;
      p_value = &pOld->value;
      pOuta = (QAngle *)((char *)pNew - (char *)pOld);
      flDestinationTimea = v15;
      while ( 1 )
      {
        v17 = ExtrapolateInterpolatedVarType(
                &result,
                oldVal: p_value,
                newVal: (QAngle *)((char *)p_value + v14),
                divisor: v12,
                flExtrapolationAmount);
        v13->x = v17->x;
        v18 = v23;
        *(float *)((char *)&p_value->x + flDestinationTimea) = v17->y;
        ++v11;
        v13->z = v17->z;
        ++p_value;
        ++v13;
        if ( v11 >= v18->m_nMaxCount )
          break;
        v12 = 1.0 / (float)(flChangeTime - v9);
        v14 = (int)pOuta;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FC80
// Name: protected: void CInterpolatedVarArrayBase<class QAngle,0>::TimeFixup2_Hermite(struct CInterpolatedVarEntryBase<class QAngle,0> __near &,struct CInterpolatedVarEntryBase<class QAngle,0> __near * __near &,struct CInterpolatedVarEntryBase<class QAngle,0> __near * __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,0>::TimeFixup2_Hermite(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        CInterpolatedVarEntryBase<QAngle,0> *fixup,
        CInterpolatedVarEntryBase<QAngle,0> **prev,
        CInterpolatedVarEntryBase<QAngle,0> **start,
        float dt1,
        bool bAllowHermiteFix)
{
  CInterpolatedVarArrayBase<QAngle,0> *v7; // edi
  float flChangeTime; // xmm1_4
  float v9; // xmm0_4
  CInterpolatedVarEntryBase<QAngle,0> *v10; // edx
  int v11; // eax
  float v12; // xmm7_4
  int v13; // esi
  float *v14; // eax
  int v15; // ecx
  float v16; // eax
  __int64 v17; // xmm0_8
  float v18; // ecx
  float v19; // xmm1_4
  const QAngle *v20; // edi
  const QAngle *v21; // ecx
  __int64 v22; // xmm0_8
  float z; // eax
  Quaternion qt; // [esp+14h] [ebp-70h] BYREF
  Quaternion outQuat; // [esp+24h] [ebp-60h] BYREF
  Quaternion q; // [esp+34h] [ebp-50h] BYREF
  QAngle angles; // [esp+44h] [ebp-40h] BYREF
  float v28[3]; // [esp+50h] [ebp-34h] BYREF
  __int64 v29; // [esp+5Ch] [ebp-28h]
  float v30; // [esp+64h] [ebp-20h]
  __int64 v31; // [esp+68h] [ebp-1Ch]
  float v32; // [esp+70h] [ebp-14h]
  __int64 v33; // [esp+74h] [ebp-10h] BYREF
  float v34; // [esp+7Ch] [ebp-8h]
  CInterpolatedVarArrayBase<QAngle,0> *v35; // [esp+80h] [ebp-4h]
  float frac; // [esp+90h] [ebp+Ch]
  int i; // [esp+98h] [ebp+14h]

  v7 = this;
  flChangeTime = (*start)->flChangeTime;
  v9 = flChangeTime - (*prev)->flChangeTime;
  v35 = this;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(dt1 - v9) & _mask__AbsFloat_) > 0.000099999997 && v9 > 0.000099999997 )
  {
    v10 = fixup;
    v11 = 0;
    fixup->flChangeTime = flChangeTime - dt1;
    v12 = dt1 / v9;
    frac = dt1 / v9;
    i = 0;
    if ( this->m_nMaxCount != 0 )
    {
      v13 = 0;
      do
      {
        if ( v7->m_bLooping[v11] != 0 )
        {
          if ( g_bHermiteFix && bAllowHermiteFix )
          {
            v14 = (float *)((char *)&(*prev)->value.x + v13);
          }
          else
          {
            v15 = (int)*prev;
            v16 = *(float *)((char *)&(*start)->value.z + v13);
            v29 = *(_QWORD *)((char *)&(*start)->value.x + v13);
            v17 = *(_QWORD *)(v13 + v15 + 4);
            v18 = *(float *)(v13 + v15 + 12);
            v31 = v17;
            v32 = v18;
            v19 = 1.0 - (float)(1.0 - v12);
            v30 = v16;
            v28[0] = (float)((float)(1.0 - v12) * *(float *)&v29) + (float)(*(float *)&v17 * v19);
            v28[1] = (float)((float)(1.0 - v12) * *((float *)&v29 + 1)) + (float)(*((float *)&v17 + 1) * v19);
            v28[2] = (float)((float)(1.0 - v12) * v16) + (float)(v18 * v19);
            v14 = v28;
          }
        }
        else if ( g_bHermiteFix && bAllowHermiteFix )
        {
          v14 = (float *)((char *)&(*prev)->value.x + v13);
        }
        else
        {
          v20 = (QAngle *)((char *)&(*start)->value + v13);
          v21 = (QAngle *)((char *)&(*prev)->value + v13);
          if ( v20->x == v21->x
            && *(float *)((char *)&(*start)->value.y + v13) == *(float *)((char *)&(*prev)->value.y + v13)
            && *(float *)((char *)&(*start)->value.z + v13) == *(float *)((char *)&(*prev)->value.z + v13) )
          {
            v22 = *(_QWORD *)&v21->x;
            z = *(float *)((char *)&(*prev)->value.z + v13);
          }
          else
          {
            AngleQuaternion(angles: v21, &outQuat);
            AngleQuaternion(angles: v20, outQuat: &q);
            QuaternionSlerp(p: &outQuat, &q, t: 1.0 - frac, &qt);
            QuaternionAngles(q: &qt, &angles);
            v22 = *(_QWORD *)&angles.x;
            z = angles.z;
            v12 = frac;
            v10 = fixup;
          }
          v7 = v35;
          v34 = z;
          v14 = (float *)&v33;
          v33 = v22;
        }
        v13 += 12;
        *(float *)((char *)v10 + v13 - 8) = *v14;
        *(float *)((char *)v10 + v13 - 4) = v14[1];
        *(float *)((char *)&v10->flChangeTime + v13) = v14[2];
        v11 = i + 1;
        i = v11;
      }
      while ( v11 < v7->m_nMaxCount );
    }
    *prev = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FEC0
// Name: protected: void CInterpolatedVarArrayBase<class Vector,0>::RemoveEntriesPreviousTo(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::RemoveEntriesPreviousTo(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        float flTime)
{
  int v2; // edx
  int m_maxElement; // edi
  int i; // esi
  int v5; // eax

  v2 = 0;
  if ( this->m_VarHistory.m_count != 0 )
  {
    m_maxElement = this->m_VarHistory.m_maxElement;
    for ( i = this->m_VarHistory.m_firstElement - m_maxElement; ; ++i )
    {
      v5 = v2 + this->m_VarHistory.m_firstElement;
      if ( v5 >= m_maxElement )
        v5 = i;
      if ( flTime > this->m_VarHistory.m_pElements[v5].flChangeTime )
        break;
      if ( ++v2 >= this->m_VarHistory.m_count )
        return;
    }
    if ( v2 + 3 < this->m_VarHistory.m_count )
      this->m_VarHistory.m_count = v2 + 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FF20
// Name: protected: void CInterpolatedVarArrayBase<class QAngle,0>::_Interpolate(class QAngle __near *,float,struct CInterpolatedVarEntryBase<class QAngle,0> __near *,struct CInterpolatedVarEntryBase<class QAngle,0> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,0>::_Interpolate(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        QAngle *out,
        float frac,
        CInterpolatedVarEntryBase<QAngle,0> *start,
        CInterpolatedVarEntryBase<QAngle,0> *end)
{
  int v7; // esi
  float *p_z; // ecx
  float *v9; // eax
  CInterpolatedVarArrayBase<QAngle,0> *v10; // edx
  double v11; // st7
  int v12; // eax
  float v13; // xmm6_4
  QAngle *v14; // edi
  int v15; // ebx
  int v16; // edx
  QAngle *p_value; // esi
  float v18; // ecx
  float v19; // xmm1_4
  float v20; // xmm2_4
  __int64 v21; // xmm0_8
  Quaternion qt; // [esp+14h] [ebp-64h] BYREF
  Quaternion outQuat; // [esp+24h] [ebp-54h] BYREF
  Quaternion q; // [esp+34h] [ebp-44h] BYREF
  QAngle angles; // [esp+44h] [ebp-34h] BYREF
  __int64 v26; // [esp+50h] [ebp-28h]
  float v27; // [esp+58h] [ebp-20h]
  __int64 v28; // [esp+5Ch] [ebp-1Ch]
  float z; // [esp+64h] [ebp-14h]
  __int64 v30; // [esp+68h] [ebp-10h]
  float v31; // [esp+70h] [ebp-8h]
  CInterpolatedVarArrayBase<QAngle,0> *v32; // [esp+74h] [ebp-4h]
  QAngle *outa; // [esp+80h] [ebp+8h]
  int i; // [esp+88h] [ebp+10h]

  v32 = this;
  if ( start == end )
  {
    v7 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      p_z = &out->z;
      v9 = &end->value.z;
      do
      {
        v10 = v32;
        *(p_z - 2) = *(v9 - 2);
        ++v7;
        v11 = *(v9 - 1);
        v9 += 3;
        *(p_z - 1) = v11;
        p_z += 3;
        *(p_z - 3) = *(v9 - 3);
      }
      while ( v7 < v10->m_nMaxCount );
    }
  }
  else
  {
    v12 = 0;
    i = 0;
    if ( this->m_nMaxCount != 0 )
    {
      v13 = frac;
      v14 = out;
      v15 = (char *)end - (char *)start;
      v16 = (char *)out - (char *)start;
      p_value = &start->value;
      outa = (QAngle *)((char *)out - (char *)start);
      do
      {
        if ( v32->m_bLooping[v12] != 0 )
        {
          v18 = *(float *)((char *)&p_value->z + v15);
          v26 = *(_QWORD *)((char *)&p_value->x + v15);
          v28 = *(_QWORD *)&p_value->x;
          v27 = v18;
          z = p_value->z;
          v19 = (float)(*((float *)&v26 + 1) * v13) + (float)(*((float *)&v28 + 1) * (float)(1.0 - v13));
          v20 = (float)(v18 * v13) + (float)(z * (float)(1.0 - v13));
          v14->x = (float)(*(float *)&v26 * v13) + (float)(*(float *)&v28 * (float)(1.0 - v13));
          *(float *)((char *)&p_value->x + v16) = v19;
          v14->z = v20;
        }
        else
        {
          if ( *(float *)((char *)&p_value->x + v15) == p_value->x
            && *(float *)((char *)&p_value->y + v15) == p_value->y
            && *(float *)((char *)&p_value->z + v15) == p_value->z )
          {
            v21 = *(_QWORD *)&p_value->x;
            v31 = p_value->z;
          }
          else
          {
            AngleQuaternion(angles: p_value, &outQuat);
            AngleQuaternion(angles: (QAngle *)((char *)p_value + v15), outQuat: &q);
            QuaternionSlerp(p: &outQuat, &q, t: frac, &qt);
            QuaternionAngles(q: &qt, &angles);
            v21 = *(_QWORD *)&angles.x;
            v13 = frac;
            v31 = angles.z;
            v16 = (int)outa;
          }
          v12 = i;
          v30 = v21;
          LODWORD(v14->x) = v21;
          *(float *)((char *)&p_value->x + v16) = *((float *)&v30 + 1);
          v14->z = v31;
        }
        ++v12;
        ++p_value;
        ++v14;
        i = v12;
      }
      while ( v12 < v32->m_nMaxCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040110
// Name: protected: bool CInterpolatedVarArrayBase<class QAngle,0>::GetInterpolationInfo(class CInterpolatedVarArrayBase<class QAngle,0>::CInterpolationInfo __near *,float,float,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInterpolatedVarArrayBase<QAngle,0>::GetInterpolationInfo(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        CInterpolatedVarArrayBase<QAngle,0>::CInterpolationInfo *pInfo,
        float currentTime,
        float interpolation_amount,
        int *pNoMoreChanges)
{
  float v5; // xmm0_4
  int v6; // esi
  int m_maxElement; // edi
  int v8; // eax
  float flChangeTime; // xmm1_4
  int newer; // eax
  int v12; // ebx
  int v13; // edi
  int v14; // eax
  float v15; // xmm2_4
  float v16; // xmm0_4
  int v17; // edi
  int v18; // eax
  int v19; // edi
  int m_firstElement; // ebx
  unsigned int v21; // edi
  int v22; // eax
  int v23; // esi
  int p_value; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // edx
  unsigned int v28; // edi
  int v29; // eax
  int v30; // edx
  int v31; // eax
  int older; // eax
  int v33; // [esp+0h] [ebp-4h]
  CInterpolatedVarEntryBase<QAngle,0> *currentTimea; // [esp+10h] [ebp+Ch]
  unsigned int interpolation_amounta; // [esp+14h] [ebp+10h]

  v5 = currentTime - interpolation_amount;
  pInfo->m_bHermite = false;
  pInfo->frac = 0.0;
  pInfo->newer = -1;
  pInfo->older = -1;
  pInfo->oldest = -1;
  v6 = 0;
  if ( this->m_VarHistory.m_count == 0 )
  {
LABEL_7:
    newer = pInfo->newer;
    if ( newer == -1 )
    {
      older = pInfo->older;
      pInfo->newer = older;
      return older != -1;
    }
    else
    {
      pInfo->older = newer;
      return true;
    }
  }
  while ( 1 )
  {
    pInfo->older = v6;
    m_maxElement = this->m_VarHistory.m_maxElement;
    v8 = v6 + this->m_VarHistory.m_firstElement;
    if ( v8 >= m_maxElement )
      v8 -= m_maxElement;
    flChangeTime = this->m_VarHistory.m_pElements[v8].flChangeTime;
    if ( flChangeTime == 0.0 )
      goto LABEL_7;
    if ( flChangeTime <= v5 )
      break;
    pInfo->newer = v6++;
    if ( v6 >= this->m_VarHistory.m_count )
      goto LABEL_7;
  }
  v12 = pInfo->newer;
  if ( v12 != -1 )
  {
    v13 = this->m_VarHistory.m_maxElement;
    v14 = v12 + this->m_VarHistory.m_firstElement;
    if ( v14 >= v13 )
      v14 -= v13;
    v15 = this->m_VarHistory.m_pElements[v14].flChangeTime - flChangeTime;
    if ( v15 > 0.000099999997 )
    {
      v16 = (float)(v5 - flChangeTime) / v15;
      pInfo->frac = v16;
      if ( v16 >= 2.0 )
        v16 = 2.0;
      pInfo->frac = v16;
      v17 = v6 + 1;
      if ( (this->m_fType & 0x10) == 0 && v17 >= 0 && v17 < this->m_VarHistory.m_count )
      {
        pInfo->oldest = v17;
        v18 = v17 + this->m_VarHistory.m_firstElement;
        v19 = this->m_VarHistory.m_maxElement;
        if ( v18 >= v19 )
          v18 -= v19;
        if ( (float)(flChangeTime - this->m_VarHistory.m_pElements[v18].flChangeTime) > 0.000099999997 )
          pInfo->m_bHermite = true;
      }
      if ( pNoMoreChanges != nullptr && v12 == (this->m_VarHistory.m_count != 0) - 1 )
      {
        m_firstElement = this->m_VarHistory.m_firstElement;
        interpolation_amounta = 12 * this->m_nMaxCount;
        v21 = interpolation_amounta;
        v22 = m_firstElement + v6;
        v23 = this->m_VarHistory.m_maxElement;
        if ( v22 >= v23 )
          v22 -= v23;
        currentTimea = this->m_VarHistory.m_pElements;
        p_value = (int)&currentTimea[v22].value;
        v25 = m_firstElement + pInfo->newer;
        v33 = v25;
        if ( v25 >= v23 )
          v25 -= v23;
        v26 = (int)&currentTimea[v25].value;
        if ( interpolation_amounta >= 4 )
        {
          while ( *(_DWORD *)v26 == *(_DWORD *)p_value )
          {
            v21 -= 4;
            p_value += 4;
            v26 += 4;
            if ( v21 < 4 )
              goto LABEL_35;
          }
          return true;
        }
LABEL_35:
        if ( v21 == 0
          || *(_BYTE *)p_value == *(_BYTE *)v26
          && (v21 <= 1
           || *(_BYTE *)(p_value + 1) == *(_BYTE *)(v26 + 1)
           && (v21 <= 2 || *(_BYTE *)(p_value + 2) == *(_BYTE *)(v26 + 2))) )
        {
          if ( !pInfo->m_bHermite )
            goto LABEL_55;
          v27 = m_firstElement + pInfo->oldest;
          v28 = interpolation_amounta;
          if ( v27 >= v23 )
            v27 -= v23;
          v29 = v33;
          v30 = (int)&currentTimea[v27].value;
          if ( v33 >= v23 )
            v29 = v33 - v23;
          v31 = (int)&currentTimea[v29].value;
          if ( interpolation_amounta >= 4 )
          {
            while ( *(_DWORD *)v31 == *(_DWORD *)v30 )
            {
              v28 -= 4;
              v30 += 4;
              v31 += 4;
              if ( v28 < 4 )
                goto LABEL_49;
            }
            return true;
          }
LABEL_49:
          if ( v28 == 0
            || *(_BYTE *)v30 == *(_BYTE *)v31
            && (v28 <= 1
             || *(_BYTE *)(v30 + 1) == *(_BYTE *)(v31 + 1) && (v28 <= 2 || *(_BYTE *)(v30 + 2) == *(_BYTE *)(v31 + 2))) )
          {
LABEL_55:
            *pNoMoreChanges = 1;
          }
        }
      }
    }
    return true;
  }
  pInfo->newer = v6;
  if ( pNoMoreChanges != nullptr )
    *pNoMoreChanges = 1;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10040390
// Name: protected: void CInterpolatedVarArrayBase<class QAngle,0>::_Interpolate_Hermite(class QAngle __near *,float,struct CInterpolatedVarEntryBase<class QAngle,0> __near *,struct CInterpolatedVarEntryBase<class QAngle,0> __near *,struct CInterpolatedVarEntryBase<class QAngle,0> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,0>::_Interpolate_Hermite(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        QAngle *out,
        float frac,
        CInterpolatedVarEntryBase<QAngle,0> *prev,
        CInterpolatedVarEntryBase<QAngle,0> *start,
        CInterpolatedVarEntryBase<QAngle,0> *end,
        bool looping)
{
  CInterpolatedVarEntryBase<QAngle,0> *v8; // ebx
  bool v9; // zf
  CInterpolatedVarEntryBase<QAngle,0> *v10; // eax
  QAngle *v11; // edi
  QAngle *p_value; // edx
  const QAngle *v13; // esi
  char *v14; // ecx
  __int64 v15; // xmm0_8
  float v16; // eax
  __int64 v17; // xmm0_8
  float v18; // eax
  __int64 v19; // xmm0_8
  CInterpolatedVarEntryBase<QAngle,0> *v20; // eax
  QAngle *v21; // eax
  CInterpolatedVarEntryBase<QAngle,0> *v22; // ecx
  int m_nMaxCount; // ecx
  CInterpolatedVarEntryBase<QAngle,0> fixup; // [esp+1Ch] [ebp-90h] BYREF
  QAngle result; // [esp+2Ch] [ebp-80h] BYREF
  Quaternion outQuat; // [esp+38h] [ebp-74h] BYREF
  Quaternion qt; // [esp+48h] [ebp-64h] BYREF
  Quaternion q; // [esp+58h] [ebp-54h] BYREF
  QAngle v29; // [esp+68h] [ebp-44h] BYREF
  QAngle v30; // [esp+74h] [ebp-38h] BYREF
  char *v31; // [esp+80h] [ebp-2Ch]
  char *v32; // [esp+84h] [ebp-28h]
  QAngle angles; // [esp+88h] [ebp-24h] BYREF
  __int64 v34; // [esp+94h] [ebp-18h]
  float z; // [esp+9Ch] [ebp-10h]
  CInterpolatedVarArrayBase<QAngle,0> *v36; // [esp+A0h] [ebp-Ch]
  QAngle *v37; // [esp+A4h] [ebp-8h]
  CDisableRangeChecks disableRangeChecks; // [esp+ABh] [ebp-1h] BYREF
  QAngle *outa; // [esp+B4h] [ebp+8h]

  v36 = this;
  CDisableRangeChecks::CDisableRangeChecks(this: &disableRangeChecks);
  v8 = start;
  CInterpolatedVarArrayBase<QAngle,0>::TimeFixup2_Hermite(
    this,
    &fixup,
    &prev,
    &start,
    dt1: end->flChangeTime - start->flChangeTime,
    bAllowHermiteFix: true);
  v9 = this->m_nMaxCount == 0;
  start = nullptr;
  if ( !v9 )
  {
    v10 = end;
    v31 = (char *)((char *)end - (char *)v8);
    v32 = (char *)((char *)prev - (char *)v8);
    v11 = out;
    prev = (CInterpolatedVarEntryBase<QAngle,0> *)((char *)out - (char *)v8);
    p_value = &v8->value;
    v37 = &v8->value;
    v13 = &v8->value;
    outa = (QAngle *)(-4 - (_DWORD)v8);
    while ( 1 )
    {
      if ( *((_BYTE *)&start->flChangeTime + (unsigned int)v36->m_bLooping) != 0 )
      {
        v14 = (char *)outa + (_DWORD)v13;
        v15 = *(_QWORD *)((char *)&outa->y + (_DWORD)v13 + (unsigned int)v10);
        v16 = *(float *)((char *)&outa[1].x + (_DWORD)v13 + (unsigned int)v10);
        *(_QWORD *)&v30.x = v15;
        v17 = *(_QWORD *)((char *)&outa->x + (_DWORD)v13 + (unsigned int)p_value);
        v30.z = v16;
        v18 = *(float *)((char *)&outa->z + (_DWORD)v13 + (unsigned int)p_value);
        *(_QWORD *)&angles.x = v17;
        angles.z = v18;
        if ( v30.x != *(float *)&v17 )
          goto LABEL_9;
        if ( v30.y == angles.y && v30.z == angles.z )
        {
          v19 = *(_QWORD *)((char *)&p_value->x + (_DWORD)v14);
          z = *(float *)((char *)&p_value->z + (_DWORD)v14);
        }
        else
        {
LABEL_9:
          AngleQuaternion(&angles, &outQuat);
          AngleQuaternion(angles: &v30, outQuat: &q);
          QuaternionSlerp(p: &outQuat, &q, t: frac, &qt);
          QuaternionAngles(q: &qt, angles: &v29);
          v19 = *(_QWORD *)&v29.x;
          z = v29.z;
          p_value = v37;
        }
        v20 = prev;
        v34 = v19;
        LODWORD(v11->x) = v19;
        *(float *)((char *)&v13->x + (_DWORD)v20) = *((float *)&v34 + 1);
        v11->z = z;
      }
      else
      {
        v21 = Lerp_Hermite<QAngle>(
                &result,
                __formal: v11,
                t: frac,
                p0: (const QAngle *)&v32[(_DWORD)v13],
                p1: v13,
                p2: (const QAngle *)&v31[(_DWORD)v13]);
        v22 = prev;
        v11->x = v21->x;
        p_value = v37;
        *(float *)((char *)&v13->x + (_DWORD)v22) = v21->y;
        v11->z = v21->z;
      }
      m_nMaxCount = v36->m_nMaxCount;
      ++v13;
      ++v11;
      start = (CInterpolatedVarEntryBase<QAngle,0> *)((char *)start + 1);
      if ( (int)start >= m_nMaxCount )
        break;
      v10 = end;
    }
  }
  CDisableRangeChecks::~CDisableRangeChecks(this: &disableRangeChecks);
}

//------------------------------------------------------------------------------
// Address: 0x10040640
// Name: public: int CInterpolatedVarArrayBase<class Vector,0>::Interpolate(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<Vector,0>::Interpolate(
        CInterpolatedVarArrayBase<Vector,0> *this,
        float currentTime,
        float interpolation_amount)
{
  int m_firstElement; // eax
  int m_maxElement; // ebx
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  int newer; // ebx
  int v11; // eax
  CInterpolatedVarEntryBase<Vector,0> *v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // edx
  CInterpolatedVarEntryBase<Vector,0> *v20; // [esp+8h] [ebp-34h]
  float flMaxExtrapolationAmount; // [esp+10h] [ebp-2Ch]
  CInterpolatedVarArrayBase<Vector,0>::CInterpolationInfo info; // [esp+20h] [ebp-1Ch] BYREF
  int realOlder; // [esp+34h] [ebp-8h]
  int noMoreChanges; // [esp+38h] [ebp-4h] BYREF

  noMoreChanges = 0;
  if ( CInterpolatedVarArrayBase<QAngle,0>::GetInterpolationInfo(
         (CInterpolatedVarArrayBase<QAngle,0> *)this,
         pInfo: (CInterpolatedVarArrayBase<QAngle,0>::CInterpolationInfo *)&info,
         currentTime,
         interpolation_amount,
         pNoMoreChanges: &noMoreChanges) )
  {
    if ( info.m_bHermite )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      v6 = m_firstElement + info.newer;
      if ( m_firstElement + info.newer >= m_maxElement )
        v6 -= m_maxElement;
      v7 = m_firstElement + info.older;
      if ( m_firstElement + info.older >= m_maxElement )
        v7 -= m_maxElement;
      v8 = this->m_VarHistory.m_maxElement;
      v9 = info.oldest + m_firstElement;
      if ( v9 >= v8 )
        v9 -= v8;
      CInterpolatedVarArrayBase<Vector,0>::_Interpolate_Hermite(
        this,
        out: this->m_pValue,
        frac: info.frac,
        prev: &this->m_VarHistory.m_pElements[v9],
        start: COERCE_FLOAT((int)&this->m_VarHistory.m_pElements[v7]),
        end: &this->m_VarHistory.m_pElements[v6],
        looping: false);
      goto LABEL_28;
    }
    newer = info.newer;
    if ( info.newer == info.older )
    {
      v11 = info.newer + 1;
      realOlder = info.newer + 1;
      if ( CInterpolationContext::s_bAllowExtrapolation
        && v11 >= 0
        && v11 < this->m_VarHistory.m_count
        && CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0>>::operator[](
             this: &this->m_VarHistory,
             i: info.newer + 1)->flChangeTime != 0.0
        && interpolation_amount > 0.000001
        && this->m_LastNetworkedTime >= CInterpolationContext::s_flLastTimeStamp )
      {
        flMaxExtrapolationAmount = cl_extrapolate_amount.m_pParent->m_Value.m_fValue;
        v20 = CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0>>::operator[](this: &this->m_VarHistory, i: newer);
        v12 = CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0>>::operator[](
                this: &this->m_VarHistory,
                i: realOlder);
        CInterpolatedVarArrayBase<Vector,0>::_Extrapolate(
          this,
          pOut: this->m_pValue,
          pOld: v12,
          pNew: v20,
          flDestinationTime: currentTime - interpolation_amount,
          flMaxExtrapolationAmount);
LABEL_28:
        CInterpolatedVarArrayBase<Vector,0>::RemoveEntriesPreviousTo(
          (CInterpolatedVarArrayBase<QAngle,0> *)this,
          flTime: (float)(currentTime - interpolation_amount) - 0.050000001);
        return noMoreChanges;
      }
      v13 = this->m_VarHistory.m_firstElement;
      v14 = this->m_VarHistory.m_maxElement;
      v15 = v13 + newer;
      if ( v13 + newer >= v14 )
        v15 -= v14;
      v16 = info.older + v13;
      if ( v16 >= v14 )
        v16 -= v14;
    }
    else
    {
      v17 = this->m_VarHistory.m_firstElement;
      v18 = this->m_VarHistory.m_maxElement;
      v15 = v17 + info.newer;
      if ( v17 + info.newer >= v18 )
        v15 -= v18;
      v16 = info.older + v17;
      if ( v16 >= v18 )
        v16 -= v18;
    }
    CInterpolatedVarArrayBase<Vector,0>::_Interpolate(
      this,
      out: this->m_pValue,
      frac: info.frac,
      start: &this->m_VarHistory.m_pElements[v16],
      end: &this->m_VarHistory.m_pElements[v15]);
    goto LABEL_28;
  }
  return noMoreChanges;
}

//------------------------------------------------------------------------------
// Address: 0x10040840
// Name: public: void CInterpolatedVarArrayBase<class Vector,0>::AddToHead(float,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::AddToHead(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        float changeTime,
        const QAngle *values,
        bool bFlushNewer)
{
  unsigned int m_firstElement; // eax
  unsigned int m_maxElement; // ecx
  unsigned __int16 m_count; // dx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0> > *p_m_VarHistory; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ebx
  int v20; // ebx
  int v21; // ecx
  int v22; // eax
  int v23; // ebx
  CInterpolatedVarEntryBase<QAngle,0> *m_pElements; // ebx
  int v25; // ecx
  double flChangeTime; // st7
  float *p_flChangeTime; // ecx
  int v28; // eax
  float *v29; // eax
  int v30; // eax
  int v31; // ecx
  int v32; // ecx
  unsigned int v33; // [esp-10h] [ebp-10h]
  int newslot; // [esp+10h] [ebp+10h]

  if ( bFlushNewer )
  {
    while ( this->m_VarHistory.m_count != 0 )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      if ( m_firstElement >= m_maxElement )
        m_firstElement -= m_maxElement;
      if ( (float)(this->m_VarHistory.m_pElements[m_firstElement].flChangeTime + 0.000099999997) <= changeTime )
        break;
      m_count = this->m_VarHistory.m_count;
      if ( m_count != 0 )
      {
        v8 = this->m_VarHistory.m_maxElement;
        v9 = this->m_VarHistory.m_firstElement + 1;
        if ( v9 >= v8 )
          LOWORD(v9) = v9 - v8;
        this->m_VarHistory.m_firstElement = v9;
        this->m_VarHistory.m_count = m_count - 1;
      }
    }
    p_m_VarHistory = &this->m_VarHistory;
    CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
      this: &this->m_VarHistory,
      capSize: this->m_VarHistory.m_count + 1);
    v11 = this->m_VarHistory.m_maxElement;
    v12 = this->m_VarHistory.m_firstElement;
    ++this->m_VarHistory.m_count;
    v13 = v12 + v11 - 1;
    if ( v13 >= v11 )
      LOWORD(v13) = v13 - v11;
    this->m_VarHistory.m_firstElement = v13;
    newslot = 0;
  }
  else
  {
    p_m_VarHistory = &this->m_VarHistory;
    CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
      this: &this->m_VarHistory,
      capSize: this->m_VarHistory.m_count + 1);
    v14 = this->m_VarHistory.m_maxElement;
    v15 = this->m_VarHistory.m_firstElement;
    ++this->m_VarHistory.m_count;
    v16 = v15 + v14 - 1;
    if ( v16 >= v14 )
      LOWORD(v16) = v16 - v14;
    v17 = 1;
    this->m_VarHistory.m_firstElement = v16;
    newslot = 0;
    if ( this->m_VarHistory.m_count > 1u )
    {
      do
      {
        v18 = this->m_VarHistory.m_maxElement;
        v19 = v17 + this->m_VarHistory.m_firstElement;
        if ( v19 >= v18 )
          v19 -= v18;
        if ( changeTime >= p_m_VarHistory->m_pElements[v19].flChangeTime )
          break;
        v20 = this->m_VarHistory.m_firstElement;
        v21 = v20 + v17;
        if ( v20 + v17 >= v18 )
          v21 -= v18;
        v22 = v20 + newslot;
        v23 = this->m_VarHistory.m_maxElement;
        if ( v22 >= v23 )
          v22 -= v23;
        m_pElements = p_m_VarHistory->m_pElements;
        v25 = v21;
        flChangeTime = p_m_VarHistory->m_pElements[v25].flChangeTime;
        p_flChangeTime = &p_m_VarHistory->m_pElements[v25].flChangeTime;
        v28 = v22;
        m_pElements[v28].flChangeTime = flChangeTime;
        v29 = &m_pElements[v28].flChangeTime;
        newslot = v17;
        v29[1] = p_flChangeTime[1];
        ++v17;
        v29[2] = p_flChangeTime[2];
        v29[3] = p_flChangeTime[3];
      }
      while ( v17 < this->m_VarHistory.m_count );
    }
  }
  v30 = p_m_VarHistory->m_maxElement;
  v31 = newslot + p_m_VarHistory->m_firstElement;
  if ( v31 >= v30 )
    v31 -= v30;
  v32 = (int)&p_m_VarHistory->m_pElements[v31];
  v33 = 12 * this->m_nMaxCount;
  *(float *)v32 = changeTime;
  memcpy(dst: (unsigned __int8 *)(v32 + 4), src: (unsigned __int8 *)values, count: v33);
}

//------------------------------------------------------------------------------
// Address: 0x100409D0
// Name: public: int CInterpolatedVarArrayBase<class QAngle,0>::Interpolate(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<QAngle,0>::Interpolate(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        float currentTime,
        float interpolation_amount)
{
  int m_firstElement; // eax
  int m_maxElement; // ebx
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  int newer; // ebx
  int v11; // eax
  CInterpolatedVarEntryBase<QAngle,0> *v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // edx
  CInterpolatedVarEntryBase<QAngle,0> *v20; // [esp+8h] [ebp-34h]
  float flMaxExtrapolationAmount; // [esp+10h] [ebp-2Ch]
  CInterpolatedVarArrayBase<QAngle,0>::CInterpolationInfo info; // [esp+20h] [ebp-1Ch] BYREF
  int realOlder; // [esp+34h] [ebp-8h]
  int noMoreChanges; // [esp+38h] [ebp-4h] BYREF

  noMoreChanges = 0;
  if ( CInterpolatedVarArrayBase<QAngle,0>::GetInterpolationInfo(
         this,
         pInfo: &info,
         currentTime,
         interpolation_amount,
         pNoMoreChanges: &noMoreChanges) )
  {
    if ( info.m_bHermite )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      v6 = m_firstElement + info.newer;
      if ( m_firstElement + info.newer >= m_maxElement )
        v6 -= m_maxElement;
      v7 = m_firstElement + info.older;
      if ( m_firstElement + info.older >= m_maxElement )
        v7 -= m_maxElement;
      v8 = this->m_VarHistory.m_maxElement;
      v9 = info.oldest + m_firstElement;
      if ( v9 >= v8 )
        v9 -= v8;
      CInterpolatedVarArrayBase<QAngle,0>::_Interpolate_Hermite(
        this,
        out: this->m_pValue,
        frac: info.frac,
        prev: &this->m_VarHistory.m_pElements[v9],
        start: &this->m_VarHistory.m_pElements[v7],
        end: &this->m_VarHistory.m_pElements[v6],
        looping: false);
      goto LABEL_28;
    }
    newer = info.newer;
    if ( info.newer == info.older )
    {
      v11 = info.newer + 1;
      realOlder = info.newer + 1;
      if ( CInterpolationContext::s_bAllowExtrapolation
        && v11 >= 0
        && v11 < this->m_VarHistory.m_count
        && CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0>>::operator[](
             this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0> > *)&this->m_VarHistory,
             i: info.newer + 1)->flChangeTime != 0.0
        && interpolation_amount > 0.000001
        && this->m_LastNetworkedTime >= CInterpolationContext::s_flLastTimeStamp )
      {
        flMaxExtrapolationAmount = cl_extrapolate_amount.m_pParent->m_Value.m_fValue;
        v20 = (CInterpolatedVarEntryBase<QAngle,0> *)CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0>>::operator[](
                                                       this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0> > *)&this->m_VarHistory,
                                                       i: newer);
        v12 = (CInterpolatedVarEntryBase<QAngle,0> *)CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0>>::operator[](
                                                       this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0> > *)&this->m_VarHistory,
                                                       i: realOlder);
        CInterpolatedVarArrayBase<QAngle,0>::_Extrapolate(
          this,
          pOut: this->m_pValue,
          pOld: v12,
          pNew: v20,
          flDestinationTime: currentTime - interpolation_amount,
          flMaxExtrapolationAmount);
LABEL_28:
        CInterpolatedVarArrayBase<Vector,0>::RemoveEntriesPreviousTo(
          this,
          flTime: (float)(currentTime - interpolation_amount) - 0.050000001);
        return noMoreChanges;
      }
      v13 = this->m_VarHistory.m_firstElement;
      v14 = this->m_VarHistory.m_maxElement;
      v15 = v13 + newer;
      if ( v13 + newer >= v14 )
        v15 -= v14;
      v16 = info.older + v13;
      if ( v16 >= v14 )
        v16 -= v14;
    }
    else
    {
      v17 = this->m_VarHistory.m_firstElement;
      v18 = this->m_VarHistory.m_maxElement;
      v15 = v17 + info.newer;
      if ( v17 + info.newer >= v18 )
        v15 -= v18;
      v16 = info.older + v17;
      if ( v16 >= v18 )
        v16 -= v18;
    }
    CInterpolatedVarArrayBase<QAngle,0>::_Interpolate(
      this,
      out: this->m_pValue,
      frac: info.frac,
      start: &this->m_VarHistory.m_pElements[v16],
      end: &this->m_VarHistory.m_pElements[v15]);
    goto LABEL_28;
  }
  return noMoreChanges;
}

//------------------------------------------------------------------------------
// Address: 0x10041B30
// Name: public: virtual void CInterpolatedVarArrayBase<class Vector,0>::Reset(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::Reset(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        float flCurrentTime)
{
  QAngle *m_pValue; // eax

  *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
  m_pValue = this->m_pValue;
  if ( m_pValue != nullptr )
  {
    CInterpolatedVarArrayBase<Vector,0>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: m_pValue,
      bFlushNewer: false);
    CInterpolatedVarArrayBase<Vector,0>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: this->m_pValue,
      bFlushNewer: false);
    CInterpolatedVarArrayBase<Vector,0>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: this->m_pValue,
      bFlushNewer: false);
    memcpy(
      dst: (unsigned __int8 *)this->m_LastNetworkedValue,
      src: (unsigned __int8 *)this->m_pValue,
      count: 12 * this->m_nMaxCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041BB0
// Name: public: virtual int CInterpolatedVarArrayBase<class Vector,0>::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<Vector,0>::Interpolate(
        CInterpolatedVarArrayBase<Vector,0> *this,
        float currentTime)
{
  return CInterpolatedVarArrayBase<Vector,0>::Interpolate(
           this,
           currentTime,
           interpolation_amount: this->m_InterpolationAmount);
}

//------------------------------------------------------------------------------
// Address: 0x10041BE0
// Name: public: virtual void CInterpolatedVarArrayBase<class Vector,0>::Copy(class IInterpolatedVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::Copy(
        CInterpolatedVarArrayBase<Vector,0> *this,
        IInterpolatedVar *pInSrc)
{
  unsigned __int16 *v3; // edi
  unsigned __int8 m_nMaxCount; // al
  int v5; // edx
  int v6; // esi
  int v7; // eax
  Vector *m_LastNetworkedValue; // ecx
  double v9; // st7
  int m_maxElement; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  CInterpolatedVarEntryBase<Vector,0> *v15; // edx
  int v16; // eax
  int v17; // eax
  unsigned int v18; // [esp-8h] [ebp-10h]
  int i; // [esp+10h] [ebp+8h]

  v3 = (unsigned __int16 *)__RTDynamicCast(
                             inptr: pInSrc,
                             VfDelta: 0,
                             SrcType: &IInterpolatedVar `RTTI Type Descriptor',
                             TargetType: &CInterpolatedVarArrayBase<Vector,0> `RTTI Type Descriptor',
                             isReference: 0);
  if ( v3 != nullptr )
  {
    m_nMaxCount = this->m_nMaxCount;
    if ( *((_BYTE *)v3 + 29) == m_nMaxCount )
    {
      v5 = 0;
      if ( m_nMaxCount != 0 )
      {
        v6 = 0;
        do
        {
          v7 = *((_DWORD *)v3 + 5);
          m_LastNetworkedValue = this->m_LastNetworkedValue;
          m_LastNetworkedValue[v6].x = *(float *)(v7 + v6 * 12);
          ++v5;
          v9 = *(float *)(v7 + v6 * 12 + 4);
          m_LastNetworkedValue[v6++].y = v9;
          m_LastNetworkedValue[v6 - 1].z = *(float *)(v7 + v6 * 12 - 4);
          this->m_bLooping[v5 - 1] = *(_BYTE *)(v5 + *((_DWORD *)v3 + 8) - 1);
        }
        while ( v5 < this->m_nMaxCount );
      }
      this->m_LastNetworkedTime = *((float *)v3 + 6);
      *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
      i = 0;
      if ( v3[8] != 0 )
      {
        do
        {
          CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
            this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0> > *)&this->m_VarHistory,
            capSize: this->m_VarHistory.m_count + 1);
          ++this->m_VarHistory.m_count;
          m_maxElement = this->m_VarHistory.m_maxElement;
          v11 = this->m_VarHistory.m_firstElement + this->m_VarHistory.m_count - 1;
          if ( v11 >= m_maxElement )
            v11 -= m_maxElement;
          v12 = v11 + this->m_VarHistory.m_firstElement;
          v13 = this->m_VarHistory.m_maxElement;
          if ( v12 >= v13 )
            v12 -= v13;
          v14 = v3[6];
          v15 = &this->m_VarHistory.m_pElements[v12];
          v16 = i + v3[7];
          if ( v16 >= v14 )
            v16 -= v14;
          v17 = *((_DWORD *)v3 + 2) + 16 * v16;
          v18 = 12 * this->m_nMaxCount;
          v15->flChangeTime = *(float *)v17;
          memcpy(dst: (unsigned __int8 *)&v15->value, src: (unsigned __int8 *)(v17 + 4), count: v18);
          ++i;
        }
        while ( i < v3[8] );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041D10
// Name: public: virtual int CInterpolatedVarArrayBase<class QAngle,0>::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<QAngle,0>::Interpolate(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        float currentTime)
{
  return CInterpolatedVarArrayBase<QAngle,0>::Interpolate(
           this,
           currentTime,
           interpolation_amount: this->m_InterpolationAmount);
}

//------------------------------------------------------------------------------
// Address: 0x10041D40
// Name: public: virtual void CInterpolatedVarArrayBase<class QAngle,0>::Copy(class IInterpolatedVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,0>::Copy(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        IInterpolatedVar *pInSrc)
{
  unsigned __int16 *v3; // edi
  unsigned __int8 m_nMaxCount; // al
  int v5; // edx
  int v6; // esi
  int v7; // eax
  QAngle *m_LastNetworkedValue; // ecx
  double v9; // st7
  int m_maxElement; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  CInterpolatedVarEntryBase<QAngle,0> *v15; // edx
  int v16; // eax
  int v17; // eax
  unsigned int v18; // [esp-8h] [ebp-10h]
  int i; // [esp+10h] [ebp+8h]

  v3 = (unsigned __int16 *)__RTDynamicCast(
                             inptr: pInSrc,
                             VfDelta: 0,
                             SrcType: &IInterpolatedVar `RTTI Type Descriptor',
                             TargetType: &CInterpolatedVarArrayBase<QAngle,0> `RTTI Type Descriptor',
                             isReference: 0);
  if ( v3 != nullptr )
  {
    m_nMaxCount = this->m_nMaxCount;
    if ( *((_BYTE *)v3 + 29) == m_nMaxCount )
    {
      v5 = 0;
      if ( m_nMaxCount != 0 )
      {
        v6 = 0;
        do
        {
          v7 = *((_DWORD *)v3 + 5);
          m_LastNetworkedValue = this->m_LastNetworkedValue;
          m_LastNetworkedValue[v6].x = *(float *)(v7 + v6 * 12);
          ++v5;
          v9 = *(float *)(v7 + v6 * 12 + 4);
          m_LastNetworkedValue[v6++].y = v9;
          m_LastNetworkedValue[v6 - 1].z = *(float *)(v7 + v6 * 12 - 4);
          this->m_bLooping[v5 - 1] = *(_BYTE *)(v5 + *((_DWORD *)v3 + 8) - 1);
        }
        while ( v5 < this->m_nMaxCount );
      }
      this->m_LastNetworkedTime = *((float *)v3 + 6);
      *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
      i = 0;
      if ( v3[8] != 0 )
      {
        do
        {
          CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
            this: &this->m_VarHistory,
            capSize: this->m_VarHistory.m_count + 1);
          ++this->m_VarHistory.m_count;
          m_maxElement = this->m_VarHistory.m_maxElement;
          v11 = this->m_VarHistory.m_firstElement + this->m_VarHistory.m_count - 1;
          if ( v11 >= m_maxElement )
            v11 -= m_maxElement;
          v12 = v11 + this->m_VarHistory.m_firstElement;
          v13 = this->m_VarHistory.m_maxElement;
          if ( v12 >= v13 )
            v12 -= v13;
          v14 = v3[6];
          v15 = &this->m_VarHistory.m_pElements[v12];
          v16 = i + v3[7];
          if ( v16 >= v14 )
            v16 -= v14;
          v17 = *((_DWORD *)v3 + 2) + 16 * v16;
          v18 = 12 * this->m_nMaxCount;
          v15->flChangeTime = *(float *)v17;
          memcpy(dst: (unsigned __int8 *)&v15->value, src: (unsigned __int8 *)(v17 + 4), count: v18);
          ++i;
        }
        while ( i < v3[8] );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041E70
// Name: public: bool CInterpolatedVarArrayBase<class Vector,0>::NoteChanged(float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInterpolatedVarArrayBase<Vector,0>::NoteChanged(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        float flCurrentTime,
        float flChangeTime,
        float interpolation_amount,
        bool bUpdateLastNetworkedValue)
{
  char v6; // bl
  unsigned int m_firstElement; // ecx
  unsigned int m_maxElement; // edx
  unsigned int v9; // eax
  QAngle *m_pValue; // edi
  QAngle *p_value; // ecx
  int v12; // ecx
  int v13; // edi
  int i; // edx
  int v15; // eax
  bool bRet; // [esp+1Bh] [ebp-1h]

  v6 = 1;
  bRet = true;
  if ( this->m_VarHistory.m_count != 0 )
  {
    m_firstElement = this->m_VarHistory.m_firstElement;
    m_maxElement = this->m_VarHistory.m_maxElement;
    v9 = 12 * this->m_nMaxCount;
    if ( m_firstElement >= m_maxElement )
      m_firstElement -= m_maxElement;
    m_pValue = this->m_pValue;
    p_value = &this->m_VarHistory.m_pElements[m_firstElement].value;
    if ( v9 < 4 )
    {
LABEL_7:
      if ( v9 == 0
        || LOBYTE(p_value->x) == LOBYTE(m_pValue->x)
        && (v9 <= 1 || BYTE1(p_value->x) == BYTE1(m_pValue->x) && (v9 <= 2 || BYTE2(p_value->x) == BYTE2(m_pValue->x))) )
      {
        v6 = 0;
        bRet = false;
      }
    }
    else
    {
      while ( LODWORD(m_pValue->x) == LODWORD(p_value->x) )
      {
        v9 -= 4;
        p_value = (QAngle *)((char *)p_value + 4);
        m_pValue = (QAngle *)((char *)m_pValue + 4);
        if ( v9 < 4 )
          goto LABEL_7;
      }
    }
  }
  CInterpolatedVarArrayBase<Vector,0>::AddToHead(
    this,
    changeTime: flChangeTime,
    values: this->m_pValue,
    bFlushNewer: true);
  if ( bUpdateLastNetworkedValue )
    this->NoteLastNetworkedValue(this);
  v12 = 0;
  if ( this->m_VarHistory.m_count == 0 )
    return v6;
  v13 = this->m_VarHistory.m_maxElement;
  for ( i = this->m_VarHistory.m_firstElement - v13; ; ++i )
  {
    v15 = v12 + this->m_VarHistory.m_firstElement;
    if ( v15 >= v13 )
      v15 = i;
    if ( (float)((float)(flCurrentTime - interpolation_amount) - 0.050000001) > this->m_VarHistory.m_pElements[v15].flChangeTime )
      break;
    if ( ++v12 >= this->m_VarHistory.m_count )
      return bRet;
  }
  if ( v12 + 3 >= this->m_VarHistory.m_count )
    return bRet;
  this->m_VarHistory.m_count = v12 + 3;
  return bRet;
}

//------------------------------------------------------------------------------
// Address: 0x10042A30
// Name: public: virtual bool CInterpolatedVarArrayBase<class Vector,0>::NoteChanged(float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInterpolatedVarArrayBase<Vector,0>::NoteChanged(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        float flCurrentTime,
        float flChangeTime,
        bool bUpdateLastNetworkedValue)
{
  return CInterpolatedVarArrayBase<Vector,0>::NoteChanged(
           this,
           flCurrentTime,
           flChangeTime,
           interpolation_amount: this->m_InterpolationAmount,
           bUpdateLastNetworkedValue);
}

//------------------------------------------------------------------------------
// Address: 0x1015A280
// Name: public: virtual class IPhysicsObject __near * CRagdoll::GetElement(int)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CRagdoll::GetElement(CRagdoll *this, int elementNum)
{
  return this->m_ragdoll.list[elementNum].pObject;
}

//------------------------------------------------------------------------------
// Address: 0x1015A2A0
// Name: public: virtual void CRagdoll::RagdollBone(class C_BaseEntity __near *,struct mstudiobone_t __near *,int,bool __near *,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdoll::RagdollBone(
        CRagdoll *this,
        C_BaseEntity *ent,
        mstudiobone_t *pbones,
        int boneCount,
        bool *boneSimulated,
        CBoneAccessor *pBoneToWorld)
{
  int v6; // esi
  ragdoll_t *p_m_ragdoll; // edi
  int *boneIndex; // ebx

  v6 = 0;
  p_m_ragdoll = &this->m_ragdoll;
  if ( this->m_ragdoll.listCount > 0 )
  {
    boneIndex = this->m_ragdoll.boneIndex;
    do
    {
      if ( RagdollGetBoneMatrix(ragdoll: p_m_ragdoll, pBoneToWorld, objectIndex: v6) != 0 )
        boneSimulated[*boneIndex] = true;
      ++v6;
      ++boneIndex;
    }
    while ( v6 < p_m_ragdoll->listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A2E0
// Name: public: virtual class Vector const __near & CRagdoll::GetRagdollOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CRagdoll::GetRagdollOrigin(CRagdoll *this)
{
  return &this->m_origin;
}

//------------------------------------------------------------------------------
// Address: 0x1015A2F0
// Name: public: virtual bool CRagdoll::TransformVectorToWorld(int,class Vector const __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRagdoll::TransformVectorToWorld(CRagdoll *this, int iBoneIndex, const Vector *vPosition, Vector *vOut)
{
  int v4; // edi
  int listCount; // esi
  int v6; // eax
  int *boneIndex; // edx

  v4 = -1;
  if ( iBoneIndex < 0 )
    return 0;
  listCount = this->m_ragdoll.listCount;
  if ( iBoneIndex >= listCount )
    return 0;
  v6 = 0;
  if ( listCount <= 0 )
    return 0;
  boneIndex = this->m_ragdoll.boneIndex;
  do
  {
    if ( *boneIndex == iBoneIndex )
      v4 = v6;
    ++v6;
    ++boneIndex;
  }
  while ( v6 < listCount );
  if ( v4 == -1 )
    return 0;
  this->m_ragdoll.list[v4].pObject->LocalToWorld(this: this->m_ragdoll.list[v4].pObject, a2: vOut, a3: vPosition);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015A350
// Name: public: void CRagdoll::ResetRagdollSleepAfterTime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdoll::ResetRagdollSleepAfterTime(CRagdoll *this)
{
  this->m_flLastOriginChangeTime = physenv->GetSimulationTime(this: physenv);
  this->m_flAwakeTime = physenv->GetSimulationTime(this: physenv);
}

//------------------------------------------------------------------------------
// Address: 0x1015A390
// Name: public: virtual class ClientClass __near * C_ServerRagdoll::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_ServerRagdoll::GetClientClass(C_ServerRagdoll *this)
{
  return &__g_C_ServerRagdollClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1015A4D0
// Name: public: virtual float C_ServerRagdoll::LastBoneChangedTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_ServerRagdoll::LastBoneChangedTime(C_ServerRagdoll *this)
{
  return this->m_flLastBoneChangeTime;
}

//------------------------------------------------------------------------------
// Address: 0x1015A4E0
// Name: public: virtual class IClientModelRenderable __near * C_ServerRagdoll::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientThinkable *__usercall C_ServerRagdoll::GetClientModelRenderable@<eax>(C_ServerRagdoll *this@<ecx>, int a2@<esi>)
{
  if ( (int)this->m_pIk <= 0 )
    return C_BaseAnimating::GetClientModelRenderable(this, a2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1015A500
// Name: public: virtual class ClientClass __near * C_ServerRagdollAttached::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_ServerRagdollAttached::GetClientClass(C_ServerRagdollAttached *this)
{
  return &__g_C_ServerRagdollAttachedClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1015A620
// Name: public: void CRagdoll::BuildRagdollBounds(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRagdoll::BuildRagdollBounds(
        CRagdoll *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        C_BaseEntity *ent)
{
  IVModelInfoClient_vtbl *v6; // edi
  int v7; // eax
  float v10; // [esp-10h] [ebp-2Ch]
  float v11[3]; // [esp-Ch] [ebp-28h] BYREF
  Vector mins; // [esp+0h] [ebp-1Ch] BYREF
  float v13; // [esp+Ch] [ebp-10h]
  Vector maxs; // [esp+10h] [ebp-Ch]
  float retaddr; // [esp+1Ch] [ebp+0h]

  maxs.x = a2;
  maxs.y = retaddr;
  v6 = modelinfo->__vftable;
  v7 = ((int (__thiscall *)(IClientRenderable *, float *, float *, int, int))ent->GetModel)(
         a1: &ent->IClientRenderable,
         a2: v11,
         a3: &mins.y,
         a4: a3,
         a5: a4);
  ((void (__thiscall *)(IVModelInfoClient *, int))v6->GetModelBounds)(a1: modelinfo, a2: v7);
  v10 = fsqrt(
          (float)((float)((float)((float)(mins.z - v11[1]) * 0.5) * (float)((float)(mins.z - v11[1]) * 0.5))
                + (float)((float)((float)(v13 - v11[2]) * 0.5) * (float)((float)(v13 - v11[2]) * 0.5)))
        + (float)((float)((float)(mins.y - v11[0]) * 0.5) * (float)((float)(mins.y - v11[0]) * 0.5)));
  LODWORD(this->m_mins.x) = LODWORD(v10) ^ _mask__NegFloat_;
  LODWORD(this->m_mins.y) = LODWORD(v10) ^ _mask__NegFloat_;
  LODWORD(this->m_mins.z) = LODWORD(v10) ^ _mask__NegFloat_;
  this->m_maxs.x = v10;
  this->m_maxs.y = v10;
  this->m_maxs.z = v10;
}

//------------------------------------------------------------------------------
// Address: 0x1015A710
// Name: public: virtual CRagdoll::~CRagdoll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdoll::~CRagdoll(CRagdoll *this)
{
  CRagdoll *v1; // ebx
  int v2; // edi
  IPhysicsObject **p_pObject; // ebx
  IPhysicsObject *v4; // esi

  v1 = this;
  v2 = 0;
  this->__vftable = (CRagdoll_vtbl *)&CRagdoll::`vftable';
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      v4 = *p_pObject;
      if ( *p_pObject != nullptr )
      {
        g_pPhysSaveRestoreManager->ForgetModel(this: g_pPhysSaveRestoreManager, a2: *p_pObject);
        v4->EnableCollisions(this: v4, a2: false);
      }
      ++v2;
      p_pObject += 6;
    }
    while ( v2 < this->m_ragdoll.listCount );
    v1 = this;
  }
  RagdollDestroy(ragdoll: &v1->m_ragdoll);
  v1->__vftable = (CRagdoll_vtbl *)&IRagdoll::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1015A790
// Name: public: virtual void CRagdoll::GetRagdollBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdoll::GetRagdollBounds(CRagdoll *this, Vector *theMins, Vector *theMaxs)
{
  *theMins = this->m_mins;
  *theMaxs = this->m_maxs;
}

//------------------------------------------------------------------------------
// Address: 0x1015A7E0
// Name: private: void CRagdoll::PhysForceRagdollToSleep(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdoll::PhysForceRagdollToSleep(CRagdoll *this)
{
  int v2; // edi
  IPhysicsObject **p_pObject; // esi
  IPhysicsObject *pList[32]; // [esp+0h] [ebp-98h] BYREF
  Vector angVel; // [esp+80h] [ebp-18h] BYREF
  Vector vel; // [esp+8Ch] [ebp-Ch] BYREF

  v2 = 0;
  memset((void *)&vel, 0, sizeof(vel));
  memset((void *)&angVel, 0, sizeof(angVel));
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      if ( *p_pObject != nullptr )
      {
        (*p_pObject)->SetVelocity(this: *p_pObject, a2: &vel, a3: &angVel);
        pList[v2] = *p_pObject;
      }
      ++v2;
      p_pObject += 6;
    }
    while ( v2 < this->m_ragdoll.listCount );
  }
  physenv->ForceObjectsToSleep(this: physenv, a2: pList, a3: this->m_ragdoll.listCount);
}

//------------------------------------------------------------------------------
// Address: 0x1015A870
// Name: private: void CRagdoll::CheckSettleStationaryRagdoll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdoll::CheckSettleStationaryRagdoll(CRagdoll *this)
{
  double v2; // st7
  float v3; // xmm0_4
  const Vector *v4; // eax
  int i; // eax
  const Vector *v6; // eax
  Vector delta; // [esp+4h] [ebp-10h]
  float tolerance; // [esp+10h] [ebp-4h]

  v2 = ((double (__thiscall *)(IPhysicsEnvironment *))physenv->GetSimulationTime)(a1: physenv) - this->m_flAwakeTime;
  tolerance = v2;
  if ( v2 >= 1.0 )
  {
    v3 = tolerance;
    if ( tolerance > 10.0 )
    {
      tolerance = 10.0;
      goto LABEL_4;
    }
  }
  else
  {
    v3 = 1.0;
  }
  tolerance = v3;
LABEL_4:
  v4 = this->GetRagdollOrigin(this);
  delta.x = v4->x - this->m_vecLastOrigin.x;
  delta.y = v4->y - this->m_vecLastOrigin.y;
  delta.z = v4->z - this->m_vecLastOrigin.z;
  for ( i = 0; i < 3; ++i )
  {
    if ( fabs(*(&delta.x + i)) > tolerance )
    {
      this->m_flLastOriginChangeTime = physenv->GetSimulationTime(this: physenv);
      v6 = this->GetRagdollOrigin(this);
      this->m_vecLastOrigin.x = v6->x;
      this->m_vecLastOrigin.y = v6->y;
      this->m_vecLastOrigin.z = v6->z;
      return;
    }
  }
  if ( ragdoll_sleepaftertime.m_pParent->m_Value.m_fValue <= ((double (__thiscall *)(IPhysicsEnvironment *))physenv->GetSimulationTime)(a1: physenv)
                                                           - this->m_flLastOriginChangeTime )
    CRagdoll::PhysForceRagdollToSleep(this);
}

//------------------------------------------------------------------------------
// Address: 0x1015A9B0
// Name: public: virtual void CRagdoll::DrawWireframe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdoll::DrawWireframe(CRagdoll *this)
{
  IMaterial *(__thiscall *FindMaterial)(IMaterialSystem *, const char *, const char *, bool, const char *); // edx
  int v3; // edi
  IPhysicsObject **p_pObject; // esi
  const struct CPhysCollide *v5; // eax
  matrix3x4_t matrix; // [esp+8h] [ebp-38h] BYREF
  CRagdoll *v7; // [esp+38h] [ebp-8h]
  IMaterial *pWireframe; // [esp+3Ch] [ebp-4h]

  FindMaterial = materials->FindMaterial;
  v7 = this;
  v3 = 0;
  pWireframe = FindMaterial(
                 this: materials,
                 a2: "debug/debugwireframevertexcolor",
                 a3: "Other textures",
                 a4: true,
                 a5: nullptr);
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      (*p_pObject)->GetPositionMatrix(this: *p_pObject, a2: &matrix);
      v5 = (*p_pObject)->GetCollide(this: *p_pObject);
      engine->DebugDrawPhysCollide(this: engine, a2: v5, a3: pWireframe, a4: &matrix, a5: &debugColor_2);
      ++v3;
      p_pObject += 6;
    }
    while ( v3 < v7->m_ragdoll.listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015AA40
// Name: public: virtual void C_ServerRagdoll::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ServerRagdoll::PostDataUpdate(C_ServerRagdoll *this, DataUpdateType_t updateType)
{
  char v3; // al
  double InterpolationAmount; // st7
  bool v5; // zf

  C_BaseAnimating::PostDataUpdate(this, updateType);
  (*(void (__thiscall **)(float *, _DWORD, _DWORD, int))(LODWORD(this->m_ragAngles[31].y) + 16))(
    a1: &this->m_ragAngles[31].y,
    a2: *(_DWORD *)(gpGlobals.m_Index + 12),
    a3: *(_DWORD *)(gpGlobals.m_Index + 12),
    a4: 1);
  (*(void (__thiscall **)(float *, _DWORD, _DWORD, int))(LODWORD(this->m_iv_ragPos.m_InterpolationAmount) + 16))(
    a1: &this->m_iv_ragPos.m_InterpolationAmount,
    a2: *(_DWORD *)(gpGlobals.m_Index + 12),
    a3: *(_DWORD *)(gpGlobals.m_Index + 12),
    a4: 1);
  v3 = (*(int (__thiscall **)(float *))(LODWORD(this->m_ragAngles[31].y) + 28))(a1: &this->m_ragAngles[31].y);
  InterpolationAmount = C_BaseEntity::GetInterpolationAmount(this: (C_ServerRagdoll *)((char *)this - 8), flags: v3);
  v5 = *(float *)&this->m_hUnragdoll.m_Value.m_Index == *(float *)&this->m_boneIndex[31];
  this->m_flBlendWeightCurrent = InterpolationAmount + *(float *)(gpGlobals.m_Index + 12);
  if ( !v5 )
    C_BaseEntity::AddToEntityList(this: (C_ServerRagdoll *)((char *)this - 8), listId: ENTITY_LIST_SIMULATE);
}

//------------------------------------------------------------------------------
// Address: 0x1015AC10
// Name: public: virtual bool C_ServerRagdoll::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_ServerRagdoll::Simulate(C_ServerRagdoll *this)
{
  bool v2; // al
  float m_Value; // xmm3_4
  float m_flBlendWeightCurrent; // xmm1_4
  bool v5; // cl
  float v6; // xmm0_4
  float v7; // xmm1_4
  bool result; // al

  v2 = C_BaseAnimating::Simulate(this);
  m_Value = this->m_flBlendWeight.m_Value;
  m_flBlendWeightCurrent = this->m_flBlendWeightCurrent;
  v5 = v2;
  v6 = *(float *)(gpGlobals.m_Index + 16) * 5.0;
  if ( (float)(m_Value - m_flBlendWeightCurrent) <= v6 )
  {
    if ( COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_) <= (float)(m_Value - m_flBlendWeightCurrent) )
      v7 = this->m_flBlendWeight.m_Value;
    else
      v7 = m_flBlendWeightCurrent - v6;
  }
  else
  {
    v7 = m_flBlendWeightCurrent + v6;
  }
  this->m_flBlendWeightCurrent = v7;
  result = true;
  if ( v7 == m_Value )
    return v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015AC80
// Name: public: void CInterpolatedVarArrayBase<class QAngle,0>::SetMaxCount(float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(
        CInterpolatedVarArrayBase<QAngle,0> *this,
        float flCurrentTime,
        int newmax)
{
  unsigned __int8 v3; // al
  bool v5; // cl
  QAngle *v6; // eax
  unsigned __int8 *m_bLooping; // ecx

  v3 = newmax;
  v5 = newmax != this->m_nMaxCount;
  if ( newmax < 1 )
    v3 = 1;
  this->m_nMaxCount = v3;
  if ( v5 )
  {
    C_BaseEntity::operator delete(pMem: this->m_bLooping);
    C_BaseEntity::operator delete(pMem: (void *)this->m_LastNetworkedValue);
    this->m_bLooping = (unsigned __int8 *)MemAlloc_Alloc(nSize: this->m_nMaxCount);
    v6 = (QAngle *)MemAlloc_Alloc(nSize: 12 * this->m_nMaxCount);
    m_bLooping = this->m_bLooping;
    this->m_LastNetworkedValue = v6;
    memset(dst: (int)m_bLooping, value: nullptr, count: this->m_nMaxCount);
    memset(dst: (int)this->m_LastNetworkedValue, value: nullptr, count: 12 * this->m_nMaxCount);
    ((void (__thiscall *)(CInterpolatedVarArrayBase<QAngle,0> *, _DWORD))this->Reset)(
      a1: this,
      a2: LODWORD(flCurrentTime));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015AD90
// Name: public: void CRagdoll::Init(class C_BaseEntity __near *,class CStudioHdr __near *,class Vector const __near &,int,struct matrix3x4_t const __near *,struct matrix3x4_t const __near *,struct matrix3x4_t const __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CRagdoll::Init(
        CRagdoll *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        C_BaseEntity *ent,
        CStudioHdr *pstudiohdr,
        const Vector *forceVector,
        int forceBone,
        const matrix3x4_t *pDeltaBones0,
        const matrix3x4_t *pDeltaBones1,
        const matrix3x4_t *pCurrentBonePosition,
        float dt,
        bool bFixedConstraints)
{
  int ModelIndex; // eax
  float z; // xmm0_4
  ragdoll_t *p_m_ragdoll; // edi
  bool v17; // cc
  int (*v18)(void); // eax
  unsigned __int16 v19; // ax
  unsigned int v20; // eax
  int v21; // eax
  __int128 v22; // xmm0
  IPhysSaveRestoreManager_vtbl *v23; // esi
  IPhysicsObject **v24; // eax
  int v26; // [esp+1Ch] [ebp-74h] BYREF
  vcollide_t *v27; // [esp+20h] [ebp-70h]
  CStudioHdr *v28; // [esp+24h] [ebp-6Ch]
  ragdollparams_t params_4; // [esp+2Ch] [ebp-64h] OVERLAPPED BYREF
  int v30; // [esp+64h] [ebp-2Ch]
  float v31[3]; // [esp+68h] [ebp-28h] BYREF
  void (__thiscall **p_GetModelBounds)(struct IVModelInfoClient *, const struct model_t *, Vector *, Vector *); // [esp+74h] [ebp-1Ch]
  int v33; // [esp+78h] [ebp-18h]
  int v34; // [esp+7Ch] [ebp-14h]
  void (__thiscall ***v35)(struct IVModelInfoClient *, const struct model_t *, Vector *, Vector *); // [esp+80h] [ebp-10h]
  int i; // [esp+84h] [ebp-Ch]
  void *v37; // [esp+88h] [ebp-8h]
  void *retaddr; // [esp+90h] [ebp+0h]

  i = a2;
  v37 = retaddr;
  ModelIndex = C_BaseEntity::GetModelIndex(this: ent);
  v27 = (vcollide_t *)((int (__thiscall *)(IVModelInfoClient *, int, int, int, C_BaseEntity *, vcollide_t *, CStudioHdr *, int, void *, vcollide_t *, CStudioHdr *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, const matrix3x4_t *, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, void (__thiscall **)(struct IVModelInfoClient *, const struct model_t *, Vector *, Vector *), int, int))modelinfo->GetVCollide)(
                        a1: modelinfo,
                        a2: ModelIndex,
                        a3,
                        a4,
                        a5: ent,
                        a6: v27,
                        a7: v28,
                        a8: ModelIndex,
                        a9: params_4.pGameData,
                        a10: params_4.pCollide,
                        a11: params_4.pStudioHdr,
                        a12: params_4.modelIndex,
                        a13: LODWORD(params_4.forcePosition.x),
                        a14: LODWORD(params_4.forcePosition.y),
                        a15: LODWORD(params_4.forcePosition.z),
                        a16: LODWORD(params_4.forceVector.x),
                        a17: LODWORD(params_4.forceVector.y),
                        a18: LODWORD(params_4.forceVector.z),
                        a19: params_4.forceBoneIndex,
                        a20: params_4.pCurrentBones,
                        a21: LODWORD(params_4.jointFrictionScale),
                        a22: *(_DWORD *)&params_4.allowStretch,
                        a23: v30,
                        a24: LODWORD(v31[0]),
                        a25: LODWORD(v31[1]),
                        a26: LODWORD(v31[2]),
                        a27: p_GetModelBounds,
                        a28: v33,
                        a29: v34);
  if ( v27 != nullptr )
  {
    params_4.modelIndex = LODWORD(forceVector->x);
    params_4.forcePosition.x = forceVector->y;
    z = forceVector->z;
    LODWORD(params_4.forcePosition.z) = forceBone;
    LODWORD(params_4.forceVector.x) = pCurrentBonePosition;
    params_4.forcePosition.y = z;
    v28 = pstudiohdr;
    memset(&params_4, 0, 12);
    p_m_ragdoll = &this->m_ragdoll;
    params_4.forceVector.y = 1.0;
    LOBYTE(params_4.forceVector.z) = 0;
    BYTE1(params_4.forceVector.z) = bFixedConstraints;
    RagdollCreate(ragdoll: &this->m_ragdoll, params: (const ragdollparams_t *)&v26, pPhysEnv: physenv);
    C_BaseEntity::VPhysicsSetObject(this: ent, pPhysics: nullptr);
    C_BaseEntity::VPhysicsSetObject(this: ent, pPhysics: (IPhysicsObject *)&this->m_ragdoll.list[0].pObject);
    C_BaseEntity::SetCollisionGroup(this: ent, collisionGroup: 1);
    v17 = this->m_ragdoll.listCount <= 0;
    v33 = 0;
    if ( !v17 )
    {
      v35 = (void (__thiscall ***)(struct IVModelInfoClient *, const struct model_t *, Vector *, Vector *))v34;
      do
      {
        (*((void (__thiscall **)(void (__thiscall **)(struct IVModelInfoClient *, const struct model_t *, Vector *, Vector *), int))**v35
         + 83))(
          a1: *v35,
          a2: 1);
        if ( (cl_ragdoll_self_collision.m_pParent == nullptr
           || cl_ragdoll_self_collision.m_pParent->m_Value.m_nValue == 0)
          && (cl_ragdoll_collide.m_pParent == nullptr || cl_ragdoll_collide.m_pParent->m_Value.m_nValue == 0) )
        {
          v18 = *((int (**)(void))**v35 + 19);
          p_GetModelBounds = *v35;
          v19 = v18();
          (*((void (__thiscall **)(void (__thiscall **)(struct IVModelInfoClient *, const struct model_t *, Vector *, Vector *), int))*p_GetModelBounds
           + 18))(
            a1: p_GetModelBounds,
            a2: v19 | 0x8000);
          (*((void (__thiscall **)(void (__thiscall **)(struct IVModelInfoClient *, const struct model_t *, Vector *, Vector *), int))**v35
           + 84))(
            a1: *v35,
            a2: 1);
        }
        v35 += 6;
        ++v33;
      }
      while ( v33 < p_m_ragdoll->listCount );
    }
    RagdollApplyAnimationAsVelocity(
      ragdoll: &this->m_ragdoll,
      pPrevBones: pDeltaBones0,
      pCurrentBones: pDeltaBones1,
      dt);
    v34 = 1;
    v20 = C_BaseEntity::GetModelIndex(this: ent);
    RagdollActivate(ragdoll: &this->m_ragdoll, pCollide: v27, modelIndex: v20, bForceWake: v34);
    (*(void (__thiscall **)(_DWORD, Vector *, _DWORD))(**(_DWORD **)v34 + 192))(
      a1: *(_DWORD *)v34,
      a2: &this->m_origin,
      a3: 0);
    this->m_flLastOriginChangeTime = physenv->GetSimulationTime(this: physenv);
    this->m_flAwakeTime = physenv->GetSimulationTime(this: physenv);
    ent->m_iEFlags |= 0x40000u;
    if ( p_m_ragdoll->listCount != 0 )
    {
      p_GetModelBounds = &modelinfo->GetModelBounds;
      v21 = ((int (__thiscall *)(IClientRenderable *, const matrix3x4_t **, float *))ent->GetModel)(
              a1: &ent->IClientRenderable,
              a2: &params_4.pCurrentBones,
              a3: v31);
      ((void (__thiscall *)(IVModelInfoClient *, int))*p_GetModelBounds)(a1: modelinfo, a2: v21);
      v22 = 0;
      *(float *)&v22 = fsqrt(
                         (float)((float)((float)((float)(v31[1] - params_4.jointFrictionScale) * 0.5)
                                       * (float)((float)(v31[1] - params_4.jointFrictionScale) * 0.5))
                               + (float)((float)((float)(v31[2] - *(float *)&params_4.allowStretch) * 0.5)
                                       * (float)((float)(v31[2] - *(float *)&params_4.allowStretch) * 0.5)))
                       + (float)((float)((float)(v31[0] - *(float *)&params_4.pCurrentBones) * 0.5)
                               * (float)((float)(v31[0] - *(float *)&params_4.pCurrentBones) * 0.5)));
      *(_OWORD *)&params_4.forceBoneIndex = v22;
      LODWORD(v22) = v22 ^ _mask__NegFloat_;
      LODWORD(this->m_mins.x) = v22;
      LODWORD(this->m_mins.y) = v22;
      LODWORD(this->m_mins.z) = v22;
      LODWORD(v22) = params_4.forceBoneIndex;
      LODWORD(this->m_maxs.x) = params_4.forceBoneIndex;
      LODWORD(this->m_maxs.y) = v22;
      LODWORD(this->m_maxs.z) = v22;
      v17 = p_m_ragdoll->listCount <= 0;
      v33 = 0;
      if ( !v17 )
      {
        do
        {
          v23 = g_pPhysSaveRestoreManager->__vftable;
          v24 = (IPhysicsObject **)C_BaseEntity::GetModelIndex(this: ent);
          v23->AssociateModel_2(this: g_pPhysSaveRestoreManager, a2: *v24, a3: (int)v24);
          v34 += 24;
          ++v33;
        }
        while ( v33 < p_m_ragdoll->listCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B0A0
// Name: public: virtual void CRagdoll::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdoll::VPhysicsUpdate(CRagdoll *this, IPhysicsObject *pPhysics)
{
  const Vector *(__thiscall *GetRagdollOrigin)(struct CRagdoll *); // eax
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  char IsAsleep; // al
  C_BaseEntity *v9; // eax
  Vector origin; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( this->m_lastUpdate != *(float *)(gpGlobals.m_Index + 12) )
  {
    this->m_ragdoll.list[0].pObject->GetPosition(
      this: this->m_ragdoll.list[0].pObject,
      a2: &this->m_origin,
      a3: nullptr);
    GetRagdollOrigin = this->GetRagdollOrigin;
    this->m_lastUpdate = *(float *)(gpGlobals.m_Index + 12);
    origin = *GetRagdollOrigin(this);
    RagdollComputeApproximateBbox(ragdoll: &this->m_ragdoll, &origin, outMins: &this->m_mins, outMaxs: &this->m_maxs);
    v4 = this->m_mins.x - origin.x;
    v5 = this->m_mins.y - origin.y;
    this->m_mins.z = this->m_mins.z - origin.z;
    this->m_mins.x = v4;
    this->m_mins.y = v5;
    v6 = this->m_maxs.x - origin.x;
    this->m_maxs.y = this->m_maxs.y - origin.y;
    v7 = this->m_maxs.z - origin.z;
    this->m_maxs.x = v6;
    this->m_maxs.z = v7;
    IsAsleep = RagdollIsAsleep(ragdoll: &this->m_ragdoll);
    this->m_allAsleep = IsAsleep;
    if ( IsAsleep == 0 )
    {
      if ( this->m_ragdoll.pGroup->IsInErrorState(this: this->m_ragdoll.pGroup) )
      {
        v9 = (C_BaseEntity *)this->m_ragdoll.list[0].pObject->GetGameData(this: this->m_ragdoll.list[0].pObject);
        RagdollSolveSeparation(a1: COERCE_FLOAT(&savedregs), ragdoll: &this->m_ragdoll, pEntity: v9);
      }
      CRagdoll::CheckSettleStationaryRagdoll(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B1C0
// Name: public: virtual int C_ServerRagdoll::InternalDrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
const struct model_t *__thiscall C_ServerRagdoll::InternalDrawModel(
        C_ServerRagdoll *this,
        vcollide_t *flags,
        IMaterial *instance)
{
  const struct model_t *v4; // edi
  IVModelInfoClient_vtbl *v5; // esi
  int ModelIndex; // eax
  int v7; // esi
  QAngle *m_ragAngles; // edi
  matrix3x4_t matrix; // [esp+8h] [ebp-34h] BYREF
  int ret; // [esp+38h] [ebp-4h]
  vcollide_t *pCollide; // [esp+44h] [ebp+8h]
  IMaterial *pWireframe; // [esp+48h] [ebp+Ch]

  v4 = C_BaseAnimating::InternalDrawModel(this, a2: (int)this, (int)flags, (const RenderableInstance_t *)instance);
  ret = (int)v4;
  if ( vcollide_wireframe.m_pParent == nullptr || vcollide_wireframe.m_pParent->m_Value.m_nValue == 0 )
    return v4;
  v5 = modelinfo->__vftable;
  ModelIndex = C_BaseEntity::GetModelIndex(this);
  pCollide = v5->GetVCollide(this: modelinfo, a2: ModelIndex);
  v7 = 0;
  pWireframe = materials->FindMaterial(
                 this: materials,
                 a2: "debug/debugwireframevertexcolor",
                 a3: "Other textures",
                 a4: 1,
                 a5: 0);
  if ( this->m_elementCount <= 0 )
    return v4;
  m_ragAngles = this->m_ragAngles;
  do
  {
    AngleMatrix(angles: m_ragAngles, position: (const Vector *)&m_ragAngles[-32], &matrix);
    engine->DebugDrawPhysCollide(
      this: engine,
      a2: pCollide->solids[v7++],
      a3: pWireframe,
      a4: &matrix,
      a5: &debugColor_3);
    ++m_ragAngles;
  }
  while ( v7 < this->m_elementCount );
  return (const struct model_t *)ret;
}

//------------------------------------------------------------------------------
// Address: 0x1015B2B0
// Name: public: virtual class CStudioHdr __near * C_ServerRagdoll::OnNewModel(void)
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall C_ServerRagdoll::OnNewModel(C_ServerRagdoll *this)
{
  CStudioHdr *result; // eax
  CStudioHdr *v3; // ebx
  IVModelInfoClient_vtbl *v4; // edi
  int ModelIndex; // eax
  vcollide_t *v6; // eax
  IVModelInfoClient_vtbl *v7; // edi
  int v8; // eax
  int v9; // eax
  const char *v10; // eax

  result = C_BaseAnimating::OnNewModel(this);
  v3 = result;
  if ( this->m_elementCount == 0 )
  {
    v4 = modelinfo->__vftable;
    ModelIndex = C_BaseEntity::GetModelIndex(this);
    v6 = v4->GetVCollide(this: modelinfo, a2: ModelIndex);
    if ( v6 != nullptr )
    {
      this->m_elementCount = RagdollExtractBoneIndices(boneIndexOut: this->m_boneIndex, pStudioHdr: v3, pCollide: v6);
    }
    else
    {
      v7 = modelinfo->__vftable;
      v8 = C_BaseEntity::GetModelIndex(this);
      v9 = (int)v7->GetModel(this: modelinfo, a2: v8);
      v10 = v7->GetModelName(this: modelinfo, a2: (const struct model_t *)v9);
      if ( v10 == nullptr )
        v10 = "<null>";
      _Msg(a1: "*** ERROR: C_ServerRagdoll::InitModel: %s missing vcollide data ***\n", v10);
      this->m_elementCount = 0;
    }
    CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(
      this: (CInterpolatedVarArrayBase<QAngle,0> *)&this->m_iv_ragPos,
      flCurrentTime: *(float *)(gpGlobals.m_Index + 12),
      newmax: this->m_elementCount);
    CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(
      this: (CInterpolatedVarArrayBase<QAngle,0> *)&this->m_iv_ragAngles,
      flCurrentTime: *(float *)(gpGlobals.m_Index + 12),
      newmax: this->m_elementCount);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015B3A0
// Name: public: virtual void C_ServerRagdoll::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ServerRagdoll::GetRenderBounds(C_ServerRagdoll *this, Vector *theMins, Vector *theMaxs)
{
  const char **p_m_ModelName; // esi
  char v4; // al
  char *v5; // edi
  const Vector *v6; // eax
  const Vector *v7; // [esp-10h] [ebp-14h]
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  p_m_ModelName = &this->m_ModelName;
  if ( (LOBYTE(this->m_Collision.m_vecMaxs.m_Value.z) & 0x40) != 0
    || (v4 = BYTE2(this->m_Collision.m_vecMaxs.m_Value.z)) == 2
    || v4 == 0 )
  {
    v5 = (char *)this - 4;
    C_BaseEntity::CalcAbsolutePosition(this: (C_ServerRagdoll *)((char *)this - 4), a2: (int)&savedregs);
    v7 = (const Vector *)(*((int (__thiscall **)(const char **))*p_m_ModelName + 2))(a1: p_m_ModelName);
    v6 = (const Vector *)(*((int (__thiscall **)(const char **))*p_m_ModelName + 1))(a1: p_m_ModelName);
    IRotateAABB(
      transform: (const matrix3x4_t *)(v5 + 1076),
      vecMinsIn: v6,
      vecMaxsIn: v7,
      vecMinsOut: theMins,
      vecMaxsOut: theMaxs);
  }
  else
  {
    *theMins = *(Vector *)(*((int (__thiscall **)(const char **))*p_m_ModelName + 1))(a1: &this->m_ModelName);
    *theMaxs = *(Vector *)(*((int (__thiscall **)(const char **))*p_m_ModelName + 2))(a1: p_m_ModelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B440
// Name: public: virtual void C_ServerRagdoll::AccumulateLayers(class IBoneSetup __near &,class Vector __near * const,class Quaternion __near * const,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ServerRagdoll::AccumulateLayers(
        C_ServerRagdoll *this,
        IBoneSetup *boneSetup,
        Vector *pos,
        Quaternion *q,
        float currentTime)
{
  CStudioHdr *StudioHdr; // eax
  int v8; // eax
  int m_nValue; // edi
  int m_Value; // edi
  CStudioHdr *v11; // eax
  const studiohdr_t *m_pStudioHdr; // eax
  int v13; // edx
  mstudioseqdesc_t *v14; // eax
  float boneSetupa; // [esp+30h] [ebp+8h]

  C_BaseEntity::PerformCustomPhysics(
    (vgui::MenuButton *)this,
    tx0: (int)boneSetup,
    ty0: (int)pos,
    tx1: (int)q,
    ty1: SLODWORD(currentTime));
  if ( this->m_nOverlaySequence.m_Value >= 0 )
  {
    StudioHdr = IBoneSetup::GetStudioHdr(this: boneSetup);
    v8 = StudioHdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: StudioHdr)
       : StudioHdr->m_pStudioHdr->numlocalseq;
    if ( this->m_nOverlaySequence.m_Value < v8 )
    {
      if ( r_sequence_debug.m_pParent != nullptr )
        m_nValue = r_sequence_debug.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( m_nValue == this->entindex(this: &this->IClientNetworkable) )
      {
        m_Value = this->m_nOverlaySequence.m_Value;
        boneSetupa = this->m_flCycle.m_Val;
        v11 = IBoneSetup::GetStudioHdr(this: boneSetup);
        if ( v11->m_pVModel != nullptr )
        {
          v14 = CStudioHdr::pSeqdesc_Internal(this: v11, i: m_Value);
        }
        else
        {
          m_pStudioHdr = v11->m_pStudioHdr;
          v13 = m_Value;
          if ( m_Value < 0 || m_Value >= m_pStudioHdr->numlocalseq )
            v13 = 0;
          v14 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v13 + m_pStudioHdr->localseqindex);
        }
        DevMsgRT(
          pMsg: "%8.4f : %30s : %5.3f : %4.2f\n",
          currentTime,
          (const char *)v14 + v14->szlabelindex,
          boneSetupa,
          this->m_flBlendWeightCurrent);
      }
      IBoneSetup::AccumulatePose(
        this: boneSetup,
        pos,
        q,
        sequence: this->m_nOverlaySequence.m_Value,
        cycle: this->m_flCycle.m_Val,
        flWeight: this->m_flBlendWeightCurrent,
        flTime: currentTime,
        pIKContext: this->m_pIk);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B5A0
// Name: public: virtual void C_ServerRagdoll::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ServerRagdoll::UpdateOnRemove(C_ServerRagdoll *this)
{
  unsigned int m_Index; // ecx
  C_BaseAnimating **v3; // eax
  C_BaseAnimating *v4; // edi
  const struct model_t *v5; // esi
  C_BaseAnimating::AutoAllowBoneAccess boneaccess; // [esp+Bh] [ebp-1h] BYREF

  m_Index = this->m_hUnragdoll.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (C_BaseAnimating **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      v4 = *v3;
      if ( *v3 != nullptr && v4->GetModel(this: &v4->IClientRenderable) != nullptr )
      {
        v5 = v4->GetModel(this: &v4->IClientRenderable);
        if ( v5 == this->GetModel(this: &this->IClientRenderable) )
        {
          C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
            this: &boneaccess,
            bAllowForNormalModels: true,
            bAllowForViewModels: false);
          C_BaseAnimating::CreateUnragdollInfo(this: v4, pRagdoll: this);
          C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: &boneaccess);
        }
      }
    }
  }
  C_BaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x1015B630
// Name: public: virtual void C_ServerRagdollAttached::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ServerRagdollAttached::OnDataChanged(C_ServerRagdollAttached *this, DataUpdateType_t updateType)
{
  unsigned int v3; // ecx
  IHandleEntity *m_pEntity; // eax
  bool v5; // zf
  char m_boneIndexAttached; // al

  C_BaseAnimating::OnDataChanged(this, updateType);
  v3 = *(_DWORD *)&this->m_bDisableCachedRenderBounds;
  if ( v3 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
  v5 = m_pEntity == nullptr;
  m_boneIndexAttached = this->m_boneIndexAttached;
  if ( m_boneIndexAttached != !v5 )
  {
    if ( m_boneIndexAttached != 0 )
      this->m_ragdollAttachedObjectIndex = *(int *)(gpGlobals.m_Index + 12);
    LOBYTE(this->m_boneIndexAttached) = !v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B6A0
// Name: public: CRagdoll::CRagdoll(void)
// Source: json
//------------------------------------------------------------------------------
CRagdoll *__thiscall CRagdoll::CRagdoll(CRagdoll *this)
{
  this->__vftable = (CRagdoll_vtbl *)&CRagdoll::`vftable';
  this->m_ragdoll.listCount = 0;
  this->m_vecLastOrigin.x = 0.0;
  this->m_vecLastOrigin.y = 0.0;
  this->m_vecLastOrigin.z = 0.0;
  this->m_flLastOriginChangeTime = -1.0;
  this->m_flAwakeTime = -1.0;
  this->m_lastUpdate = -3.4028235e38;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015B700
// Name: class CRagdoll __near * CreateRagdoll(class C_BaseEntity __near *,class CStudioHdr __near *,class Vector const __near &,int,struct matrix3x4_t const __near *,struct matrix3x4_t const __near *,struct matrix3x4_t const __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
CRagdoll *__cdecl CreateRagdoll(
        C_BaseEntity *ent,
        CStudioHdr *pstudiohdr,
        const Vector *forceVector,
        int forceBone,
        const matrix3x4_t *pDeltaBones0,
        const matrix3x4_t *pDeltaBones1,
        const matrix3x4_t *pCurrentBonePosition,
        float dt,
        bool bFixedConstraints)
{
  CRagdoll *v9; // eax
  CRagdoll *v10; // esi
  const studiohdr_t *m_pStudioHdr; // edx
  int studiohdr2index; // eax
  int v13; // ecx
  char *v14; // eax
  int v15; // ecx
  const char *name; // eax

  v9 = (CRagdoll *)MemAlloc_Alloc(nSize: 0x3E4u);
  if ( v9 != nullptr )
  {
    v9->__vftable = (CRagdoll_vtbl *)&CRagdoll::`vftable';
    v9->m_ragdoll.listCount = 0;
    v9->m_vecLastOrigin.x = 0.0;
    v9->m_vecLastOrigin.y = 0.0;
    v9->m_vecLastOrigin.z = 0.0;
    v9->m_flLastOriginChangeTime = -1.0;
    v9->m_flAwakeTime = -1.0;
    v9->m_lastUpdate = -3.4028235e38;
    v10 = v9;
  }
  else
  {
    v10 = nullptr;
  }
  CRagdoll::Init(
    this: v10,
    ent,
    pstudiohdr,
    forceVector,
    forceBone,
    pDeltaBones0,
    pDeltaBones1,
    pCurrentBonePosition,
    dt,
    bFixedConstraints);
  if ( v10->m_ragdoll.listCount > 0 )
    return v10;
  m_pStudioHdr = pstudiohdr->m_pStudioHdr;
  studiohdr2index = pstudiohdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v13 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8], v14 = (char *)m_pStudioHdr + studiohdr2index,
                                                                   v13 != 0)
    && &v14[v13] != nullptr )
  {
    v15 = *((_DWORD *)v14 + 5);
    if ( v15 != 0 )
      name = &v14[v15];
    else
      name = nullptr;
  }
  else
  {
    name = m_pStudioHdr->name;
  }
  _Msg(a1: "Bad ragdoll for %s\n", name);
  ((void (__thiscall *)(CRagdoll *, int))v10->dtr_IRagdoll)(a1: v10, a2: 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1015B800
// Name: public: virtual void C_ServerRagdoll::BuildTransformations(class CStudioHdr __near *,class Vector __near *,class Quaternion __near * const,struct matrix3x4_t const __near &,int,class CBoneBitList __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_ServerRagdoll::BuildTransformations(
        C_ServerRagdoll *this@<ecx>,
        int a2@<ebp>,
        CStudioHdr *hdr,
        Vector *pos,
        Quaternion *q,
        const matrix3x4_t *cameraTransform,
        int boneMask,
        CBoneBitList *boneComputed)
{
  CStudioHdr *v8; // edi
  const studiohdr_t *m_pStudioHdr; // ecx
  bool v11; // sf
  int v12; // eax
  int m_Value; // ecx
  const studiohdr_t *v14; // edx
  int v15; // eax
  mstudioseqdesc_t *v16; // eax
  bool v17; // cc
  int v18; // eax
  int *m_pMemory; // edx
  float m_flBlendWeightCurrent; // xmm1_4
  matrix3x4a_t *v21; // ecx
  int v22; // esi
  int v23; // edi
  const studiohdr_t *v24; // edx
  _BYTE v25[257]; // [esp-Ch] [ebp-15Ch] OVERLAPPED BYREF
  matrix3x4a_t bonematrix; // [esp+100h] [ebp-50h]
  int v27; // [esp+130h] [ebp-20h]
  C_ServerRagdoll *v28; // [esp+134h] [ebp-1Ch]
  mstudiobone_t *pbones; // [esp+138h] [ebp-18h]
  int i; // [esp+13Ch] [ebp-14h]
  mstudioseqdesc_t *v31; // [esp+140h] [ebp-10h]
  int v32; // [esp+144h] [ebp-Ch]
  void *v33; // [esp+148h] [ebp-8h]
  void *retaddr; // [esp+150h] [ebp+0h]

  v32 = a2;
  v33 = retaddr;
  v8 = hdr;
  v28 = this;
  if ( hdr != nullptr )
  {
    memset(dst: (int)v25, value: nullptr, count: 0x100u);
    m_pStudioHdr = hdr->m_pStudioHdr;
    v11 = this->m_nOverlaySequence.m_Value < 0;
    LODWORD(bonematrix.m_flMatVal[2][3]) = (char *)hdr->m_pStudioHdr + hdr->m_pStudioHdr->boneindex;
    v31 = nullptr;
    if ( !v11 )
    {
      v12 = hdr->m_pVModel != nullptr ? CStudioHdr::GetNumSeq_Internal(this: hdr) : m_pStudioHdr->numlocalseq;
      m_Value = this->m_nOverlaySequence.m_Value;
      if ( m_Value < v12 )
      {
        if ( hdr->m_pVModel != nullptr )
        {
          v16 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: this->m_nOverlaySequence.m_Value);
        }
        else
        {
          v14 = hdr->m_pStudioHdr;
          v15 = this->m_nOverlaySequence.m_Value;
          if ( m_Value < 0 || m_Value >= v14->numlocalseq )
            v15 = 0;
          v16 = (mstudioseqdesc_t *)((char *)v14 + 212 * v15 + v14->localseqindex);
        }
        v31 = v16;
      }
    }
    v17 = this->m_elementCount <= 0;
    v27 = 0;
    if ( !v17 )
    {
      pbones = (mstudiobone_t *)this->m_ragAngles;
      i = (int)this->m_boneIndex;
      do
      {
        v18 = *(_DWORD *)i;
        if ( *(int *)i >= 0 )
        {
          m_pMemory = v8->m_boneFlags.m_Memory.m_pMemory;
          LODWORD(bonematrix.m_flMatVal[2][2]) = 4 * v18;
          if ( (boneMask & m_pMemory[v18]) != 0 )
          {
            m_flBlendWeightCurrent = this->m_flBlendWeightCurrent;
            v21 = &this->m_BoneAccessor.m_pBones[v18];
            v25[v18] = 1;
            if ( m_flBlendWeightCurrent == 0.0
              || v31 == nullptr
              || *(float *)((char *)&v31->baseptr + LODWORD(bonematrix.m_flMatVal[2][2]) + v31->weightlistindex) == 0.0 )
            {
              AngleMatrix(angles: (const QAngle *)pbones, position: (const Vector *)&pbones[-2].quat.y, matrix: v21);
            }
            else
            {
              v25[v18] = 0;
            }
          }
          v8 = hdr;
        }
        i += 4;
        pbones = (mstudiobone_t *)((char *)pbones + 12);
        ++v27;
      }
      while ( v27 < this->m_elementCount );
    }
    v22 = 0;
    if ( v8->m_pStudioHdr->numbones > 0 )
    {
      v23 = 0;
      i = (int)q;
      pbones = (mstudiobone_t *)pos;
      v31 = (mstudioseqdesc_t *)(LODWORD(bonematrix.m_flMatVal[2][3]) + 4);
      do
      {
        if ( (boneMask & hdr->m_boneFlags.m_Memory.m_pMemory[v22]) != 0
          && v25[v22] == 0
          && !CalcProceduralBone(pStudioHdr: hdr, iBone: v22, bonetoworld: &v28->m_BoneAccessor) )
        {
          QuaternionMatrix(q: (const Quaternion *)i, pos: (const Vector *)pbones, matrix: (matrix3x4_t *)&v25[256]);
          if ( v31->baseptr == -1 )
            ConcatTransforms(
              in1: cameraTransform,
              in2: (const matrix3x4_t *)&v25[256],
              out: &v28->m_BoneAccessor.m_pBones[v23]);
          else
            ConcatTransforms_Aligned(
              m0: &v28->m_BoneAccessor.m_pBones[v31->baseptr],
              m1: (const matrix3x4a_t *)&v25[256],
              out: &v28->m_BoneAccessor.m_pBones[v23]);
        }
        v24 = hdr->m_pStudioHdr;
        pbones = (mstudiobone_t *)((char *)pbones + 12);
        i += 16;
        v31 = (mstudioseqdesc_t *)((char *)v31 + 216);
        ++v22;
        ++v23;
      }
      while ( v22 < v24->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BA60
// Name: public: void ragdoll_memory_list_t::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ragdoll_memory_list_t::Update(ragdoll_memory_list_t *this)
{
  int i; // edx
  ragdoll_remember_t *m_pMemory; // eax
  int m_Size; // esi

  if ( this->tickCount <= *(_DWORD *)(gpGlobals.m_Index + 24) )
  {
    for ( i = this->list.m_Size - 1; i >= 0; --i )
    {
      m_pMemory = this->list.m_Memory.m_pMemory;
      if ( this->list.m_Memory.m_pMemory[i].tickCount != *(_DWORD *)(gpGlobals.m_Index + 24) )
      {
        m_Size = this->list.m_Size;
        if ( m_Size > 0 )
        {
          if ( i != m_Size - 1 )
          {
            m_pMemory[i].ragdoll = m_pMemory[m_Size - 1].ragdoll;
            m_pMemory[i].tickCount = m_pMemory[m_Size - 1].tickCount;
          }
          --this->list.m_Size;
        }
      }
    }
  }
  else
  {
    this->list.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BAC0
// Name: bool WasRagdollCreatedOnCurrentTick(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WasRagdollCreatedOnCurrentTick(C_BaseEntity *pRagdoll)
{
  int v1; // eax

  ragdoll_memory_list_t::Update(this: &gRagdolls);
  v1 = gRagdolls.list.m_Size - 1;
  if ( gRagdolls.list.m_Size - 1 < 0 )
    return 0;
  while ( gRagdolls.list.m_Memory.m_pMemory[v1].ragdoll != pRagdoll )
  {
    if ( --v1 < 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015BAF0
// Name: public: virtual char const __near * CInterpolatedVarArrayBase<class Vector,0>::GetDebugName(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall CInterpolatedVarArrayBase<Vector,0>::GetDebugName(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x1015BB40
// Name: public: virtual void CInterpolatedVarArrayBase<class Vector,1>::NoteLastNetworkedValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,1>::NoteLastNetworkedValue(CInterpolatedVarArrayBase<QAngle,0> *this)
{
  memcpy(
    dst: (unsigned __int8 *)this->m_LastNetworkedValue,
    src: (unsigned __int8 *)this->m_pValue,
    count: 12 * this->m_nMaxCount);
  this->m_LastNetworkedTime = g_flLastPacketTimestamp;
}

//------------------------------------------------------------------------------
// Address: 0x1015BB80
// Name: public: void CInterpolatedVarEntryBase<class Vector,1>::Init(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarEntryBase<Vector,1>::Init(
        CInterpolatedVarEntryBase<QAngle,1> *this,
        unsigned int maxCount)
{
  if ( maxCount != 0 )
  {
    if ( maxCount != this->count )
    {
      C_BaseEntity::operator delete(pMem: (void *)this->value);
      this->value = nullptr;
      this->count = 0;
    }
    if ( this->value == nullptr )
    {
      this->count = maxCount;
      this->value = (QAngle *)MemAlloc_Alloc(nSize: (12 * (unsigned __int64)maxCount) >> 32 != 0 ? -1 : 12 * maxCount);
    }
  }
  else
  {
    C_BaseEntity::operator delete(pMem: (void *)this->value);
    this->value = nullptr;
    this->count = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BBF0
// Name: protected: void CInterpolatedVarArrayBase<class Vector,1>::_Interpolate(class Vector __near *,float,struct CInterpolatedVarEntryBase<class Vector,1> __near *,struct CInterpolatedVarEntryBase<class Vector,1> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,1>::_Interpolate(
        CInterpolatedVarArrayBase<Vector,1> *this,
        Vector *out,
        float frac,
        CInterpolatedVarEntryBase<Vector,1> *start,
        CInterpolatedVarEntryBase<Vector,1> *end)
{
  int v6; // esi
  Vector *value; // eax
  float *p_z; // edx
  Vector *v9; // edi
  Vector *v10; // edx
  Vector *v11; // ebx
  int v12; // ecx
  float *v13; // eax
  float v14; // xmm5_4
  float v15; // xmm6_4
  __int64 v16; // [esp+8h] [ebp-24h]
  __int64 v17; // [esp+14h] [ebp-18h]
  int v18; // [esp+20h] [ebp-Ch]
  int v19; // [esp+24h] [ebp-8h]
  Vector *outa; // [esp+34h] [ebp+8h]
  int i; // [esp+3Ch] [ebp+10h]

  if ( start == end )
  {
    v6 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      value = end->value;
      p_z = &out->z;
      do
      {
        ++v6;
        *(p_z - 2) = value->x;
        ++value;
        p_z += 3;
        *(p_z - 4) = value[-1].y;
        *(p_z - 3) = value[-1].z;
      }
      while ( v6 < this->m_nMaxCount );
    }
  }
  else
  {
    i = 0;
    if ( this->m_nMaxCount != 0 )
    {
      v9 = start->value;
      v10 = out;
      v11 = end->value;
      v18 = (char *)v11 - (char *)v9;
      outa = (Vector *)((char *)out - (char *)v9);
      v19 = (char *)v11 - (char *)v10;
      v12 = 0;
      v13 = &v9->z;
      do
      {
        if ( this->m_bLooping[v12] != 0 )
        {
          v16 = *(_QWORD *)((char *)&v11->x + (_DWORD)((char *)v13 - 8 - (_DWORD)v9));
          v17 = *((_QWORD *)v13 - 1);
          *(float *)((char *)v13 + (_DWORD)outa) = (float)(*(float *)((char *)&v11->z
                                                                    + (_DWORD)((char *)v13 - 8 - (_DWORD)v9))
                                                         * frac)
                                                 + (float)(*v13 * (float)(1.0 - frac));
          v12 = i;
          v10->x = (float)(*(float *)&v16 * frac) + (float)(*(float *)&v17 * (float)(1.0 - frac));
          v10->y = (float)(*((float *)&v16 + 1) * frac) + (float)(*((float *)&v17 + 1) * (float)(1.0 - frac));
        }
        else
        {
          v14 = *(v13 - 1) + (float)((float)(*(float *)((char *)v13 + v18 - 4) - *(v13 - 1)) * frac);
          v15 = *v13 + (float)((float)(*(float *)((char *)v13 + v18) - *v13) * frac);
          v10->x = *(v13 - 2) + (float)((float)(*(float *)((char *)&v10->x + v19) - *(v13 - 2)) * frac);
          v10->y = v14;
          *(float *)((char *)v13 + (_DWORD)outa) = v15;
        }
        ++v12;
        v13 += 3;
        ++v10;
        i = v12;
      }
      while ( v12 < this->m_nMaxCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BDB0
// Name: protected: void CInterpolatedVarArrayBase<class Vector,1>::TimeFixup2_Hermite(struct CInterpolatedVarEntryBase<class Vector,1> __near &,struct CInterpolatedVarEntryBase<class Vector,1> __near * __near &,struct CInterpolatedVarEntryBase<class Vector,1> __near * __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,1>::TimeFixup2_Hermite(
        CInterpolatedVarArrayBase<Vector,1> *this,
        CInterpolatedVarEntryBase<Vector,1> *fixup,
        CInterpolatedVarEntryBase<Vector,1> **prev,
        CInterpolatedVarEntryBase<Vector,1> **start,
        float dt1,
        bool bAllowHermiteFix)
{
  CInterpolatedVarArrayBase<Vector,1> *v6; // edx
  float flChangeTime; // xmm1_4
  CInterpolatedVarEntryBase<Vector,1> **v8; // eax
  float v9; // xmm0_4
  int v10; // ebx
  float v11; // xmm7_4
  Vector *value; // ecx
  int v13; // eax
  float *p_x; // edi
  float *v15; // esi
  Vector *v16; // edx
  __int64 v17; // xmm0_8
  float z; // edx
  float v19; // xmm1_4
  Vector *v20; // edx
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  Vector *v26; // edx
  float v27[3]; // [esp+0h] [ebp-34h] BYREF
  float v28[3]; // [esp+Ch] [ebp-28h] BYREF
  __int64 v29; // [esp+18h] [ebp-1Ch]
  float v30; // [esp+20h] [ebp-14h]
  __int64 v31; // [esp+24h] [ebp-10h]
  float v32; // [esp+2Ch] [ebp-8h]
  CInterpolatedVarArrayBase<Vector,1> *v33; // [esp+30h] [ebp-4h]
  float frac; // [esp+48h] [ebp+14h]

  v6 = this;
  flChangeTime = (*start)->flChangeTime;
  v8 = prev;
  v9 = flChangeTime - (*prev)->flChangeTime;
  v33 = this;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(dt1 - v9) & _mask__AbsFloat_) > 0.000099999997 && v9 > 0.000099999997 )
  {
    v10 = 0;
    fixup->flChangeTime = flChangeTime - dt1;
    v11 = dt1 / v9;
    frac = dt1 / v9;
    if ( this->m_nMaxCount != 0 )
    {
      value = (*prev)->value;
      v13 = 0;
      p_x = &value->x;
      while ( 1 )
      {
        if ( v6->m_bLooping[v10] != 0 )
        {
          if ( g_bHermiteFix && bAllowHermiteFix )
          {
            v15 = p_x;
          }
          else
          {
            v16 = (*start)->value;
            v17 = *(_QWORD *)&v16[v13].x;
            z = v16[v13].z;
            v29 = v17;
            v31 = *(_QWORD *)&value[v13].x;
            v30 = z;
            v32 = value[v13].z;
            v19 = 1.0 - (float)(1.0 - v11);
            v28[0] = (float)((float)(1.0 - v11) * *(float *)&v17) + (float)(*(float *)&v31 * v19);
            v28[1] = (float)((float)(1.0 - v11) * *((float *)&v17 + 1)) + (float)(*((float *)&v31 + 1) * v19);
            v28[2] = (float)((float)(1.0 - v11) * z) + (float)(v32 * v19);
            v15 = v28;
          }
        }
        else if ( g_bHermiteFix && bAllowHermiteFix )
        {
          v15 = p_x;
        }
        else
        {
          v20 = (*start)->value;
          v21 = p_x[2];
          v22 = 1.0 - v11;
          v23 = (float)(1.0 - v11) * (float)(v20[v13].z - v21);
          v24 = *p_x + (float)((float)(1.0 - v11) * (float)(v20[v13].x - *p_x));
          v11 = frac;
          v25 = p_x[1] + (float)(v22 * (float)(v20[v13].y - p_x[1]));
          v27[0] = v24;
          v27[1] = v25;
          v27[2] = v21 + v23;
          v15 = v27;
        }
        v26 = fixup->value;
        v26[v13].x = *v15;
        ++v10;
        v26[v13++].y = v15[1];
        p_x += 3;
        v26[v13 - 1].z = v15[2];
        if ( v10 >= v33->m_nMaxCount )
          break;
        v6 = v33;
      }
      v8 = prev;
    }
    *v8 = fixup;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BFB0
// Name: public: void CInterpolatedVarArrayBase<class Vector,1>::AddToHead(float,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,1>::AddToHead(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        float changeTime,
        const QAngle *values,
        bool bFlushNewer)
{
  unsigned int m_firstElement; // eax
  unsigned int m_maxElement; // ecx
  unsigned __int16 m_count; // dx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1> > *p_m_VarHistory; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // ebx
  int v19; // ecx
  int v20; // ecx
  int v21; // eax
  int v22; // ebx
  int v23; // ecx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  unsigned int m_nMaxCount; // edi
  int v29; // esi
  unsigned __int8 *v30; // esi
  int newslot; // [esp+10h] [ebp+10h]

  if ( bFlushNewer )
  {
    while ( this->m_VarHistory.m_count != 0 )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      if ( m_firstElement >= m_maxElement )
        m_firstElement -= m_maxElement;
      if ( (float)(this->m_VarHistory.m_pElements[m_firstElement].flChangeTime + 0.000099999997) <= changeTime )
        break;
      m_count = this->m_VarHistory.m_count;
      if ( m_count != 0 )
      {
        v8 = this->m_VarHistory.m_maxElement;
        v9 = this->m_VarHistory.m_firstElement + 1;
        if ( v9 >= v8 )
          LOWORD(v9) = v9 - v8;
        this->m_VarHistory.m_firstElement = v9;
        this->m_VarHistory.m_count = m_count - 1;
      }
    }
    p_m_VarHistory = &this->m_VarHistory;
    CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
      this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_VarHistory,
      capSize: this->m_VarHistory.m_count + 1);
    v11 = this->m_VarHistory.m_maxElement;
    v12 = this->m_VarHistory.m_firstElement;
    ++this->m_VarHistory.m_count;
    v13 = v12 + v11 - 1;
    if ( v13 >= v11 )
      LOWORD(v13) = v13 - v11;
    this->m_VarHistory.m_firstElement = v13;
    newslot = 0;
  }
  else
  {
    p_m_VarHistory = &this->m_VarHistory;
    CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
      this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_VarHistory,
      capSize: this->m_VarHistory.m_count + 1);
    v14 = this->m_VarHistory.m_maxElement;
    v15 = this->m_VarHistory.m_firstElement;
    ++this->m_VarHistory.m_count;
    v16 = v15 + v14 - 1;
    if ( v16 >= v14 )
      LOWORD(v16) = v16 - v14;
    v17 = 1;
    this->m_VarHistory.m_firstElement = v16;
    newslot = 0;
    if ( this->m_VarHistory.m_count > 1u )
    {
      do
      {
        v18 = this->m_VarHistory.m_maxElement;
        v19 = v17 + this->m_VarHistory.m_firstElement;
        if ( v19 >= v18 )
          v19 -= v18;
        if ( changeTime >= p_m_VarHistory->m_pElements[v19].flChangeTime )
          break;
        v20 = this->m_VarHistory.m_firstElement;
        v21 = v20 + v17;
        if ( v20 + v17 >= v18 )
          v21 -= v18;
        v22 = v20 + newslot;
        v23 = this->m_VarHistory.m_maxElement;
        if ( v22 >= v23 )
          v22 -= v23;
        v24 = (int)&p_m_VarHistory->m_pElements[v21];
        v25 = (int)&p_m_VarHistory->m_pElements[v22];
        *(_DWORD *)(v25 + 8) = *(_DWORD *)(v24 + 8);
        *(_DWORD *)(v25 + 4) = *(_DWORD *)(v24 + 4);
        *(float *)v25 = *(float *)v24;
        *(_DWORD *)(v24 + 8) = 0;
        *(_DWORD *)(v24 + 4) = 0;
        newslot = v17++;
      }
      while ( v17 < this->m_VarHistory.m_count );
    }
  }
  v26 = p_m_VarHistory->m_maxElement;
  v27 = newslot + p_m_VarHistory->m_firstElement;
  if ( v27 >= v26 )
    v27 -= v26;
  m_nMaxCount = this->m_nMaxCount;
  v29 = (int)&p_m_VarHistory->m_pElements[v27];
  *(float *)v29 = changeTime;
  if ( m_nMaxCount != 0 )
  {
    if ( m_nMaxCount != *(_DWORD *)(v29 + 4) )
    {
      C_BaseEntity::operator delete(pMem: *(void **)(v29 + 8));
      *(_DWORD *)(v29 + 8) = 0;
      *(_DWORD *)(v29 + 4) = 0;
    }
    if ( *(_DWORD *)(v29 + 8) == 0 )
    {
      *(_DWORD *)(v29 + 4) = m_nMaxCount;
      *(_DWORD *)(v29 + 8) = MemAlloc_Alloc(nSize: (12 * (unsigned __int64)m_nMaxCount) >> 32 != 0 ? -1 : 12 * m_nMaxCount);
    }
  }
  else
  {
    C_BaseEntity::operator delete(pMem: *(void **)(v29 + 8));
    *(_DWORD *)(v29 + 8) = 0;
    *(_DWORD *)(v29 + 4) = 0;
  }
  v30 = *(unsigned __int8 **)(v29 + 8);
  if ( v30 != nullptr && m_nMaxCount != 0 )
    memcpy(dst: v30, src: (unsigned __int8 *)values, count: 12 * m_nMaxCount);
}

//------------------------------------------------------------------------------
// Address: 0x1015C1B0
// Name: protected: bool CInterpolatedVarArrayBase<class Vector,1>::GetInterpolationInfo(class CInterpolatedVarArrayBase<class Vector,1>::CInterpolationInfo __near *,float,float,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInterpolatedVarArrayBase<Vector,1>::GetInterpolationInfo(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        CInterpolatedVarArrayBase<QAngle,1>::CInterpolationInfo *pInfo,
        float currentTime,
        float interpolation_amount,
        int *pNoMoreChanges)
{
  float v5; // xmm0_4
  int v6; // esi
  int m_maxElement; // edi
  int v8; // eax
  float flChangeTime; // xmm1_4
  int newer; // eax
  int v12; // ebx
  int v13; // edi
  int v14; // eax
  float v15; // xmm2_4
  float v16; // xmm0_4
  int v17; // edi
  int v18; // eax
  int v19; // edi
  int m_firstElement; // ebx
  unsigned int v21; // edi
  int v22; // eax
  int v23; // esi
  QAngle *value; // ecx
  int v25; // eax
  QAngle *v26; // eax
  int v27; // edx
  unsigned int v28; // eax
  QAngle *v29; // edi
  int v30; // edx
  QAngle *v31; // ecx
  int older; // eax
  int v33; // [esp+0h] [ebp-4h]
  CInterpolatedVarEntryBase<QAngle,1> *currentTimea; // [esp+10h] [ebp+Ch]
  unsigned int interpolation_amounta; // [esp+14h] [ebp+10h]

  v5 = currentTime - interpolation_amount;
  pInfo->m_bHermite = false;
  pInfo->frac = 0.0;
  pInfo->newer = -1;
  pInfo->older = -1;
  pInfo->oldest = -1;
  v6 = 0;
  if ( this->m_VarHistory.m_count == 0 )
  {
LABEL_7:
    newer = pInfo->newer;
    if ( newer == -1 )
    {
      older = pInfo->older;
      pInfo->newer = older;
      return older != -1;
    }
    else
    {
      pInfo->older = newer;
      return true;
    }
  }
  while ( 1 )
  {
    pInfo->older = v6;
    m_maxElement = this->m_VarHistory.m_maxElement;
    v8 = v6 + this->m_VarHistory.m_firstElement;
    if ( v8 >= m_maxElement )
      v8 -= m_maxElement;
    flChangeTime = this->m_VarHistory.m_pElements[v8].flChangeTime;
    if ( flChangeTime == 0.0 )
      goto LABEL_7;
    if ( flChangeTime <= v5 )
      break;
    pInfo->newer = v6++;
    if ( v6 >= this->m_VarHistory.m_count )
      goto LABEL_7;
  }
  v12 = pInfo->newer;
  if ( v12 != -1 )
  {
    v13 = this->m_VarHistory.m_maxElement;
    v14 = v12 + this->m_VarHistory.m_firstElement;
    if ( v14 >= v13 )
      v14 -= v13;
    v15 = this->m_VarHistory.m_pElements[v14].flChangeTime - flChangeTime;
    if ( v15 > 0.000099999997 )
    {
      v16 = (float)(v5 - flChangeTime) / v15;
      pInfo->frac = v16;
      if ( v16 >= 2.0 )
        v16 = 2.0;
      pInfo->frac = v16;
      v17 = v6 + 1;
      if ( (this->m_fType & 0x10) == 0 && v17 >= 0 && v17 < this->m_VarHistory.m_count )
      {
        pInfo->oldest = v17;
        v18 = v17 + this->m_VarHistory.m_firstElement;
        v19 = this->m_VarHistory.m_maxElement;
        if ( v18 >= v19 )
          v18 -= v19;
        if ( (float)(flChangeTime - this->m_VarHistory.m_pElements[v18].flChangeTime) > 0.000099999997 )
          pInfo->m_bHermite = true;
      }
      if ( pNoMoreChanges != nullptr && v12 == (this->m_VarHistory.m_count != 0) - 1 )
      {
        m_firstElement = this->m_VarHistory.m_firstElement;
        interpolation_amounta = 12 * this->m_nMaxCount;
        v21 = interpolation_amounta;
        v22 = m_firstElement + v6;
        v23 = this->m_VarHistory.m_maxElement;
        if ( v22 >= v23 )
          v22 -= v23;
        currentTimea = this->m_VarHistory.m_pElements;
        value = currentTimea[v22].value;
        v25 = m_firstElement + pInfo->newer;
        v33 = v25;
        if ( v25 >= v23 )
          v25 -= v23;
        v26 = currentTimea[v25].value;
        if ( interpolation_amounta >= 4 )
        {
          while ( LODWORD(v26->x) == LODWORD(value->x) )
          {
            v21 -= 4;
            value = (QAngle *)((char *)value + 4);
            v26 = (QAngle *)((char *)v26 + 4);
            if ( v21 < 4 )
              goto LABEL_35;
          }
          return true;
        }
LABEL_35:
        if ( v21 == 0
          || LOBYTE(value->x) == LOBYTE(v26->x)
          && (v21 <= 1 || BYTE1(value->x) == BYTE1(v26->x) && (v21 <= 2 || BYTE2(value->x) == BYTE2(v26->x))) )
        {
          if ( !pInfo->m_bHermite )
            goto LABEL_55;
          v27 = m_firstElement + pInfo->oldest;
          v28 = interpolation_amounta;
          if ( v27 >= v23 )
            v27 -= v23;
          v29 = currentTimea[v27].value;
          v30 = v33;
          if ( v33 >= v23 )
            v30 = v33 - v23;
          v31 = currentTimea[v30].value;
          if ( interpolation_amounta >= 4 )
          {
            while ( LODWORD(v31->x) == LODWORD(v29->x) )
            {
              v28 -= 4;
              v29 = (QAngle *)((char *)v29 + 4);
              v31 = (QAngle *)((char *)v31 + 4);
              if ( v28 < 4 )
                goto LABEL_49;
            }
            return true;
          }
LABEL_49:
          if ( v28 == 0
            || LOBYTE(v29->x) == LOBYTE(v31->x)
            && (v28 <= 1 || BYTE1(v29->x) == BYTE1(v31->x) && (v28 <= 2 || BYTE2(v29->x) == BYTE2(v31->x))) )
          {
LABEL_55:
            *pNoMoreChanges = 1;
          }
        }
      }
    }
    return true;
  }
  pInfo->newer = v6;
  if ( pNoMoreChanges != nullptr )
    *pNoMoreChanges = 1;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1015C440
// Name: protected: void CInterpolatedVarArrayBase<class Vector,1>::_Extrapolate(class Vector __near *,struct CInterpolatedVarEntryBase<class Vector,1> __near *,struct CInterpolatedVarEntryBase<class Vector,1> __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,1>::_Extrapolate(
        CInterpolatedVarArrayBase<Vector,1> *this,
        Vector *pOut,
        CInterpolatedVarEntryBase<Vector,1> *pOld,
        CInterpolatedVarEntryBase<Vector,1> *pNew,
        float flDestinationTime,
        float flMaxExtrapolationAmount)
{
  float flChangeTime; // xmm0_4
  float v7; // xmm1_4
  int v8; // ebx
  float v9; // xmm0_4
  int v10; // edi
  float v11; // xmm7_4
  float *v12; // esi
  Vector *value; // eax
  Vector *v14; // edx
  char *v15; // edi
  float v16; // xmm2_4
  float v17; // xmm3_4
  int v18; // esi
  float *p_z; // edx
  float *v20; // eax
  Vector *pOuta; // [esp+8h] [ebp+8h]

  flChangeTime = pNew->flChangeTime;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(pOld->flChangeTime - pNew->flChangeTime) & _mask__AbsFloat_) < 0.001
    || flChangeTime >= flDestinationTime )
  {
    v18 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      p_z = &pOut->z;
      do
      {
        v20 = (float *)((char *)&pNew->value->x + (unsigned int)p_z - 8 - (_DWORD)pOut);
        ++v18;
        p_z += 3;
        *(p_z - 5) = *v20;
        *(p_z - 4) = v20[1];
        *(p_z - 3) = v20[2];
      }
      while ( v18 < this->m_nMaxCount );
    }
  }
  else
  {
    v7 = flDestinationTime - flChangeTime;
    if ( flMaxExtrapolationAmount <= (float)(flDestinationTime - flChangeTime) )
      v7 = flMaxExtrapolationAmount;
    v8 = 0;
    v9 = flChangeTime - pOld->flChangeTime;
    if ( this->m_nMaxCount != 0 )
    {
      v10 = -8 - (_DWORD)pOut;
      v11 = (float)((float)(1.0 / v9) * v7) + 1.0;
      v12 = &pOut->z;
      for ( pOuta = (Vector *)(-8 - (_DWORD)pOut); ; v10 = (int)pOuta )
      {
        value = pOld->value;
        v14 = pNew->value;
        v15 = (char *)v12 + v10;
        v16 = *(float *)&v15[(_DWORD)value + 4]
            + (float)(v11 * (float)(*(float *)&v15[(_DWORD)v14 + 4] - *(float *)&v15[(_DWORD)value + 4]));
        v17 = *(float *)&v15[(_DWORD)value + 8]
            + (float)(v11 * (float)(*(float *)&v15[(_DWORD)v14 + 8] - *(float *)&v15[(_DWORD)value + 8]));
        *(v12 - 2) = *(float *)&v15[(_DWORD)value]
                   + (float)((float)(*(float *)&v15[(_DWORD)v14] - *(float *)&v15[(_DWORD)value]) * v11);
        *(v12 - 1) = v16;
        *v12 = v17;
        ++v8;
        v12 += 3;
        if ( v8 >= this->m_nMaxCount )
          break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C590
// Name: public: virtual void CInterpolatedVarArrayBase<class Vector,1>::Copy(class IInterpolatedVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,1>::Copy(
        CInterpolatedVarArrayBase<Vector,1> *this,
        IInterpolatedVar *pInSrc)
{
  unsigned __int16 *v3; // ebx
  unsigned __int8 m_nMaxCount; // al
  int v5; // edx
  int v6; // esi
  int v7; // eax
  Vector *m_LastNetworkedValue; // ecx
  double v9; // st7
  int m_maxElement; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  CInterpolatedVarEntryBase<Vector,1> *v16; // esi
  int v17; // ecx
  int v18; // ecx
  int v19; // eax
  unsigned __int8 *v20; // edx
  double v21; // st7
  IInterpolatedVar *v22; // eax
  Vector *v23; // eax
  unsigned __int8 *value; // esi
  unsigned __int8 *src; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]
  IInterpolatedVar *pInSrca; // [esp+1Ch] [ebp+8h]

  v3 = (unsigned __int16 *)__RTDynamicCast(
                             inptr: pInSrc,
                             VfDelta: 0,
                             SrcType: &IInterpolatedVar `RTTI Type Descriptor',
                             TargetType: &CInterpolatedVarArrayBase<Vector,1> `RTTI Type Descriptor',
                             isReference: 0);
  if ( v3 != nullptr )
  {
    m_nMaxCount = this->m_nMaxCount;
    if ( *((_BYTE *)v3 + 29) == m_nMaxCount )
    {
      v5 = 0;
      if ( m_nMaxCount != 0 )
      {
        v6 = 0;
        do
        {
          v7 = *((_DWORD *)v3 + 5);
          m_LastNetworkedValue = this->m_LastNetworkedValue;
          m_LastNetworkedValue[v6].x = *(float *)(v7 + v6 * 12);
          ++v5;
          v9 = *(float *)(v7 + v6 * 12 + 4);
          m_LastNetworkedValue[v6++].y = v9;
          m_LastNetworkedValue[v6 - 1].z = *(float *)(v7 + v6 * 12 - 4);
          this->m_bLooping[v5 - 1] = *(_BYTE *)(v5 + *((_DWORD *)v3 + 8) - 1);
        }
        while ( v5 < this->m_nMaxCount );
      }
      this->m_LastNetworkedTime = *((float *)v3 + 6);
      *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
      i = 0;
      if ( v3[8] != 0 )
      {
        do
        {
          CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
            this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_VarHistory,
            capSize: this->m_VarHistory.m_count + 1);
          ++this->m_VarHistory.m_count;
          m_maxElement = this->m_VarHistory.m_maxElement;
          v11 = this->m_VarHistory.m_count + this->m_VarHistory.m_firstElement - 1;
          if ( v11 >= m_maxElement )
            v11 -= m_maxElement;
          v12 = v11 + this->m_VarHistory.m_firstElement;
          v13 = this->m_VarHistory.m_maxElement;
          if ( v12 >= v13 )
            v12 -= v13;
          v14 = v12;
          v15 = i + v3[7];
          v16 = &this->m_VarHistory.m_pElements[v14];
          v17 = v3[6];
          if ( v15 >= v17 )
            v15 -= v17;
          v18 = *((_DWORD *)v3 + 2);
          v19 = 3 * v15;
          v20 = *(unsigned __int8 **)(v18 + 4 * v19 + 8);
          v21 = *(float *)(v18 + 4 * v19);
          v22 = (IInterpolatedVar *)this->m_nMaxCount;
          v16->flChangeTime = v21;
          src = v20;
          pInSrca = v22;
          if ( v22 != nullptr )
          {
            if ( v22 != (IInterpolatedVar *)v16->count )
            {
              C_BaseEntity::operator delete(pMem: (void *)v16->value);
              v16->value = nullptr;
              v16->count = 0;
              v22 = pInSrca;
            }
            if ( v16->value != nullptr )
              goto LABEL_20;
            v16->count = (int)v22;
            v23 = (Vector *)MemAlloc_Alloc(nSize: (12 * (unsigned __int64)(unsigned int)v22) >> 32 != 0 ? -1 : 12 * (_DWORD)v22);
          }
          else
          {
            C_BaseEntity::operator delete(pMem: (void *)v16->value);
            v23 = nullptr;
            v16->count = 0;
          }
          v16->value = v23;
          v22 = pInSrca;
LABEL_20:
          value = (unsigned __int8 *)v16->value;
          if ( value != nullptr && v22 != nullptr )
            memcpy(dst: value, src, count: 12 * (_DWORD)v22);
          ++i;
        }
        while ( i < v3[8] );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C730
// Name: public: virtual void CInterpolatedVarArrayBase<class Vector,0>::RestoreToLastNetworked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,0>::RestoreToLastNetworked(CInterpolatedVarArrayBase<QAngle,0> *this)
{
  memcpy(
    dst: (unsigned __int8 *)this->m_pValue,
    src: (unsigned __int8 *)this->m_LastNetworkedValue,
    count: 12 * this->m_nMaxCount);
}

//------------------------------------------------------------------------------
// Address: 0x1015C750
// Name: protected: void CInterpolatedVarArrayBase<class QAngle,1>::_Extrapolate(class QAngle __near *,struct CInterpolatedVarEntryBase<class QAngle,1> __near *,struct CInterpolatedVarEntryBase<class QAngle,1> __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,1>::_Extrapolate(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        QAngle *pOut,
        CInterpolatedVarEntryBase<QAngle,1> *pOld,
        CInterpolatedVarEntryBase<QAngle,1> *pNew,
        float flDestinationTime,
        float flMaxExtrapolationAmount)
{
  CInterpolatedVarEntryBase<QAngle,1> *v6; // edx
  float flChangeTime; // xmm3_4
  float v8; // xmm0_4
  int v10; // edi
  float v11; // xmm1_4
  int v12; // eax
  float *v13; // esi
  QAngle *v14; // eax
  int v15; // esi
  float *p_z; // ecx
  float *v17; // eax
  QAngle result; // [esp+14h] [ebp-Ch] BYREF
  QAngle *pOuta; // [esp+28h] [ebp+8h]
  float flExtrapolationAmount; // [esp+34h] [ebp+14h]

  v6 = pNew;
  flChangeTime = pOld->flChangeTime;
  v8 = pNew->flChangeTime;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(pOld->flChangeTime - pNew->flChangeTime) & _mask__AbsFloat_) < 0.001
    || v8 >= flDestinationTime )
  {
    v15 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      p_z = &pOut->z;
      do
      {
        v17 = (float *)((char *)&pNew->value->x + (unsigned int)p_z - 8 - (_DWORD)pOut);
        ++v15;
        p_z += 3;
        *(p_z - 5) = *v17;
        *(p_z - 4) = v17[1];
        *(p_z - 3) = v17[2];
      }
      while ( v15 < this->m_nMaxCount );
    }
  }
  else
  {
    if ( flMaxExtrapolationAmount <= (float)(flDestinationTime - v8) )
      flExtrapolationAmount = flMaxExtrapolationAmount;
    else
      flExtrapolationAmount = flDestinationTime - v8;
    v10 = 0;
    v11 = 1.0 / (float)(v8 - flChangeTime);
    if ( this->m_nMaxCount != 0 )
    {
      v12 = -8 - (_DWORD)pOut;
      v13 = &pOut->z;
      for ( pOuta = (QAngle *)(-8 - (_DWORD)pOut); ; v12 = (int)pOuta )
      {
        v14 = ExtrapolateInterpolatedVarType(
                &result,
                oldVal: (const QAngle *)((char *)pOld->value + (unsigned int)v13 + v12),
                newVal: (const QAngle *)((char *)v13 + v12 + (unsigned int)v6->value),
                divisor: v11,
                flExtrapolationAmount);
        *(v13 - 2) = v14->x;
        ++v10;
        *(v13 - 1) = v14->y;
        v13 += 3;
        *(v13 - 3) = v14->z;
        if ( v10 >= this->m_nMaxCount )
          break;
        v11 = 1.0 / (float)(v8 - flChangeTime);
        v6 = pNew;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C890
// Name: protected: void CInterpolatedVarArrayBase<class QAngle,1>::_Interpolate(class QAngle __near *,float,struct CInterpolatedVarEntryBase<class QAngle,1> __near *,struct CInterpolatedVarEntryBase<class QAngle,1> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,1>::_Interpolate(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        QAngle *out,
        float frac,
        CInterpolatedVarEntryBase<QAngle,1> *start,
        CInterpolatedVarEntryBase<QAngle,1> *end)
{
  CInterpolatedVarEntryBase<QAngle,1> *v5; // esi
  int v6; // edx
  QAngle *value; // eax
  float *p_z; // ecx
  CInterpolatedVarArrayBase<QAngle,1> *v9; // esi
  double y; // st7
  bool v11; // zf
  float v12; // xmm6_4
  float *v13; // edi
  char *v14; // eax
  QAngle *v15; // ecx
  __int64 v16; // xmm0_8
  QAngle *v17; // edx
  float v18; // ecx
  __int64 v19; // xmm0_8
  float v20; // edx
  float v21; // xmm1_4
  QAngle *v22; // esi
  float v23; // xmm0_4
  const QAngle *v24; // esi
  const QAngle *v25; // ecx
  __int64 v26; // xmm0_8
  int m_nMaxCount; // ecx
  Quaternion qt; // [esp+14h] [ebp-68h] BYREF
  Quaternion outQuat; // [esp+24h] [ebp-58h] BYREF
  Quaternion q; // [esp+34h] [ebp-48h] BYREF
  QAngle angles; // [esp+44h] [ebp-38h] BYREF
  __int64 v32; // [esp+50h] [ebp-2Ch]
  float v33; // [esp+58h] [ebp-24h]
  __int64 v34; // [esp+5Ch] [ebp-20h]
  float v35; // [esp+64h] [ebp-18h]
  __int64 v36; // [esp+68h] [ebp-14h]
  float z; // [esp+70h] [ebp-Ch]
  CInterpolatedVarArrayBase<QAngle,1> *v38; // [esp+74h] [ebp-8h]
  int i; // [esp+78h] [ebp-4h]

  v5 = end;
  v38 = this;
  if ( start == end )
  {
    v6 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      value = end->value;
      p_z = &out->z;
      do
      {
        v9 = v38;
        *(p_z - 2) = value->x;
        ++v6;
        y = value->y;
        ++value;
        *(p_z - 1) = y;
        p_z += 3;
        *(p_z - 3) = value[-1].z;
      }
      while ( v6 < v9->m_nMaxCount );
    }
  }
  else
  {
    v11 = this->m_nMaxCount == 0;
    i = 0;
    if ( !v11 )
    {
      v12 = frac;
      v13 = &out->z;
      while ( 1 )
      {
        v14 = (char *)v13 - 8 - (_DWORD)out;
        if ( this->m_bLooping[i] != 0 )
        {
          v15 = v5->value;
          v16 = *(_QWORD *)((char *)&v15->x + (_DWORD)v14);
          v17 = start->value;
          v18 = *(float *)((char *)&v15->z + (_DWORD)v14);
          v32 = v16;
          v19 = *(_QWORD *)((char *)&v17->x + (_DWORD)v14);
          v20 = *(float *)((char *)&v17->z + (_DWORD)v14);
          v34 = v19;
          v35 = v20;
          v33 = v18;
          v21 = (float)(*((float *)&v32 + 1) * v12) + (float)(*((float *)&v19 + 1) * (float)(1.0 - v12));
          *(v13 - 2) = (float)(*(float *)&v32 * v12) + (float)(*(float *)&v19 * (float)(1.0 - v12));
          *(v13 - 1) = v21;
          *v13 = (float)(v18 * v12) + (float)(v20 * (float)(1.0 - v12));
        }
        else
        {
          v22 = v5->value;
          v23 = *(float *)&v14[(_DWORD)v22];
          v24 = (QAngle *)((char *)v22 + (_DWORD)v14);
          v25 = (const QAngle *)&v14[(unsigned int)start->value];
          if ( v23 == v25->x && v24->y == v25->y && v24->z == v25->z )
          {
            v26 = *(_QWORD *)&v25->x;
            z = v25->z;
          }
          else
          {
            AngleQuaternion(angles: v25, &outQuat);
            AngleQuaternion(angles: v24, outQuat: &q);
            QuaternionSlerp(p: &outQuat, &q, t: frac, &qt);
            QuaternionAngles(q: &qt, &angles);
            v26 = *(_QWORD *)&angles.x;
            v12 = frac;
            z = angles.z;
          }
          v5 = end;
          v36 = v26;
          *((_DWORD *)v13 - 2) = v26;
          *(v13 - 1) = *((float *)&v36 + 1);
          *v13 = z;
        }
        m_nMaxCount = v38->m_nMaxCount;
        v13 += 3;
        if ( ++i >= m_nMaxCount )
          break;
        this = v38;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CA90
// Name: protected: void CInterpolatedVarArrayBase<class QAngle,1>::TimeFixup2_Hermite(struct CInterpolatedVarEntryBase<class QAngle,1> __near &,struct CInterpolatedVarEntryBase<class QAngle,1> __near * __near &,struct CInterpolatedVarEntryBase<class QAngle,1> __near * __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,1>::TimeFixup2_Hermite(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        CInterpolatedVarEntryBase<QAngle,1> *fixup,
        CInterpolatedVarEntryBase<QAngle,1> **prev,
        CInterpolatedVarEntryBase<QAngle,1> **start,
        float dt1,
        bool bAllowHermiteFix)
{
  CInterpolatedVarEntryBase<QAngle,1> **v6; // edx
  float flChangeTime; // xmm1_4
  float v9; // xmm0_4
  CInterpolatedVarEntryBase<QAngle,1> *v10; // edi
  int v11; // esi
  float v12; // xmm7_4
  QAngle *v13; // eax
  QAngle *value; // eax
  __int64 v15; // xmm0_8
  QAngle *v16; // ecx
  float z; // eax
  __int64 v18; // xmm0_8
  float v19; // ecx
  float v20; // xmm1_4
  QAngle *v21; // edi
  float x; // xmm0_4
  const QAngle *v23; // edi
  QAngle *v24; // ecx
  __int64 v25; // xmm0_8
  QAngle *v26; // ecx
  Quaternion qt; // [esp+14h] [ebp-70h] BYREF
  Quaternion outQuat; // [esp+24h] [ebp-60h] BYREF
  Quaternion q; // [esp+34h] [ebp-50h] BYREF
  QAngle angles; // [esp+44h] [ebp-40h] BYREF
  float v31[3]; // [esp+50h] [ebp-34h] BYREF
  __int64 v32; // [esp+5Ch] [ebp-28h]
  float v33; // [esp+64h] [ebp-20h]
  __int64 v34; // [esp+68h] [ebp-1Ch]
  float v35; // [esp+70h] [ebp-14h]
  __int64 v36; // [esp+74h] [ebp-10h] BYREF
  float v37; // [esp+7Ch] [ebp-8h]
  CInterpolatedVarArrayBase<QAngle,1> *v38; // [esp+80h] [ebp-4h]
  int i; // [esp+90h] [ebp+Ch]
  float frac; // [esp+98h] [ebp+14h]

  v6 = start;
  flChangeTime = (*start)->flChangeTime;
  v9 = flChangeTime - (*prev)->flChangeTime;
  v38 = this;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(dt1 - v9) & _mask__AbsFloat_) > 0.000099999997 && v9 > 0.000099999997 )
  {
    v10 = fixup;
    v11 = 0;
    fixup->flChangeTime = flChangeTime - dt1;
    v12 = dt1 / v9;
    frac = dt1 / v9;
    i = 0;
    if ( this->m_nMaxCount != 0 )
    {
      do
      {
        if ( this->m_bLooping[i] != 0 )
        {
          if ( g_bHermiteFix && bAllowHermiteFix )
          {
            v13 = &(*prev)->value[v11];
          }
          else
          {
            value = (*v6)->value;
            v15 = *(_QWORD *)&value[v11].x;
            v16 = (*prev)->value;
            z = value[v11].z;
            v32 = v15;
            v18 = *(_QWORD *)&v16[v11].x;
            v19 = v16[v11].z;
            v34 = v18;
            v35 = v19;
            v20 = 1.0 - (float)(1.0 - v12);
            v33 = z;
            v31[0] = (float)((float)(1.0 - v12) * *(float *)&v32) + (float)(*(float *)&v18 * v20);
            v31[1] = (float)((float)(1.0 - v12) * *((float *)&v32 + 1)) + (float)(*((float *)&v18 + 1) * v20);
            v31[2] = (float)((float)(1.0 - v12) * z) + (float)(v19 * v20);
            v13 = (QAngle *)v31;
          }
        }
        else if ( g_bHermiteFix && bAllowHermiteFix )
        {
          v13 = &(*prev)->value[v11];
        }
        else
        {
          v21 = (*v6)->value;
          x = v21[v11].x;
          v23 = &v21[v11];
          v24 = &(*prev)->value[v11];
          if ( x == v24->x && v23->y == v24->y && v23->z == v24->z )
          {
            v25 = *(_QWORD *)&v24->x;
            v37 = v24->z;
          }
          else
          {
            AngleQuaternion(angles: v24, &outQuat);
            AngleQuaternion(angles: v23, outQuat: &q);
            QuaternionSlerp(p: &outQuat, &q, t: 1.0 - frac, &qt);
            QuaternionAngles(q: &qt, &angles);
            v25 = *(_QWORD *)&angles.x;
            v12 = frac;
            v6 = start;
            v37 = angles.z;
          }
          v10 = fixup;
          v13 = (QAngle *)&v36;
          v36 = v25;
        }
        v26 = v10->value;
        ++i;
        v26[v11++].x = v13->x;
        v26[v11 - 1].y = v13->y;
        v26[v11 - 1].z = v13->z;
        this = v38;
      }
      while ( i < v38->m_nMaxCount );
    }
    *prev = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CCE0
// Name: public: virtual void CInterpolatedVarArrayBase<class QAngle,1>::Reset(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,1>::Reset(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        float flCurrentTime)
{
  QAngle *m_pValue; // eax

  CInterpolatedVarArrayBase<float,1>::ClearHistory((CInterpolatedVarArrayBase<float,1> *)this);
  m_pValue = this->m_pValue;
  if ( m_pValue != nullptr )
  {
    CInterpolatedVarArrayBase<Vector,1>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: m_pValue,
      bFlushNewer: false);
    CInterpolatedVarArrayBase<Vector,1>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: this->m_pValue,
      bFlushNewer: false);
    CInterpolatedVarArrayBase<Vector,1>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: this->m_pValue,
      bFlushNewer: false);
    memcpy(
      dst: (unsigned __int8 *)this->m_LastNetworkedValue,
      src: (unsigned __int8 *)this->m_pValue,
      count: 12 * this->m_nMaxCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CD60
// Name: public: virtual void CInterpolatedVarArrayBase<class QAngle,1>::Copy(class IInterpolatedVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,1>::Copy(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        IInterpolatedVar *pInSrc)
{
  unsigned __int16 *v3; // ebx
  unsigned __int8 m_nMaxCount; // al
  int v5; // edx
  int v6; // esi
  int v7; // eax
  QAngle *m_LastNetworkedValue; // ecx
  double v9; // st7
  int m_maxElement; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  CInterpolatedVarEntryBase<QAngle,1> *v16; // esi
  int v17; // ecx
  int v18; // ecx
  int v19; // eax
  unsigned __int8 *v20; // edx
  double v21; // st7
  IInterpolatedVar *v22; // eax
  QAngle *v23; // eax
  unsigned __int8 *value; // esi
  unsigned __int8 *src; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]
  IInterpolatedVar *pInSrca; // [esp+1Ch] [ebp+8h]

  v3 = (unsigned __int16 *)__RTDynamicCast(
                             inptr: pInSrc,
                             VfDelta: 0,
                             SrcType: &IInterpolatedVar `RTTI Type Descriptor',
                             TargetType: &CInterpolatedVarArrayBase<QAngle,1> `RTTI Type Descriptor',
                             isReference: 0);
  if ( v3 != nullptr )
  {
    m_nMaxCount = this->m_nMaxCount;
    if ( *((_BYTE *)v3 + 29) == m_nMaxCount )
    {
      v5 = 0;
      if ( m_nMaxCount != 0 )
      {
        v6 = 0;
        do
        {
          v7 = *((_DWORD *)v3 + 5);
          m_LastNetworkedValue = this->m_LastNetworkedValue;
          m_LastNetworkedValue[v6].x = *(float *)(v7 + v6 * 12);
          ++v5;
          v9 = *(float *)(v7 + v6 * 12 + 4);
          m_LastNetworkedValue[v6++].y = v9;
          m_LastNetworkedValue[v6 - 1].z = *(float *)(v7 + v6 * 12 - 4);
          this->m_bLooping[v5 - 1] = *(_BYTE *)(v5 + *((_DWORD *)v3 + 8) - 1);
        }
        while ( v5 < this->m_nMaxCount );
      }
      this->m_LastNetworkedTime = *((float *)v3 + 6);
      *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
      i = 0;
      if ( v3[8] != 0 )
      {
        do
        {
          CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
            this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_VarHistory,
            capSize: this->m_VarHistory.m_count + 1);
          ++this->m_VarHistory.m_count;
          m_maxElement = this->m_VarHistory.m_maxElement;
          v11 = this->m_VarHistory.m_count + this->m_VarHistory.m_firstElement - 1;
          if ( v11 >= m_maxElement )
            v11 -= m_maxElement;
          v12 = v11 + this->m_VarHistory.m_firstElement;
          v13 = this->m_VarHistory.m_maxElement;
          if ( v12 >= v13 )
            v12 -= v13;
          v14 = v12;
          v15 = i + v3[7];
          v16 = &this->m_VarHistory.m_pElements[v14];
          v17 = v3[6];
          if ( v15 >= v17 )
            v15 -= v17;
          v18 = *((_DWORD *)v3 + 2);
          v19 = 3 * v15;
          v20 = *(unsigned __int8 **)(v18 + 4 * v19 + 8);
          v21 = *(float *)(v18 + 4 * v19);
          v22 = (IInterpolatedVar *)this->m_nMaxCount;
          v16->flChangeTime = v21;
          src = v20;
          pInSrca = v22;
          if ( v22 != nullptr )
          {
            if ( v22 != (IInterpolatedVar *)v16->count )
            {
              C_BaseEntity::operator delete(pMem: (void *)v16->value);
              v16->value = nullptr;
              v16->count = 0;
              v22 = pInSrca;
            }
            if ( v16->value != nullptr )
              goto LABEL_20;
            v16->count = (int)v22;
            v23 = (QAngle *)MemAlloc_Alloc(nSize: (12 * (unsigned __int64)(unsigned int)v22) >> 32 != 0 ? -1 : 12 * (_DWORD)v22);
          }
          else
          {
            C_BaseEntity::operator delete(pMem: (void *)v16->value);
            v23 = nullptr;
            v16->count = 0;
          }
          v16->value = v23;
          v22 = pInSrca;
LABEL_20:
          value = (unsigned __int8 *)v16->value;
          if ( value != nullptr && v22 != nullptr )
            memcpy(dst: value, src, count: 12 * (_DWORD)v22);
          ++i;
        }
        while ( i < v3[8] );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CF50
// Name: public: bool CInterpolatedVarArrayBase<class Vector,1>::NoteChanged(float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInterpolatedVarArrayBase<Vector,1>::NoteChanged(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        float flCurrentTime,
        float flChangeTime,
        float interpolation_amount,
        bool bUpdateLastNetworkedValue)
{
  char v6; // bl
  unsigned int m_firstElement; // ecx
  unsigned int m_maxElement; // edx
  unsigned int v9; // eax
  QAngle *m_pValue; // edi
  QAngle *value; // ecx
  int v12; // ecx
  int v13; // edi
  int i; // edx
  int v15; // eax
  bool bRet; // [esp+1Bh] [ebp-1h]

  v6 = 1;
  bRet = true;
  if ( this->m_VarHistory.m_count != 0 )
  {
    m_firstElement = this->m_VarHistory.m_firstElement;
    m_maxElement = this->m_VarHistory.m_maxElement;
    v9 = 12 * this->m_nMaxCount;
    if ( m_firstElement >= m_maxElement )
      m_firstElement -= m_maxElement;
    m_pValue = this->m_pValue;
    value = this->m_VarHistory.m_pElements[m_firstElement].value;
    if ( v9 < 4 )
    {
LABEL_7:
      if ( v9 == 0
        || LOBYTE(value->x) == LOBYTE(m_pValue->x)
        && (v9 <= 1 || BYTE1(value->x) == BYTE1(m_pValue->x) && (v9 <= 2 || BYTE2(value->x) == BYTE2(m_pValue->x))) )
      {
        v6 = 0;
        bRet = false;
      }
    }
    else
    {
      while ( LODWORD(m_pValue->x) == LODWORD(value->x) )
      {
        v9 -= 4;
        value = (QAngle *)((char *)value + 4);
        m_pValue = (QAngle *)((char *)m_pValue + 4);
        if ( v9 < 4 )
          goto LABEL_7;
      }
    }
  }
  CInterpolatedVarArrayBase<Vector,1>::AddToHead(
    this,
    changeTime: flChangeTime,
    values: this->m_pValue,
    bFlushNewer: true);
  if ( bUpdateLastNetworkedValue )
    this->NoteLastNetworkedValue(this);
  v12 = 0;
  if ( this->m_VarHistory.m_count == 0 )
    return v6;
  v13 = this->m_VarHistory.m_maxElement;
  for ( i = this->m_VarHistory.m_firstElement - v13; ; ++i )
  {
    v15 = v12 + this->m_VarHistory.m_firstElement;
    if ( v15 >= v13 )
      v15 = i;
    if ( (float)((float)(flCurrentTime - interpolation_amount) - 0.050000001) > this->m_VarHistory.m_pElements[v15].flChangeTime )
      break;
    if ( ++v12 >= this->m_VarHistory.m_count )
      return bRet;
  }
  if ( v12 + 3 >= this->m_VarHistory.m_count )
    return bRet;
  this->m_VarHistory.m_count = v12 + 3;
  return bRet;
}

//------------------------------------------------------------------------------
// Address: 0x1015D070
// Name: protected: void CInterpolatedVarArrayBase<class Vector,1>::_Interpolate_Hermite(class Vector __near *,float,struct CInterpolatedVarEntryBase<class Vector,1> __near *,struct CInterpolatedVarEntryBase<class Vector,1> __near *,struct CInterpolatedVarEntryBase<class Vector,1> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<Vector,1>::_Interpolate_Hermite(
        CInterpolatedVarArrayBase<Vector,1> *this,
        Vector *out,
        float frac,
        CInterpolatedVarEntryBase<Vector,1> *prev,
        float start,
        CInterpolatedVarEntryBase<Vector,1> *end,
        bool looping)
{
  CInterpolatedVarEntryBase<Vector,1> *v8; // esi
  Vector *value; // ebx
  Vector *v10; // esi
  Vector *v11; // edx
  float v12; // xmm1_4
  float v13; // xmm7_4
  float *p_z; // eax
  Vector *v15; // edi
  __int64 v16; // xmm0_8
  float v17; // edi
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // ecx
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  float v26; // xmm6_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float *v29; // ecx
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm5_4
  float v34; // xmm7_4
  float v35; // xmm6_4
  float v36; // xmm4_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  float v40; // xmm0_4
  float v41; // xmm6_4
  float v42; // xmm3_4
  float v43; // xmm0_4
  CInterpolatedVarArrayBase<Vector,1> *v44; // edi
  int v45; // ecx
  int v46; // edi
  unsigned int m_nMaxCount; // [esp+4h] [ebp-D4h]
  float v48; // [esp+18h] [ebp-C0h]
  float v49; // [esp+38h] [ebp-A0h]
  __int64 v50; // [esp+5Ch] [ebp-7Ch]
  float v51; // [esp+68h] [ebp-70h]
  char *v52; // [esp+6Ch] [ebp-6Ch]
  int v53; // [esp+78h] [ebp-60h]
  float v54; // [esp+7Ch] [ebp-5Ch]
  float v55; // [esp+80h] [ebp-58h]
  float v56; // [esp+88h] [ebp-50h]
  float v57; // [esp+90h] [ebp-48h]
  float v58; // [esp+94h] [ebp-44h]
  float v59; // [esp+98h] [ebp-40h]
  CInterpolatedVarEntryBase<Vector,1> fixup; // [esp+A8h] [ebp-30h] BYREF
  __int64 v61; // [esp+B4h] [ebp-24h]
  float v62; // [esp+BCh] [ebp-1Ch]
  __int64 v63; // [esp+C0h] [ebp-18h]
  float v64; // [esp+C8h] [ebp-10h]
  CInterpolatedVarArrayBase<Vector,1> *v65; // [esp+CCh] [ebp-Ch]
  int i; // [esp+D0h] [ebp-8h]
  CDisableRangeChecks disableRangeChecks; // [esp+D7h] [ebp-1h] BYREF
  Vector *outa; // [esp+E0h] [ebp+8h]

  v65 = this;
  CDisableRangeChecks::CDisableRangeChecks(this: &disableRangeChecks);
  m_nMaxCount = this->m_nMaxCount;
  memset(&fixup, 0, sizeof(fixup));
  CInterpolatedVarEntryBase<Vector,1>::Init(this: (CInterpolatedVarEntryBase<QAngle,1> *)&fixup, maxCount: m_nMaxCount);
  v8 = (CInterpolatedVarEntryBase<Vector,1> *)LODWORD(start);
  CInterpolatedVarArrayBase<Vector,1>::TimeFixup2_Hermite(
    this,
    &fixup,
    &prev,
    (CInterpolatedVarEntryBase<Vector,1> **)&start,
    dt1: end->flChangeTime - *(float *)LODWORD(start),
    bAllowHermiteFix: true);
  i = 0;
  if ( this->m_nMaxCount != 0 )
  {
    value = prev->value;
    v10 = v8->value;
    v11 = out;
    v12 = frac;
    v52 = (char *)((char *)value - (char *)v10);
    outa = (Vector *)((char *)out - (char *)v10);
    prev = (CInterpolatedVarEntryBase<Vector,1> *)(-8 - (_DWORD)v10);
    v13 = v12 * v12;
    start = v12 * v12;
    p_z = &v10->z;
    v53 = (char *)value - (char *)v11;
    while ( 1 )
    {
      if ( v65->m_bLooping[i] != 0 )
      {
        v15 = end->value;
        v16 = *(_QWORD *)((char *)&prev->flChangeTime + (_DWORD)p_z + (unsigned int)v15);
        v17 = *(float *)((char *)&prev->value + (_DWORD)p_z + (unsigned int)v15);
        v63 = v16;
        v61 = *(_QWORD *)((char *)&prev->flChangeTime + (_DWORD)p_z + (unsigned int)v10);
        v50 = *(_QWORD *)((char *)&prev->flChangeTime + (_DWORD)p_z + (unsigned int)value);
        v49 = *(float *)&v16 - *(float *)&v61;
        *(float *)&v16 = v13 * frac;
        v18 = (float)((float)((float)(v13 * frac) * 2.0) - (float)(v13 * 3.0)) + 1.0;
        v19 = (float)(v13 * 3.0) - (float)((float)(v13 * frac) * 2.0);
        v64 = v17;
        v20 = *(float *)((char *)&prev->value + (_DWORD)p_z + (unsigned int)value);
        v62 = *(float *)((char *)&prev->value + (_DWORD)p_z + (unsigned int)v10);
        v57 = (float)(*(float *)&v63 * v19) + (float)(*(float *)&v61 * v18);
        v59 = (float)(v19 * v17) + (float)(v62 * v18);
        v58 = (float)(*((float *)&v63 + 1) * v19) + (float)(*((float *)&v61 + 1) * v18);
        v21 = (float)((float)(v13 * frac) - (float)(start * 2.0)) + frac;
        v13 = start;
        v22 = (float)(v21 * (float)(*(float *)&v61 - *(float *)&v50)) + v57;
        v23 = (float)((float)(*((float *)&v61 + 1) - *((float *)&v50 + 1)) * v21) + v58;
        v24 = (float)((float)(v62 - v20) * v21) + v59;
        *(float *)&v16 = *(float *)&v16 - start;
        v25 = *(float *)&v16 * v49;
        v26 = (float)((float)(v17 - v62) * *(float *)&v16) + v24;
        v11->y = (float)((float)(*((float *)&v63 + 1) - *((float *)&v61 + 1)) * *(float *)&v16) + v23;
        *(float *)((char *)p_z + (_DWORD)outa) = v26;
      }
      else
      {
        v27 = *(p_z - 2);
        v28 = *(p_z - 1);
        v29 = (float *)((char *)&end->value->x + (unsigned int)prev + (_DWORD)p_z);
        v55 = v29[1];
        v56 = v55 - v28;
        v51 = v29[2];
        v30 = v13 * v12;
        v54 = (float)(v13 * v12) * 2.0;
        v31 = (float)(v54 - (float)(v13 * 3.0)) + 1.0;
        v32 = (float)(v13 * 3.0) - v54;
        v33 = v28 - *(float *)((char *)p_z + (_DWORD)v52 - 4);
        v34 = (float)(v55 * v32) + (float)(v28 * v31);
        v35 = (float)(*p_z * v31) + (float)(v32 * v51);
        v36 = (float)(*v29 * v32) + (float)(v27 * v31);
        v48 = v34;
        v13 = start;
        v37 = (float)(v30 - (float)(start * 2.0)) + frac;
        v38 = v37 * (float)(v27 - *(float *)((char *)&v11->x + v53));
        v39 = (float)(v33 * v37) + v48;
        v40 = v30 - start;
        v41 = v35 + (float)(v37 * (float)(*p_z - *(float *)((char *)p_z + (_DWORD)v52)));
        v25 = v40 * (float)(*v29 - v27);
        v42 = (float)(v56 * v40) + v39;
        v43 = (float)(v40 * (float)(v51 - *p_z)) + v41;
        v22 = v38 + v36;
        v11->y = v42;
        *(float *)((char *)p_z + (_DWORD)outa) = v43;
      }
      v44 = v65;
      v45 = i;
      v11->x = v25 + v22;
      v46 = v44->m_nMaxCount;
      p_z += 3;
      ++v11;
      i = v45 + 1;
      if ( v45 + 1 >= v46 )
        break;
      v12 = frac;
    }
  }
  C_BaseEntity::operator delete(pMem: (void *)fixup.value);
  fixup.value = nullptr;
  CDisableRangeChecks::~CDisableRangeChecks(this: &disableRangeChecks);
}

//------------------------------------------------------------------------------
// Address: 0x1015D480
// Name: protected: void CInterpolatedVarArrayBase<class QAngle,1>::_Interpolate_Hermite(class QAngle __near *,float,struct CInterpolatedVarEntryBase<class QAngle,1> __near *,struct CInterpolatedVarEntryBase<class QAngle,1> __near *,struct CInterpolatedVarEntryBase<class QAngle,1> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<QAngle,1>::_Interpolate_Hermite(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        QAngle *out,
        float frac,
        CInterpolatedVarEntryBase<QAngle,1> *prev,
        CInterpolatedVarEntryBase<QAngle,1> *start,
        CInterpolatedVarEntryBase<QAngle,1> *end,
        bool looping)
{
  CInterpolatedVarEntryBase<QAngle,1> *v8; // ebx
  bool v9; // zf
  int v10; // edi
  float *p_z; // esi
  QAngle *value; // eax
  QAngle *v13; // edx
  char *v14; // ecx
  __int64 v15; // xmm0_8
  float v16; // eax
  __int64 v17; // xmm0_8
  float v18; // eax
  __int64 v19; // xmm0_8
  QAngle *v20; // eax
  int v21; // edx
  unsigned int m_nMaxCount; // [esp+Ch] [ebp-94h]
  QAngle result; // [esp+1Ch] [ebp-84h] BYREF
  Quaternion outQuat; // [esp+28h] [ebp-78h] BYREF
  Quaternion q; // [esp+38h] [ebp-68h] BYREF
  Quaternion qt; // [esp+48h] [ebp-58h] BYREF
  QAngle v27; // [esp+58h] [ebp-48h] BYREF
  QAngle v28; // [esp+64h] [ebp-3Ch] BYREF
  QAngle angles; // [esp+70h] [ebp-30h] BYREF
  CInterpolatedVarEntryBase<QAngle,1> fixup; // [esp+7Ch] [ebp-24h] BYREF
  __int64 v31; // [esp+88h] [ebp-18h]
  float z; // [esp+90h] [ebp-10h]
  CInterpolatedVarArrayBase<QAngle,1> *v33; // [esp+94h] [ebp-Ch]
  int i; // [esp+98h] [ebp-8h]
  CDisableRangeChecks disableRangeChecks; // [esp+9Fh] [ebp-1h] BYREF
  QAngle *outa; // [esp+A8h] [ebp+8h]

  v33 = this;
  CDisableRangeChecks::CDisableRangeChecks(this: &disableRangeChecks);
  m_nMaxCount = this->m_nMaxCount;
  memset(&fixup, 0, sizeof(fixup));
  CInterpolatedVarEntryBase<Vector,1>::Init(this: &fixup, maxCount: m_nMaxCount);
  v8 = end;
  CInterpolatedVarArrayBase<QAngle,1>::TimeFixup2_Hermite(
    this,
    &fixup,
    &prev,
    &start,
    dt1: end->flChangeTime - start->flChangeTime,
    bAllowHermiteFix: true);
  v9 = this->m_nMaxCount == 0;
  i = 0;
  if ( !v9 )
  {
    v10 = -8 - (_DWORD)out;
    p_z = &out->z;
    outa = (QAngle *)(-8 - (_DWORD)out);
    do
    {
      if ( v33->m_bLooping[i] != 0 )
      {
        value = v8->value;
        v13 = start->value;
        v14 = (char *)p_z + v10;
        v15 = *(_QWORD *)((char *)&value->x + (_DWORD)p_z + v10);
        v16 = *(float *)((char *)&value->z + (_DWORD)p_z + v10);
        *(_QWORD *)&v28.x = v15;
        v17 = *(_QWORD *)((char *)&v13->x + (_DWORD)p_z + v10);
        v28.z = v16;
        v18 = *(float *)((char *)&v13->z + (_DWORD)p_z + v10);
        *(_QWORD *)&angles.x = v17;
        angles.z = v18;
        if ( v28.x == *(float *)&v17 && v28.y == angles.y && v28.z == angles.z )
        {
          v19 = *(_QWORD *)((char *)&v13->x + (_DWORD)v14);
          z = *(float *)((char *)&v13->z + (_DWORD)v14);
        }
        else
        {
          AngleQuaternion(&angles, &outQuat);
          AngleQuaternion(angles: &v28, outQuat: &q);
          QuaternionSlerp(p: &outQuat, &q, t: frac, &qt);
          QuaternionAngles(q: &qt, angles: &v27);
          v19 = *(_QWORD *)&v27.x;
          z = v27.z;
        }
        v31 = v19;
        *((_DWORD *)p_z - 2) = v19;
        *(p_z - 1) = *((float *)&v31 + 1);
        *p_z = z;
      }
      else
      {
        v20 = Lerp_Hermite<QAngle>(
                &result,
                __formal: (const QAngle *)(p_z - 2),
                t: frac,
                p0: (const QAngle *)((char *)prev->value + (unsigned int)p_z + v10),
                p1: (const QAngle *)((char *)p_z + v10 + (unsigned int)start->value),
                p2: (const QAngle *)((char *)p_z + v10 + (unsigned int)v8->value));
        v8 = end;
        *(QAngle *)(p_z - 2) = *v20;
        v10 = (int)outa;
      }
      v21 = v33->m_nMaxCount;
      p_z += 3;
      ++i;
    }
    while ( i < v21 );
  }
  C_BaseEntity::operator delete(pMem: (void *)fixup.value);
  fixup.value = nullptr;
  CDisableRangeChecks::~CDisableRangeChecks(this: &disableRangeChecks);
}

//------------------------------------------------------------------------------
// Address: 0x1015D680
// Name: public: virtual C_ServerRagdoll::~C_ServerRagdoll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ServerRagdoll::~C_ServerRagdoll(C_ServerRagdoll *this)
{
  CInterpolatedVarArrayBase<float,1> *p_m_iv_ragAngles; // ecx

  p_m_iv_ragAngles = (CInterpolatedVarArrayBase<float,1> *)&this->m_iv_ragAngles;
  p_m_iv_ragAngles->__vftable = (CInterpolatedVarArrayBase<float,1>_vtbl *)&CInterpolatedVarArrayBase<QAngle,1>::`vftable';
  CInterpolatedVarArrayBase<float,1>::ClearHistory(this: p_m_iv_ragAngles);
  C_BaseEntity::operator delete(pMem: this->m_iv_ragAngles.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_iv_ragAngles.m_LastNetworkedValue);
  CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>::~CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>(this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_iv_ragAngles.m_VarHistory);
  this->m_iv_ragAngles.__vftable = (CInterpolatedVarArray<QAngle,32>_vtbl *)&IInterpolatedVar::`vftable';
  this->m_iv_ragPos.__vftable = (CInterpolatedVarArray<Vector,32>_vtbl *)&CInterpolatedVarArrayBase<Vector,1>::`vftable';
  CInterpolatedVarArrayBase<float,1>::ClearHistory(this: (CInterpolatedVarArrayBase<float,1> *)&this->m_iv_ragPos);
  C_BaseEntity::operator delete(pMem: this->m_iv_ragPos.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_iv_ragPos.m_LastNetworkedValue);
  CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>::~CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>(this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_iv_ragPos.m_VarHistory);
  this->m_iv_ragPos.__vftable = (CInterpolatedVarArray<Vector,32>_vtbl *)&IInterpolatedVar::`vftable';
  C_BaseAnimating::~C_BaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x1015D770
// Name: public: virtual bool CInterpolatedVarArrayBase<class Vector,1>::NoteChanged(float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInterpolatedVarArrayBase<Vector,1>::NoteChanged(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        float flCurrentTime,
        float flChangeTime,
        bool bUpdateLastNetworkedValue)
{
  return CInterpolatedVarArrayBase<Vector,1>::NoteChanged(
           this,
           flCurrentTime,
           flChangeTime,
           interpolation_amount: this->m_InterpolationAmount,
           bUpdateLastNetworkedValue);
}

//------------------------------------------------------------------------------
// Address: 0x1015D7B0
// Name: public: int CInterpolatedVarArrayBase<class Vector,1>::Interpolate(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<Vector,1>::Interpolate(
        CInterpolatedVarArrayBase<Vector,1> *this,
        float currentTime,
        float interpolation_amount)
{
  int m_firstElement; // eax
  int m_maxElement; // ecx
  int v6; // edx
  int v7; // eax
  int newer; // ebx
  int v9; // eax
  CInterpolatedVarEntryBase<Vector,1> *v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  CInterpolatedVarEntryBase<Vector,1> *v16; // [esp+8h] [ebp-34h]
  float flMaxExtrapolationAmount; // [esp+10h] [ebp-2Ch]
  CInterpolatedVarArrayBase<Vector,1>::CInterpolationInfo info; // [esp+20h] [ebp-1Ch] BYREF
  int realOlder; // [esp+34h] [ebp-8h]
  int noMoreChanges; // [esp+38h] [ebp-4h] BYREF

  noMoreChanges = 0;
  if ( CInterpolatedVarArrayBase<Vector,1>::GetInterpolationInfo(
         (CInterpolatedVarArrayBase<QAngle,1> *)this,
         pInfo: (CInterpolatedVarArrayBase<QAngle,1>::CInterpolationInfo *)&info,
         currentTime,
         interpolation_amount,
         pNoMoreChanges: &noMoreChanges) )
  {
    if ( info.m_bHermite )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      realOlder = m_firstElement + info.newer;
      if ( m_firstElement + info.newer >= m_maxElement )
        realOlder = m_firstElement + info.newer - m_maxElement;
      v6 = m_firstElement + info.older;
      if ( m_firstElement + info.older >= m_maxElement )
        v6 -= m_maxElement;
      v7 = info.oldest + m_firstElement;
      if ( v7 >= m_maxElement )
        v7 -= m_maxElement;
      CInterpolatedVarArrayBase<Vector,1>::_Interpolate_Hermite(
        this,
        out: this->m_pValue,
        frac: info.frac,
        prev: &this->m_VarHistory.m_pElements[v7],
        start: COERCE_FLOAT((int)&this->m_VarHistory.m_pElements[v6]),
        end: &this->m_VarHistory.m_pElements[realOlder],
        looping: false);
    }
    else
    {
      newer = info.newer;
      if ( info.newer == info.older
        && (v9 = info.newer + 1, realOlder = info.newer + 1, CInterpolationContext::s_bAllowExtrapolation)
        && v9 >= 0
        && v9 < this->m_VarHistory.m_count
        && CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1>>::operator[](
             this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_VarHistory,
             i: info.newer + 1)->flChangeTime != 0.0
        && interpolation_amount > 0.000001
        && this->m_LastNetworkedTime >= CInterpolationContext::s_flLastTimeStamp )
      {
        flMaxExtrapolationAmount = cl_extrapolate_amount.m_pParent->m_Value.m_fValue;
        v16 = (CInterpolatedVarEntryBase<Vector,1> *)CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1>>::operator[](
                                                       this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_VarHistory,
                                                       i: newer);
        v10 = (CInterpolatedVarEntryBase<Vector,1> *)CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1>>::operator[](
                                                       this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_VarHistory,
                                                       i: realOlder);
        CInterpolatedVarArrayBase<Vector,1>::_Extrapolate(
          this,
          pOut: this->m_pValue,
          pOld: v10,
          pNew: v16,
          flDestinationTime: currentTime - interpolation_amount,
          flMaxExtrapolationAmount);
      }
      else
      {
        v11 = this->m_VarHistory.m_firstElement;
        v12 = this->m_VarHistory.m_maxElement;
        v13 = v11 + newer;
        if ( v11 + newer >= v12 )
          v13 -= v12;
        v14 = info.older + v11;
        if ( v14 >= v12 )
          v14 -= v12;
        CInterpolatedVarArrayBase<Vector,1>::_Interpolate(
          this,
          out: this->m_pValue,
          frac: info.frac,
          start: &this->m_VarHistory.m_pElements[v14],
          end: &this->m_VarHistory.m_pElements[v13]);
      }
    }
    CInterpolatedVarArrayBase<QAngle,1>::RemoveEntriesPreviousTo(
      (CInterpolatedVarArrayBase<float,1> *)this,
      flTime: (float)(currentTime - interpolation_amount) - 0.050000001);
  }
  return noMoreChanges;
}

//------------------------------------------------------------------------------
// Address: 0x1015D980
// Name: public: int CInterpolatedVarArrayBase<class QAngle,1>::Interpolate(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<QAngle,1>::Interpolate(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        float currentTime,
        float interpolation_amount)
{
  int m_firstElement; // eax
  int m_maxElement; // ecx
  int v6; // edx
  int v7; // eax
  int newer; // ebx
  int v9; // eax
  CInterpolatedVarEntryBase<QAngle,1> *v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  CInterpolatedVarEntryBase<QAngle,1> *v16; // [esp+8h] [ebp-34h]
  float flMaxExtrapolationAmount; // [esp+10h] [ebp-2Ch]
  CInterpolatedVarArrayBase<QAngle,1>::CInterpolationInfo info; // [esp+20h] [ebp-1Ch] BYREF
  int realOlder; // [esp+34h] [ebp-8h]
  int noMoreChanges; // [esp+38h] [ebp-4h] BYREF

  noMoreChanges = 0;
  if ( CInterpolatedVarArrayBase<Vector,1>::GetInterpolationInfo(
         this,
         pInfo: &info,
         currentTime,
         interpolation_amount,
         pNoMoreChanges: &noMoreChanges) )
  {
    if ( info.m_bHermite )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      realOlder = m_firstElement + info.newer;
      if ( m_firstElement + info.newer >= m_maxElement )
        realOlder = m_firstElement + info.newer - m_maxElement;
      v6 = m_firstElement + info.older;
      if ( m_firstElement + info.older >= m_maxElement )
        v6 -= m_maxElement;
      v7 = info.oldest + m_firstElement;
      if ( v7 >= m_maxElement )
        v7 -= m_maxElement;
      CInterpolatedVarArrayBase<QAngle,1>::_Interpolate_Hermite(
        this,
        out: this->m_pValue,
        frac: info.frac,
        prev: &this->m_VarHistory.m_pElements[v7],
        start: &this->m_VarHistory.m_pElements[v6],
        end: &this->m_VarHistory.m_pElements[realOlder],
        looping: false);
    }
    else
    {
      newer = info.newer;
      if ( info.newer == info.older
        && (v9 = info.newer + 1, realOlder = info.newer + 1, CInterpolationContext::s_bAllowExtrapolation)
        && v9 >= 0
        && v9 < this->m_VarHistory.m_count
        && CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1>>::operator[](
             this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_VarHistory,
             i: info.newer + 1)->flChangeTime != 0.0
        && interpolation_amount > 0.000001
        && this->m_LastNetworkedTime >= CInterpolationContext::s_flLastTimeStamp )
      {
        flMaxExtrapolationAmount = cl_extrapolate_amount.m_pParent->m_Value.m_fValue;
        v16 = (CInterpolatedVarEntryBase<QAngle,1> *)CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1>>::operator[](
                                                       this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_VarHistory,
                                                       i: newer);
        v10 = (CInterpolatedVarEntryBase<QAngle,1> *)CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1>>::operator[](
                                                       this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_VarHistory,
                                                       i: realOlder);
        CInterpolatedVarArrayBase<QAngle,1>::_Extrapolate(
          this,
          pOut: this->m_pValue,
          pOld: v10,
          pNew: v16,
          flDestinationTime: currentTime - interpolation_amount,
          flMaxExtrapolationAmount);
      }
      else
      {
        v11 = this->m_VarHistory.m_firstElement;
        v12 = this->m_VarHistory.m_maxElement;
        v13 = v11 + newer;
        if ( v11 + newer >= v12 )
          v13 -= v12;
        v14 = info.older + v11;
        if ( v14 >= v12 )
          v14 -= v12;
        CInterpolatedVarArrayBase<QAngle,1>::_Interpolate(
          this,
          out: this->m_pValue,
          frac: info.frac,
          start: &this->m_VarHistory.m_pElements[v14],
          end: &this->m_VarHistory.m_pElements[v13]);
      }
    }
    CInterpolatedVarArrayBase<QAngle,1>::RemoveEntriesPreviousTo(
      (CInterpolatedVarArrayBase<float,1> *)this,
      flTime: (float)(currentTime - interpolation_amount) - 0.050000001);
  }
  return noMoreChanges;
}

//------------------------------------------------------------------------------
// Address: 0x1015DB50
// Name: public: C_ServerRagdoll::C_ServerRagdoll(void)
// Source: json
//------------------------------------------------------------------------------
C_ServerRagdoll *__thiscall C_ServerRagdoll::C_ServerRagdoll(C_ServerRagdoll *this)
{
  C_BaseAnimating::C_BaseAnimating(this);
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ServerRagdoll_vtbl *)&C_ServerRagdoll::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ServerRagdoll::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ServerRagdoll::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ServerRagdoll::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ServerRagdoll::`vftable';
  this->m_iv_ragPos.__vftable = (CInterpolatedVarArray<Vector,32>_vtbl *)&CInterpolatedVarArrayBase<Vector,1>::`vftable';
  this->m_iv_ragPos.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_iv_ragPos.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_iv_ragPos.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
    this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_iv_ragPos.m_VarHistory,
    capSize: (CInterpolatedVarEntryBase<float,1> *)4);
  this->m_iv_ragPos.m_pDebugName = "C_ServerRagdoll::m_iv_ragPos";
  this->m_iv_ragPos.m_pValue = nullptr;
  this->m_iv_ragPos.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_ragPos.m_fType = 1;
  this->m_iv_ragPos.m_LastNetworkedTime = 0.0;
  this->m_iv_ragPos.m_LastNetworkedValue = nullptr;
  this->m_iv_ragPos.m_bLooping = nullptr;
  this->m_iv_ragPos.__vftable = (CInterpolatedVarArray<Vector,32>_vtbl *)&CInterpolatedVarArray<Vector,32>::`vftable';
  CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(
    this: (CInterpolatedVarArrayBase<QAngle,0> *)&this->m_iv_ragPos,
    flCurrentTime: 0.0,
    newmax: 32);
  this->m_iv_ragAngles.__vftable = (CInterpolatedVarArray<QAngle,32>_vtbl *)&CInterpolatedVarArrayBase<QAngle,1>::`vftable';
  this->m_iv_ragAngles.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_iv_ragAngles.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_iv_ragAngles.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
    this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *)&this->m_iv_ragAngles.m_VarHistory,
    capSize: (CInterpolatedVarEntryBase<float,1> *)4);
  this->m_iv_ragAngles.m_pDebugName = "C_ServerRagdoll::m_iv_ragAngles";
  this->m_iv_ragAngles.m_pValue = nullptr;
  this->m_iv_ragAngles.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_ragAngles.m_fType = 1;
  this->m_iv_ragAngles.m_LastNetworkedTime = 0.0;
  this->m_iv_ragAngles.m_LastNetworkedValue = nullptr;
  this->m_iv_ragAngles.m_bLooping = nullptr;
  this->m_iv_ragAngles.__vftable = (CInterpolatedVarArray<QAngle,32>_vtbl *)&CInterpolatedVarArray<QAngle,32>::`vftable';
  CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(
    this: (CInterpolatedVarArrayBase<QAngle,0> *)&this->m_iv_ragAngles,
    flCurrentTime: 0.0,
    newmax: 32);
  this->m_hUnragdoll.m_Value.m_Index = -1;
  this->m_elementCount = 0;
  this->m_flLastBoneChangeTime = -3.4028235e38;
  C_BaseEntity::AddVar(this, data: (void *)this->m_ragPos, watcher: &this->m_iv_ragPos, type: 2, bSetup: false);
  C_BaseEntity::AddVar(this, data: (void *)this->m_ragAngles, watcher: &this->m_iv_ragAngles, type: 2, bSetup: false);
  if ( this->m_flBlendWeight.m_Value != 0.0 )
    this->m_flBlendWeight.m_Value = 0.0;
  this->m_flBlendWeightCurrent = 0.0;
  if ( this->m_nOverlaySequence.m_Value != -1 )
    this->m_nOverlaySequence.m_Value = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015DD00
// Name: public: virtual float C_ServerRagdollAttached::LastBoneChangedTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_ServerRagdollAttached::LastBoneChangedTime(C_BaseAnimating *this)
{
  return 3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x1015DD10
// Name: public: virtual bool C_ServerRagdollAttached::SetupBones(class matrix3x4a_t __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_ServerRagdollAttached::SetupBones(
        C_ServerRagdollAttached *this,
        matrix3x4a_t *pBoneToWorldOut,
        int nMaxBones,
        int boneMask,
        float currentTime)
{
  unsigned int m_nSplitUserPlayerPredictionSlot; // ecx
  int v7; // edi
  _DWORD *v8; // esi
  int v9; // eax
  C_BaseAnimating *v10; // edx
  int v11; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  m_nSplitUserPlayerPredictionSlot = this->m_nSplitUserPlayerPredictionSlot;
  if ( m_nSplitUserPlayerPredictionSlot != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nSplitUserPlayerPredictionSlot].m_SerialNumber == HIWORD(m_nSplitUserPlayerPredictionSlot)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nSplitUserPlayerPredictionSlot].m_pEntity != nullptr )
  {
    v7 = *(&this->m_elementCount + LODWORD(this->m_attachmentPointRagdollSpace.z));
    if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: (C_ServerRagdollAttached *)((char *)this - 4));
    v8 = *(_DWORD **)&this->m_nOldMuzzleFlashParity;
    if ( v8 == nullptr || *v8 == 0 )
      v8 = nullptr;
    v9 = *(_DWORD *)(v8[11] + 4 * v7);
    v10 = (C_BaseAnimating *)boneMask;
    if ( (v9 & boneMask) == 0 )
    {
      v11 = 31;
      while ( ((1 << v11) & v9) == 0 )
      {
        if ( --v11 < 0 )
          return C_BaseAnimating::SetupBones(
                   this,
                   a2: (int)&savedregs,
                   pBoneToWorldOut,
                   nMaxBones,
                   boneMask: v10,
                   currentTime);
      }
      v10 = (C_BaseAnimating *)((1 << v11) | boneMask);
    }
  }
  else
  {
    v10 = (C_BaseAnimating *)boneMask;
  }
  return C_BaseAnimating::SetupBones(this, a2: (int)&savedregs, pBoneToWorldOut, nMaxBones, boneMask: v10, currentTime);
}

//------------------------------------------------------------------------------
// Address: 0x1015DDE0
// Name: public: virtual void C_ServerRagdollAttached::BuildTransformations(class CStudioHdr __near *,class Vector __near *,class Quaternion __near * const,struct matrix3x4_t const __near &,int,class CBoneBitList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ServerRagdollAttached::BuildTransformations(
        C_ServerRagdollAttached *this,
        CStudioHdr *hdr,
        Vector *pos,
        Quaternion *q,
        const matrix3x4_t *cameraTransform,
        int boneMask,
        CBoneBitList *boneComputed)
{
  float m_parentTime; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  unsigned int m_Index; // ecx
  float v13; // xmm0_4
  C_BaseAnimating *m_pEntity; // esi
  CStudioHdr *v15; // eax
  int v16; // ebx
  matrix3x4a_t *v17; // esi
  matrix3x4_t boneToWorld; // [esp+24h] [ebp-60h] BYREF
  Vector ragOrigin; // [esp+54h] [ebp-30h] BYREF
  Vector out; // [esp+60h] [ebp-24h] BYREF
  Vector worldOrigin; // [esp+6Ch] [ebp-18h] BYREF
  Vector offset; // [esp+78h] [ebp-Ch]
  int savedregs; // [esp+84h] [ebp+0h] BYREF
  CBoneBitList *boneComputeda; // [esp+A0h] [ebp+1Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_ServerRagdollAttached::SetupBones",
    a3: 0,
    a4: "Client_Animation",
    a5: false,
    a6: 4);
  if ( hdr == nullptr )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  m_parentTime = this->m_parentTime;
  v9 = *(float *)(gpGlobals.m_Index + 12);
  v10 = m_parentTime + 0.2;
  if ( m_parentTime != v10 )
  {
    v11 = (float)(v9 - m_parentTime) / (float)(v10 - m_parentTime);
    if ( v11 >= 0.0 )
    {
      if ( v11 <= 1.0 )
        goto LABEL_10;
      goto LABEL_9;
    }
LABEL_7:
    v11 = 0.0;
    goto LABEL_10;
  }
  if ( (float)(v9 - v10) < 0.0 )
    goto LABEL_7;
LABEL_9:
  v11 = 1.0;
LABEL_10:
  m_Index = this->m_pMoveParent.m_Index;
  offset.x = this->m_vecOffset.x * (float)(1.0 - v11);
  v13 = (float)(1.0 - v11) * this->m_vecOffset.z;
  offset.y = (float)(1.0 - v11) * this->m_vecOffset.y;
  offset.z = v13;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  memset((void *)&worldOrigin, 0, sizeof(worldOrigin));
  if ( m_pEntity != nullptr )
  {
    ((void (__stdcall *)(_DWORD, int, int, _DWORD))m_pEntity->SetupBones)(
      a1: 0,
      a2: -1,
      a3: 524032,
      a4: *(_DWORD *)(gpGlobals.m_Index + 12));
    C_BaseAnimating::GetCachedBoneMatrix(this: m_pEntity, boneIndex: this->m_boneIndexAttached, out: &boneToWorld);
    VectorTransform(in1: &this->m_attachmentPointBoneSpace.x, in2: &boneToWorld, out: &worldOrigin.x);
  }
  C_ServerRagdoll::BuildTransformations(this, a2: (int)&savedregs, hdr, pos, q, cameraTransform, boneMask, boneComputed);
  if ( m_pEntity != nullptr )
  {
    VectorTransform(
      in1: &this->m_attachmentPointRagdollSpace.x,
      in2: &this->m_BoneAccessor.m_pBones[this->m_boneIndex[this->m_ragdollAttachedObjectIndex]],
      out: &ragOrigin.x);
    out.x = worldOrigin.x - ragOrigin.x;
    out.y = worldOrigin.y - ragOrigin.y;
    out.z = worldOrigin.z - ragOrigin.z;
    offset.x = worldOrigin.x - ragOrigin.x;
    offset.y = worldOrigin.y - ragOrigin.y;
    offset.z = worldOrigin.z - ragOrigin.z;
    C_BaseEntity::SetAbsOrigin(this, absOrigin: &worldOrigin);
    this->m_vecOffset = out;
  }
  v15 = hdr;
  v16 = 0;
  if ( hdr->m_pStudioHdr->numbones > 0 )
  {
    boneComputeda = nullptr;
    do
    {
      if ( (boneMask & v15->m_boneFlags.m_Memory.m_pMemory[v16]) != 0 )
      {
        v17 = (matrix3x4a_t *)((char *)boneComputeda + (unsigned int)this->m_BoneAccessor.m_pBones);
        MatrixGetColumn(in: v17, column: 3, &out);
        out.x = out.x + offset.x;
        out.y = out.y + offset.y;
        out.z = out.z + offset.z;
        MatrixSetColumn(in: &out, column: 3, out: v17);
        v15 = hdr;
      }
      boneComputeda = (CBoneBitList *)((char *)boneComputeda + 48);
      ++v16;
    }
    while ( v16 < v15->m_pStudioHdr->numbones );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1015E130
// Name: public: void ragdoll_memory_list_t::AddToList(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ragdoll_memory_list_t::AddToList(ragdoll_memory_list_t *this, C_BaseEntity *pRagdoll)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ragdoll_remember_t *m_pMemory; // ecx
  int v6; // eax

  ragdoll_memory_list_t::Update(this);
  m_Size = this->list.m_Size;
  m_nAllocationCount = this->list.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->list.m_Size;
  m_pMemory = this->list.m_Memory.m_pMemory;
  v6 = this->list.m_Size - m_Size - 1;
  this->list.m_pElements = this->list.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 8 * v6);
  this->list.m_Memory.m_pMemory[m_Size].ragdoll = pRagdoll;
  this->list.m_Memory.m_pMemory[m_Size].tickCount = *(_DWORD *)(gpGlobals.m_Index + 24);
}

//------------------------------------------------------------------------------
// Address: 0x1015E1A0
// Name: void NoteRagdollCreationTick(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NoteRagdollCreationTick(C_BaseEntity *pRagdoll)
{
  ragdoll_memory_list_t::AddToList(this: &gRagdolls, pRagdoll);
}

//------------------------------------------------------------------------------
// Address: 0x1015E1C0
// Name: public: virtual int CInterpolatedVarArrayBase<class Vector,1>::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<Vector,1>::Interpolate(
        CInterpolatedVarArrayBase<Vector,1> *this,
        float currentTime)
{
  return CInterpolatedVarArrayBase<Vector,1>::Interpolate(
           this,
           currentTime,
           interpolation_amount: this->m_InterpolationAmount);
}

//------------------------------------------------------------------------------
// Address: 0x1015E1F0
// Name: public: virtual int CInterpolatedVarArrayBase<class QAngle,1>::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<QAngle,1>::Interpolate(
        CInterpolatedVarArrayBase<QAngle,1> *this,
        float currentTime)
{
  return CInterpolatedVarArrayBase<QAngle,1>::Interpolate(
           this,
           currentTime,
           interpolation_amount: this->m_InterpolationAmount);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE90
// Name: CRagdoll_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRagdoll_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRagdoll>();
  CRagdoll_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041BED0
// Name: _dynamic_initializer_for__ragdoll_sleepaftertime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ragdoll_sleepaftertime__()
{
  ConVar::ConVar(
    this: &ragdoll_sleepaftertime,
    pName: "ragdoll_sleepaftertime",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "After this many seconds of being basically stationary, the ragdoll will go to sleep.");
  return atexit(func: dynamic_atexit_destructor_for__ragdoll_sleepaftertime__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BF20
// Name: DT_Ragdoll::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Ragdoll::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Ragdoll::g_RecvTable);
  return atexit(func: DT_Ragdoll::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BF40
// Name: DT_Ragdoll::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Ragdoll::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Ragdoll::ignored>();
  DT_Ragdoll::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041BF70
// Name: DT_Ragdoll_Attached::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Ragdoll_Attached::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Ragdoll_Attached::g_RecvTable);
  return atexit(func: DT_Ragdoll_Attached::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BF90
// Name: DT_Ragdoll_Attached::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Ragdoll_Attached::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Ragdoll_Attached::ignored>();
  DT_Ragdoll_Attached::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10433780
// Name: _dynamic_atexit_destructor_for__ragdoll_sleepaftertime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ragdoll_sleepaftertime__()
{
  ConVar::~ConVar(this: &ragdoll_sleepaftertime);
}

//------------------------------------------------------------------------------
// Address: 0x10433790
// Name: DT_Ragdoll::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Ragdoll::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Ragdoll::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104337A0
// Name: DT_Ragdoll_Attached::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Ragdoll_Attached::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Ragdoll_Attached::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10030740
// Name: struct datamap_t __near * DataMapInit<class C_ClientRagdoll>(class C_ClientRagdoll __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<C_ClientRagdoll>()
{
  if ( (_S7_1 & 1) == 0 )
  {
    _S7_1 |= 1u;
    nameHolder_1.m_pszBase = "C_ClientRagdoll";
    nameHolder_1.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_1.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_1.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_1.m_Names.m_Size = 0;
    nameHolder_1.m_Names.m_pElements = nullptr;
    nameHolder_1.m_nLenBase = 15;
    atexit(func: DataMapInit_C_ClientRagdoll__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  C_ClientRagdoll::m_DataMap.baseMap = &C_BaseEntity::m_DataMap;
  C_ClientRagdoll::m_DataMap.dataNumFields = 23;
  C_ClientRagdoll::m_DataMap.dataDesc = &dataDesc_1[1];
  return &C_ClientRagdoll::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10031B50
// Name: _C_BaseAnimating_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseAnimating_CreateObject(int entnum, int serialNum)
{
  C_BaseAnimating *v2; // eax
  C_BaseAnimating *v3; // eax
  C_BaseAnimating *v4; // esi

  v2 = (C_BaseAnimating *)C_BaseEntity::operator new(stAllocateBlock: 0xCB8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseAnimating::C_BaseAnimating(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1015E0A0
// Name: _C_ServerRagdollAttached_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_ServerRagdollAttached_CreateObject(int entnum, int serialNum)
{
  C_ServerRagdoll *v2; // eax
  C_ServerRagdoll *v3; // esi
  bool (__thiscall *Init)(C_BaseEntity *, int, int); // eax

  v2 = (C_ServerRagdoll *)C_BaseEntity::operator new(stAllocateBlock: 0x10E0u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_ServerRagdoll::C_ServerRagdoll(this: v2);
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ServerRagdoll_vtbl *)&C_ServerRagdollAttached::`vftable'{for `IClientUnknown'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ServerRagdollAttached::`vftable'{for `IClientRenderable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ServerRagdollAttached::`vftable'{for `IClientNetworkable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ServerRagdollAttached::`vftable'{for `IClientThinkable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ServerRagdollAttached::`vftable';
  LOBYTE(v3[1].m_VarMap.m_Entries.m_pElements) = 0;
  Init = v3->Init;
  v3[1].C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = nullptr;
  v3[1].C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = nullptr;
  v3[1].m_iClassname = nullptr;
  Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1015E220
// Name: struct datamap_t __near * DataMapInit<class CRagdoll>(class CRagdoll __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRagdoll>()
{
  CPhysObjSaveRestoreOps *PhysObjSaveRestoreOps; // eax
  CPhysObjSaveRestoreOps *v1; // eax
  CPhysObjSaveRestoreOps *v2; // eax
  CPhysObjSaveRestoreOps *v3; // eax
  CPhysObjSaveRestoreOps *v4; // eax
  CPhysObjSaveRestoreOps *v5; // eax
  CPhysObjSaveRestoreOps *v6; // eax
  CPhysObjSaveRestoreOps *v7; // eax
  CPhysObjSaveRestoreOps *v8; // eax
  CPhysObjSaveRestoreOps *v9; // eax
  CPhysObjSaveRestoreOps *v10; // eax
  CPhysObjSaveRestoreOps *v11; // eax
  CPhysObjSaveRestoreOps *v12; // eax
  CPhysObjSaveRestoreOps *v13; // eax
  CPhysObjSaveRestoreOps *v14; // eax
  CPhysObjSaveRestoreOps *v15; // eax
  CPhysObjSaveRestoreOps *v16; // eax
  CPhysObjSaveRestoreOps *v17; // eax
  CPhysObjSaveRestoreOps *v18; // eax
  CPhysObjSaveRestoreOps *v19; // eax
  CPhysObjSaveRestoreOps *v20; // eax
  CPhysObjSaveRestoreOps *v21; // eax
  CPhysObjSaveRestoreOps *v22; // eax
  CPhysObjSaveRestoreOps *v23; // eax
  CPhysObjSaveRestoreOps *v24; // eax
  CPhysObjSaveRestoreOps *v25; // eax
  CPhysObjSaveRestoreOps *v26; // eax

  if ( (_S5_113 & 1) == 0 )
  {
    _S5_113 |= 1u;
    nameHolder_16.m_pszBase = "CRagdoll";
    nameHolder_16.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_16.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_16.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_16.m_Names.m_Size = 0;
    nameHolder_16.m_Names.m_pElements = nullptr;
    nameHolder_16.m_nLenBase = 8;
    atexit(func: DataMapInit_CRagdoll__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRagdoll::m_DataMap.baseMap = nullptr;
  if ( (_S5_113 & 2) == 0 )
  {
    _S5_113 |= 2u;
    PhysObjSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINTGROUP);
    *(_QWORD *)&dataDesc_15[4].td = 0;
    *(_QWORD *)&dataDesc_15[4].override_field = 0;
    *(_QWORD *)&dataDesc_15[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[4].flatOffset[1] = 0;
    dataDesc_15[5].fieldTolerance = 0.0;
    dataDesc_15[4].pSaveRestoreOps = PhysObjSaveRestoreOps;
    dataDesc_15[4].inputFunc = nullptr;
    dataDesc_15[5].fieldType = FIELD_VECTOR;
    dataDesc_15[5].fieldName = "m_ragdoll.list[0].originParentSpace";
    dataDesc_15[5].fieldOffset = 16;
    *(_DWORD *)&dataDesc_15[5].fieldSize = 131073;
    dataDesc_15[5].externalName = nullptr;
    dataDesc_15[5].pSaveRestoreOps = nullptr;
    dataDesc_15[5].inputFunc = nullptr;
    dataDesc_15[5].td = nullptr;
    dataDesc_15[5].fieldSizeInBytes = 12;
    dataDesc_15[5].override_field = nullptr;
    dataDesc_15[5].override_count = 0;
    *(_QWORD *)dataDesc_15[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[5].flatGroup = 0;
    dataDesc_15[6].fieldType = FIELD_CUSTOM;
    dataDesc_15[6].fieldName = "m_ragdoll.list[0].pObject";
    dataDesc_15[6].fieldOffset = 28;
    *(_DWORD *)&dataDesc_15[6].fieldSize = 131073;
    dataDesc_15[6].externalName = nullptr;
    dataDesc_15[6].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[6].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[6].td = 0;
    *(_QWORD *)&dataDesc_15[6].override_field = 0;
    *(_QWORD *)&dataDesc_15[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[6].flatOffset[1] = 0;
    dataDesc_15[7].fieldType = FIELD_CUSTOM;
    dataDesc_15[7].fieldName = "m_ragdoll.list[0].pConstraint";
    dataDesc_15[7].fieldOffset = 32;
    *(_DWORD *)&dataDesc_15[7].fieldSize = 131073;
    dataDesc_15[7].externalName = nullptr;
    v1 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[7].td = 0;
    *(_QWORD *)&dataDesc_15[7].override_field = 0;
    *(_QWORD *)&dataDesc_15[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[7].flatOffset[1] = 0;
    dataDesc_15[7].pSaveRestoreOps = v1;
    dataDesc_15[7].inputFunc = nullptr;
    dataDesc_15[8].fieldType = FIELD_INTEGER;
    dataDesc_15[8].fieldName = "m_ragdoll.list[0].parentIndex";
    dataDesc_15[8].fieldOffset = 36;
    *(_DWORD *)&dataDesc_15[8].fieldSize = 131073;
    dataDesc_15[8].externalName = nullptr;
    dataDesc_15[8].pSaveRestoreOps = nullptr;
    dataDesc_15[8].inputFunc = nullptr;
    dataDesc_15[8].td = nullptr;
    dataDesc_15[8].fieldSizeInBytes = 4;
    dataDesc_15[8].override_field = nullptr;
    dataDesc_15[8].override_count = 0;
    dataDesc_15[8].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_15[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[8].flatGroup = 0;
    dataDesc_15[9].fieldType = FIELD_VECTOR;
    dataDesc_15[9].fieldName = "m_ragdoll.list[1].originParentSpace";
    dataDesc_15[9].fieldOffset = 40;
    *(_DWORD *)&dataDesc_15[9].fieldSize = 131073;
    dataDesc_15[9].externalName = nullptr;
    dataDesc_15[9].pSaveRestoreOps = nullptr;
    dataDesc_15[9].inputFunc = nullptr;
    dataDesc_15[9].fieldTolerance = 0.0;
    dataDesc_15[9].td = nullptr;
    dataDesc_15[9].fieldSizeInBytes = 12;
    dataDesc_15[9].override_field = nullptr;
    dataDesc_15[9].override_count = 0;
    *(_QWORD *)dataDesc_15[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[9].flatGroup = 0;
    dataDesc_15[10].fieldType = FIELD_CUSTOM;
    dataDesc_15[10].fieldName = "m_ragdoll.list[1].pObject";
    dataDesc_15[10].fieldOffset = 52;
    *(_DWORD *)&dataDesc_15[10].fieldSize = 131073;
    dataDesc_15[10].externalName = nullptr;
    dataDesc_15[10].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[10].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[10].td = 0;
    *(_QWORD *)&dataDesc_15[10].override_field = 0;
    *(_QWORD *)&dataDesc_15[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[10].flatOffset[1] = 0;
    dataDesc_15[11].fieldType = FIELD_CUSTOM;
    dataDesc_15[11].fieldName = "m_ragdoll.list[1].pConstraint";
    dataDesc_15[11].fieldOffset = 56;
    *(_DWORD *)&dataDesc_15[11].fieldSize = 131073;
    dataDesc_15[11].externalName = nullptr;
    v2 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[11].td = 0;
    *(_QWORD *)&dataDesc_15[11].override_field = 0;
    *(_QWORD *)&dataDesc_15[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[11].flatOffset[1] = 0;
    dataDesc_15[12].fieldTolerance = 0.0;
    dataDesc_15[13].fieldTolerance = 0.0;
    dataDesc_15[11].pSaveRestoreOps = v2;
    dataDesc_15[11].inputFunc = nullptr;
    dataDesc_15[12].fieldType = FIELD_INTEGER;
    dataDesc_15[12].fieldName = "m_ragdoll.list[1].parentIndex";
    dataDesc_15[12].fieldOffset = 60;
    *(_DWORD *)&dataDesc_15[12].fieldSize = 131073;
    dataDesc_15[12].externalName = nullptr;
    dataDesc_15[12].pSaveRestoreOps = nullptr;
    dataDesc_15[12].inputFunc = nullptr;
    dataDesc_15[12].td = nullptr;
    dataDesc_15[12].fieldSizeInBytes = 4;
    dataDesc_15[12].override_field = nullptr;
    dataDesc_15[12].override_count = 0;
    *(_QWORD *)dataDesc_15[12].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[12].flatGroup = 0;
    dataDesc_15[13].fieldType = FIELD_VECTOR;
    dataDesc_15[13].fieldName = "m_ragdoll.list[2].originParentSpace";
    dataDesc_15[13].fieldOffset = 64;
    *(_DWORD *)&dataDesc_15[13].fieldSize = 131073;
    dataDesc_15[13].externalName = nullptr;
    dataDesc_15[13].pSaveRestoreOps = nullptr;
    dataDesc_15[13].inputFunc = nullptr;
    dataDesc_15[13].td = nullptr;
    dataDesc_15[13].fieldSizeInBytes = 12;
    dataDesc_15[13].override_field = nullptr;
    dataDesc_15[13].override_count = 0;
    *(_QWORD *)dataDesc_15[13].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[13].flatGroup = 0;
    dataDesc_15[14].fieldType = FIELD_CUSTOM;
    dataDesc_15[14].fieldName = "m_ragdoll.list[2].pObject";
    dataDesc_15[14].fieldOffset = 76;
    *(_DWORD *)&dataDesc_15[14].fieldSize = 131073;
    dataDesc_15[14].externalName = nullptr;
    dataDesc_15[14].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[14].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[14].td = 0;
    *(_QWORD *)&dataDesc_15[14].override_field = 0;
    *(_QWORD *)&dataDesc_15[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[14].flatOffset[1] = 0;
    dataDesc_15[15].fieldType = FIELD_CUSTOM;
    dataDesc_15[15].fieldName = "m_ragdoll.list[2].pConstraint";
    dataDesc_15[15].fieldOffset = 80;
    *(_DWORD *)&dataDesc_15[15].fieldSize = 131073;
    dataDesc_15[15].externalName = nullptr;
    v3 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[15].td = 0;
    *(_QWORD *)&dataDesc_15[15].override_field = 0;
    *(_QWORD *)&dataDesc_15[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[15].flatOffset[1] = 0;
    dataDesc_15[16].fieldTolerance = 0.0;
    dataDesc_15[17].fieldTolerance = 0.0;
    dataDesc_15[15].pSaveRestoreOps = v3;
    dataDesc_15[15].inputFunc = nullptr;
    dataDesc_15[16].fieldType = FIELD_INTEGER;
    dataDesc_15[16].fieldName = "m_ragdoll.list[2].parentIndex";
    dataDesc_15[16].fieldOffset = 84;
    *(_DWORD *)&dataDesc_15[16].fieldSize = 131073;
    dataDesc_15[16].externalName = nullptr;
    dataDesc_15[16].pSaveRestoreOps = nullptr;
    dataDesc_15[16].inputFunc = nullptr;
    dataDesc_15[16].td = nullptr;
    dataDesc_15[16].fieldSizeInBytes = 4;
    dataDesc_15[16].override_field = nullptr;
    dataDesc_15[16].override_count = 0;
    *(_QWORD *)dataDesc_15[16].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[16].flatGroup = 0;
    dataDesc_15[17].fieldType = FIELD_VECTOR;
    dataDesc_15[17].fieldName = "m_ragdoll.list[3].originParentSpace";
    dataDesc_15[17].fieldOffset = 88;
    *(_DWORD *)&dataDesc_15[17].fieldSize = 131073;
    dataDesc_15[17].externalName = nullptr;
    dataDesc_15[17].pSaveRestoreOps = nullptr;
    dataDesc_15[17].inputFunc = nullptr;
    dataDesc_15[17].td = nullptr;
    dataDesc_15[17].fieldSizeInBytes = 12;
    dataDesc_15[17].override_field = nullptr;
    dataDesc_15[17].override_count = 0;
    *(_QWORD *)dataDesc_15[17].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[17].flatGroup = 0;
    dataDesc_15[18].fieldType = FIELD_CUSTOM;
    dataDesc_15[18].fieldName = "m_ragdoll.list[3].pObject";
    dataDesc_15[18].fieldOffset = 100;
    *(_DWORD *)&dataDesc_15[18].fieldSize = 131073;
    dataDesc_15[18].externalName = nullptr;
    dataDesc_15[18].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[18].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[18].td = 0;
    *(_QWORD *)&dataDesc_15[18].override_field = 0;
    *(_QWORD *)&dataDesc_15[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[18].flatOffset[1] = 0;
    dataDesc_15[19].fieldType = FIELD_CUSTOM;
    dataDesc_15[19].fieldName = "m_ragdoll.list[3].pConstraint";
    dataDesc_15[19].fieldOffset = 104;
    *(_DWORD *)&dataDesc_15[19].fieldSize = 131073;
    dataDesc_15[19].externalName = nullptr;
    dataDesc_15[19].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_15[19].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[19].td = 0;
    *(_QWORD *)&dataDesc_15[19].override_field = 0;
    *(_QWORD *)&dataDesc_15[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[19].flatOffset[1] = 0;
    dataDesc_15[20].fieldType = FIELD_INTEGER;
    dataDesc_15[20].fieldName = "m_ragdoll.list[3].parentIndex";
    dataDesc_15[20].fieldOffset = 108;
    *(_DWORD *)&dataDesc_15[20].fieldSize = 131073;
    dataDesc_15[20].externalName = nullptr;
    dataDesc_15[20].pSaveRestoreOps = nullptr;
    dataDesc_15[20].inputFunc = nullptr;
    dataDesc_15[20].td = nullptr;
    dataDesc_15[20].fieldTolerance = 0.0;
    dataDesc_15[21].fieldTolerance = 0.0;
    dataDesc_15[20].fieldSizeInBytes = 4;
    dataDesc_15[20].override_field = nullptr;
    dataDesc_15[20].override_count = 0;
    *(_QWORD *)dataDesc_15[20].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[20].flatGroup = 0;
    dataDesc_15[21].fieldType = FIELD_VECTOR;
    dataDesc_15[21].fieldName = "m_ragdoll.list[4].originParentSpace";
    dataDesc_15[21].fieldOffset = 112;
    *(_DWORD *)&dataDesc_15[21].fieldSize = 131073;
    dataDesc_15[21].externalName = nullptr;
    dataDesc_15[21].pSaveRestoreOps = nullptr;
    dataDesc_15[21].inputFunc = nullptr;
    dataDesc_15[21].td = nullptr;
    dataDesc_15[21].fieldSizeInBytes = 12;
    dataDesc_15[21].override_field = nullptr;
    dataDesc_15[21].override_count = 0;
    *(_QWORD *)dataDesc_15[21].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[21].flatGroup = 0;
    dataDesc_15[22].fieldType = FIELD_CUSTOM;
    dataDesc_15[22].fieldName = "m_ragdoll.list[4].pObject";
    dataDesc_15[22].fieldOffset = 124;
    *(_DWORD *)&dataDesc_15[22].fieldSize = 131073;
    dataDesc_15[22].externalName = nullptr;
    dataDesc_15[22].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[22].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[22].td = 0;
    *(_QWORD *)&dataDesc_15[22].override_field = 0;
    *(_QWORD *)&dataDesc_15[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[22].flatOffset[1] = 0;
    dataDesc_15[23].fieldType = FIELD_CUSTOM;
    dataDesc_15[23].fieldName = "m_ragdoll.list[4].pConstraint";
    dataDesc_15[23].fieldOffset = 128;
    *(_DWORD *)&dataDesc_15[23].fieldSize = 131073;
    dataDesc_15[23].externalName = nullptr;
    v4 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[23].td = 0;
    *(_QWORD *)&dataDesc_15[23].override_field = 0;
    *(_QWORD *)&dataDesc_15[23].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[23].flatOffset[1] = 0;
    dataDesc_15[24].fieldTolerance = 0.0;
    dataDesc_15[25].fieldTolerance = 0.0;
    dataDesc_15[23].pSaveRestoreOps = v4;
    dataDesc_15[23].inputFunc = nullptr;
    dataDesc_15[24].fieldType = FIELD_INTEGER;
    dataDesc_15[24].fieldName = "m_ragdoll.list[4].parentIndex";
    dataDesc_15[24].fieldOffset = 132;
    *(_DWORD *)&dataDesc_15[24].fieldSize = 131073;
    dataDesc_15[24].externalName = nullptr;
    dataDesc_15[24].pSaveRestoreOps = nullptr;
    dataDesc_15[24].inputFunc = nullptr;
    dataDesc_15[24].td = nullptr;
    dataDesc_15[24].fieldSizeInBytes = 4;
    dataDesc_15[24].override_field = nullptr;
    dataDesc_15[24].override_count = 0;
    *(_QWORD *)dataDesc_15[24].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[24].flatGroup = 0;
    dataDesc_15[25].fieldType = FIELD_VECTOR;
    dataDesc_15[25].fieldName = "m_ragdoll.list[5].originParentSpace";
    dataDesc_15[25].fieldOffset = 136;
    *(_DWORD *)&dataDesc_15[25].fieldSize = 131073;
    dataDesc_15[25].externalName = nullptr;
    dataDesc_15[25].pSaveRestoreOps = nullptr;
    dataDesc_15[25].inputFunc = nullptr;
    dataDesc_15[25].td = nullptr;
    dataDesc_15[25].fieldSizeInBytes = 12;
    dataDesc_15[25].override_field = nullptr;
    dataDesc_15[25].override_count = 0;
    *(_QWORD *)dataDesc_15[25].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[25].flatGroup = 0;
    dataDesc_15[26].fieldType = FIELD_CUSTOM;
    dataDesc_15[26].fieldName = "m_ragdoll.list[5].pObject";
    dataDesc_15[26].fieldOffset = 148;
    *(_DWORD *)&dataDesc_15[26].fieldSize = 131073;
    dataDesc_15[26].externalName = nullptr;
    dataDesc_15[26].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[26].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[26].td = 0;
    *(_QWORD *)&dataDesc_15[26].override_field = 0;
    *(_QWORD *)&dataDesc_15[26].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[26].flatOffset[1] = 0;
    dataDesc_15[27].fieldType = FIELD_CUSTOM;
    dataDesc_15[27].fieldName = "m_ragdoll.list[5].pConstraint";
    dataDesc_15[27].fieldOffset = 152;
    *(_DWORD *)&dataDesc_15[27].fieldSize = 131073;
    dataDesc_15[27].externalName = nullptr;
    v5 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[27].td = 0;
    *(_QWORD *)&dataDesc_15[27].override_field = 0;
    *(_QWORD *)&dataDesc_15[27].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[27].flatOffset[1] = 0;
    dataDesc_15[28].fieldTolerance = 0.0;
    dataDesc_15[29].fieldTolerance = 0.0;
    dataDesc_15[27].pSaveRestoreOps = v5;
    dataDesc_15[27].inputFunc = nullptr;
    dataDesc_15[28].fieldType = FIELD_INTEGER;
    dataDesc_15[28].fieldName = "m_ragdoll.list[5].parentIndex";
    dataDesc_15[28].fieldOffset = 156;
    *(_DWORD *)&dataDesc_15[28].fieldSize = 131073;
    dataDesc_15[28].externalName = nullptr;
    dataDesc_15[28].pSaveRestoreOps = nullptr;
    dataDesc_15[28].inputFunc = nullptr;
    dataDesc_15[28].td = nullptr;
    dataDesc_15[28].fieldSizeInBytes = 4;
    dataDesc_15[28].override_field = nullptr;
    dataDesc_15[28].override_count = 0;
    *(_QWORD *)dataDesc_15[28].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[28].flatGroup = 0;
    dataDesc_15[29].fieldType = FIELD_VECTOR;
    dataDesc_15[29].fieldName = "m_ragdoll.list[6].originParentSpace";
    dataDesc_15[29].fieldOffset = 160;
    *(_DWORD *)&dataDesc_15[29].fieldSize = 131073;
    dataDesc_15[29].externalName = nullptr;
    dataDesc_15[29].pSaveRestoreOps = nullptr;
    dataDesc_15[29].inputFunc = nullptr;
    dataDesc_15[29].td = nullptr;
    dataDesc_15[29].fieldSizeInBytes = 12;
    dataDesc_15[29].override_field = nullptr;
    dataDesc_15[29].override_count = 0;
    *(_QWORD *)dataDesc_15[29].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[29].flatGroup = 0;
    dataDesc_15[30].fieldType = FIELD_CUSTOM;
    dataDesc_15[30].fieldName = "m_ragdoll.list[6].pObject";
    dataDesc_15[30].fieldOffset = 172;
    *(_DWORD *)&dataDesc_15[30].fieldSize = 131073;
    dataDesc_15[30].externalName = nullptr;
    dataDesc_15[30].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[30].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[30].td = 0;
    *(_QWORD *)&dataDesc_15[30].override_field = 0;
    *(_QWORD *)&dataDesc_15[30].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[30].flatOffset[1] = 0;
    dataDesc_15[31].fieldType = FIELD_CUSTOM;
    dataDesc_15[31].fieldName = "m_ragdoll.list[6].pConstraint";
    dataDesc_15[31].fieldOffset = 176;
    *(_DWORD *)&dataDesc_15[31].fieldSize = 131073;
    dataDesc_15[31].externalName = nullptr;
    v6 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[31].td = 0;
    *(_QWORD *)&dataDesc_15[31].override_field = 0;
    *(_QWORD *)&dataDesc_15[31].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[31].flatOffset[1] = 0;
    dataDesc_15[32].fieldTolerance = 0.0;
    dataDesc_15[33].fieldTolerance = 0.0;
    dataDesc_15[31].pSaveRestoreOps = v6;
    dataDesc_15[31].inputFunc = nullptr;
    dataDesc_15[32].fieldType = FIELD_INTEGER;
    dataDesc_15[32].fieldName = "m_ragdoll.list[6].parentIndex";
    dataDesc_15[32].fieldOffset = 180;
    *(_DWORD *)&dataDesc_15[32].fieldSize = 131073;
    dataDesc_15[32].externalName = nullptr;
    dataDesc_15[32].pSaveRestoreOps = nullptr;
    dataDesc_15[32].inputFunc = nullptr;
    dataDesc_15[32].td = nullptr;
    dataDesc_15[32].fieldSizeInBytes = 4;
    dataDesc_15[32].override_field = nullptr;
    dataDesc_15[32].override_count = 0;
    *(_QWORD *)dataDesc_15[32].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[32].flatGroup = 0;
    dataDesc_15[33].fieldType = FIELD_VECTOR;
    dataDesc_15[33].fieldName = "m_ragdoll.list[7].originParentSpace";
    dataDesc_15[33].fieldOffset = 184;
    *(_DWORD *)&dataDesc_15[33].fieldSize = 131073;
    dataDesc_15[33].externalName = nullptr;
    dataDesc_15[33].pSaveRestoreOps = nullptr;
    dataDesc_15[33].inputFunc = nullptr;
    dataDesc_15[33].td = nullptr;
    dataDesc_15[33].fieldSizeInBytes = 12;
    dataDesc_15[33].override_field = nullptr;
    dataDesc_15[33].override_count = 0;
    *(_QWORD *)dataDesc_15[33].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[33].flatGroup = 0;
    dataDesc_15[34].fieldType = FIELD_CUSTOM;
    dataDesc_15[34].fieldName = "m_ragdoll.list[7].pObject";
    dataDesc_15[34].fieldOffset = 196;
    *(_DWORD *)&dataDesc_15[34].fieldSize = 131073;
    dataDesc_15[34].externalName = nullptr;
    dataDesc_15[34].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[34].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[34].td = 0;
    *(_QWORD *)&dataDesc_15[34].override_field = 0;
    *(_QWORD *)&dataDesc_15[34].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[34].flatOffset[1] = 0;
    dataDesc_15[35].fieldType = FIELD_CUSTOM;
    dataDesc_15[35].fieldName = "m_ragdoll.list[7].pConstraint";
    dataDesc_15[35].fieldOffset = 200;
    *(_DWORD *)&dataDesc_15[35].fieldSize = 131073;
    dataDesc_15[35].externalName = nullptr;
    v7 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[35].td = 0;
    *(_QWORD *)&dataDesc_15[35].override_field = 0;
    *(_QWORD *)&dataDesc_15[35].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[35].flatOffset[1] = 0;
    dataDesc_15[35].pSaveRestoreOps = v7;
    dataDesc_15[35].inputFunc = nullptr;
    dataDesc_15[36].fieldType = FIELD_INTEGER;
    dataDesc_15[36].fieldName = "m_ragdoll.list[7].parentIndex";
    dataDesc_15[36].fieldOffset = 204;
    *(_DWORD *)&dataDesc_15[36].fieldSize = 131073;
    dataDesc_15[36].externalName = nullptr;
    dataDesc_15[36].pSaveRestoreOps = nullptr;
    dataDesc_15[36].inputFunc = nullptr;
    dataDesc_15[36].td = nullptr;
    dataDesc_15[36].fieldSizeInBytes = 4;
    dataDesc_15[36].override_field = nullptr;
    dataDesc_15[36].override_count = 0;
    dataDesc_15[36].fieldTolerance = 0.0;
    dataDesc_15[37].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_15[36].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[36].flatGroup = 0;
    dataDesc_15[37].fieldType = FIELD_VECTOR;
    dataDesc_15[37].fieldName = "m_ragdoll.list[8].originParentSpace";
    dataDesc_15[37].fieldOffset = 208;
    *(_DWORD *)&dataDesc_15[37].fieldSize = 131073;
    dataDesc_15[37].externalName = nullptr;
    dataDesc_15[37].pSaveRestoreOps = nullptr;
    dataDesc_15[37].inputFunc = nullptr;
    dataDesc_15[37].td = nullptr;
    dataDesc_15[37].fieldSizeInBytes = 12;
    dataDesc_15[37].override_field = nullptr;
    dataDesc_15[37].override_count = 0;
    *(_QWORD *)dataDesc_15[37].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[37].flatGroup = 0;
    dataDesc_15[38].fieldType = FIELD_CUSTOM;
    dataDesc_15[38].fieldName = "m_ragdoll.list[8].pObject";
    dataDesc_15[38].fieldOffset = 220;
    *(_DWORD *)&dataDesc_15[38].fieldSize = 131073;
    dataDesc_15[38].externalName = nullptr;
    dataDesc_15[38].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[38].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[38].td = 0;
    *(_QWORD *)&dataDesc_15[38].override_field = 0;
    *(_QWORD *)&dataDesc_15[38].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[38].flatOffset[1] = 0;
    dataDesc_15[39].fieldType = FIELD_CUSTOM;
    dataDesc_15[39].fieldName = "m_ragdoll.list[8].pConstraint";
    dataDesc_15[39].fieldOffset = 224;
    *(_DWORD *)&dataDesc_15[39].fieldSize = 131073;
    dataDesc_15[39].externalName = nullptr;
    v8 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[39].td = 0;
    *(_QWORD *)&dataDesc_15[39].override_field = 0;
    *(_QWORD *)&dataDesc_15[39].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[39].flatOffset[1] = 0;
    dataDesc_15[40].fieldTolerance = 0.0;
    dataDesc_15[41].fieldTolerance = 0.0;
    dataDesc_15[39].pSaveRestoreOps = v8;
    dataDesc_15[39].inputFunc = nullptr;
    dataDesc_15[40].fieldType = FIELD_INTEGER;
    dataDesc_15[40].fieldName = "m_ragdoll.list[8].parentIndex";
    dataDesc_15[40].fieldOffset = 228;
    *(_DWORD *)&dataDesc_15[40].fieldSize = 131073;
    dataDesc_15[40].externalName = nullptr;
    dataDesc_15[40].pSaveRestoreOps = nullptr;
    dataDesc_15[40].inputFunc = nullptr;
    dataDesc_15[40].td = nullptr;
    dataDesc_15[40].fieldSizeInBytes = 4;
    dataDesc_15[40].override_field = nullptr;
    dataDesc_15[40].override_count = 0;
    *(_QWORD *)dataDesc_15[40].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[40].flatGroup = 0;
    dataDesc_15[41].fieldType = FIELD_VECTOR;
    dataDesc_15[41].fieldName = "m_ragdoll.list[9].originParentSpace";
    dataDesc_15[41].fieldOffset = 232;
    *(_DWORD *)&dataDesc_15[41].fieldSize = 131073;
    dataDesc_15[41].externalName = nullptr;
    dataDesc_15[41].pSaveRestoreOps = nullptr;
    dataDesc_15[41].inputFunc = nullptr;
    dataDesc_15[41].td = nullptr;
    dataDesc_15[41].fieldSizeInBytes = 12;
    dataDesc_15[41].override_field = nullptr;
    dataDesc_15[41].override_count = 0;
    *(_QWORD *)dataDesc_15[41].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[41].flatGroup = 0;
    dataDesc_15[42].fieldType = FIELD_CUSTOM;
    dataDesc_15[42].fieldName = "m_ragdoll.list[9].pObject";
    dataDesc_15[42].fieldOffset = 244;
    *(_DWORD *)&dataDesc_15[42].fieldSize = 131073;
    dataDesc_15[42].externalName = nullptr;
    dataDesc_15[42].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[42].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[42].td = 0;
    *(_QWORD *)&dataDesc_15[42].override_field = 0;
    *(_QWORD *)&dataDesc_15[42].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[42].flatOffset[1] = 0;
    dataDesc_15[43].fieldType = FIELD_CUSTOM;
    dataDesc_15[43].fieldName = "m_ragdoll.list[9].pConstraint";
    dataDesc_15[43].fieldOffset = 248;
    *(_DWORD *)&dataDesc_15[43].fieldSize = 131073;
    dataDesc_15[43].externalName = nullptr;
    v9 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[43].td = 0;
    *(_QWORD *)&dataDesc_15[43].override_field = 0;
    *(_QWORD *)&dataDesc_15[43].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[43].flatOffset[1] = 0;
    dataDesc_15[44].fieldTolerance = 0.0;
    dataDesc_15[45].fieldTolerance = 0.0;
    dataDesc_15[43].pSaveRestoreOps = v9;
    dataDesc_15[43].inputFunc = nullptr;
    dataDesc_15[44].fieldType = FIELD_INTEGER;
    dataDesc_15[44].fieldName = "m_ragdoll.list[9].parentIndex";
    dataDesc_15[44].fieldOffset = 252;
    *(_DWORD *)&dataDesc_15[44].fieldSize = 131073;
    dataDesc_15[44].externalName = nullptr;
    dataDesc_15[44].pSaveRestoreOps = nullptr;
    dataDesc_15[44].inputFunc = nullptr;
    dataDesc_15[44].td = nullptr;
    dataDesc_15[44].fieldSizeInBytes = 4;
    dataDesc_15[44].override_field = nullptr;
    dataDesc_15[44].override_count = 0;
    *(_QWORD *)dataDesc_15[44].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[44].flatGroup = 0;
    dataDesc_15[45].fieldType = FIELD_VECTOR;
    dataDesc_15[45].fieldName = "m_ragdoll.list[10].originParentSpace";
    dataDesc_15[45].fieldOffset = 256;
    *(_DWORD *)&dataDesc_15[45].fieldSize = 131073;
    dataDesc_15[45].externalName = nullptr;
    dataDesc_15[45].pSaveRestoreOps = nullptr;
    dataDesc_15[45].inputFunc = nullptr;
    dataDesc_15[45].td = nullptr;
    dataDesc_15[45].fieldSizeInBytes = 12;
    dataDesc_15[45].override_field = nullptr;
    dataDesc_15[45].override_count = 0;
    *(_QWORD *)dataDesc_15[45].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[45].flatGroup = 0;
    dataDesc_15[46].fieldType = FIELD_CUSTOM;
    dataDesc_15[46].fieldName = "m_ragdoll.list[10].pObject";
    dataDesc_15[46].fieldOffset = 268;
    *(_DWORD *)&dataDesc_15[46].fieldSize = 131073;
    dataDesc_15[46].externalName = nullptr;
    dataDesc_15[46].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[46].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[46].td = 0;
    *(_QWORD *)&dataDesc_15[46].override_field = 0;
    *(_QWORD *)&dataDesc_15[46].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[46].flatOffset[1] = 0;
    dataDesc_15[47].fieldType = FIELD_CUSTOM;
    dataDesc_15[47].fieldName = "m_ragdoll.list[10].pConstraint";
    dataDesc_15[47].fieldOffset = 272;
    *(_DWORD *)&dataDesc_15[47].fieldSize = 131073;
    dataDesc_15[47].externalName = nullptr;
    dataDesc_15[47].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_15[47].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[47].td = 0;
    *(_QWORD *)&dataDesc_15[47].override_field = 0;
    *(_QWORD *)&dataDesc_15[47].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[47].flatOffset[1] = 0;
    dataDesc_15[48].fieldTolerance = 0.0;
    dataDesc_15[49].fieldTolerance = 0.0;
    dataDesc_15[48].fieldType = FIELD_INTEGER;
    dataDesc_15[48].fieldName = "m_ragdoll.list[10].parentIndex";
    dataDesc_15[48].fieldOffset = 276;
    *(_DWORD *)&dataDesc_15[48].fieldSize = 131073;
    dataDesc_15[48].externalName = nullptr;
    dataDesc_15[48].pSaveRestoreOps = nullptr;
    dataDesc_15[48].inputFunc = nullptr;
    dataDesc_15[48].td = nullptr;
    dataDesc_15[48].fieldSizeInBytes = 4;
    dataDesc_15[48].override_field = nullptr;
    dataDesc_15[48].override_count = 0;
    *(_QWORD *)dataDesc_15[48].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[48].flatGroup = 0;
    dataDesc_15[49].fieldType = FIELD_VECTOR;
    dataDesc_15[49].fieldName = "m_ragdoll.list[11].originParentSpace";
    dataDesc_15[49].fieldOffset = 280;
    *(_DWORD *)&dataDesc_15[49].fieldSize = 131073;
    dataDesc_15[49].externalName = nullptr;
    dataDesc_15[49].pSaveRestoreOps = nullptr;
    dataDesc_15[49].inputFunc = nullptr;
    dataDesc_15[49].td = nullptr;
    dataDesc_15[49].fieldSizeInBytes = 12;
    dataDesc_15[49].override_field = nullptr;
    dataDesc_15[49].override_count = 0;
    *(_QWORD *)dataDesc_15[49].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[49].flatGroup = 0;
    dataDesc_15[50].fieldType = FIELD_CUSTOM;
    dataDesc_15[50].fieldName = "m_ragdoll.list[11].pObject";
    dataDesc_15[50].fieldOffset = 292;
    *(_DWORD *)&dataDesc_15[50].fieldSize = 131073;
    dataDesc_15[50].externalName = nullptr;
    dataDesc_15[50].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[50].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[50].td = 0;
    *(_QWORD *)&dataDesc_15[50].override_field = 0;
    *(_QWORD *)&dataDesc_15[50].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[50].flatOffset[1] = 0;
    dataDesc_15[51].fieldType = FIELD_CUSTOM;
    dataDesc_15[51].fieldName = "m_ragdoll.list[11].pConstraint";
    dataDesc_15[51].fieldOffset = 296;
    *(_DWORD *)&dataDesc_15[51].fieldSize = 131073;
    dataDesc_15[51].externalName = nullptr;
    v10 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[51].td = 0;
    *(_QWORD *)&dataDesc_15[51].override_field = 0;
    *(_QWORD *)&dataDesc_15[51].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[51].flatOffset[1] = 0;
    dataDesc_15[51].pSaveRestoreOps = v10;
    dataDesc_15[51].inputFunc = nullptr;
    dataDesc_15[52].fieldType = FIELD_INTEGER;
    dataDesc_15[52].fieldName = "m_ragdoll.list[11].parentIndex";
    dataDesc_15[52].fieldOffset = 300;
    *(_DWORD *)&dataDesc_15[52].fieldSize = 131073;
    dataDesc_15[52].externalName = nullptr;
    dataDesc_15[52].pSaveRestoreOps = nullptr;
    dataDesc_15[52].inputFunc = nullptr;
    dataDesc_15[52].td = nullptr;
    dataDesc_15[52].fieldSizeInBytes = 4;
    dataDesc_15[52].override_field = nullptr;
    dataDesc_15[52].override_count = 0;
    dataDesc_15[52].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_15[52].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[52].flatGroup = 0;
    dataDesc_15[53].fieldType = FIELD_VECTOR;
    dataDesc_15[53].fieldName = "m_ragdoll.list[12].originParentSpace";
    dataDesc_15[53].fieldOffset = 304;
    *(_DWORD *)&dataDesc_15[53].fieldSize = 131073;
    dataDesc_15[53].externalName = nullptr;
    dataDesc_15[53].fieldTolerance = 0.0;
    dataDesc_15[53].pSaveRestoreOps = nullptr;
    dataDesc_15[53].inputFunc = nullptr;
    dataDesc_15[53].td = nullptr;
    dataDesc_15[53].fieldSizeInBytes = 12;
    dataDesc_15[53].override_field = nullptr;
    dataDesc_15[53].override_count = 0;
    *(_QWORD *)dataDesc_15[53].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[53].flatGroup = 0;
    dataDesc_15[54].fieldType = FIELD_CUSTOM;
    dataDesc_15[54].fieldName = "m_ragdoll.list[12].pObject";
    dataDesc_15[54].fieldOffset = 316;
    *(_DWORD *)&dataDesc_15[54].fieldSize = 131073;
    dataDesc_15[54].externalName = nullptr;
    dataDesc_15[54].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[54].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[54].td = 0;
    *(_QWORD *)&dataDesc_15[54].override_field = 0;
    *(_QWORD *)&dataDesc_15[54].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[54].flatOffset[1] = 0;
    dataDesc_15[55].fieldType = FIELD_CUSTOM;
    dataDesc_15[55].fieldName = "m_ragdoll.list[12].pConstraint";
    dataDesc_15[55].fieldOffset = 320;
    *(_DWORD *)&dataDesc_15[55].fieldSize = 131073;
    dataDesc_15[55].externalName = nullptr;
    v11 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[55].td = 0;
    *(_QWORD *)&dataDesc_15[55].override_field = 0;
    *(_QWORD *)&dataDesc_15[55].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[55].flatOffset[1] = 0;
    dataDesc_15[56].fieldTolerance = 0.0;
    dataDesc_15[57].fieldTolerance = 0.0;
    dataDesc_15[55].pSaveRestoreOps = v11;
    dataDesc_15[55].inputFunc = nullptr;
    dataDesc_15[56].fieldType = FIELD_INTEGER;
    dataDesc_15[56].fieldName = "m_ragdoll.list[12].parentIndex";
    dataDesc_15[56].fieldOffset = 324;
    *(_DWORD *)&dataDesc_15[56].fieldSize = 131073;
    dataDesc_15[56].externalName = nullptr;
    dataDesc_15[56].pSaveRestoreOps = nullptr;
    dataDesc_15[56].inputFunc = nullptr;
    dataDesc_15[56].td = nullptr;
    dataDesc_15[56].fieldSizeInBytes = 4;
    dataDesc_15[56].override_field = nullptr;
    dataDesc_15[56].override_count = 0;
    *(_QWORD *)dataDesc_15[56].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[56].flatGroup = 0;
    dataDesc_15[57].fieldType = FIELD_VECTOR;
    dataDesc_15[57].fieldName = "m_ragdoll.list[13].originParentSpace";
    dataDesc_15[57].fieldOffset = 328;
    *(_DWORD *)&dataDesc_15[57].fieldSize = 131073;
    dataDesc_15[57].externalName = nullptr;
    dataDesc_15[57].pSaveRestoreOps = nullptr;
    dataDesc_15[57].inputFunc = nullptr;
    dataDesc_15[57].td = nullptr;
    dataDesc_15[57].fieldSizeInBytes = 12;
    dataDesc_15[57].override_field = nullptr;
    dataDesc_15[57].override_count = 0;
    *(_QWORD *)dataDesc_15[57].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[57].flatGroup = 0;
    dataDesc_15[58].fieldType = FIELD_CUSTOM;
    dataDesc_15[58].fieldName = "m_ragdoll.list[13].pObject";
    dataDesc_15[58].fieldOffset = 340;
    *(_DWORD *)&dataDesc_15[58].fieldSize = 131073;
    dataDesc_15[58].externalName = nullptr;
    dataDesc_15[58].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[58].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[58].td = 0;
    *(_QWORD *)&dataDesc_15[58].override_field = 0;
    *(_QWORD *)&dataDesc_15[58].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[58].flatOffset[1] = 0;
    dataDesc_15[59].fieldType = FIELD_CUSTOM;
    dataDesc_15[59].fieldName = "m_ragdoll.list[13].pConstraint";
    dataDesc_15[59].fieldOffset = 344;
    *(_DWORD *)&dataDesc_15[59].fieldSize = 131073;
    dataDesc_15[59].externalName = nullptr;
    v12 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[59].td = 0;
    *(_QWORD *)&dataDesc_15[59].override_field = 0;
    *(_QWORD *)&dataDesc_15[59].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[59].flatOffset[1] = 0;
    dataDesc_15[60].fieldTolerance = 0.0;
    dataDesc_15[61].fieldTolerance = 0.0;
    dataDesc_15[59].pSaveRestoreOps = v12;
    dataDesc_15[59].inputFunc = nullptr;
    dataDesc_15[60].fieldType = FIELD_INTEGER;
    dataDesc_15[60].fieldName = "m_ragdoll.list[13].parentIndex";
    dataDesc_15[60].fieldOffset = 348;
    *(_DWORD *)&dataDesc_15[60].fieldSize = 131073;
    dataDesc_15[60].externalName = nullptr;
    dataDesc_15[60].pSaveRestoreOps = nullptr;
    dataDesc_15[60].inputFunc = nullptr;
    dataDesc_15[60].td = nullptr;
    dataDesc_15[60].fieldSizeInBytes = 4;
    dataDesc_15[60].override_field = nullptr;
    dataDesc_15[60].override_count = 0;
    *(_QWORD *)dataDesc_15[60].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[60].flatGroup = 0;
    dataDesc_15[61].fieldType = FIELD_VECTOR;
    dataDesc_15[61].fieldName = "m_ragdoll.list[14].originParentSpace";
    dataDesc_15[61].fieldOffset = 352;
    *(_DWORD *)&dataDesc_15[61].fieldSize = 131073;
    dataDesc_15[61].externalName = nullptr;
    dataDesc_15[61].pSaveRestoreOps = nullptr;
    dataDesc_15[61].inputFunc = nullptr;
    dataDesc_15[61].td = nullptr;
    dataDesc_15[61].fieldSizeInBytes = 12;
    dataDesc_15[61].override_field = nullptr;
    dataDesc_15[61].override_count = 0;
    *(_QWORD *)dataDesc_15[61].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[61].flatGroup = 0;
    dataDesc_15[62].fieldType = FIELD_CUSTOM;
    dataDesc_15[62].fieldName = "m_ragdoll.list[14].pObject";
    dataDesc_15[62].fieldOffset = 364;
    *(_DWORD *)&dataDesc_15[62].fieldSize = 131073;
    dataDesc_15[62].externalName = nullptr;
    dataDesc_15[62].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[62].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[62].td = 0;
    *(_QWORD *)&dataDesc_15[62].override_field = 0;
    *(_QWORD *)&dataDesc_15[62].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[62].flatOffset[1] = 0;
    dataDesc_15[63].fieldType = FIELD_CUSTOM;
    dataDesc_15[63].fieldName = "m_ragdoll.list[14].pConstraint";
    dataDesc_15[63].fieldOffset = 368;
    *(_DWORD *)&dataDesc_15[63].fieldSize = 131073;
    dataDesc_15[63].externalName = nullptr;
    dataDesc_15[63].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_15[63].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[63].td = 0;
    *(_QWORD *)&dataDesc_15[63].override_field = 0;
    *(_QWORD *)&dataDesc_15[63].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[63].flatOffset[1] = 0;
    dataDesc_15[64].fieldType = FIELD_INTEGER;
    dataDesc_15[64].fieldName = "m_ragdoll.list[14].parentIndex";
    dataDesc_15[64].fieldOffset = 372;
    *(_DWORD *)&dataDesc_15[64].fieldSize = 131073;
    dataDesc_15[64].externalName = nullptr;
    dataDesc_15[64].pSaveRestoreOps = nullptr;
    dataDesc_15[64].fieldTolerance = 0.0;
    dataDesc_15[65].fieldTolerance = 0.0;
    dataDesc_15[64].inputFunc = nullptr;
    dataDesc_15[64].td = nullptr;
    dataDesc_15[64].fieldSizeInBytes = 4;
    dataDesc_15[64].override_field = nullptr;
    dataDesc_15[64].override_count = 0;
    *(_QWORD *)dataDesc_15[64].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[64].flatGroup = 0;
    dataDesc_15[65].fieldType = FIELD_VECTOR;
    dataDesc_15[65].fieldName = "m_ragdoll.list[15].originParentSpace";
    dataDesc_15[65].fieldOffset = 376;
    *(_DWORD *)&dataDesc_15[65].fieldSize = 131073;
    dataDesc_15[65].externalName = nullptr;
    dataDesc_15[65].pSaveRestoreOps = nullptr;
    dataDesc_15[65].inputFunc = nullptr;
    dataDesc_15[65].td = nullptr;
    dataDesc_15[65].fieldSizeInBytes = 12;
    dataDesc_15[65].override_field = nullptr;
    dataDesc_15[65].override_count = 0;
    *(_QWORD *)dataDesc_15[65].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[65].flatGroup = 0;
    dataDesc_15[66].fieldType = FIELD_CUSTOM;
    dataDesc_15[66].fieldName = "m_ragdoll.list[15].pObject";
    dataDesc_15[66].fieldOffset = 388;
    *(_DWORD *)&dataDesc_15[66].fieldSize = 131073;
    dataDesc_15[66].externalName = nullptr;
    dataDesc_15[66].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[66].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[66].td = 0;
    *(_QWORD *)&dataDesc_15[66].override_field = 0;
    *(_QWORD *)&dataDesc_15[66].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[66].flatOffset[1] = 0;
    dataDesc_15[67].fieldType = FIELD_CUSTOM;
    dataDesc_15[67].fieldName = "m_ragdoll.list[15].pConstraint";
    dataDesc_15[67].fieldOffset = 392;
    *(_DWORD *)&dataDesc_15[67].fieldSize = 131073;
    dataDesc_15[67].externalName = nullptr;
    v13 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[67].td = 0;
    *(_QWORD *)&dataDesc_15[67].override_field = 0;
    *(_QWORD *)&dataDesc_15[67].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[67].flatOffset[1] = 0;
    dataDesc_15[67].pSaveRestoreOps = v13;
    dataDesc_15[67].inputFunc = nullptr;
    dataDesc_15[68].fieldType = FIELD_INTEGER;
    dataDesc_15[68].fieldName = "m_ragdoll.list[15].parentIndex";
    dataDesc_15[68].fieldOffset = 396;
    *(_DWORD *)&dataDesc_15[68].fieldSize = 131073;
    dataDesc_15[68].externalName = nullptr;
    dataDesc_15[68].pSaveRestoreOps = nullptr;
    dataDesc_15[68].inputFunc = nullptr;
    dataDesc_15[68].td = nullptr;
    dataDesc_15[68].fieldSizeInBytes = 4;
    dataDesc_15[68].override_field = nullptr;
    dataDesc_15[68].override_count = 0;
    dataDesc_15[68].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_15[68].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[68].flatGroup = 0;
    dataDesc_15[69].fieldType = FIELD_VECTOR;
    dataDesc_15[69].fieldName = "m_ragdoll.list[16].originParentSpace";
    dataDesc_15[69].fieldOffset = 400;
    *(_DWORD *)&dataDesc_15[69].fieldSize = 131073;
    dataDesc_15[69].externalName = nullptr;
    dataDesc_15[69].pSaveRestoreOps = nullptr;
    dataDesc_15[69].inputFunc = nullptr;
    dataDesc_15[69].td = nullptr;
    dataDesc_15[69].fieldSizeInBytes = 12;
    dataDesc_15[69].override_field = nullptr;
    dataDesc_15[69].override_count = 0;
    dataDesc_15[69].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_15[69].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[69].flatGroup = 0;
    dataDesc_15[70].fieldType = FIELD_CUSTOM;
    dataDesc_15[70].fieldName = "m_ragdoll.list[16].pObject";
    dataDesc_15[70].fieldOffset = 412;
    *(_DWORD *)&dataDesc_15[70].fieldSize = 131073;
    dataDesc_15[70].externalName = nullptr;
    dataDesc_15[70].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[70].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[70].td = 0;
    *(_QWORD *)&dataDesc_15[70].override_field = 0;
    *(_QWORD *)&dataDesc_15[70].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[70].flatOffset[1] = 0;
    dataDesc_15[71].fieldType = FIELD_CUSTOM;
    dataDesc_15[71].fieldName = "m_ragdoll.list[16].pConstraint";
    dataDesc_15[71].fieldOffset = 416;
    *(_DWORD *)&dataDesc_15[71].fieldSize = 131073;
    dataDesc_15[71].externalName = nullptr;
    v14 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[71].td = 0;
    *(_QWORD *)&dataDesc_15[71].override_field = 0;
    *(_QWORD *)&dataDesc_15[71].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[71].flatOffset[1] = 0;
    dataDesc_15[72].fieldTolerance = 0.0;
    dataDesc_15[73].fieldTolerance = 0.0;
    dataDesc_15[71].pSaveRestoreOps = v14;
    dataDesc_15[71].inputFunc = nullptr;
    dataDesc_15[72].fieldType = FIELD_INTEGER;
    dataDesc_15[72].fieldName = "m_ragdoll.list[16].parentIndex";
    dataDesc_15[72].fieldOffset = 420;
    *(_DWORD *)&dataDesc_15[72].fieldSize = 131073;
    dataDesc_15[72].externalName = nullptr;
    dataDesc_15[72].pSaveRestoreOps = nullptr;
    dataDesc_15[72].inputFunc = nullptr;
    dataDesc_15[72].td = nullptr;
    dataDesc_15[72].fieldSizeInBytes = 4;
    dataDesc_15[72].override_field = nullptr;
    dataDesc_15[72].override_count = 0;
    *(_QWORD *)dataDesc_15[72].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[72].flatGroup = 0;
    dataDesc_15[73].fieldType = FIELD_VECTOR;
    dataDesc_15[73].fieldName = "m_ragdoll.list[17].originParentSpace";
    dataDesc_15[73].fieldOffset = 424;
    *(_DWORD *)&dataDesc_15[73].fieldSize = 131073;
    dataDesc_15[73].externalName = nullptr;
    dataDesc_15[73].pSaveRestoreOps = nullptr;
    dataDesc_15[73].inputFunc = nullptr;
    dataDesc_15[73].td = nullptr;
    dataDesc_15[73].fieldSizeInBytes = 12;
    dataDesc_15[73].override_field = nullptr;
    dataDesc_15[73].override_count = 0;
    *(_QWORD *)dataDesc_15[73].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[73].flatGroup = 0;
    dataDesc_15[74].fieldType = FIELD_CUSTOM;
    dataDesc_15[74].fieldName = "m_ragdoll.list[17].pObject";
    dataDesc_15[74].fieldOffset = 436;
    *(_DWORD *)&dataDesc_15[74].fieldSize = 131073;
    dataDesc_15[74].externalName = nullptr;
    dataDesc_15[74].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[74].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[74].td = 0;
    *(_QWORD *)&dataDesc_15[74].override_field = 0;
    *(_QWORD *)&dataDesc_15[74].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[74].flatOffset[1] = 0;
    dataDesc_15[75].fieldType = FIELD_CUSTOM;
    dataDesc_15[75].fieldName = "m_ragdoll.list[17].pConstraint";
    dataDesc_15[75].fieldOffset = 440;
    *(_DWORD *)&dataDesc_15[75].fieldSize = 131073;
    dataDesc_15[75].externalName = nullptr;
    v15 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[75].td = 0;
    *(_QWORD *)&dataDesc_15[75].override_field = 0;
    *(_QWORD *)&dataDesc_15[75].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[75].flatOffset[1] = 0;
    dataDesc_15[76].fieldTolerance = 0.0;
    dataDesc_15[77].fieldTolerance = 0.0;
    dataDesc_15[75].pSaveRestoreOps = v15;
    dataDesc_15[75].inputFunc = nullptr;
    dataDesc_15[76].fieldType = FIELD_INTEGER;
    dataDesc_15[76].fieldName = "m_ragdoll.list[17].parentIndex";
    dataDesc_15[76].fieldOffset = 444;
    *(_DWORD *)&dataDesc_15[76].fieldSize = 131073;
    dataDesc_15[76].externalName = nullptr;
    dataDesc_15[76].pSaveRestoreOps = nullptr;
    dataDesc_15[76].inputFunc = nullptr;
    dataDesc_15[76].td = nullptr;
    dataDesc_15[76].fieldSizeInBytes = 4;
    dataDesc_15[76].override_field = nullptr;
    dataDesc_15[76].override_count = 0;
    *(_QWORD *)dataDesc_15[76].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[76].flatGroup = 0;
    dataDesc_15[77].fieldType = FIELD_VECTOR;
    dataDesc_15[77].fieldName = "m_ragdoll.list[18].originParentSpace";
    dataDesc_15[77].fieldOffset = 448;
    *(_DWORD *)&dataDesc_15[77].fieldSize = 131073;
    dataDesc_15[77].externalName = nullptr;
    dataDesc_15[77].pSaveRestoreOps = nullptr;
    dataDesc_15[77].inputFunc = nullptr;
    dataDesc_15[77].td = nullptr;
    dataDesc_15[77].fieldSizeInBytes = 12;
    dataDesc_15[77].override_field = nullptr;
    dataDesc_15[77].override_count = 0;
    *(_QWORD *)dataDesc_15[77].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[77].flatGroup = 0;
    dataDesc_15[78].fieldType = FIELD_CUSTOM;
    dataDesc_15[78].fieldName = "m_ragdoll.list[18].pObject";
    dataDesc_15[78].fieldOffset = 460;
    *(_DWORD *)&dataDesc_15[78].fieldSize = 131073;
    dataDesc_15[78].externalName = nullptr;
    dataDesc_15[78].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[78].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[78].td = 0;
    *(_QWORD *)&dataDesc_15[78].override_field = 0;
    *(_QWORD *)&dataDesc_15[78].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[78].flatOffset[1] = 0;
    dataDesc_15[79].fieldType = FIELD_CUSTOM;
    dataDesc_15[79].fieldName = "m_ragdoll.list[18].pConstraint";
    dataDesc_15[79].fieldOffset = 464;
    *(_DWORD *)&dataDesc_15[79].fieldSize = 131073;
    dataDesc_15[79].externalName = nullptr;
    v16 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[79].td = 0;
    *(_QWORD *)&dataDesc_15[79].override_field = 0;
    *(_QWORD *)&dataDesc_15[79].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[79].flatOffset[1] = 0;
    dataDesc_15[79].pSaveRestoreOps = v16;
    dataDesc_15[79].inputFunc = nullptr;
    dataDesc_15[80].fieldType = FIELD_INTEGER;
    dataDesc_15[80].fieldName = "m_ragdoll.list[18].parentIndex";
    dataDesc_15[80].fieldOffset = 468;
    *(_DWORD *)&dataDesc_15[80].fieldSize = 131073;
    dataDesc_15[80].externalName = nullptr;
    dataDesc_15[80].pSaveRestoreOps = nullptr;
    dataDesc_15[80].inputFunc = nullptr;
    dataDesc_15[80].td = nullptr;
    dataDesc_15[80].fieldSizeInBytes = 4;
    dataDesc_15[80].override_field = nullptr;
    dataDesc_15[80].override_count = 0;
    dataDesc_15[80].fieldTolerance = 0.0;
    dataDesc_15[81].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_15[80].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[80].flatGroup = 0;
    dataDesc_15[81].fieldType = FIELD_VECTOR;
    dataDesc_15[81].fieldName = "m_ragdoll.list[19].originParentSpace";
    dataDesc_15[81].fieldOffset = 472;
    *(_DWORD *)&dataDesc_15[81].fieldSize = 131073;
    dataDesc_15[81].externalName = nullptr;
    dataDesc_15[81].pSaveRestoreOps = nullptr;
    dataDesc_15[81].inputFunc = nullptr;
    dataDesc_15[81].td = nullptr;
    dataDesc_15[81].fieldSizeInBytes = 12;
    dataDesc_15[81].override_field = nullptr;
    dataDesc_15[81].override_count = 0;
    *(_QWORD *)dataDesc_15[81].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[81].flatGroup = 0;
    dataDesc_15[82].fieldType = FIELD_CUSTOM;
    dataDesc_15[82].fieldName = "m_ragdoll.list[19].pObject";
    dataDesc_15[82].fieldOffset = 484;
    *(_DWORD *)&dataDesc_15[82].fieldSize = 131073;
    dataDesc_15[82].externalName = nullptr;
    dataDesc_15[82].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[82].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[82].td = 0;
    *(_QWORD *)&dataDesc_15[82].override_field = 0;
    *(_QWORD *)&dataDesc_15[82].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[82].flatOffset[1] = 0;
    dataDesc_15[83].fieldType = FIELD_CUSTOM;
    dataDesc_15[83].fieldName = "m_ragdoll.list[19].pConstraint";
    dataDesc_15[83].fieldOffset = 488;
    *(_DWORD *)&dataDesc_15[83].fieldSize = 131073;
    dataDesc_15[83].externalName = nullptr;
    v17 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[83].td = 0;
    *(_QWORD *)&dataDesc_15[83].override_field = 0;
    *(_QWORD *)&dataDesc_15[83].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[83].flatOffset[1] = 0;
    dataDesc_15[84].fieldTolerance = 0.0;
    dataDesc_15[85].fieldTolerance = 0.0;
    dataDesc_15[83].pSaveRestoreOps = v17;
    dataDesc_15[83].inputFunc = nullptr;
    dataDesc_15[84].fieldType = FIELD_INTEGER;
    dataDesc_15[84].fieldName = "m_ragdoll.list[19].parentIndex";
    dataDesc_15[84].fieldOffset = 492;
    *(_DWORD *)&dataDesc_15[84].fieldSize = 131073;
    dataDesc_15[84].externalName = nullptr;
    dataDesc_15[84].pSaveRestoreOps = nullptr;
    dataDesc_15[84].inputFunc = nullptr;
    dataDesc_15[84].td = nullptr;
    dataDesc_15[84].fieldSizeInBytes = 4;
    dataDesc_15[84].override_field = nullptr;
    dataDesc_15[84].override_count = 0;
    *(_QWORD *)dataDesc_15[84].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[84].flatGroup = 0;
    dataDesc_15[85].fieldType = FIELD_VECTOR;
    dataDesc_15[85].fieldName = "m_ragdoll.list[20].originParentSpace";
    dataDesc_15[85].fieldOffset = 496;
    *(_DWORD *)&dataDesc_15[85].fieldSize = 131073;
    dataDesc_15[85].externalName = nullptr;
    dataDesc_15[85].pSaveRestoreOps = nullptr;
    dataDesc_15[85].inputFunc = nullptr;
    dataDesc_15[85].td = nullptr;
    dataDesc_15[85].fieldSizeInBytes = 12;
    dataDesc_15[85].override_field = nullptr;
    dataDesc_15[85].override_count = 0;
    *(_QWORD *)dataDesc_15[85].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[85].flatGroup = 0;
    dataDesc_15[86].fieldType = FIELD_CUSTOM;
    dataDesc_15[86].fieldName = "m_ragdoll.list[20].pObject";
    dataDesc_15[86].fieldOffset = 508;
    *(_DWORD *)&dataDesc_15[86].fieldSize = 131073;
    dataDesc_15[86].externalName = nullptr;
    dataDesc_15[86].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[86].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[86].td = 0;
    *(_QWORD *)&dataDesc_15[86].override_field = 0;
    *(_QWORD *)&dataDesc_15[86].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[86].flatOffset[1] = 0;
    dataDesc_15[87].fieldType = FIELD_CUSTOM;
    dataDesc_15[87].fieldName = "m_ragdoll.list[20].pConstraint";
    dataDesc_15[87].fieldOffset = 512;
    *(_DWORD *)&dataDesc_15[87].fieldSize = 131073;
    dataDesc_15[87].externalName = nullptr;
    v18 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[87].td = 0;
    *(_QWORD *)&dataDesc_15[87].override_field = 0;
    *(_QWORD *)&dataDesc_15[87].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[87].flatOffset[1] = 0;
    dataDesc_15[88].fieldTolerance = 0.0;
    dataDesc_15[89].fieldTolerance = 0.0;
    dataDesc_15[87].pSaveRestoreOps = v18;
    dataDesc_15[87].inputFunc = nullptr;
    dataDesc_15[88].fieldType = FIELD_INTEGER;
    dataDesc_15[88].fieldName = "m_ragdoll.list[20].parentIndex";
    dataDesc_15[88].fieldOffset = 516;
    *(_DWORD *)&dataDesc_15[88].fieldSize = 131073;
    dataDesc_15[88].externalName = nullptr;
    dataDesc_15[88].pSaveRestoreOps = nullptr;
    dataDesc_15[88].inputFunc = nullptr;
    dataDesc_15[88].td = nullptr;
    dataDesc_15[88].fieldSizeInBytes = 4;
    dataDesc_15[88].override_field = nullptr;
    dataDesc_15[88].override_count = 0;
    *(_QWORD *)dataDesc_15[88].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[88].flatGroup = 0;
    dataDesc_15[89].fieldType = FIELD_VECTOR;
    dataDesc_15[89].fieldName = "m_ragdoll.list[21].originParentSpace";
    dataDesc_15[89].fieldOffset = 520;
    *(_DWORD *)&dataDesc_15[89].fieldSize = 131073;
    dataDesc_15[89].externalName = nullptr;
    dataDesc_15[89].pSaveRestoreOps = nullptr;
    dataDesc_15[89].inputFunc = nullptr;
    dataDesc_15[89].td = nullptr;
    dataDesc_15[89].fieldSizeInBytes = 12;
    dataDesc_15[89].override_field = nullptr;
    dataDesc_15[89].override_count = 0;
    *(_QWORD *)dataDesc_15[89].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[89].flatGroup = 0;
    dataDesc_15[90].fieldType = FIELD_CUSTOM;
    dataDesc_15[90].fieldName = "m_ragdoll.list[21].pObject";
    dataDesc_15[90].fieldOffset = 532;
    *(_DWORD *)&dataDesc_15[90].fieldSize = 131073;
    dataDesc_15[90].externalName = nullptr;
    dataDesc_15[90].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[90].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[90].td = 0;
    *(_QWORD *)&dataDesc_15[90].override_field = 0;
    *(_QWORD *)&dataDesc_15[90].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[90].flatOffset[1] = 0;
    dataDesc_15[91].fieldType = FIELD_CUSTOM;
    dataDesc_15[91].fieldName = "m_ragdoll.list[21].pConstraint";
    dataDesc_15[91].fieldOffset = 536;
    *(_DWORD *)&dataDesc_15[91].fieldSize = 131073;
    dataDesc_15[91].externalName = nullptr;
    dataDesc_15[91].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_15[91].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[91].td = 0;
    *(_QWORD *)&dataDesc_15[91].override_field = 0;
    *(_QWORD *)&dataDesc_15[91].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[91].flatOffset[1] = 0;
    dataDesc_15[92].fieldTolerance = 0.0;
    dataDesc_15[93].fieldTolerance = 0.0;
    dataDesc_15[92].fieldType = FIELD_INTEGER;
    dataDesc_15[92].fieldName = "m_ragdoll.list[21].parentIndex";
    dataDesc_15[92].fieldOffset = 540;
    *(_DWORD *)&dataDesc_15[92].fieldSize = 131073;
    dataDesc_15[92].externalName = nullptr;
    dataDesc_15[92].pSaveRestoreOps = nullptr;
    dataDesc_15[92].inputFunc = nullptr;
    dataDesc_15[92].td = nullptr;
    dataDesc_15[92].fieldSizeInBytes = 4;
    dataDesc_15[92].override_field = nullptr;
    dataDesc_15[92].override_count = 0;
    *(_QWORD *)dataDesc_15[92].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[92].flatGroup = 0;
    dataDesc_15[93].fieldType = FIELD_VECTOR;
    dataDesc_15[93].fieldName = "m_ragdoll.list[22].originParentSpace";
    dataDesc_15[93].fieldOffset = 544;
    *(_DWORD *)&dataDesc_15[93].fieldSize = 131073;
    dataDesc_15[93].externalName = nullptr;
    dataDesc_15[93].pSaveRestoreOps = nullptr;
    dataDesc_15[93].inputFunc = nullptr;
    dataDesc_15[93].td = nullptr;
    dataDesc_15[93].fieldSizeInBytes = 12;
    dataDesc_15[93].override_field = nullptr;
    dataDesc_15[93].override_count = 0;
    *(_QWORD *)dataDesc_15[93].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[93].flatGroup = 0;
    dataDesc_15[94].fieldType = FIELD_CUSTOM;
    dataDesc_15[94].fieldName = "m_ragdoll.list[22].pObject";
    dataDesc_15[94].fieldOffset = 556;
    *(_DWORD *)&dataDesc_15[94].fieldSize = 131073;
    dataDesc_15[94].externalName = nullptr;
    dataDesc_15[94].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[94].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[94].td = 0;
    *(_QWORD *)&dataDesc_15[94].override_field = 0;
    *(_QWORD *)&dataDesc_15[94].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[94].flatOffset[1] = 0;
    dataDesc_15[95].fieldType = FIELD_CUSTOM;
    dataDesc_15[95].fieldName = "m_ragdoll.list[22].pConstraint";
    dataDesc_15[95].fieldOffset = 560;
    *(_DWORD *)&dataDesc_15[95].fieldSize = 131073;
    dataDesc_15[95].externalName = nullptr;
    v19 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[95].td = 0;
    *(_QWORD *)&dataDesc_15[95].override_field = 0;
    *(_QWORD *)&dataDesc_15[95].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[95].flatOffset[1] = 0;
    dataDesc_15[95].pSaveRestoreOps = v19;
    dataDesc_15[95].inputFunc = nullptr;
    dataDesc_15[96].fieldType = FIELD_INTEGER;
    dataDesc_15[96].fieldName = "m_ragdoll.list[22].parentIndex";
    dataDesc_15[96].fieldOffset = 564;
    *(_DWORD *)&dataDesc_15[96].fieldSize = 131073;
    dataDesc_15[96].externalName = nullptr;
    dataDesc_15[96].pSaveRestoreOps = nullptr;
    dataDesc_15[96].inputFunc = nullptr;
    dataDesc_15[96].td = nullptr;
    dataDesc_15[96].fieldSizeInBytes = 4;
    dataDesc_15[96].override_field = nullptr;
    dataDesc_15[96].override_count = 0;
    dataDesc_15[96].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_15[96].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[96].flatGroup = 0;
    dataDesc_15[97].fieldType = FIELD_VECTOR;
    dataDesc_15[97].fieldName = "m_ragdoll.list[23].originParentSpace";
    dataDesc_15[97].fieldOffset = 568;
    dataDesc_15[97].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_15[97].fieldSize = 131073;
    dataDesc_15[97].externalName = nullptr;
    dataDesc_15[97].pSaveRestoreOps = nullptr;
    dataDesc_15[97].inputFunc = nullptr;
    dataDesc_15[97].td = nullptr;
    dataDesc_15[97].fieldSizeInBytes = 12;
    dataDesc_15[97].override_field = nullptr;
    dataDesc_15[97].override_count = 0;
    *(_QWORD *)dataDesc_15[97].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[97].flatGroup = 0;
    dataDesc_15[98].fieldType = FIELD_CUSTOM;
    dataDesc_15[98].fieldName = "m_ragdoll.list[23].pObject";
    dataDesc_15[98].fieldOffset = 580;
    *(_DWORD *)&dataDesc_15[98].fieldSize = 131073;
    dataDesc_15[98].externalName = nullptr;
    dataDesc_15[98].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[98].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[98].td = 0;
    *(_QWORD *)&dataDesc_15[98].override_field = 0;
    *(_QWORD *)&dataDesc_15[98].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[98].flatOffset[1] = 0;
    dataDesc_15[99].fieldType = FIELD_CUSTOM;
    dataDesc_15[99].fieldName = "m_ragdoll.list[23].pConstraint";
    dataDesc_15[99].fieldOffset = 584;
    *(_DWORD *)&dataDesc_15[99].fieldSize = 131073;
    dataDesc_15[99].externalName = nullptr;
    v20 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[99].td = 0;
    *(_QWORD *)&dataDesc_15[99].override_field = 0;
    *(_QWORD *)&dataDesc_15[99].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[99].flatOffset[1] = 0;
    dataDesc_15[100].fieldTolerance = 0.0;
    dataDesc_15[101].fieldTolerance = 0.0;
    dataDesc_15[99].pSaveRestoreOps = v20;
    dataDesc_15[99].inputFunc = nullptr;
    dataDesc_15[100].fieldType = FIELD_INTEGER;
    dataDesc_15[100].fieldName = "m_ragdoll.list[23].parentIndex";
    dataDesc_15[100].fieldOffset = 588;
    *(_DWORD *)&dataDesc_15[100].fieldSize = 131073;
    dataDesc_15[100].externalName = nullptr;
    dataDesc_15[100].pSaveRestoreOps = nullptr;
    dataDesc_15[100].inputFunc = nullptr;
    dataDesc_15[100].td = nullptr;
    dataDesc_15[100].fieldSizeInBytes = 4;
    dataDesc_15[100].override_field = nullptr;
    dataDesc_15[100].override_count = 0;
    *(_QWORD *)dataDesc_15[100].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[100].flatGroup = 0;
    dataDesc_15[101].fieldType = FIELD_VECTOR;
    dataDesc_15[101].fieldName = "m_ragdoll.list[24].originParentSpace";
    dataDesc_15[101].fieldOffset = 592;
    *(_DWORD *)&dataDesc_15[101].fieldSize = 131073;
    dataDesc_15[101].externalName = nullptr;
    dataDesc_15[101].pSaveRestoreOps = nullptr;
    dataDesc_15[101].inputFunc = nullptr;
    dataDesc_15[101].td = nullptr;
    dataDesc_15[101].fieldSizeInBytes = 12;
    dataDesc_15[101].override_field = nullptr;
    dataDesc_15[101].override_count = 0;
    *(_QWORD *)dataDesc_15[101].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[101].flatGroup = 0;
    dataDesc_15[102].fieldType = FIELD_CUSTOM;
    dataDesc_15[102].fieldName = "m_ragdoll.list[24].pObject";
    dataDesc_15[102].fieldOffset = 604;
    *(_DWORD *)&dataDesc_15[102].fieldSize = 131073;
    dataDesc_15[102].externalName = nullptr;
    dataDesc_15[102].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[102].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[102].td = 0;
    *(_QWORD *)&dataDesc_15[102].override_field = 0;
    *(_QWORD *)&dataDesc_15[102].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[102].flatOffset[1] = 0;
    dataDesc_15[103].fieldType = FIELD_CUSTOM;
    dataDesc_15[103].fieldName = "m_ragdoll.list[24].pConstraint";
    dataDesc_15[103].fieldOffset = 608;
    *(_DWORD *)&dataDesc_15[103].fieldSize = 131073;
    dataDesc_15[103].externalName = nullptr;
    v21 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[103].td = 0;
    *(_QWORD *)&dataDesc_15[103].override_field = 0;
    *(_QWORD *)&dataDesc_15[103].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[103].flatOffset[1] = 0;
    dataDesc_15[104].fieldTolerance = 0.0;
    dataDesc_15[105].fieldTolerance = 0.0;
    dataDesc_15[103].pSaveRestoreOps = v21;
    dataDesc_15[103].inputFunc = nullptr;
    dataDesc_15[104].fieldType = FIELD_INTEGER;
    dataDesc_15[104].fieldName = "m_ragdoll.list[24].parentIndex";
    dataDesc_15[104].fieldOffset = 612;
    *(_DWORD *)&dataDesc_15[104].fieldSize = 131073;
    dataDesc_15[104].externalName = nullptr;
    dataDesc_15[104].pSaveRestoreOps = nullptr;
    dataDesc_15[104].inputFunc = nullptr;
    dataDesc_15[104].td = nullptr;
    dataDesc_15[104].fieldSizeInBytes = 4;
    dataDesc_15[104].override_field = nullptr;
    dataDesc_15[104].override_count = 0;
    *(_QWORD *)dataDesc_15[104].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[104].flatGroup = 0;
    dataDesc_15[105].fieldType = FIELD_VECTOR;
    dataDesc_15[105].fieldName = "m_ragdoll.list[25].originParentSpace";
    dataDesc_15[105].fieldOffset = 616;
    *(_DWORD *)&dataDesc_15[105].fieldSize = 131073;
    dataDesc_15[105].externalName = nullptr;
    dataDesc_15[105].pSaveRestoreOps = nullptr;
    dataDesc_15[105].inputFunc = nullptr;
    dataDesc_15[105].td = nullptr;
    dataDesc_15[105].fieldSizeInBytes = 12;
    dataDesc_15[105].override_field = nullptr;
    dataDesc_15[105].override_count = 0;
    *(_QWORD *)dataDesc_15[105].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[105].flatGroup = 0;
    dataDesc_15[106].fieldType = FIELD_CUSTOM;
    dataDesc_15[106].fieldName = "m_ragdoll.list[25].pObject";
    dataDesc_15[106].fieldOffset = 628;
    *(_DWORD *)&dataDesc_15[106].fieldSize = 131073;
    dataDesc_15[106].externalName = nullptr;
    dataDesc_15[106].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[106].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[106].td = 0;
    *(_QWORD *)&dataDesc_15[106].override_field = 0;
    *(_QWORD *)&dataDesc_15[106].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[106].flatOffset[1] = 0;
    dataDesc_15[107].fieldType = FIELD_CUSTOM;
    dataDesc_15[107].fieldName = "m_ragdoll.list[25].pConstraint";
    dataDesc_15[107].fieldOffset = 632;
    *(_DWORD *)&dataDesc_15[107].fieldSize = 131073;
    dataDesc_15[107].externalName = nullptr;
    dataDesc_15[107].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_15[107].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[107].td = 0;
    *(_QWORD *)&dataDesc_15[107].override_field = 0;
    *(_QWORD *)&dataDesc_15[107].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[107].flatOffset[1] = 0;
    dataDesc_15[108].fieldType = FIELD_INTEGER;
    dataDesc_15[108].fieldName = "m_ragdoll.list[25].parentIndex";
    dataDesc_15[108].fieldOffset = 636;
    dataDesc_15[108].fieldTolerance = 0.0;
    dataDesc_15[109].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_15[108].fieldSize = 131073;
    dataDesc_15[108].externalName = nullptr;
    dataDesc_15[108].pSaveRestoreOps = nullptr;
    dataDesc_15[108].inputFunc = nullptr;
    dataDesc_15[108].td = nullptr;
    dataDesc_15[108].fieldSizeInBytes = 4;
    dataDesc_15[108].override_field = nullptr;
    dataDesc_15[108].override_count = 0;
    *(_QWORD *)dataDesc_15[108].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[108].flatGroup = 0;
    dataDesc_15[109].fieldType = FIELD_VECTOR;
    dataDesc_15[109].fieldName = "m_ragdoll.list[26].originParentSpace";
    dataDesc_15[109].fieldOffset = 640;
    *(_DWORD *)&dataDesc_15[109].fieldSize = 131073;
    dataDesc_15[109].externalName = nullptr;
    dataDesc_15[109].pSaveRestoreOps = nullptr;
    dataDesc_15[109].inputFunc = nullptr;
    dataDesc_15[109].td = nullptr;
    dataDesc_15[109].fieldSizeInBytes = 12;
    dataDesc_15[109].override_field = nullptr;
    dataDesc_15[109].override_count = 0;
    *(_QWORD *)dataDesc_15[109].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[109].flatGroup = 0;
    dataDesc_15[110].fieldType = FIELD_CUSTOM;
    dataDesc_15[110].fieldName = "m_ragdoll.list[26].pObject";
    dataDesc_15[110].fieldOffset = 652;
    *(_DWORD *)&dataDesc_15[110].fieldSize = 131073;
    dataDesc_15[110].externalName = nullptr;
    dataDesc_15[110].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[110].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[110].td = 0;
    *(_QWORD *)&dataDesc_15[110].override_field = 0;
    *(_QWORD *)&dataDesc_15[110].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[110].flatOffset[1] = 0;
    dataDesc_15[111].fieldType = FIELD_CUSTOM;
    dataDesc_15[111].fieldName = "m_ragdoll.list[26].pConstraint";
    dataDesc_15[111].fieldOffset = 656;
    *(_DWORD *)&dataDesc_15[111].fieldSize = 131073;
    dataDesc_15[111].externalName = nullptr;
    v22 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[111].td = 0;
    *(_QWORD *)&dataDesc_15[111].override_field = 0;
    *(_QWORD *)&dataDesc_15[111].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[111].flatOffset[1] = 0;
    dataDesc_15[111].pSaveRestoreOps = v22;
    dataDesc_15[111].inputFunc = nullptr;
    dataDesc_15[112].fieldType = FIELD_INTEGER;
    dataDesc_15[112].fieldName = "m_ragdoll.list[26].parentIndex";
    dataDesc_15[112].fieldOffset = 660;
    *(_DWORD *)&dataDesc_15[112].fieldSize = 131073;
    dataDesc_15[112].externalName = nullptr;
    dataDesc_15[112].pSaveRestoreOps = nullptr;
    dataDesc_15[112].inputFunc = nullptr;
    dataDesc_15[112].td = nullptr;
    dataDesc_15[112].fieldSizeInBytes = 4;
    dataDesc_15[112].override_field = nullptr;
    dataDesc_15[112].override_count = 0;
    dataDesc_15[112].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_15[112].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[112].flatGroup = 0;
    dataDesc_15[113].fieldType = FIELD_VECTOR;
    dataDesc_15[113].fieldName = "m_ragdoll.list[27].originParentSpace";
    dataDesc_15[113].fieldOffset = 664;
    *(_DWORD *)&dataDesc_15[113].fieldSize = 131073;
    dataDesc_15[113].externalName = nullptr;
    dataDesc_15[113].pSaveRestoreOps = nullptr;
    dataDesc_15[113].inputFunc = nullptr;
    dataDesc_15[113].td = nullptr;
    dataDesc_15[113].fieldSizeInBytes = 12;
    dataDesc_15[113].fieldTolerance = 0.0;
    dataDesc_15[113].override_field = nullptr;
    dataDesc_15[113].override_count = 0;
    *(_QWORD *)dataDesc_15[113].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[113].flatGroup = 0;
    dataDesc_15[114].fieldType = FIELD_CUSTOM;
    dataDesc_15[114].fieldName = "m_ragdoll.list[27].pObject";
    dataDesc_15[114].fieldOffset = 676;
    *(_DWORD *)&dataDesc_15[114].fieldSize = 131073;
    dataDesc_15[114].externalName = nullptr;
    dataDesc_15[114].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[114].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[114].td = 0;
    *(_QWORD *)&dataDesc_15[114].override_field = 0;
    *(_QWORD *)&dataDesc_15[114].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[114].flatOffset[1] = 0;
    dataDesc_15[115].fieldType = FIELD_CUSTOM;
    dataDesc_15[115].fieldName = "m_ragdoll.list[27].pConstraint";
    dataDesc_15[115].fieldOffset = 680;
    *(_DWORD *)&dataDesc_15[115].fieldSize = 131073;
    dataDesc_15[115].externalName = nullptr;
    v23 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[115].td = 0;
    *(_QWORD *)&dataDesc_15[115].override_field = 0;
    *(_QWORD *)&dataDesc_15[115].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[115].flatOffset[1] = 0;
    dataDesc_15[116].fieldTolerance = 0.0;
    dataDesc_15[117].fieldTolerance = 0.0;
    dataDesc_15[115].pSaveRestoreOps = v23;
    dataDesc_15[115].inputFunc = nullptr;
    dataDesc_15[116].fieldType = FIELD_INTEGER;
    dataDesc_15[116].fieldName = "m_ragdoll.list[27].parentIndex";
    dataDesc_15[116].fieldOffset = 684;
    *(_DWORD *)&dataDesc_15[116].fieldSize = 131073;
    dataDesc_15[116].externalName = nullptr;
    dataDesc_15[116].pSaveRestoreOps = nullptr;
    dataDesc_15[116].inputFunc = nullptr;
    dataDesc_15[116].td = nullptr;
    dataDesc_15[116].fieldSizeInBytes = 4;
    dataDesc_15[116].override_field = nullptr;
    dataDesc_15[116].override_count = 0;
    *(_QWORD *)dataDesc_15[116].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[116].flatGroup = 0;
    dataDesc_15[117].fieldType = FIELD_VECTOR;
    dataDesc_15[117].fieldName = "m_ragdoll.list[28].originParentSpace";
    dataDesc_15[117].fieldOffset = 688;
    *(_DWORD *)&dataDesc_15[117].fieldSize = 131073;
    dataDesc_15[117].externalName = nullptr;
    dataDesc_15[117].pSaveRestoreOps = nullptr;
    dataDesc_15[117].inputFunc = nullptr;
    dataDesc_15[117].td = nullptr;
    dataDesc_15[117].fieldSizeInBytes = 12;
    dataDesc_15[117].override_field = nullptr;
    dataDesc_15[117].override_count = 0;
    *(_QWORD *)dataDesc_15[117].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[117].flatGroup = 0;
    dataDesc_15[118].fieldType = FIELD_CUSTOM;
    dataDesc_15[118].fieldName = "m_ragdoll.list[28].pObject";
    dataDesc_15[118].fieldOffset = 700;
    *(_DWORD *)&dataDesc_15[118].fieldSize = 131073;
    dataDesc_15[118].externalName = nullptr;
    dataDesc_15[118].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[118].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[118].td = 0;
    *(_QWORD *)&dataDesc_15[118].override_field = 0;
    *(_QWORD *)&dataDesc_15[118].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[118].flatOffset[1] = 0;
    dataDesc_15[119].fieldType = FIELD_CUSTOM;
    dataDesc_15[119].fieldName = "m_ragdoll.list[28].pConstraint";
    dataDesc_15[119].fieldOffset = 704;
    *(_DWORD *)&dataDesc_15[119].fieldSize = 131073;
    dataDesc_15[119].externalName = nullptr;
    v24 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[119].td = 0;
    *(_QWORD *)&dataDesc_15[119].override_field = 0;
    *(_QWORD *)&dataDesc_15[119].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[119].flatOffset[1] = 0;
    dataDesc_15[120].fieldTolerance = 0.0;
    dataDesc_15[121].fieldTolerance = 0.0;
    dataDesc_15[119].pSaveRestoreOps = v24;
    dataDesc_15[119].inputFunc = nullptr;
    dataDesc_15[120].fieldType = FIELD_INTEGER;
    dataDesc_15[120].fieldName = "m_ragdoll.list[28].parentIndex";
    dataDesc_15[120].fieldOffset = 708;
    *(_DWORD *)&dataDesc_15[120].fieldSize = 131073;
    dataDesc_15[120].externalName = nullptr;
    dataDesc_15[120].pSaveRestoreOps = nullptr;
    dataDesc_15[120].inputFunc = nullptr;
    dataDesc_15[120].td = nullptr;
    dataDesc_15[120].fieldSizeInBytes = 4;
    dataDesc_15[120].override_field = nullptr;
    dataDesc_15[120].override_count = 0;
    *(_QWORD *)dataDesc_15[120].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[120].flatGroup = 0;
    dataDesc_15[121].fieldType = FIELD_VECTOR;
    dataDesc_15[121].fieldName = "m_ragdoll.list[29].originParentSpace";
    dataDesc_15[121].fieldOffset = 712;
    *(_DWORD *)&dataDesc_15[121].fieldSize = 131073;
    dataDesc_15[121].externalName = nullptr;
    dataDesc_15[121].pSaveRestoreOps = nullptr;
    dataDesc_15[121].inputFunc = nullptr;
    dataDesc_15[121].td = nullptr;
    dataDesc_15[121].fieldSizeInBytes = 12;
    dataDesc_15[121].override_field = nullptr;
    dataDesc_15[121].override_count = 0;
    *(_QWORD *)dataDesc_15[121].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[121].flatGroup = 0;
    dataDesc_15[122].fieldType = FIELD_CUSTOM;
    dataDesc_15[122].fieldName = "m_ragdoll.list[29].pObject";
    dataDesc_15[122].fieldOffset = 724;
    *(_DWORD *)&dataDesc_15[122].fieldSize = 131073;
    dataDesc_15[122].externalName = nullptr;
    dataDesc_15[122].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[122].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[122].td = 0;
    *(_QWORD *)&dataDesc_15[122].override_field = 0;
    *(_QWORD *)&dataDesc_15[122].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[122].flatOffset[1] = 0;
    dataDesc_15[123].fieldType = FIELD_CUSTOM;
    dataDesc_15[123].fieldName = "m_ragdoll.list[29].pConstraint";
    dataDesc_15[123].fieldOffset = 728;
    *(_DWORD *)&dataDesc_15[123].fieldSize = 131073;
    dataDesc_15[123].externalName = nullptr;
    dataDesc_15[123].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_15[123].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[123].td = 0;
    *(_QWORD *)&dataDesc_15[123].override_field = 0;
    *(_QWORD *)&dataDesc_15[123].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[123].flatOffset[1] = 0;
    dataDesc_15[124].fieldType = FIELD_INTEGER;
    dataDesc_15[124].fieldName = "m_ragdoll.list[29].parentIndex";
    dataDesc_15[124].fieldOffset = 732;
    *(_DWORD *)&dataDesc_15[124].fieldSize = 131073;
    dataDesc_15[124].externalName = nullptr;
    dataDesc_15[124].pSaveRestoreOps = nullptr;
    dataDesc_15[124].inputFunc = nullptr;
    dataDesc_15[124].td = nullptr;
    dataDesc_15[124].fieldSizeInBytes = 4;
    dataDesc_15[124].override_field = nullptr;
    dataDesc_15[124].fieldTolerance = 0.0;
    dataDesc_15[125].fieldTolerance = 0.0;
    dataDesc_15[124].override_count = 0;
    *(_QWORD *)dataDesc_15[124].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[124].flatGroup = 0;
    dataDesc_15[125].fieldType = FIELD_VECTOR;
    dataDesc_15[125].fieldName = "m_ragdoll.list[30].originParentSpace";
    dataDesc_15[125].fieldOffset = 736;
    *(_DWORD *)&dataDesc_15[125].fieldSize = 131073;
    dataDesc_15[125].externalName = nullptr;
    dataDesc_15[125].pSaveRestoreOps = nullptr;
    dataDesc_15[125].inputFunc = nullptr;
    dataDesc_15[125].td = nullptr;
    dataDesc_15[125].fieldSizeInBytes = 12;
    dataDesc_15[125].override_field = nullptr;
    dataDesc_15[125].override_count = 0;
    *(_QWORD *)dataDesc_15[125].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[125].flatGroup = 0;
    dataDesc_15[126].fieldType = FIELD_CUSTOM;
    dataDesc_15[126].fieldName = "m_ragdoll.list[30].pObject";
    dataDesc_15[126].fieldOffset = 748;
    *(_DWORD *)&dataDesc_15[126].fieldSize = 131073;
    dataDesc_15[126].externalName = nullptr;
    dataDesc_15[126].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[126].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[126].td = 0;
    *(_QWORD *)&dataDesc_15[126].override_field = 0;
    *(_QWORD *)&dataDesc_15[126].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[126].flatOffset[1] = 0;
    dataDesc_15[127].fieldType = FIELD_CUSTOM;
    dataDesc_15[127].fieldName = "m_ragdoll.list[30].pConstraint";
    dataDesc_15[127].fieldOffset = 752;
    *(_DWORD *)&dataDesc_15[127].fieldSize = 131073;
    dataDesc_15[127].externalName = nullptr;
    v25 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[127].td = 0;
    *(_QWORD *)&dataDesc_15[127].override_field = 0;
    *(_QWORD *)&dataDesc_15[127].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[127].flatOffset[1] = 0;
    dataDesc_15[128].fieldTolerance = 0.0;
    dataDesc_15[129].fieldTolerance = 0.0;
    dataDesc_15[127].pSaveRestoreOps = v25;
    dataDesc_15[127].inputFunc = nullptr;
    dataDesc_15[128].fieldType = FIELD_INTEGER;
    dataDesc_15[128].fieldName = "m_ragdoll.list[30].parentIndex";
    dataDesc_15[128].fieldOffset = 756;
    *(_DWORD *)&dataDesc_15[128].fieldSize = 131073;
    dataDesc_15[128].externalName = nullptr;
    dataDesc_15[128].pSaveRestoreOps = nullptr;
    dataDesc_15[128].inputFunc = nullptr;
    dataDesc_15[128].td = nullptr;
    dataDesc_15[128].fieldSizeInBytes = 4;
    dataDesc_15[128].override_field = nullptr;
    dataDesc_15[128].override_count = 0;
    *(_QWORD *)dataDesc_15[128].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[128].flatGroup = 0;
    dataDesc_15[129].fieldType = FIELD_VECTOR;
    dataDesc_15[129].fieldName = "m_ragdoll.list[31].originParentSpace";
    dataDesc_15[129].fieldOffset = 760;
    *(_DWORD *)&dataDesc_15[129].fieldSize = 131073;
    dataDesc_15[129].externalName = nullptr;
    dataDesc_15[129].pSaveRestoreOps = nullptr;
    dataDesc_15[129].inputFunc = nullptr;
    dataDesc_15[129].td = nullptr;
    dataDesc_15[129].fieldSizeInBytes = 12;
    dataDesc_15[129].override_field = nullptr;
    dataDesc_15[129].override_count = 0;
    *(_QWORD *)dataDesc_15[129].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[129].flatGroup = 0;
    dataDesc_15[130].fieldType = FIELD_CUSTOM;
    dataDesc_15[130].fieldName = "m_ragdoll.list[31].pObject";
    dataDesc_15[130].fieldOffset = 772;
    *(_DWORD *)&dataDesc_15[130].fieldSize = 131073;
    dataDesc_15[130].externalName = nullptr;
    dataDesc_15[130].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_15[130].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_15[130].td = 0;
    *(_QWORD *)&dataDesc_15[130].override_field = 0;
    *(_QWORD *)&dataDesc_15[130].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[130].flatOffset[1] = 0;
    dataDesc_15[131].fieldType = FIELD_CUSTOM;
    dataDesc_15[131].fieldName = "m_ragdoll.list[31].pConstraint";
    dataDesc_15[131].fieldOffset = 776;
    *(_DWORD *)&dataDesc_15[131].fieldSize = 131073;
    dataDesc_15[131].externalName = nullptr;
    v26 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_15[131].td = 0;
    *(_QWORD *)&dataDesc_15[131].override_field = 0;
    *(_QWORD *)&dataDesc_15[131].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[131].flatOffset[1] = 0;
    dataDesc_15[132].fieldTolerance = 0.0;
    dataDesc_15[132].fieldType = FIELD_INTEGER;
    dataDesc_15[131].pSaveRestoreOps = v26;
    dataDesc_15[131].inputFunc = nullptr;
    dataDesc_15[132].fieldName = "m_ragdoll.list[31].parentIndex";
    dataDesc_15[132].fieldOffset = 780;
    *(_DWORD *)&dataDesc_15[132].fieldSize = 131073;
    dataDesc_15[132].externalName = nullptr;
    dataDesc_15[132].pSaveRestoreOps = nullptr;
    dataDesc_15[132].inputFunc = nullptr;
    dataDesc_15[132].td = nullptr;
    dataDesc_15[132].fieldSizeInBytes = 4;
    dataDesc_15[132].override_field = nullptr;
    dataDesc_15[132].override_count = 0;
    *(_QWORD *)dataDesc_15[132].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[132].flatGroup = 0;
  }
  CRagdoll::m_DataMap.dataNumFields = 132;
  CRagdoll::m_DataMap.dataDesc = &dataDesc_15[1];
  return &CRagdoll::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101616C0
// Name: _C_ServerRagdoll_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_ServerRagdoll_CreateObject(int entnum, int serialNum)
{
  C_ServerRagdoll *v2; // eax
  C_ServerRagdoll *v3; // eax
  C_ServerRagdoll *v4; // esi

  v2 = (C_ServerRagdoll *)C_BaseEntity::operator new(stAllocateBlock: 0x10A8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_ServerRagdoll::C_ServerRagdoll(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1041BEA0
// Name: _dynamic_initializer_for__cl_ragdoll_self_collision__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ragdoll_self_collision__()
{
  ConVar::ConVar(this: &cl_ragdoll_self_collision, pName: "cl_ragdoll_self_collision", pDefaultValue: "1", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__cl_ragdoll_self_collision__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BF00
// Name: _dynamic_initializer_for____g_C_ServerRagdollClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_ServerRagdollClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_ServerRagdollClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_ServerRagdollClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041BF50
// Name: _dynamic_initializer_for____g_C_ServerRagdollAttachedClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_ServerRagdollAttachedClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_ServerRagdollAttachedClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_ServerRagdollAttachedClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041BFA0
// Name: _dynamic_initializer_for__gRagdolls__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gRagdolls__()
{
  return atexit(func: dynamic_atexit_destructor_for__gRagdolls__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BFB0
// Name: _dynamic_initializer_for__g_ragdoll_maxcount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ragdoll_maxcount__()
{
  ConVar::ConVar(this: &g_ragdoll_maxcount, pName: "g_ragdoll_maxcount", pDefaultValue: "8", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_ragdoll_maxcount__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BFE0
// Name: _dynamic_initializer_for__g_debug_ragdoll_removal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_ragdoll_removal__()
{
  ConVar::ConVar(this: &g_debug_ragdoll_removal, pName: "g_debug_ragdoll_removal", pDefaultValue: "0", flags: 24576);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_ragdoll_removal__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C010
// Name: _dynamic_initializer_for__s_RagdollLRU__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_RagdollLRU__()
{
  CRagdollLRURetirement::CRagdollLRURetirement(this: &s_RagdollLRU, name: "CRagdollLRURetirement");
  return atexit(func: dynamic_atexit_destructor_for__s_RagdollLRU__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C030
// Name: _dynamic_initializer_for__g_ragdoll_important_maxcount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ragdoll_important_maxcount__()
{
  ConVar::ConVar(
    this: &g_ragdoll_important_maxcount,
    pName: "g_ragdoll_important_maxcount",
    pDefaultValue: "2",
    flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_ragdoll_important_maxcount__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C060
// Name: _dynamic_initializer_for__s_pStereoParamTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pStereoParamTexture__()
{
  CTextureReference::CTextureReference(this: &s_pStereoParamTexture);
  return atexit(func: dynamic_atexit_destructor_for__s_pStereoParamTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C080
// Name: _dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture__()
{
  CTextureReference::CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture);
  return atexit(func: dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C0A0
// Name: _dynamic_initializer_for__s_pFullscreenTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pFullscreenTexture__()
{
  CTextureReference::CTextureReference(this: &s_pFullscreenTexture);
  return atexit(func: dynamic_atexit_destructor_for__s_pFullscreenTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C0C0
// Name: _dynamic_initializer_for__s_pCameraTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pCameraTexture__()
{
  CTextureReference::CTextureReference(this: &s_pCameraTexture);
  return atexit(func: dynamic_atexit_destructor_for__s_pCameraTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C0E0
// Name: _dynamic_initializer_for__s_pFullFrameDepthTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pFullFrameDepthTexture__()
{
  CTextureReference::CTextureReference(this: &s_pFullFrameDepthTexture);
  return atexit(func: dynamic_atexit_destructor_for__s_pFullFrameDepthTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C100
// Name: _dynamic_initializer_for__s_pFullFrameFrameBufferTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pFullFrameFrameBufferTexture__()
{
  CTextureReference *v0; // esi
  int i; // edi

  v0 = s_pFullFrameFrameBufferTexture;
  for ( i = 3; i >= 0; --i )
    CTextureReference::CTextureReference(this: v0++);
  return atexit(func: dynamic_atexit_destructor_for__s_pFullFrameFrameBufferTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C130
// Name: _dynamic_initializer_for__s_pWaterReflectionTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pWaterReflectionTexture__()
{
  CTextureReference::CTextureReference(this: &s_pWaterReflectionTexture);
  return atexit(func: dynamic_atexit_destructor_for__s_pWaterReflectionTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C150
// Name: _dynamic_initializer_for__s_pWaterRefractionTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pWaterRefractionTexture__()
{
  CTextureReference::CTextureReference(this: &s_pWaterRefractionTexture);
  return atexit(func: dynamic_atexit_destructor_for__s_pWaterRefractionTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C170
// Name: _dynamic_initializer_for__s_pSmallBufferHDR0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pSmallBufferHDR0__()
{
  CTextureReference::CTextureReference(this: &s_pSmallBufferHDR0);
  return atexit(func: dynamic_atexit_destructor_for__s_pSmallBufferHDR0__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C190
// Name: _dynamic_initializer_for__s_pSmallBufferHDR1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pSmallBufferHDR1__()
{
  CTextureReference::CTextureReference(this: &s_pSmallBufferHDR1);
  return atexit(func: dynamic_atexit_destructor_for__s_pSmallBufferHDR1__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C1B0
// Name: _dynamic_initializer_for__s_pQuarterSizedFB0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pQuarterSizedFB0__()
{
  CTextureReference::CTextureReference(this: &s_pQuarterSizedFB0);
  return atexit(func: dynamic_atexit_destructor_for__s_pQuarterSizedFB0__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C1D0
// Name: _dynamic_initializer_for__s_pQuarterSizedFB1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pQuarterSizedFB1__()
{
  CTextureReference::CTextureReference(this: &s_pQuarterSizedFB1);
  return atexit(func: dynamic_atexit_destructor_for__s_pQuarterSizedFB1__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C1F0
// Name: _dynamic_initializer_for__s_TeenyTextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_TeenyTextures__()
{
  CTextureReference *v0; // esi
  int i; // edi

  v0 = s_TeenyTextures;
  for ( i = 2; i >= 0; --i )
    CTextureReference::CTextureReference(this: v0++);
  return atexit(func: dynamic_atexit_destructor_for__s_TeenyTextures__);
}

//------------------------------------------------------------------------------
// Address: 0x104337B0
// Name: _DataMapInit_CRagdoll__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRagdoll__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_16);
}

//------------------------------------------------------------------------------
// Address: 0x104337C0
// Name: _dynamic_atexit_destructor_for__gRagdolls__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gRagdolls__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&gRagdolls);
}

//------------------------------------------------------------------------------
// Address: 0x104337D0
// Name: _dynamic_atexit_destructor_for__g_ragdoll_maxcount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ragdoll_maxcount__()
{
  ConVar::~ConVar(this: &g_ragdoll_maxcount);
}

//------------------------------------------------------------------------------
// Address: 0x104337E0
// Name: _dynamic_atexit_destructor_for__g_debug_ragdoll_removal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_ragdoll_removal__()
{
  ConVar::~ConVar(this: &g_debug_ragdoll_removal);
}

//------------------------------------------------------------------------------
// Address: 0x104337F0
// Name: _dynamic_atexit_destructor_for__g_ragdoll_important_maxcount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ragdoll_important_maxcount__()
{
  ConVar::~ConVar(this: &g_ragdoll_important_maxcount);
}

//------------------------------------------------------------------------------
// Address: 0x10433800
// Name: _dynamic_atexit_destructor_for__s_RagdollLRU__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_RagdollLRU__()
{
  CRagdollLRURetirement::~CRagdollLRURetirement(this: &s_RagdollLRU);
}

//------------------------------------------------------------------------------
// Address: 0x10433810
// Name: _dynamic_atexit_destructor_for__s_pStereoParamTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pStereoParamTexture__()
{
  CTextureReference::~CTextureReference(this: &s_pStereoParamTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10433820
// Name: _dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__()
{
  CTextureReference::~CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10433830
// Name: _dynamic_atexit_destructor_for__s_pFullscreenTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pFullscreenTexture__()
{
  CTextureReference::~CTextureReference(this: &s_pFullscreenTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10433840
// Name: _dynamic_atexit_destructor_for__s_pCameraTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pCameraTexture__()
{
  CTextureReference::~CTextureReference(this: &s_pCameraTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10433850
// Name: _dynamic_atexit_destructor_for__s_pFullFrameDepthTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pFullFrameDepthTexture__()
{
  CTextureReference::~CTextureReference(this: &s_pFullFrameDepthTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10433860
// Name: _dynamic_atexit_destructor_for__s_pWaterReflectionTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pWaterReflectionTexture__()
{
  CTextureReference::~CTextureReference(this: &s_pWaterReflectionTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10433870
// Name: _dynamic_atexit_destructor_for__s_pWaterRefractionTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pWaterRefractionTexture__()
{
  CTextureReference::~CTextureReference(this: &s_pWaterRefractionTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10433880
// Name: _dynamic_atexit_destructor_for__s_pSmallBufferHDR0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pSmallBufferHDR0__()
{
  CTextureReference::~CTextureReference(this: &s_pSmallBufferHDR0);
}

//------------------------------------------------------------------------------
// Address: 0x10433890
// Name: _dynamic_atexit_destructor_for__s_pSmallBufferHDR1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pSmallBufferHDR1__()
{
  CTextureReference::~CTextureReference(this: &s_pSmallBufferHDR1);
}

//------------------------------------------------------------------------------
// Address: 0x104338A0
// Name: _dynamic_atexit_destructor_for__s_pQuarterSizedFB0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pQuarterSizedFB0__()
{
  CTextureReference::~CTextureReference(this: &s_pQuarterSizedFB0);
}

//------------------------------------------------------------------------------
// Address: 0x104338B0
// Name: _dynamic_atexit_destructor_for__s_pQuarterSizedFB1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pQuarterSizedFB1__()
{
  CTextureReference::~CTextureReference(this: &s_pQuarterSizedFB1);
}

//------------------------------------------------------------------------------
// Address: 0x104338C0
// Name: _dynamic_atexit_destructor_for__s_TeenyTextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_TeenyTextures__()
{
  CTextureReference *v0; // esi
  int i; // edi

  v0 = (CTextureReference *)&vec2_origin_13;
  for ( i = 2; i >= 0; --i )
    CTextureReference::~CTextureReference(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x104338E0
// Name: _dynamic_atexit_destructor_for__s_pFullFrameFrameBufferTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pFullFrameFrameBufferTexture__()
{
  CTextureReference *v0; // esi
  int i; // edi

  v0 = &s_pSmallBufferHDR0;
  for ( i = 3; i >= 0; --i )
    CTextureReference::~CTextureReference(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10433900
// Name: _DataMapInit_entitytable_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_entitytable_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_17);
}

//------------------------------------------------------------------------------
// Address: 0x10433910
// Name: _DataMapInit_SaveRestoreBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SaveRestoreBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_18);
}

//------------------------------------------------------------------------------
// Address: 0x10433920
// Name: _dynamic_atexit_destructor_for__g_SaveRestoreBlockSet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SaveRestoreBlockSet__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_SaveRestoreBlockSet.m_BlockHeaders);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_SaveRestoreBlockSet.m_Handlers);
}
