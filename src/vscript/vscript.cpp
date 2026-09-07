// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/vscript.cpp
// Functions: 16
// ============================================================

#include "vscript\vscript.h"

//------------------------------------------------------------------------------
// Address: 0x10025C10
// Name: public: virtual class IScriptVM __near * CScriptManager::CreateVM(enum ScriptLanguage_t)
// Source: json
//------------------------------------------------------------------------------
CSquirrelVM *__thiscall CScriptManager::CreateVM(CScriptManager *this, ScriptLanguage_t language)
{
  CSquirrelVM *result; // eax
  void *v3; // eax
  CSquirrelVM *v4; // ecx
  CSquirrelVM *v5; // eax
  CSquirrelVM *v6; // esi
  float (__cdecl *v7)(float, float); // [esp+0h] [ebp-8h]
  int (__cdecl *v8)(int, int); // [esp+0h] [ebp-8h]

  result = nullptr;
  if ( language != SL_SQUIRREL )
  {
    if ( language != SL_LUA )
      return result;
    v5 = (CSquirrelVM *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24);
    if ( v5 != nullptr )
    {
      v5->__vftable = (CSquirrelVM_vtbl *)&CLuaVM::`vftable';
      v5->m_hVM = nullptr;
      v5->m_hOnCreateScopeFunc._unVal.nInteger = 0;
      v5->m_hOnReleaseScopeFunc._type = 0;
      v5->m_hDbg = nullptr;
      v5->m_hOnCreateScopeFunc._type = 0;
      goto LABEL_8;
    }
    return nullptr;
  }
  v3 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 168);
  if ( v3 == nullptr )
    return nullptr;
  v5 = CSquirrelVM::CSquirrelVM(this: v4, a2: (int)v3);
LABEL_8:
  v6 = v5;
  if ( v5 != nullptr )
  {
    v5->Init(this: v5);
    if ( (`CScriptManager::CreateVM'::`14'::`local static guard' & 1) == 0 )
    {
      `CScriptManager::CreateVM'::`14'::`local static guard' |= 1u;
      `CScriptManager::CreateVM'::`14'::binding.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
      `CScriptManager::CreateVM'::`14'::binding.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
      `CScriptManager::CreateVM'::`14'::binding.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
      `CScriptManager::CreateVM'::`14'::binding.m_desc.m_Parameters.m_Size = 0;
      `CScriptManager::CreateVM'::`14'::binding.m_desc.m_Parameters.m_pElements = nullptr;
      `CScriptManager::CreateVM'::`14'::binding.m_desc.m_pszFunction = nullptr;
      `CScriptManager::CreateVM'::`14'::binding.m_desc.m_ReturnType = 31;
      `CScriptManager::CreateVM'::`14'::binding.m_desc.m_pszDescription = nullptr;
      atexit(func: `CScriptManager::CreateVM'::`14'::`dynamic atexit destructor for 'binding'');
    }
    `CScriptManager::CreateVM'::`14'::binding.m_desc.m_pszScriptName = "RandomFloat";
    `CScriptManager::CreateVM'::`14'::binding.m_desc.m_pszFunction = "RandomFloat";
    `CScriptManager::CreateVM'::`14'::binding.m_desc.m_pszDescription = "Generate a random floating point number within a"
                                                                        " range, inclusive";
    `CScriptManager::CreateVM'::`14'::binding.m_desc.m_Parameters.m_Size = 0;
    ScriptDeduceFunctionSignature<float,float,float>(
      pDesc: &`CScriptManager::CreateVM'::`14'::binding.m_desc,
      pfnProxied: v7);
    `CScriptManager::CreateVM'::`14'::binding.m_pFunction = (void *)_RandomFloat;
    `CScriptManager::CreateVM'::`14'::binding.m_pfnBinding = CNonMemberScriptBinding2<float (__cdecl *)(float,float),float,float,float>::Call;
    v6->RegisterFunction(this: v6, a2: &`CScriptManager::CreateVM'::`14'::binding);
    if ( (`CScriptManager::CreateVM'::`14'::`local static guard' & 2) == 0 )
    {
      `CScriptManager::CreateVM'::`14'::`local static guard' |= 2u;
      `CScriptManager::CreateVM'::`23'::binding.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
      `CScriptManager::CreateVM'::`23'::binding.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
      `CScriptManager::CreateVM'::`23'::binding.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
      `CScriptManager::CreateVM'::`23'::binding.m_desc.m_Parameters.m_Size = 0;
      `CScriptManager::CreateVM'::`23'::binding.m_desc.m_Parameters.m_pElements = nullptr;
      `CScriptManager::CreateVM'::`23'::binding.m_desc.m_pszFunction = nullptr;
      `CScriptManager::CreateVM'::`23'::binding.m_desc.m_ReturnType = 31;
      `CScriptManager::CreateVM'::`23'::binding.m_desc.m_pszDescription = nullptr;
      atexit(func: `CScriptManager::CreateVM'::`23'::`dynamic atexit destructor for 'binding'');
    }
    `CScriptManager::CreateVM'::`23'::binding.m_desc.m_pszScriptName = "RandomInt";
    `CScriptManager::CreateVM'::`23'::binding.m_desc.m_pszFunction = "RandomInt";
    `CScriptManager::CreateVM'::`23'::binding.m_desc.m_pszDescription = "Generate a random integer within a range, inclusive";
    `CScriptManager::CreateVM'::`23'::binding.m_desc.m_Parameters.m_Size = 0;
    ScriptDeduceFunctionSignature<int,int,int>(pDesc: &`CScriptManager::CreateVM'::`23'::binding.m_desc, pfnProxied: v8);
    `CScriptManager::CreateVM'::`23'::binding.m_pFunction = _RandomInt;
    `CScriptManager::CreateVM'::`23'::binding.m_pfnBinding = CNonMemberScriptBinding2<int (__cdecl *)(int,int),int,int,int>::Call;
    v6->RegisterFunction(this: v6, a2: &`CScriptManager::CreateVM'::`23'::binding);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10025DE0
// Name: public: virtual void CScriptManager::DestroyVM(class IScriptVM __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptManager::DestroyVM(CScriptManager *this, CSquirrelVM *p)
{
  CSquirrelVM *v2; // ecx

  if ( p != nullptr )
  {
    p->Shutdown(this: p);
    if ( p->GetLanguage(this: p) == SL_SQUIRREL )
    {
      CSquirrelVM::~CSquirrelVM(this: v2, thisa: p);
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p);
    }
    else if ( p->GetLanguage(this: p) == SL_LUA )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025E50
// Name: public: virtual bool CTier1AppSystem<class IScriptManager,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier1AppSystem<IScriptManager,0>::Connect(
        CTier1AppSystem<IScriptManager,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025E70
// Name: public: virtual void CTier1AppSystem<class IScriptManager,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTier1AppSystem<IScriptManager,0>::Disconnect(CTier1AppSystem<IScriptManager,0> *this)
{
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10025E80
// Name: public: virtual enum InitReturnVal_t CTier1AppSystem<class IScriptManager,0>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier1AppSystem<IScriptManager,0>::Init(CTier1AppSystem<IScriptManager,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025EA0
// Name: public: virtual void CTier1AppSystem<class IScriptManager,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier1AppSystem<IScriptManager,0>::Shutdown(CTier1AppSystem<IScriptManager,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10025EB0
// Name: public: virtual enum AppSystemTier_t CTier1AppSystem<class IScriptManager,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier1AppSystem<IScriptManager,0>::GetTier(CTier1AppSystem<IScriptManager,0> *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025EC0
// Name: public: virtual void __near * CBaseAppSystem<class IScriptManager>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseAppSystem<IScriptManager>::QueryInterface(
        CBaseAppSystem<IScriptManager> *this,
        const char *pInterfaceName)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10025ED0
// Name: public: virtual void CBaseAppSystem<class IScriptManager>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IScriptManager>::Reconnect(
        CBaseAppSystem<IScriptManager> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10025F50
// Name: void ScriptDeduceFunctionSignature<float,float,float>(struct ScriptFuncDescriptor_t __near *,float (*)(float,float))
// Source: json
//------------------------------------------------------------------------------
void __usercall ScriptDeduceFunctionSignature<float,float,float>(ScriptFuncDescriptor_t *pDesc@<eax>, int a2@<esi>)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // edi
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_nAllocationCount; // eax
  int m_Size; // esi
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // eax
  int v10; // esi
  int v11; // eax
  int *v12; // ecx
  int v13; // eax
  int *v14; // eax
  int v15; // [esp-4h] [ebp-Ch]

  pDesc->m_ReturnType = 1;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v3 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(int *, int))v3->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v4;
  }
  p_m_Parameters->m_pElements = p_m_Parameters->m_Memory.m_pMemory;
  m_nAllocationCount = p_m_Parameters->m_Memory.m_nAllocationCount;
  v15 = a2;
  m_Size = p_m_Parameters->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<int,int> *)(m_Size - m_nAllocationCount + 1), num: v15);
  ++p_m_Parameters->m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v8 = p_m_Parameters->m_Size - m_Size - 1;
  p_m_Parameters->m_pElements = p_m_Parameters->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = 1;
  v10 = p_m_Parameters->m_Size;
  v11 = p_m_Parameters->m_Memory.m_nAllocationCount;
  if ( v10 + 1 > v11 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<int,int> *)(v10 - v11 + 1), num: v15);
  ++p_m_Parameters->m_Size;
  v12 = p_m_Parameters->m_Memory.m_pMemory;
  v13 = p_m_Parameters->m_Size - v10 - 1;
  p_m_Parameters->m_pElements = p_m_Parameters->m_Memory.m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 4 * v13);
  v14 = &p_m_Parameters->m_Memory.m_pMemory[v10];
  if ( v14 != nullptr )
    *v14 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026040
