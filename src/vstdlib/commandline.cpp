// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/commandline.cpp
// Functions: 68
// ============================================================

#include "vstdlib\commandline.h"

//------------------------------------------------------------------------------
// Address: 0x3F601090
// Name: public: CCommandLineParam::CCommandLineParam(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCommandLineParam *__thiscall CCommandLineParam::CCommandLineParam(
        CCommandLineParam *this,
        const char *a2,
        const char *a3)
{
  int v4; // eax

  this->m_hParam = -1;
  if ( (*(int (**)(void))CommandLine)() != 0 )
  {
    v4 = (*(int (**)(void))CommandLine)();
    this->m_hParam = (*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v4 + 48))(a1: v4, a2, a3);
  }
  if ( this->m_hParam == -1 )
    AssertMsgImplementation(
      a1: "Assertion Failed: m_hParam != -1",
      a2: 0,
      a3: ".\\commandline.cpp",
      a4: 104,
      a5: &unk_3F6641EC,
      a6: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F6010F0
// Name: public: CCommandLineParam::~CCommandLineParam(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CCommandLineParam::~CCommandLineParam(CCommandLineParam *this)
{
  int v2; // eax

  if ( (*(int (**)(void))CommandLine)() != 0 )
  {
    v2 = (*(int (**)(void))CommandLine)();
    ((void (__thiscall *)(int))loc_3F601F50)(a1: v2);
  }
  this->m_hParam = -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F601200
// Name: public: bool CCommandLine::CommandLineParam_t::operator==(struct CCommandLine::CommandLineParam_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CCommandLineParam *__userpurge CCommandLine::CommandLineParam_t::operator==@<eax>(
        CCommandLine::CommandLineParam_t *this@<ecx>,
        const CCommandLine::CommandLineParam_t *val,
        const char *a3)
{
  CCommandLineParam *v3; // ecx

  ((void (*)(void))loc_3F601240)();
  if ( ((unsigned __int8)val & 1) != 0 )
    JUMPOUT(0x3F601216);
  return CCommandLineParam::CCommandLineParam(this: v3, pchName: (const char *)val, pchHelpText: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F6012A0
// Name: _CommandLine
// Source: json
//------------------------------------------------------------------------------
void __usercall CommandLine(_BYTE *a1@<eax>)
{
  *a1 |= (unsigned __int8)a1;
  JUMPOUT(0x3F6012A5);
}

//------------------------------------------------------------------------------
// Address: 0x3F601340
// Name: public: CCommandLine::CCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CCommandLine::CCommandLine(
        CCommandLine *this@<ecx>,
        char a2@<cf>,
        char a3@<al>,
        _BYTE **a4@<ebx>,
        FILE *a5@<edi>,
        int a6)
{
  bool v6; // zf
  signed int v7; // esi
  char *v8; // ecx
  _BYTE *v9; // eax

  if ( !a2 )
  {
    v6 = a3 + *((_BYTE *)a4 - 12843836) == 0;
    *((_BYTE *)a4 - 12843836) += a3;
    if ( !v6 )
    {
      v7 = STACK[0x114] - 2;
      do
      {
        if ( a3 == 10 )
          a3 = 32;
        v8 = *a4;
        *v8 = a3;
        *a4 = v8 + 1;
        if ( (int)&v8[-a6 + 1] >= v7 )
          break;
        a3 = fgetc(Stream: a5);
      }
      while ( a3 != -1 );
    }
    v9 = *a4;
    *v9 = 32;
    *a4 = v9 + 1;
    fclose_0(Stream: a5);
    JUMPOUT(0x3F60138E);
  }
  JUMPOUT(0x3F601344);
}

//------------------------------------------------------------------------------
// Address: 0x3F6013C0
// Name: public: ICommandLine::ICommandLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICommandLine::ICommandLine(ICommandLine *this)
{
  JUMPOUT(0x3F6013CC);
}

//------------------------------------------------------------------------------
// Address: 0x3F6013D0
// Name: public: virtual CCommandLine::~CCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
void __usercall CCommandLine::~CCommandLine(
        CCommandLine *this@<ecx>,
        _BYTE *a2@<eax>,
        char a3@<bl>,
        int a4,
        int a5,
        char a6)
{
  char *v6; // eax
  char v7; // cl
  int v8; // eax
  size_t v9; // ecx

  *a2 |= (unsigned __int8)a2;
  *((_BYTE *)this - 2012732340) += (_BYTE)this;
  if ( ((unsigned __int8)a2 & 0xC) != 0 )
  {
    v6 = &a6;
    do
      v7 = *v6++;
    while ( v7 != a3 );
    v8 = v6 - (&a6 + 1);
    v9 = 1;
    if ( (unsigned int)(v8 + 1) < 0x800 || (v9 = 2047 - v8, v8 != 2047) )
      strncat_0(Destination: &a6, Source: "\"", Count: v9)[2047] = a3;
    JUMPOUT(0x3F60142D);
  }
  JUMPOUT(0x3F601547);
}

//------------------------------------------------------------------------------
// Address: 0x3F601430
// Name: private: void CCommandLine::LoadParametersFromFile(char const __near * __near &,char __near * __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CCommandLine::LoadParametersFromFile(CCommandLine *this, int maxDestLen, bool bInQuotes)
{
  JUMPOUT(0x3F601432);
}

//------------------------------------------------------------------------------
// Address: 0x3F601530
// Name: public: virtual void CCommandLine::CreateCmdLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CCommandLine::CreateCmdLine(
        CCommandLine *this@<ecx>,
        _BYTE *a2@<eax>,
        int a3@<edx>,
        int a4@<ebx>,
        _BYTE *a5@<edi>,
        int argc,
        char **argv)
{
  char cmdline[2048]; // [esp+8h] [ebp-804h] BYREF

  *(_BYTE *)(a4 - 1405419067) += (_BYTE)a2;
  LOBYTE(a2) = (unsigned __int8)a2 & 0x18;
  *a2 |= (unsigned __int8)a2;
  *a5 += (_BYTE)this;
  *(_WORD *)(a3 - 1946157058) = __FS__;
  this->CreateCmdLine_2(this, a2: &cmdline[8]);
}

//------------------------------------------------------------------------------
// Address: 0x3F601730
// Name: public: virtual void CCommandLine::CreateCmdLine(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CCommandLine::CreateCmdLine(
        CCommandLine *this@<ecx>,
        void (__cdecl *a2)(const char *, _DWORD, const char *, int, void *, _DWORD)@<ebx>,
        const char *commandline,
        const char *a4)
{
  const char *v4; // ebp
  unsigned int v5; // edi
  const char *v6; // eax
  char *v7; // esi
  char *v8; // eax
  char v9; // cl
  size_t v10; // edi
  const char *v11; // ecx
  unsigned int i; // eax

  while ( 1 )
  {
?CreateCmdLine@CCommandLine@@UAEXPBD@Z:
    v4 = *((const char **)commandline + 1);
    v5 = strlen(v4);
    if ( v4 == nullptr )
      a2(a1: "Assertion Failed: ptr", a2: 0, a3: ".\\strtools.cpp", a4: 88, a5: &unk_3F66577F, a6: 0);
    if ( a4 == nullptr )
      a2(a1: "Assertion Failed: ptr", a2: 0, a3: ".\\strtools.cpp", a4: 88, a5: &unk_3F66577F, a6: 0);
    v6 = Q_stristr(a1: v4, a2: a4);
    v7 = (char *)v6;
    if ( v6 == nullptr )
      break;
    v8 = (char *)(v6 + 1);
    if ( v7 != (char *)-1 )
    {
      do
      {
        v9 = *v8;
        if ( *v8 == 0 )
          break;
        if ( v9 == 45 || v9 == 43 )
        {
          if ( *v8 == 0 )
            break;
          v10 = (size_t)&v4[v5 - (_DWORD)v8];
          memcpy_1(a1: v7, Src: v8, Size: v10);
          v7[v10] = 0;
          goto ?CreateCmdLine@CCommandLine@@UAEXPBD@Z;
        }
        ++v8;
      }
      while ( v8 != nullptr );
    }
    memset(a1: v7, Val: 0, Size: v8 - v7);
  }
  v11 = *((const char **)commandline + 1);
  for ( i = strlen(v11); i != 0; i = strlen(v11) )
  {
    if ( v11[i - 1] != 32 )
      break;
    v11[i - 1] = 0;
    v11 = *((const char **)commandline + 1);
  }
  sub_3F601C00();
}

