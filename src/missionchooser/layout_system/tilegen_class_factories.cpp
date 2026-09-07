// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system/tilegen_class_factories.cpp
// Functions: 303
// ============================================================

#include "missionchooser\layout_system\tilegen_class_factories.h"

//------------------------------------------------------------------------------
// Address: 0x10012EB0
// Name: public: static class ITilegenExpression<int> __near * CTilegenClassRegistry<class ITilegenExpression<int>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__cdecl CTilegenClassRegistry<ITilegenExpression<int>>::CreateInstance(const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012F40
// Name: public: static class ITilegenExpression<bool> __near * CTilegenClassRegistry<class ITilegenExpression<bool>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__cdecl CTilegenClassRegistry<ITilegenExpression<bool>>::CreateInstance(
        const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013080
// Name: public: static class ITilegenExpression<char const __near *> __near * CTilegenClassRegistry<class ITilegenExpression<char const __near *>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<char const *> *__cdecl CTilegenClassRegistry<ITilegenExpression<char const *>>::CreateInstance(
        const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013110
// Name: public: static class ITilegenExpression<class CRoom const __near *> __near * CTilegenClassRegistry<class ITilegenExpression<class CRoom const __near *>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CRoom const *> *__cdecl CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::CreateInstance(
        const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015B00
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_Add>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_Add>::GetName(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_Add> *this)
{
  return "+";
}

//------------------------------------------------------------------------------
// Address: 0x10015B10
// Name: public: virtual char const __near * CTilegenExpression_Add::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_Add::GetTypeName(CTilegenExpression_Add *this)
{
  return "CTilegenExpression_Add";
}

//------------------------------------------------------------------------------
// Address: 0x10015B20
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_Subtract>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_Subtract>::GetName(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_Subtract> *this)
{
  return "-";
}

//------------------------------------------------------------------------------
// Address: 0x10015B30
// Name: public: virtual char const __near * CTilegenExpression_Subtract::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_Subtract::GetTypeName(CTilegenExpression_Subtract *this)
{
  return "CTilegenExpression_Subtract";
}

//------------------------------------------------------------------------------
// Address: 0x10015B40
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<float>,class CTilegenExpression_FloatMultiply>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<float>,CTilegenExpression_FloatMultiply>::GetName(
        CTilegenClassFactory<ITilegenExpression<float>,CTilegenExpression_FloatMultiply> *this)
{
  return "fmul";
}

//------------------------------------------------------------------------------
// Address: 0x10015B50
// Name: public: virtual char const __near * CTilegenExpression_FloatMultiply::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_FloatMultiply::GetTypeName(CTilegenExpression_FloatMultiply *this)
{
  return "CTilegenExpression_FloatMultiply";
}

//------------------------------------------------------------------------------
// Address: 0x10015B60
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_And>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_And>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_And> *this)
{
  return "&&";
}

//------------------------------------------------------------------------------
// Address: 0x10015B70
// Name: public: virtual char const __near * CTilegenExpression_And::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_And::GetTypeName(CTilegenExpression_And *this)
{
  return "CTilegenExpression_And";
}

//------------------------------------------------------------------------------
// Address: 0x10015B80
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_Or>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Or>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Or> *this)
{
  return "||";
}

//------------------------------------------------------------------------------
// Address: 0x10015B90
// Name: public: virtual char const __near * CTilegenExpression_Or::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_Or::GetTypeName(CTilegenExpression_Or *this)
{
  return "CTilegenExpression_Or";
}

//------------------------------------------------------------------------------
// Address: 0x10015BA0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_Not>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Not>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Not> *this)
{
  return "!";
}

//------------------------------------------------------------------------------
// Address: 0x10015BB0
// Name: public: virtual char const __near * CTilegenExpression_Not::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_Not::GetTypeName(CTilegenExpression_Not *this)
{
  return "CTilegenExpression_Not";
}

//------------------------------------------------------------------------------
// Address: 0x10015BC0
// Name: public: virtual char const __near * CTilegenExpression_BoolToInt::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_BoolToInt::GetTypeName(CTilegenExpression_BoolToInt *this)
{
  return "CTilegenExpression_BoolToInt";
}

//------------------------------------------------------------------------------
// Address: 0x10015BD0
// Name: public: virtual char const __near * CTilegenExpression_IntToBool::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_IntToBool::GetTypeName(CTilegenExpression_IntToBool *this)
{
  return "CTilegenExpression_IntToBool";
}

//------------------------------------------------------------------------------
// Address: 0x10015BE0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_FloatToInt>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_FloatToInt>::GetName(
        CTilegenExpression_FloatToInt *this)
{
  return "CTilegenExpression_FloatToInt";
}

//------------------------------------------------------------------------------
// Address: 0x10015BF0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<float>,class CTilegenExpression_IntToFloat>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<float>,CTilegenExpression_IntToFloat>::GetName(
        CTilegenExpression_IntToFloat *this)
{
  return "CTilegenExpression_IntToFloat";
}

//------------------------------------------------------------------------------
// Address: 0x10015C00
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_Greater>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Greater>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Greater> *this)
{
  return ">";
}

//------------------------------------------------------------------------------
// Address: 0x10015C10
// Name: public: virtual char const __near * CTilegenExpression_Greater::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_Greater::GetTypeName(CTilegenExpression_Greater *this)
{
  return "CTilegenExpression_Greater";
}

//------------------------------------------------------------------------------
// Address: 0x10015C20
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_GreaterOrEqual>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_GreaterOrEqual>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_GreaterOrEqual> *this)
{
  return ">=";
}

//------------------------------------------------------------------------------
// Address: 0x10015C30
// Name: public: virtual char const __near * CTilegenExpression_GreaterOrEqual::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_GreaterOrEqual::GetTypeName(CTilegenExpression_GreaterOrEqual *this)
{
  return "CTilegenExpression_GreaterOrEqual";
}

//------------------------------------------------------------------------------
// Address: 0x10015C40
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_Equal>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Equal>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Equal> *this)
{
  return "==";
}

//------------------------------------------------------------------------------
// Address: 0x10015C50
// Name: public: virtual char const __near * CTilegenExpression_Equal::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_Equal::GetTypeName(CTilegenExpression_Equal *this)
{
  return "CTilegenExpression_Equal";
}

//------------------------------------------------------------------------------
// Address: 0x10015C60
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_NotEqual>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_NotEqual>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_NotEqual> *this)
{
  return "!=";
}

//------------------------------------------------------------------------------
// Address: 0x10015C70
// Name: public: virtual char const __near * CTilegenExpression_NotEqual::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_NotEqual::GetTypeName(CTilegenExpression_NotEqual *this)
{
  return "CTilegenExpression_NotEqual";
}

//------------------------------------------------------------------------------
// Address: 0x10015C80
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_Less>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Less>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Less> *this)
{
  return "<";
}

//------------------------------------------------------------------------------
// Address: 0x10015C90
// Name: public: virtual char const __near * CTilegenExpression_Less::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_Less::GetTypeName(CTilegenExpression_Less *this)
{
  return "CTilegenExpression_Less";
}

//------------------------------------------------------------------------------
// Address: 0x10015CA0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_LessOrEqual>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_LessOrEqual>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_LessOrEqual> *this)
{
  return "<=";
}

//------------------------------------------------------------------------------
// Address: 0x10015CB0
// Name: public: virtual char const __near * CTilegenExpression_LessOrEqual::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_LessOrEqual::GetTypeName(CTilegenExpression_LessOrEqual *this)
{
  return "CTilegenExpression_LessOrEqual";
}

//------------------------------------------------------------------------------
// Address: 0x10015CC0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_LiteralInt>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_LiteralInt>::GetName(
        CTilegenExpression_LiteralInt *this)
{
  return "CTilegenExpression_LiteralInt";
}

//------------------------------------------------------------------------------
// Address: 0x10015CD0
// Name: public: virtual char const __near * CTilegenExpression_LiteralBool::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_LiteralBool::GetTypeName(CTilegenExpression_LiteralBool *this)
{
  return "CTilegenExpression_LiteralBool";
}

//------------------------------------------------------------------------------
// Address: 0x10015CE0
// Name: public: virtual char const __near * CTilegenExpression_LiteralFloat::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_LiteralFloat::GetTypeName(CTilegenExpression_LiteralFloat *this)
{
  return "CTilegenExpression_LiteralFloat";
}

//------------------------------------------------------------------------------
// Address: 0x10015CF0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_LiteralString>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_LiteralString>::GetName(
        CTilegenExpression_LiteralString *this)
{
  return "CTilegenExpression_LiteralString";
}

//------------------------------------------------------------------------------
// Address: 0x10015D00
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_StringEqual>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_StringEqual>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_StringEqual> *this)
{
  return "streq";
}

//------------------------------------------------------------------------------
// Address: 0x10015D10
// Name: public: virtual char const __near * CTilegenExpression_StringEqual::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_StringEqual::GetTypeName(CTilegenExpression_StringEqual *this)
{
  return "CTilegenExpression_StringEqual";
}

//------------------------------------------------------------------------------
// Address: 0x10015D20
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_StringNotEqual>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_StringNotEqual>::GetName(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_StringNotEqual> *this)
{
  return "!streq";
}

//------------------------------------------------------------------------------
// Address: 0x10015D30
// Name: public: virtual char const __near * CTilegenExpression_StringNotEqual::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_StringNotEqual::GetTypeName(CTilegenExpression_StringNotEqual *this)
{
  return "CTilegenExpression_StringNotEqual";
}

//------------------------------------------------------------------------------
// Address: 0x10015D40
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_StringConcatenate>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_StringConcatenate>::GetName(
        CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_StringConcatenate> *this)
{
  return "concat";
}

//------------------------------------------------------------------------------
// Address: 0x10015D50
// Name: public: virtual char const __near * CTilegenExpression_StringConcatenate::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_StringConcatenate::GetTypeName(CTilegenExpression_StringConcatenate *this)
{
  return "CTilegenExpression_StringConcatenate";
}

//------------------------------------------------------------------------------
// Address: 0x10015D60
// Name: public: virtual char const __near * CTilegenExpression_RoomName::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_RoomName::GetTypeName(CTilegenExpression_RoomName *this)
{
  return "CTilegenExpression_RoomName";
}

//------------------------------------------------------------------------------
// Address: 0x10015D70
// Name: public: virtual char const __near * CTilegenExpression_RoomArea::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_RoomArea::GetTypeName(CTilegenExpression_RoomArea *this)
{
  return "CTilegenExpression_RoomArea";
}

//------------------------------------------------------------------------------
// Address: 0x10015D80
// Name: public: virtual char const __near * CTilegenExpression_ExtractRoomName::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_ExtractRoomName::GetTypeName(CTilegenExpression_ExtractRoomName *this)
{
  return "CTilegenExpression_ExtractRoomName";
}

//------------------------------------------------------------------------------
// Address: 0x10015D90
// Name: public: virtual char const __near * CTilegenExpression_ExtractThemeName::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_ExtractThemeName::GetTypeName(CTilegenExpression_ExtractThemeName *this)
{
  return "CTilegenExpression_ExtractThemeName";
}

//------------------------------------------------------------------------------
// Address: 0x10015DA0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<class CRoom const __near *>,class CTilegenExpression_LastPlacedRoom>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<CRoom const *>,CTilegenExpression_LastPlacedRoom>::GetName(
        CTilegenExpression_LastPlacedRoom *this)
{
  return "CTilegenExpression_LastPlacedRoom";
}

//------------------------------------------------------------------------------
// Address: 0x10015DB0
// Name: public: virtual char const __near * CTilegenExpression_SourceRoomFromExit::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_SourceRoomFromExit::GetTypeName(CTilegenExpression_SourceRoomFromExit *this)
{
  return "CTilegenExpression_SourceRoomFromExit";
}

//------------------------------------------------------------------------------
// Address: 0x10015DC0
// Name: public: virtual char const __near * CTilegenExpression_SourceRoomTemplateFromExit::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_SourceRoomTemplateFromExit::GetTypeName(
        CTilegenExpression_SourceRoomTemplateFromExit *this)
{
  return "CTilegenExpression_SourceRoomTemplateFromExit";
}

//------------------------------------------------------------------------------
// Address: 0x10015DD0
// Name: public: virtual char const __near * CTilegenExpression_ChokepointGrowSource::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_ChokepointGrowSource::GetTypeName(
        CTilegenExpression_ChokepointGrowSource *this)
{
  return "CTilegenExpression_ChokepointGrowSource";
}

//------------------------------------------------------------------------------
// Address: 0x10015DE0
// Name: public: virtual char const __near * CTilegenExpression_RoomChildCount::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_RoomChildCount::GetTypeName(CTilegenExpression_RoomChildCount *this)
{
  return "CTilegenExpression_RoomChildCount";
}

//------------------------------------------------------------------------------
// Address: 0x10015DF0
// Name: public: virtual char const __near * CTilegenExpression_RoomTemplateFromName::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_RoomTemplateFromName::GetTypeName(
        CTilegenExpression_RoomTemplateFromName *this)
{
  return "CTilegenExpression_RoomTemplateFromName";
}

//------------------------------------------------------------------------------
// Address: 0x10015E00
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_XPosition>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_XPosition>::GetName(
        CTilegenExpression_XPosition *this)
{
  return "CTilegenExpression_XPosition";
}

//------------------------------------------------------------------------------
// Address: 0x10015E10
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_YPosition>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_YPosition>::GetName(
        CTilegenExpression_YPosition *this)
{
  return "CTilegenExpression_YPosition";
}

//------------------------------------------------------------------------------
// Address: 0x10015E20
// Name: public: virtual char const __near * CTilegenExpression_HasTag::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_HasTag::GetTypeName(CTilegenExpression_HasTag *this)
{
  return "CTilegenExpression_HasTag";
}

//------------------------------------------------------------------------------
// Address: 0x10015E30
// Name: public: virtual char const __near * CTilegenExpression_CanPlaceRandomly::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_CanPlaceRandomly::GetTypeName(CTilegenExpression_CanPlaceRandomly *this)
{
  return "CTilegenExpression_CanPlaceRandomly";
}

//------------------------------------------------------------------------------
// Address: 0x10015E40
// Name: public: virtual char const __near * CTilegenExpression_NumTimesPlaced::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_NumTimesPlaced::GetTypeName(CTilegenExpression_NumTimesPlaced *this)
{
  return "CTilegenExpression_NumTimesPlaced";
}

//------------------------------------------------------------------------------
// Address: 0x10015E50
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_ExitTag>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_ExitTag>::GetName(
        CTilegenExpression_ExitTag *this)
{
  return "CTilegenExpression_ExitTag";
}

//------------------------------------------------------------------------------
// Address: 0x10015E60
// Name: public: virtual char const __near * CTilegenExpression_ExitDirection::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_ExitDirection::GetTypeName(CTilegenExpression_ExitDirection *this)
{
  return "CTilegenExpression_ExitDirection";
}

//------------------------------------------------------------------------------
// Address: 0x10015E70
// Name: public: virtual char const __near * CTilegenExpression_ParentState::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_ParentState::GetTypeName(CTilegenExpression_ParentState *this)
{
  return "CTilegenExpression_ParentState";
}

//------------------------------------------------------------------------------
// Address: 0x10015E80
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_StateName>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_StateName>::GetName(
        CTilegenExpression_StateName *this)
{
  return "CTilegenExpression_StateName";
}

//------------------------------------------------------------------------------
// Address: 0x10015E90
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_MapReduceExits>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_MapReduceExits>::GetName(
        CTilegenExpression_MapReduceExits *this)
{
  return "CTilegenExpression_MapReduceExits";
}

