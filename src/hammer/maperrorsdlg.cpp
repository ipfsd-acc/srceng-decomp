// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/maperrorsdlg.cpp
// Functions: 22
// ============================================================

#include "hammer\maperrorsdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100D3DF0
// Name: public: CMapErrorsDlg::CMapErrorsDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CMapErrorsDlg *__thiscall CMapErrorsDlg::CMapErrorsDlg(CMapErrorsDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0xB0u, pParentWnd: pParent);
  this->__vftable = (CMapErrorsDlg_vtbl *)&CMapErrorsDlg::`vftable';
  CWnd::CWnd(this: &this->m_cErrors);
  this->m_cErrors.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D3ED0
// Name: protected: virtual void CMapErrorsDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapErrorsDlg::DoDataExchange(CMapErrorsDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x462, rControl: (HWND__ *)&this->m_cErrors);
}

//------------------------------------------------------------------------------
// Address: 0x100D3EF0
// Name: protected: virtual int CMapErrorsDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapErrorsDlg::OnInitDialog(CMapErrorsDlg *this)
{
  error3d *i; // esi
  LRESULT v3; // eax

  CDialog::OnInitDialog(this);
  for ( i = Enum3dErrors(bStart: 1); i != nullptr; i = Enum3dErrors(bStart: 0) )
  {
    SendMessageA(hWnd: this->m_cErrors.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)i->pszReason);
    v3 = SendMessageA(hWnd: this->m_cErrors.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_cErrors.m_hWnd, Msg: 0x19Au, wParam: v3 - 1, lParam: (LPARAM)i);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D3F60
// Name: protected: virtual struct AFX_MSGMAP const __near * CMapErrorsDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMapErrorsDlg::GetMessageMap(CMapErrorsDlg *this)
{
  return (const AFX_MSGMAP *)&off_105ECCBC;
}

//------------------------------------------------------------------------------
// Address: 0x105BFE50
// Name: _dynamic_initializer_for__Errors__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Errors__()
{
  return atexit(func: dynamic_atexit_destructor_for__Errors__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9FE0
// Name: _dynamic_atexit_destructor_for__Errors__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Errors__()
{
  Errors.__vftable = (CArray<error3d,error3d &>_vtbl *)&CArray<error3d,error3d &>::`vftable';
  if ( Errors.m_pData != nullptr )
    operator delete(p: Errors.m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x105BFE60
// Name: _dynamic_initializer_for__g_ToolHandlerSyncMesh__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ToolHandlerSyncMesh__()
{
  CToolHandler_SyncMesh::CToolHandler_SyncMesh(this: &g_ToolHandlerSyncMesh);
  return atexit(func: dynamic_atexit_destructor_for__g_ToolHandlerSyncMesh__);
}

//------------------------------------------------------------------------------
// Address: 0x105BFE80
// Name: _dynamic_initializer_for__g_HammerIpcServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_HammerIpcServer__()
{
  CValveIpcServer::CValveIpcServer(this: &g_HammerIpcServer, szServerName: "HAMMER_IPC_SERVER");
  g_HammerIpcServer.__vftable = (CHammerIpcServer_vtbl *)&CHammerIpcServer::`vftable';
  AppRegisterPostInitFn(fn: CHammerIpcServer::AppInit);
  AppRegisterPreShutdownFn(fn: CHammerIpcServer::AppShutdown);
  return atexit(func: dynamic_atexit_destructor_for__g_HammerIpcServer__);
}

//------------------------------------------------------------------------------
// Address: 0x105BFF00
// Name: _dynamic_initializer_for__g_syncmesh_saveloadhandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_syncmesh_saveloadhandler__()
{
  CVmfMeshDataSupport_SaveLoadHandler::CVmfMeshDataSupport_SaveLoadHandler(this: &g_syncmesh_saveloadhandler);
  g_syncmesh_saveloadhandler.__vftable = (CSyncMesh_SaveLoadHandler_vtbl *)&CSyncMesh_SaveLoadHandler::`vftable';
  VmfInstallMapEntitySaveLoadHandler(pHandler: (vgui::TreeNode *)&g_syncmesh_saveloadhandler);
  return atexit(func: dynamic_atexit_destructor_for__g_syncmesh_saveloadhandler__);
}

//------------------------------------------------------------------------------
// Address: 0x105BFF60
// Name: _dynamic_initializer_for__HL2Info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__HL2Info__()
{
  int result; // eax

  result = GetAppSteamAppId(eSourceApp: k_App_HL2);
  HL2Info.steamAppID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105BFF70
// Name: _dynamic_initializer_for__CStrikeInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CStrikeInfo__()
{
  int result; // eax

  result = GetAppSteamAppId(eSourceApp: k_App_CSS);
  CStrikeInfo.steamAppID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105BFF80
// Name: _dynamic_initializer_for__CStrike15Info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CStrike15Info__()
{
  int result; // eax

  result = GetAppSteamAppId(eSourceApp: k_App_CSS15);
  CStrike15Info.steamAppID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105BFF90
// Name: _dynamic_initializer_for__HL2DMInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__HL2DMInfo__()
{
  int result; // eax

  result = GetAppSteamAppId(eSourceApp: k_App_HL2MP);
  HL2DMInfo.steamAppID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105BFFA0
// Name: _dynamic_initializer_for__DODInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__DODInfo__()
{
  int result; // eax

  result = GetAppSteamAppId(eSourceApp: k_App_DODS);
  DODInfo.steamAppID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105BFFB0
// Name: _dynamic_initializer_for__Episode1Info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Episode1Info__()
{
  int result; // eax

  result = GetAppSteamAppId(eSourceApp: k_App_HL2_EP1);
  Episode1Info.steamAppID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105BFFC0
// Name: _dynamic_initializer_for__Episode2Info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Episode2Info__()
{
  int result; // eax

  result = GetAppSteamAppId(eSourceApp: k_App_HL2_EP2);
  Episode2Info.steamAppID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105BFFD0
// Name: _dynamic_initializer_for__TF2Info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__TF2Info__()
{
  int result; // eax

  result = GetAppSteamAppId(eSourceApp: k_App_TF2);
  TF2Info.steamAppID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105BFFE0
// Name: _dynamic_initializer_for__PortalInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__PortalInfo__()
{
  int result; // eax

  result = GetAppSteamAppId(eSourceApp: k_App_PORTAL);
  PortalInfo.steamAppID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105BFFF0
// Name: _dynamic_initializer_for__SwarmInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__SwarmInfo__()
{
  int result; // eax

  result = GetAppSteamAppId(eSourceApp: k_App_SWARM);
  SwarmInfo.steamAppID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105CA000
// Name: _dynamic_atexit_destructor_for__g_syncmesh_saveloadhandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_syncmesh_saveloadhandler__()
{
  g_syncmesh_saveloadhandler.__vftable = (CSyncMesh_SaveLoadHandler_vtbl *)&CSyncMesh_SaveLoadHandler::`vftable';
  CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(this: &g_syncmesh_saveloadhandler);
}

//------------------------------------------------------------------------------
// Address: 0x105CA050
// Name: _dynamic_atexit_destructor_for__g_ToolHandlerSyncMesh__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ToolHandlerSyncMesh__()
{
  CToolHandler_SyncMesh::~CToolHandler_SyncMesh(this: &g_ToolHandlerSyncMesh);
}

//------------------------------------------------------------------------------
// Address: 0x105CA060
// Name: _dynamic_atexit_destructor_for__g_HammerIpcServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_HammerIpcServer__()
{
  g_HammerIpcServer.__vftable = (CHammerIpcServer_vtbl *)&CValveIpcServer::`vftable';
  CValveIpcServer::Unregister(this: &g_HammerIpcServer);
  if ( g_HammerIpcServer.m_szServerName != nullptr )
  {
    operator delete(p: g_HammerIpcServer.m_szServerName);
    g_HammerIpcServer.m_szServerName = nullptr;
  }
}
