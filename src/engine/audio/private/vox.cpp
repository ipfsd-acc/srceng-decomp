// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/vox.cpp
// Functions: 53
// ============================================================

#include "engine\audio\private\vox.h"

//------------------------------------------------------------------------------
// Address: 0x1001A2D0
// Name: public: int CUtlMap<char const __near *,int,int>::Insert(char const __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,int,int>::Insert(CUtlMap<char const *,int,int> *this, const char **key, int insert)
{
  int v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,int,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(_DWORD *)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001AB10
// Name: public: int CUtlDict<int,int>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,int>::Insert(CUtlDict<int,int> *this, char *pName, const int *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,int,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x10057CD0
// Name: public: void WordBuf::Set(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WordBuf::Set(WordBuf *this, const char *w)
{
  if ( w != nullptr )
  {
    V_strncpy(pDest: this->word, pSrc: w, maxLen: 256);
    for ( ; _V_strlen(str: this->word) >= 1; this->word[_V_strlen(str: this->word) - 1] = 0 )
    {
      if ( this->word[_V_strlen(str: this->word) - 1] != 32 )
        break;
    }
  }
  else
  {
    this->word[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057D30
// Name: char __near * __near * VOX_ParseString(char __near *)
// Source: json
//------------------------------------------------------------------------------
char **__cdecl VOX_ParseString(char *psz)
{
  char *v1; // esi
  char **i; // edx
  char j; // al
  char m; // al
  char v6; // cl
  char k; // al
  char v8; // al
  characterset_t skip; // [esp+4h] [ebp-200h] BYREF
  characterset_t nextWord; // [esp+104h] [ebp-100h] BYREF

  v1 = psz;
  memset(dst: (unsigned __int8 *)rgpparseword, value: 0, count: sizeof(rgpparseword));
  if ( psz == nullptr )
    return nullptr;
  rgpparseword[0] = psz;
  CharacterSetBuild(pSetBuffer: &nextWord, pszSetString: " ,.({");
  CharacterSetBuild(pSetBuffer: &skip, pszSetString: "., ");
  for ( i = &rgpparseword[1]; (int)i < (int)&g_cmapnames; ++i )
  {
    for ( j = *v1; j != 0; j = *++v1 )
    {
      if ( nextWord.set[j] != 0 )
        break;
    }
    if ( j == 40 )
    {
      for ( k = *v1; k != 0; k = *++v1 )
      {
        if ( k == 41 )
          break;
      }
    }
    else
    {
      if ( j != 123 )
        goto LABEL_14;
      for ( m = *v1; m != 0; m = *++v1 )
      {
        if ( m == 125 )
          break;
      }
    }
    j = *++v1;
    if ( j == 0 )
      return rgpparseword;
LABEL_14:
    if ( j == 0 )
      return rgpparseword;
    if ( j == 46 || j == 44 )
    {
      v6 = v1[1];
      if ( v6 != 10 && v6 != 13 && v6 != 0 )
      {
        *i++ = j == 46 ? voxperiod : voxcomma;
        if ( (int)i >= (int)&g_cmapnames )
          return rgpparseword;
      }
    }
    *v1 = 0;
    v8 = *++v1;
    if ( v8 == 0 )
      return rgpparseword;
    while ( skip.set[v8] != 0 )
    {
      v8 = *++v1;
      if ( v8 == 0 )
        return rgpparseword;
    }
    *i = v1;
  }
  return rgpparseword;
}

//------------------------------------------------------------------------------
// Address: 0x10057E60
// Name: float VOX_GetChanVol(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl VOX_GetChanVol(channel_t *ch)
{
  if ( ch->pMixer != nullptr )
    return ch->pMixer->GetVolumeScale(this: ch->pMixer);
  else
    return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10057E80
// Name: int VOX_ParseWordParams(char __near *,struct voxword_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_ParseWordParams(char *psz, voxword_t *pvoxword, int fFirst)
{
  char *v3; // ebx
  char i; // al
  char v5; // dl
  char *v6; // ebx
  char v7; // al
  char v8; // al
  int v9; // edi
  unsigned int v10; // esi
  char v11; // al
  int v12; // eax
  characterset_t commandSet; // [esp+Ch] [ebp-20Ch] BYREF
  characterset_t delimitSet; // [esp+10Ch] [ebp-10Ch] BYREF
  char *pszsave; // [esp+20Ch] [ebp-Ch]
  char sznum[8]; // [esp+210h] [ebp-8h] BYREF
  char ct_3; // [esp+223h] [ebp+Bh]
  char c_3; // [esp+22Bh] [ebp+13h]

  v3 = psz;
  pszsave = psz;
  CharacterSetBuild(pSetBuffer: &commandSet, pszSetString: "vpset)");
  if ( fFirst != 0 )
  {
    voxwordDefault.pitch = -1;
    voxwordDefault.volume = 100;
    voxwordDefault.start = 0;
    voxwordDefault.end = 100;
    voxwordDefault.fKeepCached = 0;
    voxwordDefault.timecompress = 0;
  }
  *pvoxword = voxwordDefault;
  if ( psz[strlen(psz) - 1] == 41 )
  {
    CharacterSetBuild(pSetBuffer: &delimitSet, pszSetString: "()");
    for ( i = *psz; delimitSet.set[i] == 0; ++v3 )
      i = v3[1];
    if ( i == 41 )
      return 0;
    *v3 = 0;
    v5 = v3[1];
    v6 = v3 + 1;
    ct_3 = v5;
    while ( 1 )
    {
      if ( ct_3 != 0 )
      {
        do
        {
          if ( commandSet.set[ct_3] != 0 )
            break;
          v7 = *++v6;
          ct_3 = v7;
        }
        while ( v7 != 0 );
      }
      if ( ct_3 == 41 )
        break;
      memset(sznum, 0, sizeof(sznum));
      v8 = *++v6;
      v9 = v8;
      v10 = 0;
      c_3 = v8;
      if ( isdigit(c: v8) == 0 )
        break;
      if ( isdigit(c: v9) != 0 )
      {
        do
        {
          if ( v10 >= 7 )
            break;
          v11 = *++v6;
          sznum[v10++] = c_3;
          c_3 = v11;
        }
        while ( isdigit(c: v11) != 0 );
      }
      v12 = atoi(nptr: sznum);
      switch ( ct_3 )
      {
        case 'e':
          pvoxword->end = v12;
          ct_3 = c_3;
          break;
        case 'p':
          pvoxword->pitch = v12;
          ct_3 = c_3;
          break;
        case 's':
          pvoxword->start = v12;
          ct_3 = c_3;
          break;
        case 't':
          pvoxword->timecompress = v12;
          goto LABEL_22;
        case 'v':
          pvoxword->volume = v12;
          ct_3 = c_3;
          break;
        default:
LABEL_22:
          ct_3 = c_3;
          break;
      }
    }
    if ( strlen(pszsave) == 0 )
    {
      voxwordDefault = *pvoxword;
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100580C0
// Name: int VOX_LookupEntIndex(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_LookupEntIndex(int type, int soundsource, bool fallocnew)
{
  int result; // eax
  int *v4; // ecx
  unsigned int v5; // ecx
  int v6; // ecx

  result = 0;
  v4 = dword_104DC2C4;
  do
  {
    if ( *(v4 - 1) == type && *v4 == soundsource )
    {
      byte_104DC2F0[104 * result] = 0;
      return result;
    }
    v4 += 26;
    ++result;
  }
  while ( (int)v4 < (int)&g_rgmapnames[1] );
  if ( !fallocnew )
    return -1;
  result = g_entnamelastsaved + 1;
  g_entnamelastsaved = result;
  if ( result >= 64 )
  {
    result = 0;
    g_entnamelastsaved = 0;
  }
  v5 = 26 * result;
  g_entnames[v5 / 0x1A].type = type;
  dword_104DC2C4[v5] = soundsource;
  dword_104DC324[v5] = 0;
  byte_104DC2F0[v5 * 4] = 0;
  dword_104DC2C8[v5] = 0;
  dword_104DC2CC[v5] = 0;
  v6 = 26 * result;
  dword_104DC2D0[v6] = 0;
  dword_104DC304[v6] = 0;
  dword_104DC2F4[v6] = 0;
  dword_104DC314[v6] = 0;
  dword_104DC2E0[v6] = 0;
  dword_104DC2D4[v6] = 0;
  dword_104DC308[v6] = 0;
  dword_104DC2F8[v6] = 0;
  dword_104DC318[v6] = 0;
  dword_104DC2E4[v6] = 0;
  dword_104DC2D8[v6] = 0;
  dword_104DC30C[v6] = 0;
  dword_104DC2FC[v6] = 0;
  dword_104DC31C[v6] = 0;
  dword_104DC2E8[v6] = 0;
  dword_104DC2DC[v6] = 0;
  dword_104DC310[v6] = 0;
  dword_104DC300[v6] = 0;
  dword_104DC320[v6] = 0;
  dword_104DC2EC[v6] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100581E0
// Name: int VOX_LookupLastDeadIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_LookupLastDeadIndex(int type)
{
  float v1; // xmm0_4
  int result; // eax
  int v3; // edx
  int *v4; // ecx

  v1 = -1.0;
  result = -1;
  v3 = 2;
  v4 = dword_104DC324;
  do
  {
    if ( *(v4 - 25) == type && *((_BYTE *)v4 - 52) != 0 && *(float *)v4 >= v1 )
    {
      v1 = *(float *)v4;
      result = v3 - 2;
    }
    if ( v4[1] == type && *((_BYTE *)v4 + 52) != 0 && *((float *)v4 + 26) >= v1 )
    {
      v1 = *((float *)v4 + 26);
      result = v3 - 1;
    }
    if ( v4[27] == type && *((_BYTE *)v4 + 156) != 0 && *((float *)v4 + 52) >= v1 )
    {
      v1 = *((float *)v4 + 52);
      result = v3;
    }
    if ( v4[53] == type && *((_BYTE *)v4 + 260) != 0 && *((float *)v4 + 78) >= v1 )
    {
      v1 = *((float *)v4 + 78);
      result = v3 + 1;
    }
    v3 += 4;
    v4 += 104;
  }
  while ( v3 - 2 < 64 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100582A0
// Name: void VOX_InsertWords(int,int,char __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_InsertWords(int ireplace, int cnew, char *pszNew, char *pszNew1, char *pszNew2)
{
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  char **v8; // ecx

  if ( cnew != 0 )
  {
    v5 = cnew - 1;
    if ( cnew != 1 )
    {
      v6 = 31;
      v7 = v5 + ireplace;
      if ( v5 + ireplace < 31 )
      {
        v8 = &rgpparseword[-v5 + 31];
        do
          rgpparseword[v6--] = *v8--;
        while ( v6 > v7 );
      }
    }
    rgpparseword[ireplace] = pszNew;
    if ( cnew == 2 || cnew == 3 )
    {
      rgpparseword[ireplace + 1] = pszNew1;
      if ( cnew == 3 )
        rgpparseword[ireplace + 2] = pszNew2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058320
// Name: void VOX_DeleteWord(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_DeleteWord(int iword)
{
  char **v1; // edi

  if ( (unsigned int)iword <= 0x1F )
  {
    v1 = &rgpparseword[iword];
    *v1 = nullptr;
    if ( iword < 31 )
      qmemcpy(v1, &rgpparseword[iword + 1], 4 * (31 - iword));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058350
// Name: CCPairLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CCPairLessFunc(const ccpair *lhs, const ccpair *rhs)
{
  return _V_stricmp(s1: lhs->token.word, s2: rhs->token.word) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10058370
// Name: VOX_ListClear
// Source: json
//------------------------------------------------------------------------------
filelist_t *VOX_ListClear()
{
  filelist_t *result; // eax
  filelist_t *pNext; // esi

  result = g_pSentenceFileList;
  if ( g_pSentenceFileList != nullptr )
  {
    do
    {
      pNext = result->pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result);
      result = pNext;
    }
    while ( pNext != nullptr );
  }
  g_pSentenceFileList = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100583B0
// Name: VOX_ListFileIsLoaded
// Source: json
//------------------------------------------------------------------------------
int __usercall VOX_ListFileIsLoaded@<eax>(const char *psentenceFileName@<edi>)
{
  filelist_t *v1; // esi

  v1 = g_pSentenceFileList;
  if ( g_pSentenceFileList == nullptr )
    return 0;
  while ( strcmp(psentenceFileName, v1->pFileName) != 0 )
  {
    v1 = v1->pNext;
    if ( v1 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10058400
// Name: char __near * VOX_GetDirectory(char __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_GetDirectory(char *szpath, int maxpath, char *psz)
{
  int v3; // ebx
  char *v4; // esi
  char v5; // al
  int v7; // eax
  int v8; // ebx

  v3 = 0;
  v4 = &psz[_V_strlen(str: psz) - 1];
  v5 = *v4;
  if ( v4 <= psz )
  {
LABEL_4:
    if ( v5 != 47 )
    {
      V_strncpy(pDest: szpath, pSrc: "vox/", maxLen: maxpath);
      return psz;
    }
  }
  else
  {
    while ( v5 != 47 )
    {
      v5 = *--v4;
      ++v3;
      if ( v4 <= psz )
        goto LABEL_4;
    }
  }
  v7 = _V_strlen(str: psz) - v3;
  v8 = maxpath - 1;
  if ( v7 >= 0 )
  {
    if ( v7 <= v8 )
      v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  _V_memcpy(dest: szpath, src: psz, count: v8);
  szpath[v8] = 0;
  return v4 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10058490
// Name: VOX_ListMarkFileLoaded
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_ListMarkFileLoaded(const char *psentenceFileName)
{
  char *v1; // eax
  filelist_t *v2; // esi
  const char *v3; // edi
  filelist_t *v4; // ecx

  v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(psentenceFileName) + 9);
  v2 = (filelist_t *)v1;
  if ( v1 != nullptr )
  {
    v3 = v1 + 8;
    _V_strcpy(dest: v1 + 8, src: psentenceFileName);
    v4 = g_pSentenceFileList;
    v2->pFileName = v3;
    v2->pNext = v4;
    g_pSentenceFileList = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100584F0
// Name: _VOX_SentenceCount
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_SentenceCount()
{
  return g_Sentences.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10058630
// Name: public: unsigned int IFileSystem::GetOptimalReadSize(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IFileSystem::GetOptimalReadSize(IFileSystem *this, void *hFile, unsigned int nLogicalSize)
{
  if ( this->GetOptimalIOConstraints(this, a2: hFile, a3: (unsigned int *)&hFile, a4: nullptr, a5: nullptr) )
    return ~((int)hFile - 1) & ((unsigned int)hFile + nLogicalSize - 1);
  else
    return nLogicalSize;
}

//------------------------------------------------------------------------------
// Address: 0x10058670
// Name: void VOX_ParseLineCommands(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_ParseLineCommands(char *pSentenceData, int sentenceIndex)
{
  unsigned __int8 *v2; // esi
  char v3; // al
  const char *v4; // edi
  unsigned int v5; // ebx
  bool v6; // zf
  const char *v7; // esi
  char i; // al
  int v9; // eax
  char v10; // al
  sentence_t *v11; // edi
  char v12; // al
  int v13; // edi
  char j; // al
  char v15; // al
  char *v16; // [esp-10h] [ebp-21Ch]
  char tempBuffer[512]; // [esp+4h] [ebp-208h] BYREF
  char *pStart; // [esp+204h] [ebp-8h]
  int tempBufferPos; // [esp+208h] [ebp-4h]

  v2 = (unsigned __int8 *)pSentenceData;
  tempBufferPos = 0;
  if ( pSentenceData != nullptr )
  {
    v3 = *pSentenceData;
    pStart = pSentenceData;
    if ( v3 != 0 )
    {
LABEL_3:
      v4 = (const char *)v2;
      do
      {
        if ( v3 == 123 )
          break;
        v3 = *++v4;
      }
      while ( v3 != 0 );
      v5 = v4 - (const char *)v2 + tempBufferPos;
      if ( v5 > 0x200 )
      {
        DevMsg(a1: "Error! sentence too long!\n");
        return;
      }
      memcpy(dst: (unsigned __int8 *)&tempBuffer[tempBufferPos], src: v2, count: v4 - (const char *)v2);
      v6 = *v4 == 0;
      tempBufferPos = v5;
      v7 = v4;
      if ( !v6 )
        v7 = v4 + 1;
      while ( 1 )
      {
        for ( i = *v7; i != 0; i = *++v7 )
        {
          if ( i > 32 )
            break;
        }
        v9 = tolower(c: *v7);
        if ( v9 == 99 )
        {
          if ( V_strnicmp(s1: v7, s2: "closecaption", n: 12) == 0 )
          {
            v13 = sentenceIndex;
            *((_BYTE *)&g_Sentences.m_Memory.m_pMemory[sentenceIndex] + 8) = *((_BYTE *)&g_Sentences.m_Memory.m_pMemory[sentenceIndex]
                                                                             + 8)
                                                                           & 0x80
                                                                           | 1;
            v7 = COM_Parse(data: v7 + 12);
            for ( j = *v7; j != 0; j = *++v7 )
            {
              if ( j == 125 )
                break;
              if ( j <= 32 )
                break;
            }
            if ( _V_strlen(str: com_token) <= 0 )
            {
              g_Sentences.m_Memory.m_pMemory[v13].caption.m_Id = -1;
            }
            else
            {
              CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pSentenceData + 1, pStr: com_token);
              g_Sentences.m_Memory.m_pMemory[v13].caption.m_Id = HIWORD(pSentenceData);
            }
          }
        }
        else if ( v9 == 108 )
        {
          if ( V_strnicmp(s1: v7, s2: "len", n: 3) == 0 )
          {
            v11 = &g_Sentences.m_Memory.m_pMemory[sentenceIndex];
            v11->length = atof(nptr: v7 + 3);
            v12 = v7[4];
            v7 += 4;
            if ( v12 == 0 )
              break;
            while ( v12 != 125 && v12 > 32 )
            {
              v12 = *++v7;
              if ( v12 == 0 )
                goto LABEL_18;
            }
          }
        }
        else
        {
          v10 = *v7;
          if ( *v7 == 0 )
            break;
          while ( v10 != 125 && v10 > 32 )
          {
            v10 = *++v7;
            if ( v10 == 0 )
              goto LABEL_18;
          }
        }
        if ( *v7 == 0 )
          break;
        if ( *v7 == 125 )
        {
          v15 = v7[1];
          v2 = (unsigned __int8 *)(v7 + 1);
          if ( v15 != 0 )
          {
            while ( v15 <= 32 )
            {
              v15 = *++v2;
              if ( v15 == 0 )
                goto LABEL_18;
            }
            v3 = *v2;
            if ( *v2 != 0 )
              goto LABEL_3;
          }
          break;
        }
      }
LABEL_18:
      if ( (unsigned int)tempBufferPos >= 0x200 )
        return;
    }
    v16 = pStart;
    tempBuffer[tempBufferPos] = 0;
    _V_strcpy(dest: v16, src: tempBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100588C0
// Name: void VOX_LRUInit(struct sentencegroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl VOX_LRUInit(int pGroup)
{
  int v2; // ecx
  unsigned __int8 *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  IUniformRandomStream *v7; // ecx
  int v8; // eax
  unsigned __int8 v9; // cl
  int i; // [esp+Ch] [ebp+8h]

  v2 = *(unsigned __int16 *)pGroup;
  if ( (_WORD)v2 != 0 )
  {
    v3 = &g_GroupLRU.m_Memory.m_pMemory[*(__int16 *)(pGroup + 2)];
    v4 = 0;
    if ( (__int16)v2 > 0 )
    {
      do
      {
        v3[v4] = v4;
        v2 = *(__int16 *)pGroup;
        ++v4;
      }
      while ( v4 < v2 );
    }
    v5 = *(__int16 *)pGroup;
    i = 0;
    if ( 4 * v5 > 0 )
    {
      do
      {
        v6 = _RandomInt(this: (IUniformRandomStream *)v2, a2: 0, a3: v5 - 1);
        v8 = _RandomInt(this: v7, a2: 0, a3: *(__int16 *)pGroup - 1);
        v9 = v3[v6];
        v3[v6] = v3[v8];
        v3[v8] = v9;
        v5 = *(__int16 *)pGroup;
        v2 = i + 1;
        i = v2;
      }
      while ( v2 < 4 * v5 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058950
// Name: _VOX_GroupIndexFromName
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_GroupIndexFromName(char *pGroupName)
{
  int result; // eax
  CUtlSymbol *i; // ecx

  if ( pGroupName == nullptr )
    return -1;
  CUtlSymbolTable::AddString(
    this: &sentencegroup_t::s_SymbolTable,
    result: (CUtlSymbol *)&pGroupName,
    pString: pGroupName);
  result = 0;
  if ( g_SentenceGroups.m_Size <= 0 )
    return -1;
  for ( i = &g_SentenceGroups.m_Memory.m_pMemory->groupname; (_WORD)pGroupName != i->m_Id; i += 3 )
  {
    if ( ++result >= g_SentenceGroups.m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100589A0
// Name: _VOX_GroupNameFromIndex
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_GroupNameFromIndex(int groupIndex)
{
  if ( groupIndex < 0 || groupIndex >= g_SentenceGroups.m_Size )
    return nullptr;
  else
    return CUtlSymbolTable::String(
             this: &sentencegroup_t::s_SymbolTable,
             id: g_SentenceGroups.m_Memory.m_pMemory[groupIndex].groupname);
}

//------------------------------------------------------------------------------
// Address: 0x100589E0
// Name: _VOX_GroupPickSequential
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_GroupPickSequential(int isentenceg, char *szfound, int szfoundLen, int ipick, int freset)
{
  char *v5; // eax
  unsigned __int8 count; // cl
  int v7; // esi
  int v8; // edi

  if ( isentenceg < 0 )
    return -1;
  if ( isentenceg > g_SentenceGroups.m_Size )
    return -1;
  v5 = CUtlSymbolTable::String(
         this: &sentencegroup_t::s_SymbolTable,
         id: g_SentenceGroups.m_Memory.m_pMemory[isentenceg].groupname);
  count = g_SentenceGroups.m_Memory.m_pMemory[isentenceg].count;
  if ( count == 0 )
    return -1;
  v7 = ipick;
  v8 = count;
  if ( ipick >= count )
    v7 = count - 1;
  V_snprintf(pDest: szfound, maxLen: szfoundLen, pFormat: "!%s%d", v5, v7);
  if ( v7 < v8 )
    return v7 + 1;
  else
    return freset == 0 ? v8 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x10058A70
// Name: _VOX_GroupPick
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_GroupPick(int isentenceg, char *szfound, int strLen)
{
  int v3; // esi
  char *v4; // eax
  sentencegroup_t *m_pMemory; // ecx
  unsigned __int8 count; // bl
  unsigned __int8 *v7; // edi
  unsigned __int8 v8; // al
  int v9; // esi
  const char *isentencega; // [esp+14h] [ebp+8h]

  if ( isentenceg < 0 || isentenceg > g_SentenceGroups.m_Size )
    return -1;
  v3 = isentenceg;
  v4 = CUtlSymbolTable::String(
         this: &sentencegroup_t::s_SymbolTable,
         id: g_SentenceGroups.m_Memory.m_pMemory[isentenceg].groupname);
  m_pMemory = g_SentenceGroups.m_Memory.m_pMemory;
  count = g_SentenceGroups.m_Memory.m_pMemory[isentenceg].count;
  v7 = &g_GroupLRU.m_Memory.m_pMemory[g_SentenceGroups.m_Memory.m_pMemory[isentenceg].lru];
  isentencega = v4;
  while ( 1 )
  {
    v8 = 0;
    if ( count != 0 )
      break;
LABEL_7:
    VOX_LRUInit(pGroup: (int)&m_pMemory[v3]);
    m_pMemory = g_SentenceGroups.m_Memory.m_pMemory;
  }
  while ( v7[v8] == 0xFF )
  {
    if ( ++v8 >= count )
      goto LABEL_7;
  }
  v9 = v7[v8];
  v7[v8] = -1;
  V_snprintf(pDest: szfound, maxLen: strLen, pFormat: "!%s%d", isentencega, v9);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10058B30
// Name: _VOX_SentenceLength
// Source: json
//------------------------------------------------------------------------------
double __cdecl VOX_SentenceLength(int sentence_num)
{
  if ( sentence_num < 0 || sentence_num > g_Sentences.m_Size - 1 )
    return 0.0;
  else
    return g_Sentences.m_Memory.m_pMemory[sentence_num].length;
}

//------------------------------------------------------------------------------
// Address: 0x10058B60
// Name: _VOX_LookupString
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupString(
        const char *pSentenceName,
        int *psentencenum,
        bool *pbEmitCaption,
        CUtlSymbol *pCaptionSymbol,
        float *pflDuration)
{
  int m_Size; // ebx
  int v6; // esi
  int i; // edi
  char *name; // [esp+0h] [ebp-4h]

  if ( pbEmitCaption != nullptr )
    *pbEmitCaption = false;
  if ( pCaptionSymbol != nullptr )
    pCaptionSymbol->m_Id = -1;
  if ( pflDuration != nullptr )
    *pflDuration = 0.0;
  m_Size = g_Sentences.m_Size;
  v6 = 0;
  if ( g_Sentences.m_Size <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    name = g_Sentences.m_Memory.m_pMemory[i].pName;
    if ( _V_stricmp(s1: pSentenceName, s2: name) == 0 )
      break;
    if ( ++v6 >= m_Size )
      return nullptr;
  }
  if ( psentencenum != nullptr )
    *psentencenum = v6;
  if ( pbEmitCaption != nullptr )
    *pbEmitCaption = *((_BYTE *)&g_Sentences.m_Memory.m_pMemory[v6] + 8) & 0x7F;
  if ( pCaptionSymbol != nullptr )
    pCaptionSymbol->m_Id = (unsigned __int16)g_Sentences.m_Memory.m_pMemory[v6].caption;
  if ( pflDuration != nullptr )
    *pflDuration = g_Sentences.m_Memory.m_pMemory[v6].length;
  return &name[_V_strlen(str: name) + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10058C40
// Name: _VOX_SentenceNameFromIndex
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_SentenceNameFromIndex(int sentencenum)
{
  if ( sentencenum >= g_Sentences.m_Size )
    return nullptr;
  else
    return g_Sentences.m_Memory.m_pMemory[sentencenum].pName;
}

//------------------------------------------------------------------------------
// Address: 0x100593E0
// Name: _VOX_Shutdown
// Source: json
//------------------------------------------------------------------------------
filelist_t *VOX_Shutdown()
{
  filelist_t *result; // eax

  g_Sentences.m_Size = 0;
  result = VOX_ListClear();
  g_SentenceGroups.m_Size = 0;
  g_cmapnames = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059410
// Name: char __near * VOX_LookupRndVirtual(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupRndVirtual(char *pGroupName)
{
  int v1; // eax
  CUtlSymbol *i; // ecx
  int v4; // esi
  int j; // ebx
  char *pName; // edi
  const char *v7; // edi
  char *v8; // eax
  char szsentencename[32]; // [esp+4h] [ebp-24h] BYREF
  int m_Size; // [esp+24h] [ebp-4h]

  if ( pGroupName == nullptr )
    return nullptr;
  CUtlSymbolTable::AddString(
    this: &sentencegroup_t::s_SymbolTable,
    result: (CUtlSymbol *)&pGroupName,
    pString: pGroupName);
  v1 = 0;
  if ( g_SentenceGroups.m_Size <= 0 )
    return nullptr;
  for ( i = &g_SentenceGroups.m_Memory.m_pMemory->groupname; (_WORD)pGroupName != i->m_Id; i += 3 )
  {
    if ( ++v1 >= g_SentenceGroups.m_Size )
      return nullptr;
  }
  if ( v1 < 0 || VOX_GroupPick(isentenceg: v1, szfound: szsentencename, strLen: 31) < 0 )
    return nullptr;
  if ( szsentencename[0] == 33 )
    pGroupName = &szsentencename[1];
  else
    pGroupName = szsentencename;
  v4 = 0;
  m_Size = g_Sentences.m_Size;
  if ( g_Sentences.m_Size <= 0 )
    return nullptr;
  for ( j = 0; ; ++j )
  {
    pName = g_Sentences.m_Memory.m_pMemory[j].pName;
    if ( _V_stricmp(s1: pGroupName, s2: pName) == 0 )
      break;
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  v7 = &pName[_V_strlen(str: pName) + 1];
  if ( v7 == nullptr )
    return nullptr;
  v8 = _V_strstr(s1: v7, search: " ");
  if ( v8 != nullptr )
    *v8 = 0;
  return (char *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x10059510
// Name: char __near * VOX_LookupSentenceByIndex(char __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupSentenceByIndex(char *pGroupname, int ipick, int *pipicknext)
{
  int v3; // eax
  CUtlSymbol *i; // ecx
  int v6; // edi
  int v7; // esi
  char *v8; // eax
  unsigned __int8 count; // cl
  int v10; // esi
  int v11; // esi
  int v12; // edi
  char *pName; // ebx
  const char *v14; // ebx
  char *v15; // eax
  char szsentencename[32]; // [esp+Ch] [ebp-28h] BYREF
  int m_Size; // [esp+2Ch] [ebp-8h]
  int isentence; // [esp+30h] [ebp-4h]

  if ( pGroupname == nullptr )
    return nullptr;
  CUtlSymbolTable::AddString(
    this: &sentencegroup_t::s_SymbolTable,
    result: (CUtlSymbol *)&pGroupname,
    pString: pGroupname);
  v3 = 0;
  if ( g_SentenceGroups.m_Size <= 0 )
    return nullptr;
  for ( i = &g_SentenceGroups.m_Memory.m_pMemory->groupname; (_WORD)pGroupname != i->m_Id; i += 3 )
  {
    if ( ++v3 >= g_SentenceGroups.m_Size )
      return nullptr;
  }
  if ( v3 < 0 )
    return nullptr;
  v6 = ipick;
  if ( v3 > g_SentenceGroups.m_Size )
    return nullptr;
  v7 = v3;
  v8 = CUtlSymbolTable::String(
         this: &sentencegroup_t::s_SymbolTable,
         id: g_SentenceGroups.m_Memory.m_pMemory[v3].groupname);
  count = g_SentenceGroups.m_Memory.m_pMemory[v7].count;
  if ( count == 0 )
    return nullptr;
  v10 = count;
  if ( v6 >= count )
    v6 = count - 1;
  V_snprintf(pDest: szsentencename, maxLen: 31, pFormat: "!%s%d", v8, v6);
  if ( v6 < v10 )
  {
    isentence = v6 + 1;
    if ( v6 + 1 >= 0 )
      goto LABEL_16;
    return nullptr;
  }
  isentence = 0;
LABEL_16:
  if ( szsentencename[0] == 33 )
    pGroupname = &szsentencename[1];
  else
    pGroupname = szsentencename;
  v11 = 0;
  m_Size = g_Sentences.m_Size;
  if ( g_Sentences.m_Size <= 0 )
  {
LABEL_23:
    v14 = nullptr;
  }
  else
  {
    v12 = 0;
    while ( 1 )
    {
      pName = g_Sentences.m_Memory.m_pMemory[v12].pName;
      if ( _V_stricmp(s1: pGroupname, s2: pName) == 0 )
        break;
      ++v11;
      ++v12;
      if ( v11 >= m_Size )
        goto LABEL_23;
    }
    v14 = &pName[_V_strlen(str: pName) + 1];
  }
  v15 = _V_strstr(s1: v14, search: " ");
  if ( v15 != nullptr )
    *v15 = 0;
  if ( pipicknext != nullptr )
    *pipicknext = isentence;
  return (char *)v14;
}

//------------------------------------------------------------------------------
// Address: 0x10059660
// Name: char __near * VOX_LookupNumber(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupNumber(char *pGroupName, int ipick)
{
  int v2; // ebx
  int v3; // esi
  char sznumbers[16]; // [esp+Ch] [ebp-10h] BYREF

  v2 = _V_strlen(str: pGroupName);
  v3 = _V_strlen(str: "V_NUMBERS");
  _V_strcpy(dest: sznumbers, src: "V_NUMBERS");
  sznumbers[v3] = pGroupName[v2 - 1];
  sznumbers[v3 + 1] = 0;
  return VOX_LookupSentenceByIndex(pGroupname: sznumbers, ipick, pipicknext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100596C0
// Name: void VOX_LookupRangeHeadingOrGrid(int,char __near *,struct channel_t __near *,int,char __near * __near *,char __near * __near *,char __near * __near *,int __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall VOX_LookupRangeHeadingOrGrid(
        char *a1@<ebp>,
        int irhg,
        char *pGroupName,
        channel_t *pChannel,
        int soundsource,
        char **ppszNew,
        char **ppszNew1,
        char **ppszNew2,
        int *pcnew,
        bool fsimple)
{
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // edx
  float v14; // xmm1_4
  __int128 v15; // xmm0
  double v16; // st7
  double x; // st7
  int v18; // ecx
  int v19; // esi
  int v20; // edi
  int v21; // ecx
  char *v22; // eax
  char *v23; // eax
  char *v24; // eax
  char *v25; // eax
  char *v26; // eax
  char *v27; // eax
  char *v28; // eax
  char *v29; // eax
  char *v30; // ecx
  char *v31; // eax
  char *v32; // eax
  Vector v33; // [esp-Ch] [ebp-48h] BYREF
  __int128 SL; // [esp+0h] [ebp-3Ch] OVERLAPPED BYREF
  int v35; // [esp+1Ch] [ebp-20h]
  char *v36; // [esp+20h] [ebp-1Ch]
  char *v37; // [esp+24h] [ebp-18h]
  int ones; // [esp+28h] [ebp-14h]
  char *ptens; // [esp+2Ch] [ebp-10h]
  char *phundreds; // [esp+30h] [ebp-Ch]
  char *pones; // [esp+34h] [ebp-8h]
  char *retaddr; // [esp+3Ch] [ebp+0h]

  phundreds = a1;
  pones = retaddr;
  v10 = listener_origin[0].x - pChannel->origin.x;
  v11 = listener_origin[0].y - pChannel->origin.y;
  v12 = listener_origin[0].z - pChannel->origin.z;
  v13 = 0;
  v37 = nullptr;
  v36 = nullptr;
  ones = 0;
  ptens = nullptr;
  v33.x = v10;
  v33.y = v11;
  v33.z = v12;
  if ( irhg != 0 )
  {
    if ( irhg == 1 )
    {
      *(_QWORD *)((char *)&SL + 4) = 0;
      HIDWORD(SL) = 0;
      VectorAngles(forward: &v33, angles: (QAngle *)((char *)&SL + 4));
      v13 = (int)*((float *)&SL + 2);
    }
    else
    {
      if ( irhg == 2 )
      {
        x = listener_origin[0].x;
      }
      else
      {
        if ( irhg != 3 )
        {
LABEL_16:
          v18 = v13;
          goto LABEL_17;
        }
        x = listener_origin[0].y;
      }
      v13 = (int)((x + 16384.0) * 2.54 * 0.01 * 0.1) % 20;
    }
  }
  else
  {
    v14 = (float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v10 * v10);
    v15 = 0;
    *(float *)&v15 = fsqrt(v14);
    SL = v15;
    v16 = *(float *)&v15 * 2.54 * 0.01;
    if ( (int)v16 >= 0 )
    {
      v13 = 900;
      if ( (int)v16 <= 900 )
        v13 = (int)v16;
    }
    else
    {
      v13 = 0;
    }
  }
  if ( v13 < 0 )
  {
    v18 = 0;
    goto LABEL_17;
  }
  v18 = 999;
  if ( v13 <= 999 )
    goto LABEL_16;
LABEL_17:
  v19 = v18 / 100;
  v20 = v18 % 100 / 10;
  v21 = v18 - 10 * (v20 + 10 * (v18 / 100));
  v35 = v21;
  if ( fsimple )
  {
    ones = _V_strlen(str: pGroupName);
    ptens = (char *)_V_strlen(str: "V_NUMBERS");
    _V_strcpy(dest: (char *)&SL, src: "V_NUMBERS");
    v22 = ptens;
    *((_BYTE *)&SL + (_DWORD)ptens) = pGroupName[ones - 1];
    v22[(_DWORD)&SL + 1] = 0;
    ones = (int)VOX_LookupSentenceByIndex(pGroupname: (char *)&SL, ipick: v35, pipicknext: nullptr);
    ptens = (char *)1;
    if ( v20 != 0 || v19 != 0 )
    {
      v36 = VOX_LookupNumber(pGroupName, ipick: v20);
      ptens = (char *)2;
      if ( v19 != 0 )
      {
        v37 = VOX_LookupNumber(pGroupName, ipick: v19);
        ptens = (char *)3;
      }
    }
    goto LookupNumExit;
  }
  if ( v19 != 0 )
  {
    if ( v20 == 0 && v21 == 0 )
    {
      if ( v19 > 3 )
      {
        v37 = VOX_LookupNumber(pGroupName, ipick: v19);
        v36 = VOX_LookupNumber(pGroupName, ipick: 0);
        ones = (int)VOX_LookupNumber(pGroupName, ipick: 0);
        ptens = (char *)2;
      }
      else
      {
        v37 = VOX_LookupNumber(pGroupName, ipick: v19 + 27);
        ptens = (char *)1;
      }
      goto LookupNumExit;
    }
    if ( v19 > 3 || v20 != 0 || v21 == 0 )
      v23 = VOX_LookupNumber(pGroupName, ipick: v19);
    else
      v23 = VOX_LookupNumber(pGroupName, ipick: v19 + 27);
    v37 = v23;
    ptens = (char *)1;
    if ( v20 == 0 )
    {
      if ( v35 == 0 )
        goto LookupNumExit;
      ones = (int)VOX_LookupNumber(pGroupName, ipick: v35);
      ptens = (char *)2;
      if ( v19 <= 3 )
        goto LookupNumExit;
      v24 = VOX_LookupNumber(pGroupName, ipick: 0);
      ptens = (char *)3;
LABEL_45:
      v36 = v24;
      goto LookupNumExit;
    }
    v21 = v35;
  }
  if ( v20 > 1 )
  {
    if ( v21 != 0 )
    {
      v26 = VOX_LookupNumber(pGroupName, ipick: v21);
      ++ptens;
      ones = (int)v26;
    }
    v24 = VOX_LookupNumber(pGroupName, ipick: v20 + 18);
    ++ptens;
    goto LABEL_45;
  }
  if ( v20 != 0 || v21 != 0 )
  {
    v25 = VOX_LookupNumber(pGroupName, ipick: v21 + 10 * v20);
    ++ptens;
    ones = (int)v25;
  }
LookupNumExit:
  v27 = ptens;
  *pcnew = (int)ptens;
  v28 = v27 - 1;
  if ( v28 != nullptr )
  {
    v29 = v28 - 1;
    if ( v29 != nullptr )
    {
      if ( v29 == (char *)1 )
      {
        *ppszNew = v37;
        *ppszNew1 = v36;
        *ppszNew2 = (char *)ones;
      }
      else
      {
        *ppszNew = nullptr;
      }
    }
    else
    {
      v30 = v36;
      v31 = (char *)ones;
      if ( v36 != nullptr && ones != 0 )
      {
        *ppszNew = v36;
        *ppszNew1 = v31;
      }
      else if ( v37 != nullptr )
      {
        if ( ones != 0 )
        {
          *ppszNew = v37;
          *ppszNew1 = v31;
        }
        else if ( v36 != nullptr )
        {
          *ppszNew = v37;
          *ppszNew1 = v30;
        }
      }
    }
  }
  else
  {
    v32 = (char *)ones;
    if ( ones == 0 )
    {
      v32 = v36;
      if ( v36 == nullptr )
        v32 = v37;
    }
    *ppszNew = v32;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059AD0
// Name: char __near * VOX_LookupSectorVirtual(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupSectorVirtual(char *pGroupname)
{
  IUniformRandomStream *v1; // ecx
  int v2; // eax
  int m_nValue; // ecx
  int v5; // edi
  int v6; // esi
  char dest[16]; // [esp+0h] [ebp-14h] BYREF
  float curtime; // [esp+10h] [ebp-4h]
  char *pGroupnamea; // [esp+1Ch] [ebp+8h]

  curtime = g_pSoundServices->GetClientTime(this: g_pSoundServices);
  v2 = g_vox_isector;
  if ( g_vox_isector == -1 )
  {
    v2 = _RandomInt(this: v1, a2: 0, a3: 19);
    g_vox_isector = v2;
  }
  if ( snd_vox_sectimeout.m_pParent != nullptr )
    m_nValue = snd_vox_sectimeout.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( (float)(curtime - g_vox_lastsectorupdate) > (float)m_nValue )
  {
    g_vox_isector = ++v2;
    if ( v2 > 20 )
    {
      v2 = 1;
      g_vox_isector = 1;
    }
    g_vox_lastsectorupdate = curtime;
  }
  v5 = v2;
  pGroupnamea = (char *)_V_strlen(str: pGroupname);
  v6 = _V_strlen(str: "V_NUMBERS");
  _V_strcpy(dest, src: "V_NUMBERS");
  dest[v6] = pGroupname[(_DWORD)pGroupnamea - 1];
  dest[v6 + 1] = 0;
  return VOX_LookupSentenceByIndex(pGroupname: dest, ipick: v5, pipicknext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10059BA0
// Name: char __near * VOX_LookupGlobalVirtual(int,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupGlobalVirtual(int type, int soundsource, char *pGroupName, int iglobal)
{
  int v4; // ecx
  _vox_entname *v5; // eax
  float *v6; // esi
  int v7; // edx
  char *result; // eax
  char *v9; // esi
  int v10; // eax
  float curtime; // [esp+Ch] [ebp-4h]

  curtime = g_pSoundServices->GetClientTime(this: g_pSoundServices);
  v4 = 0;
  v5 = g_entnames;
  v6 = (float *)&dword_104DC304[iglobal];
  while ( 1 )
  {
    if ( v5->type == type )
    {
      v7 = snd_vox_globaltimeout.m_pParent != nullptr ? snd_vox_globaltimeout.m_pParent->m_Value.m_nValue : 0;
      if ( (float)v7 >= (float)(curtime - *v6) )
        break;
    }
    ++v5;
    ++v4;
    v6 += 26;
    if ( (int)v5 >= (int)g_rgmapnames )
      goto LABEL_10;
  }
  result = (char *)dword_104DC2D0[26 * v4 + iglobal];
  if ( result != nullptr )
    return result;
LABEL_10:
  v9 = VOX_LookupRndVirtual(pGroupName);
  v10 = iglobal + 26 * VOX_LookupEntIndex(type, soundsource, fallocnew: true);
  *(float *)&dword_104DC304[v10] = curtime;
  dword_104DC2D0[v10] = (int)v9;
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10059C60
// Name: char __near * VOX_LookupGlobalSeqVirtual(int,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupGlobalSeqVirtual(int type, int soundsource, char *pGroupName, int iglobal)
{
  int v4; // esi
  _vox_entname *v5; // eax
  int v6; // eax
  int v7; // esi
  char *result; // eax
  int m_nValue; // eax
  float v10; // xmm1_4
  int v11; // [esp-8h] [ebp-10h]
  float curtime; // [esp+4h] [ebp-4h]

  curtime = g_pSoundServices->GetClientTime(this: g_pSoundServices);
  v4 = 0;
  v5 = g_entnames;
  while ( v5->type != type )
  {
    ++v5;
    ++v4;
    if ( (int)v5 >= (int)g_rgmapnames )
    {
      v6 = VOX_LookupEntIndex(type, soundsource, fallocnew: true);
      goto Pick_next;
    }
  }
  if ( snd_vox_seqtimeout.m_pParent != nullptr )
    m_nValue = snd_vox_seqtimeout.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v10 = (float)(m_nValue / 2);
  v6 = v4;
  if ( v10 < (float)(curtime - *(float *)&dword_104DC314[26 * v4 + iglobal]) )
    dword_104DC2F4[26 * v4 + iglobal] = 0;
Pick_next:
  v7 = iglobal + 26 * v6;
  v11 = dword_104DC2F4[v7];
  iglobal = 0;
  result = VOX_LookupSentenceByIndex(pGroupname: pGroupName, ipick: v11, pipicknext: &iglobal);
  dword_104DC2F4[v7] = iglobal;
  *(float *)&dword_104DC314[v7] = curtime;
  dword_104DC2E0[v7] = (int)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059D40
// Name: void VOX_LookupMapnames(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_LookupMapnames()
{
  int v0; // eax
  CUtlSymbol *j; // ecx
  int v2; // ebx
  int v3; // esi
  char *v4; // eax
  unsigned __int8 count; // cl
  int v6; // esi
  int v7; // esi
  int v8; // edi
  char *pName; // ebx
  const char *v10; // ebx
  char *v11; // eax
  int v12; // eax
  char pDest; // [esp+Ch] [ebp-30h] BYREF
  char v14; // [esp+Dh] [ebp-2Fh] BYREF
  int m_Size; // [esp+2Ch] [ebp-10h]
  char *s1; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  CUtlSymbol result; // [esp+38h] [ebp-4h] BYREF

  i = 0;
  do
  {
    CUtlSymbolTable::AddString(this: &sentencegroup_t::s_SymbolTable, &result, pString: "V_MAPNAME");
    v0 = 0;
    if ( g_SentenceGroups.m_Size <= 0 )
      break;
    for ( j = &g_SentenceGroups.m_Memory.m_pMemory->groupname; result.m_Id != j->m_Id; j += 3 )
    {
      if ( ++v0 >= g_SentenceGroups.m_Size )
        return;
    }
    if ( v0 < 0 )
      break;
    v2 = i;
    if ( v0 > g_SentenceGroups.m_Size )
      break;
    v3 = v0;
    v4 = CUtlSymbolTable::String(
           this: &sentencegroup_t::s_SymbolTable,
           id: g_SentenceGroups.m_Memory.m_pMemory[v0].groupname);
    count = g_SentenceGroups.m_Memory.m_pMemory[v3].count;
    if ( count == 0 )
      break;
    v6 = count;
    if ( v2 >= count )
      v2 = count - 1;
    V_snprintf(&pDest, maxLen: 31, pFormat: "!%s%d", v4, v2);
    if ( v2 < v6 && v2 + 1 < 0 )
      break;
    s1 = pDest == 33 ? &v14 : &pDest;
    v7 = 0;
    m_Size = g_Sentences.m_Size;
    if ( g_Sentences.m_Size <= 0 )
    {
LABEL_21:
      v10 = nullptr;
    }
    else
    {
      v8 = 0;
      while ( 1 )
      {
        pName = g_Sentences.m_Memory.m_pMemory[v8].pName;
        if ( _V_stricmp(s1, s2: pName) == 0 )
          break;
        ++v7;
        ++v8;
        if ( v7 >= m_Size )
          goto LABEL_21;
      }
      v10 = &pName[_V_strlen(str: pName) + 1];
    }
    v11 = _V_strstr(s1: v10, search: " ");
    if ( v11 != nullptr )
      *v11 = 0;
    if ( v10 == nullptr )
      break;
    v12 = i;
    ++g_cmapnames;
    g_rgmapnames[i] = (char *)v10;
    i = v12 + 1;
  }
  while ( v12 + 1 < 24 );
}

//------------------------------------------------------------------------------
// Address: 0x10059EA0
// Name: void VOX_ReplaceVirtualNames(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_ReplaceVirtualNames(channel_t *pchan)
{
  char *v1; // ebx
  int v2; // esi
  int v3; // eax
  char *v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // eax
  int *v9; // ecx
  char *v10; // eax
  _DWORD *v11; // edi
  int v12; // edi
  ISoundServices *v13; // ecx
  int v14; // edi
  double v15; // st7
  int v16; // eax
  int DeadIndex; // eax
  int v18; // eax
  char *v19; // eax
  char *v20; // eax
  const char *v21; // [esp-Ch] [ebp-17Ch]
  const char *v22; // [esp-8h] [ebp-178h]
  char szgroup1[32]; // [esp+8h] [ebp-168h] BYREF
  char szgroup2[32]; // [esp+28h] [ebp-148h] BYREF
  char szparseword[256]; // [esp+48h] [ebp-128h] BYREF
  unsigned int v26; // [esp+148h] [ebp-28h]
  const char *pszmap; // [esp+14Ch] [ebp-24h]
  char *pszNew2; // [esp+150h] [ebp-20h] BYREF
  char **v29; // [esp+154h] [ebp-1Ch]
  int i; // [esp+158h] [ebp-18h]
  char *pszNew1; // [esp+15Ch] [ebp-14h] BYREF
  int soundsource; // [esp+160h] [ebp-10h]
  char *pszNew; // [esp+164h] [ebp-Ch] BYREF
  int cnew; // [esp+168h] [ebp-8h] BYREF
  char chtype; // [esp+16Fh] [ebp-1h]
  int savedregs; // [esp+170h] [ebp+0h] BYREF

  v1 = nullptr;
  i = 0;
  if ( pchan != nullptr )
  {
    v2 = pchan->soundsource;
    soundsource = v2;
  }
  else
  {
    soundsource = 0;
    v2 = 0;
  }
  if ( (host_map.m_nFlags & 0x1000) != 0 )
  {
    pszmap = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    pszmap = host_map.m_pParent->m_Value.m_pszString;
    if ( pszmap == nullptr )
      pszmap = defaultValue;
  }
  if ( rgpparseword[0] != nullptr )
  {
    v26 = 0;
    v29 = rgpparseword;
    do
    {
      if ( **v29 != 86 || (*v29)[1] != 95 )
        goto LABEL_76;
      v22 = *v29;
      cnew = 0;
      pszNew = nullptr;
      pszNew1 = nullptr;
      pszNew2 = nullptr;
      v3 = _V_strlen(str: v22);
      v21 = *v29;
      chtype = (*v29)[v3 - 1];
      _V_strcpy(dest: szparseword, src: v21);
      v4 = _V_strstr(s1: szparseword, search: "_MAP__");
      if ( v4 != nullptr )
      {
        v5 = 0;
        if ( g_cmapnames <= 0 )
          goto LABEL_18;
        do
        {
          v6 = (int)_V_strstr(s1: pszmap, search: g_rgmapnames[v5]);
          if ( v6 != 0 )
            break;
          ++v5;
        }
        while ( v5 < g_cmapnames );
        v6 = v5;
        if ( v5 >= 0 )
        {
          if ( v5 > 99 )
            v6 = 99;
        }
        else
        {
LABEL_18:
          v6 = 0;
        }
        v4[4] = 48;
        if ( v6 >= 10 )
          V_snprintf(pDest: v4 + 4, maxLen: 2, pFormat: "%d", v6);
        else
          V_snprintf(pDest: v4 + 5, maxLen: 1, pFormat: "%1d", v6);
        v2 = soundsource;
      }
      if ( _V_strstr(s1: szparseword, search: "V_MYNAME") != nullptr )
      {
        v7 = 1;
LABEL_29:
        v8 = 26 * VOX_LookupEntIndex(type: chtype, soundsource: v2, fallocnew: true);
        v9 = &dword_104DC2C8[v8];
        if ( v7 != 1 )
          v9 = &dword_104DC2CC[v8];
        v10 = (char *)*v9;
        v11 = v9;
        if ( *v9 == 0 )
        {
          v10 = VOX_LookupRndVirtual(pGroupName: szparseword);
          *v11 = v10;
        }
        v1 = v10;
        goto LABEL_74;
      }
      if ( _V_strstr(s1: szparseword, search: "V_MYNUM") != nullptr )
      {
        v7 = 0;
        goto LABEL_29;
      }
      if ( _V_strstr(s1: szparseword, search: "V_RND") != nullptr )
      {
        v1 = VOX_LookupRndVirtual(pGroupName: szparseword);
LABEL_74:
        cnew = 1;
        goto LABEL_75;
      }
      if ( _V_strstr(s1: szparseword, search: "V_DIST") != nullptr )
      {
        VOX_LookupRangeHeadingOrGrid(
          a1: (char *)&savedregs,
          irhg: 0,
          pGroupName: szparseword,
          pChannel: pchan,
          soundsource: v2,
          ppszNew: &pszNew,
          ppszNew1: &pszNew1,
          ppszNew2: &pszNew2,
          pcnew: &cnew,
          fsimple: true);
        v1 = pszNew;
      }
      else if ( _V_strstr(s1: szparseword, search: "V_DIR") != nullptr )
      {
        VOX_LookupRangeHeadingOrGrid(
          a1: (char *)&savedregs,
          irhg: 1,
          pGroupName: szparseword,
          pChannel: pchan,
          soundsource: v2,
          ppszNew: &pszNew,
          ppszNew1: &pszNew1,
          ppszNew2: &pszNew2,
          pcnew: &cnew,
          fsimple: false);
        v1 = pszNew;
      }
      else
      {
        if ( _V_strstr(s1: szparseword, search: "V_IDIED") != nullptr )
        {
          v12 = VOX_LookupEntIndex(type: chtype, soundsource: v2, fallocnew: false);
          if ( v12 < 0 )
          {
            _V_strcpy(dest: szgroup1, src: "V_MYNAME");
            szgroup1[8] = chtype;
            szgroup1[9] = 0;
            _V_strcpy(dest: szgroup2, src: "V_MYNUM");
            szgroup2[7] = chtype;
            szgroup2[8] = 0;
            v12 = VOX_LookupEntIndex(type: chtype, soundsource: v2, fallocnew: true);
            dword_104DC2C8[26 * v12] = (int)VOX_LookupRndVirtual(pGroupName: szgroup1);
            dword_104DC2CC[26 * v12] = (int)VOX_LookupRndVirtual(pGroupName: szgroup2);
            v2 = soundsource;
          }
          v13 = g_pSoundServices;
          v14 = 26 * v12;
          byte_104DC2F0[v14 * 4] = 1;
          v15 = ((double (__thiscall *)(ISoundServices *))v13->GetClientTime)(a1: v13);
          v16 = i;
          *(float *)&dword_104DC324[v14] = v15;
          if ( (unsigned int)v16 <= 0x1F )
          {
            *v29 = nullptr;
            if ( v16 < 31 )
            {
              qmemcpy(v29, &rgpparseword[v26 / 4 + 1], 4 * (31 - v16));
              v2 = soundsource;
            }
          }
          goto LABEL_75;
        }
        if ( _V_strstr(s1: szparseword, search: "V_WHODIED") != nullptr )
        {
          DeadIndex = VOX_LookupLastDeadIndex(type: chtype);
          if ( DeadIndex < 0 )
          {
            VOX_DeleteWord(iword: i);
          }
          else
          {
            v18 = 26 * DeadIndex;
            v1 = (char *)dword_104DC2C8[v18];
            v19 = (char *)dword_104DC2CC[v18];
            cnew = 1;
            pszNew1 = v19;
            if ( v19 != nullptr )
              cnew = 2;
          }
          goto LABEL_75;
        }
        if ( _V_strstr(s1: szparseword, search: "V_SECTOR") != nullptr )
        {
          v20 = VOX_LookupSectorVirtual(pGroupname: szparseword);
        }
        else
        {
          if ( _V_strstr(s1: szparseword, search: "V_GRIDX") != nullptr )
          {
            VOX_LookupRangeHeadingOrGrid(
              a1: (char *)&savedregs,
              irhg: 2,
              pGroupName: szparseword,
              pChannel: pchan,
              soundsource: v2,
              ppszNew: &pszNew,
              ppszNew1: &pszNew1,
              ppszNew2: &pszNew2,
              pcnew: &cnew,
              fsimple: true);
            v1 = pszNew;
            goto LABEL_75;
          }
          if ( _V_strstr(s1: szparseword, search: "V_GRIDY") != nullptr )
          {
            VOX_LookupRangeHeadingOrGrid(
              a1: (char *)&savedregs,
              irhg: 3,
              pGroupName: szparseword,
              pChannel: pchan,
              soundsource: v2,
              ppszNew: &pszNew,
              ppszNew1: &pszNew1,
              ppszNew2: &pszNew2,
              pcnew: &cnew,
              fsimple: true);
            v1 = pszNew;
            goto LABEL_75;
          }
          if ( _V_strstr(s1: szparseword, search: "V_G0_") != nullptr )
          {
            v20 = VOX_LookupGlobalVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 0);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_G1_") != nullptr )
          {
            v20 = VOX_LookupGlobalVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 1);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_G2_") != nullptr )
          {
            v20 = VOX_LookupGlobalVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 2);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_G3_") != nullptr )
          {
            v20 = VOX_LookupGlobalVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 3);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_SEQG0_") != nullptr )
          {
            v20 = VOX_LookupGlobalSeqVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 0);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_SEQG1_") != nullptr )
          {
            v20 = VOX_LookupGlobalSeqVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 1);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_SEQG2_") != nullptr )
          {
            v20 = VOX_LookupGlobalSeqVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 2);
          }
          else
          {
            if ( _V_strstr(s1: szparseword, search: "V_SEQG3_") == nullptr )
              goto LABEL_75;
            v20 = VOX_LookupGlobalSeqVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 3);
          }
        }
        v1 = v20;
        if ( v20 != nullptr )
          goto LABEL_74;
      }
LABEL_75:
      VOX_InsertWords(ireplace: i, cnew, pszNew: v1, pszNew1, pszNew2);
      v1 = nullptr;
LABEL_76:
      ++i;
      v26 = 4 * i;
      v29 = &rgpparseword[i];
    }
    while ( *v29 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A4E0
// Name: _VOX_LoadSound
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl VOX_LoadSound(channel_t *pchan, const char *pszin)
{
  const char *v2; // edi
  int v3; // ebx
  char *v4; // eax
  const char *Directory; // esi
  channel_t *v6; // esi
  int v7; // eax
  char *v8; // esi
  char **v9; // edi
  int *v10; // esi
  CSfxTable *Name; // eax
  bool v12; // zf
  CSentenceMixer *SentenceMixer; // eax
  CSfxTable *v14; // edx
  ISoundServices_vtbl *v15; // esi
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // [esp-1Ch] [ebp-F44h]
  float v19; // [esp+0h] [ebp-F28h]
  _BYTE dst[1153]; // [esp+10h] [ebp-F18h] OVERLAPPED BYREF
  _BYTE captionstream_1008[513]; // [esp+890h] [ebp-698h] OVERLAPPED BYREF
  char pathbuffer[260]; // [esp+AA0h] [ebp-488h] BYREF
  char groupname[512]; // [esp+BA4h] [ebp-384h] BYREF
  char szpath[260]; // [esp+DA4h] [ebp-184h] BYREF
  char captiontoken[128]; // [esp+EA8h] [ebp-80h] BYREF

  v2 = pszin;
  v3 = 0;
  captiontoken[127] = 0;
  *(_WORD *)&captiontoken[120] = -1;
  *(_DWORD *)&captiontoken[112] = 0;
  if ( pszin != nullptr )
  {
    memset(dst, value: 0, count: 0x480u);
    memset(dst: captionstream_1008, value: 0, count: 0x200u);
    v4 = VOX_LookupString(
           pSentenceName: pszin,
           psentencenum: nullptr,
           pbEmitCaption: (bool *)&captiontoken[127],
           pCaptionSymbol: (CUtlSymbol *)&captiontoken[120],
           pflDuration: (float *)&captiontoken[112]);
    if ( v4 != nullptr )
    {
      Directory = VOX_GetDirectory(szpath: &groupname[496], maxpath: 260, psz: v4);
      if ( (unsigned int)_V_strlen(str: Directory) <= 0x1FF )
      {
        V_strncpy(pDest: captionstream_1008, pSrc: Directory, maxLen: 512);
        VOX_ParseString(psz: captionstream_1008);
        v6 = pchan;
        VOX_ReplaceVirtualNames(pchan);
        *(_DWORD *)&captiontoken[116] = 0;
        V_strncpy(pDest: &pathbuffer[244], pSrc: pszin, maxLen: 512);
        v7 = _V_strlen(str: &pathbuffer[244]);
        if ( v7 > 0 )
        {
          v8 = &pathbuffer[v7 + 243];
          do
          {
            if ( isdigit(c: *v8) == 0 )
              break;
            *v8-- = 0;
          }
          while ( (int)&v8[1 - (_DWORD)&pathbuffer[244]] > 0 );
          v6 = pchan;
          v2 = pszin;
        }
        V_snprintf(pDest: &dst[1152], maxLen: 1024, pFormat: "%s ", &pathbuffer[244]);
        if ( rgpparseword[0] != nullptr )
        {
          v9 = rgpparseword;
          v10 = (int *)&dst[20];
          do
          {
            if ( VOX_ParseWordParams(
                   psz: *v9,
                   pvoxword: (voxword_t *)(v10 - 5),
                   fFirst: *(_DWORD *)&captiontoken[116] == 0) != 0 )
            {
              V_snprintf(pDest: &captionstream_1008[512], maxLen: 260, pFormat: "%s%s.wav", &groupname[496], *v9);
              Name = S_FindName(szName: &captionstream_1008[512], pInCache: v10);
              v18 = *v9;
              v10[3] = (int)Name;
              *v10 = 1;
              V_snprintf(pDest: &szpath[244], maxLen: 128, pFormat: "S(%s%s) ", &groupname[496], v18);
              V_strncat(pDest: &dst[1152], pSrc: &szpath[244], destBufferSize: 0x400u, max_chars_to_copy: -1);
              ++v3;
              v10 += 9;
            }
            v12 = rgpparseword[*(_DWORD *)&captiontoken[116] + 1] == nullptr;
            v9 = &rgpparseword[++*(_DWORD *)&captiontoken[116]];
          }
          while ( !v12 );
          v6 = pchan;
          v2 = pszin;
        }
        v6->pMixer = nullptr;
        if ( v3 != 0 )
        {
          SentenceMixer = CreateSentenceMixer(pWords: (voxword_t *)dst);
          v6->pMixer = SentenceMixer;
          if ( SentenceMixer != nullptr )
          {
            v14 = *(CSfxTable **)&dst[32];
            LOBYTE(v6->flagsword) |= 2u;
            v6->sfx = v14;
            if ( g_pSoundServices != nullptr )
            {
              if ( captiontoken[127] != 0 )
              {
                if ( *(_WORD *)&captiontoken[120] == 0xFFFF )
                {
                  ((void (__stdcall *)(_BYTE *))g_pSoundServices->EmitSentenceCloseCaption)(a1: &dst[1152]);
                  if ( snd_vox_captiontrace.m_pParent != nullptr
                    && snd_vox_captiontrace.m_pParent->m_Value.m_nValue != 0 )
                  {
                    _Msg(a1: "Vox: captionstream '%s'\n", &dst[1152]);
                  }
                }
                else
                {
                  v15 = g_pSoundServices->__vftable;
                  v19 = *(float *)&captiontoken[112];
                  v16 = CUtlSymbol::String(this: (CUtlSymbol *)&captiontoken[120]);
                  ((void (__thiscall *)(ISoundServices *, const char *, _DWORD))v15->EmitCloseCaption)(
                    a1: g_pSoundServices,
                    a2: v16,
                    a3: LODWORD(v19));
                  if ( snd_vox_captiontrace.m_pParent != nullptr
                    && snd_vox_captiontrace.m_pParent->m_Value.m_nValue != 0 )
                  {
                    v17 = CUtlSymbol::String(this: (CUtlSymbol *)&captiontoken[120]);
                    _Msg(a1: "Vox: caption '%s'\n", v17);
                  }
                }
              }
              else if ( snd_vox_captiontrace.m_pParent != nullptr
                     && snd_vox_captiontrace.m_pParent->m_Value.m_nValue != 0 )
              {
                _Msg(a1: "Vox:  No caption for '%s'\n", v2);
              }
            }
          }
        }
      }
      else
      {
        DevMsg(a1: "VOX_LoadSound: sentence is too long %s\n", Directory);
      }
    }
    else
    {
      DevMsg(a1: "VOX_LoadSound: no sentence named %s\n", pszin);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B230
// Name: void VOX_AddNumbers(char __near *,class CUtlVector<struct WordBuf,class CUtlMemory<struct WordBuf,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_AddNumbers(char *pGroupName, CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > *list)
{
  int v2; // ebx
  int v3; // edi
  char v4; // al
  int v5; // ebx
  const char *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  WordBuf *m_pMemory; // ecx
  int v10; // eax
  WordBuf *v11; // edi
  int v12; // [esp-18h] [ebp-138h]
  WordBuf w; // [esp+Ch] [ebp-114h] BYREF
  char sznumbers[16]; // [esp+10Ch] [ebp-14h] BYREF
  int i; // [esp+11Ch] [ebp-4h]

  i = 0;
  do
  {
    v2 = _V_strlen(str: pGroupName);
    v3 = _V_strlen(str: "V_NUMBERS");
    _V_strcpy(dest: sznumbers, src: "V_NUMBERS");
    v4 = pGroupName[v2 - 1];
    v5 = i;
    v12 = i;
    sznumbers[v3] = v4;
    sznumbers[v3 + 1] = 0;
    w.word[0] = 0;
    v6 = VOX_LookupSentenceByIndex(pGroupname: sznumbers, ipick: v12, pipicknext: nullptr);
    WordBuf::Set(this: &w, w: v6);
    m_Size = list->m_Size;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<WordBuf,int>::Grow(this: &list->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v10 = list->m_Size - m_Size - 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v10 << 8);
    v11 = &list->m_Memory.m_pMemory[m_Size];
    if ( v11 != nullptr )
      V_strncpy(pDest: v11->word, pSrc: w.word, maxLen: 256);
    i = v5 + 1;
  }
  while ( v5 + 1 <= 30 );
}

//------------------------------------------------------------------------------
// Address: 0x1005B320
// Name: void VOX_AddRndVirtual(char __near *,class CUtlVector<struct WordBuf,class CUtlMemory<struct WordBuf,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_AddRndVirtual(char *pGroupName, CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > *list)
{
  int v2; // eax
  CUtlSymbol *i; // ecx
  int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // edi
  char *pName; // ebx
  const char *v9; // eax
  int count; // ecx
  unsigned __int16 m_Id; // [esp-4h] [ebp-140h]
  WordBuf w; // [esp+Ch] [ebp-130h] BYREF
  char szsentencename[32]; // [esp+10Ch] [ebp-30h] BYREF
  char *v14; // [esp+12Ch] [ebp-10h]
  unsigned int v15; // [esp+130h] [ebp-Ch]
  int m_Size; // [esp+134h] [ebp-8h]
  int snum; // [esp+138h] [ebp-4h]

  if ( pGroupName != nullptr )
  {
    CUtlSymbolTable::AddString(
      this: &sentencegroup_t::s_SymbolTable,
      result: (CUtlSymbol *)&pGroupName,
      pString: pGroupName);
    v2 = 0;
    if ( g_SentenceGroups.m_Size > 0 )
    {
      for ( i = &g_SentenceGroups.m_Memory.m_pMemory->groupname; (_WORD)pGroupName != i->m_Id; i += 3 )
      {
        if ( ++v2 >= g_SentenceGroups.m_Size )
          return;
      }
      if ( v2 >= 0 )
      {
        v4 = v2;
        m_Id = g_SentenceGroups.m_Memory.m_pMemory[v2].groupname.m_Id;
        v15 = 6 * v2;
        v14 = CUtlSymbolTable::String(this: &sentencegroup_t::s_SymbolTable, id: (CUtlSymbol)m_Id);
        v5 = 0;
        snum = 0;
        if ( g_SentenceGroups.m_Memory.m_pMemory[v4].count > 0 )
        {
          do
          {
            V_snprintf(pDest: szsentencename, maxLen: 32, pFormat: "%s%d", v14, v5);
            if ( szsentencename[0] == 33 )
              pGroupName = &szsentencename[1];
            else
              pGroupName = szsentencename;
            v6 = 0;
            m_Size = g_Sentences.m_Size;
            if ( g_Sentences.m_Size > 0 )
            {
              v7 = 0;
              while ( 1 )
              {
                pName = g_Sentences.m_Memory.m_pMemory[v7].pName;
                if ( _V_stricmp(s1: pGroupName, s2: pName) == 0 )
                  break;
                ++v6;
                ++v7;
                if ( v6 >= m_Size )
                  goto LABEL_19;
              }
              v9 = &pName[_V_strlen(str: pName) + 1];
              if ( v9 != nullptr )
              {
                w.word[0] = 0;
                WordBuf::Set(this: &w, w: v9);
                CUtlVector<WordBuf,CUtlMemory<WordBuf,int>>::InsertBefore(this: list, elem: list->m_Size, src: &w);
              }
            }
LABEL_19:
            count = g_SentenceGroups.m_Memory.m_pMemory[v15 / 6].count;
            v5 = snum + 1;
            snum = v5;
          }
          while ( v5 < count );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B480
// Name: VOX_BuildVirtualNameList
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_BuildVirtualNameList(char *word, CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > *list)
{
  char v2; // bl
  char *v3; // eax
  char *v4; // edi
  int v5; // esi
  _BYTE *v6; // ebx
  WordBuf w; // [esp+Ch] [ebp-240h] BYREF
  char szgroup1[32]; // [esp+10Ch] [ebp-140h] BYREF
  char szgroup2[32]; // [esp+12Ch] [ebp-120h] BYREF
  char szparseword[256]; // [esp+14Ch] [ebp-100h] BYREF

  v2 = word[_V_strlen(str: word) - 1];
  V_strncpy(pDest: szparseword, pSrc: word, maxLen: 256);
  v3 = _V_strstr(s1: szparseword, search: "_MAP__");
  v4 = v3;
  if ( v3 != nullptr )
  {
    v5 = 0;
    if ( g_cmapnames > 0 )
    {
      v6 = v3 + 4;
      do
      {
        *v6 = 48;
        if ( v5 >= 10 )
          V_snprintf(pDest: v4 + 4, maxLen: 2, pFormat: "%d", v5);
        else
          V_snprintf(pDest: v4 + 5, maxLen: 1, pFormat: "%1d", v5);
        VOX_BuildVirtualNameList(word: szparseword, list);
        ++v5;
      }
      while ( v5 < g_cmapnames );
    }
    return;
  }
  if ( _V_strstr(s1: szparseword, search: "V_MYNAME") != nullptr
    || _V_strstr(s1: szparseword, search: "V_MYNUM") != nullptr
    || _V_strstr(s1: szparseword, search: "V_RND") != nullptr )
  {
    goto LABEL_32;
  }
  if ( _V_strstr(s1: szparseword, search: "V_DIST") != nullptr || _V_strstr(s1: szparseword, search: "V_DIR") != nullptr )
    goto LABEL_23;
  if ( _V_strstr(s1: szparseword, search: "V_IDIED") != nullptr )
  {
    _V_strcpy(dest: szgroup1, src: "V_MYNAME");
    szgroup1[8] = v2;
    szgroup1[9] = 0;
    _V_strcpy(dest: szgroup2, src: "V_MYNUM");
    szgroup2[7] = v2;
    szgroup2[8] = 0;
    VOX_BuildVirtualNameList(word: szgroup1, list);
    VOX_BuildVirtualNameList(word: szgroup2, list);
    return;
  }
  if ( _V_strstr(s1: szparseword, search: "V_WHODIED") == nullptr )
  {
    if ( _V_strstr(s1: szparseword, search: "V_SECTOR") != nullptr
      || _V_strstr(s1: szparseword, search: "V_GRIDX") != nullptr
      || _V_strstr(s1: szparseword, search: "V_GRIDY") != nullptr )
    {
LABEL_23:
      VOX_AddNumbers(pGroupName: szparseword, list);
      goto LABEL_33;
    }
    if ( _V_strstr(s1: szparseword, search: "V_G0_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_G1_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_G2_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_G3_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_SEQG0_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_SEQG1_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_SEQG2_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_SEQG3_") != nullptr )
    {
LABEL_32:
      VOX_AddRndVirtual(pGroupName: szparseword, list);
    }
  }
LABEL_33:
  if ( V_strnicmp(s1: szparseword, s2: "V_", n: 2) != 0 )
  {
    w.word[0] = 0;
    WordBuf::Set(this: &w, w: szparseword);
    CUtlVector<WordBuf,CUtlMemory<WordBuf,int>>::InsertBefore(this: list, elem: list->m_Size, src: &w);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B850
// Name: int VOX_GroupAdd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_GroupAdd(const char *pSentenceName)
{
  signed int v1; // esi
  void *v2; // esp
  int v3; // esi
  sentencegroup_t *v4; // eax
  int v5; // esi
  sentencegroup_t *v6; // edi
  char v8[14]; // [esp+0h] [ebp-14h] BYREF
  CUtlSymbol v9; // [esp+Eh] [ebp-6h] BYREF
  CUtlSymbol symGroupName; // [esp+10h] [ebp-4h] BYREF

  v1 = strlen(pSentenceName) - 1;
  if ( v1 <= 0 || isdigit(c: pSentenceName[v1]) == 0 )
    return -1;
  do
  {
    if ( isdigit(c: pSentenceName[v1]) == 0 )
      break;
    --v1;
  }
  while ( v1 > 0 );
  v2 = alloca(v1 + 2);
  V_strncpy(pDest: v8, pSrc: pSentenceName, maxLen: v1 + 2);
  CUtlSymbolTable::AddString(this: &sentencegroup_t::s_SymbolTable, result: &symGroupName, pString: v8);
  v3 = 0;
  if ( g_SentenceGroups.m_Size <= 0 )
  {
LABEL_8:
    v5 = CUtlVector<sentencegroup_t,CUtlMemory<sentencegroup_t,int>>::InsertBefore(
           this: &g_SentenceGroups,
           elem: g_SentenceGroups.m_Size);
    v6 = &g_SentenceGroups.m_Memory.m_pMemory[v5];
    v6->groupname = (CUtlSymbol)CUtlSymbolTable::AddString(
                                  this: &sentencegroup_t::s_SymbolTable,
                                  result: &v9,
                                  pString: v8)->m_Id;
    v6->count = 1;
    return v5;
  }
  else
  {
    while ( symGroupName.m_Id != g_SentenceGroups.m_Memory.m_pMemory[(g_SentenceGroups.m_Size + v3 - 1)
                                                                   % g_SentenceGroups.m_Size].groupname.m_Id )
    {
      if ( ++v3 >= g_SentenceGroups.m_Size )
        goto LABEL_8;
    }
    v4 = &g_SentenceGroups.m_Memory.m_pMemory[(g_SentenceGroups.m_Size + v3 - 1) % g_SentenceGroups.m_Size];
    ++v4->count;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B960
// Name: void VOX_Precache(class IEngineSound __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_Precache(IEngineSound *pSoundSystem, unsigned int sentenceIndex, const char *pPathOverride)
{
  sentence_t *m_pMemory; // ebx
  unsigned int v4; // edi
  char *pName; // eax
  int v6; // esi
  int v7; // eax
  const char *Directory; // eax
  char *v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // eax
  char *v13; // ebx
  int m_Size; // ebx
  WordBuf *v15; // eax
  voxword_t rgvoxword[32]; // [esp+Ch] [ebp-920h] BYREF
  char buffer[512]; // [esp+48Ch] [ebp-4A0h] BYREF
  char *pWords[32]; // [esp+68Ch] [ebp-2A0h]
  char pathbuffer[260]; // [esp+70Ch] [ebp-220h] BYREF
  char szpath[260]; // [esp+810h] [ebp-11Ch] BYREF
  int count; // [esp+914h] [ebp-18h]
  CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > list; // [esp+918h] [ebp-14h] BYREF
  voxword_t *sentenceIndexa; // [esp+938h] [ebp+Ch]
  int i; // [esp+93Ch] [ebp+10h]

  m_pMemory = g_Sentences.m_Memory.m_pMemory;
  v4 = sentenceIndex;
  pName = g_Sentences.m_Memory.m_pMemory[sentenceIndex].pName;
  if ( *pName != 86 || pName[1] != 95 )
  {
    *((_BYTE *)&g_Sentences.m_Memory.m_pMemory[v4] + 8) |= 0x80u;
    m_pMemory = g_Sentences.m_Memory.m_pMemory;
  }
  v6 = 0;
  memset(dst: (unsigned __int8 *)rgvoxword, value: 0, count: sizeof(rgvoxword));
  v7 = _V_strlen(str: m_pMemory[v4].pName);
  Directory = VOX_GetDirectory(szpath, maxpath: 260, psz: &m_pMemory[v4].pName[v7 + 1]);
  V_strncpy(pDest: buffer, pSrc: Directory, maxLen: 512);
  if ( pPathOverride != nullptr )
    V_strncpy(pDest: szpath, pSrc: pPathOverride, maxLen: 260);
  VOX_ParseString(psz: buffer);
  v9 = rgpparseword[0];
  v10 = 0;
  count = 0;
  if ( rgpparseword[0] != nullptr )
  {
    v11 = 0;
    do
    {
      ++v10;
      pWords[v11] = v9;
      v11 = v10;
      v9 = rgpparseword[v10];
    }
    while ( v9 != nullptr );
    count = v10;
  }
  v12 = 0;
  i = 0;
  if ( v10 > 0 )
  {
    sentenceIndexa = rgvoxword;
    while ( 1 )
    {
      v13 = pWords[v12];
      if ( *v13 == 86 && v13[1] == 95 )
      {
        memset(&list, 0, sizeof(list));
        VOX_BuildVirtualNameList(word: v13, &list);
        m_Size = list.m_Size;
        if ( list.m_Size > 0 )
        {
          do
          {
            V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s%s.wav", szpath, list.m_Memory.m_pMemory[v6].word);
            pSoundSystem->PrecacheSound(this: pSoundSystem, a2: pathbuffer, a3: false, a4: false);
            ++v6;
            --m_Size;
          }
          while ( m_Size != 0 );
          v6 = 0;
        }
        v15 = list.m_Memory.m_pMemory;
        list.m_Size = 0;
        if ( list.m_Memory.m_nGrowSize >= 0 )
        {
          if ( list.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
            v15 = nullptr;
            list.m_Memory.m_pMemory = nullptr;
          }
          list.m_Memory.m_nAllocationCount = 0;
        }
        list.m_pElements = v15;
        if ( list.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      }
      else if ( VOX_ParseWordParams(psz: v13, pvoxword: sentenceIndexa, fFirst: v12 == 0) != 0 )
      {
        V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s%s.wav", szpath, v13);
        pSoundSystem->PrecacheSound(this: pSoundSystem, a2: pathbuffer, a3: false, a4: false);
        ++sentenceIndexa;
      }
      if ( ++i >= count )
        break;
      v12 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BB90
// Name: _VOX_PrecacheSentenceGroup
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_PrecacheSentenceGroup(IEngineSound *pSoundSystem, const char *pGroupName, const char *pPathOverride)
{
  signed int v3; // esi
  int v4; // edi
  int len; // [esp+4h] [ebp-4h]

  v3 = 0;
  len = _V_strlen(str: pGroupName);
  if ( g_Sentences.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      if ( *((char *)&g_Sentences.m_Memory.m_pMemory[v4] + 8) >= 0
        && V_strncasecmp(s1: g_Sentences.m_Memory.m_pMemory[v4].pName, s2: pGroupName, n: len) == 0 )
      {
        VOX_Precache(pSoundSystem, sentenceIndex: v3, pPathOverride);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < g_Sentences.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BC10
// Name: void VOX_TouchSounds(class CUtlDict<int,int> __near &,class CUtlRBTree<struct ccpair,int,bool (*)(struct ccpair const __near &,struct ccpair const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ccpair,int>,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_TouchSounds(
        CUtlDict<int,int> *list,
        CUtlRBTree<ccpair,int,bool (__cdecl*)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int> > *ccpairs,
        bool spewsentences)
{
  int i; // esi
  void *v4; // eax
  UtlRBTreeNode_t<ccpair,int> *j; // esi
  void *v6; // edi
  UtlRBTreeNode_t<ccpair,int> *Inorder; // esi
  IBaseFileSystem_vtbl *v8; // edi
  int v9; // eax
  char outline[512]; // [esp+8h] [ebp-200h] BYREF
  void *fh; // [esp+218h] [ebp+10h]

  for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &list->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &list->m_Elements.m_Tree,
              i) )
  {
    V_snprintf(
      pDest: outline,
      maxLen: 512,
      pFormat: "sound/%s",
      list->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: outline, a3: "rb", a4: 0);
    if ( v4 != nullptr )
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
  }
  if ( spewsentences )
  {
    for ( j = (UtlRBTreeNode_t<ccpair,int> *)CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::FirstInorder(this: ccpairs);
          j != (UtlRBTreeNode_t<ccpair,int> *)-1;
          j = CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::NextInorder(
                this: ccpairs,
                i: (int)j) )
    {
      _Msg(
        a1: "\"%s\"\t\"%s\"\n",
        ccpairs->m_Elements.m_pMemory[(_DWORD)j].m_Data.token.word,
        ccpairs->m_Elements.m_pMemory[(_DWORD)j].m_Data.value.word);
    }
    v6 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: "sentences.m3u", a3: "wt", a4: "GAME");
    fh = v6;
    if ( v6 != nullptr )
    {
      Inorder = (UtlRBTreeNode_t<ccpair,int> *)CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::FirstInorder(this: ccpairs);
      if ( Inorder != (UtlRBTreeNode_t<ccpair,int> *)-1 )
      {
        do
        {
          V_snprintf(
            pDest: outline,
            maxLen: 512,
            pFormat: "%s\n",
            ccpairs->m_Elements.m_pMemory[(_DWORD)Inorder].m_Data.fullpath.word);
          v8 = g_pFileSystem->IBaseFileSystem::__vftable;
          v9 = _V_strlen(str: outline);
          v8->Write(this: &g_pFileSystem->IBaseFileSystem, a2: outline, a3: v9, a4: fh);
          Inorder = CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::NextInorder(
                      this: ccpairs,
                      i: (int)Inorder);
        }
        while ( Inorder != (UtlRBTreeNode_t<ccpair,int> *)-1 );
        v6 = fh;
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BDC0
// Name: void VOX_GroupInitAllLRUs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_GroupInitAllLRUs()
{
  int v0; // ecx
  int v1; // esi
  int v2; // eax
  unsigned __int8 *m_pMemory; // edx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // edi

  v0 = 0;
  v1 = 0;
  if ( g_SentenceGroups.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      g_SentenceGroups.m_Memory.m_pMemory[v2].lru = v1;
      ++v0;
      v1 += g_SentenceGroups.m_Memory.m_pMemory[v2++].count;
    }
    while ( v0 < g_SentenceGroups.m_Size );
  }
  m_pMemory = g_GroupLRU.m_Memory.m_pMemory;
  m_Size = 0;
  g_GroupLRU.m_Size = 0;
  if ( g_GroupLRU.m_Memory.m_nGrowSize < 0 )
  {
    m_nAllocationCount = g_GroupLRU.m_Memory.m_nAllocationCount;
  }
  else
  {
    if ( g_GroupLRU.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_GroupLRU.m_Memory.m_pMemory);
      m_Size = g_GroupLRU.m_Size;
      m_pMemory = nullptr;
      g_GroupLRU.m_Memory.m_pMemory = nullptr;
    }
    m_nAllocationCount = 0;
    g_GroupLRU.m_Memory.m_nAllocationCount = 0;
  }
  g_GroupLRU.m_pElements = m_pMemory;
  if ( m_Size < v1 )
  {
    v6 = v1 - m_Size;
    v7 = m_Size;
    if ( v6 != 0 )
    {
      if ( m_Size + v6 > m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)&g_GroupLRU, num: v6 + m_Size - m_nAllocationCount);
        m_Size = g_GroupLRU.m_Size;
        m_pMemory = g_GroupLRU.m_Memory.m_pMemory;
      }
      g_GroupLRU.m_Size = v6 + m_Size;
      v8 = m_Size - v7;
      g_GroupLRU.m_pElements = m_pMemory;
      if ( v8 > 0 && v6 > 0 )
        _V_memmove(dest: &m_pMemory[v7 + v6], src: &m_pMemory[v7], count: v8);
    }
  }
  v9 = 0;
  if ( g_SentenceGroups.m_Size > 0 )
  {
    v10 = 0;
    do
    {
      VOX_LRUInit(pGroup: (int)&g_SentenceGroups.m_Memory.m_pMemory[v10]);
      ++v9;
      ++v10;
    }
    while ( v9 < g_SentenceGroups.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BFB0
// Name: void VOX_CompactSentenceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_CompactSentenceFile()
{
  int v0; // edi
  int v1; // ebx
  int v2; // esi
  int m_Size; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // edi
  int v9; // eax
  char *v10; // ebx
  unsigned int v11; // edi
  int totalMem; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  for ( i = 0; i < g_Sentences.m_Size; ++i )
  {
    v2 = _V_strlen(str: g_Sentences.m_Memory.m_pMemory[v0].pName) + 1;
    v1 += v2 + _V_strlen(str: &g_Sentences.m_Memory.m_pMemory[v0++].pName[v2]) + 1;
  }
  m_Size = g_SentenceFile.m_Size;
  if ( g_SentenceFile.m_Size < v1 )
  {
    v4 = v1 - g_SentenceFile.m_Size;
    v5 = g_SentenceFile.m_Size;
    if ( v4 != 0 )
    {
      if ( g_SentenceFile.m_Size + v4 > g_SentenceFile.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(
          this: &g_SentenceFile.m_Memory,
          num: v4 + g_SentenceFile.m_Size - g_SentenceFile.m_Memory.m_nAllocationCount);
        m_Size = g_SentenceFile.m_Size;
      }
      g_SentenceFile.m_Size = v4 + m_Size;
      v6 = m_Size - v5;
      g_SentenceFile.m_pElements = g_SentenceFile.m_Memory.m_pMemory;
      if ( v6 > 0 && v4 > 0 )
        _V_memmove(
          dest: &g_SentenceFile.m_Memory.m_pMemory[v5 + v4],
          src: &g_SentenceFile.m_Memory.m_pMemory[v5],
          count: v6);
    }
  }
  v7 = 0;
  totalMem = 0;
  for ( ia = 0; ia < g_Sentences.m_Size; ++ia )
  {
    v8 = _V_strlen(str: g_Sentences.m_Memory.m_pMemory[v7].pName) + 1;
    v9 = _V_strlen(str: &g_Sentences.m_Memory.m_pMemory[v7].pName[v8]);
    v10 = &g_SentenceFile.m_Memory.m_pMemory[totalMem];
    v11 = v9 + 1 + v8;
    memcpy(
      dst: (unsigned __int8 *)&g_SentenceFile.m_Memory.m_pMemory[totalMem],
      src: (unsigned __int8 *)g_Sentences.m_Memory.m_pMemory[v7].pName,
      count: v11);
    totalMem += v11;
    g_Sentences.m_Memory.m_pMemory[v7++].pName = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C0F0
// Name: public: int CUtlMap<char const __near *,int,int>::Insert(char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,int,int>::Insert(CUtlMap<char const *,int,int> *this, const char **key)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  CUtlMap<char const *,int,int>::Node_t node; // [esp+8h] [ebp-Ch] BYREF
  int parent; // [esp+10h] [ebp-4h] BYREF

  node.key = *key;
  parent = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    &parent,
    leftchild: (bool *)&key);
  v3 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v3,
    parent,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
    m_pMemory[v3].m_Data = node;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1005C160
// Name: public: int CUtlDict<int,int>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,int>::Insert(CUtlDict<int,int> *this, char *pName)
{
  const char *v2; // edi
  char *v4; // eax

  v2 = pName;
  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v4, v2);
    pName = v4;
    return CUtlMap<char const *,int,int>::Insert(this: &this->m_Elements, key: (const char **)&pName);
  }
  else
  {
    pName = nullptr;
    return CUtlMap<char const *,int,int>::Insert(this: &this->m_Elements, key: (const char **)&pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C1D0
// Name: void VOX_TouchSound(char const __near *,class CUtlDict<int,int> __near &,class CUtlRBTree<struct ccpair,int,bool (*)(struct ccpair const __near &,struct ccpair const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ccpair,int>,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_TouchSound(
        const char *pszin,
        CUtlDict<int,int> *filelist,
        CUtlRBTree<ccpair,int,bool (__cdecl*)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int> > *ccpairs,
        bool spewsentences)
{
  int v4; // esi
  const char *v5; // edi
  char *v6; // eax
  const char *Directory; // esi
  WordBuf *m_pMemory; // eax
  const char **v9; // esi
  int v10; // esi
  const char *v11; // eax
  const char *v12; // eax
  int v13; // esi
  const char *v14; // edi
  char *v15; // [esp-10h] [ebp-ED8h]
  const char *v16; // [esp-10h] [ebp-ED8h]
  const char *v17; // [esp-10h] [ebp-ED8h]
  const char *v18; // [esp-Ch] [ebp-ED4h]
  const char *v19; // [esp-Ch] [ebp-ED4h]
  const char *v20; // [esp-Ch] [ebp-ED4h]
  const char *v21; // [esp-Ch] [ebp-ED4h]
  voxword_t rgvoxword[32]; // [esp+4h] [ebp-EC4h] BYREF
  char buffer[512]; // [esp+484h] [ebp-A44h] BYREF
  char pDest[256]; // [esp+684h] [ebp-844h] BYREF
  ccpair pair; // [esp+784h] [ebp-744h] BYREF
  WordBuf w; // [esp+A84h] [ebp-444h] BYREF
  char szpath[260]; // [esp+B84h] [ebp-344h] BYREF
  char name[256]; // [esp+C88h] [ebp-240h] BYREF
  char pathbuffer[260]; // [esp+D88h] [ebp-140h] BYREF
  CUtlMap<char const *,int,int>::Node_t v30; // [esp+E8Ch] [ebp-3Ch] BYREF
  CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > list; // [esp+E94h] [ebp-34h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+EA8h] [ebp-20h] BYREF
  CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > rep; // [esp+EB0h] [ebp-18h] BYREF
  int c; // [esp+EC4h] [ebp-4h]
  int i; // [esp+ED0h] [ebp+8h]

  if ( pszin != nullptr )
  {
    memset(dst: (unsigned __int8 *)rgvoxword, value: 0, count: sizeof(rgvoxword));
    memset(dst: (unsigned __int8 *)buffer, value: 0, count: sizeof(buffer));
    v4 = 0;
    c = g_Sentences.m_Size;
    if ( g_Sentences.m_Size <= 0 )
      goto LABEL_8;
    search.elem = 0;
    while ( 1 )
    {
      v5 = *(char **)((char *)&g_Sentences.m_Memory.m_pMemory->pName + search.elem);
      if ( _V_stricmp(s1: pszin, s2: v5) == 0 )
        break;
      search.elem += 12;
      if ( ++v4 >= c )
        goto LABEL_8;
    }
    v6 = (char *)&v5[_V_strlen(str: v5) + 1];
    if ( v6 != nullptr )
    {
      Directory = VOX_GetDirectory(szpath, maxpath: 260, psz: v6);
      if ( (unsigned int)_V_strlen(str: Directory) <= 0x1FF )
      {
        V_strncpy(pDest: buffer, pSrc: Directory, maxLen: 512);
        VOX_ParseString(psz: buffer);
        m_pMemory = nullptr;
        i = 0;
        memset(&rep, 0, sizeof(rep));
        if ( rgpparseword[0] != nullptr )
        {
          v9 = (const char **)rgpparseword;
          do
          {
            if ( VOX_ParseWordParams(psz: (char *)*v9, pvoxword: rgvoxword, fFirst: i == 0) != 0 )
            {
              if ( V_strnicmp(s1: *v9, s2: "V_", n: 2) != 0 )
              {
                V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s%s.wav", szpath, *v9);
                v30.key = pathbuffer;
                if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                       this: &filelist->m_Elements.m_Tree,
                       search: &v30) == -1 )
                  CUtlDict<int,int>::Insert(this: filelist, pName: pathbuffer);
                v19 = *v9;
                w.word[0] = 0;
                WordBuf::Set(this: &w, w: v19);
                CUtlVector<WordBuf,CUtlMemory<WordBuf,int>>::InsertBefore(this: &rep, elem: rep.m_Size, src: &w);
                v20 = *v9;
                pair.token.word[0] = 0;
                pair.value.word[0] = 0;
                pair.fullpath.word[0] = 0;
                V_snprintf(pDest: pair.token.word, maxLen: 256, pFormat: "S(%s%s)", szpath, v20);
                WordBuf::Set(this: &pair.value, w: *v9);
                v12 = (const char *)((int (__thiscall *)(ISoundServices *, char *, const char *))g_pSoundServices->GetGameDir)(
                                      a1: g_pSoundServices,
                                      a2: szpath,
                                      a3: *v9);
                V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s/sound/%s%s.wav", v12, v17, v21);
                V_FixSlashes(pname: pathbuffer, separator: 92);
                WordBuf::Set(this: &pair.fullpath, w: pathbuffer);
                if ( CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Find(
                       this: ccpairs,
                       search: &pair) == -1 )
                  CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Insert(
                    this: ccpairs,
                    insert: &pair);
              }
              else
              {
                v15 = (char *)*v9;
                memset(&list, 0, sizeof(list));
                VOX_BuildVirtualNameList(word: v15, &list);
                v10 = 0;
                for ( c = list.m_Size; v10 < c; ++v10 )
                {
                  V_snprintf(pDest: name, maxLen: 256, pFormat: "%s", list.m_Memory.m_pMemory[v10].word);
                  if ( V_strnicmp(s1: name, s2: "V_", n: 2) == 0 )
                    _Warning(a1: "VOX_TouchSound didn't resolve virtual token %s!\n", name);
                  V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s%s.wav", szpath, name);
                  search.key = pathbuffer;
                  if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                         this: &filelist->m_Elements.m_Tree,
                         &search) == -1 )
                    CUtlDict<int,int>::Insert(this: filelist, pName: pathbuffer);
                  w.word[0] = 0;
                  if ( v10 == 0 )
                  {
                    WordBuf::Set(this: &w, w: name);
                    CUtlVector<WordBuf,CUtlMemory<WordBuf,int>>::InsertBefore(this: &rep, elem: rep.m_Size, src: &w);
                  }
                  pair.token.word[0] = 0;
                  pair.value.word[0] = 0;
                  pair.fullpath.word[0] = 0;
                  V_snprintf(pDest: pair.token.word, maxLen: 256, pFormat: "S(%s%s)", szpath, name);
                  WordBuf::Set(this: &pair.value, w: name);
                  v11 = (const char *)((int (__thiscall *)(ISoundServices *, char *, char *))g_pSoundServices->GetGameDir)(
                                        a1: g_pSoundServices,
                                        a2: szpath,
                                        a3: name);
                  V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s/sound/%s%s.wav", v11, v16, v18);
                  V_FixSlashes(pname: pathbuffer, separator: 92);
                  WordBuf::Set(this: &pair.fullpath, w: pathbuffer);
                  if ( CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Find(
                         this: ccpairs,
                         search: &pair) == -1 )
                    CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Insert(
                      this: ccpairs,
                      insert: &pair);
                }
                CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&list);
              }
            }
            v9 = (const char **)&rgpparseword[++i];
          }
          while ( *v9 != nullptr );
          m_pMemory = rep.m_Memory.m_pMemory;
        }
        if ( spewsentences )
        {
          v13 = 0;
          pDest[0] = 0;
          if ( rep.m_Size > 0 )
          {
            v14 = (const char *)m_pMemory;
            do
            {
              V_strncat(pDest, pSrc: v14, destBufferSize: 0x400u, max_chars_to_copy: -1);
              if ( v13 != rep.m_Size - 1 )
                V_strncat(pDest, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
              ++v13;
              v14 += 256;
            }
            while ( v13 < rep.m_Size );
          }
          _Msg(a1: "     %s\n", pDest);
          m_pMemory = rep.m_Memory.m_pMemory;
        }
        if ( rep.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      }
      else
      {
        DevMsg(a1: "VOX_TouchSound: sentence is too long %s\n", Directory);
      }
    }
    else
    {
LABEL_8:
      DevMsg(a1: "VOX_TouchSound: no sentence named %s\n", pszin);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C6E0
// Name: void VOX_AddSentenceWavesToResList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_AddSentenceWavesToResList()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ebx
  int v5; // esi
  sentence_t *v6; // esi
  int v7; // esi
  char *v8; // ebx
  const char *v9; // eax
  bool v10; // zf
  int i; // esi
  int Inorder; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v13; // ebx
  const char *pName; // [esp-14h] [ebp-78h]
  CUtlRBTree<ccpair,int,bool (__cdecl*)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int> > ccpairs; // [esp+4h] [ebp-60h] BYREF
  CUtlDict<int,int> list; // [esp+28h] [ebp-3Ch] BYREF
  int v17; // [esp+4Ch] [ebp-18h]
  char *s1; // [esp+50h] [ebp-14h]
  int m_Size; // [esp+54h] [ebp-10h]
  int v20; // [esp+58h] [ebp-Ch]
  sentence_t *pSentence; // [esp+5Ch] [ebp-8h]
  BOOL spewsentences; // [esp+60h] [ebp-4h]

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-makereslists") != 0
    || (v1 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-spewsentences") != 0) )
  {
    v2 = _CommandLine();
    LOBYTE(spewsentences) = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(
                              a1: v2,
                              a2: "-spewsentences") != 0;
    v3 = 0;
    list.m_Elements.m_Tree.m_Root = -1;
    list.m_Elements.m_Tree.m_FirstFree = -1;
    list.m_Elements.m_Tree.m_LastAlloc.index = -1;
    ccpairs.m_Root = -1;
    ccpairs.m_FirstFree = -1;
    ccpairs.m_LastAlloc.index = -1;
    m_pMemory = nullptr;
    memset(&list.m_Elements.m_Tree.m_Elements, 0, sizeof(list.m_Elements.m_Tree.m_Elements));
    list.m_Elements.m_Tree.m_NumElements = 0;
    list.m_Elements.m_Tree.m_pElements = nullptr;
    list.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    ccpairs.m_LessFunc = CCPairLessFunc;
    memset(&ccpairs.m_Elements, 0, sizeof(ccpairs.m_Elements));
    ccpairs.m_NumElements = 0;
    ccpairs.m_pElements = nullptr;
    if ( g_Sentences.m_Size > 0 )
    {
      v5 = 0;
      v20 = 0;
      m_Size = g_Sentences.m_Size;
      do
      {
        v6 = (sentence_t *)((char *)g_Sentences.m_Memory.m_pMemory + v5);
        pName = v6->pName;
        pSentence = v6;
        if ( V_strnicmp(s1: pName, s2: "V_", n: 2) != 0 )
        {
          if ( spewsentences )
          {
            s1 = v6->pName;
            v7 = 0;
            v17 = g_Sentences.m_Size;
            if ( g_Sentences.m_Size > 0 )
            {
              while ( 1 )
              {
                v8 = g_Sentences.m_Memory.m_pMemory[v3].pName;
                if ( _V_stricmp(s1, s2: v8) == 0 )
                  break;
                ++v7;
                ++v3;
                if ( v7 >= v17 )
                  goto LABEL_13;
              }
              v9 = &v8[_V_strlen(str: v8) + 1];
              if ( v9 != nullptr )
                _Msg(a1: "%s : %s\n", pSentence->pName, v9);
LABEL_13:
              v3 = 0;
            }
          }
          VOX_TouchSound(pszin: pSentence->pName, filelist: &list, &ccpairs, spewsentences);
        }
        v5 = v20 + 12;
        v10 = m_Size-- == 1;
        v20 += 12;
      }
      while ( !v10 );
      m_pMemory = list.m_Elements.m_Tree.m_Elements.m_pMemory;
    }
    VOX_TouchSounds(&list, &ccpairs, spewsentences);
    for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &list.m_Elements.m_Tree);
          i != -1;
          i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                this: &list.m_Elements.m_Tree,
                i) )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory[i].m_Data.key);
    }
    CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &list.m_Elements.m_Tree);
    CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::RemoveAll(this: &ccpairs);
    if ( ccpairs.m_Elements.m_nGrowSize >= 0 && ccpairs.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ccpairs.m_Elements.m_pMemory);
    Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &list.m_Elements.m_Tree);
    if ( Inorder != -1 )
    {
      v13 = list.m_Elements.m_Tree.m_Elements.m_pMemory;
      do
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v13[Inorder].m_Data.key);
        Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                    this: &list.m_Elements.m_Tree,
                    i: Inorder);
      }
      while ( Inorder != -1 );
    }
    CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &list.m_Elements.m_Tree);
    CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &list.m_Elements.m_Tree);
    if ( list.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 && list.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C960
// Name: _VOX_ReadSentenceFile
// Source: json
//------------------------------------------------------------------------------
void __usercall VOX_ReadSentenceFile(int a1@<ebx>, const char *psentenceFileName)
{
  CMapReslistGenerator *v2; // eax
  void *v3; // esi
  int v4; // eax
  unsigned int v5; // ebx
  unsigned int Size; // eax
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // ebx
  const char *v9; // esi
  char v10; // al
  char *i; // edi
  sentence_t *v12; // eax
  char v13; // al
  characterset_t whitespace; // [esp+4h] [ebp-108h] BYREF
  unsigned __int8 *pFileData; // [esp+104h] [ebp-8h]
  const char *pName; // [esp+108h] [ebp-4h]

  if ( VOX_ListFileIsLoaded(psentenceFileName) != 0 )
  {
    v2 = MapReslistGenerator();
    if ( v2->m_bLoggingEnabled && !v2->m_bLogToEngineList )
      VOX_AddSentenceWavesToResList();
  }
  else
  {
    v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: psentenceFileName, a3: "rb", a4: 0);
    if ( v3 != nullptr )
    {
      v4 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: v3,
             a3: a1);
      v5 = v4;
      if ( v4 > 0 )
      {
        pFileData = (unsigned __int8 *)g_pFileSystem->AllocOptimalReadBuffer(
                                         this: g_pFileSystem,
                                         a2: v3,
                                         a3: v4 + 1,
                                         a4: 0);
        if ( pFileData != nullptr )
        {
          pName = (const char *)g_pFileSystem->IAppSystem::__vftable;
          Size = IFileSystem::GetOptimalReadSize(this: g_pFileSystem, hFile: v3, nLogicalSize: v5);
          v7 = pFileData;
          (*((void (__thiscall **)(IFileSystem *, unsigned __int8 *, unsigned int, unsigned int, void *))pName + 72))(
            a1: g_pFileSystem,
            a2: pFileData,
            a3: Size,
            a4: v5,
            a5: v3);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
          v8 = &pFileData[v5];
          *v8 = 0;
          v9 = (const char *)v7;
          CharacterSetBuild(pSetBuffer: &whitespace, pszSetString: "\n\r\t ");
          pName = nullptr;
          if ( v7 < v8 )
          {
            do
            {
              v10 = *v9;
              for ( i = nullptr; v9 < (const char *)v8; v10 = *++v9 )
              {
                if ( whitespace.set[v10] == 0 )
                  break;
              }
              if ( *v9 == 0 )
                break;
              if ( *v9 != 47 )
              {
                v12 = &g_Sentences.m_Memory.m_pMemory[CUtlVector<sentence_t,CUtlMemory<sentence_t,int>>::InsertBefore(
                                                        this: &g_Sentences,
                                                        elem: g_Sentences.m_Size)];
                v12->pName = (char *)v9;
                v12->length = 0.0;
                *((_BYTE *)v12 + 8) = 0;
                v12->caption.m_Id = -1;
                v13 = *v9;
                pName = v9;
                if ( v9 < (const char *)v8 )
                {
                  while ( v13 != 32 )
                  {
                    v13 = *++v9;
                    if ( v9 >= (const char *)v8 )
                      goto LABEL_23;
                  }
                  if ( v9 < (const char *)v8 )
                    *v9++ = 0;
                }
LABEL_23:
                i = (char *)v9;
              }
              if ( v9 < (const char *)v8 )
              {
                while ( *v9 != 10 && *v9 != 13 )
                {
                  if ( ++v9 >= (const char *)v8 )
                    goto LABEL_31;
                }
                if ( v9 < (const char *)v8 )
                  *v9++ = 0;
              }
LABEL_31:
              if ( i != nullptr && i < (char *)v8 )
              {
                VOX_GroupAdd(pSentenceName: pName);
                VOX_ParseLineCommands(pSentenceData: i, sentenceIndex: g_Sentences.m_Size - 1);
              }
            }
            while ( v9 < (const char *)v8 );
            v7 = pFileData;
          }
          VOX_CompactSentenceFile();
          g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: v7);
          VOX_GroupInitAllLRUs();
          VOX_AddSentenceWavesToResList();
          VOX_ListMarkFileLoaded(psentenceFileName);
        }
        else
        {
          DevMsg(a1: "VOX_ReadSentenceFile: %s couldn't allocate %i bytes for data\n", psentenceFileName, v5);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
        }
      }
      else
      {
        DevMsg(a1: "VOX_ReadSentenceFile: %s has invalid size %i\n", psentenceFileName, v4);
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
      }
    }
    else
    {
      DevMsg(a1: "Couldn't load %s\n", psentenceFileName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CBD0
// Name: _VOX_Init
// Source: json
//------------------------------------------------------------------------------
void __usercall VOX_Init(int a1@<ebx>)
{
  char *m_pMemory; // eax
  unsigned __int8 *v2; // eax
  IMemAlloc_vtbl *v3; // edx
  sentence_t *v4; // eax

  g_entnamelastsaved = 0;
  _V_memset(dest: g_entnames, fill: 0, count: 6656);
  _V_memset(dest: g_rgmapnames, fill: 0, count: 96);
  m_pMemory = g_SentenceFile.m_Memory.m_pMemory;
  g_cmapnames = 0;
  g_SentenceFile.m_Size = 0;
  if ( g_SentenceFile.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SentenceFile.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SentenceFile.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_SentenceFile.m_Memory.m_pMemory = nullptr;
    }
    g_SentenceFile.m_Memory.m_nAllocationCount = 0;
  }
  g_SentenceFile.m_pElements = m_pMemory;
  v2 = g_GroupLRU.m_Memory.m_pMemory;
  g_GroupLRU.m_Size = 0;
  if ( g_GroupLRU.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_GroupLRU.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_GroupLRU.m_Memory.m_pMemory);
      v2 = nullptr;
      g_GroupLRU.m_Memory.m_pMemory = nullptr;
    }
    g_GroupLRU.m_Memory.m_nAllocationCount = 0;
  }
  g_GroupLRU.m_pElements = v2;
  g_Sentences.m_Size = 0;
  if ( g_Sentences.m_Memory.m_nAllocationCount < 900 && g_Sentences.m_Memory.m_nGrowSize >= 0 )
  {
    g_Sentences.m_Memory.m_nAllocationCount = 900;
    v3 = _g_pMemAlloc->__vftable;
    if ( g_Sentences.m_Memory.m_pMemory != nullptr )
      v4 = (sentence_t *)((int (__stdcall *)(sentence_t *, int))v3->Realloc_2)(
                           a1: g_Sentences.m_Memory.m_pMemory,
                           a2: 10800);
    else
      v4 = (sentence_t *)((int (__stdcall *)(int))v3->Alloc_2)(a1: 10800);
    g_Sentences.m_Memory.m_pMemory = v4;
  }
  g_Sentences.m_pElements = g_Sentences.m_Memory.m_pMemory;
  VOX_ListClear();
  VOX_ReadSentenceFile(a1, psentenceFileName: "scripts/sentences.txt");
  VOX_LookupMapnames();
}

//------------------------------------------------------------------------------
// Address: 0x1005CCE0
// Name: VOX_Reload
// Source: json
//------------------------------------------------------------------------------
void __usercall VOX_Reload(int a1@<ebx>)
{
  g_Sentences.m_Size = 0;
  VOX_ListClear();
  g_SentenceGroups.m_Size = 0;
  g_cmapnames = 0;
  VOX_Init(a1);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1001A000
// Name: public: int CUtlMap<char const __near *,int,int>::Insert(char const __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,int,int>::Insert(CUtlMap<char const *,int,int> *this, const char **key, int insert)
{
  int v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,int,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(_DWORD *)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001A840
// Name: public: int CUtlDict<int,int>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,int>::Insert(CUtlDict<int,int> *this, char *pName, const int *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,int,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x10057AB0
// Name: public: void WordBuf::Set(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WordBuf::Set(WordBuf *this, const char *w)
{
  if ( w != nullptr )
  {
    V_strncpy(pDest: this->word, pSrc: w, maxLen: 256);
    for ( ; _V_strlen(str: this->word) >= 1; this->word[_V_strlen(str: this->word) - 1] = 0 )
    {
      if ( this->word[_V_strlen(str: this->word) - 1] != 32 )
        break;
    }
  }
  else
  {
    this->word[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057B10
// Name: char __near * __near * VOX_ParseString(char __near *)
// Source: json
//------------------------------------------------------------------------------
char **__cdecl VOX_ParseString(char *psz)
{
  char *v1; // esi
  char **i; // edx
  char j; // al
  char m; // al
  char v6; // cl
  char k; // al
  char v8; // al
  characterset_t skip; // [esp+4h] [ebp-200h] BYREF
  characterset_t nextWord; // [esp+104h] [ebp-100h] BYREF

  v1 = psz;
  memset(dst: (unsigned __int8 *)rgpparseword, value: 0, count: sizeof(rgpparseword));
  if ( psz == nullptr )
    return nullptr;
  rgpparseword[0] = psz;
  CharacterSetBuild(pSetBuffer: &nextWord, pszSetString: " ,.({");
  CharacterSetBuild(pSetBuffer: &skip, pszSetString: "., ");
  for ( i = &rgpparseword[1]; (int)i < (int)&g_cmapnames; ++i )
  {
    for ( j = *v1; j != 0; j = *++v1 )
    {
      if ( nextWord.set[j] != 0 )
        break;
    }
    if ( j == 40 )
    {
      for ( k = *v1; k != 0; k = *++v1 )
      {
        if ( k == 41 )
          break;
      }
    }
    else
    {
      if ( j != 123 )
        goto LABEL_14;
      for ( m = *v1; m != 0; m = *++v1 )
      {
        if ( m == 125 )
          break;
      }
    }
    j = *++v1;
    if ( j == 0 )
      return rgpparseword;
LABEL_14:
    if ( j == 0 )
      return rgpparseword;
    if ( j == 46 || j == 44 )
    {
      v6 = v1[1];
      if ( v6 != 10 && v6 != 13 && v6 != 0 )
      {
        *i++ = j == 46 ? voxperiod : voxcomma;
        if ( (int)i >= (int)&g_cmapnames )
          return rgpparseword;
      }
    }
    *v1 = 0;
    v8 = *++v1;
    if ( v8 == 0 )
      return rgpparseword;
    while ( skip.set[v8] != 0 )
    {
      v8 = *++v1;
      if ( v8 == 0 )
        return rgpparseword;
    }
    *i = v1;
  }
  return rgpparseword;
}

//------------------------------------------------------------------------------
// Address: 0x10057C40
// Name: float VOX_GetChanVol(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl VOX_GetChanVol(channel_t *ch)
{
  if ( ch->pMixer != nullptr )
    return ch->pMixer->GetVolumeScale(this: ch->pMixer);
  else
    return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10057C60
// Name: int VOX_ParseWordParams(char __near *,struct voxword_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_ParseWordParams(char *psz, voxword_t *pvoxword, int fFirst)
{
  char *v3; // ebx
  char i; // al
  char v5; // dl
  char *v6; // ebx
  char v7; // al
  char v8; // al
  int v9; // edi
  unsigned int v10; // esi
  char v11; // al
  int v12; // eax
  characterset_t commandSet; // [esp+Ch] [ebp-20Ch] BYREF
  characterset_t delimitSet; // [esp+10Ch] [ebp-10Ch] BYREF
  char *pszsave; // [esp+20Ch] [ebp-Ch]
  char sznum[8]; // [esp+210h] [ebp-8h] BYREF
  char ct_3; // [esp+223h] [ebp+Bh]
  char c_3; // [esp+22Bh] [ebp+13h]

  v3 = psz;
  pszsave = psz;
  CharacterSetBuild(pSetBuffer: &commandSet, pszSetString: "vpset)");
  if ( fFirst != 0 )
  {
    voxwordDefault.pitch = -1;
    voxwordDefault.volume = 100;
    voxwordDefault.start = 0;
    voxwordDefault.end = 100;
    voxwordDefault.fKeepCached = 0;
    voxwordDefault.timecompress = 0;
  }
  *pvoxword = voxwordDefault;
  if ( psz[strlen(psz) - 1] == 41 )
  {
    CharacterSetBuild(pSetBuffer: &delimitSet, pszSetString: "()");
    for ( i = *psz; delimitSet.set[i] == 0; ++v3 )
      i = v3[1];
    if ( i == 41 )
      return 0;
    *v3 = 0;
    v5 = v3[1];
    v6 = v3 + 1;
    ct_3 = v5;
    while ( 1 )
    {
      if ( ct_3 != 0 )
      {
        do
        {
          if ( commandSet.set[ct_3] != 0 )
            break;
          v7 = *++v6;
          ct_3 = v7;
        }
        while ( v7 != 0 );
      }
      if ( ct_3 == 41 )
        break;
      memset(sznum, 0, sizeof(sznum));
      v8 = *++v6;
      v9 = v8;
      v10 = 0;
      c_3 = v8;
      if ( isdigit(c: v8) == 0 )
        break;
      if ( isdigit(c: v9) != 0 )
      {
        do
        {
          if ( v10 >= 7 )
            break;
          v11 = *++v6;
          sznum[v10++] = c_3;
          c_3 = v11;
        }
        while ( isdigit(c: v11) != 0 );
      }
      v12 = atoi(nptr: sznum);
      switch ( ct_3 )
      {
        case 'e':
          pvoxword->end = v12;
          ct_3 = c_3;
          break;
        case 'p':
          pvoxword->pitch = v12;
          ct_3 = c_3;
          break;
        case 's':
          pvoxword->start = v12;
          ct_3 = c_3;
          break;
        case 't':
          pvoxword->timecompress = v12;
          goto LABEL_22;
        case 'v':
          pvoxword->volume = v12;
          ct_3 = c_3;
          break;
        default:
LABEL_22:
          ct_3 = c_3;
          break;
      }
    }
    if ( strlen(pszsave) == 0 )
    {
      voxwordDefault = *pvoxword;
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10057EA0
// Name: int VOX_LookupEntIndex(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_LookupEntIndex(int type, int soundsource, bool fallocnew)
{
  int result; // eax
  int *v4; // ecx
  unsigned int v5; // ecx
  int v6; // ecx

  result = 0;
  v4 = dword_104DC2C4;
  do
  {
    if ( *(v4 - 1) == type && *v4 == soundsource )
    {
      byte_104DC2F0[104 * result] = 0;
      return result;
    }
    v4 += 26;
    ++result;
  }
  while ( (int)v4 < (int)&g_rgmapnames[1] );
  if ( !fallocnew )
    return -1;
  result = g_entnamelastsaved + 1;
  g_entnamelastsaved = result;
  if ( result >= 64 )
  {
    result = 0;
    g_entnamelastsaved = 0;
  }
  v5 = 26 * result;
  g_entnames[v5 / 0x1A].type = type;
  dword_104DC2C4[v5] = soundsource;
  dword_104DC324[v5] = 0;
  byte_104DC2F0[v5 * 4] = 0;
  dword_104DC2C8[v5] = 0;
  dword_104DC2CC[v5] = 0;
  v6 = 26 * result;
  dword_104DC2D0[v6] = 0;
  dword_104DC304[v6] = 0;
  dword_104DC2F4[v6] = 0;
  dword_104DC314[v6] = 0;
  dword_104DC2E0[v6] = 0;
  dword_104DC2D4[v6] = 0;
  dword_104DC308[v6] = 0;
  dword_104DC2F8[v6] = 0;
  dword_104DC318[v6] = 0;
  dword_104DC2E4[v6] = 0;
  dword_104DC2D8[v6] = 0;
  dword_104DC30C[v6] = 0;
  dword_104DC2FC[v6] = 0;
  dword_104DC31C[v6] = 0;
  dword_104DC2E8[v6] = 0;
  dword_104DC2DC[v6] = 0;
  dword_104DC310[v6] = 0;
  dword_104DC300[v6] = 0;
  dword_104DC320[v6] = 0;
  dword_104DC2EC[v6] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057FC0
// Name: int VOX_LookupLastDeadIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_LookupLastDeadIndex(int type)
{
  float v1; // xmm0_4
  int result; // eax
  int v3; // edx
  int *v4; // ecx

  v1 = -1.0;
  result = -1;
  v3 = 2;
  v4 = dword_104DC324;
  do
  {
    if ( *(v4 - 25) == type && *((_BYTE *)v4 - 52) != 0 && *(float *)v4 >= v1 )
    {
      v1 = *(float *)v4;
      result = v3 - 2;
    }
    if ( v4[1] == type && *((_BYTE *)v4 + 52) != 0 && *((float *)v4 + 26) >= v1 )
    {
      v1 = *((float *)v4 + 26);
      result = v3 - 1;
    }
    if ( v4[27] == type && *((_BYTE *)v4 + 156) != 0 && *((float *)v4 + 52) >= v1 )
    {
      v1 = *((float *)v4 + 52);
      result = v3;
    }
    if ( v4[53] == type && *((_BYTE *)v4 + 260) != 0 && *((float *)v4 + 78) >= v1 )
    {
      v1 = *((float *)v4 + 78);
      result = v3 + 1;
    }
    v3 += 4;
    v4 += 104;
  }
  while ( v3 - 2 < 64 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058080
// Name: void VOX_InsertWords(int,int,char __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_InsertWords(int ireplace, int cnew, char *pszNew, char *pszNew1, char *pszNew2)
{
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  char **v8; // ecx

  if ( cnew != 0 )
  {
    v5 = cnew - 1;
    if ( cnew != 1 )
    {
      v6 = 31;
      v7 = v5 + ireplace;
      if ( v5 + ireplace < 31 )
      {
        v8 = &rgpparseword[-v5 + 31];
        do
          rgpparseword[v6--] = *v8--;
        while ( v6 > v7 );
      }
    }
    rgpparseword[ireplace] = pszNew;
    if ( cnew == 2 || cnew == 3 )
    {
      rgpparseword[ireplace + 1] = pszNew1;
      if ( cnew == 3 )
        rgpparseword[ireplace + 2] = pszNew2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058100
// Name: void VOX_DeleteWord(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_DeleteWord(int iword)
{
  char **v1; // edi

  if ( (unsigned int)iword <= 0x1F )
  {
    v1 = &rgpparseword[iword];
    *v1 = nullptr;
    if ( iword < 31 )
      qmemcpy(v1, &rgpparseword[iword + 1], 4 * (31 - iword));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058130
// Name: CCPairLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CCPairLessFunc(const ccpair *lhs, const ccpair *rhs)
{
  return _V_stricmp(s1: lhs->token.word, s2: rhs->token.word) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10058150
// Name: VOX_ListClear
// Source: json
//------------------------------------------------------------------------------
filelist_t *VOX_ListClear()
{
  filelist_t *result; // eax
  filelist_t *pNext; // esi

  result = g_pSentenceFileList;
  if ( g_pSentenceFileList != nullptr )
  {
    do
    {
      pNext = result->pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result);
      result = pNext;
    }
    while ( pNext != nullptr );
  }
  g_pSentenceFileList = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058190
// Name: VOX_ListFileIsLoaded
// Source: json
//------------------------------------------------------------------------------
int __usercall VOX_ListFileIsLoaded@<eax>(const char *psentenceFileName@<edi>)
{
  filelist_t *v1; // esi

  v1 = g_pSentenceFileList;
  if ( g_pSentenceFileList == nullptr )
    return 0;
  while ( strcmp(psentenceFileName, v1->pFileName) != 0 )
  {
    v1 = v1->pNext;
    if ( v1 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10058270
// Name: VOX_ListMarkFileLoaded
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_ListMarkFileLoaded(const char *psentenceFileName)
{
  char *v1; // eax
  filelist_t *v2; // esi
  const char *v3; // edi
  filelist_t *v4; // ecx

  v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(psentenceFileName) + 9);
  v2 = (filelist_t *)v1;
  if ( v1 != nullptr )
  {
    v3 = v1 + 8;
    _V_strcpy(dest: v1 + 8, src: psentenceFileName);
    v4 = g_pSentenceFileList;
    v2->pFileName = v3;
    v2->pNext = v4;
    g_pSentenceFileList = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100582D0
// Name: _VOX_SentenceCount
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_SentenceCount()
{
  return g_Sentences.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100584A0
// Name: public: unsigned int IFileSystem::GetOptimalReadSize(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IFileSystem::GetOptimalReadSize(IFileSystem *this, void *hFile, unsigned int nLogicalSize)
{
  if ( this->GetOptimalIOConstraints(this, a2: hFile, a3: (unsigned int *)&hFile, a4: nullptr, a5: nullptr) )
    return ~((int)hFile - 1) & ((unsigned int)hFile + nLogicalSize - 1);
  else
    return nLogicalSize;
}

//------------------------------------------------------------------------------
// Address: 0x100584E0
// Name: void VOX_ParseLineCommands(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_ParseLineCommands(char *pSentenceData, int sentenceIndex)
{
  unsigned __int8 *v2; // esi
  char v3; // al
  const char *v4; // edi
  unsigned int v5; // ebx
  bool v6; // zf
  const char *v7; // esi
  char i; // al
  int v9; // eax
  char v10; // al
  sentence_t *v11; // edi
  char v12; // al
  int v13; // edi
  char j; // al
  char v15; // al
  char *v16; // [esp-10h] [ebp-21Ch]
  char tempBuffer[512]; // [esp+4h] [ebp-208h] BYREF
  char *pStart; // [esp+204h] [ebp-8h]
  int tempBufferPos; // [esp+208h] [ebp-4h]

  v2 = (unsigned __int8 *)pSentenceData;
  tempBufferPos = 0;
  if ( pSentenceData != nullptr )
  {
    v3 = *pSentenceData;
    pStart = pSentenceData;
    if ( v3 != 0 )
    {
LABEL_3:
      v4 = (const char *)v2;
      do
      {
        if ( v3 == 123 )
          break;
        v3 = *++v4;
      }
      while ( v3 != 0 );
      v5 = v4 - (const char *)v2 + tempBufferPos;
      if ( v5 > 0x200 )
      {
        DevMsg(a1: "Error! sentence too long!\n");
        return;
      }
      memcpy(dst: (unsigned __int8 *)&tempBuffer[tempBufferPos], src: v2, count: v4 - (const char *)v2);
      v6 = *v4 == 0;
      tempBufferPos = v5;
      v7 = v4;
      if ( !v6 )
        v7 = v4 + 1;
      while ( 1 )
      {
        for ( i = *v7; i != 0; i = *++v7 )
        {
          if ( i > 32 )
            break;
        }
        v9 = tolower(c: *v7);
        if ( v9 == 99 )
        {
          if ( V_strnicmp(s1: v7, s2: "closecaption", n: 12) == 0 )
          {
            v13 = sentenceIndex;
            *((_BYTE *)&g_Sentences.m_Memory.m_pMemory[sentenceIndex] + 8) = *((_BYTE *)&g_Sentences.m_Memory.m_pMemory[sentenceIndex]
                                                                             + 8)
                                                                           & 0x80
                                                                           | 1;
            v7 = COM_Parse(data: v7 + 12);
            for ( j = *v7; j != 0; j = *++v7 )
            {
              if ( j == 125 )
                break;
              if ( j <= 32 )
                break;
            }
            if ( _V_strlen(str: com_token) <= 0 )
            {
              g_Sentences.m_Memory.m_pMemory[v13].caption.m_Id = -1;
            }
            else
            {
              CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pSentenceData + 1, pStr: com_token);
              g_Sentences.m_Memory.m_pMemory[v13].caption.m_Id = HIWORD(pSentenceData);
            }
          }
        }
        else if ( v9 == 108 )
        {
          if ( V_strnicmp(s1: v7, s2: "len", n: 3) == 0 )
          {
            v11 = &g_Sentences.m_Memory.m_pMemory[sentenceIndex];
            v11->length = atof(nptr: v7 + 3);
            v12 = v7[4];
            v7 += 4;
            if ( v12 == 0 )
              break;
            while ( v12 != 125 && v12 > 32 )
            {
              v12 = *++v7;
              if ( v12 == 0 )
                goto LABEL_18;
            }
          }
        }
        else
        {
          v10 = *v7;
          if ( *v7 == 0 )
            break;
          while ( v10 != 125 && v10 > 32 )
          {
            v10 = *++v7;
            if ( v10 == 0 )
              goto LABEL_18;
          }
        }
        if ( *v7 == 0 )
          break;
        if ( *v7 == 125 )
        {
          v15 = v7[1];
          v2 = (unsigned __int8 *)(v7 + 1);
          if ( v15 != 0 )
          {
            while ( v15 <= 32 )
            {
              v15 = *++v2;
              if ( v15 == 0 )
                goto LABEL_18;
            }
            v3 = *v2;
            if ( *v2 != 0 )
              goto LABEL_3;
          }
          break;
        }
      }
LABEL_18:
      if ( (unsigned int)tempBufferPos >= 0x200 )
        return;
    }
    v16 = pStart;
    tempBuffer[tempBufferPos] = 0;
    _V_strcpy(dest: v16, src: tempBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058730
// Name: void VOX_LRUInit(struct sentencegroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl VOX_LRUInit(int pGroup)
{
  int v2; // ecx
  unsigned __int8 *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  IUniformRandomStream *v7; // ecx
  int v8; // eax
  unsigned __int8 v9; // cl
  int i; // [esp+Ch] [ebp+8h]

  v2 = *(unsigned __int16 *)pGroup;
  if ( (_WORD)v2 != 0 )
  {
    v3 = &g_GroupLRU.m_Memory.m_pMemory[*(__int16 *)(pGroup + 2)];
    v4 = 0;
    if ( (__int16)v2 > 0 )
    {
      do
      {
        v3[v4] = v4;
        v2 = *(__int16 *)pGroup;
        ++v4;
      }
      while ( v4 < v2 );
    }
    v5 = *(__int16 *)pGroup;
    i = 0;
    if ( 4 * v5 > 0 )
    {
      do
      {
        v6 = _RandomInt(this: (IUniformRandomStream *)v2, a2: 0, a3: v5 - 1);
        v8 = _RandomInt(this: v7, a2: 0, a3: *(__int16 *)pGroup - 1);
        v9 = v3[v6];
        v3[v6] = v3[v8];
        v3[v8] = v9;
        v5 = *(__int16 *)pGroup;
        v2 = i + 1;
        i = v2;
      }
      while ( v2 < 4 * v5 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100587C0
// Name: _VOX_GroupIndexFromName
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_GroupIndexFromName(const char *pGroupName)
{
  int result; // eax
  CUtlSymbol *i; // ecx

  if ( pGroupName == nullptr )
    return -1;
  CUtlSymbolTable::AddString(
    this: &sentencegroup_t::s_SymbolTable,
    result: (CUtlSymbol *)&pGroupName,
    pString: pGroupName);
  result = 0;
  if ( g_SentenceGroups.m_Size <= 0 )
    return -1;
  for ( i = &g_SentenceGroups.m_Memory.m_pMemory->groupname; (_WORD)pGroupName != i->m_Id; i += 3 )
  {
    if ( ++result >= g_SentenceGroups.m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058810
// Name: _VOX_GroupNameFromIndex
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl VOX_GroupNameFromIndex(int groupIndex)
{
  if ( groupIndex < 0 || groupIndex >= g_SentenceGroups.m_Size )
    return nullptr;
  else
    return CUtlSymbolTable::String(
             this: &sentencegroup_t::s_SymbolTable,
             id: g_SentenceGroups.m_Memory.m_pMemory[groupIndex].groupname);
}

//------------------------------------------------------------------------------
// Address: 0x10058850
// Name: _VOX_GroupPickSequential
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_GroupPickSequential(int isentenceg, char *szfound, int szfoundLen, int ipick, int freset)
{
  const char *v5; // eax
  unsigned __int8 count; // cl
  int v7; // esi
  int v8; // edi

  if ( isentenceg < 0 )
    return -1;
  if ( isentenceg > g_SentenceGroups.m_Size )
    return -1;
  v5 = CUtlSymbolTable::String(
         this: &sentencegroup_t::s_SymbolTable,
         id: g_SentenceGroups.m_Memory.m_pMemory[isentenceg].groupname);
  count = g_SentenceGroups.m_Memory.m_pMemory[isentenceg].count;
  if ( count == 0 )
    return -1;
  v7 = ipick;
  v8 = count;
  if ( ipick >= count )
    v7 = count - 1;
  V_snprintf(pDest: szfound, maxLen: szfoundLen, pFormat: "!%s%d", v5, v7);
  if ( v7 < v8 )
    return v7 + 1;
  else
    return freset == 0 ? v8 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x100588E0
// Name: _VOX_GroupPick
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_GroupPick(int isentenceg, char *szfound, int strLen)
{
  int v3; // esi
  const char *v4; // eax
  sentencegroup_t *m_pMemory; // ecx
  unsigned __int8 count; // bl
  unsigned __int8 *v7; // edi
  unsigned __int8 v8; // al
  int v9; // esi
  const char *isentencega; // [esp+14h] [ebp+8h]

  if ( isentenceg < 0 || isentenceg > g_SentenceGroups.m_Size )
    return -1;
  v3 = isentenceg;
  v4 = CUtlSymbolTable::String(
         this: &sentencegroup_t::s_SymbolTable,
         id: g_SentenceGroups.m_Memory.m_pMemory[isentenceg].groupname);
  m_pMemory = g_SentenceGroups.m_Memory.m_pMemory;
  count = g_SentenceGroups.m_Memory.m_pMemory[isentenceg].count;
  v7 = &g_GroupLRU.m_Memory.m_pMemory[g_SentenceGroups.m_Memory.m_pMemory[isentenceg].lru];
  isentencega = v4;
  while ( 1 )
  {
    v8 = 0;
    if ( count != 0 )
      break;
LABEL_7:
    VOX_LRUInit(pGroup: (int)&m_pMemory[v3]);
    m_pMemory = g_SentenceGroups.m_Memory.m_pMemory;
  }
  while ( v7[v8] == 0xFF )
  {
    if ( ++v8 >= count )
      goto LABEL_7;
  }
  v9 = v7[v8];
  v7[v8] = -1;
  V_snprintf(pDest: szfound, maxLen: strLen, pFormat: "!%s%d", isentencega, v9);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100589D0
// Name: _VOX_LookupString
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupString(
        const char *pSentenceName,
        int *psentencenum,
        bool *pbEmitCaption,
        CUtlSymbol *pCaptionSymbol,
        float *pflDuration)
{
  int m_Size; // ebx
  int v6; // esi
  int i; // edi
  char *name; // [esp+0h] [ebp-4h]

  if ( pbEmitCaption != nullptr )
    *pbEmitCaption = false;
  if ( pCaptionSymbol != nullptr )
    pCaptionSymbol->m_Id = -1;
  if ( pflDuration != nullptr )
    *pflDuration = 0.0;
  m_Size = g_Sentences.m_Size;
  v6 = 0;
  if ( g_Sentences.m_Size <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    name = g_Sentences.m_Memory.m_pMemory[i].pName;
    if ( _V_stricmp(s1: pSentenceName, s2: name) == 0 )
      break;
    if ( ++v6 >= m_Size )
      return nullptr;
  }
  if ( psentencenum != nullptr )
    *psentencenum = v6;
  if ( pbEmitCaption != nullptr )
    *pbEmitCaption = *((_BYTE *)&g_Sentences.m_Memory.m_pMemory[v6] + 8) & 0x7F;
  if ( pCaptionSymbol != nullptr )
    pCaptionSymbol->m_Id = (unsigned __int16)g_Sentences.m_Memory.m_pMemory[v6].caption;
  if ( pflDuration != nullptr )
    *pflDuration = g_Sentences.m_Memory.m_pMemory[v6].length;
  return &name[_V_strlen(str: name) + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10058AB0
// Name: _VOX_SentenceNameFromIndex
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_SentenceNameFromIndex(int sentencenum)
{
  if ( sentencenum >= g_Sentences.m_Size )
    return nullptr;
  else
    return g_Sentences.m_Memory.m_pMemory[sentencenum].pName;
}

//------------------------------------------------------------------------------
// Address: 0x10059230
// Name: _VOX_Shutdown
// Source: json
//------------------------------------------------------------------------------
filelist_t *VOX_Shutdown()
{
  filelist_t *result; // eax

  g_Sentences.m_Size = 0;
  result = VOX_ListClear();
  g_SentenceGroups.m_Size = 0;
  g_cmapnames = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059260
// Name: char __near * VOX_LookupRndVirtual(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupRndVirtual(char *pGroupName)
{
  int v1; // eax
  CUtlSymbol *i; // ecx
  int v4; // esi
  int j; // ebx
  char *pName; // edi
  const char *v7; // edi
  char *v8; // eax
  char szsentencename[32]; // [esp+4h] [ebp-24h] BYREF
  int m_Size; // [esp+24h] [ebp-4h]

  if ( pGroupName == nullptr )
    return nullptr;
  CUtlSymbolTable::AddString(
    this: &sentencegroup_t::s_SymbolTable,
    result: (CUtlSymbol *)&pGroupName,
    pString: pGroupName);
  v1 = 0;
  if ( g_SentenceGroups.m_Size <= 0 )
    return nullptr;
  for ( i = &g_SentenceGroups.m_Memory.m_pMemory->groupname; (_WORD)pGroupName != i->m_Id; i += 3 )
  {
    if ( ++v1 >= g_SentenceGroups.m_Size )
      return nullptr;
  }
  if ( v1 < 0 || VOX_GroupPick(isentenceg: v1, szfound: szsentencename, strLen: 31) < 0 )
    return nullptr;
  if ( szsentencename[0] == 33 )
    pGroupName = &szsentencename[1];
  else
    pGroupName = szsentencename;
  v4 = 0;
  m_Size = g_Sentences.m_Size;
  if ( g_Sentences.m_Size <= 0 )
    return nullptr;
  for ( j = 0; ; ++j )
  {
    pName = g_Sentences.m_Memory.m_pMemory[j].pName;
    if ( _V_stricmp(s1: pGroupName, s2: pName) == 0 )
      break;
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  v7 = &pName[_V_strlen(str: pName) + 1];
  if ( v7 == nullptr )
    return nullptr;
  v8 = _V_strstr(s1: v7, search: " ");
  if ( v8 != nullptr )
    *v8 = 0;
  return (char *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x10059360
// Name: char __near * VOX_LookupSentenceByIndex(char __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupSentenceByIndex(char *pGroupname, int ipick, int *pipicknext)
{
  int v3; // eax
  CUtlSymbol *i; // ecx
  int v6; // edi
  int v7; // esi
  const char *v8; // eax
  unsigned __int8 count; // cl
  int v10; // esi
  int v11; // esi
  int v12; // edi
  char *pName; // ebx
  const char *v14; // ebx
  char *v15; // eax
  char szsentencename[32]; // [esp+Ch] [ebp-28h] BYREF
  int m_Size; // [esp+2Ch] [ebp-8h]
  int isentence; // [esp+30h] [ebp-4h]

  if ( pGroupname == nullptr )
    return nullptr;
  CUtlSymbolTable::AddString(
    this: &sentencegroup_t::s_SymbolTable,
    result: (CUtlSymbol *)&pGroupname,
    pString: pGroupname);
  v3 = 0;
  if ( g_SentenceGroups.m_Size <= 0 )
    return nullptr;
  for ( i = &g_SentenceGroups.m_Memory.m_pMemory->groupname; (_WORD)pGroupname != i->m_Id; i += 3 )
  {
    if ( ++v3 >= g_SentenceGroups.m_Size )
      return nullptr;
  }
  if ( v3 < 0 )
    return nullptr;
  v6 = ipick;
  if ( v3 > g_SentenceGroups.m_Size )
    return nullptr;
  v7 = v3;
  v8 = CUtlSymbolTable::String(
         this: &sentencegroup_t::s_SymbolTable,
         id: g_SentenceGroups.m_Memory.m_pMemory[v3].groupname);
  count = g_SentenceGroups.m_Memory.m_pMemory[v7].count;
  if ( count == 0 )
    return nullptr;
  v10 = count;
  if ( v6 >= count )
    v6 = count - 1;
  V_snprintf(pDest: szsentencename, maxLen: 31, pFormat: "!%s%d", v8, v6);
  if ( v6 < v10 )
  {
    isentence = v6 + 1;
    if ( v6 + 1 >= 0 )
      goto LABEL_16;
    return nullptr;
  }
  isentence = 0;
LABEL_16:
  if ( szsentencename[0] == 33 )
    pGroupname = &szsentencename[1];
  else
    pGroupname = szsentencename;
  v11 = 0;
  m_Size = g_Sentences.m_Size;
  if ( g_Sentences.m_Size <= 0 )
  {
LABEL_23:
    v14 = nullptr;
  }
  else
  {
    v12 = 0;
    while ( 1 )
    {
      pName = g_Sentences.m_Memory.m_pMemory[v12].pName;
      if ( _V_stricmp(s1: pGroupname, s2: pName) == 0 )
        break;
      ++v11;
      ++v12;
      if ( v11 >= m_Size )
        goto LABEL_23;
    }
    v14 = &pName[_V_strlen(str: pName) + 1];
  }
  v15 = _V_strstr(s1: v14, search: " ");
  if ( v15 != nullptr )
    *v15 = 0;
  if ( pipicknext != nullptr )
    *pipicknext = isentence;
  return (char *)v14;
}

//------------------------------------------------------------------------------
// Address: 0x100594B0
// Name: char __near * VOX_LookupNumber(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupNumber(char *pGroupName, int ipick)
{
  int v2; // ebx
  int v3; // esi
  char sznumbers[16]; // [esp+Ch] [ebp-10h] BYREF

  v2 = _V_strlen(str: pGroupName);
  v3 = _V_strlen(str: "V_NUMBERS");
  _V_strcpy(dest: sznumbers, src: "V_NUMBERS");
  sznumbers[v3] = pGroupName[v2 - 1];
  sznumbers[v3 + 1] = 0;
  return VOX_LookupSentenceByIndex(pGroupname: sznumbers, ipick, pipicknext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10059920
// Name: char __near * VOX_LookupSectorVirtual(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupSectorVirtual(char *pGroupname)
{
  IUniformRandomStream *v1; // ecx
  int v2; // eax
  int m_nValue; // ecx
  int v5; // edi
  int v6; // esi
  char dest[16]; // [esp+0h] [ebp-14h] BYREF
  float curtime; // [esp+10h] [ebp-4h]
  char *pGroupnamea; // [esp+1Ch] [ebp+8h]

  curtime = g_pSoundServices->GetClientTime(this: g_pSoundServices);
  v2 = g_vox_isector;
  if ( g_vox_isector == -1 )
  {
    v2 = _RandomInt(this: v1, a2: 0, a3: 19);
    g_vox_isector = v2;
  }
  if ( snd_vox_sectimeout.m_pParent != nullptr )
    m_nValue = snd_vox_sectimeout.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( (float)(curtime - g_vox_lastsectorupdate) > (float)m_nValue )
  {
    g_vox_isector = ++v2;
    if ( v2 > 20 )
    {
      v2 = 1;
      g_vox_isector = 1;
    }
    g_vox_lastsectorupdate = curtime;
  }
  v5 = v2;
  pGroupnamea = (char *)_V_strlen(str: pGroupname);
  v6 = _V_strlen(str: "V_NUMBERS");
  _V_strcpy(dest, src: "V_NUMBERS");
  dest[v6] = pGroupname[(_DWORD)pGroupnamea - 1];
  dest[v6 + 1] = 0;
  return VOX_LookupSentenceByIndex(pGroupname: dest, ipick: v5, pipicknext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100599F0
// Name: char __near * VOX_LookupGlobalVirtual(int,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupGlobalVirtual(int type, int soundsource, char *pGroupName, int iglobal)
{
  int v4; // ecx
  _vox_entname *v5; // eax
  float *v6; // esi
  int v7; // edx
  char *result; // eax
  char *v9; // esi
  int v10; // eax
  float curtime; // [esp+Ch] [ebp-4h]

  curtime = g_pSoundServices->GetClientTime(this: g_pSoundServices);
  v4 = 0;
  v5 = g_entnames;
  v6 = (float *)&dword_104DC304[iglobal];
  while ( 1 )
  {
    if ( v5->type == type )
    {
      v7 = snd_vox_globaltimeout.m_pParent != nullptr ? snd_vox_globaltimeout.m_pParent->m_Value.m_nValue : 0;
      if ( (float)v7 >= (float)(curtime - *v6) )
        break;
    }
    ++v5;
    ++v4;
    v6 += 26;
    if ( (int)v5 >= (int)g_rgmapnames )
      goto LABEL_10;
  }
  result = (char *)dword_104DC2D0[26 * v4 + iglobal];
  if ( result != nullptr )
    return result;
LABEL_10:
  v9 = VOX_LookupRndVirtual(pGroupName);
  v10 = iglobal + 26 * VOX_LookupEntIndex(type, soundsource, fallocnew: true);
  *(float *)&dword_104DC304[v10] = curtime;
  dword_104DC2D0[v10] = (int)v9;
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10059AB0
// Name: char __near * VOX_LookupGlobalSeqVirtual(int,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VOX_LookupGlobalSeqVirtual(int type, int soundsource, char *pGroupName, int iglobal)
{
  int v4; // esi
  _vox_entname *v5; // eax
  int v6; // eax
  int v7; // esi
  char *result; // eax
  int m_nValue; // eax
  float v10; // xmm1_4
  int v11; // [esp-8h] [ebp-10h]
  float curtime; // [esp+4h] [ebp-4h]

  curtime = g_pSoundServices->GetClientTime(this: g_pSoundServices);
  v4 = 0;
  v5 = g_entnames;
  while ( v5->type != type )
  {
    ++v5;
    ++v4;
    if ( (int)v5 >= (int)g_rgmapnames )
    {
      v6 = VOX_LookupEntIndex(type, soundsource, fallocnew: true);
      goto Pick_next;
    }
  }
  if ( snd_vox_seqtimeout.m_pParent != nullptr )
    m_nValue = snd_vox_seqtimeout.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v10 = (float)(m_nValue / 2);
  v6 = v4;
  if ( v10 < (float)(curtime - *(float *)&dword_104DC314[26 * v4 + iglobal]) )
    dword_104DC2F4[26 * v4 + iglobal] = 0;
Pick_next:
  v7 = iglobal + 26 * v6;
  v11 = dword_104DC2F4[v7];
  iglobal = 0;
  result = VOX_LookupSentenceByIndex(pGroupname: pGroupName, ipick: v11, pipicknext: &iglobal);
  dword_104DC2F4[v7] = iglobal;
  *(float *)&dword_104DC314[v7] = curtime;
  dword_104DC2E0[v7] = (int)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059B90
// Name: void VOX_LookupMapnames(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_LookupMapnames()
{
  int v0; // eax
  CUtlSymbol *j; // ecx
  int v2; // ebx
  int v3; // esi
  const char *v4; // eax
  unsigned __int8 count; // cl
  int v6; // esi
  int v7; // esi
  int v8; // edi
  char *pName; // ebx
  const char *v10; // ebx
  char *v11; // eax
  int v12; // eax
  char pDest; // [esp+Ch] [ebp-30h] BYREF
  char v14; // [esp+Dh] [ebp-2Fh] BYREF
  int m_Size; // [esp+2Ch] [ebp-10h]
  char *s1; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  CUtlSymbol result; // [esp+38h] [ebp-4h] BYREF

  i = 0;
  do
  {
    CUtlSymbolTable::AddString(this: &sentencegroup_t::s_SymbolTable, &result, pString: "V_MAPNAME");
    v0 = 0;
    if ( g_SentenceGroups.m_Size <= 0 )
      break;
    for ( j = &g_SentenceGroups.m_Memory.m_pMemory->groupname; result.m_Id != j->m_Id; j += 3 )
    {
      if ( ++v0 >= g_SentenceGroups.m_Size )
        return;
    }
    if ( v0 < 0 )
      break;
    v2 = i;
    if ( v0 > g_SentenceGroups.m_Size )
      break;
    v3 = v0;
    v4 = CUtlSymbolTable::String(
           this: &sentencegroup_t::s_SymbolTable,
           id: g_SentenceGroups.m_Memory.m_pMemory[v0].groupname);
    count = g_SentenceGroups.m_Memory.m_pMemory[v3].count;
    if ( count == 0 )
      break;
    v6 = count;
    if ( v2 >= count )
      v2 = count - 1;
    V_snprintf(&pDest, maxLen: 31, pFormat: "!%s%d", v4, v2);
    if ( v2 < v6 && v2 + 1 < 0 )
      break;
    s1 = pDest == 33 ? &v14 : &pDest;
    v7 = 0;
    m_Size = g_Sentences.m_Size;
    if ( g_Sentences.m_Size <= 0 )
    {
LABEL_21:
      v10 = nullptr;
    }
    else
    {
      v8 = 0;
      while ( 1 )
      {
        pName = g_Sentences.m_Memory.m_pMemory[v8].pName;
        if ( _V_stricmp(s1, s2: pName) == 0 )
          break;
        ++v7;
        ++v8;
        if ( v7 >= m_Size )
          goto LABEL_21;
      }
      v10 = &pName[_V_strlen(str: pName) + 1];
    }
    v11 = _V_strstr(s1: v10, search: " ");
    if ( v11 != nullptr )
      *v11 = 0;
    if ( v10 == nullptr )
      break;
    v12 = i;
    ++g_cmapnames;
    g_rgmapnames[i] = (char *)v10;
    i = v12 + 1;
  }
  while ( v12 + 1 < 24 );
}

//------------------------------------------------------------------------------
// Address: 0x10059CF0
// Name: void VOX_ReplaceVirtualNames(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_ReplaceVirtualNames(channel_t *pchan)
{
  char *v1; // ebx
  int v2; // esi
  int v3; // eax
  char *v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // eax
  int *v9; // ecx
  char *v10; // eax
  _DWORD *v11; // edi
  int v12; // edi
  ISoundServices *v13; // ecx
  int v14; // edi
  double v15; // st7
  int v16; // eax
  int DeadIndex; // eax
  int v18; // eax
  char *v19; // eax
  char *v20; // eax
  const char *v21; // [esp-Ch] [ebp-17Ch]
  const char *v22; // [esp-8h] [ebp-178h]
  char szgroup1[32]; // [esp+8h] [ebp-168h] BYREF
  char szgroup2[32]; // [esp+28h] [ebp-148h] BYREF
  char szparseword[256]; // [esp+48h] [ebp-128h] BYREF
  unsigned int v26; // [esp+148h] [ebp-28h]
  const char *pszmap; // [esp+14Ch] [ebp-24h]
  char *pszNew2; // [esp+150h] [ebp-20h] BYREF
  char **v29; // [esp+154h] [ebp-1Ch]
  int i; // [esp+158h] [ebp-18h]
  char *pszNew1; // [esp+15Ch] [ebp-14h] BYREF
  int soundsource; // [esp+160h] [ebp-10h]
  char *pszNew; // [esp+164h] [ebp-Ch] BYREF
  int cnew; // [esp+168h] [ebp-8h] BYREF
  char chtype; // [esp+16Fh] [ebp-1h]

  v1 = nullptr;
  i = 0;
  if ( pchan != nullptr )
  {
    v2 = pchan->soundsource;
    soundsource = v2;
  }
  else
  {
    soundsource = 0;
    v2 = 0;
  }
  if ( (host_map.m_nFlags & 0x1000) != 0 )
  {
    pszmap = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    pszmap = host_map.m_pParent->m_Value.m_pszString;
    if ( pszmap == nullptr )
      pszmap = defaultValue;
  }
  if ( rgpparseword[0] != nullptr )
  {
    v26 = 0;
    v29 = rgpparseword;
    do
    {
      if ( **v29 != 86 || (*v29)[1] != 95 )
        goto LABEL_76;
      v22 = *v29;
      cnew = 0;
      pszNew = nullptr;
      pszNew1 = nullptr;
      pszNew2 = nullptr;
      v3 = _V_strlen(str: v22);
      v21 = *v29;
      chtype = (*v29)[v3 - 1];
      _V_strcpy(dest: szparseword, src: v21);
      v4 = _V_strstr(s1: szparseword, search: "_MAP__");
      if ( v4 != nullptr )
      {
        v5 = 0;
        if ( g_cmapnames <= 0 )
          goto LABEL_18;
        do
        {
          v6 = (int)_V_strstr(s1: pszmap, search: g_rgmapnames[v5]);
          if ( v6 != 0 )
            break;
          ++v5;
        }
        while ( v5 < g_cmapnames );
        v6 = v5;
        if ( v5 >= 0 )
        {
          if ( v5 > 99 )
            v6 = 99;
        }
        else
        {
LABEL_18:
          v6 = 0;
        }
        v4[4] = 48;
        if ( v6 >= 10 )
          V_snprintf(pDest: v4 + 4, maxLen: 2, pFormat: "%d", v6);
        else
          V_snprintf(pDest: v4 + 5, maxLen: 1, pFormat: "%1d", v6);
        v2 = soundsource;
      }
      if ( _V_strstr(s1: szparseword, search: "V_MYNAME") != nullptr )
      {
        v7 = 1;
LABEL_29:
        v8 = 26 * VOX_LookupEntIndex(type: chtype, soundsource: v2, fallocnew: true);
        v9 = &dword_104DC2C8[v8];
        if ( v7 != 1 )
          v9 = &dword_104DC2CC[v8];
        v10 = (char *)*v9;
        v11 = v9;
        if ( *v9 == 0 )
        {
          v10 = VOX_LookupRndVirtual(pGroupName: szparseword);
          *v11 = v10;
        }
        v1 = v10;
        goto LABEL_74;
      }
      if ( _V_strstr(s1: szparseword, search: "V_MYNUM") != nullptr )
      {
        v7 = 0;
        goto LABEL_29;
      }
      if ( _V_strstr(s1: szparseword, search: "V_RND") != nullptr )
      {
        v1 = VOX_LookupRndVirtual(pGroupName: szparseword);
LABEL_74:
        cnew = 1;
        goto LABEL_75;
      }
      if ( _V_strstr(s1: szparseword, search: "V_DIST") != nullptr )
      {
        VOX_LookupRangeHeadingOrGrid(
          irhg: 0,
          pGroupName: szparseword,
          pChannel: pchan,
          soundsource: v2,
          ppszNew: &pszNew,
          ppszNew1: &pszNew1,
          ppszNew2: &pszNew2,
          pcnew: &cnew,
          fsimple: true);
        v1 = pszNew;
      }
      else if ( _V_strstr(s1: szparseword, search: "V_DIR") != nullptr )
      {
        VOX_LookupRangeHeadingOrGrid(
          irhg: 1,
          pGroupName: szparseword,
          pChannel: pchan,
          soundsource: v2,
          ppszNew: &pszNew,
          ppszNew1: &pszNew1,
          ppszNew2: &pszNew2,
          pcnew: &cnew,
          fsimple: false);
        v1 = pszNew;
      }
      else
      {
        if ( _V_strstr(s1: szparseword, search: "V_IDIED") != nullptr )
        {
          v12 = VOX_LookupEntIndex(type: chtype, soundsource: v2, fallocnew: false);
          if ( v12 < 0 )
          {
            _V_strcpy(dest: szgroup1, src: "V_MYNAME");
            szgroup1[8] = chtype;
            szgroup1[9] = 0;
            _V_strcpy(dest: szgroup2, src: "V_MYNUM");
            szgroup2[7] = chtype;
            szgroup2[8] = 0;
            v12 = VOX_LookupEntIndex(type: chtype, soundsource: v2, fallocnew: true);
            dword_104DC2C8[26 * v12] = (int)VOX_LookupRndVirtual(pGroupName: szgroup1);
            dword_104DC2CC[26 * v12] = (int)VOX_LookupRndVirtual(pGroupName: szgroup2);
            v2 = soundsource;
          }
          v13 = g_pSoundServices;
          v14 = 26 * v12;
          byte_104DC2F0[v14 * 4] = 1;
          v15 = ((double (__thiscall *)(ISoundServices *))v13->GetClientTime)(a1: v13);
          v16 = i;
          *(float *)&dword_104DC324[v14] = v15;
          if ( (unsigned int)v16 <= 0x1F )
          {
            *v29 = nullptr;
            if ( v16 < 31 )
            {
              qmemcpy(v29, &rgpparseword[v26 / 4 + 1], 4 * (31 - v16));
              v2 = soundsource;
            }
          }
          goto LABEL_75;
        }
        if ( _V_strstr(s1: szparseword, search: "V_WHODIED") != nullptr )
        {
          DeadIndex = VOX_LookupLastDeadIndex(type: chtype);
          if ( DeadIndex < 0 )
          {
            VOX_DeleteWord(iword: i);
          }
          else
          {
            v18 = 26 * DeadIndex;
            v1 = (char *)dword_104DC2C8[v18];
            v19 = (char *)dword_104DC2CC[v18];
            cnew = 1;
            pszNew1 = v19;
            if ( v19 != nullptr )
              cnew = 2;
          }
          goto LABEL_75;
        }
        if ( _V_strstr(s1: szparseword, search: "V_SECTOR") != nullptr )
        {
          v20 = VOX_LookupSectorVirtual(pGroupname: szparseword);
        }
        else
        {
          if ( _V_strstr(s1: szparseword, search: "V_GRIDX") != nullptr )
          {
            VOX_LookupRangeHeadingOrGrid(
              irhg: 2,
              pGroupName: szparseword,
              pChannel: pchan,
              soundsource: v2,
              ppszNew: &pszNew,
              ppszNew1: &pszNew1,
              ppszNew2: &pszNew2,
              pcnew: &cnew,
              fsimple: true);
            v1 = pszNew;
            goto LABEL_75;
          }
          if ( _V_strstr(s1: szparseword, search: "V_GRIDY") != nullptr )
          {
            VOX_LookupRangeHeadingOrGrid(
              irhg: 3,
              pGroupName: szparseword,
              pChannel: pchan,
              soundsource: v2,
              ppszNew: &pszNew,
              ppszNew1: &pszNew1,
              ppszNew2: &pszNew2,
              pcnew: &cnew,
              fsimple: true);
            v1 = pszNew;
            goto LABEL_75;
          }
          if ( _V_strstr(s1: szparseword, search: "V_G0_") != nullptr )
          {
            v20 = VOX_LookupGlobalVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 0);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_G1_") != nullptr )
          {
            v20 = VOX_LookupGlobalVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 1);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_G2_") != nullptr )
          {
            v20 = VOX_LookupGlobalVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 2);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_G3_") != nullptr )
          {
            v20 = VOX_LookupGlobalVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 3);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_SEQG0_") != nullptr )
          {
            v20 = VOX_LookupGlobalSeqVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 0);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_SEQG1_") != nullptr )
          {
            v20 = VOX_LookupGlobalSeqVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 1);
          }
          else if ( _V_strstr(s1: szparseword, search: "V_SEQG2_") != nullptr )
          {
            v20 = VOX_LookupGlobalSeqVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 2);
          }
          else
          {
            if ( _V_strstr(s1: szparseword, search: "V_SEQG3_") == nullptr )
              goto LABEL_75;
            v20 = VOX_LookupGlobalSeqVirtual(type: chtype, soundsource: v2, pGroupName: szparseword, iglobal: 3);
          }
        }
        v1 = v20;
        if ( v20 != nullptr )
          goto LABEL_74;
      }
LABEL_75:
      VOX_InsertWords(ireplace: i, cnew, pszNew: v1, pszNew1, pszNew2);
      v1 = nullptr;
LABEL_76:
      ++i;
      v26 = 4 * i;
      v29 = &rgpparseword[i];
    }
    while ( *v29 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A330
// Name: _VOX_LoadSound
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_LoadSound(channel_t *pchan, const char *pszin)
{
  const char *v2; // edi
  int v3; // ebx
  char *v4; // eax
  const char *Directory; // esi
  channel_t *v6; // esi
  int v7; // eax
  char *v8; // esi
  char **v9; // edi
  int *p_fKeepCached; // esi
  CSfxTable *Name; // eax
  bool v12; // zf
  CAudioMixer *SentenceMixer; // eax
  CSfxTable *sfx; // edx
  ISoundServices_vtbl *v15; // esi
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // [esp-1Ch] [ebp-F44h]
  float v19; // [esp+0h] [ebp-F28h]
  voxword_t rgvoxword[32]; // [esp+10h] [ebp-F18h] BYREF
  char captionstream[1024]; // [esp+490h] [ebp-A98h] BYREF
  char buffer[512]; // [esp+890h] [ebp-698h] BYREF
  char pathbuffer[260]; // [esp+A90h] [ebp-498h] BYREF
  char groupname[512]; // [esp+B94h] [ebp-394h] BYREF
  char szpath[260]; // [esp+D94h] [ebp-194h] BYREF
  char captiontoken[128]; // [esp+E98h] [ebp-90h] BYREF
  float duration; // [esp+F18h] [ebp-10h] BYREF
  int i; // [esp+F1Ch] [ebp-Ch]
  CUtlSymbol captionSymbol; // [esp+F20h] [ebp-8h] BYREF
  bool emitcaption; // [esp+F27h] [ebp-1h] BYREF

  v2 = pszin;
  v3 = 0;
  emitcaption = false;
  captionSymbol.m_Id = -1;
  duration = 0.0;
  if ( pszin != nullptr )
  {
    memset(dst: (unsigned __int8 *)rgvoxword, value: 0, count: sizeof(rgvoxword));
    memset(dst: (unsigned __int8 *)buffer, value: 0, count: sizeof(buffer));
    v4 = VOX_LookupString(
           pSentenceName: pszin,
           psentencenum: nullptr,
           pbEmitCaption: &emitcaption,
           pCaptionSymbol: &captionSymbol,
           pflDuration: &duration);
    if ( v4 != nullptr )
    {
      Directory = VOX_GetDirectory(szpath, maxpath: 260, psz: v4);
      if ( (unsigned int)_V_strlen(str: Directory) <= 0x1FF )
      {
        V_strncpy(pDest: buffer, pSrc: Directory, maxLen: 512);
        VOX_ParseString(psz: buffer);
        v6 = pchan;
        VOX_ReplaceVirtualNames(pchan);
        i = 0;
        V_strncpy(pDest: groupname, pSrc: pszin, maxLen: 512);
        v7 = _V_strlen(str: groupname);
        if ( v7 > 0 )
        {
          v8 = &pathbuffer[v7 + 259];
          do
          {
            if ( isdigit(c: *v8) == 0 )
              break;
            *v8-- = 0;
          }
          while ( (int)&v8[1 - (_DWORD)groupname] > 0 );
          v6 = pchan;
          v2 = pszin;
        }
        V_snprintf(pDest: captionstream, maxLen: 1024, pFormat: "%s ", groupname);
        if ( rgpparseword[0] != nullptr )
        {
          v9 = rgpparseword;
          p_fKeepCached = &rgvoxword[0].fKeepCached;
          do
          {
            if ( VOX_ParseWordParams(psz: *v9, pvoxword: (voxword_t *)(p_fKeepCached - 5), fFirst: i == 0) != 0 )
            {
              V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s%s.wav", szpath, *v9);
              Name = S_FindName(szName: pathbuffer, pInCache: p_fKeepCached);
              v18 = *v9;
              p_fKeepCached[3] = (int)Name;
              *p_fKeepCached = 1;
              V_snprintf(pDest: captiontoken, maxLen: 128, pFormat: "S(%s%s) ", szpath, v18);
              V_strncat(pDest: captionstream, pSrc: captiontoken, destBufferSize: 0x400u, max_chars_to_copy: -1);
              ++v3;
              p_fKeepCached += 9;
            }
            v12 = rgpparseword[i + 1] == nullptr;
            v9 = &rgpparseword[++i];
          }
          while ( !v12 );
          v6 = pchan;
          v2 = pszin;
        }
        v6->pMixer = nullptr;
        if ( v3 != 0 )
        {
          SentenceMixer = CreateSentenceMixer(pWords: rgvoxword);
          v6->pMixer = SentenceMixer;
          if ( SentenceMixer != nullptr )
          {
            sfx = rgvoxword[0].sfx;
            LOBYTE(v6->flagsword) |= 2u;
            v6->sfx = sfx;
            if ( g_pSoundServices != nullptr )
            {
              if ( emitcaption )
              {
                if ( captionSymbol.m_Id == 0xFFFF )
                {
                  ((void (__stdcall *)(char *))g_pSoundServices->EmitSentenceCloseCaption)(a1: captionstream);
                  if ( snd_vox_captiontrace.m_pParent != nullptr
                    && snd_vox_captiontrace.m_pParent->m_Value.m_nValue != 0 )
                  {
                    _Msg(a1: "Vox: captionstream '%s'\n", captionstream);
                  }
                }
                else
                {
                  v15 = g_pSoundServices->__vftable;
                  v19 = duration;
                  v16 = CUtlSymbol::String(this: &captionSymbol);
                  ((void (__thiscall *)(ISoundServices *, const char *, _DWORD))v15->EmitCloseCaption)(
                    a1: g_pSoundServices,
                    a2: v16,
                    a3: LODWORD(v19));
                  if ( snd_vox_captiontrace.m_pParent != nullptr
                    && snd_vox_captiontrace.m_pParent->m_Value.m_nValue != 0 )
                  {
                    v17 = CUtlSymbol::String(this: &captionSymbol);
                    _Msg(a1: "Vox: caption '%s'\n", v17);
                  }
                }
              }
              else if ( snd_vox_captiontrace.m_pParent != nullptr
                     && snd_vox_captiontrace.m_pParent->m_Value.m_nValue != 0 )
              {
                _Msg(a1: "Vox:  No caption for '%s'\n", v2);
              }
            }
          }
        }
      }
      else
      {
        DevMsg(a1: "VOX_LoadSound: sentence is too long %s\n", Directory);
      }
    }
    else
    {
      DevMsg(a1: "VOX_LoadSound: no sentence named %s\n", pszin);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B010
// Name: void VOX_AddNumbers(char __near *,class CUtlVector<struct WordBuf,class CUtlMemory<struct WordBuf,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_AddNumbers(char *pGroupName, CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > *list)
{
  int v2; // ebx
  int v3; // edi
  char v4; // al
  int v5; // ebx
  const char *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  WordBuf *m_pMemory; // ecx
  int v10; // eax
  WordBuf *v11; // edi
  int v12; // [esp-18h] [ebp-138h]
  WordBuf w; // [esp+Ch] [ebp-114h] BYREF
  char sznumbers[16]; // [esp+10Ch] [ebp-14h] BYREF
  int i; // [esp+11Ch] [ebp-4h]

  i = 0;
  do
  {
    v2 = _V_strlen(str: pGroupName);
    v3 = _V_strlen(str: "V_NUMBERS");
    _V_strcpy(dest: sznumbers, src: "V_NUMBERS");
    v4 = pGroupName[v2 - 1];
    v5 = i;
    v12 = i;
    sznumbers[v3] = v4;
    sznumbers[v3 + 1] = 0;
    w.word[0] = 0;
    v6 = VOX_LookupSentenceByIndex(pGroupname: sznumbers, ipick: v12, pipicknext: nullptr);
    WordBuf::Set(this: &w, w: v6);
    m_Size = list->m_Size;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<WordBuf,int>::Grow(this: &list->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v10 = list->m_Size - m_Size - 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v10 << 8);
    v11 = &list->m_Memory.m_pMemory[m_Size];
    if ( v11 != nullptr )
      V_strncpy(pDest: v11->word, pSrc: w.word, maxLen: 256);
    i = v5 + 1;
  }
  while ( v5 + 1 <= 30 );
}

//------------------------------------------------------------------------------
// Address: 0x1005B100
// Name: void VOX_AddRndVirtual(char __near *,class CUtlVector<struct WordBuf,class CUtlMemory<struct WordBuf,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_AddRndVirtual(char *pGroupName, CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > *list)
{
  int v2; // eax
  CUtlSymbol *i; // ecx
  int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // edi
  char *pName; // ebx
  const char *v9; // eax
  int count; // ecx
  unsigned __int16 m_Id; // [esp-4h] [ebp-140h]
  WordBuf w; // [esp+Ch] [ebp-130h] BYREF
  char szsentencename[32]; // [esp+10Ch] [ebp-30h] BYREF
  const char *v14; // [esp+12Ch] [ebp-10h]
  unsigned int v15; // [esp+130h] [ebp-Ch]
  int m_Size; // [esp+134h] [ebp-8h]
  int snum; // [esp+138h] [ebp-4h]

  if ( pGroupName != nullptr )
  {
    CUtlSymbolTable::AddString(
      this: &sentencegroup_t::s_SymbolTable,
      result: (CUtlSymbol *)&pGroupName,
      pString: pGroupName);
    v2 = 0;
    if ( g_SentenceGroups.m_Size > 0 )
    {
      for ( i = &g_SentenceGroups.m_Memory.m_pMemory->groupname; (_WORD)pGroupName != i->m_Id; i += 3 )
      {
        if ( ++v2 >= g_SentenceGroups.m_Size )
          return;
      }
      if ( v2 >= 0 )
      {
        v4 = v2;
        m_Id = g_SentenceGroups.m_Memory.m_pMemory[v2].groupname.m_Id;
        v15 = 6 * v2;
        v14 = CUtlSymbolTable::String(this: &sentencegroup_t::s_SymbolTable, id: (CUtlSymbol)m_Id);
        v5 = 0;
        snum = 0;
        if ( g_SentenceGroups.m_Memory.m_pMemory[v4].count > 0 )
        {
          do
          {
            V_snprintf(pDest: szsentencename, maxLen: 32, pFormat: "%s%d", v14, v5);
            if ( szsentencename[0] == 33 )
              pGroupName = &szsentencename[1];
            else
              pGroupName = szsentencename;
            v6 = 0;
            m_Size = g_Sentences.m_Size;
            if ( g_Sentences.m_Size > 0 )
            {
              v7 = 0;
              while ( 1 )
              {
                pName = g_Sentences.m_Memory.m_pMemory[v7].pName;
                if ( _V_stricmp(s1: pGroupName, s2: pName) == 0 )
                  break;
                ++v6;
                ++v7;
                if ( v6 >= m_Size )
                  goto LABEL_19;
              }
              v9 = &pName[_V_strlen(str: pName) + 1];
              if ( v9 != nullptr )
              {
                w.word[0] = 0;
                WordBuf::Set(this: &w, w: v9);
                CUtlVector<WordBuf,CUtlMemory<WordBuf,int>>::InsertBefore(this: list, elem: list->m_Size, src: &w);
              }
            }
LABEL_19:
            count = g_SentenceGroups.m_Memory.m_pMemory[v15 / 6].count;
            v5 = snum + 1;
            snum = v5;
          }
          while ( v5 < count );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B260
// Name: VOX_BuildVirtualNameList
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_BuildVirtualNameList(char *word, CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > *list)
{
  char v2; // bl
  char *v3; // eax
  char *v4; // edi
  int v5; // esi
  _BYTE *v6; // ebx
  WordBuf w; // [esp+Ch] [ebp-240h] BYREF
  char szgroup1[32]; // [esp+10Ch] [ebp-140h] BYREF
  char szgroup2[32]; // [esp+12Ch] [ebp-120h] BYREF
  char szparseword[256]; // [esp+14Ch] [ebp-100h] BYREF

  v2 = word[_V_strlen(str: word) - 1];
  V_strncpy(pDest: szparseword, pSrc: word, maxLen: 256);
  v3 = _V_strstr(s1: szparseword, search: "_MAP__");
  v4 = v3;
  if ( v3 != nullptr )
  {
    v5 = 0;
    if ( g_cmapnames > 0 )
    {
      v6 = v3 + 4;
      do
      {
        *v6 = 48;
        if ( v5 >= 10 )
          V_snprintf(pDest: v4 + 4, maxLen: 2, pFormat: "%d", v5);
        else
          V_snprintf(pDest: v4 + 5, maxLen: 1, pFormat: "%1d", v5);
        VOX_BuildVirtualNameList(word: szparseword, list);
        ++v5;
      }
      while ( v5 < g_cmapnames );
    }
    return;
  }
  if ( _V_strstr(s1: szparseword, search: "V_MYNAME") != nullptr
    || _V_strstr(s1: szparseword, search: "V_MYNUM") != nullptr
    || _V_strstr(s1: szparseword, search: "V_RND") != nullptr )
  {
    goto LABEL_32;
  }
  if ( _V_strstr(s1: szparseword, search: "V_DIST") != nullptr || _V_strstr(s1: szparseword, search: "V_DIR") != nullptr )
    goto LABEL_23;
  if ( _V_strstr(s1: szparseword, search: "V_IDIED") != nullptr )
  {
    _V_strcpy(dest: szgroup1, src: "V_MYNAME");
    szgroup1[8] = v2;
    szgroup1[9] = 0;
    _V_strcpy(dest: szgroup2, src: "V_MYNUM");
    szgroup2[7] = v2;
    szgroup2[8] = 0;
    VOX_BuildVirtualNameList(word: szgroup1, list);
    VOX_BuildVirtualNameList(word: szgroup2, list);
    return;
  }
  if ( _V_strstr(s1: szparseword, search: "V_WHODIED") == nullptr )
  {
    if ( _V_strstr(s1: szparseword, search: "V_SECTOR") != nullptr
      || _V_strstr(s1: szparseword, search: "V_GRIDX") != nullptr
      || _V_strstr(s1: szparseword, search: "V_GRIDY") != nullptr )
    {
LABEL_23:
      VOX_AddNumbers(pGroupName: szparseword, list);
      goto LABEL_33;
    }
    if ( _V_strstr(s1: szparseword, search: "V_G0_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_G1_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_G2_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_G3_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_SEQG0_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_SEQG1_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_SEQG2_") != nullptr
      || _V_strstr(s1: szparseword, search: "V_SEQG3_") != nullptr )
    {
LABEL_32:
      VOX_AddRndVirtual(pGroupName: szparseword, list);
    }
  }
LABEL_33:
  if ( V_strnicmp(s1: szparseword, s2: "V_", n: 2) != 0 )
  {
    w.word[0] = 0;
    WordBuf::Set(this: &w, w: szparseword);
    CUtlVector<WordBuf,CUtlMemory<WordBuf,int>>::InsertBefore(this: list, elem: list->m_Size, src: &w);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B630
// Name: int VOX_GroupAdd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VOX_GroupAdd(const char *pSentenceName)
{
  signed int v1; // esi
  void *v2; // esp
  int v3; // esi
  sentencegroup_t *v4; // eax
  int v5; // esi
  sentencegroup_t *v6; // edi
  char v8[14]; // [esp+0h] [ebp-14h] BYREF
  CUtlSymbol v9; // [esp+Eh] [ebp-6h] BYREF
  CUtlSymbol symGroupName; // [esp+10h] [ebp-4h] BYREF

  v1 = strlen(pSentenceName) - 1;
  if ( v1 <= 0 || isdigit(c: pSentenceName[v1]) == 0 )
    return -1;
  do
  {
    if ( isdigit(c: pSentenceName[v1]) == 0 )
      break;
    --v1;
  }
  while ( v1 > 0 );
  v2 = alloca(v1 + 2);
  V_strncpy(pDest: v8, pSrc: pSentenceName, maxLen: v1 + 2);
  CUtlSymbolTable::AddString(this: &sentencegroup_t::s_SymbolTable, result: &symGroupName, pString: v8);
  v3 = 0;
  if ( g_SentenceGroups.m_Size <= 0 )
  {
LABEL_8:
    v5 = CUtlVector<sentencegroup_t,CUtlMemory<sentencegroup_t,int>>::InsertBefore(
           this: &g_SentenceGroups,
           elem: g_SentenceGroups.m_Size);
    v6 = &g_SentenceGroups.m_Memory.m_pMemory[v5];
    v6->groupname = (CUtlSymbol)CUtlSymbolTable::AddString(
                                  this: &sentencegroup_t::s_SymbolTable,
                                  result: &v9,
                                  pString: v8)->m_Id;
    v6->count = 1;
    return v5;
  }
  else
  {
    while ( symGroupName.m_Id != g_SentenceGroups.m_Memory.m_pMemory[(g_SentenceGroups.m_Size + v3 - 1)
                                                                   % g_SentenceGroups.m_Size].groupname.m_Id )
    {
      if ( ++v3 >= g_SentenceGroups.m_Size )
        goto LABEL_8;
    }
    v4 = &g_SentenceGroups.m_Memory.m_pMemory[(g_SentenceGroups.m_Size + v3 - 1) % g_SentenceGroups.m_Size];
    ++v4->count;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B740
// Name: void VOX_Precache(class IEngineSound __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_Precache(IEngineSound *pSoundSystem, unsigned int sentenceIndex, const char *pPathOverride)
{
  sentence_t *m_pMemory; // ebx
  unsigned int v4; // edi
  char *pName; // eax
  int v6; // esi
  int v7; // eax
  const char *Directory; // eax
  char *v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // eax
  char *v13; // ebx
  int m_Size; // ebx
  WordBuf *v15; // eax
  voxword_t rgvoxword[32]; // [esp+Ch] [ebp-920h] BYREF
  char buffer[512]; // [esp+48Ch] [ebp-4A0h] BYREF
  char *pWords[32]; // [esp+68Ch] [ebp-2A0h]
  char pathbuffer[260]; // [esp+70Ch] [ebp-220h] BYREF
  char szpath[260]; // [esp+810h] [ebp-11Ch] BYREF
  int count; // [esp+914h] [ebp-18h]
  CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > list; // [esp+918h] [ebp-14h] BYREF
  voxword_t *sentenceIndexa; // [esp+938h] [ebp+Ch]
  int i; // [esp+93Ch] [ebp+10h]

  m_pMemory = g_Sentences.m_Memory.m_pMemory;
  v4 = sentenceIndex;
  pName = g_Sentences.m_Memory.m_pMemory[sentenceIndex].pName;
  if ( *pName != 86 || pName[1] != 95 )
  {
    *((_BYTE *)&g_Sentences.m_Memory.m_pMemory[v4] + 8) |= 0x80u;
    m_pMemory = g_Sentences.m_Memory.m_pMemory;
  }
  v6 = 0;
  memset(dst: (unsigned __int8 *)rgvoxword, value: 0, count: sizeof(rgvoxword));
  v7 = _V_strlen(str: m_pMemory[v4].pName);
  Directory = VOX_GetDirectory(szpath, maxpath: 260, psz: &m_pMemory[v4].pName[v7 + 1]);
  V_strncpy(pDest: buffer, pSrc: Directory, maxLen: 512);
  if ( pPathOverride != nullptr )
    V_strncpy(pDest: szpath, pSrc: pPathOverride, maxLen: 260);
  VOX_ParseString(psz: buffer);
  v9 = rgpparseword[0];
  v10 = 0;
  count = 0;
  if ( rgpparseword[0] != nullptr )
  {
    v11 = 0;
    do
    {
      ++v10;
      pWords[v11] = v9;
      v11 = v10;
      v9 = rgpparseword[v10];
    }
    while ( v9 != nullptr );
    count = v10;
  }
  v12 = 0;
  i = 0;
  if ( v10 > 0 )
  {
    sentenceIndexa = rgvoxword;
    while ( 1 )
    {
      v13 = pWords[v12];
      if ( *v13 == 86 && v13[1] == 95 )
      {
        memset(&list, 0, sizeof(list));
        VOX_BuildVirtualNameList(word: v13, &list);
        m_Size = list.m_Size;
        if ( list.m_Size > 0 )
        {
          do
          {
            V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s%s.wav", szpath, list.m_Memory.m_pMemory[v6].word);
            pSoundSystem->PrecacheSound(this: pSoundSystem, a2: pathbuffer, a3: false, a4: false);
            ++v6;
            --m_Size;
          }
          while ( m_Size != 0 );
          v6 = 0;
        }
        v15 = list.m_Memory.m_pMemory;
        list.m_Size = 0;
        if ( list.m_Memory.m_nGrowSize >= 0 )
        {
          if ( list.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
            v15 = nullptr;
            list.m_Memory.m_pMemory = nullptr;
          }
          list.m_Memory.m_nAllocationCount = 0;
        }
        list.m_pElements = v15;
        if ( list.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      }
      else if ( VOX_ParseWordParams(psz: v13, pvoxword: sentenceIndexa, fFirst: v12 == 0) != 0 )
      {
        V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s%s.wav", szpath, v13);
        pSoundSystem->PrecacheSound(this: pSoundSystem, a2: pathbuffer, a3: false, a4: false);
        ++sentenceIndexa;
      }
      if ( ++i >= count )
        break;
      v12 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B970
// Name: _VOX_PrecacheSentenceGroup
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_PrecacheSentenceGroup(IEngineSound *pSoundSystem, const char *pGroupName, const char *pPathOverride)
{
  signed int v3; // esi
  int v4; // edi
  int len; // [esp+4h] [ebp-4h]

  v3 = 0;
  len = _V_strlen(str: pGroupName);
  if ( g_Sentences.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      if ( *((char *)&g_Sentences.m_Memory.m_pMemory[v4] + 8) >= 0
        && V_strncasecmp(s1: g_Sentences.m_Memory.m_pMemory[v4].pName, s2: pGroupName, n: len) == 0 )
      {
        VOX_Precache(pSoundSystem, sentenceIndex: v3, pPathOverride);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < g_Sentences.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B9F0
// Name: void VOX_TouchSounds(class CUtlDict<int,int> __near &,class CUtlRBTree<struct ccpair,int,bool (*)(struct ccpair const __near &,struct ccpair const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ccpair,int>,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_TouchSounds(
        CUtlDict<int,int> *list,
        CUtlRBTree<ccpair,int,bool (__cdecl*)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int> > *ccpairs,
        bool spewsentences)
{
  int i; // esi
  void *v4; // eax
  UtlRBTreeNode_t<ccpair,int> *j; // esi
  void *v6; // edi
  UtlRBTreeNode_t<ccpair,int> *Inorder; // esi
  IBaseFileSystem_vtbl *v8; // edi
  int v9; // eax
  char outline[512]; // [esp+8h] [ebp-200h] BYREF
  void *fh; // [esp+218h] [ebp+10h]

  for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &list->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &list->m_Elements.m_Tree,
              i) )
  {
    V_snprintf(
      pDest: outline,
      maxLen: 512,
      pFormat: "sound/%s",
      list->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: outline, a3: "rb", a4: 0);
    if ( v4 != nullptr )
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
  }
  if ( spewsentences )
  {
    for ( j = (UtlRBTreeNode_t<ccpair,int> *)CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::FirstInorder(this: ccpairs);
          j != (UtlRBTreeNode_t<ccpair,int> *)-1;
          j = CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::NextInorder(
                this: ccpairs,
                i: (int)j) )
    {
      _Msg(
        a1: "\"%s\"\t\"%s\"\n",
        ccpairs->m_Elements.m_pMemory[(_DWORD)j].m_Data.token.word,
        ccpairs->m_Elements.m_pMemory[(_DWORD)j].m_Data.value.word);
    }
    v6 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: "sentences.m3u", a3: "wt", a4: "GAME");
    fh = v6;
    if ( v6 != nullptr )
    {
      Inorder = (UtlRBTreeNode_t<ccpair,int> *)CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::FirstInorder(this: ccpairs);
      if ( Inorder != (UtlRBTreeNode_t<ccpair,int> *)-1 )
      {
        do
        {
          V_snprintf(
            pDest: outline,
            maxLen: 512,
            pFormat: "%s\n",
            ccpairs->m_Elements.m_pMemory[(_DWORD)Inorder].m_Data.fullpath.word);
          v8 = g_pFileSystem->IBaseFileSystem::__vftable;
          v9 = _V_strlen(str: outline);
          v8->Write(this: &g_pFileSystem->IBaseFileSystem, a2: outline, a3: v9, a4: fh);
          Inorder = CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::NextInorder(
                      this: ccpairs,
                      i: (int)Inorder);
        }
        while ( Inorder != (UtlRBTreeNode_t<ccpair,int> *)-1 );
        v6 = fh;
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BBA0
// Name: void VOX_GroupInitAllLRUs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_GroupInitAllLRUs()
{
  int v0; // ecx
  int v1; // esi
  int v2; // eax
  unsigned __int8 *m_pMemory; // edx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // edi

  v0 = 0;
  v1 = 0;
  if ( g_SentenceGroups.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      g_SentenceGroups.m_Memory.m_pMemory[v2].lru = v1;
      ++v0;
      v1 += g_SentenceGroups.m_Memory.m_pMemory[v2++].count;
    }
    while ( v0 < g_SentenceGroups.m_Size );
  }
  m_pMemory = g_GroupLRU.m_Memory.m_pMemory;
  m_Size = 0;
  g_GroupLRU.m_Size = 0;
  if ( g_GroupLRU.m_Memory.m_nGrowSize < 0 )
  {
    m_nAllocationCount = g_GroupLRU.m_Memory.m_nAllocationCount;
  }
  else
  {
    if ( g_GroupLRU.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_GroupLRU.m_Memory.m_pMemory);
      m_Size = g_GroupLRU.m_Size;
      m_pMemory = nullptr;
      g_GroupLRU.m_Memory.m_pMemory = nullptr;
    }
    m_nAllocationCount = 0;
    g_GroupLRU.m_Memory.m_nAllocationCount = 0;
  }
  g_GroupLRU.m_pElements = m_pMemory;
  if ( m_Size < v1 )
  {
    v6 = v1 - m_Size;
    v7 = m_Size;
    if ( v6 != 0 )
    {
      if ( m_Size + v6 > m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)&g_GroupLRU, num: v6 + m_Size - m_nAllocationCount);
        m_Size = g_GroupLRU.m_Size;
        m_pMemory = g_GroupLRU.m_Memory.m_pMemory;
      }
      g_GroupLRU.m_Size = v6 + m_Size;
      v8 = m_Size - v7;
      g_GroupLRU.m_pElements = m_pMemory;
      if ( v8 > 0 && v6 > 0 )
        _V_memmove(dest: &m_pMemory[v7 + v6], src: &m_pMemory[v7], count: v8);
    }
  }
  v9 = 0;
  if ( g_SentenceGroups.m_Size > 0 )
  {
    v10 = 0;
    do
    {
      VOX_LRUInit(pGroup: (int)&g_SentenceGroups.m_Memory.m_pMemory[v10]);
      ++v9;
      ++v10;
    }
    while ( v9 < g_SentenceGroups.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BD50
// Name: void VOX_CompactSentenceFile(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_CompactSentenceFile()
{
  int v0; // edi
  int v1; // ebx
  int v2; // esi
  int m_Size; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // edi
  int v9; // eax
  char *v10; // ebx
  unsigned int v11; // edi
  int totalMem; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  for ( i = 0; i < g_Sentences.m_Size; ++i )
  {
    v2 = _V_strlen(str: g_Sentences.m_Memory.m_pMemory[v0].pName) + 1;
    v1 += v2 + _V_strlen(str: &g_Sentences.m_Memory.m_pMemory[v0++].pName[v2]) + 1;
  }
  m_Size = g_SentenceFile.m_Size;
  if ( g_SentenceFile.m_Size < v1 )
  {
    v4 = v1 - g_SentenceFile.m_Size;
    v5 = g_SentenceFile.m_Size;
    if ( v4 != 0 )
    {
      if ( g_SentenceFile.m_Size + v4 > g_SentenceFile.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(
          this: &g_SentenceFile.m_Memory,
          num: v4 + g_SentenceFile.m_Size - g_SentenceFile.m_Memory.m_nAllocationCount);
        m_Size = g_SentenceFile.m_Size;
      }
      g_SentenceFile.m_Size = v4 + m_Size;
      v6 = m_Size - v5;
      g_SentenceFile.m_pElements = g_SentenceFile.m_Memory.m_pMemory;
      if ( v6 > 0 && v4 > 0 )
        _V_memmove(
          dest: &g_SentenceFile.m_Memory.m_pMemory[v5 + v4],
          src: &g_SentenceFile.m_Memory.m_pMemory[v5],
          count: v6);
    }
  }
  v7 = 0;
  totalMem = 0;
  for ( ia = 0; ia < g_Sentences.m_Size; ++ia )
  {
    v8 = _V_strlen(str: g_Sentences.m_Memory.m_pMemory[v7].pName) + 1;
    v9 = _V_strlen(str: &g_Sentences.m_Memory.m_pMemory[v7].pName[v8]);
    v10 = &g_SentenceFile.m_Memory.m_pMemory[totalMem];
    v11 = v9 + 1 + v8;
    memcpy(
      dst: (unsigned __int8 *)&g_SentenceFile.m_Memory.m_pMemory[totalMem],
      src: (unsigned __int8 *)g_Sentences.m_Memory.m_pMemory[v7].pName,
      count: v11);
    totalMem += v11;
    g_Sentences.m_Memory.m_pMemory[v7++].pName = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BE90
// Name: public: int CUtlMap<char const __near *,int,int>::Insert(char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,int,int>::Insert(CUtlMap<char const *,int,int> *this, const char **key)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  CUtlMap<char const *,int,int>::Node_t node; // [esp+8h] [ebp-Ch] BYREF
  int parent; // [esp+10h] [ebp-4h] BYREF

  node.key = *key;
  parent = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    &parent,
    leftchild: (bool *)&key);
  v3 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v3,
    parent,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
    m_pMemory[v3].m_Data = node;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1005BF00
// Name: public: int CUtlDict<int,int>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,int>::Insert(CUtlDict<int,int> *this, char *pName)
{
  const char *v2; // edi
  char *v4; // eax

  v2 = pName;
  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v4, v2);
    pName = v4;
    return CUtlMap<char const *,int,int>::Insert(this: &this->m_Elements, key: (const char **)&pName);
  }
  else
  {
    pName = nullptr;
    return CUtlMap<char const *,int,int>::Insert(this: &this->m_Elements, key: (const char **)&pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BF80
// Name: void VOX_TouchSound(char const __near *,class CUtlDict<int,int> __near &,class CUtlRBTree<struct ccpair,int,bool (*)(struct ccpair const __near &,struct ccpair const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ccpair,int>,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_TouchSound(
        const char *pszin,
        CUtlDict<int,int> *filelist,
        CUtlRBTree<ccpair,int,bool (__cdecl*)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int> > *ccpairs,
        bool spewsentences)
{
  int v4; // esi
  const char *v5; // edi
  char *v6; // eax
  const char *Directory; // esi
  WordBuf *m_pMemory; // eax
  const char **v9; // esi
  int v10; // esi
  const char *v11; // eax
  const char *v12; // eax
  int v13; // esi
  const char *v14; // edi
  char *v15; // [esp-10h] [ebp-ED8h]
  const char *v16; // [esp-10h] [ebp-ED8h]
  const char *v17; // [esp-10h] [ebp-ED8h]
  const char *v18; // [esp-Ch] [ebp-ED4h]
  const char *v19; // [esp-Ch] [ebp-ED4h]
  const char *v20; // [esp-Ch] [ebp-ED4h]
  const char *v21; // [esp-Ch] [ebp-ED4h]
  voxword_t rgvoxword[32]; // [esp+4h] [ebp-EC4h] BYREF
  char buffer[512]; // [esp+484h] [ebp-A44h] BYREF
  char pDest[256]; // [esp+684h] [ebp-844h] BYREF
  ccpair pair; // [esp+784h] [ebp-744h] BYREF
  WordBuf w; // [esp+A84h] [ebp-444h] BYREF
  char szpath[260]; // [esp+B84h] [ebp-344h] BYREF
  char name[256]; // [esp+C88h] [ebp-240h] BYREF
  char pathbuffer[260]; // [esp+D88h] [ebp-140h] BYREF
  CUtlMap<char const *,int,int>::Node_t v30; // [esp+E8Ch] [ebp-3Ch] BYREF
  CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > list; // [esp+E94h] [ebp-34h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+EA8h] [ebp-20h] BYREF
  CUtlVector<WordBuf,CUtlMemory<WordBuf,int> > rep; // [esp+EB0h] [ebp-18h] BYREF
  int c; // [esp+EC4h] [ebp-4h]
  int i; // [esp+ED0h] [ebp+8h]

  if ( pszin != nullptr )
  {
    memset(dst: (unsigned __int8 *)rgvoxword, value: 0, count: sizeof(rgvoxword));
    memset(dst: (unsigned __int8 *)buffer, value: 0, count: sizeof(buffer));
    v4 = 0;
    c = g_Sentences.m_Size;
    if ( g_Sentences.m_Size <= 0 )
      goto LABEL_8;
    search.elem = 0;
    while ( 1 )
    {
      v5 = *(char **)((char *)&g_Sentences.m_Memory.m_pMemory->pName + search.elem);
      if ( _V_stricmp(s1: pszin, s2: v5) == 0 )
        break;
      search.elem += 12;
      if ( ++v4 >= c )
        goto LABEL_8;
    }
    v6 = (char *)&v5[_V_strlen(str: v5) + 1];
    if ( v6 != nullptr )
    {
      Directory = VOX_GetDirectory(szpath, maxpath: 260, psz: v6);
      if ( (unsigned int)_V_strlen(str: Directory) <= 0x1FF )
      {
        V_strncpy(pDest: buffer, pSrc: Directory, maxLen: 512);
        VOX_ParseString(psz: buffer);
        m_pMemory = nullptr;
        i = 0;
        memset(&rep, 0, sizeof(rep));
        if ( rgpparseword[0] != nullptr )
        {
          v9 = (const char **)rgpparseword;
          do
          {
            if ( VOX_ParseWordParams(psz: (char *)*v9, pvoxword: rgvoxword, fFirst: i == 0) != 0 )
            {
              if ( V_strnicmp(s1: *v9, s2: "V_", n: 2) != 0 )
              {
                V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s%s.wav", szpath, *v9);
                v30.key = pathbuffer;
                if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                       this: &filelist->m_Elements.m_Tree,
                       search: &v30) == -1 )
                  CUtlDict<int,int>::Insert(this: filelist, pName: pathbuffer);
                v19 = *v9;
                w.word[0] = 0;
                WordBuf::Set(this: &w, w: v19);
                CUtlVector<WordBuf,CUtlMemory<WordBuf,int>>::InsertBefore(this: &rep, elem: rep.m_Size, src: &w);
                v20 = *v9;
                pair.token.word[0] = 0;
                pair.value.word[0] = 0;
                pair.fullpath.word[0] = 0;
                V_snprintf(pDest: pair.token.word, maxLen: 256, pFormat: "S(%s%s)", szpath, v20);
                WordBuf::Set(this: &pair.value, w: *v9);
                v12 = (const char *)((int (__thiscall *)(ISoundServices *, char *, const char *))g_pSoundServices->GetGameDir)(
                                      a1: g_pSoundServices,
                                      a2: szpath,
                                      a3: *v9);
                V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s/sound/%s%s.wav", v12, v17, v21);
                V_FixSlashes(pname: pathbuffer, separator: 92);
                WordBuf::Set(this: &pair.fullpath, w: pathbuffer);
                if ( CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Find(
                       this: ccpairs,
                       search: &pair) == -1 )
                  CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Insert(
                    this: ccpairs,
                    insert: &pair);
              }
              else
              {
                v15 = (char *)*v9;
                memset(&list, 0, sizeof(list));
                VOX_BuildVirtualNameList(word: v15, &list);
                v10 = 0;
                for ( c = list.m_Size; v10 < c; ++v10 )
                {
                  V_snprintf(pDest: name, maxLen: 256, pFormat: "%s", list.m_Memory.m_pMemory[v10].word);
                  if ( V_strnicmp(s1: name, s2: "V_", n: 2) == 0 )
                    _Warning(a1: "VOX_TouchSound didn't resolve virtual token %s!\n", name);
                  V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s%s.wav", szpath, name);
                  search.key = pathbuffer;
                  if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                         this: &filelist->m_Elements.m_Tree,
                         &search) == -1 )
                    CUtlDict<int,int>::Insert(this: filelist, pName: pathbuffer);
                  w.word[0] = 0;
                  if ( v10 == 0 )
                  {
                    WordBuf::Set(this: &w, w: name);
                    CUtlVector<WordBuf,CUtlMemory<WordBuf,int>>::InsertBefore(this: &rep, elem: rep.m_Size, src: &w);
                  }
                  pair.token.word[0] = 0;
                  pair.value.word[0] = 0;
                  pair.fullpath.word[0] = 0;
                  V_snprintf(pDest: pair.token.word, maxLen: 256, pFormat: "S(%s%s)", szpath, name);
                  WordBuf::Set(this: &pair.value, w: name);
                  v11 = (const char *)((int (__thiscall *)(ISoundServices *, char *, char *))g_pSoundServices->GetGameDir)(
                                        a1: g_pSoundServices,
                                        a2: szpath,
                                        a3: name);
                  V_snprintf(pDest: pathbuffer, maxLen: 260, pFormat: "%s/sound/%s%s.wav", v11, v16, v18);
                  V_FixSlashes(pname: pathbuffer, separator: 92);
                  WordBuf::Set(this: &pair.fullpath, w: pathbuffer);
                  if ( CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Find(
                         this: ccpairs,
                         search: &pair) == -1 )
                    CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Insert(
                      this: ccpairs,
                      insert: &pair);
                }
                CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&list);
              }
            }
            v9 = (const char **)&rgpparseword[++i];
          }
          while ( *v9 != nullptr );
          m_pMemory = rep.m_Memory.m_pMemory;
        }
        if ( spewsentences )
        {
          v13 = 0;
          pDest[0] = 0;
          if ( rep.m_Size > 0 )
          {
            v14 = (const char *)m_pMemory;
            do
            {
              V_strncat(pDest, pSrc: v14, destBufferSize: 0x400u, max_chars_to_copy: -1);
              if ( v13 != rep.m_Size - 1 )
                V_strncat(pDest, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
              ++v13;
              v14 += 256;
            }
            while ( v13 < rep.m_Size );
          }
          _Msg(a1: "     %s\n", pDest);
          m_pMemory = rep.m_Memory.m_pMemory;
        }
        if ( rep.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      }
      else
      {
        DevMsg(a1: "VOX_TouchSound: sentence is too long %s\n", Directory);
      }
    }
    else
    {
LABEL_8:
      DevMsg(a1: "VOX_TouchSound: no sentence named %s\n", pszin);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C490
// Name: void VOX_AddSentenceWavesToResList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VOX_AddSentenceWavesToResList()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ebx
  int v5; // esi
  sentence_t *v6; // esi
  int v7; // esi
  char *v8; // ebx
  const char *v9; // eax
  bool v10; // zf
  int i; // esi
  int Inorder; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v13; // ebx
  const char *pName; // [esp-14h] [ebp-78h]
  CUtlRBTree<ccpair,int,bool (__cdecl*)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int> > ccpairs; // [esp+4h] [ebp-60h] BYREF
  CUtlDict<int,int> list; // [esp+28h] [ebp-3Ch] BYREF
  int v17; // [esp+4Ch] [ebp-18h]
  char *s1; // [esp+50h] [ebp-14h]
  int m_Size; // [esp+54h] [ebp-10h]
  int v20; // [esp+58h] [ebp-Ch]
  sentence_t *pSentence; // [esp+5Ch] [ebp-8h]
  BOOL spewsentences; // [esp+60h] [ebp-4h]

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-makereslists") != 0
    || (v1 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-spewsentences") != 0) )
  {
    v2 = _CommandLine();
    LOBYTE(spewsentences) = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(
                              a1: v2,
                              a2: "-spewsentences") != 0;
    v3 = 0;
    list.m_Elements.m_Tree.m_Root = -1;
    list.m_Elements.m_Tree.m_FirstFree = -1;
    list.m_Elements.m_Tree.m_LastAlloc.index = -1;
    ccpairs.m_Root = -1;
    ccpairs.m_FirstFree = -1;
    ccpairs.m_LastAlloc.index = -1;
    m_pMemory = nullptr;
    memset(&list.m_Elements.m_Tree.m_Elements, 0, sizeof(list.m_Elements.m_Tree.m_Elements));
    list.m_Elements.m_Tree.m_NumElements = 0;
    list.m_Elements.m_Tree.m_pElements = nullptr;
    list.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    ccpairs.m_LessFunc = CCPairLessFunc;
    memset(&ccpairs.m_Elements, 0, sizeof(ccpairs.m_Elements));
    ccpairs.m_NumElements = 0;
    ccpairs.m_pElements = nullptr;
    if ( g_Sentences.m_Size > 0 )
    {
      v5 = 0;
      v20 = 0;
      m_Size = g_Sentences.m_Size;
      do
      {
        v6 = (sentence_t *)((char *)g_Sentences.m_Memory.m_pMemory + v5);
        pName = v6->pName;
        pSentence = v6;
        if ( V_strnicmp(s1: pName, s2: "V_", n: 2) != 0 )
        {
          if ( spewsentences )
          {
            s1 = v6->pName;
            v7 = 0;
            v17 = g_Sentences.m_Size;
            if ( g_Sentences.m_Size > 0 )
            {
              while ( 1 )
              {
                v8 = g_Sentences.m_Memory.m_pMemory[v3].pName;
                if ( _V_stricmp(s1, s2: v8) == 0 )
                  break;
                ++v7;
                ++v3;
                if ( v7 >= v17 )
                  goto LABEL_13;
              }
              v9 = &v8[_V_strlen(str: v8) + 1];
              if ( v9 != nullptr )
                _Msg(a1: "%s : %s\n", pSentence->pName, v9);
LABEL_13:
              v3 = 0;
            }
          }
          VOX_TouchSound(pszin: pSentence->pName, filelist: &list, &ccpairs, spewsentences);
        }
        v5 = v20 + 12;
        v10 = m_Size-- == 1;
        v20 += 12;
      }
      while ( !v10 );
      m_pMemory = list.m_Elements.m_Tree.m_Elements.m_pMemory;
    }
    VOX_TouchSounds(&list, &ccpairs, spewsentences);
    for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &list.m_Elements.m_Tree);
          i != -1;
          i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                this: &list.m_Elements.m_Tree,
                i) )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory[i].m_Data.key);
    }
    CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &list.m_Elements.m_Tree);
    CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::RemoveAll(this: &ccpairs);
    if ( ccpairs.m_Elements.m_nGrowSize >= 0 && ccpairs.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ccpairs.m_Elements.m_pMemory);
    Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &list.m_Elements.m_Tree);
    if ( Inorder != -1 )
    {
      v13 = list.m_Elements.m_Tree.m_Elements.m_pMemory;
      do
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v13[Inorder].m_Data.key);
        Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                    this: &list.m_Elements.m_Tree,
                    i: Inorder);
      }
      while ( Inorder != -1 );
    }
    CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &list.m_Elements.m_Tree);
    CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &list.m_Elements.m_Tree);
    if ( list.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 && list.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C710
// Name: _VOX_ReadSentenceFile
// Source: json
//------------------------------------------------------------------------------
void __usercall VOX_ReadSentenceFile(int a1@<ebx>, const char *psentenceFileName)
{
  CMapReslistGenerator *v2; // eax
  void *v3; // esi
  int v4; // eax
  unsigned int v5; // ebx
  unsigned int Size; // eax
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // ebx
  const char *v9; // esi
  char v10; // al
  char *i; // edi
  sentence_t *v12; // eax
  char v13; // al
  characterset_t whitespace; // [esp+4h] [ebp-108h] BYREF
  unsigned __int8 *pFileData; // [esp+104h] [ebp-8h]
  const char *pName; // [esp+108h] [ebp-4h]

  if ( VOX_ListFileIsLoaded(psentenceFileName) != 0 )
  {
    v2 = MapReslistGenerator();
    if ( v2->m_bLoggingEnabled && !v2->m_bLogToEngineList )
      VOX_AddSentenceWavesToResList();
  }
  else
  {
    v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: psentenceFileName, a3: "rb", a4: 0);
    if ( v3 != nullptr )
    {
      v4 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: v3,
             a3: a1);
      v5 = v4;
      if ( v4 > 0 )
      {
        pFileData = (unsigned __int8 *)g_pFileSystem->AllocOptimalReadBuffer(
                                         this: g_pFileSystem,
                                         a2: v3,
                                         a3: v4 + 1,
                                         a4: 0);
        if ( pFileData != nullptr )
        {
          pName = (const char *)g_pFileSystem->IAppSystem::__vftable;
          Size = IFileSystem::GetOptimalReadSize(this: g_pFileSystem, hFile: v3, nLogicalSize: v5);
          v7 = pFileData;
          (*((void (__thiscall **)(IFileSystem *, unsigned __int8 *, unsigned int, unsigned int, void *))pName + 72))(
            a1: g_pFileSystem,
            a2: pFileData,
            a3: Size,
            a4: v5,
            a5: v3);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
          v8 = &pFileData[v5];
          *v8 = 0;
          v9 = (const char *)v7;
          CharacterSetBuild(pSetBuffer: &whitespace, pszSetString: "\n\r\t ");
          pName = nullptr;
          if ( v7 < v8 )
          {
            do
            {
              v10 = *v9;
              for ( i = nullptr; v9 < (const char *)v8; v10 = *++v9 )
              {
                if ( whitespace.set[v10] == 0 )
                  break;
              }
              if ( *v9 == 0 )
                break;
              if ( *v9 != 47 )
              {
                v12 = &g_Sentences.m_Memory.m_pMemory[CUtlVector<sentence_t,CUtlMemory<sentence_t,int>>::InsertBefore(
                                                        this: &g_Sentences,
                                                        elem: g_Sentences.m_Size)];
                v12->pName = (char *)v9;
                v12->length = 0.0;
                *((_BYTE *)v12 + 8) = 0;
                v12->caption.m_Id = -1;
                v13 = *v9;
                pName = v9;
                if ( v9 < (const char *)v8 )
                {
                  while ( v13 != 32 )
                  {
                    v13 = *++v9;
                    if ( v9 >= (const char *)v8 )
                      goto LABEL_23;
                  }
                  if ( v9 < (const char *)v8 )
                    *v9++ = 0;
                }
LABEL_23:
                i = (char *)v9;
              }
              if ( v9 < (const char *)v8 )
              {
                while ( *v9 != 10 && *v9 != 13 )
                {
                  if ( ++v9 >= (const char *)v8 )
                    goto LABEL_31;
                }
                if ( v9 < (const char *)v8 )
                  *v9++ = 0;
              }
LABEL_31:
              if ( i != nullptr && i < (char *)v8 )
              {
                VOX_GroupAdd(pSentenceName: pName);
                VOX_ParseLineCommands(pSentenceData: i, sentenceIndex: g_Sentences.m_Size - 1);
              }
            }
            while ( v9 < (const char *)v8 );
            v7 = pFileData;
          }
          VOX_CompactSentenceFile();
          g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: v7);
          VOX_GroupInitAllLRUs();
          VOX_AddSentenceWavesToResList();
          VOX_ListMarkFileLoaded(psentenceFileName);
        }
        else
        {
          DevMsg(a1: "VOX_ReadSentenceFile: %s couldn't allocate %i bytes for data\n", psentenceFileName, v5);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
        }
      }
      else
      {
        DevMsg(a1: "VOX_ReadSentenceFile: %s has invalid size %i\n", psentenceFileName, v4);
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
      }
    }
    else
    {
      DevMsg(a1: "Couldn't load %s\n", psentenceFileName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C980
// Name: _VOX_Init
// Source: json
//------------------------------------------------------------------------------
void __usercall VOX_Init(int a1@<ebx>)
{
  char *m_pMemory; // eax
  unsigned __int8 *v2; // eax
  IMemAlloc_vtbl *v3; // edx
  sentence_t *v4; // eax

  g_entnamelastsaved = 0;
  _V_memset(dest: g_entnames, fill: 0, count: 6656);
  _V_memset(dest: g_rgmapnames, fill: 0, count: 96);
  m_pMemory = g_SentenceFile.m_Memory.m_pMemory;
  g_cmapnames = 0;
  g_SentenceFile.m_Size = 0;
  if ( g_SentenceFile.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SentenceFile.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SentenceFile.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_SentenceFile.m_Memory.m_pMemory = nullptr;
    }
    g_SentenceFile.m_Memory.m_nAllocationCount = 0;
  }
  g_SentenceFile.m_pElements = m_pMemory;
  v2 = g_GroupLRU.m_Memory.m_pMemory;
  g_GroupLRU.m_Size = 0;
  if ( g_GroupLRU.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_GroupLRU.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_GroupLRU.m_Memory.m_pMemory);
      v2 = nullptr;
      g_GroupLRU.m_Memory.m_pMemory = nullptr;
    }
    g_GroupLRU.m_Memory.m_nAllocationCount = 0;
  }
  g_GroupLRU.m_pElements = v2;
  g_Sentences.m_Size = 0;
  if ( g_Sentences.m_Memory.m_nAllocationCount < 900 && g_Sentences.m_Memory.m_nGrowSize >= 0 )
  {
    g_Sentences.m_Memory.m_nAllocationCount = 900;
    v3 = _g_pMemAlloc->__vftable;
    if ( g_Sentences.m_Memory.m_pMemory != nullptr )
      v4 = (sentence_t *)((int (__stdcall *)(sentence_t *, int))v3->Realloc_2)(
                           a1: g_Sentences.m_Memory.m_pMemory,
                           a2: 10800);
    else
      v4 = (sentence_t *)((int (__stdcall *)(int))v3->Alloc_2)(a1: 10800);
    g_Sentences.m_Memory.m_pMemory = v4;
  }
  g_Sentences.m_pElements = g_Sentences.m_Memory.m_pMemory;
  VOX_ListClear();
  VOX_ReadSentenceFile(a1, psentenceFileName: "scripts/sentences.txt");
  VOX_LookupMapnames();
}

//------------------------------------------------------------------------------
// Address: 0x1005CA90
// Name: VOX_Reload
// Source: json
//------------------------------------------------------------------------------
void __usercall VOX_Reload(int a1@<ebx>)
{
  g_Sentences.m_Size = 0;
  VOX_ListClear();
  g_SentenceGroups.m_Size = 0;
  g_cmapnames = 0;
  VOX_Init(a1);
}

} // namespace engine_xlsp