//------------------------------------------------------------------------------
// Address: 0x10015EA0
// Name: public: virtual char const __near * CTilegenExpression_CountExits::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_CountExits::GetTypeName(CTilegenExpression_CountExits *this)
{
  return "CTilegenExpression_CountExits";
}

//------------------------------------------------------------------------------
// Address: 0x10015EB0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_VariableInt>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_VariableInt>::GetName(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_VariableInt> *this)
{
  return "var_int";
}

//------------------------------------------------------------------------------
// Address: 0x10015EC0
// Name: public: virtual char const __near * CTilegenExpression_VariableInt::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_VariableInt::GetTypeName(CTilegenExpression_VariableInt *this)
{
  return "CTilegenExpression_VariableInt";
}

//------------------------------------------------------------------------------
// Address: 0x10015ED0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_VariableString>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_VariableString>::GetName(
        CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_VariableString> *this)
{
  return "var_string";
}

//------------------------------------------------------------------------------
// Address: 0x10015EE0
// Name: public: virtual char const __near * CTilegenExpression_VariableString::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_VariableString::GetTypeName(CTilegenExpression_VariableString *this)
{
  return "CTilegenExpression_VariableString";
}

//------------------------------------------------------------------------------
// Address: 0x10015EF0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<class CExit const __near *>,class CTilegenExpression_VariableExit>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<CExit const *>,CTilegenExpression_VariableExit>::GetName(
        CTilegenClassFactory<ITilegenExpression<CExit const *>,CTilegenExpression_VariableExit> *this)
{
  return "var_exit";
}

//------------------------------------------------------------------------------
// Address: 0x10015F00
// Name: public: virtual char const __near * CTilegenExpression_VariableExit::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_VariableExit::GetTypeName(CTilegenExpression_VariableExit *this)
{
  return "CTilegenExpression_VariableExit";
}

//------------------------------------------------------------------------------
// Address: 0x10015F10
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<class CRoomCandidate const __near *>,class CTilegenExpression_VariableRoomCandidate>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<CRoomCandidate const *>,CTilegenExpression_VariableRoomCandidate>::GetName(
        CTilegenClassFactory<ITilegenExpression<CRoomCandidate const *>,CTilegenExpression_VariableRoomCandidate> *this)
{
  return "var_room_candidate";
}

//------------------------------------------------------------------------------
// Address: 0x10015F20
// Name: public: virtual char const __near * CTilegenExpression_VariableRoomCandidate::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_VariableRoomCandidate::GetTypeName(
        CTilegenExpression_VariableRoomCandidate *this)
{
  return "CTilegenExpression_VariableRoomCandidate";
}

//------------------------------------------------------------------------------
// Address: 0x10015F30
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<class CRoomTemplate const __near *>,class CTilegenExpression_VariableRoomTemplate>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<CRoomTemplate const *>,CTilegenExpression_VariableRoomTemplate>::GetName(
        CTilegenClassFactory<ITilegenExpression<CRoomTemplate const *>,CTilegenExpression_VariableRoomTemplate> *this)
{
  return "var_room_template";
}

//------------------------------------------------------------------------------
// Address: 0x10015F40
// Name: public: virtual char const __near * CTilegenExpression_VariableRoomTemplate::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_VariableRoomTemplate::GetTypeName(
        CTilegenExpression_VariableRoomTemplate *this)
{
  return "CTilegenExpression_VariableRoomTemplate";
}

//------------------------------------------------------------------------------
// Address: 0x10015F50
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenExpression<class CTilegenState const __near *>,class CTilegenExpression_VariableState>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenExpression<CTilegenState const *>,CTilegenExpression_VariableState>::GetName(
        CTilegenClassFactory<ITilegenExpression<CTilegenState const *>,CTilegenExpression_VariableState> *this)
{
  return "var_state";
}

//------------------------------------------------------------------------------
// Address: 0x10015F60
// Name: public: virtual char const __near * CTilegenExpression_VariableState::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_VariableState::GetTypeName(CTilegenExpression_VariableState *this)
{
  return "CTilegenExpression_VariableState";
}

//------------------------------------------------------------------------------
// Address: 0x10015F70
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_NestedActions>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_NestedActions>::GetName(
        CTilegenAction_NestedActions *this)
{
  return "CTilegenAction_NestedActions";
}

//------------------------------------------------------------------------------
// Address: 0x10015F80
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_SetVariableInt>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableInt>::GetName(
        CTilegenAction_SetVariableInt *this)
{
  return "CTilegenAction_SetVariableInt";
}

//------------------------------------------------------------------------------
// Address: 0x10015F90
// Name: public: virtual void CTilegenAction_SetVariable::OnBeginGeneration(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_SetVariable::OnBeginGeneration(
        CTilegenAction_SetVariable *this,
        CLayoutSystem *pLayoutSystem)
{
  if ( this->m_bFireOnBeginGeneration )
    this->InternalExecute(this, a2: pLayoutSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10015FB0
// Name: public: virtual void CTilegenAction_SetVariable::OnStateChanged(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_SetVariable::OnStateChanged(
        CTilegenAction_SetVariable *this,
        CLayoutSystem *pLayoutSystem)
{
  if ( this->m_bFireOnChangeState )
    this->InternalExecute(this, a2: pLayoutSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10015FD0
// Name: public: virtual void CTilegenAction_SetVariable::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_SetVariable::Execute(CTilegenAction_SetVariable *this, CLayoutSystem *pLayoutSystem)
{
  if ( !this->m_bFireOnBeginGeneration && !this->m_bFireOnChangeState )
    this->InternalExecute(this, a2: pLayoutSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10016030
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_SetVariableString>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableString>::GetName(
        CTilegenAction_SetVariableString *this)
{
  return "CTilegenAction_SetVariableString";
}

//------------------------------------------------------------------------------
// Address: 0x10016040
// Name: public: virtual char const __near * CTilegenAction_SetVariableBoolExpression::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenAction_SetVariableBoolExpression::GetTypeName(
        CTilegenAction_SetVariableBoolExpression *this)
{
  return "CTilegenAction_SetVariableBoolExpression";
}

//------------------------------------------------------------------------------
// Address: 0x10016050
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_SetVariableAction>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableAction>::GetName(
        CTilegenAction_SetVariableAction *this)
{
  return "CTilegenAction_SetVariableAction";
}

//------------------------------------------------------------------------------
// Address: 0x10016060
// Name: public: virtual char const __near * CTilegenAction_AddRoomCandidates::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenAction_AddRoomCandidates::GetTypeName(CTilegenAction_AddRoomCandidates *this)
{
  return "CTilegenAction_AddRoomCandidates";
}

//------------------------------------------------------------------------------
// Address: 0x10016070
// Name: public: virtual char const __near * CTilegenAction_AddRoomCandidatesAtLocation::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenAction_AddRoomCandidatesAtLocation::GetTypeName(
        CTilegenAction_AddRoomCandidatesAtLocation *this)
{
  return "CTilegenAction_AddRoomCandidatesAtLocation";
}

//------------------------------------------------------------------------------
// Address: 0x10016080
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_ChooseCandidate>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_ChooseCandidate>::GetName(
        CTilegenAction_ChooseCandidate *this)
{
  return "CTilegenAction_ChooseCandidate";
}

//------------------------------------------------------------------------------
// Address: 0x10016090
// Name: public: virtual char const __near * CTilegenAction_FilterCandidatesByDirection::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenAction_FilterCandidatesByDirection::GetTypeName(
        CTilegenAction_FilterCandidatesByDirection *this)
{
  return "CTilegenAction_FilterCandidatesByDirection";
}

//------------------------------------------------------------------------------
// Address: 0x100160A0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_FilterCandidatesForLinearGrowth>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_FilterCandidatesForLinearGrowth>::GetName(
        CTilegenAction_FilterCandidatesForLinearGrowth *this)
{
  return "CTilegenAction_FilterCandidatesForLinearGrowth";
}

//------------------------------------------------------------------------------
// Address: 0x100160B0
// Name: public: virtual char const __near * CTilegenAction_SwitchState::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenAction_SwitchState::GetTypeName(CTilegenAction_SwitchState *this)
{
  return "CTilegenAction_SwitchState";
}

//------------------------------------------------------------------------------
// Address: 0x100160C0
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_FinishGeneration>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_FinishGeneration>::GetName(
        CTilegenAction_FinishGeneration *this)
{
  return "CTilegenAction_FinishGeneration";
}

//------------------------------------------------------------------------------
// Address: 0x100160D0
// Name: public: virtual char const __near * CTilegenAction_EpicFail::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenAction_EpicFail::GetTypeName(CTilegenAction_EpicFail *this)
{
  return "CTilegenAction_EpicFail";
}

//------------------------------------------------------------------------------
// Address: 0x100160E0
// Name: public: virtual bool CTilegenAction_FinishGeneration::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_FinishGeneration::LoadFromKeyValues(CASW_Spawn_Selection *this, const char *szName)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100160F0
// Name: public: virtual char const __near * CTilegenAction_EnsureRoomExists::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenAction_EnsureRoomExists::GetTypeName(CTilegenAction_EnsureRoomExists *this)
{
  return "CTilegenAction_EnsureRoomExists";
}

//------------------------------------------------------------------------------
// Address: 0x10016100
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_AddConnectorRoomCandidates>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_AddConnectorRoomCandidates>::GetName(
        CTilegenAction_AddConnectorRoomCandidates *this)
{
  return "CTilegenAction_AddConnectorRoomCandidates";
}

//------------------------------------------------------------------------------
// Address: 0x10016110
// Name: public: virtual char const __near * CTilegenAction_PlaceComponent::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenAction_PlaceComponent::GetTypeName(CTilegenAction_PlaceComponent *this)
{
  return "CTilegenAction_PlaceComponent";
}

//------------------------------------------------------------------------------
// Address: 0x10016120
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_AddInstances>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_AddInstances>::GetName(
        CTilegenAction_AddInstances *this)
{
  return "CTilegenAction_AddInstances";
}

//------------------------------------------------------------------------------
// Address: 0x10016130
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_AddInstanceToRoom>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_AddInstanceToRoom>::GetName(
        CTilegenAction_AddInstanceToRoom *this)
{
  return "CTilegenAction_AddInstanceToRoom";
}

//------------------------------------------------------------------------------
// Address: 0x10016140
// Name: public: virtual char const __near * CTilegenAction_LoadLayout::GetTypeName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenAction_LoadLayout::GetTypeName(CTilegenAction_LoadLayout *this)
{
  return "CTilegenAction_LoadLayout";
}

//------------------------------------------------------------------------------
// Address: 0x10016150
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenRange<class CExit const __near *>,class CTilegenRange_NewOpenExits>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenRange<CExit const *>,CTilegenRange_NewOpenExits>::GetName(
        CTilegenClassFactory<ITilegenRange<CExit const *>,CTilegenRange_NewOpenExits> *this)
{
  return "CTilegenRange_NewOpenExits";
}

//------------------------------------------------------------------------------
// Address: 0x10016160
// Name: public: virtual char const __near * CTilegenClassFactory<class ITilegenRange<class CExit const __near *>,class CTilegenRange_ClosedExits>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenClassFactory<ITilegenRange<CExit const *>,CTilegenRange_ClosedExits>::GetName(
        CTilegenClassFactory<ITilegenRange<CExit const *>,CTilegenRange_ClosedExits> *this)
{
  return "CTilegenRange_ClosedExits";
}

//------------------------------------------------------------------------------
// Address: 0x10016170
// Name: public: virtual bool CTilegenExpression_Binary<bool,int>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_Binary<bool,int>::Evaluate(
        CTilegenExpression_Binary<char const *,char const *> *this,
        CFreeVariableMap *pContext)
{
  CFreeVariableMap *v3; // edi
  CFreeVariableMap *v4; // eax
  ITilegenExpression<char const *> *v5; // ecx
  int v7; // [esp+8h] [ebp-4h] BYREF

  v3 = pContext;
  v4 = (CFreeVariableMap *)this->m_pExpression[1]->Evaluate(this: this->m_pExpression[1], a2: pContext);
  v5 = this->m_pExpression[0];
  pContext = v4;
  v7 = (int)v5->Evaluate(this: v5, a2: v3);
  return this->DirectEvaluate(this, a2: v3, a3: (const char *const *)&v7, a4: (const char *const *)&pContext);
}

//------------------------------------------------------------------------------
// Address: 0x100161C0
// Name: public: virtual int CTilegenExpression_Unary<int,bool>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_Unary<int,bool>::Evaluate(
        CTilegenExpression_Unary<int,bool> *this,
        CFreeVariableMap *pContext)
{
  CFreeVariableMap *v3; // edi

  v3 = pContext;
  HIBYTE(pContext) = this->m_pExpression->Evaluate(this: this->m_pExpression, a2: pContext);
  return this->DirectEvaluate(this, a2: v3, a3: (const bool *)&pContext + 3);
}

//------------------------------------------------------------------------------
// Address: 0x100161F0
// Name: public: virtual int CTilegenExpression_Unary<int,float>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_Unary<int,float>::Evaluate(CTilegenExpression_Unary<int,float> *this, float pContext)
{
  CFreeVariableMap *v3; // edi

  v3 = (CFreeVariableMap *)LODWORD(pContext);
  pContext = this->m_pExpression->Evaluate(this: this->m_pExpression, a2: (CFreeVariableMap *)LODWORD(pContext));
  return this->DirectEvaluate(this, a2: v3, a3: &pContext);
}

//------------------------------------------------------------------------------
// Address: 0x10016220
// Name: public: virtual class CRoom const __near * CTilegenExpression_Unary<class CRoom const __near *,class CExit const __near *>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
const CTilegenState *__thiscall CTilegenExpression_Unary<CRoom const *,CExit const *>::Evaluate(
        CTilegenExpression_Unary<CTilegenState const *,CTilegenState const *> *this,
        CFreeVariableMap *pContext)
{
  CFreeVariableMap *v3; // edi

  v3 = pContext;
  pContext = (CFreeVariableMap *)this->m_pExpression->Evaluate(this: this->m_pExpression, a2: pContext);
  return this->DirectEvaluate(this, a2: v3, a3: (const CTilegenState *const *)&pContext);
}

//------------------------------------------------------------------------------
// Address: 0x10016250
// Name: public: virtual int CTilegenExpression_MapReduce<int,class CExit const __near *>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_MapReduce<int,CExit const *>::Evaluate(
        CTilegenExpression_MapReduce<int,CExit const *> *this,
        CFreeVariableMap *pContext)
{
  CFreeVariableMap *v2; // edi
  ITilegenRange<CExit const *> *m_pInputRange; // esi
  CExit *v5; // eax
  CFreeVariableMap *v6; // eax
  int nValues; // [esp+Ch] [ebp-8h]
  int reducedValue; // [esp+10h] [ebp-4h] BYREF

  v2 = pContext;
  m_pInputRange = this->m_pInputRange;
  reducedValue = 0;
  nValues = 0;
  if ( this->m_pInputRangeExpression != nullptr )
    m_pInputRange = this->m_pInputRangeExpression->Evaluate(this: this->m_pInputRangeExpression, a2: pContext);
  else
    m_pInputRange->Initialize(this: m_pInputRange, a2: pContext);
  m_pInputRange->Reset(this: m_pInputRange);
  for ( ; m_pInputRange->MoveNext(this: m_pInputRange); reducedValue = (int)v6 )
  {
    v5 = (CExit *)m_pInputRange->GetCurrent(this: m_pInputRange);
    CFreeVariableMap::SetOrCreateFreeVariable(this: v2, pName: this->m_IteratorName, pValue: v5);
    v6 = (CFreeVariableMap *)this->m_pMapFunction->Evaluate(this: this->m_pMapFunction, a2: v2);
    pContext = v6;
    if ( nValues != 0 )
      v6 = (CFreeVariableMap *)this->m_pReduceFunction->DirectEvaluate(
                                 this: this->m_pReduceFunction,
                                 a2: v2,
                                 a3: &reducedValue,
                                 a4: (const int *)&pContext);
    ++nValues;
  }
  return reducedValue;
}

