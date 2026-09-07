// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier3/choreoutils.cpp
// Functions: 30
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004CDCA0
// Name: LookupSequence
// Source: json
//------------------------------------------------------------------------------
int __usercall LookupSequence@<eax>(CStudioHdr *pStudioHdr@<edi>, const char *pSequenceName)
{
  int i; // esi
  int v3; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v5; // eax
  mstudioseqdesc_t *v6; // eax

  for ( i = 0; ; ++i )
  {
    v3 = pStudioHdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: pStudioHdr)
       : pStudioHdr->m_pStudioHdr->numlocalseq;
    if ( i >= v3 )
      break;
    if ( pStudioHdr->m_pVModel != nullptr )
    {
      v6 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i);
    }
    else
    {
      m_pStudioHdr = pStudioHdr->m_pStudioHdr;
      v5 = i;
      if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
        v5 = 0;
      v6 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v5 + m_pStudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: pSequenceName, s2: (const char *)v6 + v6->szlabelindex) == 0 )
      return i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004CDD80
// Name: bool UpdateGestureLength(class CChoreoEvent __near *,class CStudioHdr __near *,float __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UpdateGestureLength(CChoreoEvent *e, CStudioHdr *pStudioHdr, float *pPoseParameters, bool bCheckOnly)
{
  char *Parameters; // eax
  int v7; // eax
  char v8; // bl
  float flCurDuration; // [esp+10h] [ebp-4h] BYREF
  float flSeqDuration; // [esp+1Ch] [ebp+8h]

  if ( e == nullptr || CChoreoEvent::GetType(this: e) != GESTURE )
    return 0;
  Parameters = CChoreoEvent::GetParameters(this: e);
  v7 = LookupSequence(pStudioHdr, pSequenceName: Parameters);
  if ( v7 < 0 )
    return 0;
  v8 = 0;
  flSeqDuration = Studio_Duration(pStudioHdr, iSequence: v7, poseParameter: pPoseParameters);
  CChoreoEvent::GetGestureSequenceDuration(this: e, duration: &flCurDuration);
  if ( flSeqDuration != 0.0 && flSeqDuration != flCurDuration )
  {
    v8 = 1;
    if ( !bCheckOnly )
      CChoreoEvent::SetGestureSequenceDuration(this: e, duration: flSeqDuration);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004CDE20
// Name: bool UpdateSequenceLength(class CChoreoEvent __near *,class CStudioHdr __near *,float __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UpdateSequenceLength(
        CChoreoEvent *e,
        CStudioHdr *pStudioHdr,
        float *pPoseParameters,
        bool bCheckOnly,
        bool bVerbose)
{
  char *Name; // eax
  char *Parameters; // eax
  int v9; // edi
  bool IsFixedLength; // al
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  double v14; // st7
  char *v15; // eax
  char *v16; // eax
  float endtime; // [esp+Ch] [ebp-18h]
  float endtimea; // [esp+Ch] [ebp-18h]
  char dt; // [esp+1Ch] [ebp-8h]
  float dta; // [esp+1Ch] [ebp-8h]
  float flSeqDuration; // [esp+20h] [ebp-4h]
  char bChanged_3; // [esp+2Fh] [ebp+Bh]

  if ( e == nullptr )
    return 0;
  if ( CChoreoEvent::GetType(this: e) != SEQUENCE )
  {
    if ( bVerbose )
    {
      Name = CChoreoEvent::GetName(this: e);
      ConMsg(a1: "UpdateSequenceLength:  called on non-SEQUENCE event %s\n", Name);
    }
    return 0;
  }
  Parameters = CChoreoEvent::GetParameters(this: e);
  v9 = LookupSequence(pStudioHdr, pSequenceName: Parameters);
  if ( v9 < 0 )
    return 0;
  bChanged_3 = 0;
  dt = GetSequenceFlags(pStudioHdr, nSequence: v9);
  flSeqDuration = Studio_Duration(pStudioHdr, iSequence: v9, poseParameter: pPoseParameters);
  IsFixedLength = CChoreoEvent::IsFixedLength(this: e);
  if ( (dt & 1) == 0 )
  {
    if ( !IsFixedLength )
    {
      if ( bCheckOnly )
        return 1;
      if ( bVerbose )
      {
        v13 = CChoreoEvent::GetName(this: e);
        ConMsg(a1: "CheckSequenceLength:  %s is fixed length, removing looping flag\n", v13);
      }
      bChanged_3 = 1;
    }
    CChoreoEvent::SetFixedLength(this: e, isfixedlength: true);
    if ( CChoreoEvent::CurveHasEndTime(this: e) )
    {
      v14 = ((double (__thiscall *)(CChoreoEvent *))e->GetDuration)(a1: e);
      if ( fabs(v14 - flSeqDuration) <= 0.0099999998 )
      {
        if ( bCheckOnly )
          return bChanged_3;
      }
      else
      {
        if ( bCheckOnly )
          return 1;
        if ( bVerbose )
        {
          v15 = CChoreoEvent::GetName(this: e);
          dta = v14;
          ConMsg(
            a1: "CheckSequenceLength:  %s has wrong duration, changing length from %f to %f seconds\n",
            v15,
            dta,
            flSeqDuration);
        }
        bChanged_3 = 1;
      }
    }
    else
    {
      if ( bCheckOnly )
        return 1;
      if ( bVerbose )
      {
        v16 = CChoreoEvent::GetName(this: e);
        ConMsg(a1: "CheckSequenceLength:  %s has wrong duration, changing length to %f seconds\n", v16, flSeqDuration);
      }
      bChanged_3 = 1;
    }
    endtimea = CChoreoEvent::GetStartTime(this: e) + flSeqDuration;
    CChoreoEvent::SetEndTime(this: e, endtime: endtimea);
    return bChanged_3;
  }
  if ( IsFixedLength )
  {
    if ( bCheckOnly )
      return 1;
    if ( bVerbose )
    {
      v11 = CChoreoEvent::GetName(this: e);
      ConMsg(a1: "UpdateSequenceLength:  %s is looping, removing fixed length flag\n", v11);
    }
    bChanged_3 = 1;
  }
  CChoreoEvent::SetFixedLength(this: e, isfixedlength: false);
  if ( CChoreoEvent::CurveHasEndTime(this: e) )
    return bChanged_3;
  if ( bCheckOnly )
    return 1;
  if ( bVerbose )
  {
    v12 = CChoreoEvent::GetName(this: e);
    ConMsg(a1: "CheckSequenceLength:  %s is looping, setting default end time\n", v12);
  }
  endtime = CChoreoEvent::GetStartTime(this: e) + flSeqDuration;
  CChoreoEvent::SetEndTime(this: e, endtime);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CE040
// Name: bool AutoAddGestureKeys(class CChoreoEvent __near *,class CStudioHdr __near *,float __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AutoAddGestureKeys(CChoreoEvent *e, CStudioHdr *pStudioHdr, float *pPoseParameters)
{
  char *Parameters; // eax
  char *name; // edi
  KeyValues *v5; // eax
  const studiohdr_t *m_pStudioHdr; // edx
  int studiohdr2index; // eax
  int v8; // ecx
  char *v9; // eax
  int v10; // ecx
  char *KeyValueText; // eax
  char v12; // al
  KeyValues *v13; // ecx
  KeyValues *Key; // edi
  int v16; // esi
  KeyValues *i; // edi
  const char *v18; // eax
  char *v19; // eax
  const char *v20; // eax
  char *v21; // eax
  const char *v22; // eax
  char *v23; // eax
  const char *v24; // eax
  char *String; // eax
  const char *v26; // eax
  KeyValues *FirstSubKey; // esi
  int Int; // eax
  const char *v29; // eax
  CEventAbsoluteTag *AbsoluteTag; // eax
  const char *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  CEventAbsoluteTag *v34; // eax
  CEventAbsoluteTag *v35; // eax
  CEventAbsoluteTag *v36; // eax
  CEventAbsoluteTag *v37; // eax
  CEventAbsoluteTag *v38; // eax
  CEventAbsoluteTag *v39; // eax
  CEventAbsoluteTag *v40; // eax
  CEventAbsoluteTag *v41; // eax
  CEventAbsoluteTag *v42; // eax
  float percentage; // [esp+0h] [ebp-220h]
  float percentagea; // [esp+0h] [ebp-220h]
  char szExit[128]; // [esp+10h] [ebp-210h] BYREF
  char szEndLoop[128]; // [esp+90h] [ebp-190h] BYREF
  char szStartLoop[128]; // [esp+110h] [ebp-110h] BYREF
  char szEntry[128]; // [esp+190h] [ebp-90h] BYREF
  float v49; // [esp+210h] [ebp-10h]
  int nMaxFrame; // [esp+214h] [ebp-Ch]
  KeyValues *pSeqKeyValues; // [esp+218h] [ebp-8h]
  float flPercentage; // [esp+21Ch] [ebp-4h]

  Parameters = CChoreoEvent::GetParameters(this: e);
  name = nullptr;
  flPercentage = COERCE_FLOAT(LookupSequence(pStudioHdr, pSequenceName: Parameters));
  if ( flPercentage < 0.0 )
    return 0;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    pSeqKeyValues = KeyValues::KeyValues(this: v5, setName: defaultValue);
  else
    pSeqKeyValues = nullptr;
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v8 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8], v9 = (char *)m_pStudioHdr + studiohdr2index, v8 != 0)
    && &v9[v8] != nullptr )
  {
    v10 = *((_DWORD *)v9 + 5);
    if ( v10 != 0 )
      name = &v9[v10];
  }
  else
  {
    name = m_pStudioHdr->name;
  }
  KeyValueText = (char *)Studio_GetKeyValueText(pStudioHdr, iSequence: SLODWORD(flPercentage));
  v12 = KeyValues::LoadFromBuffer(
          this: pSeqKeyValues,
          resourceName: name,
          pBuffer: KeyValueText,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  v13 = pSeqKeyValues;
  if ( v12 == 0 )
  {
LABEL_14:
    KeyValues::deleteThis(this: v13);
    return 0;
  }
  Key = KeyValues::FindKey(this: pSeqKeyValues, keyName: "faceposer", bCreate: false);
  if ( Key == nullptr )
  {
    v13 = pSeqKeyValues;
    goto LABEL_14;
  }
  v16 = Studio_MaxFrame(pStudioHdr, iSequence: SLODWORD(flPercentage), poseParameter: pPoseParameters) - 1;
  nMaxFrame = v16;
  strcpy(szStartLoop, "loop");
  memset(dst: (unsigned __int8 *)&szStartLoop[5], value: 0, count: 0x7Bu);
  *(_DWORD *)szEndLoop = (char *)&g_flexedverts[405].z + 1;
  memset(dst: (unsigned __int8 *)&szEndLoop[4], value: 0, count: 0x7Cu);
  strcpy(szEntry, "apex");
  memset(dst: (unsigned __int8 *)&szEntry[5], value: 0, count: 0x7Bu);
  *(_DWORD *)szExit = (char *)&g_flexedverts[405].z + 1;
  memset(dst: (unsigned __int8 *)&szExit[4], value: 0, count: 0x7Cu);
  for ( i = KeyValues::GetFirstSubKey(this: Key); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v18 = KeyValues::GetName(this: i);
    if ( _V_stricmp(s1: v18, s2: "startloop") != 0 )
    {
      v20 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v20, s2: "endloop") != 0 )
      {
        v22 = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: v22, s2: "entrytag") != 0 )
        {
          v24 = KeyValues::GetName(this: i);
          if ( _V_stricmp(s1: v24, s2: "exittag") != 0 )
          {
            v26 = KeyValues::GetName(this: i);
            if ( _V_stricmp(s1: v26, s2: "tags") == 0 && v16 > 0 )
            {
              FirstSubKey = KeyValues::GetFirstSubKey(this: i);
              if ( FirstSubKey != nullptr )
              {
                v49 = (float)nMaxFrame;
                do
                {
                  Int = KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
                  flPercentage = (float)Int / v49;
                  v29 = KeyValues::GetName(this: FirstSubKey);
                  AbsoluteTag = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: v29);
                  percentage = flPercentage;
                  if ( AbsoluteTag != nullptr )
                  {
                    CEventAbsoluteTag::SetPercentage(this: AbsoluteTag, percentage: flPercentage);
                  }
                  else
                  {
                    v31 = KeyValues::GetName(this: FirstSubKey);
                    CChoreoEvent::AddAbsoluteTag(this: e, type: ORIGINAL, tagname: v31, t: percentage);
                    percentagea = flPercentage;
                    v32 = KeyValues::GetName(this: FirstSubKey);
                    CChoreoEvent::AddAbsoluteTag(this: e, type: PLAYBACK, tagname: v32, t: percentagea);
                  }
                  v33 = KeyValues::GetName(this: FirstSubKey);
                  v34 = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: v33);
                  CEventAbsoluteTag::SetLocked(this: v34, bLocked: true);
                  FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
                }
                while ( FirstSubKey != nullptr );
              }
              CChoreoEvent::VerifyTagOrder(this: e);
              CChoreoEvent::PreventTagOverlap(this: e);
              v16 = nMaxFrame;
            }
          }
          else
          {
            String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
            V_strncpy(pDest: szExit, pSrc: String, maxLen: 128);
          }
        }
        else
        {
          v23 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
          V_strncpy(pDest: szEntry, pSrc: v23, maxLen: 128);
        }
      }
      else
      {
        v21 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
        V_strncpy(pDest: szEndLoop, pSrc: v21, maxLen: 128);
      }
    }
    else
    {
      v19 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
      V_strncpy(pDest: szStartLoop, pSrc: v19, maxLen: 128);
    }
  }
  v35 = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: szStartLoop);
  if ( v35 != nullptr )
    CEventAbsoluteTag::SetLinear(this: v35, bLinear: true);
  v36 = CChoreoEvent::FindAbsoluteTag(this: e, type: PLAYBACK, tagname: szStartLoop);
  if ( v36 != nullptr )
    CEventAbsoluteTag::SetLinear(this: v36, bLinear: true);
  v37 = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: szEndLoop);
  if ( v37 != nullptr )
    CEventAbsoluteTag::SetLinear(this: v37, bLinear: true);
  v38 = CChoreoEvent::FindAbsoluteTag(this: e, type: PLAYBACK, tagname: szEndLoop);
  if ( v38 != nullptr )
    CEventAbsoluteTag::SetLinear(this: v38, bLinear: true);
  v39 = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: szEntry);
  if ( v39 != nullptr )
    CEventAbsoluteTag::SetEntry(this: v39, bEntry: true);
  v40 = CChoreoEvent::FindAbsoluteTag(this: e, type: PLAYBACK, tagname: szEntry);
  if ( v40 != nullptr )
    CEventAbsoluteTag::SetEntry(this: v40, bEntry: true);
  v41 = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: szExit);
  if ( v41 != nullptr )
    CEventAbsoluteTag::SetExit(this: v41, bExit: true);
  v42 = CChoreoEvent::FindAbsoluteTag(this: e, type: PLAYBACK, tagname: szExit);
  if ( v42 != nullptr )
    CEventAbsoluteTag::SetExit(this: v42, bExit: true);
  KeyValues::deleteThis(this: pSeqKeyValues);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CE4A8
