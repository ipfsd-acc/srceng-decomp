// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_math.cpp
// Functions: 194
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_math.h"

//------------------------------------------------------------------------------
// Address: 0x10047990
// Name: public: virtual void CSosOperatorSourceDistance::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceDistance::ParseKV(
        CSosOperatorDelta *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // edi
  const char *Name; // esi
  const char *String; // eax

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0
      && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100480D0
// Name: public: virtual unsigned int CSosOperatorFloat::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorFloat::GetSize(CSosOperatorEntryTime *this)
{
  return 36;
}

//------------------------------------------------------------------------------
// Address: 0x10048940
// Name: enum SOFunc1Type_t S_GetFunc1Type(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SOFunc1Type_t __cdecl S_GetFunc1Type(const char *pValueString)
{
  SOFunc1Type_t result; // eax

  result = V_strcasecmp(s1: pValueString, s2: "none");
  if ( result != SO_FUNC1_NONE )
  {
    if ( V_strcasecmp(s1: pValueString, s2: "sin") != 0 )
    {
      if ( V_strcasecmp(s1: pValueString, s2: "asin") != 0 )
      {
        if ( V_strcasecmp(s1: pValueString, s2: "cos") != 0 )
        {
          if ( V_strcasecmp(s1: pValueString, s2: "acos") != 0 )
          {
            if ( V_strcasecmp(s1: pValueString, s2: "tan") != 0 )
            {
              if ( V_strcasecmp(s1: pValueString, s2: "atan") != 0 )
              {
                if ( V_strcasecmp(s1: pValueString, s2: "sinh") != 0 )
                {
                  if ( V_strcasecmp(s1: pValueString, s2: "asinh") != 0 )
                  {
                    if ( V_strcasecmp(s1: pValueString, s2: "cosh") != 0 )
                    {
                      if ( V_strcasecmp(s1: pValueString, s2: "acosh") != 0 )
                      {
                        if ( V_strcasecmp(s1: pValueString, s2: "tanh") != 0 )
                        {
                          if ( V_strcasecmp(s1: pValueString, s2: "atanh") != 0 )
                          {
                            if ( V_strcasecmp(s1: pValueString, s2: "exp") != 0 )
                            {
                              if ( V_strcasecmp(s1: pValueString, s2: "expm1") != 0 )
                              {
                                if ( V_strcasecmp(s1: pValueString, s2: "exp2") != 0 )
                                {
                                  if ( V_strcasecmp(s1: pValueString, s2: "log") != 0 )
                                  {
                                    if ( V_strcasecmp(s1: pValueString, s2: "log2") != 0 )
                                    {
                                      if ( V_strcasecmp(s1: pValueString, s2: "log1p") != 0 )
                                      {
                                        if ( V_strcasecmp(s1: pValueString, s2: "log10") != 0 )
                                        {
                                          if ( V_strcasecmp(s1: pValueString, s2: "logb") != 0 )
                                          {
                                            if ( V_strcasecmp(s1: pValueString, s2: "fabs") != 0 )
                                            {
                                              if ( V_strcasecmp(s1: pValueString, s2: "sqrt") != 0 )
                                              {
                                                if ( V_strcasecmp(s1: pValueString, s2: "erf") != 0 )
                                                {
                                                  if ( V_strcasecmp(s1: pValueString, s2: "erfc") != 0 )
                                                  {
                                                    if ( V_strcasecmp(s1: pValueString, s2: "gamma") != 0 )
                                                    {
                                                      if ( V_strcasecmp(s1: pValueString, s2: "lgamma") != 0 )
                                                      {
                                                        if ( V_strcasecmp(s1: pValueString, s2: "ceil") != 0 )
                                                        {
                                                          if ( V_strcasecmp(s1: pValueString, s2: "floor") != 0 )
                                                          {
                                                            if ( V_strcasecmp(s1: pValueString, s2: "rint") != 0 )
                                                            {
                                                              if ( V_strcasecmp(s1: pValueString, s2: "nearbyint") != 0 )
                                                              {
                                                                if ( V_strcasecmp(s1: pValueString, s2: "rintol") != 0 )
                                                                {
                                                                  if ( V_strcasecmp(s1: pValueString, s2: "round") != 0 )
                                                                  {
                                                                    if ( V_strcasecmp(s1: pValueString, s2: "roundtol") != 0 )
                                                                      return V_strcasecmp(s1: pValueString, s2: "trunc") != 0
                                                                           ? 0
                                                                           : 34;
                                                                    else
                                                                      return SO_FUNC1_ROUNDTOL;
                                                                  }
                                                                  else
                                                                  {
                                                                    return SO_FUNC1_ROUND;
                                                                  }
                                                                }
                                                                else
                                                                {
                                                                  return SO_FUNC1_RINTOL;
                                                                }
                                                              }
                                                              else
                                                              {
                                                                return SO_FUNC1_NEARBYINT;
                                                              }
                                                            }
                                                            else
                                                            {
                                                              return SO_FUNC1_RINT;
                                                            }
                                                          }
                                                          else
                                                          {
                                                            return SO_FUNC1_FLOOR;
                                                          }
                                                        }
                                                        else
                                                        {
                                                          return SO_FUNC1_CEIL;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        return SO_FUNC1_LGAMMA;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      return SO_FUNC1_GAMMA;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    return SO_FUNC1_ERFC;
                                                  }
                                                }
                                                else
                                                {
                                                  return SO_FUNC1_ERF;
                                                }
                                              }
                                              else
                                              {
                                                return SO_FUNC1_SQRT;
                                              }
                                            }
                                            else
                                            {
                                              return SO_FUNC1_FABS;
                                            }
                                          }
                                          else
                                          {
                                            return SO_FUNC1_LOGB;
                                          }
                                        }
                                        else
                                        {
                                          return SO_FUNC1_LOG10;
                                        }
                                      }
                                      else
                                      {
                                        return SO_FUNC1_LOG1P;
                                      }
                                    }
                                    else
                                    {
                                      return SO_FUNC1_LOG2;
                                    }
                                  }
                                  else
                                  {
                                    return SO_FUNC1_LOG;
                                  }
                                }
                                else
                                {
                                  return SO_FUNC1_EXP2;
                                }
                              }
                              else
                              {
                                return SO_FUNC1_EXPM1;
                              }
                            }
                            else
                            {
                              return SO_FUNC1_EXP;
                            }
                          }
                          else
                          {
                            return SO_FUNC1_ATANH;
                          }
                        }
                        else
                        {
                          return SO_FUNC1_TANH;
                        }
                      }
                      else
                      {
                        return SO_FUNC1_ACOSH;
                      }
                    }
                    else
                    {
                      return SO_FUNC1_COSH;
                    }
                  }
                  else
                  {
                    return SO_FUNC1_ASINH;
                  }
                }
                else
                {
                  return SO_FUNC1_SINH;
                }
              }
              else
              {
                return SO_FUNC1_ATAN;
              }
            }
            else
            {
              return SO_FUNC1_TAN;
            }
          }
          else
          {
            return SO_FUNC1_ACOS;
          }
        }
        else
        {
          return SO_FUNC1_COS;
        }
      }
      else
      {
        return SO_FUNC1_ASIN;
      }
    }
    else
    {
      return SO_FUNC1_SIN;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048CE0
// Name: void S_PrintFunc1Type(enum SOFunc1Type_t,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_PrintFunc1Type(SOFunc1Type_t nType, int nLevel)
{
  const char *v2; // esi

  switch ( nType )
  {
    case SO_FUNC1_SIN:
      v2 = "sin";
      break;
    case SO_FUNC1_ASIN:
      v2 = "asin";
      break;
    case SO_FUNC1_COS:
      v2 = "cos";
      break;
    case SO_FUNC1_ACOS:
      v2 = "acos";
      break;
    case SO_FUNC1_TAN:
      v2 = "tan";
      break;
    case SO_FUNC1_ATAN:
      v2 = "atan";
      break;
    case SO_FUNC1_SINH:
      v2 = "sinh";
      break;
    case SO_FUNC1_ASINH:
      v2 = "asinh";
      break;
    case SO_FUNC1_COSH:
      v2 = "cosh";
      break;
    case SO_FUNC1_ACOSH:
      v2 = "acosh";
      break;
    case SO_FUNC1_TANH:
      v2 = "tanh";
      break;
    case SO_FUNC1_ATANH:
      v2 = "atanh";
      break;
    case SO_FUNC1_EXP:
      v2 = "exp";
      break;
    case SO_FUNC1_EXPM1:
      v2 = "expm1";
      break;
    case SO_FUNC1_EXP2:
      v2 = "exp2";
      break;
    case SO_FUNC1_LOG:
      v2 = "log";
      break;
    case SO_FUNC1_LOG2:
      v2 = "log2";
      break;
    case SO_FUNC1_LOG1P:
      v2 = "log1p";
      break;
    case SO_FUNC1_LOG10:
      v2 = "log10";
      break;
    case SO_FUNC1_LOGB:
      v2 = "logb";
      break;
    case SO_FUNC1_FABS:
      v2 = "fabs";
      break;
    case SO_FUNC1_SQRT:
      v2 = "sqrt";
      break;
    case SO_FUNC1_ERF:
      v2 = "erf";
      break;
    case SO_FUNC1_ERFC:
      v2 = "erfc";
      break;
    case SO_FUNC1_GAMMA:
      v2 = "gamma";
      break;
    case SO_FUNC1_LGAMMA:
      v2 = "lgamma";
      break;
    case SO_FUNC1_CEIL:
      v2 = "ceil";
      break;
    case SO_FUNC1_FLOOR:
      v2 = "floor";
      break;
    case SO_FUNC1_RINT:
      v2 = "rint";
      break;
    case SO_FUNC1_NEARBYINT:
      v2 = "nearbyint";
      break;
    case SO_FUNC1_RINTOL:
      v2 = "rintol";
      break;
    case SO_FUNC1_ROUND:
      v2 = "round";
      break;
    case SO_FUNC1_ROUNDTOL:
      v2 = "roundtol";
      break;
    case SO_FUNC1_TRUNC:
      v2 = "trunc";
      break;
    default:
      v2 = "none";
      break;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*sFunction: %s\n",
      nLevel,
      "    ",
      v2);
}

//------------------------------------------------------------------------------
// Address: 0x10048EF0
// Name: enum SOOpType_t S_GetExpressionType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SOOpType_t __cdecl S_GetExpressionType(const char *pValueString)
{
  SOOpType_t result; // eax

  result = V_strcasecmp(s1: pValueString, s2: "none");
  if ( result != SO_OP_NONE )
  {
    if ( V_strcasecmp(s1: pValueString, s2: "set") != 0 )
    {
      if ( V_strcasecmp(s1: pValueString, s2: "add") != 0 )
      {
        if ( V_strcasecmp(s1: pValueString, s2: "sub") != 0 )
        {
          if ( V_strcasecmp(s1: pValueString, s2: "mult") != 0 )
          {
            if ( V_strcasecmp(s1: pValueString, s2: "div") != 0 )
            {
              if ( V_strcasecmp(s1: pValueString, s2: "mod") != 0 )
              {
                if ( V_strcasecmp(s1: pValueString, s2: "max") != 0 )
                {
                  if ( V_strcasecmp(s1: pValueString, s2: "min") != 0 )
                  {
                    if ( V_strcasecmp(s1: pValueString, s2: "invert") != 0 )
                    {
                      if ( V_strcasecmp(s1: pValueString, s2: "greater_than") != 0 )
                      {
                        if ( V_strcasecmp(s1: pValueString, s2: "less_than") != 0 )
                        {
                          if ( V_strcasecmp(s1: pValueString, s2: "greater_than_or_equal") != 0 )
                          {
                            if ( V_strcasecmp(s1: pValueString, s2: "less_than_or_equal") != 0 )
                            {
                              if ( V_strcasecmp(s1: pValueString, s2: "equals") != 0 )
                                return V_strcasecmp(s1: pValueString, s2: "invert_scale") != 0 ? 0 : 15;
                              else
                                return SO_OP_EQ;
                            }
                            else
                            {
                              return SO_OP_LTOE;
                            }
                          }
                          else
                          {
                            return SO_OP_GTOE;
                          }
                        }
                        else
                        {
                          return SO_OP_LT;
                        }
                      }
                      else
                      {
                        return SO_OP_GT;
                      }
                    }
                    else
                    {
                      return SO_OP_INV;
                    }
                  }
                  else
                  {
                    return SO_OP_MIN;
                  }
                }
                else
                {
                  return SO_OP_MAX;
                }
              }
              else
              {
                return SO_OP_MOD;
              }
            }
            else
            {
              return SO_OP_DIV;
            }
          }
          else
          {
            return SO_OP_MULT;
          }
        }
        else
        {
          return SO_OP_SUB;
        }
      }
      else
      {
        return SO_OP_ADD;
      }
    }
    else
    {
      return SO_OP_SET;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100490A0
// Name: void S_PrintOpType(enum SOOpType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_PrintOpType(SOOpType_t nType, int nLevel)
{
  const char *v2; // esi

  switch ( nType )
  {
    case SO_OP_SET:
      v2 = "set";
      break;
    case SO_OP_ADD:
      v2 = "add";
      break;
    case SO_OP_SUB:
      v2 = "sub";
      break;
    case SO_OP_MULT:
      v2 = "mult";
      break;
    case SO_OP_DIV:
      v2 = "div";
      break;
    case SO_OP_MAX:
      v2 = "max";
      break;
    case SO_OP_MIN:
      v2 = "min";
      break;
    case SO_OP_INV:
      v2 = "invert";
      break;
    case SO_OP_GT:
      v2 = "greater_than";
      break;
    case SO_OP_LT:
      v2 = "less_than";
      break;
    case SO_OP_GTOE:
      v2 = "greater_than_or_equal";
      break;
    case SO_OP_LTOE:
      v2 = "less_than_or_equal";
      break;
    case SO_OP_EQ:
      v2 = "equals";
      break;
    case SO_OP_INV_SCALE:
      v2 = "invert_scale";
      break;
    default:
      v2 = "none";
      break;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*sOperation: %s\n",
      nLevel,
      "    ",
      v2);
}

//------------------------------------------------------------------------------
// Address: 0x100491A0
// Name: public: virtual void CSosOperatorFunc1::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFunc1::SetDefaults(CSosOperatorFunc1 *this, _DWORD *pVoidMem)
{
  pVoidMem[5] = 0;
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[6] = 0;
  *((_BYTE *)pVoidMem + 28) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100491D0
// Name: public: virtual void CSosOperatorFunc1::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFunc1::Print(
        CSosOperatorFunc1 *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *v5; // eax

  CSosOperator::PrintBaseParams(this, (CSosOperator_t *)pVoidMem, pStack, nOpIndex, nLevel);
  S_PrintFunc1Type(nType: *((SOFunc1Type_t *)pVoidMem + 6), nLevel);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v5 = "true";
    if ( *((_BYTE *)pVoidMem + 28) == 0 )
      v5 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*snormalize_trig: %s\n",
      nLevel,
      "    ",
      v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049250
// Name: public: virtual void CSosOperatorFunc1::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFunc1::ParseKV(
        CSosOperatorFunc1 *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "function") != 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "normalize_trig") != 0 )
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
        }
        else
        {
          LOBYTE(pVoidMem[2].m_flExecuteOffset[0]) = V_strcasecmp(s1: v7, s2: "true") == 0;
        }
      }
      else
      {
        LODWORD(pVoidMem[2].m_flExecute[0]) = S_GetFunc1Type(pValueString: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049360
// Name: public: virtual void CSosOperatorFloat::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFloat::SetDefaults(CSosOperatorFloat *this, _DWORD *pVoidMem)
{
  pVoidMem[7] = 0;
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[5] = 0;
  pVoidMem[6] = -1;
  pVoidMem[8] = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10049390
// Name: float ceil(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ceil(float _X)
{
  return ceil(X: _X);
}

//------------------------------------------------------------------------------
// Address: 0x100493B0
// Name: public: virtual void CSosOperatorFloat::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFloat::Print(
        CSosOperatorFloat *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, (CSosOperator_t *)pVoidMem, pStack, nOpIndex, nLevel);
  S_PrintOpType(nType: *((SOOpType_t *)pVoidMem + 8), nLevel);
}

//------------------------------------------------------------------------------
// Address: 0x100493E0
// Name: public: virtual void CSosOperatorFloat::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFloat::ParseKV(
        CSosOperatorFloat *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "apply") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        *(_DWORD *)&pVoidMem[2].m_bExecuteOnce = S_GetExpressionType(pValueString: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100494B0
// Name: public: virtual void CSosOperatorVec3::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorVec3::SetDefaults(CSosOperatorVec3 *this, _DWORD *pVoidMem)
{
  pVoidMem[15] = 0;
  pVoidMem[16] = 0;
  pVoidMem[17] = 0;
  pVoidMem[3] = 0;
  pVoidMem[6] = -1;
  pVoidMem[4] = 0;
  pVoidMem[7] = -1;
  pVoidMem[5] = 0;
  pVoidMem[8] = -1;
  pVoidMem[9] = 0;
  pVoidMem[12] = -1;
  pVoidMem[10] = 0;
  pVoidMem[13] = -1;
  pVoidMem[11] = 0;
  pVoidMem[14] = -1;
  pVoidMem[18] = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10049510
// Name: public: virtual void CSosOperatorVec3::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorVec3::Print(
        CSosOperatorVec3 *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, (CSosOperator_t *)pVoidMem, pStack, nOpIndex, nLevel);
  S_PrintOpType(nType: *((SOOpType_t *)pVoidMem + 18), nLevel);
}

//------------------------------------------------------------------------------
// Address: 0x10049540
// Name: public: virtual void CSosOperatorVec3::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorVec3::ParseKV(
        CSosOperatorVec3 *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "apply") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        LODWORD(pVoidMem[6].m_flExecute[0]) = S_GetExpressionType(pValueString: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049610
// Name: public: virtual void CSosOperatorSpeakers::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpeakers::SetDefaults(CSosOperatorSpeakers *this, _DWORD *pVoidMem)
{
  pVoidMem[27] = 0;
  pVoidMem[28] = 0;
  pVoidMem[29] = 0;
  pVoidMem[30] = 0;
  pVoidMem[31] = 0;
  pVoidMem[32] = 0;
  pVoidMem[3] = 0;
  pVoidMem[9] = -1;
  pVoidMem[4] = 0;
  pVoidMem[10] = -1;
  pVoidMem[5] = 0;
  pVoidMem[11] = -1;
  pVoidMem[6] = 0;
  pVoidMem[12] = -1;
  pVoidMem[7] = 0;
  pVoidMem[13] = -1;
  pVoidMem[8] = 0;
  pVoidMem[14] = -1;
  pVoidMem[15] = 0;
  pVoidMem[21] = -1;
  pVoidMem[16] = 0;
  pVoidMem[22] = -1;
  pVoidMem[17] = 0;
  pVoidMem[23] = -1;
  pVoidMem[18] = 0;
  pVoidMem[24] = -1;
  pVoidMem[19] = 0;
  pVoidMem[25] = -1;
  pVoidMem[20] = 0;
  pVoidMem[26] = -1;
  pVoidMem[33] = 4;
}

//------------------------------------------------------------------------------
// Address: 0x100496B0
// Name: public: virtual void CSosOperatorSpeakers::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpeakers::Print(
        CSosOperatorSpeakers *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, (CSosOperator_t *)pVoidMem, pStack, nOpIndex, nLevel);
  S_PrintOpType(nType: *((SOOpType_t *)pVoidMem + 33), nLevel);
}

//------------------------------------------------------------------------------
// Address: 0x100496E0
// Name: public: virtual void CSosOperatorSpeakers::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpeakers::ParseKV(
        CSosOperatorSpeakers *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  interval_t v8; // [esp+4h] [ebp-34h] BYREF
  interval_t v9; // [esp+Ch] [ebp-2Ch] BYREF
  interval_t v10; // [esp+14h] [ebp-24h] BYREF
  interval_t v11; // [esp+1Ch] [ebp-1Ch] BYREF
  interval_t v12; // [esp+24h] [ebp-14h] BYREF
  interval_t interval; // [esp+2Ch] [ebp-Ch] BYREF
  CSosOperator *v14; // [esp+34h] [ebp-4h]
  KeyValues *pParams; // [esp+48h] [ebp+10h]

  v14 = this;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pOpKeys);
  pParams = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
      v7 = String;
      if ( Name != nullptr
        && *Name != 0
        && String != nullptr
        && *String != 0
        && CSosOperator::BaseParseKV(this: v14, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "apply") != 0 )
        {
          if ( V_strcasecmp(s1: Name, s2: "left_front") != 0 )
          {
            if ( V_strcasecmp(s1: Name, s2: "right_front") != 0 )
            {
              if ( V_strcasecmp(s1: Name, s2: "left_rear") != 0 )
              {
                if ( V_strcasecmp(s1: Name, s2: "right_rear") != 0 )
                {
                  if ( V_strcasecmp(s1: Name, s2: "center") != 0 )
                  {
                    if ( V_strcasecmp(s1: Name, s2: "lfe") != 0 )
                    {
                      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
                        _LoggingSystem_Log(
                          a1: LOG_SND_OPERATORS,
                          a2: 1,
                          a3: "Error: Unknown sound operator attribute %s\n",
                          Name);
                    }
                    else
                    {
                      v8 = ReadInterval(pString: v7);
                      *(float *)&pVoidMem[2].m_bExecuteOnce = RandomInterval(interval: &v8);
                    }
                  }
                  else
                  {
                    v9 = ReadInterval(pString: v7);
                    *(float *)pVoidMem[2].m_flExecuteOffset = RandomInterval(interval: &v9);
                  }
                }
                else
                {
                  v10 = ReadInterval(pString: v7);
                  pVoidMem[2].m_flExecute[0] = RandomInterval(interval: &v10);
                }
              }
              else
              {
                v11 = ReadInterval(pString: v7);
                *(float *)&pVoidMem[1].m_bExecuteOnce = RandomInterval(interval: &v11);
              }
            }
            else
            {
              v12 = ReadInterval(pString: v7);
              *(float *)pVoidMem[1].m_flExecuteOffset = RandomInterval(interval: &v12);
            }
          }
          else
          {
            interval = ReadInterval(pString: v7);
            pVoidMem[1].m_flExecute[0] = RandomInterval(&interval);
          }
        }
        else
        {
          LODWORD(pVoidMem[11].m_flExecute[0]) = S_GetExpressionType(pValueString: v7);
        }
      }
      pParams = KeyValues::GetNextKey(this: pParams);
      if ( pParams == nullptr )
        break;
      FirstSubKey = pParams;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049900
// Name: public: virtual void CSosOperatorSourceDistance::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceDistance::SetDefaults(CSosOperatorSourceDistance *this, _DWORD *pVoidMem)
{
  pVoidMem[9] = 1065353216;
  pVoidMem[3] = 0;
  pVoidMem[6] = -1;
  pVoidMem[4] = 0;
  pVoidMem[7] = -1;
  pVoidMem[5] = 0;
  pVoidMem[8] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10049950
// Name: public: virtual void CSosOperatorFacing::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFacing::SetDefaults(CSosOperatorFacing *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[6] = -1;
  pVoidMem[4] = 0;
  pVoidMem[7] = -1;
  pVoidMem[5] = 0;
  pVoidMem[8] = -1;
  pVoidMem[9] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049980
// Name: public: virtual void CSosOperatorRemapValue::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorRemapValue::SetDefaults(CSosOperatorRemapValue *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[5] = 1036831949;
  pVoidMem[6] = -1;
  pVoidMem[7] = 0;
  pVoidMem[8] = -1;
  pVoidMem[9] = 1065353216;
  pVoidMem[10] = -1;
  pVoidMem[11] = 0;
  pVoidMem[12] = -1;
  pVoidMem[13] = 0;
  *((_WORD *)pVoidMem + 28) = 257;
}

//------------------------------------------------------------------------------
// Address: 0x100499E0
// Name: public: virtual void CSosOperatorRemapValue::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorRemapValue::ParseKV(
        CSosOperatorRemapValue *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "clamp_range") != 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "default_to_max") != 0 )
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
        }
        else if ( V_strcasecmp(s1: v7, s2: "false") == 0 )
        {
          pVoidMem[4].m_bHasExecuted = false;
        }
      }
      else if ( V_strcasecmp(s1: v7, s2: "false") == 0 )
      {
        pVoidMem[4].m_bExecuteOnce = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049B00
// Name: public: virtual void CSosOperatorRandom::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorRandom::SetDefaults(CSosOperatorRandom *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[5] = 1065353216;
  pVoidMem[6] = -1;
  pVoidMem[7] = 1065353216;
}

//------------------------------------------------------------------------------
// Address: 0x10049B30
// Name: float RemapVal(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapVal(float val, float A, float B, float C, float D)
{
  if ( A != B )
    return C + (D - C) * (val - A) / (B - A);
  if ( (float)(val - B) < 0.0 )
    return C;
  return D;
}

