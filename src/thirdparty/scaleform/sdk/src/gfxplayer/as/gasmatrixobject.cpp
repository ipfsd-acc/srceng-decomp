// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasmatrixobject.cpp
// Functions: 21
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasmatrixobject.h"

//------------------------------------------------------------------------------
// Address: 0x10124C90
// Name: public: virtual enum GASObjectInterface::ObjectType GASMatrixObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int __cdecl GASMatrixObject::GetObjectType()
{
  return 15;
}

//------------------------------------------------------------------------------
// Address: 0x10124CA0
// Name: public: class GASValue (__near * GASMatrixObject::GetMatrixAsValuesArray(class GASStringContext __near *,class GASValue (__near *)[6]))[6]
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASMatrixObject::GetMatrixAsValuesArray(
        int a1@<ecx>,
        void *psc,
        GMemAddressStub *marr,
        int psc_8,
        const char *psc_12,
        int psc_16)
{
  void *v6; // edi
  int v7; // esi
  struct GASStringNode *ConstStringNode; // eax
  GMemAddressStub *v9; // ebx
  int v10; // eax
  bool v11; // zf
  GMemAddressStub *v12; // eax
  GMemAddressStub *v13; // eax
  GMemAddressStub *v14; // eax
  GMemAddressStub *v15; // eax
  GMemAddressStub *v16; // eax
  GASValue v17; // [esp+Ch] [ebp-14h] BYREF
  int v18; // [esp+10h] [ebp-10h]
  struct GASStringNode *v19; // [esp+1Ch] [ebp-4h] BYREF

  v6 = psc;
  v7 = a1 + 16;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)psc + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Size,
                      a3: 1u,
                      a4: 0);
  v9 = marr;
  v19 = ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  HIBYTE(psc) = (*(int (__thiscall **)(int, void *, struct GASStringNode **, GMemAddressStub *))(*(_DWORD *)v7 + 44))(
                  a1: v7,
                  a2: psc,
                  a3: &v19,
                  a4: v9);
  v10 = (int)v19;
  v11 = (*((_DWORD *)v19 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v10);
  if ( HIBYTE(psc) == 0 )
  {
    LOBYTE(v17) = 4;
    v18 = 1;
    GASValue::operator=(this: (int)v9, v: (tagWNDCLASSW *)&v17);
    GASValue::~GASValue(this: &v17, a2: (int)v6);
  }
  marr = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                              this: *(GASStringManager **)(*(_DWORD *)v6 + 636),
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968,
                              a3: 1u,
                              a4: 0);
  ++*(_DWORD *)&marr[8];
  HIBYTE(psc) = (*(int (__thiscall **)(int, void *, GMemAddressStub **, GMemAddressStub *))(*(_DWORD *)v7 + 44))(
                  a1: v7,
                  a2: v6,
                  a3: &marr,
                  a4: v9 + 16);
  v12 = marr;
  v11 = (*(_DWORD *)&marr[8])-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: (int)v12);
  if ( HIBYTE(psc) == 0 )
  {
    LOBYTE(v17) = 4;
    v18 = 0;
    GASValue::operator=(this: (int)&v9[16], v: (tagWNDCLASSW *)&v17);
    GASValue::~GASValue(this: &v17, a2: (int)v6);
  }
  marr = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                              this: *(GASStringManager **)(*(_DWORD *)v6 + 636),
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8.m_Memory.m_nGrowSize,
                              a3: 1u,
                              a4: 0);
  ++*(_DWORD *)&marr[8];
  HIBYTE(psc) = (*(int (__thiscall **)(int, void *, GMemAddressStub **, GMemAddressStub *))(*(_DWORD *)v7 + 44))(
                  a1: v7,
                  a2: v6,
                  a3: &marr,
                  a4: v9 + 32);
  v13 = marr;
  v11 = (*(_DWORD *)&marr[8])-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: (int)v13);
  if ( HIBYTE(psc) == 0 )
  {
    LOBYTE(v17) = 4;
    v18 = 0;
    GASValue::operator=(this: (int)&v9[32], v: (tagWNDCLASSW *)&v17);
    GASValue::~GASValue(this: &v17, a2: (int)v6);
  }
  marr = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                              this: *(GASStringManager **)(*(_DWORD *)v6 + 636),
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Memory.m_nGrowSize,
                              a3: 1u,
                              a4: 0);
  ++*(_DWORD *)&marr[8];
  HIBYTE(psc) = (*(int (__thiscall **)(int, void *, GMemAddressStub **, GMemAddressStub *))(*(_DWORD *)v7 + 44))(
                  a1: v7,
                  a2: v6,
                  a3: &marr,
                  a4: v9 + 48);
  v14 = marr;
  v11 = (*(_DWORD *)&marr[8])-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: (int)v14);
  if ( HIBYTE(psc) == 0 )
  {
    LOBYTE(v17) = 4;
    v18 = 1;
    GASValue::operator=(this: (int)&v9[48], v: (tagWNDCLASSW *)&v17);
    GASValue::~GASValue(this: &v17, a2: (int)v6);
  }
  marr = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                              this: *(GASStringManager **)(*(_DWORD *)v6 + 636),
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8.m_Memory.m_nAllocationCount,
                              a3: 2u,
                              a4: 0);
  ++*(_DWORD *)&marr[8];
  HIBYTE(psc) = (*(int (__thiscall **)(int, void *, GMemAddressStub **, GMemAddressStub *))(*(_DWORD *)v7 + 44))(
                  a1: v7,
                  a2: v6,
                  a3: &marr,
                  a4: v9 + 64);
  v15 = marr;
  v11 = (*(_DWORD *)&marr[8])-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: (int)v15);
  if ( HIBYTE(psc) == 0 )
  {
    LOBYTE(v17) = 4;
    v18 = 0;
    GASValue::operator=(this: (int)&v9[64], v: (tagWNDCLASSW *)&v17);
    GASValue::~GASValue(this: &v17, a2: (int)v6);
  }
  marr = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                              this: *(GASStringManager **)(*(_DWORD *)v6 + 636),
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8,
                              a3: 2u,
                              a4: 0);
  ++*(_DWORD *)&marr[8];
  HIBYTE(psc) = (*(int (__thiscall **)(int, void *, GMemAddressStub **, GMemAddressStub *))(*(_DWORD *)v7 + 44))(
                  a1: v7,
                  a2: v6,
                  a3: &marr,
                  a4: v9 + 80);
  v16 = marr;
  v11 = (*(_DWORD *)&marr[8])-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: (int)v16);
  if ( HIBYTE(psc) == 0 )
  {
    LOBYTE(v17) = 4;
    v18 = 0;
    GASValue::operator=(this: (int)&v9[80], v: (tagWNDCLASSW *)&v17);
    GASValue::~GASValue(this: &v17, a2: (int)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124F20
// Name: public: class GMatrix2D GASMatrixObject::GetMatrix(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASMatrixObject::GetMatrix(
        int a1@<ecx>,
        long double a2@<st0>,
        float *penv,
        _SERVICE_STATUS *v,
        const char *a5,
        int a6)
{
  unsigned int dwControlsAccepted; // eax
  GMemAddressStub *p_dwControlsAccepted; // esi
  int v9; // edi
  int v10; // eax
  bool v11; // zf
  double v12; // st7
  int v13; // eax
  double v14; // st7
  int v15; // eax
  double v16; // st7
  int v17; // eax
  double v18; // st7
  int v19; // eax
  double v20; // st7
  int v21; // eax
  int v22; // [esp-Ch] [ebp-30h]
  GASValue va[4]; // [esp+Ch] [ebp-18h] BYREF
  struct GASStringNode *ConstStringNode; // [esp+1Ch] [ebp-8h] BYREF
  char v25; // [esp+23h] [ebp-1h]

  GMatrix2D::SetIdentity(this: penv);
  dwControlsAccepted = v[4].dwControlsAccepted;
  p_dwControlsAccepted = (GMemAddressStub *)&v[4].dwControlsAccepted;
  LOBYTE(va[0]) = 0;
  v9 = a1 + 16;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(dwControlsAccepted + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Size,
                      a3: 1u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  v25 = (*(int (__thiscall **)(int, unsigned int *, struct GASStringNode **, GASValue *))(*(_DWORD *)v9 + 44))(
          a1: v9,
          a2: &v[4].dwControlsAccepted,
          a3: &ConstStringNode,
          a4: va);
  v10 = (int)ConstStringNode;
  v11 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v10);
  if ( v25 != 0 )
  {
    v12 = GASValue::ToNumber(this: va, a2: v9, a3: a2, result: v);
    *penv = v12;
  }
  else
  {
    v12 = 1.0;
    *penv = 1.0;
  }
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)p_dwControlsAccepted + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968,
                      a3: 1u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  v25 = (*(int (__thiscall **)(int, GMemAddressStub *, struct GASStringNode **, GASValue *))(*(_DWORD *)v9 + 44))(
          a1: v9,
          a2: p_dwControlsAccepted,
          a3: &ConstStringNode,
          a4: va);
  v13 = (int)ConstStringNode;
  v11 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v13);
  if ( v25 != 0 )
  {
    v14 = GASValue::ToNumber(this: va, a2: v9, a3: v12, result: v);
    penv[3] = v14;
  }
  else
  {
    v14 = 0.0;
    penv[3] = 0.0;
  }
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)p_dwControlsAccepted + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8.m_Memory.m_nGrowSize,
                      a3: 1u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  v25 = (*(int (__thiscall **)(int, GMemAddressStub *, struct GASStringNode **, GASValue *))(*(_DWORD *)v9 + 44))(
          a1: v9,
          a2: p_dwControlsAccepted,
          a3: &ConstStringNode,
          a4: va);
  v15 = (int)ConstStringNode;
  v11 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v15);
  if ( v25 != 0 )
  {
    v16 = GASValue::ToNumber(this: va, a2: v9, a3: v14, result: v);
    penv[1] = v16;
  }
  else
  {
    v16 = 0.0;
    penv[1] = 0.0;
  }
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)p_dwControlsAccepted + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Memory.m_nGrowSize,
                      a3: 1u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  v25 = (*(int (__thiscall **)(int, GMemAddressStub *, struct GASStringNode **, GASValue *))(*(_DWORD *)v9 + 44))(
          a1: v9,
          a2: p_dwControlsAccepted,
          a3: &ConstStringNode,
          a4: va);
  v17 = (int)ConstStringNode;
  v11 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v17);
  if ( v25 != 0 )
  {
    v18 = GASValue::ToNumber(this: va, a2: v9, a3: v16, result: v);
    penv[4] = v18;
  }
  else
  {
    v18 = 1.0;
    penv[4] = 1.0;
  }
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)p_dwControlsAccepted + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8.m_Memory.m_nAllocationCount,
                      a3: 2u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  v25 = (*(int (__thiscall **)(int, GMemAddressStub *, struct GASStringNode **, GASValue *))(*(_DWORD *)v9 + 44))(
          a1: v9,
          a2: p_dwControlsAccepted,
          a3: &ConstStringNode,
          a4: va);
  v19 = (int)ConstStringNode;
  v11 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v19);
  if ( v25 != 0 )
  {
    v20 = GASValue::ToNumber(this: va, a2: v9, a3: v18, result: v);
    penv[2] = v20;
  }
  else
  {
    v20 = 0.0;
    penv[2] = 0.0;
  }
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)p_dwControlsAccepted + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8,
                      a3: 2u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  v25 = (*(int (__thiscall **)(int, GMemAddressStub *, struct GASStringNode **, GASValue *))(*(_DWORD *)v9 + 44))(
          a1: v9,
          a2: p_dwControlsAccepted,
          a3: &ConstStringNode,
          a4: va);
  v21 = (int)ConstStringNode;
  v11 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v21);
  if ( v25 != 0 )
    penv[5] = GASValue::ToNumber(this: va, a2: v22, a3: v20, result: v);
  else
    penv[5] = 0.0;
  GASValue::~GASValue(this: va, a2: v22);
}