//------------------------------------------------------------------------------
// Address: 0x3F601890
// Name: public: virtual void CCommandLine::RemoveParm(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCommandLine::RemoveParm(
        CCommandLine *this@<ecx>,
        int a2@<eax>,
        int a3@<edx>,
        int a4@<ebx>,
        const char *a5@<ebp>,
        int a6@<edi>,
        int a7@<esi>,
        int hParm,
        int a9,
        int a10,
        const char *a11)
{
  int v11; // esi
  int v12; // esi
  size_t v13; // esi
  char *v14; // ebx
  char *v15; // eax
  _BYTE *v16; // ecx
  char v17; // dl

  *(_DWORD *)(a3 + 29393672) += this;
  if ( (_BYTE)this == 0 )
  {
    v11 = a2 - a3;
    if ( a11 != nullptr )
      v11 += strlen(a11) + 1;
    v12 = v11 + 1;
    if ( *(_DWORD *)(a6 + 4) == 0 )
    {
      *(_DWORD *)(a6 + 4) = (*(int (__thiscall **)(_DWORD, int, const char *, int, _DWORD, _DWORD, int, int))(*g_pMemAllocSteam + 4))(
                              a1: g_pMemAllocSteam,
                              a2: v12,
                              a3: ".\\commandline.cpp",
                              a4: 404,
                              a5: 0,
                              a6: 0,
                              a7,
                              a8: a4);
      JUMPOUT(0x3F6018F1);
    }
    ((void (__stdcall *)(int, const char *))loc_3F601710)(a1: a6, a2: a5);
    v13 = v12 + strlen(*(const char **)(a6 + 4)) + 2;
    v14 = (char *)(*(int (__thiscall **)(_DWORD, size_t, const char *, int, _DWORD, _DWORD, int, int))(*g_pMemAllocSteam + 4))(
                    a1: g_pMemAllocSteam,
                    a2: v13,
                    a3: ".\\commandline.cpp",
                    a4: 421,
                    a5: 0,
                    a6: 0,
                    a7,
                    a8: a4);
    memset(a1: v14, Val: 0, Size: v13);
    v15 = *(char **)(a6 + 4);
    v16 = v14;
    do
    {
      v17 = *v15;
      *v16++ = *v15++;
    }
    while ( v17 != 0 );
    *(_WORD *)&v14[strlen(v14)] = 32;
    strcat(v14, a5);
    if ( a2 != 0 )
    {
      strlen(v14);
      JUMPOUT(0x3F601A2A);
    }
    JUMPOUT(0x3F601A60);
  }
  JUMPOUT(0x3F601892);
}