//------------------------------------------------------------------------------
// Address: 0x10049BA0
// Name: public: virtual void CSosOperatorFunc1::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFunc1::Execute(
        CSosOperatorFunc1 *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        void *nOpIndex)
{
  double v7; // st7
  long double v8; // st7
  long double v9; // rt0
  float v10; // xmm0_4
  float v11; // [esp+10h] [ebp-4h]

  v11 = 0.0;
  switch ( *((_DWORD *)pVoidMem + 6) )
  {
    case 1:
      v7 = sin(pVoidMem[3]);
      goto LABEL_18;
    case 2:
      v7 = asin(pVoidMem[3]);
      goto LABEL_18;
    case 3:
      v7 = cos(pVoidMem[3]);
      goto LABEL_18;
    case 4:
      v7 = acos(pVoidMem[3]);
      goto LABEL_18;
    case 5:
      v7 = tan(pVoidMem[3]);
      goto LABEL_18;
    case 6:
      v7 = atan2(pVoidMem[3], 1.0);
      goto LABEL_18;
    case 7:
      v7 = sinh(pVoidMem[3]);
      goto LABEL_18;
    case 9:
      v7 = cosh(pVoidMem[3]);
      goto LABEL_18;
    case 0xB:
      v7 = tanh(pVoidMem[3]);
      goto LABEL_18;
    case 0xD:
      v8 = pVoidMem[3] * 1.442695040888963407;
      v9 = rint(v8);
      v7 = __FSCALE__(__F2XM1__(v8 - v9) + 1.0, v9);
      goto LABEL_18;
    case 0x10:
      v7 = __FYL2X__(pVoidMem[3], 0.6931471805599453094);
      goto LABEL_18;
    case 0x13:
      v7 = __FYL2X__(pVoidMem[3], 0.3010299956639811952);
      goto LABEL_18;
    case 0x15:
      v7 = fabs(pVoidMem[3]);
      goto LABEL_18;
    case 0x16:
      v7 = sqrt(pVoidMem[3]);
      goto LABEL_18;
    case 0x1B:
      v7 = ceil(_X: pVoidMem[3]);
      goto LABEL_18;
    case 0x1C:
      v7 = floor(X: pVoidMem[3]);
LABEL_18:
      v11 = v7;
      break;
    default:
      break;
  }
  v10 = v11;
  if ( *((_BYTE *)pVoidMem + 28) != 0 )
    v10 = (float)(v11 + 1.0) * 0.5;
  pVoidMem[5] = v10;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: (int)nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049D40
// Name: public: virtual void CSosOperatorFloat::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFloat::Execute(
        CSosOperatorFloat *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v6; // xmm0_4
  float v8; // xmm1_4
  float flResult; // [esp+8h] [ebp+8h]
  float flResulta; // [esp+8h] [ebp+8h]

  v6 = 0.0;
  switch ( *((_DWORD *)pVoidMem + 8) )
  {
    case 1:
      v6 = pVoidMem[3];
      break;
    case 2:
      v6 = pVoidMem[5] + pVoidMem[3];
      break;
    case 3:
      v6 = pVoidMem[3] - pVoidMem[5];
      break;
    case 4:
      v6 = pVoidMem[5] * pVoidMem[3];
      break;
    case 5:
      v8 = pVoidMem[5];
      if ( v8 > 0.0 )
        v6 = pVoidMem[3] / v8;
      break;
    case 6:
      flResult = pVoidMem[5];
      if ( flResult > 0.0 )
      {
        flResulta = fmod(pVoidMem[3], flResult);
        v6 = flResulta;
      }
      break;
    case 7:
      v6 = pVoidMem[3];
      if ( v6 <= pVoidMem[5] )
        v6 = pVoidMem[5];
      break;
    case 8:
      v6 = pVoidMem[3];
      if ( pVoidMem[5] <= v6 )
        v6 = pVoidMem[5];
      break;
    case 9:
      v6 = 1.0 - pVoidMem[3];
      break;
    case 0xA:
      if ( pVoidMem[3] <= pVoidMem[5] )
        goto LABEL_17;
      v6 = 1.0;
      break;
    case 0xB:
      if ( pVoidMem[5] <= pVoidMem[3] )
        goto LABEL_17;
      v6 = 1.0;
      break;
    case 0xC:
      if ( pVoidMem[3] < pVoidMem[5] )
        goto LABEL_17;
      v6 = 1.0;
      break;
    case 0xD:
      if ( pVoidMem[5] < pVoidMem[3] )
        goto LABEL_17;
      v6 = 1.0;
      break;
    case 0xE:
      if ( pVoidMem[3] == pVoidMem[5] )
        v6 = 1.0;
      else
LABEL_17:
        v6 = 0.0;
      break;
    case 0xF:
      v6 = 1.0 - (float)((float)(1.0 - pVoidMem[3]) * pVoidMem[5]);
      break;
    default:
      break;
  }
  pVoidMem[7] = v6;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049F30
// Name: public: virtual void CSosOperatorVec3::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorVec3::Execute(
        CSosOperatorVec3 *this,
        float *pVoidMem,
        channel_t *pChannel,
        channel_t *pScratchPad,
        CScratchPad *pStack,
        CSosOperatorStack *nOpIndex)
{
  double v6; // st7
  double v7; // st6
  float *v8; // esi
  int i; // ebx
  float v10; // xmm0_4

  v6 = 1.0;
  v7 = 0.0;
  v8 = pVoidMem + 9;
  for ( i = 3; i != 0; --i )
  {
    switch ( *((_DWORD *)pVoidMem + 18) )
    {
      case 1:
        v8[6] = *(v8 - 6);
        break;
      case 2:
        v8[6] = *(v8 - 6) + *v8;
        break;
      case 3:
        v8[6] = *(v8 - 6) - *v8;
        break;
      case 4:
        v8[6] = *(v8 - 6) * *v8;
        break;
      case 5:
        if ( *v8 > 0.0 )
          v8[6] = *(v8 - 6) / *v8;
        break;
      case 6:
        if ( *v8 > 0.0 )
        {
          v8[6] = fmod(*(v8 - 6), *v8);
          v7 = 0.0;
          v6 = 1.0;
        }
        break;
      case 7:
        v10 = *(v8 - 6);
        if ( v10 <= *v8 )
          v10 = *v8;
        goto LABEL_18;
      case 8:
        v10 = *(v8 - 6);
        if ( *v8 > v10 )
LABEL_18:
          v8[6] = v10;
        else
          v8[6] = *v8;
        break;
      case 9:
        v8[6] = 1.0 - *(v8 - 6);
        break;
      case 0xA:
        if ( *(v8 - 6) <= *v8 )
          goto LABEL_24;
        v8[6] = v6;
        break;
      case 0xB:
        if ( *v8 <= *(v8 - 6) )
          goto LABEL_24;
        v8[6] = v6;
        break;
      case 0xC:
        if ( *(v8 - 6) < *v8 )
          goto LABEL_24;
        v8[6] = v6;
        break;
      case 0xD:
        if ( *v8 < *(v8 - 6) )
          goto LABEL_24;
        v8[6] = v6;
        break;
      case 0xE:
        if ( *(v8 - 6) == *v8 )
          v8[6] = v6;
        else
LABEL_24:
          v8[6] = v7;
        break;
      default:
        break;
    }
    ++v8;
  }
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: (CSosOperatorStack *)pStack, a4: (int)nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A110
// Name: public: virtual void CSosOperatorSpeakers::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpeakers::Execute(
        CSosOperatorSpeakers *this,
        float *pVoidMem,
        channel_t *pChannel,
        channel_t *pScratchPad,
        CScratchPad *pStack,
        CSosOperatorStack *nOpIndex)
{
  double v6; // st7
  double v7; // st6
  float *v8; // esi
  int i; // ebx
  float v10; // xmm0_4

  v6 = 1.0;
  v7 = 0.0;
  v8 = pVoidMem + 15;
  for ( i = 6; i != 0; --i )
  {
    switch ( *((_DWORD *)pVoidMem + 33) )
    {
      case 1:
        v8[12] = *(v8 - 12);
        break;
      case 2:
        v8[12] = *(v8 - 12) + *v8;
        break;
      case 3:
        v8[12] = *(v8 - 12) - *v8;
        break;
      case 4:
        v8[12] = *(v8 - 12) * *v8;
        break;
      case 5:
        if ( *v8 > 0.0 )
          v8[12] = *(v8 - 12) / *v8;
        break;
      case 6:
        if ( *v8 > 0.0 )
        {
          v8[12] = fmod(*(v8 - 12), *v8);
          v7 = 0.0;
          v6 = 1.0;
        }
        break;
      case 7:
        v10 = *(v8 - 12);
        if ( v10 <= *v8 )
          v10 = *v8;
        goto LABEL_18;
      case 8:
        v10 = pVoidMem[4];
        if ( *v8 > v10 )
LABEL_18:
          v8[12] = v10;
        else
          v8[12] = *v8;
        break;
      case 9:
        v8[12] = 1.0 - *(v8 - 12);
        break;
      case 0xA:
        if ( *(v8 - 12) <= *v8 )
          goto LABEL_24;
        v8[12] = v6;
        break;
      case 0xB:
        if ( *v8 <= *(v8 - 12) )
          goto LABEL_24;
        v8[12] = v6;
        break;
      case 0xC:
        if ( *(v8 - 12) < *v8 )
          goto LABEL_24;
        v8[12] = v6;
        break;
      case 0xD:
        if ( *v8 < *(v8 - 12) )
          goto LABEL_24;
        v8[12] = v6;
        break;
      case 0xE:
        if ( *(v8 - 12) == *v8 )
          v8[12] = v6;
        else
LABEL_24:
          v8[12] = v7;
        break;
      default:
        break;
    }
    ++v8;
  }
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: (CSosOperatorStack *)pStack, a4: (int)nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A2F0
// Name: public: virtual void CSosOperatorSourceDistance::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSosOperatorSourceDistance::Execute(
        CSosOperatorSourceDistance *this@<ecx>,
        int a2@<ebp>,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  bool v7; // zf
  int v8; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  __int128 v14; // xmm0
  __int128 v15; // [esp-10h] [ebp-2Ch] BYREF
  int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  void *v18; // [esp+14h] [ebp-8h]
  void *retaddr; // [esp+1Ch] [ebp+0h]

  v17 = a2;
  v18 = retaddr;
  v7 = !pScratchPad->m_bIsPlayerSound;
  v8 = 2139095039;
  v16 = 2139095039;
  if ( v7 )
  {
    v10 = pVoidMem[3] - pScratchPad->m_vPlayerOrigin[0].x;
    v11 = pVoidMem[4] - pScratchPad->m_vPlayerOrigin[0].y;
    v12 = pVoidMem[5] - pScratchPad->m_vPlayerOrigin[0].z;
  }
  else
  {
    ConvertListenerVectorTo2D(pvforward: (Vector *)((char *)&v15 + 4), pvright: pScratchPad->m_vPlayerRight);
    v10 = *((float *)&v15 + 1) * 12.0;
    v11 = *((float *)&v15 + 2) * 12.0;
    v12 = *((float *)&v15 + 3) * 12.0;
    v8 = v16;
  }
  v13 = (float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v10 * v10);
  v14 = 0;
  *(float *)&v14 = fsqrt(v13);
  v15 = v14;
  if ( *(float *)&v14 < 3.4028235e38 )
    v8 = v15;
  *((_DWORD *)pVoidMem + 9) = v8;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A3F0
// Name: public: virtual void CSosOperatorRemapValue::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorRemapValue::Execute(
        CSosOperatorRemapValue *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v12; // xmm0_4
  float B; // [esp+20h] [ebp-10h]

  v6 = pVoidMem[3];
  v7 = pVoidMem[5];
  v8 = pVoidMem[11];
  v9 = pVoidMem[7];
  v10 = pVoidMem[9];
  if ( v6 > v7 && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Warning: remap_value operator min arg is greater than max arg\n");
  if ( v9 > v10 && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Warning: remap_value operator map min arg is greater than map max arg\n");
  if ( v6 == v7 )
  {
    if ( v6 > v8 )
    {
      v12 = v9;
      goto LABEL_21;
    }
    if ( v8 > v7 )
    {
      v12 = v10;
      goto LABEL_21;
    }
    if ( *((_BYTE *)pVoidMem + 57) != 0 )
    {
      v12 = v10;
      goto LABEL_21;
    }
LABEL_17:
    v12 = v9;
    goto LABEL_21;
  }
  if ( v9 == v10 )
  {
    v12 = v9;
    goto LABEL_21;
  }
  if ( v6 >= v8 )
    goto LABEL_17;
  if ( v8 < v7 )
  {
    B = RemapVal(val: v8, A: v6, B: v7, C: v9, D: v10);
    v12 = B;
  }
  else
  {
    v12 = v10;
  }
LABEL_21:
  if ( *((_BYTE *)pVoidMem + 56) != 0 )
  {
    if ( v9 <= v12 )
    {
      if ( v12 > v10 )
        v12 = v10;
    }
    else
    {
      v12 = v9;
    }
  }
  pVoidMem[13] = v12;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A5A0
// Name: public: virtual void CSosOperatorRandom::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorRandom::Execute(
        CSosOperatorRandom *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  pVoidMem[7] = _RandomFloat((IUniformRandomStream *)this, a2: pVoidMem[3], a3: pVoidMem[5]);
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A5F0
// Name: public: virtual void CSosOperatorFacing::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFacing::Execute(
        CSosOperatorFacing *this,
        void *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  QAngle vAngles; // [esp+4h] [ebp-Ch] BYREF

  if ( pChannel != nullptr )
  {
    vAngles = *(QAngle *)((_BYTE *)pVoidMem + 1);
    *((float *)pVoidMem + 9) = (SND_GetFacingDirection(
                                  pChannel,
                                  vecListenerOrigin: &pScratchPad->m_vBlendedListenerOrigin,
                                  source_angles: &vAngles)
                              + 1.0)
                             * 0.5;
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A6C0
// Name: public: CSosOperatorFunc1::CSosOperatorFunc1(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorFunc1 *__thiscall CSosOperatorFunc1::CSosOperatorFunc1(CSosOperatorFunc1 *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  int v5; // [esp-8h] [ebp-20h]
  CSosOperator::InputData_t src; // [esp+4h] [ebp-14h] BYREF
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorFunc1_vtbl *)&CSosOperatorFunc1::`vftable';
  src.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 20;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  src.m_nCount = 1;
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 16;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input1", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_func1",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004A780
// Name: public: CSosOperatorFloat::CSosOperatorFloat(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorFloat *__thiscall CSosOperatorFloat::CSosOperatorFloat(CSosOperatorFloat *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorFloat_vtbl *)&CSosOperatorFloat::`vftable';
  src.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 28;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 16;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input1", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  src.m_nOffset = 20;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input2", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_float",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004A870
// Name: public: CSosOperatorVec3::CSosOperatorVec3(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorVec3 *__thiscall CSosOperatorVec3::CSosOperatorVec3(CSosOperatorVec3 *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorVec3_vtbl *)&CSosOperatorVec3::`vftable';
  src.m_nCount = 3;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 60;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input1", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  src.m_nOffset = 36;
  src.m_nOffsetOffset = 48;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input2", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_vec3",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004A960
// Name: public: virtual unsigned int CSosOperatorVec3::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorVec3::GetSize(CSosOperatorVec3 *this)
{
  return 76;
}

//------------------------------------------------------------------------------
// Address: 0x1004A970
// Name: public: CSosOperatorSpeakers::CSosOperatorSpeakers(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSpeakers *__thiscall CSosOperatorSpeakers::CSosOperatorSpeakers(CSosOperatorSpeakers *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorSpeakers_vtbl *)&CSosOperatorSpeakers::`vftable';
  src.m_nCount = 6;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 108;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 36;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 6;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input1", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  src.m_nOffset = 60;
  src.m_nOffsetOffset = 84;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 6;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input2", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_speakers",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004AA60
// Name: public: virtual unsigned int CSosOperatorSpeakers::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorSpeakers::GetSize(CSosOperatorSpeakers *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x1004AA70
// Name: public: CSosOperatorSourceDistance::CSosOperatorSourceDistance(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSourceDistance *__thiscall CSosOperatorSourceDistance::CSosOperatorSourceDistance(
        CSosOperatorSourceDistance *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  int v5; // [esp-8h] [ebp-20h]
  CSosOperator::InputData_t src; // [esp+4h] [ebp-14h] BYREF
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorSourceDistance_vtbl *)&CSosOperatorSourceDistance::`vftable';
  src.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 36;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  src.m_nCount = 3;
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "calc_source_distance",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004AB30
// Name: public: virtual unsigned int CSosOperatorSourceDistance::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorSourceDistance::GetSize(CSosOperatorFacing *this)
{
  return 40;
}

//------------------------------------------------------------------------------
// Address: 0x1004AB40
// Name: public: CSosOperatorFacing::CSosOperatorFacing(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorFacing *__thiscall CSosOperatorFacing::CSosOperatorFacing(CSosOperatorFacing *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  int v5; // [esp-8h] [ebp-20h]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-14h] BYREF
  __int16 v7; // [esp+10h] [ebp-8h]
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorFacing_vtbl *)&CSosOperatorFacing::`vftable';
  v7 = 3;
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = 24;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_angles", element: &nIndex);
  v7 = 1;
  v5 = this->m_vOutputs.m_Size;
  outputData.m_Type = 36;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v5,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "calc_angles_facing",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004AC00
// Name: public: CSosOperatorRemapValue::CSosOperatorRemapValue(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorRemapValue *__thiscall CSosOperatorRemapValue::CSosOperatorRemapValue(CSosOperatorRemapValue *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  int v7; // [esp-8h] [ebp-28h]
  int v8; // [esp-8h] [ebp-28h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-14h] BYREF
  __int16 v10; // [esp+18h] [ebp-8h]
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorRemapValue_vtbl *)&CSosOperatorRemapValue::`vftable';
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 44;
  outputData.m_Type = 48;
  *(_DWORD *)&outputData.m_nCount = 0;
  v10 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  v10 = 1;
  outputData.m_nOffset = 12;
  outputData.m_Type = 16;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_min", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  outputData.m_nOffset = 20;
  outputData.m_Type = 24;
  *(_DWORD *)&outputData.m_nCount = 0;
  v10 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_max", element: &nIndex);
  v7 = this->m_vInputs.m_Size;
  outputData.m_nOffset = 28;
  outputData.m_Type = 32;
  *(_DWORD *)&outputData.m_nCount = 0;
  v10 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v7,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_map_min", element: &nIndex);
  outputData.m_nOffset = 36;
  outputData.m_Type = 40;
  *(_DWORD *)&outputData.m_nCount = 0;
  v10 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: this->m_vInputs.m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_map_max", element: &nIndex);
  v10 = 1;
  v8 = this->m_vOutputs.m_Size;
  outputData.m_Type = 52;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v8,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_remap_float",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004ADC0
// Name: public: virtual unsigned int CSosOperatorRemapValue::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorRemapValue::GetSize(CSosOperatorRemapValue *this)
{
  return 60;
}

//------------------------------------------------------------------------------
// Address: 0x1004ADD0
// Name: public: CSosOperatorRandom::CSosOperatorRandom(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorRandom *__thiscall CSosOperatorRandom::CSosOperatorRandom(CSosOperatorRandom *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-14h] BYREF
  __int16 v8; // [esp+18h] [ebp-8h]
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorRandom_vtbl *)&CSosOperatorRandom::`vftable';
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = 16;
  *(_DWORD *)&outputData.m_nCount = 0;
  v8 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_min", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  v8 = 1;
  outputData.m_nOffset = 20;
  outputData.m_Type = 24;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_max", element: &nIndex);
  v8 = 1;
  v6 = this->m_vOutputs.m_Size;
  outputData.m_Type = 28;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v6,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_random",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EB420
// Name: _ceil
// Source: json
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp-8h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x102EB460
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(unsigned __int64 arg2)
{
  __m128i v1; // xmm7
  __m128i v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64((const __m128i *)&arg2);
  v2 = _mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32(v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns_0, (__m128i)_mm_and_pd((__m128d)v2, *(__m128d *)&S_0));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        arg2 = v6;
        return *(double *)&v6;
      }
      return *(double *)&arg2;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64((const __m128i *)&arg2);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      arg2 = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One_0;
      return *(double *)&arg2;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)&arg2;
      *(double *)&arg2 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One_0);
      return *(double *)&arg2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EB540