//------------------------------------------------------------------------------
// Address: 0x101251C0
// Name: public: void GASMatrixObject::SetMatrix(class GASEnvironment __near *,class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASMatrixObject::SetMatrix(int a1@<ecx>, int a2@<edi>, _DWORD *penv, GMemAddressStub *ConstStringNode)
{
  float *v4; // ebx
  int v5; // eax
  int *v6; // esi
  int v7; // edi
  GMemAddressStub *v8; // eax
  bool v9; // zf
  int v10; // eax
  GMemAddressStub *v11; // eax
  int v12; // eax
  GMemAddressStub *v13; // eax
  int v14; // eax
  GMemAddressStub *v15; // eax
  int v16; // eax
  GMemAddressStub *v17; // eax
  int v18; // eax
  GMemAddressStub *v19; // eax
  GASValue v21; // [esp+8h] [ebp-10h] BYREF
  double v22; // [esp+Ch] [ebp-Ch]

  v4 = (float *)ConstStringNode;
  v22 = *(float *)ConstStringNode;
  v5 = penv[30];
  v6 = penv + 30;
  LOBYTE(v21) = 3;
  v7 = a1 + 16;
  HIBYTE(penv) = 0;
  ConstStringNode = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                                         this: *(GASStringManager **)(v5 + 636),
                                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Size,
                                         a3: 1u,
                                         a4: 0);
  ++*(_DWORD *)&ConstStringNode[8];
  (*(void (__thiscall **)(int, int *, GMemAddressStub **, GASValue *, char *, int))(*(_DWORD *)v7 + 40))(
    a1: v7,
    a2: v6,
    a3: &ConstStringNode,
    a4: &v21,
    a5: (char *)&penv + 3,
    a6: a2);
  v8 = ConstStringNode;
  v9 = (*(_DWORD *)&ConstStringNode[8])-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v8);
  GASValue::~GASValue(this: &v21, a2: v7);
  v10 = *v6;
  v22 = v4[3];
  LOBYTE(v21) = 3;
  HIBYTE(penv) = 0;
  ConstStringNode = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                                         this: *(GASStringManager **)(v10 + 636),
                                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968,
                                         a3: 1u,
                                         a4: 0);
  ++*(_DWORD *)&ConstStringNode[8];
  (*(void (__thiscall **)(int, int *, GMemAddressStub **, GASValue *, char *))(*(_DWORD *)v7 + 40))(
    a1: v7,
    a2: v6,
    a3: &ConstStringNode,
    a4: &v21,
    a5: (char *)&penv + 3);
  v11 = ConstStringNode;
  v9 = (*(_DWORD *)&ConstStringNode[8])-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v11);
  GASValue::~GASValue(this: &v21, a2: v7);
  v12 = *v6;
  v22 = v4[1];
  LOBYTE(v21) = 3;
  HIBYTE(penv) = 0;
  ConstStringNode = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                                         this: *(GASStringManager **)(v12 + 636),
                                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8.m_Memory.m_nGrowSize,
                                         a3: 1u,
                                         a4: 0);
  ++*(_DWORD *)&ConstStringNode[8];
  (*(void (__thiscall **)(int, int *, GMemAddressStub **, GASValue *, char *))(*(_DWORD *)v7 + 40))(
    a1: v7,
    a2: v6,
    a3: &ConstStringNode,
    a4: &v21,
    a5: (char *)&penv + 3);
  v13 = ConstStringNode;
  v9 = (*(_DWORD *)&ConstStringNode[8])-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v13);
  GASValue::~GASValue(this: &v21, a2: v7);
  v14 = *v6;
  v22 = v4[4];
  LOBYTE(v21) = 3;
  HIBYTE(penv) = 0;
  ConstStringNode = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                                         this: *(GASStringManager **)(v14 + 636),
                                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Memory.m_nGrowSize,
                                         a3: 1u,
                                         a4: 0);
  ++*(_DWORD *)&ConstStringNode[8];
  (*(void (__thiscall **)(int, int *, GMemAddressStub **, GASValue *, char *))(*(_DWORD *)v7 + 40))(
    a1: v7,
    a2: v6,
    a3: &ConstStringNode,
    a4: &v21,
    a5: (char *)&penv + 3);
  v15 = ConstStringNode;
  v9 = (*(_DWORD *)&ConstStringNode[8])-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v15);
  GASValue::~GASValue(this: &v21, a2: v7);
  v16 = *v6;
  v22 = v4[2];
  LOBYTE(v21) = 3;
  HIBYTE(penv) = 0;
  ConstStringNode = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                                         this: *(GASStringManager **)(v16 + 636),
                                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8.m_Memory.m_nAllocationCount,
                                         a3: 2u,
                                         a4: 0);
  ++*(_DWORD *)&ConstStringNode[8];
  (*(void (__thiscall **)(int, int *, GMemAddressStub **, GASValue *, char *))(*(_DWORD *)v7 + 40))(
    a1: v7,
    a2: v6,
    a3: &ConstStringNode,
    a4: &v21,
    a5: (char *)&penv + 3);
  v17 = ConstStringNode;
  v9 = (*(_DWORD *)&ConstStringNode[8])-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v17);
  GASValue::~GASValue(this: &v21, a2: v7);
  v18 = *v6;
  v22 = v4[5];
  LOBYTE(v21) = 3;
  HIBYTE(penv) = 0;
  ConstStringNode = (GMemAddressStub *)GASStringManager::CreateConstStringNode(
                                         this: *(GASStringManager **)(v18 + 636),
                                         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8,
                                         a3: 2u,
                                         a4: 0);
  ++*(_DWORD *)&ConstStringNode[8];
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v7 + 40))(a1: v7, a2: v6);
  v19 = ConstStringNode;
  v9 = (*(_DWORD *)&ConstStringNode[8])-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v19);
  GASValue::~GASValue(this: &v21, a2: (int)&ConstStringNode);
}

