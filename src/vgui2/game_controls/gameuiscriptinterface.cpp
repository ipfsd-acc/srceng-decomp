// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gameuiscriptinterface.cpp
// Functions: 18
// ============================================================

#include "vgui2\game_controls\gameuiscriptinterface.h"

//------------------------------------------------------------------------------
// Address: 0x00428CE0
// Name: public: static bool CGameUIScriptInterface::ScriptVmKeyValueToVariant(class IScriptVM __near *,class KeyValues __near *,struct ScriptVariant_t __near &,char __near * const)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CGameUIScriptInterface::ScriptVmKeyValueToVariant(
        IScriptVM *pVM,
        KeyValues *val,
        ScriptVariant_t *varValue,
        char *chScratchBuffer)
{
  bool result; // al
  unsigned __int64 Uint64; // rax
  const char *Name; // eax
  KeyValues::types_t defaultValue; // [esp+0h] [ebp-8h]

  switch ( KeyValues::GetDataType(this: val, keyName: nullptr) )
  {
    case 0:
      varValue->m_int = (int)CGameUIScriptInterface::ScriptTableFromKeyValues(pVM, kv: val);
      varValue->m_type = 33;
      result = true;
      break;
    case 1:
      varValue->m_int = (int)KeyValues::GetString(this: val, keyName: nullptr, defaultValue: ::defaultValue);
      varValue->m_type = 32;
      result = true;
      break;
    case 2:
      varValue->m_int = KeyValues::GetInt(this: val, keyName: nullptr, defaultValue: 0);
      varValue->m_type = 5;
      result = true;
      break;
    case 3:
      varValue->m_float = KeyValues::GetFloat(this: val, keyName: nullptr, defaultValue: 0.0);
      varValue->m_type = 1;
      result = true;
      break;
    case 7:
      Uint64 = KeyValues::GetUint64(this: val, keyName: nullptr, defaultValue: 0);
      V_snprintf(pDest: chScratchBuffer, maxLen: 128, pFormat: "%llu", Uint64);
      varValue->m_int = (int)chScratchBuffer;
      varValue->m_type = 32;
      result = true;
      break;
    default:
      defaultValue = KeyValues::GetDataType(this: val, keyName: nullptr);
      Name = KeyValues::GetName(this: val);
      _Warning(a1: "ScriptVmKeyValueToVariant failed to package parameter %s (type %d)\n", Name, defaultValue);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428DF0
// Name: public: static bool CGameUIScriptInterface::ScriptVmStringFromVariant(struct ScriptVariant_t __near &,char __near * const)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CGameUIScriptInterface::ScriptVmStringFromVariant(ScriptVariant_t *varValue, char *chScratchBuffer)
{
  bool result; // al
  const char *m_int; // eax

  switch ( varValue->m_type )
  {
    case 1:
      V_snprintf(pDest: chScratchBuffer, maxLen: 128, pFormat: "%f", varValue->m_float);
      result = true;
      break;
    case 5:
      V_snprintf(pDest: chScratchBuffer, maxLen: 128, pFormat: "%d", varValue->m_int);
      result = true;
      break;
    case 6:
      V_snprintf(pDest: chScratchBuffer, maxLen: 128, pFormat: "%d", (unsigned __int8)varValue->m_char);
      result = true;
      break;
    case 8:
      V_snprintf(pDest: chScratchBuffer, maxLen: 128, pFormat: "%c", varValue->m_char);
      result = true;
      break;
    case 0x20:
      m_int = (const char *)varValue->m_int;
      if ( varValue->m_int == 0 )
        m_int = defaultValue;
      V_snprintf(pDest: chScratchBuffer, maxLen: 128, pFormat: "%s", m_int);
      result = true;
      break;
    default:
      _Warning(a1: "ScriptVmStringFromVariant failed to unpack parameter variant type %d\n", varValue->m_type);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428F10
// Name: public: static struct HSCRIPT__ __near * CGameUIScriptInterface::ScriptTableFromKeyValues(class IScriptVM __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__cdecl CGameUIScriptInterface::ScriptTableFromKeyValues(IScriptVM *pVM, KeyValues *kv)
{
  void (__thiscall *CreateTable)(IScriptVM *, ScriptVariant_t *); // edx
  KeyValues *i; // esi
  const char *Name; // eax
  ScriptVariant_t varTable; // [esp+10h] [ebp-90h] BYREF
  ScriptVariant_t varValue; // [esp+18h] [ebp-88h] BYREF
  char chScratchBuffer[128]; // [esp+20h] [ebp-80h] BYREF

  if ( kv == nullptr || pVM == nullptr )
    return nullptr;
  CreateTable = pVM->CreateTable;
  varTable.m_type = 0;
  varTable.m_flags = 0;
  varTable.m_int = 0;
  CreateTable(this: pVM, a2: &varTable);
  for ( i = KeyValues::GetFirstSubKey(this: kv); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    varValue.m_type = 0;
    varValue.m_flags = 0;
    varValue.m_int = 0;
    if ( CGameUIScriptInterface::ScriptVmKeyValueToVariant(pVM, val: i, &varValue, chScratchBuffer) )
    {
      Name = KeyValues::GetName(this: i);
      pVM->SetValue(this: pVM, a2: (HSCRIPT__ *)varTable.m_int, a3: Name, a4: &varValue);
    }
  }
  return (HSCRIPT__ *)varTable.m_int;
}

//------------------------------------------------------------------------------
// Address: 0x00428FD0
// Name: public: static bool CMemberScriptBinding2<class CGameUIScriptInterface __near *,struct HSCRIPT__ __near * (CGameUIScriptInterface::*)(char const __near *,struct HSCRIPT__ __near *),struct HSCRIPT__ __near *,char const __near *,struct HSCRIPT__ __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CGameUIScriptInterface *,HSCRIPT__ * (__thiscall CGameUIScriptInterface::*)(char const *,HSCRIPT__ *),HSCRIPT__ *,char const *,HSCRIPT__ *>::Call(
        int (__stdcall *pFunction)(const char *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 2 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = defaultValue;
  pReturn->m_int = pFunction(a1: m_int, a2: pArguments[1].m_int);
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00429010
// Name: public: static bool CMemberScriptBinding3<class CGameUIScriptInterface __near *,struct HSCRIPT__ __near * (CGameUIScriptInterface::*)(int,char const __near *,struct HSCRIPT__ __near *),struct HSCRIPT__ __near *,int,char const __near *,struct HSCRIPT__ __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding3<CGameUIScriptInterface *,HSCRIPT__ * (__thiscall CGameUIScriptInterface::*)(int,char const *,HSCRIPT__ *),HSCRIPT__ *,int,char const *,HSCRIPT__ *>::Call(
        int (__stdcall *pFunction)(int, const char *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_pszString; // edx

  if ( nArguments != 3 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_pszString = pArguments[1].m_pszString;
  if ( m_pszString == nullptr )
    m_pszString = defaultValue;
  pReturn->m_int = pFunction(a1: pArguments->m_int, a2: m_pszString, a3: pArguments[2].m_int);
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00429120
// Name: public: static class KeyValues __near * CGameUIScriptInterface::ScriptVmKeyValueFromVariant(class IScriptVM __near *,struct ScriptVariant_t __near &)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl CGameUIScriptInterface::ScriptVmKeyValueFromVariant(IScriptVM *pVM, ScriptVariant_t *varValue)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  KeyValues *result; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  CFmtStrN<256> *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // esi
  const char *value; // eax
  CFmtStrN<256> v15; // [esp+Ch] [ebp-10Ch] BYREF

  switch ( varValue->m_type )
  {
    case 1:
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: defaultValue);
      else
        v6 = nullptr;
      KeyValues::SetFloat(this: v6, keyName: nullptr, value: varValue->m_float);
      result = v6;
      break;
    case 5:
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
      {
        v3 = KeyValues::KeyValues(this: v2, setName: defaultValue);
        KeyValues::SetInt(this: v3, keyName: nullptr, value: varValue->m_int);
        result = v3;
      }
      else
      {
        KeyValues::SetInt(this: nullptr, keyName: nullptr, value: varValue->m_int);
        result = nullptr;
      }
      break;
    case 6:
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v8 = KeyValues::KeyValues(this: v7, setName: defaultValue);
      else
        v8 = nullptr;
      KeyValues::SetInt(this: v8, keyName: nullptr, value: varValue->m_char != 0);
      result = v8;
      break;
    case 8:
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: defaultValue);
      else
        v10 = nullptr;
      v11 = CFmtStrN<256>::CFmtStrN<256>(this: &v15, pszFormat: "%c", varValue->m_char);
      KeyValues::SetString(this: v10, keyName: nullptr, value: v11->m_szBuf);
      result = v10;
      break;
    case 0x20:
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
        v13 = KeyValues::KeyValues(this: v12, setName: defaultValue);
      else
        v13 = nullptr;
      value = (const char *)varValue->m_int;
      if ( varValue->m_int == 0 )
        value = defaultValue;
      KeyValues::SetString(this: v13, keyName: nullptr, value);
      result = v13;
      break;
    case 0x21:
      result = CGameUIScriptInterface::ScriptTableToKeyValues(pVM, szName: defaultValue, hTable: varValue->m_hScript);
      break;
    default:
      _Warning(a1: "ScriptVmKeyValueFromVariant failed to unpack parameter variant type %d\n", varValue->m_type);
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429320
// Name: public: static class KeyValues __near * CGameUIScriptInterface::ScriptTableToKeyValues(class IScriptVM __near *,char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl CGameUIScriptInterface::ScriptTableToKeyValues(
        IScriptVM *pVM,
        const char *szName,
        HSCRIPT__ *hTable)
{
  const char *v3; // esi
  KeyValues *v4; // eax
  KeyValues *result; // eax
  int v6; // esi
  int (__thiscall *GetKeyValue)(IScriptVM *, HSCRIPT__ *, int, ScriptVariant_t *, ScriptVariant_t *); // edx
  KeyValues *v8; // esi
  KeyValues *v9; // eax
  KeyValues *kv; // [esp+14h] [ebp-9Ch]
  int k; // [esp+18h] [ebp-98h]
  ScriptVariant_t varValue; // [esp+1Ch] [ebp-94h] BYREF
  ScriptVariant_t varKey; // [esp+24h] [ebp-8Ch] BYREF
  int numKeys; // [esp+2Ch] [ebp-84h]
  char chScratchBuffer[128]; // [esp+30h] [ebp-80h] BYREF

  v3 = szName;
  if ( szName == nullptr )
    v3 = defaultValue;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    result = KeyValues::KeyValues(this: v4, setName: v3);
    kv = result;
  }
  else
  {
    kv = nullptr;
    result = nullptr;
  }
  if ( hTable != nullptr && pVM != nullptr )
  {
    v6 = 0;
    numKeys = pVM->GetNumTableEntries(this: pVM, a2: hTable);
    k = 0;
    if ( numKeys > 0 )
    {
      do
      {
        GetKeyValue = pVM->GetKeyValue;
        varKey.m_type = 0;
        varKey.m_flags = 0;
        varKey.m_int = 0;
        varValue.m_type = 0;
        varValue.m_flags = 0;
        varValue.m_int = 0;
        GetKeyValue(this: pVM, a2: hTable, a3: v6, a4: &varKey, a5: &varValue);
        if ( CGameUIScriptInterface::ScriptVmStringFromVariant(varValue: &varKey, chScratchBuffer) )
        {
          v8 = CGameUIScriptInterface::ScriptVmKeyValueFromVariant(pVM, &varValue);
          if ( v8 == nullptr )
          {
            v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v9 != nullptr )
              v8 = KeyValues::KeyValues(this: v9, setName: defaultValue);
            else
              v8 = nullptr;
          }
          KeyValues::SetName(this: v8, setName: chScratchBuffer);
          KeyValues::AddSubKey(this: kv, pSubkey: v8);
          v6 = k;
        }
        k = ++v6;
      }
      while ( v6 < numKeys );
    }
    return kv;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429E00
// Name: public: struct HSCRIPT__ __near * CGameUIScriptInterface::LoadMenu(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CGameUIScriptInterface::LoadMenu(
        CGameUIScriptInterface *this,
        const char *szMenuName,
        HSCRIPT__ *hParams)
{
  KeyValues *v4; // ebx
  IGameUISystem *v5; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  int v9; // eax
  HSCRIPT__ *v10; // edi
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v12; // [esp+8h] [ebp-4h]

  if ( szMenuName == nullptr || *szMenuName == 0 )
    return nullptr;
  v4 = CGameUIScriptInterface::ScriptTableToKeyValues(pVM: this->m_pScriptVM, szName: szMenuName, hTable: hParams);
  if ( ui_script_spew_level.m_pParent->m_Value.m_nValue > 0 )
  {
    DevMsg(a1: "CGameUIScriptInterface::LoadMenu\n");
    pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
    v12 = 1;
    KeyValues::Dump(this: v4, &pDump, nIndentLevel: 0);
  }
  v5 = g_pGameUISystemMgrImpl->LoadGameUIScreen(this: g_pGameUISystemMgrImpl, a2: v4);
  if ( v5 != nullptr )
  {
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: defaultValue);
    else
      v8 = nullptr;
    v9 = v5->GetScriptHandle(this: v5);
    KeyValues::SetInt(this: v8, keyName: "scripthandle", value: v9);
    v10 = CGameUIScriptInterface::ScriptTableFromKeyValues(pVM: this->m_pScriptVM, kv: v8);
    if ( v8 != nullptr )
      KeyValues::deleteThis(this: v8);
    if ( v4 != nullptr )
      KeyValues::deleteThis(this: v4);
    return v10;
  }
  else
  {
    if ( v4 != nullptr )
      KeyValues::deleteThis(this: v4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429F10
// Name: public: struct HSCRIPT__ __near * CGameUIScriptInterface::CreateGraphic(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CGameUIScriptInterface::CreateGraphic(
        CGameUIScriptInterface *this,
        const char *szGraphicClassName,
        HSCRIPT__ *hParams)
{
  CGameUIDefinition *m_pMenu; // eax
  KeyValues *v5; // esi
  const char *String; // eax
  const char *v7; // ebp
  IGameUIGraphicClassFactory *v8; // eax
  int v9; // ebp
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  HSCRIPT__ *v13; // ebx

  if ( szGraphicClassName == nullptr || *szGraphicClassName == 0 )
    return nullptr;
  m_pMenu = this->m_pMenu;
  if ( m_pMenu == nullptr || m_pMenu->m_pGameUISystem == nullptr )
  {
    DevWarning(a1: "Scripts not connected to game UI system and cannot create graphics!\n");
    return nullptr;
  }
  v5 = CGameUIScriptInterface::ScriptTableToKeyValues(
         pVM: this->m_pScriptVM,
         szName: szGraphicClassName,
         hTable: hParams);
  if ( ui_script_spew_level.m_pParent->m_Value.m_nValue > 0 )
  {
    DevMsg(a1: "CGameUIScriptInterface::CreateGraphic\n");
    KeyValuesDumpAsDevMsg(pKeyValues: v5, nIndentLevel: 0, nDeveloperLevel: 1);
  }
  String = KeyValues::GetString(this: v5, keyName: "name", defaultValue: nullptr);
  v7 = String;
  if ( String == nullptr )
  {
    DevWarning(a1: "A must have a name!\n", 0);
LABEL_15:
    if ( v5 != nullptr )
      KeyValues::deleteThis(this: v5);
    return nullptr;
  }
  if ( CGameUIDefinition::GraphicExists(this: this->m_pMenu, pName: String) != nullptr )
  {
    DevWarning(a1: "A graphic with this name %s is already loaded!\n", v7);
    goto LABEL_15;
  }
  v8 = g_pGameUISystemMgrImpl->GetGraphicClassFactory(this: g_pGameUISystemMgrImpl, a2: szGraphicClassName);
  if ( v8 == nullptr )
  {
    DevWarning(a1: "No graphic class factory for %s!\n", szGraphicClassName);
    goto LABEL_15;
  }
  v9 = v8->CreateNewGraphicClass(this: v8, a2: v5, a3: this->m_pMenu);
  if ( v9 == 0 )
  {
    DevWarning(a1: "No graphic in factory %s!\n", szGraphicClassName);
    goto LABEL_15;
  }
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: defaultValue);
  else
    v12 = nullptr;
  KeyValues::SetInt(this: v12, keyName: "scripthandle", value: *(_DWORD *)(v9 + 360));
  v13 = CGameUIScriptInterface::ScriptTableFromKeyValues(pVM: this->m_pScriptVM, kv: v12);
  if ( v12 != nullptr )
    KeyValues::deleteThis(this: v12);
  if ( v5 != nullptr )
    KeyValues::deleteThis(this: v5);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x0042A070
// Name: public: struct HSCRIPT__ __near * CGameUIScriptInterface::CallScript(int,char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CGameUIScriptInterface::CallScript(
        CGameUIScriptInterface *this,
        int iScriptHandle,
        KeyValues *szCommandName,
        HSCRIPT__ *hParams)
{
  const char *v4; // edi
  CGameUISystem *m_pGameUISystem; // esi
  KeyValues *v8; // edi
  const char *v9; // eax
  KeyValues *v10; // esi
  HSCRIPT__ *v11; // ebx

  v4 = (const char *)szCommandName;
  if ( szCommandName == nullptr || *(_BYTE *)szCommandName == 0 )
    return nullptr;
  if ( iScriptHandle != 0 )
    m_pGameUISystem = CGameUISystem::FromScriptHandle(iScriptHandle);
  else
    m_pGameUISystem = (CGameUISystem *)this->m_pMenu->m_pGameUISystem;
  if ( m_pGameUISystem != nullptr )
  {
    v8 = CGameUIScriptInterface::ScriptTableToKeyValues(pVM: this->m_pScriptVM, szName: v4, hTable: hParams);
    if ( ui_script_spew_level.m_pParent->m_Value.m_nValue > 0 )
    {
      v9 = (const char *)m_pGameUISystem->GetName(this: m_pGameUISystem);
      DevMsg(a1: "CGameUIScriptInterface::CallScript( %d : %s )\n", iScriptHandle, v9);
      KeyValuesDumpAsDevMsg(pKeyValues: v8, nIndentLevel: 0, nDeveloperLevel: 1);
    }
    szCommandName = nullptr;
    m_pGameUISystem->ExecuteScript(this: m_pGameUISystem, a2: v8, a3: &szCommandName);
    if ( ui_script_spew_level.m_pParent->m_Value.m_nValue > 0 )
      KeyValuesDumpAsDevMsg(pKeyValues: szCommandName, nIndentLevel: 0, nDeveloperLevel: 1);
    v10 = szCommandName;
    v11 = CGameUIScriptInterface::ScriptTableFromKeyValues(pVM: this->m_pScriptVM, kv: szCommandName);
    if ( v10 != nullptr )
      KeyValues::deleteThis(this: v10);
    if ( v8 != nullptr )
      KeyValues::deleteThis(this: v8);
    return v11;
  }
  else
  {
    _Warning(a1: "CGameUIScriptInterface::CallScript with invalid script handle %d!\n", iScriptHandle);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A170
// Name: public: struct HSCRIPT__ __near * CGameUIScriptInterface::CallGraphic(int,char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CGameUIScriptInterface::CallGraphic(
        CGameUIScriptInterface *this,
        int iGraphicHandle,
        const char *szCommandName,
        HSCRIPT__ *hParams)
{
  CGameGraphic *v5; // esi
  KeyValues *v7; // edi
  const char *v8; // eax
  KeyValues *v9; // esi
  HSCRIPT__ *v10; // ebx

  if ( szCommandName == nullptr || *szCommandName == 0 || iGraphicHandle == 0 )
    return nullptr;
  v5 = CGameGraphic::FromScriptHandle(iScriptHandle: iGraphicHandle);
  if ( v5 != nullptr )
  {
    v7 = CGameUIScriptInterface::ScriptTableToKeyValues(pVM: this->m_pScriptVM, szName: szCommandName, hTable: hParams);
    if ( ui_script_spew_level.m_pParent->m_Value.m_nValue > 0 )
    {
      v8 = CUtlString::operator char const *(this: &v5->m_pName);
      DevMsg(a1: "CGameUIScriptInterface::CallGraphic( %d : %s )\n", iGraphicHandle, v8);
      KeyValuesDumpAsDevMsg(pKeyValues: v7, nIndentLevel: 0, nDeveloperLevel: 1);
    }
    v9 = v5->HandleScriptCommand(this: v5, a2: v7);
    if ( ui_script_spew_level.m_pParent->m_Value.m_nValue > 0 )
      KeyValuesDumpAsDevMsg(pKeyValues: v9, nIndentLevel: 0, nDeveloperLevel: 1);
    v10 = CGameUIScriptInterface::ScriptTableFromKeyValues(pVM: this->m_pScriptVM, kv: v9);
    if ( v9 != nullptr )
      KeyValues::deleteThis(this: v9);
    if ( v7 != nullptr )
      KeyValues::deleteThis(this: v7);
    return v10;
  }
  else
  {
    _Warning(a1: "CGameUIScriptInterface::CallGraphic with invalid graphic handle %d!\n", iGraphicHandle);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BC20
// Name: public: void CGameUIScriptInterface::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIScriptInterface::Shutdown(CGameUIScriptInterface *this)
{
  CUtlMap<CUtlString,IGameUIScreenController *,unsigned short> *p_m_Nuggets; // edi
  unsigned __int16 i; // si
  IGameUIScreenController *elem; // ecx

  p_m_Nuggets = &this->m_Nuggets;
  for ( i = CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Nuggets.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &p_m_Nuggets->m_Tree,
              i) )
  {
    elem = this->m_Nuggets.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    elem->OnScreenDisconnected(this: elem, a2: this->m_pMenu->m_pGameUISystem);
  }
  CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &p_m_Nuggets->m_Tree);
  p_m_Nuggets->m_Tree.m_FirstFree = -1;
  if ( p_m_Nuggets->m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( p_m_Nuggets->m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Nuggets->m_Tree.m_Elements.m_pMemory);
      p_m_Nuggets->m_Tree.m_Elements.m_pMemory = nullptr;
    }
    p_m_Nuggets->m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  p_m_Nuggets->m_Tree.m_LastAlloc.index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042BCB0
// Name: public: struct HSCRIPT__ __near * CGameUIScriptInterface::Nugget(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CGameUIScriptInterface::Nugget(
        CGameUIScriptInterface *this,
        char *szCommandName,
        HSCRIPT__ *hParams)
{
  CGameUIDefinition *m_pMenu; // ecx
  KeyValues *v5; // esi
  const char *Name; // eax
  const char *v7; // eax
  const char *String; // edi
  IGameUIScreenControllerFactory *v10; // edi
  const char *v11; // edi
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  int v14; // eax
  HSCRIPT__ *v15; // ebx
  const char *v16; // eax
  HSCRIPT__ *v17; // ecx
  CGameUISystem *m_pGameUISystem; // eax
  char **v19; // ecx
  const char *v20; // eax
  const char *v21; // eax
  IGameUIScreenController *Int; // eax
  int v23; // eax
  const char *v24; // eax
  KeyValues *v25; // eax
  int v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  unsigned __int16 v30; // di
  const char *v31; // eax
  char *v32; // eax
  const char *v33; // edi
  const char *v34; // eax
  void *v35; // esp
  unsigned __int16 v36; // di
  IGameUIScreenController *elem; // ecx
  KeyValues *v38; // eax
  const char *v39; // [esp-Ch] [ebp-34h]
  int v40; // [esp-8h] [ebp-30h]
  const char *v41; // [esp-4h] [ebp-2Ch]
  int v42; // [esp-4h] [ebp-2Ch]
  const char *v43; // [esp-4h] [ebp-2Ch]
  char v44[12]; // [esp+0h] [ebp-28h] BYREF
  CUtlString key; // [esp+Ch] [ebp-1Ch] BYREF
  const char *pch; // [esp+1Ch] [ebp-Ch]
  CGameUISystem *v47; // [esp+20h] [ebp-8h]
  IGameUIScreenController *usIdx; // [esp+24h] [ebp-4h] BYREF

  if ( szCommandName == nullptr || *szCommandName == 0 )
    return nullptr;
  m_pMenu = this->m_pMenu;
  if ( m_pMenu == nullptr || m_pMenu->m_pGameUISystem == nullptr )
  {
    DevWarning(a1: "Scripts not connected to game UI system and cannot use nuggets!\n");
    return nullptr;
  }
  v5 = CGameUIScriptInterface::ScriptTableToKeyValues(pVM: this->m_pScriptVM, szName: szCommandName, hTable: hParams);
  if ( ui_script_spew_level.m_pParent->m_Value.m_nValue > 0 )
  {
    DevMsg(a1: "CGameUIScriptInterface::Nugget\n");
    KeyValuesDumpAsDevMsg(pKeyValues: v5, nIndentLevel: 0, nDeveloperLevel: 1);
  }
  Name = KeyValues::GetName(this: v5);
  v7 = StringAfterPrefix(str: Name, prefix: "load:");
  if ( v7 == nullptr )
  {
    v16 = KeyValues::GetName(this: v5);
    String = StringAfterPrefix(str: v16, prefix: "ref:");
    if ( String != nullptr )
    {
      hParams = (HSCRIPT__ *)KeyValues::GetInt(this: v5, keyName: "scripthandle", defaultValue: 0);
      pch = KeyValues::GetString(this: v5, keyName: "usename", defaultValue: String);
      CUtlString::CUtlString(this: &key, pString: String);
      HIBYTE(szCommandName) = CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Find(
                                this: &this->m_Nuggets,
                                &key) != 0xFFFF;
      CUtlString::~CUtlString(this: &key);
      if ( HIBYTE(szCommandName) != 0 )
        goto LABEL_9;
      v17 = hParams;
      if ( hParams != nullptr )
      {
        m_pGameUISystem = CGameUISystem::FromScriptHandle(iScriptHandle: (int)hParams);
        v17 = hParams;
      }
      else
      {
        m_pGameUISystem = (CGameUISystem *)this->m_pMenu->m_pGameUISystem;
      }
      v47 = m_pGameUISystem;
      if ( m_pGameUISystem != nullptr )
      {
        if ( m_pGameUISystem->m_GameUIDef.m_Scripts.m_Size != 0
          && (v19 = (char **)*m_pGameUISystem->m_GameUIDef.m_Scripts.m_Memory.m_pMemory) != nullptr
          && (szCommandName = *v19) != nullptr )
        {
          CUtlString::CUtlString(this: &key, pString: pch);
          usIdx = (IGameUIScreenController *)CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Find(
                                               this: (CUtlMap<CUtlString,IGameUIScreenController *,unsigned short> *)(szCommandName + 12),
                                               &key);
          CUtlString::~CUtlString(this: &key);
          if ( (_WORD)usIdx != 0xFFFF )
          {
            usIdx = *(IGameUIScreenController **)(*((_DWORD *)szCommandName + 4) + 28 * (unsigned __int16)usIdx + 24);
            Int = (IGameUIScreenController *)KeyValues::GetInt(this: v5, keyName: "ptr", defaultValue: 0);
            if ( usIdx != Int )
            {
              v23 = KeyValues::GetInt(this: v5, keyName: "ptr", defaultValue: 0);
              v24 = (const char *)((int (__thiscall *)(CGameUISystem *, const char *, IGameUIScreenController *, int))v47->GetName)(
                                    a1: v47,
                                    a2: pch,
                                    a3: usIdx,
                                    a4: v23);
              DevWarning(
                a1: "Nugget reference request %s with script handle %d(%s) for nugget %s yielding %08X instead of expected %08X!\n",
                String,
                hParams,
                v24,
                v39,
                v40,
                v42);
            }
            CUtlString::CUtlString(this: &key, pString: String);
            CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Insert(
              this: &this->m_Nuggets,
              &key,
              insert: &usIdx);
            CUtlString::~CUtlString(this: &key);
            usIdx->OnScreenConnected(this: usIdx, a2: this->m_pMenu->m_pGameUISystem);
            v25 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v25 != nullptr )
              szCommandName = (char *)KeyValues::KeyValues(this: v25, setName: defaultValue);
            else
              szCommandName = nullptr;
            v26 = this->m_pMenu->m_pGameUISystem->GetScriptHandle(this: this->m_pMenu->m_pGameUISystem);
            KeyValues::SetInt(this: (KeyValues *)szCommandName, keyName: "scripthandle", value: v26);
            KeyValues::SetString(this: (KeyValues *)szCommandName, keyName: "usename", value: String);
            KeyValues::SetInt(this: (KeyValues *)szCommandName, keyName: "ptr", value: (int)usIdx);
            if ( ui_script_spew_level.m_pParent->m_Value.m_nValue <= 0 )
            {
              v13 = (KeyValues *)szCommandName;
            }
            else
            {
              v27 = (const char *)((int (__thiscall *)(CGameUISystem *, const char *))v47->GetName)(a1: v47, a2: pch);
              DevMsg(a1: "Referenced nugget %s from %d(%s):%s\n", String, hParams, v27, v43);
              v13 = (KeyValues *)szCommandName;
              KeyValuesDumpAsDevMsg(pKeyValues: (KeyValues *)szCommandName, nIndentLevel: 0, nDeveloperLevel: 1);
            }
            goto LABEL_21;
          }
          v21 = (const char *)((int (__thiscall *)(CGameUISystem *, const char *))v47->GetName)(a1: v47, a2: pch);
          DevWarning(
            a1: "Nugget reference request %s with script handle %d(%s) which has no nugget %s!\n",
            String,
            hParams,
            v21,
            v41);
        }
        else
        {
          v20 = (const char *)m_pGameUISystem->GetName(this: m_pGameUISystem);
          DevWarning(
            a1: "Nugget reference request %s with script handle %d(%s) which has no scripts!\n",
            String,
            hParams,
            v20);
        }
      }
      else
      {
        DevWarning(a1: "Nugget reference request %s with invalid script handle %d!\n", String, v17);
      }
    }
    else
    {
      v28 = KeyValues::GetName(this: v5);
      v29 = StringAfterPrefix(str: v28, prefix: "free:");
      szCommandName = (char *)v29;
      if ( v29 != nullptr )
      {
        CUtlString::CUtlString(this: &key, pString: v29);
        v30 = CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Find(this: &this->m_Nuggets, &key);
        CUtlString::~CUtlString(this: &key);
        if ( v30 == 0xFFFF )
        {
          DevWarning(a1: "Nugget factory %s is not loaded!\n", szCommandName);
        }
        else
        {
          hParams = (HSCRIPT__ *)this->m_Nuggets.m_Tree.m_Elements.m_pMemory[v30].m_Data.elem;
          CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::RemoveAt(this: &this->m_Nuggets, i: v30);
          (*(void (__thiscall **)(HSCRIPT__ *, IGameUISystem *))(*(_DWORD *)hParams + 4))(
            a1: hParams,
            a2: this->m_pMenu->m_pGameUISystem);
          if ( ui_script_spew_level.m_pParent->m_Value.m_nValue > 0 )
            DevMsg(a1: "Unloaded nugget %s\n", szCommandName);
        }
      }
      else
      {
        v31 = KeyValues::GetName(this: v5);
        v32 = (char *)StringAfterPrefix(str: v31, prefix: "use:");
        v33 = v32;
        if ( v32 != nullptr )
        {
          szCommandName = v32;
          strchr(string: (unsigned __int8 *)v32, chr: 0x3Au);
          pch = v34;
          if ( v34 != nullptr )
          {
            v35 = alloca(v34 - v33 + 1);
            hParams = (HSCRIPT__ *)v44;
            V_strncpy(pDest: v44, pSrc: v33, maxLen: v34 - v33 + 1);
            szCommandName = (char *)hParams;
            KeyValues::SetName(this: v5, setName: pch + 1);
          }
          else
          {
            KeyValues::SetName(this: v5, setName: defaultValue);
          }
          CUtlString::CUtlString(this: &key, pString: szCommandName);
          v36 = CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Find(this: &this->m_Nuggets, &key);
          CUtlString::~CUtlString(this: &key);
          if ( v36 != 0xFFFF )
          {
            elem = this->m_Nuggets.m_Tree.m_Elements.m_pMemory[v36].m_Data.elem;
            v38 = elem->OnScreenEvent(this: elem, a2: this->m_pMenu->m_pGameUISystem, a3: v5);
            v13 = v38;
            if ( ui_script_spew_level.m_pParent->m_Value.m_nValue > 0 )
              KeyValuesDumpAsDevMsg(pKeyValues: v38, nIndentLevel: 0, nDeveloperLevel: 1);
            goto LABEL_21;
          }
          DevWarning(a1: "Nugget factory %s is not loaded!\n", szCommandName);
        }
      }
    }
LABEL_10:
    if ( v5 != nullptr )
    {
      KeyValues::deleteThis(this: v5);
      return nullptr;
    }
    return nullptr;
  }
  hParams = (HSCRIPT__ *)v7;
  String = KeyValues::GetString(this: v5, keyName: "usename", defaultValue: v7);
  pch = String;
  CUtlString::CUtlString(this: &key, pString: String);
  HIBYTE(szCommandName) = CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Find(
                            this: &this->m_Nuggets,
                            &key) != 0xFFFF;
  CUtlString::~CUtlString(this: &key);
  if ( HIBYTE(szCommandName) != 0 )
  {
LABEL_9:
    DevWarning(a1: "Nugget factory %s is already loaded!\n", String);
    goto LABEL_10;
  }
  v10 = g_pGameUISystemMgrImpl->GetScreenControllerFactory(this: g_pGameUISystemMgrImpl, a2: hParams);
  if ( v10 == nullptr )
  {
    DevWarning(a1: "No nugget factory for %s!\n", hParams);
    goto LABEL_10;
  }
  KeyValues::SetName(this: v5, setName: (const char *)hParams);
  v11 = (const char *)v10->GetController(this: v10, a2: v5);
  szCommandName = (char *)v11;
  if ( v11 == nullptr )
  {
    DevWarning(a1: "No nugget in factory %s!\n", hParams);
    goto LABEL_10;
  }
  CUtlString::CUtlString(this: &key, pString: pch);
  CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Insert(
    this: &this->m_Nuggets,
    &key,
    insert: (IGameUIScreenController *const *)&szCommandName);
  CUtlString::~CUtlString(this: &key);
  (**(void (__thiscall ***)(const char *, IGameUISystem *))v11)(a1: v11, a2: this->m_pMenu->m_pGameUISystem);
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: defaultValue);
  else
    v13 = nullptr;
  v14 = this->m_pMenu->m_pGameUISystem->GetScriptHandle(this: this->m_pMenu->m_pGameUISystem);
  KeyValues::SetInt(this: v13, keyName: "scripthandle", value: v14);
  KeyValues::SetString(this: v13, keyName: "usename", value: pch);
  KeyValues::SetInt(this: v13, keyName: "ptr", value: (int)szCommandName);
  if ( ui_script_spew_level.m_pParent->m_Value.m_nValue > 0 )
  {
    DevMsg(a1: "Loaded nugget %s\n", (const char *)hParams);
    KeyValuesDumpAsDevMsg(pKeyValues: v13, nIndentLevel: 0, nDeveloperLevel: 1);
  }
LABEL_21:
  v15 = CGameUIScriptInterface::ScriptTableFromKeyValues(pVM: this->m_pScriptVM, kv: v13);
  if ( v13 != nullptr )
    KeyValues::deleteThis(this: v13);
  if ( v5 != nullptr )
    KeyValues::deleteThis(this: v5);
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x0042C3C0
// Name: void InitCGameUIScriptInterfaceScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCGameUIScriptInterfaceScriptDesc()
{
  ScriptFunctionBinding_t *v0; // edi
  _DWORD *p_m_pMemory; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // ebp
  int m_nAllocationCount; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _DWORD *v9; // eax
  int v10; // ebp
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  _DWORD *v14; // eax
  ScriptFunctionBinding_t *v15; // edi
  _DWORD *v16; // esi
  IMemAlloc_vtbl *v17; // edx
  int v18; // eax
  int v19; // ebp
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  _DWORD *v23; // eax
  int v24; // ebp
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  _DWORD *v28; // eax
  ScriptFunctionBinding_t *v29; // edi
  _DWORD *v30; // esi
  IMemAlloc_vtbl *v31; // edx
  int v32; // eax
  int v33; // ebp
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  _DWORD *v37; // eax
  int v38; // ebp
  int v39; // eax
  int v40; // ecx
  int v41; // eax
  _DWORD *v42; // eax
  int v43; // ebp
  int v44; // eax
  int v45; // ecx
  int v46; // eax
  _DWORD *v47; // eax
  ScriptFunctionBinding_t *v48; // edi
  void **v49; // esi
  void *v50; // eax
  int v51; // ebp
  int v52; // eax
  char *v53; // ecx
  int v54; // eax
  _DWORD *v55; // eax
  int v56; // ebp
  int v57; // eax
  char *v58; // ecx
  int v59; // eax
  _DWORD *v60; // eax
  int v61; // ebp
  int v62; // eax
  char *v63; // ecx
  int v64; // eax
  _DWORD *v65; // eax
  ScriptFunctionBinding_t *v66; // edi
  void **v67; // esi
  void *v68; // eax
  int v69; // ebp
  int v70; // eax
  char *v71; // ecx
  int v72; // eax
  _DWORD *v73; // eax
  int v74; // ebp
  int v75; // eax
  char *v76; // ecx
  int v77; // eax
  _DWORD *v78; // eax

  if ( !bInitialized )
  {
    g_CGameUIScriptInterface_ScriptDesc.m_pszScriptName = "CGameUIScriptInterface";
    g_CGameUIScriptInterface_ScriptDesc.m_pszClassname = "CGameUIScriptInterface";
    bInitialized = true;
    g_CGameUIScriptInterface_ScriptDesc.m_pszDescription = "!";
    g_CGameUIScriptInterface_ScriptDesc.m_pBaseDesc = nullptr;
    g_CGameUIScriptInterface_ScriptDesc.pHelper = nullptr;
    v0 = &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                      this: &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings,
                                                                                      elem: g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings.m_Size)];
    p_m_pMemory = &v0->m_desc.m_Parameters.m_Memory.m_pMemory;
    v0->m_desc.m_pszDescription = "LoadMenu( name, {params} ) : Load a menu.";
    v0->m_desc.m_pszScriptName = "LoadMenu";
    v0->m_desc.m_pszFunction = "LoadMenu";
    v0->m_desc.m_ReturnType = 33;
    v0->m_desc.m_Parameters.m_Memory.m_nGrowSize = 1;
    if ( v0->m_desc.m_Parameters.m_Memory.m_nAllocationCount < 2 && v0->m_desc.m_Parameters.m_Memory.m_nGrowSize >= 0 )
    {
      v0->m_desc.m_Parameters.m_Memory.m_nAllocationCount = 2;
      v2 = _g_pMemAlloc->__vftable;
      if ( *p_m_pMemory != 0 )
        v3 = ((int (__stdcall *)(_DWORD, int))v2->Realloc_2)(a1: *p_m_pMemory, a2: 8);
      else
        v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
      *p_m_pMemory = v3;
    }
    v0->m_desc.m_Parameters.m_pElements = v0->m_desc.m_Parameters.m_Memory.m_pMemory;
    m_Size = v0->m_desc.m_Parameters.m_Size;
    m_nAllocationCount = v0->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v0->m_desc.m_Parameters,
        num: m_Size - m_nAllocationCount + 1);
    ++v0->m_desc.m_Parameters.m_Size;
    v6 = *p_m_pMemory;
    v7 = v0->m_desc.m_Parameters.m_Size - m_Size - 1;
    v8 = v0->m_desc.m_Parameters.m_Size - m_Size == 1;
    v0->m_desc.m_Parameters.m_pElements = v0->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v7 >= 0 && !v8 )
      _V_memmove(dest: (void *)(v6 + 4 * m_Size + 4), src: (const void *)(v6 + 4 * m_Size), count: 4 * v7);
    v9 = (_DWORD *)(*p_m_pMemory + 4 * m_Size);
    if ( v9 != nullptr )
      *v9 = 32;
    v10 = v0->m_desc.m_Parameters.m_Size;
    v11 = v0->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v10 + 1 > v11 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v0->m_desc.m_Parameters,
        num: v10 - v11 + 1);
    ++v0->m_desc.m_Parameters.m_Size;
    v12 = *p_m_pMemory;
    v13 = v0->m_desc.m_Parameters.m_Size - v10 - 1;
    v8 = v0->m_desc.m_Parameters.m_Size - v10 == 1;
    v0->m_desc.m_Parameters.m_pElements = v0->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v13 >= 0 && !v8 )
      _V_memmove(dest: (void *)(v12 + 4 * v10 + 4), src: (const void *)(v12 + 4 * v10), count: 4 * v13);
    v14 = (_DWORD *)(*p_m_pMemory + 4 * v10);
    if ( v14 != nullptr )
      *v14 = 33;
    v0->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CGameUIScriptInterface *,HSCRIPT__ * (__thiscall CGameUIScriptInterface::*)(char const *,HSCRIPT__ *),HSCRIPT__ *,char const *,HSCRIPT__ *>::Call;
    v0->m_pFunction = CGameUIScriptInterface::LoadMenu;
    v0->m_flags = 1;
    v15 = &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                       this: &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings,
                                                                                       elem: g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings.m_Size)];
    v16 = &v15->m_desc.m_Parameters.m_Memory.m_pMemory;
    v15->m_desc.m_pszDescription = "CreateGraphic( classname, {params} ) : Create a graphic.";
    v15->m_desc.m_pszScriptName = "CreateGraphic";
    v15->m_desc.m_pszFunction = "CreateGraphic";
    v15->m_desc.m_ReturnType = 33;
    v15->m_desc.m_Parameters.m_Memory.m_nGrowSize = 1;
    if ( v15->m_desc.m_Parameters.m_Memory.m_nAllocationCount < 2 && v15->m_desc.m_Parameters.m_Memory.m_nGrowSize >= 0 )
    {
      v15->m_desc.m_Parameters.m_Memory.m_nAllocationCount = 2;
      v17 = _g_pMemAlloc->__vftable;
      if ( *v16 != 0 )
        v18 = ((int (__stdcall *)(_DWORD, int))v17->Realloc_2)(a1: *v16, a2: 8);
      else
        v18 = ((int (__stdcall *)(int))v17->Alloc_2)(a1: 8);
      *v16 = v18;
    }
    v15->m_desc.m_Parameters.m_pElements = v15->m_desc.m_Parameters.m_Memory.m_pMemory;
    v19 = v15->m_desc.m_Parameters.m_Size;
    v20 = v15->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v19 + 1 > v20 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v15->m_desc.m_Parameters,
        num: v19 - v20 + 1);
    ++v15->m_desc.m_Parameters.m_Size;
    v21 = *v16;
    v22 = v15->m_desc.m_Parameters.m_Size - v19 - 1;
    v8 = v15->m_desc.m_Parameters.m_Size - v19 == 1;
    v15->m_desc.m_Parameters.m_pElements = v15->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v22 >= 0 && !v8 )
      _V_memmove(dest: (void *)(v21 + 4 * v19 + 4), src: (const void *)(v21 + 4 * v19), count: 4 * v22);
    v23 = (_DWORD *)(*v16 + 4 * v19);
    if ( v23 != nullptr )
      *v23 = 32;
    v24 = v15->m_desc.m_Parameters.m_Size;
    v25 = v15->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v24 + 1 > v25 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v15->m_desc.m_Parameters,
        num: v24 - v25 + 1);
    ++v15->m_desc.m_Parameters.m_Size;
    v26 = *v16;
    v27 = v15->m_desc.m_Parameters.m_Size - v24 - 1;
    v8 = v15->m_desc.m_Parameters.m_Size - v24 == 1;
    v15->m_desc.m_Parameters.m_pElements = v15->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v27 >= 0 && !v8 )
      _V_memmove(dest: (void *)(v26 + 4 * v24 + 4), src: (const void *)(v26 + 4 * v24), count: 4 * v27);
    v28 = (_DWORD *)(*v16 + 4 * v24);
    if ( v28 != nullptr )
      *v28 = 33;
    v15->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CGameUIScriptInterface *,HSCRIPT__ * (__thiscall CGameUIScriptInterface::*)(char const *,HSCRIPT__ *),HSCRIPT__ *,char const *,HSCRIPT__ *>::Call;
    v15->m_pFunction = CGameUIScriptInterface::CreateGraphic;
    v15->m_flags = 1;
    v29 = &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                       this: &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings,
                                                                                       elem: g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings.m_Size)];
    v30 = &v29->m_desc.m_Parameters.m_Memory.m_pMemory;
    v29->m_desc.m_pszDescription = "CallScript( scripthandle, function, {params} ) : Execute other script function (scrip"
                                   "thandle=0 will run local script).";
    v29->m_desc.m_pszScriptName = "CallScript";
    v29->m_desc.m_pszFunction = "CallScript";
    v29->m_desc.m_ReturnType = 33;
    v29->m_desc.m_Parameters.m_Memory.m_nGrowSize = 1;
    if ( v29->m_desc.m_Parameters.m_Memory.m_nAllocationCount < 3 && v29->m_desc.m_Parameters.m_Memory.m_nGrowSize >= 0 )
    {
      v29->m_desc.m_Parameters.m_Memory.m_nAllocationCount = 3;
      v31 = _g_pMemAlloc->__vftable;
      if ( *v30 != 0 )
        v32 = ((int (__stdcall *)(_DWORD, int))v31->Realloc_2)(a1: *v30, a2: 12);
      else
        v32 = ((int (__stdcall *)(int))v31->Alloc_2)(a1: 12);
      *v30 = v32;
    }
    v29->m_desc.m_Parameters.m_pElements = v29->m_desc.m_Parameters.m_Memory.m_pMemory;
    v33 = v29->m_desc.m_Parameters.m_Size;
    v34 = v29->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v33 + 1 > v34 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v29->m_desc.m_Parameters,
        num: v33 - v34 + 1);
    ++v29->m_desc.m_Parameters.m_Size;
    v35 = *v30;
    v36 = v29->m_desc.m_Parameters.m_Size - v33 - 1;
    v8 = v29->m_desc.m_Parameters.m_Size - v33 == 1;
    v29->m_desc.m_Parameters.m_pElements = v29->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v36 >= 0 && !v8 )
      _V_memmove(dest: (void *)(v35 + 4 * v33 + 4), src: (const void *)(v35 + 4 * v33), count: 4 * v36);
    v37 = (_DWORD *)(*v30 + 4 * v33);
    if ( v37 != nullptr )
      *v37 = 5;
    v38 = v29->m_desc.m_Parameters.m_Size;
    v39 = v29->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v38 + 1 > v39 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v29->m_desc.m_Parameters,
        num: v38 - v39 + 1);
    ++v29->m_desc.m_Parameters.m_Size;
    v40 = *v30;
    v41 = v29->m_desc.m_Parameters.m_Size - v38 - 1;
    v8 = v29->m_desc.m_Parameters.m_Size - v38 == 1;
    v29->m_desc.m_Parameters.m_pElements = v29->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v41 >= 0 && !v8 )
      _V_memmove(dest: (void *)(v40 + 4 * v38 + 4), src: (const void *)(v40 + 4 * v38), count: 4 * v41);
    v42 = (_DWORD *)(*v30 + 4 * v38);
    if ( v42 != nullptr )
      *v42 = 32;
    v43 = v29->m_desc.m_Parameters.m_Size;
    v44 = v29->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v43 + 1 > v44 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v29->m_desc.m_Parameters,
        num: v43 - v44 + 1);
    ++v29->m_desc.m_Parameters.m_Size;
    v45 = *v30;
    v46 = v29->m_desc.m_Parameters.m_Size - v43 - 1;
    v8 = v29->m_desc.m_Parameters.m_Size - v43 == 1;
    v29->m_desc.m_Parameters.m_pElements = v29->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v46 >= 0 && !v8 )
      _V_memmove(dest: (void *)(v45 + 4 * v43 + 4), src: (const void *)(v45 + 4 * v43), count: 4 * v46);
    v47 = (_DWORD *)(*v30 + 4 * v43);
    if ( v47 != nullptr )
      *v47 = 33;
    v29->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding3<CGameUIScriptInterface *,HSCRIPT__ * (__thiscall CGameUIScriptInterface::*)(int,char const *,HSCRIPT__ *),HSCRIPT__ *,int,char const *,HSCRIPT__ *>::Call;
    v29->m_pFunction = CGameUIScriptInterface::CallScript;
    v29->m_flags = 1;
    v48 = &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                       this: &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings,
                                                                                       elem: g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings.m_Size)];
    v49 = (void **)&v48->m_desc.m_Parameters.m_Memory.m_pMemory;
    v48->m_desc.m_pszDescription = "CallGraphic( graphichandle, commandname, {params} ) : Execute a graphic function.";
    v48->m_desc.m_pszScriptName = "CallGraphic";
    v48->m_desc.m_pszFunction = "CallGraphic";
    v48->m_desc.m_ReturnType = 33;
    v48->m_desc.m_Parameters.m_Memory.m_nGrowSize = 1;
    if ( v48->m_desc.m_Parameters.m_Memory.m_nAllocationCount < 3 && v48->m_desc.m_Parameters.m_Memory.m_nGrowSize >= 0 )
    {
      v48->m_desc.m_Parameters.m_Memory.m_nAllocationCount = 3;
      if ( *v49 != nullptr )
        v50 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *v49, a3: 12);
      else
        v50 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
      *v49 = v50;
    }
    v48->m_desc.m_Parameters.m_pElements = v48->m_desc.m_Parameters.m_Memory.m_pMemory;
    v51 = v48->m_desc.m_Parameters.m_Size;
    v52 = v48->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v51 + 1 > v52 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v48->m_desc.m_Parameters,
        num: v51 - v52 + 1);
    ++v48->m_desc.m_Parameters.m_Size;
    v53 = (char *)*v49;
    v54 = v48->m_desc.m_Parameters.m_Size - v51 - 1;
    v8 = v48->m_desc.m_Parameters.m_Size - v51 == 1;
    v48->m_desc.m_Parameters.m_pElements = v48->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v54 >= 0 && !v8 )
      _V_memmove(dest: &v53[4 * v51 + 4], src: &v53[4 * v51], count: 4 * v54);
    v55 = (char *)*v49 + 4 * v51;
    if ( v55 != nullptr )
      *v55 = 5;
    v56 = v48->m_desc.m_Parameters.m_Size;
    v57 = v48->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v56 + 1 > v57 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v48->m_desc.m_Parameters,
        num: v56 - v57 + 1);
    ++v48->m_desc.m_Parameters.m_Size;
    v58 = (char *)*v49;
    v59 = v48->m_desc.m_Parameters.m_Size - v56 - 1;
    v8 = v48->m_desc.m_Parameters.m_Size - v56 == 1;
    v48->m_desc.m_Parameters.m_pElements = v48->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v59 >= 0 && !v8 )
      _V_memmove(dest: &v58[4 * v56 + 4], src: &v58[4 * v56], count: 4 * v59);
    v60 = (char *)*v49 + 4 * v56;
    if ( v60 != nullptr )
      *v60 = 32;
    v61 = v48->m_desc.m_Parameters.m_Size;
    v62 = v48->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v61 + 1 > v62 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v48->m_desc.m_Parameters,
        num: v61 - v62 + 1);
    ++v48->m_desc.m_Parameters.m_Size;
    v63 = (char *)*v49;
    v64 = v48->m_desc.m_Parameters.m_Size - v61 - 1;
    v8 = v48->m_desc.m_Parameters.m_Size - v61 == 1;
    v48->m_desc.m_Parameters.m_pElements = v48->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v64 >= 0 && !v8 )
      _V_memmove(dest: &v63[4 * v61 + 4], src: &v63[4 * v61], count: 4 * v64);
    v65 = (char *)*v49 + 4 * v61;
    if ( v65 != nullptr )
      *v65 = 33;
    v48->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding3<CGameUIScriptInterface *,HSCRIPT__ * (__thiscall CGameUIScriptInterface::*)(int,char const *,HSCRIPT__ *),HSCRIPT__ *,int,char const *,HSCRIPT__ *>::Call;
    v48->m_pFunction = CGameUIScriptInterface::CallGraphic;
    v48->m_flags = 1;
    v66 = &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                       this: &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings,
                                                                                       elem: g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings.m_Size)];
    v67 = (void **)&v66->m_desc.m_Parameters.m_Memory.m_pMemory;
    v66->m_desc.m_pszDescription = "Nugget( action, {params} ) : Interface with nuggets.";
    v66->m_desc.m_pszScriptName = "Nugget";
    v66->m_desc.m_pszFunction = "Nugget";
    v66->m_desc.m_ReturnType = 33;
    v66->m_desc.m_Parameters.m_Memory.m_nGrowSize = 1;
    if ( v66->m_desc.m_Parameters.m_Memory.m_nAllocationCount < 2 && v66->m_desc.m_Parameters.m_Memory.m_nGrowSize >= 0 )
    {
      v66->m_desc.m_Parameters.m_Memory.m_nAllocationCount = 2;
      if ( *v67 != nullptr )
        v68 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *v67, a3: 8);
      else
        v68 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8);
      *v67 = v68;
    }
    v66->m_desc.m_Parameters.m_pElements = v66->m_desc.m_Parameters.m_Memory.m_pMemory;
    v69 = v66->m_desc.m_Parameters.m_Size;
    v70 = v66->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v69 + 1 > v70 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v66->m_desc.m_Parameters,
        num: v69 - v70 + 1);
    ++v66->m_desc.m_Parameters.m_Size;
    v71 = (char *)*v67;
    v72 = v66->m_desc.m_Parameters.m_Size - v69 - 1;
    v8 = v66->m_desc.m_Parameters.m_Size - v69 == 1;
    v66->m_desc.m_Parameters.m_pElements = v66->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v72 >= 0 && !v8 )
      _V_memmove(dest: &v71[4 * v69 + 4], src: &v71[4 * v69], count: 4 * v72);
    v73 = (char *)*v67 + 4 * v69;
    if ( v73 != nullptr )
      *v73 = 32;
    v74 = v66->m_desc.m_Parameters.m_Size;
    v75 = v66->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v74 + 1 > v75 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v66->m_desc.m_Parameters,
        num: v74 - v75 + 1);
    ++v66->m_desc.m_Parameters.m_Size;
    v76 = (char *)*v67;
    v77 = v66->m_desc.m_Parameters.m_Size - v74 - 1;
    v8 = v66->m_desc.m_Parameters.m_Size - v74 == 1;
    v66->m_desc.m_Parameters.m_pElements = v66->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( v77 >= 0 && !v8 )
      _V_memmove(dest: &v76[4 * v74 + 4], src: &v76[4 * v74], count: 4 * v77);
    v78 = (char *)*v67 + 4 * v74;
    if ( v78 != nullptr )
      *v78 = 33;
    v66->m_flags = 1;
    v66->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CGameUIScriptInterface *,HSCRIPT__ * (__thiscall CGameUIScriptInterface::*)(char const *,HSCRIPT__ *),HSCRIPT__ *,char const *,HSCRIPT__ *>::Call;
    v66->m_pFunction = CGameUIScriptInterface::Nugget;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042CAB0
