// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_closecaption.cpp
// Functions: 140
// ============================================================

#include "game\client\hud_closecaption.h"

//------------------------------------------------------------------------------
// Address: 0x100F7E40
// Name: public: void CaptionLookup_t::SetHash(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CaptionLookup_t::SetHash(CaptionLookup_t *this, char *string)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned int v5[3]; // [esp+0h] [ebp-10h] BYREF
  unsigned int pulCRC; // [esp+Ch] [ebp-4h] BYREF

  v3 = _V_strlen(str: string);
  v4 = alloca(v3 + 1);
  V_strncpy(pDest: (char *)v5, pSrc: string, maxLen: v3 + 1);
  _V_strlower(start: (char *)v5);
  CRC32_Init(&pulCRC);
  CRC32_ProcessBuffer(&pulCRC, pBuffer: v5, nBuffer: v3);
  CRC32_Final(&pulCRC);
  this->hash = pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x100F7EB0
// Name: public: static bool AsyncCaption_t::BlockInfo_t::Less(struct AsyncCaption_t::BlockInfo_t const __near &,struct AsyncCaption_t::BlockInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AsyncCaption_t::BlockInfo_t::Less(
        const AsyncCaption_t::BlockInfo_t *lhs,
        const AsyncCaption_t::BlockInfo_t *rhs)
{
  if ( lhs->fileindex == rhs->fileindex )
    return lhs->blocknum < rhs->blocknum;
  else
    return lhs->fileindex < rhs->fileindex;
}

//------------------------------------------------------------------------------
// Address: 0x100F7EE0
// Name: public: static char const __near * CHudCloseCaption::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudCloseCaption::GetPanelClassName()
{
  return "CHudCloseCaption";
}

//------------------------------------------------------------------------------
// Address: 0x100F7EF0
// Name: private: static void __near * CHudCloseCaption::GetVar_m_flBackgroundAlpha(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
Color *__cdecl CHudCloseCaption::GetVar_m_flBackgroundAlpha(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._fgColor;
  else
    return (Color *)528;
}

//------------------------------------------------------------------------------
// Address: 0x100F7F10
// Name: private: static void __near * CHudCloseCaption::GetVar_m_flGrowTime(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlHandle<vgui::BuildGroup> *__cdecl CHudCloseCaption::GetVar_m_flGrowTime(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._buildGroup;
  else
    return (CUtlHandle<vgui::BuildGroup> *)536;
}

//------------------------------------------------------------------------------
// Address: 0x100F7F30
// Name: private: static void __near * CHudCloseCaption::GetVar_m_flItemHiddenTime(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
__int16 *__cdecl CHudCloseCaption::GetVar_m_flItemHiddenTime(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_nResizeDeltaX;
  else
    return (__int16 *)544;
}

//------------------------------------------------------------------------------
// Address: 0x100F7F50
// Name: private: static void __near * CHudCloseCaption::GetVar_m_flItemFadeInTime(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl CHudCloseCaption::GetVar_m_flItemFadeInTime(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._buildModeFlags;
  else
    return (unsigned __int16 *)552;
}

//------------------------------------------------------------------------------
// Address: 0x100F7F70
// Name: private: static void __near * CHudCloseCaption::GetVar_m_flItemFadeOutTime(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudCloseCaption::GetVar_m_flItemFadeOutTime(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1] + 172;
  else
    return 560;
}

//------------------------------------------------------------------------------
// Address: 0x100F7F90
// Name: private: static void __near * CHudCloseCaption::GetVar_m_nTopOffset(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl CHudCloseCaption::GetVar_m_nTopOffset(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._pinToSiblingCorner;
  else
    return (unsigned __int8 *)568;
}

//------------------------------------------------------------------------------
// Address: 0x100F7FB0
// Name: public: void CCloseCaptionWorkUnit::SetStream(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCloseCaptionWorkUnit::SetStream(CCloseCaptionWorkUnit *this, const wchar_t *stream)
{
  unsigned int v3; // edi
  wchar_t *v4; // eax

  C_BaseEntity::operator delete(pMem: this->m_pszStream);
  this->m_pszStream = nullptr;
  v3 = wcsnlen(wcs: stream, maxsize: 0x27D7u);
  v4 = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(v3 + 1) >> 31 != 0 ? -1 : 2 * (v3 + 1));
  this->m_pszStream = v4;
  wcsncpy(dest: v4, source: stream, count: v3);
  this->m_pszStream[v3] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F8010
// Name: void CaptionAsyncLoaderCallback(struct FileAsyncRequest_t const __near &,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CaptionAsyncLoaderCallback(const FileAsyncRequest_t *request)
{
  *((_BYTE *)request->pContext + 16) |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x100F8020
// Name: private: bool CHudCloseCaption::SplitCommand(wchar_t const __near * __near *,wchar_t __near *,wchar_t __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudCloseCaption::SplitCommand(
        CHudCloseCaption *this,
        const wchar_t **ppIn,
        wchar_t *cmd,
        wchar_t *args)
{
  const wchar_t *v5; // eax
  bool v6; // zf
  wchar_t *v8; // edx
  wchar_t *v9; // edi
  wchar_t *v10; // eax
  wchar_t i; // cx
  wchar_t v12; // cx
  const wchar_t *oldin; // [esp+Ch] [ebp+8h]

  v5 = *ppIn;
  v6 = **ppIn == 60;
  oldin = *ppIn;
  if ( !v6 )
    return 0;
  v8 = args;
  v9 = cmd;
  *args = 0;
  v10 = (wchar_t *)(v5 + 1);
  *cmd = 0;
  for ( i = *v10; *v10 != 0; ++v9 )
  {
    if ( i == 58 || i == 62 || i >= 9u && (i <= 0xDu || i == 32) )
      break;
    ++v10;
    *v9 = i;
    i = *v10;
  }
  *v9 = 0;
  if ( *v10 == 58 )
  {
    v12 = v10[1];
    ++v10;
    if ( v12 != 0 )
    {
      do
      {
        if ( v12 == 62 )
          break;
        ++v10;
        *v8 = v12;
        v12 = *v10;
        ++v8;
      }
      while ( *v10 != 0 );
    }
    *v8 = 0;
  }
  *ppIn += v10 - oldin;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F80D0
// Name: private: bool CHudCloseCaption::GetFloatCommandValue(wchar_t const __near *,wchar_t const __near *,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudCloseCaption::GetFloatCommandValue(
        CHudCloseCaption *this,
        const wchar_t *stream,
        const wchar_t *findcmd,
        float *value)
{
  const wchar_t *i; // edi
  int v5; // eax
  wchar_t *v6; // eax
  wchar_t v7; // cx
  wchar_t *v8; // esi
  bool v9; // zf
  wchar_t v10; // cx
  wchar_t *v11; // edx
  wchar_t args[256]; // [esp+Ch] [ebp-400h] BYREF
  wchar_t cmd[256]; // [esp+20Ch] [ebp-200h] BYREF

  for ( i = stream; i != nullptr; ++i )
  {
    v5 = *i;
    if ( (_WORD)v5 == 0 )
      break;
    if ( v5 == 60 )
    {
      args[0] = 0;
      v6 = (wchar_t *)(i + 1);
      cmd[0] = 0;
      v7 = i[1];
      v8 = cmd;
      if ( v7 != 0 )
      {
        do
        {
          if ( v7 == 58 || v7 == 62 || v7 >= 9u && (v7 <= 0xDu || v7 == 32) )
            break;
          ++v6;
          *v8 = v7;
          v7 = *v6;
          ++v8;
        }
        while ( *v6 != 0 );
      }
      v9 = *v6 == 58;
      *v8 = 0;
      if ( v9 )
      {
        v10 = v6[1];
        ++v6;
        v11 = args;
        if ( v10 != 0 )
        {
          do
          {
            if ( v10 == 62 )
              break;
            ++v6;
            *v11 = v10;
            v10 = *v6;
            ++v11;
          }
          while ( *v6 != 0 );
        }
        *v11 = 0;
      }
      i += v6 - i;
      if ( wcscmp(cmd, findcmd) == 0 )
      {
        *value = wcstod(nptr: args, endptr: nullptr);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F8210
// Name: private: bool CHudCloseCaption::StreamHasCommand(wchar_t const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudCloseCaption::StreamHasCommand(
        CHudCloseCaption *this,
        const wchar_t *stream,
        const wchar_t *search)
{
  const wchar_t *i; // edi
  int v4; // eax
  wchar_t v5; // cx
  wchar_t *v6; // eax
  wchar_t *v7; // esi
  bool v8; // zf
  wchar_t v9; // cx
  wchar_t *j; // edx
  wchar_t args[256]; // [esp+Ch] [ebp-400h] BYREF
  wchar_t cmd[256]; // [esp+20Ch] [ebp-200h] BYREF

  for ( i = stream; i != nullptr; ++i )
  {
    v4 = *i;
    if ( (_WORD)v4 == 0 )
      break;
    if ( v4 == 60 )
    {
      v5 = i[1];
      cmd[0] = 0;
      v6 = (wchar_t *)(i + 1);
      v7 = cmd;
      if ( v5 != 0 )
      {
        do
        {
          if ( v5 == 58 || v5 == 62 || v5 >= 9u && (v5 <= 0xDu || v5 == 32) )
            break;
          ++v6;
          *v7 = v5;
          v5 = *v6;
          ++v7;
        }
        while ( *v6 != 0 );
      }
      v8 = *v6 == 58;
      *v7 = 0;
      if ( v8 )
      {
        v9 = v6[1];
        ++v6;
        for ( j = args; v9 != 0; ++j )
        {
          if ( v9 == 62 )
            break;
          v9 = v6[1];
          ++v6;
        }
      }
      i += v6 - i;
      if ( wcscmp(cmd, search) == 0 )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F8330
// Name: private: void CHudCloseCaption::CreateFonts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::CreateFonts(CHudCloseCaption *this)
{
  vgui::ISchemeManager *v2; // esi
  vgui::ISchemeManager_vtbl *v3; // ebx
  int v4; // eax
  int v5; // esi

  v2 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = ((int (__stdcall *)(const char *))g_pVGuiSchemeManager->GetScheme)(a1: "basemodui_scheme");
  v5 = (int)v3->GetIScheme(this: v2, a2: v4);
  this->m_hFonts[0] = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 12))(
                        a1: v5,
                        a2: "CloseCaption_Normal",
                        a3: 1);
  this->m_hFonts[2] = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 12))(
                        a1: v5,
                        a2: "CloseCaption_Bold",
                        a3: 1);
  this->m_hFonts[1] = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 12))(
                        a1: v5,
                        a2: "CloseCaption_Italic",
                        a3: 1);
  this->m_hFonts[3] = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 12))(
                        a1: v5,
                        a2: "CloseCaption_BoldItalic",
                        a3: 1);
  if ( g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFonts[0]) >= 6 )
    this->m_nLineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFonts[0]);
  else
    this->m_nLineHeight = 6;
}

