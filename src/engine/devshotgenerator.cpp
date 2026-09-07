// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/devshotgenerator.cpp
// Functions: 6
// ============================================================

#include "engine\devshotgenerator.h"

//------------------------------------------------------------------------------
// Address: 0x100B9370
// Name: class CDevShotGenerator __near & DevShotGenerator(void)
// Source: json
//------------------------------------------------------------------------------
CDevShotGenerator *__cdecl DevShotGenerator()
{
  return &g_DevShotGenerator;
}

//------------------------------------------------------------------------------
// Address: 0x100B9380
// Name: public: void CDevShotGenerator::BuildMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDevShotGenerator::BuildMapList(CDevShotGenerator *this@<ecx>, int a2@<esi>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  char *v6; // [esp-Ch] [ebp-14h]
  const char *pMapFile; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bDevShotsEnabled )
  {
    _Msg(a1: "-makedevshots usage:\n", a2);
    _Msg(a1: "  [ -usedevshotsfile filename ] -- get map list from specified file, default is to build for maps/*.bsp\n");
    _Msg(a1: "  [ -startmap mapname ] -- restart generation at specified map (after crash, implies resume)\n");
    _Msg(a1: "  [ -condebug ] -- prepend console.log entries with mapname or engine if not in a map\n");
    _Msg(a1: "  [ +map mapname ] -- generate devshots for specified map and exit after that map\n");
    pMapFile = nullptr;
    v3 = _CommandLine();
    (*(void (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v3 + 12))(
      a1: v3,
      a2: "-usedevshotsfile",
      a3: &pMapFile);
    v4 = _CommandLine();
    v6 = (char *)pMapFile;
    v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 40))(a1: v4);
    if ( !BuildGeneralMapList(
            aMaps: &this->m_Maps,
            bUseMapListFile: v5 != 0,
            pMapFile: "-usedevshotsfile",
            pSystemMsg: v6,
            iCurrentMap: (int *)"devshots") )
      this->m_bDevShotsEnabled = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9420