//------------------------------------------------------------------------------
// Address: 0x3F601A30
// Name: public: virtual void CCommandLine::AppendParm(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CCommandLine::AppendParm(
        CCommandLine *this@<ecx>,
        int _EAX@<eax>,
        __int16 a3@<dx>,
        char *a4@<ebx>,
        _WORD *a5@<edi>,
        int hParm,
        const char *pszValues)
{
  __asm { aas }
  *a5 = a3;
  strcat(a4, (const char *)this);
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(*g_pMemAllocSteam + 24))(
    a1: g_pMemAllocSteam,
    a2: *(_DWORD *)(hParm + 4),
    a3: 0);
  *(_DWORD *)(hParm + 4) = a4;
  sub_3F601C00();
}

//------------------------------------------------------------------------------
// Address: 0x3F601AA0
// Name: sub_3F601AA0
// Source: rtti_class
//------------------------------------------------------------------------------
char *__thiscall sub_3F601AA0(_DWORD *this, int a2, _DWORD *a3)
{
  int v3; // esi
  int v4; // eax
  char *result; // eax
  int v6; // ecx
  char v7; // dl
  char *v8; // ecx
  char v9; // dl
  char *i; // ecx
  int v11; // edx
  char v12; // bl

  if ( a2 >= *(this + 267) )
    return nullptr;
  if ( a2 < 0 )
    return nullptr;
  v3 = 16 * a2 + *(this + 260);
  if ( *(_DWORD *)(v3 + 8) == a2 && *(_DWORD *)(v3 + 12) != a2 )
    return nullptr;
  v4 = *(_DWORD *)(16 * a2 + *(this + 260));
  if ( v4 == 0 )
    return nullptr;
  if ( a3 != nullptr )
    *a3 = 0;
  v6 = *(this + 1);
  if ( v6 == 0 )
    return nullptr;
  result = (char *)Q_stristr(a1: v6, a2: v4);
  if ( result != nullptr && a3 != nullptr )
  {
    v7 = *result;
    v8 = result;
    if ( *result != 0 )
    {
      while ( v7 != 32 )
      {
        v7 = *++v8;
        if ( v7 == 0 )
          return result;
      }
    }
    v9 = *v8;
    if ( *v8 != 0 && v9 != 43 && v9 != 45 )
    {
      for ( i = v8 + 1; *i == 32; ++i )
        ;
      v11 = 0;
      do
      {
        v12 = *i;
        if ( *i == 0 )
          break;
        if ( v12 == 32 )
          break;
        byte_3F665F20[v11++] = v12;
        ++i;
      }
      while ( v11 < 127 );
      byte_3F665F20[v11] = 0;
      *a3 = byte_3F665F20;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F601C90
// Name: public: virtual char const __near * CCommandLine::GetCmdLine(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F601CA0
// Name: public: virtual char const __near * CCommandLine::CheckParm(int,char const __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const char *__usercall CCommandLine::CheckParm@<eax>(
        CCommandLine *this@<ecx>,
        unsigned __int16 a2@<dx>,
        char *a3@<ebp>)
{
  bool v3; // zf
  const char *result; // eax

  v3 = 32 * *(a3 - 93) == 0;
  *(a3 - 93) *= 32;
  result = (const char *)__indword(a2);
  if ( !v3 )
    return (const char *)sub_3F601B80(Src: a3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F601DD0
// Name: private: void CCommandLine::AddArgument(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CCommandLine::AddArgument(CCommandLine *this@<esi>, int a2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F601E80
// Name: private: void CCommandLine::ParseCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CCommandLine::ParseCommandLine@<st0>(CCommandLine *this@<ecx>, double a2@<st0>, int a3, float a4)
{
  int v5; // eax
  char *v6; // eax

  v5 = this->FindParm(this, a2: a3);
  if ( v5 == 0 )
    return a4;
  if ( v5 == this->m_nParmCount - 1 )
    return a4;
  v6 = this->m_ppParms[v5 + 1];
  if ( *v6 == 45 || *v6 == 43 )
    return a4;
  sub_3F629098(String: v6);
  return (float)a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F601F40
// Name: private: void CCommandLine::CleanUpParms(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CCommandLine::CleanUpParms(CCommandLine *this, int a2, int a3)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F601F90
// Name: public: virtual int CCommandLine::ParmCount(void)const
// Source: json
//------------------------------------------------------------------------------
void __usercall CCommandLine::ParmCount(CCommandLine *this@<ecx>, _DWORD *a2@<eax>)
{
  *a2 += a2;
  *((_BYTE *)a2 + (_DWORD)&unk_3F660FFF - 1063653495) += BYTE1(this);
  JUMPOUT(0x3F601F95);
}

//------------------------------------------------------------------------------
// Address: 0x3F601FA0
// Name: public: virtual int CCommandLine::FindParm(int)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall CCommandLine::FindParm@<eax>(CCommandLine *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  int result; // eax
  int v5; // [esp-14h] [ebp-14h]
  int v6; // [esp-10h] [ebp-10h]

  result = ((int (__stdcall *)(int, int))loc_3F6025D0)(a1: v5, a2: v6);
  *(_DWORD *)(*(_DWORD *)(a4 + 4) + a2 + 12) = *(_DWORD *)(a4 + 24);
  *(_DWORD *)(a4 + 24) = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F602030
// Name: public: virtual char const __near * CCommandLine::GetParm(int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCommandLine::GetParm(
        CCommandLine *this@<ecx>,
        char a2@<zf>,
        void (*a3)(const char *, int, const char *, ...)@<ebx>,
        int a4@<ebp>,
        int a5@<esi>,
        int nIndex)
{
  if ( !a2 )
  {
    a3(
      a1: "console",
      a2: 1,
      a3: "\"%s\" : %s\n",
      *(_DWORD *)(*(_DWORD *)(a4 + 1040) + 16 * a5),
      *(_DWORD *)(*(_DWORD *)(a4 + 1040) + 16 * a5 + 4));
    if ( (unsigned __int8)sub_3F602320(a1: a4 + 1036) == 0 )
      JUMPOUT(0x3F60207E);
    JUMPOUT(0x3F6020B6);
  }
  JUMPOUT(0x3F6020C9);
}

//------------------------------------------------------------------------------
// Address: 0x3F602080
// Name: public: virtual char const __near * CCommandLine::ParmValue(int,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CCommandLine::ParmValue(CCommandLine *this, int hParm, const char *pDefaultVal)
{
  const char *v3; // eax
  int v4; // eax

  v3 = (const char *)((int (__thiscall *)(CCommandLine *))loc_3F6027D0)(a1: this);
  v4 = ((int (*)(const char *, ...))loc_3F6027D0)(a1: "Assertion Failed: %s", v3);
  AssertMsgImplementation(
    a1: v4,
    a2: 0,
    a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
    a4: 284,
    a5: &unk_3F66571D,
    a6: 0);
  JUMPOUT(0x3F6020BC);
}

//------------------------------------------------------------------------------
// Address: 0x3F6020C0
// Name: public: virtual int CCommandLine::ParmValue(int,int)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall CCommandLine::ParmValue@<eax>(
        CCommandLine *this@<ecx>,
        int (__cdecl *a2)(const char *, int, const char *)@<ebx>,
        int a3@<esi>)
{
  if ( a3 != -1 )
    JUMPOUT(0x3F602040);
  return a2(a1: "console", a2: 1, a3: "----------------------------------------\n");
}

//------------------------------------------------------------------------------
// Address: 0x3F602110
// Name: public: virtual float CCommandLine::ParmValue(int,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::ParmValue(CCommandLine *this, int hParm, float flDefaultVal)
{
  *(_BYTE *)(2 * (_DWORD)this + 0x50) = 0;
  __asm { iret }
  JUMPOUT(0x3F602119);
}

//------------------------------------------------------------------------------
// Address: 0x3F602160
// Name: public: virtual int CCommandLine::RegisterParam(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCommandLine::RegisterParam(
        CCommandLine *this@<ecx>,
        char a2@<of>,
        int a3@<eax>,
        char a4@<dl>,
        const char *pchName,
        const char *pchHelpText)
{
  if ( a2 )
  {
    *(_BYTE *)(a3 - 117) += a4;
    __asm { iret }
    JUMPOUT(0x3F602166);
  }
  JUMPOUT(0x3F602164);
}

//------------------------------------------------------------------------------
// Address: 0x3F602240
// Name: private: char const __near * CCommandLine::GetCommandString(int)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const char *__userpurge CCommandLine::GetCommandString@<eax>(
        CCommandLine *this@<ecx>,
        CCommandLine **hParam@<eax>,
        CCommandLine *a3@<edx>,
        int a4@<ebx>,
        int a5@<esi>,
        int a6)
{
  LOBYTE(hParam) = (_BYTE)hParam + 116;
  LOBYTE(this) = *(_BYTE *)(a4 + 72583947) | (unsigned __int8)this;
  *hParam = this;
  hParam[1] = a3;
  return (const char *)a5;
}

//------------------------------------------------------------------------------
// Address: 0x3F6022A0
// Name: public: virtual void CCommandLine::PrintCommandHelp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::PrintCommandHelp(CCommandLine *this, int a2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F6023F0
// Name: public: virtual void CCommandLine::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::Validate(CCommandLine *this, CValidator *validator, char *pchName)
{
  JUMPOUT(0x3F6023F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F6024B0
// Name: public: CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::~CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::~CUtlLinkedList<CCommandLine::CommandLineParam_t,int>(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this)
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
}

//------------------------------------------------------------------------------
// Address: 0x3F6024F0
// Name: public: int CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::AddToTail(struct CCommandLine::CommandLineParam_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::AddToTail(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<eax>,
        const CCommandLine::CommandLineParam_t *src@<edi>,
        int a3@<ebx>,
        int a4@<ebp>,
        int a5@<esi>)
{
  int v6; // [esp-8h] [ebp-8h]
  int v7; // [esp-4h] [ebp-4h]

  __asm { aas }
  ((void (__cdecl *)(const char *, _DWORD, const char *, int))AssertMsgImplementation)(
    a1: "Assertion Failed: IsValidIndex(elem)",
    a2: 0,
    a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
    a4: 606);
  ((void (__stdcall *)(int, int))loc_3F6025D0)(a1: v6, a2: v7);
  *(_DWORD *)(*(_DWORD *)(a5 + 4) + 16 * a4 + 12) = a3;
  JUMPOUT(0x3F60251F);
}

//------------------------------------------------------------------------------
// Address: 0x3F602520
// Name: public: int CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::Find(struct CCommandLine::CommandLineParam_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::Find(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const CCommandLine::CommandLineParam_t *src)
{
  *(_BYTE *)((*(_DWORD *)(a2 + 1200165958) | (unsigned int)this) + 0x75EB146E) |= *(_BYTE *)(a2 + 1200165958)
                                                                                | (unsigned __int8)this;
  if ( a2 >= *(_DWORD *)(a4 + 32) || a2 < 0 )
    goto LABEL_6;
  if ( (unsigned __int8)sub_3F602320(a1: a4) == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(i)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
      a4: 277,
      a5: &unk_3F665723,
      a6: 0);
  if ( *(_DWORD *)(16 * a2 + *(_DWORD *)(a4 + 4) + 8) == a2 )
LABEL_6:
    AssertMsgImplementation(
      a1: "Assertion Failed: IsInList(before)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
      a4: 626,
      a5: &unk_3F665720,
      a6: 0);
  *(_DWORD *)(a3 + 8) = *(_DWORD *)(*(_DWORD *)(a4 + 4) + 16 * a2 + 8);
  JUMPOUT(0x3F60259E);
}

//------------------------------------------------------------------------------
// Address: 0x3F6025A0
// Name: public: void CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::Remove(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<ecx>,
        int a2@<ebx>)
{
  *(_BYTE *)(a2 - 8189825) |= (unsigned __int8)this;
  JUMPOUT(0x3F6025A6);
}

