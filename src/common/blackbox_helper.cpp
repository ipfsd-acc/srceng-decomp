// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/blackbox_helper.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10023B30
// Name: void BlackBox_Record(char const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __usercall BlackBox_Record(int a1@<edi>, int a2@<esi>, const char *type, const char *pFormat, ...)
{
  int v4; // esi
  const char *v5; // eax
  char szMessage[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list params; // [esp+410h] [ebp+10h] BYREF

  va_start(params, pFormat);
  if ( (_S5_7 & 1) == 0 )
  {
    _S5_7 |= 1u;
    ConVarRef::ConVarRef(this: &blackbox, pName: "blackbox");
  }
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&blackbox) && blackbox.m_pConVarState->m_Value.m_nValue != 0 )
  {
    v4 = 0;
    if ( ((int (__thiscall *)(IBlackBox *, int, int))blackboxrecorder->GetTypeCount)(
           a1: blackboxrecorder,
           a2: a1,
           a3: a2) > 0 )
    {
      do
      {
        v5 = blackboxrecorder->GetTypeName(this: blackboxrecorder, a2: v4);
        if ( V_strcasecmp(s1: v5, s2: type) == 0 )
          break;
        ++v4;
      }
      while ( v4 < blackboxrecorder->GetTypeCount(this: blackboxrecorder) );
    }
    if ( v4 < blackboxrecorder->GetTypeCount(this: blackboxrecorder) )
    {
      V_vsnprintf(pDest: szMessage, maxLen: 0x400u, pFormat, params);
      blackboxrecorder->Record(this: blackboxrecorder, a2: v4, a3: szMessage);
    }
    else
    {
      _Msg(a1: "Invalid blackbox type: %s\n", type);
    }
  }
}
