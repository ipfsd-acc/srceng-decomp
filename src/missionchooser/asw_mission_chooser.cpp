// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/asw_mission_chooser.cpp
// Functions: 14
// ============================================================

#include "missionchooser\asw_mission_chooser.h"

//------------------------------------------------------------------------------
// Address: 0x10004540
// Name: public: virtual bool CASW_Mission_Chooser::GetCurrentTimeAndDate(int __near *,int __near *,int __near *,int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CASW_Mission_Chooser::GetCurrentTimeAndDate(
        CASW_Mission_Chooser *this,
        int *year,
        int *month,
        int *dayOfWeek,
        int *day,
        int *hour,
        int *minute,
        int *second)
{
  return ASW_System_GetCurrentTimeAndDate(year, month, dayOfWeek, day, hour, minute, second);
}

//------------------------------------------------------------------------------
// Address: 0x10004570
// Name: public: virtual class IASW_Random_Missions __near * CASW_Mission_Chooser::RandomMissions(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Random_Missions *__thiscall CASW_Mission_Chooser::RandomMissions(CASW_Mission_Chooser *this)
{
  return &g_RandomMissions;
}

//------------------------------------------------------------------------------
// Address: 0x10004580
// Name: public: virtual class IASW_Mission_Chooser_Source __near * CASW_Mission_Chooser::LocalMissionSource(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Mission_Chooser_Source_Local *__thiscall CASW_Mission_Chooser::LocalMissionSource(CASW_Mission_Chooser *this)
{
  return &g_LocalMissionSource;
}

//------------------------------------------------------------------------------
// Address: 0x10004590
// Name: public: virtual class IASW_Mission_Text_Database __near * CASW_Mission_Chooser::MissionTextDatabase(void)
// Source: json
//------------------------------------------------------------------------------
CASW_MissionTextDB *__thiscall CASW_Mission_Chooser::MissionTextDatabase(CASW_Mission_Chooser *this)
{
  return &g_MissionTextDatabase;
}

//------------------------------------------------------------------------------
// Address: 0x100045A0
// Name: public: virtual class IASW_Location_Grid __near * CASW_Mission_Chooser::LocationGrid(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Location_Grid *__thiscall CASW_Mission_Chooser::LocationGrid(CASW_Mission_Chooser *this)
{
  CASW_Location_Grid *result; // eax
  CASW_Location_Grid *v2; // eax

  result = g_pLocationGrid;
  if ( g_pLocationGrid == nullptr )
  {
    v2 = (CASW_Location_Grid *)operator new(nSize: 0x20u);
    if ( v2 != nullptr )
    {
      result = CASW_Location_Grid::CASW_Location_Grid(this: v2);
      g_pLocationGrid = result;
    }
    else
    {
      g_pLocationGrid = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100045D0
// Name: public: virtual class IASW_Map_Builder __near * CASW_Mission_Chooser::MapBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Map_Builder *__thiscall CASW_Mission_Chooser::MapBuilder(CASW_Mission_Chooser *this)
{
  CASW_Map_Builder *result; // eax
  CASW_Map_Builder *v2; // eax

  result = g_pMapBuilder;
  if ( g_pMapBuilder == nullptr )
  {
    v2 = (CASW_Map_Builder *)operator new(nSize: 0x22E8u);
    if ( v2 != nullptr )
    {
      result = CASW_Map_Builder::CASW_Map_Builder(this: v2);
      g_pMapBuilder = result;
    }
    else
    {
      g_pMapBuilder = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004600
// Name: class CASW_Spawn_Selection __near * SpawnSelection(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Spawn_Selection *__cdecl SpawnSelection()
{
  return &g_SpawnSelection;
}

//------------------------------------------------------------------------------
// Address: 0x10004610
// Name: public: virtual void __near * CASW_Mission_Chooser::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CASW_Mission_Chooser::QueryInterface(CASW_Mission_Chooser *this, const char *pInterfaceName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  return FactoryThis(a1: pInterfaceName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10004640
// Name: public: virtual void CBaseAppSystem<class IASW_Mission_Chooser>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IASW_Mission_Chooser>::Reconnect(
        CBaseAppSystem<IASW_Mission_Chooser> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10004660
// Name: public: virtual enum InitReturnVal_t CASW_Mission_Chooser::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Mission_Chooser::Init(CASW_Mission_Chooser *this)
{
  char tilegendir[260]; // [esp+0h] [ebp-104h] BYREF

  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  V_MakeAbsolutePath(pOut: g_gamedir, outLen: 1024, pPath: "infested", pStartingDir: nullptr);
  V_AppendSlash(pStr: g_gamedir, strSize: 1024);
  V_snprintf(pDest: tilegendir, maxLen: 260, pFormat: "%s\\tilegen", g_gamedir);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: tilegendir, a3: "TILEGEN", a4: PATH_ADD_TO_TAIL);
  V_snprintf(pDest: g_layoutsdir, maxLen: 1024, pFormat: "%s\\tilegen\\layouts", g_gamedir);
  CASW_MissionTextDB::LoadKeyValuesFile(this: &g_MissionTextDatabase, pFilename: "tilegen/objective_text.txt");
  CASW_Spawn_Selection::Init(this: &g_SpawnSelection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004720
// Name: public: virtual bool CASW_Mission_Chooser::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CASW_Mission_Chooser::Connect(
        CASW_Mission_Chooser *this,
        void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // esi
  vgui::Panel *v3; // ecx
  IFileLoggingListener *v5; // eax
  int v6; // eax
  void (__thiscall *AssignLogChannel)(IFileLoggingListener *, int, int); // edx
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  v2 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  vgui::Panel::PostChildPaint(this: v3);
  if ( g_pFullFileSystem == nullptr )
  {
    _Error(a1: "Missionchooser requires the filesystem to run!\n");
    return 0;
  }
  engine = (IVEngineClient *)v2(a1: "VEngineClient013", a2: nullptr);
  if ( engine == nullptr )
    _Msg(a1: "Failed to load engine\n");
  enginevgui = (IEngineVGui *)v2(a1: "VEngineVGui001", a2: nullptr);
  if ( enginevgui == nullptr )
    _Msg(a1: "Failed to load enginevgui\n");
  v5 = (IFileLoggingListener *)v2(a1: "FileLoggingListener001", a2: nullptr);
  filelogginglistener = v5;
  if ( v5 == nullptr )
    return 0;
  v6 = v5->BeginLoggingToFile(this: v5, a2: "tilegen_log.txt", a3: "w", a4: nullptr);
  AssignLogChannel = filelogginglistener->AssignLogChannel;
  s_TilegenLogHandle = v6;
  AssignLogChannel(this: filelogginglistener, a2: LOG_TilegenLayoutSystem, a3: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004810
// Name: public: virtual void CASW_Mission_Chooser::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser::Disconnect(CASW_Mission_Chooser *this)
{
  vgui::Panel *v1; // ecx

  filelogginglistener->EndLoggingToFile(this: filelogginglistener, a2: s_TilegenLogHandle);
  vgui::Panel::PostChildPaint(this: v1);
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10004840
// Name: public: virtual void CTier2AppSystem<class IASW_Mission_Chooser,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IASW_Mission_Chooser,0>::Shutdown(CTier2AppSystem<IASW_Mission_Chooser,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10004630
// Name: __CreateCASW_Mission_ChooserIASW_Mission_Chooser_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CASW_Mission_Chooser *__cdecl _CreateCASW_Mission_ChooserIASW_Mission_Chooser_interface()
{
  return &_g_CASW_Mission_Chooser_singleton;
}