//------------------------------------------------------------------------------
// Address: 0x3F6025B0
// Name: public: int CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::Next(int)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::Next(
        char a1@<cf>,
        char a2@<bl>,
        int a3@<esi>,
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this,
        int a5)
{
  *(_BYTE *)(a3 + 93) += a2 + a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6026B0
// Name: public: bool CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::IsValidIndex(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<ecx>,
        int i@<eax>,
        int a3@<esi>)
{
  int v3; // edi
  const char *v4; // eax

  if ( i == *(_DWORD *)(a3 + 8) )
    sub_3F626080(a1: this);
  if ( *(_DWORD *)(a3 + 32) == -1 )
    AssertMsgImplementation(
      a1: "Assertion Failed: m_TotalElements != InvalidIndex()",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
      a4: 363,
      a5: &unk_3F665722,
      a6: 0);
  v3 = *(_DWORD *)(a3 + 32);
  *(_DWORD *)(a3 + 32) = v3 + 1;
  if ( v3 == -1 )
  {
    v4 = (const char *)sub_3F62928F(a1: &output[800]);
    Error(a1: "%s overflow!\n", v4);
    JUMPOUT(0x3F60270D);
  }
  JUMPOUT(0x3F60271E);
}

//------------------------------------------------------------------------------
// Address: 0x3F602710
// Name: public: void CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::Validate(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<eax>,
        CValidator *validator@<esi>,
        int a3@<edx>,
        CValObject *a4@<edi>)
{
  int v4; // eax

  LOBYTE(this) = (_BYTE)this - 117;
  validator->m_cubThreshold = *(_DWORD *)(16 * (_DWORD)this + a3 + 12);
  v4 = 16 * (_DWORD)a4;
  *(void **)((char *)&validator->m_pValObjectLast->m_pvObj + v4) = a4;
  *(CValObject **)((char *)&validator->m_pValObjectLast->m_pValObjectParent + v4) = a4;
  validator->m_cubLeaked = (int)validator->m_pValObjectLast;
}