// Name: fast_error_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn fast_error_exit(int rterrnum)
{
  if ( *(_DWORD *)&__error_mode != 2 )
    _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  __crtExitProcess(status: 255);
}

//------------------------------------------------------------------------------
// Address: 0x004CE4D1
// Name: __tmainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tmainCRTStartup()
{
  int v0; // eax
  int v1; // eax
  int mainret; // [esp+14h] [ebp-20h]
  int managedapp; // [esp+18h] [ebp-1Ch]

  if ( _NoHeapEnableTerminationOnCorruption == 0 )
    HeapSetInformation(
      HeapHandle: nullptr,
      HeapInformationClass: HeapEnableTerminationOnCorruption,
      HeapInformation: nullptr,
      HeapInformationLength: 0);
  managedapp = *(_WORD *)&MEMORY[0x400000] == 23117
            && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
            && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267
            && *(_DWORD *)(MEMORY[0x40003C] + 4194420) > 0xEu
            && *(_DWORD *)(MEMORY[0x40003C] + 4194536) != 0;
  if ( !_heap_init() )
    fast_error_exit(rterrnum: 28);
  if ( _mtinit() == 0 )
    fast_error_exit(rterrnum: 16);
  _RTC_Initialize();
  if ( _ioinit() < 0 )
    _amsg_exit(rterrnum: 27);
  _acmdln = GetCommandLineA();
  _aenvptr = __crtGetEnvironmentStringsA();
  if ( _setargv() < 0 )
    _amsg_exit(rterrnum: 8);
  if ( _setenvp() < 0 )
    _amsg_exit(rterrnum: 9);
  v0 = _cinit(initFloatingPrecision: 1);
  if ( v0 != 0 )
    _amsg_exit(rterrnum: v0);
  __initenv = _environ;
  v1 = main(argc: __argc, argv: (const char **)__argv, envp: (const char **)_environ);
  mainret = v1;
  if ( managedapp == 0 )
    exit(code: v1);
  _cexit();
  return mainret;
}

