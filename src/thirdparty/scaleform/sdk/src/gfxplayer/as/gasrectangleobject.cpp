// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasrectangleobject.cpp
// Functions: 31
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasrectangleobject.h"

//------------------------------------------------------------------------------
// Address: 0x101282D0
// Name: public: virtual enum GASObjectInterface::ObjectType GASRectangleObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASRectangleObject::GetObjectType()
{
  return 17;
}

//------------------------------------------------------------------------------
// Address: 0x10128360
// Name: GFxObject_GetRectangleProperties
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode *__usercall GFxObject_GetRectangleProperties@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int v3; // esi
  int v5; // edi
  int v6; // eax
  bool v7; // zf
  int v8; // eax
  int v9; // eax
  struct GASStringNode *result; // eax
  struct GASStringNode *ConstStringNode; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3 + 120;
  v5 = a2 + 16;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)(a3 + 120) + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nGrowSize,
                      a3: 1u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, int, struct GASStringNode **, int))(*(_DWORD *)v5 + 44))(
    a1: v5,
    a2: v3,
    a3: &ConstStringNode,
    a4: a1);
  v6 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v6);
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)v3 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nAllocationCount,
                      a3: 1u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, int, struct GASStringNode **, int))(*(_DWORD *)v5 + 44))(
    a1: v5,
    a2: v3,
    a3: &ConstStringNode,
    a4: a1 + 16);
  v8 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v8);
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)v3 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_pElements,
                      a3: 5u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, int, struct GASStringNode **, int))(*(_DWORD *)v5 + 44))(
    a1: v5,
    a2: v3,
    a3: &ConstStringNode,
    a4: a1 + 32);
  v9 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v9);
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)v3 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_Memory.m_nGrowSize,
                      a3: 6u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, int, struct GASStringNode **, int))(*(_DWORD *)v5 + 44))(
    a1: v5,
    a2: v3,
    a3: &ConstStringNode,
    a4: a1 + 48);
  result = ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    return (struct GASStringNode *)GASStringNode::ReleaseNode(a1: (int)result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10128470
// Name: public: void GASRectangleObject::GetProperties(class GASStringContext __near *,class GASValue __near * const)
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode *__userpurge GASRectangleObject::GetProperties@<eax>(
        int a1@<ecx>,
        struct GASStringNode *psc,
        int params,
        const char *psc_8,
        int psc_12)
{
  struct GASStringNode *v5; // edi
  int v6; // esi
  struct GASStringNode *ConstStringNode; // eax
  int v8; // ebx
  int v9; // eax
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  struct GASStringNode *result; // eax

  v5 = psc;
  v6 = a1 + 16;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)psc + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nGrowSize,
                      a3: 1u,
                      a4: 0);
  v8 = params;
  psc = ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, struct GASStringNode *, struct GASStringNode **, int))(*(_DWORD *)v6 + 44))(
    a1: v6,
    a2: v5,
    a3: &psc,
    a4: v8);
  v9 = (int)psc;
  v10 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v9);
  psc = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(*(_DWORD *)v5 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nAllocationCount,
          a3: 1u,
          a4: 0);
  ++*((_DWORD *)psc + 2);
  (*(void (__thiscall **)(int, struct GASStringNode *, struct GASStringNode **, int))(*(_DWORD *)v6 + 44))(
    a1: v6,
    a2: v5,
    a3: &psc,
    a4: v8 + 16);
  v11 = (int)psc;
  v10 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v11);
  psc = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(*(_DWORD *)v5 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_pElements,
          a3: 5u,
          a4: 0);
  ++*((_DWORD *)psc + 2);
  (*(void (__thiscall **)(int, struct GASStringNode *, struct GASStringNode **, int))(*(_DWORD *)v6 + 44))(
    a1: v6,
    a2: v5,
    a3: &psc,
    a4: v8 + 32);
  v12 = (int)psc;
  v10 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v12);
  psc = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(*(_DWORD *)v5 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_Memory.m_nGrowSize,
          a3: 6u,
          a4: 0);
  ++*((_DWORD *)psc + 2);
  (*(void (__thiscall **)(int, struct GASStringNode *, struct GASStringNode **, int))(*(_DWORD *)v6 + 44))(
    a1: v6,
    a2: v5,
    a3: &psc,
    a4: v8 + 48);
  result = psc;
  v10 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v10 )
    return (struct GASStringNode *)GASStringNode::ReleaseNode(a1: (int)result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10128580
// Name: public: void GASRectangleObject::GetProperties(class GASEnvironment __near *,class GRect<double> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASRectangleObject::GetProperties(
        int a1@<ecx>,
        long double a2@<st0>,
        _SERVICE_STATUS *penv,
        GMemoryHeap *r,
        int params,
        const char *a6,
        int a7)
{
  int v7; // edi
  unsigned int dwControlsAccepted; // ecx
  char *p_dwControlsAccepted; // esi
  int v10; // eax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  int v14; // eax
  double v15; // st7
  double v16; // st6
  GASValue *v17; // esi
  int v18; // edi
  double v19; // [esp+Ch] [ebp-60h]
  double v20; // [esp+14h] [ebp-58h]
  double v21; // [esp+20h] [ebp-4Ch] BYREF
  GASValue v22[4]; // [esp+28h] [ebp-44h] BYREF
  GASValue v23[4]; // [esp+38h] [ebp-34h] BYREF
  GASValue v24[4]; // [esp+48h] [ebp-24h] BYREF
  GASValue v25[4]; // [esp+58h] [ebp-14h] BYREF
  int v26; // [esp+68h] [ebp-4h] BYREF

  v7 = a1 + 16;
  dwControlsAccepted = penv[4].dwControlsAccepted;
  p_dwControlsAccepted = (char *)&penv[4].dwControlsAccepted;
  LOBYTE(v22[0]) = 0;
  LOBYTE(v23[0]) = 0;
  LOBYTE(v24[0]) = 0;
  LOBYTE(v25[0]) = 0;
  HIDWORD(v21) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(dwControlsAccepted + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nGrowSize,
                   a3: 1u,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v21) + 8);
  (*(void (__thiscall **)(int, unsigned int *, char *, GASValue *))(*(_DWORD *)v7 + 44))(
    a1: v7,
    a2: &penv[4].dwControlsAccepted,
    a3: (char *)&v21 + 4,
    a4: v22);
  v10 = HIDWORD(v21);
  v11 = (*(_DWORD *)(HIDWORD(v21) + 8))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v10);
  HIDWORD(v21) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)p_dwControlsAccepted + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nAllocationCount,
                   a3: 1u,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v21) + 8);
  (*(void (__thiscall **)(int, char *, char *, GASValue *))(*(_DWORD *)v7 + 44))(
    a1: v7,
    a2: p_dwControlsAccepted,
    a3: (char *)&v21 + 4,
    a4: v23);
  v12 = HIDWORD(v21);
  v11 = (*(_DWORD *)(HIDWORD(v21) + 8))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v12);
  HIDWORD(v21) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)p_dwControlsAccepted + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_pElements,
                   a3: 5u,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v21) + 8);
  (*(void (__thiscall **)(int, char *, char *, GASValue *))(*(_DWORD *)v7 + 44))(
    a1: v7,
    a2: p_dwControlsAccepted,
    a3: (char *)&v21 + 4,
    a4: v24);
  v13 = HIDWORD(v21);
  v11 = (*(_DWORD *)(HIDWORD(v21) + 8))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v13);
  HIDWORD(v21) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)p_dwControlsAccepted + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_Memory.m_nGrowSize,
                   a3: 6u,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v21) + 8);
  (*(void (__thiscall **)(int, char *, char *, GASValue *))(*(_DWORD *)v7 + 44))(
    a1: v7,
    a2: p_dwControlsAccepted,
    a3: (char *)&v21 + 4,
    a4: v25);
  v14 = HIDWORD(v21);
  v11 = (*(_DWORD *)(HIDWORD(v21) + 8))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v14);
  v19 = GASValue::ToNumber(this: v24, a2: v7, a3: a2, result: penv);
  v20 = GASValue::ToNumber(this: v25, a2: v7, a3: v19, result: penv);
  v21 = GASValue::ToNumber(this: v22, a2: v7, a3: v20, result: penv);
  v15 = GASValue::ToNumber(this: v23, a2: v7, a3: v21, result: penv);
  v16 = v21;
  *(double *)&r->__vftable = v21;
  v17 = (GASValue *)&v26;
  v18 = 3;
  *(double *)&r->pNext = v15;
  *(double *)&r->RefCount = v16 + v19;
  *(double *)&r->pAutoRelease = v15 + v20;
  do
  {
    v17 -= 4;
    GASValue::~GASValue(this: v17, a2: v18--);
  }
  while ( v18 >= 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10128720
// Name: public: void GASRectangleObject::SetProperties(class GASStringContext __near *,class GASValue const __near * const)
// Source: json
//------------------------------------------------------------------------------
GMemoryHeap *__thiscall GASRectangleObject::SetProperties(
        char *this,
        const UtlRBTreeNode_t<char const *,unsigned short> *psc,
        GMemoryHeap *a3)
{
  const UtlRBTreeNode_t<char const *,unsigned short> *v3; // edi
  int v4; // eax
  char *v5; // esi
  struct GASStringNode *ConstStringNode; // eax
  GMemoryHeap *v7; // ebx
  int v8; // eax
  bool v9; // zf
  int v10; // eax
  GMemoryHeap *v11; // eax
  int v12; // eax
  GMemoryHeap *v13; // eax
  int v14; // eax
  GMemoryHeap *result; // eax
  char v16; // [esp+Fh] [ebp-1h] BYREF

  v3 = psc;
  v4 = *(_DWORD *)psc;
  v5 = this + 16;
  v16 = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(v4 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nGrowSize,
                      a3: 1u,
                      a4: 0);
  v7 = a3;
  psc = ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, const UtlRBTreeNode_t<char const *,unsigned short> *, const UtlRBTreeNode_t<char const *,unsigned short> **, GMemoryHeap *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &psc,
    a4: v7,
    a5: &v16);
  v8 = (int)psc;
  v9 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v8);
  v10 = *(_DWORD *)v3;
  HIBYTE(psc) = 0;
  a3 = (GMemoryHeap *)GASStringManager::CreateConstStringNode(
                        this: *(GASStringManager **)(v10 + 636),
                        result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nAllocationCount,
                        a3: 1u,
                        a4: 0);
  ++a3->pNext;
  (*(void (__thiscall **)(char *, const UtlRBTreeNode_t<char const *,unsigned short> *, GMemoryHeap **, volatile unsigned int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    &a3,
    a4: &v7->RefCount,
    a5: (char *)&psc + 3);
  v11 = a3;
  v9 = a3->pNext-- == (GMemoryHeap *)1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v11);
  v12 = *(_DWORD *)v3;
  HIBYTE(psc) = 0;
  a3 = (GMemoryHeap *)GASStringManager::CreateConstStringNode(
                        this: *(GASStringManager **)(v12 + 636),
                        result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_pElements,
                        a3: 5u,
                        a4: 0);
  ++a3->pNext;
  (*(void (__thiscall **)(char *, const UtlRBTreeNode_t<char const *,unsigned short> *, GMemoryHeap **, unsigned int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    &a3,
    a4: &v7->Info.Desc.MinAlign,
    a5: (char *)&psc + 3);
  v13 = a3;
  v9 = a3->pNext-- == (GMemoryHeap *)1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v13);
  v14 = *(_DWORD *)v3;
  HIBYTE(psc) = 0;
  a3 = (GMemoryHeap *)GASStringManager::CreateConstStringNode(
                        this: *(GASStringManager **)(v14 + 636),
                        result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_Memory.m_nGrowSize,
                        a3: 6u,
                        a4: 0);
  ++a3->pNext;
  (*(void (__thiscall **)(char *, const UtlRBTreeNode_t<char const *,unsigned short> *, GMemoryHeap **, unsigned int *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    &a3,
    a4: &v7->Info.Desc.Limit,
    a5: (char *)&psc + 3);
  result = a3;
  v9 = a3->pNext-- == (GMemoryHeap *)1;
  if ( v9 )
    return (GMemoryHeap *)GASStringNode::ReleaseNode(a1: (int)result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10128850
// Name: public: void GASRectangleObject::SetProperties(class GASEnvironment __near *,class GRect<double> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASRectangleObject::SetProperties(
        int a1@<ecx>,
        int a2@<edi>,
        unsigned int penv,
        GMemoryHeap *r,
        int a5)
{
  double *v5; // ebx
  int v6; // eax
  int *v7; // esi
  int v8; // edi
  GMemoryHeap *v9; // eax
  bool v10; // zf
  int v11; // eax
  GMemoryHeap *v12; // eax
  int v13; // eax
  GMemoryHeap *v14; // eax
  int v15; // eax
  GMemoryHeap *v16; // eax
  GASValue v18; // [esp+8h] [ebp-10h] BYREF
  double v19; // [esp+Ch] [ebp-Ch]

  v5 = (double *)r;
  v19 = *(double *)&r->__vftable;
  v6 = *(_DWORD *)(penv + 120);
  v7 = (int *)(penv + 120);
  LOBYTE(v18) = 3;
  v8 = a1 + 16;
  HIBYTE(penv) = 0;
  r = (GMemoryHeap *)GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(v6 + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nGrowSize,
                       a3: 1u,
                       a4: 0);
  ++r->pNext;
  (*(void (__thiscall **)(int, int *, GMemoryHeap **, GASValue *, char *, int))(*(_DWORD *)v8 + 40))(
    a1: v8,
    a2: v7,
    a3: &r,
    a4: &v18,
    a5: (char *)&penv + 3,
    a6: a2);
  v9 = r;
  v10 = r->pNext-- == (GMemoryHeap *)1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v9);
  GASValue::~GASValue(this: &v18, a2: v8);
  v11 = *v7;
  v19 = v5[1];
  LOBYTE(v18) = 3;
  HIBYTE(penv) = 0;
  r = (GMemoryHeap *)GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(v11 + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nAllocationCount,
                       a3: 1u,
                       a4: 0);
  ++r->pNext;
  (*(void (__thiscall **)(int, int *, GMemoryHeap **, GASValue *, char *))(*(_DWORD *)v8 + 40))(
    a1: v8,
    a2: v7,
    a3: &r,
    a4: &v18,
    a5: (char *)&penv + 3);
  v12 = r;
  v10 = r->pNext-- == (GMemoryHeap *)1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v12);
  GASValue::~GASValue(this: &v18, a2: v8);
  v13 = *v7;
  v19 = v5[2] - *v5;
  LOBYTE(v18) = 3;
  HIBYTE(penv) = 0;
  r = (GMemoryHeap *)GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(v13 + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_pElements,
                       a3: 5u,
                       a4: 0);
  ++r->pNext;
  (*(void (__thiscall **)(int, int *, GMemoryHeap **, GASValue *, char *))(*(_DWORD *)v8 + 40))(
    a1: v8,
    a2: v7,
    a3: &r,
    a4: &v18,
    a5: (char *)&penv + 3);
  v14 = r;
  v10 = r->pNext-- == (GMemoryHeap *)1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v14);
  GASValue::~GASValue(this: &v18, a2: v8);
  v15 = *v7;
  v19 = v5[3] - v5[1];
  LOBYTE(v18) = 3;
  HIBYTE(penv) = 0;
  r = (GMemoryHeap *)GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(v15 + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_Memory.m_nGrowSize,
                       a3: 6u,
                       a4: 0);
  ++r->pNext;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v8 + 40))(a1: v8, a2: v7);
  v16 = r;
  v10 = r->pNext-- == (GMemoryHeap *)1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v16);
  GASValue::~GASValue(this: &v18, a2: (int)&r);
}