//------------------------------------------------------------------------------
// Address: 0x101253F0
// Name: public: void GASMatrixObject::SetMatrixTwips(class GASStringContext __near *,class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASMatrixObject::SetMatrixTwips(
        int a1@<ecx>,
        struct GASStringNode *psc,
        GMemoryHeap *m,
        const char *psc_8,
        int psc_12)
{
  float *v5; // ebx
  struct GASStringNode *v6; // edi
  int v7; // eax
  int v8; // esi
  struct GASStringNode *v9; // eax
  bool v10; // zf
  int v11; // eax
  struct GASStringNode *v12; // eax
  int v13; // eax
  struct GASStringNode *v14; // eax
  int v15; // eax
  struct GASStringNode *v16; // eax
  double v17; // st7
  int v18; // eax
  struct GASStringNode *v19; // eax
  double v20; // st7
  int v21; // eax
  struct GASStringNode *v22; // eax
  GASValue v23; // [esp+Ch] [ebp-10h] BYREF
  double v24; // [esp+10h] [ebp-Ch]

  v5 = (float *)m;
  v24 = *(float *)&m->__vftable;
  v6 = psc;
  v7 = *(_DWORD *)psc;
  LOBYTE(v23) = 3;
  v8 = a1 + 16;
  HIBYTE(m) = 0;
  psc = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v7 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Size,
          a3: 1u,
          a4: 0);
  ++*((_DWORD *)psc + 2);
  (*(void (__thiscall **)(int, struct GASStringNode *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)v8 + 40))(
    a1: v8,
    a2: v6,
    a3: &psc,
    a4: &v23,
    a5: (char *)&m + 3);
  v9 = psc;
  v10 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v9);
  GASValue::~GASValue(this: &v23, a2: (int)v6);
  v11 = *(_DWORD *)v6;
  v24 = v5[3];
  LOBYTE(v23) = 3;
  HIBYTE(m) = 0;
  psc = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v11 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968,
          a3: 1u,
          a4: 0);
  ++*((_DWORD *)psc + 2);
  (*(void (__thiscall **)(int, struct GASStringNode *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)v8 + 40))(
    a1: v8,
    a2: v6,
    a3: &psc,
    a4: &v23,
    a5: (char *)&m + 3);
  v12 = psc;
  v10 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v12);
  GASValue::~GASValue(this: &v23, a2: (int)v6);
  v13 = *(_DWORD *)v6;
  v24 = v5[1];
  LOBYTE(v23) = 3;
  HIBYTE(m) = 0;
  psc = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v13 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8.m_Memory.m_nGrowSize,
          a3: 1u,
          a4: 0);
  ++*((_DWORD *)psc + 2);
  (*(void (__thiscall **)(int, struct GASStringNode *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)v8 + 40))(
    a1: v8,
    a2: v6,
    a3: &psc,
    a4: &v23,
    a5: (char *)&m + 3);
  v14 = psc;
  v10 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v14);
  GASValue::~GASValue(this: &v23, a2: (int)v6);
  v15 = *(_DWORD *)v6;
  v24 = v5[4];
  LOBYTE(v23) = 3;
  HIBYTE(m) = 0;
  psc = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v15 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Memory.m_nGrowSize,
          a3: 1u,
          a4: 0);
  ++*((_DWORD *)psc + 2);
  (*(void (__thiscall **)(int, struct GASStringNode *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)v8 + 40))(
    a1: v8,
    a2: v6,
    a3: &psc,
    a4: &v23,
    a5: (char *)&m + 3);
  v16 = psc;
  v10 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v16);
  GASValue::~GASValue(this: &v23, a2: (int)v6);
  v17 = v5[2] / 20.0;
  v18 = *(_DWORD *)v6;
  LOBYTE(v23) = 3;
  HIBYTE(m) = 0;
  v24 = v17;
  psc = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v18 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8.m_Memory.m_nAllocationCount,
          a3: 2u,
          a4: 0);
  ++*((_DWORD *)psc + 2);
  (*(void (__thiscall **)(int, struct GASStringNode *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)v8 + 40))(
    a1: v8,
    a2: v6,
    a3: &psc,
    a4: &v23,
    a5: (char *)&m + 3);
  v19 = psc;
  v10 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v19);
  GASValue::~GASValue(this: &v23, a2: (int)v6);
  v20 = v5[5] / 20.0;
  v21 = *(_DWORD *)v6;
  LOBYTE(v23) = 3;
  HIBYTE(m) = 0;
  v24 = v20;
  psc = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v21 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8,
          a3: 2u,
          a4: 0);
  ++*((_DWORD *)psc + 2);
  (*(void (__thiscall **)(int, struct GASStringNode *))(*(_DWORD *)v8 + 40))(a1: v8, a2: v6);
  v22 = psc;
  v10 = (*((_DWORD *)psc + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v22);
  GASValue::~GASValue(this: &v23, a2: (int)&psc);
}