//------------------------------------------------------------------------------
// Address: 0x004CE632
// Name: _mainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mainCRTStartup()
{
  __security_init_cookie();
  return _tmainCRTStartup();
}

//------------------------------------------------------------------------------
// Address: 0x004CE710
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x004CE740
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(__m128i *dst, const __m128i *src, unsigned int count)
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
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
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
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
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
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
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
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 004CE799 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *((_DWORD *)&v4[-1] + v5 - 3) = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *((_DWORD *)&v4[-1] + v5 - 2) = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *((_DWORD *)&v4[-1] + v5 - 1) = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        v4[-1].m128i_i32[v5] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        v4->m128i_i32[v5 - 3] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        v4->m128i_i32[v5 - 2] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        v4->m128i_i32[v5 - 1] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 = (__m128i *)((char *)v4 + 4 * v5);
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
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
TrailUp1:
            v4->m128i_i8[0] = *v3;
            break;
          case 2u:
TrailUp2:
            v4->m128i_i8[0] = *v3;
            v4->m128i_i8[1] = v3[1];
            break;
          case 3u:
TrailUp3:
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
// Address: 0x004CEAA1
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
    _lock_file2(i: 1, s: (char *)&v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: (char *)&v7[1]);
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
// Address: 0x004CEB48
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x004CEB60
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = value;
    if ( value != 0 || count < 0x80 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero(a1: (_BYTE *)dst, a2: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CEBE0
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004CEBE9
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x004CEBFC
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp+0h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004CEC16
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CEDAE
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CEDE0
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
// Address: 0x004CEE9E
// Name: _putenv_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl putenv_helper(char *name, const char *value)
{
  const CHAR *v3; // edi
  int v4; // eax
  int v5; // eax
  unsigned int v6; // esi
  unsigned __int8 *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned __int8 *v11; // eax
  int v12; // edi
  int v13; // eax
  unsigned __int8 *v14; // eax
  int v15; // eax
  char *newoption; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 *woption; // [esp+8h] [ebp-4h] BYREF

  newoption = nullptr;
  if ( __env_initialized == 0 )
    return -1;
  v3 = name;
  if ( name == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( value != nullptr )
  {
    v8 = strnlen(str: name, maxsize: 0x7FFFu);
    v9 = strnlen(str: value, maxsize: 0x7FFFu);
    if ( v8 < 0x7FFF && v9 < 0x7FFF )
    {
      v10 = v9 + v8 + 2;
      v11 = calloc(count: v10, size: 1u);
      newoption = (char *)v11;
      if ( v11 != nullptr )
      {
        strcpy_s(_Dst: (char *)v11, _SizeInBytes: v10, _Src: name);
        newoption[v8] = 61;
        strcpy_s(_Dst: &newoption[v8 + 1], _SizeInBytes: v10 - (v8 + 1), _Src: value);
        v3 = name;
        goto LABEL_16;
      }
      return -1;
    }
LABEL_13:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _mbschr(string: (unsigned __int8 *)name, c: 0x3Du);
  if ( v4 != 0 && (v4 - (int)name >= 0x7FFF || strnlen(str: (const char *)(v4 + 1), maxsize: 0x7FFFu) >= 0x7FFF) )
    goto LABEL_13;
  strlen(buf: name);
  v6 = v5 + 1;
  v7 = calloc(count: v5 + 1, size: 1u);
  newoption = (char *)v7;
  if ( v7 == nullptr )
    return -1;
  strcpy_s(_Dst: (char *)v7, _SizeInBytes: v6, _Src: name);
LABEL_16:
  if ( __crtsetenv(poption: &newoption, primary: 1) != 0 )
  {
    if ( newoption != nullptr )
      free(pMem: newoption);
    return -1;
  }
  if ( _wenviron == nullptr )
    return 0;
  woption = nullptr;
  v12 = MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: v3,
          cbMultiByte: -1,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  if ( v12 == 0 )
    goto LABEL_29;
  if ( value != nullptr )
  {
    v13 = MultiByteToWideChar(
            CodePage: 0,
            dwFlags: 0,
            lpMultiByteStr: value,
            cbMultiByte: -1,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    if ( v13 == 0 )
    {
LABEL_29:
      *_errno() = 42;
      return -1;
    }
    v12 += v13 + 1;
  }
  v14 = calloc(count: v12, size: 2u);
  woption = (unsigned __int16 *)v14;
  if ( v14 == nullptr )
    return -1;
  if ( MultiByteToWideChar(
         CodePage: 0,
         dwFlags: 0,
         lpMultiByteStr: name,
         cbMultiByte: -1,
         lpWideCharStr: (LPWSTR)v14,
         cchWideChar: v12) == 0
    || value != nullptr
    && (v15 = wcslen(wcs: woption),
        woption[v15] = 61,
        MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: value,
          cbMultiByte: -1,
          lpWideCharStr: &woption[v15 + 1],
          cchWideChar: v12 - (v15 + 1)) == 0) )
  {
    free(pMem: woption);
    goto LABEL_29;
  }
  if ( __crtwsetenv(poption: &woption, primary: 0) != 0 )
  {
    if ( woption != nullptr )
      free(pMem: woption);
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CF09B
// Name: __putenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _putenv(char *option)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = putenv_helper(name: option, value: nullptr);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004CF0E0
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
// Address: 0x004CF13A
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  unsigned int v3; // ebx
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
// Address: 0x004CF25E
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
// Address: 0x004CF2A7
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
// Address: 0x004CF326
// Name: __access
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access(const char *path, int amode)
{
  return -(_access_s(path, amode) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x004CF33E
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
// Address: 0x004CF3C5
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
// Address: 0x004CF43F
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
      v4 = _getenv_helper_nolock(option: varname);
      v5 = v4;
      if ( v4 == nullptr )
        goto LABEL_3;
      strlen(buf: v4);
      v7 = v6 + 1;
      v8 = calloc(count: v6 + 1, size: 1u);
      *pBuffer = (char *)v8;
      if ( v8 != nullptr )
      {
        if ( strcpy_s(_Dst: (char *)v8, _SizeInBytes: v7, _Src: v5) != 0 )
          _invoke_watson(a1: 0);
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
// Address: 0x004CF516
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
// Address: 0x004CF560
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
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 004CF5B9 case 0 }
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

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x00418E30
// Name: char __near * PSkipSoundChars(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl PSkipSoundChars(char *pch)
{
  char *result; // eax
  char v2; // cl

  for ( result = pch; ; ++result )
  {
    v2 = *result;
    if ( *result != 42
      && v2 != 63
      && v2 != 33
      && v2 != 35
      && v2 != 64
      && v2 != 40
      && v2 != 62
      && v2 != 60
      && v2 != 94
      && v2 != 41
      && v2 != 125
      && v2 != 36 )
    {
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418E80
// Name: LookupSequence
// Source: json
//------------------------------------------------------------------------------
int __usercall LookupSequence@<eax>(CStudioHdr *pStudioHdr@<edi>, const char *pSequenceName)
{
  int i; // esi
  int v3; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v5; // eax
  mstudioseqdesc_t *v6; // eax

  for ( i = 0; ; ++i )
  {
    v3 = pStudioHdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: pStudioHdr)
       : pStudioHdr->m_pStudioHdr->numlocalseq;
    if ( i >= v3 )
      break;
    if ( pStudioHdr->m_pVModel != nullptr )
    {
      v6 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i);
    }
    else
    {
      m_pStudioHdr = pStudioHdr->m_pStudioHdr;
      v5 = i;
      if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
        v5 = 0;
      v6 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v5 + m_pStudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: pSequenceName, s2: (const char *)v6 + v6->szlabelindex) == 0 )
      return i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00418F00
// Name: GetSequenceFlags
// Source: json
//------------------------------------------------------------------------------
int __usercall GetSequenceFlags@<eax>(CStudioHdr *pStudioHdr@<eax>, int nSequence@<edi>)
{
  int v3; // eax
  const studiohdr_t *m_pStudioHdr; // esi
  int v5; // eax

  if ( pStudioHdr == nullptr || nSequence < 0 )
    return 0;
  v3 = pStudioHdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: pStudioHdr)
     : pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( nSequence >= v3 )
    return 0;
  if ( pStudioHdr->m_pVModel != nullptr )
    return CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: nSequence)->flags;
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  v5 = nSequence;
  if ( nSequence >= m_pStudioHdr->numlocalseq )
    v5 = 0;
  return *(_DWORD *)&m_pStudioHdr->name[212 * v5 + m_pStudioHdr->localseqindex];
}

//------------------------------------------------------------------------------
// Address: 0x00418F60
// Name: bool UpdateGestureLength(class CChoreoEvent __near *,class CStudioHdr __near *,float __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UpdateGestureLength(CChoreoEvent *e, CStudioHdr *pStudioHdr, float *pPoseParameters, bool bCheckOnly)
{
  char *Parameters; // eax
  int v7; // eax
  char v8; // bl
  float flCurDuration; // [esp+10h] [ebp-4h] BYREF
  float flSeqDuration; // [esp+1Ch] [ebp+8h]

  if ( e == nullptr || CChoreoEvent::GetType(this: e) != GESTURE )
    return 0;
  Parameters = CChoreoEvent::GetParameters(this: e);
  v7 = LookupSequence(pStudioHdr, pSequenceName: Parameters);
  if ( v7 < 0 )
    return 0;
  v8 = 0;
  flSeqDuration = Studio_Duration(pStudioHdr, iSequence: v7, poseParameter: pPoseParameters);
  CChoreoEvent::GetGestureSequenceDuration(this: e, duration: &flCurDuration);
  if ( flSeqDuration != 0.0 && flSeqDuration != flCurDuration )
  {
    v8 = 1;
    if ( !bCheckOnly )
      CChoreoEvent::SetGestureSequenceDuration(this: e, duration: flSeqDuration);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00419000
// Name: bool UpdateSequenceLength(class CChoreoEvent __near *,class CStudioHdr __near *,float __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UpdateSequenceLength(
        CChoreoEvent *e,
        CStudioHdr *pStudioHdr,
        float *pPoseParameters,
        bool bCheckOnly,
        bool bVerbose)
{
  char *Name; // eax
  char *Parameters; // eax
  int v9; // edi
  bool IsFixedLength; // al
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  double v14; // st7
  char *v15; // eax
  char *v16; // eax
  float endtime; // [esp+Ch] [ebp-18h]
  float endtimea; // [esp+Ch] [ebp-18h]
  char dt; // [esp+1Ch] [ebp-8h]
  float dta; // [esp+1Ch] [ebp-8h]
  float flSeqDuration; // [esp+20h] [ebp-4h]
  char bChanged_3; // [esp+2Fh] [ebp+Bh]

  if ( e == nullptr )
    return 0;
  if ( CChoreoEvent::GetType(this: e) != SEQUENCE )
  {
    if ( bVerbose )
    {
      Name = CChoreoEvent::GetName(this: e);
      ConMsg(a1: "UpdateSequenceLength:  called on non-SEQUENCE event %s\n", Name);
    }
    return 0;
  }
  Parameters = CChoreoEvent::GetParameters(this: e);
  v9 = LookupSequence(pStudioHdr, pSequenceName: Parameters);
  if ( v9 < 0 )
    return 0;
  bChanged_3 = 0;
  dt = GetSequenceFlags(pStudioHdr, nSequence: v9);
  flSeqDuration = Studio_Duration(pStudioHdr, iSequence: v9, poseParameter: pPoseParameters);
  IsFixedLength = CChoreoEvent::IsFixedLength(this: e);
  if ( (dt & 1) == 0 )
  {
    if ( !IsFixedLength )
    {
      if ( bCheckOnly )
        return 1;
      if ( bVerbose )
      {
        v13 = CChoreoEvent::GetName(this: e);
        ConMsg(a1: "CheckSequenceLength:  %s is fixed length, removing looping flag\n", v13);
      }
      bChanged_3 = 1;
    }
    CChoreoEvent::SetFixedLength(this: e, isfixedlength: true);
    if ( CChoreoEvent::CurveHasEndTime(this: e) )
    {
      v14 = ((double (__thiscall *)(CChoreoEvent *))e->GetDuration)(a1: e);
      if ( fabs(v14 - flSeqDuration) <= 0.0099999998 )
      {
        if ( bCheckOnly )
          return bChanged_3;
      }
      else
      {
        if ( bCheckOnly )
          return 1;
        if ( bVerbose )
        {
          v15 = CChoreoEvent::GetName(this: e);
          dta = v14;
          ConMsg(
            a1: "CheckSequenceLength:  %s has wrong duration, changing length from %f to %f seconds\n",
            v15,
            dta,
            flSeqDuration);
        }
        bChanged_3 = 1;
      }
    }
    else
    {
      if ( bCheckOnly )
        return 1;
      if ( bVerbose )
      {
        v16 = CChoreoEvent::GetName(this: e);
        ConMsg(a1: "CheckSequenceLength:  %s has wrong duration, changing length to %f seconds\n", v16, flSeqDuration);
      }
      bChanged_3 = 1;
    }
    endtimea = CChoreoEvent::GetStartTime(this: e) + flSeqDuration;
    CChoreoEvent::SetEndTime(this: e, endtime: endtimea);
    return bChanged_3;
  }
  if ( IsFixedLength )
  {
    if ( bCheckOnly )
      return 1;
    if ( bVerbose )
    {
      v11 = CChoreoEvent::GetName(this: e);
      ConMsg(a1: "UpdateSequenceLength:  %s is looping, removing fixed length flag\n", v11);
    }
    bChanged_3 = 1;
  }
  CChoreoEvent::SetFixedLength(this: e, isfixedlength: false);
  if ( CChoreoEvent::CurveHasEndTime(this: e) )
    return bChanged_3;
  if ( bCheckOnly )
    return 1;
  if ( bVerbose )
  {
    v12 = CChoreoEvent::GetName(this: e);
    ConMsg(a1: "CheckSequenceLength:  %s is looping, setting default end time\n", v12);
  }
  endtime = CChoreoEvent::GetStartTime(this: e) + flSeqDuration;
  CChoreoEvent::SetEndTime(this: e, endtime);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419220
// Name: bool AutoAddGestureKeys(class CChoreoEvent __near *,class CStudioHdr __near *,float __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AutoAddGestureKeys(CChoreoEvent *e, CStudioHdr *pStudioHdr, float *pPoseParameters)
{
  char *Parameters; // eax
  const char *name; // edi
  KeyValues *v5; // eax
  const studiohdr_t *m_pStudioHdr; // edx
  int studiohdr2index; // eax
  int v8; // ecx
  char *v9; // eax
  int v10; // ecx
  char *KeyValueText; // eax
  char v12; // al
  KeyValues *v13; // ecx
  KeyValues *Key; // edi
  int v16; // esi
  KeyValues *i; // edi
  const char *v18; // eax
  char *v19; // eax
  const char *v20; // eax
  char *v21; // eax
  const char *v22; // eax
  char *v23; // eax
  const char *v24; // eax
  char *String; // eax
  const char *v26; // eax
  KeyValues *FirstSubKey; // esi
  int Int; // eax
  const char *v29; // eax
  CEventAbsoluteTag *AbsoluteTag; // eax
  const char *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  CEventAbsoluteTag *v34; // eax
  CEventAbsoluteTag *v35; // eax
  CEventAbsoluteTag *v36; // eax
  CEventAbsoluteTag *v37; // eax
  CEventAbsoluteTag *v38; // eax
  CEventAbsoluteTag *v39; // eax
  CEventAbsoluteTag *v40; // eax
  CEventAbsoluteTag *v41; // eax
  CEventAbsoluteTag *v42; // eax
  float percentage; // [esp+0h] [ebp-220h]
  float percentagea; // [esp+0h] [ebp-220h]
  char szExit[128]; // [esp+10h] [ebp-210h] BYREF
  char szEndLoop[128]; // [esp+90h] [ebp-190h] BYREF
  char szStartLoop[128]; // [esp+110h] [ebp-110h] BYREF
  char szEntry[128]; // [esp+190h] [ebp-90h] BYREF
  float v49; // [esp+210h] [ebp-10h]
  int nMaxFrame; // [esp+214h] [ebp-Ch]
  KeyValues *pSeqKeyValues; // [esp+218h] [ebp-8h]
  float flPercentage; // [esp+21Ch] [ebp-4h]

  Parameters = CChoreoEvent::GetParameters(this: e);
  name = nullptr;
  flPercentage = COERCE_FLOAT(LookupSequence(pStudioHdr, pSequenceName: Parameters));
  if ( flPercentage < 0.0 )
    return 0;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    pSeqKeyValues = KeyValues::KeyValues(this: v5, setName: &defaultValue);
  else
    pSeqKeyValues = nullptr;
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v8 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8], v9 = (char *)m_pStudioHdr + studiohdr2index, v8 != 0)
    && &v9[v8] != nullptr )
  {
    v10 = *((_DWORD *)v9 + 5);
    if ( v10 != 0 )
      name = &v9[v10];
  }
  else
  {
    name = m_pStudioHdr->name;
  }
  KeyValueText = (char *)Studio_GetKeyValueText(pStudioHdr, iSequence: SLODWORD(flPercentage));
  v12 = KeyValues::LoadFromBuffer(
          this: pSeqKeyValues,
          resourceName: name,
          pBuffer: KeyValueText,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  v13 = pSeqKeyValues;
  if ( v12 == 0 )
  {
LABEL_14:
    KeyValues::deleteThis(this: v13);
    return 0;
  }
  Key = KeyValues::FindKey(this: pSeqKeyValues, keyName: "faceposer", bCreate: false);
  if ( Key == nullptr )
  {
    v13 = pSeqKeyValues;
    goto LABEL_14;
  }
  v16 = Studio_MaxFrame(pStudioHdr, iSequence: SLODWORD(flPercentage), poseParameter: pPoseParameters) - 1;
  nMaxFrame = v16;
  strcpy(szStartLoop, "loop");
  memset(dst: (unsigned __int8 *)&szStartLoop[5], value: 0, count: 0x7Bu);
  strcpy(szEndLoop, "end");
  memset(dst: (unsigned __int8 *)&szEndLoop[4], value: 0, count: 0x7Cu);
  strcpy(szEntry, "apex");
  memset(dst: (unsigned __int8 *)&szEntry[5], value: 0, count: 0x7Bu);
  strcpy(szExit, "end");
  memset(dst: (unsigned __int8 *)&szExit[4], value: 0, count: 0x7Cu);
  for ( i = KeyValues::GetFirstSubKey(this: Key); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v18 = KeyValues::GetName(this: i);
    if ( _V_stricmp(s1: v18, s2: "startloop") != 0 )
    {
      v20 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v20, s2: "endloop") != 0 )
      {
        v22 = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: v22, s2: "entrytag") != 0 )
        {
          v24 = KeyValues::GetName(this: i);
          if ( _V_stricmp(s1: v24, s2: "exittag") != 0 )
          {
            v26 = KeyValues::GetName(this: i);
            if ( _V_stricmp(s1: v26, s2: "tags") == 0 && v16 > 0 )
            {
              FirstSubKey = KeyValues::GetFirstSubKey(this: i);
              if ( FirstSubKey != nullptr )
              {
                v49 = (float)nMaxFrame;
                do
                {
                  Int = KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
                  flPercentage = (float)Int / v49;
                  v29 = KeyValues::GetName(this: FirstSubKey);
                  AbsoluteTag = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: v29);
                  percentage = flPercentage;
                  if ( AbsoluteTag != nullptr )
                  {
                    CEventAbsoluteTag::SetPercentage(this: AbsoluteTag, percentage: flPercentage);
                  }
                  else
                  {
                    v31 = KeyValues::GetName(this: FirstSubKey);
                    CChoreoEvent::AddAbsoluteTag(this: e, type: ORIGINAL, tagname: v31, t: percentage);
                    percentagea = flPercentage;
                    v32 = KeyValues::GetName(this: FirstSubKey);
                    CChoreoEvent::AddAbsoluteTag(this: e, type: PLAYBACK, tagname: v32, t: percentagea);
                  }
                  v33 = KeyValues::GetName(this: FirstSubKey);
                  v34 = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: v33);
                  CEventAbsoluteTag::SetLocked(this: v34, bLocked: true);
                  FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
                }
                while ( FirstSubKey != nullptr );
              }
              CChoreoEvent::VerifyTagOrder(this: e);
              CChoreoEvent::PreventTagOverlap(this: e);
              v16 = nMaxFrame;
            }
          }
          else
          {
            String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &defaultValue);
            V_strncpy(pDest: szExit, pSrc: String, maxLen: 128);
          }
        }
        else
        {
          v23 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &defaultValue);
          V_strncpy(pDest: szEntry, pSrc: v23, maxLen: 128);
        }
      }
      else
      {
        v21 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &defaultValue);
        V_strncpy(pDest: szEndLoop, pSrc: v21, maxLen: 128);
      }
    }
    else
    {
      v19 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &defaultValue);
      V_strncpy(pDest: szStartLoop, pSrc: v19, maxLen: 128);
    }
  }
  v35 = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: szStartLoop);
  if ( v35 != nullptr )
    CEventAbsoluteTag::SetLinear(this: v35, bLinear: true);
  v36 = CChoreoEvent::FindAbsoluteTag(this: e, type: PLAYBACK, tagname: szStartLoop);
  if ( v36 != nullptr )
    CEventAbsoluteTag::SetLinear(this: v36, bLinear: true);
  v37 = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: szEndLoop);
  if ( v37 != nullptr )
    CEventAbsoluteTag::SetLinear(this: v37, bLinear: true);
  v38 = CChoreoEvent::FindAbsoluteTag(this: e, type: PLAYBACK, tagname: szEndLoop);
  if ( v38 != nullptr )
    CEventAbsoluteTag::SetLinear(this: v38, bLinear: true);
  v39 = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: szEntry);
  if ( v39 != nullptr )
    CEventAbsoluteTag::SetEntry(this: v39, bEntry: true);
  v40 = CChoreoEvent::FindAbsoluteTag(this: e, type: PLAYBACK, tagname: szEntry);
  if ( v40 != nullptr )
    CEventAbsoluteTag::SetEntry(this: v40, bEntry: true);
  v41 = CChoreoEvent::FindAbsoluteTag(this: e, type: ORIGINAL, tagname: szExit);
  if ( v41 != nullptr )
    CEventAbsoluteTag::SetExit(this: v41, bExit: true);
  v42 = CChoreoEvent::FindAbsoluteTag(this: e, type: PLAYBACK, tagname: szExit);
  if ( v42 != nullptr )
    CEventAbsoluteTag::SetExit(this: v42, bExit: true);
  KeyValues::deleteThis(this: pSeqKeyValues);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419690
