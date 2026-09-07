// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/choreogen/choreogen.cpp
// Functions: 31
// ============================================================

#include "utils\choreogen\choreogen.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: SpewStdout
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SpewStdout(SpewType_t spewType, const char *pMsg)
{
  _iobuf *v3; // eax

  if ( pMsg == nullptr )
    return true;
  printf(format: pMsg);
  v3 = __iob_func();
  fflush(stream: v3 + 1);
  return spewType != SPEW_ASSERT;
}

//------------------------------------------------------------------------------
// Address: 0x00401030
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  return AppMain(argc, (char **)argv, pAppSystemGroup: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x00401050
// Name: public: virtual bool CChoreoGenApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoGenApp::Create(CChoreoGenApp *this)
{
  void *System; // eax
  AppSystemInfo_t appSystems[8]; // [esp+0h] [ebp-44h] BYREF
  const char *v5; // [esp+40h] [ebp-4h]

  _SpewOutputFunc(a1: SpewStdout);
  appSystems[2].m_pInterfaceName = "datacache.dll";
  appSystems[3].m_pInterfaceName = "datacache.dll";
  appSystems[7].m_pInterfaceName = &wavname;
  v5 = &wavname;
  appSystems[0].m_pInterfaceName = "materialsystem.dll";
  appSystems[1].m_pModuleName = "VMaterialSystem080";
  appSystems[1].m_pInterfaceName = "p4lib.dll";
  appSystems[2].m_pModuleName = "VP4001";
  appSystems[3].m_pModuleName = "VDataCache003";
  appSystems[4].m_pModuleName = "MDLCache004";
  appSystems[4].m_pInterfaceName = "studiorender.dll";
  appSystems[5].m_pModuleName = "VStudioRender026";
  appSystems[5].m_pInterfaceName = "vphysics.dll";
  appSystems[6].m_pModuleName = "VPhysics031";
  appSystems[6].m_pInterfaceName = "soundemittersystem.dll";
  appSystems[7].m_pModuleName = "VSoundEmitter003";
  CAppSystemGroup::AddSystems(this, pSystemList: (AppSystemInfo_t *)&appSystems[0].m_pInterfaceName);
  System = CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem080");
  if ( System != nullptr )
  {
    (*(void (__cdecl **)(const char *))(*(_DWORD *)System + 24))(a1: "shaderapiempty.dll");
    return 1;
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_42F298, a2: appSystems[0].m_pInterfaceName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401130
// Name: public: virtual bool CChoreoGenApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoGenApp::PreInit(CChoreoGenApp *this)
{
  const char *v3; // [esp+20h] [ebp-Ch]
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+24h] [ebp-8h] BYREF
  void *(__cdecl *Factory)(const char *, int *); // [esp+28h] [ebp-4h] BYREF

  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  pFactoryList = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  Factory = CAppSystemGroup::GetFactory();
  ConnectTier3Libraries(pFactoryList: &Factory, nFactoryCount: 1);
  if ( g_pFullFileSystem != nullptr && g_pMDLCache != nullptr )
    return CSteamAppSystemGroup::SetupSearchPaths(
             this,
             pStartingDir: nullptr,
             bOnlyUseStartingDir: false,
             bIsTool: true);
  _Error(this: (ISceneTokenProcessor *)&stru_42F3AC, a2: v3);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004011E0
// Name: public: void CChoreoGenApp::PrintHelp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoGenApp::PrintHelp(CChoreoGenApp *this)
{
  int v1; // ecx
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx

  _Msg(a1: this, a2: "Usage: generates choreo in vcd's from authored templates.\n");
  _Msg(a1: v1, a2: "\t-i: path of the .csv file \n");
  _Msg(a1: v2, a2: "\t-npc:    npc name to process.  if specified, ignores entries\n");
  _Msg(a1: v3, a2: "\t         that dont match this name in the NPC column of the .csv. \n");
  _Msg(a1: v4, a2: "\t-filter: substring to match.  Only process wav entries that\n");
  _Msg(a1: v5, a2: "\t         match this substring. \n");
  _Msg(a1: v6, a2: "\t-nop4:   disable p4.  Wont save the vcd's if they exist and are\n");
  _Msg(a1: v7, a2: "\t         read-only\n");
  _Msg(a1: v8, a2: "\t-g:      Game. options are 'tf' or 'l4d'.  so that it the files\n");
  _Msg(a1: v9, a2: "\t         generated are named and placed in the convention of the project.\n");
  _Msg(a1: v10, a2: "\t test\n");
}

//------------------------------------------------------------------------------
// Address: 0x00401240
// Name: private: class CChoreoEvent __near * CChoreoGenApp::GetSpeakEvent(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoGenApp::GetSpeakEvent(CChoreoGenApp *this, CChoreoScene *pScene)
{
  int v2; // esi
  CChoreoEvent *Event; // edi

  v2 = 0;
  if ( (int)CChoreoScene::GetNumEvents(this: (IterateRIFF *)pScene) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Event = CChoreoScene::GetEvent(this: pScene, event: v2);
    if ( CChoreoEvent::GetType(this: Event) == SPEAK )
      break;
    if ( ++v2 >= (int)CChoreoScene::GetNumEvents(this: (IterateRIFF *)pScene) )
      return nullptr;
  }
  return Event;
}

//------------------------------------------------------------------------------
// Address: 0x00401290
// Name: private: bool CChoreoGenApp::AddEvents(class CChoreoScene __near *,struct CChoreoGenApp::ChoreoGenInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoGenApp::AddEvents(
        CChoreoGenApp *this,
        CChoreoScene *pScene,
        CChoreoGenApp::ChoreoGenInfo_t *info)
{
  CChoreoEvent *v4; // esi
  CChoreoEvent *SpeakEvent; // eax
  float starttime; // [esp+0h] [ebp-10h]

  v4 = CChoreoScene::AllocEvent(this: pScene);
  CChoreoEvent::SetType(this: v4, type: STOPPOINT);
  CChoreoEvent::SetName(this: v4, name: "FireCompletion");
  SpeakEvent = CChoreoGenApp::GetSpeakEvent(this, pScene);
  starttime = CChoreoEvent::GetEndTime(this: SpeakEvent);
  CChoreoEvent::SetStartTime(this: v4, starttime);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004012E0
// Name: private: bool CChoreoGenApp::InitTemplateData(struct CChoreoGenApp::ChoreoTemplateInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoGenApp::InitTemplateData(CChoreoGenApp *this, CChoreoGenApp::ChoreoTemplateInfo_t *tInfo)
{
  CChoreoEvent *SpeakEvent; // eax
  CChoreoEvent *v4; // edi
  const char *v5; // [esp+0h] [ebp-8h]

  if ( tInfo->m_pScene != nullptr )
  {
    SpeakEvent = CChoreoGenApp::GetSpeakEvent(this, pScene: tInfo->m_pScene);
    v4 = SpeakEvent;
    if ( SpeakEvent != nullptr )
    {
      tInfo->m_flWavStartTime = CChoreoEvent::GetStartTime(this: SpeakEvent);
      tInfo->m_flWavEndTime = CChoreoEvent::GetEndTime(this: v4);
      return 1;
    }
    else
    {
      _Warning(
        a1: "No Wav event found in template %s.\n",
        (const char *)tInfo->m_pFileName.m_Storage.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_42F660, a2: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401360
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  if ( this->m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401390
// Name: public: void CUtlMemory<struct CChoreoGenApp::ChoreoGenInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int>::Grow(
        CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CChoreoGenApp::ChoreoGenInfo_t *m_pMemory; // edx
  bool v7; // zf

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (CChoreoGenApp::ChoreoGenInfo_t *)_g_pMemAlloc->Alloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: 68 * m_nAllocationCount);
    else
      this->m_pMemory = (CChoreoGenApp::ChoreoGenInfo_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: 68 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004014E0
// Name: private: int CChoreoGenApp::GetTemplateIndex(char const __near *,class CUtlVector<struct CChoreoGenApp::ChoreoTemplateInfo_t,class CUtlMemory<struct CChoreoGenApp::ChoreoTemplateInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoGenApp::GetTemplateIndex(
        CChoreoGenApp *this,
        const char *name,
        CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int> > *templateList)
{
  int v3; // ebx
  int i; // esi
  const char *v5; // eax

  v3 = 0;
  if ( templateList->m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &templateList->m_Memory.m_pMemory[i].m_pFileName);
    if ( _stricmp(dst: name, src: v5) == 0 )
      break;
    if ( ++v3 >= templateList->m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00401530
// Name: private: class CChoreoScene __near * CChoreoGenApp::LoadVcd(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoScene *__thiscall CChoreoGenApp::LoadVcd(CChoreoGenApp *this, const char *subdir, const char *name)
{
  ISceneTokenProcessor *TokenProcessor; // eax
  CChoreoScene *Scene; // esi
  CUtlBuffer buf; // [esp+2Ch] [ebp-23Ch] BYREF
  char fullPath[260]; // [esp+5Ch] [ebp-20Ch] BYREF
  char relPath[264]; // [esp+160h] [ebp-108h] BYREF

  V_ComposeFileName(path: subdir, filename: name, dest: &relPath[4], destSize: 260);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: &relPath[4],
    a3: "GAME",
    a4: &fullPath[4],
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: &fullPath[4],
         a3: nullptr,
         a4: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    SetTokenProcessorBuffer(buf: (const char *)buf.m_Memory.m_nAllocationCount);
    TokenProcessor = GetTokenProcessor();
    Scene = ChoreoLoadScene(filename: &fullPath[4], callback: nullptr, tokenizer: TokenProcessor, pfn: nullptr);
    if ( Scene != nullptr )
    {
      if ( buf.m_Get >= 0 && buf.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
      return Scene;
    }
    else
    {
      _Warning(a1: "Error loading vcd file: %s\n", &fullPath[4]);
      if ( buf.m_Get >= 0 && buf.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
      return nullptr;
    }
  }
  else
  {
    _Warning(a1: "Error reading file: %s\n", &fullPath[4]);
    if ( buf.m_Get >= 0 && buf.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004019B0
// Name: public: char CUtlBuffer::GetChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al
  char v3; // [esp+7h] [ebp-1h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    v3 = 0;
    CUtlBuffer::Scanf(this, pFmt: "%c", &v3);
    return v3;
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401A00
// Name: public: CmdParams_t::~CmdParams_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CmdParams_t::~CmdParams_t(CmdParams_t *this)
{
  if ( this->m_vProj.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vProj.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vProj.m_Storage.m_Memory.m_pMemory);
      this->m_vProj.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_vProj.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_pFilter.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pFilter.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pFilter.m_Storage.m_Memory.m_pMemory);
      this->m_pFilter.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pFilter.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_pNpc.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pNpc.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pNpc.m_Storage.m_Memory.m_pMemory);
      this->m_pNpc.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pNpc.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401A70
// Name: private: enum CChoreoGenApp::TokenRetVal_t CChoreoGenApp::ParseToken(class CUtlBuffer __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoGenApp::ParseToken(CChoreoGenApp *this, CUtlBuffer *buf, char *pToken, int nMaxTokenLen)
{
  char *v4; // ebp
  int v6; // edi
  unsigned __int8 Char; // al
  bool v8; // bl
  unsigned __int8 v9; // cl

  v4 = pToken;
  *pToken = 0;
  if ( buf->m_Error != 0 )
    return 2;
  v6 = 0;
  Char = CUtlBuffer::GetChar(this: buf);
  v8 = false;
  while ( 1 )
  {
    if ( Char == 34 )
    {
      v8 = !v8;
    }
    else if ( (Char == 44 || Char == 10) && !v8 )
    {
      v4[v6] = 0;
      return Char == 10;
    }
    if ( v6 < nMaxTokenLen - 1 && Char != 34 )
      v4[v6++] = Char;
    if ( buf->m_Error != 0 )
      break;
    if ( (buf->m_Flags & 1) != 0 )
    {
      LOBYTE(pToken) = 0;
      CUtlBuffer::Scanf(this: buf, pFmt: "%c", &pToken);
      Char = (unsigned __int8)pToken;
    }
    else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v9 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      LOBYTE(pToken) = v9;
      Char = v9;
    }
    else
    {
      LOBYTE(pToken) = 0;
      Char = 0;
    }
  }
  v4[v6] = 0;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00401B50
// Name: public: CChoreoGenApp::ChoreoGenInfo_t::~ChoreoGenInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoGenApp::ChoreoGenInfo_t::~ChoreoGenInfo_t(CChoreoGenApp::ChoreoGenInfo_t *this)
{
  if ( this->m_pSceneTemplate.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pSceneTemplate.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSceneTemplate.m_Storage.m_Memory.m_pMemory);
      this->m_pSceneTemplate.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pSceneTemplate.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_pNpcName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pNpcName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pNpcName.m_Storage.m_Memory.m_pMemory);
      this->m_pNpcName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pNpcName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_pSndEntry.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pSndEntry.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSndEntry.m_Storage.m_Memory.m_pMemory);
      this->m_pSndEntry.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pSndEntry.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_pWavFile.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pWavFile.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pWavFile.m_Storage.m_Memory.m_pMemory);
      this->m_pWavFile.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pWavFile.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401BE0
// Name: private: class CUtlString CChoreoGenApp::GetSoundEntry(struct CChoreoGenApp::ChoreoGenInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall CChoreoGenApp::GetSoundEntry(
        CChoreoGenApp *this,
        CUtlString *result,
        CChoreoGenApp::ChoreoGenInfo_t *info)
{
  int i; // esi
  CUtlString pWav; // [esp+0h] [ebp-14h] BYREF
  char c; // [esp+1Ch] [ebp+8h]

  CUtlString::CUtlString(this: result);
  if ( g_params.m_game == 1 )
  {
    CUtlString::CUtlString(this: (CUtlString *)&pWav.m_Storage.m_Memory.m_nAllocationCount, string: &info->m_pWavFile);
    for ( i = 0; i < CUtlString::Length(this: (CUtlString *)&pWav.m_Storage.m_Memory.m_nAllocationCount); ++i )
    {
      c = CUtlString::operator char const *(this: (CUtlString *)&pWav.m_Storage.m_Memory.m_nAllocationCount)[i];
      if ( c == 95 )
        CUtlString::operator+=(this: result, c: 46);
      else
        CUtlString::operator+=(this: result, c);
    }
    if ( pWav.m_Storage.m_nActualLength >= 0 && pWav.m_Storage.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pWav.m_Storage.m_Memory.m_nAllocationCount);
  }
  else if ( g_params.m_game == 2 )
  {
    CUtlString::operator=(this: result, src: &info->m_pSndEntry);
    return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401CA0
// Name: private: float CChoreoGenApp::GetWavDurationFromEvent(class CChoreoEvent const __near *,struct CChoreoGenApp::ChoreoGenInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CChoreoGenApp::GetWavDurationFromEvent(
        CChoreoGenApp *this,
        const CChoreoEvent *pEvent,
        CChoreoGenApp::ChoreoGenInfo_t *info)
{
  char *v3; // esi
  int v4; // eax
  const char *v5; // eax
  double result; // st7
  CUtlString pSndPath; // [esp+4h] [ebp-11Ch] BYREF
  char pFullWavPath[260]; // [esp+18h] [ebp-108h] BYREF

  CUtlString::CUtlString(this: (CUtlString *)&pSndPath.m_Storage.m_Memory.m_nAllocationCount, string: &g_params.m_vProj);
  if ( g_params.m_game == 1 )
  {
    CUtlString::operator+=(this: (CUtlString *)&pSndPath.m_Storage.m_Memory.m_nAllocationCount, rhs: "/sound/vo/");
  }
  else if ( g_params.m_game == 2 )
  {
    CUtlString::operator+=(
      this: (CUtlString *)&pSndPath.m_Storage.m_Memory.m_nAllocationCount,
      rhs: "/sound/player/survivor/voice/");
    CUtlString::operator+=(this: (CUtlString *)&pSndPath.m_Storage.m_Memory.m_nAllocationCount, rhs: &info->m_pNpcName);
    CUtlString::operator+=(this: (CUtlString *)&pSndPath.m_Storage.m_Memory.m_nAllocationCount, rhs: "/");
  }
  v3 = CUtlString::Get(this: &info->m_pWavFile);
  v4 = CUtlString::Length(this: &info->m_pWavFile);
  V_SetExtension(path: v3, extension: ".wav", pathStringLength: v4 + 5);
  v5 = CUtlString::operator char const *(this: (CUtlString *)&pSndPath.m_Storage.m_Memory.m_nAllocationCount);
  V_ComposeFileName(path: v5, filename: v3, dest: &pFullWavPath[4], destSize: 260);
  result = GetWavSoundDuration(pWavFile: &pFullWavPath[4]);
  *(float *)pFullWavPath = result;
  if ( pSndPath.m_Storage.m_nActualLength >= 0 && pSndPath.m_Storage.m_Memory.m_nAllocationCount != 0 )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pSndPath.m_Storage.m_Memory.m_nAllocationCount);
    return *(float *)pFullWavPath;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401D80
// Name: private: bool CChoreoGenApp::ProcessSpeakEvent(class CChoreoEvent __near *,struct CChoreoGenApp::ChoreoGenInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoGenApp::ProcessSpeakEvent(
        CChoreoGenApp *this,
        CChoreoEvent *pSpeak,
        CChoreoGenApp::ChoreoGenInfo_t *info)
{
  CUtlString *SoundEntry; // eax
  const char *v6; // eax
  double WavDurationFromEvent; // st7
  float endtime; // [esp+4h] [ebp-20h]
  CUtlString v10; // [esp+14h] [ebp-10h] BYREF
  float fSndDur; // [esp+28h] [ebp+4h]

  if ( pSpeak == nullptr )
    return 0;
  SoundEntry = CChoreoGenApp::GetSoundEntry(this, result: &v10, info);
  v6 = CUtlString::operator char const *(this: SoundEntry);
  CChoreoEvent::SetParameters(this: pSpeak, param: v6);
  if ( v10.m_Storage.m_Memory.m_nGrowSize >= 0 && v10.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10.m_Storage.m_Memory.m_pMemory);
  CChoreoEvent::SetName(this: pSpeak, name: "SpeakEvent");
  WavDurationFromEvent = CChoreoGenApp::GetWavDurationFromEvent(this, pEvent: pSpeak, info);
  if ( WavDurationFromEvent <= 0.0 )
  {
    _Warning(a1: "error getting sound duration for %s\n", (const char *)info->m_pWavFile.m_Storage.m_Memory.m_pMemory);
    return 0;
  }
  fSndDur = WavDurationFromEvent;
  endtime = CChoreoEvent::GetStartTime(this: pSpeak) + fSndDur;
  CChoreoEvent::SetEndTime(this: pSpeak, endtime);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401EC0
// Name: private: bool CChoreoGenApp::AdjustEvents(class CChoreoScene __near *,struct CChoreoGenApp::ChoreoGenInfo_t __near &,class CUtlVector<struct CChoreoGenApp::ChoreoTemplateInfo_t,class CUtlMemory<struct CChoreoGenApp::ChoreoTemplateInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoGenApp::AdjustEvents(
        CChoreoGenApp *this,
        CChoreoScene *pScene,
        CChoreoGenApp::ChoreoGenInfo_t *info,
        CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int> > *templateList)
{
  CChoreoScene *v4; // ebx
  CChoreoGenApp::ChoreoTemplateInfo_t *v5; // esi
  CChoreoEvent *SpeakEvent; // eax
  int v7; // edi
  CChoreoEvent **m_pElements; // ebp
  CChoreoEvent *Event; // eax
  CChoreoEvent **v10; // esi
  int m_nAllocationCount; // ebx
  CChoreoEvent **v12; // esi
  int v13; // ebx
  CChoreoEvent *v14; // esi
  CCurveData *p_m_Ramp; // edi
  IterateRIFF *v16; // ecx
  int v17; // esi
  CExpressionSample *v18; // ebx
  int j; // ebx
  CChoreoEvent *v21; // esi
  CChoreoEvent::EVENTTYPE Type; // eax
  CCurveData *v23; // edi
  IterateRIFF *v24; // ecx
  int v25; // esi
  CExpressionSample *v26; // ecx
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > pExpressions; // [esp+14h] [ebp-18h] BYREF
  int v29; // [esp+28h] [ebp-4h]
  float pScenea; // [esp+30h] [ebp+4h]
  float fDelta; // [esp+34h] [ebp+8h]
  CChoreoEvent *i; // [esp+38h] [ebp+Ch]
  int ia; // [esp+38h] [ebp+Ch]

  v4 = pScene;
  v5 = &templateList->m_Memory.m_pMemory[info->m_iTemplateIndex];
  SpeakEvent = CChoreoGenApp::GetSpeakEvent(this, pScene);
  v7 = 0;
  m_pElements = nullptr;
  fDelta = CChoreoEvent::GetEndTime(this: SpeakEvent) - v5->m_flWavEndTime;
  memset(&pExpressions.m_Memory.m_nAllocationCount, 0, 16);
  v29 = 0;
  if ( (int)CChoreoScene::GetNumEvents(this: (IterateRIFF *)pScene) > 0 )
  {
    do
    {
      Event = CChoreoScene::GetEvent(this: v4, event: v7);
      if ( CChoreoEvent::GetType(this: Event) == EXPRESSION )
      {
        i = CChoreoScene::GetEvent(this: v4, event: v7);
        v10 = m_pElements;
        if ( (int)m_pElements + 1 > pExpressions.m_Memory.m_nGrowSize )
        {
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<KeyValues *,int> *)&pExpressions.m_Memory.m_nAllocationCount,
            num: (int)m_pElements - pExpressions.m_Memory.m_nGrowSize + 1);
          m_pElements = pExpressions.m_pElements;
        }
        m_nAllocationCount = pExpressions.m_Memory.m_nAllocationCount;
        m_pElements = (CChoreoEvent **)((char *)m_pElements + 1);
        pExpressions.m_pElements = m_pElements;
        v29 = pExpressions.m_Memory.m_nAllocationCount;
        if ( (char *)m_pElements - (char *)v10 - 1 > 0 )
          memmove(
            dst: (unsigned __int8 *)(pExpressions.m_Memory.m_nAllocationCount + 4 * (_DWORD)v10 + 4),
            src: (unsigned __int8 *)(pExpressions.m_Memory.m_nAllocationCount + 4 * (_DWORD)v10),
            count: 4 * ((char *)m_pElements - (char *)v10 - 1));
        v12 = (CChoreoEvent **)(m_nAllocationCount + 4 * (_DWORD)v10);
        v4 = pScene;
        if ( v12 != nullptr )
          *v12 = i;
      }
      ++v7;
    }
    while ( v7 < (int)CChoreoScene::GetNumEvents(this: (IterateRIFF *)v4) );
  }
  v13 = 0;
  for ( ia = 0; v13 < (int)m_pElements; ia = v13 )
  {
    v14 = *(CChoreoEvent **)(pExpressions.m_Memory.m_nAllocationCount + 4 * v13);
    if ( v13 != 0 )
    {
      CChoreoEvent::OffsetTime(this: *(CChoreoEvent **)(pExpressions.m_Memory.m_nAllocationCount + 4 * v13), dt: fDelta);
    }
    else if ( CChoreoEvent::GetEndTime(this: v14) + fDelta > 0.0 )
    {
      p_m_Ramp = &v14->m_Ramp;
      if ( CCurveData::GetCount(this: (IterateRIFF *)&v14->m_Ramp) != 0 )
      {
        *(float *)&pExpressions.m_Memory.m_pMemory = v14->GetDuration(this: v14);
        CChoreoEvent::OffsetEndTime(this: v14, dt: fDelta);
        v16 = (IterateRIFF *)&v14->m_Ramp;
        v17 = 0;
        if ( (int)CCurveData::GetCount(this: v16) > 0 )
        {
          do
          {
            v18 = CCurveData::Get(this: p_m_Ramp, index: v17);
            if ( *(float *)&pExpressions.m_Memory.m_pMemory - v18->time < 0.85000002
              || v17 == CCurveData::GetCount(this: (IterateRIFF *)p_m_Ramp) - 1 )
            {
              v18->time = v18->time + fDelta;
            }
            ++v17;
          }
          while ( v17 < (int)CCurveData::GetCount(this: (IterateRIFF *)p_m_Ramp) );
          v13 = ia;
        }
      }
      else
      {
        CChoreoEvent::OffsetEndTime(this: v14, dt: fDelta);
      }
    }
    ++v13;
  }
  for ( j = 0; j < (int)CChoreoScene::GetNumEvents(this: (IterateRIFF *)pScene); ++j )
  {
    v21 = CChoreoScene::GetEvent(this: pScene, event: j);
    Type = CChoreoEvent::GetType(this: v21);
    if ( (Type == LOOKAT || Type == FACE || Type == MOVETO) && CChoreoEvent::GetEndTime(this: v21) + fDelta > 0.0 )
    {
      v23 = &v21->m_Ramp;
      if ( CCurveData::GetCount(this: (IterateRIFF *)&v21->m_Ramp) != 0 )
      {
        pScenea = v21->GetDuration(this: v21);
        CChoreoEvent::OffsetEndTime(this: v21, dt: fDelta);
        v24 = (IterateRIFF *)&v21->m_Ramp;
        v25 = 0;
        if ( (int)CCurveData::GetCount(this: v24) > 0 )
        {
          do
          {
            v26 = CCurveData::Get(this: v23, index: v25);
            if ( pScenea - v26->time < 0.85000002 )
              v26->time = fDelta + v26->time;
            ++v25;
          }
          while ( v25 < (int)CCurveData::GetCount(this: (IterateRIFF *)v23) );
        }
      }
      else
      {
        CChoreoEvent::OffsetEndTime(this: v21, dt: fDelta);
      }
    }
  }
  if ( pExpressions.m_Size >= 0 && pExpressions.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pExpressions.m_Memory.m_nAllocationCount);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004021C0
// Name: private: bool CChoreoGenApp::ProcessChoreo(class CChoreoScene __near *,struct CChoreoGenApp::ChoreoGenInfo_t __near &,class CUtlVector<struct CChoreoGenApp::ChoreoTemplateInfo_t,class CUtlMemory<struct CChoreoGenApp::ChoreoTemplateInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoGenApp::ProcessChoreo(
        CChoreoGenApp *this,
        CChoreoScene *pScene,
        CChoreoGenApp::ChoreoGenInfo_t *info,
        CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int> > *templateList)
{
  CChoreoEvent *SpeakEvent; // eax

  SpeakEvent = CChoreoGenApp::GetSpeakEvent(this, pScene);
  if ( CChoreoGenApp::ProcessSpeakEvent(this, pSpeak: SpeakEvent, info) != 0 )
  {
    if ( CChoreoGenApp::AdjustEvents(this, pScene, info, templateList) != 0 )
    {
      if ( CChoreoGenApp::AddEvents(this, pScene, info) != 0 )
      {
        return 1;
      }
      else
      {
        _Warning(a1: "Error in AddEvents\n");
        return 0;
      }
    }
    else
    {
      _Warning(a1: "Error in AdjustEvents\n");
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Error in ProcessSpeakEvent\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402250
// Name: private: bool CChoreoGenApp::GenerateVcd(struct CChoreoGenApp::ChoreoGenInfo_t __near &,class CUtlVector<struct CChoreoGenApp::ChoreoTemplateInfo_t,class CUtlMemory<struct CChoreoGenApp::ChoreoTemplateInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoGenApp::GenerateVcd(
        CChoreoGenApp *this,
        CChoreoGenApp::ChoreoGenInfo_t *info,
        CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int> > *templateList)
{
  const char *v3; // eax
  const char *v4; // eax
  char v5; // bl
  int i; // edi
  char v7; // al
  const char *v8; // eax
  CChoreoScene *Vcd; // edi
  int m_nAllocationCount; // eax
  IMemAlloc *v11; // ecx
  CChoreoScene *m_pScene; // ebx
  CChoreoActor *Actor; // ebp
  const char *v15; // eax
  CP4File *v16; // esi
  const char *v17; // [esp-Ch] [ebp-358h]
  CUtlString *p_m_pNpcName; // [esp-4h] [ebp-350h]
  CUtlString pVcdName; // [esp+Ch] [ebp-340h] BYREF
  CUtlString pEmptyVcdPath; // [esp+1Ch] [ebp-330h] BYREF
  CUtlString pVcdPath; // [esp+2Ch] [ebp-320h] BYREF
  CChoreoGenApp *c; // [esp+40h] [ebp-30Ch]
  char pFullVcdSavePath[260]; // [esp+44h] [ebp-308h] BYREF
  char wName[516]; // [esp+148h] [ebp-204h] BYREF

  c = this;
  CUtlString::CUtlString(this: (CUtlString *)&pVcdPath.m_Storage.m_Memory.m_nAllocationCount, string: &g_params.m_vProj);
  CUtlString::CUtlString(this: (CUtlString *)&pVcdName.m_Storage.m_Memory.m_nAllocationCount);
  if ( g_params.m_game == 1 )
  {
    CUtlString::operator+=(this: (CUtlString *)&pVcdPath.m_Storage.m_Memory.m_nAllocationCount, rhs: "/scenes/player/");
    CUtlString::operator+=(this: (CUtlString *)&pVcdPath.m_Storage.m_Memory.m_nAllocationCount, rhs: &info->m_pNpcName);
    CUtlString::operator+=(this: (CUtlString *)&pVcdPath.m_Storage.m_Memory.m_nAllocationCount, rhs: "/low/");
    v5 = 0;
    for ( i = 0; i < CUtlString::Length(this: &info->m_pWavFile); ++i )
    {
      v7 = CUtlString::operator char const *(this: &info->m_pWavFile)[i];
      pFullVcdSavePath[0] = v7;
      if ( v7 == 46 )
        break;
      if ( v7 == 95 )
      {
        v5 = 1;
      }
      else if ( v5 != 0 )
      {
        CUtlString::operator+=(
          this: (CUtlString *)&pVcdName.m_Storage.m_Memory.m_nAllocationCount,
          c: pFullVcdSavePath[0]);
      }
    }
    CUtlString::operator+=(this: (CUtlString *)&pVcdName.m_Storage.m_Memory.m_nAllocationCount, rhs: ".vcd");
  }
  else if ( g_params.m_game == 2 )
  {
    CUtlString::operator+=(this: (CUtlString *)&pVcdPath.m_Storage.m_Memory.m_nAllocationCount, rhs: "/scenes/");
    CUtlString::operator+=(this: (CUtlString *)&pVcdPath.m_Storage.m_Memory.m_nAllocationCount, rhs: &info->m_pNpcName);
    CUtlString::operator+=(this: (CUtlString *)&pVcdPath.m_Storage.m_Memory.m_nAllocationCount, rhs: "/");
    v3 = CUtlString::operator char const *(this: &info->m_pWavFile);
    V_StripExtension(in: v3, out: &wName[4], outSize: 512);
    CUtlString::operator=(this: (CUtlString *)&pVcdName.m_Storage.m_Memory.m_nAllocationCount, src: &wName[4]);
    CUtlString::operator+=(this: (CUtlString *)&pVcdName.m_Storage.m_Memory.m_nAllocationCount, rhs: ".vcd");
  }
  v17 = CUtlString::operator char const *(this: (CUtlString *)&pVcdName.m_Storage.m_Memory.m_nAllocationCount);
  v4 = CUtlString::operator char const *(this: (CUtlString *)&pVcdPath.m_Storage.m_Memory.m_nAllocationCount);
  V_ComposeFileName(path: v4, filename: v17, dest: &pFullVcdSavePath[4], destSize: 260);
  _Msg(a1: pVcdName.m_Storage.m_nActualLength, a2: "Generating vcd %s...\n");
  CUtlString::CUtlString(
    this: (CUtlString *)&pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount,
    string: &g_params.m_vProj);
  if ( g_params.m_game == 1 )
  {
    CUtlString::operator+=(
      this: (CUtlString *)&pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount,
      rhs: "/scenes/player/");
    p_m_pNpcName = &info->m_pNpcName;
  }
  else
  {
    if ( g_params.m_game != 2 )
      goto LABEL_17;
    CUtlString::operator+=(this: (CUtlString *)&pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount, rhs: "/scenes/");
    p_m_pNpcName = &info->m_pNpcName;
  }
  CUtlString::operator+=(this: (CUtlString *)&pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount, rhs: p_m_pNpcName);
  CUtlString::operator+=(this: (CUtlString *)&pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount, rhs: "/templates/");
LABEL_17:
  v8 = CUtlString::Get(this: (CUtlString *)&pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount);
  Vcd = CChoreoGenApp::LoadVcd(this: c, subdir: v8, name: "empty.vcd");
  if ( Vcd == nullptr )
  {
    _Warning(a1: "empty.vcd not found!  this vcd must exist in the templates folder\n");
LABEL_19:
    if ( pEmptyVcdPath.m_Storage.m_nActualLength < 0 )
    {
LABEL_24:
      if ( pVcdName.m_Storage.m_nActualLength >= 0 )
      {
        if ( pVcdName.m_Storage.m_Memory.m_nAllocationCount != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pVcdName.m_Storage.m_Memory.m_nAllocationCount);
          pVcdName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        pVcdName.m_Storage.m_Memory.m_nGrowSize = 0;
      }
      if ( pVcdPath.m_Storage.m_nActualLength >= 0 && pVcdPath.m_Storage.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pVcdPath.m_Storage.m_Memory.m_nAllocationCount);
      return 0;
    }
    m_nAllocationCount = pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount;
    if ( pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount == 0 )
    {
LABEL_23:
      pEmptyVcdPath.m_Storage.m_Memory.m_nGrowSize = 0;
      goto LABEL_24;
    }
    v11 = _g_pMemAlloc;
LABEL_22:
    v11->Free_2(this: v11, a2: (void *)m_nAllocationCount);
    pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount = 0;
    goto LABEL_23;
  }
  m_pScene = templateList->m_Memory.m_pMemory[info->m_iTemplateIndex].m_pScene;
  if ( g_params.m_game == 2 )
  {
    Actor = CChoreoScene::GetActor(this: m_pScene, actor: 0);
    if ( Actor != nullptr )
    {
      v15 = CUtlString::Get(this: &info->m_pNpcName);
      CChoreoActor::SetName(this: Actor, name: v15);
    }
  }
  if ( !CChoreoScene::Merge(this: Vcd, other: m_pScene) )
  {
    _Warning(a1: "Merging template scene failed\n");
LABEL_37:
    if ( pEmptyVcdPath.m_Storage.m_nActualLength < 0 )
      goto LABEL_24;
    m_nAllocationCount = pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount;
    if ( pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount == 0 )
      goto LABEL_23;
    v11 = _g_pMemAlloc;
    goto LABEL_22;
  }
  if ( CChoreoGenApp::ProcessChoreo(this: c, pScene: Vcd, info, templateList) == 0 )
  {
    _Warning(
      a1: "Failed processing choreo for wav entry %s\n",
      (const char *)info->m_pWavFile.m_Storage.m_Memory.m_pMemory);
    goto LABEL_19;
  }
  v16 = CP4Factory::AccessFile(this: g_p4factory, szFilename: &pFullVcdSavePath[4]);
  v16->Edit(this: v16);
  CChoreoScene::MarkForSaveAll(this: Vcd, mark: true);
  if ( !CChoreoScene::SaveToFile(this: Vcd, filename: &pFullVcdSavePath[4]) )
  {
    _Warning(a1: "unable to save file %s\n", &pFullVcdSavePath[4]);
    v16->Add(this: v16);
    ((void (__thiscall *)(CP4File *, int))v16->dtr_CP4File)(a1: v16, a2: 1);
    goto LABEL_37;
  }
  ++g_ChoreoGenStats.m_iNumGeneratedVCDs;
  v16->Add(this: v16);
  ((void (__thiscall *)(CP4File *, int))v16->dtr_CP4File)(a1: v16, a2: 1);
  if ( pEmptyVcdPath.m_Storage.m_nActualLength >= 0 )
  {
    if ( pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount);
      pEmptyVcdPath.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    pEmptyVcdPath.m_Storage.m_Memory.m_nGrowSize = 0;
  }
  if ( pVcdName.m_Storage.m_nActualLength >= 0 )
  {
    if ( pVcdName.m_Storage.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pVcdName.m_Storage.m_Memory.m_nAllocationCount);
      pVcdName.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    pVcdName.m_Storage.m_Memory.m_nGrowSize = 0;
  }
  if ( pVcdPath.m_Storage.m_nActualLength >= 0 && pVcdPath.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pVcdPath.m_Storage.m_Memory.m_nAllocationCount);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402700
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004028E0
// Name: private: void CChoreoGenApp::ParseScriptFile(class CUtlBuffer __near &,class CUtlVector<struct CChoreoGenApp::ChoreoGenInfo_t,class CUtlMemory<struct CChoreoGenApp::ChoreoGenInfo_t,int>> __near &,struct CmdParams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoGenApp::ParseScriptFile(
        CChoreoGenApp *this,
        CUtlBuffer *buf,
        CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int> > *infoList,
        CmdParams_t *params)
{
  int v4; // ebp
  int v6; // eax
  const char *v7; // eax
  int v8; // ebx
  const char *v9; // eax
  int v10; // ebx
  CChoreoGenApp::ChoreoGenInfo_t info; // [esp+8h] [ebp-248h] BYREF
  char pToken[512]; // [esp+4Ch] [ebp-204h] BYREF

  v4 = 0;
  if ( buf->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlString::CUtlString(this: (CUtlString *)&info.m_pWavFile.m_Storage.m_Memory.m_nAllocationCount);
      CUtlString::CUtlString(this: (CUtlString *)&info.m_pSndEntry.m_Storage.m_Memory.m_nAllocationCount);
      CUtlString::CUtlString(this: (CUtlString *)&info.m_pNpcName.m_Storage.m_Memory.m_nAllocationCount);
      CUtlString::CUtlString(this: (CUtlString *)&info.m_pSceneTemplate.m_Storage.m_Memory.m_nAllocationCount);
      *(_DWORD *)pToken = -1;
      v6 = CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512);
      if ( v6 == 2 )
        break;
      ++g_ChoreoGenStats.m_iNumScriptEntries;
      if ( v6 != 0 )
      {
        _Warning(a1: "ERROR: Failed parsing npc token from script line %d.\n", v4);
      }
      else
      {
        CUtlString::operator=(
          this: (CUtlString *)&info.m_pNpcName.m_Storage.m_Memory.m_nAllocationCount,
          src: &pToken[4]);
        if ( CUtlString::Length(this: &params->m_pNpc) == 0
          || (v7 = CUtlString::Get(this: &params->m_pNpc), _stricmp(dst: v7, src: &pToken[4]) == 0) )
        {
          v8 = CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512);
          if ( v8 != 0 )
          {
            _Warning(a1: "ERROR: Missing comma at line %d.  may be empty line\n", v4);
            if ( v8 != 1 )
            {
              while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
                ;
            }
          }
          else if ( CUtlString::Length(this: &params->m_pFilter) == 0
                 || (v9 = CUtlString::operator char const *(this: &params->m_pFilter),
                     V_stristr(pStr: &pToken[4], pSearch: v9) != nullptr) )
          {
            CUtlString::operator=(
              this: (CUtlString *)&info.m_pWavFile.m_Storage.m_Memory.m_nAllocationCount,
              src: &pToken[4]);
            v10 = CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512);
            if ( v10 != 0 )
            {
              _Warning(a1: "ERROR: Cannot parse line text token at line %d.\n", v4);
              if ( v10 != 1 )
              {
                while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
                  ;
              }
            }
            else if ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) == 1 )
            {
              CUtlString::operator=(
                this: (CUtlString *)&info.m_pSceneTemplate.m_Storage.m_Memory.m_nAllocationCount,
                src: &pToken[4]);
              if ( CUtlString::Length(this: (CUtlString *)&info.m_pSceneTemplate.m_Storage.m_Memory.m_nAllocationCount) != 0 )
              {
                CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int>>::InsertBefore(
                  this: infoList,
                  elem: infoList->m_Size,
                  src: (const CChoreoGenApp::ChoreoGenInfo_t *)&info.m_pWavFile.m_Storage.m_Memory.m_nAllocationCount);
                ++g_ChoreoGenStats.m_iNumVCDEntries;
              }
            }
            else
            {
              _Warning(a1: "ERROR: Cannot parse vcd token at line %d\n", v4);
              while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
                ;
            }
          }
          else
          {
            ++g_ChoreoGenStats.m_iNumSkippedFilterEntries;
            while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
              ;
          }
        }
        else
        {
          ++g_ChoreoGenStats.m_iNumSkippedNPCEntries;
          while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
            ;
        }
      }
      CChoreoGenApp::ChoreoGenInfo_t::~ChoreoGenInfo_t(this: (CChoreoGenApp::ChoreoGenInfo_t *)&info.m_pWavFile.m_Storage.m_Memory.m_nAllocationCount);
      ++v4;
      if ( buf->m_Error != 0 )
        return;
    }
    CChoreoGenApp::ChoreoGenInfo_t::~ChoreoGenInfo_t(this: (CChoreoGenApp::ChoreoGenInfo_t *)&info.m_pWavFile.m_Storage.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402B70
// Name: private: void CChoreoGenApp::ParseScriptFile_L4D(class CUtlBuffer __near &,class CUtlVector<struct CChoreoGenApp::ChoreoGenInfo_t,class CUtlMemory<struct CChoreoGenApp::ChoreoGenInfo_t,int>> __near &,struct CmdParams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoGenApp::ParseScriptFile_L4D(
        CChoreoGenApp *this,
        CUtlBuffer *buf,
        CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int> > *infoList,
        CmdParams_t *params)
{
  int v4; // ebp
  int v6; // eax
  int v7; // ebx
  const char *v8; // eax
  int v9; // ebx
  int v10; // ebx
  const char *v11; // eax
  const char *v12; // eax
  CChoreoGenApp::ChoreoGenInfo_t info; // [esp+8h] [ebp-248h] BYREF
  char pToken[512]; // [esp+4Ch] [ebp-204h] BYREF

  v4 = 0;
  if ( buf->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlString::CUtlString(this: (CUtlString *)&info.m_pWavFile.m_Storage.m_Memory.m_nAllocationCount);
      CUtlString::CUtlString(this: (CUtlString *)&info.m_pSndEntry.m_Storage.m_Memory.m_nAllocationCount);
      CUtlString::CUtlString(this: (CUtlString *)&info.m_pNpcName.m_Storage.m_Memory.m_nAllocationCount);
      CUtlString::CUtlString(this: (CUtlString *)&info.m_pSceneTemplate.m_Storage.m_Memory.m_nAllocationCount);
      *(_DWORD *)pToken = -1;
      v6 = CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512);
      v7 = v6;
      if ( v6 == 2 )
        break;
      ++g_ChoreoGenStats.m_iNumScriptEntries;
      if ( v6 != 0 )
      {
        _Warning(a1: "ERROR: Missing comma at line %d.  may be empty line\n", v4);
        if ( v7 != 1 )
        {
          while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
            ;
        }
      }
      else if ( CUtlString::Length(this: &params->m_pFilter) == 0
             || (v8 = CUtlString::operator char const *(this: &params->m_pFilter),
                 V_stristr(pStr: &pToken[4], pSearch: v8) != nullptr) )
      {
        CUtlString::operator=(
          this: (CUtlString *)&info.m_pWavFile.m_Storage.m_Memory.m_nAllocationCount,
          src: &pToken[4]);
        v9 = CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512);
        if ( v9 != 0 )
        {
          _Warning(a1: "ERROR: Cannot parse line text token at line %d.\n", v4);
          if ( v9 != 1 )
          {
            while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
              ;
          }
        }
        else if ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 0 )
        {
          _Warning(a1: "ERROR: Failed parsing npc token from script line %d.\n", v4);
        }
        else
        {
          CUtlString::operator=(
            this: (CUtlString *)&info.m_pSndEntry.m_Storage.m_Memory.m_nAllocationCount,
            src: &pToken[4]);
          v10 = CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512);
          if ( v10 != 0 )
          {
            _Warning(a1: "ERROR: Cannot parse line text token at line %d.\n", v4);
            if ( v10 != 1 )
            {
              while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
                ;
            }
          }
          else if ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
          {
            if ( CUtlString::Length(this: &params->m_pNpc) == 0
              || (v11 = CUtlString::Get(this: &params->m_pNpc), _stricmp(dst: v11, src: &pToken[4]) == 0) )
            {
              CUtlString::operator=(
                this: (CUtlString *)&info.m_pNpcName.m_Storage.m_Memory.m_nAllocationCount,
                src: &pToken[4]);
              if ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) == 1 )
              {
                CUtlString::operator=(
                  this: (CUtlString *)&info.m_pSceneTemplate.m_Storage.m_Memory.m_nAllocationCount,
                  src: &pToken[4]);
                if ( CUtlString::Length(this: (CUtlString *)&info.m_pSceneTemplate.m_Storage.m_Memory.m_nAllocationCount) != 0 )
                {
                  v12 = CUtlString::Get(this: (CUtlString *)&info.m_pNpcName.m_Storage.m_Memory.m_nAllocationCount);
                  if ( _stricmp(dst: v12, src: "npc") != 0 )
                  {
                    CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int>>::InsertBefore(
                      this: infoList,
                      elem: infoList->m_Size,
                      src: (const CChoreoGenApp::ChoreoGenInfo_t *)&info.m_pWavFile.m_Storage.m_Memory.m_nAllocationCount);
                    ++g_ChoreoGenStats.m_iNumVCDEntries;
                  }
                }
              }
              else
              {
                _Warning(a1: "ERROR: Cannot parse vcd token at line %d\n", v4);
                while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
                  ;
              }
            }
            else
            {
              ++g_ChoreoGenStats.m_iNumSkippedNPCEntries;
              while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
                ;
            }
          }
        }
      }
      else
      {
        while ( CChoreoGenApp::ParseToken(this, buf, pToken: &pToken[4], nMaxTokenLen: 512) != 1 )
          ;
        ++g_ChoreoGenStats.m_iNumSkippedFilterEntries;
      }
      CChoreoGenApp::ChoreoGenInfo_t::~ChoreoGenInfo_t(this: (CChoreoGenApp::ChoreoGenInfo_t *)&info.m_pWavFile.m_Storage.m_Memory.m_nAllocationCount);
      ++v4;
      if ( buf->m_Error != 0 )
        return;
    }
    CChoreoGenApp::ChoreoGenInfo_t::~ChoreoGenInfo_t(this: (CChoreoGenApp::ChoreoGenInfo_t *)&info.m_pWavFile.m_Storage.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402EA0
// Name: private: bool CChoreoGenApp::LoadTemplates(class CUtlVector<struct CChoreoGenApp::ChoreoTemplateInfo_t,class CUtlMemory<struct CChoreoGenApp::ChoreoTemplateInfo_t,int>> __near &,class CUtlVector<struct CChoreoGenApp::ChoreoGenInfo_t,class CUtlMemory<struct CChoreoGenApp::ChoreoGenInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoGenApp::LoadTemplates(
        CChoreoGenApp *this,
        CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int> > *templateList,
        CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int> > *infoList)
{
  int m_Size; // eax
  int v5; // ebx
  const char *v7; // edi
  int TemplateIndex; // esi
  const char *v9; // eax
  CChoreoScene *Vcd; // eax
  CUtlString pTemplatePath; // [esp+8h] [ebp-30h] BYREF
  CChoreoGenApp::ChoreoTemplateInfo_t t; // [esp+18h] [ebp-20h] BYREF
  CChoreoScene *v13; // [esp+34h] [ebp-4h]
  int i; // [esp+40h] [ebp+8h]

  m_Size = infoList->m_Size;
  v5 = 0;
  pTemplatePath.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)this;
  if ( m_Size == 0 )
  {
    _Warning(a1: "No templates to load\n");
    return 0;
  }
  i = 0;
  if ( m_Size <= 0 )
  {
LABEL_19:
    g_ChoreoGenStats.m_iNumUniqueVCDs = templateList->m_Size;
    return 1;
  }
  while ( 1 )
  {
    v7 = CUtlString::operator char const *(this: &infoList->m_Memory.m_pMemory[v5].m_pSceneTemplate);
    TemplateIndex = CChoreoGenApp::GetTemplateIndex(
                      this: (CChoreoGenApp *)pTemplatePath.m_Storage.m_Memory.m_pMemory,
                      name: v7,
                      templateList);
    if ( TemplateIndex == -1 )
      break;
LABEL_18:
    infoList->m_Memory.m_pMemory[v5++].m_iTemplateIndex = TemplateIndex;
    if ( ++i >= infoList->m_Size )
      goto LABEL_19;
  }
  CUtlString::CUtlString(this: (CUtlString *)&t.m_pFileName.m_Storage.m_Memory.m_nAllocationCount);
  *(float *)&t.m_pScene = 0.0;
  t.m_flWavEndTime = 0.0;
  v13 = nullptr;
  CUtlString::operator=(this: (CUtlString *)&t.m_pFileName.m_Storage.m_Memory.m_nAllocationCount, src: v7);
  CUtlString::CUtlString(
    this: (CUtlString *)&pTemplatePath.m_Storage.m_Memory.m_nAllocationCount,
    string: &g_params.m_vProj);
  if ( g_params.m_game == 1 )
  {
    CUtlString::operator+=(
      this: (CUtlString *)&pTemplatePath.m_Storage.m_Memory.m_nAllocationCount,
      rhs: "/scenes/player/");
    CUtlString::operator+=(
      this: (CUtlString *)&pTemplatePath.m_Storage.m_Memory.m_nAllocationCount,
      rhs: &infoList->m_Memory.m_pMemory[v5].m_pNpcName);
  }
  else
  {
    if ( g_params.m_game != 2 )
      goto LABEL_10;
    CUtlString::operator+=(this: (CUtlString *)&pTemplatePath.m_Storage.m_Memory.m_nAllocationCount, rhs: "/scenes/");
    CUtlString::operator+=(
      this: (CUtlString *)&pTemplatePath.m_Storage.m_Memory.m_nAllocationCount,
      rhs: &infoList->m_Memory.m_pMemory[v5].m_pNpcName);
  }
  CUtlString::operator+=(this: (CUtlString *)&pTemplatePath.m_Storage.m_Memory.m_nAllocationCount, rhs: "/templates/");
