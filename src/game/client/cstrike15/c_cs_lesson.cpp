// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/c_cs_lesson.cpp
// Functions: 5
// ============================================================

#include "game\client\cstrike15\c_cs_lesson.h"

//------------------------------------------------------------------------------
// Address: 0x101B7F80
// Name: private: bool CScriptedIconLesson::Mod_ProcessElementAction(int,bool,char const __near *,class CHandle<class C_BaseEntity> __near &,class CGameInstructorSymbol const __near *,float,class C_BaseEntity __near *,char const __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CScriptedIconLesson::Mod_ProcessElementAction@<al>(
        CScriptedIconLesson *this@<ecx>,
        const char *a2@<ebx>,
        int iAction,
        bool bNot,
        const char *pchVarName,
        CHandle<C_BaseEntity> *hVar,
        const CGameInstructorSymbol *pchParamName,
        float fParam,
        C_BaseEntity *pParam,
        const char *pchParam,
        bool *bModHandled)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  C_CSPlayer *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  int (*GetCurrentGameType)(void); // edx

  *bModHandled = true;
  m_Index = hVar->m_Index;
  if ( hVar->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  switch ( iAction )
  {
    case '+':
      GetCurrentGameType = (int (*)(void))g_pGameTypes->GetCurrentGameType;
      return (float)GetCurrentGameType() == fParam;
    case ',':
      GetCurrentGameType = (int (*)(void))g_pGameTypes->GetCurrentGameMode;
      return (float)GetCurrentGameType() == fParam;
    case '-':
      v15 = (C_CSPlayer *)__RTDynamicCast(
                            inptr: m_pEntity,
                            VfDelta: 0,
                            SrcType: &C_BaseEntity `RTTI Type Descriptor',
                            TargetType: &C_CSPlayer `RTTI Type Descriptor',
                            isReference: 0);
      if ( v15 != nullptr )
      {
        LOBYTE(a2) = C_CSPlayer::HasDefuser(this: v15);
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this, a2) )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->HasSpareWeapon()", pchVarName);
          v17 = "true";
          if ( (_BYTE)a2 == 0 )
            v17 = "false";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%s ", v17);
          v18 = "== false\n";
          if ( !bNot )
            v18 = "== true\n";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v18);
        }
        if ( bNot )
          return (_BYTE)a2 == 0;
        else
          return (char)a2;
      }
      else
      {
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this, a2) )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->HasDefuser()", pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "... ");
          v16 = "== false\n";
          if ( !bNot )
            v16 = "== true\n";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v16);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as CSPlayer returned NULL!\n");
        }
        return false;
      }
    default:
      *bModHandled = false;
      return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8130
// Name: public: static void CScriptedIconLesson::Mod_PreReadLessonsFromFile(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CScriptedIconLesson::Mod_PreReadLessonsFromFile()
{
  int element; // [esp+0h] [ebp-4h] BYREF

  element = 43;
  CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "game type is", &element);
  element = 44;
  CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "game mode is", &element);
  element = 45;
  CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "has defuser", &element);
}

//------------------------------------------------------------------------------
// Address: 0x10411180
// Name: _dynamic_initializer_for__CScriptedIconLesson::LessonActionMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CScriptedIconLesson::LessonActionMap__()
{
  return atexit(func: dynamic_atexit_destructor_for__CScriptedIconLesson::LessonActionMap__);
}

//------------------------------------------------------------------------------
// Address: 0x1042FF60
// Name: _dynamic_atexit_destructor_for__CScriptedIconLesson::LessonActionMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CScriptedIconLesson::LessonActionMap__()
{
  CUtlDict<int,int>::RemoveAll(this: &CScriptedIconLesson::LessonActionMap);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &CScriptedIconLesson::LessonActionMap.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1042FF80
// Name: _dynamic_atexit_destructor_for__cl_customsounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_customsounds__()
{
  ConVar::~ConVar(this: &cl_customsounds);
}
