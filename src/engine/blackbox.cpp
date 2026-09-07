// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/blackbox.cpp
// Functions: 23
// ============================================================

#include "engine\blackbox.h"

//------------------------------------------------------------------------------
// Address: 0x1013BBE0
// Name: public: CBlackBoxRecord::CBlackBoxRecord(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBlackBoxRecord *__thiscall CBlackBoxRecord::CBlackBoxRecord(CBlackBoxRecord *this, const char *new_message)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al

  this->m_time = _Plat_FloatTime();
  v3 = (char *)MemAlloc_Alloc(nSize: strlen(new_message) + 1);
  this->m_message = v3;
  v4 = new_message;
  v5 = v3;
  do
  {
    v6 = *v4;
    *v5++ = *v4++;
  }
  while ( v6 != 0 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013BC40
// Name: public: virtual void CBlackBox::SetLimit(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlackBox::SetLimit(CBlackBox *this, unsigned int type, unsigned int count)
{
  if ( type <= 2 )
    this->m_record_limits[type] = count;
}

//------------------------------------------------------------------------------
// Address: 0x1013BC60
// Name: public: virtual char const __near * CBlackBox::GetTypeName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBlackBox::GetTypeName(CBlackBox *this, unsigned int type)
{
  if ( type <= 2 )
    return gTypeMap[type];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013BC80
// Name: blackbox_dump
// Source: json
//------------------------------------------------------------------------------
void __cdecl blackbox_dump()
{
  int i; // edi
  signed int v1; // esi
  const char *v2; // eax
  const char *v3; // eax
  int v4; // [esp-14h] [ebp-18h]
  const char *v5; // [esp-10h] [ebp-14h]
  int v6; // [esp-Ch] [ebp-10h]

  for ( i = 0; i < gBlackBox->GetTypeCount(this: gBlackBox); ++i )
  {
    v1 = 0;
    if ( gBlackBox->Count(this: gBlackBox, a2: i) > 0 )
    {
      do
      {
        v2 = gBlackBox->Get(this: gBlackBox, a2: i, a3: v1);
        v3 = (const char *)((int (__thiscall *)(IBlackBox *, int, int, const char *))gBlackBox->GetTypeName)(
                             a1: gBlackBox,
                             a2: i,
                             a3: v1 + 1,
                             a4: v2);
        _Msg(a1: "%s[%d]: %s\n", v3, v4, v5);
        ++v1;
      }
      while ( v1 < ((int (__thiscall *)(IBlackBox *, int, int))gBlackBox->Count)(a1: gBlackBox, a2: i, a3: v6) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BD10
// Name: public: virtual int CBlackBox::Count(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBlackBox::Count(CBlackBox *this, unsigned int type)
{
  if ( type <= 2 )
    return this->m_records[type].m_Size;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1013BD30
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
  if ( blackbox.m_pParent != nullptr && blackbox.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = 0;
    if ( ((int (__thiscall *)(IBlackBox *, int, int))gBlackBox->GetTypeCount)(a1: gBlackBox, a2: a1, a3: a2) > 0 )
    {
      do
      {
        v5 = gBlackBox->GetTypeName(this: gBlackBox, a2: v4);
        if ( V_strcasecmp(s1: v5, s2: type) == 0 )
          break;
        ++v4;
      }
      while ( v4 < gBlackBox->GetTypeCount(this: gBlackBox) );
    }
    if ( v4 < gBlackBox->GetTypeCount(this: gBlackBox) )
    {
      V_vsnprintf(pDest: szMessage, maxLen: 1024, pFormat, params);
      gBlackBox->Record(this: gBlackBox, a2: v4, a3: szMessage);
    }
    else
    {
      _Msg(a1: "Invalid blackbox type: %s\n", type);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BE00
// Name: public: char const __near * CFmtStrN<1040>::sprintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *CFmtStrN<1040>::sprintf(CFmtStrN<1040> *this, const char *pszFormat, ...)
{
  CFmtStrN<1040> *v2; // esi
  bool v3; // zf
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  this->InitQuietTruncation(this);
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v2->m_szBuf, maxLen: 1039, pFormat: pszFormat, params, pbTruncated: (bool *)&this + 3);
  v3 = HIBYTE(this) == 0;
  v2->m_szBuf[1039] = 0;
  if ( !v3 && !v2->m_bQuietTruncation && `CFmtStrN<1040>::sprintf'::`4'::scAsserted < 5 )
    ++`CFmtStrN<1040>::sprintf'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2->m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x1013BE70
// Name: public: CBlackBoxRecord::operator char const __near *(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBlackBoxRecord::operator char const *(CBlackBoxRecord *this)
{
  if ( (___B_1___BCBlackBoxRecord__QBEPBDXZ_51 & 1) == 0 )
  {
    ___B_1___BCBlackBoxRecord__QBEPBDXZ_51 |= 1u;
    _buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A.m_bQuietTruncation = true;
    _buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A.__vftable = (CFmtStrN<1040>_vtbl *)&CFmtStrN<1040>::`vftable';
    _buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A.m_szBuf[0] = 0;
    _buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A.m_nLength = 0;
  }
  CFmtStrN<1040>::sprintf(
    this: &_buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A,
    pszFormat: "[%02d:%02d:%02.3f]: %s",
    (int)(0.0002777777777777778 * this->m_time),
    (int)(0.01666666666666667 * this->m_time) % 60,
    (double)(this->m_time
           - (double)(60
                    * ((int)(0.01666666666666667 * this->m_time) % 60 + 60 * (int)(0.0002777777777777778 * this->m_time)))),
    this->m_message);
  return _buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A.m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x1013BF20
// Name: public: virtual char const __near * CBlackBox::Get(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBlackBox::Get(CBlackBox *this, unsigned int type, unsigned int index)
{
  if ( type <= 2 )
    return CBlackBoxRecord::operator char const *(this: this->m_records[type].m_Memory.m_pMemory[index]);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013BF50
// Name: blackbox_record
// Source: json
//------------------------------------------------------------------------------
void __usercall blackbox_record(int a1@<edi>, int a2@<esi>, const CCommand *args)
{
  const char *v3; // edx
  const char *v4; // eax

  if ( blackbox.m_pParent != nullptr && blackbox.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( args->m_nArgc >= 2 )
    {
      v3 = defaultValue;
      if ( args->m_nArgc > 2 )
        v3 = args->m_ppArgv[2];
      v4 = defaultValue;
      if ( args->m_nArgc > 1 )
        v4 = args->m_ppArgv[1];
      BlackBox_Record(a1, a2, type: v4, pFormat: v3);
    }
    else
    {
      _Msg(a1: "Insufficient arguments to blackbox_record. Usage: blackbox_record <type> <message>\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C040
// Name: public: virtual void CBlackBox::Flush(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlackBox::Flush(CBlackBox *this, unsigned int type)
{
  if ( type <= 2 )
    CUtlVector<CBlackBoxRecord *,CUtlMemory<CBlackBoxRecord *,int>>::PurgeAndDeleteElements(this: &this->m_records[type]);
}

//------------------------------------------------------------------------------
// Address: 0x1013C060
// Name: public: CBlackBox::~CBlackBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlackBox::~CBlackBox(CBlackBox *this)
{
  int v2; // esi
  CUtlVector<CBlackBoxRecord *,CUtlMemory<CBlackBoxRecord *,int> > *m_records; // edi
  unsigned int *m_record_limits; // esi
  int i; // edi
  void *v6; // eax

  this->__vftable = (CBlackBox_vtbl *)&CBlackBox::`vftable';
  v2 = 0;
  m_records = this->m_records;
  do
  {
    if ( (unsigned int)v2 <= 2 )
      CUtlVector<CBlackBoxRecord *,CUtlMemory<CBlackBoxRecord *,int>>::PurgeAndDeleteElements(this: m_records);
    ++v2;
    ++m_records;
  }
  while ( v2 < 3 );
  m_record_limits = this->m_record_limits;
  for ( i = 2; i >= 0; --i )
  {
    m_record_limits -= 5;
    m_record_limits[3] = 0;
    if ( (m_record_limits[2] & 0x80000000) == 0 )
    {
      if ( *m_record_limits != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_record_limits);
        *m_record_limits = 0;
      }
      m_record_limits[1] = 0;
    }
    v6 = (void *)*m_record_limits;
    m_record_limits[4] = *m_record_limits;
    if ( (m_record_limits[2] & 0x80000000) == 0 )
    {
      if ( v6 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
        *m_record_limits = 0;
      }
      m_record_limits[1] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C0F0
// Name: public: virtual void CBlackBox::Record(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlackBox::Record(CBlackBox *this, unsigned int type, CBlackBoxRecord *msg)
{
  CBlackBoxRecord *v4; // eax
  int m_nAllocationCount; // eax
  char *v6; // ebx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  CBlackBoxRecord **v10; // eax
  void **v11; // edi
  CBlackBoxRecord *new_record; // [esp+14h] [ebp+Ch]

  if ( blackbox.m_pParent != nullptr && blackbox.m_pParent->m_Value.m_nValue != 0 && type <= 2 )
  {
    v4 = (CBlackBoxRecord *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v4 != nullptr )
      new_record = CBlackBoxRecord::CBlackBoxRecord(this: v4, new_message: (const char *)msg);
    else
      new_record = nullptr;
    m_nAllocationCount = this->m_records[type].m_Memory.m_nAllocationCount;
    v6 = (char *)this + 20 * type;
    v7 = *((_DWORD *)v6 + 4);
    if ( v7 + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(v6 + 4), num: v7 - m_nAllocationCount + 1);
    ++*((_DWORD *)v6 + 4);
    v8 = *((_DWORD *)v6 + 1);
    v9 = *((_DWORD *)v6 + 4) - v7 - 1;
    *((_DWORD *)v6 + 5) = v8;
    if ( v9 > 0 )
      _V_memmove(dest: (void *)(v8 + 4 * v7 + 4), src: (const void *)(v8 + 4 * v7), count: 4 * v9);
    v10 = (CBlackBoxRecord **)(*((_DWORD *)v6 + 1) + 4 * v7);
    if ( v10 != nullptr )
      *v10 = new_record;
    if ( *((_DWORD *)v6 + 4) > this->m_record_limits[type] )
    {
      v11 = **((void ****)v6 + 1);
      CUtlVector<CBlackBoxRecord *,CUtlMemory<CBlackBoxRecord *,int>>::Remove(
        this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)(v6 + 4),
        elem: 0);
      if ( v11 != nullptr )
      {
        if ( v11[2] != nullptr )
          free(pMem: v11[2]);
        free(pMem: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10318C60
// Name: _dynamic_initializer_for__blackbox__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__blackbox__()
{
  ConVar::ConVar(this: &blackbox, pName: "blackbox", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__blackbox__);
}

//------------------------------------------------------------------------------
// Address: 0x10318D00
// Name: _dynamic_initializer_for__blackbox_record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__blackbox_record_command__()
{
  ConCommand::ConCommand(
    this: &blackbox_record_command,
    pName: "blackbox_record",
    callback: (void (__cdecl *)())blackbox_record,
    pHelpString: "Record an entry into the blackbox",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__blackbox_record_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318D30
// Name: _dynamic_initializer_for__blackbox_dump_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__blackbox_dump_command__()
{
  ConCommand::ConCommand(
    this: &blackbox_dump_command,
    pName: "blackbox_dump",
    callback: blackbox_dump,
    pHelpString: "Dump the contents of the blackbox",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__blackbox_dump_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324A40
// Name: _dynamic_atexit_destructor_for__blackbox__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__blackbox__()
{
  ConVar::~ConVar(this: &blackbox);
}

//------------------------------------------------------------------------------
// Address: 0x10324A50
// Name: _dynamic_atexit_destructor_for__blackbox_record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__blackbox_record_command__()
{
  ConCommand::~ConCommand(this: &blackbox_record_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324A60
// Name: _dynamic_atexit_destructor_for__blackbox_dump_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__blackbox_dump_command__()
{
  ConCommand::~ConCommand(this: &blackbox_dump_command);
}

//------------------------------------------------------------------------------
// Address: 0x1013BC30
// Name: __CreateCBlackBoxIBlackBox_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBlackBox *__cdecl _CreateCBlackBoxIBlackBox_interface()
{
  return &gCBlackBox;
}

//------------------------------------------------------------------------------
// Address: 0x10318C90
// Name: _dynamic_initializer_for__gCBlackBox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gCBlackBox__()
{
  int v0; // edx
  int *p_m_nGrowSize; // eax

  v0 = 2;
  p_m_nGrowSize = &gCBlackBox.m_records[0].m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v0;
  }
  while ( v0 >= 0 );
  gCBlackBox.m_record_limits[0] = 16;
  gCBlackBox.m_record_limits[1] = 16;
  gCBlackBox.m_record_limits[2] = 16;
  return atexit(func: dynamic_atexit_destructor_for__gCBlackBox__);
}

//------------------------------------------------------------------------------
// Address: 0x10318CE0
// Name: _dynamic_initializer_for____g_CreateCBlackBoxIBlackBox_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCBlackBoxIBlackBox_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCBlackBoxIBlackBox_reg,
           fn: (void *(__cdecl *)())_CreateCBlackBoxIBlackBox_interface,
           pName: "BlackBoxVersion001");
}

//------------------------------------------------------------------------------
// Address: 0x10324A70
// Name: _dynamic_atexit_destructor_for__gCBlackBox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gCBlackBox__()
{
  CBlackBox::~CBlackBox(this: &gCBlackBox);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1013BD00
// Name: public: CBlackBoxRecord::CBlackBoxRecord(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBlackBoxRecord *__thiscall CBlackBoxRecord::CBlackBoxRecord(CBlackBoxRecord *this, const char *new_message)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al

  this->m_time = _Plat_FloatTime(a1: this);
  v3 = (char *)MemAlloc_Alloc(nSize: strlen(new_message) + 1);
  this->m_message = v3;
  v4 = new_message;
  v5 = v3;
  do
  {
    v6 = *v4;
    *v5++ = *v4++;
  }
  while ( v6 != 0 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013BD60
// Name: public: virtual void CBlackBox::SetLimit(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlackBox::SetLimit(CBlackBox *this, unsigned int type, unsigned int count)
{
  if ( type <= 2 )
    this->m_record_limits[type] = count;
}

//------------------------------------------------------------------------------
// Address: 0x1013BD80
// Name: public: virtual char const __near * CBlackBox::GetTypeName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBlackBox::GetTypeName(CBlackBox *this, unsigned int type)
{
  if ( type <= 2 )
    return gTypeMap[type];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013BDA0
// Name: blackbox_dump
// Source: json
//------------------------------------------------------------------------------
void __cdecl blackbox_dump()
{
  int i; // edi
  signed int v1; // esi
  const char *v2; // eax
  const char *v3; // eax
  int v4; // [esp-14h] [ebp-18h]
  const char *v5; // [esp-10h] [ebp-14h]
  int v6; // [esp-Ch] [ebp-10h]

  for ( i = 0; i < gBlackBox->GetTypeCount(this: gBlackBox); ++i )
  {
    v1 = 0;
    if ( gBlackBox->Count(this: gBlackBox, a2: i) > 0 )
    {
      do
      {
        v2 = gBlackBox->Get(this: gBlackBox, a2: i, a3: v1);
        v3 = (const char *)((int (__thiscall *)(IBlackBox *, int, int, const char *))gBlackBox->GetTypeName)(
                             a1: gBlackBox,
                             a2: i,
                             a3: v1 + 1,
                             a4: v2);
        _Msg(a1: "%s[%d]: %s\n", v3, v4, v5);
        ++v1;
      }
      while ( v1 < ((int (__thiscall *)(IBlackBox *, int, int))gBlackBox->Count)(a1: gBlackBox, a2: i, a3: v6) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BE30
// Name: public: virtual int CBlackBox::Count(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBlackBox::Count(CBlackBox *this, unsigned int type)
{
  if ( type <= 2 )
    return this->m_records[type].m_Size;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1013BE50
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
  if ( blackbox.m_pParent != nullptr && blackbox.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = 0;
    if ( ((int (__thiscall *)(IBlackBox *, int, int))gBlackBox->GetTypeCount)(a1: gBlackBox, a2: a1, a3: a2) > 0 )
    {
      do
      {
        v5 = gBlackBox->GetTypeName(this: gBlackBox, a2: v4);
        if ( V_strcasecmp(s1: v5, s2: type) == 0 )
          break;
        ++v4;
      }
      while ( v4 < gBlackBox->GetTypeCount(this: gBlackBox) );
    }
    if ( v4 < gBlackBox->GetTypeCount(this: gBlackBox) )
    {
      V_vsnprintf(pDest: szMessage, maxLen: 1024, pFormat, params);
      gBlackBox->Record(this: gBlackBox, a2: v4, a3: szMessage);
    }
    else
    {
      _Msg(a1: "Invalid blackbox type: %s\n", type);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BF90
// Name: public: CBlackBoxRecord::operator char const __near *(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBlackBoxRecord::operator char const *(CBlackBoxRecord *this)
{
  if ( (___B_1___BCBlackBoxRecord__QBEPBDXZ_51 & 1) == 0 )
  {
    ___B_1___BCBlackBoxRecord__QBEPBDXZ_51 |= 1u;
    _buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A.m_bQuietTruncation = true;
    _buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A.__vftable = (CFmtStrN<1040>_vtbl *)&CFmtStrN<1040>::`vftable';
    _buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A.m_szBuf[0] = 0;
    _buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A.m_nLength = 0;
  }
  CFmtStrN<1040>::sprintf(
    this: &_buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A,
    pszFormat: "[%02d:%02d:%02.3f]: %s",
    (int)(0.0002777777777777778 * this->m_time),
    (int)(0.01666666666666667 * this->m_time) % 60,
    (double)(this->m_time
           - (double)(60
                    * ((int)(0.01666666666666667 * this->m_time) % 60 + 60 * (int)(0.0002777777777777778 * this->m_time)))),
    this->m_message);
  return _buf__1___BCBlackBoxRecord__QBEPBDXZ_4V__CFmtStrN__0EBA___A.m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x1013C070
// Name: blackbox_record
// Source: json
//------------------------------------------------------------------------------
void __usercall blackbox_record(int a1@<edi>, int a2@<esi>, const CCommand *args)
{
  const char *v3; // edx
  const char *v4; // eax

  if ( blackbox.m_pParent != nullptr && blackbox.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( args->m_nArgc >= 2 )
    {
      v3 = defaultValue;
      if ( args->m_nArgc > 2 )
        v3 = args->m_ppArgv[2];
      v4 = defaultValue;
      if ( args->m_nArgc > 1 )
        v4 = args->m_ppArgv[1];
      BlackBox_Record(a1, a2, type: v4, pFormat: v3);
    }
    else
    {
      _Msg(a1: "Insufficient arguments to blackbox_record. Usage: blackbox_record <type> <message>\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C150
// Name: public: virtual void CBlackBox::Flush(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlackBox::Flush(CBlackBox *this, unsigned int type)
{
  if ( type <= 2 )
    CUtlVector<CBlackBoxRecord *,CUtlMemory<CBlackBoxRecord *,int>>::PurgeAndDeleteElements(this: &this->m_records[type]);
}

//------------------------------------------------------------------------------
// Address: 0x1013C170
// Name: public: CBlackBox::~CBlackBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlackBox::~CBlackBox(CBlackBox *this)
{
  int v2; // esi
  CUtlVector<CBlackBoxRecord *,CUtlMemory<CBlackBoxRecord *,int> > *m_records; // edi
  unsigned int *m_record_limits; // esi
  int i; // edi
  void *v6; // eax

  this->__vftable = (CBlackBox_vtbl *)&CBlackBox::`vftable';
  v2 = 0;
  m_records = this->m_records;
  do
  {
    if ( (unsigned int)v2 <= 2 )
      CUtlVector<CBlackBoxRecord *,CUtlMemory<CBlackBoxRecord *,int>>::PurgeAndDeleteElements(this: m_records);
    ++v2;
    ++m_records;
  }
  while ( v2 < 3 );
  m_record_limits = this->m_record_limits;
  for ( i = 2; i >= 0; --i )
  {
    m_record_limits -= 5;
    m_record_limits[3] = 0;
    if ( (m_record_limits[2] & 0x80000000) == 0 )
    {
      if ( *m_record_limits != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_record_limits);
        *m_record_limits = 0;
      }
      m_record_limits[1] = 0;
    }
    v6 = (void *)*m_record_limits;
    m_record_limits[4] = *m_record_limits;
    if ( (m_record_limits[2] & 0x80000000) == 0 )
    {
      if ( v6 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
        *m_record_limits = 0;
      }
      m_record_limits[1] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C200
// Name: public: virtual void CBlackBox::Record(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlackBox::Record(CBlackBox *this, unsigned int type, CBlackBoxRecord *msg)
{
  CBlackBoxRecord *v4; // eax
  int m_nAllocationCount; // eax
  char *v6; // ebx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  CBlackBoxRecord **v10; // eax
  void **v11; // edi
  CBlackBoxRecord *new_record; // [esp+14h] [ebp+Ch]

  if ( blackbox.m_pParent != nullptr && blackbox.m_pParent->m_Value.m_nValue != 0 && type <= 2 )
  {
    v4 = (CBlackBoxRecord *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v4 != nullptr )
      new_record = CBlackBoxRecord::CBlackBoxRecord(this: v4, new_message: (const char *)msg);
    else
      new_record = nullptr;
    m_nAllocationCount = this->m_records[type].m_Memory.m_nAllocationCount;
    v6 = (char *)this + 20 * type;
    v7 = *((_DWORD *)v6 + 4);
    if ( v7 + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(v6 + 4), num: v7 - m_nAllocationCount + 1);
    ++*((_DWORD *)v6 + 4);
    v8 = *((_DWORD *)v6 + 1);
    v9 = *((_DWORD *)v6 + 4) - v7 - 1;
    *((_DWORD *)v6 + 5) = v8;
    if ( v9 > 0 )
      _V_memmove(dest: (void *)(v8 + 4 * v7 + 4), src: (const void *)(v8 + 4 * v7), count: 4 * v9);
    v10 = (CBlackBoxRecord **)(*((_DWORD *)v6 + 1) + 4 * v7);
    if ( v10 != nullptr )
      *v10 = new_record;
    if ( *((_DWORD *)v6 + 4) > this->m_record_limits[type] )
    {
      v11 = **((void ****)v6 + 1);
      CUtlVector<CBlackBoxRecord *,CUtlMemory<CBlackBoxRecord *,int>>::Remove(
        this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)(v6 + 4),
        elem: 0);
      if ( v11 != nullptr )
      {
        if ( v11[2] != nullptr )
          free(pMem: v11[2]);
        free(pMem: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10318E30
// Name: _dynamic_initializer_for__blackbox__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__blackbox__()
{
  ConVar::ConVar(this: &blackbox, pName: "blackbox", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__blackbox__);
}

//------------------------------------------------------------------------------
// Address: 0x10318ED0
// Name: _dynamic_initializer_for__blackbox_record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__blackbox_record_command__()
{
  ConCommand::ConCommand(
    this: &blackbox_record_command,
    pName: "blackbox_record",
    callback: (void (__cdecl *)())blackbox_record,
    pHelpString: "Record an entry into the blackbox",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__blackbox_record_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318F00
// Name: _dynamic_initializer_for__blackbox_dump_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__blackbox_dump_command__()
{
  ConCommand::ConCommand(
    this: &blackbox_dump_command,
    pName: "blackbox_dump",
    callback: blackbox_dump,
    pHelpString: "Dump the contents of the blackbox",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__blackbox_dump_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324C20
// Name: _dynamic_atexit_destructor_for__blackbox__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__blackbox__()
{
  ConVar::~ConVar(this: &blackbox);
}

//------------------------------------------------------------------------------
// Address: 0x10324C30
// Name: _dynamic_atexit_destructor_for__blackbox_record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__blackbox_record_command__()
{
  ConCommand::~ConCommand(this: &blackbox_record_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324C40
// Name: _dynamic_atexit_destructor_for__blackbox_dump_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__blackbox_dump_command__()
{
  ConCommand::~ConCommand(this: &blackbox_dump_command);
}

//------------------------------------------------------------------------------
// Address: 0x1013BD50
// Name: __CreateCBlackBoxIBlackBox_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBlackBox *__cdecl _CreateCBlackBoxIBlackBox_interface()
{
  return &gCBlackBox;
}

//------------------------------------------------------------------------------
// Address: 0x10318E60
// Name: _dynamic_initializer_for__gCBlackBox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gCBlackBox__()
{
  int v0; // edx
  int *p_m_nGrowSize; // eax

  v0 = 2;
  p_m_nGrowSize = &gCBlackBox.m_records[0].m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v0;
  }
  while ( v0 >= 0 );
  gCBlackBox.m_record_limits[0] = 16;
  gCBlackBox.m_record_limits[1] = 16;
  gCBlackBox.m_record_limits[2] = 16;
  return atexit(func: dynamic_atexit_destructor_for__gCBlackBox__);
}

//------------------------------------------------------------------------------
// Address: 0x10318EB0
// Name: _dynamic_initializer_for____g_CreateCBlackBoxIBlackBox_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCBlackBoxIBlackBox_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCBlackBoxIBlackBox_reg,
           fn: (void *(__cdecl *)())_CreateCBlackBoxIBlackBox_interface,
           pName: "BlackBoxVersion001");
}

//------------------------------------------------------------------------------
// Address: 0x10324C50
// Name: _dynamic_atexit_destructor_for__gCBlackBox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gCBlackBox__()
{
  CBlackBox::~CBlackBox(this: &gCBlackBox);
}

} // namespace engine_xlsp
