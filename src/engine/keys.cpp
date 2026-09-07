// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/keys.cpp
// Functions: 35
// ============================================================

#include "engine\keys.h"

//------------------------------------------------------------------------------
// Address: 0x10198120
// Name: enum ButtonCode_t GetBaseButtonCode(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl GetBaseButtonCode(ButtonCode_t code)
{
  ButtonCode_t result; // eax

  result = code;
  if ( (unsigned int)(code - 114) <= 0x7F )
    return ((code - 114) & 0x8000001F) + 114;
  if ( (unsigned int)(code - 242) <= 0xF )
    return ((code - 242) & 0x80000003) + 242;
  if ( (unsigned int)(code - 258) <= 0x2F )
    return (code - 258) % 12 + 258;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10198190
// Name: int GetJoystickForCode(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetJoystickForCode(ButtonCode_t code)
{
  if ( (unsigned int)(code - 114) > 0xBF )
    return 0;
  if ( code <= JOYSTICK_LAST_BUTTON )
    return (code - 114) / 32;
  if ( (unsigned int)(code - 242) > 0xF )
    return (code - 258) / 12;
  return (code - 242) / 4;
}

//------------------------------------------------------------------------------
// Address: 0x10198200
// Name: escape
// Source: json
//------------------------------------------------------------------------------
void __cdecl escape()
{
  IEngineVGuiInternal *v0; // eax

  v0 = EngineVGui();
  v0->HideGameUI(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10198210
// Name: class KeyValues __near * GetDefaultKeyBindings(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__usercall GetDefaultKeyBindings@<eax>(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  KeyValues *v3; // eax
  void *v4; // edi
  int v6; // esi
  void *v7; // ebx
  const char *i; // esi
  const char *v9; // esi
  char token[1024]; // [esp+0h] [ebp-60Ch] BYREF
  char szFileName[260]; // [esp+400h] [ebp-20Ch] BYREF
  char szKeyName[260]; // [esp+504h] [ebp-108h] BYREF
  KeyValues *defaults; // [esp+608h] [ebp-4h]

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    defaults = KeyValues::KeyValues(this: v3, setName: "defaults");
  else
    defaults = nullptr;
  V_snprintf(pDest: szFileName, maxLen: 260, pFormat: "%skb_def.lst", "scripts/");
  v4 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, _DWORD, int))g_pFileSystem->Open)(
                 a1: &g_pFileSystem->IBaseFileSystem,
                 a2: szFileName,
                 a3: "r",
                 a4: 0,
                 a5: a2);
  if ( v4 != nullptr )
  {
    v6 = ((int (__thiscall *)(IBaseFileSystem *, void *, int, int))g_pFileSystem->Size_2)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: v4,
           a3,
           a4: a1);
    v7 = MemAlloc_Alloc(nSize: v6 + 1);
    g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v7, a3: v6, a4: v4);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    *((_BYTE *)v7 + v6) = 0;
    for ( i = COM_ParseFile(data: (const char *)v7, token, maxtoken: 1024);
          strlen(token) != 0;
          i = COM_ParseFile(data: v9, token, maxtoken: 1024) )
    {
      V_strncpy(pDest: szKeyName, pSrc: token, maxLen: 256);
      v9 = COM_ParseFile(data: i, token, maxtoken: 1024);
      if ( strlen(token) == 0 )
        break;
      KeyValues::SetString(this: defaults, keyName: token, value: szKeyName);
    }
    free(pMem: v7);
    return defaults;
  }
  else
  {
    ConMsg(a1: "Couldn't open kb_def.lst\n");
    return defaults;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101983D0
// Name: char const __near * GetSuggestedBinding(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetSuggestedBinding(char *command, KeyValues *defaults)
{
  char *result; // eax
  KeyValues *FirstSubKey; // esi
  char *String; // edi
  const char *Name; // eax

  if ( defaults == nullptr )
    return nullptr;
  result = KeyValues::GetString(this: defaults, keyName: command, defaultValue: nullptr);
  if ( result == nullptr )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: defaults);
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( V_stristr(pStr: Name, pSearch: command) != nullptr )
          break;
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        if ( FirstSubKey == nullptr )
          return nullptr;
      }
      return String;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10198440
