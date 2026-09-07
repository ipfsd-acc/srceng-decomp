// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdllib/mdllib.cpp
// Functions: 7
// ============================================================

#include "mdllib\mdllib.h"

//------------------------------------------------------------------------------
// Address: 0x10001010
// Name: public: virtual bool CMdlLib::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMdlLib::Connect(CMdlLib *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001020
// Name: public: virtual enum InitReturnVal_t CMdlLib::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMdlLib::Init(CMdlLib *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: public: virtual void __near * CMdlLib::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMdlLib::QueryInterface(CMdlLib *this, const char *pInterfaceName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  return FactoryThis(a1: pInterfaceName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10001050
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<class IMdlLib>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CBaseAppSystem<IMdlLib>::GetDependencies(CBaseAppSystem<IMdlLib> *this)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001060
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<class IMdlLib>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IMdlLib>::GetTier(CBaseAppSystem<IMdlLib> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10001070
// Name: public: virtual void CBaseAppSystem<class IMdlLib>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IMdlLib>::Reconnect(
        CBaseAppSystem<IMdlLib> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: __CreateCMdlLibIMdlLib_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMdlLib *__cdecl _CreateCMdlLibIMdlLib_interface()
{
  return &s_Mdllib;
}