LABEL_10:
  v9 = CUtlString::Get(this: (CUtlString *)&pTemplatePath.m_Storage.m_Memory.m_nAllocationCount);
  Vcd = CChoreoGenApp::LoadVcd(this: (CChoreoGenApp *)pTemplatePath.m_Storage.m_Memory.m_pMemory, subdir: v9, name: v7);
  if ( Vcd != nullptr )
  {
    v13 = Vcd;
    CChoreoGenApp::InitTemplateData(
      this: (CChoreoGenApp *)pTemplatePath.m_Storage.m_Memory.m_pMemory,
      tInfo: (CChoreoGenApp::ChoreoTemplateInfo_t *)&t.m_pFileName.m_Storage.m_Memory.m_nAllocationCount);
    CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int>>::InsertBefore(
      this: templateList,
      elem: templateList->m_Size,
      src: (const CChoreoGenApp::ChoreoTemplateInfo_t *)&t.m_pFileName.m_Storage.m_Memory.m_nAllocationCount);
    TemplateIndex = templateList->m_Size - 1;
    if ( pTemplatePath.m_Storage.m_nActualLength >= 0 )
    {
      if ( pTemplatePath.m_Storage.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pTemplatePath.m_Storage.m_Memory.m_nAllocationCount);
        pTemplatePath.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      pTemplatePath.m_Storage.m_Memory.m_nGrowSize = 0;
    }
    if ( t.m_pFileName.m_Storage.m_nActualLength >= 0 && t.m_pFileName.m_Storage.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)t.m_pFileName.m_Storage.m_Memory.m_nAllocationCount);
    goto LABEL_18;
  }
  if ( pTemplatePath.m_Storage.m_nActualLength >= 0 )
  {
    if ( pTemplatePath.m_Storage.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pTemplatePath.m_Storage.m_Memory.m_nAllocationCount);
      pTemplatePath.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    pTemplatePath.m_Storage.m_Memory.m_nGrowSize = 0;
  }
  if ( t.m_pFileName.m_Storage.m_nActualLength >= 0 && t.m_pFileName.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)t.m_pFileName.m_Storage.m_Memory.m_nAllocationCount);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403170