// Name: public: CGameUIScriptInterface::~CGameUIScriptInterface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIScriptInterface::~CGameUIScriptInterface(CGameUIScriptInterface *this)
{
  CGameUIScriptInterface::Shutdown(this);
  CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_GraphicScriptInstances.m_Tree);
  CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Nuggets.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0042CAD0
// Name: public: CGameUIScriptInterface::CGameUIScriptInterface(class IScriptVM __near *,class CGameUIDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
CGameUIScriptInterface *__thiscall CGameUIScriptInterface::CGameUIScriptInterface(
        CGameUIScriptInterface *this,
        IScriptVM *pScriptVM,
        CGameUIDefinition *pDef)
{
  IScriptVM *m_pScriptVM; // edi
  int v5; // eax
  bool (__thiscall *SetValue)(IScriptVM *, HSCRIPT__ *, const char *, const ScriptVariant_t *); // edx
  HSCRIPT__ *v7; // ebp
  int v9; // [esp+10h] [ebp-8h] BYREF
  __int16 v10; // [esp+14h] [ebp-4h]
  __int16 v11; // [esp+16h] [ebp-2h]

  this->m_pMenu = pDef;
  this->m_pScriptVM = pScriptVM;
  this->m_Nuggets.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))UtlStringLessFunc;
  this->m_Nuggets.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Nuggets.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Nuggets.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Nuggets.m_Tree.m_Root = -1;
  this->m_Nuggets.m_Tree.m_FirstFree = -1;
  this->m_Nuggets.m_Tree.m_NumElements = 0;
  this->m_Nuggets.m_Tree.m_LastAlloc.index = -1;
  this->m_Nuggets.m_Tree.m_pElements = this->m_Nuggets.m_Tree.m_Elements.m_pMemory;
  this->m_GraphicScriptInstances.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))UtlStringLessFunc;
  this->m_GraphicScriptInstances.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_GraphicScriptInstances.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_GraphicScriptInstances.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_GraphicScriptInstances.m_Tree.m_Root = -1;
  this->m_GraphicScriptInstances.m_Tree.m_FirstFree = -1;
  this->m_GraphicScriptInstances.m_Tree.m_NumElements = 0;
  this->m_GraphicScriptInstances.m_Tree.m_LastAlloc.index = -1;
  this->m_GraphicScriptInstances.m_Tree.m_pElements = this->m_GraphicScriptInstances.m_Tree.m_Elements.m_pMemory;
  m_pScriptVM = this->m_pScriptVM;
  v5 = (int)m_pScriptVM->RegisterInstance(this: m_pScriptVM, a2: &g_CGameUIScriptInterface_ScriptDesc, a3: this);
  SetValue = m_pScriptVM->SetValue;
  v7 = (HSCRIPT__ *)v5;
  v10 = 33;
  v11 = 0;
  v9 = v5;
  SetValue(this: m_pScriptVM, a2: nullptr, a3: "c", a4: (const ScriptVariant_t *)&v9);
  this->m_Scope = v7;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00429060
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<class CUtlString,class IGameUIScreenController __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlString,class IGameUIScreenController __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlString,class IGameUIScreenController __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenController *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x004290C0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<class CUtlString,class CGameGraphic __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlString,class CGameGraphic __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlString,class CGameGraphic __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}
