// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: devtools/statsmap/xmlconfig.cpp
// Functions: 14
// ============================================================

#include "devtools\statsmap\xmlconfig.h"

//------------------------------------------------------------------------------
// Address: 0x00401280
// Name: public: CUtlMemory<struct CHeatMapPoint,int>::~CUtlMemory<struct CHeatMapPoint,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CHeatMapPoint,int>::~CUtlMemory<CHeatMapPoint,int>(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401D40
// Name: public: void CUtlMemory<struct CHeatMapPoint,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CHeatMapPoint,int>::Grow(CUtlMemory<CHeatMapPoint,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CHeatMapPoint *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CHeatMapPoint *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CHeatMapPoint *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004023C0
// Name: public: CUtlVector<struct CHeatMapPoint,class CUtlMemory<struct CHeatMapPoint,int>>::~CUtlVector<struct CHeatMapPoint,class CUtlMemory<struct CHeatMapPoint,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CHeatMapPoint,CUtlMemory<CHeatMapPoint,int>>::~CUtlVector<CHeatMapPoint,CUtlMemory<CHeatMapPoint,int>>(
        CUtlVector<CHeatMapPoint,CUtlMemory<CHeatMapPoint,int> > *this)
{
  CHeatMapPoint *m_pMemory; // eax

  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402450
// Name: public: int CUtlVector<struct CHeatMapPoint,class CUtlMemory<struct CHeatMapPoint,int>>::InsertBefore(int,struct CHeatMapPoint const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHeatMapPoint,CUtlMemory<CHeatMapPoint,int>>::InsertBefore(
        CUtlVector<CHeatMapPoint,CUtlMemory<CHeatMapPoint,int> > *this,
        int elem,
        const CHeatMapPoint *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CHeatMapPoint *m_pMemory; // ecx
  int v7; // eax
  CHeatMapPoint *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CHeatMapPoint,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00403EB0
// Name: public: CGraph::CGraph(void)
// Source: json
//------------------------------------------------------------------------------
CGraph *__thiscall CGraph::CGraph(CGraph *this)
{
  this->m_szMapName[0] = 0;
  this->m_szAdditionalWhere[0] = 0;
  this->m_szTitle[0] = 0;
  this->m_szTable[0] = 0;
  this->m_szColumnX[0] = 0;
  this->m_szColumnY[0] = 0;
  this->m_szColumnScalar[0] = 0;
  this->m_szOutputImageName[0] = 0;
  this->m_iDays = 7;
  this->m_iResultLimit = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403F00
// Name: int cstream(unsigned char __near *,int,int __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl cstream(unsigned __int8 *buf, int cBytes, int *cBytesActual, CUtlBuffer *inputData)
{
  int v4; // eax
  int UpTo; // eax

  v4 = inputData->m_nMaxPut - inputData->m_Get;
  if ( cBytes < v4 )
    v4 = cBytes;
  *cBytesActual = v4;
  UpTo = CUtlBuffer::GetUpTo(this: inputData, pMem: buf, nSize: v4);
  *cBytesActual = UpTo;
  return UpTo < cBytes;
}

//------------------------------------------------------------------------------
// Address: 0x00403F40
// Name: bool CopyAttribute(class CXMLConfig __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CopyAttribute(CXMLConfig *pConfig, const char *pszAttributeName, char *pszResult, int iResultSize)
{
  int NamedItem; // eax

  NamedItem = XMLParser_GetNamedItem(a1: pConfig->m_Parser, a2: pszAttributeName);
  if ( NamedItem != 0 )
  {
    V_snprintf(pDest: pszResult, maxLen: iResultSize, pFormat: "%s", *(const char **)(NamedItem + 4));
    return 1;
  }
  else
  {
    *pszResult = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403F90
// Name: int Characters(void __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Characters(_DWORD *pUserData, const unsigned __int8 *Chars, unsigned int cbChars)
{
  int i; // eax

  if ( pUserData[2] != 0 )
  {
    if ( cbChars >= 0x40 )
    {
      _Msg(a1: "Error, map name entry is too long\n");
      return 1;
    }
    for ( i = 0; i < (int)cbChars; ++i )
      *(_BYTE *)(pUserData[2] + i + 12) = Chars[i];
    *(_BYTE *)(pUserData[2] + cbChars + 12) = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403FF0
// Name: public: CXMLConfig::CXMLConfig(void)
// Source: json
//------------------------------------------------------------------------------
CXMLConfig *__thiscall CXMLConfig::CXMLConfig(CXMLConfig *this)
{
  this->m_bReadingMapList = false;
  this->m_pCurrentMap = nullptr;
  this->pCurrentProduct = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404000
// Name: public: void CUtlMemory<class COverviewMap __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<COverviewMap *,int>::Grow(CUtlMemory<CProduct *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CProduct **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CProduct **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CProduct **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404090
// Name: public: int CUtlVector<class COverviewMap __near *,class CUtlMemory<class COverviewMap __near *,int>>::InsertBefore(int,class COverviewMap __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<COverviewMap *,CUtlMemory<COverviewMap *,int>>::InsertBefore(
        CUtlVector<CProduct *,CUtlMemory<CProduct *,int> > *this,
        int elem,
        CProduct **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CProduct **m_pMemory; // ecx
  int v7; // eax
  CProduct **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<COverviewMap *,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404100
// Name: int StartElement(void __near *,unsigned char const __near *,unsigned char const __near *,unsigned char const __near *,struct tagXMLVECTOR __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl StartElement(
        CXMLConfig *pUserData,
        const unsigned __int8 *uri,
        const unsigned __int8 *localName,
        const unsigned __int8 *qName)
{
  char *v4; // eax
  char *v5; // esi
  int v6; // eax
  int result; // eax
  CGraph *v8; // eax
  CGraph *v9; // ebx
  int NamedItem; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  CProduct *pCurrentProduct; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CGraph **m_pMemory; // ecx
  int v24; // eax
  CGraph **v25; // eax
  _DWORD *v26; // eax
  tagXMLPARSER *m_Parser; // [esp-8h] [ebp-124h]
  char pszResult[128]; // [esp+10h] [ebp-10Ch] BYREF
  char buffer[128]; // [esp+90h] [ebp-8Ch] BYREF
  int v30; // [esp+118h] [ebp-4h]

  if ( _V_stricmp(s1: (const char *)qName, s2: "product") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)qName, s2: "statsmap") != 0 )
    {
      result = _V_stricmp(s1: (const char *)qName, s2: "maplist");
      if ( result == 0 )
      {
        pUserData->m_bReadingMapList = true;
        return result;
      }
      if ( _V_stricmp(s1: (const char *)qName, s2: "map") == 0 && pUserData->m_bReadingMapList )
      {
        v26 = operator new(nSize: 0x4Cu);
        if ( v26 != nullptr )
        {
          v26[1] = 0;
          *v26 = 0;
          v26[2] = 0;
          *((_BYTE *)v26 + 12) = 0;
        }
        else
        {
          v26 = nullptr;
        }
        pUserData->m_pCurrentMap = (COverviewMap *)v26;
        if ( CopyAttribute(pConfig: pUserData, pszAttributeName: "OverviewX", pszResult, iResultSize: 128) != 0 )
          pUserData->m_pCurrentMap->m_iPosX = atoi(nptr: pszResult);
        if ( CopyAttribute(pConfig: pUserData, pszAttributeName: "OverviewY", pszResult, iResultSize: 128) != 0 )
          pUserData->m_pCurrentMap->m_iPosY = atoi(nptr: pszResult);
        if ( CopyAttribute(pConfig: pUserData, pszAttributeName: "OverviewScale", pszResult, iResultSize: 128) != 0 )
          pUserData->m_pCurrentMap->m_flScale = atof(nptr: pszResult);
      }
    }
    else
    {
      v8 = (CGraph *)operator new(nSize: 0x748u);
      if ( v8 != nullptr )
        v9 = CGraph::CGraph(this: v8);
      else
        v9 = nullptr;
      NamedItem = XMLParser_GetNamedItem(a1: pUserData->m_Parser, a2: "map");
      if ( NamedItem != 0 )
        V_snprintf(pDest: v9->m_szMapName, maxLen: 64, pFormat: "%s", *(const char **)(NamedItem + 4));
      else
        v9->m_szMapName[0] = 0;
      v11 = XMLParser_GetNamedItem(a1: pUserData->m_Parser, a2: "where");
      if ( v11 != 0 )
        V_snprintf(pDest: v9->m_szAdditionalWhere, maxLen: 1024, pFormat: "%s", *(const char **)(v11 + 4));
      else
        v9->m_szAdditionalWhere[0] = 0;
      v12 = XMLParser_GetNamedItem(a1: pUserData->m_Parser, a2: "title");
      if ( v12 != 0 )
        V_snprintf(pDest: v9->m_szTitle, maxLen: 128, pFormat: "%s", *(const char **)(v12 + 4));
      else
        v9->m_szTitle[0] = 0;
      v13 = XMLParser_GetNamedItem(a1: pUserData->m_Parser, a2: "table");
      if ( v13 != 0 )
        V_snprintf(pDest: v9->m_szTable, maxLen: 128, pFormat: "%s", *(const char **)(v13 + 4));
      else
        v9->m_szTable[0] = 0;
      v14 = XMLParser_GetNamedItem(a1: pUserData->m_Parser, a2: "x");
      if ( v14 != 0 )
        V_snprintf(pDest: v9->m_szColumnX, maxLen: 128, pFormat: "%s", *(const char **)(v14 + 4));
      else
        v9->m_szColumnX[0] = 0;
      v15 = XMLParser_GetNamedItem(a1: pUserData->m_Parser, a2: "y");
      if ( v15 != 0 )
        V_snprintf(pDest: v9->m_szColumnY, maxLen: 128, pFormat: "%s", *(const char **)(v15 + 4));
      else
        v9->m_szColumnY[0] = 0;
      v16 = XMLParser_GetNamedItem(a1: pUserData->m_Parser, a2: "scalar");
      if ( v16 != 0 )
        V_snprintf(pDest: v9->m_szColumnScalar, maxLen: 128, pFormat: "%s", *(const char **)(v16 + 4));
      else
        v9->m_szColumnScalar[0] = 0;
      v17 = XMLParser_GetNamedItem(a1: pUserData->m_Parser, a2: "image");
      if ( v17 != 0 )
        V_snprintf(pDest: v9->m_szOutputImageName, maxLen: 128, pFormat: "%s", *(const char **)(v17 + 4));
      else
        v9->m_szOutputImageName[0] = 0;
      v18 = XMLParser_GetNamedItem(a1: pUserData->m_Parser, a2: "days");
      if ( v18 != 0 )
      {
        V_snprintf(pDest: buffer, maxLen: 128, pFormat: "%s", *(const char **)(v18 + 4));
        v9->m_iDays = atoi(nptr: buffer);
      }
      else
      {
        buffer[0] = 0;
      }
      v19 = XMLParser_GetNamedItem(a1: pUserData->m_Parser, a2: "limit");
      if ( v19 != 0 )
      {
        V_snprintf(pDest: buffer, maxLen: 128, pFormat: "%s", *(const char **)(v19 + 4));
        v9->m_iResultLimit = atoi(nptr: buffer);
      }
      else
      {
        buffer[0] = 0;
      }
      pCurrentProduct = pUserData->pCurrentProduct;
      m_Size = pCurrentProduct->m_Graphs.m_Size;
      m_nAllocationCount = pCurrentProduct->m_Graphs.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<COverviewMap *,int>::Grow(
          this: (CUtlMemory<CProduct *,int> *)&pCurrentProduct->m_Graphs,
          num: m_Size - m_nAllocationCount + 1);
      ++pCurrentProduct->m_Graphs.m_Size;
      m_pMemory = pCurrentProduct->m_Graphs.m_Memory.m_pMemory;
      v24 = pCurrentProduct->m_Graphs.m_Size - m_Size - 1;
      pCurrentProduct->m_Graphs.m_pElements = m_pMemory;
      if ( v24 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v24);
      v25 = &pCurrentProduct->m_Graphs.m_Memory.m_pMemory[m_Size];
      if ( v25 != nullptr )
      {
        *v25 = v9;
        return 0;
      }
    }
    return 0;
  }
  else
  {
    v4 = (char *)operator new(nSize: 0xA8u);
    if ( v4 != nullptr )
    {
      *((_DWORD *)v4 + 32) = 0;
      *((_DWORD *)v4 + 33) = 0;
      *((_DWORD *)v4 + 34) = 0;
      *((_DWORD *)v4 + 35) = 0;
      *((_DWORD *)v4 + 36) = 0;
      *((_DWORD *)v4 + 37) = 0;
      *((_DWORD *)v4 + 38) = 0;
      *((_DWORD *)v4 + 39) = 0;
      *((_DWORD *)v4 + 40) = 0;
      *((_DWORD *)v4 + 41) = 0;
      *v4 = 0;
      v5 = v4;
    }
    else
    {
      v5 = nullptr;
    }
    pUserData->pCurrentProduct = (CProduct *)v5;
    m_Parser = pUserData->m_Parser;
    v30 = -1;
    v6 = XMLParser_GetNamedItem(a1: m_Parser, a2: "shortname");
    if ( v6 != 0 )
      V_snprintf(pDest: v5, maxLen: 128, pFormat: "%s", *(const char **)(v6 + 4));
    else
      *v5 = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404630
// Name: int EndElement(void __near *,unsigned char const __near *,unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndElement(
        CProduct **pUserData,
        const unsigned __int8 *uri,
        const unsigned __int8 *localName,
        const unsigned __int8 *qName)
{
  CStatsMap *v4; // eax
  int result; // eax
  CProduct **v6; // esi

  if ( _V_stricmp(s1: (const char *)qName, s2: "product") == 0 )
  {
    v4 = StatsMap();
    CUtlVector<COverviewMap *,CUtlMemory<COverviewMap *,int>>::InsertBefore(
      this: &v4->m_Products,
      elem: v4->m_Products.m_Size,
      src: pUserData + 1);
    pUserData[1] = nullptr;
    return 0;
  }
  result = _V_stricmp(s1: (const char *)qName, s2: "maplist");
  if ( result == 0 )
  {
    *(_BYTE *)pUserData = 0;
    return result;
  }
  if ( _V_stricmp(s1: (const char *)qName, s2: "map") == 0 && *(_BYTE *)pUserData != 0 )
  {
    v6 = pUserData + 2;
    if ( *(float *)&pUserData[2]->m_szProductName[8] > 0.0 )
    {
      CUtlVector<COverviewMap *,CUtlMemory<COverviewMap *,int>>::InsertBefore(
        this: (CUtlVector<CProduct *,CUtlMemory<CProduct *,int> > *)&pUserData[1]->m_Maps,
        elem: pUserData[1]->m_Maps.m_Size,
        src: v6);
      *v6 = nullptr;
      return 0;
    }
    free(pMem: pUserData[2]);
    *v6 = nullptr;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004046F0
// Name: public: bool CXMLConfig::ReadXMLFile(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CXMLConfig::ReadXMLFile@<al>(CXMLConfig *this@<ecx>, int a2@<ebx>)
{
  tagXMLPARSER **p_m_Parser; // esi
  void *v4; // edi
  int v5; // ebx
  int (__thiscall *Read)(IBaseFileSystem *, void *, int, void *); // edx
  int v7; // eax
  CXMLConfig *v8; // edx
  char *m_szXMLDir; // [esp-10h] [ebp-170h]
  char szFileName[264]; // [esp+4h] [ebp-15Ch] BYREF
  CUtlBuffer buf; // [esp+10Ch] [ebp-54h] BYREF
  char szSchemaFile[20]; // [esp+13Ch] [ebp-24h] BYREF
  CXMLConfig *v13; // [esp+150h] [ebp-10h]
  int v14; // [esp+15Ch] [ebp-4h]

  p_m_Parser = &this->m_Parser;
  v13 = this;
  if ( XMLParser_Create(a1: &this->m_Parser) != 0 )
  {
    strcpy(szSchemaFile, "gamestatsweb.xml");
    memset(szFileName, 0, 261);
    if ( StatsMap() == (CStatsMap *)-909 || StatsMap()->m_szXMLDir[0] == 0 )
    {
      V_ComposeFileName(path: ".", filename: szSchemaFile, dest: szFileName, destSize: 261);
      if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFileName, a3: nullptr) )
        V_ComposeFileName(
          path: "../../src/devtools/processgamestats2",
          filename: szSchemaFile,
          dest: szFileName,
          destSize: 261);
    }
    else
    {
      m_szXMLDir = StatsMap()->m_szXMLDir;
      V_ComposeFileName(path: m_szXMLDir, filename: szSchemaFile, dest: szFileName, destSize: 261);
    }
    v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFileName, a3: "rb", a4: 0);
    if ( v4 != nullptr )
    {
      v5 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFullFileSystem->Size_2)(
             a1: &g_pFullFileSystem->IBaseFileSystem,
             a2: v4,
             a3: a2);
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: v5, nFlags: 1);
      Read = g_pFullFileSystem->Read;
      v14 = 0;
      v7 = Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: v5, a4: v4);
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v7);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
      (*p_m_Parser)->errorHandler = (void (__cdecl *)(tagXMLPARSER *))jpeg_mem_term;
      (*p_m_Parser)->startElementHandler = (int (__cdecl *)(void *, const unsigned __int8 *, const unsigned __int8 *, const unsigned __int8 *, tagXMLVECTOR *))StartElement;
      (*p_m_Parser)->endElementHandler = (int (__cdecl *)(void *, const unsigned __int8 *, const unsigned __int8 *, const unsigned __int8 *))EndElement;
      v8 = v13;
      (*p_m_Parser)->charactersHandler = (int (__cdecl *)(void *, const unsigned __int8 *, int))Characters;
      (*p_m_Parser)->UserData = v8;
      if ( XMLParser_Parse(a1: *p_m_Parser, a2: cstream, a3: &buf, a4: 0) == 0 )
        _Warning(
          a1: "XML Error: %s\nLine: %d Col: %d\n",
          (const char *)(*p_m_Parser)->ErrorString,
          (*p_m_Parser)->ErrorLine,
          (*p_m_Parser)->ErrorColumn);
      XMLParser_Free(a1: *p_m_Parser);
      v14 = -1;
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 1;
    }
    else
    {
      _Msg(a1: "Failed to find gamestatsweb.xml\n");
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Error creating parser!\n");
    return 0;
  }
}