// Name: __allrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allrem(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  unsigned __int64 result; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // eax
  int v9; // ecx
  bool v10; // cf
  unsigned __int64 v11; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 == 0 )
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    result = v4 % (unsigned int)a2;
    if ( v2 - 1 < 0 )
      return result;
    return -(__int64)result;
  }
  v6 = __PAIR64__(v3, a2);
  v7 = a1;
  do
  {
    v6 >>= 1;
    v7 >>= 1;
  }
  while ( HIDWORD(v6) != 0 );
  v8 = v7 / (unsigned int)v6;
  v9 = HIDWORD(a2) * v8;
  v11 = (unsigned int)a2 * (unsigned __int64)v8;
  v10 = __CFADD__(v9, HIDWORD(v11));
  HIDWORD(v11) += v9;
  if ( v10 || v11 > a1 )
    v11 -= a2;
  result = v11 - a1;
  if ( v2 - 1 < 0 )
    return -(__int64)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EB5F2
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  number = 0;
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / ibase;
  pctype = locinfo->pctype;
  v16 = 0xFFFFFFFF % ibase;
  while ( 1 )
  {
    if ( (pctype[v7] & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (pctype[v7] & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v12 <= v16 )
    {
      number = v12 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v14 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v14;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x102EB81D
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102EB848
// Name: _strtoul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoul(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 1);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102EB880
// Name: shortsort_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shortsort_s(
        char *hi@<eax>,
        char *lo,
        unsigned int width,
        int (__cdecl *comp)(void *, const void *, const void *),
        void *context)
{
  char *v5; // edx
  char *v6; // edi
  unsigned int v7; // ecx
  char *v8; // esi
  char *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  int v12; // ecx
  char v13; // dl

  v5 = lo;
  v6 = hi;
  if ( hi > lo )
  {
    v7 = width;
    do
    {
      v8 = &lo[width];
      v9 = v5;
      if ( &lo[width] <= v6 )
      {
        do
        {
          if ( comp(a1: context, a2: v8, a3: v9) > 0 )
            v9 = v8;
          v8 += width;
        }
        while ( v8 <= v6 );
        v7 = width;
        v5 = lo;
      }
      v10 = v7;
      v11 = v6;
      if ( v9 != v6 && v7 != 0 )
      {
        v12 = v9 - v6;
        do
        {
          v13 = v11[v12];
          v11[v12] = *v11;
          *v11++ = v13;
          --v10;
        }
        while ( v10 != 0 );
        v7 = width;
        v5 = lo;
      }
      v6 -= v7;
    }
    while ( v6 > v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EB910
// Name: _qsort_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl qsort_s(
        char *base,
        unsigned int num,
        unsigned int width,
        int (__cdecl *comp)(void *, const void *, const void *),
        void *context)
{
  char *v5; // ebx
  unsigned int v6; // esi
  char *v7; // edi
  unsigned int v8; // eax
  char *v9; // esi
  unsigned int v10; // edx
  char *v11; // eax
  int v12; // ecx
  unsigned int v13; // edx
  char *v14; // eax
  int v15; // ecx
  unsigned int v16; // edx
  char *v17; // eax
  int v18; // ecx
  unsigned int v19; // edx
  char *v20; // eax
  int v21; // ecx
  char *v22; // eax
  char *v23; // edx
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  char *v27; // edx
  char *v28; // eax
  char *histk[30]; // [esp+8h] [ebp-100h]
  char *lostk[30]; // [esp+80h] [ebp-88h]
  unsigned int v31; // [esp+F8h] [ebp-10h]
  int stkptr; // [esp+FCh] [ebp-Ch]
  char *hi; // [esp+100h] [ebp-8h]
  char *lo; // [esp+104h] [ebp-4h]
  char base_3; // [esp+113h] [ebp+Bh]
  char base_3a; // [esp+113h] [ebp+Bh]
  char base_3b; // [esp+113h] [ebp+Bh]
  char base_3c; // [esp+113h] [ebp+Bh]

  v5 = base;
  if ( base == nullptr && num != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  v6 = width;
  if ( width == 0 || comp == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  if ( num >= 2 )
  {
    v7 = &base[width * (num - 1)];
    stkptr = 0;
    lo = base;
    hi = v7;
    while ( 1 )
    {
      v8 = (v7 - v5) / v6 + 1;
      if ( v8 <= 8 )
      {
        shortsort_s(hi: v7, lo: v5, width: v6, comp, context);
        goto LABEL_56;
      }
      v9 = &v5[(v8 >> 1) * v6];
      if ( comp(a1: context, a2: v5, a3: v9) > 0 )
      {
        v10 = width;
        v11 = v9;
        if ( v5 != v9 )
        {
          v12 = v5 - v9;
          do
          {
            v31 = v10 - 1;
            base_3 = v11[v12];
            v11[v12] = *v11;
            *v11 = base_3;
            v10 = v31;
            ++v11;
          }
          while ( v31 != 0 );
        }
      }
      if ( comp(a1: context, a2: v5, a3: v7) > 0 )
      {
        v13 = width;
        v14 = v7;
        if ( v5 != v7 )
        {
          v15 = v5 - v7;
          do
          {
            v31 = v13 - 1;
            base_3a = v14[v15];
            v14[v15] = *v14;
            *v14 = base_3a;
            v13 = v31;
            ++v14;
          }
          while ( v31 != 0 );
        }
      }
      if ( comp(a1: context, a2: v9, a3: v7) > 0 )
      {
        v16 = width;
        v17 = v7;
        if ( v9 != v7 )
        {
          v18 = v9 - v7;
          do
          {
            base_3b = v17[v18];
            v17[v18] = *v17;
            *v17++ = base_3b;
            --v16;
          }
          while ( v16 != 0 );
          v5 = lo;
        }
      }
      while ( 1 )
      {
        if ( v9 > v5 )
        {
          while ( 1 )
          {
            v5 += width;
            if ( v5 >= v9 )
              break;
            if ( comp(a1: context, a2: v5, a3: v9) > 0 )
            {
              if ( v9 > v5 )
                goto LABEL_31;
              goto LABEL_29;
            }
          }
        }
        do
LABEL_29:
          v5 += width;
        while ( v5 <= hi && comp(a1: context, a2: v5, a3: v9) <= 0 );
        do
LABEL_31:
          v7 -= width;
        while ( v7 > v9 && comp(a1: context, a2: v7, a3: v9) > 0 );
        if ( v5 > v7 )
          break;
        v19 = width;
        v20 = v7;
        if ( v5 != v7 )
        {
          v21 = v5 - v7;
          do
          {
            v31 = v19 - 1;
            base_3c = v20[v21];
            v20[v21] = *v20;
            *v20 = base_3c;
            v19 = v31;
            ++v20;
          }
          while ( v31 != 0 );
        }
        if ( v9 == v7 )
          v9 = v5;
      }
      v7 += width;
      if ( v9 >= v7 )
        goto LABEL_43;
      do
      {
        v7 -= width;
        if ( v7 <= v9 )
          goto LABEL_43;
      }
      while ( comp(a1: context, a2: v7, a3: v9) == 0 );
      if ( v9 < v7 )
      {
LABEL_45:
        v22 = lo;
      }
      else
      {
LABEL_43:
        while ( 1 )
        {
          v7 -= width;
          v22 = lo;
          if ( v7 <= lo )
            break;
          if ( comp(a1: context, a2: v7, a3: v9) != 0 )
            goto LABEL_45;
        }
      }
      v23 = hi;
      if ( v7 - v22 < hi - v5 )
      {
        if ( v5 < hi )
        {
          v25 = stkptr;
          lostk[stkptr] = v5;
          histk[v25] = v23;
          stkptr = v25 + 1;
        }
        if ( v22 >= v7 )
          goto LABEL_55;
        v5 = lo;
        v6 = width;
        hi = v7;
      }
      else
      {
        if ( v22 < v7 )
        {
          v24 = stkptr;
          lostk[stkptr] = v22;
          histk[v24] = v7;
          stkptr = v24 + 1;
        }
        if ( v5 >= v23 )
        {
LABEL_55:
          v6 = width;
LABEL_56:
          v26 = --stkptr;
          if ( stkptr < 0 )
            return;
          v27 = lostk[v26];
          v28 = histk[v26];
          lo = v27;
          hi = v28;
          v5 = v27;
          v7 = v28;
        }
        else
        {
          v7 = hi;
          v6 = width;
          lo = v5;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EBBCF
// Name: _strtok
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strtok(char *string, const char *control)
{
  char v3; // dl
  char *token; // edx
  char *v5; // ebx
  _tiddata *ptd; // [esp+10h] [ebp-28h]
  unsigned __int8 map[32]; // [esp+14h] [ebp-24h] BYREF

  ptd = _getptd();
  memset(map, 0, sizeof(map));
  do
  {
    v3 = *control;
    map[*(unsigned __int8 *)control >> 3] |= 1 << (*control & 7);
    ++control;
  }
  while ( v3 != 0 );
  token = string;
  if ( string == nullptr )
    token = ptd->_token;
  while ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 && *token != 0 )
    ++token;
  v5 = token;
  while ( *token != 0 )
  {
    if ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 )
    {
      *token++ = 0;
      break;
    }
    ++token;
  }
  ptd->_token = token;
  return token != v5 ? v5 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102EBC90
// Name: _acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl acos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp-8h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x102FB138);
  }
  JUMPOUT(0x102EBD1F);
}

//------------------------------------------------------------------------------
// Address: 0x102EBCD0
// Name: __CIacos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIacos(double a1, int a2, int a3)
{
  int v4; // eax
  bool v5; // zf
  char v6; // [esp-8h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIacos;
  v4 = _mm_getcsr() & 0x7F80;
  v5 = v4 == 8064;
  if ( v4 == 8064 )
    v5 = (v6 & 0x7F) == 127;
  if ( v5 )
    _CIacos_pentium4(a1, __saved_registers: a2, __return_address: a3);
  else
__CIacos:
    _CIacos_default(a1: LODWORD(a1), a2: HIDWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x102EBD0B
// Name: __CIacos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x102EBDE0
// Name: _asin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl asin(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp-8h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x102FB698);
  }
  JUMPOUT(0x102EBE6F);
}

//------------------------------------------------------------------------------
// Address: 0x102EBE20
// Name: __CIasin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIasin(double a1, int a2, int a3)
{
  int v4; // eax
  bool v5; // zf
  char v6; // [esp-8h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIasin;
  v4 = _mm_getcsr() & 0x7F80;
  v5 = v4 == 8064;
  if ( v4 == 8064 )
    v5 = (v6 & 0x7F) == 127;
  if ( v5 )
    _CIasin_pentium4(a1, __saved_registers: a2, __return_address: a3);
  else
__CIasin:
    _CIasin_default(a1: LODWORD(a1), a2: HIDWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x102EBE5B
// Name: __CIasin_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x102EBF30
// Name: _sinh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sinh(double X)
{
  double result; // st7

  _ctrandisp1(parm1: *(unsigned __int64 *)&X);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EBF3A
// Name: _cosh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl cosh(double X)
{
  JUMPOUT(0x102EBF35);
}

//------------------------------------------------------------------------------
// Address: 0x102EBF41
// Name: _tanh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl tanh(double X)
{
  JUMPOUT(0x102EBF35);
}

//------------------------------------------------------------------------------
// Address: 0x102EBF48
// Name: __CIsinh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __thiscall _CIsinh(int this)
{
  return _cintrindisp1(a1: this, a2: &_OP_SINHjmptab);
}

//------------------------------------------------------------------------------
// Address: 0x102EBF52
// Name: __CIcosh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIcosh()
{
  JUMPOUT(0x102EBF4D);
}

//------------------------------------------------------------------------------
// Address: 0x102EBF59
// Name: __CItanh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CItanh()
{
  JUMPOUT(0x102EBF4D);
}

//------------------------------------------------------------------------------
// Address: 0x102EBF60
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x102ED246);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EBFE6
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fread_nolock_s(
        char *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  char *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = buffer;
  dataSize = bufferSize;
  if ( elementSize == 0 || num == 0 )
    return 0;
  if ( buffer != nullptr )
  {
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
      goto LABEL_13;
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
    {
LABEL_13:
      v6 = num * elementSize;
      v7 = num * elementSize;
      if ( (stream->_flag & 0x10C) != 0 )
        streambufsize = stream->_bufsiz;
      else
        streambufsize = 4096;
      if ( v6 == 0 )
        return num;
      while ( 1 )
      {
        if ( (stream->_flag & 0x10C) != 0 )
        {
          cnt = stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_44;
            v9 = v7;
            if ( v7 >= cnt )
              v9 = stream->_cnt;
            if ( v9 > dataSize )
              goto LABEL_41;
            memcpy_s(dst: data, sizeInBytes: dataSize, src: stream->_ptr, count: v9);
            stream->_cnt -= v9;
            stream->_ptr += v9;
            data += v9;
            v7 -= v9;
            dataSize -= v9;
            v6 = num * elementSize;
            goto LABEL_39;
          }
        }
        if ( v7 < streambufsize )
          break;
        if ( streambufsize != 0 )
        {
          if ( v7 <= 0x7FFFFFFF )
          {
            v10 = v7 % streambufsize;
            v11 = v7;
          }
          else
          {
            v10 = 0x7FFFFFFF % streambufsize;
            v11 = 0x7FFFFFFF;
          }
          v12 = v11 - v10;
        }
        else
        {
          v12 = 0x7FFFFFFF;
          if ( v7 <= 0x7FFFFFFF )
            v12 = v7;
        }
        if ( v12 > dataSize )
          goto LABEL_41;
        v17 = v12;
        v13 = fileno(stream);
        v14 = _read(fh: v13, buf: data, cnt: v17);
        if ( v14 == 0 )
        {
          stream->_flag |= 0x10u;
          return (v6 - v7) / elementSize;
        }
        if ( v14 == -1 )
        {
LABEL_44:
          stream->_flag |= 0x20u;
          return (v6 - v7) / elementSize;
        }
        data += v14;
        v7 -= v14;
        dataSize -= v14;
LABEL_39:
        if ( v7 == 0 )
          return num;
      }
      v15 = _filbuf(str: stream);
      if ( v15 == -1 )
        return (v6 - v7) / elementSize;
      if ( dataSize != 0 )
      {
        v16 = data++;
        *v16 = v15;
        --v7;
        --dataSize;
        streambufsize = stream->_bufsiz;
        goto LABEL_39;
      }
LABEL_41:
      if ( bufferSize != -1 )
        memset(dst: (int)buffer, value: nullptr, count: bufferSize);
      *_errno() = 34;
LABEL_5:
      _invalid_parameter_noinfo();
      return 0;
    }
  }
  *_errno() = 22;
  goto LABEL_5;
}

//------------------------------------------------------------------------------
// Address: 0x102EC1A2
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread_s(
        char *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( elementSize == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fread_nolock_s(buffer, bufferSize, elementSize, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EC230
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread(char *buffer, unsigned int elementSize, unsigned int count, _iobuf *stream)
{
  return fread_s(buffer, bufferSize: 0xFFFFFFFF, elementSize, count, stream);
}

//------------------------------------------------------------------------------
// Address: 0x102EC24D
// Name: __fwrite_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fwrite_nolock(unsigned __int8 *buffer, unsigned int size, unsigned int num, _iobuf *stream)
{
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int cnt; // eax
  unsigned int v8; // edi
  unsigned int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int bufsize; // [esp+10h] [ebp-8h]
  unsigned __int8 *data; // [esp+14h] [ebp-4h]

  if ( size == 0 || num == 0 )
    return 0;
  if ( stream == nullptr || buffer == nullptr || num > 0xFFFFFFFF / size )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v5 = num * size;
  data = buffer;
  v6 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsize = stream->_bufsiz;
  else
    bufsize = 4096;
  if ( v5 == 0 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x108) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt != 0 )
      {
        if ( cnt < 0 )
        {
          stream->_flag |= 0x20u;
LABEL_34:
          v13 = v5;
          return (v13 - v6) / size;
        }
        v8 = v6;
        if ( v6 >= cnt )
          v8 = stream->_cnt;
        memcpy(dst: (unsigned __int8 *)stream->_ptr, src: data, count: v8);
        stream->_cnt -= v8;
        stream->_ptr += v8;
        v6 -= v8;
        data += v8;
        goto LABEL_27;
      }
    }
    if ( v6 >= bufsize )
      break;
    if ( _flsbuf(ch: (char)*data, str: stream) == -1 )
      goto LABEL_34;
    ++data;
    --v6;
    bufsize = stream->_bufsiz;
    if ( (int)bufsize <= 0 )
      bufsize = 1;
LABEL_31:
    if ( v6 == 0 )
      return num;
  }
  if ( (stream->_flag & 0x108) != 0 && _flush(str: stream) != 0 )
    goto LABEL_34;
  v9 = v6;
  if ( bufsize != 0 )
    v9 = v6 - v6 % bufsize;
  v10 = fileno(stream);
  v11 = _write(fh: v10, buf: data, cnt: v9);
  if ( v11 != -1 )
  {
    v12 = v9;
    if ( v11 <= v9 )
      v12 = v11;
    data += v12;
    v6 -= v12;
    if ( v11 >= v9 )
    {
LABEL_27:
      v5 = num * size;
      goto LABEL_31;
    }
  }
  stream->_flag |= 0x20u;
  v13 = num * size;
  return (v13 - v6) / size;
}

//------------------------------------------------------------------------------
// Address: 0x102EC3A4
// Name: _fwrite
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fwrite(unsigned __int8 *buffer, unsigned int size, unsigned int count, _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( size == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fwrite_nolock(buffer, size, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EC41E
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC48B
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC4FF
// Name: __fseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseek_nolock(_iobuf *str, int offset, int whence)
{
  int flag; // eax
  int v5; // eax
  int v6; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock(str);
      whence = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = fileno(stream: str);
    return (_lseek(fh: v6, pos: offset, mthd: whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC589
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fseek(_iobuf *stream, int offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseek_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC605
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  _BYTE v7[12]; // [esp+1Ch] [ebp-10h] BYREF
  int v8; // [esp+28h] [ebp-4h]
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  v8 = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: v7, a3: -2);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EC6C1
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x102EC6D8
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftell_nolock(_iobuf *str)
{
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v9; // ebx
  char *v10; // edx
  int cnt; // edx
  ioinfo **v12; // ebx
  int v13; // esi
  char *v14; // eax
  char *v15; // ecx
  bool v16; // zf
  int bufsiz; // eax
  int v18; // ecx
  unsigned int offset; // [esp+8h] [ebp-Ch]
  int fd; // [esp+Ch] [ebp-8h]
  int filepos; // [esp+10h] [ebp-4h]
  unsigned int rdcnt; // [esp+1Ch] [ebp+8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = fileno(stream: str);
  v4 = v3;
  fd = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v5 = _lseek(fh: v3, pos: 0, mthd: 1);
  filepos = v5;
  if ( v5 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v5 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  v9 = (char *)(str->_ptr - base);
  offset = (unsigned int)v9;
  if ( (flag & 3) != 0 )
  {
    if ( __pioinfo[v4 >> 5][v4 & 0x1F].osfile < 0 )
    {
      v10 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v10 == 10 )
            ++v9;
          ++v10;
        }
        while ( v10 < ptr );
        offset = (unsigned int)v9;
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( filepos == 0 )
    return (int)v9;
  if ( (str->_flag & 1) == 0 )
    return filepos + offset;
  cnt = str->_cnt;
  if ( cnt != 0 )
  {
    v12 = &__pioinfo[fd >> 5];
    rdcnt = cnt + ptr - base;
    v13 = (fd & 0x1F) << 6;
    if ( *(&(*v12)->osfile + v13) >= 0 )
    {
LABEL_39:
      filepos -= rdcnt;
      return filepos + offset;
    }
    if ( _lseek(fh: fd, pos: 0, mthd: 2) == filepos )
    {
      v14 = str->_base;
      v15 = &v14[rdcnt];
      while ( v14 < v15 )
      {
        if ( *v14 == 10 )
          ++rdcnt;
        ++v14;
      }
      v16 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v16 )
        ++rdcnt;
      goto LABEL_39;
    }
    if ( _lseek(fh: fd, pos: filepos, mthd: 0) >= 0 )
    {
      bufsiz = 512;
      if ( rdcnt > 0x200 || ((v18 = str->_flag) & 8) == 0 || (v18 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      rdcnt = bufsiz;
      v16 = (*(&(*v12)->osfile + v13) & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  offset = 0;
  return filepos + offset;
}

//------------------------------------------------------------------------------
// Address: 0x102EC86C
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ftell(_iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ftell_nolock(str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC8D1
// Name: __isupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isupper_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 1;
  else
    result = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EC922
// Name: _isupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isupper(int c)
{
  if ( __locale_changed != 0 )
    return _isupper_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EC950
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, mask: 4, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EC9A1
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 4;
}

//------------------------------------------------------------------------------
// Address: 0x102EC9CF
// Name: __isxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isxdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x80;
  else
    result = _isctype_l(c, mask: 128, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECA25
// Name: _isxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isxdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isxdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x80;
}

//------------------------------------------------------------------------------
// Address: 0x102ECA55
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isspace_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 8;
  else
    result = _isctype_l(c, mask: 8, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECAA6
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isspace(int c)
{
  if ( __locale_changed != 0 )
    return _isspace_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 8;
}

//------------------------------------------------------------------------------
// Address: 0x102ECAD4
// Name: __isalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isalnum_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x107;
  else
    result = _isctype_l(c, mask: 263, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECB2A
// Name: _isalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isalnum(int c)
{
  if ( __locale_changed != 0 )
    return _isalnum_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x107;
}

//------------------------------------------------------------------------------
// Address: 0x102ECB5A
// Name: __isprint_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isprint_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x157;
  else
    result = _isctype_l(c, mask: 343, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECBB0
// Name: _isprint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isprint(int c)
{
  if ( __locale_changed != 0 )
    return _isprint_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x157;
}

//------------------------------------------------------------------------------
// Address: 0x102ECBE0
// Name: __iscntrl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _iscntrl_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x20;
  else
    result = _isctype_l(c, mask: 32, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECC31
// Name: _iscntrl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iscntrl(int c)
{
  if ( __locale_changed != 0 )
    return _iscntrl_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x102ECC5F
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _tolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+18h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+1Ch] [ebp-4h] BYREF
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pclmap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x102ECD74
// Name: _tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl tolower(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _tolower_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 65 <= 0x19 )
    return c + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECDA0
// Name: FindCompleteObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__thiscall FindCompleteObject(void **inptr)
{
  int v1; // edx
  _BYTE *result; // eax
  int v3; // edx

  v1 = *((_DWORD *)*inptr - 1);
  result = (char *)inptr - *(_DWORD *)(v1 + 4);
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 != 0 )
    result -= *(unsigned int *)((char *)inptr - v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECDB6
// Name: PMDtoOffset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall PMDtoOffset@<eax>(const PMD *pmd@<eax>, char *pThis)
{
  int pdisp; // edx
  int v3; // ecx

  pdisp = pmd->pdisp;
  v3 = 0;
  if ( pdisp >= 0 )
    v3 = *(_DWORD *)(*(_DWORD *)&pThis[pdisp] + pmd->vdisp) + pmd->pdisp;
  return v3 + pmd->mdisp;
}

//------------------------------------------------------------------------------
// Address: 0x102ECDDA
// Name: FindMITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindMITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassArray *pBaseClassArray; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  const _s_RTTIBaseClassDescriptor *pSourceBCD; // [esp+Ch] [ebp-14h]
  const _s_RTTIBaseClassDescriptor *pTargetBCD; // [esp+10h] [ebp-10h]
  unsigned int nTargetBases; // [esp+14h] [ebp-Ch]
  unsigned int iTarget; // [esp+18h] [ebp-8h]
  unsigned int i; // [esp+1Ch] [ebp-4h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  pTargetBCD = nullptr;
  pSourceBCD = nullptr;
  nTargetBases = 0;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  while ( 1 )
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( pSourceBCD != nullptr )
        {
          if ( (v8->attributes & 3) == 0 && (pSourceBCD->attributes & 1) == 0 )
            return v8;
          return nullptr;
        }
        iTarget = i;
        pTargetBCD = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
        break;
    }
LABEL_12:
    if ( ++i >= numBaseClasses )
      return nullptr;
  }
  if ( pTargetBCD == nullptr )
  {
    pSourceBCD = v8;
    goto LABEL_12;
  }
  if ( i - iTarget > nTargetBases )
  {
    if ( (pTargetBCD->attributes & 3) == 0 )
      goto LABEL_20;
    return nullptr;
  }
  if ( (pTargetBCD->attributes & 0x40) == 0 )
  {
    if ( iTarget == 0 )
    {
LABEL_20:
      if ( (v8->attributes & 1) != 0 )
        return nullptr;
    }
    return pTargetBCD;
  }
  return (pTargetBCD->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) == 0
       ? pTargetBCD
       : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102ECEE2
// Name: FindVITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindVITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassDescriptor *v7; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  bool v11; // al
  int v12; // eax
  const _s_RTTIBaseClassDescriptor *result; // eax
  const _s_RTTIBaseClassArray *pBaseClassArray; // [esp+Ch] [ebp-24h]
  const _s_RTTIBaseClassDescriptor *pCrossCastTargetBCD; // [esp+10h] [ebp-20h]
  const _s_RTTIBaseClassDescriptor *pCrossCastSourceBCD; // [esp+14h] [ebp-1Ch]
  int offsetDownCastResult; // [esp+18h] [ebp-18h]
  const _s_RTTIBaseClassDescriptor *pDownCastResultBCD; // [esp+1Ch] [ebp-14h]
  unsigned int nTargetBases; // [esp+20h] [ebp-10h]
  unsigned int iTarget; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+28h] [ebp-8h]
  bool fDownCastAllowed; // [esp+2Fh] [ebp-1h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  offsetDownCastResult = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  v7 = nullptr;
  pDownCastResultBCD = nullptr;
  pCrossCastSourceBCD = nullptr;
  pCrossCastTargetBCD = nullptr;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  nTargetBases = 0;
  fDownCastAllowed = true;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  do
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( (v8->attributes & 3) == 0 )
          pCrossCastTargetBCD = v8;
        iTarget = i;
        v7 = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
      {
        if ( i - iTarget > nTargetBases )
        {
          if ( (v8->attributes & 5) == 0 )
            pCrossCastSourceBCD = v8;
        }
        else if ( fDownCastAllowed )
        {
          if ( (v7->attributes & 0x40) != 0 )
          {
            if ( (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 4) == 0;
          }
          else
          {
            if ( iTarget == 0 && (v8->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = true;
          }
          if ( fDownCastAllowed && v11 )
          {
            v12 = PMDtoOffset(pmd: &v7->where, pThis: pCompleteObject);
            if ( pDownCastResultBCD != nullptr && offsetDownCastResult != v12 )
              return nullptr;
            pDownCastResultBCD = v7;
            offsetDownCastResult = v12;
          }
        }
      }
    }
    ++i;
  }
  while ( i < numBaseClasses );
  if ( !fDownCastAllowed || (result = pDownCastResultBCD, pDownCastResultBCD == nullptr) )
  {
    if ( pCrossCastSourceBCD == nullptr )
      return nullptr;
    result = pCrossCastTargetBCD;
    if ( pCrossCastTargetBCD == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED178
// Name: $LN35_6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _LN35_6@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    strlen(buf: (unsigned __int8 *)string);
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      str._cnt = v6;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ED1E6
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return _LN35_6(string, inputfn: _input_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x102ED208
// Name: _sscanf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf_s(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return _LN35_6(string, inputfn: _input_s_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x102ED240
// Name: _strchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strchr(char *string, unsigned __int8 chr)
{
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = string;
  if ( ((unsigned __int8)string & 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == chr || v3 == 0 )
        break;
      if ( ((unsigned __int8)v2 & 3) == 0 )
        goto main_loop;
    }
  }
  else
  {
    do
    {
main_loop:
      while ( 1 )
      {
        v4 = ((chr << 8) | chr | (((chr << 8) | chr) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( (((v4 + 2130640639) ^ ~v4) & 0x81010100) != 0 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 != 0 && ((v7 & 0x1010100) != 0 || (v5 & 0x80000000) == 0) )
          return;
      }
      v8 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v8 == chr )
        break;
      if ( (_BYTE)v8 == 0 )
        break;
      if ( BYTE1(v8) == chr )
        break;
      if ( BYTE1(v8) == 0 )
        break;
      v9 = HIWORD(v8);
      if ( (_BYTE)v9 == chr )
        break;
    }
    while ( (_BYTE)v9 != 0 && BYTE1(v9) != chr && BYTE1(v9) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ED300
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x102ED330
// Name: __allshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _allshr@<eax>(__int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> 31;
  }
  else if ( a2 >= 0x20u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> (a2 & 0x1F);
  }
  else
  {
    a1 >>= a2 & 0x1F;
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x102ED360
// Name: __allshl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _allshl@<eax>(__int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  __int64 v2; // rax

  if ( a2 >= 0x40u )
  {
    LODWORD(v2) = 0;
  }
  else if ( a2 >= 0x20u )
  {
    LODWORD(v2) = 0;
  }
  else
  {
    return a1 << (a2 & 0x1F);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102ED380
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown_0+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 102ED3D9 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ED6E1
// Name: _wcsstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcsstr(const wchar_t *wcs1, const wchar_t *wcs2)
{
  unsigned __int16 *result; // eax
  const wchar_t *v3; // edi
  unsigned __int16 v4; // dx
  int i; // eax
  const wchar_t *v6; // ecx
  int v7; // edx

  result = (unsigned __int16 *)wcs1;
  v3 = wcs1;
  if ( *wcs2 != 0 )
  {
    if ( *wcs1 != 0 )
    {
      v4 = *wcs1;
      for ( i = (char *)wcs1 - (char *)wcs2; ; i += 2 )
      {
        v6 = wcs2;
        if ( v4 != 0 )
          break;
LABEL_8:
        if ( *v6 == 0 )
          return (unsigned __int16 *)v3;
        v4 = *++v3;
        if ( *v3 == 0 )
          return nullptr;
      }
      while ( 1 )
      {
        v7 = *v6;
        if ( (_WORD)v7 == 0 )
          return (unsigned __int16 *)v3;
        if ( *(const wchar_t *)((char *)v6 + i) == v7 && *(const wchar_t *)((char *)++v6 + i) != 0 )
          continue;
        goto LABEL_8;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED741
// Name: __snprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snprintf(char *string, unsigned int count, const char *format, ...)
{
  int result; // eax
  int v4; // edi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+3Ch] [ebp+14h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr = 0;
      return v4;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED7ED
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED899
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x102ED8B6
// Name: __mkdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mkdir(const char *path)
{
  DWORD LastError; // eax

  if ( CreateDirectoryA(lpPathName: path, lpSecurityAttributes: nullptr) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102ED8E8
// Name: __rmdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _rmdir(const char *path)
{
  DWORD LastError; // eax

  if ( RemoveDirectoryA(lpPathName: path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102ED918
// Name: _remove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl remove(const char *path)
{
  DWORD LastError; // eax

  if ( DeleteFileA(lpFileName: path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102ED948
// Name: _unlink
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unlink(const char *path)
{
  return remove(path);
}

//------------------------------------------------------------------------------
// Address: 0x102ED953
// Name: _strncmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncmp(const char *first, const char *last, unsigned int count)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  unsigned int i; // esi
  unsigned int n; // [esp+4h] [ebp-4h]

  n = 0;
  if ( count == 0 )
    return 0;
  if ( count <= 4 )
  {
    v4 = last;
    v5 = first;
LABEL_20:
    for ( i = n; ; ++i )
    {
      if ( i >= count )
        return 0;
      if ( *v5 == 0 || *v5 != *v4 )
        break;
      ++v5;
      ++v4;
    }
    v10 = *(unsigned __int8 *)v5;
    v11 = *(unsigned __int8 *)v4;
  }
  else
  {
    v4 = last;
    v5 = first;
    while ( 1 )
    {
      v6 = *v5;
      v5 += 4;
      v4 += 4;
      if ( v6 == 0 || v6 != *(v4 - 4) )
        break;
      v7 = *(v5 - 3);
      if ( v7 == 0 || v7 != *(v4 - 3) )
      {
        v10 = *((unsigned __int8 *)v5 - 3);
        v11 = *((unsigned __int8 *)v4 - 3);
        return v10 - v11;
      }
      v8 = *(v5 - 2);
      if ( v8 == 0 || v8 != *(v4 - 2) )
      {
        v10 = *((unsigned __int8 *)v5 - 2);
        v11 = *((unsigned __int8 *)v4 - 2);
        return v10 - v11;
      }
      v9 = *(v5 - 1);
      if ( v9 == 0 || v9 != *(v4 - 1) )
      {
        v10 = *((unsigned __int8 *)v5 - 1);
        v11 = *((unsigned __int8 *)v4 - 1);
        return v10 - v11;
      }
      n += 4;
      if ( n >= count - 4 )
        goto LABEL_20;
    }
    v10 = *((unsigned __int8 *)v5 - 4);
    v11 = *((unsigned __int8 *)v4 - 4);
  }
  return v10 - v11;
}

//------------------------------------------------------------------------------
// Address: 0x102EDA13
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isleadbyte_l(unsigned __int8 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _loc_update.localeinfo.locinfo->pctype[c] & 0x8000;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EDA4B
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isleadbyte(unsigned __int8 c)
{
  return _isleadbyte_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EDA5E
// Name: _iswdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswdigit(unsigned __int16 c)
{
  return iswctype(c, mask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x102EDA71
// Name: _iswspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswspace(unsigned __int16 c)
{
  return iswctype(c, mask: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x102EDA84
// Name: _iswalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswalnum(unsigned __int16 c)
{
  return iswctype(c, mask: 0x107u);
}

//------------------------------------------------------------------------------
// Address: 0x102EDA9A
// Name: _iswcntrl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswcntrl(unsigned __int16 c)
{
  return iswctype(c, mask: 0x20u);
}

//------------------------------------------------------------------------------
// Address: 0x102EDAAD
// Name: _iswascii
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl iswascii(unsigned __int16 c)
{
  return c < 0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x102EDAC1
// Name: _wcsncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcsncpy(unsigned __int16 *dest, const wchar_t *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned __int16 *v4; // edi
  unsigned __int16 v5; // ax
  unsigned int v6; // ecx
  char v7; // cf
  unsigned int v8; // ecx
  unsigned __int16 *v9; // edi
  int i; // ecx

  v3 = count;
  v4 = dest;
  if ( count != 0 )
  {
    do
    {
      v5 = *(unsigned __int16 *)((char *)v4 + (char *)source - (char *)dest);
      *v4++ = v5;
      if ( v5 == 0 )
        break;
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 != 0 )
    {
      v6 = v3 - 1;
      if ( v6 != 0 )
      {
        v7 = v6 & 1;
        v8 = v6 >> 1;
        memset(v4, 0, 4 * v8);
        v9 = &v4[2 * v8];
        for ( i = v7; i != 0; --i )
          *v9++ = 0;
      }
    }
  }
  return dest;
}

//------------------------------------------------------------------------------
// Address: 0x102EDB10
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x102EDC34
// Name: IsRootUNCName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall IsRootUNCName@<eax>(const char *path@<esi>)
{
  unsigned int v1; // eax
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  unsigned __int8 *v9; // [esp+0h] [ebp-4h]

  strlen(buf: v9);
  if ( v1 < 5 || *path != 92 && *path != 47 )
    return false;
  v2 = path[1];
  if ( v2 != 92 && v2 != 47 )
    return false;
  v3 = path[2];
  if ( v3 == 92 )
    return false;
  if ( v3 == 47 )
    return false;
  v4 = path + 3;
  v5 = path[3];
  if ( v5 == 0 )
    return false;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    v5 = *++v4;
  }
  while ( *v4 != 0 );
  if ( *v4 == 0 )
    return false;
  v6 = (char *)(v4 + 1);
  if ( *v6 == 0 )
    return false;
  v7 = *v6;
  do
  {
    if ( v7 == 92 )
      break;
    if ( v7 == 47 )
      break;
    v7 = *++v6;
  }
  while ( *v6 != 0 );
  return *v6 == 0 || v6[1] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x102EDCAE
// Name: _fullpath_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fullpath_helper(char *buf, const char *path, unsigned int sz, char **pBuf)
{
  int v4; // esi
  char *v5; // edi
  int *v6; // eax
  char *result; // eax

  v4 = *_errno();
  *_errno() = 0;
  v5 = _fullpath(UserBuf: buf, path, maxlen: sz);
  v6 = _errno();
  if ( v5 != nullptr )
  {
    *v6 = v4;
    return v5;
  }
  else if ( *v6 == 34 )
  {
    *_errno() = v4;
    result = _fullpath(UserBuf: nullptr, path, maxlen: 0);
    *pBuf = result;
  }
  else
  {
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EDD0E
// Name: __stat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stat64i32(const char *name, _stat64i32 *buf)
{
  const char *dwHighDateTime; // esi
  unsigned int v3; // eax
  unsigned __int8 *v4; // eax
  const char *v5; // esi
  int v6; // eax
  __int64 v7; // rax
  int v8; // esi
  DWORD LastError; // eax
  int retval; // [esp+Ch] [ebp-26Ch]
  int drive; // [esp+10h] [ebp-268h]
  _FILETIME LocalFTime; // [esp+14h] [ebp-264h] BYREF
  int fd; // [esp+1Ch] [ebp-25Ch] BYREF
  _WIN32_FIND_DATAA findbuf; // [esp+20h] [ebp-258h] BYREF
  _SYSTEMTIME SystemTime; // [esp+160h] [ebp-118h] BYREF
  char pathbuf[260]; // [esp+170h] [ebp-108h] BYREF

  dwHighDateTime = name;
  LocalFTime.dwHighDateTime = (unsigned int)name;
  retval = 0;
  if ( name == nullptr || buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( _mbspbrk(string: (const unsigned __int8 *)name, charset: "?*") != nullptr )
  {
LABEL_5:
    *_errno() = 2;
    *__doserrno() = 2;
    return -1;
  }
  if ( name[1] == 58 )
  {
    if ( *name != 0 && name[2] == 0 )
      goto LABEL_5;
    v3 = _mbctolower(c: *name) - 96;
  }
  else
  {
    v3 = _getdrive();
  }
  drive = v3;
  fd = (int)FindFirstFileExA(
              lpFileName: name,
              fInfoLevelId: FindExInfoStandard,
              lpFindFileData: &findbuf,
              fSearchOp: FindExSearchNameMatch,
              lpSearchFilter: nullptr,
              dwAdditionalFlags: 0);
  if ( fd != -1 )
  {
    if ( (findbuf.dwFileAttributes & 0x400) != 0 && findbuf.dwReserved0 == -1610612724 )
    {
      fd = -1;
      if ( _sopen_s(pfh: &fd, path: name, oflag: 0, shflag: 64, pmode: 0) == 0 && fd != -1 )
      {
        v8 = _fstat64i32(fildes: fd, buf);
        _close(fh: fd);
        return v8;
      }
      goto LABEL_5;
    }
    if ( findbuf.ftLastWriteTime.dwLowDateTime != 0 || findbuf.ftLastWriteTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastWriteTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      buf->st_mtime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
    }
    else
    {
      buf->st_mtime = 0;
    }
    if ( findbuf.ftLastAccessTime.dwLowDateTime != 0 || findbuf.ftLastAccessTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastAccessTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      buf->st_atime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
    }
    else
    {
      buf->st_atime = buf->st_mtime;
    }
    if ( findbuf.ftCreationTime.dwLowDateTime == 0 && findbuf.ftCreationTime.dwHighDateTime == 0 )
    {
      buf->st_ctime = buf->st_mtime;
LABEL_45:
      FindClose(hFindFile: (HANDLE)fd);
      goto LABEL_46;
    }
    if ( FileTimeToLocalFileTime(lpFileTime: &findbuf.ftCreationTime, lpLocalFileTime: &LocalFTime)
      && FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
    {
      buf->st_ctime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
      goto LABEL_45;
    }
LABEL_49:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    FindClose(hFindFile: (HANDLE)fd);
    return -1;
  }
  fd = 0;
  if ( _mbspbrk(string: (const unsigned __int8 *)name, charset: "./\\") == nullptr )
    goto LABEL_5;
  v4 = (unsigned __int8 *)fullpath_helper(buf: pathbuf, path: name, sz: 0x104u, pBuf: (char **)&fd);
  v5 = (const char *)v4;
  if ( v4 == nullptr || (strlen(buf: v4), v6 != 3) && !IsRootUNCName(path: v5) || GetDriveTypeA(lpRootPathName: v5) <= 1 )
  {
    if ( fd != 0 )
      free(pMem: (void *)fd);
    goto LABEL_5;
  }
  if ( fd != 0 )
    free(pMem: (void *)fd);
  findbuf.dwFileAttributes = 16;
  findbuf.nFileSizeHigh = 0;
  findbuf.nFileSizeLow = 0;
  findbuf.cFileName[0] = 0;
  v7 = __loctotime64_t(yr: 1980, mo: 1, dy: 1, hr: 0, mn: 0, sc: 0, dstflag: -1);
  dwHighDateTime = (const char *)LocalFTime.dwHighDateTime;
  buf->st_mtime = v7;
  buf->st_atime = v7;
  buf->st_ctime = v7;
LABEL_46:
  buf->st_mode = __dtoxmode(attr: findbuf.dwFileAttributes, name: dwHighDateTime);
  buf->st_nlink = 1;
  buf->st_size = findbuf.nFileSizeLow;
  if ( findbuf.nFileSizeHigh != 0 )
  {
    retval = -1;
    buf->st_size = 0;
  }
  buf->st_ino = 0;
  buf->st_gid = 0;
  buf->st_uid = 0;
  buf->st_dev = drive - 1;
  buf->st_rdev = drive - 1;
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EE273
// Name: public: std::__non_rtti_object::__non_rtti_object(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::__non_rtti_object *__thiscall std::__non_rtti_object::__non_rtti_object(
        std::__non_rtti_object *this,
        const char *_Message)
{
  std::bad_typeid::bad_typeid(this, _Message);
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::__non_rtti_object::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EE316
// Name: public: std::__non_rtti_object::__non_rtti_object(class std::__non_rtti_object const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::__non_rtti_object *__thiscall std::__non_rtti_object::__non_rtti_object(
        std::__non_rtti_object *this,
        const std::__non_rtti_object *that)
{
  std::bad_typeid::bad_typeid(this, that);
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::__non_rtti_object::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EE333
// Name: void __near * operator new(unsigned int,struct std::nothrow_t const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int count)
{
  return MemAlloc_Alloc(nSize: count);
}

//------------------------------------------------------------------------------
// Address: 0x102EE362
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax
  wchar_t drvstr[4]; // [esp+0h] [ebp-Ch] BYREF

  result = true;
  if ( drive != 0 )
  {
    drvstr[0] = drive + 64;
    wcscpy(&drvstr[1], L":\\");
    if ( GetDriveTypeW(lpRootPathName: drvstr) <= 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EE3BC
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  int v3; // ebx
  char *v5; // edi
  signed int FullPathNameA; // eax
  unsigned __int8 *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  int count; // [esp+8h] [ebp-4h]

  v3 = drive;
  if ( drive != 0 )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  else
  {
    v3 = _getdrive();
  }
  v5 = pnbuf;
  if ( pnbuf != nullptr )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v3 != 0 )
  {
    LOBYTE(drive) = v3 + 64;
    strcpy((char *)&drive + 1, ":.");
  }
  else
  {
    strcpy((char *)&drive, ".");
  }
  FullPathNameA = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: count, lpBuffer: v5, lpFilePart: &pname);
  if ( FullPathNameA == 0 )
    goto LABEL_24;
  if ( v5 == nullptr )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v7 = calloc(count: maxlen, size: 1u);
    v5 = (char *)v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return nullptr;
    }
    v8 = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: maxlen, lpBuffer: (LPSTR)v7, lpFilePart: &pname);
    if ( v8 != 0 && v8 < maxlen )
      return v5;
LABEL_24:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return nullptr;
  }
  if ( FullPathNameA < count )
    return v5;
  *_errno() = 34;
  *v5 = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102EE4E0
// Name: __getcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getcwd(char *pnbuf, int maxlen)
{
  char *retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = _getdcwd_nolock(drive: 0, pnbuf, maxlen);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EE529
// Name: __access_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access_s(const char *path, int amode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  if ( path == nullptr || (amode & 0xFFFFFFF9) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  FileAttributesA = GetFileAttributesA(lpFileName: path);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return *_errno();
  }
  if ( (FileAttributesA & 0x10) == 0 && (FileAttributesA & 1) != 0 && (amode & 2) != 0 )
  {
    *__doserrno() = 5;
    *_errno() = 13;
    return *_errno();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102EE5A8
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl _getenv_helper_nolock(char *option)
{
  unsigned __int8 **v1; // esi
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax

  v1 = (unsigned __int8 **)_environ;
  if ( __env_initialized == 0 )
    return nullptr;
  if ( _environ != nullptr
    || _wenviron != nullptr && __wtomb_environ() == 0 && (v1 = (unsigned __int8 **)_environ, _environ != nullptr) )
  {
    if ( option != nullptr )
    {
      strlen(buf: (unsigned __int8 *)option);
      v4 = v3;
      while ( *v1 != nullptr )
      {
        strlen(buf: *v1);
        if ( v5 > v4 && (*v1)[v4] == 61 && _mbsnbicoll(s1: *v1, s2: (const unsigned __int8 *)option, n: v4) == 0 )
          return (const char *)&(*v1)[v4 + 1];
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102EE62F
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv(char *option)
{
  char *retval; // [esp+14h] [ebp-1Ch]

  if ( option != nullptr && strnlen(str: option, maxsize: 0x7FFFu) < 0x7FFF )
  {
    _lock(locknum: 7);
    retval = (char *)_getenv_helper_nolock(option);
    _unlock(locknum: 7);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EE6A9
// Name: __dupenv_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _dupenv_s(char **pBuffer, unsigned int *pBufferSizeInTChars, char *varname)
{
  int v3; // esi
  unsigned __int8 *v4; // eax
  const char *v5; // ebx
  int v6; // eax
  unsigned int v7; // esi
  unsigned __int8 *v8; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  v3 = 0;
  if ( pBuffer != nullptr )
  {
    *pBuffer = nullptr;
    if ( pBufferSizeInTChars != nullptr )
      *pBufferSizeInTChars = 0;
    if ( varname != nullptr )
    {
      v4 = (unsigned __int8 *)_getenv_helper_nolock(option: varname);
      v5 = (const char *)v4;
      if ( v4 == nullptr )
        goto LABEL_3;
      strlen(buf: v4);
      v7 = v6 + 1;
      v8 = calloc(count: v6 + 1, size: 1u);
      *pBuffer = (char *)v8;
      if ( v8 != nullptr )
      {
        if ( strcpy_s(_Dst: (char *)v8, _SizeInBytes: v7, _Src: v5) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        if ( pBufferSizeInTChars != nullptr )
          *pBufferSizeInTChars = v7;
        retval = 0;
      }
      else
      {
        *_errno() = 12;
        retval = *_errno();
      }
LABEL_14:
      _unlock(locknum: 7);
      return retval;
    }
  }
  v3 = 22;
  *_errno() = 22;
  _invalid_parameter_noinfo();
LABEL_3:
  retval = v3;
  goto LABEL_14;
}

//------------------------------------------------------------------------------
// Address: 0x102EE780
// Name: __spawnv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnv(int modeflag, const char *pathname, const char *const *argv)
{
  if ( pathname != nullptr && *pathname != 0 && argv != nullptr && *argv != nullptr && **(_BYTE **)argv != 0 )
    return _spawnve(mode: modeflag, name: pathname, argv, envp: nullptr);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102EE7D0
// Name: _longjmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn longjmp(jmp_buf Buf, int Value)
{
  int *__attribute__((__org_typedef(jmp_buf))) v2; // ebx
  void *v3; // esi
  void (__stdcall *v4)(int *__attribute__((__org_typedef(jmp_buf)))); // eax
  _EXCEPTION_RECORD ExceptionRecord; // [esp+0h] [ebp-50h] BYREF

  v2 = Buf;
  ExceptionRecord.ExceptionCode = -2147483610;
  memset(&ExceptionRecord.ExceptionFlags, 0, 16);
  v3 = (void *)Buf[6];
  if ( v3 != (void *)__readfsdword(0) )
  {
    RtlUnwind(TargetFrame: v3, TargetIp: &lj_return, &ExceptionRecord, ReturnValue: nullptr);
    v2 = Buf;
  }
  if ( v3 != nullptr )
  {
    if ( _rt_probe_read4(ptr: (unsigned int *)v2 + 8) != 0 && v2[8] == 1447244336 )
    {
      v4 = (void (__stdcall *)(int *__attribute__((__org_typedef(jmp_buf)))))v2[9];
      if ( v4 != nullptr )
        v4(a1: v2);
    }
    else
    {
      _local_unwind2(
        a1: v3,
        a2: v2[7],
        a3: ExceptionRecord.ExceptionCode,
        __return_address: ExceptionRecord.ExceptionFlags,
        a5: ExceptionRecord.ExceptionRecord,
        a6: ExceptionRecord.ExceptionAddress);
    }
  }
  _NLG_Notify(a1: 0);
  ((void (*)(void))v2[5])();
}

//------------------------------------------------------------------------------
// Address: 0x102EE890
// Name: __setjmp3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _setjmp3@<eax>(
        int a1@<ebx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        _DWORD *a5,
        int a6,
        _EXCEPTION_REGISTRATION_RECORD *a7,
        int a8,
        ...)
{
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  unsigned int v9; // ecx
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, a8);
  *a5 = a2;
  a5[1] = a1;
  a5[2] = a3;
  a5[3] = a4;
  a5[4] = &retaddr;
  a5[5] = retaddr;
  a5[8] = 1447244336;
  a5[9] = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  a5[6] = ExceptionList;
  if ( ExceptionList == (_EXCEPTION_REGISTRATION_RECORD *)-1 )
  {
    a5[7] = -1;
  }
  else if ( a6 != 0 && (ExceptionList = a7, a5[9] = a7, a6 != 1) )
  {
    a5[7] = a8;
    v9 = a6 - 2;
    if ( a6 != 2 )
    {
      if ( v9 > 6 )
        v9 = 6;
      qmemcpy(a5 + 10, va, 4 * v9);
    }
  }
  else
  {
    a5[7] = ExceptionList[1].Handler;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102EE90B
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  const char *v3; // esi
  int v5; // eax
  _flt *v6; // eax
  _flt *v7; // ecx
  int flags; // eax
  long double v9; // st7
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-34h] BYREF
  long double tmp; // [esp+1Ch] [ebp-24h]
  _flt answerstruct; // [esp+24h] [ebp-1Ch] BYREF

  v3 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
       ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v3] & 8
       : _isctype_l(c: *(unsigned __int8 *)v3, mask: 8, plocinfo: &_loc_update.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  v6 = _fltin2(flt: &answerstruct, str: v3, _Locale: &_loc_update.localeinfo);
  v7 = v6;
  if ( endptr != nullptr )
    *endptr = (char *)&v3[v6->nbytes];
  flags = v6->flags;
  if ( (v7->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr != nullptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v9 = _HUGE;
    if ( *v3 == 45 )
      v9 = -_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v9 = 0.0, 0.0 != v7->dval) )
  {
    tmp = v7->dval;
    goto LABEL_24;
  }
  tmp = v9;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x102EEA2E
// Name: _strtod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl strtod(char *nptr, char **endptr)
{
  return _strtod_l(nptr, endptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EEA45
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int printf(const char *format, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  int v4; // edi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    v2 = __iob_func();
    _lock_file2(i: 1, s: &v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: &v7[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EEAEC
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x102EEB02
// Name: _fprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fprintf(_iobuf *str, const char *format, ...)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v6; // esi
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v3 = fileno(stream: str);
      if ( v3 == -1 || v3 == -2 )
        v4 = &__badioinfo;
      else
        v4 = &__pioinfo[v3 >> 5][v3 & 0x1F];
      if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
        || (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v6 = _stbuf(str);
      retval = _output_l(stream: str, format, plocinfo: nullptr, argptr);
      _ftbuf(flag: v6, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EEC0E
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x102EEC14
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int osfhnd; // eax

  v0 = _nstream;
  if ( _nstream == 0 )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)calloc(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)calloc(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&dststart )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_1042CF80;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_1042CFE0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102EECC5
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pMem: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x102EECE5
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_1042D1D0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(locknum: pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EED26
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(locknum: i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EED58
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_1042D1D0 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(locknum: pf - _iob + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EED94
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(locknum: i + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EEED6
// Name: _seh_longjmp_unwind(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _seh_longjmp_unwind(int a1)
{
  int v2; // [esp+0h] [ebp-4h]

  return _local_unwind2(a1: *(_DWORD *)(a1 + 24), a2: *(_DWORD *)(a1 + 28), a3: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102EEEF1
// Name: void (*_set_se_translator(void (*)(unsigned int,struct _EXCEPTION_POINTERS __near *)))(unsigned int,struct _EXCEPTION_POINTERS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl _set_se_translator(
        void (__cdecl *pNew)(unsigned int, _EXCEPTION_POINTERS *)))(unsigned int, _EXCEPTION_POINTERS *)
{
  void *translator; // esi

  translator = _getptd()->_translator;
  _getptd()->_translator = pNew;
  return (void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *))translator;
}

//------------------------------------------------------------------------------
// Address: 0x102EEF15
// Name: __toupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _toupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+14h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 2;
    }
    else
    {
      v4 = _isctype_l(c, mask: 2, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pcumap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x102EF02B
// Name: _toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl toupper(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _toupper_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 97 <= 0x19 )
    return c - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EF060
// Name: __aulldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldiv(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v3; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = v6 / v5;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    return v8;
  }
  else
  {
    LODWORD(v3) = a1;
    HIDWORD(v3) = HIDWORD(a1) % (unsigned int)a2;
    return v3 / (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EF0C8
// Name: __gmtime64_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _gmtime64_s(tm *ptm, const __int64 *timp)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int v8; // edi
  int v9; // eax
  int v10; // et0
  int v11; // et0
  unsigned int v12; // edi
  unsigned int v13; // et0
  int *v14; // edx
  int tm_yday; // eax
  int i; // ecx
  int v17; // ecx
  signed __int64 v18; // kr28_8
  __int64 caltim; // [esp+4h] [ebp-10h]
  unsigned int caltim_4; // [esp+8h] [ebp-Ch]
  int v21; // [esp+Ch] [ebp-8h]
  int islpyr; // [esp+10h] [ebp-4h]
  int tmptim; // [esp+1Ch] [ebp+8h]

  islpyr = 0;
  if ( ptm == nullptr || (memset(dst: (int)ptm, value: (unsigned __int8 *)0xFF, count: sizeof(tm)), timp == nullptr) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  v4 = *(_DWORD *)timp;
  v5 = *((_DWORD *)timp + 1);
  LODWORD(caltim) = *(_DWORD *)timp;
  if ( *timp < -43200 || __SPAIR64__(v5, v4) > 0x7934126CFLL )
  {
    *_errno() = 22;
    return 22;
  }
  v6 = __SPAIR64__(v5, v4) / 31536000;
  v21 = v6 + 69;
  tmptim = v6 + 70;
  v7 = 86400 * (-365LL * (int)v6 - (((int)v6 + 369) / 400 - ((int)v6 + 69) / 100 + ((int)v6 + 69) / 4 - 17));
  HIDWORD(caltim) = *((_DWORD *)timp + 1);
  v8 = v7 + caltim;
  HIDWORD(caltim) = (unsigned __int64)(v7 + caltim) >> 32;
  if ( caltim >= 0 )
  {
    if ( (tmptim % 4 != 0 || tmptim % 100 == 0) && (tmptim + 1900) % 400 != 0 )
      goto LABEL_18;
    goto LABEL_17;
  }
  v9 = v21;
  v10 = (__PAIR64__(HIDWORD(caltim), v8) + 31536000) >> 32;
  v8 += 31536000;
  HIDWORD(caltim) = v10;
  tmptim = v21;
  if ( v21 % 4 == 0 )
  {
    if ( v21 % 100 != 0 )
    {
LABEL_13:
      v11 = (__PAIR64__(HIDWORD(caltim), v8) + 86400) >> 32;
      v8 += 86400;
      HIDWORD(caltim) = v11;
LABEL_17:
      islpyr = 1;
      goto LABEL_18;
    }
    v9 = v21;
  }
  if ( (v9 + 1900) % 400 == 0 )
    goto LABEL_13;
LABEL_18:
  ptm->tm_year = tmptim;
  ptm->tm_yday = __SPAIR64__(HIDWORD(caltim), v8) / 86400;
  v13 = (-86400LL * (int)(__SPAIR64__(HIDWORD(caltim), v8) / 86400) + __PAIR64__(HIDWORD(caltim), v8)) >> 32;
  v12 = __SPAIR64__(HIDWORD(caltim), v8) % 86400;
  caltim_4 = v13;
  v14 = _lpdays;
  if ( islpyr == 0 )
    v14 = _days;
  tm_yday = ptm->tm_yday;
  for ( i = 1; v14[i] < tm_yday; ++i )
    ;
  v17 = i - 1;
  ptm->tm_mon = v17;
  ptm->tm_mday = tm_yday - v14[v17];
  ptm->tm_wday = (int)(*timp / 86400 + 4) % 7;
  ptm->tm_hour = __SPAIR64__(caltim_4, v12) / 3600;
  v18 = -3600LL * (int)(__SPAIR64__(caltim_4, v12) / 3600) + __PAIR64__(caltim_4, v12);
  ptm->tm_min = v18 / 60;
  ptm->tm_sec = v18 % 60;
  ptm->tm_isdst = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102EF301
// Name: __gmtime64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tm *__cdecl _gmtime64(const __int64 *timp)
{
  tm *result; // eax

  result = (tm *)__getgmtimebuf();
  if ( result != nullptr )
    return _gmtime64_s(ptm: result, timp) == 0 ? result : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EF328
// Name: _make__time64_t
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl make__time64_t(int ultflag)
{
  tm *tb; // ecx
  tm *v2; // edi
  int result; // eax
  int tm_mon; // eax
  int v5; // ecx
  __int64 v6; // rax
  bool v7; // cf
  int v8; // esi
  __int64 v9; // kr08_8
  int tm_isdst; // eax
  int v11; // eax
  int timezone; // [esp+10h] [ebp-44h] BYREF
  int dstbias; // [esp+14h] [ebp-40h] BYREF
  __int64 tmptm2; // [esp+18h] [ebp-3Ch]
  int v15; // [esp+20h] [ebp-34h]
  __int64 tmptm1; // [esp+24h] [ebp-30h] BYREF
  tm tbtemp; // [esp+2Ch] [ebp-28h] BYREF

  v2 = tb;
  dstbias = 0;
  timezone = 0;
  if ( tb == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  tmptm1 = tb->tm_year;
  if ( (unsigned __int64)((int)tmptm1 - 69LL) > 0x408 )
    goto err_mktime;
  tm_mon = tb->tm_mon;
  if ( (unsigned int)tm_mon >= 0xC )
  {
    v5 = tm_mon % 12;
    v6 = tm_mon / 12;
    v7 = __CFADD__((_DWORD)v6, (_DWORD)tmptm1);
    LODWORD(tmptm1) = v6 + tmptm1;
    v2->tm_mon = v5;
    HIDWORD(tmptm1) += HIDWORD(v6) + v7;
    if ( v5 < 0 )
    {
      v7 = (_DWORD)tmptm1 != 0;
      LODWORD(tmptm1) = tmptm1 - 1;
      v2->tm_mon = v5 + 12;
      HIDWORD(tmptm1) = v7 + HIDWORD(tmptm1) - 1;
    }
    if ( (unsigned __int64)(tmptm1 - 69) > 0x408 )
      goto err_mktime;
  }
  v8 = v2->tm_mon;
  tmptm2 = _days[v8];
  if ( (tmptm1 % 4 == 0 && tmptm1 % 100 != 0 || (tmptm1 + 1900) % 400 == 0) && v8 > 1 )
    ++tmptm2;
  v9 = (tmptm1 - 1) / 4 + v2->tm_mday + (tmptm1 + 299) / 400 - (tmptm1 - 1) / 100;
  v15 = HIDWORD(v9);
  tmptm1 = 60 * (60 * (24 * (tmptm2 + 365 * tmptm1 + v9 - 25567) + v2->tm_hour) + v2->tm_min) + v2->tm_sec;
  if ( ultflag != 0 )
  {
    __tzset();
    if ( _get_dstbias(_Daylight_savings_bias: &dstbias) != 0 || _get_timezone(_Timezone: &timezone) != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    tmptm1 += timezone;
    if ( _localtime64_s(ptm: &tbtemp, ptime: &tmptm1) != 0 )
      goto err_mktime;
    tm_isdst = v2->tm_isdst;
    if ( tm_isdst <= 0 && (tm_isdst >= 0 || tbtemp.tm_isdst <= 0) )
      goto LABEL_24;
    tmptm1 += dstbias;
    v11 = _localtime64_s(ptm: &tbtemp, ptime: &tmptm1);
  }
  else
  {
    v11 = _gmtime64_s(ptm: &tbtemp, timp: &tmptm1);
  }
  if ( v11 == 0 )
  {
LABEL_24:
    result = tmptm1;
    *v2 = tbtemp;
    return result;
  }
err_mktime:
  *_errno() = 22;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102EF5D7
// Name: __mktime64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mktime64()
{
  return make__time64_t(ultflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102EF5E9
// Name: ___ascii_stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __ascii_stricmp(const char *dst, const char *src)
{
  int v4; // eax
  int v5; // ecx

  do
  {
    v4 = *(unsigned __int8 *)dst++;
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
    v5 = *(unsigned __int8 *)src++;
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  while ( v4 != 0 && v4 == v5 );
  return v4 - v5;
}

//------------------------------------------------------------------------------
// Address: 0x102EF622
// Name: __stricmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _stricmp_l(const char *dst, const char *src, localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  const char *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( dst != nullptr )
  {
    v4 = src;
    if ( src != nullptr )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
          v6 = _tolower_l(c: *(unsigned __int8 *)v4++, plocinfo: &_loc_update.localeinfo);
        }
        while ( v5 != 0 && v5 == v6 );
        result = v5 - v6;
      }
      else
      {
        result = __ascii_stricmp(dst, src);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EF6E2
// Name: __stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _stricmp(const char *dst, const char *src)
{
  if ( __locale_changed != 0 )
    return _stricmp_l(dst, src, plocinfo: nullptr);
  if ( dst != nullptr && src != nullptr )
    return __ascii_stricmp(dst, src);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x102EF729
// Name: _tzset_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void tzset_nolock()
{
  unsigned __int8 *v0; // eax
  unsigned __int8 *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // edi
  int v7; // edi
  char **v8; // edi
  const char *v9; // esi
  char v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // esi
  int negdiff; // [esp+14h] [ebp-38h]
  UINT lc_cp; // [esp+18h] [ebp-34h]
  int defused; // [esp+1Ch] [ebp-30h] BYREF
  int nochange; // [esp+20h] [ebp-2Ch]
  int dstbias; // [esp+24h] [ebp-28h] BYREF
  int daylight; // [esp+28h] [ebp-24h] BYREF
  char **tzname; // [esp+2Ch] [ebp-20h]
  int timezone[6]; // [esp+30h] [ebp-1Ch] BYREF
  int v23; // [esp+48h] [ebp-4h]

  negdiff = 0;
  nochange = 0;
  timezone[0] = 0;
  daylight = 0;
  dstbias = 0;
  _lock(locknum: 7);
  v23 = 0;
  tzname = __tzname();
  if ( _get_timezone(_Timezone: timezone) != 0
    || _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0 )
  {
LABEL_12:
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  lc_cp = ___lc_codepage_func();
  tzapiused = 0;
  dstend.yr = -1;
  dststart.yr = -1;
  v0 = (unsigned __int8 *)_getenv_helper_nolock(option: "TZ");
  v1 = v0;
  if ( v0 == nullptr || *v0 == 0 )
  {
    if ( lastTZ != nullptr )
    {
      free(pMem: lastTZ);
      lastTZ = nullptr;
    }
    if ( GetTimeZoneInformation(lpTimeZoneInformation: &tzinfo) != -1 )
    {
      tzapiused = 1;
      timezone[0] = 60 * tzinfo.Bias;
      if ( tzinfo.StandardDate.wMonth != 0 )
        timezone[0] = 60 * tzinfo.StandardBias + 60 * tzinfo.Bias;
      if ( tzinfo.DaylightDate.wMonth != 0 && tzinfo.DaylightBias != 0 )
      {
        daylight = 1;
        dstbias = 60 * (tzinfo.DaylightBias - tzinfo.StandardBias);
      }
      else
      {
        daylight = 0;
        dstbias = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.StandardName,
             cchWideChar: -1,
             lpMultiByteStr: *tzname,
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        **tzname = 0;
      }
      else
      {
        (*tzname)[63] = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.DaylightName,
             cchWideChar: -1,
             lpMultiByteStr: tzname[1],
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        *tzname[1] = 0;
      }
      else
      {
        tzname[1][63] = 0;
      }
    }
    goto LABEL_30;
  }
  if ( lastTZ != nullptr )
  {
    strcmp(str1: v0, str2: (unsigned __int8 *)lastTZ);
    if ( v2 == 0 )
    {
LABEL_30:
      nochange = 1;
      goto LABEL_31;
    }
    if ( lastTZ != nullptr )
      free(pMem: lastTZ);
  }
  strlen(buf: v1);
  lastTZ = (char *)MemAlloc_Alloc(nSize: v3 + 1);
  if ( lastTZ == nullptr )
    goto LABEL_30;
  strlen(buf: v1);
  if ( strcpy_s(_Dst: lastTZ, _SizeInBytes: v4 + 1, _Src: (const char *)v1) != 0 )
    goto LABEL_12;
LABEL_31:
  v5 = timezone[0];
  *__timezone() = v5;
  v6 = daylight;
  *__daylight() = v6;
  v7 = dstbias;
  *__dstbias() = v7;
  v23 = -2;
  _unlock(locknum: 7);
  if ( nochange == 0 )
  {
    v8 = tzname;
    if ( strncpy_s(_Dst: *tzname, _SizeInBytes: 0x40u, _Src: (const char *)v1, _Count: 3u) != 0 )
      goto LABEL_12;
    v9 = (const char *)(v1 + 3);
    if ( *v9 == 45 )
    {
      negdiff = 1;
      ++v9;
    }
    timezone[0] = 3600 * atol(nptr: v9);
    while ( 1 )
    {
      v10 = *v9;
      if ( *v9 != 43 && (v10 < 48 || v10 > 57) )
        break;
      ++v9;
    }
    if ( *v9 == 58 )
    {
      v11 = atol(nptr: ++v9);
      timezone[0] += 60 * v11;
      while ( *v9 >= 48 && *v9 <= 57 )
        ++v9;
      if ( *v9 == 58 )
      {
        v12 = atol(nptr: ++v9);
        timezone[0] += v12;
        while ( *v9 >= 48 && *v9 <= 57 )
          ++v9;
      }
    }
    if ( negdiff != 0 )
      timezone[0] = -timezone[0];
    daylight = *v9;
    if ( daylight != 0 )
    {
      if ( strncpy_s(_Dst: v8[1], _SizeInBytes: 0x40u, _Src: v9, _Count: 3u) != 0 )
        goto LABEL_12;
    }
    else
    {
      *v8[1] = 0;
    }
    v13 = timezone[0];
    *__timezone() = v13;
    v14 = daylight;
    *__daylight() = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EFC33
// Name: _isindst_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isindst_nolock@<eax>(tm *tb@<edi>)
{
  int result; // eax
  int tm_year; // edx
  int v3; // eax
  int v4; // ecx
  int tm_yday; // edx
  int v6; // eax
  int endmonth; // [esp+4h] [ebp-Ch]
  int endweek; // [esp+8h] [ebp-8h]
  int daylight; // [esp+Ch] [ebp-4h] BYREF

  daylight = 0;
  result = _get_daylight(_Daylight: &daylight);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( daylight != 0 )
  {
    tm_year = tb->tm_year;
    if ( tm_year != dststart.yr || tm_year != dstend.yr )
    {
      if ( tzapiused != 0 )
      {
        if ( tzinfo.DaylightDate.wYear != 0 )
          cvtdate(
            month: tzinfo.DaylightDate.wMonth,
            hour: tzinfo.DaylightDate.wHour,
            trantype: 1,
            datetype: 0,
            year: tm_year,
            week: 0,
            dayofweek: 0,
            date: tzinfo.DaylightDate.wDay,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        else
          cvtdate(
            month: tzinfo.DaylightDate.wMonth,
            hour: tzinfo.DaylightDate.wHour,
            trantype: 1,
            datetype: 1,
            year: tm_year,
            week: tzinfo.DaylightDate.wDay,
            dayofweek: tzinfo.DaylightDate.wDayOfWeek,
            date: 0,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        if ( tzinfo.StandardDate.wYear != 0 )
          cvtdate(
            month: tzinfo.StandardDate.wMonth,
            hour: tzinfo.StandardDate.wHour,
            trantype: 0,
            datetype: 0,
            year: tb->tm_year,
            week: 0,
            dayofweek: 0,
            date: tzinfo.StandardDate.wDay,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
        else
          cvtdate(
            month: tzinfo.StandardDate.wMonth,
            hour: tzinfo.StandardDate.wHour,
            trantype: 0,
            datetype: 1,
            year: tb->tm_year,
            week: tzinfo.StandardDate.wDay,
            dayofweek: tzinfo.StandardDate.wDayOfWeek,
            date: 0,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
      }
      else
      {
        v3 = 3;
        v4 = 2;
        endmonth = 11;
        endweek = 1;
        if ( tm_year < 107 )
        {
          v3 = 4;
          v4 = 1;
          endmonth = 10;
          endweek = 5;
        }
        cvtdate(
          month: v3,
          hour: 2,
          trantype: 1,
          datetype: 1,
          year: tm_year,
          week: v4,
          dayofweek: 0,
          date: 0,
          min: 0,
          sec: 0,
          msec: 0);
        cvtdate(
          month: endmonth,
          hour: 2,
          trantype: 0,
          datetype: 1,
          year: tb->tm_year,
          week: endweek,
          dayofweek: 0,
          date: 0,
          min: 0,
          sec: 0,
          msec: 0);
      }
    }
    tm_yday = tb->tm_yday;
    if ( dststart.yd >= dstend.yd )
    {
      if ( tm_yday < dstend.yd || tm_yday > dststart.yd )
        return 1;
      if ( tm_yday <= dstend.yd || tm_yday >= dststart.yd )
        goto LABEL_28;
    }
    else if ( tm_yday >= dststart.yd && tm_yday <= dstend.yd )
    {
      if ( tm_yday > dststart.yd && tm_yday < dstend.yd )
        return 1;
LABEL_28:
      v6 = 1000 * (tb->tm_sec + 60 * (tb->tm_min + 60 * tb->tm_hour));
      if ( tm_yday == dststart.yd )
        return v6 >= dststart.ms;
      else
        return v6 < dstend.ms;
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EFE0A
// Name: ___tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __tzset()
{
  if ( first_time == 0 )
  {
    _lock(locknum: 6);
    if ( first_time == 0 )
    {
      tzset_nolock();
      ++first_time;
    }
    _unlock(locknum: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EFE59
// Name: __tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _tzset()
{
  _lock(locknum: 6);
  tzset_nolock();
  _unlock(locknum: 6);
}

//------------------------------------------------------------------------------
// Address: 0x102EFE91
// Name: __isindst
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isindst(tm *tb)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 6);
  retval = isindst_nolock(tb);
  _unlock(locknum: 6);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EFED2
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _CRT_INIT(void *hDllHandle, unsigned int dwReason, void *lpreserved)
{
  vgui::PropertyPage *v4; // ecx
  vgui::PropertyPage *v5; // ecx
  unsigned __int8 *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, unsigned __int8 *); // eax
  unsigned int v9; // [esp-8h] [ebp-30h]
  unsigned __int8 *v10; // [esp-4h] [ebp-2Ch]

  if ( dwReason == 1 )
  {
    if ( !_heap_init() )
      return 0;
    if ( _mtinit() == 0 )
    {
LABEL_5:
      CColorBalanceUIPanel::Init(this: v4);
      return 0;
    }
    _RTC_Initialize();
    _acmdln = GetCommandLineA();
    _aenvptr = (char *)__crtGetEnvironmentStringsA();
    if ( _ioinit() < 0 )
    {
LABEL_7:
      _mtterm();
      goto LABEL_5;
    }
    if ( _setargv() < 0 || _setenvp() < 0 || _cinit(initFloatingPrecision: 0) != 0 )
    {
      _ioterm();
      goto LABEL_7;
    }
    ++_proc_attached;
  }
  else if ( dwReason != 0 )
  {
    if ( dwReason == 2 )
    {
      __set_flsgetvalue();
      v6 = calloc(count: 1u, size: 0x214u);
      v7 = (_tiddata *)v6;
      if ( v6 == nullptr )
        return 0;
      v10 = v6;
      v9 = __flsindex;
      v8 = (int (__stdcall *)(unsigned int, unsigned __int8 *))DecodePointer(Ptr: gpFlsSetValue);
      if ( v8(a1: v9, a2: v10) == 0 )
      {
        free(pMem: v7);
        return 0;
      }
      _initptd(ptd: v7, ptloci: nullptr);
      v7->_tid = GetCurrentThreadId();
      v7->_thandle = -1;
    }
    else if ( dwReason == 3 )
    {
      _freeptd(ptd: nullptr);
    }
  }
  else
  {
    if ( _proc_attached <= 0 )
      return 0;
    --_proc_attached;
    if ( _C_Termination_Done == 0 )
      _cexit();
    if ( lpreserved == nullptr )
    {
      _ioterm();
      _mtterm();
      CColorBalanceUIPanel::Init(this: v5);
      if ( __flsindex != -1 )
        _mtterm();
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F0036
// Name: __DllMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _DllMainCRTStartup(void *lpreserved, unsigned int dwReason, HINSTANCE hDllHandle)
{
  BOOL v5; // eax
  int retcode; // [esp+10h] [ebp-1Ch]

  if ( dwReason == 0 && _proc_attached == 0
    || (dwReason == 1 || dwReason == 2) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
  {
    return 0;
  }
  v5 = DllMain(hinstDLL: hDllHandle, fdwReason: dwReason, lpvReserved: lpreserved);
  retcode = v5;
  if ( dwReason == 1 && !v5 )
  {
    DllMain(hinstDLL: hDllHandle, fdwReason: 0, lpvReserved: lpreserved);
    _CRT_INIT(hDllHandle, dwReason: 0, lpreserved);
  }
  if ( (dwReason == 0 || dwReason == 3) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
    return 0;
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x102F012C
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    __security_init_cookie();
  return _DllMainCRTStartup(lpreserved: lpReserved, dwReason: fdwReason, hDllHandle: hinstDLL);
}

//------------------------------------------------------------------------------
// Address: 0x102F014F
// Name: ___libm_sse2_sin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_sin@<st0>(__m128i a1@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(a1, 3) & 0x7FF0) != 0x7FF0 )
    return sin(X: *(double *)a1.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F0307
// Name: ___libm_sse2_acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_acos()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102F07AA
// Name: ___libm_sse2_pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_pow()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102F1222
// Name: ___libm_sse2_atan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_atan()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102F1434
// Name: ___libm_sse2_log
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __libm_sse2_log(__m128d a1@<xmm0>)
{
  __m128i v1; // xmm5
  int v2; // eax
  __m128d v3; // xmm6
  unsigned int v4; // ecx
  __m128d v5; // xmm0
  double i; // [esp+4h] [ebp-8h]

  for ( i = a1.m128d_f64[0]; ; a1.m128d_f64[0] = i * *(double *)Two52 )
  {
    v1 = (__m128i)a1;
    a1 = _mm_or_pd(_mm_and_pd(_mm_unpacklo_pd(a1, a1), *(__m128d *)emask), *(__m128d *)One);
    v2 = _mm_extract_epi16((__m128i)_mm_add_pd(*(__m128d *)Magic, a1), 0) & 0x7F0;
    v3 = _mm_and_pd(*(__m128d *)hi_mask, a1);
    a1.m128d_f64[1] = _mm_add_pd(
                        _mm_mul_pd(_mm_sub_pd(a1, v3), *(__m128d *)((char *)B_Tbl + v2)),
                        _mm_sub_pd(_mm_mul_pd(v3, *(__m128d *)((char *)B_Tbl + v2)), *(__m128d *)One)).m128d_f64[1];
    v4 = (_mm_extract_epi16(_mm_srli_epi64(v1, 0x34u), 0) & 0xFFF) - 1;
    if ( v4 <= 0x7FD )
      break;
    v5.m128d_f64[0] = i;
    if ( _mm_extract_epi16((__m128i)_mm_cmpeq_sd(*(__m128d *)Zero, v5), 0) != 0 || v4 != -1 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F165A
// Name: ___libm_sse2_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_exp@<st0>(__m128d a1@<xmm0>)
{
  __m128d v1; // xmm0
  int v2; // eax
  __m128i v3; // xmm7
  __m128d v4; // xmm1
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  __m128d v8; // xmm0
  __m128d v9; // xmm2
  __m128d v10; // xmm4
  __m128d v11; // xmm0
  __m128d v12; // xmm0
  __m128i v13; // xmm2
  double v14; // xmm0_8
  int v15; // edx
  int v16; // eax
  double result; // st7
  double v18; // [esp+8h] [ebp-16h]

  v1 = _mm_unpacklo_pd(a1, a1);
  v2 = _mm_extract_epi16((__m128i)v1, 3) & 0x7FFF;
  if ( ((v2 - 15504) | (unsigned int)(16527 - v2)) < 0x80000000 )
  {
    v3 = (__m128i)_mm_add_pd(_mm_mul_pd(*(__m128d *)cv_0, v1), *(__m128d *)Shifter_0);
    v4 = _mm_sub_pd((__m128d)v3, *(__m128d *)Shifter_0);
    v5 = _mm_cvtsi128_si32(v3);
    v6 = 4 * (v5 & 0x3F);
    v7 = v5 >> 6;
    v8 = _mm_sub_pd(_mm_sub_pd(v1, _mm_mul_pd(*(__m128d *)&cv_0[4], v4)), _mm_mul_pd(*(__m128d *)&cv_0[8], v4));
    v9 = *(__m128d *)&Tbl_addr_0[v6];
    v10 = _mm_mul_pd(*(__m128d *)&cv_0[12], v8);
    v4.m128d_f64[0] = v8.m128d_f64[0];
    v11 = _mm_mul_pd(v8, v8);
    v11.m128d_f64[0] = v11.m128d_f64[0] * v11.m128d_f64[0];
    v12 = _mm_mul_pd(v11, _mm_add_pd(*(__m128d *)&cv_0[16], v10));
    v4.m128d_f64[0] = v4.m128d_f64[0] + v9.m128d_f64[0] + v12.m128d_f64[0];
    v13 = (__m128i)_mm_or_pd(
                     _mm_unpackhi_pd(v9, v9),
                     (__m128d)_mm_slli_epi64(
                                _mm_add_epi64(
                                  _mm_and_si128(v3, _mm_load_si128((const __m128i *)mmask)),
                                  _mm_load_si128((const __m128i *)bias)),
                                0x2Eu));
    v14 = _mm_unpackhi_pd(v12, v12).m128d_f64[0] + v4.m128d_f64[0];
    if ( (unsigned int)(v7 + 894) > 0x77C )
    {
      v15 = v7;
      v16 = v7 >> 1;
      *(_QWORD *)&v18 = _mm_andnot_si128(_mm_load_si128((const __m128i *)emask_0), v13).m128i_u64[0]
                      | (_mm_cvtsi32_si128(v16 + 1023).m128i_u64[0] << 52);
      return (v14 * v18 + v18) * COERCE_DOUBLE(_mm_cvtsi32_si128(v15 - v16 + 1023).m128i_u64[0] << 52);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F1870
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (abstr & 0x30000) != 0 )
  {
    if ( (abstr & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F18FE
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = abstr & 0x3000000;
  switch ( v4 )
  {
    case 0x1000000u:
      result |= 0x8040u;
      break;
    case 0x2000000u:
      result |= 0x40u;
      break;
    case 0x3000000u:
      result |= 0x8000u;
      break;
    default:
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F199E
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // cx
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  unsigned int v23; // [esp+14h] [ebp-Ch]
  __int16 oldCw; // [esp+1Ch] [ebp-4h]
  unsigned int newabs; // [esp+2Ch] [ebp+Ch]

  v2 = 0;
  if ( (oldCw & 1) != 0 )
    v2 = 16;
  if ( (oldCw & 4) != 0 )
    v2 |= 8u;
  if ( (oldCw & 8) != 0 )
    v2 |= 4u;
  if ( (oldCw & 0x10) != 0 )
    v2 |= 2u;
  if ( (oldCw & 0x20) != 0 )
    v2 |= 1u;
  if ( (oldCw & 2) != 0 )
    v2 |= 0x80000u;
  v3 = oldCw & 0xC00;
  if ( (oldCw & 0xC00) != 0 )
  {
    switch ( v3 )
    {
      case 1024:
        v2 |= 0x100u;
        break;
      case 2048:
        v2 |= 0x200u;
        break;
      case 3072:
        v2 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (oldCw & 0x300) != 0 )
  {
    if ( (oldCw & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (oldCw & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  newabs = result;
  if ( result != v2 )
  {
    v6 = hw_cw(abstr: result);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    newabs = v8;
    result = v8;
  }
  v10 = 0;
  if ( __sse2_available != 0 )
  {
    v11 = _mm_getcsr();
    if ( (v11 & 0x80u) != 0 )
      v10 = 16;
    if ( (v11 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v10 |= 0x80000u;
    v12 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v12 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v13 = (v11 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v15 = newctrl & mask & 0x308031F | v10 & ~(mask & 0x308031F);
    if ( v15 == v10 )
    {
      v16 = v10;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v18 = 0;
      if ( (v17 & 0x80u) != 0 )
        v18 = 16;
      if ( (v17 & 0x200) != 0 )
        v18 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v18 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v18 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v18 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v18 |= 0x80000u;
      v19 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v19 )
        {
          case 8192:
            v18 |= 0x100u;
            break;
          case 16384:
            v18 |= 0x200u;
            break;
          case 24576:
            v18 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v20 = (v17 & 0x8040) - 64;
      if ( v20 != 0 )
      {
        v21 = v20 - 32704;
        if ( v21 != 0 )
        {
          if ( v21 == 64 )
            v18 |= 0x1000000u;
        }
        else
        {
          v18 |= 0x3000000u;
        }
      }
      else
      {
        v18 |= 0x2000000u;
      }
      v16 = v18;
    }
    v22 = newabs ^ v16;
    result = newabs | v16;
    if ( (v22 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F1CB0
// Name: __controlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _controlfp(unsigned int newctrl, unsigned int mask)
{
  unsigned int v2; // edi
  int v3; // edx
  unsigned int v4; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // dx
  int v18; // ecx
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  unsigned int v22; // [esp+10h] [ebp-10h]
  unsigned int v23; // [esp+18h] [ebp-8h]

  v2 = mask & 0xFFF7FFFF;
  v3 = 0;
  if ( (mask & 1) != 0 )
    v3 = 16;
  if ( (mask & 4) != 0 )
    v3 |= 8u;
  if ( (mask & 8) != 0 )
    v3 |= 4u;
  if ( (mask & 0x10) != 0 )
    v3 |= 2u;
  if ( (mask & 0x20) != 0 )
    v3 |= 1u;
  if ( (mask & 2) != 0 )
    v3 |= 0x80000u;
  v4 = mask & 0xC00;
  if ( (mask & 0xC00) != 0 )
  {
    switch ( v4 )
    {
      case 0x400u:
        v3 |= 0x100u;
        break;
      case 0x800u:
        v3 |= 0x200u;
        break;
      case 0xC00u:
        v3 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (mask & 0x300) != 0 )
  {
    if ( (mask & 0x300) == 0x200 )
      v3 |= 0x10000u;
  }
  else
  {
    v3 |= 0x20000u;
  }
  if ( (mask & 0x1000) != 0 )
    v3 |= 0x40000u;
  result = newctrl & v2 | v3 & ~v2;
  v22 = result;
  if ( result != v3 )
  {
    v6 = hw_cw(abstr: newctrl & v2 | v3 & ~v2);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    result = v8;
    v22 = v8;
  }
  v10 = 0;
  if ( __sse2_available != 0 )
  {
    v11 = _mm_getcsr();
    if ( (v11 & 0x80u) != 0 )
      v10 = 16;
    if ( (v11 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v10 |= 0x80000u;
    v12 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v12 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v13 = (v11 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v15 = newctrl & mask & 0x300031F | v10 & ~(mask & 0x300031F);
    if ( v15 == v10 )
    {
      v16 = v10;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v16 = 0;
      if ( (v17 & 0x80u) != 0 )
        v16 = 16;
      if ( (v17 & 0x200) != 0 )
        v16 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v16 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v16 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v16 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v16 |= 0x80000u;
      v18 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v18 )
        {
          case 8192:
            v16 |= 0x100u;
            break;
          case 16384:
            v16 |= 0x200u;
            break;
          case 24576:
            v16 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v19 = (v17 & 0x8040) - 64;
      if ( v19 != 0 )
      {
        v20 = v19 - 32704;
        if ( v20 != 0 )
        {
          if ( v20 == 64 )
            v16 |= 0x1000000u;
        }
        else
        {
          v16 |= 0x3000000u;
        }
      }
      else
      {
        v16 |= 0x2000000u;
      }
    }
    v21 = v22 ^ v16;
    result = v22 | v16;
    if ( (v21 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F1FC5
// Name: void __ArrayUnwind(void __near *,unsigned int,int,void (*)(void __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __ArrayUnwind(char *ptr, unsigned int size, int count, void (*pDtor)(void))
{
  while ( --count >= 0 )
  {
    ptr -= size;
    pDtor();
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F20EB
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(unsigned int cookie)
{
  if ( cookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x102F2100
// Name: __ftol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __usercall _ftol@<edx:eax>(double a1@<st0>)
{
  return (__int64)a1;
}

//------------------------------------------------------------------------------
// Address: 0x102F2130
// Name: __CIsqrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x102F21EA
// Name: __mbscmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbscmp_l(unsigned __int8 *s1, unsigned __int8 *s2, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // esi
  __int16 v5; // cx
  __int16 v6; // ax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = s1;
  if ( s1 != nullptr )
  {
    v4 = s2;
    if ( s2 != nullptr )
    {
      if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
      {
        while ( 1 )
        {
          v5 = *v3++;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v5 + 1] & 4) != 0 )
          {
            if ( *v3 != 0 )
              v5 = *v3++ | (unsigned __int16)(v5 << 8);
            else
              v5 = 0;
          }
          v6 = *v4++;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) != 0 )
          {
            if ( *v4 != 0 )
              v6 = *v4++ | (unsigned __int16)(v6 << 8);
            else
              v6 = 0;
          }
          if ( v6 != v5 )
            break;
          if ( v5 == 0 )
          {
            if ( _loc_update.updated )
              _loc_update.ptd->_ownlocale &= ~2u;
            return;
          }
        }
      }
      else
      {
        strcmp(str1: s1, str2: s2);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F22E9
// Name: __mbscmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbscmp(unsigned __int8 *s1, unsigned __int8 *s2)
{
  _mbscmp_l(s1, s2, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F2300
// Name: __ungetc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ungetc_nolock(int ch, _iobuf *str)
{
  int v2; // eax
  ioinfo *v3; // ecx
  ioinfo *v4; // eax
  int flag; // eax
  char *v7; // eax
  int v8; // eax

  if ( (str->_flag & 0x40) == 0 )
  {
    v2 = fileno(stream: str);
    if ( v2 == -1 || v2 == -2 )
      v3 = &__badioinfo;
    else
      v3 = &__pioinfo[v2 >> 5][v2 & 0x1F];
    if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0
      || (v2 == -1 || v2 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v2 >> 5][v2 & 0x1F]), *((char *)v4 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( ch == -1 )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( str->_base == nullptr )
    _getbuf(str);
  if ( str->_ptr == str->_base )
  {
    if ( str->_cnt != 0 )
      return -1;
    ++str->_ptr;
  }
  v7 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v7 != (_BYTE)ch )
    {
      str->_ptr = v7 + 1;
      return -1;
    }
  }
  else
  {
    *v7 = ch;
  }
  v8 = str->_flag;
  ++str->_cnt;
  str->_flag = v8 & 0xFFFFFFEE | 1;
  return (unsigned __int8)ch;
}

//------------------------------------------------------------------------------
// Address: 0x102F23E3
// Name: _ungetc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ungetc(int ch, _iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ungetc_nolock(ch, str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F244C
// Name: _fgetc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fgetc(_iobuf *stream)
{
  int v2; // eax
  ioinfo *v3; // ecx
  ioinfo *v4; // eax
  int v6; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    if ( (stream->_flag & 0x40) == 0 )
    {
      v2 = fileno(stream);
      if ( v2 == -1 || v2 == -2 )
        v3 = &__badioinfo;
      else
        v3 = &__pioinfo[v2 >> 5][v2 & 0x1F];
      if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0
        || (v2 == -1 || v2 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v2 >> 5][v2 & 0x1F]), *((char *)v4 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      if ( --stream->_cnt < 0 )
        v6 = _filbuf(str: stream);
      else
        v6 = *(unsigned __int8 *)stream->_ptr++;
      retval = v6;
    }
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F2540
// Name: _ferror
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ferror(_iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_flag & 0x20;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return 0;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10047E40
// Name: public: virtual unsigned int CSosOperatorFloat::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorFloat::GetSize(CSosOperatorEntryTime *this)
{
  return 36;
}

//------------------------------------------------------------------------------
// Address: 0x100486A0
// Name: enum SOFunc1Type_t S_GetFunc1Type(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SOFunc1Type_t __cdecl S_GetFunc1Type(const char *pValueString)
{
  SOFunc1Type_t result; // eax

  result = V_strcasecmp(s1: pValueString, s2: "none");
  if ( result != SO_FUNC1_NONE )
  {
    if ( V_strcasecmp(s1: pValueString, s2: "sin") != 0 )
    {
      if ( V_strcasecmp(s1: pValueString, s2: "asin") != 0 )
      {
        if ( V_strcasecmp(s1: pValueString, s2: "cos") != 0 )
        {
          if ( V_strcasecmp(s1: pValueString, s2: "acos") != 0 )
          {
            if ( V_strcasecmp(s1: pValueString, s2: "tan") != 0 )
            {
              if ( V_strcasecmp(s1: pValueString, s2: "atan") != 0 )
              {
                if ( V_strcasecmp(s1: pValueString, s2: "sinh") != 0 )
                {
                  if ( V_strcasecmp(s1: pValueString, s2: "asinh") != 0 )
                  {
                    if ( V_strcasecmp(s1: pValueString, s2: "cosh") != 0 )
                    {
                      if ( V_strcasecmp(s1: pValueString, s2: "acosh") != 0 )
                      {
                        if ( V_strcasecmp(s1: pValueString, s2: "tanh") != 0 )
                        {
                          if ( V_strcasecmp(s1: pValueString, s2: "atanh") != 0 )
                          {
                            if ( V_strcasecmp(s1: pValueString, s2: "exp") != 0 )
                            {
                              if ( V_strcasecmp(s1: pValueString, s2: "expm1") != 0 )
                              {
                                if ( V_strcasecmp(s1: pValueString, s2: "exp2") != 0 )
                                {
                                  if ( V_strcasecmp(s1: pValueString, s2: "log") != 0 )
                                  {
                                    if ( V_strcasecmp(s1: pValueString, s2: "log2") != 0 )
                                    {
                                      if ( V_strcasecmp(s1: pValueString, s2: "log1p") != 0 )
                                      {
                                        if ( V_strcasecmp(s1: pValueString, s2: "log10") != 0 )
                                        {
                                          if ( V_strcasecmp(s1: pValueString, s2: "logb") != 0 )
                                          {
                                            if ( V_strcasecmp(s1: pValueString, s2: "fabs") != 0 )
                                            {
                                              if ( V_strcasecmp(s1: pValueString, s2: "sqrt") != 0 )
                                              {
                                                if ( V_strcasecmp(s1: pValueString, s2: "erf") != 0 )
                                                {
                                                  if ( V_strcasecmp(s1: pValueString, s2: "erfc") != 0 )
                                                  {
                                                    if ( V_strcasecmp(s1: pValueString, s2: "gamma") != 0 )
                                                    {
                                                      if ( V_strcasecmp(s1: pValueString, s2: "lgamma") != 0 )
                                                      {
                                                        if ( V_strcasecmp(s1: pValueString, s2: "ceil") != 0 )
                                                        {
                                                          if ( V_strcasecmp(s1: pValueString, s2: "floor") != 0 )
                                                          {
                                                            if ( V_strcasecmp(s1: pValueString, s2: "rint") != 0 )
                                                            {
                                                              if ( V_strcasecmp(s1: pValueString, s2: "nearbyint") != 0 )
                                                              {
                                                                if ( V_strcasecmp(s1: pValueString, s2: "rintol") != 0 )
                                                                {
                                                                  if ( V_strcasecmp(s1: pValueString, s2: "round") != 0 )
                                                                  {
                                                                    if ( V_strcasecmp(s1: pValueString, s2: "roundtol") != 0 )
                                                                      return V_strcasecmp(s1: pValueString, s2: "trunc") != 0
                                                                           ? 0
                                                                           : 34;
                                                                    else
                                                                      return SO_FUNC1_ROUNDTOL;
                                                                  }
                                                                  else
                                                                  {
                                                                    return SO_FUNC1_ROUND;
                                                                  }
                                                                }
                                                                else
                                                                {
                                                                  return SO_FUNC1_RINTOL;
                                                                }
                                                              }
                                                              else
                                                              {
                                                                return SO_FUNC1_NEARBYINT;
                                                              }
                                                            }
                                                            else
                                                            {
                                                              return SO_FUNC1_RINT;
                                                            }
                                                          }
                                                          else
                                                          {
                                                            return SO_FUNC1_FLOOR;
                                                          }
                                                        }
                                                        else
                                                        {
                                                          return SO_FUNC1_CEIL;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        return SO_FUNC1_LGAMMA;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      return SO_FUNC1_GAMMA;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    return SO_FUNC1_ERFC;
                                                  }
                                                }
                                                else
                                                {
                                                  return SO_FUNC1_ERF;
                                                }
                                              }
                                              else
                                              {
                                                return SO_FUNC1_SQRT;
                                              }
                                            }
                                            else
                                            {
                                              return SO_FUNC1_FABS;
                                            }
                                          }
                                          else
                                          {
                                            return SO_FUNC1_LOGB;
                                          }
                                        }
                                        else
                                        {
                                          return SO_FUNC1_LOG10;
                                        }
                                      }
                                      else
                                      {
                                        return SO_FUNC1_LOG1P;
                                      }
                                    }
                                    else
                                    {
                                      return SO_FUNC1_LOG2;
                                    }
                                  }
                                  else
                                  {
                                    return SO_FUNC1_LOG;
                                  }
                                }
                                else
                                {
                                  return SO_FUNC1_EXP2;
                                }
                              }
                              else
                              {
                                return SO_FUNC1_EXPM1;
                              }
                            }
                            else
                            {
                              return SO_FUNC1_EXP;
                            }
                          }
                          else
                          {
                            return SO_FUNC1_ATANH;
                          }
                        }
                        else
                        {
                          return SO_FUNC1_TANH;
                        }
                      }
                      else
                      {
                        return SO_FUNC1_ACOSH;
                      }
                    }
                    else
                    {
                      return SO_FUNC1_COSH;
                    }
                  }
                  else
                  {
                    return SO_FUNC1_ASINH;
                  }
                }
                else
                {
                  return SO_FUNC1_SINH;
                }
              }
              else
              {
                return SO_FUNC1_ATAN;
              }
            }
            else
            {
              return SO_FUNC1_TAN;
            }
          }
          else
          {
            return SO_FUNC1_ACOS;
          }
        }
        else
        {
          return SO_FUNC1_COS;
        }
      }
      else
      {
        return SO_FUNC1_ASIN;
      }
    }
    else
    {
      return SO_FUNC1_SIN;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048A40
// Name: void S_PrintFunc1Type(enum SOFunc1Type_t,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_PrintFunc1Type(SOFunc1Type_t nType, int nLevel)
{
  const char *v2; // esi

  switch ( nType )
  {
    case SO_FUNC1_SIN:
      v2 = "sin";
      break;
    case SO_FUNC1_ASIN:
      v2 = "asin";
      break;
    case SO_FUNC1_COS:
      v2 = "cos";
      break;
    case SO_FUNC1_ACOS:
      v2 = "acos";
      break;
    case SO_FUNC1_TAN:
      v2 = "tan";
      break;
    case SO_FUNC1_ATAN:
      v2 = "atan";
      break;
    case SO_FUNC1_SINH:
      v2 = "sinh";
      break;
    case SO_FUNC1_ASINH:
      v2 = "asinh";
      break;
    case SO_FUNC1_COSH:
      v2 = "cosh";
      break;
    case SO_FUNC1_ACOSH:
      v2 = "acosh";
      break;
    case SO_FUNC1_TANH:
      v2 = "tanh";
      break;
    case SO_FUNC1_ATANH:
      v2 = "atanh";
      break;
    case SO_FUNC1_EXP:
      v2 = "exp";
      break;
    case SO_FUNC1_EXPM1:
      v2 = "expm1";
      break;
    case SO_FUNC1_EXP2:
      v2 = "exp2";
      break;
    case SO_FUNC1_LOG:
      v2 = "log";
      break;
    case SO_FUNC1_LOG2:
      v2 = "log2";
      break;
    case SO_FUNC1_LOG1P:
      v2 = "log1p";
      break;
    case SO_FUNC1_LOG10:
      v2 = "log10";
      break;
    case SO_FUNC1_LOGB:
      v2 = "logb";
      break;
    case SO_FUNC1_FABS:
      v2 = "fabs";
      break;
    case SO_FUNC1_SQRT:
      v2 = "sqrt";
      break;
    case SO_FUNC1_ERF:
      v2 = "erf";
      break;
    case SO_FUNC1_ERFC:
      v2 = "erfc";
      break;
    case SO_FUNC1_GAMMA:
      v2 = "gamma";
      break;
    case SO_FUNC1_LGAMMA:
      v2 = "lgamma";
      break;
    case SO_FUNC1_CEIL:
      v2 = "ceil";
      break;
    case SO_FUNC1_FLOOR:
      v2 = "floor";
      break;
    case SO_FUNC1_RINT:
      v2 = "rint";
      break;
    case SO_FUNC1_NEARBYINT:
      v2 = "nearbyint";
      break;
    case SO_FUNC1_RINTOL:
      v2 = "rintol";
      break;
    case SO_FUNC1_ROUND:
      v2 = "round";
      break;
    case SO_FUNC1_ROUNDTOL:
      v2 = "roundtol";
      break;
    case SO_FUNC1_TRUNC:
      v2 = "trunc";
      break;
    default:
      v2 = "none";
      break;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*sFunction: %s\n",
      nLevel,
      "    ",
      v2);
}

//------------------------------------------------------------------------------
// Address: 0x10048C50
// Name: enum SOOpType_t S_GetExpressionType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SOOpType_t __cdecl S_GetExpressionType(const char *pValueString)
{
  SOOpType_t result; // eax

  result = V_strcasecmp(s1: pValueString, s2: "none");
  if ( result != SO_OP_NONE )
  {
    if ( V_strcasecmp(s1: pValueString, s2: "set") != 0 )
    {
      if ( V_strcasecmp(s1: pValueString, s2: "add") != 0 )
      {
        if ( V_strcasecmp(s1: pValueString, s2: "sub") != 0 )
        {
          if ( V_strcasecmp(s1: pValueString, s2: "mult") != 0 )
          {
            if ( V_strcasecmp(s1: pValueString, s2: "div") != 0 )
            {
              if ( V_strcasecmp(s1: pValueString, s2: "mod") != 0 )
              {
                if ( V_strcasecmp(s1: pValueString, s2: "max") != 0 )
                {
                  if ( V_strcasecmp(s1: pValueString, s2: "min") != 0 )
                  {
                    if ( V_strcasecmp(s1: pValueString, s2: "invert") != 0 )
                    {
                      if ( V_strcasecmp(s1: pValueString, s2: "greater_than") != 0 )
                      {
                        if ( V_strcasecmp(s1: pValueString, s2: "less_than") != 0 )
                        {
                          if ( V_strcasecmp(s1: pValueString, s2: "greater_than_or_equal") != 0 )
                          {
                            if ( V_strcasecmp(s1: pValueString, s2: "less_than_or_equal") != 0 )
                            {
                              if ( V_strcasecmp(s1: pValueString, s2: "equals") != 0 )
                                return V_strcasecmp(s1: pValueString, s2: "invert_scale") != 0 ? 0 : 15;
                              else
                                return SO_OP_EQ;
                            }
                            else
                            {
                              return SO_OP_LTOE;
                            }
                          }
                          else
                          {
                            return SO_OP_GTOE;
                          }
                        }
                        else
                        {
                          return SO_OP_LT;
                        }
                      }
                      else
                      {
                        return SO_OP_GT;
                      }
                    }
                    else
                    {
                      return SO_OP_INV;
                    }
                  }
                  else
                  {
                    return SO_OP_MIN;
                  }
                }
                else
                {
                  return SO_OP_MAX;
                }
              }
              else
              {
                return SO_OP_MOD;
              }
            }
            else
            {
              return SO_OP_DIV;
            }
          }
          else
          {
            return SO_OP_MULT;
          }
        }
        else
        {
          return SO_OP_SUB;
        }
      }
      else
      {
        return SO_OP_ADD;
      }
    }
    else
    {
      return SO_OP_SET;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048E00
// Name: void S_PrintOpType(enum SOOpType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_PrintOpType(SOOpType_t nType, int nLevel)
{
  const char *v2; // esi

  switch ( nType )
  {
    case SO_OP_SET:
      v2 = "set";
      break;
    case SO_OP_ADD:
      v2 = "add";
      break;
    case SO_OP_SUB:
      v2 = "sub";
      break;
    case SO_OP_MULT:
      v2 = "mult";
      break;
    case SO_OP_DIV:
      v2 = "div";
      break;
    case SO_OP_MAX:
      v2 = "max";
      break;
    case SO_OP_MIN:
      v2 = "min";
      break;
    case SO_OP_INV:
      v2 = "invert";
      break;
    case SO_OP_GT:
      v2 = "greater_than";
      break;
    case SO_OP_LT:
      v2 = "less_than";
      break;
    case SO_OP_GTOE:
      v2 = "greater_than_or_equal";
      break;
    case SO_OP_LTOE:
      v2 = "less_than_or_equal";
      break;
    case SO_OP_EQ:
      v2 = "equals";
      break;
    case SO_OP_INV_SCALE:
      v2 = "invert_scale";
      break;
    default:
      v2 = "none";
      break;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*sOperation: %s\n",
      nLevel,
      "    ",
      v2);
}

//------------------------------------------------------------------------------
// Address: 0x10048F00
// Name: public: virtual void CSosOperatorFunc1::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFunc1::SetDefaults(CSosOperatorFunc1 *this, _DWORD *pVoidMem)
{
  pVoidMem[5] = 0;
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[6] = 0;
  *((_BYTE *)pVoidMem + 28) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10048F30
// Name: public: virtual void CSosOperatorFunc1::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFunc1::Print(
        CSosOperatorFunc1 *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *v5; // eax

  CSosOperator::PrintBaseParams(this, (CSosOperator_t *)pVoidMem, pStack, nOpIndex, nLevel);
  S_PrintFunc1Type(nType: *((SOFunc1Type_t *)pVoidMem + 6), nLevel);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v5 = "true";
    if ( *((_BYTE *)pVoidMem + 28) == 0 )
      v5 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*snormalize_trig: %s\n",
      nLevel,
      "    ",
      v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048FB0
// Name: public: virtual void CSosOperatorFunc1::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFunc1::ParseKV(
        CSosOperatorFunc1 *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "function") != 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "normalize_trig") != 0 )
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
        }
        else
        {
          LOBYTE(pVoidMem[2].m_flExecuteOffset[0]) = V_strcasecmp(s1: v7, s2: "true") == 0;
        }
      }
      else
      {
        LODWORD(pVoidMem[2].m_flExecute[0]) = S_GetFunc1Type(pValueString: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100490C0
// Name: public: virtual void CSosOperatorFloat::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFloat::SetDefaults(CSosOperatorFloat *this, _DWORD *pVoidMem)
{
  pVoidMem[7] = 0;
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[5] = 0;
  pVoidMem[6] = -1;
  pVoidMem[8] = 4;
}

//------------------------------------------------------------------------------
// Address: 0x100490F0
// Name: float ceil(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ceil(float _X)
{
  return ceil(X: _X);
}

//------------------------------------------------------------------------------
// Address: 0x10049110
// Name: public: virtual void CSosOperatorFloat::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFloat::Print(
        CSosOperatorFloat *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, (CSosOperator_t *)pVoidMem, pStack, nOpIndex, nLevel);
  S_PrintOpType(nType: *((SOOpType_t *)pVoidMem + 8), nLevel);
}

//------------------------------------------------------------------------------
// Address: 0x10049140
// Name: public: virtual void CSosOperatorFloat::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFloat::ParseKV(
        CSosOperatorFloat *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "apply") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        *(_DWORD *)&pVoidMem[2].m_bExecuteOnce = S_GetExpressionType(pValueString: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049210
// Name: public: virtual void CSosOperatorVec3::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorVec3::SetDefaults(CSosOperatorVec3 *this, _DWORD *pVoidMem)
{
  pVoidMem[15] = 0;
  pVoidMem[16] = 0;
  pVoidMem[17] = 0;
  pVoidMem[3] = 0;
  pVoidMem[6] = -1;
  pVoidMem[4] = 0;
  pVoidMem[7] = -1;
  pVoidMem[5] = 0;
  pVoidMem[8] = -1;
  pVoidMem[9] = 0;
  pVoidMem[12] = -1;
  pVoidMem[10] = 0;
  pVoidMem[13] = -1;
  pVoidMem[11] = 0;
  pVoidMem[14] = -1;
  pVoidMem[18] = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10049270
// Name: public: virtual void CSosOperatorVec3::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorVec3::Print(
        CSosOperatorVec3 *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, (CSosOperator_t *)pVoidMem, pStack, nOpIndex, nLevel);
  S_PrintOpType(nType: *((SOOpType_t *)pVoidMem + 18), nLevel);
}

//------------------------------------------------------------------------------
// Address: 0x100492A0
// Name: public: virtual void CSosOperatorVec3::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorVec3::ParseKV(
        CSosOperatorVec3 *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "apply") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        LODWORD(pVoidMem[6].m_flExecute[0]) = S_GetExpressionType(pValueString: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049370
// Name: public: virtual void CSosOperatorSpeakers::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpeakers::SetDefaults(CSosOperatorSpeakers *this, _DWORD *pVoidMem)
{
  pVoidMem[27] = 0;
  pVoidMem[28] = 0;
  pVoidMem[29] = 0;
  pVoidMem[30] = 0;
  pVoidMem[31] = 0;
  pVoidMem[32] = 0;
  pVoidMem[3] = 0;
  pVoidMem[9] = -1;
  pVoidMem[4] = 0;
  pVoidMem[10] = -1;
  pVoidMem[5] = 0;
  pVoidMem[11] = -1;
  pVoidMem[6] = 0;
  pVoidMem[12] = -1;
  pVoidMem[7] = 0;
  pVoidMem[13] = -1;
  pVoidMem[8] = 0;
  pVoidMem[14] = -1;
  pVoidMem[15] = 0;
  pVoidMem[21] = -1;
  pVoidMem[16] = 0;
  pVoidMem[22] = -1;
  pVoidMem[17] = 0;
  pVoidMem[23] = -1;
  pVoidMem[18] = 0;
  pVoidMem[24] = -1;
  pVoidMem[19] = 0;
  pVoidMem[25] = -1;
  pVoidMem[20] = 0;
  pVoidMem[26] = -1;
  pVoidMem[33] = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10049410
// Name: public: virtual void CSosOperatorSpeakers::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpeakers::Print(
        CSosOperatorSpeakers *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, (CSosOperator_t *)pVoidMem, pStack, nOpIndex, nLevel);
  S_PrintOpType(nType: *((SOOpType_t *)pVoidMem + 33), nLevel);
}

//------------------------------------------------------------------------------
// Address: 0x10049440
// Name: public: virtual void CSosOperatorSpeakers::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpeakers::ParseKV(
        CSosOperatorSpeakers *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  interval_t v8; // [esp+4h] [ebp-34h] BYREF
  interval_t v9; // [esp+Ch] [ebp-2Ch] BYREF
  interval_t v10; // [esp+14h] [ebp-24h] BYREF
  interval_t v11; // [esp+1Ch] [ebp-1Ch] BYREF
  interval_t v12; // [esp+24h] [ebp-14h] BYREF
  interval_t interval; // [esp+2Ch] [ebp-Ch] BYREF
  CSosOperator *v14; // [esp+34h] [ebp-4h]
  KeyValues *pParams; // [esp+48h] [ebp+10h]

  v14 = this;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pOpKeys);
  pParams = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
      v7 = String;
      if ( Name != nullptr
        && *Name != 0
        && String != nullptr
        && *String != 0
        && CSosOperator::BaseParseKV(this: v14, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "apply") != 0 )
        {
          if ( V_strcasecmp(s1: Name, s2: "left_front") != 0 )
          {
            if ( V_strcasecmp(s1: Name, s2: "right_front") != 0 )
            {
              if ( V_strcasecmp(s1: Name, s2: "left_rear") != 0 )
              {
                if ( V_strcasecmp(s1: Name, s2: "right_rear") != 0 )
                {
                  if ( V_strcasecmp(s1: Name, s2: "center") != 0 )
                  {
                    if ( V_strcasecmp(s1: Name, s2: "lfe") != 0 )
                    {
                      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
                        _LoggingSystem_Log(
                          a1: LOG_SND_OPERATORS,
                          a2: 1,
                          a3: "Error: Unknown sound operator attribute %s\n",
                          Name);
                    }
                    else
                    {
                      v8 = ReadInterval(pString: v7);
                      *(float *)&pVoidMem[2].m_bExecuteOnce = RandomInterval(interval: &v8);
                    }
                  }
                  else
                  {
                    v9 = ReadInterval(pString: v7);
                    *(float *)pVoidMem[2].m_flExecuteOffset = RandomInterval(interval: &v9);
                  }
                }
                else
                {
                  v10 = ReadInterval(pString: v7);
                  pVoidMem[2].m_flExecute[0] = RandomInterval(interval: &v10);
                }
              }
              else
              {
                v11 = ReadInterval(pString: v7);
                *(float *)&pVoidMem[1].m_bExecuteOnce = RandomInterval(interval: &v11);
              }
            }
            else
            {
              v12 = ReadInterval(pString: v7);
              *(float *)pVoidMem[1].m_flExecuteOffset = RandomInterval(interval: &v12);
            }
          }
          else
          {
            interval = ReadInterval(pString: v7);
            pVoidMem[1].m_flExecute[0] = RandomInterval(&interval);
          }
        }
        else
        {
          LODWORD(pVoidMem[11].m_flExecute[0]) = S_GetExpressionType(pValueString: v7);
        }
      }
      pParams = KeyValues::GetNextKey(this: pParams);
      if ( pParams == nullptr )
        break;
      FirstSubKey = pParams;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049660
// Name: public: virtual void CSosOperatorSourceDistance::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceDistance::SetDefaults(CSosOperatorSourceDistance *this, _DWORD *pVoidMem)
{
  pVoidMem[9] = 1065353216;
  pVoidMem[3] = 0;
  pVoidMem[6] = -1;
  pVoidMem[4] = 0;
  pVoidMem[7] = -1;
  pVoidMem[5] = 0;
  pVoidMem[8] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100496A0
// Name: public: virtual void CSosOperatorSourceDistance::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceDistance::ParseKV(
        CSosOperatorDelta *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // edi
  const char *Name; // esi
  const char *String; // eax

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0
      && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049740
// Name: public: virtual void CSosOperatorFacing::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFacing::SetDefaults(CSosOperatorFacing *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[6] = -1;
  pVoidMem[4] = 0;
  pVoidMem[7] = -1;
  pVoidMem[5] = 0;
  pVoidMem[8] = -1;
  pVoidMem[9] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049770
// Name: public: virtual void CSosOperatorRemapValue::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorRemapValue::SetDefaults(CSosOperatorRemapValue *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[5] = 1036831949;
  pVoidMem[6] = -1;
  pVoidMem[7] = 0;
  pVoidMem[8] = -1;
  pVoidMem[9] = 1065353216;
  pVoidMem[10] = -1;
  pVoidMem[11] = 0;
  pVoidMem[12] = -1;
  pVoidMem[13] = 0;
  *((_WORD *)pVoidMem + 28) = 257;
}

//------------------------------------------------------------------------------
// Address: 0x100497D0
// Name: public: virtual void CSosOperatorRemapValue::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorRemapValue::ParseKV(
        CSosOperatorRemapValue *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "clamp_range") != 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "default_to_max") != 0 )
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
        }
        else if ( V_strcasecmp(s1: v7, s2: "false") == 0 )
        {
          pVoidMem[4].m_bHasExecuted = false;
        }
      }
      else if ( V_strcasecmp(s1: v7, s2: "false") == 0 )
      {
        pVoidMem[4].m_bExecuteOnce = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100498F0
// Name: public: virtual void CSosOperatorRandom::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorRandom::SetDefaults(CSosOperatorRandom *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[5] = 1065353216;
  pVoidMem[6] = -1;
  pVoidMem[7] = 1065353216;
}

//------------------------------------------------------------------------------
// Address: 0x10049920
// Name: float RemapVal(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapVal(float val, float A, float B, float C, float D)
{
  if ( A != B )
    return C + (D - C) * (val - A) / (B - A);
  if ( (float)(val - B) < 0.0 )
    return C;
  return D;
}

//------------------------------------------------------------------------------
// Address: 0x10049990
// Name: public: virtual void CSosOperatorFunc1::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFunc1::Execute(
        CSosOperatorFunc1 *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  double v7; // st7
  long double v8; // st7
  long double v9; // rt0
  float v10; // xmm0_4
  float flResult; // [esp+10h] [ebp-4h]

  flResult = 0.0;
  switch ( *((_DWORD *)pVoidMem + 6) )
  {
    case 1:
      v7 = sin(pVoidMem[3]);
      goto LABEL_18;
    case 2:
      v7 = asin(pVoidMem[3]);
      goto LABEL_18;
    case 3:
      v7 = cos(pVoidMem[3]);
      goto LABEL_18;
    case 4:
      v7 = acos(pVoidMem[3]);
      goto LABEL_18;
    case 5:
      v7 = tan(pVoidMem[3]);
      goto LABEL_18;
    case 6:
      v7 = atan2(pVoidMem[3], 1.0);
      goto LABEL_18;
    case 7:
      v7 = sinh(pVoidMem[3]);
      goto LABEL_18;
    case 9:
      v7 = cosh(pVoidMem[3]);
      goto LABEL_18;
    case 0xB:
      v7 = tanh(pVoidMem[3]);
      goto LABEL_18;
    case 0xD:
      v8 = pVoidMem[3] * 1.442695040888963407;
      v9 = rint(v8);
      v7 = __FSCALE__(__F2XM1__(v8 - v9) + 1.0, v9);
      goto LABEL_18;
    case 0x10:
      v7 = __FYL2X__(pVoidMem[3], 0.6931471805599453094);
      goto LABEL_18;
    case 0x13:
      v7 = __FYL2X__(pVoidMem[3], 0.3010299956639811952);
      goto LABEL_18;
    case 0x15:
      v7 = fabs(pVoidMem[3]);
      goto LABEL_18;
    case 0x16:
      v7 = sqrt(pVoidMem[3]);
      goto LABEL_18;
    case 0x1B:
      v7 = ceil(_X: pVoidMem[3]);
      goto LABEL_18;
    case 0x1C:
      v7 = floor(X: pVoidMem[3]);
LABEL_18:
      flResult = v7;
      break;
    default:
      break;
  }
  v10 = flResult;
  if ( *((_BYTE *)pVoidMem + 28) != 0 )
    v10 = (float)(flResult + 1.0) * 0.5;
  pVoidMem[5] = v10;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049D20
// Name: public: virtual void CSosOperatorVec3::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorVec3::Execute(
        CSosOperatorVec3 *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  double v6; // st7
  double v7; // st6
  float *v8; // esi
  int i; // ebx
  float v10; // xmm0_4

  v6 = 1.0;
  v7 = 0.0;
  v8 = pVoidMem + 9;
  for ( i = 3; i != 0; --i )
  {
    switch ( *((_DWORD *)pVoidMem + 18) )
    {
      case 1:
        v8[6] = *(v8 - 6);
        break;
      case 2:
        v8[6] = *(v8 - 6) + *v8;
        break;
      case 3:
        v8[6] = *(v8 - 6) - *v8;
        break;
      case 4:
        v8[6] = *(v8 - 6) * *v8;
        break;
      case 5:
        if ( *v8 > 0.0 )
          v8[6] = *(v8 - 6) / *v8;
        break;
      case 6:
        if ( *v8 > 0.0 )
        {
          v8[6] = fmod(*(v8 - 6), *v8);
          v7 = 0.0;
          v6 = 1.0;
        }
        break;
      case 7:
        v10 = *(v8 - 6);
        if ( v10 <= *v8 )
          v10 = *v8;
        goto LABEL_18;
      case 8:
        v10 = *(v8 - 6);
        if ( *v8 > v10 )
LABEL_18:
          v8[6] = v10;
        else
          v8[6] = *v8;
        break;
      case 9:
        v8[6] = 1.0 - *(v8 - 6);
        break;
      case 0xA:
        if ( *(v8 - 6) <= *v8 )
          goto LABEL_24;
        v8[6] = v6;
        break;
      case 0xB:
        if ( *v8 <= *(v8 - 6) )
          goto LABEL_24;
        v8[6] = v6;
        break;
      case 0xC:
        if ( *(v8 - 6) < *v8 )
          goto LABEL_24;
        v8[6] = v6;
        break;
      case 0xD:
        if ( *v8 < *(v8 - 6) )
          goto LABEL_24;
        v8[6] = v6;
        break;
      case 0xE:
        if ( *(v8 - 6) == *v8 )
          v8[6] = v6;
        else
LABEL_24:
          v8[6] = v7;
        break;
      default:
        break;
    }
    ++v8;
  }
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049F00
// Name: public: virtual void CSosOperatorSpeakers::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSpeakers::Execute(
        CSosOperatorSpeakers *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  double v6; // st7
  double v7; // st6
  float *v8; // esi
  int i; // ebx
  float v10; // xmm0_4

  v6 = 1.0;
  v7 = 0.0;
  v8 = pVoidMem + 15;
  for ( i = 6; i != 0; --i )
  {
    switch ( *((_DWORD *)pVoidMem + 33) )
    {
      case 1:
        v8[12] = *(v8 - 12);
        break;
      case 2:
        v8[12] = *(v8 - 12) + *v8;
        break;
      case 3:
        v8[12] = *(v8 - 12) - *v8;
        break;
      case 4:
        v8[12] = *(v8 - 12) * *v8;
        break;
      case 5:
        if ( *v8 > 0.0 )
          v8[12] = *(v8 - 12) / *v8;
        break;
      case 6:
        if ( *v8 > 0.0 )
        {
          v8[12] = fmod(*(v8 - 12), *v8);
          v7 = 0.0;
          v6 = 1.0;
        }
        break;
      case 7:
        v10 = *(v8 - 12);
        if ( v10 <= *v8 )
          v10 = *v8;
        goto LABEL_18;
      case 8:
        v10 = pVoidMem[4];
        if ( *v8 > v10 )
LABEL_18:
          v8[12] = v10;
        else
          v8[12] = *v8;
        break;
      case 9:
        v8[12] = 1.0 - *(v8 - 12);
        break;
      case 0xA:
        if ( *(v8 - 12) <= *v8 )
          goto LABEL_24;
        v8[12] = v6;
        break;
      case 0xB:
        if ( *v8 <= *(v8 - 12) )
          goto LABEL_24;
        v8[12] = v6;
        break;
      case 0xC:
        if ( *(v8 - 12) < *v8 )
          goto LABEL_24;
        v8[12] = v6;
        break;
      case 0xD:
        if ( *v8 < *(v8 - 12) )
          goto LABEL_24;
        v8[12] = v6;
        break;
      case 0xE:
        if ( *(v8 - 12) == *v8 )
          v8[12] = v6;
        else
LABEL_24:
          v8[12] = v7;
        break;
      default:
        break;
    }
    ++v8;
  }
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A0E0
// Name: public: virtual void CSosOperatorSourceDistance::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSosOperatorSourceDistance::Execute(
        CSosOperatorSourceDistance *this@<ecx>,
        int a2@<ebp>,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  bool v7; // zf
  int v8; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  __int128 v14; // xmm0
  __int128 v15; // [esp-10h] [ebp-2Ch] BYREF
  int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  void *v18; // [esp+14h] [ebp-8h]
  void *retaddr; // [esp+1Ch] [ebp+0h]

  v17 = a2;
  v18 = retaddr;
  v7 = !pScratchPad->m_bIsPlayerSound;
  v8 = 2139095039;
  v16 = 2139095039;
  if ( v7 )
  {
    v10 = pVoidMem[3] - pScratchPad->m_vPlayerOrigin[0].x;
    v11 = pVoidMem[4] - pScratchPad->m_vPlayerOrigin[0].y;
    v12 = pVoidMem[5] - pScratchPad->m_vPlayerOrigin[0].z;
  }
  else
  {
    ConvertListenerVectorTo2D(pvforward: (Vector *)((char *)&v15 + 4), pvright: pScratchPad->m_vPlayerRight);
    v10 = *((float *)&v15 + 1) * 12.0;
    v11 = *((float *)&v15 + 2) * 12.0;
    v12 = *((float *)&v15 + 3) * 12.0;
    v8 = v16;
  }
  v13 = (float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v10 * v10);
  v14 = 0;
  *(float *)&v14 = fsqrt(v13);
  v15 = v14;
  if ( *(float *)&v14 < 3.4028235e38 )
    v8 = v15;
  *((_DWORD *)pVoidMem + 9) = v8;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A1E0
// Name: public: virtual void CSosOperatorRemapValue::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorRemapValue::Execute(
        CSosOperatorRemapValue *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float A; // xmm0_4
  float B; // xmm2_4
  float val; // xmm3_4
  float C; // xmm1_4
  float D; // xmm4_4
  float v12; // xmm0_4
  float flResult; // [esp+20h] [ebp-10h]

  A = pVoidMem[3];
  B = pVoidMem[5];
  val = pVoidMem[11];
  C = pVoidMem[7];
  D = pVoidMem[9];
  if ( A > B && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Warning: remap_value operator min arg is greater than max arg\n");
  if ( C > D && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Warning: remap_value operator map min arg is greater than map max arg\n");
  if ( A == B )
  {
    if ( A > val )
    {
      v12 = C;
      goto LABEL_21;
    }
    if ( val > B )
    {
      v12 = D;
      goto LABEL_21;
    }
    if ( *((_BYTE *)pVoidMem + 57) != 0 )
    {
      v12 = D;
      goto LABEL_21;
    }
LABEL_17:
    v12 = C;
    goto LABEL_21;
  }
  if ( C == D )
  {
    v12 = C;
    goto LABEL_21;
  }
  if ( A >= val )
    goto LABEL_17;
  if ( val < B )
  {
    flResult = RemapVal(val, A, B, C, D);
    v12 = flResult;
  }
  else
  {
    v12 = D;
  }
LABEL_21:
  if ( *((_BYTE *)pVoidMem + 56) != 0 )
  {
    if ( C <= v12 )
    {
      if ( v12 > D )
        v12 = D;
    }
    else
    {
      v12 = C;
    }
  }
  pVoidMem[13] = v12;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A390
// Name: public: virtual void CSosOperatorRandom::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorRandom::Execute(
        CSosOperatorRandom *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  pVoidMem[7] = _RandomFloat((IUniformRandomStream *)this, a2: pVoidMem[3], a3: pVoidMem[5]);
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A3E0
// Name: public: virtual void CSosOperatorFacing::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorFacing::Execute(
        CSosOperatorFacing *this,
        void *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  QAngle vAngles; // [esp+4h] [ebp-Ch] BYREF

  if ( pChannel != nullptr )
  {
    vAngles = *(QAngle *)((_BYTE *)pVoidMem + 1);
    *((float *)pVoidMem + 9) = (SND_GetFacingDirection(
                                  pChannel,
                                  vecListenerOrigin: &pScratchPad->m_vBlendedListenerOrigin,
                                  source_angles: &vAngles)
                              + 1.0)
                             * 0.5;
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A4B0
// Name: public: CSosOperatorFunc1::CSosOperatorFunc1(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorFunc1 *__thiscall CSosOperatorFunc1::CSosOperatorFunc1(CSosOperatorFunc1 *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  int v5; // [esp-8h] [ebp-20h]
  CSosOperator::InputData_t src; // [esp+4h] [ebp-14h] BYREF
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorFunc1_vtbl *)&CSosOperatorFunc1::`vftable';
  src.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 20;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  src.m_nCount = 1;
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 16;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input1", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_func1",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004A570
// Name: public: CSosOperatorFloat::CSosOperatorFloat(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorFloat *__thiscall CSosOperatorFloat::CSosOperatorFloat(CSosOperatorFloat *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorFloat_vtbl *)&CSosOperatorFloat::`vftable';
  src.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 28;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 16;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input1", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  src.m_nOffset = 20;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input2", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_float",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004A660
// Name: public: CSosOperatorVec3::CSosOperatorVec3(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorVec3 *__thiscall CSosOperatorVec3::CSosOperatorVec3(CSosOperatorVec3 *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorVec3_vtbl *)&CSosOperatorVec3::`vftable';
  src.m_nCount = 3;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 60;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input1", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  src.m_nOffset = 36;
  src.m_nOffsetOffset = 48;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input2", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_vec3",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004A750
// Name: public: virtual unsigned int CSosOperatorVec3::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorVec3::GetSize(CSosOperatorVec3 *this)
{
  return 76;
}

//------------------------------------------------------------------------------
// Address: 0x1004A760
// Name: public: CSosOperatorSpeakers::CSosOperatorSpeakers(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSpeakers *__thiscall CSosOperatorSpeakers::CSosOperatorSpeakers(CSosOperatorSpeakers *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorSpeakers_vtbl *)&CSosOperatorSpeakers::`vftable';
  src.m_nCount = 6;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 108;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 36;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 6;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input1", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  src.m_nOffset = 60;
  src.m_nOffsetOffset = 84;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 6;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input2", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_speakers",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004A850
// Name: public: virtual unsigned int CSosOperatorSpeakers::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorSpeakers::GetSize(CSosOperatorSpeakers *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x1004A860
// Name: public: CSosOperatorSourceDistance::CSosOperatorSourceDistance(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSourceDistance *__thiscall CSosOperatorSourceDistance::CSosOperatorSourceDistance(
        CSosOperatorSourceDistance *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  int v5; // [esp-8h] [ebp-20h]
  CSosOperator::InputData_t src; // [esp+4h] [ebp-14h] BYREF
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorSourceDistance_vtbl *)&CSosOperatorSourceDistance::`vftable';
  src.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 36;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  src.m_nCount = 3;
  v5 = this->m_vInputs.m_Size;
  src.m_nOffset = 12;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v5,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "calc_source_distance",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004A980
// Name: public: CSosOperatorFacing::CSosOperatorFacing(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorFacing *__thiscall CSosOperatorFacing::CSosOperatorFacing(CSosOperatorFacing *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  int v5; // [esp-8h] [ebp-20h]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-14h] BYREF
  __int16 v7; // [esp+10h] [ebp-8h]
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorFacing_vtbl *)&CSosOperatorFacing::`vftable';
  v7 = 3;
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = 24;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_angles", element: &nIndex);
  v7 = 1;
  v5 = this->m_vOutputs.m_Size;
  outputData.m_Type = 36;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v5,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "calc_angles_facing",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004AA40
// Name: public: virtual unsigned int CSosOperatorSourceDistance::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorSourceDistance::GetSize(CSosOperatorFacing *this)
{
  return 40;
}

//------------------------------------------------------------------------------
// Address: 0x1004AA50
// Name: public: CSosOperatorRemapValue::CSosOperatorRemapValue(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorRemapValue *__thiscall CSosOperatorRemapValue::CSosOperatorRemapValue(CSosOperatorRemapValue *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  int v7; // [esp-8h] [ebp-28h]
  int v8; // [esp-8h] [ebp-28h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-14h] BYREF
  __int16 v10; // [esp+18h] [ebp-8h]
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorRemapValue_vtbl *)&CSosOperatorRemapValue::`vftable';
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 44;
  outputData.m_Type = 48;
  *(_DWORD *)&outputData.m_nCount = 0;
  v10 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  v10 = 1;
  outputData.m_nOffset = 12;
  outputData.m_Type = 16;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_min", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  outputData.m_nOffset = 20;
  outputData.m_Type = 24;
  *(_DWORD *)&outputData.m_nCount = 0;
  v10 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_max", element: &nIndex);
  v7 = this->m_vInputs.m_Size;
  outputData.m_nOffset = 28;
  outputData.m_Type = 32;
  *(_DWORD *)&outputData.m_nCount = 0;
  v10 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v7,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_map_min", element: &nIndex);
  outputData.m_nOffset = 36;
  outputData.m_Type = 40;
  *(_DWORD *)&outputData.m_nCount = 0;
  v10 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: this->m_vInputs.m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_map_max", element: &nIndex);
  v10 = 1;
  v8 = this->m_vOutputs.m_Size;
  outputData.m_Type = 52;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v8,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_remap_float",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004AC10
// Name: public: virtual unsigned int CSosOperatorRemapValue::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorRemapValue::GetSize(CSosOperatorRemapValue *this)
{
  return 60;
}

//------------------------------------------------------------------------------
// Address: 0x1004AC20
// Name: public: CSosOperatorRandom::CSosOperatorRandom(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorRandom *__thiscall CSosOperatorRandom::CSosOperatorRandom(CSosOperatorRandom *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-14h] BYREF
  __int16 v8; // [esp+18h] [ebp-8h]
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorRandom_vtbl *)&CSosOperatorRandom::`vftable';
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = 16;
  *(_DWORD *)&outputData.m_nCount = 0;
  v8 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_min", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  v8 = 1;
  outputData.m_nOffset = 20;
  outputData.m_Type = 24;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_max", element: &nIndex);
  v8 = 1;
  v6 = this->m_vOutputs.m_Size;
  outputData.m_Type = 28;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v6,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "math_random",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EB600
// Name: _ceil
// Source: json
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x102EB640
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128i v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = _mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32(v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns_0, (__m128i)_mm_and_pd((__m128d)v2, *(__m128d *)&S_0));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      a1.m128i_i64[0] = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One_0;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One_0);
      return *(double *)a1.m128i_i64;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EB720
// Name: __allrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allrem(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  unsigned __int64 result; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // eax
  int v9; // ecx
  bool v10; // cf
  unsigned __int64 v11; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 == 0 )
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    result = v4 % (unsigned int)a2;
    if ( v2 - 1 < 0 )
      return result;
    return -(__int64)result;
  }
  v6 = __PAIR64__(v3, a2);
  v7 = a1;
  do
  {
    v6 >>= 1;
    v7 >>= 1;
  }
  while ( HIDWORD(v6) != 0 );
  v8 = v7 / (unsigned int)v6;
  v9 = HIDWORD(a2) * v8;
  v11 = (unsigned int)a2 * (unsigned __int64)v8;
  v10 = __CFADD__(v9, HIDWORD(v11));
  HIDWORD(v11) += v9;
  if ( v10 || v11 > a1 )
    v11 -= a2;
  result = v11 - a1;
  if ( v2 - 1 < 0 )
    return -(__int64)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EB7D2
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  number = 0;
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / ibase;
  pctype = locinfo->pctype;
  v16 = 0xFFFFFFFF % ibase;
  while ( 1 )
  {
    if ( (pctype[v7] & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (pctype[v7] & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v12 <= v16 )
    {
      number = v12 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v14 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v14;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x102EB9FD
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102EBA28
// Name: _strtoul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoul(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 1);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102EBA60
// Name: shortsort_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shortsort_s(
        char *hi@<eax>,
        char *lo,
        unsigned int width,
        int (__cdecl *comp)(void *, const void *, const void *),
        void *context)
{
  char *v5; // edx
  char *v6; // edi
  unsigned int v7; // ecx
  char *v8; // esi
  char *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  int v12; // ecx
  char v13; // dl

  v5 = lo;
  v6 = hi;
  if ( hi > lo )
  {
    v7 = width;
    do
    {
      v8 = &lo[width];
      v9 = v5;
      if ( &lo[width] <= v6 )
      {
        do
        {
          if ( comp(a1: context, a2: v8, a3: v9) > 0 )
            v9 = v8;
          v8 += width;
        }
        while ( v8 <= v6 );
        v7 = width;
        v5 = lo;
      }
      v10 = v7;
      v11 = v6;
      if ( v9 != v6 && v7 != 0 )
      {
        v12 = v9 - v6;
        do
        {
          v13 = v11[v12];
          v11[v12] = *v11;
          *v11++ = v13;
          --v10;
        }
        while ( v10 != 0 );
        v7 = width;
        v5 = lo;
      }
      v6 -= v7;
    }
    while ( v6 > v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EBAF0
// Name: _qsort_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl qsort_s(
        char *base,
        unsigned int num,
        unsigned int width,
        int (__cdecl *comp)(void *, const void *, const void *),
        void *context)
{
  char *v5; // ebx
  unsigned int v6; // esi
  char *v7; // edi
  unsigned int v8; // eax
  char *v9; // esi
  unsigned int v10; // edx
  char *v11; // eax
  int v12; // ecx
  unsigned int v13; // edx
  char *v14; // eax
  int v15; // ecx
  unsigned int v16; // edx
  char *v17; // eax
  int v18; // ecx
  unsigned int v19; // edx
  char *v20; // eax
  int v21; // ecx
  char *v22; // eax
  char *v23; // edx
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  char *v27; // edx
  char *v28; // eax
  char *histk[30]; // [esp+8h] [ebp-100h]
  char *lostk[30]; // [esp+80h] [ebp-88h]
  unsigned int v31; // [esp+F8h] [ebp-10h]
  int stkptr; // [esp+FCh] [ebp-Ch]
  char *hi; // [esp+100h] [ebp-8h]
  char *lo; // [esp+104h] [ebp-4h]
  char base_3; // [esp+113h] [ebp+Bh]
  char base_3a; // [esp+113h] [ebp+Bh]
  char base_3b; // [esp+113h] [ebp+Bh]
  char base_3c; // [esp+113h] [ebp+Bh]

  v5 = base;
  if ( base == nullptr && num != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  v6 = width;
  if ( width == 0 || comp == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  if ( num >= 2 )
  {
    v7 = &base[width * (num - 1)];
    stkptr = 0;
    lo = base;
    hi = v7;
    while ( 1 )
    {
      v8 = (v7 - v5) / v6 + 1;
      if ( v8 <= 8 )
      {
        shortsort_s(hi: v7, lo: v5, width: v6, comp, context);
        goto LABEL_56;
      }
      v9 = &v5[(v8 >> 1) * v6];
      if ( comp(a1: context, a2: v5, a3: v9) > 0 )
      {
        v10 = width;
        v11 = v9;
        if ( v5 != v9 )
        {
          v12 = v5 - v9;
          do
          {
            v31 = v10 - 1;
            base_3 = v11[v12];
            v11[v12] = *v11;
            *v11 = base_3;
            v10 = v31;
            ++v11;
          }
          while ( v31 != 0 );
        }
      }
      if ( comp(a1: context, a2: v5, a3: v7) > 0 )
      {
        v13 = width;
        v14 = v7;
        if ( v5 != v7 )
        {
          v15 = v5 - v7;
          do
          {
            v31 = v13 - 1;
            base_3a = v14[v15];
            v14[v15] = *v14;
            *v14 = base_3a;
            v13 = v31;
            ++v14;
          }
          while ( v31 != 0 );
        }
      }
      if ( comp(a1: context, a2: v9, a3: v7) > 0 )
      {
        v16 = width;
        v17 = v7;
        if ( v9 != v7 )
        {
          v18 = v9 - v7;
          do
          {
            base_3b = v17[v18];
            v17[v18] = *v17;
            *v17++ = base_3b;
            --v16;
          }
          while ( v16 != 0 );
          v5 = lo;
        }
      }
      while ( 1 )
      {
        if ( v9 > v5 )
        {
          while ( 1 )
          {
            v5 += width;
            if ( v5 >= v9 )
              break;
            if ( comp(a1: context, a2: v5, a3: v9) > 0 )
            {
              if ( v9 > v5 )
                goto LABEL_31;
              goto LABEL_29;
            }
          }
        }
        do
LABEL_29:
          v5 += width;
        while ( v5 <= hi && comp(a1: context, a2: v5, a3: v9) <= 0 );
        do
LABEL_31:
          v7 -= width;
        while ( v7 > v9 && comp(a1: context, a2: v7, a3: v9) > 0 );
        if ( v5 > v7 )
          break;
        v19 = width;
        v20 = v7;
        if ( v5 != v7 )
        {
          v21 = v5 - v7;
          do
          {
            v31 = v19 - 1;
            base_3c = v20[v21];
            v20[v21] = *v20;
            *v20 = base_3c;
            v19 = v31;
            ++v20;
          }
          while ( v31 != 0 );
        }
        if ( v9 == v7 )
          v9 = v5;
      }
      v7 += width;
      if ( v9 >= v7 )
        goto LABEL_43;
      do
      {
        v7 -= width;
        if ( v7 <= v9 )
          goto LABEL_43;
      }
      while ( comp(a1: context, a2: v7, a3: v9) == 0 );
      if ( v9 < v7 )
      {
LABEL_45:
        v22 = lo;
      }
      else
      {
LABEL_43:
        while ( 1 )
        {
          v7 -= width;
          v22 = lo;
          if ( v7 <= lo )
            break;
          if ( comp(a1: context, a2: v7, a3: v9) != 0 )
            goto LABEL_45;
        }
      }
      v23 = hi;
      if ( v7 - v22 < hi - v5 )
      {
        if ( v5 < hi )
        {
          v25 = stkptr;
          lostk[stkptr] = v5;
          histk[v25] = v23;
          stkptr = v25 + 1;
        }
        if ( v22 >= v7 )
          goto LABEL_55;
        v5 = lo;
        v6 = width;
        hi = v7;
      }
      else
      {
        if ( v22 < v7 )
        {
          v24 = stkptr;
          lostk[stkptr] = v22;
          histk[v24] = v7;
          stkptr = v24 + 1;
        }
        if ( v5 >= v23 )
        {
LABEL_55:
          v6 = width;
LABEL_56:
          v26 = --stkptr;
          if ( stkptr < 0 )
            return;
          v27 = lostk[v26];
          v28 = histk[v26];
          lo = v27;
          hi = v28;
          v5 = v27;
          v7 = v28;
        }
        else
        {
          v7 = hi;
          v6 = width;
          lo = v5;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EBDAF
// Name: _strtok
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strtok(char *string, const char *control)
{
  char v3; // dl
  char *token; // edx
  char *v5; // ebx
  _tiddata *ptd; // [esp+10h] [ebp-28h]
  unsigned __int8 map[32]; // [esp+14h] [ebp-24h] BYREF

  ptd = _getptd();
  memset(map, 0, sizeof(map));
  do
  {
    v3 = *control;
    map[*(unsigned __int8 *)control >> 3] |= 1 << (*control & 7);
    ++control;
  }
  while ( v3 != 0 );
  token = string;
  if ( string == nullptr )
    token = ptd->_token;
  while ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 && *token != 0 )
    ++token;
  v5 = token;
  while ( *token != 0 )
  {
    if ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 )
    {
      *token++ = 0;
      break;
    }
    ++token;
  }
  ptd->_token = token;
  return token != v5 ? v5 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102EBE70
// Name: _acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl acos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x102FB318);
  }
  JUMPOUT(0x102EBEFF);
}

//------------------------------------------------------------------------------
// Address: 0x102EBEB0
// Name: __CIacos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIacos(int a1, int a2)
{
  int v3; // eax
  bool v4; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIacos;
  v3 = _mm_getcsr() & 0x7F80;
  v4 = v3 == 8064;
  if ( v3 == 8064 )
    v4 = (v5 & 0x7F) == 127;
  if ( v4 )
    _CIacos_pentium4();
  else
__CIacos:
    _CIacos_default(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x102EBEEB
// Name: __CIacos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x102EBFC0
// Name: _asin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl asin(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x102FB878);
  }
  JUMPOUT(0x102EC04F);
}

//------------------------------------------------------------------------------
// Address: 0x102EC000
// Name: __CIasin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIasin(int a1, int a2)
{
  int v3; // eax
  bool v4; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIasin;
  v3 = _mm_getcsr() & 0x7F80;
  v4 = v3 == 8064;
  if ( v3 == 8064 )
    v4 = (v5 & 0x7F) == 127;
  if ( v4 )
    _CIasin_pentium4();
  else
__CIasin:
    _CIasin_default(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x102EC03B
// Name: __CIasin_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x102EC110
// Name: _sinh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sinh(double X)
{
  double v1; // st7
  double result; // st7

  _ctrandisp1(a1: v1, parm1: *(unsigned __int64 *)&X);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EC11A
// Name: _cosh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl cosh(double X)
{
  JUMPOUT(0x102EC115);
}

//------------------------------------------------------------------------------
// Address: 0x102EC121
// Name: _tanh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl tanh(double X)
{
  JUMPOUT(0x102EC115);
}

//------------------------------------------------------------------------------
// Address: 0x102EC128
// Name: __CIsinh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _CIsinh@<st0>(double x@<st0>, __int16 a2@<cx>, __int16 a3@<fpstat>)
{
  double result; // st7

  _cintrindisp1(a1: (int)&_OP_SINHjmptab, a2, a3, a4: x);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EC132
// Name: __CIcosh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIcosh()
{
  JUMPOUT(0x102EC12D);
}

//------------------------------------------------------------------------------
// Address: 0x102EC139
// Name: __CItanh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CItanh()
{
  JUMPOUT(0x102EC12D);
}

//------------------------------------------------------------------------------
// Address: 0x102EC140
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x102ED426);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC1C6
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fread_nolock_s(
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned __int8 *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  unsigned __int8 *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = buffer;
  dataSize = bufferSize;
  if ( elementSize == 0 || num == 0 )
    return 0;
  if ( buffer != nullptr )
  {
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
      goto LABEL_13;
    if ( bufferSize != -1 )
      memset(dst: buffer, value: 0, count: bufferSize);
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
    {
LABEL_13:
      v6 = num * elementSize;
      v7 = num * elementSize;
      if ( (stream->_flag & 0x10C) != 0 )
        streambufsize = stream->_bufsiz;
      else
        streambufsize = 4096;
      if ( v6 == 0 )
        return num;
      while ( 1 )
      {
        if ( (stream->_flag & 0x10C) != 0 )
        {
          cnt = stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_44;
            v9 = v7;
            if ( v7 >= cnt )
              v9 = stream->_cnt;
            if ( v9 > dataSize )
              goto LABEL_41;
            memcpy_s(dst: data, sizeInBytes: dataSize, src: (unsigned __int8 *)stream->_ptr, count: v9);
            stream->_cnt -= v9;
            stream->_ptr += v9;
            data += v9;
            v7 -= v9;
            dataSize -= v9;
            v6 = num * elementSize;
            goto LABEL_39;
          }
        }
        if ( v7 < streambufsize )
          break;
        if ( streambufsize != 0 )
        {
          if ( v7 <= 0x7FFFFFFF )
          {
            v10 = v7 % streambufsize;
            v11 = v7;
          }
          else
          {
            v10 = 0x7FFFFFFF % streambufsize;
            v11 = 0x7FFFFFFF;
          }
          v12 = v11 - v10;
        }
        else
        {
          v12 = 0x7FFFFFFF;
          if ( v7 <= 0x7FFFFFFF )
            v12 = v7;
        }
        if ( v12 > dataSize )
          goto LABEL_41;
        v17 = v12;
        v13 = fileno(stream);
        v14 = _read(fh: v13, buf: (char *)data, cnt: v17);
        if ( v14 == 0 )
        {
          stream->_flag |= 0x10u;
          return (v6 - v7) / elementSize;
        }
        if ( v14 == -1 )
        {
LABEL_44:
          stream->_flag |= 0x20u;
          return (v6 - v7) / elementSize;
        }
        data += v14;
        v7 -= v14;
        dataSize -= v14;
LABEL_39:
        if ( v7 == 0 )
          return num;
      }
      v15 = _filbuf(str: stream);
      if ( v15 == -1 )
        return (v6 - v7) / elementSize;
      if ( dataSize != 0 )
      {
        v16 = data++;
        *v16 = v15;
        --v7;
        --dataSize;
        streambufsize = stream->_bufsiz;
        goto LABEL_39;
      }
LABEL_41:
      if ( bufferSize != -1 )
        memset(dst: buffer, value: 0, count: bufferSize);
      *_errno() = 34;
LABEL_5:
      _invalid_parameter_noinfo();
      return 0;
    }
  }
  *_errno() = 22;
  goto LABEL_5;
}

//------------------------------------------------------------------------------
// Address: 0x102EC382
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread_s(
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( elementSize == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    if ( bufferSize != -1 )
      memset(dst: buffer, value: 0, count: bufferSize);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fread_nolock_s(buffer, bufferSize, elementSize, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EC410
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread(unsigned __int8 *buffer, unsigned int elementSize, unsigned int count, _iobuf *stream)
{
  return fread_s(buffer, bufferSize: 0xFFFFFFFF, elementSize, count, stream);
}

//------------------------------------------------------------------------------
// Address: 0x102EC42D
// Name: __fwrite_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fwrite_nolock(unsigned __int8 *buffer, unsigned int size, unsigned int num, _iobuf *stream)
{
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int cnt; // eax
  unsigned int v8; // edi
  unsigned int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int bufsize; // [esp+10h] [ebp-8h]
  unsigned __int8 *data; // [esp+14h] [ebp-4h]

  if ( size == 0 || num == 0 )
    return 0;
  if ( stream == nullptr || buffer == nullptr || num > 0xFFFFFFFF / size )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v5 = num * size;
  data = buffer;
  v6 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsize = stream->_bufsiz;
  else
    bufsize = 4096;
  if ( v5 == 0 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x108) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt != 0 )
      {
        if ( cnt < 0 )
        {
          stream->_flag |= 0x20u;
LABEL_34:
          v13 = v5;
          return (v13 - v6) / size;
        }
        v8 = v6;
        if ( v6 >= cnt )
          v8 = stream->_cnt;
        memcpy(dst: (unsigned __int8 *)stream->_ptr, src: data, count: v8);
        stream->_cnt -= v8;
        stream->_ptr += v8;
        v6 -= v8;
        data += v8;
        goto LABEL_27;
      }
    }
    if ( v6 >= bufsize )
      break;
    if ( _flsbuf(ch: *data, str: (int)stream) == -1 )
      goto LABEL_34;
    ++data;
    --v6;
    bufsize = stream->_bufsiz;
    if ( (int)bufsize <= 0 )
      bufsize = 1;
LABEL_31:
    if ( v6 == 0 )
      return num;
  }
  if ( (stream->_flag & 0x108) != 0 && _flush(str: stream) != 0 )
    goto LABEL_34;
  v9 = v6;
  if ( bufsize != 0 )
    v9 = v6 - v6 % bufsize;
  v10 = fileno(stream);
  v11 = _write(fh: v10, buf: data, cnt: v9);
  if ( v11 != -1 )
  {
    v12 = v9;
    if ( v11 <= v9 )
      v12 = v11;
    data += v12;
    v6 -= v12;
    if ( v11 >= v9 )
    {
LABEL_27:
      v5 = num * size;
      goto LABEL_31;
    }
  }
  stream->_flag |= 0x20u;
  v13 = num * size;
  return (v13 - v6) / size;
}

//------------------------------------------------------------------------------
// Address: 0x102EC584
// Name: _fwrite
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fwrite(unsigned __int8 *buffer, unsigned int size, unsigned int count, _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( size == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fwrite_nolock(buffer, size, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EC5FE
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC66B
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC6DF
// Name: __fseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseek_nolock(_iobuf *str, LONG offset, DWORD whence)
{
  int flag; // eax
  int v5; // eax
  int v6; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock(str);
      whence = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = fileno(stream: str);
    return (_lseek(fh: v6, pos: offset, mthd: whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC769
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fseek(_iobuf *stream, LONG offset, DWORD whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseek_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC7E5
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  ms_exc.registration.TryLevel = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: (int)&ms_exc.registration, a3: 0xFFFFFFFE);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EC8A1
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x102EC8B8
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftell_nolock(_iobuf *str)
{
  int v3; // eax
  int v4; // esi
  signed int v5; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v9; // ebx
  char *v10; // edx
  int cnt; // edx
  ioinfo **v12; // ebx
  int v13; // esi
  char *v14; // eax
  char *v15; // ecx
  bool v16; // zf
  int bufsiz; // eax
  int v18; // ecx
  unsigned int offset; // [esp+8h] [ebp-Ch]
  int fd; // [esp+Ch] [ebp-8h]
  LONG filepos; // [esp+10h] [ebp-4h]
  unsigned int rdcnt; // [esp+1Ch] [ebp+8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = fileno(stream: str);
  v4 = v3;
  fd = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v5 = _lseek(fh: v3, pos: 0, mthd: 1u);
  filepos = v5;
  if ( v5 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v5 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  v9 = (char *)(str->_ptr - base);
  offset = (unsigned int)v9;
  if ( (flag & 3) != 0 )
  {
    if ( __pioinfo[v4 >> 5][v4 & 0x1F].osfile < 0 )
    {
      v10 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v10 == 10 )
            ++v9;
          ++v10;
        }
        while ( v10 < ptr );
        offset = (unsigned int)v9;
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( filepos == 0 )
    return (int)v9;
  if ( (str->_flag & 1) == 0 )
    return filepos + offset;
  cnt = str->_cnt;
  if ( cnt != 0 )
  {
    v12 = &__pioinfo[fd >> 5];
    rdcnt = cnt + ptr - base;
    v13 = (fd & 0x1F) << 6;
    if ( *(&(*v12)->osfile + v13) >= 0 )
    {
LABEL_39:
      filepos -= rdcnt;
      return filepos + offset;
    }
    if ( _lseek(fh: fd, pos: 0, mthd: 2u) == filepos )
    {
      v14 = str->_base;
      v15 = &v14[rdcnt];
      while ( v14 < v15 )
      {
        if ( *v14 == 10 )
          ++rdcnt;
        ++v14;
      }
      v16 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v16 )
        ++rdcnt;
      goto LABEL_39;
    }
    if ( (_lseek(fh: fd, pos: filepos, mthd: 0) & 0x80000000) == 0 )
    {
      bufsiz = 512;
      if ( rdcnt > 0x200 || ((v18 = str->_flag) & 8) == 0 || (v18 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      rdcnt = bufsiz;
      v16 = (*(&(*v12)->osfile + v13) & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  offset = 0;
  return filepos + offset;
}

//------------------------------------------------------------------------------
// Address: 0x102ECA4C
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ftell(_iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ftell_nolock(str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ECAB1
// Name: __isupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isupper_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 1;
  else
    result = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECB02
// Name: _isupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isupper(int c)
{
  if ( __locale_changed != 0 )
    return _isupper_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 1;
}

//------------------------------------------------------------------------------
// Address: 0x102ECB30
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, mask: 4, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECB81
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 4;
}

//------------------------------------------------------------------------------
// Address: 0x102ECBAF
// Name: __isxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isxdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x80;
  else
    result = _isctype_l(c, mask: 128, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECC05
// Name: _isxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isxdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isxdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x80;
}

//------------------------------------------------------------------------------
// Address: 0x102ECC35
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isspace_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 8;
  else
    result = _isctype_l(c, mask: 8, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECC86
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isspace(int c)
{
  if ( __locale_changed != 0 )
    return _isspace_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 8;
}

//------------------------------------------------------------------------------
// Address: 0x102ECCB4
// Name: __isalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isalnum_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x107;
  else
    result = _isctype_l(c, mask: 263, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECD0A
// Name: _isalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isalnum(int c)
{
  if ( __locale_changed != 0 )
    return _isalnum_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x107;
}

//------------------------------------------------------------------------------
// Address: 0x102ECD3A
// Name: __isprint_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isprint_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x157;
  else
    result = _isctype_l(c, mask: 343, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECD90
// Name: _isprint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isprint(int c)
{
  if ( __locale_changed != 0 )
    return _isprint_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x157;
}

//------------------------------------------------------------------------------
// Address: 0x102ECDC0
// Name: __iscntrl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _iscntrl_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x20;
  else
    result = _isctype_l(c, mask: 32, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECE11
// Name: _iscntrl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iscntrl(int c)
{
  if ( __locale_changed != 0 )
    return _iscntrl_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x102ECE3F
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _tolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+18h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+1Ch] [ebp-4h] BYREF
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pclmap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x102ECF54
// Name: _tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl tolower(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _tolower_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 65 <= 0x19 )
    return c + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECF80
// Name: FindCompleteObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__thiscall FindCompleteObject(void **inptr)
{
  int v1; // edx
  _BYTE *result; // eax
  int v3; // edx

  v1 = *((_DWORD *)*inptr - 1);
  result = (char *)inptr - *(_DWORD *)(v1 + 4);
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 != 0 )
    result -= *(unsigned int *)((char *)inptr - v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECF96
// Name: PMDtoOffset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall PMDtoOffset@<eax>(const PMD *pmd@<eax>, char *pThis)
{
  int pdisp; // edx
  int v3; // ecx

  pdisp = pmd->pdisp;
  v3 = 0;
  if ( pdisp >= 0 )
    v3 = *(_DWORD *)(*(_DWORD *)&pThis[pdisp] + pmd->vdisp) + pmd->pdisp;
  return v3 + pmd->mdisp;
}

//------------------------------------------------------------------------------
// Address: 0x102ECFBA
// Name: FindMITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindMITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassArray *pBaseClassArray; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  const _s_RTTIBaseClassDescriptor *pSourceBCD; // [esp+Ch] [ebp-14h]
  const _s_RTTIBaseClassDescriptor *pTargetBCD; // [esp+10h] [ebp-10h]
  unsigned int nTargetBases; // [esp+14h] [ebp-Ch]
  unsigned int iTarget; // [esp+18h] [ebp-8h]
  unsigned int i; // [esp+1Ch] [ebp-4h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  pTargetBCD = nullptr;
  pSourceBCD = nullptr;
  nTargetBases = 0;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  while ( 1 )
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( pSourceBCD != nullptr )
        {
          if ( (v8->attributes & 3) == 0 && (pSourceBCD->attributes & 1) == 0 )
            return v8;
          return nullptr;
        }
        iTarget = i;
        pTargetBCD = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
        break;
    }
LABEL_12:
    if ( ++i >= numBaseClasses )
      return nullptr;
  }
  if ( pTargetBCD == nullptr )
  {
    pSourceBCD = v8;
    goto LABEL_12;
  }
  if ( i - iTarget > nTargetBases )
  {
    if ( (pTargetBCD->attributes & 3) == 0 )
      goto LABEL_20;
    return nullptr;
  }
  if ( (pTargetBCD->attributes & 0x40) == 0 )
  {
    if ( iTarget == 0 )
    {
LABEL_20:
      if ( (v8->attributes & 1) != 0 )
        return nullptr;
    }
    return pTargetBCD;
  }
  return (pTargetBCD->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) == 0
       ? pTargetBCD
       : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102ED0C2
// Name: FindVITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindVITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassDescriptor *v7; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  bool v11; // al
  int v12; // eax
  const _s_RTTIBaseClassDescriptor *result; // eax
  const _s_RTTIBaseClassArray *pBaseClassArray; // [esp+Ch] [ebp-24h]
  const _s_RTTIBaseClassDescriptor *pCrossCastTargetBCD; // [esp+10h] [ebp-20h]
  const _s_RTTIBaseClassDescriptor *pCrossCastSourceBCD; // [esp+14h] [ebp-1Ch]
  int offsetDownCastResult; // [esp+18h] [ebp-18h]
  const _s_RTTIBaseClassDescriptor *pDownCastResultBCD; // [esp+1Ch] [ebp-14h]
  unsigned int nTargetBases; // [esp+20h] [ebp-10h]
  unsigned int iTarget; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+28h] [ebp-8h]
  bool fDownCastAllowed; // [esp+2Fh] [ebp-1h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  offsetDownCastResult = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  v7 = nullptr;
  pDownCastResultBCD = nullptr;
  pCrossCastSourceBCD = nullptr;
  pCrossCastTargetBCD = nullptr;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  nTargetBases = 0;
  fDownCastAllowed = true;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  do
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( (v8->attributes & 3) == 0 )
          pCrossCastTargetBCD = v8;
        iTarget = i;
        v7 = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
      {
        if ( i - iTarget > nTargetBases )
        {
          if ( (v8->attributes & 5) == 0 )
            pCrossCastSourceBCD = v8;
        }
        else if ( fDownCastAllowed )
        {
          if ( (v7->attributes & 0x40) != 0 )
          {
            if ( (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 4) == 0;
          }
          else
          {
            if ( iTarget == 0 && (v8->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = true;
          }
          if ( fDownCastAllowed && v11 )
          {
            v12 = PMDtoOffset(pmd: &v7->where, pThis: pCompleteObject);
            if ( pDownCastResultBCD != nullptr && offsetDownCastResult != v12 )
              return nullptr;
            pDownCastResultBCD = v7;
            offsetDownCastResult = v12;
          }
        }
      }
    }
    ++i;
  }
  while ( i < numBaseClasses );
  if ( !fDownCastAllowed || (result = pDownCastResultBCD, pDownCastResultBCD == nullptr) )
  {
    if ( pCrossCastSourceBCD == nullptr )
      return nullptr;
    result = pCrossCastTargetBCD;
    if ( pCrossCastTargetBCD == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED358
// Name: $LN35_6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _LN35_6@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    strlen(buf: string);
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      str._cnt = v6;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ED3C6
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return _LN35_6(
           string,
           inputfn: (int (__cdecl *)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *))_input_l,
           format,
           plocinfo: nullptr,
           arglist);
}

//------------------------------------------------------------------------------
// Address: 0x102ED3E8
// Name: _sscanf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf_s(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return _LN35_6(string, inputfn: _input_s_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x102ED420
// Name: _strchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strchr(char *string, unsigned __int8 chr)
{
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = string;
  if ( ((unsigned __int8)string & 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == chr || v3 == 0 )
        break;
      if ( ((unsigned __int8)v2 & 3) == 0 )
        goto main_loop;
    }
  }
  else
  {
    do
    {
main_loop:
      while ( 1 )
      {
        v4 = ((chr << 8) | chr | (((chr << 8) | chr) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( (((v4 + 2130640639) ^ ~v4) & 0x81010100) != 0 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 != 0 && ((v7 & 0x1010100) != 0 || (v5 & 0x80000000) == 0) )
          return;
      }
      v8 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v8 == chr )
        break;
      if ( (_BYTE)v8 == 0 )
        break;
      if ( BYTE1(v8) == chr )
        break;
      if ( BYTE1(v8) == 0 )
        break;
      v9 = HIWORD(v8);
      if ( (_BYTE)v9 == chr )
        break;
    }
    while ( (_BYTE)v9 != 0 && BYTE1(v9) != chr && BYTE1(v9) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ED4E0
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x102ED510
// Name: __allshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _allshr@<eax>(__int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> 31;
  }
  else if ( a2 >= 0x20u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> (a2 & 0x1F);
  }
  else
  {
    a1 >>= a2 & 0x1F;
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x102ED540
// Name: __allshl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _allshl@<eax>(__int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  __int64 v2; // rax

  if ( a2 >= 0x40u )
  {
    LODWORD(v2) = 0;
  }
  else if ( a2 >= 0x20u )
  {
    LODWORD(v2) = 0;
  }
  else
  {
    return a1 << (a2 & 0x1F);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102ED560
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(__m128i *dst, const __m128i *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  __m128i *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = (unsigned __int8 *)src;
  v4 = dst;
  if ( dst > src && dst < (__m128i *)&src->m128i_i8[count] )
  {
    v6 = &src->m128i_u8[count - 4];
    v7 = &dst->m128i_u8[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown_0+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = (unsigned __int8 *)src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(a1: count, a2: dst, a3: src);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 102ED5B9 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *((_DWORD *)&v4[-1] + v5 - 3) = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *((_DWORD *)&v4[-1] + v5 - 2) = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *((_DWORD *)&v4[-1] + v5 - 1) = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        v4[-1].m128i_i32[v5] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        v4->m128i_i32[v5 - 3] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        v4->m128i_i32[v5 - 2] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        v4->m128i_i32[v5 - 1] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 = (__m128i *)((char *)v4 + 4 * v5);
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 = (__m128i *)((char *)v4 + 4 * v5);
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            v4->m128i_i8[0] = *v3;
            break;
          case 2u:
TrailUp2_0:
            v4->m128i_i8[0] = *v3;
            v4->m128i_i8[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            v4->m128i_i8[0] = *v3;
            v4->m128i_i8[1] = v3[1];
            v4->m128i_i8[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ED8C1
// Name: _wcsstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcsstr(const wchar_t *wcs1, const wchar_t *wcs2)
{
  unsigned __int16 *result; // eax
  const wchar_t *v3; // edi
  unsigned __int16 v4; // dx
  int i; // eax
  const wchar_t *v6; // ecx
  int v7; // edx

  result = (unsigned __int16 *)wcs1;
  v3 = wcs1;
  if ( *wcs2 != 0 )
  {
    if ( *wcs1 != 0 )
    {
      v4 = *wcs1;
      for ( i = (char *)wcs1 - (char *)wcs2; ; i += 2 )
      {
        v6 = wcs2;
        if ( v4 != 0 )
          break;
LABEL_8:
        if ( *v6 == 0 )
          return (unsigned __int16 *)v3;
        v4 = *++v3;
        if ( *v3 == 0 )
          return nullptr;
      }
      while ( 1 )
      {
        v7 = *v6;
        if ( (_WORD)v7 == 0 )
          return (unsigned __int16 *)v3;
        if ( *(const wchar_t *)((char *)v6 + i) == v7 && *(const wchar_t *)((char *)++v6 + i) != 0 )
          continue;
        goto LABEL_8;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED921
// Name: __snprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snprintf(char *string, unsigned int count, const char *format, ...)
{
  int result; // eax
  int v4; // edi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+3Ch] [ebp+14h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, (int)&str);
      else
        *str._ptr = 0;
      return v4;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED9CD
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, (int)&str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EDA79
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x102EDA96
// Name: __mkdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mkdir(const char *path)
{
  DWORD LastError; // eax

  if ( CreateDirectoryA(lpPathName: path, lpSecurityAttributes: nullptr) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102EDAC8
// Name: __rmdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _rmdir(const char *path)
{
  DWORD LastError; // eax

  if ( RemoveDirectoryA(lpPathName: path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102EDAF8
// Name: _remove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl remove(const char *path)
{
  DWORD LastError; // eax

  if ( DeleteFileA(lpFileName: path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102EDB28
// Name: _unlink
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unlink(const char *path)
{
  return remove(path);
}

//------------------------------------------------------------------------------
// Address: 0x102EDB33
// Name: _strncmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncmp(const char *first, const char *last, unsigned int count)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  unsigned int i; // esi
  unsigned int n; // [esp+4h] [ebp-4h]

  n = 0;
  if ( count == 0 )
    return 0;
  if ( count <= 4 )
  {
    v4 = last;
    v5 = first;
LABEL_20:
    for ( i = n; ; ++i )
    {
      if ( i >= count )
        return 0;
      if ( *v5 == 0 || *v5 != *v4 )
        break;
      ++v5;
      ++v4;
    }
    v10 = *(unsigned __int8 *)v5;
    v11 = *(unsigned __int8 *)v4;
  }
  else
  {
    v4 = last;
    v5 = first;
    while ( 1 )
    {
      v6 = *v5;
      v5 += 4;
      v4 += 4;
      if ( v6 == 0 || v6 != *(v4 - 4) )
        break;
      v7 = *(v5 - 3);
      if ( v7 == 0 || v7 != *(v4 - 3) )
      {
        v10 = *((unsigned __int8 *)v5 - 3);
        v11 = *((unsigned __int8 *)v4 - 3);
        return v10 - v11;
      }
      v8 = *(v5 - 2);
      if ( v8 == 0 || v8 != *(v4 - 2) )
      {
        v10 = *((unsigned __int8 *)v5 - 2);
        v11 = *((unsigned __int8 *)v4 - 2);
        return v10 - v11;
      }
      v9 = *(v5 - 1);
      if ( v9 == 0 || v9 != *(v4 - 1) )
      {
        v10 = *((unsigned __int8 *)v5 - 1);
        v11 = *((unsigned __int8 *)v4 - 1);
        return v10 - v11;
      }
      n += 4;
      if ( n >= count - 4 )
        goto LABEL_20;
    }
    v10 = *((unsigned __int8 *)v5 - 4);
    v11 = *((unsigned __int8 *)v4 - 4);
  }
  return v10 - v11;
}

//------------------------------------------------------------------------------
// Address: 0x102EDBF3
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isleadbyte_l(unsigned __int8 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _loc_update.localeinfo.locinfo->pctype[c] & 0x8000;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EDC2B
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isleadbyte(unsigned __int8 c)
{
  return _isleadbyte_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EDC3E
// Name: _iswdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswdigit(unsigned __int16 c)
{
  return iswctype(c, mask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x102EDC51
// Name: _iswspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswspace(unsigned __int16 c)
{
  return iswctype(c, mask: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x102EDC64
// Name: _iswalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswalnum(unsigned __int16 c)
{
  return iswctype(c, mask: 0x107u);
}

//------------------------------------------------------------------------------
// Address: 0x102EDC7A
// Name: _iswcntrl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswcntrl(unsigned __int16 c)
{
  return iswctype(c, mask: 0x20u);
}

//------------------------------------------------------------------------------
// Address: 0x102EDC8D
// Name: _iswascii
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl iswascii(unsigned __int16 c)
{
  return c < 0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x102EDCA1
// Name: _wcsncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcsncpy(unsigned __int16 *dest, const wchar_t *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned __int16 *v4; // edi
  unsigned __int16 v5; // ax
  unsigned int v6; // ecx
  char v7; // cf
  unsigned int v8; // ecx
  unsigned __int16 *v9; // edi
  int i; // ecx

  v3 = count;
  v4 = dest;
  if ( count != 0 )
  {
    do
    {
      v5 = *(unsigned __int16 *)((char *)v4 + (char *)source - (char *)dest);
      *v4++ = v5;
      if ( v5 == 0 )
        break;
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 != 0 )
    {
      v6 = v3 - 1;
      if ( v6 != 0 )
      {
        v7 = v6 & 1;
        v8 = v6 >> 1;
        memset(v4, 0, 4 * v8);
        v9 = &v4[2 * v8];
        for ( i = v7; i != 0; --i )
          *v9++ = 0;
      }
    }
  }
  return dest;
}

//------------------------------------------------------------------------------
// Address: 0x102EDCF0
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x102EDE14
// Name: IsRootUNCName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall IsRootUNCName@<eax>(const char *path@<esi>)
{
  unsigned int v1; // eax
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  char *v9; // [esp+0h] [ebp-4h]

  strlen(buf: v9);
  if ( v1 < 5 || *path != 92 && *path != 47 )
    return false;
  v2 = path[1];
  if ( v2 != 92 && v2 != 47 )
    return false;
  v3 = path[2];
  if ( v3 == 92 )
    return false;
  if ( v3 == 47 )
    return false;
  v4 = path + 3;
  v5 = path[3];
  if ( v5 == 0 )
    return false;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    v5 = *++v4;
  }
  while ( *v4 != 0 );
  if ( *v4 == 0 )
    return false;
  v6 = (char *)(v4 + 1);
  if ( *v6 == 0 )
    return false;
  v7 = *v6;
  do
  {
    if ( v7 == 92 )
      break;
    if ( v7 == 47 )
      break;
    v7 = *++v6;
  }
  while ( *v6 != 0 );
  return *v6 == 0 || v6[1] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x102EDE8E
// Name: _fullpath_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fullpath_helper(char *buf, const char *path, DWORD sz, char **pBuf)
{
  int v4; // esi
  char *v5; // edi
  int *v6; // eax
  char *result; // eax

  v4 = *_errno();
  *_errno() = 0;
  v5 = _fullpath(UserBuf: buf, path, maxlen: sz);
  v6 = _errno();
  if ( v5 != nullptr )
  {
    *v6 = v4;
    return v5;
  }
  else if ( *v6 == 34 )
  {
    *_errno() = v4;
    result = _fullpath(UserBuf: nullptr, path, maxlen: 0);
    *pBuf = result;
  }
  else
  {
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EDEEE
// Name: __stat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stat64i32(char *name, _stat64i32 *buf)
{
  const char *dwHighDateTime; // esi
  int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  char *v6; // eax
  const char *v7; // esi
  int v8; // eax
  __int64 v9; // rax
  int v10; // esi
  int v12; // edx
  int v13; // edx
  int v14; // edx
  DWORD LastError; // eax
  int retval; // [esp+Ch] [ebp-26Ch]
  int drive; // [esp+10h] [ebp-268h]
  _FILETIME LocalFTime; // [esp+14h] [ebp-264h] BYREF
  int fd; // [esp+1Ch] [ebp-25Ch] BYREF
  _WIN32_FIND_DATAA findbuf; // [esp+20h] [ebp-258h] BYREF
  _SYSTEMTIME SystemTime; // [esp+160h] [ebp-118h] BYREF
  char pathbuf[260]; // [esp+170h] [ebp-108h] BYREF

  dwHighDateTime = name;
  LocalFTime.dwHighDateTime = (unsigned int)name;
  retval = 0;
  if ( name == nullptr || buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _mbspbrk(string: (unsigned __int8 *)name, charset: "?*");
  if ( v3 != 0 )
  {
LABEL_5:
    *_errno() = 2;
    *__doserrno() = 2;
    return -1;
  }
  if ( name[1] == 58 )
  {
    if ( *name != 0 && name[2] == 0 )
      goto LABEL_5;
    v4 = _mbctolower(c: *name) - 96;
  }
  else
  {
    v4 = _getdrive();
  }
  drive = v4;
  fd = (int)FindFirstFileExA(
              lpFileName: name,
              fInfoLevelId: FindExInfoStandard,
              lpFindFileData: &findbuf,
              fSearchOp: FindExSearchNameMatch,
              lpSearchFilter: nullptr,
              dwAdditionalFlags: 0);
  if ( fd != -1 )
  {
    if ( (findbuf.dwFileAttributes & 0x400) != 0 && findbuf.dwReserved0 == -1610612724 )
    {
      fd = -1;
      if ( _sopen_s(pfh: &fd, path: name, oflag: 0, shflag: 64, pmode: 0) == 0 && fd != -1 )
      {
        v10 = _fstat64i32(fildes: fd, buf);
        _close(fh: fd);
        return v10;
      }
      goto LABEL_5;
    }
    if ( findbuf.ftLastWriteTime.dwLowDateTime != 0 || findbuf.ftLastWriteTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastWriteTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      LODWORD(buf->st_mtime) = __loctotime64_t(
                                 yr: SystemTime.wYear,
                                 mo: SystemTime.wMonth,
                                 dy: SystemTime.wDay,
                                 hr: SystemTime.wHour,
                                 mn: SystemTime.wMinute,
                                 sc: SystemTime.wSecond,
                                 dstflag: -1);
      HIDWORD(buf->st_mtime) = v12;
    }
    else
    {
      buf->st_mtime = 0;
    }
    if ( findbuf.ftLastAccessTime.dwLowDateTime != 0 || findbuf.ftLastAccessTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastAccessTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      LODWORD(buf->st_atime) = __loctotime64_t(
                                 yr: SystemTime.wYear,
                                 mo: SystemTime.wMonth,
                                 dy: SystemTime.wDay,
                                 hr: SystemTime.wHour,
                                 mn: SystemTime.wMinute,
                                 sc: SystemTime.wSecond,
                                 dstflag: -1);
      HIDWORD(buf->st_atime) = v13;
    }
    else
    {
      buf->st_atime = buf->st_mtime;
    }
    if ( findbuf.ftCreationTime.dwLowDateTime == 0 && findbuf.ftCreationTime.dwHighDateTime == 0 )
    {
      buf->st_ctime = buf->st_mtime;
LABEL_45:
      FindClose(hFindFile: (HANDLE)fd);
      goto LABEL_46;
    }
    if ( FileTimeToLocalFileTime(lpFileTime: &findbuf.ftCreationTime, lpLocalFileTime: &LocalFTime)
      && FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
    {
      LODWORD(buf->st_ctime) = __loctotime64_t(
                                 yr: SystemTime.wYear,
                                 mo: SystemTime.wMonth,
                                 dy: SystemTime.wDay,
                                 hr: SystemTime.wHour,
                                 mn: SystemTime.wMinute,
                                 sc: SystemTime.wSecond,
                                 dstflag: -1);
      HIDWORD(buf->st_ctime) = v14;
      goto LABEL_45;
    }
LABEL_49:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    FindClose(hFindFile: (HANDLE)fd);
    return -1;
  }
  fd = 0;
  _mbspbrk(string: (unsigned __int8 *)name, charset: "./\\");
  if ( v5 == 0 )
    goto LABEL_5;
  v6 = fullpath_helper(buf: pathbuf, path: name, sz: 0x104u, pBuf: (char **)&fd);
  v7 = v6;
  if ( v6 == nullptr || (strlen(buf: v6), v8 != 3) && !IsRootUNCName(path: v7) || GetDriveTypeA(lpRootPathName: v7) <= 1 )
  {
    if ( fd != 0 )
      free(pMem: (void *)fd);
    goto LABEL_5;
  }
  if ( fd != 0 )
    free(pMem: (void *)fd);
  findbuf.dwFileAttributes = 16;
  findbuf.nFileSizeHigh = 0;
  findbuf.nFileSizeLow = 0;
  findbuf.cFileName[0] = 0;
  LODWORD(v9) = __loctotime64_t(yr: 1980, mo: 1, dy: 1, hr: 0, mn: 0, sc: 0, dstflag: -1);
  dwHighDateTime = (const char *)LocalFTime.dwHighDateTime;
  buf->st_mtime = v9;
  buf->st_atime = v9;
  buf->st_ctime = v9;
LABEL_46:
  buf->st_mode = __dtoxmode(attr: findbuf.dwFileAttributes, name: dwHighDateTime);
  buf->st_nlink = 1;
  buf->st_size = findbuf.nFileSizeLow;
  if ( findbuf.nFileSizeHigh != 0 )
  {
    retval = -1;
    buf->st_size = 0;
  }
  buf->st_ino = 0;
  buf->st_gid = 0;
  buf->st_uid = 0;
  buf->st_dev = drive - 1;
  buf->st_rdev = drive - 1;
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EE448
// Name: public: std::__non_rtti_object::__non_rtti_object(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::__non_rtti_object *__thiscall std::__non_rtti_object::__non_rtti_object(
        std::__non_rtti_object *this,
        const char *_Message)
{
  std::bad_typeid::bad_typeid(this, _Message);
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::__non_rtti_object::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EE4F6
// Name: public: std::__non_rtti_object::__non_rtti_object(class std::__non_rtti_object const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::__non_rtti_object *__thiscall std::__non_rtti_object::__non_rtti_object(
        std::__non_rtti_object *this,
        const std::__non_rtti_object *that)
{
  std::bad_typeid::bad_typeid(this, that);
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::__non_rtti_object::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EE513
// Name: void __near * operator new(unsigned int,struct std::nothrow_t const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int count)
{
  return MemAlloc_Alloc(nSize: count);
}

//------------------------------------------------------------------------------
// Address: 0x102EE542
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax
  wchar_t drvstr[4]; // [esp+0h] [ebp-Ch] BYREF

  result = true;
  if ( drive != 0 )
  {
    drvstr[0] = drive + 64;
    wcscpy(&drvstr[1], L":\\");
    if ( GetDriveTypeW(lpRootPathName: drvstr) <= 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EE59C
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  unsigned int v3; // ebx
  char *v5; // edi
  signed int FullPathNameA; // eax
  char *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  int count; // [esp+8h] [ebp-4h]

  v3 = drive;
  if ( drive != 0 )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  else
  {
    v3 = _getdrive();
  }
  v5 = pnbuf;
  if ( pnbuf != nullptr )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v3 != 0 )
  {
    LOBYTE(drive) = v3 + 64;
    strcpy((char *)&drive + 1, ":.");
  }
  else
  {
    strcpy((char *)&drive, ".");
  }
  FullPathNameA = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: count, lpBuffer: v5, lpFilePart: &pname);
  if ( FullPathNameA == 0 )
    goto LABEL_24;
  if ( v5 == nullptr )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v7 = (char *)calloc(count: maxlen, size: 1u);
    v5 = v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return nullptr;
    }
    v8 = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: maxlen, lpBuffer: v7, lpFilePart: &pname);
    if ( v8 != 0 && v8 < maxlen )
      return v5;
LABEL_24:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return nullptr;
  }
  if ( FullPathNameA < count )
    return v5;
  *_errno() = 34;
  *v5 = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102EE6C0
// Name: __getcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getcwd(char *pnbuf, int maxlen)
{
  char *retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = _getdcwd_nolock(drive: 0, pnbuf, maxlen);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102EE709
// Name: __access_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access_s(const char *path, int amode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  if ( path == nullptr || (amode & 0xFFFFFFF9) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  FileAttributesA = GetFileAttributesA(lpFileName: path);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return *_errno();
  }
  if ( (FileAttributesA & 0x10) == 0 && (FileAttributesA & 1) != 0 && (amode & 2) != 0 )
  {
    *__doserrno() = 5;
    *_errno() = 13;
    return *_errno();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102EE788
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getenv_helper_nolock(char *option)
{
  char **v1; // esi
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax

  v1 = _environ;
  if ( __env_initialized == 0 )
    return nullptr;
  if ( _environ != nullptr || _wenviron != nullptr && __wtomb_environ() == 0 && (v1 = _environ, _environ != nullptr) )
  {
    if ( option != nullptr )
    {
      strlen(buf: option);
      v4 = v3;
      while ( *v1 != nullptr )
      {
        strlen(buf: *v1);
        if ( v5 > v4
          && (*v1)[v4] == 61
          && _mbsnbicoll(s1: (const unsigned __int8 *)*v1, s2: (const unsigned __int8 *)option, n: v4) == 0 )
        {
          return &(*v1)[v4 + 1];
        }
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102EE80F
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv(char *option)
{
  char *retval; // [esp+14h] [ebp-1Ch]

  if ( option != nullptr && strnlen(str: option, maxsize: 0x7FFFu) < 0x7FFF )
  {
    _lock(locknum: 7);
    retval = _getenv_helper_nolock(option);
    _unlock(locknum: 7);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EE889
// Name: __dupenv_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _dupenv_s(char **pBuffer, unsigned int *pBufferSizeInTChars, char *varname)
{
  int v3; // esi
  char *v4; // eax
  const char *v5; // ebx
  int v6; // eax
  unsigned int v7; // esi
  char *v8; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  v3 = 0;
  if ( pBuffer != nullptr )
  {
    *pBuffer = nullptr;
    if ( pBufferSizeInTChars != nullptr )
      *pBufferSizeInTChars = 0;
    if ( varname != nullptr )
    {
      v4 = _getenv_helper_nolock(option: varname);
      v5 = v4;
      if ( v4 == nullptr )
        goto LABEL_3;
      strlen(buf: v4);
      v7 = v6 + 1;
      v8 = (char *)calloc(count: v6 + 1, size: 1u);
      *pBuffer = v8;
      if ( v8 != nullptr )
      {
        if ( strcpy_s(_Dst: v8, _SizeInBytes: v7, _Src: v5) != 0 )
          _invoke_watson();
        if ( pBufferSizeInTChars != nullptr )
          *pBufferSizeInTChars = v7;
        retval = 0;
      }
      else
      {
        *_errno() = 12;
        retval = *_errno();
      }
LABEL_14:
      _unlock(locknum: 7);
      return retval;
    }
  }
  v3 = 22;
  *_errno() = 22;
  _invalid_parameter_noinfo();
LABEL_3:
  retval = v3;
  goto LABEL_14;
}

//------------------------------------------------------------------------------
// Address: 0x102EE960
// Name: __spawnv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnv(int modeflag, char *pathname, const char **argv)
{
  if ( pathname != nullptr && *pathname != 0 && argv != nullptr && *argv != nullptr && **argv != 0 )
    return _spawnve(mode: modeflag, name: pathname, argv, envp: nullptr);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102EE9B0
// Name: _longjmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn longjmp(jmp_buf Buf, int Value)
{
  unsigned int *v2; // ebx
  unsigned int v3; // ebp
  void *v4; // esi
  void (__stdcall *v5)(unsigned int *); // eax
  _EXCEPTION_RECORD ExceptionRecord; // [esp+0h] [ebp-50h] BYREF

  v2 = (unsigned int *)Buf;
  ExceptionRecord.ExceptionCode = -2147483610;
  memset(&ExceptionRecord.ExceptionFlags, 0, 16);
  v3 = *Buf;
  v4 = (void *)Buf[6];
  if ( v4 != (void *)__readfsdword(0) )
  {
    RtlUnwind(TargetFrame: v4, TargetIp: &lj_return, &ExceptionRecord, ReturnValue: nullptr);
    v2 = (unsigned int *)Buf;
  }
  if ( v4 != nullptr )
  {
    if ( _rt_probe_read4(ptr: v2 + 8) != 0 && v2[8] == 1447244336 )
    {
      v5 = (void (__stdcall *)(unsigned int *))v2[9];
      if ( v5 != nullptr )
        v5(a1: v2);
    }
    else
    {
      _local_unwind2(a1: (int)v4, a2: v2[7]);
    }
  }
  _NLG_Notify(result: v2[5], a2: v3, a3: 0);
  ((void (*)(void))v2[5])();
}

//------------------------------------------------------------------------------
// Address: 0x102EEA70
// Name: __setjmp3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _setjmp3@<eax>(
        int a1@<ebx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        _DWORD *a5,
        int a6,
        _EXCEPTION_REGISTRATION_RECORD *a7,
        int a8,
        ...)
{
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  unsigned int v9; // ecx
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, a8);
  *a5 = a2;
  a5[1] = a1;
  a5[2] = a3;
  a5[3] = a4;
  a5[4] = &retaddr;
  a5[5] = retaddr;
  a5[8] = 1447244336;
  a5[9] = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  a5[6] = ExceptionList;
  if ( ExceptionList == (_EXCEPTION_REGISTRATION_RECORD *)-1 )
  {
    a5[7] = -1;
  }
  else if ( a6 != 0 && (ExceptionList = a7, a5[9] = a7, a6 != 1) )
  {
    a5[7] = a8;
    v9 = a6 - 2;
    if ( a6 != 2 )
    {
      if ( v9 > 6 )
        v9 = 6;
      qmemcpy(a5 + 10, va, 4 * v9);
    }
  }
  else
  {
    a5[7] = ExceptionList[1].Handler;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102EEAEB
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  const char *v3; // esi
  int v5; // eax
  _flt *v6; // eax
  _flt *v7; // ecx
  int flags; // eax
  long double v9; // st7
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-34h] BYREF
  long double tmp; // [esp+1Ch] [ebp-24h]
  _flt answerstruct; // [esp+24h] [ebp-1Ch] BYREF

  v3 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
       ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v3] & 8
       : _isctype_l(c: *(unsigned __int8 *)v3, mask: 8, plocinfo: &_loc_update.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  v6 = _fltin2(flt: &answerstruct, str: v3, _Locale: &_loc_update.localeinfo);
  v7 = v6;
  if ( endptr != nullptr )
    *endptr = (char *)&v3[v6->nbytes];
  flags = v6->flags;
  if ( (v7->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr != nullptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v9 = _HUGE;
    if ( *v3 == 45 )
      v9 = -_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v9 = 0.0, 0.0 != v7->dval) )
  {
    tmp = v7->dval;
    goto LABEL_24;
  }
  tmp = v9;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x102EEC25
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int printf(const char *format, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  int v4; // edi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    v2 = __iob_func();
    _lock_file2(i: 1, s: &v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: &v7[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EECCC
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x102EECE2
// Name: _fprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fprintf(_iobuf *str, const char *format, ...)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v6; // esi
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v3 = fileno(stream: str);
      if ( v3 == -1 || v3 == -2 )
        v4 = &__badioinfo;
      else
        v4 = &__pioinfo[v3 >> 5][v3 & 0x1F];
      if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
        || (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v6 = _stbuf(str);
      retval = _output_l(stream: str, format, plocinfo: nullptr, argptr);
      _ftbuf(flag: v6, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EEDEE
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x102EEDF4
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int osfhnd; // eax

  v0 = _nstream;
  if ( _nstream == 0 )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)calloc(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)calloc(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&dststart )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_1042CF80;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_1042CFE0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102EEEA5
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pMem: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x102EEEC5
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_1042D1D0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(locknum: pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EEF06
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(locknum: i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EEF38
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_1042D1D0 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(locknum: pf - _iob + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EEF74
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(locknum: i + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EF0B6
// Name: _seh_longjmp_unwind(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _seh_longjmp_unwind(int a1)
{
  return _local_unwind2(a1: *(_DWORD *)(a1 + 24), a2: *(_DWORD *)(a1 + 28));
}

//------------------------------------------------------------------------------
// Address: 0x102EF0D1
// Name: void (*_set_se_translator(void (*)(unsigned int,struct _EXCEPTION_POINTERS __near *)))(unsigned int,struct _EXCEPTION_POINTERS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl _set_se_translator(
        void (__cdecl *pNew)(unsigned int, _EXCEPTION_POINTERS *)))(unsigned int, _EXCEPTION_POINTERS *)
{
  void *translator; // esi

  translator = _getptd()->_translator;
  _getptd()->_translator = pNew;
  return (void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *))translator;
}

//------------------------------------------------------------------------------
// Address: 0x102EF0F5
// Name: __toupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _toupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+14h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 2;
    }
    else
    {
      v4 = _isctype_l(c, mask: 2, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pcumap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x102EF20B
// Name: _toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl toupper(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _toupper_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 97 <= 0x19 )
    return c - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EF240
// Name: __aulldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldiv(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v3; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = v6 / v5;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    return v8;
  }
  else
  {
    LODWORD(v3) = a1;
    HIDWORD(v3) = HIDWORD(a1) % (unsigned int)a2;
    return v3 / (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EF2A8
// Name: __gmtime64_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _gmtime64_s(tm *ptm, const __int64 *timp)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int v8; // edi
  int v9; // eax
  int v10; // et0
  int v11; // et0
  unsigned int v12; // edi
  unsigned int v13; // et0
  int *v14; // edx
  int tm_yday; // eax
  int i; // ecx
  int v17; // ecx
  signed __int64 v18; // kr28_8
  __int64 caltim; // [esp+4h] [ebp-10h]
  unsigned int caltim_4; // [esp+8h] [ebp-Ch]
  int v21; // [esp+Ch] [ebp-8h]
  int islpyr; // [esp+10h] [ebp-4h]
  int tmptim; // [esp+1Ch] [ebp+8h]

  islpyr = 0;
  if ( ptm == nullptr || (memset(dst: (unsigned __int8 *)ptm, value: 0xFFu, count: sizeof(tm)), timp == nullptr) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  v4 = *(_DWORD *)timp;
  v5 = *((_DWORD *)timp + 1);
  LODWORD(caltim) = *(_DWORD *)timp;
  if ( *timp < -43200 || __SPAIR64__(v5, v4) > 0x7934126CFLL )
  {
    *_errno() = 22;
    return 22;
  }
  v6 = __SPAIR64__(v5, v4) / 31536000;
  v21 = v6 + 69;
  tmptim = v6 + 70;
  v7 = 86400 * (-365LL * (int)v6 - (((int)v6 + 369) / 400 - ((int)v6 + 69) / 100 + ((int)v6 + 69) / 4 - 17));
  HIDWORD(caltim) = *((_DWORD *)timp + 1);
  v8 = v7 + caltim;
  HIDWORD(caltim) = (unsigned __int64)(v7 + caltim) >> 32;
  if ( caltim >= 0 )
  {
    if ( (tmptim % 4 != 0 || tmptim % 100 == 0) && (tmptim + 1900) % 400 != 0 )
      goto LABEL_18;
    goto LABEL_17;
  }
  v9 = v21;
  v10 = (__PAIR64__(HIDWORD(caltim), v8) + 31536000) >> 32;
  v8 += 31536000;
  HIDWORD(caltim) = v10;
  tmptim = v21;
  if ( v21 % 4 == 0 )
  {
    if ( v21 % 100 != 0 )
    {
LABEL_13:
      v11 = (__PAIR64__(HIDWORD(caltim), v8) + 86400) >> 32;
      v8 += 86400;
      HIDWORD(caltim) = v11;
LABEL_17:
      islpyr = 1;
      goto LABEL_18;
    }
    v9 = v21;
  }
  if ( (v9 + 1900) % 400 == 0 )
    goto LABEL_13;
LABEL_18:
  ptm->tm_year = tmptim;
  ptm->tm_yday = __SPAIR64__(HIDWORD(caltim), v8) / 86400;
  v13 = (-86400LL * (int)(__SPAIR64__(HIDWORD(caltim), v8) / 86400) + __PAIR64__(HIDWORD(caltim), v8)) >> 32;
  v12 = __SPAIR64__(HIDWORD(caltim), v8) % 86400;
  caltim_4 = v13;
  v14 = _lpdays;
  if ( islpyr == 0 )
    v14 = _days;
  tm_yday = ptm->tm_yday;
  for ( i = 1; v14[i] < tm_yday; ++i )
    ;
  v17 = i - 1;
  ptm->tm_mon = v17;
  ptm->tm_mday = tm_yday - v14[v17];
  ptm->tm_wday = (int)(*timp / 86400 + 4) % 7;
  ptm->tm_hour = __SPAIR64__(caltim_4, v12) / 3600;
  v18 = -3600LL * (int)(__SPAIR64__(caltim_4, v12) / 3600) + __PAIR64__(caltim_4, v12);
  ptm->tm_min = v18 / 60;
  ptm->tm_sec = v18 % 60;
  ptm->tm_isdst = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102EF4E1
// Name: __gmtime64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tm *__cdecl _gmtime64(const __int64 *timp)
{
  tm *result; // eax

  result = (tm *)__getgmtimebuf();
  if ( result != nullptr )
    return _gmtime64_s(ptm: result, timp) == 0 ? result : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EF508
// Name: _make__time64_t
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl make__time64_t(int ultflag)
{
  tm *tb; // ecx
  tm *v2; // edi
  int result; // eax
  int tm_mon; // eax
  int v5; // ecx
  __int64 v6; // rax
  bool v7; // cf
  int v8; // esi
  unsigned int v9; // ebx
  unsigned __int64 v10; // rcx
  int tm_isdst; // eax
  int v12; // eax
  int timezone; // [esp+10h] [ebp-44h] BYREF
  int dstbias; // [esp+14h] [ebp-40h] BYREF
  __int64 tmptm2; // [esp+18h] [ebp-3Ch]
  unsigned int v16; // [esp+20h] [ebp-34h]
  __int64 tmptm1; // [esp+24h] [ebp-30h] BYREF
  tm tbtemp; // [esp+2Ch] [ebp-28h] BYREF

  v2 = tb;
  dstbias = 0;
  timezone = 0;
  if ( tb == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  tmptm1 = tb->tm_year;
  if ( (unsigned __int64)((int)tmptm1 - 69LL) > 0x408 )
    goto err_mktime;
  tm_mon = tb->tm_mon;
  if ( (unsigned int)tm_mon >= 0xC )
  {
    v5 = tm_mon % 12;
    v6 = tm_mon / 12;
    v7 = __CFADD__((_DWORD)v6, (_DWORD)tmptm1);
    LODWORD(tmptm1) = v6 + tmptm1;
    v2->tm_mon = v5;
    HIDWORD(tmptm1) += HIDWORD(v6) + v7;
    if ( v5 < 0 )
    {
      v7 = (_DWORD)tmptm1 != 0;
      LODWORD(tmptm1) = tmptm1 - 1;
      v2->tm_mon = v5 + 12;
      HIDWORD(tmptm1) = v7 + HIDWORD(tmptm1) - 1;
    }
    if ( (unsigned __int64)(tmptm1 - 69) > 0x408 )
      goto err_mktime;
  }
  v8 = v2->tm_mon;
  tmptm2 = _days[v8];
  if ( (tmptm1 % 4 == 0 && tmptm1 % 100 != 0 || (tmptm1 + 1900) % 400 == 0) && v8 > 1 )
    ++tmptm2;
  v9 = (tmptm1 - 1) / 4 + v2->tm_mday + (tmptm1 + 299) / 400 - (tmptm1 - 1) / 100;
  v16 = (unsigned __int64)((tmptm1 - 1) / 4 + v2->tm_mday + (tmptm1 + 299) / 400 - (tmptm1 - 1) / 100) >> 32;
  v10 = 60 * (60 * (24 * (tmptm2 + 365 * tmptm1 + __PAIR64__(v16, v9) - 25567) + v2->tm_hour) + v2->tm_min);
  tmptm1 = v10 + v2->tm_sec;
  if ( ultflag != 0 )
  {
    __tzset(a1: v10);
    if ( _get_dstbias(_Daylight_savings_bias: &dstbias) != 0 || _get_timezone(_Timezone: &timezone) != 0 )
      _invoke_watson();
    tmptm1 += timezone;
    if ( _localtime64_s(ptm: &tbtemp, ptime: &tmptm1) != 0 )
      goto err_mktime;
    tm_isdst = v2->tm_isdst;
    if ( tm_isdst <= 0 && (tm_isdst >= 0 || tbtemp.tm_isdst <= 0) )
      goto LABEL_24;
    tmptm1 += dstbias;
    v12 = _localtime64_s(ptm: &tbtemp, ptime: &tmptm1);
  }
  else
  {
    v12 = _gmtime64_s(ptm: &tbtemp, timp: &tmptm1);
  }
  if ( v12 == 0 )
  {
LABEL_24:
    result = tmptm1;
    *v2 = tbtemp;
    return result;
  }
err_mktime:
  *_errno() = 22;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102EF7B7
// Name: __mktime64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mktime64()
{
  return make__time64_t(ultflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102EF7C9
// Name: ___ascii_stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __ascii_stricmp(const char *dst, const char *src)
{
  int v4; // eax
  int v5; // ecx

  do
  {
    v4 = *(unsigned __int8 *)dst++;
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
    v5 = *(unsigned __int8 *)src++;
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  while ( v4 != 0 && v4 == v5 );
  return v4 - v5;
}

//------------------------------------------------------------------------------
// Address: 0x102EF802
// Name: __stricmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _stricmp_l(const char *dst, const char *src, localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  const char *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( dst != nullptr )
  {
    v4 = src;
    if ( src != nullptr )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
          v6 = _tolower_l(c: *(unsigned __int8 *)v4++, plocinfo: &_loc_update.localeinfo);
        }
        while ( v5 != 0 && v5 == v6 );
        result = v5 - v6;
      }
      else
      {
        result = __ascii_stricmp(dst, src);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EF8C2
// Name: __stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _stricmp(const char *dst, const char *src)
{
  if ( __locale_changed != 0 )
    return _stricmp_l(dst, src, plocinfo: nullptr);
  if ( dst != nullptr && src != nullptr )
    return __ascii_stricmp(dst, src);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x102EF909
// Name: _tzset_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void tzset_nolock()
{
  unsigned __int8 *v0; // eax
  char *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // edi
  int v7; // edi
  char **v8; // edi
  const char *v9; // esi
  char v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // esi
  int negdiff; // [esp+14h] [ebp-38h]
  UINT lc_cp; // [esp+18h] [ebp-34h]
  int defused; // [esp+1Ch] [ebp-30h] BYREF
  int nochange; // [esp+20h] [ebp-2Ch]
  int dstbias; // [esp+24h] [ebp-28h] BYREF
  int daylight; // [esp+28h] [ebp-24h] BYREF
  char **tzname; // [esp+2Ch] [ebp-20h]
  int timezone; // [esp+30h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  negdiff = 0;
  nochange = 0;
  timezone = 0;
  daylight = 0;
  dstbias = 0;
  _lock(locknum: 7);
  ms_exc.registration.TryLevel = 0;
  tzname = __tzname();
  if ( _get_timezone(_Timezone: &timezone) != 0
    || _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0 )
  {
LABEL_12:
    _invoke_watson();
  }
  lc_cp = ___lc_codepage_func();
  tzapiused = 0;
  dstend.yr = -1;
  dststart.yr = -1;
  v0 = (unsigned __int8 *)_getenv_helper_nolock(option: "TZ");
  v1 = (char *)v0;
  if ( v0 == nullptr || *v0 == 0 )
  {
    if ( lastTZ != nullptr )
    {
      free(pMem: lastTZ);
      lastTZ = nullptr;
    }
    if ( GetTimeZoneInformation(lpTimeZoneInformation: &tzinfo) != -1 )
    {
      tzapiused = 1;
      timezone = 60 * tzinfo.Bias;
      if ( tzinfo.StandardDate.wMonth != 0 )
        timezone = 60 * tzinfo.StandardBias + 60 * tzinfo.Bias;
      if ( tzinfo.DaylightDate.wMonth != 0 && tzinfo.DaylightBias != 0 )
      {
        daylight = 1;
        dstbias = 60 * (tzinfo.DaylightBias - tzinfo.StandardBias);
      }
      else
      {
        daylight = 0;
        dstbias = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.StandardName,
             cchWideChar: -1,
             lpMultiByteStr: *tzname,
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        **tzname = 0;
      }
      else
      {
        (*tzname)[63] = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.DaylightName,
             cchWideChar: -1,
             lpMultiByteStr: tzname[1],
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        *tzname[1] = 0;
      }
      else
      {
        tzname[1][63] = 0;
      }
    }
    goto LABEL_30;
  }
  if ( lastTZ != nullptr )
  {
    strcmp(str1: v0, str2: (unsigned __int8 *)lastTZ);
    if ( v2 == 0 )
    {
LABEL_30:
      nochange = 1;
      goto LABEL_31;
    }
    if ( lastTZ != nullptr )
      free(pMem: lastTZ);
  }
  strlen(buf: v1);
  lastTZ = (char *)MemAlloc_Alloc(nSize: v3 + 1);
  if ( lastTZ == nullptr )
    goto LABEL_30;
  strlen(buf: v1);
  if ( strcpy_s(_Dst: lastTZ, _SizeInBytes: v4 + 1, _Src: v1) != 0 )
    goto LABEL_12;
LABEL_31:
  v5 = timezone;
  *__timezone() = v5;
  v6 = daylight;
  *__daylight() = v6;
  v7 = dstbias;
  *__dstbias() = v7;
  ms_exc.registration.TryLevel = -2;
  _unlock(locknum: 7);
  if ( nochange == 0 )
  {
    v8 = tzname;
    if ( strncpy_s(_Dst: *tzname, _SizeInBytes: 0x40u, _Src: v1, _Count: 3u) != 0 )
      goto LABEL_12;
    v9 = v1 + 3;
    if ( *v9 == 45 )
    {
      negdiff = 1;
      ++v9;
    }
    timezone = 3600 * atol(nptr: v9);
    while ( 1 )
    {
      v10 = *v9;
      if ( *v9 != 43 && (v10 < 48 || v10 > 57) )
        break;
      ++v9;
    }
    if ( *v9 == 58 )
    {
      v11 = atol(nptr: ++v9);
      timezone += 60 * v11;
      while ( *v9 >= 48 && *v9 <= 57 )
        ++v9;
      if ( *v9 == 58 )
      {
        v12 = atol(nptr: ++v9);
        timezone += v12;
        while ( *v9 >= 48 && *v9 <= 57 )
          ++v9;
      }
    }
    if ( negdiff != 0 )
      timezone = -timezone;
    daylight = *v9;
    if ( daylight != 0 )
    {
      if ( strncpy_s(_Dst: v8[1], _SizeInBytes: 0x40u, _Src: v9, _Count: 3u) != 0 )
        goto LABEL_12;
    }
    else
    {
      *v8[1] = 0;
    }
    v13 = timezone;
    *__timezone() = v13;
    v14 = daylight;
    *__daylight() = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EFE13
// Name: _isindst_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isindst_nolock@<eax>(tm *tb@<edi>)
{
  int result; // eax
  int tm_year; // edx
  int v3; // eax
  int v4; // ecx
  int tm_yday; // edx
  int v6; // eax
  int endmonth; // [esp+4h] [ebp-Ch]
  int endweek; // [esp+8h] [ebp-8h]
  int daylight; // [esp+Ch] [ebp-4h] BYREF

  daylight = 0;
  result = _get_daylight(_Daylight: &daylight);
  if ( result != 0 )
    _invoke_watson();
  if ( daylight != 0 )
  {
    tm_year = tb->tm_year;
    if ( tm_year != dststart.yr || tm_year != dstend.yr )
    {
      if ( tzapiused != 0 )
      {
        if ( tzinfo.DaylightDate.wYear != 0 )
          cvtdate(
            trantype: 1,
            datetype: 0,
            year: tm_year,
            month: tzinfo.DaylightDate.wMonth,
            week: 0,
            dayofweek: 0,
            date: tzinfo.DaylightDate.wDay,
            hour: tzinfo.DaylightDate.wHour,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        else
          cvtdate(
            trantype: 1,
            datetype: 1,
            year: tm_year,
            month: tzinfo.DaylightDate.wMonth,
            week: tzinfo.DaylightDate.wDay,
            dayofweek: tzinfo.DaylightDate.wDayOfWeek,
            date: 0,
            hour: tzinfo.DaylightDate.wHour,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        if ( tzinfo.StandardDate.wYear != 0 )
          cvtdate(
            trantype: 0,
            datetype: 0,
            year: tb->tm_year,
            month: tzinfo.StandardDate.wMonth,
            week: 0,
            dayofweek: 0,
            date: tzinfo.StandardDate.wDay,
            hour: tzinfo.StandardDate.wHour,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
        else
          cvtdate(
            trantype: 0,
            datetype: 1,
            year: tb->tm_year,
            month: tzinfo.StandardDate.wMonth,
            week: tzinfo.StandardDate.wDay,
            dayofweek: tzinfo.StandardDate.wDayOfWeek,
            date: 0,
            hour: tzinfo.StandardDate.wHour,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
      }
      else
      {
        v3 = 3;
        v4 = 2;
        endmonth = 11;
        endweek = 1;
        if ( tm_year < 107 )
        {
          v3 = 4;
          v4 = 1;
          endmonth = 10;
          endweek = 5;
        }
        cvtdate(
          trantype: 1,
          datetype: 1,
          year: tm_year,
          month: v3,
          week: v4,
          dayofweek: 0,
          date: 0,
          hour: 2,
          min: 0,
          sec: 0,
          msec: 0);
        cvtdate(
          trantype: 0,
          datetype: 1,
          year: tb->tm_year,
          month: endmonth,
          week: endweek,
          dayofweek: 0,
          date: 0,
          hour: 2,
          min: 0,
          sec: 0,
          msec: 0);
      }
    }
    tm_yday = tb->tm_yday;
    if ( dststart.yd >= dstend.yd )
    {
      if ( tm_yday < dstend.yd || tm_yday > dststart.yd )
        return 1;
      if ( tm_yday <= dstend.yd || tm_yday >= dststart.yd )
        goto LABEL_28;
    }
    else if ( tm_yday >= dststart.yd && tm_yday <= dstend.yd )
    {
      if ( tm_yday > dststart.yd && tm_yday < dstend.yd )
        return 1;
LABEL_28:
      v6 = 1000 * (tb->tm_sec + 60 * (tb->tm_min + 60 * tb->tm_hour));
      if ( tm_yday == dststart.yd )
        return v6 >= dststart.ms;
      else
        return v6 < dstend.ms;
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EFFEA
// Name: ___tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __tzset()
{
  if ( first_time == 0 )
  {
    _lock(locknum: 6);
    if ( first_time == 0 )
    {
      tzset_nolock();
      ++first_time;
    }
    _unlock(locknum: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F0039
// Name: __tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _tzset()
{
  _lock(locknum: 6);
  tzset_nolock();
  _unlock(locknum: 6);
}

//------------------------------------------------------------------------------
// Address: 0x102F0071
// Name: __isindst
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isindst(tm *tb)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 6);
  retval = isindst_nolock(tb);
  _unlock(locknum: 6);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102F00B2
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _CRT_INIT(void *hDllHandle, unsigned int dwReason, void *lpreserved)
{
  vgui::PropertyPage *v4; // ecx
  vgui::PropertyPage *v5; // ecx
  _tiddata *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, _tiddata *); // eax
  unsigned int v9; // [esp-8h] [ebp-30h]
  _tiddata *v10; // [esp-4h] [ebp-2Ch]

  if ( dwReason == 1 )
  {
    if ( _heap_init() == 0 )
      return 0;
    if ( _mtinit() == 0 )
    {
LABEL_5:
      CColorBalanceUIPanel::Init(this: v4);
      return 0;
    }
    _RTC_Initialize();
    _acmdln = GetCommandLineA();
    _aenvptr = __crtGetEnvironmentStringsA();
    if ( _ioinit() < 0 )
    {
LABEL_7:
      _mtterm();
      goto LABEL_5;
    }
    if ( _setargv() < 0 || _setenvp() < 0 || _cinit(initFloatingPrecision: 0) != 0 )
    {
      _ioterm();
      goto LABEL_7;
    }
    ++_proc_attached;
  }
  else if ( dwReason != 0 )
  {
    if ( dwReason == 2 )
    {
      __set_flsgetvalue();
      v6 = (_tiddata *)calloc(count: 1u, size: 0x214u);
      v7 = v6;
      if ( v6 == nullptr )
        return 0;
      v10 = v6;
      v9 = __flsindex;
      v8 = (int (__stdcall *)(unsigned int, _tiddata *))DecodePointer(Ptr: gpFlsSetValue);
      if ( v8(a1: v9, a2: v10) == 0 )
      {
        free(pMem: v7);
        return 0;
      }
      _initptd(ptd: v7, ptloci: nullptr);
      v7->_tid = GetCurrentThreadId();
      v7->_thandle = -1;
    }
    else if ( dwReason == 3 )
    {
      _freeptd(ptd: nullptr);
    }
  }
  else
  {
    if ( _proc_attached <= 0 )
      return 0;
    --_proc_attached;
    if ( _C_Termination_Done == 0 )
      _cexit();
    if ( lpreserved == nullptr )
    {
      _ioterm();
      _mtterm();
      CColorBalanceUIPanel::Init(this: v5);
      if ( __flsindex != -1 )
        _mtterm();
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F0216
// Name: __DllMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _DllMainCRTStartup(void *lpreserved, unsigned int dwReason, HINSTANCE hDllHandle)
{
  BOOL v5; // eax
  int retcode; // [esp+10h] [ebp-1Ch]

  if ( dwReason == 0 && _proc_attached == 0
    || (dwReason == 1 || dwReason == 2) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
  {
    return 0;
  }
  v5 = DllMain(hinstDLL: hDllHandle, fdwReason: dwReason, lpvReserved: lpreserved);
  retcode = v5;
  if ( dwReason == 1 && !v5 )
  {
    DllMain(hinstDLL: hDllHandle, fdwReason: 0, lpvReserved: lpreserved);
    _CRT_INIT(hDllHandle, dwReason: 0, lpreserved);
  }
  if ( (dwReason == 0 || dwReason == 3) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
    return 0;
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x102F030C
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    __security_init_cookie();
  return _DllMainCRTStartup(lpreserved: lpReserved, dwReason: fdwReason, hDllHandle: hinstDLL);
}

//------------------------------------------------------------------------------
// Address: 0x102F032F
// Name: ___libm_sse2_sin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_sin@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(X, 3) & 0x7FF0) != 0x7FF0 )
    return sin(X: *(double *)X.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F04E7
// Name: ___libm_sse2_acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_acos()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102F098A
// Name: ___libm_sse2_pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_pow()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102F1402
// Name: ___libm_sse2_atan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_atan()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102F1614
// Name: ___libm_sse2_log
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __libm_sse2_log(__m128d a1@<xmm0>)
{
  __m128i v1; // xmm5
  int v2; // eax
  __m128d v3; // xmm6
  unsigned int v4; // ecx
  __m128d v5; // xmm0
  double i; // [esp+4h] [ebp-8h]

  for ( i = a1.m128d_f64[0]; ; a1.m128d_f64[0] = i * *(double *)Two52 )
  {
    v1 = (__m128i)a1;
    a1 = _mm_or_pd(_mm_and_pd(_mm_unpacklo_pd(a1, a1), *(__m128d *)emask), *(__m128d *)One);
    v2 = _mm_extract_epi16((__m128i)_mm_add_pd(*(__m128d *)Magic, a1), 0) & 0x7F0;
    v3 = _mm_and_pd(*(__m128d *)hi_mask, a1);
    a1.m128d_f64[1] = _mm_add_pd(
                        _mm_mul_pd(_mm_sub_pd(a1, v3), *(__m128d *)((char *)B_Tbl + v2)),
                        _mm_sub_pd(_mm_mul_pd(v3, *(__m128d *)((char *)B_Tbl + v2)), *(__m128d *)One)).m128d_f64[1];
    v4 = (_mm_extract_epi16(_mm_srli_epi64(v1, 0x34u), 0) & 0xFFF) - 1;
    if ( v4 <= 0x7FD )
      break;
    v5.m128d_f64[0] = i;
    if ( _mm_extract_epi16((__m128i)_mm_cmpeq_sd(*(__m128d *)Zero, v5), 0) != 0 || v4 != -1 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F183A
// Name: ___libm_sse2_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_exp@<st0>(__m128d a1@<xmm0>)
{
  __m128d v1; // xmm0
  int v2; // eax
  __m128i v3; // xmm7
  __m128d v4; // xmm1
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  __m128d v8; // xmm0
  __m128d v9; // xmm2
  __m128d v10; // xmm4
  __m128d v11; // xmm0
  __m128d v12; // xmm0
  __m128i v13; // xmm2
  double v14; // xmm0_8
  int v15; // edx
  int v16; // eax
  double result; // st7
  double v18; // [esp+8h] [ebp-16h]

  v1 = _mm_unpacklo_pd(a1, a1);
  v2 = _mm_extract_epi16((__m128i)v1, 3) & 0x7FFF;
  if ( ((v2 - 15504) | (unsigned int)(16527 - v2)) < 0x80000000 )
  {
    v3 = (__m128i)_mm_add_pd(_mm_mul_pd(*(__m128d *)cv_0, v1), *(__m128d *)Shifter_0);
    v4 = _mm_sub_pd((__m128d)v3, *(__m128d *)Shifter_0);
    v5 = _mm_cvtsi128_si32(v3);
    v6 = 4 * (v5 & 0x3F);
    v7 = v5 >> 6;
    v8 = _mm_sub_pd(_mm_sub_pd(v1, _mm_mul_pd(*(__m128d *)&cv_0[4], v4)), _mm_mul_pd(*(__m128d *)&cv_0[8], v4));
    v9 = *(__m128d *)&Tbl_addr_0[v6];
    v10 = _mm_mul_pd(*(__m128d *)&cv_0[12], v8);
    v4.m128d_f64[0] = v8.m128d_f64[0];
    v11 = _mm_mul_pd(v8, v8);
    v11.m128d_f64[0] = v11.m128d_f64[0] * v11.m128d_f64[0];
    v12 = _mm_mul_pd(v11, _mm_add_pd(*(__m128d *)&cv_0[16], v10));
    v4.m128d_f64[0] = v4.m128d_f64[0] + v9.m128d_f64[0] + v12.m128d_f64[0];
    v13 = (__m128i)_mm_or_pd(
                     _mm_unpackhi_pd(v9, v9),
                     (__m128d)_mm_slli_epi64(
                                _mm_add_epi64(
                                  _mm_and_si128(v3, _mm_load_si128((const __m128i *)mmask)),
                                  _mm_load_si128((const __m128i *)bias)),
                                0x2Eu));
    v14 = _mm_unpackhi_pd(v12, v12).m128d_f64[0] + v4.m128d_f64[0];
    if ( (unsigned int)(v7 + 894) > 0x77C )
    {
      v15 = v7;
      v16 = v7 >> 1;
      *(_QWORD *)&v18 = _mm_andnot_si128(_mm_load_si128((const __m128i *)emask_0), v13).m128i_u64[0]
                      | (_mm_cvtsi32_si128(v16 + 1023).m128i_u64[0] << 52);
      return (v14 * v18 + v18) * COERCE_DOUBLE(_mm_cvtsi32_si128(v15 - v16 + 1023).m128i_u64[0] << 52);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F1A50
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (abstr & 0x30000) != 0 )
  {
    if ( (abstr & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F1ADE
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = abstr & 0x3000000;
  switch ( v4 )
  {
    case 0x1000000u:
      result |= 0x8040u;
      break;
    case 0x2000000u:
      result |= 0x40u;
      break;
    case 0x3000000u:
      result |= 0x8000u;
      break;
    default:
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F1B7E
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // cx
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  unsigned int v23; // [esp+14h] [ebp-Ch]
  __int16 oldCw; // [esp+1Ch] [ebp-4h]
  unsigned int newabs; // [esp+2Ch] [ebp+Ch]

  v2 = 0;
  if ( (oldCw & 1) != 0 )
    v2 = 16;
  if ( (oldCw & 4) != 0 )
    v2 |= 8u;
  if ( (oldCw & 8) != 0 )
    v2 |= 4u;
  if ( (oldCw & 0x10) != 0 )
    v2 |= 2u;
  if ( (oldCw & 0x20) != 0 )
    v2 |= 1u;
  if ( (oldCw & 2) != 0 )
    v2 |= 0x80000u;
  v3 = oldCw & 0xC00;
  if ( (oldCw & 0xC00) != 0 )
  {
    switch ( v3 )
    {
      case 1024:
        v2 |= 0x100u;
        break;
      case 2048:
        v2 |= 0x200u;
        break;
      case 3072:
        v2 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (oldCw & 0x300) != 0 )
  {
    if ( (oldCw & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (oldCw & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  newabs = result;
  if ( result != v2 )
  {
    v6 = hw_cw(abstr: result);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    newabs = v8;
    result = v8;
  }
  v10 = 0;
  if ( __sse2_available != 0 )
  {
    v11 = _mm_getcsr();
    if ( (v11 & 0x80u) != 0 )
      v10 = 16;
    if ( (v11 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v10 |= 0x80000u;
    v12 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v12 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v13 = (v11 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v15 = newctrl & mask & 0x308031F | v10 & ~(mask & 0x308031F);
    if ( v15 == v10 )
    {
      v16 = v10;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v18 = 0;
      if ( (v17 & 0x80u) != 0 )
        v18 = 16;
      if ( (v17 & 0x200) != 0 )
        v18 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v18 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v18 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v18 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v18 |= 0x80000u;
      v19 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v19 )
        {
          case 8192:
            v18 |= 0x100u;
            break;
          case 16384:
            v18 |= 0x200u;
            break;
          case 24576:
            v18 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v20 = (v17 & 0x8040) - 64;
      if ( v20 != 0 )
      {
        v21 = v20 - 32704;
        if ( v21 != 0 )
        {
          if ( v21 == 64 )
            v18 |= 0x1000000u;
        }
        else
        {
          v18 |= 0x3000000u;
        }
      }
      else
      {
        v18 |= 0x2000000u;
      }
      v16 = v18;
    }
    v22 = newabs ^ v16;
    result = newabs | v16;
    if ( (v22 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F1E90
// Name: __controlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _controlfp(unsigned int newctrl, unsigned int mask)
{
  unsigned int v2; // edi
  int v3; // edx
  unsigned int v4; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // dx
  int v18; // ecx
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  unsigned int v22; // [esp+10h] [ebp-10h]
  unsigned int v23; // [esp+18h] [ebp-8h]

  v2 = mask & 0xFFF7FFFF;
  v3 = 0;
  if ( (mask & 1) != 0 )
    v3 = 16;
  if ( (mask & 4) != 0 )
    v3 |= 8u;
  if ( (mask & 8) != 0 )
    v3 |= 4u;
  if ( (mask & 0x10) != 0 )
    v3 |= 2u;
  if ( (mask & 0x20) != 0 )
    v3 |= 1u;
  if ( (mask & 2) != 0 )
    v3 |= 0x80000u;
  v4 = mask & 0xC00;
  if ( (mask & 0xC00) != 0 )
  {
    switch ( v4 )
    {
      case 0x400u:
        v3 |= 0x100u;
        break;
      case 0x800u:
        v3 |= 0x200u;
        break;
      case 0xC00u:
        v3 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (mask & 0x300) != 0 )
  {
    if ( (mask & 0x300) == 0x200 )
      v3 |= 0x10000u;
  }
  else
  {
    v3 |= 0x20000u;
  }
  if ( (mask & 0x1000) != 0 )
    v3 |= 0x40000u;
  result = newctrl & v2 | v3 & ~v2;
  v22 = result;
  if ( result != v3 )
  {
    v6 = hw_cw(abstr: newctrl & v2 | v3 & ~v2);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    result = v8;
    v22 = v8;
  }
  v10 = 0;
  if ( __sse2_available != 0 )
  {
    v11 = _mm_getcsr();
    if ( (v11 & 0x80u) != 0 )
      v10 = 16;
    if ( (v11 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v10 |= 0x80000u;
    v12 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v12 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v13 = (v11 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v15 = newctrl & mask & 0x300031F | v10 & ~(mask & 0x300031F);
    if ( v15 == v10 )
    {
      v16 = v10;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v16 = 0;
      if ( (v17 & 0x80u) != 0 )
        v16 = 16;
      if ( (v17 & 0x200) != 0 )
        v16 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v16 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v16 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v16 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v16 |= 0x80000u;
      v18 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v18 )
        {
          case 8192:
            v16 |= 0x100u;
            break;
          case 16384:
            v16 |= 0x200u;
            break;
          case 24576:
            v16 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v19 = (v17 & 0x8040) - 64;
      if ( v19 != 0 )
      {
        v20 = v19 - 32704;
        if ( v20 != 0 )
        {
          if ( v20 == 64 )
            v16 |= 0x1000000u;
        }
        else
        {
          v16 |= 0x3000000u;
        }
      }
      else
      {
        v16 |= 0x2000000u;
      }
    }
    v21 = v22 ^ v16;
    result = v22 | v16;
    if ( (v21 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F21A5
// Name: void __ArrayUnwind(void __near *,unsigned int,int,void (*)(void __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __ArrayUnwind(char *ptr, unsigned int size, int count, void (*pDtor)(void))
{
  while ( --count >= 0 )
  {
    ptr -= size;
    pDtor();
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F22CB
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(unsigned int cookie)
{
  if ( cookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x102F22E0
// Name: __ftol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __usercall _ftol@<edx:eax>(double a1@<st0>)
{
  return (__int64)a1;
}

//------------------------------------------------------------------------------
// Address: 0x102F2310
// Name: __CIsqrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x102F23CA
// Name: __mbscmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbscmp_l(unsigned __int8 *s1, unsigned __int8 *s2, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // esi
  __int16 v5; // cx
  __int16 v6; // ax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = s1;
  if ( s1 != nullptr )
  {
    v4 = s2;
    if ( s2 != nullptr )
    {
      if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
      {
        while ( 1 )
        {
          v5 = *v3++;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v5 + 1] & 4) != 0 )
          {
            if ( *v3 != 0 )
              v5 = *v3++ | (unsigned __int16)(v5 << 8);
            else
              v5 = 0;
          }
          v6 = *v4++;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) != 0 )
          {
            if ( *v4 != 0 )
              v6 = *v4++ | (unsigned __int16)(v6 << 8);
            else
              v6 = 0;
          }
          if ( v6 != v5 )
            break;
          if ( v5 == 0 )
          {
            if ( _loc_update.updated )
              _loc_update.ptd->_ownlocale &= ~2u;
            return;
          }
        }
      }
      else
      {
        strcmp(str1: s1, str2: s2);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F24C9
// Name: __mbscmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbscmp(unsigned __int8 *s1, unsigned __int8 *s2)
{
  _mbscmp_l(s1, s2, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F24E0
// Name: __ungetc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ungetc_nolock(int ch, _iobuf *str)
{
  int v2; // eax
  ioinfo *v3; // ecx
  ioinfo *v4; // eax
  int flag; // eax
  char *v7; // eax
  int v8; // eax

  if ( (str->_flag & 0x40) == 0 )
  {
    v2 = fileno(stream: str);
    if ( v2 == -1 || v2 == -2 )
      v3 = &__badioinfo;
    else
      v3 = &__pioinfo[v2 >> 5][v2 & 0x1F];
    if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0
      || (v2 == -1 || v2 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v2 >> 5][v2 & 0x1F]), *((char *)v4 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( ch == -1 )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( str->_base == nullptr )
    _getbuf(str);
  if ( str->_ptr == str->_base )
  {
    if ( str->_cnt != 0 )
      return -1;
    ++str->_ptr;
  }
  v7 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v7 != (_BYTE)ch )
    {
      str->_ptr = v7 + 1;
      return -1;
    }
  }
  else
  {
    *v7 = ch;
  }
  v8 = str->_flag;
  ++str->_cnt;
  str->_flag = v8 & 0xFFFFFFEE | 1;
  return (unsigned __int8)ch;
}

//------------------------------------------------------------------------------
// Address: 0x102F25C3
// Name: _ungetc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ungetc(int ch, _iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ungetc_nolock(ch, str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F262C
// Name: _fgetc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fgetc(_iobuf *stream)
{
  int v2; // eax
  ioinfo *v3; // ecx
  ioinfo *v4; // eax
  int v6; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    if ( (stream->_flag & 0x40) == 0 )
    {
      v2 = fileno(stream);
      if ( v2 == -1 || v2 == -2 )
        v3 = &__badioinfo;
      else
        v3 = &__pioinfo[v2 >> 5][v2 & 0x1F];
      if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0
        || (v2 == -1 || v2 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v2 >> 5][v2 & 0x1F]), *((char *)v4 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      if ( --stream->_cnt < 0 )
        v6 = _filbuf(str: stream);
      else
        v6 = *(unsigned __int8 *)stream->_ptr++;
      retval = v6;
    }
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F2720
// Name: _ferror
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ferror(_iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_flag & 0x20;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return 0;
}

} // namespace engine_xlsp
