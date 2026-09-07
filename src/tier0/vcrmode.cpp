// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/vcrmode.cpp
// Functions: 88
// ============================================================

#include "tier0\vcrmode.h"

//------------------------------------------------------------------------------
// Address: 0x3F00A9A0
// Name: unsigned short GetCurrentVCRThreadIndex(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GetCurrentVCRThreadIndex(int _EBX@<ebx>, int a2@<esi>, int a3, int a4, int a5, ...)
{
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, a5);
  __asm { rep mov eax, [ebx+0A34h] }
  *(_DWORD *)(a2 + 2612) = _EAX;
  if ( a2 + 2616 != _EBX + 2616 )
  {
    sub_3F00C800(a1: va, a2: a2 + 2616, a3: **(_DWORD **)(a2 + 2620), a4: a2 + 2616, a5: *(_DWORD *)(a2 + 2620));
    sub_3F00C8D0(a1: _EBX + 2616);
  }
  JUMPOUT(0x3F00A9DE);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A9E0
// Name: public: CVCRThreadSafe::CVCRThreadSafe(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVCRThreadSafe::CVCRThreadSafe(
        CVCRThreadSafe *this@<ecx>,
        _BYTE *a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5,
        int a6,
        int a7,
        char a8)
{
  bool v8; // zf

  *(_BYTE *)(a3 + 672958) += (_BYTE)this;
  v8 = BYTE1(a2) + *a2 == 0;
  *a2 += BYTE1(a2);
  if ( !v8 )
  {
    sub_3F00C9A0(a1: &a8, a2: a4, a3: **(_DWORD **)(a4 + 4), a4, a5: *(_DWORD *)(a4 + 4));
    sub_3F00CA70(a1: a2 + 2628);
  }
  sub_3F00C410(a1: a2 + 2640);
  JUMPOUT(0x3F00AA27);
}

//------------------------------------------------------------------------------
// Address: 0x3F00AA30
// Name: public: CVCRThreadSafe::~CVCRThreadSafe(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F00AA60
// Name: VCR_Error
// Source: json
//------------------------------------------------------------------------------
void VCR_Error()
{
  JUMPOUT(0x3F00AA62);
}

//------------------------------------------------------------------------------
// Address: 0x3F00AAD0
// Name: VCR_Read
// Source: json
//------------------------------------------------------------------------------
void __usercall VCR_Read(void *pDest@<ecx>, _DWORD *a2@<eax>)
{
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  LOBYTE(a2) = BYTE1(pDest) | (unsigned __int8)a2;
  *a2 -= &retaddr;
  JUMPOUT(0x3F00AAD5);
}

//------------------------------------------------------------------------------
// Address: 0x3F00AB30
// Name: VCR_Write
// Source: json
//------------------------------------------------------------------------------
void __usercall VCR_Write(const void *pSrc@<edx>, int size@<ecx>, int a3@<eax>, int _EBX@<ebx>)
{
  __asm { fadd    dword ptr [ebx+760A107Eh] }
  *(_BYTE *)(_EBX + 243991622) &= size;
  Msg(
    a1: (int)"WARNING: Disabling vprof spike dumping and stopping profile for thread %d - %s because of exceeded rate limit, "
         "try a higher threshold.\n",
    size,
    (const char *)(a3 + 2356));
  VCR_SignalNextEvent();
}