//------------------------------------------------------------------------------
// Address: 0x3F602770
// Name: public: struct CCommandLine::CommandLineParam_t const __near & CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const CCommandLine::CommandLineParam_t *__usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::operator[]@<eax>(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<edi>,
        int i@<esi>,
        char a3@<cf>,
        int _EAX@<eax>,
        int a5@<ebx>)
{
  *(_BYTE *)(a5 + 101) -= a3 + _EAX;
  __asm { aas }
  return (const CCommandLine::CommandLineParam_t *)(*(_DWORD *)(16 * i + this->m_Memory.m_nAllocationCount + 8) != i);
}

//------------------------------------------------------------------------------
// Address: 0x3F6027B0
// Name: protected: void CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::ResetDbgInfo(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::ResetDbgInfo(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<ecx>,
        int a2@<eax>)
{
  *((_BYTE *)&unk_3F660FFF + a2 - 1063653379) += BYTE1(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F6027F0
// Name: public: int CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::InsertBefore(int,struct CCommandLine::CommandLineParam_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::InsertBefore@<eax>(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<eax>,
        void *a2@<ecx>)
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  return memset(a1: a2, Val: 0, Size: (size_t)this);
}

//------------------------------------------------------------------------------
// Address: 0x3F602830
// Name: public: void CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::RemoveAll(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<ecx>,
        int a2@<eax>,
        __int16 _DX@<dx>)
{
  _DWORD *v3; // eax

  v3 = (_DWORD *)(a2 - 1);
  __asm { insb }
  v3[28] = this;
  v3[18] = this;
  v3[17] = this;
  v3[16] = this;
  v3[19] = this;
  v3[22] = this;
  v3[20] = "(none)";
  v3[21] = this;
}

