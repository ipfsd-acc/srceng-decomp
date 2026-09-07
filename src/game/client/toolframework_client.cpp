// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/toolframework_client.cpp
// Functions: 14
// ============================================================

#include "game\client\toolframework_client.h"

//------------------------------------------------------------------------------
// Address: 0x10271900
// Name: bool ToolsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ToolsEnabled()
{
  return g_ToolFrameworkClient.m_pTools != nullptr
      && g_ToolFrameworkClient.m_pTools->InToolMode(this: g_ToolFrameworkClient.m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10271920
// Name: class IGameSystem __near * ToolFrameworkClientSystem(void)
// Source: json
//------------------------------------------------------------------------------
CToolFrameworkClient *__cdecl ToolFrameworkClientSystem()
{
  return &g_ToolFrameworkClient;
}

//------------------------------------------------------------------------------
// Address: 0x10271930
// Name: public: virtual bool CToolFrameworkClient::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkClient::Init(CToolFrameworkClient *this)
{
  IClientEngineTools *v2; // eax
  factorylist_t list; // [esp+4h] [ebp-4h] BYREF

  FactoryList_Retrieve(destData: &list);
  v2 = (IClientEngineTools *)list.appSystemFactory(a1: "VCLIENTENGINETOOLS001", a2: nullptr);
  this->m_pTools = v2;
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10271960
// Name: public: virtual void CToolFrameworkClient::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkClient::LevelInitPreEntity(CToolFrameworkClient *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->LevelInitPreEntityAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10271980
// Name: public: virtual void CToolFrameworkClient::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkClient::LevelInitPostEntity(CToolFrameworkClient *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->LevelInitPostEntityAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x102719A0
// Name: public: virtual void CToolFrameworkClient::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkClient::LevelShutdownPreEntity(CToolFrameworkClient *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->LevelShutdownPreEntityAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x102719C0
// Name: public: virtual void CToolFrameworkClient::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkClient::LevelShutdownPostEntity(CToolFrameworkClient *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->LevelShutdownPostEntityAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x102719E0
// Name: public: virtual void CToolFrameworkClient::PreRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkClient::PreRender(CToolFrameworkClient *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->PreRenderAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10271A00
// Name: public: virtual void CToolFrameworkClient::PostRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkClient::PostRender(CToolFrameworkClient *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->PostRenderAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10271A20
// Name: bool ToolFramework_IsThirdPersonCamera(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ToolFramework_IsThirdPersonCamera()
{
  return g_ToolFrameworkClient.m_pTools != nullptr
      && g_ToolFrameworkClient.m_pTools->IsThirdPersonCamera(this: g_ToolFrameworkClient.m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10271A40
// Name: void ToolFramework_PostToolMessage(unsigned int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolFramework_PostToolMessage(unsigned int hEntity, KeyValues *msg)
{
  if ( g_ToolFrameworkClient.m_pTools != nullptr )
    g_ToolFrameworkClient.m_pTools->PostToolMessage(this: g_ToolFrameworkClient.m_pTools, a2: hEntity, a3: msg);
}

//------------------------------------------------------------------------------
// Address: 0x10271A60
// Name: void ToolFramework_AdjustEngineViewport(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolFramework_AdjustEngineViewport(int *x, int *y, int *width, int *height)
{
  if ( g_ToolFrameworkClient.m_pTools != nullptr )
    g_ToolFrameworkClient.m_pTools->AdjustEngineViewport(
      this: g_ToolFrameworkClient.m_pTools,
      a2: x,
      a3: y,
      a4: width,
      a5: height);
}

//------------------------------------------------------------------------------
// Address: 0x10271A90
// Name: bool ToolFramework_SetupEngineView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ToolFramework_SetupEngineView(Vector *origin, QAngle *angles, float *fov)
{
  return g_ToolFrameworkClient.m_pTools != nullptr
      && g_ToolFrameworkClient.m_pTools->SetupEngineView(
           this: g_ToolFrameworkClient.m_pTools,
           a2: origin,
           a3: angles,
           a4: fov);
}

//------------------------------------------------------------------------------
// Address: 0x10271AC0
// Name: bool ToolFramework_SetupAudioState(struct AudioState_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ToolFramework_SetupAudioState(AudioState_t *audioState)
{
  return g_ToolFrameworkClient.m_pTools != nullptr
      && g_ToolFrameworkClient.m_pTools->SetupAudioState(this: g_ToolFrameworkClient.m_pTools, a2: audioState);
}