//------------------------------------------------------------------------------
// Address: 0x10125620
// Name: public: static void GASMatrixProto::ToString(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::ToString(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  GASEnvironment *v3; // edi
  unsigned __int8 *v4; // eax
  GASEnvironment *v5; // edi
  unsigned __int8 *v6; // eax
  GASEnvironment *v7; // edi
  unsigned __int8 *v8; // eax
  GASEnvironment *v9; // edi
  unsigned __int8 *v10; // eax
  GASEnvironment *v11; // edi
  unsigned __int8 *v12; // eax
  GASEnvironment *v13; // edi
  unsigned __int8 *v14; // eax
  struct GASStringNode *StringNode; // edi
  GASFnCall v16; // esi
  bool v17; // zf
  void *v18; // esi
  int *v19; // esi
  int i; // edi
  int v21; // ecx
  GASValue *v22; // esi
  int j; // edi
  tagALTTABINFO *v24; // [esp-Ch] [ebp-A4h]
  const char *v25; // [esp+0h] [ebp-98h]
  int v26; // [esp+4h] [ebp-94h]
  GASValue v27[4]; // [esp+8h] [ebp-90h] BYREF
  CUtlMemory<CImagePacker,int> v28; // [esp+18h] [ebp-80h] BYREF
  GASValue v29; // [esp+2Ch] [ebp-6Ch] BYREF
  GASValue v30; // [esp+3Ch] [ebp-5Ch] BYREF
  GASValue v31; // [esp+4Ch] [ebp-4Ch] BYREF
  GASValue v32; // [esp+5Ch] [ebp-3Ch] BYREF
  GASValue v33; // [esp+6Ch] [ebp-2Ch] BYREF
  CImagePacker **v34; // [esp+7Ch] [ebp-1Ch] BYREF
  CImagePacker **v35; // [esp+80h] [ebp-18h] BYREF
  CImagePacker **v36; // [esp+84h] [ebp-14h] BYREF
  CImagePacker **v37; // [esp+88h] [ebp-10h] BYREF
  CImagePacker **v38; // [esp+8Ch] [ebp-Ch] BYREF
  CImagePacker **v39; // [esp+90h] [ebp-8h] BYREF
  int v40; // [esp+94h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0xFu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr && v2 != (GASFnCall)16 )
    {
      v24 = a2[6] + 3;
      LOBYTE(v28.m_nAllocationCount) = 0;
      LOBYTE(v29) = 0;
      LOBYTE(v30) = 0;
      LOBYTE(v31) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v33) = 0;
      GASMatrixObject::GetMatrixAsValuesArray(
        a1: (int)&v2[-1].cxItem,
        psc: v24,
        marr: (GMemAddressStub *)&v28.m_nAllocationCount,
        psc_8: a1,
        psc_12: v25,
        psc_16: v26);
      v3 = (GASEnvironment *)a2[6];
      v4 = (unsigned __int8 *)GASValue::ToPrimitive(
                                this: (GASValue *)&v28.m_nAllocationCount,
                                a2: v27,
                                a3: v3,
                                __formal: 0);
      GASValue::ToStringImpl(
        this: v4,
        a2: (int *)&v34,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)v3,
        precision: 6,
        debug: false);
      GASValue::~GASValue(this: v27, a2: (int)v3);
      v5 = (GASEnvironment *)a2[6];
      v6 = (unsigned __int8 *)GASValue::ToPrimitive(this: &v29, a2: v27, a3: v5, __formal: 0);
      GASValue::ToStringImpl(
        this: v6,
        a2: (int *)&v35,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)v5,
        precision: 6,
        debug: false);
      GASValue::~GASValue(this: v27, a2: (int)v5);
      v7 = (GASEnvironment *)a2[6];
      v8 = (unsigned __int8 *)GASValue::ToPrimitive(this: &v30, a2: v27, a3: v7, __formal: 0);
      GASValue::ToStringImpl(
        this: v8,
        a2: (int *)&v36,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)v7,
        precision: 6,
        debug: false);
      GASValue::~GASValue(this: v27, a2: (int)v7);
      v9 = (GASEnvironment *)a2[6];
      v10 = (unsigned __int8 *)GASValue::ToPrimitive(this: &v31, a2: v27, a3: v9, __formal: 0);
      GASValue::ToStringImpl(
        this: v10,
        a2: (int *)&v37,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)v9,
        precision: 6,
        debug: false);
      GASValue::~GASValue(this: v27, a2: (int)v9);
      v11 = (GASEnvironment *)a2[6];
      v12 = (unsigned __int8 *)GASValue::ToPrimitive(this: &v32, a2: v27, a3: v11, __formal: 0);
      GASValue::ToStringImpl(
        this: v12,
        a2: (int *)&v38,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)v11,
        precision: 6,
        debug: false);
      GASValue::~GASValue(this: v27, a2: (int)v11);
      v13 = (GASEnvironment *)a2[6];
      v14 = (unsigned __int8 *)GASValue::ToPrimitive(this: &v33, a2: v27, a3: v13, __formal: 0);
      GASValue::ToStringImpl(
        this: v14,
        a2: (int *)&v39,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)v13,
        precision: 6,
        debug: false);
      GASValue::~GASValue(this: v27, a2: (int)v13);
      GString::GString(this: &v28);
      GString::AppendString(this: &v28, putf8str: (CImagePacker *)"(a=", utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: *v34, utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: (CImagePacker *)", b=", utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: *v35, utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: (CImagePacker *)", c=", utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: *v36, utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: (CImagePacker *)", d=", utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: *v37, utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: (CImagePacker *)", tx=", utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: *v38, utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: (CImagePacker *)&stru_102A6BD8.m_Size, utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: *v39, utf8StrSz: -1);
      GString::AppendString(this: &v28, putf8str: (CImagePacker *)")", utf8StrSz: -1);
      StringNode = GASStringManager::CreateStringNode(
                     this: *(GASStringManager **)(a2[6][3].cbSize + 636),
                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)v28.m_pMemory
                                                                                               & 0xFFFFFFFC)
                                                                                              + 8),
                     length: *(_DWORD *)((int)v28.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++*((_DWORD *)StringNode + 2);
      v16 = a2[1];
      if ( LOBYTE(v16->cbSize) >= 5u )
        GASValue::DropRefs(this: (GASValue *)v16, a2: (int)StringNode);
      LOBYTE(v16->cbSize) = 5;
      v16->cItems = (int)StringNode;
      v17 = ++*((_DWORD *)StringNode + 2) == 1;
      --*((_DWORD *)StringNode + 2);
      if ( v17 )
        GASStringNode::ReleaseNode(a1: (int)StringNode);
      v18 = (void *)((int)v28.m_pMemory & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v28.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v18);
      v19 = &v40;
      for ( i = 5; i >= 0; --i )
      {
        v21 = *--v19;
        v17 = (*(_DWORD *)(v21 + 8))-- == 1;
        if ( v17 )
          GASStringNode::ReleaseNode(a1: v21);
      }
      v22 = (GASValue *)&v34;
      for ( j = 5; j >= 0; --j )
      {
        v22 -= 4;
        GASValue::~GASValue(this: v22, a2: j);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125950
// Name: public: static void GASMatrixProto::Concat(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::Concat(int a1@<ebx>, const char *a2@<edi>, long double a3@<st0>, GASFnCall *a4)
{
  GASFnCall v4; // eax
  int p_cxItem; // ebx
  GASValue *v6; // eax
  struct GASObject *v7; // edi
  long double v8; // st7
  const struct GMatrix2D *v9; // eax
  const struct GASEnvironment *v10; // [esp-Ch] [ebp-44h]
  const char *v12; // [esp-8h] [ebp-40h]
  int v14; // [esp-4h] [ebp-3Ch]
  float v15[6]; // [esp+4h] [ebp-34h] BYREF
  GMatrix2D penv; // [esp+1Ch] [ebp-1Ch] BYREF

  if ( GASFnCall::CheckThisPtr(this: a4, type: 0xFu) )
  {
    v4 = a4[2];
    if ( v4 != nullptr )
    {
      p_cxItem = (int)&v4[-1].cxItem;
      if ( v4 != (GASFnCall)16 && (int)a4[7] > 0 )
      {
        v10 = (const struct GASEnvironment *)a4[6];
        v6 = (GASValue *)GASFnCall::Arg(this: a4, a2: 0);
        v7 = GASValue::ToObject(this: v6, (int)a2, a3: v10);
        if ( ((int (__thiscall *)(struct GASObject *))v7[2].pNode[1].pNext)(a1: &v7[2]) == 15 )
        {
          GASMatrixObject::GetMatrix(a1: p_cxItem, a2: a3, (float *)&penv, v: (_SERVICE_STATUS *)a4[6], a5: a2, a6: a1);
          GASMatrixObject::GetMatrix(a1: (int)v7, a2: v8, penv: v15, v: (_SERVICE_STATUS *)a4[6], a5: v12, a6: v14);
          GMatrix2D::Append(this: &penv, a2: v9);
          GASMatrixObject::SetMatrix(a1: p_cxItem, a2: (int)v7, penv: a4[6], ConstStringNode: (GMemAddressStub *)&penv);
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a4, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125A20
// Name: public: static void GASMatrixProto::CreateBox(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::CreateBox(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int p_cxItem; // edi
  GASValue *v4; // eax
  double v5; // st7
  GASValue *v6; // eax
  GASValue *v7; // eax
  double v8; // st7
  GASValue *v9; // eax
  double v10; // st7
  GASValue *v11; // eax
  _DWORD *v12; // [esp-Ch] [ebp-60h]
  _SERVICE_STATUS *v13; // [esp-8h] [ebp-5Ch]
  _SERVICE_STATUS *v14; // [esp-8h] [ebp-5Ch]
  _SERVICE_STATUS *v15; // [esp-8h] [ebp-5Ch]
  _SERVICE_STATUS *v16; // [esp-8h] [ebp-5Ch]
  _SERVICE_STATUS *v17; // [esp-8h] [ebp-5Ch]
  float v18; // [esp+4h] [ebp-50h]
  float v19; // [esp+8h] [ebp-4Ch]
  float v20; // [esp+Ch] [ebp-48h]
  float v21; // [esp+10h] [ebp-44h]
  float v22; // [esp+14h] [ebp-40h]
  float v23; // [esp+18h] [ebp-3Ch]
  float v24; // [esp+1Ch] [ebp-38h]
  float v25; // [esp+1Ch] [ebp-38h]
  struct GMatrix2D v26; // [esp+20h] [ebp-34h] BYREF
  GMatrix2D v27; // [esp+38h] [ebp-1Ch] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0xFu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
    {
      p_cxItem = (int)&v2[-1].cxItem;
      if ( v2 != (GASFnCall)16 && (int)a2[7] > 1 )
      {
        GMatrix2D::SetIdentity(this: (float *)&v27);
        v13 = (_SERVICE_STATUS *)a2[6];
        v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
        v5 = GASValue::ToNumber(this: v4, a2: p_cxItem, a3: a1, result: v13);
        v19 = v5;
        v14 = (_SERVICE_STATUS *)a2[6];
        v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
        v18 = GASValue::ToNumber(this: v6, a2: p_cxItem, a3: v5, result: v14);
        v23 = 0.0;
        v21 = 0.0;
        v22 = 0.0;
        if ( (int)a2[7] > 2 )
        {
          v15 = (_SERVICE_STATUS *)a2[6];
          v7 = (GASValue *)GASFnCall::Arg(this: a2, a2: 2);
          v8 = GASValue::ToNumber(this: v7, a2: p_cxItem, a3: 0.0, result: v15);
          v23 = v8;
          if ( (int)a2[7] > 3 )
          {
            v16 = (_SERVICE_STATUS *)a2[6];
            v9 = (GASValue *)GASFnCall::Arg(this: a2, a2: 3);
            v10 = GASValue::ToNumber(this: v9, a2: p_cxItem, a3: v8, result: v16);
            v21 = v10;
            if ( (int)a2[7] > 4 )
            {
              v17 = (_SERVICE_STATUS *)a2[6];
              v11 = (GASValue *)GASFnCall::Arg(this: a2, a2: 4);
              v22 = GASValue::ToNumber(this: v11, a2: p_cxItem, a3: v10, result: v17);
            }
          }
        }
        v24 = cos(v23);
        v20 = v24;
        v25 = sin(v23);
        v26.M_[0][0] = v20;
        v26.M_[0][1] = -v25;
        v26.M_[0][2] = 0.0;
        v26.M_[1][2] = 0.0;
        v26.M_[1][0] = v25;
        v26.M_[1][1] = v20;
        GMatrix2D::Append(this: &v27, a2: &v26);
        v12 = a2[6];
        v27.M_[0][0] = v27.M_[0][0] * v19;
        v27.M_[0][1] = v27.M_[0][1] * v19;
        v27.M_[0][2] = v19 * v27.M_[0][2];
        v27.M_[1][0] = v27.M_[1][0] * v18;
        v27.M_[1][1] = v27.M_[1][1] * v18;
        v27.M_[1][2] = v18 * v27.M_[1][2];
        v27.M_[0][2] = v27.M_[0][2] + v21;
        v27.M_[1][2] = v27.M_[1][2] + v22;
        GASMatrixObject::SetMatrix(a1: p_cxItem, a2: p_cxItem, penv: v12, ConstStringNode: (GMemAddressStub *)&v27);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125BD0
// Name: public: static void GASMatrixProto::CreateGradientBox(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::CreateGradientBox(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int p_cxItem; // edi
  GASValue *v4; // eax
  double v5; // st7
  GASValue *v6; // eax
  long double v7; // st7
  GASValue *v8; // eax
  double v9; // st7
  GASValue *v10; // eax
  long double v11; // st7
  GASValue *v12; // eax
  _DWORD *v13; // [esp-Ch] [ebp-60h]
  _SERVICE_STATUS *v14; // [esp-8h] [ebp-5Ch]
  _SERVICE_STATUS *v15; // [esp-8h] [ebp-5Ch]
  _SERVICE_STATUS *v16; // [esp-8h] [ebp-5Ch]
  _SERVICE_STATUS *v17; // [esp-8h] [ebp-5Ch]
  _SERVICE_STATUS *v18; // [esp-8h] [ebp-5Ch]
  float v19; // [esp+4h] [ebp-50h]
  float v20; // [esp+8h] [ebp-4Ch]
  float v21; // [esp+Ch] [ebp-48h]
  float v22; // [esp+10h] [ebp-44h]
  float v23; // [esp+14h] [ebp-40h]
  float v24; // [esp+14h] [ebp-40h]
  float v25; // [esp+18h] [ebp-3Ch]
  float v26; // [esp+18h] [ebp-3Ch]
  float v27; // [esp+1Ch] [ebp-38h]
  float v28; // [esp+1Ch] [ebp-38h]
  float v29; // [esp+1Ch] [ebp-38h]
  float v30; // [esp+1Ch] [ebp-38h]
  struct GMatrix2D v31; // [esp+20h] [ebp-34h] BYREF
  GMatrix2D v32; // [esp+38h] [ebp-1Ch] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0xFu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
    {
      p_cxItem = (int)&v2[-1].cxItem;
      if ( v2 != (GASFnCall)16 && (int)a2[7] > 1 )
      {
        GMatrix2D::SetIdentity(this: (float *)&v32);
        v14 = (_SERVICE_STATUS *)a2[6];
        v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
        v5 = GASValue::ToNumber(this: v4, a2: p_cxItem, a3: a1, result: v14);
        v25 = v5;
        v15 = (_SERVICE_STATUS *)a2[6];
        v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
        v23 = GASValue::ToNumber(this: v6, a2: p_cxItem, a3: v5, result: v15);
        v21 = 0.0;
        v20 = v25 * 0.5;
        v7 = 0.5 * v23;
        v22 = v7;
        if ( (int)a2[7] > 2 )
        {
          v16 = (_SERVICE_STATUS *)a2[6];
          v8 = (GASValue *)GASFnCall::Arg(this: a2, a2: 2);
          v9 = GASValue::ToNumber(this: v8, a2: p_cxItem, a3: v7, result: v16);
          v21 = v9;
          if ( (int)a2[7] > 3 )
          {
            v17 = (_SERVICE_STATUS *)a2[6];
            v10 = (GASValue *)GASFnCall::Arg(this: a2, a2: 3);
            v27 = GASValue::ToNumber(this: v10, a2: p_cxItem, a3: v9, result: v17);
            v11 = v27 + v20;
            v20 = v11;
            if ( (int)a2[7] > 4 )
            {
              v18 = (_SERVICE_STATUS *)a2[6];
              v12 = (GASValue *)GASFnCall::Arg(this: a2, a2: 4);
              v28 = GASValue::ToNumber(this: v12, a2: p_cxItem, a3: v11, result: v18);
              v22 = v28 + v22;
            }
          }
        }
        v26 = v25 * 0.0006103515625;
        v24 = 0.0006103515625 * v23;
        v29 = cos(v21);
        v19 = v29;
        v30 = sin(v21);
        v31.M_[0][0] = v19;
        v31.M_[0][1] = -v30;
        v31.M_[0][2] = 0.0;
        v31.M_[1][2] = 0.0;
        v31.M_[1][0] = v30;
        v31.M_[1][1] = v19;
        GMatrix2D::Append(this: &v32, a2: &v31);
        v13 = a2[6];
        v32.M_[0][0] = v32.M_[0][0] * v26;
        v32.M_[0][1] = v32.M_[0][1] * v26;
        v32.M_[0][2] = v26 * v32.M_[0][2];
        v32.M_[1][0] = v32.M_[1][0] * v24;
        v32.M_[1][1] = v32.M_[1][1] * v24;
        v32.M_[1][2] = v24 * v32.M_[1][2];
        v32.M_[0][2] = v32.M_[0][2] + v20;
        v32.M_[1][2] = v32.M_[1][2] + v22;
        GASMatrixObject::SetMatrix(a1: p_cxItem, a2: p_cxItem, penv: v13, ConstStringNode: (GMemAddressStub *)&v32);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125DC0
// Name: public: static void GASMatrixProto::Identity(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASMatrixProto::Identity(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int p_cxItem; // esi
  GMemAddressStub v3[24]; // [esp+4h] [ebp-1Ch] BYREF

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0xFu) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
    {
      p_cxItem = (int)&v1[-1].cxItem;
      if ( v1 != (GASFnCall)16 )
      {
        GMatrix2D::SetIdentity(this: (float *)v3);
        GASMatrixObject::SetMatrix(a1: p_cxItem, a2: (int)a1, penv: a1[6], ConstStringNode: v3);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125E40
// Name: public: static void GASMatrixProto::Invert(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::Invert(int a1@<edi>, const char *a2@<esi>, long double a3@<st0>, GASFnCall *a4)
{
  GASFnCall v4; // eax
  int p_cxItem; // edi
  int v6; // eax
  GMemAddressStub *v7; // esi
  const CMaterialDict::MaterialLookup_t *v8; // [esp-8h] [ebp-40h]
  float penv[6]; // [esp+4h] [ebp-34h] BYREF
  CMaterialDict::MaterialLookup_t m; // [esp+1Ch] [ebp-1Ch] BYREF
  float v12; // [esp+24h] [ebp-14h]
  float v13; // [esp+28h] [ebp-10h]
  float v14; // [esp+2Ch] [ebp-Ch]
  float v15; // [esp+30h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a4, type: 0xFu) )
  {
    v4 = a4[2];
    if ( v4 != nullptr )
    {
      p_cxItem = (int)&v4[-1].cxItem;
      if ( v4 != (GASFnCall)16 )
      {
        GASMatrixObject::GetMatrix(a1: p_cxItem, a2: a3, penv, v: (_SERVICE_STATUS *)a4[6], a5: a2, a6: a1);
        v7 = (GMemAddressStub *)v6;
        m.m_pMaterial = *(IMaterialInternal **)v6;
        *(float *)&m.m_Name.m_Id = *(float *)(v6 + 4);
        v12 = *(float *)(v6 + 8);
        v13 = *(float *)(v6 + 12);
        v14 = *(float *)(v6 + 16);
        v15 = *(float *)(v6 + 20);
        GMatrix2D::SetInverse(a1: (float *)v6, &m, a3: v8);
        GASMatrixObject::SetMatrix(a1: p_cxItem, a2: p_cxItem, penv: a4[6], ConstStringNode: v7);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a4, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125EF0
// Name: public: static void GASMatrixProto::Rotate(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::Rotate(const char *a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  int p_cxItem; // edi
  GASValue *v5; // eax
  double v6; // st7
  _SERVICE_STATUS *v7; // [esp-8h] [ebp-4Ch]
  int v9; // [esp+0h] [ebp-44h]
  float v10; // [esp+4h] [ebp-40h]
  float v11; // [esp+8h] [ebp-3Ch]
  float v12; // [esp+Ch] [ebp-38h]
  float v13; // [esp+Ch] [ebp-38h]
  GMatrix2D penv; // [esp+10h] [ebp-34h] BYREF
  struct GMatrix2D v15; // [esp+28h] [ebp-1Ch] BYREF

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0xFu) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
    {
      p_cxItem = (int)&v3[-1].cxItem;
      if ( v3 != (GASFnCall)16 && (int)a3[7] > 0 )
      {
        v7 = (_SERVICE_STATUS *)a3[6];
        v5 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
        v6 = GASValue::ToNumber(this: v5, a2: p_cxItem, a3: a2, result: v7);
        v11 = v6;
        GASMatrixObject::GetMatrix(a1: p_cxItem, a2: v6, (float *)&penv, v: (_SERVICE_STATUS *)a3[6], a5: a1, a6: v9);
        v12 = cos(v11);
        v10 = v12;
        v13 = sin(v11);
        v15.M_[0][0] = v10;
        v15.M_[0][1] = -v13;
        v15.M_[0][2] = 0.0;
        v15.M_[1][2] = 0.0;
        v15.M_[1][0] = v13;
        v15.M_[1][1] = v10;
        GMatrix2D::Append(this: &penv, a2: &v15);
        GASMatrixObject::SetMatrix(a1: p_cxItem, a2: p_cxItem, penv: a3[6], ConstStringNode: (GMemAddressStub *)&penv);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125FF0
// Name: public: static void GASMatrixProto::Scale(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::Scale(const char *a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  int p_cxItem; // edi
  GASValue *v5; // eax
  double v6; // st7
  GASValue *v7; // eax
  double v8; // st7
  _DWORD *v9; // [esp-Ch] [ebp-34h]
  _SERVICE_STATUS *v10; // [esp-8h] [ebp-30h]
  _SERVICE_STATUS *v11; // [esp-8h] [ebp-30h]
  int v13; // [esp+0h] [ebp-28h]
  float v14; // [esp+4h] [ebp-24h]
  float v15; // [esp+8h] [ebp-20h]
  float penv; // [esp+Ch] [ebp-1Ch] BYREF
  float v17; // [esp+10h] [ebp-18h]
  float v18; // [esp+14h] [ebp-14h]
  float v19; // [esp+18h] [ebp-10h]
  float v20; // [esp+1Ch] [ebp-Ch]
  float v21; // [esp+20h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0xFu) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
    {
      p_cxItem = (int)&v3[-1].cxItem;
      if ( v3 != (GASFnCall)16 && (int)a3[7] > 1 )
      {
        v10 = (_SERVICE_STATUS *)a3[6];
        v5 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
        v6 = GASValue::ToNumber(this: v5, a2: p_cxItem, a3: a2, result: v10);
        v14 = v6;
        v11 = (_SERVICE_STATUS *)a3[6];
        v7 = (GASValue *)GASFnCall::Arg(this: a3, a2: 1);
        v8 = GASValue::ToNumber(this: v7, a2: p_cxItem, a3: v6, result: v11);
        v15 = v8;
        GASMatrixObject::GetMatrix(a1: p_cxItem, a2: v8, &penv, v: (_SERVICE_STATUS *)a3[6], a5: a1, a6: v13);
        v9 = a3[6];
        penv = penv * v14;
        v17 = v17 * v14;
        v18 = v14 * v18;
        v19 = v19 * v15;
        v20 = v20 * v15;
        v21 = v15 * v21;
        GASMatrixObject::SetMatrix(a1: p_cxItem, a2: p_cxItem, penv: v9, ConstStringNode: (GMemAddressStub *)&penv);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101260F0
// Name: public: static void GASMatrixProto::Translate(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::Translate(const char *a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  int p_cxItem; // edi
  GASValue *v5; // eax
  double v6; // st7
  GASValue *v7; // eax
  double v8; // st7
  _DWORD *v9; // edx
  _SERVICE_STATUS *v10; // [esp-8h] [ebp-30h]
  _SERVICE_STATUS *v11; // [esp-8h] [ebp-30h]
  int v13; // [esp+0h] [ebp-28h]
  float v14; // [esp+4h] [ebp-24h]
  float v15; // [esp+8h] [ebp-20h]
  float penv[2]; // [esp+Ch] [ebp-1Ch] BYREF
  float v17; // [esp+14h] [ebp-14h]
  float v18; // [esp+20h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0xFu) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
    {
      p_cxItem = (int)&v3[-1].cxItem;
      if ( v3 != (GASFnCall)16 && (int)a3[7] > 1 )
      {
        v10 = (_SERVICE_STATUS *)a3[6];
        v5 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
        v6 = GASValue::ToNumber(this: v5, a2: p_cxItem, a3: a2, result: v10);
        v14 = v6;
        v11 = (_SERVICE_STATUS *)a3[6];
        v7 = (GASValue *)GASFnCall::Arg(this: a3, a2: 1);
        v8 = GASValue::ToNumber(this: v7, a2: p_cxItem, a3: v6, result: v11);
        v15 = v8;
        GASMatrixObject::GetMatrix(a1: p_cxItem, a2: v8, penv, v: (_SERVICE_STATUS *)a3[6], a5: a1, a6: v13);
        v9 = a3[6];
        v17 = v17 + v14;
        v18 = v18 + v15;
        GASMatrixObject::SetMatrix(a1: p_cxItem, a2: p_cxItem, penv: v9, ConstStringNode: (GMemAddressStub *)penv);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126200
// Name: public: GASMatrixObject::GASMatrixObject(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GASMatrixObject::GASMatrixObject@<eax>(
        int a1@<ecx>,
        unsigned int penv,
        GMemAddressStub *a3,
        const char *a4,
        int a5)
{
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GMemAddressStub v8[24]; // [esp+Ch] [ebp-1Ch] BYREF

  GASObject::GASObject(this: (GASObject *)a1, a2: (struct GASEnvironment *)penv);
  *(_DWORD *)a1 = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(a1 + 16) = &GASMatrixObject::`vftable'{for `GASObjectInterface'};
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *(vc_attributes::PreRangeAttribute **)(penv + 120),
                                                    result: (vc_attributes::InvalidCheckAttribute *)0xD);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(a1 + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)(penv + 120),
    psc_4: Prototype);
  GMatrix2D::SetIdentity(this: (float *)v8);
  GASMatrixObject::SetMatrix(a1, a2: penv, (_DWORD *)penv, ConstStringNode: v8);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10126270
// Name: public: static void GASMatrixProto::Clone(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::Clone(
        const char *a1@<ebx>,
        GMemAddressStub *a2@<edi>,
        long double a3@<st0>,
        GASFnCall *a4)
{
  GASFnCall v4; // eax
  int p_cxItem; // ebx
  GASValue *v6; // esi
  int v7; // ecx
  int (__thiscall *v8)(int, int, int *); // edx
  int v9; // eax
  struct GASObject *v10; // edi
  GMemAddressStub *v11; // eax
  const char *v12; // [esp-8h] [ebp-2Ch]
  const char *v13; // [esp-4h] [ebp-28h]
  int v14; // [esp+0h] [ebp-24h]
  int v15; // [esp+4h] [ebp-20h] BYREF
  float penv[6]; // [esp+8h] [ebp-1Ch] BYREF

  if ( GASFnCall::CheckThisPtr(this: a4, type: 0xFu) )
  {
    v4 = a4[2];
    v13 = a1;
    if ( v4 != nullptr && (p_cxItem = (int)&v4[-1].cxItem, v4 != (GASFnCall)16) )
    {
      v7 = *(_DWORD *)(a4[6][3].cbSize + 656);
      v8 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v7 + 40);
      v12 = (const char *)a2;
      v15 = 323;
      v9 = v8(a1: v7, a2: 52, a3: &v15);
      if ( v9 != 0 )
        v10 = (struct GASObject *)GASMatrixObject::GASMatrixObject(
                                    a1: v9,
                                    penv: (unsigned int)a4[6],
                                    a3: a2,
                                    a4: v13,
                                    a5: v14);
      else
        v10 = nullptr;
      GASMatrixObject::GetMatrix(a1: p_cxItem, a2: a3, penv, v: (_SERVICE_STATUS *)a4[6], a5: v12, a6: (int)v13);
      GASMatrixObject::SetMatrix(a1: (int)v10, a2: (int)v10, penv: a4[6], ConstStringNode: v11);
      GASValue::SetAsObject(this: (GASValue *)a4[1], a2: v10);
      if ( v10 != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)v10, a2: (int)v10);
    }
    else
    {
      v6 = (GASValue *)a4[1];
      GASValue::DropRefs(this: v6, (int)a2);
      *(_BYTE *)v6 = 0;
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a4, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126360
// Name: public: static void GASMatrixProto::TransformPoint(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::TransformPoint(
        int a1@<ebx>,
        const char *a2@<edi>,
        long double a3@<st0>,
        GASFnCall *a4)
{
  GASFnCall v4; // ebx
  int p_cxItem; // ebx
  GASValue *v6; // eax
  struct GASObject *v7; // eax
  GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *v8; // edi
  int v9; // ecx
  int (__thiscall *v10)(int, int, int *); // edx
  GASPointObject *v11; // edi
  struct GASEnvironment *v12; // eax
  struct GASEnvironment *v13; // edx
  long double v14; // st7
  long double v15; // st7
  long double v16; // st7
  long double v17; // st7
  GASValue *v18; // esi
  int i; // ebx
  const wchar_t **p_lpszMenuName; // esi
  int j; // edi
  const GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *v22; // [esp-10h] [ebp-A4h]
  const struct GASEnvironment *v23; // [esp-Ch] [ebp-A0h]
  tagWNDCLASSW v; // [esp+4h] [ebp-90h] BYREF
  _BYTE v27[16]; // [esp+34h] [ebp-60h] BYREF
  int v28; // [esp+44h] [ebp-50h] BYREF
  _OVERLAPPED v29; // [esp+48h] [ebp-4Ch] BYREF
  double v30; // [esp+5Ch] [ebp-38h]
  tagWNDCLASSW v31; // [esp+68h] [ebp-2Ch] BYREF

  if ( GASFnCall::CheckThisPtr(this: a4, type: 0xFu) )
  {
    v4 = a4[2];
    if ( v4 != nullptr )
    {
      p_cxItem = (int)&v4[-1].cxItem;
      if ( p_cxItem != 0 && (int)a4[7] > 0 )
      {
        v23 = (const struct GASEnvironment *)a4[6];
        v6 = (GASValue *)GASFnCall::Arg(this: a4, a2: 0);
        v7 = GASValue::ToObject(this: v6, (int)a2, a3: v23);
        v8 = (GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *)v7;
        if ( v7 != nullptr && ((int (__thiscall *)(struct GASObject *))v7[2].pNode[1].pNext)(a1: &v7[2]) == 16 )
        {
          GASMatrixObject::GetMatrix(
            a1: p_cxItem,
            a2: a3,
            penv: (float *)&v31.hInstance,
            v: (_SERVICE_STATUS *)a4[6],
            a5: a2,
            a6: a1);
          v22 = (const GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *)&a4[6][3];
          LOBYTE(v.style) = 0;
          LOBYTE(v.hInstance) = 0;
          GASPointObject::GetProperties(this: v8, psc: v22);
          v9 = *(_DWORD *)(a4[6][3].cbSize + 656);
          v10 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v9 + 40);
          v28 = 323;
          if ( v10(a1: v9, a2: 52, a3: &v28) != 0 )
            v11 = (GASPointObject *)GASPointObject::GASPointObject(result: (GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *)a4[6]);
          else
            v11 = nullptr;
          v12 = (struct GASEnvironment *)a4[6];
          *(double *)&v29.InternalHigh = *(float *)&v31.hInstance;
          LOBYTE(v.lpszMenuName) = 0;
          v27[0] = 0;
          LOBYTE(v29.Internal) = 3;
          GASValue::Mul(this: (unsigned int)&v29, penv: v12, &v);
          v13 = (struct GASEnvironment *)a4[6];
          v30 = *(float *)&v31.hIcon;
          LOBYTE(v29.hEvent) = 3;
          GASValue::Mul(this: (unsigned int)&v29.hEvent, penv: v13, v: (tagWNDCLASSW *)&v.hInstance);
          v14 = *(float *)&v31.hCursor;
          *(double *)&v31.lpfnWndProc = *(float *)&v31.hCursor;
          LOBYTE(v31.style) = 3;
          GASValue::operator=(this: (int)&v.lpszMenuName, v: &v31);
          GASValue::~GASValue(this: (GASValue *)&v31, a2: (int)v11);
          GASValue::Add(
            this: (unsigned int)&v.lpszMenuName,
            a2: (int)v11,
            a3: v14,
            penv: (unsigned int)a4[6],
            v: (tagWNDCLASSW *)&v29);
          GASValue::Add(
            this: (unsigned int)&v.lpszMenuName,
            a2: (int)v11,
            a3: v15,
            penv: (unsigned int)a4[6],
            v: (tagWNDCLASSW *)&v29.hEvent);
          *(double *)&v31.lpfnWndProc = *(float *)&v31.hbrBackground;
          LOBYTE(v31.style) = 3;
          GASValue::operator=(this: (int)&v29, v: &v31);
          GASValue::~GASValue(this: (GASValue *)&v31, a2: (int)v11);
          GASValue::Mul(this: (unsigned int)&v29, penv: (struct GASEnvironment *)a4[6], &v);
          *(double *)&v31.lpfnWndProc = *(float *)&v31.lpszMenuName;
          LOBYTE(v31.style) = 3;
          GASValue::operator=(this: (int)&v29.hEvent, v: &v31);
          GASValue::~GASValue(this: (GASValue *)&v31, a2: (int)v11);
          GASValue::Mul(
            this: (unsigned int)&v29.hEvent,
            penv: (struct GASEnvironment *)a4[6],
            v: (tagWNDCLASSW *)&v.hInstance);
          v16 = *(float *)&v31.lpszClassName;
          *(double *)&v31.lpfnWndProc = *(float *)&v31.lpszClassName;
          LOBYTE(v31.style) = 3;
          GASValue::operator=(this: (int)v27, v: &v31);
          GASValue::~GASValue(this: (GASValue *)&v31, a2: (int)v11);
          GASValue::Add(
            this: (unsigned int)v27,
            a2: (int)v11,
            a3: v16,
            penv: (unsigned int)a4[6],
            v: (tagWNDCLASSW *)&v29);
          GASValue::Add(
            this: (unsigned int)v27,
            a2: (int)v11,
            a3: v17,
            penv: (unsigned int)a4[6],
            v: (tagWNDCLASSW *)&v29.hEvent);
          GASPointObject::SetProperties(
            this: v11,
            params: (struct GASStringContext *)&a4[6][3],
            a3: (const struct GASValue *const)&v.lpszMenuName);
          GASValue::SetAsObject(this: (GASValue *)a4[1], a2: (struct GASObject *)v11);
          GASValue::~GASValue(this: (GASValue *)&v29.hEvent, a2: (int)v11);
          GASValue::~GASValue(this: (GASValue *)&v29, a2: (int)v11);
          v18 = (GASValue *)&v28;
          for ( i = 1; i >= 0; --i )
          {
            v18 -= 4;
            GASValue::~GASValue(this: v18, a2: (int)v11);
          }
          if ( v11 != nullptr )
            GRefCountBaseGC<323>::Release(a1: (int)v11, a2: (int)v11);
          p_lpszMenuName = &v.lpszMenuName;
          for ( j = 1; j >= 0; --j )
          {
            p_lpszMenuName -= 4;
            GASValue::~GASValue(this: (GASValue *)p_lpszMenuName, a2: j);
          }
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a4, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101265E0
// Name: public: static void GASMatrixProto::DeltaTransformPoint(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMatrixProto::DeltaTransformPoint(
        int a1@<ebx>,
        const char *a2@<edi>,
        long double a3@<st0>,
        GASFnCall *a4)
{
  GASFnCall v4; // ebx
  int p_cxItem; // ebx
  GASValue *v6; // eax
  struct GASObject *v7; // eax
  GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *v8; // edi
  int v9; // ecx
  int (__thiscall *v10)(int, int, int *); // edx
  GASPointObject *v11; // edi
  struct GASEnvironment *v12; // eax
  long double v13; // st7
  long double v14; // st7
  GASValue *v15; // esi
  int i; // ebx
  const wchar_t **p_lpszMenuName; // esi
  int j; // edi
  const GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *v19; // [esp-10h] [ebp-94h]
  const struct GASEnvironment *v20; // [esp-Ch] [ebp-90h]
  tagWNDCLASSW v; // [esp+4h] [ebp-80h] BYREF
  _BYTE v24[16]; // [esp+34h] [ebp-50h] BYREF
  int v25; // [esp+44h] [ebp-40h] BYREF
  tagWNDCLASSW v26; // [esp+48h] [ebp-3Ch] BYREF
  float v27; // [esp+74h] [ebp-10h]
  float v28; // [esp+78h] [ebp-Ch]

  if ( GASFnCall::CheckThisPtr(this: a4, type: 0xFu) )
  {
    v4 = a4[2];
    if ( v4 != nullptr )
    {
      p_cxItem = (int)&v4[-1].cxItem;
      if ( p_cxItem != 0 && (int)a4[7] > 0 )
      {
        v20 = (const struct GASEnvironment *)a4[6];
        v6 = (GASValue *)GASFnCall::Arg(this: a4, a2: 0);
        v7 = GASValue::ToObject(this: v6, (int)a2, a3: v20);
        v8 = (GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *)v7;
        if ( v7 != nullptr && ((int (__thiscall *)(struct GASObject *))v7[2].pNode[1].pNext)(a1: &v7[2]) == 16 )
        {
          GASMatrixObject::GetMatrix(
            a1: p_cxItem,
            a2: a3,
            penv: (float *)&v26.lpszMenuName,
            v: (_SERVICE_STATUS *)a4[6],
            a5: a2,
            a6: a1);
          v19 = (const GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *)&a4[6][3];
          LOBYTE(v.style) = 0;
          LOBYTE(v.hInstance) = 0;
          GASPointObject::GetProperties(this: v8, psc: v19);
          v9 = *(_DWORD *)(a4[6][3].cbSize + 656);
          v10 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v9 + 40);
          v25 = 323;
          if ( v10(a1: v9, a2: 52, a3: &v25) != 0 )
            v11 = (GASPointObject *)GASPointObject::GASPointObject(result: (GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *)a4[6]);
          else
            v11 = nullptr;
          v12 = (struct GASEnvironment *)a4[6];
          *(double *)&v26.lpfnWndProc = *(float *)&v26.lpszMenuName;
          LOBYTE(v.lpszMenuName) = 0;
          v24[0] = 0;
          LOBYTE(v26.style) = 3;
          GASValue::Mul(this: (unsigned int)&v26, penv: v12, &v);
          v13 = *(float *)&v26.lpszClassName;
          *(double *)&v26.hIcon = *(float *)&v26.lpszClassName;
          LOBYTE(v26.hInstance) = 3;
          GASValue::operator=(this: (int)&v.lpszMenuName, v: (tagWNDCLASSW *)&v26.hInstance);
          GASValue::~GASValue(this: (GASValue *)&v26.hInstance, a2: (int)v11);
          GASValue::Mul(
            this: (unsigned int)&v.lpszMenuName,
            penv: (struct GASEnvironment *)a4[6],
            v: (tagWNDCLASSW *)&v.hInstance);
          GASValue::Add(this: (unsigned int)&v.lpszMenuName, a2: (int)v11, a3: v13, penv: (unsigned int)a4[6], v: &v26);
          *(double *)&v26.hIcon = v27;
          LOBYTE(v26.hInstance) = 3;
          GASValue::operator=(this: (int)&v26, v: (tagWNDCLASSW *)&v26.hInstance);
          GASValue::~GASValue(this: (GASValue *)&v26.hInstance, a2: (int)v11);
          GASValue::Mul(this: (unsigned int)&v26, penv: (struct GASEnvironment *)a4[6], &v);
          v14 = v28;
          *(double *)&v26.hIcon = v28;
          LOBYTE(v26.hInstance) = 3;
          GASValue::operator=(this: (int)v24, v: (tagWNDCLASSW *)&v26.hInstance);
          GASValue::~GASValue(this: (GASValue *)&v26.hInstance, a2: (int)v11);
          GASValue::Mul(this: (unsigned int)v24, penv: (struct GASEnvironment *)a4[6], v: (tagWNDCLASSW *)&v.hInstance);
          GASValue::Add(this: (unsigned int)v24, a2: (int)v11, a3: v14, penv: (unsigned int)a4[6], v: &v26);
          GASPointObject::SetProperties(
            this: v11,
            params: (struct GASStringContext *)&a4[6][3],
            a3: (const struct GASValue *const)&v.lpszMenuName);
          GASValue::SetAsObject(this: (GASValue *)a4[1], a2: (struct GASObject *)v11);
          GASValue::~GASValue(this: (GASValue *)&v26, a2: (int)v11);
          v15 = (GASValue *)&v25;
          for ( i = 1; i >= 0; --i )
          {
            v15 -= 4;
            GASValue::~GASValue(this: v15, a2: (int)v11);
          }
          if ( v11 != nullptr )
            GRefCountBaseGC<323>::Release(a1: (int)v11, a2: (int)v11);
          p_lpszMenuName = &v.lpszMenuName;
          for ( j = 1; j >= 0; --j )
          {
            p_lpszMenuName -= 4;
            GASValue::~GASValue(this: (GASValue *)p_lpszMenuName, a2: j);
          }
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a4, a2: "Matrix", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126810
// Name: public: virtual class GASObject __near * GASMatrixCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__thiscall GASMatrixCtorFunction::CreateNewObject(
        GASMatrixCtorFunction *this,
        struct GASEnvironment *penv)
{
  int v2; // ecx
  int (__thiscall *v3)(int, int, int *); // edx
  vc_attributes::PreRangeAttribute **v4; // ebx
  GASObject *v5; // eax
  int v6; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  int v9; // [esp+Ch] [ebp-20h] BYREF
  GMemAddressStub v10[24]; // [esp+10h] [ebp-1Ch] BYREF

  v2 = *(_DWORD *)(*((_DWORD *)penv + 30) + 656);
  v3 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v2 + 40);
  v4 = (vc_attributes::PreRangeAttribute **)((char *)penv + 120);
  v9 = 323;
  v5 = (GASObject *)v3(a1: v2, a2: 52, a3: &v9);
  v6 = (int)v5;
  if ( v5 == nullptr )
    return nullptr;
  GASObject::GASObject(this: v5, a2: penv);
  *(_DWORD *)v6 = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(v6 + 16) = &GASMatrixObject::`vftable'{for `GASObjectInterface'};
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *v4,
                                                    result: (vc_attributes::InvalidCheckAttribute *)0xD);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(v6 + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v4,
    psc_4: Prototype);
  GMatrix2D::SetIdentity(this: (float *)v10);
  GASMatrixObject::SetMatrix(a1: v6, a2: (int)penv, penv, ConstStringNode: v10);
  return (struct GASObject *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x101268C0
// Name: public: static void GASMatrixCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMatrixCtorFunction::GlobalCtor(int a1@<edi>, int fna)
{
  int v3; // eax
  struct GASObject *v4; // ebx
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *); // eax
  GASObject *v7; // eax
  int v8; // ebx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  struct GASObject *v10; // ebx
  struct GASValue *v11; // eax
  struct GASValue *v12; // eax
  struct GASValue *v13; // eax
  struct GASValue *v14; // eax
  struct GASValue *v15; // eax
  struct GASValue *v16; // eax
  int v17; // [esp+Ch] [ebp-24h] BYREF
  struct GASObject *v18; // [esp+10h] [ebp-20h]
  GMemAddressStub v19[24]; // [esp+14h] [ebp-1Ch] BYREF

  if ( *(_DWORD *)(fna + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fna + 8) + 8))(a1: *(_DWORD *)(fna + 8)) == 15
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(fna + 8) + 64))(a1: *(_DWORD *)(fna + 8)) == 0 )
  {
    v3 = *(_DWORD *)(fna + 8);
    if ( v3 != 0 )
    {
      v4 = (struct GASObject *)(v3 - 16);
      if ( v3 != 16 )
        v4[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v4[1].pNode->pNext + 1) & 0x8FFFFFFF);
      v18 = (struct GASObject *)(v3 - 16);
    }
    else
    {
      v4 = nullptr;
      v18 = nullptr;
    }
  }
  else
  {
    v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fna + 24) + 120) + 656);
    v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
    v17 = 323;
    v7 = (GASObject *)v6(a1: v5, a2: 52, a3: &v17);
    a1 = (int)v7;
    if ( v7 != nullptr )
    {
      v8 = *(_DWORD *)(fna + 24);
      GASObject::GASObject(this: v7, a2: (struct GASEnvironment *)v8);
      *(_DWORD *)a1 = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
      *(_DWORD *)(a1 + 16) = &GASMatrixObject::`vftable'{for `GASObjectInterface'};
      Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                        this: *(vc_attributes::PreRangeAttribute **)(v8 + 120),
                                                        result: (vc_attributes::InvalidCheckAttribute *)0xD);
      GASObject::Set__proto__(
        this: (CTSQueue<CFunctor *,0,1> *)(a1 + 16),
        psc: (CTSQueue<CFunctor *,0,1>::Node_t *)(v8 + 120),
        psc_4: Prototype);
      GMatrix2D::SetIdentity(this: (float *)v19);
      GASMatrixObject::SetMatrix(a1, a2: a1, penv: (_DWORD *)v8, ConstStringNode: v19);
    }
    else
    {
      a1 = 0;
    }
    v18 = (struct GASObject *)a1;
    v4 = (struct GASObject *)a1;
  }
  GASValue::SetAsObject(this: *(GASValue **)(fna + 4), a2: v4);
  if ( *(int *)(fna + 28) > 0 )
  {
    a1 = *(_DWORD *)(fna + 24) + 120;
    v10 = v4 + 2;
    v11 = GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    GASObjectInterface::SetConstMemberRaw(
      this: v10,
      result: (tagWNDCLASSW *)a1,
      a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Size,
      a4: (int)v11);
    if ( *(int *)(fna + 28) > 1 )
    {
      v12 = GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
      GASObjectInterface::SetConstMemberRaw(
        this: v10,
        result: (tagWNDCLASSW *)a1,
        a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968,
        a4: (int)v12);
      if ( *(int *)(fna + 28) > 2 )
      {
        v13 = GASFnCall::Arg(this: (GASFnCall *)fna, a2: 2);
        GASObjectInterface::SetConstMemberRaw(
          this: v10,
          result: (tagWNDCLASSW *)a1,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8.m_Memory.m_nGrowSize,
          a4: (int)v13);
        if ( *(int *)(fna + 28) > 3 )
        {
          v14 = GASFnCall::Arg(this: (GASFnCall *)fna, a2: 3);
          GASObjectInterface::SetConstMemberRaw(
            this: v10,
            result: (tagWNDCLASSW *)a1,
            a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0968.m_Memory.m_nGrowSize,
            a4: (int)v14);
          if ( *(int *)(fna + 28) > 4 )
          {
            v15 = GASFnCall::Arg(this: (GASFnCall *)fna, a2: 4);
            GASObjectInterface::SetConstMemberRaw(
              this: v10,
              result: (tagWNDCLASSW *)a1,
              a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8.m_Memory.m_nAllocationCount,
              a4: (int)v15);
            if ( *(int *)(fna + 28) > 5 )
            {
              v16 = GASFnCall::Arg(this: (GASFnCall *)fna, a2: 5);
              GASObjectInterface::SetConstMemberRaw(
                this: v10,
                result: (tagWNDCLASSW *)a1,
                a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6BD8,
                a4: (int)v16);
            }
          }
        }
      }
    }
    v4 = v18;
  }
  if ( v4 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v4, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10126B70
// Name: public: static class GASFunctionRef GASMatrixCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMatrixCtorFunction::Register(void *pgc, struct GASFunctionRef *a2, _KCRM_MARSHAL_HEADER *pgca)
{
  vc_attributes::PreRangeAttribute *v3; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v5)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v6; // eax
  GASCFunctionObject *v7; // ebx
  GASCFunctionObject *v8; // eax
  struct GASFunctionRef *v9; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v11)(const char *, int, struct GASFunctionRef **); // edx
  int v12; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  unsigned int Deref; // edx
  GASValue *v15; // eax
  GASValue v16[4]; // [esp+Ch] [ebp-1Ch] BYREF
  _KCRM_MARSHAL_HEADER *v17; // [esp+1Ch] [ebp-Ch] BYREF
  char v18; // [esp+20h] [ebp-8h]
  int v19; // [esp+24h] [ebp-4h]

  v3 = (vc_attributes::PreRangeAttribute *)pgca;
  VersionMajor = pgca[41].VersionMajor;
  v17 = pgca;
  v18 = 8;
  v5 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v6 = (GASCFunctionObject *)v5(a1: VersionMajor, a2: 56, a3: &pgca);
  v7 = v6;
  if ( v6 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v6,
      func: (_REASON_CONTEXT *)&v17,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASMatrixCtorFunction::GlobalCtor);
    v7->dwSize = (unsigned int)&GASMatrixCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v7->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v8 = v7;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = a2;
  *(_DWORD *)a2 = v8;
  *((_BYTE *)v9 + 8) = 0;
  *((_DWORD *)v9 + 1) = 0;
  MaxVal = v3[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, struct GASFunctionRef **))(*(_DWORD *)MaxVal + 40);
  a2 = (struct GASFunctionRef *)323;
  v12 = v11(a1: MaxVal, a2: 84, a3: &a2);
  if ( v12 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v3,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASMatrixObject,GASEnvironment>::GASPrototype<GASMatrixObject,GASEnvironment>(
      this: (FlashArrayVisitor *)v12,
      psc: (struct GASStringContext *)&v17,
      psc_4: Prototype,
      psc_8: (unsigned int)v9);
    *(_DWORD *)v12 = &GASMatrixProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v12 + 16) = &GASPrototype<GASMatrixObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v12 + 52) = &GASPrototype<GASMatrixObject,GASEnvironment>::`vftable';
    HIBYTE(pgca) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v12 + 52),
      a2: v12,
      flags: (vc_attributes::PreRangeAttribute **)&v17,
      flags_4: (const struct GASNameFunction *)&GAS_MatrixFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&pgca + 3));
  }
  else
  {
    v12 = 0;
  }
  if ( v12 != 0 )
    *(_DWORD *)(v12 + 8) = (*(_DWORD *)(v12 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v3, a2: (int)v3, a3: 13, a4: v12);
  Deref = v3[55].Deref;
  HIBYTE(pgca) = 0;
  v19 = *(_DWORD *)(Deref + 16);
  v15 = GASValue::GASValue(this: v16, a2: (int)v3, a3: v9);
  (*(void (__thiscall **)(unsigned int, _KCRM_MARSHAL_HEADER **, vc_attributes::PreRangeAttribute *, GASValue *, char *))(v19 + 40))(
    a1: v3[55].Deref + 16,
    a2: &v17,
    a3: v3 + 5,
    a4: v15,
    a5: (char *)&pgca + 3);
  GASValue::~GASValue(this: v16, a2: (int)v3);
  if ( v12 != 0 )
    GRefCountBaseGC<323>::Release(a1: v12, a2: (int)v3);
}