//------------------------------------------------------------------------------
// Address: 0x100F8400
// Name: public: void WorkUnitParams::Next(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WorkUnitParams::Next(WorkUnitParams *this, int lineheight)
{
  bool v3; // zf

  _V_memset(dest: (int)this, fill: nullptr, count: 0x4FB0u);
  this->x += this->width;
  v3 = !this->newline;
  this->out = (wchar_t *)this;
  this->width = 0;
  if ( !v3 )
  {
    this->y += lineheight;
    this->newline = false;
    this->x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8460
// Name: private: bool CHudCloseCaption::GetNoRepeatValue(wchar_t const __near *,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudCloseCaption::GetNoRepeatValue(CHudCloseCaption *this, const wchar_t *caption, float *retval)
{
  const wchar_t *i; // edi
  int v4; // eax
  wchar_t *v5; // eax
  wchar_t v6; // cx
  wchar_t *v7; // esi
  bool v8; // zf
  wchar_t v9; // cx
  wchar_t *v10; // edx
  wchar_t args[256]; // [esp+0h] [ebp-400h] BYREF
  wchar_t cmd[256]; // [esp+200h] [ebp-200h] BYREF

  *retval = 0.0;
  for ( i = caption; i != nullptr; ++i )
  {
    v4 = *i;
    if ( (_WORD)v4 == 0 )
      break;
    if ( v4 == 60 )
    {
      args[0] = 0;
      v5 = (wchar_t *)(i + 1);
      cmd[0] = 0;
      v6 = i[1];
      v7 = cmd;
      if ( v6 != 0 )
      {
        do
        {
          if ( v6 == 58 || v6 == 62 || v6 >= 9u && (v6 <= 0xDu || v6 == 32) )
            break;
          ++v5;
          *v7 = v6;
          v6 = *v5;
          ++v7;
        }
        while ( *v5 != 0 );
      }
      v8 = *v5 == 58;
      *v7 = 0;
      if ( v8 )
      {
        v9 = v5[1];
        ++v5;
        v10 = args;
        if ( v9 != 0 )
        {
          do
          {
            if ( v9 == 62 )
              break;
            ++v5;
            *v10 = v9;
            v9 = *v5;
            ++v10;
          }
          while ( *v5 != 0 );
        }
        *v10 = 0;
      }
      i += v5 - i;
      if ( wcscmp(cmd, L"norepeat") == 0 )
      {
        *retval = wcstod(nptr: args, endptr: nullptr);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F85B0
// Name: public: void CHudCloseCaption::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::Lock(CHudCloseCaption *this)
{
  this->m_bLocked = true;
}

//------------------------------------------------------------------------------
// Address: 0x100F85C0
// Name: EmitCaptionCompletion
// Source: json
//------------------------------------------------------------------------------
int __usercall EmitCaptionCompletion@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const char *partial,
        char (*commands)[64])
{
  int i; // edi
  const char *v7; // esi
  unsigned int substringLen; // [esp+0h] [ebp-Ch]
  char *substring; // [esp+4h] [ebp-8h]
  int current; // [esp+8h] [ebp-4h]

  current = 0;
  if ( g_pVGuiLocalize == nullptr )
    return 0;
  substring = nullptr;
  substringLen = 0;
  if ( _V_strstr(s1: partial, search: "cc_emit") != nullptr && strlen(partial) > 8 )
  {
    substring = (char *)(partial + 8);
    substringLen = strlen(partial + 8);
  }
  for ( i = ((int (__thiscall *)(vgui::ILocalize *, int, int))g_pVGuiLocalize->GetFirstStringIndex)(
              a1: g_pVGuiLocalize,
              a2,
              a3);
        i != -1;
        i = ((int (__thiscall *)(vgui::ILocalize *))g_pVGuiLocalize->GetNextStringIndex)(a1: g_pVGuiLocalize) )
  {
    if ( current >= 64 )
      break;
    v7 = (const char *)((int (__thiscall *)(vgui::ILocalize *, int, int))g_pVGuiLocalize->GetNameByIndex)(
                         a1: g_pVGuiLocalize,
                         a2: i,
                         a3: a1);
    if ( v7 != nullptr && (substring == nullptr || V_strncasecmp(s1: v7, s2: substring, n: substringLen) == 0) )
    {
      V_snprintf(pDest: (char *)commands, maxLen: 64, pFormat: "%s %s", "cc_emit", v7);
      ++current;
      ++commands;
    }
    a1 = i;
  }
  return current;
}

//------------------------------------------------------------------------------
// Address: 0x100F86C0
// Name: cc_showblocks
// Source: json
//------------------------------------------------------------------------------
void __cdecl cc_showblocks()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: 0);
  Element = CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
  if ( Element != nullptr )
    BYTE2(Element[10].m_HudRenderGroups.m_Memory.m_pMemory) = BYTE2(Element[10].m_HudRenderGroups.m_Memory.m_pMemory) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F86F0
// Name: private: void CHudCloseCaption::SetUseAsianWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::SetUseAsianWordWrapping(CHudCloseCaption *this)
{
  const char *(__thiscall *GetLanguage)(vgui::ISchemeManager *); // edx
  const char *v3; // eax
  const char *v4; // esi

  if ( bCheckForAsianLanguage )
  {
    this->m_bUseAsianWordWrapping = bIsAsianLanguage;
  }
  else
  {
    GetLanguage = g_pVGuiSchemeManager->GetLanguage;
    bCheckForAsianLanguage = true;
    v3 = GetLanguage(this: g_pVGuiSchemeManager);
    v4 = v3;
    if ( v3 != nullptr )
    {
      if ( _V_stricmp(s1: v3, s2: "japanese") != 0
        && _V_stricmp(s1: v4, s2: "schinese") != 0
        && _V_stricmp(s1: v4, s2: "tchinese") != 0 )
      {
        this->m_bUseAsianWordWrapping = bIsAsianLanguage;
      }
      else
      {
        this->m_bUseAsianWordWrapping = true;
        bIsAsianLanguage = true;
      }
    }
    else
    {
      this->m_bUseAsianWordWrapping = bIsAsianLanguage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8790
// Name: public: struct memhandle_t__ __near * CManagedDataCacheClient<struct AsyncCaptionData_t,struct asynccaptionparams_t,struct AsyncCaptionData_t __near *>::CacheCreate(struct asynccaptionparams_t const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const asynccaptionparams_t *__thiscall CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>::CacheCreate(
        CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *> *this,
        memhandle_t__ *createParams,
        unsigned int flags)
{
  const asynccaptionparams_t *v3; // edi
  _BYTE *v5; // eax
  int *v6; // esi
  unsigned int blocksize; // edi
  void *v8; // eax
  int v9; // edx
  unsigned int v11; // [esp-8h] [ebp-14h]

  v3 = (const asynccaptionparams_t *)createParams;
  this->m_pCache->EnsureCapacity(this: this->m_pCache, a2: *((_DWORD *)createParams + 4) + 24, a3: 1u);
  v5 = MemAlloc_Alloc(nSize: 0x18u);
  v6 = nullptr;
  if ( v5 != nullptr )
  {
    v5[16] &= 0xFCu;
    *((_DWORD *)v5 + 1) = 0;
    *((_DWORD *)v5 + 3) = 0;
    *((_DWORD *)v5 + 5) = 0;
    *(_DWORD *)v5 = -1;
    *((_DWORD *)v5 + 2) = -1;
    v6 = (int *)v5;
  }
  *v6 = v3->blocktoload;
  v6[2] = v3->fileindex;
  blocksize = v3->blocksize;
  v6[3] = blocksize;
  v8 = MemAlloc_Alloc(nSize: blocksize);
  v11 = flags;
  v9 = v6[3];
  v6[1] = (int)v8;
  this->m_pCache->AddEx(this: this->m_pCache, a2: (unsigned int)v6, a3: v6, a4: v9 + 24, a5: v11, a6: &createParams);
  return (const asynccaptionparams_t *)createParams;
}

//------------------------------------------------------------------------------
// Address: 0x100F88E0
// Name: public: float CCloseCaptionItem::GetAlpha(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCloseCaptionItem::GetAlpha(
        CCloseCaptionItem *this,
        float fadeintimehidden,
        float fadeintime,
        float fadeouttime)
{
  float v4; // xmm0_4
  float m_flTimeToLive; // xmm2_4
  float v6; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4

  v4 = this->m_flInitialLifeSpan - this->m_flTimeToLive;
  m_flTimeToLive = this->m_flTimeToLive;
  if ( (float)(fadeintimehidden + fadeintime) <= 0.001 || (float)(fadeintimehidden + fadeintime) <= v4 )
  {
    if ( fadeouttime <= 0.001 || fadeouttime <= m_flTimeToLive )
    {
      return 1.0;
    }
    else
    {
      v8 = m_flTimeToLive / fadeouttime;
      v9 = 0.0;
      if ( v8 < 0.0 )
        return v9;
      v9 = 1.0;
      if ( v8 > 1.0 )
        return v9;
      else
        return v8;
    }
  }
  else if ( v4 < fadeintimehidden )
  {
    return 0.0;
  }
  else
  {
    v6 = 1.0;
    if ( fadeintime <= 0.001 )
      return v6;
    v6 = (float)(v4 - fadeintimehidden) / fadeintime;
    if ( v6 < 0.0 )
      return 0.0;
    if ( v6 <= 1.0 )
      return v6;
    else
      return 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F89C0
// Name: public: void AsyncCaptionData_t::AsyncLoad(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AsyncCaptionData_t::AsyncLoad(AsyncCaptionData_t *this, const char *fileName, int blockOffset)
{
  int m_nBlockSize; // ecx
  FileAsyncRequest_t fileRequest; // [esp+4h] [ebp-2Ch] BYREF

  memset(dst: (int)&fileRequest, value: nullptr, count: sizeof(fileRequest));
  fileRequest.pData = this->m_pBlockData;
  m_nBlockSize = this->m_nBlockSize;
  fileRequest.pContext = this;
  fileRequest.nBytes = m_nBlockSize;
  fileRequest.pszFilename = fileName;
  fileRequest.nOffset = blockOffset;
  fileRequest.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
  fileRequest.pfnCallback = (void (__cdecl *)(const FileAsyncRequest_t *, int, FSAsyncStatus_t))CaptionAsyncLoaderCallback;
  fileRequest.flags = 0;
  fileRequest.priority = -1;
  fileRequest.pszPathID = "GAME";
  filesystem->AsyncReadMultiple(this: filesystem, a2: &fileRequest, a3: 1, a4: &this->m_hAsyncControl);
}

//------------------------------------------------------------------------------
// Address: 0x100F8A40
// Name: public: virtual void CHudCloseCaption::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::ApplySchemeSettings(CHudCloseCaption *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, (int)pScheme);
  CHudCloseCaption::SetUseAsianWordWrapping(this: (CHudCloseCaption *)((char *)this - 56));
}

//------------------------------------------------------------------------------
// Address: 0x100F8A60
// Name: cc_flush
// Source: json
//------------------------------------------------------------------------------
void __cdecl cc_flush()
{
  CHud *Hud; // eax

  Hud = GetHud(nSlot: 0);
  if ( CHud::FindElement(this: Hud, pName: "CHudCloseCaption") != nullptr )
    g_AsyncCaptionResourceManager.m_pCache->Flush(this: g_AsyncCaptionResourceManager.m_pCache, a2: true, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x100F8A90
// Name: public: void AsyncCaptionData_t::DestroyResource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AsyncCaptionData_t::DestroyResource(AsyncCaptionData_t *this)
{
  char v2; // al

  v2 = *((_BYTE *)this + 16);
  if ( (v2 & 1) != 0 && (v2 & 2) == 0 )
    filesystem->AsyncFinish(this: filesystem, a2: this->m_hAsyncControl, a3: true);
  filesystem->AsyncRelease(this: filesystem, a2: this->m_hAsyncControl);
  C_BaseEntity::operator delete(pMem: this->m_pBlockData);
  this->m_pBlockData = nullptr;
  C_BaseEntity::operator delete(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x100F8AF0
// Name: public: virtual bool CManagedDataCacheClient<struct AsyncCaptionData_t,struct asynccaptionparams_t,struct AsyncCaptionData_t __near *>::HandleCacheNotification(struct DataCacheNotification_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>::HandleCacheNotification(
        CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *> *this,
        const DataCacheNotification_t *notification)
{
  if ( (unsigned int)(notification->type - 1) > 2 )
    return 0;
  AsyncCaptionData_t::DestroyResource(this: (AsyncCaptionData_t *)notification->clientId);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F8C40
// Name: private: void CHudCloseCaption::DrawStream(struct wrect_s __near &,struct wrect_s __near &,class CCloseCaptionItem __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHudCloseCaption::DrawStream(
        CHudCloseCaption *this@<ecx>,
        const wchar_t *a2@<ebx>,
        unsigned int a3@<edi>,
        int a4@<esi>,
        wrect_s *rcText,
        wrect_s *rcWindow,
        CCloseCaptionItem *item,
        int iFadeLine,
        float flFadeLineAlpha)
{
  CCloseCaptionItem *v9; // esi
  int m_Size; // edi
  int v11; // eax
  CCloseCaptionWorkUnit *v12; // esi
  float v13; // xmm0_4
  int v14; // edi
  int v15; // ebx
  int m_nHeight; // ecx
  int bottom; // edx
  long double v18; // st7
  const wchar_t *m_pszStream; // eax
  unsigned int v20; // eax
  const wchar_t *v21; // esi
  int rcOut; // [esp+14h] [ebp-2Ch]
  int rcOut_12; // [esp+20h] [ebp-20h]
  int c; // [esp+24h] [ebp-1Ch]
  unsigned int useF; // [esp+28h] [ebp-18h]
  int i; // [esp+2Ch] [ebp-14h]
  float alpha; // [esp+30h] [ebp-10h]
  float flDista; // [esp+34h] [ebp-Ch]
  Color flDist; // [esp+34h] [ebp-Ch]
  int v33; // [esp+38h] [ebp-8h]
  Color v34; // [esp+3Ch] [ebp-4h]

  v9 = item;
  m_Size = item->m_Work.m_Size;
  c = m_Size;
  alpha = CCloseCaptionItem::GetAlpha(
            this: item,
            fadeintimehidden: this->m_flItemHiddenTime,
            fadeintime: this->m_flItemFadeInTime,
            fadeouttime: this->m_flItemFadeOutTime);
  v11 = 0;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v12 = v9->m_Work.m_Memory.m_pMemory[v11];
      v13 = alpha;
      useF = v12->m_hFont;
      v14 = rcText->top + v12->m_nY;
      v15 = rcText->left + v12->m_nX + 3 + v12->m_nWidth;
      rcOut = rcText->left + v12->m_nX + 3;
      m_nHeight = v12->m_nHeight;
      rcOut_12 = m_nHeight + v14;
      if ( v11 == iFadeLine )
      {
        v13 = alpha * flFadeLineAlpha;
        goto LABEL_11;
      }
      if ( v14 >= rcWindow->top )
      {
        bottom = rcWindow->bottom;
        if ( rcOut_12 <= bottom )
          break;
      }
LABEL_19:
      i = ++v11;
      if ( v11 >= c )
        return;
      v9 = item;
    }
    if ( v14 > bottom )
    {
      v18 = Bias(x: (float)(v14 - bottom) / (float)((float)m_nHeight * 0.25), biasAmt: 0x3E4CCCCDu);
      if ( v18 > 1.0 )
      {
LABEL_18:
        v11 = i;
        goto LABEL_19;
      }
      flDista = v18;
      v13 = (float)(1.0 - flDista) * alpha;
    }
LABEL_11:
    flDist = v12->m_Color;
    flDist._color[3] = (int)(float)((float)flDist._color[3] * v13);
    if ( !item->m_bValid )
    {
      v34._color[3] = (int)(float)(v13 * 255.0);
      *(_WORD *)v34._color = -1;
      v34._color[2] = -1;
      HIBYTE(v33) = v34._color[3];
      flDist = v34;
      LOWORD(v33) = 25700;
      BYTE2(v33) = 40;
      ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: v33);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: rcOut, a3: v14, a4: v15 + 2, a5: rcOut_12);
    }
    ((void (__thiscall *)(vgui::ISurface *, unsigned int, const wchar_t *, unsigned int, int))g_pVGuiSurface->DrawSetTextFont)(
      a1: g_pVGuiSurface,
      a2: useF,
      a3: a2,
      a4: a3,
      a5: a4);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: rcOut, a3: v14);
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetTextColor)(a1: g_pVGuiSurface, a2: flDist);
    m_pszStream = v12->m_pszStream;
    if ( m_pszStream == nullptr )
      m_pszStream = &szFunFact;
    v20 = wcsnlen(wcs: m_pszStream, maxsize: 0x27D8u);
    v21 = v12->m_pszStream;
    if ( v21 == nullptr )
      v21 = &szFunFact;
    a4 = 0;
    a3 = v20;
    a2 = v21;
    ((void (*)(void))g_pVGuiSurface->DrawPrintText)();
    goto LABEL_18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8E70
// Name: public: bool CAsyncCaption::GetStream(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncCaption::GetStream(CAsyncCaption *this, wchar_t *buf, unsigned int bufSizeInBytes)
{
  CAsyncCaption *v3; // esi
  int v4; // eax
  int m_Size; // ecx
  CAsyncCaption::caption_t **m_pMemory; // edx
  unsigned int v7; // eax
  unsigned int v8; // edi
  int v9; // ebx
  CAsyncCaption::caption_t *v11; // esi
  wchar_t *stream; // eax
  wchar_t *v13; // edx
  __int16 v14; // cx
  unsigned int v15; // eax
  wchar_t *v16; // edi
  wchar_t v17; // cx
  wchar_t *v18; // edi
  wchar_t v19; // ax
  unsigned int v20; // [esp+4h] [ebp-Ch]
  CAsyncCaption *v21; // [esp+8h] [ebp-8h]
  int c; // [esp+Ch] [ebp-4h]
  unsigned int maxlen; // [esp+1Ch] [ebp+Ch]

  v3 = this;
  v4 = 0;
  *buf = 0;
  m_Size = this->m_Tokens.m_Size;
  v21 = v3;
  c = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_6:
    v7 = bufSizeInBytes >> 1;
    v8 = 0;
    v9 = 0;
    maxlen = bufSizeInBytes >> 1;
    if ( m_Size > 0 )
    {
      while ( 1 )
      {
        v11 = v3->m_Tokens.m_Memory.m_pMemory[v9];
        v20 = v8 + wcsnlen(wcs: v11->stream, maxsize: v7) + 1;
        if ( v20 >= maxlen )
          break;
        stream = v11->stream;
        v13 = stream;
        do
          v14 = *stream++;
        while ( v14 != 0 );
        v15 = (char *)stream - (char *)v13;
        v16 = buf - 1;
        do
        {
          v17 = v16[1];
          ++v16;
        }
        while ( v17 != 0 );
        qmemcpy(v16, v13, v15);
        if ( v9 < c - 1 )
        {
          v18 = buf - 1;
          do
          {
            v19 = v18[1];
            ++v18;
          }
          while ( v19 != 0 );
          wcscpy(v18, L" ");
        }
        v8 = v20;
        if ( ++v9 >= c )
          break;
        v3 = v21;
        v7 = maxlen;
      }
    }
    return 1;
  }
  else
  {
    m_pMemory = v3->m_Tokens.m_Memory.m_pMemory;
    while ( *m_pMemory != nullptr && (*m_pMemory)->stream != nullptr )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_6;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8F70
// Name: public: void CHudCloseCaption::FindSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHudCloseCaption::FindSound(CHudCloseCaption *this@<ecx>, int a2@<esi>, const char *pchANSI)
{
  CHudCloseCaption *v3; // edi
  AsyncCaption_t *v4; // ebx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // esi
  int blockNum; // esi
  char *v8; // eax
  int v9; // edi
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // edx
  void *v11; // esi
  unsigned int length; // ecx
  int k; // esi
  char *v14; // edi
  int m; // esi
  char *v16; // edi
  unsigned int blocksize; // [esp-10h] [ebp-D40h]
  wchar_t stream[1024]; // [esp+4h] [ebp-D2Ch] BYREF
  char streamANSI[1024]; // [esp+804h] [ebp-52Ch] BYREF
  char fn[256]; // [esp+C04h] [ebp-12Ch] BYREF
  CaptionLookup_t search; // [esp+D04h] [ebp-2Ch] BYREF
  CHudCloseCaption *v23; // [esp+D10h] [ebp-20h]
  int nLoadedBlock; // [esp+D14h] [ebp-1Ch]
  int i; // [esp+D18h] [ebp-18h]
  int j; // [esp+D1Ch] [ebp-14h]
  unsigned int v27; // [esp+D20h] [ebp-10h]
  CaptionLookup_t *lu; // [esp+D24h] [ebp-Ch]
  unsigned __int8 *block; // [esp+D28h] [ebp-8h]
  unsigned int v30; // [esp+D2Ch] [ebp-4h]

  v3 = this;
  v23 = this;
  i = 0;
  if ( this->m_AsyncCaptions.m_Size > 0 )
  {
    v27 = 0;
    do
    {
      v4 = &v3->m_AsyncCaptions.m_Memory.m_pMemory[v27 / 0x54];
      v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4->m_Header.blocksize);
      blocksize = v4->m_Header.blocksize;
      v6 = v5;
      block = v5;
      nLoadedBlock = -1;
      _V_memset(dest: (int)v5, fill: nullptr, count: blocksize);
      j = 0;
      if ( v4->m_CaptionDirectory.m_Size > 0 )
      {
        v30 = 0;
        do
        {
          blockNum = v4->m_CaptionDirectory.m_Memory.m_pMemory[v30 / 0xC].blockNum;
          lu = &v4->m_CaptionDirectory.m_Memory.m_pMemory[v30 / 0xC];
          v8 = (char *)CUtlSymbol::String(this: &v4->m_DataBaseFile);
          V_strncpy(pDest: fn, pSrc: v8, maxLen: 256);
          V_FixSlashes(pname: fn, separator: 92);
          _V_strlower(start: fn);
          v9 = v4->m_Header.dataoffset + blockNum * v4->m_Header.blocksize;
          if ( blockNum != nLoadedBlock )
          {
            Open = filesystem->Open;
            nLoadedBlock = blockNum;
            v11 = Open(this: &filesystem->IBaseFileSystem, a2: fn, a3: "rb", a4: nullptr);
            filesystem->Seek(this: &filesystem->IBaseFileSystem, a2: v11, a3: v9, a4: FILESYSTEM_SEEK_CURRENT);
            filesystem->Read(this: &filesystem->IBaseFileSystem, a2: block, a3: v4->m_Header.blocksize, a4: v11);
            filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v11);
          }
          length = lu->length;
          if ( (unsigned __int16)length >= 0x800u )
            length = 2048;
          _V_memcpy(dest: (unsigned __int8 *)stream, src: &block[lu->offset], count: length);
          _V_UCS2ToUTF8(a1: stream, a2: streamANSI, a3: 1024);
          streamANSI[1023] = 0;
          if ( V_stristr(a1: streamANSI, a2: (const char *)v4, pStr: streamANSI, pSearch: pchANSI) != nullptr )
          {
            _Msg(a1: "found '%s' in %s\n", streamANSI, fn);
            for ( k = soundemitterbase->First(this: soundemitterbase);
                  k != soundemitterbase->InvalidIndex(this: soundemitterbase);
                  k = ((int (__thiscall *)(ISoundEmitterSystemBase *))soundemitterbase->Next)(a1: soundemitterbase) )
            {
              v14 = (char *)((int (__thiscall *)(ISoundEmitterSystemBase *, int, int))soundemitterbase->GetSoundName)(
                              a1: soundemitterbase,
                              a2: k,
                              a3: a2);
              CaptionLookup_t::SetHash(this: &search, string: v14);
              if ( search.hash == lu->hash )
                _Msg(a1: "    '%s' matches\n", v14);
              a2 = k;
            }
            for ( m = g_pVGuiLocalize->GetFirstStringIndex(this: g_pVGuiLocalize);
                  m != -1;
                  m = ((int (__thiscall *)(vgui::ILocalize *))g_pVGuiLocalize->GetNextStringIndex)(a1: g_pVGuiLocalize) )
            {
              v16 = (char *)((int (__thiscall *)(vgui::ILocalize *, int, int))g_pVGuiLocalize->GetNameByIndex)(
                              a1: g_pVGuiLocalize,
                              a2: m,
                              a3: a2);
              CaptionLookup_t::SetHash(this: &search, string: v16);
              if ( search.hash == lu->hash )
                _Msg(a1: "    '%s' localization matches\n", v16);
              a2 = m;
            }
          }
          v30 += 12;
          ++j;
        }
        while ( j < v4->m_CaptionDirectory.m_Size );
        v6 = block;
        v3 = v23;
      }
      C_BaseEntity::operator delete(pMem: v6);
      v27 += 84;
      ++i;
    }
    while ( i < v3->m_AsyncCaptions.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA820
// Name: public: void CHudCloseCaption::OnFinishAsyncLoad(int,int,struct AsyncCaptionData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::OnFinishAsyncLoad(
        CHudCloseCaption *this,
        int nFileIndex,
        int nBlockNum,
        AsyncCaptionData_t *pData)
{
  int m_Head; // eax
  int v5; // eax
  CAsyncCaption *v6; // edi
  int v7; // edx
  CAsyncCaption::caption_t *v8; // ebx
  CaptionLookup_t *v9; // esi
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // eax
  int v12; // [esp+0h] [ebp-14h]
  int m_Size; // [esp+4h] [ebp-10h]
  CAsyncCaption *item; // [esp+8h] [ebp-Ch]
  int v15; // [esp+Ch] [ebp-8h]
  CHudCloseCaption *i; // [esp+10h] [ebp-4h]

  m_Head = this->m_AsyncWork.m_Head;
  for ( i = this;
        m_Head != 0xFFFF;
        m_Head = *(unsigned __int16 *)((char *)&this->m_AsyncWork.m_Memory.m_pMemory->m_Next + v5) )
  {
    v5 = 8 * (unsigned __int16)m_Head;
    v6 = *(CAsyncCaption **)((char *)&this->m_AsyncWork.m_Memory.m_pMemory->m_Element + v5);
    v12 = v5;
    item = v6;
    if ( v6 != nullptr )
    {
      v7 = 0;
      m_Size = v6->m_Tokens.m_Size;
      v15 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v8 = v6->m_Tokens.m_Memory.m_pMemory[v7];
          if ( v8 != nullptr && v8->stream == nullptr && v8->fileindex == nFileIndex )
          {
            v9 = &this->m_AsyncCaptions.m_Memory.m_pMemory[nFileIndex].m_CaptionDirectory.m_Memory.m_pMemory[v8->dirindex];
            if ( v9->blockNum == nBlockNum )
            {
              v10 = &pData->m_pBlockData[v9->offset];
              v11 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 2 * (v9->length >> 1));
              v8->stream = (wchar_t *)v11;
              memcpy(dst: v11, src: v10, count: v9->length);
              v6 = item;
              v7 = v15;
            }
            this = i;
          }
          v15 = ++v7;
        }
        while ( v7 < m_Size );
        v5 = v12;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA920
// Name: cc_findsound
// Source: json
//------------------------------------------------------------------------------
void __cdecl cc_findsound(const CCommand *args)
{
  CHud *Hud; // eax
  CHudCloseCaption *Element; // eax
  const char *v3; // edx

  if ( args->m_nArgc == 2 )
  {
    Hud = GetHud(nSlot: 0);
    Element = (CHudCloseCaption *)CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
    if ( Element != nullptr )
    {
      v3 = prType;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      CHudCloseCaption::FindSound(this: Element, pchANSI: v3);
    }
  }
  else
  {
    _Msg(a1: "usage:  cc_findsound 'substring'\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC240
// Name: public: CCloseCaptionItem::CCloseCaptionItem(wchar_t const __near *,float,float,float,bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CCloseCaptionItem *__thiscall CCloseCaptionItem::CCloseCaptionItem(
        CCloseCaptionItem *this,
        const wchar_t *stream,
        float timetolive,
        float addedtime,
        float predisplay,
        bool valid,
        bool fromplayer,
        bool bSFXEntry,
        bool bLowPriorityEntry)
{
  this->m_bSFXEntry = bSFXEntry;
  this->m_bFromPlayer = fromplayer;
  this->m_flTimeToLive = 0.0;
  this->m_flAddedTime = addedtime;
  this->m_bValid = false;
  this->m_nTotalWidth = 0;
  this->m_nTotalHeight = 0;
  this->m_bSizeComputed = false;
  this->m_bLowPriorityEntry = bLowPriorityEntry;
  this->m_Work.m_Memory.m_pMemory = nullptr;
  this->m_Work.m_Memory.m_nAllocationCount = 0;
  this->m_Work.m_Memory.m_nGrowSize = 0;
  this->m_Work.m_Size = 0;
  this->m_Work.m_pElements = nullptr;
  wcsncpy(dest: this->m_szStream, source: stream, count: 0x27D8u);
  this->m_flTimeToLive = timetolive;
  this->m_flInitialLifeSpan = timetolive;
  this->m_flPreDisplayTime = cc_predisplay_time.m_pParent->m_Value.m_fValue + predisplay;
  this->m_bValid = valid;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FC300
// Name: public: CCloseCaptionItem::~CCloseCaptionItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCloseCaptionItem::~CCloseCaptionItem(CCloseCaptionItem *this)
{
  CCloseCaptionWorkUnit *v2; // edi

  while ( this->m_Work.m_Size > 0 )
  {
    v2 = *this->m_Work.m_Memory.m_pMemory;
    if ( this->m_Work.m_Size - 1 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)this->m_Work.m_Memory.m_pMemory,
        src: (unsigned __int8 *)this->m_Work.m_Memory.m_pMemory + 4,
        count: 4 * (this->m_Work.m_Size - 1));
    --this->m_Work.m_Size;
    if ( v2 != nullptr )
    {
      C_BaseEntity::operator delete(pMem: v2->m_pszStream);
      v2->m_pszStream = nullptr;
      C_BaseEntity::operator delete(pMem: v2);
    }
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Work);
}

//------------------------------------------------------------------------------
// Address: 0x100FC380
// Name: public: void CAsyncCaptionResourceManager::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncCaptionResourceManager::Clear(CAsyncCaptionResourceManager *this)
{
  CAsyncCaptionResourceManager *v1; // ebx
  CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl*)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short> > *p_m_RequestedBlocks; // edi
  int v3; // esi
  int c; // [esp+4h] [ebp-10h]
  int file; // [esp+8h] [ebp-Ch]
  int v7; // [esp+10h] [ebp-4h]

  v1 = this;
  file = 0;
  if ( this->m_Db.m_Size > 0 )
  {
    v7 = 0;
    do
    {
      p_m_RequestedBlocks = &v1->m_Db.m_Memory.m_pMemory[v7].m_RequestedBlocks;
      v3 = 0;
      c = p_m_RequestedBlocks->m_NumElements;
      if ( p_m_RequestedBlocks->m_NumElements != 0 )
      {
        do
        {
          v1->m_pCache->Remove(
            this: v1->m_pCache,
            a2: p_m_RequestedBlocks->m_Elements.m_pMemory[(unsigned __int16)v3].m_Data.handle,
            a3: nullptr,
            a4: nullptr,
            a5: true);
          v1 = this;
          ++v3;
        }
        while ( v3 < c );
      }
      CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: p_m_RequestedBlocks);
      ++v7;
      ++file;
    }
    while ( file < v1->m_Db.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC6A0
// Name: public: static void CHudCloseCaption::PanelAnimationVar_m_flBackgroundAlpha::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCloseCaption::PanelAnimationVar_m_flBackgroundAlpha::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCloseCaption::PanelAnimationVar_m_flBackgroundAlpha::InitVar'::`2'::bAdded )
  {
    `CHudCloseCaption::PanelAnimationVar_m_flBackgroundAlpha::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCloseCaption");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BgAlpha";
    src.m_pszVariable = "m_flBackgroundAlpha";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "192";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCloseCaption::GetVar_m_flBackgroundAlpha;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC700
// Name: public: static void CHudCloseCaption::PanelAnimationVar_m_flGrowTime::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCloseCaption::PanelAnimationVar_m_flGrowTime::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCloseCaption::PanelAnimationVar_m_flGrowTime::InitVar'::`2'::bAdded )
  {
    `CHudCloseCaption::PanelAnimationVar_m_flGrowTime::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCloseCaption");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "GrowTime";
    src.m_pszVariable = "m_flGrowTime";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "0.25";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCloseCaption::GetVar_m_flGrowTime;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC760
// Name: public: static void CHudCloseCaption::PanelAnimationVar_m_flItemHiddenTime::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCloseCaption::PanelAnimationVar_m_flItemHiddenTime::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCloseCaption::PanelAnimationVar_m_flItemHiddenTime::InitVar'::`2'::bAdded )
  {
    `CHudCloseCaption::PanelAnimationVar_m_flItemHiddenTime::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCloseCaption");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "ItemHiddenTime";
    src.m_pszVariable = "m_flItemHiddenTime";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "0.2";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCloseCaption::GetVar_m_flItemHiddenTime;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC7C0
// Name: public: static void CHudCloseCaption::PanelAnimationVar_m_flItemFadeInTime::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCloseCaption::PanelAnimationVar_m_flItemFadeInTime::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCloseCaption::PanelAnimationVar_m_flItemFadeInTime::InitVar'::`2'::bAdded )
  {
    `CHudCloseCaption::PanelAnimationVar_m_flItemFadeInTime::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCloseCaption");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "ItemFadeInTime";
    src.m_pszVariable = "m_flItemFadeInTime";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "0.15";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCloseCaption::GetVar_m_flItemFadeInTime;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC820
// Name: public: static void CHudCloseCaption::PanelAnimationVar_m_flItemFadeOutTime::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCloseCaption::PanelAnimationVar_m_flItemFadeOutTime::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCloseCaption::PanelAnimationVar_m_flItemFadeOutTime::InitVar'::`2'::bAdded )
  {
    `CHudCloseCaption::PanelAnimationVar_m_flItemFadeOutTime::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCloseCaption");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "ItemFadeOutTime";
    src.m_pszVariable = "m_flItemFadeOutTime";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "0.3";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCloseCaption::GetVar_m_flItemFadeOutTime;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC880
// Name: public: static void CHudCloseCaption::PanelAnimationVar_m_nTopOffset::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCloseCaption::PanelAnimationVar_m_nTopOffset::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCloseCaption::PanelAnimationVar_m_nTopOffset::InitVar'::`2'::bAdded )
  {
    `CHudCloseCaption::PanelAnimationVar_m_nTopOffset::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCloseCaption");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "topoffset";
    src.m_pszVariable = "m_nTopOffset";
    src.m_pszType = "int";
    src.m_pszDefaultValue = "40";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCloseCaption::GetVar_m_nTopOffset;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC8E0
// Name: public: void CCloseCaptionItem::AddWork(class CCloseCaptionWorkUnit __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCloseCaptionItem::AddWork(CCloseCaptionItem *this, vgui::TreeNode *unit)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Work; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_Work.m_Memory.m_nAllocationCount;
  p_m_Work = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Work;
  m_Size = this->m_Work.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Work, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Work[1].m_pMemory;
  m_pMemory = p_m_Work->m_pMemory;
  v6 = (int)p_m_Work[1].m_pMemory - m_Size - 1;
  p_m_Work[1].m_nAllocationCount = (int)p_m_Work->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_Work->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = unit;
}

//------------------------------------------------------------------------------
// Address: 0x100FC950
// Name: public: void CHudCloseCaption::Process(wchar_t const __near *,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::Process(
        CHudCloseCaption *this,
        wchar_t *stream,
        float duration,
        bool fromplayer,
        wchar_t *direct)
{
  const wchar_t *v6; // edi
  wchar_t *v7; // esi
  char HasCommand; // bl
  int m_nValue; // eax
  int m_Size; // eax
  float v11; // xmm0_4
  float m_flTimeToLive; // xmm1_4
  wchar_t *v13; // esi
  const wchar_t *v14; // ebx
  char v15; // al
  wchar_t *v16; // edi
  CCloseCaptionItem *v17; // eax
  CCloseCaptionItem *v18; // ebx
  CHudCloseCaption *v19; // esi
  int v20; // edi
  int v21; // eax
  CCloseCaptionItem **v22; // ecx
  int v23; // eax
  CCloseCaptionItem **v24; // eax
  char FloatCommandValue; // al
  int v26; // eax
  int v27; // ecx
  bool v28; // zf
  CCloseCaptionItem *v29; // eax
  CCloseCaptionItem *v30; // ebx
  CHudCloseCaption *v31; // esi
  int v32; // edi
  int m_nAllocationCount; // eax
  CCloseCaptionItem **m_pMemory; // ecx
  int v35; // eax
  CCloseCaptionItem **v36; // eax
  float v37; // xmm0_4
  wchar_t v38[10200]; // [esp+28h] [ebp-53C8h] BYREF
  wchar_t cmd[256]; // [esp+4FD8h] [ebp-418h] BYREF
  wchar_t args[256]; // [esp+51D8h] [ebp-218h] BYREF
  bool bSFXEntry[4]; // [esp+53D8h] [ebp-18h]
  bool bLowPriorityEntry[4]; // [esp+53DCh] [ebp-14h]
  __int64 timetolive; // [esp+53E0h] [ebp-10h]
  float value; // [esp+53E8h] [ebp-8h] BYREF
  CHudCloseCaption *v45; // [esp+53ECh] [ebp-4h]
  bool streama; // [esp+53F8h] [ebp+8h]
  float predisplay; // [esp+53FCh] [ebp+Ch]

  v45 = this;
  if ( (_BYTE)direct != 0
    || closecaption.m_pParent != nullptr && closecaption.m_pParent->m_Value.m_nValue != 0 && !this->m_bLocked )
  {
    v6 = stream;
    v7 = stream;
    if ( *stream != 0 )
    {
      while ( iswspace(c: *v7) != 0 )
      {
        if ( *++v7 == 0 )
          return;
      }
      HasCommand = CHudCloseCaption::StreamHasCommand(this, stream, search: L"sfx");
      bSFXEntry[0] = HasCommand;
      bLowPriorityEntry[0] = CHudCloseCaption::StreamHasCommand(this: v45, stream, search: L"low");
      if ( cc_subtitles.m_pParent == nullptr || cc_subtitles.m_pParent->m_Value.m_nValue == 0 || HasCommand == 0 )
      {
        streama = wcsncmp(first: stream, last: L"!!!", count: 3u) != 0;
        if ( wcsncmp(first: v6, last: L"-->", count: 3u) == 0 )
        {
          streama = false;
          if ( cc_captiontrace.m_pParent == nullptr )
            return;
          m_nValue = cc_captiontrace.m_pParent->m_Value.m_nValue;
          if ( m_nValue < 2 )
          {
            if ( m_nValue == 1 )
              _Msg(a1: "Missing caption for '%S'\n", v6);
            return;
          }
        }
        m_Size = v45->m_Items.m_Size;
        v11 = cc_linger_time.m_pParent->m_Value.m_fValue + duration;
        timetolive = LODWORD(v11);
        if ( m_Size > 0 )
        {
          m_flTimeToLive = v45->m_Items.m_Memory.m_pMemory[m_Size - 1]->m_flTimeToLive;
          if ( m_flTimeToLive > v11 )
            *((float *)&timetolive + 1) = m_flTimeToLive - v11;
          if ( v11 <= m_flTimeToLive )
            *(float *)&timetolive = m_flTimeToLive;
        }
        predisplay = 0.0;
        value = 0.0;
        v13 = v38;
        direct = (wchar_t *)v6;
        while ( 1 )
        {
          if ( *v6 == 0 )
          {
LABEL_48:
            *v13 = 0;
            if ( v38[0] != 0 )
            {
              v29 = (CCloseCaptionItem *)MemAlloc_Alloc(nSize: 0x4FE4u);
              if ( v29 != nullptr )
                v30 = CCloseCaptionItem::CCloseCaptionItem(
                        this: v29,
                        stream: v38,
                        timetolive: *(float *)&timetolive,
                        addedtime: *((float *)&timetolive + 1),
                        predisplay,
                        valid: streama,
                        fromplayer,
                        bSFXEntry: bSFXEntry[0],
                        bLowPriorityEntry: bLowPriorityEntry[0]);
              else
                v30 = nullptr;
              v31 = v45;
              v32 = v45->m_Items.m_Size;
              m_nAllocationCount = v45->m_Items.m_Memory.m_nAllocationCount;
              if ( v32 + 1 > m_nAllocationCount )
                CUtlMemory<CChoreoActor *,int>::Grow(
                  this: (CUtlMemory<vgui::TreeNode *,int> *)&v45->m_Items,
                  num: v32 - m_nAllocationCount + 1);
              ++v31->m_Items.m_Size;
              m_pMemory = v31->m_Items.m_Memory.m_pMemory;
              v35 = v31->m_Items.m_Size - v32 - 1;
              v31->m_Items.m_pElements = m_pMemory;
              if ( v35 > 0 )
                _V_memmove(
                  dest: (unsigned __int8 *)&m_pMemory[v32 + 1],
                  src: (unsigned __int8 *)&m_pMemory[v32],
                  count: 4 * v35);
              v36 = &v31->m_Items.m_Memory.m_pMemory[v32];
              if ( v36 != nullptr )
                *v36 = v30;
              if ( CHudCloseCaption::StreamHasCommand(this: v31, stream: v38, search: L"sfx") != 0 )
                v30->m_flPreDisplayTime = 0.0;
              if ( CHudCloseCaption::GetFloatCommandValue(this: v31, stream: v38, findcmd: L"len", &value) != 0 )
              {
                v37 = value;
                v30->m_flTimeToLive = value;
                v30->m_flInitialLifeSpan = v37;
              }
            }
            return;
          }
          v14 = v6;
          v15 = CHudCloseCaption::SplitCommand(this: v45, ppIn: (const wchar_t **)&direct, cmd, args);
          v16 = direct;
          if ( v15 != 0 )
          {
            if ( wcscmp(cmd, L"delay") == 0 )
            {
              *v13 = 0;
              if ( v38[0] != 0 )
              {
                v17 = (CCloseCaptionItem *)MemAlloc_Alloc(nSize: 0x4FE4u);
                if ( v17 != nullptr )
                  v18 = CCloseCaptionItem::CCloseCaptionItem(
                          this: v17,
                          stream: v38,
                          timetolive: *(float *)&timetolive,
                          addedtime: *((float *)&timetolive + 1),
                          predisplay,
                          valid: streama,
                          fromplayer,
                          bSFXEntry: bSFXEntry[0],
                          bLowPriorityEntry: bLowPriorityEntry[0]);
                else
                  v18 = nullptr;
                v19 = v45;
                v20 = v45->m_Items.m_Size;
                v21 = v45->m_Items.m_Memory.m_nAllocationCount;
                if ( v20 + 1 > v21 )
                  CUtlMemory<CChoreoActor *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&v45->m_Items,
                    num: v20 - v21 + 1);
                ++v19->m_Items.m_Size;
                v22 = v19->m_Items.m_Memory.m_pMemory;
                v23 = v19->m_Items.m_Size - v20 - 1;
                v19->m_Items.m_pElements = v22;
                if ( v23 > 0 )
                  _V_memmove(dest: (unsigned __int8 *)&v22[v20 + 1], src: (unsigned __int8 *)&v22[v20], count: 4 * v23);
                v24 = &v19->m_Items.m_Memory.m_pMemory[v20];
                if ( v24 != nullptr )
                  *v24 = v18;
                if ( CHudCloseCaption::StreamHasCommand(this: v19, stream: v38, search: L"sfx") != 0 )
                  v18->m_flPreDisplayTime = 0.0;
                FloatCommandValue = CHudCloseCaption::GetFloatCommandValue(
                                      this: v19,
                                      stream: v38,
                                      findcmd: L"len",
                                      &value);
                v16 = direct;
                if ( FloatCommandValue != 0 )
                  v18->m_flTimeToLive = value;
              }
              v13 = v38;
              if ( wcstod(nptr: args, endptr: nullptr) >= 0.0 )
                predisplay = wcstod(nptr: args, endptr: nullptr);
              else
                predisplay = 0.0;
              goto LABEL_47;
            }
            v26 = direct - v14 - 1;
            if ( v26 >= 0 )
            {
              v27 = (char *)v14 - (char *)v13;
              do
              {
                *v13 = *(wchar_t *)((char *)v13 + v27);
                ++v13;
                --v26;
              }
              while ( v26 >= 0 );
            }
          }
          *v13++ = *v16;
LABEL_47:
          v28 = v16 + 1 == nullptr;
          v6 = v16 + 1;
          direct = (wchar_t *)v6;
          if ( v28 )
            goto LABEL_48;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FCE10
// Name: private: void CHudCloseCaption::AddWorkUnit(class CCloseCaptionItem __near *,struct WorkUnitParams __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHudCloseCaption::AddWorkUnit(
        CHudCloseCaption *this@<ecx>,
        int a2@<edi>,
        CCloseCaptionItem *item,
        WorkUnitParams *params)
{
  _DWORD *v4; // eax
  CCloseCaptionWorkUnit *v5; // edi
  int v6; // eax
  int x; // edx
  int m_nTotalHeight; // edx
  int m_nTotalWidth; // eax
  int v10; // eax

  g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: params->font);
  *params->out = 0;
  if ( params->stream[0] != 0 )
  {
    v4 = MemAlloc_Alloc(nSize: 0x24u);
    if ( v4 != nullptr )
    {
      v4[2] = 0;
      v4[3] = 0;
      v4[4] = 0;
      *((_WORD *)v4 + 10) = 0;
      v4[6] = 0;
      v4[7] = 0;
      v4[8] = -1;
      v5 = (CCloseCaptionWorkUnit *)v4;
    }
    else
    {
      v5 = nullptr;
    }
    CCloseCaptionWorkUnit::SetStream(this: v5, stream: params->stream);
    v5->m_Color = params->clr;
    v5->m_bBold = params->bold;
    v5->m_bItalic = params->italic;
    v5->m_nWidth = params->width;
    v6 = ((int (__thiscall *)(vgui::ISurface *, unsigned int, int))g_pVGuiSurface->GetFontTall)(
           a1: g_pVGuiSurface,
           a2: params->font,
           a3: a2);
    v5->m_nHeight = v6;
    x = params->x;
    v5->m_nY = params->y;
    v5->m_nX = x;
    v5->m_hFont = params->font;
    v5->m_flFadeStartTime = 0.0;
    m_nTotalHeight = item->m_nTotalHeight;
    if ( m_nTotalHeight <= v6 + params->y )
      m_nTotalHeight = v6 + params->y;
    m_nTotalWidth = item->m_nTotalWidth;
    if ( m_nTotalWidth <= params->width + params->x )
      m_nTotalWidth = params->width + params->x;
    item->m_nTotalHeight = m_nTotalHeight;
    item->m_nTotalWidth = m_nTotalWidth;
    CCloseCaptionItem::AddWork(this: item, unit: v5);
    v10 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: params->font);
    WorkUnitParams::Next(this: params, lineheight: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FCF60
// Name: public: CAsyncCaption::~CAsyncCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncCaption::~CAsyncCaption(CAsyncCaption *this)
{
  int m_Size; // eax
  int v3; // ebx
  CAsyncCaption::caption_t *v4; // edi
  CAsyncCaption::caption_t **m_pMemory; // eax
  int c; // [esp+8h] [ebp-4h]

  m_Size = this->m_Tokens.m_Size;
  v3 = 0;
  for ( c = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = this->m_Tokens.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->token);
      C_BaseEntity::operator delete(pMem: v4->stream);
      C_BaseEntity::operator delete(pMem: v4);
      m_Size = c;
    }
  }
  this->m_Tokens.m_Size = 0;
  if ( this->m_Tokens.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Tokens.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Tokens.m_Memory.m_pMemory);
      this->m_Tokens.m_Memory.m_pMemory = nullptr;
    }
    this->m_Tokens.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Tokens.m_pElements = this->m_Tokens.m_Memory.m_pMemory;
  this->m_Tokens.m_Size = 0;
  if ( this->m_Tokens.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Tokens.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Tokens.m_Memory.m_pMemory);
      this->m_Tokens.m_Memory.m_pMemory = nullptr;
    }
    this->m_Tokens.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Tokens.m_Memory.m_pMemory;
  this->m_Tokens.m_pElements = m_pMemory;
  if ( this->m_Tokens.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Tokens.m_Memory.m_pMemory = nullptr;
    }
    this->m_Tokens.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD040
// Name: public: void CAsyncCaption::AddRandomToken(class CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncCaption::AddRandomToken(CAsyncCaption *this, IUniformRandomStream **directories)
{
  IUniformRandomStream **v2; // esi
  int v3; // eax
  IUniformRandomStream *v4; // ecx
  int v5; // esi
  char **v6; // eax
  char **v7; // ebx
  char *v8; // eax
  unsigned int v9; // esi
  void *v10; // esp
  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *v11; // eax
  int v12; // edx
  CAsyncCaption *v13; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CAsyncCaption::caption_t **m_pMemory; // ecx
  int v17; // eax
  char ***v18; // edi
  int v19; // [esp-4h] [ebp-3Ch]
  char foo[32]; // [esp+Ch] [ebp-2Ch] BYREF
  CAsyncCaption *v21; // [esp+2Ch] [ebp-Ch]
  int fileindex; // [esp+30h] [ebp-8h]
  int idx; // [esp+34h] [ebp-4h]

  v2 = directories;
  v19 = (int)&directories[3][-1].__vftable + 3;
  v21 = this;
  v3 = _RandomInt((IUniformRandomStream *)this, a2: 0, a3: v19);
  v4 = *v2;
  fileindex = v3;
  v5 = _RandomInt(this: v4, a2: 0, a3: (int)&v4[21 * v3 + 10].__vftable[-1].RandomFloatExp + 3);
  idx = v5;
  v6 = (char **)MemAlloc_Alloc(nSize: 0x14u);
  if ( v6 != nullptr )
  {
    *v6 = nullptr;
    v6[1] = nullptr;
    v6[2] = (char *)-1;
    v6[3] = (char *)-1;
    v6[4] = nullptr;
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  *(_DWORD *)foo = v5;
  V_snprintf(pDest: foo, maxLen: 0x20u, pFormat: "%d");
  v8 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(foo) + 1);
  if ( v8 != nullptr )
    strcpy(v8, foo);
  else
    v8 = nullptr;
  *v7 = v8;
  v9 = _V_strlen(str: foo);
  v10 = alloca(v9 + 1);
  V_strncpy(pDest: foo, pSrc: foo, maxLen: v9 + 1);
  _V_strlower(start: foo);
  CRC32_Init(pulCRC: (unsigned int *)&directories);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&directories, pBuffer: foo, nBuffer: v9);
  CRC32_Final(pulCRC: (unsigned int *)&directories);
  v11 = (CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *)directories;
  v12 = fileindex;
  v13 = v21;
  v7[2] = (char *)idx;
  v7[1] = (char *)v11;
  v7[4] = nullptr;
  v7[3] = (char *)v12;
  m_Size = v13->m_Tokens.m_Size;
  m_nAllocationCount = v13->m_Tokens.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&v13->m_Tokens,
      num: m_Size - m_nAllocationCount + 1);
  ++v13->m_Tokens.m_Size;
  m_pMemory = v13->m_Tokens.m_Memory.m_pMemory;
  v17 = v13->m_Tokens.m_Size - m_Size - 1;
  v13->m_Tokens.m_pElements = m_pMemory;
  if ( v17 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v17);
  v18 = (char ***)&v13->m_Tokens.m_Memory.m_pMemory[m_Size];
  if ( v18 != nullptr )
    *v18 = v7;
}

//------------------------------------------------------------------------------
// Address: 0x100FD1C0
// Name: public: bool CAsyncCaption::AddTokenByHash(class CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>> __near &,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncCaption::AddTokenByHash(
        CAsyncCaption *this,
        CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *directories,
        char *hash,
        const char *pchToken)
{
  int m_Size; // ebx
  int v6; // edi
  char **v8; // eax
  char **v9; // ebx
  char *v10; // eax
  int v11; // edx
  CAsyncCaption *v12; // esi
  int v13; // edi
  int m_nAllocationCount; // eax
  CAsyncCaption::caption_t **m_pMemory; // ecx
  int v16; // eax
  char ***v17; // edi
  CaptionLookup_t search; // [esp+Ch] [ebp-14h] BYREF
  CAsyncCaption *v19; // [esp+18h] [ebp-8h]
  int idx; // [esp+1Ch] [ebp-4h]
  int i; // [esp+28h] [ebp+8h]

  m_Size = directories->m_Size;
  v6 = 0;
  v19 = this;
  search.hash = (unsigned int)hash;
  i = 0;
  if ( m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    idx = CUtlSortVector<CaptionLookup_t,CCaptionLookupLess>::Find(
            this: &directories->m_Memory.m_pMemory[v6].m_CaptionDirectory,
            src: &search);
    if ( idx != -1 )
      break;
    ++v6;
    if ( ++i >= m_Size )
      return 0;
  }
  if ( i >= m_Size )
    return 0;
  v8 = (char **)MemAlloc_Alloc(nSize: 0x14u);
  if ( v8 != nullptr )
  {
    *v8 = nullptr;
    v8[1] = nullptr;
    v8[2] = (char *)-1;
    v8[3] = (char *)-1;
    v8[4] = nullptr;
    v9 = v8;
  }
  else
  {
    v9 = nullptr;
  }
  if ( pchToken != nullptr
    && (v10 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pchToken) + 1)) != nullptr )
  {
    strcpy(v10, pchToken);
  }
  else
  {
    v10 = nullptr;
  }
  v11 = idx;
  v12 = v19;
  *v9 = v10;
  v9[1] = hash;
  v9[2] = (char *)v11;
  v9[4] = nullptr;
  v9[3] = (char *)i;
  v13 = v12->m_Tokens.m_Size;
  m_nAllocationCount = v12->m_Tokens.m_Memory.m_nAllocationCount;
  if ( v13 + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&v12->m_Tokens,
      num: v13 - m_nAllocationCount + 1);
  ++v12->m_Tokens.m_Size;
  m_pMemory = v12->m_Tokens.m_Memory.m_pMemory;
  v16 = v12->m_Tokens.m_Size - v13 - 1;
  v12->m_Tokens.m_pElements = m_pMemory;
  if ( v16 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v13 + 1], src: (unsigned __int8 *)&m_pMemory[v13], count: 4 * v16);
  v17 = (char ***)&v12->m_Tokens.m_Memory.m_pMemory[v13];
  if ( v17 != nullptr )
    *v17 = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FD300
// Name: public: bool CAsyncCaption::AddToken(class CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncCaption::AddToken(
        CAsyncCaption *this,
        CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *directories,
        char *token)
{
  char *v3; // ebx
  unsigned int v4; // esi
  void *v5; // esp
  CAsyncCaption *v7[3]; // [esp+0h] [ebp-10h] BYREF
  CAsyncCaption *v8; // [esp+Ch] [ebp-4h]

  v3 = token;
  v8 = this;
  v4 = _V_strlen(str: token);
  v5 = alloca(v4 + 1);
  V_strncpy(pDest: (char *)v7, pSrc: v3, maxLen: v4 + 1);
  _V_strlower(start: (char *)v7);
  CRC32_Init(pulCRC: (unsigned int *)&token);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&token, pBuffer: v7, nBuffer: v4);
  CRC32_Final(pulCRC: (unsigned int *)&token);
  return CAsyncCaption::AddTokenByHash(this: v8, directories, hash: token, pchToken: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100FD380
// Name: private: void CHudCloseCaption::ClearAsyncWork(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::ClearAsyncWork(CHudCloseCaption *this)
{
  int i; // eax
  unsigned int v3; // esi
  UtlLinkedListElem_t<CAsyncCaption *,unsigned short> *m_pMemory; // eax
  unsigned int v5; // esi
  CAsyncCaption *m_Element; // ebx
  UtlLinkedListElem_t<CAsyncCaption *,unsigned short> *v7; // ecx

  for ( i = this->m_AsyncWork.m_Head; i != 0xFFFF; i = this->m_AsyncWork.m_Memory.m_pMemory[v5].m_Next )
  {
    v3 = (unsigned __int16)i;
    m_pMemory = this->m_AsyncWork.m_Memory.m_pMemory;
    v5 = v3;
    m_Element = m_pMemory[v5].m_Element;
    if ( m_Element != nullptr )
    {
      CAsyncCaption::~CAsyncCaption(this: m_pMemory[v5].m_Element);
      C_BaseEntity::operator delete(pMem: m_Element);
    }
  }
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_AsyncWork);
  if ( this->m_AsyncWork.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_AsyncWork.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AsyncWork.m_Memory.m_pMemory);
      this->m_AsyncWork.m_Memory.m_pMemory = nullptr;
    }
    this->m_AsyncWork.m_Memory.m_nAllocationCount = 0;
  }
  this->m_AsyncWork.m_FirstFree = -1;
  v7 = this->m_AsyncWork.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_AsyncWork.m_NumAlloced = -65536;
  this->m_AsyncWork.m_pElements = v7;
}

//------------------------------------------------------------------------------
// Address: 0x100FD4F0
// Name: public: AsyncCaption_t::AsyncCaption_t(void)
// Source: json
//------------------------------------------------------------------------------
AsyncCaption_t *__thiscall AsyncCaption_t::AsyncCaption_t(AsyncCaption_t *this)
{
  UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short> *m_pMemory; // ecx

  this->m_RequestedBlocks.m_LessFunc = AsyncCaption_t::BlockInfo_t::Less;
  this->m_RequestedBlocks.m_Elements.m_pMemory = nullptr;
  this->m_RequestedBlocks.m_Elements.m_nAllocationCount = 0;
  this->m_RequestedBlocks.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_RequestedBlocks.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_RequestedBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_RequestedBlocks.m_FirstFree = -1;
  this->m_RequestedBlocks.m_pElements = m_pMemory;
  this->m_CaptionDirectory.m_Memory.m_pMemory = nullptr;
  this->m_CaptionDirectory.m_Memory.m_nAllocationCount = 0;
  this->m_CaptionDirectory.m_Memory.m_nGrowSize = 0;
  this->m_CaptionDirectory.m_Size = 0;
  this->m_CaptionDirectory.m_pElements = nullptr;
  this->m_CaptionDirectory.m_pLessContext = nullptr;
  this->m_CaptionDirectory.m_bNeedsSort = false;
  this->m_DataBaseFile.m_Id = -1;
  _V_memset(dest: &this->m_Header, fill: 0, count: 24);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FD550
// Name: public: virtual void CHudCloseCaption::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::LevelInit(CHudCloseCaption *this)
{
  CHudCloseCaption::CreateFonts(this);
  CUtlRBTree<CHudCloseCaption::CaptionRepeat,int,bool (__cdecl *)(CHudCloseCaption::CaptionRepeat const &,CHudCloseCaption::CaptionRepeat const &),CUtlMemory<UtlRBTreeNode_t<CHudCloseCaption::CaptionRepeat,int>,int>>::RemoveAll(this: &this->m_CloseCaptionRepeats);
  CHudCloseCaption::ClearAsyncWork(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FD570
// Name: public: virtual void CHudCloseCaption::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::Reset(CHudCloseCaption *this)
{
  if ( this->m_bLevelShutDown || g_pGameRules == nullptr || !g_pGameRules->IsMultiplayer(this: g_pGameRules) )
  {
    CUtlVector<CCloseCaptionItem *,CUtlMemory<CCloseCaptionItem *,int>>::PurgeAndDeleteElements(this: &this->m_Items);
    CHudCloseCaption::ClearAsyncWork(this);
    this->m_bLocked = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD5B0
// Name: private: bool CHudCloseCaption::FindColorForTag(wchar_t __near *,class Color __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudCloseCaption::FindColorForTag(CHudCloseCaption *this, wchar_t *pTag, Color *tagColor)
{
  int v4; // eax
  char buf[128]; // [esp+4h] [ebp-88h] BYREF
  CUtlMap<char const *,Color,int>::Node_t search; // [esp+84h] [ebp-8h] BYREF

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: pTag, a3: buf, a4: 128);
  search.key = buf;
  search.elem = 0;
  v4 = CUtlRBTree<CUtlMap<char const *,Color,int>::Node_t,int,CUtlMap<char const *,Color,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int>,int>>::Find(
         this: &this->m_ColorMap.m_Elements.m_Tree,
         &search);
  if ( v4 == -1 )
    return 0;
  *tagColor = this->m_ColorMap.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FD820
// Name: public: int CAsyncCaptionResourceManager::FindOrAddBlock(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncCaptionResourceManager::FindOrAddBlock(
        CAsyncCaptionResourceManager *this,
        int dbFileIndex,
        int blockNum)
{
  const char *v4; // eax
  AsyncCaption_t *m_pMemory; // ebx
  CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl*)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short> > *p_m_RequestedBlocks; // ebx
  int v7; // eax
  AsyncCaption_t *v9; // esi
  int blocksize; // eax
  int v11; // edx
  memhandle_t__ *v12; // eax
  char fn[256]; // [esp+Ch] [ebp-134h] BYREF
  AsyncCaption_t::BlockInfo_t search; // [esp+10Ch] [ebp-34h] BYREF
  asynccaptionparams_t params; // [esp+118h] [ebp-28h] BYREF
  AsyncCaption_t::BlockInfo_t info; // [esp+12Ch] [ebp-14h] BYREF
  const char *dbname; // [esp+138h] [ebp-8h]
  int idx; // [esp+13Ch] [ebp-4h]

  v4 = CUtlSymbol::String(this: &this->m_Db.m_Memory.m_pMemory[dbFileIndex].m_DataBaseFile);
  m_pMemory = this->m_Db.m_Memory.m_pMemory;
  dbname = v4;
  p_m_RequestedBlocks = &m_pMemory[dbFileIndex].m_RequestedBlocks;
  search.fileindex = dbFileIndex;
  search.blocknum = blockNum;
  v7 = CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::Find(
         this: p_m_RequestedBlocks,
         &search);
  idx = v7;
  if ( (unsigned __int16)v7 == 0xFFFF )
  {
    V_strncpy(pDest: fn, pSrc: (char *)dbname, maxLen: 256);
    V_FixSlashes(pname: fn, separator: 92);
    _V_strlower(start: fn);
    v9 = &this->m_Db.m_Memory.m_pMemory[dbFileIndex];
    blocksize = v9->m_Header.blocksize;
    params.dbfile = fn;
    v11 = v9->m_Header.dataoffset + blockNum * blocksize;
    params.blocksize = blocksize;
    params.blocktoload = blockNum;
    params.blockoffset = v11;
    params.fileindex = dbFileIndex;
    v12 = (memhandle_t__ *)CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>::CacheCreate(
                             this: &this->CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>,
                             createParams: (memhandle_t__ *)&params,
                             flags: 0);
    info.blocknum = blockNum;
    info.fileindex = dbFileIndex;
    info.handle = v12;
    return CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::Insert(
             this: p_m_RequestedBlocks,
             a2: (const char *)this,
             insert: &info);
  }
  else
  {
    this->m_pCache->Touch(
      this: this->m_pCache,
      a2: p_m_RequestedBlocks->m_Elements.m_pMemory[(unsigned __int16)v7].m_Data.handle);
    return idx;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD920
// Name: private: void CHudCloseCaption::ComputeStreamWork(int,class CCloseCaptionItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::ComputeStreamWork(
        CHudCloseCaption *this,
        int available_width,
        CCloseCaptionItem *item)
{
  CHudCloseCaption *v3; // edi
  CCloseCaptionItem *v4; // ebx
  CCloseCaptionItem *v5; // esi
  char v6; // al
  wchar_t *v7; // esi
  bool v8; // zf
  Color v9; // edi
  wchar_t *v10; // ebx
  unsigned __int16 *v11; // esi
  const wchar_t *v12; // eax
  unsigned __int16 *v13; // eax
  unsigned int v14; // ecx
  int m_Size; // ebx
  int v16; // esi
  int v17; // ebx
  vgui::PageTab **m_pMemory; // ecx
  vgui::PageTab **v19; // eax
  Color v20; // eax
  _BYTE *v21; // eax
  int v22; // edi
  vgui::PageTab *v23; // ebx
  int v24; // esi
  int v25; // edi
  vgui::PageTab **v26; // ecx
  vgui::PageTab **v27; // eax
  Color v28; // eax
  int italic; // eax
  wchar_t v30; // dx
  vgui::ISurface_vtbl *v31; // edx
  const wchar_t *v32; // ebx
  unsigned int v33; // esi
  unsigned __int16 *v34; // edi
  CHudCloseCaption *v35; // ecx
  bool v36; // sf
  WorkUnitParams dest; // [esp+Ch] [ebp-543Ch] BYREF
  wchar_t args[256]; // [esp+4FD8h] [ebp-470h] BYREF
  wchar_t cmd[128]; // [esp+51D8h] [ebp-270h] BYREF
  wchar_t pDest[128]; // [esp+52D8h] [ebp-170h] BYREF
  char v41[4]; // [esp+53D8h] [ebp-70h] BYREF
  int v42; // [esp+53DCh] [ebp-6Ch] BYREF
  char v43; // [esp+53E0h] [ebp-68h] BYREF
  unsigned __int8 v44; // [esp+53E4h] [ebp-64h] BYREF
  char v45; // [esp+53E8h] [ebp-60h] BYREF
  char v46; // [esp+53ECh] [ebp-5Ch] BYREF
  unsigned __int8 v47; // [esp+53F0h] [ebp-58h] BYREF
  char v48; // [esp+53F4h] [ebp-54h] BYREF
  char v49; // [esp+53F8h] [ebp-50h] BYREF
  int v50; // [esp+53FCh] [ebp-4Ch] BYREF
  char v51; // [esp+5400h] [ebp-48h] BYREF
  unsigned __int8 v52; // [esp+5404h] [ebp-44h] BYREF
  int v53; // [esp+5408h] [ebp-40h] BYREF
  _WORD v54[2]; // [esp+540Ch] [ebp-3Ch] BYREF
  int width; // [esp+5410h] [ebp-38h]
  Color v56; // [esp+5414h] [ebp-34h]
  _BYTE v57[4]; // [esp+5418h] [ebp-30h] BYREF
  Color tagColor; // [esp+541Ch] [ebp-2Ch] BYREF
  _BYTE v59[4]; // [esp+5420h] [ebp-28h] BYREF
  CHudCloseCaption *v60; // [esp+5424h] [ebp-24h]
  CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > v61; // [esp+5428h] [ebp-20h] BYREF
  wchar_t *ppIn; // [esp+543Ch] [ebp-Ch] BYREF
  wchar_t *v63; // [esp+5440h] [ebp-8h]
  char v64; // [esp+5447h] [ebp-1h]

  v3 = this;
  v60 = this;
  dest.clr = 0;
  _V_memset((int)&dest, fill: nullptr, count: 0x4FB0u);
  v4 = item;
  memset(&dest.x, 0, 14);
  dest.font = 0;
  v5 = item;
  dest.out = (wchar_t *)&dest;
  dest.clr = (Color)-1;
  dest.newline = false;
  ppIn = (wchar_t *)item;
  memset(&v61, 0, sizeof(v61));
  v64 = 1;
  v63 = nullptr;
  width = -1;
  if ( item != nullptr )
  {
    do
    {
      if ( v5->m_szStream[0] == 0 )
        break;
      v6 = CHudCloseCaption::SplitCommand(this: v3, (const wchar_t **)&ppIn, cmd, args);
      v7 = ppIn;
      if ( v6 != 0 )
      {
        if ( wcscmp(cmd, L"cr") == 0 )
        {
          dest.newline = true;
          CHudCloseCaption::AddWorkUnit(this: v3, a2: (int)v3, item: v4, params: &dest);
        }
        else
        {
          if ( wcscmp(cmd, L"clr") == 0 )
          {
            CHudCloseCaption::AddWorkUnit(this: v3, a2: (int)v3, item: v4, params: &dest);
            if ( args[0] != 0 || v61.m_Size < 2 )
            {
              if ( swscanf(string: args, format: L"%i,%i,%i", &v47, &v44, &v52) == 3 )
              {
                v8 = *v7 == 62;
                v56._color[0] = v47;
                v56._color[1] = v44;
                v56._color[2] = v52;
                v56._color[3] = -1;
                v9 = v56;
                if ( v8 )
                {
                  v10 = ppIn + 1;
                  v11 = wcsstr(wcs1: ppIn + 1, wcs2: L":");
                  if ( v11 != nullptr )
                  {
                    v12 = v10;
                    if ( *v10 == 60 )
                    {
                      while ( 1 )
                      {
                        v13 = wcsstr(wcs1: v12, wcs2: L">");
                        if ( v13 == nullptr )
                          break;
                        v12 = v13 + 1;
                        if ( *v12 != 60 )
                          goto LABEL_18;
                      }
                      v12 = v10;
                    }
LABEL_18:
                    v14 = 2 * (v11 - v12) + 2;
                    if ( v14 > 0x100 )
                      v14 = 256;
                    V_wcsncpy(pDest, pSrc: v12, maxLenInBytes: v14);
                    tagColor = 0;
                    if ( CHudCloseCaption::FindColorForTag(this: v60, pTag: pDest, &tagColor) != 0 )
                      v9 = tagColor;
                  }
                }
                m_Size = v61.m_Size;
                v16 = v61.m_Size;
                if ( v61.m_Size + 1 > v61.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CChoreoActor *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&v61,
                    num: v61.m_Size - v61.m_Memory.m_nAllocationCount + 1);
                  m_Size = v61.m_Size;
                }
                v17 = m_Size + 1;
                v61.m_Size = v17;
                v61.m_pElements = v61.m_Memory.m_pMemory;
                if ( v17 - v16 - 1 > 0 )
                  _V_memmove(
                    dest: (unsigned __int8 *)&v61.m_Memory.m_pMemory[v16 + 1],
                    src: (unsigned __int8 *)&v61.m_Memory.m_pMemory[v16],
                    count: 4 * (v17 - v16 - 1));
                m_pMemory = v61.m_Memory.m_pMemory;
                v19 = &v61.m_Memory.m_pMemory[v16];
                if ( v19 != nullptr )
                  *v19 = (vgui::PageTab *)v9;
                v20 = (Color)m_pMemory[v17 - 1];
                v3 = v60;
                v7 = ppIn;
                v4 = item;
                dest.clr = v20;
              }
              goto LABEL_62;
            }
          }
          else
          {
            if ( wcscmp(cmd, L"playerclr") != 0 )
            {
              if ( wcscmp(cmd, L"I") == 0 )
              {
                CHudCloseCaption::AddWorkUnit(this: v3, a2: (int)v3, item: v4, params: &dest);
                dest.italic = !dest.italic;
              }
              else if ( wcscmp(cmd, L"B") == 0 )
              {
                CHudCloseCaption::AddWorkUnit(this: v3, a2: (int)v3, item: v4, params: &dest);
                dest.bold = !dest.bold;
              }
              goto LABEL_62;
            }
            CHudCloseCaption::AddWorkUnit(this: v3, a2: (int)v3, item: v4, params: &dest);
            if ( args[0] != 0 || v61.m_Size < 2 )
            {
              if ( swscanf(string: args, format: L"%i,%i,%i:%i,%i,%i", &v49, &v45, &v43, &v46, &v48, &v51) == 6 )
              {
                if ( v4->m_bFromPlayer )
                {
                  v59[2] = v43;
                  v59[0] = v49;
                  v59[1] = v45;
                  v59[3] = -1;
                  v21 = v59;
                }
                else
                {
                  v57[2] = v51;
                  v57[0] = v46;
                  v57[1] = v48;
                  v57[3] = -1;
                  v21 = v57;
                }
                v22 = v61.m_Size;
                v23 = *(vgui::PageTab **)v21;
                v24 = v61.m_Size;
                if ( v61.m_Size + 1 > v61.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CChoreoActor *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&v61,
                    num: v61.m_Size - v61.m_Memory.m_nAllocationCount + 1);
                  v22 = v61.m_Size;
                }
                v25 = v22 + 1;
                v61.m_Size = v25;
                v61.m_pElements = v61.m_Memory.m_pMemory;
                if ( v25 - v24 - 1 > 0 )
                  _V_memmove(
                    dest: (unsigned __int8 *)&v61.m_Memory.m_pMemory[v24 + 1],
                    src: (unsigned __int8 *)&v61.m_Memory.m_pMemory[v24],
                    count: 4 * (v25 - v24 - 1));
                v26 = v61.m_Memory.m_pMemory;
                v27 = &v61.m_Memory.m_pMemory[v24];
                if ( v27 != nullptr )
                  *v27 = v23;
                v28 = (Color)v26[v25 - 1];
                v3 = v60;
                v7 = ppIn;
                v4 = item;
                dest.clr = v28;
              }
              goto LABEL_62;
            }
          }
          CUtlVector<Color,CUtlMemory<Color,int>>::Remove(this: &v61, elem: v61.m_Size - 1);
          dest.clr = (Color)v61.m_Memory.m_pMemory[v61.m_Size - 1];
        }
        goto LABEL_62;
      }
      if ( dest.bold )
        italic = dest.italic + 2;
      else
        italic = dest.italic;
      dest.font = v3->m_hFonts[italic];
      v30 = *ppIn;
      v54[1] = 0;
      v54[0] = v30;
      v31 = g_pVGuiSurface->__vftable;
      tagColor = (Color)dest.font;
      v31->GetTextSize(this: g_pVGuiSurface, a2: dest.font, a3: v54, a4: &v53, a5: &v42);
      if ( v53 + dest.x + dest.width > available_width )
      {
        if ( v63 == nullptr || (v32 = v63 + 1, v7 < v63 + 1) )
        {
          v4 = item;
          dest.newline = true;
          CHudCloseCaption::AddWorkUnit(this: v3, a2: (int)v3, item, params: &dest);
          goto LABEL_55;
        }
        v33 = ppIn - v63 - 1;
        dest.out += -v33 - (v64 != 0);
        dest.width = width;
        v34 = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(ppIn - v63) >> 31 != 0 ? -1 : 2 * (ppIn - v63));
        wcsncpy(dest: v34, source: v32, count: v33);
        v35 = v60;
        v34[v33] = 0;
        dest.newline = true;
        CHudCloseCaption::AddWorkUnit(this: v35, a2: (int)v34, item, params: &dest);
        wcsncpy(dest: dest.out, source: v34, count: v33);
        dest.out += v33;
        g_pVGuiSurface->GetTextSize(this: g_pVGuiSurface, a2: (unsigned int)tagColor, a3: v34, a4: &v50, a5: (int *)v41);
        dest.width = v50;
        C_BaseEntity::operator delete(pMem: v34);
        v3 = v60;
        v7 = ppIn;
        v63 = nullptr;
        width = -1;
      }
      v4 = item;
LABEL_55:
      *dest.out++ = *v7;
      dest.width += v53;
      if ( isbreakablewspace(ch: *v7) != 0 )
      {
        v64 = 1;
        width = dest.width;
      }
      else
      {
        if ( !v3->m_bUseAsianWordWrapping || !AsianWordWrap::CanBreakAfter(wsz: v7) )
          goto LABEL_62;
        v64 = 0;
        width = dest.width;
      }
      v63 = v7;
LABEL_62:
      v8 = v7 + 1 == nullptr;
      v5 = (CCloseCaptionItem *)(v7 + 1);
      ppIn = (wchar_t *)v5;
    }
    while ( !v8 );
  }
  dest.newline = true;
  CHudCloseCaption::AddWorkUnit(this: v3, a2: (int)v3, item: v4, params: &dest);
  v36 = v61.m_Memory.m_nGrowSize < 0;
  v4->m_bSizeComputed = true;
  if ( !v36 && v61.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v61.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100FE050
// Name: private: void CHudCloseCaption::_ProcessCaption(wchar_t const __near *,unsigned int,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHudCloseCaption::_ProcessCaption(
        CHudCloseCaption *this@<ecx>,
        const char *a2@<edi>,
        wchar_t *caption,
        unsigned int hash,
        float duration,
        bool fromplayer,
        wchar_t *direct)
{
  char NoRepeatValue; // bl
  int v9; // eax
  UtlRBTreeNode_t<CHudCloseCaption::CaptionRepeat,int> *m_pMemory; // ecx
  int v11; // eax
  float m_flInterval; // xmm0_4
  int p_m_Data; // eax
  CHudCloseCaption::CaptionRepeat entry; // [esp+18h] [ebp-14h] BYREF
  float interval; // [esp+28h] [ebp-4h] BYREF

  interval = 0.0;
  NoRepeatValue = CHudCloseCaption::GetNoRepeatValue(this, caption, retval: &interval);
  memset(&entry.m_nLastEmitTick, 0, 12);
  entry.m_nTokenIndex = hash;
  v9 = CUtlRBTree<CHudCloseCaption::CaptionRepeat,int,bool (__cdecl *)(CHudCloseCaption::CaptionRepeat const &,CHudCloseCaption::CaptionRepeat const &),CUtlMemory<UtlRBTreeNode_t<CHudCloseCaption::CaptionRepeat,int>,int>>::Find(
         this: &this->m_CloseCaptionRepeats,
         search: &entry);
  if ( v9 == -1 )
  {
    entry.m_flLastEmitTime = *(float *)(gpGlobals.m_Index + 12);
    entry.m_nLastEmitTick = *(_DWORD *)(gpGlobals.m_Index + 24);
    entry.m_flInterval = interval;
    CUtlRBTree<CHudCloseCaption::CaptionRepeat,int,bool (__cdecl *)(CHudCloseCaption::CaptionRepeat const &,CHudCloseCaption::CaptionRepeat const &),CUtlMemory<UtlRBTreeNode_t<CHudCloseCaption::CaptionRepeat,int>,int>>::Insert(
      this: &this->m_CloseCaptionRepeats,
      a2,
      insert: &entry);
LABEL_9:
    CHudCloseCaption::Process(this, stream: caption, duration, fromplayer, direct);
    return;
  }
  m_pMemory = this->m_CloseCaptionRepeats.m_Elements.m_pMemory;
  v11 = v9;
  m_flInterval = m_pMemory[v11].m_Data.m_flInterval;
  p_m_Data = (int)&m_pMemory[v11].m_Data;
  if ( m_flInterval <= 0.0 )
  {
    if ( *(_DWORD *)(gpGlobals.m_Index + 24) <= *(_DWORD *)(p_m_Data + 4) )
      return;
    goto LABEL_8;
  }
  if ( NoRepeatValue == 0 || (float)(*(float *)(p_m_Data + 8) + m_flInterval) <= *(float *)(gpGlobals.m_Index + 12) )
  {
LABEL_8:
    *(float *)(p_m_Data + 8) = *(float *)(gpGlobals.m_Index + 12);
    *(_DWORD *)(p_m_Data + 4) = *(_DWORD *)(gpGlobals.m_Index + 24);
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FE230
// Name: public: void CAsyncCaptionResourceManager::PollForAsyncLoading(class CHudCloseCaption __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncCaptionResourceManager::PollForAsyncLoading(
        CAsyncCaptionResourceManager *this,
        CHudCloseCaption *hudCloseCaption,
        int dbFileIndex,
        int blockNum)
{
  int v4; // ebx
  int v6; // eax
  UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short> *m_pMemory; // edx
  IDataCacheSection *m_pCache; // ecx
  int v9; // edi
  memhandle_t__ *v10; // eax
  IDataCacheSection_vtbl *v11; // edx
  int v12; // eax
  AsyncCaption_t *v13; // ecx
  int blocksize; // eax
  int v15; // eax
  memhandle_t__ *v16; // eax
  CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *> *v17; // ecx
  IDataCacheSection *v18; // ecx
  IDataCacheSection_vtbl *v19; // edx
  char v20; // cl
  char fn[256]; // [esp+Ch] [ebp-124h] BYREF
  asynccaptionparams_t params; // [esp+10Ch] [ebp-24h] BYREF
  const char *dbname; // [esp+120h] [ebp-10h]
  CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl*)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short> > *requested; // [esp+124h] [ebp-Ch]
  CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *> *v25; // [esp+128h] [ebp-8h]
  memhandle_t__ *handle; // [esp+12Ch] [ebp-4h]

  v4 = dbFileIndex;
  dbname = CUtlSymbol::String(this: &this->m_Db.m_Memory.m_pMemory[dbFileIndex].m_DataBaseFile);
  requested = &this->m_Db.m_Memory.m_pMemory[dbFileIndex].m_RequestedBlocks;
  v6 = CAsyncCaptionResourceManager::FindOrAddBlock(this, dbFileIndex, blockNum);
  if ( v6 != 0xFFFF )
  {
    m_pMemory = requested->m_Elements.m_pMemory;
    v25 = &this->CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>;
    m_pCache = this->m_pCache;
    v9 = (unsigned __int16)v6;
    v10 = m_pMemory[v9].m_Data.handle;
    v11 = m_pCache->__vftable;
    handle = v10;
    v12 = (int)v11->Lock(this: m_pCache, a2: v10);
    if ( v12 != 0 )
      goto LABEL_4;
    V_strncpy(pDest: fn, pSrc: (char *)dbname, maxLen: 256);
    V_FixSlashes(pname: fn, separator: 92);
    _V_strlower(start: fn);
    v13 = &this->m_Db.m_Memory.m_pMemory[v4];
    blocksize = v13->m_Header.blocksize;
    params.dbfile = fn;
    params.blocksize = blocksize;
    v15 = v13->m_Header.dataoffset + blockNum * blocksize;
    params.blocktoload = blockNum;
    params.fileindex = dbFileIndex;
    params.blockoffset = v15;
    v16 = (memhandle_t__ *)CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>::CacheCreate(
                             this: v25,
                             createParams: (memhandle_t__ *)&params,
                             flags: 0);
    v17 = v25;
    requested->m_Elements.m_pMemory[v9].m_Data.handle = v16;
    v18 = v17->m_pCache;
    v19 = v18->__vftable;
    handle = v16;
    v12 = (int)v19->Lock(this: v18, a2: v16);
    if ( v12 != 0 )
    {
LABEL_4:
      v20 = *(_BYTE *)(v12 + 16);
      if ( (v20 & 2) != 0 )
      {
        *(_BYTE *)(v12 + 16) = v20 & 0xFE;
        if ( hudCloseCaption != nullptr )
          CHudCloseCaption::OnFinishAsyncLoad(
            this: hudCloseCaption,
            nFileIndex: requested->m_Elements.m_pMemory[v9].m_Data.fileindex,
            nBlockNum: requested->m_Elements.m_pMemory[v9].m_Data.blocknum,
            pData: (AsyncCaptionData_t *)v12);
        this->m_pCache->BreakLock(this: this->m_pCache, a2: handle);
      }
      else if ( (v20 & 1) != 0 )
      {
        v25->m_pCache->Unlock(this: v25->m_pCache, a2: handle);
      }
      else
      {
        *(_BYTE *)(v12 + 16) = v20 | 1;
        AsyncCaptionData_t::AsyncLoad(
          this: (AsyncCaptionData_t *)v12,
          fileName: dbname,
          blockOffset: this->m_Db.m_Memory.m_pMemory[v4].m_Header.dataoffset
        + blockNum * this->m_Db.m_Memory.m_pMemory[v4].m_Header.blocksize);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FE3C0
// Name: public: virtual void CHudCloseCaption::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::Paint(CHudCloseCaption *this)
{
  int v2; // edi
  char *v3; // esi
  char v4; // bl
  unsigned __int16 v5; // ax
  memhandle_t__ *v6; // esi
  _BYTE *v7; // eax
  char v8; // al
  int v9; // eax
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  void (__thiscall *v11)(vgui::ISurface *, Color); // eax
  int v12; // esi
  float m_flCurrentAlpha; // edx
  int m_Size; // esi
  int v15; // eax
  int m_NumElements; // ebx
  CCloseCaptionItem *v17; // eax
  float m_flPreDisplayTime; // xmm0_4
  CCloseCaptionItem *v19; // edi
  int m_nTotalWidth; // eax
  int m_nTotalHeight; // edi
  int v22; // edi
  VisibleStreamItem *m_pMemory; // ecx
  VisibleStreamItem *v24; // eax
  CCloseCaptionItem *v25; // edx
  int v26; // edx
  unsigned __int8 *p_item; // edi
  int m_nValue; // eax
  int v29; // edx
  unsigned __int8 *v30; // edi
  ConVar *m_pParent; // ecx
  int v32; // eax
  int v33; // esi
  unsigned int j; // edi
  int v35; // eax
  unsigned __int8 *v36; // eax
  float v37; // xmm0_4
  CHudCloseCaption *v38; // ecx
  float v39; // xmm2_4
  float v40; // xmm4_4
  int index; // eax
  float v42; // xmm6_4
  float v43; // xmm5_4
  float v44; // xmm3_4
  float v45; // xmm0_4
  int v46; // edx
  float v47; // xmm0_4
  int m_FirstFree; // eax
  int v49; // edi
  CCloseCaptionItem **v50; // xmm0_4
  CHudCloseCaption_vtbl *v51; // edx
  int v52; // ecx
  int v53; // eax
  int v54; // ecx
  int v55; // edx
  VisibleStreamItem *v56; // edi
  CCloseCaptionItem *v57; // ecx
  float v58; // xmm0_4
  int v59; // ebx
  unsigned int m_szStream; // edi
  int v61; // ecx
  int v62; // eax
  int v63; // edx
  __m128 v64; // xmm0
  __m128 v65; // xmm2
  float v66; // xmm5_4
  float v67; // xmm4_4
  __m128 v68; // xmm3
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  float v71; // xmm0_4
  int v72; // edx
  int v73; // ebx
  int v74; // eax
  int v75; // ecx
  bool v76; // zf
  float v77; // xmm5_4
  int v78; // ecx
  float v79; // xmm0_4
  double v80; // xmm0_8
  __int64 v81; // xmm1_8
  __int64 v82; // xmm1_8
  double v83; // xmm0_8
  float v84; // xmm0_4
  double v85; // st7
  const wchar_t *v86; // ebx
  int v87; // ecx
  CUtlVector<VisibleStreamItem,CUtlMemory<VisibleStreamItem,int> > visibleitems; // [esp+4Ch] [ebp-7Ch] BYREF
  wrect_s rcOutput; // [esp+60h] [ebp-68h] BYREF
  wrect_s rcText; // [esp+70h] [ebp-58h]
  wrect_s v91; // [esp+80h] [ebp-48h] BYREF
  int h; // [esp+90h] [ebp-38h] BYREF
  int w; // [esp+94h] [ebp-34h] BYREF
  int iLinesToMove; // [esp+98h] [ebp-30h]
  Color bgColor; // [esp+9Ch] [ebp-2Ch] BYREF
  CCloseCaptionItem *item; // [esp+A0h] [ebp-28h]
  float flFadeLineAlpha; // [esp+A4h] [ebp-24h]
  int iFadeLine; // [esp+A8h] [ebp-20h]
  int iHeightToMove; // [esp+ACh] [ebp-1Ch]
  int height; // [esp+B0h] [ebp-18h]
  int iSizeCheck; // [esp+B4h] [ebp-14h]
  int i; // [esp+B8h] [ebp-10h]
  int avail_height; // [esp+BCh] [ebp-Ch]
  CHudCloseCaption *v104; // [esp+C0h] [ebp-8h]
  bool loaded; // [esp+C7h] [ebp-1h]

  v104 = this;
  vgui::Panel::GetSize((vgui::Panel *)this, wide: &w, tall: &h);
  if ( BYTE2(this->m_flGrowTime) != 0 )
  {
    iHeightToMove = 0;
    item = nullptr;
    if ( SLODWORD(this->m_flBackgroundAlpha) > 0 )
    {
      iFadeLine = 0;
      while ( 1 )
      {
        v2 = 50;
        iLinesToMove = *(_DWORD *)(LODWORD(v104->m_flGoalHeightStartTime) + iFadeLine + 64);
        flFadeLineAlpha = 0.0;
        if ( iLinesToMove > 0 )
          break;
LABEL_21:
        iHeightToMove += 9;
        iFadeLine += 84;
        item = (CCloseCaptionItem *)((char *)item + 1);
        if ( (int)item >= SLODWORD(v104->m_flBackgroundAlpha) )
          goto LABEL_22;
      }
      while ( 1 )
      {
        v3 = (char *)g_AsyncCaptionResourceManager.m_Db.m_Memory.m_pMemory + iFadeLine;
        *(float *)&v91.top = flFadeLineAlpha;
        v4 = 0;
        loaded = false;
        v91.right = (int)item;
        v5 = CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::Find(
               this: (CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl*)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short> > *)((char *)&g_AsyncCaptionResourceManager.m_Db.m_Memory.m_pMemory->m_RequestedBlocks + iFadeLine),
               search: (const AsyncCaption_t::BlockInfo_t *)&v91.right);
        if ( v5 == 0xFFFF )
        {
          DrawSetColor = g_pVGuiSurface->DrawSetColor;
          iSizeCheck = 2130706432;
          ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: 2130706432);
        }
        else
        {
          v6 = *(memhandle_t__ **)(*((_DWORD *)v3 + 1) + 20 * v5 + 16);
          v7 = g_AsyncCaptionResourceManager.m_pCache->Lock(this: g_AsyncCaptionResourceManager.m_pCache, a2: v6);
          if ( v7 == nullptr )
            goto LABEL_16;
          v8 = v7[16];
          if ( (v8 & 1) != 0 )
          {
            v4 = 1;
          }
          else if ( (v8 & 2) != 0 )
          {
            loaded = true;
          }
          g_AsyncCaptionResourceManager.m_pCache->Unlock(this: g_AsyncCaptionResourceManager.m_pCache, a2: v6);
          if ( v4 != 0 )
          {
            i = 2147418112;
            v9 = 2147418112;
LABEL_17:
            ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: v9);
            goto LABEL_18;
          }
          if ( !loaded )
          {
LABEL_16:
            height = 2130771967;
            v9 = 2130771967;
            goto LABEL_17;
          }
          v11 = g_pVGuiSurface->DrawSetColor;
          avail_height = 2130771712;
          ((void (__thiscall *)(vgui::ISurface *, int))v11)(a1: g_pVGuiSurface, a2: 2130771712);
        }
LABEL_18:
        v12 = iHeightToMove;
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: v2,
          a3: iHeightToMove,
          a4: v2 + 8,
          a5: iHeightToMove + 8);
        v2 += 9;
        if ( v2 >= 400 )
        {
          v2 = 50;
          iHeightToMove = v12 + 9;
        }
        ++LODWORD(flFadeLineAlpha);
        if ( SLODWORD(flFadeLineAlpha) >= iLinesToMove )
          goto LABEL_21;
      }
    }
  }
LABEL_22:
  m_flCurrentAlpha = v104->m_flCurrentAlpha;
  m_Size = 0;
  rcOutput.right = w;
  rcOutput.left = 0;
  avail_height = h - LODWORD(m_flCurrentAlpha) - 24;
  v15 = *(_DWORD *)&v104->m_AsyncWork.m_NumAlloced;
  *(_QWORD *)&rcOutput.top = __PAIR64__(h, LODWORD(m_flCurrentAlpha));
  rcText = rcOutput;
  m_NumElements = 0;
  iLinesToMove = w - 24;
  memset(&visibleitems, 0, sizeof(visibleitems));
  iHeightToMove = v15;
  flFadeLineAlpha = 0.0;
  i = 0;
  if ( v15 <= 0 )
    goto LABEL_78;
  do
  {
    v17 = *(CCloseCaptionItem **)(v104->m_AsyncWork.m_Memory.m_nGrowSize + 4 * i);
    m_flPreDisplayTime = v17->m_flPreDisplayTime;
    item = v17;
    if ( m_flPreDisplayTime <= 0.0 )
    {
      v19 = v17;
      if ( !v17->m_bSizeComputed )
        CHudCloseCaption::ComputeStreamWork(
          this: (CHudCloseCaption *)((char *)v104 - 56),
          available_width: iLinesToMove,
          item: v17);
      m_nTotalWidth = v19->m_nTotalWidth;
      m_nTotalHeight = v19->m_nTotalHeight;
      m_NumElements += m_nTotalHeight;
      iFadeLine = m_nTotalHeight;
      if ( m_nTotalWidth > SLODWORD(flFadeLineAlpha) )
        flFadeLineAlpha = *(float *)&m_nTotalWidth;
      v91.right = iFadeLine;
      v91.top = m_nTotalWidth;
      v22 = m_Size;
      if ( m_Size + 1 > visibleitems.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&visibleitems,
          num: m_Size - visibleitems.m_Memory.m_nAllocationCount + 1);
        m_Size = visibleitems.m_Size;
      }
      m_pMemory = visibleitems.m_Memory.m_pMemory;
      visibleitems.m_Size = ++m_Size;
      visibleitems.m_pElements = visibleitems.m_Memory.m_pMemory;
      if ( m_Size - v22 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&visibleitems.m_Memory.m_pMemory[v22 + 1],
          src: (unsigned __int8 *)&visibleitems.m_Memory.m_pMemory[v22],
          count: 12 * (m_Size - v22 - 1));
        m_pMemory = visibleitems.m_Memory.m_pMemory;
      }
      v24 = &m_pMemory[v22];
      if ( v24 != nullptr )
      {
        v25 = item;
        *(_QWORD *)&v24->height = *(_QWORD *)&v91.right;
        v24->item = v25;
      }
      v26 = 0;
      iSizeCheck = 0;
      if ( m_NumElements > avail_height )
      {
        item = (CCloseCaptionItem *)(m_Size - 1);
        p_item = (unsigned __int8 *)&m_pMemory->item;
        do
        {
          if ( cc_minvisibleitems.m_pParent != nullptr )
            m_nValue = cc_minvisibleitems.m_pParent->m_Value.m_nValue;
          else
            m_nValue = 0;
          if ( m_Size <= m_nValue || v26 > (int)item )
            break;
          if ( *(_BYTE *)(*(_DWORD *)p_item + 20430) != 0 )
          {
            m_NumElements -= *((_DWORD *)p_item - 2);
            *(_DWORD *)(*(_DWORD *)p_item + 20404) = 0;
            if ( m_Size - v26 - 1 > 0 )
            {
              _V_memmove(dest: p_item - 8, src: p_item + 4, count: 12 * (m_Size - v26 - 1));
              v26 = iSizeCheck;
            }
            --m_Size;
            item = (CCloseCaptionItem *)((char *)item - 1);
          }
          else
          {
            iSizeCheck = ++v26;
            p_item += 12;
          }
        }
        while ( m_NumElements > avail_height );
        visibleitems.m_Size = m_Size;
      }
      v29 = 0;
      iSizeCheck = 0;
      if ( m_NumElements <= avail_height )
      {
        m_pParent = cc_minvisibleitems.m_pParent;
      }
      else
      {
        v30 = (unsigned __int8 *)&visibleitems.m_Memory.m_pMemory->item;
        while ( 1 )
        {
          m_pParent = cc_minvisibleitems.m_pParent;
          v32 = cc_minvisibleitems.m_pParent != nullptr ? cc_minvisibleitems.m_pParent->m_Value.m_nValue : 0;
          if ( m_Size <= v32 )
            break;
          item = (CCloseCaptionItem *)(m_Size - 1);
          if ( v29 > m_Size - 1 )
            break;
          if ( *(_BYTE *)(*(_DWORD *)v30 + 20431) != 0 )
          {
            m_NumElements -= *((_DWORD *)v30 - 2);
            v33 = m_Size - v29 - 1;
            *(_DWORD *)(*(_DWORD *)v30 + 20404) = 0;
            if ( v33 > 0 )
            {
              _V_memmove(dest: v30 - 8, src: v30 + 4, count: 12 * v33);
              v29 = iSizeCheck;
            }
            m_Size = (int)item;
          }
          else
          {
            iSizeCheck = ++v29;
            v30 += 12;
          }
          if ( m_NumElements <= avail_height )
          {
            m_pParent = cc_minvisibleitems.m_pParent;
            break;
          }
        }
        visibleitems.m_Size = m_Size;
      }
      if ( iFadeLine <= avail_height )
      {
        for ( j = 12 * m_Size - 12; m_NumElements > avail_height; j -= 12 )
        {
          v35 = m_pParent != nullptr ? m_pParent->m_Value.m_nValue : 0;
          if ( m_Size <= v35 )
            break;
          v36 = (unsigned __int8 *)visibleitems.m_Memory.m_pMemory;
          m_NumElements -= visibleitems.m_Memory.m_pMemory->height;
          --m_Size;
          visibleitems.m_Memory.m_pMemory->item->m_flTimeToLive = 0.0;
          if ( m_Size > 0 )
            _V_memmove(dest: v36, src: v36 + 12, count: j);
          m_pParent = cc_minvisibleitems.m_pParent;
        }
        visibleitems.m_Size = m_Size;
      }
    }
    ++i;
  }
  while ( i < iHeightToMove );
  if ( m_Size < 1 )
LABEL_78:
    v37 = 0.0;
  else
    v37 = 1.0;
  v38 = v104;
  if ( m_NumElements <= v104->m_CloseCaptionRepeats.m_NumElements )
    m_NumElements = v104->m_CloseCaptionRepeats.m_NumElements;
  if ( m_NumElements != v104->m_CloseCaptionRepeats.m_FirstFree )
  {
    v104->m_CloseCaptionRepeats.m_FirstFree = m_NumElements;
    v38->m_Items.m_Memory.m_nAllocationCount = *(int *)(gpGlobals.m_Index + 12);
    *(float *)&v38->m_Items.m_Memory.m_nGrowSize = *(float *)(gpGlobals.m_Index + 12) + *(float *)&v38->m_hFonts[1];
  }
  if ( v37 != *(float *)&v38->m_CloseCaptionRepeats.m_pElements )
  {
    *(float *)&v38->m_CloseCaptionRepeats.m_pElements = v37;
    v38->m_Items.m_Memory.m_nAllocationCount = *(int *)(gpGlobals.m_Index + 12);
    *(float *)&v38->m_Items.m_Memory.m_nGrowSize = *(float *)(gpGlobals.m_Index + 12) + *(float *)&v38->m_hFonts[1];
  }
  if ( m_Size == 0
    && v38->m_CloseCaptionRepeats.m_FirstFree == v38->m_CloseCaptionRepeats.m_LastAlloc.index
    && *(float *)&v38->m_CloseCaptionRepeats.m_pElements == *(float *)&v38->m_Items.m_Memory.m_pMemory )
  {
    v38->m_Items.m_Memory.m_nAllocationCount = 0;
    v38->m_Items.m_Memory.m_nGrowSize = 0;
    if ( visibleitems.m_Memory.m_nGrowSize >= 0 && visibleitems.m_Memory.m_pMemory != nullptr )
LABEL_151:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: visibleitems.m_Memory.m_pMemory);
  }
  else
  {
    v39 = *(float *)&v38->m_Items.m_Memory.m_nGrowSize;
    loaded = false;
    if ( v39 == 0.0 || (v40 = *(float *)&v38->m_Items.m_Memory.m_nAllocationCount) == 0.0 || v39 <= v40 )
    {
      m_FirstFree = v38->m_CloseCaptionRepeats.m_FirstFree;
      v38->m_Items.m_Memory.m_pMemory = (CCloseCaptionItem **)v38->m_CloseCaptionRepeats.m_pElements;
      v38->m_CloseCaptionRepeats.m_LastAlloc.index = m_FirstFree;
    }
    else
    {
      index = v38->m_CloseCaptionRepeats.m_LastAlloc.index;
      v42 = *(float *)&v38->m_Items.m_Memory.m_pMemory;
      v43 = (float)(v38->m_CloseCaptionRepeats.m_FirstFree - index);
      v44 = *(float *)&v38->m_CloseCaptionRepeats.m_pElements - v42;
      loaded = v43 < 0.0;
      v45 = (float)(*(float *)(gpGlobals.m_Index + 12) - v40) / (float)(v39 - v40);
      if ( v45 >= 0.0 )
      {
        if ( v45 > 1.0 )
          v45 = 1.0;
      }
      else
      {
        v45 = 0.0;
      }
      v46 = index + (int)(float)(v45 * v43);
      v47 = (float)(v45 * v44) + v42;
      v38->m_CloseCaptionRepeats.m_LastAlloc.index = v46;
      if ( v47 >= 0.0 )
      {
        if ( v47 > 1.0 )
          v47 = 1.0;
        *(float *)&v38->m_Items.m_Memory.m_pMemory = v47;
      }
      else
      {
        v38->m_Items.m_Memory.m_pMemory = nullptr;
      }
    }
    v49 = rcOutput.bottom - v38->m_CloseCaptionRepeats.m_LastAlloc.index - 24;
    ((void (__thiscall *)(CHudCloseCaption *, Color *))v38->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].LevelShutdown)(
      a1: v38,
      a2: &bgColor);
    v50 = v104->m_Items.m_Memory.m_pMemory;
    bgColor._color[3] = (int)*(float *)&v104->m_Items.m_pElements;
    v51 = v104->CHudElement::CGameEventListener::IGameEventListener2::__vftable;
    iLinesToMove = v49 <= 0 ? 0 : v49;
    ((void (__stdcall *)(int, int, int, int, Color, CCloseCaptionItem **, _DWORD))v51[7].SetHiddenBits)(
      a1: rcText.left,
      a2: iLinesToMove,
      a3: rcText.right - rcText.left,
      a4: rcText.bottom - iLinesToMove,
      a5: bgColor,
      a6: v50,
      a7: 0);
    if ( m_Size != 0 )
    {
      v52 = v104->m_CloseCaptionRepeats.m_LastAlloc.index;
      rcText.left += 12;
      rcText.right -= 12;
      if ( loaded )
        v52 = m_NumElements;
      v53 = rcText.bottom - v52 - 12;
      v54 = 0;
      rcText.top = v53;
      i = 0;
      if ( m_Size > 0 )
      {
        v104 = (CHudCloseCaption *)((char *)v104 - 56);
        do
        {
          v55 = avail_height;
          v56 = &visibleitems.m_Memory.m_pMemory[v54];
          iSizeCheck = (int)v56;
          if ( v54 == 0 )
          {
            v57 = v56->item;
            if ( v57->m_flAddedTime > 0.0 )
            {
              v58 = v57->m_flTimeToLive - v57->m_flAddedTime;
              if ( v58 < 0.0 )
                v58 = 0.0;
              v57->m_flTimeToLive = v58;
              v56->item->m_flAddedTime = 0.0;
            }
          }
          v59 = v56->height;
          m_szStream = (unsigned int)v56->item->m_szStream;
          height = v59;
          iFadeLine = -1;
          flFadeLineAlpha = 1.0;
          if ( v59 > v55 )
          {
            v61 = *(_DWORD *)(m_szStream + 20444);
            v62 = v59 - v55;
            v63 = 0;
            if ( v61 > 0 )
            {
              item = *(CCloseCaptionItem **)(m_szStream + 20432);
              while ( 1 )
              {
                v62 -= *(_DWORD *)(*(_DWORD *)item->m_szStream + 12);
                if ( v62 <= 0 )
                  break;
                item = (CCloseCaptionItem *)((char *)item + 4);
                if ( ++v63 >= v61 )
                  goto LABEL_124;
              }
              v61 = v63 + 2;
            }
LABEL_124:
            v64 = (__m128)*(unsigned int *)(m_szStream + 20408);
            v65.m128_i32[0] = 1258291200;
            v66 = v64.m128_f32[0] - *(float *)(m_szStream + 20404);
            v67 = v64.m128_f32[0] / (float)v61;
            v64.m128_f32[0] = v66 / v67;
            v68 = _mm_and_ps((__m128)0x80000000, v64);
            v65.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v64, v68), v65).m128_f32[0]) & 0x4B000000
                            | v68.m128_i32[0];
            v69 = v64;
            v69.m128_f32[0] = (float)((float)(v66 / v67) + v65.m128_f32[0]) - v65.m128_f32[0];
            v70 = v69;
            v70.m128_f32[0] = v69.m128_f32[0] - (float)(v66 / v67);
            v71 = v69.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v70, v68).m128_u32[0] & 0x3F800000);
            v72 = 0;
            iHeightToMove = 0;
            if ( v71 >= 0.0 )
            {
              if ( v71 > (float)v61 )
                v71 = (float)v61;
            }
            else
            {
              v71 = 0.0;
            }
            v73 = (int)v71;
            iLinesToMove = (int)v71;
            if ( (int)v71 != 0 )
            {
              v74 = 0;
              if ( v73 > 0 )
              {
                v75 = *(_DWORD *)(m_szStream + 20432);
                item = (CCloseCaptionItem *)(int)v71;
                do
                {
                  v72 = v74;
                  v74 += *(_DWORD *)(*(_DWORD *)v75 + 12);
                  v75 += 4;
                  v76 = item == (CCloseCaptionItem *)1;
                  item = (CCloseCaptionItem *)((char *)item - 1);
                  iHeightToMove = v72;
                }
                while ( !v76 );
                v73 = iLinesToMove;
              }
              v77 = v66 - (float)((float)v73 * v67);
              if ( v77 >= 0.5 )
              {
                if ( v77 < 1.0 )
                {
                  *(double *)&v82 = 0.0;
                  v83 = (float)((float)(v77 - 0.5) * 4.0);
                  if ( v83 < 0.0 || (*(double *)&v82 = 1.0, v83 > 1.0) )
                    v83 = *(double *)&v82;
                  v84 = v83;
                  v85 = ceil(X: (float)((float)(v74 - v72) * v84));
                  v74 = (int)(v85 + (double)iHeightToMove);
                  iFadeLine = v73 - 1;
                  flFadeLineAlpha = 0.0;
                }
                v72 = v74;
              }
              else
              {
                v78 = *(_DWORD *)(*(_DWORD *)(m_szStream + 20432) + 4 * v73 - 4);
                v79 = *(float *)(v78 + 16);
                iFadeLine = v73 - 1;
                if ( v79 == 0.0 )
                  *(float *)(v78 + 16) = *(float *)(gpGlobals.m_Index + 12);
                v80 = (float)(1.0 - (float)((float)(*(float *)(gpGlobals.m_Index + 12) - *(float *)(v78 + 16)) * 2.0));
                *(double *)&v81 = 0.0;
                if ( v80 < 0.0 || (*(double *)&v81 = 1.0, v80 > 1.0) )
                  v80 = *(double *)&v81;
                flFadeLineAlpha = v80;
              }
            }
            v59 = height;
            v53 = 2 - v72;
            rcText.top = 2 - v72;
          }
          v86 = (const wchar_t *)(v53 + v59);
          v87 = *(_DWORD *)(iSizeCheck + 4) + rcText.left + 6;
          v91.left = rcText.left;
          rcText.bottom = (int)v86;
          *(_QWORD *)&v91.top = *(_QWORD *)&rcText.top;
          v91.right = v87;
          CHudCloseCaption::DrawStream(
            this: v104,
            a2: v86,
            a3: m_szStream,
            a4: m_Size,
            rcText: &v91,
            rcWindow: &rcOutput,
            item: (CCloseCaptionItem *)m_szStream,
            iFadeLine,
            flFadeLineAlpha);
          v53 = (int)v86;
          rcText.top = (int)v86;
          if ( (int)v86 >= rcOutput.bottom )
            break;
          v54 = i + 1;
          i = v54;
        }
        while ( v54 < m_Size );
      }
      if ( visibleitems.m_Memory.m_nGrowSize >= 0 && visibleitems.m_Memory.m_pMemory != nullptr )
        goto LABEL_151;
    }
    else if ( visibleitems.m_Memory.m_nGrowSize >= 0 && visibleitems.m_Memory.m_pMemory != nullptr )
    {
      goto LABEL_151;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FEDF0
// Name: public: void CAsyncCaption::StartRequesting(class CHudCloseCaption __near *,class CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncCaption::StartRequesting(
        CAsyncCaption *this,
        CHudCloseCaption *hudCloseCaption,
        CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *directories)
{
  int v4; // esi
  CAsyncCaption::caption_t *v5; // eax
  int c; // [esp+8h] [ebp-4h]

  v4 = 0;
  c = this->m_Tokens.m_Size;
  if ( c > 0 )
  {
    do
    {
      v5 = this->m_Tokens.m_Memory.m_pMemory[v4];
      CAsyncCaptionResourceManager::PollForAsyncLoading(
        this: &g_AsyncCaptionResourceManager,
        hudCloseCaption,
        dbFileIndex: v5->fileindex,
        blockNum: directories->m_Memory.m_pMemory[v5->fileindex].m_CaptionDirectory.m_Memory.m_pMemory[v5->dirindex].blockNum);
      ++v4;
    }
    while ( v4 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FEE50
// Name: public: void CAsyncCaption::ProcessAsyncWork(class CHudCloseCaption __near *,class CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncCaption::ProcessAsyncWork(
        CAsyncCaption *this,
        CHudCloseCaption *hudCloseCaption,
        CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *directories)
{
  int m_Size; // edx
  int v4; // esi
  CAsyncCaption::caption_t *v5; // eax
  int c; // [esp+4h] [ebp-8h]
  CAsyncCaption *v7; // [esp+8h] [ebp-4h]

  m_Size = this->m_Tokens.m_Size;
  v4 = 0;
  v7 = this;
  for ( c = m_Size; v4 < m_Size; ++v4 )
  {
    v5 = this->m_Tokens.m_Memory.m_pMemory[v4];
    if ( v5->stream == nullptr )
    {
      CAsyncCaptionResourceManager::PollForAsyncLoading(
        this: &g_AsyncCaptionResourceManager,
        hudCloseCaption,
        dbFileIndex: v5->fileindex,
        blockNum: directories->m_Memory.m_pMemory[v5->fileindex].m_CaptionDirectory.m_Memory.m_pMemory[v5->dirindex].blockNum);
      this = v7;
      m_Size = c;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FEEC0
// Name: private: void CHudCloseCaption::ProcessAsyncWork(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::ProcessAsyncWork(CHudCloseCaption *this)
{
  int i; // eax
  int v3; // edi
  CAsyncCaption *m_Element; // ecx
  int m_Head; // ebx
  UtlLinkedListElem_t<CAsyncCaption *,unsigned short> *m_pMemory; // ecx
  int v7; // edi
  CAsyncCaption *v8; // eax
  int m_Size; // eax
  int v10; // ebx
  unsigned int hash; // ecx
  UtlLinkedListElem_t<CAsyncCaption *,unsigned short> *v12; // eax
  int m_Previous; // ecx
  int v14; // ecx
  CAsyncCaption *v15; // edi
  CAsyncCaption *v16; // ecx
  wchar_t buf[10200]; // [esp+18h] [ebp-51C0h] BYREF
  char pDest[512]; // [esp+4FC8h] [ebp-210h] BYREF
  int m_Next; // [esp+51C8h] [ebp-10h]
  int j; // [esp+51CCh] [ebp-Ch]
  CAsyncCaption *v21; // [esp+51D0h] [ebp-8h]
  int v22; // [esp+51D4h] [ebp-4h]

  for ( i = this->m_AsyncWork.m_Head; i != 0xFFFF; i = this->m_AsyncWork.m_Memory.m_pMemory[v3].m_Next )
  {
    v3 = (unsigned __int16)i;
    m_Element = this->m_AsyncWork.m_Memory.m_pMemory[v3].m_Element;
    if ( m_Element != nullptr )
      CAsyncCaption::ProcessAsyncWork(this: m_Element, hudCloseCaption: this, directories: &this->m_AsyncCaptions);
  }
  m_Head = this->m_AsyncWork.m_Head;
  v22 = m_Head;
  if ( m_Head != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = this->m_AsyncWork.m_Memory.m_pMemory;
      v7 = (unsigned __int16)m_Head;
      v8 = m_pMemory[(unsigned __int16)m_Head].m_Element;
      m_Next = m_pMemory[(unsigned __int16)m_Head].m_Next;
      v21 = v8;
      if ( v8 == nullptr || !CAsyncCaption::GetStream(this: v8, buf, bufSizeInBytes: 20400) )
        break;
      if ( buf[0] != 0 )
      {
        m_Size = v21->m_Tokens.m_Size;
        v10 = 0;
        pDest[0] = 0;
        for ( j = m_Size; v10 < j; ++v10 )
        {
          V_strncat(
            pDest,
            pSrc: v21->m_Tokens.m_Memory.m_pMemory[v10]->token,
            destBufferSize: 0x200u,
            max_chars_to_copy: -1);
          if ( v10 != j - 1 )
            V_strncat(pDest, pSrc: " ", destBufferSize: 0x200u, max_chars_to_copy: -1);
        }
        if ( (*((_BYTE *)v21 + 4) & 1) != 0 )
        {
          if ( buf[0] != 0 )
            CHudCloseCaption::Process(
              this,
              stream: buf,
              duration: (float)(v21->m_Tokens.m_Size + 1) * 0.75,
              fromplayer: false,
              direct: nullptr);
        }
        else
        {
          if ( v21->m_Tokens.m_Size != 0 )
            hash = (*v21->m_Tokens.m_Memory.m_pMemory)->hash;
          else
            hash = 0;
          CHudCloseCaption::_ProcessCaption(
            this,
            a2: (const char *)v7,
            caption: buf,
            hash,
            duration: v21->m_flDuration,
            fromplayer: (*((_BYTE *)v21 + 4) & 2) != 0,
            direct: (wchar_t *)((*((_BYTE *)v21 + 4) & 4) != 0));
        }
        LOWORD(m_Head) = v22;
      }
      if ( v7 < this->m_AsyncWork.m_Memory.m_nAllocationCount
        && (unsigned __int16)m_Head <= this->m_AsyncWork.m_LastAlloc.index )
      {
        v12 = this->m_AsyncWork.m_Memory.m_pMemory;
        if ( v12[v7].m_Previous != (_WORD)m_Head )
        {
          m_Previous = v12[v7].m_Previous;
          if ( (_WORD)m_Previous == 0xFFFF )
            this->m_AsyncWork.m_Head = v12[v7].m_Next;
          else
            v12[m_Previous].m_Next = v12[v7].m_Next;
          v14 = v12[v7].m_Next;
          if ( (_WORD)v14 == 0xFFFF )
          {
            this->m_AsyncWork.m_Tail = v12[v7].m_Previous;
          }
          else
          {
            this->m_AsyncWork.m_Memory.m_pMemory[v14].m_Previous = v12[v7].m_Previous;
            LOWORD(m_Head) = v22;
          }
          v12[v7].m_Next = m_Head;
          v12[v7].m_Previous = m_Head;
          --this->m_AsyncWork.m_ElementCount;
        }
      }
      this->m_AsyncWork.m_Memory.m_pMemory[v7].m_Next = this->m_AsyncWork.m_FirstFree;
      v15 = v21;
      v16 = v21;
      this->m_AsyncWork.m_FirstFree = m_Head;
      CAsyncCaption::~CAsyncCaption(this: v16);
      C_BaseEntity::operator delete(pMem: v15);
      v22 = m_Next;
      if ( m_Next == 0xFFFF )
        break;
      LOWORD(m_Head) = v22;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF150
// Name: public: void CHudCloseCaption::PlayRandomCaption(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CHudCloseCaption::PlayRandomCaption(CHudCloseCaption *this)
{
  CAsyncCaption *v1; // esi
  _BYTE *v3; // eax
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream *v5; // ecx
  CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *p_m_AsyncWork; // edi
  int v7; // ebx
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *v8; // eax

  v1 = nullptr;
  if ( closecaption.m_pParent != nullptr && closecaption.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v3 != nullptr )
    {
      v3[4] &= 0xFCu;
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 2) = 0;
      *((_DWORD *)v3 + 3) = 0;
      *((_DWORD *)v3 + 4) = 0;
      *((_DWORD *)v3 + 5) = 0;
      *((_DWORD *)v3 + 6) = 0;
      v1 = (CAsyncCaption *)v3;
    }
    *((_BYTE *)v1 + 4) &= ~1u;
    CAsyncCaption::AddRandomToken(this: v1, directories: &this->m_AsyncCaptions);
    v1->m_flDuration = _RandomFloat(this: v4, a2: 1.0, a3: 3.0);
    *((_BYTE *)v1 + 4) ^= (*((_BYTE *)v1 + 4) ^ (2 * (_RandomInt(this: v5, a2: 0, a3: 1) == 0))) & 2;
    CAsyncCaption::StartRequesting(this: v1, hudCloseCaption: this, directories: &this->m_AsyncCaptions);
    p_m_AsyncWork = (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_AsyncWork;
    v7 = (unsigned __int16)CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal(
                             this: &this->m_AsyncWork,
                             multilist: false);
    if ( (_WORD)v7 != 0xFFFF )
    {
      CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
        this: p_m_AsyncWork,
        before: 0xFFFFu,
        elem: v7);
      v8 = &p_m_AsyncWork->m_Memory.m_pMemory[v7];
      if ( v8 != nullptr )
        v8->m_Element = (C_RopeKeyframe *)v1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF230
// Name: private: bool CHudCloseCaption::AddAsyncWork(char const __near *,bool,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHudCloseCaption::AddAsyncWork(
        CHudCloseCaption *this,
        char *tokenstream,
        bool bIsStream,
        float duration,
        bool fromplayer,
        bool direct)
{
  CAsyncCaption *v6; // esi
  _BYTE *v9; // eax
  char *v10; // ebx
  CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *p_m_AsyncWork; // ebx
  unsigned __int16 v12; // ax
  int v13; // edi
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *v14; // eax
  CHudCloseCaption *v15; // eax
  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *p_m_AsyncCaptions; // edx
  char tokenname[512]; // [esp+Ch] [ebp-210h] BYREF
  CaptionLookup_t v18; // [esp+20Ch] [ebp-10h] BYREF
  CHudCloseCaption *hudCloseCaption; // [esp+218h] [ebp-4h]
  bool bret; // [esp+237h] [ebp+1Bh]

  v6 = nullptr;
  hudCloseCaption = this;
  if ( (closecaption.m_pParent == nullptr || closecaption.m_pParent->m_Value.m_nValue == 0) && !direct )
    return false;
  bret = true;
  v9 = MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v9 != nullptr )
  {
    v9[4] &= 0xFCu;
    *(_DWORD *)v9 = 0;
    *((_DWORD *)v9 + 2) = 0;
    *((_DWORD *)v9 + 3) = 0;
    *((_DWORD *)v9 + 4) = 0;
    *((_DWORD *)v9 + 5) = 0;
    *((_DWORD *)v9 + 6) = 0;
    v6 = (CAsyncCaption *)v9;
  }
  *((_BYTE *)v6 + 4) = bIsStream | *((_BYTE *)v6 + 4) & 0xFA | (4 * direct);
  if ( bIsStream )
  {
    tokenname[0] = 0;
    v10 = nexttoken(token: tokenname, str: tokenstream, sep: 32);
    while ( v10 != nullptr )
    {
      if ( (int)_V_strlen(str: tokenname) <= 0 )
        break;
      v10 = nexttoken(token: tokenname, str: v10, sep: 32);
      if ( _V_strlen(str: tokenname) == 0 )
        break;
      CaptionLookup_t::SetHash(this: &v18, string: tokenname);
      CAsyncCaption::AddTokenByHash(this: v6, directories: &this->m_AsyncCaptions, hash: v18.hash, pchToken: tokenname);
    }
  }
  else
  {
    bret = CAsyncCaption::AddToken(this: v6, directories: &this->m_AsyncCaptions, token: tokenstream);
  }
  p_m_AsyncWork = (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_AsyncWork;
  v12 = CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_AsyncWork,
          multilist: false);
  v13 = v12;
  if ( v12 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_AsyncWork,
      before: 0xFFFFu,
      elem: v12);
    v14 = &p_m_AsyncWork->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      v14->m_Element = (C_RopeKeyframe *)v6;
  }
  v15 = hudCloseCaption;
  p_m_AsyncCaptions = &hudCloseCaption->m_AsyncCaptions;
  *((_BYTE *)v6 + 4) ^= (*((_BYTE *)v6 + 4) ^ (2 * fromplayer)) & 2;
  v6->m_flDuration = duration;
  CAsyncCaption::StartRequesting(this: v6, hudCloseCaption: v15, directories: p_m_AsyncCaptions);
  return bret;
}

//------------------------------------------------------------------------------
// Address: 0x100FF3C0
// Name: private: bool CHudCloseCaption::AddAsyncWorkByHash(unsigned int,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHudCloseCaption::AddAsyncWorkByHash(
        CHudCloseCaption *this,
        unsigned int hash,
        float duration,
        bool fromplayer,
        bool direct)
{
  CAsyncCaption *v5; // esi
  _BYTE *v8; // eax
  CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *p_m_AsyncWork; // ebx
  unsigned __int16 v10; // ax
  int v11; // edi
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *v12; // eax
  bool bret; // [esp+27h] [ebp+17h]

  v5 = nullptr;
  if ( (closecaption.m_pParent == nullptr || closecaption.m_pParent->m_Value.m_nValue == 0) && !direct )
    return false;
  v8 = MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v8 != nullptr )
  {
    v8[4] &= 0xFCu;
    *(_DWORD *)v8 = 0;
    *((_DWORD *)v8 + 2) = 0;
    *((_DWORD *)v8 + 3) = 0;
    *((_DWORD *)v8 + 4) = 0;
    *((_DWORD *)v8 + 5) = 0;
    *((_DWORD *)v8 + 6) = 0;
    v5 = (CAsyncCaption *)v8;
  }
  *((_BYTE *)v5 + 4) = *((_BYTE *)v5 + 4) & 0xFA | (4 * direct);
  p_m_AsyncWork = (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_AsyncWork;
  bret = CAsyncCaption::AddTokenByHash(this: v5, directories: &this->m_AsyncCaptions, hash, pchToken: prType);
  v10 = CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_AsyncWork,
          multilist: false);
  v11 = v10;
  if ( v10 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_AsyncWork,
      before: 0xFFFFu,
      elem: v10);
    v12 = &p_m_AsyncWork->m_Memory.m_pMemory[v11];
    if ( v12 != nullptr )
      v12->m_Element = (C_RopeKeyframe *)v5;
  }
  *((_BYTE *)v5 + 4) ^= (*((_BYTE *)v5 + 4) ^ (2 * fromplayer)) & 2;
  v5->m_flDuration = duration;
  CAsyncCaption::StartRequesting(this: v5, hudCloseCaption: this, directories: &this->m_AsyncCaptions);
  return bret;
}

//------------------------------------------------------------------------------
// Address: 0x100FF4B0
// Name: public: void CHudCloseCaption::ProcessSentenceCaptionStream(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::ProcessSentenceCaptionStream(CHudCloseCaption *this, char *tokenstream)
{
  float m_fValue; // xmm0_4
  CAsyncCaption *v4; // edi
  unsigned int v5; // esi
  int v6; // eax
  UtlRBTreeNode_t<CHudCloseCaption::CaptionRepeat,int> *m_pMemory; // ecx
  float v8; // xmm0_4
  int v9; // eax
  float v10; // xmm1_4
  int p_m_Data; // eax
  _BYTE *v12; // eax
  char *v13; // esi
  CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *p_m_AsyncWork; // esi
  unsigned __int16 v15; // ax
  int v16; // ebx
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *v17; // eax
  CHudCloseCaption *v18; // eax
  char tokenname[512]; // [esp+0h] [ebp-41Ch] BYREF
  char token[512]; // [esp+200h] [ebp-21Ch] BYREF
  CHudCloseCaption *hudCloseCaption; // [esp+400h] [ebp-1Ch]
  CHudCloseCaption::CaptionRepeat entry; // [esp+404h] [ebp-18h] BYREF
  unsigned int pulCRC; // [esp+414h] [ebp-8h] BYREF
  float v24; // [esp+418h] [ebp-4h]

  m_fValue = cc_sentencecaptionnorepeat.m_pParent->m_Value.m_fValue;
  hudCloseCaption = this;
  if ( m_fValue >= 0.1 )
  {
    if ( m_fValue <= 60.0 )
      v24 = m_fValue;
    else
      v24 = 60.0;
  }
  else
  {
    v24 = 0.1;
  }
  tokenname[0] = 0;
  nexttoken(token: tokenname, str: tokenstream, sep: 32);
  if ( (int)_V_strlen(str: tokenname) <= 0 )
  {
    v4 = nullptr;
  }
  else
  {
    v4 = nullptr;
    memset((void *)&entry, 0, sizeof(entry));
    v5 = _V_strlen(str: tokenname);
    CRC32_Init(&pulCRC);
    CRC32_ProcessBuffer(&pulCRC, pBuffer: tokenname, nBuffer: v5);
    CRC32_Final(&pulCRC);
    entry.m_nTokenIndex = pulCRC;
    v6 = CUtlRBTree<CHudCloseCaption::CaptionRepeat,int,bool (__cdecl *)(CHudCloseCaption::CaptionRepeat const &,CHudCloseCaption::CaptionRepeat const &),CUtlMemory<UtlRBTreeNode_t<CHudCloseCaption::CaptionRepeat,int>,int>>::Find(
           this: &this->m_CloseCaptionRepeats,
           search: &entry);
    if ( v6 == -1 )
    {
      entry.m_flLastEmitTime = *(float *)(gpGlobals.m_Index + 12);
      entry.m_nLastEmitTick = *(_DWORD *)(gpGlobals.m_Index + 24);
      entry.m_flInterval = v24;
      CUtlRBTree<CHudCloseCaption::CaptionRepeat,int,bool (__cdecl *)(CHudCloseCaption::CaptionRepeat const &,CHudCloseCaption::CaptionRepeat const &),CUtlMemory<UtlRBTreeNode_t<CHudCloseCaption::CaptionRepeat,int>,int>>::Insert(
        this: &this->m_CloseCaptionRepeats,
        a2: nullptr,
        insert: &entry);
    }
    else
    {
      m_pMemory = this->m_CloseCaptionRepeats.m_Elements.m_pMemory;
      v8 = *(float *)(gpGlobals.m_Index + 12);
      v9 = v6;
      v10 = m_pMemory[v9].m_Data.m_flInterval + m_pMemory[v9].m_Data.m_flLastEmitTime;
      p_m_Data = (int)&m_pMemory[v9].m_Data;
      if ( v10 > v8 )
        return;
      *(float *)(p_m_Data + 8) = v8;
      *(_DWORD *)(p_m_Data + 4) = *(_DWORD *)(gpGlobals.m_Index + 24);
    }
  }
  if ( closecaption.m_pParent != nullptr && closecaption.m_pParent->m_Value.m_nValue != 0 )
  {
    v12 = MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v12 != nullptr )
    {
      v12[4] &= 0xFCu;
      *(_DWORD *)v12 = 0;
      *((_DWORD *)v12 + 2) = 0;
      *((_DWORD *)v12 + 3) = 0;
      *((_DWORD *)v12 + 4) = 0;
      *((_DWORD *)v12 + 5) = 0;
      *((_DWORD *)v12 + 6) = 0;
      v4 = (CAsyncCaption *)v12;
    }
    *((_BYTE *)v4 + 4) = *((_BYTE *)v4 + 4) & 0xFA | 1;
    token[0] = 0;
    v13 = nexttoken(token, str: tokenstream, sep: 32);
    while ( v13 != nullptr )
    {
      if ( (int)_V_strlen(str: token) <= 0 )
        break;
      v13 = nexttoken(token, str: v13, sep: 32);
      if ( _V_strlen(str: token) == 0 )
        break;
      CaptionLookup_t::SetHash(this: (CaptionLookup_t *)&entry.m_nLastEmitTick, string: token);
      CAsyncCaption::AddTokenByHash(
        this: v4,
        directories: &this->m_AsyncCaptions,
        hash: entry.m_nLastEmitTick,
        pchToken: token);
    }
    p_m_AsyncWork = (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_AsyncWork;
    v15 = CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal(
            this: &this->m_AsyncWork,
            multilist: false);
    v16 = v15;
    if ( v15 != 0xFFFF )
    {
      CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
        this: p_m_AsyncWork,
        before: 0xFFFFu,
        elem: v15);
      v17 = &p_m_AsyncWork->m_Memory.m_pMemory[v16];
      if ( v17 != nullptr )
        v17->m_Element = (C_RopeKeyframe *)v4;
    }
    v18 = hudCloseCaption;
    *((_BYTE *)v4 + 4) &= ~2u;
    v4->m_flDuration = 0.0;
    CAsyncCaption::StartRequesting(this: v4, hudCloseCaption: v18, directories: &v18->m_AsyncCaptions);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF730
// Name: public: bool CHudCloseCaption::ProcessCaption(char const __near *,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHudCloseCaption::ProcessCaption(
        CHudCloseCaption *this,
        char *tokenname,
        float duration,
        bool fromplayer,
        bool direct)
{
  return CHudCloseCaption::AddAsyncWork(this, tokenstream: tokenname, bIsStream: false, duration, fromplayer, direct);
}

//------------------------------------------------------------------------------
// Address: 0x100FF760
// Name: public: void CHudCloseCaption::MsgFunc_CloseCaption(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::MsgFunc_CloseCaption(CHudCloseCaption *this, bf_read *msg)
{
  int m_nBitsAvail; // esi
  unsigned int v3; // ecx
  const unsigned int *v4; // edx
  const unsigned int *v5; // esi
  const unsigned int *m_pDataIn; // ecx
  unsigned int m_nInBufWord; // edi
  int v8; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int v10; // esi
  unsigned int v11; // ebx
  int v12; // ecx
  unsigned int v13; // edx
  int v14; // esi
  int v15; // ecx
  int v16; // ecx
  const unsigned int *v17; // ecx
  const unsigned int *v18; // edx
  unsigned int v19; // edx
  const unsigned int *v20; // esi
  unsigned int v21; // edi
  int v22; // edx
  const unsigned int *v23; // ecx
  unsigned int v24; // esi
  unsigned int v25; // ebx
  double v26; // st7
  int v27; // ecx
  unsigned int v28; // edx
  int v29; // esi
  int v30; // ecx
  int v31; // eax
  const unsigned int *v32; // ecx
  const unsigned int *v33; // edx
  unsigned int v34; // edx
  const unsigned int *v35; // esi
  unsigned int v36; // edi
  int v37; // edx
  const unsigned int *v38; // ecx
  unsigned int v39; // esi
  unsigned int v40; // ebx
  _BYTE *v41; // eax
  CAsyncCaption *v42; // esi
  unsigned __int16 v43; // ax
  int v44; // ebx
  UtlLinkedListElem_t<CAsyncCaption *,unsigned short> *v45; // eax
  float duration; // [esp+Ch] [ebp-Ch]
  int hash; // [esp+14h] [ebp-4h]
  bool fromplayer_3; // [esp+23h] [ebp+Bh]

  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pDataIn = msg->m_pDataIn;
    m_nInBufWord = msg->m_nInBufWord;
    v8 = 32 - m_nBitsAvail;
    m_pBufferEnd = msg->m_pBufferEnd;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      hash = 0;
    }
    else
    {
      v10 = msg->m_nInBufWord;
      v11 = (v10 & CBitBuffer::s_nMaskTable[v8]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v8;
      hash = v11 | m_nInBufWord;
      msg->m_nInBufWord = v10 >> v8;
    }
    goto LABEL_19;
  }
  v3 = msg->m_nInBufWord;
  msg->m_nBitsAvail = m_nBitsAvail - 32;
  if ( m_nBitsAvail == 32 )
  {
    v4 = msg->m_pDataIn;
    v5 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v4 == v5 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v4 + 1;
      hash = v3;
    }
    else
    {
      if ( v4 <= v5 )
      {
        msg->m_nInBufWord = *v4;
        msg->m_pDataIn = v4 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      hash = v3;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    hash = v3;
  }
LABEL_19:
  v12 = msg->m_nBitsAvail;
  if ( v12 < 15 )
  {
    v20 = msg->m_pBufferEnd;
    v21 = msg->m_nInBufWord;
    v22 = 15 - v12;
    v23 = msg->m_pDataIn;
    if ( v23 == v20 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v20 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_34;
      }
      msg->m_nInBufWord = *v23;
    }
    msg->m_pDataIn = v23 + 1;
LABEL_34:
    if ( msg->m_bOverflow )
    {
      v16 = 0;
    }
    else
    {
      v24 = msg->m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v22]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v22;
      v16 = v25 | v21;
      msg->m_nInBufWord = v24 >> v22;
    }
    goto LABEL_37;
  }
  v13 = msg->m_nInBufWord;
  v14 = v13 & 0x7FFF;
  v15 = v12 - 15;
  msg->m_nBitsAvail = v15;
  if ( v15 != 0 )
  {
    msg->m_nInBufWord = v13 >> 15;
    v16 = v13 & 0x7FFF;
  }
  else
  {
    v17 = msg->m_pDataIn;
    v18 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v17 == v18 )
    {
      msg->m_pDataIn = v17 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v16 = v14;
    }
    else
    {
      if ( v17 <= v18 )
      {
        v19 = *v17;
        msg->m_pDataIn = v17 + 1;
        msg->m_nInBufWord = v19;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v16 = v14;
    }
  }
LABEL_37:
  v26 = (double)(unsigned int)v16 * 0.1;
  v27 = msg->m_nBitsAvail;
  if ( v27 < 1 )
  {
    v35 = msg->m_pBufferEnd;
    v36 = msg->m_nInBufWord;
    v37 = 1 - v27;
    v38 = msg->m_pDataIn;
    if ( v38 == v35 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v38 > v35 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_52;
      }
      msg->m_nInBufWord = *v38;
    }
    msg->m_pDataIn = v38 + 1;
LABEL_52:
    if ( msg->m_bOverflow )
    {
      v31 = 0;
    }
    else
    {
      v39 = msg->m_nInBufWord;
      v40 = (v39 & CBitBuffer::s_nMaskTable[v37]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v37;
      msg->m_nInBufWord = v39 >> v37;
      v31 = v40 | v36;
    }
    goto LABEL_55;
  }
  v28 = msg->m_nInBufWord;
  v29 = v28 & 1;
  v30 = v27 - 1;
  msg->m_nBitsAvail = v30;
  if ( v30 != 0 )
  {
    msg->m_nInBufWord = v28 >> 1;
    v31 = v28 & 1;
  }
  else
  {
    v32 = msg->m_pDataIn;
    v33 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v32 == v33 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v32 + 1;
      v31 = v29;
    }
    else
    {
      if ( v32 <= v33 )
      {
        v34 = *v32;
        msg->m_pDataIn = v32 + 1;
        msg->m_nInBufWord = v34;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v31 = v29;
    }
  }
LABEL_55:
  fromplayer_3 = v31 != 0;
  if ( closecaption.m_pParent != nullptr && closecaption.m_pParent->m_Value.m_nValue != 0 )
  {
    v41 = MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v41 != nullptr )
    {
      v41[4] &= 0xFCu;
      *(_DWORD *)v41 = 0;
      *((_DWORD *)v41 + 2) = 0;
      *((_DWORD *)v41 + 3) = 0;
      *((_DWORD *)v41 + 4) = 0;
      *((_DWORD *)v41 + 5) = 0;
      *((_DWORD *)v41 + 6) = 0;
      v42 = (CAsyncCaption *)v41;
    }
    else
    {
      v42 = nullptr;
    }
    *((_BYTE *)v42 + 4) &= 0xFAu;
    CAsyncCaption::AddTokenByHash(this: v42, directories: &this->m_AsyncCaptions, hash, pchToken: prType);
    v43 = CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal(
            this: &this->m_AsyncWork,
            multilist: false);
    v44 = v43;
    if ( v43 != 0xFFFF )
    {
      CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_AsyncWork,
        before: 0xFFFFu,
        elem: v43);
      v45 = &this->m_AsyncWork.m_Memory.m_pMemory[v44];
      if ( v45 != nullptr )
        v45->m_Element = v42;
    }
    *((_BYTE *)v42 + 4) ^= (*((_BYTE *)v42 + 4) ^ (2 * fromplayer_3)) & 2;
    duration = v26;
    v42->m_flDuration = duration;
    CAsyncCaption::StartRequesting(this: v42, hudCloseCaption: this, directories: &this->m_AsyncCaptions);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FFB00
// Name: public: void CHudCloseCaption::MsgFunc_CloseCaptionDirect(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::MsgFunc_CloseCaptionDirect(CHudCloseCaption *this, bf_read *msg)
{
  int m_nBitsAvail; // esi
  unsigned int v4; // ecx
  const unsigned int *v5; // edx
  const unsigned int *v6; // esi
  const unsigned int *m_pDataIn; // ecx
  unsigned int m_nInBufWord; // edi
  int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int v11; // esi
  unsigned int v12; // ebx
  int v13; // ecx
  unsigned int v14; // edx
  int v15; // esi
  int v16; // ecx
  int v17; // ecx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edx
  unsigned int v20; // edx
  const unsigned int *v21; // esi
  unsigned int v22; // edi
  int v23; // edx
  const unsigned int *v24; // ecx
  unsigned int v25; // esi
  unsigned int v26; // ebx
  double v27; // st7
  int v28; // ecx
  unsigned int v29; // edx
  int v30; // esi
  int v31; // ecx
  int v32; // eax
  const unsigned int *v33; // ecx
  const unsigned int *v34; // edx
  unsigned int v35; // edx
  const unsigned int *v36; // esi
  unsigned int v37; // edi
  int v38; // edx
  const unsigned int *v39; // ecx
  unsigned int v40; // esi
  unsigned int v41; // ebx
  float duration; // [esp+18h] [ebp-8h]
  bf_read *msga; // [esp+28h] [ebp+8h]

  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pDataIn = msg->m_pDataIn;
    m_nInBufWord = msg->m_nInBufWord;
    v9 = 32 - m_nBitsAvail;
    m_pBufferEnd = msg->m_pBufferEnd;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      msga = nullptr;
    }
    else
    {
      v11 = msg->m_nInBufWord;
      v12 = (v11 & CBitBuffer::s_nMaskTable[v9]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v9;
      msga = (bf_read *)(v12 | m_nInBufWord);
      msg->m_nInBufWord = v11 >> v9;
    }
    goto LABEL_19;
  }
  v4 = msg->m_nInBufWord;
  msg->m_nBitsAvail = m_nBitsAvail - 32;
  if ( m_nBitsAvail == 32 )
  {
    v5 = msg->m_pDataIn;
    v6 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v5 == v6 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v5 + 1;
      msga = (bf_read *)v4;
    }
    else
    {
      if ( v5 <= v6 )
      {
        msg->m_nInBufWord = *v5;
        msg->m_pDataIn = v5 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msga = (bf_read *)v4;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    msga = (bf_read *)v4;
  }
LABEL_19:
  v13 = msg->m_nBitsAvail;
  if ( v13 < 15 )
  {
    v21 = msg->m_pBufferEnd;
    v22 = msg->m_nInBufWord;
    v23 = 15 - v13;
    v24 = msg->m_pDataIn;
    if ( v24 == v21 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v24 > v21 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_34;
      }
      msg->m_nInBufWord = *v24;
    }
    msg->m_pDataIn = v24 + 1;
LABEL_34:
    if ( msg->m_bOverflow )
    {
      v17 = 0;
    }
    else
    {
      v25 = msg->m_nInBufWord;
      v26 = (v25 & CBitBuffer::s_nMaskTable[v23]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v23;
      v17 = v26 | v22;
      msg->m_nInBufWord = v25 >> v23;
    }
    goto LABEL_37;
  }
  v14 = msg->m_nInBufWord;
  v15 = v14 & 0x7FFF;
  v16 = v13 - 15;
  msg->m_nBitsAvail = v16;
  if ( v16 != 0 )
  {
    msg->m_nInBufWord = v14 >> 15;
    v17 = v14 & 0x7FFF;
  }
  else
  {
    v18 = msg->m_pDataIn;
    v19 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v18 == v19 )
    {
      msg->m_pDataIn = v18 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v17 = v15;
    }
    else
    {
      if ( v18 <= v19 )
      {
        v20 = *v18;
        msg->m_pDataIn = v18 + 1;
        msg->m_nInBufWord = v20;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v17 = v15;
    }
  }
LABEL_37:
  v27 = (double)(unsigned int)v17 * 0.1;
  v28 = msg->m_nBitsAvail;
  if ( v28 < 1 )
  {
    v36 = msg->m_pBufferEnd;
    v37 = msg->m_nInBufWord;
    v38 = 1 - v28;
    v39 = msg->m_pDataIn;
    if ( v39 == v36 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v39 > v36 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_52;
      }
      msg->m_nInBufWord = *v39;
    }
    msg->m_pDataIn = v39 + 1;
LABEL_52:
    if ( msg->m_bOverflow )
    {
      v32 = 0;
    }
    else
    {
      v40 = msg->m_nInBufWord;
      v41 = (v40 & CBitBuffer::s_nMaskTable[v38]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v38;
      msg->m_nInBufWord = v40 >> v38;
      v32 = v41 | v37;
    }
    goto LABEL_55;
  }
  v29 = msg->m_nInBufWord;
  v30 = v29 & 1;
  v31 = v28 - 1;
  msg->m_nBitsAvail = v31;
  if ( v31 != 0 )
  {
    msg->m_nInBufWord = v29 >> 1;
    v32 = v29 & 1;
  }
  else
  {
    v33 = msg->m_pDataIn;
    v34 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v33 == v34 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v33 + 1;
      v32 = v30;
    }
    else
    {
      if ( v33 <= v34 )
      {
        v35 = *v33;
        msg->m_pDataIn = v33 + 1;
        msg->m_nInBufWord = v35;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v32 = v30;
    }
  }
LABEL_55:
  this->m_bVisibleDueToDirect = true;
  duration = v27;
  CHudCloseCaption::AddAsyncWorkByHash(this, hash: (unsigned int)msga, duration, fromplayer: v32 != 0, direct: true);
}

//------------------------------------------------------------------------------
// Address: 0x100FFDF0
// Name: cc_emit
// Source: json
//------------------------------------------------------------------------------
void __cdecl cc_emit(const CCommand *args)
{
  CHud *Hud; // eax
  CHudCloseCaption *Element; // edi
  _BYTE *v3; // eax
  CAsyncCaption *v4; // esi
  unsigned __int16 v5; // ax
  int v6; // ebx
  UtlLinkedListElem_t<CAsyncCaption *,unsigned short> *v7; // eax
  const char *argsa; // [esp+10h] [ebp+8h]

  if ( args->m_nArgc == 2 )
  {
    Hud = GetHud(nSlot: 0);
    Element = (CHudCloseCaption *)CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
    if ( Element != nullptr )
    {
      argsa = args->m_nArgc > 1 ? args->m_ppArgv[1] : prType;
      if ( closecaption.m_pParent != nullptr && closecaption.m_pParent->m_Value.m_nValue != 0 )
      {
        v3 = MemAlloc_Alloc(nSize: 0x1Cu);
        if ( v3 != nullptr )
        {
          v3[4] &= 0xFCu;
          *(_DWORD *)v3 = 0;
          *((_DWORD *)v3 + 2) = 0;
          *((_DWORD *)v3 + 3) = 0;
          *((_DWORD *)v3 + 4) = 0;
          *((_DWORD *)v3 + 5) = 0;
          *((_DWORD *)v3 + 6) = 0;
          v4 = (CAsyncCaption *)v3;
        }
        else
        {
          v4 = nullptr;
        }
        *((_BYTE *)v4 + 4) &= 0xFAu;
        CAsyncCaption::AddToken(this: v4, directories: &Element->m_AsyncCaptions, token: argsa);
        v5 = CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal(
               this: &Element->m_AsyncWork,
               multilist: false);
        v6 = v5;
        if ( v5 != 0xFFFF )
        {
          CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
            this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&Element->m_AsyncWork,
            before: 0xFFFFu,
            elem: v5);
          v7 = &Element->m_AsyncWork.m_Memory.m_pMemory[v6];
          if ( v7 != nullptr )
            v7->m_Element = v4;
        }
        *((_BYTE *)v4 + 4) &= ~2u;
        v4->m_flDuration = 5.0;
        CAsyncCaption::StartRequesting(this: v4, hudCloseCaption: Element, directories: &Element->m_AsyncCaptions);
      }
    }
  }
  else
  {
    _Msg(a1: "usage:  cc_emit tokenname\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FFF10
// Name: cc_random
// Source: json
//------------------------------------------------------------------------------
void __cdecl cc_random(const CCommand *args)
{
  int v1; // esi
  const char *v2; // edi
  CHud *Hud; // eax
  CHudCloseCaption *Element; // edi

  v1 = 1;
  if ( args->m_nArgc == 2 && atoi(nptr: args->m_ppArgv[1]) >= 1 )
  {
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    else
      v2 = prType;
    v1 = atoi(nptr: v2);
  }
  Hud = GetHud(nSlot: 0);
  Element = (CHudCloseCaption *)CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
  if ( Element != nullptr && v1 > 0 )
  {
    do
    {
      CHudCloseCaption::PlayRandomCaption(this: Element);
      --v1;
    }
    while ( v1 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101000F0
// Name: public: struct AsyncCaption_t __near & AsyncCaption_t::operator=(struct AsyncCaption_t const __near &)
// Source: json
//------------------------------------------------------------------------------
AsyncCaption_t *__thiscall AsyncCaption_t::operator=(AsyncCaption_t *this, const AsyncCaption_t *rhs)
{
  const AsyncCaption_t *v2; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short> *v12; // ecx
  int v13; // edi
  const AsyncCaption_t::BlockInfo_t *p_m_Data; // [esp+8h] [ebp-10h]
  unsigned __int16 i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = rhs;
  if ( this != rhs )
  {
    CUtlSortVector<CaptionLookup_t,CCaptionLookupLess>::operator=(
      this: &this->m_CaptionDirectory,
      __that: &rhs->m_CaptionDirectory);
    this->m_Header = rhs->m_Header;
    this->m_DataBaseFile.m_Id = rhs->m_DataBaseFile.m_Id;
    Inorder = CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::FirstInorder(this: &rhs->m_RequestedBlocks);
    for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
    {
      p_m_Data = &v2->m_RequestedBlocks.m_Elements.m_pMemory[Inorder].m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->m_RequestedBlocks,
        insert: p_m_Data,
        parent,
        &leftchild);
      v5 = CUtlRBTree<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMetaClassMgrImp::MetaClassDict_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
             this: &this->m_RequestedBlocks,
             a2: (const char *)v2);
      v6 = parent[0];
      v7 = v5;
      v8 = v5;
      v9 = &this->m_RequestedBlocks.m_Elements.m_pMemory[v8];
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Parent = v6;
      v9->m_Tag = 0;
      if ( v6 == 0xFFFF )
      {
        this->m_RequestedBlocks.m_Root = v7;
      }
      else
      {
        v10 = v6;
        m_pMemory = this->m_RequestedBlocks.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v7;
        else
          m_pMemory[v10].m_Right = v7;
      }
      CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->m_RequestedBlocks,
        elem: v7);
      v12 = this->m_RequestedBlocks.m_Elements.m_pMemory;
      ++this->m_RequestedBlocks.m_NumElements;
      v13 = (int)&v12[v8].m_Data;
      if ( v13 != 0 )
      {
        *(_QWORD *)v13 = *(_QWORD *)&p_m_Data->fileindex;
        *(_DWORD *)(v13 + 8) = p_m_Data->handle;
      }
      v2 = rhs;
      Inorder = CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &rhs->m_RequestedBlocks,
                  i);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10100230
// Name: void __MsgFunc_CHudCloseCaption_CloseCaption(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CHudCloseCaption_CloseCaption(bf_read *msg)
{
  CHud *Hud; // eax
  CHudCloseCaption *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (CHudCloseCaption *)CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
  if ( Element != nullptr )
    CHudCloseCaption::MsgFunc_CloseCaption(this: Element, msg);
}

//------------------------------------------------------------------------------
// Address: 0x10100260
// Name: void __MsgFunc_CHudCloseCaption_CloseCaptionDirect(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CHudCloseCaption_CloseCaptionDirect(bf_read *msg)
{
  CHud *Hud; // eax
  CHudCloseCaption *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (CHudCloseCaption *)CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
  if ( Element != nullptr )
    CHudCloseCaption::MsgFunc_CloseCaptionDirect(this: Element, msg);
}

//------------------------------------------------------------------------------
// Address: 0x10100290
// Name: public: virtual void CHudCloseCaption::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::OnTick(CHudCloseCaption *this)
{
  int v2; // ebx
  int m_nValue; // eax
  int v4; // eax
  int v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  int v9; // ecx
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  int v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // ecx
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  int v21; // ecx
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  int v25; // edi
  CCloseCaptionItem *v26; // ebx
  float dt; // [esp+Ch] [ebp-Ch]
  int c; // [esp+10h] [ebp-8h]
  bool foundfirstnondeletion; // [esp+17h] [ebp-1h]

  CHudCloseCaption::ProcessAsyncWork(this: (CHudCloseCaption *)((char *)this - 56));
  v2 = *(_DWORD *)&this->m_AsyncWork.m_NumAlloced;
  dt = *(float *)(gpGlobals.m_Index + 16);
  c = v2;
  if ( BYTE1(this->m_flGrowTime) != 0 )
  {
    ((void (__thiscall *)(CHudCloseCaption *, int))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[1].WantsHudLayoutEntry)(
      a1: this,
      a2: 1);
    if ( v2 == 0 && HIWORD(this->m_nBgTextureId1) == 0 )
      BYTE1(this->m_flGrowTime) = 0;
  }
  else
  {
    if ( closecaption.m_pParent != nullptr )
      m_nValue = closecaption.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    ((void (__thiscall *)(CHudCloseCaption *, bool))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[1].WantsHudLayoutEntry)(
      a1: this,
      a2: m_nValue != 0);
  }
  v4 = 0;
  if ( v2 >= 4 )
  {
    do
    {
      v5 = *(_DWORD *)(this->m_AsyncWork.m_Memory.m_nGrowSize + 4 * v4);
      v6 = *(float *)(v5 + 20400);
      if ( v6 <= 0.0 )
      {
        v8 = *(float *)(v5 + 20404) - dt;
        if ( v8 < 0.0 )
          v8 = 0.0;
        *(float *)(v5 + 20404) = v8;
      }
      else
      {
        v7 = v6 - dt;
        if ( v7 < 0.0 )
          v7 = 0.0;
        *(float *)(v5 + 20400) = v7;
      }
      v9 = *(_DWORD *)(this->m_AsyncWork.m_Memory.m_nGrowSize + 4 * v4 + 4);
      v10 = *(float *)(v9 + 20400);
      if ( v10 <= 0.0 )
      {
        v12 = *(float *)(v9 + 20404) - dt;
        if ( v12 < 0.0 )
          v12 = 0.0;
        *(float *)(v9 + 20404) = v12;
      }
      else
      {
        v11 = v10 - dt;
        if ( v11 < 0.0 )
          v11 = 0.0;
        *(float *)(v9 + 20400) = v11;
      }
      v13 = *(_DWORD *)(this->m_AsyncWork.m_Memory.m_nGrowSize + 4 * v4 + 8);
      v14 = *(float *)(v13 + 20400);
      if ( v14 <= 0.0 )
      {
        v16 = *(float *)(v13 + 20404) - dt;
        if ( v16 < 0.0 )
          v16 = 0.0;
        *(float *)(v13 + 20404) = v16;
      }
      else
      {
        v15 = v14 - dt;
        if ( v15 < 0.0 )
          v15 = 0.0;
        *(float *)(v13 + 20400) = v15;
      }
      v17 = *(_DWORD *)(this->m_AsyncWork.m_Memory.m_nGrowSize + 4 * v4 + 12);
      v18 = *(float *)(v17 + 20400);
      if ( v18 <= 0.0 )
      {
        v20 = *(float *)(v17 + 20404) - dt;
        if ( v20 < 0.0 )
          v20 = 0.0;
        *(float *)(v17 + 20404) = v20;
      }
      else
      {
        v19 = v18 - dt;
        if ( v19 < 0.0 )
          v19 = 0.0;
        *(float *)(v17 + 20400) = v19;
      }
      v4 += 4;
    }
    while ( v4 < v2 - 3 );
  }
  for ( ; v4 < v2; ++v4 )
  {
    v21 = *(_DWORD *)(this->m_AsyncWork.m_Memory.m_nGrowSize + 4 * v4);
    v22 = *(float *)(v21 + 20400);
    if ( v22 <= 0.0 )
    {
      v24 = *(float *)(v21 + 20404) - dt;
      if ( v24 < 0.0 )
        v24 = 0.0;
      *(float *)(v21 + 20404) = v24;
    }
    else
    {
      v23 = v22 - dt;
      if ( v23 < 0.0 )
        v23 = 0.0;
      *(float *)(v21 + 20400) = v23;
    }
  }
  v25 = 0;
  foundfirstnondeletion = false;
  if ( v2 > 0 )
  {
    do
    {
      v26 = *(CCloseCaptionItem **)(this->m_AsyncWork.m_Memory.m_nGrowSize + 4 * v25);
      if ( v26->m_flPreDisplayTime <= 0.0 )
      {
        if ( v26->m_flTimeToLive <= 0.0 )
        {
          if ( !foundfirstnondeletion )
          {
            CCloseCaptionItem::~CCloseCaptionItem(this: v26);
            C_BaseEntity::operator delete(pMem: v26);
            if ( *(_DWORD *)&this->m_AsyncWork.m_NumAlloced - v25 - 1 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)(this->m_AsyncWork.m_Memory.m_nGrowSize + 4 * v25),
                src: (unsigned __int8 *)(this->m_AsyncWork.m_Memory.m_nGrowSize + 4 * v25 + 4),
                count: 4 * (*(_DWORD *)&this->m_AsyncWork.m_NumAlloced - v25 - 1));
            --*(_DWORD *)&this->m_AsyncWork.m_NumAlloced;
            --v25;
            --c;
          }
        }
        else
        {
          foundfirstnondeletion = true;
        }
      }
      ++v25;
    }
    while ( v25 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100540
// Name: public: void CHudCloseCaption::ProcessCaptionDirect(char const __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::ProcessCaptionDirect(
        CHudCloseCaption *this,
        char *tokenname,
        float duration,
        bool fromplayer)
{
  int v5; // eax
  char token[512]; // [esp+10h] [ebp-200h] BYREF

  this->m_bVisibleDueToDirect = true;
  V_strncpy(pDest: token, pSrc: tokenname, maxLen: 512);
  _V_strstr(s1: token, search: "\\");
  if ( v5 != 0 )
    Hack_FixEscapeChars(str: token);
  CHudCloseCaption::AddAsyncWork(this, tokenstream: token, bIsStream: false, duration, fromplayer, direct: true);
}

//------------------------------------------------------------------------------
// Address: 0x101005C0
// Name: public: void CHudCloseCaption::AddFileToCaptionDictionary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::AddFileToCaptionDictionary(CHudCloseCaption *this, const char *filename)
{
  int v3; // edi
  void *v4; // esp
  const char *i; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  AsyncCaption_t *m_pMemory; // ecx
  int v9; // eax
  AsyncCaption_t *v10; // ecx
  bool v11; // zf
  AsyncCaption_t *v12; // ecx
  AsyncCaption_t *v13; // ebx
  char v14[12]; // [esp+0h] [ebp-114h] BYREF
  char fullpath[260]; // [esp+Ch] [ebp-108h] BYREF
  unsigned int v16; // [esp+110h] [ebp-4h]

  v3 = filesystem->GetSearchPath(this: filesystem, a2: "GAME", a3: true, a4: nullptr, a5: 0);
  v4 = alloca(v3 + 1);
  filesystem->GetSearchPath(this: filesystem, a2: "GAME", a3: true, a4: v14, a5: v3);
  for ( i = strtok(string: v14, control: ";"); i != nullptr; i = strtok(string: nullptr, control: ";") )
  {
    V_snprintf(pDest: fullpath, maxLen: 0x104u, pFormat: "%s%s", i, filename);
    V_FixSlashes(pname: fullpath, separator: 92);
    _V_strlower(start: fullpath);
    m_Size = this->m_AsyncCaptions.m_Size;
    m_nAllocationCount = this->m_AsyncCaptions.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<AsyncCaption_t,int>::Grow(
        this: (CUtlMemory<PanelItem_t,int> *)&this->m_AsyncCaptions,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_AsyncCaptions.m_Size;
    m_pMemory = this->m_AsyncCaptions.m_Memory.m_pMemory;
    v9 = this->m_AsyncCaptions.m_Size - m_Size - 1;
    this->m_AsyncCaptions.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 84 * v9);
    v10 = this->m_AsyncCaptions.m_Memory.m_pMemory;
    v11 = &v10[m_Size] == nullptr;
    v12 = &v10[m_Size];
    v16 = 84 * m_Size;
    if ( !v11 )
      AsyncCaption_t::AsyncCaption_t(this: v12);
    if ( AsyncCaption_t::LoadFromFile(
           this: &this->m_AsyncCaptions.m_Memory.m_pMemory[m_Size],
           a2: (int)this,
           pchFullPath: fullpath) != 0 )
    {
      DevMsg(a1: "Client: added caption file: %s\n", fullpath);
    }
    else
    {
      v13 = &this->m_AsyncCaptions.m_Memory.m_pMemory[v16 / 0x54];
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v13->m_CaptionDirectory);
      CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::~CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>(this: &v13->m_RequestedBlocks);
      if ( this->m_AsyncCaptions.m_Size - m_Size - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&this->m_AsyncCaptions.m_Memory.m_pMemory[v16 / 0x54],
          src: (unsigned __int8 *)&this->m_AsyncCaptions.m_Memory.m_pMemory[v16 / 0x54 + 1],
          count: 84 * (this->m_AsyncCaptions.m_Size - m_Size - 1));
      --this->m_AsyncCaptions.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100770
// Name: private: void CHudCloseCaption::LoadColorMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::LoadColorMap(CHudCloseCaption *this, const char *pFilename)
{
  int v3; // eax
  char colorToken[260]; // [esp+4h] [ebp-34Ch] BYREF
  char tagToken[260]; // [esp+108h] [ebp-248h] BYREF
  characterset_t breakSet; // [esp+20Ch] [ebp-144h] BYREF
  CUtlBuffer colorMapBuffer; // [esp+30Ch] [ebp-44h] BYREF
  CUtlMap<char const *,Color,int>::Node_t search; // [esp+33Ch] [ebp-14h] BYREF
  int b; // [esp+344h] [ebp-Ch] BYREF
  int r; // [esp+348h] [ebp-8h] BYREF
  int g; // [esp+34Ch] [ebp-4h] BYREF
  Color tagColor; // [esp+358h] [ebp+8h]

  CUtlBuffer::CUtlBuffer(this: &colorMapBuffer, growSize: 0, initSize: 0, nFlags: 1u);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pFilename,
         a3: "MOD",
         a4: &colorMapBuffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: (char *)prType);
    while ( CUtlBuffer::ParseToken(
              this: &colorMapBuffer,
              pBreaks: &breakSet,
              pTokenBuf: tagToken,
              nMaxLen: 260,
              bParseComments: 1) > 0 )
    {
      if ( CUtlBuffer::ParseToken(
             this: &colorMapBuffer,
             pBreaks: &breakSet,
             pTokenBuf: colorToken,
             nMaxLen: 260,
             bParseComments: 1) <= 0 )
        break;
      if ( V_strnicmp(s1: colorToken, s2: "<clr:", n: 5) == 0
        && sscanf(string: &colorToken[5], format: "%i,%i,%i", &r, &g, &b) == 3 )
      {
        tagColor._color[1] = g;
        tagColor._color[0] = r;
        tagColor._color[2] = b;
        tagColor._color[3] = -1;
        search.elem = 0;
        search.key = tagToken;
        v3 = CUtlRBTree<CUtlMap<char const *,Color,int>::Node_t,int,CUtlMap<char const *,Color,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int>,int>>::Find(
               this: &this->m_ColorMap.m_Elements.m_Tree,
               &search);
        if ( v3 == -1 )
          v3 = CUtlDict<Color,int>::Insert(this: &this->m_ColorMap, pName: tagToken);
        this->m_ColorMap.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem = tagColor;
      }
    }
  }
  if ( colorMapBuffer.m_Memory.m_nGrowSize >= 0 && colorMapBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: colorMapBuffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10100970
// Name: public: virtual bool CAsyncCaptionResourceManager::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncCaptionResourceManager::Init(CAsyncCaptionResourceManager *this)
{
  _DWORD v2[4]; // [esp+4h] [ebp-10h] BYREF

  v2[0] = 0x10000;
  v2[1] = -1;
  v2[2] = 0;
  v2[3] = 0;
  if ( this->m_pCache == nullptr )
    this->m_pCache = g_pDataCache->AddSection(
                       this: g_pDataCache,
                       a2: &this->CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>,
                       a3: "Captions",
                       a4: v2,
                       a5: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101009C0
// Name: public: virtual void CAsyncCaptionResourceManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncCaptionResourceManager::Shutdown(CAsyncCaptionResourceManager *this)
{
  IDataCacheSection *m_pCache; // esi
  IDataCache *v3; // eax
  IDataCache *v4; // edi
  int v5; // eax
  IDataCache_vtbl *v6; // [esp+8h] [ebp-4h]

  CAsyncCaptionResourceManager::Clear(this);
  m_pCache = this->m_pCache;
  if ( m_pCache != nullptr )
  {
    v3 = m_pCache->GetSharedCache(this: m_pCache);
    v4 = v3;
    v6 = v3->__vftable;
    v5 = ((int (__thiscall *)(IDataCacheSection *, int))m_pCache->GetName)(a1: m_pCache, a2: 1);
    ((void (__thiscall *)(IDataCache *, int))v6->RemoveSection)(a1: v4, a2: v5);
    this->m_pCache = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100A10
// Name: public: virtual CAsyncCaptionResourceManager::~CAsyncCaptionResourceManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncCaptionResourceManager::~CAsyncCaptionResourceManager(CAsyncCaptionResourceManager *this)
{
  IDataCacheSection *m_pCache; // esi
  IDataCache *v3; // eax
  IDataCache *v4; // ebx
  int v5; // eax
  IDataCache_vtbl *v6; // [esp+8h] [ebp-4h]

  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::~CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>(this: &this->m_Db);
  m_pCache = this->m_pCache;
  this->CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>_vtbl *)&CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>::`vftable';
  if ( m_pCache != nullptr )
  {
    v3 = m_pCache->GetSharedCache(this: m_pCache);
    v4 = v3;
    v6 = v3->__vftable;
    v5 = ((int (__thiscall *)(IDataCacheSection *, int))m_pCache->GetName)(a1: m_pCache, a2: 1);
    ((void (__thiscall *)(IDataCache *, int))v6->RemoveSection)(a1: v4, a2: v5);
    this->m_pCache = nullptr;
  }
  this->CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>_vtbl *)&IDataCacheClient::`vftable';
  IGameSystem::~IGameSystem(this);
}

//------------------------------------------------------------------------------
// Address: 0x10100A80
// Name: public: virtual CHudCloseCaption::~CHudCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::~CHudCloseCaption(CHudCloseCaption *this)
{
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudCloseCaption_vtbl *)&CHudCloseCaption::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudCloseCaption::`vftable'{for `vgui::Panel'};
  CUtlRBTree<CHudCloseCaption::CaptionRepeat,int,bool (__cdecl *)(CHudCloseCaption::CaptionRepeat const &,CHudCloseCaption::CaptionRepeat const &),CUtlMemory<UtlRBTreeNode_t<CHudCloseCaption::CaptionRepeat,int>,int>>::RemoveAll(this: &this->m_CloseCaptionRepeats);
  CHudCloseCaption::ClearAsyncWork(this);
  CUtlDict<Color,int>::RemoveAll(this: &this->m_ColorMap);
  CUtlRBTree<CUtlMap<char const *,Color,int>::Node_t,int,CUtlMap<char const *,Color,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,Color,int>::Node_t,int,CUtlMap<char const *,Color,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,Color,int>::Node_t,int>,int>>(this: &this->m_ColorMap.m_Elements.m_Tree);
  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::~CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>(this: &this->m_AsyncCaptions);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Items);
  CUtlRBTree<CHudCloseCaption::CaptionRepeat,int,bool (__cdecl *)(CHudCloseCaption::CaptionRepeat const &,CHudCloseCaption::CaptionRepeat const &),CUtlMemory<UtlRBTreeNode_t<CHudCloseCaption::CaptionRepeat,int>,int>>::~CUtlRBTree<CHudCloseCaption::CaptionRepeat,int,bool (__cdecl *)(CHudCloseCaption::CaptionRepeat const &,CHudCloseCaption::CaptionRepeat const &),CUtlMemory<UtlRBTreeNode_t<CHudCloseCaption::CaptionRepeat,int>,int>>(this: &this->m_CloseCaptionRepeats);
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_AsyncWork);
  if ( this->m_AsyncWork.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_AsyncWork.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AsyncWork.m_Memory.m_pMemory);
      this->m_AsyncWork.m_Memory.m_pMemory = nullptr;
    }
    this->m_AsyncWork.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this: &this->vgui::Panel);
  CHudElement::~CHudElement(this);
}

//------------------------------------------------------------------------------
// Address: 0x10100B30
// Name: public: virtual void CHudCloseCaption::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::LevelShutdown(CHudCloseCaption *this)
{
  void (*Reset)(void); // edx

  Reset = (void (*)(void))this->Reset;
  this->m_bLevelShutDown = true;
  Reset();
  this->m_bLevelShutDown = false;
}

//------------------------------------------------------------------------------
// Address: 0x10100B60
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudCloseCaption::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudCloseCaption::GetMessageMap(CHudCloseCaption *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudCloseCaption::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudCloseCaption::GetMessageMap'::`2'::s_pMap;
  `CHudCloseCaption::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudCloseCaption");
  `CHudCloseCaption::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10100B90
// Name: public: virtual struct PanelAnimationMap __near * CHudCloseCaption::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudCloseCaption::GetAnimMap(CHudCloseCaption *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudCloseCaption");
}

//------------------------------------------------------------------------------
// Address: 0x10100BA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudCloseCaption::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudCloseCaption::GetKBMap(CHudCloseCaption *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudCloseCaption::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudCloseCaption::GetKBMap'::`2'::s_pMap;
  `CHudCloseCaption::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudCloseCaption");
  `CHudCloseCaption::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10100BD0
// Name: public: void CHudCloseCaption::InitCaptionDictionary(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCloseCaption::InitCaptionDictionary(CHudCloseCaption *this, const char *language, float bForce)
{
  const char *v3; // ebx
  CUtlSymbol *p_m_CurrentLanguage; // ecx
  const char *v6; // eax
  double v7; // st7
  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *p_m_AsyncCaptions; // esi
  const char *v9; // eax
  const char *v10; // eax
  int m_Size; // ebx
  int v12; // edi
  int v13; // [esp+8h] [ebp-8h]
  int v14; // [esp+8h] [ebp-8h]

  v3 = language;
  if ( LOBYTE(bForce) != 0
    || (p_m_CurrentLanguage = &this->m_CurrentLanguage, this->m_CurrentLanguage.m_Id == 0xFFFF)
    || (v6 = CUtlSymbol::String(this: p_m_CurrentLanguage), _V_stricmp(s1: v6, s2: language) != 0) )
  {
    if ( language != nullptr || LOBYTE(bForce) == 0 || this->m_CurrentLanguage.m_Id == 0xFFFF )
    {
      CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&bForce + 1, pStr: language);
      this->m_CurrentLanguage.m_Id = HIWORD(bForce);
    }
    else
    {
      v3 = CUtlSymbol::String(this: &this->m_CurrentLanguage);
    }
    bForce = _Plat_FloatTime(a1: v13);
    if ( this->m_AsyncWork.m_ElementCount != 0 )
    {
      while ( 1 )
      {
        CHudCloseCaption::ProcessAsyncWork(this);
        v7 = _Plat_FloatTime(a1: v14);
        if ( v7 - bForce >= 0.5 )
          break;
        if ( this->m_AsyncWork.m_ElementCount == 0 )
          goto LABEL_14;
      }
      DevWarning(
        a1: "Could not finish async caption work after %f seconds of processing before caption dictionary init!\n",
        0.5);
      CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_AsyncWork);
    }
LABEL_14:
    p_m_AsyncCaptions = &this->m_AsyncCaptions;
    CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::RemoveAll(this: &this->m_AsyncCaptions);
    if ( this->m_AsyncCaptions.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_AsyncCaptions->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_AsyncCaptions->m_Memory.m_pMemory);
        p_m_AsyncCaptions->m_Memory.m_pMemory = nullptr;
      }
      this->m_AsyncCaptions.m_Memory.m_nAllocationCount = 0;
    }
    this->m_AsyncCaptions.m_pElements = this->m_AsyncCaptions.m_Memory.m_pMemory;
    CAsyncCaptionResourceManager::Clear(this: &g_AsyncCaptionResourceManager);
    v9 = VarArgs(format: "resource/closecaption_%s.dat", v3);
    CHudCloseCaption::AddFileToCaptionDictionary(this, filename: v9);
    v10 = VarArgs(format: "resource/subtitles_%s.dat", v3);
    CHudCloseCaption::AddFileToCaptionDictionary(this, filename: v10);
    m_Size = this->m_AsyncCaptions.m_Size;
    CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::RemoveAll(this: &g_AsyncCaptionResourceManager.m_Db);
    CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::InsertMultipleBefore(
      this: &g_AsyncCaptionResourceManager.m_Db,
      elem: g_AsyncCaptionResourceManager.m_Db.m_Size,
      num: m_Size);
    if ( m_Size > 0 )
    {
      v12 = 0;
      do
      {
        AsyncCaption_t::operator=(
          this: &g_AsyncCaptionResourceManager.m_Db.m_Memory.m_pMemory[v12],
          rhs: &p_m_AsyncCaptions->m_Memory.m_pMemory[v12]);
        ++v12;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100D60
// Name: void OnCaptionLanguageChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnCaptionLanguageChanged(IConVar *pConVar)
{
  CHud *Hud; // eax
  CHudCloseCaption *Element; // esi
  char fallback[512]; // [esp+0h] [ebp-448h] BYREF
  char fn[512]; // [esp+200h] [ebp-248h] BYREF
  char uilanguage[64]; // [esp+400h] [ebp-48h] BYREF
  ConVarRef var; // [esp+440h] [ebp-8h] BYREF

  if ( g_pVGuiLocalize != nullptr )
  {
    ConVarRef::ConVarRef(this: &var, pConVar);
    V_snprintf(
      pDest: fn,
      maxLen: 0x200u,
      pFormat: "resource/closecaption_%s.txt",
      var.m_pConVarState->m_Value.m_pszString);
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/closecaption_%language%.txt", a3: "GAME", a4: true);
    engine->GetUILanguage(this: engine, a2: uilanguage, a3: 64);
    Hud = GetHud(nSlot: 0);
    Element = (CHudCloseCaption *)CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
    if ( _V_strlen(str: var.m_pConVarState->m_Value.m_pszString) > 0
      && _V_stricmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: uilanguage) != 0 )
    {
      if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: fn, a3: nullptr) )
      {
        g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: fn, a3: "GAME", a4: true);
      }
      else
      {
        V_snprintf(pDest: fallback, maxLen: 0x200u, pFormat: "resource/closecaption_%s.txt", uilanguage);
        _Msg(a1: "%s not found\n", fn);
        _Msg(a1: "%s will be used\n", fallback);
      }
      if ( Element != nullptr )
        CHudCloseCaption::InitCaptionDictionary(
          this: Element,
          language: var.m_pConVarState->m_Value.m_pszString,
          bForce: false);
    }
    else if ( Element != nullptr )
    {
      CHudCloseCaption::InitCaptionDictionary(this: Element, language: uilanguage, bForce: false);
    }
    DevMsg(a1: "cc_lang = %s\n", var.m_pConVarState->m_Value.m_pszString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100F10
// Name: public: CHudCloseCaption::CHudCloseCaption(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudCloseCaption *__thiscall CHudCloseCaption::CHudCloseCaption(CHudCloseCaption *this, const char *pElementName)
{
  UtlLinkedListElem_t<CAsyncCaption *,unsigned short> *m_pMemory; // edx
  ClientModeCSFullscreen *FullscreenClientMode; // eax
  vgui::Panel *v5; // eax
  char uilanguage[64]; // [esp+Ch] [ebp-40h] BYREF
  const char *pElementNamea; // [esp+54h] [ebp+8h]
  const char *pElementNameb; // [esp+54h] [ebp+8h]
  const char *pElementNamec; // [esp+54h] [ebp+8h]

  CHudElement::CHudElement(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudCloseCaption");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudCloseCaption_vtbl *)&CHudCloseCaption::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudCloseCaption::`vftable'{for `vgui::Panel'};
  if ( `CHudCloseCaption::ChainToMap'::`2'::chained == 0 )
  {
    `CHudCloseCaption::ChainToMap'::`2'::chained = 1;
    pElementNamea = (const char *)vgui::FindOrAddPanelMessageMap(className: "CHudCloseCaption");
    *((_DWORD *)pElementNamea + 7) = CHudCloseCaption::GetPanelClassName;
    *((_DWORD *)pElementNamea + 6) = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudCloseCaption::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudCloseCaption::ChainToAnimationMap'::`2'::chained = 1;
    pElementNameb = (const char *)FindOrAddPanelAnimationMap(className: "CHudCloseCaption");
    *((_DWORD *)pElementNameb + 6) = CHudCloseCaption::GetPanelClassName;
    *((_DWORD *)pElementNameb + 5) = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudCloseCaption::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudCloseCaption::KB_ChainToMap'::`2'::chained = 1;
    pElementNamec = (const char *)vgui::FindOrAddPanelKeyBindingMap(className: "CHudCloseCaption");
    *((_DWORD *)pElementNamec + 17) = CHudCloseCaption::GetPanelClassName;
    *((_DWORD *)pElementNamec + 6) = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_AsyncWork.m_Memory.m_pMemory = nullptr;
  this->m_AsyncWork.m_Memory.m_nAllocationCount = 0;
  this->m_AsyncWork.m_Memory.m_nGrowSize = 0;
  this->m_AsyncWork.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_AsyncWork.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_AsyncWork.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_AsyncWork.m_Head = -1;
  this->m_AsyncWork.m_pElements = m_pMemory;
  this->m_AsyncWork.m_NumAlloced = 0;
  this->m_CloseCaptionRepeats.m_LessFunc = (bool (__cdecl *)(const CHudCloseCaption::CaptionRepeat *, const CHudCloseCaption::CaptionRepeat *))lessFunc;
  this->m_CloseCaptionRepeats.m_Elements.m_pMemory = nullptr;
  this->m_CloseCaptionRepeats.m_Elements.m_nAllocationCount = 0;
  this->m_CloseCaptionRepeats.m_Elements.m_nGrowSize = 0;
  this->m_CloseCaptionRepeats.m_Root = -1;
  this->m_CloseCaptionRepeats.m_FirstFree = -1;
  this->m_CloseCaptionRepeats.m_NumElements = 0;
  this->m_CloseCaptionRepeats.m_LastAlloc.index = -1;
  this->m_CloseCaptionRepeats.m_pElements = this->m_CloseCaptionRepeats.m_Elements.m_pMemory;
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  CHudCloseCaption::PanelAnimationVar_m_flBackgroundAlpha::InitVar();
  CHudCloseCaption::PanelAnimationVar_m_flGrowTime::InitVar();
  CHudCloseCaption::PanelAnimationVar_m_flItemHiddenTime::InitVar();
  CHudCloseCaption::PanelAnimationVar_m_flItemFadeInTime::InitVar();
  CHudCloseCaption::PanelAnimationVar_m_flItemFadeOutTime::InitVar();
  CHudCloseCaption::PanelAnimationVar_m_nTopOffset::InitVar();
  this->m_AsyncCaptions.m_Memory.m_pMemory = nullptr;
  this->m_AsyncCaptions.m_Memory.m_nAllocationCount = 0;
  this->m_AsyncCaptions.m_Memory.m_nGrowSize = 0;
  this->m_AsyncCaptions.m_Size = 0;
  this->m_AsyncCaptions.m_pElements = nullptr;
  this->m_bPaintDebugInfo = false;
  this->m_CurrentLanguage.m_Id = -1;
  this->m_ColorMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_ColorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_ColorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_ColorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_ColorMap.m_Elements.m_Tree.m_Root = -1;
  this->m_ColorMap.m_Elements.m_Tree.m_NumElements = 0;
  this->m_ColorMap.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_ColorMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_ColorMap.m_Elements.m_Tree.m_pElements = this->m_ColorMap.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_ColorMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_ColorMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  FullscreenClientMode = GetFullscreenClientMode();
  v5 = FullscreenClientMode->GetViewport(this: FullscreenClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v5);
  vgui::Panel::SetProportional(this: &this->vgui::Panel, state: true);
  this->m_flGoalAlpha = 1.0;
  this->m_flCurrentAlpha = 1.0;
  this->m_nGoalHeight = 0;
  this->m_nCurrentHeight = 0;
  this->m_flGoalHeightStartTime = 0.0;
  this->m_flGoalHeightFinishTime = 0.0;
  *(_WORD *)&this->m_bLocked = 0;
  vgui::Panel::SetPaintBorderEnabled(this: &this->vgui::Panel, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this: &this->vgui::Panel, state: false);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/closecaption_%language%.txt", a3: "GAME", a4: true);
  CUserMessages::HookMessage(this: usermessages, name: "CloseCaption", hook: __MsgFunc_CHudCloseCaption_CloseCaption);
  CUserMessages::HookMessage(
    this: usermessages,
    name: "CloseCaptionDirect",
    hook: __MsgFunc_CHudCloseCaption_CloseCaptionDirect);
  engine->GetUILanguage(this: engine, a2: uilanguage, a3: 64);
  if ( _V_stricmp(s1: uilanguage, s2: "english") != 0 )
    ConVar::SetValue(this: (ConVar *)&english.IConVar, value: 0);
  else
    ConVar::SetValue(this: (ConVar *)&english.IConVar, value: 1);
  CHudCloseCaption::InitCaptionDictionary(this, language: uilanguage, bForce: 0.0);
  CHudCloseCaption::LoadColorMap(this, pFilename: "resource/captioning_colors.txt");
  *(_WORD *)&this->m_bLevelShutDown = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10101290
// Name: Create_CHudCloseCaption
// Source: json
//------------------------------------------------------------------------------
CHudCloseCaption *__cdecl Create_CHudCloseCaption()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 640);
  memset(dst: v0, value: 0, count: 0x280u);
  if ( v0 != nullptr )
    return CHudCloseCaption::CHudCloseCaption(this: (CHudCloseCaption *)v0, pElementName: "CHudCloseCaption");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10416BB0
// Name: _dynamic_initializer_for__closecaption__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__closecaption__()
{
  ConVar::ConVar(
    this: &closecaption,
    pName: "closecaption",
    pDefaultValue: "0",
    flags: 16777856,
    pHelpString: "Enable close captioning.");
  return atexit(func: dynamic_atexit_destructor_for__closecaption__);
}

//------------------------------------------------------------------------------
// Address: 0x10431B80
// Name: _dynamic_atexit_destructor_for__closecaption__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__closecaption__()
{
  ConVar::~ConVar(this: &closecaption);
}

//------------------------------------------------------------------------------
// Address: 0x10416BE0
// Name: _dynamic_initializer_for__cc_linger_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_linger_time__()
{
  ConVar::ConVar(
    this: &cc_linger_time,
    pName: "cc_linger_time",
    pDefaultValue: "1.0",
    flags: 128,
    pHelpString: "Close caption linger time.");
  return atexit(func: dynamic_atexit_destructor_for__cc_linger_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10416C10
// Name: _dynamic_initializer_for__cc_predisplay_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_predisplay_time__()
{
  ConVar::ConVar(
    this: &cc_predisplay_time,
    pName: "cc_predisplay_time",
    pDefaultValue: "0.25",
    flags: 128,
    pHelpString: "Close caption delay before showing caption.");
  return atexit(func: dynamic_atexit_destructor_for__cc_predisplay_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10416C40
// Name: _dynamic_initializer_for__cc_captiontrace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_captiontrace__()
{
  ConVar::ConVar(
    this: &cc_captiontrace,
    pName: "cc_captiontrace",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show missing closecaptions (0 = no, 1 = devconsole, 2 = show in hud)");
  return atexit(func: dynamic_atexit_destructor_for__cc_captiontrace__);
}

//------------------------------------------------------------------------------
// Address: 0x10416C70
// Name: _dynamic_initializer_for__cc_subtitles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_subtitles__()
{
  ConVar::ConVar(
    this: &cc_subtitles,
    pName: "cc_subtitles",
    pDefaultValue: "0",
    flags: 16777344,
    pHelpString: "If set, don't show sound effect captions, just voice overs (i.e., won't help hearing impaired players).");
  return atexit(func: dynamic_atexit_destructor_for__cc_subtitles__);
}

//------------------------------------------------------------------------------
// Address: 0x10416CA0
// Name: _dynamic_initializer_for__english__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__english__()
{
  ConVar::ConVar(
    this: &english,
    pName: "english",
    pDefaultValue: "1",
    flags: 512,
    pHelpString: "If set to 1, running the english language set of assets.");
  return atexit(func: dynamic_atexit_destructor_for__english__);
}

//------------------------------------------------------------------------------
// Address: 0x10416CD0
// Name: _dynamic_initializer_for__g_AsyncCaptionResourceManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AsyncCaptionResourceManager__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_AsyncCaptionResourceManager, name: "CAsyncCaptionResourceManager");
  g_AsyncCaptionResourceManager.m_pCache = nullptr;
  g_AsyncCaptionResourceManager.CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CAsyncCaptionResourceManager_vtbl *)&CAsyncCaptionResourceManager::`vftable'{for `CAutoGameSystem'};
  g_AsyncCaptionResourceManager.CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>_vtbl *)&CAsyncCaptionResourceManager::`vftable'{for `CManagedDataCacheClient<AsyncCaptionData_t,asynccaptionparams_t,AsyncCaptionData_t *>'};
  g_AsyncCaptionResourceManager.m_Db.m_Memory.m_pMemory = nullptr;
  g_AsyncCaptionResourceManager.m_Db.m_Memory.m_nAllocationCount = 0;
  g_AsyncCaptionResourceManager.m_Db.m_Memory.m_nGrowSize = 0;
  g_AsyncCaptionResourceManager.m_Db.m_Size = 0;
  g_AsyncCaptionResourceManager.m_Db.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_AsyncCaptionResourceManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10416D20
// Name: _dynamic_initializer_for__g_CHudCloseCaption_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudCloseCaption_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudCloseCaption_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudCloseCaption,
           depth: 50,
           flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10416D40
// Name: _dynamic_initializer_for__cc_minvisibleitems__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_minvisibleitems__()
{
  ConVar::ConVar(
    this: &cc_minvisibleitems,
    pName: "cc_minvisibleitems",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Minimum number of caption items to show.");
  return atexit(func: dynamic_atexit_destructor_for__cc_minvisibleitems__);
}

//------------------------------------------------------------------------------
// Address: 0x10416D70
// Name: _dynamic_initializer_for__cc_sentencecaptionnorepeat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_sentencecaptionnorepeat__()
{
  ConVar::ConVar(
    this: &cc_sentencecaptionnorepeat,
    pName: "cc_sentencecaptionnorepeat",
    pDefaultValue: "4",
    flags: 0,
    pHelpString: "How often a sentence can repeat.");
  return atexit(func: dynamic_atexit_destructor_for__cc_sentencecaptionnorepeat__);
}

//------------------------------------------------------------------------------
// Address: 0x10416DA0
// Name: _dynamic_initializer_for__cc_emit_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_emit_command__()
{
  ConCommand::ConCommand(
    this: &cc_emit_command,
    pName: "cc_emit",
    callback: (void (__cdecl *)())cc_emit,
    pHelpString: "Emits a closed caption",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))EmitCaptionCompletion);
  return atexit(func: dynamic_atexit_destructor_for__cc_emit_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10416DD0
// Name: _dynamic_initializer_for__cc_random_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_random_command__()
{
  ConCommand::ConCommand(
    this: &cc_random_command,
    pName: "cc_random",
    callback: (void (__cdecl *)())cc_random,
    pHelpString: "Emits a random caption",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_random_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10416E00
// Name: _dynamic_initializer_for__cc_flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_flush_command__()
{
  ConCommand::ConCommand(
    this: &cc_flush_command,
    pName: "cc_flush",
    callback: cc_flush,
    pHelpString: "Flushes async'd captions.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_flush_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10416E30
// Name: _dynamic_initializer_for__cc_showblocks_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_showblocks_command__()
{
  ConCommand::ConCommand(
    this: &cc_showblocks_command,
    pName: "cc_showblocks",
    callback: cc_showblocks,
    pHelpString: "Toggles showing which blocks are pending/loaded async.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_showblocks_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10416E60
// Name: _dynamic_initializer_for__cc_lang__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_lang__()
{
  ConVar::ConVar(
    this: &cc_lang,
    pName: "cc_lang",
    pDefaultValue: prType,
    flags: 128,
    pHelpString: "Current close caption language (emtpy = use game UI language)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnCaptionLanguageChanged);
  return atexit(func: dynamic_atexit_destructor_for__cc_lang__);
}

//------------------------------------------------------------------------------
// Address: 0x10416E90
// Name: _dynamic_initializer_for__cc_findsound_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_findsound_command__()
{
  ConCommand::ConCommand(
    this: &cc_findsound_command,
    pName: "cc_findsound",
    callback: (void (__cdecl *)())cc_findsound,
    pHelpString: "Searches for soundname which emits specified text.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_findsound_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10416EC0
// Name: _dynamic_initializer_for__g_CHudCrosshair_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudCrosshair_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudCrosshair_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudCrosshair,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10416EE0
// Name: _dynamic_initializer_for__g_CHudFilmDemo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudFilmDemo_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudFilmDemo_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudFilmDemo,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10416F00
// Name: _dynamic_initializer_for__g_CHudHDRDemo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudHDRDemo_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudHDRDemo_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudHDRDemo,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10416F20
// Name: _dynamic_initializer_for__mat_show_ab_hdr_hudelement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_show_ab_hdr_hudelement__()
{
  ConVar::ConVar(
    this: &mat_show_ab_hdr_hudelement,
    pName: "mat_show_ab_hdr_hudelement",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "HDR Demo HUD Element toggle.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))mat_show_ab_hdr_hudelement_changed);
  return atexit(func: dynamic_atexit_destructor_for__mat_show_ab_hdr_hudelement__);
}

//------------------------------------------------------------------------------
// Address: 0x10416F50
// Name: _dynamic_initializer_for__g_CHudHintDisplay_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudHintDisplay_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudHintDisplay_Helper,
           pfnCreate: Create_CHudHintDisplay,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10416F70
// Name: _dynamic_initializer_for__sv_hudhint_sound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_hudhint_sound__()
{
  ConVar::ConVar(this: &sv_hudhint_sound, pName: "sv_hudhint_sound", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__sv_hudhint_sound__);
}

//------------------------------------------------------------------------------
// Address: 0x10416FA0
// Name: _dynamic_initializer_for__g_CHudHintKeyDisplay_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudHintKeyDisplay_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudHintKeyDisplay_Helper,
           pfnCreate: Create_CHudHintKeyDisplay,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10416FC0
// Name: _dynamic_initializer_for__gLCD__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gLCD__()
{
  CLCD::CLCD(this: &gLCD);
  return atexit(func: dynamic_atexit_destructor_for__gLCD__);
}

//------------------------------------------------------------------------------
// Address: 0x10417000
// Name: _dynamic_initializer_for__g15_reload_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g15_reload_command__()
{
  ConCommand::ConCommand(
    this: &g15_reload_command,
    pName: "g15_reload",
    callback: g15_reload,
    pHelpString: "Reloads the Logitech G-15 Keyboard configs.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__g15_reload_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10417030
// Name: _dynamic_initializer_for__g15_dumpplayer_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g15_dumpplayer_command__()
{
  ConCommand::ConCommand(
    this: &g15_dumpplayer_command,
    pName: "g15_dumpplayer",
    callback: g15_dumpplayer,
    pHelpString: "Spew player data.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__g15_dumpplayer_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10417060
// Name: _dynamic_initializer_for__g15_update_msec__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g15_update_msec__()
{
  ConVar::ConVar(
    this: &g15_update_msec,
    pName: "g15_update_msec",
    pDefaultValue: "250",
    flags: 128,
    pHelpString: "Logitech G-15 Keyboard update interval.");
  return atexit(func: dynamic_atexit_destructor_for__g15_update_msec__);
}

//------------------------------------------------------------------------------
// Address: 0x10417090
// Name: _dynamic_initializer_for__cl_dumpplayer_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_dumpplayer_command__()
{
  ConCommand::ConCommand(
    this: &cl_dumpplayer_command,
    pName: "cl_dumpplayer",
    callback: (void (__cdecl *)())cl_dumpplayer,
    pHelpString: "Dumps info about a player",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_dumpplayer_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10431B90
// Name: _dynamic_atexit_destructor_for__cc_linger_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_linger_time__()
{
  ConVar::~ConVar(this: &cc_linger_time);
}

//------------------------------------------------------------------------------
// Address: 0x10431BA0
// Name: _dynamic_atexit_destructor_for__cc_predisplay_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_predisplay_time__()
{
  ConVar::~ConVar(this: &cc_predisplay_time);
}

//------------------------------------------------------------------------------
// Address: 0x10431BB0
// Name: _dynamic_atexit_destructor_for__cc_captiontrace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_captiontrace__()
{
  ConVar::~ConVar(this: &cc_captiontrace);
}

//------------------------------------------------------------------------------
// Address: 0x10431BC0
// Name: _dynamic_atexit_destructor_for__cc_subtitles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_subtitles__()
{
  ConVar::~ConVar(this: &cc_subtitles);
}

//------------------------------------------------------------------------------
// Address: 0x10431BD0
// Name: _dynamic_atexit_destructor_for__english__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__english__()
{
  ConVar::~ConVar(this: &english);
}

//------------------------------------------------------------------------------
// Address: 0x10431BE0
// Name: _dynamic_atexit_destructor_for__cc_minvisibleitems__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_minvisibleitems__()
{
  ConVar::~ConVar(this: &cc_minvisibleitems);
}

//------------------------------------------------------------------------------
// Address: 0x10431BF0
// Name: _dynamic_atexit_destructor_for__cc_sentencecaptionnorepeat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_sentencecaptionnorepeat__()
{
  ConVar::~ConVar(this: &cc_sentencecaptionnorepeat);
}

//------------------------------------------------------------------------------
// Address: 0x10431C00
// Name: _dynamic_atexit_destructor_for__cc_emit_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_emit_command__()
{
  ConCommand::~ConCommand(this: &cc_emit_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431C10
// Name: _dynamic_atexit_destructor_for__cc_random_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_random_command__()
{
  ConCommand::~ConCommand(this: &cc_random_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431C20
// Name: _dynamic_atexit_destructor_for__cc_flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_flush_command__()
{
  ConCommand::~ConCommand(this: &cc_flush_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431C30
// Name: _dynamic_atexit_destructor_for__cc_showblocks_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_showblocks_command__()
{
  ConCommand::~ConCommand(this: &cc_showblocks_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431C40
// Name: _dynamic_atexit_destructor_for__cc_lang__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_lang__()
{
  ConVar::~ConVar(this: &cc_lang);
}

//------------------------------------------------------------------------------
// Address: 0x10431C50
// Name: _dynamic_atexit_destructor_for__cc_findsound_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_findsound_command__()
{
  ConCommand::~ConCommand(this: &cc_findsound_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431C60
// Name: _dynamic_atexit_destructor_for__g_AsyncCaptionResourceManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AsyncCaptionResourceManager__()
{
  CAsyncCaptionResourceManager::~CAsyncCaptionResourceManager(this: &g_AsyncCaptionResourceManager);
}

//------------------------------------------------------------------------------
// Address: 0x10431C70
// Name: _dynamic_atexit_destructor_for__mat_show_ab_hdr_hudelement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_show_ab_hdr_hudelement__()
{
  ConVar::~ConVar(this: &mat_show_ab_hdr_hudelement);
}

//------------------------------------------------------------------------------
// Address: 0x10431C80
// Name: _dynamic_atexit_destructor_for__sv_hudhint_sound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_hudhint_sound__()
{
  ConVar::~ConVar(this: &sv_hudhint_sound);
}

//------------------------------------------------------------------------------
// Address: 0x10431C90
// Name: _dynamic_atexit_destructor_for__g15_reload_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g15_reload_command__()
{
  ConCommand::~ConCommand(this: &g15_reload_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431CA0
// Name: _dynamic_atexit_destructor_for__g15_dumpplayer_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g15_dumpplayer_command__()
{
  ConCommand::~ConCommand(this: &g15_dumpplayer_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431CB0
// Name: _dynamic_atexit_destructor_for__g15_update_msec__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g15_update_msec__()
{
  ConVar::~ConVar(this: &g15_update_msec);
}

//------------------------------------------------------------------------------
// Address: 0x10431CC0
// Name: _dynamic_atexit_destructor_for__cl_dumpplayer_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_dumpplayer_command__()
{
  ConCommand::~ConCommand(this: &cl_dumpplayer_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431CD0
// Name: _dynamic_atexit_destructor_for__gLCD__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gLCD__()
{
  CLCD::~CLCD(this: &gLCD);
}