//------------------------------------------------------------------------------
// Address: 0x3F6029F0
// Name: public: void CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::Free(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this)
{
  JUMPOUT(0x3F6029F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F602AC0
// Name: public: struct CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::ListElem_t __near & CUtlMemory<struct CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::ListElem_t>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F602B20
// Name: public: struct CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::ListElem_t __near * CUtlMemory<struct CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::ListElem_t>::Base(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F602B80
// Name: public: struct CCommandLine::CommandLineParam_t __near & CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F602B90
// Name: public: void CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::LinkBefore(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this,
        int before,
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::ListElem_t *elem)
{
  *((_BYTE *)this - 2147464067) = __ROL1__(*((_BYTE *)this - 2147464067), 1);
  JUMPOUT(0x3F602B99);
}

//------------------------------------------------------------------------------
// Address: 0x3F602CD0
// Name: public: void CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::Unlink(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<edi>,
        CValidator *elem@<esi>,
        int _EAX@<eax>)
{
  __asm { aas }
  CValidator::ClaimMemory(this: elem, a2: *((void **)this + 18));
  CValidator::Pop(this: elem);
}

//------------------------------------------------------------------------------
// Address: 0x3F602ED0
// Name: public: bool CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::IsInList(int)const
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::IsInList(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<eax>)
{
  JUMPOUT(0x3F602ED2);
}

//------------------------------------------------------------------------------
// Address: 0x3F602F90
// Name: public: int CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::Previous(int)const
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::Previous@<eax>(
        int i@<eax>,
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this)
{
  int v3; // edi
  int v4; // esi
  int result; // eax

  if ( *(int *)(i + 60) <= 1 )
    AssertMsgImplementation(
      a1: "Assertion Failed: m_VecCoroutineStack.Count() > 1",
      a2: 0,
      a3: ".\\coroutine.cpp",
      a4: 410,
      a5: &unk_3F665728,
      a6: 0);
  v3 = *(_DWORD *)(i + 60) - 1;
  v4 = i + 44;
  if ( (unsigned __int8)sub_3F614FF0(a1: v4) == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(i)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 306,
      a5: &unk_3F665743,
      a6: 0);
  result = ((int (__stdcall *)(int))loc_3F6058E0)(a1: v3);
  --*(_DWORD *)(v4 + 16);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F603070
// Name: int UtlMemory_CalcNewAllocationCount(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall UtlMemory_CalcNewAllocationCount(
        int nAllocationCount@<eax>,
        int nNewSize@<ecx>,
        int nBytesItem@<esi>,
        int a4@<ebx>,
        int a5@<edi>)
{
  CValidator *v5; // ebx

  v5 = (CValidator *)(a4 + 1);
  __asm { aas }
  CValidator::ClaimMemory(this: v5, a2: *(void **)(a5 + 72));
  CValidator::Pop(this: v5);
  JUMPOUT(0x3F603087);
}