//------------------------------------------------------------------------------
// Address: 0x3F00AB50
// Name: VCR_SignalNextEvent
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall VCR_SignalNextEvent(int a1@<edi>, int a2@<esi>)
{
  CVProfile *v2; // ecx
  struct CVProfNode *v3; // edi
  int v4; // eax

  *(_BYTE *)(a2 + 9) = 1;
  *(_DWORD *)(a2 + 12) = a1;
  v2 = *(CVProfile **)(a2 + 4);
  v3 = *(struct CVProfNode **)(v2->m_GroupIDStack[1] + 116);
  v4 = CVProfile::BudgetGroupNameToBudgetGroupID(this: v2, a2: "Sleeping");
  if ( (double)*(int *)(a2 + 12) < CVProfile::GetFrameTimeOutsideBudgetGroup_Recursive(
                                     this: (CVProfile *)*(_DWORD *)(a2 + 4),
                                     a2: v3,
                                     a3: v4) )
  {
    ++*(_DWORD *)(a2 + 16);
    *(_BYTE *)(a2 + 11) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00ABD0
// Name: VCR_WriteEvent
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall VCR_WriteEvent(int a1@<ecx>, int a2@<ebx>)
{
  bool v2; // zf
  int v3; // eax
  int threadID; // [esp+0h] [ebp-8h]

  *(_BYTE *)(a2 - 61) |= a2;
  if ( *(_BYTE *)(threadID + 9) == (_BYTE)a2 )
  {
    if ( *(_BYTE *)(threadID + 10) == (_BYTE)a2 )
    {
      if ( *(_DWORD *)(threadID + 12) > a2 )
      {
        if ( *(_BYTE *)(threadID + 11) != (_BYTE)a2 )
        {
          CVProfile::OutputReport(a1: 17);
          v3 = *(_DWORD *)(threadID + 4);
          if ( *(_DWORD *)v3 != a2 )
          {
            v2 = (*(_DWORD *)v3)-- == 1;
            if ( v2 )
              CVProfNode::ExitScope(this: *(CVProfNode **)(v3 + 12));
          }
          CVProfile::Reset(this: *(CVProfile **)(threadID + 4));
          JUMPOUT(0x3F00AC4A);
        }
        JUMPOUT(0x3F00AC54);
      }
      JUMPOUT(0x3F00ABDA);
    }
    CVProfile::OutputReport(a1: 17);
    *(_BYTE *)(threadID + 10) = a2;
  }
  else
  {
    if ( *(_DWORD *)a1 != a2 )
    {
      v2 = (*(_DWORD *)a1)-- == 1;
      if ( v2 )
        CVProfNode::ExitScope(this: *(CVProfNode **)(a1 + 12));
    }
    *(_BYTE *)(threadID + 9) = a2;
    _InterlockedExchangeAdd(&g_VProfProfilesRunningCount, 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00AC50
// Name: public: virtual enum VCREvent CVCRTrace::ReadEvent(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVCRTrace::ReadEvent(CVCRTrace *this)
{
  JUMPOUT(0x3F00AC56);
}

//------------------------------------------------------------------------------
// Address: 0x3F00AC60
// Name: public: virtual void CVCRTrace::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CVCRTrace::Read(CVCRTrace *this@<ecx>, int a2@<esi>, void *pDest, int size)
{
  CVProfNode::ExitScope((CVProfNode *)this);
  CVProfile::Reset(this: *(CVProfile **)(a2 + 4));
  JUMPOUT(0x3F00B880);
}

//------------------------------------------------------------------------------
// Address: 0x3F00AC80
// Name: VCR_Start
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall VCR_Start(_DWORD *this)
{
  *(this + 1) = 0;
  *this = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00AE00
// Name: VCR_End
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
IVCRTrace *__usercall VCR_End@<eax>(
        int a1@<eax>,
        int a2@<edx>,
        char a3@<ch>,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  char v9; // bl
  HANDLE v10; // esi
  DWORD v12; // [esp-Ch] [ebp-Ch]
  BOOL v13; // [esp-8h] [ebp-8h]
  DWORD v14; // [esp-4h] [ebp-4h]

  *(_BYTE *)(a1 + 106) += a2;
  *(_BYTE *)(a2 + 64) += a3;
  v9 = 1;
  v10 = OpenThread(dwDesiredAccess: v12, bInheritHandle: v13, dwThreadId: v14);
  if ( v10 != nullptr )
  {
    if ( !GetExitCodeThread(hThread: v10, lpExitCode: (LPDWORD)&a9) || a9 != 259 )
      v9 = 0;
    CloseHandle(hObject: v10);
    if ( v9 != 0 )
      JUMPOUT(0x3F00AE6C);
  }
  return VCR_GetVCRTraceInterface();
}

//------------------------------------------------------------------------------
// Address: 0x3F00AE40
// Name: VCR_GetVCRTraceInterface
// Source: json
//------------------------------------------------------------------------------
void __usercall VCR_GetVCRTraceInterface(int a1@<ebx>)
{
  if ( a1 != 0 )
    JUMPOUT(0x3F00AE46);
  JUMPOUT(0x3F00AE54);
}

//------------------------------------------------------------------------------
// Address: 0x3F00AE50
// Name: VCR_GetMode
// Source: json
//------------------------------------------------------------------------------
void __usercall VCR_GetMode(char a1@<al>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 1187448004) += a1;
  JUMPOUT(0x3F00AE56);
}

//------------------------------------------------------------------------------
// Address: 0x3F00AE60
// Name: VCR_SetEnabled
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall VCR_SetEnabled(_DWORD *a1@<edi>, int bEnabled, int a3, int a4, _RTL_CRITICAL_SECTION *a5, int a6)
{
  *a1 = 0;
  while ( 1 )
  {
    ++a1;
    if ( --a6 == 0 )
      break;
    if ( *a1 != 0 )
      JUMPOUT(0x3F00ADFF);
  }
  LeaveCriticalSection(lpCriticalSection: a5);
  JUMPOUT(0x3F00AE8D);
}

//------------------------------------------------------------------------------
// Address: 0x3F00AE90
// Name: VCR_SyncToken
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall VCR_SyncToken(void *this)
{
  MEMORY[0] = this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B140
// Name: VCR_Hook_Sys_FloatTime
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F00B2D0
// Name: VCR_Hook_PeekMessage
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge VCR_Hook_PeekMessage@<eax>(
        int a1@<eax>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        tagMSG *msg,
        void *hWnd,
        unsigned int wMsgFilterMin,
        unsigned int wMsgFilterMax,
        unsigned int wRemoveMsg)
{
  int v9; // ecx
  int v10; // edx
  _RTL_CRITICAL_SECTION *ret; // [esp+2h] [ebp-14h]

  v9 = *(_DWORD *)(a2 + 12);
  v10 = *(_DWORD *)(a2 + 8);
  *(double *)(a1 + 24) = 0.0;
  *(_DWORD *)(a1 + 12) = a3;
  *(_DWORD *)(a1 + 16) = a3;
  *(_DWORD *)a1 = v9;
  *(_DWORD *)(a1 + 4) = v10;
  *(_BYTE *)(a1 + 8) = 0;
  *(_BYTE *)(a1 + 9) = 0;
  *(_BYTE *)(a1 + 10) = 0;
  *(_BYTE *)(a1 + 11) = 0;
  LOBYTE(STACK[0x132]) = 0;
  *(_DWORD *)(a4 + 4 * (_DWORD)msg + 32) = a1;
  STACK[0x132] = -1;
  LeaveCriticalSection(lpCriticalSection: ret);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B530
// Name: void VCR_Hook_RecordGameMsg(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge VCR_Hook_RecordGameMsg(
        int a1@<eax>,
        int a2@<ebx>,
        int a3@<ebp>,
        CVProfNode *a4@<esi>,
        unsigned int uMsg,
        unsigned int wParam,
        int lParam,
        int a8,
        int a9,
        int a10)
{
  size_t v10; // edi
  char *v11; // eax
  CVProfile *v12; // edi
  int BudgetGroupName; // eax
  CVProfNode *m_pParent; // eax
  const void *v15; // [esp-2h] [ebp-14h]

  v10 = a1 + 1;
  v11 = (char *)((int (__cdecl *)(int))byte_3F01A077)(a1: a1 + 1);
  v15 = *(const void **)(a3 + 12);
  a4->m_pszName = v11;
  memcpy_1(a1: v11, Src: v15, Size: v10);
  a4[1].m_pszName = (const char *)CVProfNode::s_iCurrentUniqueNodeID++;
  if ( (int)a4[1].m_pszName <= a2 )
  {
    a4->m_iClientData = a2;
  }
  else
  {
    v12 = *(CVProfile **)(a3 + 8);
    if ( v12->m_GroupIDStack[5] == a2 )
      CVProfile::CreateBudgetGroups(this: *(CVProfile **)(a3 + 8));
    BudgetGroupName = CVProfile::FindBudgetGroupName(this: v12, fh: *(const char **)(a3 + 24));
    if ( BudgetGroupName == -1 )
    {
      a4->m_iClientData = ((int (__thiscall *)(CVProfile *, _DWORD, _DWORD))_LN17_1)(
                            a1: v12,
                            a2: *(_DWORD *)(a3 + 24),
                            a3: *(_DWORD *)(a3 + 28));
    }
    else
    {
      *(_DWORD *)(v12->m_GroupIDStack[5] + 8 * BudgetGroupName + 4) |= *(_DWORD *)(a3 + 28);
      a4->m_iClientData = BudgetGroupName;
    }
  }
  CVProfNode::Reset(this: a4);
  m_pParent = a4->m_pParent;
  if ( m_pParent != (CVProfNode *)a2 && a4->m_iClientData == a2 )
    a4->m_iClientData = m_pParent->m_iClientData;
  *(_DWORD *)(a3 - 4) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B6D0
// Name: void VCR_Hook_RecordEndGameMsg(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl VCR_Hook_RecordEndGameMsg()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B800
// Name: bool VCR_Hook_PlaybackGameMsg(unsigned int __near &,unsigned int __near &,long __near &)
// Source: json
//------------------------------------------------------------------------------
int __usercall VCR_Hook_PlaybackGameMsg@<eax>(char a1@<zf>)
{
  int result; // eax

  result = -599850030;
  if ( !a1 )
  {
    do
    {
      __asm { fild    qword ptr [eax+40h] }
      result = *(_DWORD *)(result + 120);
      __asm
      {
        fmul    st, st(1)
        fsubp   st(2), st
      }
    }
    while ( result != 0 );
  }
  __asm { fstp    st }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B9A0
// Name: VCR_Hook_GetCursorPos
// Source: json
//------------------------------------------------------------------------------
void __thiscall VCR_Hook_GetCursorPos(CVProfile *this, tagPOINT *pt, int a3, char *a4, bool a5, void *a6)
{
  CVProfile::EnterScope(this, a2: (const char *)pt, a3, a4, a5, a6: 4, a7: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F00BCC0
// Name: VCR_Hook_recvfrom
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge VCR_Hook_recvfrom@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        int s,
        char *buf,
        int len,
        int flags,
        sockaddr *from,
        int *fromlen)
{
  return *(_DWORD *)(*(_DWORD *)(a2 + 28) + 8 * a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F00BF80
// Name: VCR_Hook_recv
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
_DWORD *__usercall VCR_Hook_recv@<eax>(int a1@<ebx>, _DWORD *a2@<edi>, int a3@<esi>)
{
  a2[1] = a3;
  a2[6] = a1;
  a2[2] = a1;
  a2[3] = a1;
  a2[4] = a1;
  a2[5] = a1;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F00C5F0
// Name: VCR_Hook_GetCommandLine
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__userpurge VCR_Hook_GetCommandLine@<eax>(
        char a1@<dh>,
        int a2@<ebx>,
        int a3@<ebp>,
        const void *a4@<edi>,
        int a5@<esi>,
        int a6,
        int a7)
{
  int v8; // ebx
  char *v9; // ecx
  bool v10; // zf
  int v11; // esi
  rsize_t v12; // eax
  char *v13; // esi

  *(_BYTE *)(a5 + 5) |= a1;
  _invalid_parameter_noinfo_0();
  *(_DWORD *)(a3 - 32) = a2;
  v8 = *(_DWORD *)(a3 + 8);
  v9 = *(char **)(v8 + 4);
  *(_DWORD *)(a3 - 40) = *(_DWORD *)(a3 - 24);
  *(_DWORD *)(a3 - 36) = a5;
  *(_DWORD *)(a3 - 48) = a2;
  *(_DWORD *)(a3 - 44) = a4;
  v11 = (a5 - (int)a4) >> 2;
  v10 = v11 == 0;
  v12 = 4 * v11;
  v13 = &v9[4 * v11];
  if ( !v10 )
    memmove_s_0(Destination: v9, DestinationSize: v12, Source: a4, SourceSize: v12);
  *(_DWORD *)(v8 + 8) = v13;
  *(_DWORD *)(a3 - 4) = -1;
  return (char *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x3F00C7A0
// Name: VCR_Hook_RegOpenKeyEx
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge VCR_Hook_RegOpenKeyEx@<eax>(
        char a1@<cl>,
        _DWORD *a2@<ebx>,
        int a3@<ebp>,
        int a4@<esi>,
        void *hKey,
        const char *lpSubKey,
        unsigned int ulOptions,
        unsigned int samDesired,
        void *pHKey)
{
  *(_BYTE *)(a3 + 4) = 0;
  *((_BYTE *)a2 - 265615247) |= a1;
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  if ( a4 >> 2 != 0 && (unsigned __int8)((int (*)(void))loc_3F00CBF0)() != 0 )
    a2[2] = ((int (__thiscall *)(_DWORD, _DWORD))loc_3F00DBE0)(a1: a2[1], a2: *(_DWORD *)(*(_DWORD *)(a3 + 12) + 4));
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F00C960
// Name: VCR_Hook_RegSetValueEx
// Source: json
//------------------------------------------------------------------------------
int __usercall VCR_Hook_RegSetValueEx@<eax>(int a1@<eax>)
{
  _BYTE v3[8]; // [esp+Eh] [ebp-8h] BYREF

  sub_3F00C800(a1: v3, a2: a1, a3: **(_DWORD **)(a1 + 4), a4: a1, a5: *(_DWORD *)(a1 + 4));
  j__free(Block: *(void **)(a1 + 4));
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00CB30
// Name: VCR_Hook_RegQueryValueEx
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall VCR_Hook_RegQueryValueEx@<eax>(int result@<eax>, int a2@<edi>)
{
  *(_DWORD *)(a2 + 8) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00CDA0
// Name: VCR_Hook_RegCreateKeyEx
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall VCR_Hook_RegCreateKeyEx(char a1@<dh>, int a2@<ebx>, int a3@<ebp>, int **a4@<edi>)
{
  int *v4; // esi
  int v5; // edx
  int v6; // eax
  int *i; // ecx
  int *v8; // eax
  int v9; // ecx
  bool v10; // zf
  int v11; // eax
  int v12; // ecx
  int v13; // [esp-26h] [ebp-3Ch]
  int v14; // [esp-22h] [ebp-38h]
  int v15; // [esp-1Eh] [ebp-34h]
  int v16; // [esp-1Ah] [ebp-30h]
  int v17; // [esp-16h] [ebp-2Ch]
  int v18; // [esp-12h] [ebp-28h]
  int v19; // [esp-Eh] [ebp-24h]
  int v20; // [esp-Ah] [ebp-20h]
  int v21; // [esp-6h] [ebp-1Ch]
  int v22; // [esp-2h] [ebp-18h]

  *(_BYTE *)(a3 + 123) |= a1;
  v4 = *(int **)(a2 + 4);
  if ( *((_BYTE *)a4 + 33) == 0 )
    a4[1] = v4;
  v5 = *(_DWORD *)(a3 + 8);
  v6 = *(_DWORD *)(v5 + 4);
  if ( *(_DWORD *)(v6 + 4) == a2 )
  {
    *(_DWORD *)(v6 + 4) = a4;
  }
  else if ( *v4 == a2 )
  {
    *v4 = (int)a4;
  }
  else
  {
    v4[2] = (int)a4;
  }
  if ( **(_DWORD **)(v5 + 4) == a2 )
  {
    if ( *((_BYTE *)a4 + 33) != 0 )
    {
      i = v4;
    }
    else
    {
      v8 = *a4;
      for ( i = (int *)a4; *((_BYTE *)v8 + 33) == 0; v8 = (int *)*v8 )
        i = v8;
    }
    **(_DWORD **)(v5 + 4) = i;
  }
  v9 = *(_DWORD *)(v5 + 4);
  v10 = *(_DWORD *)(v9 + 8) == a2;
  *(_DWORD *)(a3 - 20) = v9;
  if ( v10 )
  {
    if ( *((_BYTE *)a4 + 33) != 0 )
    {
      *(_DWORD *)(v9 + 8) = v4;
    }
    else
    {
      v11 = ((int (__stdcall *)(int, int, int, int))loc_3F00D0B0)(a1: v13, a2: v14, a3: v15, a4: v16);
      v5 = *(_DWORD *)(a3 + 8);
      *(_DWORD *)(*(_DWORD *)(a3 - 20) + 8) = v11;
    }
  }
  if ( *(_BYTE *)(*(_DWORD *)(a3 - 16) + 32) != 1 )
    goto LABEL_42;
  if ( a4 == *(int ***)(*(_DWORD *)(v5 + 4) + 4) )
    goto LABEL_41;
  while ( 1 )
  {
    if ( *((_BYTE *)a4 + 32) != 1 )
      goto LABEL_41;
    v12 = *v4;
    if ( a4 == (int **)*v4 )
    {
      v12 = v4[2];
      if ( *(_BYTE *)(v12 + 32) == 0 )
      {
        *(_BYTE *)(v12 + 32) = 1;
        *((_BYTE *)v4 + 32) = 0;
        ((void (__thiscall *)(int *, int, int, int, int, int, int))loc_3F00D750)(
          a1: v4,
          a2: v5,
          a3: v13,
          a4: v14,
          a5: v15,
          a6: v16,
          a7: v17);
        v12 = v4[2];
        v5 = *(_DWORD *)(a3 + 8);
      }
      if ( *(_BYTE *)(v12 + 33) != 0 )
        goto LABEL_36;
      if ( *(_BYTE *)(*(_DWORD *)v12 + 32) != 1 || *(_BYTE *)(*(_DWORD *)(v12 + 8) + 32) != 1 )
      {
        if ( *(_BYTE *)(*(_DWORD *)(v12 + 8) + 32) == 1 )
        {
          *(_BYTE *)(*(_DWORD *)v12 + 32) = 1;
          *(_BYTE *)(v12 + 32) = 0;
          ((void (__stdcall *)(int, int, int, int, int, int))loc_3F00D7B0)(
            a1: v5,
            a2: v18,
            a3: v19,
            a4: v20,
            a5: v21,
            a6: v22);
          v12 = v4[2];
          v5 = *(_DWORD *)(a3 + 8);
        }
        *(_BYTE *)(v12 + 32) = *((_BYTE *)v4 + 32);
        *((_BYTE *)v4 + 32) = 1;
        *(_BYTE *)(*(_DWORD *)(v12 + 8) + 32) = 1;
        ((void (__thiscall *)(int *, int))loc_3F00D750)(a1: v4, a2: v5);
        goto LABEL_41;
      }
    }
    else
    {
      if ( *(_BYTE *)(v12 + 32) == 0 )
      {
        *(_BYTE *)(v12 + 32) = 1;
        *((_BYTE *)v4 + 32) = 0;
        ((void (__thiscall *)(int *, int, int, int, int, int, int))loc_3F00D7B0)(
          a1: v4,
          a2: v5,
          a3: v13,
          a4: v14,
          a5: v15,
          a6: v16,
          a7: v17);
        v12 = *v4;
        v5 = *(_DWORD *)(a3 + 8);
      }
      if ( *(_BYTE *)(v12 + 33) != 0 )
        goto LABEL_36;
      if ( *(_BYTE *)(*(_DWORD *)(v12 + 8) + 32) != 1 || *(_BYTE *)(*(_DWORD *)v12 + 32) != 1 )
      {
        if ( *(_BYTE *)(*(_DWORD *)v12 + 32) == 1 )
        {
          *(_BYTE *)(*(_DWORD *)(v12 + 8) + 32) = 1;
          *(_BYTE *)(v12 + 32) = 0;
          ((void (__stdcall *)(int, int, int, int, int, int))loc_3F00D750)(
            a1: v5,
            a2: v18,
            a3: v19,
            a4: v20,
            a5: v21,
            a6: v22);
          v12 = *v4;
          v5 = *(_DWORD *)(a3 + 8);
        }
        *(_BYTE *)(v12 + 32) = *((_BYTE *)v4 + 32);
        *((_BYTE *)v4 + 32) = 1;
        *(_BYTE *)(*(_DWORD *)v12 + 32) = 1;
        ((void (__thiscall *)(int *, int))loc_3F00D7B0)(a1: v4, a2: v5);
LABEL_41:
        *((_BYTE *)a4 + 32) = 1;
LABEL_42:
        JUMPOUT(0x3F00CF8C);
      }
    }
    *(_BYTE *)(v12 + 32) = 0;
LABEL_36:
    a4 = (int **)v4;
    v10 = v4 == *(int **)(*(_DWORD *)(v5 + 4) + 4);
    v4 = (int *)v4[1];
    if ( v10 )
      goto LABEL_41;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00CF90
// Name: VCR_Hook_RegCloseKey
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge VCR_Hook_RegCloseKey(
        int a1@<eax>,
        int a2@<ecx>,
        int a3@<ebx>,
        _DWORD *a4@<ebp>,
        void *hKey,
        int a6,
        int a7,
        int a8)
{
  bool v8; // zf
  _DWORD *v9; // eax
  int v10; // edx

  *(_BYTE *)(a3 + 1099630669) += a2;
  v8 = ((unsigned __int8)a1 | *(_BYTE *)(a3 - 1065024316)) == 0;
  *(_BYTE *)(a3 - 1065024316) |= a1;
  if ( !v8 )
    *(_DWORD *)(a2 + 8) = a1 - 1;
  v9 = (_DWORD *)a4[3];
  v10 = a4[5];
  *v9 = a4[4];
  v9[1] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x3F00D0E0
// Name: int VCR_Hook_GetNumberOfConsoleInputEvents(void __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __usercall VCR_Hook_GetNumberOfConsoleInputEvents@<eax>(
        int a1@<eax>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>)
{
  int result; // eax
  int v6; // [esp-Ah] [ebp-1Ch] BYREF
  int v7; // [esp-6h] [ebp-18h]
  int v8; // [esp-2h] [ebp-14h] OVERLAPPED
  int v9; // [esp+Eh] [ebp-4h]

  v9 = a1;
  v8 = a2;
  v7 = a5;
  v6 = a4;
  *(_DWORD *)(a3 - 16) = &v6;
  result = ((int (__thiscall *)(int, int, int))loc_3F00DD10)(a1: 1, a2: v6, a3: v7);
  *(_DWORD *)(a3 - 24) = result;
  *(_DWORD *)(a3 - 4) = 0;
  if ( result != 0 )
    *(_DWORD *)result = 0;
  *(_DWORD *)(a3 - 20) = 1;
  if ( result != -4 )
    *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(a3 - 20) = 2;
  if ( result != -8 )
    *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(a3 - 4) = -1;
  *(_WORD *)(result + 32) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00D2B0
// Name: int VCR_Hook_ReadConsoleInput(void __near *,void __near *,int,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__userpurge VCR_Hook_ReadConsoleInput@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        _DWORD *a3@<ebp>,
        int *a4@<edi>,
        int *a5@<esi>,
        void *hInput,
        void *pRecs,
        int nMaxRecs,
        unsigned int *pNumRead)
{
  _DWORD *v9; // eax
  char v10; // al
  int v11; // edx
  int v12; // ecx
  bool v13; // zf
  int v14; // ecx
  int v15; // eax
  _DWORD *result; // eax
  int v17; // edx

  *(_BYTE *)(a2 + 1216940099) |= a1;
  *(_BYTE *)(a2 + 1480131650) |= a1;
  v9 = *(_DWORD **)(a2 + 4);
  if ( *v9 == a2 )
    *v9 = a1;
  else
    v9[2] = a1;
  *(_DWORD *)(a1 + 4) = *(_DWORD *)(a2 + 4);
  v10 = *(_BYTE *)(a1 + 20);
  *(_BYTE *)(a1 + 20) = *(_BYTE *)(a2 + 20);
  v11 = a3[2];
  *(_BYTE *)(a2 + 20) = v10;
  if ( *(_BYTE *)(*(a3 - 4) + 20) == 1 )
  {
    if ( a4 != *(int **)(*(_DWORD *)(v11 + 4) + 4) )
    {
      do
      {
        if ( *((_BYTE *)a4 + 20) != 1 )
          break;
        v12 = *a5;
        if ( a4 == (int *)*a5 )
        {
          v12 = a5[2];
          if ( *(_BYTE *)(v12 + 20) == 0 )
          {
            *(_BYTE *)(v12 + 20) = 1;
            *((_BYTE *)a5 + 20) = 0;
            ((void (__thiscall *)(int *, int))loc_3F00D900)(a1: a5, a2: v11);
            v12 = a5[2];
            v11 = a3[2];
          }
          if ( *(_BYTE *)(v12 + 21) != 0 )
            goto LABEL_22;
          if ( *(_BYTE *)(*(_DWORD *)v12 + 20) != 1 || *(_BYTE *)(*(_DWORD *)(v12 + 8) + 20) != 1 )
          {
            if ( *(_BYTE *)(*(_DWORD *)(v12 + 8) + 20) == 1 )
            {
              *(_BYTE *)(*(_DWORD *)v12 + 20) = 1;
              *(_BYTE *)(v12 + 20) = 0;
              ((void (__stdcall *)(int))loc_3F00D960)(a1: v11);
              v12 = a5[2];
              v11 = a3[2];
            }
            *(_BYTE *)(v12 + 20) = *((_BYTE *)a5 + 20);
            *((_BYTE *)a5 + 20) = 1;
            *(_BYTE *)(*(_DWORD *)(v12 + 8) + 20) = 1;
            ((void (__thiscall *)(int *, int))loc_3F00D900)(a1: a5, a2: v11);
            break;
          }
        }
        else
        {
          if ( *(_BYTE *)(v12 + 20) == 0 )
          {
            *(_BYTE *)(v12 + 20) = 1;
            *((_BYTE *)a5 + 20) = 0;
            ((void (__thiscall *)(int *, int))loc_3F00D960)(a1: a5, a2: v11);
            v12 = *a5;
            v11 = a3[2];
          }
          if ( *(_BYTE *)(v12 + 21) != 0 )
            goto LABEL_22;
          if ( *(_BYTE *)(*(_DWORD *)(v12 + 8) + 20) != 1 || *(_BYTE *)(*(_DWORD *)v12 + 20) != 1 )
          {
            if ( *(_BYTE *)(*(_DWORD *)v12 + 20) == 1 )
            {
              *(_BYTE *)(*(_DWORD *)(v12 + 8) + 20) = 1;
              *(_BYTE *)(v12 + 20) = 0;
              ((void (__stdcall *)(int))loc_3F00D900)(a1: v11);
              v12 = *a5;
              v11 = a3[2];
            }
            *(_BYTE *)(v12 + 20) = *((_BYTE *)a5 + 20);
            *((_BYTE *)a5 + 20) = 1;
            *(_BYTE *)(*(_DWORD *)v12 + 20) = 1;
            ((void (__thiscall *)(int *, int))loc_3F00D960)(a1: a5, a2: v11);
            break;
          }
        }
        *(_BYTE *)(v12 + 20) = 0;
LABEL_22:
        a4 = a5;
        v13 = a5 == *(int **)(*(_DWORD *)(v11 + 4) + 4);
        a5 = (int *)a5[1];
      }
      while ( !v13 );
    }
    *((_BYTE *)a4 + 20) = 1;
  }
  j__free(Block: (void *)*(a3 - 4));
  v14 = a3[2];
  v15 = *(_DWORD *)(v14 + 8);
  if ( v15 != 0 )
    *(_DWORD *)(v14 + 8) = v15 - 1;
  result = (_DWORD *)a3[3];
  v17 = a3[5];
  *result = a3[4];
  result[1] = v17;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00D4D0
// Name: void VCR_Hook_LocalTime(struct tm __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge VCR_Hook_LocalTime(int a1@<ecx>, int a2@<ebp>, int a3@<edi>, _DWORD *a4@<esi>, tm *today, int a6)
{
  int ltime; // [esp+4Ch] [ebp-14h]

  *a4 = sub_3F00D470(a1, a2: ltime);
  a4[2] = sub_3F00D470(a1: *(_DWORD *)(a3 + 8), a2: a4);
  *(_DWORD *)(a2 - 4) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00D660
// Name: void VCR_Hook_Time(long __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall VCR_Hook_Time(int *today, _DWORD *a2, int a3, void *Destination, int a5, void *Source)
{
  int v6; // edi
  int v7; // eax
  int v8; // edi

  v6 = a3;
  if ( a3 == 0 || a3 != a5 )
    _invalid_parameter_noinfo_0();
  if ( Destination != Source )
  {
    v7 = (today[2] - (int)Source) >> 2;
    v8 = (int)Destination + 4 * v7;
    if ( v7 > 0 )
      memmove_s_0(Destination, DestinationSize: 4 * v7, Source, SourceSize: 4 * v7);
    today[2] = v8;
    v6 = a3;
  }
  *a2 = v6;
  a2[1] = Destination;
}

//------------------------------------------------------------------------------
// Address: 0x3F00D7D0
// Name: short VCR_Hook_GetKeyState(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge VCR_Hook_GetKeyState@<eax>(int a1@<eax>, int a2@<ecx>, int nVirtKey)
{
  unsigned int result; // eax
  unsigned int *v4; // edx

  LOBYTE(a1) = a1 - 80;
  result = (a1 | 0x89044289) - 1;
  *(_BYTE *)(a2 - 1034091455) |= a2;
  v4 = *(unsigned int **)(a2 + 4);
  if ( a2 == v4[2] )
    v4[2] = result;
  else
    *v4 = result;
  *(_DWORD *)(result + 8) = a2;
  *(_DWORD *)(a2 + 4) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00D970
// Name: void VCR_GenericRecord(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge VCR_GenericRecord(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        int a4@<ebp>,
        const char *pEventName,
        const void *pData,
        int len)
{
  int v7; // edx
  _DWORD *v8; // edx

  *(_BYTE *)(a4 + 3) += BYTE1(a2);
  *(_DWORD *)(a2 + 4) = a3;
  *(_DWORD *)(a1 + 4) = *(_DWORD *)(a3 + 4);
  v7 = *(_DWORD *)(*(_DWORD *)(a4 + 8) + 4);
  if ( a3 == *(_DWORD *)(v7 + 4) )
  {
    *(_DWORD *)(v7 + 4) = a1;
    *(_DWORD *)(a1 + 8) = a3;
    *(_DWORD *)(a3 + 4) = a1;
  }
  else
  {
    v8 = *(_DWORD **)(a3 + 4);
    if ( a3 == v8[2] )
      v8[2] = a1;
    else
      *v8 = a1;
    *(_DWORD *)(a1 + 8) = a3;
    *(_DWORD *)(a3 + 4) = a1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00DB80
// Name: int VCR_GenericPlaybackInternal(char const __near *,void __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge VCR_GenericPlaybackInternal(int maxLen, bool bForceSameLen, bool bForceSameContents)
{
  JUMPOUT(0x3F00DE10);
}

//------------------------------------------------------------------------------
// Address: 0x3F00DF40
// Name: int VCR_GenericPlayback(char const __near *,void __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall VCR_GenericPlayback(std::exception *a1@<ecx>, int a2@<ebp>)
{
  const struct std::exception *v2; // [esp-10h] [ebp-10h]

  v2 = *(const struct std::exception **)(a2 + 8);
  *(_DWORD *)(a2 - 16) = a1;
  std::exception::exception(this: a1, a2: v2);
  *(_DWORD *)(a2 - 4) = 0;
  JUMPOUT(0x3F00DF5F);
}

//------------------------------------------------------------------------------
// Address: 0x3F00DF60
// Name: void VCR_GenericValue(char const __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge VCR_GenericValue(
        char _BH@<bh>,
        int a2@<ebp>,
        int _EDI@<edi>,
        const char *pEventName,
        void *pData,
        int maxLen)
{
  __asm { rep add bh, [edi] }
  *(_DWORD *)(a2 - 4) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00DFD0
// Name: void VCR_GenericValueVerify(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge VCR_GenericValueVerify(_DWORD *a1@<ecx>, const char *pEventName, int pData, int maxLen)
{
  *a1 = &std::length_error::`vftable';
  sub_3F00E4A0(a1);
  if ( ((unsigned __int8)pEventName & 1) != 0 )
    j__free(Block: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F00E040
// Name: void WriteShortString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WriteShortString(_DWORD *this)
{
  *this = &std::length_error::`vftable';
  sub_3F00E4A0(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x3F00E0C0
// Name: void ReadAndVerifyShortString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall ReadAndVerifyShortString(int a1@<eax>, char a2@<dl>, const char *pStr)
{
  LOBYTE(a1) = a1 - 117;
  *(_BYTE *)(a1 - 24) |= a2;
  JUMPOUT(0x3F00E0C9);
}

//------------------------------------------------------------------------------
// Address: 0x3F00E1E0
// Name: void VCR_GenericRecordString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge VCR_GenericRecordString(
        const char *pEventName@<ecx>,
        char a2@<cf>,
        char a3@<zf>,
        int a4@<eax>,
        int a5@<ebx>,
        int a6@<edi>,
        unsigned int a7@<esi>,
        const char *pString,
        int a9)
{
  if ( a2 | a3 )
  {
    *(_DWORD *)(a6 + 20) = pEventName;
    if ( a7 >= 0x10 )
      a4 = a5;
    pEventName[a4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00E330
// Name: void VCR_GenericPlaybackString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __stdcall VCR_GenericPlaybackString(const char *pString, int a2, int a3)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F00E480
// Name: void VCR_GenericString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge VCR_GenericString(const char *pEventName, const char *pString)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F00E4F0
// Name: double VCR_GetPercentCompleted(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall VCR_GetPercentCompleted(int a1@<ebp>, void *a2@<esi>)
{
  *(_DWORD *)(a1 - 4) = -1;
  sub_3F01D197(this: a2);
  JUMPOUT(0x3F00E509);
}

//------------------------------------------------------------------------------
// Address: 0x3F00E510
// Name: void __near * VCR_CreateThread(void __near *,unsigned long,void __near *,void __near *,unsigned long,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall VCR_CreateThread(_DWORD *this)
{
  *this = &std::out_of_range::`vftable';
  return sub_3F00E4A0(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x3F00E7D0
// Name: unsigned long VCR_WaitForSingleObject(void __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned int __userpurge VCR_WaitForSingleObject@<eax>(
        char a1@<sf>,
        char a2@<of>,
        int a3@<edx>,
        int a4@<ebp>,
        int a5@<edi>,
        void *handle,
        unsigned int dwMilliseconds)
{
  int v7; // eax
  int i; // ecx
  unsigned int v9; // edx
  int v10; // eax
  int j; // ecx
  unsigned int v12; // edx
  int v13; // eax
  int k; // ecx
  unsigned int v15; // edx
  int v16; // eax
  int m; // ecx
  int v18; // eax
  int v19; // edx
  int v20; // ecx
  int n; // eax
  unsigned int result; // eax

  *(_BYTE *)(a4 + a3 - 272) = 1;
  if ( a1 != a2 )
    JUMPOUT(0x3F00E7C0);
  v7 = *(_DWORD *)(a4 - 12);
  if ( v7 >= 0 )
  {
    for ( i = 0; i < 32; i += 8 )
    {
      v9 = (unsigned int)v7 >> i;
      *(_BYTE *)(a4 + (unsigned __int8)v9 - 272) = 1;
    }
  }
  v10 = *(_DWORD *)(a4 - 8);
  if ( v10 >= 0 )
  {
    for ( j = 0; j < 32; j += 8 )
    {
      v12 = (unsigned int)v10 >> j;
      *(_BYTE *)(a4 + (unsigned __int8)v12 - 272) = 1;
    }
  }
  v13 = *(_DWORD *)(a4 - 4);
  if ( v13 >= 0 )
  {
    for ( k = 0; k < 32; k += 8 )
    {
      v15 = (unsigned int)v13 >> k;
      *(_BYTE *)(a4 + (unsigned __int8)v15 - 272) = 1;
    }
  }
  if ( a5 + 1 < *(unsigned __int8 *)(a4 + 12) )
    JUMPOUT(0x3F00E790);
  v16 = 0;
  for ( m = 0; m < 256; m += 4 )
  {
    if ( *(_BYTE *)(a4 + m - 272) != 0 )
      ++v16;
    if ( *(_BYTE *)(a4 + m - 271) != 0 )
      ++v16;
    if ( *(_BYTE *)(a4 + m - 270) != 0 )
      ++v16;
    if ( *(_BYTE *)(a4 + m - 269) != 0 )
      ++v16;
  }
  v18 = ((int (__cdecl *)(int))byte_3F01A077)(a1: v16);
  v19 = *(_DWORD *)(a4 + 8);
  *(_DWORD *)(v19 + 72) = v18;
  v20 = 0;
  for ( n = 1; n < 256; ++n )
  {
    if ( *(_BYTE *)(a4 + n - 272) != 0 )
    {
      *(_BYTE *)(v20 + *(_DWORD *)(v19 + 72)) = n;
      ++v20;
    }
  }
  result = *(_DWORD *)(v19 + 72);
  *(_BYTE *)(v20 + result) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EA20
// Name: unsigned long VCR_WaitForMultipleObjects(unsigned int,void const __near * __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge VCR_WaitForMultipleObjects(
        int a1@<ebp>,
        unsigned int nHandles,
        const void **pHandles,
        const void **bWaitAll,
        int timeout)
{
  int v5; // esi

  v5 = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(a1 - 4) = 0;
  if ( *(_DWORD *)(v5 + 56) >= 0x10u )
    j__free(Block: *(void **)(v5 + 36));
  *(_DWORD *)(v5 + 56) = 15;
  *(_DWORD *)(v5 + 52) = 0;
  *(_BYTE *)(v5 + 36) = 0;
  *(_DWORD *)(a1 - 4) = -1;
  if ( *(_DWORD *)(v5 + 24) >= 0x10u )
    j__free(Block: *(void **)(v5 + 4));
  *(_DWORD *)(v5 + 20) = 0;
  *(_DWORD *)(v5 + 24) = 15;
  *(_BYTE *)(v5 + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EAB0
// Name: void VCR_EnterCriticalSection(void __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall VCR_EnterCriticalSection(char a1@<zf>, int a2@<ebp>)
{
  void *v2; // eax
  int v3; // eax

  if ( a1 )
  {
    v2 = operator new(Size: 0x60u);
    *(_DWORD *)(a2 - 16) = v2;
    *(_DWORD *)(a2 - 4) = 0;
    if ( v2 != nullptr )
      v3 = sub_3F00E9B0(a1: v2);
    else
      v3 = 0;
    *(_DWORD *)(a2 - 4) = -1;
    dword_3F03D3E0 = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00AC90
// Name: public: int CVProfileArray::GetCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CVProfileArray::GetCount(CVProfileArray *this)
{
  return *((_DWORD *)this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F00ACA0
// Name: public: class CVProfile __near * CVProfileArray::GetProfile(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct CVProfile *__thiscall CVProfileArray::GetProfile(CVProfileArray *this, int a2)
{
  if ( a2 >= *((_DWORD *)this + 1) )
    return nullptr;
  else
    return *(struct CVProfile **)(*(_DWORD *)this + 4 * a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F00ACC0
// Name: public: class CVProfileArray __near & CVProfileArray::operator=(class CVProfileArray const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall CVProfileArray::operator=(_DWORD *this, _DWORD *a2)
{
  *this = *a2;
  *(this + 1) = a2[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00ACE0
// Name: public: CVProfManager::CVProfManager(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVProfManager *__thiscall CVProfManager::CVProfManager(LPCRITICAL_SECTION lpCriticalSection)
{
  InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount: 0xFA0u);
  *((_WORD *)lpCriticalSection + 14) = 0;
  *((_DWORD *)lpCriticalSection + 6) = 0;
  *((_BYTE *)lpCriticalSection + 30) = 0;
  memset((char *)lpCriticalSection + 32, 0, 0x400u);
  *((double *)lpCriticalSection + 132) = 0.0;
  return (CVProfManager *)lpCriticalSection;
}

//------------------------------------------------------------------------------
// Address: 0x3F00AD50
// Name: public: CVProfManager::~CVProfManager(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfManager::~CVProfManager(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F00AEC0
// Name: public: bool CVProfManager::BIsProfilePtrValid(class CVProfile __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall CVProfManager::BIsProfilePtrValid(char *lpCriticalSection, struct CVProfile *a2)
{
  int v3; // ecx
  char *i; // edx

  EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
  v3 = 0;
  for ( i = lpCriticalSection + 32; *(_DWORD *)i == 0 || *(struct CVProfile **)(*(_DWORD *)i + 4) != a2; i += 4 )
  {
    if ( ++v3 >= 256 )
    {
      LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
      return 0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00AF60
// Name: public: void CVProfManager::StartProfilingAllThreads(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfManager::StartProfilingAllThreads(_RTL_CRITICAL_SECTION *lpCriticalSection)
{
  int *v2; // ecx
  int i; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  EnterCriticalSection(lpCriticalSection);
  v2 = (int *)((char *)lpCriticalSection + 36);
  for ( i = 64; i != 0; --i )
  {
    v4 = *(v2 - 1);
    if ( v4 != 0 && *(_DWORD *)(v4 + 4) != 0 )
    {
      *(_BYTE *)(v4 + 8) = 1;
      *(_BYTE *)(v4 + 9) = 0;
    }
    v5 = *v2;
    if ( *v2 != 0 && *(_DWORD *)(v5 + 4) != 0 )
    {
      *(_BYTE *)(v5 + 8) = 1;
      *(_BYTE *)(v5 + 9) = 0;
    }
    v6 = v2[1];
    if ( v6 != 0 && *(_DWORD *)(v6 + 4) != 0 )
    {
      *(_BYTE *)(v6 + 8) = 1;
      *(_BYTE *)(v6 + 9) = 0;
    }
    v7 = v2[2];
    if ( v7 != 0 && *(_DWORD *)(v7 + 4) != 0 )
    {
      *(_BYTE *)(v7 + 8) = 1;
      *(_BYTE *)(v7 + 9) = 0;
    }
    v2 += 4;
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F00B010
// Name: public: void CVProfManager::StopProfilingAllThreads(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfManager::StopProfilingAllThreads(_RTL_CRITICAL_SECTION *lpCriticalSection)
{
  int *v2; // ecx
  int i; // edx
  int v4; // eax

  EnterCriticalSection(lpCriticalSection);
  v2 = (int *)((char *)lpCriticalSection + 32);
  for ( i = 256; i != 0; --i )
  {
    v4 = *v2;
    if ( *v2 != 0 && *(_DWORD *)(v4 + 4) != 0 )
    {
      *(_BYTE *)(v4 + 8) = 0;
      *(_BYTE *)(v4 + 9) = 1;
      *(_DWORD *)(v4 + 12) = 0;
    }
    ++v2;
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F00B080
// Name: public: void CVProfManager::EnableDumpSpikes(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfManager::EnableDumpSpikes(char *lpCriticalSection, int a2)
{
  char *v3; // edi
  int v4; // eax
  int v5; // esi
  int i; // [esp+14h] [ebp-10h]

  EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
  v3 = lpCriticalSection + 32;
  for ( i = 256; i != 0; --i )
  {
    v4 = *(_DWORD *)v3;
    if ( *(_DWORD *)v3 != 0 )
    {
      if ( *(_DWORD *)(v4 + 4) != 0 )
      {
        *(_BYTE *)(v4 + 8) = 1;
        *(_BYTE *)(v4 + 9) = 0;
      }
      v5 = *(_DWORD *)v3;
      if ( *(_DWORD *)(*(_DWORD *)v3 + 4) != 0 )
      {
        *(_DWORD *)(v5 + 12) = a2;
        if ( a2 > 0 )
        {
          *(_DWORD *)(v5 + 16) = 0;
          *(double *)(v5 + 24) = Plat_FloatTime();
        }
      }
    }
    v3 += 4;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F00B1D0
// Name: public: class CVProfileThreadEntry __near * CVProfManager::AddProfileForThread(class CVProfile __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct CVProfileThreadEntry *__userpurge CVProfManager::AddProfileForThread@<eax>(
        LPCRITICAL_SECTION lpCriticalSection@<ecx>,
        tagMSG *a2,
        void *a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  LPCRITICAL_SECTION v6; // esi
  DWORD **i; // edi
  char v8; // bl
  HANDLE v9; // esi
  DWORD *v10; // esi
  void *v11; // ebx
  void *v12; // eax
  char *v14; // eax
  int v16; // [esp+14h] [ebp-11Ch]
  unsigned int ExitCode[2]; // [esp+18h] [ebp-118h] BYREF
  char v18[260]; // [esp+20h] [ebp-110h] BYREF
  int v19; // [esp+12Ch] [ebp-4h]
  int savedregs; // [esp+130h] [ebp+0h] BYREF

  v6 = lpCriticalSection;
  ExitCode[1] = (unsigned int)lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  v19 = 0;
  v16 = 0;
  for ( i = (DWORD **)&v6[1].RecursionCount; *i != nullptr; ++i )
  {
    v8 = 1;
    v9 = OpenThread(dwDesiredAccess: 0x40u, bInheritHandle: false, dwThreadId: **i);
    if ( v9 == nullptr )
      goto LABEL_11;
    if ( !GetExitCodeThread(hThread: v9, lpExitCode: ExitCode) || ExitCode[0] != 259 )
      v8 = 0;
    CloseHandle(hObject: v9);
    if ( v8 == 0 )
    {
LABEL_11:
      v10 = *i;
      v11 = (void *)(*i)[1];
      if ( v11 != nullptr )
      {
        CVProfile::~CVProfile(this: (CVProfile *)(*i)[1]);
        j__free(Block: v11);
      }
      v10[1] = 0;
      j__free(Block: *i);
      *i = nullptr;
LABEL_14:
      v6 = lpCriticalSection;
      break;
    }
    if ( *i == nullptr )
      goto LABEL_14;
    if ( ++v16 >= 256 )
    {
      v14 = sub_3F008FA0(
              a1: v18,
              Format: "Assertion Failed: %s",
              "No room for new profile in vprof thread profile list, grow MAX_THREADS_TO_VPROF_AT_ONCE");
      ((void (__cdecl *)(char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: v14,
        a2: 0,
        a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
        a4: 851,
        a5: &`CVProfManager::AddProfileForThread'::`15'::fDumped,
        a6: 0);
      v19 = -1;
      LeaveCriticalSection(lpCriticalSection);
      return nullptr;
    }
    v6 = lpCriticalSection;
  }
  v12 = operator new(Size: 0x20u);
  ExitCode[0] = (unsigned int)v12;
  LOBYTE(v19) = 1;
  if ( v12 == nullptr )
    JUMPOUT(0x3F00B2F8);
  return (struct CVProfileThreadEntry *)VCR_Hook_PeekMessage(
                                          a1: (int)v12,
                                          a2: (int)&savedregs,
                                          a3: 0,
                                          a4: (int)v6,
                                          msg: a2,
                                          hWnd: a3,
                                          wMsgFilterMin: a4,
                                          wMsgFilterMax: a5,
                                          wRemoveMsg: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F00B3A0
// Name: public: void CVProfManager::Validate(class CValidator __near &,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfManager::Validate(CVProfManager *this, struct CValidator *a2, const char *a3)
{
  const char *v4; // eax
  CValObject *m_pValObjectCur; // eax

  v4 = (const char *)((int (__thiscall *)(void ***))loc_3F01A9E2)(a1: &CVProfManager `RTTI Type Descriptor');
  CValidator::Push(this: a2, a2: v4, a3: this, a4: a3);
  if ( LOBYTE(a2[1].m_cValObjectsAllocated) == 0 && BYTE1(a2->m_threadMutexValidationLock[1]) == 0 )
  {
    if ( a2->m_pValObjectCur == nullptr )
      ((void (__cdecl *)(errentry *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: &errtable[34],
        a2: 0,
        a3: &errtable[9],
        a4: 158,
        a5: &unk_3F041A88,
        a6: 0);
    m_pValObjectCur = a2->m_pValObjectCur;
    a2->m_pValObjectCur = m_pValObjectCur->m_pValObjectParent;
    if ( m_pValObjectCur->m_cubMemTree <= 0 )
      --a2->m_cValObjectsUsed;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00B440
// Name: sub_3F00B440
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F00BFD0
// Name: sub_3F00BFD0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F00BFD0@<eax>(_DWORD *a1@<esi>)
{
  int result; // eax
  int v2; // eax
  unsigned int v3; // edx
  int v4; // edi
  unsigned int *v5; // ecx
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // edx
  _DWORD *v9; // ecx
  int v10; // edx
  int v11; // edx
  int v12; // [esp+Ch] [ebp-4h]

  result = a1[1];
  if ( result != 0 )
  {
    **(_WORD **)(result + 44) |= 0x100u;
    v2 = a1[1];
    v3 = *(_DWORD *)(v2 + 20);
    *(_DWORD *)(v2 + 16) |= 4u;
    *(_DWORD *)(v2 + 16) |= 8u;
    v4 = *(_DWORD *)(v2 + 16);
    v5 = (unsigned int *)(v2 + 16);
    v12 = v2;
    v6 = *(unsigned __int16 *)(v2 + 4);
    v5[1] = v3;
    v5[1] = v5[1];
    *v5 = v4 & 0xFE0001FF | (v6 << 9);
    ((void (__thiscall *)(_DWORD, _DWORD))loc_3F00EBF0)(a1: *(_DWORD *)(v12 + 12), a2: *(_DWORD *)(v12 + 40));
    v7 = (_DWORD *)a1[1];
    v8 = v7[7];
    v7[6] &= ~0x1000u;
    v7[7] = v8;
    ((void (__thiscall *)(_DWORD, _DWORD))loc_3F00EBF0)(a1: v7[3], a2: v7[9]);
    ((void (__thiscall *)(_DWORD, _DWORD))loc_3F00EBF0)(a1: *(_DWORD *)(a1[1] + 12), a2: *(_DWORD *)(a1[1] + 32));
    v9 = (_DWORD *)a1[1];
    v10 = v9[7];
    v9[6] |= 0x1000u;
    v9[7] = v10;
    ((void (__thiscall *)(_DWORD, _DWORD))loc_3F00EBF0)(a1: v9[3], a2: v9[9]);
    result = sub_3F00BDF0(this: (_DWORD *)a1[1]);
    a1[2] = result;
    a1[3] = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00C0A0
// Name: sub_3F00C0A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F00C0A0(int a1@<esi>)
{
  _DWORD *v1; // ecx
  __int64 v2; // rax
  _DWORD *v3; // ecx
  __int64 v4; // kr00_8

  v1 = *(_DWORD **)(a1 + 4);
  if ( v1 != nullptr )
  {
    LODWORD(v2) = sub_3F00BDF0(this: v1);
    v3 = *(_DWORD **)(a1 + 4);
    *(_DWORD *)(a1 + 16) = v2;
    v4 = v2 - *(_QWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 20) = HIDWORD(v2);
    HIDWORD(v2) = v3[7];
    v3[6] &= ~0x1000u;
    v3[7] = HIDWORD(v2);
    ((void (__thiscall *)(_DWORD, _DWORD))loc_3F00EBF0)(a1: v3[3], a2: v3[9]);
    *(_DWORD *)(a1 + 24) = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00C0F0
// Name: sub_3F00C0F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F00C0F0(void *a1@<eax>, int a2@<esi>)
{
  int v2; // eax

  CValidator::Push(this: (CValidator *)a2, a2: (const char *)&__initialmbcinfo.mbctype[24], a3: a1, a4: "m_L2Cache");
  if ( *(_BYTE *)(a2 + 2112) == 0 && *(_BYTE *)(a2 + 49) == 0 )
  {
    if ( *(_DWORD *)(a2 + 8) == 0 )
      ((void (__cdecl *)(errentry *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: &errtable[34],
        a2: 0,
        a3: &errtable[9],
        a4: 158,
        a5: &unk_3F041A88,
        a6: 0);
    v2 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(v2 + 12);
    if ( *(int *)(v2 + 32) <= 0 )
      --*(_DWORD *)(a2 + 20);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00C150
// Name: sub_3F00C150
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F00C150(int this, const char *a2)
{
  *(_DWORD *)(this + 24) = 15;
  *(_DWORD *)(this + 20) = 0;
  *(_BYTE *)(this + 4) = 0;
  ((void (__thiscall *)(int, const char *, unsigned int))loc_3F00CC30)(a1: this, a2, a3: strlen(a2));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00C220
// Name: j_VCR_Hook_RegSetValueEx
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __usercall j_VCR_Hook_RegSetValueEx@<eax>(int a1@<eax>)
{
  return VCR_Hook_RegSetValueEx(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F00C230
// Name: sub_3F00C230
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_3F00C230(int a1, int a2)
{
  int v2; // eax
  _DWORD v4[7]; // [esp+0h] [ebp-1Ch] BYREF

  v4[3] = v4;
  v2 = ((int (__stdcall *)(_DWORD, _DWORD))loc_3F00D540)(a1: v4[0], a2: v4[1]);
  *(_DWORD *)(a1 + 4) = v2;
  *(_BYTE *)(v2 + 21) = 1;
  *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) = *(_DWORD *)(a1 + 4);
  **(_DWORD **)(a1 + 4) = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(*(_DWORD *)(a1 + 4) + 8) = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 8) = 0;
  v4[6] = 0;
  sub_3F00CA70(a1: a2);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00C2A4
// Name: sub_3F00C2A4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn sub_3F00C2A4()
{
  sub_3F00CB00();
  _CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F00C2C0
// Name: sub_3F00C2C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int sub_3F00C2C0(void)
{
  return sub_3F00CB00();
}

//------------------------------------------------------------------------------
// Address: 0x3F00C2D0
// Name: sub_3F00C2D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall sub_3F00C2D0(_DWORD *this, _DWORD *a2)
{
  int v3; // eax
  size_t v4; // ecx
  unsigned int v5; // esi
  char *v6; // eax
  unsigned int v7; // esi
  _DWORD *v9; // [esp+0h] [ebp-3Ch] BYREF
  unsigned int v10; // [esp+4h] [ebp-38h]
  _DWORD *v11; // [esp+Ch] [ebp-30h]
  unsigned int v12; // [esp+10h] [ebp-2Ch]
  _DWORD *v13; // [esp+14h] [ebp-28h]
  _DWORD *v14; // [esp+1Ch] [ebp-20h]
  _DWORD *v15; // [esp+24h] [ebp-18h]
  unsigned int v16; // [esp+28h] [ebp-14h]
  _DWORD *v17; // [esp+2Ch] [ebp-10h]
  int v18; // [esp+38h] [ebp-4h]

  v17 = &v9;
  v3 = *(this + 1);
  v4 = 0;
  if ( v3 != 0 )
    v5 = (*(this + 2) - v3) >> 5;
  else
    v5 = 0;
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  if ( v5 != 0 )
  {
    if ( v5 > 0x7FFFFFF )
      ((void (__stdcall *)(_DWORD *, unsigned int))loc_3F00D5E0)(a1: v9, a2: v10);
    if ( v5 > v4 )
      v6 = (char *)((int (__thiscall *)(unsigned int))loc_3F00DC10)(a1: v5);
    else
      v6 = (char *)operator new(Size: v4);
    a2[1] = v6;
    a2[2] = v6;
    a2[3] = &v6[32 * v5];
    v18 = 0;
    v16 = *(this + 2);
    v14 = nullptr;
    if ( *(this + 1) > v16 )
      _invalid_parameter_noinfo_0();
    v14 = this;
    v7 = *(this + 1);
    v13 = nullptr;
    if ( v7 > *(this + 2) )
      _invalid_parameter_noinfo_0();
    v13 = this;
    v11 = v14;
    v12 = v16;
    v15 = this;
    v16 = v7;
    LOBYTE(v16) = 0;
    v10 = v16;
    v9 = a2;
    a2[2] = ((int (__stdcall *)(unsigned int, unsigned int))loc_3F00DE10)(a1: v7, a2: v12);
    v18 = -1;
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F00C3E0
// Name: sub_3F00C3E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F00C3E0(int a1@<esi>)
{
  if ( *(_DWORD *)(a1 + 4) != 0 )
    j__free(Block: *(void **)(a1 + 4));
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00C410
// Name: sub_3F00C410
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_3F00C410@<eax>(_DWORD *result@<eax>, _DWORD *pOutData)
{
  _DWORD *v2; // esi
  int v3; // edi
  unsigned int v4; // edx
  int v5; // ecx
  unsigned int v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  bool v15; // [esp-4h] [ebp-10h]
  bool v16; // [esp+0h] [ebp-Ch]

  v2 = result;
  if ( result != pOutData )
  {
    v3 = pOutData[1];
    if ( v3 != 0 && (v4 = (pOutData[2] - v3) >> 5) != 0 )
    {
      v5 = result[1];
      if ( v5 != 0 )
        v6 = (result[2] - v5) >> 5;
      else
        v6 = 0;
      if ( v4 > v6 )
      {
        if ( v5 != 0 )
          v8 = (v2[3] - v5) >> 5;
        else
          v8 = 0;
        if ( v4 > v8 )
        {
          if ( v5 != 0 )
            j__free(Block: (void *)v2[1]);
          v12 = pOutData[1];
          if ( v12 != 0 )
            v13 = (pOutData[2] - v12) >> 5;
          else
            v13 = 0;
          v2[1] = 0;
          v2[2] = 0;
          v2[3] = 0;
          if ( v13 != 0 && (unsigned __int8)((int (*)(void))loc_3F00CBA0)() != 0 )
          {
            VCR_GenericPlaybackInternal(maxLen: pOutData[1], bForceSameLen: pOutData[2], bForceSameContents: v15);
            v2[2] = v14;
          }
          return v2;
        }
        else
        {
          if ( v5 != 0 )
            v9 = (v2[2] - v5) >> 5;
          else
            v9 = 0;
          v10 = pOutData[1] + 32 * v9;
          ((void (__stdcall *)(int))loc_3F00DB40)(a1: v10);
          VCR_GenericPlaybackInternal(maxLen: v10, bForceSameLen: pOutData[2], bForceSameContents: v16);
          v2[2] = v11;
          return v2;
        }
      }
      else
      {
        ((void (__stdcall *)(_DWORD))loc_3F00DB40)(a1: pOutData[2]);
        v7 = pOutData[1];
        if ( v7 != 0 )
          v2[2] = v2[1] + 32 * ((pOutData[2] - v7) >> 5);
        else
          v2[2] = v2[1];
        return v2;
      }
    }
    else
    {
      ((void (*)(void))loc_3F00CB60)();
      return v2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00C800
// Name: sub_3F00C800
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__userpurge sub_3F00C800@<eax>(int a1@<edi>, _DWORD *a2, int a3, int a4, int a5, int a6)
{
  int v6; // ebx
  int v7; // esi
  _DWORD *v8; // eax
  int v10; // [esp+0h] [ebp-1Ch]
  _BYTE v11[12]; // [esp+8h] [ebp-14h] BYREF
  int v12; // [esp+14h] [ebp-8h]

  v6 = a3;
  v12 = **(_DWORD **)(a1 + 4);
  if ( a3 == 0 || a3 != a1 )
    _invalid_parameter_noinfo_0();
  v7 = a4;
  if ( a4 != v12 )
    goto LABEL_13;
  v12 = *(_DWORD *)(a1 + 4);
  if ( a5 == 0 || a5 != a1 )
    _invalid_parameter_noinfo_0();
  if ( a6 == v12 )
  {
    ((void (__thiscall *)(int, _DWORD))loc_3F00D710)(a1, a2: *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4));
    *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) = *(_DWORD *)(a1 + 4);
    v8 = *(_DWORD **)(a1 + 4);
    *(_DWORD *)(a1 + 8) = 0;
    *v8 = v8;
    *(_DWORD *)(*(_DWORD *)(a1 + 4) + 8) = *(_DWORD *)(a1 + 4);
    a2[1] = **(_DWORD **)(a1 + 4);
    *a2 = a1;
    return a2;
  }
  else
  {
LABEL_13:
    while ( 1 )
    {
      if ( v6 == 0 || v6 != a5 )
        _invalid_parameter_noinfo_0();
      if ( v7 == a6 )
        break;
      v12 = v7;
      ((void (__stdcall *)(int))loc_3F00DA60)(a1: v10);
      v10 = v12;
      ((void (__cdecl *)(int, _BYTE *, int))loc_3F00CD00)(a1, a2: v11, a3: v6);
      v7 = a4;
      v6 = a3;
    }
    a2[1] = v7;
    *a2 = v6;
    return a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00C8D0
// Name: sub_3F00C8D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int *__userpurge sub_3F00C8D0@<eax>(int a1@<eax>, int a2)
{
  int v3; // edi
  int **v4; // edx
  int *result; // eax
  int *v6; // ecx
  int v7; // esi
  int **v8; // ecx

  v3 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v3 + 4) = ((int (__thiscall *)(int, _DWORD, int))loc_3F00D000)(
                          a1,
                          a2: *(_DWORD *)(*(_DWORD *)(a2 + 4) + 4),
                          a3: v3);
  v4 = *(int ***)(a1 + 4);
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a2 + 8);
  result = v4[1];
  if ( *((_BYTE *)result + 33) != 0 )
  {
    *v4 = (int *)v4;
    *(_DWORD *)(*(_DWORD *)(a1 + 4) + 8) = *(_DWORD *)(a1 + 4);
  }
  else
  {
    v6 = (int *)*result;
    if ( *(_BYTE *)(*result + 33) == 0 )
    {
      do
      {
        result = v6;
        v6 = (int *)*v6;
      }
      while ( *((_BYTE *)v6 + 33) == 0 );
    }
    *v4 = result;
    v7 = *(_DWORD *)(a1 + 4);
    v8 = *(int ***)(v7 + 4);
    for ( result = v8[2]; *((_BYTE *)result + 33) == 0; result = (int *)result[2] )
      v8 = (int **)result;
    *(_DWORD *)(v7 + 8) = v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00C9A0
// Name: sub_3F00C9A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__userpurge sub_3F00C9A0@<eax>(int a1@<edi>, _DWORD *a2, int a3, int a4, int a5, int a6)
{
  int v6; // ebx
  int v7; // esi
  _DWORD *v8; // eax
  int v10; // [esp+0h] [ebp-1Ch]
  _BYTE v11[12]; // [esp+8h] [ebp-14h] BYREF
  int v12; // [esp+14h] [ebp-8h]

  v6 = a3;
  v12 = **(_DWORD **)(a1 + 4);
  if ( a3 == 0 || a3 != a1 )
    _invalid_parameter_noinfo_0();
  v7 = a4;
  if ( a4 != v12 )
    goto LABEL_13;
  v12 = *(_DWORD *)(a1 + 4);
  if ( a5 == 0 || a5 != a1 )
    _invalid_parameter_noinfo_0();
  if ( a6 == v12 )
  {
    ((void (__thiscall *)(int, _DWORD))loc_3F00D8C0)(a1, a2: *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4));
    *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) = *(_DWORD *)(a1 + 4);
    v8 = *(_DWORD **)(a1 + 4);
    *(_DWORD *)(a1 + 8) = 0;
    *v8 = v8;
    *(_DWORD *)(*(_DWORD *)(a1 + 4) + 8) = *(_DWORD *)(a1 + 4);
    a2[1] = **(_DWORD **)(a1 + 4);
    *a2 = a1;
    return a2;
  }
  else
  {
LABEL_13:
    while ( 1 )
    {
      if ( v6 == 0 || v6 != a5 )
        _invalid_parameter_noinfo_0();
      if ( v7 == a6 )
        break;
      v12 = v7;
      ((void (__stdcall *)(int))loc_3F00DAD0)(a1: v10);
      v10 = v12;
      ((void (__cdecl *)(int, _BYTE *, int))loc_3F00D170)(a1, a2: v11, a3: v6);
      v7 = a4;
      v6 = a3;
    }
    a2[1] = v7;
    *a2 = v6;
    return a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00CA70
// Name: sub_3F00CA70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__userpurge sub_3F00CA70@<eax>(int a1@<eax>, int a2)
{
  int v3; // edi
  int **v4; // edx
  int *result; // eax
  int *v6; // ecx
  int v7; // esi
  int **v8; // ecx

  v3 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v3 + 4) = sub_3F00D470(a1: *(_DWORD *)(*(_DWORD *)(a2 + 4) + 4), a2: v3);
  v4 = *(int ***)(a1 + 4);
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a2 + 8);
  result = v4[1];
  if ( *((_BYTE *)result + 21) != 0 )
  {
    *v4 = (int *)v4;
    *(_DWORD *)(*(_DWORD *)(a1 + 4) + 8) = *(_DWORD *)(a1 + 4);
  }
  else
  {
    v6 = (int *)*result;
    if ( *(_BYTE *)(*result + 21) == 0 )
    {
      do
      {
        result = v6;
        v6 = (int *)*v6;
      }
      while ( *((_BYTE *)v6 + 21) == 0 );
    }
    *v4 = result;
    v7 = *(_DWORD *)(a1 + 4);
    v8 = *(int ***)(v7 + 4);
    for ( result = v8[2]; *((_BYTE *)result + 21) == 0; result = (int *)result[2] )
      v8 = (int **)result;
    *(_DWORD *)(v7 + 8) = v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00CB00
// Name: sub_3F00CB00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F00CB00@<eax>(int a1@<eax>)
{
  int v3; // [esp+8h] [ebp-8h] BYREF

  sub_3F00C9A0(a1, a2: &v3, a3: a1, a4: **(_DWORD **)(a1 + 4), a5: a1, a6: *(_DWORD *)(a1 + 4));
  j__free(Block: *(void **)(a1 + 4));
  *(_DWORD *)(a1 + 4) = 0;
  return VCR_Hook_RegQueryValueEx(result: 0, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F00D440
// Name: sub_3F00D440
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__usercall sub_3F00D440@<eax>(int a1@<eax>)
{
  _DWORD *result; // eax

  ((void (__thiscall *)(int, _DWORD))loc_3F00D8C0)(a1, a2: *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4));
  *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) = *(_DWORD *)(a1 + 4);
  result = *(_DWORD **)(a1 + 4);
  *(_DWORD *)(a1 + 8) = 0;
  *result = result;
  *(_DWORD *)(*(_DWORD *)(a1 + 4) + 8) = *(_DWORD *)(a1 + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00D470
// Name: sub_3F00D470
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F00D470(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  _DWORD v5[4]; // [esp+0h] [ebp-24h] BYREF
  _DWORD *v6; // [esp+10h] [ebp-14h]
  _DWORD *v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v7 = v5;
  v5[3] = this;
  v3 = (_DWORD *)*(this + 1);
  v6 = v3;
  if ( *(_BYTE *)(a2 + 21) != 0 )
    JUMPOUT(0x3F00D4F0);
  v4 = (_DWORD *)((int (__thiscall *)(int, _DWORD *))loc_3F00D9C0)(a1: a2 + 12, a2: v3);
  if ( *((_BYTE *)v6 + 21) != 0 )
    v6 = v4;
  v8 = 0;
  VCR_Hook_LocalTime(a1: *(_DWORD *)a2, a2: (int)&savedregs, a3: a2, a4: v4, today: (tm *)a2, a6: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F00E4A0
// Name: sub_3F00E4A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F00E4A0(void **this)
{
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  *this = &std::logic_error::`vftable';
  if ( (unsigned int)*(this + 9) >= 0x10 )
    j__free(Block: *(this + 4));
  *(this + 9) = (void *)15;
  *(this + 8) = nullptr;
  *((_BYTE *)this + 16) = 0;
  VCR_GetPercentCompleted(a1: (int)&savedregs, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x3F00E8F0
// Name: sub_3F00E8F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F00E8F0(char *this)
{
  char *v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edi
  char *v10; // esi
  char *v16; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  unsigned int v18; // [esp+14h] [ebp-4h]

  _EAX = 0x80000000;
  __asm { cpuid }
  v18 = _EAX;
  if ( _EAX < 0 )
  {
    v6 = (char *)((int (__cdecl *)(int))byte_3F01A077)(a1: (unsigned __int64)(unsigned int)(4 * _EAX) >> 30 != 0 ? -1 : 16 * _EAX);
    v7 = v18;
    v8 = -2147483647;
    v16 = v6;
    for ( i = -2147483647; v8 <= v18; i = v8 )
    {
      _EAX = i;
      v10 = &v6[16 * v8 - 16];
      __asm { cpuid }
      *(_DWORD *)v10 = _EAX;
      *((_DWORD *)v10 + 1) = _EBX;
      *((_DWORD *)v10 + 2) = _ECX;
      *((_DWORD *)v10 + 3) = _EDX;
      v7 = v18;
      v6 = v16;
      ++v8;
    }
    if ( v7 >= 0x80000002 )
      ((void (__thiscall *)(char *, char *, unsigned int))loc_3F00CC30)(a1: this + 32, a2: v6 + 16, a3: strlen(v6 + 16));
    j__free(Block: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00E9B0
// Name: sub_3F00E9B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_3F00E9B0(int a1)
{
  ((void (__cdecl *)(int))loc_3F00E5D0)(a1);
  *(double *)(a1 + 88) = 0.0;
  *(_DWORD *)(a1 + 76) = 0;
  *(_BYTE *)(a1 + 80) = 0;
  ((void (*)(void))loc_3F00EAF0)();
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EA10
// Name: sub_3F00EA10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F00EC10
// Name: VCR_WriteVal_unsigned_long_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall __noreturn VCR_WriteVal_unsigned_long_(unsigned int *val)
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F00EC30
// Name: ?GetSubNode@CVProfNode@@QAEPAV1@PBDH0H@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge CVProfNode::GetSubNode@<eax>(
        CVProfNode *this@<ecx>,
        int a2@<ebp>,
        const char *pszName,
        int detailLevel,
        const char *pBudgetGroupName,
        int budgetFlags)
{
  int result; // eax
  DWORD v7; // [esp-20h] [ebp-20h]
  void *v8; // [esp-1Ch] [ebp-1Ch]
  DWORD v9; // [esp-18h] [ebp-18h]
  void *v10; // [esp-14h] [ebp-14h]
  DWORD v11; // [esp-10h] [ebp-10h]
  unsigned int *v12; // [esp-Ch] [ebp-Ch]
  _OVERLAPPED *v13; // [esp-8h] [ebp-8h]

  result = DeviceIoControl(
             hDevice: this,
             dwIoControlCode: v7,
             lpInBuffer: v8,
             nInBufferSize: v9,
             lpOutBuffer: v10,
             nOutBufferSize: v11,
             lpBytesReturned: v12,
             lpOverlapped: v13);
  if ( result == 0 && *(_DWORD *)(a2 + 8) != 0 )
    return -8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EC50
// Name: sub_3F00EC50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F00EC50(void *a1@<eax>, int a2@<esi>)
{
  int v2; // eax

  CValidator::Push(
    this: (CValidator *)a2,
    a2: (const char *)&__initialmbcinfo.mbctype[112],
    a3: a1,
    a4: (const char *)&__initialmbcinfo.mbctype[112]);
  if ( *(_BYTE *)(a2 + 2112) == 0 && *(_BYTE *)(a2 + 49) == 0 )
  {
    if ( *(_DWORD *)(a2 + 8) == 0 )
      ((void (__cdecl *)(errentry *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: &errtable[34],
        a2: 0,
        a3: &errtable[9],
        a4: 158,
        a5: &unk_3F041A88,
        a6: 0);
    v2 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(v2 + 12);
    if ( *(int *)(v2 + 32) <= 0 )
      --*(_DWORD *)(a2 + 20);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00ECD0
// Name: ?GetSubNode@CVProfNode@@QAEPAV1@PBDH0@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfNode::GetSubNode(
        CVProfNode *this@<ecx>,
        char a2@<cf>,
        void *a3@<eax>,
        void (__cdecl *a4)(_DWORD, _DWORD, _DWORD, _DWORD)@<esi>,
        const char *pszName,
        int detailLevel,
        const char *pBudgetGroupName)
{
  LOBYTE(a3) = a2;
  hEvent = a3;
  if ( dword_3F0415B4 == nullptr )
  {
    a4(a1: 0, a2: 0, a3: 0, a4: 0);
    JUMPOUT(0x3F00ECE9);
  }
  JUMPOUT(0x3F00ECEE);
}
