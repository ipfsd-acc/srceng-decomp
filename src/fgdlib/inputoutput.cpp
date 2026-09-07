// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fgdlib/inputoutput.cpp
// Functions: 5
// ============================================================

#include "fgdlib\inputoutput.h"

//------------------------------------------------------------------------------
// Address: 0x101F70B0
// Name: public: char const __near * CClassInputOutputBase::GetTypeText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CClassInputOutputBase::GetTypeText(CClassInputOutputBase *this)
{
  InputOutputType_t m_eType; // ecx
  int v2; // eax

  m_eType = this->m_eType;
  v2 = 0;
  while ( TypeMap_0[v2].eType != m_eType )
  {
    if ( (unsigned int)++v2 >= 0xA )
      return "unknown";
  }
  return TypeMap_0[v2].pszName;
}

//------------------------------------------------------------------------------
// Address: 0x101F70E0
// Name: public: enum InputOutputType_t CClassInputOutputBase::SetType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
InputOutputType_t __thiscall CClassInputOutputBase::SetType(CClassInputOutputBase *this, const char *szType)
{
  int v3; // esi
  InputOutputType_t result; // eax

  v3 = 0;
  while ( _V_stricmp(s1: TypeMap_0[v3].pszName, s2: szType) != 0 )
  {
    if ( (unsigned int)++v3 >= 0xA )
      return iotInvalid;
  }
  result = TypeMap_0[v3].eType;
  this->m_eType = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F7130
// Name: public: class CClassInputOutputBase __near & CClassInputOutputBase::operator=(class CClassInputOutputBase __near &)
// Source: json
//------------------------------------------------------------------------------
CClassInputOutputBase *__thiscall CClassInputOutputBase::operator=(
        CClassInputOutputBase *this,
        CClassInputOutputBase *Other)
{
  char *m_szName; // eax
  int v4; // edx
  char v5; // cl
  char *v6; // eax
  char *v7; // eax
  char *v8; // ecx
  char *v9; // edx
  char v10; // al
  char *m_pszDescription; // [esp-4h] [ebp-Ch]

  m_szName = Other->m_szName;
  v4 = (char *)this - (char *)Other;
  do
  {
    v5 = *m_szName;
    m_szName[v4] = *m_szName;
    ++m_szName;
  }
  while ( v5 != 0 );
  m_pszDescription = this->m_pszDescription;
  this->m_eType = Other->m_eType;
  operator delete(p: m_pszDescription);
  v6 = Other->m_pszDescription;
  if ( v6 != nullptr )
  {
    v7 = (char *)operator new(nSize: strlen(v6) + 1);
    this->m_pszDescription = v7;
    v8 = Other->m_pszDescription;
    v9 = v7;
    do
    {
      v10 = *v8;
      *v9++ = *v8++;
    }
    while ( v10 != 0 );
    return this;
  }
  else
  {
    this->m_pszDescription = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F71C0
// Name: public: CClassInput::CClassInput(void)
// Source: json
//------------------------------------------------------------------------------
CClassInput *__thiscall CClassInput::CClassInput(CClassInput *this)
{
  this->m_eType = iotInvalid;
  this->m_pszDescription = nullptr;
  this->__vftable = (CClassInput_vtbl *)&CClassInput::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F71E0
// Name: public: CClassOutput::CClassOutput(void)
// Source: json
//------------------------------------------------------------------------------
CClassOutput *__thiscall CClassOutput::CClassOutput(CClassOutput *this)
{
  this->m_eType = iotInvalid;
  this->m_pszDescription = nullptr;
  this->__vftable = (CClassOutput_vtbl *)&CClassOutput::`vftable';
  return this;
}

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100FBEA0
// Name: public: enum InputOutputType_t CClassInputOutputBase::SetType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
InputOutputType_t __thiscall CClassInputOutputBase::SetType(CClassInputOutputBase *this, const char *szType)
{
  int v3; // esi
  InputOutputType_t result; // eax

  v3 = 0;
  while ( _V_stricmp(s1: TypeMap_0[v3].pszName, s2: szType) != 0 )
  {
    if ( (unsigned int)++v3 >= 0xA )
      return iotInvalid;
  }
  result = TypeMap_0[v3].eType;
  this->m_eType = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FBEF0
// Name: public: class CClassInputOutputBase __near & CClassInputOutputBase::operator=(class CClassInputOutputBase __near &)
// Source: json
//------------------------------------------------------------------------------
CClassInputOutputBase *__thiscall CClassInputOutputBase::operator=(
        CClassInputOutputBase *this,
        CClassInputOutputBase *Other)
{
  char *m_szName; // eax
  int v4; // edx
  char v5; // cl
  char *v6; // eax
  char *v7; // eax
  char *v8; // ecx
  char *v9; // edx
  char v10; // al
  char *m_pszDescription; // [esp-4h] [ebp-Ch]

  m_szName = Other->m_szName;
  v4 = (char *)this - (char *)Other;
  do
  {
    v5 = *m_szName;
    m_szName[v4] = *m_szName;
    ++m_szName;
  }
  while ( v5 != 0 );
  m_pszDescription = this->m_pszDescription;
  this->m_eType = Other->m_eType;
  free(pMem: m_pszDescription);
  v6 = Other->m_pszDescription;
  if ( v6 != nullptr )
  {
    v7 = (char *)operator new(nSize: strlen(v6) + 1);
    this->m_pszDescription = v7;
    v8 = Other->m_pszDescription;
    v9 = v7;
    do
    {
      v10 = *v8;
      *v9++ = *v8++;
    }
    while ( v10 != 0 );
    return this;
  }
  else
  {
    this->m_pszDescription = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FBF80
// Name: public: CClassInput::CClassInput(void)
// Source: json
//------------------------------------------------------------------------------
CClassInput *__thiscall CClassInput::CClassInput(CClassInput *this)
{
  this->m_eType = iotInvalid;
  this->m_pszDescription = nullptr;
  this->__vftable = (CClassInput_vtbl *)&CClassInput::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FBFA0
// Name: public: CClassOutput::CClassOutput(void)
// Source: json
//------------------------------------------------------------------------------
CClassOutput *__thiscall CClassOutput::CClassOutput(CClassOutput *this)
{
  this->m_eType = iotInvalid;
  this->m_pszDescription = nullptr;
  this->__vftable = (CClassOutput_vtbl *)&CClassOutput::`vftable';
  return this;
}

} // namespace missionchooser

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00454360
// Name: public: enum InputOutputType_t CClassInputOutputBase::SetType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
InputOutputType_t __thiscall CClassInputOutputBase::SetType(CClassInputOutputBase *this, const char *szType)
{
  int v3; // esi
  InputOutputType_t result; // eax

  v3 = 0;
  while ( _V_stricmp(s1: TypeMap_0[v3].pszName, s2: szType) != 0 )
  {
    if ( (unsigned int)++v3 >= 0xA )
      return iotInvalid;
  }
  result = TypeMap_0[v3].eType;
  this->m_eType = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004543B0
// Name: public: class CClassInputOutputBase __near & CClassInputOutputBase::operator=(class CClassInputOutputBase __near &)
// Source: json
//------------------------------------------------------------------------------
CClassInputOutputBase *__thiscall CClassInputOutputBase::operator=(
        CClassInputOutputBase *this,
        CClassInputOutputBase *Other)
{
  char *m_szName; // eax
  int v4; // edx
  char v5; // cl
  char *v6; // eax
  char *v7; // eax
  char *v8; // ecx
  char *v9; // edx
  char v10; // al
  char *m_pszDescription; // [esp-4h] [ebp-Ch]

  m_szName = Other->m_szName;
  v4 = (char *)this - (char *)Other;
  do
  {
    v5 = *m_szName;
    m_szName[v4] = *m_szName;
    ++m_szName;
  }
  while ( v5 != 0 );
  m_pszDescription = this->m_pszDescription;
  this->m_eType = Other->m_eType;
  free(pMem: m_pszDescription);
  v6 = Other->m_pszDescription;
  if ( v6 != nullptr )
  {
    v7 = (char *)MemAlloc_Alloc(nSize: strlen(v6) + 1);
    this->m_pszDescription = v7;
    v8 = Other->m_pszDescription;
    v9 = v7;
    do
    {
      v10 = *v8;
      *v9++ = *v8++;
    }
    while ( v10 != 0 );
    return this;
  }
  else
  {
    this->m_pszDescription = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454440
// Name: public: CClassInput::CClassInput(void)
// Source: json
//------------------------------------------------------------------------------
CClassInput *__thiscall CClassInput::CClassInput(CClassInput *this)
{
  this->m_eType = iotInvalid;
  this->m_pszDescription = nullptr;
  this->__vftable = (CClassInput_vtbl *)&CClassInput::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00454460
// Name: public: CClassOutput::CClassOutput(void)
// Source: json
//------------------------------------------------------------------------------
CClassOutput *__thiscall CClassOutput::CClassOutput(CClassOutput *this)
{
  this->m_eType = iotInvalid;
  this->m_pszDescription = nullptr;
  this->__vftable = (CClassOutput_vtbl *)&CClassOutput::`vftable';
  return this;
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00449DC0
// Name: public: enum InputOutputType_t CClassInputOutputBase::SetType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
InputOutputType_t __thiscall CClassInputOutputBase::SetType(CClassInputOutputBase *this, const char *szType)
{
  int v3; // esi
  InputOutputType_t result; // eax

  v3 = 0;
  while ( _V_stricmp(s1: TypeMap_0[v3].pszName, s2: szType) != 0 )
  {
    if ( (unsigned int)++v3 >= 0xA )
      return iotInvalid;
  }
  result = TypeMap_0[v3].eType;
  this->m_eType = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449E10
// Name: public: class CClassInputOutputBase __near & CClassInputOutputBase::operator=(class CClassInputOutputBase __near &)
// Source: json
//------------------------------------------------------------------------------
CClassInputOutputBase *__thiscall CClassInputOutputBase::operator=(
        CClassInputOutputBase *this,
        CClassInputOutputBase *Other)
{
  char *m_szName; // eax
  int v4; // edx
  char v5; // cl
  char *v6; // eax
  char *v7; // eax
  char *v8; // ecx
  char *v9; // edx
  char v10; // al
  char *m_pszDescription; // [esp-4h] [ebp-Ch]

  m_szName = Other->m_szName;
  v4 = (char *)this - (char *)Other;
  do
  {
    v5 = *m_szName;
    m_szName[v4] = *m_szName;
    ++m_szName;
  }
  while ( v5 != 0 );
  m_pszDescription = this->m_pszDescription;
  this->m_eType = Other->m_eType;
  free(pMem: m_pszDescription);
  v6 = Other->m_pszDescription;
  if ( v6 != nullptr )
  {
    v7 = (char *)operator new(nSize: strlen(v6) + 1);
    this->m_pszDescription = v7;
    v8 = Other->m_pszDescription;
    v9 = v7;
    do
    {
      v10 = *v8;
      *v9++ = *v8++;
    }
    while ( v10 != 0 );
    return this;
  }
  else
  {
    this->m_pszDescription = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449EA0
// Name: public: CClassInput::CClassInput(void)
// Source: json
//------------------------------------------------------------------------------
CClassInput *__thiscall CClassInput::CClassInput(CClassInput *this)
{
  this->m_eType = iotInvalid;
  this->m_pszDescription = nullptr;
  this->__vftable = (CClassInput_vtbl *)&CClassInput::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00449EC0
// Name: public: CClassOutput::CClassOutput(void)
// Source: json
//------------------------------------------------------------------------------
CClassOutput *__thiscall CClassOutput::CClassOutput(CClassOutput *this)
{
  this->m_eType = iotInvalid;
  this->m_pszDescription = nullptr;
  this->__vftable = (CClassOutput_vtbl *)&CClassOutput::`vftable';
  return this;
}

} // namespace vbsp2
