// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/console.cpp
// Functions: 41
// ============================================================

#include "engine\console.h"

//------------------------------------------------------------------------------
// Address: 0x1008A340
// Name: public: void CUtlMemory<struct CConPanel::CNotifyText,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CConPanel::CNotifyText,int>::Grow(CUtlMemory<NetMessageCvar_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  NetMessageCvar_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 520 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (NetMessageCvar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (NetMessageCvar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADA40
// Name: GetTimestampString
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetTimestampString()
{
  tm today; // [esp+0h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &today);
  V_snprintf(
    pDest: string,
    maxLen: 128,
    pFormat: "%02i/%02i/%04i - %02i:%02i:%02i",
    today.tm_mon + 1,
    today.tm_mday,
    today.tm_year + 1900,
    today.tm_hour,
    today.tm_min,
    today.tm_sec);
  return string;
}

//------------------------------------------------------------------------------
// Address: 0x100ADA90
// Name: void Con_HideConsole_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_HideConsole_f()
{
  IEngineVGuiInternal *v0; // eax
  IEngineVGuiInternal *v1; // eax

  v0 = EngineVGui();
  if ( v0->IsConsoleVisible(this: v0) )
  {
    v1 = EngineVGui();
    v1->HideConsole(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADAC0
// Name: Con_LogLevelCallback
// Source: json
//------------------------------------------------------------------------------
char __cdecl Con_LogLevelCallback(const CLoggingSystem::LoggingChannel_t *pChannel, const char *pParameter)
{
  int v2; // esi

  if ( _V_stricmp(s1: pParameter, s2: "all") == 0 )
  {
    v2 = 0;
LABEL_9:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      _LoggingSystem_Log(
        a1: LOG_CONSOLE,
        a2: 0,
        a3: "Setting channel '%s' minimum spew level to '%s'.\n",
        pChannel->m_Name,
        pParameter);
    _LoggingSystem_SetChannelSpewLevel(a1: pChannel->m_ID, a2: v2);
    return 1;
  }
  if ( _V_stricmp(s1: pParameter, s2: "warning") == 0 )
  {
    v2 = 1;
    goto LABEL_9;
  }
  if ( _V_stricmp(s1: pParameter, s2: "error") == 0 )
  {
    v2 = 3;
    goto LABEL_9;
  }
  if ( _V_stricmp(s1: pParameter, s2: "off") == 0 )
  {
    v2 = 4;
    goto LABEL_9;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
    _LoggingSystem_Log(a1: LOG_CONSOLE, a2: 1, a3: "Unrecognized severity: %s.\n", pParameter);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ADBA0
// Name: Con_LogFlagsCallback
// Source: json
//------------------------------------------------------------------------------
char __cdecl Con_LogFlagsCallback(const CLoggingSystem::LoggingChannel_t *pChannel, const char *pParameter)
{
  const char *v3; // esi
  int v4; // edi
  int ChannelFlags; // eax
  int v6; // esi
  const char *pFlag; // [esp+0h] [ebp-4h]
  char bEnable_3; // [esp+13h] [ebp+Fh]

  if ( *pParameter == 43 )
  {
    bEnable_3 = 1;
  }
  else
  {
    if ( *pParameter != 45 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
        _LoggingSystem_Log(a1: LOG_CONSOLE, a2: 1, a3: "First character of flag specifier must be + or -.\n");
      return 0;
    }
    bEnable_3 = 0;
  }
  v3 = pParameter + 1;
  pFlag = pParameter + 1;
  if ( _V_stricmp(s1: pParameter + 1, s2: "donotecho") == 0 )
  {
    v4 = 2;
LABEL_9:
    ChannelFlags = _LoggingSystem_GetChannelFlags(a1: pChannel->m_ID);
    if ( bEnable_3 != 0 )
      v6 = v4 | ChannelFlags;
    else
      v6 = ~v4 & ChannelFlags;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_CONSOLE, a2: 0, a3: "Enabling flag '%s' on channel '%s'.\n", pFlag, pChannel->m_Name);
    _LoggingSystem_SetChannelFlags(a1: pChannel->m_ID, a2: v6);
    return 1;
  }
  if ( _V_stricmp(s1: v3, s2: "consoleonly") == 0 )
  {
    v4 = 1;
    goto LABEL_9;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
    _LoggingSystem_Log(a1: LOG_CONSOLE, a2: 1, a3: "Unrecognized flag: %s.\n", v3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ADCD0
// Name: void Con_RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_RunFrame()
{
  if ( g_pNetConsoleMgr != nullptr )
    CNetConsoleMgr::RunFrame(this: g_pNetConsoleMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100ADCE0
// Name: safestrncat
// Source: json
//------------------------------------------------------------------------------
void __usercall safestrncat(
        wchar_t *text@<ecx>,
        int maxCharactersWithNullTerminator@<edx>,
        wchar_t *add@<eax>,
        int addchars)
{
  wchar_t *v6; // eax
  int v7; // edx
  wchar_t *v8; // edi
  __int16 v9; // cx
  int v10; // eax
  wchar_t *v11; // ecx

  v6 = text;
  v7 = maxCharactersWithNullTerminator - 1;
  v8 = text + 1;
  do
    v9 = *v6++;
  while ( v9 != 0 );
  v10 = v6 - v8;
  if ( v10 < v7 )
  {
    v11 = &text[v10];
    do
    {
      ++v10;
      if ( --addchars < 0 )
        break;
      *v11++ = *add++;
    }
    while ( v10 < v7 );
    *v11 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADD40
// Name: public: virtual void CConPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::ApplySchemeSettings(CConPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_hFont = pScheme->GetFont(this: pScheme, a2: "DefaultSmallDropShadow", a3: false);
  this->m_hFontFixed = pScheme->GetFont(this: pScheme, a2: "DefaultFixedDropShadow", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100ADD90
// Name: public: void CConPanel::DrawText(unsigned long,int,int,wchar_t __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CConPanel::DrawText(CConPanel *this, unsigned int font, int x, int y, wchar_t *fmt, ...)
{
  wchar_t data[1024]; // [esp+0h] [ebp-800h] BYREF
  va_list va; // [esp+81Ch] [ebp+1Ch] BYREF

  va_start(va, fmt);
  V_snwprintf(pDest: data, maxLen: 1023, pFormat: fmt, va);
  data[1023] = 0;
  DrawColoredText(font, x, y, r: 255, g: 255, b: 255, a: 255, text: data);
}

//------------------------------------------------------------------------------
// Address: 0x100ADDF0
// Name: public: virtual void CConPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::Paint(CConPanel *this)
{
  this->DrawDebugAreas(this);
  this->DrawNotify(this);
}

//------------------------------------------------------------------------------
// Address: 0x100ADE10
// Name: public: char const __near * __near * CCommand::ArgV(void)const
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CCommand::ArgV(CCommand *this)
{
  if ( this->m_nArgc != 0 )
    return this->m_ppArgv;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100ADE20
// Name: void ConsoleLogFileCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConsoleLogFileCallback(IConVar *var)
{
  const char *v1; // eax
  int v2; // eax
  ConVarRef ref; // [esp+0h] [ebp-8h] BYREF

  v1 = var->GetName(this: var);
  ConVarRef::ConVarRef(this: &ref, pName: v1);
  if ( COM_IsValidPath(pszFilename: ref.m_pConVarState->m_Value.m_pszString) )
  {
    con_debuglog = true;
  }
  else
  {
    v2 = _CommandLine();
    con_debuglog = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-condebug") != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADE80
// Name: char const __near * GetConsoleLogFilename(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetConsoleLogFilename()
{
  char *m_pszString; // esi
  bool v1; // zf
  char *result; // eax

  if ( (con_logfile.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = con_logfile.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v1 = !COM_IsValidPath(pszFilename: m_pszString);
  result = "console.log";
  if ( !v1 )
    return m_pszString;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ADED0
// Name: Con_LogFunctionHelper
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_LogFunctionHelper(
        const CCommand *args,
        bool (__cdecl *callbackFunction)(const CLoggingSystem::LoggingChannel_t *, const char *))
{
  CCommand *v2; // edx
  int m_nArgc; // eax
  const char **m_ppArgv; // ecx
  int v5; // ebx
  int v6; // edi
  Con_LogFunctionHelper::__l5::ChannelSpecifier_t *v7; // esi
  const char *v8; // eax
  int FirstChannelID; // eax
  const CLoggingSystem::LoggingChannel_t *Channel; // esi
  int v11; // edi
  CLoggingSystem::LoggingTag_t *m_pFirstTag; // esi
  const char *m_pSpecifier; // ebx
  char v14; // al
  Con_LogFunctionHelper::__l5::ChannelSpecifier_t channelSpecifier[16]; // [esp+0h] [ebp-8Ch] BYREF
  const char *pParameter; // [esp+80h] [ebp-Ch]
  int nSpecifierCount; // [esp+84h] [ebp-8h]
  const CLoggingSystem::LoggingChannel_t *pLoggingChannel; // [esp+88h] [ebp-4h]
  int channelID; // [esp+94h] [ebp+8h]

  v2 = args;
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 3 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      _LoggingSystem_Log(
        a1: LOG_CONSOLE,
        a2: 0,
        a3: "Log Function Help: \n"
        "    log_level <channel specifiers> <level>\n"
        "    log_color <channel specifiers> <hex color>\n"
        "    log_flags <channel specifiers> <+/-flag>\n"
        "All functions are case insensitive.\n"
        "\n"
        "A channel specifier is either:\n"
        "1) tag specifiers: +/-tag1 +/-tag2 ...      // Narrows down to channels with & without given tags.\n"
        "2) channel names: name1 name2 ...           // Lists channels by name.\n"
        "\n"
        "level: all, warning, error, off             // Spews anything at or above the specified level.\n"
        "                                            // 'off' turns all spew off, 'all' turns all spew on.\n"
        "hex color: RRGGBBAA                         // A hexadecimal color value in the order RGBA.\n"
        "flag: <+/->DoNotEcho                        // Enable/disable a flag to turn off echoing to the console.\n"
        "      <+/->ConsoleOnly                      // Enable/disable a flag to send text only to the console.\n"
        "e.g.\n"
        "    log_level +console -developer warning   // Sets minimum spew level of channels with the tag\n"
        "                                            // 'console' but without the tag 'developer' to 'warning'.\n"
        "\n"
        "    log_color renderdebug bsp FFC08040      // Sets the 'renderdebug' and 'bsp' channels to the RGBA color (64, "
        "128, 192, 255).\n"
        "\n"
        "    log_flags +developer +donotecho         // Turns on the LCF_DO_NOT_ECHO flag for all channels with the 'developer' tag.\n\n");
    return;
  }
  if ( m_nArgc != 0 )
    m_ppArgv = args->m_ppArgv;
  else
    m_ppArgv = nullptr;
  v5 = m_nArgc - 2;
  pParameter = m_ppArgv[m_nArgc - 1];
  nSpecifierCount = m_nArgc - 2;
  if ( m_nArgc - 2 > 16 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_CONSOLE, a2: 1, a3: "Too many channel specifiers (max: %d).\n", 16);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      _LoggingSystem_Log(
        a1: LOG_CONSOLE,
        a2: 0,
        a3: "Log Function Help: \n"
        "    log_level <channel specifiers> <level>\n"
        "    log_color <channel specifiers> <hex color>\n"
        "    log_flags <channel specifiers> <+/-flag>\n"
        "All functions are case insensitive.\n"
        "\n"
        "A channel specifier is either:\n"
        "1) tag specifiers: +/-tag1 +/-tag2 ...      // Narrows down to channels with & without given tags.\n"
        "2) channel names: name1 name2 ...           // Lists channels by name.\n"
        "\n"
        "level: all, warning, error, off             // Spews anything at or above the specified level.\n"
        "                                            // 'off' turns all spew off, 'all' turns all spew on.\n"
        "hex color: RRGGBBAA                         // A hexadecimal color value in the order RGBA.\n"
        "flag: <+/->DoNotEcho                        // Enable/disable a flag to turn off echoing to the console.\n"
        "      <+/->ConsoleOnly                      // Enable/disable a flag to send text only to the console.\n"
        "e.g.\n"
        "    log_level +console -developer warning   // Sets minimum spew level of channels with the tag\n"
        "                                            // 'console' but without the tag 'developer' to 'warning'.\n"
        "\n"
        "    log_color renderdebug bsp FFC08040      // Sets the 'renderdebug' and 'bsp' channels to the RGBA color (64, "
        "128, 192, 255).\n"
        "\n"
        "    log_flags +developer +donotecho         // Turns on the LCF_DO_NOT_ECHO flag for all channels with the 'developer' tag.\n\n");
    return;
  }
  v6 = 1;
  pLoggingChannel = (const CLoggingSystem::LoggingChannel_t *)(m_nArgc - 1);
  if ( m_nArgc - 1 <= 1 )
  {
LABEL_23:
    FirstChannelID = _LoggingSystem_GetFirstChannelID();
    channelID = FirstChannelID;
    if ( FirstChannelID != -1 )
    {
      while ( 1 )
      {
        Channel = (const CLoggingSystem::LoggingChannel_t *)_LoggingSystem_GetChannel(a1: FirstChannelID);
        v11 = 0;
        for ( pLoggingChannel = Channel; v11 < v5; ++v11 )
        {
          if ( channelSpecifier[0].m_bIsTag )
          {
            m_pFirstTag = Channel->m_pFirstTag;
            m_pSpecifier = channelSpecifier[v11].m_pSpecifier;
            if ( m_pFirstTag != nullptr )
            {
              while ( _V_stricmp(s1: m_pFirstTag->m_pTagName, s2: m_pSpecifier) != 0 )
              {
                m_pFirstTag = m_pFirstTag->m_pNextTag;
                if ( m_pFirstTag == nullptr )
                  goto LABEL_35;
              }
              v14 = 1;
            }
            else
            {
LABEL_35:
              v14 = 0;
            }
            v5 = nSpecifierCount;
            Channel = pLoggingChannel;
            if ( channelSpecifier[v11].m_bInclude != v14 )
              break;
          }
          else if ( _V_stricmp(s1: channelSpecifier[v11].m_pSpecifier, s2: Channel->m_Name) == 0 )
          {
            break;
          }
        }
        if ( (v11 == v5) == channelSpecifier[0].m_bIsTag && !callbackFunction(a1: Channel, a2: pParameter) )
          break;
        channelID = _LoggingSystem_GetNextChannelID(a1: channelID);
        if ( channelID == -1 )
          return;
        FirstChannelID = channelID;
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
LABEL_46:
        _LoggingSystem_Log(
          a1: LOG_CONSOLE,
          a2: 0,
          a3: "Log Function Help: \n"
          "    log_level <channel specifiers> <level>\n"
          "    log_color <channel specifiers> <hex color>\n"
          "    log_flags <channel specifiers> <+/-flag>\n"
          "All functions are case insensitive.\n"
          "\n"
          "A channel specifier is either:\n"
          "1) tag specifiers: +/-tag1 +/-tag2 ...      // Narrows down to channels with & without given tags.\n"
          "2) channel names: name1 name2 ...           // Lists channels by name.\n"
          "\n"
          "level: all, warning, error, off             // Spews anything at or above the specified level.\n"
          "                                            // 'off' turns all spew off, 'all' turns all spew on.\n"
          "hex color: RRGGBBAA                         // A hexadecimal color value in the order RGBA.\n"
          "flag: <+/->DoNotEcho                        // Enable/disable a flag to turn off echoing to the console.\n"
          "      <+/->ConsoleOnly                      // Enable/disable a flag to send text only to the console.\n"
          "e.g.\n"
          "    log_level +console -developer warning   // Sets minimum spew level of channels with the tag\n"
          "                                            // 'console' but without the tag 'developer' to 'warning'.\n"
          "\n"
          "    log_color renderdebug bsp FFC08040      // Sets the 'renderdebug' and 'bsp' channels to the RGBA color (64"
          ", 128, 192, 255).\n"
          "\n"
          "    log_flags +developer +donotecho         // Turns on the LCF_DO_NOT_ECHO flag for all channels with the 'de"
          "veloper' tag.\n"
          "\n");
    }
  }
  else
  {
    v7 = channelSpecifier;
    while ( 1 )
    {
      v8 = CCommand::ArgV(this: v2)[v6];
      if ( *v8 == 43 )
      {
        ++v8;
        *(_WORD *)&v7->m_bIsTag = 257;
      }
      else if ( *v8 == 45 )
      {
        ++v8;
        *(_WORD *)&v7->m_bIsTag = 1;
      }
      else
      {
        v7->m_bIsTag = false;
      }
      v7->m_pSpecifier = v8;
      if ( v6 > 1 && v7->m_bIsTag != v7[-1].m_bIsTag )
        break;
      ++v6;
      ++v7;
      if ( v6 >= (int)pLoggingChannel )
        goto LABEL_23;
      v2 = args;
    }
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_CONSOLE,
        a2: 1,
        a3: "Cannot mix and match tag specifiers with channel name specifiers.\n");
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      goto LABEL_46;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE170
// Name: Con_LogColorCallback
// Source: json
//------------------------------------------------------------------------------
char __cdecl Con_LogColorCallback(const CLoggingSystem::LoggingChannel_t *pChannel, const char *pParameter)
{
  int color; // [esp+4h] [ebp-4h] BYREF

  V_hextobinary(in: pParameter, numchars: 8, out: (unsigned __int8 *)&color, maxoutputbytes: 4);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
    _LoggingSystem_Log(
      a1: LOG_CONSOLE,
      a2: 0,
      a3: "Setting channel '%s' color to %08X.\n",
      pChannel->m_Name,
      _byteswap_ulong(color));
  _LoggingSystem_SetChannelColor(a1: pChannel->m_ID, a2: color);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AE1E0
// Name: void Con_LogLevel_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_LogLevel_f(const CCommand *args)
{
  Con_LogFunctionHelper(
    args,
    callbackFunction: (bool (__cdecl *)(const CLoggingSystem::LoggingChannel_t *, const char *))Con_LogLevelCallback);
}

//------------------------------------------------------------------------------
// Address: 0x100AE200
// Name: void Con_LogColor_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_LogColor_f(const CCommand *args)
{
  Con_LogFunctionHelper(
    args,
    callbackFunction: (bool (__cdecl *)(const CLoggingSystem::LoggingChannel_t *, const char *))Con_LogColorCallback);
}

//------------------------------------------------------------------------------
// Address: 0x100AE220
// Name: void Con_LogFlags_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_LogFlags_f(const CCommand *args)
{
  Con_LogFunctionHelper(
    args,
    callbackFunction: (bool (__cdecl *)(const CLoggingSystem::LoggingChannel_t *, const char *))Con_LogFlagsCallback);
}

//------------------------------------------------------------------------------
// Address: 0x100AE240
// Name: void Con_LogDumpChannels_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_LogDumpChannels_f()
{
  int v0; // ebx
  int Channel; // esi
  int v2; // eax
  const char *v3; // edi
  void (*v4)(int, _DWORD, const char *, ...); // edi
  int i; // esi
  const char *v6; // [esp-Ch] [ebp-81Ch]
  char buf[2048]; // [esp+8h] [ebp-808h] BYREF
  unsigned int v8; // [esp+808h] [ebp-8h]
  int nChannelCount; // [esp+80Ch] [ebp-4h]

  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
    _LoggingSystem_Log(
      a1: LOG_CONSOLE,
      a2: 0,
      a3: "%-4s    %-32s    %-10s    %-10s    %-32s    %-32s\n",
      "ID",
      "Channel Name",
      "Severity",
      "Color",
      "Flags",
      "Tags");
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
    _LoggingSystem_Log(
      a1: LOG_CONSOLE,
      a2: 0,
      a3: "------------------------------------------------------------------------------------------------------------------"
      "----------------------------------\n");
  v0 = 0;
  nChannelCount = _LoggingSystem_GetChannelCount();
  if ( nChannelCount > 0 )
  {
    do
    {
      Channel = _LoggingSystem_GetChannel(a1: v0);
      v2 = *(_DWORD *)(Channel + 8);
      if ( v2 < 4 )
      {
        if ( v2 < 3 )
        {
          v3 = "warning";
          if ( v2 < 1 )
            v3 = "all";
        }
        else
        {
          v3 = "error";
        }
      }
      else
      {
        v3 = "off";
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      {
        v8 = *(_DWORD *)(Channel + 12);
        v6 = v3;
        v4 = (void (*)(int, _DWORD, const char *, ...))_LoggingSystem_Log;
        _LoggingSystem_Log(
          a1: LOG_CONSOLE,
          a2: 0,
          a3: "%-4d    %-32s    %-10s    0x%08X    ",
          v0,
          (const char *)(Channel + 16),
          v6,
          _byteswap_ulong(v8));
      }
      else
      {
        v4 = (void (*)(int, _DWORD, const char *, ...))_LoggingSystem_Log;
      }
      buf[0] = 0;
      if ( (*(_BYTE *)(Channel + 4) & 1) != 0 )
        V_strncat(pDest: buf, pSrc: "[ConsoleOnly]", destBufferSize: 0x800u, max_chars_to_copy: -1);
      if ( (*(_BYTE *)(Channel + 4) & 2) != 0 )
        V_strncat(pDest: buf, pSrc: "[DoNotEcho]", destBufferSize: 0x800u, max_chars_to_copy: -1);
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
        v4(a1: LOG_CONSOLE, a2: 0, a3: "%-32s    ", buf);
      buf[0] = 0;
      for ( i = *(_DWORD *)(Channel + 48); i != 0; i = *(_DWORD *)(i + 4) )
      {
        V_strncat(pDest: buf, pSrc: "[", destBufferSize: 0x800u, max_chars_to_copy: -1);
        V_strncat(pDest: buf, pSrc: *(const char **)i, destBufferSize: 0x800u, max_chars_to_copy: -1);
        V_strncat(pDest: buf, pSrc: "]", destBufferSize: 0x800u, max_chars_to_copy: -1);
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
        v4(a1: LOG_CONSOLE, a2: 0, a3: "%-32s\n", buf);
      ++v0;
    }
    while ( v0 < nChannelCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE480
// Name: void Con_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_Init()
{
  int v0; // eax
  int v1; // eax
  bool v2; // bl
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char *m_pszString; // esi
  bool v10; // zf
  const char *v11; // eax
  const char *v12; // [esp-10h] [ebp-18h]

  v0 = _CommandLine();
  v1 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-rpt");
  v2 = v1 != 0;
  if ( v1 != 0
    || (v3 = _CommandLine(),
        v4 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-condebug"),
        con_debuglog = v2,
        v4 != 0) )
  {
    con_debuglog = true;
  }
  v5 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-makereslists") != 0
    || (v6 = _CommandLine(),
        v12 = "-mapname",
        v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 40))(a1: v6),
        con_debuglogmapprefixed = false,
        v7 != 0) )
  {
    con_debuglogmapprefixed = true;
  }
  if ( con_debuglog )
  {
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: "console.log", a2: (int)v12);
    if ( v2
      || (v8 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-conclearlog") != 0) )
    {
      if ( (con_logfile.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = con_logfile.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)defaultValue;
      }
      v10 = !COM_IsValidPath(pszFilename: m_pszString);
      v11 = "console.log";
      if ( !v10 )
        v11 = m_pszString;
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: v11, a3: "GAME");
    }
  }
  con_initialized = true;
}

//------------------------------------------------------------------------------
// Address: 0x100AE580
// Name: public: void CConPanel::Con_NPrintf(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::Con_NPrintf(CConPanel *this, unsigned int idx, const char *msg)
{
  wchar_t *v4; // esi

  if ( idx <= 0x7F )
  {
    v4 = (wchar_t *)((char *)this + 532 * idx);
    V_snwprintf(pDest: v4 + 186, maxLen: 255, pFormat: L"%S", msg);
    v4[441] = 0;
    *((float *)v4 + 221) = realtime + 4.0;
    *((float *)v4 + 222) = this->da_default_color[0];
    *((float *)v4 + 223) = this->da_default_color[1];
    *((float *)v4 + 224) = this->da_default_color[2];
    *((_BYTE *)v4 + 900) = 0;
    this->m_bDrawDebugAreas = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE610
// Name: public: void CConPanel::Con_NXPrintf(struct con_nprint_s const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::Con_NXPrintf(CConPanel *this, const con_nprint_s *info, const char *msg)
{
  int index; // eax
  float time_to_live; // xmm0_4
  int v6; // ecx

  if ( info != nullptr )
  {
    index = info->index;
    if ( info->index >= 0 && index < 128 )
    {
      V_snwprintf(pDest: this->da_notify[index].szNotify, maxLen: 255, pFormat: L"%S", msg);
      this->da_notify[info->index].szNotify[255] = 0;
      time_to_live = info->time_to_live;
      if ( time_to_live == -1.0 )
        this->da_notify[info->index].expire = -1.0;
      else
        this->da_notify[info->index].expire = time_to_live + realtime;
      v6 = info->index;
      this->da_notify[v6].color[0] = info->color[0];
      this->da_notify[v6].color[1] = info->color[1];
      this->da_notify[v6].color[2] = info->color[2];
      this->da_notify[info->index].fixed_width_font = info->fixed_width_font;
      this->m_bDrawDebugAreas = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE700
// Name: public: int CConPanel::ProcessNotifyLines(int __near &,int __near &,int __near &,int __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConPanel::ProcessNotifyLines(CConPanel *this, int *left, int *top, int *right, int *bottom, bool bDraw)
{
  CConPanel *v6; // esi
  int v7; // eax
  float v8; // xmm1_4
  float *p_expire; // edi
  float v10; // xmm0_4
  unsigned int m_hFontFixed; // ebx
  const wchar_t *v12; // edi
  int v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // eax
  int i; // [esp+Ch] [ebp-1Ch]
  int len; // [esp+14h] [ebp-14h]
  int nFontTall; // [esp+18h] [ebp-10h]
  int count; // [esp+1Ch] [ebp-Ch]
  float *v25; // [esp+20h] [ebp-8h]
  int y; // [esp+24h] [ebp-4h]

  v6 = this;
  count = 0;
  v7 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFontFixed);
  v8 = realtime;
  i = 0;
  p_expire = &v6->da_notify[0].expire;
  nFontTall = v7 + 1;
  y = 20;
  v25 = &v6->da_notify[0].expire;
  while ( 1 )
  {
    v10 = *p_expire;
    if ( *p_expire > v8 )
      break;
    if ( v10 == -1.0 )
      goto LABEL_6;
LABEL_25:
    y += nFontTall;
    p_expire += 133;
    ++i;
    v25 = p_expire;
    if ( i >= 128 )
      return count;
  }
  if ( v10 == -1.0 )
  {
LABEL_6:
    if ( bDraw )
      *p_expire = v8 - 1.0;
  }
  if ( *((_BYTE *)p_expire + 16) != 0 )
    m_hFontFixed = v6->m_hFontFixed;
  else
    m_hFontFixed = v6->m_hFont;
  v12 = (const wchar_t *)(p_expire - 128);
  len = DrawTextLen(font: m_hFontFixed, text: v12);
  v13 = videomode->GetModeWidth(this: videomode) + -10 - len;
  if ( nFontTall + 20 <= videomode->GetModeHeight(this: videomode) - 20 )
  {
    ++count;
    if ( bDraw )
      DrawColoredText(
        font: m_hFontFixed,
        x: v13,
        y,
        r: (int)(float)(v25[1] * 255.0),
        g: (int)(float)(v25[2] * 255.0),
        b: (int)(float)(v25[3] * 255.0),
        a: 255,
        text: v12);
    if ( *v12 != 0 )
    {
      v14 = *left;
      if ( *left >= v13 )
        v14 = v13;
      *left = v14;
      v15 = *top;
      if ( *top >= y )
        v15 = y;
      v16 = len + v13;
      *top = v15;
      v17 = *right;
      if ( *right <= v16 )
        v17 = v16;
      *right = v17;
      v18 = *bottom;
      if ( *bottom <= y + nFontTall )
        v18 = y + nFontTall;
      *bottom = v18;
    }
    p_expire = v25;
    v6 = this;
    v8 = realtime;
    goto LABEL_25;
  }
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x100AE8C0
// Name: public: virtual void CConPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CConPanel::PaintBackground(CConPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  IEngineVGuiInternal *v4; // eax
  int Wide; // edi
  int HostVersion; // eax
  void (__thiscall *DrawSetTextColor)(vgui::ISurface *, Color); // eax
  int v8; // eax
  CClientState *BaseLocalClient; // eax
  CClientState *v10; // eax
  INetChannel *m_NetChannel; // ebx
  netadr_s *v12; // eax
  const char *v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // [esp-8h] [ebp-394h]
  char *m_szLevelNameShort; // [esp-4h] [ebp-390h]
  wchar_t text[200]; // [esp+4h] [ebp-388h] BYREF
  wchar_t unicode[200]; // [esp+194h] [ebp-1F8h] BYREF
  char ver[100]; // [esp+324h] [ebp-68h] BYREF
  int v22; // [esp+388h] [ebp-4h]

  v4 = EngineVGui();
  if ( v4->IsConsoleVisible(this: v4) )
  {
    Wide = vgui::Panel::GetWide(this);
    v16 = build_number();
    HostVersion = GetHostVersion();
    V_snprintf(pDest: ver, maxLen: 100, pFormat: "Source Engine %i (build %d)", HostVersion, v16);
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: ver, a3: unicode, a4: 400);
    DrawSetTextColor = g_pVGuiSurface->DrawSetTextColor;
    v22 = -1;
    ((void (__thiscall *)(vgui::ISurface *, int))DrawSetTextColor)(a1: g_pVGuiSurface, a2: -1);
    v8 = DrawTextLen(font: this->m_hFont, text: unicode);
    CConPanel::DrawText(this, font: this->m_hFont, x: Wide - v8 - 2, y: 0, fmt: unicode);
    if ( GetBaseLocalClient()->m_nSignonState == 6 )
    {
      BaseLocalClient = GetBaseLocalClient();
      if ( ((unsigned __int8 (__thiscall *)(INetChannel *, int, int))BaseLocalClient->m_NetChannel->IsLoopback)(
             a1: BaseLocalClient->m_NetChannel,
             a2,
             a3) != 0 )
      {
        v10 = GetBaseLocalClient();
        V_snprintf(pDest: ver, maxLen: 100, pFormat: "Map '%s'", v10->m_szLevelNameShort);
      }
      else
      {
        m_NetChannel = GetBaseLocalClient()->m_NetChannel;
        m_szLevelNameShort = GetBaseLocalClient()->m_szLevelNameShort;
        v12 = (netadr_s *)m_NetChannel->GetRemoteAddress(this: m_NetChannel);
        v13 = netadr_s::ToString(this: v12, baseOnly: false);
        V_snprintf(pDest: ver, maxLen: 100, pFormat: "Server '%s' Map '%s'", v13, m_szLevelNameShort);
      }
      ((void (__thiscall *)(vgui::ILocalize *, char *, wchar_t *))g_pVGuiLocalize->ConvertANSIToUnicode)(
        a1: g_pVGuiLocalize,
        a2: ver,
        a3: text);
      v14 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont) + 1;
      v15 = DrawTextLen(font: this->m_hFont, text);
      CConPanel::DrawText(this, font: this->m_hFont, x: Wide - v15 - 2, y: v14, fmt: text);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEA70
// Name: void Con_ShowConsole_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_ShowConsole_f()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  IEngineVGuiInternal *v3; // eax

  if ( g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput) == 0 )
  {
    v0 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(a1: v0, a2: "-noconsole", a3: 0) == 0 )
    {
      if ( con_enable.m_pParent != nullptr && con_enable.m_pParent->m_Value.m_nValue != 0
        || developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0
        || (v1 = _CommandLine(),
            (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v1 + 12))(a1: v1, a2: "-console", a3: 0) != 0)
        || (v2 = _CommandLine(),
            (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-rpt", a3: 0) != 0) )
      {
        v3 = EngineVGui();
        v3->ShowConsole(this: v3);
        SCR_EndLoadingPlaque();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEB00
// Name: void Con_ToggleConsole_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_ToggleConsole_f()
{
  IEngineVGuiInternal *v0; // eax
  IEngineVGuiInternal *v1; // eax
  IEngineVGuiInternal *v2; // eax
  IEngineVGuiInternal *v3; // eax

  v0 = EngineVGui();
  if ( v0->IsConsoleVisible(this: v0) )
  {
    v1 = EngineVGui();
    if ( v1->IsConsoleVisible(this: v1) )
    {
      v2 = EngineVGui();
      v2->HideConsole(this: v2);
    }
    v3 = EngineVGui();
    v3->HideGameUI(this: v3);
  }
  else
  {
    Con_ShowConsole_f();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEB50
// Name: void Con_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_Shutdown()
{
  CNetConsoleMgr *v0; // esi

  if ( g_pNetConsoleMgr != nullptr )
  {
    v0 = g_pNetConsoleMgr;
    CSocketCreator::~CSocketCreator(this: &g_pNetConsoleMgr->m_Socket);
    free(pMem: v0);
  }
  con_initialized = false;
}

//------------------------------------------------------------------------------
// Address: 0x100AEB80
// Name: void Con_DebugLog(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_DebugLog(char *fmt, ...)
{
  char *m_pszString; // esi
  bool v2; // zf
  const char *v3; // eax
  void *v4; // esi
  CMapReslistGenerator *v5; // eax
  char *v6; // eax
  char *TimestampString; // eax
  char pDest[4096]; // [esp+4h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+Ch] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  if ( (con_logfile.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = con_logfile.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v2 = !COM_IsValidPath(pszFilename: m_pszString);
  v3 = "console.log";
  if ( !v2 )
    v3 = m_pszString;
  v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v3, a3: "a", a4: 0);
  if ( v4 != nullptr )
  {
    if ( con_debuglogmapprefixed )
    {
      v5 = MapReslistGenerator();
      v6 = CMapReslistGenerator::LogPrefix(this: v5);
      if ( v6 != nullptr )
        g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v6, a3: strlen(v6), a4: v4);
    }
    if ( con_timestamp.m_pParent != nullptr && con_timestamp.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( needTimestamp )
      {
        TimestampString = GetTimestampString();
        g_pFileSystem->Write(
          this: &g_pFileSystem->IBaseFileSystem,
          a2: TimestampString,
          a3: strlen(TimestampString),
          a4: v4);
        g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: ": ", a3: 2, a4: v4);
      }
      needTimestamp = V_stristr(pStr: pDest, pSearch: "\n") != nullptr;
    }
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pDest, a3: strlen(pDest), a4: v4);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AED00
// Name: public: virtual void CConPanel::DrawNotify(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::DrawNotify(CConPanel *this)
{
  int v2; // ebx
  int v3; // esi
  CConPanel::CNotifyText *v4; // eax
  float liferemaining; // xmm0_4
  float v6; // xmm0_4
  int v7; // ecx
  int c; // [esp+4h] [ebp-Ch]
  Color clr; // [esp+8h] [ebp-8h]
  int y; // [esp+Ch] [ebp-4h]

  y = 5;
  if ( this->m_hFontFixed != 0
    && developer.m_pParent != nullptr
    && developer.m_pParent->m_Value.m_nValue != 0
    && cl_movieinfo.moviename[0] == 0
    && (!toolframework->InToolMode(this: toolframework) || toolframework->ShouldGameRenderView(this: toolframework))
    && con_drawnotify.m_pParent != nullptr
    && con_drawnotify.m_pParent->m_Value.m_nValue != 0 )
  {
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFontFixed);
    v2 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFontFixed) + 1;
    v3 = 0;
    c = this->m_NotifyText.m_Size;
    if ( c > 0 )
    {
      while ( 1 )
      {
        v4 = &this->m_NotifyText.m_Memory.m_pMemory[v3];
        liferemaining = v4->liferemaining;
        clr = v4->clr;
        if ( liferemaining >= 0.5 )
          break;
        if ( liferemaining < 0.0 )
          liferemaining = 0.0;
        v6 = liferemaining * 2.0;
        v7 = (int)(float)(v6 * 255.0);
        if ( v3 != 0 || v6 >= 0.2 )
          goto LABEL_17;
        y = (int)(float)((float)y - (float)((float)(1.0 - (float)(v6 * 5.0)) * (float)v2));
        DrawColoredText(
          font: this->m_hFontFixed,
          x: 8,
          y,
          r: clr._color[0],
          g: clr._color[1],
          b: clr._color[2],
          a: (unsigned __int8)v7,
          text: v4->text);
LABEL_18:
        y += v2;
        if ( ++v3 >= c )
          return;
      }
      LOBYTE(v7) = -1;
LABEL_17:
      DrawColoredText(
        font: this->m_hFontFixed,
        x: 8,
        y,
        r: clr._color[0],
        g: clr._color[1],
        b: clr._color[2],
        a: (unsigned __int8)v7,
        text: v4->text);
      goto LABEL_18;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEEA0
// Name: public: virtual void CConPanel::DrawDebugAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::DrawDebugAreas(CConPanel *this)
{
  int m_nValue; // esi
  int v3; // eax
  int left; // [esp+4h] [ebp-10h] BYREF
  int top; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int bottom; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_bDrawDebugAreas )
  {
    left = 99999;
    top = 99999;
    right = -99999;
    bottom = -99999;
    if ( con_nprint_bgalpha.m_pParent != nullptr
      && con_nprint_bgalpha.m_pParent->m_Value.m_nValue != 0
      && CConPanel::ProcessNotifyLines(this, &left, &top, &right, &bottom, bDraw: false) != 0 )
    {
      if ( con_nprint_bgborder.m_pParent != nullptr )
        m_nValue = con_nprint_bgborder.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( con_nprint_bgalpha.m_pParent != nullptr )
        v3 = con_nprint_bgalpha.m_pParent->m_Value.m_nValue;
      else
        v3 = 0;
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, int))g_pVGuiSurface->DrawSetColor_2)(a1: 0, a2: 0, a3: 0, a4: v3);
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: left - m_nValue,
        a3: top - m_nValue,
        a4: m_nValue + right,
        a5: m_nValue + bottom);
    }
    if ( CConPanel::ProcessNotifyLines(this, &left, &top, &right, &bottom, bDraw: true) == 0 )
      this->m_bDrawDebugAreas = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEFC0
// Name: public: virtual bool CConPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CConPanel::ShouldDraw(CConPanel *this)
{
  IEngineVGuiInternal *v2; // eax
  int v3; // edi
  int v4; // ebx
  CConPanel::CNotifyText *m_pMemory; // eax
  float v6; // xmm0_4
  bool bVisible; // [esp+7h] [ebp-1h]

  bVisible = this->m_bDrawDebugAreas;
  v2 = EngineVGui();
  if ( v2->IsConsoleVisible(this: v2) )
    return 1;
  v3 = this->m_NotifyText.m_Size - 1;
  if ( v3 >= 0 )
  {
    v4 = v3;
    do
    {
      m_pMemory = this->m_NotifyText.m_Memory.m_pMemory;
      v6 = m_pMemory[v4].liferemaining - host_frametime;
      m_pMemory[v4].liferemaining = v6;
      if ( v6 > 0.0 )
      {
        bVisible = true;
      }
      else
      {
        if ( this->m_NotifyText.m_Size - v3 - 1 > 0 )
          _V_memmove(
            dest: &this->m_NotifyText.m_Memory.m_pMemory[v4],
            src: &this->m_NotifyText.m_Memory.m_pMemory[v4 + 1],
            count: 520 * (this->m_NotifyText.m_Size - v3 - 1));
        --this->m_NotifyText.m_Size;
      }
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  return bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x100AF0F0
// Name: void Con_ClearNotify(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_ClearNotify()
{
  if ( g_pConPanel != nullptr )
    g_pConPanel->m_NotifyText.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AF110
// Name: public: CConPanel::CConPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CConPanel *__thiscall CConPanel::CConPanel(CConPanel *this, vgui::Panel *parent)
{
  int v3; // eax
  int v5; // [esp-4h] [ebp-Ch]

  CBasePanel::CBasePanel(this, parent, panelName: "CConPanel");
  this->__vftable = (CConPanel_vtbl *)&CConPanel::`vftable';
  this->m_NotifyText.m_Memory.m_pMemory = nullptr;
  this->m_NotifyText.m_Memory.m_nAllocationCount = 0;
  this->m_NotifyText.m_Memory.m_nGrowSize = 0;
  this->m_NotifyText.m_Size = 0;
  this->m_NotifyText.m_pElements = nullptr;
  v5 = videomode->GetModeHeight(this: videomode);
  v3 = videomode->GetModeWidth(this: videomode);
  vgui::Panel::SetSize(this, wide: v3, tall: v5);
  vgui::Panel::SetPos(this, x: 0, y: 0);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetCursor(this, cursor: 0);
  this->da_default_color[0] = 1.0;
  this->da_default_color[1] = 1.0;
  this->da_default_color[2] = 1.0;
  this->m_bDrawDebugAreas = false;
  g_pConPanel = this;
  memset(dst: (unsigned __int8 *)this->da_notify, value: 0, count: sizeof(this->da_notify));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AF1E0
// Name: void Con_CreateConsolePanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_CreateConsolePanel(vgui::Panel *parent)
{
  CConPanel *v1; // eax
  CConPanel *v2; // eax

  v1 = (CConPanel *)MemAlloc_Alloc(nSize: 0x10B78u);
  if ( v1 != nullptr )
  {
    v2 = CConPanel::CConPanel(this: v1, parent);
    conPanel = v2;
    if ( v2 != nullptr )
      v2->SetVisible(this: v2, a2: false);
  }
  else
  {
    conPanel = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF230
// Name: void Con_Clear_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_Clear_f()
{
  IEngineVGuiInternal *v0; // eax

  v0 = EngineVGui();
  v0->ClearConsole(this: v0);
  if ( g_pConPanel != nullptr )
    g_pConPanel->m_NotifyText.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AF2A0
// Name: public: void CConPanel::AddToNotify(class Color const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::AddToNotify(CConPanel *this, const Color *clr, const char *msg)
{
  CConPanel *v3; // ebx
  const char *v4; // edi
  int v5; // esi
  CConPanel::CNotifyText *v6; // esi
  wchar_t *v7; // edi
  unsigned __int16 *v8; // eax
  int v9; // eax
  CConPanel *v10; // esi
  int i; // eax
  int m_nValue; // ecx
  wchar_t unicode[1024]; // [esp+4h] [ebp-804h] BYREF
  CConPanel *v14; // [esp+804h] [ebp-4h]
  int copysize; // [esp+814h] [ebp+Ch]

  v3 = this;
  v14 = this;
  if ( host_initialized && developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = msg;
    if ( *msg == 1 || *msg == 2 )
      v4 = msg + 1;
    if ( *v4 != 0 )
    {
      v5 = this->m_NotifyText.m_Size - 1;
      if ( v5 >= 0 )
      {
        v6 = &this->m_NotifyText.m_Memory.m_pMemory[v5];
        v6->clr = *clr;
      }
      else
      {
        v6 = &this->m_NotifyText.m_Memory.m_pMemory[CUtlVector<CConPanel::CNotifyText,CUtlMemory<CConPanel::CNotifyText,int>>::InsertBefore(
                                                      this: &this->m_NotifyText,
                                                      elem: this->m_NotifyText.m_Size)];
        v6->clr = *clr;
        v6->text[0] = 0;
        v6->liferemaining = con_notifytime.m_pParent->m_Value.m_fValue;
      }
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v4, a3: unicode, a4: 2048);
      v7 = unicode;
      if ( unicode[0] != 0 )
      {
        while ( 1 )
        {
          v8 = wcsstr(wcs1: v7, wcs2: L"\n");
          if ( v8 == nullptr )
            break;
          copysize = v8 - v7 + 1;
          safestrncat(text: v6->text, maxCharactersWithNullTerminator: 256, add: v7, addchars: copysize);
          v9 = v6->text[0];
          if ( (_WORD)v9 != 0 && v9 != 10 )
          {
            v10 = v14;
            v6 = &v10->m_NotifyText.m_Memory.m_pMemory[CUtlVector<CConPanel::CNotifyText,CUtlMemory<CConPanel::CNotifyText,int>>::InsertBefore(
                                                         this: &v14->m_NotifyText,
                                                         elem: v14->m_NotifyText.m_Size)];
          }
          v3 = v14;
          v6->clr = *clr;
          v6->text[0] = 0;
          v7 += copysize;
          v6->liferemaining = con_notifytime.m_pParent->m_Value.m_fValue;
          if ( *v7 == 0 )
            goto LABEL_19;
        }
        safestrncat(text: v6->text, maxCharactersWithNullTerminator: 256, add: v7, addchars: wcslen(v7));
        v6->clr = *clr;
        v6->liferemaining = con_notifytime.m_pParent->m_Value.m_fValue;
      }
LABEL_19:
      for ( i = v3->m_NotifyText.m_Size; i > 0; i = v3->m_NotifyText.m_Size )
      {
        if ( con_times.m_pParent != nullptr )
          m_nValue = con_times.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( i < m_nValue )
          break;
        CUtlVector<CConPanel::CNotifyText,CUtlMemory<CConPanel::CNotifyText,int>>::Remove(
          this: &v3->m_NotifyText,
          elem: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF480
// Name: void Con_ColorPrint(class Color const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_ColorPrint(const Color *clr, const char *msg)
{
  IEngineVGuiInternal *v2; // eax
  int m_nValue; // eax
  int m_pParent; // ecx
  int v5; // eax
  char *m_pszString; // edi
  char *v7; // esi
  int v8; // eax
  Color mycolor; // [esp+0h] [ebp-8h] BYREF
  bool indeveloper; // [esp+5h] [ebp-3h]
  bool debugprint; // [esp+6h] [ebp-2h]
  bool convisible; // [esp+7h] [ebp-1h]

  v2 = EngineVGui();
  convisible = v2->IsConsoleVisible(this: v2);
  if ( developer.m_pParent != nullptr )
    m_nValue = developer.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  debugprint = g_fIsDebugPrint;
  m_pParent = (int)g_pNetConsoleMgr;
  indeveloper = m_nValue > 0;
  if ( g_pNetConsoleMgr != nullptr )
    CNetConsoleMgr::SendStringToNetConsoles(this: g_pNetConsoleMgr, pString: msg);
  if ( !g_bInColorPrint )
  {
    if ( con_filter_enable.m_pParent != nullptr )
    {
      v5 = con_filter_enable.m_pParent->m_Value.m_nValue;
      if ( v5 > 0 )
      {
        m_pParent = 4096;
        if ( (con_filter_text.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = con_filter_text.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)defaultValue;
        }
        if ( (con_filter_text_out.m_nFlags & 0x1000) != 0 )
        {
          v7 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pParent = (int)con_filter_text_out.m_pParent;
          v7 = con_filter_text_out.m_pParent->m_Value.m_pszString;
          if ( v7 == nullptr )
            v7 = (char *)defaultValue;
        }
        v8 = v5 - 1;
        if ( v8 != 0 )
        {
          if ( v8 == 1 )
          {
            if ( v7 != nullptr && *v7 != 0 && V_stristr(pStr: msg, pSearch: v7) != nullptr )
              return;
            if ( m_pszString != nullptr && *m_pszString != 0 && V_stristr(pStr: msg, pSearch: m_pszString) == nullptr )
            {
              mycolor = (Color)-1765226296;
              g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: &mycolor, a3: msg);
              return;
            }
          }
        }
        else if ( m_pszString != nullptr && *m_pszString != 0 && V_stristr(pStr: msg, pSearch: m_pszString) == nullptr
               || v7 != nullptr && *v7 != 0 && V_stristr(pStr: msg, pSearch: v7) != nullptr )
        {
          return;
        }
      }
    }
    g_bInColorPrint = true;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: m_pParent) != 0
      && (con_trace.m_pParent == nullptr || con_trace.m_pParent->m_Value.m_nValue == 0) )
    {
      Sys_OutputDebugString(msg);
    }
    if ( sv.m_bIsDedicated )
    {
      g_bInColorPrint = false;
    }
    else
    {
      if ( g_fColorPrintf )
      {
        g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: clr, a3: "%s", msg);
      }
      else if ( g_fIsDebugPrint )
      {
        if ( GetBaseLocalClient()->m_nSignonState != 6 || !convisible )
          g_pCVar->ConsoleDPrintf(this: g_pCVar, a2: "%s", msg);
      }
      else
      {
        g_pCVar->ConsolePrintf(this: g_pCVar, a2: "%s", msg);
      }
      if ( GenericThreadLocals::CThreadLocalBase::Get(this: &g_bInSpew) == nullptr )
        _Msg(a1: "%s", msg);
      g_bInColorPrint = false;
      if ( (!debugprint || indeveloper && !convisible) && g_pConPanel != nullptr )
        CConPanel::AddToNotify(this: g_pConPanel, clr, msg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF6C0
// Name: void Con_ColorPrintf(class Color const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_ColorPrintf(const Color *clr, char *fmt, ...)
{
  DWORD CurrentThreadId; // ecx
  char pDest[4100]; // [esp+0h] [ebp-1004h] BYREF
  va_list params; // [esp+1014h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    autoMutex__.m_ownerID = 0;
    autoMutex__.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex__.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex__, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex__.m_depth;
  }
  if ( SV_RedirectActive() )
  {
    SV_RedirectAddText(txt: pDest);
  }
  else
  {
    if ( con_debuglog )
      Con_DebugLog(fmt: "%s", pDest);
    if ( con_initialized )
    {
      g_fColorPrintf = true;
      Con_ColorPrint(clr, msg: pDest);
      g_fColorPrintf = false;
      if ( --autoMutex__.m_depth != 0 )
        return;
      goto LABEL_15;
    }
  }
  if ( --autoMutex__.m_depth != 0 )
    return;
LABEL_15:
  _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100AF7E0
// Name: void Con_NPrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_NPrintf(unsigned int idx, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  CConPanel::Con_NPrintf(this: g_pConPanel, idx, msg: pDest);
}

//------------------------------------------------------------------------------
// Address: 0x100AF830
// Name: void Con_NXPrintf(struct con_nprint_s const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_NXPrintf(const con_nprint_s *info, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  CConPanel::Con_NXPrintf(this: g_pConPanel, info, msg: pDest);
}

//------------------------------------------------------------------------------
// Address: 0x101FF520
// Name: bool Con_IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Con_IsVisible()
{
  IEngineVGuiInternal *v0; // eax

  v0 = EngineVGui();
  return v0->IsConsoleVisible(this: v0);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1008A050
// Name: public: void CUtlMemory<struct CConPanel::CNotifyText,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CConPanel::CNotifyText,int>::Grow(CUtlMemory<NetMessageCvar_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  NetMessageCvar_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 520 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (NetMessageCvar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (NetMessageCvar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD6E0
// Name: GetTimestampString
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetTimestampString()
{
  tm today; // [esp+0h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &today);
  V_snprintf(
    pDest: string,
    maxLen: 128,
    pFormat: "%02i/%02i/%04i - %02i:%02i:%02i",
    today.tm_mon + 1,
    today.tm_mday,
    today.tm_year + 1900,
    today.tm_hour,
    today.tm_min,
    today.tm_sec);
  return string;
}

//------------------------------------------------------------------------------
// Address: 0x100AD730
// Name: void Con_HideConsole_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_HideConsole_f()
{
  IEngineVGuiInternal *v0; // eax
  IEngineVGuiInternal *v1; // eax

  v0 = EngineVGui();
  if ( v0->IsConsoleVisible(this: v0) )
  {
    v1 = EngineVGui();
    v1->HideConsole(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD760
// Name: Con_LogLevelCallback
// Source: json
//------------------------------------------------------------------------------
char __cdecl Con_LogLevelCallback(const CLoggingSystem::LoggingChannel_t *pChannel, const char *pParameter)
{
  int v2; // esi

  if ( _V_stricmp(s1: pParameter, s2: "all") == 0 )
  {
    v2 = 0;
LABEL_9:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      _LoggingSystem_Log(
        a1: LOG_CONSOLE,
        a2: 0,
        a3: "Setting channel '%s' minimum spew level to '%s'.\n",
        pChannel->m_Name,
        pParameter);
    _LoggingSystem_SetChannelSpewLevel(a1: pChannel->m_ID, a2: v2);
    return 1;
  }
  if ( _V_stricmp(s1: pParameter, s2: "warning") == 0 )
  {
    v2 = 1;
    goto LABEL_9;
  }
  if ( _V_stricmp(s1: pParameter, s2: "error") == 0 )
  {
    v2 = 3;
    goto LABEL_9;
  }
  if ( _V_stricmp(s1: pParameter, s2: "off") == 0 )
  {
    v2 = 4;
    goto LABEL_9;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
    _LoggingSystem_Log(a1: LOG_CONSOLE, a2: 1, a3: "Unrecognized severity: %s.\n", pParameter);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AD840
// Name: Con_LogFlagsCallback
// Source: json
//------------------------------------------------------------------------------
char __cdecl Con_LogFlagsCallback(const CLoggingSystem::LoggingChannel_t *pChannel, const char *pParameter)
{
  const char *v3; // esi
  int v4; // edi
  int ChannelFlags; // eax
  int v6; // esi
  const char *pFlag; // [esp+0h] [ebp-4h]
  char bEnable_3; // [esp+13h] [ebp+Fh]

  if ( *pParameter == 43 )
  {
    bEnable_3 = 1;
  }
  else
  {
    if ( *pParameter != 45 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
        _LoggingSystem_Log(a1: LOG_CONSOLE, a2: 1, a3: "First character of flag specifier must be + or -.\n");
      return 0;
    }
    bEnable_3 = 0;
  }
  v3 = pParameter + 1;
  pFlag = pParameter + 1;
  if ( _V_stricmp(s1: pParameter + 1, s2: "donotecho") == 0 )
  {
    v4 = 2;
LABEL_9:
    ChannelFlags = _LoggingSystem_GetChannelFlags(a1: pChannel->m_ID);
    if ( bEnable_3 != 0 )
      v6 = v4 | ChannelFlags;
    else
      v6 = ~v4 & ChannelFlags;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_CONSOLE, a2: 0, a3: "Enabling flag '%s' on channel '%s'.\n", pFlag, pChannel->m_Name);
    _LoggingSystem_SetChannelFlags(a1: pChannel->m_ID, a2: v6);
    return 1;
  }
  if ( _V_stricmp(s1: v3, s2: "consoleonly") == 0 )
  {
    v4 = 1;
    goto LABEL_9;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
    _LoggingSystem_Log(a1: LOG_CONSOLE, a2: 1, a3: "Unrecognized flag: %s.\n", v3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AD970
// Name: void Con_RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_RunFrame()
{
  if ( g_pNetConsoleMgr != nullptr )
    CNetConsoleMgr::RunFrame(this: g_pNetConsoleMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100AD980
// Name: safestrncat
// Source: json
//------------------------------------------------------------------------------
void __usercall safestrncat(
        wchar_t *text@<ecx>,
        int maxCharactersWithNullTerminator@<edx>,
        wchar_t *add@<eax>,
        int addchars)
{
  wchar_t *v6; // eax
  int v7; // edx
  wchar_t *v8; // edi
  __int16 v9; // cx
  int v10; // eax
  wchar_t *v11; // ecx

  v6 = text;
  v7 = maxCharactersWithNullTerminator - 1;
  v8 = text + 1;
  do
    v9 = *v6++;
  while ( v9 != 0 );
  v10 = v6 - v8;
  if ( v10 < v7 )
  {
    v11 = &text[v10];
    do
    {
      ++v10;
      if ( --addchars < 0 )
        break;
      *v11++ = *add++;
    }
    while ( v10 < v7 );
    *v11 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD9E0
// Name: public: virtual void CConPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::ApplySchemeSettings(CConPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_hFont = pScheme->GetFont(this: pScheme, a2: "DefaultSmallDropShadow", a3: false);
  this->m_hFontFixed = pScheme->GetFont(this: pScheme, a2: "DefaultFixedDropShadow", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100ADA30
// Name: public: void CConPanel::DrawText(unsigned long,int,int,wchar_t __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CConPanel::DrawText(CConPanel *this, unsigned int font, int x, int y, wchar_t *fmt, ...)
{
  wchar_t data[1024]; // [esp+0h] [ebp-800h] BYREF
  va_list va; // [esp+81Ch] [ebp+1Ch] BYREF

  va_start(va, fmt);
  V_snwprintf(pDest: data, maxLen: 1023, pFormat: fmt, va);
  data[1023] = 0;
  DrawColoredText(font, x, y, r: 255, g: 255, b: 255, a: 255, text: data);
}

//------------------------------------------------------------------------------
// Address: 0x100ADAB0
// Name: public: char const __near * __near * CCommand::ArgV(void)const
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CCommand::ArgV(CCommand *this)
{
  if ( this->m_nArgc != 0 )
    return this->m_ppArgv;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100ADB20
// Name: char const __near * GetConsoleLogFilename(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetConsoleLogFilename()
{
  char *m_pszString; // esi
  bool v1; // zf
  char *result; // eax

  if ( (con_logfile.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = con_logfile.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v1 = !COM_IsValidPath(pszFilename: m_pszString);
  result = "console.log";
  if ( !v1 )
    return m_pszString;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ADB60
// Name: Con_LogFunctionHelper
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_LogFunctionHelper(
        const CCommand *args,
        bool (__cdecl *callbackFunction)(const CLoggingSystem::LoggingChannel_t *, const char *))
{
  CCommand *v2; // edx
  int m_nArgc; // eax
  const char **m_ppArgv; // ecx
  int v5; // ebx
  int v6; // edi
  Con_LogFunctionHelper::__l5::ChannelSpecifier_t *v7; // esi
  const char *v8; // eax
  int FirstChannelID; // eax
  const CLoggingSystem::LoggingChannel_t *Channel; // esi
  int v11; // edi
  CLoggingSystem::LoggingTag_t *m_pFirstTag; // esi
  const char *m_pSpecifier; // ebx
  char v14; // al
  Con_LogFunctionHelper::__l5::ChannelSpecifier_t channelSpecifier[16]; // [esp+0h] [ebp-8Ch] BYREF
  const char *pParameter; // [esp+80h] [ebp-Ch]
  int nSpecifierCount; // [esp+84h] [ebp-8h]
  const CLoggingSystem::LoggingChannel_t *pLoggingChannel; // [esp+88h] [ebp-4h]
  int channelID; // [esp+94h] [ebp+8h]

  v2 = args;
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 3 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      _LoggingSystem_Log(
        a1: LOG_CONSOLE,
        a2: 0,
        a3: "Log Function Help: \n"
        "    log_level <channel specifiers> <level>\n"
        "    log_color <channel specifiers> <hex color>\n"
        "    log_flags <channel specifiers> <+/-flag>\n"
        "All functions are case insensitive.\n"
        "\n"
        "A channel specifier is either:\n"
        "1) tag specifiers: +/-tag1 +/-tag2 ...      // Narrows down to channels with & without given tags.\n"
        "2) channel names: name1 name2 ...           // Lists channels by name.\n"
        "\n"
        "level: all, warning, error, off             // Spews anything at or above the specified level.\n"
        "                                            // 'off' turns all spew off, 'all' turns all spew on.\n"
        "hex color: RRGGBBAA                         // A hexadecimal color value in the order RGBA.\n"
        "flag: <+/->DoNotEcho                        // Enable/disable a flag to turn off echoing to the console.\n"
        "      <+/->ConsoleOnly                      // Enable/disable a flag to send text only to the console.\n"
        "e.g.\n"
        "    log_level +console -developer warning   // Sets minimum spew level of channels with the tag\n"
        "                                            // 'console' but without the tag 'developer' to 'warning'.\n"
        "\n"
        "    log_color renderdebug bsp FFC08040      // Sets the 'renderdebug' and 'bsp' channels to the RGBA color (64, "
        "128, 192, 255).\n"
        "\n"
        "    log_flags +developer +donotecho         // Turns on the LCF_DO_NOT_ECHO flag for all channels with the 'developer' tag.\n\n");
    return;
  }
  if ( m_nArgc != 0 )
    m_ppArgv = args->m_ppArgv;
  else
    m_ppArgv = nullptr;
  v5 = m_nArgc - 2;
  pParameter = m_ppArgv[m_nArgc - 1];
  nSpecifierCount = m_nArgc - 2;
  if ( m_nArgc - 2 > 16 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_CONSOLE, a2: 1, a3: "Too many channel specifiers (max: %d).\n", 16);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      _LoggingSystem_Log(
        a1: LOG_CONSOLE,
        a2: 0,
        a3: "Log Function Help: \n"
        "    log_level <channel specifiers> <level>\n"
        "    log_color <channel specifiers> <hex color>\n"
        "    log_flags <channel specifiers> <+/-flag>\n"
        "All functions are case insensitive.\n"
        "\n"
        "A channel specifier is either:\n"
        "1) tag specifiers: +/-tag1 +/-tag2 ...      // Narrows down to channels with & without given tags.\n"
        "2) channel names: name1 name2 ...           // Lists channels by name.\n"
        "\n"
        "level: all, warning, error, off             // Spews anything at or above the specified level.\n"
        "                                            // 'off' turns all spew off, 'all' turns all spew on.\n"
        "hex color: RRGGBBAA                         // A hexadecimal color value in the order RGBA.\n"
        "flag: <+/->DoNotEcho                        // Enable/disable a flag to turn off echoing to the console.\n"
        "      <+/->ConsoleOnly                      // Enable/disable a flag to send text only to the console.\n"
        "e.g.\n"
        "    log_level +console -developer warning   // Sets minimum spew level of channels with the tag\n"
        "                                            // 'console' but without the tag 'developer' to 'warning'.\n"
        "\n"
        "    log_color renderdebug bsp FFC08040      // Sets the 'renderdebug' and 'bsp' channels to the RGBA color (64, "
        "128, 192, 255).\n"
        "\n"
        "    log_flags +developer +donotecho         // Turns on the LCF_DO_NOT_ECHO flag for all channels with the 'developer' tag.\n\n");
    return;
  }
  v6 = 1;
  pLoggingChannel = (const CLoggingSystem::LoggingChannel_t *)(m_nArgc - 1);
  if ( m_nArgc - 1 <= 1 )
  {
LABEL_23:
    FirstChannelID = _LoggingSystem_GetFirstChannelID();
    channelID = FirstChannelID;
    if ( FirstChannelID != -1 )
    {
      while ( 1 )
      {
        Channel = (const CLoggingSystem::LoggingChannel_t *)_LoggingSystem_GetChannel(a1: FirstChannelID);
        v11 = 0;
        for ( pLoggingChannel = Channel; v11 < v5; ++v11 )
        {
          if ( channelSpecifier[0].m_bIsTag )
          {
            m_pFirstTag = Channel->m_pFirstTag;
            m_pSpecifier = channelSpecifier[v11].m_pSpecifier;
            if ( m_pFirstTag != nullptr )
            {
              while ( _V_stricmp(s1: m_pFirstTag->m_pTagName, s2: m_pSpecifier) != 0 )
              {
                m_pFirstTag = m_pFirstTag->m_pNextTag;
                if ( m_pFirstTag == nullptr )
                  goto LABEL_35;
              }
              v14 = 1;
            }
            else
            {
LABEL_35:
              v14 = 0;
            }
            v5 = nSpecifierCount;
            Channel = pLoggingChannel;
            if ( channelSpecifier[v11].m_bInclude != v14 )
              break;
          }
          else if ( _V_stricmp(s1: channelSpecifier[v11].m_pSpecifier, s2: Channel->m_Name) == 0 )
          {
            break;
          }
        }
        if ( (v11 == v5) == channelSpecifier[0].m_bIsTag && !callbackFunction(a1: Channel, a2: pParameter) )
          break;
        channelID = _LoggingSystem_GetNextChannelID(a1: channelID);
        if ( channelID == -1 )
          return;
        FirstChannelID = channelID;
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
LABEL_46:
        _LoggingSystem_Log(
          a1: LOG_CONSOLE,
          a2: 0,
          a3: "Log Function Help: \n"
          "    log_level <channel specifiers> <level>\n"
          "    log_color <channel specifiers> <hex color>\n"
          "    log_flags <channel specifiers> <+/-flag>\n"
          "All functions are case insensitive.\n"
          "\n"
          "A channel specifier is either:\n"
          "1) tag specifiers: +/-tag1 +/-tag2 ...      // Narrows down to channels with & without given tags.\n"
          "2) channel names: name1 name2 ...           // Lists channels by name.\n"
          "\n"
          "level: all, warning, error, off             // Spews anything at or above the specified level.\n"
          "                                            // 'off' turns all spew off, 'all' turns all spew on.\n"
          "hex color: RRGGBBAA                         // A hexadecimal color value in the order RGBA.\n"
          "flag: <+/->DoNotEcho                        // Enable/disable a flag to turn off echoing to the console.\n"
          "      <+/->ConsoleOnly                      // Enable/disable a flag to send text only to the console.\n"
          "e.g.\n"
          "    log_level +console -developer warning   // Sets minimum spew level of channels with the tag\n"
          "                                            // 'console' but without the tag 'developer' to 'warning'.\n"
          "\n"
          "    log_color renderdebug bsp FFC08040      // Sets the 'renderdebug' and 'bsp' channels to the RGBA color (64"
          ", 128, 192, 255).\n"
          "\n"
          "    log_flags +developer +donotecho         // Turns on the LCF_DO_NOT_ECHO flag for all channels with the 'de"
          "veloper' tag.\n"
          "\n");
    }
  }
  else
  {
    v7 = channelSpecifier;
    while ( 1 )
    {
      v8 = CCommand::ArgV(this: v2)[v6];
      if ( *v8 == 43 )
      {
        ++v8;
        *(_WORD *)&v7->m_bIsTag = 257;
      }
      else if ( *v8 == 45 )
      {
        ++v8;
        *(_WORD *)&v7->m_bIsTag = 1;
      }
      else
      {
        v7->m_bIsTag = false;
      }
      v7->m_pSpecifier = v8;
      if ( v6 > 1 && v7->m_bIsTag != v7[-1].m_bIsTag )
        break;
      ++v6;
      ++v7;
      if ( v6 >= (int)pLoggingChannel )
        goto LABEL_23;
      v2 = args;
    }
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_CONSOLE,
        a2: 1,
        a3: "Cannot mix and match tag specifiers with channel name specifiers.\n");
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      goto LABEL_46;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADE00
// Name: Con_LogColorCallback
// Source: json
//------------------------------------------------------------------------------
char __cdecl Con_LogColorCallback(const CLoggingSystem::LoggingChannel_t *pChannel, const char *pParameter)
{
  int color; // [esp+4h] [ebp-4h] BYREF

  V_hextobinary(in: pParameter, numchars: 8, out: (unsigned __int8 *)&color, maxoutputbytes: 4);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
    _LoggingSystem_Log(
      a1: LOG_CONSOLE,
      a2: 0,
      a3: "Setting channel '%s' color to %08X.\n",
      pChannel->m_Name,
      _byteswap_ulong(color));
  _LoggingSystem_SetChannelColor(a1: pChannel->m_ID, a2: color);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ADE70
// Name: void Con_LogLevel_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_LogLevel_f(const CCommand *args)
{
  Con_LogFunctionHelper(
    args,
    callbackFunction: (bool (__cdecl *)(const CLoggingSystem::LoggingChannel_t *, const char *))Con_LogLevelCallback);
}

//------------------------------------------------------------------------------
// Address: 0x100ADE90
// Name: void Con_LogColor_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_LogColor_f(const CCommand *args)
{
  Con_LogFunctionHelper(
    args,
    callbackFunction: (bool (__cdecl *)(const CLoggingSystem::LoggingChannel_t *, const char *))Con_LogColorCallback);
}

//------------------------------------------------------------------------------
// Address: 0x100ADEB0
// Name: void Con_LogFlags_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_LogFlags_f(const CCommand *args)
{
  Con_LogFunctionHelper(
    args,
    callbackFunction: (bool (__cdecl *)(const CLoggingSystem::LoggingChannel_t *, const char *))Con_LogFlagsCallback);
}

//------------------------------------------------------------------------------
// Address: 0x100ADEE0
// Name: void Con_LogDumpChannels_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_LogDumpChannels_f()
{
  int v0; // ebx
  int Channel; // esi
  int v2; // eax
  const char *v3; // edi
  void (*v4)(int, _DWORD, const char *, ...); // edi
  int i; // esi
  const char *v6; // [esp-Ch] [ebp-81Ch]
  char buf[2048]; // [esp+8h] [ebp-808h] BYREF
  unsigned int v8; // [esp+808h] [ebp-8h]
  int nChannelCount; // [esp+80Ch] [ebp-4h]

  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
    _LoggingSystem_Log(
      a1: LOG_CONSOLE,
      a2: 0,
      a3: "%-4s    %-32s    %-10s    %-10s    %-32s    %-32s\n",
      "ID",
      "Channel Name",
      "Severity",
      "Color",
      "Flags",
      "Tags");
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
    _LoggingSystem_Log(
      a1: LOG_CONSOLE,
      a2: 0,
      a3: "------------------------------------------------------------------------------------------------------------------"
      "----------------------------------\n");
  v0 = 0;
  nChannelCount = _LoggingSystem_GetChannelCount();
  if ( nChannelCount > 0 )
  {
    do
    {
      Channel = _LoggingSystem_GetChannel(a1: v0);
      v2 = *(_DWORD *)(Channel + 8);
      if ( v2 < 4 )
      {
        if ( v2 < 3 )
        {
          v3 = "warning";
          if ( v2 < 1 )
            v3 = "all";
        }
        else
        {
          v3 = "error";
        }
      }
      else
      {
        v3 = "off";
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
      {
        v8 = *(_DWORD *)(Channel + 12);
        v6 = v3;
        v4 = (void (*)(int, _DWORD, const char *, ...))_LoggingSystem_Log;
        _LoggingSystem_Log(
          a1: LOG_CONSOLE,
          a2: 0,
          a3: "%-4d    %-32s    %-10s    0x%08X    ",
          v0,
          (const char *)(Channel + 16),
          v6,
          _byteswap_ulong(v8));
      }
      else
      {
        v4 = (void (*)(int, _DWORD, const char *, ...))_LoggingSystem_Log;
      }
      buf[0] = 0;
      if ( (*(_BYTE *)(Channel + 4) & 1) != 0 )
        V_strncat(pDest: buf, pSrc: "[ConsoleOnly]", destBufferSize: 0x800u, max_chars_to_copy: -1);
      if ( (*(_BYTE *)(Channel + 4) & 2) != 0 )
        V_strncat(pDest: buf, pSrc: "[DoNotEcho]", destBufferSize: 0x800u, max_chars_to_copy: -1);
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
        v4(a1: LOG_CONSOLE, a2: 0, a3: "%-32s    ", buf);
      buf[0] = 0;
      for ( i = *(_DWORD *)(Channel + 48); i != 0; i = *(_DWORD *)(i + 4) )
      {
        V_strncat(pDest: buf, pSrc: "[", destBufferSize: 0x800u, max_chars_to_copy: -1);
        V_strncat(pDest: buf, pSrc: *(const char **)i, destBufferSize: 0x800u, max_chars_to_copy: -1);
        V_strncat(pDest: buf, pSrc: "]", destBufferSize: 0x800u, max_chars_to_copy: -1);
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0) != 0 )
        v4(a1: LOG_CONSOLE, a2: 0, a3: "%-32s\n", buf);
      ++v0;
    }
    while ( v0 < nChannelCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE120
// Name: void Con_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_Init()
{
  int v0; // eax
  int v1; // eax
  bool v2; // bl
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char *m_pszString; // esi
  bool v10; // zf
  const char *v11; // eax

  v0 = _CommandLine();
  v1 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-rpt");
  v2 = v1 != 0;
  if ( v1 != 0
    || (v3 = _CommandLine(),
        v4 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-condebug"),
        con_debuglog = v2,
        v4 != 0) )
  {
    con_debuglog = true;
  }
  v5 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-makereslists") != 0
    || (v6 = _CommandLine(),
        v7 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-mapname"),
        con_debuglogmapprefixed = false,
        v7 != 0) )
  {
    con_debuglogmapprefixed = true;
  }
  if ( con_debuglog )
  {
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: "console.log");
    if ( v2
      || (v8 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-conclearlog") != 0) )
    {
      if ( (con_logfile.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = con_logfile.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)defaultValue;
      }
      v10 = !COM_IsValidPath(pszFilename: m_pszString);
      v11 = "console.log";
      if ( !v10 )
        v11 = m_pszString;
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: v11, a3: "GAME");
    }
  }
  con_initialized = true;
}

//------------------------------------------------------------------------------
// Address: 0x100AE2B0
// Name: public: void CConPanel::Con_NXPrintf(struct con_nprint_s const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::Con_NXPrintf(CConPanel *this, const con_nprint_s *info, const char *msg)
{
  int index; // eax
  float time_to_live; // xmm0_4
  int v6; // ecx

  if ( info != nullptr )
  {
    index = info->index;
    if ( info->index >= 0 && index < 128 )
    {
      V_snwprintf(pDest: this->da_notify[index].szNotify, maxLen: 255, pFormat: L"%S", msg);
      this->da_notify[info->index].szNotify[255] = 0;
      time_to_live = info->time_to_live;
      if ( time_to_live == -1.0 )
        this->da_notify[info->index].expire = -1.0;
      else
        this->da_notify[info->index].expire = time_to_live + realtime;
      v6 = info->index;
      this->da_notify[v6].color[0] = info->color[0];
      this->da_notify[v6].color[1] = info->color[1];
      this->da_notify[v6].color[2] = info->color[2];
      this->da_notify[info->index].fixed_width_font = info->fixed_width_font;
      this->m_bDrawDebugAreas = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE3A0
// Name: public: int CConPanel::ProcessNotifyLines(int __near &,int __near &,int __near &,int __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConPanel::ProcessNotifyLines(CConPanel *this, int *left, int *top, int *right, int *bottom, bool bDraw)
{
  CConPanel *v6; // esi
  int v7; // eax
  float v8; // xmm1_4
  float *p_expire; // edi
  float v10; // xmm0_4
  unsigned int m_hFontFixed; // ebx
  const wchar_t *v12; // edi
  int v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // eax
  int i; // [esp+Ch] [ebp-1Ch]
  int len; // [esp+14h] [ebp-14h]
  int nFontTall; // [esp+18h] [ebp-10h]
  int count; // [esp+1Ch] [ebp-Ch]
  float *v25; // [esp+20h] [ebp-8h]
  int y; // [esp+24h] [ebp-4h]

  v6 = this;
  count = 0;
  v7 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFontFixed);
  v8 = realtime;
  i = 0;
  p_expire = &v6->da_notify[0].expire;
  nFontTall = v7 + 1;
  y = 20;
  v25 = &v6->da_notify[0].expire;
  while ( 1 )
  {
    v10 = *p_expire;
    if ( *p_expire > v8 )
      break;
    if ( v10 == -1.0 )
      goto LABEL_6;
LABEL_25:
    y += nFontTall;
    p_expire += 133;
    ++i;
    v25 = p_expire;
    if ( i >= 128 )
      return count;
  }
  if ( v10 == -1.0 )
  {
LABEL_6:
    if ( bDraw )
      *p_expire = v8 - 1.0;
  }
  if ( *((_BYTE *)p_expire + 16) != 0 )
    m_hFontFixed = v6->m_hFontFixed;
  else
    m_hFontFixed = v6->m_hFont;
  v12 = (const wchar_t *)(p_expire - 128);
  len = DrawTextLen(font: m_hFontFixed, text: v12);
  v13 = videomode->GetModeWidth(this: videomode) + -10 - len;
  if ( nFontTall + 20 <= videomode->GetModeHeight(this: videomode) - 20 )
  {
    ++count;
    if ( bDraw )
      DrawColoredText(
        font: m_hFontFixed,
        x: v13,
        y,
        r: (int)(float)(v25[1] * 255.0),
        g: (int)(float)(v25[2] * 255.0),
        b: (int)(float)(v25[3] * 255.0),
        a: 255,
        text: v12);
    if ( *v12 != 0 )
    {
      v14 = *left;
      if ( *left >= v13 )
        v14 = v13;
      *left = v14;
      v15 = *top;
      if ( *top >= y )
        v15 = y;
      v16 = len + v13;
      *top = v15;
      v17 = *right;
      if ( *right <= v16 )
        v17 = v16;
      *right = v17;
      v18 = *bottom;
      if ( *bottom <= y + nFontTall )
        v18 = y + nFontTall;
      *bottom = v18;
    }
    p_expire = v25;
    v6 = this;
    v8 = realtime;
    goto LABEL_25;
  }
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x100AE560
// Name: public: virtual void CConPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CConPanel::PaintBackground(CConPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  IEngineVGuiInternal *v4; // eax
  int Wide; // edi
  int HostVersion; // eax
  void (__thiscall *DrawSetTextColor)(vgui::ISurface *, Color); // eax
  int v8; // eax
  CClientState *BaseLocalClient; // eax
  CClientState *v10; // eax
  INetChannel *m_NetChannel; // ebx
  netadr_s *v12; // eax
  const char *v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // [esp-8h] [ebp-394h]
  char *m_szLevelNameShort; // [esp-4h] [ebp-390h]
  wchar_t text[200]; // [esp+4h] [ebp-388h] BYREF
  wchar_t unicode[200]; // [esp+194h] [ebp-1F8h] BYREF
  char ver[100]; // [esp+324h] [ebp-68h] BYREF
  int v22; // [esp+388h] [ebp-4h]

  v4 = EngineVGui();
  if ( v4->IsConsoleVisible(this: v4) )
  {
    Wide = vgui::Panel::GetWide(this);
    v16 = build_number();
    HostVersion = GetHostVersion();
    V_snprintf(pDest: ver, maxLen: 100, pFormat: "Source Engine %i (build %d)", HostVersion, v16);
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: ver, a3: unicode, a4: 400);
    DrawSetTextColor = g_pVGuiSurface->DrawSetTextColor;
    v22 = -1;
    ((void (__thiscall *)(vgui::ISurface *, int))DrawSetTextColor)(a1: g_pVGuiSurface, a2: -1);
    v8 = DrawTextLen(font: this->m_hFont, text: unicode);
    CConPanel::DrawText(this, font: this->m_hFont, x: Wide - v8 - 2, y: 0, fmt: unicode);
    if ( GetBaseLocalClient()->m_nSignonState == 6 )
    {
      BaseLocalClient = GetBaseLocalClient();
      if ( ((unsigned __int8 (__thiscall *)(INetChannel *, int, int))BaseLocalClient->m_NetChannel->IsLoopback)(
             a1: BaseLocalClient->m_NetChannel,
             a2,
             a3) != 0 )
      {
        v10 = GetBaseLocalClient();
        V_snprintf(pDest: ver, maxLen: 100, pFormat: "Map '%s'", v10->m_szLevelNameShort);
      }
      else
      {
        m_NetChannel = GetBaseLocalClient()->m_NetChannel;
        m_szLevelNameShort = GetBaseLocalClient()->m_szLevelNameShort;
        v12 = (netadr_s *)m_NetChannel->GetRemoteAddress(this: m_NetChannel);
        v13 = netadr_s::ToString(this: v12, baseOnly: false);
        V_snprintf(pDest: ver, maxLen: 100, pFormat: "Server '%s' Map '%s'", v13, m_szLevelNameShort);
      }
      ((void (__thiscall *)(vgui::ILocalize *, char *, wchar_t *))g_pVGuiLocalize->ConvertANSIToUnicode)(
        a1: g_pVGuiLocalize,
        a2: ver,
        a3: text);
      v14 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont) + 1;
      v15 = DrawTextLen(font: this->m_hFont, text);
      CConPanel::DrawText(this, font: this->m_hFont, x: Wide - v15 - 2, y: v14, fmt: text);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE710
// Name: void Con_ShowConsole_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_ShowConsole_f()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  IEngineVGuiInternal *v3; // eax

  if ( g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput) == 0 )
  {
    v0 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(a1: v0, a2: "-noconsole", a3: 0) == 0 )
    {
      if ( con_enable.m_pParent != nullptr && con_enable.m_pParent->m_Value.m_nValue != 0
        || developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0
        || (v1 = _CommandLine(),
            (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v1 + 12))(a1: v1, a2: "-console", a3: 0) != 0)
        || (v2 = _CommandLine(),
            (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-rpt", a3: 0) != 0) )
      {
        v3 = EngineVGui();
        v3->ShowConsole(this: v3);
        SCR_EndLoadingPlaque();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE7A0
// Name: void Con_ToggleConsole_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_ToggleConsole_f()
{
  IEngineVGuiInternal *v0; // eax
  IEngineVGuiInternal *v1; // eax
  IEngineVGuiInternal *v2; // eax
  IEngineVGuiInternal *v3; // eax

  v0 = EngineVGui();
  if ( v0->IsConsoleVisible(this: v0) )
  {
    v1 = EngineVGui();
    if ( v1->IsConsoleVisible(this: v1) )
    {
      v2 = EngineVGui();
      v2->HideConsole(this: v2);
    }
    v3 = EngineVGui();
    v3->HideGameUI(this: v3);
  }
  else
  {
    Con_ShowConsole_f();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE7F0
// Name: void Con_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_Shutdown()
{
  CNetConsoleMgr *v0; // esi

  if ( g_pNetConsoleMgr != nullptr )
  {
    v0 = g_pNetConsoleMgr;
    CSocketCreator::~CSocketCreator(this: &g_pNetConsoleMgr->m_Socket);
    free(pMem: v0);
  }
  con_initialized = false;
}

//------------------------------------------------------------------------------
// Address: 0x100AE820
// Name: void Con_DebugLog(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_DebugLog(char *fmt, ...)
{
  char *m_pszString; // esi
  bool v2; // zf
  const char *v3; // eax
  void *v4; // esi
  CMapReslistGenerator *v5; // eax
  const char *v6; // eax
  char *TimestampString; // eax
  char pDest[4096]; // [esp+4h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+Ch] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  if ( (con_logfile.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = con_logfile.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v2 = !COM_IsValidPath(pszFilename: m_pszString);
  v3 = "console.log";
  if ( !v2 )
    v3 = m_pszString;
  v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v3, a3: "a", a4: 0);
  if ( v4 != nullptr )
  {
    if ( con_debuglogmapprefixed )
    {
      v5 = MapReslistGenerator();
      v6 = CMapReslistGenerator::LogPrefix(this: v5);
      if ( v6 != nullptr )
        g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v6, a3: strlen(v6), a4: v4);
    }
    if ( con_timestamp.m_pParent != nullptr && con_timestamp.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( needTimestamp )
      {
        TimestampString = GetTimestampString();
        g_pFileSystem->Write(
          this: &g_pFileSystem->IBaseFileSystem,
          a2: TimestampString,
          a3: strlen(TimestampString),
          a4: v4);
        g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: ": ", a3: 2, a4: v4);
      }
      needTimestamp = V_stristr(pStr: pDest, pSearch: "\n") != nullptr;
    }
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pDest, a3: strlen(pDest), a4: v4);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE9A0
// Name: public: virtual void CConPanel::DrawNotify(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::DrawNotify(CConPanel *this)
{
  int v2; // ebx
  int v3; // esi
  CConPanel::CNotifyText *v4; // eax
  float liferemaining; // xmm0_4
  float v6; // xmm0_4
  int v7; // ecx
  int c; // [esp+4h] [ebp-Ch]
  Color clr; // [esp+8h] [ebp-8h]
  int y; // [esp+Ch] [ebp-4h]

  y = 5;
  if ( this->m_hFontFixed != 0
    && developer.m_pParent != nullptr
    && developer.m_pParent->m_Value.m_nValue != 0
    && cl_movieinfo.moviename[0] == 0
    && (!toolframework->InToolMode(this: toolframework) || toolframework->ShouldGameRenderView(this: toolframework))
    && con_drawnotify.m_pParent != nullptr
    && con_drawnotify.m_pParent->m_Value.m_nValue != 0 )
  {
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hFontFixed);
    v2 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFontFixed) + 1;
    v3 = 0;
    c = this->m_NotifyText.m_Size;
    if ( c > 0 )
    {
      while ( 1 )
      {
        v4 = &this->m_NotifyText.m_Memory.m_pMemory[v3];
        liferemaining = v4->liferemaining;
        clr = v4->clr;
        if ( liferemaining >= 0.5 )
          break;
        if ( liferemaining < 0.0 )
          liferemaining = 0.0;
        v6 = liferemaining * 2.0;
        v7 = (int)(float)(v6 * 255.0);
        if ( v3 != 0 || v6 >= 0.2 )
          goto LABEL_17;
        y = (int)(float)((float)y - (float)((float)(1.0 - (float)(v6 * 5.0)) * (float)v2));
        DrawColoredText(
          font: this->m_hFontFixed,
          x: 8,
          y,
          r: clr._color[0],
          g: clr._color[1],
          b: clr._color[2],
          a: (unsigned __int8)v7,
          text: v4->text);
LABEL_18:
        y += v2;
        if ( ++v3 >= c )
          return;
      }
      LOBYTE(v7) = -1;
LABEL_17:
      DrawColoredText(
        font: this->m_hFontFixed,
        x: 8,
        y,
        r: clr._color[0],
        g: clr._color[1],
        b: clr._color[2],
        a: (unsigned __int8)v7,
        text: v4->text);
      goto LABEL_18;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEB40
// Name: public: virtual void CConPanel::DrawDebugAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::DrawDebugAreas(CConPanel *this)
{
  int m_nValue; // esi
  int v3; // eax
  int left; // [esp+4h] [ebp-10h] BYREF
  int top; // [esp+8h] [ebp-Ch] BYREF
  int right; // [esp+Ch] [ebp-8h] BYREF
  int bottom; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_bDrawDebugAreas )
  {
    left = 99999;
    top = 99999;
    right = -99999;
    bottom = -99999;
    if ( con_nprint_bgalpha.m_pParent != nullptr
      && con_nprint_bgalpha.m_pParent->m_Value.m_nValue != 0
      && CConPanel::ProcessNotifyLines(this, &left, &top, &right, &bottom, bDraw: false) != 0 )
    {
      if ( con_nprint_bgborder.m_pParent != nullptr )
        m_nValue = con_nprint_bgborder.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( con_nprint_bgalpha.m_pParent != nullptr )
        v3 = con_nprint_bgalpha.m_pParent->m_Value.m_nValue;
      else
        v3 = 0;
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, int))g_pVGuiSurface->DrawSetColor_2)(a1: 0, a2: 0, a3: 0, a4: v3);
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: left - m_nValue,
        a3: top - m_nValue,
        a4: m_nValue + right,
        a5: m_nValue + bottom);
    }
    if ( CConPanel::ProcessNotifyLines(this, &left, &top, &right, &bottom, bDraw: true) == 0 )
      this->m_bDrawDebugAreas = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEC60
// Name: public: virtual bool CConPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CConPanel::ShouldDraw(CConPanel *this)
{
  IEngineVGuiInternal *v2; // eax
  int v3; // edi
  int v4; // ebx
  CConPanel::CNotifyText *m_pMemory; // eax
  float v6; // xmm0_4
  bool bVisible; // [esp+7h] [ebp-1h]

  bVisible = this->m_bDrawDebugAreas;
  v2 = EngineVGui();
  if ( v2->IsConsoleVisible(this: v2) )
    return 1;
  v3 = this->m_NotifyText.m_Size - 1;
  if ( v3 >= 0 )
  {
    v4 = v3;
    do
    {
      m_pMemory = this->m_NotifyText.m_Memory.m_pMemory;
      v6 = m_pMemory[v4].liferemaining - host_frametime;
      m_pMemory[v4].liferemaining = v6;
      if ( v6 > 0.0 )
      {
        bVisible = true;
      }
      else
      {
        if ( this->m_NotifyText.m_Size - v3 - 1 > 0 )
          _V_memmove(
            dest: &this->m_NotifyText.m_Memory.m_pMemory[v4],
            src: &this->m_NotifyText.m_Memory.m_pMemory[v4 + 1],
            count: 520 * (this->m_NotifyText.m_Size - v3 - 1));
        --this->m_NotifyText.m_Size;
      }
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  return bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x100AED90
// Name: void Con_ClearNotify(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_ClearNotify()
{
  if ( g_pConPanel != nullptr )
    g_pConPanel->m_NotifyText.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AEDB0
// Name: public: CConPanel::CConPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CConPanel *__thiscall CConPanel::CConPanel(CConPanel *this, vgui::Panel *parent)
{
  int v3; // eax
  int v5; // [esp-4h] [ebp-Ch]

  CBasePanel::CBasePanel(this, parent, panelName: "CConPanel");
  this->__vftable = (CConPanel_vtbl *)&CConPanel::`vftable';
  this->m_NotifyText.m_Memory.m_pMemory = nullptr;
  this->m_NotifyText.m_Memory.m_nAllocationCount = 0;
  this->m_NotifyText.m_Memory.m_nGrowSize = 0;
  this->m_NotifyText.m_Size = 0;
  this->m_NotifyText.m_pElements = nullptr;
  v5 = videomode->GetModeHeight(this: videomode);
  v3 = videomode->GetModeWidth(this: videomode);
  vgui::Panel::SetSize(this, wide: v3, tall: v5);
  vgui::Panel::SetPos(this, x: 0, y: 0);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Panel::SetCursor(this, cursor: 0);
  this->da_default_color[0] = 1.0;
  this->da_default_color[1] = 1.0;
  this->da_default_color[2] = 1.0;
  this->m_bDrawDebugAreas = false;
  g_pConPanel = this;
  memset(dst: (unsigned __int8 *)this->da_notify, value: 0, count: sizeof(this->da_notify));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AEE80
// Name: void Con_CreateConsolePanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_CreateConsolePanel(vgui::Panel *parent)
{
  CConPanel *v1; // eax
  CConPanel *v2; // eax

  v1 = (CConPanel *)MemAlloc_Alloc(nSize: 0x10B78u);
  if ( v1 != nullptr )
  {
    v2 = CConPanel::CConPanel(this: v1, parent);
    conPanel = v2;
    if ( v2 != nullptr )
      v2->SetVisible(this: v2, a2: false);
  }
  else
  {
    conPanel = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEED0
// Name: void Con_Clear_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_Clear_f()
{
  IEngineVGuiInternal *v0; // eax

  v0 = EngineVGui();
  v0->ClearConsole(this: v0);
  if ( g_pConPanel != nullptr )
    g_pConPanel->m_NotifyText.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AEF40
// Name: public: void CConPanel::AddToNotify(class Color const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConPanel::AddToNotify(CConPanel *this, const Color *clr, const char *msg)
{
  CConPanel *v3; // ebx
  const char *v4; // edi
  int v5; // esi
  CConPanel::CNotifyText *v6; // esi
  wchar_t *v7; // edi
  unsigned __int16 *v8; // eax
  int v9; // eax
  CConPanel *v10; // esi
  int i; // eax
  int m_nValue; // ecx
  wchar_t unicode[1024]; // [esp+4h] [ebp-804h] BYREF
  CConPanel *v14; // [esp+804h] [ebp-4h]
  int copysize; // [esp+814h] [ebp+Ch]

  v3 = this;
  v14 = this;
  if ( host_initialized && developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = msg;
    if ( *msg == 1 || *msg == 2 )
      v4 = msg + 1;
    if ( *v4 != 0 )
    {
      v5 = this->m_NotifyText.m_Size - 1;
      if ( v5 >= 0 )
      {
        v6 = &this->m_NotifyText.m_Memory.m_pMemory[v5];
        v6->clr = *clr;
      }
      else
      {
        v6 = &this->m_NotifyText.m_Memory.m_pMemory[CUtlVector<CConPanel::CNotifyText,CUtlMemory<CConPanel::CNotifyText,int>>::InsertBefore(
                                                      this: &this->m_NotifyText,
                                                      elem: this->m_NotifyText.m_Size)];
        v6->clr = *clr;
        v6->text[0] = 0;
        v6->liferemaining = con_notifytime.m_pParent->m_Value.m_fValue;
      }
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v4, a3: unicode, a4: 2048);
      v7 = unicode;
      if ( unicode[0] != 0 )
      {
        while ( 1 )
        {
          v8 = wcsstr(wcs1: v7, wcs2: L"\n");
          if ( v8 == nullptr )
            break;
          copysize = v8 - v7 + 1;
          safestrncat(text: v6->text, maxCharactersWithNullTerminator: 256, add: v7, addchars: copysize);
          v9 = v6->text[0];
          if ( (_WORD)v9 != 0 && v9 != 10 )
          {
            v10 = v14;
            v6 = &v10->m_NotifyText.m_Memory.m_pMemory[CUtlVector<CConPanel::CNotifyText,CUtlMemory<CConPanel::CNotifyText,int>>::InsertBefore(
                                                         this: &v14->m_NotifyText,
                                                         elem: v14->m_NotifyText.m_Size)];
          }
          v3 = v14;
          v6->clr = *clr;
          v6->text[0] = 0;
          v7 += copysize;
          v6->liferemaining = con_notifytime.m_pParent->m_Value.m_fValue;
          if ( *v7 == 0 )
            goto LABEL_19;
        }
        safestrncat(text: v6->text, maxCharactersWithNullTerminator: 256, add: v7, addchars: wcslen(v7));
        v6->clr = *clr;
        v6->liferemaining = con_notifytime.m_pParent->m_Value.m_fValue;
      }
LABEL_19:
      for ( i = v3->m_NotifyText.m_Size; i > 0; i = v3->m_NotifyText.m_Size )
      {
        if ( con_times.m_pParent != nullptr )
          m_nValue = con_times.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( i < m_nValue )
          break;
        CUtlVector<CConPanel::CNotifyText,CUtlMemory<CConPanel::CNotifyText,int>>::Remove(
          this: &v3->m_NotifyText,
          elem: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF120
// Name: void Con_ColorPrint(class Color const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Con_ColorPrint(const Color *clr, const char *msg)
{
  IEngineVGuiInternal *v2; // eax
  int m_nValue; // eax
  int v4; // eax
  char *m_pszString; // edi
  char *v6; // esi
  int v7; // eax
  Color mycolor; // [esp+0h] [ebp-8h] BYREF
  bool indeveloper; // [esp+5h] [ebp-3h]
  bool debugprint; // [esp+6h] [ebp-2h]
  bool convisible; // [esp+7h] [ebp-1h]

  v2 = EngineVGui();
  convisible = v2->IsConsoleVisible(this: v2);
  if ( developer.m_pParent != nullptr )
    m_nValue = developer.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  debugprint = g_fIsDebugPrint;
  indeveloper = m_nValue > 0;
  if ( g_pNetConsoleMgr != nullptr )
    CNetConsoleMgr::SendStringToNetConsoles(this: g_pNetConsoleMgr, pString: msg);
  if ( !g_bInColorPrint )
  {
    if ( con_filter_enable.m_pParent != nullptr )
    {
      v4 = con_filter_enable.m_pParent->m_Value.m_nValue;
      if ( v4 > 0 )
      {
        if ( (con_filter_text.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = con_filter_text.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)defaultValue;
        }
        if ( (con_filter_text_out.m_nFlags & 0x1000) != 0 )
        {
          v6 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          v6 = con_filter_text_out.m_pParent->m_Value.m_pszString;
          if ( v6 == nullptr )
            v6 = (char *)defaultValue;
        }
        v7 = v4 - 1;
        if ( v7 != 0 )
        {
          if ( v7 == 1 )
          {
            if ( v6 != nullptr && *v6 != 0 && V_stristr(pStr: msg, pSearch: v6) != nullptr )
              return;
            if ( m_pszString != nullptr && *m_pszString != 0 && V_stristr(pStr: msg, pSearch: m_pszString) == nullptr )
            {
              mycolor = (Color)-1765226296;
              g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: &mycolor, a3: msg);
              return;
            }
          }
        }
        else if ( m_pszString != nullptr && *m_pszString != 0 && V_stristr(pStr: msg, pSearch: m_pszString) == nullptr
               || v6 != nullptr && *v6 != 0 && V_stristr(pStr: msg, pSearch: v6) != nullptr )
        {
          return;
        }
      }
    }
    g_bInColorPrint = true;
    if ( (unsigned __int8)_Plat_IsInDebugSession() != 0
      && (con_trace.m_pParent == nullptr || con_trace.m_pParent->m_Value.m_nValue == 0) )
    {
      Sys_OutputDebugString(msg);
    }
    if ( sv.m_bIsDedicated )
    {
      g_bInColorPrint = false;
    }
    else
    {
      if ( g_fColorPrintf )
      {
        g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: clr, a3: "%s", msg);
      }
      else if ( g_fIsDebugPrint )
      {
        if ( GetBaseLocalClient()->m_nSignonState != 6 || !convisible )
          g_pCVar->ConsoleDPrintf(this: g_pCVar, a2: "%s", msg);
      }
      else
      {
        g_pCVar->ConsolePrintf(this: g_pCVar, a2: "%s", msg);
      }
      if ( GenericThreadLocals::CThreadLocalBase::Get(this: &g_bInSpew) == nullptr )
        _Msg(a1: "%s", msg);
      g_bInColorPrint = false;
      if ( (!debugprint || indeveloper && !convisible) && g_pConPanel != nullptr )
        CConPanel::AddToNotify(this: g_pConPanel, clr, msg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF360
// Name: void Con_ColorPrintf(class Color const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_ColorPrintf(const Color *clr, char *fmt, ...)
{
  DWORD CurrentThreadId; // ecx
  char pDest[4100]; // [esp+0h] [ebp-1004h] BYREF
  va_list params; // [esp+1014h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    autoMutex__.m_ownerID = 0;
    autoMutex__.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex__.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex__, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex__.m_depth;
  }
  if ( SV_RedirectActive() )
  {
    SV_RedirectAddText(txt: pDest);
  }
  else
  {
    if ( con_debuglog )
      Con_DebugLog(fmt: "%s", pDest);
    if ( con_initialized )
    {
      g_fColorPrintf = true;
      Con_ColorPrint(clr, msg: pDest);
      g_fColorPrintf = false;
      if ( --autoMutex__.m_depth != 0 )
        return;
      goto LABEL_15;
    }
  }
  if ( --autoMutex__.m_depth != 0 )
    return;
LABEL_15:
  _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100AF4D0
// Name: void Con_NXPrintf(struct con_nprint_s const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_NXPrintf(const con_nprint_s *info, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  CConPanel::Con_NXPrintf(this: g_pConPanel, info, msg: pDest);
}

//------------------------------------------------------------------------------
// Address: 0x101FF790
// Name: bool Con_IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Con_IsVisible()
{
  IEngineVGuiInternal *v0; // eax

  v0 = EngineVGui();
  return v0->IsConsoleVisible(this: v0);
}

} // namespace engine_xlsp