// Name: void DevShotGenerator_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DevShotGenerator_Init()
{
  int v0; // eax
  int v1; // eax

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-makedevshots") != 0 )
  {
    v1 = _CommandLine();
    g_DevShotGenerator.m_bUsingMapList = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(
                                           a1: v1,
                                           a2: "-usedevshotsfile") != 0;
    g_DevShotGenerator.m_bDevShotsEnabled = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9470
// Name: public: void CDevShotGenerator::NextMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDevShotGenerator::NextMap(CDevShotGenerator *this)
{
  int m_iCurrentMap; // eax
  ECommandTarget_t v3; // eax
  ECommandTarget_t TraceType; // eax
  CFmtStrN<256> str; // [esp+4h] [ebp-10Ch] BYREF

  if ( this->m_bDevShotsEnabled )
  {
    m_iCurrentMap = this->m_iCurrentMap;
    if ( m_iCurrentMap < 0 || m_iCurrentMap >= this->m_Maps.m_Size )
    {
      TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
      Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
    }
    else
    {
      CFmtStrN<256>::CFmtStrN<256>(
        this: &str,
        pszFormat: "map %s\n",
        this->m_Maps.m_Memory.m_pMemory[m_iCurrentMap].name);
      v3 = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)str.m_szBuf);
      Cbuf_AddText(eTarget: v3, pText: str.m_szBuf, nTickDelay: 0);
      ++this->m_iCurrentMap;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B94F0
// Name: public: void CDevShotGenerator::StartDevShotGeneration(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDevShotGenerator::StartDevShotGeneration(CDevShotGenerator *this)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  CFmtStrN<256> str; // [esp+4h] [ebp-10Ch] BYREF

  CDevShotGenerator::BuildMapList(this, a2: (int)this);
  CFmtStrN<256>::CFmtStrN<256>(
    this: &str,
    pszFormat: "map %s\n",
    this->m_Maps.m_Memory.m_pMemory[this->m_iCurrentMap].name);
  TraceType = CTraceFilter::GetTraceType(this: v2);
  Cbuf_AddText(eTarget: TraceType, pText: str.m_szBuf, nTickDelay: 0);
  ++this->m_iCurrentMap;
}

//------------------------------------------------------------------------------
// Address: 0x100B9540
// Name: void CL_DevShots_NextMap(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DevShots_NextMap()
{
  CDevShotGenerator::NextMap(this: &g_DevShotGenerator);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100B9020
// Name: class CDevShotGenerator __near & DevShotGenerator(void)
// Source: json
//------------------------------------------------------------------------------
CDevShotGenerator *__cdecl DevShotGenerator()
{
  return &g_DevShotGenerator;
}

//------------------------------------------------------------------------------
// Address: 0x100B9030
// Name: public: void CDevShotGenerator::BuildMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDevShotGenerator::BuildMapList(CDevShotGenerator *this@<ecx>, int a2@<esi>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  char *v6; // [esp-Ch] [ebp-14h]
  const char *pMapFile; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bDevShotsEnabled )
  {
    _Msg(a1: "-makedevshots usage:\n", a2);
    _Msg(a1: "  [ -usedevshotsfile filename ] -- get map list from specified file, default is to build for maps/*.bsp\n");
    _Msg(a1: "  [ -startmap mapname ] -- restart generation at specified map (after crash, implies resume)\n");
    _Msg(a1: "  [ -condebug ] -- prepend console.log entries with mapname or engine if not in a map\n");
    _Msg(a1: "  [ +map mapname ] -- generate devshots for specified map and exit after that map\n");
    pMapFile = nullptr;
    v3 = _CommandLine();
    (*(void (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v3 + 12))(
      a1: v3,
      a2: "-usedevshotsfile",
      a3: &pMapFile);
    v4 = _CommandLine();
    v6 = (char *)pMapFile;
    v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 40))(a1: v4);
    if ( !BuildGeneralMapList(
            aMaps: &this->m_Maps,
            bUseMapListFile: v5 != 0,
            pMapFile: "-usedevshotsfile",
            pSystemMsg: v6,
            iCurrentMap: (int *)"devshots") )
      this->m_bDevShotsEnabled = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B90F0
// Name: void DevShotGenerator_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DevShotGenerator_Init()
{
  int v0; // eax
  int v1; // eax

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-makedevshots") != 0 )
  {
    v1 = _CommandLine();
    g_DevShotGenerator.m_bUsingMapList = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(
                                           a1: v1,
                                           a2: "-usedevshotsfile") != 0;
    g_DevShotGenerator.m_bDevShotsEnabled = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9140
// Name: public: void CDevShotGenerator::NextMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDevShotGenerator::NextMap(CDevShotGenerator *this)
{
  int m_iCurrentMap; // eax
  ECommandTarget_t v3; // eax
  ECommandTarget_t TraceType; // eax
  CFmtStrN<256> str; // [esp+4h] [ebp-10Ch] BYREF

  if ( this->m_bDevShotsEnabled )
  {
    m_iCurrentMap = this->m_iCurrentMap;
    if ( m_iCurrentMap < 0 || m_iCurrentMap >= this->m_Maps.m_Size )
    {
      TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
      Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
    }
    else
    {
      CFmtStrN<256>::CFmtStrN<256>(
        this: &str,
        pszFormat: "map %s\n",
        this->m_Maps.m_Memory.m_pMemory[m_iCurrentMap].name);
      v3 = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)str.m_szBuf);
      Cbuf_AddText(eTarget: v3, pText: str.m_szBuf, nTickDelay: 0);
      ++this->m_iCurrentMap;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B91C0
// Name: public: void CDevShotGenerator::StartDevShotGeneration(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDevShotGenerator::StartDevShotGeneration(CDevShotGenerator *this)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  CFmtStrN<256> str; // [esp+4h] [ebp-10Ch] BYREF

  CDevShotGenerator::BuildMapList(this, a2: (int)this);
  CFmtStrN<256>::CFmtStrN<256>(
    this: &str,
    pszFormat: "map %s\n",
    this->m_Maps.m_Memory.m_pMemory[this->m_iCurrentMap].name);
  TraceType = CTraceFilter::GetTraceType(this: v2);
  Cbuf_AddText(eTarget: TraceType, pText: str.m_szBuf, nTickDelay: 0);
  ++this->m_iCurrentMap;
}

//------------------------------------------------------------------------------
// Address: 0x100B9210
// Name: void CL_DevShots_NextMap(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DevShots_NextMap()
{
  CDevShotGenerator::NextMap(this: &g_DevShotGenerator);
}

} // namespace engine_xlsp
