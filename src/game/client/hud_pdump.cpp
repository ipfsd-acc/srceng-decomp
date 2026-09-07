// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_pdump.cpp
// Functions: 36
// ============================================================

#include "game\client\hud_pdump.h"

//------------------------------------------------------------------------------
// Address: 0x1003DF40
// Name: public: int CUtlSortVector<class C_BaseEntity __near *,class CEntIndexLessFunc>::Find(class C_BaseEntity __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc>::Find(
        CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc> *this,
        C_BaseEntity *const *src)
{
  CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc> *v2; // edi
  int v3; // esi
  int v5; // esi
  int v6; // edi
  int v7; // eax
  C_BaseEntity **v8; // edi
  int v9; // ebx
  int v10; // eax
  int start; // [esp+10h] [ebp-8h]
  int end; // [esp+14h] [ebp-4h]

  v2 = this;
  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = v2->m_Size - 1;
  start = 0;
  end = v3;
  if ( v3 < 0 )
    return -1;
  while ( 1 )
  {
    v5 = (start + v3) >> 1;
    v6 = v2->m_Memory.m_pMemory[v5]->entindex(this: &v2->m_Memory.m_pMemory[v5]->IClientNetworkable);
    v7 = (*src)->entindex(this: &(*src)->IClientNetworkable);
    if ( v6 == -1 )
      v6 = 2048;
    if ( v7 == -1 )
      v7 = 2048;
    if ( v6 < v7 )
    {
      start = v5 + 1;
      goto LABEL_22;
    }
    v8 = &this->m_Memory.m_pMemory[v5];
    v9 = (*src)->entindex(this: &(*src)->IClientNetworkable);
    v10 = (*v8)->entindex(this: &(*v8)->IClientNetworkable);
    if ( v9 == -1 )
      v9 = 2048;
    if ( v10 == -1 )
      v10 = 2048;
    if ( v9 >= v10 )
      return v5;
    end = v5 - 1;
LABEL_22:
    if ( start > end )
      return -1;
    v2 = this;
    v3 = end;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E220
// Name: public: int CUtlSortVector<class C_BaseEntity __near *,class CEntIndexLessFunc>::FindLessOrEqual(class C_BaseEntity __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc>::FindLessOrEqual(
        CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc> *this,
        C_BaseEntity *const *src)
{
  CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc> *v2; // edi
  int result; // eax
  int v4; // esi
  int v5; // edi
  int v6; // eax
  C_BaseEntity **v7; // edi
  int v8; // ebx
  int v9; // eax
  int start; // [esp+10h] [ebp-8h]
  int end; // [esp+14h] [ebp-4h]

  v2 = this;
  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 277);
  }
  result = v2->m_Size - 1;
  start = 0;
  end = result;
  if ( result >= 0 )
  {
    while ( 1 )
    {
      v4 = (result + start) >> 1;
      v5 = v2->m_Memory.m_pMemory[v4]->entindex(this: &v2->m_Memory.m_pMemory[v4]->IClientNetworkable);
      v6 = (*src)->entindex(this: &(*src)->IClientNetworkable);
      if ( v5 == -1 )
        v5 = 2048;
      if ( v6 == -1 )
        v6 = 2048;
      if ( v5 >= v6 )
      {
        v7 = &this->m_Memory.m_pMemory[v4];
        v8 = (*src)->entindex(this: &(*src)->IClientNetworkable);
        v9 = (*v7)->entindex(this: &(*v7)->IClientNetworkable);
        if ( v8 == -1 )
          v8 = 2048;
        if ( v9 == -1 )
          v9 = 2048;
        if ( v8 >= v9 )
          return v4;
        end = v4 - 1;
      }
      else
      {
        start = v4 + 1;
      }
      result = end;
      if ( start > end )
        return result;
      v2 = this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003F7F0
// Name: public: int CUtlSortVector<class C_BaseEntity __near *,class CEntIndexLessFunc>::Insert(class C_BaseEntity __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc>::Insert(
        CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc> *this,
        C_BaseEntity *const *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  C_BaseEntity **m_pMemory; // ecx
  int v8; // eax
  C_BaseEntity **v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100BF620
// Name: protected: static int CUtlSortVector<struct CaptionLookup_t,class CCaptionLookupLess>::CompareHelper(void __near *,struct CaptionLookup_t const __near *,struct CaptionLookup_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CaptionLookup_t,CCaptionLookupLess>::CompareHelper(
        void *context,
        const CaptionLookup_t *lhs,
        const CaptionLookup_t *rhs)
{
  if ( rhs->hash <= lhs->hash )
    return rhs->hash < lhs->hash;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100F9230
// Name: public: int CUtlSortVector<struct CaptionLookup_t,class CCaptionLookupLess>::Find(struct CaptionLookup_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CaptionLookup_t,CCaptionLookupLess>::Find(
        CUtlSortVector<CaptionLookup_t,CCaptionLookupLess> *this,
        const CaptionLookup_t *src)
{
  int v3; // esi
  int v4; // ecx
  CaptionLookup_t *m_pMemory; // ebx
  unsigned int hash; // edi
  int result; // eax
  unsigned int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    hash = src->hash;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].hash;
      if ( hash <= v8 )
      {
        if ( hash >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100FE1D0
// Name: public: class CUtlSortVector<struct CaptionLookup_t,class CCaptionLookupLess> __near & CUtlSortVector<struct CaptionLookup_t,class CCaptionLookupLess>::operator=(class CUtlSortVector<struct CaptionLookup_t,class CCaptionLookupLess> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlSortVector<CaptionLookup_t,CCaptionLookupLess> *__thiscall CUtlSortVector<CaptionLookup_t,CCaptionLookupLess>::operator=(
        CUtlSortVector<CaptionLookup_t,CCaptionLookupLess> *this,
        const CUtlSortVector<CaptionLookup_t,CCaptionLookupLess> *__that)
{
  int m_Size; // ebx
  int v4; // edx
  CaptionLookup_t *v5; // eoff
  CaptionLookup_t *m_pMemory; // ecx

  m_Size = __that->m_Size;
  this->m_Size = 0;
  CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::InsertMultipleBefore(
    (CUtlVector<Vector,CUtlMemory<Vector,int> > *)this,
    elem: 0,
    num: m_Size);
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = &__that->m_Memory.m_pMemory[v4];
      m_pMemory = this->m_Memory.m_pMemory;
      *(_QWORD *)&m_pMemory[v4].hash = *(_QWORD *)&v5->hash;
      *(_DWORD *)&m_pMemory[v4++].offset = *(_DWORD *)&v5->offset;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  this->m_pLessContext = __that->m_pLessContext;
  this->m_bNeedsSort = __that->m_bNeedsSort;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010E590
// Name: public: static char const __near * CPDumpPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPDumpPanel::GetPanelClassName()
{
  return "CPDumpPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1010E5A0
// Name: private: static void __near * CPDumpPanel::GetVar_m_FontSmall(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
Color *__cdecl CPDumpPanel::GetVar_m_FontSmall(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_clrDragFrame;
  else
    return (Color *)432;
}

//------------------------------------------------------------------------------
// Address: 0x1010E5C0
// Name: private: static void __near * CPDumpPanel::GetVar_m_FontMedium(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip **__cdecl CPDumpPanel::GetVar_m_FontMedium(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_pTooltips;
  else
    return (vgui::Tooltip **)440;
}

//------------------------------------------------------------------------------
// Address: 0x1010E5E0
// Name: private: static void __near * CPDumpPanel::GetVar_m_FontBig(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CPDumpPanel::GetVar_m_FontBig(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_lLastDoublePressTime;
  else
    return (void *)448;
}

//------------------------------------------------------------------------------
// Address: 0x1010E600
// Name: class CPDumpPanel __near * GetPDumpPanel(void)
// Source: json
//------------------------------------------------------------------------------
CPDumpPanel *__cdecl GetPDumpPanel()
{
  CHud *Hud; // eax

  Hud = GetHud(nSlot: 0);
  return (CPDumpPanel *)CHud::FindElement(this: Hud, pName: "CPDumpPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1010E620
// Name: public: virtual void CPDumpPanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPDumpPanel::ApplySettings(
        CPDumpPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *inResourceData)
{
  ((void (__thiscall *)(CPDumpPanel *, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[7].Reset)(
    a1: this,
    a2: 0);
  vgui::Panel::ApplySettings((vgui::Panel *)this, a2, a3, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x1010E650
// Name: public: virtual void CPDumpPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPDumpPanel::ApplySchemeSettings(CPDumpPanel *this, vgui::IScheme *pScheme)
{
  int screenWide; // [esp+4h] [ebp-8h] BYREF
  int screenTall; // [esp+8h] [ebp-4h] BYREF

  ((void (__thiscall *)(CPDumpPanel *, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[7].Reset)(
    a1: this,
    a2: 0);
  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, (int)pScheme);
  ((void (__thiscall *)(CPDumpPanel *, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].OnSplitScreenStateChanged)(
    a1: this,
    a2: 0);
  VGui_GetTrueScreenSize(w: &screenWide, h: &screenTall);
  vgui::Panel::SetBounds((vgui::Panel *)this, x: 0, y: 0, wide: screenWide, tall: screenTall);
  vgui::Panel::SetZPos((vgui::Panel *)this, z: 100);
}

//------------------------------------------------------------------------------
// Address: 0x1010E6C0
// Name: GetButtonFieldValue
// Source: json
//------------------------------------------------------------------------------
char *__usercall GetButtonFieldValue@<eax>(const char *value@<eax>, char *buf@<edi>, unsigned int bufsize)
{
  char *v4; // eax
  char v6; // al
  int v7; // ebx
  unsigned int i; // esi
  int bits; // [esp+4h] [ebp-4h]

  *buf = 0;
  v4 = _V_strstr(s1: value, search: "(");
  if ( v4 == nullptr )
    return (char *)value;
  bits = V_atoi(str: v4 + 1);
  v6 = 1;
  v7 = 1;
  for ( i = 0; i < 26; ++i )
  {
    if ( (v7 & bits) != 0 )
    {
      if ( v6 == 0 )
        V_strncat(pDest: buf, pSrc: ",", destBufferSize: bufsize, max_chars_to_copy: -1);
      V_strncat(pDest: buf, pSrc: g_ButtonNames[i].pchName, destBufferSize: bufsize, max_chars_to_copy: -1);
      v6 = 0;
    }
    v7 = __ROL4__(v7, 1);
  }
  _V_strlower(start: buf);
  return buf;
}

//------------------------------------------------------------------------------
// Address: 0x1010E760
// Name: CleanupZeros
// Source: json
//------------------------------------------------------------------------------
char *__usercall CleanupZeros@<eax>(char *value@<edx>, char *buf@<eax>)
{
  char v2; // cl
  char *i; // esi
  const char *v4; // edi
  char j; // cl

  v2 = *value;
  for ( i = buf; *value != 0; v2 = *value )
  {
    if ( v2 == 46 )
    {
      v4 = ++value;
      for ( j = *value; j != 0; j = *++value )
      {
        if ( j != 48 )
          break;
      }
      if ( *value != 32 && *value != 41 )
      {
        *i++ = 46;
        value = (char *)v4;
      }
    }
    else
    {
      *i++ = v2;
      ++value;
    }
  }
  *i = 0;
  return buf;
}

//------------------------------------------------------------------------------
// Address: 0x1010E7C0
// Name: private: void CPDumpPanel::PredictionDumpColor(bool,bool,bool,bool,bool,bool,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPDumpPanel::PredictionDumpColor(
        CPDumpPanel *this,
        bool legend,
        bool predictable,
        bool networked,
        bool errorchecked,
        bool differs,
        bool withintolerance,
        int *r,
        int *g,
        int *b,
        int *a)
{
  if ( legend || predictable )
  {
    *r = 255;
    *g = 255;
    *b = 255;
    *a = 255;
    if ( networked )
    {
      if ( errorchecked )
      {
        *r = 180;
        *g = 180;
        *b = 225;
      }
      else
      {
        *r = 150;
        *g = 180;
        *b = 150;
      }
    }
    if ( differs )
    {
      if ( withintolerance )
      {
        *r = 255;
        *g = 255;
        *b = 0;
        *a = 255;
      }
      else
      {
        if ( networked )
        {
          *r = 255;
          *g = 0;
          *b = 0;
        }
        else
        {
          *r = 180;
          *g = 180;
          *b = 100;
        }
        *a = 255;
      }
    }
  }
  else
  {
    *r = 150;
    *g = 180;
    *b = 150;
    *a = 255;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E8C0
// Name: protected: static int CUtlSortVector<struct CPDumpPanel::DumpInfo,class CPDumpPanel::DumpInfo::CDumpInfoLess>::CompareHelper(void __near *,struct CPDumpPanel::DumpInfo const __near *,struct CPDumpPanel::DumpInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CPDumpPanel::DumpInfo,CPDumpPanel::DumpInfo::CDumpInfoLess>::CompareHelper(
        void *context,
        const CPDumpPanel::DumpInfo *lhs,
        const CPDumpPanel::DumpInfo *rhs)
{
  int v3; // eax
  int v5; // eax

  v3 = _V_stricmp(s1: lhs->classname, s2: rhs->classname);
  if ( v3 < 0 || v3 <= 0 && lhs->index < rhs->index )
    return -1;
  v5 = _V_stricmp(s1: rhs->classname, s2: lhs->classname);
  return v5 < 0 || v5 <= 0 && rhs->index < lhs->index;
}

//------------------------------------------------------------------------------
// Address: 0x1010E930
// Name: public: virtual bool CPDumpPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPDumpPanel::ShouldDraw(CPDumpPanel *this)
{
  if ( this->m_DumpEntityInfo.m_Size != 0 )
    return CHudElement::ShouldDraw(this);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010E950
// Name: public: void CUtlMemory<struct CPDumpPanel::DumpInfo,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPDumpPanel::DumpInfo,int>::Grow(CUtlMemory<CPDumpPanel::DumpInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CPDumpPanel::DumpInfo *m_pMemory; // edx
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
    v7 = 264 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CPDumpPanel::DumpInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CPDumpPanel::DumpInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E9F0
// Name: public: void CPDumpPanel::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPDumpPanel::Clear(CPDumpPanel *this)
{
  this->m_DumpEntityInfo.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010EA00
// Name: public: virtual void CPDumpPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPDumpPanel::Paint(CPDumpPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  unsigned int v4; // ecx
  C_BaseEntity *m_pEntity; // ecx
  int v6; // eax
  int v7; // ecx
  int i; // eax
  int (__thiscall *GetFontTall)(vgui::ISurface *, unsigned int); // edx
  int v10; // edi
  int (__thiscall *v11)(vgui::ISurface *, unsigned int); // eax
  int v12; // eax
  int (__thiscall *v13)(vgui::ISurface *, unsigned int); // edx
  int v14; // ebx
  char *v15; // eax
  bool v16; // zf
  type_info *v17; // eax
  void (__thiscall *DrawSetTextColor)(vgui::ISurface *, Color); // edx
  int v19; // eax
  const char *v20; // edi
  int v21; // ebx
  void (__thiscall *v22)(vgui::ISurface *, Color); // eax
  void (__thiscall *v23)(vgui::ISurface *, Color); // eax
  int v24; // ebx
  int v25; // esi
  void (__thiscall *v26)(vgui::ISurface *, Color); // eax
  void (__thiscall *v27)(vgui::ISurface *, Color); // eax
  int v28; // esi
  void (__thiscall *v29)(vgui::ISurface *, Color); // eax
  int v30; // esi
  void (__thiscall *v31)(vgui::ISurface *, Color); // eax
  int v32; // esi
  void (__thiscall *v33)(vgui::ISurface *, Color); // eax
  int v34; // esi
  void (__thiscall *v35)(vgui::ISurface *, Color); // eax
  const char *v36; // [esp-Ch] [ebp-B24h]
  const char *v37; // [esp-8h] [ebp-B20h]
  vgui::CSizerBase *m_pSizer; // [esp-4h] [ebp-B1Ch]
  const char *v39; // [esp-4h] [ebp-B1Ch]
  wchar_t szconverted[1024]; // [esp+4h] [ebp-B14h] BYREF
  char currentclass[128]; // [esp+804h] [ebp-314h] BYREF
  char sz[512]; // [esp+884h] [ebp-294h] BYREF
  char classprefix[32]; // [esp+A84h] [ebp-94h] BYREF
  char classextra[32]; // [esp+AA4h] [ebp-74h] BYREF
  int textSizeTall; // [esp+AC4h] [ebp-54h] BYREF
  int x[5]; // [esp+AC8h] [ebp-50h]
  BOOL bPredictable; // [esp+ADCh] [ebp-3Ch]
  int fonttallMedium; // [esp+AE0h] [ebp-38h]
  int textSizeWide; // [esp+AE4h] [ebp-34h] BYREF
  int fonttall; // [esp+AE8h] [ebp-30h]
  int a; // [esp+AECh] [ebp-2Ch] BYREF
  int g; // [esp+AF0h] [ebp-28h] BYREF
  int b; // [esp+AF4h] [ebp-24h] BYREF
  int r; // [esp+AF8h] [ebp-20h] BYREF
  int c; // [esp+AFCh] [ebp-1Ch]
  int fonttallBig; // [esp+B00h] [ebp-18h]
  int v57; // [esp+B04h] [ebp-14h]
  const char *classname; // [esp+B08h] [ebp-10h]
  C_BaseEntity *v59; // [esp+B0Ch] [ebp-Ch]
  int v60; // [esp+B10h] [ebp-8h]
  int col; // [esp+B14h] [ebp-4h]

  v4 = *(_DWORD *)&this->m_m_nBgTextureId3_register;
  if ( v4 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == HIWORD(v4)
    && (m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity,
        v59 = m_pEntity,
        m_pEntity != nullptr) )
  {
    LOBYTE(bPredictable) = C_BaseEntity::GetPredictable(this: m_pEntity);
    x[0] = 20;
    v6 = vgui::Panel::GetWide((vgui::Panel *)this) / 375;
    if ( v6 >= 1 )
    {
      if ( v6 <= 5 )
      {
        v57 = v6;
        v7 = v6;
      }
      else
      {
        v57 = 5;
        v7 = 5;
      }
    }
    else
    {
      v7 = 1;
      v57 = 1;
    }
    for ( i = 0; i < v7; ++i )
    {
      if ( i != 0 )
        x[i] = x[i - 1] + 355;
      else
        x[0] = 20;
    }
    GetFontTall = g_pVGuiSurface->GetFontTall;
    c = *(_DWORD *)&this->m_m_nBgTextureId1_register;
    v10 = ((int (__thiscall *)(vgui::ISurface *, int, int, int))GetFontTall)(
            a1: g_pVGuiSurface,
            a2: this->m_nBgTextureId4,
            a3,
            a4: a2)
        - 7;
    v11 = g_pVGuiSurface->GetFontTall;
    m_pSizer = this->m_pSizer;
    fonttall = v10;
    v12 = v11(this: g_pVGuiSurface, a2: (unsigned int)m_pSizer);
    v13 = g_pVGuiSurface->GetFontTall;
    fonttallMedium = v12 - 7;
    fonttallBig = v13(this: g_pVGuiSurface, a2: (unsigned int)this->m_DumpEntityInfo.m_Memory.m_pMemory) - 7;
    r = 255;
    g = 255;
    b = 255;
    a = 255;
    currentclass[0] = 0;
    v14 = 15;
    col = 0;
    classextra[0] = 0;
    V_strncpy(pDest: classprefix, pSrc: "class ", maxLen: 32);
    v15 = C_BaseEntity::GetClassname(this: v59);
    v16 = *v15 == 0;
    classname = v15;
    if ( v16 )
    {
      v17 = (type_info *)__RTtypeid(inptr: v59);
      classname = type_info::name(this: v17, __ptype_info_node: &__type_info_root_node);
      V_strncpy(pDest: classextra, pSrc: " (classmap missing)", maxLen: 32);
      classprefix[0] = 0;
    }
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: (unsigned int)this->m_DumpEntityInfo.m_Memory.m_pMemory);
    DrawSetTextColor = g_pVGuiSurface->DrawSetTextColor;
    v60 = -1;
    ((void (__thiscall *)(vgui::ISurface *, int))DrawSetTextColor)(a1: g_pVGuiSurface, a2: -1);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x[0] - 10, a3: 13 - fonttallBig);
    v19 = ((int (__thiscall *)(IClientNetworkable *, char *, const char *, char *))v59->entindex)(
            a1: &v59->IClientNetworkable,
            a2: classprefix,
            a3: classname,
            a4: classextra);
    V_snprintf(pDest: sz, maxLen: 0x200u, pFormat: "entity # %i: %s%s%s", v19, v36, v37, v39);
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: szconverted, a4: 2048);
    g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: szconverted, a3: wcslen(szconverted), a4: FONT_DRAW_DEFAULT);
    fonttallBig = 0;
    if ( c > 0 )
    {
      classname = nullptr;
      do
      {
        v20 = &classname[LODWORD(this->m_flAlpha)];
        if ( _V_stricmp(s1: v20 + 4, s2: currentclass) != 0 )
        {
          v21 = v14 + 2;
          g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: (unsigned int)this->m_pSizer);
          v22 = g_pVGuiSurface->DrawSetTextColor;
          v60 = -10158336;
          ((void (__thiscall *)(vgui::ISurface *, int))v22)(a1: g_pVGuiSurface, a2: -10158336);
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x[col] - 10, a3: v21);
          V_snprintf(pDest: sz, maxLen: 0x200u, pFormat: "%s", v20 + 4);
          g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: szconverted, a4: 2048);
          g_pVGuiSurface->DrawPrintText(
            this: g_pVGuiSurface,
            a2: szconverted,
            a3: wcslen(szconverted),
            a4: FONT_DRAW_DEFAULT);
          v14 = fonttallMedium + v21;
          V_strncpy(pDest: currentclass, pSrc: (char *)v20 + 4, maxLen: 128);
        }
        CPDumpPanel::PredictionDumpColor(
          this: (CPDumpPanel *)((char *)this - 56),
          legend: false,
          predictable: bPredictable,
          networked: v20[132],
          errorchecked: v20[263] == 0,
          differs: v20[261],
          withintolerance: v20[262],
          &r,
          &g,
          &b,
          &a);
        g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_nBgTextureId4);
        LOBYTE(v59) = r;
        BYTE1(v59) = g;
        BYTE2(v59) = b;
        v23 = g_pVGuiSurface->DrawSetTextColor;
        HIBYTE(v59) = a;
        ((void (__thiscall *)(vgui::ISurface *, C_BaseEntity *))v23)(a1: g_pVGuiSurface, a2: v59);
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x[col], a3: v14);
        V_snprintf(pDest: sz, maxLen: 0x200u, pFormat: "%s", v20 + 133);
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: szconverted, a4: 2048);
        g_pVGuiSurface->DrawPrintText(
          this: g_pVGuiSurface,
          a2: szconverted,
          a3: wcslen(szconverted),
          a4: FONT_DRAW_DEFAULT);
        v10 = fonttall;
        v14 += fonttall;
        if ( v14 >= -15 - v10 + vgui::Panel::GetTall((vgui::Panel *)this) )
        {
          v14 = 15;
          if ( ++col >= v57 )
            break;
        }
        classname += 264;
        ++fonttallBig;
      }
      while ( fonttallBig < c );
    }
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_nBgTextureId4);
    g_pVGuiLocalize->ConvertANSIToUnicode(
      this: g_pVGuiLocalize,
      a2: "Not networked, no differences",
      a3: szconverted,
      a4: 2048);
    g_pVGuiSurface->GetTextSize(
      this: g_pVGuiSurface,
      a2: this->m_nBgTextureId4,
      a3: szconverted,
      a4: &textSizeWide,
      a5: &textSizeTall);
    v24 = -5 - textSizeWide + ScreenWidth();
    v25 = ScreenHeight() + -80 - 7 * v10;
    v26 = g_pVGuiSurface->DrawSetTextColor;
    col = -1;
    ((void (__thiscall *)(vgui::ISurface *, int))v26)(a1: g_pVGuiSurface, a2: -1);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v24, a3: v25);
    V_strncpy(pDest: sz, pSrc: "Not networked, no differences", maxLen: 512);
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: szconverted, a4: 2048);
    g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: szconverted, a3: wcslen(szconverted), a4: FONT_DRAW_DEFAULT);
    v27 = g_pVGuiSurface->DrawSetTextColor;
    col = -6900586;
    v28 = v10 + v25;
    ((void (__thiscall *)(vgui::ISurface *, int))v27)(a1: g_pVGuiSurface, a2: -6900586);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v24, a3: v28);
    V_strncpy(pDest: sz, pSrc: "Networked, not checked", maxLen: 512);
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: szconverted, a4: 2048);
    g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: szconverted, a3: wcslen(szconverted), a4: FONT_DRAW_DEFAULT);
    v29 = g_pVGuiSurface->DrawSetTextColor;
    col = -1985356;
    v30 = v10 + v28;
    ((void (__thiscall *)(vgui::ISurface *, int))v29)(a1: g_pVGuiSurface, a2: -1985356);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v24, a3: v30);
    V_strncpy(pDest: sz, pSrc: "Networked, error checked", maxLen: 512);
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: szconverted, a4: 2048);
    g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: szconverted, a3: wcslen(szconverted), a4: FONT_DRAW_DEFAULT);
    v31 = g_pVGuiSurface->DrawSetTextColor;
    col = -16711681;
    v32 = v10 + v30;
    ((void (__thiscall *)(vgui::ISurface *, int))v31)(a1: g_pVGuiSurface, a2: -16711681);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v24, a3: v32);
    V_strncpy(pDest: sz, pSrc: "Differs, but within tolerance", maxLen: 512);
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: szconverted, a4: 2048);
    g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: szconverted, a3: wcslen(szconverted), a4: FONT_DRAW_DEFAULT);
    v33 = g_pVGuiSurface->DrawSetTextColor;
    col = -10177356;
    v34 = v10 + v32;
    ((void (__thiscall *)(vgui::ISurface *, int))v33)(a1: g_pVGuiSurface, a2: -10177356);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v24, a3: v34);
    V_strncpy(pDest: sz, pSrc: "Differs, but not networked", maxLen: 512);
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: szconverted, a4: 2048);
    wcslen(szconverted);
    ((void (__thiscall *)(vgui::ISurface *, wchar_t *))g_pVGuiSurface->DrawPrintText)(
      a1: g_pVGuiSurface,
      a2: szconverted);
    v35 = g_pVGuiSurface->DrawSetTextColor;
    col = -16776961;
    ((void (__thiscall *)(vgui::ISurface *, int))v35)(a1: g_pVGuiSurface, a2: -16776961);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v24, a3: v10 + v34);
    V_strncpy(pDest: sz, pSrc: "Differs, networked", maxLen: 512);
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: szconverted, a4: 2048);
    g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: szconverted, a3: wcslen(szconverted), a4: FONT_DRAW_DEFAULT);
  }
  else
  {
    *(_DWORD *)&this->m_m_nBgTextureId1_register = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F2D0
// Name: public: int CUtlSortVector<struct CPDumpPanel::DumpInfo,class CPDumpPanel::DumpInfo::CDumpInfoLess>::InsertNoSort(struct CPDumpPanel::DumpInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CPDumpPanel::DumpInfo,CPDumpPanel::DumpInfo::CDumpInfoLess>::InsertNoSort(
        CUtlSortVector<CPDumpPanel::DumpInfo,CPDumpPanel::DumpInfo::CDumpInfoLess> *this,
        const CPDumpPanel::DumpInfo *src)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CPDumpPanel::DumpInfo *m_pMemory; // ecx
  int v6; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  this->m_bNeedsSort = true;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPDumpPanel::DumpInfo,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 264 * v6);
  result = m_Size;
  if ( &this->m_Memory.m_pMemory[m_Size] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[m_Size], src, sizeof(this->m_Memory.m_pMemory[m_Size]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010F360
// Name: public: virtual struct vgui::PanelMessageMap __near * CPDumpPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPDumpPanel::GetMessageMap(CPDumpPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPDumpPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPDumpPanel::GetMessageMap'::`2'::s_pMap;
  `CPDumpPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPDumpPanel");
  `CPDumpPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010F390
// Name: public: virtual struct PanelAnimationMap __near * CPDumpPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPDumpPanel::GetAnimMap(CPDumpPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPDumpPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1010F3A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPDumpPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPDumpPanel::GetKBMap(CPDumpPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPDumpPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPDumpPanel::GetKBMap'::`2'::s_pMap;
  `CPDumpPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPDumpPanel");
  `CPDumpPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010F3D0
// Name: public: void CPDumpPanel::DumpComparision(char const __near *,char const __near *,char const __near *,bool,bool,bool,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPDumpPanel::DumpComparision(
        CPDumpPanel *this,
        const char *classname,
        const char *fieldname,
        const char *fieldtype,
        bool networked,
        bool noterrorchecked,
        bool differs,
        bool withintolerance,
        char *value)
{
  const char *v9; // edi
  int v11; // esi
  char *ButtonFieldValue; // eax
  char bv[128]; // [esp+8h] [ebp-188h] BYREF
  CPDumpPanel::DumpInfo slot; // [esp+88h] [ebp-108h] BYREF

  v9 = fieldname;
  if ( fieldname != nullptr )
  {
    slot.index = this->m_nCurrentIndex;
    this->m_nCurrentIndex = slot.index + 1;
    V_snprintf(pDest: slot.classname, maxLen: 0x80u, pFormat: "%s", classname);
    slot.networked = networked;
    v11 = 0;
    while ( _V_stricmp(s1: fieldname, s2: pchButtonFields[v11]) != 0 )
    {
      if ( (unsigned int)++v11 >= 6 )
      {
        ButtonFieldValue = CleanupZeros(value, buf: bv);
        goto LABEL_6;
      }
    }
    ButtonFieldValue = GetButtonFieldValue(value, buf: bv, bufsize: 0x80u);
    v9 = fieldname;
LABEL_6:
    V_snprintf(pDest: slot.fieldstring, maxLen: 0x80u, pFormat: "%s %s", v9, ButtonFieldValue);
    slot.differs = differs;
    slot.noterrorchecked = noterrorchecked;
    slot.withintolerance = withintolerance;
    CUtlSortVector<CPDumpPanel::DumpInfo,CPDumpPanel::DumpInfo::CDumpInfoLess>::InsertNoSort(
      this: &this->m_DumpEntityInfo,
      src: &slot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F4C0
// Name: DumpComparision
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpComparision(
        const char *classname,
        const char *fieldname,
        const char *fieldtype,
        bool networked,
        bool noterrorchecked,
        bool differs,
        bool withintolerance,
        const char *value)
{
  CHud *Hud; // eax
  CPDumpPanel *Element; // eax

  Hud = GetHud(nSlot: 0);
  Element = (CPDumpPanel *)CHud::FindElement(this: Hud, pName: "CPDumpPanel");
  if ( Element != nullptr )
    CPDumpPanel::DumpComparision(
      this: Element,
      classname,
      fieldname,
      fieldtype,
      networked,
      noterrorchecked,
      differs,
      withintolerance,
      value);
}

//------------------------------------------------------------------------------
// Address: 0x1010F510
// Name: public: static void CPDumpPanel::PanelAnimationVar_m_FontSmall::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPDumpPanel::PanelAnimationVar_m_FontSmall::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CPDumpPanel::PanelAnimationVar_m_FontSmall::InitVar'::`2'::bAdded )
  {
    `CPDumpPanel::PanelAnimationVar_m_FontSmall::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CPDumpPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "ItemFont";
    src.m_pszVariable = "m_FontSmall";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "DebugOverlay";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CPDumpPanel::GetVar_m_FontSmall;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F570
// Name: public: static void CPDumpPanel::PanelAnimationVar_m_FontMedium::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPDumpPanel::PanelAnimationVar_m_FontMedium::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CPDumpPanel::PanelAnimationVar_m_FontMedium::InitVar'::`2'::bAdded )
  {
    `CPDumpPanel::PanelAnimationVar_m_FontMedium::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CPDumpPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LabelFont";
    src.m_pszVariable = "m_FontMedium";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "DebugOverlay";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CPDumpPanel::GetVar_m_FontMedium;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F5D0
// Name: public: static void CPDumpPanel::PanelAnimationVar_m_FontBig::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPDumpPanel::PanelAnimationVar_m_FontBig::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CPDumpPanel::PanelAnimationVar_m_FontBig::InitVar'::`2'::bAdded )
  {
    `CPDumpPanel::PanelAnimationVar_m_FontBig::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CPDumpPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "TitleFont";
    src.m_pszVariable = "m_FontBig";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "DebugOverlay";
    src.m_pfnLookup = CPDumpPanel::GetVar_m_FontBig;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F630
// Name: public: CPDumpPanel::CPDumpPanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPDumpPanel *__thiscall CPDumpPanel::CPDumpPanel(CPDumpPanel *this, const char *pElementName)
{
  PanelAnimationMap *v3; // ebx
  vgui::PanelKeyBindingMap *v4; // ebx
  ClientModeCSFullscreen *FullscreenClientMode; // eax
  vgui::Panel *v6; // eax
  const char *pElementNamea; // [esp+14h] [ebp+8h]

  CHudElement::CHudElement(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudPredictionDump");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CPDumpPanel_vtbl *)&CPDumpPanel::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CPDumpPanel::`vftable'{for `vgui::Panel'};
  if ( `CPDumpPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPDumpPanel::ChainToMap'::`2'::chained = 1;
    pElementNamea = (const char *)vgui::FindOrAddPanelMessageMap(className: "CPDumpPanel");
    *((_DWORD *)pElementNamea + 7) = CPDumpPanel::GetPanelClassName;
    *((_DWORD *)pElementNamea + 6) = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CPDumpPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPDumpPanel::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CPDumpPanel");
    v3->pfnClassName = CPDumpPanel::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CPDumpPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPDumpPanel::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CPDumpPanel");
    v4->pfnClassName = CPDumpPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_DumpEntityInfo.m_Memory.m_pMemory = nullptr;
  this->m_DumpEntityInfo.m_Memory.m_nAllocationCount = 0;
  this->m_DumpEntityInfo.m_Memory.m_nGrowSize = 0;
  this->m_DumpEntityInfo.m_Size = 0;
  this->m_DumpEntityInfo.m_pElements = nullptr;
  this->m_DumpEntityInfo.m_pLessContext = nullptr;
  this->m_DumpEntityInfo.m_bNeedsSort = false;
  this->m_hDumpEntity.m_Index = -1;
  this->m_nCurrentIndex = 0;
  CPDumpPanel::PanelAnimationVar_m_FontSmall::InitVar();
  CPDumpPanel::PanelAnimationVar_m_FontMedium::InitVar();
  CPDumpPanel::PanelAnimationVar_m_FontBig::InitVar();
  FullscreenClientMode = GetFullscreenClientMode();
  v6 = FullscreenClientMode->GetViewport(this: FullscreenClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v6);
  vgui::Panel::SetProportional(this: &this->vgui::Panel, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this: &this->vgui::Panel, state: 0);
  vgui::Panel::SetMouseInputEnabled(this: &this->vgui::Panel, state: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010F7E0
// Name: Create_CPDumpPanel
// Source: json
//------------------------------------------------------------------------------
CPDumpPanel *__cdecl Create_CPDumpPanel()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 452);
  memset(dst: v0, value: 0, count: 0x1C4u);
  if ( v0 != nullptr )
    return CPDumpPanel::CPDumpPanel(this: (CPDumpPanel *)v0, pElementName: "CPDumpPanel");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1010F820
// Name: public: void CPDumpPanel::DumpEntity(class C_BaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPDumpPanel::DumpEntity(CPDumpPanel *this, C_BaseEntity *ent, int commands_acknowledged)
{
  C_BaseEntity *v3; // esi
  unsigned __int8 *OriginalNetworkDataObject; // ebx
  unsigned __int8 *PredictedFrame; // eax
  int v7; // eax
  signed int m_Size; // eax
  bool v9; // [esp-14h] [ebp-6Ch]
  bool v10; // [esp-Ch] [ebp-64h]
  datamap_t *v11; // [esp-4h] [ebp-5Ch]
  CPredictionCopy datacompare; // [esp+Ch] [ebp-4Ch] BYREF
  void *context; // [esp+4Ch] [ebp-Ch] BYREF
  char *data_type_original; // [esp+50h] [ebp-8h]
  BOOL data_type_predicted; // [esp+54h] [ebp-4h]

  v3 = ent;
  LOBYTE(data_type_original) = 1;
  LOBYTE(data_type_predicted) = 1;
  if ( C_BaseEntity::GetPredictable(this: ent) )
  {
    OriginalNetworkDataObject = C_BaseEntity::GetOriginalNetworkDataObject(this: v3);
    PredictedFrame = C_BaseEntity::GetPredictedFrame(this: v3, framenumber: commands_acknowledged - 1);
  }
  else
  {
    OriginalNetworkDataObject = (unsigned __int8 *)v3;
    LOBYTE(data_type_original) = 0;
    PredictedFrame = (unsigned __int8 *)v3;
    LOBYTE(data_type_predicted) = 0;
  }
  v10 = data_type_predicted;
  v9 = (char)data_type_original;
  this->m_DumpEntityInfo.m_Size = 0;
  CPredictionCopy::CPredictionCopy(
    this: &datacompare,
    type: 2,
    dest: OriginalNetworkDataObject,
    dest_packed: v9,
    src: PredictedFrame,
    src_packed: v10,
    opType: TRANSFERDATA_ERRORCHECK_DESCRIBE,
    func: DumpComparision);
  this->m_nCurrentIndex = 0;
  v11 = v3->GetPredDescMap(this: v3);
  v7 = v3->entindex(this: &v3->IClientNetworkable);
  CPredictionCopy::TransferData(this: &datacompare, operation: prType, entindex: v7, dmap: v11);
  this->m_hDumpEntity.m_Index = v3->GetRefEHandle(this: v3)->m_Index;
  if ( this->m_DumpEntityInfo.m_bNeedsSort )
  {
    m_Size = this->m_DumpEntityInfo.m_Size;
    this->m_DumpEntityInfo.m_bNeedsSort = false;
    if ( m_Size > 1 )
    {
      context = this->m_DumpEntityInfo.m_pLessContext;
      data_type_original = (char *)&ent + 3;
      qsort_s(
        base: this->m_DumpEntityInfo.m_Memory.m_pMemory,
        num: m_Size,
        width: 0x108u,
        comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CPDumpPanel::DumpInfo,CPDumpPanel::DumpInfo::CDumpInfoLess>::CompareHelper,
        &context);
    }
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&datacompare.m_FieldStack);
}

//------------------------------------------------------------------------------
// Address: 0x10405950
// Name: protected: static int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::CompareHelper(void __near *,class CDmxAttribute __near * const __near *,class CDmxAttribute __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper(
        void *context,
        CDmxAttribute *const *lhs,
        CDmxAttribute *const *rhs)
{
  int v3; // ecx
  int v4; // esi
  int result; // eax
  int lhsa; // [esp+14h] [ebp+Ch]
  int rhsa; // [esp+18h] [ebp+10h]
  int rhsb; // [esp+18h] [ebp+10h]

  v3 = (int)*rhs;
  v4 = (int)*lhs;
  result = -1;
  if ( *lhs != nullptr )
    rhsa = *(_DWORD *)(v4 + 4);
  else
    rhsa = -1;
  if ( v3 != 0 )
    lhsa = *(_DWORD *)(v3 + 4);
  else
    lhsa = -1;
  if ( rhsa >= lhsa )
  {
    if ( v3 != 0 )
      rhsb = *(_DWORD *)(v3 + 4);
    else
      rhsb = -1;
    if ( v4 != 0 )
      return rhsb < *(_DWORD *)(v4 + 4);
    else
      return rhsb < -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405B50
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::Find(class CDmxAttribute __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute *const **src)
{
  int v3; // ebx
  int v4; // ecx
  CDmxAttribute **m_pMemory; // eax
  CDmxAttribute *const *v6; // esi
  int result; // eax
  CDmxAttribute *v8; // edx
  int *v9; // edi
  int *v10; // esi
  int *v11; // esi
  int *v12; // ecx
  int v13; // [esp+Ch] [ebp-24h] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v14; // [esp+10h] [ebp-20h] BYREF
  int v15; // [esp+14h] [ebp-1Ch] BYREF
  int v16; // [esp+18h] [ebp-18h] BYREF
  int v17; // [esp+1Ch] [ebp-14h] BYREF
  int v18; // [esp+20h] [ebp-10h] BYREF
  int v19; // [esp+24h] [ebp-Ch] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v20; // [esp+28h] [ebp-8h] BYREF
  CDmxAttribute **v21; // [esp+2Ch] [ebp-4h]
  CDmxAttribute *const *srca; // [esp+38h] [ebp+8h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = *src;
    v21 = m_pMemory;
    for ( srca = v6; ; v6 = srca )
    {
      result = (v4 + v3) >> 1;
      v8 = v21[result];
      if ( v8 != nullptr )
      {
        v20.m_Id = (int)v8->m_Name.u;
        v9 = (int *)&v20;
      }
      else
      {
        v19 = -1;
        v9 = &v19;
      }
      if ( v6 != nullptr )
      {
        v18 = *((_DWORD *)v6 + 1);
        v10 = &v18;
      }
      else
      {
        v17 = -1;
        v10 = &v17;
      }
      if ( *v9 >= *v10 )
      {
        if ( srca != nullptr )
        {
          v16 = *((_DWORD *)srca + 1);
          v11 = &v16;
        }
        else
        {
          v15 = -1;
          v11 = &v15;
        }
        if ( v8 != nullptr )
        {
          v14.m_Id = (int)v8->m_Name.u;
          v12 = (int *)&v14;
        }
        else
        {
          v13 = -1;
          v12 = &v13;
        }
        if ( *v11 >= *v12 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
      if ( v3 > v4 )
        return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10405DA0
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::InsertNoSort(class CDmxAttribute __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute **src)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmxAttribute **v7; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  this->m_bNeedsSort = true;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = *src;
  return m_Size;
}