//------------------------------------------------------------------------------
// Address: 0x10016300
// Name: protected: virtual void CTilegenAction_SetVariableT<char const __near *>::InternalExecute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_SetVariableT<char const *>::InternalExecute(
        CTilegenAction_SetVariableT<char const *> *this,
        CLayoutSystem *pLayoutSystem)
{
  const char *v3; // ebx
  char *v4; // eax

  v3 = this->m_pVariableName->Evaluate(this: this->m_pVariableName, a2: &pLayoutSystem->m_FreeVariables);
  v4 = (char *)this->m_pExpression->Evaluate(this: this->m_pExpression, a2: &pLayoutSystem->m_FreeVariables);
  CFreeVariableMap::SetOrCreateFreeVariable(this: &pLayoutSystem->m_FreeVariables, pName: v3, pValue: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10016340
// Name: protected: virtual void CTilegenAction_SetVariableT<bool>::InternalExecute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_SetVariableT<bool>::InternalExecute(
        CTilegenAction_SetVariableT<bool> *this,
        CLayoutSystem *pLayoutSystem)
{
  const char *v3; // ebx
  bool v4; // al

  v3 = this->m_pVariableName->Evaluate(this: this->m_pVariableName, a2: &pLayoutSystem->m_FreeVariables);
  v4 = this->m_pExpression->Evaluate(this: this->m_pExpression, a2: &pLayoutSystem->m_FreeVariables);
  CFreeVariableMap::SetOrCreateFreeVariable(this: &pLayoutSystem->m_FreeVariables, pName: v3, pValue: (void *)v4);
}

//------------------------------------------------------------------------------
// Address: 0x10016380
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_HasTag>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenExpression_HasTag *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_HasTag>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_HasTag> *this)
{
  CTilegenExpression_HasTag *v1; // eax

  v1 = (CTilegenExpression_HasTag *)operator new(nSize: 0xCu);
  if ( v1 != nullptr )
    return CTilegenExpression_HasTag::CTilegenExpression_HasTag(
             this: v1,
             pRoomTemplateExpression: nullptr,
             pTagExpression: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100163A0
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_CanPlaceRandomly>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenExpression_CanPlaceRandomly *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_CanPlaceRandomly>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_CanPlaceRandomly> *this)
{
  CTilegenExpression_CanPlaceRandomly *v1; // eax

  v1 = (CTilegenExpression_CanPlaceRandomly *)operator new(nSize: 8u);
  if ( v1 != nullptr )
    return CTilegenExpression_CanPlaceRandomly::CTilegenExpression_CanPlaceRandomly(
             this: v1,
             pRoomTemplateExpression: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100163C0
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_AddRoomCandidates>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_AddRoomCandidates *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_AddRoomCandidates>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_AddRoomCandidates> *this)
{
  CTilegenAction_AddRoomCandidates *v1; // eax

  v1 = (CTilegenAction_AddRoomCandidates *)operator new(nSize: 0x24u);
  if ( v1 != nullptr )
    return CTilegenAction_AddRoomCandidates::CTilegenAction_AddRoomCandidates(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100163E0
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_AddRoomCandidatesAtLocation>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_AddRoomCandidatesAtLocation *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_AddRoomCandidatesAtLocation>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_AddRoomCandidatesAtLocation> *this)
{
  CTilegenAction_AddRoomCandidatesAtLocation *v1; // eax

  v1 = (CTilegenAction_AddRoomCandidatesAtLocation *)operator new(nSize: 0x18u);
  if ( v1 != nullptr )
    return CTilegenAction_AddRoomCandidatesAtLocation::CTilegenAction_AddRoomCandidatesAtLocation(
             this: v1,
             pThemeNameExpression: nullptr,
             pXExpression: nullptr,
             pYExpression: nullptr,
             pRoomTemplateFilter: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016410
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_ChooseCandidate>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_ChooseCandidate>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_ChooseCandidate> *this)
{
  ITilegenAction *result; // eax

  result = (ITilegenAction *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ITilegenAction_vtbl *)&CTilegenAction_ChooseCandidate::`vftable';
  LOBYTE(result[1].__vftable) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016430
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_FilterCandidatesByDirection>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_FilterCandidatesByDirection *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_FilterCandidatesByDirection>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_FilterCandidatesByDirection> *this)
{
  CTilegenAction_FilterCandidatesByDirection *v1; // eax

  v1 = (CTilegenAction_FilterCandidatesByDirection *)operator new(nSize: 0xCu);
  if ( v1 != nullptr )
    return CTilegenAction_FilterCandidatesByDirection::CTilegenAction_FilterCandidatesByDirection(
             this: v1,
             pDirectionExpression: nullptr,
             pThresholdExpression: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016450
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_FilterCandidatesForLinearGrowth>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_FilterCandidatesForLinearGrowth>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_FilterCandidatesForLinearGrowth> *this)
{
  ITilegenAction *result; // eax

  result = (ITilegenAction *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ITilegenAction_vtbl *)&CTilegenAction_FilterCandidatesForLinearGrowth::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016470
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_SwitchState>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_SwitchState *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_SwitchState>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_SwitchState> *this)
{
  CTilegenAction_SwitchState *v1; // eax

  v1 = (CTilegenAction_SwitchState *)operator new(nSize: 8u);
  if ( v1 != nullptr )
    return CTilegenAction_SwitchState::CTilegenAction_SwitchState(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016490
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_FinishGeneration>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_FinishGeneration>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_FinishGeneration> *this)
{
  ITilegenAction *result; // eax

  result = (ITilegenAction *)operator new(nSize: 4u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ITilegenAction_vtbl *)&CTilegenAction_FinishGeneration::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100164B0
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_EpicFail>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_EpicFail>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_EpicFail> *this)
{
  ITilegenAction *result; // eax

  result = (ITilegenAction *)operator new(nSize: 4u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ITilegenAction_vtbl *)&CTilegenAction_EpicFail::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100164D0
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_EnsureRoomExists>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_EnsureRoomExists>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_EnsureRoomExists> *this)
{
  ITilegenAction *result; // eax

  result = (ITilegenAction *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ITilegenAction_vtbl *)&CTilegenAction_EnsureRoomExists::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100164F0
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_AddConnectorRoomCandidates>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_AddConnectorRoomCandidates *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_AddConnectorRoomCandidates>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_AddConnectorRoomCandidates> *this)
{
  CTilegenAction_AddConnectorRoomCandidates *v1; // eax

  v1 = (CTilegenAction_AddConnectorRoomCandidates *)operator new(nSize: 0x18u);
  if ( v1 != nullptr )
    return CTilegenAction_AddConnectorRoomCandidates::CTilegenAction_AddConnectorRoomCandidates(
             this: v1,
             pAddRoomCandidates: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016510
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_PlaceComponent>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_PlaceComponent *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_PlaceComponent>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_PlaceComponent> *this)
{
  CTilegenAction_PlaceComponent *v1; // eax

  v1 = (CTilegenAction_PlaceComponent *)operator new(nSize: 0x6Cu);
  if ( v1 != nullptr )
    return CTilegenAction_PlaceComponent::CTilegenAction_PlaceComponent(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016530
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_AddInstances>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_AddInstances *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_AddInstances>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_AddInstances> *this)
{
  CTilegenAction_AddInstances *v1; // eax

  v1 = (CTilegenAction_AddInstances *)operator new(nSize: 0x134u);
  if ( v1 != nullptr )
    return CTilegenAction_AddInstances::CTilegenAction_AddInstances(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016550
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_AddInstanceToRoom>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_AddInstanceToRoom *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_AddInstanceToRoom>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_AddInstanceToRoom> *this)
{
  CTilegenAction_AddInstanceToRoom *v1; // eax

  v1 = (CTilegenAction_AddInstanceToRoom *)operator new(nSize: 0x130u);
  if ( v1 != nullptr )
    return CTilegenAction_AddInstanceToRoom::CTilegenAction_AddInstanceToRoom(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016570
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_LoadLayout>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_LoadLayout *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_LoadLayout>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_LoadLayout> *this)
{
  CTilegenAction_LoadLayout *v1; // eax

  v1 = (CTilegenAction_LoadLayout *)operator new(nSize: 0x108u);
  if ( v1 != nullptr )
    return CTilegenAction_LoadLayout::CTilegenAction_LoadLayout(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016990
// Name: protected: virtual void CTilegenAction_SetVariableAction::InternalExecute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_SetVariableAction::InternalExecute(
        CTilegenAction_SetVariableBoolExpression *this,
        CLayoutSystem *pLayoutSystem)
{
  const char *v3; // eax

  v3 = this->m_pVariableName->Evaluate(this: this->m_pVariableName, a2: &pLayoutSystem->m_FreeVariables);
  CFreeVariableMap::SetOrCreateFreeVariable(
    this: &pLayoutSystem->m_FreeVariables,
    pName: v3,
    pValue: this->m_pExpression);
}

//------------------------------------------------------------------------------
// Address: 0x10016A40
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_NestedActions>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_NestedActions *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_NestedActions>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_NestedActions> *this)
{
  CTilegenAction_NestedActions *v1; // eax

  v1 = (CTilegenAction_NestedActions *)operator new(nSize: 0x1Cu);
  if ( v1 != nullptr )
    return CTilegenAction_NestedActions::CTilegenAction_NestedActions(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016A80
// Name: public: virtual char const __near * CTilegenExpression_Literal<char const __near *>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_Literal<char const *>::Evaluate(
        CTilegenExpression_Literal<char const *> *this,
        CFreeVariableMap *pContext)
{
  return this->m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10016A90
// Name: public: virtual bool CTilegenExpression_Literal<bool>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Literal<bool>::Evaluate(
        CTilegenExpression_Literal<bool> *this,
        CFreeVariableMap *pContext)
{
  return this->m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10016AA0
// Name: public: virtual float CTilegenExpression_Literal<float>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTilegenExpression_Literal<float>::Evaluate(
        CTilegenExpression_Literal<float> *this,
        CFreeVariableMap *pContext)
{
  return this->m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10016AB0
// Name: public: virtual class CTilegenState const __near * CTilegenExpression_Variable<class CTilegenState const __near *>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
const CTilegenState *__thiscall CTilegenExpression_Variable<CTilegenState const *>::Evaluate(
        CTilegenExpression_Variable<CTilegenState const *> *this,
        CFreeVariableMap *pContext)
{
  const char *v4; // [esp-4h] [ebp-Ch]

  v4 = this->m_pVariableNameExpression->Evaluate(this: this->m_pVariableNameExpression, a2: pContext);
  if ( this->m_bDisallowNULL )
    return (const CTilegenState *)CFreeVariableMap::GetFreeVariableDisallowNULL(this: pContext, pName: v4);
  else
    return (const CTilegenState *)CFreeVariableMap::GetFreeVariableOrNULL(this: pContext, pName: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10016AF0
// Name: public: virtual class ITilegenExpression<class CRoom const __near *> __near * CTilegenClassFactory<class ITilegenExpression<class CRoom const __near *>,class CTilegenExpression_LastPlacedRoom>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CRoom const *> *__thiscall CTilegenClassFactory<ITilegenExpression<CRoom const *>,CTilegenExpression_LastPlacedRoom>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<CRoom const *>,CTilegenExpression_LastPlacedRoom> *this)
{
  ITilegenExpression<CRoom const *> *result; // eax

  result = (ITilegenExpression<CRoom const *> *)operator new(nSize: 4u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ITilegenExpression<CRoom const *>_vtbl *)&CTilegenExpression_LastPlacedRoom::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016B10
// Name: public: virtual class ITilegenExpression<class CRoom const __near *> __near * CTilegenClassFactory<class ITilegenExpression<class CRoom const __near *>,class CTilegenExpression_SourceRoomFromExit>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CRoom const *> *__thiscall CTilegenClassFactory<ITilegenExpression<CRoom const *>,CTilegenExpression_SourceRoomFromExit>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<CRoom const *>,CTilegenExpression_SourceRoomFromExit> *this)
{
  ITilegenExpression<CRoom const *> *result; // eax

  result = (ITilegenExpression<CRoom const *> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<CRoom const *>_vtbl *)&CTilegenExpression_SourceRoomFromExit::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016B30
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_SetVariableAction>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableAction>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableAction> *this)
{
  ITilegenAction *result; // eax

  result = (ITilegenAction *)operator new(nSize: 0x10u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  LOWORD(result[2].__vftable) = 0;
  result->__vftable = (ITilegenAction_vtbl *)&CTilegenAction_SetVariableAction::`vftable';
  result[3].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016BF0
// Name: public: virtual bool CTilegenExpression_Greater::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Greater::Evaluate(CTilegenExpression_Greater *this, CFreeVariableMap *pContext)
{
  ITilegenExpression<int> *v2; // esi
  int v3; // ebx

  v2 = this->m_pExpression[1];
  v3 = this->m_pExpression[0]->Evaluate(this: this->m_pExpression[0], a2: pContext);
  return v3 > v2->Evaluate(this: v2, a2: pContext);
}

//------------------------------------------------------------------------------
// Address: 0x10016C30
// Name: public: virtual bool CTilegenExpression_Greater::DirectEvaluate(class CFreeVariableMap __near *,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_Greater::DirectEvaluate(
        CTilegenExpression_Greater *this,
        CFreeVariableMap *pContext,
        const int *param1,
        const int *param2)
{
  return *param1 > *param2;
}

//------------------------------------------------------------------------------
// Address: 0x10016C50
// Name: public: virtual bool CTilegenExpression_GreaterOrEqual::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_GreaterOrEqual::Evaluate(
        CTilegenExpression_GreaterOrEqual *this,
        CFreeVariableMap *pContext)
{
  ITilegenExpression<int> *v2; // esi
  int v3; // ebx

  v2 = this->m_pExpression[1];
  v3 = this->m_pExpression[0]->Evaluate(this: this->m_pExpression[0], a2: pContext);
  return v3 >= v2->Evaluate(this: v2, a2: pContext);
}

//------------------------------------------------------------------------------
// Address: 0x10016C90
// Name: public: virtual bool CTilegenExpression_GreaterOrEqual::DirectEvaluate(class CFreeVariableMap __near *,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_GreaterOrEqual::DirectEvaluate(
        CTilegenExpression_GreaterOrEqual *this,
        CFreeVariableMap *pContext,
        const int *param1,
        const int *param2)
{
  return *param1 >= *param2;
}

//------------------------------------------------------------------------------
// Address: 0x10016CB0
// Name: public: virtual bool CTilegenExpression_Equal::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Equal::Evaluate(CTilegenExpression_Equal *this, CFreeVariableMap *pContext)
{
  ITilegenExpression<int> *v2; // esi
  int v3; // ebx

  v2 = this->m_pExpression[1];
  v3 = this->m_pExpression[0]->Evaluate(this: this->m_pExpression[0], a2: pContext);
  return v3 == v2->Evaluate(this: v2, a2: pContext);
}

//------------------------------------------------------------------------------
// Address: 0x10016CF0
// Name: public: virtual bool CTilegenExpression_Equal::DirectEvaluate(class CFreeVariableMap __near *,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_Equal::DirectEvaluate(
        CTilegenExpression_Equal *this,
        CFreeVariableMap *pContext,
        const int *param1,
        const int *param2)
{
  return *param1 == *param2;
}

//------------------------------------------------------------------------------
// Address: 0x10016D10
// Name: public: virtual bool CTilegenExpression_NotEqual::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_NotEqual::Evaluate(CTilegenExpression_NotEqual *this, CFreeVariableMap *pContext)
{
  ITilegenExpression<int> *v2; // esi
  int v3; // ebx

  v2 = this->m_pExpression[1];
  v3 = this->m_pExpression[0]->Evaluate(this: this->m_pExpression[0], a2: pContext);
  return v3 != v2->Evaluate(this: v2, a2: pContext);
}

//------------------------------------------------------------------------------
// Address: 0x10016D50
// Name: public: virtual bool CTilegenExpression_NotEqual::DirectEvaluate(class CFreeVariableMap __near *,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_NotEqual::DirectEvaluate(
        CTilegenExpression_NotEqual *this,
        CFreeVariableMap *pContext,
        const int *param1,
        const int *param2)
{
  return *param1 != *param2;
}