// Name: void ScriptDeduceFunctionSignature<int,int,int>(struct ScriptFuncDescriptor_t __near *,int (*)(int,int))
// Source: json
//------------------------------------------------------------------------------
void __usercall ScriptDeduceFunctionSignature<int,int,int>(ScriptFuncDescriptor_t *pDesc@<eax>)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // edi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // esi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // [esp+0h] [ebp-8h]

  pDesc->m_ReturnType = 5;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  p_m_Parameters->m_pElements = p_m_Parameters->m_Memory.m_pMemory;
  m_Size = p_m_Parameters->m_Size;
  m_nAllocationCount = p_m_Parameters->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<int,int> *)(m_Size - m_nAllocationCount + 1), num: v14);
  ++p_m_Parameters->m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = p_m_Parameters->m_Size - m_Size - 1;
  p_m_Parameters->m_pElements = p_m_Parameters->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 5;
  v9 = p_m_Parameters->m_Size;
  v10 = p_m_Parameters->m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<int,int> *)(v9 - v10 + 1), num: v14);
  ++p_m_Parameters->m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = p_m_Parameters->m_Size - v9 - 1;
  p_m_Parameters->m_pElements = p_m_Parameters->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 5;
}

//------------------------------------------------------------------------------
// Address: 0x10026130
// Name: public: static bool CNonMemberScriptBinding2<float (*)(float,float),float,float,float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding2<float (__cdecl *)(float,float),float,float,float>::Call(
        double (__cdecl *pFunction)(int, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 2 || pReturn == nullptr || pContext != nullptr )
    return 0;
  pReturn->m_float = pFunction(a1: pArguments->m_int, a2: pArguments[1].m_int);
  pReturn->m_type = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026180
