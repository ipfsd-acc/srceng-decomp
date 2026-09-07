// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/hardwarematrixstate.cpp
// Functions: 8
// ============================================================

#include "utils\studiomdl\hardwarematrixstate.h"

//------------------------------------------------------------------------------
// Address: 0x00416230
// Name: public: CHardwareMatrixState::CHardwareMatrixState(void)
// Source: json
//------------------------------------------------------------------------------
CHardwareMatrixState *__thiscall CHardwareMatrixState::CHardwareMatrixState(CHardwareMatrixState *this)
{
  this->m_LRUCounter = 0;
  this->m_NumMatrices = 0;
  this->m_matrixState = nullptr;
  this->m_savedMatrixState = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00416240
// Name: public: void CHardwareMatrixState::Init(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareMatrixState::Init(CHardwareMatrixState *this, int numHardwareMatrices)
{
  int v3; // eax
  int v4; // ecx
  CHardwareMatrixState::MatrixState_t *m_matrixState; // [esp-4h] [ebp-8h]

  m_matrixState = this->m_matrixState;
  this->m_NumMatrices = numHardwareMatrices;
  free(pMem: m_matrixState);
  this->m_matrixState = (CHardwareMatrixState::MatrixState_t *)MemAlloc_Alloc(
                                                                 nSize: (12
                                                                * (unsigned __int64)(unsigned int)this->m_NumMatrices) >> 32 != 0
                                                               ? -1
                                                               : 12 * this->m_NumMatrices);
  free(pMem: this->m_savedMatrixState);
  this->m_savedMatrixState = (CHardwareMatrixState::MatrixState_t *)MemAlloc_Alloc(
                                                                      nSize: (12
                                                                     * (unsigned __int64)(unsigned int)this->m_NumMatrices) >> 32 != 0
                                                                    ? -1
                                                                    : 12 * this->m_NumMatrices);
  v3 = 0;
  this->m_LRUCounter = 0;
  this->m_AllocatedMatrices = 0;
  if ( this->m_NumMatrices > 0 )
  {
    v4 = 0;
    do
    {
      this->m_matrixState[v4].allocated = false;
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_NumMatrices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004162D0
// Name: public: bool CHardwareMatrixState::IsMatrixAllocated(int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHardwareMatrixState::IsMatrixAllocated(CHardwareMatrixState *this, int globalMatrixID)
{
  int m_NumMatrices; // esi
  int v3; // edx
  CHardwareMatrixState::MatrixState_t *i; // eax

  m_NumMatrices = this->m_NumMatrices;
  v3 = 0;
  if ( m_NumMatrices <= 0 )
    return 0;
  for ( i = this->m_matrixState; i->globalMatrixID != globalMatrixID || !i->allocated; ++i )
  {
    if ( ++v3 >= m_NumMatrices )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00416310
// Name: public: int CHardwareMatrixState::AllocatedMatrixCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareMatrixState::AllocatedMatrixCount(CHardwareMatrixState *this)
{
  return this->m_AllocatedMatrices;
}

//------------------------------------------------------------------------------
// Address: 0x00416320
// Name: public: int CHardwareMatrixState::FreeMatrixCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareMatrixState::FreeMatrixCount(CHardwareMatrixState *this)
{
  return this->m_NumMatrices - this->m_AllocatedMatrices;
}

//------------------------------------------------------------------------------
// Address: 0x00416330
// Name: public: int CHardwareMatrixState::GetNthBoneGlobalID(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareMatrixState::GetNthBoneGlobalID(CHardwareMatrixState *this, int n)
{
  int m_NumMatrices; // esi
  int v3; // edi
  int v4; // eax
  CHardwareMatrixState::MatrixState_t *m_matrixState; // ecx
  CHardwareMatrixState::MatrixState_t *v6; // edx

  m_NumMatrices = this->m_NumMatrices;
  v3 = 0;
  v4 = 0;
  if ( m_NumMatrices <= 0 )
LABEL_7:
    MdlError(fmt: "GetNthBoneGlobalID() Failure\n");
  m_matrixState = this->m_matrixState;
  v6 = m_matrixState;
  while ( !v6->allocated )
  {
LABEL_6:
    ++v4;
    ++v6;
    if ( v4 >= m_NumMatrices )
      goto LABEL_7;
  }
  if ( n != v3 )
  {
    ++v3;
    goto LABEL_6;
  }
  return m_matrixState[v4].globalMatrixID;
}

//------------------------------------------------------------------------------
// Address: 0x00416390
// Name: public: bool CHardwareMatrixState::AllocateMatrix(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHardwareMatrixState::AllocateMatrix(CHardwareMatrixState *this, int globalMatrixID)
{
  int m_NumMatrices; // esi
  int v3; // eax
  CHardwareMatrixState::MatrixState_t *m_matrixState; // edx
  int v5; // eax
  CHardwareMatrixState::MatrixState_t *i; // edx
  int v8; // eax

  m_NumMatrices = this->m_NumMatrices;
  v3 = 0;
  if ( m_NumMatrices <= 0 )
  {
LABEL_6:
    v5 = 0;
    if ( m_NumMatrices <= 0 )
      return 0;
    for ( i = this->m_matrixState; i->allocated; ++i )
    {
      if ( ++v5 >= this->m_NumMatrices )
        return 0;
    }
    v8 = v5;
    this->m_matrixState[v8].globalMatrixID = globalMatrixID;
    this->m_matrixState[v8].allocated = true;
    this->m_matrixState[v8].lastUsageID = this->m_LRUCounter++;
    ++this->m_AllocatedMatrices;
  }
  else
  {
    m_matrixState = this->m_matrixState;
    while ( m_matrixState->globalMatrixID != globalMatrixID || !m_matrixState->allocated )
    {
      ++v3;
      ++m_matrixState;
      if ( v3 >= m_NumMatrices )
        goto LABEL_6;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00416400
// Name: public: void CHardwareMatrixState::DeallocateAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareMatrixState::DeallocateAll(CHardwareMatrixState *this)
{
  int v1; // edx
  int v2; // eax

  v1 = 0;
  if ( this->m_NumMatrices <= 0 )
  {
    this->m_AllocatedMatrices = 0;
  }
  else
  {
    v2 = 0;
    do
    {
      this->m_matrixState[v2].allocated = false;
      this->m_matrixState[v2].globalMatrixID = 0x7FFFFFFF;
      this->m_matrixState[v2].lastUsageID = 0x7FFFFFFF;
      ++v1;
      ++v2;
    }
    while ( v1 < this->m_NumMatrices );
    this->m_AllocatedMatrices = 0;
  }
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0040EEB0
// Name: public: CHardwareMatrixState::CHardwareMatrixState(void)
// Source: json
//------------------------------------------------------------------------------
CHardwareMatrixState *__thiscall CHardwareMatrixState::CHardwareMatrixState(CHardwareMatrixState *this)
{
  this->m_LRUCounter = 0;
  this->m_NumMatrices = 0;
  this->m_matrixState = nullptr;
  this->m_savedMatrixState = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040EEC0
// Name: public: void CHardwareMatrixState::Init(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareMatrixState::Init(CHardwareMatrixState *this, int numHardwareMatrices)
{
  int v3; // eax
  int v4; // ecx
  CHardwareMatrixState::MatrixState_t *m_matrixState; // [esp-4h] [ebp-8h]

  m_matrixState = this->m_matrixState;
  this->m_NumMatrices = numHardwareMatrices;
  free(pMem: m_matrixState);
  this->m_matrixState = (CHardwareMatrixState::MatrixState_t *)MemAlloc_Alloc(
                                                                 nSize: (12
                                                                * (unsigned __int64)(unsigned int)this->m_NumMatrices) >> 32 != 0
                                                               ? -1
                                                               : 12 * this->m_NumMatrices);
  free(pMem: this->m_savedMatrixState);
  this->m_savedMatrixState = (CHardwareMatrixState::MatrixState_t *)MemAlloc_Alloc(
                                                                      nSize: (12
                                                                     * (unsigned __int64)(unsigned int)this->m_NumMatrices) >> 32 != 0
                                                                    ? -1
                                                                    : 12 * this->m_NumMatrices);
  v3 = 0;
  this->m_LRUCounter = 0;
  this->m_AllocatedMatrices = 0;
  if ( this->m_NumMatrices > 0 )
  {
    v4 = 0;
    do
    {
      this->m_matrixState[v4].allocated = false;
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_NumMatrices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EF50
// Name: public: bool CHardwareMatrixState::IsMatrixAllocated(int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHardwareMatrixState::IsMatrixAllocated(CHardwareMatrixState *this, int globalMatrixID)
{
  int m_NumMatrices; // esi
  int v3; // edx
  CHardwareMatrixState::MatrixState_t *i; // eax

  m_NumMatrices = this->m_NumMatrices;
  v3 = 0;
  if ( m_NumMatrices <= 0 )
    return 0;
  for ( i = this->m_matrixState; i->globalMatrixID != globalMatrixID || !i->allocated; ++i )
  {
    if ( ++v3 >= m_NumMatrices )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040EF90
// Name: public: int CHardwareMatrixState::AllocatedMatrixCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareMatrixState::AllocatedMatrixCount(CHardwareMatrixState *this)
{
  return this->m_AllocatedMatrices;
}

//------------------------------------------------------------------------------
// Address: 0x0040EFA0
// Name: public: int CHardwareMatrixState::FreeMatrixCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareMatrixState::FreeMatrixCount(CHardwareMatrixState *this)
{
  return this->m_NumMatrices - this->m_AllocatedMatrices;
}

//------------------------------------------------------------------------------
// Address: 0x0040EFB0
// Name: public: int CHardwareMatrixState::GetNthBoneGlobalID(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareMatrixState::GetNthBoneGlobalID(CHardwareMatrixState *this, int n)
{
  int m_NumMatrices; // esi
  int v3; // edi
  int v4; // eax
  CHardwareMatrixState::MatrixState_t *m_matrixState; // ecx
  CHardwareMatrixState::MatrixState_t *v6; // edx

  m_NumMatrices = this->m_NumMatrices;
  v3 = 0;
  v4 = 0;
  if ( m_NumMatrices <= 0 )
LABEL_7:
    MdlError(fmt: "GetNthBoneGlobalID() Failure\n");
  m_matrixState = this->m_matrixState;
  v6 = m_matrixState;
  while ( !v6->allocated )
  {
LABEL_6:
    ++v4;
    ++v6;
    if ( v4 >= m_NumMatrices )
      goto LABEL_7;
  }
  if ( n != v3 )
  {
    ++v3;
    goto LABEL_6;
  }
  return m_matrixState[v4].globalMatrixID;
}

//------------------------------------------------------------------------------
// Address: 0x0040F010
// Name: public: bool CHardwareMatrixState::AllocateMatrix(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHardwareMatrixState::AllocateMatrix(CHardwareMatrixState *this, int globalMatrixID)
{
  int m_NumMatrices; // esi
  int v3; // eax
  CHardwareMatrixState::MatrixState_t *m_matrixState; // edx
  int v5; // eax
  CHardwareMatrixState::MatrixState_t *i; // edx
  int v8; // eax

  m_NumMatrices = this->m_NumMatrices;
  v3 = 0;
  if ( m_NumMatrices <= 0 )
  {
LABEL_6:
    v5 = 0;
    if ( m_NumMatrices <= 0 )
      return 0;
    for ( i = this->m_matrixState; i->allocated; ++i )
    {
      if ( ++v5 >= this->m_NumMatrices )
        return 0;
    }
    v8 = v5;
    this->m_matrixState[v8].globalMatrixID = globalMatrixID;
    this->m_matrixState[v8].allocated = true;
    this->m_matrixState[v8].lastUsageID = this->m_LRUCounter++;
    ++this->m_AllocatedMatrices;
  }
  else
  {
    m_matrixState = this->m_matrixState;
    while ( m_matrixState->globalMatrixID != globalMatrixID || !m_matrixState->allocated )
    {
      ++v3;
      ++m_matrixState;
      if ( v3 >= m_NumMatrices )
        goto LABEL_6;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040F080
// Name: public: void CHardwareMatrixState::DeallocateAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareMatrixState::DeallocateAll(CHardwareMatrixState *this)
{
  int v1; // edx
  int v2; // eax

  v1 = 0;
  if ( this->m_NumMatrices <= 0 )
  {
    this->m_AllocatedMatrices = 0;
  }
  else
  {
    v2 = 0;
    do
    {
      this->m_matrixState[v2].allocated = false;
      this->m_matrixState[v2].globalMatrixID = 0x7FFFFFFF;
      this->m_matrixState[v2].lastUsageID = 0x7FFFFFFF;
      ++v1;
      ++v2;
    }
    while ( v1 < this->m_NumMatrices );
    this->m_AllocatedMatrices = 0;
  }
}

} // namespace studiomdl
