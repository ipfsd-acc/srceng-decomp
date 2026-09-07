// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/vscript_server.cpp
// Functions: 130
// ============================================================

#include "game\server\vscript_server.h"

//------------------------------------------------------------------------------
// Address: 0x10050D80
// Name: public: static bool CDefOps<class CChoreoActor __near *>::LessFunc(class CChoreoActor __near * const __near &,class CChoreoActor __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<CChoreoActor *>::LessFunc(void *const *lhs, void *const *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x10097D80
// Name: struct ScriptClassDesc_t __near * GetScriptDesc(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc()
{
  return &g_CBaseAnimating_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x10098B40
// Name: public: static bool CMemberScriptBinding1<class CBaseAnimating __near *,class Vector const __near & (CBaseAnimating::*)(int),class Vector const __near &,int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CBaseAnimating *,Vector const & (__thiscall CBaseAnimating::*)(int),Vector const &,int>::Call(
        int (__stdcall *pFunction)(int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  int v5; // eax
  _DWORD *v6; // eax
  int m_int; // ecx

  if ( nArguments != 1 || pReturn == nullptr || pContext == nullptr )
    return 0;
  v5 = pFunction(a1: pArguments->m_int);
  pReturn->m_type = 3;
  pReturn->m_int = v5;
  v6 = operator new(nSize: 0xCu);
  if ( v6 != nullptr )
  {
    m_int = pReturn->m_int;
    *(_QWORD *)v6 = *(_QWORD *)pReturn->m_int;
    v6[2] = *(_DWORD *)(m_int + 8);
    pReturn->m_int = (int)v6;
  }
  else
  {
    pReturn->m_int = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B37D0
// Name: struct ScriptClassDesc_t __near * GetScriptDesc(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc()
{
  return &g_CBaseEntity_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x100B73A0
// Name: public: static bool CMemberScriptBinding0<class CBaseEntity __near *,class Vector const __near & (CBaseEntity::*)(void),class Vector const __near &>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  int v5; // eax
  _DWORD *v6; // eax
  int m_int; // ecx

  if ( nArguments != 0 || pReturn == nullptr || pContext == nullptr )
    return 0;
  v5 = pFunction();
  pReturn->m_type = 3;
  pReturn->m_int = v5;
  v6 = operator new(nSize: 0xCu);
  if ( v6 != nullptr )
  {
    m_int = pReturn->m_int;
    *(_QWORD *)v6 = *(_QWORD *)pReturn->m_int;
    v6[2] = *(_DWORD *)(m_int + 8);
    pReturn->m_int = (int)v6;
  }
  else
  {
    pReturn->m_int = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B7400
// Name: public: static bool CMemberScriptBinding1<class CBaseEntity __near *,void (CBaseEntity::*)(class Vector const __near &),void,class Vector const __near &>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(Vector const &),void,Vector const &>::Call(
        void (__thiscall *pFunction)(void *, const Vector *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const Vector *v5; // eax

  if ( nArguments != 1 || pReturn != nullptr || pContext == nullptr )
    return 0;
  v5 = ScriptVariant_t::operator Vector const &(this: pArguments);
  pFunction(a1: pContext, a2: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B7480
// Name: public: static bool CMemberScriptBinding0<class CEnvEntityMaker __near *,void (CEnvEntityMaker::*)(void),void>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding0<CEnvEntityMaker *,void (__thiscall CEnvEntityMaker::*)(void),void>::Call(
        void (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn != nullptr || pContext == nullptr )
    return 0;
  pFunction();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B74B0
// Name: public: static bool CMemberScriptBinding1<class CBaseEntity __near *,void (CBaseEntity::*)(struct HSCRIPT__ __near *),void,struct HSCRIPT__ __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(HSCRIPT__ *),void,HSCRIPT__ *>::Call(
        void (__stdcall *pFunction)(int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 1 || pReturn != nullptr || pContext == nullptr )
    return 0;
  pFunction(a1: pArguments->m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B74E0
// Name: public: static bool CMemberScriptBinding0<class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(void),struct HSCRIPT__ __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext == nullptr )
    return 0;
  pReturn->m_int = pFunction();
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B75B0
// Name: public: static bool CMemberScriptBinding2<class CBaseEntity __near *,bool (CBaseEntity::*)(char const __near *,class Vector const __near &),bool,char const __near *,class Vector const __near &>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CBaseEntity *,bool (__thiscall CBaseEntity::*)(char const *,Vector const &),bool,char const *,Vector const &>::Call(
        int (__thiscall *pFunction)(void *, const char *, const Vector *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // esi
  const Vector *v6; // eax

  if ( nArguments != 2 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  v6 = ScriptVariant_t::operator Vector const &(this: pArguments + 1);
  pReturn->m_char = pFunction(a1: pContext, a2: m_int, a3: v6);
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CF020
// Name: struct ScriptClassDesc_t __near * GetScriptDesc(class CBaseFlex __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc()
{
  return &g_CBaseFlex_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x100CF910
// Name: public: static bool CMemberScriptBinding1<class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(struct HSCRIPT__ __near *),struct HSCRIPT__ __near *,struct HSCRIPT__ __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *),HSCRIPT__ *,HSCRIPT__ *>::Call(
        int (__stdcall *pFunction)(int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 1 || pReturn == nullptr || pContext == nullptr )
    return 0;
  pReturn->m_int = pFunction(a1: pArguments->m_int);
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D7770
// Name: struct ScriptClassDesc_t __near * GetScriptDesc(class CBaseMultiplayerPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc()
{
  return &g_CBaseMultiplayerPlayer_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x10113680
// Name: struct ScriptClassDesc_t __near * GetScriptDesc<class CEnvEntityMaker>(class CEnvEntityMaker __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc<CEnvEntityMaker>()
{
  return &g_CEnvEntityMaker_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x10113870
// Name: public: static bool CMemberScriptBinding2<class CBaseEntity __near *,void (CBaseEntity::*)(class Vector const __near &,class Vector const __near &),void,class Vector const __near &,class Vector const __near &>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CBaseEntity *,void (__thiscall CBaseEntity::*)(Vector const &,Vector const &),void,Vector const &,Vector const &>::Call(
        void (__thiscall *pFunction)(void *, const Vector *, const Vector *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const Vector *v5; // eax
  const Vector *v7; // [esp-8h] [ebp-Ch]

  if ( nArguments != 2 || pReturn != nullptr || pContext == nullptr )
    return 0;
  v7 = ScriptVariant_t::operator Vector const &(this: pArguments + 1);
  v5 = ScriptVariant_t::operator Vector const &(this: pArguments);
  pFunction(a1: pContext, a2: v5, a3: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101148B0
// Name: void ScriptDeduceFunctionSignature<void,char const __near *>(struct ScriptFuncDescriptor_t __near *,void (*)(char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<void,char const *>(ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)32;
}

//------------------------------------------------------------------------------
// Address: 0x101B39A0
// Name: struct ScriptClassDesc_t __near * GetScriptDesc<class CBasePlayer>(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc<CBasePlayer>()
{
  return &g_CBasePlayer_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x101FE040
// Name: struct ScriptClassDesc_t __near * GetScriptDesc(class CSceneEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc()
{
  return &g_CSceneEntity_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x1023C860
// Name: struct ScriptClassDesc_t __near * GetScriptDesc<class CTriggerCamera>(class CTriggerCamera __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc<CTriggerCamera>()
{
  return &g_CTriggerCamera_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x1023CDD0
// Name: public: enum ScriptStatus_t IScriptVM::Call<char const __near *,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,float>(struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,bool,struct ScriptVariant_t __near *,char const __near *,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,float)
// Source: json
//------------------------------------------------------------------------------
ScriptStatus_t __thiscall IScriptVM::Call<char const *,HSCRIPT__ *,HSCRIPT__ *,HSCRIPT__ *,float>(
        IScriptVM *this,
        HSCRIPT__ *hFunction,
        HSCRIPT__ *hScope,
        BOOL bWait,
        ScriptVariant_t *pReturn,
        const char *arg1,
        HSCRIPT__ *arg2,
        HSCRIPT__ *arg3,
        HSCRIPT__ *arg4,
        float arg5)
{
  ScriptStatus_t (__thiscall *ExecuteFunction)(IScriptVM *, HSCRIPT__ *, ScriptVariant_t *, int, ScriptVariant_t *, HSCRIPT__ *, bool); // eax
  ScriptVariant_t args[5]; // [esp+0h] [ebp-28h] BYREF

  args[1].m_flags = 0;
  args[3].m_flags = 0;
  args[0].m_type = 32;
  args[1].m_type = 33;
  args[2].m_type = 33;
  args[3].m_type = 33;
  args[0].m_flags = 0;
  args[2].m_flags = 0;
  args[4].m_flags = 0;
  args[4].m_type = 1;
  args[0].m_int = (int)arg1;
  args[1].m_int = (int)arg2;
  args[2].m_int = (int)arg3;
  args[3].m_int = (int)arg4;
  ExecuteFunction = this->ExecuteFunction;
  args[4].m_float = arg5;
  return ExecuteFunction(this, a2: hFunction, a3: args, a4: 5, a5: pReturn, a6: hScope, a7: bWait);
}

//------------------------------------------------------------------------------
// Address: 0x1025D5D0
// Name: struct ScriptClassDesc_t __near * GetScriptDesc<class CScriptKeyValues>(class CScriptKeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc<CScriptKeyValues>()
{
  return &g_CScriptKeyValues_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x1025D5E0
// Name: public: int CScriptKeyValues::ScriptGetKeyValueInt(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptKeyValues::ScriptGetKeyValueInt(CScriptKeyValues *this, const char *pszName)
{
  return KeyValues::GetInt(this: this->m_pKeyValues, keyName: pszName, defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1025D600
// Name: public: float CScriptKeyValues::ScriptGetKeyValueFloat(char const __near *)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CScriptKeyValues::ScriptGetKeyValueFloat(CScriptKeyValues *this, const char *pszName)
{
  return KeyValues::GetFloat(this: this->m_pKeyValues, keyName: pszName, defaultValue: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1025D620
// Name: public: char const __near * CScriptKeyValues::ScriptGetKeyValueString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CScriptKeyValues::ScriptGetKeyValueString(CScriptKeyValues *this, const char *pszName)
{
  return KeyValues::GetString(this: this->m_pKeyValues, keyName: pszName, defaultValue: locale);
}

//------------------------------------------------------------------------------
// Address: 0x1025D640
// Name: public: bool CScriptKeyValues::ScriptIsKeyValueEmpty(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptKeyValues::ScriptIsKeyValueEmpty(CScriptKeyValues *this, const char *pszName)
{
  return KeyValues::IsEmpty(this: this->m_pKeyValues, keyName: pszName);
}

//------------------------------------------------------------------------------
// Address: 0x1025D650
// Name: public: void CScriptKeyValues::ScriptReleaseKeyValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptKeyValues::ScriptReleaseKeyValues(CScriptKeyValues *this)
{
  KeyValues::deleteThis(this: this->m_pKeyValues);
  this->m_pKeyValues = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025D670
// Name: public: CScriptKeyValues::CScriptKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CScriptKeyValues *__thiscall CScriptKeyValues::CScriptKeyValues(CScriptKeyValues *this, KeyValues *pKeyValues)
{
  this->m_pKeyValues = pKeyValues;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1025D680
// Name: FrameTime
// Source: json
//------------------------------------------------------------------------------
double __cdecl FrameTime()
{
  return gpGlobals->frametime;
}

//------------------------------------------------------------------------------
// Address: 0x1025D690
// Name: DoUniqueString
// Source: json
//------------------------------------------------------------------------------
char *__cdecl DoUniqueString(const char *pszBase)
{
  g_pScriptVM->GenerateUniqueKey(this: g_pScriptVM, a2: pszBase, a3: szBuf_1, a4: 512);
  return szBuf_1;
}

//------------------------------------------------------------------------------
// Address: 0x1025D6C0
// Name: DoRecordAchievementEvent
// Source: json
//------------------------------------------------------------------------------
void __cdecl DoRecordAchievementEvent(const char *pszAchievementname, int iPlayerIndex)
{
  CBasePlayer *v2; // eax

  if ( iPlayerIndex >= 0 )
  {
    v2 = nullptr;
    if ( iPlayerIndex <= 0 || (v2 = UTIL_PlayerByIndex(playerIndex: iPlayerIndex)) != nullptr )
      UTIL_RecordAchievementEvent(pszAchievementname, pPlayer: v2);
    else
      DevWarning(
        a1: "DoRecordAchievementEvent called with a player index that doesn't resolve to a player (%s, %d)!\n",
        pszAchievementname,
        iPlayerIndex);
  }
  else
  {
    DevWarning(
      a1: "DoRecordAchievementEvent called with invalid player index (%s, %d)!\n",
      pszAchievementname,
      iPlayerIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D720
// Name: bool IsEntityCreationAllowedInScripts(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsEntityCreationAllowedInScripts()
{
  return g_VScriptGameSystem.m_bAllowEntityCreationInScripts;
}

//------------------------------------------------------------------------------
// Address: 0x1025D730
// Name: class ISaveRestoreBlockHandler __near * GetVScriptSaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CVScriptSaveRestoreBlockHandler *__cdecl GetVScriptSaveRestoreBlockHandler()
{
  return &g_VScriptSaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x1025D740
// Name: public: static void __near * CScriptConstructor<class CScriptKeyValues>::Construct(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl CScriptConstructor<CScriptKeyValues>::Construct()
{
  _DWORD *result; // eax

  result = operator new(nSize: 4u);
  if ( result == nullptr )
    return nullptr;
  *result = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025D760
// Name: public: static bool CDefOps<char const __near *>::LessFunc(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDefOps<char const *>::LessFunc(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x1025D7C0
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::Next(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::Next(CScriptEntityIterator *this, HSCRIPT__ *hStartEntity)
{
  IScriptVM_vtbl *v2; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v4; // eax
  CBaseEntity *Ent; // eax

  if ( hStartEntity != nullptr )
  {
    v2 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc();
    v4 = (CBaseEntity *)v2->GetInstanceValue(this: g_pScriptVM, a2: hStartEntity, a3: ScriptDesc);
  }
  else
  {
    v4 = nullptr;
  }
  Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: v4);
  if ( Ent != nullptr )
    return CBaseEntity::GetScriptInstance(this: Ent);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025D810
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::CreateByClassname(char const __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::CreateByClassname(CScriptEntityIterator *this, const char *className)
{
  CBaseEntity *EntityByName; // eax

  EntityByName = CreateEntityByName(className, iForceEdictIndex: -1, bNotify: true);
  if ( EntityByName != nullptr )
    return CBaseEntity::GetScriptInstance(this: EntityByName);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025D840
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::FindByClassname(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::FindByClassname(
        CScriptEntityIterator *this,
        HSCRIPT__ *hStartEntity,
        const char *szName)
{
  IScriptVM_vtbl *v3; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v5; // eax
  CBaseEntity *EntityByClassname; // eax

  if ( hStartEntity != nullptr )
  {
    v3 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc();
    v5 = (CBaseEntity *)v3->GetInstanceValue(this: g_pScriptVM, a2: hStartEntity, a3: ScriptDesc);
  }
  else
  {
    v5 = nullptr;
  }
  EntityByClassname = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: v5, szName);
  if ( EntityByClassname != nullptr )
    return CBaseEntity::GetScriptInstance(this: EntityByClassname);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025D8A0
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::FindByName(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::FindByName(
        CScriptEntityIterator *this,
        HSCRIPT__ *hStartEntity,
        const char *szName)
{
  IScriptVM_vtbl *v3; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v5; // eax
  CBaseEntity *EntityByName; // eax

  if ( hStartEntity != nullptr )
  {
    v3 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc();
    v5 = (CBaseEntity *)v3->GetInstanceValue(this: g_pScriptVM, a2: hStartEntity, a3: ScriptDesc);
  }
  else
  {
    v5 = nullptr;
  }
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: v5,
                   szName,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    return CBaseEntity::GetScriptInstance(this: EntityByName);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025D900
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::FindInSphere(struct HSCRIPT__ __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::FindInSphere(
        CScriptEntityIterator *this,
        HSCRIPT__ *hStartEntity,
        const Vector *vecCenter,
        float flRadius)
{
  IScriptVM_vtbl *v4; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v6; // eax
  CBaseEntity *EntityInSphere; // eax

  if ( hStartEntity != nullptr )
  {
    v4 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc();
    v6 = (CBaseEntity *)v4->GetInstanceValue(this: g_pScriptVM, a2: hStartEntity, a3: ScriptDesc);
  }
  else
  {
    v6 = nullptr;
  }
  EntityInSphere = CGlobalEntityList::FindEntityInSphere(this: &gEntList, pStartEntity: v6, vecCenter, flRadius);
  if ( EntityInSphere != nullptr )
    return CBaseEntity::GetScriptInstance(this: EntityInSphere);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025D960
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::FindByTarget(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::FindByTarget(
        CScriptEntityIterator *this,
        HSCRIPT__ *hStartEntity,
        const char *szName)
{
  IScriptVM_vtbl *v3; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v5; // eax
  CBaseEntity *EntityByTarget; // eax

  if ( hStartEntity != nullptr )
  {
    v3 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc();
    v5 = (CBaseEntity *)v3->GetInstanceValue(this: g_pScriptVM, a2: hStartEntity, a3: ScriptDesc);
  }
  else
  {
    v5 = nullptr;
  }
  EntityByTarget = CGlobalEntityList::FindEntityByTarget(this: &gEntList, pStartEntity: v5, szName);
  if ( EntityByTarget != nullptr )
    return CBaseEntity::GetScriptInstance(this: EntityByTarget);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025D9C0
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::FindByModel(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::FindByModel(
        CScriptEntityIterator *this,
        HSCRIPT__ *hStartEntity,
        const char *szModelName)
{
  IScriptVM_vtbl *v3; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v5; // eax
  CBaseEntity *EntityByModel; // eax

  if ( hStartEntity != nullptr )
  {
    v3 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc();
    v5 = (CBaseEntity *)v3->GetInstanceValue(this: g_pScriptVM, a2: hStartEntity, a3: ScriptDesc);
  }
  else
  {
    v5 = nullptr;
  }
  EntityByModel = CGlobalEntityList::FindEntityByModel(this: &gEntList, pStartEntity: v5, szModelName);
  if ( EntityByModel != nullptr )
    return CBaseEntity::GetScriptInstance(this: EntityByModel);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025DA20
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::FindByNameNearest(char const __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::FindByNameNearest(
        CScriptEntityIterator *this,
        const char *szName,
        const Vector *vecSrc,
        float flRadius)
{
  CBaseEntity *EntityByNameNearest; // eax

  EntityByNameNearest = CGlobalEntityList::FindEntityByNameNearest(
                          this: &gEntList,
                          szName,
                          vecSrc,
                          flRadius,
                          pSearchingEntity: nullptr,
                          pActivator: nullptr,
                          pCaller: nullptr);
  if ( EntityByNameNearest != nullptr )
    return CBaseEntity::GetScriptInstance(this: EntityByNameNearest);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025DA60
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::FindByNameWithin(struct HSCRIPT__ __near *,char const __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::FindByNameWithin(
        CScriptEntityIterator *this,
        HSCRIPT__ *hStartEntity,
        const char *szName,
        const Vector *vecSrc,
        float flRadius)
{
  IScriptVM_vtbl *v5; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v7; // eax
  CBaseEntity *EntityByNameWithin; // eax

  if ( hStartEntity != nullptr )
  {
    v5 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc();
    v7 = (CBaseEntity *)v5->GetInstanceValue(this: g_pScriptVM, a2: hStartEntity, a3: ScriptDesc);
  }
  else
  {
    v7 = nullptr;
  }
  EntityByNameWithin = CGlobalEntityList::FindEntityByNameWithin(
                         this: &gEntList,
                         pStartEntity: v7,
                         szName,
                         vecSrc,
                         flRadius,
                         pSearchingEntity: nullptr,
                         pActivator: nullptr,
                         pCaller: nullptr);
  if ( EntityByNameWithin != nullptr )
    return CBaseEntity::GetScriptInstance(this: EntityByNameWithin);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025DAD0
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::FindByClassnameNearest(char const __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::FindByClassnameNearest(
        CScriptEntityIterator *this,
        const char *szName,
        const Vector *vecSrc,
        float flRadius)
{
  CBaseEntity *EntityByClassnameNearest; // eax

  EntityByClassnameNearest = CGlobalEntityList::FindEntityByClassnameNearest(this: &gEntList, szName, vecSrc, flRadius);
  if ( EntityByClassnameNearest != nullptr )
    return CBaseEntity::GetScriptInstance(this: EntityByClassnameNearest);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025DB10
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::FindByClassnameWithin(struct HSCRIPT__ __near *,char const __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::FindByClassnameWithin(
        CScriptEntityIterator *this,
        HSCRIPT__ *hStartEntity,
        const char *szName,
        const Vector *vecSrc,
        float flRadius)
{
  IScriptVM_vtbl *v5; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v7; // eax
  CBaseEntity *EntityByClassnameWithin; // eax

  if ( hStartEntity != nullptr )
  {
    v5 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc();
    v7 = (CBaseEntity *)v5->GetInstanceValue(this: g_pScriptVM, a2: hStartEntity, a3: ScriptDesc);
  }
  else
  {
    v7 = nullptr;
  }
  EntityByClassnameWithin = CGlobalEntityList::FindEntityByClassnameWithin(
                              this: &gEntList,
                              pStartEntity: v7,
                              szName,
                              vecSrc,
                              flRadius);
  if ( EntityByClassnameWithin != nullptr )
    return CBaseEntity::GetScriptInstance(this: EntityByClassnameWithin);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025DB80
// Name: public: struct HSCRIPT__ __near * CScriptKeyValues::ScriptFindKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptKeyValues::ScriptFindKey(CScriptKeyValues *this, const char *pszName)
{
  HSCRIPT__ *result; // eax
  HSCRIPT__ *v3; // esi
  HSCRIPT__ **v4; // eax

  result = (HSCRIPT__ *)KeyValues::FindKey(this: this->m_pKeyValues, keyName: pszName, bCreate: false);
  v3 = result;
  if ( result != nullptr )
  {
    v4 = (HSCRIPT__ **)operator new(nSize: 4u);
    if ( v4 != nullptr )
      *v4 = v3;
    else
      v4 = nullptr;
    return g_pScriptVM->RegisterInstance(this: g_pScriptVM, a2: &g_CScriptKeyValues_ScriptDesc, a3: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025DBD0
// Name: public: struct HSCRIPT__ __near * CScriptKeyValues::ScriptGetFirstSubKey(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptKeyValues::ScriptGetFirstSubKey(CScriptKeyValues *this)
{
  HSCRIPT__ *result; // eax
  HSCRIPT__ *v2; // esi
  HSCRIPT__ **v3; // eax

  result = (HSCRIPT__ *)KeyValues::GetFirstSubKey(this: this->m_pKeyValues);
  v2 = result;
  if ( result != nullptr )
  {
    v3 = (HSCRIPT__ **)operator new(nSize: 4u);
    if ( v3 != nullptr )
      *v3 = v2;
    else
      v3 = nullptr;
    return g_pScriptVM->RegisterInstance(this: g_pScriptVM, a2: &g_CScriptKeyValues_ScriptDesc, a3: v3);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025DC10
// Name: public: struct HSCRIPT__ __near * CScriptKeyValues::ScriptGetNextKey(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptKeyValues::ScriptGetNextKey(CScriptKeyValues *this)
{
  HSCRIPT__ *result; // eax
  HSCRIPT__ *v2; // esi
  HSCRIPT__ **v3; // eax

  result = (HSCRIPT__ *)KeyValues::GetNextKey(this: this->m_pKeyValues);
  v2 = result;
  if ( result != nullptr )
  {
    v3 = (HSCRIPT__ **)operator new(nSize: 4u);
    if ( v3 != nullptr )
      *v3 = v2;
    else
      v3 = nullptr;
    return g_pScriptVM->RegisterInstance(this: g_pScriptVM, a2: &g_CScriptKeyValues_ScriptDesc, a3: v3);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025DC50
// Name: public: bool CScriptKeyValues::ScriptGetKeyValueBool(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptKeyValues::ScriptGetKeyValueBool(CScriptKeyValues *this, const char *pszName)
{
  return KeyValues::GetInt(this: this->m_pKeyValues, keyName: pszName, defaultValue: 0) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1025DC70
// Name: GetMapName
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMapName()
{
  const char *result; // eax

  result = gpGlobals->mapname.pszValue;
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025DC90
// Name: int GetDeveloperLevel(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetDeveloperLevel()
{
  if ( developer.m_pParent != nullptr )
    return developer.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1025DCA0
// Name: public: static void CScriptConstructor<class CScriptKeyValues>::Destruct(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CScriptConstructor<CScriptKeyValues>::Destruct(KeyValues **p)
{
  if ( p != nullptr )
  {
    if ( *p != nullptr )
      KeyValues::deleteThis(this: *p);
    *p = nullptr;
    free(pMem: p);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025DCD0
// Name: public: enum ScriptStatus_t IScriptVM::Call<struct HSCRIPT__ __near *,struct HSCRIPT__ __near *>(struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,bool,struct ScriptVariant_t __near *,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptStatus_t __thiscall IScriptVM::Call<HSCRIPT__ *,HSCRIPT__ *>(
        IScriptVM *this,
        HSCRIPT__ *hFunction,
        HSCRIPT__ *hScope,
        BOOL bWait,
        ScriptVariant_t *pReturn,
        HSCRIPT__ *arg1,
        HSCRIPT__ *arg2)
{
  ScriptVariant_t args[2]; // [esp+0h] [ebp-10h] BYREF

  args[1].m_flags = 0;
  args[0].m_int = (int)arg1;
  args[1].m_int = (int)arg2;
  args[0].m_flags = 0;
  args[0].m_type = 33;
  args[1].m_type = 33;
  return this->ExecuteFunction(this, a2: hFunction, a3: args, a4: 2, a5: pReturn, a6: hScope, a7: bWait);
}

//------------------------------------------------------------------------------
// Address: 0x1025DD20
// Name: public: static bool CMemberScriptBinding1<class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(char const __near *),struct HSCRIPT__ __near *,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(char const *),HSCRIPT__ *,char const *>::Call(
        int (__stdcall *pFunction)(const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 1 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_int = pFunction(a1: m_int);
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025DD60
// Name: public: static bool CMemberScriptBinding2<class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(struct HSCRIPT__ __near *,char const __near *),struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *,char const *),HSCRIPT__ *,HSCRIPT__ *,char const *>::Call(
        int (__stdcall *pFunction)(int, const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_pszString; // edx

  if ( nArguments != 2 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_pszString = pArguments[1].m_pszString;
  if ( m_pszString == nullptr )
    m_pszString = locale;
  pReturn->m_int = pFunction(a1: pArguments->m_int, a2: m_pszString);
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025DDB0
// Name: public: static bool CMemberScriptBinding3<class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(struct HSCRIPT__ __near *,class Vector const __near &,float),struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,class Vector const __near &,float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding3<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *,Vector const &,float),HSCRIPT__ *,HSCRIPT__ *,Vector const &,float>::Call(
        int (__thiscall *pFunction)(void *, int, const Vector *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  int m_int; // edi
  const Vector *v6; // eax
  int v8; // [esp+0h] [ebp-10h]

  if ( nArguments != 3 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = pArguments->m_int;
  v8 = pArguments[2].m_int;
  v6 = ScriptVariant_t::operator Vector const &(this: pArguments + 1);
  pReturn->m_int = pFunction(a1: pContext, a2: m_int, a3: v6, a4: v8);
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025DE10
// Name: public: static bool CMemberScriptBinding3<class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(char const __near *,class Vector const __near &,float),struct HSCRIPT__ __near *,char const __near *,class Vector const __near &,float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding3<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(char const *,Vector const &,float),HSCRIPT__ *,char const *,Vector const &,float>::Call(
        int (__thiscall *pFunction)(void *, const char *, const Vector *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  int m_int; // xmm0_4
  const char *v6; // esi
  const Vector *v7; // eax

  if ( nArguments != 3 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = pArguments[2].m_int;
  v6 = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    v6 = locale;
  v7 = ScriptVariant_t::operator Vector const &(this: pArguments + 1);
  pReturn->m_int = pFunction(a1: pContext, a2: v6, a3: v7, a4: m_int);
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025DE70
// Name: public: static bool CMemberScriptBinding4<class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(struct HSCRIPT__ __near *,char const __near *,class Vector const __near &,float),struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,char const __near *,class Vector const __near &,float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding4<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *,char const *,Vector const &,float),HSCRIPT__ *,HSCRIPT__ *,char const *,Vector const &,float>::Call(
        int (__thiscall *pFunction)(void *, int, const char *, const Vector *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  int m_int; // xmm0_4
  const char *m_pszString; // ebx
  int v7; // esi
  const Vector *v8; // eax

  if ( nArguments != 4 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = pArguments[3].m_int;
  m_pszString = pArguments[1].m_pszString;
  if ( m_pszString == nullptr )
    m_pszString = locale;
  v7 = pArguments->m_int;
  v8 = ScriptVariant_t::operator Vector const &(this: pArguments + 2);
  pReturn->m_int = pFunction(a1: pContext, a2: v7, a3: m_pszString, a4: v8, a5: m_int);
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025DED0
// Name: public: static bool CMemberScriptBinding1<class CScriptKeyValues __near *,int (CScriptKeyValues::*)(char const __near *),int,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CScriptKeyValues *,int (__thiscall CScriptKeyValues::*)(char const *),int,char const *>::Call(
        int (__stdcall *pFunction)(const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 1 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_int = pFunction(a1: m_int);
  pReturn->m_type = 5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025DF10
// Name: public: static bool CMemberScriptBinding1<class CScriptKeyValues __near *,float (CScriptKeyValues::*)(char const __near *),float,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CScriptKeyValues *,float (__thiscall CScriptKeyValues::*)(char const *),float,char const *>::Call(
        double (__stdcall *pFunction)(const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 1 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_float = pFunction(a1: m_int);
  pReturn->m_type = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025DF50
// Name: public: static bool CMemberScriptBinding1<class CScriptKeyValues __near *,bool (CScriptKeyValues::*)(char const __near *),bool,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CScriptKeyValues *,bool (__thiscall CScriptKeyValues::*)(char const *),bool,char const *>::Call(
        int (__stdcall *pFunction)(const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 1 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_char = pFunction(a1: m_int);
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025DF90
// Name: public: static bool CMemberScriptBinding1<class CScriptKeyValues __near *,char const __near * (CScriptKeyValues::*)(char const __near *),char const __near *,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CScriptKeyValues *,char const * (__thiscall CScriptKeyValues::*)(char const *),char const *,char const *>::Call(
        int (__stdcall *pFunction)(const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 1 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_int = pFunction(a1: m_int);
  pReturn->m_type = 32;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025DFD0
// Name: public: static bool CNonMemberScriptBinding1<void (*)(char const __near *),void,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding1<void (__cdecl *)(char const *),void,char const *>::Call(
        void (__cdecl *pFunction)(const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 1 || pReturn != nullptr || pContext != nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pFunction(a1: m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E010
// Name: public: static bool CNonMemberScriptBinding0<char const __near * (*)(void),char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding0<char const * (__cdecl *)(void),char const *>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext != nullptr )
    return 0;
  pReturn->m_int = pFunction();
  pReturn->m_type = 32;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E040
// Name: public: static bool CNonMemberScriptBinding0<bool (*)(void),bool>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding0<bool (__cdecl *)(void),bool>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext != nullptr )
    return 0;
  pReturn->m_char = pFunction();
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E070
// Name: public: static bool CNonMemberScriptBinding3<float (*)(class Vector const __near &,class Vector const __near &,struct HSCRIPT__ __near *),float,class Vector const __near &,class Vector const __near &,struct HSCRIPT__ __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding3<float (__cdecl *)(Vector const &,Vector const &,HSCRIPT__ *),float,Vector const &,Vector const &,HSCRIPT__ *>::Call(
        double (__cdecl *pFunction)(const Vector *, const Vector *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const Vector *v5; // eax
  const Vector *v7; // [esp-Ch] [ebp-10h]
  int m_int; // [esp-8h] [ebp-Ch]

  if ( nArguments != 3 || pReturn == nullptr || pContext != nullptr )
    return 0;
  m_int = pArguments[2].m_int;
  v7 = ScriptVariant_t::operator Vector const &(this: pArguments + 1);
  v5 = ScriptVariant_t::operator Vector const &(this: pArguments);
  pReturn->m_float = pFunction(a1: v5, a2: v7, a3: m_int);
  pReturn->m_type = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E0C0
// Name: public: static bool CNonMemberScriptBinding0<float (*)(void),float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding0<float (__cdecl *)(void),float>::Call(
        double (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext != nullptr )
    return 0;
  pReturn->m_float = pFunction();
  pReturn->m_type = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E0F0
// Name: public: static bool CNonMemberScriptBinding6<void (*)(char const __near *,char const __near *,char const __near *,float,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *),void,char const __near *,char const __near *,char const __near *,float,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding6<void (__cdecl *)(char const *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *),void,char const *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *>::Call(
        void (__cdecl *pFunction)(const char *, const char *, const char *, int, int, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_pszString; // ecx
  const char *v6; // edx
  const char *m_int; // eax

  if ( nArguments != 6 || pReturn != nullptr || pContext != nullptr )
    return 0;
  m_pszString = pArguments[2].m_pszString;
  if ( m_pszString == nullptr )
    m_pszString = locale;
  v6 = pArguments[1].m_pszString;
  if ( v6 == nullptr )
    v6 = locale;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pFunction(
    a1: m_int,
    a2: v6,
    a3: m_pszString,
    a4: pArguments[3].m_int,
    a5: pArguments[4].m_int,
    a6: pArguments[5].m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E160
// Name: public: static bool CNonMemberScriptBinding6<void (*)(struct HSCRIPT__ __near *,char const __near *,char const __near *,float,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *),void,struct HSCRIPT__ __near *,char const __near *,char const __near *,float,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding6<void (__cdecl *)(HSCRIPT__ *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *),void,HSCRIPT__ *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *>::Call(
        void (__cdecl *pFunction)(int, const char *, const char *, int, int, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_pszString; // ecx
  const char *v6; // edx

  if ( nArguments != 6 || pReturn != nullptr || pContext != nullptr )
    return 0;
  m_pszString = pArguments[2].m_pszString;
  if ( m_pszString == nullptr )
    m_pszString = locale;
  v6 = pArguments[1].m_pszString;
  if ( v6 == nullptr )
    v6 = locale;
  pFunction(
    a1: pArguments->m_int,
    a2: v6,
    a3: m_pszString,
    a4: pArguments[3].m_int,
    a5: pArguments[4].m_int,
    a6: pArguments[5].m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E1C0
// Name: public: static bool CNonMemberScriptBinding1<char const __near * (*)(char const __near *),char const __near *,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding1<char const * (__cdecl *)(char const *),char const *,char const *>::Call(
        int (__cdecl *pFunction)(const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 1 || pReturn == nullptr || pContext != nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_int = pFunction(a1: m_int);
  pReturn->m_type = 32;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E210
// Name: public: static bool CNonMemberScriptBinding1<struct HSCRIPT__ __near * (*)(char const __near *),struct HSCRIPT__ __near *,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding1<HSCRIPT__ * (__cdecl *)(char const *),HSCRIPT__ *,char const *>::Call(
        int (__cdecl *pFunction)(const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 1 || pReturn == nullptr || pContext != nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_int = pFunction(a1: m_int);
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E260
// Name: public: static bool CNonMemberScriptBinding8<void (*)(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,float),void,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding8<void (__cdecl *)(Vector const &,Vector const &,Vector const &,int,int,int,int,float),void,Vector const &,Vector const &,Vector const &,int,int,int,int,float>::Call(
        void (__cdecl *pFunction)(const Vector *, const Vector *, const Vector *, int, int, int, int, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const Vector *v5; // eax
  const Vector *v7; // [esp-18h] [ebp-24h]
  const Vector *v8; // [esp-14h] [ebp-20h]
  int v9; // [esp-10h] [ebp-1Ch]
  int v10; // [esp-Ch] [ebp-18h]
  int v11; // [esp-8h] [ebp-14h]
  int v12; // [esp-4h] [ebp-10h]
  int m_int; // [esp+0h] [ebp-Ch]

  if ( nArguments != 8 || pReturn != nullptr || pContext != nullptr )
    return 0;
  m_int = pArguments[7].m_int;
  v12 = pArguments[6].m_int;
  v11 = pArguments[5].m_int;
  v10 = pArguments[4].m_int;
  v9 = pArguments[3].m_int;
  v8 = ScriptVariant_t::operator Vector const &(this: pArguments + 2);
  v7 = ScriptVariant_t::operator Vector const &(this: pArguments + 1);
  v5 = ScriptVariant_t::operator Vector const &(this: pArguments);
  pFunction(a1: v5, a2: v7, a3: v8, a4: v9, a5: v10, a6: v11, a7: v12, a8: m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E2C0
// Name: public: static bool CNonMemberScriptBinding7<void (*)(class Vector const __near &,class Vector const __near &,int,int,int,bool,float),void,class Vector const __near &,class Vector const __near &,int,int,int,bool,float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding7<void (__cdecl *)(Vector const &,Vector const &,int,int,int,bool,float),void,Vector const &,Vector const &,int,int,int,bool,float>::Call(
        void (__cdecl *pFunction)(const Vector *, const Vector *, int, int, int, int, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const Vector *v5; // eax
  const Vector *v7; // [esp-14h] [ebp-20h]
  int v8; // [esp-10h] [ebp-1Ch]
  int v9; // [esp-Ch] [ebp-18h]
  int v10; // [esp-8h] [ebp-14h]
  int m_int; // [esp+0h] [ebp-Ch]

  if ( nArguments != 7 || pReturn != nullptr || pContext != nullptr )
    return 0;
  LOBYTE(nArguments) = pArguments[5].m_char;
  m_int = pArguments[6].m_int;
  v10 = pArguments[4].m_int;
  v9 = pArguments[3].m_int;
  v8 = pArguments[2].m_int;
  v7 = ScriptVariant_t::operator Vector const &(this: pArguments + 1);
  v5 = ScriptVariant_t::operator Vector const &(this: pArguments);
  pFunction(a1: v5, a2: v7, a3: v8, a4: v9, a5: v10, a6: nArguments, a7: m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E320
// Name: public: static bool CNonMemberScriptBinding2<bool (*)(char const __near *,struct HSCRIPT__ __near *),bool,char const __near *,struct HSCRIPT__ __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding2<bool (__cdecl *)(char const *,HSCRIPT__ *),bool,char const *,HSCRIPT__ *>::Call(
        int (__cdecl *pFunction)(const char *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 2 || pReturn == nullptr || pContext != nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_char = pFunction(a1: m_int, a2: pArguments[1].m_int);
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E370
// Name: public: static bool CNonMemberScriptBinding4<struct HSCRIPT__ __near * (*)(char const __near *,class Vector const __near &,char const __near *,int),struct HSCRIPT__ __near *,char const __near *,class Vector const __near &,char const __near *,int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding4<HSCRIPT__ * (__cdecl *)(char const *,Vector const &,char const *,int),HSCRIPT__ *,char const *,Vector const &,char const *,int>::Call(
        int (__cdecl *pFunction)(const char *, const Vector *, const char *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_pszString; // ecx
  const char *m_int; // esi
  const Vector *v7; // eax
  const char *v9; // [esp-Ch] [ebp-10h]
  int v10; // [esp-8h] [ebp-Ch]

  if ( nArguments != 4 || pReturn == nullptr || pContext != nullptr )
    return 0;
  m_pszString = pArguments[2].m_pszString;
  if ( m_pszString == nullptr )
    m_pszString = locale;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  v10 = pArguments[3].m_int;
  v9 = m_pszString;
  v7 = ScriptVariant_t::operator Vector const &(this: pArguments + 1);
  pReturn->m_int = pFunction(a1: m_int, a2: v7, a3: v9, a4: v10);
  pReturn->m_type = 33;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E3D0
// Name: public: static bool CNonMemberScriptBinding2<void (*)(char const __near *,int),void,char const __near *,int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding2<void (__cdecl *)(char const *,int),void,char const *,int>::Call(
        void (__cdecl *pFunction)(const char *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 2 || pReturn != nullptr || pContext != nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pFunction(a1: m_int, a2: pArguments[1].m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E410
// Name: public: static bool CNonMemberScriptBinding0<int (*)(void),int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding0<int (__cdecl *)(void),int>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext != nullptr )
    return 0;
  pReturn->m_int = pFunction();
  pReturn->m_type = 5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025E440
// Name: public: struct HSCRIPT__ __near * CScriptEntityIterator::First(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptEntityIterator::First(CScriptEntityIterator *this)
{
  CBaseEntity *Ent; // eax

  Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
  if ( Ent != nullptr )
    return CBaseEntity::GetScriptInstance(this: Ent);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1025E460
// Name: SendToConsole
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendToConsole(const char *pszCommand)
{
  CBasePlayer *LocalPlayer; // eax

  if ( gpGlobals->maxClients <= 1 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
  }
  else
  {
    if ( engine->IsDedicatedServer(this: engine) )
    {
LABEL_6:
      DevMsg(a1: "Cannot execute \"%s\", no player\n", pszCommand);
      return;
    }
    LocalPlayer = UTIL_GetListenServerHost();
  }
  if ( LocalPlayer == nullptr )
    goto LABEL_6;
  engine->ClientCommand(this: engine, a2: LocalPlayer->m_Network.m_pPev, a3: pszCommand);
}

//------------------------------------------------------------------------------
// Address: 0x1025E4D0
// Name: LoopSinglePlayerMaps
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LoopSinglePlayerMaps()
{
  return loopsingleplayermaps.m_pParent != nullptr && loopsingleplayermaps.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1025E4F0
// Name: DoEntFire
// Source: json
//------------------------------------------------------------------------------
void __cdecl DoEntFire(
        const char *pszTarget,
        const char *pszAction,
        const char *pszValue,
        float delay,
        HSCRIPT__ *hActivator,
        HSCRIPT__ *hCaller)
{
  int v6; // ebx
  IScriptVM_vtbl *v7; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v9; // esi
  IScriptVM_vtbl *v10; // edi
  ScriptClassDesc_t *v11; // eax
  CBaseEntity *v12; // eax
  variant_t v13; // [esp-14h] [ebp-58h]
  __int64 value_4; // [esp+20h] [ebp-24h]
  _fieldtypes value_16; // [esp+2Ch] [ebp-18h]
  char v16[4]; // [esp+30h] [ebp-14h] BYREF
  char v17[4]; // [esp+34h] [ebp-10h] BYREF
  char v18[4]; // [esp+38h] [ebp-Ch] BYREF
  const char *target; // [esp+3Ch] [ebp-8h]
  const char *action; // [esp+40h] [ebp-4h]

  v6 = 0;
  action = "Use";
  value_16 = FIELD_VOID;
  target = *(const char **)AllocPooledString(pszValue: v18).pszValue;
  if ( target == nullptr )
    target = locale;
  if ( gpGlobals->maxClients <= 1 || _V_stricmp(s1: target, s2: "point_servercommand") != 0 )
  {
    if ( *pszAction != 0 )
    {
      action = *(const char **)AllocPooledString(pszValue: v17).pszValue;
      if ( action == nullptr )
        action = locale;
    }
    if ( *pszValue != 0 )
    {
      v6 = *(_DWORD *)AllocPooledString(pszValue: v16).pszValue;
      value_16 = FIELD_STRING;
    }
    if ( delay < 0.0 )
      delay = 0.0;
    if ( hCaller != nullptr )
    {
      v7 = g_pScriptVM->__vftable;
      ScriptDesc = GetScriptDesc();
      v9 = (CBaseEntity *)v7->GetInstanceValue(this: g_pScriptVM, a2: hCaller, a3: ScriptDesc);
    }
    else
    {
      v9 = nullptr;
    }
    if ( hActivator != nullptr )
    {
      v10 = g_pScriptVM->__vftable;
      v11 = GetScriptDesc();
      v12 = (CBaseEntity *)v10->GetInstanceValue(this: g_pScriptVM, a2: hActivator, a3: v11);
    }
    else
    {
      v12 = nullptr;
    }
    *(_QWORD *)(&v13.flVal + 1) = value_4;
    v13.iVal = v6;
    v13.eVal.m_Index = -1;
    v13.fieldType = value_16;
    CEventQueue::AddEvent(
      this: &g_EventQueue,
      target,
      targetInput: action,
      Value: v13,
      fireDelay: delay,
      pActivator: v12,
      pCaller: v9,
      outputID: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025E640
// Name: bool DoIncludeScript(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DoIncludeScript(const char *pszScript, HSCRIPT__ *hScope)
{
  const char *v2; // eax
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v5; // [esp+4h] [ebp-10Ch] BYREF

  if ( VScriptRunScript(pszScriptName: pszScript, hScope, bWarnMissing: true) )
    return 1;
  v2 = pszScript;
  if ( pszScript == nullptr )
    v2 = "unknown";
  v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v5, pszFormat: "Failed to include script \"%s\"", v2);
  g_pScriptVM->RaiseException(this: g_pScriptVM, a2: v3->m_szBuf);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1025E6B0
// Name: DoEntFireByInstanceHandle
// Source: json
//------------------------------------------------------------------------------
void __cdecl DoEntFireByInstanceHandle(
        HSCRIPT__ *hTarget,
        CBaseEntity *pszAction,
        const char *pszValue,
        float delay,
        HSCRIPT__ *hActivator,
        HSCRIPT__ *hCaller)
{
  int v6; // ebx
  IScriptVM_vtbl *v7; // esi
  ScriptClassDesc_t *v8; // eax
  CBaseEntity *v9; // edi
  IScriptVM_vtbl *v10; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v12; // esi
  IScriptVM_vtbl *v13; // edi
  ScriptClassDesc_t *v14; // eax
  CBaseEntity *v15; // eax
  variant_t v16; // [esp-Ch] [ebp-4Ch]
  __int64 value_4; // [esp+28h] [ebp-18h]
  _fieldtypes value_16; // [esp+34h] [ebp-Ch]
  char v19[4]; // [esp+38h] [ebp-8h] BYREF
  const char *action; // [esp+3Ch] [ebp-4h]

  v6 = 0;
  action = "Use";
  value_16 = FIELD_VOID;
  if ( LOBYTE(pszAction->__vftable) != 0 )
  {
    action = *(const char **)AllocPooledString(pszValue: v19).pszValue;
    if ( action == nullptr )
      action = locale;
  }
  if ( *pszValue != 0 )
  {
    v6 = *(_DWORD *)AllocPooledString(pszValue: (const char *)&pszAction).pszValue;
    value_16 = FIELD_STRING;
  }
  if ( delay < 0.0 )
    delay = 0.0;
  if ( hTarget != nullptr
    && (v7 = g_pScriptVM->__vftable,
        v8 = GetScriptDesc(),
        v9 = (CBaseEntity *)v7->GetInstanceValue(this: g_pScriptVM, a2: hTarget, a3: v8),
        pszAction = v9,
        v9 != nullptr) )
  {
    if ( hCaller != nullptr )
    {
      v10 = g_pScriptVM->__vftable;
      ScriptDesc = GetScriptDesc();
      v12 = (CBaseEntity *)v10->GetInstanceValue(this: g_pScriptVM, a2: hCaller, a3: ScriptDesc);
    }
    else
    {
      v12 = nullptr;
    }
    if ( hActivator != nullptr )
    {
      v13 = g_pScriptVM->__vftable;
      v14 = GetScriptDesc();
      v15 = (CBaseEntity *)v13->GetInstanceValue(this: g_pScriptVM, a2: hActivator, a3: v14);
      v9 = pszAction;
    }
    else
    {
      v15 = nullptr;
    }
    *(_QWORD *)(&v16.flVal + 1) = value_4;
    v16.iVal = v6;
    v16.eVal.m_Index = -1;
    v16.fieldType = value_16;
    CEventQueue::AddEvent(
      this: &g_EventQueue,
      target: v9,
      targetInput: action,
      Value: v16,
      fireDelay: delay,
      pActivator: v15,
      pCaller: v12,
      outputID: 0);
  }
  else
  {
    _Warning(a1: "VScript error: DoEntFire was passed an invalid entity instance.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025E800
// Name: ScriptTraceLine
// Source: json
//------------------------------------------------------------------------------
double __usercall ScriptTraceLine@<st0>(
        int a1@<esi>,
        const Vector *vecStart,
        const Vector *vecEnd,
        HSCRIPT__ *entIgnore)
{
  IScriptVM_vtbl *v4; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  const IHandleEntity *v6; // eax
  int v8; // [esp-Ch] [ebp-64h]
  int v9; // [esp-4h] [ebp-5Ch]
  CGameTrace tr; // [esp+4h] [ebp-54h] BYREF
  IHandleEntity savedregs; // [esp+58h] [ebp+0h] BYREF

  if ( entIgnore != nullptr )
  {
    v9 = a1;
    v4 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc();
    v6 = (const IHandleEntity *)((int (__thiscall *)(IScriptVM *, HSCRIPT__ *, ScriptClassDesc_t *, int))v4->GetInstanceValue)(
                                  a1: g_pScriptVM,
                                  a2: entIgnore,
                                  a3: ScriptDesc,
                                  a4: v9);
    a1 = v8;
  }
  else
  {
    v6 = nullptr;
  }
  UTIL_TraceLine(
    a1: &savedregs,
    a2: a1,
    vecAbsStart: vecStart,
    vecAbsEnd: vecEnd,
    mask: 0x2000Bu,
    ignore: v6,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fractionleftsolid == 0.0 || !tr.startsolid )
    return tr.fraction;
  else
    return 1.0 - tr.fractionleftsolid;
}

//------------------------------------------------------------------------------
// Address: 0x1025E880
// Name: bool VScriptServerReplaceClosures(char const __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VScriptServerReplaceClosures(const char *pszScriptName, HSCRIPT__ *hScope, bool bWarnMissing)
{
  HSCRIPT__ *v4; // esi
  HSCRIPT__ *v5; // eax
  HSCRIPT__ *v6; // edi

  if ( g_pScriptVM == nullptr )
    return 0;
  v4 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: "__ReplaceClosures", a3: 0);
  if ( v4 == nullptr )
    return 0;
  v5 = VScriptCompileScript(pszScriptName, bWarnMissing);
  v6 = v5;
  if ( v5 != nullptr )
  {
    IScriptVM::Call<HSCRIPT__ *,HSCRIPT__ *>(
      this: g_pScriptVM,
      hFunction: v4,
      hScope: nullptr,
      bWait: true,
      pReturn: nullptr,
      arg1: v5,
      arg2: hScope);
    g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v4);
    g_pScriptVM->ReleaseScript(this: g_pScriptVM, a2: v6);
    return 1;
  }
  else
  {
    g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025E910
// Name: script_reload_code
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_reload_code(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc > 1 && *(v1 = args->m_ppArgv[1]) != 0 )
  {
    if ( g_pScriptVM != nullptr )
    {
      VScriptServerReplaceClosures(pszScriptName: v1, hScope: nullptr, bWarnMissing: true);
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "No script specified\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025E9A0
// Name: script_reload_think
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_reload_think(const CCommand *args)
{
  const char *v1; // ebx
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v3; // edi
  CBaseEntity *i; // esi
  HSCRIPT__ *m_hScope; // ecx
  const char *pszValue; // eax

  v1 = locale;
  if ( args->m_nArgc > 1 && *args->m_ppArgv[1] != 0 )
    v1 = args->m_ppArgv[1];
  if ( g_pScriptVM != nullptr )
  {
    CommandClient = UTIL_GetCommandClient();
    v3 = CommandClient;
    if ( CommandClient != nullptr )
    {
      for ( i = GetNextCommandEntity(pPlayer: CommandClient, name: v1, ent: nullptr);
            i != nullptr;
            i = GetNextCommandEntity(pPlayer: v3, name: v1, ent: i) )
      {
        m_hScope = i->m_ScriptScope.m_hScope;
        if ( m_hScope != (HSCRIPT__ *)-1 )
        {
          pszValue = i->m_iszScriptThinkFunction.pszValue;
          if ( pszValue != nullptr )
            VScriptServerReplaceClosures(pszScriptName: pszValue, hScope: m_hScope, bWarnMissing: true);
        }
      }
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025EA50
// Name: public: virtual void CVScriptGameSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptGameSystem::LevelInitPostEntity(CVScriptGameSystem *this)
{
  this->m_bAllowEntityCreationInScripts = false;
}

//------------------------------------------------------------------------------
// Address: 0x1025EA60
// Name: public: virtual void CVScriptGameSystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptGameSystem::LevelShutdownPostEntity(CVScriptGameSystem *this)
{
  if ( g_pScriptVM != nullptr )
  {
    scriptmanager->DestroyVM(this: scriptmanager, a2: g_pScriptVM);
    g_pScriptVM = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025EA90
// Name: public: virtual void CVScriptGameSystem::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptGameSystem::FrameUpdatePostEntityThink(CVScriptGameSystem *this)
{
  if ( g_pScriptVM != nullptr )
    ((void (__stdcall *)(_DWORD))g_pScriptVM->Frame)(a1: LODWORD(gpGlobals->frametime));
}

//------------------------------------------------------------------------------
// Address: 0x1025EAC0
// Name: private: virtual bool CBaseEntityScriptInstanceHelper::ToString(void __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntityScriptInstanceHelper::ToString(
        CBaseEntityScriptInstanceHelper *this,
        _DWORD *p,
        char *pBuf,
        int bufSize)
{
  const char *v4; // edx
  signed int v5; // eax
  const char *v7; // edx
  signed int v8; // eax

  if ( p[51] != 0 )
  {
    v4 = (const char *)p[23];
    if ( v4 == nullptr )
      v4 = locale;
    v5 = p[6];
    if ( v5 != 0 )
      v5 = (signed int)(v5 - (unsigned int)gpGlobals->pEdicts) >> 4;
    V_snprintf(pDest: pBuf, maxLen: bufSize, pFormat: "([%d] %s: %s)", v5, v4, (const char *)p[51]);
    return 1;
  }
  else
  {
    v7 = (const char *)p[23];
    if ( v7 == nullptr )
      v7 = locale;
    v8 = p[6];
    if ( v8 != 0 )
      v8 = (signed int)(v8 - (unsigned int)gpGlobals->pEdicts) >> 4;
    V_snprintf(pDest: pBuf, maxLen: bufSize, pFormat: "([%d] %s)", v8, v7);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025EDD0
// Name: struct HSCRIPT__ __near * CreateProp(char const __near *,class Vector const __near &,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__cdecl CreateProp(
        const char *pszEntityName,
        const Vector *vOrigin,
        const char *pszModelName,
        Activity iAnim)
{
  CBaseEntity *EntityByName; // esi
  CBaseEdict *v5; // ecx
  int v6; // eax

  EntityByName = CreateEntityByName(className: pszEntityName, iForceEdictIndex: -1, bNotify: true);
  CBaseEntity::SetAbsOrigin(this: EntityByName, absOrigin: vOrigin);
  EntityByName->SetModel(this: EntityByName, a2: pszModelName);
  LOBYTE(EntityByName[1].m_Network.m_TimerEvent.m_pCallback) = 0;
  if ( EntityByName[1].m_Network.m_PVSInfo.m_vCenter[0] != 1.0 )
  {
    if ( EntityByName->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&EntityByName->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = &EntityByName->m_Network.m_pPev->CBaseEdict;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: 0x37Cu);
    }
    EntityByName[1].m_Network.m_PVSInfo.m_vCenter[0] = 1.0;
  }
  v6 = CBaseAnimating::SelectWeightedSequence(this: (CBaseAnimating *)EntityByName, activity: iAnim);
  if ( v6 != -1 )
    CBaseAnimating::SetSequence(this: (CBaseAnimating *)EntityByName, nSequence: v6);
  return CBaseEntity::GetScriptInstance(this: EntityByName);
}

//------------------------------------------------------------------------------
// Address: 0x1025EE70
// Name: private: virtual void __near * CBaseEntityScriptInstanceHelper::BindOnRead(struct HSCRIPT__ __near *,void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntityScriptInstanceHelper::BindOnRead(
        CBaseEntityScriptInstanceHelper *this,
        HSCRIPT__ *hInstance,
        void *pOld,
        const char *pszId)
{
  unsigned __int16 v4; // ax
  CBaseEntity *result; // eax
  CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  search.key = pszId;
  v4 = CUtlRBTree<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CBaseEntity *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_VScriptSaveRestoreBlockHandler.m_InstanceMap.m_Tree,
         &search);
  if ( v4 == 0xFFFF )
    return nullptr;
  result = g_VScriptSaveRestoreBlockHandler.m_InstanceMap.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  result->m_hScriptInstance = hInstance;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025EF30
// Name: script_reload_entity_code
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_reload_entity_code(CBasePlayer *args)
{
  bool v1; // cc
  CBasePlayer *CommandClient; // eax
  CBaseEntity *i; // edi
  int j; // esi
  char **m_pMemory; // eax
  char szScriptsList[256]; // [esp+4h] [ebp-118h] BYREF
  CUtlStringList szScripts; // [esp+104h] [ebp-18h] BYREF
  const char *pszTarget; // [esp+118h] [ebp-4h]
  CBasePlayer *pPlayer; // [esp+124h] [ebp+8h]

  v1 = (int)args->__vftable <= 1;
  pszTarget = locale;
  if ( !v1 && *(_BYTE *)LODWORD(args->m_flPoseParameter.m_Value[22]) != 0 )
    pszTarget = (const char *)LODWORD(args->m_flPoseParameter.m_Value[22]);
  if ( g_pScriptVM != nullptr )
  {
    CommandClient = UTIL_GetCommandClient();
    pPlayer = CommandClient;
    if ( CommandClient != nullptr )
    {
      for ( i = GetNextCommandEntity(pPlayer: CommandClient, name: pszTarget, ent: nullptr);
            i != nullptr;
            i = GetNextCommandEntity(pPlayer, name: pszTarget, ent: i) )
      {
        if ( i->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 && i->m_iszVScripts.pszValue != nullptr )
        {
          _V_strcpy(dest: szScriptsList, src: i->m_iszVScripts.pszValue);
          memset(&szScripts, 0, sizeof(szScripts));
          V_SplitString(pString: szScriptsList, pSeparator: " ", outStrings: &szScripts);
          for ( j = 0; j < szScripts.m_Size; ++j )
            VScriptServerReplaceClosures(
              pszScriptName: szScripts.m_Memory.m_pMemory[j],
              hScope: i->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 ? i->m_ScriptScope.m_hScope : nullptr,
              bWarnMissing: true);
          CUtlVector<SWeaponHitData *,CUtlMemory<SWeaponHitData *,int>>::PurgeAndDeleteElements(this: &szScripts);
          m_pMemory = szScripts.m_Memory.m_pMemory;
          szScripts.m_Size = 0;
          if ( szScripts.m_Memory.m_nGrowSize >= 0 )
          {
            if ( szScripts.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: szScripts.m_Memory.m_pMemory);
              m_pMemory = nullptr;
              szScripts.m_Memory.m_pMemory = nullptr;
            }
            szScripts.m_Memory.m_nAllocationCount = 0;
          }
          szScripts.m_pElements = m_pMemory;
          if ( szScripts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        }
      }
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x102608A0
// Name: void ScriptDeduceFunctionSignature<void,char const __near *,int>(struct ScriptFuncDescriptor_t __near *,void (*)(char const __near *,int))
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<void,char const *,int>(ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 0;
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
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 5;
}

//------------------------------------------------------------------------------
// Address: 0x102609B0
// Name: bool VScriptServerInit(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall VScriptServerInit@<al>(int a1@<ebx>)
{
  int v1; // eax
  const char *v2; // eax
  int v3; // edi
  IScriptVM *v4; // eax
  IScriptVM *v5; // ebx
  IScriptVM *v6; // edi
  IScriptVM *v7; // ecx
  HSCRIPT__ *(__thiscall *RegisterInstance)(IScriptVM *, ScriptClassDesc_t *, void *); // eax
  int v9; // eax
  bool (__thiscall *SetValue)(IScriptVM *, HSCRIPT__ *, const char *, const ScriptVariant_t *); // edx
  unsigned __int64 v12; // [esp+0h] [ebp-18h]
  _DWORD v13[2]; // [esp+8h] [ebp-10h] BYREF
  const char *pszScriptLanguage; // [esp+10h] [ebp-8h] BYREF
  ScriptLanguage_t scriptLanguage; // [esp+14h] [ebp-4h]

  if ( scriptmanager != nullptr )
  {
    scriptLanguage = SL_SQUIRREL;
    v1 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v1 + 12))(
           a1: v1,
           a2: "-scriptlang",
           a3: &pszScriptLanguage) != 0 )
    {
      if ( _V_stricmp(s1: pszScriptLanguage, s2: "gamemonkey") != 0 )
      {
        if ( _V_stricmp(s1: pszScriptLanguage, s2: "squirrel") != 0 )
        {
          if ( _V_stricmp(s1: pszScriptLanguage, s2: "python") != 0 )
          {
            DevWarning(
              a1: "-server_script does not recognize a language named '%s'. virtual machine did NOT start.\n",
              pszScriptLanguage);
            g_pScriptVM = nullptr;
            return 0;
          }
          scriptLanguage = SL_PYTHON;
        }
        else
        {
          scriptLanguage = SL_SQUIRREL;
        }
      }
      else
      {
        scriptLanguage = SL_GAMEMONKEY;
      }
    }
    if ( g_pScriptVM != nullptr
      || (g_pScriptVM = scriptmanager->CreateVM(this: scriptmanager, a2: scriptLanguage), g_pScriptVM != nullptr) )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 0) != 0 )
      {
        v2 = g_pScriptVM->GetLanguageName(this: g_pScriptVM);
        _LoggingSystem_Log(
          a1: LOG_VScript,
          a2: 0,
          a3: "VSCRIPT: Started VScript virtual machine using script language '%s'\n",
          v2);
      }
      if ( (_S2_234 & 1) == 0 )
      {
        _S2_234 |= 1u;
        binding_13.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_13.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_13.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_13.m_desc.m_Parameters.m_Size = 0;
        binding_13.m_desc.m_Parameters.m_pElements = nullptr;
        binding_13.m_desc.m_pszFunction = nullptr;
        binding_13.m_desc.m_ReturnType = 31;
        binding_13.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_35_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_13.m_desc.m_pszDescription = "Print a hud message on all clients";
      binding_13.m_desc.m_Parameters.m_Size = 0;
      binding_13.m_desc.m_pszScriptName = "ShowMessage";
      binding_13.m_desc.m_pszFunction = "UTIL_ShowMessageAll";
      ScriptDeduceFunctionSignature<void,char const *>(pDesc: &binding_13.m_desc);
      binding_13.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding1<void (__cdecl *)(char const *),void,char const *>::Call;
      binding_13.m_pFunction = UTIL_ShowMessageAll;
      ((void (__thiscall *)(IScriptVM *, ScriptFunctionBinding_t *, int))g_pScriptVM->RegisterFunction)(
        a1: g_pScriptVM,
        a2: &binding_13,
        a3: a1);
      if ( (_S2_234 & 2) == 0 )
      {
        _S2_234 |= 2u;
        binding_12.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_12.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_12.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_12.m_desc.m_Parameters.m_Size = 0;
        binding_12.m_desc.m_Parameters.m_pElements = nullptr;
        binding_12.m_desc.m_pszFunction = nullptr;
        binding_12.m_desc.m_ReturnType = 31;
        binding_12.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_44_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_12.m_desc.m_pszDescription = "Send a string to the console as a command";
      binding_12.m_desc.m_Parameters.m_Size = 0;
      binding_12.m_desc.m_pszScriptName = "SendToConsole";
      binding_12.m_desc.m_pszFunction = "SendToConsole";
      ScriptDeduceFunctionSignature<void,char const *>(pDesc: &binding_12.m_desc);
      binding_12.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding1<void (__cdecl *)(char const *),void,char const *>::Call;
      binding_12.m_pFunction = SendToConsole;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_12);
      if ( (_S2_234 & 4) == 0 )
      {
        _S2_234 |= 4u;
        binding_11.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_11.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_11.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_11.m_desc.m_Parameters.m_Size = 0;
        binding_11.m_desc.m_Parameters.m_pElements = nullptr;
        binding_11.m_desc.m_pszFunction = nullptr;
        binding_11.m_desc.m_ReturnType = 31;
        binding_11.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_53_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_11.m_desc.m_pszScriptName = "GetMapName";
      binding_11.m_desc.m_pszFunction = "GetMapName";
      binding_11.m_desc.m_pszDescription = "Get the name of the map.";
      binding_11.m_desc.m_Parameters.m_Size = 0;
      binding_11.m_desc.m_ReturnType = 32;
      binding_11.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding0<char const * (__cdecl *)(void),char const *>::Call;
      binding_11.m_pFunction = GetMapName;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_11);
      if ( (_S2_234 & 8) == 0 )
      {
        _S2_234 |= 8u;
        binding_10.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_10.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_10.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_10.m_desc.m_Parameters.m_Size = 0;
        binding_10.m_desc.m_Parameters.m_pElements = nullptr;
        binding_10.m_desc.m_pszFunction = nullptr;
        binding_10.m_desc.m_ReturnType = 31;
        binding_10.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_62_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_10.m_desc.m_pszScriptName = "LoopSinglePlayerMaps";
      binding_10.m_desc.m_pszFunction = "LoopSinglePlayerMaps";
      binding_10.m_desc.m_pszDescription = "Run the single player maps in a continuous loop.";
      binding_10.m_desc.m_Parameters.m_Size = 0;
      binding_10.m_desc.m_ReturnType = 6;
      binding_10.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding0<bool (__cdecl *)(void),bool>::Call;
      binding_10.m_pFunction = LoopSinglePlayerMaps;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_10);
      if ( (_S2_234 & 0x10) == 0 )
      {
        _S2_234 |= 0x10u;
        binding_9.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_9.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_9.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_9.m_desc.m_Parameters.m_Size = 0;
        binding_9.m_desc.m_Parameters.m_pElements = nullptr;
        binding_9.m_desc.m_pszFunction = nullptr;
        binding_9.m_desc.m_ReturnType = 31;
        binding_9.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_71_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_9.m_desc.m_pszDescription = "given 2 points & ent to ignore, return fraction along line that hits world or models";
      binding_9.m_desc.m_Parameters.m_Size = 0;
      binding_9.m_desc.m_pszScriptName = "TraceLine";
      binding_9.m_desc.m_pszFunction = "ScriptTraceLine";
      ScriptDeduceFunctionSignature<float,Vector const &,Vector const &,HSCRIPT__ *>(
        pDesc: &binding_9.m_desc,
        pfnProxied: (float (__cdecl *)(const Vector *, const Vector *, HSCRIPT__ *))ScriptTraceLine);
      binding_9.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding3<float (__cdecl *)(Vector const &,Vector const &,HSCRIPT__ *),float,Vector const &,Vector const &,HSCRIPT__ *>::Call;
      binding_9.m_pFunction = ScriptTraceLine;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_9);
      if ( (_S2_234 & 0x20) == 0 )
      {
        _S2_234 |= 0x20u;
        binding_8.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_8.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_8.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_8.m_desc.m_Parameters.m_Size = 0;
        binding_8.m_desc.m_Parameters.m_pElements = nullptr;
        binding_8.m_desc.m_pszFunction = nullptr;
        binding_8.m_desc.m_ReturnType = 31;
        binding_8.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_80_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_8.m_desc.m_pszScriptName = "Time";
      binding_8.m_desc.m_pszFunction = "Time";
      binding_8.m_desc.m_pszDescription = "Get the current server time";
      binding_8.m_desc.m_Parameters.m_Size = 0;
      binding_8.m_desc.m_ReturnType = 1;
      binding_8.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding0<float (__cdecl *)(void),float>::Call;
      binding_8.m_pFunction = IntervalTimer::Now;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_8);
      if ( (_S2_234 & 0x40) == 0 )
      {
        _S2_234 |= 0x40u;
        binding_7.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_7.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_7.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_7.m_desc.m_Parameters.m_Size = 0;
        binding_7.m_desc.m_Parameters.m_pElements = nullptr;
        binding_7.m_desc.m_pszFunction = nullptr;
        binding_7.m_desc.m_ReturnType = 31;
        binding_7.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_89_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_7.m_desc.m_pszScriptName = "FrameTime";
      binding_7.m_desc.m_pszFunction = "FrameTime";
      binding_7.m_desc.m_pszDescription = "Get the time spent on the server in the last frame";
      binding_7.m_desc.m_Parameters.m_Size = 0;
      binding_7.m_desc.m_ReturnType = 1;
      binding_7.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding0<float (__cdecl *)(void),float>::Call;
      binding_7.m_pFunction = FrameTime;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_7);
      if ( (_S2_234 & 0x80u) == 0 )
      {
        _S2_234 |= 0x80u;
        binding_6.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_6.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_6.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_6.m_desc.m_Parameters.m_Size = 0;
        binding_6.m_desc.m_Parameters.m_pElements = nullptr;
        binding_6.m_desc.m_pszFunction = nullptr;
        binding_6.m_desc.m_ReturnType = 31;
        binding_6.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_98_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_6.m_desc.m_pszDescription = "#EntFire:Generate and entity i/o event";
      binding_6.m_desc.m_Parameters.m_Size = 0;
      binding_6.m_desc.m_pszScriptName = "DoEntFire";
      binding_6.m_desc.m_pszFunction = "DoEntFire";
      ScriptDeduceFunctionSignature<void,char const *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *>(
        pDesc: &binding_6.m_desc,
        pfnProxied: DoEntFire);
      binding_6.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding6<void (__cdecl *)(char const *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *),void,char const *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *>::Call;
      binding_6.m_pFunction = DoEntFire;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_6);
      if ( (_S2_234 & 0x100) == 0 )
      {
        _S2_234 |= 0x100u;
        binding_5.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_5.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_5.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_5.m_desc.m_Parameters.m_Size = 0;
        binding_5.m_desc.m_Parameters.m_pElements = nullptr;
        binding_5.m_desc.m_pszFunction = nullptr;
        binding_5.m_desc.m_ReturnType = 31;
        binding_5.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_107_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_5.m_desc.m_pszDescription = "Generate and entity i/o event. First parameter is an entity instance.";
      binding_5.m_desc.m_Parameters.m_Size = 0;
      binding_5.m_desc.m_pszScriptName = "EntFireByHandle";
      binding_5.m_desc.m_pszFunction = "DoEntFireByInstanceHandle";
      ScriptDeduceFunctionSignature<void,HSCRIPT__ *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *>(
        pDesc: &binding_5.m_desc,
        pfnProxied: (void (__cdecl *)(HSCRIPT__ *, const char *, const char *, float, HSCRIPT__ *, HSCRIPT__ *))DoEntFireByInstanceHandle);
      binding_5.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding6<void (__cdecl *)(HSCRIPT__ *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *),void,HSCRIPT__ *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *>::Call;
      binding_5.m_pFunction = DoEntFireByInstanceHandle;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_5);
      if ( (_S2_234 & 0x200) == 0 )
      {
        _S2_234 |= 0x200u;
        binding_4.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_4.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_4.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_4.m_desc.m_Parameters.m_Size = 0;
        binding_4.m_desc.m_Parameters.m_pElements = nullptr;
        binding_4.m_desc.m_pszFunction = nullptr;
        binding_4.m_desc.m_ReturnType = 31;
        binding_4.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_116_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_4.m_desc.m_pszDescription = "#UniqueString:Generate a string guaranteed to be unique across the life of the"
                                          " script VM, with an optional root string. Useful for adding data to tables whe"
                                          "n not sure what keys are already in use in that table.";
      binding_4.m_desc.m_Parameters.m_Size = 0;
      binding_4.m_desc.m_pszScriptName = "DoUniqueString";
      binding_4.m_desc.m_pszFunction = "DoUniqueString";
      ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,char const *,char const *>(
        pDesc: &binding_4.m_desc,
        pfnProxied: (const char *(__cdecl *)(const char *))DoUniqueString);
      binding_4.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding1<char const * (__cdecl *)(char const *),char const *,char const *>::Call;
      binding_4.m_pFunction = DoUniqueString;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_4);
      if ( (_S2_234 & 0x400) == 0 )
      {
        _S2_234 |= 0x400u;
        binding_3.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_3.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_3.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_3.m_desc.m_Parameters.m_Size = 0;
        binding_3.m_desc.m_Parameters.m_pElements = nullptr;
        binding_3.m_desc.m_pszFunction = nullptr;
        binding_3.m_desc.m_ReturnType = 31;
        binding_3.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_125_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_3.m_desc.m_pszDescription = "Create a scene entity to play the specified scene.";
      binding_3.m_desc.m_Parameters.m_Size = 0;
      binding_3.m_desc.m_pszScriptName = "CreateSceneEntity";
      binding_3.m_desc.m_pszFunction = "ScriptCreateSceneEntity";
      ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,char const *>(
        pDesc: &binding_3.m_desc,
        pObject: (CSceneEntity *)ScriptCreateSceneEntity,
        pfnProxied: (HSCRIPT__ *(__thiscall *__ptr64)(CSceneEntity *, const char *))v12);
      binding_3.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding1<HSCRIPT__ * (__cdecl *)(char const *),HSCRIPT__ *,char const *>::Call;
      binding_3.m_pFunction = ScriptCreateSceneEntity;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_3);
      if ( (_S2_234 & 0x800) == 0 )
      {
        _S2_234 |= 0x800u;
        pDesc.m_Parameters.m_Memory.m_pMemory = nullptr;
        pDesc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        pDesc.m_Parameters.m_Memory.m_nGrowSize = 0;
        pDesc.m_Parameters.m_Size = 0;
        pDesc.m_Parameters.m_pElements = nullptr;
        pDesc.m_pszFunction = nullptr;
        pDesc.m_ReturnType = 31;
        pDesc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit__::G_::_dynamic_atexit_destructor_for__binding__);
      }
      pDesc.m_pszDescription = "Draw a debug overlay box";
      pDesc.m_Parameters.m_Size = 0;
      pDesc.m_pszScriptName = "DebugDrawBox";
      pDesc.m_pszFunction = "NDebugOverlay::Box";
      ScriptDeduceFunctionSignature<void,Vector const &,Vector const &,Vector const &,int,int,int,int,float>(
        pDesc: &pDesc,
        pfnProxied: NDebugOverlay::Box);
      dword_10661538 = (int)CNonMemberScriptBinding8<void (__cdecl *)(Vector const &,Vector const &,Vector const &,int,int,int,int,float),void,Vector const &,Vector const &,Vector const &,int,int,int,int,float>::Call;
      dword_1066153C = (int)NDebugOverlay::Box;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: (ScriptFunctionBinding_t *)&pDesc);
      if ( (_S2_234 & 0x1000) == 0 )
      {
        _S2_234 |= 0x1000u;
        stru_106614E4.m_Parameters.m_Memory.m_pMemory = nullptr;
        stru_106614E4.m_Parameters.m_Memory.m_nAllocationCount = 0;
        stru_106614E4.m_Parameters.m_Memory.m_nGrowSize = 0;
        stru_106614E4.m_Parameters.m_Size = 0;
        stru_106614E4.m_Parameters.m_pElements = nullptr;
        stru_106614E4.m_pszFunction = nullptr;
        stru_106614E4.m_ReturnType = 31;
        stru_106614E4.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit__::P_::_dynamic_atexit_destructor_for__binding__);
      }
      stru_106614E4.m_pszDescription = "Draw a debug overlay box";
      stru_106614E4.m_Parameters.m_Size = 0;
      stru_106614E4.m_pszScriptName = "DebugDrawLine";
      stru_106614E4.m_pszFunction = "NDebugOverlay::Line";
      ScriptDeduceFunctionSignature<void,Vector const &,Vector const &,int,int,int,bool,float>(
        pDesc: &stru_106614E4,
        pfnProxied: NDebugOverlay::Line);
      dword_10661508 = (int)CNonMemberScriptBinding7<void (__cdecl *)(Vector const &,Vector const &,int,int,int,bool,float),void,Vector const &,Vector const &,int,int,int,bool,float>::Call;
      dword_1066150C = (int)NDebugOverlay::Line;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: (ScriptFunctionBinding_t *)&stru_106614E4);
      if ( (_S2_234 & 0x2000) == 0 )
      {
        _S2_234 |= 0x2000u;
        binding_2.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_2.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_2.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_2.m_desc.m_Parameters.m_Size = 0;
        binding_2.m_desc.m_Parameters.m_pElements = nullptr;
        binding_2.m_desc.m_pszFunction = nullptr;
        binding_2.m_desc.m_ReturnType = 31;
        binding_2.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_152_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_2.m_desc.m_pszDescription = "Execute a script (internal)";
      binding_2.m_desc.m_Parameters.m_Size = 0;
      binding_2.m_desc.m_pszScriptName = "DoIncludeScript";
      binding_2.m_desc.m_pszFunction = "DoIncludeScript";
      ScriptDeduceFunctionSignature<bool,char const *,HSCRIPT__ *>(
        pDesc: &binding_2.m_desc,
        pfnProxied: (bool (__cdecl *)(const char *, HSCRIPT__ *))DoIncludeScript);
      binding_2.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding2<bool (__cdecl *)(char const *,HSCRIPT__ *),bool,char const *,HSCRIPT__ *>::Call;
      binding_2.m_pFunction = DoIncludeScript;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_2);
      if ( (_S2_234 & 0x4000) == 0 )
      {
        _S2_234 |= 0x4000u;
        binding_1.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_1.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_1.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_1.m_desc.m_Parameters.m_Size = 0;
        binding_1.m_desc.m_Parameters.m_pElements = nullptr;
        binding_1.m_desc.m_pszFunction = nullptr;
        binding_1.m_desc.m_ReturnType = 31;
        binding_1.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_161_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_1.m_desc.m_pszDescription = "Create a physics prop";
      binding_1.m_desc.m_Parameters.m_Size = 0;
      binding_1.m_desc.m_pszScriptName = "CreateProp";
      binding_1.m_desc.m_pszFunction = "CreateProp";
      ScriptDeduceFunctionSignature<HSCRIPT__ *,char const *,Vector const &,char const *,int>(
        pDesc: &binding_1.m_desc,
        pfnProxied: (HSCRIPT__ *(__cdecl *)(const char *, const Vector *, const char *, int))CreateProp);
      binding_1.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding4<HSCRIPT__ * (__cdecl *)(char const *,Vector const &,char const *,int),HSCRIPT__ *,char const *,Vector const &,char const *,int>::Call;
      binding_1.m_pFunction = CreateProp;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_1);
      if ( (_S2_234 & 0x8000) == 0 )
      {
        _S2_234 |= 0x8000u;
        binding_0.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_0.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_0.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_0.m_desc.m_Parameters.m_Size = 0;
        binding_0.m_desc.m_Parameters.m_pElements = nullptr;
        binding_0.m_desc.m_pszFunction = nullptr;
        binding_0.m_desc.m_ReturnType = 31;
        binding_0.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_170_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_0.m_desc.m_pszDescription = "Records achievement event or progress";
      binding_0.m_desc.m_Parameters.m_Size = 0;
      binding_0.m_desc.m_pszScriptName = "RecordAchievementEvent";
      binding_0.m_desc.m_pszFunction = "DoRecordAchievementEvent";
      ScriptDeduceFunctionSignature<void,char const *,int>(pDesc: &binding_0.m_desc);
      binding_0.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding2<void (__cdecl *)(char const *,int),void,char const *,int>::Call;
      binding_0.m_pFunction = DoRecordAchievementEvent;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_0);
      if ( (_S2_234 & 0x10000) == 0 )
      {
        _S2_234 |= 0x10000u;
        binding.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding.m_desc.m_Parameters.m_Size = 0;
        binding.m_desc.m_Parameters.m_pElements = nullptr;
        binding.m_desc.m_pszFunction = nullptr;
        binding.m_desc.m_ReturnType = 31;
        binding.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptServerInit_::_179_::_dynamic_atexit_destructor_for__binding__);
      }
      binding.m_desc.m_pszScriptName = "GetDeveloperLevel";
      binding.m_desc.m_pszFunction = "GetDeveloperLevel";
      binding.m_desc.m_pszDescription = "Gets the level of 'develoer'";
      binding.m_desc.m_Parameters.m_Size = 0;
      binding.m_desc.m_ReturnType = 5;
      binding.m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CNonMemberScriptBinding0<int (__cdecl *)(void),int>::Call;
      binding.m_pFunction = GetDeveloperLevel;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding);
      v3 = `ScriptClassDesc_t::GetDescList'::`2'::pHead;
      v4 = g_pScriptVM;
      v5 = g_pScriptVM;
      if ( `ScriptClassDesc_t::GetDescList'::`2'::pHead != 0 )
      {
        do
        {
          v5->RegisterClass(this: v5, a2: (ScriptClassDesc_t *)v3);
          v3 = *(_DWORD *)(v3 + 48);
        }
        while ( v3 != 0 );
        v4 = g_pScriptVM;
      }
      if ( g_pGameRules != nullptr )
      {
        g_pGameRules->RegisterScriptFunctions(this: g_pGameRules);
        v4 = g_pScriptVM;
      }
      v6 = v4;
      v7 = v4;
      RegisterInstance = v4->RegisterInstance;
      v13[1] = 33;
      v9 = (int)RegisterInstance(this: v7, a2: &g_CScriptEntityIterator_ScriptDesc, a3: &g_ScriptEntityIterator);
      SetValue = v6->SetValue;
      v13[0] = v9;
      SetValue(this: v6, a2: nullptr, a3: "Entities", a4: (const ScriptVariant_t *)v13);
      if ( scriptLanguage == SL_SQUIRREL )
        g_pScriptVM->Run_3(this: g_pScriptVM, a2: (const char *)g_Script_vscript_server, a3: true);
      VScriptRunScript(pszScriptName: "mapspawn", hScope: nullptr, bWarnMissing: false);
      if ( script_connect_debugger_on_mapspawn.m_pParent != nullptr
        && script_connect_debugger_on_mapspawn.m_pParent->m_Value.m_nValue != 0 )
      {
        g_pScriptVM->ConnectDebugger(this: g_pScriptVM);
      }
      return 1;
    }
    else
    {
      DevWarning(a1: "VM Did not start!\n");
      g_pScriptVM = nullptr;
      return 0;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_VScript, a2: 0, a3: "\nVSCRIPT: Scripting is disabled.\n");
    g_pScriptVM = nullptr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102616E0
// Name: public: virtual void CVScriptGameSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVScriptGameSystem::LevelInitPreEntity(CVScriptGameSystem *this@<ecx>, int a1@<ebx>)
{
  this->m_bAllowEntityCreationInScripts = true;
  VScriptServerInit(a1);
}

//------------------------------------------------------------------------------
// Address: 0x102616F0
// Name: public: virtual char const __near * CVScriptSaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVScriptSaveRestoreBlockHandler::GetBlockName(CVScriptSaveRestoreBlockHandler *this)
{
  return "VScriptServer";
}

//------------------------------------------------------------------------------
// Address: 0x10261700
// Name: public: virtual void CVScriptSaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptSaveRestoreBlockHandler::WriteSaveHeaders(CVScriptSaveRestoreBlockHandler *this, ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &VSCRIPT_SERVER_SAVE_RESTORE_VERSION, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10261720
// Name: public: virtual void CVScriptSaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptSaveRestoreBlockHandler::ReadRestoreHeaders(
        CVScriptSaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  pRestore->ReadShort(this: pRestore, a2: (__int16 *)&pRestore, a3: 1, a4: 0);
  this->m_fDoLoad = (_WORD)pRestore == (unsigned __int16)VSCRIPT_SERVER_SAVE_RESTORE_VERSION;
}

//------------------------------------------------------------------------------
// Address: 0x10262430
// Name: public: virtual void CVScriptSaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptSaveRestoreBlockHandler::Save(CVScriptSaveRestoreBlockHandler *this, ScriptLanguage_t pSave)
{
  ScriptLanguage_t v2; // esi
  void (__thiscall *v3)(ScriptLanguage_t, ScriptLanguage_t *, int); // edx
  void (__thiscall *v4)(ScriptLanguage_t, ScriptLanguage_t *, int); // edx
  CUtlBuffer buffer; // [esp+4h] [ebp-30h] BYREF

  v2 = pSave;
  (*(void (__thiscall **)(ScriptLanguage_t))(*(_DWORD *)pSave + 28))(a1: pSave);
  v3 = *(void (__thiscall **)(ScriptLanguage_t, ScriptLanguage_t *, int))(*(_DWORD *)v2 + 52);
  pSave = g_pScriptVM != nullptr;
  v3(a1: v2, a2: &pSave, a3: 1);
  if ( g_pScriptVM != nullptr )
  {
    pSave = g_pScriptVM->GetLanguage(this: g_pScriptVM);
    (*(void (__thiscall **)(ScriptLanguage_t, ScriptLanguage_t *, int))(*(_DWORD *)v2 + 52))(a1: v2, a2: &pSave, a3: 1);
    CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
    g_pScriptVM->WriteState(this: g_pScriptVM, a2: &buffer);
    v4 = *(void (__thiscall **)(ScriptLanguage_t, ScriptLanguage_t *, int))(*(_DWORD *)v2 + 52);
    pSave = buffer.m_Put;
    v4(a1: v2, a2: &pSave, a3: 1);
    if ( pSave > SL_NONE )
      (*(void (__thiscall **)(ScriptLanguage_t, unsigned __int8 *, ScriptLanguage_t))(*(_DWORD *)v2 + 76))(
        a1: v2,
        a2: buffer.m_Memory.m_pMemory,
        a3: pSave);
    if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
  }
  (*(void (__thiscall **)(ScriptLanguage_t))(*(_DWORD *)v2 + 36))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10262500
// Name: public: virtual void CVScriptSaveRestoreBlockHandler::PostRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptSaveRestoreBlockHandler::PostRestore(CVScriptSaveRestoreBlockHandler *this)
{
  CVScriptSaveRestoreBlockHandler *v1; // esi
  CUtlMap<char const *,CBaseEntity *,unsigned short> *p_m_InstanceMap; // ebx
  int Inorder; // edi
  CBaseEntity *elem; // esi
  const char *pszValue; // eax
  ScriptVariant_t variant; // [esp+Ch] [ebp-Ch] BYREF
  CVScriptSaveRestoreBlockHandler *v7; // [esp+14h] [ebp-4h]

  v1 = this;
  p_m_InstanceMap = &this->m_InstanceMap;
  v7 = this;
  Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CBaseEntity *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_InstanceMap.m_Tree);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      elem = v1->m_InstanceMap.m_Tree.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.elem;
      if ( elem->m_hScriptInstance != nullptr )
      {
        pszValue = elem->m_iszScriptId.pszValue;
        *(_DWORD *)&variant.m_type = 0;
        variant.m_int = 0;
        if ( pszValue == nullptr )
          pszValue = locale;
        if ( g_pScriptVM->GetValue(this: g_pScriptVM, a2: nullptr, a3: pszValue, a4: &variant) && variant.m_type == 33 )
        {
          elem->m_ScriptScope.m_hScope = (HSCRIPT__ *)variant.m_int;
          CBaseEntity::RunPrecacheScripts(this: elem);
        }
      }
      else
      {
        elem->m_iszScriptId.pszValue = nullptr;
      }
      Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CBaseEntity *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                    this: &p_m_InstanceMap->m_Tree,
                                    i: Inorder);
      if ( Inorder == 0xFFFF )
        break;
      v1 = v7;
    }
  }
  CUtlRBTree<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CBaseEntity *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &p_m_InstanceMap->m_Tree);
  p_m_InstanceMap->m_Tree.m_FirstFree = -1;
  if ( p_m_InstanceMap->m_Tree.m_Elements.m_nGrowSize < 0 )
  {
    p_m_InstanceMap->m_Tree.m_LastAlloc.index = -1;
  }
  else
  {
    if ( p_m_InstanceMap->m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_InstanceMap->m_Tree.m_Elements.m_pMemory);
      p_m_InstanceMap->m_Tree.m_Elements.m_pMemory = nullptr;
    }
    p_m_InstanceMap->m_Tree.m_Elements.m_nAllocationCount = 0;
    p_m_InstanceMap->m_Tree.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262610
// Name: void InitCScriptEntityIteratorScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitCScriptEntityIteratorScriptDesc(int a1@<edi>)
{
  ScriptFunctionBinding_t *v1; // eax
  ScriptFunctionBinding_t *v2; // esi
  ScriptFunctionBinding_t *v3; // esi
  ScriptFunctionBinding_t *v4; // esi
  ScriptFunctionBinding_t *v5; // esi
  ScriptFunctionBinding_t *v6; // esi
  ScriptFunctionBinding_t *v7; // esi
  ScriptFunctionBinding_t *v8; // esi
  ScriptFunctionBinding_t *v9; // esi
  ScriptFunctionBinding_t *v10; // esi
  ScriptFunctionBinding_t *v11; // esi
  ScriptFunctionBinding_t *v12; // esi
  HSCRIPT__ *(__thiscall *__ptr64 v13)(CSceneEntity *, const char *); // [esp-10h] [ebp-10h]

  if ( !bInitialized_7 )
  {
    HIDWORD(v13) = a1;
    bInitialized_7 = true;
    g_CScriptEntityIterator_ScriptDesc.m_pszDescription = "!The global list of entities";
    g_CScriptEntityIterator_ScriptDesc.m_pszScriptName = "CEntities";
    g_CScriptEntityIterator_ScriptDesc.m_pszClassname = "CScriptEntityIterator";
    g_CScriptEntityIterator_ScriptDesc.m_pBaseDesc = nullptr;
    g_CScriptEntityIterator_ScriptDesc.pHelper = nullptr;
    v1 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                     this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                     elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v1->m_desc.m_pszDescription = "Begin an iteration over the list of entities";
    v1->m_desc.m_pszScriptName = "First";
    v1->m_desc.m_pszFunction = "First";
    v1->m_desc.m_ReturnType = 33;
    v1->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v1->m_pFunction = CScriptEntityIterator::First;
    v1->m_flags = 1;
    v2 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                     this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                     elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v2->m_desc.m_pszDescription = "Continue an iteration over the list of entities, providing reference to a previously found entity";
    v2->m_desc.m_pszScriptName = "Next";
    v2->m_desc.m_pszFunction = "Next";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *>(
      pDesc: &v2->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptEntityIterator::Next);
    v2->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *),HSCRIPT__ *,HSCRIPT__ *>::Call;
    v2->m_pFunction = CScriptEntityIterator::Next;
    v2->m_flags = 1;
    v3 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                     this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                     elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    LODWORD(v13) = CScriptEntityIterator::CreateByClassname;
    v3->m_desc.m_pszDescription = "Creates an entity by classname";
    v3->m_desc.m_pszScriptName = "CreateByClassname";
    v3->m_desc.m_pszFunction = "CreateByClassname";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,char const *>(
      pDesc: &v3->m_desc,
      pObject: nullptr,
      pfnProxied: v13);
    v3->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(char const *),HSCRIPT__ *,char const *>::Call;
    v3->m_pFunction = CScriptEntityIterator::CreateByClassname;
    v3->m_flags = 1;
    v4 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                     this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                     elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v4->m_desc.m_pszDescription = "Find entities by class name. Pass 'null' to start an iteration, or reference to a prev"
                                  "iously found entity to continue a search";
    v4->m_desc.m_pszScriptName = "FindByClassname";
    v4->m_desc.m_pszFunction = "FindByClassname";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *,char const *>(
      pDesc: &v4->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptEntityIterator::FindByClassname);
    v4->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *,char const *),HSCRIPT__ *,HSCRIPT__ *,char const *>::Call;
    v4->m_pFunction = CScriptEntityIterator::FindByClassname;
    v4->m_flags = 1;
    v5 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                     this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                     elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v5->m_desc.m_pszDescription = "Find entities by name. Pass 'null' to start an iteration, or reference to a previously"
                                  " found entity to continue a search";
    v5->m_desc.m_pszScriptName = "FindByName";
    v5->m_desc.m_pszFunction = "FindByName";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *,char const *>(
      pDesc: &v5->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptEntityIterator::FindByName);
    v5->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *,char const *),HSCRIPT__ *,HSCRIPT__ *,char const *>::Call;
    v5->m_pFunction = CScriptEntityIterator::FindByName;
    v5->m_flags = 1;
    v6 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                     this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                     elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v6->m_desc.m_pszDescription = "Find entities within a radius. Pass 'null' to start an iteration, or reference to a pr"
                                  "eviously found entity to continue a search";
    v6->m_desc.m_pszScriptName = "FindInSphere";
    v6->m_desc.m_pszFunction = "FindInSphere";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *,Vector const &,float>(
      pDesc: &v6->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptEntityIterator::FindInSphere);
    v6->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding3<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *,Vector const &,float),HSCRIPT__ *,HSCRIPT__ *,Vector const &,float>::Call;
    v6->m_pFunction = CScriptEntityIterator::FindInSphere;
    v6->m_flags = 1;
    v7 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                     this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                     elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v7->m_desc.m_pszDescription = "Find entities by targetname. Pass 'null' to start an iteration, or reference to a prev"
                                  "iously found entity to continue a search";
    v7->m_desc.m_pszScriptName = "FindByTarget";
    v7->m_desc.m_pszFunction = "FindByTarget";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *,char const *>(
      pDesc: &v7->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptEntityIterator::FindByTarget);
    v7->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *,char const *),HSCRIPT__ *,HSCRIPT__ *,char const *>::Call;
    v7->m_pFunction = CScriptEntityIterator::FindByTarget;
    v7->m_flags = 1;
    v8 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                     this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                     elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v8->m_desc.m_pszDescription = "Find entities by model name. Pass 'null' to start an iteration, or reference to a prev"
                                  "iously found entity to continue a search";
    v8->m_desc.m_pszScriptName = "FindByModel";
    v8->m_desc.m_pszFunction = "FindByModel";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *,char const *>(
      pDesc: &v8->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptEntityIterator::FindByModel);
    v8->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *,char const *),HSCRIPT__ *,HSCRIPT__ *,char const *>::Call;
    v8->m_pFunction = CScriptEntityIterator::FindByModel;
    v8->m_flags = 1;
    v9 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                     this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                     elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v9->m_desc.m_pszDescription = "Find entities by name nearest to a point.";
    v9->m_desc.m_pszScriptName = "FindByNameNearest";
    v9->m_desc.m_pszFunction = "FindByNameNearest";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,char const *,Vector const &,float>(
      pDesc: &v9->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptEntityIterator::FindByNameNearest);
    v9->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding3<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(char const *,Vector const &,float),HSCRIPT__ *,char const *,Vector const &,float>::Call;
    v9->m_pFunction = CScriptEntityIterator::FindByNameNearest;
    v9->m_flags = 1;
    v10 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                      this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                      elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v10->m_desc.m_pszDescription = "Find entities by name within a radius. Pass 'null' to start an iteration, or referenc"
                                   "e to a previously found entity to continue a search";
    v10->m_desc.m_pszScriptName = "FindByNameWithin";
    v10->m_desc.m_pszFunction = "FindByNameWithin";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *,char const *,Vector const &,float>(
      pDesc: &v10->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptEntityIterator::FindByNameWithin);
    v10->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding4<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *,char const *,Vector const &,float),HSCRIPT__ *,HSCRIPT__ *,char const *,Vector const &,float>::Call;
    v10->m_pFunction = CScriptEntityIterator::FindByNameWithin;
    v10->m_flags = 1;
    v11 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                      this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                      elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v11->m_desc.m_pszDescription = "Find entities by class name nearest to a point.";
    v11->m_desc.m_pszScriptName = "FindByClassnameNearest";
    v11->m_desc.m_pszFunction = "FindByClassnameNearest";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,char const *,Vector const &,float>(
      pDesc: &v11->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptEntityIterator::FindByClassnameNearest);
    v11->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding3<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(char const *,Vector const &,float),HSCRIPT__ *,char const *,Vector const &,float>::Call;
    v11->m_pFunction = CScriptEntityIterator::FindByClassnameNearest;
    v11->m_flags = 1;
    v12 = &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                      this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings,
                                                                                      elem: g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings.m_Size)];
    v12->m_desc.m_pszDescription = "Find entities by class name within a radius. Pass 'null' to start an iteration, or re"
                                   "ference to a previously found entity to continue a search";
    v12->m_desc.m_pszScriptName = "FindByClassnameWithin";
    v12->m_desc.m_pszFunction = "FindByClassnameWithin";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *,char const *,Vector const &,float>(
      pDesc: &v12->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptEntityIterator::FindByClassnameWithin);
    v12->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding4<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(HSCRIPT__ *,char const *,Vector const &,float),HSCRIPT__ *,HSCRIPT__ *,char const *,Vector const &,float>::Call;
    v12->m_flags = 1;
    v12->m_pFunction = CScriptEntityIterator::FindByClassnameWithin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262A20
// Name: void InitCScriptKeyValuesScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitCScriptKeyValuesScriptDesc(int a1@<esi>)
{
  ScriptFunctionBinding_t *v1; // esi
  ScriptFunctionBinding_t *v2; // eax
  ScriptFunctionBinding_t *v3; // eax
  ScriptFunctionBinding_t *v4; // esi
  ScriptFunctionBinding_t *v5; // esi
  ScriptFunctionBinding_t *v6; // esi
  ScriptFunctionBinding_t *v7; // esi
  ScriptFunctionBinding_t *v8; // esi
  ScriptFunctionBinding_t *v9; // eax
  HSCRIPT__ *(__thiscall *__ptr64 v10)(CSceneEntity *, const char *); // [esp-Ch] [ebp-Ch]

  if ( !bInitialized_8 )
  {
    g_CScriptKeyValues_ScriptDesc.m_pszScriptName = "CScriptKeyValues";
    g_CScriptKeyValues_ScriptDesc.m_pszClassname = "CScriptKeyValues";
    HIDWORD(v10) = a1;
    bInitialized_8 = true;
    g_CScriptKeyValues_ScriptDesc.m_pszDescription = "Wrapper class over KeyValues instance";
    g_CScriptKeyValues_ScriptDesc.m_pBaseDesc = nullptr;
    g_CScriptKeyValues_ScriptDesc.pHelper = nullptr;
    g_CScriptKeyValues_ScriptDesc.m_pfnConstruct = (void *(__cdecl *)())CScriptConstructor<CScriptKeyValues>::Construct;
    g_CScriptKeyValues_ScriptDesc.m_pfnDestruct = (void (__cdecl *)(void *))CScriptConstructor<CScriptKeyValues>::Destruct;
    v1 = &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                this: &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings,
                                                                                elem: g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Size)];
    LODWORD(v10) = CScriptKeyValues::ScriptFindKey;
    v1->m_desc.m_pszDescription = "Given a KeyValues object and a key name, find a KeyValues object associated with the key name";
    v1->m_desc.m_pszScriptName = "FindKey";
    v1->m_desc.m_pszFunction = "ScriptFindKey";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,char const *>(
      pDesc: &v1->m_desc,
      pObject: nullptr,
      pfnProxied: v10);
    v1->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(char const *),HSCRIPT__ *,char const *>::Call;
    v1->m_pFunction = CScriptKeyValues::ScriptFindKey;
    v1->m_flags = 1;
    v2 = &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                this: &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings,
                                                                                elem: g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Size)];
    v2->m_desc.m_pszDescription = "Given a KeyValues object, return the first sub key object";
    v2->m_desc.m_pszScriptName = "GetFirstSubKey";
    v2->m_desc.m_pszFunction = "ScriptGetFirstSubKey";
    v2->m_desc.m_ReturnType = 33;
    v2->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v2->m_pFunction = CScriptKeyValues::ScriptGetFirstSubKey;
    v2->m_flags = 1;
    v3 = &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                this: &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings,
                                                                                elem: g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Size)];
    v3->m_desc.m_pszDescription = "Given a KeyValues object, return the next key object in a sub key group";
    v3->m_desc.m_pszScriptName = "GetNextKey";
    v3->m_desc.m_pszFunction = "ScriptGetNextKey";
    v3->m_desc.m_ReturnType = 33;
    v3->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v3->m_pFunction = CScriptKeyValues::ScriptGetNextKey;
    v3->m_flags = 1;
    v4 = &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                this: &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings,
                                                                                elem: g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Size)];
    v4->m_desc.m_pszDescription = "Given a KeyValues object and a key name, return associated integer value";
    v4->m_desc.m_pszScriptName = "GetKeyInt";
    v4->m_desc.m_pszFunction = "ScriptGetKeyValueInt";
    ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,int,char const *>(
      pDesc: &v4->m_desc,
      pObject: nullptr,
      pfnProxied: (int (__thiscall *)(CBaseAnimating *, const char *))CScriptKeyValues::ScriptGetKeyValueInt);
    v4->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CScriptKeyValues *,int (__thiscall CScriptKeyValues::*)(char const *),int,char const *>::Call;
    v4->m_pFunction = CScriptKeyValues::ScriptGetKeyValueInt;
    v4->m_flags = 1;
    v5 = &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                this: &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings,
                                                                                elem: g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Size)];
    v5->m_desc.m_pszDescription = "Given a KeyValues object and a key name, return associated float value";
    v5->m_desc.m_pszScriptName = "GetKeyFloat";
    v5->m_desc.m_pszFunction = "ScriptGetKeyValueFloat";
    ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,float,char const *>(
      pDesc: &v5->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptKeyValues::ScriptGetKeyValueFloat);
    v5->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CScriptKeyValues *,float (__thiscall CScriptKeyValues::*)(char const *),float,char const *>::Call;
    v5->m_pFunction = CScriptKeyValues::ScriptGetKeyValueFloat;
    v5->m_flags = 1;
    v6 = &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                this: &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings,
                                                                                elem: g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Size)];
    v6->m_desc.m_pszDescription = "Given a KeyValues object and a key name, return associated bool value";
    v6->m_desc.m_pszScriptName = "GetKeyBool";
    v6->m_desc.m_pszFunction = "ScriptGetKeyValueBool";
    ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,bool,char const *>(
      pDesc: &v6->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptKeyValues::ScriptGetKeyValueBool);
    v6->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CScriptKeyValues *,bool (__thiscall CScriptKeyValues::*)(char const *),bool,char const *>::Call;
    v6->m_pFunction = CScriptKeyValues::ScriptGetKeyValueBool;
    v6->m_flags = 1;
    v7 = &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                this: &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings,
                                                                                elem: g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Size)];
    v7->m_desc.m_pszDescription = "Given a KeyValues object and a key name, return associated string value";
    v7->m_desc.m_pszScriptName = "GetKeyString";
    v7->m_desc.m_pszFunction = "ScriptGetKeyValueString";
    ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,char const *,char const *>(
      pDesc: &v7->m_desc,
      pfnProxied: nullptr);
    v7->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CScriptKeyValues *,char const * (__thiscall CScriptKeyValues::*)(char const *),char const *,char const *>::Call;
    v7->m_pFunction = CScriptKeyValues::ScriptGetKeyValueString;
    v7->m_flags = 1;
    v8 = &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                this: &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings,
                                                                                elem: g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Size)];
    v8->m_desc.m_pszDescription = "Given a KeyValues object and a key name, return true if key name has no value";
    v8->m_desc.m_pszScriptName = "IsKeyEmpty";
    v8->m_desc.m_pszFunction = "ScriptIsKeyValueEmpty";
    ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,bool,char const *>(
      pDesc: &v8->m_desc,
      pObject: nullptr,
      pfnProxied: CScriptKeyValues::ScriptIsKeyValueEmpty);
    v8->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CScriptKeyValues *,bool (__thiscall CScriptKeyValues::*)(char const *),bool,char const *>::Call;
    v8->m_pFunction = CScriptKeyValues::ScriptIsKeyValueEmpty;
    v8->m_flags = 1;
    v9 = &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                this: &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings,
                                                                                elem: g_CScriptKeyValues_ScriptDesc.m_FunctionBindings.m_Size)];
    v9->m_desc.m_pszDescription = "Given a root KeyValues object, release its contents";
    v9->m_desc.m_pszScriptName = "ReleaseKeyValues";
    v9->m_desc.m_pszFunction = "ScriptReleaseKeyValues";
    v9->m_desc.m_ReturnType = 0;
    v9->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CEnvEntityMaker *,void (__thiscall CEnvEntityMaker::*)(void),void>::Call;
    v9->m_pFunction = CScriptKeyValues::ScriptReleaseKeyValues;
    v9->m_flags = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262D40
// Name: public: virtual void CVScriptSaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptSaveRestoreBlockHandler::Restore(
        CVScriptSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        bool createPlayers)
{
  CVScriptSaveRestoreBlockHandler *v3; // edi
  bool v4; // zf
  CBaseEntity *Ent; // ebx
  IScriptVM_vtbl *v6; // esi
  int v7; // eax
  const char *pszValue; // eax
  CUtlRBTree<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CBaseEntity *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_Tree; // esi
  unsigned __int16 v10; // cx
  int v11; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short> *v12; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short> *v14; // eax
  CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t *p_m_Data; // eax
  int v16; // edi
  int v17; // edi
  int (__thiscall *ReadData)(IRestore *, char *, int, int); // edx
  CUtlBuffer buffer; // [esp+4h] [ebp-44h] BYREF
  CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t insert; // [esp+34h] [ebp-14h] BYREF
  CVScriptSaveRestoreBlockHandler *v21; // [esp+3Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+40h] [ebp-8h] BYREF
  bool leftchild; // [esp+47h] [ebp-1h] BYREF

  v3 = this;
  v4 = !this->m_fDoLoad;
  v21 = this;
  if ( !v4 || g_pScriptVM == nullptr )
  {
    Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
    if ( Ent != nullptr )
    {
      while ( 1 )
      {
        if ( Ent->m_iszScriptId.pszValue != nullptr )
        {
          v6 = g_pScriptVM->__vftable;
          v7 = (int)Ent->GetScriptDesc(this: Ent);
          v6->RegisterClass(this: g_pScriptVM, a2: (ScriptClassDesc_t *)v7);
          pszValue = Ent->m_iszScriptId.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          insert.key = pszValue;
          p_m_Tree = &v3->m_InstanceMap.m_Tree;
          insert.elem = Ent;
          *(_DWORD *)parent = 0xFFFF;
          leftchild = false;
          CUtlRBTree<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CBaseEntity *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
            this: &v3->m_InstanceMap.m_Tree,
            &insert,
            parent,
            &leftchild);
          v10 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
                  this: (CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v3->m_InstanceMap,
                  a2: (const char *)v3);
          v11 = v10;
          v12 = &p_m_Tree->m_Elements.m_pMemory[v11];
          v12->m_Parent = parent[0];
          v12->m_Right = -1;
          v12->m_Left = -1;
          v12->m_Tag = 0;
          if ( parent[0] == 0xFFFF )
          {
            p_m_Tree->m_Root = v10;
          }
          else
          {
            m_pMemory = p_m_Tree->m_Elements.m_pMemory;
            if ( leftchild )
              m_pMemory[parent[0]].m_Left = v10;
            else
              m_pMemory[parent[0]].m_Right = v10;
          }
          CUtlRBTree<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CBaseEntity *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
            this: p_m_Tree,
            elem: v10);
          v14 = p_m_Tree->m_Elements.m_pMemory;
          ++p_m_Tree->m_NumElements;
          p_m_Data = &v14[v11].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = insert;
        }
        Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
        if ( Ent == nullptr )
          break;
        v3 = v21;
      }
    }
    pRestore->StartBlock(this: pRestore);
    if ( pRestore->ReadInt(this: pRestore) != 0 )
    {
      v16 = pRestore->ReadInt(this: pRestore);
      if ( v16 == g_pScriptVM->GetLanguage(this: g_pScriptVM) )
      {
        v17 = pRestore->ReadInt(this: pRestore);
        if ( v17 > 0 )
        {
          CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
          CUtlBuffer::EnsureCapacity(this: &buffer, num: v17);
          CUtlBuffer::EnsureCapacity(this: &buffer, num: v17);
          ReadData = pRestore->ReadData;
          buffer.m_nMaxPut = v17;
          ReadData(this: pRestore, a2: (char *)buffer.m_Memory.m_pMemory, a3: v17, a4: 0);
          g_pScriptVM->ReadState(this: g_pScriptVM, a2: &buffer);
          CUtlBuffer::~CUtlBuffer(this: &buffer);
        }
      }
    }
    pRestore->EndBlock(this: pRestore);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035F2D0
// Name: public: static bool CDefOps<class CUtlSymbol const>::LessFunc(class CUtlSymbol const __near &,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<CUtlSymbol const>::LessFunc(
        const ResponseRules::CriteriaSet::CritEntry_t *lhs,
        const ResponseRules::CriteriaSet::CritEntry_t *rhs)
{
  return lhs->criterianame.m_Id < rhs->criterianame.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10405100
// Name: _dynamic_initializer_for__server_game_time_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__server_game_time_command__()
{
  ConCommand::ConCommand(
    this: &server_game_time_command,
    pName: "server_game_time",
    callback: server_game_time,
    pHelpString: "Gives the game time in seconds (server's curtime)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__server_game_time_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BF10
// Name: _dynamic_atexit_destructor_for__server_game_time_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__server_game_time_command__()
{
  ConCommand::~ConCommand(this: &server_game_time_command);
}

//------------------------------------------------------------------------------
// Address: 0x10114960
// Name: void ScriptDeduceFunctionSignature<class CEnvEntityMaker __near *,class CEnvEntityMaker,void,class Vector const __near &,class Vector const __near &>(struct ScriptFuncDescriptor_t __near *,class CEnvEntityMaker __near *,void (CEnvEntityMaker::*)(class Vector const __near &,class Vector const __near &))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CEnvEntityMaker *,CEnvEntityMaker,void,Vector const &,Vector const &>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 0;
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
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 3;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 3;
}

//------------------------------------------------------------------------------
// Address: 0x1025F0C0
// Name: void ScriptDeduceFunctionSignature<class CScriptEntityIterator __near *,class CScriptEntityIterator,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *>(struct ScriptFuncDescriptor_t __near *,class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(struct HSCRIPT__ __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 33;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)33;
}

//------------------------------------------------------------------------------
// Address: 0x1025F170
// Name: void ScriptDeduceFunctionSignature<class CScriptEntityIterator __near *,class CScriptEntityIterator,struct HSCRIPT__ __near *,char const __near *>(struct ScriptFuncDescriptor_t __near *,class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(char const __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,char const *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 33;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)32;
}

//------------------------------------------------------------------------------
// Address: 0x1025F220
// Name: void ScriptDeduceFunctionSignature<class CScriptEntityIterator __near *,class CScriptEntityIterator,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,char const __near *>(struct ScriptFuncDescriptor_t __near *,class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(struct HSCRIPT__ __near *,char const __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *,char const *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 33;
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
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 33;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 32;
}

//------------------------------------------------------------------------------
// Address: 0x1025F320
// Name: void ScriptDeduceFunctionSignature<class CScriptEntityIterator __near *,class CScriptEntityIterator,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,class Vector const __near &,float>(struct ScriptFuncDescriptor_t __near *,class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(struct HSCRIPT__ __near *,class Vector const __near &,float))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *,Vector const &,float>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // eax

  pDesc->m_ReturnType = 33;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 3 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 3;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 12);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 12);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  m_Size = pDesc->m_Parameters.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 33;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 3;
  v14 = pDesc->m_Parameters.m_Size;
  v15 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v14 + 1 > v15 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v14 - v15 + 1);
  ++pDesc->m_Parameters.m_Size;
  v16 = p_m_Parameters->m_Memory.m_pMemory;
  v17 = pDesc->m_Parameters.m_Size - v14 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
  v18 = &p_m_Parameters->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025F480
// Name: void ScriptDeduceFunctionSignature<class CScriptEntityIterator __near *,class CScriptEntityIterator,struct HSCRIPT__ __near *,char const __near *,class Vector const __near &,float>(struct ScriptFuncDescriptor_t __near *,class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(char const __near *,class Vector const __near &,float))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,char const *,Vector const &,float>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // eax

  pDesc->m_ReturnType = 33;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 3 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 3;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 12);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 12);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  m_Size = pDesc->m_Parameters.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 3;
  v14 = pDesc->m_Parameters.m_Size;
  v15 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v14 + 1 > v15 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v14 - v15 + 1);
  ++pDesc->m_Parameters.m_Size;
  v16 = p_m_Parameters->m_Memory.m_pMemory;
  v17 = pDesc->m_Parameters.m_Size - v14 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
  v18 = &p_m_Parameters->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025F5E0
// Name: void ScriptDeduceFunctionSignature<class CScriptEntityIterator __near *,class CScriptEntityIterator,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,char const __near *,class Vector const __near &,float>(struct ScriptFuncDescriptor_t __near *,class CScriptEntityIterator __near *,struct HSCRIPT__ __near * (CScriptEntityIterator::*)(struct HSCRIPT__ __near *,char const __near *,class Vector const __near &,float))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,HSCRIPT__ *,char const *,Vector const &,float>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // eax
  int v19; // edi
  int v20; // eax
  int *v21; // ecx
  int v22; // eax
  int *v23; // eax

  pDesc->m_ReturnType = 33;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 4 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 4;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 16);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 16);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  m_Size = pDesc->m_Parameters.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 33;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 32;
  v14 = pDesc->m_Parameters.m_Size;
  v15 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v14 + 1 > v15 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v14 - v15 + 1);
  ++pDesc->m_Parameters.m_Size;
  v16 = p_m_Parameters->m_Memory.m_pMemory;
  v17 = pDesc->m_Parameters.m_Size - v14 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
  v18 = &p_m_Parameters->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 3;
  v19 = pDesc->m_Parameters.m_Size;
  v20 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v19 + 1 > v20 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v19 - v20 + 1);
  ++pDesc->m_Parameters.m_Size;
  v21 = p_m_Parameters->m_Memory.m_pMemory;
  v22 = pDesc->m_Parameters.m_Size - v19 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v22 > 0 )
    _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
  v23 = &p_m_Parameters->m_Memory.m_pMemory[v19];
  if ( v23 != nullptr )
    *v23 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025F790
// Name: void ScriptDeduceFunctionSignature<class CScriptKeyValues __near *,class CScriptKeyValues,int,char const __near *>(struct ScriptFuncDescriptor_t __near *,class CScriptKeyValues __near *,int (CScriptKeyValues::*)(char const __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,int,char const *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 5;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)32;
}

//------------------------------------------------------------------------------
// Address: 0x1025F840
// Name: void ScriptDeduceFunctionSignature<class CScriptKeyValues __near *,class CScriptKeyValues,float,char const __near *>(struct ScriptFuncDescriptor_t __near *,class CScriptKeyValues __near *,float (CScriptKeyValues::*)(char const __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,float,char const *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 1;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)32;
}

//------------------------------------------------------------------------------
// Address: 0x1025F8F0
// Name: void ScriptDeduceFunctionSignature<class CScriptKeyValues __near *,class CScriptKeyValues,bool,char const __near *>(struct ScriptFuncDescriptor_t __near *,class CScriptKeyValues __near *,bool (CScriptKeyValues::*)(char const __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,bool,char const *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 6;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)32;
}

//------------------------------------------------------------------------------
// Address: 0x1025F9A0
// Name: void ScriptDeduceFunctionSignature<class CScriptKeyValues __near *,class CScriptKeyValues,char const __near *,char const __near *>(struct ScriptFuncDescriptor_t __near *,class CScriptKeyValues __near *,char const __near * (CScriptKeyValues::*)(char const __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,char const *,char const *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 32;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)32;
}

//------------------------------------------------------------------------------
// Address: 0x1025FA50
// Name: void ScriptDeduceFunctionSignature<float,class Vector const __near &,class Vector const __near &,struct HSCRIPT__ __near *>(struct ScriptFuncDescriptor_t __near *,float (*)(class Vector const __near &,class Vector const __near &,struct HSCRIPT__ __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<float,Vector const &,Vector const &,HSCRIPT__ *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // eax

  pDesc->m_ReturnType = 1;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 3 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 3;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 12);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 12);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 3;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 3;
  v14 = pDesc->m_Parameters.m_Size;
  v15 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v14 + 1 > v15 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v14 - v15 + 1);
  ++pDesc->m_Parameters.m_Size;
  v16 = p_m_Parameters->m_Memory.m_pMemory;
  v17 = pDesc->m_Parameters.m_Size - v14 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
  v18 = &p_m_Parameters->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 33;
}

//------------------------------------------------------------------------------
// Address: 0x1025FBB0
// Name: void ScriptDeduceFunctionSignature<void,char const __near *,char const __near *,char const __near *,float,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *>(struct ScriptFuncDescriptor_t __near *,void (*)(char const __near *,char const __near *,char const __near *,float,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<void,char const *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // eax
  int v19; // edi
  int v20; // eax
  int *v21; // ecx
  int v22; // eax
  int *v23; // eax
  int v24; // edi
  int v25; // eax
  int *v26; // ecx
  int v27; // eax
  int *v28; // eax
  int v29; // edi
  int v30; // eax
  int *v31; // ecx
  int v32; // eax
  int *v33; // eax

  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 6 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 6;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 24);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 24);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 32;
  v14 = pDesc->m_Parameters.m_Size;
  v15 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v14 + 1 > v15 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v14 - v15 + 1);
  ++pDesc->m_Parameters.m_Size;
  v16 = p_m_Parameters->m_Memory.m_pMemory;
  v17 = pDesc->m_Parameters.m_Size - v14 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
  v18 = &p_m_Parameters->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 32;
  v19 = pDesc->m_Parameters.m_Size;
  v20 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v19 + 1 > v20 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v19 - v20 + 1);
  ++pDesc->m_Parameters.m_Size;
  v21 = p_m_Parameters->m_Memory.m_pMemory;
  v22 = pDesc->m_Parameters.m_Size - v19 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v22 > 0 )
    _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
  v23 = &p_m_Parameters->m_Memory.m_pMemory[v19];
  if ( v23 != nullptr )
    *v23 = 1;
  v24 = pDesc->m_Parameters.m_Size;
  v25 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v24 + 1 > v25 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v24 - v25 + 1);
  ++pDesc->m_Parameters.m_Size;
  v26 = p_m_Parameters->m_Memory.m_pMemory;
  v27 = pDesc->m_Parameters.m_Size - v24 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v27 > 0 )
    _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
  v28 = &p_m_Parameters->m_Memory.m_pMemory[v24];
  if ( v28 != nullptr )
    *v28 = 33;
  v29 = pDesc->m_Parameters.m_Size;
  v30 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v29 + 1 > v30 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v29 - v30 + 1);
  ++pDesc->m_Parameters.m_Size;
  v31 = p_m_Parameters->m_Memory.m_pMemory;
  v32 = pDesc->m_Parameters.m_Size - v29 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v32 > 0 )
    _V_memmove(dest: &v31[v29 + 1], src: &v31[v29], count: 4 * v32);
  v33 = &p_m_Parameters->m_Memory.m_pMemory[v29];
  if ( v33 != nullptr )
    *v33 = 33;
}

//------------------------------------------------------------------------------
// Address: 0x1025FE00
// Name: void ScriptDeduceFunctionSignature<void,struct HSCRIPT__ __near *,char const __near *,char const __near *,float,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *>(struct ScriptFuncDescriptor_t __near *,void (*)(struct HSCRIPT__ __near *,char const __near *,char const __near *,float,struct HSCRIPT__ __near *,struct HSCRIPT__ __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<void,HSCRIPT__ *,char const *,char const *,float,HSCRIPT__ *,HSCRIPT__ *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // eax
  int v19; // edi
  int v20; // eax
  int *v21; // ecx
  int v22; // eax
  int *v23; // eax
  int v24; // edi
  int v25; // eax
  int *v26; // ecx
  int v27; // eax
  int *v28; // eax
  int v29; // edi
  int v30; // eax
  int *v31; // ecx
  int v32; // eax
  int *v33; // eax

  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 6 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 6;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 24);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 24);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 33;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 32;
  v14 = pDesc->m_Parameters.m_Size;
  v15 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v14 + 1 > v15 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v14 - v15 + 1);
  ++pDesc->m_Parameters.m_Size;
  v16 = p_m_Parameters->m_Memory.m_pMemory;
  v17 = pDesc->m_Parameters.m_Size - v14 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
  v18 = &p_m_Parameters->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 32;
  v19 = pDesc->m_Parameters.m_Size;
  v20 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v19 + 1 > v20 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v19 - v20 + 1);
  ++pDesc->m_Parameters.m_Size;
  v21 = p_m_Parameters->m_Memory.m_pMemory;
  v22 = pDesc->m_Parameters.m_Size - v19 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v22 > 0 )
    _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
  v23 = &p_m_Parameters->m_Memory.m_pMemory[v19];
  if ( v23 != nullptr )
    *v23 = 1;
  v24 = pDesc->m_Parameters.m_Size;
  v25 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v24 + 1 > v25 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v24 - v25 + 1);
  ++pDesc->m_Parameters.m_Size;
  v26 = p_m_Parameters->m_Memory.m_pMemory;
  v27 = pDesc->m_Parameters.m_Size - v24 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v27 > 0 )
    _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
  v28 = &p_m_Parameters->m_Memory.m_pMemory[v24];
  if ( v28 != nullptr )
    *v28 = 33;
  v29 = pDesc->m_Parameters.m_Size;
  v30 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v29 + 1 > v30 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v29 - v30 + 1);
  ++pDesc->m_Parameters.m_Size;
  v31 = p_m_Parameters->m_Memory.m_pMemory;
  v32 = pDesc->m_Parameters.m_Size - v29 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v32 > 0 )
    _V_memmove(dest: &v31[v29 + 1], src: &v31[v29], count: 4 * v32);
  v33 = &p_m_Parameters->m_Memory.m_pMemory[v29];
  if ( v33 != nullptr )
    *v33 = 33;
}

//------------------------------------------------------------------------------
// Address: 0x10260050
// Name: void ScriptDeduceFunctionSignature<void,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,float>(struct ScriptFuncDescriptor_t __near *,void (*)(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,float))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<void,Vector const &,Vector const &,Vector const &,int,int,int,int,float>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // eax
  int v19; // edi
  int v20; // eax
  int *v21; // ecx
  int v22; // eax
  int *v23; // eax
  int v24; // edi
  int v25; // eax
  int *v26; // ecx
  int v27; // eax
  int *v28; // eax
  int v29; // edi
  int v30; // eax
  int *v31; // ecx
  int v32; // eax
  int *v33; // eax
  int v34; // edi
  int v35; // eax
  int *v36; // ecx
  int v37; // eax
  int *v38; // eax
  int v39; // edi
  int v40; // eax
  int *v41; // ecx
  int v42; // eax
  int *v43; // eax

  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 8 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 8;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 32);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 32);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  m_Size = pDesc->m_Parameters.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 3;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 3;
  v14 = pDesc->m_Parameters.m_Size;
  v15 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v14 + 1 > v15 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v14 - v15 + 1);
  ++pDesc->m_Parameters.m_Size;
  v16 = p_m_Parameters->m_Memory.m_pMemory;
  v17 = pDesc->m_Parameters.m_Size - v14 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
  v18 = &p_m_Parameters->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 3;
  v19 = pDesc->m_Parameters.m_Size;
  v20 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v19 + 1 > v20 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v19 - v20 + 1);
  ++pDesc->m_Parameters.m_Size;
  v21 = p_m_Parameters->m_Memory.m_pMemory;
  v22 = pDesc->m_Parameters.m_Size - v19 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v22 > 0 )
    _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
  v23 = &p_m_Parameters->m_Memory.m_pMemory[v19];
  if ( v23 != nullptr )
    *v23 = 5;
  v24 = pDesc->m_Parameters.m_Size;
  v25 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v24 + 1 > v25 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v24 - v25 + 1);
  ++pDesc->m_Parameters.m_Size;
  v26 = p_m_Parameters->m_Memory.m_pMemory;
  v27 = pDesc->m_Parameters.m_Size - v24 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v27 > 0 )
    _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
  v28 = &p_m_Parameters->m_Memory.m_pMemory[v24];
  if ( v28 != nullptr )
    *v28 = 5;
  v29 = pDesc->m_Parameters.m_Size;
  v30 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v29 + 1 > v30 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v29 - v30 + 1);
  ++pDesc->m_Parameters.m_Size;
  v31 = p_m_Parameters->m_Memory.m_pMemory;
  v32 = pDesc->m_Parameters.m_Size - v29 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v32 > 0 )
    _V_memmove(dest: &v31[v29 + 1], src: &v31[v29], count: 4 * v32);
  v33 = &p_m_Parameters->m_Memory.m_pMemory[v29];
  if ( v33 != nullptr )
    *v33 = 5;
  v34 = pDesc->m_Parameters.m_Size;
  v35 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v34 + 1 > v35 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v34 - v35 + 1);
  ++pDesc->m_Parameters.m_Size;
  v36 = p_m_Parameters->m_Memory.m_pMemory;
  v37 = pDesc->m_Parameters.m_Size - v34 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v37 > 0 )
    _V_memmove(dest: &v36[v34 + 1], src: &v36[v34], count: 4 * v37);
  v38 = &p_m_Parameters->m_Memory.m_pMemory[v34];
  if ( v38 != nullptr )
    *v38 = 5;
  v39 = pDesc->m_Parameters.m_Size;
  v40 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v39 + 1 > v40 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v39 - v40 + 1);
  ++pDesc->m_Parameters.m_Size;
  v41 = p_m_Parameters->m_Memory.m_pMemory;
  v42 = pDesc->m_Parameters.m_Size - v39 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v42 > 0 )
    _V_memmove(dest: &v41[v39 + 1], src: &v41[v39], count: 4 * v42);
  v43 = &p_m_Parameters->m_Memory.m_pMemory[v39];
  if ( v43 != nullptr )
    *v43 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10260350
// Name: void ScriptDeduceFunctionSignature<void,class Vector const __near &,class Vector const __near &,int,int,int,bool,float>(struct ScriptFuncDescriptor_t __near *,void (*)(class Vector const __near &,class Vector const __near &,int,int,int,bool,float))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<void,Vector const &,Vector const &,int,int,int,bool,float>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // eax
  int v19; // edi
  int v20; // eax
  int *v21; // ecx
  int v22; // eax
  int *v23; // eax
  int v24; // edi
  int v25; // eax
  int *v26; // ecx
  int v27; // eax
  int *v28; // eax
  int v29; // edi
  int v30; // eax
  int *v31; // ecx
  int v32; // eax
  int *v33; // eax
  int v34; // edi
  int v35; // eax
  int *v36; // ecx
  int v37; // eax
  int *v38; // eax

  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 7 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 7;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 28);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 28);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  m_Size = pDesc->m_Parameters.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 3;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 3;
  v14 = pDesc->m_Parameters.m_Size;
  v15 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v14 + 1 > v15 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v14 - v15 + 1);
  ++pDesc->m_Parameters.m_Size;
  v16 = p_m_Parameters->m_Memory.m_pMemory;
  v17 = pDesc->m_Parameters.m_Size - v14 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
  v18 = &p_m_Parameters->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 5;
  v19 = pDesc->m_Parameters.m_Size;
  v20 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v19 + 1 > v20 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v19 - v20 + 1);
  ++pDesc->m_Parameters.m_Size;
  v21 = p_m_Parameters->m_Memory.m_pMemory;
  v22 = pDesc->m_Parameters.m_Size - v19 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v22 > 0 )
    _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
  v23 = &p_m_Parameters->m_Memory.m_pMemory[v19];
  if ( v23 != nullptr )
    *v23 = 5;
  v24 = pDesc->m_Parameters.m_Size;
  v25 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v24 + 1 > v25 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v24 - v25 + 1);
  ++pDesc->m_Parameters.m_Size;
  v26 = p_m_Parameters->m_Memory.m_pMemory;
  v27 = pDesc->m_Parameters.m_Size - v24 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v27 > 0 )
    _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
  v28 = &p_m_Parameters->m_Memory.m_pMemory[v24];
  if ( v28 != nullptr )
    *v28 = 5;
  v29 = pDesc->m_Parameters.m_Size;
  v30 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v29 + 1 > v30 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v29 - v30 + 1);
  ++pDesc->m_Parameters.m_Size;
  v31 = p_m_Parameters->m_Memory.m_pMemory;
  v32 = pDesc->m_Parameters.m_Size - v29 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v32 > 0 )
    _V_memmove(dest: &v31[v29 + 1], src: &v31[v29], count: 4 * v32);
  v33 = &p_m_Parameters->m_Memory.m_pMemory[v29];
  if ( v33 != nullptr )
    *v33 = 6;
  v34 = pDesc->m_Parameters.m_Size;
  v35 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v34 + 1 > v35 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v34 - v35 + 1);
  ++pDesc->m_Parameters.m_Size;
  v36 = p_m_Parameters->m_Memory.m_pMemory;
  v37 = pDesc->m_Parameters.m_Size - v34 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v37 > 0 )
    _V_memmove(dest: &v36[v34 + 1], src: &v36[v34], count: 4 * v37);
  v38 = &p_m_Parameters->m_Memory.m_pMemory[v34];
  if ( v38 != nullptr )
    *v38 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x102605F0
// Name: void ScriptDeduceFunctionSignature<bool,char const __near *,struct HSCRIPT__ __near *>(struct ScriptFuncDescriptor_t __near *,bool (*)(char const __near *,struct HSCRIPT__ __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<bool,char const *,HSCRIPT__ *>(ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 6;
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
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 33;
}

//------------------------------------------------------------------------------
// Address: 0x102606F0
// Name: void ScriptDeduceFunctionSignature<struct HSCRIPT__ __near *,char const __near *,class Vector const __near &,char const __near *,int>(struct ScriptFuncDescriptor_t __near *,struct HSCRIPT__ __near * (*)(char const __near *,class Vector const __near &,char const __near *,int))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<HSCRIPT__ *,char const *,Vector const &,char const *,int>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // eax
  int v19; // edi
  int v20; // eax
  int *v21; // ecx
  int v22; // eax
  int *v23; // eax

  pDesc->m_ReturnType = 33;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 4 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 4;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 16);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 16);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 3;
  v14 = pDesc->m_Parameters.m_Size;
  v15 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v14 + 1 > v15 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v14 - v15 + 1);
  ++pDesc->m_Parameters.m_Size;
  v16 = p_m_Parameters->m_Memory.m_pMemory;
  v17 = pDesc->m_Parameters.m_Size - v14 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
  v18 = &p_m_Parameters->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 32;
  v19 = pDesc->m_Parameters.m_Size;
  v20 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v19 + 1 > v20 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v19 - v20 + 1);
  ++pDesc->m_Parameters.m_Size;
  v21 = p_m_Parameters->m_Memory.m_pMemory;
  v22 = pDesc->m_Parameters.m_Size - v19 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v22 > 0 )
    _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
  v23 = &p_m_Parameters->m_Memory.m_pMemory[v19];
  if ( v23 != nullptr )
    *v23 = 5;
}

//------------------------------------------------------------------------------
// Address: 0x1041BF20
// Name: _dynamic_atexit_destructor_for__gGlobalState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gGlobalState__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&gGlobalState.m_list);
  CUtlSymbolTable::~CUtlSymbolTable(this: &gGlobalState.m_nameList);
  IGameSystem::~IGameSystem(this: &gGlobalState);
}

//------------------------------------------------------------------------------
// Address: 0x1041BF40
// Name: _DataMapInit_CGlobalState__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGlobalState__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_231);
}

//------------------------------------------------------------------------------
// Address: 0x1041BF50
// Name: _DataMapInit_globalentity_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_globalentity_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_232);
}

//------------------------------------------------------------------------------
// Address: 0x1041BF60
// Name: _DataMapInit_CGunTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGunTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_233);
}