// Name: public: static bool CNonMemberScriptBinding2<int (*)(int,int),int,int,int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding2<int (__cdecl *)(int,int),int,int,int>::Call(
        int (__cdecl *pFunction)(int, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 2 || pReturn == nullptr || pContext != nullptr )
    return 0;
  pReturn->m_int = pFunction(a1: pArguments->m_int, a2: pArguments[1].m_int);
  pReturn->m_type = 5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100261C0
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlMemory<int,int>::Grow(CUtlMemory<int,int> *this@<ecx>, int a2@<edi>)
{
  int v2; // esi
  int v3; // eax
  int v4; // ecx
  void *v5; // edx
  unsigned int v6; // [esp-4h] [ebp-8h]

  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 >= 0 )
  {
    v3 = *(_DWORD *)(a2 + 4);
    v4 = (int)this + v3;
    if ( v2 != 0 )
    {
      v3 = v2 * ((v4 - 1) / v2 + 1);
    }
    else
    {
      if ( v3 == 0 )
        v3 = 8;
      if ( v3 >= v4 )
        goto LABEL_13;
      do
        v3 *= 2;
      while ( v3 < v4 );
    }
    if ( v3 < v4 )
    {
      if ( v3 != 0 || v4 > -1 )
      {
        do
          v3 = (v4 + v3) / 2;
        while ( v3 < v4 );
      }
      else
      {
        v3 = -1;
      }
    }
LABEL_13:
    v5 = *(void **)a2;
    *(_DWORD *)(a2 + 4) = v3;
    v6 = 4 * v3;
    if ( v5 != nullptr )
      *(_DWORD *)a2 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v5, a3: v6);
    else
      *(_DWORD *)a2 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CDC0
// Name: public: void CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
        CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Realloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: m_pMemory,
                                                                             a3: v7);
    else
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Alloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025E40
// Name: __CreateCScriptManagerIScriptManager_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CScriptManager *__cdecl _CreateCScriptManagerIScriptManager_interface()
{
  return &g_ScriptManager;
}
