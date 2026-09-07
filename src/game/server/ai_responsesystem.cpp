// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_responsesystem.cpp
// Functions: 32
// ============================================================

#include "game\server\ai_responsesystem.h"

//------------------------------------------------------------------------------
// Address: 0x1007DCE0
// Name: public: virtual void CGameResponseSystem::PrecacheResponses(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameResponseSystem::PrecacheResponses(CGameResponseSystem *this, bool bEnable)
{
  this->m_bPrecache = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1007DCF0
// Name: class ISaveRestoreBlockHandler __near * GetDefaultResponseSystemSaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CDefaultResponseSystemSaveRestoreBlockHandler *__cdecl GetDefaultResponseSystemSaveRestoreBlockHandler()
{
  return &g_DefaultResponseSystemSaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x1007DD00
// Name: public: virtual bool CDefaultResponseSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDefaultResponseSystem::Init(CDefaultResponseSystem *this)
{
  ResponseRules::CResponseSystem *v1; // esi
  const char *v2; // eax

  v1 = (CDefaultResponseSystem *)((char *)this - 15852);
  v2 = (const char *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 3963) + 24))(a1: (char *)this - 15852);
  ResponseRules::CResponseSystem::LoadRuleSet(this: v1, basescript: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007DD20
// Name: char const __near * RR_Parse(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl RR_Parse(char *data, char *token)
{
  char *result; // eax
  int v3; // edi
  unsigned __int8 i; // cl
  char v5; // cl
  int v6; // esi

  result = data;
  v3 = 0;
  *token = 0;
  if ( data != nullptr )
  {
    i = *data;
    while ( i > 0x20u )
    {
LABEL_7:
      if ( i != 47 )
      {
        if ( i == 34 )
        {
          ++result;
          while ( 1 )
          {
            v5 = *result;
            if ( (unsigned __int8)(*result - 65) <= 0x19u )
              v5 += 32;
            ++result;
            if ( v5 == 34 || v5 == 0 )
              break;
            token[v3++] = v5;
          }
        }
        else
        {
LABEL_20:
          if ( g_BreakSetIncludingColons.set[i] != 0 )
          {
            *token = i;
            token[1] = 0;
            return ++result;
          }
          v6 = token - result;
          do
          {
            if ( (unsigned __int8)(i - 65) <= 0x19u )
              i += 32;
            result[v6] = i;
            i = *++result;
            ++v3;
            if ( (unsigned __int8)(i - 65) <= 0x19u )
              i += 32;
          }
          while ( g_BreakSetIncludingColons.set[i] == 0 && i > 0x20u );
        }
        token[v3] = 0;
        return result;
      }
      if ( result[1] != 47 )
        goto LABEL_20;
      for ( i = *result; i != 0; i = *++result )
      {
        if ( i == 10 )
          break;
      }
    }
    while ( i != 0 )
    {
      i = *++result;
      if ( i > 0x20u )
        goto LABEL_7;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007DDF0
// Name: private: virtual char const __near * CResponseRulesToEngineInterface::ParseFile(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CResponseRulesToEngineInterface::ParseFile(
        CResponseRulesToEngineInterface *this,
        char *data,
        char *token,
        int maxlen)
{
  return RR_Parse(data, token);
}

//------------------------------------------------------------------------------
// Address: 0x1007DE10
// Name: private: virtual class IFileSystem __near * CResponseRulesToEngineInterface::GetFilesystem(void)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__thiscall CResponseRulesToEngineInterface::GetFilesystem(CResponseRulesToEngineInterface *this)
{
  return filesystem;
}

//------------------------------------------------------------------------------
// Address: 0x1007DE20
// Name: private: virtual class IUniformRandomStream __near * CResponseRulesToEngineInterface::GetRandomStream(void)
// Source: json
//------------------------------------------------------------------------------
IUniformRandomStream *__thiscall CResponseRulesToEngineInterface::GetRandomStream(
        CResponseRulesToEngineInterface *this)
{
  return random;
}

//------------------------------------------------------------------------------
// Address: 0x1007DE30
// Name: private: virtual class ICommandLine __near * CResponseRulesToEngineInterface::GetCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
ICommandLine *__thiscall CResponseRulesToEngineInterface::GetCommandLine(CResponseRulesToEngineInterface *this)
{
  return _CommandLine(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007DE40
// Name: private: virtual unsigned char __near * CResponseRulesToEngineInterface::LoadFileForMe(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CResponseRulesToEngineInterface::LoadFileForMe(
        CResponseRulesToEngineInterface *this,
        const char *filename,
        int *pLength)
{
  return UTIL_LoadFileForMe(filename, pLength);
}

//------------------------------------------------------------------------------
// Address: 0x1007DE60
// Name: private: virtual void CResponseRulesToEngineInterface::FreeFile(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseRulesToEngineInterface::FreeFile(
        CResponseRulesToEngineInterface *this,
        unsigned __int8 *buffer)
{
  UTIL_FreeFile(buffer);
}

//------------------------------------------------------------------------------
// Address: 0x1007DF10
// Name: public: virtual char const __near * CDefaultResponseSystemSaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDefaultResponseSystemSaveRestoreBlockHandler::GetBlockName(
        CDefaultResponseSystemSaveRestoreBlockHandler *this)
{
  return "ResponseSystem";
}

//------------------------------------------------------------------------------
// Address: 0x1007DF20
// Name: public: virtual void CDefaultResponseSystemSaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultResponseSystemSaveRestoreBlockHandler::WriteSaveHeaders(
        CDefaultResponseSystemSaveRestoreBlockHandler *this,
        ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &RESPONSESYSTEM_SAVE_RESTORE_VERSION, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1007DF40
// Name: public: virtual void CDefaultResponseSystemSaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultResponseSystemSaveRestoreBlockHandler::ReadRestoreHeaders(
        CDefaultResponseSystemSaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  pRestore->ReadShort(this: pRestore, a2: (__int16 *)&pRestore, a3: 1, a4: 0);
  this->m_fDoLoad = (_WORD)pRestore == (unsigned __int16)RESPONSESYSTEM_SAVE_RESTORE_VERSION;
}

//------------------------------------------------------------------------------
// Address: 0x1007F450
// Name: public: virtual void CGameResponseSystem::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameResponseSystem::Precache(CGameResponseSystem *this)
{
  CGameResponseSystem *v1; // esi
  ICommandLine *v2; // eax
  int v3; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short> *m_pMemory; // edx
  int v5; // ebx
  ResponseRules::ResponseGroup *p_elem; // edi
  ResponseRules::ParserResponse *v7; // eax
  int v8; // eax
  const char *v9; // esi
  ResponseRules::IEngineEmulator *v10; // eax
  int v11; // eax
  ResponseRules::IEngineEmulator *v12; // eax
  int v13; // eax
  ResponseRules::IEngineEmulator *v14; // eax
  int v15; // eax
  int m_NumElements; // edx
  char file[260]; // [esp+4h] [ebp-218h] BYREF
  char genderFile[260]; // [esp+108h] [ebp-114h] BYREF
  CGameResponseSystem *v19; // [esp+20Ch] [ebp-10h]
  int j; // [esp+210h] [ebp-Ch]
  int i; // [esp+214h] [ebp-8h]
  bool bTouchFiles; // [esp+21Bh] [ebp-1h]

  v1 = this;
  v19 = this;
  v2 = _CommandLine((CResponseRulesToEngineInterface *)this);
  bTouchFiles = v2->FindParm(this: v2, a2: "-makereslists") != 0;
  v3 = 0;
  i = 0;
  if ( v1->m_Responses.m_Elements.m_Tree.m_NumElements > 0 )
  {
    do
    {
      m_pMemory = v1->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory;
      v5 = 0;
      p_elem = &m_pMemory[(__int16)v3].m_Data.elem;
      j = 0;
      if ( m_pMemory[(__int16)v3].m_Data.elem.group.m_Size > 0 )
      {
        do
        {
          v7 = p_elem->group.m_Memory.m_pMemory;
          if ( (*((_BYTE *)&p_elem->group.m_Memory.m_pMemory[v5] + 32) & 0x3F) == 1 )
          {
            CBaseEntity::PrecacheScriptSound(soundname: v7[v5].value);
          }
          else if ( (*((_BYTE *)&p_elem->group.m_Memory.m_pMemory[v5] + 32) & 0x3F) == 3 )
          {
            V_strncpy(pDest: file, pSrc: v7[v5].value, maxLen: 260);
            strstr(str1: (unsigned __int8 *)file, str2: "$gender");
            if ( v8 != 0 )
            {
              v9 = (const char *)(v8 + 7);
              *(_BYTE *)v8 = 0;
              V_snprintf(pDest: genderFile, maxLen: 260, pFormat: "%smale%s", file, (const char *)(v8 + 7));
              PrecacheInstancedScene(pszScene: genderFile);
              if ( bTouchFiles )
              {
                v10 = ResponseRules::IEngineEmulator::Get();
                v11 = (int)v10->GetFilesystem(this: v10);
                (*(void (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)(v11 + 4) + 24))(
                  a1: v11 + 4,
                  a2: genderFile,
                  a3: 0);
              }
              V_snprintf(pDest: genderFile, maxLen: 260, pFormat: "%sfemale%s", file, v9);
              PrecacheInstancedScene(pszScene: genderFile);
              if ( bTouchFiles )
              {
                v12 = ResponseRules::IEngineEmulator::Get();
                v13 = (int)v12->GetFilesystem(this: v12);
                (*(void (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)(v13 + 4) + 24))(
                  a1: v13 + 4,
                  a2: genderFile,
                  a3: 0);
              }
            }
            else
            {
              PrecacheInstancedScene(pszScene: file);
              if ( bTouchFiles )
              {
                v14 = ResponseRules::IEngineEmulator::Get();
                v15 = (int)v14->GetFilesystem(this: v14);
                (*(void (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)(v15 + 4) + 24))(a1: v15 + 4, a2: file, a3: 0);
              }
            }
          }
          ++v5;
          ++j;
        }
        while ( j < p_elem->group.m_Size );
        v1 = v19;
        v3 = i;
      }
      m_NumElements = v1->m_Responses.m_Elements.m_Tree.m_NumElements;
      i = ++v3;
    }
    while ( v3 < m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F630
// Name: public: virtual void CDefaultResponseSystemSaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultResponseSystemSaveRestoreBlockHandler::Save(
        CDefaultResponseSystemSaveRestoreBlockHandler *this,
        ISave *pSave)
{
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  int v4; // edi
  unsigned __int16 *p_elem; // ebx
  void (__thiscall *WriteShort_2)(ISave *, const __int16 *, int); // edx
  char *v7; // edi
  int j; // [esp+4h] [ebp-10h]
  int count; // [esp+8h] [ebp-Ch] BYREF
  int i; // [esp+Ch] [ebp-8h]
  int groupCount; // [esp+10h] [ebp-4h] BYREF
  ISave *pSavea; // [esp+1Ch] [ebp+8h]

  WriteInt_2 = pSave->WriteInt_2;
  count = defaultresponsesytem.m_Responses.m_Elements.m_Tree.m_NumElements;
  WriteInt_2(this: pSave, a2: &count, a3: 1);
  for ( i = 0; i < count; ++i )
  {
    pSave->StartBlock_2(this: pSave, a2: "ResponseGroup");
    v4 = (__int16)i;
    pSave->WriteString_4(
      this: pSave,
      a2: defaultresponsesytem.m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.key);
    p_elem = (unsigned __int16 *)&defaultresponsesytem.m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
    pSave->WriteAll(this: pSave, a2: p_elem, a3: &ResponseRules::ResponseGroup::m_DataMap);
    WriteShort_2 = pSave->WriteShort_2;
    groupCount = p_elem[6];
    WriteShort_2(this: pSave, a2: (const __int16 *)&groupCount, a3: 1);
    j = 0;
    if ( (__int16)groupCount > 0 )
    {
      pSavea = nullptr;
      do
      {
        v7 = (char *)pSavea + *(_DWORD *)p_elem;
        pSave->StartBlock_2(this: pSave, a2: "Response");
        pSave->WriteString_4(this: pSave, a2: *(const char **)(v7 + 25));
        pSave->WriteAll(this: pSave, a2: v7, a3: &ResponseRules::ParserResponse::m_DataMap);
        pSave->EndBlock(this: pSave);
        pSavea += 24;
        ++j;
      }
      while ( j < (__int16)groupCount );
    }
    pSave->EndBlock(this: pSave);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F740
// Name: public: virtual void CResponseSystemSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseSystemSaveRestoreOps::Save(
        CResponseSystemSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CDefaultResponseSystem *v3; // ebx
  ISave *v4; // esi
  ISave_vtbl *v5; // eax
  int v6; // edi
  int p_elem; // ebx
  void (__thiscall *WriteShort_2)(ISave *, const __int16 *, int); // edx
  char *v9; // edi
  ResponseRules::CResponseSystem *pRS; // [esp+4h] [ebp-10h]
  int j; // [esp+8h] [ebp-Ch]
  int count; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+10h] [ebp-4h]
  const SaveRestoreFieldInfo_t *fieldInfoa; // [esp+1Ch] [ebp+8h]

  v3 = *(CDefaultResponseSystem **)fieldInfo->pField;
  pRS = v3;
  if ( v3 != nullptr && v3 != &defaultresponsesytem )
  {
    v4 = pSave;
    v5 = pSave->__vftable;
    count = v3->m_Responses.m_Elements.m_Tree.m_NumElements;
    v5->WriteInt_2(this: pSave, a2: &count, a3: 1);
    i = 0;
    if ( count > 0 )
    {
      while ( 1 )
      {
        v4->StartBlock_2(this: v4, a2: "ResponseGroup");
        v6 = (__int16)i;
        v4->WriteString_4(this: v4, a2: v3->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.key);
        p_elem = (int)&v3->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
        v4->WriteAll(this: v4, a2: (const void *)p_elem, a3: &ResponseRules::ResponseGroup::m_DataMap);
        WriteShort_2 = v4->WriteShort_2;
        pSave = (ISave *)*(unsigned __int16 *)(p_elem + 12);
        WriteShort_2(this: v4, a2: (const __int16 *)&pSave, a3: 1);
        j = 0;
        if ( (__int16)pSave > 0 )
        {
          fieldInfoa = nullptr;
          do
          {
            v9 = (char *)fieldInfoa + *(_DWORD *)p_elem;
            v4->StartBlock_2(this: v4, a2: "Response");
            v4->WriteString_4(this: v4, a2: *(const char **)(v9 + 25));
            v4->WriteAll(this: v4, a2: v9, a3: &ResponseRules::ParserResponse::m_DataMap);
            v4->EndBlock(this: v4);
            fieldInfoa += 8;
            ++j;
          }
          while ( j < (__int16)pSave );
        }
        v4->EndBlock(this: v4);
        if ( ++i >= count )
          break;
        v3 = (CDefaultResponseSystem *)pRS;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FCE0
// Name: private: void CDefaultResponseSystem::ClearInstanced(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultResponseSystem::ClearInstanced(CDefaultResponseSystem *this)
{
  int v2; // esi
  int v3; // edi
  CInstancedResponseSystem *elem; // ecx
  CUtlDict<CInstancedResponseSystem *,int> *p_m_InstancedSystems; // edi
  int i; // esi

  v2 = this->m_InstancedSystems.m_Elements.m_Tree.m_NumElements - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      elem = this->m_InstancedSystems.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
      elem->Release(this: elem);
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
  p_m_InstancedSystems = &this->m_InstancedSystems;
  for ( i = CUtlRBTree<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int,CUtlMap<char const *,CInstancedResponseSystem *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_InstancedSystems.m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int,CUtlMap<char const *,CInstancedResponseSystem *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int>,int>>::NextInorder(
              this: &p_m_InstancedSystems->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_InstancedSystems.m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int,CUtlMap<char const *,CInstancedResponseSystem *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int>,int>>::RemoveAll(this: &p_m_InstancedSystems->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1007FD70
// Name: public: virtual void CDefaultResponseSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultResponseSystem::Shutdown(CDefaultResponseSystem *this)
{
  ResponseRules::CResponseSystem *v1; // esi

  v1 = (CDefaultResponseSystem *)((char *)this - 15852);
  CDefaultResponseSystem::ClearInstanced(this: (CDefaultResponseSystem *)((char *)this - 15852));
  ResponseRules::CResponseSystem::Clear(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1007FD90
// Name: public: CDefaultResponseSystem::CDefaultResponseSystem(void)
// Source: json
//------------------------------------------------------------------------------
CDefaultResponseSystem *__thiscall CDefaultResponseSystem::CDefaultResponseSystem(CDefaultResponseSystem *this)
{
  bool v2; // zf
  CDefaultResponseSystem *result; // eax

  ResponseRules::CResponseSystem::CResponseSystem(this);
  this->CGameResponseSystem::ResponseRules::CResponseSystem::ResponseRules::IResponseSystem::__vftable = (CDefaultResponseSystem_vtbl *)&CGameResponseSystem::`vftable';
  this->m_bPrecache = true;
  CAutoGameSystem::CAutoGameSystem(this: &this->CAutoGameSystem, name: "CDefaultResponseSystem");
  this->CGameResponseSystem::ResponseRules::CResponseSystem::ResponseRules::IResponseSystem::__vftable = (CDefaultResponseSystem_vtbl *)&CDefaultResponseSystem::`vftable'{for `CGameResponseSystem'};
  this->CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CAutoGameSystem_vtbl *)&CDefaultResponseSystem::`vftable'{for `CAutoGameSystem'};
  this->m_InstancedSystems.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_InstancedSystems.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_InstancedSystems.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_InstancedSystems.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_InstancedSystems.m_Elements.m_Tree.m_Root = -1;
  this->m_InstancedSystems.m_Elements.m_Tree.m_NumElements = 0;
  this->m_InstancedSystems.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_InstancedSystems.m_Elements.m_Tree.m_LastAlloc.index = -1;
  v2 = this->m_InstancedSystems.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr;
  this->m_InstancedSystems.m_Elements.m_Tree.m_pElements = this->m_InstancedSystems.m_Elements.m_Tree.m_Elements.m_pMemory;
  result = this;
  if ( v2 )
    this->m_InstancedSystems.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007FE20
// Name: public: virtual char const __near * CDefaultResponseSystem::GetScriptFile(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDefaultResponseSystem::GetScriptFile(CDefaultResponseSystem *this)
{
  return "scripts/talker/response_rules.txt";
}

//------------------------------------------------------------------------------
// Address: 0x1007FE30
// Name: public: virtual void CDefaultResponseSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultResponseSystem::LevelInitPreEntity(CDefaultResponseSystem *this)
{
  if ( *((_BYTE *)this - 4) != 0 )
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 3963) + 28))(a1: (char *)this - 15852);
  ResponseRules::CResponseSystem::ResetResponseGroups(this: (CDefaultResponseSystem *)((char *)this - 15852));
}

//------------------------------------------------------------------------------
// Address: 0x1007FE70
// Name: public: short CUtlDict<struct ResponseRules::ResponseGroup,short>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CUtlDict<ResponseRules::ResponseGroup,short>::Find(
        CUtlDict<ResponseRules::ResponseGroup,short> *this,
        const char *pName)
{
  __int16 v2; // si
  CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t search; // [esp+8h] [ebp-1Ch] BYREF

  if ( pName == nullptr )
    return -1;
  *((_BYTE *)&search.elem + 23) = *((_BYTE *)&search.elem + 23) & 0xE0 | 1;
  memset(&search.elem, 0, 20);
  *(_WORD *)&search.elem.m_bEnabled = 1;
  search.elem.m_nDepletionCount = 1;
  search.key = pName;
  v2 = CUtlRBTree<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short,CUtlMap<char const *,ResponseRules::ResponseGroup,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  CUtlVector<ResponseRules::ParserResponse,CUtlMemory<ResponseRules::ParserResponse,int>>::Purge(this: &search.elem.group);
  if ( search.elem.group.m_Memory.m_nGrowSize >= 0 && search.elem.group.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.group.m_Memory.m_pMemory);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1007FEF0
// Name: public: void CDefaultResponseSystem::ReloadAllResponseSystems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultResponseSystem::ReloadAllResponseSystems(CDefaultResponseSystem *this)
{
  CDefaultResponseSystem *v1; // esi
  int v2; // edi
  int v3; // ebx
  UtlRBTreeNode_t<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int> *m_pMemory; // eax
  CInstancedResponseSystem *sys; // [esp+8h] [ebp-8h]

  v1 = this;
  ResponseRules::CResponseSystem::Clear(this);
  v1->Init(this: &v1->CAutoGameSystem);
  v2 = v1->m_InstancedSystems.m_Elements.m_Tree.m_NumElements - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      m_pMemory = v1->m_InstancedSystems.m_Elements.m_Tree.m_Elements.m_pMemory;
      sys = m_pMemory[v3].m_Data.elem;
      if ( v1->m_bCustomManagable )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory[v3].m_Data.key);
        CUtlRBTree<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int,CUtlMap<char const *,CInstancedResponseSystem *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CInstancedResponseSystem *,int>::Node_t,int>,int>>::Unlink(
          this: &v1->m_InstancedSystems.m_Elements.m_Tree,
          elem: v2);
        v1->m_InstancedSystems.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Left = v2;
        v1->m_InstancedSystems.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Right = v1->m_InstancedSystems.m_Elements.m_Tree.m_FirstFree;
        --v1->m_InstancedSystems.m_Elements.m_Tree.m_NumElements;
        v1->m_InstancedSystems.m_Elements.m_Tree.m_FirstFree = v2;
        v1 = this;
      }
      else
      {
        ResponseRules::CResponseSystem::Clear(this: m_pMemory[v3].m_Data.elem);
        sys->Init(this: sys);
      }
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
  v1->Precache(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10080010
// Name: rr_reloadresponsesystems
// Source: json
//------------------------------------------------------------------------------
void __cdecl rr_reloadresponsesystems()
{
  CDefaultResponseSystem::ReloadAllResponseSystems(this: &defaultresponsesytem);
}

//------------------------------------------------------------------------------
// Address: 0x10080020
// Name: public: virtual void CDefaultResponseSystemSaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultResponseSystemSaveRestoreBlockHandler::Restore(
        CDefaultResponseSystemSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        bool createPlayers)
{
  int v4; // eax
  __int16 v5; // ax
  ResponseRules::ResponseGroup *p_elem; // edi
  __int16 v7; // ax
  int v8; // ebx
  char responsename[256]; // [esp+0h] [ebp-248h] BYREF
  char groupname[256]; // [esp+100h] [ebp-148h] BYREF
  char szResponseBlockName[32]; // [esp+200h] [ebp-48h] BYREF
  char szResponseGroupBlockName[32]; // [esp+220h] [ebp-28h] BYREF
  int i; // [esp+240h] [ebp-8h]
  int j; // [esp+244h] [ebp-4h]
  IRestore *pRestorea; // [esp+250h] [ebp+8h]

  if ( this->m_fDoLoad )
  {
    v4 = pRestore->ReadInt(this: pRestore);
    if ( v4 > 0 )
    {
      for ( i = v4; i != 0; --i )
      {
        pRestore->StartBlock_2(this: pRestore, a2: szResponseGroupBlockName);
        if ( _V_stricmp(s1: szResponseGroupBlockName, s2: "ResponseGroup") == 0 )
        {
          pRestore->ReadString_2(this: pRestore, a2: groupname, a3: 256, a4: 0);
          v5 = CUtlDict<ResponseRules::ResponseGroup,short>::Find(
                 this: &defaultresponsesytem.m_Responses,
                 pName: groupname);
          if ( v5 != -1 )
          {
            p_elem = &defaultresponsesytem.m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
            pRestore->ReadAll(this: pRestore, a2: p_elem, a3: &ResponseRules::ResponseGroup::m_DataMap);
            v7 = pRestore->ReadShort_2(this: pRestore);
            if ( v7 > 0 )
            {
              for ( j = v7; j != 0; --j )
              {
                pRestore->StartBlock_2(this: pRestore, a2: szResponseBlockName);
                if ( _V_stricmp(s1: szResponseBlockName, s2: "Response") == 0 )
                {
                  pRestore->ReadString_2(this: pRestore, a2: responsename, a3: 256, a4: 0);
                  v8 = 0;
                  if ( p_elem->group.m_Size > 0 )
                  {
                    pRestorea = nullptr;
                    do
                    {
                      if ( _V_stricmp(
                             s1: *(const char **)((char *)&pRestorea[6].__vftable
                                            + (unsigned int)p_elem->group.m_Memory.m_pMemory
                                            + 1),
                             s2: responsename) == 0 )
                        break;
                      pRestorea += 24;
                      ++v8;
                    }
                    while ( v8 < p_elem->group.m_Size );
                    if ( v8 < p_elem->group.m_Size )
                      pRestore->ReadAll(
                        this: pRestore,
                        a2: &p_elem->group.m_Memory.m_pMemory[v8],
                        a3: &ResponseRules::ParserResponse::m_DataMap);
                  }
                }
                pRestore->EndBlock(this: pRestore);
              }
            }
          }
        }
        pRestore->EndBlock(this: pRestore);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100801A0
// Name: public: virtual void CResponseSystemSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseSystemSaveRestoreOps::Restore(
        CResponseSystemSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CDefaultResponseSystem *v3; // ebx
  int v5; // eax
  __int16 v6; // ax
  ResponseRules::ResponseGroup *p_elem; // edi
  __int16 v8; // ax
  int v9; // ebx
  char responsename[256]; // [esp+4h] [ebp-248h] BYREF
  char groupname[256]; // [esp+104h] [ebp-148h] BYREF
  char szResponseBlockName[32]; // [esp+204h] [ebp-48h] BYREF
  char szResponseGroupBlockName[32]; // [esp+224h] [ebp-28h] BYREF
  ResponseRules::CResponseSystem *pRS; // [esp+244h] [ebp-8h]
  int i; // [esp+248h] [ebp-4h]
  const SaveRestoreFieldInfo_t *fieldInfoa; // [esp+254h] [ebp+8h]
  IRestore *pRestorea; // [esp+258h] [ebp+Ch]

  v3 = *(CDefaultResponseSystem **)fieldInfo->pField;
  pRS = v3;
  if ( v3 != nullptr && v3 != &defaultresponsesytem )
  {
    v5 = pRestore->ReadInt(this: pRestore);
    if ( v5 > 0 )
    {
      for ( i = v5; i != 0; --i )
      {
        pRestore->StartBlock_2(this: pRestore, a2: szResponseGroupBlockName);
        if ( _V_stricmp(s1: szResponseGroupBlockName, s2: "ResponseGroup") == 0 )
        {
          pRestore->ReadString_2(this: pRestore, a2: groupname, a3: 256, a4: 0);
          v6 = CUtlDict<ResponseRules::ResponseGroup,short>::Find(this: &v3->m_Responses, pName: groupname);
          if ( v6 != -1 )
          {
            p_elem = &v3->m_Responses.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
            pRestore->ReadAll(this: pRestore, a2: p_elem, a3: &ResponseRules::ResponseGroup::m_DataMap);
            v8 = pRestore->ReadShort_2(this: pRestore);
            if ( v8 > 0 )
            {
              for ( pRestorea = (IRestore *)v8; pRestorea != nullptr; pRestorea = (IRestore *)((char *)pRestorea - 1) )
              {
                pRestore->StartBlock_2(this: pRestore, a2: szResponseBlockName);
                if ( _V_stricmp(s1: szResponseBlockName, s2: "Response") == 0 )
                {
                  pRestore->ReadString_2(this: pRestore, a2: responsename, a3: 256, a4: 0);
                  v9 = 0;
                  if ( p_elem->group.m_Size > 0 )
                  {
                    fieldInfoa = nullptr;
                    do
                    {
                      if ( _V_stricmp(
                             s1: *(const char **)((char *)&fieldInfoa[2].pField
                                            + (unsigned int)p_elem->group.m_Memory.m_pMemory
                                            + 1),
                             s2: responsename) == 0 )
                        break;
                      fieldInfoa += 8;
                      ++v9;
                    }
                    while ( v9 < p_elem->group.m_Size );
                    if ( v9 < p_elem->group.m_Size )
                      pRestore->ReadAll(
                        this: pRestore,
                        a2: &p_elem->group.m_Memory.m_pMemory[v9],
                        a3: &ResponseRules::ParserResponse::m_DataMap);
                  }
                }
                pRestore->EndBlock(this: pRestore);
              }
              v3 = (CDefaultResponseSystem *)pRS;
            }
          }
        }
        pRestore->EndBlock(this: pRestore);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036FB20
// Name: public: void CUtlDict<struct ResponseRules::ResponseGroup,short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<ResponseRules::ResponseGroup,short>::RemoveAll(
        CUtlDict<ResponseRules::ResponseGroup,short> *this)
{
  __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short,CUtlMap<char const *,ResponseRules::ResponseGroup,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short,CUtlMap<char const *,ResponseRules::ResponseGroup,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short,CUtlMap<char const *,ResponseRules::ResponseGroup,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1036FBA0
// Name: public: short CUtlDict<struct ResponseRules::ResponseGroup,short>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CUtlDict<ResponseRules::ResponseGroup,short>::Insert(
        CUtlDict<ResponseRules::ResponseGroup,short> *this,
        const char *pName)
{
  char *v2; // eax
  const char *v3; // ecx
  __int16 v4; // si
  CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t insert; // [esp+Ch] [ebp-20h] BYREF
  CUtlRBTree<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short,CUtlMap<char const *,ResponseRules::ResponseGroup,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short> > *p_m_Tree; // [esp+28h] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v2, pName);
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  insert.key = v3;
  memset(&insert.elem, 0, 20);
  *(_WORD *)&insert.elem.m_bEnabled = 1;
  insert.elem.m_nDepletionCount = 1;
  *((_BYTE *)&insert.elem + 23) = *((_BYTE *)&insert.elem + 23) & 0xE0 | 1;
  v4 = CUtlRBTree<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short,CUtlMap<char const *,ResponseRules::ResponseGroup,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short>>::Insert(
         this: p_m_Tree,
         a2: pName,
         &insert);
  CUtlVector<ResponseRules::ParserResponse,CUtlMemory<ResponseRules::ParserResponse,int>>::Purge(this: &insert.elem.group);
  if ( insert.elem.group.m_Memory.m_nGrowSize >= 0 && insert.elem.group.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: insert.elem.group.m_Memory.m_pMemory);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103FEAC0
// Name: ParserResponse_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *ParserResponse_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ResponseRules::ParserResponse>();
  ParserResponse_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEAD0
// Name: ResponseGroup_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *ResponseGroup_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ResponseRules::ResponseGroup>();
  ResponseGroup_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEAE0
// Name: _dynamic_initializer_for__defaultresponsesytem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__defaultresponsesytem__()
{
  CDefaultResponseSystem::CDefaultResponseSystem(this: &defaultresponsesytem);
  return atexit(func: dynamic_atexit_destructor_for__defaultresponsesytem__);
}

//------------------------------------------------------------------------------
// Address: 0x103FEB00
// Name: _dynamic_initializer_for__rr_reloadresponsesystems_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_reloadresponsesystems_command__()
{
  ConCommand::ConCommand(
    this: &rr_reloadresponsesystems_command,
    pName: "rr_reloadresponsesystems",
    callback: (void (__cdecl *)(const CCommand *))rr_reloadresponsesystems,
    pHelpString: "Reload all response system scripts.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rr_reloadresponsesystems_command__);
}
