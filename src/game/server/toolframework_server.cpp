// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/toolframework_server.cpp
// Functions: 9
// ============================================================

#include "game\server\toolframework_server.h"

//------------------------------------------------------------------------------
// Address: 0x10337980
// Name: public: virtual bool CToolFrameworkServer::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkServer::Init(CToolFrameworkServer *this)
{
  IServerEngineTools *v2; // eax
  bool result; // al
  factorylist_t list; // [esp+4h] [ebp-Ch] BYREF

  FactoryList_Retrieve(destData: &list);
  v2 = (IServerEngineTools *)list.engineFactory(a1: "VSERVERENGINETOOLS001", a2: 0);
  this->m_pTools = v2;
  if ( v2 != nullptr )
    return true;
  result = engine->IsDedicatedServer(this: engine);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103379D0
// Name: public: virtual void CToolFrameworkServer::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkServer::LevelInitPreEntity(CToolFrameworkServer *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->LevelInitPreEntityAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x103379F0
// Name: public: virtual void CToolFrameworkServer::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkServer::LevelInitPostEntity(CToolFrameworkServer *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->LevelInitPostEntityAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10337A10
// Name: public: virtual void CToolFrameworkServer::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkServer::LevelShutdownPreEntity(CToolFrameworkServer *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->LevelShutdownPreEntityAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10337A30
// Name: public: virtual void CToolFrameworkServer::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkServer::LevelShutdownPostEntity(CToolFrameworkServer *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->LevelShutdownPostEntityAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10337A50
// Name: public: virtual void CToolFrameworkServer::FrameUpdatePreEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkServer::FrameUpdatePreEntityThink(CToolFrameworkServer *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->FrameUpdatePreEntityThinkAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10337A70
// Name: public: virtual void CToolFrameworkServer::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkServer::FrameUpdatePostEntityThink(CToolFrameworkServer *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->FrameUpdatePostEntityThinkAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10337A90
// Name: public: virtual void CToolFrameworkServer::PreClientUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkServer::PreClientUpdate(CToolFrameworkServer *this)
{
  if ( this->m_pTools != nullptr )
    this->m_pTools->PreClientUpdateAllTools(this: this->m_pTools);
}

//------------------------------------------------------------------------------
// Address: 0x10337AB0
// Name: public: virtual void CToolFrameworkServer::PreSetupVisibility(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkServer::PreSetupVisibility(CToolFrameworkServer *this)
{
  if ( this->m_pNext != nullptr )
    this->m_pNext->SafeRemoveIfDesired(this: this->m_pNext);
}