//------------------------------------------------------------------------------
// Address: 0x3F603090
// Name: public: CDbgFmtMsg::CDbgFmtMsg(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void CDbgFmtMsg::CDbgFmtMsg(CDbgFmtMsg *this, const char *pszFormat, ...)
{
  int v2; // [esp-4h] [ebp-4h]

  if ( Coroutine_ReleaseThreadMemory(a1: v2) == -1 )
  {
    sub_3F62928F(a1: &output[920]);
    JUMPOUT(0x3F6030B2);
  }
  JUMPOUT(0x3F60306D);
}

//------------------------------------------------------------------------------
// Address: 0x3F6030C0
// Name: int Q_stricmp(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void Q_stricmp()
{
  __asm { aas }
  sub_3F62928F(a1: &CUtlMemoryBase `RTTI Type Descriptor');
  JUMPOUT(0x3F6030CD);
}

//------------------------------------------------------------------------------
// Address: 0x3F6158A0
// Name: __Q_stricmp
// Source: json
//------------------------------------------------------------------------------
void __usercall _Q_stricmp(_DWORD *_EAX@<eax>, int a2@<edx>, char a3@<cl>, int a4@<ebx>)
{
  unsigned __int8 v5; // cl

  *_EAX += _EAX;
  *(_BYTE *)(a4 + 1715637269) += a3;
  __asm { aas }
  v5 = *(_BYTE *)(a2 + dword_3F664280);
  dword_3F66428C = a2 + 1;
  if ( (v5 & (unsigned __int8)_EAX) == (_BYTE)_EAX )
    JUMPOUT(0x3F6158CE);
  JUMPOUT(0x3F6159BC);
}

//------------------------------------------------------------------------------
// Address: 0x3F601220
// Name: ??0CCommandLineParam@@QAE@PBD0@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CCommandLineParam *__userpurge CCommandLineParam::CCommandLineParam@<eax>(
        CCommandLineParam *this@<ecx>,
        CCommandLineParam *a2@<esi>,
        const char *pchName,
        const char *pchHelpText)
{
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F601230
// Name: sub_3F601230
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *sub_3F601230()
{
  dword_3F665888 = (int)&ICommandLine::`vftable';
  return &dword_3F665888;
}

//------------------------------------------------------------------------------
// Address: 0x3F601270
// Name: ??1CCommandLineParam@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CCommandLineParam::~CCommandLineParam(CCommandLineParam *this@<ecx>, __int16 _AX@<ax>)
{
  __asm { aas }
  JUMPOUT(0x3F601272);
}

//------------------------------------------------------------------------------
// Address: 0x3F601A90
// Name: sub_3F601A90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F601A90(_DWORD *this)
{
  return *(this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F601B80
// Name: sub_3F601B80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __userpurge sub_3F601B80@<eax>(unsigned int result@<eax>, int a2@<edi>, void *Src)
{
  unsigned int v3; // esi
  int v4; // esi

  v3 = result;
  if ( result > (unsigned int)Src )
  {
    if ( *(int *)(a2 + 8) >= 256 )
      AssertMsgImplementation(
        a1: "Assertion Failed: m_nParmCount < MAX_PARAMETERS",
        a2: 0,
        a3: ".\\commandline.cpp",
        a4: 524,
        a5: &unk_3F66571A,
        a6: 0);
    v4 = v3 - (_DWORD)Src + 1;
    *(_DWORD *)(a2 + 4 * *(_DWORD *)(a2 + 8) + 12) = sub_3F609C70();
    memcpy_1(a1: *(void **)(a2 + 4 * *(_DWORD *)(a2 + 8) + 12), Src, Size: v4 - 1);
    result = *(_DWORD *)(a2 + 4 * *(_DWORD *)(a2 + 8) + 12);
    *(_BYTE *)(result + v4 - 1) = 0;
    ++*(_DWORD *)(a2 + 8);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F601C00
// Name: sub_3F601C00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F601C00(int a1@<eax>)
{
  char *v2; // esi
  char i; // al
  char v4; // al

  ((void (*)(void))loc_3F601CC0)();
  v2 = *(char **)(a1 + 4);
  if ( v2 != nullptr )
  {
    for ( i = *v2; i != 0; i = *++v2 )
    {
      if ( isspace_0(C: i) == 0 )
        break;
    }
    v4 = *v2;
    if ( *v2 != 0 )
    {
      if ( v4 != 34 )
        isspace_0(C: v4);
      JUMPOUT(0x3F601C9F);
    }
    JUMPOUT(0x3F601CAF);
  }
  JUMPOUT(0x3F601CB1);
}

//------------------------------------------------------------------------------
// Address: 0x3F602214
// Name: nullsub_33
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_33()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F6022B0
// Name: sub_3F6022B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_3F6022B0@<eax>(int a1@<eax>, int a2)
{
  const char *v3; // eax
  int v4; // eax

  if ( (unsigned __int8)sub_3F602320(a1: a2) == 0 )
  {
    v3 = (const char *)((int (*)(const char *, ...))loc_3F6027D0)(a1: "CUtlLinkedList::Next: invalid index %d\n", a1);
    v4 = ((int (*)(const char *, ...))loc_3F6027D0)(a1: "Assertion Failed: %s", v3);
    AssertMsgImplementation(
      a1: v4,
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
      a4: 284,
      a5: &unk_3F66571D,
      a6: 0);
  }
  return *(_DWORD *)(16 * a1 + *(_DWORD *)(a2 + 4) + 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F602320
// Name: sub_3F602320
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall sub_3F602320@<eax>(int a1@<eax>, int a2@<ecx>)
{
  int v2; // ecx
  BOOL result; // eax

  result = false;
  if ( a1 < *(_DWORD *)(a2 + 32) && a1 >= 0 )
  {
    v2 = 16 * a1 + *(_DWORD *)(a2 + 4);
    if ( *(_DWORD *)(v2 + 8) != a1 || *(_DWORD *)(v2 + 12) == a1 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F602350
// Name: sub_3F602350
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F602350(_DWORD *a1@<eax>, CValidator *a2@<esi>)
{
  const char *v3; // eax
  const char *v4; // eax
  void *v5; // edi

  v3 = (const char *)sub_3F62928F(a1: &output[800]);
  CValidator::Push(this: a2, a2: v3, a3: a1, a4: "m_listCommandLineOption");
  v4 = (const char *)sub_3F62928F(a1: &CUtlMemoryBase `RTTI Type Descriptor');
  CValidator::Push(this: a2, a2: v4, a3: a1, a4: "m_Memory");
  v5 = (void *)a1[1];
  if ( v5 != nullptr )
    CValidator::ClaimMemory(this: a2, a2: v5);
  CValidator::Pop(this: a2);
  CValidator::Pop(this: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F6023B0
// Name: sub_3F6023B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F6023B0@<eax>(int result@<eax>)
{
  *(_DWORD *)(result + 36) = *(_DWORD *)(result + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F602CF0
// Name: sub_3F602CF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__stdcall sub_3F602CF0(_DWORD *a1)
{
  _DWORD *v1; // ebp
  int v2; // ecx
  _DWORD *v3; // eax
  unsigned int v4; // eax

  v1 = a1;
  a1[1] = 124;
  v1[2] = 0;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = -1;
  v1[6] = -1;
  v1[7] = -1;
  v1[9] = 0;
  v1[8] = 0;
  v1[10] = 0;
  v1[11] = 4;
  v1[12] = 0;
  v1[13] = 0;
  v1[14] = 0;
  v1[15] = 0;
  *v1 = 0;
  CoroutineTestFunc(pvRelaunch: (void *)0xFFFFFFFF);
  v2 = v1[2];
  a1 = v3;
  *(_DWORD *)(124 * (_DWORD)v3 + v2 + 80) = "(main)";
  v4 = v1[12];
  if ( (unsigned int)&a1 >= v4 && (unsigned int)&a1 < v4 + 4 * v1[15] )
    AssertMsgImplementation(
      a1: "Assertion Failed: (&src < Base()) || (&src >= (Base() + Count()) )",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 623,
      a5: &unk_3F66573D,
      a6: 0);
  sub_3F605810(&a1);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x3F602E60
// Name: sub_3F602E60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F602E60@<eax>(_DWORD *a1@<edi>)
{
  int v1; // esi

  v1 = a1[15] - 1;
  if ( (unsigned __int8)sub_3F614FF0(a1: a1 + 11) == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(i)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 292,
      a5: &unk_3F66573C,
      a6: 0);
  return a1[2] + 124 * *(_DWORD *)(a1[12] + 4 * v1);
}

//------------------------------------------------------------------------------
// Address: 0x3F603020
// Name: sub_3F603020
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F603020(_DWORD *a1, CValidator *a2)
{
  CCoroutineMgr *v2; // ecx

  CValidator::Push(this: a2, a2: "CCoroutineMgr", a3: a1, a4: "g_VecPCoroutineMgr[i]");
  CCoroutineMgr::~CCoroutineMgr(this: v2);
  if ( a1[5] != -1 )
    JUMPOUT(0x3F603055);
  JUMPOUT(0x3F60309F);
}

//------------------------------------------------------------------------------
// Address: 0x3F6158D0
// Name: __Q_strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F615900
// Name: __Q_strupr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Q_strupr(const char *file, int line, char *start, _MEMORY_BASIC_INFORMATION Buffer)
{
  __asm { aas }
  VirtualQuery(lpAddress: &unk_3F665878, lpBuffer: &Buffer, dwLength: 0x1Cu);
  JUMPOUT(0x3F61591F);
}

//------------------------------------------------------------------------------
// Address: 0x3F615920
// Name: __Q_strlower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _Q_strlower(HMODULE a1@<edx>, int a2@<esi>)
{
  char *v2; // [esp-8h] [ebp-8h]
  DWORD v3; // [esp-4h] [ebp-4h]

  GetModuleFileNameA(hModule: a1, lpFilename: v2, nSize: v3);
  dword_3F665D08 = a2;
  JUMPOUT(0x3F61593F);
}
