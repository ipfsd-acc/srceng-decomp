// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/dt_instrumentation.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1016CB90
// Name: void DTI_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DTI_Init()
{
  int v0; // eax
  const char *v1; // eax
  int v2; // [esp-18h] [ebp-140h]
  int v3; // [esp-14h] [ebp-13Ch]
  int v4; // [esp-10h] [ebp-138h]
  int v5; // [esp-Ch] [ebp-134h]
  int v6; // [esp-8h] [ebp-130h]
  int v7; // [esp-4h] [ebp-12Ch]
  char dtiFileName[260]; // [esp+0h] [ebp-128h] BYREF
  tm systemTime; // [esp+104h] [ebp-24h] BYREF

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-dti") != 0 && !g_bDTIEnabled )
  {
    g_bDTIEnabled = true;
    _Plat_GetLocalTime(a1: &systemTime);
    v1 = (const char *)((int (__thiscall *)(IVEngineClient *, int, int, int, int, int, int))engineClient->GetLevelNameShort)(
                         a1: engineClient,
                         a2: (systemTime.tm_year + 1900) % 100,
                         a3: systemTime.tm_mon,
                         a4: systemTime.tm_wday,
                         a5: systemTime.tm_hour,
                         a6: systemTime.tm_min,
                         a7: systemTime.tm_sec);
    V_snprintf(
      pDest: dtiFileName,
      maxLen: 260,
      pFormat: "dti_client_%s_%02d%02d%02d-%02d%02d%02d.csv",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7);
    g_pDTIFilename = COM_StringCopy(in: dtiFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CC40
// Name: void _DTI_HookDeltaBits(class CRecvDecoder __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _DTI_HookDeltaBits(CRecvDecoder *pDecoder, int iProp, int nDataBits, int nIndexBits)
{
  CDTIRecvTable *m_pDTITable; // ecx
  CDTIProp *v5; // eax

  m_pDTITable = pDecoder->m_pDTITable;
  if ( m_pDTITable != nullptr )
  {
    v5 = &m_pDTITable->m_Props.m_Memory.m_pMemory[iProp];
    v5->m_nDataBits += nDataBits;
    ++v5->m_nDecodes;
    v5->m_nIndexBits += nIndexBits;
    v5->m_nPropIndex = iProp;
    m_pDTITable->m_bSawAction = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CDB0
// Name: void DTI_Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DTI_Flush()
{
  int m_Head; // eax
  UtlLinkedListElem_t<CDTIRecvTable *,int> *m_pMemory; // ecx
  int v2; // eax
  int v3; // edi
  _DWORD *v4; // esi
  const char *v5; // ebx
  const char *v6; // eax
  int v7; // [esp+24h] [ebp-20h]
  void *v8; // [esp+28h] [ebp-1Ch]
  int v9; // [esp+2Ch] [ebp-18h]
  int v10; // [esp+3Ch] [ebp-8h]
  int v11; // [esp+40h] [ebp-4h]

  if ( g_bDTIEnabled )
  {
    v8 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: g_pDTIFilename, a3: "wt", a4: 0);
    if ( v8 != nullptr )
    {
      ((void (__stdcall *)(IFileSystem *))g_pFileSystem->FPrintf)(a1: g_pFileSystem);
      m_Head = g_DTIRecvTables.m_Head;
      v11 = 2;
      if ( g_DTIRecvTables.m_Head != -1 )
      {
        m_pMemory = g_DTIRecvTables.m_Memory.m_pMemory;
        do
        {
          v2 = 12 * m_Head;
          v3 = *(int *)((char *)&m_pMemory->m_Element + v2);
          v7 = v2;
          if ( *(_BYTE *)(v3 + 36) != 0 )
          {
            v9 = 0;
            if ( *(int *)(v3 + 28) > 0 )
            {
              v10 = 0;
              do
              {
                v4 = (_DWORD *)(v10 + *(_DWORD *)(v3 + 16));
                if ( v4[4] != 0 )
                {
                  v5 = CUtlString::operator char const *(this: (CUtlString *)(v10 + *(_DWORD *)(v3 + 16)));
                  v6 = CUtlString::operator char const *(this: (CUtlString *)v3);
                  g_pFileSystem->FPrintf(
                    this: g_pFileSystem,
                    a2: v8,
                    a3: "%s,%s,%d,%d,%.3f,%d,%.3f,%d,=D%d/I$1\n",
                    v6,
                    v5,
                    v4[4],
                    v4[5],
                    (double)(int)v4[5] / (double)(int)v4[4],
                    v4[6],
                    (double)(int)v4[6] / (double)(int)v4[4],
                    v4[7],
                    v11);
                  v2 = v7;
                  ++v11;
                }
                v10 += 32;
                ++v9;
              }
              while ( v9 < *(_DWORD *)(v3 + 28) );
              m_pMemory = g_DTIRecvTables.m_Memory.m_pMemory;
            }
          }
          m_Head = *(int *)((char *)&m_pMemory->m_Next + v2);
        }
        while ( m_Head != -1 );
      }
      ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Close)(a1: &g_pFileSystem->IBaseFileSystem);
      _Msg(a1: "DTI: wrote client stats into %s.\n", g_pDTIFilename);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D050
// Name: void DTI_HookRecvDecoder(class CRecvDecoder __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DTI_HookRecvDecoder(CRecvDecoder *pDecoder)
{
  int v1; // eax
  CUtlString *v2; // eax
  CDTIRecvTable *v3; // esi
  CDTIRecvTable *v4; // edi
  char *m_pNetTableName; // edx
  int m_Size; // ebx
  CUtlVector<CDTIProp,CUtlMemory<CDTIProp,int> > *p_m_Props; // esi
  int v8; // ebx
  int v9; // edi
  const SendProp *v10; // eax
  const char *m_pParentArrayPropName; // ecx
  int v12; // eax
  int v13; // esi
  UtlLinkedListElem_t<CDTIRecvTable *,int> *m_pMemory; // ecx
  int v15; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<CDTIRecvTable *,int> *v17; // eax
  char *m_pVarName; // [esp-10h] [ebp-118h]
  char temp[256]; // [esp+0h] [ebp-108h] BYREF
  CDTIRecvTable *pTable; // [esp+100h] [ebp-8h]
  bool dtiEnabled; // [esp+107h] [ebp-1h]

  if ( g_bDTIEnabled )
  {
    v1 = _CommandLine();
    dtiEnabled = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-dti") > 0;
    v2 = (CUtlString *)MemAlloc_Alloc(nSize: 0x28u);
    v3 = (CDTIRecvTable *)v2;
    v4 = nullptr;
    if ( v2 != nullptr )
    {
      CUtlString::CUtlString(this: v2);
      v3->m_Props.m_Memory.m_pMemory = nullptr;
      v3->m_Props.m_Memory.m_nAllocationCount = 0;
      v3->m_Props.m_Memory.m_nGrowSize = 0;
      v3->m_Props.m_Size = 0;
      v3->m_Props.m_pElements = nullptr;
      v3->m_bSawAction = false;
      v4 = v3;
    }
    m_pNetTableName = pDecoder->m_pTable->m_pNetTableName;
    pTable = v4;
    CUtlString::Set(this: &v4->m_Name, pValue: m_pNetTableName);
    m_Size = pDecoder->m_Props.m_Size;
    p_m_Props = &v4->m_Props;
    CUtlVector<CDTIProp,CUtlMemory<CDTIProp,int>>::RemoveAll(this: &v4->m_Props);
    CUtlVector<CDTIProp,CUtlMemory<CDTIProp,int>>::InsertMultipleBefore(
      this: &v4->m_Props,
      elem: v4->m_Props.m_Size,
      num: m_Size);
    v8 = 0;
    if ( v4->m_Props.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        v10 = pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[v8];
        if ( dtiEnabled )
        {
          m_pParentArrayPropName = v10->m_pParentArrayPropName;
          m_pVarName = v10->m_pVarName;
          if ( m_pParentArrayPropName != nullptr )
          {
            V_snprintf(pDest: temp, maxLen: 256, pFormat: "%s:%s", m_pParentArrayPropName, m_pVarName);
            m_pVarName = temp;
          }
          CUtlString::Set(this: &p_m_Props->m_Memory.m_pMemory[v9].m_Name, pValue: m_pVarName);
        }
        else
        {
          CUtlString::Set(this: &p_m_Props->m_Memory.m_pMemory[v9].m_Name, pValue: v10->m_pVarName);
        }
        ++v8;
        ++v9;
      }
      while ( v8 < pTable->m_Props.m_Size );
      v4 = pTable;
    }
    v12 = CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::AllocInternal(
            this: &g_DTIRecvTables,
            multilist: false);
    v13 = v12;
    if ( v12 != -1 )
    {
      CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&g_DTIRecvTables,
        elem: v12);
      m_pMemory = g_DTIRecvTables.m_Memory.m_pMemory;
      v15 = v13;
      g_DTIRecvTables.m_Memory.m_pMemory[v15].m_Next = -1;
      m_Tail = g_DTIRecvTables.m_Tail;
      m_pMemory[v15].m_Previous = g_DTIRecvTables.m_Tail;
      g_DTIRecvTables.m_Tail = v13;
      if ( m_Tail == -1 )
        g_DTIRecvTables.m_Head = v13;
      else
        g_DTIRecvTables.m_Memory.m_pMemory[m_Tail].m_Next = v13;
      ++g_DTIRecvTables.m_ElementCount;
      v17 = &g_DTIRecvTables.m_Memory.m_pMemory[v15];
      if ( v17 != nullptr )
        v17->m_Element = v4;
    }
    pDecoder->m_pDTITable = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D2F0
// Name: void DTI_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DTI_Term()
{
  if ( g_bDTIEnabled )
  {
    DTI_Flush();
    CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::PurgeAndDeleteElements(this: &g_DTIRecvTables);
    free(pMem: (void *)g_pDTIFilename);
    g_pDTIFilename = nullptr;
    g_bDTIEnabled = false;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1016CC80
// Name: void DTI_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DTI_Init()
{
  int v0; // eax
  const char *v1; // eax
  int v2; // [esp-18h] [ebp-140h]
  int v3; // [esp-14h] [ebp-13Ch]
  int v4; // [esp-10h] [ebp-138h]
  int v5; // [esp-Ch] [ebp-134h]
  int v6; // [esp-8h] [ebp-130h]
  int v7; // [esp-4h] [ebp-12Ch]
  char dtiFileName[260]; // [esp+0h] [ebp-128h] BYREF
  tm systemTime; // [esp+104h] [ebp-24h] BYREF

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-dti") != 0 && !g_bDTIEnabled )
  {
    g_bDTIEnabled = true;
    _Plat_GetLocalTime(a1: &systemTime);
    v1 = (const char *)((int (__thiscall *)(IVEngineClient *, int, int, int, int, int, int))engineClient->GetLevelNameShort)(
                         a1: engineClient,
                         a2: (systemTime.tm_year + 1900) % 100,
                         a3: systemTime.tm_mon,
                         a4: systemTime.tm_wday,
                         a5: systemTime.tm_hour,
                         a6: systemTime.tm_min,
                         a7: systemTime.tm_sec);
    V_snprintf(
      pDest: dtiFileName,
      maxLen: 260,
      pFormat: "dti_client_%s_%02d%02d%02d-%02d%02d%02d.csv",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7);
    g_pDTIFilename = COM_StringCopy(in: dtiFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CD30
// Name: void _DTI_HookDeltaBits(class CRecvDecoder __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _DTI_HookDeltaBits(CRecvDecoder *pDecoder, int iProp, int nDataBits, int nIndexBits)
{
  CDTIRecvTable *m_pDTITable; // ecx
  CDTIProp *v5; // eax

  m_pDTITable = pDecoder->m_pDTITable;
  if ( m_pDTITable != nullptr )
  {
    v5 = &m_pDTITable->m_Props.m_Memory.m_pMemory[iProp];
    v5->m_nDataBits += nDataBits;
    ++v5->m_nDecodes;
    v5->m_nIndexBits += nIndexBits;
    v5->m_nPropIndex = iProp;
    m_pDTITable->m_bSawAction = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CEA0
// Name: void DTI_Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DTI_Flush()
{
  int m_Head; // eax
  UtlLinkedListElem_t<CDTIRecvTable *,int> *m_pMemory; // ecx
  int v2; // eax
  int v3; // edi
  _DWORD *v4; // esi
  const char *v5; // ebx
  const char *v6; // eax
  int v7; // [esp+24h] [ebp-20h]
  void *v8; // [esp+28h] [ebp-1Ch]
  int v9; // [esp+2Ch] [ebp-18h]
  int v10; // [esp+3Ch] [ebp-8h]
  int v11; // [esp+40h] [ebp-4h]

  if ( g_bDTIEnabled )
  {
    v8 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: g_pDTIFilename, a3: "wt", a4: 0);
    if ( v8 != nullptr )
    {
      ((void (__stdcall *)(IFileSystem *))g_pFileSystem->FPrintf)(a1: g_pFileSystem);
      m_Head = g_DTIRecvTables.m_Head;
      v11 = 2;
      if ( g_DTIRecvTables.m_Head != -1 )
      {
        m_pMemory = g_DTIRecvTables.m_Memory.m_pMemory;
        do
        {
          v2 = 12 * m_Head;
          v3 = *(int *)((char *)&m_pMemory->m_Element + v2);
          v7 = v2;
          if ( *(_BYTE *)(v3 + 36) != 0 )
          {
            v9 = 0;
            if ( *(int *)(v3 + 28) > 0 )
            {
              v10 = 0;
              do
              {
                v4 = (_DWORD *)(v10 + *(_DWORD *)(v3 + 16));
                if ( v4[4] != 0 )
                {
                  v5 = CUtlString::operator char const *(this: (CUtlString *)(v10 + *(_DWORD *)(v3 + 16)));
                  v6 = CUtlString::operator char const *(this: (CUtlString *)v3);
                  g_pFileSystem->FPrintf(
                    this: g_pFileSystem,
                    a2: v8,
                    a3: "%s,%s,%d,%d,%.3f,%d,%.3f,%d,=D%d/I$1\n",
                    v6,
                    v5,
                    v4[4],
                    v4[5],
                    (double)(int)v4[5] / (double)(int)v4[4],
                    v4[6],
                    (double)(int)v4[6] / (double)(int)v4[4],
                    v4[7],
                    v11);
                  v2 = v7;
                  ++v11;
                }
                v10 += 32;
                ++v9;
              }
              while ( v9 < *(_DWORD *)(v3 + 28) );
              m_pMemory = g_DTIRecvTables.m_Memory.m_pMemory;
            }
          }
          m_Head = *(int *)((char *)&m_pMemory->m_Next + v2);
        }
        while ( m_Head != -1 );
      }
      ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Close)(a1: &g_pFileSystem->IBaseFileSystem);
      _Msg(a1: "DTI: wrote client stats into %s.\n", g_pDTIFilename);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D1C0
// Name: void DTI_HookRecvDecoder(class CRecvDecoder __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DTI_HookRecvDecoder(CRecvDecoder *pDecoder)
{
  int v1; // eax
  CUtlString *v2; // eax
  CDTIRecvTable *v3; // esi
  CDTIRecvTable *v4; // edi
  char *m_pNetTableName; // edx
  int m_Size; // ebx
  CUtlVector<CDTIProp,CUtlMemory<CDTIProp,int> > *p_m_Props; // esi
  int v8; // ebx
  int v9; // edi
  const SendProp *v10; // eax
  const char *m_pParentArrayPropName; // ecx
  int v12; // eax
  int v13; // esi
  UtlLinkedListElem_t<CDTIRecvTable *,int> *m_pMemory; // ecx
  int v15; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<CDTIRecvTable *,int> *v17; // eax
  char *m_pVarName; // [esp-10h] [ebp-118h]
  char temp[256]; // [esp+0h] [ebp-108h] BYREF
  CDTIRecvTable *pTable; // [esp+100h] [ebp-8h]
  bool dtiEnabled; // [esp+107h] [ebp-1h]

  if ( g_bDTIEnabled )
  {
    v1 = _CommandLine();
    dtiEnabled = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-dti") > 0;
    v2 = (CUtlString *)MemAlloc_Alloc(nSize: 0x28u);
    v3 = (CDTIRecvTable *)v2;
    v4 = nullptr;
    if ( v2 != nullptr )
    {
      CUtlString::CUtlString(this: v2);
      v3->m_Props.m_Memory.m_pMemory = nullptr;
      v3->m_Props.m_Memory.m_nAllocationCount = 0;
      v3->m_Props.m_Memory.m_nGrowSize = 0;
      v3->m_Props.m_Size = 0;
      v3->m_Props.m_pElements = nullptr;
      v3->m_bSawAction = false;
      v4 = v3;
    }
    m_pNetTableName = pDecoder->m_pTable->m_pNetTableName;
    pTable = v4;
    CUtlString::Set(this: &v4->m_Name, pValue: m_pNetTableName);
    m_Size = pDecoder->m_Props.m_Size;
    p_m_Props = &v4->m_Props;
    CUtlVector<CDTIProp,CUtlMemory<CDTIProp,int>>::RemoveAll(this: &v4->m_Props);
    CUtlVector<CDTIProp,CUtlMemory<CDTIProp,int>>::InsertMultipleBefore(
      this: &v4->m_Props,
      elem: v4->m_Props.m_Size,
      num: m_Size);
    v8 = 0;
    if ( v4->m_Props.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        v10 = pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[v8];
        if ( dtiEnabled )
        {
          m_pParentArrayPropName = v10->m_pParentArrayPropName;
          m_pVarName = v10->m_pVarName;
          if ( m_pParentArrayPropName != nullptr )
          {
            V_snprintf(pDest: temp, maxLen: 256, pFormat: "%s:%s", m_pParentArrayPropName, m_pVarName);
            m_pVarName = temp;
          }
          CUtlString::Set(this: &p_m_Props->m_Memory.m_pMemory[v9].m_Name, pValue: m_pVarName);
        }
        else
        {
          CUtlString::Set(this: &p_m_Props->m_Memory.m_pMemory[v9].m_Name, pValue: v10->m_pVarName);
        }
        ++v8;
        ++v9;
      }
      while ( v8 < pTable->m_Props.m_Size );
      v4 = pTable;
    }
    v12 = CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::AllocInternal(
            this: &g_DTIRecvTables,
            multilist: false);
    v13 = v12;
    if ( v12 != -1 )
    {
      CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&g_DTIRecvTables,
        elem: v12);
      m_pMemory = g_DTIRecvTables.m_Memory.m_pMemory;
      v15 = v13;
      g_DTIRecvTables.m_Memory.m_pMemory[v15].m_Next = -1;
      m_Tail = g_DTIRecvTables.m_Tail;
      m_pMemory[v15].m_Previous = g_DTIRecvTables.m_Tail;
      g_DTIRecvTables.m_Tail = v13;
      if ( m_Tail == -1 )
        g_DTIRecvTables.m_Head = v13;
      else
        g_DTIRecvTables.m_Memory.m_pMemory[m_Tail].m_Next = v13;
      ++g_DTIRecvTables.m_ElementCount;
      v17 = &g_DTIRecvTables.m_Memory.m_pMemory[v15];
      if ( v17 != nullptr )
        v17->m_Element = v4;
    }
    pDecoder->m_pDTITable = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D460
// Name: void DTI_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DTI_Term()
{
  if ( g_bDTIEnabled )
  {
    DTI_Flush();
    CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::PurgeAndDeleteElements(this: &g_DTIRecvTables);
    free(pMem: (void *)g_pDTIFilename);
    g_pDTIFilename = nullptr;
    g_bDTIEnabled = false;
  }
}

} // namespace engine_xlsp
