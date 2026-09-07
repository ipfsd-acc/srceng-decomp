// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxresourcehandle.cpp
// Functions: 5
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxresourcehandle.h"

//------------------------------------------------------------------------------
// Address: 0x100DB0B0
// Name: public: GFxResourceBinding::GFxResourceBinding(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceBinding::GFxResourceBinding(CExpressionEvaluator *this, ExprNode *pheap)
{
  this->m_ExprTree = pheap;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_CurPosition, spinCount: 0);
  this->m_pExpression = nullptr;
  *(_DWORD *)&this->m_CurToken = 0;
  this->m_Identifier[20] = 0;
  *(_DWORD *)&this->m_Identifier[24] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100DB0E0
// Name: public: void GFxResourceBinding::GetResourceData_Locked(struct GFxResourceBindData __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceBinding::GetResourceData_Locked(
        GFxResourceBinding *this,
        IShaderDevice **a2,
        unsigned int a3)
{
  const char *m_pExpression; // edx
  IShaderDevice *v5; // ecx
  IShaderDevice **v6; // esi
  char v7; // bl
  IShaderDevice *v8; // ecx
  IShaderDevice *v9; // eax
  IShaderDevice **v10; // esi
  IShaderDevice *v11; // edx
  IShaderDevice *v12[2]; // [esp+Ch] [ebp-14h] BYREF
  IShaderDevice *v13[2]; // [esp+14h] [ebp-Ch] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+1Ch] [ebp-4h]

  lpCriticalSection = (LPCRITICAL_SECTION)&this->m_CurPosition;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_CurPosition);
  if ( a3 >= *(_DWORD *)&this->m_CurToken )
  {
    v7 = 2;
    v13[0] = nullptr;
    v13[1] = nullptr;
    v10 = v13;
  }
  else
  {
    m_pExpression = this->m_pExpression;
    v5 = *(IShaderDevice **)&m_pExpression[8 * a3];
    v6 = (IShaderDevice **)&m_pExpression[8 * a3];
    v7 = 1;
    if ( v5 != nullptr )
      GRefCountImpl::AddRef(this: v5);
    v8 = *v6;
    v9 = v6[1];
    v12[0] = v8;
    v12[1] = v9;
    v10 = v12;
    if ( v8 != nullptr )
      GRefCountImpl::AddRef(this: v8);
  }
  if ( *a2 != nullptr )
    GFxResource::Release(this: *a2);
  v11 = v10[1];
  *a2 = *v10;
  a2[1] = v11;
  if ( (v7 & 2) != 0 )
  {
    v7 &= ~2u;
    if ( v13[0] != nullptr )
      GFxResource::Release(this: v13[0]);
  }
  if ( (v7 & 1) != 0 && v12[0] != nullptr )
    GFxResource::Release(this: v12[0]);
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x100DB1A0
// Name: public: void GFxResourceBinding::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
ExprNode *__thiscall GFxResourceBinding::Destroy(CExpressionEvaluator *this)
{
  ExprNode *result; // eax
  IShaderDevice **m_pExpression; // esi
  int v4; // ebx

  result = (ExprNode *)this->m_pExpression;
  if ( result != nullptr )
  {
    m_pExpression = (IShaderDevice **)this->m_pExpression;
    if ( *(_DWORD *)&this->m_CurToken != 0 )
    {
      v4 = *(_DWORD *)&this->m_CurToken;
      do
      {
        if ( *m_pExpression != nullptr )
          GFxResource::Release(this: *m_pExpression);
        m_pExpression += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    result = (ExprNode *)((int (__thiscall *)(GMemoryHeap *, const char *))GMemory::pGlobalHeap->Free)(
                           a1: GMemory::pGlobalHeap,
                           a2: this->m_pExpression);
    this->m_pExpression = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DB1F0
// Name: public: void GFxResourceBinding::SetBindData(unsigned int,struct GFxResourceBindData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceBinding::SetBindData(GFxResourceBinding *this, unsigned int a2, IShaderDevice **a3)
{
  int *p_m_CurPosition; // ebx
  unsigned int v5; // esi
  ExprNode *m_ExprTree; // ecx
  const char *v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  unsigned int v10; // ebx
  _DWORD *v11; // ecx
  unsigned int v12; // edx
  int v13; // ecx
  const char *m_pExpression; // esi
  int v15; // ebx
  IShaderDevice *v16; // ecx
  IShaderDevice *v17; // ecx
  unsigned int v18; // edx
  IShaderDevice **v19; // ebx
  char *v20; // esi
  int *v21; // [esp+Ch] [ebp-18h]
  unsigned int v22; // [esp+10h] [ebp-14h]
  int v23; // [esp+14h] [ebp-10h] BYREF
  int v24; // [esp+18h] [ebp-Ch] BYREF
  unsigned int v25; // [esp+1Ch] [ebp-8h]
  const char *v26; // [esp+20h] [ebp-4h]

  p_m_CurPosition = &this->m_CurPosition;
  v21 = &this->m_CurPosition;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_CurPosition);
  v5 = (a2 + 16) & 0xFFFFFFF0;
  v22 = v5;
  if ( v5 > *(_DWORD *)&this->m_CurToken )
  {
    m_ExprTree = this->m_ExprTree;
    if ( this->m_pExpression != nullptr )
    {
      v23 = 265;
      v9 = ((int (__thiscall *)(ExprNode *, unsigned int, int *))m_ExprTree->left[2].kind)(
             a1: m_ExprTree,
             a2: 8 * v5,
             a3: &v23);
      v10 = 0;
      v26 = (const char *)v9;
      v11 = (_DWORD *)v9;
      if ( v5 != 0 )
      {
        v12 = (a2 + 16) & 0xFFFFFFF0;
        do
        {
          if ( v11 != nullptr )
          {
            *v11 = 0;
            v11[1] = 0;
          }
          v11 += 2;
          --v12;
        }
        while ( v12 != 0 );
      }
      v13 = *(_DWORD *)&this->m_CurToken;
      v25 = 0;
      if ( v13 != 0 )
      {
        do
        {
          m_pExpression = this->m_pExpression;
          v15 = 8 * v10;
          v16 = *(IShaderDevice **)&m_pExpression[v15];
          if ( v16 != nullptr )
          {
            GRefCountImpl::AddRef(this: v16);
            v9 = (int)v26;
          }
          v17 = *(IShaderDevice **)(v15 + v9);
          if ( v17 != nullptr )
          {
            GFxResource::Release(this: v17);
            v9 = (int)v26;
          }
          *(_DWORD *)(v15 + v9) = *(_DWORD *)&m_pExpression[v15];
          *(_DWORD *)(v15 + v9 + 4) = *(_DWORD *)&m_pExpression[v15 + 4];
          v18 = *(_DWORD *)&this->m_CurToken;
          v10 = v25 + 1;
          v25 = v10;
        }
        while ( v10 < v18 );
        v5 = v22;
      }
      v19 = (IShaderDevice **)this->m_pExpression;
      if ( *(_DWORD *)&this->m_CurToken != 0 )
      {
        v25 = *(_DWORD *)&this->m_CurToken;
        do
        {
          if ( *v19 != nullptr )
            GFxResource::Release(this: *v19);
          v19 += 2;
          --v25;
        }
        while ( v25 != 0 );
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)this->m_pExpression);
      p_m_CurPosition = v21;
      this->m_pExpression = v26;
    }
    else
    {
      v24 = 265;
      this->m_pExpression = (const char *)((int (__thiscall *)(ExprNode *, unsigned int, int *))m_ExprTree->left[2].kind)(
                                            a1: m_ExprTree,
                                            a2: 8 * v5,
                                            a3: &v24);
      v7 = this->m_pExpression;
      if ( v5 != 0 )
      {
        v8 = (a2 + 16) & 0xFFFFFFF0;
        do
        {
          if ( v7 != nullptr )
          {
            *(_DWORD *)v7 = 0;
            *((_DWORD *)v7 + 1) = 0;
          }
          v7 += 8;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
    *(_DWORD *)&this->m_CurToken = v5;
  }
  v20 = (char *)&this->m_pExpression[8 * a2];
  if ( *a3 != nullptr )
    GRefCountImpl::AddRef(this: *a3);
  if ( *(_DWORD *)v20 != 0 )
    GFxResource::Release(this: *(IShaderDevice **)v20);
  *(_DWORD *)v20 = *a3;
  *((_DWORD *)v20 + 1) = a3[1];
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_CurPosition);
}

//------------------------------------------------------------------------------
// Address: 0x100DB370
// Name: public: GFxResourceBinding::~GFxResourceBinding(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceBinding::~GFxResourceBinding(CExpressionEvaluator *this)
{
  GFxResourceBinding::Destroy(this);
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_CurPosition);
}