//------------------------------------------------------------------------------
// Address: 0x101289D0
// Name: public: static void GASRectangleProto::Contains(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::Contains(int a1@<edi>, GASFnCall *a2)
{
  char v2; // bl
  tagWNDCLASSW *v3; // eax
  tagWNDCLASSW *v4; // eax
  GASFnCall v5; // eax
  int p_cxItem; // ecx
  _SERVICE_STATUS *v7; // edx
  long double v8; // st7
  double v9; // st7
  double v10; // st6
  double v11; // st4
  GASFnCall v12; // esi
  GASFnCall v13; // esi
  int v14; // [esp+0h] [ebp-50h]
  const char *v15; // [esp+4h] [ebp-4Ch]
  double v16; // [esp+8h] [ebp-48h] BYREF
  double v17; // [esp+10h] [ebp-40h]
  double v18; // [esp+18h] [ebp-38h]
  double v19; // [esp+20h] [ebp-30h]
  GASValue v20[4]; // [esp+28h] [ebp-28h] BYREF
  GASValue v21[4]; // [esp+38h] [ebp-18h] BYREF
  double v22; // [esp+48h] [ebp-8h]

  v2 = 1;
  if ( (int)a2[7] <= 1 )
  {
    v13 = a2[1];
    GASValue::DropRefs(this: (GASValue *)v13, a2: a1);
    LOBYTE(v13->cbSize) = 2;
    LOBYTE(v13->cItems) = 0;
  }
  else
  {
    v3 = (tagWNDCLASSW *)GASFnCall::Arg(this: a2, a2: 0);
    GASValue::GASValue(this: v20, v: v3);
    v4 = (tagWNDCLASSW *)GASFnCall::Arg(this: a2, a2: 1);
    GASValue::GASValue(this: v21, v: v4);
    if ( GASFnCall::CheckThisPtr(this: a2, type: 0x11u) )
    {
      v5 = a2[2];
      if ( v5 != nullptr )
        p_cxItem = (int)&v5[-1].cxItem;
      else
        p_cxItem = 0;
      v7 = (_SERVICE_STATUS *)a2[6];
      v16 = 0.0;
      v17 = 0.0;
      v18 = 0.0;
      v19 = 0.0;
      GASRectangleObject::GetProperties(
        a1: p_cxItem,
        a2: 0.0,
        penv: v7,
        r: (GMemoryHeap *)&v16,
        params: v14,
        a6: v15,
        a7: COERCE_UNSIGNED_INT64(0.0));
      v22 = GASValue::ToNumber(this: v20, a2: a1, a3: v8, result: (_SERVICE_STATUS *)a2[6]);
      v9 = GASValue::ToNumber(this: v21, a2: a1, a3: v22, result: (_SERVICE_STATUS *)a2[6]);
      v10 = v22;
      if ( v18 == v22 )
        v10 = v22 + 1.0;
      if ( v19 == v9 )
      {
        v11 = v19;
        v9 = v9 + 1.0;
      }
      else
      {
        v11 = v19;
      }
      if ( v18 < v10 || v16 > v10 || v11 < v9 || v9 < v17 )
        v2 = 0;
      v12 = a2[1];
      GASValue::DropRefs(this: (GASValue *)v12, a2: a1);
      LOBYTE(v12->cbSize) = 2;
      LOBYTE(v12->cItems) = v2;
    }
    else
    {
      GASFnCall::ThisPtrError(this: a2, a2: "Rectangle", a3: nullptr, a4: 0);
    }
    GASValue::~GASValue(this: v21, a2: a1);
    GASValue::~GASValue(this: v20, a2: a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128B20
// Name: public: static void GASRectangleProto::ContainsPoint(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::ContainsPoint(int a1@<edi>, GASFnCall *a2)
{
  char v2; // bl
  GASValue *v3; // eax
  struct GASObject *v4; // edi
  GASFnCall v5; // eax
  int p_cxItem; // ecx
  _SERVICE_STATUS *v7; // eax
  GASValue *v8; // esi
  int j; // edi
  double v10; // st7
  double v11; // st4
  double v12; // st5
  GASFnCall v13; // esi
  GASValue *v14; // esi
  int i; // edi
  const struct GASEnvironment *v16; // [esp-8h] [ebp-60h]
  const char *v18; // [esp+0h] [ebp-58h]
  int v19; // [esp+4h] [ebp-54h]
  _BYTE v20[16]; // [esp+8h] [ebp-50h] BYREF
  _BYTE v21[16]; // [esp+18h] [ebp-40h] BYREF
  double v22; // [esp+28h] [ebp-30h] BYREF
  double v23; // [esp+30h] [ebp-28h]
  double v24; // [esp+38h] [ebp-20h]
  double v25; // [esp+40h] [ebp-18h]
  int v26[2]; // [esp+48h] [ebp-10h] BYREF
  double v27; // [esp+50h] [ebp-8h]

  v2 = 0;
  if ( (int)a2[7] > 0 )
  {
    v16 = (const struct GASEnvironment *)a2[6];
    v3 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
    v4 = GASValue::ToObject(this: v3, a2: a1, a3: v16);
    if ( v4 != nullptr )
    {
      if ( GASFnCall::CheckThisPtr(this: a2, type: 0x11u) )
      {
        v5 = a2[2];
        if ( v5 != nullptr )
          p_cxItem = (int)&v5[-1].cxItem;
        else
          p_cxItem = 0;
        v7 = (_SERVICE_STATUS *)a2[6];
        v22 = 0.0;
        v23 = 0.0;
        v24 = 0.0;
        v25 = 0.0;
        v20[0] = 0;
        v21[0] = 0;
        GASRectangleObject::GetProperties(
          a1: p_cxItem,
          a2: 0.0,
          penv: v7,
          r: (GMemoryHeap *)&v22,
          params: a1,
          a6: v18,
          a7: v19);
        GFxObject_GetPointProperties(a1: (struct GASEnvironment *)a2[6], a2: v4, a3: (struct GASValue *const)v20);
        if ( ((int (__thiscall *)(struct GASObject *))v4[2].pNode[1].pNext)(a1: &v4[2]) == 16
          || v20[0] != 0 && v20[0] != 10 && LOBYTE(GASValue::IsUndefined(this: v21).usPreferredNode) == 0 )
        {
          GASPointObject::GetProperties(this: v4, a2: (_SERVICE_STATUS *)a2[6], a3: (double *)v26);
          v10 = *(double *)v26;
          if ( v24 == *(double *)v26 )
          {
            *(double *)v26 = *(double *)v26 + 1.0;
            v10 = v10 + 1.0;
          }
          v11 = v27;
          if ( v25 == v27 )
          {
            v11 = v27 + 1.0;
            v12 = v25;
            v27 = v11;
          }
          else
          {
            v12 = v25;
          }
          if ( v24 >= v10 && v22 <= v10 && v11 <= v12 && v11 >= v23 )
            v2 = 1;
          v13 = a2[1];
          GASValue::DropRefs(this: (GASValue *)v13, a2: (int)v4);
          LOBYTE(v13->cbSize) = 2;
          LOBYTE(v13->cItems) = v2;
          v14 = (GASValue *)&v22;
          for ( i = 1; i >= 0; --i )
          {
            v14 -= 4;
            GASValue::~GASValue(this: v14, a2: i);
          }
        }
        else
        {
          v8 = (GASValue *)&v22;
          for ( j = 1; j >= 0; --j )
          {
            v8 -= 4;
            GASValue::~GASValue(this: v8, a2: j);
          }
        }
      }
      else
      {
        GASFnCall::ThisPtrError(this: a2, a2: "Rectangle", a3: nullptr, a4: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128CC0
// Name: public: static void GASRectangleProto::ContainsRectangle(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::ContainsRectangle(int a1@<edi>, GASFnCall *a2)
{
  char v2; // bl
  GASValue *v3; // eax
  struct GASObject *v4; // edi
  GASFnCall v5; // eax
  int p_cxItem; // ecx
  _SERVICE_STATUS *v7; // eax
  long double v8; // st7
  double v9; // st7
  GASFnCall v10; // esi
  unsigned int *v11; // esi
  int j; // edi
  unsigned int *p_SpinCount; // esi
  int i; // edi
  const struct GASEnvironment *v15; // [esp-8h] [ebp-8Ch]
  const char *v17; // [esp+0h] [ebp-84h]
  int v18; // [esp+4h] [ebp-80h]
  long double v19; // [esp+8h] [ebp-7Ch]
  double v20; // [esp+10h] [ebp-74h]
  long double v21; // [esp+18h] [ebp-6Ch]
  GMemoryHeap r; // [esp+20h] [ebp-64h] BYREF

  v2 = 0;
  if ( (int)a2[7] > 0 )
  {
    v15 = (const struct GASEnvironment *)a2[6];
    v3 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
    v4 = GASValue::ToObject(this: v3, a2: a1, a3: v15);
    if ( v4 != nullptr )
    {
      if ( GASFnCall::CheckThisPtr(this: a2, type: 0x11u) )
      {
        v5 = a2[2];
        if ( v5 != nullptr )
          p_cxItem = (int)&v5[-1].cxItem;
        else
          p_cxItem = 0;
        v7 = (_SERVICE_STATUS *)a2[6];
        *(double *)&r.__vftable = 0.0;
        *(double *)&r.pNext = 0.0;
        *(double *)&r.RefCount = 0.0;
        *(double *)&r.pAutoRelease = 0.0;
        LOBYTE(r.Info.Desc.MinAlign) = 0;
        LOBYTE(r.Info.Desc.Limit) = 0;
        LOBYTE(r.Info.pName) = 0;
        LOBYTE(r.HeapLock.cs.LockCount) = 0;
        GASRectangleObject::GetProperties(a1: p_cxItem, a2: 0.0, penv: v7, &r, params: a1, a6: v17, a7: v18);
        GFxObject_GetRectangleProperties(a1: (int)&r.Info.Desc.MinAlign, a2: (int)v4, a3: (int)a2[6]);
        if ( LOBYTE(r.Info.Desc.MinAlign) == 0
          || LOBYTE(r.Info.Desc.MinAlign) == 10
          || LOBYTE(r.Info.Desc.Limit) == 0
          || LOBYTE(r.Info.Desc.Limit) == 10
          || LOBYTE(GASValue::IsUndefined(this: &r.Info.pName).usPreferredNode) != 0
          || LOBYTE(GASValue::IsUndefined(this: &r.HeapLock.cs.LockCount).usPreferredNode) != 0 )
        {
          p_SpinCount = &r.HeapLock.cs.SpinCount;
          for ( i = 3; i >= 0; --i )
          {
            p_SpinCount -= 4;
            GASValue::~GASValue(this: (GASValue *)p_SpinCount, a2: i);
          }
        }
        else
        {
          v20 = GASValue::ToNumber(
                  this: (GASValue *)&r.Info.pName,
                  a2: (int)v4,
                  a3: v8,
                  result: (_SERVICE_STATUS *)a2[6]);
          v21 = GASValue::ToNumber(
                  this: (GASValue *)&r.HeapLock.cs.LockCount,
                  a2: (int)v4,
                  a3: v20,
                  result: (_SERVICE_STATUS *)a2[6]);
          v19 = GASValue::ToNumber(
                  this: (GASValue *)&r.Info.Desc.MinAlign,
                  a2: (int)v4,
                  a3: v21,
                  result: (_SERVICE_STATUS *)a2[6]);
          v9 = GASValue::ToNumber(
                 this: (GASValue *)&r.Info.Desc.Limit,
                 a2: (int)v4,
                 a3: v19,
                 result: (_SERVICE_STATUS *)a2[6]);
          if ( v20 + v19 <= *(double *)&r.RefCount
            && v21 + v9 <= *(double *)&r.pAutoRelease
            && v19 >= *(double *)&r.__vftable
            && v9 >= *(double *)&r.pNext )
          {
            v2 = 1;
          }
          v10 = a2[1];
          GASValue::DropRefs(this: (GASValue *)v10, a2: (int)v4);
          LOBYTE(v10->cbSize) = 2;
          LOBYTE(v10->cItems) = v2;
          v11 = &r.HeapLock.cs.SpinCount;
          for ( j = 3; j >= 0; --j )
          {
            v11 -= 4;
            GASValue::~GASValue(this: (GASValue *)v11, a2: j);
          }
        }
      }
      else
      {
        GASFnCall::ThisPtrError(this: a2, a2: "Rectangle", a3: nullptr, a4: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128EA0
// Name: public: static void GASRectangleProto::Inflate(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::Inflate(int a1@<edi>, GASFnCall *a2)
{
  bool v2; // cc
  tagWNDCLASSW *v3; // eax
  tagWNDCLASSW *v4; // eax
  GASFnCall v5; // eax
  int p_cxItem; // edi
  _SERVICE_STATUS *v7; // ecx
  long double v8; // st7
  double v9; // st7
  unsigned int v10; // [esp-Ch] [ebp-58h]
  int v12; // [esp-4h] [ebp-50h]
  const char *v13; // [esp+0h] [ebp-4Ch]
  double v14; // [esp+4h] [ebp-48h] BYREF
  double v15; // [esp+Ch] [ebp-40h]
  double v16; // [esp+14h] [ebp-38h]
  double v17; // [esp+1Ch] [ebp-30h]
  GASValue v18[4]; // [esp+24h] [ebp-28h] BYREF
  GASValue v19[4]; // [esp+34h] [ebp-18h] BYREF
  double v20; // [esp+44h] [ebp-8h]

  v2 = (int)a2[7] <= 0;
  LOBYTE(v18[0]) = 0;
  LOBYTE(v19[0]) = 0;
  if ( !v2 )
  {
    v3 = (tagWNDCLASSW *)GASFnCall::Arg(this: a2, a2: 0);
    GASValue::operator=(this: (int)v18, v: v3);
    if ( (int)a2[7] > 1 )
    {
      v4 = (tagWNDCLASSW *)GASFnCall::Arg(this: a2, a2: 1);
      GASValue::operator=(this: (int)v19, v: v4);
    }
  }
  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x11u) )
  {
    v5 = a2[2];
    if ( v5 != nullptr )
      p_cxItem = (int)&v5[-1].cxItem;
    else
      p_cxItem = 0;
    v7 = (_SERVICE_STATUS *)a2[6];
    v14 = 0.0;
    v15 = 0.0;
    v16 = 0.0;
    v17 = 0.0;
    GASRectangleObject::GetProperties(
      a1: p_cxItem,
      a2: 0.0,
      penv: v7,
      r: (GMemoryHeap *)&v14,
      params: a1,
      a6: v13,
      a7: COERCE_UNSIGNED_INT64(0.0));
    v20 = GASValue::ToNumber(this: v18, a2: p_cxItem, a3: v8, result: (_SERVICE_STATUS *)a2[6]);
    v9 = GASValue::ToNumber(this: v19, a2: p_cxItem, a3: v20, result: (_SERVICE_STATUS *)a2[6]);
    v10 = (unsigned int)a2[6];
    v14 = v14 - v20;
    v16 = v20 + v16;
    v15 = v15 - v9;
    v17 = v9 + v17;
    GASRectangleObject::SetProperties(a1: p_cxItem, a2: p_cxItem, penv: v10, r: (GMemoryHeap *)&v14, a5: v12);
    GASValue::~GASValue(this: v19, a2: p_cxItem);
    GASValue::~GASValue(this: v18, a2: p_cxItem);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Rectangle", a3: nullptr, a4: 0);
    GASValue::~GASValue(this: v19, a2: a1);
    GASValue::~GASValue(this: v18, a2: a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128FB0
// Name: public: static void GASRectangleProto::InflatePoint(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::InflatePoint(int a1@<ebx>, const char *a2@<edi>, GASFnCall *a3)
{
  GASFnCall v3; // edi
  char *p_cxItem; // edi
  GASValue *v5; // eax
  struct GASObject *v6; // ebx
  _SERVICE_STATUS *v7; // eax
  unsigned int v8; // ecx
  const struct GASEnvironment *v9; // [esp-Ch] [ebp-40h]
  int v11; // [esp-8h] [ebp-3Ch]
  int v13; // [esp+0h] [ebp-34h]
  double v14; // [esp+4h] [ebp-30h] BYREF
  double v15; // [esp+Ch] [ebp-28h]
  double v16; // [esp+14h] [ebp-20h]
  double v17; // [esp+1Ch] [ebp-18h]
  int v18[2]; // [esp+24h] [ebp-10h] BYREF
  double v19; // [esp+2Ch] [ebp-8h]

  if ( (int)a3[7] > 0 )
  {
    if ( GASFnCall::CheckThisPtr(this: a3, type: 0x11u) )
    {
      v3 = a3[2];
      if ( v3 != nullptr )
        p_cxItem = (char *)&v3[-1].cxItem;
      else
        p_cxItem = nullptr;
      v9 = (const struct GASEnvironment *)a3[6];
      v5 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
      v6 = GASValue::ToObject(this: v5, a2: (int)p_cxItem, a3: v9);
      if ( v6 != nullptr )
      {
        v7 = (_SERVICE_STATUS *)a3[6];
        v14 = 0.0;
        v15 = 0.0;
        v16 = 0.0;
        v17 = 0.0;
        GASRectangleObject::GetProperties(
          a1: (int)p_cxItem,
          a2: 0.0,
          penv: v7,
          r: (GMemoryHeap *)&v14,
          params: a1,
          a6: a2,
          a7: v13);
        GFxObject_GetPointProperties(a1: (_SERVICE_STATUS *)a3[6], a2: (int)v6, a3: (double *)v18);
        v8 = (unsigned int)a3[6];
        v14 = v14 - *(double *)v18;
        v16 = *(double *)v18 + v16;
        v15 = v15 - v19;
        v17 = v19 + v17;
        GASRectangleObject::SetProperties(
          a1: (int)p_cxItem,
          a2: (int)p_cxItem,
          penv: v8,
          r: (GMemoryHeap *)&v14,
          a5: v11);
      }
      else
      {
        GASRectangleObject::SetProperties(
          this: p_cxItem,
          psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)&a3[6][3],
          a3: &GFxRectangle_NaNParams);
      }
    }
    else
    {
      GASFnCall::ThisPtrError(this: a3, a2: "Rectangle", a3: nullptr, a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101290A0
// Name: public: static void GASRectangleProto::Intersects(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::Intersects(int a1@<edi>, GASFnCall *a2)
{
  char Reserve_high; // bl
  GASFnCall v3; // eax
  GASValue *v4; // eax
  struct GASObject *v5; // edi
  _SERVICE_STATUS *v6; // edx
  long double v7; // st7
  double v8; // st7
  double v9; // st5
  double v10; // st6
  double v11; // st2
  double v12; // st4
  double v13; // st7
  double v14; // st3
  double v15; // st5
  double v16; // st6
  double v17; // st3
  double v18; // st3
  double v19; // rt0
  double v20; // rt1
  double v21; // st3
  double v22; // st6
  GASValue *v23; // edi
  int i; // ebx
  GASFnCall v25; // esi
  const struct GASEnvironment *v26; // [esp-8h] [ebp-C0h]
  int v27; // [esp-4h] [ebp-BCh]
  const char *v28; // [esp+0h] [ebp-B8h]
  int v29; // [esp+4h] [ebp-B4h]
  double v30; // [esp+20h] [ebp-98h]
  double v31; // [esp+38h] [ebp-80h]
  double v32; // [esp+40h] [ebp-78h]
  GMemoryHeap r; // [esp+48h] [ebp-70h] BYREF
  int v34; // [esp+B4h] [ebp-4h] BYREF

  Reserve_high = 0;
  if ( !GASFnCall::CheckThisPtr(this: a2, type: 0x11u) )
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Rectangle", a3: nullptr, a4: 0);
    return;
  }
  v3 = a2[2];
  if ( v3 != nullptr )
    r.Info.Desc.Granularity = (unsigned int)&v3[-1].cxItem;
  else
    r.Info.Desc.Granularity = 0;
  if ( (int)a2[7] > 0 )
  {
    v27 = a1;
    v26 = (const struct GASEnvironment *)a2[6];
    v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
    v5 = GASValue::ToObject(this: v4, a2: a1, a3: v26);
    if ( v5 == nullptr )
    {
LABEL_30:
      a1 = v27;
      goto LABEL_31;
    }
    v6 = (_SERVICE_STATUS *)a2[6];
    *(double *)&r.__vftable = 0.0;
    *(double *)&r.pNext = 0.0;
    *(double *)&r.RefCount = 0.0;
    *(double *)&r.pAutoRelease = 0.0;
    LOBYTE(r.Info.Desc.Threshold) = 0;
    LOBYTE(r.Info.pParent) = 0;
    LOBYTE(r.HeapLock.cs.DebugInfo) = 0;
    LOBYTE(r.HeapLock.cs.LockSemaphore) = 0;
    GASRectangleObject::GetProperties(a1: r.Info.Desc.Granularity, a2: 0.0, penv: v6, &r, params: v27, a6: v28, a7: v29);
    GFxObject_GetRectangleProperties(a1: (int)&r.Info.Desc.Threshold, a2: (int)v5, a3: (int)a2[6]);
    v31 = GASValue::ToNumber(this: (GASValue *)&r.HeapLock, a2: (int)v5, a3: v7, result: (_SERVICE_STATUS *)a2[6]);
    v32 = GASValue::ToNumber(
            this: (GASValue *)&r.HeapLock.cs.LockSemaphore,
            a2: (int)v5,
            a3: v31,
            result: (_SERVICE_STATUS *)a2[6]);
    *(double *)&r.Info.Desc.MinAlign = GASValue::ToNumber(
                                         this: (GASValue *)&r.Info.Desc.Threshold,
                                         a2: (int)v5,
                                         a3: v32,
                                         result: (_SERVICE_STATUS *)a2[6]);
    v8 = GASValue::ToNumber(
           this: (GASValue *)&r.Info.pParent,
           a2: (int)v5,
           a3: *(long double *)&r.Info.Desc.MinAlign,
           result: (_SERVICE_STATUS *)a2[6]);
    v9 = *(double *)&r.Info.Desc.MinAlign;
    v10 = v31 + *(double *)&r.Info.Desc.MinAlign;
    v30 = v32 + v8;
    v11 = v8;
    if ( v8 > *(double *)&r.pAutoRelease || *(double *)&r.pNext > v30 || *(double *)&r.__vftable > v10 )
    {
      v15 = 0.0;
      v16 = 0.0;
    }
    else
    {
      if ( *(double *)&r.RefCount >= *(double *)&r.Info.Desc.MinAlign )
      {
        v12 = v8;
        if ( *(double *)&r.__vftable > *(double *)&r.Info.Desc.MinAlign )
          v9 = *(double *)&r.__vftable;
        v13 = 0.0;
        if ( *(double *)&r.RefCount <= v10 )
          v10 = *(double *)&r.RefCount;
        if ( *(double *)&r.pNext > v11 )
          v12 = *(double *)&r.pNext;
        v14 = v30;
        if ( *(double *)&r.pAutoRelease <= v30 )
          v14 = *(double *)&r.pAutoRelease;
        goto LABEL_24;
      }
      v15 = 0.0;
      v16 = 0.0;
    }
    v17 = v15;
    v9 = 0.0;
    v13 = v17;
    v18 = v16;
    v10 = 0.0;
    v19 = v18;
    v14 = 0.0;
    v12 = v19;
LABEL_24:
    v20 = v14;
    v21 = v10;
    v22 = v20;
    HIBYTE(r.Info.Desc.Reserve) = 1;
    if ( v13 == v21 - v9 || v22 - v12 == v13 )
      HIBYTE(r.Info.Desc.Reserve) = 0;
    v23 = (GASValue *)&v34;
    for ( i = 3; i >= 0; --i )
    {
      v23 -= 4;
      GASValue::~GASValue(this: v23, a2: (int)v23);
    }
    Reserve_high = HIBYTE(r.Info.Desc.Reserve);
    goto LABEL_30;
  }
LABEL_31:
  v25 = a2[1];
  GASValue::DropRefs(this: (GASValue *)v25, a2: a1);
  LOBYTE(v25->cItems) = Reserve_high;
  LOBYTE(v25->cbSize) = 2;
}

//------------------------------------------------------------------------------
// Address: 0x101292D0
// Name: public: static void GASRectangleProto::IsEmpty(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::IsEmpty(int a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  char v3; // bl
  GASFnCall v4; // eax
  int p_cxItem; // ecx
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  GASFnCall v11; // esi
  GASValue *v12; // esi
  int i; // edi
  struct GASStringNode *v14; // [esp-8h] [ebp-64h]
  const char *v15; // [esp+0h] [ebp-5Ch]
  int v16; // [esp+4h] [ebp-58h]
  double v17; // [esp+8h] [ebp-54h]
  double v18; // [esp+10h] [ebp-4Ch]
  double v19; // [esp+10h] [ebp-4Ch]
  int params[4]; // [esp+18h] [ebp-44h] BYREF
  GASValue v21; // [esp+28h] [ebp-34h] BYREF
  GASValue v22[4]; // [esp+38h] [ebp-24h] BYREF
  GASValue v23[4]; // [esp+48h] [ebp-14h] BYREF
  int v24; // [esp+58h] [ebp-4h] BYREF

  v3 = 0;
  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x11u) )
  {
    v4 = a3[2];
    if ( v4 != nullptr )
      p_cxItem = (int)&v4[-1].cxItem;
    else
      p_cxItem = 0;
    v14 = (struct GASStringNode *)&a3[6][3];
    LOBYTE(params[0]) = 0;
    LOBYTE(v21) = 0;
    LOBYTE(v22[0]) = 0;
    LOBYTE(v23[0]) = 0;
    GASRectangleObject::GetProperties(a1: p_cxItem, psc: v14, (int)params, psc_8: v15, psc_12: v16);
    v6 = GASValue::ToNumber(this: v22, a2: a1, a3: a2, result: (_SERVICE_STATUS *)a3[6]);
    v18 = v6;
    if ( (HIDWORD(v18) & 0x7FF00000) == 0x7FF00000 && (HIDWORD(v18) & 0xFFFFF | LODWORD(v18)) != 0
      || (v7 = GASValue::ToNumber(this: v23, a2: a1, a3: v6, result: (_SERVICE_STATUS *)a3[6]),
          v19 = v7,
          (HIDWORD(v19) & 0x7FF00000) == 0x7FF00000)
      && (HIDWORD(v19) & 0xFFFFF | LODWORD(v19)) != 0
      || (v8 = GASValue::ToNumber(this: (GASValue *)params, a2: a1, a3: v7, result: (_SERVICE_STATUS *)a3[6]),
          v9 = GASValue::ToNumber(this: &v21, a2: a1, a3: v8, result: (_SERVICE_STATUS *)a3[6]),
          v17 = GASValue::ToNumber(this: v22, a2: a1, a3: v9, result: (_SERVICE_STATUS *)a3[6]),
          v10 = GASValue::ToNumber(this: v23, a2: a1, a3: v17, result: (_SERVICE_STATUS *)a3[6]),
          v17 <= 0.0)
      || v10 <= 0.0 )
    {
      v3 = 1;
    }
    v11 = a3[1];
    GASValue::DropRefs(this: (GASValue *)v11, a2: a1);
    LOBYTE(v11->cbSize) = 2;
    LOBYTE(v11->cItems) = v3;
    v12 = (GASValue *)&v24;
    for ( i = 3; i >= 0; --i )
    {
      v12 -= 4;
      GASValue::~GASValue(this: v12, a2: i);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "Rectangle", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129440
// Name: public: static void GASRectangleProto::Offset(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::Offset(const char *a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  tagWNDCLASSW *v3; // eax
  tagWNDCLASSW *v4; // eax
  GASFnCall v5; // eax
  char *p_cxItem; // edi
  double v7; // st7
  long double v8; // st7
  double v9; // st7
  GASValue *v10; // esi
  int i; // edi
  struct GASStringNode *v12; // [esp-Ch] [ebp-90h]
  int v14; // [esp+0h] [ebp-84h]
  GASValue v15[4]; // [esp+8h] [ebp-7Ch] BYREF
  GASValue v16[4]; // [esp+18h] [ebp-6Ch] BYREF
  double v17; // [esp+28h] [ebp-5Ch]
  tagWNDCLASSW v; // [esp+30h] [ebp-54h] BYREF
  char v19; // [esp+60h] [ebp-24h]
  char v20; // [esp+70h] [ebp-14h]
  int v21; // [esp+80h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x11u) )
  {
    LOBYTE(v15[0]) = 0;
    LOBYTE(v16[0]) = 0;
    if ( (int)a3[7] > 0 )
    {
      v3 = (tagWNDCLASSW *)GASFnCall::Arg(this: a3, a2: 0);
      GASValue::operator=(this: (int)v15, v: v3);
      if ( (int)a3[7] > 1 )
      {
        v4 = (tagWNDCLASSW *)GASFnCall::Arg(this: a3, a2: 1);
        GASValue::operator=(this: (int)v16, v: v4);
      }
    }
    v5 = a3[2];
    if ( v5 != nullptr )
      p_cxItem = (char *)&v5[-1].cxItem;
    else
      p_cxItem = nullptr;
    v12 = (struct GASStringNode *)&a3[6][3];
    LOBYTE(v.hInstance) = 0;
    LOBYTE(v.lpszMenuName) = 0;
    v19 = 0;
    v20 = 0;
    GASRectangleObject::GetProperties(a1: (int)p_cxItem, psc: v12, params: (int)&v.hInstance, psc_8: a1, psc_12: v14);
    v17 = GASValue::ToNumber(
            this: (GASValue *)&v.hInstance,
            a2: (int)p_cxItem,
            a3: a2,
            result: (_SERVICE_STATUS *)a3[6]);
    v7 = GASValue::ToNumber(this: v15, a2: (int)p_cxItem, a3: v17, result: (_SERVICE_STATUS *)a3[6]);
    v8 = v7 + v17;
    *(double *)&v.lpfnWndProc = v8;
    LOBYTE(v.style) = 3;
    GASValue::operator=(this: (int)&v.hInstance, &v);
    GASValue::~GASValue(this: (GASValue *)&v, a2: (int)p_cxItem);
    v17 = GASValue::ToNumber(
            this: (GASValue *)&v.lpszMenuName,
            a2: (int)p_cxItem,
            a3: v8,
            result: (_SERVICE_STATUS *)a3[6]);
    v9 = GASValue::ToNumber(this: v16, a2: (int)p_cxItem, a3: v17, result: (_SERVICE_STATUS *)a3[6]);
    *(double *)&v.lpfnWndProc = v9 + v17;
    LOBYTE(v.style) = 3;
    GASValue::operator=(this: (int)&v.lpszMenuName, &v);
    GASValue::~GASValue(this: (GASValue *)&v, a2: (int)p_cxItem);
    GASRectangleObject::SetProperties(
      this: p_cxItem,
      psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)&a3[6][3],
      a3: (GMemoryHeap *)&v.hInstance);
    v10 = (GASValue *)&v21;
    for ( i = 3; i >= 0; --i )
    {
      v10 -= 4;
      GASValue::~GASValue(this: v10, a2: i);
    }
    GASValue::~GASValue(this: v16, a2: i);
    GASValue::~GASValue(this: v15, a2: i);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "Rectangle", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101295A0
// Name: public: static void GASRectangleProto::OffsetPoint(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::OffsetPoint(
        const char *a1@<ebx>,
        int a2@<edi>,
        long double a3@<st0>,
        GASFnCall *a4)
{
  GASFnCall v4; // edi
  char *p_cxItem; // edi
  GASValue *v6; // eax
  struct GASObject *v7; // eax
  GASFnCall v8; // edx
  struct GASObject *v9; // ebx
  GASValue *v10; // esi
  int k; // edi
  int v12; // ebx
  tagWNDCLASSW *v13; // esi
  int j; // edi
  GASValue *v15; // esi
  double v16; // st7
  long double v17; // st7
  int v18; // ebx
  double v19; // st7
  tagWNDCLASSW *p_v; // esi
  int i; // edi
  GASValue *v22; // esi
  const struct GASEnvironment *v23; // [esp-Ch] [ebp-94h]
  GASValue v26[4]; // [esp+4h] [ebp-84h] BYREF
  GASValue v27[4]; // [esp+14h] [ebp-74h] BYREF
  tagWNDCLASSW v; // [esp+24h] [ebp-64h] BYREF
  GASValue v29[4]; // [esp+54h] [ebp-34h] BYREF
  char v30; // [esp+64h] [ebp-24h]
  char v31; // [esp+74h] [ebp-14h]
  int v32; // [esp+84h] [ebp-4h] BYREF

  if ( (int)a4[7] > 0 )
  {
    if ( GASFnCall::CheckThisPtr(this: a4, type: 0x11u) )
    {
      v4 = a4[2];
      if ( v4 != nullptr )
        p_cxItem = (char *)&v4[-1].cxItem;
      else
        p_cxItem = nullptr;
      v23 = (const struct GASEnvironment *)a4[6];
      v6 = (GASValue *)GASFnCall::Arg(this: a4, a2: 0);
      v7 = GASValue::ToObject(this: v6, a2: (int)p_cxItem, a3: v23);
      v8 = a4[6];
      v9 = v7;
      LOBYTE(v.lpszMenuName) = 0;
      LOBYTE(v29[0]) = 0;
      v30 = 0;
      v31 = 0;
      if ( v7 != nullptr )
      {
        LOBYTE(v26[0]) = 0;
        LOBYTE(v27[0]) = 0;
        GFxObject_GetPointProperties(a1: (struct GASEnvironment *)v8, a2: v7, a3: (struct GASValue *const)v26);
        if ( ((int (__thiscall *)(struct GASObject *))v9[2].pNode[1].pNext)(a1: &v9[2]) == 16
          || LOBYTE(v26[0]) != 0
          && LOBYTE(v26[0]) != 10
          && LOBYTE(GASValue::IsUndefined(this: v27).usPreferredNode) == 0 )
        {
          GASRectangleObject::GetProperties(
            a1: (int)p_cxItem,
            psc: (struct GASStringNode *)&a4[6][3],
            params: (int)&v.lpszMenuName,
            psc_8: a1,
            psc_12: a2);
          *(double *)&v.hCursor = GASValue::ToNumber(this: v26, a2: (int)p_cxItem, a3, result: (_SERVICE_STATUS *)a4[6]);
          v16 = GASValue::ToNumber(
                  this: (GASValue *)&v.lpszMenuName,
                  a2: (int)p_cxItem,
                  a3: *(long double *)&v.hCursor,
                  result: (_SERVICE_STATUS *)a4[6]);
          v17 = v16 + *(double *)&v.hCursor;
          v18 = 3;
          *(double *)&v.lpfnWndProc = v17;
          LOBYTE(v.style) = 3;
          GASValue::operator=(this: (int)&v.lpszMenuName, &v);
          GASValue::~GASValue(this: (GASValue *)&v, a2: (int)p_cxItem);
          *(double *)&v.hCursor = GASValue::ToNumber(
                                    this: v27,
                                    a2: (int)p_cxItem,
                                    a3: v17,
                                    result: (_SERVICE_STATUS *)a4[6]);
          v19 = GASValue::ToNumber(
                  this: v29,
                  a2: (int)p_cxItem,
                  a3: *(long double *)&v.hCursor,
                  result: (_SERVICE_STATUS *)a4[6]);
          *(double *)&v.lpfnWndProc = v19 + *(double *)&v.hCursor;
          LOBYTE(v.style) = 3;
          GASValue::operator=(this: (int)v29, &v);
          GASValue::~GASValue(this: (GASValue *)&v, a2: (int)p_cxItem);
          GASRectangleObject::SetProperties(
            this: p_cxItem,
            psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)&a4[6][3],
            a3: (GMemoryHeap *)&v.lpszMenuName);
          p_v = &v;
          for ( i = 1; i >= 0; --i )
          {
            p_v = (tagWNDCLASSW *)((char *)p_v - 16);
            GASValue::~GASValue(this: (GASValue *)p_v, a2: i);
          }
          v22 = (GASValue *)&v32;
          do
          {
            v22 -= 4;
            GASValue::~GASValue(this: v22, a2: i);
            --v18;
          }
          while ( v18 >= 0 );
        }
        else
        {
          GASRectangleObject::GetProperties(
            a1: (int)p_cxItem,
            psc: (struct GASStringNode *)&a4[6][3],
            params: (int)&v.lpszMenuName,
            psc_8: a1,
            psc_12: a2);
          *(double *)&v.hIcon = GASNumberUtil::NaN();
          v12 = 3;
          LOBYTE(v.hInstance) = 3;
          GASValue::operator=(this: (int)&v.lpszMenuName, v: (tagWNDCLASSW *)&v.hInstance);
          GASValue::~GASValue(this: (GASValue *)&v.hInstance, a2: (int)p_cxItem);
          *(double *)&v.hIcon = GASNumberUtil::NaN();
          LOBYTE(v.hInstance) = 3;
          GASValue::operator=(this: (int)v29, v: (tagWNDCLASSW *)&v.hInstance);
          GASValue::~GASValue(this: (GASValue *)&v.hInstance, a2: (int)p_cxItem);
          GASRectangleObject::SetProperties(
            this: p_cxItem,
            psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)&a4[6][3],
            a3: (GMemoryHeap *)&v.lpszMenuName);
          v13 = &v;
          for ( j = 1; j >= 0; --j )
          {
            v13 = (tagWNDCLASSW *)((char *)v13 - 16);
            GASValue::~GASValue(this: (GASValue *)v13, a2: j);
          }
          v15 = (GASValue *)&v32;
          do
          {
            v15 -= 4;
            GASValue::~GASValue(this: v15, a2: j);
            --v12;
          }
          while ( v12 >= 0 );
        }
      }
      else
      {
        GASRectangleObject::GetProperties(
          a1: (int)p_cxItem,
          psc: (struct GASStringNode *)&v8[3],
          params: (int)&v.lpszMenuName,
          psc_8: a1,
          psc_12: a2);
        *(double *)&v.hIcon = GASNumberUtil::NaN();
        LOBYTE(v.hInstance) = 3;
        GASValue::operator=(this: (int)&v.lpszMenuName, v: (tagWNDCLASSW *)&v.hInstance);
        GASValue::~GASValue(this: (GASValue *)&v.hInstance, a2: (int)p_cxItem);
        *(double *)&v.hIcon = GASNumberUtil::NaN();
        LOBYTE(v.hInstance) = 3;
        GASValue::operator=(this: (int)v29, v: (tagWNDCLASSW *)&v.hInstance);
        GASValue::~GASValue(this: (GASValue *)&v.hInstance, a2: (int)p_cxItem);
        GASRectangleObject::SetProperties(
          this: p_cxItem,
          psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)&a4[6][3],
          a3: (GMemoryHeap *)&v.lpszMenuName);
        v10 = (GASValue *)&v32;
        for ( k = 3; k >= 0; --k )
        {
          v10 -= 4;
          GASValue::~GASValue(this: v10, a2: k);
        }
      }
    }
    else
    {
      GASFnCall::ThisPtrError(this: a4, a2: "Rectangle", a3: nullptr, a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129880
// Name: public: static void GASRectangleProto::SetEmpty(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::SetEmpty(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int p_cxItem; // ecx
  unsigned int v4; // edx
  int v5; // [esp+0h] [ebp-24h]
  double v6[4]; // [esp+4h] [ebp-20h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x11u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (int)&v2[-1].cxItem;
    else
      p_cxItem = 0;
    v4 = (unsigned int)a2[6];
    v6[0] = 0.0;
    v6[1] = 0.0;
    v6[2] = 0.0;
    v6[3] = 0.0;
    GASRectangleObject::SetProperties(a1: p_cxItem, a2: a1, penv: v4, r: (GMemoryHeap *)v6, a5: v5);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Rectangle", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101298E0
// Name: public: static void GASRectangleProto::ToString(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::ToString(const char *a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  struct GASStringNode *StringNode; // edi
  GASFnCall v4; // esi
  bool v5; // zf
  void *v6; // esi
  int *v7; // esi
  int i; // edi
  int v9; // ecx
  GASValue *v10; // esi
  int j; // edi
  struct GASStringNode *v12; // [esp-Ch] [ebp-6Ch]
  int v13; // [esp+0h] [ebp-60h]
  CUtlMemory<CImagePacker,int> v14; // [esp+8h] [ebp-58h] BYREF
  unsigned __int8 v15[16]; // [esp+1Ch] [ebp-44h] BYREF
  unsigned __int8 v16[16]; // [esp+2Ch] [ebp-34h] BYREF
  unsigned __int8 v17[16]; // [esp+3Ch] [ebp-24h] BYREF
  CImagePacker **v18; // [esp+4Ch] [ebp-14h] BYREF
  CImagePacker **v19; // [esp+50h] [ebp-10h] BYREF
  CImagePacker **v20; // [esp+54h] [ebp-Ch] BYREF
  CImagePacker **v21; // [esp+58h] [ebp-8h] BYREF
  int v22; // [esp+5Ch] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x11u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr && v2 != (GASFnCall)16 )
    {
      v12 = (struct GASStringNode *)&a2[6][3];
      LOBYTE(v14.m_nAllocationCount) = 0;
      v15[0] = 0;
      v16[0] = 0;
      v17[0] = 0;
      GASRectangleObject::GetProperties(
        a1: (int)&v2[-1].cxItem,
        psc: v12,
        params: (int)&v14.m_nAllocationCount,
        psc_8: a1,
        psc_12: v13);
      GASValue::ToStringImpl(
        this: (unsigned __int8 *)&v14.m_nAllocationCount,
        a2: (int *)&v18,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)a2[6],
        precision: 6,
        debug: false);
      GASValue::ToStringImpl(
        this: v15,
        a2: (int *)&v19,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)a2[6],
        precision: 6,
        debug: false);
      GASValue::ToStringImpl(
        this: v16,
        a2: (int *)&v20,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)a2[6],
        precision: 6,
        debug: false);
      GASValue::ToStringImpl(
        this: v17,
        a2: (int *)&v21,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)a2[6],
        precision: 6,
        debug: false);
      GString::GString(this: &v14);
      GString::AppendString(this: &v14, putf8str: (CImagePacker *)"(x=", utf8StrSz: -1);
      GString::AppendString(this: &v14, putf8str: *v18, utf8StrSz: -1);
      GString::AppendString(this: &v14, putf8str: (CImagePacker *)", y=", utf8StrSz: -1);
      GString::AppendString(this: &v14, putf8str: *v19, utf8StrSz: -1);
      GString::AppendString(this: &v14, putf8str: (CImagePacker *)", width=", utf8StrSz: -1);
      GString::AppendString(this: &v14, putf8str: *v20, utf8StrSz: -1);
      GString::AppendString(this: &v14, putf8str: (CImagePacker *)", height=", utf8StrSz: -1);
      GString::AppendString(this: &v14, putf8str: *v21, utf8StrSz: -1);
      GString::AppendString(this: &v14, putf8str: (CImagePacker *)")", utf8StrSz: -1);
      StringNode = GASStringManager::CreateStringNode(
                     this: *(GASStringManager **)(a2[6][3].cbSize + 636),
                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)v14.m_pMemory
                                                                                               & 0xFFFFFFFC)
                                                                                              + 8),
                     length: *(_DWORD *)((int)v14.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++*((_DWORD *)StringNode + 2);
      v4 = a2[1];
      if ( LOBYTE(v4->cbSize) >= 5u )
        GASValue::DropRefs(this: (GASValue *)v4, a2: (int)StringNode);
      LOBYTE(v4->cbSize) = 5;
      v4->cItems = (int)StringNode;
      v5 = ++*((_DWORD *)StringNode + 2) == 1;
      --*((_DWORD *)StringNode + 2);
      if ( v5 )
        GASStringNode::ReleaseNode(a1: (int)StringNode);
      v6 = (void *)((int)v14.m_pMemory & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v14.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
      v7 = &v22;
      for ( i = 3; i >= 0; --i )
      {
        v9 = *--v7;
        v5 = (*(_DWORD *)(v9 + 8))-- == 1;
        if ( v5 )
          GASStringNode::ReleaseNode(a1: v9);
      }
      v10 = (GASValue *)&v18;
      for ( j = 3; j >= 0; --j )
      {
        v10 -= 4;
        GASValue::~GASValue(this: v10, a2: j);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Rectangle", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129AF0
// Name: public: virtual bool GASRectangleObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASRectangleObject::SetMember(
        CTSQueue<CFunctor *,0,1> *a1@<ecx>,
        const char *a2@<ebx>,
        int a3@<esi>,
        _SERVICE_STATUS *penv,
        const char ***name,
        tagWNDCLASSW *val,
        char *flags,
        int flags_4)
{
  int p_m_Count; // esi
  long double v11; // st7
  int v12; // esi
  long double v14; // st7
  int v15; // esi
  long double v17; // st7
  int v18; // esi
  long double v20; // st7
  _SERVICE_STATUS *v21; // esi
  struct GASObject *v22; // eax
  struct GASObject *v23; // eax
  double v24; // st7
  struct GASObject *v25; // eax
  int v27; // [esp-8h] [ebp-3Ch]
  int v28; // [esp-8h] [ebp-3Ch]
  int v29; // [esp-8h] [ebp-3Ch]
  int v30; // [esp-8h] [ebp-3Ch]
  int v31; // [esp-8h] [ebp-3Ch]
  int v32; // [esp+0h] [ebp-34h]
  double v33; // [esp+4h] [ebp-30h] BYREF
  double v34; // [esp+Ch] [ebp-28h]
  double v35; // [esp+14h] [ebp-20h]
  double v36; // [esp+1Ch] [ebp-18h]
  int v37[2]; // [esp+24h] [ebp-10h] BYREF
  double v38; // [esp+2Ch] [ebp-8h]

  if ( (*flags & 4) == 0 )
  {
    if ( strcmp(**name, "left") == 0 )
    {
      v33 = 0.0;
      p_m_Count = (int)&a1[-1].m_Count;
      v34 = 0.0;
      v35 = 0.0;
      v36 = 0.0;
      GASRectangleObject::GetProperties(
        a1: p_m_Count,
        a2: 0.0,
        penv,
        r: (GMemoryHeap *)&v33,
        params: a3,
        a6: a2,
        a7: v32);
      v33 = GASValue::ToNumber(this: (GASValue *)val, a2: (int)penv, a3: v11, result: penv);
      GASRectangleObject::SetProperties(
        a1: p_m_Count,
        a2: (int)penv,
        (unsigned int)penv,
        r: (GMemoryHeap *)&v33,
        a5: v27);
      return;
    }
    if ( strcmp(**name, "top") == 0 )
    {
      v33 = 0.0;
      v12 = (int)&a1[-1].m_Count;
      v34 = 0.0;
      v35 = 0.0;
      v36 = 0.0;
      GASRectangleObject::GetProperties(a1: v12, a2: 0.0, penv, r: (GMemoryHeap *)&v33, params: a3, a6: a2, a7: v32);
      v34 = GASValue::ToNumber(this: (GASValue *)val, a2: (int)penv, a3: v14, result: penv);
      GASRectangleObject::SetProperties(a1: v12, a2: (int)penv, (unsigned int)penv, r: (GMemoryHeap *)&v33, a5: v28);
      return;
    }
    if ( GASString::operator==(this: name, a2: "right") )
    {
      v33 = 0.0;
      v15 = (int)&a1[-1].m_Count;
      v34 = 0.0;
      v35 = 0.0;
      v36 = 0.0;
      GASRectangleObject::GetProperties(a1: v15, a2: 0.0, penv, r: (GMemoryHeap *)&v33, params: a3, a6: a2, a7: v32);
      v35 = GASValue::ToNumber(this: (GASValue *)val, a2: (int)penv, a3: v17, result: penv);
      GASRectangleObject::SetProperties(a1: v15, a2: (int)penv, (unsigned int)penv, r: (GMemoryHeap *)&v33, a5: v29);
      return;
    }
    if ( GASString::operator==(this: name, a2: (const char *)&stru_102A3488.m_Size) )
    {
      v33 = 0.0;
      v18 = (int)&a1[-1].m_Count;
      v34 = 0.0;
      v35 = 0.0;
      v36 = 0.0;
      GASRectangleObject::GetProperties(a1: v18, a2: 0.0, penv, r: (GMemoryHeap *)&v33, params: a3, a6: a2, a7: v32);
      v36 = GASValue::ToNumber(this: (GASValue *)val, a2: (int)penv, a3: v20, result: penv);
      GASRectangleObject::SetProperties(a1: v18, a2: (int)penv, (unsigned int)penv, r: (GMemoryHeap *)&v33, a5: v30);
      return;
    }
    if ( GASString::operator==(this: name, a2: (const char *)&stru_102A6FE4.m_Size) )
    {
      v21 = penv;
      v33 = 0.0;
      v34 = 0.0;
      v35 = 0.0;
      v36 = 0.0;
      GASRectangleObject::GetProperties(
        a1: (int)&a1[-1].m_Count,
        a2: 0.0,
        penv,
        r: (GMemoryHeap *)&v33,
        params: a3,
        a6: a2,
        a7: v32);
      v22 = GASValue::ToObject(this: (GASValue *)val, a2: (int)a1, a3: (const struct GASEnvironment *)penv);
      if ( v22 != nullptr )
      {
        GFxObject_GetPointProperties(a1: penv, a2: (int)v22, a3: (double *)v37);
        v33 = *(double *)v37;
        v34 = v38;
      }
      goto LABEL_20;
    }
    if ( GASString::operator==(this: name, a2: (const char *)&stru_102A6FE4) )
    {
      v21 = penv;
      v33 = 0.0;
      v34 = 0.0;
      v35 = 0.0;
      v36 = 0.0;
      GASRectangleObject::GetProperties(
        a1: (int)&a1[-1].m_Count,
        a2: 0.0,
        penv,
        r: (GMemoryHeap *)&v33,
        params: a3,
        a6: a2,
        a7: v32);
      v23 = GASValue::ToObject(this: (GASValue *)val, a2: (int)a1, a3: (const struct GASEnvironment *)penv);
      if ( v23 != nullptr )
      {
        GFxObject_GetPointProperties(a1: penv, a2: (int)v23, a3: (double *)v37);
        v35 = *(double *)v37;
        v24 = v38;
LABEL_19:
        v36 = v24;
        goto LABEL_20;
      }
      goto LABEL_20;
    }
    if ( GASString::operator==(this: name, a2: "size") )
    {
      v21 = penv;
      v33 = 0.0;
      v34 = 0.0;
      v35 = 0.0;
      v36 = 0.0;
      GASRectangleObject::GetProperties(
        a1: (int)&a1[-1].m_Count,
        a2: 0.0,
        penv,
        r: (GMemoryHeap *)&v33,
        params: a3,
        a6: a2,
        a7: v32);
      v25 = GASValue::ToObject(this: (GASValue *)val, a2: (int)a1, a3: (const struct GASEnvironment *)penv);
      if ( v25 != nullptr )
      {
        GFxObject_GetPointProperties(a1: penv, a2: (int)v25, a3: (double *)v37);
        v35 = *(double *)v37 + v33;
        v24 = v34 + v38;
        goto LABEL_19;
      }
LABEL_20:
      GASRectangleObject::SetProperties(
        a1: (int)&a1[-1].m_Count,
        a2: (int)a1,
        penv: (unsigned int)v21,
        r: (GMemoryHeap *)&v33,
        a5: v31);
      return;
    }
    GASObject::SetMember(
      this: a1,
      a2: (GASEnvironment *)penv,
      (_IMAGE_SYMBOL_EX *)name,
      pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)val,
      pmember: flags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129DF0
// Name: GFxRectangle_ComputeTopLeft
// Source: json
//------------------------------------------------------------------------------
GASValue *__usercall GFxRectangle_ComputeTopLeft@<eax>(
        GASValue *a1@<ebx>,
        CTSQueue<CFunctor *,0,1>::Node_t *a2@<edi>,
        double a3,
        double a4)
{
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *v5; // edx
  int v6; // eax
  int *v7; // esi
  double v9[2]; // [esp+4h] [ebp-14h] BYREF
  int v10; // [esp+14h] [ebp-4h] BYREF

  pNext = a2[15].pNext[82].pNext;
  v5 = pNext->pNext[5].pNext;
  v10 = 323;
  v6 = ((int (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, int, int *))v5)(a1: pNext, a2: 52, a3: &v10);
  if ( v6 != 0 )
    v7 = (int *)GASPointObject::GASPointObject(this: v6, result: a2);
  else
    v7 = nullptr;
  v9[0] = a3;
  v9[1] = a4;
  GASPointObject::SetProperties(this: v7, (int)a2, a3: v9);
  GASValue::GASValue(this: a1, a2: (struct GASObject *)v7);
  if ( v7 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v7, (int)a2);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10129E60
// Name: GFxRectangle_ComputeBottomRight
// Source: json
//------------------------------------------------------------------------------
GASValue *__usercall GFxRectangle_ComputeBottomRight@<eax>(
        GASValue *a1@<ebx>,
        CTSQueue<CFunctor *,0,1>::Node_t *a2@<edi>,
        int a3,
        int a4,
        int a5,
        int a6,
        double a7,
        double a8)
{
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *v9; // edx
  int v10; // eax
  int *v11; // esi
  double v13[2]; // [esp+4h] [ebp-14h] BYREF
  int v14; // [esp+14h] [ebp-4h] BYREF

  pNext = a2[15].pNext[82].pNext;
  v9 = pNext->pNext[5].pNext;
  v14 = 323;
  v10 = ((int (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, int, int *))v9)(a1: pNext, a2: 52, a3: &v14);
  if ( v10 != 0 )
    v11 = (int *)GASPointObject::GASPointObject(this: v10, result: a2);
  else
    v11 = nullptr;
  v13[0] = a7;
  v13[1] = a8;
  GASPointObject::SetProperties(this: v11, (int)a2, a3: v13);
  GASValue::GASValue(this: a1, a2: (struct GASObject *)v11);
  if ( v11 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v11, (int)a2);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10129ED0
// Name: GFxRectangle_ComputeSize
// Source: json
//------------------------------------------------------------------------------
GASValue *__usercall GFxRectangle_ComputeSize@<eax>(
        GASValue *a1@<ebx>,
        CTSQueue<CFunctor *,0,1>::Node_t *a2@<edi>,
        double a3,
        double a4,
        double a5,
        double a6)
{
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *v7; // edx
  int v8; // eax
  int *v9; // esi
  double v11[2]; // [esp+4h] [ebp-14h] BYREF
  int v12; // [esp+14h] [ebp-4h] BYREF

  pNext = a2[15].pNext[82].pNext;
  v7 = pNext->pNext[5].pNext;
  v12 = 323;
  v8 = ((int (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, int, int *))v7)(a1: pNext, a2: 52, a3: &v12);
  if ( v8 != 0 )
    v9 = (int *)GASPointObject::GASPointObject(this: v8, result: a2);
  else
    v9 = nullptr;
  v11[0] = a5 - a3;
  v11[1] = a6 - a4;
  GASPointObject::SetProperties(this: v9, (int)a2, a3: v11);
  GASValue::GASValue(this: a1, a2: (struct GASObject *)v9);
  if ( v9 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v9, (int)a2);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10129F40
// Name: public: GASRectangleObject::GASRectangleObject(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
GASRectangleObject *__thiscall GASRectangleObject::GASRectangleObject(GASRectangleObject *this, struct GASEnvironment *a2)
{
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  GASObject::GASObject((GASObject *)this, a2);
  *(_DWORD *)this = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A6FF8;
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *((vc_attributes::PreRangeAttribute **)a2 + 30),
                                                    result: (vc_attributes::InvalidCheckAttribute *)0xF);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)((char *)this + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)a2 + 15,
    psc_4: Prototype);
  GASRectangleObject::SetProperties(
    (char *)this,
    psc: (struct GASEnvironment *)((char *)a2 + 120),
    a3: &GFxRectangle_DefaultParams);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10129F90
// Name: public: virtual bool GASRectangleObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASRectangleObject::GetMember(
        D3DXQUATERNION *this,
        _SERVICE_STATUS *penv,
        const char ***a3,
        struct GASValue *a4)
{
  struct GASEnvironment *v4; // edi
  double v6; // st7
  tagWNDCLASSW *v7; // eax
  int v9; // [esp+0h] [ebp-3Ch]
  const char *v10; // [esp+4h] [ebp-38h]
  int v11; // [esp+8h] [ebp-34h]
  double v12; // [esp+Ch] [ebp-30h] BYREF
  double v13; // [esp+14h] [ebp-28h]
  double v14; // [esp+1Ch] [ebp-20h]
  double v15; // [esp+24h] [ebp-18h]
  GASValue v16; // [esp+2Ch] [ebp-10h] BYREF
  double v17; // [esp+30h] [ebp-Ch]

  v4 = (struct GASEnvironment *)a3;
  if ( strcmp(**a3, "left") == 0 )
  {
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    GASRectangleObject::GetProperties(
      a1: (int)(this - 1),
      a2: 0.0,
      penv,
      r: (GMemoryHeap *)&v12,
      params: v9,
      a6: v10,
      a7: v11);
    v6 = v12;
LABEL_3:
    v17 = v6;
    LOBYTE(v16) = 3;
    v7 = (tagWNDCLASSW *)&v16;
LABEL_4:
    GASValue::operator=(this: (int)a4, v: v7);
    GASValue::~GASValue(this: &v16, a2: (int)v4);
    return 1;
  }
  if ( strcmp(**a3, "right") == 0 )
  {
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    GASRectangleObject::GetProperties(
      a1: (int)(this - 1),
      a2: 0.0,
      penv,
      r: (GMemoryHeap *)&v12,
      params: v9,
      a6: v10,
      a7: v11);
    v6 = v14;
    goto LABEL_3;
  }
  if ( strcmp(**a3, "top") == 0 )
  {
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    GASRectangleObject::GetProperties(
      a1: (int)(this - 1),
      a2: 0.0,
      penv,
      r: (GMemoryHeap *)&v12,
      params: v9,
      a6: v10,
      a7: v11);
    v6 = v13;
    goto LABEL_3;
  }
  if ( GASString::operator==(this: a3, a2: (const char *)&stru_102A3488.m_Size) )
  {
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    GASRectangleObject::GetProperties(
      a1: (int)(this - 1),
      a2: 0.0,
      penv,
      r: (GMemoryHeap *)&v12,
      params: v9,
      a6: v10,
      a7: v11);
    v6 = v15;
    goto LABEL_3;
  }
  if ( GASString::operator==(this: a3, a2: (const char *)&stru_102A6FE4.m_Size) )
  {
    v4 = (struct GASEnvironment *)penv;
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    GASRectangleObject::GetProperties(
      a1: (int)(this - 1),
      a2: 0.0,
      penv,
      r: (GMemoryHeap *)&v12,
      params: v9,
      a6: v10,
      a7: v11);
    v7 = (tagWNDCLASSW *)GFxRectangle_ComputeTopLeft(
                           a1: &v16,
                           a2: (CTSQueue<CFunctor *,0,1>::Node_t *)penv,
                           a3: v12,
                           a4: v13);
    goto LABEL_4;
  }
  if ( GASString::operator==(this: a3, a2: (const char *)&stru_102A6FE4) )
  {
    v4 = (struct GASEnvironment *)penv;
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    GASRectangleObject::GetProperties(
      a1: (int)(this - 1),
      a2: 0.0,
      penv,
      r: (GMemoryHeap *)&v12,
      params: v9,
      a6: v10,
      a7: v11);
    v7 = (tagWNDCLASSW *)GFxRectangle_ComputeBottomRight(
                           a1: &v16,
                           a2: (CTSQueue<CFunctor *,0,1>::Node_t *)penv,
                           a3: SLODWORD(v12),
                           a4: SHIDWORD(v12),
                           a5: SLODWORD(v13),
                           a6: SHIDWORD(v13),
                           a7: v14,
                           a8: v15);
    goto LABEL_4;
  }
  if ( GASString::operator==(this: a3, a2: "size") )
  {
    v4 = (struct GASEnvironment *)penv;
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    GASRectangleObject::GetProperties(
      a1: (int)(this - 1),
      a2: 0.0,
      penv,
      r: (GMemoryHeap *)&v12,
      params: v9,
      a6: v10,
      a7: v11);
    v7 = (tagWNDCLASSW *)GFxRectangle_ComputeSize(
                           a1: &v16,
                           a2: (CTSQueue<CFunctor *,0,1>::Node_t *)penv,
                           a3: v12,
                           a4: v13,
                           a5: v14,
                           a6: v15);
    goto LABEL_4;
  }
  return (unsigned __int8)GASObject::GetMember(
                            this,
                            result: (ID3DXFont *)penv,
                            penv: (_IMAGE_SYMBOL_EX *)a3,
                            val: (int *)a4);
}

//------------------------------------------------------------------------------
// Address: 0x1012A230
// Name: public: static void GASRectangleProto::Clone(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::Clone(int a1@<ebx>, const char *a2@<esi>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // edx
  GASObject *v6; // eax
  int v7; // esi
  GASFnCall v8; // ebx
  vc_attributes::PreRangeAttribute *cbSize; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v11; // edi
  int i; // ebx
  struct GASStringNode *v13; // [esp-10h] [ebp-60h]
  int v16; // [esp+4h] [ebp-4Ch] BYREF
  int *p_cxItem; // [esp+8h] [ebp-48h]
  int params[4]; // [esp+Ch] [ebp-44h] BYREF
  char v19; // [esp+1Ch] [ebp-34h]
  char v20; // [esp+2Ch] [ebp-24h]
  char v21; // [esp+3Ch] [ebp-14h]
  int v22; // [esp+4Ch] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x11u) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
      p_cxItem = &v3[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = *(_DWORD *)(a3[6][3].cbSize + 656);
    v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
    v16 = 323;
    v6 = (GASObject *)v5(a1: v4, a2: 52, a3: &v16);
    v7 = (int)v6;
    if ( v6 != nullptr )
    {
      v8 = a3[6];
      GASObject::GASObject(this: v6, a2: (struct GASEnvironment *)v8);
      *(_DWORD *)v7 = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
      *(_DWORD *)(v7 + 16) = &off_102A6FF8;
      cbSize = (vc_attributes::PreRangeAttribute *)v8[3].cbSize;
      v8 += 3;
      Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                        this: cbSize,
                                                        result: (vc_attributes::InvalidCheckAttribute *)0xF);
      GASObject::Set__proto__(
        this: (CTSQueue<CFunctor *,0,1> *)(v7 + 16),
        psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v8,
        psc_4: Prototype);
      GASRectangleObject::SetProperties(
        this: (char *)v7,
        psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)v8,
        a3: &GFxRectangle_DefaultParams);
    }
    else
    {
      v7 = 0;
    }
    v13 = (struct GASStringNode *)&a3[6][3];
    LOBYTE(params[0]) = 0;
    v19 = 0;
    v20 = 0;
    v21 = 0;
    GASRectangleObject::GetProperties(a1: (int)p_cxItem, psc: v13, (int)params, psc_8: a2, psc_12: a1);
    GASRectangleObject::SetProperties(
      this: (char *)v7,
      psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)&a3[6][3],
      a3: (GMemoryHeap *)params);
    GASValue::SetAsObject(this: (GASValue *)a3[1], a2: (struct GASObject *)v7);
    v11 = (GASValue *)&v22;
    for ( i = 3; i >= 0; --i )
    {
      v11 -= 4;
      GASValue::~GASValue(this: v11, a2: (int)v11);
    }
    if ( v7 != 0 )
      GRefCountBaseGC<323>::Release(a1: v7, a2: (int)v11);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "Rectangle", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A360
// Name: public: static void GASRectangleProto::Equals(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::Equals(int a1@<edi>, GASFnCall *a2)
{
  bool v2; // bl
  GASValue *v3; // eax
  struct GASObject *v4; // eax
  GASFnCall v5; // eax
  int p_cxItem; // ecx
  int v7; // edx
  _SERVICE_STATUS *v8; // edx
  long double v9; // st7
  GASFnCall v10; // esi
  const struct GASEnvironment *v11; // [esp-4h] [ebp-50h]
  int v12; // [esp+0h] [ebp-4Ch]
  int v13; // [esp+0h] [ebp-4Ch]
  const char *v14; // [esp+4h] [ebp-48h]
  const char *v15; // [esp+4h] [ebp-48h]
  int v16; // [esp+8h] [ebp-44h]
  int v17; // [esp+8h] [ebp-44h]
  double v18; // [esp+Ch] [ebp-40h] BYREF
  double v19; // [esp+14h] [ebp-38h]
  double v20; // [esp+1Ch] [ebp-30h]
  double v21; // [esp+24h] [ebp-28h]
  double v22; // [esp+2Ch] [ebp-20h] BYREF
  double v23; // [esp+34h] [ebp-18h]
  double v24; // [esp+3Ch] [ebp-10h]
  double v25; // [esp+44h] [ebp-8h]

  v2 = false;
  if ( (int)a2[7] > 0 )
  {
    v11 = (const struct GASEnvironment *)a2[6];
    v3 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
    v4 = GASValue::ToObject(this: v3, a2: a1, a3: v11);
    a1 = (int)v4;
    if ( v4 != nullptr && ((int (__thiscall *)(struct GASObject *))v4[2].pNode[1].pNext)(a1: &v4[2]) == 17 )
    {
      if ( !GASFnCall::CheckThisPtr(this: a2, type: 0x11u) )
      {
        GASFnCall::ThisPtrError(this: a2, a2: "Rectangle", a3: nullptr, a4: 0);
        return;
      }
      v5 = a2[2];
      if ( v5 != nullptr )
        p_cxItem = (int)&v5[-1].cxItem;
      else
        p_cxItem = 0;
      v7 = *(_DWORD *)(a1 + 8) + 1;
      v22 = 0.0;
      v23 = 0.0;
      v24 = 0.0;
      v25 = 0.0;
      *(_DWORD *)(a1 + 8) = v7 & 0x8FFFFFFF;
      v8 = (_SERVICE_STATUS *)a2[6];
      v18 = 0.0;
      v19 = 0.0;
      v20 = 0.0;
      v21 = 0.0;
      GASRectangleObject::GetProperties(
        a1: p_cxItem,
        a2: 0.0,
        penv: v8,
        r: (GMemoryHeap *)&v22,
        params: v12,
        a6: v14,
        a7: v16);
      GASRectangleObject::GetProperties(
        a1,
        a2: v9,
        penv: (_SERVICE_STATUS *)a2[6],
        r: (GMemoryHeap *)&v18,
        params: v13,
        a6: v15,
        a7: v17);
      v2 = v18 == v22 && v20 == v24 && v19 == v23 && v21 == v25;
      GRefCountBaseGC<323>::Release(a1, a2: a1);
    }
  }
  v10 = a2[1];
  GASValue::DropRefs(this: (GASValue *)v10, a2: a1);
  LOBYTE(v10->cItems) = v2;
  LOBYTE(v10->cbSize) = 2;
}

//------------------------------------------------------------------------------
// Address: 0x1012A480
// Name: public: static void GASRectangleProto::Intersection(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::Intersection(const char *a1@<ebx>, int a2@<esi>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  int p_cxItem; // ebx
  GASValue *v5; // eax
  struct GASObject *v6; // esi
  _SERVICE_STATUS *v7; // edx
  long double v8; // st7
  double v9; // st7
  double v10; // st6
  double v11; // st5
  double v12; // st4
  double v13; // rtt
  double v14; // st4
  double v15; // st5
  double v16; // rt0
  double v17; // st5
  double v18; // st7
  GASValue *v19; // esi
  int i; // ebx
  int v21; // ecx
  int (__thiscall *v22)(int, int, unsigned int *); // eax
  GASObject *v23; // eax
  int v24; // esi
  GASFnCall v25; // ebx
  vc_attributes::PreRangeAttribute *cbSize; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  const struct GASEnvironment *v28; // [esp-Ch] [ebp-ACh]
  int v29; // [esp-8h] [ebp-A8h]
  int v31; // [esp+0h] [ebp-A0h]
  double v32; // [esp+4h] [ebp-9Ch]
  double v33; // [esp+Ch] [ebp-94h]
  GMemoryHeap r; // [esp+14h] [ebp-8Ch] BYREF
  GASValue v35; // [esp+7Ch] [ebp-24h] BYREF
  GASValue v36; // [esp+8Ch] [ebp-14h] BYREF
  int v37; // [esp+9Ch] [ebp-4h] BYREF

  *(double *)&r.Info.Desc.Reserve = 0.0;
  *(double *)&r.Info.Desc.Limit = 0.0;
  *(double *)&r.Info.Desc.Arena = 0.0;
  *(double *)&r.Info.pName = 0.0;
  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x11u) )
  {
    v3 = a3[2];
    v29 = a2;
    if ( v3 != nullptr )
      p_cxItem = (int)&v3[-1].cxItem;
    else
      p_cxItem = 0;
    if ( (int)a3[7] > 0 )
    {
      v28 = (const struct GASEnvironment *)a3[6];
      v5 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
      v6 = GASValue::ToObject(this: v5, a2: (int)a3, a3: v28);
      if ( v6 != nullptr )
      {
        v7 = (_SERVICE_STATUS *)a3[6];
        *(double *)&r.__vftable = 0.0;
        *(double *)&r.pNext = 0.0;
        *(double *)&r.RefCount = 0.0;
        *(double *)&r.pAutoRelease = 0.0;
        LOBYTE(r.ChildHeaps.Root.pNext) = 0;
        LOBYTE(r.HeapLock.cs.OwningThread) = 0;
        LOBYTE(v35) = 0;
        LOBYTE(v36) = 0;
        GASRectangleObject::GetProperties(a1: p_cxItem, a2: 0.0, penv: v7, &r, params: v29, a6: a1, a7: v31);
        GFxObject_GetRectangleProperties(a1: (int)&r.ChildHeaps.Root.pNext, a2: (int)v6, a3: (int)a3[6]);
        v32 = GASValue::ToNumber(this: &v35, a2: (int)a3, a3: v8, result: (_SERVICE_STATUS *)a3[6]);
        v33 = GASValue::ToNumber(this: &v36, a2: (int)a3, a3: v32, result: (_SERVICE_STATUS *)a3[6]);
        *(double *)&r.Info.Desc.MinAlign = GASValue::ToNumber(
                                             this: (GASValue *)&r.ChildHeaps.Root.pNext,
                                             a2: (int)a3,
                                             a3: v33,
                                             result: (_SERVICE_STATUS *)a3[6]);
        v9 = GASValue::ToNumber(
               this: (GASValue *)&r.HeapLock.cs.OwningThread,
               a2: (int)a3,
               a3: *(long double *)&r.Info.Desc.MinAlign,
               result: (_SERVICE_STATUS *)a3[6]);
        v10 = *(double *)&r.Info.Desc.MinAlign;
        v11 = v32 + *(double *)&r.Info.Desc.MinAlign;
        v12 = v33 + v9;
        if ( *(double *)&r.pAutoRelease >= v9
          && *(double *)&r.pNext <= v12
          && *(double *)&r.__vftable <= v11
          && *(double *)&r.RefCount >= *(double *)&r.Info.Desc.MinAlign )
        {
          if ( *(double *)&r.__vftable > *(double *)&r.Info.Desc.MinAlign )
            v10 = *(double *)&r.__vftable;
          *(double *)&r.Info.Desc.Reserve = v10;
          if ( *(double *)&r.RefCount <= v11 )
            v11 = *(double *)&r.RefCount;
          v13 = v12;
          v14 = v11;
          v15 = v13;
          *(double *)&r.Info.Desc.Arena = v14;
          if ( *(double *)&r.pNext > v9 )
            v9 = *(double *)&r.pNext;
          v16 = v15;
          v17 = v9;
          v18 = v16;
          *(double *)&r.Info.Desc.Limit = v17;
          if ( *(double *)&r.pAutoRelease <= v16 )
            *(double *)&r.Info.pName = *(double *)&r.pAutoRelease;
          else
            *(double *)&r.Info.pName = v18;
        }
        if ( 0.0 == *(double *)&r.Info.Desc.Arena - *(double *)&r.Info.Desc.Reserve
          || 0.0 == *(double *)&r.Info.pName - *(double *)&r.Info.Desc.Limit )
        {
          *(double *)&r.Info.Desc.Reserve = 0.0;
          *(double *)&r.Info.Desc.Limit = 0.0;
          *(double *)&r.Info.Desc.Arena = 0.0;
          *(double *)&r.Info.pName = 0.0;
        }
        v19 = (GASValue *)&v37;
        for ( i = 3; i >= 0; --i )
        {
          v19 -= 4;
          GASValue::~GASValue(this: v19, a2: (int)a3);
        }
      }
    }
    v21 = *(_DWORD *)(a3[6][3].cbSize + 656);
    v22 = *(int (__thiscall **)(int, int, unsigned int *))(*(_DWORD *)v21 + 40);
    r.Info.Desc.Granularity = 323;
    v23 = (GASObject *)v22(a1: v21, a2: 52, a3: &r.Info.Desc.Granularity);
    v24 = (int)v23;
    if ( v23 != nullptr )
    {
      v25 = a3[6];
      GASObject::GASObject(this: v23, a2: (struct GASEnvironment *)v25);
      *(_DWORD *)v24 = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
      *(_DWORD *)(v24 + 16) = &off_102A6FF8;
      cbSize = (vc_attributes::PreRangeAttribute *)v25[3].cbSize;
      v25 += 3;
      Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                        this: cbSize,
                                                        result: (vc_attributes::InvalidCheckAttribute *)0xF);
      GASObject::Set__proto__(
        this: (CTSQueue<CFunctor *,0,1> *)(v24 + 16),
        psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v25,
        psc_4: Prototype);
      GASRectangleObject::SetProperties(
        this: (char *)v24,
        psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)v25,
        a3: &GFxRectangle_DefaultParams);
    }
    else
    {
      v24 = 0;
    }
    GASRectangleObject::SetProperties(
      a1: v24,
      a2: (int)a3,
      penv: (unsigned int)a3[6],
      r: (GMemoryHeap *)&r.Info.Desc.Reserve,
      a5: v29);
    GASValue::SetAsObject(this: (GASValue *)a3[1], a2: (struct GASObject *)v24);
    if ( v24 != 0 )
      GRefCountBaseGC<323>::Release(a1: v24, a2: (int)a3);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "Rectangle", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A740
// Name: public: static void GASRectangleProto::Union(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASRectangleProto::Union(const char *a1@<ebx>, int a2@<edi>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  int v4; // ecx
  int (__thiscall *v5)(int, int, char **); // edx
  GASObject *v6; // eax
  int v7; // edi
  GASFnCall v8; // ebx
  vc_attributes::PreRangeAttribute *cbSize; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v11; // eax
  struct GASObject *v12; // ebx
  _SERVICE_STATUS *v13; // edx
  long double v14; // st7
  double v15; // st7
  double v16; // st5
  double v17; // st6
  double v18; // st5
  long double v19; // st6
  long double v20; // rt2
  double v21; // st6
  long double v22; // st7
  _SERVICE_STATUS *v23; // ecx
  double v24; // st7
  GViewport *v25; // ecx
  char v26; // al
  unsigned __int64 v27; // st7
  GViewport *v28; // ecx
  char v29; // al
  GASValue *v30; // ebx
  const struct GASEnvironment *v31; // [esp+Ch] [ebp-B0h]
  int v32; // [esp+10h] [ebp-ACh]
  int v34; // [esp+18h] [ebp-A4h]
  double v35; // [esp+1Ch] [ebp-A0h]
  long double v36; // [esp+24h] [ebp-98h]
  GMemoryHeap r; // [esp+2Ch] [ebp-90h] BYREF
  GASValue v38; // [esp+98h] [ebp-24h] BYREF
  GASValue v39; // [esp+A8h] [ebp-14h] BYREF
  int v40; // [esp+B8h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x11u) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
      r.ChildHeaps.Root.pNext = (GMemoryHeap *)&v3[-1].cxItem;
    else
      r.ChildHeaps.Root.pNext = nullptr;
    v4 = *(_DWORD *)(a3[6][3].cbSize + 656);
    v5 = *(int (__thiscall **)(int, int, char **))(*(_DWORD *)v4 + 40);
    v32 = a2;
    r.Info.pName = (char *)323;
    v6 = (GASObject *)v5(a1: v4, a2: 52, a3: &r.Info.pName);
    v7 = (int)v6;
    if ( v6 != nullptr )
    {
      v8 = a3[6];
      GASObject::GASObject(this: v6, a2: (struct GASEnvironment *)v8);
      *(_DWORD *)v7 = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
      *(_DWORD *)(v7 + 16) = &off_102A6FF8;
      cbSize = (vc_attributes::PreRangeAttribute *)v8[3].cbSize;
      v8 += 3;
      Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                        this: cbSize,
                                                        result: (vc_attributes::InvalidCheckAttribute *)0xF);
      GASObject::Set__proto__(
        this: (CTSQueue<CFunctor *,0,1> *)(v7 + 16),
        psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v8,
        psc_4: Prototype);
      GASRectangleObject::SetProperties(
        this: (char *)v7,
        psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)v8,
        a3: &GFxRectangle_DefaultParams);
    }
    else
    {
      v7 = 0;
    }
    GASValue::SetAsObject(this: (GASValue *)a3[1], a2: (struct GASObject *)v7);
    if ( (int)a3[7] <= 0 )
    {
      GASRectangleObject::SetProperties(
        this: (char *)v7,
        psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)&a3[6][3],
        a3: &GFxRectangle_NaNParams);
    }
    else
    {
      *(double *)&r.Info.Desc.MinAlign = GASNumberUtil::NaN();
      *(double *)&r.Info.Desc.Reserve = GASNumberUtil::NaN();
      *(double *)&r.Info.Desc.Limit = GASNumberUtil::NaN();
      *(double *)&r.Info.Desc.Arena = GASNumberUtil::NaN();
      v31 = (const struct GASEnvironment *)a3[6];
      v11 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
      v12 = GASValue::ToObject(this: v11, a2: v7, a3: v31);
      if ( v12 != nullptr )
      {
        v13 = (_SERVICE_STATUS *)a3[6];
        *(double *)&r.__vftable = 0.0;
        *(double *)&r.pNext = 0.0;
        *(double *)&r.RefCount = 0.0;
        *(double *)&r.pAutoRelease = 0.0;
        LOBYTE(r.HeapLock.cs.DebugInfo) = 0;
        LOBYTE(r.HeapLock.cs.LockSemaphore) = 0;
        LOBYTE(v38) = 0;
        LOBYTE(v39) = 0;
        GASRectangleObject::GetProperties(
          a1: (int)r.ChildHeaps.Root.pNext,
          a2: 0.0,
          penv: v13,
          &r,
          params: v32,
          a6: a1,
          a7: v34);
        GFxObject_GetRectangleProperties(a1: (int)&r.HeapLock, a2: (int)v12, a3: (int)a3[6]);
        v35 = GASValue::ToNumber(this: &v38, a2: v7, a3: v14, result: (_SERVICE_STATUS *)a3[6]);
        v36 = GASValue::ToNumber(this: &v39, a2: v7, a3: v35, result: (_SERVICE_STATUS *)a3[6]);
        *(double *)&r.ChildHeaps = GASValue::ToNumber(
                                     this: (GASValue *)&r.HeapLock,
                                     a2: v7,
                                     a3: v36,
                                     result: (_SERVICE_STATUS *)a3[6]);
        v15 = GASValue::ToNumber(
                this: (GASValue *)&r.HeapLock.cs.LockSemaphore,
                a2: v7,
                a3: *(long double *)&r.ChildHeaps,
                result: (_SERVICE_STATUS *)a3[6]);
        v16 = *(double *)&r.ChildHeaps;
        v17 = v35 + *(double *)&r.ChildHeaps;
        if ( *(double *)&r.__vftable <= *(double *)&r.ChildHeaps )
          v16 = *(double *)&r.__vftable;
        *(double *)&r.Info.Desc.MinAlign = v16;
        if ( *(double *)&r.RefCount > v17 )
          v17 = *(double *)&r.RefCount;
        v18 = v17;
        v19 = v36 + v15;
        *(double *)&r.Info.Desc.Limit = v18;
        if ( *(double *)&r.pNext <= v15 )
          v15 = *(double *)&r.pNext;
        v20 = v19;
        v21 = v15;
        v22 = v20;
        *(double *)&r.Info.Desc.Reserve = v21;
        if ( *(double *)&r.pAutoRelease > v20 )
          v22 = *(double *)&r.pAutoRelease;
        v23 = (_SERVICE_STATUS *)a3[6];
        *(double *)&r.Info.Desc.Arena = v22;
        v24 = GASValue::ToNumber(this: (GASValue *)&r.HeapLock, a2: v7, a3: v22, result: v23);
        GASNumberUtil::IsNaN(v: v25, u: SLODWORD(v24), u_4: HIDWORD(*(unsigned __int64 *)&v24));
        if ( v26 != 0 )
        {
          v24 = GASNumberUtil::NaN();
          *(double *)&r.Info.Desc.MinAlign = v24;
        }
        *(double *)&v27 = GASValue::ToNumber(
                            this: (GASValue *)&r.HeapLock.cs.LockSemaphore,
                            a2: v7,
                            a3: v24,
                            result: (_SERVICE_STATUS *)a3[6]);
        GASNumberUtil::IsNaN(v: v28, u: v27, u_4: HIDWORD(v27));
        if ( v29 != 0 )
          *(double *)&r.Info.Desc.Reserve = GASNumberUtil::NaN();
        v30 = (GASValue *)&v40;
        r.ChildHeaps.Root.pNext = (GMemoryHeap *)3;
        do
        {
          v30 -= 4;
          GASValue::~GASValue(this: v30, a2: v7);
          --r.ChildHeaps.Root.pNext;
        }
        while ( (int)r.ChildHeaps.Root.pNext >= 0 );
      }
      GASRectangleObject::SetProperties(
        a1: v7,
        a2: v7,
        penv: (unsigned int)a3[6],
        r: (GMemoryHeap *)&r.Info.Desc.MinAlign,
        a5: v32);
    }
    if ( v7 != 0 )
      GRefCountBaseGC<323>::Release(a1: v7, a2: v7);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "Rectangle", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A9F0
// Name: public: static void GASRectangleCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASRectangleCtorFunction::GlobalCtor(int a1@<edi>, int fna)
{
  int v3; // eax
  struct GASObject *v4; // eax
  struct GASObject *v5; // ebx
  int v6; // ecx
  int (__thiscall *v7)(int, int, int *); // edx
  GASObject *v8; // eax
  int v9; // ebx
  vc_attributes::PreRangeAttribute *v10; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  tagWNDCLASSW *v12; // eax
  tagWNDCLASSW *v13; // eax
  tagWNDCLASSW *v14; // eax
  tagWNDCLASSW *v15; // eax
  GASValue *v16; // esi
  int v17; // [esp+Ch] [ebp-48h] BYREF
  _BYTE v18[16]; // [esp+10h] [ebp-44h] BYREF
  _BYTE v19[16]; // [esp+20h] [ebp-34h] BYREF
  _BYTE v20[16]; // [esp+30h] [ebp-24h] BYREF
  _BYTE v21[16]; // [esp+40h] [ebp-14h] BYREF
  int v22; // [esp+50h] [ebp-4h] BYREF

  if ( *(_DWORD *)(fna + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fna + 8) + 8))(a1: *(_DWORD *)(fna + 8)) == 17
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(fna + 8) + 64))(a1: *(_DWORD *)(fna + 8)) == 0 )
  {
    v3 = *(_DWORD *)(fna + 8);
    if ( v3 != 0 )
    {
      v4 = (struct GASObject *)(v3 - 16);
      if ( v4 != nullptr )
        v4[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v4[1].pNode->pNext + 1) & 0x8FFFFFFF);
      v5 = v4;
    }
    else
    {
      v5 = nullptr;
    }
  }
  else
  {
    v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fna + 24) + 120) + 656);
    v7 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v6 + 40);
    v17 = 323;
    v8 = (GASObject *)v7(a1: v6, a2: 52, a3: &v17);
    a1 = (int)v8;
    if ( v8 != nullptr )
    {
      v9 = *(_DWORD *)(fna + 24);
      GASObject::GASObject(this: v8, a2: (struct GASEnvironment *)v9);
      *(_DWORD *)a1 = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
      *(_DWORD *)(a1 + 16) = &off_102A6FF8;
      v10 = *(vc_attributes::PreRangeAttribute **)(v9 + 120);
      v9 += 120;
      Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                        this: v10,
                                                        result: (vc_attributes::InvalidCheckAttribute *)0xF);
      GASObject::Set__proto__(
        this: (CTSQueue<CFunctor *,0,1> *)(a1 + 16),
        psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v9,
        psc_4: Prototype);
      GASRectangleObject::SetProperties(
        this: (char *)a1,
        psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)v9,
        a3: &GFxRectangle_DefaultParams);
    }
    else
    {
      a1 = 0;
    }
    v5 = (struct GASObject *)a1;
  }
  GASValue::SetAsObject(this: *(GASValue **)(fna + 4), a2: v5);
  if ( *(int *)(fna + 28) > 0 )
  {
    v18[0] = 0;
    v19[0] = 0;
    v20[0] = 0;
    v21[0] = 0;
    v12 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    GASValue::operator=(this: (int)v18, v: v12);
    a1 = 3;
    if ( *(int *)(fna + 28) > 1 )
    {
      v13 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
      GASValue::operator=(this: (int)v19, v: v13);
      if ( *(int *)(fna + 28) > 2 )
      {
        v14 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 2);
        GASValue::operator=(this: (int)v20, v: v14);
        if ( *(int *)(fna + 28) > 3 )
        {
          v15 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 3);
          GASValue::operator=(this: (int)v21, v: v15);
        }
      }
    }
    GASRectangleObject::SetProperties(
      this: (char *)v5,
      psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)(*(_DWORD *)(fna + 24) + 120),
      a3: (GMemoryHeap *)v18);
    v16 = (GASValue *)&v22;
    do
    {
      v16 -= 4;
      GASValue::~GASValue(this: v16, a2: a1--);
    }
    while ( a1 >= 0 );
  }
  if ( v5 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v5, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1012AB80
// Name: public: virtual class GASObject __near * GASRectangleCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASRectangleCtorFunction::CreateNewObject(
        GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *this,
        int penv)
{
  struct GASEnvironment *v2; // ebx
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  vc_attributes::PreRangeAttribute **v5; // edi
  GASObject *v6; // eax
  GASObject *v7; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  v2 = (struct GASEnvironment *)penv;
  v3 = *(_DWORD *)(*(_DWORD *)(penv + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  v5 = (vc_attributes::PreRangeAttribute **)(penv + 120);
  penv = 323;
  v6 = (GASObject *)v4(a1: v3, a2: 52, a3: &penv);
  v7 = v6;
  if ( v6 != nullptr )
  {
    GASObject::GASObject(this: v6, a2: v2);
    v7->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
    v7[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&off_102A6FF8;
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: *v5,
                                                      result: (vc_attributes::InvalidCheckAttribute *)0xF);
    GASObject::Set__proto__(
      this: (CTSQueue<CFunctor *,0,1> *)&v7[2],
      psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v5,
      psc_4: Prototype);
    GASRectangleObject::SetProperties(
      this: (char *)v7,
      psc: (const UtlRBTreeNode_t<char const *,unsigned short> *)v5,
      a3: &GFxRectangle_DefaultParams);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012AC80
// Name: public: GASRectangleProto::GASRectangleProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::ISurface *__userpurge GASRectangleProto::GASRectangleProto@<eax>(
        vgui::ISurface *this@<ecx>,
        int a2@<edi>,
        struct GASStringContext *psc,
        struct GASObject *ConstStringNode,
        const struct GASFunctionRef *a5)
{
  int v6; // eax
  struct GASObject *v7; // eax
  bool v8; // zf
  int v9; // ecx
  struct GASObject *v10; // eax
  int v11; // edx
  struct GASObject *v12; // eax
  int v13; // eax
  struct GASObject *v14; // eax
  int v15; // ecx
  struct GASObject *v16; // eax
  int v17; // edx
  struct GASObject *v18; // eax
  int v19; // eax
  struct GASObject *v20; // eax
  GASValue v22; // [esp+Ch] [ebp-10h] BYREF
  int v23; // [esp+10h] [ebp-Ch]

  GASPrototype<GASRectangleObject,GASEnvironment>::GASPrototype<GASRectangleObject,GASEnvironment>(
    this,
    psc,
    psc_4: (CTSQueue<CFunctor *,0,1>::Node_t *)ConstStringNode,
    psc_8: (unsigned int)a5);
  this->__vftable = (vgui::ISurface_vtbl *)&GASRectangleProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASRectangleProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASRectangleProto::`vftable';
  HIBYTE(a5) = 6;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 13,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)psc,
    flags_4: (const struct GASNameFunction *)&GASRectangleProto::FunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&a5 + 3));
  v6 = *(_DWORD *)psc;
  HIBYTE(a5) = 2;
  LOBYTE(v22) = 4;
  v23 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v6 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"left",
                                          a3: 4u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: psc,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v22,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v7 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v7);
  GASValue::~GASValue(this: &v22, a2);
  v9 = *(_DWORD *)psc;
  HIBYTE(a5) = 2;
  LOBYTE(v22) = 4;
  v23 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v9 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"top",
                                          a3: 3u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: psc,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v22,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v10 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v10);
  GASValue::~GASValue(this: &v22, a2);
  v11 = *(_DWORD *)psc;
  HIBYTE(a5) = 2;
  LOBYTE(v22) = 4;
  v23 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v11 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"right",
                                          a3: 5u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: psc,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v22,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v12 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v12);
  GASValue::~GASValue(this: &v22, a2);
  v13 = *(_DWORD *)psc;
  HIBYTE(a5) = 2;
  LOBYTE(v22) = 4;
  v23 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v13 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3488.m_Size,
                                          a3: 6u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: psc,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v22,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v14 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v14);
  GASValue::~GASValue(this: &v22, a2);
  v15 = *(_DWORD *)psc;
  HIBYTE(a5) = 2;
  LOBYTE(v22) = 4;
  v23 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v15 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6FE4.m_Size,
                                          a3: 7u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: psc,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v22,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v16 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v16);
  GASValue::~GASValue(this: &v22, a2);
  v17 = *(_DWORD *)psc;
  HIBYTE(a5) = 2;
  LOBYTE(v22) = 4;
  v23 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v17 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6FE4,
                                          a3: 0xBu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: psc,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v22,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v18 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v18);
  GASValue::~GASValue(this: &v22, a2);
  v19 = *(_DWORD *)psc;
  HIBYTE(a5) = 2;
  LOBYTE(v22) = 4;
  v23 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v19 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"size",
                                          a3: 4u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: psc,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v22,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v20 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v20);
  GASValue::~GASValue(this: &v22, a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012AF40
// Name: public: static class GASFunctionRef GASRectangleCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASRectangleCtorFunction::Register(struct GASFunctionRef *a1, _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // esi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // edi
  GASCFunctionObject *v7; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v10)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  vgui::ISurface *v11; // ebx
  vc_attributes::InvalidCheckAttribute *Prototype; // eax
  vgui::ISurface *v13; // ebx
  unsigned int Deref; // edx
  GASValue *v15; // eax
  GASValue v17[4]; // [esp+Ch] [ebp-18h] BYREF
  vgui::ISurface::SurfaceFeature_t psc; // [esp+1Ch] [ebp-8h] BYREF
  char v19; // [esp+20h] [ebp-4h]
  struct GASFunctionRef *v20; // [esp+2Ch] [ebp+8h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  psc = (vgui::ISurface::SurfaceFeature_t)pgc;
  v19 = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASCFunctionObject *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&psc,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASRectangleCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASRectangleCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  *(_DWORD *)a1 = v7;
  *((_BYTE *)a1 + 8) = 0;
  *((_DWORD *)a1 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v10 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)MaxVal + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v11 = (vgui::ISurface *)v10(a1: MaxVal, a2: 84, a3: &pgc);
  if ( v11 != nullptr )
  {
    Prototype = GASGlobalContext::GetPrototype(this: v2, result: (vc_attributes::InvalidCheckAttribute *)1);
    v13 = GASRectangleProto::GASRectangleProto(
            this: v11,
            a2: (int)a1,
            (struct GASStringContext *)&psc,
            ConstStringNode: (struct GASObject *)Prototype,
            a5: a1);
  }
  else
  {
    v13 = nullptr;
  }
  if ( v13 != nullptr )
    v13[2].__vftable = (vgui::ISurface_vtbl *)(((int)&v13[2].Connect + 1) & 0x8FFFFFFF);
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)a1, a3: 15, a4: (int)v13);
  Deref = v2[55].Deref;
  HIBYTE(pgc) = 0;
  v20 = *(struct GASFunctionRef **)(Deref + 16);
  v15 = GASValue::GASValue(this: v17, a2: (int)a1, a3: a1);
  (*((void (__thiscall **)(unsigned int, vgui::ISurface::SurfaceFeature_t *, const char **, GASValue *, char *))v20 + 10))(
    a1: v2[55].Deref + 16,
    a2: &psc,
    a3: &v2[5].MaxVal,
    a4: v15,
    a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v17, a2: (int)a1);
  if ( v13 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v13, a2: (int)a1);
  return a1;
}
