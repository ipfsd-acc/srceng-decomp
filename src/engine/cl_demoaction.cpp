// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_demoaction.cpp
// Functions: 28
// ============================================================

#include "engine\cl_demoaction.h"

//------------------------------------------------------------------------------
// Address: 0x10075D80
// Name: public: CBaseDemoAction::CBaseDemoAction(void)
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__thiscall CBaseDemoAction::CBaseDemoAction(CBaseDemoAction *this)
{
  this->__vftable = (CBaseDemoAction_vtbl *)&CBaseDemoAction::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10075D90
// Name: public: virtual CBaseDemoAction::~CBaseDemoAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::~CBaseDemoAction(CBaseDemoAction *this)
{
  this->__vftable = (CBaseDemoAction_vtbl *)&CBaseDemoAction::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10075DB0
// Name: public: void CBaseDemoAction::SetActionFired(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetActionFired(CBaseDemoAction *this, bool fired)
{
  this->m_bActionFired = fired;
}

//------------------------------------------------------------------------------
// Address: 0x10075DC0
// Name: public: void CBaseDemoAction::SetFinishedAction(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetFinishedAction(CBaseDemoAction *this, bool finished)
{
  this->m_bActionFinished = finished;
  if ( finished )
    this->OnActionFinished(this);
}

//------------------------------------------------------------------------------
// Address: 0x10075DE0
// Name: public: static void __near * CBaseDemoAction::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CBaseDemoAction::operator new(unsigned int sz)
{
  return calloc(count: 1u, size: sz);
}

//------------------------------------------------------------------------------
// Address: 0x10075E00
// Name: public: static void CBaseDemoAction::AddFactory(enum DEMOACTION,class CBaseDemoAction __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseDemoAction::AddFactory(DEMOACTION actionType, CBaseDemoAction *(__cdecl *func)())
{
  if ( (unsigned int)actionType > DEMO_ACTION_ZOOM )
    Sys_Error(error: "CBaseDemoAction::AddFactory: Bogus factory type %i\n", actionType);
  else
    g_rgDemoTypeNames[actionType].func = func;
}

//------------------------------------------------------------------------------
// Address: 0x10075E30
// Name: public: static void CBaseDemoAction::AddEditorFactory(enum DEMOACTION,class CBaseActionEditDialog __near * (*)(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseDemoAction::AddEditorFactory(
        DEMOACTION actionType,
        CBaseActionEditDialog *(__cdecl *func)(CDemoEditorPanel *, CBaseDemoAction *, bool))
{
  if ( (unsigned int)actionType > DEMO_ACTION_ZOOM )
    Sys_Error(error: "CBaseDemoAction::AddEditorFactory: Bogus factory type %i\n", actionType);
  else
    g_rgDemoTypeNames[actionType].editfunc = func;
}

//------------------------------------------------------------------------------
// Address: 0x10075E60
// Name: public: static bool CBaseDemoAction::HasEditorFactory(enum DEMOACTION)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBaseDemoAction::HasEditorFactory(DEMOACTION actionType)
{
  return (unsigned int)actionType <= DEMO_ACTION_ZOOM && g_rgDemoTypeNames[actionType].editfunc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10075E90
// Name: public: static char const __near * CBaseDemoAction::NameForType(enum DEMOACTION)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseDemoAction::NameForType(DEMOACTION actionType)
{
  if ( (unsigned int)actionType <= DEMO_ACTION_ZOOM )
    return g_rgDemoTypeNames[actionType].name;
  ConMsg(a1: "ERROR: CBaseDemoAction::NameForType type %i out of range\n", actionType);
  return g_rgDemoTypeNames[0].name;
}

//------------------------------------------------------------------------------
// Address: 0x10075EC0
// Name: public: static enum DEMOACTION CBaseDemoAction::TypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
DEMOACTION __cdecl CBaseDemoAction::TypeForName(const char *name)
{
  DemoActionDictionary *v1; // esi

  v1 = g_rgDemoTypeNames;
  while ( V_strcasecmp(s1: v1->name, s2: name) != 0 )
  {
    if ( (int)++v1 >= (int)g_rgDemoTimingTypeNames )
      return DEMO_ACTION_UNKNOWN;
  }
  return v1->actiontype;
}

//------------------------------------------------------------------------------
// Address: 0x10075F00
// Name: public: static char const __near * CBaseDemoAction::NameForTimingType(enum DEMOACTIONTIMINGTYPE)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseDemoAction::NameForTimingType(DEMOACTIONTIMINGTYPE timingType)
{
  if ( (unsigned int)timingType <= ACTION_USES_TIME )
    return g_rgDemoTimingTypeNames[timingType].name;
  ConMsg(a1: "ERROR: CBaseDemoAction::NameForTimingType type %i out of range\n", timingType);
  return g_rgDemoTimingTypeNames[0].name;
}

//------------------------------------------------------------------------------
// Address: 0x10075F30
// Name: public: static enum DEMOACTIONTIMINGTYPE CBaseDemoAction::TimingTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
DEMOACTIONTIMINGTYPE __cdecl CBaseDemoAction::TimingTypeForName(const char *name)
{
  DemoTimingTagDictionary *v1; // esi

  v1 = g_rgDemoTimingTypeNames;
  while ( V_strcasecmp(s1: v1->name, s2: name) != 0 )
  {
    if ( (int)++v1 >= (int)&CBaseDemoAction `RTTI Type Descriptor' )
      return ACTION_USES_NEITHER;
  }
  return v1->timingtype;
}

//------------------------------------------------------------------------------
// Address: 0x10075F70
// Name: public: static void CBaseDemoAction::BufPrintf(int,class CUtlBuffer __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseDemoAction::BufPrintf(int depth, CUtlBuffer *buf, const char *fmt, ...)
{
  int i; // esi
  char string[1024]; // [esp+8h] [ebp-400h] BYREF
  va_list params; // [esp+41Ch] [ebp+14h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
  for ( i = depth; i > 0; --i )
    CUtlBuffer::Printf(this: buf, pFmt: "\t");
  CUtlBuffer::Printf(this: buf, pFmt: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x10075FD0
// Name: public: void CBaseDemoAction::SaveToBuffer(int,int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SaveToBuffer(CBaseDemoAction *this, int depth, int index, CUtlBuffer *buf)
{
  DEMOACTION m_Type; // eax
  const char *name; // eax

  CBaseDemoAction::BufPrintf(depth, buf, fmt: "\"%i\"\n", index);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "%{\n");
  m_Type = this->m_Type;
  g_bSaveChained = false;
  if ( (unsigned int)m_Type > DEMO_ACTION_ZOOM )
  {
    ConMsg(a1: "ERROR: CBaseDemoAction::NameForType type %i out of range\n", m_Type);
    name = g_rgDemoTypeNames[0].name;
  }
  else
  {
    name = g_rgDemoTypeNames[m_Type].name;
  }
  CBaseDemoAction::BufPrintf(depth: depth + 1, buf, fmt: "factory \"%s\"\n", name);
  this->SaveKeysToBuffer(this, a2: depth + 1, a3: buf);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x10076070
// Name: public: void CBaseDemoAction::SetActionName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetActionName(CBaseDemoAction *this, const char *name)
{
  V_strncpy(pDest: this->m_szActionName, pSrc: name, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10076090
// Name: public: virtual bool CBaseDemoAction::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseDemoAction::Init(CBaseDemoAction *this, KeyValues *pInitData)
{
  const char *String; // eax
  int m_nStartTick; // ecx
  const char *v6; // eax
  float Float; // [esp+10h] [ebp+8h]

  String = KeyValues::GetString(this: pInitData, keyName: "name", defaultValue: defaultValue);
  if ( String != nullptr && *String != 0 )
  {
    V_strncpy(pDest: this->m_szActionName, pSrc: String, maxLen: 64);
    this->m_nStartTick = KeyValues::GetInt(this: pInitData, keyName: "starttick", defaultValue: -1);
    Float = KeyValues::GetFloat(this: pInitData, keyName: "starttime", defaultValue: -1.0);
    m_nStartTick = this->m_nStartTick;
    this->m_flStartTime = Float;
    if ( m_nStartTick == -1 && Float == -1.0 )
      this->m_Timing = ACTION_USES_NEITHER;
    else
      this->m_Timing = (m_nStartTick == -1) + 1;
    v6 = KeyValues::GetString(this: pInitData, keyName: "target", defaultValue: defaultValue);
    if ( v6 != nullptr && *v6 != 0 )
      V_strncpy(pDest: this->m_szActionTarget, pSrc: v6, maxLen: 64);
    return 1;
  }
  else
  {
    _Msg(a1: "CBaseDemoAction::Init:  must specify a name for action!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076180
// Name: public: int CBaseDemoAction::GetStartTick(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseDemoAction::GetStartTick(CBaseDemoAction *this)
{
  return this->m_nStartTick;
}

//------------------------------------------------------------------------------
// Address: 0x10076190
// Name: public: float CBaseDemoAction::GetStartTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseDemoAction::GetStartTime(CBaseDemoAction *this)
{
  return this->m_flStartTime;
}

//------------------------------------------------------------------------------
// Address: 0x100761A0
// Name: public: void CBaseDemoAction::SetStartTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetStartTick(vgui::Panel *this, Color color)
{
  this->_bgColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x100761B0
// Name: public: void CBaseDemoAction::SetStartTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetStartTime(CBaseDemoAction *this, float t)
{
  this->m_flStartTime = t;
}

//------------------------------------------------------------------------------
// Address: 0x100761D0
// Name: public: virtual bool CBaseDemoAction::Update(struct DemoActionTimingContext const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseDemoAction::Update(CBaseDemoAction *this, const DemoActionTimingContext *tc)
{
  __int32 v4; // ecx
  float m_flStartTime; // xmm0_4
  int m_nStartTick; // ecx

  if ( this->m_bActionFinished )
    return 0;
  if ( !this->m_bActionFired )
  {
    v4 = this->m_Timing - 1;
    if ( v4 != 0 )
    {
      if ( v4 != 1 )
        return 0;
      m_flStartTime = this->m_flStartTime;
      if ( m_flStartTime >= tc->prevtime && tc->curtime >= m_flStartTime )
      {
        demoaction->InsertFireEvent(this: demoaction, a2: this);
        return 1;
      }
    }
    else
    {
      m_nStartTick = this->m_nStartTick;
      if ( m_nStartTick >= tc->prevtick && m_nStartTick <= tc->curtick )
        demoaction->InsertFireEvent(this: demoaction, a2: this);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10076250
// Name: public: char const __near * CBaseDemoAction::GetActionName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseDemoAction::GetActionName(CBaseDemoAction *this)
{
  return this->m_szActionName;
}

//------------------------------------------------------------------------------
// Address: 0x10076260
// Name: public: virtual void CBaseDemoAction::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::Reset(CBaseDemoAction *this)
{
  *(_WORD *)&this->m_bActionFired = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100762A0
// Name: public: static class CBaseDemoAction __near * CBaseDemoAction::CreateDemoAction(enum DEMOACTION)
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__cdecl CBaseDemoAction::CreateDemoAction(DEMOACTION actionType)
{
  CBaseDemoAction *(*func)(void); // ecx
  const char *v2; // eax

  if ( (unsigned int)actionType > DEMO_ACTION_ZOOM )
  {
    Sys_Error(error: "CBaseDemoAction::AddFactory: Bogus factory type %i\n", actionType);
    return nullptr;
  }
  else
  {
    func = g_rgDemoTypeNames[actionType].func;
    if ( func != nullptr )
    {
      return func();
    }
    else
    {
      v2 = CBaseDemoAction::NameForType(actionType);
      ConMsg(a1: "CBaseDemoAction::CreateDemoAction:  Missing factory for %s\n", v2);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100762F0
// Name: public: static class CBaseActionEditDialog __near * CBaseDemoAction::CreateActionEditor(enum DEMOACTION,class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__cdecl CBaseDemoAction::CreateActionEditor(
        DEMOACTION actionType,
        CDemoEditorPanel *parent,
        CBaseDemoAction *action,
        BOOL newaction)
{
  CBaseActionEditDialog *(__cdecl *editfunc)(CDemoEditorPanel *, CBaseDemoAction *, bool); // ecx
  const char *v5; // eax

  if ( (unsigned int)actionType > DEMO_ACTION_ZOOM )
  {
    Sys_Error(error: "CBaseDemoAction::AddFactory: Bogus factory type %i\n", actionType);
    return nullptr;
  }
  else
  {
    editfunc = g_rgDemoTypeNames[actionType].editfunc;
    if ( editfunc != nullptr )
    {
      return editfunc(a1: parent, a2: action, a3: newaction);
    }
    else
    {
      v5 = CBaseDemoAction::NameForType(actionType);
      ConMsg(a1: "CBaseDemoAction::CreateActionEditor:  Missing edit factory for %s\n", v5);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076350
// Name: public: virtual void CBaseDemoAction::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SaveKeysToBuffer(CBaseDemoAction *this, int depth, CUtlBuffer *buf)
{
  g_bSaveChained = true;
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "name \"%s\"\n", this->m_szActionName);
  if ( this->m_szActionTarget[0] != 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "target \"%s\"\n", this->m_szActionTarget);
  if ( this->m_Timing == ACTION_USES_TICK )
  {
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "starttick \"%i\"\n", this->m_nStartTick);
  }
  else if ( this->m_Timing == ACTION_USES_TIME )
  {
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "starttime \"%.3f\"\n", this->m_flStartTime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10265070
// Name: public: bool CBaseDemoAction::GetActionFired(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseDemoAction::GetActionFired(vgui::BuildGroup *this)
{
  return this->_enabled;
}

//------------------------------------------------------------------------------
// Address: 0x10285EA0
// Name: public: void CBaseDemoAction::SetTimingType(enum DEMOACTIONTIMINGTYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetTimingType(vgui::Panel *this, Color color)
{
  this->_fgColor = color;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10075A50
// Name: public: CBaseDemoAction::CBaseDemoAction(void)
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__thiscall CBaseDemoAction::CBaseDemoAction(CBaseDemoAction *this)
{
  this->__vftable = (CBaseDemoAction_vtbl *)&CBaseDemoAction::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10075A60
// Name: public: virtual CBaseDemoAction::~CBaseDemoAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::~CBaseDemoAction(CBaseDemoAction *this)
{
  this->__vftable = (CBaseDemoAction_vtbl *)&CBaseDemoAction::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10075A80
// Name: public: void CBaseDemoAction::SetActionFired(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetActionFired(CBaseDemoAction *this, bool fired)
{
  this->m_bActionFired = fired;
}

//------------------------------------------------------------------------------
// Address: 0x10075A90
// Name: public: void CBaseDemoAction::SetFinishedAction(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetFinishedAction(CBaseDemoAction *this, bool finished)
{
  this->m_bActionFinished = finished;
  if ( finished )
    this->OnActionFinished(this);
}

//------------------------------------------------------------------------------
// Address: 0x10075AB0
// Name: public: static void __near * CBaseDemoAction::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CBaseDemoAction::operator new(unsigned int sz)
{
  return calloc(count: 1u, size: sz);
}

//------------------------------------------------------------------------------
// Address: 0x10075AE0
// Name: public: static void CBaseDemoAction::AddFactory(enum DEMOACTION,class CBaseDemoAction __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseDemoAction::AddFactory(DEMOACTION actionType, CBaseDemoAction *(__cdecl *func)())
{
  if ( (unsigned int)actionType > DEMO_ACTION_ZOOM )
    Sys_Error(error: "CBaseDemoAction::AddFactory: Bogus factory type %i\n", actionType);
  else
    g_rgDemoTypeNames[actionType].func = func;
}

//------------------------------------------------------------------------------
// Address: 0x10075B10
// Name: public: static void CBaseDemoAction::AddEditorFactory(enum DEMOACTION,class CBaseActionEditDialog __near * (*)(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseDemoAction::AddEditorFactory(
        DEMOACTION actionType,
        CBaseActionEditDialog *(__cdecl *func)(CDemoEditorPanel *, CBaseDemoAction *, bool))
{
  if ( (unsigned int)actionType > DEMO_ACTION_ZOOM )
    Sys_Error(error: "CBaseDemoAction::AddEditorFactory: Bogus factory type %i\n", actionType);
  else
    g_rgDemoTypeNames[actionType].editfunc = func;
}

//------------------------------------------------------------------------------
// Address: 0x10075B40
// Name: public: static bool CBaseDemoAction::HasEditorFactory(enum DEMOACTION)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBaseDemoAction::HasEditorFactory(DEMOACTION actionType)
{
  return (unsigned int)actionType <= DEMO_ACTION_ZOOM && g_rgDemoTypeNames[actionType].editfunc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10075B70
// Name: public: static char const __near * CBaseDemoAction::NameForType(enum DEMOACTION)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseDemoAction::NameForType(DEMOACTION actionType)
{
  if ( (unsigned int)actionType <= DEMO_ACTION_ZOOM )
    return g_rgDemoTypeNames[actionType].name;
  ConMsg(a1: "ERROR: CBaseDemoAction::NameForType type %i out of range\n", actionType);
  return g_rgDemoTypeNames[0].name;
}

//------------------------------------------------------------------------------
// Address: 0x10075BA0
// Name: public: static enum DEMOACTION CBaseDemoAction::TypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
DEMOACTION __cdecl CBaseDemoAction::TypeForName(const char *name)
{
  DemoActionDictionary *v1; // esi

  v1 = g_rgDemoTypeNames;
  while ( V_strcasecmp(s1: v1->name, s2: name) != 0 )
  {
    if ( (int)++v1 >= (int)g_rgDemoTimingTypeNames )
      return DEMO_ACTION_UNKNOWN;
  }
  return v1->actiontype;
}

//------------------------------------------------------------------------------
// Address: 0x10075BE0
// Name: public: static char const __near * CBaseDemoAction::NameForTimingType(enum DEMOACTIONTIMINGTYPE)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseDemoAction::NameForTimingType(DEMOACTIONTIMINGTYPE timingType)
{
  if ( (unsigned int)timingType <= ACTION_USES_TIME )
    return g_rgDemoTimingTypeNames[timingType].name;
  ConMsg(a1: "ERROR: CBaseDemoAction::NameForTimingType type %i out of range\n", timingType);
  return g_rgDemoTimingTypeNames[0].name;
}

//------------------------------------------------------------------------------
// Address: 0x10075C10
// Name: public: static enum DEMOACTIONTIMINGTYPE CBaseDemoAction::TimingTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
DEMOACTIONTIMINGTYPE __cdecl CBaseDemoAction::TimingTypeForName(const char *name)
{
  DemoTimingTagDictionary *v1; // esi

  v1 = g_rgDemoTimingTypeNames;
  while ( V_strcasecmp(s1: v1->name, s2: name) != 0 )
  {
    if ( (int)++v1 >= (int)&CBaseDemoAction `RTTI Type Descriptor' )
      return ACTION_USES_NEITHER;
  }
  return v1->timingtype;
}

//------------------------------------------------------------------------------
// Address: 0x10075C50
// Name: public: static void CBaseDemoAction::BufPrintf(int,class CUtlBuffer __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseDemoAction::BufPrintf(int depth, CUtlBuffer *buf, const char *fmt, ...)
{
  int i; // esi
  char string[1024]; // [esp+8h] [ebp-400h] BYREF
  va_list params; // [esp+41Ch] [ebp+14h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
  for ( i = depth; i > 0; --i )
    CUtlBuffer::Printf(this: buf, pFmt: "\t");
  CUtlBuffer::Printf(this: buf, pFmt: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x10075CB0
// Name: public: void CBaseDemoAction::SaveToBuffer(int,int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SaveToBuffer(CBaseDemoAction *this, int depth, int index, CUtlBuffer *buf)
{
  DEMOACTION m_Type; // eax
  const char *name; // eax

  CBaseDemoAction::BufPrintf(depth, buf, fmt: "\"%i\"\n", index);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "%{\n");
  m_Type = this->m_Type;
  g_bSaveChained = false;
  if ( (unsigned int)m_Type > DEMO_ACTION_ZOOM )
  {
    ConMsg(a1: "ERROR: CBaseDemoAction::NameForType type %i out of range\n", m_Type);
    name = g_rgDemoTypeNames[0].name;
  }
  else
  {
    name = g_rgDemoTypeNames[m_Type].name;
  }
  CBaseDemoAction::BufPrintf(depth: depth + 1, buf, fmt: "factory \"%s\"\n", name);
  this->SaveKeysToBuffer(this, a2: depth + 1, a3: buf);
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x10075D50
// Name: public: void CBaseDemoAction::SetActionName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetActionName(CBaseDemoAction *this, const char *name)
{
  V_strncpy(pDest: this->m_szActionName, pSrc: name, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10075D70
// Name: public: virtual bool CBaseDemoAction::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseDemoAction::Init(CBaseDemoAction *this, KeyValues *pInitData)
{
  const char *String; // eax
  int m_nStartTick; // ecx
  const char *v6; // eax
  float pInitDataa; // [esp+14h] [ebp+8h]

  String = KeyValues::GetString(this: pInitData, keyName: "name", defaultValue: defaultValue);
  if ( String != nullptr && *String != 0 )
  {
    V_strncpy(pDest: this->m_szActionName, pSrc: String, maxLen: 64);
    this->m_nStartTick = KeyValues::GetInt(this: pInitData, keyName: "starttick", defaultValue: -1);
    pInitDataa = KeyValues::GetFloat(this: pInitData, keyName: "starttime", defaultValue: -1.0);
    m_nStartTick = this->m_nStartTick;
    this->m_flStartTime = pInitDataa;
    if ( m_nStartTick == -1 && pInitDataa == -1.0 )
      this->m_Timing = ACTION_USES_NEITHER;
    else
      this->m_Timing = (m_nStartTick == -1) + 1;
    v6 = KeyValues::GetString(this: pInitData, keyName: "target", defaultValue: defaultValue);
    if ( v6 != nullptr && *v6 != 0 )
      V_strncpy(pDest: this->m_szActionTarget, pSrc: v6, maxLen: 64);
    return 1;
  }
  else
  {
    _Msg(a1: "CBaseDemoAction::Init:  must specify a name for action!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075E70
// Name: public: float CBaseDemoAction::GetStartTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseDemoAction::GetStartTime(CBaseDemoAction *this)
{
  return this->m_flStartTime;
}

//------------------------------------------------------------------------------
// Address: 0x10075E80
// Name: public: void CBaseDemoAction::SetStartTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetStartTime(CBaseDemoAction *this, float t)
{
  this->m_flStartTime = t;
}

//------------------------------------------------------------------------------
// Address: 0x10075EA0
// Name: public: virtual bool CBaseDemoAction::Update(struct DemoActionTimingContext const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseDemoAction::Update(CBaseDemoAction *this, const DemoActionTimingContext *tc)
{
  __int32 v4; // ecx
  float m_flStartTime; // xmm0_4
  int m_nStartTick; // ecx

  if ( this->m_bActionFinished )
    return 0;
  if ( !this->m_bActionFired )
  {
    v4 = this->m_Timing - 1;
    if ( v4 != 0 )
    {
      if ( v4 != 1 )
        return 0;
      m_flStartTime = this->m_flStartTime;
      if ( m_flStartTime >= tc->prevtime && tc->curtime >= m_flStartTime )
      {
        demoaction->InsertFireEvent(this: demoaction, a2: this);
        return 1;
      }
    }
    else
    {
      m_nStartTick = this->m_nStartTick;
      if ( m_nStartTick >= tc->prevtick && m_nStartTick <= tc->curtick )
        demoaction->InsertFireEvent(this: demoaction, a2: this);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10075F20
// Name: public: char const __near * CBaseDemoAction::GetActionName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseDemoAction::GetActionName(CBaseDemoAction *this)
{
  return this->m_szActionName;
}

//------------------------------------------------------------------------------
// Address: 0x10075FC0
// Name: public: static class CBaseActionEditDialog __near * CBaseDemoAction::CreateActionEditor(enum DEMOACTION,class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__cdecl CBaseDemoAction::CreateActionEditor(
        DEMOACTION actionType,
        CDemoEditorPanel *parent,
        CBaseDemoAction *action,
        BOOL newaction)
{
  CBaseActionEditDialog *(__cdecl *editfunc)(CDemoEditorPanel *, CBaseDemoAction *, bool); // ecx
  const char *v5; // eax

  if ( (unsigned int)actionType > DEMO_ACTION_ZOOM )
  {
    Sys_Error(error: "CBaseDemoAction::AddFactory: Bogus factory type %i\n", actionType);
    return nullptr;
  }
  else
  {
    editfunc = g_rgDemoTypeNames[actionType].editfunc;
    if ( editfunc != nullptr )
    {
      return editfunc(a1: parent, a2: action, a3: newaction);
    }
    else
    {
      v5 = CBaseDemoAction::NameForType(actionType);
      ConMsg(a1: "CBaseDemoAction::CreateActionEditor:  Missing edit factory for %s\n", v5);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076020
// Name: public: virtual void CBaseDemoAction::SaveKeysToBuffer(int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SaveKeysToBuffer(CBaseDemoAction *this, int depth, CUtlBuffer *buf)
{
  g_bSaveChained = true;
  CBaseDemoAction::BufPrintf(depth, buf, fmt: "name \"%s\"\n", this->m_szActionName);
  if ( this->m_szActionTarget[0] != 0 )
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "target \"%s\"\n", this->m_szActionTarget);
  if ( this->m_Timing == ACTION_USES_TICK )
  {
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "starttick \"%i\"\n", this->m_nStartTick);
  }
  else if ( this->m_Timing == ACTION_USES_TIME )
  {
    CBaseDemoAction::BufPrintf(depth, buf, fmt: "starttime \"%.3f\"\n", this->m_flStartTime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10285FF0
// Name: public: void CBaseDemoAction::SetStartTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetStartTick(vgui::Panel *this, Color color)
{
  this->_bgColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x10286000
// Name: public: void CBaseDemoAction::SetTimingType(enum DEMOACTIONTIMINGTYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDemoAction::SetTimingType(vgui::Panel *this, Color color)
{
  this->_fgColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x102D4750
// Name: public: bool CBaseDemoAction::GetActionFired(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseDemoAction::GetActionFired(vgui::BuildGroup *this)
{
  return this->_enabled;
}

} // namespace engine_xlsp
