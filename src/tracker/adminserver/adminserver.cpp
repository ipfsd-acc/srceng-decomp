// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/adminserver.cpp
// Functions: 9
// ============================================================

#include "tracker\adminserver\adminserver.h"

//------------------------------------------------------------------------------
// Address: 0x10001050
// Name: public: virtual bool CAdminServer::Initialize(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAdminServer::Initialize(
        CAdminServer *this,
        void *(__cdecl **factorylist)(const char *, int *),
        int factoryCount)
{
  vgui::PropertyPage *v3; // ecx
  int i; // esi
  CRemoteServer *v5; // eax

  ConnectTier1Libraries(pFactoryList: factorylist, nFactoryCount: factoryCount);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(pFactoryList: factorylist, nFactoryCount: factoryCount);
  vgui::PropertyPage::OnPageHide(this: v3);
  for ( i = 0; i < factoryCount; ++i )
  {
    if ( g_pGameServerData == nullptr )
      g_pGameServerData = (IGameServerData *)factorylist[i](a1: "GameServerData001", a2: nullptr);
    if ( g_pVProfExport == nullptr )
      g_pVProfExport = (IVProfExport *)factorylist[i](a1: "VProfExport001", a2: nullptr);
  }
  v5 = RemoteServer();
  CRemoteServer::Initialize(this: v5);
  if ( !vgui::VGui_InitInterfacesList(moduleName: "AdminServer", factoryList: factorylist, numFactories: factoryCount) )
    return 0;
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "admin/admin_%language%.txt", a3: nullptr, a4: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001110
// Name: public: virtual bool CAdminServer::PostInitialize(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAdminServer::PostInitialize(
        CAdminServer *this,
        void *(__cdecl **modules)(const char *, int *),
        void *(__cdecl **factoryCount)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001120
// Name: public: virtual void CAdminServer::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAdminServer::Shutdown(CAdminServer *this)
{
  vgui::PropertyPage::OnPageHide((vgui::PropertyPage *)this);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10001140
// Name: public: virtual void CAdminServer::SetParent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAdminServer::SetParent(CAdminServer *this, CAdminServer::OpenedManageDialog_t *parent)
{
  this->m_OpenedManageDialog.m_pElements = parent;
}

//------------------------------------------------------------------------------
// Address: 0x10001150
// Name: public: void CUtlMemory<struct CAdminServer::OpenedManageDialog_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CAdminServer::OpenedManageDialog_t,int>::Grow(
        CUtlMemory<vgui::PropertySheet::Page_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::PropertySheet::Page_t *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::PropertySheet::Page_t *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v7);
    else
      this->m_pMemory = (vgui::PropertySheet::Page_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100011F0
// Name: public: virtual class IManageServer __near * CAdminServer::GetManageServerInterface(unsigned int)
// Source: json
//------------------------------------------------------------------------------
IManageServer *__thiscall CAdminServer::GetManageServerInterface(CAdminServer *this, signed int handle)
{
  IManageServer *result; // eax

  if ( handle < 1 || handle > this->m_OpenedManageDialog.m_Size )
    return nullptr;
  result = (IManageServer *)g_pVGui->HandleToPanel(
                              this: g_pVGui,
                              a2: this->m_OpenedManageDialog.m_Memory.m_pMemory[handle].handle);
  if ( result != nullptr )
    return this->m_OpenedManageDialog.m_Memory.m_pMemory[handle].manageInterface;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001300
// Name: public: virtual unsigned int CAdminServer::OpenManageServerDialog(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAdminServer::OpenManageServerDialog(CAdminServer *this, const char *serverName, const char *gameDir)
{
  CGamePanelInfo *v4; // eax
  CGamePanelInfo *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CAdminServer::OpenedManageDialog_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax
  CAdminServer::OpenedManageDialog_t *v12; // [esp+Ch] [ebp-4h]
  vgui::IVGui_vtbl *serverNamea; // [esp+18h] [ebp+8h]
  const char *gameDira; // [esp+1Ch] [ebp+Ch]

  v4 = (CGamePanelInfo *)operator new(nSize: 0x254u);
  if ( v4 != nullptr )
    v5 = CGamePanelInfo::CGamePanelInfo(this: v4, parent: nullptr, name: serverName, mod: gameDir);
  else
    v5 = nullptr;
  v5->SetParent(this: v5, a2: this->m_hParent);
  m_Size = this->m_OpenedManageDialog.m_Size;
  m_nAllocationCount = this->m_OpenedManageDialog.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAdminServer::OpenedManageDialog_t,int>::Grow(
      this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_OpenedManageDialog,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_OpenedManageDialog.m_Size;
  m_pMemory = this->m_OpenedManageDialog.m_Memory.m_pMemory;
  v9 = this->m_OpenedManageDialog.m_Size - m_Size - 1;
  this->m_OpenedManageDialog.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v9);
  gameDira = (const char *)g_pVGui;
  v12 = &this->m_OpenedManageDialog.m_Memory.m_pMemory[m_Size];
  serverNamea = g_pVGui->__vftable;
  v10 = v5->GetVPanel(this: v5);
  v12->handle = serverNamea->PanelToHandle(this: (vgui::IVGui *)gameDira, a2: v10);
  this->m_OpenedManageDialog.m_Memory.m_pMemory[m_Size].manageInterface = &v5->IManageServer;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: __CreateCAdminServerIAdminServer_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAdminServer *__cdecl _CreateCAdminServerIAdminServer_interface()
{
  return &g_AdminServerSingleton;
}

//------------------------------------------------------------------------------
// Address: 0x10001040
// Name: __CreateCAdminServerIVGuiModule_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IVGuiModule *__cdecl _CreateCAdminServerIVGuiModule_interface()
{
  return &g_AdminServerSingleton.IVGuiModule;
}