// Name: public: virtual int CChoreoGenApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoGenApp::Main(CChoreoGenApp *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  const char *v6; // edi
  int v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  const char *v12; // eax
  int v13; // eax
  int v14; // eax
  const char *v15; // eax
  int v16; // ecx
  int v18; // eax
  int v19; // ecx
  CChoreoGenApp::ChoreoGenInfo_t *m_pElements; // ebx
  int v21; // esi
  CChoreoGenApp::ChoreoGenInfo_t *m_nAllocationCount; // edi
  int v23; // ecx
  CUtlString game; // [esp+68h] [ebp-6Ch] BYREF
  CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int> > infoList; // [esp+78h] [ebp-5Ch] BYREF
  CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int> > templateList; // [esp+8Ch] [ebp-48h] BYREF
  CUtlBuffer buf; // [esp+A0h] [ebp-34h] BYREF

  game.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)this;
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: &wavname, a3: "LOCAL", a4: PATH_ADD_TO_HEAD);
  v2 = _CommandLine_Tier0();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-h", a3: 0) != 0
    || (v3 = _CommandLine_Tier0(),
        (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-help", a3: 0) != 0)
    || (v4 = _CommandLine_Tier0(), (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 36))(a1: v4) == 0) )
  {
    CChoreoGenApp::PrintHelp(this);
    return 0;
  }
  else
  {
    v5 = _CommandLine_Tier0();
    v6 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 32))(a1: v5, a2: "-i", a3: 0);
    v7 = _CommandLine_Tier0();
    v8 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v7 + 32))(a1: v7, a2: "-g", a3: 0);
    CUtlString::CUtlString(this: (CUtlString *)&game.m_Storage.m_Memory.m_nAllocationCount, pString: v8);
    if ( CUtlString::operator==(this: (CUtlString *)&game.m_Storage.m_Memory.m_nAllocationCount, src: "tf") )
    {
      g_params.m_game = 1;
    }
    else if ( CUtlString::operator==(this: (CUtlString *)&game.m_Storage.m_Memory.m_nAllocationCount, src: "zion") )
    {
      g_params.m_game = 0;
    }
    else
    {
      g_params.m_game = 3
                      - CUtlString::operator==(
                          this: (CUtlString *)&game.m_Storage.m_Memory.m_nAllocationCount,
                          src: "l4d");
    }
    v9 = getenv(option: "vproject");
    CUtlString::operator=(this: &g_params.m_vProj, src: v9);
    v10 = _CommandLine_Tier0();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v10 + 12))(a1: v10, a2: "-npc", a3: 0) != 0 )
    {
      v11 = _CommandLine_Tier0();
      v12 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v11 + 32))(
                            a1: v11,
                            a2: "-npc",
                            a3: 0);
      CUtlString::Set(this: &g_params.m_pNpc, pValue: v12);
    }
    v13 = _CommandLine_Tier0();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v13 + 12))(a1: v13, a2: "-filter", a3: 0) != 0 )
    {
      v14 = _CommandLine_Tier0();
      v15 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v14 + 32))(
                            a1: v14,
                            a2: "-filter",
                            a3: 0);
      CUtlString::Set(this: &g_params.m_pFilter, pValue: v15);
    }
    CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0, nFlags: 1);
    _Msg(a1: v16, a2: "Loading file %s\n");
    if ( !g_pFullFileSystem->ReadFile(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: v6,
            a3: nullptr,
            a4: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount,
            a5: 0,
            a6: 0,
            a7: nullptr) )
    {
      _Warning(a1: "ERROR: Unable to load file %s\n", v6);
      CUtlString::~CUtlString(this: (CUtlString *)&buf.m_Memory.m_nAllocationCount);
      CUtlString::~CUtlString(this: (CUtlString *)&game.m_Storage.m_Memory.m_nAllocationCount);
      return 0;
    }
    memset(&infoList.m_Memory.m_nAllocationCount, 0, 16);
    memset(&templateList, 0, sizeof(templateList));
    buf.m_Memory.m_pMemory = nullptr;
    if ( g_params.m_game == 2 )
      CChoreoGenApp::ParseScriptFile_L4D(
        this: (CChoreoGenApp *)game.m_Storage.m_Memory.m_pMemory,
        buf: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount,
        infoList: (CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int> > *)&infoList.m_Memory.m_nAllocationCount,
        params: &g_params);
    else
      CChoreoGenApp::ParseScriptFile(
        this: (CChoreoGenApp *)game.m_Storage.m_Memory.m_pMemory,
        buf: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount,
        infoList: (CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int> > *)&infoList.m_Memory.m_nAllocationCount,
        params: &g_params);
    if ( CChoreoGenApp::LoadTemplates(
           this: (CChoreoGenApp *)game.m_Storage.m_Memory.m_pMemory,
           templateList: (CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int> > *)&templateList.m_Memory.m_nAllocationCount,
           infoList: (CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int> > *)&infoList.m_Memory.m_nAllocationCount) == 0 )
    {
      _Warning(a1: "failed to load templates\n");
      system(command: "pause");
      CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int>>::~CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int>>(this: (CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int> > *)&templateList.m_Memory.m_nAllocationCount);
      CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int>>::~CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int>>(this: (CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int> > *)&infoList.m_Memory.m_nAllocationCount);
      CUtlString::~CUtlString(this: (CUtlString *)&buf.m_Memory.m_nAllocationCount);
      CUtlString::~CUtlString(this: (CUtlString *)&game.m_Storage.m_Memory.m_nAllocationCount);
      return -1;
    }
    v18 = _CommandLine_Tier0();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v18 + 40))(a1: v18, a2: "-nop4") != 0 )
      CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: true);
    CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "Choreogen Auto Checkout: ");
    m_pElements = infoList.m_pElements;
    v21 = 0;
    if ( (int)infoList.m_pElements > 0 )
    {
      m_nAllocationCount = (CChoreoGenApp::ChoreoGenInfo_t *)infoList.m_Memory.m_nAllocationCount;
      do
      {
        if ( CChoreoGenApp::GenerateVcd(
               this: (CChoreoGenApp *)game.m_Storage.m_Memory.m_pMemory,
               info: m_nAllocationCount,
               templateList: (CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int> > *)&templateList.m_Memory.m_nAllocationCount) == 0 )
          _Msg(a1: v19, a2: "error generating vcd for info %i\n");
        ++v21;
        ++m_nAllocationCount;
      }
      while ( v21 < (int)m_pElements );
    }
    _Msg(a1: v19, a2: "Found %d script entries\n");
    _Msg(a1: v23, a2: "Generated %d vcds\n");
    system(command: "pause");
    CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int>>::~CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int>>(this: (CUtlVector<CChoreoGenApp::ChoreoTemplateInfo_t,CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int> > *)&templateList.m_Memory.m_nAllocationCount);
    CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int>>::~CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int>>(this: (CUtlVector<CChoreoGenApp::ChoreoGenInfo_t,CUtlMemory<CChoreoGenApp::ChoreoGenInfo_t,int> > *)&infoList.m_Memory.m_nAllocationCount);
    if ( buf.m_Get >= 0 )
    {
      if ( buf.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
        buf.m_Memory.m_nAllocationCount = 0;
      }
      buf.m_Memory.m_nGrowSize = 0;
    }
    if ( game.m_Storage.m_nActualLength < 0 || game.m_Storage.m_Memory.m_nAllocationCount == 0 )
      return -1;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)game.m_Storage.m_Memory.m_nAllocationCount);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403520
// Name: public: virtual void CTier3SteamApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier3SteamApp::PostShutdown(CTier3SteamApp *this)
{
  DisconnectTier3Libraries();
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00404610
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408450
// Name: public: void CUtlMemory<struct CChoreoGenApp::ChoreoTemplateInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CChoreoGenApp::ChoreoTemplateInfo_t,int>::Grow(
        CUtlMemory<CEventAbsoluteTag,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CEventAbsoluteTag *m_pMemory; // edx
  bool v7; // zf

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (CEventAbsoluteTag *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (CEventAbsoluteTag *)_g_pMemAlloc->Realloc_2(
                                               this: _g_pMemAlloc,
                                               a2: m_pMemory,
                                               a3: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411990
// Name: public: void CUtlDict<struct EventGroup,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<EventGroup,int>::RemoveAll(CUtlDict<EventGroup,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}