// Name: char const __near * GetSoundForEvent(class CChoreoEvent __near *,class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
char *__usercall GetSoundForEvent@<eax>(const char *a1@<ebx>, CChoreoEvent *pEvent, CStudioHdr *pStudioHdr)
{
  char *Parameters; // esi
  const char *v4; // ecx
  const studiohdr_t *m_pStudioHdr; // edx
  int studiohdr2index; // eax
  int v8; // ecx
  char *v9; // eax
  int v10; // ecx
  const char *name; // eax
  char *v12; // eax

  Parameters = CChoreoEvent::GetParameters(this: pEvent);
  if ( V_stristr(a1: v4, a2: a1, pStr: Parameters, pSearch: ".wav") != nullptr )
    return PSkipSoundChars(pch: Parameters);
  if ( pStudioHdr != nullptr )
  {
    m_pStudioHdr = pStudioHdr->m_pStudioHdr;
    if ( pStudioHdr->m_pStudioHdr != nullptr )
    {
      studiohdr2index = m_pStudioHdr->studiohdr2index;
      if ( studiohdr2index == 0
        || (v8 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8],
            v9 = (char *)m_pStudioHdr + studiohdr2index,
            v8 == 0)
        || &v9[v8] == nullptr )
      {
        name = m_pStudioHdr->name;
        goto LABEL_12;
      }
      v10 = *((_DWORD *)v9 + 5);
      if ( v10 != 0 )
      {
        name = &v9[v10];
LABEL_12:
        v12 = (char *)g_pSoundEmitterSystem->GetWavFileForSound_2(this: g_pSoundEmitterSystem, a2: Parameters, a3: name);
        return PSkipSoundChars(pch: v12);
      }
    }
  }
  name = nullptr;
  goto LABEL_12;
}

} // namespace vcdupdate