//------------------------------------------------------------------------------
// Address: 0x10016D70
// Name: public: virtual bool CTilegenExpression_Less::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Less::Evaluate(CTilegenExpression_Less *this, CFreeVariableMap *pContext)
{
  ITilegenExpression<int> *v2; // esi
  int v3; // ebx

  v2 = this->m_pExpression[1];
  v3 = this->m_pExpression[0]->Evaluate(this: this->m_pExpression[0], a2: pContext);
  return v3 < v2->Evaluate(this: v2, a2: pContext);
}

//------------------------------------------------------------------------------
// Address: 0x10016DB0
// Name: public: virtual bool CTilegenExpression_Less::DirectEvaluate(class CFreeVariableMap __near *,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_Less::DirectEvaluate(
        CTilegenExpression_Less *this,
        CFreeVariableMap *pContext,
        const int *param1,
        const int *param2)
{
  return *param1 < *param2;
}

//------------------------------------------------------------------------------
// Address: 0x10016DD0
// Name: public: virtual bool CTilegenExpression_LessOrEqual::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_LessOrEqual::Evaluate(
        CTilegenExpression_LessOrEqual *this,
        CFreeVariableMap *pContext)
{
  ITilegenExpression<int> *v2; // esi
  int v3; // ebx

  v2 = this->m_pExpression[1];
  v3 = this->m_pExpression[0]->Evaluate(this: this->m_pExpression[0], a2: pContext);
  return v3 <= v2->Evaluate(this: v2, a2: pContext);
}

//------------------------------------------------------------------------------
// Address: 0x10016E10
// Name: public: virtual bool CTilegenExpression_LessOrEqual::DirectEvaluate(class CFreeVariableMap __near *,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_LessOrEqual::DirectEvaluate(
        CTilegenExpression_LessOrEqual *this,
        CFreeVariableMap *pContext,
        const int *param1,
        const int *param2)
{
  return *param1 <= *param2;
}

//------------------------------------------------------------------------------
// Address: 0x10016E30
// Name: public: virtual int CTilegenExpression_Subtract::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_Subtract::Evaluate(CTilegenExpression_Subtract *this, CFreeVariableMap *pContext)
{
  ITilegenExpression<int> *v2; // esi
  int v3; // ebx

  v2 = this->m_pExpression[1];
  v3 = this->m_pExpression[0]->Evaluate(this: this->m_pExpression[0], a2: pContext);
  return v3 - v2->Evaluate(this: v2, a2: pContext);
}

//------------------------------------------------------------------------------
// Address: 0x10016E60
// Name: public: virtual int CTilegenExpression_Subtract::DirectEvaluate(class CFreeVariableMap __near *,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_Subtract::DirectEvaluate(
        CTilegenExpression_Subtract *this,
        CFreeVariableMap *pContext,
        const int *param1,
        const int *param2)
{
  return *param1 - *param2;
}

//------------------------------------------------------------------------------
// Address: 0x10016ED0
// Name: public: virtual bool CTilegenExpression_StringEqual::DirectEvaluate(class CFreeVariableMap __near *,char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_StringEqual::DirectEvaluate(
        CTilegenExpression_StringEqual *this,
        CFreeVariableMap *pContext,
        const char **param1,
        const char **param2)
{
  return _V_stricmp(s1: *param1, s2: *param2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10016EF0
// Name: public: virtual bool CTilegenExpression_StringNotEqual::DirectEvaluate(class CFreeVariableMap __near *,char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_StringNotEqual::DirectEvaluate(
        CTilegenExpression_StringNotEqual *this,
        CFreeVariableMap *pContext,
        const char **param1,
        const char **param2)
{
  return _V_stricmp(s1: *param1, s2: *param2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10016F20
// Name: public: virtual bool CTilegenExpression_Not::DirectEvaluate(class CFreeVariableMap __near *,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_Not::DirectEvaluate(
        CTilegenExpression_Not *this,
        CFreeVariableMap *pContext,
        const bool *param)
{
  return !*param;
}

//------------------------------------------------------------------------------
// Address: 0x10016F80
// Name: public: virtual int CTilegenExpression_BoolToInt::DirectEvaluate(class CFreeVariableMap __near *,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_BoolToInt::DirectEvaluate(
        CTilegenExpression_BoolToInt *this,
        CFreeVariableMap *pContext,
        const bool *param)
{
  return *(unsigned __int8 *)param;
}

//------------------------------------------------------------------------------
// Address: 0x10016F90
// Name: public: virtual bool CTilegenExpression_IntToBool::DirectEvaluate(class CFreeVariableMap __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_IntToBool::DirectEvaluate(
        CTilegenExpression_IntToBool *this,
        CFreeVariableMap *pContext,
        const int *param)
{
  return *param != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10016FF0
// Name: public: virtual int CTilegenExpression_FloatToInt::DirectEvaluate(class CFreeVariableMap __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_FloatToInt::DirectEvaluate(
        CTilegenExpression_FloatToInt *this,
        CFreeVariableMap *pContext,
        const float *param)
{
  return (int)*param;
}

//------------------------------------------------------------------------------
// Address: 0x10017000
// Name: public: virtual float CTilegenExpression_IntToFloat::DirectEvaluate(class CFreeVariableMap __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTilegenExpression_IntToFloat::DirectEvaluate(
        CTilegenExpression_IntToFloat *this,
        CFreeVariableMap *pContext,
        const int *param)
{
  return (double)*param;
}