// Name: int Key_CountBindings(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Key_CountBindings()
{
  int result; // eax
  KeyInfo_t *v1; // ecx
  char *m_pKeyBinding; // edx
  char *v3; // edx
  char *v4; // edx
  char *v5; // edx
  char *v6; // edx

  result = 0;
  v1 = &s_KeyContext.m_pKeyInfo[1];
  do
  {
    m_pKeyBinding = v1[-1].m_pKeyBinding;
    if ( m_pKeyBinding != nullptr && *m_pKeyBinding != 0 )
      ++result;
    if ( v1->m_pKeyBinding != nullptr && *v1->m_pKeyBinding != 0 )
      ++result;
    v3 = v1[1].m_pKeyBinding;
    if ( v3 != nullptr && *v3 != 0 )
      ++result;
    v4 = v1[2].m_pKeyBinding;
    if ( v4 != nullptr && *v4 != 0 )
      ++result;
    v5 = v1[3].m_pKeyBinding;
    if ( v5 != nullptr && *v5 != 0 )
      ++result;
    v6 = v1[4].m_pKeyBinding;
    if ( v6 != nullptr && *v6 != 0 )
      ++result;
    v1 += 6;
  }
  while ( (int)v1 < (int)&s_KeyContext.m_nTrapKey );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101984A0
// Name: IsKeyBoundedToBinding
// Source: json
//------------------------------------------------------------------------------
char __usercall IsKeyBoundedToBinding@<al>(int i@<eax>, const char *pBind@<edi>)
{
  unsigned __int8 *m_pKeyBinding; // esi
  int v3; // eax
  char *v5; // eax
  char szBinding[256]; // [esp+4h] [ebp-100h] BYREF

  m_pKeyBinding = (unsigned __int8 *)s_KeyContext.m_pKeyInfo[i].m_pKeyBinding;
  if ( m_pKeyBinding != nullptr && *m_pKeyBinding != 0 )
  {
    strchr(string: m_pKeyBinding, chr: 0x3Bu);
    if ( v3 != 0 )
    {
      V_strncpy(pDest: szBinding, pSrc: (const char *)m_pKeyBinding, maxLen: 256);
      v5 = strtok(string: szBinding, control: ";");
      if ( v5 != nullptr )
      {
        while ( 1 )
        {
          if ( *v5 == 43 )
            ++v5;
          if ( V_strcasecmp(s1: v5, s2: pBind) == 0 )
            break;
          v5 = strtok(string: nullptr, control: ";");
          if ( v5 == nullptr )
            return 0;
        }
        return 1;
      }
    }
    else
    {
      if ( *m_pKeyBinding == 43 )
        ++m_pKeyBinding;
      if ( V_strcasecmp(s1: (const char *)m_pKeyBinding, s2: pBind) == 0 )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10198540
// Name: int Key_CodeForBinding(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Key_CodeForBinding(const char *pBinding, int userId, int iStartCount, int iAllowJoystick)
{
  const char *v4; // eax
  const char *v6; // edi
  int v7; // esi
  int iCount; // [esp+14h] [ebp+8h]

  v4 = pBinding;
  if ( pBinding != nullptr )
  {
LABEL_2:
    v6 = v4;
    if ( *v4 == 43 )
      v6 = v4 + 1;
    v7 = 0;
    iCount = 0;
    while ( 1 )
    {
      if ( IsKeyBoundedToBinding(i: v7, pBind: v6) != 0 )
      {
        if ( iAllowJoystick < 0 )
          goto LABEL_11;
        if ( iAllowJoystick != 0 )
        {
          if ( (unsigned int)(v7 - 114) <= 0xBF )
          {
LABEL_11:
            if ( iCount == iStartCount )
              return v7;
            ++iCount;
          }
        }
        else if ( (unsigned int)(v7 - 114) > 0xBF )
        {
          goto LABEL_11;
        }
      }
      if ( ++v7 >= 306 )
      {
        if ( _V_stricmp(s1: "duck", s2: v6) == 0 )
        {
          iStartCount = iCount;
          iAllowJoystick = -1;
          v4 = "toggle_duck";
          goto LABEL_2;
        }
        if ( _V_stricmp(s1: "zoom", s2: v6) == 0 )
        {
          iAllowJoystick = -1;
          iStartCount = iCount;
          v4 = "toggle_zoom";
          goto LABEL_2;
        }
        return -1;
      }
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10198600
// Name: char const __near * Key_BindingForKey(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Key_BindingForKey(ButtonCode_t code)
{
  if ( (unsigned int)code > BUTTON_CODE_LAST )
    return nullptr;
  else
    return s_KeyContext.m_pKeyInfo[code].m_pKeyBinding;
}

//------------------------------------------------------------------------------
// Address: 0x10198620
// Name: key_listboundkeys
// Source: json
//------------------------------------------------------------------------------
void __cdecl key_listboundkeys()
{
  ButtonCode_t i; // esi
  char *m_pKeyBinding; // eax
  const char *(__thiscall *ButtonCodeToString)(IInputSystem *, ButtonCode_t); // eax
  const char *v3; // eax
  int JoystickForCode; // eax
  const char *v5; // [esp-8h] [ebp-10h]
  char *v6; // [esp-4h] [ebp-Ch]

  for ( i = BUTTON_CODE_NONE; i < BUTTON_CODE_LAST; ++i )
  {
    if ( (unsigned int)i <= BUTTON_CODE_LAST )
    {
      m_pKeyBinding = s_KeyContext.m_pKeyInfo[i].m_pKeyBinding;
      if ( m_pKeyBinding != nullptr && *m_pKeyBinding != 0 )
      {
        v6 = s_KeyContext.m_pKeyInfo[i].m_pKeyBinding;
        ButtonCodeToString = g_pInputSystem->ButtonCodeToString;
        if ( (unsigned int)(i - 114) <= 0xBF )
        {
          v5 = (const char *)((int (__stdcall *)(ButtonCode_t))ButtonCodeToString)(a1: i);
          JoystickForCode = GetJoystickForCode(code: i);
          ConMsg(a1: "[%d:%d]\"%s\" = \"%s\"\n", i, JoystickForCode, v5, v6);
        }
        else
        {
          v3 = (const char *)((int (__stdcall *)(ButtonCode_t))ButtonCodeToString)(a1: i);
          ConMsg(a1: "\"%s\" = \"%s\"\n", v3, v6);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101986A0
// Name: key_findbinding
// Source: json
//------------------------------------------------------------------------------
void __cdecl key_findbinding(const CCommand *args)
{
  const char *v1; // eax
  ButtonCode_t v2; // esi
  char *m_pKeyBinding; // edi
  int JoystickForCode; // eax
  const char *v5; // [esp-14h] [ebp-14h]
  const CCommand *argsa; // [esp+8h] [ebp+8h]

  if ( args->m_nArgc == 2 && (v1 = args->m_ppArgv[1], argsa = (const CCommand *)v1, v1 != nullptr) && *v1 != 0 )
  {
    v2 = BUTTON_CODE_NONE;
    while ( 1 )
    {
      if ( (unsigned int)v2 <= BUTTON_CODE_LAST )
      {
        m_pKeyBinding = s_KeyContext.m_pKeyInfo[v2].m_pKeyBinding;
        if ( m_pKeyBinding != nullptr && *m_pKeyBinding != 0 && _V_strstr(s1: m_pKeyBinding, search: v1) != nullptr )
        {
          v5 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v2);
          if ( (unsigned int)(v2 - 114) <= 0xBF )
          {
            JoystickForCode = GetJoystickForCode(code: v2);
            ConMsg(a1: "[%d] \"%s\" = \"%s\"\n", JoystickForCode, v5, m_pKeyBinding);
          }
          else
          {
            ConMsg(a1: "\"%s\" = \"%s\"\n", v5, m_pKeyBinding);
          }
        }
      }
      if ( ++v2 >= BUTTON_CODE_LAST )
        break;
      v1 = (const char *)argsa;
    }
  }
  else
  {
    ConMsg(a1: "usage:  key_findbinding substring\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198760
// Name: void Key_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_Init()
{
  ReadCheatCommandsFromFile(pchFileName: "scripts/cheatcodes.txt");
  ReadCheatCommandsFromFile(pchFileName: "scripts/mod_cheatcodes.txt");
}

//------------------------------------------------------------------------------
// Address: 0x10198780
// Name: void Key_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_Shutdown()
{
  unsigned int i; // esi

  for ( i = 0; i < 306; ++i )
  {
    free(pMem: s_KeyContext.m_pKeyInfo[i].m_pKeyBinding);
    s_KeyContext.m_pKeyInfo[i].m_pKeyBinding = nullptr;
  }
  ClearCheatCommands();
}

//------------------------------------------------------------------------------
// Address: 0x101987B0
// Name: void Key_StartTrapMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_StartTrapMode()
{
  if ( !s_KeyContext.m_bTrapMode )
  {
    *(_WORD *)&s_KeyContext.m_bTrapMode = 1;
    s_KeyContext.m_nTrapKeyUp = BUTTON_CODE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101987D0
// Name: bool Key_CheckDoneTrapping(enum ButtonCode_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Key_CheckDoneTrapping(ButtonCode_t *code)
{
  if ( s_KeyContext.m_bTrapMode || !s_KeyContext.m_bDoneTrapping )
    return 0;
  *code = s_KeyContext.m_nTrapKey;
  s_KeyContext.m_nTrapKey = BUTTON_CODE_INVALID;
  s_KeyContext.m_bDoneTrapping = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10198810
// Name: FilterTrappedKey
// Source: json
//------------------------------------------------------------------------------
char __usercall FilterTrappedKey@<al>(ButtonCode_t code@<eax>, bool bDown@<cl>)
{
  if ( s_KeyContext.m_nTrapKeyUp != code || bDown )
  {
    if ( s_KeyContext.m_bTrapMode && bDown )
    {
      s_KeyContext.m_nTrapKey = code;
      s_KeyContext.m_nTrapKeyUp = code;
      *(_WORD *)&s_KeyContext.m_bTrapMode = 256;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    s_KeyContext.m_nTrapKeyUp = BUTTON_CODE_INVALID;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198850
// Name: HandleToolKey
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HandleToolKey(const InputEvent_t *event)
{
  IToolSystem *v1; // eax

  if ( event->m_nType == 202 || event->m_nType == 203 )
    return false;
  v1 = toolframework->GetTopmostTool(this: toolframework);
  return v1 != nullptr && v1->TrapKey(this: v1, a2: (ButtonCode_t)event->m_nData, a3: event->m_nType != 1);
}

//------------------------------------------------------------------------------
// Address: 0x101988B0
// Name: HandleVGuiKey
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HandleVGuiKey(const InputEvent_t *event)
{
  IEngineVGuiInternal *v1; // eax

  v1 = EngineVGui();
  return v1->Key_Event(this: v1, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x101988D0
// Name: HandleScaleformKey
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HandleScaleformKey(const InputEvent_t *event)
{
  int m_nData; // esi
  bool result; // al

  m_nData = event->m_nData;
  result = g_pScaleformUI->HandleInputEvent(this: g_pScaleformUI, a2: event);
  if ( m_nData == 109 || m_nData == 110 || m_nData == 111 )
    return false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10198900
// Name: HandleClientKey
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HandleClientKey(const InputEvent_t *event)
{
  int m_nType; // eax

  m_nType = event->m_nType;
  return event->m_nType != 203
      && m_nType != 202
      && g_ClientDLL != nullptr
      && g_ClientDLL->IN_KeyEvent(
           this: g_ClientDLL,
           a2: m_nType != 1,
           a3: (ButtonCode_t)event->m_nData,
           a4: s_KeyContext.m_pKeyInfo[event->m_nData].m_pKeyBinding) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10198960
// Name: HandleGameUIKey
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HandleGameUIKey(const InputEvent_t *event)
{
  return g_ClientDLL != nullptr && g_ClientDLL->HandleGameUIEvent(this: g_ClientDLL, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x10198990
// Name: HandleEngineKey
// Source: json
//------------------------------------------------------------------------------
char __cdecl HandleEngineKey(const InputEvent_t *event)
{
  int m_nType; // eax
  bool v2; // bl
  ButtonCode_t m_nData; // esi
  int JoystickForCode; // eax
  char *m_pKeyBinding; // edi
  char v6; // al
  char *v7; // ecx
  vgui::CTreeViewListControl *v8; // ecx
  ECommandTarget_t TraceType; // eax
  ECommandTarget_t v10; // eax
  char *v12; // [esp-14h] [ebp-414h]
  const char *v13; // [esp-Ch] [ebp-40Ch]
  char cmd[1024]; // [esp+0h] [ebp-400h] BYREF

  m_nType = event->m_nType;
  if ( event->m_nType == 203 || m_nType == 202 )
    return 0;
  v2 = m_nType != 1;
  m_nData = event->m_nData;
  if ( m_nType != 1
    && (unsigned int)(m_nData - 114) <= 0xBF
    && (unsigned int)(m_nData - 258) > 0x2F
    && s_KeyContext.m_pKeyInfo[m_nData].m_pKeyBinding == nullptr )
  {
    v13 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: m_nData);
    JoystickForCode = GetJoystickForCode(code: m_nData);
    _ConDMsg(a1: "[joy %d]%s is unbound.\n", JoystickForCode, v13);
  }
  m_pKeyBinding = s_KeyContext.m_pKeyInfo[m_nData].m_pKeyBinding;
  if ( m_pKeyBinding != nullptr )
  {
    v6 = *m_pKeyBinding;
    if ( *m_pKeyBinding != 0 )
    {
      if ( v2 )
      {
        if ( v6 == 43 )
        {
          V_snprintf(pDest: cmd, maxLen: 1024, pFormat: "%s %i\n", m_pKeyBinding, m_nData);
          v7 = cmd;
          v12 = cmd;
          goto LABEL_23;
        }
        if ( _V_stricmp(s1: m_pKeyBinding, s2: "toggleconsole") != 0
          || (*((_BYTE *)&s_KeyContext.m_pKeyInfo[81] + 4) & 0x10) == 0
          && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[79] + 4) & 0x10) == 0
          && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[83] + 4) & 0x10) == 0
          && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[82] + 4) & 0x10) == 0
          && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[80] + 4) & 0x10) == 0
          && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[84] + 4) & 0x10) == 0 )
        {
          TraceType = CTraceFilter::GetTraceType(this: v8);
          Cbuf_AddText(eTarget: TraceType, pText: m_pKeyBinding, nTickDelay: 0);
          v12 = "\n";
          goto LABEL_23;
        }
      }
      else if ( v6 == 43 )
      {
        V_snprintf(pDest: cmd, maxLen: 1024, pFormat: "-%s %i\n", m_pKeyBinding + 1, m_nData);
        v12 = cmd;
LABEL_23:
        v10 = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)v7);
        Cbuf_AddText(eTarget: v10, pText: v12, nTickDelay: 0);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10198B10
// Name: FilterKey
// Source: json
//------------------------------------------------------------------------------
bool __usercall FilterKey@<al>(
        const InputEvent_t *event@<eax>,
        KeyUpTarget_t target,
        bool (__cdecl *func)(const InputEvent_t *))
{
  int m_nType; // eax
  int m_nData; // esi
  bool result; // al
  int v7; // edi

  m_nType = event->m_nType;
  m_nData = event->m_nData;
  if ( (m_nType == 1 || m_nType == 202 || m_nType == 203)
    && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) & 0xF) != target
    && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) & 0xF) != 0 )
  {
    return false;
  }
  result = func(a1: event);
  v7 = event->m_nType;
  if ( v7 == 0 || v7 == 2 )
  {
    if ( result )
      *((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) ^= (target
                                                          ^ *((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4))
                                                         & 0xF;
  }
  else if ( v7 == 1 && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) & 0xF) == target )
  {
    *((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) &= 0xF0u;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10198BB0
// Name: void Key_Event(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_Event(const InputEvent_t *event)
{
  ButtonCode_t m_nData; // edi
  int m_nValue; // eax
  int m_nType; // eax
  bool v4; // cl
  IEngineVGuiInternal *v5; // eax
  IEngineVGuiInternal *v6; // eax

  m_nData = event->m_nData;
  if ( (unsigned int)(m_nData - 114) > 0xBF )
  {
    if ( in_forceuser.m_pParent != nullptr )
      m_nValue = in_forceuser.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: m_nValue);
  }
  m_nType = event->m_nType;
  if ( event->m_nType == 203
    || m_nType == 202
    || (m_nType == 0 || m_nType == 2 ? (v4 = true) : (v4 = false),
        ((*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) & 0x10) != 0) != v4
     && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) ^= (*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4)
                                                             ^ (16 * v4))
                                                            & 0x10,
         FilterTrappedKey(code: m_nData, bDown: v4) == 0)) )
  {
    v5 = EngineVGui();
    if ( v5->IsInitialized(this: v5) )
    {
      v6 = EngineVGui();
      v6->UpdateButtonState(this: v6, a2: event);
      if ( !FilterKey(event, target: KEY_UP_TOOLS, func: HandleToolKey)
        && (m_nData == KEY_ESCAPE
         || event->m_nType == 0 && m_nData == KEY_BACKQUOTE
         || !FilterKey(event, target: KEY_UP_VGUI, func: HandleVGuiKey)
         && !FilterKey(event, target: KEY_UP_SCALEFORM, func: HandleScaleformKey))
        && !FilterKey(event, target: KEY_UP_GAMEUI, func: HandleGameUIKey)
        && !FilterKey(event, target: KEY_UP_CLIENT, func: HandleClientKey)
        && (m_nData != KEY_ESCAPE || !FilterKey(event, target: KEY_UP_VGUI, func: HandleVGuiKey)) )
      {
        FilterKey(event, target: KEY_UP_ENGINE, func: (bool (__cdecl *)(const InputEvent_t *))HandleEngineKey);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198D10
// Name: enum ButtonCode_t ButtonCodeToJoystickButtonCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl ButtonCodeToJoystickButtonCode(ButtonCode_t code, int nDesiredJoystick)
{
  ButtonCode_t result; // eax
  int v3; // esi

  result = code;
  if ( (unsigned int)(code - 114) <= 0xBF )
  {
    v3 = nDesiredJoystick;
    if ( nDesiredJoystick != 0 )
    {
      if ( nDesiredJoystick >= 0 )
      {
        if ( nDesiredJoystick > 3 )
          v3 = 3;
      }
      else
      {
        v3 = 0;
      }
      result = GetBaseButtonCode(code);
      if ( (unsigned int)(result - 114) > 0x7F )
      {
        if ( (unsigned int)(result - 242) > 0xF )
        {
          if ( (unsigned int)(result - 258) <= 0x2F )
            result += 12 * v3;
        }
        else
        {
          result += 4 * v3;
        }
      }
      else
      {
        result += 32 * v3;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10198D80
// Name: void Key_SetBinding(enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_SetBinding(ButtonCode_t keynum, const char *pBinding)
{
  ButtonCode_t v2; // esi
  char *m_pKeyBinding; // eax
  int v4; // ebx
  char *v5; // edi
  IScaleformUI *v6; // ecx
  IBaseClientDLL_vtbl *v7; // ebx
  int v8; // eax

  v2 = keynum;
  if ( keynum != BUTTON_CODE_INVALID )
  {
    if ( (unsigned int)(keynum - 114) <= 0xBF )
      v2 = ButtonCodeToJoystickButtonCode(code: keynum, nDesiredJoystick: 0);
    m_pKeyBinding = s_KeyContext.m_pKeyInfo[v2].m_pKeyBinding;
    if ( m_pKeyBinding != nullptr )
    {
      if ( _V_strcmp(s1: m_pKeyBinding, s2: pBinding) == 0 )
        return;
      free(pMem: s_KeyContext.m_pKeyInfo[v2].m_pKeyBinding);
      s_KeyContext.m_pKeyInfo[v2].m_pKeyBinding = nullptr;
    }
    v4 = _V_strlen(str: pBinding);
    v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
    V_strncpy(pDest: v5, pSrc: pBinding, maxLen: v4 + 1);
    v5[v4] = 0;
    v6 = g_pScaleformUI;
    s_KeyContext.m_pKeyInfo[v2].m_pKeyBinding = v5;
    if ( v6 != nullptr )
      v6->UpdateBindingForButton(this: v6, a2: v2, a3: pBinding);
    if ( g_ClientDLL != nullptr )
    {
      v7 = g_ClientDLL->__vftable;
      v8 = ((int (__thiscall *)(IInputSystem *, ButtonCode_t, char *))g_pInputSystem->ButtonCodeToString)(
             a1: g_pInputSystem,
             a2: v2,
             a3: v5);
      ((void (__thiscall *)(IBaseClientDLL *, ButtonCode_t, int))v7->OnKeyBindingChanged)(
        a1: g_ClientDLL,
        a2: v2,
        a3: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198E60
// Name: unbind
// Source: json
//------------------------------------------------------------------------------
void __cdecl unbind(const CCommand *args)
{
  ButtonCode_t v1; // eax

  if ( args->m_nArgc == 2 )
  {
    v1 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: args->m_ppArgv[1]);
    if ( v1 == BUTTON_CODE_INVALID )
    {
      if ( args->m_nArgc > 1 )
        ConMsg(a1: "\"%s\" isn't a valid key\n", args->m_ppArgv[1]);
      else
        ConMsg(a1: "\"%s\" isn't a valid key\n", defaultValue);
    }
    else if ( v1 == KEY_ESCAPE )
    {
      ConMsg(a1: "Can't unbind ESCAPE key\n");
    }
    else
    {
      Key_SetBinding(keynum: v1, pBinding: defaultValue);
    }
  }
  else
  {
    ConMsg(a1: "unbind <key> : remove commands from a key\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198F00
// Name: unbindall
// Source: json
//------------------------------------------------------------------------------
void __cdecl unbindall()
{
  ButtonCode_t i; // esi

  for ( i = BUTTON_CODE_NONE; i < BUTTON_CODE_LAST; ++i )
  {
    if ( s_KeyContext.m_pKeyInfo[i].m_pKeyBinding != nullptr && i != KEY_ESCAPE && i != KEY_BACKQUOTE )
      Key_SetBinding(keynum: i, pBinding: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198F30
// Name: bind_0
// Source: json
//------------------------------------------------------------------------------
void __cdecl bind_0(const CCommand *args)
{
  int m_nArgc; // edi
  const char *v2; // eax
  ButtonCode_t v3; // eax
  ButtonCode_t v4; // ebx
  char *m_pKeyBinding; // ebx
  const char *v6; // esi
  int v7; // esi
  const char **v8; // ebx
  const char *v9; // eax
  char cmd[1024]; // [esp+8h] [ebp-404h] BYREF
  ButtonCode_t b; // [esp+408h] [ebp-4h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 2 || m_nArgc == 3 )
  {
    v2 = defaultValue;
    if ( m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    v3 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: v2);
    v4 = v3;
    b = v3;
    if ( v3 == BUTTON_CODE_INVALID )
    {
      if ( args->m_nArgc > 1 )
        ConMsg(a1: "\"%s\" isn't a valid key\n", args->m_ppArgv[1]);
      else
        ConMsg(a1: "\"%s\" isn't a valid key\n", defaultValue);
    }
    else if ( m_nArgc == 2 )
    {
      if ( (unsigned int)(v3 - 114) <= 0xBF )
      {
        b = ButtonCodeToJoystickButtonCode(code: v3, nDesiredJoystick: 0);
        v4 = b;
      }
      m_pKeyBinding = s_KeyContext.m_pKeyInfo[v4].m_pKeyBinding;
      if ( m_pKeyBinding != nullptr )
      {
        if ( args->m_nArgc > 1 )
          v6 = args->m_ppArgv[1];
        else
          v6 = defaultValue;
        ConMsg(a1: "\"%s\" = \"%s\"\n", v6, m_pKeyBinding);
      }
      else if ( args->m_nArgc > 1 )
      {
        ConMsg(a1: "\"%s\" is not bound\n", args->m_ppArgv[1]);
      }
      else
      {
        ConMsg(a1: "\"%s\" is not bound\n", defaultValue);
      }
    }
    else if ( v3 == KEY_ESCAPE )
    {
      V_strncpy(pDest: cmd, pSrc: "cancelselect", maxLen: 1024);
      Key_SetBinding(keynum: KEY_ESCAPE, pBinding: cmd);
    }
    else
    {
      v7 = 2;
      cmd[0] = 0;
      if ( m_nArgc > 2 )
      {
        v8 = &args->m_ppArgv[2];
        do
        {
          if ( v7 > 2 )
            V_strncat(pDest: cmd, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
          if ( v7 < 0 || v7 >= args->m_nArgc )
            v9 = defaultValue;
          else
            v9 = *v8;
          V_strncat(pDest: cmd, pSrc: v9, destBufferSize: 0x400u, max_chars_to_copy: -1);
          ++v7;
          ++v8;
        }
        while ( v7 < m_nArgc );
        v4 = b;
      }
      Key_SetBinding(keynum: v4, pBinding: cmd);
    }
  }
  else
  {
    ConMsg(a1: "bind <key> [command] : attach a command to a key\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199120
// Name: char const __near * Key_NameForBinding(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Key_NameForBinding(const char *pBinding, int userId, int iStartCount, int iAllowJoystick)
{
  int v4; // eax
  ButtonCode_t v5; // ebx
  const char *v6; // edi

  v4 = Key_CodeForBinding(pBinding, userId, iStartCount, iAllowJoystick);
  v5 = v4;
  if ( pBinding == nullptr || v4 == -1 )
    return nullptr;
  v6 = pBinding;
  if ( *pBinding == 43 )
    v6 = pBinding + 1;
  if ( IsKeyBoundedToBinding(i: v4, pBind: v6) != 0 )
    return g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v5);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10199180
// Name: public: CFmtStrN<2048>::CFmtStrN<2048>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<2048> *CFmtStrN<2048>::CFmtStrN<2048>(CFmtStrN<2048> *this, const char *pszFormat, ...)
{
  CFmtStrN<2048> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<2048>_vtbl *)&CFmtStrN<2048>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 2047, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[2047] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<2048>::CFmtStrN<2048>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<2048>::CFmtStrN<2048>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101991F0
// Name: void Key_ForceBind_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Key_ForceBind_f(int a1@<ebx>, const CCommand *args)
{
  const CCommand *v2; // edi
  int m_nArgc; // esi
  int v4; // eax
  char *v5; // ebx
  int v6; // eax
  ButtonCode_t v7; // esi
  const char *v8; // edi
  const char *v9; // edi
  char *SuggestedBinding; // esi
  ButtonCode_t v11; // eax
  ButtonCode_t v12; // edi
  ButtonCode_t v13; // eax
  ButtonCode_t v14; // edi
  char *m_pKeyBinding; // eax
  ButtonCode_t v16; // esi
  const char *v17; // eax
  char *v18; // ecx
  int v19; // eax
  ButtonCode_t v20; // esi
  const char *v21; // edi
  int argc; // [esp+8h] [ebp-18h]
  KeyValues *defaults; // [esp+Ch] [ebp-14h]
  const char **v24; // [esp+10h] [ebp-10h]
  int arg; // [esp+14h] [ebp-Ch]
  Color unboundColor; // [esp+18h] [ebp-8h] BYREF
  Color boundColor; // [esp+1Ch] [ebp-4h] BYREF

  v2 = args;
  m_nArgc = args->m_nArgc;
  argc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    defaults = GetDefaultKeyBindings(a1, a2: (int)args, a3: m_nArgc);
    v4 = 1;
    boundColor = (Color)-12517632;
    unboundColor = (Color)-12582657;
    arg = 1;
    if ( m_nArgc > 1 )
    {
      v24 = &args->m_ppArgv[1];
      while ( 1 )
      {
        v5 = (char *)(v4 < 0 || v4 >= v2->m_nArgc ? defaultValue : *v24);
        v6 = Key_CodeForBinding(pBinding: v5, userId: -1, iStartCount: 0, iAllowJoystick: -1);
        v7 = v6;
        if ( v5 == nullptr || v6 == -1 )
          goto LABEL_15;
        v8 = v5;
        if ( *v5 == 43 )
          v8 = v5 + 1;
        if ( IsKeyBoundedToBinding(i: v6, pBind: v8) != 0 )
          v9 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v7);
        else
LABEL_15:
          v9 = nullptr;
        SuggestedBinding = GetSuggestedBinding(command: v5, defaults);
        if ( SuggestedBinding != nullptr )
        {
          if ( v9 == nullptr )
          {
            v13 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: SuggestedBinding);
            v14 = v13;
            if ( (unsigned int)v13 > BUTTON_CODE_LAST )
              m_pKeyBinding = nullptr;
            else
              m_pKeyBinding = s_KeyContext.m_pKeyInfo[v13].m_pKeyBinding;
            if ( v14 == BUTTON_CODE_INVALID || m_pKeyBinding != nullptr && *m_pKeyBinding != 0 )
            {
              v16 = v14 + 1;
              if ( v14 + 1 > 106 )
                v16 = KEY_0;
              if ( v16 != v14 )
              {
                while ( 1 )
                {
                  v17 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v16);
                  if ( (unsigned int)v16 > BUTTON_CODE_LAST )
                    break;
                  v18 = s_KeyContext.m_pKeyInfo[v16].m_pKeyBinding;
                  if ( v18 == nullptr || *v18 == 0 )
                    break;
                  if ( ++v16 > KEY_SCROLLLOCKTOGGLE )
                    v16 = KEY_0;
                  if ( v16 == v14 )
                    goto LABEL_40;
                }
                ConColorMsg(a1: &boundColor, a2: "Bound \"%s\" to key %s\n", v5, v17);
                Key_SetBinding(keynum: v16, pBinding: v5);
              }
            }
            else
            {
              ConColorMsg(a1: &boundColor, a2: "Bound \"%s\" to key %s\n", v5, SuggestedBinding);
              Key_SetBinding(keynum: v14, pBinding: v5);
            }
LABEL_40:
            v19 = Key_CodeForBinding(pBinding: v5, userId: -1, iStartCount: 0, iAllowJoystick: -1);
            v20 = v19;
            if ( v5 == nullptr || v19 == -1 )
              goto LABEL_46;
            v21 = v5;
            if ( *v5 == 43 )
              v21 = v5 + 1;
            if ( IsKeyBoundedToBinding(i: v19, pBind: v21) == 0
              || g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v20) == nullptr )
            {
LABEL_46:
              ConColorMsg(a1: &unboundColor, a2: "Unable to bind \"%s\" to a key\n", v5);
            }
          }
        }
        else if ( v9 != nullptr )
        {
          v11 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: v9);
          v12 = v11;
          if ( v11 != BUTTON_CODE_INVALID && v11 != KEY_ESCAPE )
          {
            ConColorMsg(a1: &boundColor, a2: "Unbound obsolete command \"%s\"\n", v5);
            Key_SetBinding(keynum: v12, pBinding: defaultValue);
          }
        }
        ++v24;
        if ( ++arg >= argc )
          break;
        v2 = args;
        v4 = arg;
      }
    }
    KeyValues::deleteThis(this: defaults);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199430
// Name: void Key_WriteBindings(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_WriteBindings(CUtlBuffer *buf, int iSplitscreenSlot)
{
  int v2; // edx
  int *p_m_nGrowSize; // eax
  ButtonCode_t v4; // esi
  char *m_pKeyBinding; // ebx
  const char *v6; // edi
  int JoystickForCode; // esi
  CFmtStrN<2048> *v8; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v9; // ebx
  int m_Size; // edi
  CUtlString *m_pMemory; // esi
  const char *v12; // eax
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *v13; // esi
  int i; // ebx
  CUtlBinaryBlock *v15; // eax
  CFmtStrN<2048> v16; // [esp+0h] [ebp-84Ch] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > deferred[2]; // [esp+80Ch] [ebp-40h] BYREF
  char v18; // [esp+834h] [ebp-18h] BYREF
  CUtlString str; // [esp+838h] [ebp-14h] BYREF
  int nSlot; // [esp+848h] [ebp-4h]

  v2 = 1;
  p_m_nGrowSize = &deferred[0].m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v2;
  }
  while ( v2 >= 0 );
  v4 = BUTTON_CODE_NONE;
  nSlot = 0;
  do
  {
    m_pKeyBinding = s_KeyContext.m_pKeyInfo[v4].m_pKeyBinding;
    if ( m_pKeyBinding != nullptr && *m_pKeyBinding != 0 )
    {
      v6 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v4);
      JoystickForCode = GetJoystickForCode(code: v4);
      if ( iSplitscreenSlot >= 0 )
      {
        if ( iSplitscreenSlot != JoystickForCode )
          goto LABEL_14;
LABEL_8:
        CUtlBuffer::Printf(this: buf, pFmt: "bind \"%s\" \"%s\"\n", v6, m_pKeyBinding);
        goto LABEL_14;
      }
      if ( JoystickForCode == 0 )
        goto LABEL_8;
      CUtlString::CUtlString(this: &str);
      v8 = CFmtStrN<2048>::CFmtStrN<2048>(
             this: &v16,
             pszFormat: "cmd%d bind \"%s\" \"%s\"\n",
             JoystickForCode + 1,
             v6,
             m_pKeyBinding);
      CUtlString::operator=(this: &str, src: v8->m_szBuf);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        this: &deferred[JoystickForCode],
        elem: deferred[JoystickForCode].m_Size,
        src: &str);
      str.m_Storage.m_nActualLength = 0;
      if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( str.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
          str.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        str.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
LABEL_14:
    v4 = nSlot + 1;
    nSlot = v4;
  }
  while ( v4 < BUTTON_CODE_LAST );
  nSlot = 1;
  if ( host_state.max_splitscreen_players > 1 )
  {
    v9 = &deferred[1];
    do
    {
      m_Size = v9->m_Size;
      if ( m_Size > 0 )
      {
        m_pMemory = v9->m_Memory.m_pMemory;
        do
        {
          v12 = CUtlString::operator char const *(this: m_pMemory);
          CUtlBuffer::Printf(this: buf, pFmt: "%s", v12);
          ++m_pMemory;
          --m_Size;
        }
        while ( m_Size != 0 );
      }
      ++v9;
      ++nSlot;
    }
    while ( nSlot < host_state.max_splitscreen_players );
  }
  v13 = (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&v18;
  for ( i = 1; i >= 0; --i )
  {
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: --v13);
    if ( v13->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v13->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13->m_Memory.m_pMemory);
        v13->m_Memory.m_pMemory = nullptr;
      }
      v13->m_Memory.m_nAllocationCount = 0;
    }
    v15 = v13->m_Memory.m_pMemory;
    v13->m_pElements = v13->m_Memory.m_pMemory;
    if ( v13->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v15 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
        v13->m_Memory.m_pMemory = nullptr;
      }
      v13->m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211E5C
// Name: bind(x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall bind(SOCKET s, const struct sockaddr *name, int namelen)
{
  return __imp__bind@12(s, name, namelen);
}

//------------------------------------------------------------------------------
// Address: 0x10211E62
// Name: __WSAFDIsSet(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall __WSAFDIsSet(SOCKET fd, fd_set *a2)
{
  return __imp____WSAFDIsSet@8(fd, a2);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10198550
// Name: enum ButtonCode_t GetBaseButtonCode(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl GetBaseButtonCode(ButtonCode_t code)
{
  ButtonCode_t result; // eax

  result = code;
  if ( (unsigned int)(code - 114) <= 0x7F )
    return ((code - 114) & 0x8000001F) + 114;
  if ( (unsigned int)(code - 242) <= 0xF )
    return ((code - 242) & 0x80000003) + 242;
  if ( (unsigned int)(code - 258) <= 0x2F )
    return (code - 258) % 12 + 258;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101985C0
// Name: int GetJoystickForCode(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetJoystickForCode(ButtonCode_t code)
{
  if ( (unsigned int)(code - 114) > 0xBF )
    return 0;
  if ( code <= JOYSTICK_LAST_BUTTON )
    return (code - 114) / 32;
  if ( (unsigned int)(code - 242) > 0xF )
    return (code - 258) / 12;
  return (code - 242) / 4;
}

//------------------------------------------------------------------------------
// Address: 0x10198630
// Name: escape
// Source: json
//------------------------------------------------------------------------------
void __cdecl escape()
{
  IEngineVGuiInternal *v0; // eax

  v0 = EngineVGui();
  v0->HideGameUI(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10198640
// Name: class KeyValues __near * GetDefaultKeyBindings(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__usercall GetDefaultKeyBindings@<eax>(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  KeyValues *v3; // eax
  void *v4; // edi
  int v6; // esi
  void *v7; // ebx
  const char *i; // esi
  const char *v9; // esi
  char token[1024]; // [esp+0h] [ebp-60Ch] BYREF
  char szFileName[260]; // [esp+400h] [ebp-20Ch] BYREF
  char szKeyName[260]; // [esp+504h] [ebp-108h] BYREF
  KeyValues *defaults; // [esp+608h] [ebp-4h]

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    defaults = KeyValues::KeyValues(this: v3, setName: "defaults");
  else
    defaults = nullptr;
  V_snprintf(pDest: szFileName, maxLen: 260, pFormat: "%skb_def.lst", "scripts/");
  v4 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, _DWORD, int))g_pFileSystem->Open)(
                 a1: &g_pFileSystem->IBaseFileSystem,
                 a2: szFileName,
                 a3: "r",
                 a4: 0,
                 a5: a2);
  if ( v4 != nullptr )
  {
    v6 = ((int (__thiscall *)(IBaseFileSystem *, void *, int, int))g_pFileSystem->Size_2)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: v4,
           a3,
           a4: a1);
    v7 = MemAlloc_Alloc(nSize: v6 + 1);
    g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v7, a3: v6, a4: v4);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    *((_BYTE *)v7 + v6) = 0;
    for ( i = COM_ParseFile(data: (const char *)v7, token, maxtoken: 1024);
          strlen(token) != 0;
          i = COM_ParseFile(data: v9, token, maxtoken: 1024) )
    {
      V_strncpy(pDest: szKeyName, pSrc: token, maxLen: 256);
      v9 = COM_ParseFile(data: i, token, maxtoken: 1024);
      if ( strlen(token) == 0 )
        break;
      KeyValues::SetString(this: defaults, keyName: token, value: szKeyName);
    }
    free(pMem: v7);
    return defaults;
  }
  else
  {
    ConMsg(a1: "Couldn't open kb_def.lst\n");
    return defaults;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198800
// Name: char const __near * GetSuggestedBinding(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetSuggestedBinding(const char *command, KeyValues *defaults)
{
  const char *result; // eax
  KeyValues *FirstSubKey; // esi
  const char *String; // edi
  const char *Name; // eax

  if ( defaults == nullptr )
    return nullptr;
  result = KeyValues::GetString(this: defaults, keyName: command, defaultValue: nullptr);
  if ( result == nullptr )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: defaults);
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( V_stristr(pStr: Name, pSearch: command) != nullptr )
          break;
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        if ( FirstSubKey == nullptr )
          return nullptr;
      }
      return String;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10198870
// Name: int Key_CountBindings(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Key_CountBindings()
{
  int result; // eax
  KeyInfo_t *v1; // ecx
  char *m_pKeyBinding; // edx
  char *v3; // edx
  char *v4; // edx
  char *v5; // edx
  char *v6; // edx

  result = 0;
  v1 = &s_KeyContext.m_pKeyInfo[1];
  do
  {
    m_pKeyBinding = v1[-1].m_pKeyBinding;
    if ( m_pKeyBinding != nullptr && *m_pKeyBinding != 0 )
      ++result;
    if ( v1->m_pKeyBinding != nullptr && *v1->m_pKeyBinding != 0 )
      ++result;
    v3 = v1[1].m_pKeyBinding;
    if ( v3 != nullptr && *v3 != 0 )
      ++result;
    v4 = v1[2].m_pKeyBinding;
    if ( v4 != nullptr && *v4 != 0 )
      ++result;
    v5 = v1[3].m_pKeyBinding;
    if ( v5 != nullptr && *v5 != 0 )
      ++result;
    v6 = v1[4].m_pKeyBinding;
    if ( v6 != nullptr && *v6 != 0 )
      ++result;
    v1 += 6;
  }
  while ( (int)v1 < (int)&s_KeyContext.m_nTrapKey );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10198970
// Name: int Key_CodeForBinding(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Key_CodeForBinding(const char *pBinding, int userId, int iStartCount, int iAllowJoystick)
{
  const char *v4; // eax
  const char *v6; // edi
  int v7; // esi
  int iCount; // [esp+14h] [ebp+8h]

  v4 = pBinding;
  if ( pBinding != nullptr )
  {
LABEL_2:
    v6 = v4;
    if ( *v4 == 43 )
      v6 = v4 + 1;
    v7 = 0;
    iCount = 0;
    while ( 1 )
    {
      if ( IsKeyBoundedToBinding(i: v7, pBind: v6) )
      {
        if ( iAllowJoystick < 0 )
          goto LABEL_11;
        if ( iAllowJoystick != 0 )
        {
          if ( (unsigned int)(v7 - 114) <= 0xBF )
          {
LABEL_11:
            if ( iCount == iStartCount )
              return v7;
            ++iCount;
          }
        }
        else if ( (unsigned int)(v7 - 114) > 0xBF )
        {
          goto LABEL_11;
        }
      }
      if ( ++v7 >= 306 )
      {
        if ( _V_stricmp(s1: "duck", s2: v6) == 0 )
        {
          iStartCount = iCount;
          iAllowJoystick = -1;
          v4 = "toggle_duck";
          goto LABEL_2;
        }
        if ( _V_stricmp(s1: "zoom", s2: v6) == 0 )
        {
          iAllowJoystick = -1;
          iStartCount = iCount;
          v4 = "toggle_zoom";
          goto LABEL_2;
        }
        return -1;
      }
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10198A30
// Name: char const __near * Key_BindingForKey(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Key_BindingForKey(ButtonCode_t code)
{
  if ( (unsigned int)code > BUTTON_CODE_LAST )
    return nullptr;
  else
    return s_KeyContext.m_pKeyInfo[code].m_pKeyBinding;
}

//------------------------------------------------------------------------------
// Address: 0x10198A50
// Name: key_listboundkeys
// Source: json
//------------------------------------------------------------------------------
void __cdecl key_listboundkeys()
{
  ButtonCode_t i; // esi
  char *m_pKeyBinding; // eax
  const char *(__thiscall *ButtonCodeToString)(IInputSystem *, ButtonCode_t); // eax
  const char *v3; // eax
  int JoystickForCode; // eax
  const char *v5; // [esp-8h] [ebp-10h]
  char *v6; // [esp-4h] [ebp-Ch]

  for ( i = BUTTON_CODE_NONE; i < BUTTON_CODE_LAST; ++i )
  {
    if ( (unsigned int)i <= BUTTON_CODE_LAST )
    {
      m_pKeyBinding = s_KeyContext.m_pKeyInfo[i].m_pKeyBinding;
      if ( m_pKeyBinding != nullptr && *m_pKeyBinding != 0 )
      {
        v6 = s_KeyContext.m_pKeyInfo[i].m_pKeyBinding;
        ButtonCodeToString = g_pInputSystem->ButtonCodeToString;
        if ( (unsigned int)(i - 114) <= 0xBF )
        {
          v5 = (const char *)((int (__stdcall *)(ButtonCode_t))ButtonCodeToString)(a1: i);
          JoystickForCode = GetJoystickForCode(code: i);
          ConMsg(a1: "[%d:%d]\"%s\" = \"%s\"\n", i, JoystickForCode, v5, v6);
        }
        else
        {
          v3 = (const char *)((int (__stdcall *)(ButtonCode_t))ButtonCodeToString)(a1: i);
          ConMsg(a1: "\"%s\" = \"%s\"\n", v3, v6);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198AD0
// Name: key_findbinding
// Source: json
//------------------------------------------------------------------------------
void __cdecl key_findbinding(const CCommand *args)
{
  const char *v1; // eax
  ButtonCode_t v2; // esi
  char *m_pKeyBinding; // edi
  int JoystickForCode; // eax
  const char *v5; // [esp-14h] [ebp-14h]
  const CCommand *argsa; // [esp+8h] [ebp+8h]

  if ( args->m_nArgc == 2 && (v1 = args->m_ppArgv[1], argsa = (const CCommand *)v1, v1 != nullptr) && *v1 != 0 )
  {
    v2 = BUTTON_CODE_NONE;
    while ( 1 )
    {
      if ( (unsigned int)v2 <= BUTTON_CODE_LAST )
      {
        m_pKeyBinding = s_KeyContext.m_pKeyInfo[v2].m_pKeyBinding;
        if ( m_pKeyBinding != nullptr && *m_pKeyBinding != 0 && _V_strstr(s1: m_pKeyBinding, search: v1) != nullptr )
        {
          v5 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v2);
          if ( (unsigned int)(v2 - 114) <= 0xBF )
          {
            JoystickForCode = GetJoystickForCode(code: v2);
            ConMsg(a1: "[%d] \"%s\" = \"%s\"\n", JoystickForCode, v5, m_pKeyBinding);
          }
          else
          {
            ConMsg(a1: "\"%s\" = \"%s\"\n", v5, m_pKeyBinding);
          }
        }
      }
      if ( ++v2 >= BUTTON_CODE_LAST )
        break;
      v1 = (const char *)argsa;
    }
  }
  else
  {
    ConMsg(a1: "usage:  key_findbinding substring\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198B90
// Name: void Key_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_Init()
{
  ReadCheatCommandsFromFile(pchFileName: "scripts/cheatcodes.txt");
  ReadCheatCommandsFromFile(pchFileName: "scripts/mod_cheatcodes.txt");
}

//------------------------------------------------------------------------------
// Address: 0x10198BE0
// Name: void Key_StartTrapMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_StartTrapMode()
{
  if ( !s_KeyContext.m_bTrapMode )
  {
    *(_WORD *)&s_KeyContext.m_bTrapMode = 1;
    s_KeyContext.m_nTrapKeyUp = BUTTON_CODE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198C00
// Name: bool Key_CheckDoneTrapping(enum ButtonCode_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Key_CheckDoneTrapping(ButtonCode_t *code)
{
  if ( s_KeyContext.m_bTrapMode || !s_KeyContext.m_bDoneTrapping )
    return 0;
  *code = s_KeyContext.m_nTrapKey;
  s_KeyContext.m_nTrapKey = BUTTON_CODE_INVALID;
  s_KeyContext.m_bDoneTrapping = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10198C40
// Name: FilterTrappedKey
// Source: json
//------------------------------------------------------------------------------
char __usercall FilterTrappedKey@<al>(ButtonCode_t code@<eax>, bool bDown@<cl>)
{
  if ( s_KeyContext.m_nTrapKeyUp != code || bDown )
  {
    if ( s_KeyContext.m_bTrapMode && bDown )
    {
      s_KeyContext.m_nTrapKey = code;
      s_KeyContext.m_nTrapKeyUp = code;
      *(_WORD *)&s_KeyContext.m_bTrapMode = 256;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    s_KeyContext.m_nTrapKeyUp = BUTTON_CODE_INVALID;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198C80
// Name: HandleToolKey
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HandleToolKey(const InputEvent_t *event)
{
  IToolSystem *v1; // eax

  if ( event->m_nType == 202 || event->m_nType == 203 )
    return false;
  v1 = toolframework->GetTopmostTool(this: toolframework);
  return v1 != nullptr && v1->TrapKey(this: v1, a2: (ButtonCode_t)event->m_nData, a3: event->m_nType != 1);
}

//------------------------------------------------------------------------------
// Address: 0x10198CE0
// Name: HandleVGuiKey
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HandleVGuiKey(const InputEvent_t *event)
{
  IEngineVGuiInternal *v1; // eax

  v1 = EngineVGui();
  return v1->Key_Event(this: v1, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x10198D00
// Name: HandleScaleformKey
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HandleScaleformKey(const InputEvent_t *event)
{
  int m_nData; // esi
  bool result; // al

  m_nData = event->m_nData;
  result = g_pScaleformUI->HandleInputEvent(this: g_pScaleformUI, a2: event);
  if ( m_nData == 109 || m_nData == 110 || m_nData == 111 )
    return false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10198D30
// Name: HandleClientKey
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HandleClientKey(const InputEvent_t *event)
{
  int m_nType; // eax

  m_nType = event->m_nType;
  return event->m_nType != 203
      && m_nType != 202
      && g_ClientDLL != nullptr
      && g_ClientDLL->IN_KeyEvent(
           this: g_ClientDLL,
           a2: m_nType != 1,
           a3: (ButtonCode_t)event->m_nData,
           a4: s_KeyContext.m_pKeyInfo[event->m_nData].m_pKeyBinding) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10198D90
// Name: HandleGameUIKey
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HandleGameUIKey(const InputEvent_t *event)
{
  return g_ClientDLL != nullptr && g_ClientDLL->HandleGameUIEvent(this: g_ClientDLL, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x10198DC0
// Name: HandleEngineKey
// Source: json
//------------------------------------------------------------------------------
char __cdecl HandleEngineKey(const InputEvent_t *event)
{
  int m_nType; // eax
  bool v2; // bl
  ButtonCode_t m_nData; // esi
  int JoystickForCode; // eax
  char *m_pKeyBinding; // edi
  char v6; // al
  char *v7; // ecx
  vgui::CTreeViewListControl *v8; // ecx
  ECommandTarget_t TraceType; // eax
  ECommandTarget_t v10; // eax
  char *v12; // [esp-14h] [ebp-414h]
  const char *v13; // [esp-Ch] [ebp-40Ch]
  char cmd[1024]; // [esp+0h] [ebp-400h] BYREF

  m_nType = event->m_nType;
  if ( event->m_nType == 203 || m_nType == 202 )
    return 0;
  v2 = m_nType != 1;
  m_nData = event->m_nData;
  if ( m_nType != 1
    && (unsigned int)(m_nData - 114) <= 0xBF
    && (unsigned int)(m_nData - 258) > 0x2F
    && s_KeyContext.m_pKeyInfo[m_nData].m_pKeyBinding == nullptr )
  {
    v13 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: m_nData);
    JoystickForCode = GetJoystickForCode(code: m_nData);
    _ConDMsg(a1: "[joy %d]%s is unbound.\n", JoystickForCode, v13);
  }
  m_pKeyBinding = s_KeyContext.m_pKeyInfo[m_nData].m_pKeyBinding;
  if ( m_pKeyBinding != nullptr )
  {
    v6 = *m_pKeyBinding;
    if ( *m_pKeyBinding != 0 )
    {
      if ( v2 )
      {
        if ( v6 == 43 )
        {
          V_snprintf(pDest: cmd, maxLen: 1024, pFormat: "%s %i\n", m_pKeyBinding, m_nData);
          v7 = cmd;
          v12 = cmd;
          goto LABEL_23;
        }
        if ( _V_stricmp(s1: m_pKeyBinding, s2: "toggleconsole") != 0
          || (*((_BYTE *)&s_KeyContext.m_pKeyInfo[81] + 4) & 0x10) == 0
          && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[79] + 4) & 0x10) == 0
          && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[83] + 4) & 0x10) == 0
          && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[82] + 4) & 0x10) == 0
          && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[80] + 4) & 0x10) == 0
          && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[84] + 4) & 0x10) == 0 )
        {
          TraceType = CTraceFilter::GetTraceType(this: v8);
          Cbuf_AddText(eTarget: TraceType, pText: m_pKeyBinding, nTickDelay: 0);
          v12 = "\n";
          goto LABEL_23;
        }
      }
      else if ( v6 == 43 )
      {
        V_snprintf(pDest: cmd, maxLen: 1024, pFormat: "-%s %i\n", m_pKeyBinding + 1, m_nData);
        v12 = cmd;
LABEL_23:
        v10 = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)v7);
        Cbuf_AddText(eTarget: v10, pText: v12, nTickDelay: 0);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10198F40
// Name: FilterKey
// Source: json
//------------------------------------------------------------------------------
bool __usercall FilterKey@<al>(
        const InputEvent_t *event@<eax>,
        KeyUpTarget_t target,
        bool (__cdecl *func)(const InputEvent_t *))
{
  int m_nType; // eax
  int m_nData; // esi
  bool result; // al
  int v7; // edi

  m_nType = event->m_nType;
  m_nData = event->m_nData;
  if ( (m_nType == 1 || m_nType == 202 || m_nType == 203)
    && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) & 0xF) != target
    && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) & 0xF) != 0 )
  {
    return false;
  }
  result = func(a1: event);
  v7 = event->m_nType;
  if ( v7 == 0 || v7 == 2 )
  {
    if ( result )
      *((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) ^= (target
                                                          ^ *((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4))
                                                         & 0xF;
  }
  else if ( v7 == 1 && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) & 0xF) == target )
  {
    *((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) &= 0xF0u;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10198FE0
// Name: void Key_Event(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_Event(const InputEvent_t *event)
{
  ButtonCode_t m_nData; // edi
  int m_nValue; // eax
  int m_nType; // eax
  bool v4; // cl
  IEngineVGuiInternal *v5; // eax
  IEngineVGuiInternal *v6; // eax

  m_nData = event->m_nData;
  if ( (unsigned int)(m_nData - 114) > 0xBF )
  {
    if ( in_forceuser.m_pParent != nullptr )
      m_nValue = in_forceuser.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: m_nValue);
  }
  m_nType = event->m_nType;
  if ( event->m_nType == 203
    || m_nType == 202
    || (m_nType == 0 || m_nType == 2 ? (v4 = true) : (v4 = false),
        ((*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) & 0x10) != 0) != v4
     && (*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4) ^= (*((_BYTE *)&s_KeyContext.m_pKeyInfo[m_nData] + 4)
                                                             ^ (16 * v4))
                                                            & 0x10,
         FilterTrappedKey(code: m_nData, bDown: v4) == 0)) )
  {
    v5 = EngineVGui();
    if ( v5->IsInitialized(this: v5) )
    {
      v6 = EngineVGui();
      v6->UpdateButtonState(this: v6, a2: event);
      if ( !FilterKey(event, target: KEY_UP_TOOLS, func: HandleToolKey)
        && (m_nData == KEY_ESCAPE
         || event->m_nType == 0 && m_nData == KEY_BACKQUOTE
         || !FilterKey(event, target: KEY_UP_VGUI, func: HandleVGuiKey)
         && !FilterKey(event, target: KEY_UP_SCALEFORM, func: HandleScaleformKey))
        && !FilterKey(event, target: KEY_UP_GAMEUI, func: HandleGameUIKey)
        && !FilterKey(event, target: KEY_UP_CLIENT, func: HandleClientKey)
        && (m_nData != KEY_ESCAPE || !FilterKey(event, target: KEY_UP_VGUI, func: HandleVGuiKey)) )
      {
        FilterKey(event, target: KEY_UP_ENGINE, func: (bool (__cdecl *)(const InputEvent_t *))HandleEngineKey);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199150
// Name: enum ButtonCode_t ButtonCodeToJoystickButtonCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl ButtonCodeToJoystickButtonCode(ButtonCode_t code, int nDesiredJoystick)
{
  ButtonCode_t result; // eax
  int v3; // esi

  result = code;
  if ( (unsigned int)(code - 114) <= 0xBF )
  {
    v3 = nDesiredJoystick;
    if ( nDesiredJoystick != 0 )
    {
      if ( nDesiredJoystick >= 0 )
      {
        if ( nDesiredJoystick > 3 )
          v3 = 3;
      }
      else
      {
        v3 = 0;
      }
      result = GetBaseButtonCode(code);
      if ( (unsigned int)(result - 114) > 0x7F )
      {
        if ( (unsigned int)(result - 242) > 0xF )
        {
          if ( (unsigned int)(result - 258) <= 0x2F )
            result += 12 * v3;
        }
        else
        {
          result += 4 * v3;
        }
      }
      else
      {
        result += 32 * v3;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101991C0
// Name: void Key_SetBinding(enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_SetBinding(ButtonCode_t keynum, const char *pBinding)
{
  ButtonCode_t v2; // esi
  char *m_pKeyBinding; // eax
  int v4; // ebx
  char *v5; // edi
  IScaleformUI *v6; // ecx
  IBaseClientDLL_vtbl *v7; // ebx
  int v8; // eax

  v2 = keynum;
  if ( keynum != BUTTON_CODE_INVALID )
  {
    if ( (unsigned int)(keynum - 114) <= 0xBF )
      v2 = ButtonCodeToJoystickButtonCode(code: keynum, nDesiredJoystick: 0);
    m_pKeyBinding = s_KeyContext.m_pKeyInfo[v2].m_pKeyBinding;
    if ( m_pKeyBinding != nullptr )
    {
      if ( _V_strcmp(s1: m_pKeyBinding, s2: pBinding) == 0 )
        return;
      free(pMem: s_KeyContext.m_pKeyInfo[v2].m_pKeyBinding);
      s_KeyContext.m_pKeyInfo[v2].m_pKeyBinding = nullptr;
    }
    v4 = _V_strlen(str: pBinding);
    v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
    V_strncpy(pDest: v5, pSrc: pBinding, maxLen: v4 + 1);
    v5[v4] = 0;
    v6 = g_pScaleformUI;
    s_KeyContext.m_pKeyInfo[v2].m_pKeyBinding = v5;
    if ( v6 != nullptr )
      v6->UpdateBindingForButton(this: v6, a2: v2, a3: pBinding);
    if ( g_ClientDLL != nullptr )
    {
      v7 = g_ClientDLL->__vftable;
      v8 = ((int (__thiscall *)(IInputSystem *, ButtonCode_t, char *))g_pInputSystem->ButtonCodeToString)(
             a1: g_pInputSystem,
             a2: v2,
             a3: v5);
      ((void (__thiscall *)(IBaseClientDLL *, ButtonCode_t, int))v7->OnKeyBindingChanged)(
        a1: g_ClientDLL,
        a2: v2,
        a3: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101992A0
// Name: unbind
// Source: json
//------------------------------------------------------------------------------
void __cdecl unbind(const CCommand *args)
{
  ButtonCode_t v1; // eax

  if ( args->m_nArgc == 2 )
  {
    v1 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: args->m_ppArgv[1]);
    if ( v1 == BUTTON_CODE_INVALID )
    {
      if ( args->m_nArgc > 1 )
        ConMsg(a1: "\"%s\" isn't a valid key\n", args->m_ppArgv[1]);
      else
        ConMsg(a1: "\"%s\" isn't a valid key\n", defaultValue);
    }
    else if ( v1 == KEY_ESCAPE )
    {
      ConMsg(a1: "Can't unbind ESCAPE key\n");
    }
    else
    {
      Key_SetBinding(keynum: v1, pBinding: defaultValue);
    }
  }
  else
  {
    ConMsg(a1: "unbind <key> : remove commands from a key\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199340
// Name: unbindall
// Source: json
//------------------------------------------------------------------------------
void __cdecl unbindall()
{
  ButtonCode_t i; // esi

  for ( i = BUTTON_CODE_NONE; i < BUTTON_CODE_LAST; ++i )
  {
    if ( s_KeyContext.m_pKeyInfo[i].m_pKeyBinding != nullptr && i != KEY_ESCAPE && i != KEY_BACKQUOTE )
      Key_SetBinding(keynum: i, pBinding: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199370
// Name: bind_0
// Source: json
//------------------------------------------------------------------------------
void __cdecl bind_0(const CCommand *args)
{
  int m_nArgc; // edi
  const char *v2; // eax
  ButtonCode_t v3; // eax
  ButtonCode_t v4; // ebx
  char *m_pKeyBinding; // ebx
  const char *v6; // esi
  int v7; // esi
  const char **v8; // ebx
  const char *v9; // eax
  char cmd[1024]; // [esp+8h] [ebp-404h] BYREF
  ButtonCode_t b; // [esp+408h] [ebp-4h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 2 || m_nArgc == 3 )
  {
    v2 = defaultValue;
    if ( m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    v3 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: v2);
    v4 = v3;
    b = v3;
    if ( v3 == BUTTON_CODE_INVALID )
    {
      if ( args->m_nArgc > 1 )
        ConMsg(a1: "\"%s\" isn't a valid key\n", args->m_ppArgv[1]);
      else
        ConMsg(a1: "\"%s\" isn't a valid key\n", defaultValue);
    }
    else if ( m_nArgc == 2 )
    {
      if ( (unsigned int)(v3 - 114) <= 0xBF )
      {
        b = ButtonCodeToJoystickButtonCode(code: v3, nDesiredJoystick: 0);
        v4 = b;
      }
      m_pKeyBinding = s_KeyContext.m_pKeyInfo[v4].m_pKeyBinding;
      if ( m_pKeyBinding != nullptr )
      {
        if ( args->m_nArgc > 1 )
          v6 = args->m_ppArgv[1];
        else
          v6 = defaultValue;
        ConMsg(a1: "\"%s\" = \"%s\"\n", v6, m_pKeyBinding);
      }
      else if ( args->m_nArgc > 1 )
      {
        ConMsg(a1: "\"%s\" is not bound\n", args->m_ppArgv[1]);
      }
      else
      {
        ConMsg(a1: "\"%s\" is not bound\n", defaultValue);
      }
    }
    else if ( v3 == KEY_ESCAPE )
    {
      V_strncpy(pDest: cmd, pSrc: "cancelselect", maxLen: 1024);
      Key_SetBinding(keynum: KEY_ESCAPE, pBinding: cmd);
    }
    else
    {
      v7 = 2;
      cmd[0] = 0;
      if ( m_nArgc > 2 )
      {
        v8 = &args->m_ppArgv[2];
        do
        {
          if ( v7 > 2 )
            V_strncat(pDest: cmd, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
          if ( v7 < 0 || v7 >= args->m_nArgc )
            v9 = defaultValue;
          else
            v9 = *v8;
          V_strncat(pDest: cmd, pSrc: v9, destBufferSize: 0x400u, max_chars_to_copy: -1);
          ++v7;
          ++v8;
        }
        while ( v7 < m_nArgc );
        v4 = b;
      }
      Key_SetBinding(keynum: v4, pBinding: cmd);
    }
  }
  else
  {
    ConMsg(a1: "bind <key> [command] : attach a command to a key\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199560
// Name: char const __near * Key_NameForBinding(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Key_NameForBinding(const char *pBinding, int userId, int iStartCount, int iAllowJoystick)
{
  int v4; // eax
  ButtonCode_t v5; // ebx
  const char *v6; // edi

  v4 = Key_CodeForBinding(pBinding, userId, iStartCount, iAllowJoystick);
  v5 = v4;
  if ( pBinding == nullptr || v4 == -1 )
    return nullptr;
  v6 = pBinding;
  if ( *pBinding == 43 )
    v6 = pBinding + 1;
  if ( IsKeyBoundedToBinding(i: v4, pBind: v6) )
    return g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v5);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101995C0
// Name: public: CFmtStrN<2048>::CFmtStrN<2048>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<2048> *CFmtStrN<2048>::CFmtStrN<2048>(CFmtStrN<2048> *this, const char *pszFormat, ...)
{
  CFmtStrN<2048> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<2048>_vtbl *)&CFmtStrN<2048>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 2047, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[2047] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<2048>::CFmtStrN<2048>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<2048>::CFmtStrN<2048>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10199630
// Name: void Key_ForceBind_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Key_ForceBind_f(int a1@<ebx>, const CCommand *args)
{
  const CCommand *v2; // edi
  int m_nArgc; // esi
  int v4; // eax
  const char *v5; // ebx
  int v6; // eax
  ButtonCode_t v7; // esi
  const char *v8; // edi
  const char *v9; // edi
  const char *SuggestedBinding; // esi
  ButtonCode_t v11; // eax
  ButtonCode_t v12; // edi
  ButtonCode_t v13; // eax
  ButtonCode_t v14; // edi
  char *m_pKeyBinding; // eax
  ButtonCode_t v16; // esi
  const char *v17; // eax
  char *v18; // ecx
  int v19; // eax
  ButtonCode_t v20; // esi
  const char *v21; // edi
  int argc; // [esp+8h] [ebp-18h]
  KeyValues *defaults; // [esp+Ch] [ebp-14h]
  const char **v24; // [esp+10h] [ebp-10h]
  int arg; // [esp+14h] [ebp-Ch]
  Color unboundColor; // [esp+18h] [ebp-8h] BYREF
  Color boundColor; // [esp+1Ch] [ebp-4h] BYREF

  v2 = args;
  m_nArgc = args->m_nArgc;
  argc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    defaults = GetDefaultKeyBindings(a1, a2: (int)args, a3: m_nArgc);
    v4 = 1;
    boundColor = (Color)-12517632;
    unboundColor = (Color)-12582657;
    arg = 1;
    if ( m_nArgc > 1 )
    {
      v24 = &args->m_ppArgv[1];
      while ( 1 )
      {
        v5 = v4 < 0 || v4 >= v2->m_nArgc ? defaultValue : *v24;
        v6 = Key_CodeForBinding(pBinding: v5, userId: -1, iStartCount: 0, iAllowJoystick: -1);
        v7 = v6;
        if ( v5 == nullptr || v6 == -1 )
          goto LABEL_15;
        v8 = v5;
        if ( *v5 == 43 )
          v8 = v5 + 1;
        if ( IsKeyBoundedToBinding(i: v6, pBind: v8) )
          v9 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v7);
        else
LABEL_15:
          v9 = nullptr;
        SuggestedBinding = GetSuggestedBinding(command: v5, defaults);
        if ( SuggestedBinding != nullptr )
        {
          if ( v9 == nullptr )
          {
            v13 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: SuggestedBinding);
            v14 = v13;
            if ( (unsigned int)v13 > BUTTON_CODE_LAST )
              m_pKeyBinding = nullptr;
            else
              m_pKeyBinding = s_KeyContext.m_pKeyInfo[v13].m_pKeyBinding;
            if ( v14 == BUTTON_CODE_INVALID || m_pKeyBinding != nullptr && *m_pKeyBinding != 0 )
            {
              v16 = v14 + 1;
              if ( v14 + 1 > 106 )
                v16 = KEY_0;
              if ( v16 != v14 )
              {
                while ( 1 )
                {
                  v17 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v16);
                  if ( (unsigned int)v16 > BUTTON_CODE_LAST )
                    break;
                  v18 = s_KeyContext.m_pKeyInfo[v16].m_pKeyBinding;
                  if ( v18 == nullptr || *v18 == 0 )
                    break;
                  if ( ++v16 > KEY_SCROLLLOCKTOGGLE )
                    v16 = KEY_0;
                  if ( v16 == v14 )
                    goto LABEL_40;
                }
                ConColorMsg(a1: &boundColor, a2: "Bound \"%s\" to key %s\n", v5, v17);
                Key_SetBinding(keynum: v16, pBinding: v5);
              }
            }
            else
            {
              ConColorMsg(a1: &boundColor, a2: "Bound \"%s\" to key %s\n", v5, SuggestedBinding);
              Key_SetBinding(keynum: v14, pBinding: v5);
            }
LABEL_40:
            v19 = Key_CodeForBinding(pBinding: v5, userId: -1, iStartCount: 0, iAllowJoystick: -1);
            v20 = v19;
            if ( v5 == nullptr || v19 == -1 )
              goto LABEL_46;
            v21 = v5;
            if ( *v5 == 43 )
              v21 = v5 + 1;
            if ( !IsKeyBoundedToBinding(i: v19, pBind: v21)
              || g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v20) == nullptr )
            {
LABEL_46:
              ConColorMsg(a1: &unboundColor, a2: "Unable to bind \"%s\" to a key\n", v5);
            }
          }
        }
        else if ( v9 != nullptr )
        {
          v11 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: v9);
          v12 = v11;
          if ( v11 != BUTTON_CODE_INVALID && v11 != KEY_ESCAPE )
          {
            ConColorMsg(a1: &boundColor, a2: "Unbound obsolete command \"%s\"\n", v5);
            Key_SetBinding(keynum: v12, pBinding: defaultValue);
          }
        }
        ++v24;
        if ( ++arg >= argc )
          break;
        v2 = args;
        v4 = arg;
      }
    }
    KeyValues::deleteThis(this: defaults);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199870
// Name: void Key_WriteBindings(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Key_WriteBindings(CUtlBuffer *buf, int iSplitscreenSlot)
{
  int v2; // edx
  int *p_m_nGrowSize; // eax
  ButtonCode_t v4; // esi
  char *m_pKeyBinding; // ebx
  const char *v6; // edi
  int JoystickForCode; // esi
  CFmtStrN<2048> *v8; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v9; // ebx
  int m_Size; // edi
  CUtlString *m_pMemory; // esi
  const char *v12; // eax
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *v13; // esi
  int i; // ebx
  CUtlBinaryBlock *v15; // eax
  CFmtStrN<2048> v16; // [esp+0h] [ebp-84Ch] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > deferred[2]; // [esp+80Ch] [ebp-40h] BYREF
  char v18; // [esp+834h] [ebp-18h] BYREF
  CUtlString str; // [esp+838h] [ebp-14h] BYREF
  int nSlot; // [esp+848h] [ebp-4h]

  v2 = 1;
  p_m_nGrowSize = &deferred[0].m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v2;
  }
  while ( v2 >= 0 );
  v4 = BUTTON_CODE_NONE;
  nSlot = 0;
  do
  {
    m_pKeyBinding = s_KeyContext.m_pKeyInfo[v4].m_pKeyBinding;
    if ( m_pKeyBinding != nullptr && *m_pKeyBinding != 0 )
    {
      v6 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v4);
      JoystickForCode = GetJoystickForCode(code: v4);
      if ( iSplitscreenSlot >= 0 )
      {
        if ( iSplitscreenSlot != JoystickForCode )
          goto LABEL_14;
LABEL_8:
        CUtlBuffer::Printf(this: buf, pFmt: "bind \"%s\" \"%s\"\n", v6, m_pKeyBinding);
        goto LABEL_14;
      }
      if ( JoystickForCode == 0 )
        goto LABEL_8;
      CUtlString::CUtlString(this: &str);
      v8 = CFmtStrN<2048>::CFmtStrN<2048>(
             this: &v16,
             pszFormat: "cmd%d bind \"%s\" \"%s\"\n",
             JoystickForCode + 1,
             v6,
             m_pKeyBinding);
      CUtlString::operator=(this: &str, src: v8->m_szBuf);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        this: &deferred[JoystickForCode],
        elem: deferred[JoystickForCode].m_Size,
        src: &str);
      str.m_Storage.m_nActualLength = 0;
      if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( str.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
          str.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        str.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
LABEL_14:
    v4 = nSlot + 1;
    nSlot = v4;
  }
  while ( v4 < BUTTON_CODE_LAST );
  nSlot = 1;
  if ( host_state.max_splitscreen_players > 1 )
  {
    v9 = &deferred[1];
    do
    {
      m_Size = v9->m_Size;
      if ( m_Size > 0 )
      {
        m_pMemory = v9->m_Memory.m_pMemory;
        do
        {
          v12 = CUtlString::operator char const *(this: m_pMemory);
          CUtlBuffer::Printf(this: buf, pFmt: "%s", v12);
          ++m_pMemory;
          --m_Size;
        }
        while ( m_Size != 0 );
      }
      ++v9;
      ++nSlot;
    }
    while ( nSlot < host_state.max_splitscreen_players );
  }
  v13 = (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&v18;
  for ( i = 1; i >= 0; --i )
  {
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: --v13);
    if ( v13->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v13->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13->m_Memory.m_pMemory);
        v13->m_Memory.m_pMemory = nullptr;
      }
      v13->m_Memory.m_nAllocationCount = 0;
    }
    v15 = v13->m_Memory.m_pMemory;
    v13->m_pElements = v13->m_Memory.m_pMemory;
    if ( v13->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v15 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
        v13->m_Memory.m_pMemory = nullptr;
      }
      v13->m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021202E
// Name: bind(x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall bind(SOCKET s, const struct sockaddr *name, int namelen)
{
  return __imp__bind@12(s, name, namelen);
}

//------------------------------------------------------------------------------
// Address: 0x10212034
// Name: __WSAFDIsSet(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall __WSAFDIsSet(SOCKET fd, fd_set *a2)
{
  return __imp____WSAFDIsSet@8(fd, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1021203A
// Name: select(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const struct timeval *timeout)
{
  return __imp__select@20(nfds, readfds, writefds, exceptfds, timeout);
}

} // namespace engine_xlsp
