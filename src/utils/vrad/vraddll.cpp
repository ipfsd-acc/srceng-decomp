// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/vraddll.cpp
// Functions: 9
// ============================================================

#include "utils\vrad\vraddll.h"

//------------------------------------------------------------------------------
// Address: 0x1002A050
// Name: int CalcDatSize(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CalcDatSize()
{
  int v0; // eax
  int v1; // esi
  char **v2; // ecx
  dat *v3; // edx
  char *name; // edi
  char *size; // ebx
  int v6; // esi
  int v7; // edx
  _DWORD *v8; // ecx

  v0 = 0;
  v1 = 1;
  v2 = &off_1012CC80;
  v3 = g_Dats;
  do
  {
    if ( dword_1012CC74[2 * v1] > dword_1012CC7C[2 * v1] )
    {
      name = v3->name;
      size = (char *)v3->size;
      v3->name = *v2;
      v3->size = (int)v2[1];
      v0 = 0;
      *v2 = name;
      v2[1] = size;
      if ( v1 <= 1 )
      {
        --v1;
        v2 -= 2;
        --v3;
      }
      else
      {
        v1 -= 2;
        v2 -= 4;
        v3 -= 2;
      }
    }
    ++v1;
    v2 += 2;
    ++v3;
  }
  while ( v1 < 33 );
  v6 = 0;
  v7 = 0;
  v8 = &unk_1012CC84;
  do
  {
    v0 += *(v8 - 2);
    v7 += *v8;
    v6 += v8[2];
    v8 += 6;
  }
  while ( (int)v8 < (int)&vec4_invalid_19.y );
  return v7 + v6 + v0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A0F0
// Name: public: virtual int CVRadDLL::main(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVRadDLL::main(CVRadDLL *this, entity_t *argc, char **argv)
{
  return VRAD_Main(argc, argv);
}

//------------------------------------------------------------------------------
// Address: 0x1002A110
// Name: public: virtual bool CVRadDLL::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVRadDLL::Init@<al>(CVRadDLL *this@<ecx>, int a2@<esi>, const char *pFilename)
{
  VRAD_Init();
  do_fast = 1;
  g_bLowPriorityThreads = true;
  g_pIncremental = GetIncremental();
  VRAD_LoadBSP(a1: a2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002A150
// Name: public: virtual float CVRadDLL::GetPercentComplete(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVRadDLL::GetPercentComplete(CVRadDLL *this)
{
  return (double)g_iCurFace / (double)(int)numfaces;
}

//------------------------------------------------------------------------------
// Address: 0x1002A160
// Name: public: virtual void CVRadDLL::Interrupt(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDLL::Interrupt(CVRadDLL *this)
{
  g_bInterrupt = true;
}

//------------------------------------------------------------------------------
// Address: 0x1002A180
// Name: public: virtual void CVRadDLL::GetBSPInfo(class CBSPInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDLL::GetBSPInfo(CVRadDLL *this, CBSPInfo *pInfo)
{
  pInfo->dlightdata = pdlightdata->m_Memory.m_pMemory;
  pInfo->lightdatasize = pdlightdata->m_Size;
  pInfo->dfaces = dfaces;
  pInfo->m_pFacesTouched = g_FacesTouched.m_Memory.m_pMemory;
  pInfo->numfaces = numfaces;
  pInfo->dvertexes = dvertexes;
  pInfo->numvertexes = numvertexes;
  pInfo->dedges = dedges;
  pInfo->numedges = numedges;
  pInfo->dsurfedges = dsurfedges;
  pInfo->numsurfedges = numsurfedges;
  pInfo->texinfo = texinfo.m_Memory.m_pMemory;
  pInfo->numtexinfo = texinfo.m_Size;
  pInfo->g_dispinfo = g_dispinfo.m_Memory.m_pMemory;
  pInfo->g_numdispinfo = g_dispinfo.m_Size;
  pInfo->dtexdata = dtexdata;
  pInfo->numtexdata = numtexdata;
  pInfo->texDataStringData = g_TexDataStringData.m_Memory.m_pMemory;
  pInfo->nTexDataStringData = g_TexDataStringData.m_Size;
  pInfo->texDataStringTable = g_TexDataStringTable.m_Memory.m_pMemory;
  pInfo->nTexDataStringTable = g_TexDataStringTable.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1002A240
// Name: public: virtual bool CVRadDLL::DoIncrementalLight(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVRadDLL::DoIncrementalLight@<al>(
        CVRadDLL *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pVMFFile)
{
  entity_t *v4; // esi
  int v6; // [esp-4h] [ebp-210h]
  char tempPath[260]; // [esp+4h] [ebp-208h] BYREF
  char tempFilename[260]; // [esp+108h] [ebp-104h] BYREF

  GetTempPathA(nBufferLength: 0x104u, lpBuffer: tempPath);
  GetTempFileNameA(lpPathName: tempPath, lpPrefixString: "vmf_entities_", uUnique: 0, lpTempFileName: tempFilename);
  v4 = (entity_t *)g_pFileSystem->Open(this: g_pFileSystem, a2: tempFilename, a3: "wb", a4: 0);
  if ( v4 == nullptr )
    return 0;
  ((void (__thiscall *)(IBaseFileSystem *, const char *, unsigned int, entity_t *, int))g_pFileSystem->Write)(
    a1: g_pFileSystem,
    a2: pVMFFile,
    a3: strlen(pVMFFile) + 1,
    a4: v4,
    a5: a3);
  g_pFileSystem->Close(this: g_pFileSystem, a2: v4);
  if ( !LoadEntsFromMapFile(pFilename: tempFilename) )
    return 0;
  CreateDirectLights();
  ProcessSkyCameras();
  g_bInterrupt = false;
  if ( RadWorld_Go(a1: a2, a2: v6, a3: v4) == 0 )
  {
    g_iCurFace = 0;
    return 0;
  }
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: &g_LastGoodLightData,
    pArray: pdlightdata->m_Memory.m_pMemory,
    size: pdlightdata->m_Size);
  if ( g_pIncremental != nullptr )
    g_pIncremental->GetFacesTouched(this: g_pIncremental, a2: &g_FacesTouched);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002A350
// Name: public: virtual bool CVRadDLL::Serialize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRadDLL::Serialize(CVRadDLL *this)
{
  if ( g_pIncremental == nullptr )
    return 0;
  if ( g_LastGoodLightData.m_Size <= 0 )
    return 0;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: pdlightdata,
    pArray: g_LastGoodLightData.m_Memory.m_pMemory,
    size: g_LastGoodLightData.m_Size);
  if ( !g_pIncremental->Serialize(this: g_pIncremental) )
    return 0;
  CUtlVector<CLightValue,CUtlMemory<CLightValue,int>>::Purge(this: &g_LastGoodLightData);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008A820
// Name: public: virtual void CVRadDLL::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDLL::Release(CFileSystemPassThru *this)
{
  ;
}