//------------------------------------------------------------------------------
// Address: 0x100171C0
// Name: public: virtual bool CTilegenExpression_LiteralInt::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_LiteralInt::LoadFromKeyValues(
        CTilegenExpression_LiteralInt *this,
        KeyValues *pKeyValues)
{
  this->m_Value = KeyValues::GetInt(this: pKeyValues, keyName: "value", defaultValue: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10017210
// Name: public: virtual bool CTilegenExpression_LiteralBool::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_LiteralBool::LoadFromKeyValues(
        CTilegenExpression_LiteralBool *this,
        KeyValues *pKeyValues)
{
  this->m_Value = KeyValues::GetInt(this: pKeyValues, keyName: "value", defaultValue: 0) != 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10017240
// Name: public: virtual bool CTilegenExpression_LiteralFloat::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_LiteralFloat::LoadFromKeyValues(
        CTilegenExpression_LiteralFloat *this,
        KeyValues *pKeyValues)
{
  this->m_Value = KeyValues::GetFloat(this: pKeyValues, keyName: "value", defaultValue: 0.0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100172A0
// Name: public: virtual bool CTilegenExpression_LiteralString::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_LiteralString::LoadFromKeyValues(
        CTilegenExpression_LiteralString *this,
        KeyValues *pKeyValues)
{
  const char *String; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "value", defaultValue: nullptr);
  if ( String != nullptr )
  {
    V_strncpy(pDest: this->m_StringData, pSrc: String, maxLen: 64);
    this->m_Value = this->m_StringData;
    return 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "No value specified for CTilegenExpression_Literal in key values.\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100173A0
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_Subtract>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_Subtract>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_Subtract> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_Subtract::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100173C0
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_Not>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Not>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Not> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_Not::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100173E0
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_BoolToInt>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_BoolToInt>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_BoolToInt> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_BoolToInt::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017400
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_IntToBool>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_IntToBool>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_IntToBool> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_IntToBool::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017420
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_FloatToInt>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_FloatToInt>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_FloatToInt> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_FloatToInt::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017440
// Name: public: virtual class ITilegenExpression<float> __near * CTilegenClassFactory<class ITilegenExpression<float>,class CTilegenExpression_IntToFloat>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<float> *__thiscall CTilegenClassFactory<ITilegenExpression<float>,CTilegenExpression_IntToFloat>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<float>,CTilegenExpression_IntToFloat> *this)
{
  ITilegenExpression<float> *result; // eax

  result = (ITilegenExpression<float> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<float>_vtbl *)&CTilegenExpression_IntToFloat::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017460
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_Greater>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Greater>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Greater> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_Greater::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017480
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_GreaterOrEqual>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_GreaterOrEqual>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_GreaterOrEqual> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_GreaterOrEqual::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100174A0
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_Equal>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Equal>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Equal> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_Equal::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100174C0
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_NotEqual>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_NotEqual>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_NotEqual> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_NotEqual::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100174E0
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_Less>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Less>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Less> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_Less::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017500
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_LessOrEqual>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_LessOrEqual>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_LessOrEqual> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_LessOrEqual::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017520
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_LiteralInt>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_LiteralInt>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_LiteralInt> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_LiteralInt::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017540
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_LiteralBool>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_LiteralBool>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_LiteralBool> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  LOBYTE(result[1].__vftable) = 0;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_LiteralBool::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017560
// Name: public: virtual class ITilegenExpression<float> __near * CTilegenClassFactory<class ITilegenExpression<float>,class CTilegenExpression_LiteralFloat>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<float> *__thiscall CTilegenClassFactory<ITilegenExpression<float>,CTilegenExpression_LiteralFloat>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<float>,CTilegenExpression_LiteralFloat> *this)
{
  ITilegenExpression<float> *result; // eax

  result = (ITilegenExpression<float> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<float>_vtbl *)&CTilegenExpression_LiteralFloat::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017580
// Name: public: virtual class ITilegenExpression<char const __near *> __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_LiteralString>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<char const *> *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_LiteralString>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_LiteralString> *this)
{
  char *v1; // esi
  ITilegenExpression<char const *> *result; // eax

  v1 = (char *)operator new(nSize: 0x48u);
  result = nullptr;
  if ( v1 != nullptr )
  {
    *((_DWORD *)v1 + 1) = 0;
    *(_DWORD *)v1 = &CTilegenExpression_LiteralString::`vftable';
    V_strncpy(pDest: v1 + 8, pSrc: szDescription, maxLen: 64);
    *((_DWORD *)v1 + 1) = v1 + 8;
    return (ITilegenExpression<char const *> *)v1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100175C0
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_StringEqual>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_StringEqual>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_StringEqual> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_StringEqual::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100175E0
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_StringNotEqual>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_StringNotEqual>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_StringNotEqual> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_StringNotEqual::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017600
// Name: public: virtual class ITilegenExpression<char const __near *> __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_StringConcatenate>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<char const *> *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_StringConcatenate>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_StringConcatenate> *this)
{
  ITilegenExpression<char const *> *result; // eax

  result = (ITilegenExpression<char const *> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<char const *>_vtbl *)&CTilegenExpression_StringConcatenate::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017620
// Name: public: virtual class ITilegenExpression<char const __near *> __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_RoomName>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<char const *> *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_RoomName>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_RoomName> *this)
{
  ITilegenExpression<char const *> *result; // eax

  result = (ITilegenExpression<char const *> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<char const *>_vtbl *)&CTilegenExpression_RoomName::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017640
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_RoomArea>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_RoomArea>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_RoomArea> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_RoomArea::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017660
// Name: public: virtual class ITilegenExpression<char const __near *> __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_ExtractRoomName>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<char const *> *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_ExtractRoomName>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_ExtractRoomName> *this)
{
  ITilegenExpression<char const *> *result; // eax

  result = (ITilegenExpression<char const *> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<char const *>_vtbl *)&CTilegenExpression_ExtractRoomName::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017680
// Name: public: virtual class ITilegenExpression<char const __near *> __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_ExtractThemeName>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<char const *> *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_ExtractThemeName>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_ExtractThemeName> *this)
{
  ITilegenExpression<char const *> *result; // eax

  result = (ITilegenExpression<char const *> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<char const *>_vtbl *)&CTilegenExpression_ExtractThemeName::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100176A0
// Name: public: virtual class ITilegenExpression<class CRoomTemplate const __near *> __near * CTilegenClassFactory<class ITilegenExpression<class CRoomTemplate const __near *>,class CTilegenExpression_SourceRoomTemplateFromExit>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CRoomTemplate const *> *__thiscall CTilegenClassFactory<ITilegenExpression<CRoomTemplate const *>,CTilegenExpression_SourceRoomTemplateFromExit>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<CRoomTemplate const *>,CTilegenExpression_SourceRoomTemplateFromExit> *this)
{
  ITilegenExpression<CRoomTemplate const *> *result; // eax

  result = (ITilegenExpression<CRoomTemplate const *> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<CRoomTemplate const *>_vtbl *)&CTilegenExpression_SourceRoomTemplateFromExit::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100176C0
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_ChokepointGrowSource>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_ChokepointGrowSource>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_ChokepointGrowSource> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_ChokepointGrowSource::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100176E0
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_RoomChildCount>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_RoomChildCount>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_RoomChildCount> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_RoomChildCount::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017700
// Name: public: virtual class ITilegenExpression<class CRoomTemplate const __near *> __near * CTilegenClassFactory<class ITilegenExpression<class CRoomTemplate const __near *>,class CTilegenExpression_RoomTemplateFromName>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CRoomTemplate const *> *__thiscall CTilegenClassFactory<ITilegenExpression<CRoomTemplate const *>,CTilegenExpression_RoomTemplateFromName>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<CRoomTemplate const *>,CTilegenExpression_RoomTemplateFromName> *this)
{
  ITilegenExpression<CRoomTemplate const *> *result; // eax

  result = (ITilegenExpression<CRoomTemplate const *> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<CRoomTemplate const *>_vtbl *)&CTilegenExpression_RoomTemplateFromName::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017720
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_XPosition>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_XPosition>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_XPosition> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_XPosition::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017740
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_YPosition>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_YPosition>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_YPosition> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_YPosition::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017760
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_NumTimesPlaced>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_NumTimesPlaced>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_NumTimesPlaced> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_NumTimesPlaced::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017780
// Name: public: virtual class ITilegenExpression<char const __near *> __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_ExitTag>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<char const *> *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_ExitTag>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_ExitTag> *this)
{
  ITilegenExpression<char const *> *result; // eax

  result = (ITilegenExpression<char const *> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<char const *>_vtbl *)&CTilegenExpression_ExitTag::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100177A0
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_ExitDirection>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_ExitDirection>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_ExitDirection> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_ExitDirection::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100177C0
// Name: public: virtual class ITilegenExpression<class CTilegenState const __near *> __near * CTilegenClassFactory<class ITilegenExpression<class CTilegenState const __near *>,class CTilegenExpression_ParentState>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CTilegenState const *> *__thiscall CTilegenClassFactory<ITilegenExpression<CTilegenState const *>,CTilegenExpression_ParentState>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<CTilegenState const *>,CTilegenExpression_ParentState> *this)
{
  ITilegenExpression<CTilegenState const *> *result; // eax

  result = (ITilegenExpression<CTilegenState const *> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<CTilegenState const *>_vtbl *)&CTilegenExpression_ParentState::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100177E0
// Name: public: virtual class ITilegenExpression<char const __near *> __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_StateName>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<char const *> *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_StateName>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_StateName> *this)
{
  ITilegenExpression<char const *> *result; // eax

  result = (ITilegenExpression<char const *> *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<char const *>_vtbl *)&CTilegenExpression_StateName::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017800
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_MapReduceExits>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_MapReduceExits>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_MapReduceExits> *this)
{
  void *v1; // esi
  ITilegenExpression<int> *result; // eax

  v1 = operator new(nSize: 0x54u);
  result = nullptr;
  if ( v1 != nullptr )
  {
    *((_DWORD *)v1 + 1) = 0;
    *((_DWORD *)v1 + 2) = 0;
    *((_DWORD *)v1 + 3) = 0;
    *((_DWORD *)v1 + 4) = 0;
    *(_DWORD *)v1 = &CTilegenExpression_MapReduce<int,CExit const *>::`vftable';
    V_strncpy(pDest: (char *)v1 + 20, pSrc: szDescription, maxLen: 64);
    *(_DWORD *)v1 = &CTilegenExpression_MapReduceExits::`vftable';
    return (ITilegenExpression<int> *)v1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017850
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_VariableInt>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_VariableInt>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_VariableInt> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  LOBYTE(result[2].__vftable) = 1;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_VariableInt::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017880
// Name: public: virtual class ITilegenExpression<char const __near *> __near * CTilegenClassFactory<class ITilegenExpression<char const __near *>,class CTilegenExpression_VariableString>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<char const *> *__thiscall CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_VariableString>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<char const *>,CTilegenExpression_VariableString> *this)
{
  ITilegenExpression<char const *> *result; // eax

  result = (ITilegenExpression<char const *> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  LOBYTE(result[2].__vftable) = 1;
  result->__vftable = (ITilegenExpression<char const *>_vtbl *)&CTilegenExpression_VariableString::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100178B0
// Name: public: virtual class ITilegenExpression<class CExit const __near *> __near * CTilegenClassFactory<class ITilegenExpression<class CExit const __near *>,class CTilegenExpression_VariableExit>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CExit const *> *__thiscall CTilegenClassFactory<ITilegenExpression<CExit const *>,CTilegenExpression_VariableExit>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<CExit const *>,CTilegenExpression_VariableExit> *this)
{
  ITilegenExpression<CExit const *> *result; // eax

  result = (ITilegenExpression<CExit const *> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  LOBYTE(result[2].__vftable) = 1;
  result->__vftable = (ITilegenExpression<CExit const *>_vtbl *)&CTilegenExpression_VariableExit::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100178E0
// Name: public: virtual class ITilegenExpression<class CRoomCandidate const __near *> __near * CTilegenClassFactory<class ITilegenExpression<class CRoomCandidate const __near *>,class CTilegenExpression_VariableRoomCandidate>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CRoomCandidate const *> *__thiscall CTilegenClassFactory<ITilegenExpression<CRoomCandidate const *>,CTilegenExpression_VariableRoomCandidate>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<CRoomCandidate const *>,CTilegenExpression_VariableRoomCandidate> *this)
{
  ITilegenExpression<CRoomCandidate const *> *result; // eax

  result = (ITilegenExpression<CRoomCandidate const *> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  LOBYTE(result[2].__vftable) = 1;
  result->__vftable = (ITilegenExpression<CRoomCandidate const *>_vtbl *)&CTilegenExpression_VariableRoomCandidate::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017910
// Name: public: virtual class ITilegenExpression<class CRoomTemplate const __near *> __near * CTilegenClassFactory<class ITilegenExpression<class CRoomTemplate const __near *>,class CTilegenExpression_VariableRoomTemplate>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CRoomTemplate const *> *__thiscall CTilegenClassFactory<ITilegenExpression<CRoomTemplate const *>,CTilegenExpression_VariableRoomTemplate>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<CRoomTemplate const *>,CTilegenExpression_VariableRoomTemplate> *this)
{
  ITilegenExpression<CRoomTemplate const *> *result; // eax

  result = (ITilegenExpression<CRoomTemplate const *> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  LOBYTE(result[2].__vftable) = 1;
  result->__vftable = (ITilegenExpression<CRoomTemplate const *>_vtbl *)&CTilegenExpression_VariableRoomTemplate::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017940
// Name: public: virtual class ITilegenExpression<class CTilegenState const __near *> __near * CTilegenClassFactory<class ITilegenExpression<class CTilegenState const __near *>,class CTilegenExpression_VariableState>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CTilegenState const *> *__thiscall CTilegenClassFactory<ITilegenExpression<CTilegenState const *>,CTilegenExpression_VariableState>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<CTilegenState const *>,CTilegenExpression_VariableState> *this)
{
  ITilegenExpression<CTilegenState const *> *result; // eax

  result = (ITilegenExpression<CTilegenState const *> *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  LOBYTE(result[2].__vftable) = 1;
  result->__vftable = (ITilegenExpression<CTilegenState const *>_vtbl *)&CTilegenExpression_VariableState::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017970
// Name: public: static class ITilegenExpression<float> __near * CTilegenClassRegistry<class ITilegenExpression<float>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<float> *__cdecl CTilegenClassRegistry<ITilegenExpression<float>>::CreateInstance(
        const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017A00
// Name: public: static class ITilegenAction __near * CTilegenClassRegistry<class ITilegenAction>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__cdecl CTilegenClassRegistry<ITilegenAction>::CreateInstance(const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017A90
// Name: public: static class ITilegenExpression<class CExit const __near *> __near * CTilegenClassRegistry<class ITilegenExpression<class CExit const __near *>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CExit const *> *__cdecl CTilegenClassRegistry<ITilegenExpression<CExit const *>>::CreateInstance(
        const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017B20
// Name: public: static class ITilegenExpression<class CRoomTemplate const __near *> __near * CTilegenClassRegistry<class ITilegenExpression<class CRoomTemplate const __near *>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CRoomTemplate const *> *__cdecl CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::CreateInstance(
        const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017BB0
// Name: public: static class ITilegenExpression<class CRoomCandidate const __near *> __near * CTilegenClassRegistry<class ITilegenExpression<class CRoomCandidate const __near *>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CRoomCandidate const *> *__cdecl CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::CreateInstance(
        const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017C40
// Name: public: static class ITilegenExpression<class ITilegenRange<class CExit const __near *> __near *> __near * CTilegenClassRegistry<class ITilegenExpression<class ITilegenRange<class CExit const __near *> __near *>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<ITilegenRange<CExit const *> *> *__cdecl CTilegenClassRegistry<ITilegenExpression<ITilegenRange<CExit const *> *>>::CreateInstance(
        const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenExpression<ITilegenRange<CExit const *> *>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenExpression<ITilegenRange<CExit const *> *>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenExpression<ITilegenRange<CExit const *> *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenExpression<ITilegenRange<CExit const *> *>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenExpression<ITilegenRange<CExit const *> *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenExpression<ITilegenRange<CExit const *> *>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017CD0
// Name: public: static class ITilegenExpression<class CTilegenState const __near *> __near * CTilegenClassRegistry<class ITilegenExpression<class CTilegenState const __near *>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<CTilegenState const *> *__cdecl CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::CreateInstance(
        const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017E80
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_SetVariableInt>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableInt>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableInt> *this)
{
  ITilegenAction *result; // eax

  result = (ITilegenAction *)operator new(nSize: 0x10u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  LOWORD(result[2].__vftable) = 0;
  result[3].__vftable = nullptr;
  result->__vftable = (ITilegenAction_vtbl *)&CTilegenAction_SetVariableInt::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017EB0
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_SetVariableString>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableString>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableString> *this)
{
  ITilegenAction *result; // eax

  result = (ITilegenAction *)operator new(nSize: 0x10u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  LOWORD(result[2].__vftable) = 0;
  result[3].__vftable = nullptr;
  result->__vftable = (ITilegenAction_vtbl *)&CTilegenAction_SetVariableString::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017EE0
// Name: public: virtual class ITilegenAction __near * CTilegenClassFactory<class ITilegenAction,class CTilegenAction_SetVariableBoolExpression>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__thiscall CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableBoolExpression>::CreateInstance(
        CTilegenClassFactory<ITilegenAction,CTilegenAction_SetVariableBoolExpression> *this)
{
  ITilegenAction *result; // eax

  result = (ITilegenAction *)operator new(nSize: 0x10u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  LOWORD(result[2].__vftable) = 0;
  result[3].__vftable = nullptr;
  result->__vftable = (ITilegenAction_vtbl *)&CTilegenAction_SetVariableBoolExpression::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017F80
// Name: CreateFromKeyValues_ITilegenAction_
// Source: json
//------------------------------------------------------------------------------
ITilegenAction *__usercall CreateFromKeyValues_ITilegenAction_@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenAction *Instance; // eax
  ITilegenAction *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Tilegen class does not support literal values.\n");
    return nullptr;
  }
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenAction>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenAction *, int))v5->dtr_ITilegenAction)(a1: v5, a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
      return nullptr;
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100186A0
// Name: bool CreateActionAndCondition(class KeyValues __near *,class ITilegenAction __near * __near *,class ITilegenExpression<bool> __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateActionAndCondition(
        KeyValues *pKeyValues,
        ITilegenAction **ppAction,
        ITilegenExpression<bool> **ppCondition)
{
  ITilegenAction *v3; // eax
  bool result; // al
  KeyValues *Key; // eax
  ITilegenExpression<bool> *v6; // eax

  *ppCondition = nullptr;
  v3 = CreateFromKeyValues_ITilegenAction_(pKeyValues, bCreateEmptyInstance: false);
  *ppAction = v3;
  result = false;
  if ( v3 != nullptr )
  {
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "condition", bCreate: false);
    if ( Key == nullptr )
      return true;
    v6 = CreateFromKeyValues_ITilegenExpression_bool___(pKeyValues: Key, bCreateEmptyInstance: false);
    *ppCondition = v6;
    if ( v6 != nullptr )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018700
// Name: bool CreateActionAndConditionFromKeyValuesBlock(class KeyValues __near *,char const __near *,char const __near *,class ITilegenAction __near * __near *,class ITilegenExpression<bool> __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateActionAndConditionFromKeyValuesBlock(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenAction **ppAction,
        ITilegenExpression<bool> **ppCondition)
{
  KeyValues *Key; // edi
  ITilegenAction *v7; // eax
  KeyValues *v8; // eax
  ITilegenExpression<bool> *v9; // eax

  *ppAction = nullptr;
  *ppCondition = nullptr;
  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  if ( Key == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Could not load sub-key '%s' for parent class '%s'.\n");
    return 0;
  }
  *ppCondition = nullptr;
  v7 = CreateFromKeyValues_ITilegenAction_(pKeyValues: Key, bCreateEmptyInstance: false);
  *ppAction = v7;
  if ( v7 == nullptr )
    return 0;
  v8 = KeyValues::FindKey(this: Key, keyName: "condition", bCreate: false);
  if ( v8 != nullptr )
  {
    v9 = CreateFromKeyValues_ITilegenExpression_bool___(pKeyValues: v8, bCreateEmptyInstance: false);
    *ppCondition = v9;
    if ( v9 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10018840
// Name: public: virtual int CTilegenExpression_Multi<int>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
CFreeVariableMap *__thiscall CTilegenExpression_Multi<int>::Evaluate(
        CTilegenExpression_Multi<int> *this,
        CFreeVariableMap *pContext)
{
  int m_Size; // eax
  CFreeVariableMap *result; // eax
  bool v5; // zf
  ITilegenExpression<int> **m_pMemory; // eax
  CFreeVariableMap *v7; // edi
  int v8; // eax
  ITilegenExpression<int> **v9; // ecx
  int v10; // eax
  int (__thiscall *DirectEvaluate)(CTilegenExpression_Multi<int> *, CFreeVariableMap *, const int *, const int *); // edx
  int v12; // ebx
  ITilegenExpression<int> *v13; // ecx
  int v14; // eax
  int (__thiscall *v15)(CTilegenExpression_Multi<int> *, CFreeVariableMap *, const int *, const int *); // edx
  int v16; // [esp+4h] [ebp-8h] BYREF
  int v17; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_Expressions.m_Size;
  if ( m_Size == 0 )
    return (CFreeVariableMap *)this->GetIdentityValue(this);
  v5 = m_Size == 1;
  m_pMemory = this->m_Expressions.m_Memory.m_pMemory;
  if ( v5 )
    return (CFreeVariableMap *)(*m_pMemory)->Evaluate(this: *m_pMemory, a2: pContext);
  v7 = pContext;
  v8 = m_pMemory[1]->Evaluate(this: m_pMemory[1], a2: pContext);
  v9 = this->m_Expressions.m_Memory.m_pMemory;
  v17 = v8;
  v10 = (*v9)->Evaluate(this: *v9, a2: v7);
  DirectEvaluate = this->DirectEvaluate;
  v16 = v10;
  result = (CFreeVariableMap *)DirectEvaluate(this, a2: v7, a3: &v16, a4: &v17);
  v12 = 2;
  for ( pContext = result; v12 < this->m_Expressions.m_Size; pContext = result )
  {
    v13 = this->m_Expressions.m_Memory.m_pMemory[v12];
    v14 = v13->Evaluate(this: v13, a2: v7);
    v15 = this->DirectEvaluate;
    v16 = v14;
    result = (CFreeVariableMap *)v15(this, a2: v7, a3: (const int *)&pContext, a4: &v16);
    ++v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018900
// Name: public: virtual float CTilegenExpression_Multi<float>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTilegenExpression_Multi<float>::Evaluate(CTilegenExpression_Multi<float> *this, float pContext)
{
  int m_Size; // eax
  double result; // st7
  bool v5; // zf
  ITilegenExpression<float> **m_pMemory; // eax
  CFreeVariableMap *v7; // edi
  int i; // ebx
  ITilegenExpression<float> *v9; // ecx
  float v10; // [esp+4h] [ebp-8h] BYREF
  float v11; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_Expressions.m_Size;
  if ( m_Size == 0 )
    return this->GetIdentityValue(this);
  v5 = m_Size == 1;
  m_pMemory = this->m_Expressions.m_Memory.m_pMemory;
  if ( v5 )
    return ((float (__thiscall *)(ITilegenExpression<float> *, float))(*m_pMemory)->Evaluate)(
             a1: *m_pMemory,
             a2: COERCE_FLOAT(LODWORD(pContext)));
  v7 = (CFreeVariableMap *)LODWORD(pContext);
  v11 = m_pMemory[1]->Evaluate(this: m_pMemory[1], a2: (CFreeVariableMap *)LODWORD(pContext));
  v10 = ((double (__thiscall *)(ITilegenExpression<float> *, CFreeVariableMap *))*(_DWORD *)(**(_DWORD **)this->m_Expressions.m_Memory.m_pMemory
                                                                                           + 12))(
          a1: *this->m_Expressions.m_Memory.m_pMemory,
          a2: v7);
  result = ((double (__thiscall *)(CTilegenExpression_Multi<float> *, CFreeVariableMap *, float *, float *))this->DirectEvaluate)(
             a1: this,
             a2: v7,
             a3: &v10,
             a4: &v11);
  pContext = result;
  for ( i = 2; i < this->m_Expressions.m_Size; ++i )
  {
    v9 = this->m_Expressions.m_Memory.m_pMemory[i];
    v10 = v9->Evaluate(this: v9, a2: v7);
    result = ((double (__thiscall *)(CTilegenExpression_Multi<float> *, CFreeVariableMap *, float *, float *))this->DirectEvaluate)(
               a1: this,
               a2: v7,
               a3: &pContext,
               a4: &v10);
    pContext = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100189C0
// Name: public: virtual bool CTilegenExpression_Multi<bool>::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Multi<bool>::Evaluate(
        CTilegenExpression_Multi<bool> *this,
        CFreeVariableMap *pContext)
{
  int m_Size; // eax
  bool result; // al
  bool v5; // zf
  ITilegenExpression<bool> **m_pMemory; // eax
  CFreeVariableMap *v7; // edi
  bool v8; // al
  ITilegenExpression<bool> **v9; // ecx
  bool v10; // al
  bool (__thiscall *DirectEvaluate)(CTilegenExpression_Multi<bool> *, CFreeVariableMap *, const bool *, const bool *); // edx
  int v12; // ebx
  ITilegenExpression<bool> *v13; // ecx
  bool v14; // al
  bool (__thiscall *v15)(CTilegenExpression_Multi<bool> *, CFreeVariableMap *, const bool *, const bool *); // edx
  bool v16; // [esp+6h] [ebp-2h] BYREF
  bool v17; // [esp+7h] [ebp-1h] BYREF

  m_Size = this->m_Expressions.m_Size;
  if ( m_Size == 0 )
    return this->GetIdentityValue(this);
  v5 = m_Size == 1;
  m_pMemory = this->m_Expressions.m_Memory.m_pMemory;
  if ( v5 )
    return (*m_pMemory)->Evaluate(this: *m_pMemory, a2: pContext);
  v7 = pContext;
  v8 = m_pMemory[1]->Evaluate(this: m_pMemory[1], a2: pContext);
  v9 = this->m_Expressions.m_Memory.m_pMemory;
  v17 = v8;
  v10 = (*v9)->Evaluate(this: *v9, a2: v7);
  DirectEvaluate = this->DirectEvaluate;
  v16 = v10;
  result = DirectEvaluate(this, a2: v7, a3: &v16, a4: &v17);
  v12 = 2;
  for ( HIBYTE(pContext) = result; v12 < this->m_Expressions.m_Size; HIBYTE(pContext) = result )
  {
    v13 = this->m_Expressions.m_Memory.m_pMemory[v12];
    v14 = v13->Evaluate(this: v13, a2: v7);
    v15 = this->DirectEvaluate;
    v16 = v14;
    result = v15(this, a2: v7, a3: (const bool *)&pContext + 3, a4: &v16);
    ++v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018F40
// Name: public: virtual int CTilegenExpression_Add::DirectEvaluate(class CFreeVariableMap __near *,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_Add::DirectEvaluate(
        CTilegenExpression_Add *this,
        CFreeVariableMap *pContext,
        const int *param1,
        const int *param2)
{
  return *param2 + *param1;
}

//------------------------------------------------------------------------------
// Address: 0x10018F60
// Name: public: virtual float CTilegenExpression_FloatMultiply::DirectEvaluate(class CFreeVariableMap __near *,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTilegenExpression_FloatMultiply::DirectEvaluate(
        CTilegenExpression_FloatMultiply *this,
        CFreeVariableMap *pContext,
        const float *param1,
        const float *param2)
{
  return *param1 * *param2;
}

//------------------------------------------------------------------------------
// Address: 0x10018F80
// Name: public: virtual float CTilegenExpression_FloatMultiply::GetIdentityValue(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTilegenExpression_FloatMultiply::GetIdentityValue(CTilegenExpression_FloatMultiply *this)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10018F90
// Name: public: virtual bool CTilegenExpression_And::DirectEvaluate(class CFreeVariableMap __near *,bool const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_And::DirectEvaluate(
        CTilegenExpression_And *this,
        CFreeVariableMap *pContext,
        const bool *param1,
        const bool *param2)
{
  return *param1 && *param2;
}

//------------------------------------------------------------------------------
// Address: 0x10018FC0
// Name: public: virtual bool CTilegenExpression_Or::DirectEvaluate(class CFreeVariableMap __near *,bool const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTilegenExpression_Or::DirectEvaluate(
        CTilegenExpression_Or *this,
        CFreeVariableMap *pContext,
        const bool *param1,
        const bool *param2)
{
  return *param1 || *param2;
}

//------------------------------------------------------------------------------
// Address: 0x10018FF0
// Name: public: virtual bool CTilegenExpression_Binary<int,int>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Binary<int,int>::LoadFromKeyValues(
        CTilegenExpression_Binary<int,int> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax
  bool v4; // bl
  const char *v5; // eax

  v3 = this->GetTypeName(this);
  v4 = CreateFromKeyValuesBlock<ITilegenExpression<int>>(
         pParentKV: pKeyValues,
         pKeyName: "param0",
         pParentClassName: v3,
         ppClass: this->m_pExpression,
         bOptional: false,
         bCreateEmptyInstance: false);
  v5 = this->GetTypeName(this);
  return v4
       & CreateFromKeyValuesBlock<ITilegenExpression<int>>(
           pParentKV: pKeyValues,
           pKeyName: "param1",
           pParentClassName: v5,
           ppClass: &this->m_pExpression[1],
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x10019050
// Name: public: virtual bool CTilegenExpression_Multi<int>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_Multi<int>::LoadFromKeyValues(
        CTilegenExpression_Multi<int> *this,
        KeyValues *pKeyValues)
{
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  const char *String; // eax
  ITilegenExpression<int> *Instance; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ITilegenExpression<int> **m_pMemory; // ecx
  int v9; // eax
  ITilegenExpression<int> **v10; // eax
  KeyValues *pKeyValuesa; // [esp+18h] [ebp+8h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "param") != 0 )
      goto LABEL_17;
    if ( KeyValues::GetFirstSubKey(this: FirstSubKey) != nullptr )
      break;
    pKeyValuesa = (KeyValues *)ReadLiteralIntValue(pKeyValues: FirstSubKey);
LABEL_10:
    if ( pKeyValuesa == nullptr )
      return 0;
    m_Size = this->m_Expressions.m_Size;
    m_nAllocationCount = this->m_Expressions.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Expressions,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Expressions.m_Size;
    m_pMemory = this->m_Expressions.m_Memory.m_pMemory;
    v9 = this->m_Expressions.m_Size - m_Size - 1;
    this->m_Expressions.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_Expressions.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = (ITilegenExpression<int> *)pKeyValuesa;
LABEL_17:
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return 1;
  }
  String = KeyValues::GetString(this: FirstSubKey, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<int>>::CreateInstance(pClassName: String);
    if ( Instance != nullptr && !Instance->LoadFromKeyValues(this: Instance, a2: FirstSubKey) )
    {
      ((void (__thiscall *)(ITilegenExpression<int> *, int))Instance->dtr_ITilegenExpression<int>)(a1: Instance, a2: 1);
      Instance = nullptr;
    }
    pKeyValuesa = (KeyValues *)Instance;
    goto LABEL_10;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100191A0
// Name: public: virtual bool CTilegenExpression_Multi<float>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_Multi<float>::LoadFromKeyValues(
        CTilegenExpression_Multi<float> *this,
        KeyValues *pKeyValues)
{
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  const char *String; // eax
  ITilegenExpression<float> *Instance; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ITilegenExpression<float> **m_pMemory; // ecx
  int v9; // eax
  ITilegenExpression<float> **v10; // eax
  KeyValues *pKeyValuesa; // [esp+18h] [ebp+8h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "param") != 0 )
      goto LABEL_17;
    if ( KeyValues::GetFirstSubKey(this: FirstSubKey) != nullptr )
      break;
    pKeyValuesa = (KeyValues *)ReadLiteralFloatValue(pKeyValues: FirstSubKey);
LABEL_10:
    if ( pKeyValuesa == nullptr )
      return 0;
    m_Size = this->m_Expressions.m_Size;
    m_nAllocationCount = this->m_Expressions.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Expressions,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Expressions.m_Size;
    m_pMemory = this->m_Expressions.m_Memory.m_pMemory;
    v9 = this->m_Expressions.m_Size - m_Size - 1;
    this->m_Expressions.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_Expressions.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = (ITilegenExpression<float> *)pKeyValuesa;
LABEL_17:
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return 1;
  }
  String = KeyValues::GetString(this: FirstSubKey, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<float>>::CreateInstance(pClassName: String);
    if ( Instance != nullptr && !Instance->LoadFromKeyValues(this: Instance, a2: FirstSubKey) )
    {
      ((void (__thiscall *)(ITilegenExpression<float> *, int))Instance->dtr_ITilegenExpression<float>)(
        a1: Instance,
        a2: 1);
      Instance = nullptr;
    }
    pKeyValuesa = (KeyValues *)Instance;
    goto LABEL_10;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100192F0
// Name: public: virtual bool CTilegenExpression_Multi<bool>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_Multi<bool>::LoadFromKeyValues(
        CTilegenExpression_Multi<bool> *this,
        KeyValues *pKeyValues)
{
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  const char *String; // eax
  ITilegenExpression<bool> *Instance; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ITilegenExpression<bool> **m_pMemory; // ecx
  int v9; // eax
  ITilegenExpression<bool> **v10; // eax
  KeyValues *pKeyValuesa; // [esp+18h] [ebp+8h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "param") != 0 )
      goto LABEL_17;
    if ( KeyValues::GetFirstSubKey(this: FirstSubKey) != nullptr )
      break;
    pKeyValuesa = (KeyValues *)ReadLiteralBoolValue(pKeyValues: FirstSubKey);
LABEL_10:
    if ( pKeyValuesa == nullptr )
      return 0;
    m_Size = this->m_Expressions.m_Size;
    m_nAllocationCount = this->m_Expressions.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Expressions,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Expressions.m_Size;
    m_pMemory = this->m_Expressions.m_Memory.m_pMemory;
    v9 = this->m_Expressions.m_Size - m_Size - 1;
    this->m_Expressions.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_Expressions.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = (ITilegenExpression<bool> *)pKeyValuesa;
LABEL_17:
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return 1;
  }
  String = KeyValues::GetString(this: FirstSubKey, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<bool>>::CreateInstance(pClassName: String);
    if ( Instance != nullptr && !Instance->LoadFromKeyValues(this: Instance, a2: FirstSubKey) )
    {
      ((void (__thiscall *)(ITilegenExpression<bool> *, int))Instance->dtr_ITilegenExpression<bool>)(
        a1: Instance,
        a2: 1);
      Instance = nullptr;
    }
    pKeyValuesa = (KeyValues *)Instance;
    goto LABEL_10;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019440
// Name: public: virtual bool CTilegenExpression_Unary<bool,bool>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Unary<bool,bool>::LoadFromKeyValues(
        CTilegenExpression_Unary<int,bool> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<bool>>(
           pParentKV: pKeyValues,
           pKeyName: "param",
           pParentClassName: v3,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x10019470
// Name: public: virtual bool CTilegenExpression_Unary<float,int>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Unary<float,int>::LoadFromKeyValues(
        CTilegenExpression_Unary<float,int> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<int>>(
           pParentKV: pKeyValues,
           pKeyName: "param",
           pParentClassName: v3,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x100194A0
// Name: public: virtual bool CTilegenExpression_Unary<int,float>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Unary<int,float>::LoadFromKeyValues(
        CTilegenExpression_Unary<int,float> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<float>>(
           pParentKV: pKeyValues,
           pKeyName: "param",
           pParentClassName: v3,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x100194D0
// Name: public: CTilegenExpression_CountRange<class CExit const __near *>::CTilegenExpression_CountRange<class CExit const __near *>(class ITilegenRange<class CExit const __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
CTilegenExpression_CountRange<CExit const *> *__thiscall CTilegenExpression_CountRange<CExit const *>::CTilegenExpression_CountRange<CExit const *>(
        CTilegenExpression_CountRange<CExit const *> *this,
        ITilegenRange<CExit const *> *pRange)
{
  CTilegenExpression_Multi<int> *v3; // eax
  CTilegenExpression_Multi<int> *v4; // ebx
  ITilegenExpression<int> *v5; // eax

  v3 = (CTilegenExpression_Multi<int> *)operator new(nSize: 0x18u);
  if ( v3 != nullptr )
  {
    v3->m_Expressions.m_Memory.m_pMemory = nullptr;
    v3->m_Expressions.m_Memory.m_nAllocationCount = 0;
    v3->m_Expressions.m_Memory.m_nGrowSize = 0;
    v3->m_Expressions.m_Size = 0;
    v3->m_Expressions.m_pElements = nullptr;
    v3->__vftable = (CTilegenExpression_Multi<int>_vtbl *)&CTilegenExpression_Add::`vftable';
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (ITilegenExpression<int> *)operator new(nSize: 8u);
  if ( v5 != nullptr )
  {
    v5[1].__vftable = (ITilegenExpression<int>_vtbl *)1;
    v5->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_LiteralInt::`vftable';
  }
  else
  {
    v5 = nullptr;
  }
  this->__vftable = (CTilegenExpression_CountRange<CExit const *>_vtbl *)&CTilegenExpression_MapReduce<int,CExit const *>::`vftable';
  this->m_pInputRangeExpression = nullptr;
  this->m_pInputRange = pRange;
  this->m_pMapFunction = v5;
  this->m_pReduceFunction = v4;
  V_strncpy(pDest: this->m_IteratorName, pSrc: "$$unused", maxLen: 64);
  this->__vftable = (CTilegenExpression_CountRange<CExit const *>_vtbl *)&CTilegenExpression_CountRange<CExit const *>::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10019560
// Name: public: static void CTilegenClassRegistry<class ITilegenExpression<bool>>::AddFactory(class ITilegenClassFactory<class ITilegenExpression<bool>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(
        ITilegenClassFactory<ITilegenExpression<bool> > *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenExpression<bool> > **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenExpression<bool> > **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x100195D0
// Name: public: static void CTilegenClassRegistry<class ITilegenExpression<int>>::AddFactory(class ITilegenClassFactory<class ITilegenExpression<int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(
        ITilegenClassFactory<ITilegenExpression<int> > *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenExpression<int> > **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenExpression<int> > **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10019640
// Name: public: static void CTilegenClassRegistry<class ITilegenExpression<float>>::AddFactory(class ITilegenClassFactory<class ITilegenExpression<float>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenExpression<float>>::AddFactory(
        ITilegenClassFactory<ITilegenExpression<float> > *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenExpression<float> > **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenExpression<float> > **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x100196B0
// Name: public: static void CTilegenClassRegistry<class ITilegenExpression<char const __near *>>::AddFactory(class ITilegenClassFactory<class ITilegenExpression<char const __near *>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenExpression<char const *>>::AddFactory(
        ITilegenClassFactory<ITilegenExpression<char const *> > *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenExpression<char const *> > **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenExpression<char const *> > **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10019720
// Name: public: static void CTilegenClassRegistry<class ITilegenExpression<class CExit const __near *>>::AddFactory(class ITilegenClassFactory<class ITilegenExpression<class CExit const __near *>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenExpression<CExit const *>>::AddFactory(
        ITilegenClassFactory<ITilegenExpression<CExit const *> > *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenExpression<CExit const *> > **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenExpression<CExit const *> > **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10019790
// Name: public: static void CTilegenClassRegistry<class ITilegenExpression<class CRoomTemplate const __near *>>::AddFactory(class ITilegenClassFactory<class ITilegenExpression<class CRoomTemplate const __near *>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::AddFactory(
        ITilegenClassFactory<ITilegenExpression<CRoomTemplate const *> > *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenExpression<CRoomTemplate const *> > **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenExpression<CRoomTemplate const *> > **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10019800
// Name: public: static void CTilegenClassRegistry<class ITilegenExpression<class CRoom const __near *>>::AddFactory(class ITilegenClassFactory<class ITilegenExpression<class CRoom const __near *>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::AddFactory(
        ITilegenClassFactory<ITilegenExpression<CRoom const *> > *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenExpression<CRoom const *> > **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenExpression<CRoom const *> > **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10019870
// Name: public: static void CTilegenClassRegistry<class ITilegenExpression<class CRoomCandidate const __near *>>::AddFactory(class ITilegenClassFactory<class ITilegenExpression<class CRoomCandidate const __near *>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::AddFactory(
        ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *> > *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *> > **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *> > **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x100198E0
// Name: public: static void CTilegenClassRegistry<class ITilegenExpression<class CTilegenState const __near *>>::AddFactory(class ITilegenClassFactory<class ITilegenExpression<class CTilegenState const __near *>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::AddFactory(
        ITilegenClassFactory<ITilegenExpression<CTilegenState const *> > *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenExpression<CTilegenState const *> > **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenExpression<CTilegenState const *> > **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10019950
// Name: public: static void CTilegenClassRegistry<class ITilegenAction>::AddFactory(class ITilegenClassFactory<class ITilegenAction> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenAction>::AddFactory(ITilegenClassFactory<ITilegenAction> *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenAction> **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenAction> **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenAction>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenAction>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x100199C0
// Name: public: static void CTilegenClassRegistry<class ITilegenRange<class CExit const __near *>>::AddFactory(class ITilegenClassFactory<class ITilegenRange<class CExit const __near *>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTilegenClassRegistry<ITilegenRange<CExit const *>>::AddFactory(
        ITilegenClassFactory<ITilegenRange<CExit const *> > *pFactory)
{
  int m_Size; // eax
  int v2; // esi
  ITilegenClassFactory<ITilegenRange<CExit const *> > **m_pMemory; // ecx
  int v4; // eax
  ITilegenClassFactory<ITilegenRange<CExit const *> > **v5; // eax

  m_Size = CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Size;
  v2 = CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Size;
  if ( CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Size + 1 > CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList,
      num: CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Size
    - CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Size;
  }
  m_pMemory = CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_pMemory;
  CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_pElements = CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v2 + 1],
      src: &CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10019A30
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_Add>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_Add>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_Add> *this)
{
  ITilegenExpression<int> *result; // eax

  result = (ITilegenExpression<int> *)operator new(nSize: 0x18u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result[3].__vftable = nullptr;
  result[4].__vftable = nullptr;
  result[5].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<int>_vtbl *)&CTilegenExpression_Add::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019A60
// Name: public: virtual class ITilegenExpression<float> __near * CTilegenClassFactory<class ITilegenExpression<float>,class CTilegenExpression_FloatMultiply>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<float> *__thiscall CTilegenClassFactory<ITilegenExpression<float>,CTilegenExpression_FloatMultiply>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<float>,CTilegenExpression_FloatMultiply> *this)
{
  ITilegenExpression<float> *result; // eax

  result = (ITilegenExpression<float> *)operator new(nSize: 0x18u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result[3].__vftable = nullptr;
  result[4].__vftable = nullptr;
  result[5].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<float>_vtbl *)&CTilegenExpression_FloatMultiply::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019A90
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_And>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_And>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_And> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 0x18u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result[3].__vftable = nullptr;
  result[4].__vftable = nullptr;
  result[5].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_And::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019AC0
// Name: public: virtual class ITilegenExpression<bool> __near * CTilegenClassFactory<class ITilegenExpression<bool>,class CTilegenExpression_Or>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__thiscall CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Or>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<bool>,CTilegenExpression_Or> *this)
{
  ITilegenExpression<bool> *result; // eax

  result = (ITilegenExpression<bool> *)operator new(nSize: 0x18u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result[3].__vftable = nullptr;
  result[4].__vftable = nullptr;
  result[5].__vftable = nullptr;
  result->__vftable = (ITilegenExpression<bool>_vtbl *)&CTilegenExpression_Or::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019B70
// Name: public: virtual bool CTilegenAction_SetVariable::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_SetVariable::LoadFromKeyValues(CTilegenAction_SetVariable *this, KeyValues *pKeyValues)
{
  const char *v3; // eax
  char v4; // bl

  v3 = this->GetTypeName(this);
  v4 = CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
         pParentKV: pKeyValues,
         pKeyName: "variable",
         pParentClassName: v3,
         ppClass: &this->m_pVariableName,
         bOptional: false,
         bCreateEmptyInstance: false)
     & 1;
  this->m_bFireOnBeginGeneration = KeyValues::GetInt(this: pKeyValues, keyName: "on_begin_generation", defaultValue: 0) != 0;
  this->m_bFireOnChangeState = KeyValues::GetInt(this: pKeyValues, keyName: "on_begin_state", defaultValue: 0) != 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10019BE0
// Name: public: virtual bool CTilegenAction_SetVariableAction::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_SetVariableAction::LoadFromKeyValues(
        CTilegenAction_SetVariableAction *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // edi
  char v4; // bl
  const char *v5; // eax
  char v6; // bl

  v2 = pKeyValues;
  v4 = CTilegenAction_SetVariable::LoadFromKeyValues(this, pKeyValues) & 1;
  v5 = this->GetTypeName(this);
  v6 = CreateActionAndConditionFromKeyValuesBlock(
         pParentKV: v2,
         pKeyName: "value",
         pParentClassName: v5,
         ppAction: &this->m_pAction,
         ppCondition: (ITilegenExpression<bool> **)&pKeyValues)
     & v4;
  if ( pKeyValues == nullptr )
    return v6;
  (**(void (__thiscall ***)(KeyValues *, int))pKeyValues)(a1: pKeyValues, a2: 1);
  _Warning(a1: "'CTilegenAction_SetVariableAction' cannot set actions which have associated conditions.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019C50
// Name: void RegisterAllTilegenClasses(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RegisterAllTilegenClasses()
{
  if ( !bRegistered )
  {
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_Add_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_Subtract_Factory);
    CTilegenClassRegistry<ITilegenExpression<float>>::AddFactory(pFactory: &s_CTilegenExpression_FloatMultiply_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_And_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_Or_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_Not_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_BoolToInt_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_IntToBool_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_FloatToInt_Factory);
    CTilegenClassRegistry<ITilegenExpression<float>>::AddFactory(pFactory: &s_CTilegenExpression_IntToFloat_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_Greater_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_GreaterOrEqual_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_Equal_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_NotEqual_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_Less_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_LessOrEqual_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_LiteralInt_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_LiteralBool_Factory);
    CTilegenClassRegistry<ITilegenExpression<float>>::AddFactory(pFactory: &s_CTilegenExpression_LiteralFloat_Factory);
    CTilegenClassRegistry<ITilegenExpression<char const *>>::AddFactory(pFactory: &s_CTilegenExpression_LiteralString_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_StringEqual_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_StringNotEqual_Factory);
    CTilegenClassRegistry<ITilegenExpression<char const *>>::AddFactory(pFactory: &s_CTilegenExpression_StringConcatenate_Factory);
    CTilegenClassRegistry<ITilegenExpression<char const *>>::AddFactory(pFactory: &s_CTilegenExpression_RoomName_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_RoomArea_Factory);
    CTilegenClassRegistry<ITilegenExpression<char const *>>::AddFactory(pFactory: &s_CTilegenExpression_ExtractRoomName_Factory);
    CTilegenClassRegistry<ITilegenExpression<char const *>>::AddFactory(pFactory: &s_CTilegenExpression_ExtractThemeName_Factory);
    CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::AddFactory(pFactory: &s_CTilegenExpression_LastPlacedRoom_Factory);
    CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::AddFactory(pFactory: &s_CTilegenExpression_SourceRoomFromExit_Factory);
    CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::AddFactory(pFactory: &s_CTilegenExpression_SourceRoomTemplateFromExit_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_ChokepointGrowSource_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_RoomChildCount_Factory);
    CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::AddFactory(pFactory: &s_CTilegenExpression_RoomTemplateFromName_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_XPosition_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_YPosition_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_HasTag_Factory);
    CTilegenClassRegistry<ITilegenExpression<bool>>::AddFactory(pFactory: &s_CTilegenExpression_CanPlaceRandomly_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_NumTimesPlaced_Factory);
    CTilegenClassRegistry<ITilegenExpression<char const *>>::AddFactory(pFactory: &s_CTilegenExpression_ExitTag_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_ExitDirection_Factory);
    CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::AddFactory(pFactory: &s_CTilegenExpression_ParentState_Factory);
    CTilegenClassRegistry<ITilegenExpression<char const *>>::AddFactory(pFactory: &s_CTilegenExpression_StateName_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_MapReduceExits_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_CountExits_Factory);
    CTilegenClassRegistry<ITilegenExpression<int>>::AddFactory(pFactory: &s_CTilegenExpression_VariableInt_Factory);
    CTilegenClassRegistry<ITilegenExpression<char const *>>::AddFactory(pFactory: &s_CTilegenExpression_VariableString_Factory);
    CTilegenClassRegistry<ITilegenExpression<CExit const *>>::AddFactory(pFactory: &s_CTilegenExpression_VariableExit_Factory);
    CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::AddFactory(pFactory: &s_CTilegenExpression_VariableRoomCandidate_Factory);
    CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::AddFactory(pFactory: &s_CTilegenExpression_VariableRoomTemplate_Factory);
    CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::AddFactory(pFactory: &s_CTilegenExpression_VariableState_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_NestedActions_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_SetVariableInt_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_SetVariableString_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_SetVariableBoolExpression_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_SetVariableAction_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_AddRoomCandidates_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_AddRoomCandidatesAtLocation_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_ChooseCandidate_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_FilterCandidatesByDirection_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_FilterCandidatesForLinearGrowth_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_SwitchState_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_FinishGeneration_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_EpicFail_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_EnsureRoomExists_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_AddConnectorRoomCandidates_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_PlaceComponent_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_AddInstances_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_AddInstanceToRoom_Factory);
    CTilegenClassRegistry<ITilegenAction>::AddFactory(pFactory: &s_CTilegenAction_LoadLayout_Factory);
    CTilegenClassRegistry<ITilegenRange<CExit const *>>::AddFactory(pFactory: &s_CTilegenRange_NewOpenExits_Factory);
    CTilegenClassRegistry<ITilegenRange<CExit const *>>::AddFactory(pFactory: &s_CTilegenRange_ClosedExits_Factory);
    bRegistered = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019F40
// Name: public: virtual bool CTilegenExpression_Binary<char const __near *,char const __near *>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Binary<char const *,char const *>::LoadFromKeyValues(
        CTilegenExpression_Binary<char const *,char const *> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax
  char v4; // bl
  const char *v5; // eax

  v3 = this->GetTypeName(this);
  v4 = CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
         pParentKV: pKeyValues,
         pKeyName: "param0",
         pParentClassName: v3,
         ppClass: this->m_pExpression,
         bOptional: false,
         bCreateEmptyInstance: false)
     & 1;
  v5 = this->GetTypeName(this);
  return v4
       & CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
           pParentKV: pKeyValues,
           pKeyName: "param1",
           pParentClassName: v5,
           ppClass: &this->m_pExpression[1],
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x10019FA0
// Name: public: virtual bool CTilegenExpression_Unary<char const __near *,class CRoomTemplate const __near *>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Unary<char const *,CRoomTemplate const *>::LoadFromKeyValues(
        CTilegenExpression_Unary<int,CRoomTemplate const *> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<CRoomTemplate const *>>(
           pParentKV: pKeyValues,
           pKeyName: "param",
           pParentClassName: v3,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x10019FD0
// Name: public: virtual bool CTilegenExpression_Unary<int,class CRoom const __near *>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_Unary<int,CRoom const *>::LoadFromKeyValues(
        CTilegenExpression_Unary<int,CRoom const *> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<CRoom const *>>(
           pParentKV: pKeyValues,
           pKeyName: "param",
           pParentClassName: v3,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001A000
// Name: public: virtual bool CTilegenExpression_Unary<class CRoomTemplate const __near *,char const __near *>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_Unary<CRoomTemplate const *,char const *>::LoadFromKeyValues(
        CTilegenExpression_Unary<CRoomTemplate const *,char const *> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
           pParentKV: pKeyValues,
           pKeyName: "param",
           pParentClassName: v3,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001A030
// Name: public: virtual bool CTilegenExpression_Unary<int,class CRoomCandidate const __near *>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Unary<int,CRoomCandidate const *>::LoadFromKeyValues(
        CTilegenExpression_Unary<int,CRoomCandidate const *> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<CRoomCandidate const *>>(
           pParentKV: pKeyValues,
           pKeyName: "param",
           pParentClassName: v3,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001A060
// Name: public: virtual bool CTilegenExpression_Unary<bool,class CExit const __near *>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Unary<bool,CExit const *>::LoadFromKeyValues(
        CTilegenExpression_Unary<int,CExit const *> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<CExit const *>>(
           pParentKV: pKeyValues,
           pKeyName: "param",
           pParentClassName: v3,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001A090
// Name: public: virtual bool CTilegenExpression_Unary<char const __near *,class CTilegenState const __near *>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Unary<char const *,CTilegenState const *>::LoadFromKeyValues(
        CTilegenExpression_Unary<char const *,CTilegenState const *> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<CTilegenState const *>>(
           pParentKV: pKeyValues,
           pKeyName: "param",
           pParentClassName: v3,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001A0C0
// Name: public: virtual bool CTilegenExpression_Variable<class CTilegenState const __near *>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_Variable<CTilegenState const *>::LoadFromKeyValues(
        CTilegenExpression_Variable<CTilegenState const *> *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  if ( CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
         pParentKV: pKeyValues,
         pKeyName: "variable",
         pParentClassName: v3,
         ppClass: &this->m_pVariableNameExpression,
         bOptional: false,
         bCreateEmptyInstance: false) != 0 )
  {
    this->m_bDisallowNULL = KeyValues::GetInt(this: pKeyValues, keyName: "disallow_null", defaultValue: 1) != 0;
    return 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "No variable specified for CTilegenExpression_Variable in key values.\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A140
// Name: public: virtual bool CTilegenExpression_MapReduce<int,class CExit const __near *>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_MapReduce<int,CExit const *>::LoadFromKeyValues(
        CTilegenExpression_MapReduce<int,CExit const *> *this,
        CTilegenExpression_Multi<int> *pKeyValues)
{
  KeyValues *v3; // edi
  KeyValues *Key; // ebx
  KeyValues *v5; // eax
  bool result; // al
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *(__thiscall *GetTypeName)(struct CTilegenExpression_MapReduce<int,CExit const *> *); // eax
  const char *v11; // eax
  char *m_IteratorName; // esi
  const char *String; // eax

  v3 = (KeyValues *)pKeyValues;
  if ( this->m_pInputRangeExpression != nullptr || this->m_pInputRange != nullptr )
  {
LABEL_14:
    if ( this->m_pMapFunction == nullptr )
    {
      v9 = this->GetTypeName(this);
      if ( !CreateFromKeyValuesBlock<ITilegenExpression<int>>(
              pParentKV: v3,
              pKeyName: "map",
              pParentClassName: v9,
              ppClass: &this->m_pMapFunction,
              bOptional: false,
              bCreateEmptyInstance: false) )
        return false;
    }
    if ( this->m_pReduceFunction == nullptr )
    {
      GetTypeName = this->GetTypeName;
      pKeyValues = nullptr;
      v11 = GetTypeName(this);
      CreateFromKeyValuesBlock<ITilegenExpression<int>>(
        pParentKV: v3,
        pKeyName: "reduce",
        pParentClassName: v11,
        ppClass: &pKeyValues,
        bOptional: false,
        bCreateEmptyInstance: true);
      this->m_pReduceFunction = pKeyValues;
    }
    m_IteratorName = this->m_IteratorName;
    if ( *m_IteratorName == 0 )
    {
      String = KeyValues::GetString(this: v3, keyName: "iterator", defaultValue: nullptr);
      if ( String == nullptr )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        {
          _LoggingSystem_Log(
            a1: LOG_TilegenLayoutSystem,
            a2: 1,
            a3: "No iterator name specified for CTilegenExpression_MapReduce in Key Values.\n");
          return false;
        }
        return false;
      }
      V_strncpy(pDest: m_IteratorName, pSrc: String, maxLen: 64);
    }
    return true;
  }
  Key = KeyValues::FindKey(this: (KeyValues *)pKeyValues, keyName: "range_expression", bCreate: false);
  v5 = KeyValues::FindKey(this: v3, keyName: "range", bCreate: false);
  if ( Key == nullptr )
  {
    if ( v5 == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not find 'range' or 'range_expression' subkey in CTilegenExpression_MapReduce in KeyValues file.\n");
      return false;
    }
    v8 = this->GetTypeName(this);
    if ( !CreateFromKeyValuesBlock<ITilegenRange<CExit const *>>(
            pParentKV: v3,
            pKeyName: "range",
            pParentClassName: v8,
            ppClass: &this->m_pInputRange,
            bOptional: false,
            bCreateEmptyInstance: false) )
      return false;
    goto LABEL_14;
  }
  if ( v5 != nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    {
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Found both a 'range' and 'range_expression' subkey in CTilegenExpression_MapReduce in KeyValues file.\n");
      return false;
    }
    return false;
  }
  v7 = this->GetTypeName(this);
  result = CreateFromKeyValuesBlock<ITilegenExpression<ITilegenRange<CExit const *> *>>(
             pParentKV: v3,
             pKeyName: "range_expression",
             pParentClassName: v7,
             ppClass: &this->m_pInputRangeExpression,
             bOptional: false,
             bCreateEmptyInstance: false);
  if ( result )
    goto LABEL_14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A320
// Name: public: virtual bool CTilegenAction_SetVariableT<int>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenAction_SetVariableT<int>::LoadFromKeyValues(
        CTilegenAction_SetVariableT<int> *this,
        KeyValues *pKeyValues)
{
  char v3; // bl
  const char *v4; // eax

  v3 = CTilegenAction_SetVariable::LoadFromKeyValues(this, pKeyValues) & 1;
  v4 = this->GetTypeName(this);
  return v3
       & CreateFromKeyValuesBlock<ITilegenExpression<int>>(
           pParentKV: pKeyValues,
           pKeyName: "value",
           pParentClassName: v4,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001A360
// Name: public: virtual bool CTilegenAction_SetVariableT<char const __near *>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenAction_SetVariableT<char const *>::LoadFromKeyValues(
        CTilegenAction_SetVariableT<char const *> *this,
        KeyValues *pKeyValues)
{
  char v3; // bl
  const char *v4; // eax

  v3 = CTilegenAction_SetVariable::LoadFromKeyValues(this, pKeyValues) & 1;
  v4 = this->GetTypeName(this);
  return v3
       & CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
           pParentKV: pKeyValues,
           pKeyName: "value",
           pParentClassName: v4,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001A3A0
// Name: public: virtual bool CTilegenAction_SetVariableT<bool>::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenAction_SetVariableT<bool>::LoadFromKeyValues(
        CTilegenAction_SetVariableT<bool> *this,
        KeyValues *pKeyValues)
{
  char v3; // bl
  const char *v4; // eax

  v3 = CTilegenAction_SetVariable::LoadFromKeyValues(this, pKeyValues) & 1;
  v4 = this->GetTypeName(this);
  return v3
       & CreateFromKeyValuesBlock<ITilegenExpression<bool>>(
           pParentKV: pKeyValues,
           pKeyName: "value",
           pParentClassName: v4,
           ppClass: &this->m_pExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001A3E0
// Name: public: virtual class ITilegenExpression<int> __near * CTilegenClassFactory<class ITilegenExpression<int>,class CTilegenExpression_CountExits>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
ITilegenExpression<int> *__thiscall CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_CountExits>::CreateInstance(
        CTilegenClassFactory<ITilegenExpression<int>,CTilegenExpression_CountExits> *this)
{
  CTilegenExpression_CountRange<CExit const *> *v1; // eax
  _DWORD *v2; // esi

  v1 = (CTilegenExpression_CountRange<CExit const *> *)operator new(nSize: 0x54u);
  v2 = &v1->__vftable;
  if ( v1 == nullptr )
    return nullptr;
  CTilegenExpression_CountRange<CExit const *>::CTilegenExpression_CountRange<CExit const *>(this: v1, pRange: nullptr);
  *v2 = &CTilegenExpression_CountExits::`vftable';
  return (ITilegenExpression<int> *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100BA790
// Name: public: virtual bool CTilegenExpression_Or::GetIdentityValue(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_Or::GetIdentityValue(vgui::ToggleButton *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100FCF40
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_bool___::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_bool___::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_bool___::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCF50
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_int___::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_int___::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_int___::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCF60
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_float___::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_float___::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_float___::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCF70
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_char_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_char_const_____::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_char_const_____::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCF80
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_CExit_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_CExit_const_____::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CExit_const_____::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCF90
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_CRoomTemplate_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_CRoomTemplate_const_____::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CRoomTemplate_const_____::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCFA0
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_CRoom_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_CRoom_const_____::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CRoom_const_____::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCFB0
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_CRoomCandidate_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_CRoomCandidate_const_____::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CRoomCandidate_const_____::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCFC0
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_ITilegenRange_CExit_const________::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_ITilegenRange_CExit_const________::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_ITilegenRange_CExit_const________::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCFD0
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_CTilegenState_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenExpression_CTilegenState_const_____::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CTilegenState_const_____::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCFE0
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenAction_::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenAction_::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenAction_::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FCFF0
// Name: _dynamic_initializer_for__CTilegenClassRegistry_ITilegenRange_CExit_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTilegenClassRegistry_ITilegenRange_CExit_const_____::m_FactoryList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenRange_CExit_const_____::m_FactoryList__);
}

//------------------------------------------------------------------------------
// Address: 0x100FDF10
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_bool___::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_bool___::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenExpression<bool>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDF20
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_int___::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_int___::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenExpression<int>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDF30
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_float___::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_float___::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenExpression<float>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDF40
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_char_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_char_const_____::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenExpression<char const *>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDF50
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CExit_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CExit_const_____::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenExpression<CExit const *>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDF60
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CRoomTemplate_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CRoomTemplate_const_____::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDF70
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CRoom_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CRoom_const_____::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDF80
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CRoomCandidate_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CRoomCandidate_const_____::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDF90
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CTilegenState_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_CTilegenState_const_____::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDFA0
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenAction_::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenAction_::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenAction>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDFB0
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenRange_CExit_const_____::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenRange_CExit_const_____::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100FDFC0
// Name: _dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_ITilegenRange_CExit_const________::m_FactoryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTilegenClassRegistry_ITilegenExpression_ITilegenRange_CExit_const________::m_FactoryList__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CTilegenClassRegistry<ITilegenExpression<ITilegenRange<CExit const *> *>>::m_FactoryList);
}

//------------------------------------------------------------------------------
// Address: 0x100131A0
// Name: CreateFromKeyValues_ITilegenExpression_int___
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenExpression<int> *__usercall CreateFromKeyValues_ITilegenExpression_int___@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenExpression<int> *Instance; // eax
  ITilegenExpression<int> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
    return ReadLiteralIntValue(pKeyValues);
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<int>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenExpression<int> *, int))v5->dtr_ITilegenExpression<int>)(a1: v5, a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013230
// Name: bool CreateFromKeyValuesBlock<class ITilegenExpression<bool>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenExpression<bool> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenExpression<bool>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenExpression<bool> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenExpression<bool> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenExpression_bool___(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100132F0
// Name: bool CreateFromKeyValuesBlock<class ITilegenExpression<int>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenExpression<int> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenExpression<int>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenExpression<int> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenExpression<int> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenExpression_int___(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100133B0
// Name: CreateFromKeyValues_ITilegenExpression_char_const_____
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenExpression<char const *> *__usercall CreateFromKeyValues_ITilegenExpression_char_const_____@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenExpression<char const *> *Instance; // eax
  ITilegenExpression<char const *> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
    return ReadLiteralStringValue(pKeyValues);
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<char const *>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenExpression<char const *> *, int))v5->dtr_ITilegenExpression<char const *>)(
        a1: v5,
        a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013440
// Name: CreateFromKeyValues_ITilegenExpression_CRoom_const_____
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenExpression<CRoom const *> *__usercall CreateFromKeyValues_ITilegenExpression_CRoom_const_____@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenExpression<CRoom const *> *Instance; // eax
  ITilegenExpression<CRoom const *> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Tilegen class does not support literal values.\n");
    return nullptr;
  }
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<CRoom const *>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenExpression<CRoom const *> *, int))v5->dtr_ITilegenExpression<CRoom const *>)(
        a1: v5,
        a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
      return nullptr;
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018040
// Name: CreateFromKeyValues_ITilegenExpression_bool___
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenExpression<bool> *__usercall CreateFromKeyValues_ITilegenExpression_bool___@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenExpression<bool> *Instance; // eax
  ITilegenExpression<bool> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
    return ReadLiteralBoolValue(pKeyValues);
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<bool>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenExpression<bool> *, int))v5->dtr_ITilegenExpression<bool>)(a1: v5, a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100180D0
// Name: CreateFromKeyValues_ITilegenExpression_float___
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenExpression<float> *__usercall CreateFromKeyValues_ITilegenExpression_float___@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenExpression<float> *Instance; // eax
  ITilegenExpression<float> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
    return ReadLiteralFloatValue(pKeyValues);
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<float>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenExpression<float> *, int))v5->dtr_ITilegenExpression<float>)(a1: v5, a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018160
// Name: bool CreateFromKeyValuesBlock<class ITilegenExpression<float>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenExpression<float> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenExpression<float>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenExpression<float> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenExpression<float> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenExpression_float___(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018220
// Name: CreateFromKeyValues_ITilegenExpression_CRoomTemplate_const_____
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenExpression<CRoomTemplate const *> *__usercall CreateFromKeyValues_ITilegenExpression_CRoomTemplate_const_____@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenExpression<CRoomTemplate const *> *Instance; // eax
  ITilegenExpression<CRoomTemplate const *> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Tilegen class does not support literal values.\n");
    return nullptr;
  }
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<CRoomTemplate const *>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenExpression<CRoomTemplate const *> *, int))v5->dtr_ITilegenExpression<CRoomTemplate const *>)(
        a1: v5,
        a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
      return nullptr;
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100182E0
// Name: CreateFromKeyValues_ITilegenExpression_CExit_const_____
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenExpression<CExit const *> *__usercall CreateFromKeyValues_ITilegenExpression_CExit_const_____@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenExpression<CExit const *> *Instance; // eax
  ITilegenExpression<CExit const *> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Tilegen class does not support literal values.\n");
    return nullptr;
  }
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<CExit const *>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenExpression<CExit const *> *, int))v5->dtr_ITilegenExpression<CExit const *>)(
        a1: v5,
        a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
      return nullptr;
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100183A0
// Name: CreateFromKeyValues_ITilegenExpression_CRoomCandidate_const_____
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenExpression<CRoomCandidate const *> *__usercall CreateFromKeyValues_ITilegenExpression_CRoomCandidate_const_____@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenExpression<CRoomCandidate const *> *Instance; // eax
  ITilegenExpression<CRoomCandidate const *> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Tilegen class does not support literal values.\n");
    return nullptr;
  }
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<CRoomCandidate const *>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenExpression<CRoomCandidate const *> *, int))v5->dtr_ITilegenExpression<CRoomCandidate const *>)(
        a1: v5,
        a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
      return nullptr;
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018460
// Name: CreateFromKeyValues_ITilegenExpression_CTilegenState_const_____
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenExpression<CTilegenState const *> *__usercall CreateFromKeyValues_ITilegenExpression_CTilegenState_const_____@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenExpression<CTilegenState const *> *Instance; // eax
  ITilegenExpression<CTilegenState const *> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Tilegen class does not support literal values.\n");
    return nullptr;
  }
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<CTilegenState const *>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenExpression<CTilegenState const *> *, int))v5->dtr_ITilegenExpression<CTilegenState const *>)(
        a1: v5,
        a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
      return nullptr;
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018520
// Name: CreateFromKeyValues_ITilegenExpression_ITilegenRange_CExit_const________
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenExpression<ITilegenRange<CExit const *> *> *__usercall CreateFromKeyValues_ITilegenExpression_ITilegenRange_CExit_const________@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenExpression<ITilegenRange<CExit const *> *> *Instance; // eax
  ITilegenExpression<ITilegenRange<CExit const *> *> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Tilegen class does not support literal values.\n");
    return nullptr;
  }
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenExpression<ITilegenRange<CExit const *> *>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenExpression<ITilegenRange<CExit const *> *> *, int))v5->dtr_ITilegenExpression<ITilegenRange<CExit const *> *>)(
        a1: v5,
        a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
      return nullptr;
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100185E0
// Name: CreateFromKeyValues_ITilegenRange_CExit_const_____
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITilegenRange<CExit const *> *__usercall CreateFromKeyValues_ITilegenRange_CExit_const_____@<eax>(
        KeyValues *pKeyValues@<edi>,
        bool bCreateEmptyInstance)
{
  const char *String; // eax
  ITilegenRange<CExit const *> *Instance; // eax
  ITilegenRange<CExit const *> *v5; // esi

  if ( KeyValues::GetFirstSubKey(this: pKeyValues) == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Tilegen class does not support literal values.\n");
    return nullptr;
  }
  String = KeyValues::GetString(this: pKeyValues, keyName: "class", defaultValue: nullptr);
  if ( String != nullptr )
  {
    Instance = CTilegenClassRegistry<ITilegenRange<CExit const *>>::CreateInstance(pClassName: String);
    v5 = Instance;
    if ( Instance != nullptr && !bCreateEmptyInstance && !Instance->LoadFromKeyValues(this: Instance, a2: pKeyValues) )
    {
      ((void (__thiscall *)(ITilegenRange<CExit const *> *, int))v5->dtr_ITilegenRange<CExit const *>)(a1: v5, a2: 1);
      return nullptr;
    }
    return v5;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
      return nullptr;
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "No class name specified for class instantiation in key values.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018AC0
// Name: bool CreateFromKeyValuesBlock<class ITilegenExpression<class CRoomTemplate const __near *>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenExpression<class CRoomTemplate const __near *> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenExpression<CRoomTemplate const *>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenExpression<CRoomTemplate const *> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenExpression<CRoomTemplate const *> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenExpression_CRoomTemplate_const_____(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018B80
// Name: bool CreateFromKeyValuesBlock<class ITilegenExpression<class CExit const __near *>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenExpression<class CExit const __near *> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenExpression<CExit const *>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenExpression<CExit const *> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenExpression<CExit const *> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenExpression_CExit_const_____(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018C40
// Name: bool CreateFromKeyValuesBlock<class ITilegenExpression<class CRoomCandidate const __near *>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenExpression<class CRoomCandidate const __near *> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenExpression<CRoomCandidate const *>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenExpression<CRoomCandidate const *> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenExpression<CRoomCandidate const *> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenExpression_CRoomCandidate_const_____(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018D00
// Name: bool CreateFromKeyValuesBlock<class ITilegenExpression<class CTilegenState const __near *>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenExpression<class CTilegenState const __near *> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenExpression<CTilegenState const *>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenExpression<CTilegenState const *> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenExpression<CTilegenState const *> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenExpression_CTilegenState_const_____(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018DC0
// Name: bool CreateFromKeyValuesBlock<class ITilegenExpression<class ITilegenRange<class CExit const __near *> __near *>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenExpression<class ITilegenRange<class CExit const __near *> __near *> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenExpression<ITilegenRange<CExit const *> *>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenExpression<ITilegenRange<CExit const *> *> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenExpression<ITilegenRange<CExit const *> *> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenExpression_ITilegenRange_CExit_const________(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018E80
// Name: bool CreateFromKeyValuesBlock<class ITilegenRange<class CExit const __near *>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenRange<class CExit const __near *> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenRange<CExit const *>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenRange<CExit const *> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenRange<CExit const *> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenRange_CExit_const_____(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}
