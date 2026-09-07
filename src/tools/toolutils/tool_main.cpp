// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/tool_main.cpp
// Functions: 9
// ============================================================

#include "tools\toolutils\tool_main.h"

//------------------------------------------------------------------------------
// Address: 0x102BBAD0
// Name: unsigned int VGui_GetToolRootPanel(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl VGui_GetToolRootPanel()
{
  return enginevgui->GetPanel(this: enginevgui, a2: PANEL_GAMEDLL);
}

//------------------------------------------------------------------------------
// Address: 0x102BBAF0
// Name: public: virtual void __near * CToolDictionary::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CToolDictionary *__thiscall CToolDictionary::QueryInterface(CToolDictionary *this, const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VTOOLDICTIONARY003") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102BBB20
// Name: public: virtual void CToolDictionary::CreateTools(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CToolDictionary::CreateTools(CToolDictionary *this)
{
  CreateTools();
}

//------------------------------------------------------------------------------
// Address: 0x102BBB70
// Name: public: virtual enum InitReturnVal_t CToolDictionary::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CToolDictionary::Init(CToolDictionary *this)
{
  InitReturnVal_t result; // eax

  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  result = InitDataModel();
  if ( result == INIT_OK )
  {
    MathLib_Init(gamma: 0x400CCCCD400CCCCDLL, brightness: 0.0, overbright: 2);
    if ( registry->Init(this: registry, a2: "Source\\Tools") != 0 )
    {
      return INIT_OK;
    }
    else
    {
      _Warning(a1: "registry->Init failed\n");
      return INIT_FAILED;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BBBF0
// Name: public: virtual void CToolDictionary::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDictionary::Shutdown(CToolDictionary *this)
{
  VGui_Shutdown();
  registry->Shutdown(this: registry);
  ShutdownDataModel();
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x102BBC20
// Name: public: virtual bool CToolDictionary::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolDictionary::Connect(CToolDictionary *this, void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // esi
  vgui::ToolWindow *v3; // ecx
  IVModelInfoClient *v4; // eax
  void *(__cdecl *v6[2])(const char *, int *); // [esp+4h] [ebp-8h] BYREF

  v2 = factory;
  v6[0] = factory;
  v6[1] = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: (void *(__cdecl **)(const char *, int *))1);
  ConnectTier2Libraries();
  ConnectDataModel(factory: v2);
  CDmeFXClip::OnDestruction(this: v3);
  g_pFileSystem = g_pFullFileSystem;
  enginevgui = (IEngineVGui *)((int (__cdecl *)(const char *, _DWORD, void *(__cdecl **)(const char *, int *), int))v2)(
                                a1: "VEngineVGui001",
                                a2: 0,
                                a3: v6,
                                a4: 1);
  enginetools = (IEngineTool *)v2(a1: "VENGINETOOL003", a2: nullptr);
  debugoverlay = (IVDebugOverlay *)v2(a1: "VDebugOverlay004", a2: nullptr);
  v4 = (IVModelInfoClient *)v2(a1: "VModelInfoClient004", a2: nullptr);
  modelinfoclient = v4;
  return enginevgui != nullptr
      && debugoverlay != nullptr
      && g_pCVar != nullptr
      && enginetools != nullptr
      && g_pFileSystem != nullptr
      && p4 != nullptr
      && v4 != nullptr
      && VGui_Startup(appSystemFactory: v2)
      && ConnectTools(factory: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102BBD00
// Name: public: virtual void CToolDictionary::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDictionary::Disconnect(CToolDictionary *this)
{
  vgui::ToolWindow *v1; // ecx

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  enginevgui = nullptr;
  enginetools = nullptr;
  debugoverlay = nullptr;
  g_pFileSystem = nullptr;
  CDmeFXClip::OnDestruction(this: v1);
  DisconnectDataModel();
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x102BBD30
// Name: void RegisterTool(class IToolSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RegisterTool(IToolSystem *tool)
{
  int m_Size; // eax
  int v2; // esi
  IToolSystem **m_pMemory; // ecx
  int v4; // eax
  IToolSystem **v5; // eax

  m_Size = g_ToolDictionary.m_Tools.m_Size;
  v2 = g_ToolDictionary.m_Tools.m_Size;
  if ( g_ToolDictionary.m_Tools.m_Size + 1 > g_ToolDictionary.m_Tools.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_ToolDictionary.m_Tools,
      num: g_ToolDictionary.m_Tools.m_Size - g_ToolDictionary.m_Tools.m_Memory.m_nAllocationCount + 1);
    m_Size = g_ToolDictionary.m_Tools.m_Size;
  }
  m_pMemory = g_ToolDictionary.m_Tools.m_Memory.m_pMemory;
  g_ToolDictionary.m_Tools.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  g_ToolDictionary.m_Tools.m_pElements = g_ToolDictionary.m_Tools.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&g_ToolDictionary.m_Tools.m_Memory.m_pMemory[v2 + 1],
      src: (unsigned __int8 *)&g_ToolDictionary.m_Tools.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = g_ToolDictionary.m_Tools.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = tool;
}

//------------------------------------------------------------------------------
// Address: 0x102BBAE0
// Name: __CreateCToolDictionaryIToolDictionary_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CToolDictionary *__cdecl _CreateCToolDictionaryIToolDictionary_interface()
{
  return &g_ToolDictionary;
}
